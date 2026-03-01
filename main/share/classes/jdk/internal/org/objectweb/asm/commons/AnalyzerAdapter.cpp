#include <jdk/internal/org/objectweb/asm/commons/AnalyzerAdapter.h>

#include <java/lang/AssertionError.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/Math.h>
#include <java/util/ArrayList.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <jdk/internal/org/objectweb/asm/ConstantDynamic.h>
#include <jdk/internal/org/objectweb/asm/Handle.h>
#include <jdk/internal/org/objectweb/asm/Label.h>
#include <jdk/internal/org/objectweb/asm/MethodVisitor.h>
#include <jdk/internal/org/objectweb/asm/Opcodes.h>
#include <jdk/internal/org/objectweb/asm/Type.h>
#include <jcpp.h>

#undef AALOAD
#undef AASTORE
#undef ACC_STATIC
#undef ACONST_NULL
#undef ALOAD
#undef ANEWARRAY
#undef ARETURN
#undef ARRAY
#undef ARRAYLENGTH
#undef ASM5
#undef ASM8
#undef ASTORE
#undef ATHROW
#undef BALOAD
#undef BASTORE
#undef BIPUSH
#undef BOOLEAN
#undef BYTE
#undef CALOAD
#undef CASTORE
#undef CHAR
#undef CHECKCAST
#undef D2F
#undef D2I
#undef D2L
#undef DADD
#undef DALOAD
#undef DASTORE
#undef DCMPG
#undef DCMPL
#undef DCONST_0
#undef DCONST_1
#undef DDIV
#undef DLOAD
#undef DMUL
#undef DNEG
#undef DOUBLE
#undef DREM
#undef DRETURN
#undef DSTORE
#undef DSUB
#undef DUP
#undef DUP2
#undef DUP2_X1
#undef DUP2_X2
#undef DUP_X1
#undef DUP_X2
#undef F2D
#undef F2I
#undef F2L
#undef FADD
#undef FALOAD
#undef FASTORE
#undef FCMPG
#undef FCMPL
#undef FCONST_0
#undef FCONST_1
#undef FCONST_2
#undef FDIV
#undef FLOAD
#undef FLOAT
#undef FMUL
#undef FNEG
#undef FREM
#undef FRETURN
#undef FSTORE
#undef FSUB
#undef F_NEW
#undef GETFIELD
#undef GETSTATIC
#undef GOTO
#undef I2B
#undef I2C
#undef I2D
#undef I2F
#undef I2L
#undef I2S
#undef IADD
#undef IALOAD
#undef IAND
#undef IASTORE
#undef ICONST_0
#undef ICONST_1
#undef ICONST_2
#undef ICONST_3
#undef ICONST_4
#undef ICONST_5
#undef ICONST_M1
#undef IDIV
#undef IFEQ
#undef IFGE
#undef IFGT
#undef IFLE
#undef IFLT
#undef IFNE
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
#undef IINC
#undef ILOAD
#undef IMUL
#undef INEG
#undef INSTANCEOF
#undef INT
#undef INTEGER
#undef INVOKESPECIAL
#undef INVOKESTATIC
#undef IOR
#undef IREM
#undef IRETURN
#undef ISHL
#undef ISHR
#undef ISTORE
#undef ISUB
#undef IUSHR
#undef IXOR
#undef JSR
#undef L2D
#undef L2F
#undef L2I
#undef LADD
#undef LALOAD
#undef LAND
#undef LASTORE
#undef LCMP
#undef LCONST_0
#undef LCONST_1
#undef LDIV
#undef LLOAD
#undef LMUL
#undef LNEG
#undef LONG
#undef LOOKUPSWITCH
#undef LOR
#undef LREM
#undef LRETURN
#undef LSHL
#undef LSHR
#undef LSTORE
#undef LSUB
#undef LUSHR
#undef LXOR
#undef METHOD
#undef MONITORENTER
#undef MONITOREXIT
#undef MULTIANEWARRAY
#undef NEW
#undef NEWARRAY
#undef NOP
#undef NULL
#undef OBJECT
#undef POP
#undef POP2
#undef PUTFIELD
#undef PUTSTATIC
#undef RET
#undef RETURN
#undef SALOAD
#undef SASTORE
#undef SHORT
#undef SIPUSH
#undef SOURCE_DEPRECATED
#undef SOURCE_MASK
#undef SWAP
#undef TABLESWITCH
#undef TOP
#undef T_BOOLEAN
#undef T_BYTE
#undef T_CHAR
#undef T_DOUBLE
#undef T_FLOAT
#undef T_INT
#undef T_LONG
#undef T_SHORT
#undef UNINITIALIZED_THIS

using $LabelArray = $Array<::jdk::internal::org::objectweb::asm$::Label>;
using $TypeArray = $Array<::jdk::internal::org::objectweb::asm$::Type>;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $Double = ::java::lang::Double;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $ArrayList = ::java::util::ArrayList;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $ConstantDynamic = ::jdk::internal::org::objectweb::asm$::ConstantDynamic;
using $Handle = ::jdk::internal::org::objectweb::asm$::Handle;
using $Label = ::jdk::internal::org::objectweb::asm$::Label;
using $MethodVisitor = ::jdk::internal::org::objectweb::asm$::MethodVisitor;
using $Opcodes = ::jdk::internal::org::objectweb::asm$::Opcodes;
using $Type = ::jdk::internal::org::objectweb::asm$::Type;

namespace jdk {
	namespace internal {
		namespace org {
			namespace objectweb {
				namespace asm$ {
					namespace commons {

$FieldInfo _AnalyzerAdapter_FieldInfo_[] = {
	{"locals", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/Object;>;", $PUBLIC, $field(AnalyzerAdapter, locals)},
	{"stack", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/Object;>;", $PUBLIC, $field(AnalyzerAdapter, stack)},
	{"labels", "Ljava/util/List;", "Ljava/util/List<Ljdk/internal/org/objectweb/asm/Label;>;", $PRIVATE, $field(AnalyzerAdapter, labels)},
	{"uninitializedTypes", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/Object;Ljava/lang/Object;>;", $PUBLIC, $field(AnalyzerAdapter, uninitializedTypes)},
	{"maxStack", "I", nullptr, $PRIVATE, $field(AnalyzerAdapter, maxStack)},
	{"maxLocals", "I", nullptr, $PRIVATE, $field(AnalyzerAdapter, maxLocals)},
	{"owner", "Ljava/lang/String;", nullptr, $PRIVATE, $field(AnalyzerAdapter, owner)},
	{}
};

$MethodInfo _AnalyzerAdapter_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;ILjava/lang/String;Ljava/lang/String;Ljdk/internal/org/objectweb/asm/MethodVisitor;)V", nullptr, $PUBLIC, $method(AnalyzerAdapter, init$, void, $String*, int32_t, $String*, $String*, $MethodVisitor*)},
	{"<init>", "(ILjava/lang/String;ILjava/lang/String;Ljava/lang/String;Ljdk/internal/org/objectweb/asm/MethodVisitor;)V", nullptr, $PROTECTED, $method(AnalyzerAdapter, init$, void, int32_t, $String*, int32_t, $String*, $String*, $MethodVisitor*)},
	{"execute", "(IILjava/lang/String;)V", nullptr, $PRIVATE, $method(AnalyzerAdapter, execute, void, int32_t, int32_t, $String*)},
	{"get", "(I)Ljava/lang/Object;", nullptr, $PRIVATE, $method(AnalyzerAdapter, get, $Object*, int32_t)},
	{"pop", "()Ljava/lang/Object;", nullptr, $PRIVATE, $method(AnalyzerAdapter, pop, $Object*)},
	{"pop", "(I)V", nullptr, $PRIVATE, $method(AnalyzerAdapter, pop, void, int32_t)},
	{"pop", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(AnalyzerAdapter, pop, void, $String*)},
	{"push", "(Ljava/lang/Object;)V", nullptr, $PRIVATE, $method(AnalyzerAdapter, push, void, Object$*)},
	{"pushDescriptor", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(AnalyzerAdapter, pushDescriptor, void, $String*)},
	{"set", "(ILjava/lang/Object;)V", nullptr, $PRIVATE, $method(AnalyzerAdapter, set, void, int32_t, Object$*)},
	{"visitFieldInsn", "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(AnalyzerAdapter, visitFieldInsn, void, int32_t, $String*, $String*, $String*)},
	{"visitFrame", "(II[Ljava/lang/Object;I[Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(AnalyzerAdapter, visitFrame, void, int32_t, int32_t, $ObjectArray*, int32_t, $ObjectArray*)},
	{"visitFrameTypes", "(I[Ljava/lang/Object;Ljava/util/List;)V", "(I[Ljava/lang/Object;Ljava/util/List<Ljava/lang/Object;>;)V", $PRIVATE | $STATIC, $staticMethod(AnalyzerAdapter, visitFrameTypes, void, int32_t, $ObjectArray*, $List*)},
	{"visitIincInsn", "(II)V", nullptr, $PUBLIC, $virtualMethod(AnalyzerAdapter, visitIincInsn, void, int32_t, int32_t)},
	{"visitInsn", "(I)V", nullptr, $PUBLIC, $virtualMethod(AnalyzerAdapter, visitInsn, void, int32_t)},
	{"visitIntInsn", "(II)V", nullptr, $PUBLIC, $virtualMethod(AnalyzerAdapter, visitIntInsn, void, int32_t, int32_t)},
	{"visitInvokeDynamicInsn", "(Ljava/lang/String;Ljava/lang/String;Ljdk/internal/org/objectweb/asm/Handle;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(AnalyzerAdapter, visitInvokeDynamicInsn, void, $String*, $String*, $Handle*, $ObjectArray*)},
	{"visitJumpInsn", "(ILjdk/internal/org/objectweb/asm/Label;)V", nullptr, $PUBLIC, $virtualMethod(AnalyzerAdapter, visitJumpInsn, void, int32_t, $Label*)},
	{"visitLabel", "(Ljdk/internal/org/objectweb/asm/Label;)V", nullptr, $PUBLIC, $virtualMethod(AnalyzerAdapter, visitLabel, void, $Label*)},
	{"visitLdcInsn", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(AnalyzerAdapter, visitLdcInsn, void, Object$*)},
	{"visitLocalVariable", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljdk/internal/org/objectweb/asm/Label;Ljdk/internal/org/objectweb/asm/Label;I)V", nullptr, $PUBLIC, $virtualMethod(AnalyzerAdapter, visitLocalVariable, void, $String*, $String*, $String*, $Label*, $Label*, int32_t)},
	{"visitLookupSwitchInsn", "(Ljdk/internal/org/objectweb/asm/Label;[I[Ljdk/internal/org/objectweb/asm/Label;)V", nullptr, $PUBLIC, $virtualMethod(AnalyzerAdapter, visitLookupSwitchInsn, void, $Label*, $ints*, $LabelArray*)},
	{"visitMaxs", "(II)V", nullptr, $PUBLIC, $virtualMethod(AnalyzerAdapter, visitMaxs, void, int32_t, int32_t)},
	{"visitMethodInsn", "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Z)V", nullptr, $PUBLIC, $virtualMethod(AnalyzerAdapter, visitMethodInsn, void, int32_t, $String*, $String*, $String*, bool)},
	{"visitMultiANewArrayInsn", "(Ljava/lang/String;I)V", nullptr, $PUBLIC, $virtualMethod(AnalyzerAdapter, visitMultiANewArrayInsn, void, $String*, int32_t)},
	{"visitTableSwitchInsn", "(IILjdk/internal/org/objectweb/asm/Label;[Ljdk/internal/org/objectweb/asm/Label;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(AnalyzerAdapter, visitTableSwitchInsn, void, int32_t, int32_t, $Label*, $LabelArray*)},
	{"visitTypeInsn", "(ILjava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(AnalyzerAdapter, visitTypeInsn, void, int32_t, $String*)},
	{"visitVarInsn", "(II)V", nullptr, $PUBLIC, $virtualMethod(AnalyzerAdapter, visitVarInsn, void, int32_t, int32_t)},
	{}
};

$ClassInfo _AnalyzerAdapter_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.org.objectweb.asm.commons.AnalyzerAdapter",
	"jdk.internal.org.objectweb.asm.MethodVisitor",
	nullptr,
	_AnalyzerAdapter_FieldInfo_,
	_AnalyzerAdapter_MethodInfo_
};

$Object* allocate$AnalyzerAdapter($Class* clazz) {
	return $of($alloc(AnalyzerAdapter));
}

void AnalyzerAdapter::init$($String* owner, int32_t access, $String* name, $String* descriptor, $MethodVisitor* methodVisitor) {
	AnalyzerAdapter::init$($Opcodes::ASM8, owner, access, name, descriptor, methodVisitor);
	if ($of(this)->getClass() != AnalyzerAdapter::class$) {
		$throwNew($IllegalStateException);
	}
}

void AnalyzerAdapter::init$(int32_t api, $String* owner, int32_t access, $String* name, $String* descriptor, $MethodVisitor* methodVisitor) {
	$useLocalCurrentObjectStackCache();
	$MethodVisitor::init$(api, methodVisitor);
	$set(this, owner, owner);
	$set(this, locals, $new($ArrayList));
	$set(this, stack, $new($ArrayList));
	$set(this, uninitializedTypes, $new($HashMap));
	if (((int32_t)(access & (uint32_t)$Opcodes::ACC_STATIC)) == 0) {
		if ("<init>"_s->equals(name)) {
			$init($Opcodes);
			$nc(this->locals)->add($Opcodes::UNINITIALIZED_THIS);
		} else {
			$nc(this->locals)->add(owner);
		}
	}
	{
		$var($TypeArray, arr$, $Type::getArgumentTypes(descriptor));
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Type, argumentType, arr$->get(i$));
			{
				switch ($nc(argumentType)->getSort()) {
				case $Type::BOOLEAN:
					{}
				case $Type::CHAR:
					{}
				case $Type::BYTE:
					{}
				case $Type::SHORT:
					{}
				case $Type::INT:
					{
						$init($Opcodes);
						$nc(this->locals)->add($Opcodes::INTEGER);
						break;
					}
				case $Type::FLOAT:
					{
						$init($Opcodes);
						$nc(this->locals)->add($Opcodes::FLOAT);
						break;
					}
				case $Type::LONG:
					{
						$init($Opcodes);
						$nc(this->locals)->add($Opcodes::LONG);
						$init($Opcodes);
						$nc(this->locals)->add($Opcodes::TOP);
						break;
					}
				case $Type::DOUBLE:
					{
						$init($Opcodes);
						$nc(this->locals)->add($Opcodes::DOUBLE);
						$init($Opcodes);
						$nc(this->locals)->add($Opcodes::TOP);
						break;
					}
				case $Type::ARRAY:
					{
						$nc(this->locals)->add($(argumentType->getDescriptor()));
						break;
					}
				case $Type::OBJECT:
					{
						$nc(this->locals)->add($(argumentType->getInternalName()));
						break;
					}
				default:
					{
						$throwNew($AssertionError);
					}
				}
			}
		}
	}
	this->maxLocals = $nc(this->locals)->size();
}

void AnalyzerAdapter::visitFrame(int32_t type, int32_t numLocal, $ObjectArray* local, int32_t numStack, $ObjectArray* stack) {
	if (type != $Opcodes::F_NEW) {
		$throwNew($IllegalArgumentException, "AnalyzerAdapter only accepts expanded frames (see ClassReader.EXPAND_FRAMES)"_s);
	}
	$MethodVisitor::visitFrame(type, numLocal, local, numStack, stack);
	if (this->locals != nullptr) {
		$nc(this->locals)->clear();
		$nc(this->stack)->clear();
	} else {
		$set(this, locals, $new($ArrayList));
		$set(this, stack, $new($ArrayList));
	}
	visitFrameTypes(numLocal, local, this->locals);
	visitFrameTypes(numStack, stack, this->stack);
	this->maxLocals = $Math::max(this->maxLocals, $nc(this->locals)->size());
	this->maxStack = $Math::max(this->maxStack, $nc(this->stack)->size());
}

void AnalyzerAdapter::visitFrameTypes(int32_t numTypes, $ObjectArray* frameTypes, $List* result) {
	$init(AnalyzerAdapter);
	$useLocalCurrentObjectStackCache();
	for (int32_t i = 0; i < numTypes; ++i) {
		$var($Object0, frameType, $nc(frameTypes)->get(i));
		$nc(result)->add(frameType);
		$init($Opcodes);
		if ($equals(frameType, $Opcodes::LONG) || $equals(frameType, $Opcodes::DOUBLE)) {
			result->add($Opcodes::TOP);
		}
	}
}

void AnalyzerAdapter::visitInsn(int32_t opcode) {
	$MethodVisitor::visitInsn(opcode);
	execute(opcode, 0, nullptr);
	if ((opcode >= $Opcodes::IRETURN && opcode <= $Opcodes::RETURN) || opcode == $Opcodes::ATHROW) {
		$set(this, locals, nullptr);
		$set(this, stack, nullptr);
	}
}

void AnalyzerAdapter::visitIntInsn(int32_t opcode, int32_t operand) {
	$MethodVisitor::visitIntInsn(opcode, operand);
	execute(opcode, operand, nullptr);
}

void AnalyzerAdapter::visitVarInsn(int32_t opcode, int32_t var) {
	$MethodVisitor::visitVarInsn(opcode, var);
	bool isLongOrDouble = opcode == $Opcodes::LLOAD || opcode == $Opcodes::DLOAD || opcode == $Opcodes::LSTORE || opcode == $Opcodes::DSTORE;
	this->maxLocals = $Math::max(this->maxLocals, var + (isLongOrDouble ? 2 : 1));
	execute(opcode, var, nullptr);
}

void AnalyzerAdapter::visitTypeInsn(int32_t opcode, $String* type) {
	$useLocalCurrentObjectStackCache();
	if (opcode == $Opcodes::NEW) {
		if (this->labels == nullptr) {
			$var($Label, label, $new($Label));
			$set(this, labels, $new($ArrayList, 3));
			$nc(this->labels)->add(label);
			if (this->mv != nullptr) {
				$nc(this->mv)->visitLabel(label);
			}
		}
		{
			$var($Iterator, i$, $nc(this->labels)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Label, label, $cast($Label, i$->next()));
				{
					$nc(this->uninitializedTypes)->put(label, type);
				}
			}
		}
	}
	$MethodVisitor::visitTypeInsn(opcode, type);
	execute(opcode, 0, type);
}

void AnalyzerAdapter::visitFieldInsn(int32_t opcode, $String* owner, $String* name, $String* descriptor) {
	$MethodVisitor::visitFieldInsn(opcode, owner, name, descriptor);
	execute(opcode, 0, descriptor);
}

void AnalyzerAdapter::visitMethodInsn(int32_t opcodeAndSource, $String* owner, $String* name, $String* descriptor, bool isInterface) {
	$useLocalCurrentObjectStackCache();
	if (this->api < $Opcodes::ASM5 && ((int32_t)(opcodeAndSource & (uint32_t)$Opcodes::SOURCE_DEPRECATED)) == 0) {
		$MethodVisitor::visitMethodInsn(opcodeAndSource, owner, name, descriptor, isInterface);
		return;
	}
	$MethodVisitor::visitMethodInsn(opcodeAndSource, owner, name, descriptor, isInterface);
	int32_t opcode = (int32_t)(opcodeAndSource & (uint32_t)~$Opcodes::SOURCE_MASK);
	if (this->locals == nullptr) {
		$set(this, labels, nullptr);
		return;
	}
	pop(descriptor);
	if (opcode != $Opcodes::INVOKESTATIC) {
		$var($Object, value, pop());
		if (opcode == $Opcodes::INVOKESPECIAL && $nc(name)->equals("<init>"_s)) {
			$var($Object, initializedValue, nullptr);
			$init($Opcodes);
			if ($equals(value, $Opcodes::UNINITIALIZED_THIS)) {
				$assign(initializedValue, this->owner);
			} else {
				$assign(initializedValue, $nc(this->uninitializedTypes)->get(value));
			}
			for (int32_t i = 0; i < $nc(this->locals)->size(); ++i) {
				if ($equals($nc(this->locals)->get(i), value)) {
					$nc(this->locals)->set(i, initializedValue);
				}
			}
			for (int32_t i = 0; i < $nc(this->stack)->size(); ++i) {
				if ($equals($nc(this->stack)->get(i), value)) {
					$nc(this->stack)->set(i, initializedValue);
				}
			}
		}
	}
	pushDescriptor(descriptor);
	$set(this, labels, nullptr);
}

void AnalyzerAdapter::visitInvokeDynamicInsn($String* name, $String* descriptor, $Handle* bootstrapMethodHandle, $ObjectArray* bootstrapMethodArguments) {
	$MethodVisitor::visitInvokeDynamicInsn(name, descriptor, bootstrapMethodHandle, bootstrapMethodArguments);
	if (this->locals == nullptr) {
		$set(this, labels, nullptr);
		return;
	}
	pop(descriptor);
	pushDescriptor(descriptor);
	$set(this, labels, nullptr);
}

void AnalyzerAdapter::visitJumpInsn(int32_t opcode, $Label* label) {
	$MethodVisitor::visitJumpInsn(opcode, label);
	execute(opcode, 0, nullptr);
	if (opcode == $Opcodes::GOTO) {
		$set(this, locals, nullptr);
		$set(this, stack, nullptr);
	}
}

void AnalyzerAdapter::visitLabel($Label* label) {
	$MethodVisitor::visitLabel(label);
	if (this->labels == nullptr) {
		$set(this, labels, $new($ArrayList, 3));
	}
	$nc(this->labels)->add(label);
}

void AnalyzerAdapter::visitLdcInsn(Object$* value) {
	$MethodVisitor::visitLdcInsn(value);
	if (this->locals == nullptr) {
		$set(this, labels, nullptr);
		return;
	}
	if ($instanceOf($Integer, value)) {
		$init($Opcodes);
		push($Opcodes::INTEGER);
	} else if ($instanceOf($Long, value)) {
		$init($Opcodes);
		push($Opcodes::LONG);
		push($Opcodes::TOP);
	} else if ($instanceOf($Float, value)) {
		$init($Opcodes);
		push($Opcodes::FLOAT);
	} else if ($instanceOf($Double, value)) {
		$init($Opcodes);
		push($Opcodes::DOUBLE);
		push($Opcodes::TOP);
	} else if ($instanceOf($String, value)) {
		push("java/lang/String"_s);
	} else if ($instanceOf($Type, value)) {
		int32_t sort = $nc(($cast($Type, value)))->getSort();
		if (sort == $Type::OBJECT || sort == $Type::ARRAY) {
			push("java/lang/Class"_s);
		} else if (sort == $Type::METHOD) {
			push("java/lang/invoke/MethodType"_s);
		} else {
			$throwNew($IllegalArgumentException);
		}
	} else if ($instanceOf($Handle, value)) {
		push("java/lang/invoke/MethodHandle"_s);
	} else if ($instanceOf($ConstantDynamic, value)) {
		pushDescriptor($($nc(($cast($ConstantDynamic, value)))->getDescriptor()));
	} else {
		$throwNew($IllegalArgumentException);
	}
	$set(this, labels, nullptr);
}

void AnalyzerAdapter::visitIincInsn(int32_t var, int32_t increment) {
	$MethodVisitor::visitIincInsn(var, increment);
	this->maxLocals = $Math::max(this->maxLocals, var + 1);
	execute($Opcodes::IINC, var, nullptr);
}

void AnalyzerAdapter::visitTableSwitchInsn(int32_t min, int32_t max, $Label* dflt, $LabelArray* labels) {
	$MethodVisitor::visitTableSwitchInsn(min, max, dflt, labels);
	execute($Opcodes::TABLESWITCH, 0, nullptr);
	$set(this, locals, nullptr);
	$set(this, stack, nullptr);
}

void AnalyzerAdapter::visitLookupSwitchInsn($Label* dflt, $ints* keys, $LabelArray* labels) {
	$MethodVisitor::visitLookupSwitchInsn(dflt, keys, labels);
	execute($Opcodes::LOOKUPSWITCH, 0, nullptr);
	$set(this, locals, nullptr);
	$set(this, stack, nullptr);
}

void AnalyzerAdapter::visitMultiANewArrayInsn($String* descriptor, int32_t numDimensions) {
	$MethodVisitor::visitMultiANewArrayInsn(descriptor, numDimensions);
	execute($Opcodes::MULTIANEWARRAY, numDimensions, descriptor);
}

void AnalyzerAdapter::visitLocalVariable($String* name, $String* descriptor, $String* signature, $Label* start, $Label* end, int32_t index) {
	char16_t firstDescriptorChar = $nc(descriptor)->charAt(0);
	this->maxLocals = $Math::max(this->maxLocals, index + (firstDescriptorChar == u'J' || firstDescriptorChar == u'D' ? 2 : 1));
	$MethodVisitor::visitLocalVariable(name, descriptor, signature, start, end, index);
}

void AnalyzerAdapter::visitMaxs(int32_t maxStack, int32_t maxLocals) {
	if (this->mv != nullptr) {
		this->maxStack = $Math::max(this->maxStack, maxStack);
		this->maxLocals = $Math::max(this->maxLocals, maxLocals);
		$nc(this->mv)->visitMaxs(this->maxStack, this->maxLocals);
	}
}

$Object* AnalyzerAdapter::get(int32_t local) {
	this->maxLocals = $Math::max(this->maxLocals, local + 1);
	$init($Opcodes);
	return $of(local < $nc(this->locals)->size() ? $nc(this->locals)->get(local) : $of($Opcodes::TOP));
}

void AnalyzerAdapter::set(int32_t local, Object$* type) {
	this->maxLocals = $Math::max(this->maxLocals, local + 1);
	while (local >= $nc(this->locals)->size()) {
		$init($Opcodes);
		$nc(this->locals)->add($Opcodes::TOP);
	}
	$nc(this->locals)->set(local, type);
}

void AnalyzerAdapter::push(Object$* type) {
	$nc(this->stack)->add(type);
	this->maxStack = $Math::max(this->maxStack, $nc(this->stack)->size());
}

void AnalyzerAdapter::pushDescriptor($String* fieldOrMethodDescriptor) {
	$useLocalCurrentObjectStackCache();
	$var($String, descriptor, $nc(fieldOrMethodDescriptor)->charAt(0) == u'(' ? $nc($($Type::getReturnType(fieldOrMethodDescriptor)))->getDescriptor() : fieldOrMethodDescriptor);
	switch ($nc(descriptor)->charAt(0)) {
	case u'V':
		{
			return;
		}
	case u'Z':
		{}
	case u'C':
		{}
	case u'B':
		{}
	case u'S':
		{}
	case u'I':
		{
			$init($Opcodes);
			push($Opcodes::INTEGER);
			return;
		}
	case u'F':
		{
			$init($Opcodes);
			push($Opcodes::FLOAT);
			return;
		}
	case u'J':
		{
			$init($Opcodes);
			push($Opcodes::LONG);
			$init($Opcodes);
			push($Opcodes::TOP);
			return;
		}
	case u'D':
		{
			$init($Opcodes);
			push($Opcodes::DOUBLE);
			$init($Opcodes);
			push($Opcodes::TOP);
			return;
		}
	case u'[':
		{
			push(descriptor);
			break;
		}
	case u'L':
		{
			push($(descriptor->substring(1, descriptor->length() - 1)));
			break;
		}
	default:
		{
			$throwNew($AssertionError);
		}
	}
}

$Object* AnalyzerAdapter::pop() {
	return $of($nc(this->stack)->remove($nc(this->stack)->size() - 1));
}

void AnalyzerAdapter::pop(int32_t numSlots) {
	int32_t size = $nc(this->stack)->size();
	int32_t end = size - numSlots;
	for (int32_t i = size - 1; i >= end; --i) {
		$nc(this->stack)->remove(i);
	}
}

void AnalyzerAdapter::pop($String* descriptor) {
	$useLocalCurrentObjectStackCache();
	char16_t firstDescriptorChar = $nc(descriptor)->charAt(0);
	if (firstDescriptorChar == u'(') {
		int32_t numSlots = 0;
		$var($TypeArray, types, $Type::getArgumentTypes(descriptor));
		{
			$var($TypeArray, arr$, types);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($Type, type, arr$->get(i$));
				{
					numSlots += $nc(type)->getSize();
				}
			}
		}
		pop(numSlots);
	} else if (firstDescriptorChar == u'J' || firstDescriptorChar == u'D') {
		pop(2);
	} else {
		pop(1);
	}
}

void AnalyzerAdapter::execute(int32_t opcode, int32_t intArg, $String* stringArg) {
	$useLocalCurrentObjectStackCache();
	if (opcode == $Opcodes::JSR || opcode == $Opcodes::RET) {
		$throwNew($IllegalArgumentException, "JSR/RET are not supported"_s);
	}
	if (this->locals == nullptr) {
		$set(this, labels, nullptr);
		return;
	}
	$var($Object, value1, nullptr);
	$var($Object, value2, nullptr);
	$var($Object, value3, nullptr);
	$var($Object, t4, nullptr);
	switch (opcode) {
	case $Opcodes::NOP:
		{}
	case $Opcodes::INEG:
		{}
	case $Opcodes::LNEG:
		{}
	case $Opcodes::FNEG:
		{}
	case $Opcodes::DNEG:
		{}
	case $Opcodes::I2B:
		{}
	case $Opcodes::I2C:
		{}
	case $Opcodes::I2S:
		{}
	case $Opcodes::GOTO:
		{}
	case $Opcodes::RETURN:
		{
			break;
		}
	case $Opcodes::ACONST_NULL:
		{
			$init($Opcodes);
			push($Opcodes::NULL);
			break;
		}
	case $Opcodes::ICONST_M1:
		{}
	case $Opcodes::ICONST_0:
		{}
	case $Opcodes::ICONST_1:
		{}
	case $Opcodes::ICONST_2:
		{}
	case $Opcodes::ICONST_3:
		{}
	case $Opcodes::ICONST_4:
		{}
	case $Opcodes::ICONST_5:
		{}
	case $Opcodes::BIPUSH:
		{}
	case $Opcodes::SIPUSH:
		{
			$init($Opcodes);
			push($Opcodes::INTEGER);
			break;
		}
	case $Opcodes::LCONST_0:
		{}
	case $Opcodes::LCONST_1:
		{
			$init($Opcodes);
			push($Opcodes::LONG);
			$init($Opcodes);
			push($Opcodes::TOP);
			break;
		}
	case $Opcodes::FCONST_0:
		{}
	case $Opcodes::FCONST_1:
		{}
	case $Opcodes::FCONST_2:
		{
			$init($Opcodes);
			push($Opcodes::FLOAT);
			break;
		}
	case $Opcodes::DCONST_0:
		{}
	case $Opcodes::DCONST_1:
		{
			$init($Opcodes);
			push($Opcodes::DOUBLE);
			$init($Opcodes);
			push($Opcodes::TOP);
			break;
		}
	case $Opcodes::ILOAD:
		{}
	case $Opcodes::FLOAD:
		{}
	case $Opcodes::ALOAD:
		{
			push($(get(intArg)));
			break;
		}
	case $Opcodes::LLOAD:
		{}
	case $Opcodes::DLOAD:
		{
			push($(get(intArg)));
			$init($Opcodes);
			push($Opcodes::TOP);
			break;
		}
	case $Opcodes::LALOAD:
		{}
	case $Opcodes::D2L:
		{
			pop(2);
			$init($Opcodes);
			push($Opcodes::LONG);
			$init($Opcodes);
			push($Opcodes::TOP);
			break;
		}
	case $Opcodes::DALOAD:
		{}
	case $Opcodes::L2D:
		{
			pop(2);
			$init($Opcodes);
			push($Opcodes::DOUBLE);
			$init($Opcodes);
			push($Opcodes::TOP);
			break;
		}
	case $Opcodes::AALOAD:
		{
			pop(1);
			$assign(value1, pop());
			if ($instanceOf($String, value1)) {
				pushDescriptor($($nc(($cast($String, value1)))->substring(1)));
			} else {
				$init($Opcodes);
				if ($equals(value1, $Opcodes::NULL)) {
					push(value1);
				} else {
					push("java/lang/Object"_s);
				}
			}
			break;
		}
	case $Opcodes::ISTORE:
		{}
	case $Opcodes::FSTORE:
		{}
	case $Opcodes::ASTORE:
		{
			$assign(value1, pop());
			set(intArg, value1);
			if (intArg > 0) {
				$assign(value2, get(intArg - 1));
				$init($Opcodes);
				if ($equals(value2, $Opcodes::LONG) || $equals(value2, $Opcodes::DOUBLE)) {
					set(intArg - 1, $Opcodes::TOP);
				}
			}
			break;
		}
	case $Opcodes::LSTORE:
		{}
	case $Opcodes::DSTORE:
		{
			pop(1);
			$assign(value1, pop());
			set(intArg, value1);
			$init($Opcodes);
			set(intArg + 1, $Opcodes::TOP);
			if (intArg > 0) {
				$assign(value2, get(intArg - 1));
				$init($Opcodes);
				if ($equals(value2, $Opcodes::LONG) || $equals(value2, $Opcodes::DOUBLE)) {
					set(intArg - 1, $Opcodes::TOP);
				}
			}
			break;
		}
	case $Opcodes::IASTORE:
		{}
	case $Opcodes::BASTORE:
		{}
	case $Opcodes::CASTORE:
		{}
	case $Opcodes::SASTORE:
		{}
	case $Opcodes::FASTORE:
		{}
	case $Opcodes::AASTORE:
		{
			pop(3);
			break;
		}
	case $Opcodes::LASTORE:
		{}
	case $Opcodes::DASTORE:
		{
			pop(4);
			break;
		}
	case $Opcodes::POP:
		{}
	case $Opcodes::IFEQ:
		{}
	case $Opcodes::IFNE:
		{}
	case $Opcodes::IFLT:
		{}
	case $Opcodes::IFGE:
		{}
	case $Opcodes::IFGT:
		{}
	case $Opcodes::IFLE:
		{}
	case $Opcodes::IRETURN:
		{}
	case $Opcodes::FRETURN:
		{}
	case $Opcodes::ARETURN:
		{}
	case $Opcodes::TABLESWITCH:
		{}
	case $Opcodes::LOOKUPSWITCH:
		{}
	case $Opcodes::ATHROW:
		{}
	case $Opcodes::MONITORENTER:
		{}
	case $Opcodes::MONITOREXIT:
		{}
	case $Opcodes::IFNULL:
		{}
	case $Opcodes::IFNONNULL:
		{
			pop(1);
			break;
		}
	case $Opcodes::POP2:
		{}
	case $Opcodes::IF_ICMPEQ:
		{}
	case $Opcodes::IF_ICMPNE:
		{}
	case $Opcodes::IF_ICMPLT:
		{}
	case $Opcodes::IF_ICMPGE:
		{}
	case $Opcodes::IF_ICMPGT:
		{}
	case $Opcodes::IF_ICMPLE:
		{}
	case $Opcodes::IF_ACMPEQ:
		{}
	case $Opcodes::IF_ACMPNE:
		{}
	case $Opcodes::LRETURN:
		{}
	case $Opcodes::DRETURN:
		{
			pop(2);
			break;
		}
	case $Opcodes::DUP:
		{
			$assign(value1, pop());
			push(value1);
			push(value1);
			break;
		}
	case $Opcodes::DUP_X1:
		{
			$assign(value1, pop());
			$assign(value2, pop());
			push(value1);
			push(value2);
			push(value1);
			break;
		}
	case $Opcodes::DUP_X2:
		{
			$assign(value1, pop());
			$assign(value2, pop());
			$assign(value3, pop());
			push(value1);
			push(value3);
			push(value2);
			push(value1);
			break;
		}
	case $Opcodes::DUP2:
		{
			$assign(value1, pop());
			$assign(value2, pop());
			push(value2);
			push(value1);
			push(value2);
			push(value1);
			break;
		}
	case $Opcodes::DUP2_X1:
		{
			$assign(value1, pop());
			$assign(value2, pop());
			$assign(value3, pop());
			push(value2);
			push(value1);
			push(value3);
			push(value2);
			push(value1);
			break;
		}
	case $Opcodes::DUP2_X2:
		{
			$assign(value1, pop());
			$assign(value2, pop());
			$assign(value3, pop());
			$assign(t4, pop());
			push(value2);
			push(value1);
			push(t4);
			push(value3);
			push(value2);
			push(value1);
			break;
		}
	case $Opcodes::SWAP:
		{
			$assign(value1, pop());
			$assign(value2, pop());
			push(value1);
			push(value2);
			break;
		}
	case $Opcodes::IALOAD:
		{}
	case $Opcodes::BALOAD:
		{}
	case $Opcodes::CALOAD:
		{}
	case $Opcodes::SALOAD:
		{}
	case $Opcodes::IADD:
		{}
	case $Opcodes::ISUB:
		{}
	case $Opcodes::IMUL:
		{}
	case $Opcodes::IDIV:
		{}
	case $Opcodes::IREM:
		{}
	case $Opcodes::IAND:
		{}
	case $Opcodes::IOR:
		{}
	case $Opcodes::IXOR:
		{}
	case $Opcodes::ISHL:
		{}
	case $Opcodes::ISHR:
		{}
	case $Opcodes::IUSHR:
		{}
	case $Opcodes::L2I:
		{}
	case $Opcodes::D2I:
		{}
	case $Opcodes::FCMPL:
		{}
	case $Opcodes::FCMPG:
		{
			pop(2);
			$init($Opcodes);
			push($Opcodes::INTEGER);
			break;
		}
	case $Opcodes::LADD:
		{}
	case $Opcodes::LSUB:
		{}
	case $Opcodes::LMUL:
		{}
	case $Opcodes::LDIV:
		{}
	case $Opcodes::LREM:
		{}
	case $Opcodes::LAND:
		{}
	case $Opcodes::LOR:
		{}
	case $Opcodes::LXOR:
		{
			pop(4);
			$init($Opcodes);
			push($Opcodes::LONG);
			$init($Opcodes);
			push($Opcodes::TOP);
			break;
		}
	case $Opcodes::FALOAD:
		{}
	case $Opcodes::FADD:
		{}
	case $Opcodes::FSUB:
		{}
	case $Opcodes::FMUL:
		{}
	case $Opcodes::FDIV:
		{}
	case $Opcodes::FREM:
		{}
	case $Opcodes::L2F:
		{}
	case $Opcodes::D2F:
		{
			pop(2);
			$init($Opcodes);
			push($Opcodes::FLOAT);
			break;
		}
	case $Opcodes::DADD:
		{}
	case $Opcodes::DSUB:
		{}
	case $Opcodes::DMUL:
		{}
	case $Opcodes::DDIV:
		{}
	case $Opcodes::DREM:
		{
			pop(4);
			$init($Opcodes);
			push($Opcodes::DOUBLE);
			$init($Opcodes);
			push($Opcodes::TOP);
			break;
		}
	case $Opcodes::LSHL:
		{}
	case $Opcodes::LSHR:
		{}
	case $Opcodes::LUSHR:
		{
			pop(3);
			$init($Opcodes);
			push($Opcodes::LONG);
			$init($Opcodes);
			push($Opcodes::TOP);
			break;
		}
	case $Opcodes::IINC:
		{
			$init($Opcodes);
			set(intArg, $Opcodes::INTEGER);
			break;
		}
	case $Opcodes::I2L:
		{}
	case $Opcodes::F2L:
		{
			pop(1);
			$init($Opcodes);
			push($Opcodes::LONG);
			$init($Opcodes);
			push($Opcodes::TOP);
			break;
		}
	case $Opcodes::I2F:
		{
			pop(1);
			$init($Opcodes);
			push($Opcodes::FLOAT);
			break;
		}
	case $Opcodes::I2D:
		{}
	case $Opcodes::F2D:
		{
			pop(1);
			$init($Opcodes);
			push($Opcodes::DOUBLE);
			$init($Opcodes);
			push($Opcodes::TOP);
			break;
		}
	case $Opcodes::F2I:
		{}
	case $Opcodes::ARRAYLENGTH:
		{}
	case $Opcodes::INSTANCEOF:
		{
			pop(1);
			$init($Opcodes);
			push($Opcodes::INTEGER);
			break;
		}
	case $Opcodes::LCMP:
		{}
	case $Opcodes::DCMPL:
		{}
	case $Opcodes::DCMPG:
		{
			pop(4);
			$init($Opcodes);
			push($Opcodes::INTEGER);
			break;
		}
	case $Opcodes::GETSTATIC:
		{
			pushDescriptor(stringArg);
			break;
		}
	case $Opcodes::PUTSTATIC:
		{
			pop(stringArg);
			break;
		}
	case $Opcodes::GETFIELD:
		{
			pop(1);
			pushDescriptor(stringArg);
			break;
		}
	case $Opcodes::PUTFIELD:
		{
			pop(stringArg);
			pop();
			break;
		}
	case $Opcodes::NEW:
		{
			push($($nc(this->labels)->get(0)));
			break;
		}
	case $Opcodes::NEWARRAY:
		{
			pop();
			switch (intArg) {
			case $Opcodes::T_BOOLEAN:
				{
					pushDescriptor("[Z"_s);
					break;
				}
			case $Opcodes::T_CHAR:
				{
					pushDescriptor("[C"_s);
					break;
				}
			case $Opcodes::T_BYTE:
				{
					pushDescriptor("[B"_s);
					break;
				}
			case $Opcodes::T_SHORT:
				{
					pushDescriptor("[S"_s);
					break;
				}
			case $Opcodes::T_INT:
				{
					pushDescriptor("[I"_s);
					break;
				}
			case $Opcodes::T_FLOAT:
				{
					pushDescriptor("[F"_s);
					break;
				}
			case $Opcodes::T_DOUBLE:
				{
					pushDescriptor("[D"_s);
					break;
				}
			case $Opcodes::T_LONG:
				{
					pushDescriptor("[J"_s);
					break;
				}
			default:
				{
					$throwNew($IllegalArgumentException, $$str({"Invalid array type "_s, $$str(intArg)}));
				}
			}
			break;
		}
	case $Opcodes::ANEWARRAY:
		{
			pop();
			pushDescriptor($$str({"["_s, $($Type::getObjectType(stringArg))}));
			break;
		}
	case $Opcodes::CHECKCAST:
		{
			pop();
			pushDescriptor($($nc($($Type::getObjectType(stringArg)))->getDescriptor()));
			break;
		}
	case $Opcodes::MULTIANEWARRAY:
		{
			pop(intArg);
			pushDescriptor(stringArg);
			break;
		}
	default:
		{
			$throwNew($IllegalArgumentException, $$str({"Invalid opcode "_s, $$str(opcode)}));
		}
	}
	$set(this, labels, nullptr);
}

AnalyzerAdapter::AnalyzerAdapter() {
}

$Class* AnalyzerAdapter::load$($String* name, bool initialize) {
	$loadClass(AnalyzerAdapter, name, initialize, &_AnalyzerAdapter_ClassInfo_, allocate$AnalyzerAdapter);
	return class$;
}

$Class* AnalyzerAdapter::class$ = nullptr;

					} // commons
				} // asm$
			} // objectweb
		} // org
	} // internal
} // jdk