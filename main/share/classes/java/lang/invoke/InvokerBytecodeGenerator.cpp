#include <java/lang/invoke/InvokerBytecodeGenerator.h>

#include <java/io/File.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/InternalError.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/invoke/BoundMethodHandle$SpeciesData.h>
#include <java/lang/invoke/BoundMethodHandle.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/DelegatingMethodHandle$Holder.h>
#include <java/lang/invoke/DelegatingMethodHandle.h>
#include <java/lang/invoke/DirectMethodHandle$Holder.h>
#include <java/lang/invoke/DirectMethodHandle.h>
#include <java/lang/invoke/InvokerBytecodeGenerator$1.h>
#include <java/lang/invoke/InvokerBytecodeGenerator$2.h>
#include <java/lang/invoke/InvokerBytecodeGenerator$BytecodeGenerationException.h>
#include <java/lang/invoke/InvokerBytecodeGenerator$ClassData.h>
#include <java/lang/invoke/Invokers$Holder.h>
#include <java/lang/invoke/Invokers.h>
#include <java/lang/invoke/LambdaForm$BasicType.h>
#include <java/lang/invoke/LambdaForm$Holder.h>
#include <java/lang/invoke/LambdaForm$Kind.h>
#include <java/lang/invoke/LambdaForm$Name.h>
#include <java/lang/invoke/LambdaForm$NamedFunction.h>
#include <java/lang/invoke/LambdaForm.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MemberName$Factory.h>
#include <java/lang/invoke/MemberName.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandleImpl$Intrinsic.h>
#include <java/lang/invoke/MethodHandleImpl$LoopClauses.h>
#include <java/lang/invoke/MethodHandleImpl.h>
#include <java/lang/invoke/MethodHandleStatics.h>
#include <java/lang/invoke/MethodHandles$Lookup$ClassDefiner.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/invoke/MethodTypeForm.h>
#include <java/lang/invoke/TypeDescriptor$OfField.h>
#include <java/lang/invoke/TypeDescriptor$OfMethod.h>
#include <java/lang/reflect/Modifier.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/function/Function.h>
#include <java/util/function/IntFunction.h>
#include <java/util/function/Predicate.h>
#include <java/util/stream/Stream.h>
#include <jdk/internal/misc/Unsafe.h>
#include <jdk/internal/org/objectweb/asm/AnnotationVisitor.h>
#include <jdk/internal/org/objectweb/asm/ClassWriter.h>
#include <jdk/internal/org/objectweb/asm/FieldVisitor.h>
#include <jdk/internal/org/objectweb/asm/Label.h>
#include <jdk/internal/org/objectweb/asm/MethodVisitor.h>
#include <jdk/internal/org/objectweb/asm/Opcodes.h>
#include <jdk/internal/org/objectweb/asm/Type.h>
#include <sun/invoke/util/VerifyAccess.h>
#include <sun/invoke/util/VerifyType.h>
#include <sun/invoke/util/Wrapper.h>
#include <jcpp.h>

#undef AALOAD
#undef AASTORE
#undef ACC_FINAL
#undef ACC_STATIC
#undef ACC_SUPER
#undef ACONST_NULL
#undef ALOAD
#undef ANEWARRAY
#undef ARETURN
#undef ARRAYLENGTH
#undef ASTORE
#undef ATHROW
#undef BASTORE
#undef BIPUSH
#undef CASTORE
#undef CHECKCAST
#undef CLASS_PREFIX
#undef CLS
#undef COMPUTE_FRAMES
#undef COMPUTE_MAXS
#undef D2F
#undef D2I
#undef D2L
#undef DASTORE
#undef DCONST_0
#undef DLOAD
#undef DONTINLINE_SIG
#undef DRETURN
#undef DSTORE
#undef DUMP_CLASS_FILES
#undef DUMP_CLASS_FILES_COUNTERS
#undef DUMP_CLASS_FILES_DIR
#undef DUP
#undef F2D
#undef F2I
#undef F2L
#undef FASTORE
#undef FCONST_0
#undef FLOAD
#undef FORCEINLINE_SIG
#undef FRETURN
#undef FSTORE
#undef GETFIELD
#undef GETSTATIC
#undef GOTO
#undef HIDDEN_SIG
#undef HOST_CLASS
#undef I2B
#undef I2C
#undef I2D
#undef I2F
#undef I2L
#undef I2S
#undef IAND
#undef IASTORE
#undef ICONST_0
#undef ICONST_1
#undef IFEQ
#undef IFNE
#undef ILOAD
#undef IMPL_LOOKUP
#undef INJECTEDPROFILE_SIG
#undef INT
#undef INVOKEINTERFACE
#undef INVOKER_METHOD_TYPE
#undef INVOKER_SUPER_NAME
#undef INVOKESPECIAL
#undef INVOKESTATIC
#undef INVOKEVIRTUAL
#undef IRETURN
#undef ISTORE
#undef L2D
#undef L2F
#undef L2I
#undef LASTORE
#undef LCONST_0
#undef LF
#undef LFN
#undef LFN_SIG
#undef LF_COMPILED_SIG
#undef LF_SIG
#undef LLOAD
#undef LLV_SIG
#undef LL_SIG
#undef LOOKUP
#undef LOOP_CLAUSES
#undef LRETURN
#undef LSTORE
#undef L_TYPE
#undef MAX_VALUE
#undef MEMBERNAME_FACTORY
#undef MH
#undef MHARY2
#undef MHI
#undef MH_SIG
#undef MIN_VALUE
#undef NOT_ACC_PUBLIC
#undef OBJ
#undef OBJARY
#undef OBJECT
#undef POP
#undef POP2
#undef PROFILE_GWT
#undef PROFILE_LEVEL
#undef PUTFIELD
#undef PUTSTATIC
#undef RETURN
#undef SASTORE
#undef SIPUSH
#undef SOURCE_PREFIX
#undef STATICALLY_INVOCABLE_PACKAGES
#undef SWAP
#undef TYPE
#undef T_BOOLEAN
#undef T_BYTE
#undef T_CHAR
#undef T_DOUBLE
#undef T_FLOAT
#undef T_INT
#undef T_LONG
#undef T_SHORT
#undef V_TYPE

using $LambdaForm$BasicTypeArray = $Array<::java::lang::invoke::LambdaForm$BasicType>;
using $LambdaForm$NameArray = $Array<::java::lang::invoke::LambdaForm$Name>;
using $LambdaForm$NamedFunctionArray = $Array<::java::lang::invoke::LambdaForm$NamedFunction>;
using $MethodHandleArray = $Array<::java::lang::invoke::MethodHandle>;
using $LabelArray = $Array<::jdk::internal::org::objectweb::asm$::Label>;
using $File = ::java::io::File;
using $PrintStream = ::java::io::PrintStream;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $Byte = ::java::lang::Byte;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $Double = ::java::lang::Double;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $RuntimeException = ::java::lang::RuntimeException;
using $Short = ::java::lang::Short;
using $Void = ::java::lang::Void;
using $BoundMethodHandle = ::java::lang::invoke::BoundMethodHandle;
using $BoundMethodHandle$SpeciesData = ::java::lang::invoke::BoundMethodHandle$SpeciesData;
using $DelegatingMethodHandle$Holder = ::java::lang::invoke::DelegatingMethodHandle$Holder;
using $DirectMethodHandle$Holder = ::java::lang::invoke::DirectMethodHandle$Holder;
using $InvokerBytecodeGenerator$1 = ::java::lang::invoke::InvokerBytecodeGenerator$1;
using $InvokerBytecodeGenerator$2 = ::java::lang::invoke::InvokerBytecodeGenerator$2;
using $InvokerBytecodeGenerator$BytecodeGenerationException = ::java::lang::invoke::InvokerBytecodeGenerator$BytecodeGenerationException;
using $InvokerBytecodeGenerator$ClassData = ::java::lang::invoke::InvokerBytecodeGenerator$ClassData;
using $Invokers$Holder = ::java::lang::invoke::Invokers$Holder;
using $LambdaForm = ::java::lang::invoke::LambdaForm;
using $LambdaForm$BasicType = ::java::lang::invoke::LambdaForm$BasicType;
using $LambdaForm$Holder = ::java::lang::invoke::LambdaForm$Holder;
using $LambdaForm$Kind = ::java::lang::invoke::LambdaForm$Kind;
using $LambdaForm$Name = ::java::lang::invoke::LambdaForm$Name;
using $LambdaForm$NamedFunction = ::java::lang::invoke::LambdaForm$NamedFunction;
using $MemberName = ::java::lang::invoke::MemberName;
using $MemberName$Factory = ::java::lang::invoke::MemberName$Factory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandleImpl = ::java::lang::invoke::MethodHandleImpl;
using $MethodHandleImpl$Intrinsic = ::java::lang::invoke::MethodHandleImpl$Intrinsic;
using $MethodHandleImpl$LoopClauses = ::java::lang::invoke::MethodHandleImpl$LoopClauses;
using $MethodHandleStatics = ::java::lang::invoke::MethodHandleStatics;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodHandles$Lookup$ClassDefiner = ::java::lang::invoke::MethodHandles$Lookup$ClassDefiner;
using $MethodType = ::java::lang::invoke::MethodType;
using $MethodTypeForm = ::java::lang::invoke::MethodTypeForm;
using $Modifier = ::java::lang::reflect::Modifier;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Function = ::java::util::function::Function;
using $IntFunction = ::java::util::function::IntFunction;
using $Predicate = ::java::util::function::Predicate;
using $Stream = ::java::util::stream::Stream;
using $Unsafe = ::jdk::internal::misc::Unsafe;
using $ClassWriter = ::jdk::internal::org::objectweb::asm$::ClassWriter;
using $FieldVisitor = ::jdk::internal::org::objectweb::asm$::FieldVisitor;
using $Label = ::jdk::internal::org::objectweb::asm$::Label;
using $MethodVisitor = ::jdk::internal::org::objectweb::asm$::MethodVisitor;
using $Opcodes = ::jdk::internal::org::objectweb::asm$::Opcodes;
using $Type = ::jdk::internal::org::objectweb::asm$::Type;
using $VerifyAccess = ::sun::invoke::util::VerifyAccess;
using $VerifyType = ::sun::invoke::util::VerifyType;
using $Wrapper = ::sun::invoke::util::Wrapper;

namespace java {
	namespace lang {
		namespace invoke {

class InvokerBytecodeGenerator$$Lambda$lambda$emitLoop$0 : public $Predicate {
	$class(InvokerBytecodeGenerator$$Lambda$lambda$emitLoop$0, $NO_CLASS_INIT, $Predicate)
public:
	void init$() {
	}
	virtual bool test(Object$* bt) override {
		 return InvokerBytecodeGenerator::lambda$emitLoop$0($cast($LambdaForm$BasicType, bt));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<InvokerBytecodeGenerator$$Lambda$lambda$emitLoop$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo InvokerBytecodeGenerator$$Lambda$lambda$emitLoop$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(InvokerBytecodeGenerator$$Lambda$lambda$emitLoop$0, init$, void)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(InvokerBytecodeGenerator$$Lambda$lambda$emitLoop$0, test, bool, Object$*)},
	{}
};
$ClassInfo InvokerBytecodeGenerator$$Lambda$lambda$emitLoop$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.invoke.InvokerBytecodeGenerator$$Lambda$lambda$emitLoop$0",
	"java.lang.Object",
	"java.util.function.Predicate",
	nullptr,
	methodInfos
};
$Class* InvokerBytecodeGenerator$$Lambda$lambda$emitLoop$0::load$($String* name, bool initialize) {
	$loadClass(InvokerBytecodeGenerator$$Lambda$lambda$emitLoop$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* InvokerBytecodeGenerator$$Lambda$lambda$emitLoop$0::class$ = nullptr;

class InvokerBytecodeGenerator$$Lambda$basicTypeClass$1 : public $Function {
	$class(InvokerBytecodeGenerator$$Lambda$basicTypeClass$1, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $of($sure($LambdaForm$BasicType, inst$)->basicTypeClass());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<InvokerBytecodeGenerator$$Lambda$basicTypeClass$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo InvokerBytecodeGenerator$$Lambda$basicTypeClass$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(InvokerBytecodeGenerator$$Lambda$basicTypeClass$1, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(InvokerBytecodeGenerator$$Lambda$basicTypeClass$1, apply, $Object*, Object$*)},
	{}
};
$ClassInfo InvokerBytecodeGenerator$$Lambda$basicTypeClass$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.invoke.InvokerBytecodeGenerator$$Lambda$basicTypeClass$1",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* InvokerBytecodeGenerator$$Lambda$basicTypeClass$1::load$($String* name, bool initialize) {
	$loadClass(InvokerBytecodeGenerator$$Lambda$basicTypeClass$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* InvokerBytecodeGenerator$$Lambda$basicTypeClass$1::class$ = nullptr;

class InvokerBytecodeGenerator$$Lambda$lambda$emitLoop$1$2 : public $IntFunction {
	$class(InvokerBytecodeGenerator$$Lambda$lambda$emitLoop$1$2, $NO_CLASS_INIT, $IntFunction)
public:
	void init$() {
	}
	virtual $Object* apply(int32_t x$0) override {
		 return $of(InvokerBytecodeGenerator::lambda$emitLoop$1(x$0));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<InvokerBytecodeGenerator$$Lambda$lambda$emitLoop$1$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo InvokerBytecodeGenerator$$Lambda$lambda$emitLoop$1$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(InvokerBytecodeGenerator$$Lambda$lambda$emitLoop$1$2, init$, void)},
	{"apply", "(I)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(InvokerBytecodeGenerator$$Lambda$lambda$emitLoop$1$2, apply, $Object*, int32_t)},
	{}
};
$ClassInfo InvokerBytecodeGenerator$$Lambda$lambda$emitLoop$1$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.invoke.InvokerBytecodeGenerator$$Lambda$lambda$emitLoop$1$2",
	"java.lang.Object",
	"java.util.function.IntFunction",
	nullptr,
	methodInfos
};
$Class* InvokerBytecodeGenerator$$Lambda$lambda$emitLoop$1$2::load$($String* name, bool initialize) {
	$loadClass(InvokerBytecodeGenerator$$Lambda$lambda$emitLoop$1$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* InvokerBytecodeGenerator$$Lambda$lambda$emitLoop$1$2::class$ = nullptr;

$FieldInfo _InvokerBytecodeGenerator_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(InvokerBytecodeGenerator, $assertionsDisabled)},
	{"MH", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InvokerBytecodeGenerator, MH)},
	{"MHI", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InvokerBytecodeGenerator, MHI)},
	{"LF", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InvokerBytecodeGenerator, LF)},
	{"LFN", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InvokerBytecodeGenerator, LFN)},
	{"CLS", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InvokerBytecodeGenerator, CLS)},
	{"OBJ", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InvokerBytecodeGenerator, OBJ)},
	{"OBJARY", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InvokerBytecodeGenerator, OBJARY)},
	{"LOOP_CLAUSES", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InvokerBytecodeGenerator, LOOP_CLAUSES)},
	{"MHARY2", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InvokerBytecodeGenerator, MHARY2)},
	{"MH_SIG", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InvokerBytecodeGenerator, MH_SIG)},
	{"LF_SIG", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InvokerBytecodeGenerator, LF_SIG)},
	{"LFN_SIG", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InvokerBytecodeGenerator, LFN_SIG)},
	{"LL_SIG", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InvokerBytecodeGenerator, LL_SIG)},
	{"LLV_SIG", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InvokerBytecodeGenerator, LLV_SIG)},
	{"CLASS_PREFIX", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InvokerBytecodeGenerator, CLASS_PREFIX)},
	{"SOURCE_PREFIX", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InvokerBytecodeGenerator, SOURCE_PREFIX)},
	{"INVOKER_SUPER_NAME", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(InvokerBytecodeGenerator, INVOKER_SUPER_NAME)},
	{"name", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(InvokerBytecodeGenerator, name)},
	{"className", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(InvokerBytecodeGenerator, className$)},
	{"lambdaForm", "Ljava/lang/invoke/LambdaForm;", nullptr, $PRIVATE | $FINAL, $field(InvokerBytecodeGenerator, lambdaForm)},
	{"invokerName", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(InvokerBytecodeGenerator, invokerName)},
	{"invokerType", "Ljava/lang/invoke/MethodType;", nullptr, $PRIVATE | $FINAL, $field(InvokerBytecodeGenerator, invokerType)},
	{"localsMap", "[I", nullptr, $PRIVATE, $field(InvokerBytecodeGenerator, localsMap)},
	{"localClasses", "[Ljava/lang/Class;", "[Ljava/lang/Class<*>;", $PRIVATE, $field(InvokerBytecodeGenerator, localClasses)},
	{"cw", "Ljdk/internal/org/objectweb/asm/ClassWriter;", nullptr, $PRIVATE, $field(InvokerBytecodeGenerator, cw)},
	{"mv", "Ljdk/internal/org/objectweb/asm/MethodVisitor;", nullptr, $PRIVATE, $field(InvokerBytecodeGenerator, mv)},
	{"classData", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/invoke/InvokerBytecodeGenerator$ClassData;>;", $PRIVATE | $FINAL, $field(InvokerBytecodeGenerator, classData$)},
	{"lastClass", "Ljava/lang/Class;", "Ljava/lang/Class<*>;", $PRIVATE, $field(InvokerBytecodeGenerator, lastClass)},
	{"lastInternalName", "Ljava/lang/String;", nullptr, $PRIVATE, $field(InvokerBytecodeGenerator, lastInternalName)},
	{"MEMBERNAME_FACTORY", "Ljava/lang/invoke/MemberName$Factory;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InvokerBytecodeGenerator, MEMBERNAME_FACTORY)},
	{"HOST_CLASS", "Ljava/lang/Class;", "Ljava/lang/Class<*>;", $PRIVATE | $STATIC | $FINAL, $staticField(InvokerBytecodeGenerator, HOST_CLASS)},
	{"LOOKUP", "Ljava/lang/invoke/MethodHandles$Lookup;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InvokerBytecodeGenerator, LOOKUP)},
	{"DUMP_CLASS_FILES_COUNTERS", "Ljava/util/HashMap;", "Ljava/util/HashMap<Ljava/lang/String;Ljava/lang/Integer;>;", $PRIVATE | $STATIC | $FINAL, $staticField(InvokerBytecodeGenerator, DUMP_CLASS_FILES_COUNTERS)},
	{"DUMP_CLASS_FILES_DIR", "Ljava/io/File;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InvokerBytecodeGenerator, DUMP_CLASS_FILES_DIR)},
	{"DONTINLINE_SIG", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(InvokerBytecodeGenerator, DONTINLINE_SIG)},
	{"FORCEINLINE_SIG", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(InvokerBytecodeGenerator, FORCEINLINE_SIG)},
	{"HIDDEN_SIG", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(InvokerBytecodeGenerator, HIDDEN_SIG)},
	{"INJECTEDPROFILE_SIG", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(InvokerBytecodeGenerator, INJECTEDPROFILE_SIG)},
	{"LF_COMPILED_SIG", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(InvokerBytecodeGenerator, LF_COMPILED_SIG)},
	{"STATICALLY_INVOCABLE_PACKAGES", "[Ljava/lang/Class;", "[Ljava/lang/Class<*>;", $PRIVATE | $STATIC | $FINAL, $staticField(InvokerBytecodeGenerator, STATICALLY_INVOCABLE_PACKAGES)},
	{}
};

$MethodInfo _InvokerBytecodeGenerator_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/invoke/LambdaForm;ILjava/lang/String;Ljava/lang/String;Ljava/lang/invoke/MethodType;)V", nullptr, $PRIVATE, $method(InvokerBytecodeGenerator, init$, void, $LambdaForm*, int32_t, $String*, $String*, $MethodType*)},
	{"<init>", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/invoke/MethodType;)V", nullptr, $PRIVATE, $method(InvokerBytecodeGenerator, init$, void, $String*, $String*, $MethodType*)},
	{"<init>", "(Ljava/lang/String;Ljava/lang/invoke/LambdaForm;Ljava/lang/invoke/MethodType;)V", nullptr, $PRIVATE, $method(InvokerBytecodeGenerator, init$, void, $String*, $LambdaForm*, $MethodType*)},
	{"<init>", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/invoke/LambdaForm;Ljava/lang/invoke/MethodType;)V", nullptr, 0, $method(InvokerBytecodeGenerator, init$, void, $String*, $String*, $LambdaForm*, $MethodType*)},
	{"addMethod", "()V", nullptr, 0, $virtualMethod(InvokerBytecodeGenerator, addMethod, void)},
	{"arrayInsnOpcode", "(BI)I", nullptr, $PRIVATE, $method(InvokerBytecodeGenerator, arrayInsnOpcode, int32_t, int8_t, int32_t), "java.lang.InternalError"},
	{"arrayTypeCode", "(Lsun/invoke/util/Wrapper;)B", nullptr, $PRIVATE, $method(InvokerBytecodeGenerator, arrayTypeCode, int8_t, $Wrapper*)},
	{"assertStaticType", "(Ljava/lang/Class;Ljava/lang/invoke/LambdaForm$Name;)Z", "(Ljava/lang/Class<*>;Ljava/lang/invoke/LambdaForm$Name;)Z", $PRIVATE, $method(InvokerBytecodeGenerator, assertStaticType, bool, $Class*, $LambdaForm$Name*)},
	{"bogusMethod", "(Ljava/lang/Object;)V", nullptr, $PRIVATE, $method(InvokerBytecodeGenerator, bogusMethod, void, Object$*)},
	{"checkActualReceiver", "()Z", nullptr, $PRIVATE, $method(InvokerBytecodeGenerator, checkActualReceiver, bool)},
	{"checkClassName", "(Ljava/lang/String;)Z", nullptr, $STATIC, $staticMethod(InvokerBytecodeGenerator, checkClassName, bool, $String*)},
	{"classData", "(Ljava/lang/Object;)Ljava/lang/String;", nullptr, 0, $virtualMethod(InvokerBytecodeGenerator, classData, $String*, Object$*)},
	{"classDataValues", "()Ljava/util/List;", "()Ljava/util/List<Ljava/lang/Object;>;", 0, $virtualMethod(InvokerBytecodeGenerator, classDataValues, $List*)},
	{"classFilePrologue", "()Ljdk/internal/org/objectweb/asm/ClassWriter;", nullptr, $PRIVATE, $method(InvokerBytecodeGenerator, classFilePrologue, $ClassWriter*)},
	{"className", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $STATIC, $staticMethod(InvokerBytecodeGenerator, className, $String*, $String*)},
	{"clinit", "(Ljdk/internal/org/objectweb/asm/ClassWriter;Ljava/lang/String;Ljava/util/List;)V", "(Ljdk/internal/org/objectweb/asm/ClassWriter;Ljava/lang/String;Ljava/util/List<Ljava/lang/invoke/InvokerBytecodeGenerator$ClassData;>;)V", $STATIC, $staticMethod(InvokerBytecodeGenerator, clinit, void, $ClassWriter*, $String*, $List*)},
	{"debugString", "(Ljava/lang/Object;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(InvokerBytecodeGenerator, debugString, $String*, Object$*)},
	{"emitAloadInsn", "(I)V", nullptr, $PRIVATE, $method(InvokerBytecodeGenerator, emitAloadInsn, void, int32_t)},
	{"emitArrayLength", "(Ljava/lang/invoke/LambdaForm$Name;)V", nullptr, 0, $virtualMethod(InvokerBytecodeGenerator, emitArrayLength, void, $LambdaForm$Name*)},
	{"emitArrayLoad", "(Ljava/lang/invoke/LambdaForm$Name;)V", nullptr, 0, $virtualMethod(InvokerBytecodeGenerator, emitArrayLoad, void, $LambdaForm$Name*)},
	{"emitArrayOp", "(Ljava/lang/invoke/LambdaForm$Name;I)V", nullptr, 0, $virtualMethod(InvokerBytecodeGenerator, emitArrayOp, void, $LambdaForm$Name*, int32_t)},
	{"emitArrayStore", "(Ljava/lang/invoke/LambdaForm$Name;)V", nullptr, 0, $virtualMethod(InvokerBytecodeGenerator, emitArrayStore, void, $LambdaForm$Name*)},
	{"emitAstoreInsn", "(I)V", nullptr, $PRIVATE, $method(InvokerBytecodeGenerator, emitAstoreInsn, void, int32_t)},
	{"emitBoxing", "(Lsun/invoke/util/Wrapper;)V", nullptr, $PRIVATE, $method(InvokerBytecodeGenerator, emitBoxing, void, $Wrapper*)},
	{"emitConst", "(Ljava/lang/Object;)V", nullptr, $PRIVATE, $method(InvokerBytecodeGenerator, emitConst, void, Object$*)},
	{"emitGuardWithCatch", "(I)Ljava/lang/invoke/LambdaForm$Name;", nullptr, $PRIVATE, $method(InvokerBytecodeGenerator, emitGuardWithCatch, $LambdaForm$Name*, int32_t)},
	{"emitI2X", "(Lsun/invoke/util/Wrapper;)V", nullptr, $PRIVATE, $method(InvokerBytecodeGenerator, emitI2X, void, $Wrapper*)},
	{"emitIconstInsn", "(I)V", nullptr, $PRIVATE, $method(InvokerBytecodeGenerator, emitIconstInsn, void, int32_t)},
	{"emitIconstInsn", "(Ljdk/internal/org/objectweb/asm/MethodVisitor;I)V", nullptr, $PRIVATE | $STATIC, $staticMethod(InvokerBytecodeGenerator, emitIconstInsn, void, $MethodVisitor*, int32_t)},
	{"emitImplicitConversion", "(Ljava/lang/invoke/LambdaForm$BasicType;Ljava/lang/Class;Ljava/lang/Object;)V", "(Ljava/lang/invoke/LambdaForm$BasicType;Ljava/lang/Class<*>;Ljava/lang/Object;)V", $PRIVATE, $method(InvokerBytecodeGenerator, emitImplicitConversion, void, $LambdaForm$BasicType*, $Class*, Object$*)},
	{"emitInvoke", "(Ljava/lang/invoke/LambdaForm$Name;)V", nullptr, 0, $virtualMethod(InvokerBytecodeGenerator, emitInvoke, void, $LambdaForm$Name*)},
	{"emitLoadInsn", "(Ljava/lang/invoke/LambdaForm$BasicType;I)V", nullptr, $PRIVATE, $method(InvokerBytecodeGenerator, emitLoadInsn, void, $LambdaForm$BasicType*, int32_t)},
	{"emitLoop", "(I)Ljava/lang/invoke/LambdaForm$Name;", nullptr, $PRIVATE, $method(InvokerBytecodeGenerator, emitLoop, $LambdaForm$Name*, int32_t)},
	{"emitLoopHandleInvoke", "(Ljava/lang/invoke/LambdaForm$Name;IILjava/lang/invoke/LambdaForm$Name;ZLjava/lang/invoke/MethodType;[Ljava/lang/Class;II)V", "(Ljava/lang/invoke/LambdaForm$Name;IILjava/lang/invoke/LambdaForm$Name;ZLjava/lang/invoke/MethodType;[Ljava/lang/Class<*>;II)V", $PRIVATE, $method(InvokerBytecodeGenerator, emitLoopHandleInvoke, void, $LambdaForm$Name*, int32_t, int32_t, $LambdaForm$Name*, bool, $MethodType*, $ClassArray*, int32_t, int32_t)},
	{"emitPopInsn", "(Ljava/lang/invoke/LambdaForm$BasicType;)V", nullptr, $PRIVATE, $method(InvokerBytecodeGenerator, emitPopInsn, void, $LambdaForm$BasicType*)},
	{"emitPrimCast", "(Lsun/invoke/util/Wrapper;Lsun/invoke/util/Wrapper;)V", nullptr, $PRIVATE, $method(InvokerBytecodeGenerator, emitPrimCast, void, $Wrapper*, $Wrapper*)},
	{"emitPushArgument", "(Ljava/lang/invoke/LambdaForm$Name;I)V", nullptr, $PRIVATE, $method(InvokerBytecodeGenerator, emitPushArgument, void, $LambdaForm$Name*, int32_t)},
	{"emitPushArgument", "(Ljava/lang/Class;Ljava/lang/Object;)V", "(Ljava/lang/Class<*>;Ljava/lang/Object;)V", $PRIVATE, $method(InvokerBytecodeGenerator, emitPushArgument, void, $Class*, Object$*)},
	{"emitPushArguments", "(Ljava/lang/invoke/LambdaForm$Name;I)V", nullptr, $PRIVATE, $method(InvokerBytecodeGenerator, emitPushArguments, void, $LambdaForm$Name*, int32_t)},
	{"emitPushClauseArray", "(II)V", nullptr, $PRIVATE, $method(InvokerBytecodeGenerator, emitPushClauseArray, void, int32_t, int32_t)},
	{"emitReferenceCast", "(Ljava/lang/Class;Ljava/lang/Object;)V", "(Ljava/lang/Class<*>;Ljava/lang/Object;)V", $PRIVATE, $method(InvokerBytecodeGenerator, emitReferenceCast, void, $Class*, Object$*)},
	{"emitReturn", "(Ljava/lang/invoke/LambdaForm$Name;)V", nullptr, $PRIVATE, $method(InvokerBytecodeGenerator, emitReturn, void, $LambdaForm$Name*)},
	{"emitReturnInsn", "(Ljava/lang/invoke/LambdaForm$BasicType;)V", nullptr, $PRIVATE, $method(InvokerBytecodeGenerator, emitReturnInsn, void, $LambdaForm$BasicType*)},
	{"emitSelectAlternative", "(Ljava/lang/invoke/LambdaForm$Name;Ljava/lang/invoke/LambdaForm$Name;)Ljava/lang/invoke/LambdaForm$Name;", nullptr, $PRIVATE, $method(InvokerBytecodeGenerator, emitSelectAlternative, $LambdaForm$Name*, $LambdaForm$Name*, $LambdaForm$Name*)},
	{"emitStaticInvoke", "(Ljava/lang/invoke/LambdaForm$Name;)V", nullptr, 0, $virtualMethod(InvokerBytecodeGenerator, emitStaticInvoke, void, $LambdaForm$Name*)},
	{"emitStaticInvoke", "(Ljava/lang/invoke/MemberName;Ljava/lang/invoke/LambdaForm$Name;)V", nullptr, 0, $virtualMethod(InvokerBytecodeGenerator, emitStaticInvoke, void, $MemberName*, $LambdaForm$Name*)},
	{"emitStoreInsn", "(Ljava/lang/invoke/LambdaForm$BasicType;I)V", nullptr, $PRIVATE, $method(InvokerBytecodeGenerator, emitStoreInsn, void, $LambdaForm$BasicType*, int32_t)},
	{"emitStoreResult", "(Ljava/lang/invoke/LambdaForm$Name;)V", nullptr, $PRIVATE, $method(InvokerBytecodeGenerator, emitStoreResult, void, $LambdaForm$Name*)},
	{"emitTableSwitch", "(II)Ljava/lang/invoke/LambdaForm$Name;", nullptr, $PRIVATE, $method(InvokerBytecodeGenerator, emitTableSwitch, $LambdaForm$Name*, int32_t, int32_t)},
	{"emitTryFinally", "(I)Ljava/lang/invoke/LambdaForm$Name;", nullptr, $PRIVATE, $method(InvokerBytecodeGenerator, emitTryFinally, $LambdaForm$Name*, int32_t)},
	{"emitUnboxing", "(Lsun/invoke/util/Wrapper;)V", nullptr, $PRIVATE, $method(InvokerBytecodeGenerator, emitUnboxing, void, $Wrapper*)},
	{"emitX2I", "(Lsun/invoke/util/Wrapper;)V", nullptr, $PRIVATE, $method(InvokerBytecodeGenerator, emitX2I, void, $Wrapper*)},
	{"emitZero", "(Ljava/lang/invoke/LambdaForm$BasicType;)V", nullptr, $PRIVATE, $method(InvokerBytecodeGenerator, emitZero, void, $LambdaForm$BasicType*)},
	{"extendLocalsMap", "([Ljava/lang/Class;)I", "([Ljava/lang/Class<*>;)I", $PRIVATE, $method(InvokerBytecodeGenerator, extendLocalsMap, int32_t, $ClassArray*)},
	{"generateCustomizedCode", "(Ljava/lang/invoke/LambdaForm;Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/MemberName;", nullptr, $STATIC, $staticMethod(InvokerBytecodeGenerator, generateCustomizedCode, $MemberName*, $LambdaForm*, $MethodType*)},
	{"generateCustomizedCodeBytes", "()[B", nullptr, $PRIVATE, $method(InvokerBytecodeGenerator, generateCustomizedCodeBytes, $bytes*)},
	{"generateLambdaFormInterpreterEntryPoint", "(Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/MemberName;", nullptr, $STATIC, $staticMethod(InvokerBytecodeGenerator, generateLambdaFormInterpreterEntryPoint, $MemberName*, $MethodType*)},
	{"generateLambdaFormInterpreterEntryPointBytes", "()[B", nullptr, $PRIVATE, $method(InvokerBytecodeGenerator, generateLambdaFormInterpreterEntryPointBytes, $bytes*)},
	{"generateNamedFunctionInvoker", "(Ljava/lang/invoke/MethodTypeForm;)Ljava/lang/invoke/MemberName;", nullptr, $STATIC, $staticMethod(InvokerBytecodeGenerator, generateNamedFunctionInvoker, $MemberName*, $MethodTypeForm*)},
	{"generateNamedFunctionInvokerImpl", "(Ljava/lang/invoke/MethodTypeForm;)[B", nullptr, $PRIVATE, $method(InvokerBytecodeGenerator, generateNamedFunctionInvokerImpl, $bytes*, $MethodTypeForm*)},
	{"getInternalName", "(Ljava/lang/Class;)Ljava/lang/String;", "(Ljava/lang/Class<*>;)Ljava/lang/String;", $PRIVATE, $method(InvokerBytecodeGenerator, getInternalName, $String*, $Class*)},
	{"isStaticallyInvocable", "([Ljava/lang/invoke/LambdaForm$NamedFunction;)Z", nullptr, $STATIC | $TRANSIENT, $staticMethod(InvokerBytecodeGenerator, isStaticallyInvocable, bool, $LambdaForm$NamedFunctionArray*)},
	{"isStaticallyInvocable", "(Ljava/lang/invoke/LambdaForm$Name;)Z", nullptr, $STATIC, $staticMethod(InvokerBytecodeGenerator, isStaticallyInvocable, bool, $LambdaForm$Name*)},
	{"isStaticallyInvocable", "(Ljava/lang/invoke/MemberName;)Z", nullptr, $STATIC, $staticMethod(InvokerBytecodeGenerator, isStaticallyInvocable, bool, $MemberName*)},
	{"isStaticallyInvocableType", "(Ljava/lang/invoke/MethodType;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(InvokerBytecodeGenerator, isStaticallyInvocableType, bool, $MethodType*)},
	{"isStaticallyNameable", "(Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;)Z", $STATIC, $staticMethod(InvokerBytecodeGenerator, isStaticallyNameable, bool, $Class*)},
	{"lambda$emitLoop$0", "(Ljava/lang/invoke/LambdaForm$BasicType;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(InvokerBytecodeGenerator, lambda$emitLoop$0, bool, $LambdaForm$BasicType*)},
	{"lambda$emitLoop$1", "(I)[Ljava/lang/Class;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(InvokerBytecodeGenerator, lambda$emitLoop$1, $ClassArray*, int32_t)},
	{"loadInsnOpcode", "(Ljava/lang/invoke/LambdaForm$BasicType;)I", nullptr, $PRIVATE, $method(InvokerBytecodeGenerator, loadInsnOpcode, int32_t, $LambdaForm$BasicType*), "java.lang.InternalError"},
	{"loadMethod", "([B)Ljava/lang/invoke/MemberName;", nullptr, $PRIVATE, $method(InvokerBytecodeGenerator, loadMethod, $MemberName*, $bytes*)},
	{"lookup", "()Ljava/lang/invoke/MethodHandles$Lookup;", nullptr, $PRIVATE | $STATIC, $staticMethod(InvokerBytecodeGenerator, lookup, $MethodHandles$Lookup*)},
	{"lookupPregenerated", "(Ljava/lang/invoke/LambdaForm;Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/MemberName;", nullptr, $PRIVATE | $STATIC, $staticMethod(InvokerBytecodeGenerator, lookupPregenerated, $MemberName*, $LambdaForm*, $MethodType*)},
	{"makeDumpableClassName", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(InvokerBytecodeGenerator, makeDumpableClassName, $String*, $String*)},
	{"maybeDump", "([B)V", nullptr, $PRIVATE, $method(InvokerBytecodeGenerator, maybeDump, void, $bytes*)},
	{"maybeDump", "(Ljava/lang/String;[B)V", nullptr, $STATIC, $staticMethod(InvokerBytecodeGenerator, maybeDump, void, $String*, $bytes*)},
	{"methodEpilogue", "()V", nullptr, $PRIVATE, $method(InvokerBytecodeGenerator, methodEpilogue, void)},
	{"methodPrologue", "()V", nullptr, $PRIVATE, $method(InvokerBytecodeGenerator, methodPrologue, void)},
	{"popInsnOpcode", "(Ljava/lang/invoke/LambdaForm$BasicType;)I", nullptr, $PRIVATE | $STATIC, $staticMethod(InvokerBytecodeGenerator, popInsnOpcode, int32_t, $LambdaForm$BasicType*)},
	{"refKindOpcode", "(B)I", nullptr, 0, $virtualMethod(InvokerBytecodeGenerator, refKindOpcode, int32_t, int8_t)},
	{"resolveFrom", "(Ljava/lang/String;Ljava/lang/invoke/MethodType;Ljava/lang/Class;)Ljava/lang/invoke/MemberName;", "(Ljava/lang/String;Ljava/lang/invoke/MethodType;Ljava/lang/Class<*>;)Ljava/lang/invoke/MemberName;", $PRIVATE | $STATIC, $staticMethod(InvokerBytecodeGenerator, resolveFrom, $MemberName*, $String*, $MethodType*, $Class*)},
	{"resolveInvokerMember", "(Ljava/lang/Class;Ljava/lang/String;Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/MemberName;", "(Ljava/lang/Class<*>;Ljava/lang/String;Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/MemberName;", $PRIVATE | $STATIC, $staticMethod(InvokerBytecodeGenerator, resolveInvokerMember, $MemberName*, $Class*, $String*, $MethodType*)},
	{"setClassWriter", "(Ljdk/internal/org/objectweb/asm/ClassWriter;)V", nullptr, 0, $virtualMethod(InvokerBytecodeGenerator, setClassWriter, void, $ClassWriter*)},
	{"storeInsnOpcode", "(Ljava/lang/invoke/LambdaForm$BasicType;)I", nullptr, $PRIVATE, $method(InvokerBytecodeGenerator, storeInsnOpcode, int32_t, $LambdaForm$BasicType*), "java.lang.InternalError"},
	{"toByteArray", "()[B", nullptr, $PRIVATE, $method(InvokerBytecodeGenerator, toByteArray, $bytes*)},
	{}
};

$InnerClassInfo _InvokerBytecodeGenerator_InnerClassesInfo_[] = {
	{"java.lang.invoke.InvokerBytecodeGenerator$2", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{"java.lang.invoke.InvokerBytecodeGenerator$BytecodeGenerationException", "java.lang.invoke.InvokerBytecodeGenerator", "BytecodeGenerationException", $STATIC | $FINAL},
	{"java.lang.invoke.InvokerBytecodeGenerator$ClassData", "java.lang.invoke.InvokerBytecodeGenerator", "ClassData", $STATIC},
	{"java.lang.invoke.InvokerBytecodeGenerator$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _InvokerBytecodeGenerator_ClassInfo_ = {
	$ACC_SUPER,
	"java.lang.invoke.InvokerBytecodeGenerator",
	"java.lang.Object",
	nullptr,
	_InvokerBytecodeGenerator_FieldInfo_,
	_InvokerBytecodeGenerator_MethodInfo_,
	nullptr,
	nullptr,
	_InvokerBytecodeGenerator_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.lang.invoke.InvokerBytecodeGenerator$2,java.lang.invoke.InvokerBytecodeGenerator$BytecodeGenerationException,java.lang.invoke.InvokerBytecodeGenerator$ClassData,java.lang.invoke.InvokerBytecodeGenerator$1"
};

$Object* allocate$InvokerBytecodeGenerator($Class* clazz) {
	return $of($alloc(InvokerBytecodeGenerator));
}

bool InvokerBytecodeGenerator::$assertionsDisabled = false;
$String* InvokerBytecodeGenerator::MH = nullptr;
$String* InvokerBytecodeGenerator::MHI = nullptr;
$String* InvokerBytecodeGenerator::LF = nullptr;
$String* InvokerBytecodeGenerator::LFN = nullptr;
$String* InvokerBytecodeGenerator::CLS = nullptr;
$String* InvokerBytecodeGenerator::OBJ = nullptr;
$String* InvokerBytecodeGenerator::OBJARY = nullptr;
$String* InvokerBytecodeGenerator::LOOP_CLAUSES = nullptr;
$String* InvokerBytecodeGenerator::MHARY2 = nullptr;
$String* InvokerBytecodeGenerator::MH_SIG = nullptr;
$String* InvokerBytecodeGenerator::LF_SIG = nullptr;
$String* InvokerBytecodeGenerator::LFN_SIG = nullptr;
$String* InvokerBytecodeGenerator::LL_SIG = nullptr;
$String* InvokerBytecodeGenerator::LLV_SIG = nullptr;
$String* InvokerBytecodeGenerator::CLASS_PREFIX = nullptr;
$String* InvokerBytecodeGenerator::SOURCE_PREFIX = nullptr;
$String* InvokerBytecodeGenerator::INVOKER_SUPER_NAME = nullptr;
$MemberName$Factory* InvokerBytecodeGenerator::MEMBERNAME_FACTORY = nullptr;
$Class* InvokerBytecodeGenerator::HOST_CLASS = nullptr;
$MethodHandles$Lookup* InvokerBytecodeGenerator::LOOKUP = nullptr;
$HashMap* InvokerBytecodeGenerator::DUMP_CLASS_FILES_COUNTERS = nullptr;
$File* InvokerBytecodeGenerator::DUMP_CLASS_FILES_DIR = nullptr;
$String* InvokerBytecodeGenerator::DONTINLINE_SIG = nullptr;
$String* InvokerBytecodeGenerator::FORCEINLINE_SIG = nullptr;
$String* InvokerBytecodeGenerator::HIDDEN_SIG = nullptr;
$String* InvokerBytecodeGenerator::INJECTEDPROFILE_SIG = nullptr;
$String* InvokerBytecodeGenerator::LF_COMPILED_SIG = nullptr;
$ClassArray* InvokerBytecodeGenerator::STATICALLY_INVOCABLE_PACKAGES = nullptr;

$MethodHandles$Lookup* InvokerBytecodeGenerator::lookup() {
	$init(InvokerBytecodeGenerator);
	try {
		$init($MethodHandles$Lookup);
		return $MethodHandles::privateLookupIn(InvokerBytecodeGenerator::HOST_CLASS, $MethodHandles$Lookup::IMPL_LOOKUP);
	} catch ($IllegalAccessException& e) {
		$throw($($MethodHandleStatics::newInternalError(static_cast<$Exception*>(e))));
	}
	$shouldNotReachHere();
}

void InvokerBytecodeGenerator::init$($LambdaForm* lambdaForm, int32_t localsMapSize, $String* name$renamed, $String* invokerName$renamed, $MethodType* invokerType) {
	$useLocalCurrentObjectStackCache();
	$var($String, name, name$renamed);
	$var($String, invokerName, invokerName$renamed);
	$set(this, classData$, $new($ArrayList));
	int32_t p = $nc(invokerName)->indexOf((int32_t)u'.');
	if (p > -1) {
		$assign(name, invokerName->substring(0, p));
		$assign(invokerName, invokerName->substring(p + 1));
	}
	$init($MethodHandleStatics);
	if ($MethodHandleStatics::DUMP_CLASS_FILES) {
		$assign(name, makeDumpableClassName(name));
	}
	$set(this, name, name);
	$set(this, className$, $str({InvokerBytecodeGenerator::CLASS_PREFIX, name}));
	$set(this, lambdaForm, lambdaForm);
	$set(this, invokerName, invokerName);
	$set(this, invokerType, invokerType);
	$set(this, localsMap, $new($ints, localsMapSize + 1));
	$set(this, localClasses, $new($ClassArray, localsMapSize + 1));
}

void InvokerBytecodeGenerator::init$($String* name, $String* invokerName, $MethodType* invokerType) {
	$useLocalCurrentObjectStackCache();
	InvokerBytecodeGenerator::init$(nullptr, $nc(invokerType)->parameterCount(), name, invokerName, invokerType);
	$var($MethodType, mt, $nc(invokerType)->erase());
	$nc(this->localsMap)->set(0, 0);
	{
		int32_t i = 1;
		int32_t index = 0;
		for (; i < $nc(this->localsMap)->length; ++i) {
			$Wrapper* w = $Wrapper::forBasicType($($cast($Class, $nc(mt)->parameterType(i - 1))));
			index += $nc(w)->stackSlots();
			$nc(this->localsMap)->set(i, index);
		}
	}
}

void InvokerBytecodeGenerator::init$($String* name, $LambdaForm* form, $MethodType* invokerType) {
	InvokerBytecodeGenerator::init$(name, $($nc(form)->lambdaName()), form, invokerType);
}

void InvokerBytecodeGenerator::init$($String* name, $String* invokerName, $LambdaForm* form, $MethodType* invokerType) {
	InvokerBytecodeGenerator::init$(form, $nc($nc(form)->names)->length, name, invokerName, invokerType);
	$var($LambdaForm$NameArray, names, $nc(form)->names);
	{
		int32_t i = 0;
		int32_t index = 0;
		for (; i < $nc(this->localsMap)->length; ++i) {
			$nc(this->localsMap)->set(i, index);
			if (i < $nc(names)->length) {
				$LambdaForm$BasicType* type = $nc(names->get(i))->type();
				index += $nc(type)->basicTypeSlots();
			}
		}
	}
}

void InvokerBytecodeGenerator::maybeDump($bytes* classFile) {
	$init($MethodHandleStatics);
	if ($MethodHandleStatics::DUMP_CLASS_FILES) {
		maybeDump(this->className$, classFile);
	}
}

void InvokerBytecodeGenerator::maybeDump($String* className, $bytes* classFile) {
	$init(InvokerBytecodeGenerator);
	$beforeCallerSensitive();
	$init($MethodHandleStatics);
	if ($MethodHandleStatics::DUMP_CLASS_FILES) {
		$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($InvokerBytecodeGenerator$1, className, classFile)));
	}
}

$String* InvokerBytecodeGenerator::makeDumpableClassName($String* className$renamed) {
	$init(InvokerBytecodeGenerator);
	$useLocalCurrentObjectStackCache();
	$var($String, className, className$renamed);
	$var($Integer, ctr, nullptr);
	$synchronized(InvokerBytecodeGenerator::DUMP_CLASS_FILES_COUNTERS) {
		$assign(ctr, $cast($Integer, $nc(InvokerBytecodeGenerator::DUMP_CLASS_FILES_COUNTERS)->get(className)));
		if (ctr == nullptr) {
			$assign(ctr, $Integer::valueOf(0));
		}
		$nc(InvokerBytecodeGenerator::DUMP_CLASS_FILES_COUNTERS)->put(className, $($Integer::valueOf($nc(ctr)->intValue() + 1)));
	}
	$var($String, sfx, $nc(ctr)->toString());
	while ($nc(sfx)->length() < 3) {
		$assign(sfx, $str({"0"_s, sfx}));
	}
	$plusAssign(className, sfx);
	return className;
}

$String* InvokerBytecodeGenerator::classData(Object$* arg) {
	$useLocalCurrentObjectStackCache();
	$var($String, desc, nullptr);
	if ($instanceOf($Class, arg)) {
		$assign(desc, "Ljava/lang/Class;"_s);
	} else if ($instanceOf($MethodHandle, arg)) {
		$assign(desc, InvokerBytecodeGenerator::MH_SIG);
	} else if ($instanceOf($LambdaForm, arg)) {
		$assign(desc, InvokerBytecodeGenerator::LF_SIG);
	} else {
		$assign(desc, "Ljava/lang/Object;"_s);
	}
	$var($String, name, nullptr);
	$init($MethodHandleStatics);
	if ($MethodHandleStatics::DUMP_CLASS_FILES) {
		$Class* c = $nc($of(arg))->getClass();
		while ($nc(c)->isArray()) {
			c = c->getComponentType();
		}
		$var($String, var$0, $$str({"_DATA_"_s, $($nc(c)->getSimpleName()), "_"_s}));
		$assign(name, $concat(var$0, $$str($nc(this->classData$)->size())));
	} else {
		$assign(name, $str({"_D_"_s, $$str($nc(this->classData$)->size())}));
	}
	$var($InvokerBytecodeGenerator$ClassData, cd, $new($InvokerBytecodeGenerator$ClassData, name, desc, arg));
	$nc(this->classData$)->add(cd);
	return name;
}

$List* InvokerBytecodeGenerator::classDataValues() {
	$useLocalCurrentObjectStackCache();
	$var($List, cd, this->classData$);

	$var($List, var$0, nullptr)
	switch ($nc(cd)->size()) {
	case 0:
		{
			$assign(var$0, $List::of());
			break;
		}
	case 1:
		{
			$assign(var$0, $List::of($nc(($cast($InvokerBytecodeGenerator$ClassData, $(cd->get(0)))))->value));
			break;
		}
	case 2:
		{
			$var($Object, var$1, $nc(($cast($InvokerBytecodeGenerator$ClassData, $(cd->get(0)))))->value);
			$assign(var$0, $List::of(var$1, $nc(($cast($InvokerBytecodeGenerator$ClassData, $(cd->get(1)))))->value));
			break;
		}
	case 3:
		{
			$var($Object, var$2, $nc(($cast($InvokerBytecodeGenerator$ClassData, $(cd->get(0)))))->value);
			$var($Object, var$3, $nc(($cast($InvokerBytecodeGenerator$ClassData, $(cd->get(1)))))->value);
			$assign(var$0, $List::of(var$2, var$3, $nc(($cast($InvokerBytecodeGenerator$ClassData, $(cd->get(2)))))->value));
			break;
		}
	case 4:
		{
			$var($Object, var$4, $nc(($cast($InvokerBytecodeGenerator$ClassData, $(cd->get(0)))))->value);
			$var($Object, var$5, $nc(($cast($InvokerBytecodeGenerator$ClassData, $(cd->get(1)))))->value);
			$var($Object, var$6, $nc(($cast($InvokerBytecodeGenerator$ClassData, $(cd->get(2)))))->value);
			$assign(var$0, $List::of(var$4, var$5, var$6, $nc(($cast($InvokerBytecodeGenerator$ClassData, $(cd->get(3)))))->value));
			break;
		}
	default:
		{
			{
				$var($ObjectArray, data, $new($ObjectArray, $nc(this->classData$)->size()));
				for (int32_t i = 0; i < $nc(this->classData$)->size(); ++i) {
					data->set(i, $nc(($cast($InvokerBytecodeGenerator$ClassData, $($nc(this->classData$)->get(i)))))->value);
				}
				$assign(var$0, $List::of(data));
				break;
			}
		}
	}
	return var$0;
}

$String* InvokerBytecodeGenerator::debugString(Object$* arg) {
	$init(InvokerBytecodeGenerator);
	$useLocalCurrentObjectStackCache();
	{
		$var($MethodHandle, mh, nullptr);
		bool var$0 = $instanceOf($MethodHandle, arg);
		if (var$0) {
			$assign(mh, $cast($MethodHandle, arg));
			var$0 = true;
		}
		if (var$0) {
			$var($MemberName, member, $nc(mh)->internalMemberName());
			if (member != nullptr) {
				return member->toString();
			}
			return mh->debugString();
		}
	}
	return $nc($of(arg))->toString();
}

$MemberName* InvokerBytecodeGenerator::loadMethod($bytes* classFile) {
	$useLocalCurrentObjectStackCache();
	$Class* invokerClass = $nc($($nc(InvokerBytecodeGenerator::LOOKUP)->makeHiddenClassDefiner(this->className$, classFile)))->defineClass(true, $(classDataValues()));
	return resolveInvokerMember(invokerClass, this->invokerName, this->invokerType);
}

$MemberName* InvokerBytecodeGenerator::resolveInvokerMember($Class* invokerClass, $String* name, $MethodType* type) {
	$init(InvokerBytecodeGenerator);
	$useLocalCurrentObjectStackCache();
	$var($MemberName, member, $new($MemberName, invokerClass, name, type, (int8_t)6));
	try {
		$load($ReflectiveOperationException);
		$assign(member, $nc(InvokerBytecodeGenerator::MEMBERNAME_FACTORY)->resolveOrFail((int8_t)6, member, InvokerBytecodeGenerator::HOST_CLASS, -1, $ReflectiveOperationException::class$));
	} catch ($ReflectiveOperationException& e) {
		$throw($($MethodHandleStatics::newInternalError(static_cast<$Exception*>(e))));
	}
	return member;
}

$ClassWriter* InvokerBytecodeGenerator::classFilePrologue() {
	$useLocalCurrentObjectStackCache();
	int32_t NOT_ACC_PUBLIC = 0;
	$var($ClassWriter, cw, $new($ClassWriter, $ClassWriter::COMPUTE_MAXS + $ClassWriter::COMPUTE_FRAMES));
	setClassWriter(cw);
	cw->visit($Opcodes::V1_8, NOT_ACC_PUBLIC + $Opcodes::ACC_FINAL + $Opcodes::ACC_SUPER, this->className$, nullptr, InvokerBytecodeGenerator::INVOKER_SUPER_NAME, nullptr);
	cw->visitSource($$str({InvokerBytecodeGenerator::SOURCE_PREFIX, this->name}), nullptr);
	return cw;
}

void InvokerBytecodeGenerator::methodPrologue() {
	$var($String, invokerDesc, $nc(this->invokerType)->toMethodDescriptorString());
	$set(this, mv, $nc(this->cw)->visitMethod($Opcodes::ACC_STATIC, this->invokerName, invokerDesc, nullptr, nullptr));
}

void InvokerBytecodeGenerator::methodEpilogue() {
	$nc(this->mv)->visitMaxs(0, 0);
	$nc(this->mv)->visitEnd();
}

void InvokerBytecodeGenerator::clinit($ClassWriter* cw, $String* className, $List* classData) {
	$init(InvokerBytecodeGenerator);
	$useLocalCurrentObjectStackCache();
	if ($nc(classData)->isEmpty()) {
		return;
	}
	{
		$var($Iterator, i$, $nc(classData)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($InvokerBytecodeGenerator$ClassData, p, $cast($InvokerBytecodeGenerator$ClassData, i$->next()));
			{
				$var($FieldVisitor, fv, $nc(cw)->visitField($Opcodes::ACC_STATIC | $Opcodes::ACC_FINAL, $nc(p)->name$, p->desc, nullptr, nullptr));
				$nc(fv)->visitEnd();
			}
		}
	}
	$var($MethodVisitor, mv, $nc(cw)->visitMethod($Opcodes::ACC_STATIC, "<clinit>"_s, "()V"_s, nullptr, nullptr));
	$nc(mv)->visitCode();
	mv->visitLdcInsn($($Type::getType($$str({"L"_s, className, ";"_s}))));
	mv->visitMethodInsn($Opcodes::INVOKESTATIC, "java/lang/invoke/MethodHandleNatives"_s, "classData"_s, "(Ljava/lang/Class;)Ljava/lang/Object;"_s, false);
	mv->visitTypeInsn($Opcodes::CHECKCAST, "java/util/List"_s);
	mv->visitVarInsn($Opcodes::ASTORE, 0);
	int32_t index = 0;
	{
		$var($Iterator, i$, classData->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($InvokerBytecodeGenerator$ClassData, p, $cast($InvokerBytecodeGenerator$ClassData, i$->next()));
			{
				mv->visitVarInsn($Opcodes::ALOAD, 0);
				emitIconstInsn(mv, index++);
				mv->visitMethodInsn($Opcodes::INVOKEINTERFACE, "java/util/List"_s, "get"_s, "(I)Ljava/lang/Object;"_s, true);
				mv->visitTypeInsn($Opcodes::CHECKCAST, $($nc($nc(p)->desc)->substring(1, $nc(p->desc)->length() - 1)));
				mv->visitFieldInsn($Opcodes::PUTSTATIC, className, $nc(p)->name$, p->desc);
			}
		}
	}
	mv->visitInsn($Opcodes::RETURN);
	mv->visitMaxs(2, 1);
	mv->visitEnd();
}

void InvokerBytecodeGenerator::emitConst(Object$* con) {
	if (con == nullptr) {
		$nc(this->mv)->visitInsn($Opcodes::ACONST_NULL);
		return;
	}
	if ($instanceOf($Integer, con)) {
		emitIconstInsn($nc(($cast($Integer, con)))->intValue());
		return;
	}
	if ($instanceOf($Byte, con)) {
		emitIconstInsn($nc(($cast($Byte, con)))->byteValue());
		return;
	}
	if ($instanceOf($Short, con)) {
		emitIconstInsn($nc(($cast($Short, con)))->shortValue());
		return;
	}
	if ($instanceOf($Character, con)) {
		emitIconstInsn($nc(($cast($Character, con)))->charValue());
		return;
	}
	if ($instanceOf($Long, con)) {
		int64_t x = $nc(($cast($Long, con)))->longValue();
		int16_t sx = (int16_t)x;
		if (x == sx) {
			if (sx >= 0 && sx <= 1) {
				$nc(this->mv)->visitInsn($Opcodes::LCONST_0 + (int32_t)sx);
			} else {
				emitIconstInsn((int32_t)x);
				$nc(this->mv)->visitInsn($Opcodes::I2L);
			}
			return;
		}
	}
	if ($instanceOf($Float, con)) {
		float x = $nc(($cast($Float, con)))->floatValue();
		int16_t sx = $cast(int16_t, x);
		if (x == sx) {
			if (sx >= 0 && sx <= 2) {
				$nc(this->mv)->visitInsn($Opcodes::FCONST_0 + (int32_t)sx);
			} else {
				emitIconstInsn($cast(int32_t, x));
				$nc(this->mv)->visitInsn($Opcodes::I2F);
			}
			return;
		}
	}
	if ($instanceOf($Double, con)) {
		double x = $nc(($cast($Double, con)))->doubleValue();
		int16_t sx = $cast(int16_t, x);
		if (x == sx) {
			if (sx >= 0 && sx <= 1) {
				$nc(this->mv)->visitInsn($Opcodes::DCONST_0 + (int32_t)sx);
			} else {
				emitIconstInsn($cast(int32_t, x));
				$nc(this->mv)->visitInsn($Opcodes::I2D);
			}
			return;
		}
	}
	if ($instanceOf($Boolean, con)) {
		emitIconstInsn($nc(($cast($Boolean, con)))->booleanValue() ? 1 : 0);
		return;
	}
	$nc(this->mv)->visitLdcInsn(con);
}

void InvokerBytecodeGenerator::emitIconstInsn(int32_t cst) {
	emitIconstInsn(this->mv, cst);
}

void InvokerBytecodeGenerator::emitIconstInsn($MethodVisitor* mv, int32_t cst) {
	$init(InvokerBytecodeGenerator);
	if (cst >= -1 && cst <= 5) {
		$nc(mv)->visitInsn($Opcodes::ICONST_0 + cst);
	} else if (cst >= $Byte::MIN_VALUE && cst <= $Byte::MAX_VALUE) {
		$nc(mv)->visitIntInsn($Opcodes::BIPUSH, cst);
	} else if (cst >= $Short::MIN_VALUE && cst <= $Short::MAX_VALUE) {
		$nc(mv)->visitIntInsn($Opcodes::SIPUSH, cst);
	} else {
		$nc(mv)->visitLdcInsn($($Integer::valueOf(cst)));
	}
}

void InvokerBytecodeGenerator::emitLoadInsn($LambdaForm$BasicType* type, int32_t index) {
	int32_t opcode = loadInsnOpcode(type);
	$nc(this->mv)->visitVarInsn(opcode, $nc(this->localsMap)->get(index));
}

int32_t InvokerBytecodeGenerator::loadInsnOpcode($LambdaForm$BasicType* type) {
	$init($InvokerBytecodeGenerator$2);

	int32_t var$0 = 0;
	switch ($nc($InvokerBytecodeGenerator$2::$SwitchMap$java$lang$invoke$LambdaForm$BasicType)->get($nc((type))->ordinal())) {
	case 1:
		{
			var$0 = $Opcodes::ILOAD;
			break;
		}
	case 2:
		{
			var$0 = $Opcodes::LLOAD;
			break;
		}
	case 3:
		{
			var$0 = $Opcodes::FLOAD;
			break;
		}
	case 4:
		{
			var$0 = $Opcodes::DLOAD;
			break;
		}
	case 5:
		{
			var$0 = $Opcodes::ALOAD;
			break;
		}
	default:
		{
			$throwNew($InternalError, $$str({"unknown type: "_s, type}));
		}
	}
	return var$0;
}

void InvokerBytecodeGenerator::emitAloadInsn(int32_t index) {
	$init($LambdaForm$BasicType);
	emitLoadInsn($LambdaForm$BasicType::L_TYPE, index);
}

void InvokerBytecodeGenerator::emitStoreInsn($LambdaForm$BasicType* type, int32_t index) {
	int32_t opcode = storeInsnOpcode(type);
	$nc(this->mv)->visitVarInsn(opcode, $nc(this->localsMap)->get(index));
}

int32_t InvokerBytecodeGenerator::storeInsnOpcode($LambdaForm$BasicType* type) {
	$init($InvokerBytecodeGenerator$2);

	int32_t var$0 = 0;
	switch ($nc($InvokerBytecodeGenerator$2::$SwitchMap$java$lang$invoke$LambdaForm$BasicType)->get($nc((type))->ordinal())) {
	case 1:
		{
			var$0 = $Opcodes::ISTORE;
			break;
		}
	case 2:
		{
			var$0 = $Opcodes::LSTORE;
			break;
		}
	case 3:
		{
			var$0 = $Opcodes::FSTORE;
			break;
		}
	case 4:
		{
			var$0 = $Opcodes::DSTORE;
			break;
		}
	case 5:
		{
			var$0 = $Opcodes::ASTORE;
			break;
		}
	default:
		{
			$throwNew($InternalError, $$str({"unknown type: "_s, type}));
		}
	}
	return var$0;
}

void InvokerBytecodeGenerator::emitAstoreInsn(int32_t index) {
	$init($LambdaForm$BasicType);
	emitStoreInsn($LambdaForm$BasicType::L_TYPE, index);
}

int8_t InvokerBytecodeGenerator::arrayTypeCode($Wrapper* elementType) {
	$init($InvokerBytecodeGenerator$2);

	int32_t var$0 = 0;
	switch ($nc($InvokerBytecodeGenerator$2::$SwitchMap$sun$invoke$util$Wrapper)->get($nc((elementType))->ordinal())) {
	case 1:
		{
			var$0 = $Opcodes::T_BOOLEAN;
			break;
		}
	case 2:
		{
			var$0 = $Opcodes::T_BYTE;
			break;
		}
	case 3:
		{
			var$0 = $Opcodes::T_CHAR;
			break;
		}
	case 4:
		{
			var$0 = $Opcodes::T_SHORT;
			break;
		}
	case 5:
		{
			var$0 = $Opcodes::T_INT;
			break;
		}
	case 6:
		{
			var$0 = $Opcodes::T_LONG;
			break;
		}
	case 7:
		{
			var$0 = $Opcodes::T_FLOAT;
			break;
		}
	case 8:
		{
			var$0 = $Opcodes::T_DOUBLE;
			break;
		}
	case 9:
		{
			var$0 = 0;
			break;
		}
	default:
		{
			$throwNew($InternalError);
		}
	}
	return (int8_t)var$0;
}

int32_t InvokerBytecodeGenerator::arrayInsnOpcode(int8_t tcode, int32_t aaop) {
	if (!InvokerBytecodeGenerator::$assertionsDisabled && !(aaop == $Opcodes::AASTORE || aaop == $Opcodes::AALOAD)) {
		$throwNew($AssertionError);
	}

	int32_t var$0 = 0;
	switch (tcode) {
	case $Opcodes::T_BOOLEAN:
		{
			var$0 = $Opcodes::BASTORE;
			break;
		}
	case $Opcodes::T_BYTE:
		{
			var$0 = $Opcodes::BASTORE;
			break;
		}
	case $Opcodes::T_CHAR:
		{
			var$0 = $Opcodes::CASTORE;
			break;
		}
	case $Opcodes::T_SHORT:
		{
			var$0 = $Opcodes::SASTORE;
			break;
		}
	case $Opcodes::T_INT:
		{
			var$0 = $Opcodes::IASTORE;
			break;
		}
	case $Opcodes::T_LONG:
		{
			var$0 = $Opcodes::LASTORE;
			break;
		}
	case $Opcodes::T_FLOAT:
		{
			var$0 = $Opcodes::FASTORE;
			break;
		}
	case $Opcodes::T_DOUBLE:
		{
			var$0 = $Opcodes::DASTORE;
			break;
		}
	case 0:
		{
			var$0 = $Opcodes::AASTORE;
			break;
		}
	default:
		{
			$throwNew($InternalError);
		}
	}
	int32_t xas = var$0;
	return xas - $Opcodes::AASTORE + aaop;
}

void InvokerBytecodeGenerator::emitBoxing($Wrapper* wrapper) {
	$useLocalCurrentObjectStackCache();
	$var($String, owner, $str({"java/lang/"_s, $($nc($nc(wrapper)->wrapperType())->getSimpleName())}));
	$var($String, name, "valueOf"_s);
	$var($String, desc, $str({"("_s, $$str(wrapper->basicTypeChar()), ")L"_s, owner, ";"_s}));
	$nc(this->mv)->visitMethodInsn($Opcodes::INVOKESTATIC, owner, name, desc, false);
}

void InvokerBytecodeGenerator::emitUnboxing($Wrapper* wrapper) {
	$useLocalCurrentObjectStackCache();
	$var($String, owner, $str({"java/lang/"_s, $($nc($nc(wrapper)->wrapperType())->getSimpleName())}));
	$var($String, name, $str({$(wrapper->primitiveSimpleName()), "Value"_s}));
	$var($String, desc, $str({"()"_s, $$str(wrapper->basicTypeChar())}));
	emitReferenceCast(wrapper->wrapperType(), nullptr);
	$nc(this->mv)->visitMethodInsn($Opcodes::INVOKEVIRTUAL, owner, name, desc, false);
}

void InvokerBytecodeGenerator::emitImplicitConversion($LambdaForm$BasicType* ptype, $Class* pclass, Object$* arg) {
	$useLocalCurrentObjectStackCache();
	if (!InvokerBytecodeGenerator::$assertionsDisabled && !($LambdaForm$BasicType::basicType(pclass) == ptype)) {
		$throwNew($AssertionError);
	}
	if (pclass == $nc(ptype)->basicTypeClass() && ptype != $LambdaForm$BasicType::L_TYPE) {
		return;
	}
	$init($InvokerBytecodeGenerator$2);
	switch ($nc($InvokerBytecodeGenerator$2::$SwitchMap$java$lang$invoke$LambdaForm$BasicType)->get($nc((ptype))->ordinal())) {
	case 5:
		{
			if ($VerifyType::isNullConversion($Object::class$, pclass, false)) {
				$init($MethodHandleStatics);
				if ($MethodHandleStatics::PROFILE_LEVEL > 0) {
					emitReferenceCast($Object::class$, arg);
				}
				return;
			}
			emitReferenceCast(pclass, arg);
			return;
		}
	case 1:
		{
			$init($Integer);
			if (!$VerifyType::isNullConversion($Integer::TYPE, pclass, false)) {
				$var($Wrapper, var$0, ptype->basicTypeWrapper());
				emitPrimCast(var$0, $($Wrapper::forPrimitiveType(pclass)));
			}
			return;
		}
	}
	$throw($($MethodHandleStatics::newInternalError($$str({"bad implicit conversion: tc="_s, ptype, ": "_s, pclass}))));
}

bool InvokerBytecodeGenerator::assertStaticType($Class* cls, $LambdaForm$Name* n) {
	int32_t local = $nc(n)->index();
	$Class* aclass = $nc(this->localClasses)->get(local);
	if (aclass != nullptr && (aclass == cls || $nc(cls)->isAssignableFrom(aclass))) {
		return true;
	} else if (aclass == nullptr || $nc(aclass)->isAssignableFrom(cls)) {
		$nc(this->localClasses)->set(local, cls);
	}
	return false;
}

void InvokerBytecodeGenerator::emitReferenceCast($Class* cls, Object$* arg) {
	$useLocalCurrentObjectStackCache();
	$var($LambdaForm$Name, writeBack, nullptr);
	{
		$var($LambdaForm$Name, n, nullptr);
		bool var$0 = $instanceOf($LambdaForm$Name, arg);
		if (var$0) {
			$assign(n, $cast($LambdaForm$Name, arg));
			var$0 = true;
		}
		if (var$0) {
			if ($nc(this->lambdaForm)->useCount(n) > 1) {
				$assign(writeBack, n);
				if (assertStaticType(cls, n)) {
					return;
				}
			}
		}
	}
	if (isStaticallyNameable(cls)) {
		$var($String, sig, getInternalName(cls));
		$nc(this->mv)->visitTypeInsn($Opcodes::CHECKCAST, sig);
	} else {
		$nc(this->mv)->visitFieldInsn($Opcodes::GETSTATIC, this->className$, $(classData(cls)), "Ljava/lang/Class;"_s);
		$nc(this->mv)->visitInsn($Opcodes::SWAP);
		$nc(this->mv)->visitMethodInsn($Opcodes::INVOKEVIRTUAL, InvokerBytecodeGenerator::CLS, "cast"_s, InvokerBytecodeGenerator::LL_SIG, false);
		$load($ObjectArray);
		if ($getClass($ObjectArray)->isAssignableFrom(cls)) {
			$nc(this->mv)->visitTypeInsn($Opcodes::CHECKCAST, InvokerBytecodeGenerator::OBJARY);
		} else {
			$init($MethodHandleStatics);
			if ($MethodHandleStatics::PROFILE_LEVEL > 0) {
				$nc(this->mv)->visitTypeInsn($Opcodes::CHECKCAST, InvokerBytecodeGenerator::OBJ);
			}
		}
	}
	if (writeBack != nullptr) {
		$nc(this->mv)->visitInsn($Opcodes::DUP);
		emitAstoreInsn(writeBack->index());
	}
}

void InvokerBytecodeGenerator::emitReturnInsn($LambdaForm$BasicType* type) {
	$init($InvokerBytecodeGenerator$2);

	int32_t var$0 = 0;
	switch ($nc($InvokerBytecodeGenerator$2::$SwitchMap$java$lang$invoke$LambdaForm$BasicType)->get($nc((type))->ordinal())) {
	case 1:
		{
			var$0 = $Opcodes::IRETURN;
			break;
		}
	case 2:
		{
			var$0 = $Opcodes::LRETURN;
			break;
		}
	case 3:
		{
			var$0 = $Opcodes::FRETURN;
			break;
		}
	case 4:
		{
			var$0 = $Opcodes::DRETURN;
			break;
		}
	case 5:
		{
			var$0 = $Opcodes::ARETURN;
			break;
		}
	case 6:
		{
			var$0 = $Opcodes::RETURN;
			break;
		}
	default:
		{
			$throwNew($InternalError, $$str({"unknown return type: "_s, type}));
		}
	}
	int32_t opcode = var$0;
	$nc(this->mv)->visitInsn(opcode);
}

$String* InvokerBytecodeGenerator::getInternalName($Class* c) {
	$useLocalCurrentObjectStackCache();
	if (c == $Object::class$) {
		return InvokerBytecodeGenerator::OBJ;
	} else {
		$load($ObjectArray);
		if (c == $getClass($ObjectArray)) {
			return InvokerBytecodeGenerator::OBJARY;
		} else if (c == $Class::class$) {
			return InvokerBytecodeGenerator::CLS;
		} else {
			$load($MethodHandle);
			if (c == $MethodHandle::class$) {
				return InvokerBytecodeGenerator::MH;
			}
		}
	}
	if (!InvokerBytecodeGenerator::$assertionsDisabled && !($VerifyAccess::isTypeVisible(c, $Object::class$))) {
		$throwNew($AssertionError, $($of($nc(c)->getName())));
	}
	if (c == this->lastClass) {
		return this->lastInternalName;
	}
	$set(this, lastClass, c);
	return $set(this, lastInternalName, $nc($($nc(c)->getName()))->replace(u'.', u'/'));
}

$MemberName* InvokerBytecodeGenerator::resolveFrom($String* name, $MethodType* type, $Class* holder) {
	$init(InvokerBytecodeGenerator);
	$useLocalCurrentObjectStackCache();
	$var($MemberName, member, $new($MemberName, holder, name, type, (int8_t)6));
	$var($MemberName, resolvedMember, $nc($($MemberName::getFactory()))->resolveOrNull((int8_t)6, member, holder, -1));
	$MethodHandleStatics::traceLambdaForm(name, type, holder, resolvedMember);
	return resolvedMember;
}

$MemberName* InvokerBytecodeGenerator::lookupPregenerated($LambdaForm* form, $MethodType* invokerType) {
	$init(InvokerBytecodeGenerator);
	$useLocalCurrentObjectStackCache();
	if ($nc(form)->customized != nullptr) {
		return nullptr;
	}
	$var($String, name, $nc(form)->kind->methodName);
	$init($InvokerBytecodeGenerator$2);
	switch ($nc($InvokerBytecodeGenerator$2::$SwitchMap$java$lang$invoke$LambdaForm$Kind)->get((form->kind)->ordinal())) {
	case 1:
		{
			{
				$assign(name, $str({name, "_"_s, $cast($String, $($nc($($BoundMethodHandle::speciesDataFor(form)))->key()))}));
				$load($DelegatingMethodHandle$Holder);
				return resolveFrom(name, invokerType, $DelegatingMethodHandle$Holder::class$);
			}
		}
	case 2:
		{
			$load($DelegatingMethodHandle$Holder);
			return resolveFrom(name, invokerType, $DelegatingMethodHandle$Holder::class$);
		}
	case 3:
		{}
	case 4:
		{
			{
				$assign(name, $str({name, "_"_s, $$str($nc($(form->returnType()))->basicTypeChar())}));
				$load($LambdaForm$Holder);
				return resolveFrom(name, invokerType, $LambdaForm$Holder::class$);
			}
		}
	case 5:
		{}
	case 6:
		{}
	case 7:
		{}
	case 8:
		{}
	case 9:
		{}
	case 10:
		{
			$load($Invokers$Holder);
			return resolveFrom(name, invokerType, $Invokers$Holder::class$);
		}
	case 11:
		{}
	case 12:
		{}
	case 13:
		{}
	case 14:
		{}
	case 15:
		{}
	case 16:
		{}
	case 17:
		{}
	case 18:
		{}
	case 19:
		{}
	case 20:
		{}
	case 21:
		{}
	case 22:
		{}
	case 23:
		{}
	case 24:
		{}
	case 25:
		{}
	case 26:
		{}
	case 27:
		{}
	case 28:
		{}
	case 29:
		{}
	case 30:
		{}
	case 31:
		{}
	case 32:
		{}
	case 33:
		{}
	case 34:
		{}
	case 35:
		{
			$load($DirectMethodHandle$Holder);
			return resolveFrom(name, invokerType, $DirectMethodHandle$Holder::class$);
		}
	}
	return nullptr;
}

$MemberName* InvokerBytecodeGenerator::generateCustomizedCode($LambdaForm* form, $MethodType* invokerType) {
	$init(InvokerBytecodeGenerator);
	$useLocalCurrentObjectStackCache();
	$var($MemberName, pregenerated, lookupPregenerated(form, invokerType));
	if (pregenerated != nullptr) {
		return pregenerated;
	}
	$var(InvokerBytecodeGenerator, g, $new(InvokerBytecodeGenerator, "MH"_s, form, invokerType));
	return g->loadMethod($(g->generateCustomizedCodeBytes()));
}

bool InvokerBytecodeGenerator::checkActualReceiver() {
	$nc(this->mv)->visitInsn($Opcodes::DUP);
	$nc(this->mv)->visitVarInsn($Opcodes::ALOAD, $nc(this->localsMap)->get(0));
	$nc(this->mv)->visitMethodInsn($Opcodes::INVOKESTATIC, InvokerBytecodeGenerator::MHI, "assertSame"_s, InvokerBytecodeGenerator::LLV_SIG, false);
	return true;
}

$String* InvokerBytecodeGenerator::className($String* cn) {
	$init(InvokerBytecodeGenerator);
	if (!InvokerBytecodeGenerator::$assertionsDisabled && !checkClassName(cn)) {
		$throwNew($AssertionError, $of($$str({"Class not found: "_s, cn})));
	}
	return cn;
}

bool InvokerBytecodeGenerator::checkClassName($String* cn) {
	$init(InvokerBytecodeGenerator);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($Type, tp, $Type::getType(cn));
	if ($nc(tp)->getSort() != $Type::OBJECT) {
		return false;
	}
	try {
		$Class* c = $Class::forName($($nc(tp)->getClassName()), false, nullptr);
		return true;
	} catch ($ClassNotFoundException& e) {
		return false;
	}
	$shouldNotReachHere();
}

$bytes* InvokerBytecodeGenerator::generateCustomizedCodeBytes() {
	classFilePrologue();
	addMethod();
	clinit(this->cw, this->className$, this->classData$);
	bogusMethod(this->lambdaForm);
	$var($bytes, classFile, toByteArray());
	maybeDump(classFile);
	return classFile;
}

void InvokerBytecodeGenerator::setClassWriter($ClassWriter* cw) {
	$set(this, cw, cw);
}

void InvokerBytecodeGenerator::addMethod() {
	$useLocalCurrentObjectStackCache();
	methodPrologue();
	$nc(this->mv)->visitAnnotation(InvokerBytecodeGenerator::HIDDEN_SIG, true);
	$nc(this->mv)->visitAnnotation(InvokerBytecodeGenerator::LF_COMPILED_SIG, true);
	if ($nc(this->lambdaForm)->forceInline) {
		$nc(this->mv)->visitAnnotation(InvokerBytecodeGenerator::FORCEINLINE_SIG, true);
	} else {
		$nc(this->mv)->visitAnnotation(InvokerBytecodeGenerator::DONTINLINE_SIG, true);
	}
	classData(this->lambdaForm);
	if ($nc(this->lambdaForm)->customized != nullptr) {
		$nc(this->mv)->visitFieldInsn($Opcodes::GETSTATIC, this->className$, $(classData($nc(this->lambdaForm)->customized)), InvokerBytecodeGenerator::MH_SIG);
		$nc(this->mv)->visitTypeInsn($Opcodes::CHECKCAST, InvokerBytecodeGenerator::MH);
		if (!InvokerBytecodeGenerator::$assertionsDisabled && !(checkActualReceiver())) {
			$throwNew($AssertionError);
		}
		$nc(this->mv)->visitVarInsn($Opcodes::ASTORE, $nc(this->localsMap)->get(0));
	}
	$var($LambdaForm$Name, onStack, nullptr);
	for (int32_t i = $nc(this->lambdaForm)->arity$; i < $nc($nc(this->lambdaForm)->names)->length; ++i) {
		$var($LambdaForm$Name, name, $nc($nc(this->lambdaForm)->names)->get(i));
		emitStoreResult(onStack);
		$assign(onStack, name);
		$MethodHandleImpl$Intrinsic* intr = $nc($nc(name)->function)->intrinsicName();
		$init($InvokerBytecodeGenerator$2);
		{
			int32_t numCases = 0;
			switch ($nc($InvokerBytecodeGenerator$2::$SwitchMap$java$lang$invoke$MethodHandleImpl$Intrinsic)->get($nc((intr))->ordinal())) {
			case 1:
				{
					if (!InvokerBytecodeGenerator::$assertionsDisabled && !$nc(this->lambdaForm)->isSelectAlternative(i)) {
						$throwNew($AssertionError);
					}
					$init($MethodHandleStatics);
					if ($MethodHandleStatics::PROFILE_GWT) {
						$load($MethodHandleImpl);
						if (!InvokerBytecodeGenerator::$assertionsDisabled && !($instanceOf($LambdaForm$Name, $nc(name->arguments)->get(0)) && $nc(($cast($LambdaForm$Name, $nc(name->arguments)->get(0))))->refersTo($MethodHandleImpl::class$, "profileBoolean"_s))) {
							$throwNew($AssertionError);
						}
						$nc(this->mv)->visitAnnotation(InvokerBytecodeGenerator::INJECTEDPROFILE_SIG, true);
					}
					$assign(onStack, emitSelectAlternative(name, $nc($nc(this->lambdaForm)->names)->get(i + 1)));
					++i;
					continue;
				}
			case 2:
				{
					if (!InvokerBytecodeGenerator::$assertionsDisabled && !$nc(this->lambdaForm)->isGuardWithCatch(i)) {
						$throwNew($AssertionError);
					}
					$assign(onStack, emitGuardWithCatch(i));
					i += 2;
					continue;
				}
			case 3:
				{
					if (!InvokerBytecodeGenerator::$assertionsDisabled && !$nc(this->lambdaForm)->isTryFinally(i)) {
						$throwNew($AssertionError);
					}
					$assign(onStack, emitTryFinally(i));
					i += 2;
					continue;
				}
			case 4:
				{
					if (!InvokerBytecodeGenerator::$assertionsDisabled && !$nc(this->lambdaForm)->isTableSwitch(i)) {
						$throwNew($AssertionError);
					}
					numCases = $nc(($cast($Integer, $($nc(name->function)->intrinsicData()))))->intValue();
					$assign(onStack, emitTableSwitch(i, numCases));
					i += 2;
					continue;
				}
			case 5:
				{
					if (!InvokerBytecodeGenerator::$assertionsDisabled && !$nc(this->lambdaForm)->isLoop(i)) {
						$throwNew($AssertionError);
					}
					$assign(onStack, emitLoop(i));
					i += 2;
					continue;
				}
			case 6:
				{
					emitArrayLoad(name);
					continue;
				}
			case 7:
				{
					emitArrayStore(name);
					continue;
				}
			case 8:
				{
					emitArrayLength(name);
					continue;
				}
			case 9:
				{
					if (!InvokerBytecodeGenerator::$assertionsDisabled && !($nc(name->arguments)->length == 1)) {
						$throwNew($AssertionError);
					}
					emitPushArguments(name, 0);
					continue;
				}
			case 10:
				{
					if (!InvokerBytecodeGenerator::$assertionsDisabled && !($nc(name->arguments)->length == 0)) {
						$throwNew($AssertionError);
					}
					emitConst($($nc($(name->type$->basicTypeWrapper()))->zero()));
					continue;
				}
			case 11:
				{
					break;
				}
			default:
				{
					$throw($($MethodHandleStatics::newInternalError($$str({"Unknown intrinsic: "_s, intr}))));
				}
			}
		}
		$var($MemberName, member, $nc(name->function)->member());
		if (isStaticallyInvocable(member)) {
			emitStaticInvoke(member, name);
		} else {
			emitInvoke(name);
		}
	}
	emitReturn(onStack);
	methodEpilogue();
}

$bytes* InvokerBytecodeGenerator::toByteArray() {
	try {
		return $nc(this->cw)->toByteArray();
	} catch ($RuntimeException& e) {
		$throwNew($InvokerBytecodeGenerator$BytecodeGenerationException, e);
	}
	$shouldNotReachHere();
}

void InvokerBytecodeGenerator::emitArrayLoad($LambdaForm$Name* name) {
	emitArrayOp(name, $Opcodes::AALOAD);
}

void InvokerBytecodeGenerator::emitArrayStore($LambdaForm$Name* name) {
	emitArrayOp(name, $Opcodes::AASTORE);
}

void InvokerBytecodeGenerator::emitArrayLength($LambdaForm$Name* name) {
	emitArrayOp(name, $Opcodes::ARRAYLENGTH);
}

void InvokerBytecodeGenerator::emitArrayOp($LambdaForm$Name* name, int32_t arrayOpcode) {
	$useLocalCurrentObjectStackCache();
	if (!InvokerBytecodeGenerator::$assertionsDisabled && !(arrayOpcode == $Opcodes::AALOAD || arrayOpcode == $Opcodes::AASTORE || arrayOpcode == $Opcodes::ARRAYLENGTH)) {
		$throwNew($AssertionError);
	}
	$Class* elementType = $nc($($cast($Class, $nc($($nc($nc(name)->function)->methodType()))->parameterType(0))))->getComponentType();
	if (!InvokerBytecodeGenerator::$assertionsDisabled && !(elementType != nullptr)) {
		$throwNew($AssertionError);
	}
	emitPushArguments(name, 0);
	if (arrayOpcode != $Opcodes::ARRAYLENGTH && $nc(elementType)->isPrimitive()) {
		$Wrapper* w = $Wrapper::forPrimitiveType(elementType);
		arrayOpcode = arrayInsnOpcode(arrayTypeCode(w), arrayOpcode);
	}
	$nc(this->mv)->visitInsn(arrayOpcode);
}

void InvokerBytecodeGenerator::emitInvoke($LambdaForm$Name* name) {
	$useLocalCurrentObjectStackCache();
	if (!InvokerBytecodeGenerator::$assertionsDisabled && !(!$nc(name)->isLinkerMethodInvoke())) {
		$throwNew($AssertionError);
	}
	{
		$var($MethodHandle, target, $nc($nc(name)->function)->resolvedHandle());
		if (!InvokerBytecodeGenerator::$assertionsDisabled && !(target != nullptr)) {
			$throwNew($AssertionError, $($of(name->exprString())));
		}
		$nc(this->mv)->visitFieldInsn($Opcodes::GETSTATIC, this->className$, $(classData(target)), InvokerBytecodeGenerator::MH_SIG);
		$load($MethodHandle);
		emitReferenceCast($MethodHandle::class$, target);
	}
	emitPushArguments(name, 0);
	$var($MethodType, type, $nc($nc(name)->function)->methodType());
	$nc(this->mv)->visitMethodInsn($Opcodes::INVOKEVIRTUAL, InvokerBytecodeGenerator::MH, "invokeBasic"_s, $($nc($($nc(type)->basicType()))->toMethodDescriptorString()), false);
}

bool InvokerBytecodeGenerator::isStaticallyInvocable($LambdaForm$NamedFunctionArray* functions) {
	$init(InvokerBytecodeGenerator);
	$useLocalCurrentObjectStackCache();
	{
		$var($LambdaForm$NamedFunctionArray, arr$, functions);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($LambdaForm$NamedFunction, nf, arr$->get(i$));
			{
				if (!isStaticallyInvocable($($nc(nf)->member()))) {
					return false;
				}
			}
		}
	}
	return true;
}

bool InvokerBytecodeGenerator::isStaticallyInvocable($LambdaForm$Name* name) {
	$init(InvokerBytecodeGenerator);
	return isStaticallyInvocable($($nc($nc(name)->function)->member()));
}

bool InvokerBytecodeGenerator::isStaticallyInvocable($MemberName* member) {
	$init(InvokerBytecodeGenerator);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (member == nullptr) {
		return false;
	}
	if ($nc(member)->isConstructor()) {
		return false;
	}
	$Class* cls = $nc(member)->getDeclaringClass();
	$load($MethodHandle);
	bool var$0 = $MethodHandle::class$->isAssignableFrom(cls);
	if (var$0 && !member->isPrivate()) {
		if (!InvokerBytecodeGenerator::$assertionsDisabled && !(isStaticallyInvocableType($(member->getMethodOrFieldType())))) {
			$throwNew($AssertionError);
		}
		return true;
	}
	bool var$1 = $nc(cls)->isArray();
	if (var$1 || $nc(cls)->isPrimitive()) {
		return false;
	}
	bool var$2 = $nc(cls)->isAnonymousClass();
	if (var$2 || $nc(cls)->isLocalClass()) {
		return false;
	}
	if ($nc(cls)->getClassLoader() != $MethodHandle::class$->getClassLoader()) {
		return false;
	}
	if ($nc(cls)->isHidden()) {
		return false;
	}
	if (!isStaticallyInvocableType($(member->getMethodOrFieldType()))) {
		return false;
	}
	bool var$3 = !member->isPrivate();
	if (var$3 && $VerifyAccess::isSamePackage($MethodHandle::class$, cls)) {
		return true;
	}
	bool var$4 = member->isPublic();
	if (var$4 && isStaticallyNameable(cls)) {
		return true;
	}
	return false;
}

bool InvokerBytecodeGenerator::isStaticallyInvocableType($MethodType* mtype) {
	$init(InvokerBytecodeGenerator);
	$useLocalCurrentObjectStackCache();
	if (!isStaticallyNameable($($cast($Class, $nc(mtype)->returnType())))) {
		return false;
	}
	{
		$var($ClassArray, arr$, $fcast($ClassArray, $nc(mtype)->parameterArray()));
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$Class* ptype = arr$->get(i$);
			if (!isStaticallyNameable(ptype)) {
				return false;
			}
		}
	}
	return true;
}

bool InvokerBytecodeGenerator::isStaticallyNameable($Class* cls) {
	$init(InvokerBytecodeGenerator);
	$beforeCallerSensitive();
	if (cls == $Object::class$) {
		return true;
	}
	$load($MethodHandle);
	if ($MethodHandle::class$->isAssignableFrom(cls)) {
		if (!InvokerBytecodeGenerator::$assertionsDisabled && !(!$nc(cls)->isHidden())) {
			$throwNew($AssertionError);
		}
		return true;
	}
	while ($nc(cls)->isArray()) {
		cls = cls->getComponentType();
	}
	if ($nc(cls)->isPrimitive()) {
		return true;
	}
	if ($nc(cls)->isHidden()) {
		return false;
	}
	if ($nc(cls)->getClassLoader() != $Object::class$->getClassLoader()) {
		return false;
	}
	if ($VerifyAccess::isSamePackage($MethodHandle::class$, cls)) {
		return true;
	}
	if (!$Modifier::isPublic($nc(cls)->getModifiers())) {
		return false;
	}
	{
		$var($ClassArray, arr$, InvokerBytecodeGenerator::STATICALLY_INVOCABLE_PACKAGES);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$Class* pkgcls = arr$->get(i$);
			{
				if ($VerifyAccess::isSamePackage(pkgcls, cls)) {
					return true;
				}
			}
		}
	}
	return false;
}

void InvokerBytecodeGenerator::emitStaticInvoke($LambdaForm$Name* name) {
	emitStaticInvoke($($nc($nc(name)->function)->member()), name);
}

void InvokerBytecodeGenerator::emitStaticInvoke($MemberName* member, $LambdaForm$Name* name) {
	$useLocalCurrentObjectStackCache();
	if (!InvokerBytecodeGenerator::$assertionsDisabled && !($nc(member)->equals($($nc($nc(name)->function)->member())))) {
		$throwNew($AssertionError);
	}
	$Class* defc = $nc(member)->getDeclaringClass();
	$var($String, cname, getInternalName(defc));
	$var($String, mname, member->getName());
	$var($String, mtype, nullptr);
	int8_t refKind = member->getReferenceKind();
	if (refKind == (int8_t)7) {
		if (!InvokerBytecodeGenerator::$assertionsDisabled && !(member->canBeStaticallyBound())) {
			$throwNew($AssertionError, $of(member));
		}
		refKind = (int8_t)5;
	}
	if (!InvokerBytecodeGenerator::$assertionsDisabled && !(!($nc(member->getDeclaringClass())->isInterface() && refKind == (int8_t)5))) {
		$throwNew($AssertionError);
	}
	emitPushArguments(name, 0);
	if (member->isMethod()) {
		$assign(mtype, $nc($(member->getMethodType()))->toMethodDescriptorString());
		int32_t var$0 = refKindOpcode(refKind);
		$var($String, var$1, cname);
		$var($String, var$2, mname);
		$var($String, var$3, mtype);
		$nc(this->mv)->visitMethodInsn(var$0, var$1, var$2, var$3, $nc(member->getDeclaringClass())->isInterface());
	} else {
		$assign(mtype, $MethodType::toFieldDescriptorString(member->getFieldType()));
		$nc(this->mv)->visitFieldInsn(refKindOpcode(refKind), cname, mname, mtype);
	}
	$init($LambdaForm$BasicType);
	if ($nc(name)->type$ == $LambdaForm$BasicType::L_TYPE) {
		$Class* rtype = $cast($Class, $nc($(member->getInvocationType()))->returnType());
		if (!InvokerBytecodeGenerator::$assertionsDisabled && !(!$nc(rtype)->isPrimitive())) {
			$throwNew($AssertionError);
		}
		if (rtype != $Object::class$ && !$nc(rtype)->isInterface()) {
			assertStaticType(rtype, name);
		}
	}
}

int32_t InvokerBytecodeGenerator::refKindOpcode(int8_t refKind) {
	$useLocalCurrentObjectStackCache();
	switch (refKind) {
	case 5:
		{
			return $Opcodes::INVOKEVIRTUAL;
		}
	case 6:
		{
			return $Opcodes::INVOKESTATIC;
		}
	case 7:
		{
			return $Opcodes::INVOKESPECIAL;
		}
	case 9:
		{
			return $Opcodes::INVOKEINTERFACE;
		}
	case 1:
		{
			return $Opcodes::GETFIELD;
		}
	case 3:
		{
			return $Opcodes::PUTFIELD;
		}
	case 2:
		{
			return $Opcodes::GETSTATIC;
		}
	case 4:
		{
			return $Opcodes::PUTSTATIC;
		}
	}
	$throwNew($InternalError, $$str({"refKind="_s, $$str(refKind)}));
}

$LambdaForm$Name* InvokerBytecodeGenerator::emitSelectAlternative($LambdaForm$Name* selectAlternativeName, $LambdaForm$Name* invokeBasicName) {
	$useLocalCurrentObjectStackCache();
	if (!InvokerBytecodeGenerator::$assertionsDisabled && !isStaticallyInvocable(invokeBasicName)) {
		$throwNew($AssertionError);
	}
	$var($LambdaForm$Name, receiver, $cast($LambdaForm$Name, $nc($nc(invokeBasicName)->arguments)->get(0)));
	$var($Label, L_fallback, $new($Label));
	$var($Label, L_done, $new($Label));
	emitPushArgument(selectAlternativeName, 0);
	$nc(this->mv)->visitJumpInsn($Opcodes::IFEQ, L_fallback);
	$var($ClassArray, preForkClasses, $cast($ClassArray, $nc(this->localClasses)->clone()));
	emitPushArgument(selectAlternativeName, 1);
	emitAstoreInsn($nc(receiver)->index());
	emitStaticInvoke(invokeBasicName);
	$nc(this->mv)->visitJumpInsn($Opcodes::GOTO, L_done);
	$nc(this->mv)->visitLabel(L_fallback);
	$System::arraycopy(preForkClasses, 0, this->localClasses, 0, preForkClasses->length);
	emitPushArgument(selectAlternativeName, 2);
	emitAstoreInsn($nc(receiver)->index());
	emitStaticInvoke(invokeBasicName);
	$nc(this->mv)->visitLabel(L_done);
	$System::arraycopy(preForkClasses, 0, this->localClasses, 0, preForkClasses->length);
	return invokeBasicName;
}

$LambdaForm$Name* InvokerBytecodeGenerator::emitGuardWithCatch(int32_t pos) {
	$useLocalCurrentObjectStackCache();
	$var($LambdaForm$Name, args, $nc($nc(this->lambdaForm)->names)->get(pos));
	$var($LambdaForm$Name, invoker, $nc($nc(this->lambdaForm)->names)->get(pos + 1));
	$var($LambdaForm$Name, result, $nc($nc(this->lambdaForm)->names)->get(pos + 2));
	$var($Label, L_startBlock, $new($Label));
	$var($Label, L_endBlock, $new($Label));
	$var($Label, L_handler, $new($Label));
	$var($Label, L_done, $new($Label));
	$Class* returnType = $cast($Class, $nc($($nc($($nc($nc(result)->function)->resolvedHandle()))->type()))->returnType());
	$var($MethodType, type, $nc($($cast($MethodType, $nc($($nc($($nc($nc(args)->function)->resolvedHandle()))->type()))->dropParameterTypes(0, 1))))->changeReturnType(returnType));
	$nc(this->mv)->visitTryCatchBlock(L_startBlock, L_endBlock, L_handler, "java/lang/Throwable"_s);
	$nc(this->mv)->visitLabel(L_startBlock);
	emitPushArgument(invoker, 0);
	emitPushArguments(args, 1);
	$nc(this->mv)->visitMethodInsn($Opcodes::INVOKEVIRTUAL, InvokerBytecodeGenerator::MH, "invokeBasic"_s, $($nc($($nc(type)->basicType()))->toMethodDescriptorString()), false);
	$nc(this->mv)->visitLabel(L_endBlock);
	$nc(this->mv)->visitJumpInsn($Opcodes::GOTO, L_done);
	$nc(this->mv)->visitLabel(L_handler);
	$nc(this->mv)->visitInsn($Opcodes::DUP);
	emitPushArgument(invoker, 1);
	$nc(this->mv)->visitInsn($Opcodes::SWAP);
	$nc(this->mv)->visitMethodInsn($Opcodes::INVOKEVIRTUAL, "java/lang/Class"_s, "isInstance"_s, "(Ljava/lang/Object;)Z"_s, false);
	$var($Label, L_rethrow, $new($Label));
	$nc(this->mv)->visitJumpInsn($Opcodes::IFEQ, L_rethrow);
	emitPushArgument(invoker, 2);
	$nc(this->mv)->visitInsn($Opcodes::SWAP);
	emitPushArguments(args, 1);
	$var($MethodType, catcherType, $nc(type)->insertParameterTypes(0, $$new($ClassArray, {$Throwable::class$})));
	$nc(this->mv)->visitMethodInsn($Opcodes::INVOKEVIRTUAL, InvokerBytecodeGenerator::MH, "invokeBasic"_s, $($nc($($nc(catcherType)->basicType()))->toMethodDescriptorString()), false);
	$nc(this->mv)->visitJumpInsn($Opcodes::GOTO, L_done);
	$nc(this->mv)->visitLabel(L_rethrow);
	$nc(this->mv)->visitInsn($Opcodes::ATHROW);
	$nc(this->mv)->visitLabel(L_done);
	return result;
}

$LambdaForm$Name* InvokerBytecodeGenerator::emitTryFinally(int32_t pos) {
	$useLocalCurrentObjectStackCache();
	$var($LambdaForm$Name, args, $nc($nc(this->lambdaForm)->names)->get(pos));
	$var($LambdaForm$Name, invoker, $nc($nc(this->lambdaForm)->names)->get(pos + 1));
	$var($LambdaForm$Name, result, $nc($nc(this->lambdaForm)->names)->get(pos + 2));
	$var($Label, lFrom, $new($Label));
	$var($Label, lTo, $new($Label));
	$var($Label, lCatch, $new($Label));
	$var($Label, lDone, $new($Label));
	$Class* returnType = $cast($Class, $nc($($nc($($nc($nc(result)->function)->resolvedHandle()))->type()))->returnType());
	$LambdaForm$BasicType* basicReturnType = $LambdaForm$BasicType::basicType(returnType);
	$init($Void);
	bool isNonVoid = returnType != $Void::TYPE;
	$var($MethodType, type, $nc($($cast($MethodType, $nc($($nc($($nc($nc(args)->function)->resolvedHandle()))->type()))->dropParameterTypes(0, 1))))->changeReturnType(returnType));
	$var($MethodType, cleanupType, $nc(type)->insertParameterTypes(0, $$new($ClassArray, {$Throwable::class$})));
	if (isNonVoid) {
		$assign(cleanupType, $nc(cleanupType)->insertParameterTypes(1, $$new($ClassArray, {returnType})));
	}
	$var($String, cleanupDesc, $nc($($nc(cleanupType)->basicType()))->toMethodDescriptorString());
	$nc(this->mv)->visitTryCatchBlock(lFrom, lTo, lCatch, "java/lang/Throwable"_s);
	$nc(this->mv)->visitLabel(lFrom);
	emitPushArgument(invoker, 0);
	emitPushArguments(args, 1);
	$nc(this->mv)->visitMethodInsn($Opcodes::INVOKEVIRTUAL, InvokerBytecodeGenerator::MH, "invokeBasic"_s, $($nc($(type->basicType()))->toMethodDescriptorString()), false);
	$nc(this->mv)->visitLabel(lTo);
	int32_t index = extendLocalsMap($$new($ClassArray, {returnType}));
	if (isNonVoid) {
		emitStoreInsn(basicReturnType, index);
	}
	emitPushArgument(invoker, 1);
	$nc(this->mv)->visitInsn($Opcodes::ACONST_NULL);
	if (isNonVoid) {
		emitLoadInsn(basicReturnType, index);
	}
	emitPushArguments(args, 1);
	$nc(this->mv)->visitMethodInsn($Opcodes::INVOKEVIRTUAL, InvokerBytecodeGenerator::MH, "invokeBasic"_s, cleanupDesc, false);
	$nc(this->mv)->visitJumpInsn($Opcodes::GOTO, lDone);
	$nc(this->mv)->visitLabel(lCatch);
	$nc(this->mv)->visitInsn($Opcodes::DUP);
	emitPushArgument(invoker, 1);
	$nc(this->mv)->visitInsn($Opcodes::SWAP);
	if (isNonVoid) {
		emitZero($($LambdaForm$BasicType::basicType(returnType)));
	}
	emitPushArguments(args, 1);
	$nc(this->mv)->visitMethodInsn($Opcodes::INVOKEVIRTUAL, InvokerBytecodeGenerator::MH, "invokeBasic"_s, cleanupDesc, false);
	if (isNonVoid) {
		emitPopInsn(basicReturnType);
	}
	$nc(this->mv)->visitInsn($Opcodes::ATHROW);
	$nc(this->mv)->visitLabel(lDone);
	return result;
}

void InvokerBytecodeGenerator::emitPopInsn($LambdaForm$BasicType* type) {
	$nc(this->mv)->visitInsn(popInsnOpcode(type));
}

int32_t InvokerBytecodeGenerator::popInsnOpcode($LambdaForm$BasicType* type) {
	$init(InvokerBytecodeGenerator);
	$init($InvokerBytecodeGenerator$2);

	int32_t var$0 = 0;
	switch ($nc($InvokerBytecodeGenerator$2::$SwitchMap$java$lang$invoke$LambdaForm$BasicType)->get($nc((type))->ordinal())) {
	case 1:
		{}
	case 3:
		{}
	case 5:
		{
			var$0 = $Opcodes::POP;
			break;
		}
	case 2:
		{}
	case 4:
		{
			var$0 = $Opcodes::POP2;
			break;
		}
	default:
		{
			$throwNew($InternalError, $$str({"unknown type: "_s, type}));
		}
	}
	return var$0;
}

$LambdaForm$Name* InvokerBytecodeGenerator::emitTableSwitch(int32_t pos, int32_t numCases) {
	$useLocalCurrentObjectStackCache();
	$var($LambdaForm$Name, args, $nc($nc(this->lambdaForm)->names)->get(pos));
	$var($LambdaForm$Name, invoker, $nc($nc(this->lambdaForm)->names)->get(pos + 1));
	$var($LambdaForm$Name, result, $nc($nc(this->lambdaForm)->names)->get(pos + 2));
	$Class* returnType = $cast($Class, $nc($($nc($($nc($nc(result)->function)->resolvedHandle()))->type()))->returnType());
	$var($MethodType, caseType, $nc($($cast($MethodType, $nc($($nc($($nc($nc(args)->function)->resolvedHandle()))->type()))->dropParameterTypes(0, 1))))->changeReturnType(returnType));
	$var($String, caseDescriptor, $nc($($nc(caseType)->basicType()))->toMethodDescriptorString());
	emitPushArgument(invoker, 2);
	$nc(this->mv)->visitFieldInsn($Opcodes::GETFIELD, "java/lang/invoke/MethodHandleImpl$CasesHolder"_s, "cases"_s, "[Ljava/lang/invoke/MethodHandle;"_s);
	$load($MethodHandleArray);
	int32_t casesLocal = extendLocalsMap($$new($ClassArray, {$getClass($MethodHandleArray)}));
	$init($LambdaForm$BasicType);
	emitStoreInsn($LambdaForm$BasicType::L_TYPE, casesLocal);
	$var($Label, endLabel, $new($Label));
	$var($Label, defaultLabel, $new($Label));
	$var($LabelArray, caseLabels, $new($LabelArray, numCases));
	for (int32_t i = 0; i < caseLabels->length; ++i) {
		caseLabels->set(i, $$new($Label));
	}
	emitPushArgument(invoker, 0);
	$nc(this->mv)->visitTableSwitchInsn(0, numCases - 1, defaultLabel, caseLabels);
	$nc(this->mv)->visitLabel(defaultLabel);
	emitPushArgument(invoker, 1);
	emitPushArguments(args, 1);
	$nc(this->mv)->visitMethodInsn($Opcodes::INVOKEVIRTUAL, InvokerBytecodeGenerator::MH, "invokeBasic"_s, caseDescriptor, false);
	$nc(this->mv)->visitJumpInsn($Opcodes::GOTO, endLabel);
	for (int32_t i = 0; i < numCases; ++i) {
		$nc(this->mv)->visitLabel(caseLabels->get(i));
		emitLoadInsn($LambdaForm$BasicType::L_TYPE, casesLocal);
		emitIconstInsn(i);
		$nc(this->mv)->visitInsn($Opcodes::AALOAD);
		emitPushArguments(args, 1);
		$nc(this->mv)->visitMethodInsn($Opcodes::INVOKEVIRTUAL, InvokerBytecodeGenerator::MH, "invokeBasic"_s, caseDescriptor, false);
		$nc(this->mv)->visitJumpInsn($Opcodes::GOTO, endLabel);
	}
	$nc(this->mv)->visitLabel(endLabel);
	return result;
}

$LambdaForm$Name* InvokerBytecodeGenerator::emitLoop(int32_t pos) {
	$useLocalCurrentObjectStackCache();
	$var($LambdaForm$Name, args, $nc($nc(this->lambdaForm)->names)->get(pos));
	$var($LambdaForm$Name, invoker, $nc($nc(this->lambdaForm)->names)->get(pos + 1));
	$var($LambdaForm$Name, result, $nc($nc(this->lambdaForm)->names)->get(pos + 2));
	$var($LambdaForm$BasicTypeArray, loopClauseTypes, $cast($LambdaForm$BasicTypeArray, $nc($nc(invoker)->arguments)->get(0)));
	$var($ClassArray, loopLocalStateTypes, $fcast($ClassArray, $nc($($nc($($nc($($Stream::of(loopClauseTypes)))->filter(static_cast<$Predicate*>($$new(InvokerBytecodeGenerator$$Lambda$lambda$emitLoop$0)))))->map(static_cast<$Function*>($$new(InvokerBytecodeGenerator$$Lambda$basicTypeClass$1)))))->toArray(static_cast<$IntFunction*>($$new(InvokerBytecodeGenerator$$Lambda$lambda$emitLoop$1$2)))));
	$var($ClassArray, localTypes, $new($ClassArray, $nc(loopLocalStateTypes)->length + 1));
	$load($MethodHandleImpl$LoopClauses);
	localTypes->set(0, $MethodHandleImpl$LoopClauses::class$);
	$System::arraycopy(loopLocalStateTypes, 0, localTypes, 1, loopLocalStateTypes->length);
	int32_t clauseDataIndex = extendLocalsMap(localTypes);
	int32_t firstLoopStateIndex = clauseDataIndex + 1;
	$Class* returnType = $cast($Class, $nc($($nc($($nc($nc(result)->function)->resolvedHandle()))->type()))->returnType());
	$var($MethodType, loopType, $nc($($cast($MethodType, $nc($($nc($($nc($nc(args)->function)->resolvedHandle()))->type()))->dropParameterTypes(0, 1))))->changeReturnType(returnType));
	$var($MethodType, loopHandleType, $nc(loopType)->insertParameterTypes(0, loopLocalStateTypes));
	$init($Boolean);
	$var($MethodType, predType, $nc(loopHandleType)->changeReturnType($Boolean::TYPE));
	$var($MethodType, finiType, loopHandleType);
	int32_t nClauses = $nc(loopClauseTypes)->length;
	int32_t inits = 1;
	int32_t steps = 2;
	int32_t preds = 3;
	int32_t finis = 4;
	$var($Label, lLoop, $new($Label));
	$var($Label, lDone, $new($Label));
	$var($Label, lNext, nullptr);
	emitPushArgument($MethodHandleImpl$LoopClauses::class$, $nc(invoker->arguments)->get(1));
	$nc(this->mv)->visitFieldInsn($Opcodes::GETFIELD, InvokerBytecodeGenerator::LOOP_CLAUSES, "clauses"_s, InvokerBytecodeGenerator::MHARY2);
	emitAstoreInsn(clauseDataIndex);
	{
		int32_t c = 0;
		int32_t state = 0;
		for (; c < nClauses; ++c) {
			$var($MethodType, cInitType, loopType->changeReturnType($nc(loopClauseTypes->get(c))->basicTypeClass()));
			emitLoopHandleInvoke(invoker, inits, c, args, false, cInitType, loopLocalStateTypes, clauseDataIndex, firstLoopStateIndex);
			$init($Void);
			if ($cast($Class, $nc(cInitType)->returnType()) != $Void::TYPE) {
				emitStoreInsn($($LambdaForm$BasicType::basicType($($cast($Class, cInitType->returnType())))), firstLoopStateIndex + state);
				++state;
			}
		}
	}
	$nc(this->mv)->visitLabel(lLoop);
	{
		int32_t c = 0;
		int32_t state = 0;
		for (; c < nClauses; ++c) {
			$assign(lNext, $new($Label));
			$var($MethodType, stepType, loopHandleType->changeReturnType($nc(loopClauseTypes->get(c))->basicTypeClass()));
			$init($Void);
			bool isVoid = $cast($Class, $nc(stepType)->returnType()) == $Void::TYPE;
			emitLoopHandleInvoke(invoker, steps, c, args, true, stepType, loopLocalStateTypes, clauseDataIndex, firstLoopStateIndex);
			if (!isVoid) {
				emitStoreInsn($($LambdaForm$BasicType::basicType($($cast($Class, stepType->returnType())))), firstLoopStateIndex + state);
				++state;
			}
			emitLoopHandleInvoke(invoker, preds, c, args, true, predType, loopLocalStateTypes, clauseDataIndex, firstLoopStateIndex);
			$nc(this->mv)->visitJumpInsn($Opcodes::IFNE, lNext);
			emitLoopHandleInvoke(invoker, finis, c, args, true, finiType, loopLocalStateTypes, clauseDataIndex, firstLoopStateIndex);
			$nc(this->mv)->visitJumpInsn($Opcodes::GOTO, lDone);
			$nc(this->mv)->visitLabel(lNext);
		}
	}
	$nc(this->mv)->visitJumpInsn($Opcodes::GOTO, lLoop);
	$nc(this->mv)->visitLabel(lDone);
	return result;
}

int32_t InvokerBytecodeGenerator::extendLocalsMap($ClassArray* types) {
	$useLocalCurrentObjectStackCache();
	int32_t firstSlot = $nc(this->localsMap)->length - 1;
	$set(this, localsMap, $Arrays::copyOf(this->localsMap, $nc(this->localsMap)->length + $nc(types)->length));
	$set(this, localClasses, $fcast($ClassArray, $Arrays::copyOf(this->localClasses, $nc(this->localClasses)->length + $nc(types)->length)));
	$System::arraycopy(types, 0, this->localClasses, firstSlot, $nc(types)->length);
	int32_t index = $nc(this->localsMap)->get(firstSlot - 1) + 1;
	int32_t lastSlots = 0;
	for (int32_t i = 0; i < $nc(types)->length; ++i) {
		$nc(this->localsMap)->set(firstSlot + i, index);
		lastSlots = $nc($($LambdaForm$BasicType::basicType($nc(this->localClasses)->get(firstSlot + i))))->basicTypeSlots();
		index += lastSlots;
	}
	$nc(this->localsMap)->set($nc(this->localsMap)->length - 1, index - lastSlots);
	return firstSlot;
}

void InvokerBytecodeGenerator::emitLoopHandleInvoke($LambdaForm$Name* holder, int32_t handles, int32_t clause, $LambdaForm$Name* args, bool pushLocalState, $MethodType* type, $ClassArray* loopLocalStateTypes, int32_t clauseDataSlot, int32_t firstLoopStateSlot) {
	$useLocalCurrentObjectStackCache();
	emitPushClauseArray(clauseDataSlot, handles);
	emitIconstInsn(clause);
	$nc(this->mv)->visitInsn($Opcodes::AALOAD);
	if (pushLocalState) {
		for (int32_t s = 0; s < $nc(loopLocalStateTypes)->length; ++s) {
			emitLoadInsn($($LambdaForm$BasicType::basicType(loopLocalStateTypes->get(s))), firstLoopStateSlot + s);
		}
	}
	emitPushArguments(args, 1);
	$nc(this->mv)->visitMethodInsn($Opcodes::INVOKEVIRTUAL, InvokerBytecodeGenerator::MH, "invokeBasic"_s, $($nc(type)->toMethodDescriptorString()), false);
}

void InvokerBytecodeGenerator::emitPushClauseArray(int32_t clauseDataSlot, int32_t which) {
	emitAloadInsn(clauseDataSlot);
	emitIconstInsn(which - 1);
	$nc(this->mv)->visitInsn($Opcodes::AALOAD);
}

void InvokerBytecodeGenerator::emitZero($LambdaForm$BasicType* type) {
	$init($InvokerBytecodeGenerator$2);

	int32_t var$0 = 0;
	switch ($nc($InvokerBytecodeGenerator$2::$SwitchMap$java$lang$invoke$LambdaForm$BasicType)->get($nc((type))->ordinal())) {
	case 1:
		{
			var$0 = $Opcodes::ICONST_0;
			break;
		}
	case 2:
		{
			var$0 = $Opcodes::LCONST_0;
			break;
		}
	case 3:
		{
			var$0 = $Opcodes::FCONST_0;
			break;
		}
	case 4:
		{
			var$0 = $Opcodes::DCONST_0;
			break;
		}
	case 5:
		{
			var$0 = $Opcodes::ACONST_NULL;
			break;
		}
	default:
		{
			$throwNew($InternalError, $$str({"unknown type: "_s, type}));
		}
	}
	$nc(this->mv)->visitInsn(var$0);
}

void InvokerBytecodeGenerator::emitPushArguments($LambdaForm$Name* args, int32_t start) {
	$useLocalCurrentObjectStackCache();
	$var($MethodType, type, $nc($nc(args)->function)->methodType());
	for (int32_t i = start; i < $nc(args->arguments)->length; ++i) {
		emitPushArgument($($cast($Class, $nc(type)->parameterType(i))), $nc(args->arguments)->get(i));
	}
}

void InvokerBytecodeGenerator::emitPushArgument($LambdaForm$Name* name, int32_t paramIndex) {
	$useLocalCurrentObjectStackCache();
	$var($Object0, arg, $nc($nc(name)->arguments)->get(paramIndex));
	$Class* ptype = $cast($Class, $nc($($nc(name->function)->methodType()))->parameterType(paramIndex));
	emitPushArgument(ptype, arg);
}

void InvokerBytecodeGenerator::emitPushArgument($Class* ptype, Object$* arg) {
	$useLocalCurrentObjectStackCache();
	$LambdaForm$BasicType* bptype = $LambdaForm$BasicType::basicType(ptype);
	{
		$var($LambdaForm$Name, n, nullptr);
		bool var$0 = $instanceOf($LambdaForm$Name, arg);
		if (var$0) {
			$assign(n, $cast($LambdaForm$Name, arg));
			var$0 = true;
		}
		if (var$0) {
			emitLoadInsn($nc(n)->type$, n->index());
			emitImplicitConversion($nc(n)->type$, ptype, n);
		} else {
			if (arg == nullptr && bptype == $LambdaForm$BasicType::L_TYPE) {
				$nc(this->mv)->visitInsn($Opcodes::ACONST_NULL);
			} else {
				if ($instanceOf($String, arg) && bptype == $LambdaForm$BasicType::L_TYPE) {
					$nc(this->mv)->visitLdcInsn(arg);
				} else {
					if ($Wrapper::isWrapperType($nc($of(arg))->getClass()) && bptype != $LambdaForm$BasicType::L_TYPE) {
						emitConst(arg);
					} else {
						$nc(this->mv)->visitFieldInsn($Opcodes::GETSTATIC, this->className$, $(classData(arg)), "Ljava/lang/Object;"_s);
						emitImplicitConversion($LambdaForm$BasicType::L_TYPE, ptype, arg);
					}
				}
			}
		}
	}
}

void InvokerBytecodeGenerator::emitStoreResult($LambdaForm$Name* name) {
	$init($LambdaForm$BasicType);
	if (name != nullptr && name->type$ != $LambdaForm$BasicType::V_TYPE) {
		emitStoreInsn(name->type$, name->index());
	}
}

void InvokerBytecodeGenerator::emitReturn($LambdaForm$Name* onStack) {
	$Class* rclass = $cast($Class, $nc(this->invokerType)->returnType());
	$LambdaForm$BasicType* rtype = $nc(this->lambdaForm)->returnType();
	if (!InvokerBytecodeGenerator::$assertionsDisabled && !(rtype == $LambdaForm$BasicType::basicType(rclass))) {
		$throwNew($AssertionError);
	}
	if (rtype == $LambdaForm$BasicType::V_TYPE) {
		$nc(this->mv)->visitInsn($Opcodes::RETURN);
	} else {
		$var($LambdaForm$Name, rn, $nc($nc(this->lambdaForm)->names)->get($nc(this->lambdaForm)->result));
		if (rn != onStack) {
			emitLoadInsn(rtype, $nc(this->lambdaForm)->result);
		}
		emitImplicitConversion(rtype, rclass, rn);
		emitReturnInsn(rtype);
	}
}

void InvokerBytecodeGenerator::emitPrimCast($Wrapper* from, $Wrapper* to) {
	if (from == to) {
		return;
	}
	if ($nc(from)->isSubwordOrInt()) {
		emitI2X(to);
	} else if ($nc(to)->isSubwordOrInt()) {
		emitX2I(from);
		if (to->bitWidth() < 32) {
			emitI2X(to);
		}
	} else {
		bool error = false;
		$init($InvokerBytecodeGenerator$2);
		switch ($nc($InvokerBytecodeGenerator$2::$SwitchMap$sun$invoke$util$Wrapper)->get((from)->ordinal())) {
		case 6:
			{
				{
					switch ($nc($InvokerBytecodeGenerator$2::$SwitchMap$sun$invoke$util$Wrapper)->get((to)->ordinal())) {
					case 7:
						{
							$nc(this->mv)->visitInsn($Opcodes::L2F);
							break;
						}
					case 8:
						{
							$nc(this->mv)->visitInsn($Opcodes::L2D);
							break;
						}
					default:
						{
							error = true;
							break;
						}
					}
				}
				break;
			}
		case 7:
			{
				{
					switch ($nc($InvokerBytecodeGenerator$2::$SwitchMap$sun$invoke$util$Wrapper)->get((to)->ordinal())) {
					case 6:
						{
							$nc(this->mv)->visitInsn($Opcodes::F2L);
							break;
						}
					case 8:
						{
							$nc(this->mv)->visitInsn($Opcodes::F2D);
							break;
						}
					default:
						{
							error = true;
							break;
						}
					}
				}
				break;
			}
		case 8:
			{
				{
					switch ($nc($InvokerBytecodeGenerator$2::$SwitchMap$sun$invoke$util$Wrapper)->get((to)->ordinal())) {
					case 6:
						{
							$nc(this->mv)->visitInsn($Opcodes::D2L);
							break;
						}
					case 7:
						{
							$nc(this->mv)->visitInsn($Opcodes::D2F);
							break;
						}
					default:
						{
							error = true;
							break;
						}
					}
				}
				break;
			}
		default:
			{
				error = true;
				break;
			}
		}
		if (error) {
			$throwNew($IllegalStateException, $$str({"unhandled prim cast: "_s, from, "2"_s, to}));
		}
	}
}

void InvokerBytecodeGenerator::emitI2X($Wrapper* type) {
	$init($InvokerBytecodeGenerator$2);
	switch ($nc($InvokerBytecodeGenerator$2::$SwitchMap$sun$invoke$util$Wrapper)->get($nc((type))->ordinal())) {
	case 2:
		{
			$nc(this->mv)->visitInsn($Opcodes::I2B);
			break;
		}
	case 4:
		{
			$nc(this->mv)->visitInsn($Opcodes::I2S);
			break;
		}
	case 3:
		{
			$nc(this->mv)->visitInsn($Opcodes::I2C);
			break;
		}
	case 5:
		{
			break;
		}
	case 6:
		{
			$nc(this->mv)->visitInsn($Opcodes::I2L);
			break;
		}
	case 7:
		{
			$nc(this->mv)->visitInsn($Opcodes::I2F);
			break;
		}
	case 8:
		{
			$nc(this->mv)->visitInsn($Opcodes::I2D);
			break;
		}
	case 1:
		{
			$nc(this->mv)->visitInsn($Opcodes::ICONST_1);
			$nc(this->mv)->visitInsn($Opcodes::IAND);
			break;
		}
	default:
		{
			$throwNew($InternalError, $$str({"unknown type: "_s, type}));
		}
	}
}

void InvokerBytecodeGenerator::emitX2I($Wrapper* type) {
	$init($InvokerBytecodeGenerator$2);
	switch ($nc($InvokerBytecodeGenerator$2::$SwitchMap$sun$invoke$util$Wrapper)->get($nc((type))->ordinal())) {
	case 6:
		{
			$nc(this->mv)->visitInsn($Opcodes::L2I);
			break;
		}
	case 7:
		{
			$nc(this->mv)->visitInsn($Opcodes::F2I);
			break;
		}
	case 8:
		{
			$nc(this->mv)->visitInsn($Opcodes::D2I);
			break;
		}
	default:
		{
			$throwNew($InternalError, $$str({"unknown type: "_s, type}));
		}
	}
}

$MemberName* InvokerBytecodeGenerator::generateLambdaFormInterpreterEntryPoint($MethodType* mt) {
	$init(InvokerBytecodeGenerator);
	$useLocalCurrentObjectStackCache();
	if (!InvokerBytecodeGenerator::$assertionsDisabled && !($LambdaForm::isValidSignature($($LambdaForm::basicTypeSignature(mt))))) {
		$throwNew($AssertionError);
	}
	$var($String, name, $str({"interpret_"_s, $$str($LambdaForm$BasicType::basicTypeChar($($cast($Class, $nc(mt)->returnType()))))}));
	$var($MethodType, type, mt);
	$load($MethodHandle);
	$assign(type, $nc(type)->changeParameterType(0, $MethodHandle::class$));
	$var(InvokerBytecodeGenerator, g, $new(InvokerBytecodeGenerator, "LFI"_s, name, type));
	return g->loadMethod($(g->generateLambdaFormInterpreterEntryPointBytes()));
}

$bytes* InvokerBytecodeGenerator::generateLambdaFormInterpreterEntryPointBytes() {
	$useLocalCurrentObjectStackCache();
	classFilePrologue();
	methodPrologue();
	$nc(this->mv)->visitAnnotation(InvokerBytecodeGenerator::HIDDEN_SIG, true);
	$nc(this->mv)->visitAnnotation(InvokerBytecodeGenerator::DONTINLINE_SIG, true);
	emitIconstInsn($nc(this->invokerType)->parameterCount());
	$nc(this->mv)->visitTypeInsn($Opcodes::ANEWARRAY, "java/lang/Object"_s);
	for (int32_t i = 0; i < $nc(this->invokerType)->parameterCount(); ++i) {
		$Class* ptype = $cast($Class, $nc(this->invokerType)->parameterType(i));
		$nc(this->mv)->visitInsn($Opcodes::DUP);
		emitIconstInsn(i);
		emitLoadInsn($($LambdaForm$BasicType::basicType(ptype)), i);
		if ($nc(ptype)->isPrimitive()) {
			emitBoxing($($Wrapper::forPrimitiveType(ptype)));
		}
		$nc(this->mv)->visitInsn($Opcodes::AASTORE);
	}
	emitAloadInsn(0);
	$nc(this->mv)->visitFieldInsn($Opcodes::GETFIELD, InvokerBytecodeGenerator::MH, "form"_s, "Ljava/lang/invoke/LambdaForm;"_s);
	$nc(this->mv)->visitInsn($Opcodes::SWAP);
	$nc(this->mv)->visitMethodInsn($Opcodes::INVOKEVIRTUAL, InvokerBytecodeGenerator::LF, "interpretWithArguments"_s, "([Ljava/lang/Object;)Ljava/lang/Object;"_s, false);
	$Class* rtype = $cast($Class, $nc(this->invokerType)->returnType());
	$init($Void);
	if ($nc(rtype)->isPrimitive() && rtype != $Void::TYPE) {
		emitUnboxing($($Wrapper::forPrimitiveType(rtype)));
	}
	emitReturnInsn($($LambdaForm$BasicType::basicType(rtype)));
	methodEpilogue();
	clinit(this->cw, this->className$, this->classData$);
	bogusMethod(this->invokerType);
	$var($bytes, classFile, $nc(this->cw)->toByteArray());
	maybeDump(classFile);
	return classFile;
}

$MemberName* InvokerBytecodeGenerator::generateNamedFunctionInvoker($MethodTypeForm* typeForm) {
	$init(InvokerBytecodeGenerator);
	$useLocalCurrentObjectStackCache();
	$init($LambdaForm$NamedFunction);
	$var($MethodType, invokerType, $LambdaForm$NamedFunction::INVOKER_METHOD_TYPE);
	$var($String, invokerName, $str({"invoke_"_s, $($LambdaForm::shortenSignature($($LambdaForm::basicTypeSignature($($nc(typeForm)->erasedType())))))}));
	$var(InvokerBytecodeGenerator, g, $new(InvokerBytecodeGenerator, "NFI"_s, invokerName, invokerType));
	return g->loadMethod($(g->generateNamedFunctionInvokerImpl(typeForm)));
}

$bytes* InvokerBytecodeGenerator::generateNamedFunctionInvokerImpl($MethodTypeForm* typeForm) {
	$useLocalCurrentObjectStackCache();
	$var($MethodType, dstType, $nc(typeForm)->erasedType());
	classFilePrologue();
	methodPrologue();
	$nc(this->mv)->visitAnnotation(InvokerBytecodeGenerator::HIDDEN_SIG, true);
	$nc(this->mv)->visitAnnotation(InvokerBytecodeGenerator::FORCEINLINE_SIG, true);
	emitAloadInsn(0);
	for (int32_t i = 0; i < $nc(dstType)->parameterCount(); ++i) {
		emitAloadInsn(1);
		emitIconstInsn(i);
		$nc(this->mv)->visitInsn($Opcodes::AALOAD);
		$Class* dptype = $cast($Class, dstType->parameterType(i));
		if ($nc(dptype)->isPrimitive()) {
			$Wrapper* dstWrapper = $Wrapper::forBasicType(dptype);
			$Wrapper* srcWrapper = $nc(dstWrapper)->isSubwordOrInt() ? $Wrapper::INT : dstWrapper;
			emitUnboxing(srcWrapper);
			emitPrimCast(srcWrapper, dstWrapper);
		}
	}
	$var($String, targetDesc, $nc($($nc(dstType)->basicType()))->toMethodDescriptorString());
	$nc(this->mv)->visitMethodInsn($Opcodes::INVOKEVIRTUAL, InvokerBytecodeGenerator::MH, "invokeBasic"_s, targetDesc, false);
	$Class* rtype = $cast($Class, dstType->returnType());
	$init($Void);
	if (rtype != $Void::TYPE && $nc(rtype)->isPrimitive()) {
		$Wrapper* srcWrapper = $Wrapper::forBasicType(rtype);
		$Wrapper* dstWrapper = $nc(srcWrapper)->isSubwordOrInt() ? $Wrapper::INT : srcWrapper;
		emitPrimCast(srcWrapper, dstWrapper);
		emitBoxing(dstWrapper);
	}
	if (rtype == $Void::TYPE) {
		$nc(this->mv)->visitInsn($Opcodes::ACONST_NULL);
	}
	$init($LambdaForm$BasicType);
	emitReturnInsn($LambdaForm$BasicType::L_TYPE);
	methodEpilogue();
	clinit(this->cw, this->className$, this->classData$);
	bogusMethod(dstType);
	$var($bytes, classFile, $nc(this->cw)->toByteArray());
	maybeDump(classFile);
	return classFile;
}

void InvokerBytecodeGenerator::bogusMethod(Object$* os) {
	$init($MethodHandleStatics);
	if ($MethodHandleStatics::DUMP_CLASS_FILES) {
		$set(this, mv, $nc(this->cw)->visitMethod($Opcodes::ACC_STATIC, "dummy"_s, "()V"_s, nullptr, nullptr));
		$nc(this->mv)->visitLdcInsn($($nc($of(os))->toString()));
		$nc(this->mv)->visitInsn($Opcodes::POP);
		$nc(this->mv)->visitInsn($Opcodes::RETURN);
		$nc(this->mv)->visitMaxs(0, 0);
		$nc(this->mv)->visitEnd();
	}
}

$ClassArray* InvokerBytecodeGenerator::lambda$emitLoop$1(int32_t x$0) {
	$init(InvokerBytecodeGenerator);
	return $new($ClassArray, x$0);
}

bool InvokerBytecodeGenerator::lambda$emitLoop$0($LambdaForm$BasicType* bt) {
	$init(InvokerBytecodeGenerator);
	$init($LambdaForm$BasicType);
	return bt != $LambdaForm$BasicType::V_TYPE;
}

void clinit$InvokerBytecodeGenerator($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(InvokerBytecodeGenerator::MH, "java/lang/invoke/MethodHandle"_s);
	$assignStatic(InvokerBytecodeGenerator::MHI, "java/lang/invoke/MethodHandleImpl"_s);
	$assignStatic(InvokerBytecodeGenerator::LF, "java/lang/invoke/LambdaForm"_s);
	$assignStatic(InvokerBytecodeGenerator::LFN, "java/lang/invoke/LambdaForm$Name"_s);
	$assignStatic(InvokerBytecodeGenerator::CLS, "java/lang/Class"_s);
	$assignStatic(InvokerBytecodeGenerator::OBJ, "java/lang/Object"_s);
	$assignStatic(InvokerBytecodeGenerator::OBJARY, "[Ljava/lang/Object;"_s);
	$assignStatic(InvokerBytecodeGenerator::LOOP_CLAUSES, $str({InvokerBytecodeGenerator::MHI, "$LoopClauses"_s}));
	$assignStatic(InvokerBytecodeGenerator::MHARY2, $str({"[[L"_s, InvokerBytecodeGenerator::MH, ";"_s}));
	$assignStatic(InvokerBytecodeGenerator::MH_SIG, $str({"L"_s, InvokerBytecodeGenerator::MH, ";"_s}));
	$assignStatic(InvokerBytecodeGenerator::LF_SIG, $str({"L"_s, InvokerBytecodeGenerator::LF, ";"_s}));
	$assignStatic(InvokerBytecodeGenerator::LFN_SIG, $str({"L"_s, InvokerBytecodeGenerator::LFN, ";"_s}));
	$assignStatic(InvokerBytecodeGenerator::LL_SIG, $str({"(L"_s, InvokerBytecodeGenerator::OBJ, ";)L"_s, InvokerBytecodeGenerator::OBJ, ";"_s}));
	$assignStatic(InvokerBytecodeGenerator::LLV_SIG, $str({"(L"_s, InvokerBytecodeGenerator::OBJ, ";L"_s, InvokerBytecodeGenerator::OBJ, ";)V"_s}));
	$assignStatic(InvokerBytecodeGenerator::CLASS_PREFIX, $str({InvokerBytecodeGenerator::LF, "$"_s}));
	$assignStatic(InvokerBytecodeGenerator::SOURCE_PREFIX, "LambdaForm$"_s);
	$assignStatic(InvokerBytecodeGenerator::INVOKER_SUPER_NAME, InvokerBytecodeGenerator::OBJ);
	InvokerBytecodeGenerator::$assertionsDisabled = !InvokerBytecodeGenerator::class$->desiredAssertionStatus();
	$assignStatic(InvokerBytecodeGenerator::MEMBERNAME_FACTORY, $MemberName::getFactory());
	$load($LambdaForm);
	$assignStatic(InvokerBytecodeGenerator::HOST_CLASS, $LambdaForm::class$);
	$assignStatic(InvokerBytecodeGenerator::LOOKUP, InvokerBytecodeGenerator::lookup());
	{
		$init($MethodHandleStatics);
		if ($MethodHandleStatics::DUMP_CLASS_FILES) {
			$assignStatic(InvokerBytecodeGenerator::DUMP_CLASS_FILES_COUNTERS, $new($HashMap));
			try {
				$var($File, dumpDir, $new($File, "DUMP_CLASS_FILES"_s));
				if (!dumpDir->exists()) {
					dumpDir->mkdirs();
				}
				$assignStatic(InvokerBytecodeGenerator::DUMP_CLASS_FILES_DIR, dumpDir);
				$nc($System::out)->println($$str({"Dumping class files to "_s, InvokerBytecodeGenerator::DUMP_CLASS_FILES_DIR, "/..."_s}));
			} catch ($Exception& e) {
				$throw($($MethodHandleStatics::newInternalError($cast($Exception, e))));
			}
		} else {
			$assignStatic(InvokerBytecodeGenerator::DUMP_CLASS_FILES_COUNTERS, nullptr);
			$assignStatic(InvokerBytecodeGenerator::DUMP_CLASS_FILES_DIR, nullptr);
		}
	}
	$assignStatic(InvokerBytecodeGenerator::DONTINLINE_SIG, InvokerBytecodeGenerator::className("Ljdk/internal/vm/annotation/DontInline;"_s));
	$assignStatic(InvokerBytecodeGenerator::FORCEINLINE_SIG, InvokerBytecodeGenerator::className("Ljdk/internal/vm/annotation/ForceInline;"_s));
	$assignStatic(InvokerBytecodeGenerator::HIDDEN_SIG, InvokerBytecodeGenerator::className("Ljdk/internal/vm/annotation/Hidden;"_s));
	$assignStatic(InvokerBytecodeGenerator::INJECTEDPROFILE_SIG, InvokerBytecodeGenerator::className("Ljava/lang/invoke/InjectedProfile;"_s));
	$assignStatic(InvokerBytecodeGenerator::LF_COMPILED_SIG, InvokerBytecodeGenerator::className("Ljava/lang/invoke/LambdaForm$Compiled;"_s));
	$load($Arrays);
	$load($Unsafe);
	$assignStatic(InvokerBytecodeGenerator::STATICALLY_INVOCABLE_PACKAGES, $new($ClassArray, {
		$Object::class$,
		$Arrays::class$,
		$Unsafe::class$
	}));
}

InvokerBytecodeGenerator::InvokerBytecodeGenerator() {
}

$Class* InvokerBytecodeGenerator::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(InvokerBytecodeGenerator$$Lambda$lambda$emitLoop$0::classInfo$.name)) {
			return InvokerBytecodeGenerator$$Lambda$lambda$emitLoop$0::load$(name, initialize);
		}
		if (name->equals(InvokerBytecodeGenerator$$Lambda$basicTypeClass$1::classInfo$.name)) {
			return InvokerBytecodeGenerator$$Lambda$basicTypeClass$1::load$(name, initialize);
		}
		if (name->equals(InvokerBytecodeGenerator$$Lambda$lambda$emitLoop$1$2::classInfo$.name)) {
			return InvokerBytecodeGenerator$$Lambda$lambda$emitLoop$1$2::load$(name, initialize);
		}
	}
	$loadClass(InvokerBytecodeGenerator, name, initialize, &_InvokerBytecodeGenerator_ClassInfo_, clinit$InvokerBytecodeGenerator, allocate$InvokerBytecodeGenerator);
	return class$;
}

$Class* InvokerBytecodeGenerator::class$ = nullptr;

		} // invoke
	} // lang
} // java