#include <sun/util/locale/provider/BaseLocaleDataMetaInfo.h>

#include <java/util/HashMap.h>
#include <java/util/Map.h>
#include <sun/util/locale/provider/LocaleProviderAdapter$Type.h>
#include <jcpp.h>

#undef JRE

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $HashMap = ::java::util::HashMap;
using $Map = ::java::util::Map;
using $LocaleProviderAdapter$Type = ::sun::util::locale::provider::LocaleProviderAdapter$Type;

namespace sun {
	namespace util {
		namespace locale {
			namespace provider {

$FieldInfo _BaseLocaleDataMetaInfo_FieldInfo_[] = {
	{"resourceNameToLocales", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;", $PRIVATE | $STATIC | $FINAL, $staticField(BaseLocaleDataMetaInfo, resourceNameToLocales)},
	{}
};

$MethodInfo _BaseLocaleDataMetaInfo_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(BaseLocaleDataMetaInfo, init$, void)},
	{"availableLanguageTags", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(BaseLocaleDataMetaInfo, availableLanguageTags, $String*, $String*)},
	{"getSupportedLocaleString", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(BaseLocaleDataMetaInfo, getSupportedLocaleString, $String*, $String*)},
	{"getType", "()Lsun/util/locale/provider/LocaleProviderAdapter$Type;", nullptr, $PUBLIC, $virtualMethod(BaseLocaleDataMetaInfo, getType, $LocaleProviderAdapter$Type*)},
	{}
};

$ClassInfo _BaseLocaleDataMetaInfo_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.util.locale.provider.BaseLocaleDataMetaInfo",
	"java.lang.Object",
	"sun.util.locale.provider.LocaleDataMetaInfo",
	_BaseLocaleDataMetaInfo_FieldInfo_,
	_BaseLocaleDataMetaInfo_MethodInfo_
};

$Object* allocate$BaseLocaleDataMetaInfo($Class* clazz) {
	return $of($alloc(BaseLocaleDataMetaInfo));
}

$Map* BaseLocaleDataMetaInfo::resourceNameToLocales = nullptr;

void BaseLocaleDataMetaInfo::init$() {
}

$String* BaseLocaleDataMetaInfo::getSupportedLocaleString($String* resourceName) {
	$init(BaseLocaleDataMetaInfo);
	return $cast($String, $nc(BaseLocaleDataMetaInfo::resourceNameToLocales)->getOrDefault(resourceName, ""_s));
}

$LocaleProviderAdapter$Type* BaseLocaleDataMetaInfo::getType() {
	$init($LocaleProviderAdapter$Type);
	return $LocaleProviderAdapter$Type::JRE;
}

$String* BaseLocaleDataMetaInfo::availableLanguageTags($String* category) {
	return getSupportedLocaleString(category);
}

void clinit$BaseLocaleDataMetaInfo($Class* class$) {
	$assignStatic(BaseLocaleDataMetaInfo::resourceNameToLocales, $new($HashMap, 9));
	{
		$nc(BaseLocaleDataMetaInfo::resourceNameToLocales)->put("FormatData"_s, "  en en-US "_s);
		$nc(BaseLocaleDataMetaInfo::resourceNameToLocales)->put("CollationData"_s, "  "_s);
		$nc(BaseLocaleDataMetaInfo::resourceNameToLocales)->put("BreakIteratorInfo"_s, "  "_s);
		$nc(BaseLocaleDataMetaInfo::resourceNameToLocales)->put("BreakIteratorRules"_s, "  "_s);
		$nc(BaseLocaleDataMetaInfo::resourceNameToLocales)->put("TimeZoneNames"_s, "  en "_s);
		$nc(BaseLocaleDataMetaInfo::resourceNameToLocales)->put("LocaleNames"_s, "  en "_s);
		$nc(BaseLocaleDataMetaInfo::resourceNameToLocales)->put("CurrencyNames"_s, "  en-US "_s);
		$nc(BaseLocaleDataMetaInfo::resourceNameToLocales)->put("CalendarData"_s, "  en "_s);
		$nc(BaseLocaleDataMetaInfo::resourceNameToLocales)->put("AvailableLocales"_s, " en en-US "_s);
	}
}

BaseLocaleDataMetaInfo::BaseLocaleDataMetaInfo() {
}

$Class* BaseLocaleDataMetaInfo::load$($String* name, bool initialize) {
	$loadClass(BaseLocaleDataMetaInfo, name, initialize, &_BaseLocaleDataMetaInfo_ClassInfo_, clinit$BaseLocaleDataMetaInfo, allocate$BaseLocaleDataMetaInfo);
	return class$;
}

$Class* BaseLocaleDataMetaInfo::class$ = nullptr;

			} // provider
		} // locale
	} // util
} // sun