#include <java/time/chrono/ThaiBuddhistChronology.h>

#include <java/io/InvalidObjectException.h>
#include <java/io/ObjectInputStream.h>
#include <java/lang/ClassCastException.h>
#include <java/time/Clock.h>
#include <java/time/Instant.h>
#include <java/time/LocalDate.h>
#include <java/time/ZoneId.h>
#include <java/time/chrono/AbstractChronology.h>
#include <java/time/chrono/ChronoLocalDate.h>
#include <java/time/chrono/ChronoLocalDateTime.h>
#include <java/time/chrono/ChronoZonedDateTime.h>
#include <java/time/chrono/Chronology.h>
#include <java/time/chrono/Era.h>
#include <java/time/chrono/IsoChronology.h>
#include <java/time/chrono/ThaiBuddhistChronology$1.h>
#include <java/time/chrono/ThaiBuddhistDate.h>
#include <java/time/chrono/ThaiBuddhistEra.h>
#include <java/time/format/ResolverStyle.h>
#include <java/time/temporal/ChronoField.h>
#include <java/time/temporal/TemporalAccessor.h>
#include <java/time/temporal/ValueRange.h>
#include <java/util/HashMap.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <jcpp.h>

#undef BE
#undef ERA_FULL_NAMES
#undef ERA_NARROW_NAMES
#undef ERA_SHORT_NAMES
#undef FALLBACK_LANGUAGE
#undef INSTANCE
#undef PROLEPTIC_MONTH
#undef TARGET_LANGUAGE
#undef YEAR
#undef YEARS_DIFFERENCE

using $InvalidObjectException = ::java::io::InvalidObjectException;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ClassCastException = ::java::lang::ClassCastException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Clock = ::java::time::Clock;
using $Instant = ::java::time::Instant;
using $LocalDate = ::java::time::LocalDate;
using $ZoneId = ::java::time::ZoneId;
using $AbstractChronology = ::java::time::chrono::AbstractChronology;
using $ChronoLocalDate = ::java::time::chrono::ChronoLocalDate;
using $ChronoLocalDateTime = ::java::time::chrono::ChronoLocalDateTime;
using $ChronoZonedDateTime = ::java::time::chrono::ChronoZonedDateTime;
using $Era = ::java::time::chrono::Era;
using $IsoChronology = ::java::time::chrono::IsoChronology;
using $ThaiBuddhistChronology$1 = ::java::time::chrono::ThaiBuddhistChronology$1;
using $ThaiBuddhistDate = ::java::time::chrono::ThaiBuddhistDate;
using $ThaiBuddhistEra = ::java::time::chrono::ThaiBuddhistEra;
using $ResolverStyle = ::java::time::format::ResolverStyle;
using $ChronoField = ::java::time::temporal::ChronoField;
using $TemporalAccessor = ::java::time::temporal::TemporalAccessor;
using $ValueRange = ::java::time::temporal::ValueRange;
using $HashMap = ::java::util::HashMap;
using $List = ::java::util::List;
using $Map = ::java::util::Map;

namespace java {
	namespace time {
		namespace chrono {

$FieldInfo _ThaiBuddhistChronology_FieldInfo_[] = {
	{"INSTANCE", "Ljava/time/chrono/ThaiBuddhistChronology;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(ThaiBuddhistChronology, INSTANCE)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ThaiBuddhistChronology, serialVersionUID)},
	{"YEARS_DIFFERENCE", "I", nullptr, $STATIC | $FINAL, $constField(ThaiBuddhistChronology, YEARS_DIFFERENCE)},
	{"ERA_NARROW_NAMES", "Ljava/util/HashMap;", "Ljava/util/HashMap<Ljava/lang/String;[Ljava/lang/String;>;", $PRIVATE | $STATIC | $FINAL, $staticField(ThaiBuddhistChronology, ERA_NARROW_NAMES)},
	{"ERA_SHORT_NAMES", "Ljava/util/HashMap;", "Ljava/util/HashMap<Ljava/lang/String;[Ljava/lang/String;>;", $PRIVATE | $STATIC | $FINAL, $staticField(ThaiBuddhistChronology, ERA_SHORT_NAMES)},
	{"ERA_FULL_NAMES", "Ljava/util/HashMap;", "Ljava/util/HashMap<Ljava/lang/String;[Ljava/lang/String;>;", $PRIVATE | $STATIC | $FINAL, $staticField(ThaiBuddhistChronology, ERA_FULL_NAMES)},
	{"FALLBACK_LANGUAGE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ThaiBuddhistChronology, FALLBACK_LANGUAGE)},
	{"TARGET_LANGUAGE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ThaiBuddhistChronology, TARGET_LANGUAGE)},
	{}
};

$MethodInfo _ThaiBuddhistChronology_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC},
	{"<init>", "()V", nullptr, $PRIVATE, $method(ThaiBuddhistChronology, init$, void)},
	{"date", "(Ljava/time/chrono/Era;III)Ljava/time/chrono/ThaiBuddhistDate;", nullptr, $PUBLIC, $virtualMethod(ThaiBuddhistChronology, date, $ChronoLocalDate*, $Era*, int32_t, int32_t, int32_t)},
	{"date", "(III)Ljava/time/chrono/ThaiBuddhistDate;", nullptr, $PUBLIC, $virtualMethod(ThaiBuddhistChronology, date, $ChronoLocalDate*, int32_t, int32_t, int32_t)},
	{"date", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/chrono/ThaiBuddhistDate;", nullptr, $PUBLIC, $virtualMethod(ThaiBuddhistChronology, date, $ChronoLocalDate*, $TemporalAccessor*)},
	{"dateEpochDay", "(J)Ljava/time/chrono/ThaiBuddhistDate;", nullptr, $PUBLIC, $virtualMethod(ThaiBuddhistChronology, dateEpochDay, $ChronoLocalDate*, int64_t)},
	{"dateNow", "()Ljava/time/chrono/ThaiBuddhistDate;", nullptr, $PUBLIC, $virtualMethod(ThaiBuddhistChronology, dateNow, $ChronoLocalDate*)},
	{"dateNow", "(Ljava/time/ZoneId;)Ljava/time/chrono/ThaiBuddhistDate;", nullptr, $PUBLIC, $virtualMethod(ThaiBuddhistChronology, dateNow, $ChronoLocalDate*, $ZoneId*)},
	{"dateNow", "(Ljava/time/Clock;)Ljava/time/chrono/ThaiBuddhistDate;", nullptr, $PUBLIC, $virtualMethod(ThaiBuddhistChronology, dateNow, $ChronoLocalDate*, $Clock*)},
	{"dateYearDay", "(Ljava/time/chrono/Era;II)Ljava/time/chrono/ThaiBuddhistDate;", nullptr, $PUBLIC, $virtualMethod(ThaiBuddhistChronology, dateYearDay, $ChronoLocalDate*, $Era*, int32_t, int32_t)},
	{"dateYearDay", "(II)Ljava/time/chrono/ThaiBuddhistDate;", nullptr, $PUBLIC, $virtualMethod(ThaiBuddhistChronology, dateYearDay, $ChronoLocalDate*, int32_t, int32_t)},
	{"eraOf", "(I)Ljava/time/chrono/ThaiBuddhistEra;", nullptr, $PUBLIC, $virtualMethod(ThaiBuddhistChronology, eraOf, $Era*, int32_t)},
	{"eras", "()Ljava/util/List;", "()Ljava/util/List<Ljava/time/chrono/Era;>;", $PUBLIC, $virtualMethod(ThaiBuddhistChronology, eras, $List*)},
	{"getCalendarType", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ThaiBuddhistChronology, getCalendarType, $String*)},
	{"getId", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ThaiBuddhistChronology, getId, $String*)},
	{"isLeapYear", "(J)Z", nullptr, $PUBLIC, $virtualMethod(ThaiBuddhistChronology, isLeapYear, bool, int64_t)},
	{"localDateTime", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/chrono/ChronoLocalDateTime;", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/chrono/ChronoLocalDateTime<Ljava/time/chrono/ThaiBuddhistDate;>;", $PUBLIC, $virtualMethod(ThaiBuddhistChronology, localDateTime, $ChronoLocalDateTime*, $TemporalAccessor*)},
	{"prolepticYear", "(Ljava/time/chrono/Era;I)I", nullptr, $PUBLIC, $virtualMethod(ThaiBuddhistChronology, prolepticYear, int32_t, $Era*, int32_t)},
	{"range", "(Ljava/time/temporal/ChronoField;)Ljava/time/temporal/ValueRange;", nullptr, $PUBLIC, $virtualMethod(ThaiBuddhistChronology, range, $ValueRange*, $ChronoField*)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(ThaiBuddhistChronology, readObject, void, $ObjectInputStream*), "java.io.InvalidObjectException"},
	{"resolveDate", "(Ljava/util/Map;Ljava/time/format/ResolverStyle;)Ljava/time/chrono/ThaiBuddhistDate;", "(Ljava/util/Map<Ljava/time/temporal/TemporalField;Ljava/lang/Long;>;Ljava/time/format/ResolverStyle;)Ljava/time/chrono/ThaiBuddhistDate;", $PUBLIC, $virtualMethod(ThaiBuddhistChronology, resolveDate, $ChronoLocalDate*, $Map*, $ResolverStyle*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"writeReplace", "()Ljava/lang/Object;", nullptr, 0, $virtualMethod(ThaiBuddhistChronology, writeReplace, $Object*)},
	{"zonedDateTime", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/chrono/ChronoZonedDateTime;", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/chrono/ChronoZonedDateTime<Ljava/time/chrono/ThaiBuddhistDate;>;", $PUBLIC, $virtualMethod(ThaiBuddhistChronology, zonedDateTime, $ChronoZonedDateTime*, $TemporalAccessor*)},
	{"zonedDateTime", "(Ljava/time/Instant;Ljava/time/ZoneId;)Ljava/time/chrono/ChronoZonedDateTime;", "(Ljava/time/Instant;Ljava/time/ZoneId;)Ljava/time/chrono/ChronoZonedDateTime<Ljava/time/chrono/ThaiBuddhistDate;>;", $PUBLIC, $virtualMethod(ThaiBuddhistChronology, zonedDateTime, $ChronoZonedDateTime*, $Instant*, $ZoneId*)},
	{}
};

$InnerClassInfo _ThaiBuddhistChronology_InnerClassesInfo_[] = {
	{"java.time.chrono.ThaiBuddhistChronology$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{}
};

$ClassInfo _ThaiBuddhistChronology_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.time.chrono.ThaiBuddhistChronology",
	"java.time.chrono.AbstractChronology",
	"java.io.Serializable",
	_ThaiBuddhistChronology_FieldInfo_,
	_ThaiBuddhistChronology_MethodInfo_,
	nullptr,
	nullptr,
	_ThaiBuddhistChronology_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.time.chrono.ThaiBuddhistChronology$1"
};

$Object* allocate$ThaiBuddhistChronology($Class* clazz) {
	return $of($alloc(ThaiBuddhistChronology));
}

bool ThaiBuddhistChronology::equals(Object$* obj) {
	 return this->$AbstractChronology::equals(obj);
}

int32_t ThaiBuddhistChronology::hashCode() {
	 return this->$AbstractChronology::hashCode();
}

$String* ThaiBuddhistChronology::toString() {
	 return this->$AbstractChronology::toString();
}

$Object* ThaiBuddhistChronology::clone() {
	 return this->$AbstractChronology::clone();
}

void ThaiBuddhistChronology::finalize() {
	this->$AbstractChronology::finalize();
}

ThaiBuddhistChronology* ThaiBuddhistChronology::INSTANCE = nullptr;
$HashMap* ThaiBuddhistChronology::ERA_NARROW_NAMES = nullptr;
$HashMap* ThaiBuddhistChronology::ERA_SHORT_NAMES = nullptr;
$HashMap* ThaiBuddhistChronology::ERA_FULL_NAMES = nullptr;
$String* ThaiBuddhistChronology::FALLBACK_LANGUAGE = nullptr;
$String* ThaiBuddhistChronology::TARGET_LANGUAGE = nullptr;

void ThaiBuddhistChronology::init$() {
	$AbstractChronology::init$();
}

$String* ThaiBuddhistChronology::getId() {
	return "ThaiBuddhist"_s;
}

$String* ThaiBuddhistChronology::getCalendarType() {
	return "buddhist"_s;
}

$ChronoLocalDate* ThaiBuddhistChronology::date($Era* era, int32_t yearOfEra, int32_t month, int32_t dayOfMonth) {
	return date(prolepticYear(era, yearOfEra), month, dayOfMonth);
}

$ChronoLocalDate* ThaiBuddhistChronology::date(int32_t prolepticYear, int32_t month, int32_t dayOfMonth) {
	return $new($ThaiBuddhistDate, $($LocalDate::of(prolepticYear - ThaiBuddhistChronology::YEARS_DIFFERENCE, month, dayOfMonth)));
}

$ChronoLocalDate* ThaiBuddhistChronology::dateYearDay($Era* era, int32_t yearOfEra, int32_t dayOfYear) {
	return dateYearDay(prolepticYear(era, yearOfEra), dayOfYear);
}

$ChronoLocalDate* ThaiBuddhistChronology::dateYearDay(int32_t prolepticYear, int32_t dayOfYear) {
	return $new($ThaiBuddhistDate, $($LocalDate::ofYearDay(prolepticYear - ThaiBuddhistChronology::YEARS_DIFFERENCE, dayOfYear)));
}

$ChronoLocalDate* ThaiBuddhistChronology::dateEpochDay(int64_t epochDay) {
	return $new($ThaiBuddhistDate, $($LocalDate::ofEpochDay(epochDay)));
}

$ChronoLocalDate* ThaiBuddhistChronology::dateNow() {
	return dateNow($($Clock::systemDefaultZone()));
}

$ChronoLocalDate* ThaiBuddhistChronology::dateNow($ZoneId* zone) {
	return dateNow($($Clock::system(zone)));
}

$ChronoLocalDate* ThaiBuddhistChronology::dateNow($Clock* clock) {
	return date($($LocalDate::now(clock)));
}

$ChronoLocalDate* ThaiBuddhistChronology::date($TemporalAccessor* temporal) {
	if ($instanceOf($ThaiBuddhistDate, temporal)) {
		return $cast($ThaiBuddhistDate, temporal);
	}
	return $new($ThaiBuddhistDate, $($LocalDate::from(temporal)));
}

$ChronoLocalDateTime* ThaiBuddhistChronology::localDateTime($TemporalAccessor* temporal) {
	return $AbstractChronology::localDateTime(temporal);
}

$ChronoZonedDateTime* ThaiBuddhistChronology::zonedDateTime($TemporalAccessor* temporal) {
	return $AbstractChronology::zonedDateTime(temporal);
}

$ChronoZonedDateTime* ThaiBuddhistChronology::zonedDateTime($Instant* instant, $ZoneId* zone) {
	return $AbstractChronology::zonedDateTime(instant, zone);
}

bool ThaiBuddhistChronology::isLeapYear(int64_t prolepticYear) {
	$init($IsoChronology);
	return $nc($IsoChronology::INSTANCE)->isLeapYear(prolepticYear - ThaiBuddhistChronology::YEARS_DIFFERENCE);
}

int32_t ThaiBuddhistChronology::prolepticYear($Era* era, int32_t yearOfEra) {
	if (!($instanceOf($ThaiBuddhistEra, era))) {
		$throwNew($ClassCastException, "Era must be BuddhistEra"_s);
	}
	$init($ThaiBuddhistEra);
	return ($equals(era, $ThaiBuddhistEra::BE) ? yearOfEra : 1 - yearOfEra);
}

$Era* ThaiBuddhistChronology::eraOf(int32_t eraValue) {
	return $ThaiBuddhistEra::of(eraValue);
}

$List* ThaiBuddhistChronology::eras() {
	return $List::of($($ThaiBuddhistEra::values()));
}

$ValueRange* ThaiBuddhistChronology::range($ChronoField* field) {
	$useLocalCurrentObjectStackCache();
	$init($ThaiBuddhistChronology$1);
	switch ($nc($ThaiBuddhistChronology$1::$SwitchMap$java$time$temporal$ChronoField)->get($nc((field))->ordinal())) {
	case 1:
		{
			{
				$init($ChronoField);
				$var($ValueRange, range, $ChronoField::PROLEPTIC_MONTH->range());
				int64_t var$0 = $nc(range)->getMinimum() + ThaiBuddhistChronology::YEARS_DIFFERENCE * (int64_t)12;
				return $ValueRange::of(var$0, range->getMaximum() + ThaiBuddhistChronology::YEARS_DIFFERENCE * (int64_t)12);
			}
		}
	case 2:
		{
			{
				$init($ChronoField);
				$var($ValueRange, range, $ChronoField::YEAR->range());
				int64_t var$1 = -($nc(range)->getMinimum() + ThaiBuddhistChronology::YEARS_DIFFERENCE) + 1;
				return $ValueRange::of(1, var$1, range->getMaximum() + ThaiBuddhistChronology::YEARS_DIFFERENCE);
			}
		}
	case 3:
		{
			{
				$init($ChronoField);
				$var($ValueRange, range, $ChronoField::YEAR->range());
				int64_t var$2 = $nc(range)->getMinimum() + ThaiBuddhistChronology::YEARS_DIFFERENCE;
				return $ValueRange::of(var$2, range->getMaximum() + ThaiBuddhistChronology::YEARS_DIFFERENCE);
			}
		}
	}
	return field->range();
}

$ChronoLocalDate* ThaiBuddhistChronology::resolveDate($Map* fieldValues, $ResolverStyle* resolverStyle) {
	return $cast($ThaiBuddhistDate, $AbstractChronology::resolveDate(fieldValues, resolverStyle));
}

$Object* ThaiBuddhistChronology::writeReplace() {
	return $of($AbstractChronology::writeReplace());
}

void ThaiBuddhistChronology::readObject($ObjectInputStream* s) {
	$throwNew($InvalidObjectException, "Deserialization via serialization delegate"_s);
}

void clinit$ThaiBuddhistChronology($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(ThaiBuddhistChronology::FALLBACK_LANGUAGE, "en"_s);
	$assignStatic(ThaiBuddhistChronology::TARGET_LANGUAGE, "th"_s);
	$assignStatic(ThaiBuddhistChronology::INSTANCE, $new(ThaiBuddhistChronology));
	$assignStatic(ThaiBuddhistChronology::ERA_NARROW_NAMES, $new($HashMap));
	$assignStatic(ThaiBuddhistChronology::ERA_SHORT_NAMES, $new($HashMap));
	$assignStatic(ThaiBuddhistChronology::ERA_FULL_NAMES, $new($HashMap));
	{
		$nc(ThaiBuddhistChronology::ERA_NARROW_NAMES)->put(ThaiBuddhistChronology::FALLBACK_LANGUAGE, $$new($StringArray, {
			"BB"_s,
			"BE"_s
		}));
		$nc(ThaiBuddhistChronology::ERA_NARROW_NAMES)->put(ThaiBuddhistChronology::TARGET_LANGUAGE, $$new($StringArray, {
			"BB"_s,
			"BE"_s
		}));
		$nc(ThaiBuddhistChronology::ERA_SHORT_NAMES)->put(ThaiBuddhistChronology::FALLBACK_LANGUAGE, $$new($StringArray, {
			"B.B."_s,
			"B.E."_s
		}));
		$nc(ThaiBuddhistChronology::ERA_SHORT_NAMES)->put(ThaiBuddhistChronology::TARGET_LANGUAGE, $$new($StringArray, {
			u"พ.ศ."_s,
			u"ปีก่อนคริสต์กาลที่"_s
		}));
		$nc(ThaiBuddhistChronology::ERA_FULL_NAMES)->put(ThaiBuddhistChronology::FALLBACK_LANGUAGE, $$new($StringArray, {
			"Before Buddhist"_s,
			"Budhhist Era"_s
		}));
		$nc(ThaiBuddhistChronology::ERA_FULL_NAMES)->put(ThaiBuddhistChronology::TARGET_LANGUAGE, $$new($StringArray, {
			u"พุทธศักราช"_s,
			u"ปีก่อนคริสต์กาลที่"_s
		}));
	}
}

ThaiBuddhistChronology::ThaiBuddhistChronology() {
}

$Class* ThaiBuddhistChronology::load$($String* name, bool initialize) {
	$loadClass(ThaiBuddhistChronology, name, initialize, &_ThaiBuddhistChronology_ClassInfo_, clinit$ThaiBuddhistChronology, allocate$ThaiBuddhistChronology);
	return class$;
}

$Class* ThaiBuddhistChronology::class$ = nullptr;

		} // chrono
	} // time
} // java