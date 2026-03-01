#include <java/util/concurrent/SynchronousQueue$TransferQueue$QNode.h>

#include <java/lang/ExceptionInInitializerError.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/VarHandle.h>
#include <java/util/concurrent/SynchronousQueue$TransferQueue.h>
#include <java/util/concurrent/SynchronousQueue.h>
#include <java/util/concurrent/locks/LockSupport.h>
#include <jcpp.h>

#undef QITEM
#undef QNEXT
#undef QWAITER

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

$FieldInfo _SynchronousQueue$TransferQueue$QNode_FieldInfo_[] = {
	{"next", "Ljava/util/concurrent/SynchronousQueue$TransferQueue$QNode;", nullptr, $VOLATILE, $field(SynchronousQueue$TransferQueue$QNode, next)},
	{"item", "Ljava/lang/Object;", nullptr, $VOLATILE, $field(SynchronousQueue$TransferQueue$QNode, item)},
	{"waiter", "Ljava/lang/Thread;", nullptr, $VOLATILE, $field(SynchronousQueue$TransferQueue$QNode, waiter)},
	{"isData", "Z", nullptr, $FINAL, $field(SynchronousQueue$TransferQueue$QNode, isData)},
	{"QITEM", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SynchronousQueue$TransferQueue$QNode, QITEM)},
	{"QNEXT", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SynchronousQueue$TransferQueue$QNode, QNEXT)},
	{"QWAITER", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SynchronousQueue$TransferQueue$QNode, QWAITER)},
	{}
};

$MethodInfo _SynchronousQueue$TransferQueue$QNode_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/Object;Z)V", nullptr, 0, $method(SynchronousQueue$TransferQueue$QNode, init$, void, Object$*, bool)},
	{"block", "()Z", nullptr, $PUBLIC | $FINAL, $virtualMethod(SynchronousQueue$TransferQueue$QNode, block, bool)},
	{"casItem", "(Ljava/lang/Object;Ljava/lang/Object;)Z", nullptr, 0, $method(SynchronousQueue$TransferQueue$QNode, casItem, bool, Object$*, Object$*)},
	{"casNext", "(Ljava/util/concurrent/SynchronousQueue$TransferQueue$QNode;Ljava/util/concurrent/SynchronousQueue$TransferQueue$QNode;)Z", nullptr, 0, $method(SynchronousQueue$TransferQueue$QNode, casNext, bool, SynchronousQueue$TransferQueue$QNode*, SynchronousQueue$TransferQueue$QNode*)},
	{"forgetWaiter", "()V", nullptr, 0, $method(SynchronousQueue$TransferQueue$QNode, forgetWaiter, void)},
	{"isCancelled", "()Z", nullptr, 0, $method(SynchronousQueue$TransferQueue$QNode, isCancelled, bool)},
	{"isFulfilled", "()Z", nullptr, 0, $method(SynchronousQueue$TransferQueue$QNode, isFulfilled, bool)},
	{"isOffList", "()Z", nullptr, 0, $method(SynchronousQueue$TransferQueue$QNode, isOffList, bool)},
	{"isReleasable", "()Z", nullptr, $PUBLIC | $FINAL, $virtualMethod(SynchronousQueue$TransferQueue$QNode, isReleasable, bool)},
	{"tryCancel", "(Ljava/lang/Object;)Z", nullptr, 0, $method(SynchronousQueue$TransferQueue$QNode, tryCancel, bool, Object$*)},
	{}
};

$InnerClassInfo _SynchronousQueue$TransferQueue$QNode_InnerClassesInfo_[] = {
	{"java.util.concurrent.SynchronousQueue$TransferQueue", "java.util.concurrent.SynchronousQueue", "TransferQueue", $STATIC | $FINAL},
	{"java.util.concurrent.SynchronousQueue$TransferQueue$QNode", "java.util.concurrent.SynchronousQueue$TransferQueue", "QNode", $STATIC | $FINAL},
	{"java.util.concurrent.ForkJoinPool$ManagedBlocker", "java.util.concurrent.ForkJoinPool", "ManagedBlocker", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _SynchronousQueue$TransferQueue$QNode_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.concurrent.SynchronousQueue$TransferQueue$QNode",
	"java.lang.Object",
	"java.util.concurrent.ForkJoinPool$ManagedBlocker",
	_SynchronousQueue$TransferQueue$QNode_FieldInfo_,
	_SynchronousQueue$TransferQueue$QNode_MethodInfo_,
	nullptr,
	nullptr,
	_SynchronousQueue$TransferQueue$QNode_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.concurrent.SynchronousQueue"
};

$Object* allocate$SynchronousQueue$TransferQueue$QNode($Class* clazz) {
	return $of($alloc(SynchronousQueue$TransferQueue$QNode));
}

$VarHandle* SynchronousQueue$TransferQueue$QNode::QITEM = nullptr;
$VarHandle* SynchronousQueue$TransferQueue$QNode::QNEXT = nullptr;
$VarHandle* SynchronousQueue$TransferQueue$QNode::QWAITER = nullptr;

void SynchronousQueue$TransferQueue$QNode::init$(Object$* item, bool isData) {
	$set(this, item, item);
	this->isData = isData;
}

bool SynchronousQueue$TransferQueue$QNode::casNext(SynchronousQueue$TransferQueue$QNode* cmp, SynchronousQueue$TransferQueue$QNode* val) {
	return this->next == cmp && $nc(SynchronousQueue$TransferQueue$QNode::QNEXT)->compareAndSet($$new($ObjectArray, {$of(this), $of(cmp), $of(val)}));
}

bool SynchronousQueue$TransferQueue$QNode::casItem(Object$* cmp, Object$* val) {
	return $equals(this->item, cmp) && $nc(SynchronousQueue$TransferQueue$QNode::QITEM)->compareAndSet($$new($ObjectArray, {$of(this), cmp, val}));
}

bool SynchronousQueue$TransferQueue$QNode::tryCancel(Object$* cmp) {
	return $nc(SynchronousQueue$TransferQueue$QNode::QITEM)->compareAndSet($$new($ObjectArray, {$of(this), cmp, $of(this)}));
}

bool SynchronousQueue$TransferQueue$QNode::isCancelled() {
	return $equals(this->item, this);
}

bool SynchronousQueue$TransferQueue$QNode::isOffList() {
	return this->next == this;
}

void SynchronousQueue$TransferQueue$QNode::forgetWaiter() {
	$nc(SynchronousQueue$TransferQueue$QNode::QWAITER)->setOpaque($$new($ObjectArray, {$of(this), ($Object*)nullptr}));
}

bool SynchronousQueue$TransferQueue$QNode::isFulfilled() {
	$var($Object, x, nullptr);
	bool var$0 = this->isData == (($assign(x, this->item)) == nullptr);
	return var$0 || $equals(x, this);
}

bool SynchronousQueue$TransferQueue$QNode::isReleasable() {
	$useLocalCurrentObjectStackCache();
	$var($Object, x, nullptr);
	bool var$0 = this->isData == (($assign(x, this->item)) == nullptr);
	return var$0 || $equals(x, this) || $($Thread::currentThread())->isInterrupted();
}

bool SynchronousQueue$TransferQueue$QNode::block() {
	while (!isReleasable()) {
		$LockSupport::park();
	}
	return true;
}

void clinit$SynchronousQueue$TransferQueue$QNode($Class* class$) {
	$beforeCallerSensitive();
	{
		try {
			$var($MethodHandles$Lookup, l, $MethodHandles::lookup());
			$assignStatic(SynchronousQueue$TransferQueue$QNode::QITEM, $nc(l)->findVarHandle(SynchronousQueue$TransferQueue$QNode::class$, "item"_s, $Object::class$));
			$assignStatic(SynchronousQueue$TransferQueue$QNode::QNEXT, l->findVarHandle(SynchronousQueue$TransferQueue$QNode::class$, "next"_s, SynchronousQueue$TransferQueue$QNode::class$));
			$assignStatic(SynchronousQueue$TransferQueue$QNode::QWAITER, l->findVarHandle(SynchronousQueue$TransferQueue$QNode::class$, "waiter"_s, $Thread::class$));
		} catch ($ReflectiveOperationException& e) {
			$throwNew($ExceptionInInitializerError, static_cast<$Throwable*>(e));
		}
	}
}

SynchronousQueue$TransferQueue$QNode::SynchronousQueue$TransferQueue$QNode() {
}

$Class* SynchronousQueue$TransferQueue$QNode::load$($String* name, bool initialize) {
	$loadClass(SynchronousQueue$TransferQueue$QNode, name, initialize, &_SynchronousQueue$TransferQueue$QNode_ClassInfo_, clinit$SynchronousQueue$TransferQueue$QNode, allocate$SynchronousQueue$TransferQueue$QNode);
	return class$;
}

$Class* SynchronousQueue$TransferQueue$QNode::class$ = nullptr;

		} // concurrent
	} // util
} // java