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

#include <java/lang/MemoryManager.h>

#include <java/lang/String.h>
#include <java/lang/ObjectArray.h>
#include <java/lang/Logger.h>

#include "Platform.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <inttypes.h>
#include <new>

namespace java {
	namespace lang {

const int32_t alignedObjectAllocaterSize = (int32_t)calcAlignedSize(sizeof(StoredMemoryAllocater));
const int32_t alignedObjectStoreSize = (int32_t)calcAlignedSize(sizeof(MemoryStore));

const int32_t k = 1024;
const int64_t m = 1024 * k;
const int64_t g = 1024 * m;

int32_t maxChunkSize = 4 * 1024 * 1024;
int32_t minChunkSize = 1 * 1024 * 1024;
int32_t optSlabItemCount = 2000;
int32_t minIncSize = 16;
int32_t chunkSizes[SLAB_COUNT];
int32_t maxSlabSize = 64 * 1024;
int32_t maxStaticMemroyBufferSize = 256 * 1024;
int32_t maxStaticMemroyAllocateSize = 128 * 1024;

struct MaxSizeRate {
	int64_t size;
	double rate;
};

const MaxSizeRate MAX_SIZE_RATES[] = {
	{1 * g, 0.5},
	{2 * g, 0.45},
	{4 * g, 0.4},
	{8 * g, 0.35},
	{16 * g, 0.25},
	{32 * g, 0.2},
	{64 * g, 0.15},
	{128 * g, 0.1},
	{256 * g, 0.1},
	{512 * g, 0.1},
	{1024 * g, 0.1}
};

int64_t calcDefaultMaxSize(int64_t physicalMemorySize) {
	double maxSize = 0;
	for (int32_t i = 0; $lengthOf(MAX_SIZE_RATES); i++) {
		MaxSizeRate msr = MAX_SIZE_RATES[i];
		if (physicalMemorySize >= msr.size) {
			if (i == 0) {
				maxSize += msr.size * msr.rate;
			} else {
				maxSize += (msr.size - MAX_SIZE_RATES[i - 1].size) * msr.rate;
			}
		} else {
			if (i == 0) {
				maxSize += physicalMemorySize * msr.rate;
			} else {
				maxSize += (physicalMemorySize - MAX_SIZE_RATES[i - 1].size) * msr.rate;
			}
			break;
		}
	}
	return (int64_t)maxSize;
}

void MemoryManager::setMaxMemorySize(int64_t size) {
	if (size <= 0) {
		size = calcDefaultMaxSize(Platform::getPhysicalMemory());
	}
	maxMemorySize = size;
	if (minMemorySize > maxMemorySize) {
		minMemorySize = maxMemorySize;
	}
	setMinLocalGcMemorySize();
	printArgs();
}

void MemoryManager::setMinMemorySize(int64_t size) {
	if (size <= 0) {
		size = calcDefaultMaxSize(Platform::getPhysicalMemory()) / 5;
	}
	minMemorySize = size;
	if (minMemorySize > maxMemorySize) {
		maxMemorySize = minMemorySize;
	}
	setMinLocalGcMemorySize();
	printArgs();
}

void MemoryManager::setMinLocalGcMemorySize() {
	minLocalGcMemorySize = minMemorySize / 10;
}

void MemoryManager::printArgs() {
	log_info("maxMemorySize:%" PRId64 " minMemorySize:%" PRId64 " minLocalGcMemorySize:%" PRId64 "\n", maxMemorySize, minMemorySize, minLocalGcMemorySize)
}

void* MemoryManager::systemMalloc(int64_t size) {
	void* ptr = ::malloc(size);
	if (ptr != nullptr) {
		this->setMaxPointer((uint64_t)ptr + size);
		this->setMinPointer((uint64_t)ptr);
	}
	return ptr;
}

void MemoryManager::systemFree(void* ptr) {
	::free(ptr);
}

MemoryManager::MemoryManager() : rawMemoryAllocater(this), objectMemoryAllocater(this),
		staticMemoryAllocater(this, maxStaticMemroyBufferSize, maxStaticMemroyAllocateSize),
		memoryStoreIndex(this), memoryBlockIndex(this) {
	for (int i = 0; i < SLAB_COUNT; i++) {
		stores[i] = nullptr;
	}
}

void MemoryManager::init() {
	setMaxMemorySize(0);
	setMinMemorySize(0);
	warningMemorySize = (int64_t)(this->maxMemorySize * 0.55);

	//log_info("sizeof(ObjectHead): %" PRId32 ", sizeof(Object): %" PRId32 ", sizeof(String): %" PRId32 ", sizeof(ObjectArray): %" PRId32 "\n",
		//(int32_t)sizeof(ObjectHead), (int32_t)sizeof(Object), (int32_t)sizeof(String), (int32_t)sizeof(ObjectArray));
	//int32_t size = sizeof(MemoryBlock) + sizeof(ObjectHead) + sizeof(Object);
	int32_t blockSize = (int32_t)calcBlockSizeFromPayloadSize(calcPayloadSizeFromObjectSize(sizeof(Object) + 16));

	int32_t remainedMaxChunkSize = maxChunkSize - alignedObjectAllocaterSize;
	int32_t remainedMinChunkSize = minChunkSize - alignedObjectAllocaterSize;
	for (int32_t ii = 0; ii < SLAB_COUNT; ii++) {
		if (blockSize % ALIGN_NUM != 0) {
			blockSize += (ALIGN_NUM - blockSize % ALIGN_NUM);
		}
		chunkSizes[ii] = remainedMaxChunkSize;
		int32_t count = chunkSizes[ii] / blockSize;
		while (count > optSlabItemCount && chunkSizes[ii] >= remainedMinChunkSize * 2) {
			chunkSizes[ii] -= remainedMinChunkSize;
			count = chunkSizes[ii] / blockSize;
		}
		int32_t remainder = chunkSizes[ii] % blockSize;
		while (remainder > count * ALIGN_NUM) {
			blockSize += ALIGN_NUM;
			remainder = chunkSizes[ii] % blockSize;
		}
		slabPayloadSizes[ii] = calcPayloadSizeFromBlockSize(blockSize);
		slabSizes[ii] = slabPayloadSizes[ii] - sizeof(ObjectHead);
		//log_info("%" PRId32 " chunk: %" PRId32 ", size: %" PRId32 ", count: %" PRId32 ", remainder: %" PRId32 "\n", ii, chunkSizes[ii], size, count, remainder);
		int32_t inc = (int)(blockSize * 0.1);
		if (inc < minIncSize) {
			inc = minIncSize;
		}
		blockSize += inc;
	}
}

int32_t allocaterId = 0;

StoredMemoryAllocater* MemoryManager::getCreateAllocater0() {
	//LockGuard lock(storesLock);
	StoredMemoryAllocater* allocater = allocaterCacheList.removeFirst();
	if (allocater == nullptr) {
		MemoryStore* store = createStore0(sizeof(StoredMemoryAllocater), 1024, false);
		if (store == nullptr) {
			return nullptr;
		}
		StoredMemoryBlock* block = store->allocBlock();
		allocater = new(block->payload<StoredMemoryAllocater>()) StoredMemoryAllocater();
		allocater->id = allocaterId++;
		while (true) {
			block = store->allocBlock();
			if (block != nullptr) {
				StoredMemoryAllocater* move = new(block->payload<StoredMemoryAllocater>()) StoredMemoryAllocater();
				move->id = allocaterId++;
				allocaterCacheList.prepend(move);
			} else {
				break;
			}
		}
		{
			allocaterStores.prepend(store);
		}
	}
	return allocater;
}

void MemoryManager::freeAllocater0(StoredMemoryAllocater* allocater) {
	//LockGuard lock(storesLock);
	allocater->flush();
	if (allocater->getAllocedCount() == 0) {
		allocater->deinit();
	}
	pendingAllocaters.prepend(allocater);
}

MemoryStore* MemoryManager::createStore0(int32_t payloadSize, int32_t count, bool banchMode) {
	int64_t alignedStoreSize = calcAlignedSize(sizeof(MemoryStore));
	int32_t blockSize = calcBlockSizeFromPayloadSize(payloadSize);
	//(int32_t)std::max(sizeof(MemoryBlock) + payloadSize, sizeof(StoredMemoryBlock));
	//int64_t alignedBlockSize = calcAlignedSize(blockSize);
	int64_t allSize = alignedStoreSize + blockSize * count;
	MemoryBlock* block = allocSystemBlock(allSize, false);
	if (block == nullptr) {
		return nullptr;
	}
	int8_t* buffer = block->payload<int8_t>();
	MemoryStore* store = new(buffer) MemoryStore(buffer + alignedStoreSize, (int32_t)(allSize - alignedStoreSize), payloadSize, banchMode);
	memoryStoreIndex.add(store);
	statAllocateStore(block->getMemorySize());
	//log_debug("createStore0 %p payloadSize:%" PRId32 "\n", store, payloadSize);
	return store;
}

void MemoryManager::freeStore0(MemoryStore* store) {
	//log_debug("freeStore0 %p payloadSize:%" PRId32 "\n", store, store->payloadSize);
	memoryStoreIndex.remove(store);
	MemoryBlock* block = MemoryBlock::fromPayload(store);
	statFreeStore(block->getMemorySize());
	freeSystemBlock(block);
}

#define MIN_FREE_COUNT 2
#define MAX_ALOCATER_PER_STORE 128
#define MIN_WARNING_FREE_COUNT 1
#define MAX_WARNING_ALOCATER_PER_STORE 256

bool MemoryManager::attachStore(int32_t slabIndex, StoredMemoryAllocater* allocater) {
	{
		MemoryStore* store = stores[slabIndex].load();
		if (store != nullptr) {
			if (store->freeCount >= MIN_FREE_COUNT) {
				store->addRef();
				if (store->getRefCount() < MAX_ALOCATER_PER_STORE) {
					allocater->init(store);
					store->releaseRef();
					return true;
				}
				store->releaseRef();
			}
		}
	}
	{
		AtomicMemoryStoreList& storeList = storeLists[slabIndex];
		AtomicMemoryStoreList& pendingStoreList = pendingStoreLists[slabIndex];
		LockGuard lock(storesLock);

		int count = 0;
		MemoryStore* store = storeList.removeFirst();
		//if (store != nullptr && store == storeList.head) {
		//	MemoryStore* next = store->next;
		//	log_warning("attachStore storeList.== %d %d %p %p\n", slabIndex, count, store, next);
		//}
		while (store != nullptr) {
			//log_debug("attachStore remove storeList.== %d %d %p\n", slabIndex, count, store);
			if (store->freeCount >= MIN_FREE_COUNT) {
				if (store->getRefCount() < MAX_ALOCATER_PER_STORE) {
					//if (storeList.exists(store)) {
					//	MemoryStore* store2 = storeList.head;
					//	log_warning("attachStore storeList.exists %d %d %p %p\n", slabIndex, count, store, store2);
					//}
					//log_debug("attachStore prepend storeList.== %d %d %p\n", slabIndex, count, store);
					//$fence();
					allocater->init(store);
					storeList.prepend(store);
					return true;
				}
			}
			//$fence();
			//if (pendingStoresList.exists(store)) {
			//	log_warning("attachStore pendingStoresList.exists %d %p\n", slabIndex, store);
			//}
			//log_debug("attachStore prepend pendingStores.== %d %d %p\n", slabIndex, count, store);
			pendingStoreList.prepend(store);
			store = storeList.removeFirst();
			//if (store != nullptr && store == storeList.head) {
			//	MemoryStore* next = store->next;
			//	log_warning("attachStore storeList.== %d %d %p %p\n", slabIndex, count, store, next);
			//}
			count++;
		}
		if (isMemoryWarning() && false) {
			MemoryStore* listHead = pendingStoreList.exchange(nullptr);
			store = listHead;
			while (store != nullptr) {
				if (store->freeCount >= MIN_WARNING_FREE_COUNT) {
					if (store->getRefCount() < MAX_WARNING_ALOCATER_PER_STORE) {
						allocater->init(store);
						storeList.prepend(store);
						if (listHead != nullptr) {
							pendingStoreList.prependList(listHead);
						}
						return true;
					}
				}
				pendingStoreList.prepend(store);
				listHead = listHead->next;
				store = listHead;
			}
		}
	}
	//if (store == nullptr) {
		int32_t chunkSize = chunkSizes[slabIndex];
		int32_t slabPayloadSize = slabPayloadSizes[slabIndex];
		int32_t count = chunkSize / slabPayloadSize;
		MemoryStore* store = createStore0(slabPayloadSize, count, true);
		if (store != nullptr) {
			//if (store->next != nullptr) {
			//	log_warning("attachStore create storeList.== %d %d %p\n", slabIndex, count, store);
			//}
			//if (store != nullptr && store == storeList.head) {
			//	log_warning("attachStore create storeList.== %d %d %p\n", slabIndex, count, store);
			//}
			//if (storeList.exists(store)) {
			//	log_warning("attachStore create storeList.exists %d %p\n", slabIndex, store);
			//}
			//log_debug("attachStore create prepend storeList.prepend %d %p\n", slabIndex, store);
			//store->addRef();
			allocater->init(store);
			AtomicMemoryStoreList& storeList = storeLists[slabIndex];
			storeList.prepend(store);
			//if (store != nullptr && store->next != nullptr && store->next == storeList.head) {
			//	log_warning("attachStore create storeList.== %d %d %p\n", slabIndex, count, store);
			//}
			return true;
		}
	//}
	return false;
}

int32_t MemoryManager::getChunkSize(int32_t slabIndex) {
	return chunkSizes[slabIndex];
}

StoredMemoryAllocater* MemoryManager::createAllocater(int32_t slabIndex) {
	StoredMemoryAllocater* allocater = getCreateAllocater0();
	if (allocater != nullptr) {
		bool successed = attachStore(slabIndex, allocater);
		if (successed) {
			//log_debug("createAllocater %p id:%" PRId32 "\n", allocater, allocater->id);
			return allocater;
		} else {
			freeAllocater0(allocater);
			return nullptr;
		}
	}
	return nullptr;
}

//StoredMemoryAllocater* MemoryManager::createAllocater(int32_t payloadSize, int32_t count) {
//	StoredMemoryAllocater* allocater = getCreateAllocater0();
//	if (allocater != nullptr) {
//		MemoryStore* store = createStore0(payloadSize, count, false);
//		if (store != nullptr) {
//			allocater->init(store);
//			return allocater;
//		}
//		freeAllocater0(allocater);
//		allocater = nullptr;
//	}
//	return allocater;
//}

void MemoryManager::freeAllocater(StoredMemoryAllocater* allocater) {
	//log_debug("freeAllocater %p id:%" PRId32 "\n", allocater, allocater->id);
	freeAllocater0(allocater);
}

CachedRawMemoryAllocater* MemoryManager::createCachedRawMemoryAllocater(int64_t payloadSize) {
	void* data = this->allocRawOrExit(sizeof(CachedRawMemoryAllocater));
	CachedRawMemoryAllocater* allocater = new (data) CachedRawMemoryAllocater(this, payloadSize);
	return allocater;
}

void MemoryManager::freeCachedRawMemoryAllocater(CachedRawMemoryAllocater* allocater) {
	allocater->clear();
	freeRaw(allocater);
}

MemoryBlock* RawMemoryAllocater::allocBlockOrNull(int64_t payloadSize, bool core) {
	MemoryBlock* block = memoryManager->allocSystemBlock(payloadSize, core);
	if (block != nullptr) {
		block->setAllocater(this);
		int64_t size = block->getMemorySize();
		stat.add(size, size);
		return block;
	}
	return nullptr;
}

void RawMemoryAllocater::free(void* m) {
	MemoryBlock* block = MemoryBlock::fromPayload(m);
	int64_t size = block->getMemorySize();
	stat.sub(size, size);
	memoryManager->freeSystemBlock(block);
}

void* CachedRawMemoryAllocater::allocRawOrNull() {
	StoredMemoryBlock* block = removeCache();
	if (block == nullptr) {
		block = (StoredMemoryBlock*)memoryManager->allocSystemBlock(payloadSize, false);
		if (block != nullptr) {
			block->setAllocater(this);
			int64_t size = block->getMemorySize();
			stat.add(size, size);
		}
	}
	if (block != nullptr) {
		return block->payload<void>();
	}
	return nullptr;
}

void CachedRawMemoryAllocater::opt(int32_t count) {
	if (cacheCount > minCacheCount) {
		StoredMemoryBlock* block = removeCache();
		while (block != nullptr) {
			int64_t size = block->getMemorySize();
			stat.sub(size, size);
			memoryManager->freeSystemBlock(block);
			count--;
			if (count <= 0) {
				break;
			}
			block = removeCache();
		}
	}
}

void CachedRawMemoryAllocater::clear() {
	StoredMemoryBlock* block = removeCache();
	while (block != nullptr) {
		int64_t size = block->getMemorySize();
		stat.sub(size, size);
		memoryManager->freeSystemBlock(block);
		block = removeCache();
	}
}

ObjectHead* ObjectMemoryAllocater::allocObject(int64_t payloadSize) {
	MemoryBlock* block = memoryManager->allocSystemBlock(payloadSize, false);
	if (block != nullptr) {
		block->setAllocater(this);
		block->setObject();
		block->initPayload();
		memoryManager->memoryBlockIndex.add(block);
		int64_t size = block->getMemorySize();
		stat.add(size, size);
		return block->payload<ObjectHead>();
	}
	return nullptr;
}

void ObjectMemoryAllocater::free(void* m) {
	MemoryBlock* block = MemoryBlock::fromPayload(m);
	int64_t size = block->getMemorySize();
	stat.sub(size, size);
	memoryManager->memoryBlockIndex.remove(block);
	memoryManager->freeSystemBlock(block);
}

ObjectHead* MemoryManager::allocObjectOrNull(int64_t payloadSize) {
	return objectMemoryAllocater.allocObject(payloadSize);
}

void MemoryManager::freeRaw(void* mem) {
	if (mem != nullptr) {
		MemoryBlock* block = MemoryBlock::fromPayload(mem);
		MemoryAllocater* allocater = block->getAllocater();
		allocater->free(mem);
	}
}

//void MemoryManager::freeObjectLocal(ObjectHead* oh) {
//	if (oh != nullptr) {
//		MemoryBlock* block = MemoryBlock::fromPayload(oh);
//		MemoryAllocater* allocater = block->getAllocater();
//		//if (block->isStored()) {
//		//	StoredMemoryAllocater* storedAllocater = (StoredMemoryAllocater*)allocater;
//		//	storedAllocater->freeLocal((StoredMemoryBlock*)block);
//		//} else {
//			allocater->free(oh);
//		//}
//	}
//}

void MemoryManager::freeObject(ObjectHead* oh) {
	if (oh != nullptr) {
		MemoryBlock* block = MemoryBlock::fromPayload(oh);
		MemoryAllocater* allocater = block->getAllocater();
		allocater->free(oh);
	}
}

bool MemoryManager::expand(void* mem, int32_t newSize) {
	if (mem != nullptr) {
		MemoryBlock* block = MemoryBlock::fromPayload(mem);
		int64_t size = getPayloadSize(mem);
		return newSize < size;
	}
	return false;
}

MemoryBlock* MemoryManager::allocSystemBlock(int64_t payloadSize, bool core) {
	int64_t blockSize = MemoryBlock::calcBlockSize(payloadSize);
	if (!core && willOutOfMemory(blockSize)) {
		return nullptr;
	}
	MemoryBlock* block = (MemoryBlock*)systemMalloc(blockSize);
	if (block == nullptr) {
		return nullptr;
	}
	statAllocate(blockSize);
	block->init(payloadSize);
	return block;
}

void MemoryManager::freeSystemBlock(MemoryBlock* block) {
	if (block != nullptr) {
		int64_t blockSize = block->getMemorySize();
		systemFree(block);
		statFree(blockSize);
	}
}

void* MemoryManager::allocRawOrNull(int64_t payloadSize) {
	MemoryBlock* block = rawMemoryAllocater.allocBlockOrNull(payloadSize, false);
	if (block != nullptr) {
		block->initPayload();
		return block->payload<int8_t>();
	}
	return nullptr;
}

void* MemoryManager::allocRawOrExit(int64_t payloadSize) {
	MemoryBlock* block = rawMemoryAllocater.allocBlockOrNull(payloadSize, true);
	if (block != nullptr) {
		block->initPayload();
		return block->payload<int8_t>();
	}
	log_error("out of memory error, allocRawOrExit %" PRId64 "\n", payloadSize);
	exit(1);
	return nullptr;
}

void* MemoryManager::allocRawStaticOrNull(int64_t payloadSize) {
	MemoryBlock* block = staticMemoryAllocater.alloc(payloadSize);
	if (block != nullptr) {
		block->initPayload();
		return block->payload<void>();
	}
	return allocRawOrNull(payloadSize);
}

void* MemoryManager::allocRawStaticOrExit(int64_t payloadSize) {
	MemoryBlock* block = staticMemoryAllocater.alloc(payloadSize);
	if (block != nullptr) {
		block->initPayload();
		return block->payload<void>();
	}
	log_error("out of memory error, allocRawStaticOrExit %" PRId64 "\n", payloadSize);
	exit(1);
	return nullptr;
}

ObjectHead* MemoryManager::allocObjectStaticOrNull(int64_t payloadSize) {
	MemoryBlock* block = staticMemoryAllocater.alloc(payloadSize);
	if (block != nullptr) {
		block->setObject();
		block->initPayload();
		return block->payload<ObjectHead>();
	}
	return allocObjectOrNull(payloadSize);
}

ObjectHead* MemoryManager::tryToObject(void* addr) {
	{
		MemoryStore* store = memoryStoreIndex.getByObjectAddr(addr);
		if (store != nullptr) {
			ObjectHead* oh = (ObjectHead*)store->getPayloadBegin(addr);
			if (oh != nullptr && oh->isUsed()) {
				return oh;
			}
		}
	}
	{
		MemoryBlock* block = memoryBlockIndex.getByObjectAddr(addr);
		if (block != nullptr) {
			ObjectHead* oh = (ObjectHead*)block->payload<int8_t>();
			if (oh != nullptr && oh->isUsed()) {
				return oh;
			}
		}
	}
	return nullptr;
}

void MemoryManager::opt(OPT_TYPE type) {
	if (type == OPT_FINAL_GC) {
		LockGuard lock(optLock);
		opt0(type);
	} else {
		if (optLock.try_lock()) {
			opt0(type);
			optLock.unlock();
		}
	}
}

void MemoryManager::opt0(OPT_TYPE type) {
	//log_debug("MemoryManager::opt\n");
	bool statLogOut = false;
	int64_t current = $System::currentTimeMillis();
	if (current > lastStatLogOutMs + 2000 || type == OPT_FINAL_GC) {
		statLogOut = true;
		lastStatLogOutMs = current;
	}

	int32_t maxFreeCount = 0;
	if (optCount % 2 == 0 || type == OPT_GC) {
		maxFreeCount = 1;
	}
	if (type == OPT_FINAL_GC) {
		maxFreeCount = 99999;
		//for (int i = 0; i < SLAB_COUNT; i++) {
		//	AtomicMemoryAllocaterList& allocaterList = allocaters[i];
		//	StoredMemoryAllocater* listHead = allocaterList.exchange(nullptr);
		//	MemoryAllocaterList allocatersTemp(listHead);
		//	StoredMemoryAllocater* ma = allocatersTemp.removeFirst();
		//	while (ma != nullptr) {
		//		if (ma->getAllocedCount() == 0) {
		//			pendingAllocaters.prepend(ma);
		//		} else {
		//			allocaterList.prepend(ma);
		//		}
		//		ma = allocatersTemp.removeFirst();
		//	}
		//}
	}
	{
		StoredMemoryAllocater* listHead = pendingAllocaters.exchange(nullptr);
		MemoryAllocaterList pendingAllocatersTemp(listHead);
		StoredMemoryAllocater* ma = pendingAllocatersTemp.removeFirst();
		while (ma != nullptr) {
			if (ma->getAllocedCount() == 0) {
				// pendingObjectAllocatersCount[i]--;
				// printf("MemoryManager::opt %d pendingObjectAllocaters slab:%d index:%d\n", force, i, index);
				ma->deinit();
				allocaterCacheList.prepend(ma);
			} else {
				pendingAllocaters.prepend(ma);
			}
			ma = pendingAllocatersTemp.removeFirst();
		}
	}

	MemoryStoreList freeObjectStoreList;
	MemoryStat freeObjectStoreStat;
	MemoryStat pendingStoreStat[SLAB_COUNT];
	MemoryStat storeStat[SLAB_COUNT];
	{
		LockGuard lock(storesLock);
		for (int i = 0; i < SLAB_COUNT; i++) {
			MemoryStat* stat = &pendingStoreStat[i];
			AtomicMemoryStoreList& storeList = storeLists[i];
			AtomicMemoryStoreList& pendingStoreList = pendingStoreLists[i];
			MemoryStore* listHead = pendingStoreList.exchange(nullptr);
			MemoryStoreList pendingStoresTemp(listHead);
			MemoryStore* ms = pendingStoresTemp.removeFirst();
			while (ms != nullptr) {
				if (!ms->isEmpty()) {
					// printf("MemoryManager::opt %d pendingObjectStores slab:%d size:%d index:%d\n", force, i, os->bufferSize, index);
					//if (storeList.exists(ms)) {
					//	log_warning("stores[slabIndex].exists %d %p\n", i, ms);
					//}
					storeList.prepend(ms);
				} else {
					//if (pendingStoresList.exists(ms)) {
					//	log_warning("pendingStoresList.exists %d %p\n", i, ms);
					//}
					pendingStoreList.prepend(ms);
					ms->stat(stat);
				}
				ms = pendingStoresTemp.removeFirst();
			}
		}

		for (int i = 0; i < SLAB_COUNT; i++) {
			AtomicMemoryStoreList& pendingStoreList = pendingStoreLists[i];
			MemoryStat* stat = &storeStat[i];
			MemoryStore* ms0 = stores[i];
			if (ms0 != nullptr) {
				if (ms0->freeCount < MIN_FREE_COUNT || ms0->getRefCount() >= MAX_ALOCATER_PER_STORE) {
					stores[i] = nullptr;
					pendingStoreList.prepend(ms0);
					ms0->stat(&pendingStoreStat[i]);
					ms0 = nullptr;
				} else {
					ms0->stat(stat);
				}
			}
			int32_t freeCount = 0;
			AtomicMemoryStoreList& storeList = storeLists[i];
			MemoryStore* listHead = storeList.exchange(nullptr);
			MemoryStoreList storesTemp(listHead);
			MemoryStore* ms = storesTemp.removeFirst();
			while (ms != nullptr) {
				if (freeCount < maxFreeCount && ms->canFreeThisStore()) {
					// printf("MemoryManager::opt %d objectStores slab:%d size:%d index:%d\n", force, i, os->bufferSize, index);
					//if (freeObjectStoreList.exists(ms)) {
					//	log_warning("exists %d %p\n", i, ms);
					//}
					freeCount++;
					freeObjectStoreList.prepend(ms);
					ms->stat(&freeObjectStoreStat);
				} else {
					//if (storeList.exists(ms)) {
					//	log_warning("storeList.exists %d %p\n", i, ms);
					//}
					if (ms0 == nullptr) {
						ms0 = ms;
						stores[i] = ms0;
					} else {
						storeList.prepend(ms);
					}
					ms->stat(stat);
				}
				ms = storesTemp.removeFirst();
			}
		}
	}

	MemoryStore* ms = freeObjectStoreList.removeFirst();
	while (ms != nullptr) {
		MemoryStore* next = freeObjectStoreList.removeFirst();
		//log_debug("before freeStore0 %p\n", ms);
		freeStore0(ms);
		//log_debug("after freeStore0\n");
		ms = next;
		statLogOut = true;
	}

	if (statLogOut) {
		MemoryStat pendingStoreStatSum;
		MemoryStat storeStatSum;
		MemoryStat storeTotal;
		for (int i = 0; i < SLAB_COUNT; i++) {
			if (type == OPT_FINAL_GC) {
				//storeStat[i].logOut("store", i);
			}
			storeStatSum.add(&storeStat[i]);
		}
		for (int i = 0; i < SLAB_COUNT; i++) {
			if (type == OPT_FINAL_GC) {
				//pendingStoreStat[i].logOut("pending store", i);
			}
			pendingStoreStatSum.add(&pendingStoreStat[i]);
		}
		storeTotal.add(&pendingStoreStatSum);
		storeTotal.add(&storeStatSum);
		pendingStoreStatSum.logOut("pending store sum");
		storeStatSum.logOut("store sum");
		storeTotal.logOut("store total");
		MemoryStat allocaterStoresStat;
		MemoryStore* store = allocaterStores.first();
		while (store != nullptr) {
			store->stat(&allocaterStoresStat);
			store = store->next;
		}
		allocaterStoresStat.logOut("allocater store");
		freeObjectStoreStat.logOut("free object store");
		log_debug("store stat count:%" PRId64 ", size:%" PRId64 "\n", storeCount.load(), storeSize.load());
		MemoryStat staticStat;
		staticMemoryAllocater.stat(&staticStat);
		staticStat.logOut("static memory");
		rawMemoryAllocater.stat.logOut("raw memory");
		objectMemoryAllocater.stat.logOut("object allocater");
		log_debug("memory total count:%" PRId64 ", size:%" PRId64 "\n", getTotalCount(), getTotalSize());
	}
	optCount++;
}

int64_t MemoryManager::getFreeMemory() {
	if (maxMemorySize > 0) {
		int64_t freeSize = maxMemorySize - totalSize;
		if (freeSize < 0) {
			freeSize = 0;
		}
		return freeSize;
	}
	return Platform::getAvailableMemory();
}

int64_t MemoryManager::getTotalMemory() {
	return totalSize;
}

// MemoryIndex
template<typename T>
int32_t MemoryIndex<T>::find4Add(T* item) {
	int32_t first = 0;
	int32_t last = count - 1;
	while (first <= last) {
		int32_t mid = first + (last - first) / 2;
		T* indexedItem = indexed[mid];
		if (item < indexedItem) {
			last = mid - 1;
		} else if (item > indexedItem) {
			first = mid + 1;
		} else {
			return mid;
		}
	}
	if (first < count) {
		return first;
	} else {
		return -1;
	}
}

template<typename T>
int32_t MemoryIndex<T>::find(T* item) {
	int32_t first = 0;
	int32_t last = count - 1;
	while (first <= last) {
		int32_t mid = first + (last - first) / 2;
		T* indexedItem = indexed[mid];
		if (item < indexedItem) {
			last = mid - 1;
		} else if (item > indexedItem) {
			first = mid + 1;
		} else {
			if (item == indexedItem) {
				return mid;
			} else {
				break;
			}
		}
	}
	return -1;
}

template<typename T>
void MemoryIndex<T>::add(T* item) {
	if (item == nullptr) {
		log_error("add item == null, count:%d\n", count);
	}
	LockGuard lock(indexLock);
	if (count == maxCount) {
		maxCount += 1024;
		T** newIndexed = (T**)manager->allocRawOrExit(sizeof(T*) * maxCount);
		//if (indexed != nullptr) {
			// memcpy(newIndexed, indexed, sizeof(T*) * count);
			for (int32_t i = 0; i < count; i++) {
				newIndexed[i] = indexed[i];
			}
			manager->freeRaw(indexed);
		//}
		indexed = newIndexed;
	}
	int32_t index = find4Add(item);
	if (index != -1) {
		// if (count > index) {
			// memmove(&indexed[index + 1], &indexed[index], sizeof(T*) * (count - index));
			for (int32_t i = count - 1; i >= index; i--) {
				indexed[i + 1] = indexed[i];
			}
		// }
		indexed[index] = item;
	} else {
		indexed[count] = item;
	}
	count++;

	for (int i = 0; i < count; i++) {
		T* indexedItem = indexed[i];
		if (indexedItem == nullptr) {
			log_error("add indexedItem == null, i:%d, index:%d, count:%d\n", i, index, count);
			break;
		}
	}
}

template<typename T>
void MemoryIndex<T>::remove(T* item) {
	LockGuard lock(indexLock);
	int32_t index = find(item);
	if (index != -1) {
		count--;
		// if (count > index) {
			// memmove(&indexed[index], &indexed[index + 1], sizeof(T*) * (count - index));
			for (int32_t i = index; i < count; i++) {
				indexed[i] = indexed[i + 1];
			}
		// }
		indexed[count] = nullptr;

		for (int i = 0; i < count; i++) {
			T* indexedItem = indexed[i];
			if (indexedItem == nullptr) {
				log_error("remove indexedItem == null, index:%d i:%d count:%d\n", index, i, count);
				break;
			}
		}
		return;
	}
}

MemoryStore* MemoryStoreIndex::getByObjectAddr(void* addr) {
	LockGuard lock(indexLock);
	int32_t first = 0;
	int32_t last = count - 1;
	while (first <= last) {
		int32_t mid = first + (last - first) / 2;
		MemoryStore* indexedItem = indexed[mid];
		int8_t* endPtr = (int8_t*)indexedItem->buffer + indexedItem->blockedBufferSize;
		if (addr < indexedItem) {
			last = mid - 1;
		} else if (addr >= endPtr) {
			first = mid + 1;
		} else {
			if (addr > indexedItem && addr < endPtr) {
				return indexedItem;
			} else {
				return nullptr;
			}
		}
	}
	return nullptr;
}

MemoryBlock* MemoryBlockIndex::getByObjectAddr(void* addr) {
	LockGuard lock(indexLock);
	int32_t first = 0;
	int32_t last = count - 1;
	while (first <= last) {
		int32_t mid = first + (last - first) / 2;
		MemoryBlock* indexedItem = indexed[mid];
		if (indexedItem == nullptr) {
			log_error("indexedItem == null, mid:%d, count:%d\n", mid, count);
		}
		int8_t* endPtr = indexedItem->payload<int8_t>() + indexedItem->getPayloadSize();
		if (addr < indexedItem) {
			last = mid - 1;
		} else if (addr >= endPtr) {
			first = mid + 1;
		} else {
			if (addr > indexedItem && addr < endPtr) {
				return indexedItem;
			} else {
				return nullptr;
			}
		}
	}
	return nullptr;
}

MemoryBlock* StaticMemoryAllocater::alloc(int64_t payloadSize) {
	if (payloadSize > maxAllocSize) {
		return nullptr;
	}
	StaticMemoryBuffer* it = head;
	while (it != nullptr) {
		MemoryBlock* block = it->alloc(payloadSize);
		if (block != nullptr) {
			block->setAllocater(this);
			block->init(payloadSize);
			return block;
		}
		it = it->next;
	}
	StaticMemoryBuffer* newBuffer = createBuffer();
	if (newBuffer != nullptr) {
		MemoryBlock* block = newBuffer->alloc(payloadSize);
		StaticMemoryBuffer* old = head.load(std::memory_order_relaxed);
		newBuffer->next = old;
		while (!head.compare_exchange_weak(old, newBuffer, std::memory_order_release, std::memory_order_relaxed)) {
			newBuffer->next = old;
		}
		return block;
	}
	return nullptr;
}

void StaticMemoryAllocater::free(void* m) {
	$shouldNotReachHere();
}

StaticMemoryBuffer* StaticMemoryAllocater::createBuffer() {
	void* raw = memoryManager->allocRawOrNull(maxBufferSize);
	if (raw != nullptr) {
		int64_t offset = calcAlignedSize(sizeof(StaticMemoryBuffer));
		StaticMemoryBuffer* buffer = new(raw) StaticMemoryBuffer((int8_t*)raw + offset, maxBufferSize - offset);
		return buffer;
	}
	return nullptr;
}

	} // lang
} // java