#include <jdk/internal/icu/util/CodePointTrie$Fast$FastStringIterator.h>

#include <java/lang/CharSequence.h>
#include <jdk/internal/icu/impl/NormalizerImpl$UTF16Plus.h>
#include <jdk/internal/icu/util/CodePointMap$StringIterator.h>
#include <jdk/internal/icu/util/CodePointMap.h>
#include <jdk/internal/icu/util/CodePointTrie$Data.h>
#include <jdk/internal/icu/util/CodePointTrie$Fast.h>
#include <jdk/internal/icu/util/CodePointTrie$Type.h>
#include <jcpp.h>

#undef FAST

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
using $CodePointTrie$Fast = ::jdk::internal::icu::util::CodePointTrie$Fast;
using $CodePointTrie$Type = ::jdk::internal::icu::util::CodePointTrie$Type;

namespace jdk {
	namespace internal {
		namespace icu {
			namespace util {

$FieldInfo _CodePointTrie$Fast$FastStringIterator_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/icu/util/CodePointTrie$Fast;", nullptr, $FINAL | $SYNTHETIC, $field(CodePointTrie$Fast$FastStringIterator, this$0)},
	{}
};

$MethodInfo _CodePointTrie$Fast$FastStringIterator_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/icu/util/CodePointTrie$Fast;Ljava/lang/CharSequence;I)V", nullptr, $PRIVATE, $method(CodePointTrie$Fast$FastStringIterator, init$, void, $CodePointTrie$Fast*, $CharSequence*, int32_t)},
	{"next", "()Z", nullptr, $PUBLIC, $virtualMethod(CodePointTrie$Fast$FastStringIterator, next, bool)},
	{"previous", "()Z", nullptr, $PUBLIC, $virtualMethod(CodePointTrie$Fast$FastStringIterator, previous, bool)},
	{}
};

$InnerClassInfo _CodePointTrie$Fast$FastStringIterator_InnerClassesInfo_[] = {
	{"jdk.internal.icu.util.CodePointTrie$Fast", "jdk.internal.icu.util.CodePointTrie", "Fast", $PUBLIC | $STATIC | $ABSTRACT},
	{"jdk.internal.icu.util.CodePointTrie$Fast$FastStringIterator", "jdk.internal.icu.util.CodePointTrie$Fast", "FastStringIterator", $PRIVATE | $FINAL},
	{"jdk.internal.icu.util.CodePointMap$StringIterator", "jdk.internal.icu.util.CodePointMap", "StringIterator", $PUBLIC},
	{}
};

$ClassInfo _CodePointTrie$Fast$FastStringIterator_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.icu.util.CodePointTrie$Fast$FastStringIterator",
	"jdk.internal.icu.util.CodePointMap$StringIterator",
	nullptr,
	_CodePointTrie$Fast$FastStringIterator_FieldInfo_,
	_CodePointTrie$Fast$FastStringIterator_MethodInfo_,
	nullptr,
	nullptr,
	_CodePointTrie$Fast$FastStringIterator_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.icu.util.CodePointTrie"
};

$Object* allocate$CodePointTrie$Fast$FastStringIterator($Class* clazz) {
	return $of($alloc(CodePointTrie$Fast$FastStringIterator));
}

void CodePointTrie$Fast$FastStringIterator::init$($CodePointTrie$Fast* this$0, $CharSequence* s, int32_t sIndex) {
	$set(this, this$0, this$0);
	$CodePointMap$StringIterator::init$(this$0, s, sIndex);
}

bool CodePointTrie$Fast$FastStringIterator::next() {
	if (this->sIndex >= $nc(this->s)->length()) {
		return false;
	}
	char16_t lead = $nc(this->s)->charAt(this->sIndex++);
	this->c = lead;
	int32_t dataIndex = 0;
	if (!$Character::isSurrogate(lead)) {
		dataIndex = this->this$0->fastIndex(this->c);
	} else {
		char16_t trail = 0;
		bool var$1 = $NormalizerImpl$UTF16Plus::isSurrogateLead(lead);
		bool var$0 = var$1 && this->sIndex < $nc(this->s)->length();
		if (var$0 && $Character::isLowSurrogate(trail = $nc(this->s)->charAt(this->sIndex))) {
			++this->sIndex;
			this->c = $Character::toCodePoint(lead, trail);
			$init($CodePointTrie$Type);
			dataIndex = this->this$0->smallIndex($CodePointTrie$Type::FAST, this->c);
		} else {
			dataIndex = this->this$0->dataLength - 1;
		}
	}
	this->value = $nc(this->this$0->data)->getFromIndex(dataIndex);
	return true;
}

bool CodePointTrie$Fast$FastStringIterator::previous() {
	if (this->sIndex <= 0) {
		return false;
	}
	char16_t trail = $nc(this->s)->charAt(--this->sIndex);
	this->c = trail;
	int32_t dataIndex = 0;
	if (!$Character::isSurrogate(trail)) {
		dataIndex = this->this$0->fastIndex(this->c);
	} else {
		char16_t lead = 0;
		bool var$0 = !$NormalizerImpl$UTF16Plus::isSurrogateLead(trail) && this->sIndex > 0;
		if (var$0 && $Character::isHighSurrogate(lead = $nc(this->s)->charAt(this->sIndex - 1))) {
			--this->sIndex;
			this->c = $Character::toCodePoint(lead, trail);
			$init($CodePointTrie$Type);
			dataIndex = this->this$0->smallIndex($CodePointTrie$Type::FAST, this->c);
		} else {
			dataIndex = this->this$0->dataLength - 1;
		}
	}
	this->value = $nc(this->this$0->data)->getFromIndex(dataIndex);
	return true;
}

CodePointTrie$Fast$FastStringIterator::CodePointTrie$Fast$FastStringIterator() {
}

$Class* CodePointTrie$Fast$FastStringIterator::load$($String* name, bool initialize) {
	$loadClass(CodePointTrie$Fast$FastStringIterator, name, initialize, &_CodePointTrie$Fast$FastStringIterator_ClassInfo_, allocate$CodePointTrie$Fast$FastStringIterator);
	return class$;
}

$Class* CodePointTrie$Fast$FastStringIterator::class$ = nullptr;

			} // util
		} // icu
	} // internal
} // jdk