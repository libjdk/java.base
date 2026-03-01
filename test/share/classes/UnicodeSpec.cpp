#include <UnicodeSpec.h>

#include <java/io/BufferedReader.h>
#include <java/io/File.h>
#include <java/io/FileReader.h>
#include <java/io/IOException.h>
#include <java/io/Reader.h>
#include <java/lang/CharSequence.h>
#include <java/lang/Math.h>
#include <java/lang/NumberFormatException.h>
#include <java/lang/StringBuffer.h>
#include <java/util/ArrayList.h>
#include <java/util/regex/Pattern.h>
#include <jcpp.h>

#undef COMBINING_SPACING_MARK
#undef CONNECTOR_PUNCTUATION
#undef CONTROL
#undef CURRENCY_SYMBOL
#undef DASH_PUNCTUATION
#undef DECIMAL_DIGIT_NUMBER
#undef DIRECTIONALITY_ARABIC_NUMBER
#undef DIRECTIONALITY_BOUNDARY_NEUTRAL
#undef DIRECTIONALITY_CATEGORY_COUNT
#undef DIRECTIONALITY_COMMON_NUMBER_SEPARATOR
#undef DIRECTIONALITY_EUROPEAN_NUMBER
#undef DIRECTIONALITY_EUROPEAN_NUMBER_SEPARATOR
#undef DIRECTIONALITY_EUROPEAN_NUMBER_TERMINATOR
#undef DIRECTIONALITY_FIRST_STRONG_ISOLATE
#undef DIRECTIONALITY_LEFT_TO_RIGHT
#undef DIRECTIONALITY_LEFT_TO_RIGHT_EMBEDDING
#undef DIRECTIONALITY_LEFT_TO_RIGHT_ISOLATE
#undef DIRECTIONALITY_LEFT_TO_RIGHT_OVERRIDE
#undef DIRECTIONALITY_NONSPACING_MARK
#undef DIRECTIONALITY_OTHER_NEUTRALS
#undef DIRECTIONALITY_PARAGRAPH_SEPARATOR
#undef DIRECTIONALITY_POP_DIRECTIONAL_FORMAT
#undef DIRECTIONALITY_POP_DIRECTIONAL_ISOLATE
#undef DIRECTIONALITY_RIGHT_TO_LEFT
#undef DIRECTIONALITY_RIGHT_TO_LEFT_ARABIC
#undef DIRECTIONALITY_RIGHT_TO_LEFT_EMBEDDING
#undef DIRECTIONALITY_RIGHT_TO_LEFT_ISOLATE
#undef DIRECTIONALITY_RIGHT_TO_LEFT_OVERRIDE
#undef DIRECTIONALITY_SEGMENT_SEPARATOR
#undef DIRECTIONALITY_UNDEFINED
#undef DIRECTIONALITY_WHITESPACE
#undef ENCLOSING_MARK
#undef END_PUNCTUATION
#undef FIELD_BIDI
#undef FIELD_CATEGORY
#undef FIELD_CLASS
#undef FIELD_COMMENT
#undef FIELD_DECIMAL
#undef FIELD_DECOMPOSITION
#undef FIELD_DIGIT
#undef FIELD_LOWERCASE
#undef FIELD_MIRRORED
#undef FIELD_NAME
#undef FIELD_NUMERIC
#undef FIELD_OLDNAME
#undef FIELD_TITLECASE
#undef FIELD_UPPERCASE
#undef FIELD_VALUE
#undef FINAL_QUOTE_PUNCTUATION
#undef FORMAT
#undef GENERAL_CATEGORY_COUNT
#undef INITIAL_QUOTE_PUNCTUATION
#undef LETTER_NUMBER
#undef LINE_SEPARATOR
#undef LONG
#undef LOWERCASE_LETTER
#undef MATH_SYMBOL
#undef MODIFIER_LETTER
#undef MODIFIER_SYMBOL
#undef NON_SPACING_MARK
#undef OTHER_LETTER
#undef OTHER_NUMBER
#undef OTHER_PUNCTUATION
#undef OTHER_SYMBOL
#undef PARAGRAPH_SEPARATOR
#undef PRIVATE_USE
#undef REQUIRED_FIELDS
#undef SHORT
#undef SPACE_SEPARATOR
#undef START_PUNCTUATION
#undef SURROGATE
#undef TITLECASE_LETTER
#undef UNASSIGNED
#undef UPPERCASE_LETTER

using $UnicodeSpecArray = $Array<UnicodeSpec>;
using $StringArray2 = $Array<::java::lang::String, 2>;
using $BufferedReader = ::java::io::BufferedReader;
using $File = ::java::io::File;
using $FileReader = ::java::io::FileReader;
using $IOException = ::java::io::IOException;
using $PrintStream = ::java::io::PrintStream;
using $Reader = ::java::io::Reader;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $StringBuffer = ::java::lang::StringBuffer;
using $ArrayList = ::java::util::ArrayList;
using $Pattern = ::java::util::regex::Pattern;

$FieldInfo _UnicodeSpec_FieldInfo_[] = {
	{"codePoint", "I", nullptr, 0, $field(UnicodeSpec, codePoint)},
	{"name", "Ljava/lang/String;", nullptr, 0, $field(UnicodeSpec, name)},
	{"generalCategory", "B", nullptr, 0, $field(UnicodeSpec, generalCategory)},
	{"bidiCategory", "B", nullptr, 0, $field(UnicodeSpec, bidiCategory)},
	{"combiningClass", "I", nullptr, 0, $field(UnicodeSpec, combiningClass)},
	{"decomposition", "Ljava/lang/String;", nullptr, 0, $field(UnicodeSpec, decomposition)},
	{"decimalValue", "I", nullptr, 0, $field(UnicodeSpec, decimalValue)},
	{"digitValue", "I", nullptr, 0, $field(UnicodeSpec, digitValue)},
	{"numericValue", "Ljava/lang/String;", nullptr, 0, $field(UnicodeSpec, numericValue)},
	{"mirrored", "Z", nullptr, 0, $field(UnicodeSpec, mirrored)},
	{"oldName", "Ljava/lang/String;", nullptr, 0, $field(UnicodeSpec, oldName)},
	{"comment", "Ljava/lang/String;", nullptr, 0, $field(UnicodeSpec, comment)},
	{"upperMap", "I", nullptr, 0, $field(UnicodeSpec, upperMap)},
	{"lowerMap", "I", nullptr, 0, $field(UnicodeSpec, lowerMap)},
	{"titleMap", "I", nullptr, 0, $field(UnicodeSpec, titleMap)},
	{"REQUIRED_FIELDS", "I", nullptr, $STATIC | $FINAL, $constField(UnicodeSpec, REQUIRED_FIELDS)},
	{"UNASSIGNED", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, UNASSIGNED)},
	{"UPPERCASE_LETTER", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, UPPERCASE_LETTER)},
	{"LOWERCASE_LETTER", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, LOWERCASE_LETTER)},
	{"TITLECASE_LETTER", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, TITLECASE_LETTER)},
	{"MODIFIER_LETTER", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, MODIFIER_LETTER)},
	{"OTHER_LETTER", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, OTHER_LETTER)},
	{"NON_SPACING_MARK", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, NON_SPACING_MARK)},
	{"ENCLOSING_MARK", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, ENCLOSING_MARK)},
	{"COMBINING_SPACING_MARK", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, COMBINING_SPACING_MARK)},
	{"DECIMAL_DIGIT_NUMBER", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, DECIMAL_DIGIT_NUMBER)},
	{"LETTER_NUMBER", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, LETTER_NUMBER)},
	{"OTHER_NUMBER", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, OTHER_NUMBER)},
	{"SPACE_SEPARATOR", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, SPACE_SEPARATOR)},
	{"LINE_SEPARATOR", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, LINE_SEPARATOR)},
	{"PARAGRAPH_SEPARATOR", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, PARAGRAPH_SEPARATOR)},
	{"CONTROL", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, CONTROL)},
	{"FORMAT", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, FORMAT)},
	{"PRIVATE_USE", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, PRIVATE_USE)},
	{"SURROGATE", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, SURROGATE)},
	{"DASH_PUNCTUATION", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, DASH_PUNCTUATION)},
	{"START_PUNCTUATION", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, START_PUNCTUATION)},
	{"END_PUNCTUATION", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, END_PUNCTUATION)},
	{"CONNECTOR_PUNCTUATION", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, CONNECTOR_PUNCTUATION)},
	{"OTHER_PUNCTUATION", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, OTHER_PUNCTUATION)},
	{"MATH_SYMBOL", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, MATH_SYMBOL)},
	{"CURRENCY_SYMBOL", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, CURRENCY_SYMBOL)},
	{"MODIFIER_SYMBOL", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, MODIFIER_SYMBOL)},
	{"OTHER_SYMBOL", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, OTHER_SYMBOL)},
	{"INITIAL_QUOTE_PUNCTUATION", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, INITIAL_QUOTE_PUNCTUATION)},
	{"FINAL_QUOTE_PUNCTUATION", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, FINAL_QUOTE_PUNCTUATION)},
	{"GENERAL_CATEGORY_COUNT", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, GENERAL_CATEGORY_COUNT)},
	{"SHORT", "B", nullptr, $STATIC | $FINAL, $constField(UnicodeSpec, SHORT)},
	{"LONG", "B", nullptr, $STATIC | $FINAL, $constField(UnicodeSpec, LONG)},
	{"generalCategoryList", "[[Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(UnicodeSpec, generalCategoryList)},
	{"DIRECTIONALITY_UNDEFINED", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, DIRECTIONALITY_UNDEFINED)},
	{"DIRECTIONALITY_LEFT_TO_RIGHT", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, DIRECTIONALITY_LEFT_TO_RIGHT)},
	{"DIRECTIONALITY_RIGHT_TO_LEFT", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, DIRECTIONALITY_RIGHT_TO_LEFT)},
	{"DIRECTIONALITY_RIGHT_TO_LEFT_ARABIC", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, DIRECTIONALITY_RIGHT_TO_LEFT_ARABIC)},
	{"DIRECTIONALITY_EUROPEAN_NUMBER", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, DIRECTIONALITY_EUROPEAN_NUMBER)},
	{"DIRECTIONALITY_EUROPEAN_NUMBER_SEPARATOR", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, DIRECTIONALITY_EUROPEAN_NUMBER_SEPARATOR)},
	{"DIRECTIONALITY_EUROPEAN_NUMBER_TERMINATOR", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, DIRECTIONALITY_EUROPEAN_NUMBER_TERMINATOR)},
	{"DIRECTIONALITY_ARABIC_NUMBER", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, DIRECTIONALITY_ARABIC_NUMBER)},
	{"DIRECTIONALITY_COMMON_NUMBER_SEPARATOR", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, DIRECTIONALITY_COMMON_NUMBER_SEPARATOR)},
	{"DIRECTIONALITY_NONSPACING_MARK", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, DIRECTIONALITY_NONSPACING_MARK)},
	{"DIRECTIONALITY_BOUNDARY_NEUTRAL", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, DIRECTIONALITY_BOUNDARY_NEUTRAL)},
	{"DIRECTIONALITY_PARAGRAPH_SEPARATOR", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, DIRECTIONALITY_PARAGRAPH_SEPARATOR)},
	{"DIRECTIONALITY_SEGMENT_SEPARATOR", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, DIRECTIONALITY_SEGMENT_SEPARATOR)},
	{"DIRECTIONALITY_WHITESPACE", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, DIRECTIONALITY_WHITESPACE)},
	{"DIRECTIONALITY_OTHER_NEUTRALS", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, DIRECTIONALITY_OTHER_NEUTRALS)},
	{"DIRECTIONALITY_LEFT_TO_RIGHT_EMBEDDING", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, DIRECTIONALITY_LEFT_TO_RIGHT_EMBEDDING)},
	{"DIRECTIONALITY_LEFT_TO_RIGHT_OVERRIDE", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, DIRECTIONALITY_LEFT_TO_RIGHT_OVERRIDE)},
	{"DIRECTIONALITY_RIGHT_TO_LEFT_EMBEDDING", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, DIRECTIONALITY_RIGHT_TO_LEFT_EMBEDDING)},
	{"DIRECTIONALITY_RIGHT_TO_LEFT_OVERRIDE", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, DIRECTIONALITY_RIGHT_TO_LEFT_OVERRIDE)},
	{"DIRECTIONALITY_POP_DIRECTIONAL_FORMAT", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, DIRECTIONALITY_POP_DIRECTIONAL_FORMAT)},
	{"DIRECTIONALITY_LEFT_TO_RIGHT_ISOLATE", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, DIRECTIONALITY_LEFT_TO_RIGHT_ISOLATE)},
	{"DIRECTIONALITY_RIGHT_TO_LEFT_ISOLATE", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, DIRECTIONALITY_RIGHT_TO_LEFT_ISOLATE)},
	{"DIRECTIONALITY_FIRST_STRONG_ISOLATE", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, DIRECTIONALITY_FIRST_STRONG_ISOLATE)},
	{"DIRECTIONALITY_POP_DIRECTIONAL_ISOLATE", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, DIRECTIONALITY_POP_DIRECTIONAL_ISOLATE)},
	{"DIRECTIONALITY_CATEGORY_COUNT", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(UnicodeSpec, DIRECTIONALITY_CATEGORY_COUNT)},
	{"bidiCategoryList", "[[Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(UnicodeSpec, bidiCategoryList)},
	{"FIELD_VALUE", "B", nullptr, $STATIC | $FINAL, $constField(UnicodeSpec, FIELD_VALUE)},
	{"FIELD_NAME", "B", nullptr, $STATIC | $FINAL, $constField(UnicodeSpec, FIELD_NAME)},
	{"FIELD_CATEGORY", "B", nullptr, $STATIC | $FINAL, $constField(UnicodeSpec, FIELD_CATEGORY)},
	{"FIELD_CLASS", "B", nullptr, $STATIC | $FINAL, $constField(UnicodeSpec, FIELD_CLASS)},
	{"FIELD_BIDI", "B", nullptr, $STATIC | $FINAL, $constField(UnicodeSpec, FIELD_BIDI)},
	{"FIELD_DECOMPOSITION", "B", nullptr, $STATIC | $FINAL, $constField(UnicodeSpec, FIELD_DECOMPOSITION)},
	{"FIELD_DECIMAL", "B", nullptr, $STATIC | $FINAL, $constField(UnicodeSpec, FIELD_DECIMAL)},
	{"FIELD_DIGIT", "B", nullptr, $STATIC | $FINAL, $constField(UnicodeSpec, FIELD_DIGIT)},
	{"FIELD_NUMERIC", "B", nullptr, $STATIC | $FINAL, $constField(UnicodeSpec, FIELD_NUMERIC)},
	{"FIELD_MIRRORED", "B", nullptr, $STATIC | $FINAL, $constField(UnicodeSpec, FIELD_MIRRORED)},
	{"FIELD_OLDNAME", "B", nullptr, $STATIC | $FINAL, $constField(UnicodeSpec, FIELD_OLDNAME)},
	{"FIELD_COMMENT", "B", nullptr, $STATIC | $FINAL, $constField(UnicodeSpec, FIELD_COMMENT)},
	{"FIELD_UPPERCASE", "B", nullptr, $STATIC | $FINAL, $constField(UnicodeSpec, FIELD_UPPERCASE)},
	{"FIELD_LOWERCASE", "B", nullptr, $STATIC | $FINAL, $constField(UnicodeSpec, FIELD_LOWERCASE)},
	{"FIELD_TITLECASE", "B", nullptr, $STATIC | $FINAL, $constField(UnicodeSpec, FIELD_TITLECASE)},
	{"tokenSeparator", "Ljava/util/regex/Pattern;", nullptr, $STATIC | $FINAL, $staticField(UnicodeSpec, tokenSeparator)},
	{}
};

$MethodInfo _UnicodeSpec_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(UnicodeSpec, init$, void)},
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(UnicodeSpec, init$, void, int32_t)},
	{"getBidiCategory", "()B", nullptr, $PUBLIC, $virtualMethod(UnicodeSpec, getBidiCategory, int8_t)},
	{"getCodePoint", "()I", nullptr, $PUBLIC, $virtualMethod(UnicodeSpec, getCodePoint, int32_t)},
	{"getCombiningClass", "()I", nullptr, $PUBLIC, $virtualMethod(UnicodeSpec, getCombiningClass, int32_t)},
	{"getComment", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(UnicodeSpec, getComment, $String*)},
	{"getDecimalValue", "()I", nullptr, $PUBLIC, $virtualMethod(UnicodeSpec, getDecimalValue, int32_t)},
	{"getDecomposition", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(UnicodeSpec, getDecomposition, $String*)},
	{"getDigitValue", "()I", nullptr, $PUBLIC, $virtualMethod(UnicodeSpec, getDigitValue, int32_t)},
	{"getGeneralCategory", "()B", nullptr, $PUBLIC, $virtualMethod(UnicodeSpec, getGeneralCategory, int8_t)},
	{"getLowerMap", "()I", nullptr, $PUBLIC, $virtualMethod(UnicodeSpec, getLowerMap, int32_t)},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(UnicodeSpec, getName, $String*)},
	{"getNumericValue", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(UnicodeSpec, getNumericValue, $String*)},
	{"getOldName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(UnicodeSpec, getOldName, $String*)},
	{"getTitleMap", "()I", nullptr, $PUBLIC, $virtualMethod(UnicodeSpec, getTitleMap, int32_t)},
	{"getUpperMap", "()I", nullptr, $PUBLIC, $virtualMethod(UnicodeSpec, getUpperMap, int32_t)},
	{"hasLowerMap", "()Z", nullptr, $PUBLIC, $virtualMethod(UnicodeSpec, hasLowerMap, bool)},
	{"hasTitleMap", "()Z", nullptr, $PUBLIC, $virtualMethod(UnicodeSpec, hasTitleMap, bool)},
	{"hasUpperMap", "()Z", nullptr, $PUBLIC, $virtualMethod(UnicodeSpec, hasUpperMap, bool)},
	{"hex4", "(I)Ljava/lang/String;", nullptr, $STATIC, $staticMethod(UnicodeSpec, hex4, $String*, int32_t)},
	{"hex6", "(I)Ljava/lang/String;", nullptr, $STATIC, $staticMethod(UnicodeSpec, hex6, $String*, int32_t)},
	{"isDecimalValue", "()Z", nullptr, $PUBLIC, $virtualMethod(UnicodeSpec, isDecimalValue, bool)},
	{"isDigitValue", "()Z", nullptr, $PUBLIC, $virtualMethod(UnicodeSpec, isDigitValue, bool)},
	{"isMirrored", "()Z", nullptr, $PUBLIC, $virtualMethod(UnicodeSpec, isMirrored, bool)},
	{"isNumericValue", "()Z", nullptr, $PUBLIC, $virtualMethod(UnicodeSpec, isNumericValue, bool)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(UnicodeSpec, main, void, $StringArray*)},
	{"parse", "(Ljava/lang/String;)LUnicodeSpec;", nullptr, $PUBLIC | $STATIC, $staticMethod(UnicodeSpec, parse, UnicodeSpec*, $String*)},
	{"parseBidiCategory", "(Ljava/lang/String;)B", nullptr, $PUBLIC | $STATIC, $staticMethod(UnicodeSpec, parseBidiCategory, int8_t, $String*), "java.lang.Exception"},
	{"parseCodePoint", "(Ljava/lang/String;)I", nullptr, $PUBLIC | $STATIC, $staticMethod(UnicodeSpec, parseCodePoint, int32_t, $String*), "java.lang.NumberFormatException"},
	{"parseCombiningClass", "(Ljava/lang/String;)I", nullptr, $PUBLIC | $STATIC, $staticMethod(UnicodeSpec, parseCombiningClass, int32_t, $String*), "java.lang.Exception"},
	{"parseComment", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(UnicodeSpec, parseComment, $String*, $String*), "java.lang.Exception"},
	{"parseDecimalValue", "(Ljava/lang/String;)I", nullptr, $PUBLIC | $STATIC, $staticMethod(UnicodeSpec, parseDecimalValue, int32_t, $String*), "java.lang.NumberFormatException"},
	{"parseDecomposition", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(UnicodeSpec, parseDecomposition, $String*, $String*), "java.lang.Exception"},
	{"parseDigitValue", "(Ljava/lang/String;)I", nullptr, $PUBLIC | $STATIC, $staticMethod(UnicodeSpec, parseDigitValue, int32_t, $String*), "java.lang.NumberFormatException"},
	{"parseGeneralCategory", "(Ljava/lang/String;)B", nullptr, $PUBLIC | $STATIC, $staticMethod(UnicodeSpec, parseGeneralCategory, int8_t, $String*), "java.lang.Exception"},
	{"parseLowerMap", "(Ljava/lang/String;)I", nullptr, $PUBLIC | $STATIC, $staticMethod(UnicodeSpec, parseLowerMap, int32_t, $String*), "java.lang.NumberFormatException"},
	{"parseMirrored", "(Ljava/lang/String;)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(UnicodeSpec, parseMirrored, bool, $String*), "java.lang.Exception"},
	{"parseName", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(UnicodeSpec, parseName, $String*, $String*), "java.lang.Exception"},
	{"parseNumericValue", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(UnicodeSpec, parseNumericValue, $String*, $String*), "java.lang.Exception"},
	{"parseOldName", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(UnicodeSpec, parseOldName, $String*, $String*), "java.lang.Exception"},
	{"parseTitleMap", "(Ljava/lang/String;)I", nullptr, $PUBLIC | $STATIC, $staticMethod(UnicodeSpec, parseTitleMap, int32_t, $String*), "java.lang.NumberFormatException"},
	{"parseUpperMap", "(Ljava/lang/String;)I", nullptr, $PUBLIC | $STATIC, $staticMethod(UnicodeSpec, parseUpperMap, int32_t, $String*), "java.lang.NumberFormatException"},
	{"readSpecFile", "(Ljava/io/File;I)[LUnicodeSpec;", nullptr, $PUBLIC | $STATIC, $staticMethod(UnicodeSpec, readSpecFile, $UnicodeSpecArray*, $File*, int32_t), "java.io.FileNotFoundException"},
	{"setBidiCategory", "(B)V", nullptr, 0, $virtualMethod(UnicodeSpec, setBidiCategory, void, int8_t)},
	{"setCodePoint", "(I)V", nullptr, 0, $virtualMethod(UnicodeSpec, setCodePoint, void, int32_t)},
	{"setCombiningClass", "(I)V", nullptr, 0, $virtualMethod(UnicodeSpec, setCombiningClass, void, int32_t)},
	{"setComment", "(Ljava/lang/String;)V", nullptr, 0, $virtualMethod(UnicodeSpec, setComment, void, $String*)},
	{"setDecimalValue", "(I)V", nullptr, 0, $virtualMethod(UnicodeSpec, setDecimalValue, void, int32_t)},
	{"setDecomposition", "(Ljava/lang/String;)V", nullptr, 0, $virtualMethod(UnicodeSpec, setDecomposition, void, $String*)},
	{"setDigitValue", "(I)V", nullptr, 0, $virtualMethod(UnicodeSpec, setDigitValue, void, int32_t)},
	{"setGeneralCategory", "(B)V", nullptr, 0, $virtualMethod(UnicodeSpec, setGeneralCategory, void, int8_t)},
	{"setLowerMap", "(I)V", nullptr, 0, $virtualMethod(UnicodeSpec, setLowerMap, void, int32_t)},
	{"setMirrored", "(Z)V", nullptr, 0, $virtualMethod(UnicodeSpec, setMirrored, void, bool)},
	{"setName", "(Ljava/lang/String;)V", nullptr, 0, $virtualMethod(UnicodeSpec, setName, void, $String*)},
	{"setNumericValue", "(Ljava/lang/String;)V", nullptr, 0, $virtualMethod(UnicodeSpec, setNumericValue, void, $String*)},
	{"setOldName", "(Ljava/lang/String;)V", nullptr, 0, $virtualMethod(UnicodeSpec, setOldName, void, $String*)},
	{"setTitleMap", "(I)V", nullptr, 0, $virtualMethod(UnicodeSpec, setTitleMap, void, int32_t)},
	{"setUpperMap", "(I)V", nullptr, 0, $virtualMethod(UnicodeSpec, setUpperMap, void, int32_t)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(UnicodeSpec, toString, $String*)},
	{}
};

$ClassInfo _UnicodeSpec_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"UnicodeSpec",
	"java.lang.Object",
	nullptr,
	_UnicodeSpec_FieldInfo_,
	_UnicodeSpec_MethodInfo_
};

$Object* allocate$UnicodeSpec($Class* clazz) {
	return $of($alloc(UnicodeSpec));
}

$StringArray2* UnicodeSpec::generalCategoryList = nullptr;
$StringArray2* UnicodeSpec::bidiCategoryList = nullptr;
$Pattern* UnicodeSpec::tokenSeparator = nullptr;

void UnicodeSpec::init$() {
	UnicodeSpec::init$(0x0000FFFF);
}

void UnicodeSpec::init$(int32_t codePoint) {
	this->codePoint = codePoint;
	this->generalCategory = UnicodeSpec::UNASSIGNED;
	this->bidiCategory = UnicodeSpec::DIRECTIONALITY_UNDEFINED;
	this->mirrored = false;
	this->titleMap = 0x0000FFFF;
	this->upperMap = 0x0000FFFF;
	this->lowerMap = 0x0000FFFF;
	this->decimalValue = -1;
	this->digitValue = -1;
	$set(this, numericValue, ""_s);
	$set(this, oldName, nullptr);
	$set(this, comment, nullptr);
	$set(this, name, nullptr);
}

$String* UnicodeSpec::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuffer, result, $new($StringBuffer, $(hex6(this->codePoint))));
	if (getUpperMap() != 0x0000FFFF) {
		result->append(", upper="_s)->append($(hex6(this->upperMap)));
	}
	if (getLowerMap() != 0x0000FFFF) {
		result->append(", lower="_s)->append($(hex6(this->lowerMap)));
	}
	if (getTitleMap() != 0x0000FFFF) {
		result->append(", title="_s)->append($(hex6(this->titleMap)));
	}
	return result->toString();
}

$String* UnicodeSpec::hex4(int32_t n) {
	$init(UnicodeSpec);
	$useLocalCurrentObjectStackCache();
	$var($String, q, $nc($($Long::toHexString((int32_t)(n & (uint32_t)0x0000FFFF))))->toUpperCase());
	return $str({$("0000"_s->substring($Math::min(4, q->length()))), q});
}

$String* UnicodeSpec::hex6(int32_t n) {
	$init(UnicodeSpec);
	$useLocalCurrentObjectStackCache();
	$var($String, str, $nc($($Integer::toHexString((int32_t)(n & (uint32_t)0x00FFFFFF))))->toUpperCase());
	return $str({$("000000"_s->substring($Math::min(6, str->length()))), str});
}

UnicodeSpec* UnicodeSpec::parse($String* s) {
	$init(UnicodeSpec);
	$useLocalCurrentObjectStackCache();
	$var(UnicodeSpec, spec, nullptr);
	$var($StringArray, tokens, nullptr);
	try {
		$assign(tokens, $nc(UnicodeSpec::tokenSeparator)->split(s, UnicodeSpec::REQUIRED_FIELDS));
		$assign(spec, $new(UnicodeSpec));
		spec->setCodePoint(parseCodePoint($nc(tokens)->get(UnicodeSpec::FIELD_VALUE)));
		spec->setName($(parseName($nc(tokens)->get(UnicodeSpec::FIELD_NAME))));
		spec->setGeneralCategory(parseGeneralCategory($nc(tokens)->get(UnicodeSpec::FIELD_CATEGORY)));
		spec->setBidiCategory(parseBidiCategory($nc(tokens)->get(UnicodeSpec::FIELD_BIDI)));
		spec->setCombiningClass(parseCombiningClass($nc(tokens)->get(UnicodeSpec::FIELD_CLASS)));
		spec->setDecomposition($(parseDecomposition($nc(tokens)->get(UnicodeSpec::FIELD_DECOMPOSITION))));
		spec->setDecimalValue(parseDecimalValue($nc(tokens)->get(UnicodeSpec::FIELD_DECIMAL)));
		spec->setDigitValue(parseDigitValue($nc(tokens)->get(UnicodeSpec::FIELD_DIGIT)));
		spec->setNumericValue($(parseNumericValue($nc(tokens)->get(UnicodeSpec::FIELD_NUMERIC))));
		spec->setMirrored(parseMirrored($nc(tokens)->get(UnicodeSpec::FIELD_MIRRORED)));
		spec->setOldName($(parseOldName($nc(tokens)->get(UnicodeSpec::FIELD_OLDNAME))));
		spec->setComment($(parseComment($nc(tokens)->get(UnicodeSpec::FIELD_COMMENT))));
		spec->setUpperMap(parseUpperMap($nc(tokens)->get(UnicodeSpec::FIELD_UPPERCASE)));
		spec->setLowerMap(parseLowerMap($nc(tokens)->get(UnicodeSpec::FIELD_LOWERCASE)));
		spec->setTitleMap(parseTitleMap($nc(tokens)->get(UnicodeSpec::FIELD_TITLECASE)));
	} catch ($Exception& e) {
		$assign(spec, nullptr);
		$nc($System::out)->println("Error parsing spec line."_s);
	}
	return spec;
}

int32_t UnicodeSpec::parseCodePoint($String* s) {
	$init(UnicodeSpec);
	return $Integer::parseInt(s, 16);
}

$String* UnicodeSpec::parseName($String* s) {
	$init(UnicodeSpec);
	if (s == nullptr) {
		$throwNew($Exception, "Cannot parse name."_s);
	}
	return s;
}

int8_t UnicodeSpec::parseGeneralCategory($String* s) {
	$init(UnicodeSpec);
	int8_t category = UnicodeSpec::GENERAL_CATEGORY_COUNT;
	for (int8_t x = (int8_t)0; x < $nc(UnicodeSpec::generalCategoryList)->length; ++x) {
		if ($nc(s)->equals($nc($nc(UnicodeSpec::generalCategoryList)->get(x))->get(UnicodeSpec::SHORT))) {
			category = x;
			break;
		}
	}
	if (category >= UnicodeSpec::GENERAL_CATEGORY_COUNT) {
		$throwNew($Exception, "Could not parse general category."_s);
	}
	return category;
}

int8_t UnicodeSpec::parseBidiCategory($String* s) {
	$init(UnicodeSpec);
	int8_t category = UnicodeSpec::DIRECTIONALITY_CATEGORY_COUNT;
	for (int8_t x = (int8_t)0; x < $nc(UnicodeSpec::bidiCategoryList)->length; ++x) {
		if ($nc(s)->equals($nc($nc(UnicodeSpec::bidiCategoryList)->get(x))->get(UnicodeSpec::SHORT))) {
			category = x;
			break;
		}
	}
	if (category >= UnicodeSpec::DIRECTIONALITY_CATEGORY_COUNT) {
		$throwNew($Exception, "Could not parse bidi category."_s);
	}
	return category;
}

int32_t UnicodeSpec::parseCombiningClass($String* s) {
	$init(UnicodeSpec);
	int32_t combining = -1;
	if ($nc(s)->length() > 0) {
		combining = $Integer::parseInt(s, 10);
	}
	return combining;
}

$String* UnicodeSpec::parseDecomposition($String* s) {
	$init(UnicodeSpec);
	if (s == nullptr) {
		$throwNew($Exception, "Cannot parse decomposition."_s);
	}
	return s;
}

int32_t UnicodeSpec::parseDecimalValue($String* s) {
	$init(UnicodeSpec);
	int32_t value = -1;
	if ($nc(s)->length() > 0) {
		value = $Integer::parseInt(s, 10);
	}
	return value;
}

int32_t UnicodeSpec::parseDigitValue($String* s) {
	$init(UnicodeSpec);
	int32_t value = -1;
	if ($nc(s)->length() > 0) {
		value = $Integer::parseInt(s, 10);
	}
	return value;
}

$String* UnicodeSpec::parseNumericValue($String* s) {
	$init(UnicodeSpec);
	if (s == nullptr) {
		$throwNew($Exception, "Cannot parse numeric value."_s);
	}
	return s;
}

$String* UnicodeSpec::parseComment($String* s) {
	$init(UnicodeSpec);
	if (s == nullptr) {
		$throwNew($Exception, "Cannot parse comment."_s);
	}
	return s;
}

bool UnicodeSpec::parseMirrored($String* s) {
	$init(UnicodeSpec);
	bool mirrored = false;
	if ($nc(s)->length() == 1) {
		if (s->charAt(0) == u'Y') {
			mirrored = true;
		} else if (s->charAt(0) == u'N') {
			mirrored = false;
		} else {
			$throwNew($Exception, "Cannot parse mirrored property."_s);
		}
	} else {
		$throwNew($Exception, "Cannot parse mirrored property."_s);
	}
	return mirrored;
}

$String* UnicodeSpec::parseOldName($String* s) {
	$init(UnicodeSpec);
	if (s == nullptr) {
		$throwNew($Exception, "Cannot parse old name"_s);
	}
	return s;
}

int32_t UnicodeSpec::parseUpperMap($String* s) {
	$init(UnicodeSpec);
	int32_t upperCase = 0x0000FFFF;
	if ($nc(s)->length() >= 4) {
		upperCase = $Integer::parseInt(s, 16);
	} else if (s->length() != 0) {
		$throwNew($NumberFormatException);
	}
	return upperCase;
}

int32_t UnicodeSpec::parseLowerMap($String* s) {
	$init(UnicodeSpec);
	int32_t lowerCase = 0x0000FFFF;
	if ($nc(s)->length() >= 4) {
		lowerCase = $Integer::parseInt(s, 16);
	} else if (s->length() != 0) {
		$throwNew($NumberFormatException);
	}
	return lowerCase;
}

int32_t UnicodeSpec::parseTitleMap($String* s) {
	$init(UnicodeSpec);
	int32_t titleCase = 0x0000FFFF;
	if ($nc(s)->length() >= 4) {
		titleCase = $Integer::parseInt(s, 16);
	} else if (s->length() != 0) {
		$throwNew($NumberFormatException);
	}
	return titleCase;
}

$UnicodeSpecArray* UnicodeSpec::readSpecFile($File* file, int32_t plane) {
	$init(UnicodeSpec);
	$useLocalCurrentObjectStackCache();
	$var($ArrayList, list, $new($ArrayList, 3000));
	$var($UnicodeSpecArray, result, nullptr);
	int32_t count = 0;
	$var($BufferedReader, f, $new($BufferedReader, $$new($FileReader, file)));
	$var($String, line, nullptr);
	bool loop$break = false;
	while (true) {
		try {
			$assign(line, f->readLine());
		} catch ($IOException& e) {
			loop$break = true;
			break;
		}
		if (line == nullptr) {
			loop$break = true;
			break;
		}
		$var(UnicodeSpec, item, parse($($nc(line)->trim())));
		int32_t specPlane = (int32_t)((uint32_t)$nc(item)->getCodePoint() >> 16);
		if (specPlane < plane) {
			continue;
		}
		if (specPlane > plane) {
			break;
		}
		if (item != nullptr) {
			list->add(item);
		}
	}
	$assign(result, $new($UnicodeSpecArray, list->size()));
	list->toArray(result);
	return result;
}

void UnicodeSpec::setCodePoint(int32_t value) {
	this->codePoint = value;
}

int32_t UnicodeSpec::getCodePoint() {
	return this->codePoint;
}

void UnicodeSpec::setName($String* name) {
	$set(this, name, name);
}

$String* UnicodeSpec::getName() {
	return this->name;
}

void UnicodeSpec::setGeneralCategory(int8_t category) {
	this->generalCategory = category;
}

int8_t UnicodeSpec::getGeneralCategory() {
	return this->generalCategory;
}

void UnicodeSpec::setBidiCategory(int8_t category) {
	this->bidiCategory = category;
}

int8_t UnicodeSpec::getBidiCategory() {
	return this->bidiCategory;
}

void UnicodeSpec::setCombiningClass(int32_t combiningClass) {
	this->combiningClass = combiningClass;
}

int32_t UnicodeSpec::getCombiningClass() {
	return this->combiningClass;
}

void UnicodeSpec::setDecomposition($String* decomposition) {
	$set(this, decomposition, decomposition);
}

$String* UnicodeSpec::getDecomposition() {
	return this->decomposition;
}

void UnicodeSpec::setDecimalValue(int32_t value) {
	this->decimalValue = value;
}

int32_t UnicodeSpec::getDecimalValue() {
	return this->decimalValue;
}

bool UnicodeSpec::isDecimalValue() {
	return this->decimalValue != -1;
}

void UnicodeSpec::setDigitValue(int32_t value) {
	this->digitValue = value;
}

int32_t UnicodeSpec::getDigitValue() {
	return this->digitValue;
}

bool UnicodeSpec::isDigitValue() {
	return this->digitValue != -1;
}

void UnicodeSpec::setNumericValue($String* value) {
	$set(this, numericValue, value);
}

$String* UnicodeSpec::getNumericValue() {
	return this->numericValue;
}

bool UnicodeSpec::isNumericValue() {
	return $nc(this->numericValue)->length() > 0;
}

void UnicodeSpec::setMirrored(bool value) {
	this->mirrored = value;
}

bool UnicodeSpec::isMirrored() {
	return this->mirrored;
}

void UnicodeSpec::setOldName($String* name) {
	$set(this, oldName, name);
}

$String* UnicodeSpec::getOldName() {
	return this->oldName;
}

void UnicodeSpec::setComment($String* comment) {
	$set(this, comment, comment);
}

$String* UnicodeSpec::getComment() {
	return this->comment;
}

void UnicodeSpec::setUpperMap(int32_t ch) {
	this->upperMap = ch;
}

int32_t UnicodeSpec::getUpperMap() {
	return this->upperMap;
}

bool UnicodeSpec::hasUpperMap() {
	return this->upperMap != 0x0000FFFF;
}

void UnicodeSpec::setLowerMap(int32_t ch) {
	this->lowerMap = ch;
}

int32_t UnicodeSpec::getLowerMap() {
	return this->lowerMap;
}

bool UnicodeSpec::hasLowerMap() {
	return this->lowerMap != 0x0000FFFF;
}

void UnicodeSpec::setTitleMap(int32_t ch) {
	this->titleMap = ch;
}

int32_t UnicodeSpec::getTitleMap() {
	return this->titleMap;
}

bool UnicodeSpec::hasTitleMap() {
	return this->titleMap != 0x0000FFFF;
}

void UnicodeSpec::main($StringArray* args) {
	$init(UnicodeSpec);
	$useLocalCurrentObjectStackCache();
	$var($UnicodeSpecArray, spec, nullptr);
	if ($nc(args)->length == 2) {
		try {
			$var($File, file, $new($File, args->get(0)));
			int32_t plane = $Integer::parseInt(args->get(1));
			$assign(spec, UnicodeSpec::readSpecFile(file, plane));
			$nc($System::out)->println($$str({"UnicodeSpec["_s, $$str($nc(spec)->length), "]:"_s}));
			for (int32_t x = 0; x < $nc(spec)->length; ++x) {
				$nc($System::out)->println($($nc(spec->get(x))->toString()));
			}
		} catch ($Exception& e) {
			e->printStackTrace();
		}
	}
}

void clinit$UnicodeSpec($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(UnicodeSpec::generalCategoryList, $new($StringArray2, {
		$$new($StringArray, {
			"Cn"_s,
			"UNASSIGNED"_s
		}),
		$$new($StringArray, {
			"Lu"_s,
			"UPPERCASE_LETTER"_s
		}),
		$$new($StringArray, {
			"Ll"_s,
			"LOWERCASE_LETTER"_s
		}),
		$$new($StringArray, {
			"Lt"_s,
			"TITLECASE_LETTER"_s
		}),
		$$new($StringArray, {
			"Lm"_s,
			"MODIFIER_LETTER"_s
		}),
		$$new($StringArray, {
			"Lo"_s,
			"OTHER_LETTER"_s
		}),
		$$new($StringArray, {
			"Mn"_s,
			"NON_SPACING_MARK"_s
		}),
		$$new($StringArray, {
			"Me"_s,
			"ENCLOSING_MARK"_s
		}),
		$$new($StringArray, {
			"Mc"_s,
			"COMBINING_SPACING_MARK"_s
		}),
		$$new($StringArray, {
			"Nd"_s,
			"DECIMAL_DIGIT_NUMBER"_s
		}),
		$$new($StringArray, {
			"Nl"_s,
			"LETTER_NUMBER"_s
		}),
		$$new($StringArray, {
			"No"_s,
			"OTHER_NUMBER"_s
		}),
		$$new($StringArray, {
			"Zs"_s,
			"SPACE_SEPARATOR"_s
		}),
		$$new($StringArray, {
			"Zl"_s,
			"LINE_SEPARATOR"_s
		}),
		$$new($StringArray, {
			"Zp"_s,
			"PARAGRAPH_SEPARATOR"_s
		}),
		$$new($StringArray, {
			"Cc"_s,
			"CONTROL"_s
		}),
		$$new($StringArray, {
			"Cf"_s,
			"FORMAT"_s
		}),
		$$new($StringArray, {
			"xx"_s,
			"unused"_s
		}),
		$$new($StringArray, {
			"Co"_s,
			"PRIVATE_USE"_s
		}),
		$$new($StringArray, {
			"Cs"_s,
			"SURROGATE"_s
		}),
		$$new($StringArray, {
			"Pd"_s,
			"DASH_PUNCTUATION"_s
		}),
		$$new($StringArray, {
			"Ps"_s,
			"START_PUNCTUATION"_s
		}),
		$$new($StringArray, {
			"Pe"_s,
			"END_PUNCTUATION"_s
		}),
		$$new($StringArray, {
			"Pc"_s,
			"CONNECTOR_PUNCTUATION"_s
		}),
		$$new($StringArray, {
			"Po"_s,
			"OTHER_PUNCTUATION"_s
		}),
		$$new($StringArray, {
			"Sm"_s,
			"MATH_SYMBOL"_s
		}),
		$$new($StringArray, {
			"Sc"_s,
			"CURRENCY_SYMBOL"_s
		}),
		$$new($StringArray, {
			"Sk"_s,
			"MODIFIER_SYMBOL"_s
		}),
		$$new($StringArray, {
			"So"_s,
			"OTHER_SYMBOL"_s
		}),
		$$new($StringArray, {
			"Pi"_s,
			"INITIAL_QUOTE_PUNCTUATION"_s
		}),
		$$new($StringArray, {
			"Pf"_s,
			"FINAL_QUOTE_PUNCTUATION"_s
		})
	}));
	$assignStatic(UnicodeSpec::bidiCategoryList, $new($StringArray2, {
		$$new($StringArray, {
			"L"_s,
			"DIRECTIONALITY_LEFT_TO_RIGHT"_s
		}),
		$$new($StringArray, {
			"R"_s,
			"DIRECTIONALITY_RIGHT_TO_LEFT"_s
		}),
		$$new($StringArray, {
			"AL"_s,
			"DIRECTIONALITY_RIGHT_TO_LEFT_ARABIC"_s
		}),
		$$new($StringArray, {
			"EN"_s,
			"DIRECTIONALITY_EUROPEAN_NUMBER"_s
		}),
		$$new($StringArray, {
			"ES"_s,
			"DIRECTIONALITY_EUROPEAN_NUMBER_SEPARATOR"_s
		}),
		$$new($StringArray, {
			"ET"_s,
			"DIRECTIONALITY_EUROPEAN_NUMBER_TERMINATOR"_s
		}),
		$$new($StringArray, {
			"AN"_s,
			"DIRECTIONALITY_ARABIC_NUMBER"_s
		}),
		$$new($StringArray, {
			"CS"_s,
			"DIRECTIONALITY_COMMON_NUMBER_SEPARATOR"_s
		}),
		$$new($StringArray, {
			"NSM"_s,
			"DIRECTIONALITY_NONSPACING_MARK"_s
		}),
		$$new($StringArray, {
			"BN"_s,
			"DIRECTIONALITY_BOUNDARY_NEUTRAL"_s
		}),
		$$new($StringArray, {
			"B"_s,
			"DIRECTIONALITY_PARAGRAPH_SEPARATOR"_s
		}),
		$$new($StringArray, {
			"S"_s,
			"DIRECTIONALITY_SEGMENT_SEPARATOR"_s
		}),
		$$new($StringArray, {
			"WS"_s,
			"DIRECTIONALITY_WHITESPACE"_s
		}),
		$$new($StringArray, {
			"ON"_s,
			"DIRECTIONALITY_OTHER_NEUTRALS"_s
		}),
		$$new($StringArray, {
			"LRE"_s,
			"DIRECTIONALITY_LEFT_TO_RIGHT_EMBEDDING"_s
		}),
		$$new($StringArray, {
			"LRO"_s,
			"DIRECTIONALITY_LEFT_TO_RIGHT_OVERRIDE"_s
		}),
		$$new($StringArray, {
			"RLE"_s,
			"DIRECTIONALITY_RIGHT_TO_LEFT_EMBEDDING"_s
		}),
		$$new($StringArray, {
			"RLO"_s,
			"DIRECTIONALITY_RIGHT_TO_LEFT_OVERRIDE"_s
		}),
		$$new($StringArray, {
			"PDF"_s,
			"DIRECTIONALITY_POP_DIRECTIONAL_FORMAT"_s
		}),
		$$new($StringArray, {
			"LRI"_s,
			"DIRECTIONALITY_LEFT_TO_RIGHT_ISOLATE"_s
		}),
		$$new($StringArray, {
			"RLI"_s,
			"DIRECTIONALITY_RIGHT_TO_LEFT_ISOLATE"_s
		}),
		$$new($StringArray, {
			"FSI"_s,
			"DIRECTIONALITY_FIRST_STRONG_ISOLATE"_s
		}),
		$$new($StringArray, {
			"PDI"_s,
			"DIRECTIONALITY_POP_DIRECTIONAL_ISOLATE"_s
		})
	}));
	$assignStatic(UnicodeSpec::tokenSeparator, $Pattern::compile(";"_s));
}

UnicodeSpec::UnicodeSpec() {
}

$Class* UnicodeSpec::load$($String* name, bool initialize) {
	$loadClass(UnicodeSpec, name, initialize, &_UnicodeSpec_ClassInfo_, clinit$UnicodeSpec, allocate$UnicodeSpec);
	return class$;
}

$Class* UnicodeSpec::class$ = nullptr;