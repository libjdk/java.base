#include <java/time/format/DateTimeTextProvider.h>

#include <java/time/chrono/Chronology.h>
#include <java/time/chrono/IsoChronology.h>
#include <java/time/chrono/JapaneseChronology.h>
#include <java/time/format/DateTimeTextProvider$1.h>
#include <java/time/format/DateTimeTextProvider$2.h>
#include <java/time/format/DateTimeTextProvider$LocaleStore.h>
#include <java/time/format/TextStyle.h>
#include <java/time/temporal/ChronoField.h>
#include <java/time/temporal/IsoFields.h>
#include <java/time/temporal/TemporalField.h>
#include <java/util/AbstractMap$SimpleImmutableEntry.h>
#include <java/util/ArrayList.h>
#include <java/util/Calendar.h>
#include <java/util/Comparator.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/ResourceBundle.h>
#include <java/util/Set.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/concurrent/ConcurrentMap.h>
#include <sun/util/locale/provider/CalendarDataUtility.h>
#include <sun/util/locale/provider/LocaleProviderAdapter.h>
#include <sun/util/locale/provider/LocaleResources.h>
#include <jcpp.h>

#undef ALL_STYLES
#undef AMPM_OF_DAY
#undef AM_PM
#undef CACHE
#undef COMPARATOR
#undef DAY_OF_WEEK
#undef DECEMBER
#undef ERA
#undef INSTANCE
#undef JANUARY
#undef MONTH
#undef MONTH_OF_YEAR
#undef NARROW
#undef NARROW_STANDALONE
#undef QUARTER_OF_YEAR
#undef SATURDAY
#undef SUNDAY

using $TextStyleArray = $Array<::java::time::format::TextStyle>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Chronology = ::java::time::chrono::Chronology;
using $IsoChronology = ::java::time::chrono::IsoChronology;
using $JapaneseChronology = ::java::time::chrono::JapaneseChronology;
using $DateTimeTextProvider$1 = ::java::time::format::DateTimeTextProvider$1;
using $DateTimeTextProvider$2 = ::java::time::format::DateTimeTextProvider$2;
using $DateTimeTextProvider$LocaleStore = ::java::time::format::DateTimeTextProvider$LocaleStore;
using $TextStyle = ::java::time::format::TextStyle;
using $ChronoField = ::java::time::temporal::ChronoField;
using $IsoFields = ::java::time::temporal::IsoFields;
using $TemporalField = ::java::time::temporal::TemporalField;
using $AbstractMap$SimpleImmutableEntry = ::java::util::AbstractMap$SimpleImmutableEntry;
using $ArrayList = ::java::util::ArrayList;
using $Calendar = ::java::util::Calendar;
using $Comparator = ::java::util::Comparator;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $ResourceBundle = ::java::util::ResourceBundle;
using $Set = ::java::util::Set;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $ConcurrentMap = ::java::util::concurrent::ConcurrentMap;
using $CalendarDataUtility = ::sun::util::locale::provider::CalendarDataUtility;
using $LocaleProviderAdapter = ::sun::util::locale::provider::LocaleProviderAdapter;
using $LocaleResources = ::sun::util::locale::provider::LocaleResources;

namespace java {
	namespace time {
		namespace format {

$FieldInfo _DateTimeTextProvider_FieldInfo_[] = {
	{"CACHE", "Ljava/util/concurrent/ConcurrentMap;", "Ljava/util/concurrent/ConcurrentMap<Ljava/util/Map$Entry<Ljava/time/temporal/TemporalField;Ljava/util/Locale;>;Ljava/lang/Object;>;", $PRIVATE | $STATIC | $FINAL, $staticField(DateTimeTextProvider, CACHE)},
	{"COMPARATOR", "Ljava/util/Comparator;", "Ljava/util/Comparator<Ljava/util/Map$Entry<Ljava/lang/String;Ljava/lang/Long;>;>;", $PRIVATE | $STATIC | $FINAL, $staticField(DateTimeTextProvider, COMPARATOR)},
	{"INSTANCE", "Ljava/time/format/DateTimeTextProvider;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DateTimeTextProvider, INSTANCE)},
	{}
};

$MethodInfo _DateTimeTextProvider_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(DateTimeTextProvider, init$, void)},
	{"createEntry", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/util/Map$Entry;", "<A:Ljava/lang/Object;B:Ljava/lang/Object;>(TA;TB;)Ljava/util/Map$Entry<TA;TB;>;", $PRIVATE | $STATIC, $staticMethod(DateTimeTextProvider, createEntry, $Map$Entry*, Object$*, Object$*)},
	{"createStore", "(Ljava/time/temporal/TemporalField;Ljava/util/Locale;)Ljava/lang/Object;", nullptr, $PRIVATE, $method(DateTimeTextProvider, createStore, $Object*, $TemporalField*, $Locale*)},
	{"findStore", "(Ljava/time/temporal/TemporalField;Ljava/util/Locale;)Ljava/lang/Object;", nullptr, $PRIVATE, $method(DateTimeTextProvider, findStore, $Object*, $TemporalField*, $Locale*)},
	{"getInstance", "()Ljava/time/format/DateTimeTextProvider;", nullptr, $STATIC, $staticMethod(DateTimeTextProvider, getInstance, DateTimeTextProvider*)},
	{"getLocalizedResource", "(Ljava/lang/String;Ljava/util/Locale;)Ljava/lang/Object;", "<T:Ljava/lang/Object;>(Ljava/lang/String;Ljava/util/Locale;)TT;", $STATIC, $staticMethod(DateTimeTextProvider, getLocalizedResource, $Object*, $String*, $Locale*)},
	{"getText", "(Ljava/time/temporal/TemporalField;JLjava/time/format/TextStyle;Ljava/util/Locale;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(DateTimeTextProvider, getText, $String*, $TemporalField*, int64_t, $TextStyle*, $Locale*)},
	{"getText", "(Ljava/time/chrono/Chronology;Ljava/time/temporal/TemporalField;JLjava/time/format/TextStyle;Ljava/util/Locale;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(DateTimeTextProvider, getText, $String*, $Chronology*, $TemporalField*, int64_t, $TextStyle*, $Locale*)},
	{"getTextIterator", "(Ljava/time/temporal/TemporalField;Ljava/time/format/TextStyle;Ljava/util/Locale;)Ljava/util/Iterator;", "(Ljava/time/temporal/TemporalField;Ljava/time/format/TextStyle;Ljava/util/Locale;)Ljava/util/Iterator<Ljava/util/Map$Entry<Ljava/lang/String;Ljava/lang/Long;>;>;", $PUBLIC, $virtualMethod(DateTimeTextProvider, getTextIterator, $Iterator*, $TemporalField*, $TextStyle*, $Locale*)},
	{"getTextIterator", "(Ljava/time/chrono/Chronology;Ljava/time/temporal/TemporalField;Ljava/time/format/TextStyle;Ljava/util/Locale;)Ljava/util/Iterator;", "(Ljava/time/chrono/Chronology;Ljava/time/temporal/TemporalField;Ljava/time/format/TextStyle;Ljava/util/Locale;)Ljava/util/Iterator<Ljava/util/Map$Entry<Ljava/lang/String;Ljava/lang/Long;>;>;", $PUBLIC, $virtualMethod(DateTimeTextProvider, getTextIterator, $Iterator*, $Chronology*, $TemporalField*, $TextStyle*, $Locale*)},
	{"toWeekDay", "(I)I", nullptr, $PRIVATE | $STATIC, $staticMethod(DateTimeTextProvider, toWeekDay, int32_t, int32_t)},
	{}
};

$InnerClassInfo _DateTimeTextProvider_InnerClassesInfo_[] = {
	{"java.time.format.DateTimeTextProvider$2", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{"java.time.format.DateTimeTextProvider$LocaleStore", "java.time.format.DateTimeTextProvider", "LocaleStore", $STATIC | $FINAL},
	{"java.time.format.DateTimeTextProvider$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _DateTimeTextProvider_ClassInfo_ = {
	$ACC_SUPER,
	"java.time.format.DateTimeTextProvider",
	"java.lang.Object",
	nullptr,
	_DateTimeTextProvider_FieldInfo_,
	_DateTimeTextProvider_MethodInfo_,
	nullptr,
	nullptr,
	_DateTimeTextProvider_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.time.format.DateTimeTextProvider$2,java.time.format.DateTimeTextProvider$LocaleStore,java.time.format.DateTimeTextProvider$1"
};

$Object* allocate$DateTimeTextProvider($Class* clazz) {
	return $of($alloc(DateTimeTextProvider));
}

$ConcurrentMap* DateTimeTextProvider::CACHE = nullptr;
$Comparator* DateTimeTextProvider::COMPARATOR = nullptr;
DateTimeTextProvider* DateTimeTextProvider::INSTANCE = nullptr;

void DateTimeTextProvider::init$() {
}

DateTimeTextProvider* DateTimeTextProvider::getInstance() {
	$init(DateTimeTextProvider);
	return DateTimeTextProvider::INSTANCE;
}

$String* DateTimeTextProvider::getText($TemporalField* field, int64_t value, $TextStyle* style, $Locale* locale) {
	$var($Object, store, findStore(field, locale));
	if ($instanceOf($DateTimeTextProvider$LocaleStore, store)) {
		return $nc(($cast($DateTimeTextProvider$LocaleStore, store)))->getText(value, style);
	}
	return nullptr;
}

$String* DateTimeTextProvider::getText($Chronology* chrono, $TemporalField* field, int64_t value, $TextStyle* style, $Locale* locale) {
	$init($IsoChronology);
	if ($equals(chrono, $IsoChronology::INSTANCE) || !($instanceOf($ChronoField, field))) {
		return getText(field, value, style, locale);
	}
	int32_t fieldIndex = 0;
	int32_t fieldValue = 0;
	$init($ChronoField);
	if ($equals(field, $ChronoField::ERA)) {
		fieldIndex = $Calendar::ERA;
		$init($JapaneseChronology);
		if ($equals(chrono, $JapaneseChronology::INSTANCE)) {
			if (value == -999) {
				fieldValue = 0;
			} else {
				fieldValue = (int32_t)value + 2;
			}
		} else {
			fieldValue = (int32_t)value;
		}
	} else {
		if ($equals(field, $ChronoField::MONTH_OF_YEAR)) {
			fieldIndex = $Calendar::MONTH;
			fieldValue = (int32_t)value - 1;
		} else {
			if ($equals(field, $ChronoField::DAY_OF_WEEK)) {
				fieldIndex = $Calendar::DAY_OF_WEEK;
				fieldValue = (int32_t)value + 1;
				if (fieldValue > 7) {
					fieldValue = $Calendar::SUNDAY;
				}
			} else {
				if ($equals(field, $ChronoField::AMPM_OF_DAY)) {
					fieldIndex = $Calendar::AM_PM;
					fieldValue = (int32_t)value;
				} else {
					return nullptr;
				}
			}
		}
	}
	$var($String, var$0, $nc(chrono)->getCalendarType());
	int32_t var$1 = fieldIndex;
	int32_t var$2 = fieldValue;
	return $CalendarDataUtility::retrieveJavaTimeFieldValueName(var$0, var$1, var$2, $nc(style)->toCalendarStyle(), locale);
}

$Iterator* DateTimeTextProvider::getTextIterator($TemporalField* field, $TextStyle* style, $Locale* locale) {
	$var($Object, store, findStore(field, locale));
	if ($instanceOf($DateTimeTextProvider$LocaleStore, store)) {
		return $nc(($cast($DateTimeTextProvider$LocaleStore, store)))->getTextIterator(style);
	}
	return nullptr;
}

$Iterator* DateTimeTextProvider::getTextIterator($Chronology* chrono, $TemporalField* field, $TextStyle* style, $Locale* locale) {
	$useLocalCurrentObjectStackCache();
	$init($IsoChronology);
	if ($equals(chrono, $IsoChronology::INSTANCE) || !($instanceOf($ChronoField, field))) {
		return getTextIterator(field, style, locale);
	}
	int32_t fieldIndex = 0;
	$init($DateTimeTextProvider$2);
	switch ($nc($DateTimeTextProvider$2::$SwitchMap$java$time$temporal$ChronoField)->get($nc(($cast($ChronoField, field)))->ordinal())) {
	case 1:
		{
			fieldIndex = $Calendar::ERA;
			break;
		}
	case 2:
		{
			fieldIndex = $Calendar::MONTH;
			break;
		}
	case 3:
		{
			fieldIndex = $Calendar::DAY_OF_WEEK;
			break;
		}
	case 4:
		{
			fieldIndex = $Calendar::AM_PM;
			break;
		}
	default:
		{
			return nullptr;
		}
	}
	int32_t calendarStyle = (style == nullptr) ? $Calendar::ALL_STYLES : $nc(style)->toCalendarStyle();
	$var($Map, map, $CalendarDataUtility::retrieveJavaTimeFieldValueNames($($nc(chrono)->getCalendarType()), fieldIndex, calendarStyle, locale));
	if (map == nullptr) {
		return nullptr;
	}
	$var($List, list, $new($ArrayList, $nc(map)->size()));
	switch (fieldIndex) {
	case $Calendar::ERA:
		{
			{
				$var($Iterator, i$, $nc($($nc(map)->entrySet()))->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
					{
						int32_t era = $nc(($cast($Integer, $($nc(entry)->getValue()))))->intValue();
						$init($JapaneseChronology);
						if ($equals(chrono, $JapaneseChronology::INSTANCE)) {
							if (era == 0) {
								era = -999;
							} else {
								era -= 2;
							}
						}
						$var($Object, var$0, $cast($String, entry->getKey()));
						list->add($(createEntry(var$0, $($Long::valueOf((int64_t)era)))));
					}
				}
			}
			break;
		}
	case $Calendar::MONTH:
		{
			{
				$var($Iterator, i$, $nc($($nc(map)->entrySet()))->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
					{
						$var($Object, var$1, $cast($String, $nc(entry)->getKey()));
						list->add($(createEntry(var$1, $($Long::valueOf((int64_t)($nc(($cast($Integer, $(entry->getValue()))))->intValue() + 1))))));
					}
				}
			}
			break;
		}
	case $Calendar::DAY_OF_WEEK:
		{
			{
				$var($Iterator, i$, $nc($($nc(map)->entrySet()))->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
					{
						$var($Object, var$2, $cast($String, $nc(entry)->getKey()));
						list->add($(createEntry(var$2, $($Long::valueOf((int64_t)toWeekDay($nc(($cast($Integer, $(entry->getValue()))))->intValue()))))));
					}
				}
			}
			break;
		}
	default:
		{
			{
				$var($Iterator, i$, $nc($($nc(map)->entrySet()))->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
					{
						$var($Object, var$3, $cast($String, $nc(entry)->getKey()));
						list->add($(createEntry(var$3, $($Long::valueOf((int64_t)$nc(($cast($Integer, $(entry->getValue()))))->intValue())))));
					}
				}
			}
			break;
		}
	}
	return list->iterator();
}

$Object* DateTimeTextProvider::findStore($TemporalField* field, $Locale* locale) {
	$useLocalCurrentObjectStackCache();
	$var($Map$Entry, key, createEntry(field, locale));
	$var($Object, store, $nc(DateTimeTextProvider::CACHE)->get(key));
	if (store == nullptr) {
		$assign(store, createStore(field, locale));
		$nc(DateTimeTextProvider::CACHE)->putIfAbsent(key, store);
		$assign(store, $nc(DateTimeTextProvider::CACHE)->get(key));
	}
	return $of(store);
}

int32_t DateTimeTextProvider::toWeekDay(int32_t calWeekDay) {
	$init(DateTimeTextProvider);
	if (calWeekDay == $Calendar::SUNDAY) {
		return 7;
	} else {
		return calWeekDay - 1;
	}
}

$Object* DateTimeTextProvider::createStore($TemporalField* field, $Locale* locale) {
	$useLocalCurrentObjectStackCache();
	$var($Map, styleMap, $new($HashMap));
	$init($ChronoField);
	if ($equals(field, $ChronoField::ERA)) {
		{
			$var($TextStyleArray, arr$, $TextStyle::values());
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$TextStyle* textStyle = arr$->get(i$);
				{
					if ($nc(textStyle)->isStandalone()) {
						continue;
					}
					$var($Map, displayNames, $CalendarDataUtility::retrieveJavaTimeFieldValueNames("gregory"_s, $Calendar::ERA, $nc(textStyle)->toCalendarStyle(), locale));
					if (displayNames != nullptr) {
						$var($Map, map, $new($HashMap));
						{
							$var($Iterator, i$, $nc($(displayNames->entrySet()))->iterator());
							for (; $nc(i$)->hasNext();) {
								$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
								{
									$var($Object, var$0, $of($Long::valueOf((int64_t)$nc(($cast($Integer, $($nc(entry)->getValue()))))->intValue())));
									map->put(var$0, $cast($String, $($nc(entry)->getKey())));
								}
							}
						}
						if (!map->isEmpty()) {
							styleMap->put(textStyle, map);
						}
					}
				}
			}
		}
		return $of($new($DateTimeTextProvider$LocaleStore, styleMap));
	}
	if ($equals(field, $ChronoField::MONTH_OF_YEAR)) {
		{
			$var($TextStyleArray, arr$, $TextStyle::values());
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$TextStyle* textStyle = arr$->get(i$);
				{
					$var($Map, map, $new($HashMap));
					bool var$1 = $nc(textStyle)->equals($TextStyle::NARROW);
					if (var$1 || $nc(textStyle)->equals($TextStyle::NARROW_STANDALONE)) {
						for (int32_t month = $Calendar::JANUARY; month <= $Calendar::DECEMBER; ++month) {
							$var($String, name, nullptr);
							$assign(name, $CalendarDataUtility::retrieveJavaTimeFieldValueName("gregory"_s, $Calendar::MONTH, month, textStyle->toCalendarStyle(), locale));
							if (name == nullptr) {
								break;
							}
							map->put($($Long::valueOf((month + (int64_t)1))), name);
						}
					} else {
						$var($Map, displayNames, $CalendarDataUtility::retrieveJavaTimeFieldValueNames("gregory"_s, $Calendar::MONTH, textStyle->toCalendarStyle(), locale));
						if (displayNames != nullptr) {
							{
								$var($Iterator, i$, $nc($(displayNames->entrySet()))->iterator());
								for (; $nc(i$)->hasNext();) {
									$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
									{
										$var($Object, var$2, $of($Long::valueOf((int64_t)($nc(($cast($Integer, $($nc(entry)->getValue()))))->intValue() + 1))));
										map->put(var$2, $cast($String, $($nc(entry)->getKey())));
									}
								}
							}
						} else {
							for (int32_t month = $Calendar::JANUARY; month <= $Calendar::DECEMBER; ++month) {
								$var($String, name, nullptr);
								$assign(name, $CalendarDataUtility::retrieveJavaTimeFieldValueName("gregory"_s, $Calendar::MONTH, month, textStyle->toCalendarStyle(), locale));
								if (name == nullptr) {
									break;
								}
								map->put($($Long::valueOf((month + (int64_t)1))), name);
							}
						}
					}
					if (!map->isEmpty()) {
						styleMap->put(textStyle, map);
					}
				}
			}
		}
		return $of($new($DateTimeTextProvider$LocaleStore, styleMap));
	}
	if ($equals(field, $ChronoField::DAY_OF_WEEK)) {
		{
			$var($TextStyleArray, arr$, $TextStyle::values());
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$TextStyle* textStyle = arr$->get(i$);
				{
					$var($Map, map, $new($HashMap));
					bool var$3 = $nc(textStyle)->equals($TextStyle::NARROW);
					if (var$3 || $nc(textStyle)->equals($TextStyle::NARROW_STANDALONE)) {
						for (int32_t wday = $Calendar::SUNDAY; wday <= $Calendar::SATURDAY; ++wday) {
							$var($String, name, nullptr);
							$assign(name, $CalendarDataUtility::retrieveJavaTimeFieldValueName("gregory"_s, $Calendar::DAY_OF_WEEK, wday, textStyle->toCalendarStyle(), locale));
							if (name == nullptr) {
								break;
							}
							map->put($($Long::valueOf((int64_t)toWeekDay(wday))), name);
						}
					} else {
						$var($Map, displayNames, $CalendarDataUtility::retrieveJavaTimeFieldValueNames("gregory"_s, $Calendar::DAY_OF_WEEK, textStyle->toCalendarStyle(), locale));
						if (displayNames != nullptr) {
							{
								$var($Iterator, i$, $nc($(displayNames->entrySet()))->iterator());
								for (; $nc(i$)->hasNext();) {
									$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
									{
										$var($Object, var$4, $of($Long::valueOf((int64_t)toWeekDay($nc(($cast($Integer, $($nc(entry)->getValue()))))->intValue()))));
										map->put(var$4, $cast($String, $($nc(entry)->getKey())));
									}
								}
							}
						} else {
							for (int32_t wday = $Calendar::SUNDAY; wday <= $Calendar::SATURDAY; ++wday) {
								$var($String, name, nullptr);
								$assign(name, $CalendarDataUtility::retrieveJavaTimeFieldValueName("gregory"_s, $Calendar::DAY_OF_WEEK, wday, textStyle->toCalendarStyle(), locale));
								if (name == nullptr) {
									break;
								}
								map->put($($Long::valueOf((int64_t)toWeekDay(wday))), name);
							}
						}
					}
					if (!map->isEmpty()) {
						styleMap->put(textStyle, map);
					}
				}
			}
		}
		return $of($new($DateTimeTextProvider$LocaleStore, styleMap));
	}
	if ($equals(field, $ChronoField::AMPM_OF_DAY)) {
		{
			$var($TextStyleArray, arr$, $TextStyle::values());
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$TextStyle* textStyle = arr$->get(i$);
				{
					if ($nc(textStyle)->isStandalone()) {
						continue;
					}
					$var($Map, displayNames, $CalendarDataUtility::retrieveJavaTimeFieldValueNames("gregory"_s, $Calendar::AM_PM, $nc(textStyle)->toCalendarStyle(), locale));
					if (displayNames != nullptr) {
						$var($Map, map, $new($HashMap));
						{
							$var($Iterator, i$, $nc($(displayNames->entrySet()))->iterator());
							for (; $nc(i$)->hasNext();) {
								$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
								{
									$var($Object, var$5, $of($Long::valueOf((int64_t)$nc(($cast($Integer, $($nc(entry)->getValue()))))->intValue())));
									map->put(var$5, $cast($String, $($nc(entry)->getKey())));
								}
							}
						}
						if (!map->isEmpty()) {
							styleMap->put(textStyle, map);
						}
					}
				}
			}
		}
		return $of($new($DateTimeTextProvider$LocaleStore, styleMap));
	}
	$init($IsoFields);
	if (field == $IsoFields::QUARTER_OF_YEAR) {
		$var($StringArray, keys, $new($StringArray, {
			"QuarterNames"_s,
			"standalone.QuarterNames"_s,
			"QuarterAbbreviations"_s,
			"standalone.QuarterAbbreviations"_s,
			"QuarterNarrows"_s,
			"standalone.QuarterNarrows"_s
		}));
		for (int32_t i = 0; i < keys->length; ++i) {
			$var($StringArray, names, $cast($StringArray, getLocalizedResource(keys->get(i), locale)));
			if (names != nullptr) {
				$var($Map, map, $new($HashMap));
				for (int32_t q = 0; q < names->length; ++q) {
					map->put($($Long::valueOf((int64_t)(q + 1))), names->get(q));
				}
				styleMap->put($($TextStyle::values())->get(i), map);
			}
		}
		return $of($new($DateTimeTextProvider$LocaleStore, styleMap));
	}
	return $of(""_s);
}

$Map$Entry* DateTimeTextProvider::createEntry(Object$* text, Object$* field) {
	$init(DateTimeTextProvider);
	return $new($AbstractMap$SimpleImmutableEntry, text, field);
}

$Object* DateTimeTextProvider::getLocalizedResource($String* key, $Locale* locale) {
	$init(DateTimeTextProvider);
	$useLocalCurrentObjectStackCache();
	$var($LocaleResources, lr, $nc($($LocaleProviderAdapter::getResourceBundleBased()))->getLocaleResources($($CalendarDataUtility::findRegionOverride(locale))));
	$var($ResourceBundle, rb, $nc(lr)->getJavaTimeFormatData());
	return $of($nc(rb)->containsKey(key) ? $nc(rb)->getObject(key) : ($Object*)nullptr);
}

void clinit$DateTimeTextProvider($Class* class$) {
	$assignStatic(DateTimeTextProvider::CACHE, $new($ConcurrentHashMap, 16, 0.75f, 2));
	$assignStatic(DateTimeTextProvider::COMPARATOR, $new($DateTimeTextProvider$1));
	$assignStatic(DateTimeTextProvider::INSTANCE, $new(DateTimeTextProvider));
}

DateTimeTextProvider::DateTimeTextProvider() {
}

$Class* DateTimeTextProvider::load$($String* name, bool initialize) {
	$loadClass(DateTimeTextProvider, name, initialize, &_DateTimeTextProvider_ClassInfo_, clinit$DateTimeTextProvider, allocate$DateTimeTextProvider);
	return class$;
}

$Class* DateTimeTextProvider::class$ = nullptr;

		} // format
	} // time
} // java