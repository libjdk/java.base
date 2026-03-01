#include <java/time/zone/ZoneRulesProvider.h>

#include <java/lang/ClassLoader.h>
#include <java/lang/SecurityException.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/time/zone/ZoneRules.h>
#include <java/time/zone/ZoneRulesException.h>
#include <java/time/zone/ZoneRulesProvider$1.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/NavigableMap.h>
#include <java/util/Objects.h>
#include <java/util/ServiceConfigurationError.h>
#include <java/util/ServiceLoader.h>
#include <java/util/Set.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/concurrent/ConcurrentMap.h>
#include <java/util/concurrent/CopyOnWriteArrayList.h>
#include <jcpp.h>

#undef PROVIDERS
#undef ZONES
#undef ZONE_IDS

using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $SecurityException = ::java::lang::SecurityException;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $ZoneRules = ::java::time::zone::ZoneRules;
using $ZoneRulesException = ::java::time::zone::ZoneRulesException;
using $ZoneRulesProvider$1 = ::java::time::zone::ZoneRulesProvider$1;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $NavigableMap = ::java::util::NavigableMap;
using $Objects = ::java::util::Objects;
using $ServiceConfigurationError = ::java::util::ServiceConfigurationError;
using $ServiceLoader = ::java::util::ServiceLoader;
using $Set = ::java::util::Set;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $ConcurrentMap = ::java::util::concurrent::ConcurrentMap;
using $CopyOnWriteArrayList = ::java::util::concurrent::CopyOnWriteArrayList;

namespace java {
	namespace time {
		namespace zone {

$FieldInfo _ZoneRulesProvider_FieldInfo_[] = {
	{"PROVIDERS", "Ljava/util/concurrent/CopyOnWriteArrayList;", "Ljava/util/concurrent/CopyOnWriteArrayList<Ljava/time/zone/ZoneRulesProvider;>;", $PRIVATE | $STATIC | $FINAL, $staticField(ZoneRulesProvider, PROVIDERS)},
	{"ZONES", "Ljava/util/concurrent/ConcurrentMap;", "Ljava/util/concurrent/ConcurrentMap<Ljava/lang/String;Ljava/time/zone/ZoneRulesProvider;>;", $PRIVATE | $STATIC | $FINAL, $staticField(ZoneRulesProvider, ZONES)},
	{"ZONE_IDS", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE | $STATIC | $VOLATILE, $staticField(ZoneRulesProvider, ZONE_IDS)},
	{}
};

$MethodInfo _ZoneRulesProvider_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PROTECTED, $method(ZoneRulesProvider, init$, void)},
	{"getAvailableZoneIds", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC | $STATIC, $staticMethod(ZoneRulesProvider, getAvailableZoneIds, $Set*)},
	{"getProvider", "(Ljava/lang/String;)Ljava/time/zone/ZoneRulesProvider;", nullptr, $PRIVATE | $STATIC, $staticMethod(ZoneRulesProvider, getProvider, ZoneRulesProvider*, $String*)},
	{"getRules", "(Ljava/lang/String;Z)Ljava/time/zone/ZoneRules;", nullptr, $PUBLIC | $STATIC, $staticMethod(ZoneRulesProvider, getRules, $ZoneRules*, $String*, bool)},
	{"getVersions", "(Ljava/lang/String;)Ljava/util/NavigableMap;", "(Ljava/lang/String;)Ljava/util/NavigableMap<Ljava/lang/String;Ljava/time/zone/ZoneRules;>;", $PUBLIC | $STATIC, $staticMethod(ZoneRulesProvider, getVersions, $NavigableMap*, $String*)},
	{"provideRefresh", "()Z", nullptr, $PROTECTED, $virtualMethod(ZoneRulesProvider, provideRefresh, bool)},
	{"provideRules", "(Ljava/lang/String;Z)Ljava/time/zone/ZoneRules;", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(ZoneRulesProvider, provideRules, $ZoneRules*, $String*, bool)},
	{"provideVersions", "(Ljava/lang/String;)Ljava/util/NavigableMap;", "(Ljava/lang/String;)Ljava/util/NavigableMap<Ljava/lang/String;Ljava/time/zone/ZoneRules;>;", $PROTECTED | $ABSTRACT, $virtualMethod(ZoneRulesProvider, provideVersions, $NavigableMap*, $String*)},
	{"provideZoneIds", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PROTECTED | $ABSTRACT, $virtualMethod(ZoneRulesProvider, provideZoneIds, $Set*)},
	{"refresh", "()Z", nullptr, $PUBLIC | $STATIC, $staticMethod(ZoneRulesProvider, refresh, bool)},
	{"registerProvider", "(Ljava/time/zone/ZoneRulesProvider;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(ZoneRulesProvider, registerProvider, void, ZoneRulesProvider*)},
	{"registerProvider0", "(Ljava/time/zone/ZoneRulesProvider;)V", nullptr, $PRIVATE | $STATIC | $SYNCHRONIZED, $staticMethod(ZoneRulesProvider, registerProvider0, void, ZoneRulesProvider*)},
	{}
};

$InnerClassInfo _ZoneRulesProvider_InnerClassesInfo_[] = {
	{"java.time.zone.ZoneRulesProvider$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ZoneRulesProvider_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"java.time.zone.ZoneRulesProvider",
	"java.lang.Object",
	nullptr,
	_ZoneRulesProvider_FieldInfo_,
	_ZoneRulesProvider_MethodInfo_,
	nullptr,
	nullptr,
	_ZoneRulesProvider_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.time.zone.ZoneRulesProvider$1"
};

$Object* allocate$ZoneRulesProvider($Class* clazz) {
	return $of($alloc(ZoneRulesProvider));
}

$CopyOnWriteArrayList* ZoneRulesProvider::PROVIDERS = nullptr;
$ConcurrentMap* ZoneRulesProvider::ZONES = nullptr;
$volatile($Set*) ZoneRulesProvider::ZONE_IDS = nullptr;

$Set* ZoneRulesProvider::getAvailableZoneIds() {
	$init(ZoneRulesProvider);
	return ZoneRulesProvider::ZONE_IDS;
}

$ZoneRules* ZoneRulesProvider::getRules($String* zoneId, bool forCaching) {
	$init(ZoneRulesProvider);
	$Objects::requireNonNull($of(zoneId), "zoneId"_s);
	return $nc($(getProvider(zoneId)))->provideRules(zoneId, forCaching);
}

$NavigableMap* ZoneRulesProvider::getVersions($String* zoneId) {
	$init(ZoneRulesProvider);
	$Objects::requireNonNull($of(zoneId), "zoneId"_s);
	return $nc($(getProvider(zoneId)))->provideVersions(zoneId);
}

ZoneRulesProvider* ZoneRulesProvider::getProvider($String* zoneId) {
	$init(ZoneRulesProvider);
	$useLocalCurrentObjectStackCache();
	$var(ZoneRulesProvider, provider, $cast(ZoneRulesProvider, $nc(ZoneRulesProvider::ZONES)->get(zoneId)));
	if (provider == nullptr) {
		if ($nc(ZoneRulesProvider::ZONES)->isEmpty()) {
			$throwNew($ZoneRulesException, "No time-zone data files registered"_s);
		}
		$throwNew($ZoneRulesException, $$str({"Unknown time-zone ID: "_s, zoneId}));
	}
	return provider;
}

void ZoneRulesProvider::registerProvider(ZoneRulesProvider* provider) {
	$init(ZoneRulesProvider);
	$Objects::requireNonNull($of(provider), "provider"_s);
	registerProvider0(provider);
	$nc(ZoneRulesProvider::PROVIDERS)->add(provider);
}

void ZoneRulesProvider::registerProvider0(ZoneRulesProvider* provider) {
	$load(ZoneRulesProvider);
	$synchronized(class$) {
		$init(ZoneRulesProvider);
		$useLocalCurrentObjectStackCache();
		{
			$var($Iterator, i$, $nc($($nc(provider)->provideZoneIds()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($String, zoneId, $cast($String, i$->next()));
				{
					$Objects::requireNonNull($of(zoneId), "zoneId"_s);
					$var(ZoneRulesProvider, old, $cast(ZoneRulesProvider, $nc(ZoneRulesProvider::ZONES)->putIfAbsent(zoneId, provider)));
					if (old != nullptr) {
						$throwNew($ZoneRulesException, $$str({"Unable to register zone as one already registered with that ID: "_s, zoneId, ", currently loading from provider: "_s, provider}));
					}
				}
			}
		}
		$var($Set, combinedSet, $new($HashSet, $(static_cast<$Collection*>($nc(ZoneRulesProvider::ZONES)->keySet()))));
		$assignStatic(ZoneRulesProvider::ZONE_IDS, $Collections::unmodifiableSet(combinedSet));
	}
}

bool ZoneRulesProvider::refresh() {
	$init(ZoneRulesProvider);
	$useLocalCurrentObjectStackCache();
	bool changed = false;
	{
		$var($Iterator, i$, $nc(ZoneRulesProvider::PROVIDERS)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var(ZoneRulesProvider, provider, $cast(ZoneRulesProvider, i$->next()));
			{
				changed |= $nc(provider)->provideRefresh();
			}
		}
	}
	return changed;
}

void ZoneRulesProvider::init$() {
}

bool ZoneRulesProvider::provideRefresh() {
	return false;
}

void clinit$ZoneRulesProvider($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$assignStatic(ZoneRulesProvider::PROVIDERS, $new($CopyOnWriteArrayList));
	$assignStatic(ZoneRulesProvider::ZONES, $new($ConcurrentHashMap, 512, 0.75f, 2));
	{
		$var($List, loaded, $new($ArrayList));
		$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($ZoneRulesProvider$1, loaded)));
		$var($ServiceLoader, sl, $ServiceLoader::load(ZoneRulesProvider::class$, $($ClassLoader::getSystemClassLoader())));
		$var($Iterator, it, $nc(sl)->iterator());
		while ($nc(it)->hasNext()) {
			$var(ZoneRulesProvider, provider, nullptr);
			try {
				$assign(provider, $cast(ZoneRulesProvider, it->next()));
			} catch ($ServiceConfigurationError& ex) {
				if ($instanceOf($SecurityException, $(ex->getCause()))) {
					continue;
				}
				$throw(ex);
			}
			bool found = false;
			{
				$var($Iterator, i$, loaded->iterator());
				for (; $nc(i$)->hasNext();) {
					$var(ZoneRulesProvider, p, $cast(ZoneRulesProvider, i$->next()));
					{
						if ($nc($of(p))->getClass() == $nc($of(provider))->getClass()) {
							found = true;
						}
					}
				}
			}
			if (!found) {
				ZoneRulesProvider::registerProvider0(provider);
				loaded->add(provider);
			}
		}
		$nc(ZoneRulesProvider::PROVIDERS)->addAll(loaded);
	}
}

ZoneRulesProvider::ZoneRulesProvider() {
}

$Class* ZoneRulesProvider::load$($String* name, bool initialize) {
	$loadClass(ZoneRulesProvider, name, initialize, &_ZoneRulesProvider_ClassInfo_, clinit$ZoneRulesProvider, allocate$ZoneRulesProvider);
	return class$;
}

$Class* ZoneRulesProvider::class$ = nullptr;

		} // zone
	} // time
} // java