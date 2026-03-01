#include <jdk/internal/icu/impl/UCharacterProperty.h>

#include <java/io/IOException.h>
#include <java/lang/AssertionError.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/Iterator.h>
#include <java/util/MissingResourceException.h>
#include <jdk/internal/icu/impl/ICUBinary$Authenticate.h>
#include <jdk/internal/icu/impl/ICUBinary.h>
#include <jdk/internal/icu/impl/Trie2$Range.h>
#include <jdk/internal/icu/impl/Trie2_16.h>
#include <jdk/internal/icu/impl/UCharacterProperty$1.h>
#include <jdk/internal/icu/impl/UCharacterProperty$IntProperty.h>
#include <jdk/internal/icu/impl/UCharacterProperty$IsAcceptable.h>
#include <jdk/internal/icu/lang/UCharacter$HangulSyllableType.h>
#include <jdk/internal/icu/lang/UCharacter$NumericType.h>
#include <jdk/internal/icu/text/UnicodeSet.h>
#include <jdk/internal/icu/util/VersionInfo.h>
#include <jcpp.h>

#undef AGE_SHIFT_
#undef ALPHABETIC_PROPERTY_
#undef ASCII_HEX_DIGIT_PROPERTY_
#undef BIDI_PAIRED_BRACKET_TYPE
#undef BLOCK_MASK_
#undef BLOCK_SHIFT_
#undef DASH_PROPERTY_
#undef DATA_FILE_NAME_
#undef DATA_FORMAT
#undef DECIMAL
#undef DECOMPOSITION_TYPE_MASK_
#undef DEFAULT_IGNORABLE_CODE_POINT_PROPERTY_
#undef DEPRECATED_PROPERTY_
#undef DIACRITIC_PROPERTY_
#undef DIGIT
#undef EAST_ASIAN_MASK_
#undef EAST_ASIAN_SHIFT_
#undef EXTENDER_PROPERTY_
#undef FIRST_NIBBLE_SHIFT_
#undef GCB_MASK
#undef GCB_SHIFT
#undef GRAPHEME_BASE_PROPERTY_
#undef GRAPHEME_EXTEND_PROPERTY_
#undef GRAPHEME_LINK_PROPERTY_
#undef HEX_DIGIT_PROPERTY_
#undef HYPHEN_PROPERTY_
#undef ICU_DATA_VERSION_PATH
#undef IDEOGRAPHIC_PROPERTY_
#undef IDS_BINARY_OPERATOR_PROPERTY_
#undef IDS_TRINARY_OPERATOR_PROPERTY_
#undef ID_CONTINUE_PROPERTY_
#undef ID_START_PROPERTY_
#undef INSTANCE
#undef LAST_NIBBLE_MASK_
#undef LB_MASK
#undef LB_SHIFT
#undef LEADING_JAMO
#undef LEAD_SURROGATE_SHIFT_
#undef LOGICAL_ORDER_EXCEPTION_PROPERTY_
#undef LVT_SYLLABLE
#undef LV_SYLLABLE
#undef MATH_PROPERTY_
#undef MAX_SCRIPT
#undef NONCHARACTER_CODE_POINT_PROPERTY_
#undef NONE
#undef NOT_APPLICABLE
#undef NTV_DECIMAL_START_
#undef NTV_DIGIT_START_
#undef NTV_NONE_
#undef NTV_NUMERIC_START_
#undef NUMERIC
#undef NUMERIC_TYPE_VALUE_SHIFT_
#undef PATTERN_SYNTAX
#undef PATTERN_WHITE_SPACE
#undef QUOTATION_MARK_PROPERTY_
#undef RADICAL_PROPERTY_
#undef SB_MASK
#undef SB_SHIFT
#undef SCRIPT_HIGH_MASK
#undef SCRIPT_HIGH_SHIFT
#undef SCRIPT_LOW_MASK
#undef SCRIPT_X_MASK
#undef SRC_BIDI
#undef SRC_CHAR
#undef SRC_NFC
#undef SRC_NFKC
#undef SRC_PROPSVEC
#undef SURROGATE_OFFSET_
#undef S_TERM_PROPERTY_
#undef TERMINAL_PUNCTUATION_PROPERTY_
#undef TRAILING_JAMO
#undef TYPE_MASK
#undef UNIFIED_IDEOGRAPH_PROPERTY_
#undef VARIATION_SELECTOR_PROPERTY_
#undef VOWEL_JAMO
#undef WB_MASK
#undef WB_SHIFT
#undef WHITE_SPACE_PROPERTY_
#undef XID_CONTINUE_PROPERTY_
#undef XID_START_PROPERTY_

using $IOException = ::java::io::IOException;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $Iterator = ::java::util::Iterator;
using $MissingResourceException = ::java::util::MissingResourceException;
using $ICUBinary = ::jdk::internal::icu::impl::ICUBinary;
using $ICUBinary$Authenticate = ::jdk::internal::icu::impl::ICUBinary$Authenticate;
using $Trie2$Range = ::jdk::internal::icu::impl::Trie2$Range;
using $Trie2_16 = ::jdk::internal::icu::impl::Trie2_16;
using $UCharacterProperty$1 = ::jdk::internal::icu::impl::UCharacterProperty$1;
using $UCharacterProperty$IntProperty = ::jdk::internal::icu::impl::UCharacterProperty$IntProperty;
using $UCharacterProperty$IsAcceptable = ::jdk::internal::icu::impl::UCharacterProperty$IsAcceptable;
using $UCharacter$HangulSyllableType = ::jdk::internal::icu::lang::UCharacter$HangulSyllableType;
using $UCharacter$NumericType = ::jdk::internal::icu::lang::UCharacter$NumericType;
using $UnicodeSet = ::jdk::internal::icu::text::UnicodeSet;
using $VersionInfo = ::jdk::internal::icu::util::VersionInfo;

namespace jdk {
	namespace internal {
		namespace icu {
			namespace impl {

$FieldInfo _UCharacterProperty_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(UCharacterProperty, $assertionsDisabled)},
	{"INSTANCE", "Ljdk/internal/icu/impl/UCharacterProperty;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(UCharacterProperty, INSTANCE)},
	{"m_trie_", "Ljdk/internal/icu/impl/Trie2_16;", nullptr, $PUBLIC, $field(UCharacterProperty, m_trie_)},
	{"m_unicodeVersion_", "Ljdk/internal/icu/util/VersionInfo;", nullptr, $PUBLIC, $field(UCharacterProperty, m_unicodeVersion_)},
	{"TYPE_MASK", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UCharacterProperty, TYPE_MASK)},
	{"SRC_CHAR", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UCharacterProperty, SRC_CHAR)},
	{"SRC_PROPSVEC", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UCharacterProperty, SRC_PROPSVEC)},
	{"SRC_BIDI", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UCharacterProperty, SRC_BIDI)},
	{"SRC_NFC", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UCharacterProperty, SRC_NFC)},
	{"SRC_NFKC", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UCharacterProperty, SRC_NFKC)},
	{"gcbToHst", "[I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(UCharacterProperty, gcbToHst)},
	{"intProp", "Ljdk/internal/icu/impl/UCharacterProperty$IntProperty;", nullptr, $PRIVATE, $field(UCharacterProperty, intProp)},
	{"m_additionalTrie_", "Ljdk/internal/icu/impl/Trie2_16;", nullptr, 0, $field(UCharacterProperty, m_additionalTrie_)},
	{"m_additionalVectors_", "[I", nullptr, 0, $field(UCharacterProperty, m_additionalVectors_)},
	{"m_additionalColumnsCount_", "I", nullptr, 0, $field(UCharacterProperty, m_additionalColumnsCount_)},
	{"m_maxBlockScriptValue_", "I", nullptr, 0, $field(UCharacterProperty, m_maxBlockScriptValue_)},
	{"m_maxJTGValue_", "I", nullptr, 0, $field(UCharacterProperty, m_maxJTGValue_)},
	{"m_scriptExtensions_", "[C", nullptr, $PUBLIC, $field(UCharacterProperty, m_scriptExtensions_)},
	{"DATA_FILE_NAME_", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(UCharacterProperty, DATA_FILE_NAME_)},
	{"LEAD_SURROGATE_SHIFT_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, LEAD_SURROGATE_SHIFT_)},
	{"SURROGATE_OFFSET_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, SURROGATE_OFFSET_)},
	{"NUMERIC_TYPE_VALUE_SHIFT_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, NUMERIC_TYPE_VALUE_SHIFT_)},
	{"NTV_NONE_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, NTV_NONE_)},
	{"NTV_DECIMAL_START_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, NTV_DECIMAL_START_)},
	{"NTV_DIGIT_START_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, NTV_DIGIT_START_)},
	{"NTV_NUMERIC_START_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, NTV_NUMERIC_START_)},
	{"SCRIPT_X_MASK", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UCharacterProperty, SCRIPT_X_MASK)},
	{"SCRIPT_HIGH_MASK", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UCharacterProperty, SCRIPT_HIGH_MASK)},
	{"SCRIPT_HIGH_SHIFT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UCharacterProperty, SCRIPT_HIGH_SHIFT)},
	{"MAX_SCRIPT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UCharacterProperty, MAX_SCRIPT)},
	{"EAST_ASIAN_MASK_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, EAST_ASIAN_MASK_)},
	{"EAST_ASIAN_SHIFT_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, EAST_ASIAN_SHIFT_)},
	{"BLOCK_MASK_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, BLOCK_MASK_)},
	{"BLOCK_SHIFT_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, BLOCK_SHIFT_)},
	{"SCRIPT_LOW_MASK", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UCharacterProperty, SCRIPT_LOW_MASK)},
	{"WHITE_SPACE_PROPERTY_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, WHITE_SPACE_PROPERTY_)},
	{"DASH_PROPERTY_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, DASH_PROPERTY_)},
	{"HYPHEN_PROPERTY_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, HYPHEN_PROPERTY_)},
	{"QUOTATION_MARK_PROPERTY_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, QUOTATION_MARK_PROPERTY_)},
	{"TERMINAL_PUNCTUATION_PROPERTY_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, TERMINAL_PUNCTUATION_PROPERTY_)},
	{"MATH_PROPERTY_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, MATH_PROPERTY_)},
	{"HEX_DIGIT_PROPERTY_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, HEX_DIGIT_PROPERTY_)},
	{"ASCII_HEX_DIGIT_PROPERTY_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, ASCII_HEX_DIGIT_PROPERTY_)},
	{"ALPHABETIC_PROPERTY_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, ALPHABETIC_PROPERTY_)},
	{"IDEOGRAPHIC_PROPERTY_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, IDEOGRAPHIC_PROPERTY_)},
	{"DIACRITIC_PROPERTY_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, DIACRITIC_PROPERTY_)},
	{"EXTENDER_PROPERTY_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, EXTENDER_PROPERTY_)},
	{"NONCHARACTER_CODE_POINT_PROPERTY_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, NONCHARACTER_CODE_POINT_PROPERTY_)},
	{"GRAPHEME_EXTEND_PROPERTY_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, GRAPHEME_EXTEND_PROPERTY_)},
	{"GRAPHEME_LINK_PROPERTY_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, GRAPHEME_LINK_PROPERTY_)},
	{"IDS_BINARY_OPERATOR_PROPERTY_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, IDS_BINARY_OPERATOR_PROPERTY_)},
	{"IDS_TRINARY_OPERATOR_PROPERTY_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, IDS_TRINARY_OPERATOR_PROPERTY_)},
	{"RADICAL_PROPERTY_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, RADICAL_PROPERTY_)},
	{"UNIFIED_IDEOGRAPH_PROPERTY_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, UNIFIED_IDEOGRAPH_PROPERTY_)},
	{"DEFAULT_IGNORABLE_CODE_POINT_PROPERTY_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, DEFAULT_IGNORABLE_CODE_POINT_PROPERTY_)},
	{"DEPRECATED_PROPERTY_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, DEPRECATED_PROPERTY_)},
	{"LOGICAL_ORDER_EXCEPTION_PROPERTY_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, LOGICAL_ORDER_EXCEPTION_PROPERTY_)},
	{"XID_START_PROPERTY_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, XID_START_PROPERTY_)},
	{"XID_CONTINUE_PROPERTY_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, XID_CONTINUE_PROPERTY_)},
	{"ID_START_PROPERTY_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, ID_START_PROPERTY_)},
	{"ID_CONTINUE_PROPERTY_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, ID_CONTINUE_PROPERTY_)},
	{"GRAPHEME_BASE_PROPERTY_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, GRAPHEME_BASE_PROPERTY_)},
	{"S_TERM_PROPERTY_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, S_TERM_PROPERTY_)},
	{"VARIATION_SELECTOR_PROPERTY_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, VARIATION_SELECTOR_PROPERTY_)},
	{"PATTERN_SYNTAX", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, PATTERN_SYNTAX)},
	{"PATTERN_WHITE_SPACE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, PATTERN_WHITE_SPACE)},
	{"LB_MASK", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, LB_MASK)},
	{"LB_SHIFT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, LB_SHIFT)},
	{"SB_MASK", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, SB_MASK)},
	{"SB_SHIFT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, SB_SHIFT)},
	{"WB_MASK", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, WB_MASK)},
	{"WB_SHIFT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, WB_SHIFT)},
	{"GCB_MASK", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, GCB_MASK)},
	{"GCB_SHIFT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, GCB_SHIFT)},
	{"DECOMPOSITION_TYPE_MASK_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, DECOMPOSITION_TYPE_MASK_)},
	{"FIRST_NIBBLE_SHIFT_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, FIRST_NIBBLE_SHIFT_)},
	{"LAST_NIBBLE_MASK_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, LAST_NIBBLE_MASK_)},
	{"AGE_SHIFT_", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, AGE_SHIFT_)},
	{"DATA_FORMAT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UCharacterProperty, DATA_FORMAT)},
	{"BIDI_PAIRED_BRACKET_TYPE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UCharacterProperty, BIDI_PAIRED_BRACKET_TYPE)},
	{}
};

$MethodInfo _UCharacterProperty_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(UCharacterProperty, init$, void), "java.io.IOException"},
	{"digit", "(I)I", nullptr, $PUBLIC, $method(UCharacterProperty, digit, int32_t, int32_t)},
	{"getAdditional", "(II)I", nullptr, $PUBLIC, $method(UCharacterProperty, getAdditional, int32_t, int32_t, int32_t)},
	{"getAge", "(I)Ljdk/internal/icu/util/VersionInfo;", nullptr, $PUBLIC, $method(UCharacterProperty, getAge, $VersionInfo*, int32_t)},
	{"getEuropeanDigit", "(I)I", nullptr, $PUBLIC | $STATIC, $staticMethod(UCharacterProperty, getEuropeanDigit, int32_t, int32_t)},
	{"getIntPropertyValue", "(II)I", nullptr, $PUBLIC, $method(UCharacterProperty, getIntPropertyValue, int32_t, int32_t, int32_t)},
	{"getMask", "(I)I", nullptr, $PUBLIC | $STATIC | $FINAL, $staticMethod(UCharacterProperty, getMask, int32_t, int32_t)},
	{"getNumericTypeValue", "(I)I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticMethod(UCharacterProperty, getNumericTypeValue, int32_t, int32_t)},
	{"getProperty", "(I)I", nullptr, $PUBLIC | $FINAL, $method(UCharacterProperty, getProperty, int32_t, int32_t)},
	{"getRawSupplementary", "(CC)I", nullptr, $PUBLIC | $STATIC, $staticMethod(UCharacterProperty, getRawSupplementary, int32_t, char16_t, char16_t)},
	{"getType", "(I)I", nullptr, $PUBLIC, $method(UCharacterProperty, getType, int32_t, int32_t)},
	{"mergeScriptCodeOrIndex", "(I)I", nullptr, $PUBLIC | $STATIC | $FINAL, $staticMethod(UCharacterProperty, mergeScriptCodeOrIndex, int32_t, int32_t)},
	{"ntvGetType", "(I)I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticMethod(UCharacterProperty, ntvGetType, int32_t, int32_t)},
	{"upropsvec_addPropertyStarts", "(Ljdk/internal/icu/text/UnicodeSet;)V", nullptr, $PUBLIC, $method(UCharacterProperty, upropsvec_addPropertyStarts, void, $UnicodeSet*)},
	{}
};

$InnerClassInfo _UCharacterProperty_InnerClassesInfo_[] = {
	{"jdk.internal.icu.impl.UCharacterProperty$IsAcceptable", "jdk.internal.icu.impl.UCharacterProperty", "IsAcceptable", $PRIVATE | $STATIC | $FINAL},
	{"jdk.internal.icu.impl.UCharacterProperty$NormQuickCheckIntProperty", "jdk.internal.icu.impl.UCharacterProperty", "NormQuickCheckIntProperty", $PRIVATE},
	{"jdk.internal.icu.impl.UCharacterProperty$CombiningClassIntProperty", "jdk.internal.icu.impl.UCharacterProperty", "CombiningClassIntProperty", $PRIVATE},
	{"jdk.internal.icu.impl.UCharacterProperty$BiDiIntProperty", "jdk.internal.icu.impl.UCharacterProperty", "BiDiIntProperty", $PRIVATE},
	{"jdk.internal.icu.impl.UCharacterProperty$IntProperty", "jdk.internal.icu.impl.UCharacterProperty", "IntProperty", $PRIVATE},
	{"jdk.internal.icu.impl.UCharacterProperty$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _UCharacterProperty_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.icu.impl.UCharacterProperty",
	"java.lang.Object",
	nullptr,
	_UCharacterProperty_FieldInfo_,
	_UCharacterProperty_MethodInfo_,
	nullptr,
	nullptr,
	_UCharacterProperty_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.icu.impl.UCharacterProperty$IsAcceptable,jdk.internal.icu.impl.UCharacterProperty$NormQuickCheckIntProperty,jdk.internal.icu.impl.UCharacterProperty$CombiningClassIntProperty,jdk.internal.icu.impl.UCharacterProperty$BiDiIntProperty,jdk.internal.icu.impl.UCharacterProperty$IntProperty,jdk.internal.icu.impl.UCharacterProperty$1"
};

$Object* allocate$UCharacterProperty($Class* clazz) {
	return $of($alloc(UCharacterProperty));
}

bool UCharacterProperty::$assertionsDisabled = false;
UCharacterProperty* UCharacterProperty::INSTANCE = nullptr;
$ints* UCharacterProperty::gcbToHst = nullptr;
$String* UCharacterProperty::DATA_FILE_NAME_ = nullptr;

int32_t UCharacterProperty::getProperty(int32_t ch) {
	return $nc(this->m_trie_)->get(ch);
}

int32_t UCharacterProperty::getAdditional(int32_t codepoint, int32_t column) {
	if (!UCharacterProperty::$assertionsDisabled && !(column >= 0)) {
		$throwNew($AssertionError);
	}
	if (column >= this->m_additionalColumnsCount_) {
		return 0;
	}
	return $nc(this->m_additionalVectors_)->get($nc(this->m_additionalTrie_)->get(codepoint) + column);
}

$VersionInfo* UCharacterProperty::getAge(int32_t codepoint) {
	int32_t version = $sr(getAdditional(codepoint, 0), UCharacterProperty::AGE_SHIFT_);
	return $VersionInfo::getInstance((int32_t)(($sr(version, UCharacterProperty::FIRST_NIBBLE_SHIFT_)) & (uint32_t)UCharacterProperty::LAST_NIBBLE_MASK_), (int32_t)(version & (uint32_t)UCharacterProperty::LAST_NIBBLE_MASK_), 0, 0);
}

int32_t UCharacterProperty::getType(int32_t c) {
	return (int32_t)(getProperty(c) & (uint32_t)UCharacterProperty::TYPE_MASK);
}

int32_t UCharacterProperty::getIntPropertyValue(int32_t c, int32_t which) {
	if (which == UCharacterProperty::BIDI_PAIRED_BRACKET_TYPE) {
		return $nc(this->intProp)->getValue(c);
	}
	return 0;
}

int32_t UCharacterProperty::getRawSupplementary(char16_t lead, char16_t trail) {
	$init(UCharacterProperty);
	return ($sl((int32_t)lead, UCharacterProperty::LEAD_SURROGATE_SHIFT_)) + trail + UCharacterProperty::SURROGATE_OFFSET_;
}

int32_t UCharacterProperty::getMask(int32_t type) {
	$init(UCharacterProperty);
	return $sl(1, type);
}

int32_t UCharacterProperty::getEuropeanDigit(int32_t ch) {
	$init(UCharacterProperty);
	if ((ch > 122 && ch < 0x0000FF21) || ch < 65 || (ch > 90 && ch < 97) || ch > 0x0000FF5A || (ch > 0x0000FF3A && ch < 0x0000FF41)) {
		return -1;
	}
	if (ch <= 122) {
		return ch + 10 - ((ch <= 90) ? 65 : 97);
	}
	if (ch <= 0x0000FF3A) {
		return ch + 10 - 0x0000FF21;
	}
	return ch + 10 - 0x0000FF41;
}

int32_t UCharacterProperty::digit(int32_t c) {
	int32_t value = getNumericTypeValue(getProperty(c)) - UCharacterProperty::NTV_DECIMAL_START_;
	if (value <= 9) {
		return value;
	} else {
		return -1;
	}
}

int32_t UCharacterProperty::getNumericTypeValue(int32_t props) {
	$init(UCharacterProperty);
	return $sr(props, UCharacterProperty::NUMERIC_TYPE_VALUE_SHIFT_);
}

int32_t UCharacterProperty::ntvGetType(int32_t ntv) {
	$init(UCharacterProperty);
	return (ntv == UCharacterProperty::NTV_NONE_) ? $UCharacter$NumericType::NONE : (ntv < UCharacterProperty::NTV_DIGIT_START_) ? $UCharacter$NumericType::DECIMAL : (ntv < UCharacterProperty::NTV_NUMERIC_START_) ? $UCharacter$NumericType::DIGIT : $UCharacter$NumericType::NUMERIC;
}

int32_t UCharacterProperty::mergeScriptCodeOrIndex(int32_t scriptX) {
	$init(UCharacterProperty);
	return ($sr((int32_t)(scriptX & (uint32_t)UCharacterProperty::SCRIPT_HIGH_MASK), UCharacterProperty::SCRIPT_HIGH_SHIFT)) | ((int32_t)(scriptX & (uint32_t)UCharacterProperty::SCRIPT_LOW_MASK));
}

void UCharacterProperty::init$() {
	$useLocalCurrentObjectStackCache();
	$set(this, intProp, $new($UCharacterProperty$1, this));
	$var($ByteBuffer, bytes, $ICUBinary::getRequiredData(UCharacterProperty::DATA_FILE_NAME_));
	$set(this, m_unicodeVersion_, $ICUBinary::readHeaderAndDataVersion(bytes, UCharacterProperty::DATA_FORMAT, $$new($UCharacterProperty$IsAcceptable)));
	int32_t propertyOffset = $nc(bytes)->getInt();
	bytes->getInt();
	bytes->getInt();
	int32_t additionalOffset = bytes->getInt();
	int32_t additionalVectorsOffset = bytes->getInt();
	this->m_additionalColumnsCount_ = bytes->getInt();
	int32_t scriptExtensionsOffset = bytes->getInt();
	int32_t reservedOffset7 = bytes->getInt();
	bytes->getInt();
	bytes->getInt();
	this->m_maxBlockScriptValue_ = bytes->getInt();
	this->m_maxJTGValue_ = bytes->getInt();
	$ICUBinary::skipBytes(bytes, (16 - 12) << 2);
	$set(this, m_trie_, $Trie2_16::createFromSerialized(bytes));
	int32_t expectedTrieLength = (propertyOffset - 16) * 4;
	int32_t trieLength = $nc(this->m_trie_)->getSerializedLength();
	if (trieLength > expectedTrieLength) {
		$throwNew($IOException, "uprops.icu: not enough bytes for main trie"_s);
	}
	$ICUBinary::skipBytes(bytes, expectedTrieLength - trieLength);
	$ICUBinary::skipBytes(bytes, (additionalOffset - propertyOffset) * 4);
	if (this->m_additionalColumnsCount_ > 0) {
		$set(this, m_additionalTrie_, $Trie2_16::createFromSerialized(bytes));
		expectedTrieLength = (additionalVectorsOffset - additionalOffset) * 4;
		trieLength = $nc(this->m_additionalTrie_)->getSerializedLength();
		if (trieLength > expectedTrieLength) {
			$throwNew($IOException, "uprops.icu: not enough bytes for additional-properties trie"_s);
		}
		$ICUBinary::skipBytes(bytes, expectedTrieLength - trieLength);
		int32_t size = scriptExtensionsOffset - additionalVectorsOffset;
		$set(this, m_additionalVectors_, $new($ints, size));
		for (int32_t i = 0; i < size; ++i) {
			$nc(this->m_additionalVectors_)->set(i, bytes->getInt());
		}
	}
	int32_t numChars = (reservedOffset7 - scriptExtensionsOffset) * 2;
	if (numChars > 0) {
		$set(this, m_scriptExtensions_, $new($chars, numChars));
		for (int32_t i = 0; i < numChars; ++i) {
			$nc(this->m_scriptExtensions_)->set(i, bytes->getChar());
		}
	}
}

void UCharacterProperty::upropsvec_addPropertyStarts($UnicodeSet* set) {
	$useLocalCurrentObjectStackCache();
	if (this->m_additionalColumnsCount_ > 0) {
		$var($Iterator, trieIterator, $nc(this->m_additionalTrie_)->iterator());
		$var($Trie2$Range, range, nullptr);
		while (true) {
			bool var$0 = $nc(trieIterator)->hasNext();
			if (!(var$0 && !$nc(($assign(range, $cast($Trie2$Range, trieIterator->next()))))->leadSurrogate)) {
				break;
			}
			{
				$nc(set)->add($nc(range)->startCodePoint);
			}
		}
	}
}

void clinit$UCharacterProperty($Class* class$) {
	$init($VersionInfo);
	$assignStatic(UCharacterProperty::DATA_FILE_NAME_, $str({"/jdk/internal/icu/impl/data/icudt"_s, $VersionInfo::ICU_DATA_VERSION_PATH, "/uprops.icu"_s}));
	UCharacterProperty::$assertionsDisabled = !UCharacterProperty::class$->desiredAssertionStatus();
	$assignStatic(UCharacterProperty::gcbToHst, $new($ints, {
		$UCharacter$HangulSyllableType::NOT_APPLICABLE,
		$UCharacter$HangulSyllableType::NOT_APPLICABLE,
		$UCharacter$HangulSyllableType::NOT_APPLICABLE,
		$UCharacter$HangulSyllableType::NOT_APPLICABLE,
		$UCharacter$HangulSyllableType::LEADING_JAMO,
		$UCharacter$HangulSyllableType::NOT_APPLICABLE,
		$UCharacter$HangulSyllableType::LV_SYLLABLE,
		$UCharacter$HangulSyllableType::LVT_SYLLABLE,
		$UCharacter$HangulSyllableType::TRAILING_JAMO,
		$UCharacter$HangulSyllableType::VOWEL_JAMO
	}));
	{
		try {
			$assignStatic(UCharacterProperty::INSTANCE, $new(UCharacterProperty));
		} catch ($IOException& e) {
			$throwNew($MissingResourceException, $(e->getMessage()), UCharacterProperty::DATA_FILE_NAME_, ""_s);
		}
	}
}

UCharacterProperty::UCharacterProperty() {
}

$Class* UCharacterProperty::load$($String* name, bool initialize) {
	$loadClass(UCharacterProperty, name, initialize, &_UCharacterProperty_ClassInfo_, clinit$UCharacterProperty, allocate$UCharacterProperty);
	return class$;
}

$Class* UCharacterProperty::class$ = nullptr;

			} // impl
		} // icu
	} // internal
} // jdk