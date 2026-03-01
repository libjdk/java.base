#include <jdk/internal/misc/VM.h>

#include <java/lang/ClassLoader.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/InternalError.h>
#include <java/lang/NumberFormatException.h>
#include <java/lang/Runtime.h>
#include <java/lang/Thread$State.h>
#include <java/util/Collections.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <jdk/internal/misc/OSEnvironment.h>
#include <jdk/internal/misc/VM$BufferPoolsHolder.h>
#include <jcpp.h>

#undef BLOCKED
#undef BUFFER_POOLS
#undef JAVA_LANG_SYSTEM_INITED
#undef JVMTI_THREAD_STATE_ALIVE
#undef JVMTI_THREAD_STATE_BLOCKED_ON_MONITOR_ENTER
#undef JVMTI_THREAD_STATE_RUNNABLE
#undef JVMTI_THREAD_STATE_TERMINATED
#undef JVMTI_THREAD_STATE_WAITING_INDEFINITELY
#undef JVMTI_THREAD_STATE_WAITING_WITH_TIMEOUT
#undef MODULE_SYSTEM_INITED
#undef NEW
#undef PREVIEW_MINOR_VERSION
#undef RUNNABLE
#undef SYSTEM_BOOTED
#undef SYSTEM_LOADER_INITIALIZING
#undef SYSTEM_SHUTDOWN
#undef TERMINATED
#undef TIMED_WAITING
#undef VM
#undef WAITING

using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $Runtime = ::java::lang::Runtime;
using $Thread$State = ::java::lang::Thread$State;
using $Collections = ::java::util::Collections;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $OSEnvironment = ::jdk::internal::misc::OSEnvironment;
using $VM$BufferPoolsHolder = ::jdk::internal::misc::VM$BufferPoolsHolder;

namespace jdk {
	namespace internal {
		namespace misc {

$FieldInfo _VM_FieldInfo_[] = {
	{"JAVA_LANG_SYSTEM_INITED", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(VM, JAVA_LANG_SYSTEM_INITED)},
	{"MODULE_SYSTEM_INITED", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(VM, MODULE_SYSTEM_INITED)},
	{"SYSTEM_LOADER_INITIALIZING", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(VM, SYSTEM_LOADER_INITIALIZING)},
	{"SYSTEM_BOOTED", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(VM, SYSTEM_BOOTED)},
	{"SYSTEM_SHUTDOWN", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(VM, SYSTEM_SHUTDOWN)},
	{"initLevel", "I", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(VM, initLevel$)},
	{"lock", "Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(VM, lock)},
	{"directMemory", "J", nullptr, $PRIVATE | $STATIC, $staticField(VM, directMemory)},
	{"pageAlignDirectMemory", "Z", nullptr, $PRIVATE | $STATIC, $staticField(VM, pageAlignDirectMemory)},
	{"classFileMajorVersion", "I", nullptr, $PRIVATE | $STATIC, $staticField(VM, classFileMajorVersion)},
	{"classFileMinorVersion", "I", nullptr, $PRIVATE | $STATIC, $staticField(VM, classFileMinorVersion)},
	{"PREVIEW_MINOR_VERSION", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(VM, PREVIEW_MINOR_VERSION)},
	{"savedProps", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;", $PRIVATE | $STATIC, $staticField(VM, savedProps)},
	{"finalRefCount", "I", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(VM, finalRefCount)},
	{"peakFinalRefCount", "I", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(VM, peakFinalRefCount)},
	{"JVMTI_THREAD_STATE_ALIVE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(VM, JVMTI_THREAD_STATE_ALIVE)},
	{"JVMTI_THREAD_STATE_TERMINATED", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(VM, JVMTI_THREAD_STATE_TERMINATED)},
	{"JVMTI_THREAD_STATE_RUNNABLE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(VM, JVMTI_THREAD_STATE_RUNNABLE)},
	{"JVMTI_THREAD_STATE_BLOCKED_ON_MONITOR_ENTER", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(VM, JVMTI_THREAD_STATE_BLOCKED_ON_MONITOR_ENTER)},
	{"JVMTI_THREAD_STATE_WAITING_INDEFINITELY", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(VM, JVMTI_THREAD_STATE_WAITING_INDEFINITELY)},
	{"JVMTI_THREAD_STATE_WAITING_WITH_TIMEOUT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(VM, JVMTI_THREAD_STATE_WAITING_WITH_TIMEOUT)},
	{}
};

$MethodInfo _VM_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(VM, init$, void)},
	{"addFinalRefCount", "(I)V", nullptr, $PUBLIC | $STATIC, $staticMethod(VM, addFinalRefCount, void, int32_t)},
	{"awaitInitLevel", "(I)V", nullptr, $PUBLIC | $STATIC, $staticMethod(VM, awaitInitLevel, void, int32_t), "java.lang.InterruptedException"},
	{"getBufferPools", "()Ljava/util/List;", "()Ljava/util/List<Ljdk/internal/misc/VM$BufferPool;>;", $PUBLIC | $STATIC, $staticMethod(VM, getBufferPools, $List*)},
	{"getFinalRefCount", "()I", nullptr, $PUBLIC | $STATIC, $staticMethod(VM, getFinalRefCount, int32_t)},
	{"getNanoTimeAdjustment", "(J)J", nullptr, $PUBLIC | $STATIC | $NATIVE, $staticMethod(VM, getNanoTimeAdjustment, int64_t, int64_t)},
	{"getPeakFinalRefCount", "()I", nullptr, $PUBLIC | $STATIC, $staticMethod(VM, getPeakFinalRefCount, int32_t)},
	{"getRuntimeArguments", "()[Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $NATIVE, $staticMethod(VM, getRuntimeArguments, $StringArray*)},
	{"getSavedProperties", "()Ljava/util/Map;", "()Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;", $PUBLIC | $STATIC, $staticMethod(VM, getSavedProperties, $Map*)},
	{"getSavedProperty", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(VM, getSavedProperty, $String*, $String*)},
	{"getegid", "()J", nullptr, $PUBLIC | $STATIC | $NATIVE, $staticMethod(VM, getegid, int64_t)},
	{"geteuid", "()J", nullptr, $PUBLIC | $STATIC | $NATIVE, $staticMethod(VM, geteuid, int64_t)},
	{"getgid", "()J", nullptr, $PUBLIC | $STATIC | $NATIVE, $staticMethod(VM, getgid, int64_t)},
	{"getuid", "()J", nullptr, $PUBLIC | $STATIC | $NATIVE, $staticMethod(VM, getuid, int64_t)},
	{"initLevel", "(I)V", nullptr, $PUBLIC | $STATIC, $staticMethod(VM, initLevel, void, int32_t)},
	{"initLevel", "()I", nullptr, $PUBLIC | $STATIC, $staticMethod(VM, initLevel, int32_t)},
	{"initialize", "()V", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(VM, initialize, void)},
	{"initializeOSEnvironment", "()V", nullptr, $PUBLIC | $STATIC, $staticMethod(VM, initializeOSEnvironment, void)},
	{"isBooted", "()Z", nullptr, $PUBLIC | $STATIC, $staticMethod(VM, isBooted, bool)},
	{"isDirectMemoryPageAligned", "()Z", nullptr, $PUBLIC | $STATIC, $staticMethod(VM, isDirectMemoryPageAligned, bool)},
	{"isModuleSystemInited", "()Z", nullptr, $PUBLIC | $STATIC, $staticMethod(VM, isModuleSystemInited, bool)},
	{"isSetUID", "()Z", nullptr, $PUBLIC | $STATIC, $staticMethod(VM, isSetUID, bool)},
	{"isShutdown", "()Z", nullptr, $PUBLIC | $STATIC, $staticMethod(VM, isShutdown, bool)},
	{"isSupportedClassFileVersion", "(II)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(VM, isSupportedClassFileVersion, bool, int32_t, int32_t)},
	{"isSupportedModuleDescriptorVersion", "(II)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(VM, isSupportedModuleDescriptorVersion, bool, int32_t, int32_t)},
	{"isSystemDomainLoader", "(Ljava/lang/ClassLoader;)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(VM, isSystemDomainLoader, bool, $ClassLoader*)},
	{"latestUserDefinedLoader", "()Ljava/lang/ClassLoader;", nullptr, $PUBLIC | $STATIC, $staticMethod(VM, latestUserDefinedLoader, $ClassLoader*)},
	{"latestUserDefinedLoader0", "()Ljava/lang/ClassLoader;", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(VM, latestUserDefinedLoader0, $ClassLoader*)},
	{"maxDirectMemory", "()J", nullptr, $PUBLIC | $STATIC, $staticMethod(VM, maxDirectMemory, int64_t)},
	{"saveProperties", "(Ljava/util/Map;)V", "(Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;)V", $PUBLIC | $STATIC, $staticMethod(VM, saveProperties, void, $Map*)},
	{"shutdown", "()V", nullptr, $PUBLIC | $STATIC, $staticMethod(VM, shutdown, void)},
	{"toThreadState", "(I)Ljava/lang/Thread$State;", nullptr, $PUBLIC | $STATIC, $staticMethod(VM, toThreadState, $Thread$State*, int32_t)},
	{}
};

#define _METHOD_INDEX_getNanoTimeAdjustment 5
#define _METHOD_INDEX_getRuntimeArguments 7
#define _METHOD_INDEX_getegid 10
#define _METHOD_INDEX_geteuid 11
#define _METHOD_INDEX_getgid 12
#define _METHOD_INDEX_getuid 13
#define _METHOD_INDEX_initialize 16
#define _METHOD_INDEX_latestUserDefinedLoader0 27

$InnerClassInfo _VM_InnerClassesInfo_[] = {
	{"jdk.internal.misc.VM$BufferPoolsHolder", "jdk.internal.misc.VM", "BufferPoolsHolder", $PRIVATE | $STATIC},
	{"jdk.internal.misc.VM$BufferPool", "jdk.internal.misc.VM", "BufferPool", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _VM_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.misc.VM",
	"java.lang.Object",
	nullptr,
	_VM_FieldInfo_,
	_VM_MethodInfo_,
	nullptr,
	nullptr,
	_VM_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.misc.VM$BufferPoolsHolder,jdk.internal.misc.VM$BufferPool"
};

$Object* allocate$VM($Class* clazz) {
	return $of($alloc(VM));
}

$volatile(int32_t) VM::initLevel$ = 0;
$Object* VM::lock = nullptr;
int64_t VM::directMemory = 0;
bool VM::pageAlignDirectMemory = false;
int32_t VM::classFileMajorVersion = 0;
int32_t VM::classFileMinorVersion = 0;
$Map* VM::savedProps = nullptr;
$volatile(int32_t) VM::finalRefCount = 0;
$volatile(int32_t) VM::peakFinalRefCount = 0;

void VM::init$() {
}

void VM::initLevel(int32_t value) {
	$init(VM);
	$useLocalCurrentObjectStackCache();
	$synchronized(VM::lock) {
		if (value <= VM::initLevel$ || value > VM::SYSTEM_SHUTDOWN) {
			$throwNew($InternalError, $$str({"Bad level: "_s, $$str(value)}));
		}
		VM::initLevel$ = value;
		$nc($of(VM::lock))->notifyAll();
	}
}

int32_t VM::initLevel() {
	$init(VM);
	return VM::initLevel$;
}

void VM::awaitInitLevel(int32_t value) {
	$init(VM);
	$synchronized(VM::lock) {
		while (VM::initLevel$ < value) {
			$nc($of(VM::lock))->wait();
		}
	}
}

bool VM::isModuleSystemInited() {
	$init(VM);
	return VM::initLevel() >= VM::MODULE_SYSTEM_INITED;
}

bool VM::isBooted() {
	$init(VM);
	return VM::initLevel$ >= VM::SYSTEM_BOOTED;
}

void VM::shutdown() {
	$init(VM);
	initLevel(VM::SYSTEM_SHUTDOWN);
}

bool VM::isShutdown() {
	$init(VM);
	return VM::initLevel$ == VM::SYSTEM_SHUTDOWN;
}

int64_t VM::maxDirectMemory() {
	$init(VM);
	return VM::directMemory;
}

bool VM::isDirectMemoryPageAligned() {
	$init(VM);
	return VM::pageAlignDirectMemory;
}

bool VM::isSupportedClassFileVersion(int32_t major, int32_t minor) {
	$init(VM);
	if (major < 45 || major > VM::classFileMajorVersion) {
		return false;
	}
	if (major < 56) {
		return true;
	}
	return minor == 0 || minor == VM::PREVIEW_MINOR_VERSION;
}

bool VM::isSupportedModuleDescriptorVersion(int32_t major, int32_t minor) {
	$init(VM);
	if (major < 53 || major > VM::classFileMajorVersion) {
		return false;
	}
	if (major < 56) {
		return true;
	}
	return minor == 0 || minor == VM::PREVIEW_MINOR_VERSION;
}

bool VM::isSystemDomainLoader($ClassLoader* loader) {
	$init(VM);
	$beforeCallerSensitive();
	return loader == nullptr || loader == $ClassLoader::getPlatformClassLoader();
}

$String* VM::getSavedProperty($String* key) {
	$init(VM);
	if (VM::savedProps == nullptr) {
		$throwNew($IllegalStateException, "Not yet initialized"_s);
	}
	return $cast($String, $nc(VM::savedProps)->get(key));
}

$Map* VM::getSavedProperties() {
	$init(VM);
	if (VM::savedProps == nullptr) {
		$throwNew($IllegalStateException, "Not yet initialized"_s);
	}
	return $Collections::unmodifiableMap(VM::savedProps);
}

void VM::saveProperties($Map* props) {
	$init(VM);
	$useLocalCurrentObjectStackCache();
	if (initLevel() != 0) {
		$throwNew($IllegalStateException, "Wrong init level"_s);
	}
	if (VM::savedProps == nullptr) {
		$assignStatic(VM::savedProps, props);
	}
	$var($String, s, $cast($String, $nc(props)->get("sun.nio.MaxDirectMemorySize"_s)));
	bool var$0 = s == nullptr || $nc(s)->isEmpty();
	if (var$0 || $nc(s)->equals("-1"_s)) {
		VM::directMemory = $nc($($Runtime::getRuntime()))->maxMemory();
	} else {
		int64_t l = $Long::parseLong(s);
		if (l > -1) {
			VM::directMemory = l;
		}
	}
	$assign(s, $cast($String, props->get("sun.nio.PageAlignDirectMemory"_s)));
	if ("true"_s->equals(s)) {
		VM::pageAlignDirectMemory = true;
	}
	$assign(s, $cast($String, props->get("java.class.version"_s)));
	int32_t index = $nc(s)->indexOf((int32_t)u'.');
	try {
		VM::classFileMajorVersion = $nc($($Integer::valueOf($(s->substring(0, index)))))->intValue();
		VM::classFileMinorVersion = $nc($($Integer::valueOf($(s->substring(index + 1, s->length())))))->intValue();
	} catch ($NumberFormatException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	}
}

void VM::initializeOSEnvironment() {
	$init(VM);
	if (initLevel() == 0) {
		$OSEnvironment::initialize();
	}
}

int32_t VM::getFinalRefCount() {
	$init(VM);
	return VM::finalRefCount;
}

int32_t VM::getPeakFinalRefCount() {
	$init(VM);
	return VM::peakFinalRefCount;
}

void VM::addFinalRefCount(int32_t n) {
	$init(VM);
	VM::finalRefCount += n;
	if (VM::finalRefCount > VM::peakFinalRefCount) {
		VM::peakFinalRefCount = VM::finalRefCount;
	}
}

$Thread$State* VM::toThreadState(int32_t threadStatus) {
	$init(VM);
	if (((int32_t)(threadStatus & (uint32_t)VM::JVMTI_THREAD_STATE_RUNNABLE)) != 0) {
		$init($Thread$State);
		return $Thread$State::RUNNABLE;
	} else if (((int32_t)(threadStatus & (uint32_t)VM::JVMTI_THREAD_STATE_BLOCKED_ON_MONITOR_ENTER)) != 0) {
		$init($Thread$State);
		return $Thread$State::BLOCKED;
	} else if (((int32_t)(threadStatus & (uint32_t)VM::JVMTI_THREAD_STATE_WAITING_INDEFINITELY)) != 0) {
		$init($Thread$State);
		return $Thread$State::WAITING;
	} else if (((int32_t)(threadStatus & (uint32_t)VM::JVMTI_THREAD_STATE_WAITING_WITH_TIMEOUT)) != 0) {
		$init($Thread$State);
		return $Thread$State::TIMED_WAITING;
	} else if (((int32_t)(threadStatus & (uint32_t)VM::JVMTI_THREAD_STATE_TERMINATED)) != 0) {
		$init($Thread$State);
		return $Thread$State::TERMINATED;
	} else if (((int32_t)(threadStatus & (uint32_t)VM::JVMTI_THREAD_STATE_ALIVE)) == 0) {
		$init($Thread$State);
		return $Thread$State::NEW;
	} else {
		$init($Thread$State);
		return $Thread$State::RUNNABLE;
	}
}

$ClassLoader* VM::latestUserDefinedLoader() {
	$init(VM);
	$beforeCallerSensitive();
	$var($ClassLoader, loader, latestUserDefinedLoader0());
	return loader != nullptr ? loader : $ClassLoader::getPlatformClassLoader();
}

$ClassLoader* VM::latestUserDefinedLoader0() {
	$init(VM);
	$var($ClassLoader, $ret, nullptr);
	$prepareNativeStatic(VM, latestUserDefinedLoader0, $ClassLoader*);
	$assign($ret, $invokeNativeStaticObject());
	$finishNativeStatic();
	return $ret;
}

bool VM::isSetUID() {
	$init(VM);
	int64_t uid = getuid();
	int64_t euid = geteuid();
	int64_t gid = getgid();
	int64_t egid = getegid();
	return uid != euid || gid != egid;
}

int64_t VM::getuid() {
	$init(VM);
	int64_t $ret = 0;
	$prepareNativeStatic(VM, getuid, int64_t);
	$ret = $invokeNativeStatic();
	$finishNativeStatic();
	return $ret;
}

int64_t VM::geteuid() {
	$init(VM);
	int64_t $ret = 0;
	$prepareNativeStatic(VM, geteuid, int64_t);
	$ret = $invokeNativeStatic();
	$finishNativeStatic();
	return $ret;
}

int64_t VM::getgid() {
	$init(VM);
	int64_t $ret = 0;
	$prepareNativeStatic(VM, getgid, int64_t);
	$ret = $invokeNativeStatic();
	$finishNativeStatic();
	return $ret;
}

int64_t VM::getegid() {
	$init(VM);
	int64_t $ret = 0;
	$prepareNativeStatic(VM, getegid, int64_t);
	$ret = $invokeNativeStatic();
	$finishNativeStatic();
	return $ret;
}

int64_t VM::getNanoTimeAdjustment(int64_t offsetInSeconds) {
	$init(VM);
	int64_t $ret = 0;
	$prepareNativeStatic(VM, getNanoTimeAdjustment, int64_t, int64_t offsetInSeconds);
	$ret = $invokeNativeStatic(offsetInSeconds);
	$finishNativeStatic();
	return $ret;
}

$StringArray* VM::getRuntimeArguments() {
	$init(VM);
	$var($StringArray, $ret, nullptr);
	$prepareNativeStatic(VM, getRuntimeArguments, $StringArray*);
	$assign($ret, $invokeNativeStaticObject());
	$finishNativeStatic();
	return $ret;
}

void VM::initialize() {
	$init(VM);
	$prepareNativeStatic(VM, initialize, void);
	$invokeNativeStatic();
	$finishNativeStatic();
}

$List* VM::getBufferPools() {
	$init(VM);
	$init($VM$BufferPoolsHolder);
	return $VM$BufferPoolsHolder::BUFFER_POOLS;
}

void clinit$VM($Class* class$) {
	$assignStatic(VM::lock, $new($Object));
	VM::directMemory = 64 * 1024 * 1024;
	{
		VM::initialize();
	}
}

VM::VM() {
}

$Class* VM::load$($String* name, bool initialize) {
	$loadClass(VM, name, initialize, &_VM_ClassInfo_, clinit$VM, allocate$VM);
	return class$;
}

$Class* VM::class$ = nullptr;

		} // misc
	} // internal
} // jdk