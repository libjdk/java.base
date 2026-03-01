#include <java/util/ResourceBundle$Control$CandidateListCache.h>

#include <java/util/Iterator.h>
#include <java/util/LinkedList.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/ResourceBundle$Control.h>
#include <sun/util/locale/BaseLocale.h>
#include <sun/util/locale/LocaleExtensions.h>
#include <sun/util/locale/LocaleObjectCache.h>
#include <jcpp.h>

#undef ROOT

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Iterator = ::java::util::Iterator;
using $LinkedList = ::java::util::LinkedList;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $BaseLocale = ::sun::util::locale::BaseLocale;
using $LocaleExtensions = ::sun::util::locale::LocaleExtensions;
using $LocaleObjectCache = ::sun::util::locale::LocaleObjectCache;

namespace java {
	namespace util {

$MethodInfo _ResourceBundle$Control$CandidateListCache_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(ResourceBundle$Control$CandidateListCache, init$, void)},
	{"createObject", "(Lsun/util/locale/BaseLocale;)Ljava/util/List;", "(Lsun/util/locale/BaseLocale;)Ljava/util/List<Ljava/util/Locale;>;", $PROTECTED, $virtualMethod(ResourceBundle$Control$CandidateListCache, createObject, $List*, $BaseLocale*)},
	{"createObject", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PROTECTED | $VOLATILE | $SYNTHETIC, $virtualMethod(ResourceBundle$Control$CandidateListCache, createObject, $Object*, Object$*)},
	{"getDefaultList", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/util/List;", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/util/List<Ljava/util/Locale;>;", $PRIVATE | $STATIC, $staticMethod(ResourceBundle$Control$CandidateListCache, getDefaultList, $List*, $String*, $String*, $String*, $String*)},
	{}
};

$InnerClassInfo _ResourceBundle$Control$CandidateListCache_InnerClassesInfo_[] = {
	{"java.util.ResourceBundle$Control", "java.util.ResourceBundle", "Control", $PUBLIC | $STATIC},
	{"java.util.ResourceBundle$Control$CandidateListCache", "java.util.ResourceBundle$Control", "CandidateListCache", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _ResourceBundle$Control$CandidateListCache_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.ResourceBundle$Control$CandidateListCache",
	"sun.util.locale.LocaleObjectCache",
	nullptr,
	nullptr,
	_ResourceBundle$Control$CandidateListCache_MethodInfo_,
	"Lsun/util/locale/LocaleObjectCache<Lsun/util/locale/BaseLocale;Ljava/util/List<Ljava/util/Locale;>;>;",
	nullptr,
	_ResourceBundle$Control$CandidateListCache_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.ResourceBundle"
};

$Object* allocate$ResourceBundle$Control$CandidateListCache($Class* clazz) {
	return $of($alloc(ResourceBundle$Control$CandidateListCache));
}

void ResourceBundle$Control$CandidateListCache::init$() {
	$LocaleObjectCache::init$();
}

$List* ResourceBundle$Control$CandidateListCache::createObject($BaseLocale* base) {
	$useLocalCurrentObjectStackCache();
	$var($String, language, $nc(base)->getLanguage());
	$var($String, script, base->getScript());
	$var($String, region, base->getRegion());
	$var($String, variant, base->getVariant());
	bool isNorwegianBokmal = false;
	bool isNorwegianNynorsk = false;
	if ($nc(language)->equals("no"_s)) {
		bool var$0 = $nc(region)->equals("NO"_s);
		if (var$0 && $nc(variant)->equals("NY"_s)) {
			$assign(variant, ""_s);
			isNorwegianNynorsk = true;
		} else {
			isNorwegianBokmal = true;
		}
	}
	if ($nc(language)->equals("nb"_s) || isNorwegianBokmal) {
		$var($List, tmpList, getDefaultList("nb"_s, script, region, variant));
		$var($List, bokmalList, $new($LinkedList));
		{
			$var($Iterator, i$, $nc(tmpList)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Locale, l_nb, $cast($Locale, i$->next()));
				{
					bool isRoot = $nc($($nc(l_nb)->getLanguage()))->isEmpty();
					$var($String, var$1, isRoot ? ""_s : "no"_s);
					$var($String, var$2, l_nb->getScript());
					$var($String, var$3, l_nb->getCountry());
					$var($Locale, l_no, $Locale::getInstance(var$1, var$2, var$3, $(l_nb->getVariant()), nullptr));
					bokmalList->add(isNorwegianBokmal ? l_no : l_nb);
					if (isRoot) {
						break;
					}
					bokmalList->add(isNorwegianBokmal ? l_nb : l_no);
				}
			}
		}
		return bokmalList;
	} else if ($nc(language)->equals("nn"_s) || isNorwegianNynorsk) {
		$var($List, nynorskList, getDefaultList("nn"_s, script, region, variant));
		int32_t idx = $nc(nynorskList)->size() - 1;
		nynorskList->add(idx++, $($Locale::getInstance("no"_s, "NO"_s, "NY"_s)));
		nynorskList->add(idx++, $($Locale::getInstance("no"_s, "NO"_s, ""_s)));
		nynorskList->add(idx++, $($Locale::getInstance("no"_s, ""_s, ""_s)));
		return nynorskList;
	} else if ($nc(language)->equals("zh"_s)) {
		bool var$4 = $nc(script)->isEmpty();
		if (var$4 && !$nc(region)->isEmpty()) {
			{
				$var($String, s129098$, region);
				int32_t tmp129098$ = -1;
				switch (s129098$->hashCode()) {
				case 2691:
					{
						if (s129098$->equals("TW"_s)) {
							tmp129098$ = 0;
						}
						break;
					}
				case 2307:
					{
						if (s129098$->equals("HK"_s)) {
							tmp129098$ = 1;
						}
						break;
					}
				case 2466:
					{
						if (s129098$->equals("MO"_s)) {
							tmp129098$ = 2;
						}
						break;
					}
				case 2155:
					{
						if (s129098$->equals("CN"_s)) {
							tmp129098$ = 3;
						}
						break;
					}
				case 2644:
					{
						if (s129098$->equals("SG"_s)) {
							tmp129098$ = 4;
						}
						break;
					}
				}
				switch (tmp129098$) {
				case 0:
					{}
				case 1:
					{}
				case 2:
					{
						$assign(script, "Hant"_s);
						break;
					}
				case 3:
					{}
				case 4:
					{
						$assign(script, "Hans"_s);
						break;
					}
				}
			}
		}
	}
	return getDefaultList(language, script, region, variant);
}

$List* ResourceBundle$Control$CandidateListCache::getDefaultList($String* language, $String* script, $String* region$renamed, $String* variant) {
	$init(ResourceBundle$Control$CandidateListCache);
	$useLocalCurrentObjectStackCache();
	$var($String, region, region$renamed);
	$var($List, variants, nullptr);
	if (!$nc(variant)->isEmpty()) {
		$assign(variants, $new($LinkedList));
		int32_t idx = variant->length();
		while (idx != -1) {
			variants->add($(variant->substring(0, idx)));
			idx = variant->lastIndexOf((int32_t)u'_', --idx);
		}
	}
	$var($List, list, $new($LinkedList));
	if (variants != nullptr) {
		{
			$var($Iterator, i$, variants->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($String, v, $cast($String, i$->next()));
				{
					list->add($($Locale::getInstance(language, script, region, v, nullptr)));
				}
			}
		}
	}
	if (!$nc(region)->isEmpty()) {
		list->add($($Locale::getInstance(language, script, region, ""_s, nullptr)));
	}
	if (!$nc(script)->isEmpty()) {
		list->add($($Locale::getInstance(language, script, ""_s, ""_s, nullptr)));
		if ($nc(language)->equals("zh"_s)) {
			if ($nc(region)->isEmpty()) {
				{
					$var($String, s130799$, script);
					int32_t tmp130799$ = -1;
					switch (s130799$->hashCode()) {
					case 0x0022349E:
						{
							if (s130799$->equals("Hans"_s)) {
								tmp130799$ = 0;
							}
							break;
						}
					case 0x0022349F:
						{
							if (s130799$->equals("Hant"_s)) {
								tmp130799$ = 1;
							}
							break;
						}
					}
					switch (tmp130799$) {
					case 0:
						{
							$assign(region, "CN"_s);
							break;
						}
					case 1:
						{
							$assign(region, "TW"_s);
							break;
						}
					}
				}
			}
		}
		if (variants != nullptr) {
			{
				$var($Iterator, i$, variants->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($String, v, $cast($String, i$->next()));
					{
						list->add($($Locale::getInstance(language, ""_s, region, v, nullptr)));
					}
				}
			}
		}
		if (!$nc(region)->isEmpty()) {
			list->add($($Locale::getInstance(language, ""_s, region, ""_s, nullptr)));
		}
	}
	if (!$nc(language)->isEmpty()) {
		list->add($($Locale::getInstance(language, ""_s, ""_s, ""_s, nullptr)));
	}
	$init($Locale);
	list->add($Locale::ROOT);
	return list;
}

$Object* ResourceBundle$Control$CandidateListCache::createObject(Object$* base) {
	return $of(this->createObject($cast($BaseLocale, base)));
}

ResourceBundle$Control$CandidateListCache::ResourceBundle$Control$CandidateListCache() {
}

$Class* ResourceBundle$Control$CandidateListCache::load$($String* name, bool initialize) {
	$loadClass(ResourceBundle$Control$CandidateListCache, name, initialize, &_ResourceBundle$Control$CandidateListCache_ClassInfo_, allocate$ResourceBundle$Control$CandidateListCache);
	return class$;
}

$Class* ResourceBundle$Control$CandidateListCache::class$ = nullptr;

	} // util
} // java