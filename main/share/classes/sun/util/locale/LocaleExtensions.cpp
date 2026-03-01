#include <sun/util/locale/LocaleExtensions.h>

#include <java/lang/AssertionError.h>
#include <java/util/Collections.h>
#include <java/util/Iterator.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/SortedMap.h>
#include <java/util/SortedSet.h>
#include <java/util/TreeMap.h>
#include <java/util/TreeSet.h>
#include <sun/util/locale/Extension.h>
#include <sun/util/locale/InternalLocaleBuilder$CaseInsensitiveChar.h>
#include <sun/util/locale/InternalLocaleBuilder$CaseInsensitiveString.h>
#include <sun/util/locale/InternalLocaleBuilder.h>
#include <sun/util/locale/LanguageTag.h>
#include <sun/util/locale/LocaleUtils.h>
#include <sun/util/locale/UnicodeLocaleExtension.h>
#include <jcpp.h>

#undef CALENDAR_JAPANESE
#undef CA_JAPANESE
#undef NUMBER_THAI
#undef NU_THAI
#undef SEP
#undef SINGLETON

using $AssertionError = ::java::lang::AssertionError;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Collections = ::java::util::Collections;
using $Iterator = ::java::util::Iterator;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;
using $SortedMap = ::java::util::SortedMap;
using $SortedSet = ::java::util::SortedSet;
using $TreeMap = ::java::util::TreeMap;
using $TreeSet = ::java::util::TreeSet;
using $Extension = ::sun::util::locale::Extension;
using $InternalLocaleBuilder = ::sun::util::locale::InternalLocaleBuilder;
using $InternalLocaleBuilder$CaseInsensitiveChar = ::sun::util::locale::InternalLocaleBuilder$CaseInsensitiveChar;
using $InternalLocaleBuilder$CaseInsensitiveString = ::sun::util::locale::InternalLocaleBuilder$CaseInsensitiveString;
using $LanguageTag = ::sun::util::locale::LanguageTag;
using $LocaleUtils = ::sun::util::locale::LocaleUtils;
using $UnicodeLocaleExtension = ::sun::util::locale::UnicodeLocaleExtension;

namespace sun {
	namespace util {
		namespace locale {

$FieldInfo _LocaleExtensions_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(LocaleExtensions, $assertionsDisabled)},
	{"extensionMap", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/Character;Lsun/util/locale/Extension;>;", $PRIVATE | $FINAL, $field(LocaleExtensions, extensionMap)},
	{"id", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(LocaleExtensions, id)},
	{"CALENDAR_JAPANESE", "Lsun/util/locale/LocaleExtensions;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(LocaleExtensions, CALENDAR_JAPANESE)},
	{"NUMBER_THAI", "Lsun/util/locale/LocaleExtensions;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(LocaleExtensions, NUMBER_THAI)},
	{}
};

$MethodInfo _LocaleExtensions_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Ljava/lang/Character;Lsun/util/locale/Extension;)V", nullptr, $PRIVATE, $method(LocaleExtensions, init$, void, $String*, $Character*, $Extension*)},
	{"<init>", "(Ljava/util/Map;Ljava/util/Set;Ljava/util/Map;)V", "(Ljava/util/Map<Lsun/util/locale/InternalLocaleBuilder$CaseInsensitiveChar;Ljava/lang/String;>;Ljava/util/Set<Lsun/util/locale/InternalLocaleBuilder$CaseInsensitiveString;>;Ljava/util/Map<Lsun/util/locale/InternalLocaleBuilder$CaseInsensitiveString;Ljava/lang/String;>;)V", 0, $method(LocaleExtensions, init$, void, $Map*, $Set*, $Map*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(LocaleExtensions, equals, bool, Object$*)},
	{"getExtension", "(Ljava/lang/Character;)Lsun/util/locale/Extension;", nullptr, $PUBLIC, $virtualMethod(LocaleExtensions, getExtension, $Extension*, $Character*)},
	{"getExtensionValue", "(Ljava/lang/Character;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(LocaleExtensions, getExtensionValue, $String*, $Character*)},
	{"getID", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(LocaleExtensions, getID, $String*)},
	{"getKeys", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/Character;>;", $PUBLIC, $virtualMethod(LocaleExtensions, getKeys, $Set*)},
	{"getUnicodeLocaleAttributes", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(LocaleExtensions, getUnicodeLocaleAttributes, $Set*)},
	{"getUnicodeLocaleKeys", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(LocaleExtensions, getUnicodeLocaleKeys, $Set*)},
	{"getUnicodeLocaleType", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(LocaleExtensions, getUnicodeLocaleType, $String*, $String*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(LocaleExtensions, hashCode, int32_t)},
	{"isEmpty", "()Z", nullptr, $PUBLIC, $virtualMethod(LocaleExtensions, isEmpty, bool)},
	{"isValidKey", "(C)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(LocaleExtensions, isValidKey, bool, char16_t)},
	{"isValidUnicodeLocaleKey", "(Ljava/lang/String;)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(LocaleExtensions, isValidUnicodeLocaleKey, bool, $String*)},
	{"toID", "(Ljava/util/SortedMap;)Ljava/lang/String;", "(Ljava/util/SortedMap<Ljava/lang/Character;Lsun/util/locale/Extension;>;)Ljava/lang/String;", $PRIVATE | $STATIC, $staticMethod(LocaleExtensions, toID, $String*, $SortedMap*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(LocaleExtensions, toString, $String*)},
	{}
};

$ClassInfo _LocaleExtensions_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.util.locale.LocaleExtensions",
	"java.lang.Object",
	nullptr,
	_LocaleExtensions_FieldInfo_,
	_LocaleExtensions_MethodInfo_
};

$Object* allocate$LocaleExtensions($Class* clazz) {
	return $of($alloc(LocaleExtensions));
}

bool LocaleExtensions::$assertionsDisabled = false;
LocaleExtensions* LocaleExtensions::CALENDAR_JAPANESE = nullptr;
LocaleExtensions* LocaleExtensions::NUMBER_THAI = nullptr;

void LocaleExtensions::init$($String* id, $Character* key, $Extension* value) {
	$set(this, id, id);
	$set(this, extensionMap, $Collections::singletonMap(key, value));
}

void LocaleExtensions::init$($Map* extensions, $Set* uattributes, $Map* ukeywords) {
	$useLocalCurrentObjectStackCache();
	bool hasExtension = !$LocaleUtils::isEmpty(extensions);
	bool hasUAttributes = !$LocaleUtils::isEmpty(uattributes);
	bool hasUKeywords = !$LocaleUtils::isEmpty(ukeywords);
	if (!hasExtension && !hasUAttributes && !hasUKeywords) {
		$set(this, id, ""_s);
		$set(this, extensionMap, $Collections::emptyMap());
		return;
	}
	$var($SortedMap, map, $new($TreeMap));
	if (hasExtension) {
		{
			$var($Iterator, i$, $nc($($nc(extensions)->entrySet()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Map$Entry, ext, $cast($Map$Entry, i$->next()));
				{
					char16_t key = $LocaleUtils::toLower($nc(($cast($InternalLocaleBuilder$CaseInsensitiveChar, $($nc(ext)->getKey()))))->value());
					$var($String, value, $cast($String, $nc(ext)->getValue()));
					if ($LanguageTag::isPrivateusePrefixChar(key)) {
						$assign(value, $InternalLocaleBuilder::removePrivateuseVariant(value));
						if (value == nullptr) {
							continue;
						}
					}
					$var($Object, var$0, $of($Character::valueOf(key)));
					map->put(var$0, $$new($Extension, key, $($LocaleUtils::toLowerString(value))));
				}
			}
		}
	}
	if (hasUAttributes || hasUKeywords) {
		$var($SortedSet, uaset, nullptr);
		$var($SortedMap, ukmap, nullptr);
		if (hasUAttributes) {
			$assign(uaset, $new($TreeSet));
			{
				$var($Iterator, i$, $nc(uattributes)->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($InternalLocaleBuilder$CaseInsensitiveString, cis, $cast($InternalLocaleBuilder$CaseInsensitiveString, i$->next()));
					{
						uaset->add($($LocaleUtils::toLowerString($($nc(cis)->value()))));
					}
				}
			}
		}
		if (hasUKeywords) {
			$assign(ukmap, $new($TreeMap));
			{
				$var($Iterator, i$, $nc($($nc(ukeywords)->entrySet()))->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($Map$Entry, kwd, $cast($Map$Entry, i$->next()));
					{
						$var($String, key, $LocaleUtils::toLowerString($($nc(($cast($InternalLocaleBuilder$CaseInsensitiveString, $($nc(kwd)->getKey()))))->value())));
						$var($String, type, $LocaleUtils::toLowerString($cast($String, $($nc(kwd)->getValue()))));
						ukmap->put(key, type);
					}
				}
			}
		}
		$var($UnicodeLocaleExtension, ule, $new($UnicodeLocaleExtension, uaset, ukmap));
		map->put($($Character::valueOf($UnicodeLocaleExtension::SINGLETON)), ule);
	}
	if (map->isEmpty()) {
		$set(this, id, ""_s);
		$set(this, extensionMap, $Collections::emptyMap());
	} else {
		$set(this, id, toID(map));
		$set(this, extensionMap, map);
	}
}

$Set* LocaleExtensions::getKeys() {
	if ($nc(this->extensionMap)->isEmpty()) {
		return $Collections::emptySet();
	}
	return $Collections::unmodifiableSet($($nc(this->extensionMap)->keySet()));
}

$Extension* LocaleExtensions::getExtension($Character* key) {
	return $cast($Extension, $nc(this->extensionMap)->get($($Character::valueOf($LocaleUtils::toLower($nc(key)->charValue())))));
}

$String* LocaleExtensions::getExtensionValue($Character* key) {
	$useLocalCurrentObjectStackCache();
	$var($Extension, ext, $cast($Extension, $nc(this->extensionMap)->get($($Character::valueOf($LocaleUtils::toLower($nc(key)->charValue()))))));
	if (ext == nullptr) {
		return nullptr;
	}
	return $nc(ext)->getValue();
}

$Set* LocaleExtensions::getUnicodeLocaleAttributes() {
	$useLocalCurrentObjectStackCache();
	$var($Extension, ext, $cast($Extension, $nc(this->extensionMap)->get($($Character::valueOf($UnicodeLocaleExtension::SINGLETON)))));
	if (ext == nullptr) {
		return $Collections::emptySet();
	}
	if (!LocaleExtensions::$assertionsDisabled && !($instanceOf($UnicodeLocaleExtension, ext))) {
		$throwNew($AssertionError);
	}
	return $nc(($cast($UnicodeLocaleExtension, ext)))->getUnicodeLocaleAttributes();
}

$Set* LocaleExtensions::getUnicodeLocaleKeys() {
	$useLocalCurrentObjectStackCache();
	$var($Extension, ext, $cast($Extension, $nc(this->extensionMap)->get($($Character::valueOf($UnicodeLocaleExtension::SINGLETON)))));
	if (ext == nullptr) {
		return $Collections::emptySet();
	}
	if (!LocaleExtensions::$assertionsDisabled && !($instanceOf($UnicodeLocaleExtension, ext))) {
		$throwNew($AssertionError);
	}
	return $nc(($cast($UnicodeLocaleExtension, ext)))->getUnicodeLocaleKeys();
}

$String* LocaleExtensions::getUnicodeLocaleType($String* unicodeLocaleKey) {
	$useLocalCurrentObjectStackCache();
	$var($Extension, ext, $cast($Extension, $nc(this->extensionMap)->get($($Character::valueOf($UnicodeLocaleExtension::SINGLETON)))));
	if (ext == nullptr) {
		return nullptr;
	}
	if (!LocaleExtensions::$assertionsDisabled && !($instanceOf($UnicodeLocaleExtension, ext))) {
		$throwNew($AssertionError);
	}
	return $nc(($cast($UnicodeLocaleExtension, ext)))->getUnicodeLocaleType($($LocaleUtils::toLowerString(unicodeLocaleKey)));
}

bool LocaleExtensions::isEmpty() {
	return $nc(this->extensionMap)->isEmpty();
}

bool LocaleExtensions::isValidKey(char16_t c) {
	$init(LocaleExtensions);
	bool var$0 = $LanguageTag::isExtensionSingletonChar(c);
	return var$0 || $LanguageTag::isPrivateusePrefixChar(c);
}

bool LocaleExtensions::isValidUnicodeLocaleKey($String* ukey) {
	$init(LocaleExtensions);
	return $UnicodeLocaleExtension::isKey(ukey);
}

$String* LocaleExtensions::toID($SortedMap* map) {
	$init(LocaleExtensions);
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, buf, $new($StringBuilder));
	$var($Extension, privuse, nullptr);
	{
		$var($Iterator, i$, $nc($($nc(map)->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
			{
				char16_t singleton = $nc(($cast($Character, $($nc(entry)->getKey()))))->charValue();
				$var($Extension, extension, $cast($Extension, entry->getValue()));
				if ($LanguageTag::isPrivateusePrefixChar(singleton)) {
					$assign(privuse, extension);
				} else {
					if (buf->length() > 0) {
						$init($LanguageTag);
						buf->append($LanguageTag::SEP);
					}
					buf->append($of(extension));
				}
			}
		}
	}
	if (privuse != nullptr) {
		if (buf->length() > 0) {
			$init($LanguageTag);
			buf->append($LanguageTag::SEP);
		}
		buf->append($of(privuse));
	}
	return buf->toString();
}

$String* LocaleExtensions::toString() {
	return this->id;
}

$String* LocaleExtensions::getID() {
	return this->id;
}

int32_t LocaleExtensions::hashCode() {
	return $nc(this->id)->hashCode();
}

bool LocaleExtensions::equals(Object$* other) {
	if ($equals(this, other)) {
		return true;
	}
	if (!($instanceOf(LocaleExtensions, other))) {
		return false;
	}
	return $nc(this->id)->equals($nc(($cast(LocaleExtensions, other)))->id);
}

void clinit$LocaleExtensions($Class* class$) {
	$useLocalCurrentObjectStackCache();
	LocaleExtensions::$assertionsDisabled = !LocaleExtensions::class$->desiredAssertionStatus();
	$init($UnicodeLocaleExtension);
	$assignStatic(LocaleExtensions::CALENDAR_JAPANESE, $new(LocaleExtensions, "u-ca-japanese"_s, $($Character::valueOf($UnicodeLocaleExtension::SINGLETON)), static_cast<$Extension*>($UnicodeLocaleExtension::CA_JAPANESE)));
	$assignStatic(LocaleExtensions::NUMBER_THAI, $new(LocaleExtensions, "u-nu-thai"_s, $($Character::valueOf($UnicodeLocaleExtension::SINGLETON)), static_cast<$Extension*>($UnicodeLocaleExtension::NU_THAI)));
}

LocaleExtensions::LocaleExtensions() {
}

$Class* LocaleExtensions::load$($String* name, bool initialize) {
	$loadClass(LocaleExtensions, name, initialize, &_LocaleExtensions_ClassInfo_, clinit$LocaleExtensions, allocate$LocaleExtensions);
	return class$;
}

$Class* LocaleExtensions::class$ = nullptr;

		} // locale
	} // util
} // sun