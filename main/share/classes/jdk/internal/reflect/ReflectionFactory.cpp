#include <jdk/internal/reflect/ReflectionFactory.h>

#include <java/io/Externalizable.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream.h>
#include <java/io/ObjectStreamClass.h>
#include <java/io/OptionalDataException.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/InternalError.h>
#include <java/lang/NoSuchMethodException.h>
#include <java/lang/NumberFormatException.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/reflect/AccessibleObject.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Executable.h>
#include <java/lang/reflect/Field.h>
#include <java/lang/reflect/InvocationTargetException.h>
#include <java/lang/reflect/Method.h>
#include <java/lang/reflect/Modifier.h>
#include <java/security/Permission.h>
#include <java/util/Properties.h>
#include <jdk/internal/access/JavaLangReflectAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jdk/internal/misc/VM.h>
#include <jdk/internal/reflect/BootstrapConstructorAccessorImpl.h>
#include <jdk/internal/reflect/ConstructorAccessor.h>
#include <jdk/internal/reflect/ConstructorAccessorImpl.h>
#include <jdk/internal/reflect/DelegatingConstructorAccessorImpl.h>
#include <jdk/internal/reflect/DelegatingMethodAccessorImpl.h>
#include <jdk/internal/reflect/FieldAccessor.h>
#include <jdk/internal/reflect/InstantiationExceptionConstructorAccessorImpl.h>
#include <jdk/internal/reflect/MethodAccessor.h>
#include <jdk/internal/reflect/MethodAccessorGenerator.h>
#include <jdk/internal/reflect/NativeConstructorAccessorImpl.h>
#include <jdk/internal/reflect/NativeMethodAccessorImpl.h>
#include <jdk/internal/reflect/Reflection.h>
#include <jdk/internal/reflect/SerializationConstructorAccessorImpl.h>
#include <jdk/internal/reflect/UnsafeFieldAccessorFactory.h>
#include <sun/security/action/GetPropertyAction.h>
#include <sun/security/util/SecurityConstants.h>
#include <jcpp.h>

#undef PRIVATE
#undef PROTECTED
#undef PUBLIC
#undef REFLECTION_FACTORY_ACCESS_PERMISSION
#undef TYPE

using $ConstructorArray = $Array<::java::lang::reflect::Constructor>;
using $Externalizable = ::java::io::Externalizable;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $ObjectStreamClass = ::java::io::ObjectStreamClass;
using $OptionalDataException = ::java::io::OptionalDataException;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $NoSuchMethodException = ::java::lang::NoSuchMethodException;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $RuntimeException = ::java::lang::RuntimeException;
using $SecurityManager = ::java::lang::SecurityManager;
using $Void = ::java::lang::Void;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $AccessibleObject = ::java::lang::reflect::AccessibleObject;
using $Constructor = ::java::lang::reflect::Constructor;
using $Executable = ::java::lang::reflect::Executable;
using $Field = ::java::lang::reflect::Field;
using $InvocationTargetException = ::java::lang::reflect::InvocationTargetException;
using $Method = ::java::lang::reflect::Method;
using $Modifier = ::java::lang::reflect::Modifier;
using $Permission = ::java::security::Permission;
using $Properties = ::java::util::Properties;
using $JavaLangReflectAccess = ::jdk::internal::access::JavaLangReflectAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $VM = ::jdk::internal::misc::VM;
using $BootstrapConstructorAccessorImpl = ::jdk::internal::reflect::BootstrapConstructorAccessorImpl;
using $ConstructorAccessor = ::jdk::internal::reflect::ConstructorAccessor;
using $ConstructorAccessorImpl = ::jdk::internal::reflect::ConstructorAccessorImpl;
using $DelegatingConstructorAccessorImpl = ::jdk::internal::reflect::DelegatingConstructorAccessorImpl;
using $FieldAccessor = ::jdk::internal::reflect::FieldAccessor;
using $InstantiationExceptionConstructorAccessorImpl = ::jdk::internal::reflect::InstantiationExceptionConstructorAccessorImpl;
using $MethodAccessor = ::jdk::internal::reflect::MethodAccessor;
using $MethodAccessorGenerator = ::jdk::internal::reflect::MethodAccessorGenerator;
using $NativeConstructorAccessorImpl = ::jdk::internal::reflect::NativeConstructorAccessorImpl;
using $Reflection = ::jdk::internal::reflect::Reflection;
using $UnsafeFieldAccessorFactory = ::jdk::internal::reflect::UnsafeFieldAccessorFactory;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;
using $SecurityConstants = ::sun::security::util::SecurityConstants;

namespace jdk {
	namespace internal {
		namespace reflect {

$FieldInfo _ReflectionFactory_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(ReflectionFactory, $assertionsDisabled)},
	{"initted", "Z", nullptr, $PRIVATE | $STATIC, $staticField(ReflectionFactory, initted)},
	{"soleInstance", "Ljdk/internal/reflect/ReflectionFactory;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ReflectionFactory, soleInstance)},
	{"hasStaticInitializerMethod", "Ljava/lang/reflect/Method;", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(ReflectionFactory, hasStaticInitializerMethod)},
	{"noInflation", "Z", nullptr, $PRIVATE | $STATIC, $staticField(ReflectionFactory, noInflation)},
	{"inflationThreshold", "I", nullptr, $PRIVATE | $STATIC, $staticField(ReflectionFactory, inflationThreshold$)},
	{"disableSerialConstructorChecks", "Z", nullptr, $PRIVATE | $STATIC, $staticField(ReflectionFactory, disableSerialConstructorChecks)},
	{"langReflectAccess", "Ljdk/internal/access/JavaLangReflectAccess;", nullptr, $PRIVATE | $FINAL, $field(ReflectionFactory, langReflectAccess)},
	{}
};

$MethodInfo _ReflectionFactory_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(ReflectionFactory, init$, void)},
	{"checkInitted", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(ReflectionFactory, checkInitted, void)},
	{"copyConstructor", "(Ljava/lang/reflect/Constructor;)Ljava/lang/reflect/Constructor;", "<T:Ljava/lang/Object;>(Ljava/lang/reflect/Constructor<TT;>;)Ljava/lang/reflect/Constructor<TT;>;", $PUBLIC, $virtualMethod(ReflectionFactory, copyConstructor, $Constructor*, $Constructor*)},
	{"copyField", "(Ljava/lang/reflect/Field;)Ljava/lang/reflect/Field;", nullptr, $PUBLIC, $virtualMethod(ReflectionFactory, copyField, $Field*, $Field*)},
	{"copyMethod", "(Ljava/lang/reflect/Method;)Ljava/lang/reflect/Method;", nullptr, $PUBLIC, $virtualMethod(ReflectionFactory, copyMethod, $Method*, $Method*)},
	{"findMethodForReflection", "(Ljava/lang/reflect/Method;)Ljava/lang/reflect/Method;", nullptr, $PRIVATE | $STATIC, $staticMethod(ReflectionFactory, findMethodForReflection, $Method*, $Method*)},
	{"findReadWriteObjectForSerialization", "(Ljava/lang/Class;Ljava/lang/String;Ljava/lang/Class;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/Class<*>;Ljava/lang/String;Ljava/lang/Class<*>;)Ljava/lang/invoke/MethodHandle;", $PRIVATE | $FINAL, $method(ReflectionFactory, findReadWriteObjectForSerialization, $MethodHandle*, $Class*, $String*, $Class*)},
	{"generateConstructor", "(Ljava/lang/Class;Ljava/lang/reflect/Constructor;)Ljava/lang/reflect/Constructor;", "(Ljava/lang/Class<*>;Ljava/lang/reflect/Constructor<*>;)Ljava/lang/reflect/Constructor<*>;", $PRIVATE | $FINAL, $method(ReflectionFactory, generateConstructor, $Constructor*, $Class*, $Constructor*)},
	{"getConstructorAccessor", "(Ljava/lang/reflect/Constructor;)Ljdk/internal/reflect/ConstructorAccessor;", "(Ljava/lang/reflect/Constructor<*>;)Ljdk/internal/reflect/ConstructorAccessor;", $PUBLIC, $virtualMethod(ReflectionFactory, getConstructorAccessor, $ConstructorAccessor*, $Constructor*)},
	{"getExecutableSharedParameterTypes", "(Ljava/lang/reflect/Executable;)[Ljava/lang/Class;", "(Ljava/lang/reflect/Executable;)[Ljava/lang/Class<*>;", $PUBLIC, $virtualMethod(ReflectionFactory, getExecutableSharedParameterTypes, $ClassArray*, $Executable*)},
	{"getExecutableTypeAnnotationBytes", "(Ljava/lang/reflect/Executable;)[B", nullptr, $PUBLIC, $virtualMethod(ReflectionFactory, getExecutableTypeAnnotationBytes, $bytes*, $Executable*)},
	{"getReflectionFactory", "()Ljdk/internal/reflect/ReflectionFactory;", nullptr, $PUBLIC | $STATIC, $staticMethod(ReflectionFactory, getReflectionFactory, ReflectionFactory*)},
	{"getReplaceResolveForSerialization", "(Ljava/lang/Class;Ljava/lang/String;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/Class<*>;Ljava/lang/String;)Ljava/lang/invoke/MethodHandle;", $PRIVATE, $method(ReflectionFactory, getReplaceResolveForSerialization, $MethodHandle*, $Class*, $String*)},
	{"hasStaticInitializerForSerialization", "(Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;)Z", $PUBLIC | $FINAL, $method(ReflectionFactory, hasStaticInitializerForSerialization, bool, $Class*)},
	{"inflationThreshold", "()I", nullptr, $STATIC, $staticMethod(ReflectionFactory, inflationThreshold, int32_t)},
	{"leafCopyMethod", "(Ljava/lang/reflect/Method;)Ljava/lang/reflect/Method;", nullptr, $PUBLIC, $virtualMethod(ReflectionFactory, leafCopyMethod, $Method*, $Method*)},
	{"newConstructor", "(Ljava/lang/Class;[Ljava/lang/Class;[Ljava/lang/Class;IILjava/lang/String;[B[B)Ljava/lang/reflect/Constructor;", "(Ljava/lang/Class<*>;[Ljava/lang/Class<*>;[Ljava/lang/Class<*>;IILjava/lang/String;[B[B)Ljava/lang/reflect/Constructor<*>;", $PUBLIC, $virtualMethod(ReflectionFactory, newConstructor, $Constructor*, $Class*, $ClassArray*, $ClassArray*, int32_t, int32_t, $String*, $bytes*, $bytes*)},
	{"newConstructorAccessor", "(Ljava/lang/reflect/Constructor;)Ljdk/internal/reflect/ConstructorAccessor;", "(Ljava/lang/reflect/Constructor<*>;)Ljdk/internal/reflect/ConstructorAccessor;", $PUBLIC, $virtualMethod(ReflectionFactory, newConstructorAccessor, $ConstructorAccessor*, $Constructor*)},
	{"newConstructorForExternalization", "(Ljava/lang/Class;)Ljava/lang/reflect/Constructor;", "(Ljava/lang/Class<*>;)Ljava/lang/reflect/Constructor<*>;", $PUBLIC | $FINAL, $method(ReflectionFactory, newConstructorForExternalization, $Constructor*, $Class*)},
	{"newConstructorForSerialization", "(Ljava/lang/Class;Ljava/lang/reflect/Constructor;)Ljava/lang/reflect/Constructor;", "(Ljava/lang/Class<*>;Ljava/lang/reflect/Constructor<*>;)Ljava/lang/reflect/Constructor<*>;", $PUBLIC | $FINAL, $method(ReflectionFactory, newConstructorForSerialization, $Constructor*, $Class*, $Constructor*)},
	{"newConstructorForSerialization", "(Ljava/lang/Class;)Ljava/lang/reflect/Constructor;", "(Ljava/lang/Class<*>;)Ljava/lang/reflect/Constructor<*>;", $PUBLIC | $FINAL, $method(ReflectionFactory, newConstructorForSerialization, $Constructor*, $Class*)},
	{"newFieldAccessor", "(Ljava/lang/reflect/Field;Z)Ljdk/internal/reflect/FieldAccessor;", nullptr, $PUBLIC, $virtualMethod(ReflectionFactory, newFieldAccessor, $FieldAccessor*, $Field*, bool)},
	{"newInstance", "(Ljava/lang/reflect/Constructor;[Ljava/lang/Object;Ljava/lang/Class;)Ljava/lang/Object;", "<T:Ljava/lang/Object;>(Ljava/lang/reflect/Constructor<TT;>;[Ljava/lang/Object;Ljava/lang/Class<*>;)TT;", $PUBLIC, $virtualMethod(ReflectionFactory, newInstance, $Object*, $Constructor*, $ObjectArray*, $Class*), "java.lang.IllegalAccessException,java.lang.InstantiationException,java.lang.reflect.InvocationTargetException"},
	{"newMethodAccessor", "(Ljava/lang/reflect/Method;)Ljdk/internal/reflect/MethodAccessor;", nullptr, $PUBLIC, $virtualMethod(ReflectionFactory, newMethodAccessor, $MethodAccessor*, $Method*)},
	{"newOptionalDataExceptionForSerialization", "()Ljava/lang/reflect/Constructor;", "()Ljava/lang/reflect/Constructor<Ljava/io/OptionalDataException;>;", $PUBLIC | $FINAL, $method(ReflectionFactory, newOptionalDataExceptionForSerialization, $Constructor*)},
	{"packageEquals", "(Ljava/lang/Class;Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;Ljava/lang/Class<*>;)Z", $PRIVATE | $STATIC, $staticMethod(ReflectionFactory, packageEquals, bool, $Class*, $Class*)},
	{"readObjectForSerialization", "(Ljava/lang/Class;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/Class<*>;)Ljava/lang/invoke/MethodHandle;", $PUBLIC | $FINAL, $method(ReflectionFactory, readObjectForSerialization, $MethodHandle*, $Class*)},
	{"readObjectNoDataForSerialization", "(Ljava/lang/Class;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/Class<*>;)Ljava/lang/invoke/MethodHandle;", $PUBLIC | $FINAL, $method(ReflectionFactory, readObjectNoDataForSerialization, $MethodHandle*, $Class*)},
	{"readResolveForSerialization", "(Ljava/lang/Class;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/Class<*>;)Ljava/lang/invoke/MethodHandle;", $PUBLIC | $FINAL, $method(ReflectionFactory, readResolveForSerialization, $MethodHandle*, $Class*)},
	{"setConstructorAccessor", "(Ljava/lang/reflect/Constructor;Ljdk/internal/reflect/ConstructorAccessor;)V", "(Ljava/lang/reflect/Constructor<*>;Ljdk/internal/reflect/ConstructorAccessor;)V", $PUBLIC, $virtualMethod(ReflectionFactory, setConstructorAccessor, void, $Constructor*, $ConstructorAccessor*)},
	{"superHasAccessibleConstructor", "(Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;)Z", $PRIVATE, $method(ReflectionFactory, superHasAccessibleConstructor, bool, $Class*)},
	{"writeObjectForSerialization", "(Ljava/lang/Class;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/Class<*>;)Ljava/lang/invoke/MethodHandle;", $PUBLIC | $FINAL, $method(ReflectionFactory, writeObjectForSerialization, $MethodHandle*, $Class*)},
	{"writeReplaceForSerialization", "(Ljava/lang/Class;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/Class<*>;)Ljava/lang/invoke/MethodHandle;", $PUBLIC | $FINAL, $method(ReflectionFactory, writeReplaceForSerialization, $MethodHandle*, $Class*)},
	{}
};

$InnerClassInfo _ReflectionFactory_InnerClassesInfo_[] = {
	{"jdk.internal.reflect.ReflectionFactory$GetReflectionFactoryAction", "jdk.internal.reflect.ReflectionFactory", "GetReflectionFactoryAction", $PUBLIC | $STATIC | $FINAL},
	{}
};

$ClassInfo _ReflectionFactory_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.reflect.ReflectionFactory",
	"java.lang.Object",
	nullptr,
	_ReflectionFactory_FieldInfo_,
	_ReflectionFactory_MethodInfo_,
	nullptr,
	nullptr,
	_ReflectionFactory_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.reflect.ReflectionFactory$GetReflectionFactoryAction"
};

$Object* allocate$ReflectionFactory($Class* clazz) {
	return $of($alloc(ReflectionFactory));
}

bool ReflectionFactory::$assertionsDisabled = false;
bool ReflectionFactory::initted = false;
ReflectionFactory* ReflectionFactory::soleInstance = nullptr;
$volatile($Method*) ReflectionFactory::hasStaticInitializerMethod = nullptr;
bool ReflectionFactory::noInflation = false;
int32_t ReflectionFactory::inflationThreshold$ = 0;
bool ReflectionFactory::disableSerialConstructorChecks = false;

void ReflectionFactory::init$() {
	$set(this, langReflectAccess, $SharedSecrets::getJavaLangReflectAccess());
}

ReflectionFactory* ReflectionFactory::getReflectionFactory() {
	$init(ReflectionFactory);
	$var($SecurityManager, security, $System::getSecurityManager());
	if (security != nullptr) {
		$init($SecurityConstants);
		security->checkPermission($SecurityConstants::REFLECTION_FACTORY_ACCESS_PERMISSION);
	}
	return ReflectionFactory::soleInstance;
}

$Method* ReflectionFactory::findMethodForReflection($Method* method) {
	$init(ReflectionFactory);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($String, altName, $str({"reflected$"_s, $($nc(method)->getName())}));
	try {
		return $nc(method->getDeclaringClass())->getDeclaredMethod(altName, $(method->getParameterTypes()));
	} catch ($NoSuchMethodException& ex) {
		return nullptr;
	}
	$shouldNotReachHere();
}

$FieldAccessor* ReflectionFactory::newFieldAccessor($Field* field$renamed, bool override$) {
	$useLocalCurrentObjectStackCache();
	$var($Field, field, field$renamed);
	checkInitted();
	$var($Field, root, $cast($Field, $nc(this->langReflectAccess)->getRoot(field)));
	if (root != nullptr) {
		int32_t var$0 = root->getModifiers();
		if (var$0 == $nc(field)->getModifiers() || !override$) {
			$assign(field, root);
		}
	}
	bool isFinal = $Modifier::isFinal($nc(field)->getModifiers());
	bool isReadOnly = isFinal && (!override$ || $nc(this->langReflectAccess)->isTrustedFinalField(field));
	return $UnsafeFieldAccessorFactory::newFieldAccessor(field, isReadOnly);
}

$MethodAccessor* ReflectionFactory::newMethodAccessor($Method* method0) {
	$var($Method, method, method0);
	$var($Method, root, $cast<$Method>($nullcheck(this->langReflectAccess)->getRoot(method)));
	if (root != nullptr) {
		$assign(method, root);
	}
	if (ReflectionFactory::noInflation && !$nullcheck($nullcheck(method)->getDeclaringClass())->isHidden()) {
		$Class* var$2 = method->getDeclaringClass();
		$var($String, var$3, method->getName());
		$var($ClassArray, var$4, method->getParameterTypes());
		$Class* var$5 = method->getReturnType();
		$var($ClassArray, var$6, method->getExceptionTypes());
		return $nullcheck($new<MethodAccessorGenerator>())->generateMethod(var$2, var$3, var$4, var$5, var$6, method->getModifiers());
	} else {
		$var(NativeMethodAccessorImpl, acc, $new<NativeMethodAccessorImpl>(method));
		$var(DelegatingMethodAccessorImpl, res, $new<DelegatingMethodAccessorImpl>(acc));
		acc->setParent(res);
		return res;
	}
}

$ConstructorAccessor* ReflectionFactory::newConstructorAccessor($Constructor* c$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($Constructor, c, c$renamed);
	checkInitted();
	$Class* declaringClass = $nc(c)->getDeclaringClass();
	if ($Modifier::isAbstract($nc(declaringClass)->getModifiers())) {
		return $new($InstantiationExceptionConstructorAccessorImpl, nullptr);
	}
	if (declaringClass == $Class::class$) {
		return $new($InstantiationExceptionConstructorAccessorImpl, "Can not instantiate java.lang.Class"_s);
	}
	$var($Constructor, root, $cast($Constructor, $nc(this->langReflectAccess)->getRoot(c)));
	if (root != nullptr) {
		$assign(c, root);
	}
	$load($ConstructorAccessorImpl);
	if ($Reflection::isSubclassOf(declaringClass, $ConstructorAccessorImpl::class$)) {
		return $new($BootstrapConstructorAccessorImpl, c);
	}
	if (ReflectionFactory::noInflation && !$nc(c->getDeclaringClass())->isHidden()) {
		$Class* var$0 = c->getDeclaringClass();
		$var($ClassArray, var$1, c->getParameterTypes());
		$var($ClassArray, var$2, c->getExceptionTypes());
		return $$new($MethodAccessorGenerator)->generateConstructor(var$0, var$1, var$2, c->getModifiers());
	} else {
		$var($NativeConstructorAccessorImpl, acc, $new($NativeConstructorAccessorImpl, c));
		$var($DelegatingConstructorAccessorImpl, res, $new($DelegatingConstructorAccessorImpl, acc));
		acc->setParent(res);
		return res;
	}
}

$Constructor* ReflectionFactory::newConstructor($Class* declaringClass, $ClassArray* parameterTypes, $ClassArray* checkedExceptions, int32_t modifiers, int32_t slot, $String* signature, $bytes* annotations, $bytes* parameterAnnotations) {
	return $nc(this->langReflectAccess)->newConstructor(declaringClass, parameterTypes, checkedExceptions, modifiers, slot, signature, annotations, parameterAnnotations);
}

$ConstructorAccessor* ReflectionFactory::getConstructorAccessor($Constructor* c) {
	return $nc(this->langReflectAccess)->getConstructorAccessor(c);
}

void ReflectionFactory::setConstructorAccessor($Constructor* c, $ConstructorAccessor* accessor) {
	$nc(this->langReflectAccess)->setConstructorAccessor(c, accessor);
}

$Method* ReflectionFactory::copyMethod($Method* arg) {
	return $nc(this->langReflectAccess)->copyMethod(arg);
}

$Method* ReflectionFactory::leafCopyMethod($Method* arg) {
	return $nc(this->langReflectAccess)->leafCopyMethod(arg);
}

$Field* ReflectionFactory::copyField($Field* arg) {
	return $nc(this->langReflectAccess)->copyField(arg);
}

$Constructor* ReflectionFactory::copyConstructor($Constructor* arg) {
	return $nc(this->langReflectAccess)->copyConstructor(arg);
}

$bytes* ReflectionFactory::getExecutableTypeAnnotationBytes($Executable* ex) {
	return $nc(this->langReflectAccess)->getExecutableTypeAnnotationBytes(ex);
}

$ClassArray* ReflectionFactory::getExecutableSharedParameterTypes($Executable* ex) {
	return $nc(this->langReflectAccess)->getExecutableSharedParameterTypes(ex);
}

$Object* ReflectionFactory::newInstance($Constructor* ctor, $ObjectArray* args, $Class* caller) {
	return $of($nc(this->langReflectAccess)->newInstance(ctor, args, caller));
}

$Constructor* ReflectionFactory::newConstructorForExternalization($Class* cl) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$load($Externalizable);
	if (!$Externalizable::class$->isAssignableFrom(cl)) {
		return nullptr;
	}
	try {
		$var($Constructor, cons, $nc(cl)->getConstructor($$new($ClassArray, 0)));
		$nc(cons)->setAccessible(true);
		return cons;
	} catch ($NoSuchMethodException& ex) {
		return nullptr;
	}
	$shouldNotReachHere();
}

$Constructor* ReflectionFactory::newConstructorForSerialization($Class* cl, $Constructor* constructorToCall) {
	$beforeCallerSensitive();
	if ($nc(constructorToCall)->getDeclaringClass() == cl) {
		constructorToCall->setAccessible(true);
		return constructorToCall;
	}
	return generateConstructor(cl, constructorToCall);
}

bool ReflectionFactory::superHasAccessibleConstructor($Class* cl) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$Class* superCl = $nc(cl)->getSuperclass();
	$load($Serializable);
	if (!ReflectionFactory::$assertionsDisabled && !$Serializable::class$->isAssignableFrom(cl)) {
		$throwNew($AssertionError);
	}
	if (!ReflectionFactory::$assertionsDisabled && !(superCl != nullptr)) {
		$throwNew($AssertionError);
	}
	if (packageEquals(cl, superCl)) {
		{
			$var($ConstructorArray, arr$, $nc(superCl)->getDeclaredConstructors());
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($Constructor, ctor, arr$->get(i$));
				{
					if (((int32_t)($nc(ctor)->getModifiers() & (uint32_t)$Modifier::PRIVATE)) == 0) {
						return true;
					}
				}
			}
		}
		if ($Reflection::areNestMates(cl, superCl)) {
			return true;
		}
		return false;
	} else {
		if (((int32_t)($nc(superCl)->getModifiers() & (uint32_t)($Modifier::PROTECTED | $Modifier::PUBLIC))) == 0) {
			return false;
		}
		{
			$var($ConstructorArray, arr$, $nc(superCl)->getDeclaredConstructors());
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($Constructor, ctor, arr$->get(i$));
				{
					if (((int32_t)($nc(ctor)->getModifiers() & (uint32_t)($Modifier::PROTECTED | $Modifier::PUBLIC))) != 0) {
						return true;
					}
				}
			}
		}
		return false;
	}
}

$Constructor* ReflectionFactory::newConstructorForSerialization($Class* cl) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$Class* initCl = cl;
	$load($Serializable);
	while ($Serializable::class$->isAssignableFrom(initCl)) {
		$Class* prev = initCl;
		bool var$0 = (initCl = $nc(initCl)->getSuperclass()) == nullptr;
		if (var$0 || (!ReflectionFactory::disableSerialConstructorChecks && !superHasAccessibleConstructor(prev))) {
			return nullptr;
		}
	}
	$var($Constructor, constructorToCall, nullptr);
	try {
		$assign(constructorToCall, $nc(initCl)->getDeclaredConstructor($$new($ClassArray, 0)));
		int32_t mods = $nc(constructorToCall)->getModifiers();
		if (((int32_t)(mods & (uint32_t)$Modifier::PRIVATE)) != 0 || (((int32_t)(mods & (uint32_t)($Modifier::PUBLIC | $Modifier::PROTECTED))) == 0 && !packageEquals(cl, initCl))) {
			return nullptr;
		}
	} catch ($NoSuchMethodException& ex) {
		return nullptr;
	}
	return generateConstructor(cl, constructorToCall);
}

$Constructor* ReflectionFactory::generateConstructor($Class* cl, $Constructor* constructorToCall) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$Class* var$0 = cl;
	$var($ClassArray, var$1, $nc(constructorToCall)->getParameterTypes());
	$var($ClassArray, var$2, constructorToCall->getExceptionTypes());
	int32_t var$3 = constructorToCall->getModifiers();
	$var($ConstructorAccessor, acc, $$new($MethodAccessorGenerator)->generateSerializationConstructor(var$0, var$1, var$2, var$3, constructorToCall->getDeclaringClass()));
	$Class* var$4 = $nc(constructorToCall)->getDeclaringClass();
	$var($ClassArray, var$5, constructorToCall->getParameterTypes());
	$var($ClassArray, var$6, constructorToCall->getExceptionTypes());
	int32_t var$7 = constructorToCall->getModifiers();
	int32_t var$8 = $nc(this->langReflectAccess)->getConstructorSlot(constructorToCall);
	$var($String, var$9, $nc(this->langReflectAccess)->getConstructorSignature(constructorToCall));
	$var($bytes, var$10, $nc(this->langReflectAccess)->getConstructorAnnotations(constructorToCall));
	$var($Constructor, c, newConstructor(var$4, var$5, var$6, var$7, var$8, var$9, var$10, $($nc(this->langReflectAccess)->getConstructorParameterAnnotations(constructorToCall))));
	setConstructorAccessor(c, acc);
	$nc(c)->setAccessible(true);
	return c;
}

$MethodHandle* ReflectionFactory::readObjectForSerialization($Class* cl) {
	$load($ObjectInputStream);
	return findReadWriteObjectForSerialization(cl, "readObject"_s, $ObjectInputStream::class$);
}

$MethodHandle* ReflectionFactory::readObjectNoDataForSerialization($Class* cl) {
	$load($ObjectInputStream);
	return findReadWriteObjectForSerialization(cl, "readObjectNoData"_s, $ObjectInputStream::class$);
}

$MethodHandle* ReflectionFactory::writeObjectForSerialization($Class* cl) {
	$load($ObjectOutputStream);
	return findReadWriteObjectForSerialization(cl, "writeObject"_s, $ObjectOutputStream::class$);
}

$MethodHandle* ReflectionFactory::findReadWriteObjectForSerialization($Class* cl, $String* methodName, $Class* streamClass) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$load($Serializable);
	if (!$Serializable::class$->isAssignableFrom(cl)) {
		return nullptr;
	}
	try {
		$var($Method, meth, $nc(cl)->getDeclaredMethod(methodName, $$new($ClassArray, {streamClass})));
		int32_t mods = $nc(meth)->getModifiers();
		$init($Void);
		bool var$1 = meth->getReturnType() != $Void::TYPE;
		bool var$0 = var$1 || $Modifier::isStatic(mods);
		if (var$0 || !$Modifier::isPrivate(mods)) {
			return nullptr;
		}
		meth->setAccessible(true);
		return $nc($($MethodHandles::lookup()))->unreflect(meth);
	} catch ($NoSuchMethodException& ex) {
		return nullptr;
	} catch ($IllegalAccessException& ex1) {
		$throwNew($InternalError, "Error"_s, ex1);
	}
	$shouldNotReachHere();
}

$MethodHandle* ReflectionFactory::writeReplaceForSerialization($Class* cl) {
	return getReplaceResolveForSerialization(cl, "writeReplace"_s);
}

$MethodHandle* ReflectionFactory::readResolveForSerialization($Class* cl) {
	return getReplaceResolveForSerialization(cl, "readResolve"_s);
}

$MethodHandle* ReflectionFactory::getReplaceResolveForSerialization($Class* cl, $String* methodName) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$load($Serializable);
	if (!$Serializable::class$->isAssignableFrom(cl)) {
		return nullptr;
	}
	$Class* defCl = cl;
	while (defCl != nullptr) {
		try {
			$var($Method, m, defCl->getDeclaredMethod(methodName, $$new($ClassArray, 0)));
			if ($nc(m)->getReturnType() != $Object::class$) {
				return nullptr;
			}
			int32_t mods = $nc(m)->getModifiers();
			bool var$0 = $Modifier::isStatic(mods);
			if (var$0 | $Modifier::isAbstract(mods)) {
				return nullptr;
			} else {
				bool var$2 = $Modifier::isPublic(mods);
				if (var$2 | $Modifier::isProtected(mods)) {
				} else if ($Modifier::isPrivate(mods) && (cl != defCl)) {
					return nullptr;
				} else if (!packageEquals(cl, defCl)) {
					return nullptr;
				}
			}
			try {
				m->setAccessible(true);
				return $nc($($MethodHandles::lookup()))->unreflect(m);
			} catch ($IllegalAccessException& ex0) {
				$throwNew($InternalError, "Error"_s, ex0);
			}
		} catch ($NoSuchMethodException& ex) {
			defCl = defCl->getSuperclass();
		}
	}
	return nullptr;
}

bool ReflectionFactory::hasStaticInitializerForSerialization($Class* cl) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($Method, m, ReflectionFactory::hasStaticInitializerMethod);
	if (m == nullptr) {
		try {
			$load($ObjectStreamClass);
			$assign(m, $ObjectStreamClass::class$->getDeclaredMethod("hasStaticInitializer"_s, $$new($ClassArray, {$Class::class$})));
			$nc(m)->setAccessible(true);
			$assignStatic(ReflectionFactory::hasStaticInitializerMethod, m);
		} catch ($NoSuchMethodException& ex) {
			$load($ObjectStreamClass);
			$throwNew($InternalError, $$str({"No such method hasStaticInitializer on "_s, $ObjectStreamClass::class$}), ex);
		}
	}
	try {
		return $nc(($cast($Boolean, $($nc(m)->invoke(nullptr, $$new($ObjectArray, {$of(cl)}))))))->booleanValue();
	} catch ($InvocationTargetException& ex) {
		$throwNew($InternalError, "Exception invoking hasStaticInitializer"_s, ex);
	} catch ($IllegalAccessException& ex) {
		$throwNew($InternalError, "Exception invoking hasStaticInitializer"_s, ex);
	}
	$shouldNotReachHere();
}

$Constructor* ReflectionFactory::newOptionalDataExceptionForSerialization() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	try {
		$load($OptionalDataException);
		$init($Boolean);
		$var($Constructor, boolCtor, $OptionalDataException::class$->getDeclaredConstructor($$new($ClassArray, {$Boolean::TYPE})));
		$nc(boolCtor)->setAccessible(true);
		return boolCtor;
	} catch ($NoSuchMethodException& ex) {
		$throwNew($InternalError, "Constructor not found"_s, ex);
	}
	$shouldNotReachHere();
}

int32_t ReflectionFactory::inflationThreshold() {
	$init(ReflectionFactory);
	return ReflectionFactory::inflationThreshold$;
}

void ReflectionFactory::checkInitted() {
	$init(ReflectionFactory);
	$useLocalCurrentObjectStackCache();
	if (ReflectionFactory::initted) {
		return;
	}
	if (!$VM::isModuleSystemInited()) {
		return;
	}
	$var($Properties, props, $GetPropertyAction::privilegedGetProperties());
	$var($String, val, $nc(props)->getProperty("sun.reflect.noInflation"_s));
	if (val != nullptr && val->equals("true"_s)) {
		ReflectionFactory::noInflation = true;
	}
	$assign(val, props->getProperty("sun.reflect.inflationThreshold"_s));
	if (val != nullptr) {
		try {
			ReflectionFactory::inflationThreshold$ = $Integer::parseInt(val);
		} catch ($NumberFormatException& e) {
			$throwNew($RuntimeException, "Unable to parse property sun.reflect.inflationThreshold"_s, e);
		}
	}
	ReflectionFactory::disableSerialConstructorChecks = "true"_s->equals($(props->getProperty("jdk.disableSerialConstructorChecks"_s)));
	ReflectionFactory::initted = true;
}

bool ReflectionFactory::packageEquals($Class* cl1, $Class* cl2) {
	$init(ReflectionFactory);
	$beforeCallerSensitive();
	bool var$0 = !ReflectionFactory::$assertionsDisabled;
	if (var$0) {
		bool var$1 = !$nc(cl1)->isArray();
		var$0 = !(var$1 && !$nc(cl2)->isArray());
	}
	if (var$0) {
		$throwNew($AssertionError);
	}
	if (cl1 == cl2) {
		return true;
	}
	bool var$2 = $nc(cl1)->getClassLoader() == $nc(cl2)->getClassLoader();
	if (var$2) {
		var$2 = cl1->getPackageName() == cl2->getPackageName();
	}
	return var$2;
}

void clinit$ReflectionFactory($Class* class$) {
	ReflectionFactory::$assertionsDisabled = !ReflectionFactory::class$->desiredAssertionStatus();
	ReflectionFactory::initted = false;
	$assignStatic(ReflectionFactory::soleInstance, $new(ReflectionFactory));
	ReflectionFactory::noInflation = false;
	ReflectionFactory::inflationThreshold$ = 15;
	ReflectionFactory::disableSerialConstructorChecks = false;
}

ReflectionFactory::ReflectionFactory() {
}

$Class* ReflectionFactory::load$($String* name, bool initialize) {
	$loadClass(ReflectionFactory, name, initialize, &_ReflectionFactory_ClassInfo_, clinit$ReflectionFactory, allocate$ReflectionFactory);
	return class$;
}

$Class* ReflectionFactory::class$ = nullptr;

		} // reflect
	} // internal
} // jdk