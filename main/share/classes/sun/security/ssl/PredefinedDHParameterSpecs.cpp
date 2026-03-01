#include <sun/security/ssl/PredefinedDHParameterSpecs.h>

#include <java/lang/CharSequence.h>
#include <java/math/BigInteger.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/Collections.h>
#include <java/util/HashMap.h>
#include <java/util/Map.h>
#include <java/util/regex/Matcher.h>
#include <java/util/regex/Pattern.h>
#include <javax/crypto/spec/DHParameterSpec.h>
#include <sun/security/ssl/PredefinedDHParameterSpecs$1.h>
#include <sun/security/ssl/SSLLogger.h>
#include <jcpp.h>

#undef PRIME_CERTAINTY
#undef PROPERTY_NAME
#undef TWO

using $BigIntegerArray = $Array<::java::math::BigInteger>;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $BigInteger = ::java::math::BigInteger;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Collections = ::java::util::Collections;
using $HashMap = ::java::util::HashMap;
using $Map = ::java::util::Map;
using $Matcher = ::java::util::regex::Matcher;
using $Pattern = ::java::util::regex::Pattern;
using $DHParameterSpec = ::javax::crypto::spec::DHParameterSpec;
using $PredefinedDHParameterSpecs$1 = ::sun::security::ssl::PredefinedDHParameterSpecs$1;
using $SSLLogger = ::sun::security::ssl::SSLLogger;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _PredefinedDHParameterSpecs_FieldInfo_[] = {
	{"p512", "Ljava/math/BigInteger;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PredefinedDHParameterSpecs, p512)},
	{"p768", "Ljava/math/BigInteger;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PredefinedDHParameterSpecs, p768)},
	{"p1024", "Ljava/math/BigInteger;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PredefinedDHParameterSpecs, p1024)},
	{"p1536", "Ljava/math/BigInteger;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PredefinedDHParameterSpecs, p1536)},
	{"p2048", "Ljava/math/BigInteger;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PredefinedDHParameterSpecs, p2048)},
	{"p3072", "Ljava/math/BigInteger;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PredefinedDHParameterSpecs, p3072)},
	{"p4096", "Ljava/math/BigInteger;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PredefinedDHParameterSpecs, p4096)},
	{"p6144", "Ljava/math/BigInteger;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PredefinedDHParameterSpecs, p6144)},
	{"p8192", "Ljava/math/BigInteger;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PredefinedDHParameterSpecs, p8192)},
	{"supportedPrimes", "[Ljava/math/BigInteger;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PredefinedDHParameterSpecs, supportedPrimes)},
	{"ffdhePrimes", "[Ljava/math/BigInteger;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PredefinedDHParameterSpecs, ffdhePrimes)},
	{"PRIME_CERTAINTY", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(PredefinedDHParameterSpecs, PRIME_CERTAINTY)},
	{"PROPERTY_NAME", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PredefinedDHParameterSpecs, PROPERTY_NAME)},
	{"spacesPattern", "Ljava/util/regex/Pattern;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PredefinedDHParameterSpecs, spacesPattern)},
	{"syntaxPattern", "Ljava/util/regex/Pattern;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PredefinedDHParameterSpecs, syntaxPattern)},
	{"paramsPattern", "Ljava/util/regex/Pattern;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PredefinedDHParameterSpecs, paramsPattern)},
	{"definedParams", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/Integer;Ljavax/crypto/spec/DHParameterSpec;>;", $STATIC | $FINAL, $staticField(PredefinedDHParameterSpecs, definedParams)},
	{"ffdheParams", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/Integer;Ljavax/crypto/spec/DHParameterSpec;>;", $STATIC | $FINAL, $staticField(PredefinedDHParameterSpecs, ffdheParams)},
	{}
};

$MethodInfo _PredefinedDHParameterSpecs_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(PredefinedDHParameterSpecs, init$, void)},
	{}
};

$InnerClassInfo _PredefinedDHParameterSpecs_InnerClassesInfo_[] = {
	{"sun.security.ssl.PredefinedDHParameterSpecs$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _PredefinedDHParameterSpecs_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.PredefinedDHParameterSpecs",
	"java.lang.Object",
	nullptr,
	_PredefinedDHParameterSpecs_FieldInfo_,
	_PredefinedDHParameterSpecs_MethodInfo_,
	nullptr,
	nullptr,
	_PredefinedDHParameterSpecs_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.ssl.PredefinedDHParameterSpecs$1"
};

$Object* allocate$PredefinedDHParameterSpecs($Class* clazz) {
	return $of($alloc(PredefinedDHParameterSpecs));
}

$BigInteger* PredefinedDHParameterSpecs::p512 = nullptr;
$BigInteger* PredefinedDHParameterSpecs::p768 = nullptr;
$BigInteger* PredefinedDHParameterSpecs::p1024 = nullptr;
$BigInteger* PredefinedDHParameterSpecs::p1536 = nullptr;
$BigInteger* PredefinedDHParameterSpecs::p2048 = nullptr;
$BigInteger* PredefinedDHParameterSpecs::p3072 = nullptr;
$BigInteger* PredefinedDHParameterSpecs::p4096 = nullptr;
$BigInteger* PredefinedDHParameterSpecs::p6144 = nullptr;
$BigInteger* PredefinedDHParameterSpecs::p8192 = nullptr;
$BigIntegerArray* PredefinedDHParameterSpecs::supportedPrimes = nullptr;
$BigIntegerArray* PredefinedDHParameterSpecs::ffdhePrimes = nullptr;
$String* PredefinedDHParameterSpecs::PROPERTY_NAME = nullptr;
$Pattern* PredefinedDHParameterSpecs::spacesPattern = nullptr;
$Pattern* PredefinedDHParameterSpecs::syntaxPattern = nullptr;
$Pattern* PredefinedDHParameterSpecs::paramsPattern = nullptr;
$Map* PredefinedDHParameterSpecs::definedParams = nullptr;
$Map* PredefinedDHParameterSpecs::ffdheParams = nullptr;

void PredefinedDHParameterSpecs::init$() {
}

void clinit$PredefinedDHParameterSpecs($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(PredefinedDHParameterSpecs::PROPERTY_NAME, "jdk.tls.server.defaultDHEParameters"_s);
	$beforeCallerSensitive();
	$assignStatic(PredefinedDHParameterSpecs::p512, $new($BigInteger, "D87780E15FF50B4ABBE89870188B049406B5BEA98AB23A0241D88EA75B7755E669C08093D3F0CA7FC3A5A25CF067DCB9A43DD89D1D90921C6328884461E0B6D3"_s, 16));
	$assignStatic(PredefinedDHParameterSpecs::p768, $new($BigInteger, "FFFFFFFFFFFFFFFFC90FDAA22168C234C4C6628B80DC1CD129024E088A67CC74020BBEA63B139B22514A08798E3404DDEF9519B3CD3A431B302B0A6DF25F14374FE1356D6D51C245E485B576625E7EC6F44C42E9A63A3620FFFFFFFFFFFFFFFF"_s, 16));
	$assignStatic(PredefinedDHParameterSpecs::p1024, $new($BigInteger, "FFFFFFFFFFFFFFFFC90FDAA22168C234C4C6628B80DC1CD129024E088A67CC74020BBEA63B139B22514A08798E3404DDEF9519B3CD3A431B302B0A6DF25F14374FE1356D6D51C245E485B576625E7EC6F44C42E9A637ED6B0BFF5CB6F406B7EDEE386BFB5A899FA5AE9F24117C4B1FE649286651ECE65381FFFFFFFFFFFFFFFF"_s, 16));
	$assignStatic(PredefinedDHParameterSpecs::p1536, $new($BigInteger, "FFFFFFFFFFFFFFFFC90FDAA22168C234C4C6628B80DC1CD129024E088A67CC74020BBEA63B139B22514A08798E3404DDEF9519B3CD3A431B302B0A6DF25F14374FE1356D6D51C245E485B576625E7EC6F44C42E9A637ED6B0BFF5CB6F406B7EDEE386BFB5A899FA5AE9F24117C4B1FE649286651ECE45B3DC2007CB8A163BF0598DA48361C55D39A69163FA8FD24CF5F83655D23DCA3AD961C62F356208552BB9ED529077096966D670C354E4ABC9804F1746C08CA237327FFFFFFFFFFFFFFFF"_s, 16));
	$assignStatic(PredefinedDHParameterSpecs::p2048, $new($BigInteger, "FFFFFFFFFFFFFFFFADF85458A2BB4A9AAFDC5620273D3CF1D8B9C583CE2D3695A9E13641146433FBCC939DCE249B3EF97D2FE363630C75D8F681B202AEC4617AD3DF1ED5D5FD65612433F51F5F066ED0856365553DED1AF3B557135E7F57C935984F0C70E0E68B77E2A689DAF3EFE8721DF158A136ADE73530ACCA4F483A797ABC0AB182B324FB61D108A94BB2C8E3FBB96ADAB760D7F4681D4F42A3DE394DF4AE56EDE76372BB190B07A7C8EE0A6D709E02FCE1CDF7E2ECC03404CD28342F619172FE9CE98583FF8E4F1232EEF28183C3FE3B1B4C6FAD733BB5FCBC2EC22005C58EF1837D1683B2C6F34A26C1B2EFFA886B423861285C97FFFFFFFFFFFFFFFF"_s, 16));
	$assignStatic(PredefinedDHParameterSpecs::p3072, $new($BigInteger, "FFFFFFFFFFFFFFFFADF85458A2BB4A9AAFDC5620273D3CF1D8B9C583CE2D3695A9E13641146433FBCC939DCE249B3EF97D2FE363630C75D8F681B202AEC4617AD3DF1ED5D5FD65612433F51F5F066ED0856365553DED1AF3B557135E7F57C935984F0C70E0E68B77E2A689DAF3EFE8721DF158A136ADE73530ACCA4F483A797ABC0AB182B324FB61D108A94BB2C8E3FBB96ADAB760D7F4681D4F42A3DE394DF4AE56EDE76372BB190B07A7C8EE0A6D709E02FCE1CDF7E2ECC03404CD28342F619172FE9CE98583FF8E4F1232EEF28183C3FE3B1B4C6FAD733BB5FCBC2EC22005C58EF1837D1683B2C6F34A26C1B2EFFA886B4238611FCFDCDE355B3B6519035BBC34F4DEF99C023861B46FC9D6E6C9077AD91D2691F7F7EE598CB0FAC186D91CAEFE130985139270B4130C93BC437944F4FD4452E2D74DD364F2E21E71F54BFF5CAE82AB9C9DF69EE86D2BC522363A0DABC521979B0DEADA1DBF9A42D5C4484E0ABCD06BFA53DDEF3C1B20EE3FD59D7C25E41D2B66C62E37FFFFFFFFFFFFFFFF"_s, 16));
	$assignStatic(PredefinedDHParameterSpecs::p4096, $new($BigInteger, "FFFFFFFFFFFFFFFFADF85458A2BB4A9AAFDC5620273D3CF1D8B9C583CE2D3695A9E13641146433FBCC939DCE249B3EF97D2FE363630C75D8F681B202AEC4617AD3DF1ED5D5FD65612433F51F5F066ED0856365553DED1AF3B557135E7F57C935984F0C70E0E68B77E2A689DAF3EFE8721DF158A136ADE73530ACCA4F483A797ABC0AB182B324FB61D108A94BB2C8E3FBB96ADAB760D7F4681D4F42A3DE394DF4AE56EDE76372BB190B07A7C8EE0A6D709E02FCE1CDF7E2ECC03404CD28342F619172FE9CE98583FF8E4F1232EEF28183C3FE3B1B4C6FAD733BB5FCBC2EC22005C58EF1837D1683B2C6F34A26C1B2EFFA886B4238611FCFDCDE355B3B6519035BBC34F4DEF99C023861B46FC9D6E6C9077AD91D2691F7F7EE598CB0FAC186D91CAEFE130985139270B4130C93BC437944F4FD4452E2D74DD364F2E21E71F54BFF5CAE82AB9C9DF69EE86D2BC522363A0DABC521979B0DEADA1DBF9A42D5C4484E0ABCD06BFA53DDEF3C1B20EE3FD59D7C25E41D2B669E1EF16E6F52C3164DF4FB7930E9E4E58857B6AC7D5F42D69F6D187763CF1D5503400487F55BA57E31CC7A7135C886EFB4318AED6A1E012D9E6832A907600A918130C46DC778F971AD0038092999A333CB8B7A1A1DB93D7140003C2A4ECEA9F98D0ACC0A8291CDCEC97DCF8EC9B55A7F88A46B4DB5A851F44182E1C68A007E5E655F6AFFFFFFFFFFFFFFFF"_s, 16));
	$assignStatic(PredefinedDHParameterSpecs::p6144, $new($BigInteger, "FFFFFFFFFFFFFFFFADF85458A2BB4A9AAFDC5620273D3CF1D8B9C583CE2D3695A9E13641146433FBCC939DCE249B3EF97D2FE363630C75D8F681B202AEC4617AD3DF1ED5D5FD65612433F51F5F066ED0856365553DED1AF3B557135E7F57C935984F0C70E0E68B77E2A689DAF3EFE8721DF158A136ADE73530ACCA4F483A797ABC0AB182B324FB61D108A94BB2C8E3FBB96ADAB760D7F4681D4F42A3DE394DF4AE56EDE76372BB190B07A7C8EE0A6D709E02FCE1CDF7E2ECC03404CD28342F619172FE9CE98583FF8E4F1232EEF28183C3FE3B1B4C6FAD733BB5FCBC2EC22005C58EF1837D1683B2C6F34A26C1B2EFFA886B4238611FCFDCDE355B3B6519035BBC34F4DEF99C023861B46FC9D6E6C9077AD91D2691F7F7EE598CB0FAC186D91CAEFE130985139270B4130C93BC437944F4FD4452E2D74DD364F2E21E71F54BFF5CAE82AB9C9DF69EE86D2BC522363A0DABC521979B0DEADA1DBF9A42D5C4484E0ABCD06BFA53DDEF3C1B20EE3FD59D7C25E41D2B669E1EF16E6F52C3164DF4FB7930E9E4E58857B6AC7D5F42D69F6D187763CF1D5503400487F55BA57E31CC7A7135C886EFB4318AED6A1E012D9E6832A907600A918130C46DC778F971AD0038092999A333CB8B7A1A1DB93D7140003C2A4ECEA9F98D0ACC0A8291CDCEC97DCF8EC9B55A7F88A46B4DB5A851F44182E1C68A007E5E0DD9020BFD64B645036C7A"
		"4E677D2C38532A3A23BA4442CAF53EA63BB454329B7624C8917BDD64B1C0FD4CB38E8C334C701C3ACDAD0657FCCFEC719B1F5C3E4E46041F388147FB4CFDB477A52471F7A9A96910B855322EDB6340D8A00EF092350511E30ABEC1FFF9E3A26E7FB29F8C183023C3587E38DA0077D9B4763E4E4B94B2BBC194C6651E77CAF992EEAAC0232A281BF6B3A739C1226116820AE8DB5847A67CBEF9C9091B462D538CD72B03746AE77F5E62292C311562A846505DC82DB854338AE49F5235C95B91178CCF2DD5CACEF403EC9D1810C6272B045B3B71F9DC6B80D63FDD4A8E9ADB1E6962A69526D43161C1A41D570D7938DAD4A40E329CD0E40E65FFFFFFFFFFFFFFFF"_s, 16));
	$assignStatic(PredefinedDHParameterSpecs::p8192, $new($BigInteger, "FFFFFFFFFFFFFFFFADF85458A2BB4A9AAFDC5620273D3CF1D8B9C583CE2D3695A9E13641146433FBCC939DCE249B3EF97D2FE363630C75D8F681B202AEC4617AD3DF1ED5D5FD65612433F51F5F066ED0856365553DED1AF3B557135E7F57C935984F0C70E0E68B77E2A689DAF3EFE8721DF158A136ADE73530ACCA4F483A797ABC0AB182B324FB61D108A94BB2C8E3FBB96ADAB760D7F4681D4F42A3DE394DF4AE56EDE76372BB190B07A7C8EE0A6D709E02FCE1CDF7E2ECC03404CD28342F619172FE9CE98583FF8E4F1232EEF28183C3FE3B1B4C6FAD733BB5FCBC2EC22005C58EF1837D1683B2C6F34A26C1B2EFFA886B4238611FCFDCDE355B3B6519035BBC34F4DEF99C023861B46FC9D6E6C9077AD91D2691F7F7EE598CB0FAC186D91CAEFE130985139270B4130C93BC437944F4FD4452E2D74DD364F2E21E71F54BFF5CAE82AB9C9DF69EE86D2BC522363A0DABC521979B0DEADA1DBF9A42D5C4484E0ABCD06BFA53DDEF3C1B20EE3FD59D7C25E41D2B669E1EF16E6F52C3164DF4FB7930E9E4E58857B6AC7D5F42D69F6D187763CF1D5503400487F55BA57E31CC7A7135C886EFB4318AED6A1E012D9E6832A907600A918130C46DC778F971AD0038092999A333CB8B7A1A1DB93D7140003C2A4ECEA9F98D0ACC0A8291CDCEC97DCF8EC9B55A7F88A46B4DB5A851F44182E1C68A007E5E0DD9020BFD64B645036C7A"
		"4E677D2C38532A3A23BA4442CAF53EA63BB454329B7624C8917BDD64B1C0FD4CB38E8C334C701C3ACDAD0657FCCFEC719B1F5C3E4E46041F388147FB4CFDB477A52471F7A9A96910B855322EDB6340D8A00EF092350511E30ABEC1FFF9E3A26E7FB29F8C183023C3587E38DA0077D9B4763E4E4B94B2BBC194C6651E77CAF992EEAAC0232A281BF6B3A739C1226116820AE8DB5847A67CBEF9C9091B462D538CD72B03746AE77F5E62292C311562A846505DC82DB854338AE49F5235C95B91178CCF2DD5CACEF403EC9D1810C6272B045B3B71F9DC6B80D63FDD4A8E9ADB1E6962A69526D43161C1A41D570D7938DAD4A40E329CCFF46AAA36AD004CF600C8381E425A31D951AE64FDB23FCEC9509D43687FEB69EDD1CC5E0B8CC3BDF64B10EF86B63142A3AB8829555B2F747C932665CB2C0F1CC01BD70229388839D2AF05E454504AC78B7582822846C0BA35C35F5C59160CC046FD8251541FC68C9C86B022BB7099876A460E7451A8A93109703FEE1C217E6C3826E52C51AA691E0E423CFC99E9E31650C1217B624816CDAD9A95F9D5B8019488D9C0A0A1FE3075A577E23183F81D4A3F2FA4571EFC8CE0BA8A4FE8B6855DFE72B0A66EDED2FBABFBE58A30FAFABE1C5D71A87E2F741EF8C1FE86FEA6BBFDE530677F0D97D11D49F7A8443D0822E506A9F4614E011E2A94838FF88CD68C8BB7C5C6424CFFFFFFFFFFFFFFFF"_s, 16));
	$assignStatic(PredefinedDHParameterSpecs::supportedPrimes, $new($BigIntegerArray, {
		PredefinedDHParameterSpecs::p512,
		PredefinedDHParameterSpecs::p768,
		PredefinedDHParameterSpecs::p1024,
		PredefinedDHParameterSpecs::p1536,
		PredefinedDHParameterSpecs::p2048,
		PredefinedDHParameterSpecs::p3072,
		PredefinedDHParameterSpecs::p4096,
		PredefinedDHParameterSpecs::p6144,
		PredefinedDHParameterSpecs::p8192
	}));
	$assignStatic(PredefinedDHParameterSpecs::ffdhePrimes, $new($BigIntegerArray, {
		PredefinedDHParameterSpecs::p2048,
		PredefinedDHParameterSpecs::p3072,
		PredefinedDHParameterSpecs::p4096,
		PredefinedDHParameterSpecs::p6144,
		PredefinedDHParameterSpecs::p8192
	}));
	$assignStatic(PredefinedDHParameterSpecs::spacesPattern, $Pattern::compile("\\s+"_s));
	$assignStatic(PredefinedDHParameterSpecs::syntaxPattern, $Pattern::compile("(\\{[0-9A-Fa-f]+,[0-9A-Fa-f]+\\})(,\\{[0-9A-Fa-f]+,[0-9A-Fa-f]+\\})*"_s));
	$assignStatic(PredefinedDHParameterSpecs::paramsPattern, $Pattern::compile("\\{([0-9A-Fa-f]+),([0-9A-Fa-f]+)\\}"_s));
	{
		$var($String, property, $cast($String, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($PredefinedDHParameterSpecs$1)))));
		if (property != nullptr && !property->isEmpty()) {
			bool var$1 = property->length() >= 2;
			bool var$0 = var$1 && property->charAt(0) == u'\"';
			if (var$0 && property->charAt(property->length() - 1) == u'\"') {
				$assign(property, property->substring(1, property->length() - 1));
			}
			$assign(property, property->trim());
		}
		if (property != nullptr && !property->isEmpty()) {
			$var($Matcher, spacesMatcher, $nc(PredefinedDHParameterSpecs::spacesPattern)->matcher(property));
			$assign(property, $nc(spacesMatcher)->replaceAll(""_s));
			$init($SSLLogger);
			if ($SSLLogger::isOn$ && $SSLLogger::isOn("sslctx"_s)) {
				$SSLLogger::fine($$str({"The Security Property "_s, PredefinedDHParameterSpecs::PROPERTY_NAME, ": "_s, property}), $$new($ObjectArray, 0));
			}
		}
		$var($Map, defaultParams, $new($HashMap));
		if (property != nullptr && !property->isEmpty()) {
			$var($Matcher, syntaxMatcher, $nc(PredefinedDHParameterSpecs::syntaxPattern)->matcher(property));
			if ($nc(syntaxMatcher)->matches()) {
				$var($Matcher, paramsFinder, $nc(PredefinedDHParameterSpecs::paramsPattern)->matcher(property));
				while ($nc(paramsFinder)->find()) {
					$var($String, primeModulus, paramsFinder->group(1));
					$var($BigInteger, p, $new($BigInteger, primeModulus, 16));
					if (!p->isProbablePrime(PredefinedDHParameterSpecs::PRIME_CERTAINTY)) {
						$init($SSLLogger);
						if ($SSLLogger::isOn$ && $SSLLogger::isOn("sslctx"_s)) {
							$SSLLogger::fine($$str({"Prime modulus p in Security Property, "_s, PredefinedDHParameterSpecs::PROPERTY_NAME, ", is not a prime: "_s, primeModulus}), $$new($ObjectArray, 0));
						}
						continue;
					}
					$var($String, baseGenerator, paramsFinder->group(2));
					$var($BigInteger, g, $new($BigInteger, baseGenerator, 16));
					$var($DHParameterSpec, spec, $new($DHParameterSpec, p, g));
					int32_t primeLen = p->bitLength();
					defaultParams->put($($Integer::valueOf(primeLen)), spec);
				}
			} else {
				$init($SSLLogger);
				if ($SSLLogger::isOn$ && $SSLLogger::isOn("sslctx"_s)) {
					$SSLLogger::fine($$str({"Invalid Security Property, "_s, PredefinedDHParameterSpecs::PROPERTY_NAME, ", definition"_s}), $$new($ObjectArray, 0));
				}
			}
		}
		$var($Map, tempFFDHEs, $new($HashMap));
		{
			$var($BigIntegerArray, arr$, PredefinedDHParameterSpecs::ffdhePrimes);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($BigInteger, p, arr$->get(i$));
				{
					int32_t primeLen = $nc(p)->bitLength();
					$var($DHParameterSpec, dhps, $new($DHParameterSpec, p, $BigInteger::TWO));
					tempFFDHEs->put($($Integer::valueOf(primeLen)), dhps);
					defaultParams->putIfAbsent($($Integer::valueOf(primeLen)), dhps);
				}
			}
		}
		{
			$var($BigIntegerArray, arr$, PredefinedDHParameterSpecs::supportedPrimes);
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($BigInteger, p, arr$->get(i$));
				{
					int32_t primeLen = $nc(p)->bitLength();
					if (defaultParams->get($($Integer::valueOf(primeLen))) == nullptr) {
						$var($Object, var$2, $of($Integer::valueOf(primeLen)));
						defaultParams->put(var$2, $$new($DHParameterSpec, p, $BigInteger::TWO));
					}
				}
			}
		}
		$assignStatic(PredefinedDHParameterSpecs::ffdheParams, $Collections::unmodifiableMap(tempFFDHEs));
		$assignStatic(PredefinedDHParameterSpecs::definedParams, $Collections::unmodifiableMap(defaultParams));
	}
}

PredefinedDHParameterSpecs::PredefinedDHParameterSpecs() {
}

$Class* PredefinedDHParameterSpecs::load$($String* name, bool initialize) {
	$loadClass(PredefinedDHParameterSpecs, name, initialize, &_PredefinedDHParameterSpecs_ClassInfo_, clinit$PredefinedDHParameterSpecs, allocate$PredefinedDHParameterSpecs);
	return class$;
}

$Class* PredefinedDHParameterSpecs::class$ = nullptr;

		} // ssl
	} // security
} // sun