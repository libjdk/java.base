#include <java/util/ServiceLoader.h>

#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/LinkageError.h>
#include <java/lang/Module.h>
#include <java/lang/ModuleLayer.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/module/ModuleDescriptor.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/lang/reflect/Modifier.h>
#include <java/net/URL.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/PrivilegedActionException.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/util/ArrayList.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <java/util/Optional.h>
#include <java/util/ServiceConfigurationError.h>
#include <java/util/ServiceLoader$1.h>
#include <java/util/ServiceLoader$2.h>
#include <java/util/ServiceLoader$3.h>
#include <java/util/ServiceLoader$LayerLookupIterator.h>
#include <java/util/ServiceLoader$LazyClassPathLookupIterator.h>
#include <java/util/ServiceLoader$ModuleServicesLookupIterator.h>
#include <java/util/ServiceLoader$Provider.h>
#include <java/util/ServiceLoader$ProviderImpl.h>
#include <java/util/ServiceLoader$ProviderSpliterator.h>
#include <java/util/Spliterator.h>
#include <java/util/stream/Stream.h>
#include <java/util/stream/StreamSupport.h>
#include <jdk/internal/access/JavaLangAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jdk/internal/misc/VM.h>
#include <jdk/internal/module/ServicesCatalog$ServiceProvider.h>
#include <jdk/internal/reflect/Reflection.h>
#include <jcpp.h>

#undef LANG_ACCESS

using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $LinkageError = ::java::lang::LinkageError;
using $MethodInfo = ::java::lang::MethodInfo;
using $Module = ::java::lang::Module;
using $ModuleLayer = ::java::lang::ModuleLayer;
using $Void = ::java::lang::Void;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $ModuleDescriptor = ::java::lang::module::ModuleDescriptor;
using $Constructor = ::java::lang::reflect::Constructor;
using $Method = ::java::lang::reflect::Method;
using $Modifier = ::java::lang::reflect::Modifier;
using $URL = ::java::net::URL;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $PrivilegedActionException = ::java::security::PrivilegedActionException;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $ArrayList = ::java::util::ArrayList;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $Optional = ::java::util::Optional;
using $ServiceConfigurationError = ::java::util::ServiceConfigurationError;
using $ServiceLoader$1 = ::java::util::ServiceLoader$1;
using $ServiceLoader$2 = ::java::util::ServiceLoader$2;
using $ServiceLoader$3 = ::java::util::ServiceLoader$3;
using $ServiceLoader$LayerLookupIterator = ::java::util::ServiceLoader$LayerLookupIterator;
using $ServiceLoader$LazyClassPathLookupIterator = ::java::util::ServiceLoader$LazyClassPathLookupIterator;
using $ServiceLoader$ModuleServicesLookupIterator = ::java::util::ServiceLoader$ModuleServicesLookupIterator;
using $ServiceLoader$Provider = ::java::util::ServiceLoader$Provider;
using $ServiceLoader$ProviderImpl = ::java::util::ServiceLoader$ProviderImpl;
using $ServiceLoader$ProviderSpliterator = ::java::util::ServiceLoader$ProviderSpliterator;
using $Spliterator = ::java::util::Spliterator;
using $Stream = ::java::util::stream::Stream;
using $StreamSupport = ::java::util::stream::StreamSupport;
using $JavaLangAccess = ::jdk::internal::access::JavaLangAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $VM = ::jdk::internal::misc::VM;
using $ServicesCatalog$ServiceProvider = ::jdk::internal::module::ServicesCatalog$ServiceProvider;
using $Reflection = ::jdk::internal::reflect::Reflection;

namespace java {
	namespace util {

class ServiceLoader$$Lambda$lambda$findStaticProviderMethod$0 : public $PrivilegedAction {
	$class(ServiceLoader$$Lambda$lambda$findStaticProviderMethod$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$($Method* m) {
		$set(this, m, m);
	}
	virtual $Object* run() override {
		 return $of(ServiceLoader::lambda$findStaticProviderMethod$0(m));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ServiceLoader$$Lambda$lambda$findStaticProviderMethod$0>());
	}
	$Method* m = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ServiceLoader$$Lambda$lambda$findStaticProviderMethod$0::fieldInfos[2] = {
	{"m", "Ljava/lang/reflect/Method;", nullptr, $PUBLIC, $field(ServiceLoader$$Lambda$lambda$findStaticProviderMethod$0, m)},
	{}
};
$MethodInfo ServiceLoader$$Lambda$lambda$findStaticProviderMethod$0::methodInfos[3] = {
	{"<init>", "(Ljava/lang/reflect/Method;)V", nullptr, $PUBLIC, $method(ServiceLoader$$Lambda$lambda$findStaticProviderMethod$0, init$, void, $Method*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ServiceLoader$$Lambda$lambda$findStaticProviderMethod$0, run, $Object*)},
	{}
};
$ClassInfo ServiceLoader$$Lambda$lambda$findStaticProviderMethod$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.ServiceLoader$$Lambda$lambda$findStaticProviderMethod$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* ServiceLoader$$Lambda$lambda$findStaticProviderMethod$0::load$($String* name, bool initialize) {
	$loadClass(ServiceLoader$$Lambda$lambda$findStaticProviderMethod$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ServiceLoader$$Lambda$lambda$findStaticProviderMethod$0::class$ = nullptr;

class ServiceLoader$$Lambda$lambda$loadProvider$1$1 : public $PrivilegedExceptionAction {
	$class(ServiceLoader$$Lambda$lambda$loadProvider$1$1, $NO_CLASS_INIT, $PrivilegedExceptionAction)
public:
	void init$($Module* module, $String* cn) {
		$set(this, module, module);
		$set(this, cn, cn);
	}
	virtual $Object* run() override {
		 return $of(ServiceLoader::lambda$loadProvider$1(module, cn));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ServiceLoader$$Lambda$lambda$loadProvider$1$1>());
	}
	$Module* module = nullptr;
	$String* cn = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ServiceLoader$$Lambda$lambda$loadProvider$1$1::fieldInfos[3] = {
	{"module", "Ljava/lang/Module;", nullptr, $PUBLIC, $field(ServiceLoader$$Lambda$lambda$loadProvider$1$1, module)},
	{"cn", "Ljava/lang/String;", nullptr, $PUBLIC, $field(ServiceLoader$$Lambda$lambda$loadProvider$1$1, cn)},
	{}
};
$MethodInfo ServiceLoader$$Lambda$lambda$loadProvider$1$1::methodInfos[3] = {
	{"<init>", "(Ljava/lang/Module;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(ServiceLoader$$Lambda$lambda$loadProvider$1$1, init$, void, $Module*, $String*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ServiceLoader$$Lambda$lambda$loadProvider$1$1, run, $Object*)},
	{}
};
$ClassInfo ServiceLoader$$Lambda$lambda$loadProvider$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.ServiceLoader$$Lambda$lambda$loadProvider$1$1",
	"java.lang.Object",
	"java.security.PrivilegedExceptionAction",
	fieldInfos,
	methodInfos
};
$Class* ServiceLoader$$Lambda$lambda$loadProvider$1$1::load$($String* name, bool initialize) {
	$loadClass(ServiceLoader$$Lambda$lambda$loadProvider$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ServiceLoader$$Lambda$lambda$loadProvider$1$1::class$ = nullptr;

$CompoundAttribute _ServiceLoader_MethodAnnotations_load15[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _ServiceLoader_MethodAnnotations_load16[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _ServiceLoader_MethodAnnotations_load17[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _ServiceLoader_MethodAnnotations_loadInstalled18[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$FieldInfo _ServiceLoader_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(ServiceLoader, $assertionsDisabled)},
	{"service", "Ljava/lang/Class;", "Ljava/lang/Class<TS;>;", $PRIVATE | $FINAL, $field(ServiceLoader, service)},
	{"serviceName", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(ServiceLoader, serviceName)},
	{"layer", "Ljava/lang/ModuleLayer;", nullptr, $PRIVATE | $FINAL, $field(ServiceLoader, layer)},
	{"loader", "Ljava/lang/ClassLoader;", nullptr, $PRIVATE | $FINAL, $field(ServiceLoader, loader)},
	{"acc", "Ljava/security/AccessControlContext;", nullptr, $PRIVATE | $FINAL, $field(ServiceLoader, acc)},
	{"lookupIterator1", "Ljava/util/Iterator;", "Ljava/util/Iterator<Ljava/util/ServiceLoader$Provider<TS;>;>;", $PRIVATE, $field(ServiceLoader, lookupIterator1)},
	{"instantiatedProviders", "Ljava/util/List;", "Ljava/util/List<TS;>;", $PRIVATE | $FINAL, $field(ServiceLoader, instantiatedProviders)},
	{"lookupIterator2", "Ljava/util/Iterator;", "Ljava/util/Iterator<Ljava/util/ServiceLoader$Provider<TS;>;>;", $PRIVATE, $field(ServiceLoader, lookupIterator2)},
	{"loadedProviders", "Ljava/util/List;", "Ljava/util/List<Ljava/util/ServiceLoader$Provider<TS;>;>;", $PRIVATE | $FINAL, $field(ServiceLoader, loadedProviders)},
	{"loadedAllProviders", "Z", nullptr, $PRIVATE, $field(ServiceLoader, loadedAllProviders)},
	{"reloadCount", "I", nullptr, $PRIVATE, $field(ServiceLoader, reloadCount)},
	{"LANG_ACCESS", "Ljdk/internal/access/JavaLangAccess;", nullptr, $PRIVATE | $STATIC, $staticField(ServiceLoader, LANG_ACCESS)},
	{}
};

$MethodInfo _ServiceLoader_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/Class;Ljava/lang/ModuleLayer;Ljava/lang/Class;)V", "(Ljava/lang/Class<*>;Ljava/lang/ModuleLayer;Ljava/lang/Class<TS;>;)V", $PRIVATE, $method(ServiceLoader, init$, void, $Class*, $ModuleLayer*, $Class*)},
	{"<init>", "(Ljava/lang/Class;Ljava/lang/Class;Ljava/lang/ClassLoader;)V", "(Ljava/lang/Class<*>;Ljava/lang/Class<TS;>;Ljava/lang/ClassLoader;)V", $PRIVATE, $method(ServiceLoader, init$, void, $Class*, $Class*, $ClassLoader*)},
	{"<init>", "(Ljava/lang/Module;Ljava/lang/Class;Ljava/lang/ClassLoader;)V", "(Ljava/lang/Module;Ljava/lang/Class<TS;>;Ljava/lang/ClassLoader;)V", $PRIVATE, $method(ServiceLoader, init$, void, $Module*, $Class*, $ClassLoader*)},
	{"checkCaller", "(Ljava/lang/Class;Ljava/lang/Class;)V", "(Ljava/lang/Class<*>;Ljava/lang/Class<*>;)V", $PRIVATE | $STATIC, $staticMethod(ServiceLoader, checkCaller, void, $Class*, $Class*)},
	{"fail", "(Ljava/lang/Class;Ljava/lang/String;Ljava/lang/Throwable;)V", "(Ljava/lang/Class<*>;Ljava/lang/String;Ljava/lang/Throwable;)V", $PRIVATE | $STATIC, $staticMethod(ServiceLoader, fail, void, $Class*, $String*, $Throwable*), "java.util.ServiceConfigurationError"},
	{"fail", "(Ljava/lang/Class;Ljava/lang/String;)V", "(Ljava/lang/Class<*>;Ljava/lang/String;)V", $PRIVATE | $STATIC, $staticMethod(ServiceLoader, fail, void, $Class*, $String*), "java.util.ServiceConfigurationError"},
	{"fail", "(Ljava/lang/Class;Ljava/net/URL;ILjava/lang/String;)V", "(Ljava/lang/Class<*>;Ljava/net/URL;ILjava/lang/String;)V", $PRIVATE | $STATIC, $staticMethod(ServiceLoader, fail, void, $Class*, $URL*, int32_t, $String*), "java.util.ServiceConfigurationError"},
	{"findFirst", "()Ljava/util/Optional;", "()Ljava/util/Optional<TS;>;", $PUBLIC, $method(ServiceLoader, findFirst, $Optional*)},
	{"findStaticProviderMethod", "(Ljava/lang/Class;)Ljava/lang/reflect/Method;", "(Ljava/lang/Class<*>;)Ljava/lang/reflect/Method;", $PRIVATE, $method(ServiceLoader, findStaticProviderMethod, $Method*, $Class*)},
	{"getConstructor", "(Ljava/lang/Class;)Ljava/lang/reflect/Constructor;", "(Ljava/lang/Class<*>;)Ljava/lang/reflect/Constructor<*>;", $PRIVATE, $method(ServiceLoader, getConstructor, $Constructor*, $Class*)},
	{"inExplicitModule", "(Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;)Z", $PRIVATE, $method(ServiceLoader, inExplicitModule, bool, $Class*)},
	{"iterator", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<TS;>;", $PUBLIC, $virtualMethod(ServiceLoader, iterator, $Iterator*)},
	{"lambda$findStaticProviderMethod$0", "(Ljava/lang/reflect/Method;)Ljava/lang/Void;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ServiceLoader, lambda$findStaticProviderMethod$0, $Void*, $Method*)},
	{"lambda$loadProvider$1", "(Ljava/lang/Module;Ljava/lang/String;)Ljava/lang/Class;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ServiceLoader, lambda$loadProvider$1, $Class*, $Module*, $String*), "java.lang.Exception"},
	{"load", "(Ljava/lang/Class;Ljava/lang/ClassLoader;Ljava/lang/Module;)Ljava/util/ServiceLoader;", "<S:Ljava/lang/Object;>(Ljava/lang/Class<TS;>;Ljava/lang/ClassLoader;Ljava/lang/Module;)Ljava/util/ServiceLoader<TS;>;", $STATIC, $staticMethod(ServiceLoader, load, ServiceLoader*, $Class*, $ClassLoader*, $Module*)},
	{"load", "(Ljava/lang/Class;Ljava/lang/ClassLoader;)Ljava/util/ServiceLoader;", "<S:Ljava/lang/Object;>(Ljava/lang/Class<TS;>;Ljava/lang/ClassLoader;)Ljava/util/ServiceLoader<TS;>;", $PUBLIC | $STATIC, $staticMethod(ServiceLoader, load, ServiceLoader*, $Class*, $ClassLoader*), nullptr, nullptr, _ServiceLoader_MethodAnnotations_load15},
	{"load", "(Ljava/lang/Class;)Ljava/util/ServiceLoader;", "<S:Ljava/lang/Object;>(Ljava/lang/Class<TS;>;)Ljava/util/ServiceLoader<TS;>;", $PUBLIC | $STATIC, $staticMethod(ServiceLoader, load, ServiceLoader*, $Class*), nullptr, nullptr, _ServiceLoader_MethodAnnotations_load16},
	{"load", "(Ljava/lang/ModuleLayer;Ljava/lang/Class;)Ljava/util/ServiceLoader;", "<S:Ljava/lang/Object;>(Ljava/lang/ModuleLayer;Ljava/lang/Class<TS;>;)Ljava/util/ServiceLoader<TS;>;", $PUBLIC | $STATIC, $staticMethod(ServiceLoader, load, ServiceLoader*, $ModuleLayer*, $Class*), nullptr, nullptr, _ServiceLoader_MethodAnnotations_load17},
	{"loadInstalled", "(Ljava/lang/Class;)Ljava/util/ServiceLoader;", "<S:Ljava/lang/Object;>(Ljava/lang/Class<TS;>;)Ljava/util/ServiceLoader<TS;>;", $PUBLIC | $STATIC, $staticMethod(ServiceLoader, loadInstalled, ServiceLoader*, $Class*), nullptr, nullptr, _ServiceLoader_MethodAnnotations_loadInstalled18},
	{"loadProvider", "(Ljdk/internal/module/ServicesCatalog$ServiceProvider;)Ljava/util/ServiceLoader$Provider;", "(Ljdk/internal/module/ServicesCatalog$ServiceProvider;)Ljava/util/ServiceLoader$Provider<TS;>;", $PRIVATE, $method(ServiceLoader, loadProvider, $ServiceLoader$Provider*, $ServicesCatalog$ServiceProvider*)},
	{"newLookupIterator", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<Ljava/util/ServiceLoader$Provider<TS;>;>;", $PRIVATE, $method(ServiceLoader, newLookupIterator, $Iterator*)},
	{"reload", "()V", nullptr, $PUBLIC, $method(ServiceLoader, reload, void)},
	{"stream", "()Ljava/util/stream/Stream;", "()Ljava/util/stream/Stream<Ljava/util/ServiceLoader$Provider<TS;>;>;", $PUBLIC, $method(ServiceLoader, stream, $Stream*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ServiceLoader, toString, $String*)},
	{}
};

$InnerClassInfo _ServiceLoader_InnerClassesInfo_[] = {
	{"java.util.ServiceLoader$ProviderSpliterator", "java.util.ServiceLoader", "ProviderSpliterator", $PRIVATE},
	{"java.util.ServiceLoader$LazyClassPathLookupIterator", "java.util.ServiceLoader", "LazyClassPathLookupIterator", $PRIVATE | $FINAL},
	{"java.util.ServiceLoader$ModuleServicesLookupIterator", "java.util.ServiceLoader", "ModuleServicesLookupIterator", $PRIVATE | $FINAL},
	{"java.util.ServiceLoader$LayerLookupIterator", "java.util.ServiceLoader", "LayerLookupIterator", $PRIVATE | $FINAL},
	{"java.util.ServiceLoader$ProviderImpl", "java.util.ServiceLoader", "ProviderImpl", $PRIVATE | $STATIC},
	{"java.util.ServiceLoader$Provider", "java.util.ServiceLoader", "Provider", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.ServiceLoader$3", nullptr, nullptr, 0},
	{"java.util.ServiceLoader$2", nullptr, nullptr, 0},
	{"java.util.ServiceLoader$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ServiceLoader_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.util.ServiceLoader",
	"java.lang.Object",
	"java.lang.Iterable",
	_ServiceLoader_FieldInfo_,
	_ServiceLoader_MethodInfo_,
	"<S:Ljava/lang/Object;>Ljava/lang/Object;Ljava/lang/Iterable<TS;>;",
	nullptr,
	_ServiceLoader_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.ServiceLoader$ProviderSpliterator,java.util.ServiceLoader$LazyClassPathLookupIterator,java.util.ServiceLoader$LazyClassPathLookupIterator$2,java.util.ServiceLoader$LazyClassPathLookupIterator$1,java.util.ServiceLoader$ModuleServicesLookupIterator,java.util.ServiceLoader$LayerLookupIterator,java.util.ServiceLoader$ProviderImpl,java.util.ServiceLoader$ProviderImpl$2,java.util.ServiceLoader$ProviderImpl$1,java.util.ServiceLoader$Provider,java.util.ServiceLoader$3,java.util.ServiceLoader$2,java.util.ServiceLoader$1"
};

$Object* allocate$ServiceLoader($Class* clazz) {
	return $of($alloc(ServiceLoader));
}

bool ServiceLoader::$assertionsDisabled = false;
$JavaLangAccess* ServiceLoader::LANG_ACCESS = nullptr;

void ServiceLoader::init$($Class* caller, $ModuleLayer* layer, $Class* svc) {
	$set(this, instantiatedProviders, $new($ArrayList));
	$set(this, loadedProviders, $new($ArrayList));
	$Objects::requireNonNull(caller);
	$Objects::requireNonNull(layer);
	$Objects::requireNonNull(svc);
	checkCaller(caller, svc);
	$set(this, service, svc);
	$set(this, serviceName, svc->getName());
	$set(this, layer, layer);
	$set(this, loader, nullptr);
	$set(this, acc, ($System::getSecurityManager() != nullptr) ? $AccessController::getContext() : ($AccessControlContext*)nullptr);
}

void ServiceLoader::init$($Class* caller, $Class* svc, $ClassLoader* cl$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($ClassLoader, cl, cl$renamed);
	$beforeCallerSensitive();
	$set(this, instantiatedProviders, $new($ArrayList));
	$set(this, loadedProviders, $new($ArrayList));
	$Objects::requireNonNull(svc);
	if ($VM::isBooted()) {
		checkCaller(caller, svc);
		if (cl == nullptr) {
			$assign(cl, $ClassLoader::getSystemClassLoader());
		}
	} else {
		$var($Module, callerModule, $nc(caller)->getModule());
		$var($Module, base, $Object::class$->getModule());
		$var($Module, svcModule, svc->getModule());
		if (callerModule != base || svcModule != base) {
			fail(svc, $$str({"not accessible to "_s, callerModule, " during VM init"_s}));
		}
		$assign(cl, nullptr);
	}
	$set(this, service, svc);
	$set(this, serviceName, svc->getName());
	$set(this, layer, nullptr);
	$set(this, loader, cl);
	$set(this, acc, ($System::getSecurityManager() != nullptr) ? $AccessController::getContext() : ($AccessControlContext*)nullptr);
}

void ServiceLoader::init$($Module* callerModule, $Class* svc, $ClassLoader* cl) {
	$set(this, instantiatedProviders, $new($ArrayList));
	$set(this, loadedProviders, $new($ArrayList));
	if (!$nc(callerModule)->canUse(svc)) {
		fail(svc, $$str({callerModule, " does not declare `uses`"_s}));
	}
	$set(this, service, $cast($Class, $Objects::requireNonNull(svc)));
	$set(this, serviceName, svc->getName());
	$set(this, layer, nullptr);
	$set(this, loader, cl);
	$set(this, acc, ($System::getSecurityManager() != nullptr) ? $AccessController::getContext() : ($AccessControlContext*)nullptr);
}

void ServiceLoader::checkCaller($Class* caller, $Class* svc) {
	$init(ServiceLoader);
	$useLocalCurrentObjectStackCache();
	if (caller == nullptr) {
		fail(svc, "no caller to check if it declares `uses`"_s);
	}
	$var($Module, callerModule, $nc(caller)->getModule());
	int32_t mods = $nc(svc)->getModifiers();
	if (!$Reflection::verifyMemberAccess(caller, svc, nullptr, mods)) {
		fail(svc, $$str({"service type not accessible to "_s, callerModule}));
	}
	if (!$nc(callerModule)->canUse(svc)) {
		fail(svc, $$str({callerModule, " does not declare `uses`"_s}));
	}
}

void ServiceLoader::fail($Class* service, $String* msg, $Throwable* cause) {
	$init(ServiceLoader);
	$useLocalCurrentObjectStackCache();
	$throwNew($ServiceConfigurationError, $$str({$($nc(service)->getName()), ": "_s, msg}), cause);
}

void ServiceLoader::fail($Class* service, $String* msg) {
	$init(ServiceLoader);
	$useLocalCurrentObjectStackCache();
	$throwNew($ServiceConfigurationError, $$str({$($nc(service)->getName()), ": "_s, msg}));
}

void ServiceLoader::fail($Class* service, $URL* u, int32_t line, $String* msg) {
	$init(ServiceLoader);
	$useLocalCurrentObjectStackCache();
	fail(service, $$str({u, ":"_s, $$str(line), ": "_s, msg}));
}

bool ServiceLoader::inExplicitModule($Class* clazz) {
	$useLocalCurrentObjectStackCache();
	$var($Module, module, $nc(clazz)->getModule());
	bool var$0 = $nc(module)->isNamed();
	return var$0 && !$nc($(module->getDescriptor()))->isAutomatic();
}

$Method* ServiceLoader::findStaticProviderMethod($Class* clazz) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($List, methods, nullptr);
	try {
		$assign(methods, $nc(ServiceLoader::LANG_ACCESS)->getDeclaredPublicMethods(clazz, "provider"_s, $$new($ClassArray, 0)));
	} catch ($Throwable& x) {
		fail(this->service, "Unable to get public provider() method"_s, x);
	}
	if ($nc(methods)->isEmpty()) {
		return nullptr;
	}
	$var($Method, result, nullptr);
	{
		$var($Iterator, i$, $nc(methods)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Method, method, $cast($Method, i$->next()));
			{
				int32_t mods = $nc(method)->getModifiers();
				if (!ServiceLoader::$assertionsDisabled && !$Modifier::isPublic(mods)) {
					$throwNew($AssertionError);
				}
				if ($Modifier::isStatic(mods)) {
					if (result != nullptr) {
						fail(this->service, $$str({clazz, " declares more than one public static provider() method"_s}));
					}
					$assign(result, method);
				}
			}
		}
	}
	if (result != nullptr) {
		$var($Method, m, result);
		$var($PrivilegedAction, pa, static_cast<$PrivilegedAction*>($new(ServiceLoader$$Lambda$lambda$findStaticProviderMethod$0, m)));
		$AccessController::doPrivileged(pa);
	}
	return result;
}

$Constructor* ServiceLoader::getConstructor($Class* clazz) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($PrivilegedExceptionAction, pa, $new($ServiceLoader$1, this, clazz));
	$var($Constructor, ctor, nullptr);
	try {
		$assign(ctor, $cast($Constructor, $AccessController::doPrivileged(pa)));
	} catch ($Throwable& x) {
		if ($instanceOf($PrivilegedActionException, x)) {
			$assign(x, x->getCause());
		}
		$var($String, cn, $nc(clazz)->getName());
		fail(this->service, $$str({cn, " Unable to get public no-arg constructor"_s}), x);
	}
	return ctor;
}

$ServiceLoader$Provider* ServiceLoader::loadProvider($ServicesCatalog$ServiceProvider* provider) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($Module, module, $nc(provider)->module());
	if (!$nc(module)->canRead($($nc(this->service)->getModule()))) {
		return nullptr;
	}
	$var($String, cn, provider->providerName());
	$Class* clazz = nullptr;
	if (this->acc == nullptr) {
		try {
			clazz = $Class::forName(module, cn);
		} catch ($LinkageError& e) {
			fail(this->service, $$str({"Unable to load "_s, cn}), e);
		}
	} else {
		$var($PrivilegedExceptionAction, pa, static_cast<$PrivilegedExceptionAction*>($new(ServiceLoader$$Lambda$lambda$loadProvider$1$1, module, cn)));
		try {
			clazz = $cast($Class, $AccessController::doPrivileged(pa));
		} catch ($Throwable& x) {
			if ($instanceOf($PrivilegedActionException, x)) {
				$assign(x, x->getCause());
			}
			fail(this->service, $$str({"Unable to load "_s, cn}), x);
			return nullptr;
		}
	}
	if (clazz == nullptr) {
		fail(this->service, $$str({"Provider "_s, cn, " not found"_s}));
	}
	int32_t mods = $nc(clazz)->getModifiers();
	if (!$Modifier::isPublic(mods)) {
		fail(this->service, $$str({clazz, " is not public"_s}));
	}
	if (inExplicitModule(clazz)) {
		$var($Method, factoryMethod, findStaticProviderMethod(clazz));
		if (factoryMethod != nullptr) {
			$Class* returnType = factoryMethod->getReturnType();
			if (!$nc(this->service)->isAssignableFrom(returnType)) {
				fail(this->service, $$str({factoryMethod, " return type not a subtype"_s}));
			}
			$Class* type = returnType;
			return $new($ServiceLoader$ProviderImpl, this->service, type, factoryMethod, this->acc);
		}
	}
	if (!$nc(this->service)->isAssignableFrom(clazz)) {
		fail(this->service, $$str({$(clazz->getName()), " not a subtype"_s}));
	}
	$Class* type = clazz;
	$var($Constructor, ctor, getConstructor(clazz));
	return $new($ServiceLoader$ProviderImpl, this->service, type, ctor, this->acc);
}

$Iterator* ServiceLoader::newLookupIterator() {
	$useLocalCurrentObjectStackCache();
	if (!ServiceLoader::$assertionsDisabled && !(this->layer == nullptr || this->loader == nullptr)) {
		$throwNew($AssertionError);
	}
	if (this->layer != nullptr) {
		return $new($ServiceLoader$LayerLookupIterator, this);
	} else {
		$var($Iterator, first, $new($ServiceLoader$ModuleServicesLookupIterator, this));
		$var($Iterator, second, $new($ServiceLoader$LazyClassPathLookupIterator, this));
		return $new($ServiceLoader$2, this, first, second);
	}
}

$Iterator* ServiceLoader::iterator() {
	if (this->lookupIterator1 == nullptr) {
		$set(this, lookupIterator1, newLookupIterator());
	}
	return $new($ServiceLoader$3, this);
}

$Stream* ServiceLoader::stream() {
	if (this->loadedAllProviders) {
		return $nc(this->loadedProviders)->stream();
	}
	if (this->lookupIterator2 == nullptr) {
		$set(this, lookupIterator2, newLookupIterator());
	}
	$var($Spliterator, s, $new($ServiceLoader$ProviderSpliterator, this, this->lookupIterator2));
	return $StreamSupport::stream(s, false);
}

ServiceLoader* ServiceLoader::load($Class* service, $ClassLoader* loader, $Module* callerModule) {
	$init(ServiceLoader);
	return $new(ServiceLoader, callerModule, service, loader);
}

ServiceLoader* ServiceLoader::load($Class* service, $ClassLoader* loader) {
	$init(ServiceLoader);
	return $new(ServiceLoader, $Reflection::getCallerClass(), service, loader);
}

ServiceLoader* ServiceLoader::load($Class* service) {
	$init(ServiceLoader);
	$useLocalCurrentObjectStackCache();
	$var($ClassLoader, cl, $($Thread::currentThread())->getContextClassLoader());
	return $new(ServiceLoader, $Reflection::getCallerClass(), service, cl);
}

ServiceLoader* ServiceLoader::loadInstalled($Class* service) {
	$init(ServiceLoader);
	$var($ClassLoader, cl, $ClassLoader::getPlatformClassLoader());
	return $new(ServiceLoader, $Reflection::getCallerClass(), service, cl);
}

ServiceLoader* ServiceLoader::load($ModuleLayer* layer, $Class* service) {
	$init(ServiceLoader);
	return $new(ServiceLoader, $Reflection::getCallerClass(), layer, service);
}

$Optional* ServiceLoader::findFirst() {
	$useLocalCurrentObjectStackCache();
	$var($Iterator, iterator, this->iterator());
	if ($nc(iterator)->hasNext()) {
		return $Optional::of($(iterator->next()));
	} else {
		return $Optional::empty();
	}
}

void ServiceLoader::reload() {
	$set(this, lookupIterator1, nullptr);
	$nc(this->instantiatedProviders)->clear();
	$set(this, lookupIterator2, nullptr);
	$nc(this->loadedProviders)->clear();
	this->loadedAllProviders = false;
	++this->reloadCount;
}

$String* ServiceLoader::toString() {
	return $str({"java.util.ServiceLoader["_s, $($nc(this->service)->getName()), "]"_s});
}

$Class* ServiceLoader::lambda$loadProvider$1($Module* module, $String* cn) {
	$init(ServiceLoader);
	$beforeCallerSensitive();
	return $Class::forName(module, cn);
}

$Void* ServiceLoader::lambda$findStaticProviderMethod$0($Method* m) {
	$init(ServiceLoader);
	$beforeCallerSensitive();
	$nc(m)->setAccessible(true);
	return nullptr;
}

void clinit$ServiceLoader($Class* class$) {
	ServiceLoader::$assertionsDisabled = !ServiceLoader::class$->desiredAssertionStatus();
	{
		$assignStatic(ServiceLoader::LANG_ACCESS, $SharedSecrets::getJavaLangAccess());
	}
}

ServiceLoader::ServiceLoader() {
}

$Class* ServiceLoader::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ServiceLoader$$Lambda$lambda$findStaticProviderMethod$0::classInfo$.name)) {
			return ServiceLoader$$Lambda$lambda$findStaticProviderMethod$0::load$(name, initialize);
		}
		if (name->equals(ServiceLoader$$Lambda$lambda$loadProvider$1$1::classInfo$.name)) {
			return ServiceLoader$$Lambda$lambda$loadProvider$1$1::load$(name, initialize);
		}
	}
	$loadClass(ServiceLoader, name, initialize, &_ServiceLoader_ClassInfo_, clinit$ServiceLoader, allocate$ServiceLoader);
	return class$;
}

$Class* ServiceLoader::class$ = nullptr;

	} // util
} // java