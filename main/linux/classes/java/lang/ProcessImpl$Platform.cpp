#include <java/lang/ProcessImpl$Platform.h>

#include <java/io/Serializable.h>
#include <java/lang/CharSequence.h>
#include <java/lang/Enum.h>
#include <java/lang/Error.h>
#include <java/lang/ProcessImpl$LaunchMechanism.h>
#include <java/lang/ProcessImpl.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/EnumSet.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/Set.h>
#include <sun/security/action/GetPropertyAction.h>
#include <jcpp.h>

#undef AIX
#undef BSD
#undef ENGLISH
#undef FORK
#undef LINUX
#undef POSIX_SPAWN
#undef VFORK

using $ProcessImpl$LaunchMechanismArray = $Array<::java::lang::ProcessImpl$LaunchMechanism>;
using $ProcessImpl$PlatformArray = $Array<::java::lang::ProcessImpl$Platform>;
using $Serializable = ::java::io::Serializable;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $Error = ::java::lang::Error;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ProcessImpl$LaunchMechanism = ::java::lang::ProcessImpl$LaunchMechanism;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $EnumSet = ::java::util::EnumSet;
using $Locale = ::java::util::Locale;
using $Set = ::java::util::Set;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;

namespace java {
	namespace lang {

class ProcessImpl$Platform$$Lambda$lambda$launchMechanism$0 : public $PrivilegedAction {
	$class(ProcessImpl$Platform$$Lambda$lambda$launchMechanism$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$(ProcessImpl$Platform* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* run() override {
		 return $of($nc(inst$)->lambda$launchMechanism$0());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ProcessImpl$Platform$$Lambda$lambda$launchMechanism$0>());
	}
	ProcessImpl$Platform* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ProcessImpl$Platform$$Lambda$lambda$launchMechanism$0::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ProcessImpl$Platform$$Lambda$lambda$launchMechanism$0, inst$)},
	{}
};
$MethodInfo ProcessImpl$Platform$$Lambda$lambda$launchMechanism$0::methodInfos[3] = {
	{"<init>", "(Ljava/lang/ProcessImpl$Platform;)V", nullptr, $PUBLIC, $method(ProcessImpl$Platform$$Lambda$lambda$launchMechanism$0, init$, void, ProcessImpl$Platform*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ProcessImpl$Platform$$Lambda$lambda$launchMechanism$0, run, $Object*)},
	{}
};
$ClassInfo ProcessImpl$Platform$$Lambda$lambda$launchMechanism$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.ProcessImpl$Platform$$Lambda$lambda$launchMechanism$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* ProcessImpl$Platform$$Lambda$lambda$launchMechanism$0::load$($String* name, bool initialize) {
	$loadClass(ProcessImpl$Platform$$Lambda$lambda$launchMechanism$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ProcessImpl$Platform$$Lambda$lambda$launchMechanism$0::class$ = nullptr;

$FieldInfo _ProcessImpl$Platform_FieldInfo_[] = {
	{"LINUX", "Ljava/lang/ProcessImpl$Platform;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(ProcessImpl$Platform, LINUX)},
	{"BSD", "Ljava/lang/ProcessImpl$Platform;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(ProcessImpl$Platform, BSD)},
	{"AIX", "Ljava/lang/ProcessImpl$Platform;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(ProcessImpl$Platform, AIX)},
	{"$VALUES", "[Ljava/lang/ProcessImpl$Platform;", nullptr, $PRIVATE | $STATIC | $FINAL | $SYNTHETIC, $staticField(ProcessImpl$Platform, $VALUES)},
	{"defaultLaunchMechanism", "Ljava/lang/ProcessImpl$LaunchMechanism;", nullptr, $FINAL, $field(ProcessImpl$Platform, defaultLaunchMechanism)},
	{"validLaunchMechanisms", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/ProcessImpl$LaunchMechanism;>;", $FINAL, $field(ProcessImpl$Platform, validLaunchMechanisms)},
	{}
};

$MethodInfo _ProcessImpl$Platform_MethodInfo_[] = {
	{"$values", "()[Ljava/lang/ProcessImpl$Platform;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ProcessImpl$Platform, $values, $ProcessImpl$PlatformArray*)},
	{"<init>", "(Ljava/lang/String;I[Ljava/lang/ProcessImpl$LaunchMechanism;)V", "([Ljava/lang/ProcessImpl$LaunchMechanism;)V", $PRIVATE | $TRANSIENT, $method(ProcessImpl$Platform, init$, void, $String*, int32_t, $ProcessImpl$LaunchMechanismArray*)},
	{"get", "()Ljava/lang/ProcessImpl$Platform;", nullptr, $STATIC, $staticMethod(ProcessImpl$Platform, get, ProcessImpl$Platform*)},
	{"lambda$launchMechanism$0", "()Ljava/lang/ProcessImpl$LaunchMechanism;", nullptr, $PRIVATE | $SYNTHETIC, $method(ProcessImpl$Platform, lambda$launchMechanism$0, $ProcessImpl$LaunchMechanism*)},
	{"launchMechanism", "()Ljava/lang/ProcessImpl$LaunchMechanism;", nullptr, 0, $method(ProcessImpl$Platform, launchMechanism, $ProcessImpl$LaunchMechanism*)},
	{"valueOf", "(Ljava/lang/String;)Ljava/lang/ProcessImpl$Platform;", nullptr, $PUBLIC | $STATIC, $staticMethod(ProcessImpl$Platform, valueOf, ProcessImpl$Platform*, $String*)},
	{"values", "()[Ljava/lang/ProcessImpl$Platform;", nullptr, $PUBLIC | $STATIC, $staticMethod(ProcessImpl$Platform, values, $ProcessImpl$PlatformArray*)},
	{}
};

$InnerClassInfo _ProcessImpl$Platform_InnerClassesInfo_[] = {
	{"java.lang.ProcessImpl$Platform", "java.lang.ProcessImpl", "Platform", $PRIVATE | $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _ProcessImpl$Platform_ClassInfo_ = {
	$FINAL | $ACC_SUPER | $ENUM,
	"java.lang.ProcessImpl$Platform",
	"java.lang.Enum",
	nullptr,
	_ProcessImpl$Platform_FieldInfo_,
	_ProcessImpl$Platform_MethodInfo_,
	"Ljava/lang/Enum<Ljava/lang/ProcessImpl$Platform;>;",
	nullptr,
	_ProcessImpl$Platform_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.lang.ProcessImpl"
};

$Object* allocate$ProcessImpl$Platform($Class* clazz) {
	return $of($alloc(ProcessImpl$Platform));
}

ProcessImpl$Platform* ProcessImpl$Platform::LINUX = nullptr;
ProcessImpl$Platform* ProcessImpl$Platform::BSD = nullptr;
ProcessImpl$Platform* ProcessImpl$Platform::AIX = nullptr;
$ProcessImpl$PlatformArray* ProcessImpl$Platform::$VALUES = nullptr;

$ProcessImpl$PlatformArray* ProcessImpl$Platform::$values() {
	$init(ProcessImpl$Platform);
	return $new($ProcessImpl$PlatformArray, {
		ProcessImpl$Platform::LINUX,
		ProcessImpl$Platform::BSD,
		ProcessImpl$Platform::AIX
	});
}

$ProcessImpl$PlatformArray* ProcessImpl$Platform::values() {
	$init(ProcessImpl$Platform);
	return $cast($ProcessImpl$PlatformArray, ProcessImpl$Platform::$VALUES->clone());
}

ProcessImpl$Platform* ProcessImpl$Platform::valueOf($String* name) {
	$init(ProcessImpl$Platform);
	return $cast(ProcessImpl$Platform, $Enum::valueOf(ProcessImpl$Platform::class$, name));
}

void ProcessImpl$Platform::init$($String* $enum$name, int32_t $enum$ordinal, $ProcessImpl$LaunchMechanismArray* launchMechanisms) {
	$Enum::init$($enum$name, $enum$ordinal);
	$set(this, defaultLaunchMechanism, $nc(launchMechanisms)->get(0));
	$set(this, validLaunchMechanisms, $EnumSet::copyOf($(static_cast<$Collection*>($Arrays::asList(launchMechanisms)))));
}

$ProcessImpl$LaunchMechanism* ProcessImpl$Platform::launchMechanism() {
	$beforeCallerSensitive();
	return $cast($ProcessImpl$LaunchMechanism, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(ProcessImpl$Platform$$Lambda$lambda$launchMechanism$0, this))));
}

ProcessImpl$Platform* ProcessImpl$Platform::get() {
	$init(ProcessImpl$Platform);
	$useLocalCurrentObjectStackCache();
	$var($String, osName, $GetPropertyAction::privilegedGetProperty("os.name"_s));
	if ($nc(osName)->equals("Linux"_s)) {
		return ProcessImpl$Platform::LINUX;
	}
	if ($nc(osName)->contains("OS X"_s)) {
		return ProcessImpl$Platform::BSD;
	}
	if ($nc(osName)->equals("AIX"_s)) {
		return ProcessImpl$Platform::AIX;
	}
	$throwNew($Error, $$str({osName, " is not a supported OS platform."_s}));
}

$ProcessImpl$LaunchMechanism* ProcessImpl$Platform::lambda$launchMechanism$0() {
	$useLocalCurrentObjectStackCache();
	$var($String, s, $System::getProperty("jdk.lang.Process.launchMechanism"_s));
	$ProcessImpl$LaunchMechanism* lm = nullptr;
	if (s == nullptr) {
		lm = this->defaultLaunchMechanism;
		$init($Locale);
		$assign(s, $nc($($nc(lm)->name()))->toLowerCase($Locale::ENGLISH));
	} else {
		try {
			$init($Locale);
			lm = $ProcessImpl$LaunchMechanism::valueOf($($nc(s)->toUpperCase($Locale::ENGLISH)));
		} catch ($IllegalArgumentException& e) {
			lm = nullptr;
		}
	}
	if (lm == nullptr || !$nc(this->validLaunchMechanisms)->contains(lm)) {
		$throwNew($Error, $$str({s, " is not a supported process launch mechanism on this platform."_s}));
	}
	return lm;
}

void clinit$ProcessImpl$Platform($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$init($ProcessImpl$LaunchMechanism);
	$assignStatic(ProcessImpl$Platform::LINUX, $new(ProcessImpl$Platform, "LINUX"_s, 0, $$new($ProcessImpl$LaunchMechanismArray, {
		$ProcessImpl$LaunchMechanism::POSIX_SPAWN,
		$ProcessImpl$LaunchMechanism::VFORK,
		$ProcessImpl$LaunchMechanism::FORK
	})));
	$assignStatic(ProcessImpl$Platform::BSD, $new(ProcessImpl$Platform, "BSD"_s, 1, $$new($ProcessImpl$LaunchMechanismArray, {
		$ProcessImpl$LaunchMechanism::POSIX_SPAWN,
		$ProcessImpl$LaunchMechanism::FORK
	})));
	$assignStatic(ProcessImpl$Platform::AIX, $new(ProcessImpl$Platform, "AIX"_s, 2, $$new($ProcessImpl$LaunchMechanismArray, {
		$ProcessImpl$LaunchMechanism::POSIX_SPAWN,
		$ProcessImpl$LaunchMechanism::FORK
	})));
	$assignStatic(ProcessImpl$Platform::$VALUES, ProcessImpl$Platform::$values());
}

ProcessImpl$Platform::ProcessImpl$Platform() {
}

$Class* ProcessImpl$Platform::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ProcessImpl$Platform$$Lambda$lambda$launchMechanism$0::classInfo$.name)) {
			return ProcessImpl$Platform$$Lambda$lambda$launchMechanism$0::load$(name, initialize);
		}
	}
	$loadClass(ProcessImpl$Platform, name, initialize, &_ProcessImpl$Platform_ClassInfo_, clinit$ProcessImpl$Platform, allocate$ProcessImpl$Platform);
	return class$;
}

$Class* ProcessImpl$Platform::class$ = nullptr;

	} // lang
} // java