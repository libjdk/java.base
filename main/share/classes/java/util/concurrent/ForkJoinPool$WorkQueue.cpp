#include <java/util/concurrent/ForkJoinPool$WorkQueue.h>

#include <java/lang/ExceptionInInitializerError.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/Thread$State.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/VarHandle.h>
#include <java/security/AccessControlContext.h>
#include <java/security/CodeSource.h>
#include <java/security/PermissionCollection.h>
#include <java/security/ProtectionDomain.h>
#include <java/util/concurrent/CompletableFuture$AsynchronousCompletionTask.h>
#include <java/util/concurrent/CountedCompleter.h>
#include <java/util/concurrent/ForkJoinPool$ManagedBlocker.h>
#include <java/util/concurrent/ForkJoinPool.h>
#include <java/util/concurrent/ForkJoinTask.h>
#include <java/util/concurrent/ForkJoinWorkerThread.h>
#include <java/util/concurrent/RejectedExecutionException.h>
#include <java/util/concurrent/ThreadLocalRandom.h>
#include <jcpp.h>

#undef BASE
#undef BLOCKED
#undef INNOCUOUS_ACC
#undef QA
#undef SOURCE
#undef TIMED_WAITING
#undef TYPE
#undef WAITING

using $ProtectionDomainArray = $Array<::java::security::ProtectionDomain>;
using $ForkJoinTaskArray = $Array<::java::util::concurrent::ForkJoinTask>;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $ExceptionInInitializerError = ::java::lang::ExceptionInInitializerError;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NamedAttribute = ::java::lang::NamedAttribute;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $Thread$State = ::java::lang::Thread$State;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $VarHandle = ::java::lang::invoke::VarHandle;
using $AccessControlContext = ::java::security::AccessControlContext;
using $CodeSource = ::java::security::CodeSource;
using $PermissionCollection = ::java::security::PermissionCollection;
using $ProtectionDomain = ::java::security::ProtectionDomain;
using $CompletableFuture$AsynchronousCompletionTask = ::java::util::concurrent::CompletableFuture$AsynchronousCompletionTask;
using $CountedCompleter = ::java::util::concurrent::CountedCompleter;
using $ForkJoinPool = ::java::util::concurrent::ForkJoinPool;
using $ForkJoinPool$ManagedBlocker = ::java::util::concurrent::ForkJoinPool$ManagedBlocker;
using $ForkJoinTask = ::java::util::concurrent::ForkJoinTask;
using $ForkJoinWorkerThread = ::java::util::concurrent::ForkJoinWorkerThread;
using $RejectedExecutionException = ::java::util::concurrent::RejectedExecutionException;
using $ThreadLocalRandom = ::java::util::concurrent::ThreadLocalRandom;

namespace java {
	namespace util {
		namespace concurrent {

$NamedAttribute ForkJoinPool$WorkQueue_Attribute_var$0[] = {
	{"value", 's', "w"},
	{}
};

$CompoundAttribute _ForkJoinPool$WorkQueue_FieldAnnotations_top[] = {
	{"Ljdk/internal/vm/annotation/Contended;", ForkJoinPool$WorkQueue_Attribute_var$0},
	{}
};

$NamedAttribute ForkJoinPool$WorkQueue_Attribute_var$1[] = {
	{"value", 's', "w"},
	{}
};

$CompoundAttribute _ForkJoinPool$WorkQueue_FieldAnnotations_source[] = {
	{"Ljdk/internal/vm/annotation/Contended;", ForkJoinPool$WorkQueue_Attribute_var$1},
	{}
};

$NamedAttribute ForkJoinPool$WorkQueue_Attribute_var$2[] = {
	{"value", 's', "w"},
	{}
};

$CompoundAttribute _ForkJoinPool$WorkQueue_FieldAnnotations_nsteals[] = {
	{"Ljdk/internal/vm/annotation/Contended;", ForkJoinPool$WorkQueue_Attribute_var$2},
	{}
};

$FieldInfo _ForkJoinPool$WorkQueue_FieldInfo_[] = {
	{"phase", "I", nullptr, $VOLATILE, $field(ForkJoinPool$WorkQueue, phase)},
	{"stackPred", "I", nullptr, 0, $field(ForkJoinPool$WorkQueue, stackPred)},
	{"config", "I", nullptr, 0, $field(ForkJoinPool$WorkQueue, config)},
	{"base", "I", nullptr, 0, $field(ForkJoinPool$WorkQueue, base)},
	{"array", "[Ljava/util/concurrent/ForkJoinTask;", "[Ljava/util/concurrent/ForkJoinTask<*>;", 0, $field(ForkJoinPool$WorkQueue, array)},
	{"owner", "Ljava/util/concurrent/ForkJoinWorkerThread;", nullptr, $FINAL, $field(ForkJoinPool$WorkQueue, owner)},
	{"top", "I", nullptr, 0, $field(ForkJoinPool$WorkQueue, top), _ForkJoinPool$WorkQueue_FieldAnnotations_top},
	{"source", "I", nullptr, $VOLATILE, $field(ForkJoinPool$WorkQueue, source), _ForkJoinPool$WorkQueue_FieldAnnotations_source},
	{"nsteals", "I", nullptr, 0, $field(ForkJoinPool$WorkQueue, nsteals), _ForkJoinPool$WorkQueue_FieldAnnotations_nsteals},
	{"QA", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ForkJoinPool$WorkQueue, QA)},
	{"SOURCE", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ForkJoinPool$WorkQueue, SOURCE)},
	{"BASE", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ForkJoinPool$WorkQueue, BASE)},
	{"INNOCUOUS_ACC", "Ljava/security/AccessControlContext;", nullptr, $PRIVATE | $STATIC, $staticField(ForkJoinPool$WorkQueue, INNOCUOUS_ACC)},
	{}
};

$MethodInfo _ForkJoinPool$WorkQueue_MethodInfo_[] = {
	{"<init>", "(Ljava/util/concurrent/ForkJoinWorkerThread;Z)V", nullptr, 0, $method(ForkJoinPool$WorkQueue, init$, void, $ForkJoinWorkerThread*, bool)},
	{"<init>", "(I)V", nullptr, 0, $method(ForkJoinPool$WorkQueue, init$, void, int32_t)},
	{"casSlotToNull", "([Ljava/util/concurrent/ForkJoinTask;ILjava/util/concurrent/ForkJoinTask;)Z", "([Ljava/util/concurrent/ForkJoinTask<*>;ILjava/util/concurrent/ForkJoinTask<*>;)Z", $STATIC | $FINAL, $staticMethod(ForkJoinPool$WorkQueue, casSlotToNull, bool, $ForkJoinTaskArray*, int32_t, $ForkJoinTask*)},
	{"externalTryUnpush", "(Ljava/util/concurrent/ForkJoinTask;)Z", "(Ljava/util/concurrent/ForkJoinTask<*>;)Z", $FINAL, $method(ForkJoinPool$WorkQueue, externalTryUnpush, bool, $ForkJoinTask*)},
	{"getAndClearSlot", "([Ljava/util/concurrent/ForkJoinTask;I)Ljava/util/concurrent/ForkJoinTask;", "([Ljava/util/concurrent/ForkJoinTask<*>;I)Ljava/util/concurrent/ForkJoinTask<*>;", $STATIC | $FINAL, $staticMethod(ForkJoinPool$WorkQueue, getAndClearSlot, $ForkJoinTask*, $ForkJoinTaskArray*, int32_t)},
	{"getPoolIndex", "()I", nullptr, $FINAL, $method(ForkJoinPool$WorkQueue, getPoolIndex, int32_t)},
	{"getSlot", "([Ljava/util/concurrent/ForkJoinTask;I)Ljava/util/concurrent/ForkJoinTask;", "([Ljava/util/concurrent/ForkJoinTask<*>;I)Ljava/util/concurrent/ForkJoinTask<*>;", $STATIC | $FINAL, $staticMethod(ForkJoinPool$WorkQueue, getSlot, $ForkJoinTask*, $ForkJoinTaskArray*, int32_t)},
	{"growArray", "()V", nullptr, $FINAL, $method(ForkJoinPool$WorkQueue, growArray, void)},
	{"helpAsyncBlocker", "(Ljava/util/concurrent/ForkJoinPool$ManagedBlocker;)V", nullptr, $FINAL, $method(ForkJoinPool$WorkQueue, helpAsyncBlocker, void, $ForkJoinPool$ManagedBlocker*)},
	{"helpComplete", "(Ljava/util/concurrent/ForkJoinTask;ZI)I", "(Ljava/util/concurrent/ForkJoinTask<*>;ZI)I", $FINAL, $method(ForkJoinPool$WorkQueue, helpComplete, int32_t, $ForkJoinTask*, bool, int32_t)},
	{"initializeInnocuousWorker", "()V", nullptr, $FINAL, $method(ForkJoinPool$WorkQueue, initializeInnocuousWorker, void)},
	{"isApparentlyUnblocked", "()Z", nullptr, $FINAL, $method(ForkJoinPool$WorkQueue, isApparentlyUnblocked, bool)},
	{"isEmpty", "()Z", nullptr, $FINAL, $method(ForkJoinPool$WorkQueue, isEmpty, bool)},
	{"lockedPush", "(Ljava/util/concurrent/ForkJoinTask;)Z", "(Ljava/util/concurrent/ForkJoinTask<*>;)Z", $FINAL, $method(ForkJoinPool$WorkQueue, lockedPush, bool, $ForkJoinTask*)},
	{"nextLocalTask", "(I)Ljava/util/concurrent/ForkJoinTask;", "(I)Ljava/util/concurrent/ForkJoinTask<*>;", $FINAL, $method(ForkJoinPool$WorkQueue, nextLocalTask, $ForkJoinTask*, int32_t)},
	{"nextLocalTask", "()Ljava/util/concurrent/ForkJoinTask;", "()Ljava/util/concurrent/ForkJoinTask<*>;", $FINAL, $method(ForkJoinPool$WorkQueue, nextLocalTask, $ForkJoinTask*)},
	{"peek", "()Ljava/util/concurrent/ForkJoinTask;", "()Ljava/util/concurrent/ForkJoinTask<*>;", $FINAL, $method(ForkJoinPool$WorkQueue, peek, $ForkJoinTask*)},
	{"pop", "()Ljava/util/concurrent/ForkJoinTask;", "()Ljava/util/concurrent/ForkJoinTask<*>;", $PRIVATE, $method(ForkJoinPool$WorkQueue, pop, $ForkJoinTask*)},
	{"push", "(Ljava/util/concurrent/ForkJoinTask;Ljava/util/concurrent/ForkJoinPool;)V", "(Ljava/util/concurrent/ForkJoinTask<*>;Ljava/util/concurrent/ForkJoinPool;)V", $FINAL, $method(ForkJoinPool$WorkQueue, push, void, $ForkJoinTask*, $ForkJoinPool*)},
	{"queueSize", "()I", nullptr, $FINAL, $method(ForkJoinPool$WorkQueue, queueSize, int32_t)},
	{"setBaseOpaque", "(I)V", nullptr, $FINAL, $method(ForkJoinPool$WorkQueue, setBaseOpaque, void, int32_t)},
	{"setSlotVolatile", "([Ljava/util/concurrent/ForkJoinTask;ILjava/util/concurrent/ForkJoinTask;)V", "([Ljava/util/concurrent/ForkJoinTask<*>;ILjava/util/concurrent/ForkJoinTask<*>;)V", $STATIC | $FINAL, $staticMethod(ForkJoinPool$WorkQueue, setSlotVolatile, void, $ForkJoinTaskArray*, int32_t, $ForkJoinTask*)},
	{"topLevelExec", "(Ljava/util/concurrent/ForkJoinTask;Ljava/util/concurrent/ForkJoinPool$WorkQueue;)V", "(Ljava/util/concurrent/ForkJoinTask<*>;Ljava/util/concurrent/ForkJoinPool$WorkQueue;)V", $FINAL, $method(ForkJoinPool$WorkQueue, topLevelExec, void, $ForkJoinTask*, ForkJoinPool$WorkQueue*)},
	{"tryLock", "()Z", nullptr, $FINAL, $method(ForkJoinPool$WorkQueue, tryLock, bool)},
	{"tryPoll", "()Ljava/util/concurrent/ForkJoinTask;", "()Ljava/util/concurrent/ForkJoinTask<*>;", $FINAL, $method(ForkJoinPool$WorkQueue, tryPoll, $ForkJoinTask*)},
	{"tryRemove", "(Ljava/util/concurrent/ForkJoinTask;Z)Z", "(Ljava/util/concurrent/ForkJoinTask<*>;Z)Z", $FINAL, $method(ForkJoinPool$WorkQueue, tryRemove, bool, $ForkJoinTask*, bool)},
	{"tryUnpush", "(Ljava/util/concurrent/ForkJoinTask;)Z", "(Ljava/util/concurrent/ForkJoinTask<*>;)Z", $FINAL, $method(ForkJoinPool$WorkQueue, tryUnpush, bool, $ForkJoinTask*)},
	{}
};

$InnerClassInfo _ForkJoinPool$WorkQueue_InnerClassesInfo_[] = {
	{"java.util.concurrent.ForkJoinPool$WorkQueue", "java.util.concurrent.ForkJoinPool", "WorkQueue", $STATIC | $FINAL},
	{}
};

$ClassInfo _ForkJoinPool$WorkQueue_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.concurrent.ForkJoinPool$WorkQueue",
	"java.lang.Object",
	nullptr,
	_ForkJoinPool$WorkQueue_FieldInfo_,
	_ForkJoinPool$WorkQueue_MethodInfo_,
	nullptr,
	nullptr,
	_ForkJoinPool$WorkQueue_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.concurrent.ForkJoinPool"
};

$Object* allocate$ForkJoinPool$WorkQueue($Class* clazz) {
	return $of($alloc(ForkJoinPool$WorkQueue));
}

$VarHandle* ForkJoinPool$WorkQueue::QA = nullptr;
$VarHandle* ForkJoinPool$WorkQueue::SOURCE = nullptr;
$VarHandle* ForkJoinPool$WorkQueue::BASE = nullptr;
$AccessControlContext* ForkJoinPool$WorkQueue::INNOCUOUS_ACC = nullptr;

$ForkJoinTask* ForkJoinPool$WorkQueue::getSlot($ForkJoinTaskArray* a, int32_t i) {
	$init(ForkJoinPool$WorkQueue);
	return $cast($ForkJoinTask, $nc(ForkJoinPool$WorkQueue::QA)->getAcquire($$new($ObjectArray, {$of(a), $$of(i)})));
}

$ForkJoinTask* ForkJoinPool$WorkQueue::getAndClearSlot($ForkJoinTaskArray* a, int32_t i) {
	$init(ForkJoinPool$WorkQueue);
	return $cast($ForkJoinTask, $nc(ForkJoinPool$WorkQueue::QA)->getAndSet($$new($ObjectArray, {$of(a), $$of(i), ($Object*)nullptr})));
}

void ForkJoinPool$WorkQueue::setSlotVolatile($ForkJoinTaskArray* a, int32_t i, $ForkJoinTask* v) {
	$init(ForkJoinPool$WorkQueue);
	$nc(ForkJoinPool$WorkQueue::QA)->setVolatile($$new($ObjectArray, {$of(a), $$of(i), $of(v)}));
}

bool ForkJoinPool$WorkQueue::casSlotToNull($ForkJoinTaskArray* a, int32_t i, $ForkJoinTask* c) {
	$init(ForkJoinPool$WorkQueue);
	return $nc(ForkJoinPool$WorkQueue::QA)->compareAndSet($$new($ObjectArray, {$of(a), $$of(i), $of(c), ($Object*)nullptr}));
}

bool ForkJoinPool$WorkQueue::tryLock() {
	return $nc(ForkJoinPool$WorkQueue::SOURCE)->compareAndSet($$new($ObjectArray, {$of(this), $$of(0), $$of(1)}));
}

void ForkJoinPool$WorkQueue::setBaseOpaque(int32_t b) {
	$nc(ForkJoinPool$WorkQueue::BASE)->setOpaque($$new($ObjectArray, {$of(this), $$of(b)}));
}

void ForkJoinPool$WorkQueue::init$($ForkJoinWorkerThread* owner, bool isInnocuous) {
	this->config = (isInnocuous) ? 0x00040000 : 0;
	$set(this, owner, owner);
}

void ForkJoinPool$WorkQueue::init$(int32_t config) {
	$set(this, array, $new($ForkJoinTaskArray, 256));
	this->config = config;
	$set(this, owner, nullptr);
	this->phase = -1;
}

int32_t ForkJoinPool$WorkQueue::getPoolIndex() {
	return (int32_t)((uint32_t)((int32_t)(this->config & (uint32_t)0x0000FFFF)) >> 1);
}

int32_t ForkJoinPool$WorkQueue::queueSize() {
	$VarHandle::acquireFence();
	int32_t n = this->top - this->base;
	return (n < 0) ? 0 : n;
}

bool ForkJoinPool$WorkQueue::isEmpty() {
	return !((this->source != 0 && this->owner == nullptr) || this->top - this->base > 0);
}

void ForkJoinPool$WorkQueue::push($ForkJoinTask* task, $ForkJoinPool* pool) {
	$var($ForkJoinTaskArray, a, this->array);
	int32_t s = this->top++;
	int32_t d = s - this->base;
	int32_t cap = 0;
	int32_t m = 0;
	if (a != nullptr && pool != nullptr && (cap = a->length) > 0) {
		setSlotVolatile(a, (int32_t)((m = cap - 1) & (uint32_t)s), task);
		if (d == m) {
			growArray();
		}
		if (d == m || a->get((int32_t)(m & (uint32_t)(s - 1))) == nullptr) {
			pool->signalWork();
		}
	}
}

bool ForkJoinPool$WorkQueue::lockedPush($ForkJoinTask* task) {
	$var($ForkJoinTaskArray, a, this->array);
	int32_t s = this->top++;
	int32_t d = s - this->base;
	int32_t cap = 0;
	int32_t m = 0;
	if (a != nullptr && (cap = a->length) > 0) {
		a->set((int32_t)((m = cap - 1) & (uint32_t)s), task);
		if (d == m) {
			growArray();
		}
		this->source = 0;
		if (d == m || a->get((int32_t)(m & (uint32_t)(s - 1))) == nullptr) {
			return true;
		}
	}
	return false;
}

void ForkJoinPool$WorkQueue::growArray() {
	$useLocalCurrentObjectStackCache();
	$var($ForkJoinTaskArray, oldArray, this->array);
	$var($ForkJoinTaskArray, newArray, nullptr);
	int32_t s = this->top - 1;
	int32_t oldCap = 0;
	int32_t newCap = 0;
	bool var$0 = oldArray != nullptr && (oldCap = oldArray->length) > 0;
	if (var$0 && (newCap = oldCap << 1) > 0) {
		try {
			$assign(newArray, $new($ForkJoinTaskArray, newCap));
		} catch ($Throwable& ex) {
			this->top = s;
			if (this->owner == nullptr) {
				this->source = 0;
			}
			$throwNew($RejectedExecutionException, "Queue capacity exceeded"_s);
		}
		int32_t newMask = newCap - 1;
		int32_t oldMask = oldCap - 1;
		for (int32_t k = oldCap; k > 0; --k, --s) {
			$var($ForkJoinTask, x, nullptr);
			if (($assign(x, getAndClearSlot(oldArray, (int32_t)(s & (uint32_t)oldMask)))) == nullptr) {
				break;
			}
			$nc(newArray)->set((int32_t)(s & (uint32_t)newMask), x);
		}
		$VarHandle::releaseFence();
		$set(this, array, newArray);
	}
}

$ForkJoinTask* ForkJoinPool$WorkQueue::pop() {
	$useLocalCurrentObjectStackCache();
	$var($ForkJoinTask, t, nullptr);
	int32_t s = this->top;
	int32_t cap = 0;
	$var($ForkJoinTaskArray, a, nullptr);
	bool var$1 = ($assign(a, this->array)) != nullptr;
	bool var$0 = var$1 && (cap = $nc(a)->length) > 0 && this->base != s--;
	if (var$0 && ($assign(t, getAndClearSlot(a, (int32_t)((cap - 1) & (uint32_t)s)))) != nullptr) {
		this->top = s;
	}
	return t;
}

bool ForkJoinPool$WorkQueue::tryUnpush($ForkJoinTask* task) {
	int32_t s = this->top;
	int32_t cap = 0;
	$var($ForkJoinTaskArray, a, nullptr);
	bool var$1 = ($assign(a, this->array)) != nullptr;
	bool var$0 = var$1 && (cap = $nc(a)->length) > 0 && this->base != s--;
	if (var$0 && casSlotToNull(a, (int32_t)((cap - 1) & (uint32_t)s), task)) {
		this->top = s;
		return true;
	}
	return false;
}

bool ForkJoinPool$WorkQueue::externalTryUnpush($ForkJoinTask* task) {
	$useLocalCurrentObjectStackCache();
	bool taken = false;
	for (;;) {
		int32_t s = this->top;
		int32_t cap = 0;
		int32_t k = 0;
		$var($ForkJoinTaskArray, a, nullptr);
		bool var$1 = ($assign(a, this->array)) == nullptr;
		bool var$0 = var$1 || (cap = $nc(a)->length) <= 0;
		if (var$0 || $nc(a)->get(k = (int32_t)((cap - 1) & (uint32_t)(s - 1))) != task) {
			break;
		}
		if (tryLock()) {
			if (this->top == s && this->array == a) {
				if (taken = casSlotToNull(a, k, task)) {
					this->top = s - 1;
					this->source = 0;
					break;
				}
			}
			this->source = 0;
		}
		$Thread::yield();
	}
	return taken;
}

bool ForkJoinPool$WorkQueue::tryRemove($ForkJoinTask* task, bool owned) {
	$useLocalCurrentObjectStackCache();
	bool taken = false;
	int32_t p = this->top;
	int32_t cap = 0;
	$var($ForkJoinTaskArray, a, nullptr);
	$var($ForkJoinTask, t, nullptr);
	bool var$0 = ($assign(a, this->array)) != nullptr && task != nullptr;
	if (var$0 && (cap = $nc(a)->length) > 0) {
		int32_t m = cap - 1;
		int32_t s = p - 1;
		int32_t d = p - this->base;
		{
			int32_t i = s;
			int32_t k = 0;
			for (; d > 0; --i, --d) {
				if (($assign(t, a->get(k = (int32_t)(i & (uint32_t)m)))) == task) {
					if (owned || tryLock()) {
						if ((owned || (this->array == a && this->top == p)) && (taken = casSlotToNull(a, k, t))) {
							for (int32_t j = i; j != s;) {
								a->set((int32_t)(j & (uint32_t)m), $(getAndClearSlot(a, (int32_t)(++j & (uint32_t)m))));
							}
							this->top = s;
						}
						if (!owned) {
							this->source = 0;
						}
					}
					break;
				}
			}
		}
	}
	return taken;
}

$ForkJoinTask* ForkJoinPool$WorkQueue::tryPoll() {
	$useLocalCurrentObjectStackCache();
	int32_t cap = 0;
	int32_t b = 0;
	int32_t k = 0;
	$var($ForkJoinTaskArray, a, nullptr);
	bool var$0 = ($assign(a, this->array)) != nullptr;
	if (var$0 && (cap = $nc(a)->length) > 0) {
		$var($ForkJoinTask, t, getSlot(a, k = (int32_t)((cap - 1) & (uint32_t)(b = this->base))));
		if (this->base == b++ && t != nullptr && casSlotToNull(a, k, t)) {
			setBaseOpaque(b);
			return t;
		}
	}
	return nullptr;
}

$ForkJoinTask* ForkJoinPool$WorkQueue::nextLocalTask(int32_t cfg) {
	$useLocalCurrentObjectStackCache();
	$var($ForkJoinTask, t, nullptr);
	int32_t s = this->top;
	int32_t cap = 0;
	$var($ForkJoinTaskArray, a, nullptr);
	bool var$0 = ($assign(a, this->array)) != nullptr;
	if (var$0 && (cap = $nc(a)->length) > 0) {
		{
			int32_t b = 0;
			int32_t d = 0;
			for (;;) {
				if ((d = s - (b = this->base)) <= 0) {
					break;
				}
				if (d == 1 || ((int32_t)(cfg & (uint32_t)0x00010000)) == 0) {
					if (($assign(t, getAndClearSlot(a, (int32_t)(--s & (uint32_t)(cap - 1))))) != nullptr) {
						this->top = s;
					}
					break;
				}
				if (($assign(t, getAndClearSlot(a, (int32_t)(b++ & (uint32_t)(cap - 1))))) != nullptr) {
					setBaseOpaque(b);
					break;
				}
			}
		}
	}
	return t;
}

$ForkJoinTask* ForkJoinPool$WorkQueue::nextLocalTask() {
	return nextLocalTask(this->config);
}

$ForkJoinTask* ForkJoinPool$WorkQueue::peek() {
	$VarHandle::acquireFence();
	int32_t cap = 0;
	$var($ForkJoinTaskArray, a, nullptr);
	bool var$0 = ($assign(a, this->array)) != nullptr;
	return (var$0 && (cap = $nc(a)->length) > 0) ? $nc(a)->get((int32_t)((cap - 1) & (uint32_t)(((int32_t)(this->config & (uint32_t)0x00010000)) != 0 ? this->base : this->top - 1))) : ($ForkJoinTask*)nullptr;
}

void ForkJoinPool$WorkQueue::topLevelExec($ForkJoinTask* task$renamed, ForkJoinPool$WorkQueue* q) {
	$useLocalCurrentObjectStackCache();
	$var($ForkJoinTask, task, task$renamed);
	int32_t cfg = this->config;
	int32_t nstolen = 1;
	while (task != nullptr) {
		task->doExec();
		bool var$0 = ($assign(task, nextLocalTask(cfg))) == nullptr && q != nullptr;
		if (var$0 && ($assign(task, q->tryPoll())) != nullptr) {
			++nstolen;
		}
	}
	this->nsteals += nstolen;
	this->source = 0;
	if (((int32_t)(cfg & (uint32_t)0x00040000)) != 0) {
		$ThreadLocalRandom::eraseThreadLocals($($Thread::currentThread()));
	}
}

int32_t ForkJoinPool$WorkQueue::helpComplete($ForkJoinTask* task, bool owned, int32_t limit) {
	$useLocalCurrentObjectStackCache();
	int32_t status = 0;
	int32_t cap = 0;
	int32_t k = 0;
	int32_t p = 0;
	int32_t s = 0;
	$var($ForkJoinTaskArray, a, nullptr);
	$var($ForkJoinTask, t, nullptr);
	while (true) {
		bool var$1 = task != nullptr && (status = task->status) >= 0 && ($assign(a, this->array)) != nullptr;
		bool var$0 = var$1 && (cap = $nc(a)->length) > 0;
		if (!(var$0 && $instanceOf($CountedCompleter, $assign(t, a->get(k = (int32_t)((cap - 1) & (uint32_t)(s = (p = this->top) - 1))))))) {
			break;
		}
		{
			$var($CountedCompleter, f, $cast($CountedCompleter, t));
			bool taken = false;
			for (;;) {
				if ($equals(f, task)) {
					if (owned) {
						if (taken = casSlotToNull(a, k, t)) {
							this->top = s;
						}
					} else if (tryLock()) {
						if (this->top == p && this->array == a && (taken = casSlotToNull(a, k, t))) {
							this->top = s;
						}
						this->source = 0;
					}
					if (taken) {
						$nc(t)->doExec();
					} else if (!owned) {
						$Thread::yield();
					}
					break;
				} else if (($assign(f, $nc(f)->completer)) == nullptr) {
					break;
				}
			}
			bool var$2 = taken && limit != 0;
			if (var$2 && --limit == 0) {
				break;
			}
		}
	}
	return status;
}

void ForkJoinPool$WorkQueue::helpAsyncBlocker($ForkJoinPool$ManagedBlocker* blocker) {
	$useLocalCurrentObjectStackCache();
	int32_t cap = 0;
	int32_t b = 0;
	int32_t d = 0;
	int32_t k = 0;
	$var($ForkJoinTaskArray, a, nullptr);
	$var($ForkJoinTask, t, nullptr);
	while (true) {
		bool var$2 = blocker != nullptr && (d = this->top - (b = this->base)) > 0 && ($assign(a, this->array)) != nullptr;
		bool var$1 = var$2 && (cap = $nc(a)->length) > 0;
		bool var$0 = var$1 && ((($assign(t, getSlot(a, k = (int32_t)((cap - 1) & (uint32_t)b)))) == nullptr && d > 1) || $instanceOf($CompletableFuture$AsynchronousCompletionTask, t));
		if (!(var$0 && !$nc(blocker)->isReleasable())) {
			break;
		}
		{
			if (t != nullptr && this->base == b++ && casSlotToNull(a, k, t)) {
				setBaseOpaque(b);
				t->doExec();
			}
		}
	}
}

void ForkJoinPool$WorkQueue::initializeInnocuousWorker() {
	$useLocalCurrentObjectStackCache();
	$var($AccessControlContext, acc, nullptr);
	if (($assign(acc, ForkJoinPool$WorkQueue::INNOCUOUS_ACC)) == nullptr) {
		$assignStatic(ForkJoinPool$WorkQueue::INNOCUOUS_ACC, ($assign(acc, $new($AccessControlContext, $$new($ProtectionDomainArray, {$$new($ProtectionDomain, nullptr, nullptr)})))));
	}
	$var($Thread, t, $Thread::currentThread());
	$ThreadLocalRandom::setInheritedAccessControlContext(t, acc);
	$ThreadLocalRandom::eraseThreadLocals(t);
}

bool ForkJoinPool$WorkQueue::isApparentlyUnblocked() {
	$var($Thread, wt, nullptr);
	$Thread$State* s = nullptr;
	bool var$2 = ($assign(wt, this->owner)) != nullptr;
	$init($Thread$State);
	bool var$1 = var$2 && (s = $nc(wt)->getState()) != $Thread$State::BLOCKED;
	bool var$0 = var$1 && s != $Thread$State::WAITING;
	return (var$0 && s != $Thread$State::TIMED_WAITING);
}

void clinit$ForkJoinPool$WorkQueue($Class* class$) {
	$beforeCallerSensitive();
	{
		try {
			$load($ForkJoinTaskArray);
			$assignStatic(ForkJoinPool$WorkQueue::QA, $MethodHandles::arrayElementVarHandle($getClass($ForkJoinTaskArray)));
			$var($MethodHandles$Lookup, l, $MethodHandles::lookup());
			$init($Integer);
			$assignStatic(ForkJoinPool$WorkQueue::SOURCE, $nc(l)->findVarHandle(ForkJoinPool$WorkQueue::class$, "source"_s, $Integer::TYPE));
			$assignStatic(ForkJoinPool$WorkQueue::BASE, l->findVarHandle(ForkJoinPool$WorkQueue::class$, "base"_s, $Integer::TYPE));
		} catch ($ReflectiveOperationException& e) {
			$throwNew($ExceptionInInitializerError, static_cast<$Throwable*>(e));
		}
	}
}

ForkJoinPool$WorkQueue::ForkJoinPool$WorkQueue() {
}

$Class* ForkJoinPool$WorkQueue::load$($String* name, bool initialize) {
	$loadClass(ForkJoinPool$WorkQueue, name, initialize, &_ForkJoinPool$WorkQueue_ClassInfo_, clinit$ForkJoinPool$WorkQueue, allocate$ForkJoinPool$WorkQueue);
	return class$;
}

$Class* ForkJoinPool$WorkQueue::class$ = nullptr;

		} // concurrent
	} // util
} // java