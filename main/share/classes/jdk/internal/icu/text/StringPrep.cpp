#include <jdk/internal/icu/text/StringPrep.h>

#include <java/io/BufferedInputStream.h>
#include <java/io/ByteArrayInputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/lang/CharSequence.h>
#include <java/lang/StringBuffer.h>
#include <java/text/Normalizer$Form.h>
#include <java/text/ParseException.h>
#include <jdk/internal/icu/impl/CharTrie.h>
#include <jdk/internal/icu/impl/StringPrepDataReader.h>
#include <jdk/internal/icu/impl/Trie$DataManipulate.h>
#include <jdk/internal/icu/lang/UCharacter.h>
#include <jdk/internal/icu/lang/UCharacterDirection.h>
#include <jdk/internal/icu/text/StringPrep$StringPrepTrieImpl.h>
#include <jdk/internal/icu/text/StringPrep$Values.h>
#include <jdk/internal/icu/text/UCharacterIterator.h>
#include <jdk/internal/icu/text/UTF16.h>
#include <jdk/internal/icu/util/VersionInfo.h>
#include <sun/text/Normalizer.h>
#include <jcpp.h>

#undef ALLOW_UNASSIGNED
#undef CHAR_DIRECTION_COUNT
#undef CHECK_BIDI_ON
#undef DATA_BUFFER_SIZE
#undef DEFAULT
#undef DELETE
#undef DONE
#undef FOUR_UCHARS_MAPPING_INDEX_START
#undef INDEX_MAPPING_DATA_SIZE
#undef INDEX_TOP
#undef INDEX_TRIE_SIZE
#undef LEFT_TO_RIGHT
#undef MAP
#undef MAX_INDEX_TOP_LENGTH
#undef MAX_INDEX_VALUE
#undef NFKC
#undef NORMALIZATION_ON
#undef NORM_CORRECTNS_LAST_UNI_VERSION
#undef ONE_UCHAR_MAPPING_INDEX_START
#undef OPTIONS
#undef PROHIBITED
#undef RIGHT_TO_LEFT
#undef RIGHT_TO_LEFT_ARABIC
#undef THREE_UCHARS_MAPPING_INDEX_START
#undef TWO_UCHARS_MAPPING_INDEX_START
#undef TYPE_LIMIT
#undef TYPE_THRESHOLD
#undef UNASSIGNED
#undef UNICODE_3_2

using $BufferedInputStream = ::java::io::BufferedInputStream;
using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $StringBuffer = ::java::lang::StringBuffer;
using $Normalizer$Form = ::java::text::Normalizer$Form;
using $ParseException = ::java::text::ParseException;
using $CharTrie = ::jdk::internal::icu::impl::CharTrie;
using $StringPrepDataReader = ::jdk::internal::icu::impl::StringPrepDataReader;
using $Trie$DataManipulate = ::jdk::internal::icu::impl::Trie$DataManipulate;
using $UCharacter = ::jdk::internal::icu::lang::UCharacter;
using $UCharacterDirection = ::jdk::internal::icu::lang::UCharacterDirection;
using $StringPrep$StringPrepTrieImpl = ::jdk::internal::icu::text::StringPrep$StringPrepTrieImpl;
using $StringPrep$Values = ::jdk::internal::icu::text::StringPrep$Values;
using $UCharacterIterator = ::jdk::internal::icu::text::UCharacterIterator;
using $UTF16 = ::jdk::internal::icu::text::UTF16;
using $VersionInfo = ::jdk::internal::icu::util::VersionInfo;
using $Normalizer = ::sun::text::Normalizer;

namespace jdk {
	namespace internal {
		namespace icu {
			namespace text {

$FieldInfo _StringPrep_FieldInfo_[] = {
	{"DEFAULT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(StringPrep, DEFAULT)},
	{"ALLOW_UNASSIGNED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(StringPrep, ALLOW_UNASSIGNED)},
	{"UNASSIGNED", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StringPrep, UNASSIGNED)},
	{"MAP", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StringPrep, MAP)},
	{"PROHIBITED", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StringPrep, PROHIBITED)},
	{"DELETE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StringPrep, DELETE)},
	{"TYPE_LIMIT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StringPrep, TYPE_LIMIT)},
	{"NORMALIZATION_ON", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StringPrep, NORMALIZATION_ON)},
	{"CHECK_BIDI_ON", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StringPrep, CHECK_BIDI_ON)},
	{"TYPE_THRESHOLD", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StringPrep, TYPE_THRESHOLD)},
	{"MAX_INDEX_VALUE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StringPrep, MAX_INDEX_VALUE)},
	{"MAX_INDEX_TOP_LENGTH", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StringPrep, MAX_INDEX_TOP_LENGTH)},
	{"INDEX_TRIE_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StringPrep, INDEX_TRIE_SIZE)},
	{"INDEX_MAPPING_DATA_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StringPrep, INDEX_MAPPING_DATA_SIZE)},
	{"NORM_CORRECTNS_LAST_UNI_VERSION", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StringPrep, NORM_CORRECTNS_LAST_UNI_VERSION)},
	{"ONE_UCHAR_MAPPING_INDEX_START", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StringPrep, ONE_UCHAR_MAPPING_INDEX_START)},
	{"TWO_UCHARS_MAPPING_INDEX_START", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StringPrep, TWO_UCHARS_MAPPING_INDEX_START)},
	{"THREE_UCHARS_MAPPING_INDEX_START", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StringPrep, THREE_UCHARS_MAPPING_INDEX_START)},
	{"FOUR_UCHARS_MAPPING_INDEX_START", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StringPrep, FOUR_UCHARS_MAPPING_INDEX_START)},
	{"OPTIONS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StringPrep, OPTIONS)},
	{"INDEX_TOP", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StringPrep, INDEX_TOP)},
	{"DATA_BUFFER_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StringPrep, DATA_BUFFER_SIZE)},
	{"sprepTrieImpl", "Ljdk/internal/icu/text/StringPrep$StringPrepTrieImpl;", nullptr, $PRIVATE, $field(StringPrep, sprepTrieImpl)},
	{"indexes", "[I", nullptr, $PRIVATE, $field(StringPrep, indexes)},
	{"mappingData", "[C", nullptr, $PRIVATE, $field(StringPrep, mappingData)},
	{"formatVersion", "[B", nullptr, $PRIVATE, $field(StringPrep, formatVersion)},
	{"sprepUniVer", "Ljdk/internal/icu/util/VersionInfo;", nullptr, $PRIVATE, $field(StringPrep, sprepUniVer)},
	{"normCorrVer", "Ljdk/internal/icu/util/VersionInfo;", nullptr, $PRIVATE, $field(StringPrep, normCorrVer)},
	{"doNFKC", "Z", nullptr, $PRIVATE, $field(StringPrep, doNFKC)},
	{"checkBiDi", "Z", nullptr, $PRIVATE, $field(StringPrep, checkBiDi)},
	{}
};

$MethodInfo _StringPrep_MethodInfo_[] = {
	{"<init>", "(Ljava/io/InputStream;)V", nullptr, $PUBLIC, $method(StringPrep, init$, void, $InputStream*), "java.io.IOException"},
	{"getCodePointValue", "(I)C", nullptr, $PRIVATE, $method(StringPrep, getCodePointValue, char16_t, int32_t)},
	{"getValues", "(CLjdk/internal/icu/text/StringPrep$Values;)V", nullptr, $PRIVATE | $STATIC | $FINAL, $staticMethod(StringPrep, getValues, void, char16_t, $StringPrep$Values*)},
	{"getVersionInfo", "(I)Ljdk/internal/icu/util/VersionInfo;", nullptr, $PRIVATE | $STATIC, $staticMethod(StringPrep, getVersionInfo, $VersionInfo*, int32_t)},
	{"getVersionInfo", "([B)Ljdk/internal/icu/util/VersionInfo;", nullptr, $PRIVATE | $STATIC, $staticMethod(StringPrep, getVersionInfo, $VersionInfo*, $bytes*)},
	{"map", "(Ljdk/internal/icu/text/UCharacterIterator;I)Ljava/lang/StringBuffer;", nullptr, $PRIVATE, $method(StringPrep, map, $StringBuffer*, $UCharacterIterator*, int32_t), "java.text.ParseException"},
	{"normalize", "(Ljava/lang/StringBuffer;)Ljava/lang/StringBuffer;", nullptr, $PRIVATE, $method(StringPrep, normalize, $StringBuffer*, $StringBuffer*)},
	{"prepare", "(Ljdk/internal/icu/text/UCharacterIterator;I)Ljava/lang/StringBuffer;", nullptr, $PUBLIC, $method(StringPrep, prepare, $StringBuffer*, $UCharacterIterator*, int32_t), "java.text.ParseException"},
	{}
};

$InnerClassInfo _StringPrep_InnerClassesInfo_[] = {
	{"jdk.internal.icu.text.StringPrep$Values", "jdk.internal.icu.text.StringPrep", "Values", $PRIVATE | $STATIC | $FINAL},
	{"jdk.internal.icu.text.StringPrep$StringPrepTrieImpl", "jdk.internal.icu.text.StringPrep", "StringPrepTrieImpl", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _StringPrep_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.icu.text.StringPrep",
	"java.lang.Object",
	nullptr,
	_StringPrep_FieldInfo_,
	_StringPrep_MethodInfo_,
	nullptr,
	nullptr,
	_StringPrep_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.icu.text.StringPrep$Values,jdk.internal.icu.text.StringPrep$StringPrepTrieImpl"
};

$Object* allocate$StringPrep($Class* clazz) {
	return $of($alloc(StringPrep));
}

char16_t StringPrep::getCodePointValue(int32_t ch) {
	return $nc($nc(this->sprepTrieImpl)->sprepTrie)->getCodePointValue(ch);
}

$VersionInfo* StringPrep::getVersionInfo(int32_t comp) {
	int32_t micro = (int32_t)(comp & (uint32_t)255);
	int32_t milli = (int32_t)((comp >> 8) & (uint32_t)255);
	int32_t minor = (int32_t)((comp >> 16) & (uint32_t)255);
	int32_t major = (int32_t)((comp >> 24) & (uint32_t)255);
	return $VersionInfo::getInstance(major, minor, milli, micro);
}

$VersionInfo* StringPrep::getVersionInfo($bytes* version) {
	if ($nc(version)->length != 4) {
		return nullptr;
	}
	return $VersionInfo::getInstance((int32_t)$nc(version)->get(0), (int32_t)version->get(1), (int32_t)version->get(2), (int32_t)version->get(3));
}

void StringPrep::init$($InputStream* inputStream) {
	$useLocalCurrentObjectStackCache();
	$var($BufferedInputStream, b, $new($BufferedInputStream, inputStream, StringPrep::DATA_BUFFER_SIZE));
	$var($StringPrepDataReader, reader, $new($StringPrepDataReader, b));
	$set(this, indexes, reader->readIndexes(StringPrep::INDEX_TOP));
	$var($bytes, sprepBytes, $new($bytes, $nc(this->indexes)->get(StringPrep::INDEX_TRIE_SIZE)));
	$set(this, mappingData, $new($chars, $nc(this->indexes)->get(StringPrep::INDEX_MAPPING_DATA_SIZE) / 2));
	reader->read(sprepBytes, this->mappingData);
	$set(this, sprepTrieImpl, $new($StringPrep$StringPrepTrieImpl));
	$set($nc(this->sprepTrieImpl), sprepTrie, $new($CharTrie, $$new($ByteArrayInputStream, sprepBytes), this->sprepTrieImpl));
	$set(this, formatVersion, reader->getDataFormatVersion());
	this->doNFKC = (((int32_t)($nc(this->indexes)->get(StringPrep::OPTIONS) & (uint32_t)StringPrep::NORMALIZATION_ON)) > 0);
	this->checkBiDi = (((int32_t)($nc(this->indexes)->get(StringPrep::OPTIONS) & (uint32_t)StringPrep::CHECK_BIDI_ON)) > 0);
	$set(this, sprepUniVer, getVersionInfo($(reader->getUnicodeVersion())));
	$set(this, normCorrVer, getVersionInfo($nc(this->indexes)->get(StringPrep::NORM_CORRECTNS_LAST_UNI_VERSION)));
	$var($VersionInfo, normUniVer, $UCharacter::getUnicodeVersion());
	bool var$0 = $nc(normUniVer)->compareTo(this->sprepUniVer) < 0;
	if (var$0 && normUniVer->compareTo(this->normCorrVer) < 0 && (((int32_t)($nc(this->indexes)->get(StringPrep::OPTIONS) & (uint32_t)StringPrep::NORMALIZATION_ON)) > 0)) {
		$throwNew($IOException, "Normalization Correction version not supported"_s);
	}
	b->close();
}

void StringPrep::getValues(char16_t trieWord, $StringPrep$Values* values) {
	$nc(values)->reset();
	if (trieWord == 0) {
		values->type = StringPrep::TYPE_LIMIT;
	} else if (trieWord >= StringPrep::TYPE_THRESHOLD) {
		values->type = (trieWord - StringPrep::TYPE_THRESHOLD);
	} else {
		values->type = StringPrep::MAP;
		if (((int32_t)(trieWord & (uint32_t)2)) > 0) {
			values->isIndex = true;
			values->value = trieWord >> 2;
		} else {
			values->isIndex = false;
			values->value = (trieWord << 16) >> 16;
			values->value = (values->value >> 2);
		}
		if ((trieWord >> 2) == StringPrep::MAX_INDEX_VALUE) {
			values->type = StringPrep::DELETE;
			values->isIndex = false;
			values->value = 0;
		}
	}
}

$StringBuffer* StringPrep::map($UCharacterIterator* iter, int32_t options) {
	$useLocalCurrentObjectStackCache();
	$var($StringPrep$Values, val, $new($StringPrep$Values));
	char16_t result = (char16_t)0;
	int32_t ch = $UCharacterIterator::DONE;
	$var($StringBuffer, dest, $new($StringBuffer));
	bool allowUnassigned = (((int32_t)(options & (uint32_t)StringPrep::ALLOW_UNASSIGNED)) > 0);
	while ((ch = $nc(iter)->nextCodePoint()) != $UCharacterIterator::DONE) {
		result = getCodePointValue(ch);
		getValues(result, val);
		if (val->type == StringPrep::UNASSIGNED && allowUnassigned == false) {
			$var($String, var$0, $str({"An unassigned code point was found in the input "_s, $(iter->getText())}));
			$throwNew($ParseException, var$0, iter->getIndex());
		} else if (val->type == StringPrep::MAP) {
			int32_t index = 0;
			int32_t length = 0;
			if (val->isIndex) {
				index = val->value;
				if (index >= $nc(this->indexes)->get(StringPrep::ONE_UCHAR_MAPPING_INDEX_START) && index < $nc(this->indexes)->get(StringPrep::TWO_UCHARS_MAPPING_INDEX_START)) {
					length = 1;
				} else if (index >= $nc(this->indexes)->get(StringPrep::TWO_UCHARS_MAPPING_INDEX_START) && index < $nc(this->indexes)->get(StringPrep::THREE_UCHARS_MAPPING_INDEX_START)) {
					length = 2;
				} else if (index >= $nc(this->indexes)->get(StringPrep::THREE_UCHARS_MAPPING_INDEX_START) && index < $nc(this->indexes)->get(StringPrep::FOUR_UCHARS_MAPPING_INDEX_START)) {
					length = 3;
				} else {
					length = $nc(this->mappingData)->get(index++);
				}
				dest->append(this->mappingData, index, length);
				continue;
			} else {
				ch -= val->value;
			}
		} else if (val->type == StringPrep::DELETE) {
			continue;
		}
		$UTF16::append(dest, ch);
	}
	return dest;
}

$StringBuffer* StringPrep::normalize($StringBuffer* src) {
	$useLocalCurrentObjectStackCache();
	$init($Normalizer$Form);
	return $new($StringBuffer, $($Normalizer::normalize($($nc(src)->toString()), $Normalizer$Form::NFKC, $Normalizer::UNICODE_3_2)));
}

$StringBuffer* StringPrep::prepare($UCharacterIterator* src, int32_t options) {
	$useLocalCurrentObjectStackCache();
	$var($StringBuffer, mapOut, map(src, options));
	$var($StringBuffer, normOut, mapOut);
	if (this->doNFKC) {
		$assign(normOut, normalize(mapOut));
	}
	int32_t ch = 0;
	char16_t result = 0;
	$var($UCharacterIterator, iter, $UCharacterIterator::getInstance(normOut));
	$var($StringPrep$Values, val, $new($StringPrep$Values));
	int32_t direction = $UCharacterDirection::CHAR_DIRECTION_COUNT;
	int32_t firstCharDir = $UCharacterDirection::CHAR_DIRECTION_COUNT;
	int32_t rtlPos = -1;
	int32_t ltrPos = -1;
	bool rightToLeft = false;
	bool leftToRight = false;
	while ((ch = $nc(iter)->nextCodePoint()) != $UCharacterIterator::DONE) {
		result = getCodePointValue(ch);
		getValues(result, val);
		if (val->type == StringPrep::PROHIBITED) {
			$throwNew($ParseException, $$str({"A prohibited code point was found in the input"_s, $(iter->getText())}), val->value);
		}
		direction = $UCharacter::getDirection(ch);
		if (firstCharDir == $UCharacterDirection::CHAR_DIRECTION_COUNT) {
			firstCharDir = direction;
		}
		if (direction == $UCharacterDirection::LEFT_TO_RIGHT) {
			leftToRight = true;
			ltrPos = iter->getIndex() - 1;
		}
		if (direction == $UCharacterDirection::RIGHT_TO_LEFT || direction == $UCharacterDirection::RIGHT_TO_LEFT_ARABIC) {
			rightToLeft = true;
			rtlPos = iter->getIndex() - 1;
		}
	}
	if (this->checkBiDi == true) {
		if (leftToRight == true && rightToLeft == true) {
			$throwNew($ParseException, $$str({"The input does not conform to the rules for BiDi code points."_s, $($nc(iter)->getText())}), (rtlPos > ltrPos) ? rtlPos : ltrPos);
		}
		if (rightToLeft == true && !((firstCharDir == $UCharacterDirection::RIGHT_TO_LEFT || firstCharDir == $UCharacterDirection::RIGHT_TO_LEFT_ARABIC) && (direction == $UCharacterDirection::RIGHT_TO_LEFT || direction == $UCharacterDirection::RIGHT_TO_LEFT_ARABIC))) {
			$throwNew($ParseException, $$str({"The input does not conform to the rules for BiDi code points."_s, $($nc(iter)->getText())}), (rtlPos > ltrPos) ? rtlPos : ltrPos);
		}
	}
	return normOut;
}

StringPrep::StringPrep() {
}

$Class* StringPrep::load$($String* name, bool initialize) {
	$loadClass(StringPrep, name, initialize, &_StringPrep_ClassInfo_, allocate$StringPrep);
	return class$;
}

$Class* StringPrep::class$ = nullptr;

			} // text
		} // icu
	} // internal
} // jdk