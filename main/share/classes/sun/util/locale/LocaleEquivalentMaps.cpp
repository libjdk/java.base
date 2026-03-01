#include <sun/util/locale/LocaleEquivalentMaps.h>

#include <java/util/HashMap.h>
#include <java/util/Map.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $HashMap = ::java::util::HashMap;
using $Map = ::java::util::Map;

namespace sun {
	namespace util {
		namespace locale {

$FieldInfo _LocaleEquivalentMaps_FieldInfo_[] = {
	{"singleEquivMap", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;", $STATIC | $FINAL, $staticField(LocaleEquivalentMaps, singleEquivMap)},
	{"multiEquivsMap", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;[Ljava/lang/String;>;", $STATIC | $FINAL, $staticField(LocaleEquivalentMaps, multiEquivsMap)},
	{"regionVariantEquivMap", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;", $STATIC | $FINAL, $staticField(LocaleEquivalentMaps, regionVariantEquivMap)},
	{}
};

$MethodInfo _LocaleEquivalentMaps_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(LocaleEquivalentMaps, init$, void)},
	{}
};

$ClassInfo _LocaleEquivalentMaps_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.util.locale.LocaleEquivalentMaps",
	"java.lang.Object",
	nullptr,
	_LocaleEquivalentMaps_FieldInfo_,
	_LocaleEquivalentMaps_MethodInfo_
};

$Object* allocate$LocaleEquivalentMaps($Class* clazz) {
	return $of($alloc(LocaleEquivalentMaps));
}

$Map* LocaleEquivalentMaps::singleEquivMap = nullptr;
$Map* LocaleEquivalentMaps::multiEquivsMap = nullptr;
$Map* LocaleEquivalentMaps::regionVariantEquivMap = nullptr;

void LocaleEquivalentMaps::init$() {
}

void clinit$LocaleEquivalentMaps($Class* class$) {
	$useLocalCurrentObjectStackCache();
	{
		$assignStatic(LocaleEquivalentMaps::singleEquivMap, $new($HashMap, 817));
		$assignStatic(LocaleEquivalentMaps::multiEquivsMap, $new($HashMap, 143));
		$assignStatic(LocaleEquivalentMaps::regionVariantEquivMap, $new($HashMap, 19));
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("aam"_s, "aas"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("aao"_s, "ar-aao"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("aas"_s, "aam"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("abh"_s, "ar-abh"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("abv"_s, "ar-abv"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("acm"_s, "ar-acm"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("acn"_s, "xia"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("acq"_s, "ar-acq"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("acw"_s, "ar-acw"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("acx"_s, "ar-acx"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("acy"_s, "ar-acy"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("adf"_s, "ar-adf"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("adp"_s, "dz"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ads"_s, "sgn-ads"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("adx"_s, "pcr"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("aeb"_s, "ar-aeb"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("aec"_s, "ar-aec"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("aed"_s, "sgn-aed"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("aen"_s, "sgn-aen"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("afb"_s, "ar-afb"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("afg"_s, "sgn-afg"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ajp"_s, "ar-ajp"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ami"_s, "i-ami"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("aog"_s, "myd"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("apc"_s, "ar-apc"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("apd"_s, "ar-apd"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ar-aao"_s, "aao"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ar-abh"_s, "abh"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ar-abv"_s, "abv"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ar-acm"_s, "acm"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ar-acq"_s, "acq"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ar-acw"_s, "acw"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ar-acx"_s, "acx"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ar-acy"_s, "acy"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ar-adf"_s, "adf"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ar-aeb"_s, "aeb"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ar-aec"_s, "aec"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ar-afb"_s, "afb"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ar-ajp"_s, "ajp"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ar-apc"_s, "apc"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ar-apd"_s, "apd"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ar-arb"_s, "arb"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ar-arq"_s, "arq"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ar-ars"_s, "ars"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ar-ary"_s, "ary"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ar-arz"_s, "arz"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ar-auz"_s, "auz"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ar-avl"_s, "avl"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ar-ayh"_s, "ayh"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ar-ayl"_s, "ayl"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ar-ayn"_s, "ayn"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ar-ayp"_s, "ayp"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ar-bbz"_s, "bbz"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ar-pga"_s, "pga"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ar-shu"_s, "shu"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ar-ssh"_s, "ssh"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("arb"_s, "ar-arb"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("arq"_s, "ar-arq"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ars"_s, "ar-ars"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("art-lojban"_s, "jbo"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ary"_s, "ar-ary"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("arz"_s, "ar-arz"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("asd"_s, "snz"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("asf"_s, "sgn-asf"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("asp"_s, "sgn-asp"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("asq"_s, "sgn-asq"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("asw"_s, "sgn-asw"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("aue"_s, "ktz"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("auz"_s, "ar-auz"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("avl"_s, "ar-avl"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ayh"_s, "ar-ayh"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ayl"_s, "ar-ayl"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ayn"_s, "ar-ayn"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ayp"_s, "ar-ayp"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ayx"_s, "nun"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("bbz"_s, "ar-bbz"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("bcg"_s, "bgm"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("bfk"_s, "sgn-bfk"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("bfy"_s, "ppa"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("bgm"_s, "bcg"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("bic"_s, "bir"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("bir"_s, "bic"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("bjd"_s, "drl"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("bjn"_s, "ms-bjn"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("blg"_s, "iba"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("bmf"_s, "krm"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("bnn"_s, "i-bnn"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("bog"_s, "sgn-bog"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("bpp"_s, "nxu"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("bqn"_s, "sgn-bqn"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("bqy"_s, "sgn-bqy"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("btj"_s, "ms-btj"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("bve"_s, "ms-bve"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("bvl"_s, "sgn-bvl"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("bvu"_s, "ms-bvu"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("cax"_s, "xba"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("cdo"_s, "zh-cdo"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("cds"_s, "sgn-cds"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("cir"_s, "meg"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("cjr"_s, "mom"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("cjy"_s, "zh-cjy"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("cka"_s, "cmr"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("cmk"_s, "xch"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("cmn-hans"_s, "zh-cmn-hans"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("cmn-hant"_s, "zh-cmn-hant"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("cmr"_s, "cka"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("cnp"_s, "zh-cnp"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("coa"_s, "ms-coa"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("cpx"_s, "zh-cpx"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("cqu"_s, "quh"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("csc"_s, "sgn-csc"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("csd"_s, "sgn-csd"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("cse"_s, "sgn-cse"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("csf"_s, "sgn-csf"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("csg"_s, "sgn-csg"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("csl"_s, "sgn-csl"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("csp"_s, "zh-csp"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("csq"_s, "sgn-csq"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("csr"_s, "sgn-csr"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("csx"_s, "sgn-csx"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("czh"_s, "zh-czh"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("czo"_s, "zh-czo"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("dev"_s, "gav"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("dif"_s, "dit"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("dit"_s, "dif"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("dmw"_s, "xrq"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("doq"_s, "sgn-doq"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("drh"_s, "khk"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("drl"_s, "bjd"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("dup"_s, "ms-dup"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("duz"_s, "guv"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("dz"_s, "adp"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ecs"_s, "sgn-ecs"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ehs"_s, "sgn-ehs"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ema"_s, "uok"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("en-gb-oed"_s, "en-gb-oxendict"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("en-gb-oxendict"_s, "en-gb-oed"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("esl"_s, "sgn-esl"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("esn"_s, "sgn-esn"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("eso"_s, "sgn-eso"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("eth"_s, "sgn-eth"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("fcs"_s, "sgn-fcs"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("fse"_s, "sgn-fse"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("fss"_s, "sgn-fss"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("gal"_s, "ilw"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("gan"_s, "zh-gan"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("gav"_s, "dev"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("gdj"_s, "kvs"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("gds"_s, "sgn-gds"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ggn"_s, "gvr"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("gom"_s, "kok-gom"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("gse"_s, "sgn-gse"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("gsm"_s, "sgn-gsm"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("gti"_s, "nyc"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("gus"_s, "sgn-gus"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("guv"_s, "duz"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("gvr"_s, "ggn"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("hab"_s, "sgn-hab"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("haf"_s, "sgn-haf"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("hds"_s, "sgn-hds"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("he"_s, "iw"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("hji"_s, "ms-hji"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("hks"_s, "sgn-hks"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("hle"_s, "sca"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("hos"_s, "sgn-hos"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("hps"_s, "sgn-hps"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("hrr"_s, "jal"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("hsh"_s, "sgn-hsh"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("hsl"_s, "sgn-hsl"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("huw"_s, "pmc"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("i-ami"_s, "ami"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("i-bnn"_s, "bnn"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("i-klingon"_s, "tlh"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("i-lux"_s, "lb"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("i-navajo"_s, "nv"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("i-pwn"_s, "pwn"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("i-tao"_s, "tao"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("i-tay"_s, "tay"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("i-tsu"_s, "tsu"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("iba"_s, "blg"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ibi"_s, "opa"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("icl"_s, "sgn-icl"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("id"_s, "in"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("iks"_s, "sgn-iks"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ils"_s, "sgn-ils"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ilw"_s, "gal"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("in"_s, "id"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("inl"_s, "sgn-inl"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ins"_s, "sgn-ins"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("isr"_s, "sgn-isr"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("iw"_s, "he"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("jak"_s, "ms-jak"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("jal"_s, "hrr"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("jax"_s, "ms-jax"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("jbo"_s, "art-lojban"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("jcs"_s, "sgn-jcs"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("jhs"_s, "sgn-jhs"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ji"_s, "yi"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("jks"_s, "sgn-jks"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("jls"_s, "sgn-jls"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("jos"_s, "sgn-jos"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("jus"_s, "sgn-jus"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("jv"_s, "jw"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("jw"_s, "jv"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("kak"_s, "tne"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("kdz"_s, "ncp"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("kgc"_s, "tdf"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("kgh"_s, "kml"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("kgi"_s, "sgn-kgi"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("khk"_s, "drh"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("kml"_s, "kgh"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("knn"_s, "kok-knn"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("koj"_s, "kwv"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("kok-gom"_s, "gom"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("kok-knn"_s, "knn"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("krm"_s, "bmf"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("kru"_s, "kxl"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ktz"_s, "aue"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("kvb"_s, "ms-kvb"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("kvk"_s, "sgn-kvk"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("kvr"_s, "ms-kvr"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("kvs"_s, "gdj"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("kwq"_s, "yam"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("kwv"_s, "koj"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("kxd"_s, "ms-kxd"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("kxe"_s, "tvd"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("kxl"_s, "kru"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("kxr"_s, "pat"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("lb"_s, "i-lux"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("lbs"_s, "sgn-lbs"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("lce"_s, "ms-lce"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("lcf"_s, "ms-lcf"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("lcq"_s, "ppr"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("lii"_s, "raq"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("liw"_s, "ms-liw"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("llo"_s, "ngt"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("lls"_s, "sgn-lls"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("lmm"_s, "rmx"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("lrr"_s, "yma"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("lsb"_s, "sgn-lsb"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("lsg"_s, "sgn-lsg"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("lsl"_s, "sgn-lsl"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("lsn"_s, "sgn-lsn"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("lso"_s, "sgn-lso"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("lsp"_s, "sgn-lsp"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("lst"_s, "sgn-lst"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("lsv"_s, "sgn-lsv"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("lsy"_s, "sgn-lsy"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ltg"_s, "lv-ltg"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("lv-ltg"_s, "ltg"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("lv-lvs"_s, "lvs"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("lvs"_s, "lv-lvs"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("lws"_s, "sgn-lws"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("lzh"_s, "zh-lzh"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("max"_s, "ms-max"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("mdl"_s, "sgn-mdl"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("meg"_s, "cir"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("meo"_s, "ms-meo"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("mfa"_s, "ms-mfa"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("mfb"_s, "ms-mfb"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("min"_s, "ms-min"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("mnp"_s, "zh-mnp"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("mo"_s, "ro"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("mom"_s, "cjr"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("mqg"_s, "ms-mqg"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("mre"_s, "sgn-mre"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ms-bjn"_s, "bjn"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ms-btj"_s, "btj"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ms-bve"_s, "bve"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ms-bvu"_s, "bvu"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ms-coa"_s, "coa"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ms-dup"_s, "dup"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ms-hji"_s, "hji"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ms-jak"_s, "jak"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ms-jax"_s, "jax"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ms-kvb"_s, "kvb"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ms-kvr"_s, "kvr"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ms-kxd"_s, "kxd"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ms-lce"_s, "lce"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ms-lcf"_s, "lcf"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ms-liw"_s, "liw"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ms-max"_s, "max"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ms-meo"_s, "meo"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ms-mfa"_s, "mfa"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ms-mfb"_s, "mfb"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ms-min"_s, "min"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ms-mqg"_s, "mqg"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ms-msi"_s, "msi"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ms-mui"_s, "mui"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ms-orn"_s, "orn"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ms-ors"_s, "ors"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ms-pel"_s, "pel"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ms-pse"_s, "pse"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ms-tmw"_s, "tmw"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ms-urk"_s, "urk"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ms-vkk"_s, "vkk"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ms-vkt"_s, "vkt"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ms-xmm"_s, "xmm"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ms-zlm"_s, "zlm"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ms-zmi"_s, "zmi"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ms-zsm"_s, "zsm"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("msd"_s, "sgn-msd"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("msi"_s, "ms-msi"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("msr"_s, "sgn-msr"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("mtm"_s, "ymt"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("mui"_s, "ms-mui"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("myd"_s, "aog"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("mzc"_s, "sgn-mzc"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("mzg"_s, "sgn-mzg"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("mzy"_s, "sgn-mzy"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("nad"_s, "xny"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("nb"_s, "no-bok"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("nbr"_s, "nns"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("nbs"_s, "sgn-nbs"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ncp"_s, "kdz"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ngt"_s, "llo"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ngv"_s, "nnx"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("nn"_s, "no-nyn"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("nns"_s, "nbr"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("nnx"_s, "ngv"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("no-bok"_s, "nb"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("no-nyn"_s, "nn"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("nsi"_s, "sgn-nsi"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("nsp"_s, "sgn-nsp"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("nsr"_s, "sgn-nsr"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("nun"_s, "ayx"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("nv"_s, "i-navajo"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("nxu"_s, "bpp"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("nyc"_s, "gti"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("nzs"_s, "sgn-nzs"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("okl"_s, "sgn-okl"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ola"_s, "thw"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("opa"_s, "ibi"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("orn"_s, "ms-orn"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ors"_s, "ms-ors"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("pat"_s, "kxr"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("pcr"_s, "adx"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("pel"_s, "ms-pel"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("pga"_s, "ar-pga"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("pgz"_s, "sgn-pgz"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("phr"_s, "pmu"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("pks"_s, "sgn-pks"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("pmc"_s, "huw"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("pmu"_s, "phr"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ppa"_s, "bfy"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ppr"_s, "lcq"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("prl"_s, "sgn-prl"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("prt"_s, "pry"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("pry"_s, "prt"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("prz"_s, "sgn-prz"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("psc"_s, "sgn-psc"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("psd"_s, "sgn-psd"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("pse"_s, "ms-pse"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("psg"_s, "sgn-psg"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("psl"_s, "sgn-psl"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("pso"_s, "sgn-pso"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("psp"_s, "sgn-psp"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("pub"_s, "puz"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("puz"_s, "pub"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("pwn"_s, "i-pwn"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("pys"_s, "sgn-pys"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("quh"_s, "cqu"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("raq"_s, "lii"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ras"_s, "tie"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("rms"_s, "sgn-rms"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("rmx"_s, "lmm"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ro"_s, "mo"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("rsi"_s, "sgn-rsi"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("rsl"_s, "sgn-rsl"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("rsm"_s, "sgn-rsm"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sca"_s, "hle"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("scv"_s, "zir"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sdl"_s, "sgn-sdl"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-ads"_s, "ads"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-aed"_s, "aed"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-aen"_s, "aen"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-afg"_s, "afg"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-asf"_s, "asf"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-asp"_s, "asp"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-asq"_s, "asq"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-asw"_s, "asw"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-bfk"_s, "bfk"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-bog"_s, "bog"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-bqn"_s, "bqn"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-bqy"_s, "bqy"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-bvl"_s, "bvl"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-cds"_s, "cds"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-csc"_s, "csc"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-csd"_s, "csd"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-cse"_s, "cse"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-csf"_s, "csf"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-csg"_s, "csg"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-csl"_s, "csl"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-csq"_s, "csq"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-csr"_s, "csr"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-csx"_s, "csx"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-doq"_s, "doq"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-ecs"_s, "ecs"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-ehs"_s, "ehs"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-esl"_s, "esl"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-esn"_s, "esn"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-eso"_s, "eso"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-eth"_s, "eth"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-fcs"_s, "fcs"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-fse"_s, "fse"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-fss"_s, "fss"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-gds"_s, "gds"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-gse"_s, "gse"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-gsm"_s, "gsm"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-gus"_s, "gus"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-hab"_s, "hab"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-haf"_s, "haf"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-hds"_s, "hds"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-hks"_s, "hks"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-hos"_s, "hos"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-hps"_s, "hps"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-hsh"_s, "hsh"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-hsl"_s, "hsl"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-icl"_s, "icl"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-iks"_s, "iks"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-ils"_s, "ils"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-inl"_s, "inl"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-ins"_s, "ins"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-isr"_s, "isr"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-jcs"_s, "jcs"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-jhs"_s, "jhs"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-jks"_s, "jks"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-jls"_s, "jls"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-jos"_s, "jos"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-jus"_s, "jus"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-kgi"_s, "kgi"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-kvk"_s, "kvk"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-lbs"_s, "lbs"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-lls"_s, "lls"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-lsb"_s, "lsb"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-lsg"_s, "lsg"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-lsl"_s, "lsl"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-lsn"_s, "lsn"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-lso"_s, "lso"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-lsp"_s, "lsp"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-lst"_s, "lst"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-lsv"_s, "lsv"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-lsy"_s, "lsy"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-lws"_s, "lws"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-mdl"_s, "mdl"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-mre"_s, "mre"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-msd"_s, "msd"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-msr"_s, "msr"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-mzc"_s, "mzc"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-mzg"_s, "mzg"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-mzy"_s, "mzy"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-nbs"_s, "nbs"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-nsi"_s, "nsi"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-nsp"_s, "nsp"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-nsr"_s, "nsr"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-nzs"_s, "nzs"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-okl"_s, "okl"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-pgz"_s, "pgz"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-pks"_s, "pks"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-prl"_s, "prl"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-prz"_s, "prz"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-psc"_s, "psc"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-psd"_s, "psd"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-psg"_s, "psg"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-psl"_s, "psl"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-pso"_s, "pso"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-psp"_s, "psp"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-pys"_s, "pys"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-rms"_s, "rms"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-rsi"_s, "rsi"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-rsl"_s, "rsl"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-rsm"_s, "rsm"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-sdl"_s, "sdl"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-sgx"_s, "sgx"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-slf"_s, "slf"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-sls"_s, "sls"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-sqk"_s, "sqk"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-sqs"_s, "sqs"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-sqx"_s, "sqx"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-ssr"_s, "ssr"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-svk"_s, "svk"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-syy"_s, "syy"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-szs"_s, "szs"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-tse"_s, "tse"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-tsm"_s, "tsm"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-tsq"_s, "tsq"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-tss"_s, "tss"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-tsy"_s, "tsy"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-tza"_s, "tza"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-ugn"_s, "ugn"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-ugy"_s, "ugy"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-ukl"_s, "ukl"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-uks"_s, "uks"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-vsi"_s, "vsi"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-vsl"_s, "vsl"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-vsv"_s, "vsv"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-wbs"_s, "wbs"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-xki"_s, "xki"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-xml"_s, "xml"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-xms"_s, "xms"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-yds"_s, "yds"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-ygs"_s, "ygs"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-yhs"_s, "yhs"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-ysl"_s, "ysl"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-ysm"_s, "ysm"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-zib"_s, "zib"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgn-zsl"_s, "zsl"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sgx"_s, "sgn-sgx"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("shu"_s, "ar-shu"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("slf"_s, "sgn-slf"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sls"_s, "sgn-sls"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("snz"_s, "asd"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sqk"_s, "sgn-sqk"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sqs"_s, "sgn-sqs"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sqx"_s, "sgn-sqx"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ssh"_s, "ar-ssh"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ssr"_s, "sgn-ssr"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("svk"_s, "sgn-svk"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sw-swc"_s, "swc"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("sw-swh"_s, "swh"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("swc"_s, "sw-swc"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("swh"_s, "sw-swh"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("syy"_s, "sgn-syy"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("szs"_s, "sgn-szs"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("taj"_s, "tsf"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("tao"_s, "i-tao"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("tay"_s, "i-tay"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("tdf"_s, "kgc"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("thc"_s, "tpo"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("thw"_s, "ola"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("tie"_s, "ras"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("tkk"_s, "twm"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("tlh"_s, "i-klingon"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("tlw"_s, "weo"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("tmp"_s, "tyj"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("tmw"_s, "ms-tmw"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("tne"_s, "kak"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("tpo"_s, "thc"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("tse"_s, "sgn-tse"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("tsf"_s, "taj"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("tsm"_s, "sgn-tsm"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("tsq"_s, "sgn-tsq"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("tss"_s, "sgn-tss"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("tsu"_s, "i-tsu"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("tsy"_s, "sgn-tsy"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("tvd"_s, "kxe"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("twm"_s, "tkk"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("tyj"_s, "tmp"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("tza"_s, "sgn-tza"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ugn"_s, "sgn-ugn"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ugy"_s, "sgn-ugy"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ukl"_s, "sgn-ukl"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("uks"_s, "sgn-uks"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("uok"_s, "ema"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("urk"_s, "ms-urk"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("uz-uzn"_s, "uzn"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("uz-uzs"_s, "uzs"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("uzn"_s, "uz-uzn"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("uzs"_s, "uz-uzs"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("vkk"_s, "ms-vkk"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("vkt"_s, "ms-vkt"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("vsi"_s, "sgn-vsi"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("vsl"_s, "sgn-vsl"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("vsv"_s, "sgn-vsv"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("waw"_s, "xkh"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("wbs"_s, "sgn-wbs"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("weo"_s, "tlw"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("wuu"_s, "zh-wuu"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("xba"_s, "cax"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("xch"_s, "cmk"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("xia"_s, "acn"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("xkh"_s, "waw"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("xki"_s, "sgn-xki"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("xml"_s, "sgn-xml"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("xmm"_s, "ms-xmm"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("xms"_s, "sgn-xms"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("xny"_s, "nad"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("xrq"_s, "dmw"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("yam"_s, "kwq"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("yds"_s, "sgn-yds"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ygs"_s, "sgn-ygs"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("yhs"_s, "sgn-yhs"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("yi"_s, "ji"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("yma"_s, "lrr"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ymt"_s, "mtm"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("yos"_s, "zom"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ysl"_s, "sgn-ysl"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("ysm"_s, "sgn-ysm"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("yue"_s, "zh-yue"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("yug"_s, "yuu"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("yuu"_s, "yug"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("zh-cdo"_s, "cdo"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("zh-cjy"_s, "cjy"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("zh-cmn-hans"_s, "cmn-hans"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("zh-cmn-hant"_s, "cmn-hant"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("zh-cnp"_s, "cnp"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("zh-cpx"_s, "cpx"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("zh-csp"_s, "csp"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("zh-czh"_s, "czh"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("zh-czo"_s, "czo"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("zh-gan"_s, "gan"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("zh-lzh"_s, "lzh"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("zh-mnp"_s, "mnp"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("zh-wuu"_s, "wuu"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("zh-yue"_s, "yue"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("zib"_s, "sgn-zib"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("zir"_s, "scv"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("zlm"_s, "ms-zlm"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("zmi"_s, "ms-zmi"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("zom"_s, "yos"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("zsl"_s, "sgn-zsl"_s);
		$nc(LocaleEquivalentMaps::singleEquivMap)->put("zsm"_s, "ms-zsm"_s);
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("ase"_s, $$new($StringArray, {
			"sgn-ase"_s,
			"sgn-us"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("bfi"_s, $$new($StringArray, {
			"sgn-bfi"_s,
			"sgn-gb"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("bzs"_s, $$new($StringArray, {
			"sgn-bzs"_s,
			"sgn-br"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("ccq"_s, $$new($StringArray, {
			"rki"_s,
			"ybd"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("cmn"_s, $$new($StringArray, {
			"zh-cmn"_s,
			"zh-guoyu"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("coy"_s, $$new($StringArray, {
			"pij"_s,
			"nts"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("csn"_s, $$new($StringArray, {
			"sgn-csn"_s,
			"sgn-co"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("drr"_s, $$new($StringArray, {
			"kzk"_s,
			"gli"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("drw"_s, $$new($StringArray, {
			"prs"_s,
			"tnf"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("dse"_s, $$new($StringArray, {
			"sgn-dse"_s,
			"sgn-nl"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("dsl"_s, $$new($StringArray, {
			"sgn-dsl"_s,
			"sgn-dk"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("dtp"_s, $$new($StringArray, {
			"ktr"_s,
			"kzj"_s,
			"kzt"_s,
			"tdu"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("fsl"_s, $$new($StringArray, {
			"sgn-fsl"_s,
			"sgn-fr"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("gfx"_s, $$new($StringArray, {
			"vaj"_s,
			"mwj"_s,
			"oun"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("gli"_s, $$new($StringArray, {
			"kzk"_s,
			"drr"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("gsg"_s, $$new($StringArray, {
			"sgn-gsg"_s,
			"sgn-de"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("gss"_s, $$new($StringArray, {
			"sgn-gss"_s,
			"sgn-gr"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("hak"_s, $$new($StringArray, {
			"zh-hak"_s,
			"i-hak"_s,
			"zh-hakka"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("hsn"_s, $$new($StringArray, {
			"zh-hsn"_s,
			"zh-xiang"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("i-hak"_s, $$new($StringArray, {
			"hak"_s,
			"zh-hak"_s,
			"zh-hakka"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("ise"_s, $$new($StringArray, {
			"sgn-ise"_s,
			"sgn-it"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("isg"_s, $$new($StringArray, {
			"sgn-isg"_s,
			"sgn-ie"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("jeg"_s, $$new($StringArray, {
			"oyb"_s,
			"skk"_s,
			"thx"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("jsl"_s, $$new($StringArray, {
			"sgn-jsl"_s,
			"sgn-jp"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("ktr"_s, $$new($StringArray, {
			"dtp"_s,
			"kzj"_s,
			"kzt"_s,
			"tdu"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("kzj"_s, $$new($StringArray, {
			"dtp"_s,
			"ktr"_s,
			"kzt"_s,
			"tdu"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("kzk"_s, $$new($StringArray, {
			"drr"_s,
			"gli"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("kzt"_s, $$new($StringArray, {
			"dtp"_s,
			"ktr"_s,
			"kzj"_s,
			"tdu"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("mfs"_s, $$new($StringArray, {
			"sgn-mfs"_s,
			"sgn-mx"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("mry"_s, $$new($StringArray, {
			"mst"_s,
			"myt"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("mst"_s, $$new($StringArray, {
			"mry"_s,
			"myt"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("mwj"_s, $$new($StringArray, {
			"vaj"_s,
			"gfx"_s,
			"oun"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("myt"_s, $$new($StringArray, {
			"mry"_s,
			"mst"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("nan"_s, $$new($StringArray, {
			"zh-nan"_s,
			"zh-min-nan"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("ncs"_s, $$new($StringArray, {
			"sgn-ncs"_s,
			"sgn-ni"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("nsl"_s, $$new($StringArray, {
			"sgn-nsl"_s,
			"sgn-no"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("nts"_s, $$new($StringArray, {
			"pij"_s,
			"coy"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("oun"_s, $$new($StringArray, {
			"vaj"_s,
			"gfx"_s,
			"mwj"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("oyb"_s, $$new($StringArray, {
			"jeg"_s,
			"skk"_s,
			"thx"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("pij"_s, $$new($StringArray, {
			"coy"_s,
			"nts"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("prs"_s, $$new($StringArray, {
			"drw"_s,
			"tnf"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("psr"_s, $$new($StringArray, {
			"sgn-psr"_s,
			"sgn-pt"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("rki"_s, $$new($StringArray, {
			"ccq"_s,
			"ybd"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sfb"_s, $$new($StringArray, {
			"sgn-sfb"_s,
			"sgn-be-fr"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sfs"_s, $$new($StringArray, {
			"sgn-sfs"_s,
			"sgn-za"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgg"_s, $$new($StringArray, {
			"sgn-sgg"_s,
			"sgn-ch-de"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-ase"_s, $$new($StringArray, {
			"ase"_s,
			"sgn-us"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-be-fr"_s, $$new($StringArray, {
			"sfb"_s,
			"sgn-sfb"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-be-nl"_s, $$new($StringArray, {
			"vgt"_s,
			"sgn-vgt"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-bfi"_s, $$new($StringArray, {
			"bfi"_s,
			"sgn-gb"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-br"_s, $$new($StringArray, {
			"bzs"_s,
			"sgn-bzs"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-bzs"_s, $$new($StringArray, {
			"bzs"_s,
			"sgn-br"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-ch-de"_s, $$new($StringArray, {
			"sgg"_s,
			"sgn-sgg"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-co"_s, $$new($StringArray, {
			"csn"_s,
			"sgn-csn"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-csn"_s, $$new($StringArray, {
			"csn"_s,
			"sgn-co"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-de"_s, $$new($StringArray, {
			"gsg"_s,
			"sgn-gsg"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-dk"_s, $$new($StringArray, {
			"dsl"_s,
			"sgn-dsl"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-dse"_s, $$new($StringArray, {
			"dse"_s,
			"sgn-nl"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-dsl"_s, $$new($StringArray, {
			"dsl"_s,
			"sgn-dk"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-es"_s, $$new($StringArray, {
			"ssp"_s,
			"sgn-ssp"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-fr"_s, $$new($StringArray, {
			"fsl"_s,
			"sgn-fsl"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-fsl"_s, $$new($StringArray, {
			"fsl"_s,
			"sgn-fr"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-gb"_s, $$new($StringArray, {
			"bfi"_s,
			"sgn-bfi"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-gr"_s, $$new($StringArray, {
			"gss"_s,
			"sgn-gss"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-gsg"_s, $$new($StringArray, {
			"gsg"_s,
			"sgn-de"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-gss"_s, $$new($StringArray, {
			"gss"_s,
			"sgn-gr"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-ie"_s, $$new($StringArray, {
			"isg"_s,
			"sgn-isg"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-ise"_s, $$new($StringArray, {
			"ise"_s,
			"sgn-it"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-isg"_s, $$new($StringArray, {
			"isg"_s,
			"sgn-ie"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-it"_s, $$new($StringArray, {
			"ise"_s,
			"sgn-ise"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-jp"_s, $$new($StringArray, {
			"jsl"_s,
			"sgn-jsl"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-jsl"_s, $$new($StringArray, {
			"jsl"_s,
			"sgn-jp"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-mfs"_s, $$new($StringArray, {
			"mfs"_s,
			"sgn-mx"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-mx"_s, $$new($StringArray, {
			"mfs"_s,
			"sgn-mfs"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-ncs"_s, $$new($StringArray, {
			"ncs"_s,
			"sgn-ni"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-ni"_s, $$new($StringArray, {
			"ncs"_s,
			"sgn-ncs"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-nl"_s, $$new($StringArray, {
			"dse"_s,
			"sgn-dse"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-no"_s, $$new($StringArray, {
			"nsl"_s,
			"sgn-nsl"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-nsl"_s, $$new($StringArray, {
			"nsl"_s,
			"sgn-no"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-psr"_s, $$new($StringArray, {
			"psr"_s,
			"sgn-pt"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-pt"_s, $$new($StringArray, {
			"psr"_s,
			"sgn-psr"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-se"_s, $$new($StringArray, {
			"swl"_s,
			"sgn-swl"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-sfb"_s, $$new($StringArray, {
			"sfb"_s,
			"sgn-be-fr"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-sfs"_s, $$new($StringArray, {
			"sfs"_s,
			"sgn-za"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-sgg"_s, $$new($StringArray, {
			"sgg"_s,
			"sgn-ch-de"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-ssp"_s, $$new($StringArray, {
			"ssp"_s,
			"sgn-es"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-swl"_s, $$new($StringArray, {
			"swl"_s,
			"sgn-se"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-us"_s, $$new($StringArray, {
			"ase"_s,
			"sgn-ase"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-vgt"_s, $$new($StringArray, {
			"vgt"_s,
			"sgn-be-nl"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("sgn-za"_s, $$new($StringArray, {
			"sfs"_s,
			"sgn-sfs"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("skk"_s, $$new($StringArray, {
			"oyb"_s,
			"jeg"_s,
			"thx"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("ssp"_s, $$new($StringArray, {
			"sgn-ssp"_s,
			"sgn-es"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("swl"_s, $$new($StringArray, {
			"sgn-swl"_s,
			"sgn-se"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("tdu"_s, $$new($StringArray, {
			"dtp"_s,
			"ktr"_s,
			"kzj"_s,
			"kzt"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("thx"_s, $$new($StringArray, {
			"oyb"_s,
			"jeg"_s,
			"skk"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("tnf"_s, $$new($StringArray, {
			"prs"_s,
			"drw"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("vaj"_s, $$new($StringArray, {
			"gfx"_s,
			"mwj"_s,
			"oun"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("vgt"_s, $$new($StringArray, {
			"sgn-vgt"_s,
			"sgn-be-nl"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("ybd"_s, $$new($StringArray, {
			"rki"_s,
			"ccq"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("zh-cmn"_s, $$new($StringArray, {
			"cmn"_s,
			"zh-guoyu"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("zh-guoyu"_s, $$new($StringArray, {
			"cmn"_s,
			"zh-cmn"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("zh-hak"_s, $$new($StringArray, {
			"hak"_s,
			"i-hak"_s,
			"zh-hakka"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("zh-hakka"_s, $$new($StringArray, {
			"hak"_s,
			"zh-hak"_s,
			"i-hak"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("zh-hsn"_s, $$new($StringArray, {
			"hsn"_s,
			"zh-xiang"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("zh-min-nan"_s, $$new($StringArray, {
			"nan"_s,
			"zh-nan"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("zh-nan"_s, $$new($StringArray, {
			"nan"_s,
			"zh-min-nan"_s
		}));
		$nc(LocaleEquivalentMaps::multiEquivsMap)->put("zh-xiang"_s, $$new($StringArray, {
			"hsn"_s,
			"zh-hsn"_s
		}));
		$nc(LocaleEquivalentMaps::regionVariantEquivMap)->put("-alalc97"_s, "-heploc"_s);
		$nc(LocaleEquivalentMaps::regionVariantEquivMap)->put("-bu"_s, "-mm"_s);
		$nc(LocaleEquivalentMaps::regionVariantEquivMap)->put("-cd"_s, "-zr"_s);
		$nc(LocaleEquivalentMaps::regionVariantEquivMap)->put("-dd"_s, "-de"_s);
		$nc(LocaleEquivalentMaps::regionVariantEquivMap)->put("-de"_s, "-dd"_s);
		$nc(LocaleEquivalentMaps::regionVariantEquivMap)->put("-fr"_s, "-fx"_s);
		$nc(LocaleEquivalentMaps::regionVariantEquivMap)->put("-fx"_s, "-fr"_s);
		$nc(LocaleEquivalentMaps::regionVariantEquivMap)->put("-heploc"_s, "-alalc97"_s);
		$nc(LocaleEquivalentMaps::regionVariantEquivMap)->put("-mm"_s, "-bu"_s);
		$nc(LocaleEquivalentMaps::regionVariantEquivMap)->put("-tl"_s, "-tp"_s);
		$nc(LocaleEquivalentMaps::regionVariantEquivMap)->put("-tp"_s, "-tl"_s);
		$nc(LocaleEquivalentMaps::regionVariantEquivMap)->put("-yd"_s, "-ye"_s);
		$nc(LocaleEquivalentMaps::regionVariantEquivMap)->put("-ye"_s, "-yd"_s);
		$nc(LocaleEquivalentMaps::regionVariantEquivMap)->put("-zr"_s, "-cd"_s);
	}
}

LocaleEquivalentMaps::LocaleEquivalentMaps() {
}

$Class* LocaleEquivalentMaps::load$($String* name, bool initialize) {
	$loadClass(LocaleEquivalentMaps, name, initialize, &_LocaleEquivalentMaps_ClassInfo_, clinit$LocaleEquivalentMaps, allocate$LocaleEquivalentMaps);
	return class$;
}

$Class* LocaleEquivalentMaps::class$ = nullptr;

		} // locale
	} // util
} // sun