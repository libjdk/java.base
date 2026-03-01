#include <sun/util/locale/provider/BreakIteratorProviderImpl.h>

#include <java/lang/InternalError.h>
#include <java/text/BreakIterator.h>
#include <java/text/spi/BreakIteratorProvider.h>
#include <java/util/Locale.h>
#include <java/util/MissingResourceException.h>
#include <java/util/Objects.h>
#include <java/util/Set.h>
#include <sun/text/DictionaryBasedBreakIterator.h>
#include <sun/text/RuleBasedBreakIterator.h>
#include <sun/util/locale/provider/LocaleProviderAdapter$Type.h>
#include <sun/util/locale/provider/LocaleProviderAdapter.h>
#include <sun/util/locale/provider/LocaleResources.h>
#include <jcpp.h>

#undef CHARACTER_INDEX
#undef LINE_INDEX
#undef SENTENCE_INDEX
#undef WORD_INDEX

using $LocaleArray = $Array<::java::util::Locale>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $BreakIterator = ::java::text::BreakIterator;
using $BreakIteratorProvider = ::java::text::spi::BreakIteratorProvider;
using $Locale = ::java::util::Locale;
using $MissingResourceException = ::java::util::MissingResourceException;
using $Objects = ::java::util::Objects;
using $Set = ::java::util::Set;
using $DictionaryBasedBreakIterator = ::sun::text::DictionaryBasedBreakIterator;
using $RuleBasedBreakIterator = ::sun::text::RuleBasedBreakIterator;
using $LocaleProviderAdapter = ::sun::util::locale::provider::LocaleProviderAdapter;
using $LocaleProviderAdapter$Type = ::sun::util::locale::provider::LocaleProviderAdapter$Type;
using $LocaleResources = ::sun::util::locale::provider::LocaleResources;

namespace sun {
	namespace util {
		namespace locale {
			namespace provider {

$FieldInfo _BreakIteratorProviderImpl_FieldInfo_[] = {
	{"CHARACTER_INDEX", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(BreakIteratorProviderImpl, CHARACTER_INDEX)},
	{"WORD_INDEX", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(BreakIteratorProviderImpl, WORD_INDEX)},
	{"LINE_INDEX", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(BreakIteratorProviderImpl, LINE_INDEX)},
	{"SENTENCE_INDEX", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(BreakIteratorProviderImpl, SENTENCE_INDEX)},
	{"type", "Lsun/util/locale/provider/LocaleProviderAdapter$Type;", nullptr, $PRIVATE | $FINAL, $field(BreakIteratorProviderImpl, type)},
	{"langtags", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE | $FINAL, $field(BreakIteratorProviderImpl, langtags)},
	{}
};

$MethodInfo _BreakIteratorProviderImpl_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Lsun/util/locale/provider/LocaleProviderAdapter$Type;Ljava/util/Set;)V", "(Lsun/util/locale/provider/LocaleProviderAdapter$Type;Ljava/util/Set<Ljava/lang/String;>;)V", $PUBLIC, $method(BreakIteratorProviderImpl, init$, void, $LocaleProviderAdapter$Type*, $Set*)},
	{"getAvailableLanguageTags", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(BreakIteratorProviderImpl, getAvailableLanguageTags, $Set*)},
	{"getAvailableLocales", "()[Ljava/util/Locale;", nullptr, $PUBLIC, $virtualMethod(BreakIteratorProviderImpl, getAvailableLocales, $LocaleArray*)},
	{"getBreakInstance", "(Ljava/util/Locale;ILjava/lang/String;Ljava/lang/String;)Ljava/text/BreakIterator;", nullptr, $PRIVATE, $method(BreakIteratorProviderImpl, getBreakInstance, $BreakIterator*, $Locale*, int32_t, $String*, $String*)},
	{"getCharacterInstance", "(Ljava/util/Locale;)Ljava/text/BreakIterator;", nullptr, $PUBLIC, $virtualMethod(BreakIteratorProviderImpl, getCharacterInstance, $BreakIterator*, $Locale*)},
	{"getLineInstance", "(Ljava/util/Locale;)Ljava/text/BreakIterator;", nullptr, $PUBLIC, $virtualMethod(BreakIteratorProviderImpl, getLineInstance, $BreakIterator*, $Locale*)},
	{"getSentenceInstance", "(Ljava/util/Locale;)Ljava/text/BreakIterator;", nullptr, $PUBLIC, $virtualMethod(BreakIteratorProviderImpl, getSentenceInstance, $BreakIterator*, $Locale*)},
	{"getWordInstance", "(Ljava/util/Locale;)Ljava/text/BreakIterator;", nullptr, $PUBLIC, $virtualMethod(BreakIteratorProviderImpl, getWordInstance, $BreakIterator*, $Locale*)},
	{"isSupportedLocale", "(Ljava/util/Locale;)Z", nullptr, $PUBLIC, $virtualMethod(BreakIteratorProviderImpl, isSupportedLocale, bool, $Locale*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _BreakIteratorProviderImpl_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.util.locale.provider.BreakIteratorProviderImpl",
	"java.text.spi.BreakIteratorProvider",
	"sun.util.locale.provider.AvailableLanguageTags",
	_BreakIteratorProviderImpl_FieldInfo_,
	_BreakIteratorProviderImpl_MethodInfo_
};

$Object* allocate$BreakIteratorProviderImpl($Class* clazz) {
	return $of($alloc(BreakIteratorProviderImpl));
}

int32_t BreakIteratorProviderImpl::hashCode() {
	 return this->$BreakIteratorProvider::hashCode();
}

bool BreakIteratorProviderImpl::equals(Object$* obj) {
	 return this->$BreakIteratorProvider::equals(obj);
}

$Object* BreakIteratorProviderImpl::clone() {
	 return this->$BreakIteratorProvider::clone();
}

$String* BreakIteratorProviderImpl::toString() {
	 return this->$BreakIteratorProvider::toString();
}

void BreakIteratorProviderImpl::finalize() {
	this->$BreakIteratorProvider::finalize();
}

void BreakIteratorProviderImpl::init$($LocaleProviderAdapter$Type* type, $Set* langtags) {
	$BreakIteratorProvider::init$();
	$set(this, type, type);
	$set(this, langtags, langtags);
}

$LocaleArray* BreakIteratorProviderImpl::getAvailableLocales() {
	return $LocaleProviderAdapter::toLocaleArray(this->langtags);
}

$BreakIterator* BreakIteratorProviderImpl::getWordInstance($Locale* locale) {
	return getBreakInstance(locale, BreakIteratorProviderImpl::WORD_INDEX, "WordData"_s, "WordDictionary"_s);
}

$BreakIterator* BreakIteratorProviderImpl::getLineInstance($Locale* locale) {
	return getBreakInstance(locale, BreakIteratorProviderImpl::LINE_INDEX, "LineData"_s, "LineDictionary"_s);
}

$BreakIterator* BreakIteratorProviderImpl::getCharacterInstance($Locale* locale) {
	return getBreakInstance(locale, BreakIteratorProviderImpl::CHARACTER_INDEX, "CharacterData"_s, "CharacterDictionary"_s);
}

$BreakIterator* BreakIteratorProviderImpl::getSentenceInstance($Locale* locale) {
	return getBreakInstance(locale, BreakIteratorProviderImpl::SENTENCE_INDEX, "SentenceData"_s, "SentenceDictionary"_s);
}

$BreakIterator* BreakIteratorProviderImpl::getBreakInstance($Locale* locale, int32_t type, $String* ruleName, $String* dictionaryName) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(locale);
	$var($LocaleResources, lr, $nc($($LocaleProviderAdapter::forJRE()))->getLocaleResources(locale));
	$var($StringArray, classNames, $cast($StringArray, $nc(lr)->getBreakIteratorInfo("BreakIteratorClasses"_s)));
	$var($String, ruleFile, $cast($String, lr->getBreakIteratorInfo(ruleName)));
	$var($bytes, ruleData, lr->getBreakIteratorResources(ruleName));
	try {
		{
			$var($String, s6958$, $nc(classNames)->get(type));
			int32_t tmp6958$ = -1;
			switch ($nc(s6958$)->hashCode()) {
			case 0x71D345D6:
				{
					if (s6958$->equals("RuleBasedBreakIterator"_s)) {
						tmp6958$ = 0;
					}
					break;
				}
			case 0x4A7414F0:
				{
					if (s6958$->equals("DictionaryBasedBreakIterator"_s)) {
						tmp6958$ = 1;
					}
					break;
				}
			}
			{
				$var($String, dictionaryFile, nullptr)
				$var($bytes, dictionaryData, nullptr)
				switch (tmp6958$) {
				case 0:
					{
						return $new($RuleBasedBreakIterator, ruleFile, ruleData);
					}
				case 1:
					{
						$assign(dictionaryFile, $cast($String, lr->getBreakIteratorInfo(dictionaryName)));
						$assign(dictionaryData, lr->getBreakIteratorResources(dictionaryName));
						return $new($DictionaryBasedBreakIterator, ruleFile, ruleData, dictionaryFile, dictionaryData);
					}
				default:
					{
						$throwNew($IllegalArgumentException, $$str({"Invalid break iterator class \""_s, classNames->get(type), "\""_s}));
					}
				}
			}
		}
	} catch ($MissingResourceException& e) {
		$throwNew($InternalError, $(e->toString()), e);
	} catch ($IllegalArgumentException& e) {
		$throwNew($InternalError, $(e->toString()), e);
	}
	$shouldNotReachHere();
}

$Set* BreakIteratorProviderImpl::getAvailableLanguageTags() {
	return this->langtags;
}

bool BreakIteratorProviderImpl::isSupportedLocale($Locale* locale) {
	return $nc($($LocaleProviderAdapter::forType(this->type)))->isSupportedProviderLocale(locale, this->langtags);
}

BreakIteratorProviderImpl::BreakIteratorProviderImpl() {
}

$Class* BreakIteratorProviderImpl::load$($String* name, bool initialize) {
	$loadClass(BreakIteratorProviderImpl, name, initialize, &_BreakIteratorProviderImpl_ClassInfo_, allocate$BreakIteratorProviderImpl);
	return class$;
}

$Class* BreakIteratorProviderImpl::class$ = nullptr;

			} // provider
		} // locale
	} // util
} // sun