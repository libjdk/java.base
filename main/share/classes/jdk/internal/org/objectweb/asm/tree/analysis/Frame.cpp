#include <jdk/internal/org/objectweb/asm/tree/analysis/Frame.h>

#include <java/lang/IndexOutOfBoundsException.h>
#include <java/util/ArrayList.h>
#include <java/util/List.h>
#include <jdk/internal/org/objectweb/asm/Opcodes.h>
#include <jdk/internal/org/objectweb/asm/Type.h>
#include <jdk/internal/org/objectweb/asm/tree/AbstractInsnNode.h>
#include <jdk/internal/org/objectweb/asm/tree/IincInsnNode.h>
#include <jdk/internal/org/objectweb/asm/tree/InvokeDynamicInsnNode.h>
#include <jdk/internal/org/objectweb/asm/tree/LabelNode.h>
#include <jdk/internal/org/objectweb/asm/tree/MethodInsnNode.h>
#include <jdk/internal/org/objectweb/asm/tree/MultiANewArrayInsnNode.h>
#include <jdk/internal/org/objectweb/asm/tree/VarInsnNode.h>
#include <jdk/internal/org/objectweb/asm/tree/analysis/AnalyzerException.h>
#include <jdk/internal/org/objectweb/asm/tree/analysis/Interpreter.h>
#include <jdk/internal/org/objectweb/asm/tree/analysis/Value.h>
#include <jcpp.h>

#undef AALOAD
#undef AASTORE
#undef ACONST_NULL
#undef ALOAD
#undef ANEWARRAY
#undef ARETURN
#undef ARRAYLENGTH
#undef ASTORE
#undef ATHROW
#undef BALOAD
#undef BASTORE
#undef BIPUSH
#undef CALOAD
#undef CASTORE
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
#undef INVOKEDYNAMIC
#undef INVOKEINTERFACE
#undef INVOKESPECIAL
#undef INVOKESTATIC
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
#undef LDC
#undef LDIV
#undef LLOAD
#undef LMUL
#undef LNEG
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
#undef MONITORENTER
#undef MONITOREXIT
#undef MULTIANEWARRAY
#undef NEW
#undef NEWARRAY
#undef NOP
#undef POP
#undef POP2
#undef PUTFIELD
#undef PUTSTATIC
#undef RET
#undef RETURN
#undef SALOAD
#undef SASTORE
#undef SIPUSH
#undef SWAP
#undef TABLESWITCH
#undef VOID_TYPE

using $ValueArray = $Array<::jdk::internal::org::objectweb::asm$::tree::analysis::Value>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IndexOutOfBoundsException = ::java::lang::IndexOutOfBoundsException;
using $MethodInfo = ::java::lang::MethodInfo;
using $ArrayList = ::java::util::ArrayList;
using $List = ::java::util::List;
using $Opcodes = ::jdk::internal::org::objectweb::asm$::Opcodes;
using $Type = ::jdk::internal::org::objectweb::asm$::Type;
using $AbstractInsnNode = ::jdk::internal::org::objectweb::asm$::tree::AbstractInsnNode;
using $IincInsnNode = ::jdk::internal::org::objectweb::asm$::tree::IincInsnNode;
using $InvokeDynamicInsnNode = ::jdk::internal::org::objectweb::asm$::tree::InvokeDynamicInsnNode;
using $LabelNode = ::jdk::internal::org::objectweb::asm$::tree::LabelNode;
using $MethodInsnNode = ::jdk::internal::org::objectweb::asm$::tree::MethodInsnNode;
using $MultiANewArrayInsnNode = ::jdk::internal::org::objectweb::asm$::tree::MultiANewArrayInsnNode;
using $VarInsnNode = ::jdk::internal::org::objectweb::asm$::tree::VarInsnNode;
using $AnalyzerException = ::jdk::internal::org::objectweb::asm$::tree::analysis::AnalyzerException;
using $Interpreter = ::jdk::internal::org::objectweb::asm$::tree::analysis::Interpreter;
using $1Value = ::jdk::internal::org::objectweb::asm$::tree::analysis::Value;

namespace jdk {
	namespace internal {
		namespace org {
			namespace objectweb {
				namespace asm$ {
					namespace tree {
						namespace analysis {

$FieldInfo _Frame_FieldInfo_[] = {
	{"returnValue", "Ljdk/internal/org/objectweb/asm/tree/analysis/Value;", "TV;", $PRIVATE, $field(Frame, returnValue)},
	{"values", "[Ljdk/internal/org/objectweb/asm/tree/analysis/Value;", "[TV;", $PRIVATE, $field(Frame, values)},
	{"numLocals", "I", nullptr, $PRIVATE, $field(Frame, numLocals)},
	{"numStack", "I", nullptr, $PRIVATE, $field(Frame, numStack)},
	{}
};

$MethodInfo _Frame_MethodInfo_[] = {
	{"<init>", "(II)V", nullptr, $PUBLIC, $method(Frame, init$, void, int32_t, int32_t)},
	{"<init>", "(Ljdk/internal/org/objectweb/asm/tree/analysis/Frame;)V", "(Ljdk/internal/org/objectweb/asm/tree/analysis/Frame<+TV;>;)V", $PUBLIC, $method(Frame, init$, void, Frame*)},
	{"clearStack", "()V", nullptr, $PUBLIC, $virtualMethod(Frame, clearStack, void)},
	{"execute", "(Ljdk/internal/org/objectweb/asm/tree/AbstractInsnNode;Ljdk/internal/org/objectweb/asm/tree/analysis/Interpreter;)V", "(Ljdk/internal/org/objectweb/asm/tree/AbstractInsnNode;Ljdk/internal/org/objectweb/asm/tree/analysis/Interpreter<TV;>;)V", $PUBLIC, $virtualMethod(Frame, execute, void, $AbstractInsnNode*, $Interpreter*), "jdk.internal.org.objectweb.asm.tree.analysis.AnalyzerException"},
	{"executeDupX2", "(Ljdk/internal/org/objectweb/asm/tree/AbstractInsnNode;Ljdk/internal/org/objectweb/asm/tree/analysis/Value;Ljdk/internal/org/objectweb/asm/tree/analysis/Interpreter;)Z", "(Ljdk/internal/org/objectweb/asm/tree/AbstractInsnNode;TV;Ljdk/internal/org/objectweb/asm/tree/analysis/Interpreter<TV;>;)Z", $PRIVATE, $method(Frame, executeDupX2, bool, $AbstractInsnNode*, $1Value*, $Interpreter*), "jdk.internal.org.objectweb.asm.tree.analysis.AnalyzerException"},
	{"executeInvokeInsn", "(Ljdk/internal/org/objectweb/asm/tree/AbstractInsnNode;Ljava/lang/String;Ljdk/internal/org/objectweb/asm/tree/analysis/Interpreter;)V", "(Ljdk/internal/org/objectweb/asm/tree/AbstractInsnNode;Ljava/lang/String;Ljdk/internal/org/objectweb/asm/tree/analysis/Interpreter<TV;>;)V", $PRIVATE, $method(Frame, executeInvokeInsn, void, $AbstractInsnNode*, $String*, $Interpreter*), "jdk.internal.org.objectweb.asm.tree.analysis.AnalyzerException"},
	{"getLocal", "(I)Ljdk/internal/org/objectweb/asm/tree/analysis/Value;", "(I)TV;", $PUBLIC, $virtualMethod(Frame, getLocal, $1Value*, int32_t)},
	{"getLocals", "()I", nullptr, $PUBLIC, $virtualMethod(Frame, getLocals, int32_t)},
	{"getMaxStackSize", "()I", nullptr, $PUBLIC, $virtualMethod(Frame, getMaxStackSize, int32_t)},
	{"getStack", "(I)Ljdk/internal/org/objectweb/asm/tree/analysis/Value;", "(I)TV;", $PUBLIC, $virtualMethod(Frame, getStack, $1Value*, int32_t)},
	{"getStackSize", "()I", nullptr, $PUBLIC, $virtualMethod(Frame, getStackSize, int32_t)},
	{"init", "(Ljdk/internal/org/objectweb/asm/tree/analysis/Frame;)Ljdk/internal/org/objectweb/asm/tree/analysis/Frame;", "(Ljdk/internal/org/objectweb/asm/tree/analysis/Frame<+TV;>;)Ljdk/internal/org/objectweb/asm/tree/analysis/Frame<TV;>;", $PUBLIC, $virtualMethod(Frame, init, Frame*, Frame*)},
	{"initJumpTarget", "(ILjdk/internal/org/objectweb/asm/tree/LabelNode;)V", nullptr, $PUBLIC, $virtualMethod(Frame, initJumpTarget, void, int32_t, $LabelNode*)},
	{"merge", "(Ljdk/internal/org/objectweb/asm/tree/analysis/Frame;Ljdk/internal/org/objectweb/asm/tree/analysis/Interpreter;)Z", "(Ljdk/internal/org/objectweb/asm/tree/analysis/Frame<+TV;>;Ljdk/internal/org/objectweb/asm/tree/analysis/Interpreter<TV;>;)Z", $PUBLIC, $virtualMethod(Frame, merge, bool, Frame*, $Interpreter*), "jdk.internal.org.objectweb.asm.tree.analysis.AnalyzerException"},
	{"merge", "(Ljdk/internal/org/objectweb/asm/tree/analysis/Frame;[Z)Z", "(Ljdk/internal/org/objectweb/asm/tree/analysis/Frame<+TV;>;[Z)Z", $PUBLIC, $virtualMethod(Frame, merge, bool, Frame*, $booleans*)},
	{"pop", "()Ljdk/internal/org/objectweb/asm/tree/analysis/Value;", "()TV;", $PUBLIC, $virtualMethod(Frame, pop, $1Value*)},
	{"push", "(Ljdk/internal/org/objectweb/asm/tree/analysis/Value;)V", "(TV;)V", $PUBLIC, $virtualMethod(Frame, push, void, $1Value*)},
	{"setLocal", "(ILjdk/internal/org/objectweb/asm/tree/analysis/Value;)V", "(ITV;)V", $PUBLIC, $virtualMethod(Frame, setLocal, void, int32_t, $1Value*)},
	{"setReturn", "(Ljdk/internal/org/objectweb/asm/tree/analysis/Value;)V", "(TV;)V", $PUBLIC, $virtualMethod(Frame, setReturn, void, $1Value*)},
	{"setStack", "(ILjdk/internal/org/objectweb/asm/tree/analysis/Value;)V", "(ITV;)V", $PUBLIC, $virtualMethod(Frame, setStack, void, int32_t, $1Value*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Frame, toString, $String*)},
	{}
};

$ClassInfo _Frame_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.org.objectweb.asm.tree.analysis.Frame",
	"java.lang.Object",
	nullptr,
	_Frame_FieldInfo_,
	_Frame_MethodInfo_,
	"<V::Ljdk/internal/org/objectweb/asm/tree/analysis/Value;>Ljava/lang/Object;"
};

$Object* allocate$Frame($Class* clazz) {
	return $of($alloc(Frame));
}

void Frame::init$(int32_t numLocals, int32_t numStack) {
	$set(this, values, $new($ValueArray, numLocals + numStack));
	this->numLocals = numLocals;
}

void Frame::init$(Frame* frame) {
	Frame::init$($nc(frame)->numLocals, $nc(frame->values)->length - frame->numLocals);
	init(frame);
}

Frame* Frame::init(Frame* frame) {
	$set(this, returnValue, $nc(frame)->returnValue);
	$System::arraycopy(frame->values, 0, this->values, 0, $nc(this->values)->length);
	this->numStack = frame->numStack;
	return this;
}

void Frame::initJumpTarget(int32_t opcode, $LabelNode* target) {
}

void Frame::setReturn($1Value* v) {
	$set(this, returnValue, v);
}

int32_t Frame::getLocals() {
	return this->numLocals;
}

int32_t Frame::getMaxStackSize() {
	return $nc(this->values)->length - this->numLocals;
}

$1Value* Frame::getLocal(int32_t index) {
	$useLocalCurrentObjectStackCache();
	if (index >= this->numLocals) {
		$throwNew($IndexOutOfBoundsException, $$str({"Trying to get an inexistant local variable "_s, $$str(index)}));
	}
	return $nc(this->values)->get(index);
}

void Frame::setLocal(int32_t index, $1Value* value) {
	$useLocalCurrentObjectStackCache();
	if (index >= this->numLocals) {
		$throwNew($IndexOutOfBoundsException, $$str({"Trying to set an inexistant local variable "_s, $$str(index)}));
	}
	$nc(this->values)->set(index, value);
}

int32_t Frame::getStackSize() {
	return this->numStack;
}

$1Value* Frame::getStack(int32_t index) {
	return $nc(this->values)->get(this->numLocals + index);
}

void Frame::setStack(int32_t index, $1Value* value) {
	$nc(this->values)->set(this->numLocals + index, value);
}

void Frame::clearStack() {
	this->numStack = 0;
}

$1Value* Frame::pop() {
	if (this->numStack == 0) {
		$throwNew($IndexOutOfBoundsException, "Cannot pop operand off an empty stack."_s);
	}
	return $nc(this->values)->get(this->numLocals + (--this->numStack));
}

void Frame::push($1Value* value) {
	if (this->numLocals + this->numStack >= $nc(this->values)->length) {
		$throwNew($IndexOutOfBoundsException, "Insufficient maximum stack size."_s);
	}
	$nc(this->values)->set(this->numLocals + (this->numStack++), value);
}

void Frame::execute($AbstractInsnNode* insn, $Interpreter* interpreter) {
	$useLocalCurrentObjectStackCache();
	$var($1Value, value1, nullptr);
	$var($1Value, value2, nullptr);
	$var($1Value, value3, nullptr);
	$var($1Value, value4, nullptr);
	int32_t var = 0;
	{
		$var($List, valueList, nullptr)
		switch ($nc(insn)->getOpcode()) {
		case $Opcodes::NOP:
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
		case $Opcodes::LCONST_0:
			{}
		case $Opcodes::LCONST_1:
			{}
		case $Opcodes::FCONST_0:
			{}
		case $Opcodes::FCONST_1:
			{}
		case $Opcodes::FCONST_2:
			{}
		case $Opcodes::DCONST_0:
			{}
		case $Opcodes::DCONST_1:
			{}
		case $Opcodes::BIPUSH:
			{}
		case $Opcodes::SIPUSH:
			{}
		case $Opcodes::LDC:
			{
				push($($nc(interpreter)->newOperation(insn)));
				break;
			}
		case $Opcodes::ILOAD:
			{}
		case $Opcodes::LLOAD:
			{}
		case $Opcodes::FLOAD:
			{}
		case $Opcodes::DLOAD:
			{}
		case $Opcodes::ALOAD:
			{
				push($($nc(interpreter)->copyOperation(insn, $(getLocal($nc(($cast($VarInsnNode, insn)))->var)))));
				break;
			}
		case $Opcodes::ISTORE:
			{}
		case $Opcodes::LSTORE:
			{}
		case $Opcodes::FSTORE:
			{}
		case $Opcodes::DSTORE:
			{}
		case $Opcodes::ASTORE:
			{
				$assign(value1, $nc(interpreter)->copyOperation(insn, $(pop())));
				var = $nc(($cast($VarInsnNode, insn)))->var;
				setLocal(var, value1);
				if ($nc(value1)->getSize() == 2) {
					setLocal(var + 1, $($nc(interpreter)->newEmptyValue(var + 1)));
				}
				if (var > 0) {
					$var($1Value, local, getLocal(var - 1));
					if (local != nullptr && local->getSize() == 2) {
						setLocal(var - 1, $($nc(interpreter)->newEmptyValue(var - 1)));
					}
				}
				break;
			}
		case $Opcodes::IASTORE:
			{}
		case $Opcodes::LASTORE:
			{}
		case $Opcodes::FASTORE:
			{}
		case $Opcodes::DASTORE:
			{}
		case $Opcodes::AASTORE:
			{}
		case $Opcodes::BASTORE:
			{}
		case $Opcodes::CASTORE:
			{}
		case $Opcodes::SASTORE:
			{
				$assign(value3, pop());
				$assign(value2, pop());
				$assign(value1, pop());
				$nc(interpreter)->ternaryOperation(insn, value1, value2, value3);
				break;
			}
		case $Opcodes::POP:
			{
				if ($nc($(pop()))->getSize() == 2) {
					$throwNew($AnalyzerException, insn, "Illegal use of POP"_s);
				}
				break;
			}
		case $Opcodes::POP2:
			{
				bool var$0 = $nc($(pop()))->getSize() == 1;
				if (var$0 && $nc($(pop()))->getSize() != 1) {
					$throwNew($AnalyzerException, insn, "Illegal use of POP2"_s);
				}
				break;
			}
		case $Opcodes::DUP:
			{
				$assign(value1, pop());
				if ($nc(value1)->getSize() != 1) {
					$throwNew($AnalyzerException, insn, "Illegal use of DUP"_s);
				}
				push(value1);
				push($($nc(interpreter)->copyOperation(insn, value1)));
				break;
			}
		case $Opcodes::DUP_X1:
			{
				$assign(value1, pop());
				$assign(value2, pop());
				bool var$1 = $nc(value1)->getSize() != 1;
				if (var$1 || $nc(value2)->getSize() != 1) {
					$throwNew($AnalyzerException, insn, "Illegal use of DUP_X1"_s);
				}
				push($($nc(interpreter)->copyOperation(insn, value1)));
				push(value2);
				push(value1);
				break;
			}
		case $Opcodes::DUP_X2:
			{
				$assign(value1, pop());
				bool var$2 = $nc(value1)->getSize() == 1;
				if (var$2 && executeDupX2(insn, value1, interpreter)) {
					break;
				}
				$throwNew($AnalyzerException, insn, "Illegal use of DUP_X2"_s);
			}
		case $Opcodes::DUP2:
			{
				$assign(value1, pop());
				if ($nc(value1)->getSize() == 1) {
					$assign(value2, pop());
					if ($nc(value2)->getSize() == 1) {
						push(value2);
						push(value1);
						push($($nc(interpreter)->copyOperation(insn, value2)));
						push($($nc(interpreter)->copyOperation(insn, value1)));
						break;
					}
				} else {
					push(value1);
					push($($nc(interpreter)->copyOperation(insn, value1)));
					break;
				}
				$throwNew($AnalyzerException, insn, "Illegal use of DUP2"_s);
			}
		case $Opcodes::DUP2_X1:
			{
				$assign(value1, pop());
				if ($nc(value1)->getSize() == 1) {
					$assign(value2, pop());
					if ($nc(value2)->getSize() == 1) {
						$assign(value3, pop());
						if ($nc(value3)->getSize() == 1) {
							push($($nc(interpreter)->copyOperation(insn, value2)));
							push($($nc(interpreter)->copyOperation(insn, value1)));
							push(value3);
							push(value2);
							push(value1);
							break;
						}
					}
				} else {
					$assign(value2, pop());
					if ($nc(value2)->getSize() == 1) {
						push($($nc(interpreter)->copyOperation(insn, value1)));
						push(value2);
						push(value1);
						break;
					}
				}
				$throwNew($AnalyzerException, insn, "Illegal use of DUP2_X1"_s);
			}
		case $Opcodes::DUP2_X2:
			{
				$assign(value1, pop());
				if ($nc(value1)->getSize() == 1) {
					$assign(value2, pop());
					if ($nc(value2)->getSize() == 1) {
						$assign(value3, pop());
						if ($nc(value3)->getSize() == 1) {
							$assign(value4, pop());
							if ($nc(value4)->getSize() == 1) {
								push($($nc(interpreter)->copyOperation(insn, value2)));
								push($($nc(interpreter)->copyOperation(insn, value1)));
								push(value4);
								push(value3);
								push(value2);
								push(value1);
								break;
							}
						} else {
							push($($nc(interpreter)->copyOperation(insn, value2)));
							push($($nc(interpreter)->copyOperation(insn, value1)));
							push(value3);
							push(value2);
							push(value1);
							break;
						}
					}
				} else if (executeDupX2(insn, value1, interpreter)) {
					break;
				}
				$throwNew($AnalyzerException, insn, "Illegal use of DUP2_X2"_s);
			}
		case $Opcodes::SWAP:
			{
				$assign(value2, pop());
				$assign(value1, pop());
				bool var$3 = $nc(value1)->getSize() != 1;
				if (var$3 || $nc(value2)->getSize() != 1) {
					$throwNew($AnalyzerException, insn, "Illegal use of SWAP"_s);
				}
				push($($nc(interpreter)->copyOperation(insn, value2)));
				push($($nc(interpreter)->copyOperation(insn, value1)));
				break;
			}
		case $Opcodes::IALOAD:
			{}
		case $Opcodes::LALOAD:
			{}
		case $Opcodes::FALOAD:
			{}
		case $Opcodes::DALOAD:
			{}
		case $Opcodes::AALOAD:
			{}
		case $Opcodes::BALOAD:
			{}
		case $Opcodes::CALOAD:
			{}
		case $Opcodes::SALOAD:
			{}
		case $Opcodes::IADD:
			{}
		case $Opcodes::LADD:
			{}
		case $Opcodes::FADD:
			{}
		case $Opcodes::DADD:
			{}
		case $Opcodes::ISUB:
			{}
		case $Opcodes::LSUB:
			{}
		case $Opcodes::FSUB:
			{}
		case $Opcodes::DSUB:
			{}
		case $Opcodes::IMUL:
			{}
		case $Opcodes::LMUL:
			{}
		case $Opcodes::FMUL:
			{}
		case $Opcodes::DMUL:
			{}
		case $Opcodes::IDIV:
			{}
		case $Opcodes::LDIV:
			{}
		case $Opcodes::FDIV:
			{}
		case $Opcodes::DDIV:
			{}
		case $Opcodes::IREM:
			{}
		case $Opcodes::LREM:
			{}
		case $Opcodes::FREM:
			{}
		case $Opcodes::DREM:
			{}
		case $Opcodes::ISHL:
			{}
		case $Opcodes::LSHL:
			{}
		case $Opcodes::ISHR:
			{}
		case $Opcodes::LSHR:
			{}
		case $Opcodes::IUSHR:
			{}
		case $Opcodes::LUSHR:
			{}
		case $Opcodes::IAND:
			{}
		case $Opcodes::LAND:
			{}
		case $Opcodes::IOR:
			{}
		case $Opcodes::LOR:
			{}
		case $Opcodes::IXOR:
			{}
		case $Opcodes::LXOR:
			{}
		case $Opcodes::LCMP:
			{}
		case $Opcodes::FCMPL:
			{}
		case $Opcodes::FCMPG:
			{}
		case $Opcodes::DCMPL:
			{}
		case $Opcodes::DCMPG:
			{
				$assign(value2, pop());
				$assign(value1, pop());
				push($($nc(interpreter)->binaryOperation(insn, value1, value2)));
				break;
			}
		case $Opcodes::INEG:
			{}
		case $Opcodes::LNEG:
			{}
		case $Opcodes::FNEG:
			{}
		case $Opcodes::DNEG:
			{
				push($($nc(interpreter)->unaryOperation(insn, $(pop()))));
				break;
			}
		case $Opcodes::IINC:
			{
				var = $nc(($cast($IincInsnNode, insn)))->var;
				setLocal(var, $($nc(interpreter)->unaryOperation(insn, $(getLocal(var)))));
				break;
			}
		case $Opcodes::I2L:
			{}
		case $Opcodes::I2F:
			{}
		case $Opcodes::I2D:
			{}
		case $Opcodes::L2I:
			{}
		case $Opcodes::L2F:
			{}
		case $Opcodes::L2D:
			{}
		case $Opcodes::F2I:
			{}
		case $Opcodes::F2L:
			{}
		case $Opcodes::F2D:
			{}
		case $Opcodes::D2I:
			{}
		case $Opcodes::D2L:
			{}
		case $Opcodes::D2F:
			{}
		case $Opcodes::I2B:
			{}
		case $Opcodes::I2C:
			{}
		case $Opcodes::I2S:
			{
				push($($nc(interpreter)->unaryOperation(insn, $(pop()))));
				break;
			}
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
			{
				$nc(interpreter)->unaryOperation(insn, $(pop()));
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
			{}
		case $Opcodes::PUTFIELD:
			{
				$assign(value2, pop());
				$assign(value1, pop());
				$nc(interpreter)->binaryOperation(insn, value1, value2);
				break;
			}
		case $Opcodes::GOTO:
			{
				break;
			}
		case $Opcodes::JSR:
			{
				push($($nc(interpreter)->newOperation(insn)));
				break;
			}
		case $Opcodes::RET:
			{
				break;
			}
		case $Opcodes::TABLESWITCH:
			{}
		case $Opcodes::LOOKUPSWITCH:
			{
				$nc(interpreter)->unaryOperation(insn, $(pop()));
				break;
			}
		case $Opcodes::IRETURN:
			{}
		case $Opcodes::LRETURN:
			{}
		case $Opcodes::FRETURN:
			{}
		case $Opcodes::DRETURN:
			{}
		case $Opcodes::ARETURN:
			{
				$assign(value1, pop());
				$nc(interpreter)->unaryOperation(insn, value1);
				$nc(interpreter)->returnOperation(insn, value1, this->returnValue);
				break;
			}
		case $Opcodes::RETURN:
			{
				if (this->returnValue != nullptr) {
					$throwNew($AnalyzerException, insn, "Incompatible return type"_s);
				}
				break;
			}
		case $Opcodes::GETSTATIC:
			{
				push($($nc(interpreter)->newOperation(insn)));
				break;
			}
		case $Opcodes::PUTSTATIC:
			{
				$nc(interpreter)->unaryOperation(insn, $(pop()));
				break;
			}
		case $Opcodes::GETFIELD:
			{
				push($($nc(interpreter)->unaryOperation(insn, $(pop()))));
				break;
			}
		case $Opcodes::INVOKEVIRTUAL:
			{}
		case $Opcodes::INVOKESPECIAL:
			{}
		case $Opcodes::INVOKESTATIC:
			{}
		case $Opcodes::INVOKEINTERFACE:
			{
				executeInvokeInsn(insn, $nc(($cast($MethodInsnNode, insn)))->desc, interpreter);
				break;
			}
		case $Opcodes::INVOKEDYNAMIC:
			{
				executeInvokeInsn(insn, $nc(($cast($InvokeDynamicInsnNode, insn)))->desc, interpreter);
				break;
			}
		case $Opcodes::NEW:
			{
				push($($nc(interpreter)->newOperation(insn)));
				break;
			}
		case $Opcodes::NEWARRAY:
			{}
		case $Opcodes::ANEWARRAY:
			{}
		case $Opcodes::ARRAYLENGTH:
			{
				push($($nc(interpreter)->unaryOperation(insn, $(pop()))));
				break;
			}
		case $Opcodes::ATHROW:
			{
				$nc(interpreter)->unaryOperation(insn, $(pop()));
				break;
			}
		case $Opcodes::CHECKCAST:
			{}
		case $Opcodes::INSTANCEOF:
			{
				push($($nc(interpreter)->unaryOperation(insn, $(pop()))));
				break;
			}
		case $Opcodes::MONITORENTER:
			{}
		case $Opcodes::MONITOREXIT:
			{
				$nc(interpreter)->unaryOperation(insn, $(pop()));
				break;
			}
		case $Opcodes::MULTIANEWARRAY:
			{
				$assign(valueList, $new($ArrayList));
				for (int32_t i = $nc(($cast($MultiANewArrayInsnNode, insn)))->dims; i > 0; --i) {
					$nc(valueList)->add(0, $(pop()));
				}
				push($($nc(interpreter)->naryOperation(insn, valueList)));
				break;
			}
		case $Opcodes::IFNULL:
			{}
		case $Opcodes::IFNONNULL:
			{
				$nc(interpreter)->unaryOperation(insn, $(pop()));
				break;
			}
		default:
			{
				$throwNew($AnalyzerException, insn, $$str({"Illegal opcode "_s, $$str(insn->getOpcode())}));
			}
		}
	}
}

bool Frame::executeDupX2($AbstractInsnNode* insn, $1Value* value1, $Interpreter* interpreter) {
	$useLocalCurrentObjectStackCache();
	$var($1Value, value2, pop());
	if ($nc(value2)->getSize() == 1) {
		$var($1Value, value3, pop());
		if ($nc(value3)->getSize() == 1) {
			push($($nc(interpreter)->copyOperation(insn, value1)));
			push(value3);
			push(value2);
			push(value1);
			return true;
		}
	} else {
		push($($nc(interpreter)->copyOperation(insn, value1)));
		push(value2);
		push(value1);
		return true;
	}
	return false;
}

void Frame::executeInvokeInsn($AbstractInsnNode* insn, $String* methodDescriptor, $Interpreter* interpreter) {
	$useLocalCurrentObjectStackCache();
	$var($ArrayList, valueList, $new($ArrayList));
	for (int32_t i = $nc($($Type::getArgumentTypes(methodDescriptor)))->length; i > 0; --i) {
		valueList->add(0, $(pop()));
	}
	bool var$0 = $nc(insn)->getOpcode() != $Opcodes::INVOKESTATIC;
	if (var$0 && insn->getOpcode() != $Opcodes::INVOKEDYNAMIC) {
		valueList->add(0, $(pop()));
	}
	if ($Type::getReturnType(methodDescriptor) == $Type::VOID_TYPE) {
		$nc(interpreter)->naryOperation(insn, valueList);
	} else {
		push($($nc(interpreter)->naryOperation(insn, valueList)));
	}
}

bool Frame::merge(Frame* frame, $Interpreter* interpreter) {
	$useLocalCurrentObjectStackCache();
	if (this->numStack != $nc(frame)->numStack) {
		$throwNew($AnalyzerException, nullptr, "Incompatible stack heights"_s);
	}
	bool changed = false;
	for (int32_t i = 0; i < this->numLocals + this->numStack; ++i) {
		$var($1Value, v, $nc(interpreter)->merge($nc(this->values)->get(i), $nc($nc(frame)->values)->get(i)));
		if (!$nc($of(v))->equals($nc(this->values)->get(i))) {
			$nc(this->values)->set(i, v);
			changed = true;
		}
	}
	return changed;
}

bool Frame::merge(Frame* frame, $booleans* localsUsed) {
	bool changed = false;
	for (int32_t i = 0; i < this->numLocals; ++i) {
		if (!$nc(localsUsed)->get(i) && !$nc($of($nc(this->values)->get(i)))->equals($nc($nc(frame)->values)->get(i))) {
			$nc(this->values)->set(i, $nc($nc(frame)->values)->get(i));
			changed = true;
		}
	}
	return changed;
}

$String* Frame::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, stringBuilder, $new($StringBuilder));
	for (int32_t i = 0; i < getLocals(); ++i) {
		stringBuilder->append($($of(getLocal(i))));
	}
	stringBuilder->append(u' ');
	for (int32_t i = 0; i < getStackSize(); ++i) {
		stringBuilder->append($($nc($of($(getStack(i))))->toString()));
	}
	return stringBuilder->toString();
}

Frame::Frame() {
}

$Class* Frame::load$($String* name, bool initialize) {
	$loadClass(Frame, name, initialize, &_Frame_ClassInfo_, allocate$Frame);
	return class$;
}

$Class* Frame::class$ = nullptr;

						} // analysis
					} // tree
				} // asm$
			} // objectweb
		} // org
	} // internal
} // jdk