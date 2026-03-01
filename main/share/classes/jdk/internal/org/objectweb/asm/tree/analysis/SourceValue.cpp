#include <jdk/internal/org/objectweb/asm/tree/analysis/SourceValue.h>

#include <java/util/Set.h>
#include <jdk/internal/org/objectweb/asm/tree/AbstractInsnNode.h>
#include <jdk/internal/org/objectweb/asm/tree/analysis/SmallSet.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Set = ::java::util::Set;
using $AbstractInsnNode = ::jdk::internal::org::objectweb::asm$::tree::AbstractInsnNode;
using $SmallSet = ::jdk::internal::org::objectweb::asm$::tree::analysis::SmallSet;

namespace jdk {
	namespace internal {
		namespace org {
			namespace objectweb {
				namespace asm$ {
					namespace tree {
						namespace analysis {

$FieldInfo _SourceValue_FieldInfo_[] = {
	{"size", "I", nullptr, $PUBLIC | $FINAL, $field(SourceValue, size)},
	{"insns", "Ljava/util/Set;", "Ljava/util/Set<Ljdk/internal/org/objectweb/asm/tree/AbstractInsnNode;>;", $PUBLIC | $FINAL, $field(SourceValue, insns)},
	{}
};

$MethodInfo _SourceValue_MethodInfo_[] = {
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(SourceValue, init$, void, int32_t)},
	{"<init>", "(ILjdk/internal/org/objectweb/asm/tree/AbstractInsnNode;)V", nullptr, $PUBLIC, $method(SourceValue, init$, void, int32_t, $AbstractInsnNode*)},
	{"<init>", "(ILjava/util/Set;)V", "(ILjava/util/Set<Ljdk/internal/org/objectweb/asm/tree/AbstractInsnNode;>;)V", $PUBLIC, $method(SourceValue, init$, void, int32_t, $Set*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(SourceValue, equals, bool, Object$*)},
	{"getSize", "()I", nullptr, $PUBLIC, $virtualMethod(SourceValue, getSize, int32_t)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(SourceValue, hashCode, int32_t)},
	{}
};

$ClassInfo _SourceValue_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.org.objectweb.asm.tree.analysis.SourceValue",
	"java.lang.Object",
	"jdk.internal.org.objectweb.asm.tree.analysis.Value",
	_SourceValue_FieldInfo_,
	_SourceValue_MethodInfo_
};

$Object* allocate$SourceValue($Class* clazz) {
	return $of($alloc(SourceValue));
}

void SourceValue::init$(int32_t size) {
	SourceValue::init$(size, static_cast<$Set*>($$new($SmallSet)));
}

void SourceValue::init$(int32_t size, $AbstractInsnNode* insnNode) {
	this->size = size;
	$set(this, insns, $new($SmallSet, insnNode));
}

void SourceValue::init$(int32_t size, $Set* insnSet) {
	this->size = size;
	$set(this, insns, insnSet);
}

int32_t SourceValue::getSize() {
	return this->size;
}

bool SourceValue::equals(Object$* value) {
	if (!($instanceOf(SourceValue, value))) {
		return false;
	}
	$var(SourceValue, sourceValue, $cast(SourceValue, value));
	return this->size == $nc(sourceValue)->size && $nc(this->insns)->equals(sourceValue->insns);
}

int32_t SourceValue::hashCode() {
	return $nc(this->insns)->hashCode();
}

SourceValue::SourceValue() {
}

$Class* SourceValue::load$($String* name, bool initialize) {
	$loadClass(SourceValue, name, initialize, &_SourceValue_ClassInfo_, allocate$SourceValue);
	return class$;
}

$Class* SourceValue::class$ = nullptr;

						} // analysis
					} // tree
				} // asm$
			} // objectweb
		} // org
	} // internal
} // jdk