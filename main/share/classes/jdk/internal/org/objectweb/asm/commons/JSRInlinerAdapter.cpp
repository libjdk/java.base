#include <jdk/internal/org/objectweb/asm/commons/JSRInlinerAdapter.h>

#include <java/lang/AssertionError.h>
#include <java/lang/IllegalStateException.h>
#include <java/util/AbstractCollection.h>
#include <java/util/ArrayList.h>
#include <java/util/BitSet.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedList.h>
#include <java/util/List.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <jdk/internal/org/objectweb/asm/Label.h>
#include <jdk/internal/org/objectweb/asm/MethodVisitor.h>
#include <jdk/internal/org/objectweb/asm/Opcodes.h>
#include <jdk/internal/org/objectweb/asm/commons/JSRInlinerAdapter$Instantiation.h>
#include <jdk/internal/org/objectweb/asm/tree/AbstractInsnNode.h>
#include <jdk/internal/org/objectweb/asm/tree/InsnList.h>
#include <jdk/internal/org/objectweb/asm/tree/InsnNode.h>
#include <jdk/internal/org/objectweb/asm/tree/JumpInsnNode.h>
#include <jdk/internal/org/objectweb/asm/tree/LabelNode.h>
#include <jdk/internal/org/objectweb/asm/tree/LocalVariableNode.h>
#include <jdk/internal/org/objectweb/asm/tree/LookupSwitchInsnNode.h>
#include <jdk/internal/org/objectweb/asm/tree/MethodNode.h>
#include <jdk/internal/org/objectweb/asm/tree/TableSwitchInsnNode.h>
#include <jdk/internal/org/objectweb/asm/tree/TryCatchBlockNode.h>
#include <jcpp.h>

#undef ACONST_NULL
#undef ARETURN
#undef ASM8
#undef ATHROW
#undef DRETURN
#undef FRETURN
#undef GOTO
#undef IRETURN
#undef JSR
#undef JUMP_INSN
#undef LABEL
#undef LOOKUPSWITCH
#undef LOOKUPSWITCH_INSN
#undef LRETURN
#undef RET
#undef RETURN
#undef TABLESWITCH
#undef TABLESWITCH_INSN

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ArrayList = ::java::util::ArrayList;
using $BitSet = ::java::util::BitSet;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $LinkedList = ::java::util::LinkedList;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;
using $Label = ::jdk::internal::org::objectweb::asm$::Label;
using $MethodVisitor = ::jdk::internal::org::objectweb::asm$::MethodVisitor;
using $Opcodes = ::jdk::internal::org::objectweb::asm$::Opcodes;
using $JSRInlinerAdapter$Instantiation = ::jdk::internal::org::objectweb::asm$::commons::JSRInlinerAdapter$Instantiation;
using $AbstractInsnNode = ::jdk::internal::org::objectweb::asm$::tree::AbstractInsnNode;
using $InsnList = ::jdk::internal::org::objectweb::asm$::tree::InsnList;
using $InsnNode = ::jdk::internal::org::objectweb::asm$::tree::InsnNode;
using $JumpInsnNode = ::jdk::internal::org::objectweb::asm$::tree::JumpInsnNode;
using $LabelNode = ::jdk::internal::org::objectweb::asm$::tree::LabelNode;
using $LocalVariableNode = ::jdk::internal::org::objectweb::asm$::tree::LocalVariableNode;
using $LookupSwitchInsnNode = ::jdk::internal::org::objectweb::asm$::tree::LookupSwitchInsnNode;
using $MethodNode = ::jdk::internal::org::objectweb::asm$::tree::MethodNode;
using $TableSwitchInsnNode = ::jdk::internal::org::objectweb::asm$::tree::TableSwitchInsnNode;
using $TryCatchBlockNode = ::jdk::internal::org::objectweb::asm$::tree::TryCatchBlockNode;

namespace jdk {
	namespace internal {
		namespace org {
			namespace objectweb {
				namespace asm$ {
					namespace commons {

$FieldInfo _JSRInlinerAdapter_FieldInfo_[] = {
	{"mainSubroutineInsns", "Ljava/util/BitSet;", nullptr, $PRIVATE | $FINAL, $field(JSRInlinerAdapter, mainSubroutineInsns)},
	{"subroutinesInsns", "Ljava/util/Map;", "Ljava/util/Map<Ljdk/internal/org/objectweb/asm/tree/LabelNode;Ljava/util/BitSet;>;", $PRIVATE | $FINAL, $field(JSRInlinerAdapter, subroutinesInsns)},
	{"sharedSubroutineInsns", "Ljava/util/BitSet;", nullptr, $FINAL, $field(JSRInlinerAdapter, sharedSubroutineInsns)},
	{}
};

$MethodInfo _JSRInlinerAdapter_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljdk/internal/org/objectweb/asm/MethodVisitor;ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;[Ljava/lang/String;)V", nullptr, $PUBLIC, $method(JSRInlinerAdapter, init$, void, $MethodVisitor*, int32_t, $String*, $String*, $String*, $StringArray*)},
	{"<init>", "(ILjdk/internal/org/objectweb/asm/MethodVisitor;ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;[Ljava/lang/String;)V", nullptr, $PROTECTED, $method(JSRInlinerAdapter, init$, void, int32_t, $MethodVisitor*, int32_t, $String*, $String*, $String*, $StringArray*)},
	{"emitCode", "()V", nullptr, $PRIVATE, $method(JSRInlinerAdapter, emitCode, void)},
	{"emitInstantiation", "(Ljdk/internal/org/objectweb/asm/commons/JSRInlinerAdapter$Instantiation;Ljava/util/List;Ljdk/internal/org/objectweb/asm/tree/InsnList;Ljava/util/List;Ljava/util/List;)V", "(Ljdk/internal/org/objectweb/asm/commons/JSRInlinerAdapter$Instantiation;Ljava/util/List<Ljdk/internal/org/objectweb/asm/commons/JSRInlinerAdapter$Instantiation;>;Ljdk/internal/org/objectweb/asm/tree/InsnList;Ljava/util/List<Ljdk/internal/org/objectweb/asm/tree/TryCatchBlockNode;>;Ljava/util/List<Ljdk/internal/org/objectweb/asm/tree/LocalVariableNode;>;)V", $PRIVATE, $method(JSRInlinerAdapter, emitInstantiation, void, $JSRInlinerAdapter$Instantiation*, $List*, $InsnList*, $List*, $List*)},
	{"findReachableInsns", "(ILjava/util/BitSet;Ljava/util/BitSet;)V", nullptr, $PRIVATE, $method(JSRInlinerAdapter, findReachableInsns, void, int32_t, $BitSet*, $BitSet*)},
	{"findSubroutineInsns", "(ILjava/util/BitSet;Ljava/util/BitSet;)V", nullptr, $PRIVATE, $method(JSRInlinerAdapter, findSubroutineInsns, void, int32_t, $BitSet*, $BitSet*)},
	{"findSubroutinesInsns", "()V", nullptr, $PRIVATE, $method(JSRInlinerAdapter, findSubroutinesInsns, void)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"visitEnd", "()V", nullptr, $PUBLIC, $virtualMethod(JSRInlinerAdapter, visitEnd, void)},
	{"visitJumpInsn", "(ILjdk/internal/org/objectweb/asm/Label;)V", nullptr, $PUBLIC, $virtualMethod(JSRInlinerAdapter, visitJumpInsn, void, int32_t, $Label*)},
	{}
};

$InnerClassInfo _JSRInlinerAdapter_InnerClassesInfo_[] = {
	{"jdk.internal.org.objectweb.asm.commons.JSRInlinerAdapter$Instantiation", "jdk.internal.org.objectweb.asm.commons.JSRInlinerAdapter", "Instantiation", $PRIVATE},
	{}
};

$ClassInfo _JSRInlinerAdapter_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.org.objectweb.asm.commons.JSRInlinerAdapter",
	"jdk.internal.org.objectweb.asm.tree.MethodNode",
	"jdk.internal.org.objectweb.asm.Opcodes",
	_JSRInlinerAdapter_FieldInfo_,
	_JSRInlinerAdapter_MethodInfo_,
	nullptr,
	nullptr,
	_JSRInlinerAdapter_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.org.objectweb.asm.commons.JSRInlinerAdapter$Instantiation"
};

$Object* allocate$JSRInlinerAdapter($Class* clazz) {
	return $of($alloc(JSRInlinerAdapter));
}

int32_t JSRInlinerAdapter::hashCode() {
	 return this->$MethodNode::hashCode();
}

bool JSRInlinerAdapter::equals(Object$* obj) {
	 return this->$MethodNode::equals(obj);
}

$Object* JSRInlinerAdapter::clone() {
	 return this->$MethodNode::clone();
}

$String* JSRInlinerAdapter::toString() {
	 return this->$MethodNode::toString();
}

void JSRInlinerAdapter::finalize() {
	this->$MethodNode::finalize();
}

void JSRInlinerAdapter::init$($MethodVisitor* methodVisitor, int32_t access, $String* name, $String* descriptor, $String* signature, $StringArray* exceptions) {
	JSRInlinerAdapter::init$($Opcodes::ASM8, methodVisitor, access, name, descriptor, signature, exceptions);
	if ($of(this)->getClass() != JSRInlinerAdapter::class$) {
		$throwNew($IllegalStateException);
	}
}

void JSRInlinerAdapter::init$(int32_t api, $MethodVisitor* methodVisitor, int32_t access, $String* name, $String* descriptor, $String* signature, $StringArray* exceptions) {
	$MethodNode::init$(api, access, name, descriptor, signature, exceptions);
	$set(this, mainSubroutineInsns, $new($BitSet));
	$set(this, subroutinesInsns, $new($HashMap));
	$set(this, sharedSubroutineInsns, $new($BitSet));
	$set(this, mv, methodVisitor);
}

void JSRInlinerAdapter::visitJumpInsn(int32_t opcode, $Label* label) {
	$useLocalCurrentObjectStackCache();
	$MethodNode::visitJumpInsn(opcode, label);
	$var($LabelNode, labelNode, $nc(($cast($JumpInsnNode, $($nc(this->instructions)->getLast()))))->label);
	if (opcode == $Opcodes::JSR && !$nc(this->subroutinesInsns)->containsKey(labelNode)) {
		$nc(this->subroutinesInsns)->put(labelNode, $$new($BitSet));
	}
}

void JSRInlinerAdapter::visitEnd() {
	if (!$nc(this->subroutinesInsns)->isEmpty()) {
		findSubroutinesInsns();
		emitCode();
	}
	if (this->mv != nullptr) {
		accept(this->mv);
	}
}

void JSRInlinerAdapter::findSubroutinesInsns() {
	$useLocalCurrentObjectStackCache();
	$var($BitSet, visitedInsns, $new($BitSet));
	findSubroutineInsns(0, this->mainSubroutineInsns, visitedInsns);
	{
		$var($Iterator, i$, $nc($($nc(this->subroutinesInsns)->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
			{
				$var($LabelNode, jsrLabelNode, $cast($LabelNode, $nc(entry)->getKey()));
				$var($BitSet, subroutineInsns, $cast($BitSet, entry->getValue()));
				findSubroutineInsns($nc(this->instructions)->indexOf(jsrLabelNode), subroutineInsns, visitedInsns);
			}
		}
	}
}

void JSRInlinerAdapter::findSubroutineInsns(int32_t startInsnIndex, $BitSet* subroutineInsns, $BitSet* visitedInsns) {
	$useLocalCurrentObjectStackCache();
	findReachableInsns(startInsnIndex, subroutineInsns, visitedInsns);
	while (true) {
		bool applicableHandlerFound = false;
		{
			$var($Iterator, i$, $nc(this->tryCatchBlocks)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($TryCatchBlockNode, tryCatchBlockNode, $cast($TryCatchBlockNode, i$->next()));
				{
					int32_t handlerIndex = $nc(this->instructions)->indexOf($nc(tryCatchBlockNode)->handler);
					if ($nc(subroutineInsns)->get(handlerIndex)) {
						continue;
					}
					int32_t startIndex = $nc(this->instructions)->indexOf($nc(tryCatchBlockNode)->start);
					int32_t endIndex = $nc(this->instructions)->indexOf($nc(tryCatchBlockNode)->end);
					int32_t firstSubroutineInsnAfterTryCatchStart = $nc(subroutineInsns)->nextSetBit(startIndex);
					if (firstSubroutineInsnAfterTryCatchStart >= startIndex && firstSubroutineInsnAfterTryCatchStart < endIndex) {
						findReachableInsns(handlerIndex, subroutineInsns, visitedInsns);
						applicableHandlerFound = true;
					}
				}
			}
		}
		if (!applicableHandlerFound) {
			return;
		}
	}
}

void JSRInlinerAdapter::findReachableInsns(int32_t insnIndex, $BitSet* subroutineInsns, $BitSet* visitedInsns) {
	$useLocalCurrentObjectStackCache();
	int32_t currentInsnIndex = insnIndex;
	while (currentInsnIndex < $nc(this->instructions)->size()) {
		if ($nc(subroutineInsns)->get(currentInsnIndex)) {
			return;
		}
		$nc(subroutineInsns)->set(currentInsnIndex);
		if ($nc(visitedInsns)->get(currentInsnIndex)) {
			$nc(this->sharedSubroutineInsns)->set(currentInsnIndex);
		}
		$nc(visitedInsns)->set(currentInsnIndex);
		$var($AbstractInsnNode, currentInsnNode, $nc(this->instructions)->get(currentInsnIndex));
		bool var$0 = $nc(currentInsnNode)->getType() == $AbstractInsnNode::JUMP_INSN;
		if (var$0 && currentInsnNode->getOpcode() != $Opcodes::JSR) {
			$var($JumpInsnNode, jumpInsnNode, $cast($JumpInsnNode, currentInsnNode));
			findReachableInsns($nc(this->instructions)->indexOf(jumpInsnNode->label), subroutineInsns, visitedInsns);
		} else if (currentInsnNode->getType() == $AbstractInsnNode::TABLESWITCH_INSN) {
			$var($TableSwitchInsnNode, tableSwitchInsnNode, $cast($TableSwitchInsnNode, currentInsnNode));
			findReachableInsns($nc(this->instructions)->indexOf(tableSwitchInsnNode->dflt), subroutineInsns, visitedInsns);
			{
				$var($Iterator, i$, $nc(tableSwitchInsnNode->labels)->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($LabelNode, labelNode, $cast($LabelNode, i$->next()));
					{
						findReachableInsns($nc(this->instructions)->indexOf(labelNode), subroutineInsns, visitedInsns);
					}
				}
			}
		} else if (currentInsnNode->getType() == $AbstractInsnNode::LOOKUPSWITCH_INSN) {
			$var($LookupSwitchInsnNode, lookupSwitchInsnNode, $cast($LookupSwitchInsnNode, currentInsnNode));
			findReachableInsns($nc(this->instructions)->indexOf(lookupSwitchInsnNode->dflt), subroutineInsns, visitedInsns);
			{
				$var($Iterator, i$, $nc(lookupSwitchInsnNode->labels)->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($LabelNode, labelNode, $cast($LabelNode, i$->next()));
					{
						findReachableInsns($nc(this->instructions)->indexOf(labelNode), subroutineInsns, visitedInsns);
					}
				}
			}
		}
		switch ($nc($($nc(this->instructions)->get(currentInsnIndex)))->getOpcode()) {
		case $Opcodes::GOTO:
			{}
		case $Opcodes::RET:
			{}
		case $Opcodes::TABLESWITCH:
			{}
		case $Opcodes::LOOKUPSWITCH:
			{}
		case $Opcodes::IRETURN:
			{}
		case $Opcodes::LRETURN:
			{}
		case $Opcodes::FRETURN:
			{}
		case $Opcodes::DRETURN:
			{}
		case $Opcodes::ARETURN:
			{}
		case $Opcodes::RETURN:
			{}
		case $Opcodes::ATHROW:
			{
				return;
			}
		default:
			{
				++currentInsnIndex;
				break;
			}
		}
	}
}

void JSRInlinerAdapter::emitCode() {
	$useLocalCurrentObjectStackCache();
	$var($LinkedList, worklist, $new($LinkedList));
	worklist->add($$new($JSRInlinerAdapter$Instantiation, this, nullptr, this->mainSubroutineInsns));
	$var($InsnList, newInstructions, $new($InsnList));
	$var($List, newTryCatchBlocks, $new($ArrayList));
	$var($List, newLocalVariables, $new($ArrayList));
	while (!worklist->isEmpty()) {
		$var($JSRInlinerAdapter$Instantiation, instantiation, $cast($JSRInlinerAdapter$Instantiation, worklist->removeFirst()));
		emitInstantiation(instantiation, worklist, newInstructions, newTryCatchBlocks, newLocalVariables);
	}
	$set(this, instructions, newInstructions);
	$set(this, tryCatchBlocks, newTryCatchBlocks);
	$set(this, localVariables, newLocalVariables);
}

void JSRInlinerAdapter::emitInstantiation($JSRInlinerAdapter$Instantiation* instantiation, $List* worklist, $InsnList* newInstructions, $List* newTryCatchBlocks, $List* newLocalVariables) {
	$useLocalCurrentObjectStackCache();
	$var($LabelNode, previousLabelNode, nullptr);
	for (int32_t i = 0; i < $nc(this->instructions)->size(); ++i) {
		$var($AbstractInsnNode, insnNode, $nc(this->instructions)->get(i));
		if ($nc(insnNode)->getType() == $AbstractInsnNode::LABEL) {
			$var($LabelNode, labelNode, $cast($LabelNode, insnNode));
			$var($LabelNode, clonedLabelNode, $nc(instantiation)->getClonedLabel(labelNode));
			if (clonedLabelNode != previousLabelNode) {
				$nc(newInstructions)->add(static_cast<$AbstractInsnNode*>(clonedLabelNode));
				$assign(previousLabelNode, clonedLabelNode);
			}
		} else if ($nc(instantiation)->findOwner(i) == instantiation) {
			if (insnNode->getOpcode() == $Opcodes::RET) {
				$var($LabelNode, retLabel, nullptr);
				{
					$var($JSRInlinerAdapter$Instantiation, retLabelOwner, instantiation);
					for (; retLabelOwner != nullptr; $assign(retLabelOwner, retLabelOwner->parent)) {
						if ($nc($nc(retLabelOwner)->subroutineInsns)->get(i)) {
							$assign(retLabel, retLabelOwner->returnLabel);
						}
					}
				}
				if (retLabel == nullptr) {
					$throwNew($IllegalArgumentException, $$str({"Instruction #"_s, $$str(i), " is a RET not owned by any subroutine"_s}));
				}
				$nc(newInstructions)->add(static_cast<$AbstractInsnNode*>($$new($JumpInsnNode, $Opcodes::GOTO, retLabel)));
			} else if (insnNode->getOpcode() == $Opcodes::JSR) {
				$var($LabelNode, jsrLabelNode, $nc(($cast($JumpInsnNode, insnNode)))->label);
				$var($BitSet, subroutineInsns, $cast($BitSet, $nc(this->subroutinesInsns)->get(jsrLabelNode)));
				$var($JSRInlinerAdapter$Instantiation, newInstantiation, $new($JSRInlinerAdapter$Instantiation, this, instantiation, subroutineInsns));
				$var($LabelNode, clonedJsrLabelNode, newInstantiation->getClonedLabelForJumpInsn(jsrLabelNode));
				$nc(newInstructions)->add(static_cast<$AbstractInsnNode*>($$new($InsnNode, $Opcodes::ACONST_NULL)));
				newInstructions->add(static_cast<$AbstractInsnNode*>($$new($JumpInsnNode, $Opcodes::GOTO, clonedJsrLabelNode)));
				newInstructions->add(static_cast<$AbstractInsnNode*>(newInstantiation->returnLabel));
				$nc(worklist)->add(newInstantiation);
			} else {
				$nc(newInstructions)->add($(insnNode->clone(instantiation)));
			}
		}
	}
	{
		$var($Iterator, i$, $nc(this->tryCatchBlocks)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($TryCatchBlockNode, tryCatchBlockNode, $cast($TryCatchBlockNode, i$->next()));
			{
				$var($LabelNode, start, $nc(instantiation)->getClonedLabel($nc(tryCatchBlockNode)->start));
				$var($LabelNode, end, instantiation->getClonedLabel($nc(tryCatchBlockNode)->end));
				if (start != end) {
					$var($LabelNode, handler, instantiation->getClonedLabelForJumpInsn($nc(tryCatchBlockNode)->handler));
					if (start == nullptr || end == nullptr || handler == nullptr) {
						$throwNew($AssertionError, $of("Internal error!"_s));
					}
					$nc(newTryCatchBlocks)->add($$new($TryCatchBlockNode, start, end, handler, $nc(tryCatchBlockNode)->type));
				}
			}
		}
	}
	{
		$var($Iterator, i$, $nc(this->localVariables)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($LocalVariableNode, localVariableNode, $cast($LocalVariableNode, i$->next()));
			{
				$var($LabelNode, start, $nc(instantiation)->getClonedLabel($nc(localVariableNode)->start));
				$var($LabelNode, end, instantiation->getClonedLabel($nc(localVariableNode)->end));
				if (start != end) {
					$nc(newLocalVariables)->add($$new($LocalVariableNode, $nc(localVariableNode)->name, localVariableNode->desc, localVariableNode->signature, start, end, localVariableNode->index));
				}
			}
		}
	}
}

JSRInlinerAdapter::JSRInlinerAdapter() {
}

$Class* JSRInlinerAdapter::load$($String* name, bool initialize) {
	$loadClass(JSRInlinerAdapter, name, initialize, &_JSRInlinerAdapter_ClassInfo_, allocate$JSRInlinerAdapter);
	return class$;
}

$Class* JSRInlinerAdapter::class$ = nullptr;

					} // commons
				} // asm$
			} // objectweb
		} // org
	} // internal
} // jdk