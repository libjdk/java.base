#include <sun/util/cldr/CLDRLocaleProviderAdapter.h>

#include <java/io/Serializable.h>
#include <java/lang/InternalError.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/PrivilegedActionException.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/text/spi/BreakIteratorProvider.h>
#include <java/text/spi/CollatorProvider.h>
#include <java/util/AbstractMap.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Optional.h>
#include <java/util/ServiceLoader.h>
#include <java/util/Set.h>
#include <java/util/StringTokenizer.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/spi/CalendarDataProvider.h>
#include <java/util/spi/CalendarNameProvider.h>
#include <java/util/spi/TimeZoneNameProvider.h>
#include <sun/util/cldr/CLDRBaseLocaleDataMetaInfo.h>
#include <sun/util/cldr/CLDRCalendarDataProviderImpl.h>
#include <sun/util/cldr/CLDRCalendarNameProviderImpl.h>
#include <sun/util/cldr/CLDRTimeZoneNameProviderImpl.h>
#include <sun/util/locale/provider/JRELocaleProviderAdapter.h>
#include <sun/util/locale/provider/LocaleDataMetaInfo.h>
#include <sun/util/locale/provider/LocaleProviderAdapter$Type.h>
#include <jcpp.h>

#undef CLDR
#undef ENGLISH
#undef ROOT
#undef US

using $LocaleArray = $Array<::java::util::Locale>;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $PrivilegedActionException = ::java::security::PrivilegedActionException;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $BreakIteratorProvider = ::java::text::spi::BreakIteratorProvider;
using $CollatorProvider = ::java::text::spi::CollatorProvider;
using $AbstractMap = ::java::util::AbstractMap;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Optional = ::java::util::Optional;
using $ServiceLoader = ::java::util::ServiceLoader;
using $Set = ::java::util::Set;
using $StringTokenizer = ::java::util::StringTokenizer;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $CalendarDataProvider = ::java::util::spi::CalendarDataProvider;
using $CalendarNameProvider = ::java::util::spi::CalendarNameProvider;
using $TimeZoneNameProvider = ::java::util::spi::TimeZoneNameProvider;
using $CLDRBaseLocaleDataMetaInfo = ::sun::util::cldr::CLDRBaseLocaleDataMetaInfo;
using $CLDRCalendarDataProviderImpl = ::sun::util::cldr::CLDRCalendarDataProviderImpl;
using $CLDRCalendarNameProviderImpl = ::sun::util::cldr::CLDRCalendarNameProviderImpl;
using $CLDRTimeZoneNameProviderImpl = ::sun::util::cldr::CLDRTimeZoneNameProviderImpl;
using $JRELocaleProviderAdapter = ::sun::util::locale::provider::JRELocaleProviderAdapter;
using $LocaleDataMetaInfo = ::sun::util::locale::provider::LocaleDataMetaInfo;
using $LocaleProviderAdapter$Type = ::sun::util::locale::provider::LocaleProviderAdapter$Type;

namespace sun {
	namespace util {
		namespace cldr {

class CLDRLocaleProviderAdapter$$Lambda$lambda$new$0 : public $PrivilegedExceptionAction {
	$class(CLDRLocaleProviderAdapter$$Lambda$lambda$new$0, $NO_CLASS_INIT, $PrivilegedExceptionAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(CLDRLocaleProviderAdapter::lambda$new$0());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<CLDRLocaleProviderAdapter$$Lambda$lambda$new$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo CLDRLocaleProviderAdapter$$Lambda$lambda$new$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(CLDRLocaleProviderAdapter$$Lambda$lambda$new$0, init$, void)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(CLDRLocaleProviderAdapter$$Lambda$lambda$new$0, run, $Object*)},
	{}
};
$ClassInfo CLDRLocaleProviderAdapter$$Lambda$lambda$new$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.util.cldr.CLDRLocaleProviderAdapter$$Lambda$lambda$new$0",
	"java.lang.Object",
	"java.security.PrivilegedExceptionAction",
	nullptr,
	methodInfos
};
$Class* CLDRLocaleProviderAdapter$$Lambda$lambda$new$0::load$($String* name, bool initialize) {
	$loadClass(CLDRLocaleProviderAdapter$$Lambda$lambda$new$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* CLDRLocaleProviderAdapter$$Lambda$lambda$new$0::class$ = nullptr;

class CLDRLocaleProviderAdapter$$Lambda$lambda$getCalendarDataProvider$1$1 : public $PrivilegedAction {
	$class(CLDRLocaleProviderAdapter$$Lambda$lambda$getCalendarDataProvider$1$1, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$(CLDRLocaleProviderAdapter* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* run() override {
		 return $of($nc(inst$)->lambda$getCalendarDataProvider$1());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<CLDRLocaleProviderAdapter$$Lambda$lambda$getCalendarDataProvider$1$1>());
	}
	CLDRLocaleProviderAdapter* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo CLDRLocaleProviderAdapter$$Lambda$lambda$getCalendarDataProvider$1$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(CLDRLocaleProviderAdapter$$Lambda$lambda$getCalendarDataProvider$1$1, inst$)},
	{}
};
$MethodInfo CLDRLocaleProviderAdapter$$Lambda$lambda$getCalendarDataProvider$1$1::methodInfos[3] = {
	{"<init>", "(Lsun/util/cldr/CLDRLocaleProviderAdapter;)V", nullptr, $PUBLIC, $method(CLDRLocaleProviderAdapter$$Lambda$lambda$getCalendarDataProvider$1$1, init$, void, CLDRLocaleProviderAdapter*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(CLDRLocaleProviderAdapter$$Lambda$lambda$getCalendarDataProvider$1$1, run, $Object*)},
	{}
};
$ClassInfo CLDRLocaleProviderAdapter$$Lambda$lambda$getCalendarDataProvider$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.util.cldr.CLDRLocaleProviderAdapter$$Lambda$lambda$getCalendarDataProvider$1$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* CLDRLocaleProviderAdapter$$Lambda$lambda$getCalendarDataProvider$1$1::load$($String* name, bool initialize) {
	$loadClass(CLDRLocaleProviderAdapter$$Lambda$lambda$getCalendarDataProvider$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* CLDRLocaleProviderAdapter$$Lambda$lambda$getCalendarDataProvider$1$1::class$ = nullptr;

class CLDRLocaleProviderAdapter$$Lambda$lambda$getCalendarNameProvider$2$2 : public $PrivilegedAction {
	$class(CLDRLocaleProviderAdapter$$Lambda$lambda$getCalendarNameProvider$2$2, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$(CLDRLocaleProviderAdapter* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* run() override {
		 return $of($nc(inst$)->lambda$getCalendarNameProvider$2());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<CLDRLocaleProviderAdapter$$Lambda$lambda$getCalendarNameProvider$2$2>());
	}
	CLDRLocaleProviderAdapter* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo CLDRLocaleProviderAdapter$$Lambda$lambda$getCalendarNameProvider$2$2::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(CLDRLocaleProviderAdapter$$Lambda$lambda$getCalendarNameProvider$2$2, inst$)},
	{}
};
$MethodInfo CLDRLocaleProviderAdapter$$Lambda$lambda$getCalendarNameProvider$2$2::methodInfos[3] = {
	{"<init>", "(Lsun/util/cldr/CLDRLocaleProviderAdapter;)V", nullptr, $PUBLIC, $method(CLDRLocaleProviderAdapter$$Lambda$lambda$getCalendarNameProvider$2$2, init$, void, CLDRLocaleProviderAdapter*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(CLDRLocaleProviderAdapter$$Lambda$lambda$getCalendarNameProvider$2$2, run, $Object*)},
	{}
};
$ClassInfo CLDRLocaleProviderAdapter$$Lambda$lambda$getCalendarNameProvider$2$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.util.cldr.CLDRLocaleProviderAdapter$$Lambda$lambda$getCalendarNameProvider$2$2",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* CLDRLocaleProviderAdapter$$Lambda$lambda$getCalendarNameProvider$2$2::load$($String* name, bool initialize) {
	$loadClass(CLDRLocaleProviderAdapter$$Lambda$lambda$getCalendarNameProvider$2$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* CLDRLocaleProviderAdapter$$Lambda$lambda$getCalendarNameProvider$2$2::class$ = nullptr;

class CLDRLocaleProviderAdapter$$Lambda$lambda$getTimeZoneNameProvider$3$3 : public $PrivilegedAction {
	$class(CLDRLocaleProviderAdapter$$Lambda$lambda$getTimeZoneNameProvider$3$3, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$(CLDRLocaleProviderAdapter* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* run() override {
		 return $of($nc(inst$)->lambda$getTimeZoneNameProvider$3());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<CLDRLocaleProviderAdapter$$Lambda$lambda$getTimeZoneNameProvider$3$3>());
	}
	CLDRLocaleProviderAdapter* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo CLDRLocaleProviderAdapter$$Lambda$lambda$getTimeZoneNameProvider$3$3::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(CLDRLocaleProviderAdapter$$Lambda$lambda$getTimeZoneNameProvider$3$3, inst$)},
	{}
};
$MethodInfo CLDRLocaleProviderAdapter$$Lambda$lambda$getTimeZoneNameProvider$3$3::methodInfos[3] = {
	{"<init>", "(Lsun/util/cldr/CLDRLocaleProviderAdapter;)V", nullptr, $PUBLIC, $method(CLDRLocaleProviderAdapter$$Lambda$lambda$getTimeZoneNameProvider$3$3, init$, void, CLDRLocaleProviderAdapter*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(CLDRLocaleProviderAdapter$$Lambda$lambda$getTimeZoneNameProvider$3$3, run, $Object*)},
	{}
};
$ClassInfo CLDRLocaleProviderAdapter$$Lambda$lambda$getTimeZoneNameProvider$3$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.util.cldr.CLDRLocaleProviderAdapter$$Lambda$lambda$getTimeZoneNameProvider$3$3",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* CLDRLocaleProviderAdapter$$Lambda$lambda$getTimeZoneNameProvider$3$3::load$($String* name, bool initialize) {
	$loadClass(CLDRLocaleProviderAdapter$$Lambda$lambda$getTimeZoneNameProvider$3$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* CLDRLocaleProviderAdapter$$Lambda$lambda$getTimeZoneNameProvider$3$3::class$ = nullptr;

$FieldInfo _CLDRLocaleProviderAdapter_FieldInfo_[] = {
	{"baseMetaInfo", "Lsun/util/cldr/CLDRBaseLocaleDataMetaInfo;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CLDRLocaleProviderAdapter, baseMetaInfo)},
	{"nonBaseMetaInfo", "Lsun/util/locale/provider/LocaleDataMetaInfo;", nullptr, $PRIVATE | $FINAL, $field(CLDRLocaleProviderAdapter, nonBaseMetaInfo)},
	{"parentLocalesMap", "Ljava/util/Map;", "Ljava/util/Map<Ljava/util/Locale;Ljava/util/Locale;>;", $PRIVATE | $STATIC | $VOLATILE, $staticField(CLDRLocaleProviderAdapter, parentLocalesMap)},
	{"langAliasesMap", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;", $PRIVATE | $STATIC | $VOLATILE, $staticField(CLDRLocaleProviderAdapter, langAliasesMap)},
	{"langAliasesCache", "Ljava/util/Map;", "Ljava/util/Map<Ljava/util/Locale;Ljava/util/Locale;>;", $PRIVATE | $STATIC | $FINAL, $staticField(CLDRLocaleProviderAdapter, langAliasesCache)},
	{}
};

$MethodInfo _CLDRLocaleProviderAdapter_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(CLDRLocaleProviderAdapter, init$, void)},
	{"applyAliases", "(Ljava/util/Locale;)Ljava/util/Locale;", nullptr, $PRIVATE | $STATIC, $staticMethod(CLDRLocaleProviderAdapter, applyAliases, $Locale*, $Locale*)},
	{"applyParentLocales", "(Ljava/lang/String;Ljava/util/List;)Ljava/util/List;", "(Ljava/lang/String;Ljava/util/List<Ljava/util/Locale;>;)Ljava/util/List<Ljava/util/Locale;>;", $PRIVATE, $method(CLDRLocaleProviderAdapter, applyParentLocales, $List*, $String*, $List*)},
	{"canonicalTZID", "(Ljava/lang/String;)Ljava/util/Optional;", "(Ljava/lang/String;)Ljava/util/Optional<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(CLDRLocaleProviderAdapter, canonicalTZID, $Optional*, $String*)},
	{"createLanguageTagSet", "(Ljava/lang/String;)Ljava/util/Set;", "(Ljava/lang/String;)Ljava/util/Set<Ljava/lang/String;>;", $PROTECTED, $virtualMethod(CLDRLocaleProviderAdapter, createLanguageTagSet, $Set*, $String*)},
	{"getAdapterType", "()Lsun/util/locale/provider/LocaleProviderAdapter$Type;", nullptr, $PUBLIC, $virtualMethod(CLDRLocaleProviderAdapter, getAdapterType, $LocaleProviderAdapter$Type*)},
	{"getAvailableLocales", "()[Ljava/util/Locale;", nullptr, $PUBLIC, $virtualMethod(CLDRLocaleProviderAdapter, getAvailableLocales, $LocaleArray*)},
	{"getBreakIteratorProvider", "()Ljava/text/spi/BreakIteratorProvider;", nullptr, $PUBLIC, $virtualMethod(CLDRLocaleProviderAdapter, getBreakIteratorProvider, $BreakIteratorProvider*)},
	{"getCalendarDataProvider", "()Ljava/util/spi/CalendarDataProvider;", nullptr, $PUBLIC, $virtualMethod(CLDRLocaleProviderAdapter, getCalendarDataProvider, $CalendarDataProvider*)},
	{"getCalendarNameProvider", "()Ljava/util/spi/CalendarNameProvider;", nullptr, $PUBLIC, $virtualMethod(CLDRLocaleProviderAdapter, getCalendarNameProvider, $CalendarNameProvider*)},
	{"getCandidateLocales", "(Ljava/lang/String;Ljava/util/Locale;)Ljava/util/List;", "(Ljava/lang/String;Ljava/util/Locale;)Ljava/util/List<Ljava/util/Locale;>;", $PUBLIC, $virtualMethod(CLDRLocaleProviderAdapter, getCandidateLocales, $List*, $String*, $Locale*)},
	{"getCollatorProvider", "()Ljava/text/spi/CollatorProvider;", nullptr, $PUBLIC, $virtualMethod(CLDRLocaleProviderAdapter, getCollatorProvider, $CollatorProvider*)},
	{"getEquivalentLoc", "(Ljava/util/Locale;)Ljava/util/Locale;", nullptr, $PRIVATE | $STATIC, $staticMethod(CLDRLocaleProviderAdapter, getEquivalentLoc, $Locale*, $Locale*)},
	{"getParentLocale", "(Ljava/util/Locale;)Ljava/util/Locale;", nullptr, $PRIVATE | $STATIC, $staticMethod(CLDRLocaleProviderAdapter, getParentLocale, $Locale*, $Locale*)},
	{"getTimeZoneNameProvider", "()Ljava/util/spi/TimeZoneNameProvider;", nullptr, $PUBLIC, $virtualMethod(CLDRLocaleProviderAdapter, getTimeZoneNameProvider, $TimeZoneNameProvider*)},
	{"isSupportedProviderLocale", "(Ljava/util/Locale;Ljava/util/Set;)Z", "(Ljava/util/Locale;Ljava/util/Set<Ljava/lang/String;>;)Z", $PUBLIC, $virtualMethod(CLDRLocaleProviderAdapter, isSupportedProviderLocale, bool, $Locale*, $Set*)},
	{"lambda$getCalendarDataProvider$1", "()Ljava/util/spi/CalendarDataProvider;", nullptr, $PRIVATE | $SYNTHETIC, $method(CLDRLocaleProviderAdapter, lambda$getCalendarDataProvider$1, $CalendarDataProvider*)},
	{"lambda$getCalendarNameProvider$2", "()Ljava/util/spi/CalendarNameProvider;", nullptr, $PRIVATE | $SYNTHETIC, $method(CLDRLocaleProviderAdapter, lambda$getCalendarNameProvider$2, $CalendarNameProvider*)},
	{"lambda$getTimeZoneNameProvider$3", "()Ljava/util/spi/TimeZoneNameProvider;", nullptr, $PRIVATE | $SYNTHETIC, $method(CLDRLocaleProviderAdapter, lambda$getTimeZoneNameProvider$3, $TimeZoneNameProvider*)},
	{"lambda$new$0", "()Lsun/util/locale/provider/LocaleDataMetaInfo;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(CLDRLocaleProviderAdapter, lambda$new$0, $LocaleDataMetaInfo*), "java.lang.Exception"},
	{}
};

$ClassInfo _CLDRLocaleProviderAdapter_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.util.cldr.CLDRLocaleProviderAdapter",
	"sun.util.locale.provider.JRELocaleProviderAdapter",
	nullptr,
	_CLDRLocaleProviderAdapter_FieldInfo_,
	_CLDRLocaleProviderAdapter_MethodInfo_
};

$Object* allocate$CLDRLocaleProviderAdapter($Class* clazz) {
	return $of($alloc(CLDRLocaleProviderAdapter));
}

$CLDRBaseLocaleDataMetaInfo* CLDRLocaleProviderAdapter::baseMetaInfo = nullptr;
$volatile($Map*) CLDRLocaleProviderAdapter::parentLocalesMap = nullptr;
$volatile($Map*) CLDRLocaleProviderAdapter::langAliasesMap = nullptr;
$Map* CLDRLocaleProviderAdapter::langAliasesCache = nullptr;

void CLDRLocaleProviderAdapter::init$() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$JRELocaleProviderAdapter::init$();
	$var($LocaleDataMetaInfo, nbmi, nullptr);
	try {
		$assign(nbmi, $cast($LocaleDataMetaInfo, $AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new(CLDRLocaleProviderAdapter$$Lambda$lambda$new$0)))));
	} catch ($PrivilegedActionException& pae) {
		$throwNew($InternalError, $(pae->getCause()));
	}
	$set(this, nonBaseMetaInfo, nbmi);
}

$LocaleProviderAdapter$Type* CLDRLocaleProviderAdapter::getAdapterType() {
	$init($LocaleProviderAdapter$Type);
	return $LocaleProviderAdapter$Type::CLDR;
}

$BreakIteratorProvider* CLDRLocaleProviderAdapter::getBreakIteratorProvider() {
	return nullptr;
}

$CalendarDataProvider* CLDRLocaleProviderAdapter::getCalendarDataProvider() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (this->calendarDataProvider == nullptr) {
		$var($CalendarDataProvider, provider, $cast($CalendarDataProvider, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(CLDRLocaleProviderAdapter$$Lambda$lambda$getCalendarDataProvider$1$1, this)))));
		$synchronized(this) {
			if (this->calendarDataProvider == nullptr) {
				$set(this, calendarDataProvider, provider);
			}
		}
	}
	return this->calendarDataProvider;
}

$CalendarNameProvider* CLDRLocaleProviderAdapter::getCalendarNameProvider() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (this->calendarNameProvider == nullptr) {
		$var($CalendarNameProvider, provider, $cast($CalendarNameProvider, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(CLDRLocaleProviderAdapter$$Lambda$lambda$getCalendarNameProvider$2$2, this)))));
		$synchronized(this) {
			if (this->calendarNameProvider == nullptr) {
				$set(this, calendarNameProvider, provider);
			}
		}
	}
	return this->calendarNameProvider;
}

$CollatorProvider* CLDRLocaleProviderAdapter::getCollatorProvider() {
	return nullptr;
}

$TimeZoneNameProvider* CLDRLocaleProviderAdapter::getTimeZoneNameProvider() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (this->timeZoneNameProvider == nullptr) {
		$var($TimeZoneNameProvider, provider, $cast($TimeZoneNameProvider, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(CLDRLocaleProviderAdapter$$Lambda$lambda$getTimeZoneNameProvider$3$3, this)))));
		$synchronized(this) {
			if (this->timeZoneNameProvider == nullptr) {
				$set(this, timeZoneNameProvider, provider);
			}
		}
	}
	return this->timeZoneNameProvider;
}

$LocaleArray* CLDRLocaleProviderAdapter::getAvailableLocales() {
	$useLocalCurrentObjectStackCache();
	$var($Set, all, createLanguageTagSet("AvailableLocales"_s));
	$var($LocaleArray, locs, $new($LocaleArray, $nc(all)->size()));
	int32_t index = 0;
	{
		$var($Iterator, i$, all->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, tag, $cast($String, i$->next()));
			{
				locs->set(index++, $($Locale::forLanguageTag(tag)));
			}
		}
	}
	return locs;
}

$Locale* CLDRLocaleProviderAdapter::applyAliases($Locale* loc) {
	$init(CLDRLocaleProviderAdapter);
	$useLocalCurrentObjectStackCache();
	if ($nc(CLDRLocaleProviderAdapter::langAliasesMap)->isEmpty()) {
		$assignStatic(CLDRLocaleProviderAdapter::langAliasesMap, $nc(CLDRLocaleProviderAdapter::baseMetaInfo)->getLanguageAliasMap());
	}
	$var($Locale, locale, $cast($Locale, $nc(CLDRLocaleProviderAdapter::langAliasesCache)->get(loc)));
	if (locale == nullptr) {
		$var($String, locTag, $nc(loc)->toLanguageTag());
		$var($Locale, aliasLocale, $nc(CLDRLocaleProviderAdapter::langAliasesMap)->containsKey(locTag) ? $Locale::forLanguageTag($cast($String, $($nc(CLDRLocaleProviderAdapter::langAliasesMap)->get(locTag)))) : loc);
		$nc(CLDRLocaleProviderAdapter::langAliasesCache)->putIfAbsent(loc, aliasLocale);
		return aliasLocale;
	} else {
		return locale;
	}
}

$Set* CLDRLocaleProviderAdapter::createLanguageTagSet($String* category$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($String, category, category$renamed);
	$assign(category, "AvailableLocales"_s);
	$var($String, supportedLocaleString, $nc(CLDRLocaleProviderAdapter::baseMetaInfo)->availableLanguageTags(category));
	$var($String, nonBaseTags, nullptr);
	if (this->nonBaseMetaInfo != nullptr) {
		$assign(nonBaseTags, $nc(this->nonBaseMetaInfo)->availableLanguageTags(category));
	}
	if (nonBaseTags != nullptr) {
		if (supportedLocaleString != nullptr) {
			$plusAssign(supportedLocaleString, $$str({" "_s, nonBaseTags}));
		} else {
			$assign(supportedLocaleString, nonBaseTags);
		}
	}
	if (supportedLocaleString == nullptr) {
		return $Collections::emptySet();
	}
	$var($StringTokenizer, tokens, $new($StringTokenizer, supportedLocaleString));
	$var($Set, tagset, $new($HashSet, (tokens->countTokens() * 4 + 2) / 3));
	while (tokens->hasMoreTokens()) {
		tagset->add($(tokens->nextToken()));
	}
	return tagset;
}

$List* CLDRLocaleProviderAdapter::getCandidateLocales($String* baseName, $Locale* locale) {
	$useLocalCurrentObjectStackCache();
	$var($List, candidates, $JRELocaleProviderAdapter::getCandidateLocales(baseName, $(applyAliases(locale))));
	return applyParentLocales(baseName, candidates);
}

$List* CLDRLocaleProviderAdapter::applyParentLocales($String* baseName, $List* candidates) {
	$useLocalCurrentObjectStackCache();
	for (int32_t i = 0; i < $nc(candidates)->size(); ++i) {
		$var($Locale, l, $cast($Locale, candidates->get(i)));
		$init($Locale);
		if (!$nc(l)->equals($Locale::ROOT)) {
			$var($Locale, p, getParentLocale(l));
			if (p != nullptr && !$nc(($cast($Locale, $(candidates->get(i + 1)))))->equals(p)) {
				$var($List, applied, candidates->subList(0, i + 1));
				if ($nc(applied)->contains(p)) {
					continue;
				}
				$nc(applied)->addAll($(applyParentLocales(baseName, $($JRELocaleProviderAdapter::getCandidateLocales(baseName, p)))));
				return applied;
			}
		}
	}
	return candidates;
}

$Locale* CLDRLocaleProviderAdapter::getParentLocale($Locale* locale) {
	$init(CLDRLocaleProviderAdapter);
	$useLocalCurrentObjectStackCache();
	$var($Locale, parent, $cast($Locale, $nc(CLDRLocaleProviderAdapter::parentLocalesMap)->get(locale)));
	if (parent == nullptr) {
		$var($String, tag, $nc(locale)->toLanguageTag());
		{
			$var($Iterator, i$, $nc($($nc($($nc(CLDRLocaleProviderAdapter::baseMetaInfo)->parentLocales()))->entrySet()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
				{
					if ($Arrays::binarySearch($cast($ObjectArray, $($nc(entry)->getValue())), $of(tag)) >= 0) {
						$assign(parent, $cast($Locale, $nc(entry)->getKey()));
						break;
					}
				}
			}
		}
		if (parent == nullptr) {
			$assign(parent, locale);
		}
		$nc(CLDRLocaleProviderAdapter::parentLocalesMap)->putIfAbsent(locale, parent);
	}
	if ($nc(locale)->equals(parent)) {
		$assign(parent, nullptr);
	}
	return parent;
}

$Locale* CLDRLocaleProviderAdapter::getEquivalentLoc($Locale* locale) {
	$init(CLDRLocaleProviderAdapter);
	$useLocalCurrentObjectStackCache();
	$var($String, s10815$, $nc(locale)->toString());
	int32_t tmp10815$ = -1;
	switch ($nc(s10815$)->hashCode()) {
	case 3521:
		{
			if (s10815$->equals("no"_s)) {
				tmp10815$ = 0;
			}
			break;
		}
	case 0x0641FCFF:
		{
			if (s10815$->equals("no_NO"_s)) {
				tmp10815$ = 1;
			}
			break;
		}
	}

	$var($Locale, var$0, nullptr)
	switch (tmp10815$) {
	case 0:
		{}
	case 1:
		{
			$assign(var$0, $Locale::forLanguageTag("nb"_s));
			break;
		}
	default:
		{
			$assign(var$0, applyAliases(locale));
			break;
		}
	}
	return var$0;
}

bool CLDRLocaleProviderAdapter::isSupportedProviderLocale($Locale* locale, $Set* langtags) {
	$useLocalCurrentObjectStackCache();
	$init($Locale);
	bool var$1 = $nc($Locale::ROOT)->equals(locale);
	bool var$0 = var$1 || $nc(langtags)->contains($($nc($($nc(locale)->stripExtensions()))->toLanguageTag()));
	return var$0 || $nc(langtags)->contains($($nc($(getEquivalentLoc(locale)))->toLanguageTag()));
}

$Optional* CLDRLocaleProviderAdapter::canonicalTZID($String* id) {
	$useLocalCurrentObjectStackCache();
	return $Optional::ofNullable($cast($String, $($nc($($nc(CLDRLocaleProviderAdapter::baseMetaInfo)->tzCanonicalIDs()))->get(id))));
}

$TimeZoneNameProvider* CLDRLocaleProviderAdapter::lambda$getTimeZoneNameProvider$3() {
	$useLocalCurrentObjectStackCache();
	$var($LocaleProviderAdapter$Type, var$0, getAdapterType());
	return $new($CLDRTimeZoneNameProviderImpl, var$0, $(getLanguageTagSet("TimeZoneNames"_s)));
}

$CalendarNameProvider* CLDRLocaleProviderAdapter::lambda$getCalendarNameProvider$2() {
	$useLocalCurrentObjectStackCache();
	$var($LocaleProviderAdapter$Type, var$0, getAdapterType());
	return $new($CLDRCalendarNameProviderImpl, var$0, $(getLanguageTagSet("FormatData"_s)));
}

$CalendarDataProvider* CLDRLocaleProviderAdapter::lambda$getCalendarDataProvider$1() {
	$useLocalCurrentObjectStackCache();
	$var($LocaleProviderAdapter$Type, var$0, getAdapterType());
	return $new($CLDRCalendarDataProviderImpl, var$0, $(getLanguageTagSet("CalendarData"_s)));
}

$LocaleDataMetaInfo* CLDRLocaleProviderAdapter::lambda$new$0() {
	$init(CLDRLocaleProviderAdapter);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	{
		$load($LocaleDataMetaInfo);
		$var($Iterator, i$, $nc($($ServiceLoader::loadInstalled($LocaleDataMetaInfo::class$)))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($LocaleDataMetaInfo, ldmi, $cast($LocaleDataMetaInfo, i$->next()));
			{
				$init($LocaleProviderAdapter$Type);
				if ($nc(ldmi)->getType() == $LocaleProviderAdapter$Type::CLDR) {
					return ldmi;
				}
			}
		}
	}
	return nullptr;
}

void clinit$CLDRLocaleProviderAdapter($Class* class$) {
	$assignStatic(CLDRLocaleProviderAdapter::baseMetaInfo, $new($CLDRBaseLocaleDataMetaInfo));
	{
		$assignStatic(CLDRLocaleProviderAdapter::parentLocalesMap, static_cast<$Map*>(static_cast<$AbstractMap*>($new($ConcurrentHashMap))));
		$assignStatic(CLDRLocaleProviderAdapter::langAliasesMap, static_cast<$Map*>(static_cast<$AbstractMap*>($new($ConcurrentHashMap))));
		$assignStatic(CLDRLocaleProviderAdapter::langAliasesCache, static_cast<$Map*>(static_cast<$AbstractMap*>($new($ConcurrentHashMap))));
		$init($Locale);
		$nc(CLDRLocaleProviderAdapter::parentLocalesMap)->put($Locale::ROOT, $Locale::ROOT);
		$nc(CLDRLocaleProviderAdapter::parentLocalesMap)->put($Locale::ENGLISH, $Locale::ENGLISH);
		$nc(CLDRLocaleProviderAdapter::parentLocalesMap)->put($Locale::US, $Locale::US);
	}
}

CLDRLocaleProviderAdapter::CLDRLocaleProviderAdapter() {
}

$Class* CLDRLocaleProviderAdapter::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(CLDRLocaleProviderAdapter$$Lambda$lambda$new$0::classInfo$.name)) {
			return CLDRLocaleProviderAdapter$$Lambda$lambda$new$0::load$(name, initialize);
		}
		if (name->equals(CLDRLocaleProviderAdapter$$Lambda$lambda$getCalendarDataProvider$1$1::classInfo$.name)) {
			return CLDRLocaleProviderAdapter$$Lambda$lambda$getCalendarDataProvider$1$1::load$(name, initialize);
		}
		if (name->equals(CLDRLocaleProviderAdapter$$Lambda$lambda$getCalendarNameProvider$2$2::classInfo$.name)) {
			return CLDRLocaleProviderAdapter$$Lambda$lambda$getCalendarNameProvider$2$2::load$(name, initialize);
		}
		if (name->equals(CLDRLocaleProviderAdapter$$Lambda$lambda$getTimeZoneNameProvider$3$3::classInfo$.name)) {
			return CLDRLocaleProviderAdapter$$Lambda$lambda$getTimeZoneNameProvider$3$3::load$(name, initialize);
		}
	}
	$loadClass(CLDRLocaleProviderAdapter, name, initialize, &_CLDRLocaleProviderAdapter_ClassInfo_, clinit$CLDRLocaleProviderAdapter, allocate$CLDRLocaleProviderAdapter);
	return class$;
}

$Class* CLDRLocaleProviderAdapter::class$ = nullptr;

		} // cldr
	} // util
} // sun