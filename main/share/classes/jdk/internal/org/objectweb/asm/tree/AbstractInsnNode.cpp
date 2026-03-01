#include <jdk/internal/org/objectweb/asm/tree/AbstractInsnNode.h>

#include <java/util/ArrayList.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <jdk/internal/org/objectweb/asm/AnnotationVisitor.h>
#include <jdk/internal/org/objectweb/asm/MethodVisitor.h>
#include <jdk/internal/org/objectweb/asm/TypePath.h>
#include <jdk/internal/org/objectweb/asm/tree/LabelNode.h>
#include <jdk/internal/org/objectweb/asm/tree/TypeAnnotationNode.h>
#include <jcpp.h>

#undef FIELD_INSN
#undef FRAME
#undef IINC_INSN
#undef INSN
#undef INT_INSN
#undef INVOKE_DYNAMIC_INSN
#undef JUMP_INSN
#undef LABEL
#undef LDC_INSN
#undef LINE
#undef LOOKUPSWITCH_INSN
#undef METHOD_INSN
#undef MULTIANEWARRAY_INSN
#undef TABLESWITCH_INSN
#undef TYPE_INSN
#undef VAR_INSN

using $LabelNodeArray = $Array<::jdk::internal::org::objectweb::asm$::tree::LabelNode>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ArrayList = ::java::util::ArrayList;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $AnnotationVisitor = ::jdk::internal::org::objectweb::asm$::AnnotationVisitor;
using $MethodVisitor = ::jdk::internal::org::objectweb::asm$::MethodVisitor;
using $LabelNode = ::jdk::internal::org::objectweb::asm$::tree::LabelNode;
using $TypeAnnotationNode = ::jdk::internal::org::objectweb::asm$::tree::TypeAnnotationNode;

namespace jdk {
	namespace internal {
		namespace org {
			namespace objectweb {
				namespace asm$ {
					namespace tree {

$FieldInfo _AbstractInsnNode_FieldInfo_[] = {
	{"INSN", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(AbstractInsnNode, INSN)},
	{"INT_INSN", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(AbstractInsnNode, INT_INSN)},
	{"VAR_INSN", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(AbstractInsnNode, VAR_INSN)},
	{"TYPE_INSN", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(AbstractInsnNode, TYPE_INSN)},
	{"FIELD_INSN", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(AbstractInsnNode, FIELD_INSN)},
	{"METHOD_INSN", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(AbstractInsnNode, METHOD_INSN)},
	{"INVOKE_DYNAMIC_INSN", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(AbstractInsnNode, INVOKE_DYNAMIC_INSN)},
	{"JUMP_INSN", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(AbstractInsnNode, JUMP_INSN)},
	{"LABEL", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(AbstractInsnNode, LABEL)},
	{"LDC_INSN", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(AbstractInsnNode, LDC_INSN)},
	{"IINC_INSN", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(AbstractInsnNode, IINC_INSN)},
	{"TABLESWITCH_INSN", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(AbstractInsnNode, TABLESWITCH_INSN)},
	{"LOOKUPSWITCH_INSN", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(AbstractInsnNode, LOOKUPSWITCH_INSN)},
	{"MULTIANEWARRAY_INSN", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(AbstractInsnNode, MULTIANEWARRAY_INSN)},
	{"FRAME", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(AbstractInsnNode, FRAME)},
	{"LINE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(AbstractInsnNode, LINE)},
	{"opcode", "I", nullptr, $PROTECTED, $field(AbstractInsnNode, opcode)},
	{"visibleTypeAnnotations", "Ljava/util/List;", "Ljava/util/List<Ljdk/internal/org/objectweb/asm/tree/TypeAnnotationNode;>;", $PUBLIC, $field(AbstractInsnNode, visibleTypeAnnotations)},
	{"invisibleTypeAnnotations", "Ljava/util/List;", "Ljava/util/List<Ljdk/internal/org/objectweb/asm/tree/TypeAnnotationNode;>;", $PUBLIC, $field(AbstractInsnNode, invisibleTypeAnnotations)},
	{"previousInsn", "Ljdk/internal/org/objectweb/asm/tree/AbstractInsnNode;", nullptr, 0, $field(AbstractInsnNode, previousInsn)},
	{"nextInsn", "Ljdk/internal/org/objectweb/asm/tree/AbstractInsnNode;", nullptr, 0, $field(AbstractInsnNode, nextInsn)},
	{"index", "I", nullptr, 0, $field(AbstractInsnNode, index)},
	{}
};

$MethodInfo _AbstractInsnNode_MethodInfo_[] = {
	{"<init>", "(I)V", nullptr, $PROTECTED, $method(AbstractInsnNode, init$, void, int32_t)},
	{"accept", "(Ljdk/internal/org/objectweb/asm/MethodVisitor;)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(AbstractInsnNode, accept, void, $MethodVisitor*)},
	{"acceptAnnotations", "(Ljdk/internal/org/objectweb/asm/MethodVisitor;)V", nullptr, $PROTECTED | $FINAL, $method(AbstractInsnNode, acceptAnnotations, void, $MethodVisitor*)},
	{"clone", "(Ljava/util/Map;)Ljdk/internal/org/objectweb/asm/tree/AbstractInsnNode;", "(Ljava/util/Map<Ljdk/internal/org/objectweb/asm/tree/LabelNode;Ljdk/internal/org/objectweb/asm/tree/LabelNode;>;)Ljdk/internal/org/objectweb/asm/tree/AbstractInsnNode;", $PUBLIC | $ABSTRACT, $virtualMethod(AbstractInsnNode, clone, AbstractInsnNode*, $Map*)},
	{"clone", "(Ljdk/internal/org/objectweb/asm/tree/LabelNode;Ljava/util/Map;)Ljdk/internal/org/objectweb/asm/tree/LabelNode;", "(Ljdk/internal/org/objectweb/asm/tree/LabelNode;Ljava/util/Map<Ljdk/internal/org/objectweb/asm/tree/LabelNode;Ljdk/internal/org/objectweb/asm/tree/LabelNode;>;)Ljdk/internal/org/objectweb/asm/tree/LabelNode;", $STATIC, $staticMethod(AbstractInsnNode, clone, $LabelNode*, $LabelNode*, $Map*)},
	{"clone", "(Ljava/util/List;Ljava/util/Map;)[Ljdk/internal/org/objectweb/asm/tree/LabelNode;", "(Ljava/util/List<Ljdk/internal/org/objectweb/asm/tree/LabelNode;>;Ljava/util/Map<Ljdk/internal/org/objectweb/asm/tree/LabelNode;Ljdk/internal/org/objectweb/asm/tree/LabelNode;>;)[Ljdk/internal/org/objectweb/asm/tree/LabelNode;", $STATIC, $staticMethod(AbstractInsnNode, clone, $LabelNodeArray*, $List*, $Map*)},
	{"cloneAnnotations", "(Ljdk/internal/org/objectweb/asm/tree/AbstractInsnNode;)Ljdk/internal/org/objectweb/asm/tree/AbstractInsnNode;", nullptr, $PROTECTED | $FINAL, $method(AbstractInsnNode, cloneAnnotations, AbstractInsnNode*, AbstractInsnNode*)},
	{"getNext", "()Ljdk/internal/org/objectweb/asm/tree/AbstractInsnNode;", nullptr, $PUBLIC, $virtualMethod(AbstractInsnNode, getNext, AbstractInsnNode*)},
	{"getOpcode", "()I", nullptr, $PUBLIC, $virtualMethod(AbstractInsnNode, getOpcode, int32_t)},
	{"getPrevious", "()Ljdk/internal/org/objectweb/asm/tree/AbstractInsnNode;", nullptr, $PUBLIC, $virtualMethod(AbstractInsnNode, getPrevious, AbstractInsnNode*)},
	{"getType", "()I", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(AbstractInsnNode, getType, int32_t)},
	{}
};

$ClassInfo _AbstractInsnNode_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"jdk.internal.org.objectweb.asm.tree.AbstractInsnNode",
	"java.lang.Object",
	nullptr,
	_AbstractInsnNode_FieldInfo_,
	_AbstractInsnNode_MethodInfo_
};

$Object* allocate$AbstractInsnNode($Class* clazz) {
	return $of($alloc(AbstractInsnNode));
}

void AbstractInsnNode::init$(int32_t opcode) {
	this->opcode = opcode;
	this->index = -1;
}

int32_t AbstractInsnNode::getOpcode() {
	return this->opcode;
}

AbstractInsnNode* AbstractInsnNode::getPrevious() {
	return this->previousInsn;
}

AbstractInsnNode* AbstractInsnNode::getNext() {
	return this->nextInsn;
}

void AbstractInsnNode::acceptAnnotations($MethodVisitor* methodVisitor) {
	$useLocalCurrentObjectStackCache();
	if (this->visibleTypeAnnotations != nullptr) {
		{
			int32_t i = 0;
			int32_t n = $nc(this->visibleTypeAnnotations)->size();
			for (; i < n; ++i) {
				$var($TypeAnnotationNode, typeAnnotation, $cast($TypeAnnotationNode, $nc(this->visibleTypeAnnotations)->get(i)));
				$nc(typeAnnotation)->accept($($nc(methodVisitor)->visitInsnAnnotation(typeAnnotation->typeRef, typeAnnotation->typePath, typeAnnotation->desc, true)));
			}
		}
	}
	if (this->invisibleTypeAnnotations != nullptr) {
		{
			int32_t i = 0;
			int32_t n = $nc(this->invisibleTypeAnnotations)->size();
			for (; i < n; ++i) {
				$var($TypeAnnotationNode, typeAnnotation, $cast($TypeAnnotationNode, $nc(this->invisibleTypeAnnotations)->get(i)));
				$nc(typeAnnotation)->accept($($nc(methodVisitor)->visitInsnAnnotation(typeAnnotation->typeRef, typeAnnotation->typePath, typeAnnotation->desc, false)));
			}
		}
	}
}

$LabelNode* AbstractInsnNode::clone($LabelNode* label, $Map* clonedLabels) {
	return $cast($LabelNode, $nc(clonedLabels)->get(label));
}

$LabelNodeArray* AbstractInsnNode::clone($List* labels, $Map* clonedLabels) {
	$useLocalCurrentObjectStackCache();
	$var($LabelNodeArray, clones, $new($LabelNodeArray, $nc(labels)->size()));
	{
		int32_t i = 0;
		int32_t n = clones->length;
		for (; i < n; ++i) {
			clones->set(i, $cast($LabelNode, $($nc(clonedLabels)->get($(labels->get(i))))));
		}
	}
	return clones;
}

AbstractInsnNode* AbstractInsnNode::cloneAnnotations(AbstractInsnNode* insnNode) {
	$useLocalCurrentObjectStackCache();
	if ($nc(insnNode)->visibleTypeAnnotations != nullptr) {
		$set(this, visibleTypeAnnotations, $new($ArrayList));
		{
			int32_t i = 0;
			int32_t n = $nc(insnNode->visibleTypeAnnotations)->size();
			for (; i < n; ++i) {
				$var($TypeAnnotationNode, sourceAnnotation, $cast($TypeAnnotationNode, $nc(insnNode->visibleTypeAnnotations)->get(i)));
				$var($TypeAnnotationNode, cloneAnnotation, $new($TypeAnnotationNode, $nc(sourceAnnotation)->typeRef, sourceAnnotation->typePath, sourceAnnotation->desc));
				$nc(sourceAnnotation)->accept(cloneAnnotation);
				$nc(this->visibleTypeAnnotations)->add(cloneAnnotation);
			}
		}
	}
	if ($nc(insnNode)->invisibleTypeAnnotations != nullptr) {
		$set(this, invisibleTypeAnnotations, $new($ArrayList));
		{
			int32_t i = 0;
			int32_t n = $nc(insnNode->invisibleTypeAnnotations)->size();
			for (; i < n; ++i) {
				$var($TypeAnnotationNode, sourceAnnotation, $cast($TypeAnnotationNode, $nc(insnNode->invisibleTypeAnnotations)->get(i)));
				$var($TypeAnnotationNode, cloneAnnotation, $new($TypeAnnotationNode, $nc(sourceAnnotation)->typeRef, sourceAnnotation->typePath, sourceAnnotation->desc));
				$nc(sourceAnnotation)->accept(cloneAnnotation);
				$nc(this->invisibleTypeAnnotations)->add(cloneAnnotation);
			}
		}
	}
	return this;
}

AbstractInsnNode::AbstractInsnNode() {
}

$Class* AbstractInsnNode::load$($String* name, bool initialize) {
	$loadClass(AbstractInsnNode, name, initialize, &_AbstractInsnNode_ClassInfo_, allocate$AbstractInsnNode);
	return class$;
}

$Class* AbstractInsnNode::class$ = nullptr;

					} // tree
				} // asm$
			} // objectweb
		} // org
	} // internal
} // jdk