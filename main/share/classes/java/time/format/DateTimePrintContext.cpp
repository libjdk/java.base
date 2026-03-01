#include <java/time/format/DateTimePrintContext.h>

#include <java/time/DateTimeException.h>
#include <java/time/Instant.h>
#include <java/time/ZoneId.h>
#include <java/time/ZoneOffset.h>
#include <java/time/chrono/ChronoLocalDate.h>
#include <java/time/chrono/ChronoZonedDateTime.h>
#include <java/time/chrono/Chronology.h>
#include <java/time/chrono/IsoChronology.h>
#include <java/time/format/DateTimeFormatter.h>
#include <java/time/format/DateTimePrintContext$1.h>
#include <java/time/format/DecimalStyle.h>
#include <java/time/temporal/ChronoField.h>
#include <java/time/temporal/TemporalAccessor.h>
#include <java/time/temporal/TemporalField.h>
#include <java/time/temporal/TemporalQueries.h>
#include <java/time/temporal/TemporalQuery.h>
#include <java/time/zone/ZoneRules.h>
#include <java/util/Locale.h>
#include <java/util/Objects.h>
#include <jcpp.h>

#undef EPOCH
#undef EPOCH_DAY
#undef INSTANCE
#undef INSTANT_SECONDS
#undef OFFSET_SECONDS

using $ChronoFieldArray = $Array<::java::time::temporal::ChronoField>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $DateTimeException = ::java::time::DateTimeException;
using $Instant = ::java::time::Instant;
using $ZoneId = ::java::time::ZoneId;
using $ZoneOffset = ::java::time::ZoneOffset;
using $ChronoLocalDate = ::java::time::chrono::ChronoLocalDate;
using $Chronology = ::java::time::chrono::Chronology;
using $IsoChronology = ::java::time::chrono::IsoChronology;
using $DateTimeFormatter = ::java::time::format::DateTimeFormatter;
using $DateTimePrintContext$1 = ::java::time::format::DateTimePrintContext$1;
using $DecimalStyle = ::java::time::format::DecimalStyle;
using $ChronoField = ::java::time::temporal::ChronoField;
using $TemporalAccessor = ::java::time::temporal::TemporalAccessor;
using $TemporalField = ::java::time::temporal::TemporalField;
using $TemporalQueries = ::java::time::temporal::TemporalQueries;
using $TemporalQuery = ::java::time::temporal::TemporalQuery;
using $ZoneRules = ::java::time::zone::ZoneRules;
using $Locale = ::java::util::Locale;
using $Objects = ::java::util::Objects;

namespace java {
	namespace time {
		namespace format {

$FieldInfo _DateTimePrintContext_FieldInfo_[] = {
	{"temporal", "Ljava/time/temporal/TemporalAccessor;", nullptr, $PRIVATE, $field(DateTimePrintContext, temporal)},
	{"formatter", "Ljava/time/format/DateTimeFormatter;", nullptr, $PRIVATE, $field(DateTimePrintContext, formatter)},
	{"optional", "I", nullptr, $PRIVATE, $field(DateTimePrintContext, optional)},
	{}
};

$MethodInfo _DateTimePrintContext_MethodInfo_[] = {
	{"<init>", "(Ljava/time/temporal/TemporalAccessor;Ljava/time/format/DateTimeFormatter;)V", nullptr, 0, $method(DateTimePrintContext, init$, void, $TemporalAccessor*, $DateTimeFormatter*)},
	{"adjust", "(Ljava/time/temporal/TemporalAccessor;Ljava/time/format/DateTimeFormatter;)Ljava/time/temporal/TemporalAccessor;", nullptr, $PRIVATE | $STATIC, $staticMethod(DateTimePrintContext, adjust, $TemporalAccessor*, $TemporalAccessor*, $DateTimeFormatter*)},
	{"endOptional", "()V", nullptr, 0, $method(DateTimePrintContext, endOptional, void)},
	{"getDecimalStyle", "()Ljava/time/format/DecimalStyle;", nullptr, 0, $method(DateTimePrintContext, getDecimalStyle, $DecimalStyle*)},
	{"getLocale", "()Ljava/util/Locale;", nullptr, 0, $method(DateTimePrintContext, getLocale, $Locale*)},
	{"getTemporal", "()Ljava/time/temporal/TemporalAccessor;", nullptr, 0, $method(DateTimePrintContext, getTemporal, $TemporalAccessor*)},
	{"getValue", "(Ljava/time/temporal/TemporalQuery;)Ljava/lang/Object;", "<R:Ljava/lang/Object;>(Ljava/time/temporal/TemporalQuery<TR;>;)TR;", 0, $method(DateTimePrintContext, getValue, $Object*, $TemporalQuery*)},
	{"getValue", "(Ljava/time/temporal/TemporalField;)Ljava/lang/Long;", nullptr, 0, $method(DateTimePrintContext, getValue, $Long*, $TemporalField*)},
	{"startOptional", "()V", nullptr, 0, $method(DateTimePrintContext, startOptional, void)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(DateTimePrintContext, toString, $String*)},
	{}
};

$InnerClassInfo _DateTimePrintContext_InnerClassesInfo_[] = {
	{"java.time.format.DateTimePrintContext$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _DateTimePrintContext_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.time.format.DateTimePrintContext",
	"java.lang.Object",
	nullptr,
	_DateTimePrintContext_FieldInfo_,
	_DateTimePrintContext_MethodInfo_,
	nullptr,
	nullptr,
	_DateTimePrintContext_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.time.format.DateTimePrintContext$1"
};

$Object* allocate$DateTimePrintContext($Class* clazz) {
	return $of($alloc(DateTimePrintContext));
}

void DateTimePrintContext::init$($TemporalAccessor* temporal, $DateTimeFormatter* formatter) {
	$set(this, temporal, adjust(temporal, formatter));
	$set(this, formatter, formatter);
}

$TemporalAccessor* DateTimePrintContext::adjust($TemporalAccessor* temporal, $DateTimeFormatter* formatter) {
	$useLocalCurrentObjectStackCache();
	$var($Chronology, overrideChrono, $nc(formatter)->getChronology());
	$var($ZoneId, overrideZone, formatter->getZone());
	if (overrideChrono == nullptr && overrideZone == nullptr) {
		return temporal;
	}
	$var($Chronology, temporalChrono, $cast($Chronology, $nc(temporal)->query($($TemporalQueries::chronology()))));
	$var($ZoneId, temporalZone, $cast($ZoneId, temporal->query($($TemporalQueries::zoneId()))));
	if ($Objects::equals(overrideChrono, temporalChrono)) {
		$assign(overrideChrono, nullptr);
	}
	if ($Objects::equals(overrideZone, temporalZone)) {
		$assign(overrideZone, nullptr);
	}
	if (overrideChrono == nullptr && overrideZone == nullptr) {
		return temporal;
	}
	$var($Chronology, effectiveChrono, overrideChrono != nullptr ? overrideChrono : temporalChrono);
	if (overrideZone != nullptr) {
		$init($ChronoField);
		if (temporal->isSupported($ChronoField::INSTANT_SECONDS)) {
			$init($IsoChronology);
			$var($Chronology, chrono, $cast($Chronology, $Objects::requireNonNullElse(effectiveChrono, $IsoChronology::INSTANCE)));
			return $nc(chrono)->zonedDateTime($($Instant::from(temporal)), overrideZone);
		}
		bool var$1 = $instanceOf($ZoneOffset, $(overrideZone->normalized()));
		bool var$0 = var$1 && temporal->isSupported($ChronoField::OFFSET_SECONDS);
		if (var$0) {
			int32_t var$2 = temporal->get($ChronoField::OFFSET_SECONDS);
			$init($Instant);
			var$0 = var$2 != $nc($($nc($(overrideZone->getRules()))->getOffset($Instant::EPOCH)))->getTotalSeconds();
		}
		if (var$0) {
			$throwNew($DateTimeException, $$str({"Unable to apply override zone \'"_s, overrideZone, "\' because the temporal object being formatted has a different offset but does not represent an instant: "_s, temporal}));
		}
	}
	$var($ZoneId, effectiveZone, overrideZone != nullptr ? overrideZone : temporalZone);
	$var($ChronoLocalDate, effectiveDate, nullptr);
	if (overrideChrono != nullptr) {
		$init($ChronoField);
		if (temporal->isSupported($ChronoField::EPOCH_DAY)) {
			$assign(effectiveDate, $nc(effectiveChrono)->date(temporal));
		} else {
			$init($IsoChronology);
			if (!($equals(overrideChrono, $IsoChronology::INSTANCE) && temporalChrono == nullptr)) {
				{
					$var($ChronoFieldArray, arr$, $ChronoField::values());
					int32_t len$ = $nc(arr$)->length;
					int32_t i$ = 0;
					for (; i$ < len$; ++i$) {
						$ChronoField* f = arr$->get(i$);
						{
							bool var$3 = $nc(f)->isDateBased();
							if (var$3 && temporal->isSupported(f)) {
								$throwNew($DateTimeException, $$str({"Unable to apply override chronology \'"_s, overrideChrono, "\' because the temporal object being formatted contains date fields but does not represent a whole date: "_s, temporal}));
							}
						}
					}
				}
			}
			$assign(effectiveDate, nullptr);
		}
	} else {
		$assign(effectiveDate, nullptr);
	}
	return $new($DateTimePrintContext$1, effectiveDate, temporal, effectiveChrono, effectiveZone);
}

$TemporalAccessor* DateTimePrintContext::getTemporal() {
	return this->temporal;
}

$Locale* DateTimePrintContext::getLocale() {
	return $nc(this->formatter)->getLocale();
}

$DecimalStyle* DateTimePrintContext::getDecimalStyle() {
	return $nc(this->formatter)->getDecimalStyle();
}

void DateTimePrintContext::startOptional() {
	++this->optional;
}

void DateTimePrintContext::endOptional() {
	--this->optional;
}

$Object* DateTimePrintContext::getValue($TemporalQuery* query) {
	$useLocalCurrentObjectStackCache();
	$var($Object, result, $nc(this->temporal)->query(query));
	if (result == nullptr && this->optional == 0) {
		$throwNew($DateTimeException, $$str({"Unable to extract "_s, query, " from temporal "_s, this->temporal}));
	}
	return $of(result);
}

$Long* DateTimePrintContext::getValue($TemporalField* field) {
	if (this->optional > 0 && !$nc(this->temporal)->isSupported(field)) {
		return nullptr;
	}
	return $Long::valueOf($nc(this->temporal)->getLong(field));
}

$String* DateTimePrintContext::toString() {
	return $nc($of(this->temporal))->toString();
}

DateTimePrintContext::DateTimePrintContext() {
}

$Class* DateTimePrintContext::load$($String* name, bool initialize) {
	$loadClass(DateTimePrintContext, name, initialize, &_DateTimePrintContext_ClassInfo_, allocate$DateTimePrintContext);
	return class$;
}

$Class* DateTimePrintContext::class$ = nullptr;

		} // format
	} // time
} // java