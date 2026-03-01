#include <sun/security/ssl/SignatureScheme.h>

#include <java/lang/Enum.h>
#include <java/security/AlgorithmConstraints.h>
#include <java/security/AlgorithmParameters.h>
#include <java/security/CryptoPrimitive.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/Key.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/PrivateKey.h>
#include <java/security/Provider.h>
#include <java/security/PublicKey.h>
#include <java/security/SecureRandom.h>
#include <java/security/Security.h>
#include <java/security/Signature.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/security/spec/ECParameterSpec.h>
#include <java/util/AbstractMap$SimpleImmutableEntry.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/EnumSet.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedList.h>
#include <java/util/List.h>
#include <java/util/Map$Entry.h>
#include <java/util/Set.h>
#include <sun/security/ssl/JsseJce.h>
#include <sun/security/ssl/NamedGroup$NamedGroupSpec.h>
#include <sun/security/ssl/NamedGroup.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/SSLConfiguration.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/SignatureScheme$SigAlgParamSpec.h>
#include <sun/security/ssl/SupportedGroupsExtension$SupportedGroups.h>
#include <sun/security/ssl/X509Authentication$X509Possession.h>
#include <sun/security/util/KeyUtil.h>
#include <sun/security/util/SignatureUtil.h>
#include <jcpp.h>

#undef DSA_SHA1
#undef DSA_SHA224
#undef DSA_SHA256
#undef ECDSA_SHA1
#undef ECDSA_SHA224
#undef MAX_VALUE
#undef NAMED_GROUP_ECDHE
#undef PROTOCOLS_TO_12
#undef PROTOCOLS_TO_13
#undef RSA_MD5
#undef RSA_PKCS1_SHA1
#undef RSA_PSS_PSS_SHA256
#undef RSA_PSS_PSS_SHA384
#undef RSA_PSS_PSS_SHA512
#undef RSA_PSS_RSAE_SHA256
#undef RSA_PSS_RSAE_SHA384
#undef RSA_PSS_RSAE_SHA512
#undef RSA_PSS_SHA256
#undef RSA_PSS_SHA384
#undef RSA_PSS_SHA512
#undef RSA_SHA224
#undef SIGNATURE
#undef SIGNATURE_PRIMITIVE_SET

using $ProtocolVersionArray = $Array<::sun::security::ssl::ProtocolVersion>;
using $SignatureSchemeArray = $Array<::sun::security::ssl::SignatureScheme>;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $AlgorithmConstraints = ::java::security::AlgorithmConstraints;
using $AlgorithmParameters = ::java::security::AlgorithmParameters;
using $CryptoPrimitive = ::java::security::CryptoPrimitive;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $Key = ::java::security::Key;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $PrivateKey = ::java::security::PrivateKey;
using $PublicKey = ::java::security::PublicKey;
using $SecureRandom = ::java::security::SecureRandom;
using $Security = ::java::security::Security;
using $Signature = ::java::security::Signature;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $ECParameterSpec = ::java::security::spec::ECParameterSpec;
using $AbstractMap$SimpleImmutableEntry = ::java::util::AbstractMap$SimpleImmutableEntry;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $EnumSet = ::java::util::EnumSet;
using $Iterator = ::java::util::Iterator;
using $LinkedList = ::java::util::LinkedList;
using $List = ::java::util::List;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;
using $JsseJce = ::sun::security::ssl::JsseJce;
using $NamedGroup = ::sun::security::ssl::NamedGroup;
using $NamedGroup$NamedGroupSpec = ::sun::security::ssl::NamedGroup$NamedGroupSpec;
using $ProtocolVersion = ::sun::security::ssl::ProtocolVersion;
using $SSLConfiguration = ::sun::security::ssl::SSLConfiguration;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $SignatureScheme$SigAlgParamSpec = ::sun::security::ssl::SignatureScheme$SigAlgParamSpec;
using $SupportedGroupsExtension$SupportedGroups = ::sun::security::ssl::SupportedGroupsExtension$SupportedGroups;
using $X509Authentication$X509Possession = ::sun::security::ssl::X509Authentication$X509Possession;
using $KeyUtil = ::sun::security::util::KeyUtil;
using $SignatureUtil = ::sun::security::util::SignatureUtil;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _SignatureScheme_FieldInfo_[] = {
	{"ECDSA_SECP256R1_SHA256", "Lsun/security/ssl/SignatureScheme;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SignatureScheme, ECDSA_SECP256R1_SHA256)},
	{"ECDSA_SECP384R1_SHA384", "Lsun/security/ssl/SignatureScheme;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SignatureScheme, ECDSA_SECP384R1_SHA384)},
	{"ECDSA_SECP521R1_SHA512", "Lsun/security/ssl/SignatureScheme;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SignatureScheme, ECDSA_SECP521R1_SHA512)},
	{"ED25519", "Lsun/security/ssl/SignatureScheme;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SignatureScheme, ED25519)},
	{"ED448", "Lsun/security/ssl/SignatureScheme;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SignatureScheme, ED448)},
	{"RSA_PSS_RSAE_SHA256", "Lsun/security/ssl/SignatureScheme;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SignatureScheme, RSA_PSS_RSAE_SHA256)},
	{"RSA_PSS_RSAE_SHA384", "Lsun/security/ssl/SignatureScheme;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SignatureScheme, RSA_PSS_RSAE_SHA384)},
	{"RSA_PSS_RSAE_SHA512", "Lsun/security/ssl/SignatureScheme;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SignatureScheme, RSA_PSS_RSAE_SHA512)},
	{"RSA_PSS_PSS_SHA256", "Lsun/security/ssl/SignatureScheme;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SignatureScheme, RSA_PSS_PSS_SHA256)},
	{"RSA_PSS_PSS_SHA384", "Lsun/security/ssl/SignatureScheme;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SignatureScheme, RSA_PSS_PSS_SHA384)},
	{"RSA_PSS_PSS_SHA512", "Lsun/security/ssl/SignatureScheme;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SignatureScheme, RSA_PSS_PSS_SHA512)},
	{"RSA_PKCS1_SHA256", "Lsun/security/ssl/SignatureScheme;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SignatureScheme, RSA_PKCS1_SHA256)},
	{"RSA_PKCS1_SHA384", "Lsun/security/ssl/SignatureScheme;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SignatureScheme, RSA_PKCS1_SHA384)},
	{"RSA_PKCS1_SHA512", "Lsun/security/ssl/SignatureScheme;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SignatureScheme, RSA_PKCS1_SHA512)},
	{"DSA_SHA256", "Lsun/security/ssl/SignatureScheme;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SignatureScheme, DSA_SHA256)},
	{"ECDSA_SHA224", "Lsun/security/ssl/SignatureScheme;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SignatureScheme, ECDSA_SHA224)},
	{"RSA_SHA224", "Lsun/security/ssl/SignatureScheme;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SignatureScheme, RSA_SHA224)},
	{"DSA_SHA224", "Lsun/security/ssl/SignatureScheme;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SignatureScheme, DSA_SHA224)},
	{"ECDSA_SHA1", "Lsun/security/ssl/SignatureScheme;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SignatureScheme, ECDSA_SHA1)},
	{"RSA_PKCS1_SHA1", "Lsun/security/ssl/SignatureScheme;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SignatureScheme, RSA_PKCS1_SHA1)},
	{"DSA_SHA1", "Lsun/security/ssl/SignatureScheme;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SignatureScheme, DSA_SHA1)},
	{"RSA_MD5", "Lsun/security/ssl/SignatureScheme;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SignatureScheme, RSA_MD5)},
	{"$VALUES", "[Lsun/security/ssl/SignatureScheme;", nullptr, $PRIVATE | $STATIC | $FINAL | $SYNTHETIC, $staticField(SignatureScheme, $VALUES)},
	{"id", "I", nullptr, $FINAL, $field(SignatureScheme, id)},
	{"name", "Ljava/lang/String;", nullptr, $FINAL, $field(SignatureScheme, name$)},
	{"algorithm", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(SignatureScheme, algorithm)},
	{"keyAlgorithm", "Ljava/lang/String;", nullptr, $FINAL, $field(SignatureScheme, keyAlgorithm)},
	{"signAlgParams", "Lsun/security/ssl/SignatureScheme$SigAlgParamSpec;", nullptr, $PRIVATE | $FINAL, $field(SignatureScheme, signAlgParams)},
	{"namedGroup", "Lsun/security/ssl/NamedGroup;", nullptr, $PRIVATE | $FINAL, $field(SignatureScheme, namedGroup)},
	{"minimalKeySize", "I", nullptr, $FINAL, $field(SignatureScheme, minimalKeySize)},
	{"supportedProtocols", "Ljava/util/List;", "Ljava/util/List<Lsun/security/ssl/ProtocolVersion;>;", $FINAL, $field(SignatureScheme, supportedProtocols)},
	{"handshakeSupportedProtocols", "Ljava/util/List;", "Ljava/util/List<Lsun/security/ssl/ProtocolVersion;>;", $FINAL, $field(SignatureScheme, handshakeSupportedProtocols)},
	{"isAvailable", "Z", nullptr, $FINAL, $field(SignatureScheme, isAvailable)},
	{"hashAlgorithms", "[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SignatureScheme, hashAlgorithms)},
	{"signatureAlgorithms", "[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SignatureScheme, signatureAlgorithms)},
	{"SIGNATURE_PRIMITIVE_SET", "Ljava/util/Set;", "Ljava/util/Set<Ljava/security/CryptoPrimitive;>;", $PRIVATE | $STATIC | $FINAL, $staticField(SignatureScheme, SIGNATURE_PRIMITIVE_SET)},
	{}
};

$MethodInfo _SignatureScheme_MethodInfo_[] = {
	{"$values", "()[Lsun/security/ssl/SignatureScheme;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(SignatureScheme, $values, $SignatureSchemeArray*)},
	{"<init>", "(Ljava/lang/String;IILjava/lang/String;Ljava/lang/String;Ljava/lang/String;[Lsun/security/ssl/ProtocolVersion;)V", "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;[Lsun/security/ssl/ProtocolVersion;)V", $PRIVATE, $method(SignatureScheme, init$, void, $String*, int32_t, int32_t, $String*, $String*, $String*, $ProtocolVersionArray*)},
	{"<init>", "(Ljava/lang/String;IILjava/lang/String;Ljava/lang/String;Ljava/lang/String;I[Lsun/security/ssl/ProtocolVersion;)V", "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;I[Lsun/security/ssl/ProtocolVersion;)V", $PRIVATE, $method(SignatureScheme, init$, void, $String*, int32_t, int32_t, $String*, $String*, $String*, int32_t, $ProtocolVersionArray*)},
	{"<init>", "(Ljava/lang/String;IILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Lsun/security/ssl/SignatureScheme$SigAlgParamSpec;I[Lsun/security/ssl/ProtocolVersion;)V", "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Lsun/security/ssl/SignatureScheme$SigAlgParamSpec;I[Lsun/security/ssl/ProtocolVersion;)V", $PRIVATE, $method(SignatureScheme, init$, void, $String*, int32_t, int32_t, $String*, $String*, $String*, $SignatureScheme$SigAlgParamSpec*, int32_t, $ProtocolVersionArray*)},
	{"<init>", "(Ljava/lang/String;IILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Lsun/security/ssl/NamedGroup;[Lsun/security/ssl/ProtocolVersion;)V", "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Lsun/security/ssl/NamedGroup;[Lsun/security/ssl/ProtocolVersion;)V", $PRIVATE, $method(SignatureScheme, init$, void, $String*, int32_t, int32_t, $String*, $String*, $String*, $NamedGroup*, $ProtocolVersionArray*)},
	{"<init>", "(Ljava/lang/String;IILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Lsun/security/ssl/SignatureScheme$SigAlgParamSpec;Lsun/security/ssl/NamedGroup;I[Lsun/security/ssl/ProtocolVersion;[Lsun/security/ssl/ProtocolVersion;)V", "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Lsun/security/ssl/SignatureScheme$SigAlgParamSpec;Lsun/security/ssl/NamedGroup;I[Lsun/security/ssl/ProtocolVersion;[Lsun/security/ssl/ProtocolVersion;)V", $PRIVATE, $method(SignatureScheme, init$, void, $String*, int32_t, int32_t, $String*, $String*, $String*, $SignatureScheme$SigAlgParamSpec*, $NamedGroup*, int32_t, $ProtocolVersionArray*, $ProtocolVersionArray*)},
	{"getAlgorithmNames", "(Ljava/util/Collection;)[Ljava/lang/String;", "(Ljava/util/Collection<Lsun/security/ssl/SignatureScheme;>;)[Ljava/lang/String;", $STATIC, $staticMethod(SignatureScheme, getAlgorithmNames, $StringArray*, $Collection*)},
	{"getPreferableAlgorithm", "(Ljava/security/AlgorithmConstraints;Ljava/util/List;Lsun/security/ssl/SignatureScheme;Lsun/security/ssl/ProtocolVersion;)Lsun/security/ssl/SignatureScheme;", "(Ljava/security/AlgorithmConstraints;Ljava/util/List<Lsun/security/ssl/SignatureScheme;>;Lsun/security/ssl/SignatureScheme;Lsun/security/ssl/ProtocolVersion;)Lsun/security/ssl/SignatureScheme;", $STATIC, $staticMethod(SignatureScheme, getPreferableAlgorithm, SignatureScheme*, $AlgorithmConstraints*, $List*, SignatureScheme*, $ProtocolVersion*)},
	{"getSigner", "(Ljava/security/PrivateKey;)Ljava/security/Signature;", nullptr, $PRIVATE, $method(SignatureScheme, getSigner, $Signature*, $PrivateKey*)},
	{"getSignerOfPreferableAlgorithm", "(Ljava/security/AlgorithmConstraints;Ljava/util/List;Lsun/security/ssl/X509Authentication$X509Possession;Lsun/security/ssl/ProtocolVersion;)Ljava/util/Map$Entry;", "(Ljava/security/AlgorithmConstraints;Ljava/util/List<Lsun/security/ssl/SignatureScheme;>;Lsun/security/ssl/X509Authentication$X509Possession;Lsun/security/ssl/ProtocolVersion;)Ljava/util/Map$Entry<Lsun/security/ssl/SignatureScheme;Ljava/security/Signature;>;", $STATIC, $staticMethod(SignatureScheme, getSignerOfPreferableAlgorithm, $Map$Entry*, $AlgorithmConstraints*, $List*, $X509Authentication$X509Possession*, $ProtocolVersion*)},
	{"getSupportedAlgorithms", "(Lsun/security/ssl/SSLConfiguration;Ljava/security/AlgorithmConstraints;Ljava/util/List;)Ljava/util/List;", "(Lsun/security/ssl/SSLConfiguration;Ljava/security/AlgorithmConstraints;Ljava/util/List<Lsun/security/ssl/ProtocolVersion;>;)Ljava/util/List<Lsun/security/ssl/SignatureScheme;>;", $STATIC, $staticMethod(SignatureScheme, getSupportedAlgorithms, $List*, $SSLConfiguration*, $AlgorithmConstraints*, $List*)},
	{"getSupportedAlgorithms", "(Lsun/security/ssl/SSLConfiguration;Ljava/security/AlgorithmConstraints;Lsun/security/ssl/ProtocolVersion;[I)Ljava/util/List;", "(Lsun/security/ssl/SSLConfiguration;Ljava/security/AlgorithmConstraints;Lsun/security/ssl/ProtocolVersion;[I)Ljava/util/List<Lsun/security/ssl/SignatureScheme;>;", $STATIC, $staticMethod(SignatureScheme, getSupportedAlgorithms, $List*, $SSLConfiguration*, $AlgorithmConstraints*, $ProtocolVersion*, $ints*)},
	{"getVerifier", "(Ljava/security/PublicKey;)Ljava/security/Signature;", nullptr, 0, $method(SignatureScheme, getVerifier, $Signature*, $PublicKey*), "java.security.NoSuchAlgorithmException,java.security.InvalidAlgorithmParameterException,java.security.InvalidKeyException"},
	{"isPermitted", "(Ljava/security/AlgorithmConstraints;)Z", nullptr, $PRIVATE, $method(SignatureScheme, isPermitted, bool, $AlgorithmConstraints*)},
	{"nameOf", "(I)Ljava/lang/String;", nullptr, $STATIC, $staticMethod(SignatureScheme, nameOf, $String*, int32_t)},
	{"nameOf", "(Ljava/lang/String;)Lsun/security/ssl/SignatureScheme;", nullptr, $STATIC, $staticMethod(SignatureScheme, nameOf, SignatureScheme*, $String*)},
	{"sizeInRecord", "()I", nullptr, $STATIC, $staticMethod(SignatureScheme, sizeInRecord, int32_t)},
	{"valueOf", "(Ljava/lang/String;)Lsun/security/ssl/SignatureScheme;", nullptr, $PUBLIC | $STATIC, $staticMethod(SignatureScheme, valueOf, SignatureScheme*, $String*)},
	{"valueOf", "(I)Lsun/security/ssl/SignatureScheme;", nullptr, $STATIC, $staticMethod(SignatureScheme, valueOf, SignatureScheme*, int32_t)},
	{"values", "()[Lsun/security/ssl/SignatureScheme;", nullptr, $PUBLIC | $STATIC, $staticMethod(SignatureScheme, values, $SignatureSchemeArray*)},
	{}
};

$InnerClassInfo _SignatureScheme_InnerClassesInfo_[] = {
	{"sun.security.ssl.SignatureScheme$SigAlgParamSpec", "sun.security.ssl.SignatureScheme", "SigAlgParamSpec", $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _SignatureScheme_ClassInfo_ = {
	$FINAL | $ACC_SUPER | $ENUM,
	"sun.security.ssl.SignatureScheme",
	"java.lang.Enum",
	nullptr,
	_SignatureScheme_FieldInfo_,
	_SignatureScheme_MethodInfo_,
	"Ljava/lang/Enum<Lsun/security/ssl/SignatureScheme;>;",
	nullptr,
	_SignatureScheme_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.ssl.SignatureScheme$SigAlgParamSpec"
};

$Object* allocate$SignatureScheme($Class* clazz) {
	return $of($alloc(SignatureScheme));
}

SignatureScheme* SignatureScheme::ECDSA_SECP256R1_SHA256 = nullptr;
SignatureScheme* SignatureScheme::ECDSA_SECP384R1_SHA384 = nullptr;
SignatureScheme* SignatureScheme::ECDSA_SECP521R1_SHA512 = nullptr;
SignatureScheme* SignatureScheme::ED25519 = nullptr;
SignatureScheme* SignatureScheme::ED448 = nullptr;
SignatureScheme* SignatureScheme::RSA_PSS_RSAE_SHA256 = nullptr;
SignatureScheme* SignatureScheme::RSA_PSS_RSAE_SHA384 = nullptr;
SignatureScheme* SignatureScheme::RSA_PSS_RSAE_SHA512 = nullptr;
SignatureScheme* SignatureScheme::RSA_PSS_PSS_SHA256 = nullptr;
SignatureScheme* SignatureScheme::RSA_PSS_PSS_SHA384 = nullptr;
SignatureScheme* SignatureScheme::RSA_PSS_PSS_SHA512 = nullptr;
SignatureScheme* SignatureScheme::RSA_PKCS1_SHA256 = nullptr;
SignatureScheme* SignatureScheme::RSA_PKCS1_SHA384 = nullptr;
SignatureScheme* SignatureScheme::RSA_PKCS1_SHA512 = nullptr;
SignatureScheme* SignatureScheme::DSA_SHA256 = nullptr;
SignatureScheme* SignatureScheme::ECDSA_SHA224 = nullptr;
SignatureScheme* SignatureScheme::RSA_SHA224 = nullptr;
SignatureScheme* SignatureScheme::DSA_SHA224 = nullptr;
SignatureScheme* SignatureScheme::ECDSA_SHA1 = nullptr;
SignatureScheme* SignatureScheme::RSA_PKCS1_SHA1 = nullptr;
SignatureScheme* SignatureScheme::DSA_SHA1 = nullptr;
SignatureScheme* SignatureScheme::RSA_MD5 = nullptr;
$SignatureSchemeArray* SignatureScheme::$VALUES = nullptr;
$StringArray* SignatureScheme::hashAlgorithms = nullptr;
$StringArray* SignatureScheme::signatureAlgorithms = nullptr;
$Set* SignatureScheme::SIGNATURE_PRIMITIVE_SET = nullptr;

$SignatureSchemeArray* SignatureScheme::$values() {
	$init(SignatureScheme);
	return $new($SignatureSchemeArray, {
		SignatureScheme::ECDSA_SECP256R1_SHA256,
		SignatureScheme::ECDSA_SECP384R1_SHA384,
		SignatureScheme::ECDSA_SECP521R1_SHA512,
		SignatureScheme::ED25519,
		SignatureScheme::ED448,
		SignatureScheme::RSA_PSS_RSAE_SHA256,
		SignatureScheme::RSA_PSS_RSAE_SHA384,
		SignatureScheme::RSA_PSS_RSAE_SHA512,
		SignatureScheme::RSA_PSS_PSS_SHA256,
		SignatureScheme::RSA_PSS_PSS_SHA384,
		SignatureScheme::RSA_PSS_PSS_SHA512,
		SignatureScheme::RSA_PKCS1_SHA256,
		SignatureScheme::RSA_PKCS1_SHA384,
		SignatureScheme::RSA_PKCS1_SHA512,
		SignatureScheme::DSA_SHA256,
		SignatureScheme::ECDSA_SHA224,
		SignatureScheme::RSA_SHA224,
		SignatureScheme::DSA_SHA224,
		SignatureScheme::ECDSA_SHA1,
		SignatureScheme::RSA_PKCS1_SHA1,
		SignatureScheme::DSA_SHA1,
		SignatureScheme::RSA_MD5
	});
}

$SignatureSchemeArray* SignatureScheme::values() {
	$init(SignatureScheme);
	return $cast($SignatureSchemeArray, SignatureScheme::$VALUES->clone());
}

SignatureScheme* SignatureScheme::valueOf($String* name) {
	$init(SignatureScheme);
	return $cast(SignatureScheme, $Enum::valueOf(SignatureScheme::class$, name));
}

void SignatureScheme::init$($String* $enum$name, int32_t $enum$ordinal, int32_t id, $String* name, $String* algorithm, $String* keyAlgorithm, $ProtocolVersionArray* supportedProtocols) {
	SignatureScheme::init$($enum$name, $enum$ordinal, id, name, algorithm, keyAlgorithm, -1, supportedProtocols);
}

void SignatureScheme::init$($String* $enum$name, int32_t $enum$ordinal, int32_t id, $String* name, $String* algorithm, $String* keyAlgorithm, int32_t minimalKeySize, $ProtocolVersionArray* supportedProtocols) {
	SignatureScheme::init$($enum$name, $enum$ordinal, id, name, algorithm, keyAlgorithm, nullptr, minimalKeySize, supportedProtocols);
}

void SignatureScheme::init$($String* $enum$name, int32_t $enum$ordinal, int32_t id, $String* name, $String* algorithm, $String* keyAlgorithm, $SignatureScheme$SigAlgParamSpec* signAlgParamSpec, int32_t minimalKeySize, $ProtocolVersionArray* supportedProtocols) {
	SignatureScheme::init$($enum$name, $enum$ordinal, id, name, algorithm, keyAlgorithm, signAlgParamSpec, nullptr, minimalKeySize, supportedProtocols, supportedProtocols);
}

void SignatureScheme::init$($String* $enum$name, int32_t $enum$ordinal, int32_t id, $String* name, $String* algorithm, $String* keyAlgorithm, $NamedGroup* namedGroup, $ProtocolVersionArray* supportedProtocols) {
	SignatureScheme::init$($enum$name, $enum$ordinal, id, name, algorithm, keyAlgorithm, nullptr, namedGroup, -1, supportedProtocols, supportedProtocols);
}

void SignatureScheme::init$($String* $enum$name, int32_t $enum$ordinal, int32_t id, $String* name, $String* algorithm, $String* keyAlgorithm, $SignatureScheme$SigAlgParamSpec* signAlgParams, $NamedGroup* namedGroup, int32_t minimalKeySize, $ProtocolVersionArray* supportedProtocols, $ProtocolVersionArray* handshakeSupportedProtocols) {
	$useLocalCurrentObjectStackCache();
	$Enum::init$($enum$name, $enum$ordinal);
	this->id = id;
	$set(this, name$, name);
	$set(this, algorithm, algorithm);
	$set(this, keyAlgorithm, keyAlgorithm);
	$set(this, signAlgParams, signAlgParams);
	$set(this, namedGroup, namedGroup);
	this->minimalKeySize = minimalKeySize;
	$set(this, supportedProtocols, $Arrays::asList(supportedProtocols));
	$set(this, handshakeSupportedProtocols, $Arrays::asList(handshakeSupportedProtocols));
	bool mediator = true;
	if ("EC"_s->equals(keyAlgorithm)) {
		mediator = $JsseJce::isEcAvailable();
	}
	if (mediator) {
		if (signAlgParams != nullptr) {
			mediator = signAlgParams->isAvailable;
		} else {
			try {
				$Signature::getInstance(algorithm);
			} catch ($Exception& e) {
				mediator = false;
				$init($SSLLogger);
				if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
					$SSLLogger::warning($$str({"Signature algorithm, "_s, algorithm, ", is not supported by the underlying providers"_s}), $$new($ObjectArray, 0));
				}
			}
		}
	}
	if (mediator && ((int32_t)((id >> 8) & (uint32_t)255)) == 3) {
		if ($Security::getProvider("SunMSCAPI"_s) != nullptr) {
			mediator = false;
		}
	}
	this->isAvailable = mediator;
}

SignatureScheme* SignatureScheme::valueOf(int32_t id) {
	$init(SignatureScheme);
	{
		$var($SignatureSchemeArray, arr$, SignatureScheme::values());
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			SignatureScheme* ss = arr$->get(i$);
			{
				if ($nc(ss)->id == id) {
					return ss;
				}
			}
		}
	}
	return nullptr;
}

$String* SignatureScheme::nameOf(int32_t id) {
	$init(SignatureScheme);
	$useLocalCurrentObjectStackCache();
	{
		$var($SignatureSchemeArray, arr$, SignatureScheme::values());
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			SignatureScheme* ss = arr$->get(i$);
			{
				if ($nc(ss)->id == id) {
					return ss->name$;
				}
			}
		}
	}
	int32_t hashId = ((int32_t)((id >> 8) & (uint32_t)255));
	int32_t signId = ((int32_t)(id & (uint32_t)255));
	$var($String, hashName, (hashId >= $nc(SignatureScheme::hashAlgorithms)->length) ? $str({"UNDEFINED-HASH("_s, $$str(hashId), ")"_s}) : $nc(SignatureScheme::hashAlgorithms)->get(hashId));
	$var($String, signName, (signId >= $nc(SignatureScheme::signatureAlgorithms)->length) ? $str({"UNDEFINED-SIGNATURE("_s, $$str(signId), ")"_s}) : $nc(SignatureScheme::signatureAlgorithms)->get(signId));
	return $str({signName, "_"_s, hashName});
}

SignatureScheme* SignatureScheme::nameOf($String* signatureSchemeName) {
	$init(SignatureScheme);
	{
		$var($SignatureSchemeArray, arr$, SignatureScheme::values());
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			SignatureScheme* ss = arr$->get(i$);
			{
				if ($nc($nc(ss)->name$)->equalsIgnoreCase(signatureSchemeName)) {
					return ss;
				}
			}
		}
	}
	return nullptr;
}

int32_t SignatureScheme::sizeInRecord() {
	$init(SignatureScheme);
	return 2;
}

bool SignatureScheme::isPermitted($AlgorithmConstraints* constraints) {
	bool var$2 = $nc(constraints)->permits(SignatureScheme::SIGNATURE_PRIMITIVE_SET, this->name$, nullptr);
	bool var$1 = var$2 && constraints->permits(SignatureScheme::SIGNATURE_PRIMITIVE_SET, this->keyAlgorithm, nullptr);
	bool var$0 = var$1 && constraints->permits(SignatureScheme::SIGNATURE_PRIMITIVE_SET, this->algorithm, (this->signAlgParams != nullptr ? this->signAlgParams->parameters : ($AlgorithmParameters*)nullptr));
	return var$0 && (this->namedGroup == nullptr || this->namedGroup->isPermitted(constraints));
}

$List* SignatureScheme::getSupportedAlgorithms($SSLConfiguration* config, $AlgorithmConstraints* constraints, $List* activeProtocols) {
	$init(SignatureScheme);
	$useLocalCurrentObjectStackCache();
	$var($List, supported, $new($LinkedList));
	$var($List, schemesToCheck, $nc($nc(config)->signatureSchemes)->isEmpty() ? $Arrays::asList($(SignatureScheme::values())) : $nc(config)->signatureSchemes);
	{
		$var($Iterator, i$, $nc(schemesToCheck)->iterator());
		for (; $nc(i$)->hasNext();) {
			SignatureScheme* ss = $cast(SignatureScheme, i$->next());
			{
				if (!$nc(ss)->isAvailable) {
					$init($SSLLogger);
					if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake,verbose"_s)) {
						$SSLLogger::finest($$str({"Ignore unsupported signature scheme: "_s, ss->name$}), $$new($ObjectArray, 0));
					}
					continue;
				}
				bool isMatch = false;
				{
					$var($Iterator, i$, $nc(activeProtocols)->iterator());
					for (; $nc(i$)->hasNext();) {
						$ProtocolVersion* pv = $cast($ProtocolVersion, i$->next());
						{
							if ($nc($nc(ss)->supportedProtocols)->contains(pv)) {
								isMatch = true;
								break;
							}
						}
					}
				}
				if (isMatch) {
					if ($nc(ss)->isPermitted(constraints)) {
						supported->add(ss);
					} else {
						$init($SSLLogger);
						if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake,verbose"_s)) {
							$SSLLogger::finest($$str({"Ignore disabled signature scheme: "_s, ss->name$}), $$new($ObjectArray, 0));
						}
					}
				} else {
					$init($SSLLogger);
					if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake,verbose"_s)) {
						$SSLLogger::finest($$str({"Ignore inactive signature scheme: "_s, $nc(ss)->name$}), $$new($ObjectArray, 0));
					}
				}
			}
		}
	}
	return supported;
}

$List* SignatureScheme::getSupportedAlgorithms($SSLConfiguration* config, $AlgorithmConstraints* constraints, $ProtocolVersion* protocolVersion, $ints* algorithmIds) {
	$init(SignatureScheme);
	$useLocalCurrentObjectStackCache();
	$var($List, supported, $new($LinkedList));
	{
		$var($ints, arr$, algorithmIds);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			int32_t ssid = arr$->get(i$);
			{
				SignatureScheme* ss = SignatureScheme::valueOf(ssid);
				if (ss == nullptr) {
					$init($SSLLogger);
					if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
						$SSLLogger::warning($$str({"Unsupported signature scheme: "_s, $(SignatureScheme::nameOf(ssid))}), $$new($ObjectArray, 0));
					}
				} else {
					bool var$4 = $nc(ss)->isAvailable && $nc(ss->supportedProtocols)->contains(protocolVersion);
					if (var$4) {
						bool var$5 = $nc($nc(config)->signatureSchemes)->isEmpty();
						var$4 = (var$5 || $nc($nc(config)->signatureSchemes)->contains(ss));
					}
					bool var$3 = var$4;
					if (var$3 && $nc(ss)->isPermitted(constraints)) {
						supported->add(ss);
					} else {
						$init($SSLLogger);
						if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
							$SSLLogger::warning($$str({"Unsupported signature scheme: "_s, ss->name$}), $$new($ObjectArray, 0));
						}
					}
				}
			}
		}
	}
	return supported;
}

SignatureScheme* SignatureScheme::getPreferableAlgorithm($AlgorithmConstraints* constraints, $List* schemes, SignatureScheme* certScheme, $ProtocolVersion* version) {
	$init(SignatureScheme);
	{
		$var($Iterator, i$, $nc(schemes)->iterator());
		for (; $nc(i$)->hasNext();) {
			SignatureScheme* ss = $cast(SignatureScheme, i$->next());
			{
				bool var$1 = $nc(ss)->isAvailable && $nc(ss->handshakeSupportedProtocols)->contains(version);
				bool var$0 = var$1 && $nc($nc(certScheme)->keyAlgorithm)->equalsIgnoreCase(ss->keyAlgorithm);
				if (var$0 && ss->isPermitted(constraints)) {
					return ss;
				}
			}
		}
	}
	return nullptr;
}

$Map$Entry* SignatureScheme::getSignerOfPreferableAlgorithm($AlgorithmConstraints* constraints, $List* schemes, $X509Authentication$X509Possession* x509Possession, $ProtocolVersion* version) {
	$init(SignatureScheme);
	$useLocalCurrentObjectStackCache();
	$var($PrivateKey, signingKey, $nc(x509Possession)->popPrivateKey);
	$var($String, keyAlgorithm, $nc(signingKey)->getAlgorithm());
	int32_t keySize = 0;
	bool var$0 = $nc(keyAlgorithm)->equalsIgnoreCase("RSA"_s);
	if (var$0 || $nc(keyAlgorithm)->equalsIgnoreCase("RSASSA-PSS"_s)) {
		keySize = $KeyUtil::getKeySize(static_cast<$Key*>(signingKey));
	} else {
		keySize = $Integer::MAX_VALUE;
	}
	{
		$var($Iterator, i$, $nc(schemes)->iterator());
		for (; $nc(i$)->hasNext();) {
			SignatureScheme* ss = $cast(SignatureScheme, i$->next());
			{
				bool var$2 = $nc(ss)->isAvailable && (keySize >= ss->minimalKeySize) && $nc(ss->handshakeSupportedProtocols)->contains(version);
				bool var$1 = var$2 && $nc(keyAlgorithm)->equalsIgnoreCase(ss->keyAlgorithm);
				if (var$1 && ss->isPermitted(constraints)) {
					$init($NamedGroup$NamedGroupSpec);
					if ((ss->namedGroup != nullptr) && (ss->namedGroup->spec == $NamedGroup$NamedGroupSpec::NAMED_GROUP_ECDHE)) {
						$var($ECParameterSpec, params, x509Possession->getECParameterSpec());
						if (params != nullptr && ss->namedGroup == $NamedGroup::valueOf(params)) {
							$var($Signature, signer, ss->getSigner(signingKey));
							if (signer != nullptr) {
								return $new($AbstractMap$SimpleImmutableEntry, ss, signer);
							}
						}
						$init($SSLLogger);
						if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake,verbose"_s)) {
							$SSLLogger::finest($$str({"Ignore the signature algorithm ("_s, ss, "), unsupported EC parameter spec: "_s, params}), $$new($ObjectArray, 0));
						}
					} else if ("EC"_s->equals(ss->keyAlgorithm)) {
						$var($ECParameterSpec, params, x509Possession->getECParameterSpec());
						if (params != nullptr) {
							$NamedGroup* keyGroup = $NamedGroup::valueOf(params);
							if (keyGroup != nullptr && $SupportedGroupsExtension$SupportedGroups::isSupported(keyGroup)) {
								$var($Signature, signer, ss->getSigner(signingKey));
								if (signer != nullptr) {
									return $new($AbstractMap$SimpleImmutableEntry, ss, signer);
								}
							}
						}
						$init($SSLLogger);
						if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake,verbose"_s)) {
							$SSLLogger::finest($$str({"Ignore the legacy signature algorithm ("_s, ss, "), unsupported EC parameter spec: "_s, params}), $$new($ObjectArray, 0));
						}
					} else {
						$var($Signature, signer, ss->getSigner(signingKey));
						if (signer != nullptr) {
							return $new($AbstractMap$SimpleImmutableEntry, ss, signer);
						}
					}
				}
			}
		}
	}
	return nullptr;
}

$StringArray* SignatureScheme::getAlgorithmNames($Collection* schemes) {
	$init(SignatureScheme);
	$useLocalCurrentObjectStackCache();
	if (schemes != nullptr) {
		$var($ArrayList, names, $new($ArrayList, schemes->size()));
		{
			$var($Iterator, i$, schemes->iterator());
			for (; $nc(i$)->hasNext();) {
				SignatureScheme* scheme = $cast(SignatureScheme, i$->next());
				{
					names->add($nc(scheme)->algorithm);
				}
			}
		}
		return $fcast($StringArray, names->toArray($$new($StringArray, 0)));
	}
	return $new($StringArray, 0);
}

$Signature* SignatureScheme::getVerifier($PublicKey* publicKey) {
	if (!this->isAvailable) {
		return nullptr;
	}
	$var($Signature, verifier, $Signature::getInstance(this->algorithm));
	$SignatureUtil::initVerifyWithParam(verifier, publicKey, (this->signAlgParams != nullptr ? this->signAlgParams->parameterSpec : ($AlgorithmParameterSpec*)nullptr));
	return verifier;
}

$Signature* SignatureScheme::getSigner($PrivateKey* privateKey) {
	$useLocalCurrentObjectStackCache();
	if (!this->isAvailable) {
		return nullptr;
	}
	try {
		$var($Signature, signer, $Signature::getInstance(this->algorithm));
		$SignatureUtil::initSignWithParam(signer, privateKey, (this->signAlgParams != nullptr ? this->signAlgParams->parameterSpec : ($AlgorithmParameterSpec*)nullptr), nullptr);
		return signer;
	} catch ($NoSuchAlgorithmException& nsae) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake,verbose"_s)) {
			$SSLLogger::finest($$str({"Ignore unsupported signature algorithm ("_s, this->name$, ")"_s}), $$new($ObjectArray, {$of(nsae)}));
		}
	} catch ($InvalidKeyException& nsae) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake,verbose"_s)) {
			$SSLLogger::finest($$str({"Ignore unsupported signature algorithm ("_s, this->name$, ")"_s}), $$new($ObjectArray, {$of(nsae)}));
		}
	} catch ($InvalidAlgorithmParameterException& nsae) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake,verbose"_s)) {
			$SSLLogger::finest($$str({"Ignore unsupported signature algorithm ("_s, this->name$, ")"_s}), $$new($ObjectArray, {$of(nsae)}));
		}
	}
	return nullptr;
}

void clinit$SignatureScheme($Class* class$) {
	$init($NamedGroup);
	$init($ProtocolVersion);
	$assignStatic(SignatureScheme::ECDSA_SECP256R1_SHA256, $new(SignatureScheme, "ECDSA_SECP256R1_SHA256"_s, 0, 1027, "ecdsa_secp256r1_sha256"_s, "SHA256withECDSA"_s, "EC"_s, $NamedGroup::SECP256_R1, $ProtocolVersion::PROTOCOLS_TO_13));
	$assignStatic(SignatureScheme::ECDSA_SECP384R1_SHA384, $new(SignatureScheme, "ECDSA_SECP384R1_SHA384"_s, 1, 1283, "ecdsa_secp384r1_sha384"_s, "SHA384withECDSA"_s, "EC"_s, $NamedGroup::SECP384_R1, $ProtocolVersion::PROTOCOLS_TO_13));
	$assignStatic(SignatureScheme::ECDSA_SECP521R1_SHA512, $new(SignatureScheme, "ECDSA_SECP521R1_SHA512"_s, 2, 1539, "ecdsa_secp521r1_sha512"_s, "SHA512withECDSA"_s, "EC"_s, $NamedGroup::SECP521_R1, $ProtocolVersion::PROTOCOLS_TO_13));
	$assignStatic(SignatureScheme::ED25519, $new(SignatureScheme, "ED25519"_s, 3, 2055, "ed25519"_s, "Ed25519"_s, "EdDSA"_s, $ProtocolVersion::PROTOCOLS_12_13));
	$assignStatic(SignatureScheme::ED448, $new(SignatureScheme, "ED448"_s, 4, 2056, "ed448"_s, "Ed448"_s, "EdDSA"_s, $ProtocolVersion::PROTOCOLS_12_13));
	$init($SignatureScheme$SigAlgParamSpec);
	$assignStatic(SignatureScheme::RSA_PSS_RSAE_SHA256, $new(SignatureScheme, "RSA_PSS_RSAE_SHA256"_s, 5, 2052, "rsa_pss_rsae_sha256"_s, "RSASSA-PSS"_s, "RSA"_s, $SignatureScheme$SigAlgParamSpec::RSA_PSS_SHA256, 528, $ProtocolVersion::PROTOCOLS_12_13));
	$assignStatic(SignatureScheme::RSA_PSS_RSAE_SHA384, $new(SignatureScheme, "RSA_PSS_RSAE_SHA384"_s, 6, 2053, "rsa_pss_rsae_sha384"_s, "RSASSA-PSS"_s, "RSA"_s, $SignatureScheme$SigAlgParamSpec::RSA_PSS_SHA384, 784, $ProtocolVersion::PROTOCOLS_12_13));
	$assignStatic(SignatureScheme::RSA_PSS_RSAE_SHA512, $new(SignatureScheme, "RSA_PSS_RSAE_SHA512"_s, 7, 2054, "rsa_pss_rsae_sha512"_s, "RSASSA-PSS"_s, "RSA"_s, $SignatureScheme$SigAlgParamSpec::RSA_PSS_SHA512, 1040, $ProtocolVersion::PROTOCOLS_12_13));
	$assignStatic(SignatureScheme::RSA_PSS_PSS_SHA256, $new(SignatureScheme, "RSA_PSS_PSS_SHA256"_s, 8, 2057, "rsa_pss_pss_sha256"_s, "RSASSA-PSS"_s, "RSASSA-PSS"_s, $SignatureScheme$SigAlgParamSpec::RSA_PSS_SHA256, 528, $ProtocolVersion::PROTOCOLS_12_13));
	$assignStatic(SignatureScheme::RSA_PSS_PSS_SHA384, $new(SignatureScheme, "RSA_PSS_PSS_SHA384"_s, 9, 2058, "rsa_pss_pss_sha384"_s, "RSASSA-PSS"_s, "RSASSA-PSS"_s, $SignatureScheme$SigAlgParamSpec::RSA_PSS_SHA384, 784, $ProtocolVersion::PROTOCOLS_12_13));
	$assignStatic(SignatureScheme::RSA_PSS_PSS_SHA512, $new(SignatureScheme, "RSA_PSS_PSS_SHA512"_s, 10, 2059, "rsa_pss_pss_sha512"_s, "RSASSA-PSS"_s, "RSASSA-PSS"_s, $SignatureScheme$SigAlgParamSpec::RSA_PSS_SHA512, 1040, $ProtocolVersion::PROTOCOLS_12_13));
	$assignStatic(SignatureScheme::RSA_PKCS1_SHA256, $new(SignatureScheme, "RSA_PKCS1_SHA256"_s, 11, 1025, "rsa_pkcs1_sha256"_s, "SHA256withRSA"_s, "RSA"_s, nullptr, nullptr, 511, $ProtocolVersion::PROTOCOLS_TO_13, $ProtocolVersion::PROTOCOLS_TO_12));
	$assignStatic(SignatureScheme::RSA_PKCS1_SHA384, $new(SignatureScheme, "RSA_PKCS1_SHA384"_s, 12, 1281, "rsa_pkcs1_sha384"_s, "SHA384withRSA"_s, "RSA"_s, nullptr, nullptr, 768, $ProtocolVersion::PROTOCOLS_TO_13, $ProtocolVersion::PROTOCOLS_TO_12));
	$assignStatic(SignatureScheme::RSA_PKCS1_SHA512, $new(SignatureScheme, "RSA_PKCS1_SHA512"_s, 13, 1537, "rsa_pkcs1_sha512"_s, "SHA512withRSA"_s, "RSA"_s, nullptr, nullptr, 768, $ProtocolVersion::PROTOCOLS_TO_13, $ProtocolVersion::PROTOCOLS_TO_12));
	$assignStatic(SignatureScheme::DSA_SHA256, $new(SignatureScheme, "DSA_SHA256"_s, 14, 1026, "dsa_sha256"_s, "SHA256withDSA"_s, "DSA"_s, $ProtocolVersion::PROTOCOLS_TO_12));
	$assignStatic(SignatureScheme::ECDSA_SHA224, $new(SignatureScheme, "ECDSA_SHA224"_s, 15, 771, "ecdsa_sha224"_s, "SHA224withECDSA"_s, "EC"_s, $ProtocolVersion::PROTOCOLS_TO_12));
	$assignStatic(SignatureScheme::RSA_SHA224, $new(SignatureScheme, "RSA_SHA224"_s, 16, 769, "rsa_sha224"_s, "SHA224withRSA"_s, "RSA"_s, 511, $ProtocolVersion::PROTOCOLS_TO_12));
	$assignStatic(SignatureScheme::DSA_SHA224, $new(SignatureScheme, "DSA_SHA224"_s, 17, 770, "dsa_sha224"_s, "SHA224withDSA"_s, "DSA"_s, $ProtocolVersion::PROTOCOLS_TO_12));
	$assignStatic(SignatureScheme::ECDSA_SHA1, $new(SignatureScheme, "ECDSA_SHA1"_s, 18, 515, "ecdsa_sha1"_s, "SHA1withECDSA"_s, "EC"_s, $ProtocolVersion::PROTOCOLS_TO_13));
	$assignStatic(SignatureScheme::RSA_PKCS1_SHA1, $new(SignatureScheme, "RSA_PKCS1_SHA1"_s, 19, 513, "rsa_pkcs1_sha1"_s, "SHA1withRSA"_s, "RSA"_s, nullptr, nullptr, 511, $ProtocolVersion::PROTOCOLS_TO_13, $ProtocolVersion::PROTOCOLS_TO_12));
	$assignStatic(SignatureScheme::DSA_SHA1, $new(SignatureScheme, "DSA_SHA1"_s, 20, 514, "dsa_sha1"_s, "SHA1withDSA"_s, "DSA"_s, $ProtocolVersion::PROTOCOLS_TO_12));
	$assignStatic(SignatureScheme::RSA_MD5, $new(SignatureScheme, "RSA_MD5"_s, 21, 257, "rsa_md5"_s, "MD5withRSA"_s, "RSA"_s, 511, $ProtocolVersion::PROTOCOLS_TO_12));
	$assignStatic(SignatureScheme::$VALUES, SignatureScheme::$values());
	$assignStatic(SignatureScheme::hashAlgorithms, $new($StringArray, {
		"none"_s,
		"md5"_s,
		"sha1"_s,
		"sha224"_s,
		"sha256"_s,
		"sha384"_s,
		"sha512"_s
	}));
	$assignStatic(SignatureScheme::signatureAlgorithms, $new($StringArray, {
		"anonymous"_s,
		"rsa"_s,
		"dsa"_s,
		"ecdsa"_s
	}));
	$init($CryptoPrimitive);
	$assignStatic(SignatureScheme::SIGNATURE_PRIMITIVE_SET, $Collections::unmodifiableSet($($EnumSet::of($CryptoPrimitive::SIGNATURE))));
}

SignatureScheme::SignatureScheme() {
}

$Class* SignatureScheme::load$($String* name, bool initialize) {
	$loadClass(SignatureScheme, name, initialize, &_SignatureScheme_ClassInfo_, clinit$SignatureScheme, allocate$SignatureScheme);
	return class$;
}

$Class* SignatureScheme::class$ = nullptr;

		} // ssl
	} // security
} // sun