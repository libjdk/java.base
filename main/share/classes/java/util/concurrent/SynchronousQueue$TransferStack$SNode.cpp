#include <java/util/concurrent/SynchronousQueue$TransferStack$SNode.h>

#include <java/lang/ExceptionInInitializerError.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/VarHandle.h>
#include <java/util/concurrent/SynchronousQueue$TransferStack.h>
#include <java/util/concurrent/SynchronousQueue.h>
#include <java/util/concurrent/locks/LockSupport.h>
#include <jcpp.h>

#undef SMATCH
#undef SNEXT
#undef SWAITER

using $ClassInfo = ::java::lang::ClassInfo;
using $ExceptionInInitializerError = ::java::lang::ExceptionInInitializerError;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $VarHandle = ::java::lang::invoke::VarHandle;
using $LockSupport = ::java::util::concurrent::locks::LockSupport;

namespace java {
	namespace util {
		namespace concurrent {

$FieldInfo _SynchronousQueue$TransferStack$SNode_FieldInfo_[] = {
	{"next", "Ljava/util/concurrent/SynchronousQueue$TransferStack$SNode;", nullptr, $VOLATILE, $field(SynchronousQueue$TransferStack$SNode, next)},
	{"match", "Ljava/util/concurrent/SynchronousQueue$TransferStack$SNode;", nullptr, $VOLATILE, $field(SynchronousQueue$TransferStack$SNode, match)},
	{"waiter", "Ljava/lang/Thread;", nullptr, $VOLATILE, $field(SynchronousQueue$TransferStack$SNode, waiter)},
	{"item", "Ljava/lang/Object;", nullptr, 0, $field(SynchronousQueue$TransferStack$SNode, item)},
	{"mode", "I", nullptr, 0, $field(SynchronousQueue$TransferStack$SNode, mode)},
	{"SMATCH", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SynchronousQueue$TransferStack$SNode, SMATCH)},
	{"SNEXT", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SynchronousQueue$TransferStack$SNode, SNEXT)},
	{"SWAITER", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SynchronousQueue$TransferStack$SNode, SWAITER)},
	{}
};

$MethodInfo _SynchronousQueue$TransferStack$SNode_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/Object;)V", nullptr, 0, $method(SynchronousQueue$TransferStack$SNode, init$, void, Object$*)},
	{"block", "()Z", nullptr, $PUBLIC | $FINAL, $virtualMethod(SynchronousQueue$TransferStack$SNode, block, bool)},
	{"casNext", "(Ljava/util/concurrent/SynchronousQueue$TransferStack$SNode;Ljava/util/concurrent/SynchronousQueue$TransferStack$SNode;)Z", nullptr, 0, $method(SynchronousQueue$TransferStack$SNode, casNext, bool, SynchronousQueue$TransferStack$SNode*, SynchronousQueue$TransferStack$SNode*)},
	{"forgetWaiter", "()V", nullptr, 0, $method(SynchronousQueue$TransferStack$SNode, forgetWaiter, void)},
	{"isCancelled", "()Z", nullptr, 0, $method(SynchronousQueue$TransferStack$SNode, isCancelled, bool)},
	{"isReleasable", "()Z", nullptr, $PUBLIC | $FINAL, $virtualMethod(SynchronousQueue$TransferStack$SNode, isReleasable, bool)},
	{"tryCancel", "()Z", nullptr, 0, $method(SynchronousQueue$TransferStack$SNode, tryCancel, bool)},
	{"tryMatch", "(Ljava/util/concurrent/SynchronousQueue$TransferStack$SNode;)Z", nullptr, 0, $method(SynchronousQueue$TransferStack$SNode, tryMatch, bool, SynchronousQueue$TransferStack$SNode*)},
	{}
};

$InnerClassInfo _SynchronousQueue$TransferStack$SNode_InnerClassesInfo_[] = {
	{"java.util.concurrent.SynchronousQueue$TransferStack", "java.util.concurrent.SynchronousQueue", "TransferStack", $STATIC | $FINAL},
	{"java.util.concurrent.SynchronousQueue$TransferStack$SNode", "java.util.concurrent.SynchronousQueue$TransferStack", "SNode", $STATIC | $FINAL},
	{"java.util.concurrent.ForkJoinPool$ManagedBlocker", "java.util.concurrent.ForkJoinPool", "ManagedBlocker", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _SynchronousQueue$TransferStack$SNode_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.concurrent.SynchronousQueue$TransferStack$SNode",
	"java.lang.Object",
	"java.util.concurrent.ForkJoinPool$ManagedBlocker",
	_SynchronousQueue$TransferStack$SNode_FieldInfo_,
	_SynchronousQueue$TransferStack$SNode_MethodInfo_,
	nullptr,
	nullptr,
	_SynchronousQueue$TransferStack$SNode_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.concurrent.SynchronousQueue"
};

$Object* allocate$SynchronousQueue$TransferStack$SNode($Class* clazz) {
	return $of($alloc(SynchronousQueue$TransferStack$SNode));
}

$VarHandle* SynchronousQueue$TransferStack$SNode::SMATCH = nullptr;
$VarHandle* SynchronousQueue$TransferStack$SNode::SNEXT = nullptr;
$VarHandle* SynchronousQueue$TransferStack$SNode::SWAITER = nullptr;

void SynchronousQueue$TransferStack$SNode::init$(Object$* item) {
	$set(this, item, item);
}

bool SynchronousQueue$TransferStack$SNode::casNext(SynchronousQueue$TransferStack$SNode* cmp, SynchronousQueue$TransferStack$SNode* val) {
	return cmp == this->next && $nc(SynchronousQueue$TransferStack$SNode::SNEXT)->compareAndSet($$new($ObjectArray, {$of(this), $of(cmp), $of(val)}));
}

bool SynchronousQueue$TransferStack$SNode::tryMatch(SynchronousQueue$TransferStack$SNode* s) {
	$useLocalCurrentObjectStackCache();
	$var(SynchronousQueue$TransferStack$SNode, m, nullptr);
	$var($Thread, w, nullptr);
	if (($assign(m, this->match)) == nullptr) {
		if ($nc(SynchronousQueue$TransferStack$SNode::SMATCH)->compareAndSet($$new($ObjectArray, {$of(this), ($Object*)nullptr, $of(s)}))) {
			if (($assign(w, this->waiter)) != nullptr) {
				$LockSupport::unpark(w);
			}
			return true;
		} else {
			$assign(m, this->match);
		}
	}
	return m == s;
}

bool SynchronousQueue$TransferStack$SNode::tryCancel() {
	return $nc(SynchronousQueue$TransferStack$SNode::SMATCH)->compareAndSet($$new($ObjectArray, {$of(this), ($Object*)nullptr, $of(this)}));
}

bool SynchronousQueue$TransferStack$SNode::isCancelled() {
	return this->match == this;
}

bool SynchronousQueue$TransferStack$SNode::isReleasable() {
	return this->match != nullptr || $($Thread::currentThread())->isInterrupted();
}

bool SynchronousQueue$TransferStack$SNode::block() {
	while (!isReleasable()) {
		$LockSupport::park();
	}
	return true;
}

void SynchronousQueue$TransferStack$SNode::forgetWaiter() {
	$nc(SynchronousQueue$TransferStack$SNode::SWAITER)->setOpaque($$new($ObjectArray, {$of(this), ($Object*)nullptr}));
}

void clinit$SynchronousQueue$TransferStack$SNode($Class* class$) {
	$beforeCallerSensitive();
	{
		try {
			$var($MethodHandles$Lookup, l, $MethodHandles::lookup());
			$assignStatic(SynchronousQueue$TransferStack$SNode::SMATCH, $nc(l)->findVarHandle(SynchronousQueue$TransferStack$SNode::class$, "match"_s, SynchronousQueue$TransferStack$SNode::class$));
			$assignStatic(SynchronousQueue$TransferStack$SNode::SNEXT, l->findVarHandle(SynchronousQueue$TransferStack$SNode::class$, "next"_s, SynchronousQueue$TransferStack$SNode::class$));
			$assignStatic(SynchronousQueue$TransferStack$SNode::SWAITER, l->findVarHandle(SynchronousQueue$TransferStack$SNode::class$, "waiter"_s, $Thread::class$));
		} catch ($ReflectiveOperationException& e) {
			$throwNew($ExceptionInInitializerError, static_cast<$Throwable*>(e));
		}
	}
}

SynchronousQueue$TransferStack$SNode::SynchronousQueue$TransferStack$SNode() {
}

$Class* SynchronousQueue$TransferStack$SNode::load$($String* name, bool initialize) {
	$loadClass(SynchronousQueue$TransferStack$SNode, name, initialize, &_SynchronousQueue$TransferStack$SNode_ClassInfo_, clinit$SynchronousQueue$TransferStack$SNode, allocate$SynchronousQueue$TransferStack$SNode);
	return class$;
}

$Class* SynchronousQueue$TransferStack$SNode::class$ = nullptr;

		} // concurrent
	} // util
} // java