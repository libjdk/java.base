#include <java/lang/reflect/Proxy$ProxyBuilder.h>

#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/ClassFormatError.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/InternalError.h>
#include <java/lang/Module.h>
#include <java/lang/NoSuchMethodException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/module/ModuleDescriptor$Builder.h>
#include <java/lang/module/ModuleDescriptor$Modifier.h>
#include <java/lang/module/ModuleDescriptor.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/lang/reflect/Modifier.h>
#include <java/lang/reflect/Proxy$ProxyBuilder$1.h>
#include <java/lang/reflect/Proxy.h>
#include <java/lang/reflect/ProxyGenerator.h>
#include <java/net/URI.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/ProtectionDomain.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/HashMap.h>
#include <java/util/HashSet.h>
#include <java/util/IdentityHashMap.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Set.h>
#include <java/util/concurrent/atomic/AtomicInteger.h>
#include <java/util/concurrent/atomic/AtomicLong.h>
#include <java/util/function/BiFunction.h>
#include <java/util/function/Consumer.h>
#include <jdk/internal/access/JavaLangAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jdk/internal/loader/AbstractClassLoaderValue$Sub.h>
#include <jdk/internal/loader/ClassLoaderValue.h>
#include <jdk/internal/misc/VM.h>
#include <jdk/internal/module/Modules.h>
#include <sun/security/action/GetPropertyAction.h>
#include <jcpp.h>

#undef DEBUG
#undef FINAL
#undef JLA
#undef PUBLIC
#undef SYNTHETIC
#undef TRUE

using $MethodArray = $Array<::java::lang::reflect::Method>;
using $PrintStream = ::java::io::PrintStream;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $ClassFormatError = ::java::lang::ClassFormatError;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $Module = ::java::lang::Module;
using $NoSuchMethodException = ::java::lang::NoSuchMethodException;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $ModuleDescriptor = ::java::lang::module::ModuleDescriptor;
using $ModuleDescriptor$Builder = ::java::lang::module::ModuleDescriptor$Builder;
using $ModuleDescriptor$Modifier = ::java::lang::module::ModuleDescriptor$Modifier;
using $Constructor = ::java::lang::reflect::Constructor;
using $Method = ::java::lang::reflect::Method;
using $Modifier = ::java::lang::reflect::Modifier;
using $Proxy = ::java::lang::reflect::Proxy;
using $Proxy$ProxyBuilder$1 = ::java::lang::reflect::Proxy$ProxyBuilder$1;
using $ProxyGenerator = ::java::lang::reflect::ProxyGenerator;
using $URI = ::java::net::URI;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $ProtectionDomain = ::java::security::ProtectionDomain;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $HashMap = ::java::util::HashMap;
using $HashSet = ::java::util::HashSet;
using $IdentityHashMap = ::java::util::IdentityHashMap;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Objects = ::java::util::Objects;
using $Set = ::java::util::Set;
using $AtomicInteger = ::java::util::concurrent::atomic::AtomicInteger;
using $AtomicLong = ::java::util::concurrent::atomic::AtomicLong;
using $BiFunction = ::java::util::function::BiFunction;
using $Consumer = ::java::util::function::Consumer;
using $JavaLangAccess = ::jdk::internal::access::JavaLangAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $AbstractClassLoaderValue$Sub = ::jdk::internal::loader::AbstractClassLoaderValue$Sub;
using $ClassLoaderValue = ::jdk::internal::loader::ClassLoaderValue;
using $VM = ::jdk::internal::misc::VM;
using $Modules = ::jdk::internal::module::Modules;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;

namespace java {
	namespace lang {
		namespace reflect {

class Proxy$ProxyBuilder$$Lambda$lambda$trace$0 : public $Consumer {
	$class(Proxy$ProxyBuilder$$Lambda$lambda$trace$0, $NO_CLASS_INIT, $Consumer)
public:
	void init$() {
	}
	virtual void accept(Object$* c) override {
		Proxy$ProxyBuilder::lambda$trace$0($cast($Class, c));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Proxy$ProxyBuilder$$Lambda$lambda$trace$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Proxy$ProxyBuilder$$Lambda$lambda$trace$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Proxy$ProxyBuilder$$Lambda$lambda$trace$0, init$, void)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(Proxy$ProxyBuilder$$Lambda$lambda$trace$0, accept, void, Object$*)},
	{}
};
$ClassInfo Proxy$ProxyBuilder$$Lambda$lambda$trace$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.reflect.Proxy$ProxyBuilder$$Lambda$lambda$trace$0",
	"java.lang.Object",
	"java.util.function.Consumer",
	nullptr,
	methodInfos
};
$Class* Proxy$ProxyBuilder$$Lambda$lambda$trace$0::load$($String* name, bool initialize) {
	$loadClass(Proxy$ProxyBuilder$$Lambda$lambda$trace$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Proxy$ProxyBuilder$$Lambda$lambda$trace$0::class$ = nullptr;

class Proxy$ProxyBuilder$$Lambda$lambda$getDynamicModule$1$1 : public $BiFunction {
	$class(Proxy$ProxyBuilder$$Lambda$lambda$getDynamicModule$1$1, $NO_CLASS_INIT, $BiFunction)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* ld, Object$* clv) override {
		 return $of(Proxy$ProxyBuilder::lambda$getDynamicModule$1($cast($ClassLoader, ld), $cast($ClassLoaderValue, clv)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Proxy$ProxyBuilder$$Lambda$lambda$getDynamicModule$1$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Proxy$ProxyBuilder$$Lambda$lambda$getDynamicModule$1$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Proxy$ProxyBuilder$$Lambda$lambda$getDynamicModule$1$1, init$, void)},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Proxy$ProxyBuilder$$Lambda$lambda$getDynamicModule$1$1, apply, $Object*, Object$*, Object$*)},
	{}
};
$ClassInfo Proxy$ProxyBuilder$$Lambda$lambda$getDynamicModule$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.reflect.Proxy$ProxyBuilder$$Lambda$lambda$getDynamicModule$1$1",
	"java.lang.Object",
	"java.util.function.BiFunction",
	nullptr,
	methodInfos
};
$Class* Proxy$ProxyBuilder$$Lambda$lambda$getDynamicModule$1$1::load$($String* name, bool initialize) {
	$loadClass(Proxy$ProxyBuilder$$Lambda$lambda$getDynamicModule$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Proxy$ProxyBuilder$$Lambda$lambda$getDynamicModule$1$1::class$ = nullptr;

$FieldInfo _Proxy$ProxyBuilder_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Proxy$ProxyBuilder, $assertionsDisabled)},
	{"JLA", "Ljdk/internal/access/JavaLangAccess;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Proxy$ProxyBuilder, JLA)},
	{"proxyClassNamePrefix", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Proxy$ProxyBuilder, proxyClassNamePrefix)},
	{"nextUniqueNumber", "Ljava/util/concurrent/atomic/AtomicLong;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Proxy$ProxyBuilder, nextUniqueNumber)},
	{"reverseProxyCache", "Ljdk/internal/loader/ClassLoaderValue;", "Ljdk/internal/loader/ClassLoaderValue<Ljava/lang/Boolean;>;", $PRIVATE | $STATIC | $FINAL, $staticField(Proxy$ProxyBuilder, reverseProxyCache)},
	{"DEBUG", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Proxy$ProxyBuilder, DEBUG)},
	{"interfaces", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/Class<*>;>;", $PRIVATE | $FINAL, $field(Proxy$ProxyBuilder, interfaces)},
	{"module", "Ljava/lang/Module;", nullptr, $PRIVATE | $FINAL, $field(Proxy$ProxyBuilder, module)},
	{"dynProxyModules", "Ljdk/internal/loader/ClassLoaderValue;", "Ljdk/internal/loader/ClassLoaderValue<Ljava/lang/Module;>;", $PRIVATE | $STATIC | $FINAL, $staticField(Proxy$ProxyBuilder, dynProxyModules)},
	{"counter", "Ljava/util/concurrent/atomic/AtomicInteger;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Proxy$ProxyBuilder, counter)},
	{}
};

$MethodInfo _Proxy$ProxyBuilder_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/ClassLoader;Ljava/util/List;)V", "(Ljava/lang/ClassLoader;Ljava/util/List<Ljava/lang/Class<*>;>;)V", 0, $method(Proxy$ProxyBuilder, init$, void, $ClassLoader*, $List*)},
	{"<init>", "(Ljava/lang/ClassLoader;Ljava/lang/Class;)V", "(Ljava/lang/ClassLoader;Ljava/lang/Class<*>;)V", 0, $method(Proxy$ProxyBuilder, init$, void, $ClassLoader*, $Class*)},
	{"addElementType", "(Ljava/util/HashSet;Ljava/lang/Class;)V", "(Ljava/util/HashSet<Ljava/lang/Class<*>;>;Ljava/lang/Class<*>;)V", $PRIVATE | $STATIC, $staticMethod(Proxy$ProxyBuilder, addElementType, void, $HashSet*, $Class*)},
	{"addElementTypes", "(Ljava/util/HashSet;[Ljava/lang/Class;)V", "(Ljava/util/HashSet<Ljava/lang/Class<*>;>;[Ljava/lang/Class<*>;)V", $PRIVATE | $STATIC | $TRANSIENT, $staticMethod(Proxy$ProxyBuilder, addElementTypes, void, $HashSet*, $ClassArray*)},
	{"build", "()Ljava/lang/reflect/Constructor;", "()Ljava/lang/reflect/Constructor<*>;", 0, $method(Proxy$ProxyBuilder, build, $Constructor*)},
	{"defineProxyClass", "(Ljava/lang/Module;Ljava/util/List;)Ljava/lang/Class;", "(Ljava/lang/Module;Ljava/util/List<Ljava/lang/Class<*>;>;)Ljava/lang/Class<*>;", $PRIVATE | $STATIC, $staticMethod(Proxy$ProxyBuilder, defineProxyClass, $Class*, $Module*, $List*)},
	{"ensureAccess", "(Ljava/lang/Module;Ljava/lang/Class;)V", "(Ljava/lang/Module;Ljava/lang/Class<*>;)V", $PRIVATE | $STATIC, $staticMethod(Proxy$ProxyBuilder, ensureAccess, void, $Module*, $Class*)},
	{"ensureVisible", "(Ljava/lang/ClassLoader;Ljava/lang/Class;)V", "(Ljava/lang/ClassLoader;Ljava/lang/Class<*>;)V", $PRIVATE | $STATIC, $staticMethod(Proxy$ProxyBuilder, ensureVisible, void, $ClassLoader*, $Class*)},
	{"getDynamicModule", "(Ljava/lang/ClassLoader;)Ljava/lang/Module;", nullptr, $PRIVATE | $STATIC, $staticMethod(Proxy$ProxyBuilder, getDynamicModule, $Module*, $ClassLoader*)},
	{"getElementType", "(Ljava/lang/Class;)Ljava/lang/Class;", "(Ljava/lang/Class<*>;)Ljava/lang/Class<*>;", $PRIVATE | $STATIC, $staticMethod(Proxy$ProxyBuilder, getElementType, $Class*, $Class*)},
	{"isDebug", "()Z", nullptr, $PRIVATE | $STATIC, $staticMethod(Proxy$ProxyBuilder, isDebug, bool)},
	{"isDebug", "(Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(Proxy$ProxyBuilder, isDebug, bool, $String*)},
	{"isExportedType", "(Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;)Z", $PRIVATE | $STATIC, $staticMethod(Proxy$ProxyBuilder, isExportedType, bool, $Class*)},
	{"isPackagePrivateType", "(Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;)Z", $PRIVATE | $STATIC, $staticMethod(Proxy$ProxyBuilder, isPackagePrivateType, bool, $Class*)},
	{"isProxyClass", "(Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;)Z", $STATIC, $staticMethod(Proxy$ProxyBuilder, isProxyClass, bool, $Class*)},
	{"lambda$getDynamicModule$1", "(Ljava/lang/ClassLoader;Ljdk/internal/loader/ClassLoaderValue;)Ljava/lang/Module;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Proxy$ProxyBuilder, lambda$getDynamicModule$1, $Module*, $ClassLoader*, $ClassLoaderValue*)},
	{"lambda$trace$0", "(Ljava/lang/Class;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Proxy$ProxyBuilder, lambda$trace$0, void, $Class*)},
	{"mapToModule", "(Ljava/lang/ClassLoader;Ljava/util/List;Ljava/util/Set;)Ljava/lang/Module;", "(Ljava/lang/ClassLoader;Ljava/util/List<Ljava/lang/Class<*>;>;Ljava/util/Set<Ljava/lang/Class<*>;>;)Ljava/lang/Module;", $PRIVATE | $STATIC, $staticMethod(Proxy$ProxyBuilder, mapToModule, $Module*, $ClassLoader*, $List*, $Set*)},
	{"referencedTypes", "(Ljava/lang/ClassLoader;Ljava/util/List;)Ljava/util/Set;", "(Ljava/lang/ClassLoader;Ljava/util/List<Ljava/lang/Class<*>;>;)Ljava/util/Set<Ljava/lang/Class<*>;>;", $PRIVATE | $STATIC, $staticMethod(Proxy$ProxyBuilder, referencedTypes, $Set*, $ClassLoader*, $List*)},
	{"toDetails", "(Ljava/lang/Class;)Ljava/lang/String;", "(Ljava/lang/Class<*>;)Ljava/lang/String;", $PRIVATE | $STATIC, $staticMethod(Proxy$ProxyBuilder, toDetails, $String*, $Class*)},
	{"trace", "(Ljava/lang/String;Ljava/lang/Module;Ljava/lang/ClassLoader;Ljava/util/List;)V", "(Ljava/lang/String;Ljava/lang/Module;Ljava/lang/ClassLoader;Ljava/util/List<Ljava/lang/Class<*>;>;)V", $STATIC, $staticMethod(Proxy$ProxyBuilder, trace, void, $String*, $Module*, $ClassLoader*, $List*)},
	{"validateProxyInterfaces", "(Ljava/lang/ClassLoader;Ljava/util/List;Ljava/util/Set;)V", "(Ljava/lang/ClassLoader;Ljava/util/List<Ljava/lang/Class<*>;>;Ljava/util/Set<Ljava/lang/Class<*>;>;)V", $PRIVATE | $STATIC, $staticMethod(Proxy$ProxyBuilder, validateProxyInterfaces, void, $ClassLoader*, $List*, $Set*)},
	{}
};

$InnerClassInfo _Proxy$ProxyBuilder_InnerClassesInfo_[] = {
	{"java.lang.reflect.Proxy$ProxyBuilder", "java.lang.reflect.Proxy", "ProxyBuilder", $PRIVATE | $STATIC | $FINAL},
	{"java.lang.reflect.Proxy$ProxyBuilder$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Proxy$ProxyBuilder_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.lang.reflect.Proxy$ProxyBuilder",
	"java.lang.Object",
	nullptr,
	_Proxy$ProxyBuilder_FieldInfo_,
	_Proxy$ProxyBuilder_MethodInfo_,
	nullptr,
	nullptr,
	_Proxy$ProxyBuilder_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.lang.reflect.Proxy"
};

$Object* allocate$Proxy$ProxyBuilder($Class* clazz) {
	return $of($alloc(Proxy$ProxyBuilder));
}

bool Proxy$ProxyBuilder::$assertionsDisabled = false;
$JavaLangAccess* Proxy$ProxyBuilder::JLA = nullptr;
$String* Proxy$ProxyBuilder::proxyClassNamePrefix = nullptr;
$AtomicLong* Proxy$ProxyBuilder::nextUniqueNumber = nullptr;
$ClassLoaderValue* Proxy$ProxyBuilder::reverseProxyCache = nullptr;
$String* Proxy$ProxyBuilder::DEBUG = nullptr;
$ClassLoaderValue* Proxy$ProxyBuilder::dynProxyModules = nullptr;
$AtomicInteger* Proxy$ProxyBuilder::counter = nullptr;

$Class* Proxy$ProxyBuilder::defineProxyClass($Module* m, $List* interfaces) {
	$init(Proxy$ProxyBuilder);
	$useLocalCurrentObjectStackCache();
	$var($String, proxyPkg, nullptr);
	int32_t accessFlags = $Modifier::PUBLIC | $Modifier::FINAL;
	bool nonExported = false;
	{
		$var($Iterator, i$, $nc(interfaces)->iterator());
		for (; $nc(i$)->hasNext();) {
			$Class* intf = $cast($Class, i$->next());
			{
				int32_t flags = $nc(intf)->getModifiers();
				if (!$Modifier::isPublic(flags)) {
					accessFlags = $Modifier::FINAL;
					$var($String, pkg, intf->getPackageName());
					if (proxyPkg == nullptr) {
						$assign(proxyPkg, pkg);
					} else if (!$nc(pkg)->equals(proxyPkg)) {
						$throwNew($IllegalArgumentException, "non-public interfaces from different packages"_s);
					}
				} else if (!$nc($(intf->getModule()))->isExported($(intf->getPackageName()))) {
					nonExported = true;
				}
			}
		}
	}
	if (proxyPkg == nullptr) {
		if (!$nc(m)->isNamed()) {
			$throwNew($InternalError, $$str({"ununamed module: "_s, m}));
		}
		$assign(proxyPkg, nonExported ? $str({"com.sun.proxy"_s, "."_s, $($nc(m)->getName())}) : m->getName());
	} else {
		bool var$1 = $nc(proxyPkg)->isEmpty();
		if (var$1 && $nc(m)->isNamed()) {
			$throwNew($IllegalArgumentException, $$str({"Unnamed package cannot be added to "_s, m}));
		}
	}
	if ($nc(m)->isNamed()) {
		if (!$nc($($nc($(m->getDescriptor()))->packages()))->contains(proxyPkg)) {
			$throwNew($InternalError, $$str({proxyPkg, " not exist in "_s, $(m->getName())}));
		}
	}
	int64_t num = $nc(Proxy$ProxyBuilder::nextUniqueNumber)->getAndIncrement();
	$var($String, proxyName, $nc(proxyPkg)->isEmpty() ? $str({Proxy$ProxyBuilder::proxyClassNamePrefix, $$str(num)}) : $str({proxyPkg, "."_s, Proxy$ProxyBuilder::proxyClassNamePrefix, $$str(num)}));
	$var($ClassLoader, loader, $Proxy::getLoader(m));
	trace(proxyName, m, loader, interfaces);
	$var($bytes, proxyClassFile, $ProxyGenerator::generateProxyClass(loader, proxyName, interfaces, accessFlags));
	try {
		$Class* pc = $nc(Proxy$ProxyBuilder::JLA)->defineClass(loader, proxyName, proxyClassFile, nullptr, "__dynamic_proxy__"_s);
		$init($Boolean);
		$nc($($nc(Proxy$ProxyBuilder::reverseProxyCache)->sub(pc)))->putIfAbsent(loader, $Boolean::TRUE);
		return pc;
	} catch ($ClassFormatError& e) {
		$throwNew($IllegalArgumentException, $(e->toString()));
	}
	$shouldNotReachHere();
}

bool Proxy$ProxyBuilder::isProxyClass($Class* c) {
	$init(Proxy$ProxyBuilder);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$init($Boolean);
	return $Objects::equals($($nc($($nc(Proxy$ProxyBuilder::reverseProxyCache)->sub(c)))->get($($nc(c)->getClassLoader()))), $Boolean::TRUE);
}

bool Proxy$ProxyBuilder::isExportedType($Class* c) {
	$init(Proxy$ProxyBuilder);
	$useLocalCurrentObjectStackCache();
	$var($String, pn, $nc(c)->getPackageName());
	bool var$0 = $Modifier::isPublic(c->getModifiers());
	return var$0 && $nc($(c->getModule()))->isExported(pn);
}

bool Proxy$ProxyBuilder::isPackagePrivateType($Class* c) {
	$init(Proxy$ProxyBuilder);
	return !$Modifier::isPublic($nc(c)->getModifiers());
}

$String* Proxy$ProxyBuilder::toDetails($Class* c) {
	$init(Proxy$ProxyBuilder);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($String, access, "unknown"_s);
	if (isExportedType(c)) {
		$assign(access, "exported"_s);
	} else if (isPackagePrivateType(c)) {
		$assign(access, "package-private"_s);
	} else {
		$assign(access, "module-private"_s);
	}
	$var($ClassLoader, ld, $nc(c)->getClassLoader());
	return $String::format("   %s/%s %s loader %s"_s, $$new($ObjectArray, {
		$($of($nc($(c->getModule()))->getName())),
		$($of(c->getName())),
		$of(access),
		$of(ld)
	}));
}

void Proxy$ProxyBuilder::trace($String* cn, $Module* module, $ClassLoader* loader, $List* interfaces) {
	$init(Proxy$ProxyBuilder);
	$useLocalCurrentObjectStackCache();
	if (isDebug()) {
		$nc($System::err)->format("PROXY: %s/%s defined by %s%n"_s, $$new($ObjectArray, {
			$($of($nc(module)->getName())),
			$of(cn),
			$of(loader)
		}));
	}
	if (isDebug("debug"_s)) {
		$nc(interfaces)->forEach(static_cast<$Consumer*>($$new(Proxy$ProxyBuilder$$Lambda$lambda$trace$0)));
	}
}

bool Proxy$ProxyBuilder::isDebug() {
	$init(Proxy$ProxyBuilder);
	return !$nc(Proxy$ProxyBuilder::DEBUG)->isEmpty();
}

bool Proxy$ProxyBuilder::isDebug($String* flag) {
	$init(Proxy$ProxyBuilder);
	return $nc(Proxy$ProxyBuilder::DEBUG)->equals(flag);
}

void Proxy$ProxyBuilder::init$($ClassLoader* loader, $List* interfaces) {
	$useLocalCurrentObjectStackCache();
	if (!$VM::isModuleSystemInited()) {
		$throwNew($InternalError, "Proxy is not supported until module system is fully initialized"_s);
	}
	if ($nc(interfaces)->size() > 0x0000FFFF) {
		$throwNew($IllegalArgumentException, $$str({"interface limit exceeded: "_s, $$str(interfaces->size())}));
	}
	$var($Set, refTypes, referencedTypes(loader, interfaces));
	validateProxyInterfaces(loader, interfaces, refTypes);
	$set(this, interfaces, interfaces);
	$set(this, module, mapToModule(loader, interfaces, refTypes));
	if (!Proxy$ProxyBuilder::$assertionsDisabled && !($Proxy::getLoader(this->module) == loader)) {
		$throwNew($AssertionError);
	}
}

void Proxy$ProxyBuilder::init$($ClassLoader* loader, $Class* intf) {
	Proxy$ProxyBuilder::init$(loader, $($Collections::singletonList(intf)));
}

$Constructor* Proxy$ProxyBuilder::build() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$Class* proxyClass = defineProxyClass(this->module, this->interfaces);
	bool var$0 = !Proxy$ProxyBuilder::$assertionsDisabled;
	if (var$0) {
		bool var$1 = !$nc(this->module)->isNamed();
		if (!var$1) {
			$var($String, var$2, $nc(proxyClass)->getPackageName());
			$load($Proxy);
			var$1 = $nc(this->module)->isOpen(var$2, $($Proxy::class$->getModule()));
		}
		var$0 = !var$1;
	}
	if (var$0) {
		$throwNew($AssertionError);
	}
	$var($Constructor, cons, nullptr);
	try {
		$init($Proxy);
		$assign(cons, $nc(proxyClass)->getConstructor($Proxy::constructorParams));
	} catch ($NoSuchMethodException& e) {
		$throwNew($InternalError, $(e->toString()), e);
	}
	$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($Proxy$ProxyBuilder$1, this, cons)));
	return cons;
}

void Proxy$ProxyBuilder::validateProxyInterfaces($ClassLoader* loader, $List* interfaces, $Set* refTypes) {
	$init(Proxy$ProxyBuilder);
	$useLocalCurrentObjectStackCache();
	$var($Map, interfaceSet, $new($IdentityHashMap, $nc(interfaces)->size()));
	{
		$var($Iterator, i$, $nc(interfaces)->iterator());
		for (; $nc(i$)->hasNext();) {
			$Class* intf = $cast($Class, i$->next());
			{
				if (!$nc(intf)->isInterface()) {
					$throwNew($IllegalArgumentException, $$str({$(intf->getName()), " is not an interface"_s}));
				}
				if ($nc(intf)->isHidden()) {
					$throwNew($IllegalArgumentException, $$str({$(intf->getName()), " is a hidden interface"_s}));
				}
				if ($nc(intf)->isSealed()) {
					$throwNew($IllegalArgumentException, $$str({$(intf->getName()), " is a sealed interface"_s}));
				}
				ensureVisible(loader, intf);
				$init($Boolean);
				if (interfaceSet->put(intf, $Boolean::TRUE) != nullptr) {
					$throwNew($IllegalArgumentException, $$str({"repeated interface: "_s, $($nc(intf)->getName())}));
				}
			}
		}
	}
	{
		$var($Iterator, i$, $nc(refTypes)->iterator());
		for (; $nc(i$)->hasNext();) {
			$Class* type = $cast($Class, i$->next());
			{
				ensureVisible(loader, type);
			}
		}
	}
}

$Set* Proxy$ProxyBuilder::referencedTypes($ClassLoader* loader, $List* interfaces) {
	$init(Proxy$ProxyBuilder);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($HashSet, types, $new($HashSet));
	{
		$var($Iterator, i$, $nc(interfaces)->iterator());
		for (; $nc(i$)->hasNext();) {
			$Class* intf = $cast($Class, i$->next());
			{
				{
					$var($MethodArray, arr$, $nc(intf)->getMethods());
					int32_t len$ = $nc(arr$)->length;
					int32_t i$ = 0;
					for (; i$ < len$; ++i$) {
						$var($Method, m, arr$->get(i$));
						{
							if (!$Modifier::isStatic($nc(m)->getModifiers())) {
								addElementType(types, $nc(m)->getReturnType());
								addElementTypes(types, $($nc(m)->getSharedParameterTypes()));
								addElementTypes(types, $($nc(m)->getSharedExceptionTypes()));
							}
						}
					}
				}
			}
		}
	}
	return types;
}

void Proxy$ProxyBuilder::addElementTypes($HashSet* types, $ClassArray* classes) {
	$init(Proxy$ProxyBuilder);
	{
		$var($ClassArray, arr$, classes);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$Class* cls = arr$->get(i$);
			{
				addElementType(types, cls);
			}
		}
	}
}

void Proxy$ProxyBuilder::addElementType($HashSet* types, $Class* cls) {
	$init(Proxy$ProxyBuilder);
	$Class* type = getElementType(cls);
	if (!$nc(type)->isPrimitive()) {
		$nc(types)->add(type);
	}
}

$Module* Proxy$ProxyBuilder::mapToModule($ClassLoader* loader, $List* interfaces, $Set* refTypes) {
	$init(Proxy$ProxyBuilder);
	$useLocalCurrentObjectStackCache();
	$var($Map, packagePrivateTypes, $new($HashMap));
	{
		$var($Iterator, i$, $nc(interfaces)->iterator());
		for (; $nc(i$)->hasNext();) {
			$Class* intf = $cast($Class, i$->next());
			{
				$var($Module, m, $nc(intf)->getModule());
				if (!$Modifier::isPublic(intf->getModifiers())) {
					packagePrivateTypes->put(intf, m);
				}
			}
		}
	}
	if (packagePrivateTypes->size() > 0) {
		$var($Module, targetModule, nullptr);
		$var($String, targetPackageName, nullptr);
		{
			$var($Iterator, i$, $nc($(packagePrivateTypes->entrySet()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
				{
					$Class* intf = $cast($Class, $nc(e)->getKey());
					$var($Module, m, $cast($Module, e->getValue()));
					if ((targetModule != nullptr && targetModule != m) || (targetPackageName != nullptr && targetPackageName != $nc(intf)->getPackageName())) {
						$throwNew($IllegalArgumentException, "cannot have non-public interfaces in different packages"_s);
					}
					if ($Proxy::getLoader(m) != loader) {
						$throwNew($IllegalArgumentException, "non-public interface is not defined by the given loader"_s);
					}
					$assign(targetModule, m);
					$assign(targetPackageName, $nc(($cast($Class, $(e->getKey()))))->getPackageName());
				}
			}
		}
		{
			$var($Iterator, i$, interfaces->iterator());
			for (; $nc(i$)->hasNext();) {
				$Class* intf = $cast($Class, i$->next());
				{
					$var($Module, m, $nc(intf)->getModule());
					if (m == targetModule) {
						continue;
					}
					bool var$0 = !$nc(targetModule)->canRead(m);
					if (var$0 || !$nc(m)->isExported($(intf->getPackageName()), targetModule)) {
						$var($String, var$1, $$str({targetModule, " can\'t access "_s}));
						$throwNew($IllegalArgumentException, $$concat(var$1, $(intf->getName())));
					}
				}
			}
		}
		if ($nc(targetModule)->isNamed()) {
			$load($Proxy);
			$Modules::addOpens(targetModule, targetPackageName, $($Proxy::class$->getModule()));
		}
		return targetModule;
	}
	$var($Module, targetModule, getDynamicModule(loader));
	$var($Set, types, $new($HashSet, static_cast<$Collection*>(interfaces)));
	types->addAll(refTypes);
	{
		$var($Iterator, i$, types->iterator());
		for (; $nc(i$)->hasNext();) {
			$Class* c = $cast($Class, i$->next());
			{
				ensureAccess(targetModule, c);
			}
		}
	}
	return targetModule;
}

void Proxy$ProxyBuilder::ensureAccess($Module* target, $Class* c) {
	$init(Proxy$ProxyBuilder);
	$useLocalCurrentObjectStackCache();
	$var($Module, m, $nc(c)->getModule());
	if (!$nc(target)->canRead(m)) {
		$Modules::addReads(target, m);
	}
	$var($String, pn, c->getPackageName());
	if (!$nc(m)->isExported(pn, target)) {
		$Modules::addExports(m, pn, target);
	}
}

void Proxy$ProxyBuilder::ensureVisible($ClassLoader* ld, $Class* c) {
	$init(Proxy$ProxyBuilder);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$Class* type = nullptr;
	try {
		type = $Class::forName($($nc(c)->getName()), false, ld);
	} catch ($ClassNotFoundException& e) {
	}
	if (type != c) {
		$throwNew($IllegalArgumentException, $$str({$($nc(c)->getName()), " referenced from a method is not visible from class loader"_s}));
	}
}

$Class* Proxy$ProxyBuilder::getElementType($Class* type) {
	$init(Proxy$ProxyBuilder);
	$Class* e = type;
	while ($nc(e)->isArray()) {
		e = e->getComponentType();
	}
	return e;
}

$Module* Proxy$ProxyBuilder::getDynamicModule($ClassLoader* loader) {
	$init(Proxy$ProxyBuilder);
	return $cast($Module, $nc(Proxy$ProxyBuilder::dynProxyModules)->computeIfAbsent(loader, static_cast<$BiFunction*>($$new(Proxy$ProxyBuilder$$Lambda$lambda$getDynamicModule$1$1))));
}

$Module* Proxy$ProxyBuilder::lambda$getDynamicModule$1($ClassLoader* ld, $ClassLoaderValue* clv) {
	$init(Proxy$ProxyBuilder);
	$useLocalCurrentObjectStackCache();
	$var($String, mn, $str({"jdk.proxy"_s, $$str($nc(Proxy$ProxyBuilder::counter)->incrementAndGet())}));
	$var($String, pn, $str({"com.sun.proxy"_s, "."_s, mn}));
	$init($ModuleDescriptor$Modifier);
	$var($ModuleDescriptor, descriptor, $nc($($nc($($nc($($ModuleDescriptor::newModule(mn, $($Set::of($of($ModuleDescriptor$Modifier::SYNTHETIC))))))->packages($($Set::of(pn, mn)))))->exports(mn)))->build());
	$var($Module, m, $Modules::defineModule(ld, descriptor, nullptr));
	$load($Proxy);
	$Modules::addReads(m, $($Proxy::class$->getModule()));
	$Modules::addExports(m, mn);
	$Modules::addOpens(m, pn, $($Proxy::class$->getModule()));
	$Modules::addOpens(m, mn, $($Proxy::class$->getModule()));
	return m;
}

void Proxy$ProxyBuilder::lambda$trace$0($Class* c) {
	$init(Proxy$ProxyBuilder);
	$nc($System::out)->println($(toDetails(c)));
}

void clinit$Proxy$ProxyBuilder($Class* class$) {
	$assignStatic(Proxy$ProxyBuilder::proxyClassNamePrefix, "$Proxy"_s);
	$load($Proxy);
	Proxy$ProxyBuilder::$assertionsDisabled = !$Proxy::class$->desiredAssertionStatus();
	$assignStatic(Proxy$ProxyBuilder::JLA, $SharedSecrets::getJavaLangAccess());
	$assignStatic(Proxy$ProxyBuilder::nextUniqueNumber, $new($AtomicLong));
	$assignStatic(Proxy$ProxyBuilder::reverseProxyCache, $new($ClassLoaderValue));
	$assignStatic(Proxy$ProxyBuilder::DEBUG, $GetPropertyAction::privilegedGetProperty("jdk.proxy.debug"_s, ""_s));
	$assignStatic(Proxy$ProxyBuilder::dynProxyModules, $new($ClassLoaderValue));
	$assignStatic(Proxy$ProxyBuilder::counter, $new($AtomicInteger));
}

Proxy$ProxyBuilder::Proxy$ProxyBuilder() {
}

$Class* Proxy$ProxyBuilder::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Proxy$ProxyBuilder$$Lambda$lambda$trace$0::classInfo$.name)) {
			return Proxy$ProxyBuilder$$Lambda$lambda$trace$0::load$(name, initialize);
		}
		if (name->equals(Proxy$ProxyBuilder$$Lambda$lambda$getDynamicModule$1$1::classInfo$.name)) {
			return Proxy$ProxyBuilder$$Lambda$lambda$getDynamicModule$1$1::load$(name, initialize);
		}
	}
	$loadClass(Proxy$ProxyBuilder, name, initialize, &_Proxy$ProxyBuilder_ClassInfo_, clinit$Proxy$ProxyBuilder, allocate$Proxy$ProxyBuilder);
	return class$;
}

$Class* Proxy$ProxyBuilder::class$ = nullptr;

		} // reflect
	} // lang
} // java