#include <sun/nio/ch/WEPollSelectorImpl.h>

#include <java/io/FileDescriptor.h>
#include <java/io/IOException.h>
#include <java/lang/AssertionError.h>
#include <java/lang/InternalError.h>
#include <java/lang/Math.h>
#include <java/nio/channels/ClosedSelectorException.h>
#include <java/nio/channels/Pipe$SinkChannel.h>
#include <java/nio/channels/Pipe$SourceChannel.h>
#include <java/nio/channels/Selector.h>
#include <java/nio/channels/spi/AbstractInterruptibleChannel.h>
#include <java/nio/channels/spi/AbstractSelector.h>
#include <java/nio/channels/spi/SelectorProvider.h>
#include <java/util/ArrayDeque.h>
#include <java/util/Deque.h>
#include <java/util/HashMap.h>
#include <java/util/Map.h>
#include <java/util/function/Consumer.h>
#include <sun/nio/ch/IOUtil.h>
#include <sun/nio/ch/Net.h>
#include <sun/nio/ch/PipeImpl.h>
#include <sun/nio/ch/SelectionKeyImpl.h>
#include <sun/nio/ch/SelectorImpl.h>
#include <sun/nio/ch/SinkChannelImpl.h>
#include <sun/nio/ch/SourceChannelImpl.h>
#include <sun/nio/ch/WEPoll.h>
#include <jcpp.h>

#undef EPOLLERR
#undef EPOLLHUP
#undef EPOLLIN
#undef EPOLLOUT
#undef EPOLLPRI
#undef MAX_VALUE
#undef NUM_EPOLLEVENTS
#undef POLLCONN
#undef POLLERR
#undef POLLHUP
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
using $Consumer = ::java::util::function::Consumer;
using $IOUtil = ::sun::nio::ch::IOUtil;
using $Net = ::sun::nio::ch::Net;
using $PipeImpl = ::sun::nio::ch::PipeImpl;
using $SelectionKeyImpl = ::sun::nio::ch::SelectionKeyImpl;
using $SelectorImpl = ::sun::nio::ch::SelectorImpl;
using $SinkChannelImpl = ::sun::nio::ch::SinkChannelImpl;
using $SourceChannelImpl = ::sun::nio::ch::SourceChannelImpl;
using $WEPoll = ::sun::nio::ch::WEPoll;

namespace sun {
	namespace nio {
		namespace ch {

$FieldInfo _WEPollSelectorImpl_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(WEPollSelectorImpl, $assertionsDisabled)},
	{"NUM_EPOLLEVENTS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(WEPollSelectorImpl, NUM_EPOLLEVENTS)},
	{"eph", "J", nullptr, $PRIVATE | $FINAL, $field(WEPollSelectorImpl, eph)},
	{"pollArrayAddress", "J", nullptr, $PRIVATE | $FINAL, $field(WEPollSelectorImpl, pollArrayAddress)},
	{"fdToKey", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/Integer;Lsun/nio/ch/SelectionKeyImpl;>;", $PRIVATE | $FINAL, $field(WEPollSelectorImpl, fdToKey)},
	{"updateLock", "Ljava/lang/Object;", nullptr, $PRIVATE | $FINAL, $field(WEPollSelectorImpl, updateLock)},
	{"updateKeys", "Ljava/util/Deque;", "Ljava/util/Deque<Lsun/nio/ch/SelectionKeyImpl;>;", $PRIVATE | $FINAL, $field(WEPollSelectorImpl, updateKeys)},
	{"interruptLock", "Ljava/lang/Object;", nullptr, $PRIVATE | $FINAL, $field(WEPollSelectorImpl, interruptLock)},
	{"interruptTriggered", "Z", nullptr, $PRIVATE, $field(WEPollSelectorImpl, interruptTriggered)},
	{"pipe", "Lsun/nio/ch/PipeImpl;", nullptr, $PRIVATE | $FINAL, $field(WEPollSelectorImpl, pipe)},
	{"fd0Val", "I", nullptr, $PRIVATE | $FINAL, $field(WEPollSelectorImpl, fd0Val)},
	{"fd1Val", "I", nullptr, $PRIVATE | $FINAL, $field(WEPollSelectorImpl, fd1Val)},
	{}
};

$MethodInfo _WEPollSelectorImpl_MethodInfo_[] = {
	{"<init>", "(Ljava/nio/channels/spi/SelectorProvider;)V", nullptr, 0, $method(WEPollSelectorImpl, init$, void, $SelectorProvider*), "java.io.IOException"},
	{"clearInterrupt", "()V", nullptr, $PRIVATE, $method(WEPollSelectorImpl, clearInterrupt, void), "java.io.IOException"},
	{"doSelect", "(Ljava/util/function/Consumer;J)I", "(Ljava/util/function/Consumer<Ljava/nio/channels/SelectionKey;>;J)I", $PROTECTED, $virtualMethod(WEPollSelectorImpl, doSelect, int32_t, $Consumer*, int64_t), "java.io.IOException"},
	{"ensureOpen", "()V", nullptr, $PRIVATE, $method(WEPollSelectorImpl, ensureOpen, void)},
	{"implClose", "()V", nullptr, $PROTECTED, $virtualMethod(WEPollSelectorImpl, implClose, void), "java.io.IOException"},
	{"implDereg", "(Lsun/nio/ch/SelectionKeyImpl;)V", nullptr, $PROTECTED, $virtualMethod(WEPollSelectorImpl, implDereg, void, $SelectionKeyImpl*), "java.io.IOException"},
	{"processEvents", "(ILjava/util/function/Consumer;)I", "(ILjava/util/function/Consumer<Ljava/nio/channels/SelectionKey;>;)I", $PRIVATE, $method(WEPollSelectorImpl, processEvents, int32_t, int32_t, $Consumer*), "java.io.IOException"},
	{"processUpdateQueue", "()V", nullptr, $PRIVATE, $method(WEPollSelectorImpl, processUpdateQueue, void)},
	{"setEventOps", "(Lsun/nio/ch/SelectionKeyImpl;)V", nullptr, $PUBLIC, $virtualMethod(WEPollSelectorImpl, setEventOps, void, $SelectionKeyImpl*)},
	{"toEPollEvents", "(I)I", nullptr, $PRIVATE | $STATIC, $staticMethod(WEPollSelectorImpl, toEPollEvents, int32_t, int32_t)},
	{"toReadyOps", "(I)I", nullptr, $PRIVATE | $STATIC, $staticMethod(WEPollSelectorImpl, toReadyOps, int32_t, int32_t)},
	{"wakeup", "()Ljava/nio/channels/Selector;", nullptr, $PUBLIC, $virtualMethod(WEPollSelectorImpl, wakeup, $Selector*)},
	{}
};

$ClassInfo _WEPollSelectorImpl_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.ch.WEPollSelectorImpl",
	"sun.nio.ch.SelectorImpl",
	nullptr,
	_WEPollSelectorImpl_FieldInfo_,
	_WEPollSelectorImpl_MethodInfo_
};

$Object* allocate$WEPollSelectorImpl($Class* clazz) {
	return $of($alloc(WEPollSelectorImpl));
}

bool WEPollSelectorImpl::$assertionsDisabled = false;

void WEPollSelectorImpl::init$($SelectorProvider* sp) {
	$useLocalCurrentObjectStackCache();
	$SelectorImpl::init$(sp);
	$set(this, fdToKey, $new($HashMap));
	$set(this, updateLock, $new($Object));
	$set(this, updateKeys, $new($ArrayDeque));
	$set(this, interruptLock, $new($Object));
	this->eph = $WEPoll::create();
	this->pollArrayAddress = $WEPoll::allocatePollArray(WEPollSelectorImpl::NUM_EPOLLEVENTS);
	try {
		$set(this, pipe, $new($PipeImpl, sp, false));
	} catch ($IOException& ioe) {
		$WEPoll::freePollArray(this->pollArrayAddress);
		$WEPoll::close(this->eph);
		$throw(ioe);
	}
	this->fd0Val = $nc($($cast($SourceChannelImpl, $nc(this->pipe)->source())))->getFDVal();
	this->fd1Val = $nc($($cast($SinkChannelImpl, $nc(this->pipe)->sink())))->getFDVal();
	$WEPoll::ctl(this->eph, 1, this->fd0Val, $WEPoll::EPOLLIN);
}

void WEPollSelectorImpl::ensureOpen() {
	if (!isOpen()) {
		$throwNew($ClosedSelectorException);
	}
}

int32_t WEPollSelectorImpl::doSelect($Consumer* action, int64_t timeout) {
	if (!WEPollSelectorImpl::$assertionsDisabled && !$Thread::holdsLock(this)) {
		$throwNew($AssertionError);
	}
	int32_t to = (int32_t)$Math::min(timeout, (int64_t)$Integer::MAX_VALUE);
	bool blocking = (to != 0);
	int32_t numEntries = 0;
	processUpdateQueue();
	processDeregisterQueue();
	{
		$var($Throwable, var$0, nullptr);
		try {
			begin(blocking);
			numEntries = $WEPoll::wait(this->eph, this->pollArrayAddress, WEPollSelectorImpl::NUM_EPOLLEVENTS, to);
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

void WEPollSelectorImpl::processUpdateQueue() {
	$useLocalCurrentObjectStackCache();
	if (!WEPollSelectorImpl::$assertionsDisabled && !$Thread::holdsLock(this)) {
		$throwNew($AssertionError);
	}
	$synchronized(this->updateLock) {
		$var($SelectionKeyImpl, ski, nullptr);
		while (($assign(ski, $cast($SelectionKeyImpl, $nc(this->updateKeys)->pollFirst()))) != nullptr) {
			if ($nc(ski)->isValid()) {
				int32_t fd = ski->getFDVal();
				$var($SelectionKeyImpl, previous, $cast($SelectionKeyImpl, $nc(this->fdToKey)->putIfAbsent($($Integer::valueOf(fd)), ski)));
				if (!WEPollSelectorImpl::$assertionsDisabled && !((previous == nullptr) || (previous == ski))) {
					$throwNew($AssertionError);
				}
				int32_t newOps = ski->translateInterestOps();
				int32_t registeredOps = ski->registeredEvents();
				if (newOps != registeredOps) {
					if (newOps == 0) {
						$WEPoll::ctl(this->eph, 3, fd, 0);
					} else {
						int32_t events = toEPollEvents(newOps);
						if (registeredOps == 0) {
							$WEPoll::ctl(this->eph, 1, fd, events);
						} else {
							$WEPoll::ctl(this->eph, 2, fd, events);
						}
					}
					ski->registeredEvents(newOps);
				}
			}
		}
	}
}

int32_t WEPollSelectorImpl::processEvents(int32_t numEntries, $Consumer* action) {
	$useLocalCurrentObjectStackCache();
	if (!WEPollSelectorImpl::$assertionsDisabled && !$Thread::holdsLock(this)) {
		$throwNew($AssertionError);
	}
	bool interrupted = false;
	int32_t numKeysUpdated = 0;
	for (int32_t i = 0; i < numEntries; ++i) {
		int64_t event = $WEPoll::getEvent(this->pollArrayAddress, i);
		int32_t fd = $WEPoll::getDescriptor(event);
		if (fd == this->fd0Val) {
			interrupted = true;
		} else {
			$var($SelectionKeyImpl, ski, $cast($SelectionKeyImpl, $nc(this->fdToKey)->get($($Integer::valueOf(fd)))));
			if (ski != nullptr) {
				int32_t events = $WEPoll::getEvents(event);
				if (((int32_t)(events & (uint32_t)$WEPoll::EPOLLPRI)) != 0) {
					$Net::discardOOB($(ski->getFD()));
				}
				int32_t rOps = toReadyOps(events);
				numKeysUpdated += processReadyEvents(rOps, ski, action);
			}
		}
	}
	if (interrupted) {
		clearInterrupt();
	}
	return numKeysUpdated;
}

void WEPollSelectorImpl::implClose() {
	$useLocalCurrentObjectStackCache();
	bool var$0 = !WEPollSelectorImpl::$assertionsDisabled;
	if (var$0) {
		bool var$1 = !isOpen();
		var$0 = !(var$1 && $Thread::holdsLock(this));
	}
	if (var$0) {
		$throwNew($AssertionError);
	}
	$synchronized(this->interruptLock) {
		this->interruptTriggered = true;
	}
	$WEPoll::close(this->eph);
	$WEPoll::freePollArray(this->pollArrayAddress);
	$nc($($cast($SinkChannelImpl, $nc(this->pipe)->sink())))->close();
	$nc($($cast($SourceChannelImpl, $nc(this->pipe)->source())))->close();
}

void WEPollSelectorImpl::implDereg($SelectionKeyImpl* ski) {
	bool var$0 = !WEPollSelectorImpl::$assertionsDisabled;
	if (var$0) {
		bool var$1 = !$nc(ski)->isValid();
		var$0 = !(var$1 && $Thread::holdsLock(this));
	}
	if (var$0) {
		$throwNew($AssertionError);
	}
	int32_t fd = $nc(ski)->getFDVal();
	if ($nc(this->fdToKey)->remove($($Integer::valueOf(fd))) != nullptr) {
		if (ski->registeredEvents() != 0) {
			$WEPoll::ctl(this->eph, 3, fd, 0);
			ski->registeredEvents(0);
		}
	} else if (!WEPollSelectorImpl::$assertionsDisabled && !(ski->registeredEvents() == 0)) {
		$throwNew($AssertionError);
	}
}

void WEPollSelectorImpl::setEventOps($SelectionKeyImpl* ski) {
	ensureOpen();
	$synchronized(this->updateLock) {
		$nc(this->updateKeys)->addLast(ski);
	}
}

$Selector* WEPollSelectorImpl::wakeup() {
	$synchronized(this->interruptLock) {
		if (!this->interruptTriggered) {
			try {
				$IOUtil::write1(this->fd1Val, (int8_t)0);
			} catch ($IOException& ioe) {
				$throwNew($InternalError, static_cast<$Throwable*>(ioe));
			}
			this->interruptTriggered = true;
		}
	}
	return this;
}

void WEPollSelectorImpl::clearInterrupt() {
	$synchronized(this->interruptLock) {
		$IOUtil::drain(this->fd0Val);
		this->interruptTriggered = false;
	}
}

int32_t WEPollSelectorImpl::toEPollEvents(int32_t ops) {
	$init(WEPollSelectorImpl);
	int32_t events = 2;
	$init($Net);
	if (((int32_t)(ops & (uint32_t)(int32_t)$Net::POLLIN)) != 0) {
		events |= 1;
	}
	if (((int32_t)(ops & (uint32_t)($Net::POLLOUT | $Net::POLLCONN))) != 0) {
		events |= 4;
	}
	return events;
}

int32_t WEPollSelectorImpl::toReadyOps(int32_t events) {
	$init(WEPollSelectorImpl);
	int32_t ops = 0;
	if (((int32_t)(events & (uint32_t)$WEPoll::EPOLLIN)) != 0) {
		$init($Net);
		ops |= $Net::POLLIN;
	}
	if (((int32_t)(events & (uint32_t)$WEPoll::EPOLLOUT)) != 0) {
		$init($Net);
		ops |= ($Net::POLLOUT | $Net::POLLCONN);
	}
	if (((int32_t)(events & (uint32_t)$WEPoll::EPOLLHUP)) != 0) {
		$init($Net);
		ops |= $Net::POLLHUP;
	}
	if (((int32_t)(events & (uint32_t)$WEPoll::EPOLLERR)) != 0) {
		$init($Net);
		ops |= $Net::POLLERR;
	}
	return ops;
}

void clinit$WEPollSelectorImpl($Class* class$) {
	WEPollSelectorImpl::$assertionsDisabled = !WEPollSelectorImpl::class$->desiredAssertionStatus();
}

WEPollSelectorImpl::WEPollSelectorImpl() {
}

$Class* WEPollSelectorImpl::load$($String* name, bool initialize) {
	$loadClass(WEPollSelectorImpl, name, initialize, &_WEPollSelectorImpl_ClassInfo_, clinit$WEPollSelectorImpl, allocate$WEPollSelectorImpl);
	return class$;
}

$Class* WEPollSelectorImpl::class$ = nullptr;

		} // ch
	} // nio
} // sun