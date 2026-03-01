#include <java/time/temporal/IsoFields$Field$3.h>

#include <java/lang/Math.h>
#include <java/time/LocalDate.h>
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
#include <java/util/Locale.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/ResourceBundle.h>
#include <sun/util/locale/provider/CalendarDataUtility.h>
#include <sun/util/locale/provider/LocaleProviderAdapter.h>
#include <sun/util/locale/provider/LocaleResources.h>
#include <jcpp.h>

#undef DAY_OF_WEEK
#undef EPOCH_DAY
#undef LENIENT
#undef STRICT
#undef WEEKS
#undef WEEK_BASED_YEAR
#undef WEEK_BASED_YEARS
#undef WEEK_OF_WEEK_BASED_YEAR

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $LocalDate = ::java::time::LocalDate;
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
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $Objects = ::java::util::Objects;
using $ResourceBundle = ::java::util::ResourceBundle;
using $CalendarDataUtility = ::sun::util::locale::provider::CalendarDataUtility;
using $LocaleProviderAdapter = ::sun::util::locale::provider::LocaleProviderAdapter;
using $LocaleResources = ::sun::util::locale::provider::LocaleResources;

namespace java {
	namespace time {
		namespace temporal {

$MethodInfo _IsoFields$Field$3_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;I)V", nullptr, $PRIVATE, $method(IsoFields$Field$3, init$, void, $String*, int32_t)},
	{"adjustInto", "(Ljava/time/temporal/Temporal;J)Ljava/time/temporal/Temporal;", "<R::Ljava/time/temporal/Temporal;>(TR;J)TR;", $PUBLIC, $virtualMethod(IsoFields$Field$3, adjustInto, $Temporal*, $Temporal*, int64_t)},
	{"getBaseUnit", "()Ljava/time/temporal/TemporalUnit;", nullptr, $PUBLIC, $virtualMethod(IsoFields$Field$3, getBaseUnit, $TemporalUnit*)},
	{"getDisplayName", "(Ljava/util/Locale;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(IsoFields$Field$3, getDisplayName, $String*, $Locale*)},
	{"getFrom", "(Ljava/time/temporal/TemporalAccessor;)J", nullptr, $PUBLIC, $virtualMethod(IsoFields$Field$3, getFrom, int64_t, $TemporalAccessor*)},
	{"getRangeUnit", "()Ljava/time/temporal/TemporalUnit;", nullptr, $PUBLIC, $virtualMethod(IsoFields$Field$3, getRangeUnit, $TemporalUnit*)},
	{"isSupportedBy", "(Ljava/time/temporal/TemporalAccessor;)Z", nullptr, $PUBLIC, $virtualMethod(IsoFields$Field$3, isSupportedBy, bool, $TemporalAccessor*)},
	{"range", "()Ljava/time/temporal/ValueRange;", nullptr, $PUBLIC, $virtualMethod(IsoFields$Field$3, range, $ValueRange*)},
	{"rangeRefinedBy", "(Ljava/time/temporal/TemporalAccessor;)Ljava/time/temporal/ValueRange;", nullptr, $PUBLIC, $virtualMethod(IsoFields$Field$3, rangeRefinedBy, $ValueRange*, $TemporalAccessor*)},
	{"resolve", "(Ljava/util/Map;Ljava/time/temporal/TemporalAccessor;Ljava/time/format/ResolverStyle;)Ljava/time/chrono/ChronoLocalDate;", "(Ljava/util/Map<Ljava/time/temporal/TemporalField;Ljava/lang/Long;>;Ljava/time/temporal/TemporalAccessor;Ljava/time/format/ResolverStyle;)Ljava/time/chrono/ChronoLocalDate;", $PUBLIC, $virtualMethod(IsoFields$Field$3, resolve, $TemporalAccessor*, $Map*, $TemporalAccessor*, $ResolverStyle*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(IsoFields$Field$3, toString, $String*)},
	{}
};

$EnclosingMethodInfo _IsoFields$Field$3_EnclosingMethodInfo_ = {
	"java.time.temporal.IsoFields$Field",
	nullptr,
	nullptr
};

$InnerClassInfo _IsoFields$Field$3_InnerClassesInfo_[] = {
	{"java.time.temporal.IsoFields$Field", "java.time.temporal.IsoFields", "Field", $PRIVATE | $STATIC | $ABSTRACT | $ENUM},
	{"java.time.temporal.IsoFields$Field$3", nullptr, nullptr, $FINAL | $ENUM},
	{}
};

$ClassInfo _IsoFields$Field$3_ClassInfo_ = {
	$FINAL | $ACC_SUPER | $ENUM,
	"java.time.temporal.IsoFields$Field$3",
	"java.time.temporal.IsoFields$Field",
	nullptr,
	nullptr,
	_IsoFields$Field$3_MethodInfo_,
	nullptr,
	&_IsoFields$Field$3_EnclosingMethodInfo_,
	_IsoFields$Field$3_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.time.temporal.IsoFields"
};

$Object* allocate$IsoFields$Field$3($Class* clazz) {
	return $of($alloc(IsoFields$Field$3));
}

void IsoFields$Field$3::init$($String* $enum$name, int32_t $enum$ordinal) {
	$IsoFields$Field::init$($enum$name, $enum$ordinal);
}

$String* IsoFields$Field$3::getDisplayName($Locale* locale) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(locale), "locale"_s);
	$var($LocaleResources, lr, $nc($($LocaleProviderAdapter::getResourceBundleBased()))->getLocaleResources($($CalendarDataUtility::findRegionOverride(locale))));
	$var($ResourceBundle, rb, $nc(lr)->getJavaTimeFormatData());
	return $nc(rb)->containsKey("field.week"_s) ? $nc(rb)->getString("field.week"_s) : toString();
}

$TemporalUnit* IsoFields$Field$3::getBaseUnit() {
	$init($ChronoUnit);
	return $ChronoUnit::WEEKS;
}

$TemporalUnit* IsoFields$Field$3::getRangeUnit() {
	$init($IsoFields);
	return $IsoFields::WEEK_BASED_YEARS;
}

$ValueRange* IsoFields$Field$3::range() {
	return $ValueRange::of(1, 52, 53);
}

bool IsoFields$Field$3::isSupportedBy($TemporalAccessor* temporal) {
	$init($ChronoField);
	bool var$0 = $nc(temporal)->isSupported($ChronoField::EPOCH_DAY);
	return var$0 && $IsoFields::isIso(temporal);
}

$ValueRange* IsoFields$Field$3::rangeRefinedBy($TemporalAccessor* temporal) {
	if (isSupportedBy(temporal) == false) {
		$throwNew($UnsupportedTemporalTypeException, "Unsupported field: WeekOfWeekBasedYear"_s);
	}
	return $IsoFields$Field::getWeekRange($($LocalDate::from(temporal)));
}

int64_t IsoFields$Field$3::getFrom($TemporalAccessor* temporal) {
	if (isSupportedBy(temporal) == false) {
		$throwNew($UnsupportedTemporalTypeException, "Unsupported field: WeekOfWeekBasedYear"_s);
	}
	return $IsoFields$Field::getWeek($($LocalDate::from(temporal)));
}

$Temporal* IsoFields$Field$3::adjustInto($Temporal* temporal, int64_t newValue) {
	$nc($(range()))->checkValidValue(newValue, this);
	$init($ChronoUnit);
	return $nc(temporal)->plus($Math::subtractExact(newValue, getFrom(temporal)), $ChronoUnit::WEEKS);
}

$TemporalAccessor* IsoFields$Field$3::resolve($Map* fieldValues, $TemporalAccessor* partialTemporal, $ResolverStyle* resolverStyle) {
	$useLocalCurrentObjectStackCache();
	$init($IsoFields$Field);
	$var($Long, wbyLong, $cast($Long, $nc(fieldValues)->get($IsoFields$Field::WEEK_BASED_YEAR)));
	$init($ChronoField);
	$var($Long, dowLong, $cast($Long, fieldValues->get($ChronoField::DAY_OF_WEEK)));
	if (wbyLong == nullptr || dowLong == nullptr) {
		return nullptr;
	}
	int32_t wby = $nc($($IsoFields$Field::WEEK_BASED_YEAR->range()))->checkValidIntValue($nc(wbyLong)->longValue(), $IsoFields$Field::WEEK_BASED_YEAR);
	int64_t wowby = $nc(($cast($Long, $(fieldValues->get($IsoFields$Field::WEEK_OF_WEEK_BASED_YEAR)))))->longValue();
	$IsoFields$Field::ensureIso(partialTemporal);
	$var($LocalDate, date, $LocalDate::of(wby, 1, 4));
	$init($ResolverStyle);
	if (resolverStyle == $ResolverStyle::LENIENT) {
		int64_t dow = $nc(dowLong)->longValue();
		if (dow > 7) {
			$assign(date, $nc(date)->plusWeeks((dow - 1) / 7));
			dow = ((dow - 1) % 7) + 1;
		} else if (dow < 1) {
			$assign(date, $nc(date)->plusWeeks($Math::subtractExact(dow, (int64_t)7) / 7));
			dow = ((dow + 6) % 7) + 1;
		}
		$assign(date, $nc($($nc(date)->plusWeeks($Math::subtractExact(wowby, (int64_t)1))))->with($ChronoField::DAY_OF_WEEK, dow));
	} else {
		int32_t dow = $ChronoField::DAY_OF_WEEK->checkValidIntValue($nc(dowLong)->longValue());
		if (wowby < 1 || wowby > 52) {
			if (resolverStyle == $ResolverStyle::STRICT) {
				$nc($($IsoFields$Field::getWeekRange(date)))->checkValidValue(wowby, this);
			} else {
				$nc($(range()))->checkValidValue(wowby, this);
			}
		}
		$assign(date, $nc($($nc(date)->plusWeeks(wowby - 1)))->with($ChronoField::DAY_OF_WEEK, dow));
	}
	fieldValues->remove(this);
	fieldValues->remove($IsoFields$Field::WEEK_BASED_YEAR);
	fieldValues->remove($ChronoField::DAY_OF_WEEK);
	return date;
}

$String* IsoFields$Field$3::toString() {
	return "WeekOfWeekBasedYear"_s;
}

IsoFields$Field$3::IsoFields$Field$3() {
}

$Class* IsoFields$Field$3::load$($String* name, bool initialize) {
	$loadClass(IsoFields$Field$3, name, initialize, &_IsoFields$Field$3_ClassInfo_, allocate$IsoFields$Field$3);
	return class$;
}

$Class* IsoFields$Field$3::class$ = nullptr;

		} // temporal
	} // time
} // java