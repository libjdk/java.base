#include <jdk/internal/loader/ClassLoaders$AppClassLoader.h>

#include <java/lang/ClassLoader.h>
#include <java/lang/InternalError.h>
#include <java/lang/Package.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityManager.h>
#include <java/net/URL.h>
#include <java/security/CodeSource.h>
#include <java/security/Permission.h>
#include <java/security/PermissionCollection.h>
#include <java/util/jar/Manifest.h>
#include <jdk/internal/loader/BuiltinClassLoader.h>
#include <jdk/internal/loader/ClassLoaders.h>
#include <jdk/internal/loader/URLClassPath.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $Package = ::java::lang::Package;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityManager = ::java::lang::SecurityManager;
using $URL = ::java::net::URL;
using $CodeSource = ::java::security::CodeSource;
using $Permission = ::java::security::Permission;
using $PermissionCollection = ::java::security::PermissionCollection;
using $Manifest = ::java::util::jar::Manifest;
using $BuiltinClassLoader = ::jdk::internal::loader::BuiltinClassLoader;
using $URLClassPath = ::jdk::internal::loader::URLClassPath;

namespace jdk {
	namespace internal {
		namespace loader {

$MethodInfo _ClassLoaders$AppClassLoader_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/loader/BuiltinClassLoader;Ljdk/internal/loader/URLClassPath;)V", nullptr, 0, $method(ClassLoaders$AppClassLoader, init$, void, $BuiltinClassLoader*, $URLClassPath*)},
	{"appendToClassPathForInstrumentation", "(Ljava/lang/String;)V", nullptr, 0, $virtualMethod(ClassLoaders$AppClassLoader, appendToClassPathForInstrumentation, void, $String*)},
	{"defineOrCheckPackage", "(Ljava/lang/String;Ljava/util/jar/Manifest;Ljava/net/URL;)Ljava/lang/Package;", nullptr, $PROTECTED, $virtualMethod(ClassLoaders$AppClassLoader, defineOrCheckPackage, $Package*, $String*, $Manifest*, $URL*)},
	{"getPermissions", "(Ljava/security/CodeSource;)Ljava/security/PermissionCollection;", nullptr, $PROTECTED, $virtualMethod(ClassLoaders$AppClassLoader, getPermissions, $PermissionCollection*, $CodeSource*)},
	{"loadClass", "(Ljava/lang/String;Z)Ljava/lang/Class;", "(Ljava/lang/String;Z)Ljava/lang/Class<*>;", $PROTECTED, $virtualMethod(ClassLoaders$AppClassLoader, loadClass, $Class*, $String*, bool), "java.lang.ClassNotFoundException"},
	{"resetArchivedStates", "()V", nullptr, $PRIVATE, $method(ClassLoaders$AppClassLoader, resetArchivedStates, void)},
	{}
};

$InnerClassInfo _ClassLoaders$AppClassLoader_InnerClassesInfo_[] = {
	{"jdk.internal.loader.ClassLoaders$AppClassLoader", "jdk.internal.loader.ClassLoaders", "AppClassLoader", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _ClassLoaders$AppClassLoader_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.loader.ClassLoaders$AppClassLoader",
	"jdk.internal.loader.BuiltinClassLoader",
	nullptr,
	nullptr,
	_ClassLoaders$AppClassLoader_MethodInfo_,
	nullptr,
	nullptr,
	_ClassLoaders$AppClassLoader_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.loader.ClassLoaders"
};

$Object* allocate$ClassLoaders$AppClassLoader($Class* clazz) {
	return $of($alloc(ClassLoaders$AppClassLoader));
}

void ClassLoaders$AppClassLoader::init$($BuiltinClassLoader* parent, $URLClassPath* ucp) {
	$BuiltinClassLoader::init$("app"_s, parent, ucp);
}

$Class* ClassLoaders$AppClassLoader::loadClass($String* cn, bool resolve) {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		int32_t i = $nc(cn)->lastIndexOf((int32_t)u'.');
		if (i != -1) {
			sm->checkPackageAccess($(cn->substring(0, i)));
		}
	}
	return $BuiltinClassLoader::loadClass(cn, resolve);
}

$PermissionCollection* ClassLoaders$AppClassLoader::getPermissions($CodeSource* cs) {
	$useLocalCurrentObjectStackCache();
	$var($PermissionCollection, perms, $BuiltinClassLoader::getPermissions(cs));
	$nc(perms)->add($$new($RuntimePermission, "exitVM"_s));
	return perms;
}

void ClassLoaders$AppClassLoader::appendToClassPathForInstrumentation($String* path) {
	appendClassPath(path);
}

$Package* ClassLoaders$AppClassLoader::defineOrCheckPackage($String* pn, $Manifest* man, $URL* url) {
	return $BuiltinClassLoader::defineOrCheckPackage(pn, man, url);
}

void ClassLoaders$AppClassLoader::resetArchivedStates() {
	setClassPath(nullptr);
}

void clinit$ClassLoaders$AppClassLoader($Class* class$) {
	$beforeCallerSensitive();
	{
		if (!$ClassLoader::registerAsParallelCapable()) {
			$throwNew($InternalError);
		}
	}
}

ClassLoaders$AppClassLoader::ClassLoaders$AppClassLoader() {
}

$Class* ClassLoaders$AppClassLoader::load$($String* name, bool initialize) {
	$loadClass(ClassLoaders$AppClassLoader, name, initialize, &_ClassLoaders$AppClassLoader_ClassInfo_, clinit$ClassLoaders$AppClassLoader, allocate$ClassLoaders$AppClassLoader);
	return class$;
}

$Class* ClassLoaders$AppClassLoader::class$ = nullptr;

		} // loader
	} // internal
} // jdk