#include <java/time/chrono/MinguoChronology.h>

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
#include <java/time/chrono/MinguoChronology$1.h>
#include <java/time/chrono/MinguoDate.h>
#include <java/time/chrono/MinguoEra.h>
#include <java/time/format/ResolverStyle.h>
#include <java/time/temporal/ChronoField.h>
#include <java/time/temporal/TemporalAccessor.h>
#include <java/time/temporal/ValueRange.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <jcpp.h>

#undef INSTANCE
#undef PROLEPTIC_MONTH
#undef ROC
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
using $MinguoChronology$1 = ::java::time::chrono::MinguoChronology$1;
using $MinguoDate = ::java::time::chrono::MinguoDate;
using $MinguoEra = ::java::time::chrono::MinguoEra;
using $ResolverStyle = ::java::time::format::ResolverStyle;
using $ChronoField = ::java::time::temporal::ChronoField;
using $TemporalAccessor = ::java::time::temporal::TemporalAccessor;
using $ValueRange = ::java::time::temporal::ValueRange;
using $List = ::java::util::List;
using $Map = ::java::util::Map;

namespace java {
	namespace time {
		namespace chrono {

$FieldInfo _MinguoChronology_FieldInfo_[] = {
	{"INSTANCE", "Ljava/time/chrono/MinguoChronology;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(MinguoChronology, INSTANCE)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MinguoChronology, serialVersionUID)},
	{"YEARS_DIFFERENCE", "I", nullptr, $STATIC | $FINAL, $constField(MinguoChronology, YEARS_DIFFERENCE)},
	{}
};

$MethodInfo _MinguoChronology_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC},
	{"<init>", "()V", nullptr, $PRIVATE, $method(MinguoChronology, init$, void)},
	{"date", "(Ljava/time/chrono/Era;III)Ljava/time/chrono/MinguoDate;", nullptr, $PUBLIC, $virtualMethod(MinguoChronology, date, $ChronoLocalDate*, $Era*, int32_t, int32_t, int32_t)},
	{"date", "(III)Ljava/time/chrono/MinguoDate;", nullptr, $PUBLIC, $virtualMethod(MinguoChronology, date, $ChronoLocalDate*, int32_t, int32_t, int32_t)},
	{"date", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/chrono/MinguoDate;", nullptr, $PUBLIC, $virtualMethod(MinguoChronology, date, $ChronoLocalDate*, $TemporalAccessor*)},
	{"dateEpochDay", "(J)Ljava/time/chrono/MinguoDate;", nullptr, $PUBLIC, $virtualMethod(MinguoChronology, dateEpochDay, $ChronoLocalDate*, int64_t)},
	{"dateNow", "()Ljava/time/chrono/MinguoDate;", nullptr, $PUBLIC, $virtualMethod(MinguoChronology, dateNow, $ChronoLocalDate*)},
	{"dateNow", "(Ljava/time/ZoneId;)Ljava/time/chrono/MinguoDate;", nullptr, $PUBLIC, $virtualMethod(MinguoChronology, dateNow, $ChronoLocalDate*, $ZoneId*)},
	{"dateNow", "(Ljava/time/Clock;)Ljava/time/chrono/MinguoDate;", nullptr, $PUBLIC, $virtualMethod(MinguoChronology, dateNow, $ChronoLocalDate*, $Clock*)},
	{"dateYearDay", "(Ljava/time/chrono/Era;II)Ljava/time/chrono/MinguoDate;", nullptr, $PUBLIC, $virtualMethod(MinguoChronology, dateYearDay, $ChronoLocalDate*, $Era*, int32_t, int32_t)},
	{"dateYearDay", "(II)Ljava/time/chrono/MinguoDate;", nullptr, $PUBLIC, $virtualMethod(MinguoChronology, dateYearDay, $ChronoLocalDate*, int32_t, int32_t)},
	{"eraOf", "(I)Ljava/time/chrono/MinguoEra;", nullptr, $PUBLIC, $virtualMethod(MinguoChronology, eraOf, $Era*, int32_t)},
	{"eras", "()Ljava/util/List;", "()Ljava/util/List<Ljava/time/chrono/Era;>;", $PUBLIC, $virtualMethod(MinguoChronology, eras, $List*)},
	{"getCalendarType", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(MinguoChronology, getCalendarType, $String*)},
	{"getId", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(MinguoChronology, getId, $String*)},
	{"isLeapYear", "(J)Z", nullptr, $PUBLIC, $virtualMethod(MinguoChronology, isLeapYear, bool, int64_t)},
	{"localDateTime", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/chrono/ChronoLocalDateTime;", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/chrono/ChronoLocalDateTime<Ljava/time/chrono/MinguoDate;>;", $PUBLIC, $virtualMethod(MinguoChronology, localDateTime, $ChronoLocalDateTime*, $TemporalAccessor*)},
	{"prolepticYear", "(Ljava/time/chrono/Era;I)I", nullptr, $PUBLIC, $virtualMethod(MinguoChronology, prolepticYear, int32_t, $Era*, int32_t)},
	{"range", "(Ljava/time/temporal/ChronoField;)Ljava/time/temporal/ValueRange;", nullptr, $PUBLIC, $virtualMethod(MinguoChronology, range, $ValueRange*, $ChronoField*)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(MinguoChronology, readObject, void, $ObjectInputStream*), "java.io.InvalidObjectException"},
	{"resolveDate", "(Ljava/util/Map;Ljava/time/format/ResolverStyle;)Ljava/time/chrono/MinguoDate;", "(Ljava/util/Map<Ljava/time/temporal/TemporalField;Ljava/lang/Long;>;Ljava/time/format/ResolverStyle;)Ljava/time/chrono/MinguoDate;", $PUBLIC, $virtualMethod(MinguoChronology, resolveDate, $ChronoLocalDate*, $Map*, $ResolverStyle*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"writeReplace", "()Ljava/lang/Object;", nullptr, 0, $virtualMethod(MinguoChronology, writeReplace, $Object*)},
	{"zonedDateTime", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/chrono/ChronoZonedDateTime;", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/chrono/ChronoZonedDateTime<Ljava/time/chrono/MinguoDate;>;", $PUBLIC, $virtualMethod(MinguoChronology, zonedDateTime, $ChronoZonedDateTime*, $TemporalAccessor*)},
	{"zonedDateTime", "(Ljava/time/Instant;Ljava/time/ZoneId;)Ljava/time/chrono/ChronoZonedDateTime;", "(Ljava/time/Instant;Ljava/time/ZoneId;)Ljava/time/chrono/ChronoZonedDateTime<Ljava/time/chrono/MinguoDate;>;", $PUBLIC, $virtualMethod(MinguoChronology, zonedDateTime, $ChronoZonedDateTime*, $Instant*, $ZoneId*)},
	{}
};

$InnerClassInfo _MinguoChronology_InnerClassesInfo_[] = {
	{"java.time.chrono.MinguoChronology$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{}
};

$ClassInfo _MinguoChronology_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.time.chrono.MinguoChronology",
	"java.time.chrono.AbstractChronology",
	"java.io.Serializable",
	_MinguoChronology_FieldInfo_,
	_MinguoChronology_MethodInfo_,
	nullptr,
	nullptr,
	_MinguoChronology_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.time.chrono.MinguoChronology$1"
};

$Object* allocate$MinguoChronology($Class* clazz) {
	return $of($alloc(MinguoChronology));
}

bool MinguoChronology::equals(Object$* obj) {
	 return this->$AbstractChronology::equals(obj);
}

int32_t MinguoChronology::hashCode() {
	 return this->$AbstractChronology::hashCode();
}

$String* MinguoChronology::toString() {
	 return this->$AbstractChronology::toString();
}

$Object* MinguoChronology::clone() {
	 return this->$AbstractChronology::clone();
}

void MinguoChronology::finalize() {
	this->$AbstractChronology::finalize();
}

MinguoChronology* MinguoChronology::INSTANCE = nullptr;

void MinguoChronology::init$() {
	$AbstractChronology::init$();
}

$String* MinguoChronology::getId() {
	return "Minguo"_s;
}

$String* MinguoChronology::getCalendarType() {
	return "roc"_s;
}

$ChronoLocalDate* MinguoChronology::date($Era* era, int32_t yearOfEra, int32_t month, int32_t dayOfMonth) {
	return date(prolepticYear(era, yearOfEra), month, dayOfMonth);
}

$ChronoLocalDate* MinguoChronology::date(int32_t prolepticYear, int32_t month, int32_t dayOfMonth) {
	return $new($MinguoDate, $($LocalDate::of(prolepticYear + MinguoChronology::YEARS_DIFFERENCE, month, dayOfMonth)));
}

$ChronoLocalDate* MinguoChronology::dateYearDay($Era* era, int32_t yearOfEra, int32_t dayOfYear) {
	return dateYearDay(prolepticYear(era, yearOfEra), dayOfYear);
}

$ChronoLocalDate* MinguoChronology::dateYearDay(int32_t prolepticYear, int32_t dayOfYear) {
	return $new($MinguoDate, $($LocalDate::ofYearDay(prolepticYear + MinguoChronology::YEARS_DIFFERENCE, dayOfYear)));
}

$ChronoLocalDate* MinguoChronology::dateEpochDay(int64_t epochDay) {
	return $new($MinguoDate, $($LocalDate::ofEpochDay(epochDay)));
}

$ChronoLocalDate* MinguoChronology::dateNow() {
	return dateNow($($Clock::systemDefaultZone()));
}

$ChronoLocalDate* MinguoChronology::dateNow($ZoneId* zone) {
	return dateNow($($Clock::system(zone)));
}

$ChronoLocalDate* MinguoChronology::dateNow($Clock* clock) {
	return date($($LocalDate::now(clock)));
}

$ChronoLocalDate* MinguoChronology::date($TemporalAccessor* temporal) {
	if ($instanceOf($MinguoDate, temporal)) {
		return $cast($MinguoDate, temporal);
	}
	return $new($MinguoDate, $($LocalDate::from(temporal)));
}

$ChronoLocalDateTime* MinguoChronology::localDateTime($TemporalAccessor* temporal) {
	return $AbstractChronology::localDateTime(temporal);
}

$ChronoZonedDateTime* MinguoChronology::zonedDateTime($TemporalAccessor* temporal) {
	return $AbstractChronology::zonedDateTime(temporal);
}

$ChronoZonedDateTime* MinguoChronology::zonedDateTime($Instant* instant, $ZoneId* zone) {
	return $AbstractChronology::zonedDateTime(instant, zone);
}

bool MinguoChronology::isLeapYear(int64_t prolepticYear) {
	$init($IsoChronology);
	return $nc($IsoChronology::INSTANCE)->isLeapYear(prolepticYear + MinguoChronology::YEARS_DIFFERENCE);
}

int32_t MinguoChronology::prolepticYear($Era* era, int32_t yearOfEra) {
	if (!($instanceOf($MinguoEra, era))) {
		$throwNew($ClassCastException, "Era must be MinguoEra"_s);
	}
	$init($MinguoEra);
	return ($equals(era, $MinguoEra::ROC) ? yearOfEra : 1 - yearOfEra);
}

$Era* MinguoChronology::eraOf(int32_t eraValue) {
	return $MinguoEra::of(eraValue);
}

$List* MinguoChronology::eras() {
	return $List::of($($MinguoEra::values()));
}

$ValueRange* MinguoChronology::range($ChronoField* field) {
	$useLocalCurrentObjectStackCache();
	$init($MinguoChronology$1);
	switch ($nc($MinguoChronology$1::$SwitchMap$java$time$temporal$ChronoField)->get($nc((field))->ordinal())) {
	case 1:
		{
			{
				$init($ChronoField);
				$var($ValueRange, range, $ChronoField::PROLEPTIC_MONTH->range());
				int64_t var$0 = $nc(range)->getMinimum() - MinguoChronology::YEARS_DIFFERENCE * (int64_t)12;
				return $ValueRange::of(var$0, range->getMaximum() - MinguoChronology::YEARS_DIFFERENCE * (int64_t)12);
			}
		}
	case 2:
		{
			{
				$init($ChronoField);
				$var($ValueRange, range, $ChronoField::YEAR->range());
				int64_t var$1 = $nc(range)->getMaximum() - MinguoChronology::YEARS_DIFFERENCE;
				return $ValueRange::of(1, var$1, -range->getMinimum() + 1 + MinguoChronology::YEARS_DIFFERENCE);
			}
		}
	case 3:
		{
			{
				$init($ChronoField);
				$var($ValueRange, range, $ChronoField::YEAR->range());
				int64_t var$2 = $nc(range)->getMinimum() - MinguoChronology::YEARS_DIFFERENCE;
				return $ValueRange::of(var$2, range->getMaximum() - MinguoChronology::YEARS_DIFFERENCE);
			}
		}
	}
	return field->range();
}

$ChronoLocalDate* MinguoChronology::resolveDate($Map* fieldValues, $ResolverStyle* resolverStyle) {
	return $cast($MinguoDate, $AbstractChronology::resolveDate(fieldValues, resolverStyle));
}

$Object* MinguoChronology::writeReplace() {
	return $of($AbstractChronology::writeReplace());
}

void MinguoChronology::readObject($ObjectInputStream* s) {
	$throwNew($InvalidObjectException, "Deserialization via serialization delegate"_s);
}

void clinit$MinguoChronology($Class* class$) {
	$assignStatic(MinguoChronology::INSTANCE, $new(MinguoChronology));
}

MinguoChronology::MinguoChronology() {
}

$Class* MinguoChronology::load$($String* name, bool initialize) {
	$loadClass(MinguoChronology, name, initialize, &_MinguoChronology_ClassInfo_, clinit$MinguoChronology, allocate$MinguoChronology);
	return class$;
}

$Class* MinguoChronology::class$ = nullptr;

		} // chrono
	} // time
} // java