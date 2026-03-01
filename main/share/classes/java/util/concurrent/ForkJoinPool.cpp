#include <java/util/concurrent/ForkJoinPool.h>

#include <java/lang/ClassLoader.h>
#include <java/lang/ExceptionInInitializerError.h>
#include <java/lang/InterruptedException.h>
#include <java/lang/Math.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/Runnable.h>
#include <java/lang/Runtime.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/Thread$UncaughtExceptionHandler.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/VarHandle.h>
#include <java/lang/reflect/Constructor.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/CodeSource.h>
#include <java/security/Permission.h>
#include <java/security/PermissionCollection.h>
#include <java/security/Permissions.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/ProtectionDomain.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/concurrent/AbstractExecutorService.h>
#include <java/util/concurrent/Callable.h>
#include <java/util/concurrent/CountedCompleter.h>
#include <java/util/concurrent/Executor.h>
#include <java/util/concurrent/ForkJoinPool$1.h>
#include <java/util/concurrent/ForkJoinPool$DefaultCommonPoolForkJoinWorkerThreadFactory.h>
#include <java/util/concurrent/ForkJoinPool$DefaultForkJoinWorkerThreadFactory.h>
#include <java/util/concurrent/ForkJoinPool$ForkJoinWorkerThreadFactory.h>
#include <java/util/concurrent/ForkJoinPool$InvokeAnyRoot.h>
#include <java/util/concurrent/ForkJoinPool$InvokeAnyTask.h>
#include <java/util/concurrent/ForkJoinPool$ManagedBlocker.h>
#include <java/util/concurrent/ForkJoinPool$WorkQueue.h>
#include <java/util/concurrent/ForkJoinTask$AdaptedCallable.h>
#include <java/util/concurrent/ForkJoinTask$AdaptedInterruptibleCallable.h>
#include <java/util/concurrent/ForkJoinTask$AdaptedRunnable.h>
#include <java/util/concurrent/ForkJoinTask$AdaptedRunnableAction.h>
#include <java/util/concurrent/ForkJoinTask$RunnableExecuteAction.h>
#include <java/util/concurrent/ForkJoinTask.h>
#include <java/util/concurrent/ForkJoinWorkerThread.h>
#include <java/util/concurrent/Future.h>
#include <java/util/concurrent/RejectedExecutionException.h>
#include <java/util/concurrent/RunnableFuture.h>
#include <java/util/concurrent/ThreadLocalRandom.h>
#include <java/util/concurrent/TimeUnit.h>
#include <java/util/concurrent/locks/Condition.h>
#include <java/util/concurrent/locks/LockSupport.h>
#include <java/util/concurrent/locks/ReentrantLock.h>
#include <java/util/function/Predicate.h>
#include <jcpp.h>

#undef ADD_WORKER
#undef COMMON_MAX_SPARES
#undef COMMON_PARALLELISM
#undef CTL
#undef DEFAULT_COMMON_MAX_SPARES
#undef DEFAULT_KEEPALIVE
#undef FIFO
#undef INITIAL_QUEUE_CAPACITY
#undef INNOCUOUS
#undef MAX_CAP
#undef MILLISECONDS
#undef MODE
#undef POOLIDS
#undef QUIET
#undef RC_MASK
#undef RC_SHIFT
#undef RC_UNIT
#undef SHUTDOWN
#undef SMASK
#undef SP_MASK
#undef SRC
#undef SS_SEQ
#undef STOP
#undef SWIDTH
#undef TC_MASK
#undef TC_SHIFT
#undef TC_UNIT
#undef TERMINATED
#undef THREADIDS
#undef TIMEOUT_SLOP
#undef TYPE
#undef UC_MASK
#undef UNCOMPENSATE
#undef UNSIGNALLED

using $PermissionArray = $Array<::java::security::Permission>;
using $ProtectionDomainArray = $Array<::java::security::ProtectionDomain>;
using $ForkJoinPool$WorkQueueArray = $Array<::java::util::concurrent::ForkJoinPool$WorkQueue>;
using $ForkJoinTaskArray = $Array<::java::util::concurrent::ForkJoinTask>;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Exception = ::java::lang::Exception;
using $ExceptionInInitializerError = ::java::lang::ExceptionInInitializerError;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InterruptedException = ::java::lang::InterruptedException;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $NamedAttribute = ::java::lang::NamedAttribute;
using $NullPointerException = ::java::lang::NullPointerException;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $Runnable = ::java::lang::Runnable;
using $Runtime = ::java::lang::Runtime;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityManager = ::java::lang::SecurityManager;
using $Thread$UncaughtExceptionHandler = ::java::lang::Thread$UncaughtExceptionHandler;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $VarHandle = ::java::lang::invoke::VarHandle;
using $Constructor = ::java::lang::reflect::Constructor;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $CodeSource = ::java::security::CodeSource;
using $Permission = ::java::security::Permission;
using $PermissionCollection = ::java::security::PermissionCollection;
using $Permissions = ::java::security::Permissions;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $ProtectionDomain = ::java::security::ProtectionDomain;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $AbstractExecutorService = ::java::util::concurrent::AbstractExecutorService;
using $Callable = ::java::util::concurrent::Callable;
using $CountedCompleter = ::java::util::concurrent::CountedCompleter;
using $Executor = ::java::util::concurrent::Executor;
using $ForkJoinPool$1 = ::java::util::concurrent::ForkJoinPool$1;
using $ForkJoinPool$DefaultCommonPoolForkJoinWorkerThreadFactory = ::java::util::concurrent::ForkJoinPool$DefaultCommonPoolForkJoinWorkerThreadFactory;
using $ForkJoinPool$DefaultForkJoinWorkerThreadFactory = ::java::util::concurrent::ForkJoinPool$DefaultForkJoinWorkerThreadFactory;
using $ForkJoinPool$ForkJoinWorkerThreadFactory = ::java::util::concurrent::ForkJoinPool$ForkJoinWorkerThreadFactory;
using $ForkJoinPool$InvokeAnyRoot = ::java::util::concurrent::ForkJoinPool$InvokeAnyRoot;
using $ForkJoinPool$InvokeAnyTask = ::java::util::concurrent::ForkJoinPool$InvokeAnyTask;
using $ForkJoinPool$ManagedBlocker = ::java::util::concurrent::ForkJoinPool$ManagedBlocker;
using $ForkJoinPool$WorkQueue = ::java::util::concurrent::ForkJoinPool$WorkQueue;
using $ForkJoinTask = ::java::util::concurrent::ForkJoinTask;
using $ForkJoinTask$AdaptedCallable = ::java::util::concurrent::ForkJoinTask$AdaptedCallable;
using $ForkJoinTask$AdaptedInterruptibleCallable = ::java::util::concurrent::ForkJoinTask$AdaptedInterruptibleCallable;
using $ForkJoinTask$AdaptedRunnable = ::java::util::concurrent::ForkJoinTask$AdaptedRunnable;
using $ForkJoinTask$AdaptedRunnableAction = ::java::util::concurrent::ForkJoinTask$AdaptedRunnableAction;
using $ForkJoinTask$RunnableExecuteAction = ::java::util::concurrent::ForkJoinTask$RunnableExecuteAction;
using $ForkJoinWorkerThread = ::java::util::concurrent::ForkJoinWorkerThread;
using $Future = ::java::util::concurrent::Future;
using $RejectedExecutionException = ::java::util::concurrent::RejectedExecutionException;
using $RunnableFuture = ::java::util::concurrent::RunnableFuture;
using $ThreadLocalRandom = ::java::util::concurrent::ThreadLocalRandom;
using $TimeUnit = ::java::util::concurrent::TimeUnit;
using $Condition = ::java::util::concurrent::locks::Condition;
using $LockSupport = ::java::util::concurrent::locks::LockSupport;
using $ReentrantLock = ::java::util::concurrent::locks::ReentrantLock;
using $Predicate = ::java::util::function::Predicate;

namespace java {
	namespace util {
		namespace concurrent {

$NamedAttribute ForkJoinPool_Attribute_var$0[] = {
	{"value", 's', "fjpctl"},
	{}
};

$CompoundAttribute _ForkJoinPool_FieldAnnotations_ctl[] = {
	{"Ljdk/internal/vm/annotation/Contended;", ForkJoinPool_Attribute_var$0},
	{}
};

$FieldInfo _ForkJoinPool_FieldInfo_[] = {
	{"SWIDTH", "I", nullptr, $STATIC | $FINAL, $constField(ForkJoinPool, SWIDTH)},
	{"SMASK", "I", nullptr, $STATIC | $FINAL, $constField(ForkJoinPool, SMASK)},
	{"MAX_CAP", "I", nullptr, $STATIC | $FINAL, $constField(ForkJoinPool, MAX_CAP)},
	{"UNSIGNALLED", "I", nullptr, $STATIC | $FINAL, $constField(ForkJoinPool, UNSIGNALLED)},
	{"SS_SEQ", "I", nullptr, $STATIC | $FINAL, $constField(ForkJoinPool, SS_SEQ)},
	{"FIFO", "I", nullptr, $STATIC | $FINAL, $constField(ForkJoinPool, FIFO)},
	{"SRC", "I", nullptr, $STATIC | $FINAL, $constField(ForkJoinPool, SRC)},
	{"INNOCUOUS", "I", nullptr, $STATIC | $FINAL, $constField(ForkJoinPool, INNOCUOUS)},
	{"QUIET", "I", nullptr, $STATIC | $FINAL, $constField(ForkJoinPool, QUIET)},
	{"SHUTDOWN", "I", nullptr, $STATIC | $FINAL, $constField(ForkJoinPool, SHUTDOWN)},
	{"TERMINATED", "I", nullptr, $STATIC | $FINAL, $constField(ForkJoinPool, TERMINATED)},
	{"STOP", "I", nullptr, $STATIC | $FINAL, $constField(ForkJoinPool, STOP)},
	{"UNCOMPENSATE", "I", nullptr, $STATIC | $FINAL, $constField(ForkJoinPool, UNCOMPENSATE)},
	{"INITIAL_QUEUE_CAPACITY", "I", nullptr, $STATIC | $FINAL, $constField(ForkJoinPool, INITIAL_QUEUE_CAPACITY)},
	{"defaultForkJoinWorkerThreadFactory", "Ljava/util/concurrent/ForkJoinPool$ForkJoinWorkerThreadFactory;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(ForkJoinPool, defaultForkJoinWorkerThreadFactory)},
	{"modifyThreadPermission", "Ljava/lang/RuntimePermission;", nullptr, $STATIC | $FINAL, $staticField(ForkJoinPool, modifyThreadPermission)},
	{"common", "Ljava/util/concurrent/ForkJoinPool;", nullptr, $STATIC | $FINAL, $staticField(ForkJoinPool, common)},
	{"COMMON_PARALLELISM", "I", nullptr, $STATIC | $FINAL, $staticField(ForkJoinPool, COMMON_PARALLELISM)},
	{"COMMON_MAX_SPARES", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ForkJoinPool, COMMON_MAX_SPARES)},
	{"poolIds", "I", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(ForkJoinPool, poolIds)},
	{"DEFAULT_KEEPALIVE", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ForkJoinPool, DEFAULT_KEEPALIVE)},
	{"TIMEOUT_SLOP", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ForkJoinPool, TIMEOUT_SLOP)},
	{"DEFAULT_COMMON_MAX_SPARES", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ForkJoinPool, DEFAULT_COMMON_MAX_SPARES)},
	{"SP_MASK", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ForkJoinPool, SP_MASK)},
	{"UC_MASK", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ForkJoinPool, UC_MASK)},
	{"RC_SHIFT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ForkJoinPool, RC_SHIFT)},
	{"RC_UNIT", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ForkJoinPool, RC_UNIT)},
	{"RC_MASK", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ForkJoinPool, RC_MASK)},
	{"TC_SHIFT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ForkJoinPool, TC_SHIFT)},
	{"TC_UNIT", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ForkJoinPool, TC_UNIT)},
	{"TC_MASK", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ForkJoinPool, TC_MASK)},
	{"ADD_WORKER", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ForkJoinPool, ADD_WORKER)},
	{"keepAlive", "J", nullptr, $FINAL, $field(ForkJoinPool, keepAlive)},
	{"stealCount", "J", nullptr, $VOLATILE, $field(ForkJoinPool, stealCount)},
	{"scanRover", "I", nullptr, 0, $field(ForkJoinPool, scanRover)},
	{"threadIds", "I", nullptr, $VOLATILE, $field(ForkJoinPool, threadIds)},
	{"bounds", "I", nullptr, $FINAL, $field(ForkJoinPool, bounds)},
	{"mode", "I", nullptr, $VOLATILE, $field(ForkJoinPool, mode)},
	{"queues", "[Ljava/util/concurrent/ForkJoinPool$WorkQueue;", nullptr, 0, $field(ForkJoinPool, queues)},
	{"registrationLock", "Ljava/util/concurrent/locks/ReentrantLock;", nullptr, $FINAL, $field(ForkJoinPool, registrationLock)},
	{"termination", "Ljava/util/concurrent/locks/Condition;", nullptr, 0, $field(ForkJoinPool, termination)},
	{"workerNamePrefix", "Ljava/lang/String;", nullptr, $FINAL, $field(ForkJoinPool, workerNamePrefix)},
	{"factory", "Ljava/util/concurrent/ForkJoinPool$ForkJoinWorkerThreadFactory;", nullptr, $FINAL, $field(ForkJoinPool, factory)},
	{"ueh", "Ljava/lang/Thread$UncaughtExceptionHandler;", nullptr, $FINAL, $field(ForkJoinPool, ueh)},
	{"saturate", "Ljava/util/function/Predicate;", "Ljava/util/function/Predicate<-Ljava/util/concurrent/ForkJoinPool;>;", $FINAL, $field(ForkJoinPool, saturate)},
	{"ctl", "J", nullptr, $VOLATILE, $field(ForkJoinPool, ctl), _ForkJoinPool_FieldAnnotations_ctl},
	{"CTL", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ForkJoinPool, CTL)},
	{"MODE", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ForkJoinPool, MODE)},
	{"THREADIDS", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ForkJoinPool, THREADIDS)},
	{"POOLIDS", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ForkJoinPool, POOLIDS)},
	{}
};

$MethodInfo _ForkJoinPool_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ForkJoinPool, init$, void)},
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(ForkJoinPool, init$, void, int32_t)},
	{"<init>", "(ILjava/util/concurrent/ForkJoinPool$ForkJoinWorkerThreadFactory;Ljava/lang/Thread$UncaughtExceptionHandler;Z)V", nullptr, $PUBLIC, $method(ForkJoinPool, init$, void, int32_t, $ForkJoinPool$ForkJoinWorkerThreadFactory*, $Thread$UncaughtExceptionHandler*, bool)},
	{"<init>", "(ILjava/util/concurrent/ForkJoinPool$ForkJoinWorkerThreadFactory;Ljava/lang/Thread$UncaughtExceptionHandler;ZIIILjava/util/function/Predicate;JLjava/util/concurrent/TimeUnit;)V", "(ILjava/util/concurrent/ForkJoinPool$ForkJoinWorkerThreadFactory;Ljava/lang/Thread$UncaughtExceptionHandler;ZIIILjava/util/function/Predicate<-Ljava/util/concurrent/ForkJoinPool;>;JLjava/util/concurrent/TimeUnit;)V", $PUBLIC, $method(ForkJoinPool, init$, void, int32_t, $ForkJoinPool$ForkJoinWorkerThreadFactory*, $Thread$UncaughtExceptionHandler*, bool, int32_t, int32_t, int32_t, $Predicate*, int64_t, $TimeUnit*)},
	{"<init>", "(B)V", nullptr, $PRIVATE, $method(ForkJoinPool, init$, void, int8_t)},
	{"awaitQuiescence", "(JLjava/util/concurrent/TimeUnit;)Z", nullptr, $PUBLIC, $virtualMethod(ForkJoinPool, awaitQuiescence, bool, int64_t, $TimeUnit*)},
	{"awaitTermination", "(JLjava/util/concurrent/TimeUnit;)Z", nullptr, $PUBLIC, $virtualMethod(ForkJoinPool, awaitTermination, bool, int64_t, $TimeUnit*), "java.lang.InterruptedException"},
	{"awaitWork", "(Ljava/util/concurrent/ForkJoinPool$WorkQueue;)I", nullptr, $PRIVATE, $method(ForkJoinPool, awaitWork, int32_t, $ForkJoinPool$WorkQueue*)},
	{"canStop", "()Z", nullptr, $FINAL, $method(ForkJoinPool, canStop, bool)},
	{"checkPermission", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(ForkJoinPool, checkPermission, void)},
	{"commonPool", "()Ljava/util/concurrent/ForkJoinPool;", nullptr, $PUBLIC | $STATIC, $staticMethod(ForkJoinPool, commonPool, ForkJoinPool*)},
	{"commonQueue", "()Ljava/util/concurrent/ForkJoinPool$WorkQueue;", nullptr, $STATIC, $staticMethod(ForkJoinPool, commonQueue, $ForkJoinPool$WorkQueue*)},
	{"compareAndExchangeCtl", "(JJ)J", nullptr, $PRIVATE, $method(ForkJoinPool, compareAndExchangeCtl, int64_t, int64_t, int64_t)},
	{"compareAndSetCtl", "(JJ)Z", nullptr, $PRIVATE, $method(ForkJoinPool, compareAndSetCtl, bool, int64_t, int64_t)},
	{"compensatedBlock", "(Ljava/util/concurrent/ForkJoinPool$ManagedBlocker;)V", nullptr, $PRIVATE, $method(ForkJoinPool, compensatedBlock, void, $ForkJoinPool$ManagedBlocker*), "java.lang.InterruptedException"},
	{"contextWithPermissions", "([Ljava/security/Permission;)Ljava/security/AccessControlContext;", nullptr, $STATIC | $TRANSIENT, $staticMethod(ForkJoinPool, contextWithPermissions, $AccessControlContext*, $PermissionArray*)},
	{"createWorker", "()Z", nullptr, $PRIVATE, $method(ForkJoinPool, createWorker, bool)},
	{"deregisterWorker", "(Ljava/util/concurrent/ForkJoinWorkerThread;Ljava/lang/Throwable;)V", nullptr, $FINAL, $method(ForkJoinPool, deregisterWorker, void, $ForkJoinWorkerThread*, $Throwable*)},
	{"drainTasksTo", "(Ljava/util/Collection;)I", "(Ljava/util/Collection<-Ljava/util/concurrent/ForkJoinTask<*>;>;)I", $PROTECTED, $virtualMethod(ForkJoinPool, drainTasksTo, int32_t, $Collection*)},
	{"execute", "(Ljava/util/concurrent/ForkJoinTask;)V", "(Ljava/util/concurrent/ForkJoinTask<*>;)V", $PUBLIC, $virtualMethod(ForkJoinPool, execute, void, $ForkJoinTask*)},
	{"execute", "(Ljava/lang/Runnable;)V", nullptr, $PUBLIC, $virtualMethod(ForkJoinPool, execute, void, $Runnable*)},
	{"externalHelpQuiescePool", "(JZ)I", nullptr, $FINAL, $method(ForkJoinPool, externalHelpQuiescePool, int32_t, int64_t, bool)},
	{"externalPush", "(Ljava/util/concurrent/ForkJoinTask;)V", "(Ljava/util/concurrent/ForkJoinTask<*>;)V", $FINAL, $method(ForkJoinPool, externalPush, void, $ForkJoinTask*)},
	{"externalQueue", "()Ljava/util/concurrent/ForkJoinPool$WorkQueue;", nullptr, $FINAL, $method(ForkJoinPool, externalQueue, $ForkJoinPool$WorkQueue*)},
	{"externalSubmit", "(Ljava/util/concurrent/ForkJoinTask;)Ljava/util/concurrent/ForkJoinTask;", "<T:Ljava/lang/Object;>(Ljava/util/concurrent/ForkJoinTask<TT;>;)Ljava/util/concurrent/ForkJoinTask<TT;>;", $PRIVATE, $method(ForkJoinPool, externalSubmit, $ForkJoinTask*, $ForkJoinTask*)},
	{"getActiveThreadCount", "()I", nullptr, $PUBLIC, $virtualMethod(ForkJoinPool, getActiveThreadCount, int32_t)},
	{"getAndAddCtl", "(J)J", nullptr, $PRIVATE, $method(ForkJoinPool, getAndAddCtl, int64_t, int64_t)},
	{"getAndAddPoolIds", "(I)I", nullptr, $PRIVATE | $STATIC, $staticMethod(ForkJoinPool, getAndAddPoolIds, int32_t, int32_t)},
	{"getAndAddThreadIds", "(I)I", nullptr, $PRIVATE, $method(ForkJoinPool, getAndAddThreadIds, int32_t, int32_t)},
	{"getAndBitwiseOrMode", "(I)I", nullptr, $PRIVATE, $method(ForkJoinPool, getAndBitwiseOrMode, int32_t, int32_t)},
	{"getAsyncMode", "()Z", nullptr, $PUBLIC, $virtualMethod(ForkJoinPool, getAsyncMode, bool)},
	{"getCommonPoolParallelism", "()I", nullptr, $PUBLIC | $STATIC, $staticMethod(ForkJoinPool, getCommonPoolParallelism, int32_t)},
	{"getFactory", "()Ljava/util/concurrent/ForkJoinPool$ForkJoinWorkerThreadFactory;", nullptr, $PUBLIC, $virtualMethod(ForkJoinPool, getFactory, $ForkJoinPool$ForkJoinWorkerThreadFactory*)},
	{"getParallelism", "()I", nullptr, $PUBLIC, $virtualMethod(ForkJoinPool, getParallelism, int32_t)},
	{"getPoolSize", "()I", nullptr, $PUBLIC, $virtualMethod(ForkJoinPool, getPoolSize, int32_t)},
	{"getQueuedSubmissionCount", "()I", nullptr, $PUBLIC, $virtualMethod(ForkJoinPool, getQueuedSubmissionCount, int32_t)},
	{"getQueuedTaskCount", "()J", nullptr, $PUBLIC, $virtualMethod(ForkJoinPool, getQueuedTaskCount, int64_t)},
	{"getRunningThreadCount", "()I", nullptr, $PUBLIC, $virtualMethod(ForkJoinPool, getRunningThreadCount, int32_t)},
	{"getStealCount", "()J", nullptr, $PUBLIC, $virtualMethod(ForkJoinPool, getStealCount, int64_t)},
	{"getSurplusQueuedTaskCount", "()I", nullptr, $STATIC, $staticMethod(ForkJoinPool, getSurplusQueuedTaskCount, int32_t)},
	{"getUncaughtExceptionHandler", "()Ljava/lang/Thread$UncaughtExceptionHandler;", nullptr, $PUBLIC, $virtualMethod(ForkJoinPool, getUncaughtExceptionHandler, $Thread$UncaughtExceptionHandler*)},
	{"hasQueuedSubmissions", "()Z", nullptr, $PUBLIC, $virtualMethod(ForkJoinPool, hasQueuedSubmissions, bool)},
	{"helpAsyncBlocker", "(Ljava/util/concurrent/Executor;Ljava/util/concurrent/ForkJoinPool$ManagedBlocker;)V", nullptr, $STATIC, $staticMethod(ForkJoinPool, helpAsyncBlocker, void, $Executor*, $ForkJoinPool$ManagedBlocker*)},
	{"helpComplete", "(Ljava/util/concurrent/ForkJoinTask;Ljava/util/concurrent/ForkJoinPool$WorkQueue;Z)I", "(Ljava/util/concurrent/ForkJoinTask<*>;Ljava/util/concurrent/ForkJoinPool$WorkQueue;Z)I", $FINAL, $method(ForkJoinPool, helpComplete, int32_t, $ForkJoinTask*, $ForkJoinPool$WorkQueue*, bool)},
	{"helpJoin", "(Ljava/util/concurrent/ForkJoinTask;Ljava/util/concurrent/ForkJoinPool$WorkQueue;Z)I", "(Ljava/util/concurrent/ForkJoinTask<*>;Ljava/util/concurrent/ForkJoinPool$WorkQueue;Z)I", $FINAL, $method(ForkJoinPool, helpJoin, int32_t, $ForkJoinTask*, $ForkJoinPool$WorkQueue*, bool)},
	{"helpQuiescePool", "(Ljava/util/concurrent/ForkJoinPool$WorkQueue;JZ)I", nullptr, $FINAL, $method(ForkJoinPool, helpQuiescePool, int32_t, $ForkJoinPool$WorkQueue*, int64_t, bool)},
	{"invoke", "(Ljava/util/concurrent/ForkJoinTask;)Ljava/lang/Object;", "<T:Ljava/lang/Object;>(Ljava/util/concurrent/ForkJoinTask<TT;>;)TT;", $PUBLIC, $virtualMethod(ForkJoinPool, invoke, $Object*, $ForkJoinTask*)},
	{"invokeAll", "(Ljava/util/Collection;)Ljava/util/List;", "<T:Ljava/lang/Object;>(Ljava/util/Collection<+Ljava/util/concurrent/Callable<TT;>;>;)Ljava/util/List<Ljava/util/concurrent/Future<TT;>;>;", $PUBLIC, $virtualMethod(ForkJoinPool, invokeAll, $List*, $Collection*)},
	{"invokeAll", "(Ljava/util/Collection;JLjava/util/concurrent/TimeUnit;)Ljava/util/List;", "<T:Ljava/lang/Object;>(Ljava/util/Collection<+Ljava/util/concurrent/Callable<TT;>;>;JLjava/util/concurrent/TimeUnit;)Ljava/util/List<Ljava/util/concurrent/Future<TT;>;>;", $PUBLIC, $virtualMethod(ForkJoinPool, invokeAll, $List*, $Collection*, int64_t, $TimeUnit*), "java.lang.InterruptedException"},
	{"invokeAny", "(Ljava/util/Collection;)Ljava/lang/Object;", "<T:Ljava/lang/Object;>(Ljava/util/Collection<+Ljava/util/concurrent/Callable<TT;>;>;)TT;", $PUBLIC, $virtualMethod(ForkJoinPool, invokeAny, $Object*, $Collection*), "java.lang.InterruptedException,java.util.concurrent.ExecutionException"},
	{"invokeAny", "(Ljava/util/Collection;JLjava/util/concurrent/TimeUnit;)Ljava/lang/Object;", "<T:Ljava/lang/Object;>(Ljava/util/Collection<+Ljava/util/concurrent/Callable<TT;>;>;JLjava/util/concurrent/TimeUnit;)TT;", $PUBLIC, $virtualMethod(ForkJoinPool, invokeAny, $Object*, $Collection*, int64_t, $TimeUnit*), "java.lang.InterruptedException,java.util.concurrent.ExecutionException,java.util.concurrent.TimeoutException"},
	{"isQuiescent", "()Z", nullptr, $PUBLIC, $virtualMethod(ForkJoinPool, isQuiescent, bool)},
	{"isShutdown", "()Z", nullptr, $PUBLIC, $virtualMethod(ForkJoinPool, isShutdown, bool)},
	{"isTerminated", "()Z", nullptr, $PUBLIC, $virtualMethod(ForkJoinPool, isTerminated, bool)},
	{"isTerminating", "()Z", nullptr, $PUBLIC, $virtualMethod(ForkJoinPool, isTerminating, bool)},
	{"managedBlock", "(Ljava/util/concurrent/ForkJoinPool$ManagedBlocker;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(ForkJoinPool, managedBlock, void, $ForkJoinPool$ManagedBlocker*), "java.lang.InterruptedException"},
	{"newInstanceFromSystemProperty", "(Ljava/lang/String;)Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC, $staticMethod(ForkJoinPool, newInstanceFromSystemProperty, $Object*, $String*), "java.lang.ReflectiveOperationException"},
	{"newTaskFor", "(Ljava/lang/Runnable;Ljava/lang/Object;)Ljava/util/concurrent/RunnableFuture;", "<T:Ljava/lang/Object;>(Ljava/lang/Runnable;TT;)Ljava/util/concurrent/RunnableFuture<TT;>;", $PROTECTED, $virtualMethod(ForkJoinPool, newTaskFor, $RunnableFuture*, $Runnable*, Object$*)},
	{"newTaskFor", "(Ljava/util/concurrent/Callable;)Ljava/util/concurrent/RunnableFuture;", "<T:Ljava/lang/Object;>(Ljava/util/concurrent/Callable<TT;>;)Ljava/util/concurrent/RunnableFuture<TT;>;", $PROTECTED, $virtualMethod(ForkJoinPool, newTaskFor, $RunnableFuture*, $Callable*)},
	{"nextTaskFor", "(Ljava/util/concurrent/ForkJoinPool$WorkQueue;)Ljava/util/concurrent/ForkJoinTask;", "(Ljava/util/concurrent/ForkJoinPool$WorkQueue;)Ljava/util/concurrent/ForkJoinTask<*>;", $FINAL, $method(ForkJoinPool, nextTaskFor, $ForkJoinTask*, $ForkJoinPool$WorkQueue*)},
	{"nextWorkerThreadName", "()Ljava/lang/String;", nullptr, $FINAL, $method(ForkJoinPool, nextWorkerThreadName, $String*)},
	{"pollScan", "(Z)Ljava/util/concurrent/ForkJoinTask;", "(Z)Ljava/util/concurrent/ForkJoinTask<*>;", $PRIVATE, $method(ForkJoinPool, pollScan, $ForkJoinTask*, bool)},
	{"pollSubmission", "()Ljava/util/concurrent/ForkJoinTask;", "()Ljava/util/concurrent/ForkJoinTask<*>;", $PROTECTED, $virtualMethod(ForkJoinPool, pollSubmission, $ForkJoinTask*)},
	{"registerWorker", "(Ljava/util/concurrent/ForkJoinPool$WorkQueue;)V", nullptr, $FINAL, $method(ForkJoinPool, registerWorker, void, $ForkJoinPool$WorkQueue*)},
	{"runWorker", "(Ljava/util/concurrent/ForkJoinPool$WorkQueue;)V", nullptr, $FINAL, $method(ForkJoinPool, runWorker, void, $ForkJoinPool$WorkQueue*)},
	{"scan", "(Ljava/util/concurrent/ForkJoinPool$WorkQueue;II)I", nullptr, $PRIVATE, $method(ForkJoinPool, scan, int32_t, $ForkJoinPool$WorkQueue*, int32_t, int32_t)},
	{"shutdown", "()V", nullptr, $PUBLIC, $virtualMethod(ForkJoinPool, shutdown, void)},
	{"shutdownNow", "()Ljava/util/List;", "()Ljava/util/List<Ljava/lang/Runnable;>;", $PUBLIC, $virtualMethod(ForkJoinPool, shutdownNow, $List*)},
	{"signalWork", "()V", nullptr, $FINAL, $method(ForkJoinPool, signalWork, void)},
	{"submissionQueue", "()Ljava/util/concurrent/ForkJoinPool$WorkQueue;", nullptr, $FINAL, $method(ForkJoinPool, submissionQueue, $ForkJoinPool$WorkQueue*)},
	{"submit", "(Ljava/util/concurrent/ForkJoinTask;)Ljava/util/concurrent/ForkJoinTask;", "<T:Ljava/lang/Object;>(Ljava/util/concurrent/ForkJoinTask<TT;>;)Ljava/util/concurrent/ForkJoinTask<TT;>;", $PUBLIC, $virtualMethod(ForkJoinPool, submit, $ForkJoinTask*, $ForkJoinTask*)},
	{"submit", "(Ljava/util/concurrent/Callable;)Ljava/util/concurrent/ForkJoinTask;", "<T:Ljava/lang/Object;>(Ljava/util/concurrent/Callable<TT;>;)Ljava/util/concurrent/ForkJoinTask<TT;>;", $PUBLIC, $virtualMethod(ForkJoinPool, submit, $Future*, $Callable*)},
	{"submit", "(Ljava/lang/Runnable;Ljava/lang/Object;)Ljava/util/concurrent/ForkJoinTask;", "<T:Ljava/lang/Object;>(Ljava/lang/Runnable;TT;)Ljava/util/concurrent/ForkJoinTask<TT;>;", $PUBLIC, $virtualMethod(ForkJoinPool, submit, $Future*, $Runnable*, Object$*)},
	{"submit", "(Ljava/lang/Runnable;)Ljava/util/concurrent/ForkJoinTask;", "(Ljava/lang/Runnable;)Ljava/util/concurrent/ForkJoinTask<*>;", $PUBLIC, $virtualMethod(ForkJoinPool, submit, $Future*, $Runnable*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ForkJoinPool, toString, $String*)},
	{"tryCompensate", "(J)I", nullptr, $PRIVATE, $method(ForkJoinPool, tryCompensate, int32_t, int64_t)},
	{"tryTerminate", "(ZZ)Z", nullptr, $PRIVATE, $method(ForkJoinPool, tryTerminate, bool, bool, bool)},
	{"uncompensate", "()V", nullptr, $FINAL, $method(ForkJoinPool, uncompensate, void)},
	{"unmanagedBlock", "(Ljava/util/concurrent/ForkJoinPool$ManagedBlocker;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(ForkJoinPool, unmanagedBlock, void, $ForkJoinPool$ManagedBlocker*), "java.lang.InterruptedException"},
	{}
};

$InnerClassInfo _ForkJoinPool_InnerClassesInfo_[] = {
	{"java.util.concurrent.ForkJoinPool$ManagedBlocker", "java.util.concurrent.ForkJoinPool", "ManagedBlocker", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.concurrent.ForkJoinPool$InvokeAnyTask", "java.util.concurrent.ForkJoinPool", "InvokeAnyTask", $STATIC | $FINAL},
	{"java.util.concurrent.ForkJoinPool$InvokeAnyRoot", "java.util.concurrent.ForkJoinPool", "InvokeAnyRoot", $STATIC | $FINAL},
	{"java.util.concurrent.ForkJoinPool$WorkQueue", "java.util.concurrent.ForkJoinPool", "WorkQueue", $STATIC | $FINAL},
	{"java.util.concurrent.ForkJoinPool$DefaultCommonPoolForkJoinWorkerThreadFactory", "java.util.concurrent.ForkJoinPool", "DefaultCommonPoolForkJoinWorkerThreadFactory", $STATIC | $FINAL},
	{"java.util.concurrent.ForkJoinPool$DefaultForkJoinWorkerThreadFactory", "java.util.concurrent.ForkJoinPool", "DefaultForkJoinWorkerThreadFactory", $STATIC | $FINAL},
	{"java.util.concurrent.ForkJoinPool$ForkJoinWorkerThreadFactory", "java.util.concurrent.ForkJoinPool", "ForkJoinWorkerThreadFactory", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.concurrent.ForkJoinPool$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ForkJoinPool_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.concurrent.ForkJoinPool",
	"java.util.concurrent.AbstractExecutorService",
	nullptr,
	_ForkJoinPool_FieldInfo_,
	_ForkJoinPool_MethodInfo_,
	nullptr,
	nullptr,
	_ForkJoinPool_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.concurrent.ForkJoinPool$ManagedBlocker,java.util.concurrent.ForkJoinPool$InvokeAnyTask,java.util.concurrent.ForkJoinPool$InvokeAnyRoot,java.util.concurrent.ForkJoinPool$WorkQueue,java.util.concurrent.ForkJoinPool$DefaultCommonPoolForkJoinWorkerThreadFactory,java.util.concurrent.ForkJoinPool$DefaultCommonPoolForkJoinWorkerThreadFactory$1,java.util.concurrent.ForkJoinPool$DefaultForkJoinWorkerThreadFactory,java.util.concurrent.ForkJoinPool$DefaultForkJoinWorkerThreadFactory$1,java.util.concurrent.ForkJoinPool$ForkJoinWorkerThreadFactory,java.util.concurrent.ForkJoinPool$1"
};

$Object* allocate$ForkJoinPool($Class* clazz) {
	return $of($alloc(ForkJoinPool));
}

$ForkJoinPool$ForkJoinWorkerThreadFactory* ForkJoinPool::defaultForkJoinWorkerThreadFactory = nullptr;
$RuntimePermission* ForkJoinPool::modifyThreadPermission = nullptr;
ForkJoinPool* ForkJoinPool::common = nullptr;
int32_t ForkJoinPool::COMMON_PARALLELISM = 0;
int32_t ForkJoinPool::COMMON_MAX_SPARES = 0;
$volatile(int32_t) ForkJoinPool::poolIds = 0;
$VarHandle* ForkJoinPool::CTL = nullptr;
$VarHandle* ForkJoinPool::MODE = nullptr;
$VarHandle* ForkJoinPool::THREADIDS = nullptr;
$VarHandle* ForkJoinPool::POOLIDS = nullptr;

void ForkJoinPool::checkPermission() {
	$init(ForkJoinPool);
	$var($SecurityManager, security, $System::getSecurityManager());
	if (security != nullptr) {
		security->checkPermission(ForkJoinPool::modifyThreadPermission);
	}
}

$AccessControlContext* ForkJoinPool::contextWithPermissions($PermissionArray* perms) {
	$init(ForkJoinPool);
	$useLocalCurrentObjectStackCache();
	$var($Permissions, permissions, $new($Permissions));
	{
		$var($PermissionArray, arr$, perms);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Permission, perm, arr$->get(i$));
			permissions->add(perm);
		}
	}
	return $new($AccessControlContext, $$new($ProtectionDomainArray, {$$new($ProtectionDomain, nullptr, permissions)}));
}

bool ForkJoinPool::compareAndSetCtl(int64_t c, int64_t v) {
	return $nc(ForkJoinPool::CTL)->compareAndSet($$new($ObjectArray, {$of(this), $$of(c), $$of(v)}));
}

int64_t ForkJoinPool::compareAndExchangeCtl(int64_t c, int64_t v) {
	return $longValue($nc(ForkJoinPool::CTL)->compareAndExchange($$new($ObjectArray, {$of(this), $$of(c), $$of(v)})));
}

int64_t ForkJoinPool::getAndAddCtl(int64_t v) {
	return $longValue($nc(ForkJoinPool::CTL)->getAndAdd($$new($ObjectArray, {$of(this), $$of(v)})));
}

int32_t ForkJoinPool::getAndBitwiseOrMode(int32_t v) {
	return $intValue($nc(ForkJoinPool::MODE)->getAndBitwiseOr($$new($ObjectArray, {$of(this), $$of(v)})));
}

int32_t ForkJoinPool::getAndAddThreadIds(int32_t x) {
	return $intValue($nc(ForkJoinPool::THREADIDS)->getAndAdd($$new($ObjectArray, {$of(this), $$of(x)})));
}

int32_t ForkJoinPool::getAndAddPoolIds(int32_t x) {
	$init(ForkJoinPool);
	return $intValue($nc(ForkJoinPool::POOLIDS)->getAndAdd($$new($ObjectArray, {$$of(x)})));
}

bool ForkJoinPool::createWorker() {
	$useLocalCurrentObjectStackCache();
	$var($ForkJoinPool$ForkJoinWorkerThreadFactory, fac, this->factory);
	$var($Throwable, ex, nullptr);
	$var($ForkJoinWorkerThread, wt, nullptr);
	try {
		if (fac != nullptr && ($assign(wt, fac->newThread(this))) != nullptr) {
			$nc(wt)->start();
			return true;
		}
	} catch ($Throwable& rex) {
		$assign(ex, rex);
	}
	deregisterWorker(wt, ex);
	return false;
}

$String* ForkJoinPool::nextWorkerThreadName() {
	$useLocalCurrentObjectStackCache();
	$var($String, prefix, this->workerNamePrefix);
	int32_t tid = getAndAddThreadIds(1) + 1;
	if (prefix == nullptr) {
		$assign(prefix, "ForkJoinPool.commonPool-worker-"_s);
	}
	return $nc(prefix)->concat($($Integer::toString(tid)));
}

void ForkJoinPool::registerWorker($ForkJoinPool$WorkQueue* w) {
	$useLocalCurrentObjectStackCache();
	$var($ReentrantLock, lock, this->registrationLock);
	$ThreadLocalRandom::localInit();
	int32_t seed = $ThreadLocalRandom::getProbe();
	if (w != nullptr && lock != nullptr) {
		int32_t modebits = ((int32_t)(this->mode & (uint32_t)ForkJoinPool::FIFO)) | w->config;
		$set(w, array, $new($ForkJoinTaskArray, ForkJoinPool::INITIAL_QUEUE_CAPACITY));
		w->stackPred = seed;
		if (((int32_t)(modebits & (uint32_t)ForkJoinPool::INNOCUOUS)) != 0) {
			w->initializeInnocuousWorker();
		}
		int32_t id = (seed << 1) | 1;
		lock->lock();
		{
			$var($Throwable, var$0, nullptr);
			try {
				$var($ForkJoinPool$WorkQueueArray, qs, nullptr);
				int32_t n = 0;
				bool var$1 = ($assign(qs, this->queues)) != nullptr;
				if (var$1 && (n = $nc(qs)->length) > 0) {
					int32_t k = n;
					int32_t m = n - 1;
					for (; qs->get(id &= (uint32_t)m) != nullptr && k > 0; id -= 2, k -= 2) {
					}
					if (k == 0) {
						id = n | 1;
					}
					w->phase = (w->config = id | modebits);
					if (id < n) {
						qs->set(id, w);
					} else {
						int32_t an = n << 1;
						int32_t am = an - 1;
						$var($ForkJoinPool$WorkQueueArray, as, $new($ForkJoinPool$WorkQueueArray, an));
						as->set((int32_t)(id & (uint32_t)am), w);
						for (int32_t j = 1; j < n; j += 2) {
							as->set(j, qs->get(j));
						}
						for (int32_t j = 0; j < n; j += 2) {
							$var($ForkJoinPool$WorkQueue, q, nullptr);
							if (($assign(q, qs->get(j))) != nullptr) {
								as->set((int32_t)($nc(q)->config & (uint32_t)am), q);
							}
						}
						$VarHandle::releaseFence();
						$set(this, queues, as);
					}
				}
			} catch ($Throwable& var$2) {
				$assign(var$0, var$2);
			} /*finally*/ {
				lock->unlock();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
}

void ForkJoinPool::deregisterWorker($ForkJoinWorkerThread* wt, $Throwable* ex) {
	$useLocalCurrentObjectStackCache();
	$var($ReentrantLock, lock, this->registrationLock);
	$var($ForkJoinPool$WorkQueue, w, nullptr);
	int32_t cfg = 0;
	if (wt != nullptr && ($assign(w, wt->workQueue)) != nullptr && lock != nullptr) {
		$var($ForkJoinPool$WorkQueueArray, qs, nullptr);
		int32_t n = 0;
		int32_t i = 0;
		cfg = $nc(w)->config;
		int64_t ns = (int64_t)(w->nsteals & (uint64_t)(int64_t)0x00000000FFFFFFFF);
		lock->lock();
		bool var$1 = ($assign(qs, this->queues)) != nullptr;
		bool var$0 = var$1 && (n = $nc(qs)->length) > 0;
		if (var$0 && qs->get(i = (int32_t)(cfg & (uint32_t)(n - 1))) == w) {
			qs->set(i, nullptr);
		}
		this->stealCount += ns;
		lock->unlock();
		int64_t c = this->ctl;
		if (((int32_t)(cfg & (uint32_t)ForkJoinPool::QUIET)) == 0) {
			int64_t var$2 = 0;
			do {
				var$2 = c;
			} while (var$2 != (c = compareAndExchangeCtl(c, ((((int64_t)(ForkJoinPool::RC_MASK & (uint64_t)(c - ForkJoinPool::RC_UNIT))) | ((int64_t)(ForkJoinPool::TC_MASK & (uint64_t)(c - ForkJoinPool::TC_UNIT)))) | ((int64_t)(ForkJoinPool::SP_MASK & (uint64_t)c))))));
		} else if ((int32_t)c == 0) {
			cfg = 0;
		}
		{
			$var($ForkJoinTask, t, nullptr);
			for (; ($assign(t, w->pop())) != nullptr;) {
				$ForkJoinTask::cancelIgnoringExceptions(t);
			}
		}
	}
	if (!tryTerminate(false, false) && w != nullptr && ((int32_t)(cfg & (uint32_t)ForkJoinPool::SRC)) != 0) {
		signalWork();
	}
	if (ex != nullptr) {
		$ForkJoinTask::rethrow(ex);
	}
}

void ForkJoinPool::signalWork() {
	$useLocalCurrentObjectStackCache();
	for (int64_t c = this->ctl; c < (int64_t)0;) {
		int32_t sp = 0;
		int32_t i = 0;
		$var($ForkJoinPool$WorkQueueArray, qs, nullptr);
		$var($ForkJoinPool$WorkQueue, v, nullptr);
		if ((sp = (int32_t)((int32_t)c & (uint32_t)~ForkJoinPool::UNSIGNALLED)) == 0) {
			if (((int64_t)(c & (uint64_t)ForkJoinPool::ADD_WORKER)) == (int64_t)0) {
				break;
			}
			int64_t var$0 = c;
			if (var$0 == (c = compareAndExchangeCtl(c, (((int64_t)(ForkJoinPool::RC_MASK & (uint64_t)(c + ForkJoinPool::RC_UNIT))) | ((int64_t)(ForkJoinPool::TC_MASK & (uint64_t)(c + ForkJoinPool::TC_UNIT))))))) {
				createWorker();
				break;
			}
		} else if (($assign(qs, this->queues)) == nullptr) {
			break;
		} else if ($nc(qs)->length <= (i = (int32_t)(sp & (uint32_t)ForkJoinPool::SMASK))) {
			break;
		} else if (($assign(v, qs->get(i))) == nullptr) {
			break;
		} else {
			int64_t nc = ((int64_t)($nc(v)->stackPred & (uint64_t)ForkJoinPool::SP_MASK)) | ((int64_t)(ForkJoinPool::UC_MASK & (uint64_t)(c + ForkJoinPool::RC_UNIT)));
			$var($Thread, vt, v->owner);
			int64_t var$1 = c;
			if (var$1 == (c = compareAndExchangeCtl(c, nc))) {
				v->phase = sp;
				$LockSupport::unpark(vt);
				break;
			}
		}
	}
}

void ForkJoinPool::runWorker($ForkJoinPool$WorkQueue* w) {
	if (this->mode >= 0 && w != nullptr) {
		w->config |= ForkJoinPool::SRC;
		int32_t r = w->stackPred;
		int32_t src = 0;
		bool var$0 = false;
		do {
			r ^= r << 13;
			r ^= (int32_t)((uint32_t)r >> 17);
			r ^= r << 5;
			var$0 = (src = scan(w, src, r)) >= 0;
		} while (var$0 || (src = awaitWork(w)) == 0);
	}
}

int32_t ForkJoinPool::scan($ForkJoinPool$WorkQueue* w, int32_t prevSrc, int32_t r) {
	$useLocalCurrentObjectStackCache();
	$var($ForkJoinPool$WorkQueueArray, qs, this->queues);
	int32_t n = (w == nullptr || qs == nullptr) ? 0 : $nc(qs)->length;
	{
		int32_t step = ((int32_t)((uint32_t)r >> 16)) | 1;
		int32_t i = n;
		for (; i > 0; --i, r += step) {
			int32_t j = 0;
			int32_t cap = 0;
			int32_t b = 0;
			$var($ForkJoinPool$WorkQueue, q, nullptr);
			$var($ForkJoinTaskArray, a, nullptr);
			bool var$1 = ($assign(q, qs->get(j = (int32_t)(r & (uint32_t)(n - 1))))) != nullptr;
			bool var$0 = var$1 && ($assign(a, $nc(q)->array)) != nullptr;
			if (var$0 && (cap = $nc(a)->length) > 0) {
				int32_t k = (int32_t)((cap - 1) & (uint32_t)(b = q->base));
				int32_t nextBase = b + 1;
				int32_t nextIndex = (int32_t)((cap - 1) & (uint32_t)nextBase);
				int32_t src = j | ForkJoinPool::SRC;
				$var($ForkJoinTask, t, $ForkJoinPool$WorkQueue::getSlot(a, k));
				if (q->base != b) {
					return prevSrc;
				} else if (t != nullptr && $ForkJoinPool$WorkQueue::casSlotToNull(a, k, t)) {
					q->base = nextBase;
					$var($ForkJoinTask, next, a->get(nextIndex));
					if (($nc(w)->source = src) != prevSrc && next != nullptr) {
						signalWork();
					}
					$nc(w)->topLevelExec(t, q);
					return src;
				} else if (a->get(nextIndex) != nullptr) {
					return prevSrc;
				}
			}
		}
	}
	return (this->queues != qs) ? prevSrc : -1;
}

int32_t ForkJoinPool::awaitWork($ForkJoinPool$WorkQueue* w) {
	$useLocalCurrentObjectStackCache();
	if (w == nullptr) {
		return -1;
	}
	int32_t phase = (int32_t)(($nc(w)->phase + ForkJoinPool::SS_SEQ) & (uint32_t)~ForkJoinPool::UNSIGNALLED);
	w->phase = phase | ForkJoinPool::UNSIGNALLED;
	int64_t prevCtl = this->ctl;
	int64_t c = 0;
	int64_t var$0 = 0;
	do {
		w->stackPred = (int32_t)prevCtl;
		c = ((int64_t)((prevCtl - ForkJoinPool::RC_UNIT) & (uint64_t)ForkJoinPool::UC_MASK)) | ((int64_t)(phase & (uint64_t)ForkJoinPool::SP_MASK));
		var$0 = prevCtl;
	} while (var$0 != (prevCtl = compareAndExchangeCtl(prevCtl, c)));
	$Thread::interrupted();
	$LockSupport::setCurrentBlocker(this);
	int64_t deadline = 0;
	int32_t ac = (int32_t)($sr(c, ForkJoinPool::RC_SHIFT));
	int32_t md = 0;
	if ((md = this->mode) < 0) {
		return -1;
	} else if (((int32_t)(md & (uint32_t)ForkJoinPool::SMASK)) + ac <= 0) {
		bool checkTermination = ((int32_t)(md & (uint32_t)ForkJoinPool::SHUTDOWN)) != 0;
		if ((deadline = $System::currentTimeMillis() + this->keepAlive) == (int64_t)0) {
			deadline = 1;
		}
		$var($ForkJoinPool$WorkQueueArray, qs, this->queues);
		int32_t n = (qs == nullptr) ? 0 : $nc(qs)->length;
		for (int32_t i = 0; i < n; i += 2) {
			$var($ForkJoinPool$WorkQueue, q, nullptr);
			$var($ForkJoinTaskArray, a, nullptr);
			int32_t cap = 0;
			int32_t b = 0;
			if (this->ctl != c) {
				checkTermination = false;
				break;
			} else {
				bool var$7 = ($assign(q, qs->get(i))) != nullptr;
				bool var$6 = var$7 && ($assign(a, $nc(q)->array)) != nullptr;
				bool var$5 = var$6 && (cap = $nc(a)->length) > 0;
				if (var$5) {
					bool var$8 = (b = q->base) != q->top;
					var$5 = (var$8 || a->get((int32_t)((cap - 1) & (uint32_t)b)) != nullptr || q->source != 0);
				}
				if (var$5) {
					if (compareAndSetCtl(c, prevCtl)) {
						w->phase = phase;
					}
					checkTermination = false;
					break;
				}
			}
		}
		if (checkTermination && tryTerminate(false, false)) {
			return -1;
		}
	}
	for (bool alt = false;;) {
		if (w->phase >= 0) {
			break;
		} else if (this->mode < 0) {
			return -1;
		} else if ((c = this->ctl) == prevCtl) {
			$Thread::onSpinWait();
		} else if (!(alt = !alt)) {
			$Thread::interrupted();
		} else if (deadline == (int64_t)0) {
			$LockSupport::park();
		} else if (deadline - $System::currentTimeMillis() > ForkJoinPool::TIMEOUT_SLOP) {
			$LockSupport::parkUntil(deadline);
		} else if (((int32_t)((int32_t)c & (uint32_t)ForkJoinPool::SMASK)) == ((int32_t)(w->config & (uint32_t)ForkJoinPool::SMASK)) && compareAndSetCtl(c, (((int64_t)(ForkJoinPool::UC_MASK & (uint64_t)(c - ForkJoinPool::TC_UNIT))) | ((int64_t)(prevCtl & (uint64_t)ForkJoinPool::SP_MASK))))) {
			w->config |= ForkJoinPool::QUIET;
			return -1;
		} else if ((deadline += this->keepAlive) == (int64_t)0) {
			deadline = 1;
		}
	}
	return 0;
}

bool ForkJoinPool::canStop() {
	$useLocalCurrentObjectStackCache();
	bool outer$break = false;
	for (int64_t oldSum = 0;;) {
		int32_t md = 0;
		$var($ForkJoinPool$WorkQueueArray, qs, nullptr);
		int64_t c = 0;
		if (($assign(qs, this->queues)) == nullptr || ((int32_t)((md = this->mode) & (uint32_t)ForkJoinPool::STOP)) != 0) {
			return true;
		}
		if (((int32_t)(md & (uint32_t)ForkJoinPool::SMASK)) + (int32_t)($sr(c = this->ctl, ForkJoinPool::RC_SHIFT)) > 0) {
			break;
		}
		int64_t checkSum = c;
		for (int32_t i = 1; i < $nc(qs)->length; i += 2) {
			$var($ForkJoinPool$WorkQueue, q, nullptr);
			$var($ForkJoinTaskArray, a, nullptr);
			int32_t s = 0;
			int32_t cap = 0;
			bool var$2 = ($assign(q, qs->get(i))) != nullptr;
			bool var$1 = var$2 && ($assign(a, $nc(q)->array)) != nullptr;
			bool var$0 = var$1 && (cap = $nc(a)->length) > 0;
			if (var$0) {
				bool var$3 = (s = q->top) != q->base;
				var$0 = (var$3 || a->get((int32_t)((cap - 1) & (uint32_t)s)) != nullptr || q->source != 0);
			}
			if (var$0) {
				outer$break = true;
				break;
			}
			checkSum += (((int64_t)i) << 32) ^ s;
		}
		if (outer$break) {
			break;
		}
		int64_t var$4 = oldSum;
		if (var$4 == (oldSum = checkSum) && this->queues == qs) {
			return true;
		}
	}
	return ((int32_t)(this->mode & (uint32_t)ForkJoinPool::STOP)) != 0;
}

int32_t ForkJoinPool::tryCompensate(int64_t c) {
	$useLocalCurrentObjectStackCache();
	$var($Predicate, sat, nullptr);
	int32_t md = this->mode;
	int32_t b = this->bounds;
	int32_t minActive = (int16_t)((int32_t)(b & (uint32_t)ForkJoinPool::SMASK));
	int32_t maxTotal = $usr(b, ForkJoinPool::SWIDTH);
	int32_t active = (int32_t)($sr(c, ForkJoinPool::RC_SHIFT));
	int32_t total = (int16_t)($usr(c, ForkJoinPool::TC_SHIFT));
	int32_t sp = (int32_t)((int32_t)c & (uint32_t)~ForkJoinPool::UNSIGNALLED);
	if (((int32_t)(md & (uint32_t)ForkJoinPool::SMASK)) == 0) {
		return 0;
	} else if (total >= 0) {
		if (sp != 0) {
			$var($ForkJoinPool$WorkQueueArray, qs, nullptr);
			int32_t n = 0;
			$var($ForkJoinPool$WorkQueue, v, nullptr);
			bool var$1 = ($assign(qs, this->queues)) != nullptr;
			bool var$0 = var$1 && (n = $nc(qs)->length) > 0;
			if (var$0 && ($assign(v, qs->get((int32_t)(sp & (uint32_t)(n - 1))))) != nullptr) {
				$var($Thread, vt, $nc(v)->owner);
				int64_t nc = ((int64_t)((int64_t)v->stackPred & (uint64_t)ForkJoinPool::SP_MASK)) | ((int64_t)(ForkJoinPool::UC_MASK & (uint64_t)c));
				if (compareAndSetCtl(c, nc)) {
					v->phase = sp;
					$LockSupport::unpark(vt);
					return ForkJoinPool::UNCOMPENSATE;
				}
			}
			return -1;
		} else if (active > minActive) {
			int64_t nc = (((int64_t)(ForkJoinPool::RC_MASK & (uint64_t)(c - ForkJoinPool::RC_UNIT))) | ((int64_t)(~ForkJoinPool::RC_MASK & (uint64_t)c)));
			return compareAndSetCtl(c, nc) ? ForkJoinPool::UNCOMPENSATE : -1;
		}
	}
	if (total < maxTotal) {
		int64_t nc = ((int64_t)((c + ForkJoinPool::TC_UNIT) & (uint64_t)ForkJoinPool::TC_MASK)) | ((int64_t)(c & (uint64_t)~ForkJoinPool::TC_MASK));
		return (!compareAndSetCtl(c, nc) ? -1 : !createWorker() ? 0 : ForkJoinPool::UNCOMPENSATE);
	} else if (!compareAndSetCtl(c, c)) {
		return -1;
	} else {
		bool var$3 = ($assign(sat, this->saturate)) != nullptr;
		if (var$3 && $nc(sat)->test(this)) {
			return 0;
		} else {
			$throwNew($RejectedExecutionException, "Thread limit exceeded replacing blocked worker"_s);
		}
	}
}

void ForkJoinPool::uncompensate() {
	getAndAddCtl(ForkJoinPool::RC_UNIT);
}

int32_t ForkJoinPool::helpJoin($ForkJoinTask* task, $ForkJoinPool$WorkQueue* w, bool canHelp) {
	$useLocalCurrentObjectStackCache();
	int32_t s = 0;
	if (task != nullptr && w != nullptr) {
		int32_t wsrc = w->source;
		int32_t wid = (int32_t)(w->config & (uint32_t)ForkJoinPool::SMASK);
		int32_t r = wid + 2;
		bool scan = true;
		int64_t c = 0;
		bool outer$break = false;
		for (;;) {
			if ((s = task->status) < 0) {
				break;
			} else if (scan = !scan) {
				if (this->mode < 0) {
					$ForkJoinTask::cancelIgnoringExceptions(task);
				} else {
					int64_t var$3 = c;
					bool var$2 = var$3 == (c = this->ctl);
					if (var$2 && (s = tryCompensate(c)) >= 0) {
						break;
					}
				}
			} else if (canHelp) {
				$var($ForkJoinPool$WorkQueueArray, qs, this->queues);
				int32_t n = (qs == nullptr) ? 0 : $nc(qs)->length;
				int32_t m = n - 1;
				for (int32_t i = n; i > 0; i -= 2, r += 2) {
					int32_t j = 0;
					$var($ForkJoinPool$WorkQueue, q, nullptr);
					$var($ForkJoinPool$WorkQueue, x, nullptr);
					$var($ForkJoinPool$WorkQueue, y, nullptr);
					$var($ForkJoinTaskArray, a, nullptr);
					if (($assign(q, qs->get(j = (int32_t)(r & (uint32_t)m)))) != nullptr) {
						int32_t sq = (int32_t)($nc(q)->source & (uint32_t)ForkJoinPool::SMASK);
						int32_t cap = 0;
						int32_t b = 0;
						bool var$4 = ($assign(a, q->array)) != nullptr;
						if (var$4 && (cap = $nc(a)->length) > 0) {
							int32_t k = (int32_t)((cap - 1) & (uint32_t)(b = q->base));
							int32_t nextBase = b + 1;
							int32_t src = j | ForkJoinPool::SRC;
							int32_t sx = 0;
							$var($ForkJoinTask, t, $ForkJoinPool$WorkQueue::getSlot(a, k));
							bool var$5 = sq == wid;
							if (!var$5) {
								bool var$6 = ($assign(x, qs->get((int32_t)(sq & (uint32_t)m)))) != nullptr;
								if (var$6) {
									bool var$7 = (sx = ((int32_t)($nc(x)->source & (uint32_t)ForkJoinPool::SMASK))) == wid;
									if (!var$7) {
										bool var$8 = ($assign(y, qs->get((int32_t)(sx & (uint32_t)m)))) != nullptr;
										var$7 = (var$8 && ((int32_t)($nc(y)->source & (uint32_t)ForkJoinPool::SMASK)) == wid);
									}
									var$6 = (var$7);
								}
								var$5 = (var$6);
							}
							bool eligible = var$5;
							if ((s = task->status) < 0) {
								outer$break = true;
								break;
							} else if (((int32_t)(q->source & (uint32_t)ForkJoinPool::SMASK)) != sq || q->base != b) {
								scan = true;
							} else if (t == nullptr) {
								scan |= (a->get((int32_t)(nextBase & (uint32_t)(cap - 1))) != nullptr || q->top != b);
							} else if (eligible) {
								if ($ForkJoinPool$WorkQueue::casSlotToNull(a, k, t)) {
									q->base = nextBase;
									w->source = src;
									$nc(t)->doExec();
									w->source = wsrc;
								}
								scan = true;
								break;
							}
						}
					}
				}
				if (outer$break) {
					break;
				}
			}
		}
	}
	return s;
}

int32_t ForkJoinPool::helpComplete($ForkJoinTask* task, $ForkJoinPool$WorkQueue* w, bool owned) {
	$useLocalCurrentObjectStackCache();
	int32_t s = 0;
	if (task != nullptr && w != nullptr) {
		int32_t r = w->config;
		bool scan = true;
		bool locals = true;
		int64_t c = 0;
		bool outer$break = false;
		for (;;) {
			if (locals) {
				if ((s = w->helpComplete(task, owned, 0)) < 0) {
					break;
				}
				locals = false;
			} else if ((s = task->status) < 0) {
				break;
			} else if (scan = !scan) {
				int64_t var$0 = c;
				if (var$0 == (c = this->ctl)) {
					break;
				}
			} else {
				$var($ForkJoinPool$WorkQueueArray, qs, this->queues);
				int32_t n = (qs == nullptr) ? 0 : $nc(qs)->length;
				for (int32_t i = n; i > 0; --i, ++r) {
					int32_t j = 0;
					int32_t cap = 0;
					int32_t b = 0;
					$var($ForkJoinPool$WorkQueue, q, nullptr);
					$var($ForkJoinTaskArray, a, nullptr);
					bool eligible = false;
					bool var$2 = ($assign(q, qs->get(j = (int32_t)(r & (uint32_t)(n - 1))))) != nullptr;
					bool var$1 = var$2 && ($assign(a, $nc(q)->array)) != nullptr;
					if (var$1 && (cap = $nc(a)->length) > 0) {
						int32_t k = (int32_t)((cap - 1) & (uint32_t)(b = q->base));
						int32_t nextBase = b + 1;
						$var($ForkJoinTask, t, $ForkJoinPool$WorkQueue::getSlot(a, k));
						if ($instanceOf($CountedCompleter, t)) {
							$var($CountedCompleter, f, $cast($CountedCompleter, t));
							bool var$3 = false;
							do {
								var$3 = !(eligible = ($equals(f, task)));
							} while (var$3 && ($assign(f, $nc(f)->completer)) != nullptr);
						}
						if ((s = task->status) < 0) {
							outer$break = true;
							break;
						} else if (q->base != b) {
							scan = true;
						} else if (t == nullptr) {
							scan |= (a->get((int32_t)(nextBase & (uint32_t)(cap - 1))) != nullptr || q->top != b);
						} else if (eligible) {
							if ($ForkJoinPool$WorkQueue::casSlotToNull(a, k, t)) {
								q->setBaseOpaque(nextBase);
								$nc(t)->doExec();
								locals = true;
							}
							scan = true;
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
	return s;
}

$ForkJoinTask* ForkJoinPool::pollScan(bool submissionsOnly) {
	$useLocalCurrentObjectStackCache();
	$VarHandle::acquireFence();
	int32_t r = this->scanRover += 0x61C88647;
	if (submissionsOnly) {
		r &= (uint32_t)~1;
	}
	int32_t step = (submissionsOnly) ? 2 : 1;
	$var($ForkJoinPool$WorkQueueArray, qs, nullptr);
	int32_t n = 0;
	while (true) {
		bool var$0 = ($assign(qs, this->queues)) != nullptr;
		if (!(var$0 && (n = $nc(qs)->length) > 0)) {
			break;
		}
		{
			bool scan = false;
			for (int32_t i = 0; i < n; i += step) {
				int32_t j = 0;
				int32_t cap = 0;
				int32_t b = 0;
				$var($ForkJoinPool$WorkQueue, q, nullptr);
				$var($ForkJoinTaskArray, a, nullptr);
				bool var$2 = ($assign(q, qs->get(j = (int32_t)((n - 1) & (uint32_t)(r + i))))) != nullptr;
				bool var$1 = var$2 && ($assign(a, $nc(q)->array)) != nullptr;
				if (var$1 && (cap = $nc(a)->length) > 0) {
					int32_t k = (int32_t)((cap - 1) & (uint32_t)(b = q->base));
					int32_t nextBase = b + 1;
					$var($ForkJoinTask, t, $ForkJoinPool$WorkQueue::getSlot(a, k));
					if (q->base != b) {
						scan = true;
					} else if (t == nullptr) {
						scan |= (q->top != b || a->get((int32_t)(nextBase & (uint32_t)(cap - 1))) != nullptr);
					} else if (!$ForkJoinPool$WorkQueue::casSlotToNull(a, k, t)) {
						scan = true;
					} else {
						q->setBaseOpaque(nextBase);
						return t;
					}
				}
			}
			if (!scan && this->queues == qs) {
				break;
			}
		}
	}
	return nullptr;
}

int32_t ForkJoinPool::helpQuiescePool($ForkJoinPool$WorkQueue* w, int64_t nanos, bool interruptible) {
	$useLocalCurrentObjectStackCache();
	if (w == nullptr) {
		return 0;
	}
	int64_t startTime = $System::nanoTime();
	int64_t parkTime = 0;
	int32_t prevSrc = $nc(w)->source;
	int32_t wsrc = prevSrc;
	int32_t cfg = w->config;
	int32_t r = cfg + 1;
	{
		bool active = true;
		bool locals = true;
		for (;;) {
			bool busy = false;
			bool scan = false;
			if (locals) {
				locals = false;
				{
					$var($ForkJoinTask, u, nullptr);
					for (; ($assign(u, w->nextLocalTask(cfg))) != nullptr;) {
						$nc(u)->doExec();
					}
				}
			}
			$var($ForkJoinPool$WorkQueueArray, qs, this->queues);
			int32_t n = (qs == nullptr) ? 0 : $nc(qs)->length;
			for (int32_t i = n; i > 0; --i, ++r) {
				int32_t j = 0;
				int32_t b = 0;
				int32_t cap = 0;
				$var($ForkJoinPool$WorkQueue, q, nullptr);
				$var($ForkJoinTaskArray, a, nullptr);
				bool var$2 = ($assign(q, qs->get(j = (int32_t)((n - 1) & (uint32_t)r)))) != nullptr;
				bool var$1 = var$2 && q != w;
				bool var$0 = var$1 && ($assign(a, $nc(q)->array)) != nullptr;
				if (var$0 && (cap = $nc(a)->length) > 0) {
					int32_t k = (int32_t)((cap - 1) & (uint32_t)(b = q->base));
					int32_t nextBase = b + 1;
					int32_t src = j | ForkJoinPool::SRC;
					$var($ForkJoinTask, t, $ForkJoinPool$WorkQueue::getSlot(a, k));
					if (q->base != b) {
						busy = (scan = true);
					} else if (t != nullptr) {
						busy = (scan = true);
						if (!active) {
							active = true;
							getAndAddCtl(ForkJoinPool::RC_UNIT);
						}
						if ($ForkJoinPool$WorkQueue::casSlotToNull(a, k, t)) {
							q->base = nextBase;
							w->source = src;
							t->doExec();
							w->source = (wsrc = prevSrc);
							locals = true;
						}
						break;
					} else if (!busy) {
						if (q->top != b || a->get((int32_t)(nextBase & (uint32_t)(cap - 1))) != nullptr) {
							busy = (scan = true);
						} else if (q->source != ForkJoinPool::QUIET && q->phase >= 0) {
							busy = true;
						}
					}
				}
			}
			$VarHandle::acquireFence();
			if (!scan && this->queues == qs) {
				bool interrupted = false;
				if (!busy) {
					w->source = prevSrc;
					if (!active) {
						getAndAddCtl(ForkJoinPool::RC_UNIT);
					}
					return 1;
				}
				if (wsrc != ForkJoinPool::QUIET) {
					w->source = (wsrc = ForkJoinPool::QUIET);
				}
				if (active) {
					active = false;
					parkTime = 0;
					getAndAddCtl((int64_t)(ForkJoinPool::RC_MASK & (uint64_t)-ForkJoinPool::RC_UNIT));
				} else if (parkTime == (int64_t)0) {
					parkTime = (int64_t)1 << 10;
					$Thread::yield();
				} else {
					bool var$4 = (interrupted = interruptible && $Thread::interrupted());
					if (var$4 || $System::nanoTime() - startTime > nanos) {
						getAndAddCtl(ForkJoinPool::RC_UNIT);
						return interrupted ? -1 : 0;
					} else {
						$LockSupport::parkNanos(this, parkTime);
						if (parkTime < (int64_t)((uint64_t)nanos >> 8) && parkTime < (int64_t)1 << 20) {
							parkTime <<= 1;
						}
					}
				}
			}
		}
	}
}

int32_t ForkJoinPool::externalHelpQuiescePool(int64_t nanos, bool interruptible) {
	$useLocalCurrentObjectStackCache();
	{
		int64_t startTime = $System::nanoTime();
		int64_t parkTime = 0;
		for (;;) {
			$var($ForkJoinTask, t, nullptr);
			if (($assign(t, pollScan(false))) != nullptr) {
				$nc(t)->doExec();
				parkTime = 0;
			} else if (canStop()) {
				return 1;
			} else if (parkTime == (int64_t)0) {
				parkTime = (int64_t)1 << 10;
				$Thread::yield();
			} else if (($System::nanoTime() - startTime) > nanos) {
				return 0;
			} else if (interruptible && $Thread::interrupted()) {
				return -1;
			} else {
				$LockSupport::parkNanos(this, parkTime);
				if (parkTime < (int64_t)((uint64_t)nanos >> 8) && parkTime < (int64_t)1 << 20) {
					parkTime <<= 1;
				}
			}
		}
	}
}

$ForkJoinTask* ForkJoinPool::nextTaskFor($ForkJoinPool$WorkQueue* w) {
	$var($ForkJoinTask, t, nullptr);
	if (w == nullptr || ($assign(t, $nc(w)->nextLocalTask(w->config))) == nullptr) {
		$assign(t, pollScan(false));
	}
	return t;
}

$ForkJoinPool$WorkQueue* ForkJoinPool::submissionQueue() {
	$useLocalCurrentObjectStackCache();
	int32_t r = 0;
	if ((r = $ThreadLocalRandom::getProbe()) == 0) {
		$ThreadLocalRandom::localInit();
		r = $ThreadLocalRandom::getProbe();
	}
	for (int32_t id = r << 1;;) {
		int32_t md = this->mode;
		int32_t n = 0;
		int32_t i = 0;
		$var($ForkJoinPool$WorkQueue, q, nullptr);
		$var($ReentrantLock, lock, nullptr);
		$var($ForkJoinPool$WorkQueueArray, qs, this->queues);
		if (((int32_t)(md & (uint32_t)ForkJoinPool::SHUTDOWN)) != 0 || qs == nullptr || (n = $nc(qs)->length) <= 0) {
			return nullptr;
		} else if (($assign(q, qs->get(i = (int32_t)((n - 1) & (uint32_t)id)))) == nullptr) {
			if (($assign(lock, this->registrationLock)) != nullptr) {
				$var($ForkJoinPool$WorkQueue, w, $new($ForkJoinPool$WorkQueue, id | ForkJoinPool::SRC));
				$nc(lock)->lock();
				if (qs->get(i) == nullptr) {
					qs->set(i, w);
				}
				lock->unlock();
			}
		} else if (!$nc(q)->tryLock()) {
			id = (r = $ThreadLocalRandom::advanceProbe(r)) << 1;
		} else {
			return q;
		}
	}
}

void ForkJoinPool::externalPush($ForkJoinTask* task) {
	$var($ForkJoinPool$WorkQueue, q, nullptr);
	if (($assign(q, submissionQueue())) == nullptr) {
		$throwNew($RejectedExecutionException);
	} else if ($nc(q)->lockedPush(task)) {
		signalWork();
	}
}

$ForkJoinTask* ForkJoinPool::externalSubmit($ForkJoinTask* task) {
	$useLocalCurrentObjectStackCache();
	$var($Thread, t, nullptr);
	$var($ForkJoinWorkerThread, wt, nullptr);
	$var($ForkJoinPool$WorkQueue, q, nullptr);
	if (task == nullptr) {
		$throwNew($NullPointerException);
	}
	bool var$0 = ($instanceOf($ForkJoinWorkerThread, $assign(t, $Thread::currentThread()))) && ($assign(q, $nc(($assign(wt, $cast($ForkJoinWorkerThread, t))))->workQueue)) != nullptr;
	if (var$0 && $nc(wt)->pool == this) {
		$nc(q)->push(task, this);
	} else {
		externalPush(task);
	}
	return task;
}

$ForkJoinPool$WorkQueue* ForkJoinPool::commonQueue() {
	$init(ForkJoinPool);
	$useLocalCurrentObjectStackCache();
	$var(ForkJoinPool, p, nullptr);
	$var($ForkJoinPool$WorkQueueArray, qs, nullptr);
	int32_t r = $ThreadLocalRandom::getProbe();
	int32_t n = 0;
	bool var$1 = ($assign(p, ForkJoinPool::common)) != nullptr;
	bool var$0 = var$1 && ($assign(qs, $nc(p)->queues)) != nullptr;
	return (var$0 && (n = $nc(qs)->length) > 0 && r != 0) ? $nc(qs)->get((int32_t)((n - 1) & (uint32_t)(r << 1))) : ($ForkJoinPool$WorkQueue*)nullptr;
}

$ForkJoinPool$WorkQueue* ForkJoinPool::externalQueue() {
	$var($ForkJoinPool$WorkQueueArray, qs, nullptr);
	int32_t r = $ThreadLocalRandom::getProbe();
	int32_t n = 0;
	bool var$0 = ($assign(qs, this->queues)) != nullptr;
	return (var$0 && (n = $nc(qs)->length) > 0 && r != 0) ? $nc(qs)->get((int32_t)((n - 1) & (uint32_t)(r << 1))) : ($ForkJoinPool$WorkQueue*)nullptr;
}

void ForkJoinPool::helpAsyncBlocker($Executor* e, $ForkJoinPool$ManagedBlocker* blocker) {
	$init(ForkJoinPool);
	$useLocalCurrentObjectStackCache();
	$var($ForkJoinPool$WorkQueue, w, nullptr);
	$var($Thread, t, nullptr);
	$var($ForkJoinWorkerThread, wt, nullptr);
	if ($instanceOf($ForkJoinWorkerThread, $assign(t, $Thread::currentThread()))) {
		if ($equals($nc(($assign(wt, $cast($ForkJoinWorkerThread, t))))->pool, e)) {
			$assign(w, wt->workQueue);
		}
	} else if ($instanceOf(ForkJoinPool, e)) {
		$assign(w, $nc(($cast(ForkJoinPool, e)))->externalQueue());
	}
	if (w != nullptr) {
		w->helpAsyncBlocker(blocker);
	}
}

int32_t ForkJoinPool::getSurplusQueuedTaskCount() {
	$init(ForkJoinPool);
	$useLocalCurrentObjectStackCache();
	$var($Thread, t, nullptr);
	$var($ForkJoinWorkerThread, wt, nullptr);
	$var(ForkJoinPool, pool, nullptr);
	$var($ForkJoinPool$WorkQueue, q, nullptr);
	if (($instanceOf($ForkJoinWorkerThread, $assign(t, $Thread::currentThread()))) && ($assign(pool, $nc(($assign(wt, $cast($ForkJoinWorkerThread, t))))->pool)) != nullptr && ($assign(q, $nc(wt)->workQueue)) != nullptr) {
		int32_t p = (int32_t)($nc(pool)->mode & (uint32_t)ForkJoinPool::SMASK);
		int32_t a = p + (int32_t)($sr(pool->ctl, ForkJoinPool::RC_SHIFT));
		int32_t n = $nc(q)->top - q->base;
		return n - (a > ($usrAssign(p, 1)) ? 0 : a > ($usrAssign(p, 1)) ? 1 : a > ($usrAssign(p, 1)) ? 2 : a > ($usrAssign(p, 1)) ? 4 : 8);
	}
	return 0;
}

bool ForkJoinPool::tryTerminate(bool now, bool enable) {
	$useLocalCurrentObjectStackCache();
	int32_t md = 0;
	if (((int32_t)((md = this->mode) & (uint32_t)ForkJoinPool::SHUTDOWN)) == 0) {
		if (!enable) {
			return false;
		}
		md = getAndBitwiseOrMode(ForkJoinPool::SHUTDOWN);
	}
	if (((int32_t)(md & (uint32_t)ForkJoinPool::STOP)) == 0) {
		if (!now && !canStop()) {
			return false;
		}
		md = getAndBitwiseOrMode(ForkJoinPool::STOP);
	}
	for (bool rescan = true;;) {
		bool changed = false;
		{
			$var($ForkJoinTask, t, nullptr);
			for (; ($assign(t, pollScan(false))) != nullptr;) {
				changed = true;
				$ForkJoinTask::cancelIgnoringExceptions(t);
			}
		}
		$var($ForkJoinPool$WorkQueueArray, qs, nullptr);
		int32_t n = 0;
		$var($ForkJoinPool$WorkQueue, q, nullptr);
		$var($Thread, thread, nullptr);
		bool var$0 = ($assign(qs, this->queues)) != nullptr;
		if (var$0 && (n = $nc(qs)->length) > 0) {
			for (int32_t j = 1; j < n; j += 2) {
				bool var$2 = ($assign(q, qs->get(j))) != nullptr;
				bool var$1 = var$2 && ($assign(thread, $nc(q)->owner)) != nullptr;
				if (var$1 && !$nc(thread)->isInterrupted()) {
					changed = true;
					try {
						thread->interrupt();
					} catch ($Throwable& ignore) {
					}
				}
			}
		}
		$var($ReentrantLock, lock, nullptr);
		$var($Condition, cond, nullptr);
		bool var$3 = ((int32_t)((md = this->mode) & (uint32_t)ForkJoinPool::TERMINATED)) == 0;
		if (var$3 && ((int32_t)(md & (uint32_t)ForkJoinPool::SMASK)) + (int16_t)($usr(this->ctl, ForkJoinPool::TC_SHIFT)) <= 0 && ((int32_t)(getAndBitwiseOrMode(ForkJoinPool::TERMINATED) & (uint32_t)ForkJoinPool::TERMINATED)) == 0 && ($assign(lock, this->registrationLock)) != nullptr) {
			$nc(lock)->lock();
			if (($assign(cond, this->termination)) != nullptr) {
				$nc(cond)->signalAll();
			}
			lock->unlock();
		}
		if (changed) {
			rescan = true;
		} else if (rescan) {
			rescan = false;
		} else {
			break;
		}
	}
	return true;
}

void ForkJoinPool::init$() {
	$init($TimeUnit);
	ForkJoinPool::init$($Math::min(ForkJoinPool::MAX_CAP, $nc($($Runtime::getRuntime()))->availableProcessors()), ForkJoinPool::defaultForkJoinWorkerThreadFactory, nullptr, false, 0, ForkJoinPool::MAX_CAP, 1, nullptr, ForkJoinPool::DEFAULT_KEEPALIVE, $TimeUnit::MILLISECONDS);
}

void ForkJoinPool::init$(int32_t parallelism) {
	$init($TimeUnit);
	ForkJoinPool::init$(parallelism, ForkJoinPool::defaultForkJoinWorkerThreadFactory, nullptr, false, 0, ForkJoinPool::MAX_CAP, 1, nullptr, ForkJoinPool::DEFAULT_KEEPALIVE, $TimeUnit::MILLISECONDS);
}

void ForkJoinPool::init$(int32_t parallelism, $ForkJoinPool$ForkJoinWorkerThreadFactory* factory, $Thread$UncaughtExceptionHandler* handler, bool asyncMode) {
	$init($TimeUnit);
	ForkJoinPool::init$(parallelism, factory, handler, asyncMode, 0, ForkJoinPool::MAX_CAP, 1, nullptr, ForkJoinPool::DEFAULT_KEEPALIVE, $TimeUnit::MILLISECONDS);
}

void ForkJoinPool::init$(int32_t parallelism, $ForkJoinPool$ForkJoinWorkerThreadFactory* factory, $Thread$UncaughtExceptionHandler* handler, bool asyncMode, int32_t corePoolSize, int32_t maximumPoolSize, int32_t minimumRunnable, $Predicate* saturate, int64_t keepAliveTime, $TimeUnit* unit) {
	$AbstractExecutorService::init$();
	checkPermission();
	int32_t p = parallelism;
	if (p <= 0 || p > ForkJoinPool::MAX_CAP || p > maximumPoolSize || keepAliveTime <= (int64_t)0) {
		$throwNew($IllegalArgumentException);
	}
	if (factory == nullptr || unit == nullptr) {
		$throwNew($NullPointerException);
	}
	$set(this, factory, factory);
	$set(this, ueh, handler);
	$set(this, saturate, saturate);
	this->keepAlive = $Math::max($nc(unit)->toMillis(keepAliveTime), ForkJoinPool::TIMEOUT_SLOP);
	int32_t size = $sl(1, 33 - $Integer::numberOfLeadingZeros(p - 1));
	int32_t corep = $Math::min($Math::max(corePoolSize, p), ForkJoinPool::MAX_CAP);
	int32_t maxSpares = $Math::min(maximumPoolSize, ForkJoinPool::MAX_CAP) - p;
	int32_t minAvail = $Math::min($Math::max(minimumRunnable, 0), ForkJoinPool::MAX_CAP);
	this->bounds = ((int32_t)((minAvail - p) & (uint32_t)ForkJoinPool::SMASK)) | ($sl(maxSpares, ForkJoinPool::SWIDTH));
	this->mode = p | (asyncMode ? ForkJoinPool::FIFO : 0);
	this->ctl = (((int64_t)(($sl((int64_t)(-corep), ForkJoinPool::TC_SHIFT)) & (uint64_t)ForkJoinPool::TC_MASK)) | ((int64_t)(($sl((int64_t)(-p), ForkJoinPool::RC_SHIFT)) & (uint64_t)ForkJoinPool::RC_MASK)));
	$set(this, registrationLock, $new($ReentrantLock));
	$set(this, queues, $new($ForkJoinPool$WorkQueueArray, size));
	$var($String, pid, $Integer::toString(getAndAddPoolIds(1) + 1));
	$set(this, workerNamePrefix, $str({"ForkJoinPool-"_s, pid, "-worker-"_s}));
}

$Object* ForkJoinPool::newInstanceFromSystemProperty($String* property) {
	$init(ForkJoinPool);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($String, className, $System::getProperty(property));
	return $of((className == nullptr) ? ($Object*)nullptr : $nc($($nc($nc($($ClassLoader::getSystemClassLoader()))->loadClass(className))->getConstructor($$new($ClassArray, 0))))->newInstance($$new($ObjectArray, 0)));
}

void ForkJoinPool::init$(int8_t forCommonPoolOnly) {
	$useLocalCurrentObjectStackCache();
	$AbstractExecutorService::init$();
	int32_t parallelism = $nc($($Runtime::getRuntime()))->availableProcessors() - 1;
	$var($ForkJoinPool$ForkJoinWorkerThreadFactory, fac, nullptr);
	$var($Thread$UncaughtExceptionHandler, handler, nullptr);
	try {
		$assign(fac, $cast($ForkJoinPool$ForkJoinWorkerThreadFactory, newInstanceFromSystemProperty("java.util.concurrent.ForkJoinPool.common.threadFactory"_s)));
		$assign(handler, $cast($Thread$UncaughtExceptionHandler, newInstanceFromSystemProperty("java.util.concurrent.ForkJoinPool.common.exceptionHandler"_s)));
		$var($String, pp, $System::getProperty("java.util.concurrent.ForkJoinPool.common.parallelism"_s));
		if (pp != nullptr) {
			parallelism = $Integer::parseInt(pp);
		}
	} catch ($Exception& ignore) {
	}
	$set(this, ueh, handler);
	this->keepAlive = ForkJoinPool::DEFAULT_KEEPALIVE;
	$set(this, saturate, nullptr);
	$set(this, workerNamePrefix, nullptr);
	int32_t p = $Math::min($Math::max(parallelism, 0), ForkJoinPool::MAX_CAP);
	int32_t size = 0;
	this->mode = p;
	if (p > 0) {
		size = $sl(1, 33 - $Integer::numberOfLeadingZeros(p - 1));
		this->bounds = ((int32_t)((1 - p) & (uint32_t)ForkJoinPool::SMASK)) | ($sl(ForkJoinPool::COMMON_MAX_SPARES, ForkJoinPool::SWIDTH));
		this->ctl = (((int64_t)(($sl((int64_t)(-p), ForkJoinPool::TC_SHIFT)) & (uint64_t)ForkJoinPool::TC_MASK)) | ((int64_t)(($sl((int64_t)(-p), ForkJoinPool::RC_SHIFT)) & (uint64_t)ForkJoinPool::RC_MASK)));
	} else {
		size = 1;
		this->bounds = 0;
		this->ctl = 0;
	}
	$set(this, factory, (fac != nullptr) ? fac : static_cast<$ForkJoinPool$ForkJoinWorkerThreadFactory*>($new($ForkJoinPool$DefaultCommonPoolForkJoinWorkerThreadFactory)));
	$set(this, queues, $new($ForkJoinPool$WorkQueueArray, size));
	$set(this, registrationLock, $new($ReentrantLock));
}

ForkJoinPool* ForkJoinPool::commonPool() {
	$init(ForkJoinPool);
	return ForkJoinPool::common;
}

$Object* ForkJoinPool::invoke($ForkJoinTask* task) {
	externalSubmit(task);
	return $of($nc(task)->joinForPoolInvoke(this));
}

void ForkJoinPool::execute($ForkJoinTask* task) {
	externalSubmit(task);
}

void ForkJoinPool::execute($Runnable* task) {
	externalSubmit(($instanceOf($ForkJoinTask, task)) ? $cast($ForkJoinTask, task) : static_cast<$ForkJoinTask*>($$new($ForkJoinTask$RunnableExecuteAction, task)));
}

$ForkJoinTask* ForkJoinPool::submit($ForkJoinTask* task) {
	return externalSubmit(task);
}

$Future* ForkJoinPool::submit($Callable* task) {
	return externalSubmit($$new($ForkJoinTask$AdaptedCallable, task));
}

$Future* ForkJoinPool::submit($Runnable* task, Object$* result) {
	return externalSubmit($$new($ForkJoinTask$AdaptedRunnable, task, result));
}

$Future* ForkJoinPool::submit($Runnable* task) {
	return externalSubmit(($instanceOf($ForkJoinTask, task)) ? $cast($ForkJoinTask, task) : static_cast<$ForkJoinTask*>($$new($ForkJoinTask$AdaptedRunnableAction, task)));
}

$List* ForkJoinPool::invokeAll($Collection* tasks) {
	$useLocalCurrentObjectStackCache();
	$var($ArrayList, futures, $new($ArrayList, $nc(tasks)->size()));
	try {
		{
			$var($Iterator, i$, $nc(tasks)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Callable, t, $cast($Callable, i$->next()));
				{
					$var($ForkJoinTask, f, $new($ForkJoinTask$AdaptedInterruptibleCallable, t));
					futures->add(f);
					externalSubmit(f);
				}
			}
		}
		for (int32_t i = futures->size() - 1; i >= 0; --i) {
			$nc(($cast($ForkJoinTask, $(futures->get(i)))))->awaitPoolInvoke(this);
		}
		return futures;
	} catch ($Throwable& t) {
		{
			$var($Iterator, i$, futures->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Future, e, $cast($Future, i$->next()));
				$ForkJoinTask::cancelIgnoringExceptions(e);
			}
		}
		$throw(t);
	}
	$shouldNotReachHere();
}

$List* ForkJoinPool::invokeAll($Collection* tasks, int64_t timeout, $TimeUnit* unit) {
	$useLocalCurrentObjectStackCache();
	int64_t nanos = $nc(unit)->toNanos(timeout);
	$var($ArrayList, futures, $new($ArrayList, $nc(tasks)->size()));
	try {
		{
			$var($Iterator, i$, $nc(tasks)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Callable, t, $cast($Callable, i$->next()));
				{
					$var($ForkJoinTask, f, $new($ForkJoinTask$AdaptedInterruptibleCallable, t));
					futures->add(f);
					externalSubmit(f);
				}
			}
		}
		int64_t startTime = $System::nanoTime();
		int64_t ns = nanos;
		bool timedOut = (ns < (int64_t)0);
		for (int32_t i = futures->size() - 1; i >= 0; --i) {
			$var($Future, f, $cast($Future, futures->get(i)));
			if (!$nc(f)->isDone()) {
				if (timedOut) {
					$ForkJoinTask::cancelIgnoringExceptions(f);
				} else {
					$nc(($cast($ForkJoinTask, f)))->awaitPoolInvoke(this, ns);
					if ((ns = nanos - ($System::nanoTime() - startTime)) < (int64_t)0) {
						timedOut = true;
					}
				}
			}
		}
		return futures;
	} catch ($Throwable& t) {
		{
			$var($Iterator, i$, futures->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Future, e, $cast($Future, i$->next()));
				$ForkJoinTask::cancelIgnoringExceptions(e);
			}
		}
		$throw(t);
	}
	$shouldNotReachHere();
}

$Object* ForkJoinPool::invokeAny($Collection* tasks) {
	$useLocalCurrentObjectStackCache();
	int32_t n = $nc(tasks)->size();
	if (n <= 0) {
		$throwNew($IllegalArgumentException);
	}
	$var($ForkJoinPool$InvokeAnyRoot, root, $new($ForkJoinPool$InvokeAnyRoot, n, this));
	$var($ArrayList, fs, $new($ArrayList, n));
	{
		$var($Throwable, var$0, nullptr);
		$var($Object, var$2, nullptr);
		bool return$1 = false;
		try {
			{
				$var($Iterator, i$, tasks->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($Callable, c, $cast($Callable, i$->next()));
					{
						if (c == nullptr) {
							$throwNew($NullPointerException);
						}
						$var($ForkJoinPool$InvokeAnyTask, f, $new($ForkJoinPool$InvokeAnyTask, root, c));
						fs->add(f);
						externalSubmit(f);
						if (root->isDone()) {
							break;
						}
					}
				}
			}
			$assign(var$2, root->getForPoolInvoke(this));
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			{
				$var($Iterator, i$, fs->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($ForkJoinPool$InvokeAnyTask, f, $cast($ForkJoinPool$InvokeAnyTask, i$->next()));
					$ForkJoinTask::cancelIgnoringExceptions(f);
				}
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

$Object* ForkJoinPool::invokeAny($Collection* tasks, int64_t timeout, $TimeUnit* unit) {
	$useLocalCurrentObjectStackCache();
	int64_t nanos = $nc(unit)->toNanos(timeout);
	int32_t n = $nc(tasks)->size();
	if (n <= 0) {
		$throwNew($IllegalArgumentException);
	}
	$var($ForkJoinPool$InvokeAnyRoot, root, $new($ForkJoinPool$InvokeAnyRoot, n, this));
	$var($ArrayList, fs, $new($ArrayList, n));
	{
		$var($Throwable, var$0, nullptr);
		$var($Object, var$2, nullptr);
		bool return$1 = false;
		try {
			{
				$var($Iterator, i$, tasks->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($Callable, c, $cast($Callable, i$->next()));
					{
						if (c == nullptr) {
							$throwNew($NullPointerException);
						}
						$var($ForkJoinPool$InvokeAnyTask, f, $new($ForkJoinPool$InvokeAnyTask, root, c));
						fs->add(f);
						externalSubmit(f);
						if (root->isDone()) {
							break;
						}
					}
				}
			}
			$assign(var$2, root->getForPoolInvoke(this, nanos));
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			{
				$var($Iterator, i$, fs->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($ForkJoinPool$InvokeAnyTask, f, $cast($ForkJoinPool$InvokeAnyTask, i$->next()));
					$ForkJoinTask::cancelIgnoringExceptions(f);
				}
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

$ForkJoinPool$ForkJoinWorkerThreadFactory* ForkJoinPool::getFactory() {
	return this->factory;
}

$Thread$UncaughtExceptionHandler* ForkJoinPool::getUncaughtExceptionHandler() {
	return this->ueh;
}

int32_t ForkJoinPool::getParallelism() {
	int32_t par = (int32_t)(this->mode & (uint32_t)ForkJoinPool::SMASK);
	return (par > 0) ? par : 1;
}

int32_t ForkJoinPool::getCommonPoolParallelism() {
	$init(ForkJoinPool);
	return ForkJoinPool::COMMON_PARALLELISM;
}

int32_t ForkJoinPool::getPoolSize() {
	return (((int32_t)(this->mode & (uint32_t)ForkJoinPool::SMASK)) + (int16_t)($usr(this->ctl, ForkJoinPool::TC_SHIFT)));
}

bool ForkJoinPool::getAsyncMode() {
	return ((int32_t)(this->mode & (uint32_t)ForkJoinPool::FIFO)) != 0;
}

int32_t ForkJoinPool::getRunningThreadCount() {
	$useLocalCurrentObjectStackCache();
	$VarHandle::acquireFence();
	$var($ForkJoinPool$WorkQueueArray, qs, nullptr);
	$var($ForkJoinPool$WorkQueue, q, nullptr);
	int32_t rc = 0;
	if (($assign(qs, this->queues)) != nullptr) {
		for (int32_t i = 1; i < $nc(qs)->length; i += 2) {
			bool var$0 = ($assign(q, qs->get(i))) != nullptr;
			if (var$0 && $nc(q)->isApparentlyUnblocked()) {
				++rc;
			}
		}
	}
	return rc;
}

int32_t ForkJoinPool::getActiveThreadCount() {
	int32_t r = ((int32_t)(this->mode & (uint32_t)ForkJoinPool::SMASK)) + (int32_t)($sr(this->ctl, ForkJoinPool::RC_SHIFT));
	return (r <= 0) ? 0 : r;
}

bool ForkJoinPool::isQuiescent() {
	return canStop();
}

int64_t ForkJoinPool::getStealCount() {
	$useLocalCurrentObjectStackCache();
	int64_t count = this->stealCount;
	$var($ForkJoinPool$WorkQueueArray, qs, nullptr);
	$var($ForkJoinPool$WorkQueue, q, nullptr);
	if (($assign(qs, this->queues)) != nullptr) {
		for (int32_t i = 1; i < $nc(qs)->length; i += 2) {
			if (($assign(q, qs->get(i))) != nullptr) {
				count += (int64_t)((int64_t)$nc(q)->nsteals & (uint64_t)(int64_t)0x00000000FFFFFFFF);
			}
		}
	}
	return count;
}

int64_t ForkJoinPool::getQueuedTaskCount() {
	$useLocalCurrentObjectStackCache();
	$VarHandle::acquireFence();
	$var($ForkJoinPool$WorkQueueArray, qs, nullptr);
	$var($ForkJoinPool$WorkQueue, q, nullptr);
	int32_t count = 0;
	if (($assign(qs, this->queues)) != nullptr) {
		for (int32_t i = 1; i < $nc(qs)->length; i += 2) {
			if (($assign(q, qs->get(i))) != nullptr) {
				count += $nc(q)->queueSize();
			}
		}
	}
	return count;
}

int32_t ForkJoinPool::getQueuedSubmissionCount() {
	$useLocalCurrentObjectStackCache();
	$VarHandle::acquireFence();
	$var($ForkJoinPool$WorkQueueArray, qs, nullptr);
	$var($ForkJoinPool$WorkQueue, q, nullptr);
	int32_t count = 0;
	if (($assign(qs, this->queues)) != nullptr) {
		for (int32_t i = 0; i < $nc(qs)->length; i += 2) {
			if (($assign(q, qs->get(i))) != nullptr) {
				count += $nc(q)->queueSize();
			}
		}
	}
	return count;
}

bool ForkJoinPool::hasQueuedSubmissions() {
	$useLocalCurrentObjectStackCache();
	$VarHandle::acquireFence();
	$var($ForkJoinPool$WorkQueueArray, qs, nullptr);
	$var($ForkJoinPool$WorkQueue, q, nullptr);
	if (($assign(qs, this->queues)) != nullptr) {
		for (int32_t i = 0; i < $nc(qs)->length; i += 2) {
			bool var$0 = ($assign(q, qs->get(i))) != nullptr;
			if (var$0 && !$nc(q)->isEmpty()) {
				return true;
			}
		}
	}
	return false;
}

$ForkJoinTask* ForkJoinPool::pollSubmission() {
	return pollScan(true);
}

int32_t ForkJoinPool::drainTasksTo($Collection* c) {
	int32_t count = 0;
	{
		$var($ForkJoinTask, t, nullptr);
		for (; ($assign(t, pollScan(false))) != nullptr;) {
			$nc(c)->add(t);
			++count;
		}
	}
	return count;
}

$String* ForkJoinPool::toString() {
	$useLocalCurrentObjectStackCache();
	int32_t md = this->mode;
	int64_t c = this->ctl;
	int64_t st = this->stealCount;
	int64_t qt = 0;
	int64_t ss = 0;
	int32_t rc = 0;
	$var($ForkJoinPool$WorkQueueArray, qs, nullptr);
	$var($ForkJoinPool$WorkQueue, q, nullptr);
	if (($assign(qs, this->queues)) != nullptr) {
		for (int32_t i = 0; i < $nc(qs)->length; ++i) {
			if (($assign(q, qs->get(i))) != nullptr) {
				int32_t size = $nc(q)->queueSize();
				if (((int32_t)(i & (uint32_t)1)) == 0) {
					ss += size;
				} else {
					qt += size;
					st += (int64_t)((int64_t)q->nsteals & (uint64_t)(int64_t)0x00000000FFFFFFFF);
					if (q->isApparentlyUnblocked()) {
						++rc;
					}
				}
			}
		}
	}
	int32_t pc = ((int32_t)(md & (uint32_t)ForkJoinPool::SMASK));
	int32_t tc = pc + (int16_t)($usr(c, ForkJoinPool::TC_SHIFT));
	int32_t ac = pc + (int32_t)($sr(c, ForkJoinPool::RC_SHIFT));
	if (ac < 0) {
		ac = 0;
	}
	$var($String, level, ((int32_t)(md & (uint32_t)ForkJoinPool::TERMINATED)) != 0 ? "Terminated"_s : ((int32_t)(md & (uint32_t)ForkJoinPool::STOP)) != 0 ? "Terminating"_s : ((int32_t)(md & (uint32_t)ForkJoinPool::SHUTDOWN)) != 0 ? "Shutting down"_s : "Running"_s);
	return $str({$($AbstractExecutorService::toString()), "["_s, level, ", parallelism = "_s, $$str(pc), ", size = "_s, $$str(tc), ", active = "_s, $$str(ac), ", running = "_s, $$str(rc), ", steals = "_s, $$str(st), ", tasks = "_s, $$str(qt), ", submissions = "_s, 
	$$str(ss), "]"_s});
}

void ForkJoinPool::shutdown() {
	checkPermission();
	if (this != ForkJoinPool::common) {
		tryTerminate(false, true);
	}
}

$List* ForkJoinPool::shutdownNow() {
	checkPermission();
	if (this != ForkJoinPool::common) {
		tryTerminate(true, true);
	}
	return $Collections::emptyList();
}

bool ForkJoinPool::isTerminated() {
	return ((int32_t)(this->mode & (uint32_t)ForkJoinPool::TERMINATED)) != 0;
}

bool ForkJoinPool::isTerminating() {
	return ((int32_t)(this->mode & (uint32_t)(ForkJoinPool::STOP | ForkJoinPool::TERMINATED))) == ForkJoinPool::STOP;
}

bool ForkJoinPool::isShutdown() {
	return ((int32_t)(this->mode & (uint32_t)ForkJoinPool::SHUTDOWN)) != 0;
}

bool ForkJoinPool::awaitTermination(int64_t timeout, $TimeUnit* unit) {
	$useLocalCurrentObjectStackCache();
	$var($ReentrantLock, lock, nullptr);
	$var($Condition, cond, nullptr);
	int64_t nanos = $nc(unit)->toNanos(timeout);
	bool terminated = false;
	if (this == ForkJoinPool::common) {
		$var($Thread, t, nullptr);
		$var($ForkJoinWorkerThread, wt, nullptr);
		int32_t q = 0;
		bool var$0 = $instanceOf($ForkJoinWorkerThread, $assign(t, $Thread::currentThread()));
		if (var$0 && $nc(($assign(wt, $cast($ForkJoinWorkerThread, t))))->pool == this) {
			q = helpQuiescePool($nc(wt)->workQueue, nanos, true);
		} else {
			q = externalHelpQuiescePool(nanos, true);
		}
		if (q < 0) {
			$throwNew($InterruptedException);
		}
	} else if (!(terminated = (((int32_t)(this->mode & (uint32_t)ForkJoinPool::TERMINATED)) != 0)) && ($assign(lock, this->registrationLock)) != nullptr) {
		$nc(lock)->lock();
		{
			$var($Throwable, var$1, nullptr);
			try {
				if (($assign(cond, this->termination)) == nullptr) {
					$set(this, termination, ($assign(cond, lock->newCondition())));
				}
				while (!(terminated = (((int32_t)(this->mode & (uint32_t)ForkJoinPool::TERMINATED)) != 0)) && nanos > (int64_t)0) {
					nanos = $nc(cond)->awaitNanos(nanos);
				}
			} catch ($Throwable& var$2) {
				$assign(var$1, var$2);
			} /*finally*/ {
				lock->unlock();
			}
			if (var$1 != nullptr) {
				$throw(var$1);
			}
		}
	}
	return terminated;
}

bool ForkJoinPool::awaitQuiescence(int64_t timeout, $TimeUnit* unit) {
	$useLocalCurrentObjectStackCache();
	$var($Thread, t, nullptr);
	$var($ForkJoinWorkerThread, wt, nullptr);
	int32_t q = 0;
	int64_t nanos = $nc(unit)->toNanos(timeout);
	bool var$0 = $instanceOf($ForkJoinWorkerThread, $assign(t, $Thread::currentThread()));
	if (var$0 && $nc(($assign(wt, $cast($ForkJoinWorkerThread, t))))->pool == this) {
		q = helpQuiescePool($nc(wt)->workQueue, nanos, false);
	} else {
		q = externalHelpQuiescePool(nanos, false);
	}
	return (q > 0);
}

void ForkJoinPool::managedBlock($ForkJoinPool$ManagedBlocker* blocker) {
	$init(ForkJoinPool);
	$useLocalCurrentObjectStackCache();
	$var($Thread, t, nullptr);
	$var(ForkJoinPool, p, nullptr);
	if ($instanceOf($ForkJoinWorkerThread, $assign(t, $Thread::currentThread())) && ($assign(p, $nc(($cast($ForkJoinWorkerThread, t)))->pool)) != nullptr) {
		$nc(p)->compensatedBlock(blocker);
	} else {
		unmanagedBlock(blocker);
	}
}

void ForkJoinPool::compensatedBlock($ForkJoinPool$ManagedBlocker* blocker) {
	$useLocalCurrentObjectStackCache();
	if (blocker == nullptr) {
		$throwNew($NullPointerException);
	}
	for (;;) {
		int32_t comp = 0;
		bool done = false;
		int64_t c = this->ctl;
		if ($nc(blocker)->isReleasable()) {
			break;
		}
		if ((comp = tryCompensate(c)) >= 0) {
			int64_t post = (comp == 0) ? (int64_t)0 : ForkJoinPool::RC_UNIT;
			{
				$var($Throwable, var$0, nullptr);
				try {
					done = $nc(blocker)->block();
				} catch ($Throwable& var$1) {
					$assign(var$0, var$1);
				} /*finally*/ {
					getAndAddCtl(post);
				}
				if (var$0 != nullptr) {
					$throw(var$0);
				}
			}
			if (done) {
				break;
			}
		}
	}
}

void ForkJoinPool::unmanagedBlock($ForkJoinPool$ManagedBlocker* blocker) {
	$init(ForkJoinPool);
	if (blocker == nullptr) {
		$throwNew($NullPointerException);
	}
	bool var$0 = false;
	do {
		var$0 = !$nc(blocker)->isReleasable();
	} while (var$0 && !blocker->block());
}

$RunnableFuture* ForkJoinPool::newTaskFor($Runnable* runnable, Object$* value) {
	return $new($ForkJoinTask$AdaptedRunnable, runnable, value);
}

$RunnableFuture* ForkJoinPool::newTaskFor($Callable* callable) {
	return $new($ForkJoinTask$AdaptedCallable, callable);
}

void clinit$ForkJoinPool($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	{
		try {
			$var($MethodHandles$Lookup, l, $MethodHandles::lookup());
			$init($Long);
			$assignStatic(ForkJoinPool::CTL, $nc(l)->findVarHandle(ForkJoinPool::class$, "ctl"_s, $Long::TYPE));
			$init($Integer);
			$assignStatic(ForkJoinPool::MODE, l->findVarHandle(ForkJoinPool::class$, "mode"_s, $Integer::TYPE));
			$assignStatic(ForkJoinPool::THREADIDS, l->findVarHandle(ForkJoinPool::class$, "threadIds"_s, $Integer::TYPE));
			$assignStatic(ForkJoinPool::POOLIDS, l->findStaticVarHandle(ForkJoinPool::class$, "poolIds"_s, $Integer::TYPE));
		} catch ($ReflectiveOperationException& e) {
			$throwNew($ExceptionInInitializerError, static_cast<$Throwable*>(e));
		}
		$load($LockSupport);
		$Class* ensureLoaded = $LockSupport::class$;
		int32_t commonMaxSpares = ForkJoinPool::DEFAULT_COMMON_MAX_SPARES;
		try {
			$var($String, p, $System::getProperty("java.util.concurrent.ForkJoinPool.common.maximumSpares"_s));
			if (p != nullptr) {
				commonMaxSpares = $Integer::parseInt(p);
			}
		} catch ($Exception& ignore) {
		}
		ForkJoinPool::COMMON_MAX_SPARES = commonMaxSpares;
		$assignStatic(ForkJoinPool::defaultForkJoinWorkerThreadFactory, $new($ForkJoinPool$DefaultForkJoinWorkerThreadFactory));
		$assignStatic(ForkJoinPool::modifyThreadPermission, $new($RuntimePermission, "modifyThread"_s));
		$var(ForkJoinPool, tmp, $cast(ForkJoinPool, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($ForkJoinPool$1)))));
		$assignStatic(ForkJoinPool::common, tmp);
		ForkJoinPool::COMMON_PARALLELISM = $Math::max((int32_t)($nc(ForkJoinPool::common)->mode & (uint32_t)ForkJoinPool::SMASK), 1);
	}
}

ForkJoinPool::ForkJoinPool() {
}

$Class* ForkJoinPool::load$($String* name, bool initialize) {
	$loadClass(ForkJoinPool, name, initialize, &_ForkJoinPool_ClassInfo_, clinit$ForkJoinPool, allocate$ForkJoinPool);
	return class$;
}

$Class* ForkJoinPool::class$ = nullptr;

		} // concurrent
	} // util
} // java