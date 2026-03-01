#include <sun/security/provider/SunEntries.h>

#include <java/io/File.h>
#include <java/net/URI.h>
#include <java/net/URISyntaxException.h>
#include <java/net/URL.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/Provider$Service.h>
#include <java/security/Provider.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedHashSet.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <jdk/internal/util/StaticProperty.h>
#include <sun/security/action/GetPropertyAction.h>
#include <sun/security/provider/NativePRNG$Blocking.h>
#include <sun/security/provider/NativePRNG$NonBlocking.h>
#include <sun/security/provider/NativePRNG.h>
#include <sun/security/provider/SunEntries$1.h>
#include <sun/security/util/SecurityProviderConstants.h>
#include <jcpp.h>

#undef DEF_SECURE_RANDOM_ALGO
#undef PROP_EGD
#undef PROP_RNDSOURCE
#undef URL_DEV_RANDOM
#undef URL_DEV_URANDOM

using $File = ::java::io::File;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $URI = ::java::net::URI;
using $URISyntaxException = ::java::net::URISyntaxException;
using $URL = ::java::net::URL;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Provider = ::java::security::Provider;
using $Provider$Service = ::java::security::Provider$Service;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $LinkedHashSet = ::java::util::LinkedHashSet;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $StaticProperty = ::jdk::internal::util::StaticProperty;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;
using $NativePRNG = ::sun::security::provider::NativePRNG;
using $NativePRNG$Blocking = ::sun::security::provider::NativePRNG$Blocking;
using $NativePRNG$NonBlocking = ::sun::security::provider::NativePRNG$NonBlocking;
using $SunEntries$1 = ::sun::security::provider::SunEntries$1;
using $SecurityProviderConstants = ::sun::security::util::SecurityProviderConstants;

namespace sun {
	namespace security {
		namespace provider {

$FieldInfo _SunEntries_FieldInfo_[] = {
	{"DEF_SECURE_RANDOM_ALGO", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(SunEntries, DEF_SECURE_RANDOM_ALGO)},
	{"services", "Ljava/util/LinkedHashSet;", "Ljava/util/LinkedHashSet<Ljava/security/Provider$Service;>;", $PRIVATE, $field(SunEntries, services)},
	{"PROP_EGD", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SunEntries, PROP_EGD)},
	{"PROP_RNDSOURCE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SunEntries, PROP_RNDSOURCE)},
	{"useLegacyDSA", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SunEntries, useLegacyDSA)},
	{"URL_DEV_RANDOM", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(SunEntries, URL_DEV_RANDOM)},
	{"URL_DEV_URANDOM", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(SunEntries, URL_DEV_URANDOM)},
	{"seedSource", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SunEntries, seedSource)},
	{}
};

$MethodInfo _SunEntries_MethodInfo_[] = {
	{"<init>", "(Ljava/security/Provider;)V", nullptr, 0, $method(SunEntries, init$, void, $Provider*)},
	{"add", "(Ljava/security/Provider;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PRIVATE, $method(SunEntries, add, void, $Provider*, $String*, $String*, $String*)},
	{"add", "(Ljava/security/Provider;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/util/HashMap;)V", "(Ljava/security/Provider;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/util/HashMap<Ljava/lang/String;Ljava/lang/String;>;)V", $PRIVATE, $method(SunEntries, add, void, $Provider*, $String*, $String*, $String*, $HashMap*)},
	{"addWithAlias", "(Ljava/security/Provider;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/util/HashMap;)V", "(Ljava/security/Provider;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/util/HashMap<Ljava/lang/String;Ljava/lang/String;>;)V", $PRIVATE, $method(SunEntries, addWithAlias, void, $Provider*, $String*, $String*, $String*, $HashMap*)},
	{"getDeviceFile", "(Ljava/net/URL;)Ljava/io/File;", nullptr, $STATIC, $staticMethod(SunEntries, getDeviceFile, $File*, $URL*), "java.io.IOException"},
	{"getSeedSource", "()Ljava/lang/String;", nullptr, $STATIC, $staticMethod(SunEntries, getSeedSource, $String*)},
	{"iterator", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<Ljava/security/Provider$Service;>;", 0, $method(SunEntries, iterator, $Iterator*)},
	{}
};

$InnerClassInfo _SunEntries_InnerClassesInfo_[] = {
	{"sun.security.provider.SunEntries$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _SunEntries_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.provider.SunEntries",
	"java.lang.Object",
	nullptr,
	_SunEntries_FieldInfo_,
	_SunEntries_MethodInfo_,
	nullptr,
	nullptr,
	_SunEntries_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.provider.SunEntries$1"
};

$Object* allocate$SunEntries($Class* clazz) {
	return $of($alloc(SunEntries));
}

$String* SunEntries::DEF_SECURE_RANDOM_ALGO = nullptr;
$String* SunEntries::PROP_EGD = nullptr;
$String* SunEntries::PROP_RNDSOURCE = nullptr;
bool SunEntries::useLegacyDSA = false;
$String* SunEntries::URL_DEV_RANDOM = nullptr;
$String* SunEntries::URL_DEV_URANDOM = nullptr;
$String* SunEntries::seedSource = nullptr;

void SunEntries::init$($Provider* p) {
	$useLocalCurrentObjectStackCache();
	$set(this, services, $new($LinkedHashSet, 50, 0.9f));
	$var($HashMap, attrs, $new($HashMap, 3));
	attrs->put("ThreadSafe"_s, "true"_s);
	if ($NativePRNG::isAvailable()) {
		add(p, "SecureRandom"_s, "NativePRNG"_s, "sun.security.provider.NativePRNG"_s, attrs);
	}
	if ($NativePRNG$Blocking::isAvailable()) {
		add(p, "SecureRandom"_s, "NativePRNGBlocking"_s, "sun.security.provider.NativePRNG$Blocking"_s, attrs);
	}
	if ($NativePRNG$NonBlocking::isAvailable()) {
		add(p, "SecureRandom"_s, "NativePRNGNonBlocking"_s, "sun.security.provider.NativePRNG$NonBlocking"_s, attrs);
	}
	attrs->put("ImplementedIn"_s, "Software"_s);
	add(p, "SecureRandom"_s, "DRBG"_s, "sun.security.provider.DRBG"_s, attrs);
	add(p, "SecureRandom"_s, "SHA1PRNG"_s, "sun.security.provider.SecureRandom"_s, attrs);
	attrs->clear();
	$var($String, dsaKeyClasses, "java.security.interfaces.DSAPublicKey|java.security.interfaces.DSAPrivateKey"_s);
	attrs->put("SupportedKeyClasses"_s, dsaKeyClasses);
	attrs->put("ImplementedIn"_s, "Software"_s);
	attrs->put("KeySize"_s, "1024"_s);
	addWithAlias(p, "Signature"_s, "SHA1withDSA"_s, "sun.security.provider.DSA$SHA1withDSA"_s, attrs);
	addWithAlias(p, "Signature"_s, "NONEwithDSA"_s, "sun.security.provider.DSA$RawDSA"_s, attrs);
	attrs->put("KeySize"_s, "2048"_s);
	addWithAlias(p, "Signature"_s, "SHA224withDSA"_s, "sun.security.provider.DSA$SHA224withDSA"_s, attrs);
	addWithAlias(p, "Signature"_s, "SHA256withDSA"_s, "sun.security.provider.DSA$SHA256withDSA"_s, attrs);
	addWithAlias(p, "Signature"_s, "SHA3-224withDSA"_s, "sun.security.provider.DSA$SHA3_224withDSA"_s, attrs);
	addWithAlias(p, "Signature"_s, "SHA3-256withDSA"_s, "sun.security.provider.DSA$SHA3_256withDSA"_s, attrs);
	attrs->put("KeySize"_s, "3072"_s);
	addWithAlias(p, "Signature"_s, "SHA384withDSA"_s, "sun.security.provider.DSA$SHA384withDSA"_s, attrs);
	addWithAlias(p, "Signature"_s, "SHA512withDSA"_s, "sun.security.provider.DSA$SHA512withDSA"_s, attrs);
	addWithAlias(p, "Signature"_s, "SHA3-384withDSA"_s, "sun.security.provider.DSA$SHA3_384withDSA"_s, attrs);
	addWithAlias(p, "Signature"_s, "SHA3-512withDSA"_s, "sun.security.provider.DSA$SHA3_512withDSA"_s, attrs);
	attrs->remove("KeySize"_s);
	add(p, "Signature"_s, "SHA1withDSAinP1363Format"_s, "sun.security.provider.DSA$SHA1withDSAinP1363Format"_s);
	add(p, "Signature"_s, "NONEwithDSAinP1363Format"_s, "sun.security.provider.DSA$RawDSAinP1363Format"_s);
	add(p, "Signature"_s, "SHA224withDSAinP1363Format"_s, "sun.security.provider.DSA$SHA224withDSAinP1363Format"_s);
	add(p, "Signature"_s, "SHA256withDSAinP1363Format"_s, "sun.security.provider.DSA$SHA256withDSAinP1363Format"_s);
	add(p, "Signature"_s, "SHA384withDSAinP1363Format"_s, "sun.security.provider.DSA$SHA384withDSAinP1363Format"_s);
	add(p, "Signature"_s, "SHA512withDSAinP1363Format"_s, "sun.security.provider.DSA$SHA512withDSAinP1363Format"_s);
	add(p, "Signature"_s, "SHA3-224withDSAinP1363Format"_s, "sun.security.provider.DSA$SHA3_224withDSAinP1363Format"_s);
	add(p, "Signature"_s, "SHA3-256withDSAinP1363Format"_s, "sun.security.provider.DSA$SHA3_256withDSAinP1363Format"_s);
	add(p, "Signature"_s, "SHA3-384withDSAinP1363Format"_s, "sun.security.provider.DSA$SHA3_384withDSAinP1363Format"_s);
	add(p, "Signature"_s, "SHA3-512withDSAinP1363Format"_s, "sun.security.provider.DSA$SHA3_512withDSAinP1363Format"_s);
	attrs->clear();
	attrs->put("ImplementedIn"_s, "Software"_s);
	attrs->put("KeySize"_s, "2048"_s);
	$var($String, dsaKPGImplClass, "sun.security.provider.DSAKeyPairGenerator$"_s);
	$plusAssign(dsaKPGImplClass, (SunEntries::useLegacyDSA ? "Legacy"_s : "Current"_s));
	addWithAlias(p, "KeyPairGenerator"_s, "DSA"_s, dsaKPGImplClass, attrs);
	addWithAlias(p, "AlgorithmParameterGenerator"_s, "DSA"_s, "sun.security.provider.DSAParameterGenerator"_s, attrs);
	attrs->remove("KeySize"_s);
	addWithAlias(p, "AlgorithmParameters"_s, "DSA"_s, "sun.security.provider.DSAParameters"_s, attrs);
	addWithAlias(p, "KeyFactory"_s, "DSA"_s, "sun.security.provider.DSAKeyFactory"_s, attrs);
	add(p, "MessageDigest"_s, "MD2"_s, "sun.security.provider.MD2"_s, attrs);
	add(p, "MessageDigest"_s, "MD5"_s, "sun.security.provider.MD5"_s, attrs);
	addWithAlias(p, "MessageDigest"_s, "SHA-1"_s, "sun.security.provider.SHA"_s, attrs);
	addWithAlias(p, "MessageDigest"_s, "SHA-224"_s, "sun.security.provider.SHA2$SHA224"_s, attrs);
	addWithAlias(p, "MessageDigest"_s, "SHA-256"_s, "sun.security.provider.SHA2$SHA256"_s, attrs);
	addWithAlias(p, "MessageDigest"_s, "SHA-384"_s, "sun.security.provider.SHA5$SHA384"_s, attrs);
	addWithAlias(p, "MessageDigest"_s, "SHA-512"_s, "sun.security.provider.SHA5$SHA512"_s, attrs);
	addWithAlias(p, "MessageDigest"_s, "SHA-512/224"_s, "sun.security.provider.SHA5$SHA512_224"_s, attrs);
	addWithAlias(p, "MessageDigest"_s, "SHA-512/256"_s, "sun.security.provider.SHA5$SHA512_256"_s, attrs);
	addWithAlias(p, "MessageDigest"_s, "SHA3-224"_s, "sun.security.provider.SHA3$SHA224"_s, attrs);
	addWithAlias(p, "MessageDigest"_s, "SHA3-256"_s, "sun.security.provider.SHA3$SHA256"_s, attrs);
	addWithAlias(p, "MessageDigest"_s, "SHA3-384"_s, "sun.security.provider.SHA3$SHA384"_s, attrs);
	addWithAlias(p, "MessageDigest"_s, "SHA3-512"_s, "sun.security.provider.SHA3$SHA512"_s, attrs);
	addWithAlias(p, "CertificateFactory"_s, "X.509"_s, "sun.security.provider.X509Factory"_s, attrs);
	add(p, "KeyStore"_s, "PKCS12"_s, "sun.security.pkcs12.PKCS12KeyStore$DualFormatPKCS12"_s);
	add(p, "KeyStore"_s, "JKS"_s, "sun.security.provider.JavaKeyStore$DualFormatJKS"_s, attrs);
	add(p, "KeyStore"_s, "CaseExactJKS"_s, "sun.security.provider.JavaKeyStore$CaseExactJKS"_s, attrs);
	add(p, "KeyStore"_s, "DKS"_s, "sun.security.provider.DomainKeyStore$DKS"_s, attrs);
	add(p, "CertStore"_s, "Collection"_s, "sun.security.provider.certpath.CollectionCertStore"_s, attrs);
	add(p, "CertStore"_s, "com.sun.security.IndexedCollection"_s, "sun.security.provider.certpath.IndexedCollectionCertStore"_s, attrs);
	add(p, "Policy"_s, "JavaPolicy"_s, "sun.security.provider.PolicySpiFile"_s);
	add(p, "Configuration"_s, "JavaLoginConfig"_s, "sun.security.provider.ConfigFile$Spi"_s);
	attrs->clear();
	attrs->put("ValidationAlgorithm"_s, "RFC5280"_s);
	attrs->put("ImplementedIn"_s, "Software"_s);
	add(p, "CertPathBuilder"_s, "PKIX"_s, "sun.security.provider.certpath.SunCertPathBuilder"_s, attrs);
	add(p, "CertPathValidator"_s, "PKIX"_s, "sun.security.provider.certpath.PKIXCertPathValidator"_s, attrs);
}

$Iterator* SunEntries::iterator() {
	return $nc(this->services)->iterator();
}

void SunEntries::add($Provider* p, $String* type, $String* algo, $String* cn) {
	$nc(this->services)->add($$new($Provider$Service, p, type, algo, cn, nullptr, nullptr));
}

void SunEntries::add($Provider* p, $String* type, $String* algo, $String* cn, $HashMap* attrs) {
	$nc(this->services)->add($$new($Provider$Service, p, type, algo, cn, nullptr, attrs));
}

void SunEntries::addWithAlias($Provider* p, $String* type, $String* algo, $String* cn, $HashMap* attrs) {
	$useLocalCurrentObjectStackCache();
	$nc(this->services)->add($$new($Provider$Service, p, type, algo, cn, $($SecurityProviderConstants::getAliases(algo)), attrs));
}

$String* SunEntries::getSeedSource() {
	$init(SunEntries);
	return SunEntries::seedSource;
}

$File* SunEntries::getDeviceFile($URL* device) {
	$init(SunEntries);
	$useLocalCurrentObjectStackCache();
	try {
		$var($URI, deviceURI, $nc(device)->toURI());
		if ($nc(deviceURI)->isOpaque()) {
			$var($URI, localDir, $$new($File, $($StaticProperty::userDir()))->toURI());
			$var($String, var$0, $($nc(localDir)->toString()));
			$var($String, uriPath, $concat(var$0, $($nc($(deviceURI->toString()))->substring(5))));
			return $new($File, $($URI::create(uriPath)));
		} else {
			return $new($File, deviceURI);
		}
	} catch ($URISyntaxException& use) {
		return $new($File, $($nc(device)->getPath()));
	}
	$shouldNotReachHere();
}

void clinit$SunEntries($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(SunEntries::PROP_EGD, "java.security.egd"_s);
	$assignStatic(SunEntries::PROP_RNDSOURCE, "securerandom.source"_s);
	$assignStatic(SunEntries::URL_DEV_RANDOM, "file:/dev/random"_s);
	$assignStatic(SunEntries::URL_DEV_URANDOM, "file:/dev/urandom"_s);
	$beforeCallerSensitive();
	SunEntries::useLegacyDSA = $Boolean::parseBoolean($($GetPropertyAction::privilegedGetProperty("jdk.security.legacyDSAKeyPairGenerator"_s)));
	$assignStatic(SunEntries::seedSource, $cast($String, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($SunEntries$1)))));
	{
		bool var$0 = $NativePRNG::isAvailable();
		if (var$0) {
			bool var$1 = $nc(SunEntries::seedSource)->equals(SunEntries::URL_DEV_URANDOM);
			var$0 = (var$1 || $nc(SunEntries::seedSource)->equals(SunEntries::URL_DEV_RANDOM));
		}
		$assignStatic(SunEntries::DEF_SECURE_RANDOM_ALGO, var$0 ? "NativePRNG"_s : "DRBG"_s);
	}
}

SunEntries::SunEntries() {
}

$Class* SunEntries::load$($String* name, bool initialize) {
	$loadClass(SunEntries, name, initialize, &_SunEntries_ClassInfo_, clinit$SunEntries, allocate$SunEntries);
	return class$;
}

$Class* SunEntries::class$ = nullptr;

		} // provider
	} // security
} // sun