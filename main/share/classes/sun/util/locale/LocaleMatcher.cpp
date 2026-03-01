#include <sun/util/locale/LocaleMatcher.h>

#include <java/io/Serializable.h>
#include <java/lang/CharSequence.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/AbstractSet.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Comparator.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Locale$FilteringMode.h>
#include <java/util/Locale$LanguageRange.h>
#include <java/util/Locale.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/TreeSet.h>
#include <java/util/function/Predicate.h>
#include <java/util/stream/Stream.h>
#include <sun/util/locale/LocaleEquivalentMaps.h>
#include <jcpp.h>

#undef AUTOSELECT_FILTERING
#undef CASE_INSENSITIVE_ORDER
#undef EXTENDED_FILTERING
#undef MAP_EXTENDED_RANGES
#undef MIN_VALUE
#undef REJECT_EXTENDED_RANGES
#undef ROOT

using $Serializable = ::java::io::Serializable;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $Double = ::java::lang::Double;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $AbstractSet = ::java::util::AbstractSet;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Locale$FilteringMode = ::java::util::Locale$FilteringMode;
using $Locale$LanguageRange = ::java::util::Locale$LanguageRange;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $TreeSet = ::java::util::TreeSet;
using $Predicate = ::java::util::function::Predicate;
using $Stream = ::java::util::stream::Stream;
using $LocaleEquivalentMaps = ::sun::util::locale::LocaleEquivalentMaps;

namespace sun {
	namespace util {
		namespace locale {

class LocaleMatcher$$Lambda$lambda$removeDuplicates$0 : public $Predicate {
	$class(LocaleMatcher$$Lambda$lambda$removeDuplicates$0, $NO_CLASS_INIT, $Predicate)
public:
	void init$($Set* distinctTags) {
		$set(this, distinctTags, distinctTags);
	}
	virtual bool test(Object$* x) override {
		 return LocaleMatcher::lambda$removeDuplicates$0(distinctTags, $cast($String, x));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LocaleMatcher$$Lambda$lambda$removeDuplicates$0>());
	}
	$Set* distinctTags = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo LocaleMatcher$$Lambda$lambda$removeDuplicates$0::fieldInfos[2] = {
	{"distinctTags", "Ljava/util/Set;", nullptr, $PUBLIC, $field(LocaleMatcher$$Lambda$lambda$removeDuplicates$0, distinctTags)},
	{}
};
$MethodInfo LocaleMatcher$$Lambda$lambda$removeDuplicates$0::methodInfos[3] = {
	{"<init>", "(Ljava/util/Set;)V", nullptr, $PUBLIC, $method(LocaleMatcher$$Lambda$lambda$removeDuplicates$0, init$, void, $Set*)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(LocaleMatcher$$Lambda$lambda$removeDuplicates$0, test, bool, Object$*)},
	{}
};
$ClassInfo LocaleMatcher$$Lambda$lambda$removeDuplicates$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.util.locale.LocaleMatcher$$Lambda$lambda$removeDuplicates$0",
	"java.lang.Object",
	"java.util.function.Predicate",
	fieldInfos,
	methodInfos
};
$Class* LocaleMatcher$$Lambda$lambda$removeDuplicates$0::load$($String* name, bool initialize) {
	$loadClass(LocaleMatcher$$Lambda$lambda$removeDuplicates$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LocaleMatcher$$Lambda$lambda$removeDuplicates$0::class$ = nullptr;

class LocaleMatcher$$Lambda$lambda$caseInsensitiveMatch$1$1 : public $Predicate {
	$class(LocaleMatcher$$Lambda$lambda$caseInsensitiveMatch$1$1, $NO_CLASS_INIT, $Predicate)
public:
	void init$($String* tag) {
		$set(this, tag, tag);
	}
	virtual bool test(Object$* element) override {
		 return LocaleMatcher::lambda$caseInsensitiveMatch$1(tag, $cast($String, element));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LocaleMatcher$$Lambda$lambda$caseInsensitiveMatch$1$1>());
	}
	$String* tag = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo LocaleMatcher$$Lambda$lambda$caseInsensitiveMatch$1$1::fieldInfos[2] = {
	{"tag", "Ljava/lang/String;", nullptr, $PUBLIC, $field(LocaleMatcher$$Lambda$lambda$caseInsensitiveMatch$1$1, tag)},
	{}
};
$MethodInfo LocaleMatcher$$Lambda$lambda$caseInsensitiveMatch$1$1::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(LocaleMatcher$$Lambda$lambda$caseInsensitiveMatch$1$1, init$, void, $String*)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(LocaleMatcher$$Lambda$lambda$caseInsensitiveMatch$1$1, test, bool, Object$*)},
	{}
};
$ClassInfo LocaleMatcher$$Lambda$lambda$caseInsensitiveMatch$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.util.locale.LocaleMatcher$$Lambda$lambda$caseInsensitiveMatch$1$1",
	"java.lang.Object",
	"java.util.function.Predicate",
	fieldInfos,
	methodInfos
};
$Class* LocaleMatcher$$Lambda$lambda$caseInsensitiveMatch$1$1::load$($String* name, bool initialize) {
	$loadClass(LocaleMatcher$$Lambda$lambda$caseInsensitiveMatch$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LocaleMatcher$$Lambda$lambda$caseInsensitiveMatch$1$1::class$ = nullptr;

$MethodInfo _LocaleMatcher_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(LocaleMatcher, init$, void)},
	{"caseInsensitiveMatch", "(Ljava/util/List;Ljava/lang/String;)Z", "(Ljava/util/List<Ljava/lang/String;>;Ljava/lang/String;)Z", $PRIVATE | $STATIC, $staticMethod(LocaleMatcher, caseInsensitiveMatch, bool, $List*, $String*)},
	{"filter", "(Ljava/util/List;Ljava/util/Collection;Ljava/util/Locale$FilteringMode;)Ljava/util/List;", "(Ljava/util/List<Ljava/util/Locale$LanguageRange;>;Ljava/util/Collection<Ljava/util/Locale;>;Ljava/util/Locale$FilteringMode;)Ljava/util/List<Ljava/util/Locale;>;", $PUBLIC | $STATIC, $staticMethod(LocaleMatcher, filter, $List*, $List*, $Collection*, $Locale$FilteringMode*)},
	{"filterBasic", "(Ljava/util/List;Ljava/util/Collection;)Ljava/util/List;", "(Ljava/util/List<Ljava/util/Locale$LanguageRange;>;Ljava/util/Collection<Ljava/lang/String;>;)Ljava/util/List<Ljava/lang/String;>;", $PRIVATE | $STATIC, $staticMethod(LocaleMatcher, filterBasic, $List*, $List*, $Collection*)},
	{"filterExtended", "(Ljava/util/List;Ljava/util/Collection;)Ljava/util/List;", "(Ljava/util/List<Ljava/util/Locale$LanguageRange;>;Ljava/util/Collection<Ljava/lang/String;>;)Ljava/util/List<Ljava/lang/String;>;", $PRIVATE | $STATIC, $staticMethod(LocaleMatcher, filterExtended, $List*, $List*, $Collection*)},
	{"filterTags", "(Ljava/util/List;Ljava/util/Collection;Ljava/util/Locale$FilteringMode;)Ljava/util/List;", "(Ljava/util/List<Ljava/util/Locale$LanguageRange;>;Ljava/util/Collection<Ljava/lang/String;>;Ljava/util/Locale$FilteringMode;)Ljava/util/List<Ljava/lang/String;>;", $PUBLIC | $STATIC, $staticMethod(LocaleMatcher, filterTags, $List*, $List*, $Collection*, $Locale$FilteringMode*)},
	{"getEquivalentForRegionAndVariant", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(LocaleMatcher, getEquivalentForRegionAndVariant, $String*, $String*)},
	{"getEquivalentsForLanguage", "(Ljava/lang/String;)[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(LocaleMatcher, getEquivalentsForLanguage, $StringArray*, $String*)},
	{"getExtentionKeyIndex", "(Ljava/lang/String;)I", nullptr, $PRIVATE | $STATIC, $staticMethod(LocaleMatcher, getExtentionKeyIndex, int32_t, $String*)},
	{"lambda$caseInsensitiveMatch$1", "(Ljava/lang/String;Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(LocaleMatcher, lambda$caseInsensitiveMatch$1, bool, $String*, $String*)},
	{"lambda$removeDuplicates$0", "(Ljava/util/Set;Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(LocaleMatcher, lambda$removeDuplicates$0, bool, $Set*, $String*)},
	{"lookup", "(Ljava/util/List;Ljava/util/Collection;)Ljava/util/Locale;", "(Ljava/util/List<Ljava/util/Locale$LanguageRange;>;Ljava/util/Collection<Ljava/util/Locale;>;)Ljava/util/Locale;", $PUBLIC | $STATIC, $staticMethod(LocaleMatcher, lookup, $Locale*, $List*, $Collection*)},
	{"lookupTag", "(Ljava/util/List;Ljava/util/Collection;)Ljava/lang/String;", "(Ljava/util/List<Ljava/util/Locale$LanguageRange;>;Ljava/util/Collection<Ljava/lang/String;>;)Ljava/lang/String;", $PUBLIC | $STATIC, $staticMethod(LocaleMatcher, lookupTag, $String*, $List*, $Collection*)},
	{"mapEquivalents", "(Ljava/util/List;Ljava/util/Map;)Ljava/util/List;", "(Ljava/util/List<Ljava/util/Locale$LanguageRange;>;Ljava/util/Map<Ljava/lang/String;Ljava/util/List<Ljava/lang/String;>;>;)Ljava/util/List<Ljava/util/Locale$LanguageRange;>;", $PUBLIC | $STATIC, $staticMethod(LocaleMatcher, mapEquivalents, $List*, $List*, $Map*)},
	{"matchFilterExtendedSubtags", "([Ljava/lang/String;[Ljava/lang/String;)I", nullptr, $PRIVATE | $STATIC, $staticMethod(LocaleMatcher, matchFilterExtendedSubtags, int32_t, $StringArray*, $StringArray*)},
	{"parse", "(Ljava/lang/String;)Ljava/util/List;", "(Ljava/lang/String;)Ljava/util/List<Ljava/util/Locale$LanguageRange;>;", $PUBLIC | $STATIC, $staticMethod(LocaleMatcher, parse, $List*, $String*)},
	{"removeDuplicates", "(Ljava/util/Collection;)Ljava/util/Collection;", "(Ljava/util/Collection<Ljava/lang/String;>;)Ljava/util/Collection<Ljava/lang/String;>;", $PRIVATE | $STATIC, $staticMethod(LocaleMatcher, removeDuplicates, $Collection*, $Collection*)},
	{"removeTagsMatchingBasicZeroRange", "(Ljava/util/List;Ljava/util/Collection;)Ljava/util/Collection;", "(Ljava/util/List<Ljava/util/Locale$LanguageRange;>;Ljava/util/Collection<Ljava/lang/String;>;)Ljava/util/Collection<Ljava/lang/String;>;", $PRIVATE | $STATIC, $staticMethod(LocaleMatcher, removeTagsMatchingBasicZeroRange, $Collection*, $List*, $Collection*)},
	{"removeTagsMatchingExtendedZeroRange", "(Ljava/util/List;Ljava/util/Collection;)Ljava/util/Collection;", "(Ljava/util/List<Ljava/util/Locale$LanguageRange;>;Ljava/util/Collection<Ljava/lang/String;>;)Ljava/util/Collection<Ljava/lang/String;>;", $PRIVATE | $STATIC, $staticMethod(LocaleMatcher, removeTagsMatchingExtendedZeroRange, $Collection*, $List*, $Collection*)},
	{"replaceFirstSubStringMatch", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(LocaleMatcher, replaceFirstSubStringMatch, $String*, $String*, $String*, $String*)},
	{"shouldIgnoreFilterBasicMatch", "(Ljava/util/List;Ljava/lang/String;)Z", "(Ljava/util/List<Ljava/util/Locale$LanguageRange;>;Ljava/lang/String;)Z", $PRIVATE | $STATIC, $staticMethod(LocaleMatcher, shouldIgnoreFilterBasicMatch, bool, $List*, $String*)},
	{"shouldIgnoreFilterExtendedMatch", "(Ljava/util/List;Ljava/lang/String;)Z", "(Ljava/util/List<Ljava/util/Locale$LanguageRange;>;Ljava/lang/String;)Z", $PRIVATE | $STATIC, $staticMethod(LocaleMatcher, shouldIgnoreFilterExtendedMatch, bool, $List*, $String*)},
	{"shouldIgnoreLookupMatch", "(Ljava/util/List;Ljava/lang/String;)Z", "(Ljava/util/List<Ljava/util/Locale$LanguageRange;>;Ljava/lang/String;)Z", $PRIVATE | $STATIC, $staticMethod(LocaleMatcher, shouldIgnoreLookupMatch, bool, $List*, $String*)},
	{"splitRanges", "(Ljava/util/List;)I", "(Ljava/util/List<Ljava/util/Locale$LanguageRange;>;)I", $PRIVATE | $STATIC, $staticMethod(LocaleMatcher, splitRanges, int32_t, $List*)},
	{"truncateRange", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(LocaleMatcher, truncateRange, $String*, $String*)},
	{}
};

$ClassInfo _LocaleMatcher_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.util.locale.LocaleMatcher",
	"java.lang.Object",
	nullptr,
	nullptr,
	_LocaleMatcher_MethodInfo_
};

$Object* allocate$LocaleMatcher($Class* clazz) {
	return $of($alloc(LocaleMatcher));
}

$List* LocaleMatcher::filter($List* priorityList, $Collection* locales, $Locale$FilteringMode* mode) {
	$useLocalCurrentObjectStackCache();
	bool var$0 = $nc(priorityList)->isEmpty();
	if (var$0 || $nc(locales)->isEmpty()) {
		return $new($ArrayList);
	}
	$var($List, tags, $new($ArrayList));
	{
		$var($Iterator, i$, $nc(locales)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Locale, locale, $cast($Locale, i$->next()));
			{
				tags->add($($nc(locale)->toLanguageTag()));
			}
		}
	}
	$var($List, filteredTags, filterTags(priorityList, tags, mode));
	$var($List, filteredLocales, $new($ArrayList, $nc(filteredTags)->size()));
	{
		$var($Iterator, i$, $nc(filteredTags)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, tag, $cast($String, i$->next()));
			{
				filteredLocales->add($($Locale::forLanguageTag(tag)));
			}
		}
	}
	return filteredLocales;
}

$List* LocaleMatcher::filterTags($List* priorityList, $Collection* tags, $Locale$FilteringMode* mode) {
	$useLocalCurrentObjectStackCache();
	bool var$0 = $nc(priorityList)->isEmpty();
	if (var$0 || $nc(tags)->isEmpty()) {
		return $new($ArrayList);
	}
	$var($ArrayList, list, nullptr);
	$init($Locale$FilteringMode);
	if (mode == $Locale$FilteringMode::EXTENDED_FILTERING) {
		return filterExtended(priorityList, tags);
	} else {
		$assign(list, $new($ArrayList));
		{
			$var($Iterator, i$, $nc(priorityList)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Locale$LanguageRange, lr, $cast($Locale$LanguageRange, i$->next()));
				{
					$var($String, range, $nc(lr)->getRange());
					bool var$1 = $nc(range)->startsWith("*-"_s);
					if (var$1 || $nc(range)->indexOf("-*"_s) != -1) {
						if (mode == $Locale$FilteringMode::AUTOSELECT_FILTERING) {
							return filterExtended(priorityList, tags);
						} else {
							if (mode == $Locale$FilteringMode::MAP_EXTENDED_RANGES) {
								if (range->charAt(0) == u'*') {
									$assign(range, "*"_s);
								} else {
									$assign(range, range->replaceAll("-[*]"_s, ""_s));
								}
								list->add($$new($Locale$LanguageRange, range, lr->getWeight()));
							} else {
								if (mode == $Locale$FilteringMode::REJECT_EXTENDED_RANGES) {
									$throwNew($IllegalArgumentException, $$str({"An extended range \""_s, range, "\" found in REJECT_EXTENDED_RANGES mode."_s}));
								}
							}
						}
					} else {
						list->add(lr);
					}
				}
			}
		}
		return filterBasic(list, tags);
	}
}

$List* LocaleMatcher::filterBasic($List* priorityList, $Collection* tags$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($Collection, tags, tags$renamed);
	int32_t splitIndex = splitRanges(priorityList);
	$var($List, nonZeroRanges, nullptr);
	$var($List, zeroRanges, nullptr);
	if (splitIndex != -1) {
		$assign(nonZeroRanges, $nc(priorityList)->subList(0, splitIndex));
		$assign(zeroRanges, priorityList->subList(splitIndex, priorityList->size()));
	} else {
		$assign(nonZeroRanges, priorityList);
		$assign(zeroRanges, $List::of());
	}
	$var($List, list, $new($ArrayList));
	{
		$var($Iterator, i$, $nc(nonZeroRanges)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Locale$LanguageRange, lr, $cast($Locale$LanguageRange, i$->next()));
			{
				$var($String, range, $nc(lr)->getRange());
				if ($nc(range)->equals("*"_s)) {
					$assign(tags, removeTagsMatchingBasicZeroRange(zeroRanges, tags));
					return $new($ArrayList, tags);
				} else {
					{
						$var($Iterator, i$, $nc(tags)->iterator());
						for (; $nc(i$)->hasNext();) {
							$var($String, tag, $cast($String, i$->next()));
							{
								$init($Locale);
								$var($String, lowerCaseTag, $nc(tag)->toLowerCase($Locale::ROOT));
								if (lowerCaseTag->startsWith(range)) {
									int32_t len = range->length();
									bool var$2 = lowerCaseTag->length() == len;
									bool var$1 = (var$2 || lowerCaseTag->charAt(len) == u'-');
									bool var$0 = var$1 && !caseInsensitiveMatch(list, lowerCaseTag);
									if (var$0 && !shouldIgnoreFilterBasicMatch(zeroRanges, lowerCaseTag)) {
										list->add(tag);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return list;
}

$Collection* LocaleMatcher::removeTagsMatchingBasicZeroRange($List* zeroRange, $Collection* tags$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($Collection, tags, tags$renamed);
	if ($nc(zeroRange)->isEmpty()) {
		$assign(tags, removeDuplicates(tags));
		return tags;
	}
	$var($List, matchingTags, $new($ArrayList));
	{
		$var($Iterator, i$, $nc(tags)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, tag, $cast($String, i$->next()));
			{
				$init($Locale);
				$var($String, lowerCaseTag, $nc(tag)->toLowerCase($Locale::ROOT));
				bool var$0 = !shouldIgnoreFilterBasicMatch(zeroRange, lowerCaseTag);
				if (var$0 && !caseInsensitiveMatch(matchingTags, lowerCaseTag)) {
					matchingTags->add(tag);
				}
			}
		}
	}
	return matchingTags;
}

$Collection* LocaleMatcher::removeDuplicates($Collection* tags) {
	$useLocalCurrentObjectStackCache();
	$var($Set, distinctTags, static_cast<$Set*>(static_cast<$AbstractSet*>($new($TreeSet, $String::CASE_INSENSITIVE_ORDER))));
	return $nc($($nc($($nc(tags)->stream()))->filter(static_cast<$Predicate*>($$new(LocaleMatcher$$Lambda$lambda$removeDuplicates$0, distinctTags)))))->toList();
}

bool LocaleMatcher::caseInsensitiveMatch($List* list, $String* tag) {
	$useLocalCurrentObjectStackCache();
	return $nc($($nc(list)->stream()))->anyMatch(static_cast<$Predicate*>($$new(LocaleMatcher$$Lambda$lambda$caseInsensitiveMatch$1$1, tag)));
}

bool LocaleMatcher::shouldIgnoreFilterBasicMatch($List* zeroRange, $String* tag) {
	$useLocalCurrentObjectStackCache();
	if ($nc(zeroRange)->isEmpty()) {
		return false;
	}
	{
		$var($Iterator, i$, $nc(zeroRange)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Locale$LanguageRange, lr, $cast($Locale$LanguageRange, i$->next()));
			{
				$var($String, range, $nc(lr)->getRange());
				if ($nc(range)->equals("*"_s)) {
					return true;
				}
				if ($nc(tag)->startsWith(range)) {
					int32_t len = $nc(range)->length();
					bool var$0 = tag->length() == len;
					if (var$0 || tag->charAt(len) == u'-') {
						return true;
					}
				}
			}
		}
	}
	return false;
}

$List* LocaleMatcher::filterExtended($List* priorityList, $Collection* tags$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($Collection, tags, tags$renamed);
	int32_t splitIndex = splitRanges(priorityList);
	$var($List, nonZeroRanges, nullptr);
	$var($List, zeroRanges, nullptr);
	if (splitIndex != -1) {
		$assign(nonZeroRanges, $nc(priorityList)->subList(0, splitIndex));
		$assign(zeroRanges, priorityList->subList(splitIndex, priorityList->size()));
	} else {
		$assign(nonZeroRanges, priorityList);
		$assign(zeroRanges, $List::of());
	}
	$var($List, list, $new($ArrayList));
	{
		$var($Iterator, i$, $nc(nonZeroRanges)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Locale$LanguageRange, lr, $cast($Locale$LanguageRange, i$->next()));
			{
				$var($String, range, $nc(lr)->getRange());
				if ($nc(range)->equals("*"_s)) {
					$assign(tags, removeTagsMatchingExtendedZeroRange(zeroRanges, tags));
					return $new($ArrayList, tags);
				}
				$var($StringArray, rangeSubtags, $nc(range)->split("-"_s));
				{
					$var($Iterator, i$, $nc(tags)->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($String, tag, $cast($String, i$->next()));
						{
							$init($Locale);
							$var($String, lowerCaseTag, $nc(tag)->toLowerCase($Locale::ROOT));
							$var($StringArray, tagSubtags, lowerCaseTag->split("-"_s));
							bool var$0 = !$nc(rangeSubtags->get(0))->equals(tagSubtags->get(0));
							if (var$0 && !$nc(rangeSubtags->get(0))->equals("*"_s)) {
								continue;
							}
							int32_t rangeIndex = matchFilterExtendedSubtags(rangeSubtags, tagSubtags);
							bool var$1 = rangeSubtags->length == rangeIndex && !caseInsensitiveMatch(list, lowerCaseTag);
							if (var$1 && !shouldIgnoreFilterExtendedMatch(zeroRanges, lowerCaseTag)) {
								list->add(tag);
							}
						}
					}
				}
			}
		}
	}
	return list;
}

$Collection* LocaleMatcher::removeTagsMatchingExtendedZeroRange($List* zeroRange, $Collection* tags$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($Collection, tags, tags$renamed);
	if ($nc(zeroRange)->isEmpty()) {
		$assign(tags, removeDuplicates(tags));
		return tags;
	}
	$var($List, matchingTags, $new($ArrayList));
	{
		$var($Iterator, i$, $nc(tags)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, tag, $cast($String, i$->next()));
			{
				$init($Locale);
				$var($String, lowerCaseTag, $nc(tag)->toLowerCase($Locale::ROOT));
				bool var$0 = !shouldIgnoreFilterExtendedMatch(zeroRange, lowerCaseTag);
				if (var$0 && !caseInsensitiveMatch(matchingTags, lowerCaseTag)) {
					matchingTags->add(tag);
				}
			}
		}
	}
	return matchingTags;
}

bool LocaleMatcher::shouldIgnoreFilterExtendedMatch($List* zeroRange, $String* tag) {
	$useLocalCurrentObjectStackCache();
	if ($nc(zeroRange)->isEmpty()) {
		return false;
	}
	$var($StringArray, tagSubtags, $nc(tag)->split("-"_s));
	{
		$var($Iterator, i$, $nc(zeroRange)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Locale$LanguageRange, lr, $cast($Locale$LanguageRange, i$->next()));
			{
				$var($String, range, $nc(lr)->getRange());
				if ($nc(range)->equals("*"_s)) {
					return true;
				}
				$var($StringArray, rangeSubtags, $nc(range)->split("-"_s));
				bool var$0 = !$nc(rangeSubtags->get(0))->equals(tagSubtags->get(0));
				if (var$0 && !$nc(rangeSubtags->get(0))->equals("*"_s)) {
					continue;
				}
				int32_t rangeIndex = matchFilterExtendedSubtags(rangeSubtags, tagSubtags);
				if (rangeSubtags->length == rangeIndex) {
					return true;
				}
			}
		}
	}
	return false;
}

int32_t LocaleMatcher::matchFilterExtendedSubtags($StringArray* rangeSubtags, $StringArray* tagSubtags) {
	int32_t rangeIndex = 1;
	int32_t tagIndex = 1;
	while (rangeIndex < $nc(rangeSubtags)->length && tagIndex < $nc(tagSubtags)->length) {
		if ($nc(rangeSubtags->get(rangeIndex))->equals("*"_s)) {
			++rangeIndex;
		} else if ($nc(rangeSubtags->get(rangeIndex))->equals(tagSubtags->get(tagIndex))) {
			++rangeIndex;
			++tagIndex;
		} else {
			bool var$1 = $nc(tagSubtags->get(tagIndex))->length() == 1;
			if (var$1 && !$nc(tagSubtags->get(tagIndex))->equals("*"_s)) {
				break;
			} else {
				++tagIndex;
			}
		}
	}
	return rangeIndex;
}

$Locale* LocaleMatcher::lookup($List* priorityList, $Collection* locales) {
	$useLocalCurrentObjectStackCache();
	bool var$0 = $nc(priorityList)->isEmpty();
	if (var$0 || $nc(locales)->isEmpty()) {
		return nullptr;
	}
	$var($List, tags, $new($ArrayList));
	{
		$var($Iterator, i$, $nc(locales)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Locale, locale, $cast($Locale, i$->next()));
			{
				tags->add($($nc(locale)->toLanguageTag()));
			}
		}
	}
	$var($String, lookedUpTag, lookupTag(priorityList, tags));
	if (lookedUpTag == nullptr) {
		return nullptr;
	} else {
		return $Locale::forLanguageTag(lookedUpTag);
	}
}

$String* LocaleMatcher::lookupTag($List* priorityList, $Collection* tags) {
	$useLocalCurrentObjectStackCache();
	bool var$0 = $nc(priorityList)->isEmpty();
	if (var$0 || $nc(tags)->isEmpty()) {
		return nullptr;
	}
	int32_t splitIndex = splitRanges(priorityList);
	$var($List, nonZeroRanges, nullptr);
	$var($List, zeroRanges, nullptr);
	if (splitIndex != -1) {
		$assign(nonZeroRanges, $nc(priorityList)->subList(0, splitIndex));
		$assign(zeroRanges, priorityList->subList(splitIndex, priorityList->size()));
	} else {
		$assign(nonZeroRanges, priorityList);
		$assign(zeroRanges, $List::of());
	}
	{
		$var($Iterator, i$, $nc(nonZeroRanges)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Locale$LanguageRange, lr, $cast($Locale$LanguageRange, i$->next()));
			{
				$var($String, range, $nc(lr)->getRange());
				if ($nc(range)->equals("*"_s)) {
					continue;
				}
				$var($String, rangeForRegex, $nc(range)->replace(static_cast<$CharSequence*>("*"_s), static_cast<$CharSequence*>("\\p{Alnum}*"_s)));
				while (!$nc(rangeForRegex)->isEmpty()) {
					{
						$var($Iterator, i$, $nc(tags)->iterator());
						for (; $nc(i$)->hasNext();) {
							$var($String, tag, $cast($String, i$->next()));
							{
								$init($Locale);
								$var($String, lowerCaseTag, $nc(tag)->toLowerCase($Locale::ROOT));
								bool var$1 = lowerCaseTag->matches(rangeForRegex);
								if (var$1 && !shouldIgnoreLookupMatch(zeroRanges, lowerCaseTag)) {
									return tag;
								}
							}
						}
					}
					$assign(rangeForRegex, truncateRange(rangeForRegex));
				}
			}
		}
	}
	return nullptr;
}

bool LocaleMatcher::shouldIgnoreLookupMatch($List* zeroRange, $String* tag) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc(zeroRange)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Locale$LanguageRange, lr, $cast($Locale$LanguageRange, i$->next()));
			{
				$var($String, range, $nc(lr)->getRange());
				if ($nc(range)->equals("*"_s)) {
					continue;
				}
				$var($String, rangeForRegex, $nc(range)->replace(static_cast<$CharSequence*>("*"_s), static_cast<$CharSequence*>("\\p{Alnum}*"_s)));
				while (!$nc(rangeForRegex)->isEmpty()) {
					if ($nc(tag)->matches(rangeForRegex)) {
						return true;
					}
					$assign(rangeForRegex, truncateRange(rangeForRegex));
				}
			}
		}
	}
	return false;
}

$String* LocaleMatcher::truncateRange($String* rangeForRegex$renamed) {
	$var($String, rangeForRegex, rangeForRegex$renamed);
	int32_t index = $nc(rangeForRegex)->lastIndexOf((int32_t)u'-');
	if (index >= 0) {
		$assign(rangeForRegex, rangeForRegex->substring(0, index));
		index = rangeForRegex->lastIndexOf((int32_t)u'-');
		if (index >= 0 && index == rangeForRegex->length() - 2) {
			$assign(rangeForRegex, rangeForRegex->substring(0, rangeForRegex->length() - 2));
		}
	} else {
		$assign(rangeForRegex, ""_s);
	}
	return rangeForRegex;
}

int32_t LocaleMatcher::splitRanges($List* priorityList) {
	$useLocalCurrentObjectStackCache();
	int32_t size = $nc(priorityList)->size();
	for (int32_t index = 0; index < size; ++index) {
		$var($Locale$LanguageRange, range, $cast($Locale$LanguageRange, priorityList->get(index)));
		if ($nc(range)->getWeight() == 0) {
			return index;
		}
	}
	return -1;
}

$List* LocaleMatcher::parse($String* ranges$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($String, ranges, ranges$renamed);
	$init($Locale);
	$assign(ranges, $($nc(ranges)->replace(static_cast<$CharSequence*>(" "_s), static_cast<$CharSequence*>(""_s)))->toLowerCase($Locale::ROOT));
	if (ranges->startsWith("accept-language:"_s)) {
		$assign(ranges, ranges->substring(16));
	}
	$var($StringArray, langRanges, ranges->split(","_s));
	$var($List, list, $new($ArrayList, langRanges->length));
	$var($List, tempList, $new($ArrayList));
	int32_t numOfRanges = 0;
	{
		$var($StringArray, arr$, langRanges);
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, range, arr$->get(i$));
			{
				int32_t index = 0;
				$var($String, r, nullptr);
				double w = 0.0;
				if ((index = $nc(range)->indexOf(";q="_s)) == -1) {
					$assign(r, range);
					w = 1.0;
				} else {
					$assign(r, range->substring(0, index));
					index += 3;
					try {
						w = $Double::parseDouble($(range->substring(index)));
					} catch ($Exception& e) {
						$throwNew($IllegalArgumentException, $$str({"weight=\""_s, $(range->substring(index)), "\" for language range \""_s, r, "\""_s}));
					}
					if (w < 0.0 || w > 1.0) {
						$throwNew($IllegalArgumentException, $$str({"weight="_s, $$str(w), " for language range \""_s, r, "\". It must be between "_s, $$str(0.0), " and "_s, $$str(1.0), "."_s}));
					}
				}
				if (!tempList->contains(r)) {
					$var($Locale$LanguageRange, lr, $new($Locale$LanguageRange, r, w));
					index = numOfRanges;
					for (int32_t j = 0; j < numOfRanges; ++j) {
						if ($nc(($cast($Locale$LanguageRange, $(list->get(j)))))->getWeight() < w) {
							index = j;
							break;
						}
					}
					list->add(index, lr);
					++numOfRanges;
					tempList->add(r);
					$var($String, equivalent, nullptr);
					bool var$0 = ($assign(equivalent, getEquivalentForRegionAndVariant(r))) != nullptr;
					if (var$0 && !tempList->contains(equivalent)) {
						list->add(index + 1, $$new($Locale$LanguageRange, equivalent, w));
						++numOfRanges;
						tempList->add(equivalent);
					}
					$var($StringArray, equivalents, nullptr);
					if (($assign(equivalents, getEquivalentsForLanguage(r))) != nullptr) {
						{
							$var($StringArray, arr$, equivalents);
							int32_t len$ = arr$->length;
							int32_t i$ = 0;
							for (; i$ < len$; ++i$) {
								$var($String, equiv, arr$->get(i$));
								{
									if (!tempList->contains(equiv)) {
										list->add(index + 1, $$new($Locale$LanguageRange, equiv, w));
										++numOfRanges;
										tempList->add(equiv);
									}
									$assign(equivalent, getEquivalentForRegionAndVariant(equiv));
									if (equivalent != nullptr && !tempList->contains(equivalent)) {
										list->add(index + 1, $$new($Locale$LanguageRange, equivalent, w));
										++numOfRanges;
										tempList->add(equivalent);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return list;
}

$String* LocaleMatcher::replaceFirstSubStringMatch($String* range, $String* substr, $String* replacement) {
	$useLocalCurrentObjectStackCache();
	int32_t pos = $nc(range)->indexOf(substr);
	if (pos == -1) {
		return range;
	} else {
		$var($String, var$0, $$str({$(range->substring(0, pos)), replacement}));
		return $concat(var$0, $(range->substring(pos + $nc(substr)->length())));
	}
}

$StringArray* LocaleMatcher::getEquivalentsForLanguage($String* range) {
	$useLocalCurrentObjectStackCache();
	$var($String, r, range);
	while (!$nc(r)->isEmpty()) {
		$init($LocaleEquivalentMaps);
		if ($nc($LocaleEquivalentMaps::singleEquivMap)->containsKey(r)) {
			$var($String, equiv, $cast($String, $nc($LocaleEquivalentMaps::singleEquivMap)->get(r)));
			return $new($StringArray, {$(replaceFirstSubStringMatch(range, r, equiv))});
		} else {
			if ($nc($LocaleEquivalentMaps::multiEquivsMap)->containsKey(r)) {
				$var($StringArray, equivs, $cast($StringArray, $nc($LocaleEquivalentMaps::multiEquivsMap)->get(r)));
				$var($StringArray, result, $new($StringArray, $nc(equivs)->length));
				for (int32_t i = 0; i < equivs->length; ++i) {
					result->set(i, $(replaceFirstSubStringMatch(range, r, equivs->get(i))));
				}
				return result;
			}
		}
		int32_t index = r->lastIndexOf((int32_t)u'-');
		if (index == -1) {
			break;
		}
		$assign(r, r->substring(0, index));
	}
	return nullptr;
}

$String* LocaleMatcher::getEquivalentForRegionAndVariant($String* range) {
	$useLocalCurrentObjectStackCache();
	int32_t extensionKeyIndex = getExtentionKeyIndex(range);
	{
		$init($LocaleEquivalentMaps);
		$var($Iterator, i$, $nc($($nc($LocaleEquivalentMaps::regionVariantEquivMap)->keySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, subtag, $cast($String, i$->next()));
			{
				int32_t index = 0;
				if ((index = $nc(range)->indexOf(subtag)) != -1) {
					if (extensionKeyIndex != $Integer::MIN_VALUE && index > extensionKeyIndex) {
						continue;
					}
					int32_t len = index + $nc(subtag)->length();
					bool var$0 = range->length() == len;
					if (var$0 || range->charAt(len) == u'-') {
						return replaceFirstSubStringMatch(range, subtag, $cast($String, $($nc($LocaleEquivalentMaps::regionVariantEquivMap)->get(subtag))));
					}
				}
			}
		}
	}
	return nullptr;
}

int32_t LocaleMatcher::getExtentionKeyIndex($String* s) {
	$var($chars, c, $nc(s)->toCharArray());
	int32_t index = $Integer::MIN_VALUE;
	for (int32_t i = 1; i < c->length; ++i) {
		if (c->get(i) == u'-') {
			if (i - index == 2) {
				return index;
			} else {
				index = i;
			}
		}
	}
	return $Integer::MIN_VALUE;
}

$List* LocaleMatcher::mapEquivalents($List* priorityList, $Map* map) {
	$useLocalCurrentObjectStackCache();
	if ($nc(priorityList)->isEmpty()) {
		return $new($ArrayList);
	}
	if (map == nullptr || $nc(map)->isEmpty()) {
		return $new($ArrayList, static_cast<$Collection*>(priorityList));
	}
	$var($Map, keyMap, $new($HashMap));
	{
		$var($Iterator, i$, $nc($($nc(map)->keySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, key, $cast($String, i$->next()));
			{
				$init($Locale);
				keyMap->put($($nc(key)->toLowerCase($Locale::ROOT)), key);
			}
		}
	}
	$var($List, list, $new($ArrayList));
	{
		$var($Iterator, i$, $nc(priorityList)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Locale$LanguageRange, lr, $cast($Locale$LanguageRange, i$->next()));
			{
				$var($String, range, $nc(lr)->getRange());
				$var($String, r, range);
				bool hasEquivalent = false;
				while (!$nc(r)->isEmpty()) {
					if (keyMap->containsKey(r)) {
						hasEquivalent = true;
						$var($List, equivalents, $cast($List, map->get($(keyMap->get(r)))));
						if (equivalents != nullptr) {
							int32_t len = r->length();
							{
								$var($Iterator, i$, equivalents->iterator());
								for (; $nc(i$)->hasNext();) {
									$var($String, equivalent, $cast($String, i$->next()));
									{
										$init($Locale);
										$var($String, var$1, $($nc(equivalent)->toLowerCase($Locale::ROOT)));
										$var($String, var$0, $concat(var$1, $($nc(range)->substring(len))));
										list->add($$new($Locale$LanguageRange, var$0, lr->getWeight()));
									}
								}
							}
						}
						break;
					}
					int32_t index = r->lastIndexOf((int32_t)u'-');
					if (index == -1) {
						break;
					}
					$assign(r, r->substring(0, index));
				}
				if (!hasEquivalent) {
					list->add(lr);
				}
			}
		}
	}
	return list;
}

void LocaleMatcher::init$() {
}

bool LocaleMatcher::lambda$caseInsensitiveMatch$1($String* tag, $String* element) {
	return ($nc(element)->equalsIgnoreCase(tag));
}

bool LocaleMatcher::lambda$removeDuplicates$0($Set* distinctTags, $String* x) {
	return $nc(distinctTags)->add(x);
}

LocaleMatcher::LocaleMatcher() {
}

$Class* LocaleMatcher::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(LocaleMatcher$$Lambda$lambda$removeDuplicates$0::classInfo$.name)) {
			return LocaleMatcher$$Lambda$lambda$removeDuplicates$0::load$(name, initialize);
		}
		if (name->equals(LocaleMatcher$$Lambda$lambda$caseInsensitiveMatch$1$1::classInfo$.name)) {
			return LocaleMatcher$$Lambda$lambda$caseInsensitiveMatch$1$1::load$(name, initialize);
		}
	}
	$loadClass(LocaleMatcher, name, initialize, &_LocaleMatcher_ClassInfo_, allocate$LocaleMatcher);
	return class$;
}

$Class* LocaleMatcher::class$ = nullptr;

		} // locale
	} // util
} // sun