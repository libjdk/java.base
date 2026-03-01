#include <java/time/chrono/Chronology.h>

#include <java/lang/Comparable.h>
#include <java/lang/Math.h>
#include <java/time/Clock.h>
#include <java/time/DateTimeException.h>
#include <java/time/Instant.h>
#include <java/time/LocalDate.h>
#include <java/time/LocalTime.h>
#include <java/time/ZoneId.h>
#include <java/time/ZoneOffset.h>
#include <java/time/chrono/AbstractChronology.h>
#include <java/time/chrono/ChronoLocalDate.h>
#include <java/time/chrono/ChronoLocalDateTime.h>
#include <java/time/chrono/ChronoLocalDateTimeImpl.h>
#include <java/time/chrono/ChronoPeriod.h>
#include <java/time/chrono/ChronoPeriodImpl.h>
#include <java/time/chrono/ChronoZonedDateTime.h>
#include <java/time/chrono/ChronoZonedDateTimeImpl.h>
#include <java/time/chrono/Chronology$1.h>
#include <java/time/chrono/Era.h>
#include <java/time/chrono/IsoChronology.h>
#include <java/time/format/DateTimeFormatter.h>
#include <java/time/format/DateTimeFormatterBuilder.h>
#include <java/time/format/ResolverStyle.h>
#include <java/time/format/TextStyle.h>
#include <java/time/temporal/ChronoField.h>
#include <java/time/temporal/Temporal.h>
#include <java/time/temporal/TemporalAccessor.h>
#include <java/time/temporal/TemporalQueries.h>
#include <java/time/temporal/TemporalQuery.h>
#include <java/time/temporal/ValueRange.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Set.h>
#include <jcpp.h>

#undef HOUR_OF_DAY
#undef INSTANCE
#undef MINUTE_OF_HOUR
#undef SECOND_OF_MINUTE

using $ClassInfo = ::java::lang::ClassInfo;
using $Comparable = ::java::lang::Comparable;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $Clock = ::java::time::Clock;
using $DateTimeException = ::java::time::DateTimeException;
using $Instant = ::java::time::Instant;
using $LocalDate = ::java::time::LocalDate;
using $LocalTime = ::java::time::LocalTime;
using $ZoneId = ::java::time::ZoneId;
using $ZoneOffset = ::java::time::ZoneOffset;
using $AbstractChronology = ::java::time::chrono::AbstractChronology;
using $ChronoLocalDate = ::java::time::chrono::ChronoLocalDate;
using $ChronoLocalDateTime = ::java::time::chrono::ChronoLocalDateTime;
using $ChronoLocalDateTimeImpl = ::java::time::chrono::ChronoLocalDateTimeImpl;
using $ChronoPeriod = ::java::time::chrono::ChronoPeriod;
using $ChronoPeriodImpl = ::java::time::chrono::ChronoPeriodImpl;
using $ChronoZonedDateTime = ::java::time::chrono::ChronoZonedDateTime;
using $ChronoZonedDateTimeImpl = ::java::time::chrono::ChronoZonedDateTimeImpl;
using $Chronology$1 = ::java::time::chrono::Chronology$1;
using $Era = ::java::time::chrono::Era;
using $IsoChronology = ::java::time::chrono::IsoChronology;
using $DateTimeFormatter = ::java::time::format::DateTimeFormatter;
using $DateTimeFormatterBuilder = ::java::time::format::DateTimeFormatterBuilder;
using $ResolverStyle = ::java::time::format::ResolverStyle;
using $TextStyle = ::java::time::format::TextStyle;
using $ChronoField = ::java::time::temporal::ChronoField;
using $Temporal = ::java::time::temporal::Temporal;
using $TemporalAccessor = ::java::time::temporal::TemporalAccessor;
using $TemporalQueries = ::java::time::temporal::TemporalQueries;
using $ValueRange = ::java::time::temporal::ValueRange;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $Objects = ::java::util::Objects;
using $Set = ::java::util::Set;

namespace java {
	namespace time {
		namespace chrono {

$MethodInfo _Chronology_MethodInfo_[] = {
	{"compareTo", "(Ljava/time/chrono/Chronology;)I", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Chronology, compareTo, int32_t, Chronology*)},
	{"compareTo", "(Ljava/lang/Object;)I", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(Chronology, compareTo, int32_t, Object$*)},
	{"date", "(Ljava/time/chrono/Era;III)Ljava/time/chrono/ChronoLocalDate;", nullptr, $PUBLIC, $virtualMethod(Chronology, date, $ChronoLocalDate*, $Era*, int32_t, int32_t, int32_t)},
	{"date", "(III)Ljava/time/chrono/ChronoLocalDate;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Chronology, date, $ChronoLocalDate*, int32_t, int32_t, int32_t)},
	{"date", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/chrono/ChronoLocalDate;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Chronology, date, $ChronoLocalDate*, $TemporalAccessor*)},
	{"dateEpochDay", "(J)Ljava/time/chrono/ChronoLocalDate;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Chronology, dateEpochDay, $ChronoLocalDate*, int64_t)},
	{"dateNow", "()Ljava/time/chrono/ChronoLocalDate;", nullptr, $PUBLIC, $virtualMethod(Chronology, dateNow, $ChronoLocalDate*)},
	{"dateNow", "(Ljava/time/ZoneId;)Ljava/time/chrono/ChronoLocalDate;", nullptr, $PUBLIC, $virtualMethod(Chronology, dateNow, $ChronoLocalDate*, $ZoneId*)},
	{"dateNow", "(Ljava/time/Clock;)Ljava/time/chrono/ChronoLocalDate;", nullptr, $PUBLIC, $virtualMethod(Chronology, dateNow, $ChronoLocalDate*, $Clock*)},
	{"dateYearDay", "(Ljava/time/chrono/Era;II)Ljava/time/chrono/ChronoLocalDate;", nullptr, $PUBLIC, $virtualMethod(Chronology, dateYearDay, $ChronoLocalDate*, $Era*, int32_t, int32_t)},
	{"dateYearDay", "(II)Ljava/time/chrono/ChronoLocalDate;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Chronology, dateYearDay, $ChronoLocalDate*, int32_t, int32_t)},
	{"epochSecond", "(IIIIIILjava/time/ZoneOffset;)J", nullptr, $PUBLIC, $virtualMethod(Chronology, epochSecond, int64_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, $ZoneOffset*)},
	{"epochSecond", "(Ljava/time/chrono/Era;IIIIIILjava/time/ZoneOffset;)J", nullptr, $PUBLIC, $virtualMethod(Chronology, epochSecond, int64_t, $Era*, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, $ZoneOffset*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"eraOf", "(I)Ljava/time/chrono/Era;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Chronology, eraOf, $Era*, int32_t)},
	{"eras", "()Ljava/util/List;", "()Ljava/util/List<Ljava/time/chrono/Era;>;", $PUBLIC | $ABSTRACT, $virtualMethod(Chronology, eras, $List*)},
	{"from", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/chrono/Chronology;", nullptr, $PUBLIC | $STATIC, $staticMethod(Chronology, from, Chronology*, $TemporalAccessor*)},
	{"getAvailableChronologies", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/time/chrono/Chronology;>;", $PUBLIC | $STATIC, $staticMethod(Chronology, getAvailableChronologies, $Set*)},
	{"getCalendarType", "()Ljava/lang/String;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Chronology, getCalendarType, $String*)},
	{"getDisplayName", "(Ljava/time/format/TextStyle;Ljava/util/Locale;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Chronology, getDisplayName, $String*, $TextStyle*, $Locale*)},
	{"getId", "()Ljava/lang/String;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Chronology, getId, $String*)},
	{"hashCode", "()I", nullptr, $PUBLIC | $ABSTRACT},
	{"isLeapYear", "(J)Z", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Chronology, isLeapYear, bool, int64_t)},
	{"localDateTime", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/chrono/ChronoLocalDateTime;", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/chrono/ChronoLocalDateTime<+Ljava/time/chrono/ChronoLocalDate;>;", $PUBLIC, $virtualMethod(Chronology, localDateTime, $ChronoLocalDateTime*, $TemporalAccessor*)},
	{"of", "(Ljava/lang/String;)Ljava/time/chrono/Chronology;", nullptr, $PUBLIC | $STATIC, $staticMethod(Chronology, of, Chronology*, $String*)},
	{"ofLocale", "(Ljava/util/Locale;)Ljava/time/chrono/Chronology;", nullptr, $PUBLIC | $STATIC, $staticMethod(Chronology, ofLocale, Chronology*, $Locale*)},
	{"period", "(III)Ljava/time/chrono/ChronoPeriod;", nullptr, $PUBLIC, $virtualMethod(Chronology, period, $ChronoPeriod*, int32_t, int32_t, int32_t)},
	{"prolepticYear", "(Ljava/time/chrono/Era;I)I", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Chronology, prolepticYear, int32_t, $Era*, int32_t)},
	{"range", "(Ljava/time/temporal/ChronoField;)Ljava/time/temporal/ValueRange;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Chronology, range, $ValueRange*, $ChronoField*)},
	{"resolveDate", "(Ljava/util/Map;Ljava/time/format/ResolverStyle;)Ljava/time/chrono/ChronoLocalDate;", "(Ljava/util/Map<Ljava/time/temporal/TemporalField;Ljava/lang/Long;>;Ljava/time/format/ResolverStyle;)Ljava/time/chrono/ChronoLocalDate;", $PUBLIC | $ABSTRACT, $virtualMethod(Chronology, resolveDate, $ChronoLocalDate*, $Map*, $ResolverStyle*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC | $ABSTRACT},
	{"zonedDateTime", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/chrono/ChronoZonedDateTime;", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/chrono/ChronoZonedDateTime<+Ljava/time/chrono/ChronoLocalDate;>;", $PUBLIC, $virtualMethod(Chronology, zonedDateTime, $ChronoZonedDateTime*, $TemporalAccessor*)},
	{"zonedDateTime", "(Ljava/time/Instant;Ljava/time/ZoneId;)Ljava/time/chrono/ChronoZonedDateTime;", "(Ljava/time/Instant;Ljava/time/ZoneId;)Ljava/time/chrono/ChronoZonedDateTime<+Ljava/time/chrono/ChronoLocalDate;>;", $PUBLIC, $virtualMethod(Chronology, zonedDateTime, $ChronoZonedDateTime*, $Instant*, $ZoneId*)},
	{}
};

$InnerClassInfo _Chronology_InnerClassesInfo_[] = {
	{"java.time.chrono.Chronology$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Chronology_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"java.time.chrono.Chronology",
	nullptr,
	"java.lang.Comparable",
	nullptr,
	_Chronology_MethodInfo_,
	"Ljava/lang/Object;Ljava/lang/Comparable<Ljava/time/chrono/Chronology;>;",
	nullptr,
	_Chronology_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.time.chrono.Chronology$1"
};

$Object* allocate$Chronology($Class* clazz) {
	return $of($alloc(Chronology));
}

bool Chronology::equals(Object$* obj) {
	 return this->$Comparable::equals(obj);
}

int32_t Chronology::hashCode() {
	 return this->$Comparable::hashCode();
}

$String* Chronology::toString() {
	 return this->$Comparable::toString();
}

Chronology* Chronology::from($TemporalAccessor* temporal) {
	$init(Chronology);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(temporal), "temporal"_s);
	$var(Chronology, obj, $cast(Chronology, $nc(temporal)->query($($TemporalQueries::chronology()))));
	$init($IsoChronology);
	return $cast(Chronology, $Objects::requireNonNullElse(obj, $IsoChronology::INSTANCE));
}

Chronology* Chronology::ofLocale($Locale* locale) {
	$init(Chronology);
	return $AbstractChronology::ofLocale(locale);
}

Chronology* Chronology::of($String* id) {
	$init(Chronology);
	return $AbstractChronology::of(id);
}

$Set* Chronology::getAvailableChronologies() {
	$init(Chronology);
	return $AbstractChronology::getAvailableChronologies();
}

$ChronoLocalDate* Chronology::date($Era* era, int32_t yearOfEra, int32_t month, int32_t dayOfMonth) {
	return date(prolepticYear(era, yearOfEra), month, dayOfMonth);
}

$ChronoLocalDate* Chronology::dateYearDay($Era* era, int32_t yearOfEra, int32_t dayOfYear) {
	return dateYearDay(prolepticYear(era, yearOfEra), dayOfYear);
}

$ChronoLocalDate* Chronology::dateNow() {
	return dateNow($($Clock::systemDefaultZone()));
}

$ChronoLocalDate* Chronology::dateNow($ZoneId* zone) {
	return dateNow($($Clock::system(zone)));
}

$ChronoLocalDate* Chronology::dateNow($Clock* clock) {
	$Objects::requireNonNull($of(clock), "clock"_s);
	return date($($LocalDate::now(clock)));
}

$ChronoLocalDateTime* Chronology::localDateTime($TemporalAccessor* temporal) {
	$useLocalCurrentObjectStackCache();
	try {
		return $nc($(date(temporal)))->atTime($($LocalTime::from(temporal)));
	} catch ($DateTimeException& ex) {
		$throwNew($DateTimeException, $$str({"Unable to obtain ChronoLocalDateTime from TemporalAccessor: "_s, $nc($of(temporal))->getClass()}), ex);
	}
	$shouldNotReachHere();
}

$ChronoZonedDateTime* Chronology::zonedDateTime($TemporalAccessor* temporal) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($ZoneId, zone, $ZoneId::from(temporal));
		try {
			$var($Instant, instant, $Instant::from(temporal));
			return zonedDateTime(instant, zone);
		} catch ($DateTimeException& ex1) {
			$var($ChronoLocalDateTimeImpl, cldt, $ChronoLocalDateTimeImpl::ensureValid(this, $(localDateTime(temporal))));
			return $ChronoZonedDateTimeImpl::ofBest(cldt, zone, nullptr);
		}
	} catch ($DateTimeException& ex) {
		$throwNew($DateTimeException, $$str({"Unable to obtain ChronoZonedDateTime from TemporalAccessor: "_s, $nc($of(temporal))->getClass()}), ex);
	}
	$shouldNotReachHere();
}

$ChronoZonedDateTime* Chronology::zonedDateTime($Instant* instant, $ZoneId* zone) {
	return $ChronoZonedDateTimeImpl::ofInstant(this, instant, zone);
}

$String* Chronology::getDisplayName($TextStyle* style, $Locale* locale) {
	$useLocalCurrentObjectStackCache();
	$var($TemporalAccessor, temporal, $new($Chronology$1, this));
	return $nc($($nc($($$new($DateTimeFormatterBuilder)->appendChronologyText(style)))->toFormatter(locale)))->format(temporal);
}

$ChronoPeriod* Chronology::period(int32_t years, int32_t months, int32_t days) {
	return $new($ChronoPeriodImpl, this, years, months, days);
}

int64_t Chronology::epochSecond(int32_t prolepticYear, int32_t month, int32_t dayOfMonth, int32_t hour, int32_t minute, int32_t second, $ZoneOffset* zoneOffset) {
	$Objects::requireNonNull($of(zoneOffset), "zoneOffset"_s);
	$init($ChronoField);
	$ChronoField::HOUR_OF_DAY->checkValidValue(hour);
	$ChronoField::MINUTE_OF_HOUR->checkValidValue(minute);
	$ChronoField::SECOND_OF_MINUTE->checkValidValue(second);
	int64_t daysInSec = $Math::multiplyExact($nc($(date(prolepticYear, month, dayOfMonth)))->toEpochDay(), 0x00015180);
	int64_t timeinSec = (hour * 60 + minute) * 60 + second;
	return $Math::addExact(daysInSec, timeinSec - $nc(zoneOffset)->getTotalSeconds());
}

int64_t Chronology::epochSecond($Era* era, int32_t yearOfEra, int32_t month, int32_t dayOfMonth, int32_t hour, int32_t minute, int32_t second, $ZoneOffset* zoneOffset) {
	$Objects::requireNonNull($of(era), "era"_s);
	return epochSecond(prolepticYear(era, yearOfEra), month, dayOfMonth, hour, minute, second, zoneOffset);
}

int32_t Chronology::compareTo(Object$* other) {
	return this->compareTo($cast(Chronology, other));
}

$Class* Chronology::load$($String* name, bool initialize) {
	$loadClass(Chronology, name, initialize, &_Chronology_ClassInfo_, allocate$Chronology);
	return class$;
}

$Class* Chronology::class$ = nullptr;

		} // chrono
	} // time
} // java