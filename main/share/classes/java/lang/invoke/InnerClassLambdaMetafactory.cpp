#include <java/lang/invoke/InnerClassLambdaMetafactory.h>

#include <java/io/FilePermission.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/InternalError.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/constant/ConstantDescs.h>
#include <java/lang/invoke/AbstractValidatingLambdaMetafactory.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/ConstantCallSite.h>
#include <java/lang/invoke/InnerClassLambdaMetafactory$1.h>
#include <java/lang/invoke/InnerClassLambdaMetafactory$2.h>
#include <java/lang/invoke/InnerClassLambdaMetafactory$ForwardingMethodGenerator.h>
#include <java/lang/invoke/LambdaConversionException.h>
#include <java/lang/invoke/LambdaProxyClassArchive.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandleInfo.h>
#include <java/lang/invoke/MethodHandles$Lookup$ClassOption.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/invoke/ProxyClassesDumper.h>
#include <java/lang/invoke/TypeConvertingMethodAdapter.h>
#include <java/lang/invoke/TypeDescriptor$OfField.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Modifier.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/LinkedHashSet.h>
#include <java/util/PropertyPermission.h>
#include <java/util/Set.h>
#include <java/util/concurrent/atomic/AtomicInteger.h>
#include <jdk/internal/misc/CDS.h>
#include <jdk/internal/org/objectweb/asm/ClassWriter.h>
#include <jdk/internal/org/objectweb/asm/ConstantDynamic.h>
#include <jdk/internal/org/objectweb/asm/FieldVisitor.h>
#include <jdk/internal/org/objectweb/asm/Handle.h>
#include <jdk/internal/org/objectweb/asm/MethodVisitor.h>
#include <jdk/internal/org/objectweb/asm/Opcodes.h>
#include <jdk/internal/org/objectweb/asm/Type.h>
#include <sun/invoke/util/BytecodeDescriptor.h>
#include <sun/invoke/util/VerifyAccess.h>
#include <sun/security/action/GetBooleanAction.h>
#include <sun/security/action/GetPropertyAction.h>
#include <jcpp.h>

#undef CLASSFILE_VERSION
#undef COMPUTE_MAXS
#undef DEFAULT_NAME
#undef DESCR_CLASS
#undef DESCR_CTOR_NOT_SERIALIZABLE_EXCEPTION
#undef DESCR_CTOR_SERIALIZED_LAMBDA
#undef DESCR_METHOD_READ_OBJECT
#undef DESCR_METHOD_WRITE_OBJECT
#undef DESCR_METHOD_WRITE_REPLACE
#undef DESCR_OBJECT
#undef DESCR_STRING
#undef DUP
#undef EMPTY_STRING_ARRAY
#undef JAVA_LANG_OBJECT
#undef LAMBDA_INSTANCE_FIELD
#undef METHOD_DESCRIPTOR_VOID
#undef NAME_CTOR
#undef NAME_METHOD_READ_OBJECT
#undef NAME_METHOD_WRITE_OBJECT
#undef NAME_METHOD_WRITE_REPLACE
#undef NAME_NOT_SERIALIZABLE_EXCEPTION
#undef NAME_SERIALIZED_LAMBDA
#undef NESTMATE
#undef SER_HOSTILE_EXCEPTIONS
#undef STRONG
#undef TYPE
#undef VOID_TYPE

using $MethodHandles$Lookup$ClassOptionArray = $Array<::java::lang::invoke::MethodHandles$Lookup$ClassOption>;
using $MethodTypeArray = $Array<::java::lang::invoke::MethodType>;
using $ConstructorArray = $Array<::java::lang::reflect::Constructor>;
using $PermissionArray = $Array<::java::security::Permission>;
using $TypeArray = $Array<::jdk::internal::org::objectweb::asm$::Type>;
using $FilePermission = ::java::io::FilePermission;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $Double = ::java::lang::Double;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $Void = ::java::lang::Void;
using $ConstantDescs = ::java::lang::constant::ConstantDescs;
using $AbstractValidatingLambdaMetafactory = ::java::lang::invoke::AbstractValidatingLambdaMetafactory;
using $CallSite = ::java::lang::invoke::CallSite;
using $ConstantCallSite = ::java::lang::invoke::ConstantCallSite;
using $InnerClassLambdaMetafactory$1 = ::java::lang::invoke::InnerClassLambdaMetafactory$1;
using $InnerClassLambdaMetafactory$2 = ::java::lang::invoke::InnerClassLambdaMetafactory$2;
using $InnerClassLambdaMetafactory$ForwardingMethodGenerator = ::java::lang::invoke::InnerClassLambdaMetafactory$ForwardingMethodGenerator;
using $LambdaConversionException = ::java::lang::invoke::LambdaConversionException;
using $LambdaProxyClassArchive = ::java::lang::invoke::LambdaProxyClassArchive;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandleInfo = ::java::lang::invoke::MethodHandleInfo;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodHandles$Lookup$ClassOption = ::java::lang::invoke::MethodHandles$Lookup$ClassOption;
using $MethodType = ::java::lang::invoke::MethodType;
using $ProxyClassesDumper = ::java::lang::invoke::ProxyClassesDumper;
using $TypeConvertingMethodAdapter = ::java::lang::invoke::TypeConvertingMethodAdapter;
using $Constructor = ::java::lang::reflect::Constructor;
using $Modifier = ::java::lang::reflect::Modifier;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $Permission = ::java::security::Permission;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $LinkedHashSet = ::java::util::LinkedHashSet;
using $PropertyPermission = ::java::util::PropertyPermission;
using $Set = ::java::util::Set;
using $AtomicInteger = ::java::util::concurrent::atomic::AtomicInteger;
using $CDS = ::jdk::internal::misc::CDS;
using $ClassWriter = ::jdk::internal::org::objectweb::asm$::ClassWriter;
using $ConstantDynamic = ::jdk::internal::org::objectweb::asm$::ConstantDynamic;
using $FieldVisitor = ::jdk::internal::org::objectweb::asm$::FieldVisitor;
using $Handle = ::jdk::internal::org::objectweb::asm$::Handle;
using $MethodVisitor = ::jdk::internal::org::objectweb::asm$::MethodVisitor;
using $Opcodes = ::jdk::internal::org::objectweb::asm$::Opcodes;
using $Type = ::jdk::internal::org::objectweb::asm$::Type;
using $BytecodeDescriptor = ::sun::invoke::util::BytecodeDescriptor;
using $VerifyAccess = ::sun::invoke::util::VerifyAccess;
using $GetBooleanAction = ::sun::security::action::GetBooleanAction;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;

namespace java {
	namespace lang {
		namespace invoke {

$FieldInfo _InnerClassLambdaMetafactory_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(InnerClassLambdaMetafactory, $assertionsDisabled)},
	{"CLASSFILE_VERSION", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(InnerClassLambdaMetafactory, CLASSFILE_VERSION)},
	{"METHOD_DESCRIPTOR_VOID", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InnerClassLambdaMetafactory, METHOD_DESCRIPTOR_VOID)},
	{"JAVA_LANG_OBJECT", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InnerClassLambdaMetafactory, JAVA_LANG_OBJECT)},
	{"NAME_CTOR", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InnerClassLambdaMetafactory, NAME_CTOR)},
	{"LAMBDA_INSTANCE_FIELD", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InnerClassLambdaMetafactory, LAMBDA_INSTANCE_FIELD)},
	{"NAME_SERIALIZED_LAMBDA", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InnerClassLambdaMetafactory, NAME_SERIALIZED_LAMBDA)},
	{"NAME_NOT_SERIALIZABLE_EXCEPTION", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InnerClassLambdaMetafactory, NAME_NOT_SERIALIZABLE_EXCEPTION)},
	{"DESCR_METHOD_WRITE_REPLACE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InnerClassLambdaMetafactory, DESCR_METHOD_WRITE_REPLACE)},
	{"DESCR_METHOD_WRITE_OBJECT", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InnerClassLambdaMetafactory, DESCR_METHOD_WRITE_OBJECT)},
	{"DESCR_METHOD_READ_OBJECT", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InnerClassLambdaMetafactory, DESCR_METHOD_READ_OBJECT)},
	{"NAME_METHOD_WRITE_REPLACE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InnerClassLambdaMetafactory, NAME_METHOD_WRITE_REPLACE)},
	{"NAME_METHOD_READ_OBJECT", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InnerClassLambdaMetafactory, NAME_METHOD_READ_OBJECT)},
	{"NAME_METHOD_WRITE_OBJECT", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InnerClassLambdaMetafactory, NAME_METHOD_WRITE_OBJECT)},
	{"DESCR_CLASS", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InnerClassLambdaMetafactory, DESCR_CLASS)},
	{"DESCR_STRING", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InnerClassLambdaMetafactory, DESCR_STRING)},
	{"DESCR_OBJECT", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InnerClassLambdaMetafactory, DESCR_OBJECT)},
	{"DESCR_CTOR_SERIALIZED_LAMBDA", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InnerClassLambdaMetafactory, DESCR_CTOR_SERIALIZED_LAMBDA)},
	{"DESCR_CTOR_NOT_SERIALIZABLE_EXCEPTION", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InnerClassLambdaMetafactory, DESCR_CTOR_NOT_SERIALIZABLE_EXCEPTION)},
	{"SER_HOSTILE_EXCEPTIONS", "[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InnerClassLambdaMetafactory, SER_HOSTILE_EXCEPTIONS)},
	{"EMPTY_STRING_ARRAY", "[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InnerClassLambdaMetafactory, EMPTY_STRING_ARRAY)},
	{"counter", "Ljava/util/concurrent/atomic/AtomicInteger;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InnerClassLambdaMetafactory, counter)},
	{"dumper", "Ljava/lang/invoke/ProxyClassesDumper;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InnerClassLambdaMetafactory, dumper)},
	{"disableEagerInitialization", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InnerClassLambdaMetafactory, disableEagerInitialization)},
	{"implMethodCondy", "Ljdk/internal/org/objectweb/asm/ConstantDynamic;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InnerClassLambdaMetafactory, implMethodCondy)},
	{"implMethodClassName", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(InnerClassLambdaMetafactory, implMethodClassName)},
	{"implMethodName", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(InnerClassLambdaMetafactory, implMethodName)},
	{"implMethodDesc", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(InnerClassLambdaMetafactory, implMethodDesc)},
	{"constructorType", "Ljava/lang/invoke/MethodType;", nullptr, $PRIVATE | $FINAL, $field(InnerClassLambdaMetafactory, constructorType)},
	{"cw", "Ljdk/internal/org/objectweb/asm/ClassWriter;", nullptr, $PRIVATE | $FINAL, $field(InnerClassLambdaMetafactory, cw)},
	{"argNames", "[Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(InnerClassLambdaMetafactory, argNames)},
	{"argDescs", "[Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(InnerClassLambdaMetafactory, argDescs)},
	{"lambdaClassName", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(InnerClassLambdaMetafactory, lambdaClassName$)},
	{"useImplMethodHandle", "Z", nullptr, $PRIVATE | $FINAL, $field(InnerClassLambdaMetafactory, useImplMethodHandle)},
	{}
};

$MethodInfo _InnerClassLambdaMetafactory_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/invoke/MethodHandles$Lookup;Ljava/lang/invoke/MethodType;Ljava/lang/String;Ljava/lang/invoke/MethodType;Ljava/lang/invoke/MethodHandle;Ljava/lang/invoke/MethodType;Z[Ljava/lang/Class;[Ljava/lang/invoke/MethodType;)V", "(Ljava/lang/invoke/MethodHandles$Lookup;Ljava/lang/invoke/MethodType;Ljava/lang/String;Ljava/lang/invoke/MethodType;Ljava/lang/invoke/MethodHandle;Ljava/lang/invoke/MethodType;Z[Ljava/lang/Class<*>;[Ljava/lang/invoke/MethodType;)V", $PUBLIC, $method(InnerClassLambdaMetafactory, init$, void, $MethodHandles$Lookup*, $MethodType*, $String*, $MethodType*, $MethodHandle*, $MethodType*, bool, $ClassArray*, $MethodTypeArray*), "java.lang.invoke.LambdaConversionException"},
	{"buildCallSite", "()Ljava/lang/invoke/CallSite;", nullptr, 0, $virtualMethod(InnerClassLambdaMetafactory, buildCallSite, $CallSite*), "java.lang.invoke.LambdaConversionException"},
	{"generateClassInitializer", "()V", nullptr, $PRIVATE, $method(InnerClassLambdaMetafactory, generateClassInitializer, void)},
	{"generateConstructor", "()V", nullptr, $PRIVATE, $method(InnerClassLambdaMetafactory, generateConstructor, void)},
	{"generateInnerClass", "()Ljava/lang/Class;", "()Ljava/lang/Class<*>;", $PRIVATE, $method(InnerClassLambdaMetafactory, generateInnerClass, $Class*), "java.lang.invoke.LambdaConversionException"},
	{"generateSerializationFriendlyMethods", "()V", nullptr, $PRIVATE, $method(InnerClassLambdaMetafactory, generateSerializationFriendlyMethods, void)},
	{"generateSerializationHostileMethods", "()V", nullptr, $PRIVATE, $method(InnerClassLambdaMetafactory, generateSerializationHostileMethods, void)},
	{"getLoadOpcode", "(Ljava/lang/Class;)I", "(Ljava/lang/Class<*>;)I", $STATIC, $staticMethod(InnerClassLambdaMetafactory, getLoadOpcode, int32_t, $Class*)},
	{"getOpcodeOffset", "(Ljava/lang/Class;)I", "(Ljava/lang/Class<*>;)I", $PRIVATE | $STATIC, $staticMethod(InnerClassLambdaMetafactory, getOpcodeOffset, int32_t, $Class*)},
	{"getParameterSize", "(Ljava/lang/Class;)I", "(Ljava/lang/Class<*>;)I", $STATIC, $staticMethod(InnerClassLambdaMetafactory, getParameterSize, int32_t, $Class*)},
	{"getReturnOpcode", "(Ljava/lang/Class;)I", "(Ljava/lang/Class<*>;)I", $STATIC, $staticMethod(InnerClassLambdaMetafactory, getReturnOpcode, int32_t, $Class*)},
	{"lambdaClassName", "(Ljava/lang/Class;)Ljava/lang/String;", "(Ljava/lang/Class<*>;)Ljava/lang/String;", $PRIVATE | $STATIC, $staticMethod(InnerClassLambdaMetafactory, lambdaClassName, $String*, $Class*)},
	{"spinInnerClass", "()Ljava/lang/Class;", "()Ljava/lang/Class<*>;", $PRIVATE, $method(InnerClassLambdaMetafactory, spinInnerClass, $Class*), "java.lang.invoke.LambdaConversionException"},
	{}
};

$InnerClassInfo _InnerClassLambdaMetafactory_InnerClassesInfo_[] = {
	{"java.lang.invoke.InnerClassLambdaMetafactory$ForwardingMethodGenerator", "java.lang.invoke.InnerClassLambdaMetafactory", "ForwardingMethodGenerator", $PRIVATE},
	{"java.lang.invoke.InnerClassLambdaMetafactory$2", nullptr, nullptr, 0},
	{"java.lang.invoke.InnerClassLambdaMetafactory$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _InnerClassLambdaMetafactory_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.lang.invoke.InnerClassLambdaMetafactory",
	"java.lang.invoke.AbstractValidatingLambdaMetafactory",
	nullptr,
	_InnerClassLambdaMetafactory_FieldInfo_,
	_InnerClassLambdaMetafactory_MethodInfo_,
	nullptr,
	nullptr,
	_InnerClassLambdaMetafactory_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.lang.invoke.InnerClassLambdaMetafactory$ForwardingMethodGenerator,java.lang.invoke.InnerClassLambdaMetafactory$2,java.lang.invoke.InnerClassLambdaMetafactory$1"
};

$Object* allocate$InnerClassLambdaMetafactory($Class* clazz) {
	return $of($alloc(InnerClassLambdaMetafactory));
}

bool InnerClassLambdaMetafactory::$assertionsDisabled = false;
$String* InnerClassLambdaMetafactory::METHOD_DESCRIPTOR_VOID = nullptr;
$String* InnerClassLambdaMetafactory::JAVA_LANG_OBJECT = nullptr;
$String* InnerClassLambdaMetafactory::NAME_CTOR = nullptr;
$String* InnerClassLambdaMetafactory::LAMBDA_INSTANCE_FIELD = nullptr;
$String* InnerClassLambdaMetafactory::NAME_SERIALIZED_LAMBDA = nullptr;
$String* InnerClassLambdaMetafactory::NAME_NOT_SERIALIZABLE_EXCEPTION = nullptr;
$String* InnerClassLambdaMetafactory::DESCR_METHOD_WRITE_REPLACE = nullptr;
$String* InnerClassLambdaMetafactory::DESCR_METHOD_WRITE_OBJECT = nullptr;
$String* InnerClassLambdaMetafactory::DESCR_METHOD_READ_OBJECT = nullptr;
$String* InnerClassLambdaMetafactory::NAME_METHOD_WRITE_REPLACE = nullptr;
$String* InnerClassLambdaMetafactory::NAME_METHOD_READ_OBJECT = nullptr;
$String* InnerClassLambdaMetafactory::NAME_METHOD_WRITE_OBJECT = nullptr;
$String* InnerClassLambdaMetafactory::DESCR_CLASS = nullptr;
$String* InnerClassLambdaMetafactory::DESCR_STRING = nullptr;
$String* InnerClassLambdaMetafactory::DESCR_OBJECT = nullptr;
$String* InnerClassLambdaMetafactory::DESCR_CTOR_SERIALIZED_LAMBDA = nullptr;
$String* InnerClassLambdaMetafactory::DESCR_CTOR_NOT_SERIALIZABLE_EXCEPTION = nullptr;
$StringArray* InnerClassLambdaMetafactory::SER_HOSTILE_EXCEPTIONS = nullptr;
$StringArray* InnerClassLambdaMetafactory::EMPTY_STRING_ARRAY = nullptr;
$AtomicInteger* InnerClassLambdaMetafactory::counter = nullptr;
$ProxyClassesDumper* InnerClassLambdaMetafactory::dumper = nullptr;
bool InnerClassLambdaMetafactory::disableEagerInitialization = false;
$ConstantDynamic* InnerClassLambdaMetafactory::implMethodCondy = nullptr;

void InnerClassLambdaMetafactory::init$($MethodHandles$Lookup* caller, $MethodType* factoryType, $String* interfaceMethodName, $MethodType* interfaceMethodType, $MethodHandle* implementation, $MethodType* dynamicMethodType, bool isSerializable, $ClassArray* altInterfaces, $MethodTypeArray* altMethods) {
	$useLocalCurrentObjectStackCache();
	$AbstractValidatingLambdaMetafactory::init$(caller, factoryType, interfaceMethodName, interfaceMethodType, implementation, dynamicMethodType, isSerializable, altInterfaces, altMethods);
	$set(this, implMethodClassName, $nc($($nc(this->implClass)->getName()))->replace(u'.', u'/'));
	$set(this, implMethodName, $nc(this->implInfo)->getName());
	$set(this, implMethodDesc, $nc($($nc(this->implInfo)->getMethodType()))->toMethodDescriptorString());
	$init($Void);
	$set(this, constructorType, $nc(factoryType)->changeReturnType($Void::TYPE));
	$set(this, lambdaClassName$, lambdaClassName(this->targetClass));
	bool var$0 = $Modifier::isProtected($nc(this->implInfo)->getModifiers());
	this->useImplMethodHandle = (var$0 && !$VerifyAccess::isSamePackage(this->targetClass, $nc(this->implInfo)->getDeclaringClass())) || this->implKind == 7;
	$set(this, cw, $new($ClassWriter, $ClassWriter::COMPUTE_MAXS));
	int32_t parameterCount = factoryType->parameterCount();
	if (parameterCount > 0) {
		$set(this, argNames, $new($StringArray, parameterCount));
		$set(this, argDescs, $new($StringArray, parameterCount));
		for (int32_t i = 0; i < parameterCount; ++i) {
			$nc(this->argNames)->set(i, $$str({"arg$"_s, $$str((i + 1))}));
			$nc(this->argDescs)->set(i, $($BytecodeDescriptor::unparse($($cast($Class, factoryType->parameterType(i))))));
		}
	} else {
		$set(this, argNames, ($set(this, argDescs, InnerClassLambdaMetafactory::EMPTY_STRING_ARRAY)));
	}
}

$String* InnerClassLambdaMetafactory::lambdaClassName($Class* targetClass) {
	$init(InnerClassLambdaMetafactory);
	$useLocalCurrentObjectStackCache();
	$var($String, name, $nc(targetClass)->getName());
	if (targetClass->isHidden()) {
		$assign(name, $nc(name)->replace(u'/', u'_'));
	}
	$var($String, var$0, $$str({$($nc(name)->replace(u'.', u'/')), "$$Lambda$"_s}));
	return $concat(var$0, $$str($nc(InnerClassLambdaMetafactory::counter)->incrementAndGet()));
}

$CallSite* InnerClassLambdaMetafactory::buildCallSite() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$Class* innerClass = spinInnerClass();
	if ($nc(this->factoryType)->parameterCount() == 0) {
		if (InnerClassLambdaMetafactory::disableEagerInitialization) {
			try {
				return $new($ConstantCallSite, $($nc(this->caller)->findStaticGetter(innerClass, InnerClassLambdaMetafactory::LAMBDA_INSTANCE_FIELD, $($cast($Class, $nc(this->factoryType)->returnType())))));
			} catch ($ReflectiveOperationException& e) {
				$throwNew($LambdaConversionException, $$str({"Exception finding "_s, InnerClassLambdaMetafactory::LAMBDA_INSTANCE_FIELD, " static field"_s}), e);
			}
		} else {
			$var($ConstructorArray, ctrs, $cast($ConstructorArray, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($InnerClassLambdaMetafactory$1, this, innerClass)))));
			if ($nc(ctrs)->length != 1) {
				$throwNew($LambdaConversionException, $$str({"Expected one lambda constructor for "_s, $($nc(innerClass)->getCanonicalName()), ", got "_s, $$str(ctrs->length)}));
			}
			try {
				$var($Object, inst, $nc($nc(ctrs)->get(0))->newInstance($$new($ObjectArray, 0)));
				return $new($ConstantCallSite, $($MethodHandles::constant(this->interfaceClass, inst)));
			} catch ($ReflectiveOperationException& e) {
				$throwNew($LambdaConversionException, "Exception instantiating lambda object"_s, e);
			}
		}
	} else {
		try {
			$var($MethodHandle, mh, $nc(this->caller)->findConstructor(innerClass, this->constructorType));
			return $new($ConstantCallSite, $($nc(mh)->asType(this->factoryType)));
		} catch ($ReflectiveOperationException& e) {
			$throwNew($LambdaConversionException, "Exception finding constructor"_s, e);
		}
	}
	$shouldNotReachHere();
}

$Class* InnerClassLambdaMetafactory::spinInnerClass() {
	if (!InnerClassLambdaMetafactory::disableEagerInitialization) {
		if ($CDS::isDumpingArchive()) {
			$Class* innerClass = generateInnerClass();
			$LambdaProxyClassArchive::register$(this->targetClass, this->interfaceMethodName, this->factoryType, this->interfaceMethodType, this->implementation, this->dynamicMethodType, this->isSerializable, this->altInterfaces, this->altMethods, innerClass);
			return innerClass;
		}
		$Class* innerClass = $LambdaProxyClassArchive::find(this->targetClass, this->interfaceMethodName, this->factoryType, this->interfaceMethodType, this->implementation, this->dynamicMethodType, this->isSerializable, this->altInterfaces, this->altMethods);
		if (innerClass != nullptr) {
			return innerClass;
		}
	}
	return generateInnerClass();
}

$Class* InnerClassLambdaMetafactory::generateInnerClass() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($StringArray, interfaceNames, nullptr);
	$var($String, interfaceName, $nc($($nc(this->interfaceClass)->getName()))->replace(u'.', u'/'));
	$load($Serializable);
	bool accidentallySerializable = !this->isSerializable && $Serializable::class$->isAssignableFrom(this->interfaceClass);
	if ($nc(this->altInterfaces)->length == 0) {
		$assign(interfaceNames, $new($StringArray, {interfaceName}));
	} else {
		$var($Set, itfs, $new($LinkedHashSet, $nc(this->altInterfaces)->length + 1));
		itfs->add(interfaceName);
		{
			$var($ClassArray, arr$, this->altInterfaces);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$Class* i = arr$->get(i$);
				{
					itfs->add($($nc($($nc(i)->getName()))->replace(u'.', u'/')));
					accidentallySerializable |= !this->isSerializable && $Serializable::class$->isAssignableFrom(i);
				}
			}
		}
		$assign(interfaceNames, $fcast($StringArray, itfs->toArray($$new($StringArray, itfs->size()))));
	}
	$nc(this->cw)->visit(InnerClassLambdaMetafactory::CLASSFILE_VERSION, 32 + 16 + 4096, this->lambdaClassName$, nullptr, InnerClassLambdaMetafactory::JAVA_LANG_OBJECT, interfaceNames);
	for (int32_t i = 0; i < $nc(this->argDescs)->length; ++i) {
		$var($FieldVisitor, fv, $nc(this->cw)->visitField(2 + 16, $nc(this->argNames)->get(i), $nc(this->argDescs)->get(i), nullptr, nullptr));
		$nc(fv)->visitEnd();
	}
	generateConstructor();
	if ($nc(this->factoryType)->parameterCount() == 0 && InnerClassLambdaMetafactory::disableEagerInitialization) {
		generateClassInitializer();
	}
	$var($MethodVisitor, mv, $nc(this->cw)->visitMethod(1, this->interfaceMethodName, $($nc(this->interfaceMethodType)->toMethodDescriptorString()), nullptr, nullptr));
	$$new($InnerClassLambdaMetafactory$ForwardingMethodGenerator, this, mv)->generate(this->interfaceMethodType);
	if (this->altMethods != nullptr) {
		{
			$var($MethodTypeArray, arr$, this->altMethods);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($MethodType, mt, arr$->get(i$));
				{
					$assign(mv, $nc(this->cw)->visitMethod(1, this->interfaceMethodName, $($nc(mt)->toMethodDescriptorString()), nullptr, nullptr));
					$$new($InnerClassLambdaMetafactory$ForwardingMethodGenerator, this, mv)->generate(mt);
				}
			}
		}
	}
	if (this->isSerializable) {
		generateSerializationFriendlyMethods();
	} else if (accidentallySerializable) {
		generateSerializationHostileMethods();
	}
	$nc(this->cw)->visitEnd();
	$var($bytes, classBytes, $nc(this->cw)->toByteArray());
	if (InnerClassLambdaMetafactory::dumper != nullptr) {
		$var($PrivilegedAction, var$0, static_cast<$PrivilegedAction*>($new($InnerClassLambdaMetafactory$2, this, classBytes)));
		$AccessController::doPrivileged(var$0, ($AccessControlContext*)nullptr, $$new($PermissionArray, {
			static_cast<$Permission*>($$new($FilePermission, "<<ALL FILES>>"_s, "read, write"_s)),
			static_cast<$Permission*>($$new($PropertyPermission, "user.dir"_s, "read"_s))
		}));
	}
	try {
		$var($MethodHandles$Lookup, lookup, nullptr);
		if (this->useImplMethodHandle) {
			$init($MethodHandles$Lookup$ClassOption);
			$assign(lookup, $nc(this->caller)->defineHiddenClassWithClassData(classBytes, this->implementation, !InnerClassLambdaMetafactory::disableEagerInitialization, $$new($MethodHandles$Lookup$ClassOptionArray, {
				$MethodHandles$Lookup$ClassOption::NESTMATE,
				$MethodHandles$Lookup$ClassOption::STRONG
			})));
		} else {
			$init($MethodHandles$Lookup$ClassOption);
			$assign(lookup, $nc(this->caller)->defineHiddenClass(classBytes, !InnerClassLambdaMetafactory::disableEagerInitialization, $$new($MethodHandles$Lookup$ClassOptionArray, {
				$MethodHandles$Lookup$ClassOption::NESTMATE,
				$MethodHandles$Lookup$ClassOption::STRONG
			})));
		}
		return $nc(lookup)->lookupClass();
	} catch ($IllegalAccessException& e) {
		$throwNew($LambdaConversionException, "Exception defining lambda proxy class"_s, e);
	} catch ($Throwable& t) {
		$throwNew($InternalError, $cast($Throwable, t));
	}
	$shouldNotReachHere();
}

void InnerClassLambdaMetafactory::generateClassInitializer() {
	$useLocalCurrentObjectStackCache();
	$var($String, lambdaTypeDescriptor, $nc($($cast($Class, $nc(this->factoryType)->returnType())))->descriptorString());
	$var($FieldVisitor, fv, $nc(this->cw)->visitField((2 | 8) | 16, InnerClassLambdaMetafactory::LAMBDA_INSTANCE_FIELD, lambdaTypeDescriptor, nullptr, nullptr));
	$nc(fv)->visitEnd();
	$var($MethodVisitor, clinit, $nc(this->cw)->visitMethod(8, "<clinit>"_s, "()V"_s, nullptr, nullptr));
	$nc(clinit)->visitCode();
	clinit->visitTypeInsn(187, this->lambdaClassName$);
	clinit->visitInsn($Opcodes::DUP);
	if (!InnerClassLambdaMetafactory::$assertionsDisabled && !($nc(this->factoryType)->parameterCount() == 0)) {
		$throwNew($AssertionError);
	}
	clinit->visitMethodInsn(183, this->lambdaClassName$, InnerClassLambdaMetafactory::NAME_CTOR, $($nc(this->constructorType)->toMethodDescriptorString()), false);
	clinit->visitFieldInsn(179, this->lambdaClassName$, InnerClassLambdaMetafactory::LAMBDA_INSTANCE_FIELD, lambdaTypeDescriptor);
	clinit->visitInsn(177);
	clinit->visitMaxs(-1, -1);
	clinit->visitEnd();
}

void InnerClassLambdaMetafactory::generateConstructor() {
	$useLocalCurrentObjectStackCache();
	$var($MethodVisitor, ctor, $nc(this->cw)->visitMethod(2, InnerClassLambdaMetafactory::NAME_CTOR, $($nc(this->constructorType)->toMethodDescriptorString()), nullptr, nullptr));
	$nc(ctor)->visitCode();
	ctor->visitVarInsn(25, 0);
	ctor->visitMethodInsn(183, InnerClassLambdaMetafactory::JAVA_LANG_OBJECT, InnerClassLambdaMetafactory::NAME_CTOR, InnerClassLambdaMetafactory::METHOD_DESCRIPTOR_VOID, false);
	int32_t parameterCount = $nc(this->factoryType)->parameterCount();
	{
		int32_t i = 0;
		int32_t lvIndex = 0;
		for (; i < parameterCount; ++i) {
			ctor->visitVarInsn(25, 0);
			$Class* argType = $cast($Class, $nc(this->factoryType)->parameterType(i));
			ctor->visitVarInsn(getLoadOpcode(argType), lvIndex + 1);
			lvIndex += getParameterSize(argType);
			ctor->visitFieldInsn(181, this->lambdaClassName$, $nc(this->argNames)->get(i), $nc(this->argDescs)->get(i));
		}
	}
	ctor->visitInsn(177);
	ctor->visitMaxs(-1, -1);
	ctor->visitEnd();
}

void InnerClassLambdaMetafactory::generateSerializationFriendlyMethods() {
	$useLocalCurrentObjectStackCache();
	$var($TypeConvertingMethodAdapter, mv, $new($TypeConvertingMethodAdapter, $($nc(this->cw)->visitMethod(2 + 16, InnerClassLambdaMetafactory::NAME_METHOD_WRITE_REPLACE, InnerClassLambdaMetafactory::DESCR_METHOD_WRITE_REPLACE, nullptr, nullptr))));
	mv->visitCode();
	mv->visitTypeInsn(187, InnerClassLambdaMetafactory::NAME_SERIALIZED_LAMBDA);
	mv->visitInsn(89);
	mv->visitLdcInsn($($Type::getType(this->targetClass)));
	mv->visitLdcInsn($($nc($($nc($($cast($Class, $nc(this->factoryType)->returnType())))->getName()))->replace(u'.', u'/')));
	mv->visitLdcInsn(this->interfaceMethodName);
	mv->visitLdcInsn($($nc(this->interfaceMethodType)->toMethodDescriptorString()));
	mv->visitLdcInsn($($Integer::valueOf($nc(this->implInfo)->getReferenceKind())));
	mv->visitLdcInsn($($nc($($nc($nc(this->implInfo)->getDeclaringClass())->getName()))->replace(u'.', u'/')));
	mv->visitLdcInsn($($nc(this->implInfo)->getName()));
	mv->visitLdcInsn($($nc($($nc(this->implInfo)->getMethodType()))->toMethodDescriptorString()));
	mv->visitLdcInsn($($nc(this->dynamicMethodType)->toMethodDescriptorString()));
	mv->iconst($nc(this->argDescs)->length);
	mv->visitTypeInsn(189, InnerClassLambdaMetafactory::JAVA_LANG_OBJECT);
	for (int32_t i = 0; i < $nc(this->argDescs)->length; ++i) {
		mv->visitInsn(89);
		mv->iconst(i);
		mv->visitVarInsn(25, 0);
		mv->visitFieldInsn(180, this->lambdaClassName$, $nc(this->argNames)->get(i), $nc(this->argDescs)->get(i));
		mv->boxIfTypePrimitive($($Type::getType($nc(this->argDescs)->get(i))));
		mv->visitInsn(83);
	}
	mv->visitMethodInsn(183, InnerClassLambdaMetafactory::NAME_SERIALIZED_LAMBDA, InnerClassLambdaMetafactory::NAME_CTOR, InnerClassLambdaMetafactory::DESCR_CTOR_SERIALIZED_LAMBDA, false);
	mv->visitInsn(176);
	mv->visitMaxs(-1, -1);
	mv->visitEnd();
}

void InnerClassLambdaMetafactory::generateSerializationHostileMethods() {
	$var($MethodVisitor, mv, $nc(this->cw)->visitMethod(2 + 16, InnerClassLambdaMetafactory::NAME_METHOD_WRITE_OBJECT, InnerClassLambdaMetafactory::DESCR_METHOD_WRITE_OBJECT, nullptr, InnerClassLambdaMetafactory::SER_HOSTILE_EXCEPTIONS));
	$nc(mv)->visitCode();
	mv->visitTypeInsn(187, InnerClassLambdaMetafactory::NAME_NOT_SERIALIZABLE_EXCEPTION);
	mv->visitInsn(89);
	mv->visitLdcInsn("Non-serializable lambda"_s);
	mv->visitMethodInsn(183, InnerClassLambdaMetafactory::NAME_NOT_SERIALIZABLE_EXCEPTION, InnerClassLambdaMetafactory::NAME_CTOR, InnerClassLambdaMetafactory::DESCR_CTOR_NOT_SERIALIZABLE_EXCEPTION, false);
	mv->visitInsn(191);
	mv->visitMaxs(-1, -1);
	mv->visitEnd();
	$assign(mv, $nc(this->cw)->visitMethod(2 + 16, InnerClassLambdaMetafactory::NAME_METHOD_READ_OBJECT, InnerClassLambdaMetafactory::DESCR_METHOD_READ_OBJECT, nullptr, InnerClassLambdaMetafactory::SER_HOSTILE_EXCEPTIONS));
	mv->visitCode();
	mv->visitTypeInsn(187, InnerClassLambdaMetafactory::NAME_NOT_SERIALIZABLE_EXCEPTION);
	mv->visitInsn(89);
	mv->visitLdcInsn("Non-serializable lambda"_s);
	mv->visitMethodInsn(183, InnerClassLambdaMetafactory::NAME_NOT_SERIALIZABLE_EXCEPTION, InnerClassLambdaMetafactory::NAME_CTOR, InnerClassLambdaMetafactory::DESCR_CTOR_NOT_SERIALIZABLE_EXCEPTION, false);
	mv->visitInsn(191);
	mv->visitMaxs(-1, -1);
	mv->visitEnd();
}

int32_t InnerClassLambdaMetafactory::getParameterSize($Class* c) {
	$init(InnerClassLambdaMetafactory);
	$init($Void);
	if (c == $Void::TYPE) {
		return 0;
	} else {
		$init($Long);
		$init($Double);
		if (c == $Long::TYPE || c == $Double::TYPE) {
			return 2;
		}
	}
	return 1;
}

int32_t InnerClassLambdaMetafactory::getLoadOpcode($Class* c) {
	$init(InnerClassLambdaMetafactory);
	$init($Void);
	if (c == $Void::TYPE) {
		$throwNew($InternalError, "Unexpected void type of load opcode"_s);
	}
	return 21 + getOpcodeOffset(c);
}

int32_t InnerClassLambdaMetafactory::getReturnOpcode($Class* c) {
	$init(InnerClassLambdaMetafactory);
	$init($Void);
	if (c == $Void::TYPE) {
		return 177;
	}
	return 172 + getOpcodeOffset(c);
}

int32_t InnerClassLambdaMetafactory::getOpcodeOffset($Class* c) {
	$init(InnerClassLambdaMetafactory);
	if ($nc(c)->isPrimitive()) {
		$init($Long);
		if (c == $Long::TYPE) {
			return 1;
		} else {
			$init($Float);
			if (c == $Float::TYPE) {
				return 2;
			} else {
				$init($Double);
				if (c == $Double::TYPE) {
					return 3;
				}
			}
		}
		return 0;
	} else {
		return 4;
	}
}

void clinit$InnerClassLambdaMetafactory($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(InnerClassLambdaMetafactory::JAVA_LANG_OBJECT, "java/lang/Object"_s);
	$assignStatic(InnerClassLambdaMetafactory::NAME_CTOR, "<init>"_s);
	$assignStatic(InnerClassLambdaMetafactory::LAMBDA_INSTANCE_FIELD, "LAMBDA_INSTANCE$"_s);
	$assignStatic(InnerClassLambdaMetafactory::NAME_SERIALIZED_LAMBDA, "java/lang/invoke/SerializedLambda"_s);
	$assignStatic(InnerClassLambdaMetafactory::NAME_NOT_SERIALIZABLE_EXCEPTION, "java/io/NotSerializableException"_s);
	$assignStatic(InnerClassLambdaMetafactory::DESCR_METHOD_WRITE_REPLACE, "()Ljava/lang/Object;"_s);
	$assignStatic(InnerClassLambdaMetafactory::DESCR_METHOD_WRITE_OBJECT, "(Ljava/io/ObjectOutputStream;)V"_s);
	$assignStatic(InnerClassLambdaMetafactory::DESCR_METHOD_READ_OBJECT, "(Ljava/io/ObjectInputStream;)V"_s);
	$assignStatic(InnerClassLambdaMetafactory::NAME_METHOD_WRITE_REPLACE, "writeReplace"_s);
	$assignStatic(InnerClassLambdaMetafactory::NAME_METHOD_READ_OBJECT, "readObject"_s);
	$assignStatic(InnerClassLambdaMetafactory::NAME_METHOD_WRITE_OBJECT, "writeObject"_s);
	$assignStatic(InnerClassLambdaMetafactory::DESCR_CLASS, "Ljava/lang/Class;"_s);
	$assignStatic(InnerClassLambdaMetafactory::DESCR_STRING, "Ljava/lang/String;"_s);
	$assignStatic(InnerClassLambdaMetafactory::DESCR_OBJECT, "Ljava/lang/Object;"_s);
	$assignStatic(InnerClassLambdaMetafactory::DESCR_CTOR_SERIALIZED_LAMBDA, $str({"("_s, InnerClassLambdaMetafactory::DESCR_CLASS, InnerClassLambdaMetafactory::DESCR_STRING, InnerClassLambdaMetafactory::DESCR_STRING, InnerClassLambdaMetafactory::DESCR_STRING, "I"_s, InnerClassLambdaMetafactory::DESCR_STRING, InnerClassLambdaMetafactory::DESCR_STRING, InnerClassLambdaMetafactory::DESCR_STRING, InnerClassLambdaMetafactory::DESCR_STRING, "["_s, InnerClassLambdaMetafactory::DESCR_OBJECT, ")V"_s}));
	$assignStatic(InnerClassLambdaMetafactory::DESCR_CTOR_NOT_SERIALIZABLE_EXCEPTION, "(Ljava/lang/String;)V"_s);
	$var($String, dumpProxyClassesKey, "jdk.internal.lambda.dumpProxyClasses"_s);
	$var($String, disableEagerInitializationKey, "jdk.internal.lambda.disableEagerInitialization"_s);
	InnerClassLambdaMetafactory::$assertionsDisabled = !InnerClassLambdaMetafactory::class$->desiredAssertionStatus();
	$init($Type);
	$assignStatic(InnerClassLambdaMetafactory::METHOD_DESCRIPTOR_VOID, $Type::getMethodDescriptor($Type::VOID_TYPE, $$new($TypeArray, 0)));
	$assignStatic(InnerClassLambdaMetafactory::SER_HOSTILE_EXCEPTIONS, $new($StringArray, {InnerClassLambdaMetafactory::NAME_NOT_SERIALIZABLE_EXCEPTION}));
	$assignStatic(InnerClassLambdaMetafactory::EMPTY_STRING_ARRAY, $new($StringArray, 0));
	$assignStatic(InnerClassLambdaMetafactory::counter, $new($AtomicInteger));
	{
		$var($String, dumpProxyClassesKey, "jdk.internal.lambda.dumpProxyClasses"_s);
		$var($String, dumpPath, $GetPropertyAction::privilegedGetProperty(dumpProxyClassesKey));
		$assignStatic(InnerClassLambdaMetafactory::dumper, (nullptr == dumpPath) ? ($ProxyClassesDumper*)nullptr : $ProxyClassesDumper::getInstance(dumpPath));
		$var($String, disableEagerInitializationKey, "jdk.internal.lambda.disableEagerInitialization"_s);
		InnerClassLambdaMetafactory::disableEagerInitialization = $GetBooleanAction::privilegedGetProperty(disableEagerInitializationKey);
		$load($MethodHandles$Lookup);
		$var($MethodType, classDataMType, $MethodType::methodType($Object::class$, $MethodHandles$Lookup::class$, $$new($ClassArray, {
			$String::class$,
			$Class::class$
		})));
		$load($MethodHandles);
		$var($String, var$0, $Type::getInternalName($MethodHandles::class$));
		$var($String, var$1, "classData"_s);
		$var($Handle, classDataBsm, $new($Handle, 6, var$0, var$1, $($nc(classDataMType)->descriptorString()), false));
		$init($ConstantDescs);
		$load($MethodHandle);
		$assignStatic(InnerClassLambdaMetafactory::implMethodCondy, $new($ConstantDynamic, $ConstantDescs::DEFAULT_NAME, $($MethodHandle::class$->descriptorString()), classDataBsm, $$new($ObjectArray, 0)));
	}
}

InnerClassLambdaMetafactory::InnerClassLambdaMetafactory() {
}

$Class* InnerClassLambdaMetafactory::load$($String* name, bool initialize) {
	$loadClass(InnerClassLambdaMetafactory, name, initialize, &_InnerClassLambdaMetafactory_ClassInfo_, clinit$InnerClassLambdaMetafactory, allocate$InnerClassLambdaMetafactory);
	return class$;
}

$Class* InnerClassLambdaMetafactory::class$ = nullptr;

		} // invoke
	} // lang
} // java