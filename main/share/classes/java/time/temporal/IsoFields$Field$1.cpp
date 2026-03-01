#include <java/time/temporal/IsoFields$Field$1.h>

#include <java/lang/Math.h>
#include <java/time/LocalDate.h>
#include <java/time/chrono/IsoChronology.h>
#include <java/time/format/ResolverStyle.h>
#include <java/time/temporal/ChronoField.h>
#include <java/time/temporal/ChronoUnit.h>
#include <java/time/temporal/IsoFields$Field.h>
#include <java/time/temporal/IsoFields.h>
#include <java/time/temporal/Temporal.h>
#include <java/time/temporal/TemporalAccessor.h>
#include <java/time/temporal/TemporalField.h>
#include <java/time/temporal/TemporalUnit.h>
#include <java/time/temporal/UnsupportedTemporalTypeException.h>
#include <java/time/temporal/ValueRange.h>
#include <java/util/Map.h>
#include <jcpp.h>

#undef DAYS
#undef DAY_OF_QUARTER
#undef DAY_OF_YEAR
#undef INSTANCE
#undef LENIENT
#undef MONTH_OF_YEAR
#undef QUARTER_DAYS
#undef QUARTER_OF_YEAR
#undef QUARTER_YEARS
#undef STRICT
#undef YEAR

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $LocalDate = ::java::time::LocalDate;
using $IsoChronology = ::java::time::chrono::IsoChronology;
using $ResolverStyle = ::java::time::format::ResolverStyle;
using $ChronoField = ::java::time::temporal::ChronoField;
using $ChronoUnit = ::java::time::temporal::ChronoUnit;
using $IsoFields = ::java::time::temporal::IsoFields;
using $IsoFields$Field = ::java::time::temporal::IsoFields$Field;
using $Temporal = ::java::time::temporal::Temporal;
using $TemporalAccessor = ::java::time::temporal::TemporalAccessor;
using $TemporalField = ::java::time::temporal::TemporalField;
using $TemporalUnit = ::java::time::temporal::TemporalUnit;
using $UnsupportedTemporalTypeException = ::java::time::temporal::UnsupportedTemporalTypeException;
using $ValueRange = ::java::time::temporal::ValueRange;
using $Map = ::java::util::Map;

namespace java {
	namespace time {
		namespace temporal {

$MethodInfo _IsoFields$Field$1_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;I)V", nullptr, $PRIVATE, $method(IsoFields$Field$1, init$, void, $String*, int32_t)},
	{"adjustInto", "(Ljava/time/temporal/Temporal;J)Ljava/time/temporal/Temporal;", "<R::Ljava/time/temporal/Temporal;>(TR;J)TR;", $PUBLIC, $virtualMethod(IsoFields$Field$1, adjustInto, $Temporal*, $Temporal*, int64_t)},
	{"getBaseUnit", "()Ljava/time/temporal/TemporalUnit;", nullptr, $PUBLIC, $virtualMethod(IsoFields$Field$1, getBaseUnit, $TemporalUnit*)},
	{"getFrom", "(Ljava/time/temporal/TemporalAccessor;)J", nullptr, $PUBLIC, $virtualMethod(IsoFields$Field$1, getFrom, int64_t, $TemporalAccessor*)},
	{"getRangeUnit", "()Ljava/time/temporal/TemporalUnit;", nullptr, $PUBLIC, $virtualMethod(IsoFields$Field$1, getRangeUnit, $TemporalUnit*)},
	{"isSupportedBy", "(Ljava/time/temporal/TemporalAccessor;)Z", nullptr, $PUBLIC, $virtualMethod(IsoFields$Field$1, isSupportedBy, bool, $TemporalAccessor*)},
	{"range", "()Ljava/time/temporal/ValueRange;", nullptr, $PUBLIC, $virtualMethod(IsoFields$Field$1, range, $ValueRange*)},
	{"rangeRefinedBy", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/temporal/ValueRange;", nullptr, $PUBLIC, $virtualMethod(IsoFields$Field$1, rangeRefinedBy, $ValueRange*, $TemporalAccessor*)},
	{"resolve", "(Ljava/util/Map;Ljava/time/temporal/TemporalAccessor;Ljava/time/format/ResolverStyle;)Ljava/time/chrono/ChronoLocalDate;", "(Ljava/util/Map<Ljava/time/temporal/TemporalField;Ljava/lang/Long;>;Ljava/time/temporal/TemporalAccessor;Ljava/time/format/ResolverStyle;)Ljava/time/chrono/ChronoLocalDate;", $PUBLIC, $virtualMethod(IsoFields$Field$1, resolve, $TemporalAccessor*, $Map*, $TemporalAccessor*, $ResolverStyle*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(IsoFields$Field$1, toString, $String*)},
	{}
};

$EnclosingMethodInfo _IsoFields$Field$1_EnclosingMethodInfo_ = {
	"java.time.temporal.IsoFields$Field",
	nullptr,
	nullptr
};

$InnerClassInfo _IsoFields$Field$1_InnerClassesInfo_[] = {
	{"java.time.temporal.IsoFields$Field", "java.time.temporal.IsoFields", "Field", $PRIVATE | $STATIC | $ABSTRACT | $ENUM},
	{"java.time.temporal.IsoFields$Field$1", nullptr, nullptr, $FINAL | $ENUM},
	{}
};

$ClassInfo _IsoFields$Field$1_ClassInfo_ = {
	$FINAL | $ACC_SUPER | $ENUM,
	"java.time.temporal.IsoFields$Field$1",
	"java.time.temporal.IsoFields$Field",
	nullptr,
	nullptr,
	_IsoFields$Field$1_MethodInfo_,
	nullptr,
	&_IsoFields$Field$1_EnclosingMethodInfo_,
	_IsoFields$Field$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.time.temporal.IsoFields"
};

$Object* allocate$IsoFields$Field$1($Class* clazz) {
	return $of($alloc(IsoFields$Field$1));
}

void IsoFields$Field$1::init$($String* $enum$name, int32_t $enum$ordinal) {
	$IsoFields$Field::init$($enum$name, $enum$ordinal);
}

$TemporalUnit* IsoFields$Field$1::getBaseUnit() {
	$init($ChronoUnit);
	return $ChronoUnit::DAYS;
}

$TemporalUnit* IsoFields$Field$1::getRangeUnit() {
	$init($IsoFields);
	return $IsoFields::QUARTER_YEARS;
}

$ValueRange* IsoFields$Field$1::range() {
	return $ValueRange::of(1, 90, 92);
}

bool IsoFields$Field$1::isSupportedBy($TemporalAccessor* temporal) {
	$init($ChronoField);
	bool var$2 = $nc(temporal)->isSupported($ChronoField::DAY_OF_YEAR);
	bool var$1 = var$2 && temporal->isSupported($ChronoField::MONTH_OF_YEAR);
	bool var$0 = var$1 && temporal->isSupported($ChronoField::YEAR);
	return var$0 && $IsoFields::isIso(temporal);
}

$ValueRange* IsoFields$Field$1::rangeRefinedBy($TemporalAccessor* temporal) {
	if (isSupportedBy(temporal) == false) {
		$throwNew($UnsupportedTemporalTypeException, "Unsupported field: DayOfQuarter"_s);
	}
	$init($IsoFields$Field);
	int64_t qoy = $nc(temporal)->getLong($IsoFields$Field::QUARTER_OF_YEAR);
	if (qoy == 1) {
		$init($ChronoField);
		int64_t year = temporal->getLong($ChronoField::YEAR);
		$init($IsoChronology);
		return ($nc($IsoChronology::INSTANCE)->isLeapYear(year) ? $ValueRange::of(1, 91) : $ValueRange::of(1, 90));
	} else if (qoy == 2) {
		return $ValueRange::of(1, 91);
	} else if (qoy == 3 || qoy == 4) {
		return $ValueRange::of(1, 92);
	}
	return range();
}

int64_t IsoFields$Field$1::getFrom($TemporalAccessor* temporal) {
	if (isSupportedBy(temporal) == false) {
		$throwNew($UnsupportedTemporalTypeException, "Unsupported field: DayOfQuarter"_s);
	}
	$init($ChronoField);
	int32_t doy = $nc(temporal)->get($ChronoField::DAY_OF_YEAR);
	int32_t moy = temporal->get($ChronoField::MONTH_OF_YEAR);
	int64_t year = temporal->getLong($ChronoField::YEAR);
	$init($IsoFields$Field);
	$init($IsoChronology);
	return doy - $nc($IsoFields$Field::QUARTER_DAYS)->get(((moy - 1) / 3) + ($nc($IsoChronology::INSTANCE)->isLeapYear(year) ? 4 : 0));
}

$Temporal* IsoFields$Field$1::adjustInto($Temporal* temporal, int64_t newValue) {
	int64_t curValue = getFrom(temporal);
	$nc($(range()))->checkValidValue(newValue, this);
	$init($ChronoField);
	return $nc(temporal)->with($ChronoField::DAY_OF_YEAR, temporal->getLong($ChronoField::DAY_OF_YEAR) + (newValue - curValue));
}

$TemporalAccessor* IsoFields$Field$1::resolve($Map* fieldValues, $TemporalAccessor* partialTemporal, $ResolverStyle* resolverStyle) {
	$useLocalCurrentObjectStackCache();
	$init($ChronoField);
	$var($Long, yearLong, $cast($Long, $nc(fieldValues)->get($ChronoField::YEAR)));
	$init($IsoFields$Field);
	$var($Long, qoyLong, $cast($Long, fieldValues->get($IsoFields$Field::QUARTER_OF_YEAR)));
	if (yearLong == nullptr || qoyLong == nullptr) {
		return nullptr;
	}
	int32_t y = $ChronoField::YEAR->checkValidIntValue($nc(yearLong)->longValue());
	int64_t doq = $nc(($cast($Long, $(fieldValues->get($IsoFields$Field::DAY_OF_QUARTER)))))->longValue();
	$IsoFields$Field::ensureIso(partialTemporal);
	$var($LocalDate, date, nullptr);
	$init($ResolverStyle);
	if (resolverStyle == $ResolverStyle::LENIENT) {
		$assign(date, $nc($($LocalDate::of(y, 1, 1)))->plusMonths($Math::multiplyExact($Math::subtractExact($nc(qoyLong)->longValue(), (int64_t)1), 3)));
		doq = $Math::subtractExact(doq, (int64_t)1);
	} else {
		int32_t qoy = $nc($($IsoFields$Field::QUARTER_OF_YEAR->range()))->checkValidIntValue($nc(qoyLong)->longValue(), $IsoFields$Field::QUARTER_OF_YEAR);
		$assign(date, $LocalDate::of(y, ((qoy - 1) * 3) + 1, 1));
		if (doq < 1 || doq > 90) {
			if (resolverStyle == $ResolverStyle::STRICT) {
				$nc($(rangeRefinedBy(date)))->checkValidValue(doq, this);
			} else {
				$nc($(range()))->checkValidValue(doq, this);
			}
		}
		--doq;
	}
	fieldValues->remove(this);
	fieldValues->remove($ChronoField::YEAR);
	fieldValues->remove($IsoFields$Field::QUARTER_OF_YEAR);
	return $nc(date)->plusDays(doq);
}

$String* IsoFields$Field$1::toString() {
	return "DayOfQuarter"_s;
}

IsoFields$Field$1::IsoFields$Field$1() {
}

$Class* IsoFields$Field$1::load$($String* name, bool initialize) {
	$loadClass(IsoFields$Field$1, name, initialize, &_IsoFields$Field$1_ClassInfo_, allocate$IsoFields$Field$1);
	return class$;
}

$Class* IsoFields$Field$1::class$ = nullptr;

		} // temporal
	} // time
} // java