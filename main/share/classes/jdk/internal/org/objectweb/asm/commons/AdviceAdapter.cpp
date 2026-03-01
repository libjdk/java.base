#include <jdk/internal/org/objectweb/asm/commons/AdviceAdapter.h>

#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/HashMap.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <jdk/internal/org/objectweb/asm/ConstantDynamic.h>
#include <jdk/internal/org/objectweb/asm/Handle.h>
#include <jdk/internal/org/objectweb/asm/Label.h>
#include <jdk/internal/org/objectweb/asm/MethodVisitor.h>
#include <jdk/internal/org/objectweb/asm/Opcodes.h>
#include <jdk/internal/org/objectweb/asm/Type.h>
#include <jdk/internal/org/objectweb/asm/commons/GeneratorAdapter.h>
#include <jdk/internal/org/objectweb/asm/commons/LocalVariablesSorter.h>
#include <jcpp.h>

#undef AALOAD
#undef AASTORE
#undef ACONST_NULL
#undef ALOAD
#undef ARETURN
#undef ARRAYLENGTH
#undef ASM5
#undef ASTORE
#undef ATHROW
#undef BALOAD
#undef BASTORE
#undef CALOAD
#undef CASTORE
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
#undef FMUL
#undef FNEG
#undef FREM
#undef FRETURN
#undef FSTORE
#undef FSUB
#undef GETFIELD
#undef GETSTATIC
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
#undef ILOAD
#undef IMUL
#undef INEG
#undef INVALID_OPCODE
#undef INVOKEDYNAMIC
#undef INVOKEINTERFACE
#undef INVOKESPECIAL
#undef INVOKEVIRTUAL
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
#undef LOR
#undef LREM
#undef LRETURN
#undef LSHL
#undef LSHR
#undef LSTORE
#undef LSUB
#undef LUSHR
#undef LXOR
#undef MONITORENTER
#undef MONITOREXIT
#undef NEW
#undef NEWARRAY
#undef NOP
#undef OTHER
#undef POP
#undef POP2
#undef PUTFIELD
#undef PUTSTATIC
#undef RET
#undef RETURN
#undef SALOAD
#undef SASTORE
#undef SOURCE_DEPRECATED
#undef SOURCE_MASK
#undef SWAP
#undef UNINITIALIZED_THIS
#undef VOID_TYPE

using $LabelArray = $Array<::jdk::internal::org::objectweb::asm$::Label>;
using $TypeArray = $Array<::jdk::internal::org::objectweb::asm$::Type>;
using $ClassInfo = ::java::lang::ClassInfo;
using $Double = ::java::lang::Double;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $HashMap = ::java::util::HashMap;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $ConstantDynamic = ::jdk::internal::org::objectweb::asm$::ConstantDynamic;
using $Handle = ::jdk::internal::org::objectweb::asm$::Handle;
using $Label = ::jdk::internal::org::objectweb::asm$::Label;
using $MethodVisitor = ::jdk::internal::org::objectweb::asm$::MethodVisitor;
using $Opcodes = ::jdk::internal::org::objectweb::asm$::Opcodes;
using $Type = ::jdk::internal::org::objectweb::asm$::Type;
using $GeneratorAdapter = ::jdk::internal::org::objectweb::asm$::commons::GeneratorAdapter;

namespace jdk {
	namespace internal {
		namespace org {
			namespace objectweb {
				namespace asm$ {
					namespace commons {

$FieldInfo _AdviceAdapter_FieldInfo_[] = {
	{"UNINITIALIZED_THIS", "Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(AdviceAdapter, UNINITIALIZED_THIS)},
	{"OTHER", "Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(AdviceAdapter, OTHER)},
	{"INVALID_OPCODE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(AdviceAdapter, INVALID_OPCODE)},
	{"methodAccess", "I", nullptr, $PROTECTED, $field(AdviceAdapter, methodAccess)},
	{"methodDesc", "Ljava/lang/String;", nullptr, $PROTECTED, $field(AdviceAdapter, methodDesc)},
	{"isConstructor", "Z", nullptr, $PRIVATE | $FINAL, $field(AdviceAdapter, isConstructor)},
	{"superClassConstructorCalled", "Z", nullptr, $PRIVATE, $field(AdviceAdapter, superClassConstructorCalled)},
	{"stackFrame", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/Object;>;", $PRIVATE, $field(AdviceAdapter, stackFrame)},
	{"forwardJumpStackFrames", "Ljava/util/Map;", "Ljava/util/Map<Ljdk/internal/org/objectweb/asm/Label;Ljava/util/List<Ljava/lang/Object;>;>;", $PRIVATE, $field(AdviceAdapter, forwardJumpStackFrames)},
	{}
};

$MethodInfo _AdviceAdapter_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(ILjdk/internal/org/objectweb/asm/MethodVisitor;ILjava/lang/String;Ljava/lang/String;)V", nullptr, $PROTECTED, $method(AdviceAdapter, init$, void, int32_t, $MethodVisitor*, int32_t, $String*, $String*)},
	{"addForwardJump", "(Ljdk/internal/org/objectweb/asm/Label;)V", nullptr, $PRIVATE, $method(AdviceAdapter, addForwardJump, void, $Label*)},
	{"addForwardJumps", "(Ljdk/internal/org/objectweb/asm/Label;[Ljdk/internal/org/objectweb/asm/Label;)V", nullptr, $PRIVATE, $method(AdviceAdapter, addForwardJumps, void, $Label*, $LabelArray*)},
	{"doVisitMethodInsn", "(ILjava/lang/String;)V", nullptr, $PRIVATE, $method(AdviceAdapter, doVisitMethodInsn, void, int32_t, $String*)},
	{"onMethodEnter", "()V", nullptr, $PROTECTED, $virtualMethod(AdviceAdapter, onMethodEnter, void)},
	{"onMethodExit", "(I)V", nullptr, $PROTECTED, $virtualMethod(AdviceAdapter, onMethodExit, void, int32_t)},
	{"peekValue", "()Ljava/lang/Object;", nullptr, $PRIVATE, $method(AdviceAdapter, peekValue, $Object*)},
	{"popValue", "()Ljava/lang/Object;", nullptr, $PRIVATE, $method(AdviceAdapter, popValue, $Object*)},
	{"pushValue", "(Ljava/lang/Object;)V", nullptr, $PRIVATE, $method(AdviceAdapter, pushValue, void, Object$*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"visitCode", "()V", nullptr, $PUBLIC, $virtualMethod(AdviceAdapter, visitCode, void)},
	{"visitFieldInsn", "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(AdviceAdapter, visitFieldInsn, void, int32_t, $String*, $String*, $String*)},
	{"visitInsn", "(I)V", nullptr, $PUBLIC, $virtualMethod(AdviceAdapter, visitInsn, void, int32_t)},
	{"visitIntInsn", "(II)V", nullptr, $PUBLIC, $virtualMethod(AdviceAdapter, visitIntInsn, void, int32_t, int32_t)},
	{"visitInvokeDynamicInsn", "(Ljava/lang/String;Ljava/lang/String;Ljdk/internal/org/objectweb/asm/Handle;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(AdviceAdapter, visitInvokeDynamicInsn, void, $String*, $String*, $Handle*, $ObjectArray*)},
	{"visitJumpInsn", "(ILjdk/internal/org/objectweb/asm/Label;)V", nullptr, $PUBLIC, $virtualMethod(AdviceAdapter, visitJumpInsn, void, int32_t, $Label*)},
	{"visitLabel", "(Ljdk/internal/org/objectweb/asm/Label;)V", nullptr, $PUBLIC, $virtualMethod(AdviceAdapter, visitLabel, void, $Label*)},
	{"visitLdcInsn", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(AdviceAdapter, visitLdcInsn, void, Object$*)},
	{"visitLookupSwitchInsn", "(Ljdk/internal/org/objectweb/asm/Label;[I[Ljdk/internal/org/objectweb/asm/Label;)V", nullptr, $PUBLIC, $virtualMethod(AdviceAdapter, visitLookupSwitchInsn, void, $Label*, $ints*, $LabelArray*)},
	{"visitMethodInsn", "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Z)V", nullptr, $PUBLIC, $virtualMethod(AdviceAdapter, visitMethodInsn, void, int32_t, $String*, $String*, $String*, bool)},
	{"visitMultiANewArrayInsn", "(Ljava/lang/String;I)V", nullptr, $PUBLIC, $virtualMethod(AdviceAdapter, visitMultiANewArrayInsn, void, $String*, int32_t)},
	{"visitTableSwitchInsn", "(IILjdk/internal/org/objectweb/asm/Label;[Ljdk/internal/org/objectweb/asm/Label;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(AdviceAdapter, visitTableSwitchInsn, void, int32_t, int32_t, $Label*, $LabelArray*)},
	{"visitTryCatchBlock", "(Ljdk/internal/org/objectweb/asm/Label;Ljdk/internal/org/objectweb/asm/Label;Ljdk/internal/org/objectweb/asm/Label;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(AdviceAdapter, visitTryCatchBlock, void, $Label*, $Label*, $Label*, $String*)},
	{"visitTypeInsn", "(ILjava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(AdviceAdapter, visitTypeInsn, void, int32_t, $String*)},
	{"visitVarInsn", "(II)V", nullptr, $PUBLIC, $virtualMethod(AdviceAdapter, visitVarInsn, void, int32_t, int32_t)},
	{}
};

$ClassInfo _AdviceAdapter_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"jdk.internal.org.objectweb.asm.commons.AdviceAdapter",
	"jdk.internal.org.objectweb.asm.commons.GeneratorAdapter",
	"jdk.internal.org.objectweb.asm.Opcodes",
	_AdviceAdapter_FieldInfo_,
	_AdviceAdapter_MethodInfo_
};

$Object* allocate$AdviceAdapter($Class* clazz) {
	return $of($alloc(AdviceAdapter));
}

int32_t AdviceAdapter::hashCode() {
	 return this->$GeneratorAdapter::hashCode();
}

bool AdviceAdapter::equals(Object$* obj) {
	 return this->$GeneratorAdapter::equals(obj);
}

$Object* AdviceAdapter::clone() {
	 return this->$GeneratorAdapter::clone();
}

$String* AdviceAdapter::toString() {
	 return this->$GeneratorAdapter::toString();
}

void AdviceAdapter::finalize() {
	this->$GeneratorAdapter::finalize();
}

$Object* AdviceAdapter::UNINITIALIZED_THIS = nullptr;
$Object* AdviceAdapter::OTHER = nullptr;
$String* AdviceAdapter::INVALID_OPCODE = nullptr;

void AdviceAdapter::init$(int32_t api, $MethodVisitor* methodVisitor, int32_t access, $String* name, $String* descriptor) {
	$GeneratorAdapter::init$(api, methodVisitor, access, name, descriptor);
	this->methodAccess = access;
	$set(this, methodDesc, descriptor);
	this->isConstructor = "<init>"_s->equals(name);
}

void AdviceAdapter::visitCode() {
	$GeneratorAdapter::visitCode();
	if (this->isConstructor) {
		$set(this, stackFrame, $new($ArrayList));
		$set(this, forwardJumpStackFrames, $new($HashMap));
	} else {
		onMethodEnter();
	}
}

void AdviceAdapter::visitLabel($Label* label) {
	$GeneratorAdapter::visitLabel(label);
	if (this->isConstructor && this->forwardJumpStackFrames != nullptr) {
		$var($List, labelStackFrame, $cast($List, $nc(this->forwardJumpStackFrames)->get(label)));
		if (labelStackFrame != nullptr) {
			$set(this, stackFrame, labelStackFrame);
			this->superClassConstructorCalled = false;
			$nc(this->forwardJumpStackFrames)->remove(label);
		}
	}
}

void AdviceAdapter::visitInsn(int32_t opcode) {
	$useLocalCurrentObjectStackCache();
	if (this->isConstructor && !this->superClassConstructorCalled) {
		int32_t stackSize = 0;
		switch (opcode) {
		case $Opcodes::IRETURN:
			{}
		case $Opcodes::FRETURN:
			{}
		case $Opcodes::ARETURN:
			{}
		case $Opcodes::LRETURN:
			{}
		case $Opcodes::DRETURN:
			{
				$throwNew($IllegalArgumentException, "Invalid return in constructor"_s);
			}
		case $Opcodes::RETURN:
			{
				onMethodExit(opcode);
				break;
			}
		case $Opcodes::ATHROW:
			{
				popValue();
				onMethodExit(opcode);
				break;
			}
		case $Opcodes::NOP:
			{}
		case $Opcodes::LALOAD:
			{}
		case $Opcodes::DALOAD:
			{}
		case $Opcodes::LNEG:
			{}
		case $Opcodes::DNEG:
			{}
		case $Opcodes::FNEG:
			{}
		case $Opcodes::INEG:
			{}
		case $Opcodes::L2D:
			{}
		case $Opcodes::D2L:
			{}
		case $Opcodes::F2I:
			{}
		case $Opcodes::I2B:
			{}
		case $Opcodes::I2C:
			{}
		case $Opcodes::I2S:
			{}
		case $Opcodes::I2F:
			{}
		case $Opcodes::ARRAYLENGTH:
			{
				break;
			}
		case $Opcodes::ACONST_NULL:
			{}
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
		case $Opcodes::FCONST_0:
			{}
		case $Opcodes::FCONST_1:
			{}
		case $Opcodes::FCONST_2:
			{}
		case $Opcodes::F2L:
			{}
		case $Opcodes::F2D:
			{}
		case $Opcodes::I2L:
			{}
		case $Opcodes::I2D:
			{
				pushValue(AdviceAdapter::OTHER);
				break;
			}
		case $Opcodes::LCONST_0:
			{}
		case $Opcodes::LCONST_1:
			{}
		case $Opcodes::DCONST_0:
			{}
		case $Opcodes::DCONST_1:
			{
				pushValue(AdviceAdapter::OTHER);
				pushValue(AdviceAdapter::OTHER);
				break;
			}
		case $Opcodes::IALOAD:
			{}
		case $Opcodes::FALOAD:
			{}
		case $Opcodes::AALOAD:
			{}
		case $Opcodes::BALOAD:
			{}
		case $Opcodes::CALOAD:
			{}
		case $Opcodes::SALOAD:
			{}
		case $Opcodes::POP:
			{}
		case $Opcodes::IADD:
			{}
		case $Opcodes::FADD:
			{}
		case $Opcodes::ISUB:
			{}
		case $Opcodes::LSHL:
			{}
		case $Opcodes::LSHR:
			{}
		case $Opcodes::LUSHR:
			{}
		case $Opcodes::L2I:
			{}
		case $Opcodes::L2F:
			{}
		case $Opcodes::D2I:
			{}
		case $Opcodes::D2F:
			{}
		case $Opcodes::FSUB:
			{}
		case $Opcodes::FMUL:
			{}
		case $Opcodes::FDIV:
			{}
		case $Opcodes::FREM:
			{}
		case $Opcodes::FCMPL:
			{}
		case $Opcodes::FCMPG:
			{}
		case $Opcodes::IMUL:
			{}
		case $Opcodes::IDIV:
			{}
		case $Opcodes::IREM:
			{}
		case $Opcodes::ISHL:
			{}
		case $Opcodes::ISHR:
			{}
		case $Opcodes::IUSHR:
			{}
		case $Opcodes::IAND:
			{}
		case $Opcodes::IOR:
			{}
		case $Opcodes::IXOR:
			{}
		case $Opcodes::MONITORENTER:
			{}
		case $Opcodes::MONITOREXIT:
			{
				popValue();
				break;
			}
		case $Opcodes::POP2:
			{}
		case $Opcodes::LSUB:
			{}
		case $Opcodes::LMUL:
			{}
		case $Opcodes::LDIV:
			{}
		case $Opcodes::LREM:
			{}
		case $Opcodes::LADD:
			{}
		case $Opcodes::LAND:
			{}
		case $Opcodes::LOR:
			{}
		case $Opcodes::LXOR:
			{}
		case $Opcodes::DADD:
			{}
		case $Opcodes::DMUL:
			{}
		case $Opcodes::DSUB:
			{}
		case $Opcodes::DDIV:
			{}
		case $Opcodes::DREM:
			{
				popValue();
				popValue();
				break;
			}
		case $Opcodes::IASTORE:
			{}
		case $Opcodes::FASTORE:
			{}
		case $Opcodes::AASTORE:
			{}
		case $Opcodes::BASTORE:
			{}
		case $Opcodes::CASTORE:
			{}
		case $Opcodes::SASTORE:
			{}
		case $Opcodes::LCMP:
			{}
		case $Opcodes::DCMPL:
			{}
		case $Opcodes::DCMPG:
			{
				popValue();
				popValue();
				popValue();
				break;
			}
		case $Opcodes::LASTORE:
			{}
		case $Opcodes::DASTORE:
			{
				popValue();
				popValue();
				popValue();
				popValue();
				break;
			}
		case $Opcodes::DUP:
			{
				pushValue($(peekValue()));
				break;
			}
		case $Opcodes::DUP_X1:
			{
				stackSize = $nc(this->stackFrame)->size();
				$nc(this->stackFrame)->add(stackSize - 2, $($nc(this->stackFrame)->get(stackSize - 1)));
				break;
			}
		case $Opcodes::DUP_X2:
			{
				stackSize = $nc(this->stackFrame)->size();
				$nc(this->stackFrame)->add(stackSize - 3, $($nc(this->stackFrame)->get(stackSize - 1)));
				break;
			}
		case $Opcodes::DUP2:
			{
				stackSize = $nc(this->stackFrame)->size();
				$nc(this->stackFrame)->add(stackSize - 2, $($nc(this->stackFrame)->get(stackSize - 1)));
				$nc(this->stackFrame)->add(stackSize - 2, $($nc(this->stackFrame)->get(stackSize - 1)));
				break;
			}
		case $Opcodes::DUP2_X1:
			{
				stackSize = $nc(this->stackFrame)->size();
				$nc(this->stackFrame)->add(stackSize - 3, $($nc(this->stackFrame)->get(stackSize - 1)));
				$nc(this->stackFrame)->add(stackSize - 3, $($nc(this->stackFrame)->get(stackSize - 1)));
				break;
			}
		case $Opcodes::DUP2_X2:
			{
				stackSize = $nc(this->stackFrame)->size();
				$nc(this->stackFrame)->add(stackSize - 4, $($nc(this->stackFrame)->get(stackSize - 1)));
				$nc(this->stackFrame)->add(stackSize - 4, $($nc(this->stackFrame)->get(stackSize - 1)));
				break;
			}
		case $Opcodes::SWAP:
			{
				stackSize = $nc(this->stackFrame)->size();
				$nc(this->stackFrame)->add(stackSize - 2, $($nc(this->stackFrame)->get(stackSize - 1)));
				$nc(this->stackFrame)->remove(stackSize);
				break;
			}
		default:
			{
				$throwNew($IllegalArgumentException, $$str({AdviceAdapter::INVALID_OPCODE, $$str(opcode)}));
			}
		}
	} else {
		switch (opcode) {
		case $Opcodes::RETURN:
			{}
		case $Opcodes::IRETURN:
			{}
		case $Opcodes::FRETURN:
			{}
		case $Opcodes::ARETURN:
			{}
		case $Opcodes::LRETURN:
			{}
		case $Opcodes::DRETURN:
			{}
		case $Opcodes::ATHROW:
			{
				onMethodExit(opcode);
				break;
			}
		default:
			{
				break;
			}
		}
	}
	$GeneratorAdapter::visitInsn(opcode);
}

void AdviceAdapter::visitVarInsn(int32_t opcode, int32_t var) {
	$useLocalCurrentObjectStackCache();
	$GeneratorAdapter::visitVarInsn(opcode, var);
	if (this->isConstructor && !this->superClassConstructorCalled) {
		switch (opcode) {
		case $Opcodes::ILOAD:
			{}
		case $Opcodes::FLOAD:
			{
				pushValue(AdviceAdapter::OTHER);
				break;
			}
		case $Opcodes::LLOAD:
			{}
		case $Opcodes::DLOAD:
			{
				pushValue(AdviceAdapter::OTHER);
				pushValue(AdviceAdapter::OTHER);
				break;
			}
		case $Opcodes::ALOAD:
			{
				pushValue(var == 0 ? AdviceAdapter::UNINITIALIZED_THIS : AdviceAdapter::OTHER);
				break;
			}
		case $Opcodes::ASTORE:
			{}
		case $Opcodes::ISTORE:
			{}
		case $Opcodes::FSTORE:
			{
				popValue();
				break;
			}
		case $Opcodes::LSTORE:
			{}
		case $Opcodes::DSTORE:
			{
				popValue();
				popValue();
				break;
			}
		case $Opcodes::RET:
			{
				break;
			}
		default:
			{
				$throwNew($IllegalArgumentException, $$str({AdviceAdapter::INVALID_OPCODE, $$str(opcode)}));
			}
		}
	}
}

void AdviceAdapter::visitFieldInsn(int32_t opcode, $String* owner, $String* name, $String* descriptor) {
	$useLocalCurrentObjectStackCache();
	$GeneratorAdapter::visitFieldInsn(opcode, owner, name, descriptor);
	if (this->isConstructor && !this->superClassConstructorCalled) {
		char16_t firstDescriptorChar = $nc(descriptor)->charAt(0);
		bool longOrDouble = firstDescriptorChar == u'J' || firstDescriptorChar == u'D';
		switch (opcode) {
		case $Opcodes::GETSTATIC:
			{
				pushValue(AdviceAdapter::OTHER);
				if (longOrDouble) {
					pushValue(AdviceAdapter::OTHER);
				}
				break;
			}
		case $Opcodes::PUTSTATIC:
			{
				popValue();
				if (longOrDouble) {
					popValue();
				}
				break;
			}
		case $Opcodes::PUTFIELD:
			{
				popValue();
				popValue();
				if (longOrDouble) {
					popValue();
				}
				break;
			}
		case $Opcodes::GETFIELD:
			{
				if (longOrDouble) {
					pushValue(AdviceAdapter::OTHER);
				}
				break;
			}
		default:
			{
				$throwNew($IllegalArgumentException, $$str({AdviceAdapter::INVALID_OPCODE, $$str(opcode)}));
			}
		}
	}
}

void AdviceAdapter::visitIntInsn(int32_t opcode, int32_t operand) {
	$GeneratorAdapter::visitIntInsn(opcode, operand);
	if (this->isConstructor && !this->superClassConstructorCalled && opcode != $Opcodes::NEWARRAY) {
		pushValue(AdviceAdapter::OTHER);
	}
}

void AdviceAdapter::visitLdcInsn(Object$* value) {
	$GeneratorAdapter::visitLdcInsn(value);
	if (this->isConstructor && !this->superClassConstructorCalled) {
		pushValue(AdviceAdapter::OTHER);
		if ($instanceOf($Double, value) || $instanceOf($Long, value) || ($instanceOf($ConstantDynamic, value) && $nc(($cast($ConstantDynamic, value)))->getSize() == 2)) {
			pushValue(AdviceAdapter::OTHER);
		}
	}
}

void AdviceAdapter::visitMultiANewArrayInsn($String* descriptor, int32_t numDimensions) {
	$GeneratorAdapter::visitMultiANewArrayInsn(descriptor, numDimensions);
	if (this->isConstructor && !this->superClassConstructorCalled) {
		for (int32_t i = 0; i < numDimensions; ++i) {
			popValue();
		}
		pushValue(AdviceAdapter::OTHER);
	}
}

void AdviceAdapter::visitTypeInsn(int32_t opcode, $String* type) {
	$GeneratorAdapter::visitTypeInsn(opcode, type);
	if (this->isConstructor && !this->superClassConstructorCalled && opcode == $Opcodes::NEW) {
		pushValue(AdviceAdapter::OTHER);
	}
}

void AdviceAdapter::visitMethodInsn(int32_t opcodeAndSource, $String* owner, $String* name, $String* descriptor, bool isInterface) {
	if (this->api < $Opcodes::ASM5 && ((int32_t)(opcodeAndSource & (uint32_t)$Opcodes::SOURCE_DEPRECATED)) == 0) {
		$GeneratorAdapter::visitMethodInsn(opcodeAndSource, owner, name, descriptor, isInterface);
		return;
	}
	$GeneratorAdapter::visitMethodInsn(opcodeAndSource, owner, name, descriptor, isInterface);
	int32_t opcode = (int32_t)(opcodeAndSource & (uint32_t)~$Opcodes::SOURCE_MASK);
	doVisitMethodInsn(opcode, descriptor);
}

void AdviceAdapter::doVisitMethodInsn(int32_t opcode, $String* descriptor) {
	$useLocalCurrentObjectStackCache();
	if (this->isConstructor && !this->superClassConstructorCalled) {
		{
			$var($TypeArray, arr$, $Type::getArgumentTypes(descriptor));
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($Type, argumentType, arr$->get(i$));
				{
					popValue();
					if ($nc(argumentType)->getSize() == 2) {
						popValue();
					}
				}
			}
		}
		{
			$var($Object, value, nullptr)
			switch (opcode) {
			case $Opcodes::INVOKEINTERFACE:
				{}
			case $Opcodes::INVOKEVIRTUAL:
				{
					popValue();
					break;
				}
			case $Opcodes::INVOKESPECIAL:
				{
					$assign(value, popValue());
					if ($equals(value, AdviceAdapter::UNINITIALIZED_THIS) && !this->superClassConstructorCalled) {
						this->superClassConstructorCalled = true;
						onMethodEnter();
					}
					break;
				}
			default:
				{
					break;
				}
			}
		}
		$var($Type, returnType, $Type::getReturnType(descriptor));
		if (returnType != $Type::VOID_TYPE) {
			pushValue(AdviceAdapter::OTHER);
			if ($nc(returnType)->getSize() == 2) {
				pushValue(AdviceAdapter::OTHER);
			}
		}
	}
}

void AdviceAdapter::visitInvokeDynamicInsn($String* name, $String* descriptor, $Handle* bootstrapMethodHandle, $ObjectArray* bootstrapMethodArguments) {
	$GeneratorAdapter::visitInvokeDynamicInsn(name, descriptor, bootstrapMethodHandle, bootstrapMethodArguments);
	doVisitMethodInsn($Opcodes::INVOKEDYNAMIC, descriptor);
}

void AdviceAdapter::visitJumpInsn(int32_t opcode, $Label* label) {
	$GeneratorAdapter::visitJumpInsn(opcode, label);
	if (this->isConstructor && !this->superClassConstructorCalled) {
		switch (opcode) {
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
		case $Opcodes::IFNULL:
			{}
		case $Opcodes::IFNONNULL:
			{
				popValue();
				break;
			}
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
			{
				popValue();
				popValue();
				break;
			}
		case $Opcodes::JSR:
			{
				pushValue(AdviceAdapter::OTHER);
				break;
			}
		default:
			{
				break;
			}
		}
		addForwardJump(label);
	}
}

void AdviceAdapter::visitLookupSwitchInsn($Label* dflt, $ints* keys, $LabelArray* labels) {
	$GeneratorAdapter::visitLookupSwitchInsn(dflt, keys, labels);
	if (this->isConstructor && !this->superClassConstructorCalled) {
		popValue();
		addForwardJumps(dflt, labels);
	}
}

void AdviceAdapter::visitTableSwitchInsn(int32_t min, int32_t max, $Label* dflt, $LabelArray* labels) {
	$GeneratorAdapter::visitTableSwitchInsn(min, max, dflt, labels);
	if (this->isConstructor && !this->superClassConstructorCalled) {
		popValue();
		addForwardJumps(dflt, labels);
	}
}

void AdviceAdapter::visitTryCatchBlock($Label* start, $Label* end, $Label* handler, $String* type) {
	$GeneratorAdapter::visitTryCatchBlock(start, end, handler, type);
	if (this->isConstructor && !$nc(this->forwardJumpStackFrames)->containsKey(handler)) {
		$var($List, handlerStackFrame, $new($ArrayList));
		handlerStackFrame->add(AdviceAdapter::OTHER);
		$nc(this->forwardJumpStackFrames)->put(handler, handlerStackFrame);
	}
}

void AdviceAdapter::addForwardJumps($Label* dflt, $LabelArray* labels) {
	$useLocalCurrentObjectStackCache();
	addForwardJump(dflt);
	{
		$var($LabelArray, arr$, labels);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Label, label, arr$->get(i$));
			{
				addForwardJump(label);
			}
		}
	}
}

void AdviceAdapter::addForwardJump($Label* label) {
	if ($nc(this->forwardJumpStackFrames)->containsKey(label)) {
		return;
	}
	$nc(this->forwardJumpStackFrames)->put(label, $$new($ArrayList, static_cast<$Collection*>(this->stackFrame)));
}

$Object* AdviceAdapter::popValue() {
	return $of($nc(this->stackFrame)->remove($nc(this->stackFrame)->size() - 1));
}

$Object* AdviceAdapter::peekValue() {
	return $of($nc(this->stackFrame)->get($nc(this->stackFrame)->size() - 1));
}

void AdviceAdapter::pushValue(Object$* value) {
	$nc(this->stackFrame)->add(value);
}

void AdviceAdapter::onMethodEnter() {
}

void AdviceAdapter::onMethodExit(int32_t opcode) {
}

void clinit$AdviceAdapter($Class* class$) {
	$assignStatic(AdviceAdapter::INVALID_OPCODE, "Invalid opcode "_s);
	$assignStatic(AdviceAdapter::UNINITIALIZED_THIS, $new($Object));
	$assignStatic(AdviceAdapter::OTHER, $new($Object));
}

AdviceAdapter::AdviceAdapter() {
}

$Class* AdviceAdapter::load$($String* name, bool initialize) {
	$loadClass(AdviceAdapter, name, initialize, &_AdviceAdapter_ClassInfo_, clinit$AdviceAdapter, allocate$AdviceAdapter);
	return class$;
}

$Class* AdviceAdapter::class$ = nullptr;

					} // commons
				} // asm$
			} // objectweb
		} // org
	} // internal
} // jdk