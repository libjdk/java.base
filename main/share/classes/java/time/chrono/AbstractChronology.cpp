#include <java/time/chrono/AbstractChronology.h>

#include <java/io/DataInput.h>
#include <java/io/DataOutput.h>
#include <java/io/InvalidObjectException.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/Math.h>
#include <java/time/DateTimeException.h>
#include <java/time/DayOfWeek.h>
#include <java/time/chrono/ChronoLocalDate.h>
#include <java/time/chrono/Chronology.h>
#include <java/time/chrono/Era.h>
#include <java/time/chrono/HijrahChronology.h>
#include <java/time/chrono/IsoChronology.h>
#include <java/time/chrono/JapaneseChronology.h>
#include <java/time/chrono/MinguoChronology.h>
#include <java/time/chrono/Ser.h>
#include <java/time/chrono/ThaiBuddhistChronology.h>
#include <java/time/format/ResolverStyle.h>
#include <java/time/temporal/ChronoField.h>
#include <java/time/temporal/ChronoUnit.h>
#include <java/time/temporal/TemporalAdjuster.h>
#include <java/time/temporal/TemporalAdjusters.h>
#include <java/time/temporal/TemporalField.h>
#include <java/time/temporal/TemporalUnit.h>
#include <java/time/temporal/ValueRange.h>
#include <java/util/Collection.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/ServiceLoader.h>
#include <java/util/Set.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <sun/util/logging/PlatformLogger.h>
#include <jcpp.h>

#undef ALIGNED_DAY_OF_WEEK_IN_MONTH
#undef ALIGNED_DAY_OF_WEEK_IN_YEAR
#undef ALIGNED_WEEK_OF_MONTH
#undef ALIGNED_WEEK_OF_YEAR
#undef CHRONOS_BY_ID
#undef CHRONOS_BY_TYPE
#undef CHRONO_TYPE
#undef DAYS
#undef DAY_OF_MONTH
#undef DAY_OF_WEEK
#undef DAY_OF_YEAR
#undef EPOCH_DAY
#undef ERA
#undef INSTANCE
#undef LENIENT
#undef MONTHS
#undef MONTH_OF_YEAR
#undef PROLEPTIC_MONTH
#undef SMART
#undef STRICT
#undef WEEKS
#undef YEAR
#undef YEAR_OF_ERA

using $DataInput = ::java::io::DataInput;
using $DataOutput = ::java::io::DataOutput;
using $InvalidObjectException = ::java::io::InvalidObjectException;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $FieldInfo = ::java::lang::FieldInfo;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $DateTimeException = ::java::time::DateTimeException;
using $DayOfWeek = ::java::time::DayOfWeek;
using $ChronoLocalDate = ::java::time::chrono::ChronoLocalDate;
using $Chronology = ::java::time::chrono::Chronology;
using $Era = ::java::time::chrono::Era;
using $HijrahChronology = ::java::time::chrono::HijrahChronology;
using $IsoChronology = ::java::time::chrono::IsoChronology;
using $JapaneseChronology = ::java::time::chrono::JapaneseChronology;
using $MinguoChronology = ::java::time::chrono::MinguoChronology;
using $Ser = ::java::time::chrono::Ser;
using $ThaiBuddhistChronology = ::java::time::chrono::ThaiBuddhistChronology;
using $ResolverStyle = ::java::time::format::ResolverStyle;
using $ChronoField = ::java::time::temporal::ChronoField;
using $ChronoUnit = ::java::time::temporal::ChronoUnit;
using $TemporalAdjusters = ::java::time::temporal::TemporalAdjusters;
using $TemporalField = ::java::time::temporal::TemporalField;
using $TemporalUnit = ::java::time::temporal::TemporalUnit;
using $ValueRange = ::java::time::temporal::ValueRange;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $Objects = ::java::util::Objects;
using $ServiceLoader = ::java::util::ServiceLoader;
using $Set = ::java::util::Set;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $PlatformLogger = ::sun::util::logging::PlatformLogger;

namespace java {
	namespace time {
		namespace chrono {

$FieldInfo _AbstractChronology_FieldInfo_[] = {
	{"CHRONOS_BY_ID", "Ljava/util/concurrent/ConcurrentHashMap;", "Ljava/util/concurrent/ConcurrentHashMap<Ljava/lang/String;Ljava/time/chrono/Chronology;>;", $PRIVATE | $STATIC | $FINAL, $staticField(AbstractChronology, CHRONOS_BY_ID)},
	{"CHRONOS_BY_TYPE", "Ljava/util/concurrent/ConcurrentHashMap;", "Ljava/util/concurrent/ConcurrentHashMap<Ljava/lang/String;Ljava/time/chrono/Chronology;>;", $PRIVATE | $STATIC | $FINAL, $staticField(AbstractChronology, CHRONOS_BY_TYPE)},
	{}
};

$MethodInfo _AbstractChronology_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PROTECTED, $method(AbstractChronology, init$, void)},
	{"addFieldValue", "(Ljava/util/Map;Ljava/time/temporal/ChronoField;J)V", "(Ljava/util/Map<Ljava/time/temporal/TemporalField;Ljava/lang/Long;>;Ljava/time/temporal/ChronoField;J)V", 0, $virtualMethod(AbstractChronology, addFieldValue, void, $Map*, $ChronoField*, int64_t)},
	{"compareTo", "(Ljava/time/chrono/Chronology;)I", nullptr, $PUBLIC, $virtualMethod(AbstractChronology, compareTo, int32_t, $Chronology*)},
	{"compareTo", "(Ljava/lang/Object;)I", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(AbstractChronology, compareTo, int32_t, Object$*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(AbstractChronology, equals, bool, Object$*)},
	{"getAvailableChronologies", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/time/chrono/Chronology;>;", $STATIC, $staticMethod(AbstractChronology, getAvailableChronologies, $Set*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(AbstractChronology, hashCode, int32_t)},
	{"initCache", "()Z", nullptr, $PRIVATE | $STATIC, $staticMethod(AbstractChronology, initCache, bool)},
	{"of", "(Ljava/lang/String;)Ljava/time/chrono/Chronology;", nullptr, $STATIC, $staticMethod(AbstractChronology, of, $Chronology*, $String*)},
	{"of0", "(Ljava/lang/String;)Ljava/time/chrono/Chronology;", nullptr, $PRIVATE | $STATIC, $staticMethod(AbstractChronology, of0, $Chronology*, $String*)},
	{"ofLocale", "(Ljava/util/Locale;)Ljava/time/chrono/Chronology;", nullptr, $STATIC, $staticMethod(AbstractChronology, ofLocale, $Chronology*, $Locale*)},
	{"readExternal", "(Ljava/io/DataInput;)Ljava/time/chrono/Chronology;", nullptr, $STATIC, $staticMethod(AbstractChronology, readExternal, $Chronology*, $DataInput*), "java.io.IOException"},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(AbstractChronology, readObject, void, $ObjectInputStream*), "java.io.ObjectStreamException"},
	{"registerChrono", "(Ljava/time/chrono/Chronology;)Ljava/time/chrono/Chronology;", nullptr, $STATIC, $staticMethod(AbstractChronology, registerChrono, $Chronology*, $Chronology*)},
	{"registerChrono", "(Ljava/time/chrono/Chronology;Ljava/lang/String;)Ljava/time/chrono/Chronology;", nullptr, $STATIC, $staticMethod(AbstractChronology, registerChrono, $Chronology*, $Chronology*, $String*)},
	{"resolveAligned", "(Ljava/time/chrono/ChronoLocalDate;JJJ)Ljava/time/chrono/ChronoLocalDate;", nullptr, 0, $virtualMethod(AbstractChronology, resolveAligned, $ChronoLocalDate*, $ChronoLocalDate*, int64_t, int64_t, int64_t)},
	{"resolveDate", "(Ljava/util/Map;Ljava/time/format/ResolverStyle;)Ljava/time/chrono/ChronoLocalDate;", "(Ljava/util/Map<Ljava/time/temporal/TemporalField;Ljava/lang/Long;>;Ljava/time/format/ResolverStyle;)Ljava/time/chrono/ChronoLocalDate;", $PUBLIC, $virtualMethod(AbstractChronology, resolveDate, $ChronoLocalDate*, $Map*, $ResolverStyle*)},
	{"resolveProlepticMonth", "(Ljava/util/Map;Ljava/time/format/ResolverStyle;)V", "(Ljava/util/Map<Ljava/time/temporal/TemporalField;Ljava/lang/Long;>;Ljava/time/format/ResolverStyle;)V", 0, $virtualMethod(AbstractChronology, resolveProlepticMonth, void, $Map*, $ResolverStyle*)},
	{"resolveYAA", "(Ljava/util/Map;Ljava/time/format/ResolverStyle;)Ljava/time/chrono/ChronoLocalDate;", "(Ljava/util/Map<Ljava/time/temporal/TemporalField;Ljava/lang/Long;>;Ljava/time/format/ResolverStyle;)Ljava/time/chrono/ChronoLocalDate;", 0, $virtualMethod(AbstractChronology, resolveYAA, $ChronoLocalDate*, $Map*, $ResolverStyle*)},
	{"resolveYAD", "(Ljava/util/Map;Ljava/time/format/ResolverStyle;)Ljava/time/chrono/ChronoLocalDate;", "(Ljava/util/Map<Ljava/time/temporal/TemporalField;Ljava/lang/Long;>;Ljava/time/format/ResolverStyle;)Ljava/time/chrono/ChronoLocalDate;", 0, $virtualMethod(AbstractChronology, resolveYAD, $ChronoLocalDate*, $Map*, $ResolverStyle*)},
	{"resolveYD", "(Ljava/util/Map;Ljava/time/format/ResolverStyle;)Ljava/time/chrono/ChronoLocalDate;", "(Ljava/util/Map<Ljava/time/temporal/TemporalField;Ljava/lang/Long;>;Ljava/time/format/ResolverStyle;)Ljava/time/chrono/ChronoLocalDate;", 0, $virtualMethod(AbstractChronology, resolveYD, $ChronoLocalDate*, $Map*, $ResolverStyle*)},
	{"resolveYMAA", "(Ljava/util/Map;Ljava/time/format/ResolverStyle;)Ljava/time/chrono/ChronoLocalDate;", "(Ljava/util/Map<Ljava/time/temporal/TemporalField;Ljava/lang/Long;>;Ljava/time/format/ResolverStyle;)Ljava/time/chrono/ChronoLocalDate;", 0, $virtualMethod(AbstractChronology, resolveYMAA, $ChronoLocalDate*, $Map*, $ResolverStyle*)},
	{"resolveYMAD", "(Ljava/util/Map;Ljava/time/format/ResolverStyle;)Ljava/time/chrono/ChronoLocalDate;", "(Ljava/util/Map<Ljava/time/temporal/TemporalField;Ljava/lang/Long;>;Ljava/time/format/ResolverStyle;)Ljava/time/chrono/ChronoLocalDate;", 0, $virtualMethod(AbstractChronology, resolveYMAD, $ChronoLocalDate*, $Map*, $ResolverStyle*)},
	{"resolveYMD", "(Ljava/util/Map;Ljava/time/format/ResolverStyle;)Ljava/time/chrono/ChronoLocalDate;", "(Ljava/util/Map<Ljava/time/temporal/TemporalField;Ljava/lang/Long;>;Ljava/time/format/ResolverStyle;)Ljava/time/chrono/ChronoLocalDate;", 0, $virtualMethod(AbstractChronology, resolveYMD, $ChronoLocalDate*, $Map*, $ResolverStyle*)},
	{"resolveYearOfEra", "(Ljava/util/Map;Ljava/time/format/ResolverStyle;)Ljava/time/chrono/ChronoLocalDate;", "(Ljava/util/Map<Ljava/time/temporal/TemporalField;Ljava/lang/Long;>;Ljava/time/format/ResolverStyle;)Ljava/time/chrono/ChronoLocalDate;", 0, $virtualMethod(AbstractChronology, resolveYearOfEra, $ChronoLocalDate*, $Map*, $ResolverStyle*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(AbstractChronology, toString, $String*)},
	{"writeExternal", "(Ljava/io/DataOutput;)V", nullptr, 0, $virtualMethod(AbstractChronology, writeExternal, void, $DataOutput*), "java.io.IOException"},
	{"writeReplace", "()Ljava/lang/Object;", nullptr, 0, $virtualMethod(AbstractChronology, writeReplace, $Object*)},
	{}
};

$ClassInfo _AbstractChronology_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"java.time.chrono.AbstractChronology",
	"java.lang.Object",
	"java.time.chrono.Chronology",
	_AbstractChronology_FieldInfo_,
	_AbstractChronology_MethodInfo_
};

$Object* allocate$AbstractChronology($Class* clazz) {
	return $of($alloc(AbstractChronology));
}

$ConcurrentHashMap* AbstractChronology::CHRONOS_BY_ID = nullptr;
$ConcurrentHashMap* AbstractChronology::CHRONOS_BY_TYPE = nullptr;

$Chronology* AbstractChronology::registerChrono($Chronology* chrono) {
	$init(AbstractChronology);
	return registerChrono(chrono, $($nc(chrono)->getId()));
}

$Chronology* AbstractChronology::registerChrono($Chronology* chrono, $String* id) {
	$init(AbstractChronology);
	$useLocalCurrentObjectStackCache();
	$var($Chronology, prev, $cast($Chronology, $nc(AbstractChronology::CHRONOS_BY_ID)->putIfAbsent(id, chrono)));
	if (prev == nullptr) {
		$var($String, type, $nc(chrono)->getCalendarType());
		if (type != nullptr) {
			$nc(AbstractChronology::CHRONOS_BY_TYPE)->putIfAbsent(type, chrono);
		}
	}
	return prev;
}

bool AbstractChronology::initCache() {
	$init(AbstractChronology);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if ($nc(AbstractChronology::CHRONOS_BY_ID)->get("ISO"_s) == nullptr) {
		$init($HijrahChronology);
		registerChrono($HijrahChronology::INSTANCE);
		$init($JapaneseChronology);
		registerChrono($JapaneseChronology::INSTANCE);
		$init($MinguoChronology);
		registerChrono($MinguoChronology::INSTANCE);
		$init($ThaiBuddhistChronology);
		registerChrono($ThaiBuddhistChronology::INSTANCE);
		$var($ServiceLoader, loader, $ServiceLoader::load(AbstractChronology::class$, ($ClassLoader*)nullptr));
		{
			$var($Iterator, i$, $nc(loader)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var(AbstractChronology, chrono, $cast(AbstractChronology, i$->next()));
				{
					$var($String, id, $nc(chrono)->getId());
					bool var$0 = $nc(id)->equals("ISO"_s);
					if (var$0 || registerChrono(chrono) != nullptr) {
						$var($PlatformLogger, logger, $PlatformLogger::getLogger("java.time.chrono"_s));
						$nc(logger)->warning($$str({"Ignoring duplicate Chronology, from ServiceLoader configuration "_s, id}));
					}
				}
			}
		}
		$init($IsoChronology);
		registerChrono($IsoChronology::INSTANCE);
		return true;
	}
	return false;
}

$Chronology* AbstractChronology::ofLocale($Locale* locale) {
	$init(AbstractChronology);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$Objects::requireNonNull($of(locale), "locale"_s);
	$var($String, type, $nc(locale)->getUnicodeLocaleType("ca"_s));
	bool var$0 = type == nullptr || "iso"_s->equals(type);
	if (var$0 || "iso8601"_s->equals(type)) {
		$init($IsoChronology);
		return $IsoChronology::INSTANCE;
	}
	do {
		$var($Chronology, chrono, $cast($Chronology, $nc(AbstractChronology::CHRONOS_BY_TYPE)->get(type)));
		if (chrono != nullptr) {
			return chrono;
		}
	} while (initCache());
	$load($Chronology);
	$var($ServiceLoader, loader, $ServiceLoader::load($Chronology::class$));
	{
		$var($Iterator, i$, $nc(loader)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Chronology, chrono, $cast($Chronology, i$->next()));
			{
				if ($nc(type)->equals($($nc(chrono)->getCalendarType()))) {
					return chrono;
				}
			}
		}
	}
	$throwNew($DateTimeException, $$str({"Unknown calendar system: "_s, type}));
}

$Chronology* AbstractChronology::of($String* id) {
	$init(AbstractChronology);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$Objects::requireNonNull($of(id), "id"_s);
	do {
		$var($Chronology, chrono, of0(id));
		if (chrono != nullptr) {
			return chrono;
		}
	} while (initCache());
	$load($Chronology);
	$var($ServiceLoader, loader, $ServiceLoader::load($Chronology::class$));
	{
		$var($Iterator, i$, $nc(loader)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Chronology, chrono, $cast($Chronology, i$->next()));
			{
				bool var$0 = $nc(id)->equals($($nc(chrono)->getId()));
				if (var$0 || $nc(id)->equals($($nc(chrono)->getCalendarType()))) {
					return chrono;
				}
			}
		}
	}
	$throwNew($DateTimeException, $$str({"Unknown chronology: "_s, id}));
}

$Chronology* AbstractChronology::of0($String* id) {
	$init(AbstractChronology);
	$var($Chronology, chrono, $cast($Chronology, $nc(AbstractChronology::CHRONOS_BY_ID)->get(id)));
	if (chrono == nullptr) {
		$assign(chrono, $cast($Chronology, $nc(AbstractChronology::CHRONOS_BY_TYPE)->get(id)));
	}
	return chrono;
}

$Set* AbstractChronology::getAvailableChronologies() {
	$init(AbstractChronology);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	initCache();
	$var($HashSet, chronos, $new($HashSet, $($nc(AbstractChronology::CHRONOS_BY_ID)->values())));
	$load($Chronology);
	$var($ServiceLoader, loader, $ServiceLoader::load($Chronology::class$));
	{
		$var($Iterator, i$, $nc(loader)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Chronology, chrono, $cast($Chronology, i$->next()));
			{
				chronos->add(chrono);
			}
		}
	}
	return chronos;
}

void AbstractChronology::init$() {
}

$ChronoLocalDate* AbstractChronology::resolveDate($Map* fieldValues, $ResolverStyle* resolverStyle) {
	$useLocalCurrentObjectStackCache();
	$init($ChronoField);
	if ($nc(fieldValues)->containsKey($ChronoField::EPOCH_DAY)) {
		return dateEpochDay($nc(($cast($Long, $(fieldValues->remove($ChronoField::EPOCH_DAY)))))->longValue());
	}
	resolveProlepticMonth(fieldValues, resolverStyle);
	$var($ChronoLocalDate, resolved, resolveYearOfEra(fieldValues, resolverStyle));
	if (resolved != nullptr) {
		return resolved;
	}
	if ($nc(fieldValues)->containsKey($ChronoField::YEAR)) {
		if (fieldValues->containsKey($ChronoField::MONTH_OF_YEAR)) {
			if (fieldValues->containsKey($ChronoField::DAY_OF_MONTH)) {
				return resolveYMD(fieldValues, resolverStyle);
			}
			if (fieldValues->containsKey($ChronoField::ALIGNED_WEEK_OF_MONTH)) {
				if (fieldValues->containsKey($ChronoField::ALIGNED_DAY_OF_WEEK_IN_MONTH)) {
					return resolveYMAA(fieldValues, resolverStyle);
				}
				if (fieldValues->containsKey($ChronoField::DAY_OF_WEEK)) {
					return resolveYMAD(fieldValues, resolverStyle);
				}
			}
		}
		if (fieldValues->containsKey($ChronoField::DAY_OF_YEAR)) {
			return resolveYD(fieldValues, resolverStyle);
		}
		if (fieldValues->containsKey($ChronoField::ALIGNED_WEEK_OF_YEAR)) {
			if (fieldValues->containsKey($ChronoField::ALIGNED_DAY_OF_WEEK_IN_YEAR)) {
				return resolveYAA(fieldValues, resolverStyle);
			}
			if (fieldValues->containsKey($ChronoField::DAY_OF_WEEK)) {
				return resolveYAD(fieldValues, resolverStyle);
			}
		}
	}
	return nullptr;
}

void AbstractChronology::resolveProlepticMonth($Map* fieldValues, $ResolverStyle* resolverStyle) {
	$useLocalCurrentObjectStackCache();
	$init($ChronoField);
	$var($Long, pMonth, $cast($Long, $nc(fieldValues)->remove($ChronoField::PROLEPTIC_MONTH)));
	if (pMonth != nullptr) {
		$init($ResolverStyle);
		if (resolverStyle != $ResolverStyle::LENIENT) {
			$ChronoField::PROLEPTIC_MONTH->checkValidValue(pMonth->longValue());
		}
		$var($ChronoLocalDate, chronoDate, $nc($($nc($(dateNow()))->with($ChronoField::DAY_OF_MONTH, 1)))->with($ChronoField::PROLEPTIC_MONTH, pMonth->longValue()));
		addFieldValue(fieldValues, $ChronoField::MONTH_OF_YEAR, $nc(chronoDate)->get($ChronoField::MONTH_OF_YEAR));
		addFieldValue(fieldValues, $ChronoField::YEAR, $nc(chronoDate)->get($ChronoField::YEAR));
	}
}

$ChronoLocalDate* AbstractChronology::resolveYearOfEra($Map* fieldValues, $ResolverStyle* resolverStyle) {
	$useLocalCurrentObjectStackCache();
	$init($ChronoField);
	$var($Long, yoeLong, $cast($Long, $nc(fieldValues)->remove($ChronoField::YEAR_OF_ERA)));
	if (yoeLong != nullptr) {
		$var($Long, eraLong, $cast($Long, fieldValues->remove($ChronoField::ERA)));
		int32_t yoe = 0;
		$init($ResolverStyle);
		if (resolverStyle != $ResolverStyle::LENIENT) {
			yoe = $nc($(range($ChronoField::YEAR_OF_ERA)))->checkValidIntValue(yoeLong->longValue(), $ChronoField::YEAR_OF_ERA);
		} else {
			yoe = $Math::toIntExact(yoeLong->longValue());
		}
		if (eraLong != nullptr) {
			$var($Era, eraObj, eraOf($nc($(range($ChronoField::ERA)))->checkValidIntValue(eraLong->longValue(), $ChronoField::ERA)));
			addFieldValue(fieldValues, $ChronoField::YEAR, prolepticYear(eraObj, yoe));
		} else {
			if (fieldValues->containsKey($ChronoField::YEAR)) {
				int32_t year = $nc($(range($ChronoField::YEAR)))->checkValidIntValue($nc(($cast($Long, $(fieldValues->get($ChronoField::YEAR)))))->longValue(), $ChronoField::YEAR);
				$var($ChronoLocalDate, chronoDate, dateYearDay(year, 1));
				addFieldValue(fieldValues, $ChronoField::YEAR, prolepticYear($($nc(chronoDate)->getEra()), yoe));
			} else {
				if (resolverStyle == $ResolverStyle::STRICT) {
					fieldValues->put($ChronoField::YEAR_OF_ERA, yoeLong);
				} else {
					$var($List, eras, this->eras());
					if ($nc(eras)->isEmpty()) {
						addFieldValue(fieldValues, $ChronoField::YEAR, yoe);
					} else {
						$var($Era, eraObj, $cast($Era, eras->get(eras->size() - 1)));
						addFieldValue(fieldValues, $ChronoField::YEAR, prolepticYear(eraObj, yoe));
					}
				}
			}
		}
	} else {
		if (fieldValues->containsKey($ChronoField::ERA)) {
			$nc($(range($ChronoField::ERA)))->checkValidValue($nc(($cast($Long, $(fieldValues->get($ChronoField::ERA)))))->longValue(), $ChronoField::ERA);
		}
	}
	return nullptr;
}

$ChronoLocalDate* AbstractChronology::resolveYMD($Map* fieldValues, $ResolverStyle* resolverStyle) {
	$useLocalCurrentObjectStackCache();
	$init($ChronoField);
	int32_t y = $nc($(range($ChronoField::YEAR)))->checkValidIntValue($nc(($cast($Long, $($nc(fieldValues)->remove($ChronoField::YEAR)))))->longValue(), $ChronoField::YEAR);
	$init($ResolverStyle);
	if (resolverStyle == $ResolverStyle::LENIENT) {
		int64_t months = $Math::subtractExact($nc(($cast($Long, $($nc(fieldValues)->remove($ChronoField::MONTH_OF_YEAR)))))->longValue(), (int64_t)1);
		int64_t days = $Math::subtractExact($nc(($cast($Long, $($nc(fieldValues)->remove($ChronoField::DAY_OF_MONTH)))))->longValue(), (int64_t)1);
		$init($ChronoUnit);
		return $nc($($nc($(date(y, 1, 1)))->plus(months, $ChronoUnit::MONTHS)))->plus(days, $ChronoUnit::DAYS);
	}
	int32_t moy = $nc($(range($ChronoField::MONTH_OF_YEAR)))->checkValidIntValue($nc(($cast($Long, $($nc(fieldValues)->remove($ChronoField::MONTH_OF_YEAR)))))->longValue(), $ChronoField::MONTH_OF_YEAR);
	$var($ValueRange, domRange, range($ChronoField::DAY_OF_MONTH));
	int32_t dom = $nc(domRange)->checkValidIntValue($nc(($cast($Long, $($nc(fieldValues)->remove($ChronoField::DAY_OF_MONTH)))))->longValue(), $ChronoField::DAY_OF_MONTH);
	if (resolverStyle == $ResolverStyle::SMART) {
		try {
			return date(y, moy, dom);
		} catch ($DateTimeException& ex) {
			return $nc($(date(y, moy, 1)))->with($($TemporalAdjusters::lastDayOfMonth()));
		}
	}
	return date(y, moy, dom);
}

$ChronoLocalDate* AbstractChronology::resolveYD($Map* fieldValues, $ResolverStyle* resolverStyle) {
	$useLocalCurrentObjectStackCache();
	$init($ChronoField);
	int32_t y = $nc($(range($ChronoField::YEAR)))->checkValidIntValue($nc(($cast($Long, $($nc(fieldValues)->remove($ChronoField::YEAR)))))->longValue(), $ChronoField::YEAR);
	$init($ResolverStyle);
	if (resolverStyle == $ResolverStyle::LENIENT) {
		int64_t days = $Math::subtractExact($nc(($cast($Long, $($nc(fieldValues)->remove($ChronoField::DAY_OF_YEAR)))))->longValue(), (int64_t)1);
		$init($ChronoUnit);
		return $nc($(dateYearDay(y, 1)))->plus(days, $ChronoUnit::DAYS);
	}
	int32_t doy = $nc($(range($ChronoField::DAY_OF_YEAR)))->checkValidIntValue($nc(($cast($Long, $($nc(fieldValues)->remove($ChronoField::DAY_OF_YEAR)))))->longValue(), $ChronoField::DAY_OF_YEAR);
	return dateYearDay(y, doy);
}

$ChronoLocalDate* AbstractChronology::resolveYMAA($Map* fieldValues, $ResolverStyle* resolverStyle) {
	$useLocalCurrentObjectStackCache();
	$init($ChronoField);
	int32_t y = $nc($(range($ChronoField::YEAR)))->checkValidIntValue($nc(($cast($Long, $($nc(fieldValues)->remove($ChronoField::YEAR)))))->longValue(), $ChronoField::YEAR);
	$init($ResolverStyle);
	if (resolverStyle == $ResolverStyle::LENIENT) {
		int64_t months = $Math::subtractExact($nc(($cast($Long, $($nc(fieldValues)->remove($ChronoField::MONTH_OF_YEAR)))))->longValue(), (int64_t)1);
		int64_t weeks = $Math::subtractExact($nc(($cast($Long, $($nc(fieldValues)->remove($ChronoField::ALIGNED_WEEK_OF_MONTH)))))->longValue(), (int64_t)1);
		int64_t days = $Math::subtractExact($nc(($cast($Long, $($nc(fieldValues)->remove($ChronoField::ALIGNED_DAY_OF_WEEK_IN_MONTH)))))->longValue(), (int64_t)1);
		$init($ChronoUnit);
		return $nc($($nc($($nc($(this->date(y, 1, 1)))->plus(months, $ChronoUnit::MONTHS)))->plus(weeks, $ChronoUnit::WEEKS)))->plus(days, $ChronoUnit::DAYS);
	}
	int32_t moy = $nc($(range($ChronoField::MONTH_OF_YEAR)))->checkValidIntValue($nc(($cast($Long, $($nc(fieldValues)->remove($ChronoField::MONTH_OF_YEAR)))))->longValue(), $ChronoField::MONTH_OF_YEAR);
	int32_t aw = $nc($(range($ChronoField::ALIGNED_WEEK_OF_MONTH)))->checkValidIntValue($nc(($cast($Long, $($nc(fieldValues)->remove($ChronoField::ALIGNED_WEEK_OF_MONTH)))))->longValue(), $ChronoField::ALIGNED_WEEK_OF_MONTH);
	int32_t ad = $nc($(range($ChronoField::ALIGNED_DAY_OF_WEEK_IN_MONTH)))->checkValidIntValue($nc(($cast($Long, $($nc(fieldValues)->remove($ChronoField::ALIGNED_DAY_OF_WEEK_IN_MONTH)))))->longValue(), $ChronoField::ALIGNED_DAY_OF_WEEK_IN_MONTH);
	$init($ChronoUnit);
	$var($ChronoLocalDate, date, $nc($(this->date(y, moy, 1)))->plus((aw - 1) * 7 + (ad - 1), $ChronoUnit::DAYS));
	if (resolverStyle == $ResolverStyle::STRICT && $nc(date)->get($ChronoField::MONTH_OF_YEAR) != moy) {
		$throwNew($DateTimeException, "Strict mode rejected resolved date as it is in a different month"_s);
	}
	return date;
}

$ChronoLocalDate* AbstractChronology::resolveYMAD($Map* fieldValues, $ResolverStyle* resolverStyle) {
	$useLocalCurrentObjectStackCache();
	$init($ChronoField);
	int32_t y = $nc($(range($ChronoField::YEAR)))->checkValidIntValue($nc(($cast($Long, $($nc(fieldValues)->remove($ChronoField::YEAR)))))->longValue(), $ChronoField::YEAR);
	$init($ResolverStyle);
	if (resolverStyle == $ResolverStyle::LENIENT) {
		int64_t months = $Math::subtractExact($nc(($cast($Long, $($nc(fieldValues)->remove($ChronoField::MONTH_OF_YEAR)))))->longValue(), (int64_t)1);
		int64_t weeks = $Math::subtractExact($nc(($cast($Long, $($nc(fieldValues)->remove($ChronoField::ALIGNED_WEEK_OF_MONTH)))))->longValue(), (int64_t)1);
		int64_t dow = $Math::subtractExact($nc(($cast($Long, $($nc(fieldValues)->remove($ChronoField::DAY_OF_WEEK)))))->longValue(), (int64_t)1);
		return resolveAligned($(this->date(y, 1, 1)), months, weeks, dow);
	}
	int32_t moy = $nc($(range($ChronoField::MONTH_OF_YEAR)))->checkValidIntValue($nc(($cast($Long, $($nc(fieldValues)->remove($ChronoField::MONTH_OF_YEAR)))))->longValue(), $ChronoField::MONTH_OF_YEAR);
	int32_t aw = $nc($(range($ChronoField::ALIGNED_WEEK_OF_MONTH)))->checkValidIntValue($nc(($cast($Long, $($nc(fieldValues)->remove($ChronoField::ALIGNED_WEEK_OF_MONTH)))))->longValue(), $ChronoField::ALIGNED_WEEK_OF_MONTH);
	int32_t dow = $nc($(range($ChronoField::DAY_OF_WEEK)))->checkValidIntValue($nc(($cast($Long, $($nc(fieldValues)->remove($ChronoField::DAY_OF_WEEK)))))->longValue(), $ChronoField::DAY_OF_WEEK);
	$init($ChronoUnit);
	$var($ChronoLocalDate, date, $nc($($nc($(this->date(y, moy, 1)))->plus((aw - 1) * 7, $ChronoUnit::DAYS)))->with($($TemporalAdjusters::nextOrSame($($DayOfWeek::of(dow))))));
	if (resolverStyle == $ResolverStyle::STRICT && $nc(date)->get($ChronoField::MONTH_OF_YEAR) != moy) {
		$throwNew($DateTimeException, "Strict mode rejected resolved date as it is in a different month"_s);
	}
	return date;
}

$ChronoLocalDate* AbstractChronology::resolveYAA($Map* fieldValues, $ResolverStyle* resolverStyle) {
	$useLocalCurrentObjectStackCache();
	$init($ChronoField);
	int32_t y = $nc($(range($ChronoField::YEAR)))->checkValidIntValue($nc(($cast($Long, $($nc(fieldValues)->remove($ChronoField::YEAR)))))->longValue(), $ChronoField::YEAR);
	$init($ResolverStyle);
	if (resolverStyle == $ResolverStyle::LENIENT) {
		int64_t weeks = $Math::subtractExact($nc(($cast($Long, $($nc(fieldValues)->remove($ChronoField::ALIGNED_WEEK_OF_YEAR)))))->longValue(), (int64_t)1);
		int64_t days = $Math::subtractExact($nc(($cast($Long, $($nc(fieldValues)->remove($ChronoField::ALIGNED_DAY_OF_WEEK_IN_YEAR)))))->longValue(), (int64_t)1);
		$init($ChronoUnit);
		return $nc($($nc($(dateYearDay(y, 1)))->plus(weeks, $ChronoUnit::WEEKS)))->plus(days, $ChronoUnit::DAYS);
	}
	int32_t aw = $nc($(range($ChronoField::ALIGNED_WEEK_OF_YEAR)))->checkValidIntValue($nc(($cast($Long, $($nc(fieldValues)->remove($ChronoField::ALIGNED_WEEK_OF_YEAR)))))->longValue(), $ChronoField::ALIGNED_WEEK_OF_YEAR);
	int32_t ad = $nc($(range($ChronoField::ALIGNED_DAY_OF_WEEK_IN_YEAR)))->checkValidIntValue($nc(($cast($Long, $($nc(fieldValues)->remove($ChronoField::ALIGNED_DAY_OF_WEEK_IN_YEAR)))))->longValue(), $ChronoField::ALIGNED_DAY_OF_WEEK_IN_YEAR);
	$init($ChronoUnit);
	$var($ChronoLocalDate, date, $nc($(dateYearDay(y, 1)))->plus((aw - 1) * 7 + (ad - 1), $ChronoUnit::DAYS));
	if (resolverStyle == $ResolverStyle::STRICT && $nc(date)->get($ChronoField::YEAR) != y) {
		$throwNew($DateTimeException, "Strict mode rejected resolved date as it is in a different year"_s);
	}
	return date;
}

$ChronoLocalDate* AbstractChronology::resolveYAD($Map* fieldValues, $ResolverStyle* resolverStyle) {
	$useLocalCurrentObjectStackCache();
	$init($ChronoField);
	int32_t y = $nc($(range($ChronoField::YEAR)))->checkValidIntValue($nc(($cast($Long, $($nc(fieldValues)->remove($ChronoField::YEAR)))))->longValue(), $ChronoField::YEAR);
	$init($ResolverStyle);
	if (resolverStyle == $ResolverStyle::LENIENT) {
		int64_t weeks = $Math::subtractExact($nc(($cast($Long, $($nc(fieldValues)->remove($ChronoField::ALIGNED_WEEK_OF_YEAR)))))->longValue(), (int64_t)1);
		int64_t dow = $Math::subtractExact($nc(($cast($Long, $($nc(fieldValues)->remove($ChronoField::DAY_OF_WEEK)))))->longValue(), (int64_t)1);
		return resolveAligned($(dateYearDay(y, 1)), 0, weeks, dow);
	}
	int32_t aw = $nc($(range($ChronoField::ALIGNED_WEEK_OF_YEAR)))->checkValidIntValue($nc(($cast($Long, $($nc(fieldValues)->remove($ChronoField::ALIGNED_WEEK_OF_YEAR)))))->longValue(), $ChronoField::ALIGNED_WEEK_OF_YEAR);
	int32_t dow = $nc($(range($ChronoField::DAY_OF_WEEK)))->checkValidIntValue($nc(($cast($Long, $($nc(fieldValues)->remove($ChronoField::DAY_OF_WEEK)))))->longValue(), $ChronoField::DAY_OF_WEEK);
	$init($ChronoUnit);
	$var($ChronoLocalDate, date, $nc($($nc($(dateYearDay(y, 1)))->plus((aw - 1) * 7, $ChronoUnit::DAYS)))->with($($TemporalAdjusters::nextOrSame($($DayOfWeek::of(dow))))));
	if (resolverStyle == $ResolverStyle::STRICT && $nc(date)->get($ChronoField::YEAR) != y) {
		$throwNew($DateTimeException, "Strict mode rejected resolved date as it is in a different year"_s);
	}
	return date;
}

$ChronoLocalDate* AbstractChronology::resolveAligned($ChronoLocalDate* base, int64_t months, int64_t weeks, int64_t dow) {
	$useLocalCurrentObjectStackCache();
	$init($ChronoUnit);
	$var($ChronoLocalDate, date, $nc($($nc(base)->plus(months, $ChronoUnit::MONTHS)))->plus(weeks, $ChronoUnit::WEEKS));
	if (dow > 7) {
		$assign(date, $nc(date)->plus((dow - 1) / 7, $ChronoUnit::WEEKS));
		dow = ((dow - 1) % 7) + 1;
	} else if (dow < 1) {
		$assign(date, $nc(date)->plus($Math::subtractExact(dow, (int64_t)7) / 7, $ChronoUnit::WEEKS));
		dow = ((dow + 6) % 7) + 1;
	}
	return $nc(date)->with($($TemporalAdjusters::nextOrSame($($DayOfWeek::of((int32_t)dow)))));
}

void AbstractChronology::addFieldValue($Map* fieldValues, $ChronoField* field, int64_t value) {
	$useLocalCurrentObjectStackCache();
	$var($Long, old, $cast($Long, $nc(fieldValues)->get(field)));
	if (old != nullptr && old->longValue() != value) {
		$throwNew($DateTimeException, $$str({"Conflict found: "_s, field, " "_s, old, " differs from "_s, field, " "_s, $$str(value)}));
	}
	fieldValues->put(field, $($Long::valueOf(value)));
}

int32_t AbstractChronology::compareTo($Chronology* other) {
	$useLocalCurrentObjectStackCache();
	return $nc($(getId()))->compareTo($($nc(other)->getId()));
}

bool AbstractChronology::equals(Object$* obj) {
	if ($equals(this, obj)) {
		return true;
	}
	if ($instanceOf(AbstractChronology, obj)) {
		return compareTo($cast(AbstractChronology, obj)) == 0;
	}
	return false;
}

int32_t AbstractChronology::hashCode() {
	int32_t var$0 = $of($of(this)->getClass())->hashCode();
	return var$0 ^ $nc($(getId()))->hashCode();
}

$String* AbstractChronology::toString() {
	return getId();
}

$Object* AbstractChronology::writeReplace() {
	return $of($new($Ser, $Ser::CHRONO_TYPE, $cast($Serializable, this)));
}

void AbstractChronology::readObject($ObjectInputStream* s) {
	$throwNew($InvalidObjectException, "Deserialization via serialization delegate"_s);
}

void AbstractChronology::writeExternal($DataOutput* out) {
	$nc(out)->writeUTF($(getId()));
}

$Chronology* AbstractChronology::readExternal($DataInput* in) {
	$init(AbstractChronology);
	$var($String, id, $nc(in)->readUTF());
	return $Chronology::of(id);
}

int32_t AbstractChronology::compareTo(Object$* other) {
	return this->compareTo($cast($Chronology, other));
}

void clinit$AbstractChronology($Class* class$) {
	$assignStatic(AbstractChronology::CHRONOS_BY_ID, $new($ConcurrentHashMap));
	$assignStatic(AbstractChronology::CHRONOS_BY_TYPE, $new($ConcurrentHashMap));
}

AbstractChronology::AbstractChronology() {
}

$Class* AbstractChronology::load$($String* name, bool initialize) {
	$loadClass(AbstractChronology, name, initialize, &_AbstractChronology_ClassInfo_, clinit$AbstractChronology, allocate$AbstractChronology);
	return class$;
}

$Class* AbstractChronology::class$ = nullptr;

		} // chrono
	} // time
} // java