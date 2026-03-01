#include <jdk/internal/org/objectweb/asm/commons/GeneratorAdapter.h>

#include <java/lang/IllegalStateException.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/List.h>
#include <jdk/internal/org/objectweb/asm/ClassVisitor.h>
#include <jdk/internal/org/objectweb/asm/ConstantDynamic.h>
#include <jdk/internal/org/objectweb/asm/Handle.h>
#include <jdk/internal/org/objectweb/asm/Label.h>
#include <jdk/internal/org/objectweb/asm/MethodVisitor.h>
#include <jdk/internal/org/objectweb/asm/Opcodes.h>
#include <jdk/internal/org/objectweb/asm/Type.h>
#include <jdk/internal/org/objectweb/asm/commons/InstructionAdapter.h>
#include <jdk/internal/org/objectweb/asm/commons/LocalVariablesSorter.h>
#include <jdk/internal/org/objectweb/asm/commons/Method.h>
#include <jdk/internal/org/objectweb/asm/commons/TableSwitchGenerator.h>
#include <jcpp.h>

#undef ACC_ABSTRACT
#undef ACC_STATIC
#undef ACONST_NULL
#undef ADD
#undef ALOAD
#undef AND
#undef ARRAY
#undef ARRAYLENGTH
#undef ASM8
#undef ATHROW
#undef BIPUSH
#undef BOOLEAN
#undef BOOLEAN_TYPE
#undef BOOLEAN_VALUE
#undef BYTE
#undef BYTE_TYPE
#undef CHAR
#undef CHARACTER_TYPE
#undef CHAR_VALUE
#undef CHECKCAST
#undef CLASS_DESCRIPTOR
#undef DCMPG
#undef DCMPL
#undef DCONST_0
#undef DIV
#undef DOUBLE
#undef DOUBLE_TYPE
#undef DOUBLE_VALUE
#undef DUP
#undef DUP2
#undef DUP2_X1
#undef DUP2_X2
#undef DUP_X1
#undef DUP_X2
#undef EQ
#undef FCMPG
#undef FCMPL
#undef FCONST_0
#undef FLOAT
#undef FLOAT_TYPE
#undef FLOAT_VALUE
#undef GE
#undef GETFIELD
#undef GETSTATIC
#undef GOTO
#undef GT
#undef IALOAD
#undef IASTORE
#undef ICONST_0
#undef ICONST_1
#undef IFNONNULL
#undef IFNULL
#undef IF_ACMPEQ
#undef IF_ACMPNE
#undef IF_ICMPEQ
#undef IF_ICMPGE
#undef IF_ICMPGT
#undef IF_ICMPLE
#undef IF_ICMPLT
#undef IF_ICMPNE
#undef ILOAD
#undef INSTANCEOF
#undef INT
#undef INTEGER_TYPE
#undef INT_TYPE
#undef INT_VALUE
#undef INVOKEINTERFACE
#undef INVOKESPECIAL
#undef INVOKESTATIC
#undef INVOKEVIRTUAL
#undef IRETURN
#undef ISTORE
#undef IXOR
#undef LCMP
#undef LCONST_0
#undef LE
#undef LONG
#undef LONG_TYPE
#undef LONG_VALUE
#undef LT
#undef MAX_VALUE
#undef MIN_VALUE
#undef MONITORENTER
#undef MONITOREXIT
#undef MUL
#undef NE
#undef NEG
#undef NEW
#undef NUMBER_TYPE
#undef OBJECT
#undef OBJECT_TYPE
#undef OR
#undef POP
#undef POP2
#undef PUTFIELD
#undef PUTSTATIC
#undef REM
#undef RET
#undef SHL
#undef SHORT
#undef SHORT_TYPE
#undef SHR
#undef SIPUSH
#undef SUB
#undef SWAP
#undef USHR
#undef VOID
#undef VOID_TYPE
#undef XOR

using $LabelArray = $Array<::jdk::internal::org::objectweb::asm$::Label>;
using $TypeArray = $Array<::jdk::internal::org::objectweb::asm$::Type>;
using $Byte = ::java::lang::Byte;
using $ClassInfo = ::java::lang::ClassInfo;
using $Double = ::java::lang::Double;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Short = ::java::lang::Short;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $List = ::java::util::List;
using $ClassVisitor = ::jdk::internal::org::objectweb::asm$::ClassVisitor;
using $ConstantDynamic = ::jdk::internal::org::objectweb::asm$::ConstantDynamic;
using $Handle = ::jdk::internal::org::objectweb::asm$::Handle;
using $Label = ::jdk::internal::org::objectweb::asm$::Label;
using $MethodVisitor = ::jdk::internal::org::objectweb::asm$::MethodVisitor;
using $Opcodes = ::jdk::internal::org::objectweb::asm$::Opcodes;
using $Type = ::jdk::internal::org::objectweb::asm$::Type;
using $InstructionAdapter = ::jdk::internal::org::objectweb::asm$::commons::InstructionAdapter;
using $LocalVariablesSorter = ::jdk::internal::org::objectweb::asm$::commons::LocalVariablesSorter;
using $Method = ::jdk::internal::org::objectweb::asm$::commons::Method;
using $TableSwitchGenerator = ::jdk::internal::org::objectweb::asm$::commons::TableSwitchGenerator;

namespace jdk {
	namespace internal {
		namespace org {
			namespace objectweb {
				namespace asm$ {
					namespace commons {

$FieldInfo _GeneratorAdapter_FieldInfo_[] = {
	{"CLASS_DESCRIPTOR", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(GeneratorAdapter, CLASS_DESCRIPTOR)},
	{"BYTE_TYPE", "Ljdk/internal/org/objectweb/asm/Type;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(GeneratorAdapter, BYTE_TYPE)},
	{"BOOLEAN_TYPE", "Ljdk/internal/org/objectweb/asm/Type;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(GeneratorAdapter, BOOLEAN_TYPE)},
	{"SHORT_TYPE", "Ljdk/internal/org/objectweb/asm/Type;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(GeneratorAdapter, SHORT_TYPE)},
	{"CHARACTER_TYPE", "Ljdk/internal/org/objectweb/asm/Type;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(GeneratorAdapter, CHARACTER_TYPE)},
	{"INTEGER_TYPE", "Ljdk/internal/org/objectweb/asm/Type;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(GeneratorAdapter, INTEGER_TYPE)},
	{"FLOAT_TYPE", "Ljdk/internal/org/objectweb/asm/Type;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(GeneratorAdapter, FLOAT_TYPE)},
	{"LONG_TYPE", "Ljdk/internal/org/objectweb/asm/Type;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(GeneratorAdapter, LONG_TYPE)},
	{"DOUBLE_TYPE", "Ljdk/internal/org/objectweb/asm/Type;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(GeneratorAdapter, DOUBLE_TYPE)},
	{"NUMBER_TYPE", "Ljdk/internal/org/objectweb/asm/Type;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(GeneratorAdapter, NUMBER_TYPE)},
	{"OBJECT_TYPE", "Ljdk/internal/org/objectweb/asm/Type;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(GeneratorAdapter, OBJECT_TYPE)},
	{"BOOLEAN_VALUE", "Ljdk/internal/org/objectweb/asm/commons/Method;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(GeneratorAdapter, BOOLEAN_VALUE)},
	{"CHAR_VALUE", "Ljdk/internal/org/objectweb/asm/commons/Method;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(GeneratorAdapter, CHAR_VALUE)},
	{"INT_VALUE", "Ljdk/internal/org/objectweb/asm/commons/Method;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(GeneratorAdapter, INT_VALUE)},
	{"FLOAT_VALUE", "Ljdk/internal/org/objectweb/asm/commons/Method;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(GeneratorAdapter, FLOAT_VALUE)},
	{"LONG_VALUE", "Ljdk/internal/org/objectweb/asm/commons/Method;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(GeneratorAdapter, LONG_VALUE)},
	{"DOUBLE_VALUE", "Ljdk/internal/org/objectweb/asm/commons/Method;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(GeneratorAdapter, DOUBLE_VALUE)},
	{"ADD", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GeneratorAdapter, ADD)},
	{"SUB", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GeneratorAdapter, SUB)},
	{"MUL", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GeneratorAdapter, MUL)},
	{"DIV", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GeneratorAdapter, DIV)},
	{"REM", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GeneratorAdapter, REM)},
	{"NEG", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GeneratorAdapter, NEG)},
	{"SHL", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GeneratorAdapter, SHL)},
	{"SHR", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GeneratorAdapter, SHR)},
	{"USHR", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GeneratorAdapter, USHR)},
	{"AND", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GeneratorAdapter, AND)},
	{"OR", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GeneratorAdapter, OR)},
	{"XOR", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GeneratorAdapter, XOR)},
	{"EQ", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GeneratorAdapter, EQ)},
	{"NE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GeneratorAdapter, NE)},
	{"LT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GeneratorAdapter, LT)},
	{"GE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GeneratorAdapter, GE)},
	{"GT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GeneratorAdapter, GT)},
	{"LE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GeneratorAdapter, LE)},
	{"access", "I", nullptr, $PRIVATE | $FINAL, $field(GeneratorAdapter, access)},
	{"name", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(GeneratorAdapter, name)},
	{"returnType", "Ljdk/internal/org/objectweb/asm/Type;", nullptr, $PRIVATE | $FINAL, $field(GeneratorAdapter, returnType)},
	{"argumentTypes", "[Ljdk/internal/org/objectweb/asm/Type;", nullptr, $PRIVATE | $FINAL, $field(GeneratorAdapter, argumentTypes)},
	{"localTypes", "Ljava/util/List;", "Ljava/util/List<Ljdk/internal/org/objectweb/asm/Type;>;", $PRIVATE | $FINAL, $field(GeneratorAdapter, localTypes)},
	{}
};

$MethodInfo _GeneratorAdapter_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/org/objectweb/asm/MethodVisitor;ILjava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(GeneratorAdapter, init$, void, $MethodVisitor*, int32_t, $String*, $String*)},
	{"<init>", "(ILjdk/internal/org/objectweb/asm/MethodVisitor;ILjava/lang/String;Ljava/lang/String;)V", nullptr, $PROTECTED, $method(GeneratorAdapter, init$, void, int32_t, $MethodVisitor*, int32_t, $String*, $String*)},
	{"<init>", "(ILjdk/internal/org/objectweb/asm/commons/Method;Ljdk/internal/org/objectweb/asm/MethodVisitor;)V", nullptr, $PUBLIC, $method(GeneratorAdapter, init$, void, int32_t, $Method*, $MethodVisitor*)},
	{"<init>", "(ILjdk/internal/org/objectweb/asm/commons/Method;Ljava/lang/String;[Ljdk/internal/org/objectweb/asm/Type;Ljdk/internal/org/objectweb/asm/ClassVisitor;)V", nullptr, $PUBLIC, $method(GeneratorAdapter, init$, void, int32_t, $Method*, $String*, $TypeArray*, $ClassVisitor*)},
	{"arrayLength", "()V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, arrayLength, void)},
	{"arrayLoad", "(Ljdk/internal/org/objectweb/asm/Type;)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, arrayLoad, void, $Type*)},
	{"arrayStore", "(Ljdk/internal/org/objectweb/asm/Type;)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, arrayStore, void, $Type*)},
	{"box", "(Ljdk/internal/org/objectweb/asm/Type;)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, box, void, $Type*)},
	{"cast", "(Ljdk/internal/org/objectweb/asm/Type;Ljdk/internal/org/objectweb/asm/Type;)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, cast, void, $Type*, $Type*)},
	{"catchException", "(Ljdk/internal/org/objectweb/asm/Label;Ljdk/internal/org/objectweb/asm/Label;Ljdk/internal/org/objectweb/asm/Type;)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, catchException, void, $Label*, $Label*, $Type*)},
	{"checkCast", "(Ljdk/internal/org/objectweb/asm/Type;)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, checkCast, void, $Type*)},
	{"dup", "()V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, dup, void)},
	{"dup2", "()V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, dup2, void)},
	{"dup2X1", "()V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, dup2X1, void)},
	{"dup2X2", "()V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, dup2X2, void)},
	{"dupX1", "()V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, dupX1, void)},
	{"dupX2", "()V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, dupX2, void)},
	{"endMethod", "()V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, endMethod, void)},
	{"fieldInsn", "(ILjdk/internal/org/objectweb/asm/Type;Ljava/lang/String;Ljdk/internal/org/objectweb/asm/Type;)V", nullptr, $PRIVATE, $method(GeneratorAdapter, fieldInsn, void, int32_t, $Type*, $String*, $Type*)},
	{"getAccess", "()I", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, getAccess, int32_t)},
	{"getArgIndex", "(I)I", nullptr, $PRIVATE, $method(GeneratorAdapter, getArgIndex, int32_t, int32_t)},
	{"getArgumentTypes", "()[Ljdk/internal/org/objectweb/asm/Type;", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, getArgumentTypes, $TypeArray*)},
	{"getBoxedType", "(Ljdk/internal/org/objectweb/asm/Type;)Ljdk/internal/org/objectweb/asm/Type;", nullptr, $PRIVATE | $STATIC, $staticMethod(GeneratorAdapter, getBoxedType, $Type*, $Type*)},
	{"getField", "(Ljdk/internal/org/objectweb/asm/Type;Ljava/lang/String;Ljdk/internal/org/objectweb/asm/Type;)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, getField, void, $Type*, $String*, $Type*)},
	{"getInternalNames", "([Ljdk/internal/org/objectweb/asm/Type;)[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(GeneratorAdapter, getInternalNames, $StringArray*, $TypeArray*)},
	{"getLocalType", "(I)Ljdk/internal/org/objectweb/asm/Type;", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, getLocalType, $Type*, int32_t)},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, getName, $String*)},
	{"getReturnType", "()Ljdk/internal/org/objectweb/asm/Type;", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, getReturnType, $Type*)},
	{"getStatic", "(Ljdk/internal/org/objectweb/asm/Type;Ljava/lang/String;Ljdk/internal/org/objectweb/asm/Type;)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, getStatic, void, $Type*, $String*, $Type*)},
	{"goTo", "(Ljdk/internal/org/objectweb/asm/Label;)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, goTo, void, $Label*)},
	{"ifCmp", "(Ljdk/internal/org/objectweb/asm/Type;ILjdk/internal/org/objectweb/asm/Label;)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, ifCmp, void, $Type*, int32_t, $Label*)},
	{"ifICmp", "(ILjdk/internal/org/objectweb/asm/Label;)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, ifICmp, void, int32_t, $Label*)},
	{"ifNonNull", "(Ljdk/internal/org/objectweb/asm/Label;)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, ifNonNull, void, $Label*)},
	{"ifNull", "(Ljdk/internal/org/objectweb/asm/Label;)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, ifNull, void, $Label*)},
	{"ifZCmp", "(ILjdk/internal/org/objectweb/asm/Label;)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, ifZCmp, void, int32_t, $Label*)},
	{"iinc", "(II)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, iinc, void, int32_t, int32_t)},
	{"instanceOf", "(Ljdk/internal/org/objectweb/asm/Type;)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, instanceOf, void, $Type*)},
	{"invokeConstructor", "(Ljdk/internal/org/objectweb/asm/Type;Ljdk/internal/org/objectweb/asm/commons/Method;)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, invokeConstructor, void, $Type*, $Method*)},
	{"invokeDynamic", "(Ljava/lang/String;Ljava/lang/String;Ljdk/internal/org/objectweb/asm/Handle;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(GeneratorAdapter, invokeDynamic, void, $String*, $String*, $Handle*, $ObjectArray*)},
	{"invokeInsn", "(ILjdk/internal/org/objectweb/asm/Type;Ljdk/internal/org/objectweb/asm/commons/Method;Z)V", nullptr, $PRIVATE, $method(GeneratorAdapter, invokeInsn, void, int32_t, $Type*, $Method*, bool)},
	{"invokeInterface", "(Ljdk/internal/org/objectweb/asm/Type;Ljdk/internal/org/objectweb/asm/commons/Method;)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, invokeInterface, void, $Type*, $Method*)},
	{"invokeStatic", "(Ljdk/internal/org/objectweb/asm/Type;Ljdk/internal/org/objectweb/asm/commons/Method;)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, invokeStatic, void, $Type*, $Method*)},
	{"invokeVirtual", "(Ljdk/internal/org/objectweb/asm/Type;Ljdk/internal/org/objectweb/asm/commons/Method;)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, invokeVirtual, void, $Type*, $Method*)},
	{"loadArg", "(I)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, loadArg, void, int32_t)},
	{"loadArgArray", "()V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, loadArgArray, void)},
	{"loadArgs", "(II)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, loadArgs, void, int32_t, int32_t)},
	{"loadArgs", "()V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, loadArgs, void)},
	{"loadInsn", "(Ljdk/internal/org/objectweb/asm/Type;I)V", nullptr, $PRIVATE, $method(GeneratorAdapter, loadInsn, void, $Type*, int32_t)},
	{"loadLocal", "(I)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, loadLocal, void, int32_t)},
	{"loadLocal", "(ILjdk/internal/org/objectweb/asm/Type;)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, loadLocal, void, int32_t, $Type*)},
	{"loadThis", "()V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, loadThis, void)},
	{"mark", "(Ljdk/internal/org/objectweb/asm/Label;)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, mark, void, $Label*)},
	{"mark", "()Ljdk/internal/org/objectweb/asm/Label;", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, mark, $Label*)},
	{"math", "(ILjdk/internal/org/objectweb/asm/Type;)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, math, void, int32_t, $Type*)},
	{"monitorEnter", "()V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, monitorEnter, void)},
	{"monitorExit", "()V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, monitorExit, void)},
	{"newArray", "(Ljdk/internal/org/objectweb/asm/Type;)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, newArray, void, $Type*)},
	{"newInstance", "(Ljdk/internal/org/objectweb/asm/Type;)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, newInstance, void, $Type*)},
	{"newLabel", "()Ljdk/internal/org/objectweb/asm/Label;", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, newLabel, $Label*)},
	{"not", "()V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, not$, void)},
	{"pop", "()V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, pop, void)},
	{"pop2", "()V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, pop2, void)},
	{"push", "(Z)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, push, void, bool)},
	{"push", "(I)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, push, void, int32_t)},
	{"push", "(J)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, push, void, int64_t)},
	{"push", "(F)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, push, void, float)},
	{"push", "(D)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, push, void, double)},
	{"push", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, push, void, $String*)},
	{"push", "(Ljdk/internal/org/objectweb/asm/Type;)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, push, void, $Type*)},
	{"push", "(Ljdk/internal/org/objectweb/asm/Handle;)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, push, void, $Handle*)},
	{"push", "(Ljdk/internal/org/objectweb/asm/ConstantDynamic;)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, push, void, $ConstantDynamic*)},
	{"putField", "(Ljdk/internal/org/objectweb/asm/Type;Ljava/lang/String;Ljdk/internal/org/objectweb/asm/Type;)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, putField, void, $Type*, $String*, $Type*)},
	{"putStatic", "(Ljdk/internal/org/objectweb/asm/Type;Ljava/lang/String;Ljdk/internal/org/objectweb/asm/Type;)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, putStatic, void, $Type*, $String*, $Type*)},
	{"ret", "(I)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, ret, void, int32_t)},
	{"returnValue", "()V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, returnValue, void)},
	{"setLocalType", "(ILjdk/internal/org/objectweb/asm/Type;)V", nullptr, $PROTECTED, $virtualMethod(GeneratorAdapter, setLocalType, void, int32_t, $Type*)},
	{"storeArg", "(I)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, storeArg, void, int32_t)},
	{"storeInsn", "(Ljdk/internal/org/objectweb/asm/Type;I)V", nullptr, $PRIVATE, $method(GeneratorAdapter, storeInsn, void, $Type*, int32_t)},
	{"storeLocal", "(I)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, storeLocal, void, int32_t)},
	{"storeLocal", "(ILjdk/internal/org/objectweb/asm/Type;)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, storeLocal, void, int32_t, $Type*)},
	{"swap", "()V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, swap, void)},
	{"swap", "(Ljdk/internal/org/objectweb/asm/Type;Ljdk/internal/org/objectweb/asm/Type;)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, swap, void, $Type*, $Type*)},
	{"tableSwitch", "([ILjdk/internal/org/objectweb/asm/commons/TableSwitchGenerator;)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, tableSwitch, void, $ints*, $TableSwitchGenerator*)},
	{"tableSwitch", "([ILjdk/internal/org/objectweb/asm/commons/TableSwitchGenerator;Z)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, tableSwitch, void, $ints*, $TableSwitchGenerator*, bool)},
	{"throwException", "()V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, throwException, void)},
	{"throwException", "(Ljdk/internal/org/objectweb/asm/Type;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, throwException, void, $Type*, $String*)},
	{"typeInsn", "(ILjdk/internal/org/objectweb/asm/Type;)V", nullptr, $PRIVATE, $method(GeneratorAdapter, typeInsn, void, int32_t, $Type*)},
	{"unbox", "(Ljdk/internal/org/objectweb/asm/Type;)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, unbox, void, $Type*)},
	{"valueOf", "(Ljdk/internal/org/objectweb/asm/Type;)V", nullptr, $PUBLIC, $virtualMethod(GeneratorAdapter, valueOf, void, $Type*)},
	{}
};

$ClassInfo _GeneratorAdapter_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.org.objectweb.asm.commons.GeneratorAdapter",
	"jdk.internal.org.objectweb.asm.commons.LocalVariablesSorter",
	nullptr,
	_GeneratorAdapter_FieldInfo_,
	_GeneratorAdapter_MethodInfo_
};

$Object* allocate$GeneratorAdapter($Class* clazz) {
	return $of($alloc(GeneratorAdapter));
}

$String* GeneratorAdapter::CLASS_DESCRIPTOR = nullptr;
$Type* GeneratorAdapter::BYTE_TYPE = nullptr;
$Type* GeneratorAdapter::BOOLEAN_TYPE = nullptr;
$Type* GeneratorAdapter::SHORT_TYPE = nullptr;
$Type* GeneratorAdapter::CHARACTER_TYPE = nullptr;
$Type* GeneratorAdapter::INTEGER_TYPE = nullptr;
$Type* GeneratorAdapter::FLOAT_TYPE = nullptr;
$Type* GeneratorAdapter::LONG_TYPE = nullptr;
$Type* GeneratorAdapter::DOUBLE_TYPE = nullptr;
$Type* GeneratorAdapter::NUMBER_TYPE = nullptr;
$Type* GeneratorAdapter::OBJECT_TYPE = nullptr;
$Method* GeneratorAdapter::BOOLEAN_VALUE = nullptr;
$Method* GeneratorAdapter::CHAR_VALUE = nullptr;
$Method* GeneratorAdapter::INT_VALUE = nullptr;
$Method* GeneratorAdapter::FLOAT_VALUE = nullptr;
$Method* GeneratorAdapter::LONG_VALUE = nullptr;
$Method* GeneratorAdapter::DOUBLE_VALUE = nullptr;

void GeneratorAdapter::init$($MethodVisitor* methodVisitor, int32_t access, $String* name, $String* descriptor) {
	GeneratorAdapter::init$($Opcodes::ASM8, methodVisitor, access, name, descriptor);
	if ($of(this)->getClass() != GeneratorAdapter::class$) {
		$throwNew($IllegalStateException);
	}
}

void GeneratorAdapter::init$(int32_t api, $MethodVisitor* methodVisitor, int32_t access, $String* name, $String* descriptor) {
	$LocalVariablesSorter::init$(api, access, descriptor, methodVisitor);
	$set(this, localTypes, $new($ArrayList));
	this->access = access;
	$set(this, name, name);
	$set(this, returnType, $Type::getReturnType(descriptor));
	$set(this, argumentTypes, $Type::getArgumentTypes(descriptor));
}

void GeneratorAdapter::init$(int32_t access, $Method* method, $MethodVisitor* methodVisitor) {
	$useLocalCurrentObjectStackCache();
	$var($MethodVisitor, var$0, methodVisitor);
	int32_t var$1 = access;
	$var($String, var$2, $nc(method)->getName());
	GeneratorAdapter::init$(var$0, var$1, var$2, $(method->getDescriptor()));
}

void GeneratorAdapter::init$(int32_t access, $Method* method, $String* signature, $TypeArray* exceptions, $ClassVisitor* classVisitor) {
	$useLocalCurrentObjectStackCache();
	int32_t var$0 = access;
	$var($String, var$1, $nc(method)->getName());
	$var($String, var$2, method->getDescriptor());
	$var($String, var$3, signature);
	GeneratorAdapter::init$(access, method, $($nc(classVisitor)->visitMethod(var$0, var$1, var$2, var$3, exceptions == nullptr ? ($StringArray*)nullptr : $(getInternalNames(exceptions)))));
}

$StringArray* GeneratorAdapter::getInternalNames($TypeArray* types) {
	$init(GeneratorAdapter);
	$useLocalCurrentObjectStackCache();
	$var($StringArray, names, $new($StringArray, $nc(types)->length));
	for (int32_t i = 0; i < names->length; ++i) {
		names->set(i, $($nc(types->get(i))->getInternalName()));
	}
	return names;
}

int32_t GeneratorAdapter::getAccess() {
	return this->access;
}

$String* GeneratorAdapter::getName() {
	return this->name;
}

$Type* GeneratorAdapter::getReturnType() {
	return this->returnType;
}

$TypeArray* GeneratorAdapter::getArgumentTypes() {
	return $cast($TypeArray, $nc(this->argumentTypes)->clone());
}

void GeneratorAdapter::push(bool value) {
	push(value ? 1 : 0);
}

void GeneratorAdapter::push(int32_t value) {
	if (value >= -1 && value <= 5) {
		$nc(this->mv)->visitInsn($Opcodes::ICONST_0 + value);
	} else if (value >= $Byte::MIN_VALUE && value <= $Byte::MAX_VALUE) {
		$nc(this->mv)->visitIntInsn($Opcodes::BIPUSH, value);
	} else if (value >= $Short::MIN_VALUE && value <= $Short::MAX_VALUE) {
		$nc(this->mv)->visitIntInsn($Opcodes::SIPUSH, value);
	} else {
		$nc(this->mv)->visitLdcInsn($($Integer::valueOf(value)));
	}
}

void GeneratorAdapter::push(int64_t value) {
	if (value == (int64_t)0 || value == (int64_t)1) {
		$nc(this->mv)->visitInsn($Opcodes::LCONST_0 + (int32_t)value);
	} else {
		$nc(this->mv)->visitLdcInsn($($Long::valueOf(value)));
	}
}

void GeneratorAdapter::push(float value) {
	int32_t bits = $Float::floatToIntBits(value);
	if (bits == (int64_t)0 || bits == 0x3F800000 || bits == 0x40000000) {
		$nc(this->mv)->visitInsn($Opcodes::FCONST_0 + $cast(int32_t, value));
	} else {
		$nc(this->mv)->visitLdcInsn($($Float::valueOf(value)));
	}
}

void GeneratorAdapter::push(double value) {
	int64_t bits = $Double::doubleToLongBits(value);
	if (bits == (int64_t)0 || bits == (int64_t)0x3FF0000000000000) {
		$nc(this->mv)->visitInsn($Opcodes::DCONST_0 + $cast(int32_t, value));
	} else {
		$nc(this->mv)->visitLdcInsn($($Double::valueOf(value)));
	}
}

void GeneratorAdapter::push($String* value) {
	if (value == nullptr) {
		$nc(this->mv)->visitInsn($Opcodes::ACONST_NULL);
	} else {
		$nc(this->mv)->visitLdcInsn(value);
	}
}

void GeneratorAdapter::push($Type* value) {
	if (value == nullptr) {
		$nc(this->mv)->visitInsn($Opcodes::ACONST_NULL);
	} else {
		switch ($nc(value)->getSort()) {
		case $Type::BOOLEAN:
			{
				$nc(this->mv)->visitFieldInsn($Opcodes::GETSTATIC, "java/lang/Boolean"_s, "TYPE"_s, GeneratorAdapter::CLASS_DESCRIPTOR);
				break;
			}
		case $Type::CHAR:
			{
				$nc(this->mv)->visitFieldInsn($Opcodes::GETSTATIC, "java/lang/Character"_s, "TYPE"_s, GeneratorAdapter::CLASS_DESCRIPTOR);
				break;
			}
		case $Type::BYTE:
			{
				$nc(this->mv)->visitFieldInsn($Opcodes::GETSTATIC, "java/lang/Byte"_s, "TYPE"_s, GeneratorAdapter::CLASS_DESCRIPTOR);
				break;
			}
		case $Type::SHORT:
			{
				$nc(this->mv)->visitFieldInsn($Opcodes::GETSTATIC, "java/lang/Short"_s, "TYPE"_s, GeneratorAdapter::CLASS_DESCRIPTOR);
				break;
			}
		case $Type::INT:
			{
				$nc(this->mv)->visitFieldInsn($Opcodes::GETSTATIC, "java/lang/Integer"_s, "TYPE"_s, GeneratorAdapter::CLASS_DESCRIPTOR);
				break;
			}
		case $Type::FLOAT:
			{
				$nc(this->mv)->visitFieldInsn($Opcodes::GETSTATIC, "java/lang/Float"_s, "TYPE"_s, GeneratorAdapter::CLASS_DESCRIPTOR);
				break;
			}
		case $Type::LONG:
			{
				$nc(this->mv)->visitFieldInsn($Opcodes::GETSTATIC, "java/lang/Long"_s, "TYPE"_s, GeneratorAdapter::CLASS_DESCRIPTOR);
				break;
			}
		case $Type::DOUBLE:
			{
				$nc(this->mv)->visitFieldInsn($Opcodes::GETSTATIC, "java/lang/Double"_s, "TYPE"_s, GeneratorAdapter::CLASS_DESCRIPTOR);
				break;
			}
		default:
			{
				$nc(this->mv)->visitLdcInsn(value);
				break;
			}
		}
	}
}

void GeneratorAdapter::push($Handle* handle) {
	if (handle == nullptr) {
		$nc(this->mv)->visitInsn($Opcodes::ACONST_NULL);
	} else {
		$nc(this->mv)->visitLdcInsn(handle);
	}
}

void GeneratorAdapter::push($ConstantDynamic* constantDynamic) {
	if (constantDynamic == nullptr) {
		$nc(this->mv)->visitInsn($Opcodes::ACONST_NULL);
	} else {
		$nc(this->mv)->visitLdcInsn(constantDynamic);
	}
}

int32_t GeneratorAdapter::getArgIndex(int32_t arg) {
	int32_t index = ((int32_t)(this->access & (uint32_t)$Opcodes::ACC_STATIC)) == 0 ? 1 : 0;
	for (int32_t i = 0; i < arg; ++i) {
		index += $nc($nc(this->argumentTypes)->get(i))->getSize();
	}
	return index;
}

void GeneratorAdapter::loadInsn($Type* type, int32_t index) {
	$nc(this->mv)->visitVarInsn($nc(type)->getOpcode($Opcodes::ILOAD), index);
}

void GeneratorAdapter::storeInsn($Type* type, int32_t index) {
	$nc(this->mv)->visitVarInsn($nc(type)->getOpcode($Opcodes::ISTORE), index);
}

void GeneratorAdapter::loadThis() {
	if (((int32_t)(this->access & (uint32_t)$Opcodes::ACC_STATIC)) != 0) {
		$throwNew($IllegalStateException, "no \'this\' pointer within static method"_s);
	}
	$nc(this->mv)->visitVarInsn($Opcodes::ALOAD, 0);
}

void GeneratorAdapter::loadArg(int32_t arg) {
	loadInsn($nc(this->argumentTypes)->get(arg), getArgIndex(arg));
}

void GeneratorAdapter::loadArgs(int32_t arg, int32_t count) {
	$useLocalCurrentObjectStackCache();
	int32_t index = getArgIndex(arg);
	for (int32_t i = 0; i < count; ++i) {
		$var($Type, argumentType, $nc(this->argumentTypes)->get(arg + i));
		loadInsn(argumentType, index);
		index += $nc(argumentType)->getSize();
	}
}

void GeneratorAdapter::loadArgs() {
	loadArgs(0, $nc(this->argumentTypes)->length);
}

void GeneratorAdapter::loadArgArray() {
	push($nc(this->argumentTypes)->length);
	newArray(GeneratorAdapter::OBJECT_TYPE);
	for (int32_t i = 0; i < $nc(this->argumentTypes)->length; ++i) {
		dup();
		push(i);
		loadArg(i);
		box($nc(this->argumentTypes)->get(i));
		arrayStore(GeneratorAdapter::OBJECT_TYPE);
	}
}

void GeneratorAdapter::storeArg(int32_t arg) {
	storeInsn($nc(this->argumentTypes)->get(arg), getArgIndex(arg));
}

$Type* GeneratorAdapter::getLocalType(int32_t local) {
	return $cast($Type, $nc(this->localTypes)->get(local - this->firstLocal));
}

void GeneratorAdapter::setLocalType(int32_t local, $Type* type) {
	int32_t index = local - this->firstLocal;
	while ($nc(this->localTypes)->size() < index + 1) {
		$nc(this->localTypes)->add(nullptr);
	}
	$nc(this->localTypes)->set(index, type);
}

void GeneratorAdapter::loadLocal(int32_t local) {
	loadInsn($(getLocalType(local)), local);
}

void GeneratorAdapter::loadLocal(int32_t local, $Type* type) {
	setLocalType(local, type);
	loadInsn(type, local);
}

void GeneratorAdapter::storeLocal(int32_t local) {
	storeInsn($(getLocalType(local)), local);
}

void GeneratorAdapter::storeLocal(int32_t local, $Type* type) {
	setLocalType(local, type);
	storeInsn(type, local);
}

void GeneratorAdapter::arrayLoad($Type* type) {
	$nc(this->mv)->visitInsn($nc(type)->getOpcode($Opcodes::IALOAD));
}

void GeneratorAdapter::arrayStore($Type* type) {
	$nc(this->mv)->visitInsn($nc(type)->getOpcode($Opcodes::IASTORE));
}

void GeneratorAdapter::pop() {
	$nc(this->mv)->visitInsn($Opcodes::POP);
}

void GeneratorAdapter::pop2() {
	$nc(this->mv)->visitInsn($Opcodes::POP2);
}

void GeneratorAdapter::dup() {
	$nc(this->mv)->visitInsn($Opcodes::DUP);
}

void GeneratorAdapter::dup2() {
	$nc(this->mv)->visitInsn($Opcodes::DUP2);
}

void GeneratorAdapter::dupX1() {
	$nc(this->mv)->visitInsn($Opcodes::DUP_X1);
}

void GeneratorAdapter::dupX2() {
	$nc(this->mv)->visitInsn($Opcodes::DUP_X2);
}

void GeneratorAdapter::dup2X1() {
	$nc(this->mv)->visitInsn($Opcodes::DUP2_X1);
}

void GeneratorAdapter::dup2X2() {
	$nc(this->mv)->visitInsn($Opcodes::DUP2_X2);
}

void GeneratorAdapter::swap() {
	$nc(this->mv)->visitInsn($Opcodes::SWAP);
}

void GeneratorAdapter::swap($Type* prev, $Type* type) {
	if ($nc(type)->getSize() == 1) {
		if ($nc(prev)->getSize() == 1) {
			swap();
		} else {
			dupX2();
			pop();
		}
	} else if ($nc(prev)->getSize() == 1) {
		dup2X1();
		pop2();
	} else {
		dup2X2();
		pop2();
	}
}

void GeneratorAdapter::math(int32_t op, $Type* type) {
	$nc(this->mv)->visitInsn($nc(type)->getOpcode(op));
}

void GeneratorAdapter::not$() {
	$nc(this->mv)->visitInsn($Opcodes::ICONST_1);
	$nc(this->mv)->visitInsn($Opcodes::IXOR);
}

void GeneratorAdapter::iinc(int32_t local, int32_t amount) {
	$nc(this->mv)->visitIincInsn(local, amount);
}

void GeneratorAdapter::cast($Type* from, $Type* to) {
	if (from != to) {
		bool var$2 = $nc(from)->getSort() < $Type::BOOLEAN;
		bool var$1 = var$2 || $nc(from)->getSort() > $Type::DOUBLE;
		bool var$0 = var$1 || $nc(to)->getSort() < $Type::BOOLEAN;
		if (var$0 || $nc(to)->getSort() > $Type::DOUBLE) {
			$throwNew($IllegalArgumentException, $$str({"Cannot cast from "_s, from, " to "_s, to}));
		}
		$InstructionAdapter::cast(this->mv, from, to);
	}
}

$Type* GeneratorAdapter::getBoxedType($Type* type) {
	$init(GeneratorAdapter);
	switch ($nc(type)->getSort()) {
	case $Type::BYTE:
		{
			return GeneratorAdapter::BYTE_TYPE;
		}
	case $Type::BOOLEAN:
		{
			return GeneratorAdapter::BOOLEAN_TYPE;
		}
	case $Type::SHORT:
		{
			return GeneratorAdapter::SHORT_TYPE;
		}
	case $Type::CHAR:
		{
			return GeneratorAdapter::CHARACTER_TYPE;
		}
	case $Type::INT:
		{
			return GeneratorAdapter::INTEGER_TYPE;
		}
	case $Type::FLOAT:
		{
			return GeneratorAdapter::FLOAT_TYPE;
		}
	case $Type::LONG:
		{
			return GeneratorAdapter::LONG_TYPE;
		}
	case $Type::DOUBLE:
		{
			return GeneratorAdapter::DOUBLE_TYPE;
		}
	default:
		{
			return type;
		}
	}
}

void GeneratorAdapter::box($Type* type) {
	$useLocalCurrentObjectStackCache();
	bool var$0 = $nc(type)->getSort() == $Type::OBJECT;
	if (var$0 || $nc(type)->getSort() == $Type::ARRAY) {
		return;
	}
	if (type == $Type::VOID_TYPE) {
		push(($String*)nullptr);
	} else {
		$var($Type, boxedType, getBoxedType(type));
		newInstance(boxedType);
		if ($nc(type)->getSize() == 2) {
			dupX2();
			dupX2();
			pop();
		} else {
			dupX1();
			swap();
		}
		invokeConstructor(boxedType, $$new($Method, "<init>"_s, $Type::VOID_TYPE, $$new($TypeArray, {type})));
	}
}

void GeneratorAdapter::valueOf($Type* type) {
	$useLocalCurrentObjectStackCache();
	bool var$0 = $nc(type)->getSort() == $Type::OBJECT;
	if (var$0 || $nc(type)->getSort() == $Type::ARRAY) {
		return;
	}
	if (type == $Type::VOID_TYPE) {
		push(($String*)nullptr);
	} else {
		$var($Type, boxedType, getBoxedType(type));
		invokeStatic(boxedType, $$new($Method, "valueOf"_s, boxedType, $$new($TypeArray, {type})));
	}
}

void GeneratorAdapter::unbox($Type* type) {
	$useLocalCurrentObjectStackCache();
	$var($Type, boxedType, GeneratorAdapter::NUMBER_TYPE);
	$var($Method, unboxMethod, nullptr);
	switch ($nc(type)->getSort()) {
	case $Type::VOID:
		{
			return;
		}
	case $Type::CHAR:
		{
			$assign(boxedType, GeneratorAdapter::CHARACTER_TYPE);
			$assign(unboxMethod, GeneratorAdapter::CHAR_VALUE);
			break;
		}
	case $Type::BOOLEAN:
		{
			$assign(boxedType, GeneratorAdapter::BOOLEAN_TYPE);
			$assign(unboxMethod, GeneratorAdapter::BOOLEAN_VALUE);
			break;
		}
	case $Type::DOUBLE:
		{
			$assign(unboxMethod, GeneratorAdapter::DOUBLE_VALUE);
			break;
		}
	case $Type::FLOAT:
		{
			$assign(unboxMethod, GeneratorAdapter::FLOAT_VALUE);
			break;
		}
	case $Type::LONG:
		{
			$assign(unboxMethod, GeneratorAdapter::LONG_VALUE);
			break;
		}
	case $Type::INT:
		{}
	case $Type::SHORT:
		{}
	case $Type::BYTE:
		{
			$assign(unboxMethod, GeneratorAdapter::INT_VALUE);
			break;
		}
	default:
		{
			$assign(unboxMethod, nullptr);
			break;
		}
	}
	if (unboxMethod == nullptr) {
		checkCast(type);
	} else {
		checkCast(boxedType);
		invokeVirtual(boxedType, unboxMethod);
	}
}

$Label* GeneratorAdapter::newLabel() {
	return $new($Label);
}

void GeneratorAdapter::mark($Label* label) {
	$nc(this->mv)->visitLabel(label);
}

$Label* GeneratorAdapter::mark() {
	$var($Label, label, $new($Label));
	$nc(this->mv)->visitLabel(label);
	return label;
}

void GeneratorAdapter::ifCmp($Type* type, int32_t mode, $Label* label) {
	$useLocalCurrentObjectStackCache();
	{
		int32_t intOp = 0;
		switch ($nc(type)->getSort()) {
		case $Type::LONG:
			{
				$nc(this->mv)->visitInsn($Opcodes::LCMP);
				break;
			}
		case $Type::DOUBLE:
			{
				$nc(this->mv)->visitInsn(mode == GeneratorAdapter::GE || mode == GeneratorAdapter::GT ? $Opcodes::DCMPL : $Opcodes::DCMPG);
				break;
			}
		case $Type::FLOAT:
			{
				$nc(this->mv)->visitInsn(mode == GeneratorAdapter::GE || mode == GeneratorAdapter::GT ? $Opcodes::FCMPL : $Opcodes::FCMPG);
				break;
			}
		case $Type::ARRAY:
			{}
		case $Type::OBJECT:
			{
				if (mode == GeneratorAdapter::EQ) {
					$nc(this->mv)->visitJumpInsn($Opcodes::IF_ACMPEQ, label);
					return;
				} else if (mode == GeneratorAdapter::NE) {
					$nc(this->mv)->visitJumpInsn($Opcodes::IF_ACMPNE, label);
					return;
				} else {
					$throwNew($IllegalArgumentException, $$str({"Bad comparison for type "_s, type}));
				}
			}
		default:
			{
				intOp = -1;
				switch (mode) {
				case GeneratorAdapter::EQ:
					{
						intOp = $Opcodes::IF_ICMPEQ;
						break;
					}
				case GeneratorAdapter::NE:
					{
						intOp = $Opcodes::IF_ICMPNE;
						break;
					}
				case GeneratorAdapter::GE:
					{
						intOp = $Opcodes::IF_ICMPGE;
						break;
					}
				case GeneratorAdapter::LT:
					{
						intOp = $Opcodes::IF_ICMPLT;
						break;
					}
				case GeneratorAdapter::LE:
					{
						intOp = $Opcodes::IF_ICMPLE;
						break;
					}
				case GeneratorAdapter::GT:
					{
						intOp = $Opcodes::IF_ICMPGT;
						break;
					}
				default:
					{
						$throwNew($IllegalArgumentException, $$str({"Bad comparison mode "_s, $$str(mode)}));
					}
				}
				$nc(this->mv)->visitJumpInsn(intOp, label);
				return;
			}
		}
	}
	$nc(this->mv)->visitJumpInsn(mode, label);
}

void GeneratorAdapter::ifICmp(int32_t mode, $Label* label) {
	$init($Type);
	ifCmp($Type::INT_TYPE, mode, label);
}

void GeneratorAdapter::ifZCmp(int32_t mode, $Label* label) {
	$nc(this->mv)->visitJumpInsn(mode, label);
}

void GeneratorAdapter::ifNull($Label* label) {
	$nc(this->mv)->visitJumpInsn($Opcodes::IFNULL, label);
}

void GeneratorAdapter::ifNonNull($Label* label) {
	$nc(this->mv)->visitJumpInsn($Opcodes::IFNONNULL, label);
}

void GeneratorAdapter::goTo($Label* label) {
	$nc(this->mv)->visitJumpInsn($Opcodes::GOTO, label);
}

void GeneratorAdapter::ret(int32_t local) {
	$nc(this->mv)->visitVarInsn($Opcodes::RET, local);
}

void GeneratorAdapter::tableSwitch($ints* keys, $TableSwitchGenerator* generator) {
	float density = 0.0;
	if ($nc(keys)->length == 0) {
		density = (float)0;
	} else {
		density = (float)keys->length / (keys->get(keys->length - 1) - keys->get(0) + 1);
	}
	tableSwitch(keys, generator, density >= 0.5f);
}

void GeneratorAdapter::tableSwitch($ints* keys, $TableSwitchGenerator* generator, bool useTable) {
	$useLocalCurrentObjectStackCache();
	for (int32_t i = 1; i < $nc(keys)->length; ++i) {
		if (keys->get(i) < keys->get(i - 1)) {
			$throwNew($IllegalArgumentException, "keys must be sorted in ascending order"_s);
		}
	}
	$var($Label, defaultLabel, newLabel());
	$var($Label, endLabel, newLabel());
	if ($nc(keys)->length > 0) {
		int32_t numKeys = keys->length;
		if (useTable) {
			int32_t min = keys->get(0);
			int32_t max = keys->get(numKeys - 1);
			int32_t range = max - min + 1;
			$var($LabelArray, labels, $new($LabelArray, range));
			$Arrays::fill(labels, $of(defaultLabel));
			for (int32_t i = 0; i < numKeys; ++i) {
				labels->set(keys->get(i) - min, $(newLabel()));
			}
			$nc(this->mv)->visitTableSwitchInsn(min, max, defaultLabel, labels);
			for (int32_t i = 0; i < range; ++i) {
				$var($Label, label, labels->get(i));
				if (label != defaultLabel) {
					mark(label);
					$nc(generator)->generateCase(i + min, endLabel);
				}
			}
		} else {
			$var($LabelArray, labels, $new($LabelArray, numKeys));
			for (int32_t i = 0; i < numKeys; ++i) {
				labels->set(i, $(newLabel()));
			}
			$nc(this->mv)->visitLookupSwitchInsn(defaultLabel, keys, labels);
			for (int32_t i = 0; i < numKeys; ++i) {
				mark(labels->get(i));
				$nc(generator)->generateCase(keys->get(i), endLabel);
			}
		}
	}
	mark(defaultLabel);
	$nc(generator)->generateDefault();
	mark(endLabel);
}

void GeneratorAdapter::returnValue() {
	$nc(this->mv)->visitInsn($nc(this->returnType)->getOpcode($Opcodes::IRETURN));
}

void GeneratorAdapter::fieldInsn(int32_t opcode, $Type* ownerType, $String* name, $Type* fieldType) {
	$useLocalCurrentObjectStackCache();
	int32_t var$0 = opcode;
	$var($String, var$1, $nc(ownerType)->getInternalName());
	$var($String, var$2, name);
	$nc(this->mv)->visitFieldInsn(var$0, var$1, var$2, $($nc(fieldType)->getDescriptor()));
}

void GeneratorAdapter::getStatic($Type* owner, $String* name, $Type* type) {
	fieldInsn($Opcodes::GETSTATIC, owner, name, type);
}

void GeneratorAdapter::putStatic($Type* owner, $String* name, $Type* type) {
	fieldInsn($Opcodes::PUTSTATIC, owner, name, type);
}

void GeneratorAdapter::getField($Type* owner, $String* name, $Type* type) {
	fieldInsn($Opcodes::GETFIELD, owner, name, type);
}

void GeneratorAdapter::putField($Type* owner, $String* name, $Type* type) {
	fieldInsn($Opcodes::PUTFIELD, owner, name, type);
}

void GeneratorAdapter::invokeInsn(int32_t opcode, $Type* type, $Method* method, bool isInterface) {
	$useLocalCurrentObjectStackCache();
	$var($String, owner, $nc(type)->getSort() == $Type::ARRAY ? $nc(type)->getDescriptor() : type->getInternalName());
	int32_t var$0 = opcode;
	$var($String, var$1, owner);
	$var($String, var$2, $nc(method)->getName());
	$nc(this->mv)->visitMethodInsn(var$0, var$1, var$2, $(method->getDescriptor()), isInterface);
}

void GeneratorAdapter::invokeVirtual($Type* owner, $Method* method) {
	invokeInsn($Opcodes::INVOKEVIRTUAL, owner, method, false);
}

void GeneratorAdapter::invokeConstructor($Type* type, $Method* method) {
	invokeInsn($Opcodes::INVOKESPECIAL, type, method, false);
}

void GeneratorAdapter::invokeStatic($Type* owner, $Method* method) {
	invokeInsn($Opcodes::INVOKESTATIC, owner, method, false);
}

void GeneratorAdapter::invokeInterface($Type* owner, $Method* method) {
	invokeInsn($Opcodes::INVOKEINTERFACE, owner, method, true);
}

void GeneratorAdapter::invokeDynamic($String* name, $String* descriptor, $Handle* bootstrapMethodHandle, $ObjectArray* bootstrapMethodArguments) {
	$nc(this->mv)->visitInvokeDynamicInsn(name, descriptor, bootstrapMethodHandle, bootstrapMethodArguments);
}

void GeneratorAdapter::typeInsn(int32_t opcode, $Type* type) {
	$nc(this->mv)->visitTypeInsn(opcode, $($nc(type)->getInternalName()));
}

void GeneratorAdapter::newInstance($Type* type) {
	typeInsn($Opcodes::NEW, type);
}

void GeneratorAdapter::newArray($Type* type) {
	$InstructionAdapter::newarray(this->mv, type);
}

void GeneratorAdapter::arrayLength() {
	$nc(this->mv)->visitInsn($Opcodes::ARRAYLENGTH);
}

void GeneratorAdapter::throwException() {
	$nc(this->mv)->visitInsn($Opcodes::ATHROW);
}

void GeneratorAdapter::throwException($Type* type, $String* message) {
	newInstance(type);
	dup();
	push(message);
	invokeConstructor(type, $($Method::getMethod("void <init> (String)"_s)));
	throwException();
}

void GeneratorAdapter::checkCast($Type* type) {
	if (!$nc(type)->equals(GeneratorAdapter::OBJECT_TYPE)) {
		typeInsn($Opcodes::CHECKCAST, type);
	}
}

void GeneratorAdapter::instanceOf($Type* type) {
	typeInsn($Opcodes::INSTANCEOF, type);
}

void GeneratorAdapter::monitorEnter() {
	$nc(this->mv)->visitInsn($Opcodes::MONITORENTER);
}

void GeneratorAdapter::monitorExit() {
	$nc(this->mv)->visitInsn($Opcodes::MONITOREXIT);
}

void GeneratorAdapter::endMethod() {
	if (((int32_t)(this->access & (uint32_t)$Opcodes::ACC_ABSTRACT)) == 0) {
		$nc(this->mv)->visitMaxs(0, 0);
	}
	$nc(this->mv)->visitEnd();
}

void GeneratorAdapter::catchException($Label* start, $Label* end, $Type* exception) {
	$useLocalCurrentObjectStackCache();
	$var($Label, catchLabel, $new($Label));
	if (exception == nullptr) {
		$nc(this->mv)->visitTryCatchBlock(start, end, catchLabel, nullptr);
	} else {
		$nc(this->mv)->visitTryCatchBlock(start, end, catchLabel, $($nc(exception)->getInternalName()));
	}
	mark(catchLabel);
}

void clinit$GeneratorAdapter($Class* class$) {
	$assignStatic(GeneratorAdapter::CLASS_DESCRIPTOR, "Ljava/lang/Class;"_s);
	$assignStatic(GeneratorAdapter::BYTE_TYPE, $Type::getObjectType("java/lang/Byte"_s));
	$assignStatic(GeneratorAdapter::BOOLEAN_TYPE, $Type::getObjectType("java/lang/Boolean"_s));
	$assignStatic(GeneratorAdapter::SHORT_TYPE, $Type::getObjectType("java/lang/Short"_s));
	$assignStatic(GeneratorAdapter::CHARACTER_TYPE, $Type::getObjectType("java/lang/Character"_s));
	$assignStatic(GeneratorAdapter::INTEGER_TYPE, $Type::getObjectType("java/lang/Integer"_s));
	$assignStatic(GeneratorAdapter::FLOAT_TYPE, $Type::getObjectType("java/lang/Float"_s));
	$assignStatic(GeneratorAdapter::LONG_TYPE, $Type::getObjectType("java/lang/Long"_s));
	$assignStatic(GeneratorAdapter::DOUBLE_TYPE, $Type::getObjectType("java/lang/Double"_s));
	$assignStatic(GeneratorAdapter::NUMBER_TYPE, $Type::getObjectType("java/lang/Number"_s));
	$assignStatic(GeneratorAdapter::OBJECT_TYPE, $Type::getObjectType("java/lang/Object"_s));
	$assignStatic(GeneratorAdapter::BOOLEAN_VALUE, $Method::getMethod("boolean booleanValue()"_s));
	$assignStatic(GeneratorAdapter::CHAR_VALUE, $Method::getMethod("char charValue()"_s));
	$assignStatic(GeneratorAdapter::INT_VALUE, $Method::getMethod("int intValue()"_s));
	$assignStatic(GeneratorAdapter::FLOAT_VALUE, $Method::getMethod("float floatValue()"_s));
	$assignStatic(GeneratorAdapter::LONG_VALUE, $Method::getMethod("long longValue()"_s));
	$assignStatic(GeneratorAdapter::DOUBLE_VALUE, $Method::getMethod("double doubleValue()"_s));
}

GeneratorAdapter::GeneratorAdapter() {
}

$Class* GeneratorAdapter::load$($String* name, bool initialize) {
	$loadClass(GeneratorAdapter, name, initialize, &_GeneratorAdapter_ClassInfo_, clinit$GeneratorAdapter, allocate$GeneratorAdapter);
	return class$;
}

$Class* GeneratorAdapter::class$ = nullptr;

					} // commons
				} // asm$
			} // objectweb
		} // org
	} // internal
} // jdk