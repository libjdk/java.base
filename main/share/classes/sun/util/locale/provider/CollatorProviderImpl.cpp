#include <sun/util/locale/provider/CollatorProviderImpl.h>

#include <java/lang/InternalError.h>
#include <java/text/Collator.h>
#include <java/text/ParseException.h>
#include <java/text/RuleBasedCollator.h>
#include <java/text/spi/CollatorProvider.h>
#include <java/util/Locale.h>
#include <java/util/Set.h>
#include <sun/util/locale/provider/CollationRules.h>
#include <sun/util/locale/provider/LocaleProviderAdapter$Type.h>
#include <sun/util/locale/provider/LocaleProviderAdapter.h>
#include <sun/util/locale/provider/LocaleResources.h>
#include <jcpp.h>

#undef DEFAULTRULES
#undef NO_DECOMPOSITION

using $LocaleArray = $Array<::java::util::Locale>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $Collator = ::java::text::Collator;
using $ParseException = ::java::text::ParseException;
using $RuleBasedCollator = ::java::text::RuleBasedCollator;
using $CollatorProvider = ::java::text::spi::CollatorProvider;
using $Locale = ::java::util::Locale;
using $Set = ::java::util::Set;
using $CollationRules = ::sun::util::locale::provider::CollationRules;
using $LocaleProviderAdapter = ::sun::util::locale::provider::LocaleProviderAdapter;
using $LocaleProviderAdapter$Type = ::sun::util::locale::provider::LocaleProviderAdapter$Type;
using $LocaleResources = ::sun::util::locale::provider::LocaleResources;

namespace sun {
	namespace util {
		namespace locale {
			namespace provider {

$FieldInfo _CollatorProviderImpl_FieldInfo_[] = {
	{"type", "Lsun/util/locale/provider/LocaleProviderAdapter$Type;", nullptr, $PRIVATE | $FINAL, $field(CollatorProviderImpl, type)},
	{"langtags", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE | $FINAL, $field(CollatorProviderImpl, langtags)},
	{}
};

$MethodInfo _CollatorProviderImpl_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Lsun/util/locale/provider/LocaleProviderAdapter$Type;Ljava/util/Set;)V", "(Lsun/util/locale/provider/LocaleProviderAdapter$Type;Ljava/util/Set<Ljava/lang/String;>;)V", $PUBLIC, $method(CollatorProviderImpl, init$, void, $LocaleProviderAdapter$Type*, $Set*)},
	{"getAvailableLanguageTags", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(CollatorProviderImpl, getAvailableLanguageTags, $Set*)},
	{"getAvailableLocales", "()[Ljava/util/Locale;", nullptr, $PUBLIC, $virtualMethod(CollatorProviderImpl, getAvailableLocales, $LocaleArray*)},
	{"getInstance", "(Ljava/util/Locale;)Ljava/text/Collator;", nullptr, $PUBLIC, $virtualMethod(CollatorProviderImpl, getInstance, $Collator*, $Locale*)},
	{"isSupportedLocale", "(Ljava/util/Locale;)Z", nullptr, $PUBLIC, $virtualMethod(CollatorProviderImpl, isSupportedLocale, bool, $Locale*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _CollatorProviderImpl_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.util.locale.provider.CollatorProviderImpl",
	"java.text.spi.CollatorProvider",
	"sun.util.locale.provider.AvailableLanguageTags",
	_CollatorProviderImpl_FieldInfo_,
	_CollatorProviderImpl_MethodInfo_
};

$Object* allocate$CollatorProviderImpl($Class* clazz) {
	return $of($alloc(CollatorProviderImpl));
}

int32_t CollatorProviderImpl::hashCode() {
	 return this->$CollatorProvider::hashCode();
}

bool CollatorProviderImpl::equals(Object$* obj) {
	 return this->$CollatorProvider::equals(obj);
}

$Object* CollatorProviderImpl::clone() {
	 return this->$CollatorProvider::clone();
}

$String* CollatorProviderImpl::toString() {
	 return this->$CollatorProvider::toString();
}

void CollatorProviderImpl::finalize() {
	this->$CollatorProvider::finalize();
}

void CollatorProviderImpl::init$($LocaleProviderAdapter$Type* type, $Set* langtags) {
	$CollatorProvider::init$();
	$set(this, type, type);
	$set(this, langtags, langtags);
}

$LocaleArray* CollatorProviderImpl::getAvailableLocales() {
	return $LocaleProviderAdapter::toLocaleArray(this->langtags);
}

bool CollatorProviderImpl::isSupportedLocale($Locale* locale) {
	return $nc($($LocaleProviderAdapter::forType(this->type)))->isSupportedProviderLocale(locale, this->langtags);
}

$Collator* CollatorProviderImpl::getInstance($Locale* locale) {
	$useLocalCurrentObjectStackCache();
	if (locale == nullptr) {
		$throwNew($NullPointerException);
	}
	$var($Collator, result, nullptr);
	$var($String, colString, $nc($($nc($($LocaleProviderAdapter::forType(this->type)))->getLocaleResources(locale)))->getCollationData());
	try {
		$init($CollationRules);
		$assign(result, $new($RuleBasedCollator, $$str({$CollationRules::DEFAULTRULES, colString})));
	} catch ($ParseException& foo) {
		try {
			$init($CollationRules);
			$assign(result, $new($RuleBasedCollator, $CollationRules::DEFAULTRULES));
		} catch ($ParseException& bar) {
			$throwNew($InternalError, static_cast<$Throwable*>(bar));
		}
	}
	$nc(result)->setDecomposition($Collator::NO_DECOMPOSITION);
	return $cast($Collator, result->clone());
}

$Set* CollatorProviderImpl::getAvailableLanguageTags() {
	return this->langtags;
}

CollatorProviderImpl::CollatorProviderImpl() {
}

$Class* CollatorProviderImpl::load$($String* name, bool initialize) {
	$loadClass(CollatorProviderImpl, name, initialize, &_CollatorProviderImpl_ClassInfo_, allocate$CollatorProviderImpl);
	return class$;
}

$Class* CollatorProviderImpl::class$ = nullptr;

			} // provider
		} // locale
	} // util
} // sun