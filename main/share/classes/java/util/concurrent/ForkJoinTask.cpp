#include <java/util/concurrent/ForkJoinTask.h>

#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream.h>
#include <java/lang/Error.h>
#include <java/lang/ExceptionInInitializerError.h>
#include <java/lang/InterruptedException.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/Runnable.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/VarHandle.h>
#include <java/lang/reflect/Constructor.h>
#include <java/util/Collection.h>
#include <java/util/List.h>
#include <java/util/RandomAccess.h>
#include <java/util/concurrent/Callable.h>
#include <java/util/concurrent/CancellationException.h>
#include <java/util/concurrent/CountedCompleter.h>
#include <java/util/concurrent/ExecutionException.h>
#include <java/util/concurrent/ForkJoinPool$WorkQueue.h>
#include <java/util/concurrent/ForkJoinPool.h>
#include <java/util/concurrent/ForkJoinTask$AdaptedCallable.h>
#include <java/util/concurrent/ForkJoinTask$AdaptedInterruptibleCallable.h>
#include <java/util/concurrent/ForkJoinTask$AdaptedRunnable.h>
#include <java/util/concurrent/ForkJoinTask$AdaptedRunnableAction.h>
#include <java/util/concurrent/ForkJoinTask$Aux.h>
#include <java/util/concurrent/ForkJoinWorkerThread.h>
#include <java/util/concurrent/Future.h>
#include <java/util/concurrent/TimeUnit.h>
#include <java/util/concurrent/TimeoutException.h>
#include <java/util/concurrent/locks/LockSupport.h>
#include <jcpp.h>

#undef ABNORMAL
#undef AUX
#undef DONE
#undef MAX_VALUE
#undef SMASK
#undef STATUS
#undef THROWN
#undef TYPE
#undef UNCOMPENSATE

using $ConstructorArray = $Array<::java::lang::reflect::Constructor>;
using $ForkJoinTaskArray = $Array<::java::util::concurrent::ForkJoinTask>;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Error = ::java::lang::Error;
using $Exception = ::java::lang::Exception;
using $ExceptionInInitializerError = ::java::lang::ExceptionInInitializerError;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InterruptedException = ::java::lang::InterruptedException;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $Runnable = ::java::lang::Runnable;
using $RuntimeException = ::java::lang::RuntimeException;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $VarHandle = ::java::lang::invoke::VarHandle;
using $Constructor = ::java::lang::reflect::Constructor;
using $Collection = ::java::util::Collection;
using $List = ::java::util::List;
using $RandomAccess = ::java::util::RandomAccess;
using $Callable = ::java::util::concurrent::Callable;
using $CancellationException = ::java::util::concurrent::CancellationException;
using $CountedCompleter = ::java::util::concurrent::CountedCompleter;
using $ExecutionException = ::java::util::concurrent::ExecutionException;
using $ForkJoinPool = ::java::util::concurrent::ForkJoinPool;
using $ForkJoinPool$WorkQueue = ::java::util::concurrent::ForkJoinPool$WorkQueue;
using $ForkJoinTask$AdaptedCallable = ::java::util::concurrent::ForkJoinTask$AdaptedCallable;
using $ForkJoinTask$AdaptedInterruptibleCallable = ::java::util::concurrent::ForkJoinTask$AdaptedInterruptibleCallable;
using $ForkJoinTask$AdaptedRunnable = ::java::util::concurrent::ForkJoinTask$AdaptedRunnable;
using $ForkJoinTask$AdaptedRunnableAction = ::java::util::concurrent::ForkJoinTask$AdaptedRunnableAction;
using $ForkJoinTask$Aux = ::java::util::concurrent::ForkJoinTask$Aux;
using $ForkJoinWorkerThread = ::java::util::concurrent::ForkJoinWorkerThread;
using $Future = ::java::util::concurrent::Future;
using $TimeUnit = ::java::util::concurrent::TimeUnit;
using $TimeoutException = ::java::util::concurrent::TimeoutException;
using $LockSupport = ::java::util::concurrent::locks::LockSupport;

namespace java {
	namespace util {
		namespace concurrent {

$FieldInfo _ForkJoinTask_FieldInfo_[] = {
	{"DONE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ForkJoinTask, DONE)},
	{"ABNORMAL", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ForkJoinTask, ABNORMAL)},
	{"THROWN", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ForkJoinTask, THROWN)},
	{"SMASK", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ForkJoinTask, SMASK)},
	{"UNCOMPENSATE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ForkJoinTask, UNCOMPENSATE)},
	{"status", "I", nullptr, $VOLATILE, $field(ForkJoinTask, status)},
	{"aux", "Ljava/util/concurrent/ForkJoinTask$Aux;", nullptr, $PRIVATE | $VOLATILE | $TRANSIENT, $field(ForkJoinTask, aux)},
	{"STATUS", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ForkJoinTask, STATUS)},
	{"AUX", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ForkJoinTask, AUX)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ForkJoinTask, serialVersionUID)},
	{}
};

$MethodInfo _ForkJoinTask_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, $PUBLIC, $method(ForkJoinTask, init$, void)},
	{"adapt", "(Ljava/lang/Runnable;)Ljava/util/concurrent/ForkJoinTask;", "(Ljava/lang/Runnable;)Ljava/util/concurrent/ForkJoinTask<*>;", $PUBLIC | $STATIC, $staticMethod(ForkJoinTask, adapt, ForkJoinTask*, $Runnable*)},
	{"adapt", "(Ljava/lang/Runnable;Ljava/lang/Object;)Ljava/util/concurrent/ForkJoinTask;", "<T:Ljava/lang/Object;>(Ljava/lang/Runnable;TT;)Ljava/util/concurrent/ForkJoinTask<TT;>;", $PUBLIC | $STATIC, $staticMethod(ForkJoinTask, adapt, ForkJoinTask*, $Runnable*, Object$*)},
	{"adapt", "(Ljava/util/concurrent/Callable;)Ljava/util/concurrent/ForkJoinTask;", "<T:Ljava/lang/Object;>(Ljava/util/concurrent/Callable<+TT;>;)Ljava/util/concurrent/ForkJoinTask<TT;>;", $PUBLIC | $STATIC, $staticMethod(ForkJoinTask, adapt, ForkJoinTask*, $Callable*)},
	{"adaptInterruptible", "(Ljava/util/concurrent/Callable;)Ljava/util/concurrent/ForkJoinTask;", "<T:Ljava/lang/Object;>(Ljava/util/concurrent/Callable<+TT;>;)Ljava/util/concurrent/ForkJoinTask<TT;>;", $PRIVATE | $STATIC, $staticMethod(ForkJoinTask, adaptInterruptible, ForkJoinTask*, $Callable*)},
	{"awaitDone", "(Ljava/util/concurrent/ForkJoinPool;ZZZJ)I", nullptr, $PRIVATE, $method(ForkJoinTask, awaitDone, int32_t, $ForkJoinPool*, bool, bool, bool, int64_t)},
	{"awaitPoolInvoke", "(Ljava/util/concurrent/ForkJoinPool;)V", nullptr, $FINAL, $method(ForkJoinTask, awaitPoolInvoke, void, $ForkJoinPool*)},
	{"awaitPoolInvoke", "(Ljava/util/concurrent/ForkJoinPool;J)V", nullptr, $FINAL, $method(ForkJoinTask, awaitPoolInvoke, void, $ForkJoinPool*, int64_t)},
	{"cancel", "(Z)Z", nullptr, $PUBLIC, $virtualMethod(ForkJoinTask, cancel, bool, bool)},
	{"cancelIgnoringExceptions", "(Ljava/util/concurrent/Future;)V", "(Ljava/util/concurrent/Future<*>;)V", $STATIC | $FINAL, $staticMethod(ForkJoinTask, cancelIgnoringExceptions, void, $Future*)},
	{"casAux", "(Ljava/util/concurrent/ForkJoinTask$Aux;Ljava/util/concurrent/ForkJoinTask$Aux;)Z", nullptr, $PRIVATE, $method(ForkJoinTask, casAux, bool, $ForkJoinTask$Aux*, $ForkJoinTask$Aux*)},
	{"casStatus", "(II)Z", nullptr, $PRIVATE, $method(ForkJoinTask, casStatus, bool, int32_t, int32_t)},
	{"compareAndSetForkJoinTaskTag", "(SS)Z", nullptr, $PUBLIC | $FINAL, $method(ForkJoinTask, compareAndSetForkJoinTaskTag, bool, int16_t, int16_t)},
	{"complete", "(Ljava/lang/Object;)V", "(TV;)V", $PUBLIC, $virtualMethod(ForkJoinTask, complete, void, Object$*)},
	{"completeExceptionally", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC, $virtualMethod(ForkJoinTask, completeExceptionally, void, $Throwable*)},
	{"doExec", "()I", nullptr, $FINAL, $method(ForkJoinTask, doExec, int32_t)},
	{"exec", "()Z", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(ForkJoinTask, exec, bool)},
	{"fork", "()Ljava/util/concurrent/ForkJoinTask;", "()Ljava/util/concurrent/ForkJoinTask<TV;>;", $PUBLIC | $FINAL, $method(ForkJoinTask, fork, ForkJoinTask*)},
	{"get", "()Ljava/lang/Object;", "()TV;", $PUBLIC | $FINAL, $virtualMethod(ForkJoinTask, get, $Object*), "java.lang.InterruptedException,java.util.concurrent.ExecutionException"},
	{"get", "(JLjava/util/concurrent/TimeUnit;)Ljava/lang/Object;", "(JLjava/util/concurrent/TimeUnit;)TV;", $PUBLIC | $FINAL, $virtualMethod(ForkJoinTask, get, $Object*, int64_t, $TimeUnit*), "java.lang.InterruptedException,java.util.concurrent.ExecutionException,java.util.concurrent.TimeoutException"},
	{"getAndBitwiseOrStatus", "(I)I", nullptr, $PRIVATE, $method(ForkJoinTask, getAndBitwiseOrStatus, int32_t, int32_t)},
	{"getException", "(I)Ljava/lang/Throwable;", nullptr, $PRIVATE, $method(ForkJoinTask, getException, $Throwable*, int32_t)},
	{"getException", "()Ljava/lang/Throwable;", nullptr, $PUBLIC | $FINAL, $method(ForkJoinTask, getException, $Throwable*)},
	{"getForPoolInvoke", "(Ljava/util/concurrent/ForkJoinPool;)Ljava/lang/Object;", "(Ljava/util/concurrent/ForkJoinPool;)TV;", $FINAL, $method(ForkJoinTask, getForPoolInvoke, $Object*, $ForkJoinPool*), "java.lang.InterruptedException,java.util.concurrent.ExecutionException"},
	{"getForPoolInvoke", "(Ljava/util/concurrent/ForkJoinPool;J)Ljava/lang/Object;", "(Ljava/util/concurrent/ForkJoinPool;J)TV;", $FINAL, $method(ForkJoinTask, getForPoolInvoke, $Object*, $ForkJoinPool*, int64_t), "java.lang.InterruptedException,java.util.concurrent.ExecutionException,java.util.concurrent.TimeoutException"},
	{"getForkJoinTaskTag", "()S", nullptr, $PUBLIC | $FINAL, $method(ForkJoinTask, getForkJoinTaskTag, int16_t)},
	{"getPool", "()Ljava/util/concurrent/ForkJoinPool;", nullptr, $PUBLIC | $STATIC, $staticMethod(ForkJoinTask, getPool, $ForkJoinPool*)},
	{"getQueuedTaskCount", "()I", nullptr, $PUBLIC | $STATIC, $staticMethod(ForkJoinTask, getQueuedTaskCount, int32_t)},
	{"getRawResult", "()Ljava/lang/Object;", "()TV;", $PUBLIC | $ABSTRACT, $virtualMethod(ForkJoinTask, getRawResult, $Object*)},
	{"getSurplusQueuedTaskCount", "()I", nullptr, $PUBLIC | $STATIC, $staticMethod(ForkJoinTask, getSurplusQueuedTaskCount, int32_t)},
	{"getThrowableException", "()Ljava/lang/Throwable;", nullptr, $PRIVATE, $method(ForkJoinTask, getThrowableException, $Throwable*)},
	{"helpQuiesce", "()V", nullptr, $PUBLIC | $STATIC, $staticMethod(ForkJoinTask, helpQuiesce, void)},
	{"inForkJoinPool", "()Z", nullptr, $PUBLIC | $STATIC, $staticMethod(ForkJoinTask, inForkJoinPool, bool)},
	{"invoke", "()Ljava/lang/Object;", "()TV;", $PUBLIC | $FINAL, $method(ForkJoinTask, invoke, $Object*)},
	{"invokeAll", "(Ljava/util/concurrent/ForkJoinTask;Ljava/util/concurrent/ForkJoinTask;)V", "(Ljava/util/concurrent/ForkJoinTask<*>;Ljava/util/concurrent/ForkJoinTask<*>;)V", $PUBLIC | $STATIC, $staticMethod(ForkJoinTask, invokeAll, void, ForkJoinTask*, ForkJoinTask*)},
	{"invokeAll", "([Ljava/util/concurrent/ForkJoinTask;)V", "([Ljava/util/concurrent/ForkJoinTask<*>;)V", $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(ForkJoinTask, invokeAll, void, $ForkJoinTaskArray*)},
	{"invokeAll", "(Ljava/util/Collection;)Ljava/util/Collection;", "<T:Ljava/util/concurrent/ForkJoinTask<*>;>(Ljava/util/Collection<TT;>;)Ljava/util/Collection<TT;>;", $PUBLIC | $STATIC, $staticMethod(ForkJoinTask, invokeAll, $Collection*, $Collection*)},
	{"isCancelled", "()Z", nullptr, $PUBLIC | $FINAL, $virtualMethod(ForkJoinTask, isCancelled, bool)},
	{"isCompletedAbnormally", "()Z", nullptr, $PUBLIC | $FINAL, $method(ForkJoinTask, isCompletedAbnormally, bool)},
	{"isCompletedNormally", "()Z", nullptr, $PUBLIC | $FINAL, $method(ForkJoinTask, isCompletedNormally, bool)},
	{"isDone", "()Z", nullptr, $PUBLIC | $FINAL, $virtualMethod(ForkJoinTask, isDone, bool)},
	{"isExceptionalStatus", "(I)Z", nullptr, $STATIC, $staticMethod(ForkJoinTask, isExceptionalStatus, bool, int32_t)},
	{"join", "()Ljava/lang/Object;", "()TV;", $PUBLIC | $FINAL, $method(ForkJoinTask, join, $Object*)},
	{"joinForPoolInvoke", "(Ljava/util/concurrent/ForkJoinPool;)Ljava/lang/Object;", "(Ljava/util/concurrent/ForkJoinPool;)TV;", $FINAL, $method(ForkJoinTask, joinForPoolInvoke, $Object*, $ForkJoinPool*)},
	{"peekNextLocalTask", "()Ljava/util/concurrent/ForkJoinTask;", "()Ljava/util/concurrent/ForkJoinTask<*>;", $PROTECTED | $STATIC, $staticMethod(ForkJoinTask, peekNextLocalTask, ForkJoinTask*)},
	{"pollNextLocalTask", "()Ljava/util/concurrent/ForkJoinTask;", "()Ljava/util/concurrent/ForkJoinTask<*>;", $PROTECTED | $STATIC, $staticMethod(ForkJoinTask, pollNextLocalTask, ForkJoinTask*)},
	{"pollSubmission", "()Ljava/util/concurrent/ForkJoinTask;", "()Ljava/util/concurrent/ForkJoinTask<*>;", $PROTECTED | $STATIC, $staticMethod(ForkJoinTask, pollSubmission, ForkJoinTask*)},
	{"pollTask", "()Ljava/util/concurrent/ForkJoinTask;", "()Ljava/util/concurrent/ForkJoinTask<*>;", $PROTECTED | $STATIC, $staticMethod(ForkJoinTask, pollTask, ForkJoinTask*)},
	{"quietlyComplete", "()V", nullptr, $PUBLIC | $FINAL, $method(ForkJoinTask, quietlyComplete, void)},
	{"quietlyInvoke", "()V", nullptr, $PUBLIC | $FINAL, $method(ForkJoinTask, quietlyInvoke, void)},
	{"quietlyJoin", "()V", nullptr, $PUBLIC | $FINAL, $method(ForkJoinTask, quietlyJoin, void)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(ForkJoinTask, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"reinitialize", "()V", nullptr, $PUBLIC, $virtualMethod(ForkJoinTask, reinitialize, void)},
	{"reportException", "(I)V", nullptr, $PRIVATE, $method(ForkJoinTask, reportException, void, int32_t)},
	{"reportExecutionException", "(I)V", nullptr, $PRIVATE, $method(ForkJoinTask, reportExecutionException, void, int32_t)},
	{"rethrow", "(Ljava/lang/Throwable;)V", nullptr, $STATIC, $staticMethod(ForkJoinTask, rethrow, void, $Throwable*)},
	{"setDone", "()I", nullptr, $PRIVATE, $method(ForkJoinTask, setDone, int32_t)},
	{"setForkJoinTaskTag", "(S)S", nullptr, $PUBLIC | $FINAL, $method(ForkJoinTask, setForkJoinTaskTag, int16_t, int16_t)},
	{"setRawResult", "(Ljava/lang/Object;)V", "(TV;)V", $PROTECTED | $ABSTRACT, $virtualMethod(ForkJoinTask, setRawResult, void, Object$*)},
	{"signalWaiters", "()V", nullptr, $PRIVATE, $method(ForkJoinTask, signalWaiters, void)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"trySetCancelled", "()I", nullptr, $PRIVATE, $method(ForkJoinTask, trySetCancelled, int32_t)},
	{"trySetException", "(Ljava/lang/Throwable;)I", nullptr, 0, $virtualMethod(ForkJoinTask, trySetException, int32_t, $Throwable*)},
	{"trySetThrown", "(Ljava/lang/Throwable;)I", nullptr, $FINAL, $method(ForkJoinTask, trySetThrown, int32_t, $Throwable*)},
	{"tryUnfork", "()Z", nullptr, $PUBLIC, $virtualMethod(ForkJoinTask, tryUnfork, bool)},
	{"uncheckedThrow", "(Ljava/lang/Throwable;)V", "<T:Ljava/lang/Throwable;>(Ljava/lang/Throwable;)V^TT;", $STATIC, $staticMethod(ForkJoinTask, uncheckedThrow, void, $Throwable*), "java.lang.Throwable"},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE, $method(ForkJoinTask, writeObject, void, $ObjectOutputStream*), "java.io.IOException"},
	{}
};

$InnerClassInfo _ForkJoinTask_InnerClassesInfo_[] = {
	{"java.util.concurrent.ForkJoinTask$AdaptedInterruptibleCallable", "java.util.concurrent.ForkJoinTask", "AdaptedInterruptibleCallable", $STATIC | $FINAL},
	{"java.util.concurrent.ForkJoinTask$AdaptedCallable", "java.util.concurrent.ForkJoinTask", "AdaptedCallable", $STATIC | $FINAL},
	{"java.util.concurrent.ForkJoinTask$RunnableExecuteAction", "java.util.concurrent.ForkJoinTask", "RunnableExecuteAction", $STATIC | $FINAL},
	{"java.util.concurrent.ForkJoinTask$AdaptedRunnableAction", "java.util.concurrent.ForkJoinTask", "AdaptedRunnableAction", $STATIC | $FINAL},
	{"java.util.concurrent.ForkJoinTask$AdaptedRunnable", "java.util.concurrent.ForkJoinTask", "AdaptedRunnable", $STATIC | $FINAL},
	{"java.util.concurrent.ForkJoinTask$Aux", "java.util.concurrent.ForkJoinTask", "Aux", $STATIC | $FINAL},
	{}
};

$ClassInfo _ForkJoinTask_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"java.util.concurrent.ForkJoinTask",
	"java.lang.Object",
	"java.util.concurrent.Future,java.io.Serializable",
	_ForkJoinTask_FieldInfo_,
	_ForkJoinTask_MethodInfo_,
	"<V:Ljava/lang/Object;>Ljava/lang/Object;Ljava/util/concurrent/Future<TV;>;Ljava/io/Serializable;",
	nullptr,
	_ForkJoinTask_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.concurrent.ForkJoinTask$AdaptedInterruptibleCallable,java.util.concurrent.ForkJoinTask$AdaptedCallable,java.util.concurrent.ForkJoinTask$RunnableExecuteAction,java.util.concurrent.ForkJoinTask$AdaptedRunnableAction,java.util.concurrent.ForkJoinTask$AdaptedRunnable,java.util.concurrent.ForkJoinTask$Aux"
};

$Object* allocate$ForkJoinTask($Class* clazz) {
	return $of($alloc(ForkJoinTask));
}

int32_t ForkJoinTask::hashCode() {
	 return this->$Future::hashCode();
}

bool ForkJoinTask::equals(Object$* obj) {
	 return this->$Future::equals(obj);
}

$Object* ForkJoinTask::clone() {
	 return this->$Future::clone();
}

$String* ForkJoinTask::toString() {
	 return this->$Future::toString();
}

void ForkJoinTask::finalize() {
	this->$Future::finalize();
}

$VarHandle* ForkJoinTask::STATUS = nullptr;
$VarHandle* ForkJoinTask::AUX = nullptr;

int32_t ForkJoinTask::getAndBitwiseOrStatus(int32_t v) {
	return $intValue($nc(ForkJoinTask::STATUS)->getAndBitwiseOr($$new($ObjectArray, {$of(this), $$of(v)})));
}

bool ForkJoinTask::casStatus(int32_t c, int32_t v) {
	return $nc(ForkJoinTask::STATUS)->compareAndSet($$new($ObjectArray, {$of(this), $$of(c), $$of(v)}));
}

bool ForkJoinTask::casAux($ForkJoinTask$Aux* c, $ForkJoinTask$Aux* v) {
	return $nc(ForkJoinTask::AUX)->compareAndSet($$new($ObjectArray, {$of(this), $of(c), $of(v)}));
}

void ForkJoinTask::signalWaiters() {
	$useLocalCurrentObjectStackCache();
	{
		$var($ForkJoinTask$Aux, a, nullptr);
		for (;;) {
			bool var$0 = ($assign(a, this->aux)) != nullptr;
			if (!(var$0 && $nc(a)->ex == nullptr)) {
				break;
			}
			{
				if (casAux(a, nullptr)) {
					{
						$var($Thread, t, nullptr);
						for (; a != nullptr; $assign(a, $nc(a)->next)) {
							if (($assign(t, a->thread)) != $Thread::currentThread() && t != nullptr) {
								$LockSupport::unpark(t);
							}
						}
					}
					break;
				}
			}
		}
	}
}

int32_t ForkJoinTask::setDone() {
	int32_t s = getAndBitwiseOrStatus(ForkJoinTask::DONE) | ForkJoinTask::DONE;
	signalWaiters();
	return s;
}

int32_t ForkJoinTask::trySetCancelled() {
	int32_t s = 0;
	bool var$0 = false;
	do {
		var$0 = (s = this->status) >= 0;
		if (var$0) {
			int32_t var$1 = s;
			var$0 = !casStatus(var$1, s |= (ForkJoinTask::DONE | ForkJoinTask::ABNORMAL));
		}
	} while (var$0);
	signalWaiters();
	return s;
}

int32_t ForkJoinTask::trySetThrown($Throwable* ex) {
	$useLocalCurrentObjectStackCache();
	$var($ForkJoinTask$Aux, h, $new($ForkJoinTask$Aux, $($Thread::currentThread()), ex));
	$var($ForkJoinTask$Aux, p, nullptr);
	bool installed = false;
	int32_t s = 0;
	while ((s = this->status) >= 0) {
		$var($ForkJoinTask$Aux, a, nullptr);
		bool var$1 = !installed;
		if (var$1) {
			bool var$2 = ($assign(a, this->aux)) == nullptr;
			var$1 = (var$2 || $nc(a)->ex == nullptr);
		}
		bool var$0 = var$1;
		if (var$0 && (installed = casAux(a, h))) {
			$assign(p, a);
		}
		bool var$3 = installed;
		if (var$3) {
			int32_t var$4 = s;
			var$3 = casStatus(var$4, s |= ((ForkJoinTask::DONE | ForkJoinTask::ABNORMAL) | ForkJoinTask::THROWN));
		}
		if (var$3) {
			break;
		}
	}
	for (; p != nullptr; $assign(p, $nc(p)->next)) {
		$LockSupport::unpark(p->thread);
	}
	return s;
}

int32_t ForkJoinTask::trySetException($Throwable* ex) {
	return trySetThrown(ex);
}

void ForkJoinTask::init$() {
}

bool ForkJoinTask::isExceptionalStatus(int32_t s) {
	$init(ForkJoinTask);
	return ((int32_t)(s & (uint32_t)ForkJoinTask::THROWN)) != 0;
}

int32_t ForkJoinTask::doExec() {
	int32_t s = 0;
	bool completed = false;
	if ((s = this->status) >= 0) {
		try {
			completed = exec();
		} catch ($Throwable& rex) {
			s = trySetException(rex);
			completed = false;
		}
		if (completed) {
			s = setDone();
		}
	}
	return s;
}

int32_t ForkJoinTask::awaitDone($ForkJoinPool* pool$renamed, bool ran, bool interruptible, bool timed, int64_t nanos) {
	$useLocalCurrentObjectStackCache();
	$var($ForkJoinPool, pool, pool$renamed);
	$var($ForkJoinPool, p, nullptr);
	bool internal = false;
	int32_t s = 0;
	$var($Thread, t, nullptr);
	$var($ForkJoinPool$WorkQueue, q, nullptr);
	if ($instanceOf($ForkJoinWorkerThread, $assign(t, $Thread::currentThread()))) {
		$var($ForkJoinWorkerThread, wt, $cast($ForkJoinWorkerThread, t));
		$assign(p, wt->pool);
		if (pool == nullptr) {
			$assign(pool, p);
		}
		if (internal = (pool == p)) {
			$assign(q, wt->workQueue);
		}
	} else {
		internal = false;
		$init($ForkJoinPool);
		$assign(p, $ForkJoinPool::common);
		if (pool == nullptr) {
			$assign(pool, p);
		}
		if (pool == p && p != nullptr) {
			$assign(q, p->externalQueue());
		}
	}
	if (interruptible && $Thread::interrupted()) {
		return ForkJoinTask::ABNORMAL;
	}
	if ((s = this->status) < 0) {
		return s;
	}
	int64_t deadline = 0;
	if (timed) {
		if (nanos <= (int64_t)0) {
			return 0;
		} else if ((deadline = nanos + $System::nanoTime()) == (int64_t)0) {
			deadline = 1;
		}
	}
	bool uncompensate = false;
	if (q != nullptr && p != nullptr) {
		bool canHelp = !timed || ((int32_t)(p->mode & (uint32_t)ForkJoinTask::SMASK)) == 0;
		if (canHelp) {
			if (($instanceOf($CountedCompleter, this)) && (s = p->helpComplete(this, q, internal)) < 0) {
				return s;
			}
			bool var$1 = !ran;
			if (var$1) {
				bool var$2 = (!internal && q->externalTryUnpush(this));
				var$1 = (var$2 || q->tryRemove(this, internal));
			}
			bool var$0 = var$1;
			if (var$0 && (s = doExec()) < 0) {
				return s;
			}
		}
		if (internal) {
			if ((s = p->helpJoin(this, q, canHelp)) < 0) {
				return s;
			}
			if (s == ForkJoinTask::UNCOMPENSATE) {
				uncompensate = true;
			}
		}
	}
	bool interrupted = false;
	bool queued = false;
	bool parked = false;
	bool fail = false;
	$var($ForkJoinTask$Aux, node, nullptr);
	while ((s = this->status) >= 0) {
		$var($ForkJoinTask$Aux, a, nullptr);
		int64_t ns = 0;
		bool var$3 = fail;
		if (var$3 || (fail = (pool != nullptr && pool->mode < 0))) {
			casStatus(s, s | (ForkJoinTask::DONE | ForkJoinTask::ABNORMAL));
		} else if (parked && $Thread::interrupted()) {
			if (interruptible) {
				s = ForkJoinTask::ABNORMAL;
				break;
			}
			interrupted = true;
		} else if (queued) {
			if (deadline != (int64_t)0) {
				if ((ns = deadline - $System::nanoTime()) <= (int64_t)0) {
					break;
				}
				$LockSupport::parkNanos(ns);
			} else {
				$LockSupport::park();
			}
			parked = true;
		} else if (node != nullptr) {
			bool var$4 = ($assign(a, this->aux)) != nullptr;
			if (var$4 && $nc(a)->ex != nullptr) {
				$Thread::onSpinWait();
			} else {
				$var($ForkJoinTask$Aux, var$6, $set(node, next, a));
				if (queued = casAux(var$6, node)) {
					$LockSupport::setCurrentBlocker(this);
				}
			}
		} else {
			try {
				$assign(node, $new($ForkJoinTask$Aux, $($Thread::currentThread()), nullptr));
			} catch ($Throwable& ex) {
				fail = true;
			}
		}
	}
	if (pool != nullptr && uncompensate) {
		pool->uncompensate();
	}
	if (queued) {
		$LockSupport::setCurrentBlocker(nullptr);
		if (s >= 0) {
			bool outer$break = false;
			{
				$var($ForkJoinTask$Aux, a, nullptr);
				for (;;) {
					bool var$7 = ($assign(a, this->aux)) != nullptr;
					if (!(var$7 && $nc(a)->ex == nullptr)) {
						break;
					}
					{
						{
							$var($ForkJoinTask$Aux, trail, nullptr);
							for (;;) {
								$var($ForkJoinTask$Aux, next, $nc(a)->next);
								if (a == node) {
									if (trail != nullptr) {
										trail->casNext(trail, next);
									} else if (casAux(a, next)) {
										outer$break = true;
										break;
									}
									break;
								} else {
									$assign(trail, a);
									if (($assign(a, next)) == nullptr) {
										outer$break = true;
										break;
									}
								}
							}
							if (outer$break) {
								break;
							}
						}
					}
				}
			}
		} else {
			signalWaiters();
			if (interrupted) {
				$($Thread::currentThread())->interrupt();
			}
		}
	}
	return s;
}

void ForkJoinTask::cancelIgnoringExceptions($Future* t) {
	$init(ForkJoinTask);
	if (t != nullptr) {
		try {
			t->cancel(true);
		} catch ($Throwable& ignore) {
		}
	}
}

$Throwable* ForkJoinTask::getThrowableException() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($Throwable, ex, nullptr);
	$var($ForkJoinTask$Aux, a, nullptr);
	if (($assign(a, this->aux)) == nullptr) {
		$assign(ex, nullptr);
	} else if (($assign(ex, $nc(a)->ex)) != nullptr && a->thread != $Thread::currentThread()) {
		try {
			$var($Constructor, noArgCtor, nullptr);
			$var($Constructor, oneArgCtor, nullptr);
			{
				$var($ConstructorArray, arr$, $nc($of(ex))->getClass()->getConstructors());
				int32_t len$ = $nc(arr$)->length;
				int32_t i$ = 0;
				for (; i$ < len$; ++i$) {
					$var($Constructor, c, arr$->get(i$));
					{
						$var($ClassArray, ps, $nc(c)->getParameterTypes());
						if ($nc(ps)->length == 0) {
							$assign(noArgCtor, c);
						} else if (ps->length == 1 && ps->get(0) == $Throwable::class$) {
							$assign(oneArgCtor, c);
							break;
						}
					}
				}
			}
			if (oneArgCtor != nullptr) {
				$assign(ex, $cast($Throwable, oneArgCtor->newInstance($$new($ObjectArray, {$of(ex)}))));
			} else if (noArgCtor != nullptr) {
				$var($Throwable, rx, $cast($Throwable, noArgCtor->newInstance($$new($ObjectArray, 0))));
				$nc(rx)->initCause(ex);
				$assign(ex, rx);
			}
		} catch ($Exception& ignore) {
		}
	}
	return ex;
}

$Throwable* ForkJoinTask::getException(int32_t s) {
	$var($Throwable, ex, nullptr);
	if (((int32_t)(s & (uint32_t)ForkJoinTask::ABNORMAL)) != 0 && (((int32_t)(s & (uint32_t)ForkJoinTask::THROWN)) == 0 || ($assign(ex, getThrowableException())) == nullptr)) {
		$assign(ex, $new($CancellationException));
	}
	return ex;
}

void ForkJoinTask::reportException(int32_t s) {
	ForkJoinTask::uncheckedThrow(((int32_t)(s & (uint32_t)ForkJoinTask::THROWN)) != 0 ? $(getThrowableException()) : ($Throwable*)nullptr);
}

void ForkJoinTask::reportExecutionException(int32_t s) {
	$var($Throwable, ex, nullptr);
	if (s == ForkJoinTask::ABNORMAL) {
		$assign(ex, $new($InterruptedException));
	} else if (s >= 0) {
		$assign(ex, $new($TimeoutException));
	} else if (((int32_t)(s & (uint32_t)ForkJoinTask::THROWN)) != 0 && ($assign(ex, getThrowableException())) != nullptr) {
		$assign(ex, $new($ExecutionException, ex));
	}
	ForkJoinTask::uncheckedThrow(ex);
}

void ForkJoinTask::rethrow($Throwable* ex) {
	$init(ForkJoinTask);
	ForkJoinTask::uncheckedThrow(ex);
}

void ForkJoinTask::uncheckedThrow($Throwable* t$renamed) {
	$init(ForkJoinTask);
	$var($Throwable, t, t$renamed);
	if (t == nullptr) {
		$assign(t, $new($CancellationException));
	}
	$throw(t);
}

ForkJoinTask* ForkJoinTask::fork() {
	$useLocalCurrentObjectStackCache();
	$var($Thread, t, nullptr);
	$var($ForkJoinWorkerThread, w, nullptr);
	if ($instanceOf($ForkJoinWorkerThread, $assign(t, $Thread::currentThread()))) {
		$nc($nc(($assign(w, $cast($ForkJoinWorkerThread, t))))->workQueue)->push(this, w->pool);
	} else {
		$init($ForkJoinPool);
		$nc($ForkJoinPool::common)->externalPush(this);
	}
	return this;
}

$Object* ForkJoinTask::join() {
	int32_t s = 0;
	if ((s = this->status) >= 0) {
		s = awaitDone(nullptr, false, false, false, 0);
	}
	if (((int32_t)(s & (uint32_t)ForkJoinTask::ABNORMAL)) != 0) {
		reportException(s);
	}
	return $of(getRawResult());
}

$Object* ForkJoinTask::invoke() {
	int32_t s = 0;
	if ((s = doExec()) >= 0) {
		s = awaitDone(nullptr, true, false, false, 0);
	}
	if (((int32_t)(s & (uint32_t)ForkJoinTask::ABNORMAL)) != 0) {
		reportException(s);
	}
	return $of(getRawResult());
}

void ForkJoinTask::invokeAll(ForkJoinTask* t1, ForkJoinTask* t2) {
	$init(ForkJoinTask);
	int32_t s1 = 0;
	int32_t s2 = 0;
	if (t1 == nullptr || t2 == nullptr) {
		$throwNew($NullPointerException);
	}
	$nc(t2)->fork();
	if ((s1 = $nc(t1)->doExec()) >= 0) {
		s1 = t1->awaitDone(nullptr, true, false, false, 0);
	}
	if (((int32_t)(s1 & (uint32_t)ForkJoinTask::ABNORMAL)) != 0) {
		cancelIgnoringExceptions(t2);
		$nc(t1)->reportException(s1);
	} else if (((int32_t)((s2 = t2->awaitDone(nullptr, false, false, false, 0)) & (uint32_t)ForkJoinTask::ABNORMAL)) != 0) {
		t2->reportException(s2);
	}
}

void ForkJoinTask::invokeAll($ForkJoinTaskArray* tasks) {
	$init(ForkJoinTask);
	$useLocalCurrentObjectStackCache();
	$var($Throwable, ex, nullptr);
	int32_t last = $nc(tasks)->length - 1;
	for (int32_t i = last; i >= 0; --i) {
		$var(ForkJoinTask, t, nullptr);
		if (($assign(t, tasks->get(i))) == nullptr) {
			$assign(ex, $new($NullPointerException));
			break;
		}
		if (i == 0) {
			int32_t s = 0;
			if ((s = $nc(t)->doExec()) >= 0) {
				s = t->awaitDone(nullptr, true, false, false, 0);
			}
			if (((int32_t)(s & (uint32_t)ForkJoinTask::ABNORMAL)) != 0) {
				$assign(ex, $nc(t)->getException(s));
			}
			break;
		}
		$nc(t)->fork();
	}
	if (ex == nullptr) {
		for (int32_t i = 1; i <= last; ++i) {
			$var(ForkJoinTask, t, nullptr);
			if (($assign(t, tasks->get(i))) != nullptr) {
				int32_t s = 0;
				if ((s = $nc(t)->status) >= 0) {
					s = t->awaitDone(nullptr, false, false, false, 0);
				}
				if (((int32_t)(s & (uint32_t)ForkJoinTask::ABNORMAL)) != 0 && ($assign(ex, $nc(t)->getException(s))) != nullptr) {
					break;
				}
			}
		}
	}
	if (ex != nullptr) {
		for (int32_t i = 1; i <= last; ++i) {
			cancelIgnoringExceptions(tasks->get(i));
		}
		rethrow(ex);
	}
}

$Collection* ForkJoinTask::invokeAll($Collection* tasks) {
	$init(ForkJoinTask);
	$useLocalCurrentObjectStackCache();
	if (!($instanceOf($RandomAccess, tasks)) || !($instanceOf($List, tasks))) {
		invokeAll($fcast($ForkJoinTaskArray, $($nc(tasks)->toArray($$new($ForkJoinTaskArray, 0)))));
		return tasks;
	}
	$var($List, ts, $cast($List, tasks));
	$var($Throwable, ex, nullptr);
	int32_t last = $nc(ts)->size() - 1;
	for (int32_t i = last; i >= 0; --i) {
		$var(ForkJoinTask, t, nullptr);
		if (($assign(t, $cast(ForkJoinTask, ts->get(i)))) == nullptr) {
			$assign(ex, $new($NullPointerException));
			break;
		}
		if (i == 0) {
			int32_t s = 0;
			if ((s = $nc(t)->doExec()) >= 0) {
				s = t->awaitDone(nullptr, true, false, false, 0);
			}
			if (((int32_t)(s & (uint32_t)ForkJoinTask::ABNORMAL)) != 0) {
				$assign(ex, $nc(t)->getException(s));
			}
			break;
		}
		$nc(t)->fork();
	}
	if (ex == nullptr) {
		for (int32_t i = 1; i <= last; ++i) {
			$var(ForkJoinTask, t, nullptr);
			if (($assign(t, $cast(ForkJoinTask, ts->get(i)))) != nullptr) {
				int32_t s = 0;
				if ((s = $nc(t)->status) >= 0) {
					s = t->awaitDone(nullptr, false, false, false, 0);
				}
				if (((int32_t)(s & (uint32_t)ForkJoinTask::ABNORMAL)) != 0 && ($assign(ex, $nc(t)->getException(s))) != nullptr) {
					break;
				}
			}
		}
	}
	if (ex != nullptr) {
		for (int32_t i = 1; i <= last; ++i) {
			cancelIgnoringExceptions($cast($Future, $(ts->get(i))));
		}
		rethrow(ex);
	}
	return tasks;
}

bool ForkJoinTask::cancel(bool mayInterruptIfRunning) {
	return ((int32_t)(trySetCancelled() & (uint32_t)(ForkJoinTask::ABNORMAL | ForkJoinTask::THROWN))) == ForkJoinTask::ABNORMAL;
}

bool ForkJoinTask::isDone() {
	return this->status < 0;
}

bool ForkJoinTask::isCancelled() {
	return ((int32_t)(this->status & (uint32_t)(ForkJoinTask::ABNORMAL | ForkJoinTask::THROWN))) == ForkJoinTask::ABNORMAL;
}

bool ForkJoinTask::isCompletedAbnormally() {
	return ((int32_t)(this->status & (uint32_t)ForkJoinTask::ABNORMAL)) != 0;
}

bool ForkJoinTask::isCompletedNormally() {
	return ((int32_t)(this->status & (uint32_t)(ForkJoinTask::DONE | ForkJoinTask::ABNORMAL))) == ForkJoinTask::DONE;
}

$Throwable* ForkJoinTask::getException() {
	return getException(this->status);
}

void ForkJoinTask::completeExceptionally($Throwable* ex) {
	trySetException(($instanceOf($RuntimeException, ex)) || ($instanceOf($Error, ex)) ? ex : static_cast<$Throwable*>($$new($RuntimeException, ex)));
}

void ForkJoinTask::complete(Object$* value) {
	try {
		setRawResult(value);
	} catch ($Throwable& rex) {
		trySetException(rex);
		return;
	}
	setDone();
}

void ForkJoinTask::quietlyComplete() {
	setDone();
}

$Object* ForkJoinTask::get() {
	int32_t s = awaitDone(nullptr, false, true, false, 0);
	if (((int32_t)(s & (uint32_t)ForkJoinTask::ABNORMAL)) != 0) {
		reportExecutionException(s);
	}
	return $of(getRawResult());
}

$Object* ForkJoinTask::get(int64_t timeout, $TimeUnit* unit) {
	int64_t nanos = $nc(unit)->toNanos(timeout);
	int32_t s = awaitDone(nullptr, false, true, true, nanos);
	if (s >= 0 || ((int32_t)(s & (uint32_t)ForkJoinTask::ABNORMAL)) != 0) {
		reportExecutionException(s);
	}
	return $of(getRawResult());
}

void ForkJoinTask::quietlyJoin() {
	if (this->status >= 0) {
		awaitDone(nullptr, false, false, false, 0);
	}
}

void ForkJoinTask::quietlyInvoke() {
	if (doExec() >= 0) {
		awaitDone(nullptr, true, false, false, 0);
	}
}

void ForkJoinTask::awaitPoolInvoke($ForkJoinPool* pool) {
	awaitDone(pool, false, false, false, 0);
}

void ForkJoinTask::awaitPoolInvoke($ForkJoinPool* pool, int64_t nanos) {
	awaitDone(pool, false, true, true, nanos);
}

$Object* ForkJoinTask::joinForPoolInvoke($ForkJoinPool* pool) {
	int32_t s = awaitDone(pool, false, false, false, 0);
	if (((int32_t)(s & (uint32_t)ForkJoinTask::ABNORMAL)) != 0) {
		reportException(s);
	}
	return $of(getRawResult());
}

$Object* ForkJoinTask::getForPoolInvoke($ForkJoinPool* pool) {
	int32_t s = awaitDone(pool, false, true, false, 0);
	if (((int32_t)(s & (uint32_t)ForkJoinTask::ABNORMAL)) != 0) {
		reportExecutionException(s);
	}
	return $of(getRawResult());
}

$Object* ForkJoinTask::getForPoolInvoke($ForkJoinPool* pool, int64_t nanos) {
	int32_t s = awaitDone(pool, false, true, true, nanos);
	if (s >= 0 || ((int32_t)(s & (uint32_t)ForkJoinTask::ABNORMAL)) != 0) {
		reportExecutionException(s);
	}
	return $of(getRawResult());
}

void ForkJoinTask::helpQuiesce() {
	$init(ForkJoinTask);
	$useLocalCurrentObjectStackCache();
	$var($Thread, t, nullptr);
	$var($ForkJoinWorkerThread, w, nullptr);
	$var($ForkJoinPool, p, nullptr);
	if ($instanceOf($ForkJoinWorkerThread, $assign(t, $Thread::currentThread())) && ($assign(p, $nc(($assign(w, $cast($ForkJoinWorkerThread, t))))->pool)) != nullptr) {
		$nc(p)->helpQuiescePool($nc(w)->workQueue, $Long::MAX_VALUE, false);
	} else {
		$init($ForkJoinPool);
		$nc($ForkJoinPool::common)->externalHelpQuiescePool($Long::MAX_VALUE, false);
	}
}

void ForkJoinTask::reinitialize() {
	$set(this, aux, nullptr);
	this->status = 0;
}

$ForkJoinPool* ForkJoinTask::getPool() {
	$init(ForkJoinTask);
	$var($Thread, t, nullptr);
	return (($instanceOf($ForkJoinWorkerThread, $assign(t, $Thread::currentThread()))) ? $nc(($cast($ForkJoinWorkerThread, t)))->pool : ($ForkJoinPool*)nullptr);
}

bool ForkJoinTask::inForkJoinPool() {
	$init(ForkJoinTask);
	return $instanceOf($ForkJoinWorkerThread, $($Thread::currentThread()));
}

bool ForkJoinTask::tryUnfork() {
	$useLocalCurrentObjectStackCache();
	$var($Thread, t, nullptr);
	$var($ForkJoinPool$WorkQueue, q, nullptr);
	bool var$0 = false;
	if ($instanceOf($ForkJoinWorkerThread, $assign(t, $Thread::currentThread()))) {
		bool var$1 = ($assign(q, $nc(($cast($ForkJoinWorkerThread, t)))->workQueue)) != nullptr;
		var$0 = var$1 && $nc(q)->tryUnpush(this);
	} else {
		bool var$2 = ($assign(q, $ForkJoinPool::commonQueue())) != nullptr;
		var$0 = var$2 && q->externalTryUnpush(this);
	}
	return var$0;
}

int32_t ForkJoinTask::getQueuedTaskCount() {
	$init(ForkJoinTask);
	$useLocalCurrentObjectStackCache();
	$var($Thread, t, nullptr);
	$var($ForkJoinPool$WorkQueue, q, nullptr);
	if ($instanceOf($ForkJoinWorkerThread, $assign(t, $Thread::currentThread()))) {
		$assign(q, $nc(($cast($ForkJoinWorkerThread, t)))->workQueue);
	} else {
		$assign(q, $ForkJoinPool::commonQueue());
	}
	return (q == nullptr) ? 0 : $nc(q)->queueSize();
}

int32_t ForkJoinTask::getSurplusQueuedTaskCount() {
	$init(ForkJoinTask);
	return $ForkJoinPool::getSurplusQueuedTaskCount();
}

ForkJoinTask* ForkJoinTask::peekNextLocalTask() {
	$init(ForkJoinTask);
	$useLocalCurrentObjectStackCache();
	$var($Thread, t, nullptr);
	$var($ForkJoinPool$WorkQueue, q, nullptr);
	if ($instanceOf($ForkJoinWorkerThread, $assign(t, $Thread::currentThread()))) {
		$assign(q, $nc(($cast($ForkJoinWorkerThread, t)))->workQueue);
	} else {
		$assign(q, $ForkJoinPool::commonQueue());
	}
	return (q == nullptr) ? (ForkJoinTask*)nullptr : $nc(q)->peek();
}

ForkJoinTask* ForkJoinTask::pollNextLocalTask() {
	$init(ForkJoinTask);
	$var($Thread, t, nullptr);
	return (($instanceOf($ForkJoinWorkerThread, $assign(t, $Thread::currentThread()))) ? $nc($nc(($cast($ForkJoinWorkerThread, t)))->workQueue)->nextLocalTask() : (ForkJoinTask*)nullptr);
}

ForkJoinTask* ForkJoinTask::pollTask() {
	$init(ForkJoinTask);
	$useLocalCurrentObjectStackCache();
	$var($Thread, t, nullptr);
	$var($ForkJoinWorkerThread, w, nullptr);
	return (($instanceOf($ForkJoinWorkerThread, $assign(t, $Thread::currentThread()))) ? $nc($nc(($assign(w, $cast($ForkJoinWorkerThread, t))))->pool)->nextTaskFor($nc(w)->workQueue) : (ForkJoinTask*)nullptr);
}

ForkJoinTask* ForkJoinTask::pollSubmission() {
	$init(ForkJoinTask);
	$var($Thread, t, nullptr);
	return (($instanceOf($ForkJoinWorkerThread, $assign(t, $Thread::currentThread()))) ? $nc($nc(($cast($ForkJoinWorkerThread, t)))->pool)->pollSubmission() : (ForkJoinTask*)nullptr);
}

int16_t ForkJoinTask::getForkJoinTaskTag() {
	return (int16_t)this->status;
}

int16_t ForkJoinTask::setForkJoinTaskTag(int16_t newValue) {
	for (int32_t s = 0;;) {
		int32_t var$0 = s = this->status;
		if (casStatus(var$0, ((int32_t)(s & (uint32_t)~ForkJoinTask::SMASK)) | ((int32_t)(newValue & (uint32_t)ForkJoinTask::SMASK)))) {
			return (int16_t)s;
		}
	}
}

bool ForkJoinTask::compareAndSetForkJoinTaskTag(int16_t expect, int16_t update) {
	for (int32_t s = 0;;) {
		if ((int16_t)(s = this->status) != expect) {
			return false;
		}
		if (casStatus(s, ((int32_t)(s & (uint32_t)~ForkJoinTask::SMASK)) | ((int32_t)(update & (uint32_t)ForkJoinTask::SMASK)))) {
			return true;
		}
	}
}

ForkJoinTask* ForkJoinTask::adapt($Runnable* runnable) {
	$init(ForkJoinTask);
	return $new($ForkJoinTask$AdaptedRunnableAction, runnable);
}

ForkJoinTask* ForkJoinTask::adapt($Runnable* runnable, Object$* result) {
	$init(ForkJoinTask);
	return $new($ForkJoinTask$AdaptedRunnable, runnable, result);
}

ForkJoinTask* ForkJoinTask::adapt($Callable* callable) {
	$init(ForkJoinTask);
	return $new($ForkJoinTask$AdaptedCallable, callable);
}

ForkJoinTask* ForkJoinTask::adaptInterruptible($Callable* callable) {
	$init(ForkJoinTask);
	return $new($ForkJoinTask$AdaptedInterruptibleCallable, callable);
}

void ForkJoinTask::writeObject($ObjectOutputStream* s) {
	$var($ForkJoinTask$Aux, a, nullptr);
	$nc(s)->defaultWriteObject();
	s->writeObject(($assign(a, this->aux)) == nullptr ? ($Object*)nullptr : $of($nc(a)->ex));
}

void ForkJoinTask::readObject($ObjectInputStream* s) {
	$nc(s)->defaultReadObject();
	$var($Object, ex, s->readObject());
	if (ex != nullptr) {
		trySetThrown($cast($Throwable, ex));
	}
}

void clinit$ForkJoinTask($Class* class$) {
	$beforeCallerSensitive();
	{
		try {
			$var($MethodHandles$Lookup, l, $MethodHandles::lookup());
			$init($Integer);
			$assignStatic(ForkJoinTask::STATUS, $nc(l)->findVarHandle(ForkJoinTask::class$, "status"_s, $Integer::TYPE));
			$load($ForkJoinTask$Aux);
			$assignStatic(ForkJoinTask::AUX, l->findVarHandle(ForkJoinTask::class$, "aux"_s, $ForkJoinTask$Aux::class$));
		} catch ($ReflectiveOperationException& e) {
			$throwNew($ExceptionInInitializerError, static_cast<$Throwable*>(e));
		}
	}
}

ForkJoinTask::ForkJoinTask() {
}

$Class* ForkJoinTask::load$($String* name, bool initialize) {
	$loadClass(ForkJoinTask, name, initialize, &_ForkJoinTask_ClassInfo_, clinit$ForkJoinTask, allocate$ForkJoinTask);
	return class$;
}

$Class* ForkJoinTask::class$ = nullptr;

		} // concurrent
	} // util
} // java