#include <java/text/SimpleDateFormat.h>

#include <java/io/InvalidObjectException.h>
#include <java/io/ObjectInputStream.h>
#include <java/lang/AssertionError.h>
#include <java/lang/CharSequence.h>
#include <java/lang/IndexOutOfBoundsException.h>
#include <java/lang/Number.h>
#include <java/lang/StringBuffer.h>
#include <java/text/AttributedCharacterIterator.h>
#include <java/text/CalendarBuilder.h>
#include <java/text/CharacterIteratorFieldDelegate.h>
#include <java/text/DateFormat$Field.h>
#include <java/text/DateFormat.h>
#include <java/text/DateFormatSymbols.h>
#include <java/text/DecimalFormat.h>
#include <java/text/DecimalFormatSymbols.h>
#include <java/text/DontCareFieldPosition.h>
#include <java/text/FieldPosition.h>
#include <java/text/Format$Field.h>
#include <java/text/Format$FieldDelegate.h>
#include <java/text/NumberFormat.h>
#include <java/text/ParsePosition.h>
#include <java/util/Calendar.h>
#include <java/util/Date.h>
#include <java/util/GregorianCalendar.h>
#include <java/util/Iterator.h>
#include <java/util/Locale$Category.h>
#include <java/util/Locale.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/SimpleTimeZone.h>
#include <java/util/SortedMap.h>
#include <java/util/TimeZone.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/concurrent/ConcurrentMap.h>
#include <sun/util/calendar/CalendarUtils.h>
#include <sun/util/calendar/ZoneInfoFile.h>
#include <sun/util/locale/provider/LocaleProviderAdapter.h>
#include <sun/util/locale/provider/LocaleResources.h>
#include <sun/util/locale/provider/TimeZoneNameUtility.h>
#include <jcpp.h>

#undef AM_PM
#undef AM_PM_FIELD
#undef DATE
#undef DATE_FIELD
#undef DAY_OF_MONTH
#undef DAY_OF_WEEK
#undef DAY_OF_WEEK_FIELD
#undef DAY_OF_WEEK_IN_MONTH
#undef DAY_OF_WEEK_IN_MONTH_FIELD
#undef DAY_OF_YEAR
#undef DAY_OF_YEAR_FIELD
#undef DST_OFFSET
#undef ERA
#undef ERA_FIELD
#undef FORMAT
#undef GMT
#undef HOUR
#undef HOUR0
#undef HOUR0_FIELD
#undef HOUR1
#undef HOUR1_FIELD
#undef HOUR_OF_DAY
#undef HOUR_OF_DAY0
#undef HOUR_OF_DAY0_FIELD
#undef HOUR_OF_DAY1
#undef HOUR_OF_DAY1_FIELD
#undef INSTANCE
#undef ISO_DAY_OF_WEEK
#undef LONG
#undef LONG_FORMAT
#undef LONG_STANDALONE
#undef MAX_VALUE
#undef MILLISECOND
#undef MILLISECOND_FIELD
#undef MILLIS_PER_MINUTE
#undef MINUTE
#undef MINUTE_FIELD
#undef MONTH
#undef MONTH_FIELD
#undef PATTERN_INDEX_TO_CALENDAR_FIELD
#undef PATTERN_INDEX_TO_DATE_FORMAT_FIELD
#undef PATTERN_INDEX_TO_DATE_FORMAT_FIELD_ID
#undef REST_OF_STYLES
#undef SECOND
#undef SECOND_FIELD
#undef SHORT
#undef SHORT_FORMAT
#undef SHORT_STANDALONE
#undef TAG_QUOTE_ASCII_CHAR
#undef TAG_QUOTE_CHARS
#undef TIMEZONE_FIELD
#undef TIME_ZONE
#undef WEEK_OF_MONTH
#undef WEEK_OF_MONTH_FIELD
#undef WEEK_OF_YEAR
#undef WEEK_OF_YEAR_FIELD
#undef WEEK_YEAR
#undef YEAR
#undef YEAR_FIELD
#undef ZONE_OFFSET

using $DateFormat$FieldArray = $Array<::java::text::DateFormat$Field>;
using $StringArray2 = $Array<::java::lang::String, 2>;
using $InvalidObjectException = ::java::io::InvalidObjectException;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $AssertionError = ::java::lang::AssertionError;
using $CharSequence = ::java::lang::CharSequence;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IndexOutOfBoundsException = ::java::lang::IndexOutOfBoundsException;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $Number = ::java::lang::Number;
using $StringBuffer = ::java::lang::StringBuffer;
using $AttributedCharacterIterator = ::java::text::AttributedCharacterIterator;
using $CalendarBuilder = ::java::text::CalendarBuilder;
using $CharacterIteratorFieldDelegate = ::java::text::CharacterIteratorFieldDelegate;
using $DateFormat = ::java::text::DateFormat;
using $DateFormat$Field = ::java::text::DateFormat$Field;
using $DateFormatSymbols = ::java::text::DateFormatSymbols;
using $DecimalFormat = ::java::text::DecimalFormat;
using $DecimalFormatSymbols = ::java::text::DecimalFormatSymbols;
using $DontCareFieldPosition = ::java::text::DontCareFieldPosition;
using $FieldPosition = ::java::text::FieldPosition;
using $Format$Field = ::java::text::Format$Field;
using $Format$FieldDelegate = ::java::text::Format$FieldDelegate;
using $NumberFormat = ::java::text::NumberFormat;
using $ParsePosition = ::java::text::ParsePosition;
using $Calendar = ::java::util::Calendar;
using $Date = ::java::util::Date;
using $GregorianCalendar = ::java::util::GregorianCalendar;
using $Iterator = ::java::util::Iterator;
using $Locale = ::java::util::Locale;
using $Locale$Category = ::java::util::Locale$Category;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $SimpleTimeZone = ::java::util::SimpleTimeZone;
using $SortedMap = ::java::util::SortedMap;
using $TimeZone = ::java::util::TimeZone;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $ConcurrentMap = ::java::util::concurrent::ConcurrentMap;
using $CalendarUtils = ::sun::util::calendar::CalendarUtils;
using $ZoneInfoFile = ::sun::util::calendar::ZoneInfoFile;
using $LocaleProviderAdapter = ::sun::util::locale::provider::LocaleProviderAdapter;
using $LocaleResources = ::sun::util::locale::provider::LocaleResources;
using $TimeZoneNameUtility = ::sun::util::locale::provider::TimeZoneNameUtility;

namespace java {
	namespace text {

$FieldInfo _SimpleDateFormat_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(SimpleDateFormat, $assertionsDisabled)},
	{"serialVersionUID", "J", nullptr, $STATIC | $FINAL, $constField(SimpleDateFormat, serialVersionUID)},
	{"currentSerialVersion", "I", nullptr, $STATIC | $FINAL, $constField(SimpleDateFormat, currentSerialVersion)},
	{"serialVersionOnStream", "I", nullptr, $PRIVATE, $field(SimpleDateFormat, serialVersionOnStream)},
	{"pattern", "Ljava/lang/String;", nullptr, $PRIVATE, $field(SimpleDateFormat, pattern)},
	{"originalNumberFormat", "Ljava/text/NumberFormat;", nullptr, $PRIVATE | $TRANSIENT, $field(SimpleDateFormat, originalNumberFormat)},
	{"originalNumberPattern", "Ljava/lang/String;", nullptr, $PRIVATE | $TRANSIENT, $field(SimpleDateFormat, originalNumberPattern)},
	{"minusSign", "C", nullptr, $PRIVATE | $TRANSIENT, $field(SimpleDateFormat, minusSign)},
	{"hasFollowingMinusSign", "Z", nullptr, $PRIVATE | $TRANSIENT, $field(SimpleDateFormat, hasFollowingMinusSign)},
	{"forceStandaloneForm", "Z", nullptr, $PRIVATE | $TRANSIENT, $field(SimpleDateFormat, forceStandaloneForm)},
	{"compiledPattern", "[C", nullptr, $PRIVATE | $TRANSIENT, $field(SimpleDateFormat, compiledPattern)},
	{"TAG_QUOTE_ASCII_CHAR", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SimpleDateFormat, TAG_QUOTE_ASCII_CHAR)},
	{"TAG_QUOTE_CHARS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SimpleDateFormat, TAG_QUOTE_CHARS)},
	{"zeroDigit", "C", nullptr, $PRIVATE | $TRANSIENT, $field(SimpleDateFormat, zeroDigit)},
	{"formatData", "Ljava/text/DateFormatSymbols;", nullptr, $PRIVATE, $field(SimpleDateFormat, formatData)},
	{"defaultCenturyStart", "Ljava/util/Date;", nullptr, $PRIVATE, $field(SimpleDateFormat, defaultCenturyStart)},
	{"defaultCenturyStartYear", "I", nullptr, $PRIVATE | $TRANSIENT, $field(SimpleDateFormat, defaultCenturyStartYear)},
	{"MILLIS_PER_MINUTE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SimpleDateFormat, MILLIS_PER_MINUTE)},
	{"GMT", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SimpleDateFormat, GMT)},
	{"cachedNumberFormatData", "Ljava/util/concurrent/ConcurrentMap;", "Ljava/util/concurrent/ConcurrentMap<Ljava/util/Locale;Ljava/text/NumberFormat;>;", $PRIVATE | $STATIC | $FINAL, $staticField(SimpleDateFormat, cachedNumberFormatData)},
	{"locale", "Ljava/util/Locale;", nullptr, $PRIVATE, $field(SimpleDateFormat, locale)},
	{"useDateFormatSymbols", "Z", nullptr, $TRANSIENT, $field(SimpleDateFormat, useDateFormatSymbols$)},
	{"PATTERN_INDEX_TO_CALENDAR_FIELD", "[I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SimpleDateFormat, PATTERN_INDEX_TO_CALENDAR_FIELD)},
	{"PATTERN_INDEX_TO_DATE_FORMAT_FIELD", "[I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SimpleDateFormat, PATTERN_INDEX_TO_DATE_FORMAT_FIELD)},
	{"PATTERN_INDEX_TO_DATE_FORMAT_FIELD_ID", "[Ljava/text/DateFormat$Field;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SimpleDateFormat, PATTERN_INDEX_TO_DATE_FORMAT_FIELD_ID)},
	{"REST_OF_STYLES", "[I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SimpleDateFormat, REST_OF_STYLES)},
	{}
};

$MethodInfo _SimpleDateFormat_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(SimpleDateFormat, init$, void)},
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(SimpleDateFormat, init$, void, $String*)},
	{"<init>", "(Ljava/lang/String;Ljava/util/Locale;)V", nullptr, $PUBLIC, $method(SimpleDateFormat, init$, void, $String*, $Locale*)},
	{"<init>", "(Ljava/lang/String;Ljava/text/DateFormatSymbols;)V", nullptr, $PUBLIC, $method(SimpleDateFormat, init$, void, $String*, $DateFormatSymbols*)},
	{"applyLocalizedPattern", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(SimpleDateFormat, applyLocalizedPattern, void, $String*)},
	{"applyPattern", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(SimpleDateFormat, applyPattern, void, $String*)},
	{"applyPatternImpl", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(SimpleDateFormat, applyPatternImpl, void, $String*)},
	{"checkNegativeNumberExpression", "()V", nullptr, $PRIVATE, $method(SimpleDateFormat, checkNegativeNumberExpression, void)},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(SimpleDateFormat, clone, $Object*)},
	{"compile", "(Ljava/lang/String;)[C", nullptr, $PRIVATE, $method(SimpleDateFormat, compile, $chars*, $String*)},
	{"encode", "(IILjava/lang/StringBuilder;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(SimpleDateFormat, encode, void, int32_t, int32_t, $StringBuilder*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(SimpleDateFormat, equals, bool, Object$*)},
	{"format", "(Ljava/util/Date;Ljava/lang/StringBuffer;Ljava/text/FieldPosition;)Ljava/lang/StringBuffer;", nullptr, $PUBLIC, $virtualMethod(SimpleDateFormat, format, $StringBuffer*, $Date*, $StringBuffer*, $FieldPosition*)},
	{"format", "(Ljava/util/Date;Ljava/lang/StringBuffer;Ljava/text/Format$FieldDelegate;)Ljava/lang/StringBuffer;", nullptr, $PRIVATE, $method(SimpleDateFormat, format, $StringBuffer*, $Date*, $StringBuffer*, $Format$FieldDelegate*)},
	{"formatToCharacterIterator", "(Ljava/lang/Object;)Ljava/text/AttributedCharacterIterator;", nullptr, $PUBLIC, $virtualMethod(SimpleDateFormat, formatToCharacterIterator, $AttributedCharacterIterator*, Object$*)},
	{"get2DigitYearStart", "()Ljava/util/Date;", nullptr, $PUBLIC, $virtualMethod(SimpleDateFormat, get2DigitYearStart, $Date*)},
	{"getDateFormatSymbols", "()Ljava/text/DateFormatSymbols;", nullptr, $PUBLIC, $virtualMethod(SimpleDateFormat, getDateFormatSymbols, $DateFormatSymbols*)},
	{"getDisplayContextNamesMap", "(ILjava/util/Locale;)Ljava/util/Map;", "(ILjava/util/Locale;)Ljava/util/Map<Ljava/lang/String;Ljava/lang/Integer;>;", $PRIVATE, $method(SimpleDateFormat, getDisplayContextNamesMap, $Map*, int32_t, $Locale*)},
	{"getDisplayNamesMap", "(ILjava/util/Locale;)Ljava/util/Map;", "(ILjava/util/Locale;)Ljava/util/Map<Ljava/lang/String;Ljava/lang/Integer;>;", $PRIVATE, $method(SimpleDateFormat, getDisplayNamesMap, $Map*, int32_t, $Locale*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(SimpleDateFormat, hashCode, int32_t)},
	{"initialize", "(Ljava/util/Locale;)V", nullptr, $PRIVATE, $method(SimpleDateFormat, initialize, void, $Locale*)},
	{"initializeCalendar", "(Ljava/util/Locale;)V", nullptr, $PRIVATE, $method(SimpleDateFormat, initializeCalendar, void, $Locale*)},
	{"initializeDefaultCentury", "()V", nullptr, $PRIVATE, $method(SimpleDateFormat, initializeDefaultCentury, void)},
	{"isDigit", "(C)Z", nullptr, $PRIVATE, $method(SimpleDateFormat, isDigit, bool, char16_t)},
	{"matchDSTString", "(Ljava/lang/String;III[[Ljava/lang/String;)Z", nullptr, $PRIVATE, $method(SimpleDateFormat, matchDSTString, bool, $String*, int32_t, int32_t, int32_t, $StringArray2*)},
	{"matchString", "(Ljava/lang/String;II[Ljava/lang/String;Ljava/text/CalendarBuilder;)I", nullptr, $PRIVATE, $method(SimpleDateFormat, matchString, int32_t, $String*, int32_t, int32_t, $StringArray*, $CalendarBuilder*)},
	{"matchString", "(Ljava/lang/String;IILjava/util/Map;Ljava/text/CalendarBuilder;)I", "(Ljava/lang/String;IILjava/util/Map<Ljava/lang/String;Ljava/lang/Integer;>;Ljava/text/CalendarBuilder;)I", $PRIVATE, $method(SimpleDateFormat, matchString, int32_t, $String*, int32_t, int32_t, $Map*, $CalendarBuilder*)},
	{"matchZoneString", "(Ljava/lang/String;I[Ljava/lang/String;)I", nullptr, $PRIVATE, $method(SimpleDateFormat, matchZoneString, int32_t, $String*, int32_t, $StringArray*)},
	{"parse", "(Ljava/lang/String;Ljava/text/ParsePosition;)Ljava/util/Date;", nullptr, $PUBLIC, $virtualMethod(SimpleDateFormat, parse, $Date*, $String*, $ParsePosition*)},
	{"parseAmbiguousDatesAsAfter", "(Ljava/util/Date;)V", nullptr, $PRIVATE, $method(SimpleDateFormat, parseAmbiguousDatesAsAfter, void, $Date*)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(SimpleDateFormat, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"set2DigitYearStart", "(Ljava/util/Date;)V", nullptr, $PUBLIC, $virtualMethod(SimpleDateFormat, set2DigitYearStart, void, $Date*)},
	{"setDateFormatSymbols", "(Ljava/text/DateFormatSymbols;)V", nullptr, $PUBLIC, $virtualMethod(SimpleDateFormat, setDateFormatSymbols, void, $DateFormatSymbols*)},
	{"shouldObeyCount", "(II)Z", nullptr, $PRIVATE, $method(SimpleDateFormat, shouldObeyCount, bool, int32_t, int32_t)},
	{"subFormat", "(IILjava/text/Format$FieldDelegate;Ljava/lang/StringBuffer;Z)V", nullptr, $PRIVATE, $method(SimpleDateFormat, subFormat, void, int32_t, int32_t, $Format$FieldDelegate*, $StringBuffer*, bool)},
	{"subParse", "(Ljava/lang/String;IIIZ[ZLjava/text/ParsePosition;ZLjava/text/CalendarBuilder;)I", nullptr, $PRIVATE, $method(SimpleDateFormat, subParse, int32_t, $String*, int32_t, int32_t, int32_t, bool, $booleans*, $ParsePosition*, bool, $CalendarBuilder*)},
	{"subParseNumericZone", "(Ljava/lang/String;IIIZLjava/text/CalendarBuilder;)I", nullptr, $PRIVATE, $method(SimpleDateFormat, subParseNumericZone, int32_t, $String*, int32_t, int32_t, int32_t, bool, $CalendarBuilder*)},
	{"subParseZoneString", "(Ljava/lang/String;ILjava/text/CalendarBuilder;)I", nullptr, $PRIVATE, $method(SimpleDateFormat, subParseZoneString, int32_t, $String*, int32_t, $CalendarBuilder*)},
	{"toLocalizedPattern", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SimpleDateFormat, toLocalizedPattern, $String*)},
	{"toPattern", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SimpleDateFormat, toPattern, $String*)},
	{"translatePattern", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE, $method(SimpleDateFormat, translatePattern, $String*, $String*, $String*, $String*)},
	{"useDateFormatSymbols", "()Z", nullptr, $PRIVATE, $method(SimpleDateFormat, useDateFormatSymbols, bool)},
	{"zeroPaddingNumber", "(IIILjava/lang/StringBuffer;)V", nullptr, $PRIVATE, $method(SimpleDateFormat, zeroPaddingNumber, void, int32_t, int32_t, int32_t, $StringBuffer*)},
	{}
};

$ClassInfo _SimpleDateFormat_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.text.SimpleDateFormat",
	"java.text.DateFormat",
	nullptr,
	_SimpleDateFormat_FieldInfo_,
	_SimpleDateFormat_MethodInfo_
};

$Object* allocate$SimpleDateFormat($Class* clazz) {
	return $of($alloc(SimpleDateFormat));
}

bool SimpleDateFormat::$assertionsDisabled = false;
$String* SimpleDateFormat::GMT = nullptr;
$ConcurrentMap* SimpleDateFormat::cachedNumberFormatData = nullptr;
$ints* SimpleDateFormat::PATTERN_INDEX_TO_CALENDAR_FIELD = nullptr;
$ints* SimpleDateFormat::PATTERN_INDEX_TO_DATE_FORMAT_FIELD = nullptr;
$DateFormat$FieldArray* SimpleDateFormat::PATTERN_INDEX_TO_DATE_FORMAT_FIELD_ID = nullptr;
$ints* SimpleDateFormat::REST_OF_STYLES = nullptr;

void SimpleDateFormat::init$() {
	$useLocalCurrentObjectStackCache();
	$init($Locale$Category);
	SimpleDateFormat::init$(""_s, $($Locale::getDefault($Locale$Category::FORMAT)));
	applyPatternImpl($($nc($($nc($($LocaleProviderAdapter::getResourceBundleBased()))->getLocaleResources(this->locale)))->getDateTimePattern($DateFormat::SHORT, $DateFormat::SHORT, this->calendar)));
}

void SimpleDateFormat::init$($String* pattern) {
	$init($Locale$Category);
	SimpleDateFormat::init$(pattern, $($Locale::getDefault($Locale$Category::FORMAT)));
}

void SimpleDateFormat::init$($String* pattern, $Locale* locale) {
	$DateFormat::init$();
	this->serialVersionOnStream = SimpleDateFormat::currentSerialVersion;
	this->minusSign = u'-';
	this->hasFollowingMinusSign = false;
	this->forceStandaloneForm = false;
	if (pattern == nullptr || locale == nullptr) {
		$throwNew($NullPointerException);
	}
	initializeCalendar(locale);
	$set(this, pattern, pattern);
	$set(this, formatData, $DateFormatSymbols::getInstanceRef(locale));
	$set(this, locale, locale);
	initialize(locale);
}

void SimpleDateFormat::init$($String* pattern, $DateFormatSymbols* formatSymbols) {
	$DateFormat::init$();
	this->serialVersionOnStream = SimpleDateFormat::currentSerialVersion;
	this->minusSign = u'-';
	this->hasFollowingMinusSign = false;
	this->forceStandaloneForm = false;
	if (pattern == nullptr || formatSymbols == nullptr) {
		$throwNew($NullPointerException);
	}
	$set(this, pattern, pattern);
	$set(this, formatData, $cast($DateFormatSymbols, $nc(formatSymbols)->clone()));
	$init($Locale$Category);
	$set(this, locale, $Locale::getDefault($Locale$Category::FORMAT));
	initializeCalendar(this->locale);
	initialize(this->locale);
	this->useDateFormatSymbols$ = true;
}

void SimpleDateFormat::initialize($Locale* loc) {
	$set(this, compiledPattern, compile(this->pattern));
	$set(this, numberFormat, $cast($NumberFormat, $nc(SimpleDateFormat::cachedNumberFormatData)->get(loc)));
	if (this->numberFormat == nullptr) {
		$set(this, numberFormat, $NumberFormat::getIntegerInstance(loc));
		$nc(this->numberFormat)->setGroupingUsed(false);
		$nc(SimpleDateFormat::cachedNumberFormatData)->putIfAbsent(loc, this->numberFormat);
	}
	$set(this, numberFormat, $cast($NumberFormat, $nc(this->numberFormat)->clone()));
	initializeDefaultCentury();
}

void SimpleDateFormat::initializeCalendar($Locale* loc) {
	if (this->calendar == nullptr) {
		if (!SimpleDateFormat::$assertionsDisabled && !(loc != nullptr)) {
			$throwNew($AssertionError);
		}
		$set(this, calendar, $Calendar::getInstance(loc));
	}
}

$chars* SimpleDateFormat::compile($String* pattern) {
	$useLocalCurrentObjectStackCache();
	int32_t length = $nc(pattern)->length();
	bool inQuote = false;
	$var($StringBuilder, compiledCode, $new($StringBuilder, length * 2));
	$var($StringBuilder, tmpBuffer, nullptr);
	int32_t count = 0;
	int32_t tagcount = 0;
	int32_t lastTag = -1;
	int32_t prevTag = -1;
	for (int32_t i = 0; i < length; ++i) {
		char16_t c = pattern->charAt(i);
		if (c == u'\'') {
			if ((i + 1) < length) {
				c = pattern->charAt(i + 1);
				if (c == u'\'') {
					++i;
					if (count != 0) {
						encode(lastTag, count, compiledCode);
						++tagcount;
						prevTag = lastTag;
						lastTag = -1;
						count = 0;
					}
					if (inQuote) {
						$nc(tmpBuffer)->append(c);
					} else {
						compiledCode->append((char16_t)((SimpleDateFormat::TAG_QUOTE_ASCII_CHAR << 8) | c));
					}
					continue;
				}
			}
			if (!inQuote) {
				if (count != 0) {
					encode(lastTag, count, compiledCode);
					++tagcount;
					prevTag = lastTag;
					lastTag = -1;
					count = 0;
				}
				if (tmpBuffer == nullptr) {
					$assign(tmpBuffer, $new($StringBuilder, length));
				} else {
					$nc(tmpBuffer)->setLength(0);
				}
				inQuote = true;
			} else {
				int32_t len = $nc(tmpBuffer)->length();
				if (len == 1) {
					char16_t ch = tmpBuffer->charAt(0);
					if (ch < 128) {
						compiledCode->append((char16_t)((SimpleDateFormat::TAG_QUOTE_ASCII_CHAR << 8) | ch));
					} else {
						compiledCode->append((char16_t)((SimpleDateFormat::TAG_QUOTE_CHARS << 8) | 1));
						compiledCode->append(ch);
					}
				} else {
					encode(SimpleDateFormat::TAG_QUOTE_CHARS, len, compiledCode);
					compiledCode->append(static_cast<$CharSequence*>(tmpBuffer));
				}
				inQuote = false;
			}
			continue;
		}
		if (inQuote) {
			$nc(tmpBuffer)->append(c);
			continue;
		}
		if (!(c >= u'a' && c <= u'z' || c >= u'A' && c <= u'Z')) {
			if (count != 0) {
				encode(lastTag, count, compiledCode);
				++tagcount;
				prevTag = lastTag;
				lastTag = -1;
				count = 0;
			}
			if (c < 128) {
				compiledCode->append((char16_t)((SimpleDateFormat::TAG_QUOTE_ASCII_CHAR << 8) | c));
			} else {
				int32_t j = 0;
				for (j = i + 1; j < length; ++j) {
					char16_t d = pattern->charAt(j);
					if (d == u'\'' || (d >= u'a' && d <= u'z' || d >= u'A' && d <= u'Z')) {
						break;
					}
				}
				encode(SimpleDateFormat::TAG_QUOTE_CHARS, j - i, compiledCode);
				for (; i < j; ++i) {
					compiledCode->append(pattern->charAt(i));
				}
				--i;
			}
			continue;
		}
		int32_t tag = 0;
		$init($DateFormatSymbols);
		if ((tag = $nc($DateFormatSymbols::patternChars)->indexOf((int32_t)c)) == -1) {
			$throwNew($IllegalArgumentException, $$str({"Illegal pattern character \'"_s, $$str(c), "\'"_s}));
		}
		if (lastTag == -1 || lastTag == tag) {
			lastTag = tag;
			++count;
			continue;
		}
		encode(lastTag, count, compiledCode);
		++tagcount;
		prevTag = lastTag;
		lastTag = tag;
		count = 1;
	}
	if (inQuote) {
		$throwNew($IllegalArgumentException, "Unterminated quote"_s);
	}
	if (count != 0) {
		encode(lastTag, count, compiledCode);
		++tagcount;
		prevTag = lastTag;
	}
	this->forceStandaloneForm = (tagcount == 1 && prevTag == 2);
	int32_t len = compiledCode->length();
	$var($chars, r, $new($chars, len));
	compiledCode->getChars(0, len, r, 0);
	return r;
}

void SimpleDateFormat::encode(int32_t tag, int32_t length, $StringBuilder* buffer) {
	$init(SimpleDateFormat);
	$useLocalCurrentObjectStackCache();
	if (tag == 21 && length >= 4) {
		$throwNew($IllegalArgumentException, $$str({"invalid ISO 8601 format: length="_s, $$str(length)}));
	}
	if (length < 255) {
		$nc(buffer)->append((char16_t)((tag << 8) | length));
	} else {
		$nc(buffer)->append((char16_t)((tag << 8) | 255));
		buffer->append((char16_t)((int32_t)((uint32_t)length >> 16)));
		buffer->append((char16_t)((int32_t)(length & (uint32_t)0x0000FFFF)));
	}
}

void SimpleDateFormat::initializeDefaultCentury() {
	$nc(this->calendar)->setTimeInMillis($System::currentTimeMillis());
	$nc(this->calendar)->add($Calendar::YEAR, -80);
	parseAmbiguousDatesAsAfter($($nc(this->calendar)->getTime()));
}

void SimpleDateFormat::parseAmbiguousDatesAsAfter($Date* startDate) {
	$set(this, defaultCenturyStart, startDate);
	$nc(this->calendar)->setTime(startDate);
	this->defaultCenturyStartYear = $nc(this->calendar)->get($Calendar::YEAR);
}

void SimpleDateFormat::set2DigitYearStart($Date* startDate) {
	parseAmbiguousDatesAsAfter($$new($Date, $nc(startDate)->getTime()));
}

$Date* SimpleDateFormat::get2DigitYearStart() {
	return $cast($Date, $nc(this->defaultCenturyStart)->clone());
}

$StringBuffer* SimpleDateFormat::format($Date* date, $StringBuffer* toAppendTo, $FieldPosition* pos) {
	$nc(pos)->beginIndex = (pos->endIndex = 0);
	return format(date, toAppendTo, $(pos->getFieldDelegate()));
}

$StringBuffer* SimpleDateFormat::format($Date* date, $StringBuffer* toAppendTo, $Format$FieldDelegate* delegate) {
	$nc(this->calendar)->setTime(date);
	bool useDateFormatSymbols = this->useDateFormatSymbols();
	for (int32_t i = 0; i < $nc(this->compiledPattern)->length;) {
		int32_t tag = (int32_t)((uint32_t)$nc(this->compiledPattern)->get(i) >> 8);
		int32_t count = (int32_t)($nc(this->compiledPattern)->get(i++) & (uint32_t)255);
		if (count == 255) {
			count = $nc(this->compiledPattern)->get(i++) << 16;
			count |= $nc(this->compiledPattern)->get(i++);
		}
		switch (tag) {
		case SimpleDateFormat::TAG_QUOTE_ASCII_CHAR:
			{
				$nc(toAppendTo)->append((char16_t)count);
				break;
			}
		case SimpleDateFormat::TAG_QUOTE_CHARS:
			{
				$nc(toAppendTo)->append(this->compiledPattern, i, count);
				i += count;
				break;
			}
		default:
			{
				subFormat(tag, count, delegate, toAppendTo, useDateFormatSymbols);
				break;
			}
		}
	}
	return toAppendTo;
}

$AttributedCharacterIterator* SimpleDateFormat::formatToCharacterIterator(Object$* obj) {
	$useLocalCurrentObjectStackCache();
	$var($StringBuffer, sb, $new($StringBuffer));
	$var($CharacterIteratorFieldDelegate, delegate, $new($CharacterIteratorFieldDelegate));
	if ($instanceOf($Date, obj)) {
		format($cast($Date, obj), sb, static_cast<$Format$FieldDelegate*>(delegate));
	} else if ($instanceOf($Number, obj)) {
		format($$new($Date, $nc(($cast($Number, obj)))->longValue()), sb, static_cast<$Format$FieldDelegate*>(delegate));
	} else if (obj == nullptr) {
		$throwNew($NullPointerException, "formatToCharacterIterator must be passed non-null object"_s);
	} else {
		$throwNew($IllegalArgumentException, "Cannot format given Object as a Date"_s);
	}
	return delegate->getIterator($(sb->toString()));
}

void SimpleDateFormat::subFormat(int32_t patternCharIndex, int32_t count, $Format$FieldDelegate* delegate, $StringBuffer* buffer, bool useDateFormatSymbols) {
	$useLocalCurrentObjectStackCache();
	int32_t maxIntCount = $Integer::MAX_VALUE;
	$var($String, current, nullptr);
	int32_t beginOffset = $nc(buffer)->length();
	int32_t field = $nc(SimpleDateFormat::PATTERN_INDEX_TO_CALENDAR_FIELD)->get(patternCharIndex);
	int32_t value = 0;
	if (field == $CalendarBuilder::WEEK_YEAR) {
		if ($nc(this->calendar)->isWeekDateSupported()) {
			value = $nc(this->calendar)->getWeekYear();
		} else {
			patternCharIndex = 1;
			field = $nc(SimpleDateFormat::PATTERN_INDEX_TO_CALENDAR_FIELD)->get(patternCharIndex);
			value = $nc(this->calendar)->get(field);
		}
	} else if (field == $CalendarBuilder::ISO_DAY_OF_WEEK) {
		value = $CalendarBuilder::toISODayOfWeek($nc(this->calendar)->get($Calendar::DAY_OF_WEEK));
	} else {
		value = $nc(this->calendar)->get(field);
	}
	int32_t style = (count >= 4) ? $Calendar::LONG : $Calendar::SHORT;
	if (!useDateFormatSymbols && field < $Calendar::ZONE_OFFSET && patternCharIndex != 22) {
		$assign(current, $nc(this->calendar)->getDisplayName(field, style, this->locale));
	}
	{
		int32_t width = 0;
		int32_t num = 0;
		switch (patternCharIndex) {
		case 0:
			{
				if (useDateFormatSymbols) {
					$var($StringArray, eras, $nc(this->formatData)->getEras());
					if (value < $nc(eras)->length) {
						$assign(current, eras->get(value));
					}
				}
				if (current == nullptr) {
					$assign(current, ""_s);
				}
				break;
			}
		case 19:
			{}
		case 1:
			{
				if ($instanceOf($GregorianCalendar, this->calendar)) {
					if (count != 2) {
						zeroPaddingNumber(value, count, maxIntCount, buffer);
					} else {
						zeroPaddingNumber(value, 2, 2, buffer);
					}
				} else if (current == nullptr) {
					zeroPaddingNumber(value, style == $Calendar::LONG ? 1 : count, maxIntCount, buffer);
				}
				break;
			}
		case 2:
			{
				if (useDateFormatSymbols) {
					$var($StringArray, months, nullptr);
					if (count >= 4) {
						$assign(months, $nc(this->formatData)->getMonths());
						$assign(current, $nc(months)->get(value));
					} else if (count == 3) {
						$assign(months, $nc(this->formatData)->getShortMonths());
						$assign(current, $nc(months)->get(value));
					}
				} else if (count < 3) {
					$assign(current, nullptr);
				} else if (this->forceStandaloneForm) {
					$assign(current, $nc(this->calendar)->getDisplayName(field, style | 32768, this->locale));
					if (current == nullptr) {
						$assign(current, $nc(this->calendar)->getDisplayName(field, style, this->locale));
					}
				}
				if (current == nullptr) {
					zeroPaddingNumber(value + 1, count, maxIntCount, buffer);
				}
				break;
			}
		case 22:
			{
				if (!SimpleDateFormat::$assertionsDisabled && !(current == nullptr)) {
					$throwNew($AssertionError);
				}
				if (this->locale == nullptr) {
					$var($StringArray, months, nullptr);
					if (count >= 4) {
						$assign(months, $nc(this->formatData)->getMonths());
						$assign(current, $nc(months)->get(value));
					} else if (count == 3) {
						$assign(months, $nc(this->formatData)->getShortMonths());
						$assign(current, $nc(months)->get(value));
					}
				} else if (count >= 3) {
					$assign(current, $nc(this->calendar)->getDisplayName(field, style | 32768, this->locale));
				}
				if (current == nullptr) {
					zeroPaddingNumber(value + 1, count, maxIntCount, buffer);
				}
				break;
			}
		case 4:
			{
				if (current == nullptr) {
					if (value == 0) {
						zeroPaddingNumber($nc(this->calendar)->getMaximum($Calendar::HOUR_OF_DAY) + 1, count, maxIntCount, buffer);
					} else {
						zeroPaddingNumber(value, count, maxIntCount, buffer);
					}
				}
				break;
			}
		case 9:
			{
				if (useDateFormatSymbols) {
					$var($StringArray, weekdays, nullptr);
					if (count >= 4) {
						$assign(weekdays, $nc(this->formatData)->getWeekdays());
						$assign(current, $nc(weekdays)->get(value));
					} else {
						$assign(weekdays, $nc(this->formatData)->getShortWeekdays());
						$assign(current, $nc(weekdays)->get(value));
					}
				}
				break;
			}
		case 14:
			{
				if (useDateFormatSymbols) {
					$var($StringArray, ampm, $nc(this->formatData)->getAmPmStrings());
					$assign(current, $nc(ampm)->get(value));
				}
				break;
			}
		case 15:
			{
				if (current == nullptr) {
					if (value == 0) {
						zeroPaddingNumber($nc(this->calendar)->getLeastMaximum($Calendar::HOUR) + 1, count, maxIntCount, buffer);
					} else {
						zeroPaddingNumber(value, count, maxIntCount, buffer);
					}
				}
				break;
			}
		case 17:
			{
				if (current == nullptr) {
					if ($nc(this->formatData)->locale == nullptr || $nc(this->formatData)->isZoneStringsSet) {
						int32_t zoneIndex = $nc(this->formatData)->getZoneIndex($($nc($($nc(this->calendar)->getTimeZone()))->getID()));
						if (zoneIndex == -1) {
							int32_t var$0 = $nc(this->calendar)->get($Calendar::ZONE_OFFSET);
							value = var$0 + $nc(this->calendar)->get($Calendar::DST_OFFSET);
							buffer->append($($ZoneInfoFile::toCustomID(value)));
						} else {
							int32_t index = ($nc(this->calendar)->get($Calendar::DST_OFFSET) == 0) ? 1 : 3;
							if (count < 4) {
								++index;
							}
							$var($StringArray2, zoneStrings, $nc(this->formatData)->getZoneStringsWrapper());
							buffer->append($nc($nc(zoneStrings)->get(zoneIndex))->get(index));
						}
					} else {
						$var($TimeZone, tz, $nc(this->calendar)->getTimeZone());
						bool daylight = ($nc(this->calendar)->get($Calendar::DST_OFFSET) != 0);
						int32_t tzstyle = (count < 4 ? $TimeZone::SHORT : $TimeZone::LONG);
						buffer->append($($nc(tz)->getDisplayName(daylight, tzstyle, $nc(this->formatData)->locale)));
					}
				}
				break;
			}
		case 18:
			{
				int32_t var$1 = $nc(this->calendar)->get($Calendar::ZONE_OFFSET);
				value = (var$1 + $nc(this->calendar)->get($Calendar::DST_OFFSET)) / 0x0000EA60;
				width = 4;
				if (value >= 0) {
					buffer->append(u'+');
				} else {
					++width;
				}
				num = (value / 60) * 100 + (value % 60);
				$CalendarUtils::sprintf0d(buffer, num, width);
				break;
			}
		case 21:
			{
				int32_t var$2 = $nc(this->calendar)->get($Calendar::ZONE_OFFSET);
				value = var$2 + $nc(this->calendar)->get($Calendar::DST_OFFSET);
				if (value == 0) {
					buffer->append(u'Z');
					break;
				}
				value /= 0x0000EA60;
				if (value >= 0) {
					buffer->append(u'+');
				} else {
					buffer->append(u'-');
					value = -value;
				}
				$CalendarUtils::sprintf0d(buffer, value / 60, 2);
				if (count == 1) {
					break;
				}
				if (count == 3) {
					buffer->append(u':');
				}
				$CalendarUtils::sprintf0d(buffer, value % 60, 2);
				break;
			}
		default:
			{
				if (current == nullptr) {
					zeroPaddingNumber(value, count, maxIntCount, buffer);
				}
				break;
			}
		}
	}
	if (current != nullptr) {
		buffer->append(current);
	}
	int32_t fieldID = $nc(SimpleDateFormat::PATTERN_INDEX_TO_DATE_FORMAT_FIELD)->get(patternCharIndex);
	$var($DateFormat$Field, f, $nc(SimpleDateFormat::PATTERN_INDEX_TO_DATE_FORMAT_FIELD_ID)->get(patternCharIndex));
	$nc(delegate)->formatted(fieldID, f, f, beginOffset, buffer->length(), buffer);
}

void SimpleDateFormat::zeroPaddingNumber(int32_t value, int32_t minDigits, int32_t maxDigits, $StringBuffer* buffer) {
	try {
		if (this->zeroDigit == 0) {
			this->zeroDigit = $nc($($nc(($cast($DecimalFormat, this->numberFormat)))->getDecimalFormatSymbols()))->getZeroDigit();
		}
		if (value >= 0) {
			if (value < 100 && minDigits >= 1 && minDigits <= 2) {
				if (value < 10) {
					if (minDigits == 2) {
						$nc(buffer)->append(this->zeroDigit);
					}
					$nc(buffer)->append((char16_t)(this->zeroDigit + value));
				} else {
					$nc(buffer)->append((char16_t)(this->zeroDigit + value / 10));
					buffer->append((char16_t)(this->zeroDigit + value % 10));
				}
				return;
			} else if (value >= 1000 && value < 10000) {
				if (minDigits == 4) {
					$nc(buffer)->append((char16_t)(this->zeroDigit + value / 1000));
					$modAssign(value, 1000);
					buffer->append((char16_t)(this->zeroDigit + value / 100));
					$modAssign(value, 100);
					buffer->append((char16_t)(this->zeroDigit + value / 10));
					buffer->append((char16_t)(this->zeroDigit + value % 10));
					return;
				}
				if (minDigits == 2 && maxDigits == 2) {
					zeroPaddingNumber(value % 100, 2, 2, buffer);
					return;
				}
			}
		}
	} catch ($Exception& e) {
	}
	$nc(this->numberFormat)->setMinimumIntegerDigits(minDigits);
	$nc(this->numberFormat)->setMaximumIntegerDigits(maxDigits);
	$init($DontCareFieldPosition);
	$nc(this->numberFormat)->format((int64_t)value, buffer, $DontCareFieldPosition::INSTANCE);
}

$Date* SimpleDateFormat::parse($String* text, $ParsePosition* pos) {
	$useLocalCurrentObjectStackCache();
	checkNegativeNumberExpression();
	int32_t start = $nc(pos)->index;
	int32_t oldStart = start;
	int32_t textLength = $nc(text)->length();
	$var($booleans, ambiguousYear, $new($booleans, {false}));
	$var($CalendarBuilder, calb, $new($CalendarBuilder));
	for (int32_t i = 0; i < $nc(this->compiledPattern)->length;) {
		int32_t tag = (int32_t)((uint32_t)$nc(this->compiledPattern)->get(i) >> 8);
		int32_t count = (int32_t)($nc(this->compiledPattern)->get(i++) & (uint32_t)255);
		if (count == 255) {
			count = $nc(this->compiledPattern)->get(i++) << 16;
			count |= $nc(this->compiledPattern)->get(i++);
		}
		{
			bool obeyCount = false;
			bool useFollowingMinusSignAsDelimiter = false;
			switch (tag) {
			case SimpleDateFormat::TAG_QUOTE_ASCII_CHAR:
				{
					if (start >= textLength || text->charAt(start) != (char16_t)count) {
						pos->index = oldStart;
						pos->errorIndex = start;
						return nullptr;
					}
					++start;
					break;
				}
			case SimpleDateFormat::TAG_QUOTE_CHARS:
				{
					while (count-- > 0) {
						if (start >= textLength || text->charAt(start) != $nc(this->compiledPattern)->get(i++)) {
							pos->index = oldStart;
							pos->errorIndex = start;
							return nullptr;
						}
						++start;
					}
					break;
				}
			default:
				{
					obeyCount = false;
					useFollowingMinusSignAsDelimiter = false;
					if (i < $nc(this->compiledPattern)->length) {
						int32_t nextTag = (int32_t)((uint32_t)$nc(this->compiledPattern)->get(i) >> 8);
						int32_t nextCount = (int32_t)($nc(this->compiledPattern)->get(i) & (uint32_t)255);
						obeyCount = shouldObeyCount(nextTag, nextCount);
						if (this->hasFollowingMinusSign && (nextTag == SimpleDateFormat::TAG_QUOTE_ASCII_CHAR || nextTag == SimpleDateFormat::TAG_QUOTE_CHARS)) {
							if (nextTag != SimpleDateFormat::TAG_QUOTE_ASCII_CHAR) {
								nextCount = $nc(this->compiledPattern)->get(i + 1);
							}
							if (nextCount == this->minusSign) {
								useFollowingMinusSignAsDelimiter = true;
							}
						}
					}
					start = subParse(text, start, tag, count, obeyCount, ambiguousYear, pos, useFollowingMinusSignAsDelimiter, calb);
					if (start < 0) {
						pos->index = oldStart;
						return nullptr;
					}
				}
			}
		}
	}
	pos->index = start;
	$var($Date, parsedDate, nullptr);
	try {
		$assign(parsedDate, $nc($(calb->establish(this->calendar)))->getTime());
		if (ambiguousYear->get(0)) {
			if ($nc(parsedDate)->before(this->defaultCenturyStart)) {
				$assign(parsedDate, $nc($($nc($(calb->addYear(100)))->establish(this->calendar)))->getTime());
			}
		}
	} catch ($IllegalArgumentException& e) {
		pos->errorIndex = start;
		pos->index = oldStart;
		return nullptr;
	}
	return parsedDate;
}

bool SimpleDateFormat::shouldObeyCount(int32_t tag, int32_t count) {
	switch (tag) {
	case 2:
		{}
	case 22:
		{
			return count <= 2;
		}
	case 1:
		{}
	case 3:
		{}
	case 4:
		{}
	case 5:
		{}
	case 6:
		{}
	case 7:
		{}
	case 8:
		{}
	case 10:
		{}
	case 11:
		{}
	case 12:
		{}
	case 13:
		{}
	case 15:
		{}
	case 16:
		{}
	case 19:
		{}
	case 20:
		{
			return true;
		}
	default:
		{
			return false;
		}
	}
}

int32_t SimpleDateFormat::matchString($String* text, int32_t start, int32_t field, $StringArray* data, $CalendarBuilder* calb) {
	int32_t i = 0;
	int32_t count = $nc(data)->length;
	if (field == $Calendar::DAY_OF_WEEK) {
		i = 1;
	}
	int32_t bestMatchLength = 0;
	int32_t bestMatch = -1;
	for (; i < count; ++i) {
		int32_t length = $nc(data->get(i))->length();
		if (length > bestMatchLength && $nc(text)->regionMatches(true, start, data->get(i), 0, length)) {
			bestMatch = i;
			bestMatchLength = length;
		}
	}
	if (bestMatch >= 0) {
		$nc(calb)->set(field, bestMatch);
		return start + bestMatchLength;
	}
	return -start;
}

int32_t SimpleDateFormat::matchString($String* text, int32_t start, int32_t field, $Map* data, $CalendarBuilder* calb) {
	$useLocalCurrentObjectStackCache();
	if (data != nullptr) {
		if ($instanceOf($SortedMap, data)) {
			{
				$var($Iterator, i$, $nc($(data->keySet()))->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($String, name, $cast($String, i$->next()));
					{
						if ($nc(text)->regionMatches(true, start, name, 0, $nc(name)->length())) {
							$nc(calb)->set(field, $nc(($cast($Integer, $(data->get(name)))))->intValue());
							return start + $nc(name)->length();
						}
					}
				}
			}
			return -start;
		}
		$var($String, bestMatch, nullptr);
		{
			$var($Iterator, i$, $nc($(data->keySet()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($String, name, $cast($String, i$->next()));
				{
					int32_t length = $nc(name)->length();
					if (bestMatch == nullptr || length > $nc(bestMatch)->length()) {
						if ($nc(text)->regionMatches(true, start, name, 0, length)) {
							$assign(bestMatch, name);
						}
					}
				}
			}
		}
		if (bestMatch != nullptr) {
			$nc(calb)->set(field, $nc(($cast($Integer, $(data->get(bestMatch)))))->intValue());
			return start + bestMatch->length();
		}
	}
	return -start;
}

int32_t SimpleDateFormat::matchZoneString($String* text, int32_t start, $StringArray* zoneNames) {
	$useLocalCurrentObjectStackCache();
	for (int32_t i = 1; i <= 4; ++i) {
		$var($String, zoneName, $nc(zoneNames)->get(i));
		if ($nc(zoneName)->isEmpty()) {
			$assign(zoneName, $TimeZoneNameUtility::retrieveDisplayName(zoneNames->get(0), i >= 3, i % 2, this->locale));
			zoneNames->set(i, zoneName);
		}
		if ($nc(text)->regionMatches(true, start, zoneName, 0, $nc(zoneName)->length())) {
			return i;
		}
	}
	return -1;
}

bool SimpleDateFormat::matchDSTString($String* text, int32_t start, int32_t zoneIndex, int32_t standardIndex, $StringArray2* zoneStrings) {
	int32_t index = standardIndex + 2;
	$var($String, zoneName, $nc($nc(zoneStrings)->get(zoneIndex))->get(index));
	if ($nc(text)->regionMatches(true, start, zoneName, 0, $nc(zoneName)->length())) {
		return true;
	}
	return false;
}

int32_t SimpleDateFormat::subParseZoneString($String* text, int32_t start, $CalendarBuilder* calb) {
	$useLocalCurrentObjectStackCache();
	bool useSameName = false;
	$var($TimeZone, currentTimeZone, getTimeZone());
	int32_t zoneIndex = $nc(this->formatData)->getZoneIndex($($nc(currentTimeZone)->getID()));
	$var($TimeZone, tz, nullptr);
	$var($StringArray2, zoneStrings, $nc(this->formatData)->getZoneStringsWrapper());
	$var($StringArray, zoneNames, nullptr);
	int32_t nameIndex = 0;
	if (zoneIndex != -1) {
		$assign(zoneNames, $nc(zoneStrings)->get(zoneIndex));
		if ((nameIndex = matchZoneString(text, start, zoneNames)) > 0) {
			if (nameIndex <= 2) {
				useSameName = $nc($nc(zoneNames)->get(nameIndex))->equalsIgnoreCase(zoneNames->get(nameIndex + 2));
			}
			$assign(tz, $TimeZone::getTimeZone($nc(zoneNames)->get(0)));
		}
	}
	if (tz == nullptr) {
		zoneIndex = $nc(this->formatData)->getZoneIndex($($nc($($TimeZone::getDefault()))->getID()));
		if (zoneIndex != -1) {
			$assign(zoneNames, $nc(zoneStrings)->get(zoneIndex));
			if ((nameIndex = matchZoneString(text, start, zoneNames)) > 0) {
				if (nameIndex <= 2) {
					useSameName = $nc($nc(zoneNames)->get(nameIndex))->equalsIgnoreCase(zoneNames->get(nameIndex + 2));
				}
				$assign(tz, $TimeZone::getTimeZone($nc(zoneNames)->get(0)));
			}
		}
	}
	if (tz == nullptr) {
		int32_t len = $nc(zoneStrings)->length;
		for (int32_t i = 0; i < len; ++i) {
			$assign(zoneNames, zoneStrings->get(i));
			if ((nameIndex = matchZoneString(text, start, zoneNames)) > 0) {
				if (nameIndex <= 2) {
					useSameName = $nc($nc(zoneNames)->get(nameIndex))->equalsIgnoreCase(zoneNames->get(nameIndex + 2));
				}
				$assign(tz, $TimeZone::getTimeZone($nc(zoneNames)->get(0)));
				break;
			}
		}
	}
	if (tz != nullptr) {
		if (!$of(tz)->equals(currentTimeZone)) {
			setTimeZone(tz);
		}
		int32_t dstAmount = (nameIndex >= 3) ? tz->getDSTSavings() : 0;
		if (!(useSameName || (nameIndex >= 3 && dstAmount == 0))) {
			$nc($($nc(calb)->clear($Calendar::ZONE_OFFSET)))->set($Calendar::DST_OFFSET, dstAmount);
		}
		return (start + $nc($nc(zoneNames)->get(nameIndex))->length());
	}
	return -start;
}

int32_t SimpleDateFormat::subParseNumericZone($String* text, int32_t start, int32_t sign, int32_t count, bool colon, $CalendarBuilder* calb) {
	$useLocalCurrentObjectStackCache();
	int32_t index = start;
	bool parse$break = false;
	for (;;) {
		try {
			char16_t c = $nc(text)->charAt(index++);
			int32_t hours = 0;
			if (!isDigit(c)) {
				parse$break = true;
				break;
			}
			hours = c - u'0';
			c = text->charAt(index++);
			if (isDigit(c)) {
				hours = hours * 10 + (c - u'0');
			} else {
				if (count > 0 || !colon) {
					parse$break = true;
					break;
				}
				--index;
			}
			if (hours > 23) {
				parse$break = true;
				break;
			}
			int32_t minutes = 0;
			if (count != 1) {
				c = text->charAt(index++);
				if (colon) {
					if (c != u':') {
						parse$break = true;
						break;
					}
					c = text->charAt(index++);
				}
				if (!isDigit(c)) {
					parse$break = true;
					break;
				}
				minutes = c - u'0';
				c = text->charAt(index++);
				if (!isDigit(c)) {
					parse$break = true;
					break;
				}
				minutes = minutes * 10 + (c - u'0');
				if (minutes > 59) {
					parse$break = true;
					break;
				}
			}
			minutes += hours * 60;
			$nc($($nc(calb)->set($Calendar::ZONE_OFFSET, minutes * SimpleDateFormat::MILLIS_PER_MINUTE * sign)))->set($Calendar::DST_OFFSET, 0);
			return index;
		} catch ($IndexOutOfBoundsException& e) {
		}
		break;
	}
	return 1 - index;
}

bool SimpleDateFormat::isDigit(char16_t c) {
	return c >= u'0' && c <= u'9';
}

int32_t SimpleDateFormat::subParse($String* text, int32_t start, int32_t patternCharIndex, int32_t count, bool obeyCount, $booleans* ambiguousYear, $ParsePosition* origPos, bool useFollowingMinusSignAsDelimiter, $CalendarBuilder* calb) {
	$useLocalCurrentObjectStackCache();
	$var($Number, number, nullptr);
	int32_t value = 0;
	$var($ParsePosition, pos, $new($ParsePosition, 0));
	pos->index = start;
	if (patternCharIndex == 19 && !$nc(this->calendar)->isWeekDateSupported()) {
		patternCharIndex = 1;
	}
	int32_t field = $nc(SimpleDateFormat::PATTERN_INDEX_TO_CALENDAR_FIELD)->get(patternCharIndex);
	for (;;) {
		if (pos->index >= $nc(text)->length()) {
			$nc(origPos)->errorIndex = start;
			return -1;
		}
		char16_t c = $nc(text)->charAt(pos->index);
		if (c != u' ' && c != u'\t') {
			break;
		}
		++pos->index;
	}
	int32_t actualStart = pos->index;
	bool parsing$break = false;
	for (;;) {
		{
			if (patternCharIndex == 4 || patternCharIndex == 15 || (patternCharIndex == 2 && count <= 2) || (patternCharIndex == 22 && count <= 2) || patternCharIndex == 1 || patternCharIndex == 19) {
				if (obeyCount) {
					if ((start + count) > $nc(text)->length()) {
						parsing$break = true;
						break;
					}
					$assign(number, $nc(this->numberFormat)->parse($($nc(text)->substring(0, start + count)), pos));
				} else {
					$assign(number, $nc(this->numberFormat)->parse(text, pos));
				}
				if (number == nullptr) {
					if (patternCharIndex != 1 || $instanceOf($GregorianCalendar, this->calendar)) {
						parsing$break = true;
						break;
					}
				} else {
					value = $nc(number)->intValue();
					bool var$0 = useFollowingMinusSignAsDelimiter && (value < 0);
					if (var$0) {
						bool var$2 = (pos->index < $nc(text)->length());
						bool var$1 = (var$2 && (text->charAt(pos->index) != this->minusSign));
						if (!var$1) {
							bool var$3 = (pos->index == $nc(text)->length());
							var$1 = (var$3 && (text->charAt(pos->index - 1) == this->minusSign));
						}
						var$0 = (var$1);
					}
					if (var$0) {
						value = -value;
						--pos->index;
					}
				}
			}
			bool useDateFormatSymbols = this->useDateFormatSymbols();
			int32_t index = 0;
			{
				$var($Map, maps, nullptr)
				switch (patternCharIndex) {
				case 0:
					{
						if (useDateFormatSymbols) {
							if ((index = matchString(text, start, $Calendar::ERA, $($nc(this->formatData)->getEras()), calb)) > 0) {
								return index;
							}
						} else {
							$var($Map, map, getDisplayNamesMap(field, this->locale));
							if ((index = matchString(text, start, field, map, calb)) > 0) {
								return index;
							}
						}
						parsing$break = true;
						break;
					}
				case 19:
					{}
				case 1:
					{
						if (!($instanceOf($GregorianCalendar, this->calendar))) {
							int32_t style = (count >= 4) ? $Calendar::LONG : $Calendar::SHORT;
							$var($Map, map, $nc(this->calendar)->getDisplayNames(field, style, this->locale));
							if (map != nullptr) {
								if ((index = matchString(text, start, field, map, calb)) > 0) {
									return index;
								}
							}
							$nc(calb)->set(field, value);
							return pos->index;
						}
						bool var$4 = count <= 2 && (pos->index - actualStart) == 2 && $Character::isDigit($nc(text)->charAt(actualStart));
						if (var$4 && $Character::isDigit($nc(text)->charAt(actualStart + 1))) {
							int32_t ambiguousTwoDigitYear = this->defaultCenturyStartYear % 100;
							$nc(ambiguousYear)->set(0, value == ambiguousTwoDigitYear);
							value += (this->defaultCenturyStartYear / 100) * 100 + (value < ambiguousTwoDigitYear ? 100 : 0);
						}
						$nc(calb)->set(field, value);
						return pos->index;
					}
				case 2:
					{
						if (count <= 2) {
							$nc(calb)->set($Calendar::MONTH, value - 1);
							return pos->index;
						}
						if (useDateFormatSymbols) {
							int32_t newStart = 0;
							if ((newStart = matchString(text, start, $Calendar::MONTH, $($nc(this->formatData)->getMonths()), calb)) > 0) {
								return newStart;
							}
							if ((index = matchString(text, start, $Calendar::MONTH, $($nc(this->formatData)->getShortMonths()), calb)) > 0) {
								return index;
							}
						} else {
							$var($Map, map, getDisplayContextNamesMap(field, this->locale));
							if ((index = matchString(text, start, field, map, calb)) > 0) {
								return index;
							}
						}
						parsing$break = true;
						break;
					}
				case 22:
					{
						if (count <= 2) {
							$nc(calb)->set($Calendar::MONTH, value - 1);
							return pos->index;
						}
						$assign(maps, getDisplayNamesMap(field, this->locale));
						if ((index = matchString(text, start, field, maps, calb)) > 0) {
							return index;
						}
						parsing$break = true;
						break;
					}
				case 4:
					{
						if (!isLenient()) {
							if (value < 1 || value > 24) {
								parsing$break = true;
								break;
							}
						}
						if (value == $nc(this->calendar)->getMaximum($Calendar::HOUR_OF_DAY) + 1) {
							value = 0;
						}
						$nc(calb)->set($Calendar::HOUR_OF_DAY, value);
						return pos->index;
					}
				case 9:
					{
						{
							if (useDateFormatSymbols) {
								int32_t newStart = 0;
								if ((newStart = matchString(text, start, $Calendar::DAY_OF_WEEK, $($nc(this->formatData)->getWeekdays()), calb)) > 0) {
									return newStart;
								}
								if ((index = matchString(text, start, $Calendar::DAY_OF_WEEK, $($nc(this->formatData)->getShortWeekdays()), calb)) > 0) {
									return index;
								}
							} else {
								$var($ints, styles, $new($ints, {
									$Calendar::LONG,
									$Calendar::SHORT
								}));
								{
									$var($ints, arr$, styles);
									int32_t len$ = arr$->length;
									int32_t i$ = 0;
									for (; i$ < len$; ++i$) {
										int32_t style = arr$->get(i$);
										{
											$var($Map, map, $nc(this->calendar)->getDisplayNames(field, style, this->locale));
											if ((index = matchString(text, start, field, map, calb)) > 0) {
												return index;
											}
										}
									}
								}
							}
						}
						parsing$break = true;
						break;
					}
				case 14:
					{
						if (useDateFormatSymbols) {
							if ((index = matchString(text, start, $Calendar::AM_PM, $($nc(this->formatData)->getAmPmStrings()), calb)) > 0) {
								return index;
							}
						} else {
							$var($Map, map, getDisplayNamesMap(field, this->locale));
							if ((index = matchString(text, start, field, map, calb)) > 0) {
								return index;
							}
						}
						parsing$break = true;
						break;
					}
				case 15:
					{
						if (!isLenient()) {
							if (value < 1 || value > 12) {
								parsing$break = true;
								break;
							}
						}
						if (value == $nc(this->calendar)->getLeastMaximum($Calendar::HOUR) + 1) {
							value = 0;
						}
						$nc(calb)->set($Calendar::HOUR, value);
						return pos->index;
					}
				case 17:
					{}
				case 18:
					{
						{
							int32_t sign = 0;
							try {
								char16_t c = $nc(text)->charAt(pos->index);
								if (c == u'+') {
									sign = 1;
								} else if (c == u'-') {
									sign = -1;
								}
								if (sign == 0) {
									bool var$6 = (c == u'G' || c == u'g');
									if (var$6) {
										int32_t var$7 = (text->length() - start);
										var$6 = var$7 >= $nc(SimpleDateFormat::GMT)->length();
									}
									bool var$5 = var$6;
									if (var$5 && text->regionMatches(true, start, SimpleDateFormat::GMT, 0, $nc(SimpleDateFormat::GMT)->length())) {
										pos->index = start + $nc(SimpleDateFormat::GMT)->length();
										if ((text->length() - pos->index) > 0) {
											c = text->charAt(pos->index);
											if (c == u'+') {
												sign = 1;
											} else if (c == u'-') {
												sign = -1;
											}
										}
										if (sign == 0) {
											$nc($($nc(calb)->set($Calendar::ZONE_OFFSET, 0)))->set($Calendar::DST_OFFSET, 0);
											return pos->index;
										}
										int32_t i = subParseNumericZone(text, ++pos->index, sign, 0, true, calb);
										if (i > 0) {
											return i;
										}
										pos->index = -i;
									} else {
										int32_t i = subParseZoneString(text, pos->index, calb);
										if (i > 0) {
											return i;
										}
										pos->index = -i;
									}
								} else {
									int32_t i = subParseNumericZone(text, ++pos->index, sign, 0, false, calb);
									if (i > 0) {
										return i;
									}
									pos->index = -i;
								}
							} catch ($IndexOutOfBoundsException& e) {
							}
						}
						parsing$break = true;
						break;
					}
				case 21:
					{
						{
							if (($nc(text)->length() - pos->index) <= 0) {
								parsing$break = true;
								break;
							}
							int32_t sign = 0;
							char16_t c = $nc(text)->charAt(pos->index);
							if (c == u'Z') {
								$nc($($nc(calb)->set($Calendar::ZONE_OFFSET, 0)))->set($Calendar::DST_OFFSET, 0);
								return ++pos->index;
							}
							if (c == u'+') {
								sign = 1;
							} else if (c == u'-') {
								sign = -1;
							} else {
								++pos->index;
								parsing$break = true;
								break;
							}
							int32_t i = subParseNumericZone(text, ++pos->index, sign, count, count == 3, calb);
							if (i > 0) {
								return i;
							}
							pos->index = -i;
						}
						parsing$break = true;
						break;
					}
				default:
					{
						if (obeyCount) {
							if ((start + count) > $nc(text)->length()) {
								parsing$break = true;
								break;
							}
							$assign(number, $nc(this->numberFormat)->parse($($nc(text)->substring(0, start + count)), pos));
						} else {
							$assign(number, $nc(this->numberFormat)->parse(text, pos));
						}
						if (number != nullptr) {
							value = number->intValue();
							bool var$8 = useFollowingMinusSignAsDelimiter && (value < 0);
							if (var$8) {
								bool var$10 = (pos->index < $nc(text)->length());
								bool var$9 = (var$10 && (text->charAt(pos->index) != this->minusSign));
								if (!var$9) {
									bool var$11 = (pos->index == $nc(text)->length());
									var$9 = (var$11 && (text->charAt(pos->index - 1) == this->minusSign));
								}
								var$8 = (var$9);
							}
							if (var$8) {
								value = -value;
								--pos->index;
							}
							$nc(calb)->set(field, value);
							return pos->index;
						}
						parsing$break = true;
						break;
					}
				}

				if (parsing$break) {
					break;
				}			}
		}
		break;
	}
	$nc(origPos)->errorIndex = pos->index;
	return -1;
}

bool SimpleDateFormat::useDateFormatSymbols() {
	return this->useDateFormatSymbols$ || this->locale == nullptr;
}

$String* SimpleDateFormat::translatePattern($String* pattern, $String* from, $String* to) {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, result, $new($StringBuilder));
	bool inQuote = false;
	for (int32_t i = 0; i < $nc(pattern)->length(); ++i) {
		char16_t c = pattern->charAt(i);
		if (inQuote) {
			if (c == u'\'') {
				inQuote = false;
			}
		} else if (c == u'\'') {
			inQuote = true;
		} else if ((c >= u'a' && c <= u'z') || (c >= u'A' && c <= u'Z')) {
			int32_t ci = $nc(from)->indexOf((int32_t)c);
			if (ci >= 0) {
				if (ci < $nc(to)->length()) {
					c = to->charAt(ci);
				}
			} else {
				$throwNew($IllegalArgumentException, $$str({"Illegal pattern  character \'"_s, $$str(c), "\'"_s}));
			}
		}
		result->append(c);
	}
	if (inQuote) {
		$throwNew($IllegalArgumentException, "Unfinished quote in pattern"_s);
	}
	return result->toString();
}

$String* SimpleDateFormat::toPattern() {
	return this->pattern;
}

$String* SimpleDateFormat::toLocalizedPattern() {
	$init($DateFormatSymbols);
	return translatePattern(this->pattern, $DateFormatSymbols::patternChars, $($nc(this->formatData)->getLocalPatternChars()));
}

void SimpleDateFormat::applyPattern($String* pattern) {
	applyPatternImpl(pattern);
}

void SimpleDateFormat::applyPatternImpl($String* pattern) {
	$set(this, compiledPattern, compile(pattern));
	$set(this, pattern, pattern);
}

void SimpleDateFormat::applyLocalizedPattern($String* pattern) {
	$useLocalCurrentObjectStackCache();
	$init($DateFormatSymbols);
	$var($String, p, translatePattern(pattern, $($nc(this->formatData)->getLocalPatternChars()), $DateFormatSymbols::patternChars));
	$set(this, compiledPattern, compile(p));
	$set(this, pattern, p);
}

$DateFormatSymbols* SimpleDateFormat::getDateFormatSymbols() {
	return $cast($DateFormatSymbols, $nc(this->formatData)->clone());
}

void SimpleDateFormat::setDateFormatSymbols($DateFormatSymbols* newFormatSymbols) {
	$set(this, formatData, $cast($DateFormatSymbols, $nc(newFormatSymbols)->clone()));
	this->useDateFormatSymbols$ = true;
}

$Object* SimpleDateFormat::clone() {
	$var(SimpleDateFormat, other, $cast(SimpleDateFormat, $DateFormat::clone()));
	$set($nc(other), formatData, $cast($DateFormatSymbols, $nc(this->formatData)->clone()));
	return $of(other);
}

int32_t SimpleDateFormat::hashCode() {
	return $nc(this->pattern)->hashCode();
}

bool SimpleDateFormat::equals(Object$* obj) {
	if (!$DateFormat::equals(obj)) {
		return false;
	}
	$var(SimpleDateFormat, that, $cast(SimpleDateFormat, obj));
	bool var$0 = $nc(this->pattern)->equals($nc(that)->pattern);
	return (var$0 && $nc(this->formatData)->equals($nc(that)->formatData));
}

$Map* SimpleDateFormat::getDisplayNamesMap(int32_t field, $Locale* locale) {
	$useLocalCurrentObjectStackCache();
	$var($Map, map, $nc(this->calendar)->getDisplayNames(field, $Calendar::SHORT_FORMAT, locale));
	{
		$var($ints, arr$, SimpleDateFormat::REST_OF_STYLES);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			int32_t style = arr$->get(i$);
			{
				$var($Map, m, $nc(this->calendar)->getDisplayNames(field, style, locale));
				if (m != nullptr) {
					$nc(map)->putAll(m);
				}
			}
		}
	}
	return map;
}

$Map* SimpleDateFormat::getDisplayContextNamesMap(int32_t field, $Locale* locale) {
	$useLocalCurrentObjectStackCache();
	$var($Map, map, $nc(this->calendar)->getDisplayNames(field, this->forceStandaloneForm ? $Calendar::SHORT_STANDALONE : $Calendar::SHORT_FORMAT, locale));
	$var($Map, m, $nc(this->calendar)->getDisplayNames(field, this->forceStandaloneForm ? $Calendar::LONG_STANDALONE : $Calendar::LONG_FORMAT, locale));
	if (m != nullptr) {
		$nc(map)->putAll(m);
	}
	return map;
}

void SimpleDateFormat::readObject($ObjectInputStream* stream) {
	$useLocalCurrentObjectStackCache();
	$nc(stream)->defaultReadObject();
	try {
		$set(this, compiledPattern, compile(this->pattern));
	} catch ($Exception& e) {
		$throwNew($InvalidObjectException, "invalid pattern"_s);
	}
	if (this->serialVersionOnStream < 1) {
		initializeDefaultCentury();
	} else {
		parseAmbiguousDatesAsAfter(this->defaultCenturyStart);
	}
	this->serialVersionOnStream = SimpleDateFormat::currentSerialVersion;
	$var($TimeZone, tz, getTimeZone());
	if ($instanceOf($SimpleTimeZone, tz)) {
		$var($String, id, $nc(tz)->getID());
		$var($TimeZone, zi, $TimeZone::getTimeZone(id));
		bool var$0 = zi != nullptr && zi->hasSameRules(tz);
		if (var$0 && $nc($(zi->getID()))->equals(id)) {
			setTimeZone(zi);
		}
	}
}

void SimpleDateFormat::checkNegativeNumberExpression() {
	$useLocalCurrentObjectStackCache();
	if (($instanceOf($DecimalFormat, this->numberFormat)) && !$nc(this->numberFormat)->equals(this->originalNumberFormat)) {
		$var($String, numberPattern, $nc(($cast($DecimalFormat, this->numberFormat)))->toPattern());
		if (!$nc(numberPattern)->equals(this->originalNumberPattern)) {
			this->hasFollowingMinusSign = false;
			int32_t separatorIndex = numberPattern->indexOf((int32_t)u';');
			if (separatorIndex > -1) {
				int32_t minusIndex = numberPattern->indexOf((int32_t)u'-', separatorIndex);
				bool var$0 = (minusIndex > numberPattern->lastIndexOf((int32_t)u'0'));
				if (var$0 && (minusIndex > numberPattern->lastIndexOf((int32_t)u'#'))) {
					this->hasFollowingMinusSign = true;
					this->minusSign = $nc($($nc(($cast($DecimalFormat, this->numberFormat)))->getDecimalFormatSymbols()))->getMinusSign();
				}
			}
			$set(this, originalNumberPattern, numberPattern);
		}
		$set(this, originalNumberFormat, this->numberFormat);
	}
}

void clinit$SimpleDateFormat($Class* class$) {
	$assignStatic(SimpleDateFormat::GMT, "GMT"_s);
	SimpleDateFormat::$assertionsDisabled = !SimpleDateFormat::class$->desiredAssertionStatus();
	$assignStatic(SimpleDateFormat::cachedNumberFormatData, $new($ConcurrentHashMap, 3));
	$assignStatic(SimpleDateFormat::PATTERN_INDEX_TO_CALENDAR_FIELD, $new($ints, {
		$Calendar::ERA,
		$Calendar::YEAR,
		$Calendar::MONTH,
		$Calendar::DATE,
		$Calendar::HOUR_OF_DAY,
		$Calendar::HOUR_OF_DAY,
		$Calendar::MINUTE,
		$Calendar::SECOND,
		$Calendar::MILLISECOND,
		$Calendar::DAY_OF_WEEK,
		$Calendar::DAY_OF_YEAR,
		$Calendar::DAY_OF_WEEK_IN_MONTH,
		$Calendar::WEEK_OF_YEAR,
		$Calendar::WEEK_OF_MONTH,
		$Calendar::AM_PM,
		$Calendar::HOUR,
		$Calendar::HOUR,
		$Calendar::ZONE_OFFSET,
		$Calendar::ZONE_OFFSET,
		$CalendarBuilder::WEEK_YEAR,
		$CalendarBuilder::ISO_DAY_OF_WEEK,
		$Calendar::ZONE_OFFSET,
		$Calendar::MONTH
	}));
	$assignStatic(SimpleDateFormat::PATTERN_INDEX_TO_DATE_FORMAT_FIELD, $new($ints, {
		$DateFormat::ERA_FIELD,
		$DateFormat::YEAR_FIELD,
		$DateFormat::MONTH_FIELD,
		$DateFormat::DATE_FIELD,
		$DateFormat::HOUR_OF_DAY1_FIELD,
		$DateFormat::HOUR_OF_DAY0_FIELD,
		$DateFormat::MINUTE_FIELD,
		$DateFormat::SECOND_FIELD,
		$DateFormat::MILLISECOND_FIELD,
		$DateFormat::DAY_OF_WEEK_FIELD,
		$DateFormat::DAY_OF_YEAR_FIELD,
		$DateFormat::DAY_OF_WEEK_IN_MONTH_FIELD,
		$DateFormat::WEEK_OF_YEAR_FIELD,
		$DateFormat::WEEK_OF_MONTH_FIELD,
		$DateFormat::AM_PM_FIELD,
		$DateFormat::HOUR1_FIELD,
		$DateFormat::HOUR0_FIELD,
		$DateFormat::TIMEZONE_FIELD,
		$DateFormat::TIMEZONE_FIELD,
		$DateFormat::YEAR_FIELD,
		$DateFormat::DAY_OF_WEEK_FIELD,
		$DateFormat::TIMEZONE_FIELD,
		$DateFormat::MONTH_FIELD
	}));
	$init($DateFormat$Field);
	$assignStatic(SimpleDateFormat::PATTERN_INDEX_TO_DATE_FORMAT_FIELD_ID, $new($DateFormat$FieldArray, {
		$DateFormat$Field::ERA,
		$DateFormat$Field::YEAR,
		$DateFormat$Field::MONTH,
		$DateFormat$Field::DAY_OF_MONTH,
		$DateFormat$Field::HOUR_OF_DAY1,
		$DateFormat$Field::HOUR_OF_DAY0,
		$DateFormat$Field::MINUTE,
		$DateFormat$Field::SECOND,
		$DateFormat$Field::MILLISECOND,
		$DateFormat$Field::DAY_OF_WEEK,
		$DateFormat$Field::DAY_OF_YEAR,
		$DateFormat$Field::DAY_OF_WEEK_IN_MONTH,
		$DateFormat$Field::WEEK_OF_YEAR,
		$DateFormat$Field::WEEK_OF_MONTH,
		$DateFormat$Field::AM_PM,
		$DateFormat$Field::HOUR1,
		$DateFormat$Field::HOUR0,
		$DateFormat$Field::TIME_ZONE,
		$DateFormat$Field::TIME_ZONE,
		$DateFormat$Field::YEAR,
		$DateFormat$Field::DAY_OF_WEEK,
		$DateFormat$Field::TIME_ZONE,
		$DateFormat$Field::MONTH
	}));
	$assignStatic(SimpleDateFormat::REST_OF_STYLES, $new($ints, {
		$Calendar::SHORT_STANDALONE,
		$Calendar::LONG_FORMAT,
		$Calendar::LONG_STANDALONE
	}));
}

SimpleDateFormat::SimpleDateFormat() {
}

$Class* SimpleDateFormat::load$($String* name, bool initialize) {
	$loadClass(SimpleDateFormat, name, initialize, &_SimpleDateFormat_ClassInfo_, clinit$SimpleDateFormat, allocate$SimpleDateFormat);
	return class$;
}

$Class* SimpleDateFormat::class$ = nullptr;

	} // text
} // java