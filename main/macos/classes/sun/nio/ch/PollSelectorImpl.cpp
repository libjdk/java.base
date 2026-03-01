#include <sun/nio/ch/PollSelectorImpl.h>

#include <java/io/IOException.h>
#include <java/lang/AssertionError.h>
#include <java/lang/InternalError.h>
#include <java/lang/Math.h>
#include <java/nio/channels/ClosedSelectorException.h>
#include <java/nio/channels/Selector.h>
#include <java/nio/channels/spi/AbstractSelector.h>
#include <java/nio/channels/spi/SelectorProvider.h>
#include <java/util/ArrayDeque.h>
#include <java/util/ArrayList.h>
#include <java/util/Deque.h>
#include <java/util/List.h>
#include <java/util/concurrent/TimeUnit.h>
#include <java/util/function/Consumer.h>
#include <jdk/internal/misc/Unsafe.h>
#include <sun/nio/ch/AllocatedNativeObject.h>
#include <sun/nio/ch/FileDispatcherImpl.h>
#include <sun/nio/ch/IOStatus.h>
#include <sun/nio/ch/IOUtil.h>
#include <sun/nio/ch/Net.h>
#include <sun/nio/ch/SelectionKeyImpl.h>
#include <sun/nio/ch/SelectorImpl.h>
#include <jcpp.h>

#undef EVENT_OFFSET
#undef FD_OFFSET
#undef INITIAL_CAPACITY
#undef INTERRUPTED
#undef MAX_VALUE
#undef MILLISECONDS
#undef NANOSECONDS
#undef POLLIN
#undef REVENT_OFFSET
#undef SIZE_POLLFD

using $IOException = ::java::io::IOException;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $ClosedSelectorException = ::java::nio::channels::ClosedSelectorException;
using $Selector = ::java::nio::channels::Selector;
using $SelectorProvider = ::java::nio::channels::spi::SelectorProvider;
using $ArrayDeque = ::java::util::ArrayDeque;
using $ArrayList = ::java::util::ArrayList;
using $Deque = ::java::util::Deque;
using $List = ::java::util::List;
using $TimeUnit = ::java::util::concurrent::TimeUnit;
using $Consumer = ::java::util::function::Consumer;
using $Unsafe = ::jdk::internal::misc::Unsafe;
using $AllocatedNativeObject = ::sun::nio::ch::AllocatedNativeObject;
using $FileDispatcherImpl = ::sun::nio::ch::FileDispatcherImpl;
using $IOStatus = ::sun::nio::ch::IOStatus;
using $IOUtil = ::sun::nio::ch::IOUtil;
using $Net = ::sun::nio::ch::Net;
using $SelectionKeyImpl = ::sun::nio::ch::SelectionKeyImpl;
using $SelectorImpl = ::sun::nio::ch::SelectorImpl;

namespace sun {
	namespace nio {
		namespace ch {

$FieldInfo _PollSelectorImpl_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(PollSelectorImpl, $assertionsDisabled)},
	{"INITIAL_CAPACITY", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(PollSelectorImpl, INITIAL_CAPACITY)},
	{"pollArrayCapacity", "I", nullptr, $PRIVATE, $field(PollSelectorImpl, pollArrayCapacity)},
	{"pollArraySize", "I", nullptr, $PRIVATE, $field(PollSelectorImpl, pollArraySize)},
	{"pollArray", "Lsun/nio/ch/AllocatedNativeObject;", nullptr, $PRIVATE, $field(PollSelectorImpl, pollArray)},
	{"fd0", "I", nullptr, $PRIVATE | $FINAL, $field(PollSelectorImpl, fd0)},
	{"fd1", "I", nullptr, $PRIVATE | $FINAL, $field(PollSelectorImpl, fd1)},
	{"pollKeys", "Ljava/util/List;", "Ljava/util/List<Lsun/nio/ch/SelectionKeyImpl;>;", $PRIVATE | $FINAL, $field(PollSelectorImpl, pollKeys)},
	{"updateLock", "Ljava/lang/Object;", nullptr, $PRIVATE | $FINAL, $field(PollSelectorImpl, updateLock)},
	{"updateKeys", "Ljava/util/Deque;", "Ljava/util/Deque<Lsun/nio/ch/SelectionKeyImpl;>;", $PRIVATE | $FINAL, $field(PollSelectorImpl, updateKeys)},
	{"interruptLock", "Ljava/lang/Object;", nullptr, $PRIVATE | $FINAL, $field(PollSelectorImpl, interruptLock)},
	{"interruptTriggered", "Z", nullptr, $PRIVATE, $field(PollSelectorImpl, interruptTriggered)},
	{"SIZE_POLLFD", "S", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(PollSelectorImpl, SIZE_POLLFD)},
	{"FD_OFFSET", "S", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(PollSelectorImpl, FD_OFFSET)},
	{"EVENT_OFFSET", "S", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(PollSelectorImpl, EVENT_OFFSET)},
	{"REVENT_OFFSET", "S", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(PollSelectorImpl, REVENT_OFFSET)},
	{}
};

$MethodInfo _PollSelectorImpl_MethodInfo_[] = {
	{"<init>", "(Ljava/nio/channels/spi/SelectorProvider;)V", nullptr, 0, $method(PollSelectorImpl, init$, void, $SelectorProvider*), "java.io.IOException"},
	{"add", "(Lsun/nio/ch/SelectionKeyImpl;I)V", nullptr, $PRIVATE, $method(PollSelectorImpl, add, void, $SelectionKeyImpl*, int32_t)},
	{"clearInterrupt", "()V", nullptr, $PRIVATE, $method(PollSelectorImpl, clearInterrupt, void), "java.io.IOException"},
	{"doSelect", "(Ljava/util/function/Consumer;J)I", "(Ljava/util/function/Consumer<Ljava/nio/channels/SelectionKey;>;J)I", $PROTECTED, $virtualMethod(PollSelectorImpl, doSelect, int32_t, $Consumer*, int64_t), "java.io.IOException"},
	{"ensureOpen", "()V", nullptr, $PRIVATE, $method(PollSelectorImpl, ensureOpen, void)},
	{"expandIfNeeded", "()V", nullptr, $PRIVATE, $method(PollSelectorImpl, expandIfNeeded, void)},
	{"getDescriptor", "(I)I", nullptr, $PRIVATE, $method(PollSelectorImpl, getDescriptor, int32_t, int32_t)},
	{"getEventOps", "(I)I", nullptr, $PRIVATE, $method(PollSelectorImpl, getEventOps, int32_t, int32_t)},
	{"getReventOps", "(I)I", nullptr, $PRIVATE, $method(PollSelectorImpl, getReventOps, int32_t, int32_t)},
	{"implClose", "()V", nullptr, $PROTECTED, $virtualMethod(PollSelectorImpl, implClose, void), "java.io.IOException"},
	{"implDereg", "(Lsun/nio/ch/SelectionKeyImpl;)V", nullptr, $PROTECTED, $virtualMethod(PollSelectorImpl, implDereg, void, $SelectionKeyImpl*), "java.io.IOException"},
	{"implRegister", "(Lsun/nio/ch/SelectionKeyImpl;)V", nullptr, $PROTECTED, $virtualMethod(PollSelectorImpl, implRegister, void, $SelectionKeyImpl*)},
	{"poll", "(JII)I", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(PollSelectorImpl, poll, int32_t, int64_t, int32_t, int32_t)},
	{"processEvents", "(Ljava/util/function/Consumer;)I", "(Ljava/util/function/Consumer<Ljava/nio/channels/SelectionKey;>;)I", $PRIVATE, $method(PollSelectorImpl, processEvents, int32_t, $Consumer*), "java.io.IOException"},
	{"processUpdateQueue", "()V", nullptr, $PRIVATE, $method(PollSelectorImpl, processUpdateQueue, void)},
	{"putDescriptor", "(II)V", nullptr, $PRIVATE, $method(PollSelectorImpl, putDescriptor, void, int32_t, int32_t)},
	{"putEventOps", "(II)V", nullptr, $PRIVATE, $method(PollSelectorImpl, putEventOps, void, int32_t, int32_t)},
	{"putReventOps", "(II)V", nullptr, $PRIVATE, $method(PollSelectorImpl, putReventOps, void, int32_t, int32_t)},
	{"remove", "(Lsun/nio/ch/SelectionKeyImpl;)V", nullptr, $PRIVATE, $method(PollSelectorImpl, remove, void, $SelectionKeyImpl*)},
	{"setEventOps", "(Lsun/nio/ch/SelectionKeyImpl;)V", nullptr, $PUBLIC, $virtualMethod(PollSelectorImpl, setEventOps, void, $SelectionKeyImpl*)},
	{"setFirst", "(II)V", nullptr, $PRIVATE, $method(PollSelectorImpl, setFirst, void, int32_t, int32_t)},
	{"update", "(Lsun/nio/ch/SelectionKeyImpl;I)V", nullptr, $PRIVATE, $method(PollSelectorImpl, update, void, $SelectionKeyImpl*, int32_t)},
	{"wakeup", "()Ljava/nio/channels/Selector;", nullptr, $PUBLIC, $virtualMethod(PollSelectorImpl, wakeup, $Selector*)},
	{}
};

#define _METHOD_INDEX_poll 12

$ClassInfo _PollSelectorImpl_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.ch.PollSelectorImpl",
	"sun.nio.ch.SelectorImpl",
	nullptr,
	_PollSelectorImpl_FieldInfo_,
	_PollSelectorImpl_MethodInfo_
};

$Object* allocate$PollSelectorImpl($Class* clazz) {
	return $of($alloc(PollSelectorImpl));
}

bool PollSelectorImpl::$assertionsDisabled = false;

void PollSelectorImpl::init$($SelectorProvider* sp) {
	$SelectorImpl::init$(sp);
	this->pollArrayCapacity = PollSelectorImpl::INITIAL_CAPACITY;
	$set(this, pollKeys, $new($ArrayList));
	$set(this, updateLock, $new($Object));
	$set(this, updateKeys, $new($ArrayDeque));
	$set(this, interruptLock, $new($Object));
	int32_t size = this->pollArrayCapacity * PollSelectorImpl::SIZE_POLLFD;
	$set(this, pollArray, $new($AllocatedNativeObject, size, false));
	try {
		int64_t fds = $IOUtil::makePipe(false);
		this->fd0 = (int32_t)((int64_t)((uint64_t)fds >> 32));
		this->fd1 = (int32_t)fds;
	} catch ($IOException& ioe) {
		$nc(this->pollArray)->free();
		$throw(ioe);
	}
	$synchronized(this) {
		$init($Net);
		setFirst(this->fd0, $Net::POLLIN);
	}
}

void PollSelectorImpl::ensureOpen() {
	if (!isOpen()) {
		$throwNew($ClosedSelectorException);
	}
}

int32_t PollSelectorImpl::doSelect($Consumer* action, int64_t timeout) {
	if (!PollSelectorImpl::$assertionsDisabled && !$Thread::holdsLock(this)) {
		$throwNew($AssertionError);
	}
	int32_t to = (int32_t)$Math::min(timeout, (int64_t)$Integer::MAX_VALUE);
	bool blocking = (to != 0);
	bool timedPoll = (to > 0);
	processUpdateQueue();
	processDeregisterQueue();
	{
		$var($Throwable, var$0, nullptr);
		try {
			begin(blocking);
			int32_t numPolled = 0;
			do {
				int64_t startTime = timedPoll ? $System::nanoTime() : (int64_t)0;
				numPolled = poll($nc(this->pollArray)->address(), this->pollArraySize, to);
				if (numPolled == $IOStatus::INTERRUPTED && timedPoll) {
					int64_t adjust = $System::nanoTime() - startTime;
					$init($TimeUnit);
					to -= $TimeUnit::MILLISECONDS->convert(adjust, $TimeUnit::NANOSECONDS);
					if (to <= 0) {
						numPolled = 0;
					}
				}
			} while (numPolled == $IOStatus::INTERRUPTED);
			if (!PollSelectorImpl::$assertionsDisabled && !(numPolled <= this->pollArraySize)) {
				$throwNew($AssertionError);
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			end(blocking);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	processDeregisterQueue();
	return processEvents(action);
}

void PollSelectorImpl::processUpdateQueue() {
	if (!PollSelectorImpl::$assertionsDisabled && !$Thread::holdsLock(this)) {
		$throwNew($AssertionError);
	}
	$synchronized(this->updateLock) {
		$var($SelectionKeyImpl, ski, nullptr);
		while (($assign(ski, $cast($SelectionKeyImpl, $nc(this->updateKeys)->pollFirst()))) != nullptr) {
			int32_t newEvents = $nc(ski)->translateInterestOps();
			if (ski->isValid()) {
				int32_t index = ski->getIndex();
				if (!PollSelectorImpl::$assertionsDisabled && !(index >= 0 && index < this->pollArraySize)) {
					$throwNew($AssertionError);
				}
				if (index > 0) {
					if (!PollSelectorImpl::$assertionsDisabled && !$equals($nc(this->pollKeys)->get(index), ski)) {
						$throwNew($AssertionError);
					}
					if (newEvents == 0) {
						remove(ski);
					} else {
						update(ski, newEvents);
					}
				} else if (newEvents != 0) {
					add(ski, newEvents);
				}
			}
		}
	}
}

int32_t PollSelectorImpl::processEvents($Consumer* action) {
	$useLocalCurrentObjectStackCache();
	if (!PollSelectorImpl::$assertionsDisabled && !$Thread::holdsLock(this)) {
		$throwNew($AssertionError);
	}
	if (!PollSelectorImpl::$assertionsDisabled && !(this->pollArraySize > 0 && this->pollArraySize == $nc(this->pollKeys)->size())) {
		$throwNew($AssertionError);
	}
	int32_t numKeysUpdated = 0;
	for (int32_t i = 1; i < this->pollArraySize; ++i) {
		int32_t rOps = getReventOps(i);
		if (rOps != 0) {
			$var($SelectionKeyImpl, ski, $cast($SelectionKeyImpl, $nc(this->pollKeys)->get(i)));
			bool var$0 = !PollSelectorImpl::$assertionsDisabled;
			if (var$0) {
				int32_t var$1 = $nc(ski)->getFDVal();
				var$0 = !(var$1 == getDescriptor(i));
			}
			if (var$0) {
				$throwNew($AssertionError);
			}
			if ($nc(ski)->isValid()) {
				numKeysUpdated += processReadyEvents(rOps, ski, action);
			}
		}
	}
	if (getReventOps(0) != 0) {
		if (!PollSelectorImpl::$assertionsDisabled && !(getDescriptor(0) == this->fd0)) {
			$throwNew($AssertionError);
		}
		clearInterrupt();
	}
	return numKeysUpdated;
}

void PollSelectorImpl::implClose() {
	if (!PollSelectorImpl::$assertionsDisabled && ! !isOpen()) {
		$throwNew($AssertionError);
	}
	if (!PollSelectorImpl::$assertionsDisabled && !$Thread::holdsLock(this)) {
		$throwNew($AssertionError);
	}
	$synchronized(this->interruptLock) {
		this->interruptTriggered = true;
	}
	$nc(this->pollArray)->free();
	$FileDispatcherImpl::closeIntFD(this->fd0);
	$FileDispatcherImpl::closeIntFD(this->fd1);
}

void PollSelectorImpl::implRegister($SelectionKeyImpl* ski) {
	if (!PollSelectorImpl::$assertionsDisabled && !($nc(ski)->getIndex() == 0)) {
		$throwNew($AssertionError);
	}
	ensureOpen();
}

void PollSelectorImpl::implDereg($SelectionKeyImpl* ski) {
	if (!PollSelectorImpl::$assertionsDisabled && ! !$nc(ski)->isValid()) {
		$throwNew($AssertionError);
	}
	if (!PollSelectorImpl::$assertionsDisabled && !$Thread::holdsLock(this)) {
		$throwNew($AssertionError);
	}
	int32_t index = $nc(ski)->getIndex();
	if (index > 0) {
		remove(ski);
	}
}

void PollSelectorImpl::setEventOps($SelectionKeyImpl* ski) {
	ensureOpen();
	$synchronized(this->updateLock) {
		$nc(this->updateKeys)->addLast(ski);
	}
}

$Selector* PollSelectorImpl::wakeup() {
	$synchronized(this->interruptLock) {
		if (!this->interruptTriggered) {
			try {
				$IOUtil::write1(this->fd1, (int8_t)0);
			} catch ($IOException& ioe) {
				$throwNew($InternalError, static_cast<$Throwable*>(ioe));
			}
			this->interruptTriggered = true;
		}
	}
	return this;
}

void PollSelectorImpl::clearInterrupt() {
	$synchronized(this->interruptLock) {
		$IOUtil::drain(this->fd0);
		this->interruptTriggered = false;
	}
}

void PollSelectorImpl::setFirst(int32_t fd, int32_t ops) {
	if (!PollSelectorImpl::$assertionsDisabled && !(this->pollArraySize == 0)) {
		$throwNew($AssertionError);
	}
	if (!PollSelectorImpl::$assertionsDisabled && !$nc(this->pollKeys)->isEmpty()) {
		$throwNew($AssertionError);
	}
	putDescriptor(0, fd);
	putEventOps(0, ops);
	this->pollArraySize = 1;
	$nc(this->pollKeys)->add(nullptr);
}

void PollSelectorImpl::add($SelectionKeyImpl* ski, int32_t ops) {
	expandIfNeeded();
	int32_t index = this->pollArraySize;
	if (!PollSelectorImpl::$assertionsDisabled && !(index > 0)) {
		$throwNew($AssertionError);
	}
	putDescriptor(index, $nc(ski)->getFDVal());
	putEventOps(index, ops);
	putReventOps(index, 0);
	$nc(ski)->setIndex(index);
	++this->pollArraySize;
	$nc(this->pollKeys)->add(ski);
	if (!PollSelectorImpl::$assertionsDisabled && !($nc(this->pollKeys)->size() == this->pollArraySize)) {
		$throwNew($AssertionError);
	}
}

void PollSelectorImpl::update($SelectionKeyImpl* ski, int32_t ops) {
	int32_t index = $nc(ski)->getIndex();
	if (!PollSelectorImpl::$assertionsDisabled && !(index > 0 && index < this->pollArraySize)) {
		$throwNew($AssertionError);
	}
	bool var$0 = !PollSelectorImpl::$assertionsDisabled;
	if (var$0) {
		int32_t var$1 = getDescriptor(index);
		var$0 = !(var$1 == ski->getFDVal());
	}
	if (var$0) {
		$throwNew($AssertionError);
	}
	putEventOps(index, ops);
}

void PollSelectorImpl::remove($SelectionKeyImpl* ski) {
	int32_t index = $nc(ski)->getIndex();
	if (!PollSelectorImpl::$assertionsDisabled && !(index > 0 && index < this->pollArraySize)) {
		$throwNew($AssertionError);
	}
	bool var$0 = !PollSelectorImpl::$assertionsDisabled;
	if (var$0) {
		int32_t var$1 = getDescriptor(index);
		var$0 = !(var$1 == ski->getFDVal());
	}
	if (var$0) {
		$throwNew($AssertionError);
	}
	int32_t lastIndex = this->pollArraySize - 1;
	if (lastIndex != index) {
		$var($SelectionKeyImpl, lastKey, $cast($SelectionKeyImpl, $nc(this->pollKeys)->get(lastIndex)));
		if (!PollSelectorImpl::$assertionsDisabled && !($nc(lastKey)->getIndex() == lastIndex)) {
			$throwNew($AssertionError);
		}
		int32_t lastFd = getDescriptor(lastIndex);
		int32_t lastOps = getEventOps(lastIndex);
		int32_t lastRevents = getReventOps(lastIndex);
		if (!PollSelectorImpl::$assertionsDisabled && !($nc(lastKey)->getFDVal() == lastFd)) {
			$throwNew($AssertionError);
		}
		putDescriptor(index, lastFd);
		putEventOps(index, lastOps);
		putReventOps(index, lastRevents);
		$nc(this->pollKeys)->set(index, lastKey);
		$nc(lastKey)->setIndex(index);
	}
	$nc(this->pollKeys)->remove(lastIndex);
	--this->pollArraySize;
	if (!PollSelectorImpl::$assertionsDisabled && !($nc(this->pollKeys)->size() == this->pollArraySize)) {
		$throwNew($AssertionError);
	}
	ski->setIndex(0);
}

void PollSelectorImpl::expandIfNeeded() {
	$useLocalCurrentObjectStackCache();
	if (this->pollArraySize == this->pollArrayCapacity) {
		int32_t oldSize = this->pollArrayCapacity * PollSelectorImpl::SIZE_POLLFD;
		int32_t newCapacity = this->pollArrayCapacity + PollSelectorImpl::INITIAL_CAPACITY;
		int32_t newSize = newCapacity * PollSelectorImpl::SIZE_POLLFD;
		$var($AllocatedNativeObject, newPollArray, $new($AllocatedNativeObject, newSize, false));
		int64_t var$0 = $nc(this->pollArray)->address();
		$nc($($Unsafe::getUnsafe()))->copyMemory(var$0, newPollArray->address(), oldSize);
		$nc(this->pollArray)->free();
		$set(this, pollArray, newPollArray);
		this->pollArrayCapacity = newCapacity;
	}
}

void PollSelectorImpl::putDescriptor(int32_t i, int32_t fd) {
	int32_t offset = PollSelectorImpl::SIZE_POLLFD * i + PollSelectorImpl::FD_OFFSET;
	$nc(this->pollArray)->putInt(offset, fd);
}

int32_t PollSelectorImpl::getDescriptor(int32_t i) {
	int32_t offset = PollSelectorImpl::SIZE_POLLFD * i + PollSelectorImpl::FD_OFFSET;
	return $nc(this->pollArray)->getInt(offset);
}

void PollSelectorImpl::putEventOps(int32_t i, int32_t event) {
	int32_t offset = PollSelectorImpl::SIZE_POLLFD * i + PollSelectorImpl::EVENT_OFFSET;
	$nc(this->pollArray)->putShort(offset, (int16_t)event);
}

int32_t PollSelectorImpl::getEventOps(int32_t i) {
	int32_t offset = PollSelectorImpl::SIZE_POLLFD * i + PollSelectorImpl::EVENT_OFFSET;
	return $nc(this->pollArray)->getShort(offset);
}

void PollSelectorImpl::putReventOps(int32_t i, int32_t revent) {
	int32_t offset = PollSelectorImpl::SIZE_POLLFD * i + PollSelectorImpl::REVENT_OFFSET;
	$nc(this->pollArray)->putShort(offset, (int16_t)revent);
}

int32_t PollSelectorImpl::getReventOps(int32_t i) {
	int32_t offset = PollSelectorImpl::SIZE_POLLFD * i + PollSelectorImpl::REVENT_OFFSET;
	return $nc(this->pollArray)->getShort(offset);
}

int32_t PollSelectorImpl::poll(int64_t pollAddress, int32_t numfds, int32_t timeout) {
	$init(PollSelectorImpl);
	int32_t $ret = 0;
	$prepareNativeStatic(PollSelectorImpl, poll, int32_t, int64_t pollAddress, int32_t numfds, int32_t timeout);
	$ret = $invokeNativeStatic(pollAddress, numfds, timeout);
	$finishNativeStatic();
	return $ret;
}

void clinit$PollSelectorImpl($Class* class$) {
	PollSelectorImpl::$assertionsDisabled = !PollSelectorImpl::class$->desiredAssertionStatus();
	{
		$IOUtil::load();
	}
}

PollSelectorImpl::PollSelectorImpl() {
}

$Class* PollSelectorImpl::load$($String* name, bool initialize) {
	$loadClass(PollSelectorImpl, name, initialize, &_PollSelectorImpl_ClassInfo_, clinit$PollSelectorImpl, allocate$PollSelectorImpl);
	return class$;
}

$Class* PollSelectorImpl::class$ = nullptr;

		} // ch
	} // nio
} // sun