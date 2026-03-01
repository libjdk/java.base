#include <jdk/internal/loader/ClassLoaders.h>

#include <java/io/File.h>
#include <java/io/IOException.h>
#include <java/lang/ClassLoader.h>
#include <java/net/URI.h>
#include <java/net/URL.h>
#include <java/nio/file/InvalidPathException.h>
#include <java/nio/file/LinkOption.h>
#include <java/nio/file/Path.h>
#include <jdk/internal/access/JavaLangAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jdk/internal/loader/ArchivedClassLoaders.h>
#include <jdk/internal/loader/BuiltinClassLoader.h>
#include <jdk/internal/loader/ClassLoaders$AppClassLoader.h>
#include <jdk/internal/loader/ClassLoaders$BootClassLoader.h>
#include <jdk/internal/loader/ClassLoaders$PlatformClassLoader.h>
#include <jdk/internal/loader/URLClassPath.h>
#include <jdk/internal/misc/VM.h>
#include <jdk/internal/module/ServicesCatalog.h>
#include <jcpp.h>

#undef APP_LOADER
#undef BOOT_LOADER
#undef JLA
#undef PLATFORM_LOADER

using $LinkOptionArray = $Array<::java::nio::file::LinkOption>;
using $File = ::java::io::File;
using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $URI = ::java::net::URI;
using $URL = ::java::net::URL;
using $InvalidPathException = ::java::nio::file::InvalidPathException;
using $Path = ::java::nio::file::Path;
using $JavaLangAccess = ::jdk::internal::access::JavaLangAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $ArchivedClassLoaders = ::jdk::internal::loader::ArchivedClassLoaders;
using $BuiltinClassLoader = ::jdk::internal::loader::BuiltinClassLoader;
using $ClassLoaders$AppClassLoader = ::jdk::internal::loader::ClassLoaders$AppClassLoader;
using $ClassLoaders$BootClassLoader = ::jdk::internal::loader::ClassLoaders$BootClassLoader;
using $ClassLoaders$PlatformClassLoader = ::jdk::internal::loader::ClassLoaders$PlatformClassLoader;
using $URLClassPath = ::jdk::internal::loader::URLClassPath;
using $VM = ::jdk::internal::misc::VM;
using $ServicesCatalog = ::jdk::internal::module::ServicesCatalog;

namespace jdk {
	namespace internal {
		namespace loader {

$CompoundAttribute _ClassLoaders_MethodAnnotations_toFileURL5[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _ClassLoaders_FieldInfo_[] = {
	{"JLA", "Ljdk/internal/access/JavaLangAccess;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ClassLoaders, JLA)},
	{"BOOT_LOADER", "Ljdk/internal/loader/ClassLoaders$BootClassLoader;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ClassLoaders, BOOT_LOADER)},
	{"PLATFORM_LOADER", "Ljdk/internal/loader/ClassLoaders$PlatformClassLoader;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ClassLoaders, PLATFORM_LOADER)},
	{"APP_LOADER", "Ljdk/internal/loader/ClassLoaders$AppClassLoader;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ClassLoaders, APP_LOADER)},
	{}
};

$MethodInfo _ClassLoaders_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(ClassLoaders, init$, void)},
	{"appClassLoader", "()Ljava/lang/ClassLoader;", nullptr, $PUBLIC | $STATIC, $staticMethod(ClassLoaders, appClassLoader, $ClassLoader*)},
	{"bootLoader", "()Ljdk/internal/loader/BuiltinClassLoader;", nullptr, $STATIC, $staticMethod(ClassLoaders, bootLoader, $BuiltinClassLoader*)},
	{"platformClassLoader", "()Ljava/lang/ClassLoader;", nullptr, $PUBLIC | $STATIC, $staticMethod(ClassLoaders, platformClassLoader, $ClassLoader*)},
	{"setArchivedServicesCatalog", "(Ljava/lang/ClassLoader;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(ClassLoaders, setArchivedServicesCatalog, void, $ClassLoader*)},
	{"toFileURL", "(Ljava/lang/String;)Ljava/net/URL;", nullptr, $PRIVATE | $STATIC | $DEPRECATED, $staticMethod(ClassLoaders, toFileURL, $URL*, $String*), nullptr, nullptr, _ClassLoaders_MethodAnnotations_toFileURL5},
	{}
};

$InnerClassInfo _ClassLoaders_InnerClassesInfo_[] = {
	{"jdk.internal.loader.ClassLoaders$AppClassLoader", "jdk.internal.loader.ClassLoaders", "AppClassLoader", $PRIVATE | $STATIC},
	{"jdk.internal.loader.ClassLoaders$PlatformClassLoader", "jdk.internal.loader.ClassLoaders", "PlatformClassLoader", $PRIVATE | $STATIC},
	{"jdk.internal.loader.ClassLoaders$BootClassLoader", "jdk.internal.loader.ClassLoaders", "BootClassLoader", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _ClassLoaders_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.loader.ClassLoaders",
	"java.lang.Object",
	nullptr,
	_ClassLoaders_FieldInfo_,
	_ClassLoaders_MethodInfo_,
	nullptr,
	nullptr,
	_ClassLoaders_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.loader.ClassLoaders$AppClassLoader,jdk.internal.loader.ClassLoaders$PlatformClassLoader,jdk.internal.loader.ClassLoaders$BootClassLoader"
};

$Object* allocate$ClassLoaders($Class* clazz) {
	return $of($alloc(ClassLoaders));
}

$JavaLangAccess* ClassLoaders::JLA = nullptr;
$ClassLoaders$BootClassLoader* ClassLoaders::BOOT_LOADER = nullptr;
$ClassLoaders$PlatformClassLoader* ClassLoaders::PLATFORM_LOADER = nullptr;
$ClassLoaders$AppClassLoader* ClassLoaders::APP_LOADER = nullptr;

void ClassLoaders::init$() {
}

void ClassLoaders::setArchivedServicesCatalog($ClassLoader* loader) {
	$init(ClassLoaders);
	$useLocalCurrentObjectStackCache();
	$var($ServicesCatalog, catalog, $nc($($ArchivedClassLoaders::get()))->servicesCatalog(loader));
	$ServicesCatalog::putServicesCatalog(loader, catalog);
}

$BuiltinClassLoader* ClassLoaders::bootLoader() {
	$init(ClassLoaders);
	return ClassLoaders::BOOT_LOADER;
}

$ClassLoader* ClassLoaders::platformClassLoader() {
	$init(ClassLoaders);
	return ClassLoaders::PLATFORM_LOADER;
}

$ClassLoader* ClassLoaders::appClassLoader() {
	$init(ClassLoaders);
	return ClassLoaders::APP_LOADER;
}

$URL* ClassLoaders::toFileURL($String* s) {
	$init(ClassLoaders);
	$useLocalCurrentObjectStackCache();
	try {
		return $nc($($nc($($nc($($nc($($Path::of(s, $$new($StringArray, 0))))->toRealPath($$new($LinkOptionArray, 0))))->toFile()))->toURI()))->toURL();
	} catch ($InvalidPathException& ignore) {
		return nullptr;
	} catch ($IOException& ignore) {
		return nullptr;
	}
	$shouldNotReachHere();
}

void clinit$ClassLoaders($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(ClassLoaders::JLA, $SharedSecrets::getJavaLangAccess());
	{
		$var($ArchivedClassLoaders, archivedClassLoaders, $ArchivedClassLoaders::get());
		if (archivedClassLoaders != nullptr) {
			$assignStatic(ClassLoaders::BOOT_LOADER, $cast($ClassLoaders$BootClassLoader, archivedClassLoaders->bootLoader()));
			ClassLoaders::setArchivedServicesCatalog(ClassLoaders::BOOT_LOADER);
			$assignStatic(ClassLoaders::PLATFORM_LOADER, $cast($ClassLoaders$PlatformClassLoader, archivedClassLoaders->platformLoader()));
			ClassLoaders::setArchivedServicesCatalog(ClassLoaders::PLATFORM_LOADER);
		} else {
			$var($String, append, $VM::getSavedProperty("jdk.boot.class.path.append"_s));
			$var($URLClassPath, ucp, (append != nullptr && !append->isEmpty()) ? $new($URLClassPath, append, true) : ($URLClassPath*)nullptr);
			$assignStatic(ClassLoaders::BOOT_LOADER, $new($ClassLoaders$BootClassLoader, ucp));
			$assignStatic(ClassLoaders::PLATFORM_LOADER, $new($ClassLoaders$PlatformClassLoader, ClassLoaders::BOOT_LOADER));
		}
		$var($String, cp, $System::getProperty("java.class.path"_s));
		if (cp == nullptr || $nc(cp)->isEmpty()) {
			$var($String, initialModuleName, $System::getProperty("jdk.module.main"_s));
			$assign(cp, (initialModuleName == nullptr) ? ""_s : ($String*)nullptr);
		}
		$var($URLClassPath, ucp, $new($URLClassPath, cp, false));
		if (archivedClassLoaders != nullptr) {
			$assignStatic(ClassLoaders::APP_LOADER, $cast($ClassLoaders$AppClassLoader, archivedClassLoaders->appLoader()));
			ClassLoaders::setArchivedServicesCatalog(ClassLoaders::APP_LOADER);
			$nc(ClassLoaders::APP_LOADER)->setClassPath(ucp);
		} else {
			$assignStatic(ClassLoaders::APP_LOADER, $new($ClassLoaders$AppClassLoader, ClassLoaders::PLATFORM_LOADER, ucp));
			$ArchivedClassLoaders::archive();
		}
	}
}

ClassLoaders::ClassLoaders() {
}

$Class* ClassLoaders::load$($String* name, bool initialize) {
	$loadClass(ClassLoaders, name, initialize, &_ClassLoaders_ClassInfo_, clinit$ClassLoaders, allocate$ClassLoaders);
	return class$;
}

$Class* ClassLoaders::class$ = nullptr;

		} // loader
	} // internal
} // jdk