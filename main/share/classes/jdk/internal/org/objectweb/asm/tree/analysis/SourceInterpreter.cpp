#include <jdk/internal/org/objectweb/asm/tree/analysis/SourceInterpreter.h>

#include <java/lang/IllegalStateException.h>
#include <java/lang/Math.h>
#include <java/util/AbstractCollection.h>
#include <java/util/Collection.h>
#include <java/util/HashSet.h>
#include <java/util/List.h>
#include <java/util/Set.h>
#include <jdk/internal/org/objectweb/asm/Opcodes.h>
#include <jdk/internal/org/objectweb/asm/Type.h>
#include <jdk/internal/org/objectweb/asm/tree/AbstractInsnNode.h>
#include <jdk/internal/org/objectweb/asm/tree/FieldInsnNode.h>
#include <jdk/internal/org/objectweb/asm/tree/InvokeDynamicInsnNode.h>
#include <jdk/internal/org/objectweb/asm/tree/LdcInsnNode.h>
#include <jdk/internal/org/objectweb/asm/tree/MethodInsnNode.h>
#include <jdk/internal/org/objectweb/asm/tree/analysis/Interpreter.h>
#include <jdk/internal/org/objectweb/asm/tree/analysis/SmallSet.h>
#include <jdk/internal/org/objectweb/asm/tree/analysis/SourceValue.h>
#include <jdk/internal/org/objectweb/asm/tree/analysis/Value.h>
#include <jcpp.h>

#undef ASM8
#undef D2L
#undef DADD
#undef DALOAD
#undef DCONST_0
#undef DCONST_1
#undef DDIV
#undef DMUL
#undef DNEG
#undef DREM
#undef DSUB
#undef F2D
#undef F2L
#undef GETFIELD
#undef GETSTATIC
#undef I2D
#undef I2L
#undef INVOKEDYNAMIC
#undef L2D
#undef LADD
#undef LALOAD
#undef LAND
#undef LCONST_0
#undef LCONST_1
#undef LDC
#undef LDIV
#undef LMUL
#undef LNEG
#undef LOR
#undef LREM
#undef LSHL
#undef LSHR
#undef LSUB
#undef LUSHR
#undef LXOR
#undef MULTIANEWARRAY
#undef VOID_TYPE

using $ClassInfo = ::java::lang::ClassInfo;
using $Double = ::java::lang::Double;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $Collection = ::java::util::Collection;
using $HashSet = ::java::util::HashSet;
using $List = ::java::util::List;
using $Set = ::java::util::Set;
using $Opcodes = ::jdk::internal::org::objectweb::asm$::Opcodes;
using $Type = ::jdk::internal::org::objectweb::asm$::Type;
using $AbstractInsnNode = ::jdk::internal::org::objectweb::asm$::tree::AbstractInsnNode;
using $FieldInsnNode = ::jdk::internal::org::objectweb::asm$::tree::FieldInsnNode;
using $InvokeDynamicInsnNode = ::jdk::internal::org::objectweb::asm$::tree::InvokeDynamicInsnNode;
using $LdcInsnNode = ::jdk::internal::org::objectweb::asm$::tree::LdcInsnNode;
using $MethodInsnNode = ::jdk::internal::org::objectweb::asm$::tree::MethodInsnNode;
using $Interpreter = ::jdk::internal::org::objectweb::asm$::tree::analysis::Interpreter;
using $SmallSet = ::jdk::internal::org::objectweb::asm$::tree::analysis::SmallSet;
using $SourceValue = ::jdk::internal::org::objectweb::asm$::tree::analysis::SourceValue;
using $1Value = ::jdk::internal::org::objectweb::asm$::tree::analysis::Value;

namespace jdk {
	namespace internal {
		namespace org {
			namespace objectweb {
				namespace asm$ {
					namespace tree {
						namespace analysis {

$MethodInfo _SourceInterpreter_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, $PUBLIC, $method(SourceInterpreter, init$, void)},
	{"<init>", "(I)V", nullptr, $PROTECTED, $method(SourceInterpreter, init$, void, int32_t)},
	{"binaryOperation", "(Ljdk/internal/org/objectweb/asm/tree/AbstractInsnNode;Ljdk/internal/org/objectweb/asm/tree/analysis/SourceValue;Ljdk/internal/org/objectweb/asm/tree/analysis/SourceValue;)Ljdk/internal/org/objectweb/asm/tree/analysis/SourceValue;", nullptr, $PUBLIC, $virtualMethod(SourceInterpreter, binaryOperation, $SourceValue*, $AbstractInsnNode*, $SourceValue*, $SourceValue*)},
	{"binaryOperation", "(Ljdk/internal/org/objectweb/asm/tree/AbstractInsnNode;Ljdk/internal/org/objectweb/asm/tree/analysis/Value;Ljdk/internal/org/objectweb/asm/tree/analysis/Value;)Ljdk/internal/org/objectweb/asm/tree/analysis/Value;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(SourceInterpreter, binaryOperation, $1Value*, $AbstractInsnNode*, $1Value*, $1Value*), "jdk.internal.org.objectweb.asm.tree.analysis.AnalyzerException"},
	{"containsAll", "(Ljava/util/Set;Ljava/util/Set;)Z", "<E:Ljava/lang/Object;>(Ljava/util/Set<TE;>;Ljava/util/Set<TE;>;)Z", $PRIVATE | $STATIC, $staticMethod(SourceInterpreter, containsAll, bool, $Set*, $Set*)},
	{"copyOperation", "(Ljdk/internal/org/objectweb/asm/tree/AbstractInsnNode;Ljdk/internal/org/objectweb/asm/tree/analysis/SourceValue;)Ljdk/internal/org/objectweb/asm/tree/analysis/SourceValue;", nullptr, $PUBLIC, $virtualMethod(SourceInterpreter, copyOperation, $SourceValue*, $AbstractInsnNode*, $SourceValue*)},
	{"copyOperation", "(Ljdk/internal/org/objectweb/asm/tree/AbstractInsnNode;Ljdk/internal/org/objectweb/asm/tree/analysis/Value;)Ljdk/internal/org/objectweb/asm/tree/analysis/Value;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(SourceInterpreter, copyOperation, $1Value*, $AbstractInsnNode*, $1Value*), "jdk.internal.org.objectweb.asm.tree.analysis.AnalyzerException"},
	{"merge", "(Ljdk/internal/org/objectweb/asm/tree/analysis/SourceValue;Ljdk/internal/org/objectweb/asm/tree/analysis/SourceValue;)Ljdk/internal/org/objectweb/asm/tree/analysis/SourceValue;", nullptr, $PUBLIC, $virtualMethod(SourceInterpreter, merge, $SourceValue*, $SourceValue*, $SourceValue*)},
	{"merge", "(Ljdk/internal/org/objectweb/asm/tree/analysis/Value;Ljdk/internal/org/objectweb/asm/tree/analysis/Value;)Ljdk/internal/org/objectweb/asm/tree/analysis/Value;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(SourceInterpreter, merge, $1Value*, $1Value*, $1Value*)},
	{"naryOperation", "(Ljdk/internal/org/objectweb/asm/tree/AbstractInsnNode;Ljava/util/List;)Ljdk/internal/org/objectweb/asm/tree/analysis/SourceValue;", "(Ljdk/internal/org/objectweb/asm/tree/AbstractInsnNode;Ljava/util/List<+Ljdk/internal/org/objectweb/asm/tree/analysis/SourceValue;>;)Ljdk/internal/org/objectweb/asm/tree/analysis/SourceValue;", $PUBLIC, $virtualMethod(SourceInterpreter, naryOperation, $1Value*, $AbstractInsnNode*, $List*)},
	{"newOperation", "(Ljdk/internal/org/objectweb/asm/tree/AbstractInsnNode;)Ljdk/internal/org/objectweb/asm/tree/analysis/SourceValue;", nullptr, $PUBLIC, $virtualMethod(SourceInterpreter, newOperation, $1Value*, $AbstractInsnNode*)},
	{"newValue", "(Ljdk/internal/org/objectweb/asm/Type;)Ljdk/internal/org/objectweb/asm/tree/analysis/SourceValue;", nullptr, $PUBLIC, $virtualMethod(SourceInterpreter, newValue, $1Value*, $Type*)},
	{"returnOperation", "(Ljdk/internal/org/objectweb/asm/tree/AbstractInsnNode;Ljdk/internal/org/objectweb/asm/tree/analysis/SourceValue;Ljdk/internal/org/objectweb/asm/tree/analysis/SourceValue;)V", nullptr, $PUBLIC, $virtualMethod(SourceInterpreter, returnOperation, void, $AbstractInsnNode*, $SourceValue*, $SourceValue*)},
	{"returnOperation", "(Ljdk/internal/org/objectweb/asm/tree/AbstractInsnNode;Ljdk/internal/org/objectweb/asm/tree/analysis/Value;Ljdk/internal/org/objectweb/asm/tree/analysis/Value;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(SourceInterpreter, returnOperation, void, $AbstractInsnNode*, $1Value*, $1Value*), "jdk.internal.org.objectweb.asm.tree.analysis.AnalyzerException"},
	{"ternaryOperation", "(Ljdk/internal/org/objectweb/asm/tree/AbstractInsnNode;Ljdk/internal/org/objectweb/asm/tree/analysis/SourceValue;Ljdk/internal/org/objectweb/asm/tree/analysis/SourceValue;Ljdk/internal/org/objectweb/asm/tree/analysis/SourceValue;)Ljdk/internal/org/objectweb/asm/tree/analysis/SourceValue;", nullptr, $PUBLIC, $virtualMethod(SourceInterpreter, ternaryOperation, $SourceValue*, $AbstractInsnNode*, $SourceValue*, $SourceValue*, $SourceValue*)},
	{"ternaryOperation", "(Ljdk/internal/org/objectweb/asm/tree/AbstractInsnNode;Ljdk/internal/org/objectweb/asm/tree/analysis/Value;Ljdk/internal/org/objectweb/asm/tree/analysis/Value;Ljdk/internal/org/objectweb/asm/tree/analysis/Value;)Ljdk/internal/org/objectweb/asm/tree/analysis/Value;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(SourceInterpreter, ternaryOperation, $1Value*, $AbstractInsnNode*, $1Value*, $1Value*, $1Value*), "jdk.internal.org.objectweb.asm.tree.analysis.AnalyzerException"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"unaryOperation", "(Ljdk/internal/org/objectweb/asm/tree/AbstractInsnNode;Ljdk/internal/org/objectweb/asm/tree/analysis/SourceValue;)Ljdk/internal/org/objectweb/asm/tree/analysis/SourceValue;", nullptr, $PUBLIC, $virtualMethod(SourceInterpreter, unaryOperation, $SourceValue*, $AbstractInsnNode*, $SourceValue*)},
	{"unaryOperation", "(Ljdk/internal/org/objectweb/asm/tree/AbstractInsnNode;Ljdk/internal/org/objectweb/asm/tree/analysis/Value;)Ljdk/internal/org/objectweb/asm/tree/analysis/Value;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(SourceInterpreter, unaryOperation, $1Value*, $AbstractInsnNode*, $1Value*), "jdk.internal.org.objectweb.asm.tree.analysis.AnalyzerException"},
	{}
};

$ClassInfo _SourceInterpreter_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.org.objectweb.asm.tree.analysis.SourceInterpreter",
	"jdk.internal.org.objectweb.asm.tree.analysis.Interpreter",
	"jdk.internal.org.objectweb.asm.Opcodes",
	nullptr,
	_SourceInterpreter_MethodInfo_,
	"Ljdk/internal/org/objectweb/asm/tree/analysis/Interpreter<Ljdk/internal/org/objectweb/asm/tree/analysis/SourceValue;>;Ljdk/internal/org/objectweb/asm/Opcodes;"
};

$Object* allocate$SourceInterpreter($Class* clazz) {
	return $of($alloc(SourceInterpreter));
}

int32_t SourceInterpreter::hashCode() {
	 return this->$Interpreter::hashCode();
}

bool SourceInterpreter::equals(Object$* obj) {
	 return this->$Interpreter::equals(obj);
}

$Object* SourceInterpreter::clone() {
	 return this->$Interpreter::clone();
}

$String* SourceInterpreter::toString() {
	 return this->$Interpreter::toString();
}

void SourceInterpreter::finalize() {
	this->$Interpreter::finalize();
}

void SourceInterpreter::init$() {
	$Interpreter::init$($Opcodes::ASM8);
	if ($of(this)->getClass() != SourceInterpreter::class$) {
		$throwNew($IllegalStateException);
	}
}

void SourceInterpreter::init$(int32_t api) {
	$Interpreter::init$(api);
}

$1Value* SourceInterpreter::newValue($Type* type) {
	$init($Type);
	if (type == $Type::VOID_TYPE) {
		return nullptr;
	}
	return $new($SourceValue, type == nullptr ? 1 : $nc(type)->getSize());
}

$1Value* SourceInterpreter::newOperation($AbstractInsnNode* insn) {
	$useLocalCurrentObjectStackCache();
	int32_t size = 0;
	{
		$var($Object, value, nullptr)
		switch ($nc(insn)->getOpcode()) {
		case $Opcodes::LCONST_0:
			{}
		case $Opcodes::LCONST_1:
			{}
		case $Opcodes::DCONST_0:
			{}
		case $Opcodes::DCONST_1:
			{
				size = 2;
				break;
			}
		case $Opcodes::LDC:
			{
				$assign(value, $nc(($cast($LdcInsnNode, insn)))->cst);
				size = $instanceOf($Long, value) || $instanceOf($Double, value) ? 2 : 1;
				break;
			}
		case $Opcodes::GETSTATIC:
			{
				size = $nc($($Type::getType($nc(($cast($FieldInsnNode, insn)))->desc)))->getSize();
				break;
			}
		default:
			{
				size = 1;
				break;
			}
		}
	}
	return $new($SourceValue, size, insn);
}

$SourceValue* SourceInterpreter::copyOperation($AbstractInsnNode* insn, $SourceValue* value) {
	return $new($SourceValue, $nc(value)->getSize(), insn);
}

$SourceValue* SourceInterpreter::unaryOperation($AbstractInsnNode* insn, $SourceValue* value) {
	int32_t size = 0;
	switch ($nc(insn)->getOpcode()) {
	case $Opcodes::LNEG:
		{}
	case $Opcodes::DNEG:
		{}
	case $Opcodes::I2L:
		{}
	case $Opcodes::I2D:
		{}
	case $Opcodes::L2D:
		{}
	case $Opcodes::F2L:
		{}
	case $Opcodes::F2D:
		{}
	case $Opcodes::D2L:
		{
			size = 2;
			break;
		}
	case $Opcodes::GETFIELD:
		{
			size = $nc($($Type::getType($nc(($cast($FieldInsnNode, insn)))->desc)))->getSize();
			break;
		}
	default:
		{
			size = 1;
			break;
		}
	}
	return $new($SourceValue, size, insn);
}

$SourceValue* SourceInterpreter::binaryOperation($AbstractInsnNode* insn, $SourceValue* value1, $SourceValue* value2) {
	int32_t size = 0;
	switch ($nc(insn)->getOpcode()) {
	case $Opcodes::LALOAD:
		{}
	case $Opcodes::DALOAD:
		{}
	case $Opcodes::LADD:
		{}
	case $Opcodes::DADD:
		{}
	case $Opcodes::LSUB:
		{}
	case $Opcodes::DSUB:
		{}
	case $Opcodes::LMUL:
		{}
	case $Opcodes::DMUL:
		{}
	case $Opcodes::LDIV:
		{}
	case $Opcodes::DDIV:
		{}
	case $Opcodes::LREM:
		{}
	case $Opcodes::DREM:
		{}
	case $Opcodes::LSHL:
		{}
	case $Opcodes::LSHR:
		{}
	case $Opcodes::LUSHR:
		{}
	case $Opcodes::LAND:
		{}
	case $Opcodes::LOR:
		{}
	case $Opcodes::LXOR:
		{
			size = 2;
			break;
		}
	default:
		{
			size = 1;
			break;
		}
	}
	return $new($SourceValue, size, insn);
}

$SourceValue* SourceInterpreter::ternaryOperation($AbstractInsnNode* insn, $SourceValue* value1, $SourceValue* value2, $SourceValue* value3) {
	return $new($SourceValue, 1, insn);
}

$1Value* SourceInterpreter::naryOperation($AbstractInsnNode* insn, $List* values) {
	$useLocalCurrentObjectStackCache();
	int32_t size = 0;
	int32_t opcode = $nc(insn)->getOpcode();
	if (opcode == $Opcodes::MULTIANEWARRAY) {
		size = 1;
	} else if (opcode == $Opcodes::INVOKEDYNAMIC) {
		size = $nc($($Type::getReturnType($nc(($cast($InvokeDynamicInsnNode, insn)))->desc)))->getSize();
	} else {
		size = $nc($($Type::getReturnType($nc(($cast($MethodInsnNode, insn)))->desc)))->getSize();
	}
	return $new($SourceValue, size, insn);
}

void SourceInterpreter::returnOperation($AbstractInsnNode* insn, $SourceValue* value, $SourceValue* expected) {
}

$SourceValue* SourceInterpreter::merge($SourceValue* value1, $SourceValue* value2) {
	$useLocalCurrentObjectStackCache();
	if ($instanceOf($SmallSet, $nc(value1)->insns) && $instanceOf($SmallSet, $nc(value2)->insns)) {
		$var($Set, setUnion, $nc(($cast($SmallSet, value1->insns)))->union$($cast($SmallSet, value2->insns)));
		if (setUnion == value1->insns && value1->size == value2->size) {
			return value1;
		} else {
			return $new($SourceValue, $Math::min(value1->size, value2->size), setUnion);
		}
	}
	if ($nc(value1)->size != $nc(value2)->size || !containsAll($nc(value1)->insns, $nc(value2)->insns)) {
		$var($HashSet, setUnion, $new($HashSet));
		setUnion->addAll($nc(value1)->insns);
		setUnion->addAll($nc(value2)->insns);
		return $new($SourceValue, $Math::min($nc(value1)->size, $nc(value2)->size), static_cast<$Set*>(setUnion));
	}
	return value1;
}

bool SourceInterpreter::containsAll($Set* self, $Set* other) {
	$init(SourceInterpreter);
	int32_t var$0 = $nc(self)->size();
	if (var$0 < $nc(other)->size()) {
		return false;
	}
	return $nc(self)->containsAll(other);
}

$1Value* SourceInterpreter::merge($1Value* value1, $1Value* value2) {
	return this->merge($cast($SourceValue, value1), $cast($SourceValue, value2));
}

void SourceInterpreter::returnOperation($AbstractInsnNode* insn, $1Value* value, $1Value* expected) {
	this->returnOperation(insn, $cast($SourceValue, value), $cast($SourceValue, expected));
}

$1Value* SourceInterpreter::ternaryOperation($AbstractInsnNode* insn, $1Value* value1, $1Value* value2, $1Value* value3) {
	return this->ternaryOperation(insn, $cast($SourceValue, value1), $cast($SourceValue, value2), $cast($SourceValue, value3));
}

$1Value* SourceInterpreter::binaryOperation($AbstractInsnNode* insn, $1Value* value1, $1Value* value2) {
	return this->binaryOperation(insn, $cast($SourceValue, value1), $cast($SourceValue, value2));
}

$1Value* SourceInterpreter::unaryOperation($AbstractInsnNode* insn, $1Value* value) {
	return this->unaryOperation(insn, $cast($SourceValue, value));
}

$1Value* SourceInterpreter::copyOperation($AbstractInsnNode* insn, $1Value* value) {
	return this->copyOperation(insn, $cast($SourceValue, value));
}

SourceInterpreter::SourceInterpreter() {
}

$Class* SourceInterpreter::load$($String* name, bool initialize) {
	$loadClass(SourceInterpreter, name, initialize, &_SourceInterpreter_ClassInfo_, allocate$SourceInterpreter);
	return class$;
}

$Class* SourceInterpreter::class$ = nullptr;

						} // analysis
					} // tree
				} // asm$
			} // objectweb
		} // org
	} // internal
} // jdk