#include <jdk/internal/org/objectweb/asm/tree/AnnotationNode.h>

#include <java/lang/IllegalStateException.h>
#include <java/util/ArrayList.h>
#include <java/util/List.h>
#include <jdk/internal/org/objectweb/asm/AnnotationVisitor.h>
#include <jdk/internal/org/objectweb/asm/Opcodes.h>
#include <jdk/internal/org/objectweb/asm/tree/Util.h>
#include <jcpp.h>

#undef ASM8

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $MethodInfo = ::java::lang::MethodInfo;
using $ArrayList = ::java::util::ArrayList;
using $List = ::java::util::List;
using $AnnotationVisitor = ::jdk::internal::org::objectweb::asm$::AnnotationVisitor;
using $Opcodes = ::jdk::internal::org::objectweb::asm$::Opcodes;
using $Util = ::jdk::internal::org::objectweb::asm$::tree::Util;

namespace jdk {
	namespace internal {
		namespace org {
			namespace objectweb {
				namespace asm$ {
					namespace tree {

$FieldInfo _AnnotationNode_FieldInfo_[] = {
	{"desc", "Ljava/lang/String;", nullptr, $PUBLIC, $field(AnnotationNode, desc)},
	{"values", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/Object;>;", $PUBLIC, $field(AnnotationNode, values)},
	{}
};

$MethodInfo _AnnotationNode_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(AnnotationNode, init$, void, $String*)},
	{"<init>", "(ILjava/lang/String;)V", nullptr, $PUBLIC, $method(AnnotationNode, init$, void, int32_t, $String*)},
	{"<init>", "(Ljava/util/List;)V", "(Ljava/util/List<Ljava/lang/Object;>;)V", 0, $method(AnnotationNode, init$, void, $List*)},
	{"accept", "(Ljdk/internal/org/objectweb/asm/AnnotationVisitor;)V", nullptr, $PUBLIC, $virtualMethod(AnnotationNode, accept, void, $AnnotationVisitor*)},
	{"accept", "(Ljdk/internal/org/objectweb/asm/AnnotationVisitor;Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $STATIC, $staticMethod(AnnotationNode, accept, void, $AnnotationVisitor*, $String*, Object$*)},
	{"check", "(I)V", nullptr, $PUBLIC, $virtualMethod(AnnotationNode, check, void, int32_t)},
	{"visit", "(Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(AnnotationNode, visit, void, $String*, Object$*)},
	{"visitAnnotation", "(Ljava/lang/String;Ljava/lang/String;)Ljdk/internal/org/objectweb/asm/AnnotationVisitor;", nullptr, $PUBLIC, $virtualMethod(AnnotationNode, visitAnnotation, $AnnotationVisitor*, $String*, $String*)},
	{"visitArray", "(Ljava/lang/String;)Ljdk/internal/org/objectweb/asm/AnnotationVisitor;", nullptr, $PUBLIC, $virtualMethod(AnnotationNode, visitArray, $AnnotationVisitor*, $String*)},
	{"visitEnd", "()V", nullptr, $PUBLIC, $virtualMethod(AnnotationNode, visitEnd, void)},
	{"visitEnum", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(AnnotationNode, visitEnum, void, $String*, $String*, $String*)},
	{}
};

$ClassInfo _AnnotationNode_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.org.objectweb.asm.tree.AnnotationNode",
	"jdk.internal.org.objectweb.asm.AnnotationVisitor",
	nullptr,
	_AnnotationNode_FieldInfo_,
	_AnnotationNode_MethodInfo_
};

$Object* allocate$AnnotationNode($Class* clazz) {
	return $of($alloc(AnnotationNode));
}

void AnnotationNode::init$($String* descriptor) {
	AnnotationNode::init$($Opcodes::ASM8, descriptor);
	if ($of(this)->getClass() != AnnotationNode::class$) {
		$throwNew($IllegalStateException);
	}
}

void AnnotationNode::init$(int32_t api, $String* descriptor) {
	$AnnotationVisitor::init$(api);
	$set(this, desc, descriptor);
}

void AnnotationNode::init$($List* values) {
	$AnnotationVisitor::init$($Opcodes::ASM8);
	$set(this, values, values);
}

void AnnotationNode::visit($String* name, Object$* value) {
	$useLocalCurrentObjectStackCache();
	if (this->values == nullptr) {
		$set(this, values, $new($ArrayList, this->desc != nullptr ? 2 : 1));
	}
	if (this->desc != nullptr) {
		$nc(this->values)->add(name);
	}
	if ($instanceOf($bytes, value)) {
		$nc(this->values)->add($($Util::asArrayList($cast($bytes, value))));
	} else if ($instanceOf($booleans, value)) {
		$nc(this->values)->add($($Util::asArrayList($cast($booleans, value))));
	} else if ($instanceOf($shorts, value)) {
		$nc(this->values)->add($($Util::asArrayList($cast($shorts, value))));
	} else if ($instanceOf($chars, value)) {
		$nc(this->values)->add($($Util::asArrayList($cast($chars, value))));
	} else if ($instanceOf($ints, value)) {
		$nc(this->values)->add($($Util::asArrayList($cast($ints, value))));
	} else if ($instanceOf($longs, value)) {
		$nc(this->values)->add($($Util::asArrayList($cast($longs, value))));
	} else if ($instanceOf($floats, value)) {
		$nc(this->values)->add($($Util::asArrayList($cast($floats, value))));
	} else if ($instanceOf($doubles, value)) {
		$nc(this->values)->add($($Util::asArrayList($cast($doubles, value))));
	} else {
		$nc(this->values)->add(value);
	}
}

void AnnotationNode::visitEnum($String* name, $String* descriptor, $String* value) {
	if (this->values == nullptr) {
		$set(this, values, $new($ArrayList, this->desc != nullptr ? 2 : 1));
	}
	if (this->desc != nullptr) {
		$nc(this->values)->add(name);
	}
	$nc(this->values)->add($$new($StringArray, {
		descriptor,
		value
	}));
}

$AnnotationVisitor* AnnotationNode::visitAnnotation($String* name, $String* descriptor) {
	if (this->values == nullptr) {
		$set(this, values, $new($ArrayList, this->desc != nullptr ? 2 : 1));
	}
	if (this->desc != nullptr) {
		$nc(this->values)->add(name);
	}
	$var(AnnotationNode, annotation, $new(AnnotationNode, descriptor));
	$nc(this->values)->add(annotation);
	return annotation;
}

$AnnotationVisitor* AnnotationNode::visitArray($String* name) {
	if (this->values == nullptr) {
		$set(this, values, $new($ArrayList, this->desc != nullptr ? 2 : 1));
	}
	if (this->desc != nullptr) {
		$nc(this->values)->add(name);
	}
	$var($List, array, $new($ArrayList));
	$nc(this->values)->add(array);
	return $new(AnnotationNode, array);
}

void AnnotationNode::visitEnd() {
}

void AnnotationNode::check(int32_t api) {
}

void AnnotationNode::accept($AnnotationVisitor* annotationVisitor) {
	$useLocalCurrentObjectStackCache();
	if (annotationVisitor != nullptr) {
		if (this->values != nullptr) {
			{
				int32_t i = 0;
				int32_t n = $nc(this->values)->size();
				for (; i < n; i += 2) {
					$var($String, name, $cast($String, $nc(this->values)->get(i)));
					$var($Object, value, $nc(this->values)->get(i + 1));
					accept(annotationVisitor, name, value);
				}
			}
		}
		annotationVisitor->visitEnd();
	}
}

void AnnotationNode::accept($AnnotationVisitor* annotationVisitor, $String* name, Object$* value) {
	$init(AnnotationNode);
	$useLocalCurrentObjectStackCache();
	if (annotationVisitor != nullptr) {
		if ($instanceOf($StringArray, value)) {
			$var($StringArray, typeValue, $cast($StringArray, value));
			annotationVisitor->visitEnum(name, $nc(typeValue)->get(0), typeValue->get(1));
		} else if ($instanceOf(AnnotationNode, value)) {
			$var(AnnotationNode, annotationValue, $cast(AnnotationNode, value));
			$nc(annotationValue)->accept($(annotationVisitor->visitAnnotation(name, annotationValue->desc)));
		} else if ($instanceOf($List, value)) {
			$var($AnnotationVisitor, arrayAnnotationVisitor, annotationVisitor->visitArray(name));
			if (arrayAnnotationVisitor != nullptr) {
				$var($List, arrayValue, $cast($List, value));
				{
					int32_t i = 0;
					int32_t n = $nc(arrayValue)->size();
					for (; i < n; ++i) {
						accept(arrayAnnotationVisitor, nullptr, $(arrayValue->get(i)));
					}
				}
				arrayAnnotationVisitor->visitEnd();
			}
		} else {
			annotationVisitor->visit(name, value);
		}
	}
}

AnnotationNode::AnnotationNode() {
}

$Class* AnnotationNode::load$($String* name, bool initialize) {
	$loadClass(AnnotationNode, name, initialize, &_AnnotationNode_ClassInfo_, allocate$AnnotationNode);
	return class$;
}

$Class* AnnotationNode::class$ = nullptr;

					} // tree
				} // asm$
			} // objectweb
		} // org
	} // internal
} // jdk