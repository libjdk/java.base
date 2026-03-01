#include <sun/nio/ch/ThreadPool.h>

#include <java/io/Serializable.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/Error.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/InstantiationException.h>
#include <java/lang/NumberFormatException.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/Runnable.h>
#include <java/lang/Runtime.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/concurrent/ExecutorService.h>
#include <java/util/concurrent/Executors.h>
#include <java/util/concurrent/ThreadFactory.h>
#include <java/util/concurrent/ThreadPoolExecutor.h>
#include <jdk/internal/misc/InnocuousThread.h>
#include <sun/nio/ch/ThreadPool$DefaultThreadPoolHolder.h>
#include <sun/security/action/GetPropertyAction.h>
#include <jcpp.h>

#undef DEFAULT_THREAD_POOL_INITIAL_SIZE
#undef DEFAULT_THREAD_POOL_THREAD_FACTORY
#undef MAX_VALUE

using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $Error = ::java::lang::Error;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InstantiationException = ::java::lang::InstantiationException;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $Runnable = ::java::lang::Runnable;
using $Runtime = ::java::lang::Runtime;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $ExecutorService = ::java::util::concurrent::ExecutorService;
using $Executors = ::java::util::concurrent::Executors;
using $ThreadFactory = ::java::util::concurrent::ThreadFactory;
using $ThreadPoolExecutor = ::java::util::concurrent::ThreadPoolExecutor;
using $InnocuousThread = ::jdk::internal::misc::InnocuousThread;
using $ThreadPool$DefaultThreadPoolHolder = ::sun::nio::ch::ThreadPool$DefaultThreadPoolHolder;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;

namespace sun {
	namespace nio {
		namespace ch {

class ThreadPool$$Lambda$lambda$defaultThreadFactory$0 : public $ThreadFactory {
	$class(ThreadPool$$Lambda$lambda$defaultThreadFactory$0, $NO_CLASS_INIT, $ThreadFactory)
public:
	void init$() {
	}
	virtual $Thread* newThread($Runnable* r) override {
		 return ThreadPool::lambda$defaultThreadFactory$0(r);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ThreadPool$$Lambda$lambda$defaultThreadFactory$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ThreadPool$$Lambda$lambda$defaultThreadFactory$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ThreadPool$$Lambda$lambda$defaultThreadFactory$0, init$, void)},
	{"newThread", "(Ljava/lang/Runnable;)Ljava/lang/Thread;", nullptr, $PUBLIC, $virtualMethod(ThreadPool$$Lambda$lambda$defaultThreadFactory$0, newThread, $Thread*, $Runnable*)},
	{}
};
$ClassInfo ThreadPool$$Lambda$lambda$defaultThreadFactory$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.nio.ch.ThreadPool$$Lambda$lambda$defaultThreadFactory$0",
	"java.lang.Object",
	"java.util.concurrent.ThreadFactory",
	nullptr,
	methodInfos
};
$Class* ThreadPool$$Lambda$lambda$defaultThreadFactory$0::load$($String* name, bool initialize) {
	$loadClass(ThreadPool$$Lambda$lambda$defaultThreadFactory$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ThreadPool$$Lambda$lambda$defaultThreadFactory$0::class$ = nullptr;

class ThreadPool$$Lambda$lambda$defaultThreadFactory$2$1 : public $ThreadFactory {
	$class(ThreadPool$$Lambda$lambda$defaultThreadFactory$2$1, $NO_CLASS_INIT, $ThreadFactory)
public:
	void init$() {
	}
	virtual $Thread* newThread($Runnable* r) override {
		 return ThreadPool::lambda$defaultThreadFactory$2(r);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ThreadPool$$Lambda$lambda$defaultThreadFactory$2$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ThreadPool$$Lambda$lambda$defaultThreadFactory$2$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ThreadPool$$Lambda$lambda$defaultThreadFactory$2$1, init$, void)},
	{"newThread", "(Ljava/lang/Runnable;)Ljava/lang/Thread;", nullptr, $PUBLIC, $virtualMethod(ThreadPool$$Lambda$lambda$defaultThreadFactory$2$1, newThread, $Thread*, $Runnable*)},
	{}
};
$ClassInfo ThreadPool$$Lambda$lambda$defaultThreadFactory$2$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.nio.ch.ThreadPool$$Lambda$lambda$defaultThreadFactory$2$1",
	"java.lang.Object",
	"java.util.concurrent.ThreadFactory",
	nullptr,
	methodInfos
};
$Class* ThreadPool$$Lambda$lambda$defaultThreadFactory$2$1::load$($String* name, bool initialize) {
	$loadClass(ThreadPool$$Lambda$lambda$defaultThreadFactory$2$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ThreadPool$$Lambda$lambda$defaultThreadFactory$2$1::class$ = nullptr;

class ThreadPool$$Lambda$lambda$defaultThreadFactory$1$2 : public $PrivilegedAction {
	$class(ThreadPool$$Lambda$lambda$defaultThreadFactory$1$2, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$($Runnable* r) {
		$set(this, r, r);
	}
	virtual $Object* run() override {
		 return $of(ThreadPool::lambda$defaultThreadFactory$1(r));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ThreadPool$$Lambda$lambda$defaultThreadFactory$1$2>());
	}
	$Runnable* r = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ThreadPool$$Lambda$lambda$defaultThreadFactory$1$2::fieldInfos[2] = {
	{"r", "Ljava/lang/Runnable;", nullptr, $PUBLIC, $field(ThreadPool$$Lambda$lambda$defaultThreadFactory$1$2, r)},
	{}
};
$MethodInfo ThreadPool$$Lambda$lambda$defaultThreadFactory$1$2::methodInfos[3] = {
	{"<init>", "(Ljava/lang/Runnable;)V", nullptr, $PUBLIC, $method(ThreadPool$$Lambda$lambda$defaultThreadFactory$1$2, init$, void, $Runnable*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ThreadPool$$Lambda$lambda$defaultThreadFactory$1$2, run, $Object*)},
	{}
};
$ClassInfo ThreadPool$$Lambda$lambda$defaultThreadFactory$1$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.nio.ch.ThreadPool$$Lambda$lambda$defaultThreadFactory$1$2",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* ThreadPool$$Lambda$lambda$defaultThreadFactory$1$2::load$($String* name, bool initialize) {
	$loadClass(ThreadPool$$Lambda$lambda$defaultThreadFactory$1$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ThreadPool$$Lambda$lambda$defaultThreadFactory$1$2::class$ = nullptr;

$FieldInfo _ThreadPool_FieldInfo_[] = {
	{"DEFAULT_THREAD_POOL_THREAD_FACTORY", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ThreadPool, DEFAULT_THREAD_POOL_THREAD_FACTORY)},
	{"DEFAULT_THREAD_POOL_INITIAL_SIZE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ThreadPool, DEFAULT_THREAD_POOL_INITIAL_SIZE)},
	{"executor", "Ljava/util/concurrent/ExecutorService;", nullptr, $PRIVATE | $FINAL, $field(ThreadPool, executor$)},
	{"isFixed", "Z", nullptr, $PRIVATE | $FINAL, $field(ThreadPool, isFixed)},
	{"poolSize", "I", nullptr, $PRIVATE | $FINAL, $field(ThreadPool, poolSize$)},
	{}
};

$MethodInfo _ThreadPool_MethodInfo_[] = {
	{"<init>", "(Ljava/util/concurrent/ExecutorService;ZI)V", nullptr, $PRIVATE, $method(ThreadPool, init$, void, $ExecutorService*, bool, int32_t)},
	{"create", "(ILjava/util/concurrent/ThreadFactory;)Lsun/nio/ch/ThreadPool;", nullptr, $STATIC, $staticMethod(ThreadPool, create, ThreadPool*, int32_t, $ThreadFactory*)},
	{"createDefault", "()Lsun/nio/ch/ThreadPool;", nullptr, $STATIC, $staticMethod(ThreadPool, createDefault, ThreadPool*)},
	{"defaultThreadFactory", "()Ljava/util/concurrent/ThreadFactory;", nullptr, $STATIC, $staticMethod(ThreadPool, defaultThreadFactory, $ThreadFactory*)},
	{"executor", "()Ljava/util/concurrent/ExecutorService;", nullptr, 0, $virtualMethod(ThreadPool, executor, $ExecutorService*)},
	{"getDefault", "()Lsun/nio/ch/ThreadPool;", nullptr, $STATIC, $staticMethod(ThreadPool, getDefault, ThreadPool*)},
	{"getDefaultThreadPoolInitialSize", "()I", nullptr, $PRIVATE | $STATIC, $staticMethod(ThreadPool, getDefaultThreadPoolInitialSize, int32_t)},
	{"getDefaultThreadPoolThreadFactory", "()Ljava/util/concurrent/ThreadFactory;", nullptr, $PRIVATE | $STATIC, $staticMethod(ThreadPool, getDefaultThreadPoolThreadFactory, $ThreadFactory*)},
	{"isFixedThreadPool", "()Z", nullptr, 0, $virtualMethod(ThreadPool, isFixedThreadPool, bool)},
	{"lambda$defaultThreadFactory$0", "(Ljava/lang/Runnable;)Ljava/lang/Thread;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ThreadPool, lambda$defaultThreadFactory$0, $Thread*, $Runnable*)},
	{"lambda$defaultThreadFactory$1", "(Ljava/lang/Runnable;)Ljava/lang/Thread;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ThreadPool, lambda$defaultThreadFactory$1, $Thread*, $Runnable*)},
	{"lambda$defaultThreadFactory$2", "(Ljava/lang/Runnable;)Ljava/lang/Thread;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ThreadPool, lambda$defaultThreadFactory$2, $Thread*, $Runnable*)},
	{"poolSize", "()I", nullptr, 0, $virtualMethod(ThreadPool, poolSize, int32_t)},
	{"wrap", "(Ljava/util/concurrent/ExecutorService;I)Lsun/nio/ch/ThreadPool;", nullptr, $PUBLIC | $STATIC, $staticMethod(ThreadPool, wrap, ThreadPool*, $ExecutorService*, int32_t)},
	{}
};

$InnerClassInfo _ThreadPool_InnerClassesInfo_[] = {
	{"sun.nio.ch.ThreadPool$DefaultThreadPoolHolder", "sun.nio.ch.ThreadPool", "DefaultThreadPoolHolder", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _ThreadPool_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.nio.ch.ThreadPool",
	"java.lang.Object",
	nullptr,
	_ThreadPool_FieldInfo_,
	_ThreadPool_MethodInfo_,
	nullptr,
	nullptr,
	_ThreadPool_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.nio.ch.ThreadPool$DefaultThreadPoolHolder"
};

$Object* allocate$ThreadPool($Class* clazz) {
	return $of($alloc(ThreadPool));
}

$String* ThreadPool::DEFAULT_THREAD_POOL_THREAD_FACTORY = nullptr;
$String* ThreadPool::DEFAULT_THREAD_POOL_INITIAL_SIZE = nullptr;

void ThreadPool::init$($ExecutorService* executor, bool isFixed, int32_t poolSize) {
	$set(this, executor$, executor);
	this->isFixed = isFixed;
	this->poolSize$ = poolSize;
}

$ExecutorService* ThreadPool::executor() {
	return this->executor$;
}

bool ThreadPool::isFixedThreadPool() {
	return this->isFixed;
}

int32_t ThreadPool::poolSize() {
	return this->poolSize$;
}

$ThreadFactory* ThreadPool::defaultThreadFactory() {
	$init(ThreadPool);
	if ($System::getSecurityManager() == nullptr) {
		return static_cast<$ThreadFactory*>($new(ThreadPool$$Lambda$lambda$defaultThreadFactory$0));
	} else {
		return static_cast<$ThreadFactory*>($new(ThreadPool$$Lambda$lambda$defaultThreadFactory$2$1));
	}
}

ThreadPool* ThreadPool::getDefault() {
	$init(ThreadPool);
	$init($ThreadPool$DefaultThreadPoolHolder);
	return $ThreadPool$DefaultThreadPoolHolder::defaultThreadPool;
}

ThreadPool* ThreadPool::createDefault() {
	$init(ThreadPool);
	$useLocalCurrentObjectStackCache();
	int32_t initialSize = getDefaultThreadPoolInitialSize();
	if (initialSize < 0) {
		initialSize = $nc($($Runtime::getRuntime()))->availableProcessors();
	}
	$var($ThreadFactory, threadFactory, getDefaultThreadPoolThreadFactory());
	if (threadFactory == nullptr) {
		$assign(threadFactory, defaultThreadFactory());
	}
	$var($ExecutorService, executor, $Executors::newCachedThreadPool(threadFactory));
	return $new(ThreadPool, executor, false, initialSize);
}

ThreadPool* ThreadPool::create(int32_t nThreads, $ThreadFactory* factory) {
	$init(ThreadPool);
	if (nThreads <= 0) {
		$throwNew($IllegalArgumentException, "\'nThreads\' must be > 0"_s);
	}
	$var($ExecutorService, executor, $Executors::newFixedThreadPool(nThreads, factory));
	return $new(ThreadPool, executor, true, nThreads);
}

ThreadPool* ThreadPool::wrap($ExecutorService* executor, int32_t initialSize) {
	$init(ThreadPool);
	if (executor == nullptr) {
		$throwNew($NullPointerException, "\'executor\' is null"_s);
	}
	if ($instanceOf($ThreadPoolExecutor, executor)) {
		int32_t max = $nc(($cast($ThreadPoolExecutor, executor)))->getMaximumPoolSize();
		if (max == $Integer::MAX_VALUE) {
			if (initialSize < 0) {
				initialSize = $nc($($Runtime::getRuntime()))->availableProcessors();
			} else {
				initialSize = 0;
			}
		}
	} else if (initialSize < 0) {
		initialSize = 0;
	}
	return $new(ThreadPool, executor, false, initialSize);
}

int32_t ThreadPool::getDefaultThreadPoolInitialSize() {
	$init(ThreadPool);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($String, propValue, $cast($String, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($GetPropertyAction, ThreadPool::DEFAULT_THREAD_POOL_INITIAL_SIZE)))));
	if (propValue != nullptr) {
		try {
			return $Integer::parseInt(propValue);
		} catch ($NumberFormatException& x) {
			$throwNew($Error, $$str({"Value of property \'"_s, ThreadPool::DEFAULT_THREAD_POOL_INITIAL_SIZE, "\' is invalid: "_s, x}));
		}
	}
	return -1;
}

$ThreadFactory* ThreadPool::getDefaultThreadPoolThreadFactory() {
	$init(ThreadPool);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($String, propValue, $cast($String, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($GetPropertyAction, ThreadPool::DEFAULT_THREAD_POOL_THREAD_FACTORY)))));
	if (propValue != nullptr) {
		try {
			$var($Object, tmp, $Class::forName(propValue, true, $($ClassLoader::getSystemClassLoader()))->newInstance());
			return $cast($ThreadFactory, tmp);
		} catch ($ClassNotFoundException& x) {
			$throwNew($Error, static_cast<$Throwable*>(x));
		} catch ($InstantiationException& x) {
			$throwNew($Error, static_cast<$Throwable*>(x));
		} catch ($IllegalAccessException& x) {
			$throwNew($Error, static_cast<$Throwable*>(x));
		}
	}
	return nullptr;
}

$Thread* ThreadPool::lambda$defaultThreadFactory$2($Runnable* r) {
	$init(ThreadPool);
	$beforeCallerSensitive();
	$var($PrivilegedAction, action, static_cast<$PrivilegedAction*>($new(ThreadPool$$Lambda$lambda$defaultThreadFactory$1$2, r)));
	return $cast($Thread, $AccessController::doPrivileged(action));
}

$Thread* ThreadPool::lambda$defaultThreadFactory$1($Runnable* r) {
	$init(ThreadPool);
	$var($Thread, t, $InnocuousThread::newThread(r));
	$nc(t)->setDaemon(true);
	return t;
}

$Thread* ThreadPool::lambda$defaultThreadFactory$0($Runnable* r) {
	$init(ThreadPool);
	$var($Thread, t, $new($Thread, r));
	t->setDaemon(true);
	return t;
}

ThreadPool::ThreadPool() {
}

void clinit$ThreadPool($Class* class$) {
	$assignStatic(ThreadPool::DEFAULT_THREAD_POOL_THREAD_FACTORY, "java.nio.channels.DefaultThreadPool.threadFactory"_s);
	$assignStatic(ThreadPool::DEFAULT_THREAD_POOL_INITIAL_SIZE, "java.nio.channels.DefaultThreadPool.initialSize"_s);
}

$Class* ThreadPool::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ThreadPool$$Lambda$lambda$defaultThreadFactory$0::classInfo$.name)) {
			return ThreadPool$$Lambda$lambda$defaultThreadFactory$0::load$(name, initialize);
		}
		if (name->equals(ThreadPool$$Lambda$lambda$defaultThreadFactory$2$1::classInfo$.name)) {
			return ThreadPool$$Lambda$lambda$defaultThreadFactory$2$1::load$(name, initialize);
		}
		if (name->equals(ThreadPool$$Lambda$lambda$defaultThreadFactory$1$2::classInfo$.name)) {
			return ThreadPool$$Lambda$lambda$defaultThreadFactory$1$2::load$(name, initialize);
		}
	}
	$loadClass(ThreadPool, name, initialize, &_ThreadPool_ClassInfo_, clinit$ThreadPool, allocate$ThreadPool);
	return class$;
}

$Class* ThreadPool::class$ = nullptr;

		} // ch
	} // nio
} // sun