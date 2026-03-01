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

#ifndef _java_lang_MemoryManager_h_
#define _java_lang_MemoryManager_h_

#include <java/lang/ObjectHead.h>
#include <java/lang/List.h>
#include <java/lang/SpinLock.h>
#include <java/lang/Logger.h>
#include <jcpp.h>
#include <string.h>
#include <mutex>

#define SLAB_COUNT 64
#define ALIGN_NUM 8

template<typename T>
inline T calcAlignedSize(T size) {
	return $align_up(size, ALIGN_NUM);
}

// Object memory layout
// 		MemoryBlock -> 16 bytes
//		ObjectHead -> 32 bytes
//		Object self

namespace java {
    namespace lang {

enum MemoryAllocaterType {
	MemoryAllocaterType_None = 0,
	MemoryAllocaterType_Store = 1,
	MemoryAllocaterType_Stored = 2,
	MemoryAllocaterType_Raw = 3,
	MemoryAllocaterType_CachedRaw = 4,
	MemoryAllocaterType_Object = 5,
	MemoryAllocaterType_Static = 6
};

class MemoryManager;
class MemoryAllocater {
public:
	virtual void free(void* m) = 0;
	virtual MemoryAllocaterType getType() = 0;
	virtual int32_t getId() = 0;
};

class MemoryBlock {
private:
	const static int32_t MEMORY_BLOCK_FLAGS_MASK = 0x7;
	const static int32_t MEMORY_BLOCK_TYPE_OBJECT = 1;
	const static int32_t MEMORY_BLOCK_TYPE_STORE = 2;
	const static int32_t MEMORY_BLOCK_PAYLOAD_INITED = 4;
	const static int32_t PAYLOAD_SIZE_SHIFT = 3;
#ifdef OBJECT_DEBUG
	int64_t MAGIC;
#endif
	MemoryAllocater* allocater;
	int64_t payloadSizeAndType; // size: payload size
public:
#ifdef OBJECT_DEBUG
	MemoryAllocaterType allocaterType;
	int32_t allocaterId;
#endif
	inline void init(int64_t payloadSize) {
#ifdef OBJECT_DEBUG
		MAGIC = 0x12345678;
#endif
		payloadSizeAndType = (payloadSize << PAYLOAD_SIZE_SHIFT);
	}
	inline void initObject(int64_t payloadSize) {
#ifdef OBJECT_DEBUG
		MAGIC = 0x12345678;
#endif
		payloadSizeAndType = (payloadSize << PAYLOAD_SIZE_SHIFT) | MEMORY_BLOCK_TYPE_OBJECT;
	}
	inline void initStoreObject(int64_t payloadSize) {
#ifdef OBJECT_DEBUG
		MAGIC = 0x12345678;
#endif
		payloadSizeAndType = (payloadSize << PAYLOAD_SIZE_SHIFT) | MEMORY_BLOCK_TYPE_OBJECT | MEMORY_BLOCK_TYPE_STORE;
	}
	inline void setObject() {
		payloadSizeAndType |= MEMORY_BLOCK_TYPE_OBJECT;
	}
	inline bool isObject() {
		return $hasFlag(payloadSizeAndType, MEMORY_BLOCK_TYPE_OBJECT);
	}
	inline bool isStoreObject() {
		return $hasFlag(payloadSizeAndType, MEMORY_BLOCK_TYPE_OBJECT | MEMORY_BLOCK_TYPE_STORE);
	}
	inline bool isStored() {
		return $hasFlag(payloadSizeAndType, MEMORY_BLOCK_TYPE_STORE);
	}
	inline bool isPayloadInited() {
		return $hasFlag(payloadSizeAndType, MEMORY_BLOCK_PAYLOAD_INITED);
	}
	inline void setPayloadInited() {
		payloadSizeAndType |= MEMORY_BLOCK_PAYLOAD_INITED;
	}
	inline void clearPayloadInited() {
		payloadSizeAndType &= ~MEMORY_BLOCK_PAYLOAD_INITED;
	}
	inline void setAllocater(MemoryAllocater* ma) {
		allocater = ma;
#ifdef OBJECT_DEBUG
		if (ma != nullptr) {
			allocaterType = ma->getType();
			allocaterId = ma->getId();
		} else {
			allocaterType = MemoryAllocaterType_None;
			allocaterId = -1;
		}
#endif
	}
	inline MemoryAllocater* getAllocater() {
		return allocater;
	}
	inline void reset() {
		allocater = nullptr;
		payloadSizeAndType = 0;
#ifdef OBJECT_DEBUG
		allocaterId = -2;
#endif
	}
	inline int64_t getPayloadSize() {
		return payloadSizeAndType >> PAYLOAD_SIZE_SHIFT;
	}
	inline int64_t getMemorySize() {
		return sizeof(MemoryBlock) + getPayloadSize();
	}
	template<typename T>
	inline T* payload() {
		return (T*)(((int8_t*)this) + sizeof(MemoryBlock));
	}
	inline void initPayload() {
		memset(payload<int8_t>(), 0, getPayloadSize());
		setPayloadInited();
	}
	inline static int64_t calcBlockSize(int64_t payloadSize) {
		return sizeof(MemoryBlock) + payloadSize;
	}
	inline static MemoryBlock* fromPayload(const void* payload) {
		return (MemoryBlock*)((int8_t*)payload - sizeof(MemoryBlock));
	}
};

class StoredMemoryBlock : public MemoryBlock {
public:
	StoredMemoryBlock* next;
	inline static StoredMemoryBlock* fromPayload(void* payload) {
		return (StoredMemoryBlock*)MemoryBlock::fromPayload(payload);
	}
};

//class StoredMemoryBanchBlock : public StoredMemoryBlock {
//public:
//	StoredMemoryBanchBlock* banchNext;
//	int32_t banchCount;
//	void initBanch() {
//		banchNext = nullptr;
//		banchCount = 1;
//	}
//	void add(StoredMemoryBlock* block) {
//		block->next = next;
//		next = block;
//		banchCount++;
//	}
//	static StoredMemoryBanchBlock* toBanch(StoredMemoryBlock* blocks) {
//		int32_t count = lengthOfList(blocks);
//		StoredMemoryBanchBlock* banch = (StoredMemoryBanchBlock*)blocks;
//		banch->banchNext = nullptr;
//		banch->banchCount = count;
//		return banch;
//	}
//};

class MemoryStat {
public:
	int32_t count = 0;
	int64_t size = 0;
	int64_t usedSize = 0;

	void add(int64_t size, int64_t usedSize) {
		count++;
		this->size += size;
		this->usedSize += usedSize;
	}

	void add(MemoryStat* stat) {
		count += stat->count;
		size += stat->size;
		usedSize += stat->usedSize;
	}

	void logOut(const char* info) {
		if (size > 0) {
			log_debug("%s count:%" PRId32 ", size:%" PRId64 "/%" PRId64 "(%.2lf%%)\n",
				info, count, usedSize, size, (double)usedSize / size * 100);
		}
	}
	void logOut(const char* info, int32_t index) {
		if (size > 0) {
			log_debug("%s %" PRId32 " count:%" PRId32 ", size:% " PRId64 "/%" PRId64 "(%.2lf%%)\n",
				info, index, count, usedSize, size, (double)usedSize / size * 100);
		}
	}
};

class AtomicMemoryStat {
public:
	std::atomic<int32_t> count = 0;
	std::atomic<int64_t> size = 0;
	std::atomic<int64_t> usedSize = 0;

	void add(int64_t size, int64_t usedSize) {
		count++;
		this->size += size;
		this->usedSize += usedSize;
	}

	void add(MemoryStat* stat) {
		count += stat->count;
		size += stat->size;
		usedSize += stat->usedSize;
	}

	void sub(int64_t size, int64_t usedSize) {
		count--;
		this->size -= size;
		this->usedSize -= usedSize;
	}

	void logOut(const char* info) {
		log_debug("%s count:%" PRId32 ", size:%" PRId64 "/%" PRId64 "(%.2lf%%)\n",
			info, count.load(), usedSize.load(), size.load(), (double)usedSize / size * 100);
	}
};

//#define MAX_BANCH_COUNT 50

template<typename T>
T calcBlockSizeFromPayloadSize(T payloadSize) {
	T blockSize = (T)sizeof(MemoryBlock) + payloadSize;
	if (blockSize < sizeof(StoredMemoryBlock)) {
		blockSize = sizeof(StoredMemoryBlock);
	}
	blockSize = calcAlignedSize(blockSize);
	return blockSize;
}
template<typename T>
T calcPayloadSizeFromBlockSize(T blockSize) {
	T payloadSize = blockSize - (T)sizeof(MemoryBlock);
	return payloadSize;
}
template<typename T>
T calcPayloadSizeFromObjectSize(T size) {
	T payloadSize = (T)sizeof(ObjectHead) + size;
	return payloadSize;
}

class MemoryStore : public MemoryAllocater {
public:
	MemoryStore(int8_t* buffer, int32_t bufferSize, int32_t payloadSize, bool banchMode) {
		this->buffer = buffer;
		this->bufferSize = bufferSize;
		this->payloadSize = payloadSize;
		//log_info("MemoryStore memset buffer:%p size:%d\n", buffer, bufferSize);

		//memset(buffer, 0, bufferSize);
		blockSize = calcBlockSizeFromPayloadSize(payloadSize);
		freeCount = blockCount = bufferSize / blockSize;
		this->blockedBufferSize = blockCount * blockSize;
		StoredMemoryBlock* blocksHead = nullptr;
		int32_t offset = 0;
		for (int32_t i = 0; i < blockCount; i++) {
			StoredMemoryBlock* block = (StoredMemoryBlock*)(buffer + offset);
			block->init(payloadSize);
			offset += blockSize;
			block->next = blocksHead;
			blocksHead = block;
		}
		if (blocksHead != nullptr) {
			blocks = blocksHead;
		}
	}

	ObjectHead* allocObject() {
		StoredMemoryBlock* block = allocBlock();
		if (block != nullptr) {
			block->setAllocater(this);
			block->initStoreObject(payloadSize);
			//if (!block->isPayloadInited()) {
				block->initPayload();
			//} else {
				//block->next = nullptr;
			//}
			return block->payload<ObjectHead>();
		} else {
			return nullptr;
		}
	}

	void* allocRaw() {
		StoredMemoryBlock* block = allocBlock();
		if (block != nullptr) {
			block->setAllocater(this);
			block->init(payloadSize);
			//if (!block->isPayloadInited()) {
			block->initPayload();
			//} else {
				//block->next = nullptr;
			//}
			return block->payload<void>();
		} else {
			return nullptr;
		}
	}

	virtual void free(void* m) override {
		StoredMemoryBlock* block = StoredMemoryBlock::fromPayload(m);
		block->clearPayloadInited();
		freeBlock(block);
	}

	virtual MemoryAllocaterType getType() override  {
		return MemoryAllocaterType_Store;
	}

	virtual int32_t getId() override {
		return 0;
	}

	bool canAlloc() {
		return freeCount > 0;
	}

	inline void backStore(MemoryBlock* block) {
		block->setAllocater(this);
	}

	void* getPayloadBegin(void* addr) {
		void* block = StoredMemoryBlock::fromPayload(addr);
		if (block >= buffer && block < (int8_t*)buffer + blockedBufferSize) {
			int64_t offset = (int8_t*)block - (int8_t*)buffer;
			int64_t remain = offset % blockSize;
			StoredMemoryBlock* block0 = (StoredMemoryBlock*)((int8_t*)block - remain);
			if (block0->isObject()) {
				void* payload = block0->payload<void>();
				if (payload <= addr) {
					return payload;
				}
			}
		}
		return nullptr;
	}

	StoredMemoryBlock* allocBlock() {
		StoredMemoryBlock* oldValue = blocks.load(std::memory_order_consume);
		//StoredMemoryBlock* oldValue = blocks;
		while (oldValue != nullptr) {
			StoredMemoryBlock* newValue = oldValue->next;
			if (blocks.compare_exchange_weak(oldValue, newValue, std::memory_order_release, std::memory_order_consume)) {
				oldValue->next = nullptr;
				freeCount--;
				return oldValue;
			}
		}
		return nullptr;
	}

	void freeBlock(StoredMemoryBlock* block) {
		block->reset();
		StoredMemoryBlock* oldValue = blocks.load(std::memory_order_relaxed);
		block->next = oldValue;
		while (!blocks.compare_exchange_weak(oldValue, block, std::memory_order_release, std::memory_order_relaxed)) {
			block->next = oldValue;
		}
		freeCount++;
	}

	void freeBlocks(StoredMemoryBlock* listFirst, StoredMemoryBlock* listLast, int32_t count) {
		StoredMemoryBlock* old = blocks.load(std::memory_order_relaxed);
		listLast->next = old;
		while (!blocks.compare_exchange_weak(old, listFirst, std::memory_order_release, std::memory_order_relaxed)) {
			listLast->next = old;
		}
		freeCount += count;
	}

	int32_t freeBlocks(StoredMemoryBlock* listHead) {
		if (listHead != nullptr) {
			ListScaner<StoredMemoryBlock> scaner;
			scaner.scan(listHead);
			int32_t count = scaner.length;
			freeBlocks(listHead, scaner.tail, count);
			//StoredMemoryBlock* old = blocks.load(std::memory_order_relaxed);
			//scaner.tail->next = old;
			//while (!blocks.compare_exchange_weak(old, listHead, std::memory_order_release, std::memory_order_relaxed)) {
			//	//old = banchBlocks;
			//	scaner.tail->next = old;
			//}
			//freeCount += count;
			return count;
		}
		return 0;
	}

	bool isEmpty() {
		return freeCount == 0;
	}

	bool canFreeThisStore() {
		return refCount == 0 && freeCount == blockCount;
	}

	int64_t getFreeSize() {
		return freeCount * blockSize;
	}

	void addRef() {
		refCount++;
	}

	void releaseRef() {
		refCount--;
	}

	int32_t getRefCount() {
		return refCount;
	}

	void stat(MemoryStat* stat) {
		MemoryBlock* block = MemoryBlock::fromPayload(this);
		int64_t size = block->getMemorySize();
		int64_t usedSize = size - getFreeSize();
		stat->add(size, usedSize);
	}

	std::atomic<StoredMemoryBlock*> blocks;
	std::atomic<int64_t> freeCount;
	std::atomic<MemoryStore*> next = nullptr;
	int8_t* buffer;
	int32_t blockedBufferSize;
	int32_t bufferSize;
	int32_t blockCount;
	int32_t payloadSize;
	int32_t blockSize;
	std::atomic<int32_t> refCount = 0; // ref by StoredMemoryAllocater
};

class StoredMemoryAllocater : public MemoryAllocater {
public:
	void init(MemoryStore* store) {
		store->addRef();
		this->store = store;
		allocedCount = 0;
		allocingList.clear();
		allocingListCount = 0;
		commitFreeCount = 0;
		freeList.clear();
		freeListCount = 0;
		freeingList.clear();
		freeingListTail = nullptr;
		freeingListCount = 0;
		payloadSize = store->payloadSize;;
		reusedCount++;
		next = nullptr;
	}

	void deinit() {
		if (store != nullptr) {
			flush();
			store->releaseRef();
			store = nullptr;
		}
	}

	inline StoredMemoryBlock* allocBlock() {
		if (allocingListCount > 0) {
			StoredMemoryBlock* block = allocingList.removeFirst();
			if (block != nullptr) {
				allocingListCount--;
				return block;
			}
			if (freeListCount > 0) {
				StoredMemoryBlock* listHead = freeList.exchange(nullptr);
				if (listHead != nullptr) {
					block = listHead;
					allocingList.exchange(listHead->next);
					freeListCount = 0;
					allocingListCount--;
					block->next = nullptr;
					return block;
				}
			}
			allocingListCount = 0;
		}
		StoredMemoryBlock* block = store->allocBlock();
		if (block != nullptr) {
			allocedCount++;
			block->setAllocater(this);
			return block;
		} else {
			return block;
		}
	}

	inline ObjectHead* allocObject() {
		StoredMemoryBlock* block = allocBlock();
		if (block != nullptr) {
			block->initStoreObject(payloadSize);
			//if (!block->isPayloadInited()) {
				block->initPayload();
			//} else {
			//	block->next = nullptr;
			//}
			return block->payload<ObjectHead>();
		} else {
			return nullptr;
		}
	}

	inline void* allocRaw() {
		StoredMemoryBlock* block = allocBlock();
		if (block != nullptr) {
			block->init(payloadSize);
			//if (!block->isPayloadInited()) {
				block->initPayload();
			//} else {
			//	block->next = nullptr;
			//}
			return block->payload<void>();
		} else {
			return nullptr;
		}
	}

	virtual void free(void* m) override {
		StoredMemoryBlock* block = StoredMemoryBlock::fromPayload(m);
		//block->clearPayloadInited();
//		store->freeBlock(block);
//		allocedCount--;
		if (freeingListTail == nullptr) {
			freeingListTail = block;
		}
		freeingList.prepend(block);
		freeingListCount++;
	}

	virtual MemoryAllocaterType getType() override {
		return MemoryAllocaterType_Stored;
	}

	virtual int32_t getId() override {
		return id;
	}

	void moveFreeingToFree() {
		StoredMemoryBlock* freeingListHead = freeingList.exchange(nullptr);
		if (freeingListHead != nullptr) {
			StoredMemoryBlock* cacheOldListHead = freeList.exchange(nullptr);
			StoredMemoryBlock* mergedListHead = nullptr;
			if (cacheOldListHead != nullptr) {
				if (freeingListCount <= freeListCount) {
					freeingListTail->next = cacheOldListHead;
					mergedListHead = freeingListHead;
				} else {
					ListScaner<StoredMemoryBlock> scaner;
					scaner.scan(cacheOldListHead);
					scaner.tail->next = freeingListHead;
					mergedListHead = scaner.head;
				}
			} else {
				mergedListHead = freeingListHead;
			}
			cacheOldListHead = freeList.exchange(mergedListHead);
			if (cacheOldListHead != nullptr) {
				freeList.prependList(cacheOldListHead);
			}
			freeingListTail = nullptr;
			freeListCount += freeingListCount;
			allocingListCount += freeingListCount;
			freeingListCount = 0;
		}
	}

	void moveFreeingToStore() {
		StoredMemoryBlock* freeingListHead = freeingList.exchange(nullptr);
		if (freeingListHead != nullptr) {
			store->freeBlocks(freeingListHead, freeingListTail, freeListCount);
			allocedCount -= freeListCount;
			freeingListTail = nullptr;
			freeingListCount = 0;
		}
	}

	void moveFreeToStore() {
		StoredMemoryBlock* freeListHead = freeList.exchange(nullptr);
		if (freeListHead != nullptr) {
			int32_t freedCount = store->freeBlocks(freeListHead);
			allocedCount -= freedCount;
			freeListCount = 0;
		}
	}

	void flush() {
		StoredMemoryBlock* listHead = allocingList.exchange(nullptr);
		int32_t freedCount = store->freeBlocks(listHead);
		if (freedCount > 0) {
			allocedCount -= freedCount;
		}
		allocingListCount = 0;
		listHead = freeList.exchange(nullptr);
		freeListCount = 0;
		freedCount = store->freeBlocks(listHead);
		if (freedCount > 0) {
			allocedCount -= freedCount;
		}
		listHead = freeingList.exchange(nullptr);
		freedCount = store->freeBlocks(listHead);
		if (freedCount > 0) {
			allocedCount -= freedCount;
		}
		freeingListCount = 0;
	}

	inline bool getAllocedCount() {
		return allocedCount;
	}

	//bool canFree() {
	//	//return allocedCount - freeingListCount == 0;
	//	return allocedCount == 0;
	//}

	bool canAlloc() {
		return store->canAlloc();
	}

	inline void backStore(MemoryBlock* block) {
		store->backStore(block);
		allocedCount--;
	}

	MemoryStore* store;
	std::atomic<int32_t> allocedCount;
	SList<StoredMemoryBlock> allocingList;
	int32_t allocingListCount;
	int32_t commitFreeCount;
	AtomicSList<StoredMemoryBlock> freeList;
	std::atomic<int32_t> freeListCount;
	SList<StoredMemoryBlock> freeingList;
	StoredMemoryBlock* freeingListTail;
	int32_t freeingListCount;
	int32_t payloadSize;
	int32_t reusedCount = 0;
	int32_t id;
	StoredMemoryAllocater* next;
};

class RawMemoryAllocater : public MemoryAllocater {
public:
	RawMemoryAllocater(MemoryManager* memoryManager) : memoryManager(memoryManager) {}
	virtual MemoryBlock* allocBlockOrNull(int64_t payloadSize, bool core);
	virtual void free(void* m) override;
	virtual MemoryAllocaterType getType() override {
		return MemoryAllocaterType_Raw;
	}
	virtual int32_t getId() override {
		return 0;
	}
	MemoryManager* memoryManager;
	AtomicMemoryStat stat;
};

class CachedRawMemoryAllocater : public MemoryAllocater {
public:
	CachedRawMemoryAllocater(MemoryManager* memoryManager, int64_t payloadSize) : memoryManager(memoryManager), payloadSize(payloadSize) {}
	void* allocRawOrNull();

	inline void free0(void* m) {
		StoredMemoryBlock* block = StoredMemoryBlock::fromPayload(m);
		addCache(block);
	}

	virtual void free(void* m) override {
		free0(m);
	}

	virtual MemoryAllocaterType getType() override {
		return MemoryAllocaterType_CachedRaw;
	}

	virtual int32_t getId() override {
		return 0;
	}

	StoredMemoryBlock* removeCache() {
		StoredMemoryBlock* oldValue = removeCacheBlocks.load(std::memory_order_consume);
		while (oldValue != nullptr) {
			StoredMemoryBlock* newValue = oldValue->next;
			if (removeCacheBlocks.compare_exchange_weak(oldValue, newValue, std::memory_order_release, std::memory_order_consume)) {
				oldValue->next = nullptr;
				cacheCount--;
				return oldValue;
			}
		}
		//StoredMemoryBlock* listHead = addCacheBlocks.exchange(nullptr);
		//if (listHead != nullptr) {
		//	oldValue = listHead;
		//	cacheCount--;
		//	listHead = listHead->next;
		//	{
		//		ListScaner<StoredMemoryBlock> scaner;
		//		scaner.scan(listHead);
		//		if (scaner.length > 0) {
		//			StoredMemoryBlock* oldValue2 = removeCacheBlocks.load(std::memory_order_relaxed);
		//			scaner.tail->next = oldValue2;
		//			while (!removeCacheBlocks.compare_exchange_weak(oldValue2, scaner.head, std::memory_order_release, std::memory_order_relaxed)) {
		//				scaner.tail->next = oldValue2;
		//			}
		//		}
		//	}
		//}
		return oldValue;
	}

	void addCache(StoredMemoryBlock* block) {
		//block->reset();
	//	if ((int64_t)block < 0xffff) {
	//		log_debug("addCache block:%p\n", block);
	//	}
		StoredMemoryBlock* oldValue = removeCacheBlocks.load(std::memory_order_relaxed);
	//	if (oldValue != nullptr && (int64_t)oldValue < 0xffff) {
	//		log_debug("addCache oldValue:%p\n", oldValue);
	//	}
		block->next = oldValue;
		while (!removeCacheBlocks.compare_exchange_weak(oldValue, block, std::memory_order_release, std::memory_order_relaxed)) {
			block->next = oldValue;
		}
	//	if (block->next != nullptr && (int64_t)block->next < 0xffff) {
	//		log_debug("addCache next:%p\n", block->next);
	//	}
		cacheCount++;
	}
	void opt(int32_t count);
	void clear();
	void setMinCacheCount(int32_t count) {
		minCacheCount = count;
	}
private:
	int64_t payloadSize;
	std::atomic<StoredMemoryBlock*> removeCacheBlocks;
	//std::atomic<StoredMemoryBlock*> addCacheBlocks;
	std::atomic<int32_t> cacheCount;
	int32_t minCacheCount;
	MemoryManager* memoryManager;
	AtomicMemoryStat stat;
};

class ObjectMemoryAllocater : public MemoryAllocater {
public:
	ObjectMemoryAllocater(MemoryManager* memoryManager) : memoryManager(memoryManager) {}
	virtual ObjectHead* allocObject(int64_t payloadSize);
	virtual void free(void* m) override;
	virtual MemoryAllocaterType getType() override {
		return MemoryAllocaterType_Object;
	}
	virtual int32_t getId() override {
		return 0;
	}
	MemoryManager* memoryManager;
	AtomicMemoryStat stat;
};

class StaticMemoryBuffer {
public:
	StaticMemoryBuffer(int8_t* buffer, int64_t bufferSize) : buffer(buffer), next(nullptr), bufferSize(bufferSize), used(0) {}
	MemoryBlock* alloc(int64_t payloadSize) {
		int64_t size = calcAlignedSize(MemoryBlock::calcBlockSize(payloadSize));

		int64_t prev = used.load(std::memory_order_relaxed);
		do {
			if (prev + size > bufferSize) {
				return nullptr;
			}
		} while (!used.compare_exchange_weak(prev, prev + size, std::memory_order_release, std::memory_order_relaxed));
		return (MemoryBlock*)(buffer + prev);
	}

	int64_t remain() {
		return bufferSize - used;
	}
	void stat(MemoryStat* stat) {
		stat->add(bufferSize, used);
	}
	int8_t* buffer;
	int64_t bufferSize;
	std::atomic<int64_t> used;
	StaticMemoryBuffer* next;
};

class StaticMemoryAllocater : public MemoryAllocater {
public:
	StaticMemoryAllocater(MemoryManager* memoryManager, int64_t maxBufferSize, int64_t maxAllocSize)
		: memoryManager(memoryManager), maxBufferSize(maxBufferSize), maxAllocSize(maxAllocSize) {}
	MemoryBlock* alloc(int64_t payloadSize);
	virtual void free(void* m) override;
	virtual MemoryAllocaterType getType() override {
		return MemoryAllocaterType_Static;
	}
	virtual int32_t getId() override {
		return 0;
	}
	void stat(MemoryStat* stat) {
		StaticMemoryBuffer* buffer = head;
		if (buffer != nullptr) {
			buffer->stat(stat);
		}
	}
	StaticMemoryBuffer* createBuffer();
	MemoryManager* memoryManager;
	int64_t maxBufferSize;
	int64_t maxAllocSize;
	std::atomic<StaticMemoryBuffer*> head;
};

template<typename T>
class MemoryIndex {
public:
	MemoryIndex(MemoryManager* manager) : manager(manager) {}
	virtual ~MemoryIndex();

	inline int32_t find4Add(T* item);
	inline int32_t find(T* item);
	void add(T* item);
	void remove(T* item);

	T** indexed = nullptr;
	int32_t count = 0;
	int32_t maxCount = 0;
	//SpinLock indexLock;
	std::mutex indexLock;
	MemoryManager* manager;
};

class MemoryStoreIndex : public MemoryIndex<MemoryStore> {
public:
	MemoryStoreIndex(MemoryManager* manager) : MemoryIndex<MemoryStore>(manager) {}
	MemoryStore* getByObjectAddr(void* addr);
};

class MemoryBlockIndex : public MemoryIndex<MemoryBlock> {
public:
	MemoryBlockIndex(MemoryManager* manager) : MemoryIndex<MemoryBlock>(manager) {}
	MemoryBlock* getByObjectAddr(void* addr);
};

using MemoryStoreList = SList<MemoryStore>;
using AtomicMemoryStoreList = AtomicSList<MemoryStore>;
using MemoryAllocaterList = SList<StoredMemoryAllocater>;
using AtomicMemoryAllocaterList = AtomicSList<StoredMemoryAllocater>;

class MemoryManager {
public:
	enum OPT_TYPE {
		OPT_NORMAL = 0,
		OPT_GC,
		OPT_FINAL_GC
	};
	MemoryManager();
	void init();
	int32_t getChunkSize(int32_t slabIndex);
	StoredMemoryAllocater* createAllocater(int32_t slabIndex);
	//StoredMemoryAllocater* createAllocater(int32_t payloadSize, int32_t count);
	MemoryStore* createStore(int32_t payloadSize, int32_t count) {
		return createStore0(payloadSize, count, false);
	}
	void freeAllocater(StoredMemoryAllocater* oa);
	CachedRawMemoryAllocater* createCachedRawMemoryAllocater(int64_t payloadSize);
	void freeCachedRawMemoryAllocater(CachedRawMemoryAllocater* allocater);
	inline int32_t getSlabIndex(int64_t size) {
		int32_t index = 0;
		//if (size >= slabSizes[SLAB_COUNT - (SLAB_COUNT / 4)]) {
		//	index = SLAB_COUNT - (SLAB_COUNT / 4);
		//} else if (size >= slabSizes[SLAB_COUNT / 2]) {
		//	index = SLAB_COUNT / 2;
		//} else if (size >= slabSizes[SLAB_COUNT / 4]) {
		//	index = SLAB_COUNT / 4;
		//}
		for (; index < SLAB_COUNT; index++) {
			if (slabSizes[index] >= size) {
				return index;
			}
		}
		return -1;
	}

	ObjectHead* allocObjectOrNull(int64_t payloadSize);
	void* allocRawOrNull(int64_t payloadSize);
	void* allocRawOrExit(int64_t payloadSize);

	void* allocRawStaticOrNull(int64_t payloadSize);
	void* allocRawStaticOrExit(int64_t payloadSize);
	ObjectHead* allocObjectStaticOrNull(int64_t payloadSize);

	ObjectHead* tryToObject(void* addr);

	void freeRaw(void* mem);
	inline void freeObjectLocal(ObjectHead* oh) {
		MemoryBlock* block = MemoryBlock::fromPayload(oh);
		MemoryAllocater* allocater = block->getAllocater();
		allocater->free(oh);
	}
	void freeObject(ObjectHead* oh);
	bool expand(void* mem, int32_t newSize);

	void opt(OPT_TYPE type);
	void opt0(OPT_TYPE type);

	int64_t getTotalCount() {
		return totalCount;
	}
	int64_t getTotalSize() {
		return totalSize;
	}
	int64_t getMaxMemorySize() {
		return maxMemorySize;
	}
	inline int64_t getMinMemorySize() {
		return minMemorySize;
	}
	inline int64_t getMinLocalGcMemorySize() {
		return minLocalGcMemorySize;
	}
	int64_t getFreeMemory();
	int64_t getTotalMemory();

	void setMaxMemorySize(int64_t size);
	void setMinMemorySize(int64_t size);
	void setMinLocalGcMemorySize();

	uint64_t getMaxPointer() {
		return maxPointer;
	}
	uint64_t getMinPointer() {
		return minPointer;
	}

	void printArgs();
private:
	StoredMemoryAllocater* getCreateAllocater0();
	void freeAllocater0(StoredMemoryAllocater* oa);
	MemoryBlock* allocSystemBlock(int64_t payloadSize, bool core);
	void freeSystemBlock(MemoryBlock* block);

	bool attachStore(int32_t slabIndex, StoredMemoryAllocater* allocater);
	MemoryStore* createStore0(int32_t payloadSize, int32_t count, bool banchMode);
	void freeStore0(MemoryStore* store);

	int32_t slabSizes[SLAB_COUNT];
	int32_t slabPayloadSizes[SLAB_COUNT];

	int64_t maxMemorySize = 0;
	int64_t minMemorySize = 0;
	int64_t minLocalGcMemorySize = 0;
	int64_t warningMemorySize = 0;
	//int64_t totalCount = 0; // only for debug now
	std::atomic<int64_t> totalCount = 0;
	std::atomic<int64_t> totalSize = 0;
	std::atomic<int64_t> storeCount = 0;
	std::atomic<int64_t> storeSize = 0;
	bool willOutOfMemory(int64_t size) {
		if (maxMemorySize > 0) {
			return totalSize + size > maxMemorySize;
		} else {
			return false;
		}
	}
	bool isMemoryWarning() {
		return totalSize > warningMemorySize;
	}
	void statAllocate(int64_t size) {
		totalCount++;
		totalSize += size;
	}
	void statFree(int64_t size) {
		totalCount--;
		totalSize -= size;
	}
	void statAllocateStore(int64_t size) {
		storeCount++;
		storeSize += size;
	}
	void statFreeStore(int64_t size) {
		storeCount--;
		storeSize -= size;
	}
	std::atomic<uint64_t> maxPointer = 0;
	std::atomic<uint64_t> minPointer = 0;
	void setMaxPointer(uint64_t pointer) {
		while (true) {
			uint64_t old = maxPointer;
			if (old < pointer) {
				maxPointer.compare_exchange_strong(old, pointer);
			} else {
				break;
			}
		}
	}

	void setMinPointer(uint64_t pointer) {
		while (true) {
			uint64_t old = minPointer;
			if (old > pointer) {
				minPointer.compare_exchange_strong(old, pointer);
			}
			else {
				break;
			}
		}
	}

	void* systemMalloc(int64_t size);
	void systemFree(void* ptr);

	RawMemoryAllocater rawMemoryAllocater;
	ObjectMemoryAllocater objectMemoryAllocater;
	StaticMemoryAllocater staticMemoryAllocater;

	MemoryStoreIndex memoryStoreIndex;
	MemoryBlockIndex memoryBlockIndex;

	std::mutex optLock;
	//SpinLock storesLock;
	std::mutex storesLock;
	int32_t optCount = 0;
	std::atomic<MemoryStore*> stores[SLAB_COUNT];
	AtomicMemoryStoreList storeLists[SLAB_COUNT];
	AtomicMemoryStoreList pendingStoreLists[SLAB_COUNT];
	//AtomicMemoryAllocaterList allocaters[SLAB_COUNT];
	AtomicMemoryAllocaterList pendingAllocaters;
	AtomicMemoryStoreList allocaterStores;
	AtomicMemoryAllocaterList allocaterCacheList;

	int64_t lastStatLogOutMs = 0;
	friend class ObjectMemoryAllocater;
	friend class RawMemoryAllocater;
	friend class CachedRawMemoryAllocater;
	friend class GlobalController;
};

// MemoryIndex
template<typename T>
MemoryIndex<T>::~MemoryIndex() {
	if (indexed != nullptr) {
		manager->freeRaw(indexed);
		indexed = nullptr;
	}
}

inline MemoryAllocater* getMemoryAllocater(void* oh) {
	MemoryBlock* block = MemoryBlock::fromPayload(oh);
	return block->getAllocater();
}

inline int64_t getPayloadSize(void* oh) {
	MemoryBlock* block = MemoryBlock::fromPayload(oh);
	return block->getPayloadSize();
}

inline int64_t getMemorySize(void* oh) {
	MemoryBlock* block = MemoryBlock::fromPayload(oh);
	return block->getPayloadSize();
}

inline static int64_t getObjectSize(ObjectHead* oh) {
	return getPayloadSize(oh) - sizeof(ObjectHead);
}

inline static void tryUpdateAllocater4Global(ObjectHead* oh) {
	MemoryBlock* block = MemoryBlock::fromPayload(oh);
	if (block->isStoreObject()) {
		StoredMemoryAllocater* ma = (StoredMemoryAllocater*)block->getAllocater();
		if (ma != nullptr) {
			ma->backStore(block);
		}
	}
}

class lock_guard {
public:
	std::mutex& m;
	lock_guard(std::mutex& m) : m(m) {
		m.lock();
	}
	~lock_guard() {
		m.unlock();
	}
};

    } // lang
} // java

#endif // _java_lang_MemoryManager_h_