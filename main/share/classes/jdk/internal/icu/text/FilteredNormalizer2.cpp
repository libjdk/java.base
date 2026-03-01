#include <jdk/internal/icu/text/FilteredNormalizer2.h>

#include <java/io/IOException.h>
#include <java/lang/Appendable.h>
#include <java/lang/CharSequence.h>
#include <java/lang/InternalError.h>
#include <jdk/internal/icu/text/Normalizer2.h>
#include <jdk/internal/icu/text/UnicodeSet$SpanCondition.h>
#include <jdk/internal/icu/text/UnicodeSet.h>
#include <jcpp.h>

#undef NOT_CONTAINED
#undef SIMPLE

using $IOException = ::java::io::IOException;
using $Appendable = ::java::lang::Appendable;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $Normalizer2 = ::jdk::internal::icu::text::Normalizer2;
using $UnicodeSet = ::jdk::internal::icu::text::UnicodeSet;
using $UnicodeSet$SpanCondition = ::jdk::internal::icu::text::UnicodeSet$SpanCondition;

namespace jdk {
	namespace internal {
		namespace icu {
			namespace text {

$FieldInfo _FilteredNormalizer2_FieldInfo_[] = {
	{"norm2", "Ljdk/internal/icu/text/Normalizer2;", nullptr, $PRIVATE, $field(FilteredNormalizer2, norm2)},
	{"set", "Ljdk/internal/icu/text/UnicodeSet;", nullptr, $PRIVATE, $field(FilteredNormalizer2, set)},
	{}
};

$MethodInfo _FilteredNormalizer2_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/icu/text/Normalizer2;Ljdk/internal/icu/text/UnicodeSet;)V", nullptr, $PUBLIC, $method(FilteredNormalizer2, init$, void, $Normalizer2*, $UnicodeSet*)},
	{"append", "(Ljava/lang/StringBuilder;Ljava/lang/CharSequence;)Ljava/lang/StringBuilder;", nullptr, $PUBLIC, $virtualMethod(FilteredNormalizer2, append, $StringBuilder*, $StringBuilder*, $CharSequence*)},
	{"getCombiningClass", "(I)I", nullptr, $PUBLIC, $virtualMethod(FilteredNormalizer2, getCombiningClass, int32_t, int32_t)},
	{"getDecomposition", "(I)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(FilteredNormalizer2, getDecomposition, $String*, int32_t)},
	{"hasBoundaryBefore", "(I)Z", nullptr, $PUBLIC, $virtualMethod(FilteredNormalizer2, hasBoundaryBefore, bool, int32_t)},
	{"isNormalized", "(Ljava/lang/CharSequence;)Z", nullptr, $PUBLIC, $virtualMethod(FilteredNormalizer2, isNormalized, bool, $CharSequence*)},
	{"normalize", "(Ljava/lang/CharSequence;Ljava/lang/StringBuilder;)Ljava/lang/StringBuilder;", nullptr, $PUBLIC, $virtualMethod(FilteredNormalizer2, normalize, $StringBuilder*, $CharSequence*, $StringBuilder*)},
	{"normalize", "(Ljava/lang/CharSequence;Ljava/lang/Appendable;)Ljava/lang/Appendable;", nullptr, $PUBLIC, $virtualMethod(FilteredNormalizer2, normalize, $Appendable*, $CharSequence*, $Appendable*)},
	{"normalize", "(Ljava/lang/CharSequence;Ljava/lang/Appendable;Ljdk/internal/icu/text/UnicodeSet$SpanCondition;)Ljava/lang/Appendable;", nullptr, $PRIVATE, $method(FilteredNormalizer2, normalize, $Appendable*, $CharSequence*, $Appendable*, $UnicodeSet$SpanCondition*)},
	{"normalizeSecondAndAppend", "(Ljava/lang/StringBuilder;Ljava/lang/CharSequence;)Ljava/lang/StringBuilder;", nullptr, $PUBLIC, $virtualMethod(FilteredNormalizer2, normalizeSecondAndAppend, $StringBuilder*, $StringBuilder*, $CharSequence*)},
	{"normalizeSecondAndAppend", "(Ljava/lang/StringBuilder;Ljava/lang/CharSequence;Z)Ljava/lang/StringBuilder;", nullptr, $PRIVATE, $method(FilteredNormalizer2, normalizeSecondAndAppend, $StringBuilder*, $StringBuilder*, $CharSequence*, bool)},
	{"spanQuickCheckYes", "(Ljava/lang/CharSequence;)I", nullptr, $PUBLIC, $virtualMethod(FilteredNormalizer2, spanQuickCheckYes, int32_t, $CharSequence*)},
	{}
};

$ClassInfo _FilteredNormalizer2_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.icu.text.FilteredNormalizer2",
	"jdk.internal.icu.text.Normalizer2",
	nullptr,
	_FilteredNormalizer2_FieldInfo_,
	_FilteredNormalizer2_MethodInfo_
};

$Object* allocate$FilteredNormalizer2($Class* clazz) {
	return $of($alloc(FilteredNormalizer2));
}

void FilteredNormalizer2::init$($Normalizer2* n2, $UnicodeSet* filterSet) {
	$Normalizer2::init$();
	$set(this, norm2, n2);
	$set(this, set, filterSet);
}

$StringBuilder* FilteredNormalizer2::normalize($CharSequence* src, $StringBuilder* dest) {
	if ($equals(dest, src)) {
		$throwNew($IllegalArgumentException);
	}
	$nc(dest)->setLength(0);
	$init($UnicodeSet$SpanCondition);
	normalize(src, dest, $UnicodeSet$SpanCondition::SIMPLE);
	return dest;
}

$Appendable* FilteredNormalizer2::normalize($CharSequence* src, $Appendable* dest) {
	if ($equals(dest, src)) {
		$throwNew($IllegalArgumentException);
	}
	$init($UnicodeSet$SpanCondition);
	return normalize(src, dest, $UnicodeSet$SpanCondition::SIMPLE);
}

$StringBuilder* FilteredNormalizer2::normalizeSecondAndAppend($StringBuilder* first, $CharSequence* second) {
	return normalizeSecondAndAppend(first, second, true);
}

$StringBuilder* FilteredNormalizer2::append($StringBuilder* first, $CharSequence* second) {
	return normalizeSecondAndAppend(first, second, false);
}

$String* FilteredNormalizer2::getDecomposition(int32_t c) {
	return $nc(this->set)->contains(c) ? $nc(this->norm2)->getDecomposition(c) : ($String*)nullptr;
}

int32_t FilteredNormalizer2::getCombiningClass(int32_t c) {
	return $nc(this->set)->contains(c) ? $nc(this->norm2)->getCombiningClass(c) : 0;
}

bool FilteredNormalizer2::isNormalized($CharSequence* s) {
	$useLocalCurrentObjectStackCache();
	$init($UnicodeSet$SpanCondition);
	$UnicodeSet$SpanCondition* spanCondition = $UnicodeSet$SpanCondition::SIMPLE;
	for (int32_t prevSpanLimit = 0; prevSpanLimit < $nc(s)->length();) {
		int32_t spanLimit = $nc(this->set)->span(s, prevSpanLimit, spanCondition);
		if (spanCondition == $UnicodeSet$SpanCondition::NOT_CONTAINED) {
			spanCondition = $UnicodeSet$SpanCondition::SIMPLE;
		} else {
			if (!$nc(this->norm2)->isNormalized($(s->subSequence(prevSpanLimit, spanLimit)))) {
				return false;
			}
			spanCondition = $UnicodeSet$SpanCondition::NOT_CONTAINED;
		}
		prevSpanLimit = spanLimit;
	}
	return true;
}

int32_t FilteredNormalizer2::spanQuickCheckYes($CharSequence* s) {
	$useLocalCurrentObjectStackCache();
	$init($UnicodeSet$SpanCondition);
	$UnicodeSet$SpanCondition* spanCondition = $UnicodeSet$SpanCondition::SIMPLE;
	for (int32_t prevSpanLimit = 0; prevSpanLimit < $nc(s)->length();) {
		int32_t spanLimit = $nc(this->set)->span(s, prevSpanLimit, spanCondition);
		if (spanCondition == $UnicodeSet$SpanCondition::NOT_CONTAINED) {
			spanCondition = $UnicodeSet$SpanCondition::SIMPLE;
		} else {
			int32_t yesLimit = prevSpanLimit + $nc(this->norm2)->spanQuickCheckYes($(s->subSequence(prevSpanLimit, spanLimit)));
			if (yesLimit < spanLimit) {
				return yesLimit;
			}
			spanCondition = $UnicodeSet$SpanCondition::NOT_CONTAINED;
		}
		prevSpanLimit = spanLimit;
	}
	return $nc(s)->length();
}

bool FilteredNormalizer2::hasBoundaryBefore(int32_t c) {
	bool var$0 = !$nc(this->set)->contains(c);
	return var$0 || $nc(this->norm2)->hasBoundaryBefore(c);
}

$Appendable* FilteredNormalizer2::normalize($CharSequence* src, $Appendable* dest, $UnicodeSet$SpanCondition* spanCondition$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($UnicodeSet$SpanCondition, spanCondition, spanCondition$renamed);
	$var($StringBuilder, tempDest, $new($StringBuilder));
	try {
		for (int32_t prevSpanLimit = 0; prevSpanLimit < $nc(src)->length();) {
			int32_t spanLimit = $nc(this->set)->span(src, prevSpanLimit, spanCondition);
			int32_t spanLength = spanLimit - prevSpanLimit;
			$init($UnicodeSet$SpanCondition);
			if (spanCondition == $UnicodeSet$SpanCondition::NOT_CONTAINED) {
				if (spanLength != 0) {
					$nc(dest)->append(src, prevSpanLimit, spanLimit);
				}
				spanCondition = $UnicodeSet$SpanCondition::SIMPLE;
			} else {
				if (spanLength != 0) {
					$nc(dest)->append($(static_cast<$CharSequence*>($nc(this->norm2)->normalize($(src->subSequence(prevSpanLimit, spanLimit)), tempDest))));
				}
				spanCondition = $UnicodeSet$SpanCondition::NOT_CONTAINED;
			}
			prevSpanLimit = spanLimit;
		}
	} catch ($IOException& e) {
		$throwNew($InternalError, $(e->toString()), e);
	}
	return dest;
}

$StringBuilder* FilteredNormalizer2::normalizeSecondAndAppend($StringBuilder* first, $CharSequence* second, bool doNormalize) {
	$useLocalCurrentObjectStackCache();
	if ($equals(first, second)) {
		$throwNew($IllegalArgumentException);
	}
	if ($nc(first)->length() == 0) {
		if (doNormalize) {
			return normalize(second, first);
		} else {
			return first->append(second);
		}
	}
	$init($UnicodeSet$SpanCondition);
	int32_t prefixLimit = $nc(this->set)->span(second, 0, $UnicodeSet$SpanCondition::SIMPLE);
	if (prefixLimit != 0) {
		$var($CharSequence, prefix, $nc(second)->subSequence(0, prefixLimit));
		int32_t suffixStart = $nc(this->set)->spanBack(first, 0x7FFFFFFF, $UnicodeSet$SpanCondition::SIMPLE);
		if (suffixStart == 0) {
			if (doNormalize) {
				$nc(this->norm2)->normalizeSecondAndAppend(first, prefix);
			} else {
				$nc(this->norm2)->append(first, prefix);
			}
		} else {
			$var($StringBuilder, middle, $new($StringBuilder, $($nc(first)->subSequence(suffixStart, first->length()))));
			if (doNormalize) {
				$nc(this->norm2)->normalizeSecondAndAppend(middle, prefix);
			} else {
				$nc(this->norm2)->append(middle, prefix);
			}
			$nc($nc(first)->delete$(suffixStart, 0x7FFFFFFF))->append(static_cast<$CharSequence*>(middle));
		}
	}
	if (prefixLimit < $nc(second)->length()) {
		$var($CharSequence, rest, second->subSequence(prefixLimit, second->length()));
		if (doNormalize) {
			normalize(rest, first, $UnicodeSet$SpanCondition::NOT_CONTAINED);
		} else {
			$nc(first)->append(rest);
		}
	}
	return first;
}

FilteredNormalizer2::FilteredNormalizer2() {
}

$Class* FilteredNormalizer2::load$($String* name, bool initialize) {
	$loadClass(FilteredNormalizer2, name, initialize, &_FilteredNormalizer2_ClassInfo_, allocate$FilteredNormalizer2);
	return class$;
}

$Class* FilteredNormalizer2::class$ = nullptr;

			} // text
		} // icu
	} // internal
} // jdk