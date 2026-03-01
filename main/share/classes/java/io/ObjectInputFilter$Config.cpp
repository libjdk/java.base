#include <java/io/ObjectInputFilter$Config.h>

#include <java/io/ObjectInputFilter$Config$BuiltinFilterFactory.h>
#include <java/io/ObjectInputFilter$Config$Global.h>
#include <java/io/ObjectInputFilter.h>
#include <java/io/ObjectStreamConstants.h>
#include <java/io/Serializable.h>
#include <java/io/SerializablePermission.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/ExceptionInInitializerError.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/InstantiationException.h>
#include <java/lang/NoSuchMethodException.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/System$Logger$Level.h>
#include <java/lang/System$Logger.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/InvocationTargetException.h>
#include <java/security/AccessController.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/Security.h>
#include <java/util/Objects.h>
#include <java/util/concurrent/atomic/AtomicBoolean.h>
#include <java/util/function/BinaryOperator.h>
#include <jdk/internal/access/JavaObjectInputFilterAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jdk/internal/util/StaticProperty.h>
#include <jcpp.h>

#undef DEBUG
#undef ERROR
#undef SERIAL_FILTER_FACTORY_PROPNAME
#undef SERIAL_FILTER_PERMISSION
#undef SERIAL_FILTER_PROPNAME
#undef TRACE

using $ObjectInputFilter = ::java::io::ObjectInputFilter;
using $ObjectInputFilter$Config$BuiltinFilterFactory = ::java::io::ObjectInputFilter$Config$BuiltinFilterFactory;
using $ObjectInputFilter$Config$Global = ::java::io::ObjectInputFilter$Config$Global;
using $ObjectStreamConstants = ::java::io::ObjectStreamConstants;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $ExceptionInInitializerError = ::java::lang::ExceptionInInitializerError;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InstantiationException = ::java::lang::InstantiationException;
using $MethodInfo = ::java::lang::MethodInfo;
using $NoSuchMethodException = ::java::lang::NoSuchMethodException;
using $RuntimeException = ::java::lang::RuntimeException;
using $SecurityManager = ::java::lang::SecurityManager;
using $System$Logger = ::java::lang::System$Logger;
using $System$Logger$Level = ::java::lang::System$Logger$Level;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Constructor = ::java::lang::reflect::Constructor;
using $InvocationTargetException = ::java::lang::reflect::InvocationTargetException;
using $AccessController = ::java::security::AccessController;
using $Permission = ::java::security::Permission;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Security = ::java::security::Security;
using $Objects = ::java::util::Objects;
using $AtomicBoolean = ::java::util::concurrent::atomic::AtomicBoolean;
using $BinaryOperator = ::java::util::function::BinaryOperator;
using $JavaObjectInputFilterAccess = ::jdk::internal::access::JavaObjectInputFilterAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $StaticProperty = ::jdk::internal::util::StaticProperty;

namespace java {
	namespace io {

class ObjectInputFilter$Config$$Lambda$lambda$static$0 : public $PrivilegedAction {
	$class(ObjectInputFilter$Config$$Lambda$lambda$static$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(ObjectInputFilter$Config::lambda$static$0());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ObjectInputFilter$Config$$Lambda$lambda$static$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ObjectInputFilter$Config$$Lambda$lambda$static$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ObjectInputFilter$Config$$Lambda$lambda$static$0, init$, void)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ObjectInputFilter$Config$$Lambda$lambda$static$0, run, $Object*)},
	{}
};
$ClassInfo ObjectInputFilter$Config$$Lambda$lambda$static$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.io.ObjectInputFilter$Config$$Lambda$lambda$static$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* ObjectInputFilter$Config$$Lambda$lambda$static$0::load$($String* name, bool initialize) {
	$loadClass(ObjectInputFilter$Config$$Lambda$lambda$static$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ObjectInputFilter$Config$$Lambda$lambda$static$0::class$ = nullptr;

class ObjectInputFilter$Config$$Lambda$lambda$static$1$1 : public $PrivilegedAction {
	$class(ObjectInputFilter$Config$$Lambda$lambda$static$1$1, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(ObjectInputFilter$Config::lambda$static$1());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ObjectInputFilter$Config$$Lambda$lambda$static$1$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ObjectInputFilter$Config$$Lambda$lambda$static$1$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ObjectInputFilter$Config$$Lambda$lambda$static$1$1, init$, void)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ObjectInputFilter$Config$$Lambda$lambda$static$1$1, run, $Object*)},
	{}
};
$ClassInfo ObjectInputFilter$Config$$Lambda$lambda$static$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.io.ObjectInputFilter$Config$$Lambda$lambda$static$1$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* ObjectInputFilter$Config$$Lambda$lambda$static$1$1::load$($String* name, bool initialize) {
	$loadClass(ObjectInputFilter$Config$$Lambda$lambda$static$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ObjectInputFilter$Config$$Lambda$lambda$static$1$1::class$ = nullptr;

class ObjectInputFilter$Config$$Lambda$createFilter2$2 : public $JavaObjectInputFilterAccess {
	$class(ObjectInputFilter$Config$$Lambda$createFilter2$2, $NO_CLASS_INIT, $JavaObjectInputFilterAccess)
public:
	void init$() {
	}
	virtual $ObjectInputFilter* createFilter2($String* pattern) override {
		 return ObjectInputFilter$Config::createFilter2(pattern);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ObjectInputFilter$Config$$Lambda$createFilter2$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ObjectInputFilter$Config$$Lambda$createFilter2$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ObjectInputFilter$Config$$Lambda$createFilter2$2, init$, void)},
	{"createFilter2", "(Ljava/lang/String;)Ljava/io/ObjectInputFilter;", nullptr, $PUBLIC, $virtualMethod(ObjectInputFilter$Config$$Lambda$createFilter2$2, createFilter2, $ObjectInputFilter*, $String*)},
	{}
};
$ClassInfo ObjectInputFilter$Config$$Lambda$createFilter2$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.io.ObjectInputFilter$Config$$Lambda$createFilter2$2",
	"java.lang.Object",
	"jdk.internal.access.JavaObjectInputFilterAccess",
	nullptr,
	methodInfos
};
$Class* ObjectInputFilter$Config$$Lambda$createFilter2$2::load$($String* name, bool initialize) {
	$loadClass(ObjectInputFilter$Config$$Lambda$createFilter2$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ObjectInputFilter$Config$$Lambda$createFilter2$2::class$ = nullptr;

$FieldInfo _ObjectInputFilter$Config_FieldInfo_[] = {
	{"serialFilterLock", "Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ObjectInputFilter$Config, serialFilterLock)},
	{"SERIAL_FILTER_PROPNAME", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ObjectInputFilter$Config, SERIAL_FILTER_PROPNAME)},
	{"SERIAL_FILTER_FACTORY_PROPNAME", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ObjectInputFilter$Config, SERIAL_FILTER_FACTORY_PROPNAME)},
	{"serialFilter", "Ljava/io/ObjectInputFilter;", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(ObjectInputFilter$Config, serialFilter)},
	{"serialFilterFactory", "Ljava/util/function/BinaryOperator;", "Ljava/util/function/BinaryOperator<Ljava/io/ObjectInputFilter;>;", $PRIVATE | $STATIC | $VOLATILE, $staticField(ObjectInputFilter$Config, serialFilterFactory)},
	{"filterFactoryNoReplace", "Ljava/util/concurrent/atomic/AtomicBoolean;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ObjectInputFilter$Config, filterFactoryNoReplace)},
	{"configLog", "Ljava/lang/System$Logger;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ObjectInputFilter$Config, configLog)},
	{}
};

$MethodInfo _ObjectInputFilter$Config_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(ObjectInputFilter$Config, init$, void)},
	{"createFilter", "(Ljava/lang/String;)Ljava/io/ObjectInputFilter;", nullptr, $PUBLIC | $STATIC, $staticMethod(ObjectInputFilter$Config, createFilter, $ObjectInputFilter*, $String*)},
	{"createFilter2", "(Ljava/lang/String;)Ljava/io/ObjectInputFilter;", nullptr, $STATIC, $staticMethod(ObjectInputFilter$Config, createFilter2, $ObjectInputFilter*, $String*)},
	{"getSerialFilter", "()Ljava/io/ObjectInputFilter;", nullptr, $PUBLIC | $STATIC, $staticMethod(ObjectInputFilter$Config, getSerialFilter, $ObjectInputFilter*)},
	{"getSerialFilterFactory", "()Ljava/util/function/BinaryOperator;", "()Ljava/util/function/BinaryOperator<Ljava/io/ObjectInputFilter;>;", $PUBLIC | $STATIC, $staticMethod(ObjectInputFilter$Config, getSerialFilterFactory, $BinaryOperator*)},
	{"getSerialFilterFactorySingleton", "()Ljava/util/function/BinaryOperator;", "()Ljava/util/function/BinaryOperator<Ljava/io/ObjectInputFilter;>;", $STATIC, $staticMethod(ObjectInputFilter$Config, getSerialFilterFactorySingleton, $BinaryOperator*)},
	{"lambda$static$0", "()Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ObjectInputFilter$Config, lambda$static$0, $String*)},
	{"lambda$static$1", "()Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ObjectInputFilter$Config, lambda$static$1, $String*)},
	{"setSerialFilter", "(Ljava/io/ObjectInputFilter;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(ObjectInputFilter$Config, setSerialFilter, void, $ObjectInputFilter*)},
	{"setSerialFilterFactory", "(Ljava/util/function/BinaryOperator;)V", "(Ljava/util/function/BinaryOperator<Ljava/io/ObjectInputFilter;>;)V", $PUBLIC | $STATIC, $staticMethod(ObjectInputFilter$Config, setSerialFilterFactory, void, $BinaryOperator*)},
	{"traceFilter", "(Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PRIVATE | $STATIC | $TRANSIENT, $staticMethod(ObjectInputFilter$Config, traceFilter, void, $String*, $ObjectArray*)},
	{}
};

$InnerClassInfo _ObjectInputFilter$Config_InnerClassesInfo_[] = {
	{"java.io.ObjectInputFilter$Config", "java.io.ObjectInputFilter", "Config", $PUBLIC | $STATIC | $FINAL},
	{"java.io.ObjectInputFilter$Config$BuiltinFilterFactory", "java.io.ObjectInputFilter$Config", "BuiltinFilterFactory", $PRIVATE | $STATIC | $FINAL},
	{"java.io.ObjectInputFilter$Config$RejectUndecidedFilter", "java.io.ObjectInputFilter$Config", "RejectUndecidedFilter", $PRIVATE | $STATIC},
	{"java.io.ObjectInputFilter$Config$MergeFilter", "java.io.ObjectInputFilter$Config", "MergeFilter", $PRIVATE | $STATIC},
	{"java.io.ObjectInputFilter$Config$PredicateFilter", "java.io.ObjectInputFilter$Config", "PredicateFilter", $PRIVATE | $STATIC},
	{"java.io.ObjectInputFilter$Config$Global", "java.io.ObjectInputFilter$Config", "Global", $STATIC | $FINAL},
	{}
};

$ClassInfo _ObjectInputFilter$Config_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.io.ObjectInputFilter$Config",
	"java.lang.Object",
	nullptr,
	_ObjectInputFilter$Config_FieldInfo_,
	_ObjectInputFilter$Config_MethodInfo_,
	nullptr,
	nullptr,
	_ObjectInputFilter$Config_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.io.ObjectInputFilter"
};

$Object* allocate$ObjectInputFilter$Config($Class* clazz) {
	return $of($alloc(ObjectInputFilter$Config));
}

$Object* ObjectInputFilter$Config::serialFilterLock = nullptr;
$String* ObjectInputFilter$Config::SERIAL_FILTER_PROPNAME = nullptr;
$String* ObjectInputFilter$Config::SERIAL_FILTER_FACTORY_PROPNAME = nullptr;
$volatile($ObjectInputFilter*) ObjectInputFilter$Config::serialFilter = nullptr;
$volatile($BinaryOperator*) ObjectInputFilter$Config::serialFilterFactory = nullptr;
$AtomicBoolean* ObjectInputFilter$Config::filterFactoryNoReplace = nullptr;
$System$Logger* ObjectInputFilter$Config::configLog = nullptr;

void ObjectInputFilter$Config::init$() {
}

void ObjectInputFilter$Config::traceFilter($String* msg, $ObjectArray* args) {
	$init(ObjectInputFilter$Config);
	$init($System$Logger$Level);
	$nc(ObjectInputFilter$Config::configLog)->log($System$Logger$Level::TRACE, msg, args);
}

$ObjectInputFilter* ObjectInputFilter$Config::getSerialFilter() {
	$init(ObjectInputFilter$Config);
	return ObjectInputFilter$Config::serialFilter;
}

void ObjectInputFilter$Config::setSerialFilter($ObjectInputFilter* filter) {
	$init(ObjectInputFilter$Config);
	$Objects::requireNonNull($of(filter), "filter"_s);
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		$init($ObjectStreamConstants);
		sm->checkPermission($ObjectStreamConstants::SERIAL_FILTER_PERMISSION);
	}
	$synchronized(ObjectInputFilter$Config::serialFilterLock) {
		if (ObjectInputFilter$Config::serialFilter != nullptr) {
			$throwNew($IllegalStateException, "Serial filter can only be set once"_s);
		}
		$assignStatic(ObjectInputFilter$Config::serialFilter, filter);
	}
}

$BinaryOperator* ObjectInputFilter$Config::getSerialFilterFactory() {
	$init(ObjectInputFilter$Config);
	if (ObjectInputFilter$Config::serialFilterFactory == nullptr) {
		$throwNew($IllegalStateException, "Serial filter factory initialization incomplete"_s);
	}
	return ObjectInputFilter$Config::serialFilterFactory;
}

$BinaryOperator* ObjectInputFilter$Config::getSerialFilterFactorySingleton() {
	$init(ObjectInputFilter$Config);
	$nc(ObjectInputFilter$Config::filterFactoryNoReplace)->set(true);
	return getSerialFilterFactory();
}

void ObjectInputFilter$Config::setSerialFilterFactory($BinaryOperator* filterFactory) {
	$init(ObjectInputFilter$Config);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(filterFactory), "filterFactory"_s);
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		$init($ObjectStreamConstants);
		sm->checkPermission($ObjectStreamConstants::SERIAL_FILTER_PERMISSION);
	}
	if ($nc(ObjectInputFilter$Config::filterFactoryNoReplace)->getAndSet(true)) {
		$var($String, msg, ObjectInputFilter$Config::serialFilterFactory != nullptr ? $nc($of(ObjectInputFilter$Config::serialFilterFactory))->getClass()->getName() : "initialization incomplete"_s);
		$throwNew($IllegalStateException, $$str({"Cannot replace filter factory: "_s, msg}));
	}
	$init($System$Logger$Level);
	$nc(ObjectInputFilter$Config::configLog)->log($System$Logger$Level::DEBUG, "Setting deserialization filter factory to {0}"_s, $$new($ObjectArray, {$($of($nc($of(filterFactory))->getClass()->getName()))}));
	$assignStatic(ObjectInputFilter$Config::serialFilterFactory, filterFactory);
}

$ObjectInputFilter* ObjectInputFilter$Config::createFilter($String* pattern) {
	$init(ObjectInputFilter$Config);
	$Objects::requireNonNull($of(pattern), "pattern"_s);
	return $ObjectInputFilter$Config$Global::createFilter(pattern, true);
}

$ObjectInputFilter* ObjectInputFilter$Config::createFilter2($String* pattern) {
	$init(ObjectInputFilter$Config);
	$Objects::requireNonNull($of(pattern), "pattern"_s);
	return $ObjectInputFilter$Config$Global::createFilter(pattern, false);
}

$String* ObjectInputFilter$Config::lambda$static$1() {
	$init(ObjectInputFilter$Config);
	return $Security::getProperty(ObjectInputFilter$Config::SERIAL_FILTER_PROPNAME);
}

$String* ObjectInputFilter$Config::lambda$static$0() {
	$init(ObjectInputFilter$Config);
	return $Security::getProperty(ObjectInputFilter$Config::SERIAL_FILTER_FACTORY_PROPNAME);
}

void clinit$ObjectInputFilter$Config($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(ObjectInputFilter$Config::SERIAL_FILTER_PROPNAME, "jdk.serialFilter"_s);
	$assignStatic(ObjectInputFilter$Config::SERIAL_FILTER_FACTORY_PROPNAME, "jdk.serialFilterFactory"_s);
	$beforeCallerSensitive();
	$assignStatic(ObjectInputFilter$Config::serialFilterLock, $new($Object));
	$assignStatic(ObjectInputFilter$Config::filterFactoryNoReplace, $new($AtomicBoolean));
	{
		$assignStatic(ObjectInputFilter$Config::configLog, $System::getLogger("java.io.serialization"_s));
		$var($String, factoryClassName, $StaticProperty::jdkSerialFilterFactory());
		if (factoryClassName == nullptr) {
			$assign(factoryClassName, $cast($String, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(ObjectInputFilter$Config$$Lambda$lambda$static$0)))));
		}
		$var($String, filterString, $StaticProperty::jdkSerialFilter());
		if (filterString == nullptr) {
			$assign(filterString, $cast($String, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(ObjectInputFilter$Config$$Lambda$lambda$static$1$1)))));
		}
		$var($ObjectInputFilter, filter, nullptr);
		if (filterString != nullptr) {
			$init($System$Logger$Level);
			$nc(ObjectInputFilter$Config::configLog)->log($System$Logger$Level::DEBUG, "Creating deserialization filter from {0}"_s, $$new($ObjectArray, {$of(filterString)}));
			try {
				$assign(filter, ObjectInputFilter$Config::createFilter(filterString));
			} catch ($RuntimeException& re) {
				$nc(ObjectInputFilter$Config::configLog)->log($System$Logger$Level::ERROR, "Error configuring filter: {0}"_s, static_cast<$Throwable*>(re));
			}
		}
		$assignStatic(ObjectInputFilter$Config::serialFilter, filter);
		if (factoryClassName == nullptr) {
			$assignStatic(ObjectInputFilter$Config::serialFilterFactory, $new($ObjectInputFilter$Config$BuiltinFilterFactory));
		} else {
			try {
				$nc(ObjectInputFilter$Config::filterFactoryNoReplace)->set(true);
				$Class* factoryClass = $Class::forName(factoryClassName, true, $($ClassLoader::getSystemClassLoader()));
				$var($BinaryOperator, factory, $cast($BinaryOperator, $nc($($nc(factoryClass)->getConstructor($$new($ClassArray, 0))))->newInstance($$new($ObjectArray, 0))));
				$init($System$Logger$Level);
				$nc(ObjectInputFilter$Config::configLog)->log($System$Logger$Level::DEBUG, "Creating deserialization filter factory for {0}"_s, $$new($ObjectArray, {$of(factoryClassName)}));
				$assignStatic(ObjectInputFilter$Config::serialFilterFactory, factory);
			} catch ($RuntimeException& ex) {
				$var($InvocationTargetException, ite, nullptr);
				bool var$0 = $instanceOf($InvocationTargetException, ex);
				if (var$0) {
					$assign(ite, $cast($InvocationTargetException, ex));
					var$0 = true;
				}
				$var($Throwable, th, (var$0) ? $nc(ite)->getCause() : static_cast<$Throwable*>(ex));
				$init($System$Logger$Level);
				$nc(ObjectInputFilter$Config::configLog)->log($System$Logger$Level::ERROR, "Error configuring filter factory: {0}"_s, $$new($ObjectArray, {$of(th)}));
				$throwNew($ExceptionInInitializerError, th);
			} catch ($ClassNotFoundException& ex) {
				$var($InvocationTargetException, ite, nullptr);
				bool var$1 = $instanceOf($InvocationTargetException, ex);
				if (var$1) {
					$assign(ite, $cast($InvocationTargetException, ex));
					var$1 = true;
				}
				$var($Throwable, th, (var$1) ? $nc(ite)->getCause() : static_cast<$Throwable*>(ex));
				$init($System$Logger$Level);
				$nc(ObjectInputFilter$Config::configLog)->log($System$Logger$Level::ERROR, "Error configuring filter factory: {0}"_s, $$new($ObjectArray, {$of(th)}));
				$throwNew($ExceptionInInitializerError, th);
			} catch ($NoSuchMethodException& ex) {
				$var($InvocationTargetException, ite, nullptr);
				bool var$2 = $instanceOf($InvocationTargetException, ex);
				if (var$2) {
					$assign(ite, $cast($InvocationTargetException, ex));
					var$2 = true;
				}
				$var($Throwable, th, (var$2) ? $nc(ite)->getCause() : static_cast<$Throwable*>(ex));
				$init($System$Logger$Level);
				$nc(ObjectInputFilter$Config::configLog)->log($System$Logger$Level::ERROR, "Error configuring filter factory: {0}"_s, $$new($ObjectArray, {$of(th)}));
				$throwNew($ExceptionInInitializerError, th);
			} catch ($IllegalAccessException& ex) {
				$var($InvocationTargetException, ite, nullptr);
				bool var$3 = $instanceOf($InvocationTargetException, ex);
				if (var$3) {
					$assign(ite, $cast($InvocationTargetException, ex));
					var$3 = true;
				}
				$var($Throwable, th, (var$3) ? $nc(ite)->getCause() : static_cast<$Throwable*>(ex));
				$init($System$Logger$Level);
				$nc(ObjectInputFilter$Config::configLog)->log($System$Logger$Level::ERROR, "Error configuring filter factory: {0}"_s, $$new($ObjectArray, {$of(th)}));
				$throwNew($ExceptionInInitializerError, th);
			} catch ($InstantiationException& ex) {
				$var($InvocationTargetException, ite, nullptr);
				bool var$4 = $instanceOf($InvocationTargetException, ex);
				if (var$4) {
					$assign(ite, $cast($InvocationTargetException, ex));
					var$4 = true;
				}
				$var($Throwable, th, (var$4) ? $nc(ite)->getCause() : static_cast<$Throwable*>(ex));
				$init($System$Logger$Level);
				$nc(ObjectInputFilter$Config::configLog)->log($System$Logger$Level::ERROR, "Error configuring filter factory: {0}"_s, $$new($ObjectArray, {$of(th)}));
				$throwNew($ExceptionInInitializerError, th);
			} catch ($InvocationTargetException& ex) {
				$var($InvocationTargetException, ite, nullptr);
				bool var$5 = $instanceOf($InvocationTargetException, ex);
				if (var$5) {
					$assign(ite, $cast($InvocationTargetException, ex));
					var$5 = true;
				}
				$var($Throwable, th, (var$5) ? $nc(ite)->getCause() : static_cast<$Throwable*>(ex));
				$init($System$Logger$Level);
				$nc(ObjectInputFilter$Config::configLog)->log($System$Logger$Level::ERROR, "Error configuring filter factory: {0}"_s, $$new($ObjectArray, {$of(th)}));
				$throwNew($ExceptionInInitializerError, th);
			}
		}
		$SharedSecrets::setJavaObjectInputFilterAccess(static_cast<$JavaObjectInputFilterAccess*>($$new(ObjectInputFilter$Config$$Lambda$createFilter2$2)));
	}
}

ObjectInputFilter$Config::ObjectInputFilter$Config() {
}

$Class* ObjectInputFilter$Config::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ObjectInputFilter$Config$$Lambda$lambda$static$0::classInfo$.name)) {
			return ObjectInputFilter$Config$$Lambda$lambda$static$0::load$(name, initialize);
		}
		if (name->equals(ObjectInputFilter$Config$$Lambda$lambda$static$1$1::classInfo$.name)) {
			return ObjectInputFilter$Config$$Lambda$lambda$static$1$1::load$(name, initialize);
		}
		if (name->equals(ObjectInputFilter$Config$$Lambda$createFilter2$2::classInfo$.name)) {
			return ObjectInputFilter$Config$$Lambda$createFilter2$2::load$(name, initialize);
		}
	}
	$loadClass(ObjectInputFilter$Config, name, initialize, &_ObjectInputFilter$Config_ClassInfo_, clinit$ObjectInputFilter$Config, allocate$ObjectInputFilter$Config);
	return class$;
}

$Class* ObjectInputFilter$Config::class$ = nullptr;

	} // io
} // java