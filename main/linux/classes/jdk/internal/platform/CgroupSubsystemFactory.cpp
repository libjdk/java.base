#include <jdk/internal/platform/CgroupSubsystemFactory.h>

#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/io/UncheckedIOException.h>
#include <java/lang/AssertionError.h>
#include <java/lang/CharSequence.h>
#include <java/lang/System$Logger$Level.h>
#include <java/lang/System$Logger.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/Paths.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Optional.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Function.h>
#include <java/util/function/Predicate.h>
#include <java/util/regex/Matcher.h>
#include <java/util/regex/Pattern.h>
#include <java/util/stream/Stream.h>
#include <jdk/internal/platform/CgroupInfo.h>
#include <jdk/internal/platform/CgroupMetrics.h>
#include <jdk/internal/platform/CgroupSubsystem.h>
#include <jdk/internal/platform/CgroupSubsystemFactory$CgroupTypeResult.h>
#include <jdk/internal/platform/CgroupUtil.h>
#include <jdk/internal/platform/CgroupV1Metrics.h>
#include <jdk/internal/platform/CgroupV1MetricsImpl.h>
#include <jdk/internal/platform/cgroupv1/CgroupV1Subsystem.h>
#include <jdk/internal/platform/cgroupv2/CgroupV2Subsystem.h>
#include <jcpp.h>

#undef BLKIO_CTRL
#undef CPUACCT_CTRL
#undef CPUSET_CTRL
#undef CPU_CTRL
#undef DEBUG
#undef MEMORY_CTRL
#undef MOUNTINFO_PATTERN

using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $UncheckedIOException = ::java::io::UncheckedIOException;
using $AssertionError = ::java::lang::AssertionError;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $System$Logger = ::java::lang::System$Logger;
using $System$Logger$Level = ::java::lang::System$Logger$Level;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Path = ::java::nio::file::Path;
using $Paths = ::java::nio::file::Paths;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Optional = ::java::util::Optional;
using $Consumer = ::java::util::function::Consumer;
using $Function = ::java::util::function::Function;
using $Predicate = ::java::util::function::Predicate;
using $Matcher = ::java::util::regex::Matcher;
using $Pattern = ::java::util::regex::Pattern;
using $Stream = ::java::util::stream::Stream;
using $CgroupInfo = ::jdk::internal::platform::CgroupInfo;
using $CgroupMetrics = ::jdk::internal::platform::CgroupMetrics;
using $CgroupSubsystem = ::jdk::internal::platform::CgroupSubsystem;
using $CgroupSubsystemFactory$CgroupTypeResult = ::jdk::internal::platform::CgroupSubsystemFactory$CgroupTypeResult;
using $CgroupUtil = ::jdk::internal::platform::CgroupUtil;
using $CgroupV1Metrics = ::jdk::internal::platform::CgroupV1Metrics;
using $CgroupV1MetricsImpl = ::jdk::internal::platform::CgroupV1MetricsImpl;
using $CgroupV1Subsystem = ::jdk::internal::platform::cgroupv1::CgroupV1Subsystem;
using $CgroupV2Subsystem = ::jdk::internal::platform::cgroupv2::CgroupV2Subsystem;

namespace jdk {
	namespace internal {
		namespace platform {

class CgroupSubsystemFactory$$Lambda$lambda$determineType$0 : public $Consumer {
	$class(CgroupSubsystemFactory$$Lambda$lambda$determineType$0, $NO_CLASS_INIT, $Consumer)
public:
	void init$($Map* infos) {
		$set(this, infos, infos);
	}
	virtual void accept(Object$* tokens) override {
		CgroupSubsystemFactory::lambda$determineType$0(infos, $cast($StringArray, tokens));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<CgroupSubsystemFactory$$Lambda$lambda$determineType$0>());
	}
	$Map* infos = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo CgroupSubsystemFactory$$Lambda$lambda$determineType$0::fieldInfos[2] = {
	{"infos", "Ljava/util/Map;", nullptr, $PUBLIC, $field(CgroupSubsystemFactory$$Lambda$lambda$determineType$0, infos)},
	{}
};
$MethodInfo CgroupSubsystemFactory$$Lambda$lambda$determineType$0::methodInfos[3] = {
	{"<init>", "(Ljava/util/Map;)V", nullptr, $PUBLIC, $method(CgroupSubsystemFactory$$Lambda$lambda$determineType$0, init$, void, $Map*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(CgroupSubsystemFactory$$Lambda$lambda$determineType$0, accept, void, Object$*)},
	{}
};
$ClassInfo CgroupSubsystemFactory$$Lambda$lambda$determineType$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.platform.CgroupSubsystemFactory$$Lambda$lambda$determineType$0",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* CgroupSubsystemFactory$$Lambda$lambda$determineType$0::load$($String* name, bool initialize) {
	$loadClass(CgroupSubsystemFactory$$Lambda$lambda$determineType$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* CgroupSubsystemFactory$$Lambda$lambda$determineType$0::class$ = nullptr;

class CgroupSubsystemFactory$$Lambda$lambda$determineType$1$1 : public $Consumer {
	$class(CgroupSubsystemFactory$$Lambda$lambda$determineType$1$1, $NO_CLASS_INIT, $Consumer)
public:
	void init$($Map* infos) {
		$set(this, infos, infos);
	}
	virtual void accept(Object$* tokens) override {
		CgroupSubsystemFactory::lambda$determineType$1(infos, $cast($StringArray, tokens));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<CgroupSubsystemFactory$$Lambda$lambda$determineType$1$1>());
	}
	$Map* infos = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo CgroupSubsystemFactory$$Lambda$lambda$determineType$1$1::fieldInfos[2] = {
	{"infos", "Ljava/util/Map;", nullptr, $PUBLIC, $field(CgroupSubsystemFactory$$Lambda$lambda$determineType$1$1, infos)},
	{}
};
$MethodInfo CgroupSubsystemFactory$$Lambda$lambda$determineType$1$1::methodInfos[3] = {
	{"<init>", "(Ljava/util/Map;)V", nullptr, $PUBLIC, $method(CgroupSubsystemFactory$$Lambda$lambda$determineType$1$1, init$, void, $Map*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(CgroupSubsystemFactory$$Lambda$lambda$determineType$1$1, accept, void, Object$*)},
	{}
};
$ClassInfo CgroupSubsystemFactory$$Lambda$lambda$determineType$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.platform.CgroupSubsystemFactory$$Lambda$lambda$determineType$1$1",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* CgroupSubsystemFactory$$Lambda$lambda$determineType$1$1::load$($String* name, bool initialize) {
	$loadClass(CgroupSubsystemFactory$$Lambda$lambda$determineType$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* CgroupSubsystemFactory$$Lambda$lambda$determineType$1$1::class$ = nullptr;

class CgroupSubsystemFactory$$Lambda$lambda$determineType$2$2 : public $Function {
	$class(CgroupSubsystemFactory$$Lambda$lambda$determineType$2$2, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* line) override {
		 return $of(CgroupSubsystemFactory::lambda$determineType$2($cast($String, line)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<CgroupSubsystemFactory$$Lambda$lambda$determineType$2$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo CgroupSubsystemFactory$$Lambda$lambda$determineType$2$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(CgroupSubsystemFactory$$Lambda$lambda$determineType$2$2, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(CgroupSubsystemFactory$$Lambda$lambda$determineType$2$2, apply, $Object*, Object$*)},
	{}
};
$ClassInfo CgroupSubsystemFactory$$Lambda$lambda$determineType$2$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.platform.CgroupSubsystemFactory$$Lambda$lambda$determineType$2$2",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* CgroupSubsystemFactory$$Lambda$lambda$determineType$2$2::load$($String* name, bool initialize) {
	$loadClass(CgroupSubsystemFactory$$Lambda$lambda$determineType$2$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* CgroupSubsystemFactory$$Lambda$lambda$determineType$2$2::class$ = nullptr;

class CgroupSubsystemFactory$$Lambda$lambda$determineType$3$3 : public $Predicate {
	$class(CgroupSubsystemFactory$$Lambda$lambda$determineType$3$3, $NO_CLASS_INIT, $Predicate)
public:
	void init$() {
	}
	virtual bool test(Object$* tokens) override {
		 return CgroupSubsystemFactory::lambda$determineType$3($cast($StringArray, tokens));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<CgroupSubsystemFactory$$Lambda$lambda$determineType$3$3>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo CgroupSubsystemFactory$$Lambda$lambda$determineType$3$3::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(CgroupSubsystemFactory$$Lambda$lambda$determineType$3$3, init$, void)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(CgroupSubsystemFactory$$Lambda$lambda$determineType$3$3, test, bool, Object$*)},
	{}
};
$ClassInfo CgroupSubsystemFactory$$Lambda$lambda$determineType$3$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.platform.CgroupSubsystemFactory$$Lambda$lambda$determineType$3$3",
	"java.lang.Object",
	"java.util.function.Predicate",
	nullptr,
	methodInfos
};
$Class* CgroupSubsystemFactory$$Lambda$lambda$determineType$3$3::load$($String* name, bool initialize) {
	$loadClass(CgroupSubsystemFactory$$Lambda$lambda$determineType$3$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* CgroupSubsystemFactory$$Lambda$lambda$determineType$3$3::class$ = nullptr;

$FieldInfo _CgroupSubsystemFactory_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(CgroupSubsystemFactory, $assertionsDisabled)},
	{"CPU_CTRL", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CgroupSubsystemFactory, CPU_CTRL)},
	{"CPUACCT_CTRL", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CgroupSubsystemFactory, CPUACCT_CTRL)},
	{"CPUSET_CTRL", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CgroupSubsystemFactory, CPUSET_CTRL)},
	{"BLKIO_CTRL", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CgroupSubsystemFactory, BLKIO_CTRL)},
	{"MEMORY_CTRL", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CgroupSubsystemFactory, MEMORY_CTRL)},
	{"MOUNTINFO_PATTERN", "Ljava/util/regex/Pattern;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CgroupSubsystemFactory, MOUNTINFO_PATTERN)},
	{}
};

$MethodInfo _CgroupSubsystemFactory_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(CgroupSubsystemFactory, init$, void)},
	{"amendCgroupInfos", "(Ljava/lang/String;Ljava/util/Map;Z)Z", "(Ljava/lang/String;Ljava/util/Map<Ljava/lang/String;Ljdk/internal/platform/CgroupInfo;>;Z)Z", $PRIVATE | $STATIC, $staticMethod(CgroupSubsystemFactory, amendCgroupInfos, bool, $String*, $Map*, bool)},
	{"create", "()Ljdk/internal/platform/CgroupMetrics;", nullptr, $STATIC, $staticMethod(CgroupSubsystemFactory, create, $CgroupMetrics*)},
	{"determineType", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/util/Optional;", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/util/Optional<Ljdk/internal/platform/CgroupSubsystemFactory$CgroupTypeResult;>;", $PUBLIC | $STATIC, $staticMethod(CgroupSubsystemFactory, determineType, $Optional*, $String*, $String*, $String*), "java.io.IOException"},
	{"lambda$determineType$0", "(Ljava/util/Map;[Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(CgroupSubsystemFactory, lambda$determineType$0, void, $Map*, $StringArray*)},
	{"lambda$determineType$1", "(Ljava/util/Map;[Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(CgroupSubsystemFactory, lambda$determineType$1, void, $Map*, $StringArray*)},
	{"lambda$determineType$2", "(Ljava/lang/String;)[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(CgroupSubsystemFactory, lambda$determineType$2, $StringArray*, $String*)},
	{"lambda$determineType$3", "([Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(CgroupSubsystemFactory, lambda$determineType$3, bool, $StringArray*)},
	{"setCgroupV1Path", "(Ljava/util/Map;[Ljava/lang/String;)V", "(Ljava/util/Map<Ljava/lang/String;Ljdk/internal/platform/CgroupInfo;>;[Ljava/lang/String;)V", $PRIVATE | $STATIC, $staticMethod(CgroupSubsystemFactory, setCgroupV1Path, void, $Map*, $StringArray*)},
	{"setCgroupV2Path", "(Ljava/util/Map;[Ljava/lang/String;)V", "(Ljava/util/Map<Ljava/lang/String;Ljdk/internal/platform/CgroupInfo;>;[Ljava/lang/String;)V", $PRIVATE | $STATIC, $staticMethod(CgroupSubsystemFactory, setCgroupV2Path, void, $Map*, $StringArray*)},
	{}
};

$InnerClassInfo _CgroupSubsystemFactory_InnerClassesInfo_[] = {
	{"jdk.internal.platform.CgroupSubsystemFactory$CgroupTypeResult", "jdk.internal.platform.CgroupSubsystemFactory", "CgroupTypeResult", $PUBLIC | $STATIC | $FINAL},
	{}
};

$ClassInfo _CgroupSubsystemFactory_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.platform.CgroupSubsystemFactory",
	"java.lang.Object",
	nullptr,
	_CgroupSubsystemFactory_FieldInfo_,
	_CgroupSubsystemFactory_MethodInfo_,
	nullptr,
	nullptr,
	_CgroupSubsystemFactory_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.platform.CgroupSubsystemFactory$CgroupTypeResult"
};

$Object* allocate$CgroupSubsystemFactory($Class* clazz) {
	return $of($alloc(CgroupSubsystemFactory));
}

bool CgroupSubsystemFactory::$assertionsDisabled = false;
$String* CgroupSubsystemFactory::CPU_CTRL = nullptr;
$String* CgroupSubsystemFactory::CPUACCT_CTRL = nullptr;
$String* CgroupSubsystemFactory::CPUSET_CTRL = nullptr;
$String* CgroupSubsystemFactory::BLKIO_CTRL = nullptr;
$String* CgroupSubsystemFactory::MEMORY_CTRL = nullptr;
$Pattern* CgroupSubsystemFactory::MOUNTINFO_PATTERN = nullptr;

void CgroupSubsystemFactory::init$() {
}

$CgroupMetrics* CgroupSubsystemFactory::create() {
	$init(CgroupSubsystemFactory);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($Optional, optResult, nullptr);
	try {
		$assign(optResult, determineType("/proc/self/mountinfo"_s, "/proc/cgroups"_s, "/proc/self/cgroup"_s));
	} catch ($IOException& e) {
		return nullptr;
	} catch ($UncheckedIOException& e) {
		return nullptr;
	}
	if ($nc(optResult)->isEmpty()) {
		return nullptr;
	}
	$var($CgroupSubsystemFactory$CgroupTypeResult, result, $cast($CgroupSubsystemFactory$CgroupTypeResult, $nc(optResult)->get()));
	if (!$nc(result)->isAnyControllersEnabled()) {
		return nullptr;
	}
	bool var$0 = $nc(result)->isAnyCgroupV1Controllers();
	if (var$0 && result->isAnyCgroupV2Controllers()) {
		$var($System$Logger, logger, $System::getLogger("jdk.internal.platform"_s));
		$init($System$Logger$Level);
		$nc(logger)->log($System$Logger$Level::DEBUG, "Mixed cgroupv1 and cgroupv2 not supported. Metrics disabled."_s);
		return nullptr;
	}
	$var($Map, infos, $nc(result)->getInfos());
	if (result->isCgroupV2()) {
		$var($CgroupInfo, anyController, $cast($CgroupInfo, $nc(infos)->get(CgroupSubsystemFactory::MEMORY_CTRL)));
		$var($CgroupSubsystem, subsystem, $CgroupV2Subsystem::getInstance(anyController));
		return subsystem != nullptr ? $new($CgroupMetrics, subsystem) : ($CgroupMetrics*)nullptr;
	} else {
		$var($CgroupV1Subsystem, subsystem, $CgroupV1Subsystem::getInstance(infos));
		return subsystem != nullptr ? static_cast<$CgroupMetrics*>($new($CgroupV1MetricsImpl, subsystem)) : ($CgroupMetrics*)nullptr;
	}
}

$Optional* CgroupSubsystemFactory::determineType($String* mountInfo, $String* cgroups, $String* selfCgroup) {
	$init(CgroupSubsystemFactory);
	$useLocalCurrentObjectStackCache();
	$var($Map, infos, $new($HashMap));
	$var($List, lines, $CgroupUtil::readAllLinesPrivileged($($Paths::get(cgroups, $$new($StringArray, 0)))));
	{
		$var($Iterator, i$, $nc(lines)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, line, $cast($String, i$->next()));
			{
				if ($nc(line)->startsWith("#"_s)) {
					continue;
				}
				$var($CgroupInfo, info, $CgroupInfo::fromCgroupsLine(line));
				{
					$var($String, s6589$, $nc(info)->getName());
					int32_t tmp6589$ = -1;
					switch ($nc(s6589$)->hashCode()) {
					case 0x000181A8:
						{
							if (s6589$->equals("cpu"_s)) {
								tmp6589$ = 0;
							}
							break;
						}
					case 0x3AC605BB:
						{
							if (s6589$->equals("cpuacct"_s)) {
								tmp6589$ = 1;
							}
							break;
						}
					case (int32_t)0xAF50F9BA:
						{
							if (s6589$->equals("cpuset"_s)) {
								tmp6589$ = 2;
							}
							break;
						}
					case (int32_t)0xBFC2BD01:
						{
							if (s6589$->equals("memory"_s)) {
								tmp6589$ = 3;
							}
							break;
						}
					case 0x0597B647:
						{
							if (s6589$->equals("blkio"_s)) {
								tmp6589$ = 4;
							}
							break;
						}
					}
					switch (tmp6589$) {
					case 0:
						{
							infos->put(CgroupSubsystemFactory::CPU_CTRL, info);
							break;
						}
					case 1:
						{
							infos->put(CgroupSubsystemFactory::CPUACCT_CTRL, info);
							break;
						}
					case 2:
						{
							infos->put(CgroupSubsystemFactory::CPUSET_CTRL, info);
							break;
						}
					case 3:
						{
							infos->put(CgroupSubsystemFactory::MEMORY_CTRL, info);
							break;
						}
					case 4:
						{
							infos->put(CgroupSubsystemFactory::BLKIO_CTRL, info);
							break;
						}
					}
				}
			}
		}
	}
	bool isCgroupsV2 = true;
	bool anyControllersEnabled = false;
	bool anyCgroupsV2Controller = false;
	bool anyCgroupsV1Controller = false;
	{
		$var($Iterator, i$, $nc($(infos->values()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($CgroupInfo, info, $cast($CgroupInfo, i$->next()));
			{
				anyCgroupsV1Controller = anyCgroupsV1Controller || $nc(info)->getHierarchyId() != 0;
				anyCgroupsV2Controller = anyCgroupsV2Controller || info->getHierarchyId() == 0;
				isCgroupsV2 = isCgroupsV2 && info->getHierarchyId() == 0;
				anyControllersEnabled = anyControllersEnabled || info->isEnabled();
			}
		}
	}
	$assign(lines, $CgroupUtil::readAllLinesPrivileged($($Paths::get(mountInfo, $$new($StringArray, 0)))));
	bool anyCgroupMounted = false;
	{
		$var($Iterator, i$, lines->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, line, $cast($String, i$->next()));
			{
				bool cgroupsControllerFound = amendCgroupInfos(line, infos, isCgroupsV2);
				anyCgroupMounted = anyCgroupMounted || cgroupsControllerFound;
			}
		}
	}
	if (!anyCgroupMounted) {
		return $Optional::empty();
	}
	{
		$var($Stream, selfCgroupLines, $CgroupUtil::readFilePrivileged($($Paths::get(selfCgroup, $$new($StringArray, 0)))));
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					$var($Consumer, action, static_cast<$Consumer*>($new(CgroupSubsystemFactory$$Lambda$lambda$determineType$0, infos)));
					if (isCgroupsV2) {
						$assign(action, static_cast<$Consumer*>($new(CgroupSubsystemFactory$$Lambda$lambda$determineType$1$1, infos)));
					}
					$nc($($nc($($nc(selfCgroupLines)->map(static_cast<$Function*>($$new(CgroupSubsystemFactory$$Lambda$lambda$determineType$2$2)))))->filter(static_cast<$Predicate*>($$new(CgroupSubsystemFactory$$Lambda$lambda$determineType$3$3)))))->forEach(action);
				} catch ($Throwable& t$) {
					if (selfCgroupLines != nullptr) {
						try {
							selfCgroupLines->close();
						} catch ($Throwable& x2) {
							t$->addSuppressed(x2);
						}
					}
					$throw(t$);
				}
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				if (selfCgroupLines != nullptr) {
					selfCgroupLines->close();
				}
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
	$var($CgroupSubsystemFactory$CgroupTypeResult, result, $new($CgroupSubsystemFactory$CgroupTypeResult, isCgroupsV2, anyControllersEnabled, anyCgroupsV2Controller, anyCgroupsV1Controller, $($Collections::unmodifiableMap(infos))));
	return $Optional::of(result);
}

void CgroupSubsystemFactory::setCgroupV2Path($Map* infos, $StringArray* tokens) {
	$init(CgroupSubsystemFactory);
	$useLocalCurrentObjectStackCache();
	int32_t hierarchyId = $Integer::parseInt($nc(tokens)->get(0));
	$var($String, cgroupPath, $nc(tokens)->get(2));
	{
		$var($Iterator, i$, $nc($($nc(infos)->values()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($CgroupInfo, info, $cast($CgroupInfo, i$->next()));
			{
				if (!CgroupSubsystemFactory::$assertionsDisabled && !(hierarchyId == $nc(info)->getHierarchyId() && hierarchyId == 0)) {
					$throwNew($AssertionError);
				}
				$nc(info)->setCgroupPath(cgroupPath);
			}
		}
	}
}

void CgroupSubsystemFactory::setCgroupV1Path($Map* infos, $StringArray* tokens) {
	$init(CgroupSubsystemFactory);
	$useLocalCurrentObjectStackCache();
	$var($String, controllerName, $nc(tokens)->get(1));
	$var($String, cgroupPath, tokens->get(2));
	if (controllerName != nullptr && cgroupPath != nullptr) {
		{
			$var($StringArray, arr$, controllerName->split(","_s));
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($String, cName, arr$->get(i$));
				{
					{
						$var($String, s11494$, cName);
						int32_t tmp11494$ = -1;
						switch ($nc(s11494$)->hashCode()) {
						case (int32_t)0xBFC2BD01:
							{
								if (s11494$->equals("memory"_s)) {
									tmp11494$ = 0;
								}
								break;
							}
						case (int32_t)0xAF50F9BA:
							{
								if (s11494$->equals("cpuset"_s)) {
									tmp11494$ = 1;
								}
								break;
							}
						case 0x3AC605BB:
							{
								if (s11494$->equals("cpuacct"_s)) {
									tmp11494$ = 2;
								}
								break;
							}
						case 0x000181A8:
							{
								if (s11494$->equals("cpu"_s)) {
									tmp11494$ = 3;
								}
								break;
							}
						case 0x0597B647:
							{
								if (s11494$->equals("blkio"_s)) {
									tmp11494$ = 4;
								}
								break;
							}
						}
						{
							$var($CgroupInfo, info, nullptr)
							switch (tmp11494$) {
							case 0:
								{}
							case 1:
								{}
							case 2:
								{}
							case 3:
								{}
							case 4:
								{
									$assign(info, $cast($CgroupInfo, $nc(infos)->get(cName)));
									$nc(info)->setCgroupPath(cgroupPath);
									break;
								}
							default:
								{
									break;
								}
							}
						}
					}
				}
			}
		}
	}
}

bool CgroupSubsystemFactory::amendCgroupInfos($String* mntInfoLine, $Map* infos, bool isCgroupsV2) {
	$init(CgroupSubsystemFactory);
	$useLocalCurrentObjectStackCache();
	$var($Matcher, lineMatcher, $nc(CgroupSubsystemFactory::MOUNTINFO_PATTERN)->matcher($($nc(mntInfoLine)->trim())));
	bool cgroupv1ControllerFound = false;
	bool cgroupv2ControllerFound = false;
	if ($nc(lineMatcher)->matches()) {
		$var($String, mountRoot, lineMatcher->group(1));
		$var($String, mountPath, lineMatcher->group(2));
		$var($String, fsType, lineMatcher->group(3));
		if ($nc(fsType)->equals("cgroup"_s)) {
			$var($Path, p, $Paths::get(mountPath, $$new($StringArray, 0)));
			$var($StringArray, controllerNames, $nc($($nc($($nc(p)->getFileName()))->toString()))->split(","_s));
			{
				$var($StringArray, arr$, controllerNames);
				int32_t len$ = arr$->length;
				int32_t i$ = 0;
				for (; i$ < len$; ++i$) {
					$var($String, controllerName, arr$->get(i$));
					{
						{
							$var($String, s13865$, controllerName);
							int32_t tmp13865$ = -1;
							switch ($nc(s13865$)->hashCode()) {
							case (int32_t)0xBFC2BD01:
								{
									if (s13865$->equals("memory"_s)) {
										tmp13865$ = 0;
									}
									break;
								}
							case 0x000181A8:
								{
									if (s13865$->equals("cpu"_s)) {
										tmp13865$ = 1;
									}
									break;
								}
							case 0x3AC605BB:
								{
									if (s13865$->equals("cpuacct"_s)) {
										tmp13865$ = 2;
									}
									break;
								}
							case 0x0597B647:
								{
									if (s13865$->equals("blkio"_s)) {
										tmp13865$ = 3;
									}
									break;
								}
							case (int32_t)0xAF50F9BA:
								{
									if (s13865$->equals("cpuset"_s)) {
										tmp13865$ = 4;
									}
									break;
								}
							}
							switch (tmp13865$) {
							case 0:
								{}
							case 1:
								{}
							case 2:
								{}
							case 3:
								{
									{
										$var($CgroupInfo, info, $cast($CgroupInfo, $nc(infos)->get(controllerName)));
										if (!CgroupSubsystemFactory::$assertionsDisabled && !($nc(info)->getMountPoint() == nullptr)) {
											$throwNew($AssertionError);
										}
										if (!CgroupSubsystemFactory::$assertionsDisabled && !($nc(info)->getMountRoot() == nullptr)) {
											$throwNew($AssertionError);
										}
										$nc(info)->setMountPoint(mountPath);
										info->setMountRoot(mountRoot);
										cgroupv1ControllerFound = true;
										break;
									}
								}
							case 4:
								{
									{
										$var($CgroupInfo, info, $cast($CgroupInfo, $nc(infos)->get(controllerName)));
										if ($nc(info)->getMountPoint() != nullptr) {
											if (!$nc($(info->getMountPoint()))->startsWith("/sys/fs/cgroup"_s)) {
												info->setMountPoint(mountPath);
												info->setMountRoot(mountRoot);
											}
										} else {
											info->setMountPoint(mountPath);
											info->setMountRoot(mountRoot);
										}
										cgroupv1ControllerFound = true;
										break;
									}
								}
							default:
								{
									break;
								}
							}
						}
					}
				}
			}
		} else if (fsType->equals("cgroup2"_s)) {
			if (isCgroupsV2) {
				{
					$var($Iterator, i$, $nc($($nc(infos)->values()))->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($CgroupInfo, info, $cast($CgroupInfo, i$->next()));
						{
							if (!CgroupSubsystemFactory::$assertionsDisabled && !($nc(info)->getMountPoint() == nullptr)) {
								$throwNew($AssertionError);
							}
							if (!CgroupSubsystemFactory::$assertionsDisabled && !($nc(info)->getMountRoot() == nullptr)) {
								$throwNew($AssertionError);
							}
							$nc(info)->setMountPoint(mountPath);
							info->setMountRoot(mountRoot);
						}
					}
				}
			}
			cgroupv2ControllerFound = true;
		}
	}
	return cgroupv1ControllerFound || cgroupv2ControllerFound;
}

bool CgroupSubsystemFactory::lambda$determineType$3($StringArray* tokens) {
	$init(CgroupSubsystemFactory);
	return ($nc(tokens)->length >= 3);
}

$StringArray* CgroupSubsystemFactory::lambda$determineType$2($String* line) {
	$init(CgroupSubsystemFactory);
	return $nc(line)->split(":"_s);
}

void CgroupSubsystemFactory::lambda$determineType$1($Map* infos, $StringArray* tokens) {
	$init(CgroupSubsystemFactory);
	setCgroupV2Path(infos, tokens);
}

void CgroupSubsystemFactory::lambda$determineType$0($Map* infos, $StringArray* tokens) {
	$init(CgroupSubsystemFactory);
	setCgroupV1Path(infos, tokens);
}

void clinit$CgroupSubsystemFactory($Class* class$) {
	$assignStatic(CgroupSubsystemFactory::CPU_CTRL, "cpu"_s);
	$assignStatic(CgroupSubsystemFactory::CPUACCT_CTRL, "cpuacct"_s);
	$assignStatic(CgroupSubsystemFactory::CPUSET_CTRL, "cpuset"_s);
	$assignStatic(CgroupSubsystemFactory::BLKIO_CTRL, "blkio"_s);
	$assignStatic(CgroupSubsystemFactory::MEMORY_CTRL, "memory"_s);
	CgroupSubsystemFactory::$assertionsDisabled = !CgroupSubsystemFactory::class$->desiredAssertionStatus();
	$assignStatic(CgroupSubsystemFactory::MOUNTINFO_PATTERN, $Pattern::compile("^[^\\s]+\\s+[^\\s]+\\s+[^\\s]+\\s+([^\\s]+)\\s+([^\\s]+)\\s+[^-]+-\\s+([^\\s]+)\\s+.*$"_s));
}

CgroupSubsystemFactory::CgroupSubsystemFactory() {
}

$Class* CgroupSubsystemFactory::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(CgroupSubsystemFactory$$Lambda$lambda$determineType$0::classInfo$.name)) {
			return CgroupSubsystemFactory$$Lambda$lambda$determineType$0::load$(name, initialize);
		}
		if (name->equals(CgroupSubsystemFactory$$Lambda$lambda$determineType$1$1::classInfo$.name)) {
			return CgroupSubsystemFactory$$Lambda$lambda$determineType$1$1::load$(name, initialize);
		}
		if (name->equals(CgroupSubsystemFactory$$Lambda$lambda$determineType$2$2::classInfo$.name)) {
			return CgroupSubsystemFactory$$Lambda$lambda$determineType$2$2::load$(name, initialize);
		}
		if (name->equals(CgroupSubsystemFactory$$Lambda$lambda$determineType$3$3::classInfo$.name)) {
			return CgroupSubsystemFactory$$Lambda$lambda$determineType$3$3::load$(name, initialize);
		}
	}
	$loadClass(CgroupSubsystemFactory, name, initialize, &_CgroupSubsystemFactory_ClassInfo_, clinit$CgroupSubsystemFactory, allocate$CgroupSubsystemFactory);
	return class$;
}

$Class* CgroupSubsystemFactory::class$ = nullptr;

		} // platform
	} // internal
} // jdk