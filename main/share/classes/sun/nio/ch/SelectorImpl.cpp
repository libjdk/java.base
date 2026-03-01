#include <sun/nio/ch/SelectorImpl.h>

#include <java/lang/AssertionError.h>
#include <java/lang/IllegalStateException.h>
#include <java/nio/channels/ClosedSelectorException.h>
#include <java/nio/channels/IllegalSelectorException.h>
#include <java/nio/channels/SelectableChannel.h>
#include <java/nio/channels/SelectionKey.h>
#include <java/nio/channels/Selector.h>
#include <java/nio/channels/spi/AbstractSelectableChannel.h>
#include <java/nio/channels/spi/AbstractSelectionKey.h>
#include <java/nio/channels/spi/AbstractSelector.h>
#include <java/nio/channels/spi/SelectorProvider.h>
#include <java/util/ArrayDeque.h>
#include <java/util/Collections.h>
#include <java/util/Deque.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/Objects.h>
#include <java/util/Set.h>
#include <java/util/concurrent/ConcurrentHashMap$KeySetView.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/function/Consumer.h>
#include <sun/nio/ch/SelChImpl.h>
#include <sun/nio/ch/SelectionKeyImpl.h>
#include <sun/nio/ch/Util.h>
#include <jcpp.h>

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $MethodInfo = ::java::lang::MethodInfo;
using $ClosedSelectorException = ::java::nio::channels::ClosedSelectorException;
using $IllegalSelectorException = ::java::nio::channels::IllegalSelectorException;
using $SelectableChannel = ::java::nio::channels::SelectableChannel;
using $SelectionKey = ::java::nio::channels::SelectionKey;
using $Selector = ::java::nio::channels::Selector;
using $AbstractSelectableChannel = ::java::nio::channels::spi::AbstractSelectableChannel;
using $AbstractSelectionKey = ::java::nio::channels::spi::AbstractSelectionKey;
using $AbstractSelector = ::java::nio::channels::spi::AbstractSelector;
using $SelectorProvider = ::java::nio::channels::spi::SelectorProvider;
using $ArrayDeque = ::java::util::ArrayDeque;
using $Collections = ::java::util::Collections;
using $Deque = ::java::util::Deque;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $Objects = ::java::util::Objects;
using $Set = ::java::util::Set;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $Consumer = ::java::util::function::Consumer;
using $SelChImpl = ::sun::nio::ch::SelChImpl;
using $SelectionKeyImpl = ::sun::nio::ch::SelectionKeyImpl;
using $Util = ::sun::nio::ch::Util;

namespace sun {
	namespace nio {
		namespace ch {

$FieldInfo _SelectorImpl_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(SelectorImpl, $assertionsDisabled)},
	{"keys", "Ljava/util/Set;", "Ljava/util/Set<Ljava/nio/channels/SelectionKey;>;", $PRIVATE | $FINAL, $field(SelectorImpl, keys$)},
	{"selectedKeys", "Ljava/util/Set;", "Ljava/util/Set<Ljava/nio/channels/SelectionKey;>;", $PRIVATE | $FINAL, $field(SelectorImpl, selectedKeys$)},
	{"publicKeys", "Ljava/util/Set;", "Ljava/util/Set<Ljava/nio/channels/SelectionKey;>;", $PRIVATE | $FINAL, $field(SelectorImpl, publicKeys)},
	{"publicSelectedKeys", "Ljava/util/Set;", "Ljava/util/Set<Ljava/nio/channels/SelectionKey;>;", $PRIVATE | $FINAL, $field(SelectorImpl, publicSelectedKeys)},
	{"cancelledKeys", "Ljava/util/Deque;", "Ljava/util/Deque<Lsun/nio/ch/SelectionKeyImpl;>;", $PRIVATE | $FINAL, $field(SelectorImpl, cancelledKeys$)},
	{"inSelect", "Z", nullptr, $PRIVATE, $field(SelectorImpl, inSelect)},
	{}
};

$MethodInfo _SelectorImpl_MethodInfo_[] = {
	{"<init>", "(Ljava/nio/channels/spi/SelectorProvider;)V", nullptr, $PROTECTED, $method(SelectorImpl, init$, void, $SelectorProvider*)},
	{"begin", "(Z)V", nullptr, $PROTECTED | $FINAL, $method(SelectorImpl, begin, void, bool)},
	{"cancel", "(Lsun/nio/ch/SelectionKeyImpl;)V", nullptr, $PUBLIC, $virtualMethod(SelectorImpl, cancel, void, $SelectionKeyImpl*)},
	{"doSelect", "(Ljava/util/function/Consumer;J)I", "(Ljava/util/function/Consumer<Ljava/nio/channels/SelectionKey;>;J)I", $PROTECTED | $ABSTRACT, $virtualMethod(SelectorImpl, doSelect, int32_t, $Consumer*, int64_t), "java.io.IOException"},
	{"end", "(Z)V", nullptr, $PROTECTED | $FINAL, $method(SelectorImpl, end, void, bool)},
	{"ensureOpen", "()V", nullptr, $PRIVATE, $method(SelectorImpl, ensureOpen, void)},
	{"implClose", "()V", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(SelectorImpl, implClose, void), "java.io.IOException"},
	{"implCloseSelector", "()V", nullptr, $PUBLIC | $FINAL, $virtualMethod(SelectorImpl, implCloseSelector, void), "java.io.IOException"},
	{"implDereg", "(Lsun/nio/ch/SelectionKeyImpl;)V", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(SelectorImpl, implDereg, void, $SelectionKeyImpl*), "java.io.IOException"},
	{"implRegister", "(Lsun/nio/ch/SelectionKeyImpl;)V", nullptr, $PROTECTED, $virtualMethod(SelectorImpl, implRegister, void, $SelectionKeyImpl*)},
	{"keys", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/nio/channels/SelectionKey;>;", $PUBLIC | $FINAL, $virtualMethod(SelectorImpl, keys, $Set*)},
	{"lockAndDoSelect", "(Ljava/util/function/Consumer;J)I", "(Ljava/util/function/Consumer<Ljava/nio/channels/SelectionKey;>;J)I", $PRIVATE, $method(SelectorImpl, lockAndDoSelect, int32_t, $Consumer*, int64_t), "java.io.IOException"},
	{"processDeregisterQueue", "()V", nullptr, $PROTECTED | $FINAL, $method(SelectorImpl, processDeregisterQueue, void), "java.io.IOException"},
	{"processReadyEvents", "(ILsun/nio/ch/SelectionKeyImpl;Ljava/util/function/Consumer;)I", "(ILsun/nio/ch/SelectionKeyImpl;Ljava/util/function/Consumer<Ljava/nio/channels/SelectionKey;>;)I", $PROTECTED | $FINAL, $method(SelectorImpl, processReadyEvents, int32_t, int32_t, $SelectionKeyImpl*, $Consumer*)},
	{"register", "(Ljava/nio/channels/spi/AbstractSelectableChannel;ILjava/lang/Object;)Ljava/nio/channels/SelectionKey;", nullptr, $PROTECTED | $FINAL, $virtualMethod(SelectorImpl, register$, $SelectionKey*, $AbstractSelectableChannel*, int32_t, Object$*)},
	{"select", "(J)I", nullptr, $PUBLIC | $FINAL, $virtualMethod(SelectorImpl, select, int32_t, int64_t), "java.io.IOException"},
	{"select", "()I", nullptr, $PUBLIC | $FINAL, $virtualMethod(SelectorImpl, select, int32_t), "java.io.IOException"},
	{"select", "(Ljava/util/function/Consumer;J)I", "(Ljava/util/function/Consumer<Ljava/nio/channels/SelectionKey;>;J)I", $PUBLIC | $FINAL, $virtualMethod(SelectorImpl, select, int32_t, $Consumer*, int64_t), "java.io.IOException"},
	{"select", "(Ljava/util/function/Consumer;)I", "(Ljava/util/function/Consumer<Ljava/nio/channels/SelectionKey;>;)I", $PUBLIC | $FINAL, $virtualMethod(SelectorImpl, select, int32_t, $Consumer*), "java.io.IOException"},
	{"selectNow", "()I", nullptr, $PUBLIC | $FINAL, $virtualMethod(SelectorImpl, selectNow, int32_t), "java.io.IOException"},
	{"selectNow", "(Ljava/util/function/Consumer;)I", "(Ljava/util/function/Consumer<Ljava/nio/channels/SelectionKey;>;)I", $PUBLIC | $FINAL, $virtualMethod(SelectorImpl, selectNow, int32_t, $Consumer*), "java.io.IOException"},
	{"selectedKeys", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/nio/channels/SelectionKey;>;", $PUBLIC | $FINAL, $virtualMethod(SelectorImpl, selectedKeys, $Set*)},
	{"setEventOps", "(Lsun/nio/ch/SelectionKeyImpl;)V", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(SelectorImpl, setEventOps, void, $SelectionKeyImpl*)},
	{}
};

$ClassInfo _SelectorImpl_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"sun.nio.ch.SelectorImpl",
	"java.nio.channels.spi.AbstractSelector",
	nullptr,
	_SelectorImpl_FieldInfo_,
	_SelectorImpl_MethodInfo_
};

$Object* allocate$SelectorImpl($Class* clazz) {
	return $of($alloc(SelectorImpl));
}

bool SelectorImpl::$assertionsDisabled = false;

void SelectorImpl::init$($SelectorProvider* sp) {
	$AbstractSelector::init$(sp);
	$set(this, cancelledKeys$, $new($ArrayDeque));
	$set(this, keys$, $ConcurrentHashMap::newKeySet());
	$set(this, selectedKeys$, $new($HashSet));
	$set(this, publicKeys, $Collections::unmodifiableSet(this->keys$));
	$set(this, publicSelectedKeys, $Util::ungrowableSet(this->selectedKeys$));
}

void SelectorImpl::ensureOpen() {
	if (!isOpen()) {
		$throwNew($ClosedSelectorException);
	}
}

$Set* SelectorImpl::keys() {
	ensureOpen();
	return this->publicKeys;
}

$Set* SelectorImpl::selectedKeys() {
	ensureOpen();
	return this->publicSelectedKeys;
}

void SelectorImpl::begin(bool blocking) {
	if (blocking) {
		begin();
	}
}

void SelectorImpl::end(bool blocking) {
	if (blocking) {
		end();
	}
}

int32_t SelectorImpl::lockAndDoSelect($Consumer* action, int64_t timeout) {
	$synchronized(this) {
		ensureOpen();
		if (this->inSelect) {
			$throwNew($IllegalStateException, "select in progress"_s);
		}
		this->inSelect = true;
		{
			$var($Throwable, var$0, nullptr);
			int32_t var$2 = 0;
			bool return$1 = false;
			try {
				$synchronized(this->publicSelectedKeys) {
					var$2 = doSelect(action, timeout);
					return$1 = true;
					goto $finally;
				}
			} catch ($Throwable& var$3) {
				$assign(var$0, var$3);
			} $finally: {
				this->inSelect = false;
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
			if (return$1) {
				return var$2;
			}
		}
	}
	$shouldNotReachHere();
}

int32_t SelectorImpl::select(int64_t timeout) {
	if (timeout < 0) {
		$throwNew($IllegalArgumentException, "Negative timeout"_s);
	}
	return lockAndDoSelect(nullptr, (timeout == 0) ? (int64_t)-1 : timeout);
}

int32_t SelectorImpl::select() {
	return lockAndDoSelect(nullptr, -1);
}

int32_t SelectorImpl::selectNow() {
	return lockAndDoSelect(nullptr, 0);
}

int32_t SelectorImpl::select($Consumer* action, int64_t timeout) {
	$Objects::requireNonNull(action);
	if (timeout < 0) {
		$throwNew($IllegalArgumentException, "Negative timeout"_s);
	}
	return lockAndDoSelect(action, (timeout == 0) ? (int64_t)-1 : timeout);
}

int32_t SelectorImpl::select($Consumer* action) {
	$Objects::requireNonNull(action);
	return lockAndDoSelect(action, -1);
}

int32_t SelectorImpl::selectNow($Consumer* action) {
	$Objects::requireNonNull(action);
	return lockAndDoSelect(action, 0);
}

void SelectorImpl::implCloseSelector() {
	$useLocalCurrentObjectStackCache();
	wakeup();
	$synchronized(this) {
		implClose();
		$synchronized(this->publicSelectedKeys) {
			$var($Iterator, i, $nc(this->keys$)->iterator());
			while ($nc(i)->hasNext()) {
				$var($SelectionKeyImpl, ski, $cast($SelectionKeyImpl, i->next()));
				deregister(ski);
				$var($SelectableChannel, selch, $nc(ski)->channel());
				bool var$0 = !$nc(selch)->isOpen();
				if (var$0 && !selch->isRegistered()) {
					$nc(($cast($SelChImpl, selch)))->kill();
				}
				$nc(this->selectedKeys$)->remove(ski);
				i->remove();
			}
			bool var$1 = !SelectorImpl::$assertionsDisabled;
			if (var$1) {
				bool var$2 = $nc(this->selectedKeys$)->isEmpty();
				var$1 = !(var$2 && $nc(this->keys$)->isEmpty());
			}
			if (var$1) {
				$throwNew($AssertionError);
			}
		}
	}
}

$SelectionKey* SelectorImpl::register$($AbstractSelectableChannel* ch, int32_t ops, Object$* attachment) {
	if (!($instanceOf($SelChImpl, ch))) {
		$throwNew($IllegalSelectorException);
	}
	$var($SelectionKeyImpl, k, $new($SelectionKeyImpl, $cast($SelChImpl, ch), this));
	if (attachment != nullptr) {
		k->attach(attachment);
	}
	implRegister(k);
	$nc(this->keys$)->add(k);
	try {
		k->interestOps(ops);
	} catch ($ClosedSelectorException& e) {
		if (!SelectorImpl::$assertionsDisabled && !($nc(ch)->keyFor(this) == nullptr)) {
			$throwNew($AssertionError);
		}
		$nc(this->keys$)->remove(k);
		k->cancel();
		$throw(e);
	}
	return k;
}

void SelectorImpl::implRegister($SelectionKeyImpl* ski) {
	ensureOpen();
}

void SelectorImpl::cancel($SelectionKeyImpl* ski) {
	$synchronized(this->cancelledKeys$) {
		$nc(this->cancelledKeys$)->addLast(ski);
	}
}

void SelectorImpl::processDeregisterQueue() {
	$useLocalCurrentObjectStackCache();
	if (!SelectorImpl::$assertionsDisabled && !$Thread::holdsLock(this)) {
		$throwNew($AssertionError);
	}
	if (!SelectorImpl::$assertionsDisabled && !$Thread::holdsLock(this->publicSelectedKeys)) {
		$throwNew($AssertionError);
	}
	$synchronized(this->cancelledKeys$) {
		$var($SelectionKeyImpl, ski, nullptr);
		while (($assign(ski, $cast($SelectionKeyImpl, $nc(this->cancelledKeys$)->pollFirst()))) != nullptr) {
			implDereg(ski);
			$nc(this->selectedKeys$)->remove(ski);
			$nc(this->keys$)->remove(ski);
			deregister(ski);
			$var($SelectableChannel, ch, $nc(ski)->channel());
			bool var$0 = !$nc(ch)->isOpen();
			if (var$0 && !ch->isRegistered()) {
				$nc(($cast($SelChImpl, ch)))->kill();
			}
		}
	}
}

int32_t SelectorImpl::processReadyEvents(int32_t rOps, $SelectionKeyImpl* ski, $Consumer* action) {
	if (action != nullptr) {
		$nc(ski)->translateAndSetReadyOps(rOps);
		int32_t var$0 = ski->nioReadyOps();
		if (((int32_t)(var$0 & (uint32_t)ski->nioInterestOps())) != 0) {
			action->accept(ski);
			ensureOpen();
			return 1;
		}
	} else {
		if (!SelectorImpl::$assertionsDisabled && !$Thread::holdsLock(this->publicSelectedKeys)) {
			$throwNew($AssertionError);
		}
		if ($nc(this->selectedKeys$)->contains(ski)) {
			if ($nc(ski)->translateAndUpdateReadyOps(rOps)) {
				return 1;
			}
		} else {
			$nc(ski)->translateAndSetReadyOps(rOps);
			int32_t var$1 = ski->nioReadyOps();
			if (((int32_t)(var$1 & (uint32_t)ski->nioInterestOps())) != 0) {
				$nc(this->selectedKeys$)->add(ski);
				return 1;
			}
		}
	}
	return 0;
}

void clinit$SelectorImpl($Class* class$) {
	SelectorImpl::$assertionsDisabled = !SelectorImpl::class$->desiredAssertionStatus();
}

SelectorImpl::SelectorImpl() {
}

$Class* SelectorImpl::load$($String* name, bool initialize) {
	$loadClass(SelectorImpl, name, initialize, &_SelectorImpl_ClassInfo_, clinit$SelectorImpl, allocate$SelectorImpl);
	return class$;
}

$Class* SelectorImpl::class$ = nullptr;

		} // ch
	} // nio
} // sun