#include <java/util/Formatter$FormatSpecifier.h>

#include <java/lang/Appendable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/CharSequence.h>
#include <java/lang/Math.h>
#include <java/lang/NumberFormatException.h>
#include <java/math/BigDecimal.h>
#include <java/math/BigInteger.h>
#include <java/math/MathContext.h>
#include <java/math/RoundingMode.h>
#include <java/text/DateFormatSymbols.h>
#include <java/text/DecimalFormat.h>
#include <java/text/DecimalFormatSymbols.h>
#include <java/text/NumberFormat.h>
#include <java/text/spi/NumberFormatProvider.h>
#include <java/time/DateTimeException.h>
#include <java/time/Instant.h>
#include <java/time/ZoneId.h>
#include <java/time/ZoneOffset.h>
#include <java/time/temporal/ChronoField.h>
#include <java/time/temporal/TemporalAccessor.h>
#include <java/time/temporal/TemporalField.h>
#include <java/time/temporal/TemporalQueries.h>
#include <java/time/temporal/TemporalQuery.h>
#include <java/time/temporal/UnsupportedTemporalTypeException.h>
#include <java/time/zone/ZoneRules.h>
#include <java/util/Calendar.h>
#include <java/util/Date.h>
#include <java/util/FormatFlagsConversionMismatchException.h>
#include <java/util/Formattable.h>
#include <java/util/Formatter$BigDecimalLayoutForm.h>
#include <java/util/Formatter$Conversion.h>
#include <java/util/Formatter$DateTime.h>
#include <java/util/Formatter$Flags.h>
#include <java/util/Formatter$FormatSpecifier$BigDecimalLayout.h>
#include <java/util/Formatter.h>
#include <java/util/IllegalFormatArgumentIndexException.h>
#include <java/util/IllegalFormatCodePointException.h>
#include <java/util/IllegalFormatConversionException.h>
#include <java/util/IllegalFormatFlagsException.h>
#include <java/util/IllegalFormatPrecisionException.h>
#include <java/util/IllegalFormatWidthException.h>
#include <java/util/Locale$Category.h>
#include <java/util/Locale.h>
#include <java/util/MissingFormatWidthException.h>
#include <java/util/Objects.h>
#include <java/util/TimeZone.h>
#include <java/util/UnknownFormatConversionException.h>
#include <java/util/regex/Matcher.h>
#include <jdk/internal/math/DoubleConsts.h>
#include <jdk/internal/math/FormattedFloatingDecimal$Form.h>
#include <jdk/internal/math/FormattedFloatingDecimal.h>
#include <sun/util/locale/provider/LocaleProviderAdapter.h>
#include <sun/util/locale/provider/LocaleResources.h>
#include <sun/util/locale/provider/ResourceBundleBasedAdapter.h>
#include <jcpp.h>

#undef ALTERNATE
#undef AMPM_OF_DAY
#undef AM_PM
#undef BOOLEAN
#undef CENTURY
#undef CHARACTER
#undef CLOCK_HOUR_OF_AMPM
#undef DATE
#undef DATE_TIME
#undef DAY_OF_MONTH
#undef DAY_OF_MONTH_0
#undef DAY_OF_WEEK
#undef DAY_OF_YEAR
#undef DECIMAL_FLOAT
#undef DECIMAL_INTEGER
#undef DST_OFFSET
#undef EXP_BIT_MASK
#undef FORMAT
#undef GENERAL
#undef GROUP
#undef HALF_UP
#undef HASHCODE
#undef HEXADECIMAL_FLOAT
#undef HEXADECIMAL_INTEGER
#undef HOUR
#undef HOUR_0
#undef HOUR_OF_DAY
#undef HOUR_OF_DAY_0
#undef INSTANT_SECONDS
#undef ISO_STANDARD_DATE
#undef LEADING_SPACE
#undef LEFT_JUSTIFY
#undef LINE_SEPARATOR
#undef MAX_EXPONENT
#undef MILLISECOND
#undef MILLISECOND_SINCE_EPOCH
#undef MILLI_OF_SECOND
#undef MINUTE
#undef MINUTE_OF_HOUR
#undef MIN_EXPONENT
#undef MIN_VALUE
#undef MONTH
#undef MONTH_OF_YEAR
#undef NAME_OF_DAY
#undef NAME_OF_DAY_ABBREV
#undef NAME_OF_MONTH
#undef NAME_OF_MONTH_ABBREV
#undef NAME_OF_MONTH_ABBREV_X
#undef NANOSECOND
#undef NANO_OF_SECOND
#undef NONE
#undef OCTAL_INTEGER
#undef OFFSET_SECONDS
#undef PARENTHESES
#undef PERCENT_SIGN
#undef PLUS
#undef PREVIOUS
#undef ROOT
#undef SCIENTIFIC
#undef SECOND
#undef SECONDS_SINCE_EPOCH
#undef SECOND_OF_MINUTE
#undef SHORT
#undef SIGNIFICAND_WIDTH
#undef SIGNIF_BIT_MASK
#undef SIGN_BIT_MASK
#undef STRING
#undef TIME
#undef TIME_12_HOUR
#undef TIME_24_HOUR
#undef UPPERCASE
#undef US
#undef YEAR
#undef YEAR_2
#undef YEAR_4
#undef YEAR_OF_ERA
#undef ZERO
#undef ZERO_PAD
#undef ZONE
#undef ZONE_NUMERIC
#undef ZONE_OFFSET

using $Formatter$FlagsArray = $Array<::java::util::Formatter$Flags>;
using $Appendable = ::java::lang::Appendable;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $Byte = ::java::lang::Byte;
using $CharSequence = ::java::lang::CharSequence;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $Double = ::java::lang::Double;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $Short = ::java::lang::Short;
using $BigDecimal = ::java::math::BigDecimal;
using $BigInteger = ::java::math::BigInteger;
using $MathContext = ::java::math::MathContext;
using $RoundingMode = ::java::math::RoundingMode;
using $DateFormatSymbols = ::java::text::DateFormatSymbols;
using $DecimalFormat = ::java::text::DecimalFormat;
using $DecimalFormatSymbols = ::java::text::DecimalFormatSymbols;
using $NumberFormat = ::java::text::NumberFormat;
using $NumberFormatProvider = ::java::text::spi::NumberFormatProvider;
using $DateTimeException = ::java::time::DateTimeException;
using $Instant = ::java::time::Instant;
using $ZoneId = ::java::time::ZoneId;
using $ZoneOffset = ::java::time::ZoneOffset;
using $ChronoField = ::java::time::temporal::ChronoField;
using $TemporalAccessor = ::java::time::temporal::TemporalAccessor;
using $TemporalField = ::java::time::temporal::TemporalField;
using $TemporalQueries = ::java::time::temporal::TemporalQueries;
using $UnsupportedTemporalTypeException = ::java::time::temporal::UnsupportedTemporalTypeException;
using $ZoneRules = ::java::time::zone::ZoneRules;
using $Calendar = ::java::util::Calendar;
using $Date = ::java::util::Date;
using $FormatFlagsConversionMismatchException = ::java::util::FormatFlagsConversionMismatchException;
using $Formattable = ::java::util::Formattable;
using $Formatter = ::java::util::Formatter;
using $Formatter$BigDecimalLayoutForm = ::java::util::Formatter$BigDecimalLayoutForm;
using $Formatter$Conversion = ::java::util::Formatter$Conversion;
using $Formatter$DateTime = ::java::util::Formatter$DateTime;
using $Formatter$Flags = ::java::util::Formatter$Flags;
using $Formatter$FormatSpecifier$BigDecimalLayout = ::java::util::Formatter$FormatSpecifier$BigDecimalLayout;
using $IllegalFormatArgumentIndexException = ::java::util::IllegalFormatArgumentIndexException;
using $IllegalFormatCodePointException = ::java::util::IllegalFormatCodePointException;
using $IllegalFormatConversionException = ::java::util::IllegalFormatConversionException;
using $IllegalFormatFlagsException = ::java::util::IllegalFormatFlagsException;
using $IllegalFormatPrecisionException = ::java::util::IllegalFormatPrecisionException;
using $IllegalFormatWidthException = ::java::util::IllegalFormatWidthException;
using $Locale = ::java::util::Locale;
using $Locale$Category = ::java::util::Locale$Category;
using $MissingFormatWidthException = ::java::util::MissingFormatWidthException;
using $Objects = ::java::util::Objects;
using $TimeZone = ::java::util::TimeZone;
using $UnknownFormatConversionException = ::java::util::UnknownFormatConversionException;
using $Matcher = ::java::util::regex::Matcher;
using $DoubleConsts = ::jdk::internal::math::DoubleConsts;
using $FormattedFloatingDecimal = ::jdk::internal::math::FormattedFloatingDecimal;
using $FormattedFloatingDecimal$Form = ::jdk::internal::math::FormattedFloatingDecimal$Form;
using $LocaleProviderAdapter = ::sun::util::locale::provider::LocaleProviderAdapter;
using $LocaleResources = ::sun::util::locale::provider::LocaleResources;
using $ResourceBundleBasedAdapter = ::sun::util::locale::provider::ResourceBundleBasedAdapter;

namespace java {
	namespace util {

$FieldInfo _Formatter$FormatSpecifier_FieldInfo_[] = {
	{"this$0", "Ljava/util/Formatter;", nullptr, $FINAL | $SYNTHETIC, $field(Formatter$FormatSpecifier, this$0)},
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Formatter$FormatSpecifier, $assertionsDisabled)},
	{"index", "I", nullptr, $PRIVATE, $field(Formatter$FormatSpecifier, index$)},
	{"f", "Ljava/util/Formatter$Flags;", nullptr, $PRIVATE, $field(Formatter$FormatSpecifier, f)},
	{"width", "I", nullptr, $PRIVATE, $field(Formatter$FormatSpecifier, width$)},
	{"precision", "I", nullptr, $PRIVATE, $field(Formatter$FormatSpecifier, precision$)},
	{"dt", "Z", nullptr, $PRIVATE, $field(Formatter$FormatSpecifier, dt)},
	{"c", "C", nullptr, $PRIVATE, $field(Formatter$FormatSpecifier, c)},
	{}
};

$MethodInfo _Formatter$FormatSpecifier_MethodInfo_[] = {
	{"<init>", "(Ljava/util/Formatter;C)V", nullptr, 0, $method(Formatter$FormatSpecifier, init$, void, $Formatter*, char16_t)},
	{"<init>", "(Ljava/util/Formatter;Ljava/lang/String;Ljava/util/regex/Matcher;)V", nullptr, 0, $method(Formatter$FormatSpecifier, init$, void, $Formatter*, $String*, $Matcher*)},
	{"addZeros", "(Ljava/lang/StringBuilder;I)V", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, addZeros, void, $StringBuilder*, int32_t)},
	{"adjustWidth", "(ILjava/util/Formatter$Flags;Z)I", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, adjustWidth, int32_t, int32_t, $Formatter$Flags*, bool)},
	{"appendJustified", "(Ljava/lang/Appendable;Ljava/lang/CharSequence;)V", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, appendJustified, void, $Appendable*, $CharSequence*), "java.io.IOException"},
	{"checkBadFlags", "([Ljava/util/Formatter$Flags;)V", nullptr, $PRIVATE | $TRANSIENT, $method(Formatter$FormatSpecifier, checkBadFlags, void, $Formatter$FlagsArray*)},
	{"checkCharacter", "()V", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, checkCharacter, void)},
	{"checkDateTime", "()V", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, checkDateTime, void)},
	{"checkFloat", "()V", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, checkFloat, void)},
	{"checkGeneral", "()V", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, checkGeneral, void)},
	{"checkInteger", "()V", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, checkInteger, void)},
	{"checkNumeric", "()V", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, checkNumeric, void)},
	{"checkText", "()V", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, checkText, void)},
	{"conversion", "(C)V", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, conversion, void, char16_t)},
	{"failConversion", "(CLjava/lang/Object;)V", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, failConversion, void, char16_t, Object$*)},
	{"failMismatch", "(Ljava/util/Formatter$Flags;C)V", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, failMismatch, void, $Formatter$Flags*, char16_t)},
	{"flags", "(Ljava/lang/String;II)V", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, flags, void, $String*, int32_t, int32_t)},
	{"getZero", "(Ljava/util/Locale;)C", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, getZero, char16_t, $Locale*)},
	{"hexDouble", "(DI)Ljava/lang/String;", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, hexDouble, $String*, double, int32_t)},
	{"index", "(Ljava/lang/String;II)V", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, index, void, $String*, int32_t, int32_t)},
	{"index", "()I", nullptr, $PUBLIC, $virtualMethod(Formatter$FormatSpecifier, index, int32_t)},
	{"leadingSign", "(Ljava/lang/StringBuilder;Z)Ljava/lang/StringBuilder;", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, leadingSign, $StringBuilder*, $StringBuilder*, bool)},
	{"localizedMagnitude", "(Ljava/lang/StringBuilder;JLjava/util/Formatter$Flags;ILjava/util/Locale;)Ljava/lang/StringBuilder;", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, localizedMagnitude, $StringBuilder*, $StringBuilder*, int64_t, $Formatter$Flags*, int32_t, $Locale*)},
	{"localizedMagnitude", "(Ljava/lang/StringBuilder;Ljava/lang/CharSequence;ILjava/util/Formatter$Flags;ILjava/util/Locale;)Ljava/lang/StringBuilder;", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, localizedMagnitude, $StringBuilder*, $StringBuilder*, $CharSequence*, int32_t, $Formatter$Flags*, int32_t, $Locale*)},
	{"localizedMagnitudeExp", "(Ljava/lang/StringBuilder;[CILjava/util/Locale;)V", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, localizedMagnitudeExp, void, $StringBuilder*, $chars*, int32_t, $Locale*)},
	{"precision", "(Ljava/lang/String;II)V", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, precision, void, $String*, int32_t, int32_t)},
	{"print", "(Ljava/lang/Object;Ljava/util/Locale;)V", nullptr, $PUBLIC, $virtualMethod(Formatter$FormatSpecifier, print, void, Object$*, $Locale*), "java.io.IOException"},
	{"print", "(Ljava/lang/String;Ljava/util/Locale;)V", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, print, void, $String*, $Locale*), "java.io.IOException"},
	{"print", "(BLjava/util/Locale;)V", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, print, void, int8_t, $Locale*), "java.io.IOException"},
	{"print", "(SLjava/util/Locale;)V", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, print, void, int16_t, $Locale*), "java.io.IOException"},
	{"print", "(ILjava/util/Locale;)V", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, print, void, int32_t, $Locale*), "java.io.IOException"},
	{"print", "(JLjava/util/Locale;)V", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, print, void, int64_t, $Locale*), "java.io.IOException"},
	{"print", "(Ljava/math/BigInteger;Ljava/util/Locale;)V", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, print, void, $BigInteger*, $Locale*), "java.io.IOException"},
	{"print", "(FLjava/util/Locale;)V", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, print, void, float, $Locale*), "java.io.IOException"},
	{"print", "(DLjava/util/Locale;)V", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, print, void, double, $Locale*), "java.io.IOException"},
	{"print", "(Ljava/lang/StringBuilder;DLjava/util/Locale;Ljava/util/Formatter$Flags;CIZ)V", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, print, void, $StringBuilder*, double, $Locale*, $Formatter$Flags*, char16_t, int32_t, bool), "java.io.IOException"},
	{"print", "(Ljava/math/BigDecimal;Ljava/util/Locale;)V", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, print, void, $BigDecimal*, $Locale*), "java.io.IOException"},
	{"print", "(Ljava/lang/StringBuilder;Ljava/math/BigDecimal;Ljava/util/Locale;Ljava/util/Formatter$Flags;CIZ)V", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, print, void, $StringBuilder*, $BigDecimal*, $Locale*, $Formatter$Flags*, char16_t, int32_t, bool), "java.io.IOException"},
	{"print", "(Ljava/util/Calendar;CLjava/util/Locale;)V", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, print, void, $Calendar*, char16_t, $Locale*), "java.io.IOException"},
	{"print", "(Ljava/lang/StringBuilder;Ljava/util/Calendar;CLjava/util/Locale;)Ljava/lang/Appendable;", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, print, $Appendable*, $StringBuilder*, $Calendar*, char16_t, $Locale*), "java.io.IOException"},
	{"print", "(Ljava/time/temporal/TemporalAccessor;CLjava/util/Locale;)V", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, print, void, $TemporalAccessor*, char16_t, $Locale*), "java.io.IOException"},
	{"print", "(Ljava/lang/StringBuilder;Ljava/time/temporal/TemporalAccessor;CLjava/util/Locale;)Ljava/lang/Appendable;", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, print, $Appendable*, $StringBuilder*, $TemporalAccessor*, char16_t, $Locale*), "java.io.IOException"},
	{"printBoolean", "(Ljava/lang/Object;Ljava/util/Locale;)V", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, printBoolean, void, Object$*, $Locale*), "java.io.IOException"},
	{"printCharacter", "(Ljava/lang/Object;Ljava/util/Locale;)V", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, printCharacter, void, Object$*, $Locale*), "java.io.IOException"},
	{"printDateTime", "(Ljava/lang/Object;Ljava/util/Locale;)V", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, printDateTime, void, Object$*, $Locale*), "java.io.IOException"},
	{"printFloat", "(Ljava/lang/Object;Ljava/util/Locale;)V", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, printFloat, void, Object$*, $Locale*), "java.io.IOException"},
	{"printHashCode", "(Ljava/lang/Object;Ljava/util/Locale;)V", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, printHashCode, void, Object$*, $Locale*), "java.io.IOException"},
	{"printInteger", "(Ljava/lang/Object;Ljava/util/Locale;)V", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, printInteger, void, Object$*, $Locale*), "java.io.IOException"},
	{"printString", "(Ljava/lang/Object;Ljava/util/Locale;)V", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, printString, void, Object$*, $Locale*), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Formatter$FormatSpecifier, toString, $String*)},
	{"toUpperCaseWithLocale", "(Ljava/lang/String;Ljava/util/Locale;)Ljava/lang/String;", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, toUpperCaseWithLocale, $String*, $String*, $Locale*)},
	{"trailingSign", "(Ljava/lang/StringBuilder;Z)Ljava/lang/StringBuilder;", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, trailingSign, $StringBuilder*, $StringBuilder*, bool)},
	{"trailingZeros", "(Ljava/lang/StringBuilder;I)V", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, trailingZeros, void, $StringBuilder*, int32_t)},
	{"width", "(Ljava/lang/String;II)V", nullptr, $PRIVATE, $method(Formatter$FormatSpecifier, width, void, $String*, int32_t, int32_t)},
	{}
};

$InnerClassInfo _Formatter$FormatSpecifier_InnerClassesInfo_[] = {
	{"java.util.Formatter$FormatSpecifier", "java.util.Formatter", "FormatSpecifier", $PRIVATE},
	{"java.util.Formatter$FormatString", "java.util.Formatter", "FormatString", $PRIVATE | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.Formatter$FormatSpecifier$BigDecimalLayout", "java.util.Formatter$FormatSpecifier", "BigDecimalLayout", $PRIVATE},
	{}
};

$ClassInfo _Formatter$FormatSpecifier_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.Formatter$FormatSpecifier",
	"java.lang.Object",
	"java.util.Formatter$FormatString",
	_Formatter$FormatSpecifier_FieldInfo_,
	_Formatter$FormatSpecifier_MethodInfo_,
	nullptr,
	nullptr,
	_Formatter$FormatSpecifier_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.Formatter"
};

$Object* allocate$Formatter$FormatSpecifier($Class* clazz) {
	return $of($alloc(Formatter$FormatSpecifier));
}

bool Formatter$FormatSpecifier::$assertionsDisabled = false;

void Formatter$FormatSpecifier::index($String* s, int32_t start, int32_t end) {
	if (start >= 0) {
		try {
			this->index$ = $Integer::parseInt(s, start, end - 1, 10);
			if (this->index$ <= 0) {
				$throwNew($IllegalFormatArgumentIndexException, this->index$);
			}
		} catch ($NumberFormatException& x) {
			$throwNew($IllegalFormatArgumentIndexException, $Integer::MIN_VALUE);
		}
	}
}

int32_t Formatter$FormatSpecifier::index() {
	return this->index$;
}

void Formatter$FormatSpecifier::flags($String* s, int32_t start, int32_t end) {
	$set(this, f, $Formatter$Flags::parse(s, start, end));
	if ($nc(this->f)->contains($Formatter$Flags::PREVIOUS)) {
		this->index$ = -1;
	}
}

void Formatter$FormatSpecifier::width($String* s, int32_t start, int32_t end) {
	if (start >= 0) {
		try {
			this->width$ = $Integer::parseInt(s, start, end, 10);
			if (this->width$ < 0) {
				$throwNew($IllegalFormatWidthException, this->width$);
			}
		} catch ($NumberFormatException& x) {
			$throwNew($IllegalFormatWidthException, $Integer::MIN_VALUE);
		}
	}
}

void Formatter$FormatSpecifier::precision($String* s, int32_t start, int32_t end) {
	if (start >= 0) {
		try {
			this->precision$ = $Integer::parseInt(s, start + 1, end, 10);
			if (this->precision$ < 0) {
				$throwNew($IllegalFormatPrecisionException, this->precision$);
			}
		} catch ($NumberFormatException& x) {
			$throwNew($IllegalFormatPrecisionException, $Integer::MIN_VALUE);
		}
	}
}

void Formatter$FormatSpecifier::conversion(char16_t conv) {
	this->c = conv;
	if (!this->dt) {
		if (!$Formatter$Conversion::isValid(this->c)) {
			$throwNew($UnknownFormatConversionException, $($String::valueOf(this->c)));
		}
		if ($Character::isUpperCase(this->c)) {
			$init($Formatter$Flags);
			$nc(this->f)->add($Formatter$Flags::UPPERCASE);
			this->c = $Character::toLowerCase(this->c);
		}
		if ($Formatter$Conversion::isText(this->c)) {
			this->index$ = -2;
		}
	}
}

void Formatter$FormatSpecifier::init$($Formatter* this$0, char16_t conv) {
	$set(this, this$0, this$0);
	this->index$ = 0;
	$init($Formatter$Flags);
	$set(this, f, $Formatter$Flags::NONE);
	this->width$ = -1;
	this->precision$ = -1;
	this->dt = false;
	this->c = conv;
	if ($Character::isUpperCase(conv)) {
		$set(this, f, $Formatter$Flags::UPPERCASE);
		this->c = $Character::toLowerCase(conv);
	}
	if ($Formatter$Conversion::isText(conv)) {
		this->index$ = -2;
	}
}

void Formatter$FormatSpecifier::init$($Formatter* this$0, $String* s, $Matcher* m) {
	$useLocalCurrentObjectStackCache();
	$set(this, this$0, this$0);
	this->index$ = 0;
	$init($Formatter$Flags);
	$set(this, f, $Formatter$Flags::NONE);
	this->width$ = -1;
	this->precision$ = -1;
	this->dt = false;
	$var($String, var$0, s);
	int32_t var$1 = $nc(m)->start(1);
	index(var$0, var$1, m->end(1));
	$var($String, var$2, s);
	int32_t var$3 = $nc(m)->start(2);
	flags(var$2, var$3, m->end(2));
	$var($String, var$4, s);
	int32_t var$5 = $nc(m)->start(3);
	width(var$4, var$5, m->end(3));
	$var($String, var$6, s);
	int32_t var$7 = $nc(m)->start(4);
	precision(var$6, var$7, m->end(4));
	int32_t tTStart = $nc(m)->start(5);
	if (tTStart >= 0) {
		this->dt = true;
		if ($nc(s)->charAt(tTStart) == u'T') {
			$nc(this->f)->add($Formatter$Flags::UPPERCASE);
		}
	}
	conversion($nc(s)->charAt(m->start(6)));
	if (this->dt) {
		checkDateTime();
	} else if ($Formatter$Conversion::isGeneral(this->c)) {
		checkGeneral();
	} else if ($Formatter$Conversion::isCharacter(this->c)) {
		checkCharacter();
	} else if ($Formatter$Conversion::isInteger(this->c)) {
		checkInteger();
	} else if ($Formatter$Conversion::isFloat(this->c)) {
		checkFloat();
	} else if ($Formatter$Conversion::isText(this->c)) {
		checkText();
	} else {
		$throwNew($UnknownFormatConversionException, $($String::valueOf(this->c)));
	}
}

void Formatter$FormatSpecifier::print(Object$* arg, $Locale* l) {
	if (this->dt) {
		printDateTime(arg, l);
		return;
	}
	switch (this->c) {
	case $Formatter$Conversion::DECIMAL_INTEGER:
		{}
	case $Formatter$Conversion::OCTAL_INTEGER:
		{}
	case $Formatter$Conversion::HEXADECIMAL_INTEGER:
		{
			printInteger(arg, l);
			break;
		}
	case $Formatter$Conversion::SCIENTIFIC:
		{}
	case $Formatter$Conversion::GENERAL:
		{}
	case $Formatter$Conversion::DECIMAL_FLOAT:
		{}
	case $Formatter$Conversion::HEXADECIMAL_FLOAT:
		{
			printFloat(arg, l);
			break;
		}
	case $Formatter$Conversion::CHARACTER:
		{
			printCharacter(arg, l);
			break;
		}
	case $Formatter$Conversion::BOOLEAN:
		{
			printBoolean(arg, l);
			break;
		}
	case $Formatter$Conversion::STRING:
		{
			printString(arg, l);
			break;
		}
	case $Formatter$Conversion::HASHCODE:
		{
			printHashCode(arg, l);
			break;
		}
	case $Formatter$Conversion::LINE_SEPARATOR:
		{
			$nc(this->this$0->a)->append($(static_cast<$CharSequence*>($System::lineSeparator())));
			break;
		}
	case $Formatter$Conversion::PERCENT_SIGN:
		{
			print("%"_s, l);
			break;
		}
	default:
		{
			if (!Formatter$FormatSpecifier::$assertionsDisabled) {
				$throwNew($AssertionError);
			}
		}
	}
}

void Formatter$FormatSpecifier::printInteger(Object$* arg, $Locale* l) {
	if (arg == nullptr) {
		print("null"_s, l);
	} else if ($instanceOf($Byte, arg)) {
		print($nc(($cast($Byte, arg)))->byteValue(), l);
	} else if ($instanceOf($Short, arg)) {
		print($nc(($cast($Short, arg)))->shortValue(), l);
	} else if ($instanceOf($Integer, arg)) {
		print($nc(($cast($Integer, arg)))->intValue(), l);
	} else if ($instanceOf($Long, arg)) {
		print($nc(($cast($Long, arg)))->longValue(), l);
	} else if ($instanceOf($BigInteger, arg)) {
		print(($cast($BigInteger, arg)), l);
	} else {
		failConversion(this->c, arg);
	}
}

void Formatter$FormatSpecifier::printFloat(Object$* arg, $Locale* l) {
	if (arg == nullptr) {
		print("null"_s, l);
	} else if ($instanceOf($Float, arg)) {
		print($nc(($cast($Float, arg)))->floatValue(), l);
	} else if ($instanceOf($Double, arg)) {
		print($nc(($cast($Double, arg)))->doubleValue(), l);
	} else if ($instanceOf($BigDecimal, arg)) {
		print(($cast($BigDecimal, arg)), l);
	} else {
		failConversion(this->c, arg);
	}
}

void Formatter$FormatSpecifier::printDateTime(Object$* arg, $Locale* l) {
	if (arg == nullptr) {
		print("null"_s, l);
		return;
	}
	$var($Calendar, cal, nullptr);
	if ($instanceOf($Long, arg)) {
		$init($Locale);
		$assign(cal, $Calendar::getInstance(l == nullptr ? $Locale::US : l));
		$nc(cal)->setTimeInMillis($nc(($cast($Long, arg)))->longValue());
	} else if ($instanceOf($Date, arg)) {
		$init($Locale);
		$assign(cal, $Calendar::getInstance(l == nullptr ? $Locale::US : l));
		$nc(cal)->setTime($cast($Date, arg));
	} else if ($instanceOf($Calendar, arg)) {
		$assign(cal, $cast($Calendar, $nc(($cast($Calendar, arg)))->clone()));
		$nc(cal)->setLenient(true);
	} else if ($instanceOf($TemporalAccessor, arg)) {
		print($cast($TemporalAccessor, arg), this->c, l);
		return;
	} else {
		failConversion(this->c, arg);
	}
	print(cal, this->c, l);
}

void Formatter$FormatSpecifier::printCharacter(Object$* arg, $Locale* l) {
	$useLocalCurrentObjectStackCache();
	if (arg == nullptr) {
		print("null"_s, l);
		return;
	}
	$var($String, s, nullptr);
	if ($instanceOf($Character, arg)) {
		$assign(s, $nc(($cast($Character, arg)))->toString());
	} else if ($instanceOf($Byte, arg)) {
		int8_t i = $nc(($cast($Byte, arg)))->byteValue();
		if ($Character::isValidCodePoint(i)) {
			$assign(s, $new($String, $($Character::toChars(i))));
		} else {
			$throwNew($IllegalFormatCodePointException, i);
		}
	} else if ($instanceOf($Short, arg)) {
		int16_t i = $nc(($cast($Short, arg)))->shortValue();
		if ($Character::isValidCodePoint(i)) {
			$assign(s, $new($String, $($Character::toChars(i))));
		} else {
			$throwNew($IllegalFormatCodePointException, i);
		}
	} else if ($instanceOf($Integer, arg)) {
		int32_t i = $nc(($cast($Integer, arg)))->intValue();
		if ($Character::isValidCodePoint(i)) {
			$assign(s, $new($String, $($Character::toChars(i))));
		} else {
			$throwNew($IllegalFormatCodePointException, i);
		}
	} else {
		failConversion(this->c, arg);
	}
	print(s, l);
}

void Formatter$FormatSpecifier::printString(Object$* arg, $Locale* l) {
	$useLocalCurrentObjectStackCache();
	if ($instanceOf($Formattable, arg)) {
		$var($Formatter, fmt, this->this$0);
		if ($nc(fmt)->locale() != l) {
			$assign(fmt, $new($Formatter, $(fmt->out()), l));
		}
		$nc(($cast($Formattable, arg)))->formatTo(fmt, $nc(this->f)->valueOf(), this->width$, this->precision$);
	} else {
		$init($Formatter$Flags);
		if ($nc(this->f)->contains($Formatter$Flags::ALTERNATE)) {
			failMismatch($Formatter$Flags::ALTERNATE, u's');
		}
		if (arg == nullptr) {
			print("null"_s, l);
		} else {
			print($($nc($of(arg))->toString()), l);
		}
	}
}

void Formatter$FormatSpecifier::printBoolean(Object$* arg, $Locale* l) {
	$var($String, s, nullptr);
	if (arg != nullptr) {
		$assign(s, ($instanceOf($Boolean, arg)) ? $nc(($cast($Boolean, arg)))->toString() : $Boolean::toString(true));
	} else {
		$assign(s, $Boolean::toString(false));
	}
	print(s, l);
}

void Formatter$FormatSpecifier::printHashCode(Object$* arg, $Locale* l) {
	$var($String, s, arg == nullptr ? "null"_s : $Integer::toHexString($nc($of(arg))->hashCode()));
	print(s, l);
}

void Formatter$FormatSpecifier::print($String* s$renamed, $Locale* l) {
	$var($String, s, s$renamed);
	if (this->precision$ != -1 && this->precision$ < $nc(s)->length()) {
		$assign(s, s->substring(0, this->precision$));
	}
	$init($Formatter$Flags);
	if ($nc(this->f)->contains($Formatter$Flags::UPPERCASE)) {
		$assign(s, toUpperCaseWithLocale(s, l));
	}
	appendJustified(this->this$0->a, s);
}

$String* Formatter$FormatSpecifier::toUpperCaseWithLocale($String* s, $Locale* l) {
	$useLocalCurrentObjectStackCache();
	$init($Locale$Category);
	return $nc(s)->toUpperCase($cast($Locale, $($Objects::requireNonNullElse(l, $($Locale::getDefault($Locale$Category::FORMAT))))));
}

void Formatter$FormatSpecifier::appendJustified($Appendable* a, $CharSequence* cs) {
	if (this->width$ == -1) {
		$nc(a)->append(cs);
		return;
	}
	$init($Formatter$Flags);
	bool padRight = $nc(this->f)->contains($Formatter$Flags::LEFT_JUSTIFY);
	int32_t sp = this->width$ - $nc(cs)->length();
	if (padRight) {
		$nc(a)->append(cs);
	}
	for (int32_t i = 0; i < sp; ++i) {
		$nc(a)->append(u' ');
	}
	if (!padRight) {
		$nc(a)->append(cs);
	}
}

$String* Formatter$FormatSpecifier::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder, "%"_s));
	$init($Formatter$Flags);
	$var($Formatter$Flags, dupf, $nc($($nc(this->f)->dup()))->remove($Formatter$Flags::UPPERCASE));
	sb->append($($nc(dupf)->toString()));
	if (this->index$ > 0) {
		sb->append(this->index$)->append(u'$');
	}
	if (this->width$ != -1) {
		sb->append(this->width$);
	}
	if (this->precision$ != -1) {
		sb->append(u'.')->append(this->precision$);
	}
	if (this->dt) {
		sb->append($nc(this->f)->contains($Formatter$Flags::UPPERCASE) ? u'T' : u't');
	}
	sb->append($nc(this->f)->contains($Formatter$Flags::UPPERCASE) ? $Character::toUpperCase(this->c) : this->c);
	return sb->toString();
}

void Formatter$FormatSpecifier::checkGeneral() {
	$useLocalCurrentObjectStackCache();
	$init($Formatter$Flags);
	if ((this->c == $Formatter$Conversion::BOOLEAN || this->c == $Formatter$Conversion::HASHCODE) && $nc(this->f)->contains($Formatter$Flags::ALTERNATE)) {
		failMismatch($Formatter$Flags::ALTERNATE, this->c);
	}
	if (this->width$ == -1 && $nc(this->f)->contains($Formatter$Flags::LEFT_JUSTIFY)) {
		$throwNew($MissingFormatWidthException, $(toString()));
	}
	checkBadFlags($$new($Formatter$FlagsArray, {
		$Formatter$Flags::PLUS,
		$Formatter$Flags::LEADING_SPACE,
		$Formatter$Flags::ZERO_PAD,
		$Formatter$Flags::GROUP,
		$Formatter$Flags::PARENTHESES
	}));
}

void Formatter$FormatSpecifier::checkDateTime() {
	$useLocalCurrentObjectStackCache();
	if (this->precision$ != -1) {
		$throwNew($IllegalFormatPrecisionException, this->precision$);
	}
	if (!$Formatter$DateTime::isValid(this->c)) {
		$throwNew($UnknownFormatConversionException, $$str({"t"_s, $$str(this->c)}));
	}
	$init($Formatter$Flags);
	checkBadFlags($$new($Formatter$FlagsArray, {
		$Formatter$Flags::ALTERNATE,
		$Formatter$Flags::PLUS,
		$Formatter$Flags::LEADING_SPACE,
		$Formatter$Flags::ZERO_PAD,
		$Formatter$Flags::GROUP,
		$Formatter$Flags::PARENTHESES
	}));
	if (this->width$ == -1 && $nc(this->f)->contains($Formatter$Flags::LEFT_JUSTIFY)) {
		$throwNew($MissingFormatWidthException, $(toString()));
	}
}

void Formatter$FormatSpecifier::checkCharacter() {
	$useLocalCurrentObjectStackCache();
	if (this->precision$ != -1) {
		$throwNew($IllegalFormatPrecisionException, this->precision$);
	}
	$init($Formatter$Flags);
	checkBadFlags($$new($Formatter$FlagsArray, {
		$Formatter$Flags::ALTERNATE,
		$Formatter$Flags::PLUS,
		$Formatter$Flags::LEADING_SPACE,
		$Formatter$Flags::ZERO_PAD,
		$Formatter$Flags::GROUP,
		$Formatter$Flags::PARENTHESES
	}));
	if (this->width$ == -1 && $nc(this->f)->contains($Formatter$Flags::LEFT_JUSTIFY)) {
		$throwNew($MissingFormatWidthException, $(toString()));
	}
}

void Formatter$FormatSpecifier::checkInteger() {
	$useLocalCurrentObjectStackCache();
	checkNumeric();
	if (this->precision$ != -1) {
		$throwNew($IllegalFormatPrecisionException, this->precision$);
	}
	if (this->c == $Formatter$Conversion::DECIMAL_INTEGER) {
		$init($Formatter$Flags);
		checkBadFlags($$new($Formatter$FlagsArray, {$Formatter$Flags::ALTERNATE}));
	} else if (this->c == $Formatter$Conversion::OCTAL_INTEGER) {
		$init($Formatter$Flags);
		checkBadFlags($$new($Formatter$FlagsArray, {$Formatter$Flags::GROUP}));
	} else {
		$init($Formatter$Flags);
		checkBadFlags($$new($Formatter$FlagsArray, {$Formatter$Flags::GROUP}));
	}
}

void Formatter$FormatSpecifier::checkBadFlags($Formatter$FlagsArray* badFlags) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Formatter$FlagsArray, arr$, badFlags);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Formatter$Flags, badFlag, arr$->get(i$));
			if ($nc(this->f)->contains(badFlag)) {
				failMismatch(badFlag, this->c);
			}
		}
	}
}

void Formatter$FormatSpecifier::checkFloat() {
	$useLocalCurrentObjectStackCache();
	checkNumeric();
	if (this->c == $Formatter$Conversion::DECIMAL_FLOAT) {
	} else if (this->c == $Formatter$Conversion::HEXADECIMAL_FLOAT) {
		$init($Formatter$Flags);
		checkBadFlags($$new($Formatter$FlagsArray, {
			$Formatter$Flags::PARENTHESES,
			$Formatter$Flags::GROUP
		}));
	} else if (this->c == $Formatter$Conversion::SCIENTIFIC) {
		$init($Formatter$Flags);
		checkBadFlags($$new($Formatter$FlagsArray, {$Formatter$Flags::GROUP}));
	} else if (this->c == $Formatter$Conversion::GENERAL) {
		$init($Formatter$Flags);
		checkBadFlags($$new($Formatter$FlagsArray, {$Formatter$Flags::ALTERNATE}));
	}
}

void Formatter$FormatSpecifier::checkNumeric() {
	$useLocalCurrentObjectStackCache();
	if (this->width$ != -1 && this->width$ < 0) {
		$throwNew($IllegalFormatWidthException, this->width$);
	}
	if (this->precision$ != -1 && this->precision$ < 0) {
		$throwNew($IllegalFormatPrecisionException, this->precision$);
	}
	bool var$0 = this->width$ == -1;
	if (var$0) {
		$init($Formatter$Flags);
		bool var$1 = $nc(this->f)->contains($Formatter$Flags::LEFT_JUSTIFY);
		var$0 = (var$1 || $nc(this->f)->contains($Formatter$Flags::ZERO_PAD));
	}
	if (var$0) {
		$throwNew($MissingFormatWidthException, $(toString()));
	}
	$init($Formatter$Flags);
	bool var$3 = $nc(this->f)->contains($Formatter$Flags::PLUS);
	bool var$2 = (var$3 && $nc(this->f)->contains($Formatter$Flags::LEADING_SPACE));
	if (!var$2) {
		bool var$4 = $nc(this->f)->contains($Formatter$Flags::LEFT_JUSTIFY);
		var$2 = (var$4 && $nc(this->f)->contains($Formatter$Flags::ZERO_PAD));
	}
	if (var$2) {
		$throwNew($IllegalFormatFlagsException, $($nc(this->f)->toString()));
	}
}

void Formatter$FormatSpecifier::checkText() {
	$useLocalCurrentObjectStackCache();
	if (this->precision$ != -1) {
		$throwNew($IllegalFormatPrecisionException, this->precision$);
	}
	switch (this->c) {
	case $Formatter$Conversion::PERCENT_SIGN:
		{
			int32_t var$1 = $nc(this->f)->valueOf();
			bool var$0 = var$1 != $nc($Formatter$Flags::LEFT_JUSTIFY)->valueOf();
			if (var$0) {
				int32_t var$2 = $nc(this->f)->valueOf();
				var$0 = var$2 != $nc($Formatter$Flags::NONE)->valueOf();
			}
			if (var$0) {
				$throwNew($IllegalFormatFlagsException, $($nc(this->f)->toString()));
			}
			$init($Formatter$Flags);
			if (this->width$ == -1 && $nc(this->f)->contains($Formatter$Flags::LEFT_JUSTIFY)) {
				$throwNew($MissingFormatWidthException, $(toString()));
			}
			break;
		}
	case $Formatter$Conversion::LINE_SEPARATOR:
		{
			if (this->width$ != -1) {
				$throwNew($IllegalFormatWidthException, this->width$);
			}
			int32_t var$3 = $nc(this->f)->valueOf();
			if (var$3 != $nc($Formatter$Flags::NONE)->valueOf()) {
				$throwNew($IllegalFormatFlagsException, $($nc(this->f)->toString()));
			}
			break;
		}
	default:
		{
			if (!Formatter$FormatSpecifier::$assertionsDisabled) {
				$throwNew($AssertionError);
			}
		}
	}
}

void Formatter$FormatSpecifier::print(int8_t value, $Locale* l) {
	int64_t v = value;
	if (value < 0 && (this->c == $Formatter$Conversion::OCTAL_INTEGER || this->c == $Formatter$Conversion::HEXADECIMAL_INTEGER)) {
		v += ((int64_t)1 << 8);
	}
	print(v, l);
}

void Formatter$FormatSpecifier::print(int16_t value, $Locale* l) {
	int64_t v = value;
	if (value < 0 && (this->c == $Formatter$Conversion::OCTAL_INTEGER || this->c == $Formatter$Conversion::HEXADECIMAL_INTEGER)) {
		v += ((int64_t)1 << 16);
		if (!Formatter$FormatSpecifier::$assertionsDisabled && !(v >= 0)) {
			$throwNew($AssertionError, v);
		}
	}
	print(v, l);
}

void Formatter$FormatSpecifier::print(int32_t value, $Locale* l) {
	int64_t v = value;
	if (value < 0 && (this->c == $Formatter$Conversion::OCTAL_INTEGER || this->c == $Formatter$Conversion::HEXADECIMAL_INTEGER)) {
		v += ((int64_t)1 << 32);
		if (!Formatter$FormatSpecifier::$assertionsDisabled && !(v >= 0)) {
			$throwNew($AssertionError, v);
		}
	}
	print(v, l);
}

void Formatter$FormatSpecifier::print(int64_t value, $Locale* l) {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	if (this->c == $Formatter$Conversion::DECIMAL_INTEGER) {
		bool neg = value < 0;
		$var($String, valueStr, $Long::toString(value, 10));
		leadingSign(sb, neg);
		localizedMagnitude(sb, valueStr, neg ? 1 : 0, this->f, adjustWidth(this->width$, this->f, neg), l);
		trailingSign(sb, neg);
	} else if (this->c == $Formatter$Conversion::OCTAL_INTEGER) {
		$init($Formatter$Flags);
		checkBadFlags($$new($Formatter$FlagsArray, {
			$Formatter$Flags::PARENTHESES,
			$Formatter$Flags::LEADING_SPACE,
			$Formatter$Flags::PLUS
		}));
		$var($String, s, $Long::toOctalString(value));
		int32_t len = ($nc(this->f)->contains($Formatter$Flags::ALTERNATE) ? $nc(s)->length() + 1 : s->length());
		if ($nc(this->f)->contains($Formatter$Flags::ALTERNATE)) {
			sb->append(u'0');
		}
		if ($nc(this->f)->contains($Formatter$Flags::ZERO_PAD)) {
			trailingZeros(sb, this->width$ - len);
		}
		sb->append(s);
	} else if (this->c == $Formatter$Conversion::HEXADECIMAL_INTEGER) {
		$init($Formatter$Flags);
		checkBadFlags($$new($Formatter$FlagsArray, {
			$Formatter$Flags::PARENTHESES,
			$Formatter$Flags::LEADING_SPACE,
			$Formatter$Flags::PLUS
		}));
		$var($String, s, $Long::toHexString(value));
		int32_t len = ($nc(this->f)->contains($Formatter$Flags::ALTERNATE) ? $nc(s)->length() + 2 : s->length());
		if ($nc(this->f)->contains($Formatter$Flags::ALTERNATE)) {
			sb->append($nc(this->f)->contains($Formatter$Flags::UPPERCASE) ? "0X"_s : "0x"_s);
		}
		if ($nc(this->f)->contains($Formatter$Flags::ZERO_PAD)) {
			trailingZeros(sb, this->width$ - len);
		}
		if ($nc(this->f)->contains($Formatter$Flags::UPPERCASE)) {
			$assign(s, toUpperCaseWithLocale(s, l));
		}
		sb->append(s);
	}
	appendJustified(this->this$0->a, sb);
}

$StringBuilder* Formatter$FormatSpecifier::leadingSign($StringBuilder* sb, bool neg) {
	if (!neg) {
		$init($Formatter$Flags);
		if ($nc(this->f)->contains($Formatter$Flags::PLUS)) {
			$nc(sb)->append(u'+');
		} else {
			if ($nc(this->f)->contains($Formatter$Flags::LEADING_SPACE)) {
				$nc(sb)->append(u' ');
			}
		}
	} else {
		$init($Formatter$Flags);
		if ($nc(this->f)->contains($Formatter$Flags::PARENTHESES)) {
			$nc(sb)->append(u'(');
		} else {
			$nc(sb)->append(u'-');
		}
	}
	return sb;
}

$StringBuilder* Formatter$FormatSpecifier::trailingSign($StringBuilder* sb, bool neg) {
	$init($Formatter$Flags);
	if (neg && $nc(this->f)->contains($Formatter$Flags::PARENTHESES)) {
		$nc(sb)->append(u')');
	}
	return sb;
}

void Formatter$FormatSpecifier::print($BigInteger* value, $Locale* l) {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	bool neg = $nc(value)->signum() == -1;
	$var($BigInteger, v, value->abs());
	leadingSign(sb, neg);
	if (this->c == $Formatter$Conversion::DECIMAL_INTEGER) {
		$var($StringBuilder, var$0, sb);
		$var($CharSequence, var$1, static_cast<$CharSequence*>($nc(v)->toString()));
		$var($Formatter$Flags, var$2, this->f);
		localizedMagnitude(var$0, var$1, 0, var$2, adjustWidth(this->width$, this->f, neg), l);
	} else if (this->c == $Formatter$Conversion::OCTAL_INTEGER) {
		$var($String, s, $nc(v)->toString(8));
		int32_t var$3 = $nc(s)->length();
		int32_t len = var$3 + sb->length();
		$init($Formatter$Flags);
		if (neg && $nc(this->f)->contains($Formatter$Flags::PARENTHESES)) {
			++len;
		}
		if ($nc(this->f)->contains($Formatter$Flags::ALTERNATE)) {
			++len;
			sb->append(u'0');
		}
		if ($nc(this->f)->contains($Formatter$Flags::ZERO_PAD)) {
			trailingZeros(sb, this->width$ - len);
		}
		sb->append(s);
	} else if (this->c == $Formatter$Conversion::HEXADECIMAL_INTEGER) {
		$var($String, s, $nc(v)->toString(16));
		int32_t var$4 = $nc(s)->length();
		int32_t len = var$4 + sb->length();
		$init($Formatter$Flags);
		if (neg && $nc(this->f)->contains($Formatter$Flags::PARENTHESES)) {
			++len;
		}
		if ($nc(this->f)->contains($Formatter$Flags::ALTERNATE)) {
			len += 2;
			sb->append($nc(this->f)->contains($Formatter$Flags::UPPERCASE) ? "0X"_s : "0x"_s);
		}
		if ($nc(this->f)->contains($Formatter$Flags::ZERO_PAD)) {
			trailingZeros(sb, this->width$ - len);
		}
		if ($nc(this->f)->contains($Formatter$Flags::UPPERCASE)) {
			$assign(s, toUpperCaseWithLocale(s, l));
		}
		sb->append(s);
	}
	trailingSign(sb, (value->signum() == -1));
	appendJustified(this->this$0->a, sb);
}

void Formatter$FormatSpecifier::print(float value, $Locale* l) {
	print((double)value, l);
}

void Formatter$FormatSpecifier::print(double value, $Locale* l) {
	$var($StringBuilder, sb, $new($StringBuilder));
	bool neg = $Double::compare(value, 0.0) == -1;
	if (!$Double::isNaN(value)) {
		double v = $Math::abs(value);
		leadingSign(sb, neg);
		if (!$Double::isInfinite(v)) {
			print(sb, v, l, this->f, this->c, this->precision$, neg);
		} else {
			$init($Formatter$Flags);
			sb->append($nc(this->f)->contains($Formatter$Flags::UPPERCASE) ? "INFINITY"_s : "Infinity"_s);
		}
		trailingSign(sb, neg);
	} else {
		$init($Formatter$Flags);
		sb->append($nc(this->f)->contains($Formatter$Flags::UPPERCASE) ? "NAN"_s : "NaN"_s);
	}
	appendJustified(this->this$0->a, sb);
}

void Formatter$FormatSpecifier::print($StringBuilder* sb, double value, $Locale* l, $Formatter$Flags* f, char16_t c, int32_t precision, bool neg) {
	$useLocalCurrentObjectStackCache();
	if (c == $Formatter$Conversion::SCIENTIFIC) {
		int32_t prec = (precision == -1 ? 6 : precision);
		$init($FormattedFloatingDecimal$Form);
		$var($FormattedFloatingDecimal, fd, $FormattedFloatingDecimal::valueOf(value, prec, $FormattedFloatingDecimal$Form::SCIENTIFIC));
		$var($StringBuilder, mant, $$new($StringBuilder)->append($($nc(fd)->getMantissa())));
		addZeros(mant, prec);
		$init($Formatter$Flags);
		if ($nc(f)->contains($Formatter$Flags::ALTERNATE) && (prec == 0)) {
			mant->append(u'.');
		}
		$var($chars, exp, (value == 0.0) ? $new($chars, {
			u'+',
			u'0',
			u'0'
		}) : $nc(fd)->getExponent());
		int32_t newW = this->width$;
		if (this->width$ != -1) {
			newW = adjustWidth(this->width$ - $nc(exp)->length - 1, f, neg);
		}
		localizedMagnitude(sb, mant, 0, f, newW, l);
		$nc(sb)->append($nc(f)->contains($Formatter$Flags::UPPERCASE) ? u'E' : u'e');
		char16_t sign = $nc(exp)->get(0);
		if (!Formatter$FormatSpecifier::$assertionsDisabled && !(sign == u'+' || sign == u'-')) {
			$throwNew($AssertionError);
		}
		sb->append(sign);
		localizedMagnitudeExp(sb, exp, 1, l);
	} else if (c == $Formatter$Conversion::DECIMAL_FLOAT) {
		int32_t prec = (precision == -1 ? 6 : precision);
		$init($FormattedFloatingDecimal$Form);
		$var($FormattedFloatingDecimal, fd, $FormattedFloatingDecimal::valueOf(value, prec, $FormattedFloatingDecimal$Form::DECIMAL_FLOAT));
		$var($StringBuilder, mant, $$new($StringBuilder)->append($($nc(fd)->getMantissa())));
		addZeros(mant, prec);
		$init($Formatter$Flags);
		if ($nc(f)->contains($Formatter$Flags::ALTERNATE) && (prec == 0)) {
			mant->append(u'.');
		}
		int32_t newW = this->width$;
		if (this->width$ != -1) {
			newW = adjustWidth(this->width$, f, neg);
		}
		localizedMagnitude(sb, mant, 0, f, newW, l);
	} else if (c == $Formatter$Conversion::GENERAL) {
		int32_t prec = precision;
		if (precision == -1) {
			prec = 6;
		} else if (precision == 0) {
			prec = 1;
		}
		$var($chars, exp, nullptr);
		$var($StringBuilder, mant, $new($StringBuilder));
		int32_t expRounded = 0;
		if (value == 0.0) {
			$assign(exp, nullptr);
			mant->append(u'0');
			expRounded = 0;
		} else {
			$init($FormattedFloatingDecimal$Form);
			$var($FormattedFloatingDecimal, fd, $FormattedFloatingDecimal::valueOf(value, prec, $FormattedFloatingDecimal$Form::GENERAL));
			$assign(exp, $nc(fd)->getExponent());
			mant->append($(fd->getMantissa()));
			expRounded = fd->getExponentRounded();
		}
		if (exp != nullptr) {
			prec -= 1;
		} else {
			prec -= expRounded + 1;
		}
		addZeros(mant, prec);
		$init($Formatter$Flags);
		if ($nc(f)->contains($Formatter$Flags::ALTERNATE) && (prec == 0)) {
			mant->append(u'.');
		}
		int32_t newW = this->width$;
		if (this->width$ != -1) {
			if (exp != nullptr) {
				newW = adjustWidth(this->width$ - exp->length - 1, f, neg);
			} else {
				newW = adjustWidth(this->width$, f, neg);
			}
		}
		localizedMagnitude(sb, mant, 0, f, newW, l);
		if (exp != nullptr) {
			$nc(sb)->append($nc(f)->contains($Formatter$Flags::UPPERCASE) ? u'E' : u'e');
			char16_t sign = exp->get(0);
			if (!Formatter$FormatSpecifier::$assertionsDisabled && !(sign == u'+' || sign == u'-')) {
				$throwNew($AssertionError);
			}
			sb->append(sign);
			localizedMagnitudeExp(sb, exp, 1, l);
		}
	} else if (c == $Formatter$Conversion::HEXADECIMAL_FLOAT) {
		int32_t prec = precision;
		if (precision == -1) {
			prec = 0;
		} else if (precision == 0) {
			prec = 1;
		}
		$var($String, s, hexDouble(value, prec));
		$var($StringBuilder, va, $new($StringBuilder));
		$init($Formatter$Flags);
		bool upper = $nc(f)->contains($Formatter$Flags::UPPERCASE);
		$nc(sb)->append(upper ? "0X"_s : "0x"_s);
		if (f->contains($Formatter$Flags::ZERO_PAD)) {
			int32_t leadingCharacters = 2;
			bool var$0 = f->contains($Formatter$Flags::LEADING_SPACE);
			if (var$0 || f->contains($Formatter$Flags::PLUS) || neg) {
				leadingCharacters = 3;
			}
			trailingZeros(sb, this->width$ - $nc(s)->length() - leadingCharacters);
		}
		int32_t idx = $nc(s)->indexOf((int32_t)u'p');
		if (upper) {
			$var($String, tmp, s->substring(0, idx));
			$init($Locale);
			$assign(tmp, tmp->toUpperCase($Locale::ROOT));
			va->append(tmp);
		} else {
			va->append(static_cast<$CharSequence*>(s), 0, idx);
		}
		if (prec != 0) {
			addZeros(va, prec);
		}
		sb->append(static_cast<$CharSequence*>(va));
		sb->append(upper ? u'P' : u'p');
		sb->append(static_cast<$CharSequence*>(s), idx + 1, s->length());
	}
}

void Formatter$FormatSpecifier::addZeros($StringBuilder* sb, int32_t prec) {
	int32_t len = $nc(sb)->length();
	int32_t i = 0;
	for (i = 0; i < len; ++i) {
		if (sb->charAt(i) == u'.') {
			break;
		}
	}
	bool needDot = false;
	if (i == len) {
		needDot = true;
	}
	int32_t outPrec = len - i - (needDot ? 0 : 1);
	if (!Formatter$FormatSpecifier::$assertionsDisabled && !(outPrec <= prec)) {
		$throwNew($AssertionError);
	}
	if (outPrec == prec) {
		return;
	}
	if (needDot) {
		sb->append(u'.');
	}
	trailingZeros(sb, prec - outPrec);
}

$String* Formatter$FormatSpecifier::hexDouble(double d, int32_t prec) {
	$useLocalCurrentObjectStackCache();
	if (!$Double::isFinite(d) || d == 0.0 || prec == 0 || prec >= 13) {
		return $nc($($Double::toHexString(d)))->substring(2);
	} else {
		if (!Formatter$FormatSpecifier::$assertionsDisabled && !(prec >= 1 && prec <= 12)) {
			$throwNew($AssertionError);
		}
		int32_t exponent = $Math::getExponent(d);
		bool subnormal = (exponent == $Double::MIN_EXPONENT - 1);
		if (subnormal) {
			double scaleUp = $Math::scalb(1.0, 54);
			d *= scaleUp;
			exponent = $Math::getExponent(d);
			if (!Formatter$FormatSpecifier::$assertionsDisabled && !(exponent >= $Double::MIN_EXPONENT && exponent <= $Double::MAX_EXPONENT)) {
				$throwNew($AssertionError, exponent);
			}
		}
		int32_t precision = 1 + prec * 4;
		int32_t shiftDistance = $DoubleConsts::SIGNIFICAND_WIDTH - precision;
		if (!Formatter$FormatSpecifier::$assertionsDisabled && !(shiftDistance >= 1 && shiftDistance < $DoubleConsts::SIGNIFICAND_WIDTH)) {
			$throwNew($AssertionError);
		}
		int64_t doppel = $Double::doubleToLongBits(d);
		int64_t newSignif = $sr((int64_t)(doppel & (uint64_t)($DoubleConsts::EXP_BIT_MASK | $DoubleConsts::SIGNIF_BIT_MASK)), shiftDistance);
		int64_t roundingBits = (int64_t)(doppel & (uint64_t)~($sl(~(int64_t)0, shiftDistance)));
		bool leastZero = ((int64_t)(newSignif & (uint64_t)(int64_t)1)) == (int64_t)0;
		bool round = ((int64_t)(($sl((int64_t)1, shiftDistance - 1)) & (uint64_t)roundingBits)) != (int64_t)0;
		bool sticky = shiftDistance > 1 && ((int64_t)(~($sl((int64_t)1, shiftDistance - 1)) & (uint64_t)roundingBits)) != 0;
		if ((leastZero && round && sticky) || (!leastZero && round)) {
			++newSignif;
		}
		int64_t signBit = (int64_t)(doppel & (uint64_t)$DoubleConsts::SIGN_BIT_MASK);
		newSignif = signBit | ($sl(newSignif, shiftDistance));
		double result = $Double::longBitsToDouble(newSignif);
		if ($Double::isInfinite(result)) {
			return "1.0p1024"_s;
		} else {
			$var($String, res, $nc($($Double::toHexString(result)))->substring(2));
			if (!subnormal) {
				return res;
			} else {
				int32_t idx = res->indexOf((int32_t)u'p');
				if (idx == -1) {
					if (!Formatter$FormatSpecifier::$assertionsDisabled) {
						$throwNew($AssertionError);
					}
					return nullptr;
				} else {
					$var($String, exp, res->substring(idx + 1));
					int32_t iexp = $Integer::parseInt(exp) - 54;
					$var($String, var$0, $$str({$(res->substring(0, idx)), "p"_s}));
					return $concat(var$0, $($Integer::toString(iexp)));
				}
			}
		}
	}
}

void Formatter$FormatSpecifier::print($BigDecimal* value, $Locale* l) {
	$useLocalCurrentObjectStackCache();
	if (this->c == $Formatter$Conversion::HEXADECIMAL_FLOAT) {
		failConversion(this->c, value);
	}
	$var($StringBuilder, sb, $new($StringBuilder));
	bool neg = $nc(value)->signum() == -1;
	$var($BigDecimal, v, value->abs());
	leadingSign(sb, neg);
	print(sb, v, l, this->f, this->c, this->precision$, neg);
	trailingSign(sb, neg);
	appendJustified(this->this$0->a, sb);
}

void Formatter$FormatSpecifier::print($StringBuilder* sb, $BigDecimal* value$renamed, $Locale* l, $Formatter$Flags* f, char16_t c, int32_t precision, bool neg) {
	$useLocalCurrentObjectStackCache();
	$var($BigDecimal, value, value$renamed);
	if (c == $Formatter$Conversion::SCIENTIFIC) {
		int32_t prec = (precision == -1 ? 6 : precision);
		int32_t scale = $nc(value)->scale();
		int32_t origPrec = value->precision();
		int32_t nzeros = 0;
		int32_t compPrec = 0;
		if (prec > origPrec - 1) {
			compPrec = origPrec;
			nzeros = prec - (origPrec - 1);
		} else {
			compPrec = prec + 1;
		}
		$var($MathContext, mc, $new($MathContext, compPrec));
		$var($BigDecimal, v, $new($BigDecimal, $(value->unscaledValue()), scale, mc));
		$var($BigInteger, var$0, v->unscaledValue());
		$init($Formatter$BigDecimalLayoutForm);
		$var($Formatter$FormatSpecifier$BigDecimalLayout, bdl, $new($Formatter$FormatSpecifier$BigDecimalLayout, this, var$0, v->scale(), $Formatter$BigDecimalLayoutForm::SCIENTIFIC));
		$var($StringBuilder, mant, bdl->mantissa());
		bool var$1 = (origPrec == 1 || !bdl->hasDot());
		$init($Formatter$Flags);
		if (var$1 && (nzeros > 0 || ($nc(f)->contains($Formatter$Flags::ALTERNATE)))) {
			$nc(mant)->append(u'.');
		}
		trailingZeros(mant, nzeros);
		$var($StringBuilder, exp, bdl->exponent());
		int32_t newW = this->width$;
		if (this->width$ != -1) {
			newW = adjustWidth(this->width$ - $nc(exp)->length() - 1, f, neg);
		}
		localizedMagnitude(sb, mant, 0, f, newW, l);
		$nc(sb)->append($nc(f)->contains($Formatter$Flags::UPPERCASE) ? u'E' : u'e');
		$var($Formatter$Flags, flags, $nc($($nc(f)->dup()))->remove($Formatter$Flags::GROUP));
		char16_t sign = $nc(exp)->charAt(0);
		if (!Formatter$FormatSpecifier::$assertionsDisabled && !(sign == u'+' || sign == u'-')) {
			$throwNew($AssertionError);
		}
		sb->append(sign);
		sb->append($(static_cast<$CharSequence*>(localizedMagnitude(nullptr, exp, 1, flags, -1, l))));
	} else if (c == $Formatter$Conversion::DECIMAL_FLOAT) {
		int32_t prec = (precision == -1 ? 6 : precision);
		int32_t scale = $nc(value)->scale();
		if (scale > prec) {
			int32_t compPrec = value->precision();
			if (compPrec <= scale) {
				$init($RoundingMode);
				$assign(value, value->setScale(prec, $RoundingMode::HALF_UP));
			} else {
				compPrec -= (scale - prec);
				$var($BigInteger, var$2, value->unscaledValue());
				int32_t var$3 = scale;
				$assign(value, $new($BigDecimal, var$2, var$3, $$new($MathContext, compPrec)));
			}
		}
		$var($BigInteger, var$4, value->unscaledValue());
		$init($Formatter$BigDecimalLayoutForm);
		$var($Formatter$FormatSpecifier$BigDecimalLayout, bdl, $new($Formatter$FormatSpecifier$BigDecimalLayout, this, var$4, value->scale(), $Formatter$BigDecimalLayoutForm::DECIMAL_FLOAT));
		$var($StringBuilder, mant, bdl->mantissa());
		int32_t nzeros = (bdl->scale() < prec ? prec - bdl->scale() : 0);
		bool var$5 = bdl->scale() == 0;
		$init($Formatter$Flags);
		if (var$5 && ($nc(f)->contains($Formatter$Flags::ALTERNATE) || nzeros > 0)) {
			$nc(mant)->append(u'.');
		}
		trailingZeros(mant, nzeros);
		localizedMagnitude(sb, mant, 0, f, adjustWidth(this->width$, f, neg), l);
	} else if (c == $Formatter$Conversion::GENERAL) {
		int32_t prec = precision;
		if (precision == -1) {
			prec = 6;
		} else if (precision == 0) {
			prec = 1;
		}
		$assign(value, $nc(value)->round($$new($MathContext, prec)));
		bool var$6 = (value->equals($BigDecimal::ZERO));
		if (!var$6) {
			bool var$7 = (value->compareTo($($BigDecimal::valueOf(1, 4))) != -1);
			var$6 = (var$7 && (value->compareTo($($BigDecimal::valueOf(1, -prec))) == -1));
		}
		if (var$6) {
			int32_t var$8 = -value->scale();
			int32_t e = var$8 + ($nc($($nc($(value->unscaledValue()))->toString()))->length() - 1);
			prec = prec - e - 1;
			print(sb, value, l, f, $Formatter$Conversion::DECIMAL_FLOAT, prec, neg);
		} else {
			print(sb, value, l, f, $Formatter$Conversion::SCIENTIFIC, prec - 1, neg);
		}
	} else if (c == $Formatter$Conversion::HEXADECIMAL_FLOAT) {
		if (!Formatter$FormatSpecifier::$assertionsDisabled) {
			$throwNew($AssertionError);
		}
	}
}

int32_t Formatter$FormatSpecifier::adjustWidth(int32_t width, $Formatter$Flags* f, bool neg) {
	int32_t newW = width;
	$init($Formatter$Flags);
	if (newW != -1 && neg && $nc(f)->contains($Formatter$Flags::PARENTHESES)) {
		--newW;
	}
	return newW;
}

void Formatter$FormatSpecifier::trailingZeros($StringBuilder* sb, int32_t nzeros) {
	for (int32_t i = 0; i < nzeros; ++i) {
		$nc(sb)->append(u'0');
	}
}

void Formatter$FormatSpecifier::print($Calendar* t, char16_t c, $Locale* l) {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	print(sb, t, c, l);
	$init($Formatter$Flags);
	if ($nc(this->f)->contains($Formatter$Flags::UPPERCASE)) {
		appendJustified(this->this$0->a, $(toUpperCaseWithLocale($(sb->toString()), l)));
	} else {
		appendJustified(this->this$0->a, sb);
	}
}

$Appendable* Formatter$FormatSpecifier::print($StringBuilder* sb$renamed, $Calendar* t, char16_t c, $Locale* l) {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, sb$renamed);
	if (sb == nullptr) {
		$assign(sb, $new($StringBuilder));
	}
	switch (c) {
	case $Formatter$DateTime::HOUR_OF_DAY_0:
		{}
	case $Formatter$DateTime::HOUR_0:
		{}
	case $Formatter$DateTime::HOUR_OF_DAY:
		{}
	case $Formatter$DateTime::HOUR:
		{
			{
				int32_t i = $nc(t)->get($Calendar::HOUR_OF_DAY);
				if (c == $Formatter$DateTime::HOUR_0 || c == $Formatter$DateTime::HOUR) {
					i = (i == 0 || i == 12 ? 12 : i % 12);
				}
				$init($Formatter$Flags);
				$var($Formatter$Flags, flags, c == $Formatter$DateTime::HOUR_OF_DAY_0 || c == $Formatter$DateTime::HOUR_0 ? $Formatter$Flags::ZERO_PAD : $Formatter$Flags::NONE);
				$nc(sb)->append($(static_cast<$CharSequence*>(localizedMagnitude(nullptr, i, flags, 2, l))));
				break;
			}
		}
	case $Formatter$DateTime::MINUTE:
		{
			{
				int32_t i = $nc(t)->get($Calendar::MINUTE);
				$init($Formatter$Flags);
				$var($Formatter$Flags, flags, $Formatter$Flags::ZERO_PAD);
				$nc(sb)->append($(static_cast<$CharSequence*>(localizedMagnitude(nullptr, i, flags, 2, l))));
				break;
			}
		}
	case $Formatter$DateTime::NANOSECOND:
		{
			{
				int32_t i = $nc(t)->get($Calendar::MILLISECOND) * 0x000F4240;
				$init($Formatter$Flags);
				$var($Formatter$Flags, flags, $Formatter$Flags::ZERO_PAD);
				$nc(sb)->append($(static_cast<$CharSequence*>(localizedMagnitude(nullptr, i, flags, 9, l))));
				break;
			}
		}
	case $Formatter$DateTime::MILLISECOND:
		{
			{
				int32_t i = $nc(t)->get($Calendar::MILLISECOND);
				$init($Formatter$Flags);
				$var($Formatter$Flags, flags, $Formatter$Flags::ZERO_PAD);
				$nc(sb)->append($(static_cast<$CharSequence*>(localizedMagnitude(nullptr, i, flags, 3, l))));
				break;
			}
		}
	case $Formatter$DateTime::MILLISECOND_SINCE_EPOCH:
		{
			{
				int64_t i = $nc(t)->getTimeInMillis();
				$init($Formatter$Flags);
				$var($Formatter$Flags, flags, $Formatter$Flags::NONE);
				$nc(sb)->append($(static_cast<$CharSequence*>(localizedMagnitude(nullptr, i, flags, this->width$, l))));
				break;
			}
		}
	case $Formatter$DateTime::AM_PM:
		{
			{
				$var($StringArray, ampm, $new($StringArray, {
					"AM"_s,
					"PM"_s
				}));
				$init($Locale);
				if (l != nullptr && l != $Locale::US) {
					$var($DateFormatSymbols, dfs, $DateFormatSymbols::getInstance(l));
					$assign(ampm, $nc(dfs)->getAmPmStrings());
				}
				$var($String, s, ampm->get($nc(t)->get($Calendar::AM_PM)));
				$init($Locale$Category);
				$nc(sb)->append($($nc(s)->toLowerCase($cast($Locale, $($Objects::requireNonNullElse(l, $($Locale::getDefault($Locale$Category::FORMAT))))))));
				break;
			}
		}
	case $Formatter$DateTime::SECONDS_SINCE_EPOCH:
		{
			{
				int64_t i = $nc(t)->getTimeInMillis() / 1000;
				$init($Formatter$Flags);
				$var($Formatter$Flags, flags, $Formatter$Flags::NONE);
				$nc(sb)->append($(static_cast<$CharSequence*>(localizedMagnitude(nullptr, i, flags, this->width$, l))));
				break;
			}
		}
	case $Formatter$DateTime::SECOND:
		{
			{
				int32_t i = $nc(t)->get($Calendar::SECOND);
				$init($Formatter$Flags);
				$var($Formatter$Flags, flags, $Formatter$Flags::ZERO_PAD);
				$nc(sb)->append($(static_cast<$CharSequence*>(localizedMagnitude(nullptr, i, flags, 2, l))));
				break;
			}
		}
	case $Formatter$DateTime::ZONE_NUMERIC:
		{
			{
				int32_t var$0 = $nc(t)->get($Calendar::ZONE_OFFSET);
				int32_t i = var$0 + t->get($Calendar::DST_OFFSET);
				bool neg = i < 0;
				$nc(sb)->append(neg ? u'-' : u'+');
				if (neg) {
					i = -i;
				}
				int32_t min = i / 0x0000EA60;
				int32_t offset = (min / 60) * 100 + (min % 60);
				$init($Formatter$Flags);
				$var($Formatter$Flags, flags, $Formatter$Flags::ZERO_PAD);
				sb->append($(static_cast<$CharSequence*>(localizedMagnitude(nullptr, offset, flags, 4, l))));
				break;
			}
		}
	case $Formatter$DateTime::ZONE:
		{
			{
				$var($TimeZone, tz, $nc(t)->getTimeZone());
				bool var$1 = (t->get($Calendar::DST_OFFSET) != 0);
				$init($Locale);
				$nc(sb)->append($($nc(tz)->getDisplayName(var$1, $TimeZone::SHORT, $cast($Locale, $($Objects::requireNonNullElse(l, $Locale::US))))));
				break;
			}
		}
	case $Formatter$DateTime::NAME_OF_DAY_ABBREV:
		{}
	case $Formatter$DateTime::NAME_OF_DAY:
		{
			{
				int32_t i = $nc(t)->get($Calendar::DAY_OF_WEEK);
				$init($Locale);
				$var($Locale, lt, $cast($Locale, $Objects::requireNonNullElse(l, $Locale::US)));
				$var($DateFormatSymbols, dfs, $DateFormatSymbols::getInstance(lt));
				if (c == $Formatter$DateTime::NAME_OF_DAY) {
					$nc(sb)->append($nc($($nc(dfs)->getWeekdays()))->get(i));
				} else {
					$nc(sb)->append($nc($($nc(dfs)->getShortWeekdays()))->get(i));
				}
				break;
			}
		}
	case $Formatter$DateTime::NAME_OF_MONTH_ABBREV:
		{}
	case $Formatter$DateTime::NAME_OF_MONTH_ABBREV_X:
		{}
	case $Formatter$DateTime::NAME_OF_MONTH:
		{
			{
				int32_t i = $nc(t)->get($Calendar::MONTH);
				$init($Locale);
				$var($Locale, lt, $cast($Locale, $Objects::requireNonNullElse(l, $Locale::US)));
				$var($DateFormatSymbols, dfs, $DateFormatSymbols::getInstance(lt));
				if (c == $Formatter$DateTime::NAME_OF_MONTH) {
					$nc(sb)->append($nc($($nc(dfs)->getMonths()))->get(i));
				} else {
					$nc(sb)->append($nc($($nc(dfs)->getShortMonths()))->get(i));
				}
				break;
			}
		}
	case $Formatter$DateTime::CENTURY:
		{}
	case $Formatter$DateTime::YEAR_2:
		{}
	case $Formatter$DateTime::YEAR_4:
		{
			{
				int32_t i = $nc(t)->get($Calendar::YEAR);
				int32_t size = 2;
				switch (c) {
				case $Formatter$DateTime::CENTURY:
					{
						i /= 100;
						break;
					}
				case $Formatter$DateTime::YEAR_2:
					{
						$modAssign(i, 100);
						break;
					}
				case $Formatter$DateTime::YEAR_4:
					{
						size = 4;
						break;
					}
				}
				$init($Formatter$Flags);
				$var($Formatter$Flags, flags, $Formatter$Flags::ZERO_PAD);
				$nc(sb)->append($(static_cast<$CharSequence*>(localizedMagnitude(nullptr, i, flags, size, l))));
				break;
			}
		}
	case $Formatter$DateTime::DAY_OF_MONTH_0:
		{}
	case $Formatter$DateTime::DAY_OF_MONTH:
		{
			{
				int32_t i = $nc(t)->get($Calendar::DATE);
				$init($Formatter$Flags);
				$var($Formatter$Flags, flags, c == $Formatter$DateTime::DAY_OF_MONTH_0 ? $Formatter$Flags::ZERO_PAD : $Formatter$Flags::NONE);
				$nc(sb)->append($(static_cast<$CharSequence*>(localizedMagnitude(nullptr, i, flags, 2, l))));
				break;
			}
		}
	case $Formatter$DateTime::DAY_OF_YEAR:
		{
			{
				int32_t i = $nc(t)->get($Calendar::DAY_OF_YEAR);
				$init($Formatter$Flags);
				$var($Formatter$Flags, flags, $Formatter$Flags::ZERO_PAD);
				$nc(sb)->append($(static_cast<$CharSequence*>(localizedMagnitude(nullptr, i, flags, 3, l))));
				break;
			}
		}
	case $Formatter$DateTime::MONTH:
		{
			{
				int32_t i = $nc(t)->get($Calendar::MONTH) + 1;
				$init($Formatter$Flags);
				$var($Formatter$Flags, flags, $Formatter$Flags::ZERO_PAD);
				$nc(sb)->append($(static_cast<$CharSequence*>(localizedMagnitude(nullptr, i, flags, 2, l))));
				break;
			}
		}
	case $Formatter$DateTime::TIME:
		{}
	case $Formatter$DateTime::TIME_24_HOUR:
		{
			{
				char16_t sep = u':';
				$nc($(print(sb, t, $Formatter$DateTime::HOUR_OF_DAY_0, l)))->append(sep);
				print(sb, t, $Formatter$DateTime::MINUTE, l);
				if (c == $Formatter$DateTime::TIME) {
					$nc(sb)->append(sep);
					print(sb, t, $Formatter$DateTime::SECOND, l);
				}
				break;
			}
		}
	case $Formatter$DateTime::TIME_12_HOUR:
		{
			{
				char16_t sep = u':';
				$nc($(print(sb, t, $Formatter$DateTime::HOUR_0, l)))->append(sep);
				$nc($(print(sb, t, $Formatter$DateTime::MINUTE, l)))->append(sep);
				$nc($(print(sb, t, $Formatter$DateTime::SECOND, l)))->append(u' ');
				$var($StringBuilder, tsb, $new($StringBuilder));
				print(tsb, t, $Formatter$DateTime::AM_PM, l);
				$nc(sb)->append($(toUpperCaseWithLocale($(tsb->toString()), l)));
				break;
			}
		}
	case $Formatter$DateTime::DATE_TIME:
		{
			{
				char16_t sep = u' ';
				$nc($(print(sb, t, $Formatter$DateTime::NAME_OF_DAY_ABBREV, l)))->append(sep);
				$nc($(print(sb, t, $Formatter$DateTime::NAME_OF_MONTH_ABBREV, l)))->append(sep);
				$nc($(print(sb, t, $Formatter$DateTime::DAY_OF_MONTH_0, l)))->append(sep);
				$nc($(print(sb, t, $Formatter$DateTime::TIME, l)))->append(sep);
				$nc($(print(sb, t, $Formatter$DateTime::ZONE, l)))->append(sep);
				print(sb, t, $Formatter$DateTime::YEAR_4, l);
				break;
			}
		}
	case $Formatter$DateTime::DATE:
		{
			{
				char16_t sep = u'/';
				$nc($(print(sb, t, $Formatter$DateTime::MONTH, l)))->append(sep);
				$nc($(print(sb, t, $Formatter$DateTime::DAY_OF_MONTH_0, l)))->append(sep);
				print(sb, t, $Formatter$DateTime::YEAR_2, l);
				break;
			}
		}
	case $Formatter$DateTime::ISO_STANDARD_DATE:
		{
			{
				char16_t sep = u'-';
				$nc($(print(sb, t, $Formatter$DateTime::YEAR_4, l)))->append(sep);
				$nc($(print(sb, t, $Formatter$DateTime::MONTH, l)))->append(sep);
				print(sb, t, $Formatter$DateTime::DAY_OF_MONTH_0, l);
				break;
			}
		}
	default:
		{
			if (!Formatter$FormatSpecifier::$assertionsDisabled) {
				$throwNew($AssertionError);
			}
		}
	}
	return sb;
}

void Formatter$FormatSpecifier::print($TemporalAccessor* t, char16_t c, $Locale* l) {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	print(sb, t, c, l);
	$init($Formatter$Flags);
	if ($nc(this->f)->contains($Formatter$Flags::UPPERCASE)) {
		appendJustified(this->this$0->a, $(toUpperCaseWithLocale($(sb->toString()), l)));
	} else {
		appendJustified(this->this$0->a, sb);
	}
}

$Appendable* Formatter$FormatSpecifier::print($StringBuilder* sb$renamed, $TemporalAccessor* t, char16_t c, $Locale* l) {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, sb$renamed);
	if (sb == nullptr) {
		$assign(sb, $new($StringBuilder));
	}
	try {
		switch (c) {
		case $Formatter$DateTime::HOUR_OF_DAY_0:
			{
				{
					$init($ChronoField);
					int32_t i = $nc(t)->get($ChronoField::HOUR_OF_DAY);
					$init($Formatter$Flags);
					$nc(sb)->append($(static_cast<$CharSequence*>(localizedMagnitude(nullptr, i, $Formatter$Flags::ZERO_PAD, 2, l))));
					break;
				}
			}
		case $Formatter$DateTime::HOUR_OF_DAY:
			{
				{
					$init($ChronoField);
					int32_t i = $nc(t)->get($ChronoField::HOUR_OF_DAY);
					$init($Formatter$Flags);
					$nc(sb)->append($(static_cast<$CharSequence*>(localizedMagnitude(nullptr, i, $Formatter$Flags::NONE, 2, l))));
					break;
				}
			}
		case $Formatter$DateTime::HOUR_0:
			{
				{
					$init($ChronoField);
					int32_t i = $nc(t)->get($ChronoField::CLOCK_HOUR_OF_AMPM);
					$init($Formatter$Flags);
					$nc(sb)->append($(static_cast<$CharSequence*>(localizedMagnitude(nullptr, i, $Formatter$Flags::ZERO_PAD, 2, l))));
					break;
				}
			}
		case $Formatter$DateTime::HOUR:
			{
				{
					$init($ChronoField);
					int32_t i = $nc(t)->get($ChronoField::CLOCK_HOUR_OF_AMPM);
					$init($Formatter$Flags);
					$nc(sb)->append($(static_cast<$CharSequence*>(localizedMagnitude(nullptr, i, $Formatter$Flags::NONE, 2, l))));
					break;
				}
			}
		case $Formatter$DateTime::MINUTE:
			{
				{
					$init($ChronoField);
					int32_t i = $nc(t)->get($ChronoField::MINUTE_OF_HOUR);
					$init($Formatter$Flags);
					$var($Formatter$Flags, flags, $Formatter$Flags::ZERO_PAD);
					$nc(sb)->append($(static_cast<$CharSequence*>(localizedMagnitude(nullptr, i, flags, 2, l))));
					break;
				}
			}
		case $Formatter$DateTime::NANOSECOND:
			{
				{
					int32_t i = 0;
					try {
						$init($ChronoField);
						i = $nc(t)->get($ChronoField::NANO_OF_SECOND);
					} catch ($UnsupportedTemporalTypeException& u) {
						$init($ChronoField);
						i = $nc(t)->get($ChronoField::MILLI_OF_SECOND) * 0x000F4240;
					}
					$init($Formatter$Flags);
					$var($Formatter$Flags, flags, $Formatter$Flags::ZERO_PAD);
					$nc(sb)->append($(static_cast<$CharSequence*>(localizedMagnitude(nullptr, i, flags, 9, l))));
					break;
				}
			}
		case $Formatter$DateTime::MILLISECOND:
			{
				{
					$init($ChronoField);
					int32_t i = $nc(t)->get($ChronoField::MILLI_OF_SECOND);
					$init($Formatter$Flags);
					$var($Formatter$Flags, flags, $Formatter$Flags::ZERO_PAD);
					$nc(sb)->append($(static_cast<$CharSequence*>(localizedMagnitude(nullptr, i, flags, 3, l))));
					break;
				}
			}
		case $Formatter$DateTime::MILLISECOND_SINCE_EPOCH:
			{
				{
					$init($ChronoField);
					int64_t var$0 = $nc(t)->getLong($ChronoField::INSTANT_SECONDS) * (int64_t)1000;
					int64_t i = var$0 + t->getLong($ChronoField::MILLI_OF_SECOND);
					$init($Formatter$Flags);
					$var($Formatter$Flags, flags, $Formatter$Flags::NONE);
					$nc(sb)->append($(static_cast<$CharSequence*>(localizedMagnitude(nullptr, i, flags, this->width$, l))));
					break;
				}
			}
		case $Formatter$DateTime::AM_PM:
			{
				{
					$var($StringArray, ampm, $new($StringArray, {
						"AM"_s,
						"PM"_s
					}));
					$init($Locale);
					if (l != nullptr && l != $Locale::US) {
						$var($DateFormatSymbols, dfs, $DateFormatSymbols::getInstance(l));
						$assign(ampm, $nc(dfs)->getAmPmStrings());
					}
					$init($ChronoField);
					$var($String, s, ampm->get($nc(t)->get($ChronoField::AMPM_OF_DAY)));
					$init($Locale$Category);
					$nc(sb)->append($($nc(s)->toLowerCase($cast($Locale, $($Objects::requireNonNullElse(l, $($Locale::getDefault($Locale$Category::FORMAT))))))));
					break;
				}
			}
		case $Formatter$DateTime::SECONDS_SINCE_EPOCH:
			{
				{
					$init($ChronoField);
					int64_t i = $nc(t)->getLong($ChronoField::INSTANT_SECONDS);
					$init($Formatter$Flags);
					$var($Formatter$Flags, flags, $Formatter$Flags::NONE);
					$nc(sb)->append($(static_cast<$CharSequence*>(localizedMagnitude(nullptr, i, flags, this->width$, l))));
					break;
				}
			}
		case $Formatter$DateTime::SECOND:
			{
				{
					$init($ChronoField);
					int32_t i = $nc(t)->get($ChronoField::SECOND_OF_MINUTE);
					$init($Formatter$Flags);
					$var($Formatter$Flags, flags, $Formatter$Flags::ZERO_PAD);
					$nc(sb)->append($(static_cast<$CharSequence*>(localizedMagnitude(nullptr, i, flags, 2, l))));
					break;
				}
			}
		case $Formatter$DateTime::ZONE_NUMERIC:
			{
				{
					$init($ChronoField);
					int32_t i = $nc(t)->get($ChronoField::OFFSET_SECONDS);
					bool neg = i < 0;
					$nc(sb)->append(neg ? u'-' : u'+');
					if (neg) {
						i = -i;
					}
					int32_t min = i / 60;
					int32_t offset = (min / 60) * 100 + (min % 60);
					$init($Formatter$Flags);
					$var($Formatter$Flags, flags, $Formatter$Flags::ZERO_PAD);
					sb->append($(static_cast<$CharSequence*>(localizedMagnitude(nullptr, offset, flags, 4, l))));
					break;
				}
			}
		case $Formatter$DateTime::ZONE:
			{
				{
					$var($ZoneId, zid, $cast($ZoneId, $nc(t)->query($($TemporalQueries::zone()))));
					if (zid == nullptr) {
						$throwNew($IllegalFormatConversionException, c, $of(t)->getClass());
					}
					$init($ChronoField);
					if (!($instanceOf($ZoneOffset, zid)) && t->isSupported($ChronoField::INSTANT_SECONDS)) {
						$var($Instant, instant, $Instant::from(t));
						bool var$1 = $nc($($nc(zid)->getRules()))->isDaylightSavings(instant);
						$init($Locale);
						$nc(sb)->append($($nc($($TimeZone::getTimeZone($($nc(zid)->getId()))))->getDisplayName(var$1, $TimeZone::SHORT, $cast($Locale, $($Objects::requireNonNullElse(l, $Locale::US))))));
						break;
					}
					$nc(sb)->append($($nc(zid)->getId()));
					break;
				}
			}
		case $Formatter$DateTime::NAME_OF_DAY_ABBREV:
			{}
		case $Formatter$DateTime::NAME_OF_DAY:
			{
				{
					$init($ChronoField);
					int32_t i = $nc(t)->get($ChronoField::DAY_OF_WEEK) % 7 + 1;
					$init($Locale);
					$var($Locale, lt, $cast($Locale, $Objects::requireNonNullElse(l, $Locale::US)));
					$var($DateFormatSymbols, dfs, $DateFormatSymbols::getInstance(lt));
					if (c == $Formatter$DateTime::NAME_OF_DAY) {
						$nc(sb)->append($nc($($nc(dfs)->getWeekdays()))->get(i));
					} else {
						$nc(sb)->append($nc($($nc(dfs)->getShortWeekdays()))->get(i));
					}
					break;
				}
			}
		case $Formatter$DateTime::NAME_OF_MONTH_ABBREV:
			{}
		case $Formatter$DateTime::NAME_OF_MONTH_ABBREV_X:
			{}
		case $Formatter$DateTime::NAME_OF_MONTH:
			{
				{
					$init($ChronoField);
					int32_t i = $nc(t)->get($ChronoField::MONTH_OF_YEAR) - 1;
					$init($Locale);
					$var($Locale, lt, $cast($Locale, $Objects::requireNonNullElse(l, $Locale::US)));
					$var($DateFormatSymbols, dfs, $DateFormatSymbols::getInstance(lt));
					if (c == $Formatter$DateTime::NAME_OF_MONTH) {
						$nc(sb)->append($nc($($nc(dfs)->getMonths()))->get(i));
					} else {
						$nc(sb)->append($nc($($nc(dfs)->getShortMonths()))->get(i));
					}
					break;
				}
			}
		case $Formatter$DateTime::CENTURY:
			{}
		case $Formatter$DateTime::YEAR_2:
			{}
		case $Formatter$DateTime::YEAR_4:
			{
				{
					$init($ChronoField);
					int32_t i = $nc(t)->get($ChronoField::YEAR_OF_ERA);
					int32_t size = 2;
					switch (c) {
					case $Formatter$DateTime::CENTURY:
						{
							i /= 100;
							break;
						}
					case $Formatter$DateTime::YEAR_2:
						{
							$modAssign(i, 100);
							break;
						}
					case $Formatter$DateTime::YEAR_4:
						{
							size = 4;
							break;
						}
					}
					$init($Formatter$Flags);
					$var($Formatter$Flags, flags, $Formatter$Flags::ZERO_PAD);
					$nc(sb)->append($(static_cast<$CharSequence*>(localizedMagnitude(nullptr, i, flags, size, l))));
					break;
				}
			}
		case $Formatter$DateTime::DAY_OF_MONTH_0:
			{}
		case $Formatter$DateTime::DAY_OF_MONTH:
			{
				{
					$init($ChronoField);
					int32_t i = $nc(t)->get($ChronoField::DAY_OF_MONTH);
					$init($Formatter$Flags);
					$var($Formatter$Flags, flags, c == $Formatter$DateTime::DAY_OF_MONTH_0 ? $Formatter$Flags::ZERO_PAD : $Formatter$Flags::NONE);
					$nc(sb)->append($(static_cast<$CharSequence*>(localizedMagnitude(nullptr, i, flags, 2, l))));
					break;
				}
			}
		case $Formatter$DateTime::DAY_OF_YEAR:
			{
				{
					$init($ChronoField);
					int32_t i = $nc(t)->get($ChronoField::DAY_OF_YEAR);
					$init($Formatter$Flags);
					$var($Formatter$Flags, flags, $Formatter$Flags::ZERO_PAD);
					$nc(sb)->append($(static_cast<$CharSequence*>(localizedMagnitude(nullptr, i, flags, 3, l))));
					break;
				}
			}
		case $Formatter$DateTime::MONTH:
			{
				{
					$init($ChronoField);
					int32_t i = $nc(t)->get($ChronoField::MONTH_OF_YEAR);
					$init($Formatter$Flags);
					$var($Formatter$Flags, flags, $Formatter$Flags::ZERO_PAD);
					$nc(sb)->append($(static_cast<$CharSequence*>(localizedMagnitude(nullptr, i, flags, 2, l))));
					break;
				}
			}
		case $Formatter$DateTime::TIME:
			{}
		case $Formatter$DateTime::TIME_24_HOUR:
			{
				{
					char16_t sep = u':';
					$nc($(print(sb, t, $Formatter$DateTime::HOUR_OF_DAY_0, l)))->append(sep);
					print(sb, t, $Formatter$DateTime::MINUTE, l);
					if (c == $Formatter$DateTime::TIME) {
						$nc(sb)->append(sep);
						print(sb, t, $Formatter$DateTime::SECOND, l);
					}
					break;
				}
			}
		case $Formatter$DateTime::TIME_12_HOUR:
			{
				{
					char16_t sep = u':';
					$nc($(print(sb, t, $Formatter$DateTime::HOUR_0, l)))->append(sep);
					$nc($(print(sb, t, $Formatter$DateTime::MINUTE, l)))->append(sep);
					$nc($(print(sb, t, $Formatter$DateTime::SECOND, l)))->append(u' ');
					$var($StringBuilder, tsb, $new($StringBuilder));
					print(tsb, t, $Formatter$DateTime::AM_PM, l);
					$nc(sb)->append($(toUpperCaseWithLocale($(tsb->toString()), l)));
					break;
				}
			}
		case $Formatter$DateTime::DATE_TIME:
			{
				{
					char16_t sep = u' ';
					$nc($(print(sb, t, $Formatter$DateTime::NAME_OF_DAY_ABBREV, l)))->append(sep);
					$nc($(print(sb, t, $Formatter$DateTime::NAME_OF_MONTH_ABBREV, l)))->append(sep);
					$nc($(print(sb, t, $Formatter$DateTime::DAY_OF_MONTH_0, l)))->append(sep);
					$nc($(print(sb, t, $Formatter$DateTime::TIME, l)))->append(sep);
					$nc($(print(sb, t, $Formatter$DateTime::ZONE, l)))->append(sep);
					print(sb, t, $Formatter$DateTime::YEAR_4, l);
					break;
				}
			}
		case $Formatter$DateTime::DATE:
			{
				{
					char16_t sep = u'/';
					$nc($(print(sb, t, $Formatter$DateTime::MONTH, l)))->append(sep);
					$nc($(print(sb, t, $Formatter$DateTime::DAY_OF_MONTH_0, l)))->append(sep);
					print(sb, t, $Formatter$DateTime::YEAR_2, l);
					break;
				}
			}
		case $Formatter$DateTime::ISO_STANDARD_DATE:
			{
				{
					char16_t sep = u'-';
					$nc($(print(sb, t, $Formatter$DateTime::YEAR_4, l)))->append(sep);
					$nc($(print(sb, t, $Formatter$DateTime::MONTH, l)))->append(sep);
					print(sb, t, $Formatter$DateTime::DAY_OF_MONTH_0, l);
					break;
				}
			}
		default:
			{
				if (!Formatter$FormatSpecifier::$assertionsDisabled) {
					$throwNew($AssertionError);
				}
			}
		}
	} catch ($DateTimeException& x) {
		$throwNew($IllegalFormatConversionException, c, $nc($of(t))->getClass());
	}
	return sb;
}

void Formatter$FormatSpecifier::failMismatch($Formatter$Flags* f, char16_t c) {
	$var($String, fs, $nc(f)->toString());
	$throwNew($FormatFlagsConversionMismatchException, fs, c);
}

void Formatter$FormatSpecifier::failConversion(char16_t c, Object$* arg) {
	$throwNew($IllegalFormatConversionException, c, $nc($of(arg))->getClass());
}

char16_t Formatter$FormatSpecifier::getZero($Locale* l) {
	$useLocalCurrentObjectStackCache();
	if ((l != nullptr) && !l->equals($(this->this$0->locale()))) {
		$var($DecimalFormatSymbols, dfs, $DecimalFormatSymbols::getInstance(l));
		return $nc(dfs)->getZeroDigit();
	}
	return this->this$0->zero();
}

$StringBuilder* Formatter$FormatSpecifier::localizedMagnitude($StringBuilder* sb, int64_t value, $Formatter$Flags* f, int32_t width, $Locale* l) {
	return localizedMagnitude(sb, $($Long::toString(value, 10)), 0, f, width, l);
}

$StringBuilder* Formatter$FormatSpecifier::localizedMagnitude($StringBuilder* sb$renamed, $CharSequence* value, int32_t offset, $Formatter$Flags* f, int32_t width, $Locale* l) {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, sb$renamed);
	if (sb == nullptr) {
		$assign(sb, $new($StringBuilder));
	}
	int32_t begin = $nc(sb)->length();
	char16_t zero = getZero(l);
	char16_t grpSep = u'\0';
	int32_t grpSize = -1;
	char16_t decSep = u'\0';
	int32_t len = $nc(value)->length();
	int32_t dot = len;
	for (int32_t j = offset; j < len; ++j) {
		if (value->charAt(j) == u'.') {
			dot = j;
			break;
		}
	}
	if (dot < len) {
		$init($Locale);
		if (l == nullptr || $nc(l)->equals($Locale::US)) {
			decSep = u'.';
		} else {
			$var($DecimalFormatSymbols, dfs, $DecimalFormatSymbols::getInstance(l));
			decSep = $nc(dfs)->getDecimalSeparator();
		}
	}
	$init($Formatter$Flags);
	if ($nc(f)->contains($Formatter$Flags::GROUP)) {
		$init($Locale);
		if (l == nullptr || $nc(l)->equals($Locale::US)) {
			grpSep = u',';
			grpSize = 3;
		} else {
			$var($DecimalFormatSymbols, dfs, $DecimalFormatSymbols::getInstance(l));
			grpSep = $nc(dfs)->getGroupingSeparator();
			$var($DecimalFormat, df, nullptr);
			$var($NumberFormat, nf, $NumberFormat::getNumberInstance(l));
			if ($instanceOf($DecimalFormat, nf)) {
				$assign(df, $cast($DecimalFormat, nf));
			} else {
				$load($NumberFormatProvider);
				$var($LocaleProviderAdapter, adapter, $LocaleProviderAdapter::getAdapter($NumberFormatProvider::class$, l));
				if (!($instanceOf($ResourceBundleBasedAdapter, adapter))) {
					$assign(adapter, $LocaleProviderAdapter::getResourceBundleBased());
				}
				$var($StringArray, all, $nc($($nc(adapter)->getLocaleResources(l)))->getNumberPatterns());
				$assign(df, $new($DecimalFormat, $nc(all)->get(0), dfs));
			}
			grpSize = $nc(df)->getGroupingSize();
			if (!df->isGroupingUsed() || grpSize == 0) {
				grpSep = u'\0';
			}
		}
	}
	for (int32_t j = offset; j < len; ++j) {
		if (j == dot) {
			sb->append(decSep);
			grpSep = u'\0';
			continue;
		}
		char16_t c = value->charAt(j);
		sb->append((char16_t)((c - u'0') + zero));
		if (grpSep != u'\0' && j != dot - 1 && ($mod((dot - j), grpSize) == 1)) {
			sb->append(grpSep);
		}
	}
	if (width != -1 && $nc(f)->contains($Formatter$Flags::ZERO_PAD)) {
		for (int32_t k = sb->length(); k < width; ++k) {
			sb->insert(begin, zero);
		}
	}
	return sb;
}

void Formatter$FormatSpecifier::localizedMagnitudeExp($StringBuilder* sb, $chars* value, int32_t offset, $Locale* l) {
	char16_t zero = getZero(l);
	int32_t len = $nc(value)->length;
	for (int32_t j = offset; j < len; ++j) {
		char16_t c = value->get(j);
		$nc(sb)->append((char16_t)((c - u'0') + zero));
	}
}

void clinit$Formatter$FormatSpecifier($Class* class$) {
	$load($Formatter);
	Formatter$FormatSpecifier::$assertionsDisabled = !$Formatter::class$->desiredAssertionStatus();
}

Formatter$FormatSpecifier::Formatter$FormatSpecifier() {
}

$Class* Formatter$FormatSpecifier::load$($String* name, bool initialize) {
	$loadClass(Formatter$FormatSpecifier, name, initialize, &_Formatter$FormatSpecifier_ClassInfo_, clinit$Formatter$FormatSpecifier, allocate$Formatter$FormatSpecifier);
	return class$;
}

$Class* Formatter$FormatSpecifier::class$ = nullptr;

	} // util
} // java