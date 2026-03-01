#include <java/time/temporal/IsoFields$Field$4.h>

#include <java/time/LocalDate.h>
#include <java/time/temporal/ChronoField.h>
#include <java/time/temporal/ChronoUnit.h>
#include <java/time/temporal/IsoFields$Field.h>
#include <java/time/temporal/IsoFields.h>
#include <java/time/temporal/Temporal.h>
#include <java/time/temporal/TemporalAccessor.h>
#include <java/time/temporal/TemporalAdjuster.h>
#include <java/time/temporal/TemporalField.h>
#include <java/time/temporal/TemporalUnit.h>
#include <java/time/temporal/UnsupportedTemporalTypeException.h>
#include <java/time/temporal/ValueRange.h>
#include <jcpp.h>

#undef DAY_OF_WEEK
#undef EPOCH_DAY
#undef FOREVER
#undef WEEK_BASED_YEAR
#undef WEEK_BASED_YEARS
#undef YEAR

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $LocalDate = ::java::time::LocalDate;
using $ChronoField = ::java::time::temporal::ChronoField;
using $ChronoUnit = ::java::time::temporal::ChronoUnit;
using $IsoFields = ::java::time::temporal::IsoFields;
using $IsoFields$Field = ::java::time::temporal::IsoFields$Field;
using $Temporal = ::java::time::temporal::Temporal;
using $TemporalAccessor = ::java::time::temporal::TemporalAccessor;
using $TemporalAdjuster = ::java::time::temporal::TemporalAdjuster;
using $TemporalField = ::java::time::temporal::TemporalField;
using $TemporalUnit = ::java::time::temporal::TemporalUnit;
using $UnsupportedTemporalTypeException = ::java::time::temporal::UnsupportedTemporalTypeException;
using $ValueRange = ::java::time::temporal::ValueRange;

namespace java {
	namespace time {
		namespace temporal {

$MethodInfo _IsoFields$Field$4_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;I)V", nullptr, $PRIVATE, $method(IsoFields$Field$4, init$, void, $String*, int32_t)},
	{"adjustInto", "(Ljava/time/temporal/Temporal;J)Ljava/time/temporal/Temporal;", "<R::Ljava/time/temporal/Temporal;>(TR;J)TR;", $PUBLIC, $virtualMethod(IsoFields$Field$4, adjustInto, $Temporal*, $Temporal*, int64_t)},
	{"getBaseUnit", "()Ljava/time/temporal/TemporalUnit;", nullptr, $PUBLIC, $virtualMethod(IsoFields$Field$4, getBaseUnit, $TemporalUnit*)},
	{"getFrom", "(Ljava/time/temporal/TemporalAccessor;)J", nullptr, $PUBLIC, $virtualMethod(IsoFields$Field$4, getFrom, int64_t, $TemporalAccessor*)},
	{"getRangeUnit", "()Ljava/time/temporal/TemporalUnit;", nullptr, $PUBLIC, $virtualMethod(IsoFields$Field$4, getRangeUnit, $TemporalUnit*)},
	{"isSupportedBy", "(Ljava/time/temporal/TemporalAccessor;)Z", nullptr, $PUBLIC, $virtualMethod(IsoFields$Field$4, isSupportedBy, bool, $TemporalAccessor*)},
	{"range", "()Ljava/time/temporal/ValueRange;", nullptr, $PUBLIC, $virtualMethod(IsoFields$Field$4, range, $ValueRange*)},
	{"rangeRefinedBy", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/temporal/ValueRange;", nullptr, $PUBLIC, $virtualMethod(IsoFields$Field$4, rangeRefinedBy, $ValueRange*, $TemporalAccessor*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(IsoFields$Field$4, toString, $String*)},
	{}
};

$EnclosingMethodInfo _IsoFields$Field$4_EnclosingMethodInfo_ = {
	"java.time.temporal.IsoFields$Field",
	nullptr,
	nullptr
};

$InnerClassInfo _IsoFields$Field$4_InnerClassesInfo_[] = {
	{"java.time.temporal.IsoFields$Field", "java.time.temporal.IsoFields", "Field", $PRIVATE | $STATIC | $ABSTRACT | $ENUM},
	{"java.time.temporal.IsoFields$Field$4", nullptr, nullptr, $FINAL | $ENUM},
	{}
};

$ClassInfo _IsoFields$Field$4_ClassInfo_ = {
	$FINAL | $ACC_SUPER | $ENUM,
	"java.time.temporal.IsoFields$Field$4",
	"java.time.temporal.IsoFields$Field",
	nullptr,
	nullptr,
	_IsoFields$Field$4_MethodInfo_,
	nullptr,
	&_IsoFields$Field$4_EnclosingMethodInfo_,
	_IsoFields$Field$4_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.time.temporal.IsoFields"
};

$Object* allocate$IsoFields$Field$4($Class* clazz) {
	return $of($alloc(IsoFields$Field$4));
}

void IsoFields$Field$4::init$($String* $enum$name, int32_t $enum$ordinal) {
	$IsoFields$Field::init$($enum$name, $enum$ordinal);
}

$TemporalUnit* IsoFields$Field$4::getBaseUnit() {
	$init($IsoFields);
	return $IsoFields::WEEK_BASED_YEARS;
}

$TemporalUnit* IsoFields$Field$4::getRangeUnit() {
	$init($ChronoUnit);
	return $ChronoUnit::FOREVER;
}

$ValueRange* IsoFields$Field$4::range() {
	$init($ChronoField);
	return $ChronoField::YEAR->range();
}

bool IsoFields$Field$4::isSupportedBy($TemporalAccessor* temporal) {
	$init($ChronoField);
	bool var$0 = $nc(temporal)->isSupported($ChronoField::EPOCH_DAY);
	return var$0 && $IsoFields::isIso(temporal);
}

int64_t IsoFields$Field$4::getFrom($TemporalAccessor* temporal) {
	if (isSupportedBy(temporal) == false) {
		$throwNew($UnsupportedTemporalTypeException, "Unsupported field: WeekBasedYear"_s);
	}
	return $IsoFields$Field::getWeekBasedYear($($LocalDate::from(temporal)));
}

$ValueRange* IsoFields$Field$4::rangeRefinedBy($TemporalAccessor* temporal) {
	if (isSupportedBy(temporal) == false) {
		$throwNew($UnsupportedTemporalTypeException, "Unsupported field: WeekBasedYear"_s);
	}
	return $IsoFields$Field::rangeRefinedBy(temporal);
}

$Temporal* IsoFields$Field$4::adjustInto($Temporal* temporal, int64_t newValue) {
	$useLocalCurrentObjectStackCache();
	if (isSupportedBy(temporal) == false) {
		$throwNew($UnsupportedTemporalTypeException, "Unsupported field: WeekBasedYear"_s);
	}
	$init($IsoFields$Field);
	int32_t newWby = $nc($(range()))->checkValidIntValue(newValue, $IsoFields$Field::WEEK_BASED_YEAR);
	$var($LocalDate, date, $LocalDate::from(temporal));
	$init($ChronoField);
	int32_t dow = $nc(date)->get($ChronoField::DAY_OF_WEEK);
	int32_t week = $IsoFields$Field::getWeek(date);
	if (week == 53 && $IsoFields$Field::getWeekRange(newWby) == 52) {
		week = 52;
	}
	$var($LocalDate, resolved, $LocalDate::of(newWby, 1, 4));
	int32_t days = (dow - $nc(resolved)->get($ChronoField::DAY_OF_WEEK)) + ((week - 1) * 7);
	$assign(resolved, resolved->plusDays(days));
	return $nc(temporal)->with(resolved);
}

$String* IsoFields$Field$4::toString() {
	return "WeekBasedYear"_s;
}

IsoFields$Field$4::IsoFields$Field$4() {
}

$Class* IsoFields$Field$4::load$($String* name, bool initialize) {
	$loadClass(IsoFields$Field$4, name, initialize, &_IsoFields$Field$4_ClassInfo_, allocate$IsoFields$Field$4);
	return class$;
}

$Class* IsoFields$Field$4::class$ = nullptr;

		} // temporal
	} // time
} // java