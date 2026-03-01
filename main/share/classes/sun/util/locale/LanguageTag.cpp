#include <sun/util/locale/LanguageTag.h>

#include <java/lang/CharSequence.h>
#include <java/util/ArrayList.h>
#include <java/util/Collections.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/StringJoiner.h>
#include <sun/util/locale/BaseLocale.h>
#include <sun/util/locale/Extension.h>
#include <sun/util/locale/LocaleExtensions.h>
#include <sun/util/locale/LocaleUtils.h>
#include <sun/util/locale/ParseStatus.h>
#include <sun/util/locale/StringTokenIterator.h>
#include <jcpp.h>

#undef LEGACY
#undef PRIVATEUSE
#undef PRIVUSE_VARIANT_PREFIX
#undef SEP
#undef UNDETERMINED

using $StringArray2 = $Array<::java::lang::String, 2>;
using $CharSequence = ::java::lang::CharSequence;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ArrayList = ::java::util::ArrayList;
using $Collections = ::java::util::Collections;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $StringJoiner = ::java::util::StringJoiner;
using $BaseLocale = ::sun::util::locale::BaseLocale;
using $Extension = ::sun::util::locale::Extension;
using $LocaleExtensions = ::sun::util::locale::LocaleExtensions;
using $LocaleUtils = ::sun::util::locale::LocaleUtils;
using $ParseStatus = ::sun::util::locale::ParseStatus;
using $StringTokenIterator = ::sun::util::locale::StringTokenIterator;

namespace sun {
	namespace util {
		namespace locale {

$FieldInfo _LanguageTag_FieldInfo_[] = {
	{"SEP", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(LanguageTag, SEP)},
	{"PRIVATEUSE", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(LanguageTag, PRIVATEUSE)},
	{"UNDETERMINED", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(LanguageTag, UNDETERMINED)},
	{"PRIVUSE_VARIANT_PREFIX", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(LanguageTag, PRIVUSE_VARIANT_PREFIX)},
	{"language", "Ljava/lang/String;", nullptr, $PRIVATE, $field(LanguageTag, language)},
	{"script", "Ljava/lang/String;", nullptr, $PRIVATE, $field(LanguageTag, script)},
	{"region", "Ljava/lang/String;", nullptr, $PRIVATE, $field(LanguageTag, region)},
	{"privateuse", "Ljava/lang/String;", nullptr, $PRIVATE, $field(LanguageTag, privateuse)},
	{"extlangs", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/String;>;", $PRIVATE, $field(LanguageTag, extlangs)},
	{"variants", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/String;>;", $PRIVATE, $field(LanguageTag, variants)},
	{"extensions", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/String;>;", $PRIVATE, $field(LanguageTag, extensions)},
	{"LEGACY", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;[Ljava/lang/String;>;", $PRIVATE | $STATIC | $FINAL, $staticField(LanguageTag, LEGACY)},
	{}
};

$MethodInfo _LanguageTag_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(LanguageTag, init$, void)},
	{"canonicalizeExtension", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(LanguageTag, canonicalizeExtension, $String*, $String*)},
	{"canonicalizeExtensionSingleton", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(LanguageTag, canonicalizeExtensionSingleton, $String*, $String*)},
	{"canonicalizeExtensionSubtag", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(LanguageTag, canonicalizeExtensionSubtag, $String*, $String*)},
	{"canonicalizeExtlang", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(LanguageTag, canonicalizeExtlang, $String*, $String*)},
	{"canonicalizeLanguage", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(LanguageTag, canonicalizeLanguage, $String*, $String*)},
	{"canonicalizePrivateuse", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(LanguageTag, canonicalizePrivateuse, $String*, $String*)},
	{"canonicalizePrivateuseSubtag", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(LanguageTag, canonicalizePrivateuseSubtag, $String*, $String*)},
	{"canonicalizeRegion", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(LanguageTag, canonicalizeRegion, $String*, $String*)},
	{"canonicalizeScript", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(LanguageTag, canonicalizeScript, $String*, $String*)},
	{"canonicalizeVariant", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(LanguageTag, canonicalizeVariant, $String*, $String*)},
	{"getExtensions", "()Ljava/util/List;", "()Ljava/util/List<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(LanguageTag, getExtensions, $List*)},
	{"getExtlangs", "()Ljava/util/List;", "()Ljava/util/List<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(LanguageTag, getExtlangs, $List*)},
	{"getLanguage", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(LanguageTag, getLanguage, $String*)},
	{"getPrivateuse", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(LanguageTag, getPrivateuse, $String*)},
	{"getRegion", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(LanguageTag, getRegion, $String*)},
	{"getScript", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(LanguageTag, getScript, $String*)},
	{"getVariants", "()Ljava/util/List;", "()Ljava/util/List<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(LanguageTag, getVariants, $List*)},
	{"isExtensionSingleton", "(Ljava/lang/String;)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(LanguageTag, isExtensionSingleton, bool, $String*)},
	{"isExtensionSingletonChar", "(C)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(LanguageTag, isExtensionSingletonChar, bool, char16_t)},
	{"isExtensionSubtag", "(Ljava/lang/String;)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(LanguageTag, isExtensionSubtag, bool, $String*)},
	{"isExtlang", "(Ljava/lang/String;)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(LanguageTag, isExtlang, bool, $String*)},
	{"isLanguage", "(Ljava/lang/String;)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(LanguageTag, isLanguage, bool, $String*)},
	{"isPrivateusePrefix", "(Ljava/lang/String;)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(LanguageTag, isPrivateusePrefix, bool, $String*)},
	{"isPrivateusePrefixChar", "(C)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(LanguageTag, isPrivateusePrefixChar, bool, char16_t)},
	{"isPrivateuseSubtag", "(Ljava/lang/String;)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(LanguageTag, isPrivateuseSubtag, bool, $String*)},
	{"isRegion", "(Ljava/lang/String;)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(LanguageTag, isRegion, bool, $String*)},
	{"isScript", "(Ljava/lang/String;)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(LanguageTag, isScript, bool, $String*)},
	{"isVariant", "(Ljava/lang/String;)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(LanguageTag, isVariant, bool, $String*)},
	{"parse", "(Ljava/lang/String;Lsun/util/locale/ParseStatus;)Lsun/util/locale/LanguageTag;", nullptr, $PUBLIC | $STATIC, $staticMethod(LanguageTag, parse, LanguageTag*, $String*, $ParseStatus*)},
	{"parseExtensions", "(Lsun/util/locale/StringTokenIterator;Lsun/util/locale/ParseStatus;)Z", nullptr, $PRIVATE, $method(LanguageTag, parseExtensions, bool, $StringTokenIterator*, $ParseStatus*)},
	{"parseExtlangs", "(Lsun/util/locale/StringTokenIterator;Lsun/util/locale/ParseStatus;)Z", nullptr, $PRIVATE, $method(LanguageTag, parseExtlangs, bool, $StringTokenIterator*, $ParseStatus*)},
	{"parseLanguage", "(Lsun/util/locale/StringTokenIterator;Lsun/util/locale/ParseStatus;)Z", nullptr, $PRIVATE, $method(LanguageTag, parseLanguage, bool, $StringTokenIterator*, $ParseStatus*)},
	{"parseLocale", "(Lsun/util/locale/BaseLocale;Lsun/util/locale/LocaleExtensions;)Lsun/util/locale/LanguageTag;", nullptr, $PUBLIC | $STATIC, $staticMethod(LanguageTag, parseLocale, LanguageTag*, $BaseLocale*, $LocaleExtensions*)},
	{"parsePrivateuse", "(Lsun/util/locale/StringTokenIterator;Lsun/util/locale/ParseStatus;)Z", nullptr, $PRIVATE, $method(LanguageTag, parsePrivateuse, bool, $StringTokenIterator*, $ParseStatus*)},
	{"parseRegion", "(Lsun/util/locale/StringTokenIterator;Lsun/util/locale/ParseStatus;)Z", nullptr, $PRIVATE, $method(LanguageTag, parseRegion, bool, $StringTokenIterator*, $ParseStatus*)},
	{"parseScript", "(Lsun/util/locale/StringTokenIterator;Lsun/util/locale/ParseStatus;)Z", nullptr, $PRIVATE, $method(LanguageTag, parseScript, bool, $StringTokenIterator*, $ParseStatus*)},
	{"parseVariants", "(Lsun/util/locale/StringTokenIterator;Lsun/util/locale/ParseStatus;)Z", nullptr, $PRIVATE, $method(LanguageTag, parseVariants, bool, $StringTokenIterator*, $ParseStatus*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(LanguageTag, toString, $String*)},
	{}
};

$ClassInfo _LanguageTag_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.util.locale.LanguageTag",
	"java.lang.Object",
	nullptr,
	_LanguageTag_FieldInfo_,
	_LanguageTag_MethodInfo_
};

$Object* allocate$LanguageTag($Class* clazz) {
	return $of($alloc(LanguageTag));
}

$String* LanguageTag::SEP = nullptr;
$String* LanguageTag::PRIVATEUSE = nullptr;
$String* LanguageTag::UNDETERMINED = nullptr;
$String* LanguageTag::PRIVUSE_VARIANT_PREFIX = nullptr;
$Map* LanguageTag::LEGACY = nullptr;

void LanguageTag::init$() {
	$set(this, language, ""_s);
	$set(this, script, ""_s);
	$set(this, region, ""_s);
	$set(this, privateuse, ""_s);
	$set(this, extlangs, $Collections::emptyList());
	$set(this, variants, $Collections::emptyList());
	$set(this, extensions, $Collections::emptyList());
}

LanguageTag* LanguageTag::parse($String* languageTag, $ParseStatus* sts$renamed) {
	$init(LanguageTag);
	$useLocalCurrentObjectStackCache();
	$var($ParseStatus, sts, sts$renamed);
	if (sts == nullptr) {
		$assign(sts, $new($ParseStatus));
	} else {
		$nc(sts)->reset();
	}
	$var($StringTokenIterator, itr, nullptr);
	$var($StringArray, gfmap, $cast($StringArray, $nc(LanguageTag::LEGACY)->get($($LocaleUtils::toLowerString(languageTag)))));
	if (gfmap != nullptr) {
		$assign(itr, $new($StringTokenIterator, gfmap->get(1), LanguageTag::SEP));
	} else {
		$assign(itr, $new($StringTokenIterator, languageTag, LanguageTag::SEP));
	}
	$var(LanguageTag, tag, $new(LanguageTag));
	if (tag->parseLanguage(itr, sts)) {
		tag->parseExtlangs(itr, sts);
		tag->parseScript(itr, sts);
		tag->parseRegion(itr, sts);
		tag->parseVariants(itr, sts);
		tag->parseExtensions(itr, sts);
	}
	tag->parsePrivateuse(itr, sts);
	bool var$0 = !$nc(itr)->isDone();
	if (var$0 && !$nc(sts)->isError()) {
		$var($String, s, itr->current());
		sts->errorIndex = itr->currentStart();
		if ($nc(s)->isEmpty()) {
			$set(sts, errorMsg, "Empty subtag"_s);
		} else {
			$set(sts, errorMsg, $str({"Invalid subtag: "_s, s}));
		}
	}
	return tag;
}

bool LanguageTag::parseLanguage($StringTokenIterator* itr, $ParseStatus* sts) {
	bool var$0 = $nc(itr)->isDone();
	if (var$0 || $nc(sts)->isError()) {
		return false;
	}
	bool found = false;
	$var($String, s, $nc(itr)->current());
	if (isLanguage(s)) {
		found = true;
		$set(this, language, s);
		$nc(sts)->parseLength = itr->currentEnd();
		itr->next();
	}
	return found;
}

bool LanguageTag::parseExtlangs($StringTokenIterator* itr, $ParseStatus* sts) {
	$useLocalCurrentObjectStackCache();
	bool var$0 = $nc(itr)->isDone();
	if (var$0 || $nc(sts)->isError()) {
		return false;
	}
	bool found = false;
	while (!$nc(itr)->isDone()) {
		$var($String, s, itr->current());
		if (!isExtlang(s)) {
			break;
		}
		found = true;
		if ($nc(this->extlangs)->isEmpty()) {
			$set(this, extlangs, $new($ArrayList, 3));
		}
		$nc(this->extlangs)->add(s);
		$nc(sts)->parseLength = itr->currentEnd();
		itr->next();
		if ($nc(this->extlangs)->size() == 3) {
			break;
		}
	}
	return found;
}

bool LanguageTag::parseScript($StringTokenIterator* itr, $ParseStatus* sts) {
	bool var$0 = $nc(itr)->isDone();
	if (var$0 || $nc(sts)->isError()) {
		return false;
	}
	bool found = false;
	$var($String, s, $nc(itr)->current());
	if (isScript(s)) {
		found = true;
		$set(this, script, s);
		$nc(sts)->parseLength = itr->currentEnd();
		itr->next();
	}
	return found;
}

bool LanguageTag::parseRegion($StringTokenIterator* itr, $ParseStatus* sts) {
	bool var$0 = $nc(itr)->isDone();
	if (var$0 || $nc(sts)->isError()) {
		return false;
	}
	bool found = false;
	$var($String, s, $nc(itr)->current());
	if (isRegion(s)) {
		found = true;
		$set(this, region, s);
		$nc(sts)->parseLength = itr->currentEnd();
		itr->next();
	}
	return found;
}

bool LanguageTag::parseVariants($StringTokenIterator* itr, $ParseStatus* sts) {
	$useLocalCurrentObjectStackCache();
	bool var$0 = $nc(itr)->isDone();
	if (var$0 || $nc(sts)->isError()) {
		return false;
	}
	bool found = false;
	while (!$nc(itr)->isDone()) {
		$var($String, s, itr->current());
		if (!isVariant(s)) {
			break;
		}
		found = true;
		if ($nc(this->variants)->isEmpty()) {
			$set(this, variants, $new($ArrayList, 3));
		}
		$nc(this->variants)->add(s);
		$nc(sts)->parseLength = itr->currentEnd();
		itr->next();
	}
	return found;
}

bool LanguageTag::parseExtensions($StringTokenIterator* itr, $ParseStatus* sts) {
	$useLocalCurrentObjectStackCache();
	bool var$0 = $nc(itr)->isDone();
	if (var$0 || $nc(sts)->isError()) {
		return false;
	}
	bool found = false;
	while (!$nc(itr)->isDone()) {
		$var($String, s, itr->current());
		if (isExtensionSingleton(s)) {
			int32_t start = itr->currentStart();
			$var($String, singleton, s);
			$var($StringBuilder, sb, $new($StringBuilder, singleton));
			itr->next();
			while (!itr->isDone()) {
				$assign(s, itr->current());
				if (isExtensionSubtag(s)) {
					sb->append(LanguageTag::SEP)->append(s);
					$nc(sts)->parseLength = itr->currentEnd();
				} else {
					break;
				}
				itr->next();
			}
			if ($nc(sts)->parseLength <= start) {
				sts->errorIndex = start;
				$set(sts, errorMsg, $str({"Incomplete extension \'"_s, singleton, "\'"_s}));
				break;
			}
			if ($nc(this->extensions)->isEmpty()) {
				$set(this, extensions, $new($ArrayList, 4));
			}
			$nc(this->extensions)->add($(sb->toString()));
			found = true;
		} else {
			break;
		}
	}
	return found;
}

bool LanguageTag::parsePrivateuse($StringTokenIterator* itr, $ParseStatus* sts) {
	$useLocalCurrentObjectStackCache();
	bool var$0 = $nc(itr)->isDone();
	if (var$0 || $nc(sts)->isError()) {
		return false;
	}
	bool found = false;
	$var($String, s, $nc(itr)->current());
	if (isPrivateusePrefix(s)) {
		int32_t start = itr->currentStart();
		$var($StringBuilder, sb, $new($StringBuilder, s));
		itr->next();
		while (!itr->isDone()) {
			$assign(s, itr->current());
			if (!isPrivateuseSubtag(s)) {
				break;
			}
			sb->append(LanguageTag::SEP)->append(s);
			$nc(sts)->parseLength = itr->currentEnd();
			itr->next();
		}
		if ($nc(sts)->parseLength <= start) {
			sts->errorIndex = start;
			$set(sts, errorMsg, "Incomplete privateuse"_s);
		} else {
			$set(this, privateuse, sb->toString());
			found = true;
		}
	}
	return found;
}

LanguageTag* LanguageTag::parseLocale($BaseLocale* baseLocale, $LocaleExtensions* localeExtensions) {
	$init(LanguageTag);
	$useLocalCurrentObjectStackCache();
	$var(LanguageTag, tag, $new(LanguageTag));
	$var($String, language, $nc(baseLocale)->getLanguage());
	$var($String, script, baseLocale->getScript());
	$var($String, region, baseLocale->getRegion());
	$var($String, variant, baseLocale->getVariant());
	bool hasSubtag = false;
	$var($String, privuseVar, nullptr);
	if (isLanguage(language)) {
		if ($nc(language)->equals("iw"_s)) {
			$assign(language, "he"_s);
		} else if (language->equals("ji"_s)) {
			$assign(language, "yi"_s);
		} else if (language->equals("in"_s)) {
			$assign(language, "id"_s);
		}
		$set(tag, language, language);
	}
	if (isScript(script)) {
		$set(tag, script, canonicalizeScript(script));
		hasSubtag = true;
	}
	if (isRegion(region)) {
		$set(tag, region, canonicalizeRegion(region));
		hasSubtag = true;
	}
	bool var$1 = $nc(tag->language)->equals("no"_s);
	bool var$0 = var$1 && $nc(tag->region)->equals("NO"_s);
	if (var$0 && $nc(variant)->equals("NY"_s)) {
		$set(tag, language, "nn"_s);
		$assign(variant, ""_s);
	}
	if (!$nc(variant)->isEmpty()) {
		$var($List, variants, nullptr);
		$var($StringTokenIterator, varitr, $new($StringTokenIterator, variant, $BaseLocale::SEP));
		while (!varitr->isDone()) {
			$var($String, var, varitr->current());
			if (!isVariant(var)) {
				break;
			}
			if (variants == nullptr) {
				$assign(variants, $new($ArrayList));
			}
			$nc(variants)->add(var);
			varitr->next();
		}
		if (variants != nullptr) {
			$set(tag, variants, variants);
			hasSubtag = true;
		}
		if (!varitr->isDone()) {
			$var($StringJoiner, sj, $new($StringJoiner, LanguageTag::SEP));
			while (!varitr->isDone()) {
				$var($String, prvv, varitr->current());
				if (!isPrivateuseSubtag(prvv)) {
					break;
				}
				sj->add(prvv);
				varitr->next();
			}
			if (sj->length() > 0) {
				$assign(privuseVar, sj->toString());
			}
		}
	}
	$var($List, extensions, nullptr);
	$var($String, privateuse, nullptr);
	if (localeExtensions != nullptr) {
		$var($Set, locextKeys, localeExtensions->getKeys());
		{
			$var($Iterator, i$, $nc(locextKeys)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Character, locextKey, $cast($Character, i$->next()));
				{
					$var($Extension, ext, localeExtensions->getExtension(locextKey));
					if (isPrivateusePrefixChar($nc(locextKey)->charValue())) {
						$assign(privateuse, $nc(ext)->getValue());
					} else {
						if (extensions == nullptr) {
							$assign(extensions, $new($ArrayList));
						}
						$var($String, var$2, $$str({$($nc(locextKey)->toString()), LanguageTag::SEP}));
						$nc(extensions)->add($$concat(var$2, $($nc(ext)->getValue())));
					}
				}
			}
		}
	}
	if (extensions != nullptr) {
		$set(tag, extensions, extensions);
		hasSubtag = true;
	}
	if (privuseVar != nullptr) {
		if (privateuse == nullptr) {
			$assign(privateuse, $str({LanguageTag::PRIVUSE_VARIANT_PREFIX, LanguageTag::SEP, privuseVar}));
		} else {
			$assign(privateuse, $str({privateuse, LanguageTag::SEP, LanguageTag::PRIVUSE_VARIANT_PREFIX, LanguageTag::SEP, $(privuseVar->replace(static_cast<$CharSequence*>($BaseLocale::SEP), static_cast<$CharSequence*>(LanguageTag::SEP)))}));
		}
	}
	if (privateuse != nullptr) {
		$set(tag, privateuse, privateuse);
	}
	if ($nc(tag->language)->isEmpty() && (hasSubtag || privateuse == nullptr)) {
		$set(tag, language, LanguageTag::UNDETERMINED);
	}
	return tag;
}

$String* LanguageTag::getLanguage() {
	return this->language;
}

$List* LanguageTag::getExtlangs() {
	if ($nc(this->extlangs)->isEmpty()) {
		return $Collections::emptyList();
	}
	return $Collections::unmodifiableList(this->extlangs);
}

$String* LanguageTag::getScript() {
	return this->script;
}

$String* LanguageTag::getRegion() {
	return this->region;
}

$List* LanguageTag::getVariants() {
	if ($nc(this->variants)->isEmpty()) {
		return $Collections::emptyList();
	}
	return $Collections::unmodifiableList(this->variants);
}

$List* LanguageTag::getExtensions() {
	if ($nc(this->extensions)->isEmpty()) {
		return $Collections::emptyList();
	}
	return $Collections::unmodifiableList(this->extensions);
}

$String* LanguageTag::getPrivateuse() {
	return this->privateuse;
}

bool LanguageTag::isLanguage($String* s) {
	$init(LanguageTag);
	int32_t len = $nc(s)->length();
	return (len >= 2) && (len <= 8) && $LocaleUtils::isAlphaString(s);
}

bool LanguageTag::isExtlang($String* s) {
	$init(LanguageTag);
	bool var$0 = ($nc(s)->length() == 3);
	return var$0 && $LocaleUtils::isAlphaString(s);
}

bool LanguageTag::isScript($String* s) {
	$init(LanguageTag);
	bool var$0 = ($nc(s)->length() == 4);
	return var$0 && $LocaleUtils::isAlphaString(s);
}

bool LanguageTag::isRegion($String* s) {
	$init(LanguageTag);
	bool var$1 = ($nc(s)->length() == 2);
	bool var$0 = (var$1 && $LocaleUtils::isAlphaString(s));
	if (!var$0) {
		bool var$2 = ($nc(s)->length() == 3);
		var$0 = (var$2 && $LocaleUtils::isNumericString(s));
	}
	return var$0;
}

bool LanguageTag::isVariant($String* s) {
	$init(LanguageTag);
	int32_t len = $nc(s)->length();
	if (len >= 5 && len <= 8) {
		return $LocaleUtils::isAlphaNumericString(s);
	}
	if (len == 4) {
		bool var$2 = $LocaleUtils::isNumeric(s->charAt(0));
		bool var$1 = var$2 && $LocaleUtils::isAlphaNumeric(s->charAt(1));
		bool var$0 = var$1 && $LocaleUtils::isAlphaNumeric(s->charAt(2));
		return var$0 && $LocaleUtils::isAlphaNumeric(s->charAt(3));
	}
	return false;
}

bool LanguageTag::isExtensionSingleton($String* s) {
	$init(LanguageTag);
	bool var$1 = ($nc(s)->length() == 1);
	bool var$0 = var$1 && $LocaleUtils::isAlphaString(s);
	return var$0 && !$LocaleUtils::caseIgnoreMatch(LanguageTag::PRIVATEUSE, s);
}

bool LanguageTag::isExtensionSingletonChar(char16_t c) {
	$init(LanguageTag);
	return isExtensionSingleton($($String::valueOf(c)));
}

bool LanguageTag::isExtensionSubtag($String* s) {
	$init(LanguageTag);
	int32_t len = $nc(s)->length();
	return (len >= 2) && (len <= 8) && $LocaleUtils::isAlphaNumericString(s);
}

bool LanguageTag::isPrivateusePrefix($String* s) {
	$init(LanguageTag);
	bool var$0 = ($nc(s)->length() == 1);
	return var$0 && $LocaleUtils::caseIgnoreMatch(LanguageTag::PRIVATEUSE, s);
}

bool LanguageTag::isPrivateusePrefixChar(char16_t c) {
	$init(LanguageTag);
	return ($LocaleUtils::caseIgnoreMatch(LanguageTag::PRIVATEUSE, $($String::valueOf(c))));
}

bool LanguageTag::isPrivateuseSubtag($String* s) {
	$init(LanguageTag);
	int32_t len = $nc(s)->length();
	return (len >= 1) && (len <= 8) && $LocaleUtils::isAlphaNumericString(s);
}

$String* LanguageTag::canonicalizeLanguage($String* s) {
	$init(LanguageTag);
	return $LocaleUtils::toLowerString(s);
}

$String* LanguageTag::canonicalizeExtlang($String* s) {
	$init(LanguageTag);
	return $LocaleUtils::toLowerString(s);
}

$String* LanguageTag::canonicalizeScript($String* s) {
	$init(LanguageTag);
	return $LocaleUtils::toTitleString(s);
}

$String* LanguageTag::canonicalizeRegion($String* s) {
	$init(LanguageTag);
	return $LocaleUtils::toUpperString(s);
}

$String* LanguageTag::canonicalizeVariant($String* s) {
	$init(LanguageTag);
	return $LocaleUtils::toLowerString(s);
}

$String* LanguageTag::canonicalizeExtension($String* s) {
	$init(LanguageTag);
	return $LocaleUtils::toLowerString(s);
}

$String* LanguageTag::canonicalizeExtensionSingleton($String* s) {
	$init(LanguageTag);
	return $LocaleUtils::toLowerString(s);
}

$String* LanguageTag::canonicalizeExtensionSubtag($String* s) {
	$init(LanguageTag);
	return $LocaleUtils::toLowerString(s);
}

$String* LanguageTag::canonicalizePrivateuse($String* s) {
	$init(LanguageTag);
	return $LocaleUtils::toLowerString(s);
}

$String* LanguageTag::canonicalizePrivateuseSubtag($String* s) {
	$init(LanguageTag);
	return $LocaleUtils::toLowerString(s);
}

$String* LanguageTag::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	if (!$nc(this->language)->isEmpty()) {
		sb->append(this->language);
		{
			$var($Iterator, i$, $nc(this->extlangs)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($String, extlang, $cast($String, i$->next()));
				{
					sb->append(LanguageTag::SEP)->append(extlang);
				}
			}
		}
		if (!$nc(this->script)->isEmpty()) {
			sb->append(LanguageTag::SEP)->append(this->script);
		}
		if (!$nc(this->region)->isEmpty()) {
			sb->append(LanguageTag::SEP)->append(this->region);
		}
		{
			$var($Iterator, i$, $nc(this->variants)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($String, variant, $cast($String, i$->next()));
				{
					sb->append(LanguageTag::SEP)->append(variant);
				}
			}
		}
		{
			$var($Iterator, i$, $nc(this->extensions)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($String, extension, $cast($String, i$->next()));
				{
					sb->append(LanguageTag::SEP)->append(extension);
				}
			}
		}
	}
	if (!$nc(this->privateuse)->isEmpty()) {
		if (sb->length() > 0) {
			sb->append(LanguageTag::SEP);
		}
		sb->append(this->privateuse);
	}
	return sb->toString();
}

void clinit$LanguageTag($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(LanguageTag::SEP, "-"_s);
	$assignStatic(LanguageTag::PRIVATEUSE, "x"_s);
	$assignStatic(LanguageTag::UNDETERMINED, "und"_s);
	$assignStatic(LanguageTag::PRIVUSE_VARIANT_PREFIX, "lvariant"_s);
	$assignStatic(LanguageTag::LEGACY, $new($HashMap));
	{
		$var($StringArray2, entries, $new($StringArray2, {
			$$new($StringArray, {
				"art-lojban"_s,
				"jbo"_s
			}),
			$$new($StringArray, {
				"cel-gaulish"_s,
				"xtg-x-cel-gaulish"_s
			}),
			$$new($StringArray, {
				"en-GB-oed"_s,
				"en-GB-x-oed"_s
			}),
			$$new($StringArray, {
				"i-ami"_s,
				"ami"_s
			}),
			$$new($StringArray, {
				"i-bnn"_s,
				"bnn"_s
			}),
			$$new($StringArray, {
				"i-default"_s,
				"en-x-i-default"_s
			}),
			$$new($StringArray, {
				"i-enochian"_s,
				"und-x-i-enochian"_s
			}),
			$$new($StringArray, {
				"i-hak"_s,
				"hak"_s
			}),
			$$new($StringArray, {
				"i-klingon"_s,
				"tlh"_s
			}),
			$$new($StringArray, {
				"i-lux"_s,
				"lb"_s
			}),
			$$new($StringArray, {
				"i-mingo"_s,
				"see-x-i-mingo"_s
			}),
			$$new($StringArray, {
				"i-navajo"_s,
				"nv"_s
			}),
			$$new($StringArray, {
				"i-pwn"_s,
				"pwn"_s
			}),
			$$new($StringArray, {
				"i-tao"_s,
				"tao"_s
			}),
			$$new($StringArray, {
				"i-tay"_s,
				"tay"_s
			}),
			$$new($StringArray, {
				"i-tsu"_s,
				"tsu"_s
			}),
			$$new($StringArray, {
				"no-bok"_s,
				"nb"_s
			}),
			$$new($StringArray, {
				"no-nyn"_s,
				"nn"_s
			}),
			$$new($StringArray, {
				"sgn-BE-FR"_s,
				"sfb"_s
			}),
			$$new($StringArray, {
				"sgn-BE-NL"_s,
				"vgt"_s
			}),
			$$new($StringArray, {
				"sgn-CH-DE"_s,
				"sgg"_s
			}),
			$$new($StringArray, {
				"zh-guoyu"_s,
				"cmn"_s
			}),
			$$new($StringArray, {
				"zh-hakka"_s,
				"hak"_s
			}),
			$$new($StringArray, {
				"zh-min"_s,
				"nan-x-zh-min"_s
			}),
			$$new($StringArray, {
				"zh-min-nan"_s,
				"nan"_s
			}),
			$$new($StringArray, {
				"zh-xiang"_s,
				"hsn"_s
			})
		}));
		{
			$var($StringArray2, arr$, entries);
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($StringArray, e, arr$->get(i$));
				{
					$nc(LanguageTag::LEGACY)->put($($LocaleUtils::toLowerString($nc(e)->get(0))), e);
				}
			}
		}
	}
}

LanguageTag::LanguageTag() {
}

$Class* LanguageTag::load$($String* name, bool initialize) {
	$loadClass(LanguageTag, name, initialize, &_LanguageTag_ClassInfo_, clinit$LanguageTag, allocate$LanguageTag);
	return class$;
}

$Class* LanguageTag::class$ = nullptr;

		} // locale
	} // util
} // sun