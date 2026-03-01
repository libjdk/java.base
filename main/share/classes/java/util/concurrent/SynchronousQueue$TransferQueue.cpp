#include <java/util/concurrent/SynchronousQueue$TransferQueue.h>

#include <java/lang/ExceptionInInitializerError.h>
#include <java/lang/InterruptedException.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/VarHandle.h>
#include <java/util/concurrent/ForkJoinPool$ManagedBlocker.h>
#include <java/util/concurrent/ForkJoinPool.h>
#include <java/util/concurrent/SynchronousQueue$TransferQueue$QNode.h>
#include <java/util/concurrent/SynchronousQueue$Transferer.h>
#include <java/util/concurrent/SynchronousQueue.h>
#include <java/util/concurrent/locks/LockSupport.h>
#include <jcpp.h>

#undef QCLEANME
#undef QHEAD
#undef QTAIL

using $ClassInfo = ::java::lang::ClassInfo;
using $ExceptionInInitializerError = ::java::lang::ExceptionInInitializerError;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InterruptedException = ::java::lang::InterruptedException;
using $MethodInfo = ::java::lang::MethodInfo;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $VarHandle = ::java::lang::invoke::VarHandle;
using $ForkJoinPool = ::java::util::concurrent::ForkJoinPool;
using $ForkJoinPool$ManagedBlocker = ::java::util::concurrent::ForkJoinPool$ManagedBlocker;
using $SynchronousQueue$TransferQueue$QNode = ::java::util::concurrent::SynchronousQueue$TransferQueue$QNode;
using $SynchronousQueue$Transferer = ::java::util::concurrent::SynchronousQueue$Transferer;
using $LockSupport = ::java::util::concurrent::locks::LockSupport;

namespace java {
	namespace util {
		namespace concurrent {

$FieldInfo _SynchronousQueue$TransferQueue_FieldInfo_[] = {
	{"head", "Ljava/util/concurrent/SynchronousQueue$TransferQueue$QNode;", nullptr, $VOLATILE | $TRANSIENT, $field(SynchronousQueue$TransferQueue, head)},
	{"tail", "Ljava/util/concurrent/SynchronousQueue$TransferQueue$QNode;", nullptr, $VOLATILE | $TRANSIENT, $field(SynchronousQueue$TransferQueue, tail)},
	{"cleanMe", "Ljava/util/concurrent/SynchronousQueue$TransferQueue$QNode;", nullptr, $VOLATILE | $TRANSIENT, $field(SynchronousQueue$TransferQueue, cleanMe)},
	{"QHEAD", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SynchronousQueue$TransferQueue, QHEAD)},
	{"QTAIL", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SynchronousQueue$TransferQueue, QTAIL)},
	{"QCLEANME", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SynchronousQueue$TransferQueue, QCLEANME)},
	{}
};

$MethodInfo _SynchronousQueue$TransferQueue_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(SynchronousQueue$TransferQueue, init$, void)},
	{"advanceHead", "(Ljava/util/concurrent/SynchronousQueue$TransferQueue$QNode;Ljava/util/concurrent/SynchronousQueue$TransferQueue$QNode;)V", nullptr, 0, $method(SynchronousQueue$TransferQueue, advanceHead, void, $SynchronousQueue$TransferQueue$QNode*, $SynchronousQueue$TransferQueue$QNode*)},
	{"advanceTail", "(Ljava/util/concurrent/SynchronousQueue$TransferQueue$QNode;Ljava/util/concurrent/SynchronousQueue$TransferQueue$QNode;)V", nullptr, 0, $method(SynchronousQueue$TransferQueue, advanceTail, void, $SynchronousQueue$TransferQueue$QNode*, $SynchronousQueue$TransferQueue$QNode*)},
	{"casCleanMe", "(Ljava/util/concurrent/SynchronousQueue$TransferQueue$QNode;Ljava/util/concurrent/SynchronousQueue$TransferQueue$QNode;)Z", nullptr, 0, $method(SynchronousQueue$TransferQueue, casCleanMe, bool, $SynchronousQueue$TransferQueue$QNode*, $SynchronousQueue$TransferQueue$QNode*)},
	{"clean", "(Ljava/util/concurrent/SynchronousQueue$TransferQueue$QNode;Ljava/util/concurrent/SynchronousQueue$TransferQueue$QNode;)V", nullptr, 0, $method(SynchronousQueue$TransferQueue, clean, void, $SynchronousQueue$TransferQueue$QNode*, $SynchronousQueue$TransferQueue$QNode*)},
	{"transfer", "(Ljava/lang/Object;ZJ)Ljava/lang/Object;", "(TE;ZJ)TE;", 0, $virtualMethod(SynchronousQueue$TransferQueue, transfer, $Object*, Object$*, bool, int64_t)},
	{}
};

$InnerClassInfo _SynchronousQueue$TransferQueue_InnerClassesInfo_[] = {
	{"java.util.concurrent.SynchronousQueue$TransferQueue", "java.util.concurrent.SynchronousQueue", "TransferQueue", $STATIC | $FINAL},
	{"java.util.concurrent.SynchronousQueue$Transferer", "java.util.concurrent.SynchronousQueue", "Transferer", $STATIC | $ABSTRACT},
	{"java.util.concurrent.SynchronousQueue$TransferQueue$QNode", "java.util.concurrent.SynchronousQueue$TransferQueue", "QNode", $STATIC | $FINAL},
	{}
};

$ClassInfo _SynchronousQueue$TransferQueue_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.concurrent.SynchronousQueue$TransferQueue",
	"java.util.concurrent.SynchronousQueue$Transferer",
	nullptr,
	_SynchronousQueue$TransferQueue_FieldInfo_,
	_SynchronousQueue$TransferQueue_MethodInfo_,
	"<E:Ljava/lang/Object;>Ljava/util/concurrent/SynchronousQueue$Transferer<TE;>;",
	nullptr,
	_SynchronousQueue$TransferQueue_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.concurrent.SynchronousQueue"
};

$Object* allocate$SynchronousQueue$TransferQueue($Class* clazz) {
	return $of($alloc(SynchronousQueue$TransferQueue));
}

$VarHandle* SynchronousQueue$TransferQueue::QHEAD = nullptr;
$VarHandle* SynchronousQueue$TransferQueue::QTAIL = nullptr;
$VarHandle* SynchronousQueue$TransferQueue::QCLEANME = nullptr;

void SynchronousQueue$TransferQueue::init$() {
	$SynchronousQueue$Transferer::init$();
	$var($SynchronousQueue$TransferQueue$QNode, h, $new($SynchronousQueue$TransferQueue$QNode, nullptr, false));
	$set(this, head, h);
	$set(this, tail, h);
}

void SynchronousQueue$TransferQueue::advanceHead($SynchronousQueue$TransferQueue$QNode* h, $SynchronousQueue$TransferQueue$QNode* nh) {
	if (h == this->head && $nc(SynchronousQueue$TransferQueue::QHEAD)->compareAndSet($$new($ObjectArray, {$of(this), $of(h), $of(nh)}))) {
		$set($nc(h), next, h);
	}
}

void SynchronousQueue$TransferQueue::advanceTail($SynchronousQueue$TransferQueue$QNode* t, $SynchronousQueue$TransferQueue$QNode* nt) {
	if (this->tail == t) {
		$nc(SynchronousQueue$TransferQueue::QTAIL)->compareAndSet($$new($ObjectArray, {$of(this), $of(t), $of(nt)}));
	}
}

bool SynchronousQueue$TransferQueue::casCleanMe($SynchronousQueue$TransferQueue$QNode* cmp, $SynchronousQueue$TransferQueue$QNode* val) {
	return this->cleanMe == cmp && $nc(SynchronousQueue$TransferQueue::QCLEANME)->compareAndSet($$new($ObjectArray, {$of(this), $of(cmp), $of(val)}));
}

$Object* SynchronousQueue$TransferQueue::transfer(Object$* e, bool timed, int64_t nanos) {
	$useLocalCurrentObjectStackCache();
	$var($SynchronousQueue$TransferQueue$QNode, s, nullptr);
	bool isData = (e != nullptr);
	for (;;) {
		$var($SynchronousQueue$TransferQueue$QNode, t, this->tail);
		$var($SynchronousQueue$TransferQueue$QNode, h, this->head);
		$var($SynchronousQueue$TransferQueue$QNode, m, nullptr);
		$var($SynchronousQueue$TransferQueue$QNode, tn, nullptr);
		if (t == nullptr || h == nullptr) {
		} else if (h == t || $nc(t)->isData == isData) {
			if (t != this->tail) {
			} else if (($assign(tn, t->next)) != nullptr) {
				advanceTail(t, tn);
			} else if (timed && nanos <= (int64_t)0) {
				return $of(nullptr);
			} else if (t->casNext(nullptr, (s != nullptr) ? s : ($assign(s, $new($SynchronousQueue$TransferQueue$QNode, e, isData))))) {
				advanceTail(t, s);
				int64_t deadline = timed ? $System::nanoTime() + nanos : (int64_t)0;
				$var($Thread, w, $Thread::currentThread());
				int32_t stat = -1;
				$var($Object, item, nullptr);
				while ($equals($assign(item, $nc(s)->item), e)) {
					bool var$0 = (timed && (nanos = deadline - $System::nanoTime()) <= 0);
					if (var$0 || w->isInterrupted()) {
						if (s->tryCancel(e)) {
							clean(t, s);
							return $of(nullptr);
						}
					} else if (!$equals($assign(item, s->item), e)) {
						break;
					} else if (stat <= 0) {
						if (t->next == s) {
							if (stat < 0 && t->isFulfilled()) {
								stat = 0;
								$Thread::yield();
							} else {
								stat = 1;
								$set(s, waiter, w);
							}
						}
					} else if (!timed) {
						$LockSupport::setCurrentBlocker(this);
						try {
							$ForkJoinPool::managedBlock(s);
						} catch ($InterruptedException& cannotHappen) {
						}
						$LockSupport::setCurrentBlocker(nullptr);
					} else if (nanos > (int64_t)1023) {
						$LockSupport::parkNanos(this, nanos);
					}
				}
				if (stat == 1) {
					$nc(s)->forgetWaiter();
				}
				if (!$nc(s)->isOffList()) {
					advanceHead(t, s);
					if (item != nullptr) {
						$set(s, item, s);
					}
				}
				return $of((item != nullptr) ? item : $of(e));
			}
		} else if (($assign(m, $nc(h)->next)) != nullptr && t == this->tail && h == this->head) {
			$var($Thread, waiter, nullptr);
			$var($Object, x, $nc(m)->item);
			bool fulfilled = ((isData == (x == nullptr)) && !$equals(x, m) && m->casItem(x, e));
			advanceHead(h, m);
			if (fulfilled) {
				if (($assign(waiter, m->waiter)) != nullptr) {
					$LockSupport::unpark(waiter);
				}
				return $of((x != nullptr) ? x : $of(e));
			}
		}
	}
}

void SynchronousQueue$TransferQueue::clean($SynchronousQueue$TransferQueue$QNode* pred, $SynchronousQueue$TransferQueue$QNode* s) {
	$useLocalCurrentObjectStackCache();
	$nc(s)->forgetWaiter();
	while ($nc(pred)->next == s) {
		$var($SynchronousQueue$TransferQueue$QNode, h, this->head);
		$var($SynchronousQueue$TransferQueue$QNode, hn, $nc(h)->next);
		if (hn != nullptr && hn->isCancelled()) {
			advanceHead(h, hn);
			continue;
		}
		$var($SynchronousQueue$TransferQueue$QNode, t, this->tail);
		if (t == h) {
			return;
		}
		$var($SynchronousQueue$TransferQueue$QNode, tn, $nc(t)->next);
		if (t != this->tail) {
			continue;
		}
		if (tn != nullptr) {
			advanceTail(t, tn);
			continue;
		}
		if (s != t) {
			$var($SynchronousQueue$TransferQueue$QNode, sn, s->next);
			if (sn == s || pred->casNext(s, sn)) {
				return;
			}
		}
		$var($SynchronousQueue$TransferQueue$QNode, dp, this->cleanMe);
		if (dp != nullptr) {
			$var($SynchronousQueue$TransferQueue$QNode, d, dp->next);
			$var($SynchronousQueue$TransferQueue$QNode, dn, nullptr);
			bool var$0 = d == nullptr || d == dp || !$nc(d)->isCancelled();
			if (!var$0) {
				bool var$2 = d != t && ($assign(dn, $nc(d)->next)) != nullptr;
				bool var$1 = var$2 && dn != d;
				var$0 = (var$1 && dp->casNext(d, dn));
			}
			if (var$0) {
				casCleanMe(dp, nullptr);
			}
			if (dp == pred) {
				return;
			}
		} else if (casCleanMe(nullptr, pred)) {
			return;
		}
	}
}

void clinit$SynchronousQueue$TransferQueue($Class* class$) {
	$beforeCallerSensitive();
	{
		try {
			$var($MethodHandles$Lookup, l, $MethodHandles::lookup());
			$load($SynchronousQueue$TransferQueue$QNode);
			$assignStatic(SynchronousQueue$TransferQueue::QHEAD, $nc(l)->findVarHandle(SynchronousQueue$TransferQueue::class$, "head"_s, $SynchronousQueue$TransferQueue$QNode::class$));
			$assignStatic(SynchronousQueue$TransferQueue::QTAIL, l->findVarHandle(SynchronousQueue$TransferQueue::class$, "tail"_s, $SynchronousQueue$TransferQueue$QNode::class$));
			$assignStatic(SynchronousQueue$TransferQueue::QCLEANME, l->findVarHandle(SynchronousQueue$TransferQueue::class$, "cleanMe"_s, $SynchronousQueue$TransferQueue$QNode::class$));
		} catch ($ReflectiveOperationException& e) {
			$throwNew($ExceptionInInitializerError, static_cast<$Throwable*>(e));
		}
	}
}

SynchronousQueue$TransferQueue::SynchronousQueue$TransferQueue() {
}

$Class* SynchronousQueue$TransferQueue::load$($String* name, bool initialize) {
	$loadClass(SynchronousQueue$TransferQueue, name, initialize, &_SynchronousQueue$TransferQueue_ClassInfo_, clinit$SynchronousQueue$TransferQueue, allocate$SynchronousQueue$TransferQueue);
	return class$;
}

$Class* SynchronousQueue$TransferQueue::class$ = nullptr;

		} // concurrent
	} // util
} // java