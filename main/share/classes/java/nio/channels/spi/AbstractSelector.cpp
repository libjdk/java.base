#include <java/nio/channels/spi/AbstractSelector.h>

#include <java/lang/InternalError.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/VarHandle.h>
#include <java/nio/channels/SelectableChannel.h>
#include <java/nio/channels/SelectionKey.h>
#include <java/nio/channels/Selector.h>
#include <java/nio/channels/spi/AbstractInterruptibleChannel.h>
#include <java/nio/channels/spi/AbstractSelectableChannel.h>
#include <java/nio/channels/spi/AbstractSelectionKey.h>
#include <java/nio/channels/spi/AbstractSelector$1.h>
#include <java/nio/channels/spi/SelectorProvider.h>
#include <java/util/HashSet.h>
#include <java/util/Set.h>
#include <sun/nio/ch/Interruptible.h>
#include <sun/nio/ch/SelectorImpl.h>
#include <jcpp.h>

#undef CLOSED
#undef TYPE

using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $VarHandle = ::java::lang::invoke::VarHandle;
using $SelectionKey = ::java::nio::channels::SelectionKey;
using $Selector = ::java::nio::channels::Selector;
using $AbstractInterruptibleChannel = ::java::nio::channels::spi::AbstractInterruptibleChannel;
using $AbstractSelectableChannel = ::java::nio::channels::spi::AbstractSelectableChannel;
using $AbstractSelectionKey = ::java::nio::channels::spi::AbstractSelectionKey;
using $AbstractSelector$1 = ::java::nio::channels::spi::AbstractSelector$1;
using $SelectorProvider = ::java::nio::channels::spi::SelectorProvider;
using $HashSet = ::java::util::HashSet;
using $Set = ::java::util::Set;
using $Interruptible = ::sun::nio::ch::Interruptible;
using $SelectorImpl = ::sun::nio::ch::SelectorImpl;

namespace java {
	namespace nio {
		namespace channels {
			namespace spi {

$FieldInfo _AbstractSelector_FieldInfo_[] = {
	{"CLOSED", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(AbstractSelector, CLOSED)},
	{"closed", "Z", nullptr, $PRIVATE | $VOLATILE, $field(AbstractSelector, closed)},
	{"provider", "Ljava/nio/channels/spi/SelectorProvider;", nullptr, $PRIVATE | $FINAL, $field(AbstractSelector, provider$)},
	{"cancelledKeys", "Ljava/util/Set;", "Ljava/util/Set<Ljava/nio/channels/SelectionKey;>;", $PRIVATE | $FINAL, $field(AbstractSelector, cancelledKeys$)},
	{"interruptor", "Lsun/nio/ch/Interruptible;", nullptr, $PRIVATE, $field(AbstractSelector, interruptor)},
	{}
};

$MethodInfo _AbstractSelector_MethodInfo_[] = {
	{"<init>", "(Ljava/nio/channels/spi/SelectorProvider;)V", nullptr, $PROTECTED, $method(AbstractSelector, init$, void, $SelectorProvider*)},
	{"begin", "()V", nullptr, $PROTECTED | $FINAL, $method(AbstractSelector, begin, void)},
	{"cancel", "(Ljava/nio/channels/SelectionKey;)V", nullptr, 0, $virtualMethod(AbstractSelector, cancel, void, $SelectionKey*)},
	{"cancelledKeys", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/nio/channels/SelectionKey;>;", $PROTECTED | $FINAL, $method(AbstractSelector, cancelledKeys, $Set*)},
	{"close", "()V", nullptr, $PUBLIC | $FINAL, $virtualMethod(AbstractSelector, close, void), "java.io.IOException"},
	{"deregister", "(Ljava/nio/channels/spi/AbstractSelectionKey;)V", nullptr, $PROTECTED | $FINAL, $method(AbstractSelector, deregister, void, $AbstractSelectionKey*)},
	{"end", "()V", nullptr, $PROTECTED | $FINAL, $method(AbstractSelector, end, void)},
	{"implCloseSelector", "()V", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(AbstractSelector, implCloseSelector, void), "java.io.IOException"},
	{"isOpen", "()Z", nullptr, $PUBLIC | $FINAL, $virtualMethod(AbstractSelector, isOpen, bool)},
	{"provider", "()Ljava/nio/channels/spi/SelectorProvider;", nullptr, $PUBLIC | $FINAL, $virtualMethod(AbstractSelector, provider, $SelectorProvider*)},
	{"register", "(Ljava/nio/channels/spi/AbstractSelectableChannel;ILjava/lang/Object;)Ljava/nio/channels/SelectionKey;", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(AbstractSelector, register$, $SelectionKey*, $AbstractSelectableChannel*, int32_t, Object$*)},
	{}
};

$InnerClassInfo _AbstractSelector_InnerClassesInfo_[] = {
	{"java.nio.channels.spi.AbstractSelector$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _AbstractSelector_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"java.nio.channels.spi.AbstractSelector",
	"java.nio.channels.Selector",
	nullptr,
	_AbstractSelector_FieldInfo_,
	_AbstractSelector_MethodInfo_,
	nullptr,
	nullptr,
	_AbstractSelector_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.nio.channels.spi.AbstractSelector$1"
};

$Object* allocate$AbstractSelector($Class* clazz) {
	return $of($alloc(AbstractSelector));
}

$VarHandle* AbstractSelector::CLOSED = nullptr;

void AbstractSelector::init$($SelectorProvider* provider) {
	$Selector::init$();
	$set(this, interruptor, nullptr);
	$set(this, provider$, provider);
	if ($instanceOf($SelectorImpl, this)) {
		$set(this, cancelledKeys$, $Set::of());
	} else {
		$set(this, cancelledKeys$, $new($HashSet));
	}
}

void AbstractSelector::cancel($SelectionKey* k) {
	$synchronized(this->cancelledKeys$) {
		$nc(this->cancelledKeys$)->add(k);
	}
}

void AbstractSelector::close() {
	bool changed = $nc(AbstractSelector::CLOSED)->compareAndSet($$new($ObjectArray, {$of(this), $$of(false), $$of(true)}));
	if (changed) {
		implCloseSelector();
	}
}

bool AbstractSelector::isOpen() {
	return !this->closed;
}

$SelectorProvider* AbstractSelector::provider() {
	return this->provider$;
}

$Set* AbstractSelector::cancelledKeys() {
	return this->cancelledKeys$;
}

void AbstractSelector::deregister($AbstractSelectionKey* key) {
	$nc(($cast($AbstractSelectableChannel, $($nc(key)->channel()))))->removeKey(key);
}

void AbstractSelector::begin() {
	if (this->interruptor == nullptr) {
		$set(this, interruptor, $new($AbstractSelector$1, this));
	}
	$AbstractInterruptibleChannel::blockedOn(this->interruptor);
	$var($Thread, me, $Thread::currentThread());
	if (me->isInterrupted()) {
		$nc(this->interruptor)->interrupt(me);
	}
}

void AbstractSelector::end() {
	$AbstractInterruptibleChannel::blockedOn(nullptr);
}

void clinit$AbstractSelector($Class* class$) {
	$beforeCallerSensitive();
	{
		try {
			$var($MethodHandles$Lookup, l, $MethodHandles::lookup());
			$init($Boolean);
			$assignStatic(AbstractSelector::CLOSED, $nc(l)->findVarHandle(AbstractSelector::class$, "closed"_s, $Boolean::TYPE));
		} catch ($Exception& e) {
			$throwNew($InternalError, static_cast<$Throwable*>(e));
		}
	}
}

AbstractSelector::AbstractSelector() {
}

$Class* AbstractSelector::load$($String* name, bool initialize) {
	$loadClass(AbstractSelector, name, initialize, &_AbstractSelector_ClassInfo_, clinit$AbstractSelector, allocate$AbstractSelector);
	return class$;
}

$Class* AbstractSelector::class$ = nullptr;

			} // spi
		} // channels
	} // nio
} // java