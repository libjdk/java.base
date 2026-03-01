#include <sun/nio/ch/AsynchronousChannelGroupImpl.h>

#include <java/io/FileDescriptor.h>
#include <java/lang/AssertionError.h>
#include <java/lang/Runnable.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityManager.h>
#include <java/nio/channels/AsynchronousChannelGroup.h>
#include <java/nio/channels/Channel.h>
#include <java/nio/channels/spi/AsynchronousChannelProvider.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/Queue.h>
#include <java/util/concurrent/ConcurrentLinkedQueue.h>
#include <java/util/concurrent/ExecutorService.h>
#include <java/util/concurrent/Executors.h>
#include <java/util/concurrent/Future.h>
#include <java/util/concurrent/RejectedExecutionException.h>
#include <java/util/concurrent/ScheduledExecutorService.h>
#include <java/util/concurrent/ScheduledFuture.h>
#include <java/util/concurrent/ScheduledThreadPoolExecutor.h>
#include <java/util/concurrent/ThreadFactory.h>
#include <java/util/concurrent/TimeUnit.h>
#include <java/util/concurrent/atomic/AtomicBoolean.h>
#include <java/util/concurrent/atomic/AtomicInteger.h>
#include <sun/nio/ch/AsynchronousChannelGroupImpl$1.h>
#include <sun/nio/ch/AsynchronousChannelGroupImpl$2.h>
#include <sun/nio/ch/AsynchronousChannelGroupImpl$3.h>
#include <sun/nio/ch/AsynchronousChannelGroupImpl$4.h>
#include <sun/nio/ch/Invoker.h>
#include <sun/nio/ch/ThreadPool.h>
#include <sun/security/action/GetIntegerAction.h>
#include <jcpp.h>

using $PermissionArray = $Array<::java::security::Permission>;
using $FileDescriptor = ::java::io::FileDescriptor;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityManager = ::java::lang::SecurityManager;
using $AsynchronousChannelGroup = ::java::nio::channels::AsynchronousChannelGroup;
using $Channel = ::java::nio::channels::Channel;
using $AsynchronousChannelProvider = ::java::nio::channels::spi::AsynchronousChannelProvider;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $Permission = ::java::security::Permission;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Queue = ::java::util::Queue;
using $ConcurrentLinkedQueue = ::java::util::concurrent::ConcurrentLinkedQueue;
using $ExecutorService = ::java::util::concurrent::ExecutorService;
using $Executors = ::java::util::concurrent::Executors;
using $Future = ::java::util::concurrent::Future;
using $RejectedExecutionException = ::java::util::concurrent::RejectedExecutionException;
using $ScheduledThreadPoolExecutor = ::java::util::concurrent::ScheduledThreadPoolExecutor;
using $TimeUnit = ::java::util::concurrent::TimeUnit;
using $AtomicBoolean = ::java::util::concurrent::atomic::AtomicBoolean;
using $AtomicInteger = ::java::util::concurrent::atomic::AtomicInteger;
using $AsynchronousChannelGroupImpl$1 = ::sun::nio::ch::AsynchronousChannelGroupImpl$1;
using $AsynchronousChannelGroupImpl$2 = ::sun::nio::ch::AsynchronousChannelGroupImpl$2;
using $AsynchronousChannelGroupImpl$3 = ::sun::nio::ch::AsynchronousChannelGroupImpl$3;
using $AsynchronousChannelGroupImpl$4 = ::sun::nio::ch::AsynchronousChannelGroupImpl$4;
using $Invoker = ::sun::nio::ch::Invoker;
using $ThreadPool = ::sun::nio::ch::ThreadPool;
using $GetIntegerAction = ::sun::security::action::GetIntegerAction;

namespace sun {
	namespace nio {
		namespace ch {

$FieldInfo _AsynchronousChannelGroupImpl_FieldInfo_[] = {
	{"internalThreadCount", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(AsynchronousChannelGroupImpl, internalThreadCount)},
	{"pool", "Lsun/nio/ch/ThreadPool;", nullptr, $PRIVATE | $FINAL, $field(AsynchronousChannelGroupImpl, pool)},
	{"threadCount", "Ljava/util/concurrent/atomic/AtomicInteger;", nullptr, $PRIVATE | $FINAL, $field(AsynchronousChannelGroupImpl, threadCount$)},
	{"timeoutExecutor", "Ljava/util/concurrent/ScheduledThreadPoolExecutor;", nullptr, $PRIVATE, $field(AsynchronousChannelGroupImpl, timeoutExecutor)},
	{"taskQueue", "Ljava/util/Queue;", "Ljava/util/Queue<Ljava/lang/Runnable;>;", $PRIVATE | $FINAL, $field(AsynchronousChannelGroupImpl, taskQueue)},
	{"shutdown", "Ljava/util/concurrent/atomic/AtomicBoolean;", nullptr, $PRIVATE | $FINAL, $field(AsynchronousChannelGroupImpl, shutdown$)},
	{"shutdownNowLock", "Ljava/lang/Object;", nullptr, $PRIVATE | $FINAL, $field(AsynchronousChannelGroupImpl, shutdownNowLock)},
	{"terminateInitiated", "Z", nullptr, $PRIVATE | $VOLATILE, $field(AsynchronousChannelGroupImpl, terminateInitiated)},
	{}
};

$MethodInfo _AsynchronousChannelGroupImpl_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/nio/channels/spi/AsynchronousChannelProvider;Lsun/nio/ch/ThreadPool;)V", nullptr, 0, $method(AsynchronousChannelGroupImpl, init$, void, $AsynchronousChannelProvider*, $ThreadPool*)},
	{"attachForeignChannel", "(Ljava/nio/channels/Channel;Ljava/io/FileDescriptor;)Ljava/lang/Object;", nullptr, $ABSTRACT, $virtualMethod(AsynchronousChannelGroupImpl, attachForeignChannel, $Object*, $Channel*, $FileDescriptor*), "java.io.IOException"},
	{"awaitTermination", "(JLjava/util/concurrent/TimeUnit;)Z", nullptr, $PUBLIC | $FINAL, $virtualMethod(AsynchronousChannelGroupImpl, awaitTermination, bool, int64_t, $TimeUnit*), "java.lang.InterruptedException"},
	{"bindToGroup", "(Ljava/lang/Runnable;)Ljava/lang/Runnable;", nullptr, $PRIVATE, $method(AsynchronousChannelGroupImpl, bindToGroup, $Runnable*, $Runnable*)},
	{"closeAllChannels", "()V", nullptr, $ABSTRACT, $virtualMethod(AsynchronousChannelGroupImpl, closeAllChannels, void), "java.io.IOException"},
	{"detachForeignChannel", "(Ljava/lang/Object;)V", nullptr, $ABSTRACT, $virtualMethod(AsynchronousChannelGroupImpl, detachForeignChannel, void, Object$*)},
	{"detachFromThreadPool", "()V", nullptr, $FINAL, $method(AsynchronousChannelGroupImpl, detachFromThreadPool, void)},
	{"execute", "(Ljava/lang/Runnable;)V", nullptr, $PUBLIC | $FINAL, $virtualMethod(AsynchronousChannelGroupImpl, execute, void, $Runnable*)},
	{"executeOnHandlerTask", "(Ljava/lang/Runnable;)V", nullptr, $ABSTRACT, $virtualMethod(AsynchronousChannelGroupImpl, executeOnHandlerTask, void, $Runnable*)},
	{"executeOnPooledThread", "(Ljava/lang/Runnable;)V", nullptr, $FINAL, $method(AsynchronousChannelGroupImpl, executeOnPooledThread, void, $Runnable*)},
	{"executor", "()Ljava/util/concurrent/ExecutorService;", nullptr, $FINAL, $method(AsynchronousChannelGroupImpl, executor, $ExecutorService*)},
	{"fixedThreadCount", "()I", nullptr, $FINAL, $method(AsynchronousChannelGroupImpl, fixedThreadCount, int32_t)},
	{"isEmpty", "()Z", nullptr, $ABSTRACT, $virtualMethod(AsynchronousChannelGroupImpl, isEmpty, bool)},
	{"isFixedThreadPool", "()Z", nullptr, $FINAL, $method(AsynchronousChannelGroupImpl, isFixedThreadPool, bool)},
	{"isShutdown", "()Z", nullptr, $PUBLIC | $FINAL, $virtualMethod(AsynchronousChannelGroupImpl, isShutdown, bool)},
	{"isTerminated", "()Z", nullptr, $PUBLIC | $FINAL, $virtualMethod(AsynchronousChannelGroupImpl, isTerminated, bool)},
	{"offerTask", "(Ljava/lang/Runnable;)V", nullptr, $FINAL, $method(AsynchronousChannelGroupImpl, offerTask, void, $Runnable*)},
	{"pollTask", "()Ljava/lang/Runnable;", nullptr, $FINAL, $method(AsynchronousChannelGroupImpl, pollTask, $Runnable*)},
	{"schedule", "(Ljava/lang/Runnable;JLjava/util/concurrent/TimeUnit;)Ljava/util/concurrent/Future;", "(Ljava/lang/Runnable;JLjava/util/concurrent/TimeUnit;)Ljava/util/concurrent/Future<*>;", $FINAL, $method(AsynchronousChannelGroupImpl, schedule, $Future*, $Runnable*, int64_t, $TimeUnit*)},
	{"shutdown", "()V", nullptr, $PUBLIC | $FINAL, $virtualMethod(AsynchronousChannelGroupImpl, shutdown, void)},
	{"shutdownExecutors", "()V", nullptr, $PRIVATE, $method(AsynchronousChannelGroupImpl, shutdownExecutors, void)},
	{"shutdownHandlerTasks", "()V", nullptr, $ABSTRACT, $virtualMethod(AsynchronousChannelGroupImpl, shutdownHandlerTasks, void)},
	{"shutdownNow", "()V", nullptr, $PUBLIC | $FINAL, $virtualMethod(AsynchronousChannelGroupImpl, shutdownNow, void), "java.io.IOException"},
	{"startInternalThread", "(Ljava/lang/Runnable;)V", nullptr, $PRIVATE, $method(AsynchronousChannelGroupImpl, startInternalThread, void, $Runnable*)},
	{"startThreads", "(Ljava/lang/Runnable;)V", nullptr, $PROTECTED | $FINAL, $method(AsynchronousChannelGroupImpl, startThreads, void, $Runnable*)},
	{"threadCount", "()I", nullptr, $FINAL, $method(AsynchronousChannelGroupImpl, threadCount, int32_t)},
	{"threadExit", "(Ljava/lang/Runnable;Z)I", nullptr, $FINAL, $method(AsynchronousChannelGroupImpl, threadExit, int32_t, $Runnable*, bool)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _AsynchronousChannelGroupImpl_InnerClassesInfo_[] = {
	{"sun.nio.ch.AsynchronousChannelGroupImpl$4", nullptr, nullptr, 0},
	{"sun.nio.ch.AsynchronousChannelGroupImpl$3", nullptr, nullptr, 0},
	{"sun.nio.ch.AsynchronousChannelGroupImpl$2", nullptr, nullptr, 0},
	{"sun.nio.ch.AsynchronousChannelGroupImpl$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _AsynchronousChannelGroupImpl_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"sun.nio.ch.AsynchronousChannelGroupImpl",
	"java.nio.channels.AsynchronousChannelGroup",
	"java.util.concurrent.Executor",
	_AsynchronousChannelGroupImpl_FieldInfo_,
	_AsynchronousChannelGroupImpl_MethodInfo_,
	nullptr,
	nullptr,
	_AsynchronousChannelGroupImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.nio.ch.AsynchronousChannelGroupImpl$4,sun.nio.ch.AsynchronousChannelGroupImpl$4$1,sun.nio.ch.AsynchronousChannelGroupImpl$3,sun.nio.ch.AsynchronousChannelGroupImpl$2,sun.nio.ch.AsynchronousChannelGroupImpl$1"
};

$Object* allocate$AsynchronousChannelGroupImpl($Class* clazz) {
	return $of($alloc(AsynchronousChannelGroupImpl));
}

int32_t AsynchronousChannelGroupImpl::hashCode() {
	 return this->$AsynchronousChannelGroup::hashCode();
}

bool AsynchronousChannelGroupImpl::equals(Object$* obj) {
	 return this->$AsynchronousChannelGroup::equals(obj);
}

$Object* AsynchronousChannelGroupImpl::clone() {
	 return this->$AsynchronousChannelGroup::clone();
}

$String* AsynchronousChannelGroupImpl::toString() {
	 return this->$AsynchronousChannelGroup::toString();
}

void AsynchronousChannelGroupImpl::finalize() {
	this->$AsynchronousChannelGroup::finalize();
}

int32_t AsynchronousChannelGroupImpl::internalThreadCount = 0;

void AsynchronousChannelGroupImpl::init$($AsynchronousChannelProvider* provider, $ThreadPool* pool) {
	$AsynchronousChannelGroup::init$(provider);
	$set(this, threadCount$, $new($AtomicInteger));
	$set(this, shutdown$, $new($AtomicBoolean));
	$set(this, shutdownNowLock, $new($Object));
	$set(this, pool, pool);
	if ($nc(pool)->isFixedThreadPool()) {
		$set(this, taskQueue, $new($ConcurrentLinkedQueue));
	} else {
		$set(this, taskQueue, nullptr);
	}
	$set(this, timeoutExecutor, $cast($ScheduledThreadPoolExecutor, $Executors::newScheduledThreadPool(1, $($ThreadPool::defaultThreadFactory()))));
	$nc(this->timeoutExecutor)->setRemoveOnCancelPolicy(true);
}

$ExecutorService* AsynchronousChannelGroupImpl::executor() {
	return $nc(this->pool)->executor();
}

bool AsynchronousChannelGroupImpl::isFixedThreadPool() {
	return $nc(this->pool)->isFixedThreadPool();
}

int32_t AsynchronousChannelGroupImpl::fixedThreadCount() {
	if (isFixedThreadPool()) {
		return $nc(this->pool)->poolSize();
	} else {
		return $nc(this->pool)->poolSize() + AsynchronousChannelGroupImpl::internalThreadCount;
	}
}

$Runnable* AsynchronousChannelGroupImpl::bindToGroup($Runnable* task) {
	$var(AsynchronousChannelGroupImpl, thisGroup, this);
	return $new($AsynchronousChannelGroupImpl$1, this, thisGroup, task);
}

void AsynchronousChannelGroupImpl::startInternalThread($Runnable* task) {
	$beforeCallerSensitive();
	$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($AsynchronousChannelGroupImpl$2, this, task)));
}

void AsynchronousChannelGroupImpl::startThreads($Runnable* task$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($Runnable, task, task$renamed);
	if (!isFixedThreadPool()) {
		for (int32_t i = 0; i < AsynchronousChannelGroupImpl::internalThreadCount; ++i) {
			startInternalThread(task);
			$nc(this->threadCount$)->incrementAndGet();
		}
	}
	if ($nc(this->pool)->poolSize() > 0) {
		$assign(task, bindToGroup(task));
		try {
			for (int32_t i = 0; i < $nc(this->pool)->poolSize(); ++i) {
				$nc($($nc(this->pool)->executor()))->execute(task);
				$nc(this->threadCount$)->incrementAndGet();
			}
		} catch ($RejectedExecutionException& x) {
		}
	}
}

int32_t AsynchronousChannelGroupImpl::threadCount() {
	return $nc(this->threadCount$)->get();
}

int32_t AsynchronousChannelGroupImpl::threadExit($Runnable* task, bool replaceMe) {
	$useLocalCurrentObjectStackCache();
	if (replaceMe) {
		try {
			if ($Invoker::isBoundToAnyGroup()) {
				$nc($($nc(this->pool)->executor()))->execute($(bindToGroup(task)));
			} else {
				startInternalThread(task);
			}
			return $nc(this->threadCount$)->get();
		} catch ($RejectedExecutionException& x) {
		}
	}
	return $nc(this->threadCount$)->decrementAndGet();
}

void AsynchronousChannelGroupImpl::executeOnPooledThread($Runnable* task) {
	$useLocalCurrentObjectStackCache();
	if (isFixedThreadPool()) {
		executeOnHandlerTask(task);
	} else {
		$nc($($nc(this->pool)->executor()))->execute($(bindToGroup(task)));
	}
}

void AsynchronousChannelGroupImpl::offerTask($Runnable* task) {
	$nc(this->taskQueue)->offer(task);
}

$Runnable* AsynchronousChannelGroupImpl::pollTask() {
	return (this->taskQueue == nullptr) ? ($Runnable*)nullptr : $cast($Runnable, $nc(this->taskQueue)->poll());
}

$Future* AsynchronousChannelGroupImpl::schedule($Runnable* task, int64_t timeout, $TimeUnit* unit) {
	try {
		return $nc(this->timeoutExecutor)->schedule(task, timeout, unit);
	} catch ($RejectedExecutionException& rej) {
		if (this->terminateInitiated) {
			return nullptr;
		}
		$throwNew($AssertionError, $of(rej));
	}
	$shouldNotReachHere();
}

bool AsynchronousChannelGroupImpl::isShutdown() {
	return $nc(this->shutdown$)->get();
}

bool AsynchronousChannelGroupImpl::isTerminated() {
	return $nc($($nc(this->pool)->executor()))->isTerminated();
}

void AsynchronousChannelGroupImpl::shutdownExecutors() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($PrivilegedAction, var$0, static_cast<$PrivilegedAction*>($new($AsynchronousChannelGroupImpl$3, this)));
	$AccessController::doPrivileged(var$0, ($AccessControlContext*)nullptr, $$new($PermissionArray, {static_cast<$Permission*>($$new($RuntimePermission, "modifyThread"_s))}));
}

void AsynchronousChannelGroupImpl::shutdown() {
	if ($nc(this->shutdown$)->getAndSet(true)) {
		return;
	}
	if (!isEmpty()) {
		return;
	}
	$synchronized(this->shutdownNowLock) {
		if (!this->terminateInitiated) {
			this->terminateInitiated = true;
			shutdownHandlerTasks();
			shutdownExecutors();
		}
	}
}

void AsynchronousChannelGroupImpl::shutdownNow() {
	$nc(this->shutdown$)->set(true);
	$synchronized(this->shutdownNowLock) {
		if (!this->terminateInitiated) {
			this->terminateInitiated = true;
			closeAllChannels();
			shutdownHandlerTasks();
			shutdownExecutors();
		}
	}
}

void AsynchronousChannelGroupImpl::detachFromThreadPool() {
	if ($nc(this->shutdown$)->getAndSet(true)) {
		$throwNew($AssertionError, $of("Already shutdown"_s));
	}
	if (!isEmpty()) {
		$throwNew($AssertionError, $of("Group not empty"_s));
	}
	shutdownHandlerTasks();
}

bool AsynchronousChannelGroupImpl::awaitTermination(int64_t timeout, $TimeUnit* unit) {
	return $nc($($nc(this->pool)->executor()))->awaitTermination(timeout, unit);
}

void AsynchronousChannelGroupImpl::execute($Runnable* task$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($Runnable, task, task$renamed);
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		$var($AccessControlContext, acc, $AccessController::getContext());
		$var($Runnable, delegate, task);
		$assign(task, $new($AsynchronousChannelGroupImpl$4, this, delegate, acc));
	}
	executeOnPooledThread(task);
}

void clinit$AsynchronousChannelGroupImpl($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	AsynchronousChannelGroupImpl::internalThreadCount = $nc(($cast($Integer, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($GetIntegerAction, "sun.nio.ch.internalThreadPoolSize"_s, 1)))))))->intValue();
}

AsynchronousChannelGroupImpl::AsynchronousChannelGroupImpl() {
}

$Class* AsynchronousChannelGroupImpl::load$($String* name, bool initialize) {
	$loadClass(AsynchronousChannelGroupImpl, name, initialize, &_AsynchronousChannelGroupImpl_ClassInfo_, clinit$AsynchronousChannelGroupImpl, allocate$AsynchronousChannelGroupImpl);
	return class$;
}

$Class* AsynchronousChannelGroupImpl::class$ = nullptr;

		} // ch
	} // nio
} // sun