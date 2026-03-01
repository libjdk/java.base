#include <java/text/MessageFormat.h>

#include <java/io/InvalidObjectException.h>
#include <java/io/ObjectInputStream.h>
#include <java/lang/ArrayIndexOutOfBoundsException.h>
#include <java/lang/CharSequence.h>
#include <java/lang/Number.h>
#include <java/lang/NumberFormatException.h>
#include <java/lang/StringBuffer.h>
#include <java/text/AttributedCharacterIterator$Attribute.h>
#include <java/text/AttributedCharacterIterator.h>
#include <java/text/CharacterIterator.h>
#include <java/text/ChoiceFormat.h>
#include <java/text/DateFormat.h>
#include <java/text/DecimalFormat.h>
#include <java/text/DecimalFormatSymbols.h>
#include <java/text/FieldPosition.h>
#include <java/text/Format$Field.h>
#include <java/text/Format.h>
#include <java/text/MessageFormat$Field.h>
#include <java/text/NumberFormat.h>
#include <java/text/ParseException.h>
#include <java/text/ParsePosition.h>
#include <java/text/SimpleDateFormat.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Date.h>
#include <java/util/List.h>
#include <java/util/Locale$Category.h>
#include <java/util/Locale.h>
#include <jcpp.h>

#undef ARGUMENT
#undef DATE_TIME_MODIFIERS
#undef DATE_TIME_MODIFIER_KEYWORDS
#undef DEFAULT
#undef DONE
#undef FORMAT
#undef FULL
#undef INITIAL_FORMATS
#undef LONG
#undef MEDIUM
#undef MODIFIER_CURRENCY
#undef MODIFIER_DEFAULT
#undef MODIFIER_FULL
#undef MODIFIER_INTEGER
#undef MODIFIER_LONG
#undef MODIFIER_MEDIUM
#undef MODIFIER_PERCENT
#undef MODIFIER_SHORT
#undef NUMBER_MODIFIER_KEYWORDS
#undef ROOT
#undef SEG_INDEX
#undef SEG_MODIFIER
#undef SEG_RAW
#undef SEG_TYPE
#undef SHORT
#undef TYPE_CHOICE
#undef TYPE_DATE
#undef TYPE_KEYWORDS
#undef TYPE_NULL
#undef TYPE_NUMBER
#undef TYPE_TIME

using $StringBuilderArray = $Array<::java::lang::StringBuilder>;
using $AttributedCharacterIteratorArray = $Array<::java::text::AttributedCharacterIterator>;
using $FormatArray = $Array<::java::text::Format>;
using $InvalidObjectException = ::java::io::InvalidObjectException;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ArrayIndexOutOfBoundsException = ::java::lang::ArrayIndexOutOfBoundsException;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $Number = ::java::lang::Number;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $StringBuffer = ::java::lang::StringBuffer;
using $AttributedCharacterIterator = ::java::text::AttributedCharacterIterator;
using $AttributedCharacterIterator$Attribute = ::java::text::AttributedCharacterIterator$Attribute;
using $CharacterIterator = ::java::text::CharacterIterator;
using $ChoiceFormat = ::java::text::ChoiceFormat;
using $DateFormat = ::java::text::DateFormat;
using $DecimalFormat = ::java::text::DecimalFormat;
using $DecimalFormatSymbols = ::java::text::DecimalFormatSymbols;
using $FieldPosition = ::java::text::FieldPosition;
using $Format = ::java::text::Format;
using $MessageFormat$Field = ::java::text::MessageFormat$Field;
using $NumberFormat = ::java::text::NumberFormat;
using $ParseException = ::java::text::ParseException;
using $ParsePosition = ::java::text::ParsePosition;
using $SimpleDateFormat = ::java::text::SimpleDateFormat;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Date = ::java::util::Date;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Locale$Category = ::java::util::Locale$Category;

namespace java {
	namespace text {

$FieldInfo _MessageFormat_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MessageFormat, serialVersionUID)},
	{"locale", "Ljava/util/Locale;", nullptr, $PRIVATE, $field(MessageFormat, locale)},
	{"pattern", "Ljava/lang/String;", nullptr, $PRIVATE, $field(MessageFormat, pattern)},
	{"INITIAL_FORMATS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MessageFormat, INITIAL_FORMATS)},
	{"formats", "[Ljava/text/Format;", nullptr, $PRIVATE, $field(MessageFormat, formats)},
	{"offsets", "[I", nullptr, $PRIVATE, $field(MessageFormat, offsets)},
	{"argumentNumbers", "[I", nullptr, $PRIVATE, $field(MessageFormat, argumentNumbers)},
	{"maxOffset", "I", nullptr, $PRIVATE, $field(MessageFormat, maxOffset)},
	{"SEG_RAW", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MessageFormat, SEG_RAW)},
	{"SEG_INDEX", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MessageFormat, SEG_INDEX)},
	{"SEG_TYPE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MessageFormat, SEG_TYPE)},
	{"SEG_MODIFIER", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MessageFormat, SEG_MODIFIER)},
	{"TYPE_NULL", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MessageFormat, TYPE_NULL)},
	{"TYPE_NUMBER", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MessageFormat, TYPE_NUMBER)},
	{"TYPE_DATE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MessageFormat, TYPE_DATE)},
	{"TYPE_TIME", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MessageFormat, TYPE_TIME)},
	{"TYPE_CHOICE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MessageFormat, TYPE_CHOICE)},
	{"TYPE_KEYWORDS", "[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(MessageFormat, TYPE_KEYWORDS)},
	{"MODIFIER_DEFAULT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MessageFormat, MODIFIER_DEFAULT)},
	{"MODIFIER_CURRENCY", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MessageFormat, MODIFIER_CURRENCY)},
	{"MODIFIER_PERCENT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MessageFormat, MODIFIER_PERCENT)},
	{"MODIFIER_INTEGER", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MessageFormat, MODIFIER_INTEGER)},
	{"NUMBER_MODIFIER_KEYWORDS", "[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(MessageFormat, NUMBER_MODIFIER_KEYWORDS)},
	{"MODIFIER_SHORT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MessageFormat, MODIFIER_SHORT)},
	{"MODIFIER_MEDIUM", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MessageFormat, MODIFIER_MEDIUM)},
	{"MODIFIER_LONG", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MessageFormat, MODIFIER_LONG)},
	{"MODIFIER_FULL", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MessageFormat, MODIFIER_FULL)},
	{"DATE_TIME_MODIFIER_KEYWORDS", "[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(MessageFormat, DATE_TIME_MODIFIER_KEYWORDS)},
	{"DATE_TIME_MODIFIERS", "[I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(MessageFormat, DATE_TIME_MODIFIERS)},
	{}
};

$MethodInfo _MessageFormat_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(MessageFormat, init$, void, $String*)},
	{"<init>", "(Ljava/lang/String;Ljava/util/Locale;)V", nullptr, $PUBLIC, $method(MessageFormat, init$, void, $String*, $Locale*)},
	{"append", "(Ljava/lang/StringBuffer;Ljava/text/CharacterIterator;)V", nullptr, $PRIVATE, $method(MessageFormat, append, void, $StringBuffer*, $CharacterIterator*)},
	{"applyPattern", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(MessageFormat, applyPattern, void, $String*)},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(MessageFormat, clone, $Object*)},
	{"copyAndFixQuotes", "(Ljava/lang/String;IILjava/lang/StringBuilder;)V", nullptr, $PRIVATE | $STATIC | $FINAL, $staticMethod(MessageFormat, copyAndFixQuotes, void, $String*, int32_t, int32_t, $StringBuilder*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(MessageFormat, equals, bool, Object$*)},
	{"findKeyword", "(Ljava/lang/String;[Ljava/lang/String;)I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticMethod(MessageFormat, findKeyword, int32_t, $String*, $StringArray*)},
	{"format", "([Ljava/lang/Object;Ljava/lang/StringBuffer;Ljava/text/FieldPosition;)Ljava/lang/StringBuffer;", nullptr, $PUBLIC | $FINAL, $method(MessageFormat, format, $StringBuffer*, $ObjectArray*, $StringBuffer*, $FieldPosition*)},
	{"format", "(Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(MessageFormat, format, $String*, $String*, $ObjectArray*)},
	{"format", "(Ljava/lang/Object;Ljava/lang/StringBuffer;Ljava/text/FieldPosition;)Ljava/lang/StringBuffer;", nullptr, $PUBLIC | $FINAL, $virtualMethod(MessageFormat, format, $StringBuffer*, Object$*, $StringBuffer*, $FieldPosition*)},
	{"formatToCharacterIterator", "(Ljava/lang/Object;)Ljava/text/AttributedCharacterIterator;", nullptr, $PUBLIC, $virtualMethod(MessageFormat, formatToCharacterIterator, $AttributedCharacterIterator*, Object$*)},
	{"getFormats", "()[Ljava/text/Format;", nullptr, $PUBLIC, $virtualMethod(MessageFormat, getFormats, $FormatArray*)},
	{"getFormatsByArgumentIndex", "()[Ljava/text/Format;", nullptr, $PUBLIC, $virtualMethod(MessageFormat, getFormatsByArgumentIndex, $FormatArray*)},
	{"getLocale", "()Ljava/util/Locale;", nullptr, $PUBLIC, $virtualMethod(MessageFormat, getLocale, $Locale*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(MessageFormat, hashCode, int32_t)},
	{"makeFormat", "(II[Ljava/lang/StringBuilder;)V", nullptr, $PRIVATE, $method(MessageFormat, makeFormat, void, int32_t, int32_t, $StringBuilderArray*)},
	{"parse", "(Ljava/lang/String;Ljava/text/ParsePosition;)[Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(MessageFormat, parse, $ObjectArray*, $String*, $ParsePosition*)},
	{"parse", "(Ljava/lang/String;)[Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(MessageFormat, parse, $ObjectArray*, $String*), "java.text.ParseException"},
	{"parseObject", "(Ljava/lang/String;Ljava/text/ParsePosition;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(MessageFormat, parseObject, $Object*, $String*, $ParsePosition*)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(MessageFormat, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"setFormat", "(ILjava/text/Format;)V", nullptr, $PUBLIC, $virtualMethod(MessageFormat, setFormat, void, int32_t, $Format*)},
	{"setFormatByArgumentIndex", "(ILjava/text/Format;)V", nullptr, $PUBLIC, $virtualMethod(MessageFormat, setFormatByArgumentIndex, void, int32_t, $Format*)},
	{"setFormats", "([Ljava/text/Format;)V", nullptr, $PUBLIC, $virtualMethod(MessageFormat, setFormats, void, $FormatArray*)},
	{"setFormatsByArgumentIndex", "([Ljava/text/Format;)V", nullptr, $PUBLIC, $virtualMethod(MessageFormat, setFormatsByArgumentIndex, void, $FormatArray*)},
	{"setLocale", "(Ljava/util/Locale;)V", nullptr, $PUBLIC, $virtualMethod(MessageFormat, setLocale, void, $Locale*)},
	{"subformat", "([Ljava/lang/Object;Ljava/lang/StringBuffer;Ljava/text/FieldPosition;Ljava/util/List;)Ljava/lang/StringBuffer;", "([Ljava/lang/Object;Ljava/lang/StringBuffer;Ljava/text/FieldPosition;Ljava/util/List<Ljava/text/AttributedCharacterIterator;>;)Ljava/lang/StringBuffer;", $PRIVATE, $method(MessageFormat, subformat, $StringBuffer*, $ObjectArray*, $StringBuffer*, $FieldPosition*, $List*)},
	{"toPattern", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(MessageFormat, toPattern, $String*)},
	{}
};

$InnerClassInfo _MessageFormat_InnerClassesInfo_[] = {
	{"java.text.MessageFormat$Field", "java.text.MessageFormat", "Field", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _MessageFormat_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.text.MessageFormat",
	"java.text.Format",
	nullptr,
	_MessageFormat_FieldInfo_,
	_MessageFormat_MethodInfo_,
	nullptr,
	nullptr,
	_MessageFormat_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.text.MessageFormat$Field"
};

$Object* allocate$MessageFormat($Class* clazz) {
	return $of($alloc(MessageFormat));
}

$StringArray* MessageFormat::TYPE_KEYWORDS = nullptr;
$StringArray* MessageFormat::NUMBER_MODIFIER_KEYWORDS = nullptr;
$StringArray* MessageFormat::DATE_TIME_MODIFIER_KEYWORDS = nullptr;
$ints* MessageFormat::DATE_TIME_MODIFIERS = nullptr;

void MessageFormat::init$($String* pattern) {
	$Format::init$();
	$set(this, pattern, ""_s);
	$set(this, formats, $new($FormatArray, MessageFormat::INITIAL_FORMATS));
	$set(this, offsets, $new($ints, MessageFormat::INITIAL_FORMATS));
	$set(this, argumentNumbers, $new($ints, MessageFormat::INITIAL_FORMATS));
	this->maxOffset = -1;
	$init($Locale$Category);
	$set(this, locale, $Locale::getDefault($Locale$Category::FORMAT));
	applyPattern(pattern);
}

void MessageFormat::init$($String* pattern, $Locale* locale) {
	$Format::init$();
	$set(this, pattern, ""_s);
	$set(this, formats, $new($FormatArray, MessageFormat::INITIAL_FORMATS));
	$set(this, offsets, $new($ints, MessageFormat::INITIAL_FORMATS));
	$set(this, argumentNumbers, $new($ints, MessageFormat::INITIAL_FORMATS));
	this->maxOffset = -1;
	$set(this, locale, locale);
	applyPattern(pattern);
}

void MessageFormat::setLocale($Locale* locale) {
	$set(this, locale, locale);
}

$Locale* MessageFormat::getLocale() {
	return this->locale;
}

void MessageFormat::applyPattern($String* pattern) {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilderArray, segments, $new($StringBuilderArray, 4));
	segments->set(MessageFormat::SEG_RAW, $$new($StringBuilder));
	int32_t part = MessageFormat::SEG_RAW;
	int32_t formatNumber = 0;
	bool inQuote = false;
	int32_t braceStack = 0;
	this->maxOffset = -1;
	for (int32_t i = 0; i < $nc(pattern)->length(); ++i) {
		char16_t ch = pattern->charAt(i);
		if (part == MessageFormat::SEG_RAW) {
			if (ch == u'\'') {
				bool var$0 = i + 1 < pattern->length();
				if (var$0 && pattern->charAt(i + 1) == u'\'') {
					$nc(segments->get(part))->append(ch);
					++i;
				} else {
					inQuote = !inQuote;
				}
			} else if (ch == u'{' && !inQuote) {
				part = MessageFormat::SEG_INDEX;
				if (segments->get(MessageFormat::SEG_INDEX) == nullptr) {
					segments->set(MessageFormat::SEG_INDEX, $$new($StringBuilder));
				}
			} else {
				$nc(segments->get(part))->append(ch);
			}
		} else if (inQuote) {
			$nc(segments->get(part))->append(ch);
			if (ch == u'\'') {
				inQuote = false;
			}
		} else {
			switch (ch) {
			case u',':
				{
					if (part < MessageFormat::SEG_MODIFIER) {
						if (segments->get(++part) == nullptr) {
							segments->set(part, $$new($StringBuilder));
						}
					} else {
						$nc(segments->get(part))->append(ch);
					}
					break;
				}
			case u'{':
				{
					++braceStack;
					$nc(segments->get(part))->append(ch);
					break;
				}
			case u'}':
				{
					if (braceStack == 0) {
						part = MessageFormat::SEG_RAW;
						makeFormat(i, formatNumber, segments);
						++formatNumber;
						segments->set(MessageFormat::SEG_INDEX, nullptr);
						segments->set(MessageFormat::SEG_TYPE, nullptr);
						segments->set(MessageFormat::SEG_MODIFIER, nullptr);
					} else {
						--braceStack;
						$nc(segments->get(part))->append(ch);
					}
					break;
				}
			case u' ':
				{
					if (part != MessageFormat::SEG_TYPE || $nc(segments->get(MessageFormat::SEG_TYPE))->length() > 0) {
						$nc(segments->get(part))->append(ch);
					}
					break;
				}
			case u'\'':
				{
					inQuote = true;
				}
			default:
				{
					$nc(segments->get(part))->append(ch);
					break;
				}
			}
		}
	}
	if (braceStack == 0 && part != 0) {
		this->maxOffset = -1;
		$throwNew($IllegalArgumentException, "Unmatched braces in the pattern."_s);
	}
	$set(this, pattern, $nc(segments->get(0))->toString());
}

$String* MessageFormat::toPattern() {
	$useLocalCurrentObjectStackCache();
	int32_t lastOffset = 0;
	$var($StringBuilder, result, $new($StringBuilder));
	for (int32_t i = 0; i <= this->maxOffset; ++i) {
		copyAndFixQuotes(this->pattern, lastOffset, $nc(this->offsets)->get(i), result);
		lastOffset = $nc(this->offsets)->get(i);
		result->append(u'{')->append($nc(this->argumentNumbers)->get(i));
		$var($Format, fmt, $nc(this->formats)->get(i));
		if (fmt == nullptr) {
		} else if ($instanceOf($NumberFormat, fmt)) {
			if ($nc($of(fmt))->equals($($NumberFormat::getInstance(this->locale)))) {
				result->append(",number"_s);
			} else if ($of(fmt)->equals($($NumberFormat::getCurrencyInstance(this->locale)))) {
				result->append(",number,currency"_s);
			} else if ($of(fmt)->equals($($NumberFormat::getPercentInstance(this->locale)))) {
				result->append(",number,percent"_s);
			} else if ($of(fmt)->equals($($NumberFormat::getIntegerInstance(this->locale)))) {
				result->append(",number,integer"_s);
			} else if ($instanceOf($DecimalFormat, fmt)) {
				result->append(",number,"_s)->append($($nc(($cast($DecimalFormat, fmt)))->toPattern()));
			} else if ($instanceOf($ChoiceFormat, fmt)) {
				result->append(",choice,"_s)->append($($nc(($cast($ChoiceFormat, fmt)))->toPattern()));
			} else {
			}
		} else if ($instanceOf($DateFormat, fmt)) {
			int32_t index = 0;
			for (index = MessageFormat::MODIFIER_DEFAULT; index < $nc(MessageFormat::DATE_TIME_MODIFIERS)->length; ++index) {
				$var($DateFormat, df, $DateFormat::getDateInstance($nc(MessageFormat::DATE_TIME_MODIFIERS)->get(index), this->locale));
				if ($nc($of(fmt))->equals(df)) {
					result->append(",date"_s);
					break;
				}
				$assign(df, $DateFormat::getTimeInstance($nc(MessageFormat::DATE_TIME_MODIFIERS)->get(index), this->locale));
				if ($nc($of(fmt))->equals(df)) {
					result->append(",time"_s);
					break;
				}
			}
			if (index >= $nc(MessageFormat::DATE_TIME_MODIFIERS)->length) {
				if ($instanceOf($SimpleDateFormat, fmt)) {
					result->append(",date,"_s)->append($($nc(($cast($SimpleDateFormat, fmt)))->toPattern()));
				} else {
				}
			} else if (index != MessageFormat::MODIFIER_DEFAULT) {
				result->append(u',')->append($nc(MessageFormat::DATE_TIME_MODIFIER_KEYWORDS)->get(index));
			}
		} else {
		}
		result->append(u'}');
	}
	copyAndFixQuotes(this->pattern, lastOffset, $nc(this->pattern)->length(), result);
	return result->toString();
}

void MessageFormat::setFormatsByArgumentIndex($FormatArray* newFormats) {
	for (int32_t i = 0; i <= this->maxOffset; ++i) {
		int32_t j = $nc(this->argumentNumbers)->get(i);
		if (j < $nc(newFormats)->length) {
			$nc(this->formats)->set(i, newFormats->get(j));
		}
	}
}

void MessageFormat::setFormats($FormatArray* newFormats) {
	int32_t runsToCopy = $nc(newFormats)->length;
	if (runsToCopy > this->maxOffset + 1) {
		runsToCopy = this->maxOffset + 1;
	}
	for (int32_t i = 0; i < runsToCopy; ++i) {
		$nc(this->formats)->set(i, newFormats->get(i));
	}
}

void MessageFormat::setFormatByArgumentIndex(int32_t argumentIndex, $Format* newFormat) {
	for (int32_t j = 0; j <= this->maxOffset; ++j) {
		if ($nc(this->argumentNumbers)->get(j) == argumentIndex) {
			$nc(this->formats)->set(j, newFormat);
		}
	}
}

void MessageFormat::setFormat(int32_t formatElementIndex, $Format* newFormat) {
	if (formatElementIndex > this->maxOffset) {
		$throwNew($ArrayIndexOutOfBoundsException, formatElementIndex);
	}
	$nc(this->formats)->set(formatElementIndex, newFormat);
}

$FormatArray* MessageFormat::getFormatsByArgumentIndex() {
	int32_t maximumArgumentNumber = -1;
	for (int32_t i = 0; i <= this->maxOffset; ++i) {
		if ($nc(this->argumentNumbers)->get(i) > maximumArgumentNumber) {
			maximumArgumentNumber = $nc(this->argumentNumbers)->get(i);
		}
	}
	$var($FormatArray, resultArray, $new($FormatArray, maximumArgumentNumber + 1));
	for (int32_t i = 0; i <= this->maxOffset; ++i) {
		resultArray->set($nc(this->argumentNumbers)->get(i), $nc(this->formats)->get(i));
	}
	return resultArray;
}

$FormatArray* MessageFormat::getFormats() {
	$var($FormatArray, resultArray, $new($FormatArray, this->maxOffset + 1));
	$System::arraycopy(this->formats, 0, resultArray, 0, this->maxOffset + 1);
	return resultArray;
}

$StringBuffer* MessageFormat::format($ObjectArray* arguments, $StringBuffer* result, $FieldPosition* pos) {
	return subformat(arguments, result, pos, nullptr);
}

$String* MessageFormat::format($String* pattern, $ObjectArray* arguments) {
	$init(MessageFormat);
	$var(MessageFormat, temp, $new(MessageFormat, pattern));
	return temp->format(arguments);
}

$StringBuffer* MessageFormat::format(Object$* arguments, $StringBuffer* result, $FieldPosition* pos) {
	return subformat($cast($ObjectArray, arguments), result, pos, nullptr);
}

$AttributedCharacterIterator* MessageFormat::formatToCharacterIterator(Object$* arguments) {
	$useLocalCurrentObjectStackCache();
	$var($StringBuffer, result, $new($StringBuffer));
	$var($ArrayList, iterators, $new($ArrayList));
	if (arguments == nullptr) {
		$throwNew($NullPointerException, "formatToCharacterIterator must be passed non-null object"_s);
	}
	subformat($cast($ObjectArray, arguments), result, nullptr, iterators);
	if (iterators->size() == 0) {
		return createAttributedCharacterIterator(""_s);
	}
	return createAttributedCharacterIterator($fcast($AttributedCharacterIteratorArray, $(iterators->toArray($$new($AttributedCharacterIteratorArray, iterators->size())))));
}

$ObjectArray* MessageFormat::parse($String* source, $ParsePosition* pos) {
	$useLocalCurrentObjectStackCache();
	if (source == nullptr) {
		$var($ObjectArray, empty, $new($ObjectArray, 0));
		return empty;
	}
	int32_t maximumArgumentNumber = -1;
	for (int32_t i = 0; i <= this->maxOffset; ++i) {
		if ($nc(this->argumentNumbers)->get(i) > maximumArgumentNumber) {
			maximumArgumentNumber = $nc(this->argumentNumbers)->get(i);
		}
	}
	$var($ObjectArray, resultArray, $new($ObjectArray, maximumArgumentNumber + 1));
	int32_t patternOffset = 0;
	int32_t sourceOffset = $nc(pos)->index;
	$var($ParsePosition, tempStatus, $new($ParsePosition, 0));
	for (int32_t i = 0; i <= this->maxOffset; ++i) {
		int32_t len = $nc(this->offsets)->get(i) - patternOffset;
		if (len == 0 || $nc(this->pattern)->regionMatches(patternOffset, source, sourceOffset, len)) {
			sourceOffset += len;
			patternOffset += len;
		} else {
			pos->errorIndex = sourceOffset;
			return nullptr;
		}
		if ($nc(this->formats)->get(i) == nullptr) {
			int32_t tempLength = (i != this->maxOffset) ? $nc(this->offsets)->get(i + 1) : $nc(this->pattern)->length();
			int32_t next = 0;
			if (patternOffset >= tempLength) {
				next = $nc(source)->length();
			} else {
				next = $nc(source)->indexOf($($nc(this->pattern)->substring(patternOffset, tempLength)), sourceOffset);
			}
			if (next < 0) {
				pos->errorIndex = sourceOffset;
				return nullptr;
			} else {
				$var($String, strValue, $nc(source)->substring(sourceOffset, next));
				if (!strValue->equals($$str({"{"_s, $$str($nc(this->argumentNumbers)->get(i)), "}"_s}))) {
					resultArray->set($nc(this->argumentNumbers)->get(i), $(source->substring(sourceOffset, next)));
				}
				sourceOffset = next;
			}
		} else {
			tempStatus->index = sourceOffset;
			resultArray->set($nc(this->argumentNumbers)->get(i), $($nc($nc(this->formats)->get(i))->parseObject(source, tempStatus)));
			if (tempStatus->index == sourceOffset) {
				pos->errorIndex = sourceOffset;
				return nullptr;
			}
			sourceOffset = tempStatus->index;
		}
	}
	int32_t len = $nc(this->pattern)->length() - patternOffset;
	if (len == 0 || $nc(this->pattern)->regionMatches(patternOffset, source, sourceOffset, len)) {
		pos->index = sourceOffset + len;
	} else {
		pos->errorIndex = sourceOffset;
		return nullptr;
	}
	return resultArray;
}

$ObjectArray* MessageFormat::parse($String* source) {
	$useLocalCurrentObjectStackCache();
	$var($ParsePosition, pos, $new($ParsePosition, 0));
	$var($ObjectArray, result, parse(source, pos));
	if (pos->index == 0) {
		$throwNew($ParseException, "MessageFormat parse error!"_s, pos->errorIndex);
	}
	return result;
}

$Object* MessageFormat::parseObject($String* source, $ParsePosition* pos) {
	return $of(parse(source, pos));
}

$Object* MessageFormat::clone() {
	$useLocalCurrentObjectStackCache();
	$var(MessageFormat, other, $cast(MessageFormat, $Format::clone()));
	$set($nc(other), formats, $cast($FormatArray, $nc(this->formats)->clone()));
	for (int32_t i = 0; i < $nc(this->formats)->length; ++i) {
		if ($nc(this->formats)->get(i) != nullptr) {
			$nc(other->formats)->set(i, $cast($Format, $($nc($nc(this->formats)->get(i))->clone())));
		}
	}
	$set(other, offsets, $cast($ints, $nc(this->offsets)->clone()));
	$set(other, argumentNumbers, $cast($ints, $nc(this->argumentNumbers)->clone()));
	return $of(other);
}

bool MessageFormat::equals(Object$* obj) {
	if ($equals(this, obj)) {
		return true;
	}
	bool var$0 = obj == nullptr;
	if (!var$0) {
		var$0 = $of(this)->getClass() != $nc($of(obj))->getClass();
	}
	if (var$0) {
		return false;
	}
	$var(MessageFormat, other, $cast(MessageFormat, obj));
	bool var$4 = this->maxOffset == $nc(other)->maxOffset && $nc(this->pattern)->equals(other->pattern);
	bool var$3 = var$4 && ((this->locale != nullptr && $nc(this->locale)->equals(other->locale)) || (this->locale == nullptr && $nc(other)->locale == nullptr));
	bool var$2 = var$3 && $Arrays::equals(this->offsets, other->offsets);
	bool var$1 = var$2 && $Arrays::equals(this->argumentNumbers, other->argumentNumbers);
	return (var$1 && $Arrays::equals(this->formats, other->formats));
}

int32_t MessageFormat::hashCode() {
	return $nc(this->pattern)->hashCode();
}

$StringBuffer* MessageFormat::subformat($ObjectArray* arguments, $StringBuffer* result, $FieldPosition* fp, $List* characterIterators) {
	$useLocalCurrentObjectStackCache();
	int32_t lastOffset = 0;
	int32_t last = $nc(result)->length();
	for (int32_t i = 0; i <= this->maxOffset; ++i) {
		result->append(static_cast<$CharSequence*>(this->pattern), lastOffset, $nc(this->offsets)->get(i));
		lastOffset = $nc(this->offsets)->get(i);
		int32_t argumentNumber = $nc(this->argumentNumbers)->get(i);
		if (arguments == nullptr || argumentNumber >= $nc(arguments)->length) {
			result->append(u'{')->append(argumentNumber)->append(u'}');
			continue;
		}
		{
			$var($Object, obj, $nc(arguments)->get(argumentNumber));
			$var($String, arg, nullptr);
			$var($Format, subFormatter, nullptr);
			if (obj == nullptr) {
				$assign(arg, "null"_s);
			} else if ($nc(this->formats)->get(i) != nullptr) {
				$assign(subFormatter, $nc(this->formats)->get(i));
				if ($instanceOf($ChoiceFormat, subFormatter)) {
					$assign(arg, $nc($nc(this->formats)->get(i))->format(obj));
					if ($nc(arg)->indexOf((int32_t)u'{') >= 0) {
						$assign(subFormatter, $new(MessageFormat, arg, this->locale));
						$assign(obj, arguments);
						$assign(arg, nullptr);
					}
				}
			} else if ($instanceOf($Number, obj)) {
				$assign(subFormatter, $NumberFormat::getInstance(this->locale));
			} else if ($instanceOf($Date, obj)) {
				$assign(subFormatter, $DateFormat::getDateTimeInstance($DateFormat::SHORT, $DateFormat::SHORT, this->locale));
			} else if ($instanceOf($String, obj)) {
				$assign(arg, $cast($String, obj));
			} else {
				$assign(arg, $nc($of(obj))->toString());
				if (arg == nullptr) {
					$assign(arg, "null"_s);
				}
			}
			if (characterIterators != nullptr) {
				if (last != result->length()) {
					characterIterators->add($(createAttributedCharacterIterator($(result->substring(last)))));
					last = result->length();
				}
				if (subFormatter != nullptr) {
					$var($AttributedCharacterIterator, subIterator, subFormatter->formatToCharacterIterator(obj));
					append(result, subIterator);
					if (last != result->length()) {
						$init($MessageFormat$Field);
						characterIterators->add($(createAttributedCharacterIterator(subIterator, static_cast<$AttributedCharacterIterator$Attribute*>($MessageFormat$Field::ARGUMENT), $($of($Integer::valueOf(argumentNumber))))));
						last = result->length();
					}
					$assign(arg, nullptr);
				}
				if (arg != nullptr && !arg->isEmpty()) {
					result->append(arg);
					$init($MessageFormat$Field);
					characterIterators->add($(createAttributedCharacterIterator(arg, static_cast<$AttributedCharacterIterator$Attribute*>($MessageFormat$Field::ARGUMENT), $($of($Integer::valueOf(argumentNumber))))));
					last = result->length();
				}
			} else {
				if (subFormatter != nullptr) {
					$assign(arg, subFormatter->format(obj));
				}
				last = result->length();
				result->append(arg);
				$init($MessageFormat$Field);
				if (i == 0 && fp != nullptr && $nc($MessageFormat$Field::ARGUMENT)->equals($(fp->getFieldAttribute()))) {
					fp->setBeginIndex(last);
					fp->setEndIndex(result->length());
				}
				last = result->length();
			}
		}
	}
	result->append(static_cast<$CharSequence*>(this->pattern), lastOffset, $nc(this->pattern)->length());
	if (characterIterators != nullptr && last != result->length()) {
		characterIterators->add($(createAttributedCharacterIterator($(result->substring(last)))));
	}
	return result;
}

void MessageFormat::append($StringBuffer* result, $CharacterIterator* iterator) {
	if ($nc(iterator)->first() != $CharacterIterator::DONE) {
		char16_t aChar = 0;
		$nc(result)->append(iterator->first());
		while ((aChar = iterator->next()) != $CharacterIterator::DONE) {
			result->append(aChar);
		}
	}
}

void MessageFormat::makeFormat(int32_t position, int32_t offsetNumber, $StringBuilderArray* textSegments) {
	$useLocalCurrentObjectStackCache();
	$var($StringArray, segments, $new($StringArray, $nc(textSegments)->length));
	for (int32_t i = 0; i < textSegments->length; ++i) {
		$var($StringBuilder, oneseg, textSegments->get(i));
		segments->set(i, (oneseg != nullptr) ? $($nc(oneseg)->toString()) : ""_s);
	}
	int32_t argumentNumber = 0;
	try {
		argumentNumber = $Integer::parseInt(segments->get(MessageFormat::SEG_INDEX));
	} catch ($NumberFormatException& e) {
		$throwNew($IllegalArgumentException, $$str({"can\'t parse argument number: "_s, segments->get(MessageFormat::SEG_INDEX)}), e);
	}
	if (argumentNumber < 0) {
		$throwNew($IllegalArgumentException, $$str({"negative argument number: "_s, $$str(argumentNumber)}));
	}
	if (offsetNumber >= $nc(this->formats)->length) {
		int32_t newLength = $nc(this->formats)->length * 2;
		$var($FormatArray, newFormats, $new($FormatArray, newLength));
		$var($ints, newOffsets, $new($ints, newLength));
		$var($ints, newArgumentNumbers, $new($ints, newLength));
		$System::arraycopy(this->formats, 0, newFormats, 0, this->maxOffset + 1);
		$System::arraycopy(this->offsets, 0, newOffsets, 0, this->maxOffset + 1);
		$System::arraycopy(this->argumentNumbers, 0, newArgumentNumbers, 0, this->maxOffset + 1);
		$set(this, formats, newFormats);
		$set(this, offsets, newOffsets);
		$set(this, argumentNumbers, newArgumentNumbers);
	}
	int32_t oldMaxOffset = this->maxOffset;
	this->maxOffset = offsetNumber;
	$nc(this->offsets)->set(offsetNumber, $nc(segments->get(MessageFormat::SEG_RAW))->length());
	$nc(this->argumentNumbers)->set(offsetNumber, argumentNumber);
	$var($Format, newFormat, nullptr);
	if (!$nc(segments->get(MessageFormat::SEG_TYPE))->isEmpty()) {
		int32_t type = findKeyword(segments->get(MessageFormat::SEG_TYPE), MessageFormat::TYPE_KEYWORDS);
		{
			int32_t mod = 0;
			switch (type) {
			case MessageFormat::TYPE_NULL:
				{
					break;
				}
			case MessageFormat::TYPE_NUMBER:
				{
					switch (findKeyword(segments->get(MessageFormat::SEG_MODIFIER), MessageFormat::NUMBER_MODIFIER_KEYWORDS)) {
					case MessageFormat::MODIFIER_DEFAULT:
						{
							$assign(newFormat, $NumberFormat::getInstance(this->locale));
							break;
						}
					case MessageFormat::MODIFIER_CURRENCY:
						{
							$assign(newFormat, $NumberFormat::getCurrencyInstance(this->locale));
							break;
						}
					case MessageFormat::MODIFIER_PERCENT:
						{
							$assign(newFormat, $NumberFormat::getPercentInstance(this->locale));
							break;
						}
					case MessageFormat::MODIFIER_INTEGER:
						{
							$assign(newFormat, $NumberFormat::getIntegerInstance(this->locale));
							break;
						}
					default:
						{
							try {
								$assign(newFormat, $new($DecimalFormat, segments->get(MessageFormat::SEG_MODIFIER), $($DecimalFormatSymbols::getInstance(this->locale))));
							} catch ($IllegalArgumentException& e) {
								this->maxOffset = oldMaxOffset;
								$throw(e);
							}
							break;
						}
					}
					break;
				}
			case MessageFormat::TYPE_DATE:
				{}
			case MessageFormat::TYPE_TIME:
				{
					mod = findKeyword(segments->get(MessageFormat::SEG_MODIFIER), MessageFormat::DATE_TIME_MODIFIER_KEYWORDS);
					if (mod >= 0 && mod < $nc(MessageFormat::DATE_TIME_MODIFIER_KEYWORDS)->length) {
						if (type == MessageFormat::TYPE_DATE) {
							$assign(newFormat, $DateFormat::getDateInstance($nc(MessageFormat::DATE_TIME_MODIFIERS)->get(mod), this->locale));
						} else {
							$assign(newFormat, $DateFormat::getTimeInstance($nc(MessageFormat::DATE_TIME_MODIFIERS)->get(mod), this->locale));
						}
					} else {
						try {
							$assign(newFormat, $new($SimpleDateFormat, segments->get(MessageFormat::SEG_MODIFIER), this->locale));
						} catch ($IllegalArgumentException& e) {
							this->maxOffset = oldMaxOffset;
							$throw(e);
						}
					}
					break;
				}
			case MessageFormat::TYPE_CHOICE:
				{
					try {
						$assign(newFormat, $new($ChoiceFormat, segments->get(MessageFormat::SEG_MODIFIER)));
					} catch ($Exception& e) {
						this->maxOffset = oldMaxOffset;
						$throwNew($IllegalArgumentException, $$str({"Choice Pattern incorrect: "_s, segments->get(MessageFormat::SEG_MODIFIER)}), e);
					}
					break;
				}
			default:
				{
					this->maxOffset = oldMaxOffset;
					$throwNew($IllegalArgumentException, $$str({"unknown format type: "_s, segments->get(MessageFormat::SEG_TYPE)}));
				}
			}
		}
	}
	$nc(this->formats)->set(offsetNumber, newFormat);
}

int32_t MessageFormat::findKeyword($String* s, $StringArray* list) {
	$init(MessageFormat);
	$useLocalCurrentObjectStackCache();
	for (int32_t i = 0; i < $nc(list)->length; ++i) {
		if ($nc(s)->equals(list->get(i))) {
			return i;
		}
	}
	$init($Locale);
	$var($String, ls, $($nc(s)->trim())->toLowerCase($Locale::ROOT));
	if (ls != s) {
		for (int32_t i = 0; i < $nc(list)->length; ++i) {
			if (ls->equals(list->get(i))) {
				return i;
			}
		}
	}
	return -1;
}

void MessageFormat::copyAndFixQuotes($String* source, int32_t start, int32_t end, $StringBuilder* target) {
	$init(MessageFormat);
	bool quoted = false;
	for (int32_t i = start; i < end; ++i) {
		char16_t ch = $nc(source)->charAt(i);
		if (ch == u'{') {
			if (!quoted) {
				$nc(target)->append(u'\'');
				quoted = true;
			}
			$nc(target)->append(ch);
		} else if (ch == u'\'') {
			$nc(target)->append("\'\'"_s);
		} else {
			if (quoted) {
				$nc(target)->append(u'\'');
				quoted = false;
			}
			$nc(target)->append(ch);
		}
	}
	if (quoted) {
		$nc(target)->append(u'\'');
	}
}

void MessageFormat::readObject($ObjectInputStream* in) {
	$nc(in)->defaultReadObject();
	bool isValid = this->maxOffset >= -1 && $nc(this->formats)->length > this->maxOffset && $nc(this->offsets)->length > this->maxOffset && $nc(this->argumentNumbers)->length > this->maxOffset;
	if (isValid) {
		int32_t lastOffset = $nc(this->pattern)->length() + 1;
		for (int32_t i = this->maxOffset; i >= 0; --i) {
			if (($nc(this->offsets)->get(i) < 0) || ($nc(this->offsets)->get(i) > lastOffset)) {
				isValid = false;
				break;
			} else {
				lastOffset = $nc(this->offsets)->get(i);
			}
		}
	}
	if (!isValid) {
		$throwNew($InvalidObjectException, "Could not reconstruct MessageFormat from corrupt stream."_s);
	}
}

void clinit$MessageFormat($Class* class$) {
	$assignStatic(MessageFormat::TYPE_KEYWORDS, $new($StringArray, {
		""_s,
		"number"_s,
		"date"_s,
		"time"_s,
		"choice"_s
	}));
	$assignStatic(MessageFormat::NUMBER_MODIFIER_KEYWORDS, $new($StringArray, {
		""_s,
		"currency"_s,
		"percent"_s,
		"integer"_s
	}));
	$assignStatic(MessageFormat::DATE_TIME_MODIFIER_KEYWORDS, $new($StringArray, {
		""_s,
		"short"_s,
		"medium"_s,
		"long"_s,
		"full"_s
	}));
	$assignStatic(MessageFormat::DATE_TIME_MODIFIERS, $new($ints, {
		$DateFormat::DEFAULT,
		$DateFormat::SHORT,
		$DateFormat::MEDIUM,
		$DateFormat::LONG,
		$DateFormat::FULL
	}));
}

MessageFormat::MessageFormat() {
}

$Class* MessageFormat::load$($String* name, bool initialize) {
	$loadClass(MessageFormat, name, initialize, &_MessageFormat_ClassInfo_, clinit$MessageFormat, allocate$MessageFormat);
	return class$;
}

$Class* MessageFormat::class$ = nullptr;

	} // text
} // java