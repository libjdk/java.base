#include <java/time/format/DateTimeTextProvider$LocaleStore.h>

#include <java/time/format/DateTimeTextProvider.h>
#include <java/time/format/TextStyle.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Comparator.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <jcpp.h>

#undef COMPARATOR

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $DateTimeTextProvider = ::java::time::format::DateTimeTextProvider;
using $TextStyle = ::java::time::format::TextStyle;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;

namespace java {
	namespace time {
		namespace format {

$FieldInfo _DateTimeTextProvider$LocaleStore_FieldInfo_[] = {
	{"valueTextMap", "Ljava/util/Map;", "Ljava/util/Map<Ljava/time/format/TextStyle;Ljava/util/Map<Ljava/lang/Long;Ljava/lang/String;>;>;", $PRIVATE | $FINAL, $field(DateTimeTextProvider$LocaleStore, valueTextMap)},
	{"parsable", "Ljava/util/Map;", "Ljava/util/Map<Ljava/time/format/TextStyle;Ljava/util/List<Ljava/util/Map$Entry<Ljava/lang/String;Ljava/lang/Long;>;>;>;", $PRIVATE | $FINAL, $field(DateTimeTextProvider$LocaleStore, parsable)},
	{}
};

$MethodInfo _DateTimeTextProvider$LocaleStore_MethodInfo_[] = {
	{"<init>", "(Ljava/util/Map;)V", "(Ljava/util/Map<Ljava/time/format/TextStyle;Ljava/util/Map<Ljava/lang/Long;Ljava/lang/String;>;>;)V", 0, $method(DateTimeTextProvider$LocaleStore, init$, void, $Map*)},
	{"getText", "(JLjava/time/format/TextStyle;)Ljava/lang/String;", nullptr, 0, $method(DateTimeTextProvider$LocaleStore, getText, $String*, int64_t, $TextStyle*)},
	{"getTextIterator", "(Ljava/time/format/TextStyle;)Ljava/util/Iterator;", "(Ljava/time/format/TextStyle;)Ljava/util/Iterator<Ljava/util/Map$Entry<Ljava/lang/String;Ljava/lang/Long;>;>;", 0, $method(DateTimeTextProvider$LocaleStore, getTextIterator, $Iterator*, $TextStyle*)},
	{}
};

$InnerClassInfo _DateTimeTextProvider$LocaleStore_InnerClassesInfo_[] = {
	{"java.time.format.DateTimeTextProvider$LocaleStore", "java.time.format.DateTimeTextProvider", "LocaleStore", $STATIC | $FINAL},
	{}
};

$ClassInfo _DateTimeTextProvider$LocaleStore_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.time.format.DateTimeTextProvider$LocaleStore",
	"java.lang.Object",
	nullptr,
	_DateTimeTextProvider$LocaleStore_FieldInfo_,
	_DateTimeTextProvider$LocaleStore_MethodInfo_,
	nullptr,
	nullptr,
	_DateTimeTextProvider$LocaleStore_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.time.format.DateTimeTextProvider"
};

$Object* allocate$DateTimeTextProvider$LocaleStore($Class* clazz) {
	return $of($alloc(DateTimeTextProvider$LocaleStore));
}

void DateTimeTextProvider$LocaleStore::init$($Map* valueTextMap) {
	$useLocalCurrentObjectStackCache();
	$set(this, valueTextMap, valueTextMap);
	$var($Map, map, $new($HashMap));
	$var($List, allList, $new($ArrayList));
	{
		$var($Iterator, i$, $nc($($nc(valueTextMap)->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, vtmEntry, $cast($Map$Entry, i$->next()));
			{
				$var($Map, reverse, $new($HashMap));
				{
					$var($Iterator, i$, $nc($($nc(($cast($Map, $($nc(vtmEntry)->getValue()))))->entrySet()))->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
						{
							$var($Object, var$0, $cast($String, $nc(entry)->getValue()));
							$var($Object, var$1, $cast($String, entry->getValue()));
							if (reverse->put(var$0, $($DateTimeTextProvider::createEntry(var$1, $cast($Long, $(entry->getKey()))))) != nullptr) {
								continue;
							}
						}
					}
				}
				$var($List, list, $new($ArrayList, $(reverse->values())));
				$init($DateTimeTextProvider);
				$Collections::sort(list, $DateTimeTextProvider::COMPARATOR);
				map->put($cast($TextStyle, $(vtmEntry->getKey())), list);
				allList->addAll(list);
				map->put(nullptr, allList);
			}
		}
	}
	$init($DateTimeTextProvider);
	$Collections::sort(allList, $DateTimeTextProvider::COMPARATOR);
	$set(this, parsable, map);
}

$String* DateTimeTextProvider$LocaleStore::getText(int64_t value, $TextStyle* style) {
	$useLocalCurrentObjectStackCache();
	$var($Map, map, $cast($Map, $nc(this->valueTextMap)->get(style)));
	return map != nullptr ? $cast($String, $nc(map)->get($($Long::valueOf(value)))) : ($String*)nullptr;
}

$Iterator* DateTimeTextProvider$LocaleStore::getTextIterator($TextStyle* style) {
	$var($List, list, $cast($List, $nc(this->parsable)->get(style)));
	return list != nullptr ? $nc(list)->iterator() : ($Iterator*)nullptr;
}

DateTimeTextProvider$LocaleStore::DateTimeTextProvider$LocaleStore() {
}

$Class* DateTimeTextProvider$LocaleStore::load$($String* name, bool initialize) {
	$loadClass(DateTimeTextProvider$LocaleStore, name, initialize, &_DateTimeTextProvider$LocaleStore_ClassInfo_, allocate$DateTimeTextProvider$LocaleStore);
	return class$;
}

$Class* DateTimeTextProvider$LocaleStore::class$ = nullptr;

		} // format
	} // time
} // java