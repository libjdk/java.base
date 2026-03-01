#include <Versions.h>

#include <java/io/DataOutputStream.h>
#include <java/io/File.h>
#include <java/io/FileOutputStream.h>
#include <java/io/OutputStream.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/Runtime$Version.h>
#include <java/lang/Runtime.h>
#include <java/lang/UnsupportedClassVersionError.h>
#include <java/net/URL.h>
#include <java/net/URLClassLoader.h>
#include <jcpp.h>

using $URLArray = $Array<::java::net::URL>;
using $DataOutputStream = ::java::io::DataOutputStream;
using $File = ::java::io::File;
using $FileOutputStream = ::java::io::FileOutputStream;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runtime = ::java::lang::Runtime;
using $Runtime$Version = ::java::lang::Runtime$Version;
using $UnsupportedClassVersionError = ::java::lang::UnsupportedClassVersionError;
using $URLClassLoader = ::java::net::URLClassLoader;

$FieldInfo _Versions_FieldInfo_[] = {
	{"cl", "Ljava/lang/ClassLoader;", nullptr, $STATIC, $staticField(Versions, cl)},
	{}
};

$MethodInfo _Versions_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Versions, init$, void)},
	{"checkClassVersion", "(IIZ)V", nullptr, $STATIC, $staticMethod(Versions, checkClassVersion, void, int32_t, int32_t, bool), "java.lang.Exception"},
	{"getProperty", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $STATIC, $staticMethod(Versions, getProperty, $String*, $String*), "java.lang.Exception"},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(Versions, main, void, $StringArray*), "java.lang.Exception"},
	{}
};

$ClassInfo _Versions_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"Versions",
	"java.lang.Object",
	nullptr,
	_Versions_FieldInfo_,
	_Versions_MethodInfo_
};

$Object* allocate$Versions($Class* clazz) {
	return $of($alloc(Versions));
}

$ClassLoader* Versions::cl = nullptr;

void Versions::init$() {
}

$String* Versions::getProperty($String* prop) {
	$useLocalCurrentObjectStackCache();
	$var($String, value, $System::getProperty(prop));
	if (value == nullptr) {
		$throwNew($Exception, $$str({"No such system property: "_s, prop}));
	}
	$nc($System::out)->printf("%s=%s%n"_s, $$new($ObjectArray, {
		$of(prop),
		$of(value)
	}));
	return value;
}

void Versions::checkClassVersion(int32_t major, int32_t minor, bool expectSupported) {
	$load(Versions);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($String, className, "ClassVersionTest"_s);
	$var($String, classFile, $str({className, ".class"_s}));
	$var($DataOutputStream, dos, $new($DataOutputStream, $$new($FileOutputStream, classFile)));
	dos->writeLong(((int64_t)0x00000000CAFEBABE << 32) + (minor << 16) + major);
	dos->close();
	bool supported = true;
	try {
		$init(Versions);
		$Class::forName(className, false, Versions::cl);
	} catch ($UnsupportedClassVersionError& e) {
		supported = false;
	} catch ($Throwable& t) {
	}
	$$new($File, classFile)->delete$();
	if (supported != expectSupported) {
		$throwNew($Exception, "Forgot to update java.class.version?"_s);
	}
}

void Versions::main($StringArray* args) {
	$useLocalCurrentObjectStackCache();
	$var($String, classVersion, getProperty("java.class.version"_s));
	$var($String, javaVersion, getProperty("java.version"_s));
	$var($String, runtimeVersion, getProperty("java.runtime.version"_s));
	$var($String, specVersion, getProperty("java.specification.version"_s));
	$var($String, vmSpecVersion, getProperty("java.vm.specification.version"_s));
	$var($String, featureVersion, $Integer::toString($nc($($Runtime::version()))->feature()));
	bool var$2 = $nc(javaVersion)->startsWith(specVersion);
	bool var$1 = var$2 && $nc(runtimeVersion)->startsWith(specVersion);
	bool var$0 = var$1 && $nc(specVersion)->equals(featureVersion);
	if (!(var$0 && $nc(vmSpecVersion)->equals(featureVersion))) {
		$throwNew($Exception, "Invalid version-related system properties"_s);
	}
	$var($StringArray, versions, $nc(classVersion)->split("\\."_s));
	int32_t majorVersion = $Integer::parseInt(versions->get(0));
	int32_t minorVersion = $Integer::parseInt(versions->get(1));
	$nc($System::out)->printf("majorVersion=%s%n"_s, $$new($ObjectArray, {$($of($Integer::valueOf(majorVersion)))}));
	$nc($System::out)->printf("minorVersion=%s%n"_s, $$new($ObjectArray, {$($of($Integer::valueOf(minorVersion)))}));
	$init(Versions);
	$assignStatic(Versions::cl, $new($URLClassLoader, $$new($URLArray, {$($$new($File, "./"_s)->toURL())}), ($ClassLoader*)nullptr));
	checkClassVersion(majorVersion, minorVersion, true);
	checkClassVersion(majorVersion + 1, minorVersion, false);
	checkClassVersion(majorVersion, minorVersion + 1, false);
}

Versions::Versions() {
}

$Class* Versions::load$($String* name, bool initialize) {
	$loadClass(Versions, name, initialize, &_Versions_ClassInfo_, allocate$Versions);
	return class$;
}

$Class* Versions::class$ = nullptr;