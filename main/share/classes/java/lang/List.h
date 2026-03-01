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

#ifndef _java_lang_List_h_
#define _java_lang_List_h_

#include <cstdint>
#include <atomic>
#include <java/lang/Logger.h>

namespace java {
	namespace lang {

template<typename T>
class AtomicSList {
public:
	::std::atomic<T*> head;
	AtomicSList() {
		head = nullptr;
	}

	void clear() {
		head = nullptr;
	}

	inline bool isEmpty() const {
		return head == nullptr;
	}

	inline bool hasOnlyOne() {
		T* t = head;
		if (t != nullptr) {
			return t->next == nullptr;
		}
		return false;
	}

	inline bool moreThanOne() {
		T* t = head;
		if (t != nullptr) {
			return t->next != nullptr;
		}
		return false;
	}

	//std::atomic<int32_t> count;
	inline void prepend(T* value) {
		//if (value->next == value) {
		//	log_warning("prepend %p\n", value);
		//}
		//if (exists(value)) {
		//	log_warning("prepend %p\n", value);
		//}
		T* oldValue = head.load(std::memory_order_relaxed);
		do {
			value->next = oldValue;
		}  while (!head.compare_exchange_weak(oldValue, value, std::memory_order_release, std::memory_order_relaxed));
		//if (value->next == value) {
		//	log_warning("prepend %p\n", value);
		//}
		//count++;
	}

	// this function is not safe on concurrent access, when the removed item prepend current list immediately
	inline T* removeFirst() {
		T* oldValue = head.load(std::memory_order_consume);
		while (oldValue != nullptr) {
			T* newValue = oldValue->next;
			//if (newValue == oldValue) {
			//	log_warning("ddd %p\n", newValue);
			//}
			if (head.compare_exchange_weak(oldValue, newValue, std::memory_order_release, std::memory_order_consume)) {
				oldValue->next = nullptr;
				//return oldValue;
				break;
			}
		}
		//if (oldValue != nullptr) {
		//	//if (exists(oldValue)) {
		//	//	log_warning("exists %p\n", oldValue);
		//	//}
		//	count--;
		//}
		return oldValue;
	}

	inline void prependList(T* list) {
		T* value = list;
		while (value != nullptr) {
			T* next = value->next;
			value->next = nullptr;
			prepend(value);
			value = next;
		}
	}

	inline void prependList(T* first, T* tail) {
		T* oldValue = head.load(std::memory_order_relaxed);
		do {
			tail->next = oldValue;
		} while (!head.compare_exchange_weak(oldValue, first, std::memory_order_release, std::memory_order_relaxed));
	}

	inline T* first() const {
		return head;
	}

	inline bool only(T* oh) const {
		if (oh == head) {
			return oh->next == nullptr;
		}
		return false;
	}

	inline bool exists(T* value) {
		T* it = head;
		while (it != nullptr) {
			if (it == value) {
				return true;
			}
			it = it->next;
		}
		return false;
	}

	inline T* exchange(T* listHead) {
		return head.exchange(listHead);
	}
};

template<typename T>
class AtomicSListIterator {
	AtomicSList<T>* list;
	T* pre;
	T* cur;
public:
	AtomicSListIterator(AtomicSList<T>* list) : list(list) {
		pre = nullptr;
		cur = list->head;
	}

	inline bool has() {
		return cur != nullptr;
	}

	inline T* get() {
		return cur;
	}

	inline void next() {
		T* oh = cur;
		pre = oh;
		cur = oh->next;
	
		//return oh;
		//while (true) {
		//	pre = cur;
		//	T* newValue = cur->next;
		//	if (cur.compare_exchange_weak(pre, newValue)) {
		//		break;
		//	}
		//}
	}

	// only safe for prepend, not ok for removeFirst
	inline T* remove() {
		T* oh = cur;
		cur = oh->next;
		if (pre != nullptr) {
			pre->next = cur;
		} else {
			//T* oh2 = list->next;
			//if (oh2 == oh) {
				while (true) {
					T* oh2 = list->head;
					if (oh2 == oh) {
						if (list->head.compare_exchange_weak(oh2, cur)) {
							return oh;
						}
					} else {
						break;
					}
				}
			//}
			
			// list has been prepend new value
			pre = list->head;
			while (pre != nullptr) {
				if (pre->next == oh) {
					pre->next = cur;
					return oh;
				}
				pre = pre->next;
			}
			// shouldNotReachHere();
			return nullptr;
		}
		return oh;

	//	T* oh = cur;
	//	if (pre != nullptr) {
	//		while (true) {
	//			if (pre->next != oh) {
	//				cur = nullptr;
	//				return false;
	//			}
	//			cur = oh->next;
	//			if (pre->next.compare_exchange_weak(oh, cur)) {
	//				break;
	//			}
	//		}
	//	} else {
	//		while (true) {
	//			T* oldValue = objectQueue->next;
	//			if (oldValue != oh) {
	//				cur = nullptr;
	//				return false;
	//			}
	//			cur = oh->next;
	//			if (objectQueue->next.compare_exchange_weak(oh, cur)) {
	//				break;
	//			}
	//		}
	//	}
	////	T* next = cur->next;
	////	objectQueue->remove(cur);
	////	cur = next;
	//	return true;
	}
};

template<typename T>
class SList {
public:
	T* head;
	SList() {
		head = nullptr;
	}
	SList(T* head) : head(head) {
	}

	void clear() {
		head = nullptr;
	}

	inline bool isEmpty() const {
		return head == nullptr;
	}

	inline bool hasOnlyOne() {
		T* t = head;
		if (t != nullptr) {
			return t->next == nullptr;
		}
		return false;
	}

	inline bool moreThanOne() {
		T* t = head;
		if (t != nullptr) {
			return t->next != nullptr;
		}
		return false;
	}

	inline void prepend(T* value) {
		value->next = head;
		head = value;
	}

	inline void prependList(T* list) {
		T* value = list;
		while (value != nullptr) {
			T* next = value->next;
			value->next = nullptr;
			prepend(value);
			value = next;
		}
	}

	inline void prependList(T* listHead, T* listTail) {
		listTail->next = head;
		head = listHead;
	}

	inline T* first() const {
		return head;
	}

	inline T* last() const {
		T* it = head;
		while (it != nullptr) {
			T* next = it->next;
			if (next != nullptr) {
				it = next;
			} else {
				return it;
			}
		}
		return it;
	}

	inline bool only(T* oh) const {
		if (oh == head) {
			return oh->next == nullptr;
		}
		return false;
	}

	inline T* removeFirst() {
		T* first = head;
		if (first == nullptr) {
			return nullptr;
		}
		head = first->next;
		first->next = nullptr;
		return first;
	}

	inline bool exists(T* value) {
		T* it = head;
		while (it != nullptr) {
			if (it == value) {
				return true;
			}
			it = it->next;
		}
		return false;
	}

	inline void swap(SList<T>& list) {
		T* t = head;
		head = list.head;
		list.head = t;
	}

	inline T* exchange(T* listHead) {
		T* oldValue = head;
		head = listHead;
		return oldValue;
	}
};

template<typename T>
class SListIterator {
	SList<T>* list;
	T* pre;
	T* cur;
public:
	SListIterator(SList<T>* list) : list(list) {
		pre = nullptr;
		cur = list->head;
	}

	inline bool has() {
		return cur != nullptr;
	}

	inline T* get() {
		return cur;
	}

	inline T* getPre() {
		return pre;
	}

	inline void next() {
		T* oh = cur;
		pre = oh;
		cur = oh->next;
	}

	inline T* remove() {
		T* oh = cur;
		cur = oh->next;
		if (pre != nullptr) {
			pre->next = cur;
		} else {
			T* oh2 = list->head;
			if (oh2 == oh) {
				list->head = cur;
				return oh;
			}

			// list has been prepend new value
			pre = list->head;
			while (pre != nullptr) {
				if (pre->next == oh) {
					pre->next = cur;
					return oh;
				}
				pre = pre->next;
			}
			// shouldNotReachHere();
			return nullptr;
		}
		return oh;
	}
};

template<typename T>
class TailedSList {
public:
	T* head = nullptr;
	T* tail = nullptr;
	int32_t length = 0;

	TailedSList() {}

	TailedSList(T* list) {
		if (list != nullptr) {
			T* tail = list;
			T* next = tail->next;
			int32_t len = 0;
			while (true) {
				len++;
				if (next != nullptr) {
					tail = next;
					next = next->next;
				} else {
					break;
				}
			}
			this->head = list;
			this->tail = tail;
			this->length = len;
		}
	}

	void clear() {
		head = tail = nullptr;
		length = 0;
	}

	bool isEmpty() {
		return head == nullptr;
	}

	T* removeFirst() {
		T* block = head;
		if (block != nullptr) {
			if (block != tail) {
				head = block->next;
			} else {
				head = tail = nullptr;
			}
			block->next = nullptr;
			length--;
		}
		return block;
	}

	void prepend(T* t) {
		if (head != nullptr) {
			t->next = head;
			head = t;
		} else {
			head = tail = t;
			t->next = nullptr;
		}
		length++;
	}
};

template<typename T>
inline int32_t lengthOfList(T* list) {
	int32_t len = 0;
	T* it = list;
	while (it != nullptr) {
		len++;
		it = it->next;
	}
	return len;
}

template<typename T>
inline T* tailOfList(T* list) {
	T* it = list;
	if (it != nullptr) {
		while (true) {
			T* next = it->next;
			if (next != nullptr) {
				it = next;
			} else {
				break;
			}
		}
	}
	return it;
}

template<typename T>
inline T* subList(T* list, int32_t maxSize) {
	if (list != nullptr) {
		T* tail = list;
		T* next = tail->next;
		for (int32_t i = 0; i < maxSize; i++) {
			if (next != nullptr) {
				tail = next;
				next = next->next;
			} else {
				break;
			}
		}
		tail->next = nullptr;
		return next;
	}
	return list;
}

template<typename T>
class ListSuber {
public:
	TailedSList<T> left;
	T* rightHead = nullptr;

	void subList(T* list, int32_t maxSize) {
		if (list != nullptr) {
			T* tail = list;
			int32_t len = 0;
			while (true) {
				len++;
				if (len >= maxSize) {
					break;
				}
				T* next = tail->next;
				if (next != nullptr) {
					tail = next;
				} else {
					break;
				}
			}
			left.head = list;
			left.tail = tail;
			left.length = len;
			rightHead = tail->next;
			tail->next = nullptr;
		}
	}
};

template<typename T>
class ListScaner {
public:
	T* head = nullptr;
	T* tail = nullptr;
	int32_t length = 0;

	void scan(T* list) {
		if (list != nullptr) {
			T* tail = list;
			T* next = tail->next;
			int32_t len = 0;
			while (true) {
				len++;
				if (next != nullptr) {
					tail = next;
					next = next->next;
				} else {
					break;
				}
			}
			this->head = list;
			this->tail = tail;
			this->length = len;
		}
	}
};

// List
template<typename T>
class ListItem {
public:
	T* prev = nullptr;
	T* next = nullptr;
};

template<typename T>
class List {
public:
	T* head;
	T* tail;

	List() {
		clear();
	}
	List(const char* name) {
		clear();
	}

	inline void clear() {
		head = nullptr;
		tail = nullptr;
		//head.prev = nullptr;
		//head.next = (T*)&tail;
		//tail.prev = (T*)&head;
		//tail.next = nullptr;
	}

	inline bool isEmpty() const {
		return head == nullptr;
		//return head.next == (T*)&tail;
	}

	inline bool hasOnlyOne() {
		//return head.next == tail.prev;
		return head != nullptr && head == tail;
	}
	
	//inline bool isEnd(T* oh) {
	//	//return oh == (T*)&tail;
	//	return oh == tail;
	//}

	inline void prepend(T* oh) {
		if (head == nullptr) {
			head = tail = oh;
		} else {
			oh->prev = nullptr;
			oh->next = head;
			head->prev = oh;
			head = oh;
		}
		//oh->prev = (T*)&head;
		//oh->next = head.next;
		//head.next->prev = oh;
		//head.next = oh;
	}

	inline void append(T* oh) {
		if (head == nullptr) {
			head = tail = oh;
		} else {
			oh->prev = tail;
			oh->next = nullptr;
			tail->next = oh;
			tail = oh;
		}
		//oh->next = (T*)&tail;
		//oh->prev = tail.prev;
		//tail.prev->next = oh;
		//tail.prev = oh;
	}

	inline T* first() const {
		if (isEmpty()) {
			return nullptr;
		}
		return head;
	}

	inline T* last() const {
		if (isEmpty()) {
			return nullptr;
		}
		return tail;
	}

	inline bool only(T* oh) const {
		//return oh == head.next && oh == tail.prev;
		return oh == head && oh == tail;
	}

	inline T* removeFirst() {
		if (isEmpty()) {
			return nullptr;
		}
		//T* oh = head.next;
		//head.next = (T*)oh->next;
		//head.next->prev = (T*)&head;
		//oh->prev = nullptr;
		//oh->next = nullptr;
		T* oh = head;
		head = oh->next;
		oh->next = nullptr;
		if (head != nullptr) {
			head->prev = nullptr;
		} else {
			tail = nullptr;
		}
		return oh;
	}

	int32_t size() const {
		int32_t c = 0;
		T* oh = head;
		while (oh != nullptr) {
			c++;
			oh = oh->next;
		}
		return c;
	}

//	void verifyCount() {
//		int32_t c = count0();
//		if (count != c) {
//			count0();
//		}
//	}

	//inline void prependQueue(List<T>* queue) {
	//	if (!queue->isEmpty()) {
	//		T* thisQueueFirst = head.next;
	//		T* queueLast = queue->tail.prev;
	//		thisQueueFirst->prev = queueLast;
	//		queueLast->next = thisQueueFirst;

	//		T* queueFirst = queue->head.next;
	//		head.next = queueFirst;
	//		queueFirst->prev = (T*)&head;

	//		queue->clear();
	//	}
	//}

	inline void remove(T* oh) {
		if (oh == head) {
			head = head->next;
			if (head != nullptr) {
				head->prev = nullptr;
			} else {
				head = tail = nullptr;
			}
			oh->next = nullptr;
			return;
		} else if (oh == tail) {
			tail = tail->prev;
			tail->next = nullptr;
			oh->prev = nullptr;
			return;
		}
		T* prev = oh->prev;
		T* next = oh->next;
		prev->next = next;
		next->prev = prev;
		oh->prev = nullptr;
		oh->next = nullptr;
	}

	//static inline void leaveQueue(T* oh) {
	//	// check oh is in queue
	//	if (oh->prev != nullptr) {
	//		oh->prev->next = oh->next;
	//		oh->next->prev = oh->prev;
	//		oh->prev = oh->next = nullptr;
	//	}
	//}
};

// template<typename T>
// class NamedList : public List<T> {
// public:
// 	const char* queueName;
// 	NamedList() : queueName("") {
// 	}

// 	NamedList(const char* queueName) : queueName(queueName) {
// 	}
// };

template<typename T>
class ListIterator {
	List<T>* objectQueue;
	T* cur;
	T* end;
public:
	ListIterator(List<T>* objectQueue) : objectQueue(objectQueue) {
		cur = objectQueue->head.next;
		end = (T*)&objectQueue->tail;
	}

	inline bool hasNext() {
		return cur != end;
	}

	inline T* next() {
		T* oh = cur;
		cur = cur->next;
		return oh;
	}

	inline T* removeNext() {
		T* oh = cur;
		T* next = cur->next;
		objectQueue->remove(cur);
		cur = next;
		return oh;
	}

	inline void remove(T* oh) {
		objectQueue->remove(oh);
	}
};

// template<typename T>
// class NamedListIterator {
// 	NamedList<T>* objectQueue;
// 	T* cur;
// 	T* end;
// public:
// 	NamedListIterator(NamedList<T>* objectQueue) : objectQueue(objectQueue) {
// 		cur = objectQueue->head.next;
// 		end = (T*)&objectQueue->tail;
// 	}

// 	inline bool hasNext() {
// 		// return cur != end;
// 		return !objectQueue->isEnd(cur);
// 	}

// 	inline T* next() {
// 		T* oh = cur;
// #ifdef _DEBUG
// 		if (cur == cur->next) {
// 			printf("a\n");
// 		}
// #endif
// 		cur = cur->next;
// #ifdef _DEBUG
// 		if (cur == nullptr) {
// 			printf("cur == nullptr\n");
// 		}
// #endif
// 		return oh;
// 	}

// 	inline T* removeNext() {
// 		T* oh = cur;
// 		T* next = cur->next;
// 		objectQueue->remove(cur);
// 		cur = next;
// 		return oh;
// 	}

// 	inline void remove(T* oh) {
// 		objectQueue->remove(oh);
// 	}
// };

	}
}

#endif // _java_lang_List_h_