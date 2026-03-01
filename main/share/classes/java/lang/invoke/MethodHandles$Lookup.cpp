#include <java/lang/invoke/MethodHandles$Lookup.h>

#include <java/lang/AssertionError.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/InternalError.h>
#include <java/lang/Module.h>
#include <java/lang/NoSuchFieldException.h>
#include <java/lang/NoSuchMethodException.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityException.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/invoke/BoundMethodHandle.h>
#include <java/lang/invoke/DirectMethodHandle.h>
#include <java/lang/invoke/InfoFromMemberName.h>
#include <java/lang/invoke/LambdaForm.h>
#include <java/lang/invoke/MemberName$Factory.h>
#include <java/lang/invoke/MemberName.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandleImpl.h>
#include <java/lang/invoke/MethodHandleInfo.h>
#include <java/lang/invoke/MethodHandleNatives.h>
#include <java/lang/invoke/MethodHandleStatics.h>
#include <java/lang/invoke/MethodHandles$Lookup$ClassDefiner.h>
#include <java/lang/invoke/MethodHandles$Lookup$ClassFile.h>
#include <java/lang/invoke/MethodHandles$Lookup$ClassOption.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/invoke/TypeDescriptor$OfField.h>
#include <java/lang/invoke/VarHandle$AccessMode.h>
#include <java/lang/invoke/VarHandle.h>
#include <java/lang/invoke/VarHandles.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Field.h>
#include <java/lang/reflect/Method.h>
#include <java/lang/reflect/Modifier.h>
#include <java/security/Permission.h>
#include <java/security/ProtectionDomain.h>
#include <java/util/Objects.h>
#include <java/util/Set.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <jdk/internal/access/JavaLangAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jdk/internal/misc/Unsafe.h>
#include <jdk/internal/misc/VM.h>
#include <jdk/internal/reflect/Reflection.h>
#include <sun/invoke/util/VerifyAccess.h>
#include <sun/reflect/misc/ReflectUtil.h>
#include <sun/security/util/SecurityConstants.h>
#include <jcpp.h>

#undef ALL_MODES
#undef CHECK_MEMBER_ACCESS_PERMISSION
#undef FULL_POWER_MODES
#undef GET_CLASSLOADER_PERMISSION
#undef IMPL_LOOKUP
#undef IMPL_NAMES
#undef LOOKASIDE_TABLE
#undef MODULE
#undef ORIGINAL
#undef PACKAGE
#undef PRIVATE
#undef PROTECTED
#undef PUBLIC
#undef PUBLIC_LOOKUP
#undef TRUSTED
#undef UNCONDITIONAL

using $MethodHandles$Lookup$ClassOptionArray = $Array<::java::lang::invoke::MethodHandles$Lookup$ClassOption>;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $Module = ::java::lang::Module;
using $NamedAttribute = ::java::lang::NamedAttribute;
using $NoSuchFieldException = ::java::lang::NoSuchFieldException;
using $NoSuchMethodException = ::java::lang::NoSuchMethodException;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityException = ::java::lang::SecurityException;
using $SecurityManager = ::java::lang::SecurityManager;
using $BoundMethodHandle = ::java::lang::invoke::BoundMethodHandle;
using $DirectMethodHandle = ::java::lang::invoke::DirectMethodHandle;
using $InfoFromMemberName = ::java::lang::invoke::InfoFromMemberName;
using $MemberName = ::java::lang::invoke::MemberName;
using $MemberName$Factory = ::java::lang::invoke::MemberName$Factory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandleImpl = ::java::lang::invoke::MethodHandleImpl;
using $MethodHandleInfo = ::java::lang::invoke::MethodHandleInfo;
using $MethodHandleNatives = ::java::lang::invoke::MethodHandleNatives;
using $MethodHandleStatics = ::java::lang::invoke::MethodHandleStatics;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup$ClassDefiner = ::java::lang::invoke::MethodHandles$Lookup$ClassDefiner;
using $MethodHandles$Lookup$ClassFile = ::java::lang::invoke::MethodHandles$Lookup$ClassFile;
using $MethodHandles$Lookup$ClassOption = ::java::lang::invoke::MethodHandles$Lookup$ClassOption;
using $MethodType = ::java::lang::invoke::MethodType;
using $VarHandle = ::java::lang::invoke::VarHandle;
using $VarHandle$AccessMode = ::java::lang::invoke::VarHandle$AccessMode;
using $VarHandles = ::java::lang::invoke::VarHandles;
using $Constructor = ::java::lang::reflect::Constructor;
using $Field = ::java::lang::reflect::Field;
using $Method = ::java::lang::reflect::Method;
using $Modifier = ::java::lang::reflect::Modifier;
using $Permission = ::java::security::Permission;
using $ProtectionDomain = ::java::security::ProtectionDomain;
using $Objects = ::java::util::Objects;
using $Set = ::java::util::Set;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $JavaLangAccess = ::jdk::internal::access::JavaLangAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $Unsafe = ::jdk::internal::misc::Unsafe;
using $VM = ::jdk::internal::misc::VM;
using $Reflection = ::jdk::internal::reflect::Reflection;
using $VerifyAccess = ::sun::invoke::util::VerifyAccess;
using $ReflectUtil = ::sun::reflect::misc::ReflectUtil;
using $SecurityConstants = ::sun::security::util::SecurityConstants;

namespace java {
	namespace lang {
		namespace invoke {

$NamedAttribute MethodHandles$Lookup_Attribute_var$0[] = {
	{"since", 's', "14"},
	{}
};

$CompoundAttribute _MethodHandles$Lookup_MethodAnnotations_hasPrivateAccess51[] = {
	{"Ljava/lang/Deprecated;", MethodHandles$Lookup_Attribute_var$0},
	{}
};

$FieldInfo _MethodHandles$Lookup_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(MethodHandles$Lookup, $assertionsDisabled)},
	{"lookupClass", "Ljava/lang/Class;", "Ljava/lang/Class<*>;", $PRIVATE | $FINAL, $field(MethodHandles$Lookup, lookupClass$)},
	{"prevLookupClass", "Ljava/lang/Class;", "Ljava/lang/Class<*>;", $PRIVATE | $FINAL, $field(MethodHandles$Lookup, prevLookupClass)},
	{"allowedModes", "I", nullptr, $PRIVATE | $FINAL, $field(MethodHandles$Lookup, allowedModes)},
	{"PUBLIC", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(MethodHandles$Lookup, PUBLIC)},
	{"PRIVATE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(MethodHandles$Lookup, PRIVATE)},
	{"PROTECTED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(MethodHandles$Lookup, PROTECTED)},
	{"PACKAGE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(MethodHandles$Lookup, PACKAGE)},
	{"MODULE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(MethodHandles$Lookup, MODULE)},
	{"UNCONDITIONAL", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(MethodHandles$Lookup, UNCONDITIONAL)},
	{"ORIGINAL", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(MethodHandles$Lookup, ORIGINAL)},
	{"ALL_MODES", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MethodHandles$Lookup, ALL_MODES)},
	{"FULL_POWER_MODES", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MethodHandles$Lookup, FULL_POWER_MODES)},
	{"TRUSTED", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MethodHandles$Lookup, TRUSTED)},
	{"cachedProtectionDomain", "Ljava/security/ProtectionDomain;", nullptr, $PRIVATE | $VOLATILE, $field(MethodHandles$Lookup, cachedProtectionDomain)},
	{"IMPL_LOOKUP", "Ljava/lang/invoke/MethodHandles$Lookup;", nullptr, $STATIC | $FINAL, $staticField(MethodHandles$Lookup, IMPL_LOOKUP)},
	{"PUBLIC_LOOKUP", "Ljava/lang/invoke/MethodHandles$Lookup;", nullptr, $STATIC | $FINAL, $staticField(MethodHandles$Lookup, PUBLIC_LOOKUP)},
	{"LOOKASIDE_TABLE", "Ljava/util/concurrent/ConcurrentHashMap;", "Ljava/util/concurrent/ConcurrentHashMap<Ljava/lang/invoke/MemberName;Ljava/lang/invoke/DirectMethodHandle;>;", $STATIC, $staticField(MethodHandles$Lookup, LOOKASIDE_TABLE)},
	{}
};

$MethodInfo _MethodHandles$Lookup_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/Class;)V", "(Ljava/lang/Class<*>;)V", 0, $method(MethodHandles$Lookup, init$, void, $Class*)},
	{"<init>", "(Ljava/lang/Class;Ljava/lang/Class;I)V", "(Ljava/lang/Class<*>;Ljava/lang/Class<*>;I)V", $PRIVATE, $method(MethodHandles$Lookup, init$, void, $Class*, $Class*, int32_t)},
	{"accessClass", "(Ljava/lang/Class;)Ljava/lang/Class;", "(Ljava/lang/Class<*>;)Ljava/lang/Class<*>;", $PUBLIC, $method(MethodHandles$Lookup, accessClass, $Class*, $Class*), "java.lang.IllegalAccessException"},
	{"accessFailedMessage", "(Ljava/lang/Class;Ljava/lang/invoke/MemberName;)Ljava/lang/String;", "(Ljava/lang/Class<*>;Ljava/lang/invoke/MemberName;)Ljava/lang/String;", 0, $method(MethodHandles$Lookup, accessFailedMessage, $String*, $Class*, $MemberName*)},
	{"bind", "(Ljava/lang/Object;Ljava/lang/String;Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/MethodHandle;", nullptr, $PUBLIC, $method(MethodHandles$Lookup, bind, $MethodHandle*, Object$*, $String*, $MethodType*), "java.lang.NoSuchMethodException,java.lang.IllegalAccessException"},
	{"canBeCached", "(BLjava/lang/Class;Ljava/lang/invoke/MemberName;)Z", "(BLjava/lang/Class<*>;Ljava/lang/invoke/MemberName;)Z", $PRIVATE, $method(MethodHandles$Lookup, canBeCached, bool, int8_t, $Class*, $MemberName*)},
	{"checkAccess", "(BLjava/lang/Class;Ljava/lang/invoke/MemberName;)V", "(BLjava/lang/Class<*>;Ljava/lang/invoke/MemberName;)V", 0, $method(MethodHandles$Lookup, checkAccess, void, int8_t, $Class*, $MemberName*), "java.lang.IllegalAccessException"},
	{"checkField", "(BLjava/lang/Class;Ljava/lang/invoke/MemberName;)V", "(BLjava/lang/Class<*>;Ljava/lang/invoke/MemberName;)V", 0, $method(MethodHandles$Lookup, checkField, void, int8_t, $Class*, $MemberName*), "java.lang.IllegalAccessException"},
	{"checkMethod", "(BLjava/lang/Class;Ljava/lang/invoke/MemberName;)V", "(BLjava/lang/Class<*>;Ljava/lang/invoke/MemberName;)V", 0, $method(MethodHandles$Lookup, checkMethod, void, int8_t, $Class*, $MemberName*), "java.lang.IllegalAccessException"},
	{"checkMethodName", "(BLjava/lang/String;)V", nullptr, 0, $method(MethodHandles$Lookup, checkMethodName, void, int8_t, $String*), "java.lang.NoSuchMethodException"},
	{"checkSecurityManager", "(Ljava/lang/Class;)V", "(Ljava/lang/Class<*>;)V", 0, $method(MethodHandles$Lookup, checkSecurityManager, void, $Class*)},
	{"checkSecurityManager", "(Ljava/lang/Class;Ljava/lang/invoke/MemberName;)V", "(Ljava/lang/Class<*>;Ljava/lang/invoke/MemberName;)V", 0, $method(MethodHandles$Lookup, checkSecurityManager, void, $Class*, $MemberName*)},
	{"checkSpecialCaller", "(Ljava/lang/Class;Ljava/lang/Class;)V", "(Ljava/lang/Class<*>;Ljava/lang/Class<*>;)V", $PRIVATE, $method(MethodHandles$Lookup, checkSpecialCaller, void, $Class*, $Class*), "java.lang.IllegalAccessException"},
	{"checkSymbolicClass", "(Ljava/lang/Class;)V", "(Ljava/lang/Class<*>;)V", 0, $method(MethodHandles$Lookup, checkSymbolicClass, void, $Class*), "java.lang.IllegalAccessException"},
	{"checkUnprivilegedlookupClass", "(Ljava/lang/Class;)V", "(Ljava/lang/Class<*>;)V", $PRIVATE | $STATIC, $staticMethod(MethodHandles$Lookup, checkUnprivilegedlookupClass, void, $Class*)},
	{"defineClass", "([B)Ljava/lang/Class;", "([B)Ljava/lang/Class<*>;", $PUBLIC, $method(MethodHandles$Lookup, defineClass, $Class*, $bytes*), "java.lang.IllegalAccessException"},
	{"defineHiddenClass", "([BZ[Ljava/lang/invoke/MethodHandles$Lookup$ClassOption;)Ljava/lang/invoke/MethodHandles$Lookup;", nullptr, $PUBLIC | $TRANSIENT, $method(MethodHandles$Lookup, defineHiddenClass, MethodHandles$Lookup*, $bytes*, bool, $MethodHandles$Lookup$ClassOptionArray*), "java.lang.IllegalAccessException"},
	{"defineHiddenClassWithClassData", "([BLjava/lang/Object;Z[Ljava/lang/invoke/MethodHandles$Lookup$ClassOption;)Ljava/lang/invoke/MethodHandles$Lookup;", nullptr, $PUBLIC | $TRANSIENT, $method(MethodHandles$Lookup, defineHiddenClassWithClassData, MethodHandles$Lookup*, $bytes*, Object$*, bool, $MethodHandles$Lookup$ClassOptionArray*), "java.lang.IllegalAccessException"},
	{"dropLookupMode", "(I)Ljava/lang/invoke/MethodHandles$Lookup;", nullptr, $PUBLIC, $method(MethodHandles$Lookup, dropLookupMode, MethodHandles$Lookup*, int32_t)},
	{"ensureDefineClassPermission", "()V", nullptr, $PRIVATE, $method(MethodHandles$Lookup, ensureDefineClassPermission, void)},
	{"ensureInitialized", "(Ljava/lang/Class;)Ljava/lang/Class;", "(Ljava/lang/Class<*>;)Ljava/lang/Class<*>;", $PUBLIC, $method(MethodHandles$Lookup, ensureInitialized, $Class*, $Class*), "java.lang.IllegalAccessException"},
	{"findBoundCallerLookup", "(Ljava/lang/invoke/MemberName;)Ljava/lang/invoke/MethodHandles$Lookup;", nullptr, 0, $method(MethodHandles$Lookup, findBoundCallerLookup, MethodHandles$Lookup*, $MemberName*), "java.lang.IllegalAccessException"},
	{"findClass", "(Ljava/lang/String;)Ljava/lang/Class;", "(Ljava/lang/String;)Ljava/lang/Class<*>;", $PUBLIC, $method(MethodHandles$Lookup, findClass, $Class*, $String*), "java.lang.ClassNotFoundException,java.lang.IllegalAccessException"},
	{"findConstructor", "(Ljava/lang/Class;Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/Class<*>;Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/MethodHandle;", $PUBLIC, $method(MethodHandles$Lookup, findConstructor, $MethodHandle*, $Class*, $MethodType*), "java.lang.NoSuchMethodException,java.lang.IllegalAccessException"},
	{"findGetter", "(Ljava/lang/Class;Ljava/lang/String;Ljava/lang/Class;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/Class<*>;Ljava/lang/String;Ljava/lang/Class<*>;)Ljava/lang/invoke/MethodHandle;", $PUBLIC, $method(MethodHandles$Lookup, findGetter, $MethodHandle*, $Class*, $String*, $Class*), "java.lang.NoSuchFieldException,java.lang.IllegalAccessException"},
	{"findSetter", "(Ljava/lang/Class;Ljava/lang/String;Ljava/lang/Class;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/Class<*>;Ljava/lang/String;Ljava/lang/Class<*>;)Ljava/lang/invoke/MethodHandle;", $PUBLIC, $method(MethodHandles$Lookup, findSetter, $MethodHandle*, $Class*, $String*, $Class*), "java.lang.NoSuchFieldException,java.lang.IllegalAccessException"},
	{"findSpecial", "(Ljava/lang/Class;Ljava/lang/String;Ljava/lang/invoke/MethodType;Ljava/lang/Class;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/Class<*>;Ljava/lang/String;Ljava/lang/invoke/MethodType;Ljava/lang/Class<*>;)Ljava/lang/invoke/MethodHandle;", $PUBLIC, $method(MethodHandles$Lookup, findSpecial, $MethodHandle*, $Class*, $String*, $MethodType*, $Class*), "java.lang.NoSuchMethodException,java.lang.IllegalAccessException"},
	{"findStatic", "(Ljava/lang/Class;Ljava/lang/String;Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/Class<*>;Ljava/lang/String;Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/MethodHandle;", $PUBLIC, $method(MethodHandles$Lookup, findStatic, $MethodHandle*, $Class*, $String*, $MethodType*), "java.lang.NoSuchMethodException,java.lang.IllegalAccessException"},
	{"findStaticGetter", "(Ljava/lang/Class;Ljava/lang/String;Ljava/lang/Class;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/Class<*>;Ljava/lang/String;Ljava/lang/Class<*>;)Ljava/lang/invoke/MethodHandle;", $PUBLIC, $method(MethodHandles$Lookup, findStaticGetter, $MethodHandle*, $Class*, $String*, $Class*), "java.lang.NoSuchFieldException,java.lang.IllegalAccessException"},
	{"findStaticSetter", "(Ljava/lang/Class;Ljava/lang/String;Ljava/lang/Class;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/Class<*>;Ljava/lang/String;Ljava/lang/Class<*>;)Ljava/lang/invoke/MethodHandle;", $PUBLIC, $method(MethodHandles$Lookup, findStaticSetter, $MethodHandle*, $Class*, $String*, $Class*), "java.lang.NoSuchFieldException,java.lang.IllegalAccessException"},
	{"findStaticVarHandle", "(Ljava/lang/Class;Ljava/lang/String;Ljava/lang/Class;)Ljava/lang/invoke/VarHandle;", "(Ljava/lang/Class<*>;Ljava/lang/String;Ljava/lang/Class<*>;)Ljava/lang/invoke/VarHandle;", $PUBLIC, $method(MethodHandles$Lookup, findStaticVarHandle, $VarHandle*, $Class*, $String*, $Class*), "java.lang.NoSuchFieldException,java.lang.IllegalAccessException"},
	{"findVarHandle", "(Ljava/lang/Class;Ljava/lang/String;Ljava/lang/Class;)Ljava/lang/invoke/VarHandle;", "(Ljava/lang/Class<*>;Ljava/lang/String;Ljava/lang/Class<*>;)Ljava/lang/invoke/VarHandle;", $PUBLIC, $method(MethodHandles$Lookup, findVarHandle, $VarHandle*, $Class*, $String*, $Class*), "java.lang.NoSuchFieldException,java.lang.IllegalAccessException"},
	{"findVirtual", "(Ljava/lang/Class;Ljava/lang/String;Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/Class<*>;Ljava/lang/String;Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/MethodHandle;", $PUBLIC, $method(MethodHandles$Lookup, findVirtual, $MethodHandle*, $Class*, $String*, $MethodType*), "java.lang.NoSuchMethodException,java.lang.IllegalAccessException"},
	{"findVirtualForMH", "(Ljava/lang/String;Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE, $method(MethodHandles$Lookup, findVirtualForMH, $MethodHandle*, $String*, $MethodType*)},
	{"findVirtualForVH", "(Ljava/lang/String;Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE, $method(MethodHandles$Lookup, findVirtualForVH, $MethodHandle*, $String*, $MethodType*)},
	{"fixmods", "(I)I", nullptr, $PRIVATE | $STATIC, $staticMethod(MethodHandles$Lookup, fixmods, int32_t, int32_t)},
	{"getDirectConstructor", "(Ljava/lang/Class;Ljava/lang/invoke/MemberName;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/Class<*>;Ljava/lang/invoke/MemberName;)Ljava/lang/invoke/MethodHandle;", $PRIVATE, $method(MethodHandles$Lookup, getDirectConstructor, $MethodHandle*, $Class*, $MemberName*), "java.lang.IllegalAccessException"},
	{"getDirectConstructorCommon", "(Ljava/lang/Class;Ljava/lang/invoke/MemberName;Z)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/Class<*>;Ljava/lang/invoke/MemberName;Z)Ljava/lang/invoke/MethodHandle;", $PRIVATE, $method(MethodHandles$Lookup, getDirectConstructorCommon, $MethodHandle*, $Class*, $MemberName*, bool), "java.lang.IllegalAccessException"},
	{"getDirectConstructorNoSecurityManager", "(Ljava/lang/Class;Ljava/lang/invoke/MemberName;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/Class<*>;Ljava/lang/invoke/MemberName;)Ljava/lang/invoke/MethodHandle;", $PRIVATE, $method(MethodHandles$Lookup, getDirectConstructorNoSecurityManager, $MethodHandle*, $Class*, $MemberName*), "java.lang.IllegalAccessException"},
	{"getDirectField", "(BLjava/lang/Class;Ljava/lang/invoke/MemberName;)Ljava/lang/invoke/MethodHandle;", "(BLjava/lang/Class<*>;Ljava/lang/invoke/MemberName;)Ljava/lang/invoke/MethodHandle;", $PRIVATE, $method(MethodHandles$Lookup, getDirectField, $MethodHandle*, int8_t, $Class*, $MemberName*), "java.lang.IllegalAccessException"},
	{"getDirectFieldCommon", "(BLjava/lang/Class;Ljava/lang/invoke/MemberName;Z)Ljava/lang/invoke/MethodHandle;", "(BLjava/lang/Class<*>;Ljava/lang/invoke/MemberName;Z)Ljava/lang/invoke/MethodHandle;", $PRIVATE, $method(MethodHandles$Lookup, getDirectFieldCommon, $MethodHandle*, int8_t, $Class*, $MemberName*, bool), "java.lang.IllegalAccessException"},
	{"getDirectFieldNoSecurityManager", "(BLjava/lang/Class;Ljava/lang/invoke/MemberName;)Ljava/lang/invoke/MethodHandle;", "(BLjava/lang/Class<*>;Ljava/lang/invoke/MemberName;)Ljava/lang/invoke/MethodHandle;", $PRIVATE, $method(MethodHandles$Lookup, getDirectFieldNoSecurityManager, $MethodHandle*, int8_t, $Class*, $MemberName*), "java.lang.IllegalAccessException"},
	{"getDirectMethod", "(BLjava/lang/Class;Ljava/lang/invoke/MemberName;Ljava/lang/invoke/MethodHandles$Lookup;)Ljava/lang/invoke/MethodHandle;", "(BLjava/lang/Class<*>;Ljava/lang/invoke/MemberName;Ljava/lang/invoke/MethodHandles$Lookup;)Ljava/lang/invoke/MethodHandle;", $PRIVATE, $method(MethodHandles$Lookup, getDirectMethod, $MethodHandle*, int8_t, $Class*, $MemberName*, MethodHandles$Lookup*), "java.lang.IllegalAccessException"},
	{"getDirectMethodCommon", "(BLjava/lang/Class;Ljava/lang/invoke/MemberName;ZZLjava/lang/invoke/MethodHandles$Lookup;)Ljava/lang/invoke/MethodHandle;", "(BLjava/lang/Class<*>;Ljava/lang/invoke/MemberName;ZZLjava/lang/invoke/MethodHandles$Lookup;)Ljava/lang/invoke/MethodHandle;", $PRIVATE, $method(MethodHandles$Lookup, getDirectMethodCommon, $MethodHandle*, int8_t, $Class*, $MemberName*, bool, bool, MethodHandles$Lookup*), "java.lang.IllegalAccessException"},
	{"getDirectMethodForConstant", "(BLjava/lang/Class;Ljava/lang/invoke/MemberName;)Ljava/lang/invoke/MethodHandle;", "(BLjava/lang/Class<*>;Ljava/lang/invoke/MemberName;)Ljava/lang/invoke/MethodHandle;", $PRIVATE, $method(MethodHandles$Lookup, getDirectMethodForConstant, $MethodHandle*, int8_t, $Class*, $MemberName*), "java.lang.ReflectiveOperationException"},
	{"getDirectMethodNoRestrictInvokeSpecial", "(Ljava/lang/Class;Ljava/lang/invoke/MemberName;Ljava/lang/invoke/MethodHandles$Lookup;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/Class<*>;Ljava/lang/invoke/MemberName;Ljava/lang/invoke/MethodHandles$Lookup;)Ljava/lang/invoke/MethodHandle;", $PRIVATE, $method(MethodHandles$Lookup, getDirectMethodNoRestrictInvokeSpecial, $MethodHandle*, $Class*, $MemberName*, MethodHandles$Lookup*), "java.lang.IllegalAccessException"},
	{"getDirectMethodNoSecurityManager", "(BLjava/lang/Class;Ljava/lang/invoke/MemberName;Ljava/lang/invoke/MethodHandles$Lookup;)Ljava/lang/invoke/MethodHandle;", "(BLjava/lang/Class<*>;Ljava/lang/invoke/MemberName;Ljava/lang/invoke/MethodHandles$Lookup;)Ljava/lang/invoke/MethodHandle;", $PRIVATE, $method(MethodHandles$Lookup, getDirectMethodNoSecurityManager, $MethodHandle*, int8_t, $Class*, $MemberName*, MethodHandles$Lookup*), "java.lang.IllegalAccessException"},
	{"getFieldVarHandle", "(BBLjava/lang/Class;Ljava/lang/invoke/MemberName;Ljava/lang/invoke/MemberName;)Ljava/lang/invoke/VarHandle;", "(BBLjava/lang/Class<*>;Ljava/lang/invoke/MemberName;Ljava/lang/invoke/MemberName;)Ljava/lang/invoke/VarHandle;", $PRIVATE, $method(MethodHandles$Lookup, getFieldVarHandle, $VarHandle*, int8_t, int8_t, $Class*, $MemberName*, $MemberName*), "java.lang.IllegalAccessException"},
	{"getFieldVarHandleCommon", "(BBLjava/lang/Class;Ljava/lang/invoke/MemberName;Ljava/lang/invoke/MemberName;Z)Ljava/lang/invoke/VarHandle;", "(BBLjava/lang/Class<*>;Ljava/lang/invoke/MemberName;Ljava/lang/invoke/MemberName;Z)Ljava/lang/invoke/VarHandle;", $PRIVATE, $method(MethodHandles$Lookup, getFieldVarHandleCommon, $VarHandle*, int8_t, int8_t, $Class*, $MemberName*, $MemberName*, bool), "java.lang.IllegalAccessException"},
	{"getFieldVarHandleNoSecurityManager", "(BBLjava/lang/Class;Ljava/lang/invoke/MemberName;Ljava/lang/invoke/MemberName;)Ljava/lang/invoke/VarHandle;", "(BBLjava/lang/Class<*>;Ljava/lang/invoke/MemberName;Ljava/lang/invoke/MemberName;)Ljava/lang/invoke/VarHandle;", $PRIVATE, $method(MethodHandles$Lookup, getFieldVarHandleNoSecurityManager, $VarHandle*, int8_t, int8_t, $Class*, $MemberName*, $MemberName*), "java.lang.IllegalAccessException"},
	{"hasFullPrivilegeAccess", "()Z", nullptr, $PUBLIC, $method(MethodHandles$Lookup, hasFullPrivilegeAccess, bool)},
	{"hasPrivateAccess", "()Z", nullptr, $PUBLIC | $DEPRECATED, $method(MethodHandles$Lookup, hasPrivateAccess, bool), nullptr, nullptr, _MethodHandles$Lookup_MethodAnnotations_hasPrivateAccess51},
	{"in", "(Ljava/lang/Class;)Ljava/lang/invoke/MethodHandles$Lookup;", "(Ljava/lang/Class<*>;)Ljava/lang/invoke/MethodHandles$Lookup;", $PUBLIC, $method(MethodHandles$Lookup, in, MethodHandles$Lookup*, $Class*)},
	{"isClassAccessible", "(Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;)Z", 0, $method(MethodHandles$Lookup, isClassAccessible, bool, $Class*)},
	{"linkMethodHandleConstant", "(BLjava/lang/Class;Ljava/lang/String;Ljava/lang/Object;)Ljava/lang/invoke/MethodHandle;", "(BLjava/lang/Class<*>;Ljava/lang/String;Ljava/lang/Object;)Ljava/lang/invoke/MethodHandle;", 0, $method(MethodHandles$Lookup, linkMethodHandleConstant, $MethodHandle*, int8_t, $Class*, $String*, Object$*), "java.lang.ReflectiveOperationException"},
	{"lookupClass", "()Ljava/lang/Class;", "()Ljava/lang/Class<*>;", $PUBLIC, $method(MethodHandles$Lookup, lookupClass, $Class*)},
	{"lookupClassOrNull", "()Ljava/lang/Class;", "()Ljava/lang/Class<*>;", $PRIVATE, $method(MethodHandles$Lookup, lookupClassOrNull, $Class*)},
	{"lookupClassProtectionDomain", "()Ljava/security/ProtectionDomain;", nullptr, $PRIVATE, $method(MethodHandles$Lookup, lookupClassProtectionDomain, $ProtectionDomain*)},
	{"lookupModes", "()I", nullptr, $PUBLIC, $method(MethodHandles$Lookup, lookupModes, int32_t)},
	{"makeAccessException", "(Ljava/lang/Class;)Ljava/lang/IllegalAccessException;", "(Ljava/lang/Class<*>;)Ljava/lang/IllegalAccessException;", $PRIVATE, $method(MethodHandles$Lookup, makeAccessException, $IllegalAccessException*, $Class*)},
	{"makeClassDefiner", "([B)Ljava/lang/invoke/MethodHandles$Lookup$ClassDefiner;", nullptr, $PRIVATE, $method(MethodHandles$Lookup, makeClassDefiner, $MethodHandles$Lookup$ClassDefiner*, $bytes*)},
	{"makeHiddenClassDefiner", "([B)Ljava/lang/invoke/MethodHandles$Lookup$ClassDefiner;", nullptr, 0, $method(MethodHandles$Lookup, makeHiddenClassDefiner, $MethodHandles$Lookup$ClassDefiner*, $bytes*)},
	{"makeHiddenClassDefiner", "([BLjava/util/Set;Z)Ljava/lang/invoke/MethodHandles$Lookup$ClassDefiner;", "([BLjava/util/Set<Ljava/lang/invoke/MethodHandles$Lookup$ClassOption;>;Z)Ljava/lang/invoke/MethodHandles$Lookup$ClassDefiner;", 0, $method(MethodHandles$Lookup, makeHiddenClassDefiner, $MethodHandles$Lookup$ClassDefiner*, $bytes*, $Set*, bool)},
	{"makeHiddenClassDefiner", "(Ljava/lang/String;[B)Ljava/lang/invoke/MethodHandles$Lookup$ClassDefiner;", nullptr, 0, $method(MethodHandles$Lookup, makeHiddenClassDefiner, $MethodHandles$Lookup$ClassDefiner*, $String*, $bytes*)},
	{"makeHiddenClassDefiner", "(Ljava/lang/invoke/MethodHandles$Lookup$ClassFile;Ljava/util/Set;Z)Ljava/lang/invoke/MethodHandles$Lookup$ClassDefiner;", "(Ljava/lang/invoke/MethodHandles$Lookup$ClassFile;Ljava/util/Set<Ljava/lang/invoke/MethodHandles$Lookup$ClassOption;>;Z)Ljava/lang/invoke/MethodHandles$Lookup$ClassDefiner;", $PRIVATE, $method(MethodHandles$Lookup, makeHiddenClassDefiner, $MethodHandles$Lookup$ClassDefiner*, $MethodHandles$Lookup$ClassFile*, $Set*, bool)},
	{"maybeBindCaller", "(Ljava/lang/invoke/MemberName;Ljava/lang/invoke/MethodHandle;Ljava/lang/invoke/MethodHandles$Lookup;)Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE, $method(MethodHandles$Lookup, maybeBindCaller, $MethodHandle*, $MemberName*, $MethodHandle*, MethodHandles$Lookup*), "java.lang.IllegalAccessException"},
	{"newLookup", "(Ljava/lang/Class;Ljava/lang/Class;I)Ljava/lang/invoke/MethodHandles$Lookup;", "(Ljava/lang/Class<*>;Ljava/lang/Class<*>;I)Ljava/lang/invoke/MethodHandles$Lookup;", $PRIVATE | $STATIC, $staticMethod(MethodHandles$Lookup, newLookup, MethodHandles$Lookup*, $Class*, $Class*, int32_t)},
	{"previousLookupClass", "()Ljava/lang/Class;", "()Ljava/lang/Class<*>;", $PUBLIC, $method(MethodHandles$Lookup, previousLookupClass, $Class*)},
	{"resolveOrFail", "(BLjava/lang/Class;Ljava/lang/String;Ljava/lang/Class;)Ljava/lang/invoke/MemberName;", "(BLjava/lang/Class<*>;Ljava/lang/String;Ljava/lang/Class<*>;)Ljava/lang/invoke/MemberName;", 0, $method(MethodHandles$Lookup, resolveOrFail, $MemberName*, int8_t, $Class*, $String*, $Class*), "java.lang.NoSuchFieldException,java.lang.IllegalAccessException"},
	{"resolveOrFail", "(BLjava/lang/Class;Ljava/lang/String;Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/MemberName;", "(BLjava/lang/Class<*>;Ljava/lang/String;Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/MemberName;", 0, $method(MethodHandles$Lookup, resolveOrFail, $MemberName*, int8_t, $Class*, $String*, $MethodType*), "java.lang.NoSuchMethodException,java.lang.IllegalAccessException"},
	{"resolveOrFail", "(BLjava/lang/invoke/MemberName;)Ljava/lang/invoke/MemberName;", nullptr, 0, $method(MethodHandles$Lookup, resolveOrFail, $MemberName*, int8_t, $MemberName*), "java.lang.ReflectiveOperationException"},
	{"resolveOrNull", "(BLjava/lang/invoke/MemberName;)Ljava/lang/invoke/MemberName;", nullptr, 0, $method(MethodHandles$Lookup, resolveOrNull, $MemberName*, int8_t, $MemberName*)},
	{"resolveOrNull", "(BLjava/lang/Class;Ljava/lang/String;Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/MemberName;", "(BLjava/lang/Class<*>;Ljava/lang/String;Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/MemberName;", 0, $method(MethodHandles$Lookup, resolveOrNull, $MemberName*, int8_t, $Class*, $String*, $MethodType*)},
	{"restrictProtectedReceiver", "(Ljava/lang/invoke/MemberName;)Z", nullptr, $PRIVATE, $method(MethodHandles$Lookup, restrictProtectedReceiver, bool, $MemberName*)},
	{"restrictReceiver", "(Ljava/lang/invoke/MemberName;Ljava/lang/invoke/DirectMethodHandle;Ljava/lang/Class;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/invoke/MemberName;Ljava/lang/invoke/DirectMethodHandle;Ljava/lang/Class<*>;)Ljava/lang/invoke/MethodHandle;", $PRIVATE, $method(MethodHandles$Lookup, restrictReceiver, $MethodHandle*, $MemberName*, $DirectMethodHandle*, $Class*), "java.lang.IllegalAccessException"},
	{"revealDirect", "(Ljava/lang/invoke/MethodHandle;)Ljava/lang/invoke/MethodHandleInfo;", nullptr, $PUBLIC, $method(MethodHandles$Lookup, revealDirect, $MethodHandleInfo*, $MethodHandle*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(MethodHandles$Lookup, toString, $String*)},
	{"unreflect", "(Ljava/lang/reflect/Method;)Ljava/lang/invoke/MethodHandle;", nullptr, $PUBLIC, $method(MethodHandles$Lookup, unreflect, $MethodHandle*, $Method*), "java.lang.IllegalAccessException"},
	{"unreflectConstructor", "(Ljava/lang/reflect/Constructor;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/reflect/Constructor<*>;)Ljava/lang/invoke/MethodHandle;", $PUBLIC, $method(MethodHandles$Lookup, unreflectConstructor, $MethodHandle*, $Constructor*), "java.lang.IllegalAccessException"},
	{"unreflectField", "(Ljava/lang/reflect/Field;Z)Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE, $method(MethodHandles$Lookup, unreflectField, $MethodHandle*, $Field*, bool), "java.lang.IllegalAccessException"},
	{"unreflectForMH", "(Ljava/lang/reflect/Method;)Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE, $method(MethodHandles$Lookup, unreflectForMH, $MethodHandle*, $Method*)},
	{"unreflectForVH", "(Ljava/lang/reflect/Method;)Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE, $method(MethodHandles$Lookup, unreflectForVH, $MethodHandle*, $Method*)},
	{"unreflectGetter", "(Ljava/lang/reflect/Field;)Ljava/lang/invoke/MethodHandle;", nullptr, $PUBLIC, $method(MethodHandles$Lookup, unreflectGetter, $MethodHandle*, $Field*), "java.lang.IllegalAccessException"},
	{"unreflectSetter", "(Ljava/lang/reflect/Field;)Ljava/lang/invoke/MethodHandle;", nullptr, $PUBLIC, $method(MethodHandles$Lookup, unreflectSetter, $MethodHandle*, $Field*), "java.lang.IllegalAccessException"},
	{"unreflectSpecial", "(Ljava/lang/reflect/Method;Ljava/lang/Class;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/reflect/Method;Ljava/lang/Class<*>;)Ljava/lang/invoke/MethodHandle;", $PUBLIC, $method(MethodHandles$Lookup, unreflectSpecial, $MethodHandle*, $Method*, $Class*), "java.lang.IllegalAccessException"},
	{"unreflectVarHandle", "(Ljava/lang/reflect/Field;)Ljava/lang/invoke/VarHandle;", nullptr, $PUBLIC, $method(MethodHandles$Lookup, unreflectVarHandle, $VarHandle*, $Field*), "java.lang.IllegalAccessException"},
	{}
};

$InnerClassInfo _MethodHandles$Lookup_InnerClassesInfo_[] = {
	{"java.lang.invoke.MethodHandles$Lookup", "java.lang.invoke.MethodHandles", "Lookup", $PUBLIC | $STATIC | $FINAL},
	{"java.lang.invoke.MethodHandles$Lookup$ClassDefiner", "java.lang.invoke.MethodHandles$Lookup", "ClassDefiner", $STATIC},
	{"java.lang.invoke.MethodHandles$Lookup$ClassFile", "java.lang.invoke.MethodHandles$Lookup", "ClassFile", $STATIC},
	{"java.lang.invoke.MethodHandles$Lookup$ClassOption", "java.lang.invoke.MethodHandles$Lookup", "ClassOption", $PUBLIC | $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _MethodHandles$Lookup_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.lang.invoke.MethodHandles$Lookup",
	"java.lang.Object",
	nullptr,
	_MethodHandles$Lookup_FieldInfo_,
	_MethodHandles$Lookup_MethodInfo_,
	nullptr,
	nullptr,
	_MethodHandles$Lookup_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.lang.invoke.MethodHandles"
};

$Object* allocate$MethodHandles$Lookup($Class* clazz) {
	return $of($alloc(MethodHandles$Lookup));
}

bool MethodHandles$Lookup::$assertionsDisabled = false;
MethodHandles$Lookup* MethodHandles$Lookup::IMPL_LOOKUP = nullptr;
MethodHandles$Lookup* MethodHandles$Lookup::PUBLIC_LOOKUP = nullptr;
$ConcurrentHashMap* MethodHandles$Lookup::LOOKASIDE_TABLE = nullptr;

int32_t MethodHandles$Lookup::fixmods(int32_t mods) {
	$init(MethodHandles$Lookup);
	mods &= (uint32_t)(MethodHandles$Lookup::ALL_MODES - MethodHandles$Lookup::PACKAGE - MethodHandles$Lookup::MODULE - MethodHandles$Lookup::ORIGINAL - MethodHandles$Lookup::UNCONDITIONAL);
	if ($Modifier::isPublic(mods)) {
		mods |= MethodHandles$Lookup::UNCONDITIONAL;
	}
	return (mods != 0) ? mods : MethodHandles$Lookup::PACKAGE;
}

$Class* MethodHandles$Lookup::lookupClass() {
	return this->lookupClass$;
}

$Class* MethodHandles$Lookup::previousLookupClass() {
	return this->prevLookupClass;
}

$Class* MethodHandles$Lookup::lookupClassOrNull() {
	return (this->allowedModes == MethodHandles$Lookup::TRUSTED) ? ($Class*)nullptr : this->lookupClass$;
}

int32_t MethodHandles$Lookup::lookupModes() {
	return (int32_t)(this->allowedModes & (uint32_t)MethodHandles$Lookup::ALL_MODES);
}

void MethodHandles$Lookup::init$($Class* lookupClass) {
	MethodHandles$Lookup::init$(lookupClass, nullptr, MethodHandles$Lookup::FULL_POWER_MODES);
}

void MethodHandles$Lookup::init$($Class* lookupClass, $Class* prevLookupClass, int32_t allowedModes) {
	bool var$0 = !MethodHandles$Lookup::$assertionsDisabled;
	if (var$0) {
		bool var$1 = prevLookupClass == nullptr;
		if (!var$1) {
			bool var$2 = ((int32_t)(allowedModes & (uint32_t)MethodHandles$Lookup::MODULE)) == 0;
			if (var$2) {
				var$2 = $nc(prevLookupClass)->getModule() != $nc(lookupClass)->getModule();
			}
			var$1 = (var$2);
		}
		var$0 = !var$1;
	}
	if (var$0) {
		$throwNew($AssertionError);
	}
	bool var$3 = !MethodHandles$Lookup::$assertionsDisabled;
	if (var$3) {
		bool var$4 = !$nc(lookupClass)->isArray();
		var$3 = !(var$4 && !lookupClass->isPrimitive());
	}
	if (var$3) {
		$throwNew($AssertionError);
	}
	$set(this, lookupClass$, lookupClass);
	$set(this, prevLookupClass, prevLookupClass);
	this->allowedModes = allowedModes;
}

MethodHandles$Lookup* MethodHandles$Lookup::newLookup($Class* lookupClass, $Class* prevLookupClass, int32_t allowedModes) {
	$init(MethodHandles$Lookup);
	checkUnprivilegedlookupClass(lookupClass);
	return $new(MethodHandles$Lookup, lookupClass, prevLookupClass, allowedModes);
}

MethodHandles$Lookup* MethodHandles$Lookup::in($Class* requestedLookupClass) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(requestedLookupClass);
	if (requestedLookupClass->isPrimitive()) {
		$throwNew($IllegalArgumentException, $$str({requestedLookupClass, " is a primitive class"_s}));
	}
	if (requestedLookupClass->isArray()) {
		$throwNew($IllegalArgumentException, $$str({requestedLookupClass, " is an array class"_s}));
	}
	if (this->allowedModes == MethodHandles$Lookup::TRUSTED) {
		return $new(MethodHandles$Lookup, requestedLookupClass, nullptr, MethodHandles$Lookup::FULL_POWER_MODES);
	}
	if (requestedLookupClass == this->lookupClass$) {
		return this;
	}
	int32_t newModes = (int32_t)(((int32_t)(this->allowedModes & (uint32_t)MethodHandles$Lookup::FULL_POWER_MODES)) & (uint32_t)~MethodHandles$Lookup::ORIGINAL);
	$var($Module, fromModule, $nc(this->lookupClass$)->getModule());
	$var($Module, targetModule, requestedLookupClass->getModule());
	$Class* plc = this->previousLookupClass();
	if (((int32_t)(this->allowedModes & (uint32_t)MethodHandles$Lookup::UNCONDITIONAL)) != 0) {
		if (!MethodHandles$Lookup::$assertionsDisabled && !(plc == nullptr)) {
			$throwNew($AssertionError);
		}
		newModes = MethodHandles$Lookup::UNCONDITIONAL;
	} else if (fromModule != targetModule) {
		if (plc != nullptr && !$VerifyAccess::isSameModule(plc, requestedLookupClass)) {
			newModes = 0;
		}
		newModes &= (uint32_t)~(((MethodHandles$Lookup::MODULE | MethodHandles$Lookup::PACKAGE) | MethodHandles$Lookup::PRIVATE) | MethodHandles$Lookup::PROTECTED);
		plc = this->lookupClass$;
	}
	if (((int32_t)(newModes & (uint32_t)MethodHandles$Lookup::PACKAGE)) != 0 && !$VerifyAccess::isSamePackage(this->lookupClass$, requestedLookupClass)) {
		newModes &= (uint32_t)~((MethodHandles$Lookup::PACKAGE | MethodHandles$Lookup::PRIVATE) | MethodHandles$Lookup::PROTECTED);
	}
	if (((int32_t)(newModes & (uint32_t)MethodHandles$Lookup::PRIVATE)) != 0 && !$VerifyAccess::isSamePackageMember(this->lookupClass$, requestedLookupClass)) {
		newModes &= (uint32_t)~(MethodHandles$Lookup::PRIVATE | MethodHandles$Lookup::PROTECTED);
	}
	if (((int32_t)(newModes & (uint32_t)(MethodHandles$Lookup::PUBLIC | MethodHandles$Lookup::UNCONDITIONAL))) != 0 && !$VerifyAccess::isClassAccessible(requestedLookupClass, this->lookupClass$, this->prevLookupClass, this->allowedModes)) {
		newModes = 0;
	}
	return newLookup(requestedLookupClass, plc, newModes);
}

MethodHandles$Lookup* MethodHandles$Lookup::dropLookupMode(int32_t modeToDrop) {
	$useLocalCurrentObjectStackCache();
	int32_t oldModes = lookupModes();
	int32_t newModes = (int32_t)(oldModes & (uint32_t)~((modeToDrop | MethodHandles$Lookup::PROTECTED) | MethodHandles$Lookup::ORIGINAL));
	switch (modeToDrop) {
	case MethodHandles$Lookup::PUBLIC:
		{
			newModes &= (uint32_t)~(MethodHandles$Lookup::FULL_POWER_MODES);
			break;
		}
	case MethodHandles$Lookup::MODULE:
		{
			newModes &= (uint32_t)~(MethodHandles$Lookup::PACKAGE | MethodHandles$Lookup::PRIVATE);
			break;
		}
	case MethodHandles$Lookup::PACKAGE:
		{
			newModes &= (uint32_t)~(MethodHandles$Lookup::PRIVATE);
			break;
		}
	case MethodHandles$Lookup::PROTECTED:
		{}
	case MethodHandles$Lookup::PRIVATE:
		{}
	case MethodHandles$Lookup::ORIGINAL:
		{}
	case MethodHandles$Lookup::UNCONDITIONAL:
		{
			break;
		}
	default:
		{
			$throwNew($IllegalArgumentException, $$str({$$str(modeToDrop), " is not a valid mode to drop"_s}));
		}
	}
	if (newModes == oldModes) {
		return this;
	}
	$Class* var$0 = lookupClass();
	return newLookup(var$0, previousLookupClass(), newModes);
}

$Class* MethodHandles$Lookup::defineClass($bytes* bytes) {
	$useLocalCurrentObjectStackCache();
	ensureDefineClassPermission();
	if (((int32_t)(lookupModes() & (uint32_t)MethodHandles$Lookup::PACKAGE)) == 0) {
		$throwNew($IllegalAccessException, "Lookup does not have PACKAGE access"_s);
	}
	return $nc($(makeClassDefiner($cast($bytes, $($nc(bytes)->clone())))))->defineClass(false);
}

void MethodHandles$Lookup::ensureDefineClassPermission() {
	$useLocalCurrentObjectStackCache();
	if (this->allowedModes == MethodHandles$Lookup::TRUSTED) {
		return;
	}
	if (!hasFullPrivilegeAccess()) {
		$var($SecurityManager, sm, $System::getSecurityManager());
		if (sm != nullptr) {
			sm->checkPermission($$new($RuntimePermission, "defineClass"_s));
		}
	}
}

MethodHandles$Lookup* MethodHandles$Lookup::defineHiddenClass($bytes* bytes, bool initialize, $MethodHandles$Lookup$ClassOptionArray* options) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(bytes);
	$Objects::requireNonNull(options);
	ensureDefineClassPermission();
	if (!hasFullPrivilegeAccess()) {
		$throwNew($IllegalAccessException, $$str({this, " does not have full privilege access"_s}));
	}
	$var($bytes, var$0, $cast($bytes, bytes->clone()));
	return $nc($(makeHiddenClassDefiner(var$0, $($Set::of(options)), false)))->defineClassAsLookup(initialize);
}

MethodHandles$Lookup* MethodHandles$Lookup::defineHiddenClassWithClassData($bytes* bytes, Object$* classData, bool initialize, $MethodHandles$Lookup$ClassOptionArray* options) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(bytes);
	$Objects::requireNonNull(classData);
	$Objects::requireNonNull(options);
	ensureDefineClassPermission();
	if (!hasFullPrivilegeAccess()) {
		$throwNew($IllegalAccessException, $$str({this, " does not have full privilege access"_s}));
	}
	$var($bytes, var$0, $cast($bytes, bytes->clone()));
	return $nc($(makeHiddenClassDefiner(var$0, $($Set::of(options)), false)))->defineClassAsLookup(initialize, classData);
}

$MethodHandles$Lookup$ClassDefiner* MethodHandles$Lookup::makeClassDefiner($bytes* bytes) {
	$useLocalCurrentObjectStackCache();
	$var($MethodHandles$Lookup$ClassFile, cf, $MethodHandles$Lookup$ClassFile::newInstance(bytes, $($nc(lookupClass())->getPackageName())));
	return $new($MethodHandles$Lookup$ClassDefiner, this, cf, 4);
}

$MethodHandles$Lookup$ClassDefiner* MethodHandles$Lookup::makeHiddenClassDefiner($bytes* bytes) {
	$useLocalCurrentObjectStackCache();
	$var($MethodHandles$Lookup$ClassFile, cf, $MethodHandles$Lookup$ClassFile::newInstance(bytes, $($nc(lookupClass())->getPackageName())));
	return makeHiddenClassDefiner(cf, $($Set::of()), false);
}

$MethodHandles$Lookup$ClassDefiner* MethodHandles$Lookup::makeHiddenClassDefiner($bytes* bytes, $Set* options, bool accessVmAnnotations) {
	$useLocalCurrentObjectStackCache();
	$var($MethodHandles$Lookup$ClassFile, cf, $MethodHandles$Lookup$ClassFile::newInstance(bytes, $($nc(lookupClass())->getPackageName())));
	return makeHiddenClassDefiner(cf, options, accessVmAnnotations);
}

$MethodHandles$Lookup$ClassDefiner* MethodHandles$Lookup::makeHiddenClassDefiner($String* name, $bytes* bytes) {
	$useLocalCurrentObjectStackCache();
	$var($MethodHandles$Lookup$ClassFile, var$0, $MethodHandles$Lookup$ClassFile::newInstanceNoCheck(name, bytes));
	return makeHiddenClassDefiner(var$0, $($Set::of()), false);
}

$MethodHandles$Lookup$ClassDefiner* MethodHandles$Lookup::makeHiddenClassDefiner($MethodHandles$Lookup$ClassFile* cf, $Set* options, bool accessVmAnnotations) {
	$beforeCallerSensitive();
	int32_t flags = 2 | $MethodHandles$Lookup$ClassOption::optionsToFlag(options);
	if (accessVmAnnotations | $VM::isSystemDomainLoader($($nc(this->lookupClass$)->getClassLoader()))) {
		flags |= 8;
	}
	return $new($MethodHandles$Lookup$ClassDefiner, this, cf, flags);
}

$ProtectionDomain* MethodHandles$Lookup::lookupClassProtectionDomain() {
	$useLocalCurrentObjectStackCache();
	$var($ProtectionDomain, pd, this->cachedProtectionDomain);
	if (pd == nullptr) {
		$set(this, cachedProtectionDomain, ($assign(pd, $nc($($SharedSecrets::getJavaLangAccess()))->protectionDomain(this->lookupClass$))));
	}
	return pd;
}

void MethodHandles$Lookup::checkUnprivilegedlookupClass($Class* lookupClass) {
	$init(MethodHandles$Lookup);
	$useLocalCurrentObjectStackCache();
	$var($String, name, $nc(lookupClass)->getName());
	if ($nc(name)->startsWith("java.lang.invoke."_s)) {
		$throw($($MethodHandleStatics::newIllegalArgumentException($$str({"illegal lookupClass: "_s, lookupClass}))));
	}
}

$String* MethodHandles$Lookup::toString() {
	$useLocalCurrentObjectStackCache();
	$var($String, cname, $nc(this->lookupClass$)->getName());
	if (this->prevLookupClass != nullptr) {
		$plusAssign(cname, $$str({"/"_s, $($nc(this->prevLookupClass)->getName())}));
	}
	do {
		if (this->allowedModes == 0) {
			goto case$0;
		}
		if (this->allowedModes == MethodHandles$Lookup::UNCONDITIONAL) {
			goto case$1;
		}
		if (this->allowedModes == MethodHandles$Lookup::PUBLIC) {
			goto case$2;
		}
		if (this->allowedModes == (MethodHandles$Lookup::PUBLIC | MethodHandles$Lookup::MODULE)) {
			goto case$3;
		}
		if (this->allowedModes == (MethodHandles$Lookup::PUBLIC | MethodHandles$Lookup::PACKAGE)) {
			goto case$4;
		}
		if (this->allowedModes == ((MethodHandles$Lookup::PUBLIC | MethodHandles$Lookup::MODULE) | MethodHandles$Lookup::PACKAGE)) {
			goto case$5;
		}
		if (this->allowedModes == ((MethodHandles$Lookup::PUBLIC | MethodHandles$Lookup::PACKAGE) | MethodHandles$Lookup::PRIVATE)) {
			goto case$6;
		}
		if (this->allowedModes == (((MethodHandles$Lookup::PUBLIC | MethodHandles$Lookup::MODULE) | MethodHandles$Lookup::PACKAGE) | MethodHandles$Lookup::PRIVATE)) {
			goto case$7;
		}
		if (this->allowedModes == (((MethodHandles$Lookup::PUBLIC | MethodHandles$Lookup::PACKAGE) | MethodHandles$Lookup::PRIVATE) | MethodHandles$Lookup::PROTECTED)) {
			goto case$8;
		}
		if (this->allowedModes == ((((MethodHandles$Lookup::PUBLIC | MethodHandles$Lookup::MODULE) | MethodHandles$Lookup::PACKAGE) | MethodHandles$Lookup::PRIVATE) | MethodHandles$Lookup::PROTECTED)) {
			goto case$9;
		}
		if (this->allowedModes == MethodHandles$Lookup::FULL_POWER_MODES) {
			goto case$10;
		}
		if (this->allowedModes == MethodHandles$Lookup::TRUSTED) {
			goto case$11;
		}
		goto case$12;
case$0:
		// 0
		{
			return $str({cname, "/noaccess"_s});
		}
case$1:
		// UNCONDITIONAL
		{
			return $str({cname, "/publicLookup"_s});
		}
case$2:
		// PUBLIC
		{
			return $str({cname, "/public"_s});
		}
case$3:
		// PUBLIC | MODULE
		{
			return $str({cname, "/module"_s});
		}
case$4:
		// PUBLIC | PACKAGE
		{
		}
case$5:
		// PUBLIC | MODULE | PACKAGE
		{
			return $str({cname, "/package"_s});
		}
case$6:
		// PUBLIC | PACKAGE | PRIVATE
		{
		}
case$7:
		// PUBLIC | MODULE | PACKAGE | PRIVATE
		{
			return $str({cname, "/private"_s});
		}
case$8:
		// PUBLIC | PACKAGE | PRIVATE | PROTECTED
		{
		}
case$9:
		// PUBLIC | MODULE | PACKAGE | PRIVATE | PROTECTED
		{
		}
case$10:
		// FULL_POWER_MODES
		{
			return cname;
		}
case$11:
		// TRUSTED
		{
			return "/trusted"_s;
		}
case$12:
		// default
		{
			$assign(cname, $str({cname, "/"_s, $($Integer::toHexString(this->allowedModes))}));
			if (!MethodHandles$Lookup::$assertionsDisabled) {
				$throwNew($AssertionError, $of(cname));
			}
			return cname;
		}
	} while (false);
}

$MethodHandle* MethodHandles$Lookup::findStatic($Class* refc, $String* name, $MethodType* type) {
	$useLocalCurrentObjectStackCache();
	$var($MemberName, method, resolveOrFail((int8_t)6, refc, name, type));
	return getDirectMethod((int8_t)6, refc, method, $(findBoundCallerLookup(method)));
}

$MethodHandle* MethodHandles$Lookup::findVirtual($Class* refc, $String* name, $MethodType* type) {
	$useLocalCurrentObjectStackCache();
	$load($MethodHandle);
	if (refc == $MethodHandle::class$) {
		$var($MethodHandle, mh, findVirtualForMH(name, type));
		if (mh != nullptr) {
			return mh;
		}
	} else {
		$load($VarHandle);
		if (refc == $VarHandle::class$) {
			$var($MethodHandle, mh, findVirtualForVH(name, type));
			if (mh != nullptr) {
				return mh;
			}
		}
	}
	int8_t refKind = ($nc(refc)->isInterface() ? (int8_t)9 : (int8_t)5);
	$var($MemberName, method, resolveOrFail(refKind, refc, name, type));
	return getDirectMethod(refKind, refc, method, $(findBoundCallerLookup(method)));
}

$MethodHandle* MethodHandles$Lookup::findVirtualForMH($String* name, $MethodType* type) {
	if ("invoke"_s->equals(name)) {
		return $MethodHandles::invoker(type);
	}
	if ("invokeExact"_s->equals(name)) {
		return $MethodHandles::exactInvoker(type);
	}
	if (!MethodHandles$Lookup::$assertionsDisabled && !(!$MemberName::isMethodHandleInvokeName(name))) {
		$throwNew($AssertionError);
	}
	return nullptr;
}

$MethodHandle* MethodHandles$Lookup::findVirtualForVH($String* name, $MethodType* type) {
	try {
		return $MethodHandles::varHandleInvoker($($VarHandle$AccessMode::valueFromMethodName(name)), type);
	} catch ($IllegalArgumentException& e) {
		return nullptr;
	}
	$shouldNotReachHere();
}

$MethodHandle* MethodHandles$Lookup::findConstructor($Class* refc, $MethodType* type) {
	$useLocalCurrentObjectStackCache();
	if ($nc(refc)->isArray()) {
		$throwNew($NoSuchMethodException, $$str({"no constructor for array class: "_s, $(refc->getName())}));
	}
	$var($String, name, "<init>"_s);
	$var($MemberName, ctor, resolveOrFail((int8_t)8, refc, name, type));
	return getDirectConstructor(refc, ctor);
}

$Class* MethodHandles$Lookup::findClass($String* targetName) {
	$beforeCallerSensitive();
	$Class* targetClass = $Class::forName(targetName, false, $($nc(this->lookupClass$)->getClassLoader()));
	return accessClass(targetClass);
}

$Class* MethodHandles$Lookup::ensureInitialized($Class* targetClass) {
	$useLocalCurrentObjectStackCache();
	if ($nc(targetClass)->isPrimitive()) {
		$throwNew($IllegalArgumentException, $$str({targetClass, " is a primitive class"_s}));
	}
	if ($nc(targetClass)->isArray()) {
		$throwNew($IllegalArgumentException, $$str({targetClass, " is an array class"_s}));
	}
	if (!$VerifyAccess::isClassAccessible(targetClass, this->lookupClass$, this->prevLookupClass, this->allowedModes)) {
		$throw($(makeAccessException(targetClass)));
	}
	checkSecurityManager(targetClass);
	$nc($($Unsafe::getUnsafe()))->ensureClassInitialized(targetClass);
	return targetClass;
}

$IllegalAccessException* MethodHandles$Lookup::makeAccessException($Class* targetClass) {
	$useLocalCurrentObjectStackCache();
	$var($String, message, $str({"access violation: "_s, targetClass}));
	if (this == $MethodHandles::publicLookup()) {
		$plusAssign(message, ", from public Lookup"_s);
	} else {
		$var($Module, m, $nc(lookupClass())->getModule());
		$plusAssign(message, $$str({", from "_s, lookupClass(), " ("_s, m, ")"_s}));
		if (this->prevLookupClass != nullptr) {
			$var($String, var$1, $$str({", previous lookup "_s, $($nc(this->prevLookupClass)->getName()), " ("_s}));
			$var($String, var$0, $$concat(var$1, $($nc(this->prevLookupClass)->getModule())));
			$plusAssign(message, $$concat(var$0, ")"_s));
		}
	}
	return $new($IllegalAccessException, message);
}

$Class* MethodHandles$Lookup::accessClass($Class* targetClass) {
	if (!isClassAccessible(targetClass)) {
		$throw($(makeAccessException(targetClass)));
	}
	checkSecurityManager(targetClass);
	return targetClass;
}

$MethodHandle* MethodHandles$Lookup::findSpecial($Class* refc, $String* name, $MethodType* type, $Class* specialCaller) {
	$useLocalCurrentObjectStackCache();
	checkSpecialCaller(specialCaller, refc);
	$var(MethodHandles$Lookup, specialLookup, this->in(specialCaller));
	$var($MemberName, method, $nc(specialLookup)->resolveOrFail((int8_t)7, refc, name, type));
	return specialLookup->getDirectMethod((int8_t)7, refc, method, $(findBoundCallerLookup(method)));
}

$MethodHandle* MethodHandles$Lookup::findGetter($Class* refc, $String* name, $Class* type) {
	$var($MemberName, field, resolveOrFail((int8_t)1, refc, name, type));
	return getDirectField((int8_t)1, refc, field);
}

$MethodHandle* MethodHandles$Lookup::findSetter($Class* refc, $String* name, $Class* type) {
	$var($MemberName, field, resolveOrFail((int8_t)3, refc, name, type));
	return getDirectField((int8_t)3, refc, field);
}

$VarHandle* MethodHandles$Lookup::findVarHandle($Class* recv, $String* name, $Class* type) {
	$useLocalCurrentObjectStackCache();
	$var($MemberName, getField, resolveOrFail((int8_t)1, recv, name, type));
	$var($MemberName, putField, resolveOrFail((int8_t)3, recv, name, type));
	return getFieldVarHandle((int8_t)1, (int8_t)3, recv, getField, putField);
}

$MethodHandle* MethodHandles$Lookup::findStaticGetter($Class* refc, $String* name, $Class* type) {
	$var($MemberName, field, resolveOrFail((int8_t)2, refc, name, type));
	return getDirectField((int8_t)2, refc, field);
}

$MethodHandle* MethodHandles$Lookup::findStaticSetter($Class* refc, $String* name, $Class* type) {
	$var($MemberName, field, resolveOrFail((int8_t)4, refc, name, type));
	return getDirectField((int8_t)4, refc, field);
}

$VarHandle* MethodHandles$Lookup::findStaticVarHandle($Class* decl, $String* name, $Class* type) {
	$useLocalCurrentObjectStackCache();
	$var($MemberName, getField, resolveOrFail((int8_t)2, decl, name, type));
	$var($MemberName, putField, resolveOrFail((int8_t)4, decl, name, type));
	return getFieldVarHandle((int8_t)2, (int8_t)4, decl, getField, putField);
}

$MethodHandle* MethodHandles$Lookup::bind(Object$* receiver, $String* name, $MethodType* type) {
	$useLocalCurrentObjectStackCache();
	$Class* refc = $nc($of(receiver))->getClass();
	$var($MemberName, method, resolveOrFail((int8_t)7, refc, name, type));
	$var($MethodHandle, mh, getDirectMethodNoRestrictInvokeSpecial(refc, method, $(findBoundCallerLookup(method))));
	if (!$nc($nc($($nc(mh)->type()))->leadingReferenceParameter())->isAssignableFrom($of(receiver)->getClass())) {
		$var($String, var$0, $$str({"The restricted defining class "_s, $($nc($nc($(mh->type()))->leadingReferenceParameter())->getName()), " is not assignable from receiver class "_s}));
		$throwNew($IllegalAccessException, $$concat(var$0, $($of(receiver)->getClass()->getName())));
	}
	return $nc($($nc(mh)->bindArgumentL(0, receiver)))->setVarargs(method);
}

$MethodHandle* MethodHandles$Lookup::unreflect($Method* m) {
	$useLocalCurrentObjectStackCache();
	$load($MethodHandle);
	if ($nc(m)->getDeclaringClass() == $MethodHandle::class$) {
		$var($MethodHandle, mh, unreflectForMH(m));
		if (mh != nullptr) {
			return mh;
		}
	}
	$load($VarHandle);
	if ($nc(m)->getDeclaringClass() == $VarHandle::class$) {
		$var($MethodHandle, mh, unreflectForVH(m));
		if (mh != nullptr) {
			return mh;
		}
	}
	$var($MemberName, method, $new($MemberName, m));
	int8_t refKind = method->getReferenceKind();
	if (refKind == (int8_t)7) {
		refKind = (int8_t)5;
	}
	if (!MethodHandles$Lookup::$assertionsDisabled && !(method->isMethod())) {
		$throwNew($AssertionError);
	}
	$var(MethodHandles$Lookup, lookup, $nc(m)->isAccessible() ? MethodHandles$Lookup::IMPL_LOOKUP : this);
	int8_t var$0 = refKind;
	$Class* var$1 = method->getDeclaringClass();
	$var($MemberName, var$2, method);
	return $nc(lookup)->getDirectMethodNoSecurityManager(var$0, var$1, var$2, $(findBoundCallerLookup(method)));
}

$MethodHandle* MethodHandles$Lookup::unreflectForMH($Method* m) {
	$useLocalCurrentObjectStackCache();
	if ($MemberName::isMethodHandleInvokeName($($nc(m)->getName()))) {
		return $MethodHandleImpl::fakeMethodHandleInvoke($$new($MemberName, m));
	}
	return nullptr;
}

$MethodHandle* MethodHandles$Lookup::unreflectForVH($Method* m) {
	$useLocalCurrentObjectStackCache();
	if ($MemberName::isVarHandleMethodInvokeName($($nc(m)->getName()))) {
		return $MethodHandleImpl::fakeVarHandleInvoke($$new($MemberName, m));
	}
	return nullptr;
}

$MethodHandle* MethodHandles$Lookup::unreflectSpecial($Method* m, $Class* specialCaller) {
	$useLocalCurrentObjectStackCache();
	checkSpecialCaller(specialCaller, $nc(m)->getDeclaringClass());
	$var(MethodHandles$Lookup, specialLookup, this->in(specialCaller));
	$var($MemberName, method, $new($MemberName, m, true));
	if (!MethodHandles$Lookup::$assertionsDisabled && !(method->isMethod())) {
		$throwNew($AssertionError);
	}
	$Class* var$0 = method->getDeclaringClass();
	$var($MemberName, var$1, method);
	return $nc(specialLookup)->getDirectMethodNoSecurityManager((int8_t)7, var$0, var$1, $(findBoundCallerLookup(method)));
}

$MethodHandle* MethodHandles$Lookup::unreflectConstructor($Constructor* c) {
	$useLocalCurrentObjectStackCache();
	$var($MemberName, ctor, $new($MemberName, c));
	if (!MethodHandles$Lookup::$assertionsDisabled && !(ctor->isConstructor())) {
		$throwNew($AssertionError);
	}
	$var(MethodHandles$Lookup, lookup, $nc(c)->isAccessible() ? MethodHandles$Lookup::IMPL_LOOKUP : this);
	return $nc(lookup)->getDirectConstructorNoSecurityManager(ctor->getDeclaringClass(), ctor);
}

$MethodHandle* MethodHandles$Lookup::unreflectGetter($Field* f) {
	return unreflectField(f, false);
}

$MethodHandle* MethodHandles$Lookup::unreflectSetter($Field* f) {
	return unreflectField(f, true);
}

$MethodHandle* MethodHandles$Lookup::unreflectField($Field* f, bool isSetter) {
	$useLocalCurrentObjectStackCache();
	$var($MemberName, field, $new($MemberName, f, isSetter));
	if (isSetter && field->isFinal()) {
		if (field->isTrustedFinalField()) {
			$var($String, msg, field->isStatic() ? "static final field has no write access"_s : "final field has no write access"_s);
			$throw($(field->makeAccessException(msg, this)));
		}
	}
	if (!MethodHandles$Lookup::$assertionsDisabled && !(isSetter ? $MethodHandleNatives::refKindIsSetter(field->getReferenceKind()) : $MethodHandleNatives::refKindIsGetter(field->getReferenceKind()))) {
		$throwNew($AssertionError);
	}
	$var(MethodHandles$Lookup, lookup, $nc(f)->isAccessible() ? MethodHandles$Lookup::IMPL_LOOKUP : this);
	int8_t var$0 = field->getReferenceKind();
	return $nc(lookup)->getDirectFieldNoSecurityManager(var$0, $nc(f)->getDeclaringClass(), field);
}

$VarHandle* MethodHandles$Lookup::unreflectVarHandle($Field* f) {
	$useLocalCurrentObjectStackCache();
	$var($MemberName, getField, $new($MemberName, f, false));
	$var($MemberName, putField, $new($MemberName, f, true));
	int8_t var$0 = getField->getReferenceKind();
	int8_t var$1 = putField->getReferenceKind();
	return getFieldVarHandleNoSecurityManager(var$0, var$1, $nc(f)->getDeclaringClass(), getField, putField);
}

$MethodHandleInfo* MethodHandles$Lookup::revealDirect($MethodHandle* target) {
	$useLocalCurrentObjectStackCache();
	if (!$nc(target)->isCrackable()) {
		$throw($($MethodHandleStatics::newIllegalArgumentException("not a direct method handle"_s)));
	}
	$var($MemberName, member, $nc(target)->internalMemberName());
	$Class* defc = $nc(member)->getDeclaringClass();
	int8_t refKind = member->getReferenceKind();
	if (!MethodHandles$Lookup::$assertionsDisabled && !($MethodHandleNatives::refKindIsValid(refKind))) {
		$throwNew($AssertionError);
	}
	if (refKind == (int8_t)7 && !target->isInvokeSpecial()) {
		refKind = (int8_t)5;
	}
	if (refKind == (int8_t)5 && $nc(defc)->isInterface()) {
		refKind = (int8_t)9;
	}
	try {
		checkAccess(refKind, defc, member);
		checkSecurityManager(defc, member);
	} catch ($IllegalAccessException& ex) {
		$throwNew($IllegalArgumentException, static_cast<$Throwable*>(ex));
	}
	if (this->allowedModes != MethodHandles$Lookup::TRUSTED && member->isCallerSensitive()) {
		$Class* callerClass = target->internalCallerClass();
		bool var$0 = ((int32_t)(lookupModes() & (uint32_t)MethodHandles$Lookup::ORIGINAL)) == 0;
		if (var$0 || callerClass != lookupClass()) {
			$throwNew($IllegalArgumentException, $$str({"method handle is caller sensitive: "_s, callerClass}));
		}
	}
	return $new($InfoFromMemberName, this, member, refKind);
}

$MemberName* MethodHandles$Lookup::resolveOrFail(int8_t refKind, $Class* refc, $String* name, $Class* type) {
	checkSymbolicClass(refc);
	$Objects::requireNonNull(name);
	$Objects::requireNonNull(type);
	$init($MethodHandles);
	int8_t var$0 = refKind;
	$var($MemberName, var$1, $new($MemberName, refc, name, type, refKind));
	$load($NoSuchFieldException);
	return $nc($MethodHandles::IMPL_NAMES)->resolveOrFail(var$0, var$1, lookupClassOrNull(), this->allowedModes, $NoSuchFieldException::class$);
}

$MemberName* MethodHandles$Lookup::resolveOrFail(int8_t refKind, $Class* refc, $String* name, $MethodType* type) {
	checkSymbolicClass(refc);
	$Objects::requireNonNull(type);
	checkMethodName(refKind, name);
	$init($MethodHandles);
	int8_t var$0 = refKind;
	$var($MemberName, var$1, $new($MemberName, refc, name, type, refKind));
	$load($NoSuchMethodException);
	return $nc($MethodHandles::IMPL_NAMES)->resolveOrFail(var$0, var$1, lookupClassOrNull(), this->allowedModes, $NoSuchMethodException::class$);
}

$MemberName* MethodHandles$Lookup::resolveOrFail(int8_t refKind, $MemberName* member) {
	$useLocalCurrentObjectStackCache();
	checkSymbolicClass($nc(member)->getDeclaringClass());
	$Objects::requireNonNull($($nc(member)->getName()));
	$Objects::requireNonNull($($nc(member)->getType()));
	$init($MethodHandles);
	$load($ReflectiveOperationException);
	return $nc($MethodHandles::IMPL_NAMES)->resolveOrFail(refKind, member, lookupClassOrNull(), this->allowedModes, $ReflectiveOperationException::class$);
}

$MemberName* MethodHandles$Lookup::resolveOrNull(int8_t refKind, $MemberName* member) {
	$useLocalCurrentObjectStackCache();
	if (!isClassAccessible($nc(member)->getDeclaringClass())) {
		return nullptr;
	}
	$Objects::requireNonNull($($nc(member)->getName()));
	$Objects::requireNonNull($($nc(member)->getType()));
	$init($MethodHandles);
	return $nc($MethodHandles::IMPL_NAMES)->resolveOrNull(refKind, member, lookupClassOrNull(), this->allowedModes);
}

$MemberName* MethodHandles$Lookup::resolveOrNull(int8_t refKind, $Class* refc, $String* name, $MethodType* type) {
	if (!isClassAccessible(refc)) {
		return nullptr;
	}
	$Objects::requireNonNull(type);
	if ($nc(name)->startsWith("<"_s) && refKind != (int8_t)8) {
		return nullptr;
	}
	$init($MethodHandles);
	int8_t var$0 = refKind;
	$var($MemberName, var$1, $new($MemberName, refc, name, type, refKind));
	return $nc($MethodHandles::IMPL_NAMES)->resolveOrNull(var$0, var$1, lookupClassOrNull(), this->allowedModes);
}

void MethodHandles$Lookup::checkSymbolicClass($Class* refc) {
	$useLocalCurrentObjectStackCache();
	if (!isClassAccessible(refc)) {
		$throw($($$new($MemberName, refc)->makeAccessException("symbolic reference class is not accessible"_s, this)));
	}
}

bool MethodHandles$Lookup::isClassAccessible($Class* refc) {
	$Objects::requireNonNull(refc);
	$Class* caller = lookupClassOrNull();
	$Class* type = refc;
	while ($nc(type)->isArray()) {
		type = type->getComponentType();
	}
	return caller == nullptr || $VerifyAccess::isClassAccessible(type, caller, this->prevLookupClass, this->allowedModes);
}

void MethodHandles$Lookup::checkMethodName(int8_t refKind, $String* name) {
	if ($nc(name)->startsWith("<"_s) && refKind != (int8_t)8) {
		$throwNew($NoSuchMethodException, $$str({"illegal method name: "_s, name}));
	}
}

MethodHandles$Lookup* MethodHandles$Lookup::findBoundCallerLookup($MemberName* m) {
	bool var$0 = $MethodHandleNatives::isCallerSensitive(m);
	if (var$0 && ((int32_t)(lookupModes() & (uint32_t)MethodHandles$Lookup::ORIGINAL)) == 0) {
		$throwNew($IllegalAccessException, "Attempt to lookup caller-sensitive method using restricted lookup object"_s);
	}
	return this;
}

bool MethodHandles$Lookup::hasPrivateAccess() {
	return hasFullPrivilegeAccess();
}

bool MethodHandles$Lookup::hasFullPrivilegeAccess() {
	return ((int32_t)(this->allowedModes & (uint32_t)(MethodHandles$Lookup::PRIVATE | MethodHandles$Lookup::MODULE))) == (MethodHandles$Lookup::PRIVATE | MethodHandles$Lookup::MODULE);
}

void MethodHandles$Lookup::checkSecurityManager($Class* refc) {
	if (this->allowedModes == MethodHandles$Lookup::TRUSTED) {
		return;
	}
	$var($SecurityManager, smgr, $System::getSecurityManager());
	if (smgr == nullptr) {
		return;
	}
	bool fullPrivilegeLookup = hasFullPrivilegeAccess();
	if (!fullPrivilegeLookup || !$VerifyAccess::classLoaderIsAncestor(this->lookupClass$, refc)) {
		$ReflectUtil::checkPackageAccess(refc);
	}
	if (!fullPrivilegeLookup) {
		$init($SecurityConstants);
		$nc(smgr)->checkPermission($SecurityConstants::GET_CLASSLOADER_PERMISSION);
	}
}

void MethodHandles$Lookup::checkSecurityManager($Class* refc, $MemberName* m) {
	$Objects::requireNonNull(refc);
	$Objects::requireNonNull(m);
	if (this->allowedModes == MethodHandles$Lookup::TRUSTED) {
		return;
	}
	$var($SecurityManager, smgr, $System::getSecurityManager());
	if (smgr == nullptr) {
		return;
	}
	bool fullPrivilegeLookup = hasFullPrivilegeAccess();
	if (!fullPrivilegeLookup || !$VerifyAccess::classLoaderIsAncestor(this->lookupClass$, refc)) {
		$ReflectUtil::checkPackageAccess(refc);
	}
	if (m->isPublic()) {
		return;
	}
	if (!fullPrivilegeLookup) {
		$init($SecurityConstants);
		$nc(smgr)->checkPermission($SecurityConstants::CHECK_MEMBER_ACCESS_PERMISSION);
	}
	$Class* defc = m->getDeclaringClass();
	if (!fullPrivilegeLookup && defc != refc) {
		$ReflectUtil::checkPackageAccess(defc);
	}
}

void MethodHandles$Lookup::checkMethod(int8_t refKind, $Class* refc, $MemberName* m) {
	$useLocalCurrentObjectStackCache();
	bool wantStatic = (refKind == (int8_t)6);
	$var($String, message, nullptr);
	if ($nc(m)->isConstructor()) {
		$assign(message, "expected a method, not a constructor"_s);
	} else if (!m->isMethod()) {
		$assign(message, "expected a method"_s);
	} else if (wantStatic != m->isStatic()) {
		$assign(message, wantStatic ? "expected a static method"_s : "expected a non-static method"_s);
	} else {
		checkAccess(refKind, refc, m);
		return;
	}
	$throw($($nc(m)->makeAccessException(message, this)));
}

void MethodHandles$Lookup::checkField(int8_t refKind, $Class* refc, $MemberName* m) {
	$useLocalCurrentObjectStackCache();
	bool wantStatic = !$MethodHandleNatives::refKindHasReceiver(refKind);
	$var($String, message, nullptr);
	if (wantStatic != $nc(m)->isStatic()) {
		$assign(message, wantStatic ? "expected a static field"_s : "expected a non-static field"_s);
	} else {
		checkAccess(refKind, refc, m);
		return;
	}
	$throw($($nc(m)->makeAccessException(message, this)));
}

void MethodHandles$Lookup::checkAccess(int8_t refKind, $Class* refc, $MemberName* m) {
	$useLocalCurrentObjectStackCache();
	bool var$0 = !MethodHandles$Lookup::$assertionsDisabled;
	if (var$0) {
		bool var$2 = $nc(m)->referenceKindIsConsistentWith(refKind);
		bool var$1 = var$2 && $MethodHandleNatives::refKindIsValid(refKind);
		if (var$1) {
			bool var$3 = $MethodHandleNatives::refKindIsField(refKind);
			var$1 = (var$3 == m->isField());
		}
		var$0 = !(var$1);
	}
	if (var$0) {
		$throwNew($AssertionError);
	}
	int32_t allowedModes = this->allowedModes;
	if (allowedModes == MethodHandles$Lookup::TRUSTED) {
		return;
	}
	int32_t mods = $nc(m)->getModifiers();
	bool var$6 = $Modifier::isProtected(mods) && refKind == (int8_t)5;
	bool var$5 = var$6 && m->getDeclaringClass() == $Object::class$;
	bool var$4 = var$5 && $nc($(m->getName()))->equals("clone"_s);
	if (var$4 && $nc(refc)->isArray()) {
		mods ^= $Modifier::PROTECTED | $Modifier::PUBLIC;
	}
	if ($Modifier::isProtected(mods) && refKind == (int8_t)8) {
		mods ^= $Modifier::PROTECTED;
	}
	bool var$7 = $Modifier::isFinal(mods);
	if (var$7 && $MethodHandleNatives::refKindIsSetter(refKind)) {
		$throw($(m->makeAccessException("unexpected set of a final field"_s, this)));
	}
	int32_t requestedModes = fixmods(mods);
	if (((int32_t)(requestedModes & (uint32_t)allowedModes)) != 0) {
		$Class* var$8 = refc;
		$Class* var$9 = m->getDeclaringClass();
		int32_t var$10 = mods;
		$Class* var$11 = lookupClass();
		if ($VerifyAccess::isMemberAccessible(var$8, var$9, var$10, var$11, previousLookupClass(), allowedModes)) {
			return;
		}
	} else {
		bool var$14 = ((int32_t)(requestedModes & (uint32_t)MethodHandles$Lookup::PROTECTED)) != 0 && ((int32_t)(allowedModes & (uint32_t)MethodHandles$Lookup::PACKAGE)) != 0;
		if (var$14) {
			$Class* var$15 = m->getDeclaringClass();
			var$14 = $VerifyAccess::isSamePackage(var$15, lookupClass());
		}
		if (var$14) {
			return;
		}
	}
	$throw($(m->makeAccessException($(accessFailedMessage(refc, m)), this)));
}

$String* MethodHandles$Lookup::accessFailedMessage($Class* refc, $MemberName* m) {
	$Class* defc = $nc(m)->getDeclaringClass();
	int32_t mods = m->getModifiers();
	bool var$0 = $Modifier::isPublic($nc(defc)->getModifiers());
	bool classOK = (var$0 && (defc == refc || $Modifier::isPublic($nc(refc)->getModifiers())));
	if (!classOK && ((int32_t)(this->allowedModes & (uint32_t)MethodHandles$Lookup::PACKAGE)) != 0) {
		bool var$1 = $VerifyAccess::isClassAccessible(defc, lookupClass(), nullptr, MethodHandles$Lookup::FULL_POWER_MODES);
		classOK = (var$1 && (defc == refc || $VerifyAccess::isClassAccessible(refc, lookupClass(), nullptr, MethodHandles$Lookup::FULL_POWER_MODES)));
	}
	if (!classOK) {
		return "class is not public"_s;
	}
	if ($Modifier::isPublic(mods)) {
		return "access to public member failed"_s;
	}
	if ($Modifier::isPrivate(mods)) {
		return "member is private"_s;
	}
	if ($Modifier::isProtected(mods)) {
		return "member is protected"_s;
	}
	return "member is private to package"_s;
}

void MethodHandles$Lookup::checkSpecialCaller($Class* specialCaller, $Class* refc) {
	$useLocalCurrentObjectStackCache();
	int32_t allowedModes = this->allowedModes;
	if (allowedModes == MethodHandles$Lookup::TRUSTED) {
		return;
	}
	bool var$0 = ((int32_t)(lookupModes() & (uint32_t)MethodHandles$Lookup::PRIVATE)) == 0;
	if (!var$0) {
		bool var$1 = specialCaller != lookupClass();
		if (var$1) {
			bool var$2 = refc != nullptr && refc->isInterface();
			var$1 = !(var$2 && refc->isAssignableFrom(specialCaller));
		}
		var$0 = (var$1);
	}
	if (var$0) {
		$throw($($$new($MemberName, specialCaller)->makeAccessException("no private access for invokespecial"_s, this)));
	}
}

bool MethodHandles$Lookup::restrictProtectedReceiver($MemberName* method) {
	bool var$2 = !$nc(method)->isProtected();
	bool var$1 = var$2 || $nc(method)->isStatic() || this->allowedModes == MethodHandles$Lookup::TRUSTED;
	if (!var$1) {
		var$1 = $nc(method)->getDeclaringClass() == lookupClass();
	}
	bool var$0 = var$1;
	if (!var$0) {
		$Class* var$3 = $nc(method)->getDeclaringClass();
		var$0 = $VerifyAccess::isSamePackage(var$3, lookupClass());
	}
	if (var$0) {
		return false;
	}
	return true;
}

$MethodHandle* MethodHandles$Lookup::restrictReceiver($MemberName* method, $DirectMethodHandle* mh, $Class* caller) {
	$useLocalCurrentObjectStackCache();
	if (!MethodHandles$Lookup::$assertionsDisabled && !(!$nc(method)->isStatic())) {
		$throwNew($AssertionError);
	}
	if (!$nc($nc(method)->getDeclaringClass())->isAssignableFrom(caller)) {
		$throw($(method->makeAccessException("caller class must be a subclass below the method"_s, caller)));
	}
	$var($MethodType, rawType, $nc(mh)->type());
	if ($nc(caller)->isAssignableFrom($($cast($Class, $nc(rawType)->parameterType(0))))) {
		return mh;
	}
	$var($MethodType, narrowType, $nc(rawType)->changeParameterType(0, caller));
	if (!MethodHandles$Lookup::$assertionsDisabled && !(!mh->isVarargsCollector())) {
		$throwNew($AssertionError);
	}
	if (!MethodHandles$Lookup::$assertionsDisabled && !(mh->viewAsTypeChecks(narrowType, true))) {
		$throwNew($AssertionError);
	}
	return mh->copyWith(narrowType, mh->form);
}

$MethodHandle* MethodHandles$Lookup::getDirectMethod(int8_t refKind, $Class* refc, $MemberName* method, MethodHandles$Lookup* callerLookup) {
	bool doRestrict = true;
	bool checkSecurity = true;
	return getDirectMethodCommon(refKind, refc, method, checkSecurity, doRestrict, callerLookup);
}

$MethodHandle* MethodHandles$Lookup::getDirectMethodNoRestrictInvokeSpecial($Class* refc, $MemberName* method, MethodHandles$Lookup* callerLookup) {
	bool doRestrict = false;
	bool checkSecurity = true;
	return getDirectMethodCommon((int8_t)7, refc, method, checkSecurity, doRestrict, callerLookup);
}

$MethodHandle* MethodHandles$Lookup::getDirectMethodNoSecurityManager(int8_t refKind, $Class* refc, $MemberName* method, MethodHandles$Lookup* callerLookup) {
	bool doRestrict = true;
	bool checkSecurity = false;
	return getDirectMethodCommon(refKind, refc, method, checkSecurity, doRestrict, callerLookup);
}

$MethodHandle* MethodHandles$Lookup::getDirectMethodCommon(int8_t refKind, $Class* refc, $MemberName* method$renamed, bool checkSecurity, bool doRestrict, MethodHandles$Lookup* boundCaller) {
	$useLocalCurrentObjectStackCache();
	$var($MemberName, method, method$renamed);
	checkMethod(refKind, refc, method);
	if (checkSecurity) {
		checkSecurityManager(refc, method);
	}
	if (!MethodHandles$Lookup::$assertionsDisabled && !(!$nc(method)->isMethodHandleInvoke())) {
		$throwNew($AssertionError);
	}
	bool var$2 = refKind == (int8_t)7 && refc != lookupClass();
	bool var$1 = var$2 && !$nc(refc)->isInterface();
	bool var$0 = var$1 && refc != $nc(lookupClass())->getSuperclass();
	if (var$0 && refc->isAssignableFrom(lookupClass())) {
		if (!MethodHandles$Lookup::$assertionsDisabled && !(!$nc($($nc(method)->getName()))->equals("<init>"_s))) {
			$throwNew($AssertionError);
		}
		$Class* refcAsSuper = lookupClass();
		$var($MemberName, m2, nullptr);
		do {
			refcAsSuper = $nc(refcAsSuper)->getSuperclass();
			$Class* var$3 = refcAsSuper;
			$var($String, var$4, $nc(method)->getName());
			$assign(m2, $new($MemberName, var$3, var$4, $(method->getMethodType()), (int8_t)7));
			$init($MethodHandles);
			$assign(m2, $nc($MethodHandles::IMPL_NAMES)->resolveOrNull(refKind, m2, lookupClassOrNull(), this->allowedModes));
		} while (m2 == nullptr && refc != refcAsSuper);
		if (m2 == nullptr) {
			$throwNew($InternalError, $($nc(method)->toString()));
		}
		$assign(method, m2);
		refc = refcAsSuper;
		checkMethod(refKind, refc, method);
	}
	$var($DirectMethodHandle, dmh, $DirectMethodHandle::make(refKind, refc, method, lookupClass()));
	$var($MethodHandle, mh, dmh);
	bool var$5 = (doRestrict && refKind == (int8_t)7);
	if (!var$5) {
		bool var$6 = $MethodHandleNatives::refKindHasReceiver(refKind);
		var$5 = (var$6 && restrictProtectedReceiver(method));
	}
	if (var$5) {
		$assign(mh, restrictReceiver(method, dmh, lookupClass()));
	}
	$assign(mh, maybeBindCaller(method, mh, boundCaller));
	$assign(mh, $nc(mh)->setVarargs(method));
	return mh;
}

$MethodHandle* MethodHandles$Lookup::maybeBindCaller($MemberName* method, $MethodHandle* mh, MethodHandles$Lookup* boundCaller) {
	if ($nc(boundCaller)->allowedModes == MethodHandles$Lookup::TRUSTED || !$MethodHandleNatives::isCallerSensitive(method)) {
		return mh;
	}
	if (((int32_t)($nc(boundCaller)->lookupModes() & (uint32_t)MethodHandles$Lookup::ORIGINAL)) == 0) {
		$throwNew($IllegalAccessException, "Attempt to lookup caller-sensitive method using restricted lookup object"_s);
	}
	if (!MethodHandles$Lookup::$assertionsDisabled && !$nc(boundCaller)->hasFullPrivilegeAccess()) {
		$throwNew($AssertionError);
	}
	$var($MethodHandle, cbmh, $MethodHandleImpl::bindCaller(mh, $nc(boundCaller)->lookupClass$));
	return cbmh;
}

$MethodHandle* MethodHandles$Lookup::getDirectField(int8_t refKind, $Class* refc, $MemberName* field) {
	bool checkSecurity = true;
	return getDirectFieldCommon(refKind, refc, field, checkSecurity);
}

$MethodHandle* MethodHandles$Lookup::getDirectFieldNoSecurityManager(int8_t refKind, $Class* refc, $MemberName* field) {
	bool checkSecurity = false;
	return getDirectFieldCommon(refKind, refc, field, checkSecurity);
}

$MethodHandle* MethodHandles$Lookup::getDirectFieldCommon(int8_t refKind, $Class* refc, $MemberName* field, bool checkSecurity) {
	checkField(refKind, refc, field);
	if (checkSecurity) {
		checkSecurityManager(refc, field);
	}
	$var($DirectMethodHandle, dmh, $DirectMethodHandle::make(refc, field));
	bool var$0 = $MethodHandleNatives::refKindHasReceiver(refKind);
	bool doRestrict = (var$0 && restrictProtectedReceiver(field));
	if (doRestrict) {
		return restrictReceiver(field, dmh, lookupClass());
	}
	return dmh;
}

$VarHandle* MethodHandles$Lookup::getFieldVarHandle(int8_t getRefKind, int8_t putRefKind, $Class* refc, $MemberName* getField, $MemberName* putField) {
	bool checkSecurity = true;
	return getFieldVarHandleCommon(getRefKind, putRefKind, refc, getField, putField, checkSecurity);
}

$VarHandle* MethodHandles$Lookup::getFieldVarHandleNoSecurityManager(int8_t getRefKind, int8_t putRefKind, $Class* refc, $MemberName* getField, $MemberName* putField) {
	bool checkSecurity = false;
	return getFieldVarHandleCommon(getRefKind, putRefKind, refc, getField, putField, checkSecurity);
}

$VarHandle* MethodHandles$Lookup::getFieldVarHandleCommon(int8_t getRefKind, int8_t putRefKind, $Class* refc, $MemberName* getField, $MemberName* putField, bool checkSecurity) {
	$useLocalCurrentObjectStackCache();
	bool var$0 = !MethodHandles$Lookup::$assertionsDisabled;
	if (var$0) {
		bool var$1 = $nc(getField)->isStatic();
		var$0 = !(var$1 == $nc(putField)->isStatic());
	}
	if (var$0) {
		$throwNew($AssertionError);
	}
	bool var$2 = !MethodHandles$Lookup::$assertionsDisabled;
	if (var$2) {
		bool var$3 = $nc(getField)->isGetter();
		var$2 = !(var$3 && $nc(putField)->isSetter());
	}
	if (var$2) {
		$throwNew($AssertionError);
	}
	bool var$4 = !MethodHandles$Lookup::$assertionsDisabled;
	if (var$4) {
		bool var$5 = $MethodHandleNatives::refKindIsStatic(getRefKind);
		var$4 = !(var$5 == $MethodHandleNatives::refKindIsStatic(putRefKind));
	}
	if (var$4) {
		$throwNew($AssertionError);
	}
	bool var$6 = !MethodHandles$Lookup::$assertionsDisabled;
	if (var$6) {
		bool var$7 = $MethodHandleNatives::refKindIsGetter(getRefKind);
		var$6 = !(var$7 && $MethodHandleNatives::refKindIsSetter(putRefKind));
	}
	if (var$6) {
		$throwNew($AssertionError);
	}
	checkField(getRefKind, refc, getField);
	if (checkSecurity) {
		checkSecurityManager(refc, getField);
	}
	if (!$nc(putField)->isFinal()) {
		checkField(putRefKind, refc, putField);
		if (checkSecurity) {
			checkSecurityManager(refc, putField);
		}
	}
	bool var$8 = $MethodHandleNatives::refKindHasReceiver(getRefKind);
	bool doRestrict = (var$8 && restrictProtectedReceiver(getField));
	if (doRestrict) {
		if (!MethodHandles$Lookup::$assertionsDisabled && ! !$nc(getField)->isStatic()) {
			$throwNew($AssertionError);
		}
		if (!$nc($nc(getField)->getDeclaringClass())->isAssignableFrom(lookupClass())) {
			$throw($(getField->makeAccessException("caller class must be a subclass below the method"_s, lookupClass())));
		}
		refc = lookupClass();
	}
	$var($MemberName, var$9, getField);
	$Class* var$10 = refc;
	$Class* var$11 = $nc(getField)->getFieldType();
	return $VarHandles::makeFieldHandle(var$9, var$10, var$11, this->allowedModes == MethodHandles$Lookup::TRUSTED && !getField->isTrustedFinalField());
}

$MethodHandle* MethodHandles$Lookup::getDirectConstructor($Class* refc, $MemberName* ctor) {
	bool checkSecurity = true;
	return getDirectConstructorCommon(refc, ctor, checkSecurity);
}

$MethodHandle* MethodHandles$Lookup::getDirectConstructorNoSecurityManager($Class* refc, $MemberName* ctor) {
	bool checkSecurity = false;
	return getDirectConstructorCommon(refc, ctor, checkSecurity);
}

$MethodHandle* MethodHandles$Lookup::getDirectConstructorCommon($Class* refc, $MemberName* ctor, bool checkSecurity) {
	if (!MethodHandles$Lookup::$assertionsDisabled && !($nc(ctor)->isConstructor())) {
		$throwNew($AssertionError);
	}
	checkAccess((int8_t)8, refc, ctor);
	if (checkSecurity) {
		checkSecurityManager(refc, ctor);
	}
	if (!MethodHandles$Lookup::$assertionsDisabled && !(!$MethodHandleNatives::isCallerSensitive(ctor))) {
		$throwNew($AssertionError);
	}
	return $nc($($DirectMethodHandle::make(ctor)))->setVarargs(ctor);
}

$MethodHandle* MethodHandles$Lookup::linkMethodHandleConstant(int8_t refKind, $Class* defc, $String* name, Object$* type) {
	$useLocalCurrentObjectStackCache();
	if (!($instanceOf($Class, type) || $instanceOf($MethodType, type))) {
		$throwNew($InternalError, "unresolved MemberName"_s);
	}
	$var($MemberName, member, $new($MemberName, refKind, defc, name, type));
	$var($MethodHandle, mh, $cast($MethodHandle, $nc(MethodHandles$Lookup::LOOKASIDE_TABLE)->get(member)));
	if (mh != nullptr) {
		checkSymbolicClass(defc);
		return mh;
	}
	$load($MethodHandle);
	if (defc == $MethodHandle::class$ && refKind == (int8_t)5) {
		$var($String, var$0, member->getName());
		$assign(mh, findVirtualForMH(var$0, $(member->getMethodType())));
		if (mh != nullptr) {
			return mh;
		}
	} else {
		$load($VarHandle);
		if (defc == $VarHandle::class$ && refKind == (int8_t)5) {
			$var($String, var$1, member->getName());
			$assign(mh, findVirtualForVH(var$1, $(member->getMethodType())));
			if (mh != nullptr) {
				return mh;
			}
		}
	}
	$var($MemberName, resolved, resolveOrFail(refKind, member));
	$assign(mh, getDirectMethodForConstant(refKind, defc, resolved));
	if ($instanceOf($DirectMethodHandle, mh) && canBeCached(refKind, defc, resolved)) {
		$var($MemberName, key, $nc(mh)->internalMemberName());
		if (key != nullptr) {
			$assign(key, key->asNormalOriginal());
		}
		if (member->equals(key)) {
			$nc(MethodHandles$Lookup::LOOKASIDE_TABLE)->put(key, $cast($DirectMethodHandle, mh));
		}
	}
	return mh;
}

bool MethodHandles$Lookup::canBeCached(int8_t refKind, $Class* defc, $MemberName* member) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (refKind == (int8_t)7) {
		return false;
	}
	bool var$2 = !$Modifier::isPublic($nc(defc)->getModifiers());
	bool var$1 = var$2 || !$Modifier::isPublic($nc($nc(member)->getDeclaringClass())->getModifiers());
	bool var$0 = var$1 || !$nc(member)->isPublic();
	if (var$0 || $nc(member)->isCallerSensitive()) {
		return false;
	}
	$var($ClassLoader, loader, $nc(defc)->getClassLoader());
	if (loader != nullptr) {
		$var($ClassLoader, sysl, $ClassLoader::getSystemClassLoader());
		bool found = false;
		while (sysl != nullptr) {
			if (loader == sysl) {
				found = true;
				break;
			}
			$assign(sysl, sysl->getParent());
		}
		if (!found) {
			return false;
		}
	}
	try {
		int8_t var$3 = refKind;
		$Class* var$4 = defc;
		$var($String, var$5, $nc(member)->getName());
		$var($MemberName, resolved2, $nc($($MethodHandles::publicLookup()))->resolveOrNull(refKind, $$new($MemberName, var$3, var$4, var$5, $(member->getType()))));
		if (resolved2 == nullptr) {
			return false;
		}
		checkSecurityManager(defc, resolved2);
	} catch ($SecurityException& ex) {
		return false;
	}
	return true;
}

$MethodHandle* MethodHandles$Lookup::getDirectMethodForConstant(int8_t refKind, $Class* defc, $MemberName* member) {
	$useLocalCurrentObjectStackCache();
	if ($MethodHandleNatives::refKindIsField(refKind)) {
		return getDirectFieldNoSecurityManager(refKind, defc, member);
	} else if ($MethodHandleNatives::refKindIsMethod(refKind)) {
		return getDirectMethodNoSecurityManager(refKind, defc, member, $(findBoundCallerLookup(member)));
	} else if (refKind == (int8_t)8) {
		return getDirectConstructorNoSecurityManager(defc, member);
	}
	$throw($($MethodHandleStatics::newIllegalArgumentException($$str({"bad MethodHandle constant #"_s, member}))));
}

void clinit$MethodHandles$Lookup($Class* class$) {
	$load($MethodHandles);
	MethodHandles$Lookup::$assertionsDisabled = !$MethodHandles::class$->desiredAssertionStatus();
	{
		$Reflection::registerFieldsToFilter(MethodHandles$Lookup::class$, $($Set::of("lookupClass"_s, "allowedModes"_s)));
	}
	{
		$init($MethodHandles);
		$nc($of($MethodHandles::IMPL_NAMES))->getClass();
	}
	$assignStatic(MethodHandles$Lookup::IMPL_LOOKUP, $new(MethodHandles$Lookup, $Object::class$, nullptr, MethodHandles$Lookup::TRUSTED));
	$assignStatic(MethodHandles$Lookup::PUBLIC_LOOKUP, $new(MethodHandles$Lookup, $Object::class$, nullptr, MethodHandles$Lookup::UNCONDITIONAL));
	$assignStatic(MethodHandles$Lookup::LOOKASIDE_TABLE, $new($ConcurrentHashMap));
}

MethodHandles$Lookup::MethodHandles$Lookup() {
}

$Class* MethodHandles$Lookup::load$($String* name, bool initialize) {
	$loadClass(MethodHandles$Lookup, name, initialize, &_MethodHandles$Lookup_ClassInfo_, clinit$MethodHandles$Lookup, allocate$MethodHandles$Lookup);
	return class$;
}

$Class* MethodHandles$Lookup::class$ = nullptr;

		} // invoke
	} // lang
} // java