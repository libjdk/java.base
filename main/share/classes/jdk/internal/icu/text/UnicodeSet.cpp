#include <jdk/internal/icu/text/UnicodeSet.h>

#include <java/lang/AssertionError.h>
#include <java/lang/CharSequence.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/text/ParsePosition.h>
#include <java/util/AbstractCollection.h>
#include <java/util/AbstractSet.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/SortedSet.h>
#include <java/util/TreeSet.h>
#include <jdk/internal/icu/impl/BMPSet.h>
#include <jdk/internal/icu/impl/UCharacterProperty.h>
#include <jdk/internal/icu/impl/UnicodeSetStringSpan.h>
#include <jdk/internal/icu/impl/Utility.h>
#include <jdk/internal/icu/text/UTF16.h>
#include <jdk/internal/icu/text/UnicodeSet$Filter.h>
#include <jdk/internal/icu/text/UnicodeSet$SpanCondition.h>
#include <jdk/internal/icu/text/UnicodeSet$VersionFilter.h>
#include <jdk/internal/icu/util/OutputInt.h>
#include <jdk/internal/icu/util/VersionInfo.h>
#include <jcpp.h>

#undef ALL
#undef BACK_UTF16_CONTAINED
#undef BACK_UTF16_NOT_CONTAINED
#undef FWD_UTF16_CONTAINED
#undef FWD_UTF16_NOT_CONTAINED
#undef GROW_EXTRA
#undef HIGH
#undef INCLUSION
#undef INSTANCE
#undef LOW
#undef MAX_VALUE
#undef MIN_VALUE
#undef NOT_CONTAINED
#undef NO_VERSION
#undef SRC_PROPSVEC
#undef START_EXTRA
#undef WITH_COUNT

using $AssertionError = ::java::lang::AssertionError;
using $CharSequence = ::java::lang::CharSequence;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $ParsePosition = ::java::text::ParsePosition;
using $AbstractCollection = ::java::util::AbstractCollection;
using $AbstractSet = ::java::util::AbstractSet;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $SortedSet = ::java::util::SortedSet;
using $TreeSet = ::java::util::TreeSet;
using $BMPSet = ::jdk::internal::icu::impl::BMPSet;
using $UCharacterProperty = ::jdk::internal::icu::impl::UCharacterProperty;
using $UnicodeSetStringSpan = ::jdk::internal::icu::impl::UnicodeSetStringSpan;
using $Utility = ::jdk::internal::icu::impl::Utility;
using $UTF16 = ::jdk::internal::icu::text::UTF16;
using $UnicodeSet$Filter = ::jdk::internal::icu::text::UnicodeSet$Filter;
using $UnicodeSet$SpanCondition = ::jdk::internal::icu::text::UnicodeSet$SpanCondition;
using $UnicodeSet$VersionFilter = ::jdk::internal::icu::text::UnicodeSet$VersionFilter;
using $OutputInt = ::jdk::internal::icu::util::OutputInt;
using $VersionInfo = ::jdk::internal::icu::util::VersionInfo;

namespace jdk {
	namespace internal {
		namespace icu {
			namespace text {

$FieldInfo _UnicodeSet_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(UnicodeSet, $assertionsDisabled)},
	{"LOW", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UnicodeSet, LOW)},
	{"HIGH", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UnicodeSet, HIGH)},
	{"MIN_VALUE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSet, MIN_VALUE)},
	{"MAX_VALUE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSet, MAX_VALUE)},
	{"len", "I", nullptr, $PRIVATE, $field(UnicodeSet, len)},
	{"list", "[I", nullptr, $PRIVATE, $field(UnicodeSet, list)},
	{"rangeList", "[I", nullptr, $PRIVATE, $field(UnicodeSet, rangeList)},
	{"buffer", "[I", nullptr, $PRIVATE, $field(UnicodeSet, buffer)},
	{"strings", "Ljava/util/TreeSet;", "Ljava/util/TreeSet<Ljava/lang/String;>;", 0, $field(UnicodeSet, strings)},
	{"START_EXTRA", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UnicodeSet, START_EXTRA)},
	{"GROW_EXTRA", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UnicodeSet, GROW_EXTRA)},
	{"INCLUSION", "Ljdk/internal/icu/text/UnicodeSet;", nullptr, $PRIVATE | $STATIC, $staticField(UnicodeSet, INCLUSION)},
	{"bmpSet", "Ljdk/internal/icu/impl/BMPSet;", nullptr, $PRIVATE | $VOLATILE, $field(UnicodeSet, bmpSet)},
	{"stringSpan", "Ljdk/internal/icu/impl/UnicodeSetStringSpan;", nullptr, $PRIVATE | $VOLATILE, $field(UnicodeSet, stringSpan)},
	{"NO_VERSION", "Ljdk/internal/icu/util/VersionInfo;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(UnicodeSet, NO_VERSION)},
	{}
};

$MethodInfo _UnicodeSet_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(UnicodeSet, init$, void)},
	{"<init>", "(Ljdk/internal/icu/text/UnicodeSet;)V", nullptr, $PRIVATE, $method(UnicodeSet, init$, void, UnicodeSet*)},
	{"<init>", "(II)V", nullptr, $PUBLIC, $method(UnicodeSet, init$, void, int32_t, int32_t)},
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(UnicodeSet, init$, void, $String*)},
	{"add", "(I)Ljdk/internal/icu/text/UnicodeSet;", nullptr, $PUBLIC | $FINAL, $method(UnicodeSet, add, UnicodeSet*, int32_t)},
	{"add", "(Ljava/lang/CharSequence;)Ljdk/internal/icu/text/UnicodeSet;", nullptr, $PUBLIC | $FINAL, $method(UnicodeSet, add, UnicodeSet*, $CharSequence*)},
	{"add", "([III)Ljdk/internal/icu/text/UnicodeSet;", nullptr, $PRIVATE, $method(UnicodeSet, add, UnicodeSet*, $ints*, int32_t, int32_t)},
	{"add_unchecked", "(II)Ljdk/internal/icu/text/UnicodeSet;", nullptr, $PRIVATE, $method(UnicodeSet, add_unchecked, UnicodeSet*, int32_t, int32_t)},
	{"add_unchecked", "(I)Ljdk/internal/icu/text/UnicodeSet;", nullptr, $PRIVATE | $FINAL, $method(UnicodeSet, add_unchecked, UnicodeSet*, int32_t)},
	{"applyFilter", "(Ljdk/internal/icu/text/UnicodeSet$Filter;I)Ljdk/internal/icu/text/UnicodeSet;", nullptr, $PRIVATE, $method(UnicodeSet, applyFilter, UnicodeSet*, $UnicodeSet$Filter*, int32_t)},
	{"applyPattern", "(Ljava/lang/String;Ljava/text/ParsePosition;)Ljdk/internal/icu/text/UnicodeSet;", nullptr, $PRIVATE, $method(UnicodeSet, applyPattern, UnicodeSet*, $String*, $ParsePosition*)},
	{"checkFrozen", "()V", nullptr, $PRIVATE, $method(UnicodeSet, checkFrozen, void)},
	{"clear", "()Ljdk/internal/icu/text/UnicodeSet;", nullptr, $PUBLIC, $virtualMethod(UnicodeSet, clear, UnicodeSet*)},
	{"cloneAsThawed", "()Ljdk/internal/icu/text/UnicodeSet;", nullptr, $PUBLIC, $virtualMethod(UnicodeSet, cloneAsThawed, UnicodeSet*)},
	{"complement", "(II)Ljdk/internal/icu/text/UnicodeSet;", nullptr, $PUBLIC, $virtualMethod(UnicodeSet, complement, UnicodeSet*, int32_t, int32_t)},
	{"contains", "(I)Z", nullptr, $PUBLIC, $virtualMethod(UnicodeSet, contains, bool, int32_t)},
	{"ensureBufferCapacity", "(I)V", nullptr, $PRIVATE, $method(UnicodeSet, ensureBufferCapacity, void, int32_t)},
	{"ensureCapacity", "(I)V", nullptr, $PRIVATE, $method(UnicodeSet, ensureCapacity, void, int32_t)},
	{"findCodePoint", "(I)I", nullptr, $PRIVATE | $FINAL, $method(UnicodeSet, findCodePoint, int32_t, int32_t)},
	{"freeze", "()Ljdk/internal/icu/text/UnicodeSet;", nullptr, $PUBLIC, $virtualMethod(UnicodeSet, freeze, UnicodeSet*)},
	{"getInclusions", "(I)Ljdk/internal/icu/text/UnicodeSet;", nullptr, $PRIVATE | $STATIC | $SYNCHRONIZED, $staticMethod(UnicodeSet, getInclusions, UnicodeSet*, int32_t)},
	{"getRangeCount", "()I", nullptr, $PUBLIC, $virtualMethod(UnicodeSet, getRangeCount, int32_t)},
	{"getRangeEnd", "(I)I", nullptr, $PUBLIC, $virtualMethod(UnicodeSet, getRangeEnd, int32_t, int32_t)},
	{"getRangeStart", "(I)I", nullptr, $PUBLIC, $virtualMethod(UnicodeSet, getRangeStart, int32_t, int32_t)},
	{"getSingleCP", "(Ljava/lang/CharSequence;)I", nullptr, $PRIVATE | $STATIC, $staticMethod(UnicodeSet, getSingleCP, int32_t, $CharSequence*)},
	{"isFrozen", "()Z", nullptr, $PUBLIC, $virtualMethod(UnicodeSet, isFrozen, bool)},
	{"max", "(II)I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticMethod(UnicodeSet, max, int32_t, int32_t, int32_t)},
	{"range", "(II)[I", nullptr, $PRIVATE, $method(UnicodeSet, range, $ints*, int32_t, int32_t)},
	{"retain", "([III)Ljdk/internal/icu/text/UnicodeSet;", nullptr, $PRIVATE, $method(UnicodeSet, retain, UnicodeSet*, $ints*, int32_t, int32_t)},
	{"retainAll", "(Ljdk/internal/icu/text/UnicodeSet;)Ljdk/internal/icu/text/UnicodeSet;", nullptr, $PUBLIC, $virtualMethod(UnicodeSet, retainAll, UnicodeSet*, UnicodeSet*)},
	{"set", "(Ljdk/internal/icu/text/UnicodeSet;)Ljdk/internal/icu/text/UnicodeSet;", nullptr, $PUBLIC, $virtualMethod(UnicodeSet, set, UnicodeSet*, UnicodeSet*)},
	{"size", "()I", nullptr, $PUBLIC, $virtualMethod(UnicodeSet, size, int32_t)},
	{"span", "(Ljava/lang/CharSequence;Ljdk/internal/icu/text/UnicodeSet$SpanCondition;)I", nullptr, $PUBLIC, $virtualMethod(UnicodeSet, span, int32_t, $CharSequence*, $UnicodeSet$SpanCondition*)},
	{"span", "(Ljava/lang/CharSequence;ILjdk/internal/icu/text/UnicodeSet$SpanCondition;)I", nullptr, $PUBLIC, $virtualMethod(UnicodeSet, span, int32_t, $CharSequence*, int32_t, $UnicodeSet$SpanCondition*)},
	{"spanAndCount", "(Ljava/lang/CharSequence;ILjdk/internal/icu/text/UnicodeSet$SpanCondition;Ljdk/internal/icu/util/OutputInt;)I", nullptr, $PUBLIC, $virtualMethod(UnicodeSet, spanAndCount, int32_t, $CharSequence*, int32_t, $UnicodeSet$SpanCondition*, $OutputInt*)},
	{"spanBack", "(Ljava/lang/CharSequence;ILjdk/internal/icu/text/UnicodeSet$SpanCondition;)I", nullptr, $PUBLIC, $virtualMethod(UnicodeSet, spanBack, int32_t, $CharSequence*, int32_t, $UnicodeSet$SpanCondition*)},
	{"spanCodePointsAndCount", "(Ljava/lang/CharSequence;ILjdk/internal/icu/text/UnicodeSet$SpanCondition;Ljdk/internal/icu/util/OutputInt;)I", nullptr, $PRIVATE, $method(UnicodeSet, spanCodePointsAndCount, int32_t, $CharSequence*, int32_t, $UnicodeSet$SpanCondition*, $OutputInt*)},
	{"xor", "([III)Ljdk/internal/icu/text/UnicodeSet;", nullptr, $PRIVATE, $method(UnicodeSet, xor$, UnicodeSet*, $ints*, int32_t, int32_t)},
	{}
};

$InnerClassInfo _UnicodeSet_InnerClassesInfo_[] = {
	{"jdk.internal.icu.text.UnicodeSet$SpanCondition", "jdk.internal.icu.text.UnicodeSet", "SpanCondition", $PUBLIC | $STATIC | $FINAL | $ENUM},
	{"jdk.internal.icu.text.UnicodeSet$VersionFilter", "jdk.internal.icu.text.UnicodeSet", "VersionFilter", $PRIVATE | $STATIC},
	{"jdk.internal.icu.text.UnicodeSet$Filter", "jdk.internal.icu.text.UnicodeSet", "Filter", $PRIVATE | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _UnicodeSet_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.icu.text.UnicodeSet",
	"java.lang.Object",
	nullptr,
	_UnicodeSet_FieldInfo_,
	_UnicodeSet_MethodInfo_,
	nullptr,
	nullptr,
	_UnicodeSet_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.icu.text.UnicodeSet$SpanCondition,jdk.internal.icu.text.UnicodeSet$VersionFilter,jdk.internal.icu.text.UnicodeSet$Filter"
};

$Object* allocate$UnicodeSet($Class* clazz) {
	return $of($alloc(UnicodeSet));
}

bool UnicodeSet::$assertionsDisabled = false;
UnicodeSet* UnicodeSet::INCLUSION = nullptr;
$VersionInfo* UnicodeSet::NO_VERSION = nullptr;

void UnicodeSet::init$() {
	$set(this, strings, $new($TreeSet));
	$set(this, list, $new($ints, 1 + UnicodeSet::START_EXTRA));
	$nc(this->list)->set(this->len++, UnicodeSet::HIGH);
}

void UnicodeSet::init$(UnicodeSet* other) {
	$set(this, strings, $new($TreeSet));
	set(other);
}

void UnicodeSet::init$(int32_t start, int32_t end) {
	UnicodeSet::init$();
	complement(start, end);
}

void UnicodeSet::init$($String* pattern) {
	UnicodeSet::init$();
	applyPattern(pattern, nullptr);
}

UnicodeSet* UnicodeSet::set(UnicodeSet* other) {
	checkFrozen();
	$set(this, list, $cast($ints, $nc($nc(other)->list)->clone()));
	this->len = other->len;
	$set(this, strings, $new($TreeSet, static_cast<$SortedSet*>(other->strings)));
	return this;
}

int32_t UnicodeSet::size() {
	int32_t n = 0;
	int32_t count = getRangeCount();
	for (int32_t i = 0; i < count; ++i) {
		int32_t var$0 = getRangeEnd(i);
		n += var$0 - getRangeStart(i) + 1;
	}
	return n + $nc(this->strings)->size();
}

UnicodeSet* UnicodeSet::add_unchecked(int32_t start, int32_t end) {
	$useLocalCurrentObjectStackCache();
	if (start < UnicodeSet::MIN_VALUE || start > UnicodeSet::MAX_VALUE) {
		$throwNew($IllegalArgumentException, $$str({"Invalid code point U+"_s, $($Utility::hex(start, 6))}));
	}
	if (end < UnicodeSet::MIN_VALUE || end > UnicodeSet::MAX_VALUE) {
		$throwNew($IllegalArgumentException, $$str({"Invalid code point U+"_s, $($Utility::hex(end, 6))}));
	}
	if (start < end) {
		add($(range(start, end)), 2, 0);
	} else if (start == end) {
		add(start);
	}
	return this;
}

UnicodeSet* UnicodeSet::add(int32_t c) {
	checkFrozen();
	return add_unchecked(c);
}

UnicodeSet* UnicodeSet::add_unchecked(int32_t c) {
	$useLocalCurrentObjectStackCache();
	if (c < UnicodeSet::MIN_VALUE || c > UnicodeSet::MAX_VALUE) {
		$throwNew($IllegalArgumentException, $$str({"Invalid code point U+"_s, $($Utility::hex(c, 6))}));
	}
	int32_t i = findCodePoint(c);
	if (((int32_t)(i & (uint32_t)1)) != 0) {
		return this;
	}
	if (c == $nc(this->list)->get(i) - 1) {
		$nc(this->list)->set(i, c);
		if (c == UnicodeSet::MAX_VALUE) {
			ensureCapacity(this->len + 1);
			$nc(this->list)->set(this->len++, UnicodeSet::HIGH);
		}
		if (i > 0 && c == $nc(this->list)->get(i - 1)) {
			$System::arraycopy(this->list, i + 1, this->list, i - 1, this->len - i - 1);
			this->len -= 2;
		}
	} else if (i > 0 && c == $nc(this->list)->get(i - 1)) {
		++(*$nc(this->list))[i - 1];
	} else {
		if (this->len + 2 > $nc(this->list)->length) {
			$var($ints, temp, $new($ints, this->len + 2 + UnicodeSet::GROW_EXTRA));
			if (i != 0) {
				$System::arraycopy(this->list, 0, temp, 0, i);
			}
			$System::arraycopy(this->list, i, temp, i + 2, this->len - i);
			$set(this, list, temp);
		} else {
			$System::arraycopy(this->list, i, this->list, i + 2, this->len - i);
		}
		$nc(this->list)->set(i, c);
		$nc(this->list)->set(i + 1, c + 1);
		this->len += 2;
	}
	return this;
}

UnicodeSet* UnicodeSet::add($CharSequence* s) {
	checkFrozen();
	int32_t cp = getSingleCP(s);
	if (cp < 0) {
		$nc(this->strings)->add($($nc(s)->toString()));
	} else {
		add_unchecked(cp, cp);
	}
	return this;
}

int32_t UnicodeSet::getSingleCP($CharSequence* s) {
	$init(UnicodeSet);
	if ($nc(s)->length() < 1) {
		$throwNew($IllegalArgumentException, "Can\'t use zero-length strings in UnicodeSet"_s);
	}
	if ($nc(s)->length() > 2) {
		return -1;
	}
	if ($nc(s)->length() == 1) {
		return s->charAt(0);
	}
	int32_t cp = $UTF16::charAt(s, 0);
	if (cp > 0x0000FFFF) {
		return cp;
	}
	return -1;
}

UnicodeSet* UnicodeSet::complement(int32_t start, int32_t end) {
	$useLocalCurrentObjectStackCache();
	checkFrozen();
	if (start < UnicodeSet::MIN_VALUE || start > UnicodeSet::MAX_VALUE) {
		$throwNew($IllegalArgumentException, $$str({"Invalid code point U+"_s, $($Utility::hex(start, 6))}));
	}
	if (end < UnicodeSet::MIN_VALUE || end > UnicodeSet::MAX_VALUE) {
		$throwNew($IllegalArgumentException, $$str({"Invalid code point U+"_s, $($Utility::hex(end, 6))}));
	}
	if (start <= end) {
		xor$($(range(start, end)), 2, 0);
	}
	return this;
}

bool UnicodeSet::contains(int32_t c) {
	$useLocalCurrentObjectStackCache();
	if (c < UnicodeSet::MIN_VALUE || c > UnicodeSet::MAX_VALUE) {
		$throwNew($IllegalArgumentException, $$str({"Invalid code point U+"_s, $($Utility::hex(c, 6))}));
	}
	if (this->bmpSet != nullptr) {
		return $nc(this->bmpSet)->contains(c);
	}
	if (this->stringSpan != nullptr) {
		return $nc(this->stringSpan)->contains(c);
	}
	int32_t i = findCodePoint(c);
	return (((int32_t)(i & (uint32_t)1)) != 0);
}

int32_t UnicodeSet::findCodePoint(int32_t c) {
	if (c < $nc(this->list)->get(0)) {
		return 0;
	}
	if (this->len >= 2 && c >= $nc(this->list)->get(this->len - 2)) {
		return this->len - 1;
	}
	int32_t lo = 0;
	int32_t hi = this->len - 1;
	for (;;) {
		int32_t i = (int32_t)((uint32_t)(lo + hi) >> 1);
		if (i == lo) {
			return hi;
		}
		if (c < $nc(this->list)->get(i)) {
			hi = i;
		} else {
			lo = i;
		}
	}
}

UnicodeSet* UnicodeSet::retainAll(UnicodeSet* c) {
	checkFrozen();
	retain($nc(c)->list, c->len, 0);
	$nc(this->strings)->retainAll(static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractSet*>($nc(c)->strings))));
	return this;
}

UnicodeSet* UnicodeSet::clear() {
	checkFrozen();
	$nc(this->list)->set(0, UnicodeSet::HIGH);
	this->len = 1;
	$nc(this->strings)->clear();
	return this;
}

int32_t UnicodeSet::getRangeCount() {
	return this->len / 2;
}

int32_t UnicodeSet::getRangeStart(int32_t index) {
	return $nc(this->list)->get(index * 2);
}

int32_t UnicodeSet::getRangeEnd(int32_t index) {
	return ($nc(this->list)->get(index * 2 + 1) - 1);
}

UnicodeSet* UnicodeSet::applyPattern($String* pattern, $ParsePosition* pos) {
	$useLocalCurrentObjectStackCache();
	if ("[:age=3.2:]"_s->equals(pattern)) {
		checkFrozen();
		$var($VersionInfo, version, $VersionInfo::getInstance("3.2"_s));
		applyFilter($$new($UnicodeSet$VersionFilter, version), $UCharacterProperty::SRC_PROPSVEC);
	} else {
		$throwNew($IllegalStateException, $$str({"UnicodeSet.applyPattern(unexpected pattern "_s, pattern, ")"_s}));
	}
	return this;
}

void UnicodeSet::ensureCapacity(int32_t newLen) {
	if (newLen <= $nc(this->list)->length) {
		return;
	}
	$var($ints, temp, $new($ints, newLen + UnicodeSet::GROW_EXTRA));
	$System::arraycopy(this->list, 0, temp, 0, this->len);
	$set(this, list, temp);
}

void UnicodeSet::ensureBufferCapacity(int32_t newLen) {
	if (this->buffer != nullptr && newLen <= $nc(this->buffer)->length) {
		return;
	}
	$set(this, buffer, $new($ints, newLen + UnicodeSet::GROW_EXTRA));
}

$ints* UnicodeSet::range(int32_t start, int32_t end) {
	if (this->rangeList == nullptr) {
		$set(this, rangeList, $new($ints, {
			start,
			end + 1,
			UnicodeSet::HIGH
		}));
	} else {
		$nc(this->rangeList)->set(0, start);
		$nc(this->rangeList)->set(1, end + 1);
	}
	return this->rangeList;
}

UnicodeSet* UnicodeSet::xor$($ints* other, int32_t otherLen, int32_t polarity) {
	ensureBufferCapacity(this->len + otherLen);
	int32_t i = 0;
	int32_t j = 0;
	int32_t k = 0;
	int32_t a = $nc(this->list)->get(i++);
	int32_t b = 0;
	if (polarity == 1 || polarity == 2) {
		b = UnicodeSet::LOW;
		if ($nc(other)->get(j) == UnicodeSet::LOW) {
			++j;
			b = other->get(j);
		}
	} else {
		b = $nc(other)->get(j++);
	}
	while (true) {
		if (a < b) {
			$nc(this->buffer)->set(k++, a);
			a = $nc(this->list)->get(i++);
		} else if (b < a) {
			$nc(this->buffer)->set(k++, b);
			b = $nc(other)->get(j++);
		} else if (a != UnicodeSet::HIGH) {
			a = $nc(this->list)->get(i++);
			b = $nc(other)->get(j++);
		} else {
			$nc(this->buffer)->set(k++, UnicodeSet::HIGH);
			this->len = k;
			break;
		}
	}
	$var($ints, temp, this->list);
	$set(this, list, this->buffer);
	$set(this, buffer, temp);
	return this;
}

UnicodeSet* UnicodeSet::add($ints* other, int32_t otherLen, int32_t polarity) {
	ensureBufferCapacity(this->len + otherLen);
	int32_t i = 0;
	int32_t j = 0;
	int32_t k = 0;
	int32_t a = $nc(this->list)->get(i++);
	int32_t b = $nc(other)->get(j++);
	bool main$break = false;
	while (true) {
		switch (polarity) {
		case 0:
			{
				if (a < b) {
					if (k > 0 && a <= $nc(this->buffer)->get(k - 1)) {
						a = max($nc(this->list)->get(i), $nc(this->buffer)->get(--k));
					} else {
						$nc(this->buffer)->set(k++, a);
						a = $nc(this->list)->get(i);
					}
					++i;
					polarity ^= 1;
				} else if (b < a) {
					if (k > 0 && b <= $nc(this->buffer)->get(k - 1)) {
						b = max(other->get(j), $nc(this->buffer)->get(--k));
					} else {
						$nc(this->buffer)->set(k++, b);
						b = other->get(j);
					}
					++j;
					polarity ^= 2;
				} else {
					if (a == UnicodeSet::HIGH) {
						main$break = true;
						break;
					}
					if (k > 0 && a <= $nc(this->buffer)->get(k - 1)) {
						a = max($nc(this->list)->get(i), $nc(this->buffer)->get(--k));
					} else {
						$nc(this->buffer)->set(k++, a);
						a = $nc(this->list)->get(i);
					}
					++i;
					polarity ^= 1;
					b = other->get(j++);
					polarity ^= 2;
				}
				break;
			}
		case 3:
			{
				if (b <= a) {
					if (a == UnicodeSet::HIGH) {
						main$break = true;
						break;
					}
					$nc(this->buffer)->set(k++, a);
				} else {
					if (b == UnicodeSet::HIGH) {
						main$break = true;
						break;
					}
					$nc(this->buffer)->set(k++, b);
				}
				a = $nc(this->list)->get(i++);
				polarity ^= 1;
				b = other->get(j++);
				polarity ^= 2;
				break;
			}
		case 1:
			{
				if (a < b) {
					$nc(this->buffer)->set(k++, a);
					a = $nc(this->list)->get(i++);
					polarity ^= 1;
				} else if (b < a) {
					b = other->get(j++);
					polarity ^= 2;
				} else {
					if (a == UnicodeSet::HIGH) {
						main$break = true;
						break;
					}
					a = $nc(this->list)->get(i++);
					polarity ^= 1;
					b = other->get(j++);
					polarity ^= 2;
				}
				break;
			}
		case 2:
			{
				if (b < a) {
					$nc(this->buffer)->set(k++, b);
					b = other->get(j++);
					polarity ^= 2;
				} else if (a < b) {
					a = $nc(this->list)->get(i++);
					polarity ^= 1;
				} else {
					if (a == UnicodeSet::HIGH) {
						main$break = true;
						break;
					}
					a = $nc(this->list)->get(i++);
					polarity ^= 1;
					b = other->get(j++);
					polarity ^= 2;
				}
				break;
			}
		}

		if (main$break) {
			break;
		}	}
	$nc(this->buffer)->set(k++, UnicodeSet::HIGH);
	this->len = k;
	$var($ints, temp, this->list);
	$set(this, list, this->buffer);
	$set(this, buffer, temp);
	return this;
}

UnicodeSet* UnicodeSet::retain($ints* other, int32_t otherLen, int32_t polarity) {
	ensureBufferCapacity(this->len + otherLen);
	int32_t i = 0;
	int32_t j = 0;
	int32_t k = 0;
	int32_t a = $nc(this->list)->get(i++);
	int32_t b = $nc(other)->get(j++);
	bool main$break = false;
	while (true) {
		switch (polarity) {
		case 0:
			{
				if (a < b) {
					a = $nc(this->list)->get(i++);
					polarity ^= 1;
				} else if (b < a) {
					b = other->get(j++);
					polarity ^= 2;
				} else {
					if (a == UnicodeSet::HIGH) {
						main$break = true;
						break;
					}
					$nc(this->buffer)->set(k++, a);
					a = $nc(this->list)->get(i++);
					polarity ^= 1;
					b = other->get(j++);
					polarity ^= 2;
				}
				break;
			}
		case 3:
			{
				if (a < b) {
					$nc(this->buffer)->set(k++, a);
					a = $nc(this->list)->get(i++);
					polarity ^= 1;
				} else if (b < a) {
					$nc(this->buffer)->set(k++, b);
					b = other->get(j++);
					polarity ^= 2;
				} else {
					if (a == UnicodeSet::HIGH) {
						main$break = true;
						break;
					}
					$nc(this->buffer)->set(k++, a);
					a = $nc(this->list)->get(i++);
					polarity ^= 1;
					b = other->get(j++);
					polarity ^= 2;
				}
				break;
			}
		case 1:
			{
				if (a < b) {
					a = $nc(this->list)->get(i++);
					polarity ^= 1;
				} else if (b < a) {
					$nc(this->buffer)->set(k++, b);
					b = other->get(j++);
					polarity ^= 2;
				} else {
					if (a == UnicodeSet::HIGH) {
						main$break = true;
						break;
					}
					a = $nc(this->list)->get(i++);
					polarity ^= 1;
					b = other->get(j++);
					polarity ^= 2;
				}
				break;
			}
		case 2:
			{
				if (b < a) {
					b = other->get(j++);
					polarity ^= 2;
				} else if (a < b) {
					$nc(this->buffer)->set(k++, a);
					a = $nc(this->list)->get(i++);
					polarity ^= 1;
				} else {
					if (a == UnicodeSet::HIGH) {
						main$break = true;
						break;
					}
					a = $nc(this->list)->get(i++);
					polarity ^= 1;
					b = other->get(j++);
					polarity ^= 2;
				}
				break;
			}
		}

		if (main$break) {
			break;
		}	}
	$nc(this->buffer)->set(k++, UnicodeSet::HIGH);
	this->len = k;
	$var($ints, temp, this->list);
	$set(this, list, this->buffer);
	$set(this, buffer, temp);
	return this;
}

int32_t UnicodeSet::max(int32_t a, int32_t b) {
	$init(UnicodeSet);
	return (a > b) ? a : b;
}

UnicodeSet* UnicodeSet::getInclusions(int32_t src) {
	$load(UnicodeSet);
	$synchronized(class$) {
		$init(UnicodeSet);
		$useLocalCurrentObjectStackCache();
		if (src != $UCharacterProperty::SRC_PROPSVEC) {
			$throwNew($IllegalStateException, $$str({"UnicodeSet.getInclusions(unknown src "_s, $$str(src), ")"_s}));
		}
		if (UnicodeSet::INCLUSION == nullptr) {
			$var(UnicodeSet, incl, $new(UnicodeSet));
			$init($UCharacterProperty);
			$nc($UCharacterProperty::INSTANCE)->upropsvec_addPropertyStarts(incl);
			$assignStatic(UnicodeSet::INCLUSION, incl);
		}
		return UnicodeSet::INCLUSION;
	}
}

UnicodeSet* UnicodeSet::applyFilter($UnicodeSet$Filter* filter, int32_t src) {
	clear();
	int32_t startHasProperty = -1;
	$var(UnicodeSet, inclusions, getInclusions(src));
	int32_t limitRange = $nc(inclusions)->getRangeCount();
	for (int32_t j = 0; j < limitRange; ++j) {
		int32_t start = inclusions->getRangeStart(j);
		int32_t end = inclusions->getRangeEnd(j);
		for (int32_t ch = start; ch <= end; ++ch) {
			if ($nc(filter)->contains(ch)) {
				if (startHasProperty < 0) {
					startHasProperty = ch;
				}
			} else if (startHasProperty >= 0) {
				add_unchecked(startHasProperty, ch - 1);
				startHasProperty = -1;
			}
		}
	}
	if (startHasProperty >= 0) {
		add_unchecked(startHasProperty, 0x0010FFFF);
	}
	return this;
}

bool UnicodeSet::isFrozen() {
	return (this->bmpSet != nullptr || this->stringSpan != nullptr);
}

UnicodeSet* UnicodeSet::freeze() {
	$useLocalCurrentObjectStackCache();
	if (!isFrozen()) {
		$set(this, buffer, nullptr);
		if ($nc(this->list)->length > (this->len + UnicodeSet::GROW_EXTRA)) {
			int32_t capacity = (this->len == 0) ? 1 : this->len;
			$var($ints, oldList, this->list);
			$set(this, list, $new($ints, capacity));
			for (int32_t i = capacity; i-- > 0;) {
				$nc(this->list)->set(i, $nc(oldList)->get(i));
			}
		}
		if (!$nc(this->strings)->isEmpty()) {
			$set(this, stringSpan, $new($UnicodeSetStringSpan, this, $$new($ArrayList, static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractSet*>(this->strings)))), $UnicodeSetStringSpan::ALL));
		}
		if (this->stringSpan == nullptr || !$nc(this->stringSpan)->needsStringSpanUTF16()) {
			$set(this, bmpSet, $new($BMPSet, this->list, this->len));
		}
	}
	return this;
}

int32_t UnicodeSet::span($CharSequence* s, $UnicodeSet$SpanCondition* spanCondition) {
	return span(s, 0, spanCondition);
}

int32_t UnicodeSet::span($CharSequence* s, int32_t start, $UnicodeSet$SpanCondition* spanCondition) {
	$useLocalCurrentObjectStackCache();
	int32_t end = $nc(s)->length();
	if (start < 0) {
		start = 0;
	} else if (start >= end) {
		return end;
	}
	if (this->bmpSet != nullptr) {
		return $nc(this->bmpSet)->span(s, start, spanCondition, nullptr);
	}
	if (this->stringSpan != nullptr) {
		return $nc(this->stringSpan)->span(s, start, spanCondition);
	} else if (!$nc(this->strings)->isEmpty()) {
		$init($UnicodeSet$SpanCondition);
		int32_t which = spanCondition == $UnicodeSet$SpanCondition::NOT_CONTAINED ? $UnicodeSetStringSpan::FWD_UTF16_NOT_CONTAINED : $UnicodeSetStringSpan::FWD_UTF16_CONTAINED;
		$var($UnicodeSetStringSpan, strSpan, $new($UnicodeSetStringSpan, this, $$new($ArrayList, static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractSet*>(this->strings)))), which));
		if (strSpan->needsStringSpanUTF16()) {
			return strSpan->span(s, start, spanCondition);
		}
	}
	return spanCodePointsAndCount(s, start, spanCondition, nullptr);
}

int32_t UnicodeSet::spanAndCount($CharSequence* s, int32_t start, $UnicodeSet$SpanCondition* spanCondition, $OutputInt* outCount) {
	$useLocalCurrentObjectStackCache();
	if (outCount == nullptr) {
		$throwNew($IllegalArgumentException, "outCount must not be null"_s);
	}
	int32_t end = $nc(s)->length();
	if (start < 0) {
		start = 0;
	} else if (start >= end) {
		return end;
	}
	if (this->stringSpan != nullptr) {
		return $nc(this->stringSpan)->spanAndCount(s, start, spanCondition, outCount);
	} else if (this->bmpSet != nullptr) {
		return $nc(this->bmpSet)->span(s, start, spanCondition, outCount);
	} else if (!$nc(this->strings)->isEmpty()) {
		$init($UnicodeSet$SpanCondition);
		int32_t which = spanCondition == $UnicodeSet$SpanCondition::NOT_CONTAINED ? $UnicodeSetStringSpan::FWD_UTF16_NOT_CONTAINED : $UnicodeSetStringSpan::FWD_UTF16_CONTAINED;
		which |= $UnicodeSetStringSpan::WITH_COUNT;
		$var($UnicodeSetStringSpan, strSpan, $new($UnicodeSetStringSpan, this, $$new($ArrayList, static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractSet*>(this->strings)))), which));
		return strSpan->spanAndCount(s, start, spanCondition, outCount);
	}
	return spanCodePointsAndCount(s, start, spanCondition, outCount);
}

int32_t UnicodeSet::spanCodePointsAndCount($CharSequence* s, int32_t start, $UnicodeSet$SpanCondition* spanCondition, $OutputInt* outCount) {
	$init($UnicodeSet$SpanCondition);
	bool spanContained = (spanCondition != $UnicodeSet$SpanCondition::NOT_CONTAINED);
	int32_t c = 0;
	int32_t next = start;
	int32_t length = $nc(s)->length();
	int32_t count = 0;
	do {
		c = $Character::codePointAt(s, next);
		if (spanContained != contains(c)) {
			break;
		}
		++count;
		next += $Character::charCount(c);
	} while (next < length);
	if (outCount != nullptr) {
		outCount->value = count;
	}
	return next;
}

int32_t UnicodeSet::spanBack($CharSequence* s, int32_t fromIndex, $UnicodeSet$SpanCondition* spanCondition) {
	$useLocalCurrentObjectStackCache();
	if (fromIndex <= 0) {
		return 0;
	}
	if (fromIndex > $nc(s)->length()) {
		fromIndex = s->length();
	}
	if (this->bmpSet != nullptr) {
		return $nc(this->bmpSet)->spanBack(s, fromIndex, spanCondition);
	}
	if (this->stringSpan != nullptr) {
		return $nc(this->stringSpan)->spanBack(s, fromIndex, spanCondition);
	} else if (!$nc(this->strings)->isEmpty()) {
		$init($UnicodeSet$SpanCondition);
		int32_t which = (spanCondition == $UnicodeSet$SpanCondition::NOT_CONTAINED) ? $UnicodeSetStringSpan::BACK_UTF16_NOT_CONTAINED : $UnicodeSetStringSpan::BACK_UTF16_CONTAINED;
		$var($UnicodeSetStringSpan, strSpan, $new($UnicodeSetStringSpan, this, $$new($ArrayList, static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractSet*>(this->strings)))), which));
		if (strSpan->needsStringSpanUTF16()) {
			return strSpan->spanBack(s, fromIndex, spanCondition);
		}
	}
	$init($UnicodeSet$SpanCondition);
	bool spanContained = (spanCondition != $UnicodeSet$SpanCondition::NOT_CONTAINED);
	int32_t c = 0;
	int32_t prev = fromIndex;
	do {
		c = $Character::codePointBefore(s, prev);
		if (spanContained != contains(c)) {
			break;
		}
		prev -= $Character::charCount(c);
	} while (prev > 0);
	return prev;
}

UnicodeSet* UnicodeSet::cloneAsThawed() {
	$var(UnicodeSet, result, $new(UnicodeSet, this));
	if (!UnicodeSet::$assertionsDisabled && ! !result->isFrozen()) {
		$throwNew($AssertionError);
	}
	return result;
}

void UnicodeSet::checkFrozen() {
	if (isFrozen()) {
		$throwNew($UnsupportedOperationException, "Attempt to modify frozen object"_s);
	}
}

void clinit$UnicodeSet($Class* class$) {
	UnicodeSet::$assertionsDisabled = !UnicodeSet::class$->desiredAssertionStatus();
	$assignStatic(UnicodeSet::INCLUSION, nullptr);
	$assignStatic(UnicodeSet::NO_VERSION, $VersionInfo::getInstance(0, 0, 0, 0));
}

UnicodeSet::UnicodeSet() {
}

$Class* UnicodeSet::load$($String* name, bool initialize) {
	$loadClass(UnicodeSet, name, initialize, &_UnicodeSet_ClassInfo_, clinit$UnicodeSet, allocate$UnicodeSet);
	return class$;
}

$Class* UnicodeSet::class$ = nullptr;

			} // text
		} // icu
	} // internal
} // jdk