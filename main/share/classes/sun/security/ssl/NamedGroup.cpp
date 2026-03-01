#include <sun/security/ssl/NamedGroup.h>

#include <java/lang/Enum.h>
#include <java/math/BigInteger.h>
#include <java/security/AlgorithmConstraints.h>
#include <java/security/AlgorithmParameters.h>
#include <java/security/CryptoPrimitive.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/SecureRandom.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/security/spec/ECParameterSpec.h>
#include <java/security/spec/InvalidParameterSpecException.h>
#include <java/security/spec/NamedParameterSpec.h>
#include <java/util/Collections.h>
#include <java/util/EnumSet.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <javax/crypto/KeyAgreement.h>
#include <javax/crypto/spec/DHParameterSpec.h>
#include <sun/security/ssl/CipherSuite$KeyExchange.h>
#include <sun/security/ssl/CipherSuite.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/JsseJce.h>
#include <sun/security/ssl/NamedGroup$ExceptionSupplier.h>
#include <sun/security/ssl/NamedGroup$NamedGroupSpec.h>
#include <sun/security/ssl/NamedGroupPossession.h>
#include <sun/security/ssl/PredefinedDHParameterSpecs.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/SSLCredentials.h>
#include <sun/security/ssl/SSLKeyDerivation.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/SSLPossession.h>
#include <sun/security/util/CurveDB.h>
#include <sun/security/util/NamedCurve.h>
#include <jcpp.h>

#undef ARBITRARY_CHAR2
#undef ARBITRARY_PRIME
#undef KEY_AGREEMENT
#undef KEY_AGREEMENT_PRIMITIVE_SET
#undef NAMED_GROUP_ARBITRARY
#undef NAMED_GROUP_ECDHE
#undef NAMED_GROUP_FFDHE
#undef NAMED_GROUP_XDH
#undef PROTOCOLS_TO_12
#undef PROTOCOLS_TO_13

using $NamedGroupArray = $Array<::sun::security::ssl::NamedGroup>;
using $ProtocolVersionArray = $Array<::sun::security::ssl::ProtocolVersion>;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $BigInteger = ::java::math::BigInteger;
using $AlgorithmConstraints = ::java::security::AlgorithmConstraints;
using $AlgorithmParameters = ::java::security::AlgorithmParameters;
using $CryptoPrimitive = ::java::security::CryptoPrimitive;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $SecureRandom = ::java::security::SecureRandom;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $ECParameterSpec = ::java::security::spec::ECParameterSpec;
using $InvalidParameterSpecException = ::java::security::spec::InvalidParameterSpecException;
using $NamedParameterSpec = ::java::security::spec::NamedParameterSpec;
using $Collections = ::java::util::Collections;
using $EnumSet = ::java::util::EnumSet;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $KeyAgreement = ::javax::crypto::KeyAgreement;
using $DHParameterSpec = ::javax::crypto::spec::DHParameterSpec;
using $CipherSuite = ::sun::security::ssl::CipherSuite;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $JsseJce = ::sun::security::ssl::JsseJce;
using $NamedGroup$ExceptionSupplier = ::sun::security::ssl::NamedGroup$ExceptionSupplier;
using $NamedGroup$NamedGroupSpec = ::sun::security::ssl::NamedGroup$NamedGroupSpec;
using $NamedGroupPossession = ::sun::security::ssl::NamedGroupPossession;
using $PredefinedDHParameterSpecs = ::sun::security::ssl::PredefinedDHParameterSpecs;
using $ProtocolVersion = ::sun::security::ssl::ProtocolVersion;
using $SSLCredentials = ::sun::security::ssl::SSLCredentials;
using $SSLKeyDerivation = ::sun::security::ssl::SSLKeyDerivation;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $SSLPossession = ::sun::security::ssl::SSLPossession;
using $CurveDB = ::sun::security::util::CurveDB;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _NamedGroup_FieldInfo_[] = {
	{"SECT163_K1", "Lsun/security/ssl/NamedGroup;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(NamedGroup, SECT163_K1)},
	{"SECT163_R1", "Lsun/security/ssl/NamedGroup;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(NamedGroup, SECT163_R1)},
	{"SECT163_R2", "Lsun/security/ssl/NamedGroup;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(NamedGroup, SECT163_R2)},
	{"SECT193_R1", "Lsun/security/ssl/NamedGroup;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(NamedGroup, SECT193_R1)},
	{"SECT193_R2", "Lsun/security/ssl/NamedGroup;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(NamedGroup, SECT193_R2)},
	{"SECT233_K1", "Lsun/security/ssl/NamedGroup;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(NamedGroup, SECT233_K1)},
	{"SECT233_R1", "Lsun/security/ssl/NamedGroup;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(NamedGroup, SECT233_R1)},
	{"SECT239_K1", "Lsun/security/ssl/NamedGroup;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(NamedGroup, SECT239_K1)},
	{"SECT283_K1", "Lsun/security/ssl/NamedGroup;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(NamedGroup, SECT283_K1)},
	{"SECT283_R1", "Lsun/security/ssl/NamedGroup;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(NamedGroup, SECT283_R1)},
	{"SECT409_K1", "Lsun/security/ssl/NamedGroup;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(NamedGroup, SECT409_K1)},
	{"SECT409_R1", "Lsun/security/ssl/NamedGroup;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(NamedGroup, SECT409_R1)},
	{"SECT571_K1", "Lsun/security/ssl/NamedGroup;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(NamedGroup, SECT571_K1)},
	{"SECT571_R1", "Lsun/security/ssl/NamedGroup;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(NamedGroup, SECT571_R1)},
	{"SECP160_K1", "Lsun/security/ssl/NamedGroup;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(NamedGroup, SECP160_K1)},
	{"SECP160_R1", "Lsun/security/ssl/NamedGroup;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(NamedGroup, SECP160_R1)},
	{"SECP160_R2", "Lsun/security/ssl/NamedGroup;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(NamedGroup, SECP160_R2)},
	{"SECP192_K1", "Lsun/security/ssl/NamedGroup;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(NamedGroup, SECP192_K1)},
	{"SECP192_R1", "Lsun/security/ssl/NamedGroup;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(NamedGroup, SECP192_R1)},
	{"SECP224_K1", "Lsun/security/ssl/NamedGroup;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(NamedGroup, SECP224_K1)},
	{"SECP224_R1", "Lsun/security/ssl/NamedGroup;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(NamedGroup, SECP224_R1)},
	{"SECP256_K1", "Lsun/security/ssl/NamedGroup;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(NamedGroup, SECP256_K1)},
	{"SECP256_R1", "Lsun/security/ssl/NamedGroup;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(NamedGroup, SECP256_R1)},
	{"SECP384_R1", "Lsun/security/ssl/NamedGroup;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(NamedGroup, SECP384_R1)},
	{"SECP521_R1", "Lsun/security/ssl/NamedGroup;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(NamedGroup, SECP521_R1)},
	{"X25519", "Lsun/security/ssl/NamedGroup;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(NamedGroup, X25519)},
	{"X448", "Lsun/security/ssl/NamedGroup;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(NamedGroup, X448)},
	{"FFDHE_2048", "Lsun/security/ssl/NamedGroup;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(NamedGroup, FFDHE_2048)},
	{"FFDHE_3072", "Lsun/security/ssl/NamedGroup;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(NamedGroup, FFDHE_3072)},
	{"FFDHE_4096", "Lsun/security/ssl/NamedGroup;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(NamedGroup, FFDHE_4096)},
	{"FFDHE_6144", "Lsun/security/ssl/NamedGroup;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(NamedGroup, FFDHE_6144)},
	{"FFDHE_8192", "Lsun/security/ssl/NamedGroup;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(NamedGroup, FFDHE_8192)},
	{"ARBITRARY_PRIME", "Lsun/security/ssl/NamedGroup;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(NamedGroup, ARBITRARY_PRIME)},
	{"ARBITRARY_CHAR2", "Lsun/security/ssl/NamedGroup;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(NamedGroup, ARBITRARY_CHAR2)},
	{"$VALUES", "[Lsun/security/ssl/NamedGroup;", nullptr, $PRIVATE | $STATIC | $FINAL | $SYNTHETIC, $staticField(NamedGroup, $VALUES)},
	{"id", "I", nullptr, $FINAL, $field(NamedGroup, id)},
	{"name", "Ljava/lang/String;", nullptr, $FINAL, $field(NamedGroup, name$)},
	{"spec", "Lsun/security/ssl/NamedGroup$NamedGroupSpec;", nullptr, $FINAL, $field(NamedGroup, spec)},
	{"supportedProtocols", "[Lsun/security/ssl/ProtocolVersion;", nullptr, $FINAL, $field(NamedGroup, supportedProtocols)},
	{"algorithm", "Ljava/lang/String;", nullptr, $FINAL, $field(NamedGroup, algorithm)},
	{"keAlgParamSpec", "Ljava/security/spec/AlgorithmParameterSpec;", nullptr, $FINAL, $field(NamedGroup, keAlgParamSpec)},
	{"keAlgParams", "Ljava/security/AlgorithmParameters;", nullptr, $FINAL, $field(NamedGroup, keAlgParams)},
	{"isAvailable", "Z", nullptr, $FINAL, $field(NamedGroup, isAvailable$)},
	{"KEY_AGREEMENT_PRIMITIVE_SET", "Ljava/util/Set;", "Ljava/util/Set<Ljava/security/CryptoPrimitive;>;", $PRIVATE | $STATIC | $FINAL, $staticField(NamedGroup, KEY_AGREEMENT_PRIMITIVE_SET)},
	{}
};

$MethodInfo _NamedGroup_MethodInfo_[] = {
	{"$values", "()[Lsun/security/ssl/NamedGroup;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(NamedGroup, $values, $NamedGroupArray*)},
	{"<init>", "(Ljava/lang/String;IILjava/lang/String;Lsun/security/ssl/NamedGroup$NamedGroupSpec;[Lsun/security/ssl/ProtocolVersion;Ljava/security/spec/AlgorithmParameterSpec;)V", "(ILjava/lang/String;Lsun/security/ssl/NamedGroup$NamedGroupSpec;[Lsun/security/ssl/ProtocolVersion;Ljava/security/spec/AlgorithmParameterSpec;)V", $PRIVATE, $method(NamedGroup, init$, void, $String*, int32_t, int32_t, $String*, $NamedGroup$NamedGroupSpec*, $ProtocolVersionArray*, $AlgorithmParameterSpec*)},
	{"createKeyDerivation", "(Lsun/security/ssl/HandshakeContext;)Lsun/security/ssl/SSLKeyDerivation;", nullptr, 0, $method(NamedGroup, createKeyDerivation, $SSLKeyDerivation*, $HandshakeContext*), "java.io.IOException"},
	{"createPossession", "(Ljava/security/SecureRandom;)Lsun/security/ssl/SSLPossession;", nullptr, 0, $method(NamedGroup, createPossession, $SSLPossession*, $SecureRandom*)},
	{"decodeCredentials", "([BLjava/security/AlgorithmConstraints;Lsun/security/ssl/NamedGroup$ExceptionSupplier;)Lsun/security/ssl/SSLCredentials;", nullptr, 0, $method(NamedGroup, decodeCredentials, $SSLCredentials*, $bytes*, $AlgorithmConstraints*, $NamedGroup$ExceptionSupplier*), "java.io.IOException,java.security.GeneralSecurityException"},
	{"encodePossessionPublicKey", "(Lsun/security/ssl/NamedGroupPossession;)[B", nullptr, 0, $method(NamedGroup, encodePossessionPublicKey, $bytes*, $NamedGroupPossession*)},
	{"isAvailable", "(Ljava/util/List;)Z", "(Ljava/util/List<Lsun/security/ssl/ProtocolVersion;>;)Z", 0, $method(NamedGroup, isAvailable, bool, $List*)},
	{"isAvailable", "(Lsun/security/ssl/ProtocolVersion;)Z", nullptr, 0, $method(NamedGroup, isAvailable, bool, $ProtocolVersion*)},
	{"isPermitted", "(Ljava/security/AlgorithmConstraints;)Z", nullptr, 0, $method(NamedGroup, isPermitted, bool, $AlgorithmConstraints*)},
	{"isSupported", "(Ljava/util/List;)Z", "(Ljava/util/List<Lsun/security/ssl/CipherSuite;>;)Z", 0, $method(NamedGroup, isSupported, bool, $List*)},
	{"nameOf", "(Ljava/lang/String;)Lsun/security/ssl/NamedGroup;", nullptr, $STATIC, $staticMethod(NamedGroup, nameOf, NamedGroup*, $String*)},
	{"nameOf", "(I)Ljava/lang/String;", nullptr, $STATIC, $staticMethod(NamedGroup, nameOf, $String*, int32_t)},
	{"valueOf", "(Ljava/lang/String;)Lsun/security/ssl/NamedGroup;", nullptr, $PUBLIC | $STATIC, $staticMethod(NamedGroup, valueOf, NamedGroup*, $String*)},
	{"valueOf", "(I)Lsun/security/ssl/NamedGroup;", nullptr, $STATIC, $staticMethod(NamedGroup, valueOf, NamedGroup*, int32_t)},
	{"valueOf", "(Ljava/security/spec/ECParameterSpec;)Lsun/security/ssl/NamedGroup;", nullptr, $STATIC, $staticMethod(NamedGroup, valueOf, NamedGroup*, $ECParameterSpec*)},
	{"valueOf", "(Ljavax/crypto/spec/DHParameterSpec;)Lsun/security/ssl/NamedGroup;", nullptr, $STATIC, $staticMethod(NamedGroup, valueOf, NamedGroup*, $DHParameterSpec*)},
	{"values", "()[Lsun/security/ssl/NamedGroup;", nullptr, $PUBLIC | $STATIC, $staticMethod(NamedGroup, values, $NamedGroupArray*)},
	{}
};

$InnerClassInfo _NamedGroup_InnerClassesInfo_[] = {
	{"sun.security.ssl.NamedGroup$XDHScheme", "sun.security.ssl.NamedGroup", "XDHScheme", $PRIVATE | $STATIC},
	{"sun.security.ssl.NamedGroup$ECDHEScheme", "sun.security.ssl.NamedGroup", "ECDHEScheme", $PRIVATE | $STATIC},
	{"sun.security.ssl.NamedGroup$FFDHEScheme", "sun.security.ssl.NamedGroup", "FFDHEScheme", $PRIVATE | $STATIC},
	{"sun.security.ssl.NamedGroup$NamedGroupSpec", "sun.security.ssl.NamedGroup", "NamedGroupSpec", $STATIC | $FINAL | $ENUM},
	{"sun.security.ssl.NamedGroup$NamedGroupScheme", "sun.security.ssl.NamedGroup", "NamedGroupScheme", $PRIVATE | $STATIC | $INTERFACE | $ABSTRACT},
	{"sun.security.ssl.NamedGroup$ExceptionSupplier", "sun.security.ssl.NamedGroup", "ExceptionSupplier", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _NamedGroup_ClassInfo_ = {
	$FINAL | $ACC_SUPER | $ENUM,
	"sun.security.ssl.NamedGroup",
	"java.lang.Enum",
	nullptr,
	_NamedGroup_FieldInfo_,
	_NamedGroup_MethodInfo_,
	"Ljava/lang/Enum<Lsun/security/ssl/NamedGroup;>;",
	nullptr,
	_NamedGroup_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.ssl.NamedGroup$XDHScheme,sun.security.ssl.NamedGroup$ECDHEScheme,sun.security.ssl.NamedGroup$FFDHEScheme,sun.security.ssl.NamedGroup$NamedGroupSpec,sun.security.ssl.NamedGroup$NamedGroupScheme,sun.security.ssl.NamedGroup$ExceptionSupplier"
};

$Object* allocate$NamedGroup($Class* clazz) {
	return $of($alloc(NamedGroup));
}

NamedGroup* NamedGroup::SECT163_K1 = nullptr;
NamedGroup* NamedGroup::SECT163_R1 = nullptr;
NamedGroup* NamedGroup::SECT163_R2 = nullptr;
NamedGroup* NamedGroup::SECT193_R1 = nullptr;
NamedGroup* NamedGroup::SECT193_R2 = nullptr;
NamedGroup* NamedGroup::SECT233_K1 = nullptr;
NamedGroup* NamedGroup::SECT233_R1 = nullptr;
NamedGroup* NamedGroup::SECT239_K1 = nullptr;
NamedGroup* NamedGroup::SECT283_K1 = nullptr;
NamedGroup* NamedGroup::SECT283_R1 = nullptr;
NamedGroup* NamedGroup::SECT409_K1 = nullptr;
NamedGroup* NamedGroup::SECT409_R1 = nullptr;
NamedGroup* NamedGroup::SECT571_K1 = nullptr;
NamedGroup* NamedGroup::SECT571_R1 = nullptr;
NamedGroup* NamedGroup::SECP160_K1 = nullptr;
NamedGroup* NamedGroup::SECP160_R1 = nullptr;
NamedGroup* NamedGroup::SECP160_R2 = nullptr;
NamedGroup* NamedGroup::SECP192_K1 = nullptr;
NamedGroup* NamedGroup::SECP192_R1 = nullptr;
NamedGroup* NamedGroup::SECP224_K1 = nullptr;
NamedGroup* NamedGroup::SECP224_R1 = nullptr;
NamedGroup* NamedGroup::SECP256_K1 = nullptr;
NamedGroup* NamedGroup::SECP256_R1 = nullptr;
NamedGroup* NamedGroup::SECP384_R1 = nullptr;
NamedGroup* NamedGroup::SECP521_R1 = nullptr;
NamedGroup* NamedGroup::X25519 = nullptr;
NamedGroup* NamedGroup::X448 = nullptr;
NamedGroup* NamedGroup::FFDHE_2048 = nullptr;
NamedGroup* NamedGroup::FFDHE_3072 = nullptr;
NamedGroup* NamedGroup::FFDHE_4096 = nullptr;
NamedGroup* NamedGroup::FFDHE_6144 = nullptr;
NamedGroup* NamedGroup::FFDHE_8192 = nullptr;
NamedGroup* NamedGroup::ARBITRARY_PRIME = nullptr;
NamedGroup* NamedGroup::ARBITRARY_CHAR2 = nullptr;
$NamedGroupArray* NamedGroup::$VALUES = nullptr;
$Set* NamedGroup::KEY_AGREEMENT_PRIMITIVE_SET = nullptr;

$NamedGroupArray* NamedGroup::$values() {
	$init(NamedGroup);
	return $new($NamedGroupArray, {
		NamedGroup::SECT163_K1,
		NamedGroup::SECT163_R1,
		NamedGroup::SECT163_R2,
		NamedGroup::SECT193_R1,
		NamedGroup::SECT193_R2,
		NamedGroup::SECT233_K1,
		NamedGroup::SECT233_R1,
		NamedGroup::SECT239_K1,
		NamedGroup::SECT283_K1,
		NamedGroup::SECT283_R1,
		NamedGroup::SECT409_K1,
		NamedGroup::SECT409_R1,
		NamedGroup::SECT571_K1,
		NamedGroup::SECT571_R1,
		NamedGroup::SECP160_K1,
		NamedGroup::SECP160_R1,
		NamedGroup::SECP160_R2,
		NamedGroup::SECP192_K1,
		NamedGroup::SECP192_R1,
		NamedGroup::SECP224_K1,
		NamedGroup::SECP224_R1,
		NamedGroup::SECP256_K1,
		NamedGroup::SECP256_R1,
		NamedGroup::SECP384_R1,
		NamedGroup::SECP521_R1,
		NamedGroup::X25519,
		NamedGroup::X448,
		NamedGroup::FFDHE_2048,
		NamedGroup::FFDHE_3072,
		NamedGroup::FFDHE_4096,
		NamedGroup::FFDHE_6144,
		NamedGroup::FFDHE_8192,
		NamedGroup::ARBITRARY_PRIME,
		NamedGroup::ARBITRARY_CHAR2
	});
}

$NamedGroupArray* NamedGroup::values() {
	$init(NamedGroup);
	return $cast($NamedGroupArray, NamedGroup::$VALUES->clone());
}

NamedGroup* NamedGroup::valueOf($String* name) {
	$init(NamedGroup);
	return $cast(NamedGroup, $Enum::valueOf(NamedGroup::class$, name));
}

void NamedGroup::init$($String* $enum$name, int32_t $enum$ordinal, int32_t id, $String* name, $NamedGroup$NamedGroupSpec* namedGroupSpec, $ProtocolVersionArray* supportedProtocols, $AlgorithmParameterSpec* keAlgParamSpec) {
	$useLocalCurrentObjectStackCache();
	$Enum::init$($enum$name, $enum$ordinal);
	this->id = id;
	$set(this, name$, name);
	$set(this, spec, namedGroupSpec);
	$set(this, algorithm, $nc(namedGroupSpec)->algorithm);
	$set(this, supportedProtocols, supportedProtocols);
	$set(this, keAlgParamSpec, keAlgParamSpec);
	$var($AlgorithmParameters, algParams, nullptr);
	bool mediator = (keAlgParamSpec != nullptr);
	$init($NamedGroup$NamedGroupSpec);
	if (mediator && (namedGroupSpec == $NamedGroup$NamedGroupSpec::NAMED_GROUP_ECDHE)) {
		mediator = $JsseJce::isEcAvailable();
	}
	if (mediator) {
		try {
			$assign(algParams, $AlgorithmParameters::getInstance(namedGroupSpec->algorithm));
			$nc(algParams)->init(keAlgParamSpec);
		} catch ($InvalidParameterSpecException& exp) {
			if (namedGroupSpec != $NamedGroup$NamedGroupSpec::NAMED_GROUP_XDH) {
				mediator = false;
				$init($SSLLogger);
				if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
					$SSLLogger::warning($$str({"No AlgorithmParameters for "_s, name}), $$new($ObjectArray, {$of(exp)}));
				}
			} else {
				$assign(algParams, nullptr);
				try {
					$KeyAgreement::getInstance(name);
				} catch ($NoSuchAlgorithmException& nsae) {
					mediator = false;
					$init($SSLLogger);
					if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
						$SSLLogger::warning($$str({"No AlgorithmParameters for "_s, name}), $$new($ObjectArray, {$of(nsae)}));
					}
				}
			}
		} catch ($NoSuchAlgorithmException& exp) {
			if (namedGroupSpec != $NamedGroup$NamedGroupSpec::NAMED_GROUP_XDH) {
				mediator = false;
				$init($SSLLogger);
				if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
					$SSLLogger::warning($$str({"No AlgorithmParameters for "_s, name}), $$new($ObjectArray, {$of(exp)}));
				}
			} else {
				$assign(algParams, nullptr);
				try {
					$KeyAgreement::getInstance(name);
				} catch ($NoSuchAlgorithmException& nsae) {
					mediator = false;
					$init($SSLLogger);
					if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
						$SSLLogger::warning($$str({"No AlgorithmParameters for "_s, name}), $$new($ObjectArray, {$of(nsae)}));
					}
				}
			}
		}
	}
	this->isAvailable$ = mediator;
	$set(this, keAlgParams, mediator ? algParams : ($AlgorithmParameters*)nullptr);
}

NamedGroup* NamedGroup::valueOf(int32_t id) {
	$init(NamedGroup);
	{
		$var($NamedGroupArray, arr$, NamedGroup::values());
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			NamedGroup* group = arr$->get(i$);
			{
				if ($nc(group)->id == id) {
					return group;
				}
			}
		}
	}
	return nullptr;
}

NamedGroup* NamedGroup::valueOf($ECParameterSpec* params) {
	$init(NamedGroup);
	{
		$var($NamedGroupArray, arr$, NamedGroup::values());
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			NamedGroup* ng = arr$->get(i$);
			{
				$init($NamedGroup$NamedGroupSpec);
				if ($nc(ng)->spec == $NamedGroup$NamedGroupSpec::NAMED_GROUP_ECDHE) {
					if (($equals(params, ng->keAlgParamSpec)) || ($equals(ng->keAlgParamSpec, $CurveDB::lookup(params)))) {
						return ng;
					}
				}
			}
		}
	}
	return nullptr;
}

NamedGroup* NamedGroup::valueOf($DHParameterSpec* params) {
	$init(NamedGroup);
	$useLocalCurrentObjectStackCache();
	{
		$var($NamedGroupArray, arr$, NamedGroup::values());
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			NamedGroup* ng = arr$->get(i$);
			{
				$init($NamedGroup$NamedGroupSpec);
				if ($nc(ng)->spec != $NamedGroup$NamedGroupSpec::NAMED_GROUP_FFDHE) {
					continue;
				}
				$var($DHParameterSpec, ngParams, $cast($DHParameterSpec, $nc(ng)->keAlgParamSpec));
				bool var$0 = $nc($($nc(ngParams)->getP()))->equals($($nc(params)->getP()));
				if (var$0 && $nc($(ngParams->getG()))->equals($($nc(params)->getG()))) {
					return ng;
				}
			}
		}
	}
	return nullptr;
}

NamedGroup* NamedGroup::nameOf($String* name) {
	$init(NamedGroup);
	{
		$var($NamedGroupArray, arr$, NamedGroup::values());
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			NamedGroup* group = arr$->get(i$);
			{
				if ($nc($nc(group)->name$)->equalsIgnoreCase(name)) {
					return group;
				}
			}
		}
	}
	return nullptr;
}

$String* NamedGroup::nameOf(int32_t id) {
	$init(NamedGroup);
	$useLocalCurrentObjectStackCache();
	{
		$var($NamedGroupArray, arr$, NamedGroup::values());
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			NamedGroup* group = arr$->get(i$);
			{
				if ($nc(group)->id == id) {
					return group->name$;
				}
			}
		}
	}
	return $str({"UNDEFINED-NAMED-GROUP("_s, $$str(id), ")"_s});
}

bool NamedGroup::isAvailable($List* protocolVersions) {
	if (this->isAvailable$) {
		{
			$var($ProtocolVersionArray, arr$, this->supportedProtocols);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$ProtocolVersion* pv = arr$->get(i$);
				{
					if ($nc(protocolVersions)->contains(pv)) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool NamedGroup::isAvailable($ProtocolVersion* protocolVersion) {
	if (this->isAvailable$) {
		{
			$var($ProtocolVersionArray, arr$, this->supportedProtocols);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$ProtocolVersion* pv = arr$->get(i$);
				{
					if (protocolVersion == pv) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool NamedGroup::isSupported($List* cipherSuites) {
	{
		$var($Iterator, i$, $nc(cipherSuites)->iterator());
		for (; $nc(i$)->hasNext();) {
			$CipherSuite* cs = $cast($CipherSuite, i$->next());
			{
				bool isMatch = isAvailable($nc(cs)->supportedProtocols);
				if (isMatch && (($nc(cs)->keyExchange == nullptr) || ($NamedGroup$NamedGroupSpec::arrayContains($nc(cs)->keyExchange->groupTypes, this->spec)))) {
					return true;
				}
			}
		}
	}
	return false;
}

bool NamedGroup::isPermitted($AlgorithmConstraints* constraints) {
	bool var$0 = $nc(constraints)->permits(NamedGroup::KEY_AGREEMENT_PRIMITIVE_SET, this->name$, nullptr);
	return var$0 && constraints->permits(NamedGroup::KEY_AGREEMENT_PRIMITIVE_SET, this->algorithm, this->keAlgParams);
}

$bytes* NamedGroup::encodePossessionPublicKey($NamedGroupPossession* namedGroupPossession) {
	return this->spec->encodePossessionPublicKey(namedGroupPossession);
}

$SSLCredentials* NamedGroup::decodeCredentials($bytes* encoded, $AlgorithmConstraints* constraints, $NamedGroup$ExceptionSupplier* onConstraintFail) {
	return this->spec->decodeCredentials(this, encoded, constraints, onConstraintFail);
}

$SSLPossession* NamedGroup::createPossession($SecureRandom* random) {
	return this->spec->createPossession(this, random);
}

$SSLKeyDerivation* NamedGroup::createKeyDerivation($HandshakeContext* hc) {
	return this->spec->createKeyDerivation(hc);
}

void clinit$NamedGroup($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$init($NamedGroup$NamedGroupSpec);
	$init($ProtocolVersion);
	$assignStatic(NamedGroup::SECT163_K1, $new(NamedGroup, "SECT163_K1"_s, 0, 1, "sect163k1"_s, $NamedGroup$NamedGroupSpec::NAMED_GROUP_ECDHE, $ProtocolVersion::PROTOCOLS_TO_12, $($CurveDB::lookup("sect163k1"_s))));
	$assignStatic(NamedGroup::SECT163_R1, $new(NamedGroup, "SECT163_R1"_s, 1, 2, "sect163r1"_s, $NamedGroup$NamedGroupSpec::NAMED_GROUP_ECDHE, $ProtocolVersion::PROTOCOLS_TO_12, $($CurveDB::lookup("sect163r1"_s))));
	$assignStatic(NamedGroup::SECT163_R2, $new(NamedGroup, "SECT163_R2"_s, 2, 3, "sect163r2"_s, $NamedGroup$NamedGroupSpec::NAMED_GROUP_ECDHE, $ProtocolVersion::PROTOCOLS_TO_12, $($CurveDB::lookup("sect163r2"_s))));
	$assignStatic(NamedGroup::SECT193_R1, $new(NamedGroup, "SECT193_R1"_s, 3, 4, "sect193r1"_s, $NamedGroup$NamedGroupSpec::NAMED_GROUP_ECDHE, $ProtocolVersion::PROTOCOLS_TO_12, $($CurveDB::lookup("sect193r1"_s))));
	$assignStatic(NamedGroup::SECT193_R2, $new(NamedGroup, "SECT193_R2"_s, 4, 5, "sect193r2"_s, $NamedGroup$NamedGroupSpec::NAMED_GROUP_ECDHE, $ProtocolVersion::PROTOCOLS_TO_12, $($CurveDB::lookup("sect193r2"_s))));
	$assignStatic(NamedGroup::SECT233_K1, $new(NamedGroup, "SECT233_K1"_s, 5, 6, "sect233k1"_s, $NamedGroup$NamedGroupSpec::NAMED_GROUP_ECDHE, $ProtocolVersion::PROTOCOLS_TO_12, $($CurveDB::lookup("sect233k1"_s))));
	$assignStatic(NamedGroup::SECT233_R1, $new(NamedGroup, "SECT233_R1"_s, 6, 7, "sect233r1"_s, $NamedGroup$NamedGroupSpec::NAMED_GROUP_ECDHE, $ProtocolVersion::PROTOCOLS_TO_12, $($CurveDB::lookup("sect233r1"_s))));
	$assignStatic(NamedGroup::SECT239_K1, $new(NamedGroup, "SECT239_K1"_s, 7, 8, "sect239k1"_s, $NamedGroup$NamedGroupSpec::NAMED_GROUP_ECDHE, $ProtocolVersion::PROTOCOLS_TO_12, $($CurveDB::lookup("sect239k1"_s))));
	$assignStatic(NamedGroup::SECT283_K1, $new(NamedGroup, "SECT283_K1"_s, 8, 9, "sect283k1"_s, $NamedGroup$NamedGroupSpec::NAMED_GROUP_ECDHE, $ProtocolVersion::PROTOCOLS_TO_12, $($CurveDB::lookup("sect283k1"_s))));
	$assignStatic(NamedGroup::SECT283_R1, $new(NamedGroup, "SECT283_R1"_s, 9, 10, "sect283r1"_s, $NamedGroup$NamedGroupSpec::NAMED_GROUP_ECDHE, $ProtocolVersion::PROTOCOLS_TO_12, $($CurveDB::lookup("sect283r1"_s))));
	$assignStatic(NamedGroup::SECT409_K1, $new(NamedGroup, "SECT409_K1"_s, 10, 11, "sect409k1"_s, $NamedGroup$NamedGroupSpec::NAMED_GROUP_ECDHE, $ProtocolVersion::PROTOCOLS_TO_12, $($CurveDB::lookup("sect409k1"_s))));
	$assignStatic(NamedGroup::SECT409_R1, $new(NamedGroup, "SECT409_R1"_s, 11, 12, "sect409r1"_s, $NamedGroup$NamedGroupSpec::NAMED_GROUP_ECDHE, $ProtocolVersion::PROTOCOLS_TO_12, $($CurveDB::lookup("sect409r1"_s))));
	$assignStatic(NamedGroup::SECT571_K1, $new(NamedGroup, "SECT571_K1"_s, 12, 13, "sect571k1"_s, $NamedGroup$NamedGroupSpec::NAMED_GROUP_ECDHE, $ProtocolVersion::PROTOCOLS_TO_12, $($CurveDB::lookup("sect571k1"_s))));
	$assignStatic(NamedGroup::SECT571_R1, $new(NamedGroup, "SECT571_R1"_s, 13, 14, "sect571r1"_s, $NamedGroup$NamedGroupSpec::NAMED_GROUP_ECDHE, $ProtocolVersion::PROTOCOLS_TO_12, $($CurveDB::lookup("sect571r1"_s))));
	$assignStatic(NamedGroup::SECP160_K1, $new(NamedGroup, "SECP160_K1"_s, 14, 15, "secp160k1"_s, $NamedGroup$NamedGroupSpec::NAMED_GROUP_ECDHE, $ProtocolVersion::PROTOCOLS_TO_12, $($CurveDB::lookup("secp160k1"_s))));
	$assignStatic(NamedGroup::SECP160_R1, $new(NamedGroup, "SECP160_R1"_s, 15, 16, "secp160r1"_s, $NamedGroup$NamedGroupSpec::NAMED_GROUP_ECDHE, $ProtocolVersion::PROTOCOLS_TO_12, $($CurveDB::lookup("secp160r1"_s))));
	$assignStatic(NamedGroup::SECP160_R2, $new(NamedGroup, "SECP160_R2"_s, 16, 17, "secp160r2"_s, $NamedGroup$NamedGroupSpec::NAMED_GROUP_ECDHE, $ProtocolVersion::PROTOCOLS_TO_12, $($CurveDB::lookup("secp160r2"_s))));
	$assignStatic(NamedGroup::SECP192_K1, $new(NamedGroup, "SECP192_K1"_s, 17, 18, "secp192k1"_s, $NamedGroup$NamedGroupSpec::NAMED_GROUP_ECDHE, $ProtocolVersion::PROTOCOLS_TO_12, $($CurveDB::lookup("secp192k1"_s))));
	$assignStatic(NamedGroup::SECP192_R1, $new(NamedGroup, "SECP192_R1"_s, 18, 19, "secp192r1"_s, $NamedGroup$NamedGroupSpec::NAMED_GROUP_ECDHE, $ProtocolVersion::PROTOCOLS_TO_12, $($CurveDB::lookup("secp192r1"_s))));
	$assignStatic(NamedGroup::SECP224_K1, $new(NamedGroup, "SECP224_K1"_s, 19, 20, "secp224k1"_s, $NamedGroup$NamedGroupSpec::NAMED_GROUP_ECDHE, $ProtocolVersion::PROTOCOLS_TO_12, $($CurveDB::lookup("secp224k1"_s))));
	$assignStatic(NamedGroup::SECP224_R1, $new(NamedGroup, "SECP224_R1"_s, 20, 21, "secp224r1"_s, $NamedGroup$NamedGroupSpec::NAMED_GROUP_ECDHE, $ProtocolVersion::PROTOCOLS_TO_12, $($CurveDB::lookup("secp224r1"_s))));
	$assignStatic(NamedGroup::SECP256_K1, $new(NamedGroup, "SECP256_K1"_s, 21, 22, "secp256k1"_s, $NamedGroup$NamedGroupSpec::NAMED_GROUP_ECDHE, $ProtocolVersion::PROTOCOLS_TO_12, $($CurveDB::lookup("secp256k1"_s))));
	$assignStatic(NamedGroup::SECP256_R1, $new(NamedGroup, "SECP256_R1"_s, 22, 23, "secp256r1"_s, $NamedGroup$NamedGroupSpec::NAMED_GROUP_ECDHE, $ProtocolVersion::PROTOCOLS_TO_13, $($CurveDB::lookup("secp256r1"_s))));
	$assignStatic(NamedGroup::SECP384_R1, $new(NamedGroup, "SECP384_R1"_s, 23, 24, "secp384r1"_s, $NamedGroup$NamedGroupSpec::NAMED_GROUP_ECDHE, $ProtocolVersion::PROTOCOLS_TO_13, $($CurveDB::lookup("secp384r1"_s))));
	$assignStatic(NamedGroup::SECP521_R1, $new(NamedGroup, "SECP521_R1"_s, 24, 25, "secp521r1"_s, $NamedGroup$NamedGroupSpec::NAMED_GROUP_ECDHE, $ProtocolVersion::PROTOCOLS_TO_13, $($CurveDB::lookup("secp521r1"_s))));
	$init($NamedParameterSpec);
	$assignStatic(NamedGroup::X25519, $new(NamedGroup, "X25519"_s, 25, 29, "x25519"_s, $NamedGroup$NamedGroupSpec::NAMED_GROUP_XDH, $ProtocolVersion::PROTOCOLS_TO_13, $NamedParameterSpec::X25519));
	$assignStatic(NamedGroup::X448, $new(NamedGroup, "X448"_s, 26, 30, "x448"_s, $NamedGroup$NamedGroupSpec::NAMED_GROUP_XDH, $ProtocolVersion::PROTOCOLS_TO_13, $NamedParameterSpec::X448));
	$init($PredefinedDHParameterSpecs);
	$assignStatic(NamedGroup::FFDHE_2048, $new(NamedGroup, "FFDHE_2048"_s, 27, 256, "ffdhe2048"_s, $NamedGroup$NamedGroupSpec::NAMED_GROUP_FFDHE, $ProtocolVersion::PROTOCOLS_TO_13, $cast($AlgorithmParameterSpec, $($nc($PredefinedDHParameterSpecs::ffdheParams)->get($($Integer::valueOf(2048)))))));
	$assignStatic(NamedGroup::FFDHE_3072, $new(NamedGroup, "FFDHE_3072"_s, 28, 257, "ffdhe3072"_s, $NamedGroup$NamedGroupSpec::NAMED_GROUP_FFDHE, $ProtocolVersion::PROTOCOLS_TO_13, $cast($AlgorithmParameterSpec, $($nc($PredefinedDHParameterSpecs::ffdheParams)->get($($Integer::valueOf(3072)))))));
	$assignStatic(NamedGroup::FFDHE_4096, $new(NamedGroup, "FFDHE_4096"_s, 29, 258, "ffdhe4096"_s, $NamedGroup$NamedGroupSpec::NAMED_GROUP_FFDHE, $ProtocolVersion::PROTOCOLS_TO_13, $cast($AlgorithmParameterSpec, $($nc($PredefinedDHParameterSpecs::ffdheParams)->get($($Integer::valueOf(4096)))))));
	$assignStatic(NamedGroup::FFDHE_6144, $new(NamedGroup, "FFDHE_6144"_s, 30, 259, "ffdhe6144"_s, $NamedGroup$NamedGroupSpec::NAMED_GROUP_FFDHE, $ProtocolVersion::PROTOCOLS_TO_13, $cast($AlgorithmParameterSpec, $($nc($PredefinedDHParameterSpecs::ffdheParams)->get($($Integer::valueOf(6144)))))));
	$assignStatic(NamedGroup::FFDHE_8192, $new(NamedGroup, "FFDHE_8192"_s, 31, 260, "ffdhe8192"_s, $NamedGroup$NamedGroupSpec::NAMED_GROUP_FFDHE, $ProtocolVersion::PROTOCOLS_TO_13, $cast($AlgorithmParameterSpec, $($nc($PredefinedDHParameterSpecs::ffdheParams)->get($($Integer::valueOf(8192)))))));
	$assignStatic(NamedGroup::ARBITRARY_PRIME, $new(NamedGroup, "ARBITRARY_PRIME"_s, 32, 0x0000FF01, "arbitrary_explicit_prime_curves"_s, $NamedGroup$NamedGroupSpec::NAMED_GROUP_ARBITRARY, $ProtocolVersion::PROTOCOLS_TO_12, nullptr));
	$assignStatic(NamedGroup::ARBITRARY_CHAR2, $new(NamedGroup, "ARBITRARY_CHAR2"_s, 33, 0x0000FF02, "arbitrary_explicit_char2_curves"_s, $NamedGroup$NamedGroupSpec::NAMED_GROUP_ARBITRARY, $ProtocolVersion::PROTOCOLS_TO_12, nullptr));
	$assignStatic(NamedGroup::$VALUES, NamedGroup::$values());
	$init($CryptoPrimitive);
	$assignStatic(NamedGroup::KEY_AGREEMENT_PRIMITIVE_SET, $Collections::unmodifiableSet($($EnumSet::of($CryptoPrimitive::KEY_AGREEMENT))));
}

NamedGroup::NamedGroup() {
}

$Class* NamedGroup::load$($String* name, bool initialize) {
	$loadClass(NamedGroup, name, initialize, &_NamedGroup_ClassInfo_, clinit$NamedGroup, allocate$NamedGroup);
	return class$;
}

$Class* NamedGroup::class$ = nullptr;

		} // ssl
	} // security
} // sun