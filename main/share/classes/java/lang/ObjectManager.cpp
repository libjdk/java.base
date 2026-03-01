/*
 * Copyright (c) 2025, Yao Yuan <yeaya@163.com>. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.  This file as subject to the
 * "Classpath" exception in the LICENSE file that accompanied this code.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <java/lang/ObjectManager.h>
#include <java/lang/ObjectManagerInternal.h>

#include <java/lang/Thread.h>
#include <java/lang/ObjectHead.h>
#include <java/lang/OutOfMemoryError.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/ArrayIndexOutOfBoundsException.h>
#include <java/lang/ArrayStoreException.h>
#include <java/lang/NegativeArraySizeException.h>
#include <java/lang/CallerHelper.h>
#include <java/lang/System.h>
#include <java/lang/Machine.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/ref/Reference.h>
#include <java/lang/ref/SoftReference.h>
#include <java/lang/ref/WeakReference.h>
#include <java/lang/ref/PhantomReference.h>
#include <java/lang/ref/FinalReference.h>
#include <java/lang/ref/ReferenceQueue.h>
#include <java/lang/ref/ReferenceQueue$Null.h>
#include <java/lang/ref/Finalizer.h>
#include <java/lang/reflect/Modifier.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/List.h>
#include <java/lang/MemoryManager.h>
#include <java/io/PrintStream.h>
#include <java/lang/ThreadLocal$ThreadLocalMap.h>
#include <java/lang/InterruptedException.h>
#include <java/util/Objects.h>
#include <java/net/URI.h>
#include <java/lang/CoreObject.h>
#include <java/lang/interpreter/ByteCodeClass.h>
#include <java/lang/YYSet.h>
#include <java/lang/ObjectManagerStat.h>
#include <java/lang/VirtualMachineError.h>
#include <java/lang/StackOverflowError.h>
#include <java/lang/Shutdown.h>
#include <java/lang/Logger.h>
#include <java/lang/SpinLock.h>
#include <jcpp.h>

#include <string.h>
#include <mutex>
#include <condition_variable>
#include <stdarg.h>

#include "Platform.h"

using namespace ::java::lang;
using namespace ::java::lang::reflect;
using namespace ::java::lang::ref;
using namespace ::java::util;

#include <map>

#pragma push_macro("NULL")
#undef NULL

template<typename T>
inline bool cas(T** mem, T*& expected, T* desired) {
	return std::atomic_compare_exchange_strong((std::atomic<intptr_t>*)mem, (intptr_t*)&expected, (intptr_t)desired);
}

inline int8_t genNextGlobalLiveCode(int32_t& liveCodeSequence) {
	if (liveCodeSequence <= 0) {
		liveCodeSequence = 0;
	}
	int8_t liveCode = liveCodeSequence % 127 + 1;
	liveCodeSequence++;
	return liveCode;
}

inline int8_t genNextLocalLiveCode(int32_t& liveCodeSequence) {
	if (liveCodeSequence <= 0) {
		liveCodeSequence = 0;
	}
	int8_t liveCode = -(liveCodeSequence % 127 + 1);
	liveCodeSequence++;
	return liveCode;
}

namespace java {
	namespace lang {

MemoryManager memoryManager;

#define DEFAULT_VAR_STACK_SIZE 4096
#define DEFAULT_REF_STACK_SIZE 4096
#define DEFAULT_JNI_LOCAL_REF_STACK_SIZE 4096
#define DEFAULT_JNI_LOCAL_REF_STACK_FRAME_SIZE 512

int64_t varStackSizeGlobal = DEFAULT_VAR_STACK_SIZE;
int64_t refStackSizeGlobal = DEFAULT_REF_STACK_SIZE;
int64_t jniLocalRefStackSizeGlobal = DEFAULT_JNI_LOCAL_REF_STACK_SIZE;
int64_t jniLocalRefStackFrameSizeGlobal = DEFAULT_JNI_LOCAL_REF_STACK_FRAME_SIZE;

struct LocalFrame {
	// int32_t capacity;
	int32_t begin;
};

//template<typename T, $enable_if($is_object0(T))>
//inline Object0* toObject0(T* inst) {
//	return (Object0*)(void*)inst;
//}
//template<typename T, $enable_if(!$is_object0(T))>
//inline Object0* toObject0(T* obj) {
//	if (ObjectManager::checkToObject0Address(obj)) {
//		return (Object0*)(void*)obj;
//	}
//	return ((Object*)(void*)obj)->toObject0$();
//}
//inline Object0* toObject0(std::nullptr_t) {
//	return nullptr;
//}
#define toObject0 $toObject0

bool isClass(Class* clazz, const char* className) {
	while (clazz != nullptr) {
		if (clazz->classInfo != nullptr && strcmp(clazz->classInfo->name, className) == 0) {
			return true;
		}
		clazz = clazz->getSuperclass();
	}
	return false;
}

class CountSize {
public:
	void add(int64_t size) {
		count++;
		this->size += size;
	}
	void add(CountSize* cs) {
		count += cs->count;
		size += cs->size;
	}
	void add(int64_t count, int64_t size) {
		this->count += count;
		this->size += size;
	}
	void sub(int64_t size) {
		count--;
		this->size -= size;
	}
	void sub(CountSize* cs) {
		count -= cs->count;
		size -= cs->size;
	}
	void clear() {
		count = 0;
		size = 0;
	}
	int64_t count = 0;
	int64_t size = 0;
};

class AtomicCountSize {
public:
	void add(int64_t size) {
		count++;
		this->size += size;
	}
	void add(CountSize* cs) {
		count += cs->count;
		size += cs->size;
	}
	void add(int64_t count, int64_t size) {
		this->count += count;
		this->size += size;
	}
	void sub(int64_t size) {
		count--;
		this->size -= size;
	}
	void sub(CountSize* cs) {
		count -= cs->count;
		size -= cs->size;
	}
	void clear() {
		count = 0;
		size = 0;
	}
	std::atomic<int64_t> count = 0;
	std::atomic<int64_t> size = 0;
};

class AddSubInt64 {
public:
	AddSubInt64() : addValue(0), subValue(0) {}

	void add(int64_t value) {
		addValue += value;
	}

	void inc() {
		addValue++;
	}

	void sub(int64_t value) {
		subValue += value;
	}

	void dec() {
		subValue++;
	}

	int64_t value() {
		return addValue - subValue;
	}

	void clear() {
		addValue = 0;
		subValue = 0;
	}

	int64_t addValue;
	int64_t subValue;
};

class AddSubCountSize {
public:
	void add(int64_t size) {
		count.inc();
		this->size.add(size);
	}
	void add(CountSize* cs) {
		count.add(cs->count);
		size.add(cs->size);
	}
	void sub(int64_t size) {
		count.dec();
		this->size.sub(size);
	}
	void sub(CountSize* cs) {
		count.sub(cs->count);
		size.sub(cs->size);
	}
	void clear() {
		count.clear();
		size.clear();
	}
	void sum(AddSubCountSize* cs) {
		count.add(cs->count.value());
		size.add(cs->size.value());
	}
	AddSubInt64 count;
	AddSubInt64 size;
};

enum GcType {
	GC_TYPE_NONE = 0,
	GC_TYPE_LOCAL,
	GC_TYPE_ASYNC_LOCAL,
	GC_TYPE_FULL
};

class GcResult {
public:
	GcResult(GcType gcType) : gcType(gcType) {

	}
	void sum(GcResult* gcResult) {
		free.add(&gcResult->free);
		moveToGlobal.add(&gcResult->moveToGlobal);
		prepareNS += gcResult->prepareNS;
		markNS += gcResult->markNS;
		localMarkNS += gcResult->localMarkNS;
		stopNS += gcResult->stopNS;
		realStopNS += gcResult->realStopNS;
		processNS += gcResult->processNS;
		costNS += gcResult->costNS;
	}

	void print(const char* prefix) {
		if (gcType == GC_TYPE_FULL) {
			log_debug("%s %d, threads:%" PRId32 " free:%" PRId64 "/%" PRId64 " move:%" PRId64 "/%" PRId64 " prepare:%.3lfms mark(%.3lfms, local:%.3lfms stop:%.3lfms/%.3lfms) process:%.3lfms total:%.3lfms\n",
				prefix, liveCode, threadCount,
				free.count, free.size, moveToGlobal.count, moveToGlobal.size,
				prepareNS / 1000000.0,
				markNS / 1000000.0,
				localMarkNS / 1000000.0,
				stopNS / 1000000.0,
				realStopNS / 1000000.0,
				processNS / 1000000.0,
				costNS / 1000000.0
			);
		} else {
			log_debug("%s %d, threads:%" PRId32 " free:%" PRId64 "/%" PRId64 " move:%" PRId64 "/%" PRId64 " prepare:%.3lfms mark(%.3lfms stop:%.3lfms/%.3lfms) process:%.3lfms total:%.3lfms\n",
				prefix, liveCode, threadCount,
				free.count, free.size, moveToGlobal.count, moveToGlobal.size,
				prepareNS / 1000000.0,
				markNS / 1000000.0,
				stopNS / 1000000.0,
				realStopNS / 1000000.0,
				processNS / 1000000.0,
				costNS / 1000000.0
			);
		}
	}
	GcType gcType;
	int8_t liveCode;
	int32_t threadCount = 0;
	CountSize free;
	CountSize moveToGlobal;
	int64_t prepareNS = 0;
	int64_t markNS = 0;
	int64_t localMarkNS = 0;
	int64_t stopNS = 0;
	int64_t realStopNS = 0;
	int64_t processNS = 0;
	int64_t costNS = 0;
};

#define MAX_SCAN_DEPTH 32
#define MAX_SCAN_CONTEXT_PENDING_SIZE  2048

class ScanContextPending {
public:
	ObjectHead* pendingArray[MAX_SCAN_CONTEXT_PENDING_SIZE];
	int32_t pendingCount = 0;
	ScanContextPending* next = nullptr;

	bool isEmpty() {
		return pendingCount == 0;
	}
	bool isFully() {
		return pendingCount == MAX_SCAN_CONTEXT_PENDING_SIZE;
	}
	void addLast(ObjectHead* oh) {
		pendingArray[pendingCount] = oh;
		pendingCount++;
	}
	ObjectHead* removeLast() {
		if (pendingCount > 0) {
			pendingCount--;
			ObjectHead* oh = pendingArray[pendingCount];
			return oh;
		}
		return nullptr;
	}
	static ScanContextPending* create();
	static void free(ScanContextPending* scp);
};

class ScanContextPendingManager {
public:
	ScanContextPendingManager() {
	}

	~ScanContextPendingManager() {
		while (head != nullptr) {
			ScanContextPending* scp = head;
			head = head->next;
			ScanContextPending::free(scp);
		}
	}

	inline bool isEmpty() {
		if (head == nullptr) {
			return true;
		}
		return head->isEmpty();
	}

	inline void addOne(ObjectHead* oh);

	inline ObjectHead* removeOne();

	inline void clear() {
		ObjectHead* oh = removeOne();
		while (oh != nullptr) {
			oh = removeOne();
		}
	}

	ScanContextPending* head = nullptr;
};

template<typename T>
class ScanMarkBase {
public:
	inline static void scanObject(T* scanner, ObjectHead* oh) {
		Class* clazz = oh->clazz;
		//if (clazz == nullptr) {
		//	log_info("scanObject clazz == nullptr\n");
		//}
		Class* componentType = clazz->componentType$;
		if (componentType == nullptr) {
			int32_t* offsetArray = clazz->objectFieldOffsetArray;
			if (offsetArray != nullptr) {
				scanner->depth++;
				Object0* this__ = fromOh(oh);
				int32_t offset = *offsetArray;
				while (offset > 0) {
					Object* obj = *(Object**)((int8_t*)this__ + offset);
					if (obj != nullptr) {
						Object0* obj0 = toObject0(obj);
						ObjectHead* ohField = toOh(obj0);
						scanner->scanField(oh, ohField, offset);
					}
					offsetArray++;
					offset = *offsetArray;
				}
				scanner->depth--;
			}
		} else {
			if (!componentType->primitive) {
				scanner->depth++;
				ObjectArray* oa = (ObjectArray*)fromOh(oh);
				Object0** begin = oa->begin();
				int32_t len = oa->_;
				//int32_t len = oa->length;
				for (int32_t i = 0; i < len; i++) {
					Object0* o = begin[i];
					if (o != nullptr) {
						ObjectHead* elementOh = toOh(o);
						scanner->scanField(oh, elementOh, 0);
					}
				}
				scanner->depth--;
			}
		}
	}

	inline static bool isEndObject(ObjectHead* oh) {
		Class* type = oh->clazz->componentType$;
		if (type != nullptr) {
			if (type->primitive) {
				return true;
			}
			return false;
		}
		if (oh->clazz->objectFieldOffsetArrayLength == 0) {
			return true;
		}
		return false;
	}

	inline static bool isBigObjectArray(ObjectHead* oh) {
		Class* type = oh->clazz->componentType$;
		if (type != nullptr && !type->primitive) {
			ObjectArray* oa = (ObjectArray*)fromOh(oh);
			return oa->_ > 32;
		}
		return false;
	}

	inline static void scanNext(T* scanner, ObjectHead* ohThis, ObjectHead* oh) {
		if (scanner->depth >= MAX_SCAN_DEPTH //|| !this->isPendingQueueEmpty()
			) {
			if (isEndObject(oh)) {
				scanObject(scanner, oh);
				return;
			}
			if (isBigObjectArray(ohThis)) {
				if (scanner->depth >= MAX_SCAN_DEPTH + 5) {
					scanner->addOnePending(oh);
					return;
				}
			} else {
				scanner->addOnePending(oh);
				return;
			}
		}
		//  this->depth++;
		scanObject(scanner, oh);
		//  this->depth--;

		//if (scanner->depth < MAX_SCAN_DEPTH - 3) {
		//	if (!scanner->isPendingQueueEmpty()) {
		//		scanner->processPendingScan();
		//	}
		//}
	}

	inline void processPendingScan() {
		ObjectHead* oh = removeOnePending();
		while (oh != nullptr) {
			scanObject((T*)this, oh);
			oh = removeOnePending();
		}
	}

	inline bool isPendingQueueEmpty() {
		return pendingManager->isEmpty();
	}

	inline void addOnePending(ObjectHead* oh) {
		//debugObjectHead("addOne pending", oh);
		pendingManager->addOne(oh);
	}

	inline ObjectHead* removeOnePending() {
		return pendingManager->removeOne();
	}

	ScanMarkBase() {
	}
	~ScanMarkBase() {
	}

	int32_t depth = 0;
	ScanContextPendingManager* pendingManager = nullptr;
};

class ScanMarkGlobal : public ScanMarkBase<ScanMarkGlobal> {
public:
	template<typename T>
	inline void scan(T obj) {
		if (obj != nullptr) {
			Object0* obj0 = toObject0(obj);
			ObjectHead* oh = toOh(obj0);
			scan(oh);
		}
	}
	inline void changeToGlobal(ObjectHead* oh) {
#ifdef OBJECT_DEBUG
		oh->markGobalLiveCode = globalController->liveCodeGlobal;
		if (oh->isDebug() || !oh->isUsed()) {
			debugObjectHead("ScanMarkGlobal.changeToGlobal", oh);
		}
#endif
		// is local monitor
		if (!oh->isMonitor() && oh->objectMonitor != 0) {
			Platform::upgradeMonitor(oh);
		}
		oh->setGlobal();
		tryUpdateAllocater4Global(oh);
	}
	inline void scan(ObjectHead* oh) {
		if (!oh->isGlobal()) {
			changeToGlobal(oh);
			scanObject(this, oh);
		}
	}
	inline void scanField(ObjectHead* ohThis, ObjectHead* oh, int32_t fieldOffset) {
		if (!oh->isGlobal()) {
			changeToGlobal(oh);
			scanNext(this, ohThis, oh);
		}
	}
};


#define MAX_ATOMIC_GC_HANDLE_PENDING_SIZE 4096

class GcHandlePending {
public:
	volatile int64_t writePos = 0;
	int64_t readPos = 0;
	ObjectHead* volatile pendingArray[MAX_ATOMIC_GC_HANDLE_PENDING_SIZE];
	GcHandlePending* next = nullptr;

	void clearPos() {
		writePos = 0;
		readPos = 0;
	}
	bool canWrite() {
		return writePos < MAX_ATOMIC_GC_HANDLE_PENDING_SIZE;
	}

	bool canRead() {
		return readPos < writePos;
	}

	void write(ObjectHead* oh) {
		pendingArray[writePos] = oh;
		writePos++;
	}
	ObjectHead* read() {
		if (readPos < writePos) {
			ObjectHead* oh = pendingArray[readPos];
			readPos++;
			return oh;
		}
		return nullptr;
	}

	static GcHandlePending* create();
	static void free(GcHandlePending* aghp);
};

class GcHandlePendingSaver {
public:
	GcHandlePendingSaver() {
	}

	~GcHandlePendingSaver() {
		GcHandlePending* aghp = head;
		head = nullptr;
		while (aghp != nullptr) {
			GcHandlePending* next = aghp->next;
			GcHandlePending::free(aghp);
			aghp = next;
		}
		head = nullptr;
	}

	inline bool write(ObjectHead* oh) {
#ifdef OBJECT_DEBUG
		if (oh->isDebug() || !oh->isUsed()) {
			//debugObjectHead("addOne", oh);
		}
#endif
		GcHandlePending* aghp = head;
		if (aghp == nullptr || !aghp->canWrite()) {
			aghp = GcHandlePending::create();
			if (aghp == nullptr) {
				log_warning("GcHandlePending::create() fail\n")
				return false;
			}
			aghp->next = head;
			head = aghp;
		}
		aghp->write(oh);
		return true;
	}

	inline GcHandlePending* getHead() {
		return head;
	}

	inline void clear0() {
		GcHandlePending* aghp = head;
		while (aghp != nullptr) {
			GcHandlePending* next = aghp->next;
			if (aghp != head) {
				GcHandlePending::free(aghp);
			} else {
				aghp->clearPos();
				aghp->next = nullptr;
			}
			aghp = next;
		}
	}

	inline GcHandlePending* readFinishedGcHandlePending() {
		GcHandlePending* aghp = head;
		if (aghp != nullptr) {
			GcHandlePending* next = aghp->next;
			aghp->next = nullptr;
			return next;
		}
		return nullptr;
	}

	GcHandlePending* volatile head = nullptr;
};

class GcHandlePendingReader {
public:
	GcHandlePendingReader(GcHandlePendingSaver* saver) : saver(saver), finished(nullptr) {
	}
	~GcHandlePendingReader() {
	}
	inline ObjectHead* readFinished() {
		if (finished == nullptr) {
			finished = saver->readFinishedGcHandlePending();
		}
		if (finished != nullptr) {
			ObjectHead* oh = finished->read();
			if (!finished->canRead()) {
				GcHandlePending* next = finished->next;
				GcHandlePending::free(finished);
				finished = next;
			}
			return oh;
		}
		return nullptr;
	}
	inline ObjectHead* read() {
		ObjectHead* oh = readFinished();
		if (oh != nullptr) {
			return oh;
		}
		GcHandlePending* aghp = saver->getHead();
		if (aghp != nullptr) {
			oh = aghp->read();
		}
		if (oh == nullptr) {
			oh = readFinished();
		}
		return oh;
	}
	GcHandlePendingSaver* saver;
	GcHandlePending* finished;
};

class LocalController;
thread_local LocalController* localController = nullptr;

#ifdef OBJECT_DEBUG
volatile int64_t newIndex = 0;
std::atomic<int64_t> scanIndex = 0;
#endif

volatile GcType globalGcType = GC_TYPE_NONE;
//std::atomic_bool globalStop4gc = false;

volatile bool objectManagerInited = false;

enum GcStatus {
	GC_STATUS_NONE = 0,
	GC_STATUS_START,
	GC_STATUS_DONE
};

const char* GcStatusNames[] {
	"NONE",
	"START",
	"DONE"
};

enum LocalControllerStatus {
	LC_STATUS_NONE = 0,
	LC_STATUS_RUN,
	LC_STATUS_STOP,
	LC_STATUS_CLEARING,
	LC_STATUS_DONE
};

const char* LocalControllerStatusNames[] {
	"NONE",
	"START",
	"STOP",
	"CLEARING",
	"DONE"
};

const char* getRefTypeName(REF_TYPE refType) {
	if (refType == OBJECT_REF_TYPE_DEFAULT) {
		return "default";
	} else if (refType == OBJECT_REF_TYPE_GLOBAL) {
		return "global";
	} else if (refType == OBJECT_REF_TYPE_FINAL) {
		return "final";
	} else if (refType == OBJECT_REF_TYPE_SOFT) {
		return "soft";
	} else if (refType == OBJECT_REF_TYPE_WEAK) {
		return "weak";
	} else if (refType == OBJECT_REF_TYPE_PHANTOM) {
		return "phantom";
	}
	return "";
};

class ObjectQueueStat {
public:
	int32_t count;
	int64_t size;

	int64_t addCount;
	int64_t addSize;
	int64_t removeCount;
	int64_t removeSize;

	inline void add(int64_t size) {
		count++;
		this->size += size;
		addCount++;
		addSize += size;
	}
	inline void remove(int64_t size) {
		count--;
		this->size -= size;
		removeCount++;
		removeSize += size;
	}
};

#define AtomicObjectList AtomicSList<ObjectHead>
#define AtomicObjectListIterator AtomicSListIterator<ObjectHead>
#define ObjectList SList<ObjectHead>
#define ObjectListIterator SListIterator<ObjectHead>

#define AtomicMemoryAllocaterList AtomicSList<StoredMemoryAllocater>
#define MemoryAllocaterList SList<StoredMemoryAllocater>

const char* getClassName(ObjectHead* oh) {
	if (oh != nullptr && oh->clazz->classInfo != nullptr) {
		return oh->clazz->classInfo->name;
	}
	return "";
}

const char* getClassName(Object* obj) {
	if (obj != nullptr) {
		Object0* obj0 = toObject0(obj);
		ObjectHead* oh = toOh(obj0);
		Class* clazz = oh->clazz;
		if (clazz != nullptr && clazz->classInfo != nullptr && clazz->classInfo->name != nullptr) {
			return clazz->classInfo->name;
		}
	}
	return "";
}

bool isClass(ObjectHead* oh, const char* name) {
	Object0* obj = fromOh(oh);
	Class* clazz = oh->clazz;
	if (clazz != nullptr && clazz->classInfo != nullptr && clazz->classInfo->name != nullptr) {
		return strcmp(clazz->classInfo->name, name) == 0;
	}
	return false;
}

void debugObjectHead(const char* where, ObjectHead* oh) {
#ifdef OBJECT_DEBUG
	int64_t id = 0;
	int32_t flags = 0;
	int32_t refCount = 0;
	const char* className = "";
	const char* className2 = "";
	if (oh == nullptr) {
		return;
	}
	className = getClassName(oh);
	id = oh->id;
	flags = oh->flags;
#ifdef ENABLE_OBJECT_REF_COUNT
	refCount = oh->refCount.global;
#endif
	log_info("%s %" PRId64 "/%p, f:%" PRId32 ", r:%" PRId32 ", live:%" PRId8 "/%" PRId8 ", (%s)\n",
				where, id, fromOh(oh), flags, refCount, (int8_t)oh->liveCode, (int8_t)oh->reachCode, className);

	if (!oh->isUsed()) {
		log_info("isDeleted flag:%" PRId32 ", id:%" PRId64 ", class:%s\n", (int32_t)oh->getFlags(), oh->id,
			oh->clazz->classInfo != nullptr ? oh->clazz->classInfo->name : "");
		if (oh->ownerOH != nullptr) {
			log_info("isDeleted owner flag:%" PRId32 ", id:%" PRId64 ", class:%s\n", (int32_t)oh->ownerOH->getFlags(), oh->ownerOH->id,
				oh->ownerOH->clazz->classInfo != nullptr ? oh->ownerOH->clazz->classInfo->name : "");
		}
	}
#else
	if (!oh->isUsed()) {
		log_info("isDeleted flag:%" PRId32 ", class:%s\n", (int32_t)oh->getFlags(),
			oh->clazz->classInfo != nullptr ? oh->clazz->classInfo->name : "");
		if (oh->isGlobal()) {
			log_info("isGlobal\n");
		}
	}
#endif
}

#ifdef OBJECT_DEBUG
template<typename T>
bool isDebug(T obj) {
	if (obj != nullptr) {
		Object0* obj0 = toObject0(obj);
		ObjectHead* oh = toOh(obj0);
		return oh->isDebug();
	}
	return false;
}
#endif

void debugObject(const char* where, const Object$* obj) {
	ObjectHead* oh = nullptr;
	ObjectHead* oh2 = nullptr;
	if (obj != nullptr) {
		Object0* o = toObject0(obj);
		oh = toOh(o);
	}
	debugObjectHead(where, oh);
}

inline void freeObjectMonitor(ObjectHead* oh) {
	if (oh->objectMonitor != 0 && oh->isMonitor()) {
		Platform::freeObjectMonitor(oh);
	}
}

void globalFullGc();

class LocalController {
public:
	LocalController() {
		threadName[0] = '\0';
		varStackSize = varStackSizeGlobal;
		refStackSize = refStackSizeGlobal;
		jniLocalRefStackSize = jniLocalRefStackSizeGlobal;
		jniLocalRefStackFrameSize = jniLocalRefStackFrameSizeGlobal;

		int64_t varStackBufferSize = calcAlignedSize(sizeof(void*) * varStackSize);
		int64_t refStackBufferSize = calcAlignedSize(sizeof(Object*) * refStackSize);
		int64_t jniLocalRefStackBufferSize = calcAlignedSize(sizeof(Object0*) * jniLocalRefStackSize);
		int64_t jniLocalRefStackFrameBufferSize = calcAlignedSize(sizeof(LocalFrame) * jniLocalRefStackFrameSize);
		int64_t totalSize = varStackBufferSize + refStackBufferSize + jniLocalRefStackBufferSize + jniLocalRefStackFrameBufferSize;
		int8_t* data = (int8_t*)ObjectManager::allocRawOrExit(totalSize);

		void** varStack = (void**)data;
		data += varStackBufferSize;

		Object** refStack = (Object**)(data);
		data += refStackBufferSize;
		objectStack.init(varStack, refStack);

		jniLocalRefStack = (Object0**)data;
		data += jniLocalRefStackBufferSize;

		jniLocalRefStackFrame = (LocalFrame*)data;

		// init first frame
		jniLocalRefStackFrameIndex = 0;
		jniLocalRefStackEndIndex = 0;
		jniLocalRefStackFrame[jniLocalRefStackFrameIndex].begin = jniLocalRefStackEndIndex;

		scanMarkGlobalScanner.pendingManager = &scanMarkGlobalPendingManager;
	}

	static LocalController* create() {
		void* data = ObjectManager::allocRawOrExit(sizeof(LocalController));
		memset(data, 0, sizeof(LocalController));
		return new(data)LocalController();
	}
	static void free(LocalController* lc) {
		void* data = lc->objectStack.varStack;
		ObjectManager::freeRaw(data);
		memoryManager.freeRaw(lc);
	}

	void snapshotStackObjects();
	void saveStackObject(void* addr);
	void markLiveLocal(int8_t liveCode, REF_TYPE scanRefLevel, GcResult* gcResult);
	void markReachLocal(int8_t liveCode, REF_TYPE scanRefLevel, GcResult* gcResult);
	void markLiveAll(int8_t liveCode, REF_TYPE scanRefLevel, GcResult* gcResult);
	void markReachAll(int8_t liveCode, REF_TYPE scanRefLevel, GcResult* gcResult);
	void clearPendingManager4Gc();

	int32_t skipAsyncLocalGcCount = 0;

	void markLiveAllPending(int8_t liveCode, REF_TYPE scanRefLevel, GcResult* gcResult);
	void markLiveLocalPending(int8_t liveCode, REF_TYPE scanRefLevel, GcResult* gcResult);
	template<typename LiveMarker, typename ReachMarker>
	void markLivePending(int8_t liveCode, REF_TYPE scanRefLevel, GcResult* gcResult);

	void relist4New(GcType gcType, GcResult* gcResult);
	void moveGlobalObjects(GcType gcType, GcResult* gcResult);
	template<typename LiveMarker>
	void markLive(int8_t liveCode, REF_TYPE scanRefLevel, GcResult* gcResult);
	template<typename ReachMarker>
	void markReach(int8_t liveCode, REF_TYPE scanRefLevel, GcResult* gcResult);
	void processLocalObject(int8_t liveCode, GcType gcType, GcResult* gcResult);
	void freeLocalObject(GcType gcType, ObjectList* toFreeList, GcResult* gcResult);
	void markLocalLive4RefCount(int8_t liveCode, REF_TYPE scanRefLevel, GcResult* gcResult);
	void processLocalObjectWithRefCount(int8_t liveCode, GcType gcType, GcResult* gcResult);
	
	void localGc(REF_TYPE scanRefLevel);
	void asyncLocalGc(REF_TYPE scanRefLevel, GcResult* gcResult);
	void fullGc(REF_TYPE scanRefLevel);
	
#ifdef ENABLE_OBJECT_REF_COUNT
	void localGcWithRefCount(REF_TYPE scanRefLevel);
#endif

	inline Object0* allocInternal(Class* clazz, int64_t size, bool throwIfOOM);
	inline ObjectHead* allocLocalObject0(int64_t size);
	//inline ObjectHead* allocLocalObject(Class* clazz, int64_t size);
	inline void freeLocalObject(GcType gcType, ObjectHead* oh);
#ifdef ENABLE_OBJECT_REF_COUNT
	inline void clearLocalRefForFree(ObjectHead* oh);
#endif
	void freeAllocs();
	void optAllocs(bool isFinalFullGc);

	inline StoredMemoryAllocater* createAllocater(int32_t slabIndex) {
		StoredMemoryAllocater* oa = memoryManager.createAllocater(slabIndex);
		if (oa != nullptr) {
			statLocal.allocAllocater();
		}
		return oa;
	}
	inline void freeAllocater(StoredMemoryAllocater* allocater) {
		memoryManager.freeAllocater(allocater);
		statLocal.freeAllocater();
	}

	void init(Thread* thread);
	void deinit();

	template<typename T>
	inline void clearLocalObjects(T& objects);

	template<typename T>
	inline void savePending4Gc(T obj);

	inline void scanMarkGlobal(ObjectHead* oh);

	ScanContextPendingManager scanMarkGlobalPendingManager;
	ScanMarkGlobal scanMarkGlobalScanner;
	inline void scanMarkGlobal0(std::nullptr_t) {}
	template<typename T>
	inline void scanMarkGlobal0(T* obj);

#ifdef ENABLE_OBJECT_REF_COUNT
	inline static void addRefCount(std::nullptr_t) {
	}

	inline static void addRefCount(ObjectHead* oh) {
#ifdef OBJECT_DEBUG
		if (oh->isDebug() || !oh->isUsed()) {
			debugObjectHead("addRefCount", oh);
		}
#endif
		if (oh->isGlobal()) {
			//oh->fetchAddGlobalRefCount();
		} else {
			oh->fetchAddLocalRefCount();
		}
	}

	template<typename T>
	inline static void addRefCount(T* obj) {
		Object0* obj0 = toObject0(obj);
		ObjectHead* oh = toOh(obj0);
		addRefCount(oh);
	}

	template<typename T>
	inline static void addRefCount(T* obj, int32_t count) {
		Object0* obj0 = toObject0(obj);
		ObjectHead* oh = toOh(obj0);
#ifdef OBJECT_DEBUG
		if (oh->isDebug() || !oh->isUsed()) {
			debugObjectHead("addRefCount", oh);
		}
#endif
		if (oh->isGlobal()) {
			//oh->fetchAddGlobalRefCount(count);
		} else {
			oh->fetchAddLocalRefCount(count);
		}
	}

	inline static void releaseRefCount(ObjectHead* oh) {
#ifdef OBJECT_DEBUG
		if (oh->isDebug() || !oh->isUsed()) {
			debugObjectHead("releaseRefCount", oh);
		}
#endif
		if (oh->isGlobal()) {
			//oh->fetchSubGlobalRefCount();
		} else {
			oh->fetchSubLocalRefCount();
		}
	}

	template<typename T>
	inline static void releaseRefCount(T* obj) {
		Object0* obj0 = toObject0(obj);
		ObjectHead* oh = toOh(obj0);
		releaseRefCount(oh);
	}
#else
	#define releaseRefCount(x)
#endif

	inline void clearVarStackRemain() {
// #ifdef OBJECT_DEBUG
// 		int32_t remainIndex = varStackRemainIndex;
// 		while (remainIndex > varStackEndIndex) {
// 			remainIndex--;
// 			varStack[remainIndex] = nullptr;
// 		}
// #else
		//objectStack.varStackRemainIndex = objectStack.varStackEndIndex;
		objectStack.varStackRemain = objectStack.varStackEnd;
// #endif
	}

	template<typename T>
	inline void throwNew() {
		T* ex = $alloc(T);
		$throw(ex);
	}
/*
	inline void pushLocalVar(Object** addr) {
		// clearVarStackRemain();
		objectStack->varStack[objectStack->varStackEndIndex] = addr;
		$storestore();
		objectStack->varStackEndIndex++;
		if (objectStack->varStackEndIndex >= $lengthOf(objectStack->varStack)) {
			throwNew<StackOverflowError>();
		}
		objectStack->varStackRemainIndex = objectStack->varStackEndIndex;
	}

	inline void popLocalVar() {
		objectStack->varStackEndIndex--;
		void* addr = objectStack->varStack[objectStack->varStackEndIndex];
		if (addr != nullptr) {
			objectStack->varStack[objectStack->varStackEndIndex] = *(Object**)addr;
		}
#ifdef OBJECT_DEBUG
		if (varStackEndIndex < 0) {
			throwNew<StackOverflowError>();
		}
		//Object* obj = (Object*)varStack[varStackEndIndex];
		//if (isDebug(obj)) {
		//	debugObject("popLocalVar", obj);
		//}
#endif
	}

	// make sure obj never be null
	inline void pushLocalRef(Object$* obj) {
#ifdef OBJECT_DEBUG
		//if (isDebug(obj)) {
		//	debugObject("pushLocalRef", obj);
		//}
#endif
		objectStack->refStack[objectStack->refStackEndIndex] = (Object*)obj;
		$storestore();
		objectStack->refStackEndIndex++;
		if (objectStack->refStackEndIndex >= $lengthOf(objectStack->refStack)) {
			throwNew<StackOverflowError>();
		}
	}

	inline void popLocalRef() {
#ifdef OBJECT_DEBUG
		//Object* obj = (Object*)varStack[varStackEndIndex - 1];
		//if (isDebug(obj)) {
		//	debugObject("popLocalRef", obj);
		//}
#endif
		objectStack->refStackEndIndex--;
#ifdef OBJECT_DEBUG
		if (refStackEndIndex < 0) {
			throwNew<StackOverflowError>();
		}
#endif
	}
	*/
	inline void pushLocalFrame(int32_t capacity) {
		jniLocalRefStackFrameIndex++;
		if (this->jniLocalRefStackFrameIndex >= jniLocalRefStackFrameSize) {
			throwNew<StackOverflowError>();
		}
		jniLocalRefStackFrame[jniLocalRefStackFrameIndex].begin = jniLocalRefStackEndIndex;
	}

	inline void popLocalFrame() {
		if (jniLocalRefStackFrameIndex <= 0) {
			throwNew<StackOverflowError>();
		}
		int32_t begin = jniLocalRefStackFrame[jniLocalRefStackFrameIndex].begin;	
		while (jniLocalRefStackEndIndex > begin) {
			jniLocalRefStackEndIndex--;
			if (jniLocalRefStackEndIndex < 0) {
				throwNew<StackOverflowError>();
			}
			Object0* obj = jniLocalRefStack[jniLocalRefStackEndIndex];
			if (obj != nullptr) {
				//HANDLE_ASSIGN_4GC(nullptr, obj);
				jniLocalRefStack[jniLocalRefStackEndIndex] = nullptr;
#ifdef OBJECT_DEBUG
				if (isDebug(obj)) {
					debugObject("popLocalFrame", obj);
				}
#endif
			}
		}
		jniLocalRefStackFrameIndex--;
	}

	inline void newLocalRef(Object$* obj) {
		if (obj != nullptr) {
	#ifdef OBJECT_DEBUG
			if (isDebug(obj)) {
				debugObject("newLocalRef", obj);
			}
	#endif
			Object0* obj0 = toObject0(obj);
			//HANDLE_ASSIGN_4GC(obj0, nullptr);
			jniLocalRefStack[jniLocalRefStackEndIndex] = obj0;
			$storestore();
			jniLocalRefStackEndIndex++;
			if (jniLocalRefStackEndIndex >= jniLocalRefStackSize) {
				throwNew<StackOverflowError>();
			}
		}
	}

	inline void deleteLocalRef(Object$* obj) {
		if (obj == nullptr) {
			return;
		}
		if (jniLocalRefStackFrameIndex < 0 || jniLocalRefStackFrameIndex >= jniLocalRefStackFrameSize) {
			throwNew<StackOverflowError>();
		}
#ifdef OBJECT_DEBUG
		if (isDebug(obj)) {
			debugObject("deleteLocalRef", obj);
		}
#endif
		Object0* obj0 = toObject0(obj);
		int32_t begin = jniLocalRefStackFrame[jniLocalRefStackFrameIndex].begin;
		if (jniLocalRefStack[jniLocalRefStackEndIndex - 1] == obj0) {
			//HANDLE_ASSIGN_4GC(nullptr, obj0);
			jniLocalRefStack[jniLocalRefStackEndIndex - 1] = nullptr;
			//releaseRefCount(obj0);
			jniLocalRefStackEndIndex--;
			while (jniLocalRefStackEndIndex > begin) {
				if (jniLocalRefStack[jniLocalRefStackEndIndex - 1] == nullptr) {
					jniLocalRefStackEndIndex--;
				} else {
					break;
				}
			}
		} else {
			int32_t index = jniLocalRefStackEndIndex - 2;
			while (index >= begin) {
				if (jniLocalRefStack[index] == obj0) {
					//HANDLE_ASSIGN_4GC(nullptr, obj0);
					jniLocalRefStack[index] = nullptr;
					//releaseRefCount(obj0);
					break;
				}
				index--;
			}
		}
	}

	void expungeStaleEntries4ThreadLocal() {
		if (thread != nullptr) {
			if (thread->threadLocals != nullptr) {
				thread->threadLocals->expungeStaleEntries();
			}
			if (thread->inheritableThreadLocals != nullptr) {
				thread->inheritableThreadLocals->expungeStaleEntries();
			}
		}
	}
//#define MAX_NEW_NORMAL_LIST_LOCAL 512
//	ObjectHead* newNormalListLocal[MAX_NEW_NORMAL_LIST_LOCAL];
//	int32_t newNormalListLocalCount = 0;
	AtomicObjectList newNormalListLocal0;
	ObjectList newNormalListLocal1;
	AtomicObjectList newRefListLocal;
	AtomicObjectList newHasFinalizeListLocal;
	static const int normalListCount = 10;
	int32_t processCount = 0;
	ObjectList normalListLocal[normalListCount];
	ObjectList refListLocal;
	ObjectList hasFinalizeListLocal;

	char threadName[32];
	bool daemon;
	bool exiting;
	std::mutex mutexLocal;
	std::condition_variable cvLocal;

	LocalControllerStat statLocal;
	LocalControllerStat statLocalSum;

	AddSubCountSize objectCSLocal;
	CountSize pendingObjectCS;

	int32_t liveCodeSequenceLocal = 1;

	std::atomic<GcStatus> gcStatusLocal = GC_STATUS_NONE;
	int8_t liveCodeLocal = 0;
	bool mainThread = false;
	//std::atomic_bool waiting = false;

	//int32_t gcCount = 0;
	// bool enableLocalRef = true;
	LocalControllerStatus status = LC_STATUS_NONE;
	//bool markRefCountInScanMarkLive = false;
	volatile bool asyncLocalGcEvent = false;
	//std::atomic_bool localStop4gc = false;
	volatile bool localStop4gc = false;
	int64_t stopNSLocal = 0;
	volatile bool fullGcing = false;
	int32_t refCountGcCount = 0;

	StoredMemoryAllocater* objectAllocaterLocalCurrent[SLAB_COUNT] = {}; // only access by current thread
	AtomicMemoryAllocaterList objectAllocaterLocal[SLAB_COUNT] = {}; // will access by other thread
	AtomicMemoryAllocaterList objectAllocaterLocalPending[SLAB_COUNT] = {}; // will access by other thread

	//ScanContextPendingManager pendingManager4GcLocal;
	volatile bool savePendingLocal = false;
	GcHandlePendingSaver pendingSaver;
	//std::mutex pendingManager4GcMutexLocal;
	//SpinLock pendingManager4GcSpinLockLocal;
	LocalController* next = nullptr;

	StackObjects stackObjects;

	ObjectStack objectStack;
	//void* varStack[JCPP_MAX_VAR_STACK_SIZE];
	//Object* refStack[JCPP_MAX_REF_STACK_SIZE];
	// void* varStack[MAX_VAR_STACK_SIZE];
	// int32_t varStackEndIndex = 0;
	// volatile int32_t varStackRemainIndex = 0;

	// Object* refStack[MAX_REF_STACK_SIZE];
	// int32_t refStackEndIndex = 0;

	// for JNI newLocalRef, deleteLocalRef
	int64_t varStackSize;
	int64_t refStackSize;
	int64_t jniLocalRefStackSize;
	int64_t jniLocalRefStackFrameSize;

	Object0** jniLocalRefStack;// [MAX_JNI_LOCAL_REF_STACK_SIZE] ;
	int32_t jniLocalRefStackEndIndex = 0;

	int32_t jniLocalRefStackFrameIndex = 0;
	LocalFrame* jniLocalRefStackFrame;// [MAX_JNI_LOCAL_REF_STACK_FRAME_SIZE] ;

	Throwable* pendingThrowable = nullptr;

	Thread* thread = nullptr;
	CoreObject* javaThread = nullptr;
	void* stackBase = nullptr;
	int64_t stackSize;

	void* getStackBase() const {
		return stackBase;
	}
	int64_t getStackSize() const {
		return stackSize;
	}
	void* getStackEnd()  const {
		return (char*)getStackBase() - getStackSize();
	}
};

using StaticPointerManager = YYSet<Object*, Allocator<Object*>>;

using LocalControllerAtomicList = AtomicSList<LocalController>;
using LocalControllerAtomicListIterator = AtomicSListIterator<LocalController>;

class GlobalController {
public:
	GlobalController() {
	}

	void init() {
		staticPointerManager.init();
		initFinalizerStore();
		initThrowableStore();
		initGcHandlePendingStore();
		initScanContextPendingStore();
	}

	int32_t makeScanCount(ObjectHead* oh);

	int32_t makeRefScanCount(ObjectHead* oh);

	void deinit(bool force);

	void debugAnalayzeOH(ObjectHead* oh) {
#ifdef OBJECT_DEBUG
		$var(String, name, oh->clazz->getName());
		if (name->equals("[Ljava.lang.Thread;")) {
			log_info("%" PRId64 " %s\n", oh->id, name->c_str());
		}
#endif
	}

	void countSizeStoredMemoryAllocater(StoredMemoryAllocater* allocater, CountSize& cacheCS) {
		if (allocater != nullptr) {
			StoredMemoryBlock* block = allocater->allocingList.head;
			while (block != nullptr) {
				cacheCS.add(block->getMemorySize());
				block = block->next;
			}
			block = allocater->freeList.head;
			while (block != nullptr) {
				cacheCS.add(block->getMemorySize());
				block = block->next;
			}
			block = allocater->freeingList.head;
			while (block != nullptr) {
				cacheCS.add(block->getMemorySize());
				block = block->next;
			}
		}
	}
	void analayzeMemory() {
		log_debug("GlobalController::analayzeMemory() enter\n");
		int32_t allocaterCountFree = 0;
		int32_t allocaterCountLocal = 0;
		CountSize cacheCSLocal;
		CountSize cacheCSGlobal;

		log_debug("GlobalController::analayzeMemory() 1\n");
		LocalControllerAtomicListIterator it = LocalControllerAtomicListIterator(&localControllerList);
		while (it.has()) {
			LocalController* controller = it.get();
			it.next();
			for (int i = 0; i < SLAB_COUNT; i++) {
				StoredMemoryAllocater* allocater = controller->objectAllocaterLocalCurrent[i];
				if (allocater != nullptr) {
					countSizeStoredMemoryAllocater(allocater, cacheCSLocal);
					allocaterCountLocal++;
				}
				{
					StoredMemoryAllocater* allocaterHead = controller->objectAllocaterLocal->exchange(nullptr);
					StoredMemoryAllocater* allocater = allocaterHead;
					while (allocater != nullptr) {
						countSizeStoredMemoryAllocater(allocater, cacheCSLocal);
						allocater = allocater->next;
						allocaterCountLocal++;
					}
					controller->objectAllocaterLocal->exchange(allocaterHead);
				}
				{
					StoredMemoryAllocater* allocaterHead = controller->objectAllocaterLocalPending->exchange(nullptr);
					StoredMemoryAllocater* allocater = allocaterHead;
					while (allocater != nullptr) {
						countSizeStoredMemoryAllocater(allocater, cacheCSLocal);
						allocater = allocater->next;
						allocaterCountLocal++;
					}
					controller->objectAllocaterLocalPending->exchange(allocaterHead);
				}
			}
		}

		//for (int i = 0; i < SLAB_COUNT; i++) {
		//	StoredMemoryAllocater* allocaterHead = memoryManager.allocaters[i].exchange(nullptr);
		//	ListScaner<StoredMemoryAllocater> scaner;
		//	scaner.scan(allocaterHead);
		//	StoredMemoryAllocater* allocater = allocaterHead;
		//	while (allocater != nullptr) {
		//		countSizeStoredMemoryAllocater(allocater, cacheCSGlobal);
		//		allocater = allocater->next;
		//	}
		//	memoryManager.allocaters[i].exchange(allocaterHead);
		//	allocaterCountFree += scaner.length;
		//}
		{
			log_debug("GlobalController::analayzeMemory() 2\n");
			StoredMemoryAllocater* allocaterHead = memoryManager.pendingAllocaters.exchange(nullptr);
			ListScaner<StoredMemoryAllocater> scaner;
			scaner.scan(allocaterHead);
			StoredMemoryAllocater* allocater = allocaterHead;
			while (allocater != nullptr) {
				countSizeStoredMemoryAllocater(allocater, cacheCSGlobal);
				allocater = allocater->next;
			}
			memoryManager.pendingAllocaters.exchange(allocaterHead);
			allocaterCountFree += scaner.length;
		}
		{
			log_debug("GlobalController::analayzeMemory() 3\n");
			StoredMemoryAllocater* allocaterHead = memoryManager.allocaterCacheList.exchange(nullptr);
			ListScaner<StoredMemoryAllocater> scaner;
			scaner.scan(allocaterHead);
			StoredMemoryAllocater* allocater = allocaterHead;
			while (allocater != nullptr) {
				countSizeStoredMemoryAllocater(allocater, cacheCSGlobal);
				allocater = allocater->next;
			}
			memoryManager.allocaterCacheList.exchange(allocaterHead);
			allocaterCountFree += scaner.length;
		}
		log_info("memory memory, allocater(%" PRId32 ", %" PRId32 ") cacheLocal(%" PRId64 ", %" PRId64 ") cacheGlobal(%" PRId64 ", %" PRId64 ")\n",
			allocaterCountLocal, allocaterCountFree, cacheCSLocal.count, cacheCSLocal.size, cacheCSGlobal.count, cacheCSGlobal.size);
		log_debug("GlobalController::analayzeMemory() leave\n");
	}
	void analayzeGlobalObject() {
		log_debug("GlobalController::analayzeGlobalObject() enter\n");
		CountSize normalListGlobalCS;
		CountSize staticListGlobalCS;
		CountSize constListGlobalCS;
		CountSize refListGlobalCS;
		CountSize refPendingListGlobalCS;
		CountSize hasFinalizeListGlobalCS;
		CountSize hasFinalizePendingListGlobalCS;
		CountSize waitToDispatchListGlobalCS;

		std::map<Class*, std::pair<int64_t, int64_t>> mmm;

		{
			ObjectListIterator it(&constListGlobal);
			int32_t i = 0;
			while (it.has()) {
				ObjectHead* oh = it.get();
				if (oh->clazz == String::class$) {
			//		String* s = (String*)toObject0(oh);
			//		char ss[512];
			//		s->c_utf8(ss, 512);
			//		log_info("%d %s\n", i++, ss);
				}
				debugAnalayzeOH(oh);
				//constListGlobalCount++;
				constListGlobalCS.add(getMemorySize(oh));
				it.next();
			}
		}

		{
			ObjectListIterator it(&staticListGlobal);
			while (it.has()) {
				ObjectHead* oh = it.get();
				//staticListGlobalCount++;
				staticListGlobalCS.add(getMemorySize(oh));
				debugAnalayzeOH(oh);
				it.next();
			}
		}

		{
			ObjectListIterator it(&refPendingListGlobal);
			while (it.has()) {
				ObjectHead* oh = it.get();
				//refPendingListGlobalCount++;
				refPendingListGlobalCS.add(getMemorySize(oh));
				debugAnalayzeOH(oh);
				it.next();
			}
		}

		{
			ObjectListIterator it(&refListGlobal);
			while (it.has()) {
				ObjectHead* oh = it.get();
				//refListGlobalCount++;
				refListGlobalCS.add(getMemorySize(oh));
				auto it2 = mmm.find(oh->clazz);
				if (it2 != mmm.end()) {
					it2->second.first++;
					it2->second.second += getMemorySize(oh);
				} else {
					mmm.insert(std::make_pair(oh->clazz, std::make_pair(1, getMemorySize(oh))));
				}
				debugAnalayzeOH(oh);
				it.next();
			}
		}

		{
			ObjectListIterator it(&hasFinalizeListGlobal);
			while (it.has()) {
				ObjectHead* oh = it.get();
				//hasFinalizeListGlobalCount++;
				hasFinalizeListGlobalCS.add(getMemorySize(oh));
				debugAnalayzeOH(oh);
				it.next();
			}
		}
		// 
		{
			ObjectListIterator it(&hasFinalizePendingListGlobal);
			while (it.has()) {
				ObjectHead* oh = it.get();
				//hasFinalizeListGlobalCount++;
				hasFinalizePendingListGlobalCS.add(getMemorySize(oh));
				debugAnalayzeOH(oh);
				it.next();
			}
		}
		// 
		{
			AtomicObjectListIterator it(&waitToDispatchListGlobal);
			while (it.has()) {
				ObjectHead* oh = it.get();
				//hasFinalizeListGlobalCount++;
				waitToDispatchListGlobalCS.add(getMemorySize(oh));
				debugAnalayzeOH(oh);
				it.next();
			}
		}
		{
			ObjectListIterator it(&staticListGlobal);
			while (it.has()) {
				ObjectHead* oh = it.get();
				if (oh->clazz == ::java::lang::interpreter::ByteCodeClass::class$) {
					::java::lang::interpreter::ByteCodeClass* bcc = (::java::lang::interpreter::ByteCodeClass*)fromOh(oh);
					if (bcc->classInfo != nullptr) {
			//			log_info("@@@@@@@@@%s\n", bcc->classInfo->name);
					} else {
			//			log_info("@@@@@@@@@%s\n", "na");
					}
				}
				auto it2 = mmm.find(oh->clazz);
				if (it2 != mmm.end()) {
					it2->second.first++;
					it2->second.second += getMemorySize(oh);
				} else {
					mmm.insert(std::make_pair(oh->clazz, std::make_pair(1, getMemorySize(oh))));
				}
				debugAnalayzeOH(oh);
				it.next();
			}
		}

		if (true) {
			ObjectListIterator it(&normalListGlobal);
			while (it.has()) {
				ObjectHead* oh = it.get();
				//normalListGlobalCount++;
				normalListGlobalCS.add(getMemorySize(oh));
				auto it2 = mmm.find(oh->clazz);
				if (it2 != mmm.end()) {
					it2->second.first++;
					it2->second.second += getMemorySize(oh);
				} else {
					mmm.insert(std::make_pair(oh->clazz, std::make_pair(1, getMemorySize(oh))));
				}
				$var(String, name, oh->clazz->getName());
				if (name->equals("java.lang.interpreter.ByteCodeClass")) {
					::java::lang::interpreter::ByteCodeClass* clazz = (::java::lang::interpreter::ByteCodeClass*)fromOh(oh);
				//	log_info(" \n");
				}
				debugAnalayzeOH(oh);
				it.next();
			}
		}

		while (!mmm.empty()) {
			Class* clazz = nullptr;
			int64_t count = 0;
			int64_t size = 0;
			auto it = mmm.begin();
			while (it != mmm.end()) {
				if (clazz == nullptr) {
					clazz = it->first;
					count = it->second.first;
					size = it->second.second;
				} else if (size < it->second.second) {
					clazz = it->first;
					count = it->second.first;
					size = it->second.second;
				}
				++it;
			}
			mmm.erase(clazz);
			if (size > 1000) {
				$var(String, name, clazz->getName());
				log_info("%s %" PRId64 ", %" PRId64 "\n", name->c_str(), count, size);
			}
		}
		log_info("global object, const(%" PRId64 ", %" PRId64 ") static(%" PRId64 ", %" PRId64 ") refPending(%" PRId64 ", %" PRId64 ")"
			" ref(%" PRId64 ", %" PRId64 ") finalize(%" PRId64 ", %" PRId64 ")"
			" finalizePending(%" PRId64 ", %" PRId64 ") normal(%" PRId64 ", %" PRId64 ") wait(%" PRId64 ", %" PRId64 ")\n",
			constListGlobalCS.count, constListGlobalCS.size, staticListGlobalCS.count, staticListGlobalCS.size,
			refPendingListGlobalCS.count, refPendingListGlobalCS.size, refListGlobalCS.count, refListGlobalCS.size, hasFinalizeListGlobalCS.count, hasFinalizeListGlobalCS.size,
			hasFinalizePendingListGlobalCS.count, hasFinalizePendingListGlobalCS.size, normalListGlobalCS.count, normalListGlobalCS.size,
			waitToDispatchListGlobalCS.count, waitToDispatchListGlobalCS.size);

		log_debug("GlobalController::analayzeGlobalObject() leave\n");
	}

	void recordStaticPointer(Object** pointer) {
		// TODO use more locks
		lock_guard lock(mutexStaticPointerManager);
		staticPointerManager.add(pointer);
	}

	bool existsNonDaemonThread();
	void printThreads();

	void fullGc0(REF_TYPE scanRefLevel, GcResult* gcResult);

	void asyncLocalGc(REF_TYPE scanRefLevel, bool force, GcResult* gcResult);

	void registerLocalController(LocalController* controller) {
		controller->status = LC_STATUS_RUN;
		localControllerList.prepend(controller);
	}

	void unregisterLocalController(LocalController* controller) {
		std::lock_guard lock(mutexGlobal);
		controller->pendingThrowable = nullptr;
		controller->jniLocalRefStackEndIndex = 0;
		controller->jniLocalRefStackFrameIndex = 0;
		controller->objectStack.varStackEnd = 0;
		controller->objectStack.varStackRemain = 0;
		controller->objectStack.refStackEnd = 0;
		controller->status = LC_STATUS_STOP;
	}

	LocalController* getLocalController(Thread* thread) {
		std::lock_guard lock(this->mutexGlobal);
		LocalControllerAtomicListIterator it = LocalControllerAtomicListIterator(&localControllerList);
		while (it.has()) {
			LocalController* controller = it.get();
			if (controller->thread == thread) {
				return controller;
			}
			it.next();
		}
		return nullptr;
	}

	$Array<Thread>* getAllThreads() {
		int32_t count = 0;
		{
			std::lock_guard lock(this->mutexGlobal);
			LocalControllerAtomicListIterator it = LocalControllerAtomicListIterator(&localControllerList);
			while (it.has()) {
				count++;
				it.next();
			}
		}
		$var($Array<Thread>, threads, $new<$Array<Thread>>(count));
		count = 0;
		{
			std::lock_guard lock(this->mutexGlobal);
			LocalControllerAtomicListIterator it = LocalControllerAtomicListIterator(&localControllerList);
			while (it.has()) {
				if (count >= threads->length) {
					break;
				}
				LocalController* controller = it.get();
				threads->set(count, controller->thread);
				count++;
				it.next();
			}
		}
		if (threads->length == count) {
			return threads;
		}
		return ($Array<Thread>*)threads->subArray(0, count);
	}

	void processGlobalObject(GcResult* gcResult);
	void processHasFinalizePendingQueueGlobal();

	void markLiveGlobal(REF_TYPE scanRefLevel, GcResult* gcResult);
	void markLiveAllPending(int8_t liveCode, REF_TYPE scanRefLevel, GcResult* gcResult);
	void markReachGlobal(REF_TYPE scanRefLevel, GcResult* gcResult);

	inline void addToPendingList(Reference* ref) {
		//$debug(ref);
		// log_info("addToPendingList %"PRId64"\n", ::java::lang::System::currentTimeMillis());
		if (ref->queue == nullptr) {
			$set(ref, queue, ReferenceQueue::NULL);
		}
		$set(ref, discovered, refPendingList);
		refPendingList = ref;
	}

	Reference* getAndClearReferencePendingList() {
		{
			std::lock_guard lock(this->mutexGlobal);
			$var(Reference, ref, refPendingList);
			refPendingList = nullptr;
			if (ref != nullptr) {
				//log_debug("getAndClearReferencePendingList\n");
			}
			return ref;
		}
	}

	bool hasReferencePendingList() {
		bool ret = false;
		{
			std::lock_guard lock(this->mutexGlobal);
			ret = refPendingList != nullptr;
		}
		return ret;
	}

	void waitForReferencePendingList() {
		//try {
			std::unique_lock lock(this->mutexGlobal);
			if (refPendingList == nullptr) {
				this->cvGlobal.wait(lock);
			}
		//} catch (Throwable&) { // InterruptedException avoid OutOfMemoryError
		//}
	}

	inline void addWaitToDispatch(ObjectHead* oh, int64_t size) {
		pendingObjectCSGlobal.add(size);
		waitToDispatchListGlobal.prepend(oh);
	}

	inline void dispatchGlobal(ObjectHead* oh) {
#ifdef OBJECT_DEBUG
		if (oh->isDebug() || !oh->isUsed()) {
			debugObjectHead("dispatchGlobal", oh);
		}
#endif
		int64_t size = getMemorySize(oh);
		objectCSGlobal.add(size);
		if (oh->isConst()) {
			constListGlobal.prepend(oh);
		} else if (oh->isRef()) {
			if (oh->isRefPending()) {
				refPendingListGlobal.prepend(oh);
			} else {
				refListGlobal.prepend(oh);
			}
		} else if (oh->isStatic()) {
			staticListGlobal.prepend(oh);
		} else if (oh->isHasFinalize()) {
			if (oh->isHasFinalizePending()) {
				hasFinalizePendingListGlobal.prepend(oh);
			} else {
				hasFinalizeListGlobal.prepend(oh);
			}
		} else {
			normalListGlobal.prepend(oh);
		}
	}

	inline void moveInFromLocal(GcType gcType, ObjectHead* oh, int64_t size) {
		if (gcType == GC_TYPE_FULL) {
			dispatchGlobal(oh);
		} else {
			addWaitToDispatch(oh, size);
		}
	}

	inline void dispatchWaitingObjects() {
		ObjectHead* listHead = waitToDispatchListGlobal.exchange(nullptr);
		ObjectList listTemp(listHead);
		ObjectHead* oh = listTemp.removeFirst();
		while (oh != nullptr) {
			dispatchGlobal(oh);
			oh = listTemp.removeFirst();
		}
	}

	inline void dispatchWaitingObjectsAndClearLiveReach() {
		ObjectHead* listHead = waitToDispatchListGlobal.exchange(nullptr);
		ObjectList listTemp(listHead);
		ObjectHead* oh = listTemp.removeFirst();
		while (oh != nullptr) {
			oh->setLive(0);
			dispatchGlobal(oh);
			oh = listTemp.removeFirst();
		}
	}

	inline ObjectHead* allocStatic0(int64_t size) {
		int64_t payloadSize = sizeof(ObjectHead) + size;
		ObjectHead* oh = memoryManager.allocObjectStaticOrNull(payloadSize);
		if (oh != nullptr) {
			oh->setStatic();
			staticCSGlocal.add(getMemorySize(oh));
		}
		return oh;
	}

	inline Object0* allocStatic(Class* clazz, int64_t size, bool isConst, bool throwIfOOM) {
		$nullcheck(clazz);
		ObjectHead* oh = nullptr;
		oh = allocStatic0(size);
		if (oh == nullptr) {
			GcResult gcResult(GC_TYPE_FULL);
			fullGc0(OBJECT_REF_TYPE_FINAL, &gcResult);
			oh = allocStatic0(size);
			if (oh == nullptr) {
				if (throwIfOOM) {
					log_warning("allocStatic OutOfMemoryError size:%" PRId64 "\n", size);
					$throwNew(OutOfMemoryError);
				} else {
					return nullptr;
				}
			}
		}

	#ifdef OBJECT_DEBUG
		oh->obj = fromOh(oh);
		//oh->newTime = System::currentTimeMillis();
		oh->id = newIndex;
		oh->debug = "allocStatic";
		newIndex++;
		oh->newLiveCodeGlobal = liveCodeGlobal;
	#endif
		oh->clazz = clazz;
		oh->setGlobal();
		if (isConst) {
			oh->setConst();
		}
		oh->setUsed();
#ifdef ENABLE_OBJECT_REF_COUNT
		oh->fetchAddGlobalRefCount();
#endif

		if (oh->isConst()) {
			constListGlobal.prepend(oh);
		} else {
			staticListGlobal.prepend(oh);
		}
		int64_t ohSize = getMemorySize(oh);
		statCurrentGobal.alloc(ohSize);
		//statCurrentGobal.addObject(ohSize);
		return fromOh(oh);
	}

	void freeGlobal0(ObjectHead* oh) {
#ifdef OBJECT_DEBUG
		if (oh->isDebug() || !oh->isUsed()) {
			debugObjectHead("freeGlobal0", oh);
		}
		oh->freeLiveCodeGlobal = liveCodeGlobal;
		//oh->clearUsed();
		//return;
#endif
		freeObjectMonitor(oh);

		if (oh->isInline()) {
			oh->clearUsed();
		} else {
			//MemoryAllocater* oa = getMemoryAllocater(oh);
			//if (oa == nullptr) {
				memoryManager.freeObject(oh);
			//} else {
			//	oa->free(oh);
			//}
		}
	}

	// must call in fullGc
	void freeGlobal(ObjectHead* oh) {
		int64_t size = getMemorySize(oh);
		//statCurrentGobal.removeObject(size);
		objectCSGlobal.sub(size);
		freeGlobal0(oh);
	}

	Class* allocClassClass() {
		ObjectHead* oh = allocStatic0(sizeof(Class));
	#ifdef OBJECT_DEBUG
		oh->obj = fromOh(oh);
		oh->debug = "allocClassClass";
	#endif
		oh->setGlobal();
		staticListGlobal.prepend(oh);
		
		int64_t ohSize = getMemorySize(oh);
		//statCurrentGobal.addObject(ohSize);
		statCurrentGobal.alloc(ohSize);

		Object0* obj = fromOh(oh);

	//	normalQueueLocal.prepend(oh);
	//	allQueueStatLocal.add(oh->bodySize);
	//	pendingObjectCount++;
	//	pendingObjectSize += oh->bodySize;

		Class* clazz = new(obj) Class();
		oh->clazz = clazz;
		oh->setUsed();
		clazz->size = sizeof(Class);
		return clazz;
	}

	void initFinalizerStore() {
		int32_t objectSize = (int32_t)(sizeof(ObjectHead) + sizeof(Finalizer));
		const int32_t objectCount = 1024;
		finalizerStore = memoryManager.createStore(objectSize, objectCount);
		if (finalizerStore == nullptr) {
			log_error("out of memory error, initFinalizerStore %" PRId32 "\n", objectSize * objectCount);
			exit(1);
		}
	}

	void initThrowableStore() {
		int32_t objectSize = (int32_t)(sizeof(ObjectHead) + sizeof(Throwable) + 16);
		const int32_t objectCount = 64;
		throwableStore = memoryManager.createStore(objectSize, objectCount);
		if (throwableStore == nullptr) {
			log_error("out of memory error, initThrowableStore %" PRId32 "\n", objectSize * objectCount);
			exit(1);
		}
	}

	void initGcHandlePendingStore() {
		int32_t objectSize = (int32_t)sizeof(GcHandlePending);
		//const int32_t objectCount = 16;
		gcHandlePendingAllocater = memoryManager.createCachedRawMemoryAllocater(objectSize);
		if (gcHandlePendingAllocater == nullptr) {
			log_error("out of memory error, initGcHandlePendingStore\n");
			exit(1);
		}
		gcHandlePendingAllocater->setMinCacheCount(8);
	}

	void initScanContextPendingStore() {
		int32_t objectSize = (int32_t)sizeof(ScanContextPending);
		const int32_t objectCount = 16;
		scanContextPendingAllocater = memoryManager.createCachedRawMemoryAllocater(objectSize);
		if (scanContextPendingAllocater == nullptr) {
			log_error("out of memory error, initScanContextPendingStore\n");
			exit(1);
		}
		scanContextPendingAllocater->setMinCacheCount(16);
	}

	inline ObjectHead* allocInternalFinalizer() {
		ObjectHead* oh = finalizerStore->allocObject();
		return nullptr;
	}

	inline ObjectHead* allocInternalThrowable() {
		return throwableStore->allocObject();
	}

	inline GcHandlePending* allocGcHandlePending() {
		void* data = (GcHandlePending*)gcHandlePendingAllocater->allocRawOrNull();
		if (data != nullptr) {
			GcHandlePending* aghp = new(data) GcHandlePending();
			return aghp;
		}
		return nullptr;
	}
	inline void freeGcHandlePending(GcHandlePending* m) {
		gcHandlePendingAllocater->free0(m);
	}

	inline ScanContextPending* allocScanContextPending() {
		void* data = (ScanContextPending*)scanContextPendingAllocater->allocRawOrNull();
		if (data != nullptr) {
			ScanContextPending* scp = new(data) ScanContextPending();
			return scp;
		}
		return nullptr;
	}

	int64_t printStatTime = 0;
	void printStat() {
		// return;
	//	statLocalCurrentSum.clear();
		LocalControllerStat statLocalCurrentSum;
		CountSize objectCS;
		int64_t threadCount = 0;
		GlobalControllerStat statCurrentGobal0;
		{
			std::lock_guard lock(this->mutexGlobal);
			LocalControllerAtomicListIterator it = LocalControllerAtomicListIterator(&localControllerList);
			while (it.has()) {
				LocalController* controller = it.get();
				threadCount++;
				statLocalCurrentSum.add(controller->statLocal);
				controller->statLocal.clear();
				objectCS.add(controller->objectCSLocal.count.value(), controller->objectCSLocal.size.value());
				it.next();
			}
			statCurrentGobal0.add(statCurrentGobal);
		}
		statLocalHistorySum.add(statLocalCurrentSum);
		statLocalCurrentSum.print("live");
		statLocalHistorySum.print("sum");
		statCurrentGobal0.print();
		log_info("local object(%" PRId64 ", %" PRId64 ") thread:%" PRId64 " allocater:% " PRId64 "\n",
			objectCS.count, objectCS.size, threadCount, statLocalHistorySum.allocAllocaterCount - statLocalHistorySum.freeAllocaterCount);
		log_info("global object(%" PRId64 ", %" PRId64 ") static(%" PRId64 ", %" PRId64 ") memory(%" PRId64 ", %" PRId64 ")\n",
			objectCSGlobal.count.value(), objectCSGlobal.size.value(),
			staticCSGlocal.count.load(), staticCSGlocal.size.load(),
			memoryManager.getTotalCount(), memoryManager.getTotalSize());
		printStatTime = 0;
	}

	void opt() {
		//LocalControllerAtomicList toFreeLocalControllerList;
		{
			std::lock_guard lock(mutexGlobal);

			processHasFinalizePendingQueueGlobal();

			LocalControllerAtomicListIterator it = LocalControllerAtomicListIterator(&localControllerList);
			while (it.has()) {
				LocalController* controller = it.get();
				if (controller->status == LC_STATUS_STOP) {
					controller->status = LC_STATUS_CLEARING;
				} else if (controller->status == LC_STATUS_CLEARING) {
					it.remove();
					//toFreeLocalControllerList.prepend(controller);
					controller->deinit();
					statLocalHistorySum.add(controller->statLocal);
					LocalController::free(controller);
					continue;
				}
				it.next();
			}
			cvGlobal.notify_all();
		}
		//LocalController* lc = toFreeLocalControllerList.removeFirst();
		//while (lc != nullptr) {
		//	lc->deinit();
		//	statLocalHistorySum.add(lc->statLocal);
		//	LocalController::free(lc);
		//	lc = toFreeLocalControllerList.removeFirst();
		//}
	}

	ObjectList normalListGlobal;
	ObjectList staticListGlobal;
	ObjectList constListGlobal;
	ObjectList refListGlobal;
	ObjectList refPendingListGlobal;
	ObjectList hasFinalizeListGlobal;
	ObjectList hasFinalizePendingListGlobal;
	AtomicObjectList waitToDispatchListGlobal;

	LocalControllerStat statLocalHistorySum;
	GlobalControllerStat statCurrentGobal;

	AddSubCountSize objectCSGlobal;
	CountSize pendingObjectCSGlobal;
	AtomicCountSize staticCSGlocal;
	Reference* refPendingList = nullptr;

	int32_t interrupt = 0;
	int8_t liveCodeGlobal = 0;
	int32_t liveCodeSequenceGlobal = 1;
	LocalControllerAtomicList localControllerList;

	std::mutex mutexGlobal;
	std::condition_variable cvGlobal;

	StaticPointerManager staticPointerManager;
	std::mutex mutexStaticPointerManager;

	MemoryStore* finalizerStore = nullptr;
	MemoryStore* throwableStore = nullptr;
	//MemoryStore* gcHandlePendingStore = nullptr;
	CachedRawMemoryAllocater* gcHandlePendingAllocater = nullptr;
	CachedRawMemoryAllocater* scanContextPendingAllocater = nullptr;
	//MemoryStore* scanContextPendingStore = nullptr;
};

GlobalController* globalController = nullptr;

int32_t gcHandlePendingCount = 0;
int32_t gcHandlePendingMaxCount = 0;
GcHandlePending* GcHandlePending::create() {
	GcHandlePending* aghp = globalController->allocGcHandlePending();
	//if (aghp == nullptr) {
	//	void* data = memoryManager.allocRawOrNull(sizeof(GcHandlePending));
	//	if (data != nullptr) {
	//		aghp = new(data) GcHandlePending();
	//	}
	//}
	if (aghp != nullptr) {
		gcHandlePendingCount++;
		if (gcHandlePendingCount > gcHandlePendingMaxCount) {
			gcHandlePendingMaxCount = gcHandlePendingCount;
			log_debug("gcHandlePendingMaxCount:%" PRId32 "\n", gcHandlePendingMaxCount)
		}
	}
	//void* data = memoryManager.allocRawOrNull(sizeof(GcHandlePending));
	//if (data != nullptr) {
	//	GcHandlePending* aghp = new(data) GcHandlePending();
	//	return aghp;
	//}
	return aghp;
}

void GcHandlePending::free(GcHandlePending* aghp) {
	gcHandlePendingCount--;
	globalController->freeGcHandlePending(aghp);
	//memoryManager.freeRaw(aghp);
}

int32_t scanContextPendingCount = 0;
int32_t scanContextPendingMaxCount = 0;
ScanContextPending* ScanContextPending::create() {
	scanContextPendingCount++;
	if (scanContextPendingCount > scanContextPendingMaxCount) {
		scanContextPendingMaxCount = scanContextPendingCount;
		log_debug("scanContextPendingMaxCount:%" PRId32 "\n", scanContextPendingMaxCount)
	}
	//log_debug("create ScanContextPending\n");
	ScanContextPending* scp = globalController->allocScanContextPending();
	if (scp != nullptr) {
		return scp;
	}
	void* data = memoryManager.allocRawOrExit(sizeof(ScanContextPending));
	scp = new(data) ScanContextPending();
	return scp;
}

void ScanContextPending::free(ScanContextPending* scp) {
	//log_debug("free ScanContextPending\n");
	//globalController->freeGcHandlePending(scp);
	scanContextPendingCount--;
	memoryManager.freeRaw(scp);
}

int64_t MIN_REAL_GC_WAITING_MS = 5;
int64_t MAX_FULL_GC_WAITING_MS = 60000;
int64_t MAX_LOCAL_GC_WAITING_MS = 30000;
int64_t MAX_MEMORY_OPT_WAITING_MS = 1000;
int64_t MAX_PRINT_STAT_WAITING_MS = 1000;

class GlobalControllerThread : public Runnable {
	$mark(GlobalControllerThread, $CLASS | $NO_CLASS_INIT, Runnable);
public:
	void stop() {
		log_debug("GlobalControllerThread::stop() enter\n");
		runFlag = false;
		$synchronized(this) {
			this->notify();
		}
		log_debug("GlobalControllerThread::stop() notify\n");
		while (!stopedFlag) {
			Thread::yield();
		}
		log_debug("GlobalControllerThread::stop() leave\n");
	}
	void asyncLocalGc(LocalController* localController) {
		localController->asyncLocalGcEvent = true;
		if (this->localGcWaitingMs < MAX_LOCAL_GC_WAITING_MS) {
			Object0* obj0 = $of(this);
			if (obj0->trylock()) {
				this->localGcWaitingMs = MAX_LOCAL_GC_WAITING_MS;
				obj0->notify();
				obj0->unlock();
			}
		}
	}
	void asyncMemoryManagerOpt(MemoryManager::OPT_TYPE optType) {
		Object0* obj0 = $of(this);
		if (obj0->trylock(obj0)) {
			nextOptType = optType;
			obj0->notify();
			obj0->unlock();
		}
	}

	virtual void run() override;
	volatile bool runFlag = true;
	volatile bool stopedFlag = false;

	int64_t gcWaitingMs = 0;
	int64_t fullGcWaitingMs = 0;
	volatile int64_t localGcWaitingMs = 0;
	int64_t memoryOptWaitingMs = 0;
	MemoryManager::OPT_TYPE nextOptType = MemoryManager::OPT_NORMAL;
};

GlobalControllerThread* globalControllerThread = nullptr;

bool isObjectField2(const char* descriptor) {
	return descriptor[1] != '\0';
}



inline void ScanContextPendingManager::addOne(ObjectHead* oh) {
#ifdef OBJECT_DEBUG
	if (oh->isDebug() || !oh->isUsed()) {
		debugObjectHead("addOne", oh);
	}
#endif
	ScanContextPending* scp = head;
	if (scp == nullptr || scp->isFully()) {
		scp = ScanContextPending::create();
		scp->next = head;
		head = scp;
	}
	scp->addLast(oh);
}

inline ObjectHead* ScanContextPendingManager::removeOne() {
	ScanContextPending* scp = head;
	if (scp == nullptr) {
		return nullptr;
	}
	if (scp->isEmpty()) {
		head = head->next;
		ScanContextPending::free(scp);
		if (head == nullptr) {
			return nullptr;
		}
		scp = head;
	}
	return scp->removeLast();
}

template<typename T>
class ScanMarkLive : public ScanMarkBase<T> {
public:
	inline bool isReferent(ObjectHead* ohThis, int32_t fieldOffset) {
		if (ohThis->isRef() && fieldOffset == $offsetof(Reference, referent)) {
			return true;
		}
		return false;
	}

	inline bool isReferentLive(ObjectHead* ohThis) {
		int32_t refType = ohThis->getRefType();
		return this->scanRefLevel >= refType;
	}

	int8_t liveCode = 0;
	int32_t unused1 = 0;

	REF_TYPE scanRefLevel = OBJECT_REF_TYPE_FINAL;
	int32_t unused2 = 0;

	int32_t scanedCount = 0;
};

class ScanMarkLive4Local : public ScanMarkLive<ScanMarkLive4Local> {
public:
	template<typename T>
	inline void scan(T obj) {
		if (obj != nullptr) {
			Object0* obj0 = toObject0(obj);
			ObjectHead* oh = toOh(obj0);
			scan(oh);
		}
	}
	inline void scan(ObjectHead* oh) {
		if (!oh->isGlobal()) {
			if (!oh->isLive(liveCode)) {
#ifdef OBJECT_DEBUG
				if (oh->isDebug() || !oh->isUsed()) {
					debugObjectHead("ScanMarkLive4Local.scan", oh);
				}
#endif
				oh->setLive(liveCode);
				scanObject(this, oh);
			}
		}
	}
	inline void scanField(ObjectHead* ohThis, ObjectHead* ohField, int32_t fieldOffset) {
		if (!ohField->isGlobal()) {
			if (!ohField->isLive(liveCode)) {
#ifdef OBJECT_DEBUG
				if (ohField->isDebug() || !ohField->isUsed()) {
					debugObjectHead("ScanMarkLive4Local.scanField", ohField);
				}
#endif
				if (isReferent(ohThis, fieldOffset)) {
					if (isReferentLive(ohThis)) {
						ohField->setLive(liveCode);
						scanNext(this, ohThis, ohField);
					}
				} else {
					ohField->setLive(liveCode);
					scanNext(this, ohThis, ohField);
				}
			}
		}
	}
};

/*
class ScanMarkLiveAndRefCount4Local : public ScanMarkBase<ScanMarkLiveAndRefCount4Local> {
public:
	inline void scan(ObjectHead* oh) {
		if (!oh->isGlobal()) {
#ifdef OBJECT_DEBUG
			if (oh->isDebug() || oh->isDeleted()) {
				debugObjectHead("ScanMarkLiveAndRefCount4Local.scan", oh);
			}
#endif
			if (!oh->isLive(liveCode)) {
				oh->setLive(liveCode);
				oh->refCount.local = 1;
				scanObject(this, oh);
			} else {
				oh->refCount.local++;
			}
		}
	}
	inline void scanField(ObjectHead* ohThis, ObjectHead* oh, int32_t fieldOffset) {
		if (!oh->isGlobal()) {
			if (!oh->isLive(liveCode)) {
#ifdef OBJECT_DEBUG
				if (oh->isDebug() || oh->isDeleted()) {
					debugObjectHead("ScanMarkLiveAndRefCount4Local.scan", oh);
				}
#endif
				if (isReferent(ohThis, fieldOffset)) {
					if (isReferentLive(ohThis)) {
						oh->setLive(liveCode);
						oh->refCount.local = 1;
						scanNext(this, ohThis, oh);
					}
				} else {
					oh->setLive(liveCode);
					oh->refCount.local = 1;
					scanNext(this, ohThis, oh);
				}
			} else {
				oh->refCount.local++;
			}
		}
	}
};
*/
class ScanMarkReach4Local : public ScanMarkLive<ScanMarkReach4Local> {
public:
	template<typename T>
	inline void scan(T obj) {
		if (obj != nullptr) {
			Object0* obj0 = toObject0(obj);
			ObjectHead* oh = toOh(obj0);
			scan(oh);
		}
	}
	inline void scan(ObjectHead* oh) {
		if (!oh->isGlobal()) {
#ifdef OBJECT_DEBUG
			if (oh->isDebug() || !oh->isUsed()) {
				debugObjectHead("ScanMarkReach4Local.scan", oh);
			}
#endif
			if (!oh->isReach(liveCode)) {
				oh->setReach(liveCode);
				//scanObject(this, oh);
			}
			scanObject(this, oh);
		}
	}
	inline void scanField(ObjectHead* ohThis, ObjectHead* oh, int32_t fieldOffset) {
		if (!oh->isGlobal()) {
			if (!oh->isReach(liveCode) && ohThis != oh) {
#ifdef OBJECT_DEBUG
				if (oh->isDebug() || !oh->isUsed()) {
					debugObjectHead("ScanMarkReach4Local.scanField", oh);
				}
#endif
				oh->setReach(liveCode);
				scanNext(this, ohThis, oh);
			}
		}
	}
};

/*
class ScanMarkReachAndRefCount4Local : public ScanMarkBase<ScanMarkReachAndRefCount4Local> {
public:
	inline void scan(ObjectHead* oh) {
		if (!oh->isGlobal()) {
#ifdef OBJECT_DEBUG
			if (oh->isDebug() || oh->isDeleted()) {
				debugObjectHead("ScanMarkReachAndRefCount4Local.scan", oh);
			}
#endif
			if (!oh->isReach(liveCode)) {
				scanObject(this, oh);
			}
		}
	}
	inline void scanField(ObjectHead* ohThis, ObjectHead* oh, int32_t fieldOffset) {
		if (!oh->isGlobal()) {
			if (!oh->isReach(liveCode) && ohThis != oh) {
#ifdef OBJECT_DEBUG
				if (oh->isDebug() || oh->isDeleted()) {
					debugObjectHead("ScanMarkReachAndRefCount4Local.scanField", oh);
				}
#endif
				oh->setReach(liveCode);
				oh->refCount.local = 1;
				scanNext(this, ohThis, oh);
			} else {
				oh->refCount.local++;
			}
		}
	}
};
*/

class ScanMarkLive4All : public ScanMarkLive<ScanMarkLive4All> {
public:
	template<typename T>
	inline void scan(T obj) {
		if (obj != nullptr) {
			Object0* obj0 = toObject0(obj);
			ObjectHead* oh = toOh(obj0);
			scan(oh);
		}
	}
	inline void scan(ObjectHead* oh) {
#ifdef OBJECT_DEBUG
		//if (oh->isDeleted()) {
		//	debugObjectHead("ScanMarkLive4All.scan isDeleted", oh);
		//}
		if (oh->isDebug() || !oh->isUsed()) {
			debugObjectHead("ScanMarkLive4All.scan", oh);
		}
#endif
		if (!oh->isLive(liveCode)) {
			oh->setLive(liveCode);
#ifdef OBJECT_DEBUG
			oh->scanIndex = scanIndex++;
			if (oh->isDebug()) {
				debugObjectHead("ScanMarkLive4All.scan setLive", oh);
			}
#endif
			scanObject(this, oh);
		}
	}
	inline void scanField(ObjectHead* ohThis, ObjectHead* oh, int32_t fieldOffset) {
		if (ohThis == nullptr) {
			log_info("scanField ohThis == nullptr\n");
		}
		if (oh == nullptr) {
			log_info("scanField oh == nullptr\n");
		}
#ifdef OBJECT_DEBUG
		if (ohThis->isDebug() || oh->isDebug()) {
			debugObjectHead("ScanMarkLive4All.scanField ohThis", ohThis);
			debugObjectHead("ScanMarkLive4All.scanField oh", oh);
		}
		if (!ohThis->isUsed() || !oh->isUsed()) {
			debugObjectHead("ScanMarkLive4All.scanField isDeleted ohThis", ohThis);
			debugObjectHead("ScanMarkLive4All.scanField isDeleted oh", oh);
		}
		//if (liveCode == 65) {
		//	oh->isDebug();
		//}
#endif

		if (!oh->isLive(liveCode)) {
			if (isReferent(ohThis, fieldOffset)) {
				if (isReferentLive(ohThis)) {
					oh->setLive(liveCode);
#ifdef OBJECT_DEBUG
					oh->scanIndex = scanIndex++;
					if (ohThis->isDebug() || oh->isDebug()) {
						debugObjectHead("ScanMarkLive4All.scanField isReferentLive setLive oh", oh);
					}
#endif
					scanNext(this, ohThis, oh);
				}
			} else {
				oh->setLive(liveCode);
#ifdef OBJECT_DEBUG
				oh->scanIndex = scanIndex++;
				if (ohThis->isDebug() || oh->isDebug()) {
					debugObjectHead("ScanMarkLive4All.scanField setLive oh", oh);
				}
#endif
				scanNext(this, ohThis, oh);
			}
		}
	}
};

class ScanMarkReach4All : public ScanMarkLive<ScanMarkReach4All> {
public:
	template<typename T>
	inline void scan(T obj) {
		if (obj != nullptr) {
			Object0* obj0 = toObject0(obj);
			ObjectHead* oh = toOh(obj0);
			scan(oh);
		}
	}
	inline void scan(ObjectHead* oh) {
		if (!oh->isReach(liveCode)) {
#ifdef OBJECT_DEBUG
			if (oh->isDebug() || !oh->isUsed()) {
				debugObjectHead("ScanMarkReach4All.scan", oh);
			}
			int8_t oldReachCode = oh->reachCode;
			int64_t oldScanIndex = oh->scanIndex;
#endif
			oh->setReach(liveCode);
#ifdef OBJECT_DEBUG
			oh->scanIndex = scanIndex++;
#endif
			//scanObject(this, oh);
		}
		scanObject(this, oh);
	}
	inline void scanField(ObjectHead* ohThis, ObjectHead* oh, int32_t fieldOffset) {
		if (!oh->isReach(liveCode) && ohThis != oh) {
#ifdef OBJECT_DEBUG
			if (oh->isDebug() || !oh->isUsed()) {
				debugObjectHead("ScanMarkReach4All.scanField", oh);
			}
			int8_t oldReachCode = oh->reachCode;
			int64_t oldScanIndex = oh->scanIndex;
#endif
			oh->setReach(liveCode);
#ifdef OBJECT_DEBUG
			oh->scanIndex = scanIndex++;
#endif
			scanNext(this, ohThis, oh);
		}
	}
};

class ScanAddLocalRefCount4Clone : public ScanMarkBase<ScanAddLocalRefCount4Clone> {
public:
	template<typename T>
	inline void scan(T obj) {
		if (obj != nullptr) {
			Object0* obj0 = toObject0(obj);
			ObjectHead* oh = toOh(obj0);
			scan(oh);
		}
	}
	inline void scan(ObjectHead* oh) {
		scanObject(this, oh);
	}
	inline void scanField(ObjectHead* ohThis, ObjectHead* oh, int32_t fieldOffset) {
#ifdef ENABLE_OBJECT_REF_COUNT
		LocalController::addRefCount(oh);
#endif
		if (localController->savePendingLocal) {
			localController->savePending4Gc(fromOh(oh));
		}
	}
};

void LocalController::init(Thread* thread) {
	//statLocal.threadCount = 1;
	this->thread = thread;
	this->daemon = thread->isDaemon();
	this->exiting = false;
	// thread->localController = this;
	$var(String, tname, thread->getName());
	if (tname != nullptr) {
		tname->utf8String(threadName, sizeof(threadName));
	} else {
		threadName[0] = 0;
		if (thread->getId() == 1) {
			strncpy(threadName, "main", sizeof(threadName));
		}
	}
}

template<typename T>
void LocalController::clearLocalObjects(T& objects) {
	ObjectHead* oh = objects.removeFirst();
	while (oh != nullptr) {
		if (oh->isGlobal()) {
			int64_t size = getMemorySize(oh);
			globalController->addWaitToDispatch(oh, size);
		} else {
			freeLocalObject(GC_TYPE_NONE, oh);
		}
		oh = objects.removeFirst();
	}
}

void LocalController::deinit() {
	clearLocalObjects(newNormalListLocal0);
	clearLocalObjects(newNormalListLocal1);
	clearLocalObjects(newRefListLocal);
	clearLocalObjects(newHasFinalizeListLocal);
	//clearLocalObjects(newRefListLocal1);
	//clearLocalObjects(newHasFinalizeListLocal1);
	for (int i = 0; i < normalListCount; i++) {
		clearLocalObjects(normalListLocal[i]);
	}
	clearLocalObjects(refListLocal);
	clearLocalObjects(hasFinalizeListLocal);

	freeAllocs();

	if (javaThread != nullptr) {
		javaThread->destroy();
		javaThread = nullptr;
	}
}

bool isThreadClass(Class* clazz) {
	while (clazz != nullptr) {
		if (clazz == Thread::class$) {
			return true;
		}
		clazz = clazz->getSuperclass();
	}
	return false;
}

void LocalController::freeAllocs() {
	for (int i = 0; i < SLAB_COUNT; i++) {
		StoredMemoryAllocater* allocater = objectAllocaterLocalCurrent[i];
		if (allocater != nullptr) {
			objectAllocaterLocalCurrent[i] = nullptr;
			freeAllocater(allocater);
		}
		{
			StoredMemoryAllocater* listHead = objectAllocaterLocal[i].exchange(nullptr);
			MemoryAllocaterList listTemp(listHead);
			allocater = listTemp.removeFirst();
			while (allocater != nullptr) {
				freeAllocater(allocater);
				allocater = listTemp.removeFirst();
			}
		}
		{
			StoredMemoryAllocater* listHead = objectAllocaterLocalPending[i].exchange(nullptr);
			MemoryAllocaterList listTemp(listHead);
			allocater = listTemp.removeFirst();
			while (allocater != nullptr) {
				freeAllocater(allocater);
				allocater = listTemp.removeFirst();
			}
		}
	}
}

void LocalController::optAllocs(bool isFinalFullGc) {
	int32_t maxOptCount = isFinalFullGc ? 999999: 1;
	for (int i = 0; i < SLAB_COUNT; i++) {
		StoredMemoryAllocater* allocater = objectAllocaterLocalCurrent[i];
		if (allocater != nullptr) {
			allocater->moveFreeingToFree();
		}
		int32_t optCount = 0;
		AtomicMemoryAllocaterList& allocaterList = objectAllocaterLocal[i];
		AtomicMemoryAllocaterList& allocaterPendingList = objectAllocaterLocalPending[i];
		{
			StoredMemoryAllocater* listHead = allocaterList.exchange(nullptr);
			MemoryAllocaterList listTemp(listHead);
			allocater = listTemp.removeFirst();
			while (allocater != nullptr) {
				if (isFinalFullGc) {
					allocater->moveFreeingToStore();
					allocater->moveFreeToStore();
				} else {
					allocater->moveFreeingToFree();
				}
				if (allocater->getAllocedCount() == 0 && optCount < maxOptCount) {
					freeAllocater(allocater);
					optCount++;
				} else {
					allocaterList.prepend(allocater);
				}
				allocater = listTemp.removeFirst();
			}
		}
		{
			StoredMemoryAllocater* listHead = allocaterPendingList.exchange(nullptr);
			MemoryAllocaterList listTemp(listHead);
			allocater = listTemp.removeFirst();
			while (allocater != nullptr) {
				if (allocater->freeingListCount > 0) {
					if (isFinalFullGc) {
						allocater->moveFreeingToStore();
						allocater->moveFreeToStore();
					} else {
						allocater->moveFreeingToFree();
					}
					if (allocater->getAllocedCount() == 0 && optCount < maxOptCount) {
						freeAllocater(allocater);
						optCount++;
					} else {
						allocaterList.prepend(allocater);
					}
				} else {
					allocaterPendingList.prepend(allocater);
				}
				allocater = listTemp.removeFirst();
			}
		}
	}
}

inline void LocalController::scanMarkGlobal(ObjectHead* oh) {
	scanMarkGlobalScanner.scan(oh);
	scanMarkGlobalScanner.processPendingScan();
}

template<typename T>
inline void LocalController::scanMarkGlobal0(T* obj) {
	if (obj != nullptr) {
		Object0* obj0 = toObject0(obj);
		ObjectHead* oh = toOh(obj0);
		if (!oh->isGlobal()) {
			scanMarkGlobal(oh);
		}
	}
}

#ifdef ENABLE_OBJECT_REF_COUNT

void assignLocalObjectFieldNullForFree(Object0* owner, int64_t fieldOffset) {
	Object*& field = *(Object**)(((int8_t*)owner) + fieldOffset);
	Object* oldField = field;

	field = nullptr;
	// while (!cas(&field, oldField, (Object*)nullptr)) {
	// 	oldField = field;
	// }
	if (oldField != nullptr) {
		LocalController::releaseRefCount(oldField);
	}
}

inline void trySubLocalRefCount(Object0*& obj) {
	if (obj != nullptr) {
		Object0* toRelease = obj;
		obj = nullptr;
		LocalController::releaseRefCount(toRelease);
	}
}

void assignLocalArrayFieldNullForFree(ObjectArray* oa) {
//	int32_t len = oa->length;
	int32_t len = oa->_;
	Object0** begin = oa->begin();
	int32_t remained = len % 4;
	len -= remained;
	for (int32_t i = 0; i < len; i += 4) {
		trySubLocalRefCount(begin[i]);
		trySubLocalRefCount(begin[i + 1]);
		trySubLocalRefCount(begin[i + 2]);
		trySubLocalRefCount(begin[i + 3]);
	}
	for (int32_t i = 0; i < remained; i++) {
		trySubLocalRefCount(begin[len + i]);
	}
}

inline void LocalController::clearLocalRefForFree(ObjectHead* oh) {
	Class* clazz = oh->clazz;
	if (!clazz->isArray()) {
		Object0* obj0 = fromOh(oh);
		for (int32_t i = 0; i < clazz->objectFieldOffsetArrayLength; i++) {
			int32_t offset = clazz->objectFieldOffsetArray[i];
			assignLocalObjectFieldNullForFree(obj0, offset);
		}
	} else {
		if (!clazz->componentType$->primitive) {
			Object0* obj0 = fromOh(oh);
			ObjectArray* oa = (ObjectArray*)obj0;
		//	if (oa->length < 16) {
			assignLocalArrayFieldNullForFree(oa);
		//	}
		}
	}
}
#endif

inline void LocalController::freeLocalObject(GcType gcType, ObjectHead* oh) {
#ifdef OBJECT_DEBUG
	if (oh->isDebug() || !oh->isUsed()) {
		debugObjectHead("freeLocalObject", oh);
	}
	//if (oh->getGlobalRefCount() != 0) {
	//	debugObjectHead("freeLocalObject refCount != 0", oh);
	//}
	//if (strcmp(getClassName(oh), "java.util.Hashtable$Entry") == 0) {
		//oh->mask = 1;
		//debugObjectHead("freeLocalObject mask = 1", oh);
		//oh->setDeleted();
		//return;
	//}
	oh->freeLiveCodeGlobal = globalController->liveCodeGlobal;
	oh->freeLiveCodeLocal = this->liveCodeLocal;
	oh->clearUsed();
	//return;
#endif
	freeObjectMonitor(oh);
	if (oh->isInline()) {
		oh->clearUsed();
	} else {
		//statLocal.free(getMemorySize(oh));
		memoryManager.freeObjectLocal(oh);
	}
}

inline ObjectHead* LocalController::allocLocalObject0(int64_t size) {
	int32_t slabIndex = memoryManager.getSlabIndex(size);
	if (slabIndex < 0) {
		int64_t payloadSize = sizeof(ObjectHead) + size;
		ObjectHead* oh = memoryManager.allocObjectOrNull(payloadSize);
		return oh;
	}
	ObjectHead* oh = nullptr;
	StoredMemoryAllocater* oa = objectAllocaterLocalCurrent[slabIndex];
	if (oa == nullptr) {
		oa = createAllocater(slabIndex);
		if (oa == nullptr) {
			return nullptr;
		}
		objectAllocaterLocalCurrent[slabIndex] = oa;
	}
	oh = oa->allocObject();
	if (oh != nullptr) {
		return oh;
	} else {
		objectAllocaterLocalCurrent[slabIndex] = nullptr;
		//MemoryAllocaterList allocaterListTemp;
		//allocaterListTemp.prepend(oa);
		AtomicMemoryAllocaterList* allocaterList = &objectAllocaterLocal[slabIndex];
		AtomicMemoryAllocaterList* allocaterListPending = &objectAllocaterLocalPending[slabIndex];
		allocaterListPending->prepend(oa);
		oa = allocaterList->removeFirst();
		while (oa != nullptr) {
			oh = oa->allocObject();
			if (oh != nullptr) {
				objectAllocaterLocalCurrent[slabIndex] = oa;
				break;
			}
			allocaterListPending->prepend(oa);
			oa = allocaterList->removeFirst();
		}
		//if (oh == nullptr) {
		//	oa = allocaterListPending->removeFirst();
		//	while (oa != nullptr) {
		//		oh = oa->allocObject();
		//		if (oh != nullptr) {
		//			objectAllocaterLocalCurrent[slabIndex] = oa;
		//			break;
		//		}
		//		allocaterListTemp.prepend(oa);
		//		oa = allocaterListPending->removeFirst();
		//	}
		//}
		if (oh == nullptr) {
			for (int i = 0; i < 5; i++) {
				oa = createAllocater(slabIndex);
				if (oa != nullptr) {
					oh = oa->allocObject();
					if (oh != nullptr) {
						objectAllocaterLocalCurrent[slabIndex] = oa;
						break;
					} else {
						freeAllocater(oa);
					}
				}
			}
		}
		//if (!allocaterListTemp.isEmpty()) {
		//	allocaterListPending->prependList(allocaterListTemp.first(), allocaterListTemp.last());
		//}
		/*
		oa = allocaterListTemp.removeFirst();
	//	int32_t freedCount = 0;
		while (oa != nullptr) {
	//		if (oa->getAllocedCount() == 0 && freedCount < 50) {
	//			memoryManager.freeAllocater(oa);
	//			statLocal.freeAllocater();
	//			freedCount++;
	//		} else {
				allocaterListPending->prepend(oa);
	//		}
			oa = allocaterListTemp.removeFirst();
		}
		*/
	}
	return oh;
}

#if 0
inline ObjectHead* LocalController::allocLocalObject(Class* clazz, int64_t size) {
	if (pendingObjectCS.size >= memoryManager.getMinLocalGcMemorySize()) {
		clearVarStackRemain();
		pendingObjectCS.clear();
		globalControllerThread->asyncLocalGc(this);
	}
	/*
	if (pendingObjectCS.size >= 16 * 1024 * 1024 && pendingObjectCS.count >= 20000) {
#ifdef ENABLE_OBJECT_REF_COUNT
		if (refCountGcCount < 50) {
			localGcWithRefCount(OBJECT_REF_TYPE_WEAK);
			refCountGcCount++;
		}
		refCountGcCount = 0;
#endif
		if (objectCSLocal.count.value() < 50000) {
			localGc(OBJECT_REF_TYPE_WEAK);
			pendingObjectCS.clear();
		} else {
			clearVarStackRemain();
			int64_t localSize = objectCSLocal.size.value();
			if (localSize > memoryManager.getMinMemorySize() / 5 && pendingObjectCS.size * 5 > localSize) {
				pendingObjectCS.clear();
				globalControllerThread->asyncLocalGc(this);
			}
		}
	}
	*/
	ObjectHead* oh = allocLocalObject0(size);
	if (oh == nullptr) {
		localGc(OBJECT_REF_TYPE_SOFT);
		oh = allocLocalObject0(size);
		if (oh == nullptr) {
			localGc(OBJECT_REF_TYPE_FINAL);
			oh = allocLocalObject0(size);
			if (oh == nullptr) {
				if (clazz == Finalizer::class$) {
					oh = globalController->allocInternalFinalizer();
					if (oh == nullptr) {
						log_error("out of memory error, allocInternalFinalizer\n");
						exit(1);
					}
				} else {
					fullGc(OBJECT_REF_TYPE_FINAL);
					oh = allocLocalObject0(size);
					if (oh == nullptr) {
						for (int i = 0; i < 3; i++) {
							fullGc(OBJECT_REF_TYPE_FINAL);
							oh = allocLocalObject0(size);
							if (oh != nullptr) {
								break;
							}
						}
					}
					if (oh == nullptr) {
						if (clazz == OutOfMemoryError::class$ || clazz == InterruptedException::class$) {
							oh = globalController->allocInternalThrowable();
						}
					}
				}
			}
		}
	}

	return oh;
}
#endif // 0

inline Object0* LocalController::allocInternal(Class* clazz, int64_t size, bool throwIfOOM) {
#ifdef OBJECT_DEBUG
	$nullcheck(clazz);
#endif
	//if (clazz->state != Class::CLASS_STATE_INITIALIZED) {
	//	clazz->ensureClassInitialized();
	//}
	//size = clazz->size;
	if (pendingObjectCS.size >= memoryManager.getMinLocalGcMemorySize()) {
		if (globalControllerThread != nullptr) {
			clearVarStackRemain();
			pendingObjectCS.clear();
			globalControllerThread->asyncLocalGc(this);
		}
	}
	//localGc(OBJECT_REF_TYPE_WEAK);
	//fullGc(OBJECT_REF_TYPE_WEAK);

	ObjectHead* oh = allocLocalObject0(size);
	if (oh == nullptr) {
		localGc(OBJECT_REF_TYPE_SOFT);
		oh = allocLocalObject0(size);
		if (oh == nullptr) {
			localGc(OBJECT_REF_TYPE_FINAL);
			oh = allocLocalObject0(size);
			if (oh == nullptr) {
				if (clazz == Finalizer::class$) {
					oh = globalController->allocInternalFinalizer();
					if (oh == nullptr) {
						log_error("out of memory error, allocInternalFinalizer\n");
						exit(1);
					}
				} else {
					fullGc(OBJECT_REF_TYPE_FINAL);
					oh = allocLocalObject0(size);
					if (oh == nullptr) {
						for (int i = 0; i < 3; i++) {
							fullGc(OBJECT_REF_TYPE_FINAL);
							oh = allocLocalObject0(size);
							if (oh != nullptr) {
								break;
							}
						}
					}
					if (oh == nullptr) {
						if (clazz == OutOfMemoryError::class$ || clazz == InterruptedException::class$) {
							oh = globalController->allocInternalThrowable();
						}
					}
				}
			}
		}
		if (oh == nullptr) {
			if (throwIfOOM) {
				if (clazz == OutOfMemoryError::class$ || clazz == InterruptedException::class$) {
					log_error("out of memory error, allocInternal %" PRId64 "\n", size);
					exit(1);
				} else {
					log_warning("allocInternal OutOfMemoryError size:%" PRId64 "\n", size);
					$throwNew(OutOfMemoryError, clazz->name);
				}
			} else {
				return nullptr;
			}
		}
	}

	oh->clazz = clazz;
	OBJECT_HEAD_FLAG ohFlags = OBJECT_FLAG_USED;
	//oh->setUsed();
	int32_t mark = clazz->mark;
	bool hasFinalize = false;
	if ($hasFlag(mark, $HAS_FINALIZE)) {
		ohFlags |= OBJECT_FLAG_HAS_FINALIZE;
		hasFinalize = true;
	}

	oh->flags = ohFlags;
	if ((mark & ($FINAL_REFERENCE | $SOFT_REFERENCE | $WEAK_REFERENCE | $PHANTOM_REFERENCE)) != 0) {
		if ($hasFlag(mark, $FINAL_REFERENCE)) {
			oh->setRefType(OBJECT_REF_TYPE_FINAL);
		} else if ($hasFlag(mark, $SOFT_REFERENCE)) {
			oh->setRefType(OBJECT_REF_TYPE_SOFT);
		} else if ($hasFlag(mark, $WEAK_REFERENCE)) {
			oh->setRefType(OBJECT_REF_TYPE_WEAK);
		} else if ($hasFlag(mark, $PHANTOM_REFERENCE)) {
			oh->setRefType(OBJECT_REF_TYPE_PHANTOM);
		}
		newRefListLocal.prepend(oh);
	} else {
		if (hasFinalize) {
			newHasFinalizeListLocal.prepend(oh);
		} else {
			newNormalListLocal0.prepend(oh);

			//if (this->newNormalListLocalCount < MAX_NEW_NORMAL_LIST_LOCAL) {
			//	newNormalListLocal[newNormalListLocalCount] = oh;
			//	newNormalListLocalCount++;
			//} else {
			//	ObjectHead* head = oh;
			//	ObjectHead* tail = oh;
			//	for (int i = 0; i < newNormalListLocalCount; i++) {
			//		tail->next = newNormalListLocal[i];
			//		tail = tail->next;
			//	}
			//	newNormalListLocalCount = 0;
			//	tail->next = nullptr;
			//	newNormalListLocal0.prependAll(head, tail);
			//}
		}
	}

#ifdef OBJECT_DEBUG
	//oh->newTime = System::currentTimeMillis();
	oh->id = newIndex++;
	oh->obj = fromOh(oh);
	oh->debug = "allocInternal";
	if (oh->isDebug() || !oh->isUsed()) {
		debugObjectHead("allocInternal", oh);
	}
	//log_info("alloc %p %" PRId64 "\n", oh, newIndex);
	//if (isClass(oh, "java.util.Hashtable")) {
	//	if (oh->id >= 62300 && oh->id <= 62320) {
	//		oh->mask |= 1;
	//		oh->ttl = 1;
	//	}
	//}
	oh->newLiveCodeGlobal = globalController->liveCodeGlobal;
	oh->newLiveCodeLocal = this->liveCodeLocal;
#endif

	

	int64_t ohSize = getMemorySize(oh);
	objectCSLocal.add(ohSize);
	pendingObjectCS.add(ohSize);
	statLocal.alloc(ohSize);
	//statLocal.addObject(ohSize);

	//pendingObjectCount++;
	//pendingObjectSize += ohSize;

	//if (gcType == GC_TYPE_ASYNC_LOCAL) {
	//	oh->setLive(this->liveCodeLocal);
	//} else if (gcType == GC_TYPE_FULL) {
	//	oh->setLive(globalController->liveCodeGlobal);
	//}

	//oh = nullptr;
	Object0* obj = fromOh(oh);
	return obj;
}

void GlobalControllerThread::run() {
	int64_t lastTime = System::currentTimeMillis();

	while (runFlag) {
	//	std::this_thread::sleep_for(20000ms);
		$synchronized(this) {
			this->wait(25);
			if (!runFlag) {
				break;
			}
		}
		int64_t curr = System::currentTimeMillis();
		int64_t diff = curr - lastTime;

		if (diff > 0) {
			gcWaitingMs += diff;
			fullGcWaitingMs += diff;
			localGcWaitingMs += diff;
			memoryOptWaitingMs += diff;
			globalController->printStatTime += diff;
		}

		globalController->opt();
		if (globalController->printStatTime >= MAX_PRINT_STAT_WAITING_MS) {
			globalController->printStat();
		}

		if (nextOptType != MemoryManager::OPT_NORMAL || memoryOptWaitingMs >= MAX_MEMORY_OPT_WAITING_MS) {
			globalController->gcHandlePendingAllocater->opt(1);
			globalController->scanContextPendingAllocater->opt(1);
			MemoryManager::OPT_TYPE optType = nextOptType;
			nextOptType = MemoryManager::OPT_NORMAL;
			memoryManager.opt(optType);
			memoryOptWaitingMs = 0;
		}

		if (gcWaitingMs >= MIN_REAL_GC_WAITING_MS) {
			if (fullGcWaitingMs >= MAX_FULL_GC_WAITING_MS || globalController->pendingObjectCSGlobal.size > memoryManager.getMinMemorySize() / 5) {
				//	globalController->printStat();
				GcResult gcResult(GC_TYPE_FULL);
				globalController->fullGc0(OBJECT_REF_TYPE_SOFT, &gcResult);
				gcWaitingMs = 0;
				fullGcWaitingMs = 0;
				localGcWaitingMs = 0;
			} else if (localGcWaitingMs >= MAX_LOCAL_GC_WAITING_MS) {
				GcResult gcResult(GC_TYPE_ASYNC_LOCAL);
				globalController->asyncLocalGc(OBJECT_REF_TYPE_WEAK, false, &gcResult);
				gcWaitingMs = 0;
				localGcWaitingMs = 0;
			}
		}
		lastTime = System::currentTimeMillis();
	}
	stopedFlag = true;
	log_info("Object Manager Thread exit\n");
}

void GlobalController::asyncLocalGc(REF_TYPE scanRefLevel, bool force, GcResult* gcResult) {
	int64_t localGcStartNS = System::nanoTime();
	{
		std::lock_guard lock(this->mutexGlobal);
		gcResult->liveCode = 0;
		globalGcType = GC_TYPE_ASYNC_LOCAL;

		//log_debug("async local gc start %s\n", getRefTypeName(scanRefLevel));
		log_debug("async local gc start %s count:%" PRId64 ", size:%" PRId64 "\n", getRefTypeName(scanRefLevel), memoryManager.getTotalCount(), memoryManager.getTotalSize());
		{
			LocalControllerAtomicListIterator it = LocalControllerAtomicListIterator(&localControllerList);
			while (it.has()) {
				LocalController* controller = it.get();
				if (force || controller->asyncLocalGcEvent || controller->skipAsyncLocalGcCount <= 0) {
					controller->asyncLocalGcEvent = false;
					controller->skipAsyncLocalGcCount = 3;
					controller->asyncLocalGc(scanRefLevel, gcResult);
				} else {
					controller->skipAsyncLocalGcCount--;
				}
				it.next();
			}
		}
		globalGcType = GC_TYPE_NONE;
	}
	int64_t costlocalNS = System::nanoTime() - localGcStartNS;
	gcResult->costNS = costlocalNS;
	gcResult->print("async local gc");
	log_debug("async local gc finsh %s count:%" PRId64 ", size:%" PRId64 "\n", getRefTypeName(scanRefLevel), memoryManager.getTotalCount(), memoryManager.getTotalSize());
}

void globalFullGc() {
	GcResult gcResult(GC_TYPE_FULL);
	globalController->fullGc0(OBJECT_REF_TYPE_FINAL, &gcResult);
}

void GlobalController::fullGc0(REF_TYPE scanRefLevel, GcResult* gcResult) {
	int64_t fullGcStartNS = System::nanoTime();
	bool isFinalFullGc = scanRefLevel == OBJECT_REF_TYPE_FINAL;
	if (localController != nullptr) {
		localController->clearVarStackRemain();
		localController->fullGcing = true;
	}
	{
		std::lock_guard lock(this->mutexGlobal);

		if (localController != nullptr && !localController->fullGcing) {
			return;
		}
		liveCodeGlobal = genNextGlobalLiveCode(liveCodeSequenceGlobal);
		gcResult->liveCode = liveCodeGlobal;
		log_debug("full gc start %s liveCode:%d, count:%" PRId64 ", size:%" PRId64 "\n", getRefTypeName(scanRefLevel), liveCodeGlobal, memoryManager.getTotalCount(), memoryManager.getTotalSize());
		{
			LocalControllerAtomicListIterator it = LocalControllerAtomicListIterator(&localControllerList);
			while (it.has()) {
				LocalController* controller = it.get();
				std::lock_guard<std::mutex> lock(controller->mutexLocal);
				controller->stopNSLocal = 0;
				controller->moveGlobalObjects(GC_TYPE_FULL, gcResult);
				controller->relist4New(GC_TYPE_FULL, gcResult);
				controller->gcStatusLocal = GC_STATUS_START;
				controller->liveCodeLocal = liveCodeGlobal;
				controller->clearPendingManager4Gc();
				controller->savePendingLocal = true;
				it.next();
			}
		}
		dispatchWaitingObjectsAndClearLiveReach();
		globalGcType = GC_TYPE_FULL;
		int64_t prepareDoneNS = System::nanoTime();
		gcResult->prepareNS = prepareDoneNS - fullGcStartNS;

		log_debug("full gc mark local live reach liveCode:%d\n", liveCodeGlobal);
		int64_t markStartNs = prepareDoneNS;
		LocalControllerAtomicListIterator it = LocalControllerAtomicListIterator(&localControllerList);
		while (it.has()) {
			LocalController* controller = it.get();
			it.next();
			if (controller->gcStatusLocal == GC_STATUS_START) {
				std::lock_guard<std::mutex> lock(controller->mutexLocal);
				gcResult->threadCount++;
				//controller->gcStatusLocal = GC_STATUS_START;
				//controller->liveCodeLocal = liveCodeGlobal;
				controller->markLiveAll(liveCodeGlobal, scanRefLevel, gcResult);
				//controller->moveGlobalObjects(GC_TYPE_FULL, gcResult);
				//log_info("markReachAll %s\n", controller->threadName);
				controller->markReachAll(liveCodeGlobal, scanRefLevel, gcResult);
				controller->gcStatusLocal = GC_STATUS_DONE;
			}
		}

		int64_t localMarkDoneNS = System::nanoTime();
		gcResult->localMarkNS = localMarkDoneNS - markStartNs;

		//log_debug("full gc dispatchWaitingObjects liveCode:%d\n", liveCodeGlobal);
		this->dispatchWaitingObjects();

		//log_debug("full gc markLiveGlobal liveCode:%d\n", liveCodeGlobal);
		markLiveGlobal(scanRefLevel, gcResult);

		//log_debug("full gc markReachGlobal liveCode:%d\n", liveCodeGlobal);
		markReachGlobal(scanRefLevel, gcResult);

		// mark pending
		//log_debug("full gc markLiveAllPending liveCode:%d\n", liveCodeGlobal);
		markLiveAllPending(liveCodeGlobal, scanRefLevel, gcResult);

		int64_t stopStartNS = System::nanoTime();
		// stop /stw
		//log_debug("full gc globalStop4gc = true liveCode:%d\n", liveCodeGlobal);
		//globalStop4gc = true;
		{
			LocalControllerAtomicListIterator it = LocalControllerAtomicListIterator(&localControllerList);
			while (it.has()) {
				LocalController* controller = it.get();
				it.next();
				if (controller->gcStatusLocal == GC_STATUS_DONE) {
					controller->localStop4gc = true;
				}
			}
		}
		// mark pending
		//log_debug("full gc markLiveAllPending liveCode:%d\n", liveCodeGlobal);
		markLiveAllPending(liveCodeGlobal, scanRefLevel, gcResult);

		int64_t markDoneNs = System::nanoTime();
		gcResult->markNS = markDoneNs - markStartNs;
		//markReachGlobal(scanRefLevel, &gcResult);

		// unstop / unstw
		//log_debug("full gc globalStop4gc = false liveCode:%d\n", liveCodeGlobal);
		//globalStop4gc = false;
		{
			LocalControllerAtomicListIterator it = LocalControllerAtomicListIterator(&localControllerList);
			while (it.has()) {
				LocalController* controller = it.get();
				it.next();
				if (controller->gcStatusLocal == GC_STATUS_DONE) {
					controller->localStop4gc = false;
				}
			}
		}
		int64_t stopEndNS = System::nanoTime();
		gcResult->stopNS = stopEndNS - stopStartNS;
		//int64_t cost5 = System::nanoTime() - fullGcStartNS;

		globalGcType = GC_TYPE_NONE;

		{
			LocalControllerAtomicListIterator it = LocalControllerAtomicListIterator(&localControllerList);
			while (it.has()) {
				LocalController* controller = it.get();
				it.next();
				if (controller->gcStatusLocal == GC_STATUS_DONE) {
					std::lock_guard<std::mutex> lock(controller->mutexLocal);
					gcResult->realStopNS += controller->stopNSLocal;
					controller->savePendingLocal = false;
					controller->processLocalObject(liveCodeGlobal, GC_TYPE_FULL, gcResult);
					controller->optAllocs(isFinalFullGc);
					controller->clearPendingManager4Gc();
					controller->gcStatusLocal = GC_STATUS_NONE;
					controller->liveCodeLocal = 0;
					controller->cvLocal.notify_all();
				}
			}
		}

		//log_debug("full gc processGlobalObject liveCode:%d\n", liveCodeGlobal);
		processGlobalObject(gcResult);

		// for test
#ifdef OBJECT_DEBUG
		/*
		//dispatchWaitingObjects(true);
		liveCodeGlobal = genNextGlobalLiveCode(liveCodeSequenceGlobal);
		//markLiveAllPending(liveCodeGlobal, scanRefLevel, gcResult);
		{
			LocalControllerAtomicListIterator it = LocalControllerAtomicListIterator(&localControllerList);
			while (it.has()) {
				LocalController* controller = it.get();
				it.next();
				if (controller->gcStatus == GC_STATUS_DONE) {
					std::lock_guard<std::mutex> lock(controller->mutexLocal);
					controller->markLiveAll(liveCodeGlobal, scanRefLevel, gcResult);
				}
			}
		}
		//dispatchWaitingObjects(false);
		markLiveGlobal(scanRefLevel, gcResult);
		*/
#endif
		if (localController != nullptr) {
			processHasFinalizePendingQueueGlobal();
		}

		int64_t processDoneNS = System::nanoTime();
		gcResult->processNS = processDoneNS - markDoneNs;
		int64_t costNs = processDoneNS - fullGcStartNS;
		gcResult->costNS = costNs;

		if (isFinalFullGc) {
			memoryManager.opt(MemoryManager::OPT_FINAL_GC);
		}
		this->pendingObjectCSGlobal.clear();
		//statCurrentGobal.fullGc(cost0, cost1, cost2, cost3, cost4, cost5, cost6, cost7);

		{
			LocalControllerAtomicListIterator it = LocalControllerAtomicListIterator(&localControllerList);
			while (it.has()) {
				LocalController* controller = it.get();
				it.next();
				if (controller->fullGcing) {
					controller->fullGcing = false;
				}
			}
		}
		cvGlobal.notify_all();
	}
	gcResult->print("full gc");
	log_debug("full gc finsh %s liveCode:%d, count:%" PRId64 ", size:%" PRId64 "\n", getRefTypeName(scanRefLevel), liveCodeGlobal, memoryManager.getTotalCount(), memoryManager.getTotalSize());
	printStat();

	if (!isFinalFullGc) {
		globalControllerThread->asyncMemoryManagerOpt(MemoryManager::OPT_GC);
	}
//	printStat();
}

void ObjectManagerInternal::init0() {
//#ifdef _DEBUG
//	Logger::setLevel(Logger::LOG_DEBUG);
//#else
//	Logger::setLevel(Logger::LOG_INFO);
//#endif
	memoryManager.init();
	localController = LocalController::create();
}

void ObjectManagerInternal::init() {
	globalController = new (memoryManager.allocRawStaticOrExit(sizeof(GlobalController))) GlobalController();
	globalController->init();
}

void ObjectManagerInternal::init2() {
	$init(Finalizer);
	$init(Shutdown);
	$assignStatic(globalControllerThread, $new(GlobalControllerThread));
	$var(Thread, t, $new(Thread, globalControllerThread));
	t->setDaemon(true);
	t->setName("Object Manager"_s);
	t->start();
}

void ObjectManagerInternal::init3() {
	objectManagerInited = true;
	memoryManager.printArgs();
}

void ObjectManagerInternal::deinit() {
	log_debug("ObjectManagerInternal::deinit() enter\n");
	if (objectManagerInited) {
		globalController->deinit(false);
		objectManagerInited = false;
	}
	log_debug("ObjectManagerInternal::deinit() leave\n");
}

void ObjectManagerInternal::beforeExit() {
	log_debug("ObjectManagerInternal::beforeExit() enter\n");
	if (objectManagerInited) {
		globalController->deinit(true);
		objectManagerInited = false;
	}
	log_debug("ObjectManagerInternal::beforeExit() leave\n");
}

inline void updateArrayEnd(ObjectArray* array, int32_t end, bool isGlobal) {
	if (end > array->_) {
		if (isGlobal) {
			std::atomic<int32_t>* arrayEnd = (std::atomic<int32_t>*)&const_cast<int32_t&>(array->_);
			int32_t oldArrayEnd = arrayEnd->load(std::memory_order_relaxed);
			do {
				if (end <= oldArrayEnd) {
					break;
				}
			} while (!arrayEnd->compare_exchange_weak(oldArrayEnd, end, std::memory_order_release, std::memory_order_relaxed));
		} else {
			const_cast<int32_t&>(array->_) = end;
		}
	}
}

inline void recordObjectOffset0(Class* clazz, int32_t fieldOffset) {
#ifdef _DEBUG
	if (fieldOffset >= clazz->size) {
		// TODO
		$throwNew(Exception);
	}
#endif
	if (clazz->needRecordObjectFieldOffset(fieldOffset)) {
		clazz->recordObjectFieldOffset(fieldOffset);
	}
}

#define $fieldOffset(owner, field) (int32_t)((int64_t)field - (int64_t)owner)

bool ObjectManager::compareAndSetReference(Object0* owner, Object** target, Object$* expected, Object$* value) {
	$nc(owner);
	$nc(target);
	ObjectHead* ohOwer = toOh(owner);
	LocalController* lc = localController;
	if (value != nullptr) {
		Object0* value0 = toObject0(value);
		if (ohOwer->isGlobal()) {
			lc->scanMarkGlobal0(value0);
		}
		if (lc->savePendingLocal) {
			lc->savePending4Gc(value0);
		}
#ifdef ENABLE_OBJECT_REF_COUNT
		LocalController::addRefCount(value);
#endif
	}
	Object* old = (Object*)expected;
	if (old != nullptr && lc->savePendingLocal) {
		lc->savePending4Gc(old);
	}
	 
	bool ret = cas(target, old, (Object*)value);
	if (ret) {
		if (old != nullptr) {
#ifdef ENABLE_OBJECT_REF_COUNT
			LocalController::releaseRefCount(old);
#endif
		} else if (value != nullptr) {
			Class* ownerClazz = ohOwer->clazz;
			if (!ownerClazz->isArray()) {
				// Unsafe::putReference will call in here
				int32_t offset = $fieldOffset(owner, target);
				recordObjectOffset0(ownerClazz, offset);
			} else {
				ObjectArray* array = (ObjectArray*)owner;
				int32_t end = $fieldOffset(array->begin(), target) / sizeof(Object*) + 1;			
				updateArrayEnd(array, end, ohOwer->isGlobal());
			}
		}
	} else {
#ifdef ENABLE_OBJECT_REF_COUNT
		if (value != nullptr) {
			LocalController::releaseRefCount(value);
		}
#endif
	}
	return ret;
}

bool ObjectManager::compareAndSetReference(Object** target, Object$* expected, Object$* value) {
	$nc(target);
	if (*target == nullptr) {
		globalController->recordStaticPointer(target);
	}
	LocalController* lc = localController;
	if (value != nullptr) {
#ifdef ENABLE_OBJECT_REF_COUNT
		LocalController::addRefCount(value);
#endif
		Object0* value0 = toObject0(value);
		lc->scanMarkGlobal0(value0);
		if (lc->savePendingLocal) {
			lc->savePending4Gc(value0);
		}
	}
	Object* old = (Object*)expected;
	if (old != nullptr && lc->savePendingLocal) {
		lc->savePending4Gc(old);
	}
	bool ret = cas(target, old, (Object*)value);
#ifdef ENABLE_OBJECT_REF_COUNT
	if (ret) {
		if (old != nullptr) {
			LocalController::releaseRefCount(old);
		}
	} else {
		if (value != nullptr) {
			LocalController::releaseRefCount(value);
		}
	}
#endif
	return ret;
}

Object* ObjectManager::compareAndExchangeReference(Object0* owner, Object** target, Object$* expected, Object$* value) {
	$nc(owner);
	$nc(target);
	ObjectHead* ohOwer = toOh(owner);
	LocalController* lc = localController;
	if (value != nullptr) {
#ifdef ENABLE_OBJECT_REF_COUNT
		LocalController::addRefCount(value);
#endif
		Object0* value0 = toObject0(value);
		if (ohOwer->isGlobal()) {
			lc->scanMarkGlobal0(value0);
		}
		if (lc->savePendingLocal) {
			lc->savePending4Gc(value0);
		}
	}
	Object* old = (Object*)expected;
	if (old != nullptr && lc->savePendingLocal) {
		lc->savePending4Gc(old);
	}
	bool ret = cas(target, old, (Object*)value);
	if (ret) {
		if (old != nullptr) {
#ifdef ENABLE_OBJECT_REF_COUNT
			LocalController::releaseRefCount(old);
#endif
		} else if (value != nullptr) {
			Class* ownerClazz = ohOwer->clazz;
			if (!ownerClazz->isArray()) {
				// Unsafe::putReference will call in here
				int32_t offset = $fieldOffset(owner, target);
				recordObjectOffset0(ownerClazz, offset);
			} else {
				ObjectArray* array = (ObjectArray*)owner;
				int32_t end = $fieldOffset(array->begin(), target) / sizeof(Object*) + 1;			
				updateArrayEnd(array, end, ohOwer->isGlobal());
			}
		}
		return (Object*)value;
	} else {
#ifdef ENABLE_OBJECT_REF_COUNT
		if (value != nullptr) {
			LocalController::releaseRefCount(value);
		}
#endif
	}
	return (Object*)old;
}

Object* ObjectManager::compareAndExchangeReference(Object** target, Object$* expected, Object$* value) {
	$nc(target);
	if (*target == nullptr) {
		globalController->recordStaticPointer(target);
	}
	LocalController* lc = localController;
	if (value != nullptr) {
#ifdef ENABLE_OBJECT_REF_COUNT
		LocalController::addRefCount(value);
#endif
		Object0* value0 = toObject0(value);
		lc->scanMarkGlobal0(value0);
		if (lc->savePendingLocal) {
			lc->savePending4Gc(value0);
		}
	}
	Object* old = (Object*)expected;
	if (old != nullptr && lc->savePendingLocal) {
		lc->savePending4Gc(old);
	}
	bool ret = cas(target, old, (Object*)value);
	if (ret) {
#ifdef ENABLE_OBJECT_REF_COUNT
		if (old != nullptr) {
			LocalController::releaseRefCount(old);
		}
#endif
		return (Object*)value;
	} else {
#ifdef ENABLE_OBJECT_REF_COUNT
		if (value != nullptr) {
			LocalController::releaseRefCount(value);
		}
#endif
	}
	return (Object*)old;
}

Reference* ObjectManagerInternal::getAndClearReferencePendingList() {
	if (objectManagerInited) {
		return globalController->getAndClearReferencePendingList();
	} else {
		return nullptr;
	}
}

bool ObjectManagerInternal::hasReferencePendingList() {
	if (objectManagerInited) {
		return globalController->hasReferencePendingList();
	} else {
		return false;
	}
}

void ObjectManagerInternal::waitForReferencePendingList() {
	if (objectManagerInited) {
		globalController->waitForReferencePendingList();
	} else {
		Thread::sleep(1);
	}
}

bool GlobalController::existsNonDaemonThread() {
	bool ret = false;
	{
		std::lock_guard lock(this->mutexGlobal);
		LocalControllerAtomicListIterator it = LocalControllerAtomicListIterator(&localControllerList);
		while (it.has()) {
			LocalController* controller = it.get();
			it.next();
			// printf("controller %s\n", controller->threadName);
			// localController is main thread
			if (!controller->exiting && !controller->daemon) {
				ret = true;
				break;
			}
		}
	}
	return ret;
}

void GlobalController::printThreads() {
	log_debug("GlobalController::printThreads() enter\n");
	std::lock_guard lock(this->mutexGlobal);
	LocalControllerAtomicListIterator it = LocalControllerAtomicListIterator(&localControllerList);
	while (it.has()) {
		LocalController* controller = it.get();
		it.next();
		//if (controller == localController) {
		//	log_debug("*");
		//}
		if (controller->exiting) {
			log_debug("exiting thread %s\n", controller->threadName);
		}  else if (controller->daemon) {
			log_debug("daemon thread %s\n", controller->threadName);
		} else {
			log_debug("thread %s\n", controller->threadName);
		}
	}
	log_debug("GlobalController::printThreads() leave\n");
}

bool isClassObj(Object* obj, Class* clazz) {
	if (obj != nullptr && clazz != nullptr && obj->getClass() == clazz) {
		return true;
	}
	return false;
}

template<typename T>
void LocalController::savePending4Gc(T obj) {
	//if (savePendingLocal) 
	{
		Object0* obj0 = toObject0(obj);
		ObjectHead* oh = toOh(obj0);
		if (oh->isStatic()) {
			return;
		}
		if (oh->isLive(liveCodeLocal)) {
			return;
		}
		if (oh->isGlobal() && globalGcType == GC_TYPE_ASYNC_LOCAL) {
			return;
		}
		if (localStop4gc) {
			int64_t stopSartNS = System::nanoTime();
			while (localStop4gc) {}
			stopNSLocal += System::nanoTime() - stopSartNS;
			return;
		}
		bool ret = pendingSaver.write(oh);
		if (!ret) {
			int64_t stopSartNS = System::nanoTime();
			while (savePendingLocal) {}
			stopNSLocal += System::nanoTime() - stopSartNS;
		}
	}
}

template<typename T>
inline void relist(ObjectHead* listHead, GcType gcType, GcResult* gcResult, CountSize& moveSize, T& targetList) {
	ObjectList list(listHead);
	ObjectListIterator it(&list);
	while (it.has()) {
		ObjectHead* oh = it.get();
		if (oh->isGlobal()) {
			it.remove();
			int64_t size = getMemorySize(oh);
			moveSize.add(size);
			globalController->moveInFromLocal(gcType, oh, size);
		} else {
			it.next();
		}
	}
	if (list.head != nullptr) {
		ObjectHead* oh = list.exchange(nullptr);
		targetList.prependList(oh, it.getPre());
	}
	//while (oh != nullptr) {
	//	ObjectHead* next = oh->next;
	//	if (oh->isGlobal()) {
	//		int64_t size = getMemorySize(oh);
	//		moveSize.add(size);
	//		globalController->moveInFromLocal(gcType, oh, size);
	//	} else {
	//		targetList.prepend(oh);
	//	}
	//	oh = next;
	//}
}

template<typename T>
inline void prependAll(ObjectHead* listHead, T& targetList) {
	if (listHead != nullptr) {
		if (targetList.isEmpty()) {
			targetList.exchange(listHead);
		} else {
			ListScaner<ObjectHead> scaner;
			scaner.scan(listHead);
			targetList.prependList(scaner.head, scaner.tail);
		}
	}
}

void LocalController::relist4New(GcType gcType, GcResult* gcResult) {
	CountSize moveSize;
	for (int i = 0; i < 1; i++) {
		{
			ObjectHead* listHead = newNormalListLocal1.exchange(nullptr);
			if (gcType != GC_TYPE_FULL) {
				prependAll(listHead, normalListLocal[0]);
			} else {
				relist(listHead, gcType, gcResult, moveSize, normalListLocal[0]);
			}
		}
		{
			ObjectHead* listHead = newNormalListLocal0.exchange(nullptr);
			//if (gcType != GC_TYPE_FULL) {
				prependAll(listHead, newNormalListLocal1);
			//} else {
				//relist(listHead, gcType, gcResult, moveSize, newNormalListLocal1);
			//}
		}
		{
			ObjectHead* listHead = newRefListLocal.exchange(nullptr);
			relist(listHead, gcType, gcResult, moveSize, refListLocal);
		}
		{
			ObjectHead* listHead = newHasFinalizeListLocal.exchange(nullptr);
			relist(listHead, gcType, gcResult, moveSize, hasFinalizeListLocal);
		}
	}
	objectCSLocal.sub(&moveSize);
	gcResult->moveToGlobal.add(&moveSize);
}

void LocalController::moveGlobalObjects(GcType gcType, GcResult* gcResult) {
	CountSize moveSize;
	{
		ObjectListIterator it(&refListLocal);
		while (it.has()) {
			ObjectHead* oh = it.get();
			if (oh->isGlobal()) {
				it.remove();
				int64_t size = getMemorySize(oh);
				moveSize.add(size);
				globalController->moveInFromLocal(gcType, oh, size);
			} else {
				it.next();
			}
		}
	}
	{
		ObjectListIterator it(&hasFinalizeListLocal);
		while (it.has()) {
			ObjectHead* oh = it.get();
			if (oh->isGlobal()) {
				it.remove();
				int64_t size = getMemorySize(oh);
				moveSize.add(size);
				globalController->moveInFromLocal(gcType, oh, size);
			} else {
				it.next();
			}
		}
	}
	{
		for (int i = 0; i < normalListCount; i++) {
			ObjectListIterator it(&normalListLocal[i]);
			while (it.has()) {
				ObjectHead* oh = it.get();
				if (oh->isGlobal()) {
					it.remove();
					int64_t size = getMemorySize(oh);
					moveSize.add(size);
					globalController->moveInFromLocal(gcType, oh, size);
				} else {
					it.next();
				}
			}
		}
	}
	objectCSLocal.sub(&moveSize);
	gcResult->moveToGlobal.add(&moveSize);
}

void ObjectManagerInternal::snapshotStackObjects(void* localController) {
	if (localController != nullptr) {
		LocalController* lc = (LocalController*)localController;
		lc->snapshotStackObjects();
	}
}

void ObjectManagerInternal::saveStackObject(void* localController, void* addr) {
	if (localController != nullptr) {
		LocalController* lc = (LocalController*)localController;
		lc->saveStackObject(addr);
	}
}

void LocalController::snapshotStackObjects() {
	uint64_t* stackBase = (uint64_t*)this->getStackBase();
	uint64_t* stackEnd = (uint64_t*)this->getStackEnd();
	ObjectStack* oStack = &objectStack;
#ifdef JCPP_OBJECT_STACK_OFFSET_MODE
	for (int64_t i = 0; i < oStack->varStackRemain; i++) {
		void* addr = oStack->varStack[i];
#else
	for (void** ptr = oStack->varStack; ptr < oStack->varStackRemain; ptr++) {
		void* addr = *ptr;// oStack->varStack[i];
#endif
		if (addr != nullptr) {
			if (((int64_t)addr & 0x7) != 0) {
				log_error("varStack (int64_t)addr & 0x7 != 0\n");
				continue;
			}

			Object* obj = nullptr;
			if ((void*)addr >= stackEnd && (void*)addr < stackBase) {
				obj = *(Object**)addr;
			} else {
				obj = (Object*)addr;
			}

			if (obj != nullptr) {
				stackObjects.add(obj);
			}
		}
	}

	//for (int i = 0; i < MAX_NEW_NORMAL_LIST_LOCAL; i++) {
	//	ObjectHead* oh = newNormalListLocal[i];
	//	Object0* obj0 = fromOh(oh);
	//	stackObjects.add(obj0);
	//}

#ifdef JCPP_OBJECT_STACK_OFFSET_MODE
	for (int64_t i = 0; i < oStack->refStackEnd; i++) {
		Object* obj = oStack->refStack[i];
#else
	for (Object** ptr = oStack->refStack; ptr < oStack->refStackEnd; ptr++) {
		Object* obj = *ptr;
#endif
		if (obj != nullptr) {
			stackObjects.add(obj);
		}
	}

	for (int32_t i = 0; i < jniLocalRefStackEndIndex; i++) {
		Object0* obj0 = jniLocalRefStack[i];
		if (obj0 != nullptr) {
			stackObjects.add(obj0);
		}
	}

	if (pendingThrowable != nullptr) {
		stackObjects.add(pendingThrowable);
	}
}

void LocalController::saveStackObject(void* addr) {
	uint64_t* stackBase = (uint64_t*)this->getStackBase();
	uint64_t* stackEnd = (uint64_t*)this->getStackEnd();
	if (addr != nullptr) {
		if (((int64_t)addr & 0x7) != 0) {
			return;
		}
		ObjectHead* oh = memoryManager.tryToObject(addr);
		if (oh == nullptr) {
			return;
		}
		//log_info("varStack addr:%p stackEnd:%p stackBase:%p\n", addr, stackEnd, stackBase);
		Object* obj = fromOh(oh);
		//if ((void*)addr >= stackEnd && (void*)addr < stackBase) {
		//	obj = *(Object**)addr;
		//} else {
		//	obj = (Object*)addr;
		//}

		if (obj != nullptr) {
			stackObjects.add(obj);
		}
	}
}

template<typename LiveMarker>
void LocalController::markLive(int8_t liveCode, REF_TYPE scanRefLevel, GcResult* gcResult) {
	Platform::snapshotStackObjects(javaThread);

	ScanContextPendingManager pendingManager;
	LiveMarker liveMarker;
	liveMarker.liveCode = liveCode;
	liveMarker.scanRefLevel = scanRefLevel;
	liveMarker.pendingManager = &pendingManager;
	void* obj = stackObjects.remove();
	while (obj != nullptr) {
		ObjectHead* oh = memoryManager.tryToObject(obj);
		obj = stackObjects.remove();
		if (oh == nullptr) {
			//log_info("varStack tryToObject null\n");
			continue;
		}
		if (!oh->isUsed()) {
			log_info("varStack !isUsed\n");
			continue;
		}
		liveMarker.scan(oh);
		liveMarker.processPendingScan();
	}
}

void LocalController::markLocalLive4RefCount(int8_t liveCode, REF_TYPE scanRefLevel, GcResult* gcResult) {
	Platform::snapshotStackObjects(javaThread);

	void* obj = stackObjects.remove();
	while (obj != nullptr) {
		ObjectHead* oh = memoryManager.tryToObject(obj);
		obj = stackObjects.remove();
		if (oh == nullptr) {
			continue;
		}
		if (!oh->isUsed()) {
			log_info("varStack !isUsed\n");
			continue;
		}
		if (!oh->isGlobal()) {
			oh->setLive(liveCode);
		}
	}
}

template<typename ReachMarker>
void LocalController::markReach(int8_t liveCode, REF_TYPE scanRefLevel, GcResult* gcResult) {
//	log_info("varStack %" PRId32  " scaned %" PRId32 " %" PRId64 "\n", varStackEndIndex, context.scanedCount, System::currentTimeMillis() - startMs);
	ScanContextPendingManager pendingManager;

	ReachMarker reachMarker;
	reachMarker.liveCode = liveCode;
	reachMarker.scanRefLevel = scanRefLevel;
	reachMarker.pendingManager = &pendingManager;

	{
		AtomicObjectListIterator it(&newNormalListLocal0);
		while (it.has()) {
			ObjectHead* oh = it.get();
			it.next();
			reachMarker.scan(oh);
			reachMarker.processPendingScan();
		}
	}
	{
		AtomicObjectListIterator it(&newRefListLocal);
		while (it.has()) {
			ObjectHead* oh = it.get();
			it.next();
			reachMarker.scan(oh);
			reachMarker.processPendingScan();
		}
	}
	{
		AtomicObjectListIterator it(&newHasFinalizeListLocal);
		while (it.has()) {
			ObjectHead* oh = it.get();
			it.next();
			reachMarker.scan(oh);
			reachMarker.processPendingScan();
		}
	}
	{
		ObjectListIterator it(&newNormalListLocal1);
		while (it.has()) {
			ObjectHead* oh = it.get();
			it.next();
			reachMarker.scan(oh);
			reachMarker.processPendingScan();
		}
	}
	//{
	//	ObjectListIterator it(&newRefListLocal1);
	//	while (it.has()) {
	//		ObjectHead* oh = it.get();
	//		it.next();
	//		reachMarker.scan(oh);
	//		reachMarker.processPendingScan();
	//	}
	//}
	//{
	//	ObjectListIterator it(&newHasFinalizeListLocal1);
	//	while (it.has()) {
	//		ObjectHead* oh = it.get();
	//		it.next();
	//		reachMarker.scan(oh);
	//		reachMarker.processPendingScan();
	//	}
	//}
	{
		ObjectListIterator it(&refListLocal);
		while (it.has()) {
			ObjectHead* oh = it.get();
			it.next();
			reachMarker.scan(oh);
			reachMarker.processPendingScan();
		}
	}
	
//	log_info("refQueueLocal %" PRId64 "\n", System::currentTimeMillis() - startMs);

	{
		// can not move follow code before refQueueLocal
		ObjectListIterator it(&hasFinalizeListLocal);
		while (it.has()) {
			ObjectHead* oh = it.get();
			it.next();

			// do not update the reachCode of the Object that has finalize
			int8_t oldReachCode = oh->reachCode;
			reachMarker.scan(oh);
			reachMarker.processPendingScan();
			if (oh->reachCode != oldReachCode) {
				oh->reachCode = oldReachCode;
			}
		}
	}
//	log_info("hasFinalizeQueueLocal %" PRId64 "\n", System::currentTimeMillis() - startMs);
}

void GlobalController::markLiveGlobal(REF_TYPE scanRefLevel, GcResult* gcResult) {

	ScanContextPendingManager pendingManager;
	ScanMarkLive4All liveMarker;
	liveMarker.liveCode = liveCodeGlobal;
	liveMarker.scanRefLevel = scanRefLevel;
	liveMarker.pendingManager = &pendingManager;

	// thread
	{
		LocalControllerAtomicListIterator it = LocalControllerAtomicListIterator(&localControllerList);
		while (it.has()) {
			LocalController* controller = it.get();
			it.next();
			if (controller->status == LC_STATUS_RUN) {
				Thread* thread = controller->thread;
				if (thread != nullptr) {
					ObjectHead* oh = toOh($of(thread));
					liveMarker.scan(oh);
					liveMarker.processPendingScan();
				}
			}
		}
	}

	// static object
	{
		ObjectListIterator it(&staticListGlobal);
		while (it.has()) {
			ObjectHead* oh = it.get();
			liveMarker.scan(oh);
			liveMarker.processPendingScan();
			it.next();
		}
	}

	// static field
	{
		lock_guard lock(mutexStaticPointerManager);
		StaticPointerManager::Iterator staticPointerManagerIt(&staticPointerManager);
		while (staticPointerManagerIt.hasNext()) {
			Object** pointer = staticPointerManagerIt.next();
			if (pointer != nullptr) {
				Object* obj = *pointer;
				if (obj != nullptr) {
					Object0* obj0 = toObject0(obj);
					ObjectHead* oh = toOh(obj0);
					liveMarker.scan(oh);
					liveMarker.processPendingScan();
				}
			}
		}
	}

	// refPending
	// don't care refPendingListLock, since come here is in full gc
	Reference* ref = refPendingList;
	while (ref != nullptr) {
		liveMarker.scan(ref);
		liveMarker.processPendingScan();
		ref = ref->discovered;
	}
}

void GlobalController::markReachGlobal(REF_TYPE scanRefLevel, GcResult* gcResult) {

	ScanContextPendingManager pendingManager;
	ScanMarkLive4All liveMarker;
	liveMarker.liveCode = liveCodeGlobal;
	liveMarker.scanRefLevel = scanRefLevel;
	liveMarker.pendingManager = &pendingManager;

	ScanContextPendingManager pendingManagerRef;
	ScanMarkReach4All reachMaker;
	reachMaker.liveCode = liveCodeGlobal;
	reachMaker.scanRefLevel = scanRefLevel;
	reachMaker.pendingManager = &pendingManagerRef;

	{
		ObjectListIterator it(&refListGlobal);
		while (it.has()) {
			ObjectHead* oh = it.get();
			it.next();
#ifdef OBJECT_DEBUG
			if (oh->isDebug() || !oh->isUsed()) {
				debugObjectHead("markReachGlobal.refListGlobal", oh);
			}
			//if (oh->getRefType() == OBJECT_REF_TYPE_WEAK) {
			//	oh->getRefType();
			//}
#endif
			Reference* ref = (Reference*)fromOh(oh);
			
			if (oh->isGlobalRef()) {
				if (oh->getRefType() == OBJECT_REF_TYPE_GLOBAL) {
					liveMarker.scan(oh);
					liveMarker.processPendingScan();
				} else {
					reachMaker.scan(oh);
					reachMaker.processPendingScan();
				}
				if (!oh->isLive(liveCodeGlobal)) {
					oh->setLive(liveCodeGlobal);
				}
			} else {
				reachMaker.scan(oh);
				reachMaker.processPendingScan();
			}
		}
	}

	{
		// can not move follow code before refListGlobal
		ObjectListIterator it(&hasFinalizeListGlobal);
		while (it.has()) {
			ObjectHead* oh = it.get();
			it.next();

			// do not update the reachCode of the Object that has finalize
			int8_t oldReachCode = oh->reachCode;
			reachMaker.scan(oh);
			reachMaker.processPendingScan();
			if (oh->reachCode != oldReachCode) {
				oh->reachCode = oldReachCode;
			}
		}
	}

	{
		// can not move follow code before refListGlobal
		ObjectListIterator it(&hasFinalizePendingListGlobal);
		while (it.has()) {
			ObjectHead* oh = it.get();
			it.next();

			// do not update the reachCode of the Object that has finalize
			int8_t oldReachCode = oh->reachCode;
			reachMaker.scan(oh);
			reachMaker.processPendingScan();
			if (oh->reachCode != oldReachCode) {
				oh->reachCode = oldReachCode;
			}
		}
	}
}

void GlobalController::markLiveAllPending(int8_t liveCode, REF_TYPE scanRefLevel, GcResult* gcResult) {
	LocalControllerAtomicListIterator it = LocalControllerAtomicListIterator(&localControllerList);
	while (it.has()) {
		LocalController* controller = it.get();
		it.next();
		//log_debug("markLiveAllPending controller:%s\n", controller->threadName);
		controller->markLiveAllPending(liveCode, scanRefLevel, gcResult);
	}
}

void LocalController::localGc(REF_TYPE scanRefLevel) {
	if (mutexLocal.try_lock()) {
		if (globalGcType == GC_TYPE_NONE && gcStatusLocal == GC_STATUS_NONE) {
			log_debug("local gc start %s count:%" PRId64 ", size:%" PRId64 "\n", getRefTypeName(scanRefLevel), memoryManager.getTotalCount(), memoryManager.getTotalSize());
			clearVarStackRemain();
			GcResult gcResult(GC_TYPE_LOCAL);
			gcResult.threadCount = 1;

			int64_t startNS = System::nanoTime();
			int8_t liveCode = genNextLocalLiveCode(liveCodeSequenceLocal);
			liveCodeLocal = liveCode;
			gcResult.liveCode = liveCode;

			relist4New(GC_TYPE_LOCAL, &gcResult);
			int64_t prepareDoneNS = System::nanoTime();
			gcResult.prepareNS = prepareDoneNS - startNS;

			markLiveLocal(liveCode, scanRefLevel, &gcResult);
			markReachLocal(liveCode, scanRefLevel, &gcResult);
			int64_t markDoneNs = System::nanoTime();
			gcResult.markNS = markDoneNs - prepareDoneNS;

			processLocalObject(liveCode, GC_TYPE_LOCAL, &gcResult);
			liveCodeLocal = 0;
			optAllocs(false);
			int64_t processDoneNs = System::nanoTime();
			gcResult.processNS = processDoneNs - markDoneNs;

			int64_t costNs = processDoneNs - startNS;
			gcResult.costNS = costNs;
			gcResult.stopNS = 0;
			gcResult.realStopNS = costNs;
			statLocal.gc(costNs, gcResult.stopNS, gcResult.realStopNS);

		//	statLocal.print("localGced");
			//memoryManager.opt(MemoryManager::OPT_GC);
			gcResult.print("localGc");
			log_debug("local gc finsh %s count:%" PRId64 ", size:%" PRId64 "\n", getRefTypeName(scanRefLevel), memoryManager.getTotalCount(), memoryManager.getTotalSize());
		}
		mutexLocal.unlock();
	}
}

#ifdef ENABLE_OBJECT_REF_COUNT
void LocalController::localGcWithRefCount(REF_TYPE scanRefLevel) {
	if (mutexLocal.try_lock()) {
		if (globalGcType == GC_TYPE_NONE && gcStatus == GC_STATUS_NONE) {
			log_debug("localGcWithRefCount start\n");
			//	statLocal.print("localGcing");
			GcResult gcResult;
			gcResult.threadCount = 1;
			int64_t startNs = System::nanoTime();
			//this->scanRefLevel = scanRefLevel;
			int8_t liveCode = genNextLocalLiveCode(liveCodeSequenceLocal);
			gcResult.liveCode = liveCode;
			markLocalLive4RefCount(liveCode, scanRefLevel, &gcResult);
			relist4New(false, &gcResult);
			processLocalObjectWithRefCount(liveCode, false, &gcResult);
			//	statLocal.print("localGced");
			//log_info("localGcWithRefCount end %d\n", (int8_t)liveCode);
			int64_t costNs = System::nanoTime() - startNs;
			//statLocal.localGc(cost);
			gcResult.costNS = costNs;
			gcResult.print("localGcWithRefCount");
		}
		mutexLocal.unlock();
	}
}
#endif

void LocalController::asyncLocalGc(REF_TYPE scanRefLevel, GcResult* gcResult) {
	//log_info("localGcFromManager start\n");
//	statLocal.print("localGcing");

	if (mutexLocal.try_lock()) {
		GcResult localGcResult(GC_TYPE_ASYNC_LOCAL);
		int64_t startNS = System::nanoTime();

		int8_t liveCode = genNextLocalLiveCode(liveCodeSequenceLocal);
		liveCodeLocal = liveCode;
		relist4New(GC_TYPE_ASYNC_LOCAL, &localGcResult);
		int64_t prepareDoneNS = System::nanoTime();
		gcResult->prepareNS = prepareDoneNS - startNS;

		clearPendingManager4Gc();
		savePendingLocal = true;
		markLiveLocal(liveCode, scanRefLevel, &localGcResult);
		//relist4New(GC_TYPE_ASYNC_LOCAL, &localGcResult);
		markReachLocal(liveCode, scanRefLevel, &localGcResult);
		this->markLiveLocalPending(liveCode, scanRefLevel, &localGcResult);
		int64_t stopStartNS = System::nanoTime();
		this->stopNSLocal = 0;
		this->localStop4gc = true;
		this->markLiveLocalPending(liveCode, scanRefLevel, &localGcResult);
		this->localStop4gc = false;
		savePendingLocal = false;
		int64_t markDoneNs = System::nanoTime();
		localGcResult.markNS = markDoneNs - prepareDoneNS;

		cvLocal.notify_all();
		int64_t stopEndNS = System::nanoTime();
		int64_t stopNs = stopEndNS - stopStartNS;
		localGcResult.stopNS = stopNs;
		localGcResult.realStopNS = stopNSLocal;
		processLocalObject(liveCode, GC_TYPE_ASYNC_LOCAL, &localGcResult);
		liveCodeLocal = 0;
		optAllocs(false);
		int64_t processDoneNs = System::nanoTime();
		localGcResult.processNS = processDoneNs - stopEndNS;
		int64_t cost = processDoneNs - startNS;
		statLocal.gc(cost, localGcResult.stopNS, localGcResult.realStopNS);
		int64_t gcSize = localGcResult.free.size + localGcResult.moveToGlobal.size;
		int64_t objectSize = objectCSLocal.size.value();

		//if (gcSize == 0) {
		//	this->skipAsyncLocalGcCount = 10;
		//} else {
		//	if (objectSize > 0) {
		//		if (gcSize < objectSize) {
		//			double r = (double)gcSize / objectSize;
		//			if (gcSize < 0.001) {
		//				this->skipAsyncLocalGcCount = 10;
		//			} else if (gcSize < 0.01) {
		//				this->skipAsyncLocalGcCount = 5;
		//			}
		//		}
		//	}
		//	if (gcSize < 64 * 1024) {
		//		this->skipAsyncLocalGcCount += 10;
		//	} else if (gcSize < 512 * 1024) {
		//		this->skipAsyncLocalGcCount += 5;
		//	}
		//}
		gcResult->threadCount++;
		gcResult->sum(&localGcResult);

		this->cvLocal.notify_all();
		mutexLocal.unlock();
	}
	//	statLocal.print("localGced");
		//log_info("localGcFromManager end %d\n", (int8_t)liveCode);
}

void LocalController::fullGc(REF_TYPE scanRefLevel) {
	GcResult gcResult(GC_TYPE_FULL);
	globalController->fullGc0(scanRefLevel, &gcResult);
	statLocal.gc(gcResult.costNS, gcResult.stopNS, gcResult.realStopNS);
}

void LocalController::markLiveLocal(int8_t liveCode, REF_TYPE scanRefLevel, GcResult* gcResult) {
	markLive<ScanMarkLive4Local>(liveCode, scanRefLevel, gcResult);
	//log_info("markLiveLocal done\n");
}

void LocalController::markReachLocal(int8_t liveCode, REF_TYPE scanRefLevel, GcResult* gcResult) {
	markReach<ScanMarkReach4Local>(liveCode, scanRefLevel, gcResult);
}

//void LocalController::markLiveAndRefCountLocal() {
//	clearVarStackRemain();
//	markLive<ScanMarkLiveAndRefCount4Local, ScanMarkReachAndRefCount4Local>();
//}

void LocalController::markLiveAll(int8_t liveCode, REF_TYPE scanRefLevel, GcResult* gcResult) {
	//log_info("markLiveAll start %s\n", this->threadName);
	markLive<ScanMarkLive4All>(liveCode, scanRefLevel, gcResult);
	//log_info("markLiveAll done %s\n", this->threadName);
}

void LocalController::markReachAll(int8_t liveCode, REF_TYPE scanRefLevel, GcResult* gcResult) {
	markReach<ScanMarkReach4All>(liveCode, scanRefLevel, gcResult);
}

void LocalController::markLiveAllPending(int8_t liveCode, REF_TYPE scanRefLevel, GcResult* gcResult) {
	markLivePending<ScanMarkLive4All, ScanMarkReach4All>(liveCode, scanRefLevel, gcResult);
}

void LocalController::markLiveLocalPending(int8_t liveCode, REF_TYPE scanRefLevel, GcResult* gcResult) {
	markLivePending<ScanMarkLive4Local, ScanMarkReach4Local>(liveCode, scanRefLevel, gcResult);
}

template<typename LiveMarker, typename ReachMarker>
void LocalController::markLivePending(int8_t liveCode, REF_TYPE scanRefLevel, GcResult* gcResult) {
	GcHandlePendingReader reader(&pendingSaver);
	if (pendingSaver.getHead() != nullptr) {
		ScanContextPendingManager pendingManager;
		LiveMarker liver;
		liver.liveCode = liveCode;
		liver.scanRefLevel = scanRefLevel;
		liver.pendingManager = &pendingManager;

		ScanContextPendingManager reachPendingManager;
		ReachMarker reacher;
		reacher.liveCode = liveCode;
		reacher.scanRefLevel = scanRefLevel;
		reacher.pendingManager = &reachPendingManager;

		ObjectHead* oh = reader.read();
		while (oh != nullptr) {
#ifdef OBJECT_DEBUG
			if (oh->isDebug() || !oh->isUsed()) {//} || oh->clazz == WeakReference::class$) {
				debugObjectHead("markLivePending", oh);
			}
#endif
			liver.scan(oh);
			liver.processPendingScan();
			reacher.scan(oh);
			reacher.processPendingScan();
#ifdef OBJECT_DEBUG
			if (oh->isDebug() || !oh->isUsed()) {//} || oh->clazz == WeakReference::class$) {
				debugObjectHead("markLivePending finsh", oh);
			}
#endif
			oh = reader.read();
		}
		//liver.processPendingScan();
		//reacher.processPendingScan();
	}
}

void LocalController::clearPendingManager4Gc() {
	pendingSaver.clear0();
}

void LocalController::processLocalObject(int8_t liveCode, GcType gcType, GcResult* gcResult) {
	ObjectList moveToGlobalPendingList;
	CountSize moveSize;

	{
		ObjectListIterator it(&refListLocal);
		while (it.has()) {
			ObjectHead* oh = it.get();
#ifdef OBJECT_DEBUG
			if (oh->isDebug() || !oh->isUsed()) {
				debugObjectHead("processLocalObject.refQueueLocal", oh);
			}
#endif
			if (oh->isGlobal()) {
				it.remove();
				int64_t size = getMemorySize(oh);
				moveSize.add(size);
				globalController->addWaitToDispatch(oh, size);
				continue;
			}
			Reference* ref = (Reference*)fromOh(oh);
			Object* referent = (Object*)ref->referent;
			if (referent != nullptr) {
				ObjectHead* referentOH = toOh(toObject0(referent));
				if (referentOH->isGlobal()) {
#ifdef OBJECT_DEBUG
					if (oh->isDebug() || !oh->isUsed()) {
						debugObjectHead("processLocalObject.refQueueLocal referent isGlobal", oh);
					}
#endif
					it.remove();
					moveToGlobalPendingList.prepend(oh);
					continue;
				}

				bool isReferentLive = referentOH->isLive(liveCode);
				if (!isReferentLive) {
#ifdef OBJECT_DEBUG
					if (oh->isDebug() || !oh->isUsed()) {
						debugObjectHead("processLocalObject.refQueueLocal referent is not live", oh);
					}
#endif
#ifdef ENABLE_OBJECT_REF_COUNT
					releaseRefCount(referentOH);
#endif
					ref->referent = nullptr; // do not call clear(), since clear() maybe cause new/throw actions
					it.remove();
					moveToGlobalPendingList.prepend(oh);
					continue;
				}
			} else {
				it.remove();
				moveToGlobalPendingList.prepend(oh);
				continue;
			}
			it.next();
		}
	}

	{
		ObjectListIterator it(&hasFinalizeListLocal);
		while (it.has()) {
			ObjectHead* oh = it.get();
#ifdef OBJECT_DEBUG
			if (oh->isDebug() || !oh->isUsed()) {
				debugObjectHead("processLocalObject.hasFinalizeQueueLocal", oh);
			}
#endif
			if (oh->isGlobal()) {
				it.remove();
				int64_t size = getMemorySize(oh);
				moveSize.add(size);
				globalController->addWaitToDispatch(oh, size);
				continue;
			} else if (!oh->isReach(liveCode)) {
#ifdef OBJECT_DEBUG
				if (oh->isDebug() || !oh->isUsed()) {
					debugObjectHead("processLocalObject.hasFinalizeQueueLocal is not live", oh);
				}
#endif
				oh->setHasFinalizePending();
				it.remove();
				moveToGlobalPendingList.prepend(oh);
				continue;
			} else {
				it.next();
			}
		}
	}

	ObjectList toFreeList;
	CountSize freeSize;

	{
		processCount++;
		ObjectHead* tails[normalListCount];
		for (int i = 0; i < normalListCount; i++) {
			ObjectListIterator it(&normalListLocal[i]);
			ObjectHead* tail = nullptr;
			if (i < normalListCount - 1 || gcType == GC_TYPE_FULL || processCount % 10 == 0) {
				while (it.has()) {
					ObjectHead* oh = it.get();
#ifdef OBJECT_DEBUG
					if (oh->isDebug() || !oh->isUsed()) {
						debugObjectHead("processLocalObject.normalQueueLocal", oh);
					}
#endif
					if (oh->isGlobal()) {
						it.remove();
						int64_t size = getMemorySize(oh);
						moveSize.add(size);
						globalController->addWaitToDispatch(oh, size);
						continue;
					} else if (!oh->isReach(liveCode)) {
						it.remove();
						//toFreeList.prepend(oh);
						int64_t size = getMemorySize(oh);
						freeSize.add(size);
						freeLocalObject(gcType, oh);
						continue;
					} else {
						tail = oh;
						it.next();
					}
				}
			}
			tails[i] = tail;
			if (i > 0) {
				if (i < normalListCount && tails[i - 1] != nullptr) {
					ObjectHead* head = normalListLocal[i - 1].exchange(nullptr);
					if (head != nullptr) {
						normalListLocal[i].prependList(head, tails[i - 1]);
					}
				}
			}
		}
	}
	statLocal.free(freeSize.count, freeSize.size);
	objectCSLocal.sub(&freeSize);
	gcResult->free.add(&freeSize);
	if (!moveToGlobalPendingList.isEmpty()) {
		ScanContextPendingManager pendingManager;
		ScanMarkGlobal scanner;
		scanner.pendingManager = &pendingManager;
		ObjectHead* oh = moveToGlobalPendingList.removeFirst();
		while (oh != nullptr) {
			scanner.scan(oh);
			scanner.processPendingScan();
			int64_t size = getMemorySize(oh);
			moveSize.add(size);
			globalController->moveInFromLocal(gcType, oh, size);
			oh = moveToGlobalPendingList.removeFirst();
		}
		if (gcType == GC_TYPE_FULL) {
			moveGlobalObjects(gcType, gcResult);
		}
	}
	objectCSLocal.sub(&moveSize);
	gcResult->moveToGlobal.add(&moveSize);

	freeLocalObject(gcType, &toFreeList, gcResult);
	pendingObjectCS.clear();
}

void LocalController::freeLocalObject(GcType gcType, ObjectList* toFreeList, GcResult* gcResult) {
	if (!toFreeList->isEmpty()) {
		CountSize freeSize;
		ObjectHead* oh = toFreeList->removeFirst();
		while (oh != nullptr) {
			int64_t size = getMemorySize(oh);
			freeSize.add(size);
			statLocal.free(size);
			freeLocalObject(gcType, oh);
			oh = toFreeList->removeFirst();
		}
		objectCSLocal.sub(&freeSize);
		gcResult->free.add(&freeSize);
	}
}

#ifdef ENABLE_OBJECT_REF_COUNT
void LocalController::processLocalObjectWithRefCount(int8_t liveCode, GcType gcType, GcResult* gcResult) {
	AtomicObjectList moveToGlobalPendingList;

	{
		AtomicObjectListIterator it(&refListLocal);
		while (it.has()) {
			ObjectHead* oh = it.get();
#ifdef OBJECT_DEBUG
			if (oh->isDebug() || !oh->isUsed()) {
				debugObjectHead("processLocalObjectWithRefCount.refQueueLocal", oh);
			}
#endif
			if (oh->isGlobal()) {
				it.remove();
				int64_t size = getMemorySize(oh);
				objectCSLocal.sub(size);
				gcResult->moveToGlobal.add(size);
				globalController->addWaitToDispatch(oh);
				continue;
			}
			Reference* ref = (Reference*)fromOh(oh);
			Object* referent = (Object*)ref->referent;
			if (referent != nullptr) {
				ObjectHead* referentOH = toOh(toObject0(referent));
				if (referentOH->isGlobal()) {
#ifdef OBJECT_DEBUG
					if (oh->isDebug() || !oh->isUsed()) {
						debugObjectHead("processLocalObjectWithRefCount.refQueueLocal referent isGlobal", oh);
					}
#endif
					it.remove();
					moveToGlobalPendingList.prepend(oh);
					continue;
				}

				bool isReferentLive = referentOH->isLive(liveCode) || referentOH->getLocalRefCount() > 1;
				/*
				if (!isReferentLive && referentOH->isRef()) {
					Reference* refRef = (Reference*)(void*)toObject0(referentOH);
					Object* refReferent = (Object*)refRef->referent;
					if (refReferent != nullptr) {
						isReferentLive = true;
					}
				}
				*/
				if (!isReferentLive) {
#ifdef OBJECT_DEBUG
					if (oh->isDebug() || !oh->isUsed()) {
						debugObjectHead("processLocalObjectWithRefCount.refQueueLocal referent is not live", oh);
					}
#endif
					releaseRefCount(referentOH);
					ref->referent = nullptr; // do not call clear(), since clear() maybe cause new/throw actions
					it.remove();
					moveToGlobalPendingList.prepend(oh);
					continue;
				}
			} else {
				it.remove();
				moveToGlobalPendingList.prepend(oh);
				continue;
			}
			it.next();
		}
	}

	{
		AtomicObjectListIterator it(&hasFinalizeListLocal);
		while (it.has()) {
			ObjectHead* oh = it.get();
#ifdef OBJECT_DEBUG
			if (oh->isDebug() || !oh->isUsed()) {
				debugObjectHead("processLocalObjectWithRefCount.hasFinalizeQueueLocal", oh);
			}
#endif
			if (oh->isGlobal()) {
				it.remove();
				int64_t size = getMemorySize(oh);
				objectCSLocal.sub(size);
				gcResult->moveToGlobal.add(size);
				globalController->addWaitToDispatch(oh);
				continue;
			} else if (oh->isRef()) {
				it.remove();
				refListLocal.prepend(oh);
				continue;
			}
			if (!(oh->isReach(liveCode) || oh->getLocalRefCount() > 0)) {
#ifdef OBJECT_DEBUG
				if (oh->isDebug() || !oh->isUsed()) {
					debugObjectHead("processLocalObjectWithRefCount.hasFinalizeQueueLocal is not live", oh);
				}
#endif
				oh->setHasFinalizePending();
				it.remove();
				moveToGlobalPendingList.prepend(oh);
				continue;
			} else {
				it.next();
			}
		}
	}

	AtomicObjectList toFreeList;
	{
		AtomicObjectListIterator it(&normalListLocal);
		while (it.has()) {
			ObjectHead* oh = it.get();
#ifdef OBJECT_DEBUG
			if (oh->isDebug() || !oh->isUsed()) {
				debugObjectHead("processLocalObjectWithRefCount.normalQueueLocal", oh);
			}
#endif
			if (oh->isGlobal()) {
				it.remove();
				int64_t size = getMemorySize(oh);
				objectCSLocal.sub(size);
				gcResult->moveToGlobal.add(size);
				globalController->addWaitToDispatch(oh);
				continue;
			} else if (oh->isRef()) {
				it.remove();
				refListLocal.prepend(oh);
				continue;
			} else if (oh->isHasFinalize()) {
				it.remove();
				hasFinalizeListLocal.prepend(oh);
				continue;
			}
			if (!(oh->isReach(liveCode) || oh->getLocalRefCount() > 0)) {
				it.remove();
				toFreeList.prepend(oh);
				int64_t size = getMemorySize(oh);
				pendingObjectCS.sub(size);
				if (pendingObjectCS.size <= 0) {
					break;
				}
				continue;
			} else {
				it.next();
			}
		}
	}

	if (!toFreeList.isEmpty()) {
		ObjectHead* oh = toFreeList.removeFirst();
		while (oh != nullptr) {
			if (inFullGc) {
				statLocal.freeByFullGc(sizeof(oh));
			} else {
				statLocal.freeByLocalGc(sizeof(oh));
			}
			clearLocalRefForFree(oh);
			int64_t size = getMemorySize(oh);
			objectCSLocal.sub(size);
			gcResult->moveToGlobal.add(size);
			freeLocalObject(oh);
			oh = toFreeList.removeFirst();
		}
	}

	if (!moveToGlobalPendingList.isEmpty()) {
		ObjectHead* oh = moveToGlobalPendingList.removeFirst();
		while (oh != nullptr) {
			scanMarkGlobal(oh);
			int64_t size = getMemorySize(oh);
			objectCSLocal.sub(size);
			gcResult->moveToGlobal.add(size);
			globalController->addWaitToDispatch(oh);
			oh = moveToGlobalPendingList.removeFirst();
		}

		//if (pendingObjectCS.count < 0) {
		//	this->pendingObjectCS.clear();
		//}
	}

	this->pendingObjectCS.clear();
}
#endif // ENABLE_OBJECT_REF_COUNT

void GlobalController::processGlobalObject(GcResult* gcResult) {
	ObjectList toFreeList;

	if (false) {
		ObjectListIterator it(&constListGlobal);
		while (it.has()) {
			ObjectHead* oh = it.get();
	#ifdef OBJECT_DEBUG
			if (oh->isDebug() || !oh->isUsed()) {
				debugObjectHead("processGlobalObject.constListGlobal", oh);
			}
			Reference* ref = (Reference*)fromOh(oh);
	#endif
			if (!oh->isReach(liveCodeGlobal)) {
				//if (oh->clazz == String::class$) {
				//	String* s = (String*)fromOh(oh);
				//	String::resetIntern(s);
				//}
				it.remove();
				toFreeList.prepend(oh);
				continue;
			} else {
				it.next();
			}
		}
	}

	{
		ObjectListIterator it(&refPendingListGlobal);
		while (it.has()) {
			ObjectHead* oh = it.get();
	#ifdef OBJECT_DEBUG
			if (oh->isDebug() || !oh->isUsed()) {
				debugObjectHead("processGlobalObject.refPendingListGlobal", oh);
			}
			Reference* ref = (Reference*)fromOh(oh);
	#endif
			if (!oh->isReach(liveCodeGlobal)) {
				it.remove();
				if (oh->isHasFinalize()) {
					oh->clearRefPending();
					oh->setRefType(OBJECT_REF_TYPE_DEFAULT);
					oh->setHasFinalizePending();
					hasFinalizePendingListGlobal.prepend(oh);
				} else {
					toFreeList.prepend(oh);
				}
				continue;
			} else {
				it.next();
			}
		}
	}

	{
		ObjectListIterator it(&refListGlobal);
		while (it.has()) {
			ObjectHead* oh = it.get();
#ifdef OBJECT_DEBUG
			if (oh->isDebug() || !oh->isUsed()) {
				debugObjectHead("processGlobalObject.refListGlobal", oh);
			}
#endif
			/*
			if (!oh->isReach(liveCode)) {
				it.remove();
				if (oh->isHasFinalize()) {
					oh->clearRefPending();
					oh->setRefType(OBJECT_REF_TYPE_DEFAULT);
					oh->setHasFinalizePending();
					hasFinalizePendingListGlobal.prepend(oh);
				} else {
					toFreeList.prepend(oh);
				}
				continue;
			}
			*/

			Reference* ref = (Reference*)(void*)fromOh(oh);
			Object* referent = (Object*)ref->referent;
			if (referent != nullptr) {
				ObjectHead* referentOH = toOh(toObject0(referent));
#ifdef OBJECT_DEBUG
				if (referentOH->isDebug() || !oh->isUsed()) {
					debugObjectHead("processGlobalObject.refListGlobal referentOH", oh);
				}
#endif
				bool isReferentLive = referentOH->isLive(liveCodeGlobal);
				if (!isReferentLive) {
#ifdef ENABLE_OBJECT_REF_COUNT
					LocalController::releaseRefCount(referentOH);
#endif
					ref->referent = nullptr;
					if (!oh->isGlobalRef()) {
						addToPendingList(ref); // don't care refPendingListLock, since come here is in full gc
						oh->setRefPending();
						//$debug(ref);
						it.remove();
						refPendingListGlobal.prepend(oh);
						continue;
					}
				}
			} else if (!oh->isGlobalRef()) {
				addToPendingList(ref); // don't care refPendingListLock, since come here is in full gc
				oh->setRefPending();
				//$debug(ref);
				it.remove();
				refPendingListGlobal.prepend(oh);
				continue;
			}
			it.next();
		}
	}

	{
		ObjectListIterator it(&hasFinalizeListGlobal);
		while (it.has()) {
			ObjectHead* oh = it.get();
#ifdef OBJECT_DEBUG
			if (oh->isDebug() || !oh->isUsed()) {
				debugObjectHead("processGlobalObject.hasFinalizeListGlobal", oh);
			}
#endif
			if (!oh->isReach(liveCodeGlobal)) {
				oh->setHasFinalizePending();
				it.remove();
				hasFinalizePendingListGlobal.prepend(oh);
				continue;
			} else {
				it.next();
			}
		}
	}

	{
		ObjectListIterator it(&normalListGlobal);
		while (it.has()) {
			ObjectHead* oh = it.get();
	#ifdef OBJECT_DEBUG
			if (oh->isDebug() || !oh->isUsed()) {
				debugObjectHead("processGlobalObject.normalListGlobal", oh);
			}
	#endif
			if (!oh->isReach(liveCodeGlobal)) {
				it.remove();
				toFreeList.prepend(oh);
				continue;
			} else {
				it.next();
			}
		}
	}

	if (!toFreeList.isEmpty()) {
		ObjectHead* oh = toFreeList.removeFirst();
		while (oh != nullptr) {
			int64_t size = getMemorySize(oh);
			statCurrentGobal.free(size);
			gcResult->free.add(size);
			freeGlobal(oh);
			oh = toFreeList.removeFirst();
		}
	}

	processHasFinalizePendingQueueGlobal();
}

void GlobalController::processHasFinalizePendingQueueGlobal() {
	ObjectListIterator it(&hasFinalizePendingListGlobal);
	while (it.has()) {
		if (!finalizerStore->canAlloc()) {
			break;
		}
		ObjectHead* oh = it.get();
		it.remove();
		oh->clearHasFinalize();
		oh->clearHasFinalizePending();
		Object0* obj = fromOh(oh);
		{
			$synchronized(Finalizer::lock) {
				Finalizer::register$(obj);
				Finalizer::queue->enqueue(Finalizer::unfinalized);
			}
		}
		normalListGlobal.prepend(oh);
	}
}

int32_t ObjectManagerInternal::availableProcessors() {
	return Platform::getActiveProcessorCount();
}

int64_t ObjectManagerInternal::freeMemory() {
	return memoryManager.getFreeMemory();
}

int64_t ObjectManagerInternal::totalMemory() {
	return memoryManager.getTotalMemory();
}

int64_t ObjectManagerInternal::maxMemory() {
	return freeMemory() + totalMemory();
}

//int32_t gcCount = 0;
void ObjectManagerInternal::gc() {
	//if (gcCount++ % 2 == 0) {
	//localController->clearVarStackRemain();

	GcResult gcResult(GC_TYPE_FULL);
	globalController->fullGc0(OBJECT_REF_TYPE_SOFT, &gcResult);
	//} else {
	//	globalController->localGcFromManager(OBJECT_REF_TYPE_SOFT, true);
	//}
	// if (localController->gcCount++ % 2 == 0) {
	//	localController->fullGc(OBJECT_REF_TYPE_SOFT);
	/// } else {
		// localController->localGc(OBJECT_REF_TYPE_SOFT);
	// }
}

void ObjectManagerInternal::setXms(int64_t size) {
	memoryManager.setMinMemorySize(size);
}

void ObjectManagerInternal::setXmx(int64_t size) {
	memoryManager.setMaxMemorySize(size);
}

int64_t xss = 0;

void ObjectManagerInternal::setXss(int64_t size) {
	xss = size;
}

int64_t ObjectManagerInternal::getXss() {
	return xss;
}

ObjectStackType objectStackType = OBJECT_STACK_TYPE_DEFAULT;

void ObjectManagerInternal::setObjectStackType(ObjectStackType type) {
	objectStackType = type;
}

ObjectStackType ObjectManagerInternal::getObjectStackType() {
	return objectStackType;
}

::java::lang::Class* ObjectManager::allocClassClass() {
	return globalController->allocClassClass();
}

Object* ObjectManager::allocStatic(Class* clazz, int64_t size) {
	Object* obj = globalController->allocStatic(clazz, size, false, true);
	return obj;
}

Object* ObjectManager::allocStaticOrNull(Class* clazz, int64_t size) {
	Object* obj = globalController->allocStatic(clazz, size, false, false);
	return obj;
}

Object* ObjectManager::allocConst(Class* clazz, int64_t size) {
	Object* obj = globalController->allocStatic(clazz, size, true, true);
	return obj;
}

Object* ObjectManager::allocConstOrNull(Class* clazz, int64_t size) {
	Object* obj = globalController->allocStatic(clazz, size, true, false);
	return obj;
}

// make sure bytes has zero tail
inline int64_t calcBytesArraySize(Class* arrayClazz, int64_t length) {
	return arrayClazz->size + length + 1;
}

inline int64_t calcArraySize(Class* arrayClazz, int64_t length) {
	//if (arrayClazz == $bytes::class$) {
	if (arrayClazz->arrayIndexScaleShift == 0) {
		return calcBytesArraySize(arrayClazz, length);
	}
	return arrayClazz->size + (length << arrayClazz->arrayIndexScaleShift);
}

#define USE_INLINE_STRING

String* ObjectManagerInternal::allocString(int8_t* bytes, int64_t length, int8_t coder) {
#ifdef USE_INLINE_STRING
	int64_t arraySize = calcAlignedSize(calcBytesArraySize(ByteArray::class$, length));
	int64_t stringSize = sizeof(String);
	int64_t stringBlockPayloadSize = sizeof(ObjectHead) + stringSize;
	int64_t stringBlockSize = MemoryBlock::calcBlockSize(stringBlockPayloadSize);
	int64_t totalSize = arraySize + stringBlockSize;

	int8_t* buffer = (int8_t*)localController->allocInternal($bytes::class$, totalSize, true);
	$var($bytes, value, new (buffer) $bytes((int32_t)length));
	value->setRegion(0, (int32_t)length, bytes);

	MemoryBlock* stringBlock = (MemoryBlock*)(buffer + arraySize);
	stringBlock->initObject(stringBlockPayloadSize);

	ObjectHead* stringOH = stringBlock->payload<ObjectHead>();
	stringOH->clazz = String::class$;
	stringOH->setInline();
	stringOH->setUsed();
	$var(String, s, new (fromOh(stringOH)) String());
	s->coder$ = coder;
	$set(s, value$, value);
	return s;
#else
	int64_t arraySize = calcArraySize(ByteArray::class$, length);
	$var($bytes, value, new (localController->allocInternal($bytes::class$, arraySize, true)) $bytes((int32_t)length));
	int8_t* buffer = (int8_t*)localController->allocInternal(String::class$, sizeof(String), true);
	$var(String, s, new (buffer) String());
	s->coder$ = coder;
	value->setRegion(0, (int32_t)length, bytes);
	$set(s, value$, value);
	return s;
#endif
}

String* ObjectManagerInternal::concatLatinString(String* s1, String* s2) {
#ifdef USE_INLINE_STRING
	int32_t length = s1->value$->length + s2->value$->length;
	int64_t arraySize = calcAlignedSize(calcBytesArraySize(ByteArray::class$, length));
	int64_t stringSize = sizeof(String);
	int64_t stringBlockPayloadSize = sizeof(ObjectHead) + stringSize;
	int64_t stringBlockSize = MemoryBlock::calcBlockSize(stringBlockPayloadSize);
	int64_t totalSize = arraySize + stringBlockSize;

	int8_t* buffer = (int8_t*)localController->allocInternal($bytes::class$, totalSize, true);
	$var($bytes, value, new (buffer) $bytes(length));
	value->setArray(0, s1->value$);
	value->setArray(s1->value$->length, s2->value$);

	MemoryBlock* stringBlock = (MemoryBlock*)(buffer + arraySize);
	stringBlock->initObject(stringBlockPayloadSize);

	ObjectHead* stringOH = stringBlock->payload<ObjectHead>();
	stringOH->clazz = String::class$;
	stringOH->setInline();
	//stringOH->setStatic();
	//stringOH->setConst();
	stringOH->setUsed();
	$var(String, s, new (fromOh(stringOH)) String());
	s->coder$ = String::LATIN1;
	$set(s, value$, value);
	return s;
#else
	int32_t length = s1->value$->length + s2->value$->length;
	int64_t arraySize = calcBytesArraySize(ByteArray::class$, length);
	$var($bytes, value, new (localController->allocInternal($bytes::class$, arraySize, true)) $bytes(length));
	int8_t* buffer = (int8_t*)localController->allocInternal(String::class$, sizeof(String), true);
	$var(String, s, new (buffer) String());
	s->coder$ = String::LATIN1;
	value->setArray(0, s1->value$);
	value->setArray(s1->value$->length, s2->value$);
	$set(s, value$, value);
	return s;
#endif
}

String* ObjectManagerInternal::allocConstString(int8_t* bytes, int64_t length, int8_t coder) {
	int64_t stringSize = calcAlignedSize(sizeof(String));
	int64_t arraySize = calcBytesArraySize(ByteArray::class$, length);
	int64_t arrayBlockPayloadSize = sizeof(ObjectHead) + arraySize;
	int64_t arrayBlockSize = MemoryBlock::calcBlockSize(arrayBlockPayloadSize);
	int64_t totalSize = stringSize + arrayBlockSize;

	int8_t* buffer = (int8_t*)globalController->allocStatic(String::class$, totalSize, true, true);
	String* s = new (buffer) String();
	s->coder$ = coder;
	MemoryBlock* arrayBlock = (MemoryBlock*)(buffer + stringSize);
	arrayBlock->setAllocater(nullptr);
	arrayBlock->initObject(arrayBlockPayloadSize);

	ObjectHead* valueOH = arrayBlock->payload<ObjectHead>();
	valueOH->clazz = $bytes::class$;
	valueOH->setInline();
	valueOH->setStatic();
	valueOH->setConst();
	valueOH->setUsed();
	$bytes* value = new (fromOh(valueOH)) $bytes((int32_t)length);
	value->setRegion(0, (int32_t)length, bytes);
	$set(s, value$, value);
	return s;
}

Object* ObjectManager::allocStaticArray(Class* clazz, int32_t length) {
	$nc(clazz);
	if (length < 0) {
		$throwNew(NegativeArraySizeException);
	}
	if (!clazz->isArray()) {
		$throwNew(IllegalArgumentException);
	}
	int64_t size = calcArraySize(clazz, length);
	Object0* obj0 = globalController->allocStatic(clazz, size, false, true);
	return obj0;
}

Object* ObjectManager::allocStaticArrayOrNull(Class* clazz, int32_t length) {
	$nc(clazz);
	if (length < 0) {
		$throwNew(NegativeArraySizeException);
	}
	if (!clazz->isArray()) {
		$throwNew(IllegalArgumentException);
	}
	int64_t size = calcArraySize(clazz, length);
	Object0* obj0 = globalController->allocStatic(clazz, size, false, false);
	return obj0;
}

Object* ObjectManager::allocConstArray(Class* clazz, int32_t length) {
	$nc(clazz);
	if (length < 0) {
		$throwNew(NegativeArraySizeException);
	}
	if (!clazz->isArray()) {
		$throwNew(IllegalArgumentException);
	}
	int64_t size = calcArraySize(clazz, length);
	Object0* obj0 = globalController->allocStatic(clazz, size, true, true);
	return obj0;
}

Object* ObjectManager::allocConstArrayOrNull(Class* clazz, int32_t length) {
	$nc(clazz);
	if (length < 0) {
		$throwNew(NegativeArraySizeException);
	}
	if (!clazz->isArray()) {
		$throwNew(IllegalArgumentException);
	}
	int64_t size = calcArraySize(clazz, length);
	Object0* obj0 = globalController->allocStatic(clazz, size, true, false);
	return obj0;
}

Object* ObjectManager::alloc(Class* clazz, int64_t size) {
#ifdef OBJECT_DEBUG
	$nullcheck(clazz);
#endif
	return localController->allocInternal(clazz, size, true);
}

Object* ObjectManager::allocOrNull(Class* clazz, int64_t size) {
#ifdef OBJECT_DEBUG
	$nullcheck(clazz);
#endif
	return localController->allocInternal(clazz, size, false);
}

void* ObjectManager::allocRaw(int64_t size) {
	if (size == 0) {
		size = 1;
	}
	void* raw = nullptr;
	raw = memoryManager.allocRawOrNull(size);
	if (raw == nullptr) {
		globalFullGc();
		raw = memoryManager.allocRawOrNull(size);
		if (raw == nullptr) {
			log_warning("allocRaw OutOfMemoryError size:%" PRId64 "\n", size);
			$throwNew(OutOfMemoryError);
		}
	}
	return raw;
}

void* ObjectManager::allocRawOrNull(int64_t size) {
	if (size == 0) {
		size = 1;
	}
	void* raw = nullptr;
	raw = memoryManager.allocRawOrNull(size);
	//if (raw == nullptr) {
	//	for (int i = 0; i < 3; i++) {
	//		globalFullGc();
	//		raw = memoryManager.allocRawOrNull(size);
	//		if (raw != nullptr) {
	//			break;
	//		}
	//	}
	//}
	if (raw == nullptr) {
		globalFullGc();
		raw = memoryManager.allocRawOrNull(size);
	}
	return raw;
}

void* ObjectManager::allocRawOrExit(int64_t size) {
	if (size == 0) {
		size = 1;
	}
	void* raw = nullptr;
	raw = allocRawOrNull(size);
	if (raw == nullptr)  {
		globalFullGc();
		raw = memoryManager.allocRawOrExit(size);
	}
	return raw;
}

void ObjectManager::freeRaw(void* raw) {
	if (raw != nullptr) {
		memoryManager.freeRaw(raw);
	}
}

void* ObjectManager::allocRawStatic(int64_t size) {
	if (size == 0) {
		size = 1;
	}
	void* raw = memoryManager.allocRawStaticOrNull(size);
	if (raw == nullptr) {
		ObjectManagerInternal::gc();
		raw = memoryManager.allocRawStaticOrNull(size);
		if (raw == nullptr) {
			log_warning("allocRawStatic OutOfMemoryError size:%" PRId64 "\n", size);
			$throwNew(OutOfMemoryError);
		}
	}
	return raw;
}

void* ObjectManager::allocRawStaticOrNull(int64_t size) {
	if (size == 0) {
		size = 1;
	}
	void* raw = memoryManager.allocRawStaticOrNull(size);
	if (raw == nullptr) {
		for (int i = 0; i < 3; i++) {
			ObjectManagerInternal::gc();
			raw = memoryManager.allocRawStaticOrNull(size);
			if (raw != nullptr) {
				break;
			}
		}
	}
	if (raw == nullptr) {
		ObjectManagerInternal::gc();
		raw = memoryManager.allocRawStaticOrNull(size);
	}
	return raw;
}

void* ObjectManager::allocRawStaticOrExit(int64_t size) {
	if (size == 0) {
		size = 1;
	}
	void* raw = allocRawStaticOrNull(size);
	if (raw == nullptr) {
		ObjectManagerInternal::gc();
		raw = memoryManager.allocRawStaticOrExit(size);
	}
	return raw;
}

int64_t ObjectManager::sizeOfRaw(const void* raw) {
	if (raw != nullptr) {
		MemoryBlock* block = MemoryBlock::fromPayload(raw);
		return block->getPayloadSize();
	}
	return -1;
}

void ObjectManager::memsetRaw(void* raw, int value) {
	$nc(raw);
	int64_t size = sizeOfRaw(raw);
	::memset(raw, value, size);
}

inline Object0* allocArrayBuffer(Class* arrayClazz, int32_t length, bool throwIfOOM) {
	if (length < 0) {
		$throwNew(NegativeArraySizeException);
	}
	int64_t size = calcArraySize(arrayClazz, length);
	return localController->allocInternal(arrayClazz, size, throwIfOOM);
}

$Array<int8_t>* ObjectManager::newByteArray(int32_t length) {
	Object* obj = allocArrayBuffer(ByteArray::class$, length, true);
	return ($Array<int8_t>*)new(obj) ByteArray(length);
}

$Array<int16_t>* ObjectManager::newShortArray(int32_t length) {
	Object* obj = allocArrayBuffer(ShortArray::class$, length, true);
	return ($Array<int16_t>*)new(obj) ShortArray(length);
}

$Array<int32_t>* ObjectManager::newIntArray(int32_t length) {
	Object* obj = allocArrayBuffer(IntArray::class$, length, true);
	return ($Array<int32_t>*)new(obj) IntArray(length);
}

$Array<int64_t>* ObjectManager::newLongArray(int32_t length) {
	Object* obj = allocArrayBuffer(LongArray::class$, length, true);
	return ($Array<int64_t>*)new(obj) LongArray(length);
}

$Array<float>* ObjectManager::newFloatArray(int32_t length) {
	Object* obj = allocArrayBuffer(FloatArray::class$, length, true);
	return ($Array<float>*)new(obj) FloatArray(length);
}

$Array<double>* ObjectManager::newDoubleArray(int32_t length) {
	Object* obj = allocArrayBuffer(DoubleArray::class$, length, true);
	return ($Array<double>*)new(obj) DoubleArray(length);
}

$Array<bool>* ObjectManager::newBooleanArray(int32_t length) {
	Object* obj = allocArrayBuffer(BooleanArray::class$, length, true);
	return ($Array<bool>*)new(obj) BooleanArray(length);
}

$Array<char16_t>* ObjectManager::newCharArray(int32_t length) {
	Object* obj = allocArrayBuffer(CharArray::class$, length, true);
	return ($Array<char16_t>*)new(obj) CharArray(length);
}

$Array<int8_t>* ObjectManager::newByteArray(const std::initializer_list<int8_t>& elements) {
	$var($Array<int8_t>, array, newByteArray((int32_t)elements.size()));
	array->setArray(0, elements);
	return array;
}

$Array<int16_t>* ObjectManager::newShortArray(const std::initializer_list<int16_t>& elements) {
	$var($Array<int16_t>, array, newShortArray((int32_t)elements.size()));
	array->setArray(0, elements);
	return array;
}

$Array<int32_t>* ObjectManager::newIntArray(const std::initializer_list<int32_t>& elements) {
	$var($Array<int32_t>, array, newIntArray((int32_t)elements.size()));
	array->setArray(0, elements);
	return array;
}

$Array<int64_t>* ObjectManager::newLongArray(const std::initializer_list<int64_t>& elements) {
	$var($Array<int64_t>, array, newLongArray((int32_t)elements.size()));
	array->setArray(0, elements);
	return array;
}

$Array<float>* ObjectManager::newFloatArray(const std::initializer_list<float>& elements) {
	$var($Array<float>, array, newFloatArray((int32_t)elements.size()));
	array->setArray(0, elements);
	return array;
}

$Array<double>* ObjectManager::newDoubleArray(const std::initializer_list<double>& elements) {
	$var($Array<double>, array, newDoubleArray((int32_t)elements.size()));
	array->setArray(0, elements);
	return array;
}

$Array<bool>* ObjectManager::newBooleanArray(const std::initializer_list<bool>& elements) {
	$var($Array<bool>, array, newBooleanArray((int32_t)elements.size()));
	array->setArray(0, elements);
	return array;
}

$Array<char16_t>* ObjectManager::newCharArray(const std::initializer_list<char16_t>& elements) {
	$var($Array<char16_t>, array, newCharArray((int32_t)elements.size()));
	array->setArray(0, elements);
	return array;
}

$ObjectArray* ObjectManager::newObjectArray(int32_t length) {
	Object* obj = allocArrayBuffer(ObjectArray::class$, length, true);
	return new(obj) ObjectArray(length);
}

$ObjectArray* ObjectManager::newObjectArray(const ::std::initializer_list<Object$*>& elements) {
	int32_t length = (int32_t)elements.size();
	Object* obj = allocArrayBuffer(ObjectArray::class$, length, true);
	$var(ObjectArray, array, new(obj) ObjectArray(length));
	array->setArray(0, elements);
	return array;
}

$ObjectArray* ObjectManager::newObjectArray(Class* componentType, int32_t length) {
	$nullcheck(componentType);
	Class* arrayClass = componentType->arrayType$;
	if (arrayClass == nullptr) {
		arrayClass = componentType->arrayType0();
	}
	Object* obj = allocArrayBuffer(arrayClass, length, true);
	return new(obj) ObjectArray(length);
}

$ObjectArray* ObjectManager::newObjectArray(Class* elementType, int32_t dim, int32_t length) {
	$nullcheck(elementType);
	Class* arrayClass = elementType;
	for (int32_t i = 0; i < dim; i++) {
		Class* clazz = arrayClass->arrayType$;
		if (clazz == nullptr) {
			clazz = arrayClass->arrayType0();
		}
		arrayClass = clazz;
	}
	Object* obj = allocArrayBuffer(arrayClass, length, true);
	return new(obj) ObjectArray(length);
}

$ObjectArray* ObjectManager::newObjectArray(Class* elementType, int32_t dim, const std::initializer_list<Object$*>& elements) {
	$var($ObjectArray, array, newObjectArray(elementType, dim, (int32_t)elements.size()));
	array->setArray(0, elements);
	return array;
}

BaseArray* ObjectManager::newArray(Class* componentType, int32_t length) {
	$nc(componentType);
	if (componentType->primitive) {
		if (componentType == Byte::TYPE) {
			return newByteArray(length);
		}
		if (componentType == Short::TYPE) {
			return newShortArray(length);
		}
		if (componentType == Integer::TYPE) {
			return newIntArray(length);
		}
		if (componentType == Long::TYPE) {
			return newLongArray(length);
		}
		if (componentType == Float::TYPE) {
			return newFloatArray(length);
		}
		if (componentType == Double::TYPE) {
			return newDoubleArray(length);
		}
		if (componentType == Boolean::TYPE) {
			return newBooleanArray(length);
		}
		if (componentType == Character::TYPE) {
			return newCharArray(length);
		}
		$throwNew(IllegalArgumentException);
	} else {
		return newObjectArray(componentType, length);
	}
}

BaseArray* ObjectManager::newArrayOrNull(Class* componentType, int32_t length) {
	$nc(componentType);
	if (componentType->primitive) {
		if (componentType == Byte::TYPE) {
			Object* obj = allocArrayBuffer(ByteArray::class$, length, false);
			if (obj == nullptr) {
				return nullptr;
			}
			return new(obj) ByteArray(length);
		}
		if (componentType == Short::TYPE) {
			Object* obj = allocArrayBuffer(ShortArray::class$, length, false);
			if (obj == nullptr) {
				return nullptr;
			}
			return new(obj) ShortArray(length);
		}
		if (componentType == Integer::TYPE) {
			Object* obj = allocArrayBuffer(IntArray::class$, length, false);
			if (obj == nullptr) {
				return nullptr;
			}
			return new(obj) IntArray(length);
		}
		if (componentType == Long::TYPE) {
			Object* obj = allocArrayBuffer(LongArray::class$, length, false);
			if (obj == nullptr) {
				return nullptr;
			}
			return new(obj) LongArray(length);
		}
		if (componentType == Float::TYPE) {
			Object* obj = allocArrayBuffer(FloatArray::class$, length, false);
			if (obj == nullptr) {
				return nullptr;
			}
			return new(obj) FloatArray(length);
		}
		if (componentType == Double::TYPE) {
			Object* obj = allocArrayBuffer(DoubleArray::class$, length, false);
			if (obj == nullptr) {
				return nullptr;
			}
			return new(obj) DoubleArray(length);
		}
		if (componentType == Boolean::TYPE) {
			Object* obj = allocArrayBuffer(BooleanArray::class$, length, false);
			if (obj == nullptr) {
				return nullptr;
			}
			return new(obj) BooleanArray(length);
		}
		if (componentType == Character::TYPE) {
			Object* obj = allocArrayBuffer(CharArray::class$, length, false);
			if (obj == nullptr) {
				return nullptr;
			}
			return new(obj) CharArray(length);
		}
		$throwNew(IllegalArgumentException);
	} else {
		Class* arrayClass = componentType->arrayType$;
		if (arrayClass == nullptr) {
			arrayClass = componentType->arrayType0();
		}
		Object* obj = allocArrayBuffer(arrayClass, length, false);
		if (obj == nullptr) {
			return nullptr;
		}
		return new(obj) ObjectArray(length);
	}
}

BaseArray* newMultiArray0(Class* componentType, $ints* dimensions, int32_t dimIndex) {
	int32_t length = dimensions->get(dimIndex);
	dimIndex++;
	if (dimIndex < dimensions->length) {
		$var(ObjectArray, oa, ObjectManager::newObjectArray(componentType, 1, length));
		for (int32_t i = 0; i < length; i++) {
			$var(BaseArray, subArray, newMultiArray0(componentType->getComponentType(), dimensions, dimIndex));
			oa->set(i, subArray);
		}
		return oa;
	} else {
		return ObjectManager::newArray(componentType, length);
	}
}

BaseArray* ObjectManager::newMultiArray(Class* elementType, $ints* dimensions) {
	$nullcheck(elementType);
	$nullcheck(dimensions);

	for (int32_t i = 0; i < dimensions->length; i++) {
		if (dimensions->get(i) < 0) {
			$throwNew(NegativeArraySizeException, $$str(dimensions->get(i)));
		}
	}

	int32_t elementTypeDim = elementType->arrayDimension();
	int32_t dim = dimensions->length;
	if (elementTypeDim > 0) {
		dim += elementTypeDim;
		elementType = elementType->elementType();
	}
	if (dim == 0 || dim > 255) { // 255: MAX_DIM
		$throwNew(IllegalArgumentException);
	}

	Class* componentType = elementType->arrayType(dim - 1);
	BaseArray* array = newMultiArray0(componentType, dimensions, 0);
	return array;
}

void* ObjectManager::alloc(const char* className, int64_t size, int32_t mark, bool isBaseOfObject) {
	Class* clazz = Machine::loadClass($cstr(className), size, mark, isBaseOfObject);
	return localController->allocInternal(clazz, size, true);
}

void* ObjectManager::allocOrNull(const char* className, int64_t size, int32_t mark, bool isBaseOfObject) {
	Class* clazz = Machine::loadClass($cstr(className), size, mark, isBaseOfObject);
	return localController->allocInternal(clazz, size, false);
}

Object0* ObjectManager::clone(Object0* obj) {
	ObjectHead* oh = toOh(obj);
	Class* clazz = oh->clazz;
	if (!clazz->isCloneable()) {
		$throwNew(CloneNotSupportedException, $ref(clazz->toString()));
	}
#ifdef OBJECT_DEBUG
	if (oh->isDebug() || !oh->isUsed()) {
		debugObjectHead("clone", oh);
	}
#endif
	int32_t ohSize = sizeof(ObjectHead);
	int64_t objectSize = getObjectSize(oh);
	Object0* objClone = localController->allocInternal(clazz, objectSize, true);
	ObjectHead* ohClone = toOh(objClone);
	memcpy((int8_t*)ohClone + ohSize, (int8_t*)oh + ohSize, objectSize);
	ohClone->clazz = clazz;
	ScanAddLocalRefCount4Clone scan;
	scan.scan(ohClone);
	return (Object0*)objClone;
}

$Array<Thread>* ObjectManagerInternal::getAllThreads() {
	return globalController->getAllThreads();
}

CoreObject* ObjectManagerInternal::getCurrentJavaThread() {
	if (localController != nullptr) {
		return localController->javaThread;
	}
	return nullptr;
}

//thread_local ObjectStack* currentObjectStack = nullptr;

void setCurrentObjectStack(ObjectStack* currentObjectStack) {
	ObjectStack::currentObjectStack() = currentObjectStack;
	//ObjectStackCache::currentObjectStack() = currentObjectStack;
}

extern "C" int jni_AttachCurrentThread(void* vm, void** penv, void* _args);

void ObjectManager::attachCurrentThread() {
	void* env = nullptr;
	jni_AttachCurrentThread(nullptr, &env, nullptr);
}

extern "C" int jni_DetachCurrentThread(void* vm);

void ObjectManager::detachCurrentThread() {
	jni_DetachCurrentThread(nullptr);
}

ObjectStack* ObjectManager::getCurrentObjectStack() {
	ObjectStack* currentObjectStack = ObjectStack::currentObjectStack();
	//if (currentObjectStack == nullptr) {
	//	//currentObjectStack = $allocRawOrNull<ObjectStack>();
	//	currentObjectStack = &localController->objectStack;
	//	ObjectStack::currentObjectStack() = currentObjectStack;
	//}
	return currentObjectStack;
}

void* ObjectManagerInternal::registerMainThread(Thread* thread, CoreObject* javaThread, void* stackBase, int64_t stackSize) {
	//currentObjectStack = &localController->objectStack;
	//localController->objectStack = ObjectManager::getCurrentObjectStack();
	//ObjectManager::getCurrentObjectStack();
	setCurrentObjectStack(&localController->objectStack);
	localController->init(thread);
	localController->mainThread = true;
	localController->javaThread = javaThread;
	localController->stackBase = stackBase;
	localController->stackSize = stackSize;
	//	onThreadStart(thread); // main thread
	globalController->registerLocalController(localController);
	//Machine::notifyThreadStart();
	return localController;
}

void ObjectManagerInternal::beforeThreadStart(Thread* thread) {
	// Integer::load$(nullptr, true);
	LocalController* lc = LocalController::create();
	lc->init(thread);
	globalController->registerLocalController(lc);
}

void* ObjectManagerInternal::onThreadStart(Thread* thread, CoreObject* javaThread, void* stackBase, int64_t stackSize) {
	// LocalController* lc = LocalController::create();
	// localController = lc;
	// setCurrentObjectStack(&localController->objectStack);

	// lc->init(thread);
	// globalController->registerLocalController(lc);

	localController = globalController->getLocalController(thread);
	if (localController == nullptr) {
		// TODO
		int i = 0;
		i++;
	} else {
		//currentObjectStack = &localController->objectStack;
		//ObjectManager::getCurrentObjectStack();
		setCurrentObjectStack(&localController->objectStack);
		//localController->objectStack = ObjectManager::getCurrentObjectStack();
		localController->javaThread = javaThread;
		localController->stackBase = stackBase;
		localController->stackSize = stackSize;
		//Machine::notifyThreadStart();
	}
	return localController;
}

void ObjectManagerInternal::onThreadEnd() {
	if (!localController->mainThread) {
		globalController->unregisterLocalController(localController);
		localController = nullptr;
	}
}

void ObjectManagerInternal::attachCurrentThread(CoreObject* javaThread) {
	LocalController* lc = LocalController::create();
	// lc->init(thread);
	globalController->registerLocalController(lc);
	localController = lc;
	setCurrentObjectStack(&localController->objectStack);
	//localController->objectStack = ObjectManager::getCurrentObjectStack();
	localController->javaThread = javaThread;
	// localController->stackBase = stackBase;
	// localController->stackSize = stackSize;
	//Machine::notifyThreadStart();
}

String* ObjectManager::plusAssignField(Object0* owner, int32_t fieldOffset, String* value) {
	$nullcheck(owner);
	Object$*& field = *(Object$**)(((int8_t*)owner) + fieldOffset);
	Object$* oldField = field;

#ifdef OBJECT_DEBUG
	if (isDebug(owner) || isDebug(field) || isDebug(value)) {
		log_info("plusAssignField offset:%" PRId32 " ", fieldOffset);
		debugObject("plusAssignField owner", owner);
		debugObject("plusAssignField field", field);
		debugObject("plusAssignField value", value);
	}
	//if (isDebug(owner) || isDebug(value)) {
	//	debugObject("plusAssignField owner", owner, "value", value);
	//}
	if (value != nullptr) {
		Object0* obj = toObject0(value);
		ObjectHead* oh = toOh(obj);
		oh->ownerOH = toOh(owner);
		oh->ownerOHFlags = oh->ownerOH->flags;
	}
#endif
	ObjectHead* ohOwner = toOh(owner);
	$var(String, res, String::concat(oldField, value));
	LocalController* lc = localController;
	while (true) {
		//lc->savePending4Gc(res);
		if (oldField != nullptr && lc->savePendingLocal) {
			lc->savePending4Gc(oldField);
		}
		if (cas(&field, oldField, (Object$*)res)) {
			break;
		}
		$assign(res, String::concat(oldField, value));
	}
	if (ohOwner->isGlobal()) {
		ObjectHead* resOH = toOh((Object0*)res);
		if (!resOH->isGlobal()) {
			lc->scanMarkGlobal(resOH);
		}
	}
#ifdef ENABLE_OBJECT_REF_COUNT
	LocalController::addRefCount(res);
#endif
	if (oldField != nullptr) {
#ifdef ENABLE_OBJECT_REF_COUNT
		LocalController::releaseRefCount(oldField);
#endif
	} else if (value != nullptr) {
		recordObjectOffset0(ohOwner->clazz, fieldOffset);
	}

	return res;
}

// offset record
template<typename FieldType, typename ValueType>
inline Object* assignFieldRecord0(Object0* owner, int32_t fieldOffset, ValueType value) {
	$nullcheck(owner);
	FieldType*& field = *(FieldType**)(((int8_t*)owner) + fieldOffset);
	FieldType* oldField = field;

#ifdef OBJECT_DEBUG
	if (isDebug(owner) || isDebug(field) || isDebug(field)) {
		log_info("assignField offset:%" PRId32 " \n", fieldOffset);
		debugObject("assignField owner:", owner);
		debugObject("assignField field:", field);
		debugObject("assignField value:", value);
	}
	//if (isDebug(owner) || isDebug(value)) {
	//	debugObject("assignField owner", owner, "value", value);
	//}
	if (value != nullptr) {
		Object0* obj = toObject0(value);
		ObjectHead* oh = toOh(obj);
		oh->ownerOH = toOh(owner);
		oh->ownerOHFlags = oh->ownerOH->flags;
	}
#endif
#ifdef ENABLE_OBJECT_REF_COUNT
	if (value != nullptr) {
		LocalController::addRefCount(value);
	}
#endif
	ObjectHead* ohOwner = toOh(owner);
	LocalController* lc = localController;
	if (ohOwner->isGlobal()) {
		if (value != nullptr) {
			Object0* value0 = toObject0(value);
			ObjectHead* valueOH = toOh(value0);
			if (!valueOH->isGlobal()) {
				lc->scanMarkGlobal(valueOH);
			}
			if (lc->savePendingLocal) {
				lc->savePending4Gc(value0);
			}
		}
		while (true) {
			if (oldField != nullptr && lc->savePendingLocal) {
				lc->savePending4Gc(oldField);
			}
			if (cas(&field, oldField, (FieldType*)value)) {
				break;
			}
		}
	} else {
		if (value != nullptr && lc->savePendingLocal) {
			lc->savePending4Gc(value);
		}
		if (oldField != nullptr && lc->savePendingLocal) {
			lc->savePending4Gc(oldField);
		}
		field = (FieldType*)value;
	}

	if (oldField != nullptr) {
#ifdef ENABLE_OBJECT_REF_COUNT
		LocalController::releaseRefCount(oldField);
#endif
	} else if (value != nullptr) {
		//int64_t fieldOffset = (intptr_t)&field - (intptr_t)owner;
		recordObjectOffset0(ohOwner->clazz, (int32_t)fieldOffset);
	}
	return (Object*)value;
}

Object* ObjectManager::assignField(Object0* owner, int32_t fieldOffset, Object$* value) {
	return assignFieldRecord0<Object$>(owner, fieldOffset, (Object$*)value);
}

Object* ObjectManager::assignField(Object0* owner, int32_t fieldOffset, Object0* value) {
	return assignFieldRecord0<Object$>(owner, fieldOffset, value);
}

Object* ObjectManager::assignField(Object0* owner, int32_t fieldOffset, ::std::nullptr_t) {
	return assignFieldRecord0<Object$>(owner, fieldOffset, nullptr);
}

Object* ObjectManager::assignField0(Object0* owner, int32_t fieldOffset, Object0* value) {
	return assignFieldRecord0<Object0>(owner, fieldOffset, value);
}

Object* ObjectManager::assignField0(Object0* owner, int32_t fieldOffset, ::std::nullptr_t) {
	return assignFieldRecord0<Object0>(owner, fieldOffset, nullptr);
}

inline bool canArrayCast(Class* srcType, Class* dstType) {
	if (srcType != dstType && dstType != Object::class$) {
		for (int32_t i = 0; i < 255; i++) {
			if (dstType->componentType$ != nullptr) {
				if (srcType->componentType$ == nullptr) {
					return false;
				}
				dstType = dstType->componentType$;
				srcType = srcType->componentType$;
			} else {
				break;
			}
		}
		if (srcType != dstType && dstType != Object::class$ && srcType->calcCastOffset(dstType, nullptr) < 0) {
			return false;
		}
	}
	return true;
}

#define needCheckArrayStoreType(srcType, dstType) (srcType != dstType && dstType != Object::class$)

inline void checkArrayStoreType(Class* srcType, Class* dstType) {
	//if (!canArrayCast(srcType, dstType)) {
	//	$throwNew(ArrayStoreException);
	//}
	//if (srcType != dstType && dstType != Object::class$) {
		for (int32_t i = 0; i < 255; i++) {
			if (dstType->componentType$ != nullptr) {
				if (srcType->componentType$ == nullptr) {
					$throwNew(ArrayStoreException);
				}
				dstType = dstType->componentType$;
				srcType = srcType->componentType$;
			} else {
				break;
			}
		}
		if (srcType != dstType && dstType != Object::class$ && srcType->calcCastOffset(dstType, nullptr) < 0) {
			$throwNew(ArrayStoreException);
		}
	//}
}

template<typename Value>
inline Object0* assignArrayValue0(ObjectArray* owner, Object0*& field, Value value) {
	ObjectHead* ohOwer = toOh($of(owner));
#ifdef OBJECT_DEBUG
	if (isDebug(owner) || isDebug(field)) {
		log_info("assignArrayValue0 index=%" PRId64 , $fieldOffset(owner->begin(), &field) / sizeof(Object*));
		debugObject("assignArrayValue0 owner", owner);
		debugObject("assignArrayValue0 field", field);
		debugObject("assignArrayValue0 value", value);
	}
	if (value != nullptr) {
		Object0* value0 = toObject0(value);
		ObjectHead* oh = toOh(value0);
		oh->ownerOH = ohOwer;
		oh->ownerOHFlags = oh->ownerOH->flags;
	}
#endif
	bool dstGlobal = ohOwer->isGlobal();
	LocalController* lc = localController;
	Object0* value0 = nullptr;
	if (value != nullptr) {
		value0 = toObject0(value);
		ObjectHead* valueOH = toOh(value0);
		Class* componentType = ohOwer->clazz->componentType$;
		Class* srcType = valueOH->clazz;
		if (needCheckArrayStoreType(srcType, componentType)) {
			checkArrayStoreType(srcType, componentType);
		}
		if (dstGlobal) {
			if (!valueOH->isGlobal()) {
				lc->scanMarkGlobal(valueOH);
			}
		}
#ifdef ENABLE_OBJECT_REF_COUNT
		LocalController::addRefCount(value0);
#endif
		int32_t end = $fieldOffset(owner->begin(), &field) / sizeof(Object*) + 1;
		updateArrayEnd(owner, end, dstGlobal);
		if (lc->savePendingLocal) {
			lc->savePending4Gc(value0);
		}
	}

	Object0* oldField = field;
	if (dstGlobal) {
		while (true) {
			if (oldField != nullptr && lc->savePendingLocal) {
				lc->savePending4Gc(oldField);
			}
			if (cas(&field, oldField, value0)) {
				break;
			}
		}
	} else {
		if (oldField != nullptr && lc->savePendingLocal) {
			lc->savePending4Gc(oldField);
		}
		field = value0;
	}
#ifdef ENABLE_OBJECT_REF_COUNT
	if (oldField != nullptr) {
		LocalController::releaseRefCount(oldField);
	}
#endif
	return value0;
}

Object0* ObjectManager::assignArray(ObjectArray* owner, Object0*& field, Object$* value) {
	return assignArrayValue0(owner, field, value);
}

Object0* ObjectManager::assignArray(ObjectArray* owner, Object0*& field, Object0* value) {
	return assignArrayValue0(owner, field, value);
}

Object0* ObjectManager::assignArray(ObjectArray* owner, Object0*& field, ::std::nullptr_t) {
	return assignArrayValue0(owner, field, nullptr);
}

template<typename Value>
void fillArray0(ObjectArray* array, int32_t fromIndex, int32_t toIndex, Value value) {
	$nullcheck(array)->rangeCheck(fromIndex, toIndex);
	ObjectHead* ohOwer = toOh($of(array));
#ifdef OBJECT_DEBUG
	if (isDebug(array) || isDebug(value)) {
		log_info("fillArray0 fromIndex:%" PRId32 ",toIndex:%d" PRId32 " ", fromIndex, toIndex);
		debugObject("fillArray0 array", array);
		debugObject("fillArray0 value", value);
	}
	if (value != nullptr) {
		Object0* value0 = toObject0(value);
		ObjectHead* oh = toOh(value0);
		oh->ownerOH = ohOwer;
		oh->ownerOHFlags = oh->ownerOH->flags;
	}
#endif
	bool dstGlobal = ohOwer->isGlobal();
	LocalController* lc = localController;
	Object0* value0 = nullptr;
	if (value != nullptr) {
		value0 = toObject0(value);
		ObjectHead* valueOH = toOh(value0);
		Class* componentType = ohOwer->clazz->componentType$;
		Class* srcType = valueOH->clazz;
		if (needCheckArrayStoreType(srcType, componentType)) {
			checkArrayStoreType(srcType, componentType);
		}
		if (dstGlobal) {
			if (!valueOH->isGlobal()) {
				lc->scanMarkGlobal(valueOH);
			}
		}
#ifdef ENABLE_OBJECT_REF_COUNT
		LocalController::addRefCount(value0, toIndex - fromIndex);
#endif
		updateArrayEnd(array, toIndex, dstGlobal);
		if (lc->savePendingLocal) {
			lc->savePending4Gc(value0);
		}
	}

	Object0** begin = array->begin();
	if (dstGlobal) {
		for (int32_t i = fromIndex; i < toIndex; i++) {
			Object0*& obj = begin[i];
			Object0* oldObj = obj;
			while (true) {
				if (oldObj != nullptr && lc->savePendingLocal) {
					lc->savePending4Gc(oldObj);
				}
				if (cas(&obj, oldObj, value0)) {
					break;
				}
			}
#ifdef ENABLE_OBJECT_REF_COUNT
			if (oldObj != nullptr) {
				LocalController::releaseRefCount(oldObj);
			}
#endif
		}
	} else {
		for (int32_t i = fromIndex; i < toIndex; i++) {
			Object0*& obj = begin[i];
			Object0* oldObj = obj;
			if (oldObj != nullptr && lc->savePendingLocal) {
				lc->savePending4Gc(oldObj);
			}
			obj = value0;
#ifdef ENABLE_OBJECT_REF_COUNT
			if (oldObj != nullptr) {
				LocalController::releaseRefCount(oldObj);
			}
#endif
		}
	}
}

void ObjectManager::fillArray(ObjectArray* array, int32_t fromIndex, int32_t toIndex, Object$* value) {
	fillArray0(array, fromIndex, toIndex, value);
}

void ObjectManager::fillArray(ObjectArray* array, int32_t fromIndex, int32_t toIndex, Object0* value) {
	fillArray0(array, fromIndex, toIndex, value);
}

void ObjectManager::fillArray(ObjectArray* array, int32_t fromIndex, int32_t toIndex, std::nullptr_t) {
	fillArray0(array, fromIndex, toIndex, nullptr);
}

template<typename Var, typename Value>
inline Object* assignStatic0(Var*& var, Value value) {
#ifdef OBJECT_DEBUG
	if (isDebug(var) || isDebug(value)) {
		debugObject("assignStatic0 var", var);
		debugObject("assignStatic0 value", value);
	}
#endif
	LocalController* lc = localController;
	lc->scanMarkGlobal0(value);
	if (var == nullptr) {
		globalController->recordStaticPointer((Object**)&var);
	}
#ifdef ENABLE_OBJECT_REF_COUNT
	if (value != nullptr) {
		LocalController::addRefCount(value);
	}
#endif
	if (value != nullptr && lc->savePendingLocal) {
		lc->savePending4Gc(value);
	}
	Var* oldVar = var;
	while (true) {
		if (oldVar != nullptr && lc->savePendingLocal) {
			lc->savePending4Gc(oldVar);
		}
		if (cas(&var, oldVar, (Var*)value)) {
			break;
		}
	}
	if (oldVar != nullptr) {
#ifdef OBJECT_DEBUG
		if (isDebug(oldVar) || isDebug(value)) {
			debugObject("assignStatic0 oldVar", oldVar);
			debugObject("assignStatic0 value", value);
		}
#endif
#ifdef ENABLE_OBJECT_REF_COUNT
		LocalController::releaseRefCount(oldVar);
#endif
	}
	return value;
}

Object* ObjectManager::assignStatic(Object*& var, Object* value) {
	return assignStatic0(var, value);
}

Object* ObjectManager::assignStatic(Object*& var, Object0* value) {
	return assignStatic0(var, value);
}

Object* ObjectManager::assignStatic(Object0*& var, Object0* value) {
	return assignStatic0(var, value);
}

Object* ObjectManager::assignStatic(Object*& var, ::std::nullptr_t) {
	return assignStatic0(var, nullptr);
}

Object* ObjectManager::assignStatic(Object0*& var, ::std::nullptr_t) {
	return assignStatic0(var, nullptr);
}

// why not use array's check, for performance
template<typename T>
inline void check(T index, T length, T thisLength) {
	if (index < 0) {
		$throwNew(ArrayIndexOutOfBoundsException, index);
	}
	if (index + length > thisLength) {
		$throwNew(ArrayIndexOutOfBoundsException, index + length);
	}
}

ObjectArray* ObjectManager::copyOf(ObjectArray* original, int32_t newLength) {
	return copyOf(original, newLength, $nc($of(original))->getClass());
}

ObjectArray* ObjectManager::copyOf(ObjectArray* original, int32_t newLength, Class* newType) {
	Object* obj = allocArrayBuffer($nc(newType), newLength, true);
	$var($ObjectArray, copy, new(obj) ObjectArray(newLength));
	int32_t length = $min($nc(original)->length, newLength);
	ObjectManager::copyArray(copy, 0, original, 0, length);
	return copy;
}

ObjectArray* ObjectManager::copyOfRange(ObjectArray* original, int32_t from, int32_t to) {
	return copyOfRange(original, from, to, $nc($of(original))->getClass());
}

ObjectArray* ObjectManager::copyOfRange(ObjectArray* original, int32_t from, int32_t to, Class* newType) {
	int32_t newLength = to - from;
	if (newLength < 0) {
		$throwNew(IllegalArgumentException, $($String::valueOf({ $$str(from), $cstr(" > "), $$str(to) })));
	}
	Object* obj = allocArrayBuffer($nc(newType), newLength, true);
	$var($ObjectArray, copy, new(obj) ObjectArray(newLength));
	//$var($ObjectArray, copy,
	//	(newType == $ObjectArray::class$)
	//	? $new<$ObjectArray>(newLength)
	//	: $fcast<$ObjectArray>(newObjectArray($($nc(newType)->getComponentType()), newLength))
	//);
	int32_t length = $min($nc(original)->length - from, newLength);
	copy->setArray(0, original, from, length);
	return copy;
}

void ObjectManager::copyArray(ObjectArray* dstArray, int32_t dstPos, const ObjectArray* srcArray, int32_t srcPos, int32_t length) {
#ifdef OBJECT_DEBUG
	if (isDebug(dstArray) || isDebug(srcArray)) {
		log_info("copyArray dstPos:%" PRId32 ",srcPos:%d" PRId32 ",length:%" PRId32 " ", dstPos, srcPos, length);
		debugObject("copyArray dstArray", dstArray);
		debugObject("copyArray srcArray", srcArray);
	}
#endif

	if (dstArray == srcArray) {
		copyArray(dstArray, dstPos, srcPos, length);
		return;
	}

	$nc(dstArray);
	check(dstPos, length, dstArray->length);
	$nc(srcArray);
	check(srcPos, length, srcArray->length);

	ObjectHead* dstArrayOH = toOh((Object0*)dstArray);
	bool dstGlobal = dstArrayOH->isGlobal();
	Object0** dst = dstArray->begin() + dstPos;
	Object0** src = srcArray->begin() + srcPos;

	ObjectHead* srcArrayOH = toOh((Object0*)srcArray);

	Class* componentTypeSrc = srcArrayOH->clazz->componentType$;
	Class* componentTypeDst = dstArrayOH->clazz->componentType$;
	bool needCheckArrayStoreType = !canArrayCast(componentTypeSrc, componentTypeDst);
	//if (componentTypeSrc != componentTypeDst && componentTypeDst != Object::class$) {
	//	needCheckArrayStoreType = true;
	//}

	bool needScanMarkGlobal = dstGlobal && !srcArrayOH->isGlobal();
	LocalController* lc = localController;
	for (int32_t i = 0; i < length; i++) {
		Object0* s = src[i];
		if (s != nullptr) {
#ifdef ENABLE_OBJECT_REF_COUNT
			LocalController::addRefCount(s);
#endif
			ObjectHead* ohS = toOh(s);
			if (needCheckArrayStoreType) {
				Class* srcType = ohS->clazz;
				if (needCheckArrayStoreType(srcType, componentTypeDst)) {
					checkArrayStoreType(srcType, componentTypeDst);
				}
			}
			if (needScanMarkGlobal) {
				if (!ohS->isGlobal()) {
					lc->scanMarkGlobal(ohS);
				}
			}
		}
		Object0* d = dst[i];
		if (dstGlobal) {
			while (true) {
				if (d != nullptr && lc->savePendingLocal) {
					lc->savePending4Gc(d);
				}
				if (cas(&dst[i], d, s)) {
					break;
				}
			}
		} else {
			if (d != nullptr && lc->savePendingLocal) {
				lc->savePending4Gc(d);
			}
			dst[i] = s;
		}
#ifdef ENABLE_OBJECT_REF_COUNT
		if (d != nullptr) {
			LocalController::releaseRefCount(d);
		}
#endif
	}

	int32_t end = dstPos + length;
	updateArrayEnd(dstArray, end, dstGlobal);
}

inline void copyArray0(Object0** src, Object0** dst, int32_t pos, bool global, LocalController* lc) {
	Object0* s = src[pos];
#ifdef ENABLE_OBJECT_REF_COUNT
	if (s != nullptr) {
		LocalController::addRefCount(s);
	}
#endif
	Object0* d = dst[pos];
	if (global) {
		while (true) {
			if (d != nullptr && lc->savePendingLocal) {
				lc->savePending4Gc(d);
			}
			if (cas(&dst[pos], d, s)) {
				break;
			}
		}
	} else {
		if (d != nullptr && lc->savePendingLocal) {
			lc->savePending4Gc(d);
		}
		dst[pos] = s;
	}
#ifdef ENABLE_OBJECT_REF_COUNT
	if (d != nullptr) {
		LocalController::releaseRefCount(d);
	}
#endif
}

void ObjectManager::copyArray(ObjectArray* array, int32_t dstPos, int32_t srcPos, int32_t length) {
#ifdef OBJECT_DEBUG
	if (isDebug(array)) {
		debugObject("copyArray array", array);
	}
#endif

	if (dstPos == srcPos) {
		return;
	}
	$nc(array);
	check(dstPos, length, array->length);
	check(srcPos, length, array->length);

	ObjectHead* arrayOh = toOh($of(array));
	Object0** begin = array->begin();
	Object0** dst = begin + dstPos;
	Object0** src = begin + srcPos;
	bool global = arrayOh->isGlobal();
	LocalController* lc = localController;
	if (dstPos > srcPos && dstPos < srcPos + length) {
		for (int32_t i = length - 1; i >= 0; i--) {
			copyArray0(src, dst, i, global, lc);
		}
	} else {
		for (int32_t i = 0; i < length; i++) {
			copyArray0(src, dst, i, global, lc);
		}
	}

	int32_t end = dstPos + length;
	updateArrayEnd(array, end, global);
}

void ObjectManager::setObjectArrayClass(ObjectArray* array, Class* clazz) {
	$nullcheck(array);
	$nullcheck(clazz);
	ObjectHead* oh = toOh((Object0*)array);
	oh->clazz = clazz;
}

#ifdef OBJECT_DEBUG
// bool ObjectManagerInternal::getThreadLocalDebug() {
// 	return localController->enableDebug;
// }

// void ObjectManagerInternal::setThreadLocalDebug(bool enable) {
// 	localController->enableDebug = enable;
// }

// void ObjectManagerInternal::setDebugMark(Object* obj, int16_t type, int16_t value) {
// 	if (obj != nullptr) {
// 		Object0* obj0 = toObject0(obj);
// 		ObjectHead* oh = toOh(obj0);
// 		oh->debugMarkType = type;
// 		oh->debugMarkValue = value;
// 	}
// }

// int16_t ObjectManagerInternal::getDebugMarkType(Object* obj) {
// 	if (obj != nullptr) {
// 		Object0* obj0 = toObject0(obj);
// 		ObjectHead* oh = toOh(obj0);
// 		return oh->debugMarkType;
// 	}
// 	return 0;
// }

// int16_t ObjectManagerInternal::getDebugMarkValue(Object* obj) {
// 	if (obj != nullptr) {
// 		Object0* obj0 = toObject0(obj);
// 		ObjectHead* oh = toOh(obj0);
// 		return oh->debugMarkValue;
// 	}
// 	return 0;
// }
#endif

int32_t GlobalController::makeScanCount(ObjectHead* oh) {
	ScanContextPendingManager pendingManager;
	ScanMarkLive4All scanner;
	scanner.liveCode = genNextGlobalLiveCode(liveCodeSequenceGlobal);;
	scanner.scanRefLevel = OBJECT_REF_TYPE_PHANTOM;
	scanner.pendingManager = &pendingManager;
	scanner.scan(oh);
	scanner.processPendingScan();
	return scanner.scanedCount;
}

int32_t GlobalController::makeRefScanCount(ObjectHead* oh) {
	ScanContextPendingManager pendingManager;
	ScanMarkReach4All scanner;
	scanner.liveCode = genNextGlobalLiveCode(liveCodeSequenceGlobal);
	scanner.scanRefLevel = OBJECT_REF_TYPE_PHANTOM;
	scanner.pendingManager = &pendingManager;
	scanner.scan(oh);
	scanner.processPendingScan();
	return scanner.scanedCount;
}

void GlobalController::deinit(bool force) {
	log_debug("GlobalController::deinit() enter\n");
	//int32_t refPendingListGlobalCount = refPendingListGlobal.size();

	if (localController == nullptr) {
		//return;
	}
	if (localController != nullptr) {
		localController->expungeStaleEntries4ThreadLocal();
		localController->exiting = true;
	}

	GcResult gcResult(GC_TYPE_FULL);
	for (int i = 0; i < 3; i++) {
		if (localController != nullptr) {
			fullGc0(OBJECT_REF_TYPE_FINAL, &gcResult);
		}
		opt();
		//printStat();
		//analayzeLeak();
	}

	printStat();

	// wail all nondaemon thread end
	int64_t lastPrintMs = System::currentTimeMillis();
	while (existsNonDaemonThread()) {
		if (System::currentTimeMillis() - lastPrintMs >= 2000) {
			lastPrintMs = System::currentTimeMillis();
			printThreads();
			if (localController != nullptr) {
				fullGc0(OBJECT_REF_TYPE_FINAL, &gcResult);
			}
		}
		if (force) {
			break;
		}
		{
			std::unique_lock lock(this->mutexGlobal);
			cvGlobal.wait_for(lock, std::chrono::nanoseconds(10));
		}
		opt();
	}
	if (globalControllerThread != nullptr) {
		globalControllerThread->stop();
	}

	log_debug("Shutdown::shutdown() before\n");
	Shutdown::shutdown();
	log_debug("Shutdown::shutdown() after\n");

	// for (int i = 0; i < 5; i++) {
	// 	fullGc0(localController, OBJECT_REF_TYPE_FINAL);
	// 	printStat();
	// 	refPendingListGlobalCount = refPendingListGlobal.size();
	// 	Thread::sleep(500);
	// }
//		while (!refPendingListGlobal.isEmpty()) {
//			Thread::sleep(1500);
//		}
	//staticListGlobal.clear();
//	staticPointerManager.init();
	// for (int i = 0; i < 2; i++) {
	// 	fullGc0(localController, OBJECT_REF_TYPE_FINAL);
	// 	//printStat();
	// 	//analayzeLeak();
	// }
	
#ifdef JCPP_ANALYZE_MEMORY
	analayzeGlobalObject();
	analayzeMemory();
	//printStat();
	//delete globalController;
	//globalController = nullptr;
	
	// free0(objectQueueLock);
	if (false) {

		// thread
		{
			LocalControllerAtomicListIterator it = LocalControllerAtomicListIterator(&localControllerList);
			while (it.has()) {
				LocalController* controller = it.get();
				it.next();
				Thread* thread = controller->thread;
				ObjectHead* oh = toOh($of(thread));
				int32_t scanedCount = makeScanCount(oh);
			}
		}

		ObjectListIterator it(&staticListGlobal);
		int32_t index = 0;
		while (it.has()) {
			ObjectHead* oh = it.get();
			it.next();
			int32_t scanedCount = makeScanCount(oh);
			if (oh->clazz == Class::class$) {
				Class* clazz = (Class*)fromOh(oh);
				if (clazz->classInfo != nullptr) {
					log_info("%d %s %d\n", index, clazz->classInfo->name, scanedCount);
				} else {
					log_info("%d 2 na %d\n", index, scanedCount);
				}
			} else if (oh->clazz->classInfo != nullptr) {
				log_info("%d %s %d\n", index, oh->clazz->classInfo->name, scanedCount);
			} else {
				log_info("%d na %d\n", index, scanedCount);
			}
			index++;
		}

		// static field
		{
			lock_guard lock(mutexStaticPointerManager);
			StaticPointerManager::Iterator staticPointerManagerIt(&staticPointerManager);
			while (staticPointerManagerIt.hasNext()) {
				Object** pointer = staticPointerManagerIt.next();
				if (pointer != nullptr) {
					Object* obj = *pointer;
					if (obj != nullptr) {
						Object0* obj0 = toObject0(obj);
						ObjectHead* oh = toOh(obj0);
						int32_t scanedCount = makeScanCount(oh);
					}
				}
			}
		}

		// refPending
		// don't care refPendingListLock, since come here is in full gc
		Reference* ref = refPendingList;
		while (ref != nullptr) {
			ObjectHead* oh = toOh($of(ref));
			int32_t scanedCount = makeScanCount(oh);
			ref = ref->discovered;
		}

		{
			ObjectListIterator it(&refListGlobal);
			while (it.has()) {
				ObjectHead* oh = it.get();
				int32_t scanedCount = makeRefScanCount(oh);
				it.next();
			}
		}

		{
			// can not move follow code before refListGlobal
			ObjectListIterator it(&hasFinalizeListGlobal);
			while (it.has()) {
				ObjectHead* oh = it.get();
				it.next();
				int32_t scanedCount = makeRefScanCount(oh);
			}
		}

		{
			// can not move follow code before refListGlobal
			ObjectListIterator it(&hasFinalizePendingListGlobal);
			while (it.has()) {
				ObjectHead* oh = it.get();
				it.next();
				int32_t scanedCount = makeRefScanCount(oh);
			}
		}
	}
	if (localController != nullptr) {
		localController->freeAllocs();
	}
	for (int i = 0; i < 1; i++) {
		fullGc0(OBJECT_REF_TYPE_FINAL, &gcResult);
		analayzeGlobalObject();
		analayzeMemory();
		printStat();
	}
#endif // JCPP_ANALYZE_MEMORY
	log_debug("GlobalController::deinit() leave\n");
}

bool ObjectManager::hasPendingException() {
	if (localController != nullptr) {
		return localController->pendingThrowable != nullptr;
	}
	return false;
}

void ObjectManager::setPendingException(Throwable* e) {
	if (localController != nullptr) {
		localController->pendingThrowable = e;
	}
#ifdef OBJECT_DEBUG
	if (isDebug(e)) {
		debugObject("setPendingException", e);
	}
#endif
}

Throwable* ObjectManager::getPendingException() {
#ifdef OBJECT_DEBUG
	if (isDebug(localController->pendingThrowable)) {
		debugObject("getPendingException", localController->pendingThrowable);
	}
#endif
	if (localController != nullptr) {
		return localController->pendingThrowable;
	}
	return nullptr;
}

Throwable* ObjectManager::catchPendingException() {
#ifdef OBJECT_DEBUG
	if (isDebug(localController->pendingThrowable)) {
		debugObject("catchPendingException", localController->pendingThrowable);
	}
#endif
	$var(Throwable, e, nullptr);
	if (localController != nullptr && localController->pendingThrowable != nullptr) {
		$assign(e, localController->pendingThrowable);
		localController->pendingThrowable = nullptr;
	}
	$nc(e);
	return e;
}

void* ObjectManager::getJNIEnv() {
	return Platform::getJNIEnv();
}

void ObjectManager::prepareNative() {
	//setPendingException(nullptr);
	localController->pushLocalFrame(16);
}

void ObjectManager::finishNative() {
	Throwable* ex = getPendingException();
	//Throwable* ex = catchPendingException();
	localController->popLocalFrame();
	if (ex != nullptr) {
		$var(Throwable, save, ex);
		setPendingException(nullptr);
		ex->throw$();
	}
}

void ObjectManager::pushLocalFrame(int32_t capacity) {
	localController->pushLocalFrame(capacity);
}

Object* ObjectManager::popLocalFrame(Object$* result) {
	if (result != nullptr) {
		$var(Object, save, (Object*)result);
		localController->popLocalFrame();
		localController->newLocalRef(result);
		return save;
	} else {
		localController->popLocalFrame();
		return nullptr;
	}
}

int32_t ObjectManager::ensureLocalCapacity(int32_t capacity) {
	return 0;
}

void ObjectManager::newLocalRef(Object$* obj) {
	localController->newLocalRef(obj);
}

void ObjectManager::newLocalRef(Object0* obj) {
	localController->newLocalRef(obj);
}

void ObjectManager::deleteLocalRef(Object$* obj) {
	localController->deleteLocalRef(obj);
}

template<typename T>
Object* newGlobalRef0(T* obj, bool weak) {
	if (obj == nullptr) {
		return nullptr;
	}
	Object0* obj0 = toObject0(obj);
	ObjectHead* oh = toOh(obj0);
	if (oh->isStatic()) {
		return (Object*)obj;
	}
	$var(Reference, ref, nullptr);
	if (weak) {
		$assign(ref, $new<WeakReference>(obj));
	} else {
		$assign(ref, $new<Reference>(obj));
	}
	obj0 = toObject0(ref);
	oh = toOh(obj0);
	oh->setGlobalRef();
	if (!weak) {
		oh->setRefType(OBJECT_REF_TYPE_GLOBAL);
	}
	localController->scanMarkGlobal(oh);
#ifdef ENABLE_OBJECT_REF_COUNT
	localController->addRefCount(obj0);
#endif
	return ref;
}

Object* ObjectManager::newGlobalRef(Object$* obj) {
	return newGlobalRef0(obj, false);
}

void ObjectManager::deleteGlobalRef(Object$* obj) {
	if (obj != nullptr) {
		Object0* obj0 = toObject0(obj);
		ObjectHead* oh = toOh(obj0);
		if (oh->isStatic()) {
			return;
		}
#ifdef OBJECT_DEBUG
	//	debug(obj);
		if (oh->isDebug() || !oh->isUsed()) {
			debugObjectHead("deleteGlobalRef", oh);
		}
#endif
		oh->clearGlobalRef();
#ifdef ENABLE_OBJECT_REF_COUNT
		localController->releaseRefCount(obj0);
#endif
	}
}

Object* ObjectManager::newWeakGlobalRef(Object$* obj) {
	return newGlobalRef0(obj, true);
}

void ObjectManager::deleteWeakGlobalRef(Object$* obj) {
	deleteGlobalRef(obj);
}

Object* ObjectManager::resolveRef(Object$* ref) {
	if (ref == nullptr) {
		return nullptr;
	}
	Object* obj = (Object*)ref;
	Object0* obj0 = toObject0(ref);
	ObjectHead* oh = toOh(obj0);
	if (oh->isGlobalRef()) {
		::java::lang::ref::Reference* reference = (::java::lang::ref::Reference*)obj0;
		return reference->get();
	}
	return obj;
}

Object* ObjectManager::newInstanceReflect(String* className, String* descriptor, ...) {
	Class* clazz = Class::forName(className);
	$var($Array<Constructor>, constructors, clazz->getConstructors());
	$var(Constructor, c, nullptr);
	for (int32_t i = 0; i < constructors->length; i++) {
		$var(Constructor, c2, constructors->get(i));
		if (Objects::equals(c2->getDescriptor(), descriptor)) {
			$assign(c, c2);
			break;
		}
	}
	if (c == nullptr) {
		// TODO throw
	}

	$var(Object, inst, clazz->allocateInstance());
	va_list args;
	va_start(args, descriptor);
	Platform::initInstanceJni(c, inst, args);
	va_end(args);
	return inst;
}

inline Method* getMethod(String* className, String* methodName, String* descriptor, bool isStatic) {
	Class* clazz = Class::forName(className);
	$var(Method, method, clazz->getMethodEx(methodName, descriptor));
	return clazz->getMethodEx(methodName, descriptor);
}

Object* ObjectManager::invokeReflect(String* className, String* methodName, String* descriptor, Object$* obj, ...) {
	$var(Method, method, getMethod(className, methodName, descriptor, false));
	va_list args;
	va_start(args, obj);
	Object* ret = Platform::invokeJni(false, method, obj, args);
	va_end(args);
	return ret;
}

Object* ObjectManager::invokeReflectStatic(String* className, String* methodName, String* descriptor, ...) {
	$var(Method, method, getMethod(className, methodName, descriptor, true));
	va_list args;
	va_start(args, descriptor);
	Object* ret = Platform::invokeJni(false, method, nullptr, args);
	va_end(args);
	return ret;
}

Field* getField(String* className, String* fieldName, bool isStatic) {
	Class* clazz = Class::forName(className);
	$var($Array<Field>, fields, clazz->getFields());
	$var(Field, field, nullptr);
	for (int32_t i = 0; i < fields->length; i++) {
		$var(Field, field2, fields->get(i));
		if (field2->isStatic() != isStatic) {
			continue;
		}
		if (field2->name->equals(fieldName)) {
			$assign(field, field2);
			break;
		}
	}
	if (field == nullptr) {
		// TODO throw
	}
	return field;
}

Object* ObjectManager::getReflect(String* className, String* fieldName, Object$* obj) {
	$var(Field, field, getField(className, fieldName, false));
	Object* ret = field->get(obj);
	return ret;
}

void ObjectManager::setReflect(String* className, String* fieldName, Object$* obj, Object$* value) {
	$var(Field, field, getField(className, fieldName, false));
	field->set(obj, value);
}

Object* ObjectManager::getReflectStatic(String* className, String* fieldName) {
	$var(Field, field, getField(className, fieldName, true));
	Object* ret = field->get(nullptr);
	return ret;
}

void ObjectManager::setReflectStatic(String* className, String* fieldName, Object$* value) {
	$var(Field, field, getField(className, fieldName, true));
	field->set(nullptr, value);
}

int32_t getVFTabSize(Class* clazz, Class* baseClazz) {
	int32_t offset = clazz->getBaseClassOffset(baseClazz);
	$var($Array<Method>, methods, nullptr);

	if (offset == 0) {
		$assign(methods, Platform::getVirtualMethods(clazz));
	} else {
		$assign(methods, Platform::getBaseClassVirtualMethods(clazz, baseClazz));
	}
	int32_t vftTableSize = methods->length;
#ifdef JCPP_USE_VIRTUAL_DESTRUCTOR // virtual ~Object()
	vftTableSize++;
#if defined(__clang__) || defined(__GNUC__)
	// the-deleting-destructor-occupy-a-second-vtable-slot
	vftTableSize++;
#endif
#endif
#ifdef JCPP_USE_VIRTUAL_TO_OBJECT0
	vftTableSize++;
#endif

	return vftTableSize;
}

bool ObjectManager::patchMemberClass(Object$* obj, PatchedMemberClassInfo*& patchedInfo, Class* memberClazz, int32_t memberFieldOffset) {
	void*** pVtabByteCode0 = (void***)((int8_t*)obj);
	if (patchedInfo != nullptr) {
		PatchedMemberClassInfo* it = patchedInfo;
		int32_t index = 0;
		while (it != nullptr) {
			pVtabByteCode0[index] = it->vfTable;
			it = it->next;
			index++;
		}
		return true;
	}
	$synchronized(memberClazz) {
		if (patchedInfo != nullptr) {
			PatchedMemberClassInfo* it = patchedInfo;
			int32_t index = 0;
			while (it != nullptr) {
				pVtabByteCode0[index] = it->vfTable;
				it = it->next;
				index++;
			}
			return true;
		}
		$var(Object, saved, obj);
		PatchedMemberClassInfo* first = nullptr;
		PatchedMemberClassInfo* last = nullptr;
		$var($ClassArray, classes, memberClazz->getPrimaryBaseClasses());
		for (int32_t i = 0; i < classes->length; i++) {
			Class* baseClazz = classes->get(i);
			int32_t vftTableSize = getVFTabSize(memberClazz, baseClazz);
			$var($longs, vfTabArray, $new<$longs>(vftTableSize));
			void** vfTabs = (void**)vfTabArray->begin();
			for (int32_t j = 0; j < vftTableSize; j++) {
				void* invokeAddress = pVtabByteCode0[0][j];
				vfTabs[j] = invokeAddress;
			}
			int32_t offset = memberFieldOffset + sizeof(void*) * i;
			int8_t* data = Platform::makeRTTIAndVFTable(obj, offset, vftTableSize, vfTabs, nullptr);
			void** vfTabs2 = Platform::rttiToVFTable(data);
			pVtabByteCode0[i] = vfTabs2;

			PatchedMemberClassInfo* it = $allocRawStatic<PatchedMemberClassInfo>();
			if (first == nullptr) {
				first = it;
			}
			it->vfTable = vfTabs2;
			it->next = nullptr;
			if (last == nullptr) {
				last = it;
				first = it;
			} else {
				last->next = it;
				last = it;
			}
		}
		patchedInfo = first;
	}
	return true;
}

void ObjectManager::debug(Object$* obj, int32_t mask, int32_t ttl) {
#ifdef OBJECT_DEBUG
	if (obj != nullptr) {
		Object0* obj0 = toObject0(obj);
		ObjectHead* oh = toOh(obj0);
		oh->mask |= mask;
		if (oh->ttl < ttl) {
			oh->ttl = ttl;
		}
		debugObjectHead("enable debug", oh);
	}
#endif
}

void ObjectManager::setDebugOpt(Object$* obj, int64_t opt) {
#ifdef OBJECT_DEBUG
	if (obj != nullptr) {
		Object0* obj0 = toObject0(obj);
		ObjectHead* oh = toOh(obj0);
		oh->opt = opt;
	}
#endif
}

int64_t ObjectManager::getDebugOpt(Object$* obj) {
#ifdef OBJECT_DEBUG
	if (obj != nullptr) {
		Object0* obj0 = toObject0(obj);
		ObjectHead* oh = toOh(obj0);
		return oh->opt;
	}
#endif
	return 0;
}

FILE* logFile = nullptr;
Logger::LogLevel Logger::logLevel = Logger::LOG_NONE;
bool Logger::logConsole = false;

const char* logLevelNames[] {
	"debug",
	"info",
	"warning",
	"error",
	""
};

void Logger::init(const char* logFilePath) {
	if (Logger::logLevel < Logger::LOG_NONE) {
		if (logFile == nullptr && logFilePath != nullptr) {
			logFile = fopen(logFilePath, "wb");
		}
	}
}

void Logger::deinit() {
	if (logFile != nullptr) {
		fclose(logFile);
		logFile = nullptr;
	}
}

void Logger::setLevel(LogLevel level) {
	Logger::logLevel = level;
}

void Logger::setLevel($String* level) {
	if (level != nullptr) {
		if (level->equalsIgnoreCase("debug")) {
			setLevel(Logger::LOG_DEBUG);
		} else if (level->equalsIgnoreCase("info")) {
			setLevel(Logger::LOG_INFO);
		} else if (level->equalsIgnoreCase("warning")) {
			setLevel(Logger::LOG_WARNING);
		} else if (level->equalsIgnoreCase("error")) {
			setLevel(Logger::LOG_ERROR);
		} else if (level->equalsIgnoreCase("none")) {
			setLevel(Logger::LOG_NONE);
		}
	}
}

void Logger::setConsole($String* flag) {
	if (flag != nullptr) {
		if (flag->equalsIgnoreCase("enable")) {
			Logger::logConsole = true;
		} else if (flag->equalsIgnoreCase("disable")) {
			Logger::logConsole = false;
		}
	}
}

void Logger::log(LogLevel logLevel, char const* const format, ...) {
	va_list args;
	va_start(args, format);
	char buffer[4096];
	buffer[0] = '\0';
	int size = 0;
	if (localController != nullptr && localController->threadName[0] != '\0') {
		size = snprintf(buffer, sizeof(buffer), "%" PRId64 " %s %s ", System::currentTimeMillis(), logLevelNames[logLevel], localController->threadName);
	} else {
		size = snprintf(buffer, sizeof(buffer), "%" PRId64 " %s ", System::currentTimeMillis(), logLevelNames[logLevel]);
	}
	size += vsnprintf(buffer + size, sizeof(buffer) - size, format, args);
	va_end(args);

	if (logFile != nullptr) {
		fwrite(buffer, 1, size, logFile);
		fflush(logFile);
	}
	if (logConsole) {
		printf("%s", buffer);
		fflush(stdout);
	}
}

	} // lang
} // java