#include <sun/nio/ch/KQueueSelectorImpl.h>

#include <java/io/IOException.h>
#include <java/lang/AssertionError.h>
#include <java/lang/InternalError.h>
#include <java/lang/Math.h>
#include <java/nio/channels/ClosedSelectorException.h>
#include <java/nio/channels/Selector.h>
#include <java/nio/channels/spi/AbstractSelector.h>
#include <java/nio/channels/spi/SelectorProvider.h>
#include <java/util/ArrayDeque.h>
#include <java/util/Deque.h>
#include <java/util/HashMap.h>
#include <java/util/Map.h>
#include <java/util/concurrent/TimeUnit.h>
#include <java/util/function/Consumer.h>
#include <sun/nio/ch/FileDispatcherImpl.h>
#include <sun/nio/ch/IOStatus.h>
#include <sun/nio/ch/IOUtil.h>
#include <sun/nio/ch/KQueue.h>
#include <sun/nio/ch/Net.h>
#include <sun/nio/ch/SelectionKeyImpl.h>
#include <sun/nio/ch/SelectorImpl.h>
#include <jcpp.h>

#undef INTERRUPTED
#undef MAX_KEVENTS
#undef MAX_VALUE
#undef MILLISECONDS
#undef NANOSECONDS
#undef POLLIN
#undef POLLOUT

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
using $Deque = ::java::util::Deque;
using $HashMap = ::java::util::HashMap;
using $Map = ::java::util::Map;
using $TimeUnit = ::java::util::concurrent::TimeUnit;
using $Consumer = ::java::util::function::Consumer;
using $FileDispatcherImpl = ::sun::nio::ch::FileDispatcherImpl;
using $IOStatus = ::sun::nio::ch::IOStatus;
using $IOUtil = ::sun::nio::ch::IOUtil;
using $KQueue = ::sun::nio::ch::KQueue;
using $Net = ::sun::nio::ch::Net;
using $SelectionKeyImpl = ::sun::nio::ch::SelectionKeyImpl;
using $SelectorImpl = ::sun::nio::ch::SelectorImpl;

namespace sun {
	namespace nio {
		namespace ch {

$FieldInfo _KQueueSelectorImpl_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(KQueueSelectorImpl, $assertionsDisabled)},
	{"MAX_KEVENTS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(KQueueSelectorImpl, MAX_KEVENTS)},
	{"kqfd", "I", nullptr, $PRIVATE | $FINAL, $field(KQueueSelectorImpl, kqfd)},
	{"pollArrayAddress", "J", nullptr, $PRIVATE | $FINAL, $field(KQueueSelectorImpl, pollArrayAddress)},
	{"fd0", "I", nullptr, $PRIVATE | $FINAL, $field(KQueueSelectorImpl, fd0)},
	{"fd1", "I", nullptr, $PRIVATE | $FINAL, $field(KQueueSelectorImpl, fd1)},
	{"fdToKey", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/Integer;Lsun/nio/ch/SelectionKeyImpl;>;", $PRIVATE | $FINAL, $field(KQueueSelectorImpl, fdToKey)},
	{"updateLock", "Ljava/lang/Object;", nullptr, $PRIVATE | $FINAL, $field(KQueueSelectorImpl, updateLock)},
	{"updateKeys", "Ljava/util/Deque;", "Ljava/util/Deque<Lsun/nio/ch/SelectionKeyImpl;>;", $PRIVATE | $FINAL, $field(KQueueSelectorImpl, updateKeys)},
	{"interruptLock", "Ljava/lang/Object;", nullptr, $PRIVATE | $FINAL, $field(KQueueSelectorImpl, interruptLock)},
	{"interruptTriggered", "Z", nullptr, $PRIVATE, $field(KQueueSelectorImpl, interruptTriggered)},
	{"pollCount", "I", nullptr, $PRIVATE, $field(KQueueSelectorImpl, pollCount)},
	{}
};

$MethodInfo _KQueueSelectorImpl_MethodInfo_[] = {
	{"<init>", "(Ljava/nio/channels/spi/SelectorProvider;)V", nullptr, 0, $method(KQueueSelectorImpl, init$, void, $SelectorProvider*), "java.io.IOException"},
	{"clearInterrupt", "()V", nullptr, $PRIVATE, $method(KQueueSelectorImpl, clearInterrupt, void), "java.io.IOException"},
	{"doSelect", "(Ljava/util/function/Consumer;J)I", "(Ljava/util/function/Consumer<Ljava/nio/channels/SelectionKey;>;J)I", $PROTECTED, $virtualMethod(KQueueSelectorImpl, doSelect, int32_t, $Consumer*, int64_t), "java.io.IOException"},
	{"ensureOpen", "()V", nullptr, $PRIVATE, $method(KQueueSelectorImpl, ensureOpen, void)},
	{"implClose", "()V", nullptr, $PROTECTED, $virtualMethod(KQueueSelectorImpl, implClose, void), "java.io.IOException"},
	{"implDereg", "(Lsun/nio/ch/SelectionKeyImpl;)V", nullptr, $PROTECTED, $virtualMethod(KQueueSelectorImpl, implDereg, void, $SelectionKeyImpl*), "java.io.IOException"},
	{"processEvents", "(ILjava/util/function/Consumer;)I", "(ILjava/util/function/Consumer<Ljava/nio/channels/SelectionKey;>;)I", $PRIVATE, $method(KQueueSelectorImpl, processEvents, int32_t, int32_t, $Consumer*), "java.io.IOException"},
	{"processUpdateQueue", "()V", nullptr, $PRIVATE, $method(KQueueSelectorImpl, processUpdateQueue, void)},
	{"setEventOps", "(Lsun/nio/ch/SelectionKeyImpl;)V", nullptr, $PUBLIC, $virtualMethod(KQueueSelectorImpl, setEventOps, void, $SelectionKeyImpl*)},
	{"wakeup", "()Ljava/nio/channels/Selector;", nullptr, $PUBLIC, $virtualMethod(KQueueSelectorImpl, wakeup, $Selector*)},
	{}
};

$ClassInfo _KQueueSelectorImpl_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.ch.KQueueSelectorImpl",
	"sun.nio.ch.SelectorImpl",
	nullptr,
	_KQueueSelectorImpl_FieldInfo_,
	_KQueueSelectorImpl_MethodInfo_
};

$Object* allocate$KQueueSelectorImpl($Class* clazz) {
	return $of($alloc(KQueueSelectorImpl));
}

bool KQueueSelectorImpl::$assertionsDisabled = false;

void KQueueSelectorImpl::init$($SelectorProvider* sp) {
	$SelectorImpl::init$(sp);
	$set(this, fdToKey, $new($HashMap));
	$set(this, updateLock, $new($Object));
	$set(this, updateKeys, $new($ArrayDeque));
	$set(this, interruptLock, $new($Object));
	this->kqfd = $KQueue::create();
	this->pollArrayAddress = $KQueue::allocatePollArray(KQueueSelectorImpl::MAX_KEVENTS);
	try {
		int64_t fds = $IOUtil::makePipe(false);
		this->fd0 = (int32_t)((int64_t)((uint64_t)fds >> 32));
		this->fd1 = (int32_t)fds;
	} catch ($IOException& ioe) {
		$KQueue::freePollArray(this->pollArrayAddress);
		$FileDispatcherImpl::closeIntFD(this->kqfd);
		$throw(ioe);
	}
	$KQueue::register$(this->kqfd, this->fd0, -1, 1);
}

void KQueueSelectorImpl::ensureOpen() {
	if (!isOpen()) {
		$throwNew($ClosedSelectorException);
	}
}

int32_t KQueueSelectorImpl::doSelect($Consumer* action, int64_t timeout) {
	if (!KQueueSelectorImpl::$assertionsDisabled && !$Thread::holdsLock(this)) {
		$throwNew($AssertionError);
	}
	int64_t to = $Math::min(timeout, (int64_t)$Integer::MAX_VALUE);
	bool blocking = (to != 0);
	bool timedPoll = (to > 0);
	int32_t numEntries = 0;
	processUpdateQueue();
	processDeregisterQueue();
	{
		$var($Throwable, var$0, nullptr);
		try {
			begin(blocking);
			do {
				int64_t startTime = timedPoll ? $System::nanoTime() : (int64_t)0;
				numEntries = $KQueue::poll(this->kqfd, this->pollArrayAddress, KQueueSelectorImpl::MAX_KEVENTS, to);
				if (numEntries == $IOStatus::INTERRUPTED && timedPoll) {
					int64_t adjust = $System::nanoTime() - startTime;
					$init($TimeUnit);
					to -= $TimeUnit::MILLISECONDS->convert(adjust, $TimeUnit::NANOSECONDS);
					if (to <= 0) {
						numEntries = 0;
					}
				}
			} while (numEntries == $IOStatus::INTERRUPTED);
			if (!KQueueSelectorImpl::$assertionsDisabled && !$IOStatus::check(numEntries)) {
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
	return processEvents(numEntries, action);
}

void KQueueSelectorImpl::processUpdateQueue() {
	$useLocalCurrentObjectStackCache();
	if (!KQueueSelectorImpl::$assertionsDisabled && !$Thread::holdsLock(this)) {
		$throwNew($AssertionError);
	}
	$synchronized(this->updateLock) {
		$var($SelectionKeyImpl, ski, nullptr);
		while (($assign(ski, $cast($SelectionKeyImpl, $nc(this->updateKeys)->pollFirst()))) != nullptr) {
			if ($nc(ski)->isValid()) {
				int32_t fd = ski->getFDVal();
				$var($SelectionKeyImpl, previous, $cast($SelectionKeyImpl, $nc(this->fdToKey)->putIfAbsent($($Integer::valueOf(fd)), ski)));
				if (!KQueueSelectorImpl::$assertionsDisabled && !((previous == nullptr) || (previous == ski))) {
					$throwNew($AssertionError);
				}
				int32_t newEvents = ski->translateInterestOps();
				int32_t registeredEvents = ski->registeredEvents();
				if (ski->getAndClearReset() && registeredEvents != 0) {
					$KQueue::register$(this->kqfd, fd, -1, 2);
					registeredEvents = 0;
				}
				if (newEvents != registeredEvents) {
					$init($Net);
					if (((int32_t)(registeredEvents & (uint32_t)(int32_t)$Net::POLLIN)) != 0) {
						if (((int32_t)(newEvents & (uint32_t)(int32_t)$Net::POLLIN)) == 0) {
							$KQueue::register$(this->kqfd, fd, -1, 2);
						}
					} else {
						if (((int32_t)(newEvents & (uint32_t)(int32_t)$Net::POLLIN)) != 0) {
							$KQueue::register$(this->kqfd, fd, -1, 1);
						}
					}
					if (((int32_t)(registeredEvents & (uint32_t)(int32_t)$Net::POLLOUT)) != 0) {
						if (((int32_t)(newEvents & (uint32_t)(int32_t)$Net::POLLOUT)) == 0) {
							$KQueue::register$(this->kqfd, fd, -2, 2);
						}
					} else {
						if (((int32_t)(newEvents & (uint32_t)(int32_t)$Net::POLLOUT)) != 0) {
							$KQueue::register$(this->kqfd, fd, -2, 1);
						}
					}
					ski->registeredEvents(newEvents);
				}
			}
		}
	}
}

int32_t KQueueSelectorImpl::processEvents(int32_t numEntries, $Consumer* action) {
	$useLocalCurrentObjectStackCache();
	if (!KQueueSelectorImpl::$assertionsDisabled && !$Thread::holdsLock(this)) {
		$throwNew($AssertionError);
	}
	int32_t numKeysUpdated = 0;
	bool interrupted = false;
	++this->pollCount;
	for (int32_t i = 0; i < numEntries; ++i) {
		int64_t kevent = $KQueue::getEvent(this->pollArrayAddress, i);
		int32_t fd = $KQueue::getDescriptor(kevent);
		if (fd == this->fd0) {
			interrupted = true;
		} else {
			$var($SelectionKeyImpl, ski, $cast($SelectionKeyImpl, $nc(this->fdToKey)->get($($Integer::valueOf(fd)))));
			if (ski != nullptr) {
				int32_t rOps = 0;
				int16_t filter = $KQueue::getFilter(kevent);
				if (filter == -1) {
					$init($Net);
					rOps |= $Net::POLLIN;
				} else if (filter == -2) {
					$init($Net);
					rOps |= $Net::POLLOUT;
				}
				int32_t updated = processReadyEvents(rOps, ski, action);
				if (updated > 0 && ski->lastPolled != this->pollCount) {
					++numKeysUpdated;
					ski->lastPolled = this->pollCount;
				}
			}
		}
	}
	if (interrupted) {
		clearInterrupt();
	}
	return numKeysUpdated;
}

void KQueueSelectorImpl::implClose() {
	if (!KQueueSelectorImpl::$assertionsDisabled && ! !isOpen()) {
		$throwNew($AssertionError);
	}
	if (!KQueueSelectorImpl::$assertionsDisabled && !$Thread::holdsLock(this)) {
		$throwNew($AssertionError);
	}
	$synchronized(this->interruptLock) {
		this->interruptTriggered = true;
	}
	$FileDispatcherImpl::closeIntFD(this->kqfd);
	$KQueue::freePollArray(this->pollArrayAddress);
	$FileDispatcherImpl::closeIntFD(this->fd0);
	$FileDispatcherImpl::closeIntFD(this->fd1);
}

void KQueueSelectorImpl::implDereg($SelectionKeyImpl* ski) {
	if (!KQueueSelectorImpl::$assertionsDisabled && ! !$nc(ski)->isValid()) {
		$throwNew($AssertionError);
	}
	if (!KQueueSelectorImpl::$assertionsDisabled && !$Thread::holdsLock(this)) {
		$throwNew($AssertionError);
	}
	int32_t fd = $nc(ski)->getFDVal();
	int32_t registeredEvents = ski->registeredEvents();
	if ($nc(this->fdToKey)->remove($($Integer::valueOf(fd))) != nullptr) {
		if (registeredEvents != 0) {
			$init($Net);
			if (((int32_t)(registeredEvents & (uint32_t)(int32_t)$Net::POLLIN)) != 0) {
				$KQueue::register$(this->kqfd, fd, -1, 2);
			}
			if (((int32_t)(registeredEvents & (uint32_t)(int32_t)$Net::POLLOUT)) != 0) {
				$KQueue::register$(this->kqfd, fd, -2, 2);
			}
			ski->registeredEvents(0);
		}
	} else if (!KQueueSelectorImpl::$assertionsDisabled && !(registeredEvents == 0)) {
		$throwNew($AssertionError);
	}
}

void KQueueSelectorImpl::setEventOps($SelectionKeyImpl* ski) {
	ensureOpen();
	$synchronized(this->updateLock) {
		$nc(this->updateKeys)->addLast(ski);
	}
}

$Selector* KQueueSelectorImpl::wakeup() {
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

void KQueueSelectorImpl::clearInterrupt() {
	$synchronized(this->interruptLock) {
		$IOUtil::drain(this->fd0);
		this->interruptTriggered = false;
	}
}

void clinit$KQueueSelectorImpl($Class* class$) {
	KQueueSelectorImpl::$assertionsDisabled = !KQueueSelectorImpl::class$->desiredAssertionStatus();
}

KQueueSelectorImpl::KQueueSelectorImpl() {
}

$Class* KQueueSelectorImpl::load$($String* name, bool initialize) {
	$loadClass(KQueueSelectorImpl, name, initialize, &_KQueueSelectorImpl_ClassInfo_, clinit$KQueueSelectorImpl, allocate$KQueueSelectorImpl);
	return class$;
}

$Class* KQueueSelectorImpl::class$ = nullptr;

		} // ch
	} // nio
} // sun