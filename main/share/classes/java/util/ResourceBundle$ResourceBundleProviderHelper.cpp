#include <java/util/ResourceBundle$ResourceBundleProviderHelper.h>

#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/Serializable.h>
#include <java/io/UncheckedIOException.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/InstantiationException.h>
#include <java/lang/InternalError.h>
#include <java/lang/Module.h>
#include <java/lang/NoSuchMethodException.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/InvocationTargetException.h>
#include <java/lang/reflect/Modifier.h>
#include <java/net/URL.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/Locale.h>
#include <java/util/PropertyResourceBundle.h>
#include <java/util/ResourceBundle$Control.h>
#include <java/util/ResourceBundle.h>
#include <jdk/internal/loader/BootLoader.h>
#include <sun/security/util/SecurityConstants.h>
#include <jcpp.h>

#undef GET_CLASSLOADER_PERMISSION
#undef INSTANCE

using $PermissionArray = $Array<::java::security::Permission>;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $Serializable = ::java::io::Serializable;
using $UncheckedIOException = ::java::io::UncheckedIOException;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InstantiationException = ::java::lang::InstantiationException;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $Module = ::java::lang::Module;
using $NoSuchMethodException = ::java::lang::NoSuchMethodException;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $Void = ::java::lang::Void;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Constructor = ::java::lang::reflect::Constructor;
using $InvocationTargetException = ::java::lang::reflect::InvocationTargetException;
using $Modifier = ::java::lang::reflect::Modifier;
using $URL = ::java::net::URL;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $Permission = ::java::security::Permission;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Locale = ::java::util::Locale;
using $PropertyResourceBundle = ::java::util::PropertyResourceBundle;
using $ResourceBundle = ::java::util::ResourceBundle;
using $ResourceBundle$Control = ::java::util::ResourceBundle$Control;
using $BootLoader = ::jdk::internal::loader::BootLoader;
using $SecurityConstants = ::sun::security::util::SecurityConstants;

namespace java {
	namespace util {

class ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$newResourceBundle$0 : public $PrivilegedAction {
	$class(ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$newResourceBundle$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$($Constructor* ctor) {
		$set(this, ctor, ctor);
	}
	virtual $Object* run() override {
		 return $of(ResourceBundle$ResourceBundleProviderHelper::lambda$newResourceBundle$0(ctor));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$newResourceBundle$0>());
	}
	$Constructor* ctor = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$newResourceBundle$0::fieldInfos[2] = {
	{"ctor", "Ljava/lang/reflect/Constructor;", nullptr, $PUBLIC, $field(ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$newResourceBundle$0, ctor)},
	{}
};
$MethodInfo ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$newResourceBundle$0::methodInfos[3] = {
	{"<init>", "(Ljava/lang/reflect/Constructor;)V", nullptr, $PUBLIC, $method(ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$newResourceBundle$0, init$, void, $Constructor*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$newResourceBundle$0, run, $Object*)},
	{}
};
$ClassInfo ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$newResourceBundle$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$newResourceBundle$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$newResourceBundle$0::load$($String* name, bool initialize) {
	$loadClass(ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$newResourceBundle$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$newResourceBundle$0::class$ = nullptr;

class ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$loadResourceBundle$1$1 : public $PrivilegedAction {
	$class(ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$loadResourceBundle$1$1, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$($Module* module, $String* bundleName) {
		$set(this, module, module);
		$set(this, bundleName, bundleName);
	}
	virtual $Object* run() override {
		 return $of(ResourceBundle$ResourceBundleProviderHelper::lambda$loadResourceBundle$1(module, bundleName));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$loadResourceBundle$1$1>());
	}
	$Module* module = nullptr;
	$String* bundleName = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$loadResourceBundle$1$1::fieldInfos[3] = {
	{"module", "Ljava/lang/Module;", nullptr, $PUBLIC, $field(ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$loadResourceBundle$1$1, module)},
	{"bundleName", "Ljava/lang/String;", nullptr, $PUBLIC, $field(ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$loadResourceBundle$1$1, bundleName)},
	{}
};
$MethodInfo ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$loadResourceBundle$1$1::methodInfos[3] = {
	{"<init>", "(Ljava/lang/Module;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$loadResourceBundle$1$1, init$, void, $Module*, $String*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$loadResourceBundle$1$1, run, $Object*)},
	{}
};
$ClassInfo ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$loadResourceBundle$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$loadResourceBundle$1$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$loadResourceBundle$1$1::load$($String* name, bool initialize) {
	$loadClass(ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$loadResourceBundle$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$loadResourceBundle$1$1::class$ = nullptr;

class ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$loadPropertyResourceBundle$2$2 : public $PrivilegedAction {
	$class(ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$loadPropertyResourceBundle$2$2, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$($String* bundleName, $Module* module, $Module* callerModule) {
		$set(this, bundleName, bundleName);
		$set(this, module, module);
		$set(this, callerModule, callerModule);
	}
	virtual $Object* run() override {
		 return $of(ResourceBundle$ResourceBundleProviderHelper::lambda$loadPropertyResourceBundle$2(bundleName, module, callerModule));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$loadPropertyResourceBundle$2$2>());
	}
	$String* bundleName = nullptr;
	$Module* module = nullptr;
	$Module* callerModule = nullptr;
	static $FieldInfo fieldInfos[4];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$loadPropertyResourceBundle$2$2::fieldInfos[4] = {
	{"bundleName", "Ljava/lang/String;", nullptr, $PUBLIC, $field(ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$loadPropertyResourceBundle$2$2, bundleName)},
	{"module", "Ljava/lang/Module;", nullptr, $PUBLIC, $field(ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$loadPropertyResourceBundle$2$2, module)},
	{"callerModule", "Ljava/lang/Module;", nullptr, $PUBLIC, $field(ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$loadPropertyResourceBundle$2$2, callerModule)},
	{}
};
$MethodInfo ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$loadPropertyResourceBundle$2$2::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;Ljava/lang/Module;Ljava/lang/Module;)V", nullptr, $PUBLIC, $method(ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$loadPropertyResourceBundle$2$2, init$, void, $String*, $Module*, $Module*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$loadPropertyResourceBundle$2$2, run, $Object*)},
	{}
};
$ClassInfo ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$loadPropertyResourceBundle$2$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$loadPropertyResourceBundle$2$2",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$loadPropertyResourceBundle$2$2::load$($String* name, bool initialize) {
	$loadClass(ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$loadPropertyResourceBundle$2$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$loadPropertyResourceBundle$2$2::class$ = nullptr;

$MethodInfo _ResourceBundle$ResourceBundleProviderHelper_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(ResourceBundle$ResourceBundleProviderHelper, init$, void)},
	{"isAccessible", "(Ljava/lang/Module;Ljava/lang/Module;Ljava/lang/String;)Z", nullptr, $STATIC, $staticMethod(ResourceBundle$ResourceBundleProviderHelper, isAccessible, bool, $Module*, $Module*, $String*)},
	{"lambda$loadPropertyResourceBundle$2", "(Ljava/lang/String;Ljava/lang/Module;Ljava/lang/Module;)Ljava/io/InputStream;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ResourceBundle$ResourceBundleProviderHelper, lambda$loadPropertyResourceBundle$2, $InputStream*, $String*, $Module*, $Module*)},
	{"lambda$loadResourceBundle$1", "(Ljava/lang/Module;Ljava/lang/String;)Ljava/lang/Class;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ResourceBundle$ResourceBundleProviderHelper, lambda$loadResourceBundle$1, $Class*, $Module*, $String*)},
	{"lambda$newResourceBundle$0", "(Ljava/lang/reflect/Constructor;)Ljava/lang/Void;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ResourceBundle$ResourceBundleProviderHelper, lambda$newResourceBundle$0, $Void*, $Constructor*)},
	{"loadPropertyResourceBundle", "(Ljava/lang/Module;Ljava/lang/Module;Ljava/lang/String;Ljava/util/Locale;)Ljava/util/ResourceBundle;", nullptr, $STATIC, $staticMethod(ResourceBundle$ResourceBundleProviderHelper, loadPropertyResourceBundle, $ResourceBundle*, $Module*, $Module*, $String*, $Locale*), "java.io.IOException"},
	{"loadResourceBundle", "(Ljava/lang/Module;Ljava/lang/Module;Ljava/lang/String;Ljava/util/Locale;)Ljava/util/ResourceBundle;", nullptr, $STATIC, $staticMethod(ResourceBundle$ResourceBundleProviderHelper, loadResourceBundle, $ResourceBundle*, $Module*, $Module*, $String*, $Locale*)},
	{"newResourceBundle", "(Ljava/lang/Class;)Ljava/util/ResourceBundle;", "(Ljava/lang/Class<+Ljava/util/ResourceBundle;>;)Ljava/util/ResourceBundle;", $STATIC, $staticMethod(ResourceBundle$ResourceBundleProviderHelper, newResourceBundle, $ResourceBundle*, $Class*)},
	{"toPackageName", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(ResourceBundle$ResourceBundleProviderHelper, toPackageName, $String*, $String*)},
	{}
};

$InnerClassInfo _ResourceBundle$ResourceBundleProviderHelper_InnerClassesInfo_[] = {
	{"java.util.ResourceBundle$ResourceBundleProviderHelper", "java.util.ResourceBundle", "ResourceBundleProviderHelper", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _ResourceBundle$ResourceBundleProviderHelper_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.ResourceBundle$ResourceBundleProviderHelper",
	"java.lang.Object",
	nullptr,
	nullptr,
	_ResourceBundle$ResourceBundleProviderHelper_MethodInfo_,
	nullptr,
	nullptr,
	_ResourceBundle$ResourceBundleProviderHelper_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.ResourceBundle"
};

$Object* allocate$ResourceBundle$ResourceBundleProviderHelper($Class* clazz) {
	return $of($alloc(ResourceBundle$ResourceBundleProviderHelper));
}

void ResourceBundle$ResourceBundleProviderHelper::init$() {
}

$ResourceBundle* ResourceBundle$ResourceBundleProviderHelper::newResourceBundle($Class* bundleClass) {
	$load(ResourceBundle$ResourceBundleProviderHelper);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	try {
		$var($Constructor, ctor, $nc(bundleClass)->getConstructor($$new($ClassArray, 0)));
		if (!$Modifier::isPublic($nc(ctor)->getModifiers())) {
			return nullptr;
		}
		$var($PrivilegedAction, pa, static_cast<$PrivilegedAction*>($new(ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$newResourceBundle$0, ctor)));
		$AccessController::doPrivileged(pa);
		try {
			return $cast($ResourceBundle, $nc(ctor)->newInstance(($ObjectArray*)nullptr));
		} catch ($InvocationTargetException& e) {
			$ResourceBundle::uncheckedThrow(e);
		} catch ($InstantiationException& e) {
			$throwNew($InternalError, static_cast<$Throwable*>(e));
		} catch ($IllegalAccessException& e) {
			$throwNew($InternalError, static_cast<$Throwable*>(e));
		}
	} catch ($NoSuchMethodException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	}
	return nullptr;
}

$ResourceBundle* ResourceBundle$ResourceBundleProviderHelper::loadResourceBundle($Module* callerModule, $Module* module, $String* baseName, $Locale* locale) {
	$load(ResourceBundle$ResourceBundleProviderHelper);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$init($ResourceBundle$Control);
	$var($String, bundleName, $nc($ResourceBundle$Control::INSTANCE)->toBundleName(baseName, locale));
	try {
		$var($PrivilegedAction, pa, static_cast<$PrivilegedAction*>($new(ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$loadResourceBundle$1$1, module, bundleName)));
		$init($SecurityConstants);
		$Class* c = $cast($Class, $AccessController::doPrivileged(pa, ($AccessControlContext*)nullptr, $$new($PermissionArray, {static_cast<$Permission*>($SecurityConstants::GET_CLASSLOADER_PERMISSION)})));
		$ResourceBundle::trace("local in %s %s caller %s: %s%n"_s, $$new($ObjectArray, {
			$of(module),
			$of(bundleName),
			$of(callerModule),
			$of(c)
		}));
		if (c == nullptr) {
			$var($ClassLoader, loader, $ResourceBundle::getLoader(module));
			if (loader != nullptr) {
				c = $Class::forName(bundleName, false, loader);
			} else {
				c = $BootLoader::loadClassOrNull(bundleName);
			}
			$ResourceBundle::trace("loader for %s %s caller %s: %s%n"_s, $$new($ObjectArray, {
				$of(module),
				$of(bundleName),
				$of(callerModule),
				$of(c)
			}));
		}
		if (c != nullptr && $ResourceBundle::class$->isAssignableFrom(c)) {
			$Class* bundleClass = c;
			$var($Module, m, $nc(bundleClass)->getModule());
			if (!isAccessible(callerModule, m, $(bundleClass->getPackageName()))) {
				$ResourceBundle::trace("   %s does not have access to %s/%s%n"_s, $$new($ObjectArray, {
					$of(callerModule),
					$($of($nc(m)->getName())),
					$($of(bundleClass->getPackageName()))
				}));
				return nullptr;
			}
			return newResourceBundle(bundleClass);
		}
	} catch ($ClassNotFoundException& e) {
	}
	return nullptr;
}

bool ResourceBundle$ResourceBundleProviderHelper::isAccessible($Module* callerModule, $Module* module, $String* pn) {
	if (!$nc(module)->isNamed() || callerModule == module) {
		return true;
	}
	return $nc(module)->isOpen(pn, callerModule);
}

$ResourceBundle* ResourceBundle$ResourceBundleProviderHelper::loadPropertyResourceBundle($Module* callerModule, $Module* module, $String* baseName, $Locale* locale) {
	$load(ResourceBundle$ResourceBundleProviderHelper);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$init($ResourceBundle$Control);
	$var($String, bundleName, $nc($ResourceBundle$Control::INSTANCE)->toBundleName(baseName, locale));
	$var($PrivilegedAction, pa, static_cast<$PrivilegedAction*>($new(ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$loadPropertyResourceBundle$2$2, bundleName, module, callerModule)));
	try {
		$var($InputStream, stream, $cast($InputStream, $AccessController::doPrivileged(pa)));
		{
			$var($Throwable, var$0, nullptr);
			$var($ResourceBundle, var$2, nullptr);
			bool return$1 = false;
			try {
				try {
					if (stream != nullptr) {
						$assign(var$2, $new($PropertyResourceBundle, stream));
						return$1 = true;
						goto $finally;
					} else {
						$assign(var$2, nullptr);
						return$1 = true;
						goto $finally;
					}
				} catch ($Throwable& t$) {
					if (stream != nullptr) {
						try {
							stream->close();
						} catch ($Throwable& x2) {
							t$->addSuppressed(x2);
						}
					}
					$throw(t$);
				}
			} catch ($Throwable& var$3) {
				$assign(var$0, var$3);
			} $finally: {
				if (stream != nullptr) {
					stream->close();
				}
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
			if (return$1) {
				return var$2;
			}
		}
	} catch ($UncheckedIOException& e) {
		$throw($($cast($IOException, e->getCause())));
	}
	$shouldNotReachHere();
}

$String* ResourceBundle$ResourceBundleProviderHelper::toPackageName($String* bundleName) {
	int32_t i = $nc(bundleName)->lastIndexOf((int32_t)u'.');
	return i != -1 ? bundleName->substring(0, i) : ""_s;
}

$InputStream* ResourceBundle$ResourceBundleProviderHelper::lambda$loadPropertyResourceBundle$2($String* bundleName, $Module* module, $Module* callerModule) {
	$load(ResourceBundle$ResourceBundleProviderHelper);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	try {
		$init($ResourceBundle$Control);
		$var($String, resourceName, $nc($ResourceBundle$Control::INSTANCE)->toResourceName0(bundleName, "properties"_s));
		if (resourceName == nullptr) {
			return nullptr;
		}
		$ResourceBundle::trace("local in %s %s caller %s%n"_s, $$new($ObjectArray, {
			$of(module),
			$of(resourceName),
			$of(callerModule)
		}));
		$var($String, pn, toPackageName(bundleName));
		$ResourceBundle::trace("   %s/%s is accessible to %s : %s%n"_s, $$new($ObjectArray, {
			$($of($nc(module)->getName())),
			$of(pn),
			$of(callerModule),
			$($of($Boolean::valueOf(isAccessible(callerModule, module, pn))))
		}));
		if (isAccessible(callerModule, module, pn)) {
			$var($InputStream, in, $nc(module)->getResourceAsStream(resourceName));
			if (in != nullptr) {
				return in;
			}
		}
		$var($ClassLoader, loader, $nc(module)->getClassLoader());
		$ResourceBundle::trace("loader for %s %s caller %s%n"_s, $$new($ObjectArray, {
			$of(module),
			$of(resourceName),
			$of(callerModule)
		}));
		try {
			if (loader != nullptr) {
				return loader->getResourceAsStream(resourceName);
			} else {
				$var($URL, url, $BootLoader::findResource(resourceName));
				if (url != nullptr) {
					return url->openStream();
				}
			}
		} catch ($Exception& e) {
		}
		return nullptr;
	} catch ($IOException& e) {
		$throwNew($UncheckedIOException, e);
	}
	$shouldNotReachHere();
}

$Class* ResourceBundle$ResourceBundleProviderHelper::lambda$loadResourceBundle$1($Module* module, $String* bundleName) {
	$load(ResourceBundle$ResourceBundleProviderHelper);
	$beforeCallerSensitive();
	return $Class::forName(module, bundleName);
}

$Void* ResourceBundle$ResourceBundleProviderHelper::lambda$newResourceBundle$0($Constructor* ctor) {
	$load(ResourceBundle$ResourceBundleProviderHelper);
	$beforeCallerSensitive();
	$nc(ctor)->setAccessible(true);
	return nullptr;
}

ResourceBundle$ResourceBundleProviderHelper::ResourceBundle$ResourceBundleProviderHelper() {
}

$Class* ResourceBundle$ResourceBundleProviderHelper::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$newResourceBundle$0::classInfo$.name)) {
			return ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$newResourceBundle$0::load$(name, initialize);
		}
		if (name->equals(ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$loadResourceBundle$1$1::classInfo$.name)) {
			return ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$loadResourceBundle$1$1::load$(name, initialize);
		}
		if (name->equals(ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$loadPropertyResourceBundle$2$2::classInfo$.name)) {
			return ResourceBundle$ResourceBundleProviderHelper$$Lambda$lambda$loadPropertyResourceBundle$2$2::load$(name, initialize);
		}
	}
	$loadClass(ResourceBundle$ResourceBundleProviderHelper, name, initialize, &_ResourceBundle$ResourceBundleProviderHelper_ClassInfo_, allocate$ResourceBundle$ResourceBundleProviderHelper);
	return class$;
}

$Class* ResourceBundle$ResourceBundleProviderHelper::class$ = nullptr;

	} // util
} // java