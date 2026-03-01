#include <jdk/internal/org/objectweb/asm/tree/FrameNode.h>

#include <java/util/ArrayList.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <jdk/internal/org/objectweb/asm/Label.h>
#include <jdk/internal/org/objectweb/asm/MethodVisitor.h>
#include <jdk/internal/org/objectweb/asm/Opcodes.h>
#include <jdk/internal/org/objectweb/asm/tree/AbstractInsnNode.h>
#include <jdk/internal/org/objectweb/asm/tree/LabelNode.h>
#include <jdk/internal/org/objectweb/asm/tree/Util.h>
#include <jcpp.h>

#undef FRAME
#undef F_APPEND
#undef F_CHOP
#undef F_FULL
#undef F_NEW
#undef F_SAME
#undef F_SAME1

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $ArrayList = ::java::util::ArrayList;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $MethodVisitor = ::jdk::internal::org::objectweb::asm$::MethodVisitor;
using $Opcodes = ::jdk::internal::org::objectweb::asm$::Opcodes;
using $AbstractInsnNode = ::jdk::internal::org::objectweb::asm$::tree::AbstractInsnNode;
using $LabelNode = ::jdk::internal::org::objectweb::asm$::tree::LabelNode;
using $Util = ::jdk::internal::org::objectweb::asm$::tree::Util;

namespace jdk {
	namespace internal {
		namespace org {
			namespace objectweb {
				namespace asm$ {
					namespace tree {

$FieldInfo _FrameNode_FieldInfo_[] = {
	{"type", "I", nullptr, $PUBLIC, $field(FrameNode, type)},
	{"local", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/Object;>;", $PUBLIC, $field(FrameNode, local)},
	{"stack", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/Object;>;", $PUBLIC, $field(FrameNode, stack)},
	{}
};

$MethodInfo _FrameNode_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(FrameNode, init$, void)},
	{"<init>", "(II[Ljava/lang/Object;I[Ljava/lang/Object;)V", nullptr, $PUBLIC, $method(FrameNode, init$, void, int32_t, int32_t, $ObjectArray*, int32_t, $ObjectArray*)},
	{"accept", "(Ljdk/internal/org/objectweb/asm/MethodVisitor;)V", nullptr, $PUBLIC, $virtualMethod(FrameNode, accept, void, $MethodVisitor*)},
	{"asArray", "(Ljava/util/List;)[Ljava/lang/Object;", "(Ljava/util/List<Ljava/lang/Object;>;)[Ljava/lang/Object;", $PRIVATE | $STATIC, $staticMethod(FrameNode, asArray, $ObjectArray*, $List*)},
	{"clone", "(Ljava/util/Map;)Ljdk/internal/org/objectweb/asm/tree/AbstractInsnNode;", "(Ljava/util/Map<Ljdk/internal/org/objectweb/asm/tree/LabelNode;Ljdk/internal/org/objectweb/asm/tree/LabelNode;>;)Ljdk/internal/org/objectweb/asm/tree/AbstractInsnNode;", $PUBLIC, $virtualMethod(FrameNode, clone, $AbstractInsnNode*, $Map*)},
	{"getType", "()I", nullptr, $PUBLIC, $virtualMethod(FrameNode, getType, int32_t)},
	{}
};

$ClassInfo _FrameNode_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.org.objectweb.asm.tree.FrameNode",
	"jdk.internal.org.objectweb.asm.tree.AbstractInsnNode",
	nullptr,
	_FrameNode_FieldInfo_,
	_FrameNode_MethodInfo_
};

$Object* allocate$FrameNode($Class* clazz) {
	return $of($alloc(FrameNode));
}

void FrameNode::init$() {
	$AbstractInsnNode::init$(-1);
}

void FrameNode::init$(int32_t type, int32_t numLocal, $ObjectArray* local, int32_t numStack, $ObjectArray* stack) {
	$AbstractInsnNode::init$(-1);
	this->type = type;
	switch (type) {
	case $Opcodes::F_NEW:
		{}
	case $Opcodes::F_FULL:
		{
			$set(this, local, $Util::asArrayList(numLocal, local));
			$set(this, stack, $Util::asArrayList(numStack, stack));
			break;
		}
	case $Opcodes::F_APPEND:
		{
			$set(this, local, $Util::asArrayList(numLocal, local));
			break;
		}
	case $Opcodes::F_CHOP:
		{
			$set(this, local, $Util::asArrayList(numLocal));
			break;
		}
	case $Opcodes::F_SAME:
		{
			break;
		}
	case $Opcodes::F_SAME1:
		{
			$set(this, stack, $Util::asArrayList(1, stack));
			break;
		}
	default:
		{
			$throwNew($IllegalArgumentException);
		}
	}
}

int32_t FrameNode::getType() {
	return $AbstractInsnNode::FRAME;
}

void FrameNode::accept($MethodVisitor* methodVisitor) {
	$useLocalCurrentObjectStackCache();
	switch (this->type) {
	case $Opcodes::F_NEW:
		{}
	case $Opcodes::F_FULL:
		{
			int32_t var$0 = this->type;
			int32_t var$1 = $nc(this->local)->size();
			$var($ObjectArray, var$2, asArray(this->local));
			int32_t var$3 = $nc(this->stack)->size();
			$nc(methodVisitor)->visitFrame(var$0, var$1, var$2, var$3, $(asArray(this->stack)));
			break;
		}
	case $Opcodes::F_APPEND:
		{
			int32_t var$4 = this->type;
			int32_t var$5 = $nc(this->local)->size();
			$nc(methodVisitor)->visitFrame(var$4, var$5, $(asArray(this->local)), 0, nullptr);
			break;
		}
	case $Opcodes::F_CHOP:
		{
			$nc(methodVisitor)->visitFrame(this->type, $nc(this->local)->size(), nullptr, 0, nullptr);
			break;
		}
	case $Opcodes::F_SAME:
		{
			$nc(methodVisitor)->visitFrame(this->type, 0, nullptr, 0, nullptr);
			break;
		}
	case $Opcodes::F_SAME1:
		{
			$nc(methodVisitor)->visitFrame(this->type, 0, nullptr, 1, $(asArray(this->stack)));
			break;
		}
	default:
		{
			$throwNew($IllegalArgumentException);
		}
	}
}

$AbstractInsnNode* FrameNode::clone($Map* clonedLabels) {
	$useLocalCurrentObjectStackCache();
	$var(FrameNode, clone, $new(FrameNode));
	clone->type = this->type;
	if (this->local != nullptr) {
		$set(clone, local, $new($ArrayList));
		{
			int32_t i = 0;
			int32_t n = $nc(this->local)->size();
			for (; i < n; ++i) {
				$var($Object, localElement, $nc(this->local)->get(i));
				if ($instanceOf($LabelNode, localElement)) {
					$assign(localElement, $nc(clonedLabels)->get(localElement));
				}
				$nc(clone->local)->add(localElement);
			}
		}
	}
	if (this->stack != nullptr) {
		$set(clone, stack, $new($ArrayList));
		{
			int32_t i = 0;
			int32_t n = $nc(this->stack)->size();
			for (; i < n; ++i) {
				$var($Object, stackElement, $nc(this->stack)->get(i));
				if ($instanceOf($LabelNode, stackElement)) {
					$assign(stackElement, $nc(clonedLabels)->get(stackElement));
				}
				$nc(clone->stack)->add(stackElement);
			}
		}
	}
	return clone;
}

$ObjectArray* FrameNode::asArray($List* list) {
	$init(FrameNode);
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, array, $new($ObjectArray, $nc(list)->size()));
	{
		int32_t i = 0;
		int32_t n = array->length;
		for (; i < n; ++i) {
			$var($Object, o, list->get(i));
			if ($instanceOf($LabelNode, o)) {
				$assign(o, $nc(($cast($LabelNode, o)))->getLabel());
			}
			array->set(i, o);
		}
	}
	return array;
}

FrameNode::FrameNode() {
}

$Class* FrameNode::load$($String* name, bool initialize) {
	$loadClass(FrameNode, name, initialize, &_FrameNode_ClassInfo_, allocate$FrameNode);
	return class$;
}

$Class* FrameNode::class$ = nullptr;

					} // tree
				} // asm$
			} // objectweb
		} // org
	} // internal
} // jdk