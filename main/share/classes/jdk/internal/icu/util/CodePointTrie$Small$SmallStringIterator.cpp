#include <jdk/internal/icu/util/CodePointTrie$Small$SmallStringIterator.h>

#include <java/lang/CharSequence.h>
#include <jdk/internal/icu/impl/NormalizerImpl$UTF16Plus.h>
#include <jdk/internal/icu/util/CodePointMap$StringIterator.h>
#include <jdk/internal/icu/util/CodePointMap.h>
#include <jdk/internal/icu/util/CodePointTrie$Data.h>
#include <jdk/internal/icu/util/CodePointTrie$Small.h>
#include <jdk/internal/icu/util/CodePointTrie$Type.h>
#include <jcpp.h>

#undef SMALL

using $CharSequence = ::java::lang::CharSequence;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NormalizerImpl$UTF16Plus = ::jdk::internal::icu::impl::NormalizerImpl$UTF16Plus;
using $CodePointMap = ::jdk::internal::icu::util::CodePointMap;
using $CodePointMap$StringIterator = ::jdk::internal::icu::util::CodePointMap$StringIterator;
using $CodePointTrie$Data = ::jdk::internal::icu::util::CodePointTrie$Data;
using $CodePointTrie$Small = ::jdk::internal::icu::util::CodePointTrie$Small;
using $CodePointTrie$Type = ::jdk::internal::icu::util::CodePointTrie$Type;

namespace jdk {
	namespace internal {
		namespace icu {
			namespace util {

$FieldInfo _CodePointTrie$Small$SmallStringIterator_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/icu/util/CodePointTrie$Small;", nullptr, $FINAL | $SYNTHETIC, $field(CodePointTrie$Small$SmallStringIterator, this$0)},
	{}
};

$MethodInfo _CodePointTrie$Small$SmallStringIterator_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/icu/util/CodePointTrie$Small;Ljava/lang/CharSequence;I)V", nullptr, $PRIVATE, $method(CodePointTrie$Small$SmallStringIterator, init$, void, $CodePointTrie$Small*, $CharSequence*, int32_t)},
	{"next", "()Z", nullptr, $PUBLIC, $virtualMethod(CodePointTrie$Small$SmallStringIterator, next, bool)},
	{"previous", "()Z", nullptr, $PUBLIC, $virtualMethod(CodePointTrie$Small$SmallStringIterator, previous, bool)},
	{}
};

$InnerClassInfo _CodePointTrie$Small$SmallStringIterator_InnerClassesInfo_[] = {
	{"jdk.internal.icu.util.CodePointTrie$Small", "jdk.internal.icu.util.CodePointTrie", "Small", $PUBLIC | $STATIC | $ABSTRACT},
	{"jdk.internal.icu.util.CodePointTrie$Small$SmallStringIterator", "jdk.internal.icu.util.CodePointTrie$Small", "SmallStringIterator", $PRIVATE | $FINAL},
	{"jdk.internal.icu.util.CodePointMap$StringIterator", "jdk.internal.icu.util.CodePointMap", "StringIterator", $PUBLIC},
	{}
};

$ClassInfo _CodePointTrie$Small$SmallStringIterator_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.icu.util.CodePointTrie$Small$SmallStringIterator",
	"jdk.internal.icu.util.CodePointMap$StringIterator",
	nullptr,
	_CodePointTrie$Small$SmallStringIterator_FieldInfo_,
	_CodePointTrie$Small$SmallStringIterator_MethodInfo_,
	nullptr,
	nullptr,
	_CodePointTrie$Small$SmallStringIterator_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.icu.util.CodePointTrie"
};

$Object* allocate$CodePointTrie$Small$SmallStringIterator($Class* clazz) {
	return $of($alloc(CodePointTrie$Small$SmallStringIterator));
}

void CodePointTrie$Small$SmallStringIterator::init$($CodePointTrie$Small* this$0, $CharSequence* s, int32_t sIndex) {
	$set(this, this$0, this$0);
	$CodePointMap$StringIterator::init$(this$0, s, sIndex);
}

bool CodePointTrie$Small$SmallStringIterator::next() {
	if (this->sIndex >= $nc(this->s)->length()) {
		return false;
	}
	char16_t lead = $nc(this->s)->charAt(this->sIndex++);
	this->c = lead;
	int32_t dataIndex = 0;
	if (!$Character::isSurrogate(lead)) {
		dataIndex = this->this$0->cpIndex(this->c);
	} else {
		char16_t trail = 0;
		bool var$1 = $NormalizerImpl$UTF16Plus::isSurrogateLead(lead);
		bool var$0 = var$1 && this->sIndex < $nc(this->s)->length();
		if (var$0 && $Character::isLowSurrogate(trail = $nc(this->s)->charAt(this->sIndex))) {
			++this->sIndex;
			this->c = $Character::toCodePoint(lead, trail);
			$init($CodePointTrie$Type);
			dataIndex = this->this$0->smallIndex($CodePointTrie$Type::SMALL, this->c);
		} else {
			dataIndex = this->this$0->dataLength - 1;
		}
	}
	this->value = $nc(this->this$0->data)->getFromIndex(dataIndex);
	return true;
}

bool CodePointTrie$Small$SmallStringIterator::previous() {
	if (this->sIndex <= 0) {
		return false;
	}
	char16_t trail = $nc(this->s)->charAt(--this->sIndex);
	this->c = trail;
	int32_t dataIndex = 0;
	if (!$Character::isSurrogate(trail)) {
		dataIndex = this->this$0->cpIndex(this->c);
	} else {
		char16_t lead = 0;
		bool var$0 = !$NormalizerImpl$UTF16Plus::isSurrogateLead(trail) && this->sIndex > 0;
		if (var$0 && $Character::isHighSurrogate(lead = $nc(this->s)->charAt(this->sIndex - 1))) {
			--this->sIndex;
			this->c = $Character::toCodePoint(lead, trail);
			$init($CodePointTrie$Type);
			dataIndex = this->this$0->smallIndex($CodePointTrie$Type::SMALL, this->c);
		} else {
			dataIndex = this->this$0->dataLength - 1;
		}
	}
	this->value = $nc(this->this$0->data)->getFromIndex(dataIndex);
	return true;
}

CodePointTrie$Small$SmallStringIterator::CodePointTrie$Small$SmallStringIterator() {
}

$Class* CodePointTrie$Small$SmallStringIterator::load$($String* name, bool initialize) {
	$loadClass(CodePointTrie$Small$SmallStringIterator, name, initialize, &_CodePointTrie$Small$SmallStringIterator_ClassInfo_, allocate$CodePointTrie$Small$SmallStringIterator);
	return class$;
}

$Class* CodePointTrie$Small$SmallStringIterator::class$ = nullptr;

			} // util
		} // icu
	} // internal
} // jdk