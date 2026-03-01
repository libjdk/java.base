#include <sun/nio/ch/EPollSelectorImpl.h>

#include <java/io/FileDescriptor.h>
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
#include <sun/nio/ch/EPoll.h>
#include <sun/nio/ch/EventFD.h>
#include <sun/nio/ch/FileDispatcherImpl.h>
#include <sun/nio/ch/IOStatus.h>
#include <sun/nio/ch/IOUtil.h>
#include <sun/nio/ch/SelectionKeyImpl.h>
#include <sun/nio/ch/SelectorImpl.h>
#include <jcpp.h>

#undef INTERRUPTED
#undef MAX_VALUE
#undef MILLISECONDS
#undef NANOSECONDS
#undef NUM_EPOLLEVENTS

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
using $EPoll = ::sun::nio::ch::EPoll;
using $EventFD = ::sun::nio::ch::EventFD;
using $FileDispatcherImpl = ::sun::nio::ch::FileDispatcherImpl;
using $IOStatus = ::sun::nio::ch::IOStatus;
using $IOUtil = ::sun::nio::ch::IOUtil;
using $SelectionKeyImpl = ::sun::nio::ch::SelectionKeyImpl;
using $SelectorImpl = ::sun::nio::ch::SelectorImpl;

namespace sun {
	namespace nio {
		namespace ch {

$FieldInfo _EPollSelectorImpl_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(EPollSelectorImpl, $assertionsDisabled)},
	{"NUM_EPOLLEVENTS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(EPollSelectorImpl, NUM_EPOLLEVENTS)},
	{"epfd", "I", nullptr, $PRIVATE | $FINAL, $field(EPollSelectorImpl, epfd)},
	{"pollArrayAddress", "J", nullptr, $PRIVATE | $FINAL, $field(EPollSelectorImpl, pollArrayAddress)},
	{"eventfd", "Lsun/nio/ch/EventFD;", nullptr, $PRIVATE | $FINAL, $field(EPollSelectorImpl, eventfd)},
	{"fdToKey", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/Integer;Lsun/nio/ch/SelectionKeyImpl;>;", $PRIVATE | $FINAL, $field(EPollSelectorImpl, fdToKey)},
	{"updateLock", "Ljava/lang/Object;", nullptr, $PRIVATE | $FINAL, $field(EPollSelectorImpl, updateLock)},
	{"updateKeys", "Ljava/util/Deque;", "Ljava/util/Deque<Lsun/nio/ch/SelectionKeyImpl;>;", $PRIVATE | $FINAL, $field(EPollSelectorImpl, updateKeys)},
	{"interruptLock", "Ljava/lang/Object;", nullptr, $PRIVATE | $FINAL, $field(EPollSelectorImpl, interruptLock)},
	{"interruptTriggered", "Z", nullptr, $PRIVATE, $field(EPollSelectorImpl, interruptTriggered)},
	{}
};

$MethodInfo _EPollSelectorImpl_MethodInfo_[] = {
	{"<init>", "(Ljava/nio/channels/spi/SelectorProvider;)V", nullptr, 0, $method(EPollSelectorImpl, init$, void, $SelectorProvider*), "java.io.IOException"},
	{"clearInterrupt", "()V", nullptr, $PRIVATE, $method(EPollSelectorImpl, clearInterrupt, void), "java.io.IOException"},
	{"doSelect", "(Ljava/util/function/Consumer;J)I", "(Ljava/util/function/Consumer<Ljava/nio/channels/SelectionKey;>;J)I", $PROTECTED, $virtualMethod(EPollSelectorImpl, doSelect, int32_t, $Consumer*, int64_t), "java.io.IOException"},
	{"ensureOpen", "()V", nullptr, $PRIVATE, $method(EPollSelectorImpl, ensureOpen, void)},
	{"implClose", "()V", nullptr, $PROTECTED, $virtualMethod(EPollSelectorImpl, implClose, void), "java.io.IOException"},
	{"implDereg", "(Lsun/nio/ch/SelectionKeyImpl;)V", nullptr, $PROTECTED, $virtualMethod(EPollSelectorImpl, implDereg, void, $SelectionKeyImpl*), "java.io.IOException"},
	{"processEvents", "(ILjava/util/function/Consumer;)I", "(ILjava/util/function/Consumer<Ljava/nio/channels/SelectionKey;>;)I", $PRIVATE, $method(EPollSelectorImpl, processEvents, int32_t, int32_t, $Consumer*), "java.io.IOException"},
	{"processUpdateQueue", "()V", nullptr, $PRIVATE, $method(EPollSelectorImpl, processUpdateQueue, void)},
	{"setEventOps", "(Lsun/nio/ch/SelectionKeyImpl;)V", nullptr, $PUBLIC, $virtualMethod(EPollSelectorImpl, setEventOps, void, $SelectionKeyImpl*)},
	{"wakeup", "()Ljava/nio/channels/Selector;", nullptr, $PUBLIC, $virtualMethod(EPollSelectorImpl, wakeup, $Selector*)},
	{}
};

$ClassInfo _EPollSelectorImpl_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.ch.EPollSelectorImpl",
	"sun.nio.ch.SelectorImpl",
	nullptr,
	_EPollSelectorImpl_FieldInfo_,
	_EPollSelectorImpl_MethodInfo_
};

$Object* allocate$EPollSelectorImpl($Class* clazz) {
	return $of($alloc(EPollSelectorImpl));
}

bool EPollSelectorImpl::$assertionsDisabled = false;
int32_t EPollSelectorImpl::NUM_EPOLLEVENTS = 0;

void EPollSelectorImpl::init$($SelectorProvider* sp) {
	$SelectorImpl::init$(sp);
	$set(this, fdToKey, $new($HashMap));
	$set(this, updateLock, $new($Object));
	$set(this, updateKeys, $new($ArrayDeque));
	$set(this, interruptLock, $new($Object));
	this->epfd = $EPoll::create();
	this->pollArrayAddress = $EPoll::allocatePollArray(EPollSelectorImpl::NUM_EPOLLEVENTS);
	try {
		$set(this, eventfd, $new($EventFD));
		$IOUtil::configureBlocking($($IOUtil::newFD($nc(this->eventfd)->efd())), false);
	} catch ($IOException& ioe) {
		$EPoll::freePollArray(this->pollArrayAddress);
		$FileDispatcherImpl::closeIntFD(this->epfd);
		$throw(ioe);
	}
	$EPoll::ctl(this->epfd, 1, $nc(this->eventfd)->efd(), 1);
}

void EPollSelectorImpl::ensureOpen() {
	if (!isOpen()) {
		$throwNew($ClosedSelectorException);
	}
}

int32_t EPollSelectorImpl::doSelect($Consumer* action, int64_t timeout) {
	if (!EPollSelectorImpl::$assertionsDisabled && !$Thread::holdsLock(this)) {
		$throwNew($AssertionError);
	}
	int32_t to = (int32_t)$Math::min(timeout, (int64_t)$Integer::MAX_VALUE);
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
				numEntries = $EPoll::wait(this->epfd, this->pollArrayAddress, EPollSelectorImpl::NUM_EPOLLEVENTS, to);
				if (numEntries == $IOStatus::INTERRUPTED && timedPoll) {
					int64_t adjust = $System::nanoTime() - startTime;
					$init($TimeUnit);
					to -= $TimeUnit::MILLISECONDS->convert(adjust, $TimeUnit::NANOSECONDS);
					if (to <= 0) {
						numEntries = 0;
					}
				}
			} while (numEntries == $IOStatus::INTERRUPTED);
			if (!EPollSelectorImpl::$assertionsDisabled && !$IOStatus::check(numEntries)) {
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

void EPollSelectorImpl::processUpdateQueue() {
	$useLocalCurrentObjectStackCache();
	if (!EPollSelectorImpl::$assertionsDisabled && !$Thread::holdsLock(this)) {
		$throwNew($AssertionError);
	}
	$synchronized(this->updateLock) {
		$var($SelectionKeyImpl, ski, nullptr);
		while (($assign(ski, $cast($SelectionKeyImpl, $nc(this->updateKeys)->pollFirst()))) != nullptr) {
			if ($nc(ski)->isValid()) {
				int32_t fd = ski->getFDVal();
				$var($SelectionKeyImpl, previous, $cast($SelectionKeyImpl, $nc(this->fdToKey)->putIfAbsent($($Integer::valueOf(fd)), ski)));
				if (!EPollSelectorImpl::$assertionsDisabled && !((previous == nullptr) || (previous == ski))) {
					$throwNew($AssertionError);
				}
				int32_t newEvents = ski->translateInterestOps();
				int32_t registeredEvents = ski->registeredEvents();
				if (newEvents != registeredEvents) {
					if (newEvents == 0) {
						$EPoll::ctl(this->epfd, 2, fd, 0);
					} else if (registeredEvents == 0) {
						$EPoll::ctl(this->epfd, 1, fd, newEvents);
					} else {
						$EPoll::ctl(this->epfd, 3, fd, newEvents);
					}
					ski->registeredEvents(newEvents);
				}
			}
		}
	}
}

int32_t EPollSelectorImpl::processEvents(int32_t numEntries, $Consumer* action) {
	$useLocalCurrentObjectStackCache();
	if (!EPollSelectorImpl::$assertionsDisabled && !$Thread::holdsLock(this)) {
		$throwNew($AssertionError);
	}
	bool interrupted = false;
	int32_t numKeysUpdated = 0;
	for (int32_t i = 0; i < numEntries; ++i) {
		int64_t event = $EPoll::getEvent(this->pollArrayAddress, i);
		int32_t fd = $EPoll::getDescriptor(event);
		if (fd == $nc(this->eventfd)->efd()) {
			interrupted = true;
		} else {
			$var($SelectionKeyImpl, ski, $cast($SelectionKeyImpl, $nc(this->fdToKey)->get($($Integer::valueOf(fd)))));
			if (ski != nullptr) {
				int32_t rOps = $EPoll::getEvents(event);
				numKeysUpdated += processReadyEvents(rOps, ski, action);
			}
		}
	}
	if (interrupted) {
		clearInterrupt();
	}
	return numKeysUpdated;
}

void EPollSelectorImpl::implClose() {
	if (!EPollSelectorImpl::$assertionsDisabled && !$Thread::holdsLock(this)) {
		$throwNew($AssertionError);
	}
	$synchronized(this->interruptLock) {
		this->interruptTriggered = true;
	}
	$FileDispatcherImpl::closeIntFD(this->epfd);
	$EPoll::freePollArray(this->pollArrayAddress);
	$nc(this->eventfd)->close();
}

void EPollSelectorImpl::implDereg($SelectionKeyImpl* ski) {
	if (!EPollSelectorImpl::$assertionsDisabled && ! !$nc(ski)->isValid()) {
		$throwNew($AssertionError);
	}
	if (!EPollSelectorImpl::$assertionsDisabled && !$Thread::holdsLock(this)) {
		$throwNew($AssertionError);
	}
	int32_t fd = $nc(ski)->getFDVal();
	if ($nc(this->fdToKey)->remove($($Integer::valueOf(fd))) != nullptr) {
		if (ski->registeredEvents() != 0) {
			$EPoll::ctl(this->epfd, 2, fd, 0);
			ski->registeredEvents(0);
		}
	} else if (!EPollSelectorImpl::$assertionsDisabled && !(ski->registeredEvents() == 0)) {
		$throwNew($AssertionError);
	}
}

void EPollSelectorImpl::setEventOps($SelectionKeyImpl* ski) {
	ensureOpen();
	$synchronized(this->updateLock) {
		$nc(this->updateKeys)->addLast(ski);
	}
}

$Selector* EPollSelectorImpl::wakeup() {
	$synchronized(this->interruptLock) {
		if (!this->interruptTriggered) {
			try {
				$nc(this->eventfd)->set();
			} catch ($IOException& ioe) {
				$throwNew($InternalError, static_cast<$Throwable*>(ioe));
			}
			this->interruptTriggered = true;
		}
	}
	return this;
}

void EPollSelectorImpl::clearInterrupt() {
	$synchronized(this->interruptLock) {
		$nc(this->eventfd)->reset();
		this->interruptTriggered = false;
	}
}

void clinit$EPollSelectorImpl($Class* class$) {
	EPollSelectorImpl::$assertionsDisabled = !EPollSelectorImpl::class$->desiredAssertionStatus();
	EPollSelectorImpl::NUM_EPOLLEVENTS = $Math::min($IOUtil::fdLimit(), 1024);
}

EPollSelectorImpl::EPollSelectorImpl() {
}

$Class* EPollSelectorImpl::load$($String* name, bool initialize) {
	$loadClass(EPollSelectorImpl, name, initialize, &_EPollSelectorImpl_ClassInfo_, clinit$EPollSelectorImpl, allocate$EPollSelectorImpl);
	return class$;
}

$Class* EPollSelectorImpl::class$ = nullptr;

		} // ch
	} // nio
} // sun