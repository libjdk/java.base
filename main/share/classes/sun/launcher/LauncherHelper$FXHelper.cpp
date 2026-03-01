#include <sun/launcher/LauncherHelper$FXHelper.h>

#include <java/lang/InternalError.h>
#include <java/lang/Module.h>
#include <java/lang/ModuleLayer.h>
#include <java/lang/NoSuchMethodException.h>
#include <java/lang/reflect/Method.h>
#include <java/lang/reflect/Modifier.h>
#include <java/util/Optional.h>
#include <sun/launcher/LauncherHelper.h>
#include <jcpp.h>

#undef JAVAFX_GRAPHICS_MODULE_NAME
#undef JAVAFX_LAUNCHER_CLASS_NAME
#undef JAVAFX_LAUNCH_MODE_CLASS
#undef JAVAFX_LAUNCH_MODE_JAR
#undef JAVAFX_LAUNCH_MODE_MODULE
#undef TYPE

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $Module = ::java::lang::Module;
using $ModuleLayer = ::java::lang::ModuleLayer;
using $NoSuchMethodException = ::java::lang::NoSuchMethodException;
using $RuntimeException = ::java::lang::RuntimeException;
using $Void = ::java::lang::Void;
using $Method = ::java::lang::reflect::Method;
using $Modifier = ::java::lang::reflect::Modifier;
using $Optional = ::java::util::Optional;
using $LauncherHelper = ::sun::launcher::LauncherHelper;

namespace sun {
	namespace launcher {

$FieldInfo _LauncherHelper$FXHelper_FieldInfo_[] = {
	{"JAVAFX_GRAPHICS_MODULE_NAME", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LauncherHelper$FXHelper, JAVAFX_GRAPHICS_MODULE_NAME)},
	{"JAVAFX_LAUNCHER_CLASS_NAME", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LauncherHelper$FXHelper, JAVAFX_LAUNCHER_CLASS_NAME)},
	{"JAVAFX_LAUNCH_MODE_CLASS", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LauncherHelper$FXHelper, JAVAFX_LAUNCH_MODE_CLASS)},
	{"JAVAFX_LAUNCH_MODE_JAR", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LauncherHelper$FXHelper, JAVAFX_LAUNCH_MODE_JAR)},
	{"JAVAFX_LAUNCH_MODE_MODULE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LauncherHelper$FXHelper, JAVAFX_LAUNCH_MODE_MODULE)},
	{"fxLaunchName", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticField(LauncherHelper$FXHelper, fxLaunchName)},
	{"fxLaunchMode", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticField(LauncherHelper$FXHelper, fxLaunchMode)},
	{"fxLauncherClass", "Ljava/lang/Class;", "Ljava/lang/Class<*>;", $PRIVATE | $STATIC, $staticField(LauncherHelper$FXHelper, fxLauncherClass)},
	{"fxLauncherMethod", "Ljava/lang/reflect/Method;", nullptr, $PRIVATE | $STATIC, $staticField(LauncherHelper$FXHelper, fxLauncherMethod)},
	{}
};

$MethodInfo _LauncherHelper$FXHelper_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(LauncherHelper$FXHelper, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(LauncherHelper$FXHelper, main, void, $StringArray*), "java.lang.Exception"},
	{"setFXLaunchParameters", "(Ljava/lang/String;I)V", nullptr, $PRIVATE | $STATIC, $staticMethod(LauncherHelper$FXHelper, setFXLaunchParameters, void, $String*, int32_t)},
	{}
};

$InnerClassInfo _LauncherHelper$FXHelper_InnerClassesInfo_[] = {
	{"sun.launcher.LauncherHelper$FXHelper", "sun.launcher.LauncherHelper", "FXHelper", $STATIC | $FINAL},
	{}
};

$ClassInfo _LauncherHelper$FXHelper_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.launcher.LauncherHelper$FXHelper",
	"java.lang.Object",
	nullptr,
	_LauncherHelper$FXHelper_FieldInfo_,
	_LauncherHelper$FXHelper_MethodInfo_,
	nullptr,
	nullptr,
	_LauncherHelper$FXHelper_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.launcher.LauncherHelper"
};

$Object* allocate$LauncherHelper$FXHelper($Class* clazz) {
	return $of($alloc(LauncherHelper$FXHelper));
}

$String* LauncherHelper$FXHelper::JAVAFX_GRAPHICS_MODULE_NAME = nullptr;
$String* LauncherHelper$FXHelper::JAVAFX_LAUNCHER_CLASS_NAME = nullptr;
$String* LauncherHelper$FXHelper::JAVAFX_LAUNCH_MODE_CLASS = nullptr;
$String* LauncherHelper$FXHelper::JAVAFX_LAUNCH_MODE_JAR = nullptr;
$String* LauncherHelper$FXHelper::JAVAFX_LAUNCH_MODE_MODULE = nullptr;
$String* LauncherHelper$FXHelper::fxLaunchName = nullptr;
$String* LauncherHelper$FXHelper::fxLaunchMode = nullptr;
$Class* LauncherHelper$FXHelper::fxLauncherClass = nullptr;
$Method* LauncherHelper$FXHelper::fxLauncherMethod = nullptr;

void LauncherHelper$FXHelper::init$() {
}

void LauncherHelper$FXHelper::setFXLaunchParameters($String* what, int32_t mode) {
	$init(LauncherHelper$FXHelper);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($Optional, om, $nc($($ModuleLayer::boot()))->findModule(LauncherHelper$FXHelper::JAVAFX_GRAPHICS_MODULE_NAME));
	if (!$nc(om)->isPresent()) {
		$LauncherHelper::abort(nullptr, "java.launcher.cls.error5"_s, $$new($ObjectArray, 0));
	}
	$assignStatic(LauncherHelper$FXHelper::fxLauncherClass, $Class::forName($cast($Module, $($nc(om)->get())), LauncherHelper$FXHelper::JAVAFX_LAUNCHER_CLASS_NAME));
	if (LauncherHelper$FXHelper::fxLauncherClass == nullptr) {
		$LauncherHelper::abort(nullptr, "java.launcher.cls.error5"_s, $$new($ObjectArray, 0));
	}
	try {
		$load($StringArray);
		$assignStatic(LauncherHelper$FXHelper::fxLauncherMethod, $nc(LauncherHelper$FXHelper::fxLauncherClass)->getMethod("launchApplication"_s, $$new($ClassArray, {
			$String::class$,
			$String::class$,
			$getClass($StringArray)
		})));
		int32_t mod = $nc(LauncherHelper$FXHelper::fxLauncherMethod)->getModifiers();
		if (!$Modifier::isStatic(mod)) {
			$LauncherHelper::abort(nullptr, "java.launcher.javafx.error1"_s, $$new($ObjectArray, 0));
		}
		$init($Void);
		if ($nc(LauncherHelper$FXHelper::fxLauncherMethod)->getReturnType() != $Void::TYPE) {
			$LauncherHelper::abort(nullptr, "java.launcher.javafx.error1"_s, $$new($ObjectArray, 0));
		}
	} catch ($NoSuchMethodException& ex) {
		$LauncherHelper::abort(ex, "java.launcher.cls.error5"_s, $$new($ObjectArray, {$of(ex)}));
	}
	$assignStatic(LauncherHelper$FXHelper::fxLaunchName, what);
	switch (mode) {
	case 1:
		{
			$assignStatic(LauncherHelper$FXHelper::fxLaunchMode, LauncherHelper$FXHelper::JAVAFX_LAUNCH_MODE_CLASS);
			break;
		}
	case 2:
		{
			$assignStatic(LauncherHelper$FXHelper::fxLaunchMode, LauncherHelper$FXHelper::JAVAFX_LAUNCH_MODE_JAR);
			break;
		}
	case 3:
		{
			$assignStatic(LauncherHelper$FXHelper::fxLaunchMode, LauncherHelper$FXHelper::JAVAFX_LAUNCH_MODE_MODULE);
			break;
		}
	default:
		{
			$throwNew($InternalError, $$str({$$str(mode), ": Unknown launch mode"_s}));
		}
	}
}

void LauncherHelper$FXHelper::main($StringArray* args) {
	$init(LauncherHelper$FXHelper);
	$beforeCallerSensitive();
	if (LauncherHelper$FXHelper::fxLauncherMethod == nullptr || LauncherHelper$FXHelper::fxLaunchMode == nullptr || LauncherHelper$FXHelper::fxLaunchName == nullptr) {
		$throwNew($RuntimeException, "Invalid JavaFX launch parameters"_s);
	}
	$nc(LauncherHelper$FXHelper::fxLauncherMethod)->invoke(nullptr, $$new($ObjectArray, {
		$of(LauncherHelper$FXHelper::fxLaunchName),
		$of(LauncherHelper$FXHelper::fxLaunchMode),
		$of(args)
	}));
}

void clinit$LauncherHelper$FXHelper($Class* class$) {
	$assignStatic(LauncherHelper$FXHelper::JAVAFX_GRAPHICS_MODULE_NAME, "javafx.graphics"_s);
	$assignStatic(LauncherHelper$FXHelper::JAVAFX_LAUNCHER_CLASS_NAME, "com.sun.javafx.application.LauncherImpl"_s);
	$assignStatic(LauncherHelper$FXHelper::JAVAFX_LAUNCH_MODE_CLASS, "LM_CLASS"_s);
	$assignStatic(LauncherHelper$FXHelper::JAVAFX_LAUNCH_MODE_JAR, "LM_JAR"_s);
	$assignStatic(LauncherHelper$FXHelper::JAVAFX_LAUNCH_MODE_MODULE, "LM_MODULE"_s);
	$assignStatic(LauncherHelper$FXHelper::fxLaunchName, nullptr);
	$assignStatic(LauncherHelper$FXHelper::fxLaunchMode, nullptr);
	$assignStatic(LauncherHelper$FXHelper::fxLauncherClass, nullptr);
	$assignStatic(LauncherHelper$FXHelper::fxLauncherMethod, nullptr);
}

LauncherHelper$FXHelper::LauncherHelper$FXHelper() {
}

$Class* LauncherHelper$FXHelper::load$($String* name, bool initialize) {
	$loadClass(LauncherHelper$FXHelper, name, initialize, &_LauncherHelper$FXHelper_ClassInfo_, clinit$LauncherHelper$FXHelper, allocate$LauncherHelper$FXHelper);
	return class$;
}

$Class* LauncherHelper$FXHelper::class$ = nullptr;

	} // launcher
} // sun