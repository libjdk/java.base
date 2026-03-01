#include <sun/util/cldr/CLDRBaseLocaleDataMetaInfo.h>

#include <java/util/HashMap.h>
#include <java/util/Locale.h>
#include <java/util/Map.h>
#include <sun/util/cldr/CLDRBaseLocaleDataMetaInfo$TZCanonicalIDMapHolder.h>
#include <sun/util/locale/provider/LocaleProviderAdapter$Type.h>
#include <jcpp.h>

#undef CLDR
#undef ROOT

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $HashMap = ::java::util::HashMap;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $CLDRBaseLocaleDataMetaInfo$TZCanonicalIDMapHolder = ::sun::util::cldr::CLDRBaseLocaleDataMetaInfo$TZCanonicalIDMapHolder;
using $LocaleProviderAdapter$Type = ::sun::util::locale::provider::LocaleProviderAdapter$Type;

namespace sun {
	namespace util {
		namespace cldr {

$FieldInfo _CLDRBaseLocaleDataMetaInfo_FieldInfo_[] = {
	{"resourceNameToLocales", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;", $PRIVATE | $STATIC | $FINAL, $staticField(CLDRBaseLocaleDataMetaInfo, resourceNameToLocales)},
	{"parentLocalesMap", "Ljava/util/Map;", "Ljava/util/Map<Ljava/util/Locale;[Ljava/lang/String;>;", $PRIVATE | $STATIC | $FINAL, $staticField(CLDRBaseLocaleDataMetaInfo, parentLocalesMap)},
	{"languageAliasMap", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;", $PRIVATE | $STATIC | $FINAL, $staticField(CLDRBaseLocaleDataMetaInfo, languageAliasMap)},
	{}
};

$MethodInfo _CLDRBaseLocaleDataMetaInfo_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(CLDRBaseLocaleDataMetaInfo, init$, void)},
	{"availableLanguageTags", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(CLDRBaseLocaleDataMetaInfo, availableLanguageTags, $String*, $String*)},
	{"getLanguageAliasMap", "()Ljava/util/Map;", "()Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;", $PUBLIC, $virtualMethod(CLDRBaseLocaleDataMetaInfo, getLanguageAliasMap, $Map*)},
	{"getType", "()Lsun/util/locale/provider/LocaleProviderAdapter$Type;", nullptr, $PUBLIC, $virtualMethod(CLDRBaseLocaleDataMetaInfo, getType, $LocaleProviderAdapter$Type*)},
	{"parentLocales", "()Ljava/util/Map;", "()Ljava/util/Map<Ljava/util/Locale;[Ljava/lang/String;>;", $PUBLIC, $virtualMethod(CLDRBaseLocaleDataMetaInfo, parentLocales, $Map*)},
	{"tzCanonicalIDs", "()Ljava/util/Map;", "()Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;", $PUBLIC, $virtualMethod(CLDRBaseLocaleDataMetaInfo, tzCanonicalIDs, $Map*)},
	{}
};

$InnerClassInfo _CLDRBaseLocaleDataMetaInfo_InnerClassesInfo_[] = {
	{"sun.util.cldr.CLDRBaseLocaleDataMetaInfo$TZCanonicalIDMapHolder", "sun.util.cldr.CLDRBaseLocaleDataMetaInfo", "TZCanonicalIDMapHolder", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _CLDRBaseLocaleDataMetaInfo_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.util.cldr.CLDRBaseLocaleDataMetaInfo",
	"java.lang.Object",
	"sun.util.locale.provider.LocaleDataMetaInfo",
	_CLDRBaseLocaleDataMetaInfo_FieldInfo_,
	_CLDRBaseLocaleDataMetaInfo_MethodInfo_,
	nullptr,
	nullptr,
	_CLDRBaseLocaleDataMetaInfo_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.util.cldr.CLDRBaseLocaleDataMetaInfo$TZCanonicalIDMapHolder"
};

$Object* allocate$CLDRBaseLocaleDataMetaInfo($Class* clazz) {
	return $of($alloc(CLDRBaseLocaleDataMetaInfo));
}

$Map* CLDRBaseLocaleDataMetaInfo::resourceNameToLocales = nullptr;
$Map* CLDRBaseLocaleDataMetaInfo::parentLocalesMap = nullptr;
$Map* CLDRBaseLocaleDataMetaInfo::languageAliasMap = nullptr;

void CLDRBaseLocaleDataMetaInfo::init$() {
}

$LocaleProviderAdapter$Type* CLDRBaseLocaleDataMetaInfo::getType() {
	$init($LocaleProviderAdapter$Type);
	return $LocaleProviderAdapter$Type::CLDR;
}

$String* CLDRBaseLocaleDataMetaInfo::availableLanguageTags($String* category) {
	return $cast($String, $nc(CLDRBaseLocaleDataMetaInfo::resourceNameToLocales)->getOrDefault(category, ""_s));
}

$Map* CLDRBaseLocaleDataMetaInfo::getLanguageAliasMap() {
	return CLDRBaseLocaleDataMetaInfo::languageAliasMap;
}

$Map* CLDRBaseLocaleDataMetaInfo::tzCanonicalIDs() {
	$init($CLDRBaseLocaleDataMetaInfo$TZCanonicalIDMapHolder);
	return $CLDRBaseLocaleDataMetaInfo$TZCanonicalIDMapHolder::tzCanonicalIDMap;
}

$Map* CLDRBaseLocaleDataMetaInfo::parentLocales() {
	return CLDRBaseLocaleDataMetaInfo::parentLocalesMap;
}

void clinit$CLDRBaseLocaleDataMetaInfo($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(CLDRBaseLocaleDataMetaInfo::resourceNameToLocales, $new($HashMap));
	$assignStatic(CLDRBaseLocaleDataMetaInfo::parentLocalesMap, $new($HashMap));
	$assignStatic(CLDRBaseLocaleDataMetaInfo::languageAliasMap, $new($HashMap));
	{
		$nc(CLDRBaseLocaleDataMetaInfo::resourceNameToLocales)->put("AvailableLocales"_s, " en en-Latn-US en-US en-US-POSIX"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::parentLocalesMap)->put($($Locale::forLanguageTag("es-419"_s)), $$new($StringArray, {
			""_s,
			"es-AR"_s,
			"es-BO"_s,
			"es-BR"_s,
			"es-BZ"_s,
			"es-CL"_s,
			"es-CO"_s,
			"es-CR"_s,
			"es-CU"_s,
			"es-DO"_s,
			"es-EC"_s,
			"es-GT"_s,
			"es-HN"_s,
			"es-MX"_s,
			"es-NI"_s,
			"es-PA"_s,
			"es-PE"_s,
			"es-PR"_s,
			"es-PY"_s,
			"es-SV"_s,
			"es-US"_s,
			"es-UY"_s,
			"es-VE"_s
		}));
		$nc(CLDRBaseLocaleDataMetaInfo::parentLocalesMap)->put($Locale::ROOT, $$new($StringArray, {
			""_s,
			"az-Arab"_s,
			"az-Cyrl"_s,
			"blt-Latn"_s,
			"bm-Nkoo"_s,
			"bs-Cyrl"_s,
			"byn-Latn"_s,
			"cu-Glag"_s,
			"dje-Arab"_s,
			"dyo-Arab"_s,
			"en-Dsrt"_s,
			"en-Shaw"_s,
			"ff-Adlm"_s,
			"ff-Arab"_s,
			"ha-Arab"_s,
			"hi-Latn"_s,
			"iu-Latn"_s,
			"kk-Arab"_s,
			"ks-Deva"_s,
			"ku-Arab"_s,
			"ky-Arab"_s,
			"ky-Latn"_s,
			"ml-Arab"_s,
			"mn-Mong"_s,
			"mni-Mtei"_s,
			"ms-Arab"_s,
			"pa-Arab"_s,
			"sat-Deva"_s,
			"sd-Deva"_s,
			"sd-Khoj"_s,
			"sd-Sind"_s,
			"shi-Latn"_s,
			"so-Arab"_s,
			"sr-Latn"_s,
			"sw-Arab"_s,
			"tg-Arab"_s,
			"ug-Cyrl"_s,
			"uz-Arab"_s,
			"uz-Cyrl"_s,
			"vai-Latn"_s,
			"wo-Arab"_s,
			"yo-Arab"_s,
			"yue-Hans"_s,
			"zh-Hant"_s
		}));
		$nc(CLDRBaseLocaleDataMetaInfo::parentLocalesMap)->put($($Locale::forLanguageTag("zh-Hant-HK"_s)), $$new($StringArray, {
			""_s,
			"zh-Hant-MO"_s
		}));
		$nc(CLDRBaseLocaleDataMetaInfo::parentLocalesMap)->put($($Locale::forLanguageTag("en-001"_s)), $$new($StringArray, {
			""_s,
			"en-150"_s,
			"en-AG"_s,
			"en-AI"_s,
			"en-AU"_s,
			"en-BB"_s,
			"en-BM"_s,
			"en-BS"_s,
			"en-BW"_s,
			"en-BZ"_s,
			"en-CA"_s,
			"en-CC"_s,
			"en-CK"_s,
			"en-CM"_s,
			"en-CX"_s,
			"en-CY"_s,
			"en-DG"_s,
			"en-DM"_s,
			"en-ER"_s,
			"en-FJ"_s,
			"en-FK"_s,
			"en-FM"_s,
			"en-GB"_s,
			"en-GD"_s,
			"en-GG"_s,
			"en-GH"_s,
			"en-GI"_s,
			"en-GM"_s,
			"en-GY"_s,
			"en-HK"_s,
			"en-IE"_s,
			"en-IL"_s,
			"en-IM"_s,
			"en-IN"_s,
			"en-IO"_s,
			"en-JE"_s,
			"en-JM"_s,
			"en-KE"_s,
			"en-KI"_s,
			"en-KN"_s,
			"en-KY"_s,
			"en-LC"_s,
			"en-LR"_s,
			"en-LS"_s,
			"en-MG"_s,
			"en-MO"_s,
			"en-MS"_s,
			"en-MT"_s,
			"en-MU"_s,
			"en-MW"_s,
			"en-MY"_s,
			"en-NA"_s,
			"en-NF"_s,
			"en-NG"_s,
			"en-NR"_s,
			"en-NU"_s,
			"en-NZ"_s,
			"en-PG"_s,
			"en-PH"_s,
			"en-PK"_s,
			"en-PN"_s,
			"en-PW"_s,
			"en-RW"_s,
			"en-SB"_s,
			"en-SC"_s,
			"en-SD"_s,
			"en-SG"_s,
			"en-SH"_s,
			"en-SL"_s,
			"en-SS"_s,
			"en-SX"_s,
			"en-SZ"_s,
			"en-TC"_s,
			"en-TK"_s,
			"en-TO"_s,
			"en-TT"_s,
			"en-TV"_s,
			"en-TZ"_s,
			"en-UG"_s,
			"en-VC"_s,
			"en-VG"_s,
			"en-VU"_s,
			"en-WS"_s,
			"en-ZA"_s,
			"en-ZM"_s,
			"en-ZW"_s
		}));
		$nc(CLDRBaseLocaleDataMetaInfo::parentLocalesMap)->put($($Locale::forLanguageTag("pt-PT"_s)), $$new($StringArray, {
			""_s,
			"pt-AO"_s,
			"pt-CH"_s,
			"pt-CV"_s,
			"pt-FR"_s,
			"pt-GQ"_s,
			"pt-GW"_s,
			"pt-LU"_s,
			"pt-MO"_s,
			"pt-MZ"_s,
			"pt-ST"_s,
			"pt-TL"_s
		}));
		$nc(CLDRBaseLocaleDataMetaInfo::parentLocalesMap)->put($($Locale::forLanguageTag("no"_s)), $$new($StringArray, {
			""_s,
			"nb"_s,
			"nn"_s
		}));
		$nc(CLDRBaseLocaleDataMetaInfo::parentLocalesMap)->put($($Locale::forLanguageTag("en-150"_s)), $$new($StringArray, {
			""_s,
			"en-AT"_s,
			"en-BE"_s,
			"en-CH"_s,
			"en-DE"_s,
			"en-DK"_s,
			"en-FI"_s,
			"en-NL"_s,
			"en-SE"_s,
			"en-SI"_s
		}));
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("zh-cmn-Hant"_s, "zh-Hant"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("mwj"_s, "vaj"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("zh-cmn-Hans"_s, "zh-Hans"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("tdu"_s, "dtp"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("pmc"_s, "huw"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("sgn-PT"_s, "psr"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("leg"_s, "enl"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("ccq"_s, "rki"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("sca"_s, "hle"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("scc"_s, "sr"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("und-nynorsk"_s, "und"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("sgn-CH-DE"_s, "sgg"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("und-arevmda"_s, "und"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("en-GB-oed"_s, "en-GB-oxendict"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("pmu"_s, "phr"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("baz"_s, "nvo"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("jar"_s, "jgk"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("yos"_s, "zom"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("mgx"_s, "jbk"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("scr"_s, "hr"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("gli"_s, "kzk"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("ktr"_s, "dtp"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("dwl"_s, "dbt"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("myd"_s, "aog"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("i-klingon"_s, "tlh"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("kdv"_s, "zkd"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("i-pwn"_s, "pwn"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("myt"_s, "mry"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("sum"_s, "ulw"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("sul"_s, "sgd"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("zh-gan"_s, "gan"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("aam"_s, "aas"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("i-navajo"_s, "nv"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("btb"_s, "beb"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("tgg"_s, "bjp"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("zh-yue"_s, "yue"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("sh"_s, "sr-Latn"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("ppa"_s, "bfy"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("sgn-CO"_s, "csn"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("i-default"_s, "en-x-i-default"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("kvs"_s, "gdj"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("und-xiang"_s, "und"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("thc"_s, "tpo"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("ibi"_s, "opa"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("nln"_s, "azd"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("sgn-BE-FR"_s, "sfb"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("ppr"_s, "lcq"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("asd"_s, "snz"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("nlr"_s, "nrk"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("i-enochian"_s, "und-x-i-enochian"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("sgn-BR"_s, "bzs"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("tl"_s, "fil"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("ybd"_s, "rki"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("sgn-SE"_s, "swl"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("sgn-DK"_s, "dsl"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("thw"_s, "ola"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("kwq"_s, "yam"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("thx"_s, "oyb"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("kgc"_s, "tdf"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("kgd"_s, "ncq"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("jeg"_s, "oyb"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("kgh"_s, "kml"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("lii"_s, "raq"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("dit"_s, "dif"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("tid"_s, "itd"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("sgn-DE"_s, "gsg"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("tie"_s, "ras"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("kxe"_s, "tvd"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("sgl"_s, "isk"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("kxl"_s, "kru"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("djl"_s, "dze"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("elp"_s, "amq"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("hrr"_s, "jal"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("sgn-US"_s, "ase"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("adp"_s, "dz"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("und-hakka"_s, "und"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("aue"_s, "ktz"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("nns"_s, "nbr"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("pry"_s, "prt"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("xba"_s, "cax"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("xrq"_s, "dmw"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("nnx"_s, "ngv"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("cel-gaulish"_s, "xtg"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("dkl"_s, "aqd"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("sgn-FR"_s, "fsl"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("bgm"_s, "bcg"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("zh-min"_s, "nan-x-zh-min"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("xsj"_s, "suj"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("tkk"_s, "twm"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("yuu"_s, "yug"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("kzh"_s, "dgl"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("kzj"_s, "dtp"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("sgn-ES"_s, "ssp"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("gav"_s, "dev"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("pcr"_s, "adx"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("yen"_s, "ynq"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("kzt"_s, "dtp"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("bhk"_s, "fbl"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("sgn-GR"_s, "gss"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("gbc"_s, "wny"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("cjr"_s, "mom"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("llo"_s, "ngt"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("mnt"_s, "wnn"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("i-hak"_s, "hak"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("sgn-GB"_s, "bfi"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("unp"_s, "wro"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("aa-saaho"_s, "ssy"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("cka"_s, "cmr"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("tlw"_s, "weo"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("und-hepburn-heploc"_s, "und-alalc97"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("mof"_s, "xnt"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("agp"_s, "apf"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("lmm"_s, "rmx"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("nad"_s, "xny"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("uok"_s, "ema"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("skk"_s, "oyb"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("und-bokmal"_s, "und"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("puz"_s, "pub"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("tmp"_s, "tyj"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("bjd"_s, "drl"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("gti"_s, "nyc"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("sgn-ZA"_s, "sfs"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("zir"_s, "scv"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("sgn-IT"_s, "ise"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("bjq"_s, "bzc"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("tne"_s, "kak"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("tnf"_s, "fa-AF"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("nbf"_s, "nru"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("sgn-IE"_s, "isg"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("bkb"_s, "ebk"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("und-arevela"_s, "und"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("zh-min-nan"_s, "nan"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("zh-guoyu"_s, "zh"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("i-mingo"_s, "see-x-i-mingo"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("cmk"_s, "xch"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("ayx"_s, "nun"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("sgn-JP"_s, "jsl"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("hy-arevmda"_s, "hyw"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("sgn-BE-NL"_s, "vgt"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("nbx"_s, "ekc"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("guv"_s, "duz"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("oun"_s, "vaj"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("ais"_s, "ami"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("jw"_s, "jv"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("und-aaland"_s, "und-AX"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("izi"_s, "eza"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("ncp"_s, "kdz"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("cnr"_s, "sr-ME"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("yiy"_s, "yrm"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("nts"_s, "pij"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("art-lojban"_s, "jbo"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("und-lojban"_s, "und"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("i-lux"_s, "lb"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("gfx"_s, "vaj"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("zh-hakka"_s, "hak"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("i-ami"_s, "ami"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("zh-xiang"_s, "hsn"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("koj"_s, "kwv"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("daf"_s, "dnj"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("coy"_s, "pij"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("ggo"_s, "esg"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("ggn"_s, "gvr"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("mst"_s, "mry"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("xia"_s, "acn"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("dap"_s, "njz"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("ggr"_s, "gtu"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("i-tay"_s, "tay"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("rmr"_s, "emx"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("drh"_s, "mn"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("mo"_s, "ro"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("drr"_s, "kzk"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("sgn-MX"_s, "mfs"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("wgw"_s, "wgb"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("drw"_s, "fa-AF"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("ill"_s, "ilm"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("kpp"_s, "jkm"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("i-tsu"_s, "tsu"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("ilw"_s, "gal"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("cqu"_s, "quh"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("tsf"_s, "taj"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("zh-wuu"_s, "wuu"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("sgn-NL"_s, "dse"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("yma"_s, "lrr"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("gio"_s, "aou"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("meg"_s, "cir"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("sgn-NO"_s, "nsi"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("xkh"_s, "waw"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("sgn-NI"_s, "ncs"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("zh-cmn"_s, "zh"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("ymt"_s, "mtm"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("i-bnn"_s, "bnn"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("i-tao"_s, "tao"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("sap"_s, "aqt"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("wit"_s, "nol"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("wiw"_s, "nwo"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("krm"_s, "bmf"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("nxu"_s, "bpp"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("dud"_s, "uth"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("duj"_s, "dwu"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("mwd"_s, "dmw"_s);
		$nc(CLDRBaseLocaleDataMetaInfo::languageAliasMap)->put("und-saaho"_s, "und"_s);
	}
}

CLDRBaseLocaleDataMetaInfo::CLDRBaseLocaleDataMetaInfo() {
}

$Class* CLDRBaseLocaleDataMetaInfo::load$($String* name, bool initialize) {
	$loadClass(CLDRBaseLocaleDataMetaInfo, name, initialize, &_CLDRBaseLocaleDataMetaInfo_ClassInfo_, clinit$CLDRBaseLocaleDataMetaInfo, allocate$CLDRBaseLocaleDataMetaInfo);
	return class$;
}

$Class* CLDRBaseLocaleDataMetaInfo::class$ = nullptr;

		} // cldr
	} // util
} // sun