#include <java/time/format/Parsed.h>

#include <java/lang/Math.h>
#include <java/time/DateTimeException.h>
#include <java/time/Instant.h>
#include <java/time/LocalDate.h>
#include <java/time/LocalTime.h>
#include <java/time/Period.h>
#include <java/time/ZoneId.h>
#include <java/time/ZoneOffset.h>
#include <java/time/chrono/ChronoLocalDate.h>
#include <java/time/chrono/ChronoLocalDateTime.h>
#include <java/time/chrono/ChronoZonedDateTime.h>
#include <java/time/chrono/Chronology.h>
#include <java/time/format/DateTimeFormatterBuilder$DayPeriod.h>
#include <java/time/format/ResolverStyle.h>
#include <java/time/temporal/ChronoField.h>
#include <java/time/temporal/TemporalAccessor.h>
#include <java/time/temporal/TemporalAmount.h>
#include <java/time/temporal/TemporalField.h>
#include <java/time/temporal/TemporalQueries.h>
#include <java/time/temporal/TemporalQuery.h>
#include <java/time/temporal/UnsupportedTemporalTypeException.h>
#include <java/util/Collection.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Set.h>
#include <jcpp.h>

#undef AMPM_OF_DAY
#undef CLOCK_HOUR_OF_AMPM
#undef CLOCK_HOUR_OF_DAY
#undef HOUR_OF_AMPM
#undef HOUR_OF_DAY
#undef INSTANT_SECONDS
#undef LENIENT
#undef MICRO_OF_DAY
#undef MICRO_OF_SECOND
#undef MIDNIGHT
#undef MILLI_OF_DAY
#undef MILLI_OF_SECOND
#undef MINUTE_OF_DAY
#undef MINUTE_OF_HOUR
#undef NANO_OF_DAY
#undef NANO_OF_SECOND
#undef OFFSET_SECONDS
#undef SECOND_OF_DAY
#undef SECOND_OF_MINUTE
#undef SMART
#undef STRICT
#undef ZERO

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $DateTimeException = ::java::time::DateTimeException;
using $Instant = ::java::time::Instant;
using $LocalDate = ::java::time::LocalDate;
using $LocalTime = ::java::time::LocalTime;
using $Period = ::java::time::Period;
using $ZoneId = ::java::time::ZoneId;
using $ZoneOffset = ::java::time::ZoneOffset;
using $ChronoLocalDate = ::java::time::chrono::ChronoLocalDate;
using $ChronoLocalDateTime = ::java::time::chrono::ChronoLocalDateTime;
using $ChronoZonedDateTime = ::java::time::chrono::ChronoZonedDateTime;
using $Chronology = ::java::time::chrono::Chronology;
using $DateTimeFormatterBuilder$DayPeriod = ::java::time::format::DateTimeFormatterBuilder$DayPeriod;
using $ResolverStyle = ::java::time::format::ResolverStyle;
using $ChronoField = ::java::time::temporal::ChronoField;
using $TemporalAccessor = ::java::time::temporal::TemporalAccessor;
using $TemporalAmount = ::java::time::temporal::TemporalAmount;
using $TemporalField = ::java::time::temporal::TemporalField;
using $TemporalQueries = ::java::time::temporal::TemporalQueries;
using $TemporalQuery = ::java::time::temporal::TemporalQuery;
using $UnsupportedTemporalTypeException = ::java::time::temporal::UnsupportedTemporalTypeException;
using $Collection = ::java::util::Collection;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Objects = ::java::util::Objects;
using $Set = ::java::util::Set;

namespace java {
	namespace time {
		namespace format {

$FieldInfo _Parsed_FieldInfo_[] = {
	{"fieldValues", "Ljava/util/Map;", "Ljava/util/Map<Ljava/time/temporal/TemporalField;Ljava/lang/Long;>;", $FINAL, $field(Parsed, fieldValues)},
	{"zone", "Ljava/time/ZoneId;", nullptr, 0, $field(Parsed, zone)},
	{"chrono", "Ljava/time/chrono/Chronology;", nullptr, 0, $field(Parsed, chrono)},
	{"leapSecond", "Z", nullptr, 0, $field(Parsed, leapSecond)},
	{"resolverStyle", "Ljava/time/format/ResolverStyle;", nullptr, $PRIVATE, $field(Parsed, resolverStyle)},
	{"date", "Ljava/time/chrono/ChronoLocalDate;", nullptr, $PRIVATE, $field(Parsed, date)},
	{"time", "Ljava/time/LocalTime;", nullptr, $PRIVATE, $field(Parsed, time)},
	{"excessDays", "Ljava/time/Period;", nullptr, 0, $field(Parsed, excessDays)},
	{"dayPeriod", "Ljava/time/format/DateTimeFormatterBuilder$DayPeriod;", nullptr, 0, $field(Parsed, dayPeriod)},
	{}
};

$MethodInfo _Parsed_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(Parsed, init$, void)},
	{"copy", "()Ljava/time/format/Parsed;", nullptr, 0, $method(Parsed, copy, Parsed*)},
	{"crossCheck", "()V", nullptr, $PRIVATE, $method(Parsed, crossCheck, void)},
	{"crossCheck", "(Ljava/time/temporal/TemporalAccessor;)V", nullptr, $PRIVATE, $method(Parsed, crossCheck, void, $TemporalAccessor*)},
	{"getLong", "(Ljava/time/temporal/TemporalField;)J", nullptr, $PUBLIC, $virtualMethod(Parsed, getLong, int64_t, $TemporalField*)},
	{"isSupported", "(Ljava/time/temporal/TemporalField;)Z", nullptr, $PUBLIC, $virtualMethod(Parsed, isSupported, bool, $TemporalField*)},
	{"query", "(Ljava/time/temporal/TemporalQuery;)Ljava/lang/Object;", "<R:Ljava/lang/Object;>(Ljava/time/temporal/TemporalQuery<TR;>;)TR;", $PUBLIC, $virtualMethod(Parsed, query, $Object*, $TemporalQuery*)},
	{"resolve", "(Ljava/time/format/ResolverStyle;Ljava/util/Set;)Ljava/time/temporal/TemporalAccessor;", "(Ljava/time/format/ResolverStyle;Ljava/util/Set<Ljava/time/temporal/TemporalField;>;)Ljava/time/temporal/TemporalAccessor;", 0, $method(Parsed, resolve, $TemporalAccessor*, $ResolverStyle*, $Set*)},
	{"resolveDateFields", "()V", nullptr, $PRIVATE, $method(Parsed, resolveDateFields, void)},
	{"resolveFields", "()V", nullptr, $PRIVATE, $method(Parsed, resolveFields, void)},
	{"resolveFractional", "()V", nullptr, $PRIVATE, $method(Parsed, resolveFractional, void)},
	{"resolveInstant", "()V", nullptr, $PRIVATE, $method(Parsed, resolveInstant, void)},
	{"resolveInstantFields", "()V", nullptr, $PRIVATE, $method(Parsed, resolveInstantFields, void)},
	{"resolveInstantFields0", "(Ljava/time/ZoneId;)V", nullptr, $PRIVATE, $method(Parsed, resolveInstantFields0, void, $ZoneId*)},
	{"resolvePeriod", "()V", nullptr, $PRIVATE, $method(Parsed, resolvePeriod, void)},
	{"resolveTime", "(JJJJ)V", nullptr, $PRIVATE, $method(Parsed, resolveTime, void, int64_t, int64_t, int64_t, int64_t)},
	{"resolveTimeFields", "()V", nullptr, $PRIVATE, $method(Parsed, resolveTimeFields, void)},
	{"resolveTimeLenient", "()V", nullptr, $PRIVATE, $method(Parsed, resolveTimeLenient, void)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Parsed, toString, $String*)},
	{"updateCheckConflict", "(Ljava/time/temporal/TemporalField;Ljava/time/temporal/TemporalField;Ljava/lang/Long;)V", nullptr, $PRIVATE, $method(Parsed, updateCheckConflict, void, $TemporalField*, $TemporalField*, $Long*)},
	{"updateCheckConflict", "(Ljava/time/chrono/ChronoLocalDate;)V", nullptr, $PRIVATE, $method(Parsed, updateCheckConflict, void, $ChronoLocalDate*)},
	{"updateCheckConflict", "(Ljava/time/LocalTime;Ljava/time/Period;)V", nullptr, $PRIVATE, $method(Parsed, updateCheckConflict, void, $LocalTime*, $Period*)},
	{}
};

$ClassInfo _Parsed_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.time.format.Parsed",
	"java.lang.Object",
	"java.time.temporal.TemporalAccessor",
	_Parsed_FieldInfo_,
	_Parsed_MethodInfo_
};

$Object* allocate$Parsed($Class* clazz) {
	return $of($alloc(Parsed));
}

void Parsed::init$() {
	$set(this, fieldValues, $new($HashMap));
	$init($Period);
	$set(this, excessDays, $Period::ZERO);
}

Parsed* Parsed::copy() {
	$var(Parsed, cloned, $new(Parsed));
	$nc(cloned->fieldValues)->putAll(this->fieldValues);
	$set(cloned, zone, this->zone);
	$set(cloned, chrono, this->chrono);
	cloned->leapSecond = this->leapSecond;
	$set(cloned, dayPeriod, this->dayPeriod);
	return cloned;
}

bool Parsed::isSupported($TemporalField* field) {
	bool var$1 = $nc(this->fieldValues)->containsKey(field);
	bool var$0 = var$1 || (this->date != nullptr && $nc(this->date)->isSupported(field));
	if (var$0 || (this->time != nullptr && $nc(this->time)->isSupported(field))) {
		return true;
	}
	return field != nullptr && (!($instanceOf($ChronoField, field))) && field->isSupportedBy(this);
}

int64_t Parsed::getLong($TemporalField* field) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(field), "field"_s);
	$var($Long, value, $cast($Long, $nc(this->fieldValues)->get(field)));
	if (value != nullptr) {
		return value->longValue();
	}
	if (this->date != nullptr && $nc(this->date)->isSupported(field)) {
		return $nc(this->date)->getLong(field);
	}
	if (this->time != nullptr && $nc(this->time)->isSupported(field)) {
		return $nc(this->time)->getLong(field);
	}
	if ($instanceOf($ChronoField, field)) {
		$throwNew($UnsupportedTemporalTypeException, $$str({"Unsupported field: "_s, field}));
	}
	return $nc(field)->getFrom(this);
}

$Object* Parsed::query($TemporalQuery* query) {
	if (query == $TemporalQueries::zoneId()) {
		return $of($of(this->zone));
	} else if (query == $TemporalQueries::chronology()) {
		return $of($of(this->chrono));
	} else if (query == $TemporalQueries::localDate()) {
		return $of($of((this->date != nullptr ? $LocalDate::from(this->date) : ($LocalDate*)nullptr)));
	} else if (query == $TemporalQueries::localTime()) {
		return $of($of(this->time));
	} else if (query == $TemporalQueries::offset()) {
		$init($ChronoField);
		$var($Long, offsetSecs, $cast($Long, $nc(this->fieldValues)->get($ChronoField::OFFSET_SECONDS)));
		if (offsetSecs != nullptr) {
			return $of($of($ZoneOffset::ofTotalSeconds(offsetSecs->intValue())));
		}
		if ($instanceOf($ZoneOffset, this->zone)) {
			return $of($of(this->zone));
		}
		return $of($nc(query)->queryFrom(this));
	} else if (query == $TemporalQueries::zone()) {
		return $of($nc(query)->queryFrom(this));
	} else if (query == $TemporalQueries::precision()) {
		return $of(nullptr);
	}
	return $of($nc(query)->queryFrom(this));
}

$TemporalAccessor* Parsed::resolve($ResolverStyle* resolverStyle, $Set* resolverFields) {
	if (resolverFields != nullptr) {
		$nc($($nc(this->fieldValues)->keySet()))->retainAll(resolverFields);
	}
	$set(this, resolverStyle, resolverStyle);
	resolveFields();
	resolveTimeLenient();
	crossCheck();
	resolvePeriod();
	resolveFractional();
	resolveInstant();
	return this;
}

void Parsed::resolveFields() {
	$useLocalCurrentObjectStackCache();
	resolveInstantFields();
	resolveDateFields();
	resolveTimeFields();
	if ($nc(this->fieldValues)->size() > 0) {
		int32_t changedCount = 0;
		bool outer$continue = false;
		while (changedCount < 50) {
			{
				$var($Iterator, i$, $nc($($nc(this->fieldValues)->entrySet()))->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
					{
						$var($TemporalField, targetField, $cast($TemporalField, $nc(entry)->getKey()));
						$var($TemporalAccessor, resolvedObject, $nc(targetField)->resolve(this->fieldValues, this, this->resolverStyle));
						if (resolvedObject != nullptr) {
							{
								$var($ChronoZonedDateTime, czdt, nullptr);
								bool var$0 = $instanceOf($ChronoZonedDateTime, resolvedObject);
								if (var$0) {
									$assign(czdt, $cast($ChronoZonedDateTime, resolvedObject));
									var$0 = true;
								}
								if (var$0) {
									if (this->zone == nullptr) {
										$set(this, zone, $nc(czdt)->getZone());
									} else if ($nc(this->zone)->equals($($nc(czdt)->getZone())) == false) {
										$throwNew($DateTimeException, $$str({"ChronoZonedDateTime must use the effective parsed zone: "_s, this->zone}));
									}
									$assign(resolvedObject, $nc(czdt)->toLocalDateTime());
								}
							}
							{
								$var($ChronoLocalDateTime, cldt, nullptr);
								bool var$1 = $instanceOf($ChronoLocalDateTime, resolvedObject);
								if (var$1) {
									$assign(cldt, $cast($ChronoLocalDateTime, resolvedObject));
									var$1 = true;
								}
								if (var$1) {
									$init($Period);
									updateCheckConflict($($nc(cldt)->toLocalTime()), $Period::ZERO);
									updateCheckConflict($($nc(cldt)->toLocalDate()));
									++changedCount;
									outer$continue = true;
									break;
								}
							}
							if ($instanceOf($ChronoLocalDate, resolvedObject)) {
								updateCheckConflict($cast($ChronoLocalDate, resolvedObject));
								++changedCount;
								outer$continue = true;
								break;
							}
							if ($instanceOf($LocalTime, resolvedObject)) {
								$init($Period);
								updateCheckConflict($cast($LocalTime, resolvedObject), $Period::ZERO);
								++changedCount;
								outer$continue = true;
								break;
							}
							$throwNew($DateTimeException, "Method resolve() can only return ChronoZonedDateTime, ChronoLocalDateTime, ChronoLocalDate or LocalTime"_s);
						} else if ($nc(this->fieldValues)->containsKey(targetField) == false) {
							++changedCount;
							outer$continue = true;
							break;
						}
					}
				}
				if (outer$continue) {
					outer$continue = false;
					continue;
				}
			}
			break;
		}
		if (changedCount == 50) {
			$throwNew($DateTimeException, "One of the parsed fields has an incorrectly implemented resolve method"_s);
		}
		if (changedCount > 0) {
			resolveInstantFields();
			resolveDateFields();
			resolveTimeFields();
		}
	}
}

void Parsed::updateCheckConflict($TemporalField* targetField, $TemporalField* changeField, $Long* changeValue) {
	$useLocalCurrentObjectStackCache();
	$var($Long, old, $cast($Long, $nc(this->fieldValues)->put(changeField, changeValue)));
	bool var$0 = old != nullptr;
	if (var$0) {
		int64_t var$1 = old->longValue();
		var$0 = var$1 != $nc(changeValue)->longValue();
	}
	if (var$0) {
		$throwNew($DateTimeException, $$str({"Conflict found: "_s, changeField, " "_s, old, " differs from "_s, changeField, " "_s, changeValue, " while resolving  "_s, targetField}));
	}
}

void Parsed::resolveInstantFields() {
	$useLocalCurrentObjectStackCache();
	$init($ChronoField);
	if ($nc(this->fieldValues)->containsKey($ChronoField::INSTANT_SECONDS)) {
		if (this->zone != nullptr) {
			resolveInstantFields0(this->zone);
		} else {
			$var($Long, offsetSecs, $cast($Long, $nc(this->fieldValues)->get($ChronoField::OFFSET_SECONDS)));
			if (offsetSecs != nullptr) {
				$var($ZoneOffset, offset, $ZoneOffset::ofTotalSeconds(offsetSecs->intValue()));
				resolveInstantFields0(offset);
			}
		}
	}
}

void Parsed::resolveInstantFields0($ZoneId* selectedZone) {
	$useLocalCurrentObjectStackCache();
	$init($ChronoField);
	$var($Instant, instant, $Instant::ofEpochSecond($nc(($cast($Long, $($nc(this->fieldValues)->remove($ChronoField::INSTANT_SECONDS)))))->longValue()));
	$var($ChronoZonedDateTime, zdt, $nc(this->chrono)->zonedDateTime(instant, selectedZone));
	updateCheckConflict($($nc(zdt)->toLocalDate()));
	updateCheckConflict($ChronoField::INSTANT_SECONDS, $ChronoField::SECOND_OF_DAY, $($Long::valueOf((int64_t)$nc($($nc(zdt)->toLocalTime()))->toSecondOfDay())));
}

void Parsed::resolveDateFields() {
	updateCheckConflict($($nc(this->chrono)->resolveDate(this->fieldValues, this->resolverStyle)));
}

void Parsed::updateCheckConflict($ChronoLocalDate* cld) {
	$useLocalCurrentObjectStackCache();
	if (this->date != nullptr) {
		if (cld != nullptr && $nc(this->date)->equals(cld) == false) {
			$throwNew($DateTimeException, $$str({"Conflict found: Fields resolved to two different dates: "_s, this->date, " "_s, cld}));
		}
	} else if (cld != nullptr) {
		if ($nc(this->chrono)->equals($(cld->getChronology())) == false) {
			$throwNew($DateTimeException, $$str({"ChronoLocalDate must use the effective parsed chronology: "_s, this->chrono}));
		}
		$set(this, date, cld);
	}
}

void Parsed::resolveTimeFields() {
	$useLocalCurrentObjectStackCache();
	$init($ChronoField);
	if ($nc(this->fieldValues)->containsKey($ChronoField::CLOCK_HOUR_OF_DAY)) {
		int64_t ch = $nc(($cast($Long, $($nc(this->fieldValues)->remove($ChronoField::CLOCK_HOUR_OF_DAY)))))->longValue();
		$init($ResolverStyle);
		if (this->resolverStyle == $ResolverStyle::STRICT || (this->resolverStyle == $ResolverStyle::SMART && ch != 0)) {
			$ChronoField::CLOCK_HOUR_OF_DAY->checkValidValue(ch);
		}
		updateCheckConflict($ChronoField::CLOCK_HOUR_OF_DAY, $ChronoField::HOUR_OF_DAY, $($Long::valueOf(ch == 24 ? (int64_t)0 : ch)));
	}
	if ($nc(this->fieldValues)->containsKey($ChronoField::CLOCK_HOUR_OF_AMPM)) {
		int64_t ch = $nc(($cast($Long, $($nc(this->fieldValues)->remove($ChronoField::CLOCK_HOUR_OF_AMPM)))))->longValue();
		$init($ResolverStyle);
		if (this->resolverStyle == $ResolverStyle::STRICT || (this->resolverStyle == $ResolverStyle::SMART && ch != 0)) {
			$ChronoField::CLOCK_HOUR_OF_AMPM->checkValidValue(ch);
		}
		updateCheckConflict($ChronoField::CLOCK_HOUR_OF_AMPM, $ChronoField::HOUR_OF_AMPM, $($Long::valueOf(ch == 12 ? (int64_t)0 : ch)));
	}
	bool var$0 = $nc(this->fieldValues)->containsKey($ChronoField::AMPM_OF_DAY);
	if (var$0 && $nc(this->fieldValues)->containsKey($ChronoField::HOUR_OF_AMPM)) {
		int64_t ap = $nc(($cast($Long, $($nc(this->fieldValues)->remove($ChronoField::AMPM_OF_DAY)))))->longValue();
		int64_t hap = $nc(($cast($Long, $($nc(this->fieldValues)->remove($ChronoField::HOUR_OF_AMPM)))))->longValue();
		$init($ResolverStyle);
		if (this->resolverStyle == $ResolverStyle::LENIENT) {
			updateCheckConflict($ChronoField::AMPM_OF_DAY, $ChronoField::HOUR_OF_DAY, $($Long::valueOf($Math::addExact($Math::multiplyExact(ap, 12), hap))));
		} else {
			$ChronoField::AMPM_OF_DAY->checkValidValue(ap);
			$ChronoField::HOUR_OF_AMPM->checkValidValue(hap);
			updateCheckConflict($ChronoField::AMPM_OF_DAY, $ChronoField::HOUR_OF_DAY, $($Long::valueOf(ap * 12 + hap)));
		}
	}
	if ($nc(this->fieldValues)->containsKey($ChronoField::NANO_OF_DAY)) {
		int64_t nod = $nc(($cast($Long, $($nc(this->fieldValues)->remove($ChronoField::NANO_OF_DAY)))))->longValue();
		$init($ResolverStyle);
		if (this->resolverStyle != $ResolverStyle::LENIENT) {
			$ChronoField::NANO_OF_DAY->checkValidValue(nod);
		}
		updateCheckConflict($ChronoField::NANO_OF_DAY, $ChronoField::HOUR_OF_DAY, $($Long::valueOf($div(nod, (int64_t)0x0000034630B8A000))));
		updateCheckConflict($ChronoField::NANO_OF_DAY, $ChronoField::MINUTE_OF_HOUR, $($Long::valueOf(($div(nod, (int64_t)0x0000000DF8475800)) % 60)));
		updateCheckConflict($ChronoField::NANO_OF_DAY, $ChronoField::SECOND_OF_MINUTE, $($Long::valueOf(($div(nod, (int64_t)1000000000)) % 60)));
		updateCheckConflict($ChronoField::NANO_OF_DAY, $ChronoField::NANO_OF_SECOND, $($Long::valueOf($mod(nod, (int64_t)1000000000))));
	}
	if ($nc(this->fieldValues)->containsKey($ChronoField::MICRO_OF_DAY)) {
		int64_t cod = $nc(($cast($Long, $($nc(this->fieldValues)->remove($ChronoField::MICRO_OF_DAY)))))->longValue();
		$init($ResolverStyle);
		if (this->resolverStyle != $ResolverStyle::LENIENT) {
			$ChronoField::MICRO_OF_DAY->checkValidValue(cod);
		}
		updateCheckConflict($ChronoField::MICRO_OF_DAY, $ChronoField::SECOND_OF_DAY, $($Long::valueOf($div(cod, (int64_t)1000000))));
		updateCheckConflict($ChronoField::MICRO_OF_DAY, $ChronoField::MICRO_OF_SECOND, $($Long::valueOf($mod(cod, (int64_t)1000000))));
	}
	if ($nc(this->fieldValues)->containsKey($ChronoField::MILLI_OF_DAY)) {
		int64_t lod = $nc(($cast($Long, $($nc(this->fieldValues)->remove($ChronoField::MILLI_OF_DAY)))))->longValue();
		$init($ResolverStyle);
		if (this->resolverStyle != $ResolverStyle::LENIENT) {
			$ChronoField::MILLI_OF_DAY->checkValidValue(lod);
		}
		updateCheckConflict($ChronoField::MILLI_OF_DAY, $ChronoField::SECOND_OF_DAY, $($Long::valueOf(lod / 1000)));
		updateCheckConflict($ChronoField::MILLI_OF_DAY, $ChronoField::MILLI_OF_SECOND, $($Long::valueOf(lod % 1000)));
	}
	if ($nc(this->fieldValues)->containsKey($ChronoField::SECOND_OF_DAY)) {
		int64_t sod = $nc(($cast($Long, $($nc(this->fieldValues)->remove($ChronoField::SECOND_OF_DAY)))))->longValue();
		$init($ResolverStyle);
		if (this->resolverStyle != $ResolverStyle::LENIENT) {
			$ChronoField::SECOND_OF_DAY->checkValidValue(sod);
		}
		updateCheckConflict($ChronoField::SECOND_OF_DAY, $ChronoField::HOUR_OF_DAY, $($Long::valueOf(sod / 3600)));
		updateCheckConflict($ChronoField::SECOND_OF_DAY, $ChronoField::MINUTE_OF_HOUR, $($Long::valueOf((sod / 60) % 60)));
		updateCheckConflict($ChronoField::SECOND_OF_DAY, $ChronoField::SECOND_OF_MINUTE, $($Long::valueOf(sod % 60)));
	}
	if ($nc(this->fieldValues)->containsKey($ChronoField::MINUTE_OF_DAY)) {
		int64_t mod = $nc(($cast($Long, $($nc(this->fieldValues)->remove($ChronoField::MINUTE_OF_DAY)))))->longValue();
		$init($ResolverStyle);
		if (this->resolverStyle != $ResolverStyle::LENIENT) {
			$ChronoField::MINUTE_OF_DAY->checkValidValue(mod);
		}
		updateCheckConflict($ChronoField::MINUTE_OF_DAY, $ChronoField::HOUR_OF_DAY, $($Long::valueOf(mod / 60)));
		updateCheckConflict($ChronoField::MINUTE_OF_DAY, $ChronoField::MINUTE_OF_HOUR, $($Long::valueOf(mod % 60)));
	}
	if ($nc(this->fieldValues)->containsKey($ChronoField::NANO_OF_SECOND)) {
		int64_t nos = $nc(($cast($Long, $($nc(this->fieldValues)->get($ChronoField::NANO_OF_SECOND)))))->longValue();
		$init($ResolverStyle);
		if (this->resolverStyle != $ResolverStyle::LENIENT) {
			$ChronoField::NANO_OF_SECOND->checkValidValue(nos);
		}
		if ($nc(this->fieldValues)->containsKey($ChronoField::MICRO_OF_SECOND)) {
			int64_t cos = $nc(($cast($Long, $($nc(this->fieldValues)->remove($ChronoField::MICRO_OF_SECOND)))))->longValue();
			if (this->resolverStyle != $ResolverStyle::LENIENT) {
				$ChronoField::MICRO_OF_SECOND->checkValidValue(cos);
			}
			nos = cos * 1000 + (nos % 1000);
			updateCheckConflict($ChronoField::MICRO_OF_SECOND, $ChronoField::NANO_OF_SECOND, $($Long::valueOf(nos)));
		}
		if ($nc(this->fieldValues)->containsKey($ChronoField::MILLI_OF_SECOND)) {
			int64_t los = $nc(($cast($Long, $($nc(this->fieldValues)->remove($ChronoField::MILLI_OF_SECOND)))))->longValue();
			if (this->resolverStyle != $ResolverStyle::LENIENT) {
				$ChronoField::MILLI_OF_SECOND->checkValidValue(los);
			}
			updateCheckConflict($ChronoField::MILLI_OF_SECOND, $ChronoField::NANO_OF_SECOND, $($Long::valueOf(los * (int64_t)1000000 + ($mod(nos, (int64_t)1000000)))));
		}
	}
	if (this->dayPeriod != nullptr && $nc(this->fieldValues)->containsKey($ChronoField::HOUR_OF_AMPM)) {
		int64_t hoap = $nc(($cast($Long, $($nc(this->fieldValues)->remove($ChronoField::HOUR_OF_AMPM)))))->longValue();
		$init($ResolverStyle);
		if (this->resolverStyle != $ResolverStyle::LENIENT) {
			$ChronoField::HOUR_OF_AMPM->checkValidValue(hoap);
		}
		$var($Long, mohObj, $cast($Long, $nc(this->fieldValues)->get($ChronoField::MINUTE_OF_HOUR)));
		int64_t moh = mohObj != nullptr ? $Math::floorMod($nc(mohObj)->longValue(), 60) : 0;
		int64_t excessHours = $nc(this->dayPeriod)->includes(($Math::floorMod(hoap, 12) + 12) * 60 + moh) ? 12 : 0;
		int64_t hod = $Math::addExact(hoap, excessHours);
		updateCheckConflict($ChronoField::HOUR_OF_AMPM, $ChronoField::HOUR_OF_DAY, $($Long::valueOf(hod)));
		$set(this, dayPeriod, nullptr);
	}
	bool var$3 = $nc(this->fieldValues)->containsKey($ChronoField::HOUR_OF_DAY);
	bool var$2 = var$3 && $nc(this->fieldValues)->containsKey($ChronoField::MINUTE_OF_HOUR);
	bool var$1 = var$2 && $nc(this->fieldValues)->containsKey($ChronoField::SECOND_OF_MINUTE);
	if (var$1 && $nc(this->fieldValues)->containsKey($ChronoField::NANO_OF_SECOND)) {
		int64_t hod = $nc(($cast($Long, $($nc(this->fieldValues)->remove($ChronoField::HOUR_OF_DAY)))))->longValue();
		int64_t moh = $nc(($cast($Long, $($nc(this->fieldValues)->remove($ChronoField::MINUTE_OF_HOUR)))))->longValue();
		int64_t som = $nc(($cast($Long, $($nc(this->fieldValues)->remove($ChronoField::SECOND_OF_MINUTE)))))->longValue();
		int64_t nos = $nc(($cast($Long, $($nc(this->fieldValues)->remove($ChronoField::NANO_OF_SECOND)))))->longValue();
		resolveTime(hod, moh, som, nos);
	}
}

void Parsed::resolveTimeLenient() {
	$useLocalCurrentObjectStackCache();
	if (this->time == nullptr) {
		$init($ChronoField);
		if ($nc(this->fieldValues)->containsKey($ChronoField::MILLI_OF_SECOND)) {
			int64_t los = $nc(($cast($Long, $($nc(this->fieldValues)->remove($ChronoField::MILLI_OF_SECOND)))))->longValue();
			if ($nc(this->fieldValues)->containsKey($ChronoField::MICRO_OF_SECOND)) {
				int64_t cos = los * 1000 + ($nc(($cast($Long, $($nc(this->fieldValues)->get($ChronoField::MICRO_OF_SECOND)))))->longValue() % 1000);
				updateCheckConflict($ChronoField::MILLI_OF_SECOND, $ChronoField::MICRO_OF_SECOND, $($Long::valueOf(cos)));
				$nc(this->fieldValues)->remove($ChronoField::MICRO_OF_SECOND);
				$nc(this->fieldValues)->put($ChronoField::NANO_OF_SECOND, $($Long::valueOf(cos * (int64_t)1000)));
			} else {
				$nc(this->fieldValues)->put($ChronoField::NANO_OF_SECOND, $($Long::valueOf(los * (int64_t)1000000)));
			}
		} else {
			if ($nc(this->fieldValues)->containsKey($ChronoField::MICRO_OF_SECOND)) {
				int64_t cos = $nc(($cast($Long, $($nc(this->fieldValues)->remove($ChronoField::MICRO_OF_SECOND)))))->longValue();
				$nc(this->fieldValues)->put($ChronoField::NANO_OF_SECOND, $($Long::valueOf(cos * (int64_t)1000)));
			}
		}
		bool var$2 = !$nc(this->fieldValues)->containsKey($ChronoField::HOUR_OF_DAY);
		bool var$1 = var$2 && !$nc(this->fieldValues)->containsKey($ChronoField::MINUTE_OF_HOUR);
		bool var$0 = var$1 && !$nc(this->fieldValues)->containsKey($ChronoField::SECOND_OF_MINUTE);
		$init($ResolverStyle);
		if (var$0 && !$nc(this->fieldValues)->containsKey($ChronoField::NANO_OF_SECOND) && this->resolverStyle != $ResolverStyle::STRICT) {
			if (this->dayPeriod != nullptr) {
				int64_t midpoint = $nc(this->dayPeriod)->mid();
				resolveTime(midpoint / 60, midpoint % 60, 0, 0);
				$set(this, dayPeriod, nullptr);
			} else {
				if ($nc(this->fieldValues)->containsKey($ChronoField::AMPM_OF_DAY)) {
					int64_t ap = $nc(($cast($Long, $($nc(this->fieldValues)->remove($ChronoField::AMPM_OF_DAY)))))->longValue();
					if (this->resolverStyle == $ResolverStyle::LENIENT) {
						resolveTime($Math::addExact($Math::multiplyExact(ap, 12), (int64_t)6), 0, 0, 0);
					} else {
						$ChronoField::AMPM_OF_DAY->checkValidValue(ap);
						resolveTime(ap * 12 + 6, 0, 0, 0);
					}
				}
			}
		}
		$var($Long, hod, $cast($Long, $nc(this->fieldValues)->get($ChronoField::HOUR_OF_DAY)));
		if (hod != nullptr) {
			$var($Long, moh, $cast($Long, $nc(this->fieldValues)->get($ChronoField::MINUTE_OF_HOUR)));
			$var($Long, som, $cast($Long, $nc(this->fieldValues)->get($ChronoField::SECOND_OF_MINUTE)));
			$var($Long, nos, $cast($Long, $nc(this->fieldValues)->get($ChronoField::NANO_OF_SECOND)));
			if ((moh == nullptr && (som != nullptr || nos != nullptr)) || (moh != nullptr && som == nullptr && nos != nullptr)) {
				return;
			}
			int64_t mohVal = (moh != nullptr ? $nc(moh)->longValue() : (int64_t)0);
			int64_t somVal = (som != nullptr ? $nc(som)->longValue() : (int64_t)0);
			int64_t nosVal = (nos != nullptr ? $nc(nos)->longValue() : (int64_t)0);
			if (this->dayPeriod != nullptr && this->resolverStyle != $ResolverStyle::LENIENT) {
				if (!$nc(this->dayPeriod)->includes(hod->longValue() * 60 + mohVal)) {
					$throwNew($DateTimeException, $$str({$("Conflict found: Resolved time %02d:%02d"_s->formatted($$new($ObjectArray, {
						$of(hod),
						$($of($Long::valueOf(mohVal)))
					}))), " conflicts with "_s, this->dayPeriod}));
				}
			}
			resolveTime(hod->longValue(), mohVal, somVal, nosVal);
			$nc(this->fieldValues)->remove($ChronoField::HOUR_OF_DAY);
			$nc(this->fieldValues)->remove($ChronoField::MINUTE_OF_HOUR);
			$nc(this->fieldValues)->remove($ChronoField::SECOND_OF_MINUTE);
			$nc(this->fieldValues)->remove($ChronoField::NANO_OF_SECOND);
		}
	}
	$init($ResolverStyle);
	if (this->resolverStyle != $ResolverStyle::LENIENT && $nc(this->fieldValues)->size() > 0) {
		{
			$var($Iterator, i$, $nc($($nc(this->fieldValues)->entrySet()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
				{
					$var($TemporalField, field, $cast($TemporalField, $nc(entry)->getKey()));
					if ($instanceOf($ChronoField, field) && $nc(field)->isTimeBased()) {
						$nc(($cast($ChronoField, field)))->checkValidValue($nc(($cast($Long, $(entry->getValue()))))->longValue());
					}
				}
			}
		}
	}
}

void Parsed::resolveTime(int64_t hod, int64_t moh, int64_t som, int64_t nos) {
	$useLocalCurrentObjectStackCache();
	$init($ResolverStyle);
	if (this->resolverStyle == $ResolverStyle::LENIENT) {
		int64_t totalNanos = $Math::multiplyExact(hod, (int64_t)0x0000034630B8A000);
		totalNanos = $Math::addExact(totalNanos, $Math::multiplyExact(moh, (int64_t)0x0000000DF8475800));
		totalNanos = $Math::addExact(totalNanos, $Math::multiplyExact(som, (int64_t)1000000000));
		totalNanos = $Math::addExact(totalNanos, nos);
		int32_t excessDays = (int32_t)$Math::floorDiv(totalNanos, (int64_t)0x00004E94914F0000);
		int64_t nod = $Math::floorMod(totalNanos, (int64_t)0x00004E94914F0000);
		$var($LocalTime, var$0, $LocalTime::ofNanoOfDay(nod));
		updateCheckConflict(var$0, $($Period::ofDays(excessDays)));
	} else {
		$init($ChronoField);
		int32_t mohVal = $ChronoField::MINUTE_OF_HOUR->checkValidIntValue(moh);
		int32_t nosVal = $ChronoField::NANO_OF_SECOND->checkValidIntValue(nos);
		if (this->resolverStyle == $ResolverStyle::SMART && hod == 24 && mohVal == 0 && som == 0 && nosVal == 0) {
			$init($LocalTime);
			updateCheckConflict($LocalTime::MIDNIGHT, $($Period::ofDays(1)));
		} else {
			int32_t hodVal = $ChronoField::HOUR_OF_DAY->checkValidIntValue(hod);
			int32_t somVal = $ChronoField::SECOND_OF_MINUTE->checkValidIntValue(som);
			$init($Period);
			updateCheckConflict($($LocalTime::of(hodVal, mohVal, somVal, nosVal)), $Period::ZERO);
		}
	}
}

void Parsed::resolvePeriod() {
	if (this->date != nullptr && this->time != nullptr && $nc(this->excessDays)->isZero() == false) {
		$set(this, date, $nc(this->date)->plus(this->excessDays));
		$init($Period);
		$set(this, excessDays, $Period::ZERO);
	}
}

void Parsed::resolveFractional() {
	$useLocalCurrentObjectStackCache();
	bool var$0 = this->time == nullptr;
	if (var$0) {
		$init($ChronoField);
		bool var$2 = $nc(this->fieldValues)->containsKey($ChronoField::INSTANT_SECONDS);
		bool var$1 = var$2 || $nc(this->fieldValues)->containsKey($ChronoField::SECOND_OF_DAY);
		var$0 = (var$1 || $nc(this->fieldValues)->containsKey($ChronoField::SECOND_OF_MINUTE));
	}
	if (var$0) {
		$init($ChronoField);
		if ($nc(this->fieldValues)->containsKey($ChronoField::NANO_OF_SECOND)) {
			int64_t nos = $nc(($cast($Long, $($nc(this->fieldValues)->get($ChronoField::NANO_OF_SECOND)))))->longValue();
			$nc(this->fieldValues)->put($ChronoField::MICRO_OF_SECOND, $($Long::valueOf(nos / 1000)));
			$nc(this->fieldValues)->put($ChronoField::MILLI_OF_SECOND, $($Long::valueOf(nos / 0x000F4240)));
		} else {
			$nc(this->fieldValues)->put($ChronoField::NANO_OF_SECOND, $($Long::valueOf((int64_t)0)));
			$nc(this->fieldValues)->put($ChronoField::MICRO_OF_SECOND, $($Long::valueOf((int64_t)0)));
			$nc(this->fieldValues)->put($ChronoField::MILLI_OF_SECOND, $($Long::valueOf((int64_t)0)));
		}
	}
}

void Parsed::resolveInstant() {
	$useLocalCurrentObjectStackCache();
	if (this->date != nullptr && this->time != nullptr) {
		$init($ChronoField);
		$var($Long, offsetSecs, $cast($Long, $nc(this->fieldValues)->get($ChronoField::OFFSET_SECONDS)));
		if (offsetSecs != nullptr) {
			$var($ZoneOffset, offset, $ZoneOffset::ofTotalSeconds(offsetSecs->intValue()));
			int64_t instant = $nc($($nc($($nc(this->date)->atTime(this->time)))->atZone(offset)))->toEpochSecond();
			$nc(this->fieldValues)->put($ChronoField::INSTANT_SECONDS, $($Long::valueOf(instant)));
		} else if (this->zone != nullptr) {
			int64_t instant = $nc($($nc($($nc(this->date)->atTime(this->time)))->atZone(this->zone)))->toEpochSecond();
			$nc(this->fieldValues)->put($ChronoField::INSTANT_SECONDS, $($Long::valueOf(instant)));
		}
	}
}

void Parsed::updateCheckConflict($LocalTime* timeToSet, $Period* periodToSet) {
	$useLocalCurrentObjectStackCache();
	if (this->time != nullptr) {
		if ($nc(this->time)->equals(timeToSet) == false) {
			$throwNew($DateTimeException, $$str({"Conflict found: Fields resolved to different times: "_s, this->time, " "_s, timeToSet}));
		}
		bool var$1 = $nc(this->excessDays)->isZero() == false;
		bool var$0 = var$1 && $nc(periodToSet)->isZero() == false;
		if (var$0 && $nc(this->excessDays)->equals(periodToSet) == false) {
			$throwNew($DateTimeException, $$str({"Conflict found: Fields resolved to different excess periods: "_s, this->excessDays, " "_s, periodToSet}));
		} else {
			$set(this, excessDays, periodToSet);
		}
	} else {
		$set(this, time, timeToSet);
		$set(this, excessDays, periodToSet);
	}
}

void Parsed::crossCheck() {
	if (this->date != nullptr) {
		crossCheck(this->date);
	}
	if (this->time != nullptr) {
		crossCheck(this->time);
		if (this->date != nullptr && $nc(this->fieldValues)->size() > 0) {
			crossCheck($($nc(this->date)->atTime(this->time)));
		}
	}
}

void Parsed::crossCheck($TemporalAccessor* target) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, it, $nc($($nc(this->fieldValues)->entrySet()))->iterator());
		for (; $nc(it)->hasNext();) {
			$var($Map$Entry, entry, $cast($Map$Entry, it->next()));
			$var($TemporalField, field, $cast($TemporalField, $nc(entry)->getKey()));
			if ($nc(target)->isSupported(field)) {
				int64_t val1 = 0;
				try {
					val1 = target->getLong(field);
				} catch ($RuntimeException& ex) {
					continue;
				}
				int64_t val2 = $nc(($cast($Long, $(entry->getValue()))))->longValue();
				if (val1 != val2) {
					$throwNew($DateTimeException, $$str({"Conflict found: Field "_s, field, " "_s, $$str(val1), " differs from "_s, field, " "_s, $$str(val2), " derived from "_s, target}));
				}
				it->remove();
			}
		}
	}
}

$String* Parsed::toString() {
	$var($StringBuilder, buf, $new($StringBuilder, 64));
	buf->append($of(this->fieldValues))->append(u',')->append($of(this->chrono));
	if (this->zone != nullptr) {
		buf->append(u',')->append($of(this->zone));
	}
	if (this->date != nullptr || this->time != nullptr) {
		buf->append(" resolved to "_s);
		if (this->date != nullptr) {
			buf->append($of(this->date));
			if (this->time != nullptr) {
				buf->append(u'T')->append($of(this->time));
			}
		} else {
			buf->append($of(this->time));
		}
	}
	return buf->toString();
}

Parsed::Parsed() {
}

$Class* Parsed::load$($String* name, bool initialize) {
	$loadClass(Parsed, name, initialize, &_Parsed_ClassInfo_, allocate$Parsed);
	return class$;
}

$Class* Parsed::class$ = nullptr;

		} // format
	} // time
} // java