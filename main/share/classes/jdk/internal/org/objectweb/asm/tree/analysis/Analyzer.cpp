#include <jdk/internal/org/objectweb/asm/tree/analysis/Analyzer.h>

#include <java/util/ArrayList.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <jdk/internal/org/objectweb/asm/Opcodes.h>
#include <jdk/internal/org/objectweb/asm/Type.h>
#include <jdk/internal/org/objectweb/asm/tree/AbstractInsnNode.h>
#include <jdk/internal/org/objectweb/asm/tree/IincInsnNode.h>
#include <jdk/internal/org/objectweb/asm/tree/InsnList.h>
#include <jdk/internal/org/objectweb/asm/tree/JumpInsnNode.h>
#include <jdk/internal/org/objectweb/asm/tree/LabelNode.h>
#include <jdk/internal/org/objectweb/asm/tree/LookupSwitchInsnNode.h>
#include <jdk/internal/org/objectweb/asm/tree/MethodNode.h>
#include <jdk/internal/org/objectweb/asm/tree/TableSwitchInsnNode.h>
#include <jdk/internal/org/objectweb/asm/tree/TryCatchBlockNode.h>
#include <jdk/internal/org/objectweb/asm/tree/VarInsnNode.h>
#include <jdk/internal/org/objectweb/asm/tree/analysis/AnalyzerException.h>
#include <jdk/internal/org/objectweb/asm/tree/analysis/Frame.h>
#include <jdk/internal/org/objectweb/asm/tree/analysis/Interpreter.h>
#include <jdk/internal/org/objectweb/asm/tree/analysis/Subroutine.h>
#include <jdk/internal/org/objectweb/asm/tree/analysis/Value.h>
#include <jcpp.h>

#undef ACC_ABSTRACT
#undef ACC_NATIVE
#undef ACC_STATIC
#undef ARETURN
#undef ATHROW
#undef DLOAD
#undef DRETURN
#undef DSTORE
#undef FRAME
#undef FRETURN
#undef GOTO
#undef IRETURN
#undef JSR
#undef LABEL
#undef LINE
#undef LLOAD
#undef LOOKUPSWITCH
#undef LRETURN
#undef LSTORE
#undef RET
#undef RETURN
#undef TABLESWITCH

using $ListArray = $Array<::java::util::List>;
using $TypeArray = $Array<::jdk::internal::org::objectweb::asm$::Type>;
using $FrameArray = $Array<::jdk::internal::org::objectweb::asm$::tree::analysis::Frame>;
using $SubroutineArray = $Array<::jdk::internal::org::objectweb::asm$::tree::analysis::Subroutine>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $ArrayList = ::java::util::ArrayList;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Opcodes = ::jdk::internal::org::objectweb::asm$::Opcodes;
using $Type = ::jdk::internal::org::objectweb::asm$::Type;
using $AbstractInsnNode = ::jdk::internal::org::objectweb::asm$::tree::AbstractInsnNode;
using $IincInsnNode = ::jdk::internal::org::objectweb::asm$::tree::IincInsnNode;
using $InsnList = ::jdk::internal::org::objectweb::asm$::tree::InsnList;
using $JumpInsnNode = ::jdk::internal::org::objectweb::asm$::tree::JumpInsnNode;
using $LabelNode = ::jdk::internal::org::objectweb::asm$::tree::LabelNode;
using $LookupSwitchInsnNode = ::jdk::internal::org::objectweb::asm$::tree::LookupSwitchInsnNode;
using $MethodNode = ::jdk::internal::org::objectweb::asm$::tree::MethodNode;
using $TableSwitchInsnNode = ::jdk::internal::org::objectweb::asm$::tree::TableSwitchInsnNode;
using $TryCatchBlockNode = ::jdk::internal::org::objectweb::asm$::tree::TryCatchBlockNode;
using $VarInsnNode = ::jdk::internal::org::objectweb::asm$::tree::VarInsnNode;
using $AnalyzerException = ::jdk::internal::org::objectweb::asm$::tree::analysis::AnalyzerException;
using $Frame = ::jdk::internal::org::objectweb::asm$::tree::analysis::Frame;
using $Interpreter = ::jdk::internal::org::objectweb::asm$::tree::analysis::Interpreter;
using $Subroutine = ::jdk::internal::org::objectweb::asm$::tree::analysis::Subroutine;

namespace jdk {
	namespace internal {
		namespace org {
			namespace objectweb {
				namespace asm$ {
					namespace tree {
						namespace analysis {

$FieldInfo _Analyzer_FieldInfo_[] = {
	{"interpreter", "Ljdk/internal/org/objectweb/asm/tree/analysis/Interpreter;", "Ljdk/internal/org/objectweb/asm/tree/analysis/Interpreter<TV;>;", $PRIVATE | $FINAL, $field(Analyzer, interpreter)},
	{"insnList", "Ljdk/internal/org/objectweb/asm/tree/InsnList;", nullptr, $PRIVATE, $field(Analyzer, insnList)},
	{"insnListSize", "I", nullptr, $PRIVATE, $field(Analyzer, insnListSize)},
	{"handlers", "[Ljava/util/List;", "[Ljava/util/List<Ljdk/internal/org/objectweb/asm/tree/TryCatchBlockNode;>;", $PRIVATE, $field(Analyzer, handlers)},
	{"frames", "[Ljdk/internal/org/objectweb/asm/tree/analysis/Frame;", "[Ljdk/internal/org/objectweb/asm/tree/analysis/Frame<TV;>;", $PRIVATE, $field(Analyzer, frames)},
	{"subroutines", "[Ljdk/internal/org/objectweb/asm/tree/analysis/Subroutine;", nullptr, $PRIVATE, $field(Analyzer, subroutines)},
	{"inInstructionsToProcess", "[Z", nullptr, $PRIVATE, $field(Analyzer, inInstructionsToProcess)},
	{"instructionsToProcess", "[I", nullptr, $PRIVATE, $field(Analyzer, instructionsToProcess)},
	{"numInstructionsToProcess", "I", nullptr, $PRIVATE, $field(Analyzer, numInstructionsToProcess)},
	{}
};

$MethodInfo _Analyzer_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/org/objectweb/asm/tree/analysis/Interpreter;)V", "(Ljdk/internal/org/objectweb/asm/tree/analysis/Interpreter<TV;>;)V", $PUBLIC, $method(Analyzer, init$, void, $Interpreter*)},
	{"analyze", "(Ljava/lang/String;Ljdk/internal/org/objectweb/asm/tree/MethodNode;)[Ljdk/internal/org/objectweb/asm/tree/analysis/Frame;", "(Ljava/lang/String;Ljdk/internal/org/objectweb/asm/tree/MethodNode;)[Ljdk/internal/org/objectweb/asm/tree/analysis/Frame<TV;>;", $PUBLIC, $virtualMethod(Analyzer, analyze, $FrameArray*, $String*, $MethodNode*), "jdk.internal.org.objectweb.asm.tree.analysis.AnalyzerException"},
	{"computeInitialFrame", "(Ljava/lang/String;Ljdk/internal/org/objectweb/asm/tree/MethodNode;)Ljdk/internal/org/objectweb/asm/tree/analysis/Frame;", "(Ljava/lang/String;Ljdk/internal/org/objectweb/asm/tree/MethodNode;)Ljdk/internal/org/objectweb/asm/tree/analysis/Frame<TV;>;", $PRIVATE, $method(Analyzer, computeInitialFrame, $Frame*, $String*, $MethodNode*)},
	{"findSubroutine", "(ILjdk/internal/org/objectweb/asm/tree/analysis/Subroutine;Ljava/util/List;)V", "(ILjdk/internal/org/objectweb/asm/tree/analysis/Subroutine;Ljava/util/List<Ljdk/internal/org/objectweb/asm/tree/AbstractInsnNode;>;)V", $PRIVATE, $method(Analyzer, findSubroutine, void, int32_t, $Subroutine*, $List*), "jdk.internal.org.objectweb.asm.tree.analysis.AnalyzerException"},
	{"getFrames", "()[Ljdk/internal/org/objectweb/asm/tree/analysis/Frame;", "()[Ljdk/internal/org/objectweb/asm/tree/analysis/Frame<TV;>;", $PUBLIC, $virtualMethod(Analyzer, getFrames, $FrameArray*)},
	{"getHandlers", "(I)Ljava/util/List;", "(I)Ljava/util/List<Ljdk/internal/org/objectweb/asm/tree/TryCatchBlockNode;>;", $PUBLIC, $virtualMethod(Analyzer, getHandlers, $List*, int32_t)},
	{"init", "(Ljava/lang/String;Ljdk/internal/org/objectweb/asm/tree/MethodNode;)V", nullptr, $PROTECTED, $virtualMethod(Analyzer, init, void, $String*, $MethodNode*), "jdk.internal.org.objectweb.asm.tree.analysis.AnalyzerException"},
	{"merge", "(ILjdk/internal/org/objectweb/asm/tree/analysis/Frame;Ljdk/internal/org/objectweb/asm/tree/analysis/Subroutine;)V", "(ILjdk/internal/org/objectweb/asm/tree/analysis/Frame<TV;>;Ljdk/internal/org/objectweb/asm/tree/analysis/Subroutine;)V", $PRIVATE, $method(Analyzer, merge, void, int32_t, $Frame*, $Subroutine*), "jdk.internal.org.objectweb.asm.tree.analysis.AnalyzerException"},
	{"merge", "(ILjdk/internal/org/objectweb/asm/tree/analysis/Frame;Ljdk/internal/org/objectweb/asm/tree/analysis/Frame;Ljdk/internal/org/objectweb/asm/tree/analysis/Subroutine;[Z)V", "(ILjdk/internal/org/objectweb/asm/tree/analysis/Frame<TV;>;Ljdk/internal/org/objectweb/asm/tree/analysis/Frame<TV;>;Ljdk/internal/org/objectweb/asm/tree/analysis/Subroutine;[Z)V", $PRIVATE, $method(Analyzer, merge, void, int32_t, $Frame*, $Frame*, $Subroutine*, $booleans*), "jdk.internal.org.objectweb.asm.tree.analysis.AnalyzerException"},
	{"newControlFlowEdge", "(II)V", nullptr, $PROTECTED, $virtualMethod(Analyzer, newControlFlowEdge, void, int32_t, int32_t)},
	{"newControlFlowExceptionEdge", "(II)Z", nullptr, $PROTECTED, $virtualMethod(Analyzer, newControlFlowExceptionEdge, bool, int32_t, int32_t)},
	{"newControlFlowExceptionEdge", "(ILjdk/internal/org/objectweb/asm/tree/TryCatchBlockNode;)Z", nullptr, $PROTECTED, $virtualMethod(Analyzer, newControlFlowExceptionEdge, bool, int32_t, $TryCatchBlockNode*)},
	{"newFrame", "(II)Ljdk/internal/org/objectweb/asm/tree/analysis/Frame;", "(II)Ljdk/internal/org/objectweb/asm/tree/analysis/Frame<TV;>;", $PROTECTED, $virtualMethod(Analyzer, newFrame, $Frame*, int32_t, int32_t)},
	{"newFrame", "(Ljdk/internal/org/objectweb/asm/tree/analysis/Frame;)Ljdk/internal/org/objectweb/asm/tree/analysis/Frame;", "(Ljdk/internal/org/objectweb/asm/tree/analysis/Frame<+TV;>;)Ljdk/internal/org/objectweb/asm/tree/analysis/Frame<TV;>;", $PROTECTED, $virtualMethod(Analyzer, newFrame, $Frame*, $Frame*)},
	{}
};

$ClassInfo _Analyzer_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.org.objectweb.asm.tree.analysis.Analyzer",
	"java.lang.Object",
	"jdk.internal.org.objectweb.asm.Opcodes",
	_Analyzer_FieldInfo_,
	_Analyzer_MethodInfo_,
	"<V::Ljdk/internal/org/objectweb/asm/tree/analysis/Value;>Ljava/lang/Object;Ljdk/internal/org/objectweb/asm/Opcodes;"
};

$Object* allocate$Analyzer($Class* clazz) {
	return $of($alloc(Analyzer));
}

void Analyzer::init$($Interpreter* interpreter) {
	$set(this, interpreter, interpreter);
}

$FrameArray* Analyzer::analyze($String* owner, $MethodNode* method) {
	$useLocalCurrentObjectStackCache();
	if (((int32_t)($nc(method)->access & (uint32_t)($Opcodes::ACC_ABSTRACT | $Opcodes::ACC_NATIVE))) != 0) {
		$set(this, frames, $new($FrameArray, 0));
		return this->frames;
	}
	$set(this, insnList, $nc(method)->instructions);
	this->insnListSize = $nc(this->insnList)->size();
	$set(this, handlers, $new($ListArray, this->insnListSize));
	$set(this, frames, $new($FrameArray, this->insnListSize));
	$set(this, subroutines, $new($SubroutineArray, this->insnListSize));
	$set(this, inInstructionsToProcess, $new($booleans, this->insnListSize));
	$set(this, instructionsToProcess, $new($ints, this->insnListSize));
	this->numInstructionsToProcess = 0;
	for (int32_t i = 0; i < $nc(method->tryCatchBlocks)->size(); ++i) {
		$var($TryCatchBlockNode, tryCatchBlock, $cast($TryCatchBlockNode, $nc(method->tryCatchBlocks)->get(i)));
		int32_t startIndex = $nc(this->insnList)->indexOf($nc(tryCatchBlock)->start);
		int32_t endIndex = $nc(this->insnList)->indexOf($nc(tryCatchBlock)->end);
		for (int32_t j = startIndex; j < endIndex; ++j) {
			$var($List, insnHandlers, $nc(this->handlers)->get(j));
			if (insnHandlers == nullptr) {
				$assign(insnHandlers, $new($ArrayList));
				$nc(this->handlers)->set(j, insnHandlers);
			}
			$nc(insnHandlers)->add(tryCatchBlock);
		}
	}
	$var($Subroutine, main, $new($Subroutine, nullptr, method->maxLocals, nullptr));
	$var($List, jsrInsns, $new($ArrayList));
	findSubroutine(0, main, jsrInsns);
	$var($Map, jsrSubroutines, $new($HashMap));
	while (!jsrInsns->isEmpty()) {
		$var($JumpInsnNode, jsrInsn, $cast($JumpInsnNode, jsrInsns->remove(0)));
		$var($Subroutine, subroutine, $cast($Subroutine, jsrSubroutines->get($nc(jsrInsn)->label)));
		if (subroutine == nullptr) {
			$assign(subroutine, $new($Subroutine, $nc(jsrInsn)->label, method->maxLocals, jsrInsn));
			jsrSubroutines->put($nc(jsrInsn)->label, subroutine);
			findSubroutine($nc(this->insnList)->indexOf($nc(jsrInsn)->label), subroutine, jsrInsns);
		} else {
			$nc($nc(subroutine)->callers)->add(jsrInsn);
		}
	}
	for (int32_t i = 0; i < this->insnListSize; ++i) {
		if ($nc(this->subroutines)->get(i) != nullptr && $nc($nc(this->subroutines)->get(i))->start == nullptr) {
			$nc(this->subroutines)->set(i, nullptr);
		}
	}
	$var($Frame, currentFrame, computeInitialFrame(owner, method));
	merge(0, currentFrame, nullptr);
	init(owner, method);
	while (this->numInstructionsToProcess > 0) {
		int32_t insnIndex = $nc(this->instructionsToProcess)->get(--this->numInstructionsToProcess);
		$var($Frame, oldFrame, $nc(this->frames)->get(insnIndex));
		$var($Subroutine, subroutine, $nc(this->subroutines)->get(insnIndex));
		$nc(this->inInstructionsToProcess)->set(insnIndex, false);
		$var($AbstractInsnNode, insnNode, nullptr);
		try {
			$assign(insnNode, $nc(method->instructions)->get(insnIndex));
			int32_t insnOpcode = $nc(insnNode)->getOpcode();
			int32_t insnType = insnNode->getType();
			if (insnType == $AbstractInsnNode::LABEL || insnType == $AbstractInsnNode::LINE || insnType == $AbstractInsnNode::FRAME) {
				merge(insnIndex + 1, oldFrame, subroutine);
				newControlFlowEdge(insnIndex, insnIndex + 1);
			} else {
				$nc($($nc(currentFrame)->init(oldFrame)))->execute(insnNode, this->interpreter);
				$assign(subroutine, subroutine == nullptr ? ($Subroutine*)nullptr : $new($Subroutine, subroutine));
				if ($instanceOf($JumpInsnNode, insnNode)) {
					$var($JumpInsnNode, jumpInsn, $cast($JumpInsnNode, insnNode));
					if (insnOpcode != $Opcodes::GOTO && insnOpcode != $Opcodes::JSR) {
						currentFrame->initJumpTarget(insnOpcode, nullptr);
						merge(insnIndex + 1, currentFrame, subroutine);
						newControlFlowEdge(insnIndex, insnIndex + 1);
					}
					int32_t jumpInsnIndex = $nc(this->insnList)->indexOf(jumpInsn->label);
					currentFrame->initJumpTarget(insnOpcode, jumpInsn->label);
					if (insnOpcode == $Opcodes::JSR) {
						merge(jumpInsnIndex, currentFrame, $$new($Subroutine, jumpInsn->label, method->maxLocals, jumpInsn));
					} else {
						merge(jumpInsnIndex, currentFrame, subroutine);
					}
					newControlFlowEdge(insnIndex, jumpInsnIndex);
				} else if ($instanceOf($LookupSwitchInsnNode, insnNode)) {
					$var($LookupSwitchInsnNode, lookupSwitchInsn, $cast($LookupSwitchInsnNode, insnNode));
					int32_t targetInsnIndex = $nc(this->insnList)->indexOf(lookupSwitchInsn->dflt);
					currentFrame->initJumpTarget(insnOpcode, lookupSwitchInsn->dflt);
					merge(targetInsnIndex, currentFrame, subroutine);
					newControlFlowEdge(insnIndex, targetInsnIndex);
					for (int32_t i = 0; i < $nc(lookupSwitchInsn->labels)->size(); ++i) {
						$var($LabelNode, label, $cast($LabelNode, $nc(lookupSwitchInsn->labels)->get(i)));
						targetInsnIndex = $nc(this->insnList)->indexOf(label);
						currentFrame->initJumpTarget(insnOpcode, label);
						merge(targetInsnIndex, currentFrame, subroutine);
						newControlFlowEdge(insnIndex, targetInsnIndex);
					}
				} else if ($instanceOf($TableSwitchInsnNode, insnNode)) {
					$var($TableSwitchInsnNode, tableSwitchInsn, $cast($TableSwitchInsnNode, insnNode));
					int32_t targetInsnIndex = $nc(this->insnList)->indexOf(tableSwitchInsn->dflt);
					currentFrame->initJumpTarget(insnOpcode, tableSwitchInsn->dflt);
					merge(targetInsnIndex, currentFrame, subroutine);
					newControlFlowEdge(insnIndex, targetInsnIndex);
					for (int32_t i = 0; i < $nc(tableSwitchInsn->labels)->size(); ++i) {
						$var($LabelNode, label, $cast($LabelNode, $nc(tableSwitchInsn->labels)->get(i)));
						currentFrame->initJumpTarget(insnOpcode, label);
						targetInsnIndex = $nc(this->insnList)->indexOf(label);
						merge(targetInsnIndex, currentFrame, subroutine);
						newControlFlowEdge(insnIndex, targetInsnIndex);
					}
				} else if (insnOpcode == $Opcodes::RET) {
					if (subroutine == nullptr) {
						$throwNew($AnalyzerException, insnNode, "RET instruction outside of a subroutine"_s);
					}
					for (int32_t i = 0; i < $nc($nc(subroutine)->callers)->size(); ++i) {
						$var($JumpInsnNode, caller, $cast($JumpInsnNode, $nc(subroutine->callers)->get(i)));
						int32_t jsrInsnIndex = $nc(this->insnList)->indexOf(caller);
						if ($nc(this->frames)->get(jsrInsnIndex) != nullptr) {
							merge(jsrInsnIndex + 1, $nc(this->frames)->get(jsrInsnIndex), currentFrame, $nc(this->subroutines)->get(jsrInsnIndex), subroutine->localsUsed);
							newControlFlowEdge(insnIndex, jsrInsnIndex + 1);
						}
					}
				} else if (insnOpcode != $Opcodes::ATHROW && (insnOpcode < $Opcodes::IRETURN || insnOpcode > $Opcodes::RETURN)) {
					if (subroutine != nullptr) {
						if ($instanceOf($VarInsnNode, insnNode)) {
							int32_t var = $nc(($cast($VarInsnNode, insnNode)))->var;
							$nc(subroutine->localsUsed)->set(var, true);
							if (insnOpcode == $Opcodes::LLOAD || insnOpcode == $Opcodes::DLOAD || insnOpcode == $Opcodes::LSTORE || insnOpcode == $Opcodes::DSTORE) {
								$nc(subroutine->localsUsed)->set(var + 1, true);
							}
						} else if ($instanceOf($IincInsnNode, insnNode)) {
							int32_t var = $nc(($cast($IincInsnNode, insnNode)))->var;
							$nc(subroutine->localsUsed)->set(var, true);
						}
					}
					merge(insnIndex + 1, currentFrame, subroutine);
					newControlFlowEdge(insnIndex, insnIndex + 1);
				}
			}
			$var($List, insnHandlers, $nc(this->handlers)->get(insnIndex));
			if (insnHandlers != nullptr) {
				{
					$var($Iterator, i$, insnHandlers->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($TryCatchBlockNode, tryCatchBlock, $cast($TryCatchBlockNode, i$->next()));
						{
							$var($Type, catchType, nullptr);
							if ($nc(tryCatchBlock)->type == nullptr) {
								$assign(catchType, $Type::getObjectType("java/lang/Throwable"_s));
							} else {
								$assign(catchType, $Type::getObjectType(tryCatchBlock->type));
							}
							if (newControlFlowExceptionEdge(insnIndex, tryCatchBlock)) {
								$var($Frame, handler, newFrame(oldFrame));
								$nc(handler)->clearStack();
								handler->push($($nc(this->interpreter)->newExceptionValue(tryCatchBlock, handler, catchType)));
								merge($nc(this->insnList)->indexOf($nc(tryCatchBlock)->handler), handler, subroutine);
							}
						}
					}
				}
			}
		} catch ($AnalyzerException& e) {
			$throwNew($AnalyzerException, e->node, $$str({"Error at instruction "_s, $$str(insnIndex), ": "_s, $(e->getMessage())}), e);
		} catch ($RuntimeException& e) {
			$throwNew($AnalyzerException, insnNode, $$str({"Error at instruction "_s, $$str(insnIndex), ": "_s, $(e->getMessage())}), e);
		}
	}
	return this->frames;
}

void Analyzer::findSubroutine(int32_t insnIndex, $Subroutine* subroutine, $List* jsrInsns) {
	$useLocalCurrentObjectStackCache();
	$var($ArrayList, instructionIndicesToProcess, $new($ArrayList));
	instructionIndicesToProcess->add($($Integer::valueOf(insnIndex)));
	while (!instructionIndicesToProcess->isEmpty()) {
		int32_t currentInsnIndex = $nc(($cast($Integer, $(instructionIndicesToProcess->remove(instructionIndicesToProcess->size() - 1)))))->intValue();
		if (currentInsnIndex < 0 || currentInsnIndex >= this->insnListSize) {
			$throwNew($AnalyzerException, nullptr, "Execution can fall off the end of the code"_s);
		}
		if ($nc(this->subroutines)->get(currentInsnIndex) != nullptr) {
			continue;
		}
		$nc(this->subroutines)->set(currentInsnIndex, $$new($Subroutine, subroutine));
		$var($AbstractInsnNode, currentInsn, $nc(this->insnList)->get(currentInsnIndex));
		if ($instanceOf($JumpInsnNode, currentInsn)) {
			if ($nc(currentInsn)->getOpcode() == $Opcodes::JSR) {
				$nc(jsrInsns)->add(currentInsn);
			} else {
				$var($JumpInsnNode, jumpInsn, $cast($JumpInsnNode, currentInsn));
				instructionIndicesToProcess->add($($Integer::valueOf($nc(this->insnList)->indexOf(jumpInsn->label))));
			}
		} else if ($instanceOf($TableSwitchInsnNode, currentInsn)) {
			$var($TableSwitchInsnNode, tableSwitchInsn, $cast($TableSwitchInsnNode, currentInsn));
			findSubroutine($nc(this->insnList)->indexOf($nc(tableSwitchInsn)->dflt), subroutine, jsrInsns);
			for (int32_t i = $nc($nc(tableSwitchInsn)->labels)->size() - 1; i >= 0; --i) {
				$var($LabelNode, labelNode, $cast($LabelNode, $nc(tableSwitchInsn->labels)->get(i)));
				instructionIndicesToProcess->add($($Integer::valueOf($nc(this->insnList)->indexOf(labelNode))));
			}
		} else if ($instanceOf($LookupSwitchInsnNode, currentInsn)) {
			$var($LookupSwitchInsnNode, lookupSwitchInsn, $cast($LookupSwitchInsnNode, currentInsn));
			findSubroutine($nc(this->insnList)->indexOf($nc(lookupSwitchInsn)->dflt), subroutine, jsrInsns);
			for (int32_t i = $nc($nc(lookupSwitchInsn)->labels)->size() - 1; i >= 0; --i) {
				$var($LabelNode, labelNode, $cast($LabelNode, $nc(lookupSwitchInsn->labels)->get(i)));
				instructionIndicesToProcess->add($($Integer::valueOf($nc(this->insnList)->indexOf(labelNode))));
			}
		}
		$var($List, insnHandlers, $nc(this->handlers)->get(currentInsnIndex));
		if (insnHandlers != nullptr) {
			{
				$var($Iterator, i$, insnHandlers->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($TryCatchBlockNode, tryCatchBlock, $cast($TryCatchBlockNode, i$->next()));
					{
						instructionIndicesToProcess->add($($Integer::valueOf($nc(this->insnList)->indexOf($nc(tryCatchBlock)->handler))));
					}
				}
			}
		}
		switch ($nc(currentInsn)->getOpcode()) {
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
				break;
			}
		default:
			{
				instructionIndicesToProcess->add($($Integer::valueOf(currentInsnIndex + 1)));
				break;
			}
		}
	}
}

$Frame* Analyzer::computeInitialFrame($String* owner, $MethodNode* method) {
	$useLocalCurrentObjectStackCache();
	$var($Frame, frame, newFrame($nc(method)->maxLocals, method->maxStack));
	int32_t currentLocal = 0;
	bool isInstanceMethod = ((int32_t)($nc(method)->access & (uint32_t)$Opcodes::ACC_STATIC)) == 0;
	if (isInstanceMethod) {
		$var($Type, ownerType, $Type::getObjectType(owner));
		$nc(frame)->setLocal(currentLocal, $($nc(this->interpreter)->newParameterValue(isInstanceMethod, currentLocal, ownerType)));
		++currentLocal;
	}
	$var($TypeArray, argumentTypes, $Type::getArgumentTypes(method->desc));
	{
		$var($TypeArray, arr$, argumentTypes);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Type, argumentType, arr$->get(i$));
			{
				$nc(frame)->setLocal(currentLocal, $($nc(this->interpreter)->newParameterValue(isInstanceMethod, currentLocal, argumentType)));
				++currentLocal;
				if ($nc(argumentType)->getSize() == 2) {
					frame->setLocal(currentLocal, $($nc(this->interpreter)->newEmptyValue(currentLocal)));
					++currentLocal;
				}
			}
		}
	}
	while (currentLocal < method->maxLocals) {
		$nc(frame)->setLocal(currentLocal, $($nc(this->interpreter)->newEmptyValue(currentLocal)));
		++currentLocal;
	}
	$nc(frame)->setReturn($($nc(this->interpreter)->newReturnTypeValue($($Type::getReturnType(method->desc)))));
	return frame;
}

$FrameArray* Analyzer::getFrames() {
	return this->frames;
}

$List* Analyzer::getHandlers(int32_t insnIndex) {
	return $nc(this->handlers)->get(insnIndex);
}

void Analyzer::init($String* owner, $MethodNode* method) {
}

$Frame* Analyzer::newFrame(int32_t numLocals, int32_t numStack) {
	return $new($Frame, numLocals, numStack);
}

$Frame* Analyzer::newFrame($Frame* frame) {
	return $new($Frame, frame);
}

void Analyzer::newControlFlowEdge(int32_t insnIndex, int32_t successorIndex) {
}

bool Analyzer::newControlFlowExceptionEdge(int32_t insnIndex, int32_t successorIndex) {
	return true;
}

bool Analyzer::newControlFlowExceptionEdge(int32_t insnIndex, $TryCatchBlockNode* tryCatchBlock) {
	return newControlFlowExceptionEdge(insnIndex, $nc(this->insnList)->indexOf($nc(tryCatchBlock)->handler));
}

void Analyzer::merge(int32_t insnIndex, $Frame* frame, $Subroutine* subroutine) {
	$useLocalCurrentObjectStackCache();
	bool changed = false;
	$var($Frame, oldFrame, $nc(this->frames)->get(insnIndex));
	if (oldFrame == nullptr) {
		$nc(this->frames)->set(insnIndex, $(newFrame(frame)));
		changed = true;
	} else {
		changed = $nc(oldFrame)->merge(frame, this->interpreter);
	}
	$var($Subroutine, oldSubroutine, $nc(this->subroutines)->get(insnIndex));
	if (oldSubroutine == nullptr) {
		if (subroutine != nullptr) {
			$nc(this->subroutines)->set(insnIndex, $$new($Subroutine, subroutine));
			changed = true;
		}
	} else if (subroutine != nullptr) {
		changed |= $nc(oldSubroutine)->merge(subroutine);
	}
	if (changed && !$nc(this->inInstructionsToProcess)->get(insnIndex)) {
		$nc(this->inInstructionsToProcess)->set(insnIndex, true);
		$nc(this->instructionsToProcess)->set(this->numInstructionsToProcess++, insnIndex);
	}
}

void Analyzer::merge(int32_t insnIndex, $Frame* frameBeforeJsr, $Frame* frameAfterRet, $Subroutine* subroutineBeforeJsr, $booleans* localsUsed) {
	$useLocalCurrentObjectStackCache();
	$nc(frameAfterRet)->merge(frameBeforeJsr, localsUsed);
	bool changed = false;
	$var($Frame, oldFrame, $nc(this->frames)->get(insnIndex));
	if (oldFrame == nullptr) {
		$nc(this->frames)->set(insnIndex, $(newFrame(frameAfterRet)));
		changed = true;
	} else {
		changed = $nc(oldFrame)->merge(frameAfterRet, this->interpreter);
	}
	$var($Subroutine, oldSubroutine, $nc(this->subroutines)->get(insnIndex));
	if (oldSubroutine != nullptr && subroutineBeforeJsr != nullptr) {
		changed |= oldSubroutine->merge(subroutineBeforeJsr);
	}
	if (changed && !$nc(this->inInstructionsToProcess)->get(insnIndex)) {
		$nc(this->inInstructionsToProcess)->set(insnIndex, true);
		$nc(this->instructionsToProcess)->set(this->numInstructionsToProcess++, insnIndex);
	}
}

Analyzer::Analyzer() {
}

$Class* Analyzer::load$($String* name, bool initialize) {
	$loadClass(Analyzer, name, initialize, &_Analyzer_ClassInfo_, allocate$Analyzer);
	return class$;
}

$Class* Analyzer::class$ = nullptr;

						} // analysis
					} // tree
				} // asm$
			} // objectweb
		} // org
	} // internal
} // jdk