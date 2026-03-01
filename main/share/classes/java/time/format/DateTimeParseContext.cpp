#include <java/time/format/DateTimeParseContext.h>

#include <java/lang/CharSequence.h>
#include <java/time/ZoneId.h>
#include <java/time/chrono/Chronology.h>
#include <java/time/chrono/IsoChronology.h>
#include <java/time/format/DateTimeFormatter.h>
#include <java/time/format/DateTimeFormatterBuilder$DayPeriod.h>
#include <java/time/format/DecimalStyle.h>
#include <java/time/format/Parsed.h>
#include <java/time/format/ResolverStyle.h>
#include <java/time/temporal/TemporalAccessor.h>
#include <java/time/temporal/TemporalField.h>
#include <java/util/ArrayList.h>
#include <java/util/Locale.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Set.h>
#include <java/util/function/Consumer.h>
#include <jcpp.h>

#undef INSTANCE

using $ConsumerArray = $Array<::java::util::function::Consumer>;
using $CharSequence = ::java::lang::CharSequence;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $ZoneId = ::java::time::ZoneId;
using $Chronology = ::java::time::chrono::Chronology;
using $IsoChronology = ::java::time::chrono::IsoChronology;
using $DateTimeFormatter = ::java::time::format::DateTimeFormatter;
using $DateTimeFormatterBuilder$DayPeriod = ::java::time::format::DateTimeFormatterBuilder$DayPeriod;
using $DecimalStyle = ::java::time::format::DecimalStyle;
using $Parsed = ::java::time::format::Parsed;
using $ResolverStyle = ::java::time::format::ResolverStyle;
using $TemporalAccessor = ::java::time::temporal::TemporalAccessor;
using $TemporalField = ::java::time::temporal::TemporalField;
using $ArrayList = ::java::util::ArrayList;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $Objects = ::java::util::Objects;
using $Set = ::java::util::Set;
using $Consumer = ::java::util::function::Consumer;

namespace java {
	namespace time {
		namespace format {

$FieldInfo _DateTimeParseContext_FieldInfo_[] = {
	{"formatter", "Ljava/time/format/DateTimeFormatter;", nullptr, $PRIVATE, $field(DateTimeParseContext, formatter)},
	{"caseSensitive", "Z", nullptr, $PRIVATE, $field(DateTimeParseContext, caseSensitive)},
	{"strict", "Z", nullptr, $PRIVATE, $field(DateTimeParseContext, strict)},
	{"parsed", "Ljava/util/ArrayList;", "Ljava/util/ArrayList<Ljava/time/format/Parsed;>;", $PRIVATE | $FINAL, $field(DateTimeParseContext, parsed)},
	{"chronoListeners", "Ljava/util/ArrayList;", "Ljava/util/ArrayList<Ljava/util/function/Consumer<Ljava/time/chrono/Chronology;>;>;", $PRIVATE, $field(DateTimeParseContext, chronoListeners)},
	{}
};

$MethodInfo _DateTimeParseContext_MethodInfo_[] = {
	{"<init>", "(Ljava/time/format/DateTimeFormatter;)V", nullptr, 0, $method(DateTimeParseContext, init$, void, $DateTimeFormatter*)},
	{"addChronoChangedListener", "(Ljava/util/function/Consumer;)V", "(Ljava/util/function/Consumer<Ljava/time/chrono/Chronology;>;)V", 0, $method(DateTimeParseContext, addChronoChangedListener, void, $Consumer*)},
	{"charEquals", "(CC)Z", nullptr, 0, $method(DateTimeParseContext, charEquals, bool, char16_t, char16_t)},
	{"charEqualsIgnoreCase", "(CC)Z", nullptr, $STATIC, $staticMethod(DateTimeParseContext, charEqualsIgnoreCase, bool, char16_t, char16_t)},
	{"copy", "()Ljava/time/format/DateTimeParseContext;", nullptr, 0, $method(DateTimeParseContext, copy, DateTimeParseContext*)},
	{"currentParsed", "()Ljava/time/format/Parsed;", nullptr, $PRIVATE, $method(DateTimeParseContext, currentParsed, $Parsed*)},
	{"endOptional", "(Z)V", nullptr, 0, $method(DateTimeParseContext, endOptional, void, bool)},
	{"getDecimalStyle", "()Ljava/time/format/DecimalStyle;", nullptr, 0, $method(DateTimeParseContext, getDecimalStyle, $DecimalStyle*)},
	{"getEffectiveChronology", "()Ljava/time/chrono/Chronology;", nullptr, 0, $method(DateTimeParseContext, getEffectiveChronology, $Chronology*)},
	{"getLocale", "()Ljava/util/Locale;", nullptr, 0, $method(DateTimeParseContext, getLocale, $Locale*)},
	{"getParsed", "(Ljava/time/temporal/TemporalField;)Ljava/lang/Long;", nullptr, 0, $method(DateTimeParseContext, getParsed, $Long*, $TemporalField*)},
	{"isCaseSensitive", "()Z", nullptr, 0, $method(DateTimeParseContext, isCaseSensitive, bool)},
	{"isStrict", "()Z", nullptr, 0, $method(DateTimeParseContext, isStrict, bool)},
	{"setCaseSensitive", "(Z)V", nullptr, 0, $method(DateTimeParseContext, setCaseSensitive, void, bool)},
	{"setParsed", "(Ljava/time/chrono/Chronology;)V", nullptr, 0, $method(DateTimeParseContext, setParsed, void, $Chronology*)},
	{"setParsed", "(Ljava/time/ZoneId;)V", nullptr, 0, $method(DateTimeParseContext, setParsed, void, $ZoneId*)},
	{"setParsedDayPeriod", "(Ljava/time/format/DateTimeFormatterBuilder$DayPeriod;)V", nullptr, 0, $method(DateTimeParseContext, setParsedDayPeriod, void, $DateTimeFormatterBuilder$DayPeriod*)},
	{"setParsedField", "(Ljava/time/temporal/TemporalField;JII)I", nullptr, 0, $method(DateTimeParseContext, setParsedField, int32_t, $TemporalField*, int64_t, int32_t, int32_t)},
	{"setParsedLeapSecond", "()V", nullptr, 0, $method(DateTimeParseContext, setParsedLeapSecond, void)},
	{"setStrict", "(Z)V", nullptr, 0, $method(DateTimeParseContext, setStrict, void, bool)},
	{"startOptional", "()V", nullptr, 0, $method(DateTimeParseContext, startOptional, void)},
	{"subSequenceEquals", "(Ljava/lang/CharSequence;ILjava/lang/CharSequence;II)Z", nullptr, 0, $method(DateTimeParseContext, subSequenceEquals, bool, $CharSequence*, int32_t, $CharSequence*, int32_t, int32_t)},
	{"toResolved", "(Ljava/time/format/ResolverStyle;Ljava/util/Set;)Ljava/time/temporal/TemporalAccessor;", "(Ljava/time/format/ResolverStyle;Ljava/util/Set<Ljava/time/temporal/TemporalField;>;)Ljava/time/temporal/TemporalAccessor;", 0, $method(DateTimeParseContext, toResolved, $TemporalAccessor*, $ResolverStyle*, $Set*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(DateTimeParseContext, toString, $String*)},
	{"toUnresolved", "()Ljava/time/format/Parsed;", nullptr, 0, $method(DateTimeParseContext, toUnresolved, $Parsed*)},
	{}
};

$ClassInfo _DateTimeParseContext_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.time.format.DateTimeParseContext",
	"java.lang.Object",
	nullptr,
	_DateTimeParseContext_FieldInfo_,
	_DateTimeParseContext_MethodInfo_
};

$Object* allocate$DateTimeParseContext($Class* clazz) {
	return $of($alloc(DateTimeParseContext));
}

void DateTimeParseContext::init$($DateTimeFormatter* formatter) {
	this->caseSensitive = true;
	this->strict = true;
	$set(this, parsed, $new($ArrayList));
	$set(this, chronoListeners, nullptr);
	$set(this, formatter, formatter);
	$nc(this->parsed)->add($$new($Parsed));
}

DateTimeParseContext* DateTimeParseContext::copy() {
	$var(DateTimeParseContext, newContext, $new(DateTimeParseContext, this->formatter));
	newContext->caseSensitive = this->caseSensitive;
	newContext->strict = this->strict;
	return newContext;
}

$Locale* DateTimeParseContext::getLocale() {
	return $nc(this->formatter)->getLocale();
}

$DecimalStyle* DateTimeParseContext::getDecimalStyle() {
	return $nc(this->formatter)->getDecimalStyle();
}

$Chronology* DateTimeParseContext::getEffectiveChronology() {
	$useLocalCurrentObjectStackCache();
	$var($Chronology, chrono, $nc($(currentParsed()))->chrono);
	if (chrono == nullptr) {
		$assign(chrono, $nc(this->formatter)->getChronology());
		if (chrono == nullptr) {
			$init($IsoChronology);
			$assign(chrono, $IsoChronology::INSTANCE);
		}
	}
	return chrono;
}

bool DateTimeParseContext::isCaseSensitive() {
	return this->caseSensitive;
}

void DateTimeParseContext::setCaseSensitive(bool caseSensitive) {
	this->caseSensitive = caseSensitive;
}

bool DateTimeParseContext::subSequenceEquals($CharSequence* cs1, int32_t offset1, $CharSequence* cs2, int32_t offset2, int32_t length) {
	bool var$0 = offset1 + length > $nc(cs1)->length();
	if (var$0 || offset2 + length > $nc(cs2)->length()) {
		return false;
	}
	if (isCaseSensitive()) {
		for (int32_t i = 0; i < length; ++i) {
			char16_t ch1 = $nc(cs1)->charAt(offset1 + i);
			char16_t ch2 = $nc(cs2)->charAt(offset2 + i);
			if (ch1 != ch2) {
				return false;
			}
		}
	} else {
		for (int32_t i = 0; i < length; ++i) {
			char16_t ch1 = $nc(cs1)->charAt(offset1 + i);
			char16_t ch2 = $nc(cs2)->charAt(offset2 + i);
			bool var$2 = ch1 != ch2;
			if (var$2) {
				char16_t var$3 = $Character::toUpperCase(ch1);
				var$2 = var$3 != $Character::toUpperCase(ch2);
			}
			bool var$1 = var$2;
			if (var$1) {
				char16_t var$4 = $Character::toLowerCase(ch1);
				var$1 = var$4 != $Character::toLowerCase(ch2);
			}
			if (var$1) {
				return false;
			}
		}
	}
	return true;
}

bool DateTimeParseContext::charEquals(char16_t ch1, char16_t ch2) {
	if (isCaseSensitive()) {
		return ch1 == ch2;
	}
	return charEqualsIgnoreCase(ch1, ch2);
}

bool DateTimeParseContext::charEqualsIgnoreCase(char16_t c1, char16_t c2) {
	bool var$1 = c1 == c2;
	if (!var$1) {
		char16_t var$2 = $Character::toUpperCase(c1);
		var$1 = var$2 == $Character::toUpperCase(c2);
	}
	bool var$0 = var$1;
	if (!var$0) {
		char16_t var$3 = $Character::toLowerCase(c1);
		var$0 = var$3 == $Character::toLowerCase(c2);
	}
	return var$0;
}

bool DateTimeParseContext::isStrict() {
	return this->strict;
}

void DateTimeParseContext::setStrict(bool strict) {
	this->strict = strict;
}

void DateTimeParseContext::startOptional() {
	$useLocalCurrentObjectStackCache();
	$nc(this->parsed)->add($($nc($(currentParsed()))->copy()));
}

void DateTimeParseContext::endOptional(bool successful) {
	if (successful) {
		$nc(this->parsed)->remove($nc(this->parsed)->size() - 2);
	} else {
		$nc(this->parsed)->remove($nc(this->parsed)->size() - 1);
	}
}

$Parsed* DateTimeParseContext::currentParsed() {
	return $cast($Parsed, $nc(this->parsed)->get($nc(this->parsed)->size() - 1));
}

$Parsed* DateTimeParseContext::toUnresolved() {
	return currentParsed();
}

$TemporalAccessor* DateTimeParseContext::toResolved($ResolverStyle* resolverStyle, $Set* resolverFields) {
	$var($Parsed, parsed, currentParsed());
	$set($nc(parsed), chrono, getEffectiveChronology());
	$set(parsed, zone, parsed->zone != nullptr ? parsed->zone : $nc(this->formatter)->getZone());
	return parsed->resolve(resolverStyle, resolverFields);
}

$Long* DateTimeParseContext::getParsed($TemporalField* field) {
	return $cast($Long, $nc($nc($(currentParsed()))->fieldValues)->get(field));
}

int32_t DateTimeParseContext::setParsedField($TemporalField* field, int64_t value, int32_t errorPos, int32_t successPos) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(field), "field"_s);
	$var($Long, old, $cast($Long, $nc($nc($(currentParsed()))->fieldValues)->put(field, $($Long::valueOf(value)))));
	return (old != nullptr && old->longValue() != value) ? ~errorPos : successPos;
}

void DateTimeParseContext::setParsed($Chronology* chrono) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(chrono), "chrono"_s);
	$set($nc($(currentParsed())), chrono, chrono);
	if (this->chronoListeners != nullptr && !$nc(this->chronoListeners)->isEmpty()) {
		$var($ConsumerArray, tmp, $new($ConsumerArray, 1));
		$var($ConsumerArray, listeners, $fcast($ConsumerArray, $nc(this->chronoListeners)->toArray(tmp)));
		$nc(this->chronoListeners)->clear();
		{
			$var($ConsumerArray, arr$, listeners);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($Consumer, l, arr$->get(i$));
				{
					$nc(l)->accept(chrono);
				}
			}
		}
	}
}

void DateTimeParseContext::addChronoChangedListener($Consumer* listener) {
	if (this->chronoListeners == nullptr) {
		$set(this, chronoListeners, $new($ArrayList));
	}
	$nc(this->chronoListeners)->add(listener);
}

void DateTimeParseContext::setParsed($ZoneId* zone) {
	$Objects::requireNonNull($of(zone), "zone"_s);
	$set($nc($(currentParsed())), zone, zone);
}

void DateTimeParseContext::setParsedLeapSecond() {
	$nc($(currentParsed()))->leapSecond = true;
}

void DateTimeParseContext::setParsedDayPeriod($DateTimeFormatterBuilder$DayPeriod* dayPeriod) {
	$set($nc($(currentParsed())), dayPeriod, dayPeriod);
}

$String* DateTimeParseContext::toString() {
	return $nc($(currentParsed()))->toString();
}

DateTimeParseContext::DateTimeParseContext() {
}

$Class* DateTimeParseContext::load$($String* name, bool initialize) {
	$loadClass(DateTimeParseContext, name, initialize, &_DateTimeParseContext_ClassInfo_, allocate$DateTimeParseContext);
	return class$;
}

$Class* DateTimeParseContext::class$ = nullptr;

		} // format
	} // time
} // java