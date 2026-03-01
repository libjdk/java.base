#include <java/text/DateFormatSymbols.h>

#include <java/io/ObjectOutputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/InternalError.h>
#include <java/lang/ref/SoftReference.h>
#include <java/text/spi/DateFormatSymbolsProvider.h>
#include <java/util/Arrays.h>
#include <java/util/Locale$Category.h>
#include <java/util/Locale.h>
#include <java/util/Objects.h>
#include <java/util/ResourceBundle.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/concurrent/ConcurrentMap.h>
#include <sun/util/locale/provider/CalendarDataUtility.h>
#include <sun/util/locale/provider/LocaleProviderAdapter.h>
#include <sun/util/locale/provider/LocaleServiceProviderPool.h>
#include <sun/util/locale/provider/ResourceBundleBasedAdapter.h>
#include <sun/util/locale/provider/TimeZoneNameUtility.h>
#include <sun/util/resources/LocaleData.h>
#include <jcpp.h>

#undef FORMAT
#undef ID
#undef PATTERN_AM_PM
#undef PATTERN_DAY_OF_MONTH
#undef PATTERN_DAY_OF_WEEK
#undef PATTERN_DAY_OF_WEEK_IN_MONTH
#undef PATTERN_DAY_OF_YEAR
#undef PATTERN_ERA
#undef PATTERN_HOUR0
#undef PATTERN_HOUR1
#undef PATTERN_HOUR_OF_DAY0
#undef PATTERN_HOUR_OF_DAY1
#undef PATTERN_ISO_DAY_OF_WEEK
#undef PATTERN_ISO_ZONE
#undef PATTERN_MILLISECOND
#undef PATTERN_MINUTE
#undef PATTERN_MONTH
#undef PATTERN_MONTH_STANDALONE
#undef PATTERN_SECOND
#undef PATTERN_WEEK_OF_MONTH
#undef PATTERN_WEEK_OF_YEAR
#undef PATTERN_WEEK_YEAR
#undef PATTERN_YEAR
#undef PATTERN_ZONE_NAME
#undef PATTERN_ZONE_VALUE

using $LocaleArray = $Array<::java::util::Locale>;
using $StringArray2 = $Array<::java::lang::String, 2>;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $SoftReference = ::java::lang::ref::SoftReference;
using $DateFormatSymbolsProvider = ::java::text::spi::DateFormatSymbolsProvider;
using $Arrays = ::java::util::Arrays;
using $Locale = ::java::util::Locale;
using $Locale$Category = ::java::util::Locale$Category;
using $Objects = ::java::util::Objects;
using $ResourceBundle = ::java::util::ResourceBundle;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $ConcurrentMap = ::java::util::concurrent::ConcurrentMap;
using $CalendarDataUtility = ::sun::util::locale::provider::CalendarDataUtility;
using $LocaleProviderAdapter = ::sun::util::locale::provider::LocaleProviderAdapter;
using $LocaleServiceProviderPool = ::sun::util::locale::provider::LocaleServiceProviderPool;
using $ResourceBundleBasedAdapter = ::sun::util::locale::provider::ResourceBundleBasedAdapter;
using $TimeZoneNameUtility = ::sun::util::locale::provider::TimeZoneNameUtility;
using $LocaleData = ::sun::util::resources::LocaleData;

namespace java {
	namespace text {

$FieldInfo _DateFormatSymbols_FieldInfo_[] = {
	{"eras", "[Ljava/lang/String;", nullptr, 0, $field(DateFormatSymbols, eras)},
	{"months", "[Ljava/lang/String;", nullptr, 0, $field(DateFormatSymbols, months)},
	{"shortMonths", "[Ljava/lang/String;", nullptr, 0, $field(DateFormatSymbols, shortMonths)},
	{"weekdays", "[Ljava/lang/String;", nullptr, 0, $field(DateFormatSymbols, weekdays)},
	{"shortWeekdays", "[Ljava/lang/String;", nullptr, 0, $field(DateFormatSymbols, shortWeekdays)},
	{"ampms", "[Ljava/lang/String;", nullptr, 0, $field(DateFormatSymbols, ampms)},
	{"zoneStrings", "[[Ljava/lang/String;", nullptr, 0, $field(DateFormatSymbols, zoneStrings)},
	{"isZoneStringsSet", "Z", nullptr, $TRANSIENT, $field(DateFormatSymbols, isZoneStringsSet)},
	{"patternChars", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(DateFormatSymbols, patternChars)},
	{"PATTERN_ERA", "I", nullptr, $STATIC | $FINAL, $constField(DateFormatSymbols, PATTERN_ERA)},
	{"PATTERN_YEAR", "I", nullptr, $STATIC | $FINAL, $constField(DateFormatSymbols, PATTERN_YEAR)},
	{"PATTERN_MONTH", "I", nullptr, $STATIC | $FINAL, $constField(DateFormatSymbols, PATTERN_MONTH)},
	{"PATTERN_DAY_OF_MONTH", "I", nullptr, $STATIC | $FINAL, $constField(DateFormatSymbols, PATTERN_DAY_OF_MONTH)},
	{"PATTERN_HOUR_OF_DAY1", "I", nullptr, $STATIC | $FINAL, $constField(DateFormatSymbols, PATTERN_HOUR_OF_DAY1)},
	{"PATTERN_HOUR_OF_DAY0", "I", nullptr, $STATIC | $FINAL, $constField(DateFormatSymbols, PATTERN_HOUR_OF_DAY0)},
	{"PATTERN_MINUTE", "I", nullptr, $STATIC | $FINAL, $constField(DateFormatSymbols, PATTERN_MINUTE)},
	{"PATTERN_SECOND", "I", nullptr, $STATIC | $FINAL, $constField(DateFormatSymbols, PATTERN_SECOND)},
	{"PATTERN_MILLISECOND", "I", nullptr, $STATIC | $FINAL, $constField(DateFormatSymbols, PATTERN_MILLISECOND)},
	{"PATTERN_DAY_OF_WEEK", "I", nullptr, $STATIC | $FINAL, $constField(DateFormatSymbols, PATTERN_DAY_OF_WEEK)},
	{"PATTERN_DAY_OF_YEAR", "I", nullptr, $STATIC | $FINAL, $constField(DateFormatSymbols, PATTERN_DAY_OF_YEAR)},
	{"PATTERN_DAY_OF_WEEK_IN_MONTH", "I", nullptr, $STATIC | $FINAL, $constField(DateFormatSymbols, PATTERN_DAY_OF_WEEK_IN_MONTH)},
	{"PATTERN_WEEK_OF_YEAR", "I", nullptr, $STATIC | $FINAL, $constField(DateFormatSymbols, PATTERN_WEEK_OF_YEAR)},
	{"PATTERN_WEEK_OF_MONTH", "I", nullptr, $STATIC | $FINAL, $constField(DateFormatSymbols, PATTERN_WEEK_OF_MONTH)},
	{"PATTERN_AM_PM", "I", nullptr, $STATIC | $FINAL, $constField(DateFormatSymbols, PATTERN_AM_PM)},
	{"PATTERN_HOUR1", "I", nullptr, $STATIC | $FINAL, $constField(DateFormatSymbols, PATTERN_HOUR1)},
	{"PATTERN_HOUR0", "I", nullptr, $STATIC | $FINAL, $constField(DateFormatSymbols, PATTERN_HOUR0)},
	{"PATTERN_ZONE_NAME", "I", nullptr, $STATIC | $FINAL, $constField(DateFormatSymbols, PATTERN_ZONE_NAME)},
	{"PATTERN_ZONE_VALUE", "I", nullptr, $STATIC | $FINAL, $constField(DateFormatSymbols, PATTERN_ZONE_VALUE)},
	{"PATTERN_WEEK_YEAR", "I", nullptr, $STATIC | $FINAL, $constField(DateFormatSymbols, PATTERN_WEEK_YEAR)},
	{"PATTERN_ISO_DAY_OF_WEEK", "I", nullptr, $STATIC | $FINAL, $constField(DateFormatSymbols, PATTERN_ISO_DAY_OF_WEEK)},
	{"PATTERN_ISO_ZONE", "I", nullptr, $STATIC | $FINAL, $constField(DateFormatSymbols, PATTERN_ISO_ZONE)},
	{"PATTERN_MONTH_STANDALONE", "I", nullptr, $STATIC | $FINAL, $constField(DateFormatSymbols, PATTERN_MONTH_STANDALONE)},
	{"localPatternChars", "Ljava/lang/String;", nullptr, 0, $field(DateFormatSymbols, localPatternChars)},
	{"locale", "Ljava/util/Locale;", nullptr, 0, $field(DateFormatSymbols, locale)},
	{"serialVersionUID", "J", nullptr, $STATIC | $FINAL, $constField(DateFormatSymbols, serialVersionUID)},
	{"millisPerHour", "I", nullptr, $STATIC | $FINAL, $constField(DateFormatSymbols, millisPerHour)},
	{"cachedInstances", "Ljava/util/concurrent/ConcurrentMap;", "Ljava/util/concurrent/ConcurrentMap<Ljava/util/Locale;Ljava/lang/ref/SoftReference<Ljava/text/DateFormatSymbols;>;>;", $PRIVATE | $STATIC | $FINAL, $staticField(DateFormatSymbols, cachedInstances)},
	{"lastZoneIndex", "I", nullptr, $PRIVATE | $TRANSIENT, $field(DateFormatSymbols, lastZoneIndex)},
	{"cachedHashCode", "I", nullptr, $VOLATILE | $TRANSIENT, $field(DateFormatSymbols, cachedHashCode)},
	{}
};

$MethodInfo _DateFormatSymbols_MethodInfo_[] = {
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "()V", nullptr, $PUBLIC, $method(DateFormatSymbols, init$, void)},
	{"<init>", "(Ljava/util/Locale;)V", nullptr, $PUBLIC, $method(DateFormatSymbols, init$, void, $Locale*)},
	{"<init>", "(Z)V", nullptr, $PRIVATE, $method(DateFormatSymbols, init$, void, bool)},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(DateFormatSymbols, clone, $Object*)},
	{"copyMembers", "(Ljava/text/DateFormatSymbols;Ljava/text/DateFormatSymbols;)V", nullptr, $PRIVATE, $method(DateFormatSymbols, copyMembers, void, DateFormatSymbols*, DateFormatSymbols*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(DateFormatSymbols, equals, bool, Object$*)},
	{"getAmPmStrings", "()[Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(DateFormatSymbols, getAmPmStrings, $StringArray*)},
	{"getAvailableLocales", "()[Ljava/util/Locale;", nullptr, $PUBLIC | $STATIC, $staticMethod(DateFormatSymbols, getAvailableLocales, $LocaleArray*)},
	{"getEras", "()[Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(DateFormatSymbols, getEras, $StringArray*)},
	{"getInstance", "()Ljava/text/DateFormatSymbols;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticMethod(DateFormatSymbols, getInstance, DateFormatSymbols*)},
	{"getInstance", "(Ljava/util/Locale;)Ljava/text/DateFormatSymbols;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticMethod(DateFormatSymbols, getInstance, DateFormatSymbols*, $Locale*)},
	{"getInstanceRef", "(Ljava/util/Locale;)Ljava/text/DateFormatSymbols;", nullptr, $STATIC | $FINAL, $staticMethod(DateFormatSymbols, getInstanceRef, DateFormatSymbols*, $Locale*)},
	{"getLocalPatternChars", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(DateFormatSymbols, getLocalPatternChars, $String*)},
	{"getMonths", "()[Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(DateFormatSymbols, getMonths, $StringArray*)},
	{"getProviderInstance", "(Ljava/util/Locale;)Ljava/text/DateFormatSymbols;", nullptr, $PRIVATE | $STATIC, $staticMethod(DateFormatSymbols, getProviderInstance, DateFormatSymbols*, $Locale*)},
	{"getShortMonths", "()[Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(DateFormatSymbols, getShortMonths, $StringArray*)},
	{"getShortWeekdays", "()[Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(DateFormatSymbols, getShortWeekdays, $StringArray*)},
	{"getWeekdays", "()[Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(DateFormatSymbols, getWeekdays, $StringArray*)},
	{"getZoneIndex", "(Ljava/lang/String;)I", nullptr, $FINAL, $method(DateFormatSymbols, getZoneIndex, int32_t, $String*)},
	{"getZoneStrings", "()[[Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(DateFormatSymbols, getZoneStrings, $StringArray2*)},
	{"getZoneStringsImpl", "(Z)[[Ljava/lang/String;", nullptr, $PRIVATE, $method(DateFormatSymbols, getZoneStringsImpl, $StringArray2*, bool)},
	{"getZoneStringsWrapper", "()[[Ljava/lang/String;", nullptr, $FINAL, $method(DateFormatSymbols, getZoneStringsWrapper, $StringArray2*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(DateFormatSymbols, hashCode, int32_t)},
	{"initializeData", "(Ljava/util/Locale;)V", nullptr, $PRIVATE, $method(DateFormatSymbols, initializeData, void, $Locale*)},
	{"isSubclassObject", "()Z", nullptr, $PRIVATE, $method(DateFormatSymbols, isSubclassObject, bool)},
	{"setAmPmStrings", "([Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(DateFormatSymbols, setAmPmStrings, void, $StringArray*)},
	{"setEras", "([Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(DateFormatSymbols, setEras, void, $StringArray*)},
	{"setLocalPatternChars", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(DateFormatSymbols, setLocalPatternChars, void, $String*)},
	{"setMonths", "([Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(DateFormatSymbols, setMonths, void, $StringArray*)},
	{"setShortMonths", "([Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(DateFormatSymbols, setShortMonths, void, $StringArray*)},
	{"setShortWeekdays", "([Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(DateFormatSymbols, setShortWeekdays, void, $StringArray*)},
	{"setWeekdays", "([Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(DateFormatSymbols, setWeekdays, void, $StringArray*)},
	{"setZoneStrings", "([[Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(DateFormatSymbols, setZoneStrings, void, $StringArray2*)},
	{"toOneBasedArray", "([Ljava/lang/String;)[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(DateFormatSymbols, toOneBasedArray, $StringArray*, $StringArray*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE, $method(DateFormatSymbols, writeObject, void, $ObjectOutputStream*), "java.io.IOException"},
	{}
};

$ClassInfo _DateFormatSymbols_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.text.DateFormatSymbols",
	"java.lang.Object",
	"java.io.Serializable,java.lang.Cloneable",
	_DateFormatSymbols_FieldInfo_,
	_DateFormatSymbols_MethodInfo_
};

$Object* allocate$DateFormatSymbols($Class* clazz) {
	return $of($alloc(DateFormatSymbols));
}

$String* DateFormatSymbols::toString() {
	 return this->$Serializable::toString();
}

void DateFormatSymbols::finalize() {
	this->$Serializable::finalize();
}

$String* DateFormatSymbols::patternChars = nullptr;
$ConcurrentMap* DateFormatSymbols::cachedInstances = nullptr;

void DateFormatSymbols::init$() {
	$set(this, eras, nullptr);
	$set(this, months, nullptr);
	$set(this, shortMonths, nullptr);
	$set(this, weekdays, nullptr);
	$set(this, shortWeekdays, nullptr);
	$set(this, ampms, nullptr);
	$set(this, zoneStrings, nullptr);
	this->isZoneStringsSet = false;
	$set(this, localPatternChars, nullptr);
	$set(this, locale, nullptr);
	$init($Locale$Category);
	initializeData($($Locale::getDefault($Locale$Category::FORMAT)));
}

void DateFormatSymbols::init$($Locale* locale) {
	$set(this, eras, nullptr);
	$set(this, months, nullptr);
	$set(this, shortMonths, nullptr);
	$set(this, weekdays, nullptr);
	$set(this, shortWeekdays, nullptr);
	$set(this, ampms, nullptr);
	$set(this, zoneStrings, nullptr);
	this->isZoneStringsSet = false;
	$set(this, localPatternChars, nullptr);
	$set(this, locale, nullptr);
	initializeData(locale);
}

void DateFormatSymbols::init$(bool flag) {
	$set(this, eras, nullptr);
	$set(this, months, nullptr);
	$set(this, shortMonths, nullptr);
	$set(this, weekdays, nullptr);
	$set(this, shortWeekdays, nullptr);
	$set(this, ampms, nullptr);
	$set(this, zoneStrings, nullptr);
	this->isZoneStringsSet = false;
	$set(this, localPatternChars, nullptr);
	$set(this, locale, nullptr);
}

$LocaleArray* DateFormatSymbols::getAvailableLocales() {
	$init(DateFormatSymbols);
	$load($DateFormatSymbolsProvider);
	$var($LocaleServiceProviderPool, pool, $LocaleServiceProviderPool::getPool($DateFormatSymbolsProvider::class$));
	return $nc(pool)->getAvailableLocales();
}

DateFormatSymbols* DateFormatSymbols::getInstance() {
	$init(DateFormatSymbols);
	$init($Locale$Category);
	return getInstance($($Locale::getDefault($Locale$Category::FORMAT)));
}

DateFormatSymbols* DateFormatSymbols::getInstance($Locale* locale) {
	$init(DateFormatSymbols);
	$var(DateFormatSymbols, dfs, getProviderInstance(locale));
	if (dfs != nullptr) {
		return dfs;
	}
	$throwNew($RuntimeException, "DateFormatSymbols instance creation failed."_s);
}

DateFormatSymbols* DateFormatSymbols::getInstanceRef($Locale* locale) {
	$init(DateFormatSymbols);
	$var(DateFormatSymbols, dfs, getProviderInstance(locale));
	if (dfs != nullptr) {
		return dfs;
	}
	$throwNew($RuntimeException, "DateFormatSymbols instance creation failed."_s);
}

DateFormatSymbols* DateFormatSymbols::getProviderInstance($Locale* locale) {
	$init(DateFormatSymbols);
	$useLocalCurrentObjectStackCache();
	$load($DateFormatSymbolsProvider);
	$var($LocaleProviderAdapter, adapter, $LocaleProviderAdapter::getAdapter($DateFormatSymbolsProvider::class$, locale));
	$var($DateFormatSymbolsProvider, provider, $nc(adapter)->getDateFormatSymbolsProvider());
	$var(DateFormatSymbols, dfsyms, $nc(provider)->getInstance(locale));
	if (dfsyms == nullptr) {
		$assign(provider, $nc($($LocaleProviderAdapter::forJRE()))->getDateFormatSymbolsProvider());
		$assign(dfsyms, $nc(provider)->getInstance(locale));
	}
	return dfsyms;
}

$StringArray* DateFormatSymbols::getEras() {
	return $fcast($StringArray, $Arrays::copyOf(this->eras, $nc(this->eras)->length));
}

void DateFormatSymbols::setEras($StringArray* newEras) {
	$set(this, eras, $fcast($StringArray, $Arrays::copyOf(newEras, $nc(newEras)->length)));
	this->cachedHashCode = 0;
}

$StringArray* DateFormatSymbols::getMonths() {
	return $fcast($StringArray, $Arrays::copyOf(this->months, $nc(this->months)->length));
}

void DateFormatSymbols::setMonths($StringArray* newMonths) {
	$set(this, months, $fcast($StringArray, $Arrays::copyOf(newMonths, $nc(newMonths)->length)));
	this->cachedHashCode = 0;
}

$StringArray* DateFormatSymbols::getShortMonths() {
	return $fcast($StringArray, $Arrays::copyOf(this->shortMonths, $nc(this->shortMonths)->length));
}

void DateFormatSymbols::setShortMonths($StringArray* newShortMonths) {
	$set(this, shortMonths, $fcast($StringArray, $Arrays::copyOf(newShortMonths, $nc(newShortMonths)->length)));
	this->cachedHashCode = 0;
}

$StringArray* DateFormatSymbols::getWeekdays() {
	return $fcast($StringArray, $Arrays::copyOf(this->weekdays, $nc(this->weekdays)->length));
}

void DateFormatSymbols::setWeekdays($StringArray* newWeekdays) {
	$set(this, weekdays, $fcast($StringArray, $Arrays::copyOf(newWeekdays, $nc(newWeekdays)->length)));
	this->cachedHashCode = 0;
}

$StringArray* DateFormatSymbols::getShortWeekdays() {
	return $fcast($StringArray, $Arrays::copyOf(this->shortWeekdays, $nc(this->shortWeekdays)->length));
}

void DateFormatSymbols::setShortWeekdays($StringArray* newShortWeekdays) {
	$set(this, shortWeekdays, $fcast($StringArray, $Arrays::copyOf(newShortWeekdays, $nc(newShortWeekdays)->length)));
	this->cachedHashCode = 0;
}

$StringArray* DateFormatSymbols::getAmPmStrings() {
	return $fcast($StringArray, $Arrays::copyOf(this->ampms, $nc(this->ampms)->length));
}

void DateFormatSymbols::setAmPmStrings($StringArray* newAmpms) {
	$set(this, ampms, $fcast($StringArray, $Arrays::copyOf(newAmpms, $nc(newAmpms)->length)));
	this->cachedHashCode = 0;
}

$StringArray2* DateFormatSymbols::getZoneStrings() {
	return getZoneStringsImpl(true);
}

void DateFormatSymbols::setZoneStrings($StringArray2* newZoneStrings) {
	$useLocalCurrentObjectStackCache();
	$var($StringArray2, aCopy, $new($StringArray2, $nc(newZoneStrings)->length));
	for (int32_t i = 0; i < newZoneStrings->length; ++i) {
		int32_t len = $nc(newZoneStrings->get(i))->length;
		if (len < 5) {
			$throwNew($IllegalArgumentException);
		}
		aCopy->set(i, $fcast($StringArray, $($Arrays::copyOf(newZoneStrings->get(i), len))));
	}
	$set(this, zoneStrings, aCopy);
	this->isZoneStringsSet = true;
	this->cachedHashCode = 0;
}

$String* DateFormatSymbols::getLocalPatternChars() {
	return this->localPatternChars;
}

void DateFormatSymbols::setLocalPatternChars($String* newLocalPatternChars) {
	$set(this, localPatternChars, $nc(newLocalPatternChars)->toString());
	this->cachedHashCode = 0;
}

$Object* DateFormatSymbols::clone() {
	try {
		$var(DateFormatSymbols, other, $cast(DateFormatSymbols, $Serializable::clone()));
		copyMembers(this, other);
		return $of(other);
	} catch ($CloneNotSupportedException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

int32_t DateFormatSymbols::hashCode() {
	int32_t hashCode = this->cachedHashCode;
	if (hashCode == 0) {
		hashCode = 5;
		hashCode = 11 * hashCode + $Arrays::hashCode(this->eras);
		hashCode = 11 * hashCode + $Arrays::hashCode(this->months);
		hashCode = 11 * hashCode + $Arrays::hashCode(this->shortMonths);
		hashCode = 11 * hashCode + $Arrays::hashCode(this->weekdays);
		hashCode = 11 * hashCode + $Arrays::hashCode(this->shortWeekdays);
		hashCode = 11 * hashCode + $Arrays::hashCode(this->ampms);
		hashCode = 11 * hashCode + $Arrays::deepHashCode($(getZoneStringsWrapper()));
		hashCode = 11 * hashCode + $Objects::hashCode(this->localPatternChars);
		if (hashCode != 0) {
			this->cachedHashCode = hashCode;
		}
	}
	return hashCode;
}

bool DateFormatSymbols::equals(Object$* obj) {
	$useLocalCurrentObjectStackCache();
	if ($equals(this, obj)) {
		return true;
	}
	bool var$0 = obj == nullptr;
	if (!var$0) {
		var$0 = $of(this)->getClass() != $nc($of(obj))->getClass();
	}
	if (var$0) {
		return false;
	}
	$var(DateFormatSymbols, that, $cast(DateFormatSymbols, obj));
	bool var$7 = $Arrays::equals(this->eras, $nc(that)->eras);
	bool var$6 = var$7 && $Arrays::equals(this->months, $nc(that)->months);
	bool var$5 = var$6 && $Arrays::equals(this->shortMonths, $nc(that)->shortMonths);
	bool var$4 = var$5 && $Arrays::equals(this->weekdays, $nc(that)->weekdays);
	bool var$3 = var$4 && $Arrays::equals(this->shortWeekdays, $nc(that)->shortWeekdays);
	bool var$2 = var$3 && $Arrays::equals(this->ampms, $nc(that)->ampms);
	if (var$2) {
		$var($ObjectArray, var$8, getZoneStringsWrapper());
		var$2 = $Arrays::deepEquals(var$8, $($nc(that)->getZoneStringsWrapper()));
	}
	bool var$1 = var$2;
	return (var$1 && ((this->localPatternChars != nullptr && $nc(this->localPatternChars)->equals($nc(that)->localPatternChars)) || (this->localPatternChars == nullptr && $nc(that)->localPatternChars == nullptr)));
}

void DateFormatSymbols::initializeData($Locale* locale) {
	$useLocalCurrentObjectStackCache();
	$var($SoftReference, ref, $cast($SoftReference, $nc(DateFormatSymbols::cachedInstances)->get(locale)));
	$var(DateFormatSymbols, dfs, nullptr);
	if (ref == nullptr || ($assign(dfs, $cast(DateFormatSymbols, $nc(ref)->get()))) == nullptr) {
		if (ref != nullptr) {
			$nc(DateFormatSymbols::cachedInstances)->remove(locale, ref);
		}
		$assign(dfs, $new(DateFormatSymbols, false));
		$var($Locale, override$, $CalendarDataUtility::findRegionOverride(locale));
		$load($DateFormatSymbolsProvider);
		$var($LocaleProviderAdapter, adapter, $LocaleProviderAdapter::getAdapter($DateFormatSymbolsProvider::class$, override$));
		if (!($instanceOf($ResourceBundleBasedAdapter, adapter))) {
			$assign(adapter, $LocaleProviderAdapter::getResourceBundleBased());
		}
		$var($ResourceBundle, resource, $nc($($nc(($cast($ResourceBundleBasedAdapter, adapter)))->getLocaleData()))->getDateFormatData(override$));
		$set(dfs, locale, locale);
		if ($nc(resource)->containsKey("Eras"_s)) {
			$set(dfs, eras, resource->getStringArray("Eras"_s));
		} else if (resource->containsKey("long.Eras"_s)) {
			$set(dfs, eras, resource->getStringArray("long.Eras"_s));
		} else if (resource->containsKey("short.Eras"_s)) {
			$set(dfs, eras, resource->getStringArray("short.Eras"_s));
		}
		$set(dfs, months, $nc(resource)->getStringArray("MonthNames"_s));
		$set(dfs, shortMonths, resource->getStringArray("MonthAbbreviations"_s));
		$set(dfs, ampms, resource->getStringArray("AmPmMarkers"_s));
		if ($nc(dfs->ampms)->length > 2) {
			$set(dfs, ampms, $fcast($StringArray, $Arrays::copyOf(dfs->ampms, 2)));
		}
		$set(dfs, localPatternChars, resource->getString("DateTimePatternChars"_s));
		$set(dfs, weekdays, toOneBasedArray($(resource->getStringArray("DayNames"_s))));
		$set(dfs, shortWeekdays, toOneBasedArray($(resource->getStringArray("DayAbbreviations"_s))));
		$assign(ref, $new($SoftReference, dfs));
		$var($SoftReference, x, $cast($SoftReference, $nc(DateFormatSymbols::cachedInstances)->putIfAbsent(locale, ref)));
		if (x != nullptr) {
			$var(DateFormatSymbols, y, $cast(DateFormatSymbols, x->get()));
			if (y == nullptr) {
				$nc(DateFormatSymbols::cachedInstances)->replace(locale, x, ref);
			} else {
				$assign(ref, x);
				$assign(dfs, y);
			}
		}
	}
	copyMembers(dfs, this);
}

$StringArray* DateFormatSymbols::toOneBasedArray($StringArray* src) {
	$init(DateFormatSymbols);
	int32_t len = $nc(src)->length;
	$var($StringArray, dst, $new($StringArray, len + 1));
	dst->set(0, ""_s);
	for (int32_t i = 0; i < len; ++i) {
		dst->set(i + 1, src->get(i));
	}
	return dst;
}

int32_t DateFormatSymbols::getZoneIndex($String* ID) {
	$var($StringArray2, zoneStrings, getZoneStringsWrapper());
	if (this->lastZoneIndex < $nc(zoneStrings)->length && $nc(ID)->equals($nc(zoneStrings->get(this->lastZoneIndex))->get(0))) {
		return this->lastZoneIndex;
	}
	for (int32_t index = 0; index < $nc(zoneStrings)->length; ++index) {
		if ($nc(ID)->equals($nc(zoneStrings->get(index))->get(0))) {
			this->lastZoneIndex = index;
			return index;
		}
	}
	return -1;
}

$StringArray2* DateFormatSymbols::getZoneStringsWrapper() {
	if (isSubclassObject()) {
		return getZoneStrings();
	} else {
		return getZoneStringsImpl(false);
	}
}

$StringArray2* DateFormatSymbols::getZoneStringsImpl(bool needsCopy) {
	$useLocalCurrentObjectStackCache();
	if (this->zoneStrings == nullptr) {
		$set(this, zoneStrings, $TimeZoneNameUtility::getZoneStrings(this->locale));
	}
	if (!needsCopy) {
		return this->zoneStrings;
	}
	int32_t len = $nc(this->zoneStrings)->length;
	$var($StringArray2, aCopy, $new($StringArray2, len));
	for (int32_t i = 0; i < len; ++i) {
		aCopy->set(i, $fcast($StringArray, $($Arrays::copyOf($nc(this->zoneStrings)->get(i), $nc($nc(this->zoneStrings)->get(i))->length))));
	}
	return aCopy;
}

bool DateFormatSymbols::isSubclassObject() {
	return !$nc($($of(this)->getClass()->getName()))->equals("java.text.DateFormatSymbols"_s);
}

void DateFormatSymbols::copyMembers(DateFormatSymbols* src, DateFormatSymbols* dst) {
	$set($nc(dst), locale, $nc(src)->locale);
	$set(dst, eras, $fcast($StringArray, $Arrays::copyOf(src->eras, $nc(src->eras)->length)));
	$set(dst, months, $fcast($StringArray, $Arrays::copyOf(src->months, $nc(src->months)->length)));
	$set(dst, shortMonths, $fcast($StringArray, $Arrays::copyOf(src->shortMonths, $nc(src->shortMonths)->length)));
	$set(dst, weekdays, $fcast($StringArray, $Arrays::copyOf(src->weekdays, $nc(src->weekdays)->length)));
	$set(dst, shortWeekdays, $fcast($StringArray, $Arrays::copyOf(src->shortWeekdays, $nc(src->shortWeekdays)->length)));
	$set(dst, ampms, $fcast($StringArray, $Arrays::copyOf(src->ampms, $nc(src->ampms)->length)));
	if (src->zoneStrings != nullptr) {
		$set(dst, zoneStrings, src->getZoneStringsImpl(true));
	} else {
		$set(dst, zoneStrings, nullptr);
	}
	$set(dst, localPatternChars, src->localPatternChars);
	dst->cachedHashCode = 0;
}

void DateFormatSymbols::writeObject($ObjectOutputStream* stream) {
	if (this->zoneStrings == nullptr) {
		$set(this, zoneStrings, $TimeZoneNameUtility::getZoneStrings(this->locale));
	}
	$nc(stream)->defaultWriteObject();
}

void clinit$DateFormatSymbols($Class* class$) {
	$assignStatic(DateFormatSymbols::patternChars, "GyMdkHmsSEDFwWahKzZYuXL"_s);
	$assignStatic(DateFormatSymbols::cachedInstances, $new($ConcurrentHashMap, 3));
}

DateFormatSymbols::DateFormatSymbols() {
}

$Class* DateFormatSymbols::load$($String* name, bool initialize) {
	$loadClass(DateFormatSymbols, name, initialize, &_DateFormatSymbols_ClassInfo_, clinit$DateFormatSymbols, allocate$DateFormatSymbols);
	return class$;
}

$Class* DateFormatSymbols::class$ = nullptr;

	} // text
} // java