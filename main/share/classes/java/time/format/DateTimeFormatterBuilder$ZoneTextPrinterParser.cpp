#include <java/time/format/DateTimeFormatterBuilder$ZoneTextPrinterParser.h>

#include <java/io/Serializable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/ref/SoftReference.h>
#include <java/time/Instant.h>
#include <java/time/LocalDate.h>
#include <java/time/LocalDateTime.h>
#include <java/time/LocalTime.h>
#include <java/time/ZoneId.h>
#include <java/time/ZoneOffset.h>
#include <java/time/ZonedDateTime.h>
#include <java/time/chrono/ChronoLocalDateTime.h>
#include <java/time/chrono/ChronoZonedDateTime.h>
#include <java/time/format/DateTimeFormatterBuilder$PrefixTree.h>
#include <java/time/format/DateTimeFormatterBuilder$ZoneIdPrinterParser.h>
#include <java/time/format/DateTimeFormatterBuilder.h>
#include <java/time/format/DateTimeParseContext.h>
#include <java/time/format/DateTimePrintContext.h>
#include <java/time/format/TextStyle.h>
#include <java/time/format/ZoneName.h>
#include <java/time/temporal/ChronoField.h>
#include <java/time/temporal/TemporalAccessor.h>
#include <java/time/temporal/TemporalField.h>
#include <java/time/temporal/TemporalQueries.h>
#include <java/time/temporal/TemporalQuery.h>
#include <java/time/zone/ZoneOffsetTransition.h>
#include <java/time/zone/ZoneRules.h>
#include <java/time/zone/ZoneRulesProvider.h>
#include <java/util/AbstractMap$SimpleImmutableEntry.h>
#include <java/util/AbstractMap.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/HashMap.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/Locale.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Set.h>
#include <java/util/TimeZone.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Predicate.h>
#include <java/util/stream/Stream.h>
#include <sun/util/locale/provider/TimeZoneNameUtility.h>
#include <jcpp.h>

#undef DST
#undef EPOCH_DAY
#undef FULL
#undef GENERIC
#undef INSTANT_SECONDS
#undef LONG
#undef NANO_OF_DAY
#undef NARROW
#undef SHORT
#undef STD

using $StringArray2 = $Array<::java::lang::String, 2>;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $SoftReference = ::java::lang::ref::SoftReference;
using $Instant = ::java::time::Instant;
using $LocalDate = ::java::time::LocalDate;
using $LocalDateTime = ::java::time::LocalDateTime;
using $LocalTime = ::java::time::LocalTime;
using $ZoneId = ::java::time::ZoneId;
using $ZoneOffset = ::java::time::ZoneOffset;
using $ZonedDateTime = ::java::time::ZonedDateTime;
using $DateTimeFormatterBuilder$PrefixTree = ::java::time::format::DateTimeFormatterBuilder$PrefixTree;
using $DateTimeFormatterBuilder$ZoneIdPrinterParser = ::java::time::format::DateTimeFormatterBuilder$ZoneIdPrinterParser;
using $DateTimeParseContext = ::java::time::format::DateTimeParseContext;
using $DateTimePrintContext = ::java::time::format::DateTimePrintContext;
using $TextStyle = ::java::time::format::TextStyle;
using $ZoneName = ::java::time::format::ZoneName;
using $ChronoField = ::java::time::temporal::ChronoField;
using $TemporalAccessor = ::java::time::temporal::TemporalAccessor;
using $TemporalField = ::java::time::temporal::TemporalField;
using $TemporalQueries = ::java::time::temporal::TemporalQueries;
using $TemporalQuery = ::java::time::temporal::TemporalQuery;
using $ZoneRules = ::java::time::zone::ZoneRules;
using $ZoneRulesProvider = ::java::time::zone::ZoneRulesProvider;
using $AbstractMap = ::java::util::AbstractMap;
using $AbstractMap$SimpleImmutableEntry = ::java::util::AbstractMap$SimpleImmutableEntry;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $HashMap = ::java::util::HashMap;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Objects = ::java::util::Objects;
using $Set = ::java::util::Set;
using $TimeZone = ::java::util::TimeZone;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $Consumer = ::java::util::function::Consumer;
using $Predicate = ::java::util::function::Predicate;
using $Stream = ::java::util::stream::Stream;
using $TimeZoneNameUtility = ::sun::util::locale::provider::TimeZoneNameUtility;

namespace java {
	namespace time {
		namespace format {

class DateTimeFormatterBuilder$ZoneTextPrinterParser$$Lambda$lambda$getTree$0 : public $Predicate {
	$class(DateTimeFormatterBuilder$ZoneTextPrinterParser$$Lambda$lambda$getTree$0, $NO_CLASS_INIT, $Predicate)
public:
	void init$() {
	}
	virtual bool test(Object$* zid) override {
		 return DateTimeFormatterBuilder$ZoneTextPrinterParser::lambda$getTree$0($cast($String, zid));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DateTimeFormatterBuilder$ZoneTextPrinterParser$$Lambda$lambda$getTree$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo DateTimeFormatterBuilder$ZoneTextPrinterParser$$Lambda$lambda$getTree$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder$ZoneTextPrinterParser$$Lambda$lambda$getTree$0, init$, void)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(DateTimeFormatterBuilder$ZoneTextPrinterParser$$Lambda$lambda$getTree$0, test, bool, Object$*)},
	{}
};
$ClassInfo DateTimeFormatterBuilder$ZoneTextPrinterParser$$Lambda$lambda$getTree$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.time.format.DateTimeFormatterBuilder$ZoneTextPrinterParser$$Lambda$lambda$getTree$0",
	"java.lang.Object",
	"java.util.function.Predicate",
	nullptr,
	methodInfos
};
$Class* DateTimeFormatterBuilder$ZoneTextPrinterParser$$Lambda$lambda$getTree$0::load$($String* name, bool initialize) {
	$loadClass(DateTimeFormatterBuilder$ZoneTextPrinterParser$$Lambda$lambda$getTree$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DateTimeFormatterBuilder$ZoneTextPrinterParser$$Lambda$lambda$getTree$0::class$ = nullptr;

class DateTimeFormatterBuilder$ZoneTextPrinterParser$$Lambda$lambda$getTree$1$1 : public $Consumer {
	$class(DateTimeFormatterBuilder$ZoneTextPrinterParser$$Lambda$lambda$getTree$1$1, $NO_CLASS_INIT, $Consumer)
public:
	void init$(DateTimeFormatterBuilder$ZoneTextPrinterParser* inst, $Locale* locale, $DateTimeFormatterBuilder$PrefixTree* t) {
		$set(this, inst$, inst);
		$set(this, locale, locale);
		$set(this, t, t);
	}
	virtual void accept(Object$* cid) override {
		$nc(inst$)->lambda$getTree$1(locale, t, $cast($String, cid));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DateTimeFormatterBuilder$ZoneTextPrinterParser$$Lambda$lambda$getTree$1$1>());
	}
	DateTimeFormatterBuilder$ZoneTextPrinterParser* inst$ = nullptr;
	$Locale* locale = nullptr;
	$DateTimeFormatterBuilder$PrefixTree* t = nullptr;
	static $FieldInfo fieldInfos[4];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo DateTimeFormatterBuilder$ZoneTextPrinterParser$$Lambda$lambda$getTree$1$1::fieldInfos[4] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(DateTimeFormatterBuilder$ZoneTextPrinterParser$$Lambda$lambda$getTree$1$1, inst$)},
	{"locale", "Ljava/util/Locale;", nullptr, $PUBLIC, $field(DateTimeFormatterBuilder$ZoneTextPrinterParser$$Lambda$lambda$getTree$1$1, locale)},
	{"t", "Ljava/time/format/DateTimeFormatterBuilder$PrefixTree;", nullptr, $PUBLIC, $field(DateTimeFormatterBuilder$ZoneTextPrinterParser$$Lambda$lambda$getTree$1$1, t)},
	{}
};
$MethodInfo DateTimeFormatterBuilder$ZoneTextPrinterParser$$Lambda$lambda$getTree$1$1::methodInfos[3] = {
	{"<init>", "(Ljava/time/format/DateTimeFormatterBuilder$ZoneTextPrinterParser;Ljava/util/Locale;Ljava/time/format/DateTimeFormatterBuilder$PrefixTree;)V", nullptr, $PUBLIC, $method(DateTimeFormatterBuilder$ZoneTextPrinterParser$$Lambda$lambda$getTree$1$1, init$, void, DateTimeFormatterBuilder$ZoneTextPrinterParser*, $Locale*, $DateTimeFormatterBuilder$PrefixTree*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(DateTimeFormatterBuilder$ZoneTextPrinterParser$$Lambda$lambda$getTree$1$1, accept, void, Object$*)},
	{}
};
$ClassInfo DateTimeFormatterBuilder$ZoneTextPrinterParser$$Lambda$lambda$getTree$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.time.format.DateTimeFormatterBuilder$ZoneTextPrinterParser$$Lambda$lambda$getTree$1$1",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* DateTimeFormatterBuilder$ZoneTextPrinterParser$$Lambda$lambda$getTree$1$1::load$($String* name, bool initialize) {
	$loadClass(DateTimeFormatterBuilder$ZoneTextPrinterParser$$Lambda$lambda$getTree$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DateTimeFormatterBuilder$ZoneTextPrinterParser$$Lambda$lambda$getTree$1$1::class$ = nullptr;

$FieldInfo _DateTimeFormatterBuilder$ZoneTextPrinterParser_FieldInfo_[] = {
	{"textStyle", "Ljava/time/format/TextStyle;", nullptr, $PRIVATE | $FINAL, $field(DateTimeFormatterBuilder$ZoneTextPrinterParser, textStyle)},
	{"preferredZones", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE, $field(DateTimeFormatterBuilder$ZoneTextPrinterParser, preferredZones)},
	{"isGeneric", "Z", nullptr, $PRIVATE | $FINAL, $field(DateTimeFormatterBuilder$ZoneTextPrinterParser, isGeneric)},
	{"STD", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(DateTimeFormatterBuilder$ZoneTextPrinterParser, STD)},
	{"DST", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(DateTimeFormatterBuilder$ZoneTextPrinterParser, DST)},
	{"GENERIC", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(DateTimeFormatterBuilder$ZoneTextPrinterParser, GENERIC)},
	{"cache", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/ref/SoftReference<Ljava/util/Map<Ljava/util/Locale;[Ljava/lang/String;>;>;>;", $PRIVATE | $STATIC | $FINAL, $staticField(DateTimeFormatterBuilder$ZoneTextPrinterParser, cache)},
	{"cachedTree", "Ljava/util/Map;", "Ljava/util/Map<Ljava/util/Locale;Ljava/util/Map$Entry<Ljava/lang/Integer;Ljava/lang/ref/SoftReference<Ljava/time/format/DateTimeFormatterBuilder$PrefixTree;>;>;>;", $PRIVATE | $FINAL, $field(DateTimeFormatterBuilder$ZoneTextPrinterParser, cachedTree)},
	{"cachedTreeCI", "Ljava/util/Map;", "Ljava/util/Map<Ljava/util/Locale;Ljava/util/Map$Entry<Ljava/lang/Integer;Ljava/lang/ref/SoftReference<Ljava/time/format/DateTimeFormatterBuilder$PrefixTree;>;>;>;", $PRIVATE | $FINAL, $field(DateTimeFormatterBuilder$ZoneTextPrinterParser, cachedTreeCI)},
	{}
};

$MethodInfo _DateTimeFormatterBuilder$ZoneTextPrinterParser_MethodInfo_[] = {
	{"<init>", "(Ljava/time/format/TextStyle;Ljava/util/Set;Z)V", "(Ljava/time/format/TextStyle;Ljava/util/Set<Ljava/time/ZoneId;>;Z)V", 0, $method(DateTimeFormatterBuilder$ZoneTextPrinterParser, init$, void, $TextStyle*, $Set*, bool)},
	{"format", "(Ljava/time/format/DateTimePrintContext;Ljava/lang/StringBuilder;)Z", nullptr, $PUBLIC, $virtualMethod(DateTimeFormatterBuilder$ZoneTextPrinterParser, format, bool, $DateTimePrintContext*, $StringBuilder*)},
	{"getDisplayName", "(Ljava/lang/String;ILjava/util/Locale;)Ljava/lang/String;", nullptr, $PRIVATE, $method(DateTimeFormatterBuilder$ZoneTextPrinterParser, getDisplayName, $String*, $String*, int32_t, $Locale*)},
	{"getTree", "(Ljava/time/format/DateTimeParseContext;)Ljava/time/format/DateTimeFormatterBuilder$PrefixTree;", nullptr, $PROTECTED, $virtualMethod(DateTimeFormatterBuilder$ZoneTextPrinterParser, getTree, $DateTimeFormatterBuilder$PrefixTree*, $DateTimeParseContext*)},
	{"lambda$getTree$0", "(Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(DateTimeFormatterBuilder$ZoneTextPrinterParser, lambda$getTree$0, bool, $String*)},
	{"lambda$getTree$1", "(Ljava/util/Locale;Ljava/time/format/DateTimeFormatterBuilder$PrefixTree;Ljava/lang/String;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(DateTimeFormatterBuilder$ZoneTextPrinterParser, lambda$getTree$1, void, $Locale*, $DateTimeFormatterBuilder$PrefixTree*, $String*)},
	{}
};

$InnerClassInfo _DateTimeFormatterBuilder$ZoneTextPrinterParser_InnerClassesInfo_[] = {
	{"java.time.format.DateTimeFormatterBuilder$ZoneTextPrinterParser", "java.time.format.DateTimeFormatterBuilder", "ZoneTextPrinterParser", $STATIC | $FINAL},
	{"java.time.format.DateTimeFormatterBuilder$ZoneIdPrinterParser", "java.time.format.DateTimeFormatterBuilder", "ZoneIdPrinterParser", $STATIC},
	{}
};

$ClassInfo _DateTimeFormatterBuilder$ZoneTextPrinterParser_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.time.format.DateTimeFormatterBuilder$ZoneTextPrinterParser",
	"java.time.format.DateTimeFormatterBuilder$ZoneIdPrinterParser",
	nullptr,
	_DateTimeFormatterBuilder$ZoneTextPrinterParser_FieldInfo_,
	_DateTimeFormatterBuilder$ZoneTextPrinterParser_MethodInfo_,
	nullptr,
	nullptr,
	_DateTimeFormatterBuilder$ZoneTextPrinterParser_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.time.format.DateTimeFormatterBuilder"
};

$Object* allocate$DateTimeFormatterBuilder$ZoneTextPrinterParser($Class* clazz) {
	return $of($alloc(DateTimeFormatterBuilder$ZoneTextPrinterParser));
}

$Map* DateTimeFormatterBuilder$ZoneTextPrinterParser::cache = nullptr;

void DateTimeFormatterBuilder$ZoneTextPrinterParser::init$($TextStyle* textStyle, $Set* preferredZones, bool isGeneric) {
	$useLocalCurrentObjectStackCache();
	$var($TemporalQuery, var$0, $TemporalQueries::zone());
	$DateTimeFormatterBuilder$ZoneIdPrinterParser::init$(var$0, $$str({"ZoneText("_s, textStyle, ")"_s}));
	$set(this, cachedTree, $new($HashMap));
	$set(this, cachedTreeCI, $new($HashMap));
	$set(this, textStyle, $cast($TextStyle, $Objects::requireNonNull($of(textStyle), "textStyle"_s)));
	this->isGeneric = isGeneric;
	if (preferredZones != nullptr && preferredZones->size() != 0) {
		$set(this, preferredZones, $new($HashSet));
		{
			$var($Iterator, i$, preferredZones->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($ZoneId, id, $cast($ZoneId, i$->next()));
				{
					$nc(this->preferredZones)->add($($nc(id)->getId()));
				}
			}
		}
	}
}

$String* DateTimeFormatterBuilder$ZoneTextPrinterParser::getDisplayName($String* id, int32_t type, $Locale* locale) {
	$useLocalCurrentObjectStackCache();
	$init($TextStyle);
	if (this->textStyle == $TextStyle::NARROW) {
		return nullptr;
	}
	$var($StringArray, names, nullptr);
	$var($SoftReference, ref, $cast($SoftReference, $nc(DateTimeFormatterBuilder$ZoneTextPrinterParser::cache)->get(id)));
	$var($Map, perLocale, nullptr);
	bool var$0 = ref == nullptr || ($assign(perLocale, $cast($Map, $nc(ref)->get()))) == nullptr;
	if (var$0 || ($assign(names, $cast($StringArray, $nc(perLocale)->get(locale)))) == nullptr) {
		$assign(names, $TimeZoneNameUtility::retrieveDisplayNames(id, locale));
		if (names == nullptr) {
			return nullptr;
		}
		$assign(names, $fcast($StringArray, $Arrays::copyOfRange(names, 0, 7)));
		names->set(5, $($TimeZoneNameUtility::retrieveGenericDisplayName(id, $TimeZone::LONG, locale)));
		if (names->get(5) == nullptr) {
			names->set(5, names->get(0));
		}
		names->set(6, $($TimeZoneNameUtility::retrieveGenericDisplayName(id, $TimeZone::SHORT, locale)));
		if (names->get(6) == nullptr) {
			names->set(6, names->get(0));
		}
		if (perLocale == nullptr) {
			$assign(perLocale, static_cast<$Map*>(static_cast<$AbstractMap*>($new($ConcurrentHashMap))));
		}
		perLocale->put(locale, names);
		$nc(DateTimeFormatterBuilder$ZoneTextPrinterParser::cache)->put(id, $$new($SoftReference, perLocale));
	}
	switch (type) {
	case DateTimeFormatterBuilder$ZoneTextPrinterParser::STD:
		{
			return $nc(names)->get(this->textStyle->zoneNameStyleIndex() + 1);
		}
	case DateTimeFormatterBuilder$ZoneTextPrinterParser::DST:
		{
			return $nc(names)->get(this->textStyle->zoneNameStyleIndex() + 3);
		}
	}
	return $nc(names)->get(this->textStyle->zoneNameStyleIndex() + 5);
}

bool DateTimeFormatterBuilder$ZoneTextPrinterParser::format($DateTimePrintContext* context, $StringBuilder* buf) {
	$useLocalCurrentObjectStackCache();
	$var($ZoneId, zone, $cast($ZoneId, $nc(context)->getValue($($TemporalQueries::zoneId()))));
	if (zone == nullptr) {
		return false;
	}
	$var($String, zname, $nc(zone)->getId());
	if (!($instanceOf($ZoneOffset, zone))) {
		$var($TemporalAccessor, dt, context->getTemporal());
		int32_t type = DateTimeFormatterBuilder$ZoneTextPrinterParser::GENERIC;
		if (!this->isGeneric) {
			$init($ChronoField);
			if ($nc(dt)->isSupported($ChronoField::INSTANT_SECONDS)) {
				type = $nc($(zone->getRules()))->isDaylightSavings($($Instant::from(dt))) ? DateTimeFormatterBuilder$ZoneTextPrinterParser::DST : DateTimeFormatterBuilder$ZoneTextPrinterParser::STD;
			} else {
				bool var$1 = dt->isSupported($ChronoField::EPOCH_DAY);
				if (var$1 && dt->isSupported($ChronoField::NANO_OF_DAY)) {
					$var($LocalDate, date, $LocalDate::ofEpochDay(dt->getLong($ChronoField::EPOCH_DAY)));
					$var($LocalTime, time, $LocalTime::ofNanoOfDay(dt->getLong($ChronoField::NANO_OF_DAY)));
					$var($LocalDateTime, ldt, $cast($LocalDateTime, $nc(date)->atTime(time)));
					if ($nc($(zone->getRules()))->getTransition(ldt) == nullptr) {
						type = $nc($(zone->getRules()))->isDaylightSavings($($nc($($cast($ZonedDateTime, $nc(ldt)->atZone(zone))))->toInstant())) ? DateTimeFormatterBuilder$ZoneTextPrinterParser::DST : DateTimeFormatterBuilder$ZoneTextPrinterParser::STD;
					}
				}
			}
		}
		$var($String, name, getDisplayName(zname, type, $(context->getLocale())));
		if (name != nullptr) {
			$assign(zname, name);
		}
	}
	$nc(buf)->append(zname);
	return true;
}

$DateTimeFormatterBuilder$PrefixTree* DateTimeFormatterBuilder$ZoneTextPrinterParser::getTree($DateTimeParseContext* context) {
	$useLocalCurrentObjectStackCache();
	$init($TextStyle);
	if (this->textStyle == $TextStyle::NARROW) {
		return $DateTimeFormatterBuilder$ZoneIdPrinterParser::getTree(context);
	}
	$var($Locale, locale, $nc(context)->getLocale());
	bool isCaseSensitive = context->isCaseSensitive();
	$var($Set, regionIds, $new($HashSet, $(static_cast<$Collection*>($ZoneRulesProvider::getAvailableZoneIds()))));
	$var($Set, nonRegionIds, $new($HashSet, 64));
	int32_t regionIdsSize = regionIds->size();
	$var($Map, cached, isCaseSensitive ? this->cachedTree : this->cachedTreeCI);
	$var($Map$Entry, entry, nullptr);
	$var($DateTimeFormatterBuilder$PrefixTree, tree, nullptr);
	$var($StringArray2, zoneStrings, nullptr);
	bool var$0 = ($assign(entry, $cast($Map$Entry, $nc(cached)->get(locale)))) == nullptr;
	if (!var$0) {
		bool var$1 = $nc(($cast($Integer, $($nc(entry)->getKey()))))->intValue() != regionIdsSize;
		var$0 = (var$1 || ($assign(tree, $cast($DateTimeFormatterBuilder$PrefixTree, $nc(($cast($SoftReference, $($nc(entry)->getValue()))))->get()))) == nullptr);
	}
	if (var$0) {
		$assign(tree, $DateTimeFormatterBuilder$PrefixTree::newTree(context));
		$assign(zoneStrings, $TimeZoneNameUtility::getZoneStrings(locale));
		{
			$var($StringArray2, arr$, zoneStrings);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($StringArray, names, arr$->get(i$));
				{
					$var($String, zid, $nc(names)->get(0));
					if (!regionIds->remove(zid)) {
						nonRegionIds->add(zid);
						continue;
					}
					$nc(tree)->add(zid, zid);
					$assign(zid, $ZoneName::toZid(zid, locale));
					int32_t i = this->textStyle == $TextStyle::FULL ? 1 : 2;
					for (; i < names->length; i += 2) {
						tree->add(names->get(i), zid);
					}
				}
			}
		}
		$var($DateTimeFormatterBuilder$PrefixTree, t, tree);
		$nc($($nc($(regionIds->stream()))->filter(static_cast<$Predicate*>($$new(DateTimeFormatterBuilder$ZoneTextPrinterParser$$Lambda$lambda$getTree$0)))))->forEach(static_cast<$Consumer*>($$new(DateTimeFormatterBuilder$ZoneTextPrinterParser$$Lambda$lambda$getTree$1$1, this, locale, t)));
		if (this->preferredZones != nullptr) {
			{
				$var($StringArray2, arr$, zoneStrings);
				int32_t len$ = $nc(arr$)->length;
				int32_t i$ = 0;
				for (; i$ < len$; ++i$) {
					$var($StringArray, names, arr$->get(i$));
					{
						$var($String, zid, $nc(names)->get(0));
						bool var$2 = !$nc(this->preferredZones)->contains(zid);
						if (var$2 || nonRegionIds->contains(zid)) {
							continue;
						}
						int32_t i = this->textStyle == $TextStyle::FULL ? 1 : 2;
						for (; i < names->length; i += 2) {
							$nc(tree)->add(names->get(i), zid);
						}
					}
				}
			}
		}
		$var($Object, var$3, $of($Integer::valueOf(regionIdsSize)));
		$nc(cached)->put(locale, $$new($AbstractMap$SimpleImmutableEntry, var$3, $$new($SoftReference, tree)));
	}
	return tree;
}

void DateTimeFormatterBuilder$ZoneTextPrinterParser::lambda$getTree$1($Locale* locale, $DateTimeFormatterBuilder$PrefixTree* t, $String* cid) {
	$var($StringArray, cidNames, $TimeZoneNameUtility::retrieveDisplayNames(cid, locale));
	$init($TextStyle);
	int32_t i = this->textStyle == $TextStyle::FULL ? 1 : 2;
	for (; i < $nc(cidNames)->length; i += 2) {
		if (cidNames->get(i) != nullptr && !$nc(cidNames->get(i))->isEmpty()) {
			$nc(t)->add(cidNames->get(i), cid);
		}
	}
}

bool DateTimeFormatterBuilder$ZoneTextPrinterParser::lambda$getTree$0($String* zid) {
	$init(DateTimeFormatterBuilder$ZoneTextPrinterParser);
	bool var$0 = !$nc(zid)->startsWith("Etc"_s);
	return var$0 && !zid->startsWith("GMT"_s);
}

void clinit$DateTimeFormatterBuilder$ZoneTextPrinterParser($Class* class$) {
	$assignStatic(DateTimeFormatterBuilder$ZoneTextPrinterParser::cache, static_cast<$Map*>(static_cast<$AbstractMap*>($new($ConcurrentHashMap))));
}

DateTimeFormatterBuilder$ZoneTextPrinterParser::DateTimeFormatterBuilder$ZoneTextPrinterParser() {
}

$Class* DateTimeFormatterBuilder$ZoneTextPrinterParser::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(DateTimeFormatterBuilder$ZoneTextPrinterParser$$Lambda$lambda$getTree$0::classInfo$.name)) {
			return DateTimeFormatterBuilder$ZoneTextPrinterParser$$Lambda$lambda$getTree$0::load$(name, initialize);
		}
		if (name->equals(DateTimeFormatterBuilder$ZoneTextPrinterParser$$Lambda$lambda$getTree$1$1::classInfo$.name)) {
			return DateTimeFormatterBuilder$ZoneTextPrinterParser$$Lambda$lambda$getTree$1$1::load$(name, initialize);
		}
	}
	$loadClass(DateTimeFormatterBuilder$ZoneTextPrinterParser, name, initialize, &_DateTimeFormatterBuilder$ZoneTextPrinterParser_ClassInfo_, clinit$DateTimeFormatterBuilder$ZoneTextPrinterParser, allocate$DateTimeFormatterBuilder$ZoneTextPrinterParser);
	return class$;
}

$Class* DateTimeFormatterBuilder$ZoneTextPrinterParser::class$ = nullptr;

		} // format
	} // time
} // java