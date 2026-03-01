#include <com/sun/crypto/provider/SunJCE.h>

#include <com/sun/crypto/provider/SunJCE$1.h>
#include <com/sun/crypto/provider/SunJCE$SecureRandomHolder.h>
#include <java/lang/SecurityManager.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/Provider$Service.h>
#include <java/security/Provider.h>
#include <java/security/SecureRandom.h>
#include <java/util/HashMap.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <sun/security/util/SecurityConstants.h>
#include <sun/security/util/SecurityProviderConstants.h>
#include <jcpp.h>

#undef BLOCK_MODES
#undef BLOCK_MODES128
#undef BLOCK_PADS
#undef PROVIDER_VER
#undef RANDOM

using $SunJCE$1 = ::com::sun::crypto::provider::SunJCE$1;
using $SunJCE$SecureRandomHolder = ::com::sun::crypto::provider::SunJCE$SecureRandomHolder;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Provider = ::java::security::Provider;
using $Provider$Service = ::java::security::Provider$Service;
using $SecureRandom = ::java::security::SecureRandom;
using $HashMap = ::java::util::HashMap;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $SecurityConstants = ::sun::security::util::SecurityConstants;
using $SecurityProviderConstants = ::sun::security::util::SecurityProviderConstants;

namespace com {
	namespace sun {
		namespace crypto {
			namespace provider {

$FieldInfo _SunJCE_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SunJCE, serialVersionUID)},
	{"info", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SunJCE, info)},
	{"debug", "Z", nullptr, $STATIC | $FINAL, $constField(SunJCE, debug)},
	{"instance", "Lcom/sun/crypto/provider/SunJCE;", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(SunJCE, instance)},
	{}
};

$MethodInfo _SunJCE_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(SunJCE, init$, void)},
	{"getInstance", "()Lcom/sun/crypto/provider/SunJCE;", nullptr, $STATIC, $staticMethod(SunJCE, getInstance, SunJCE*)},
	{"getRandom", "()Ljava/security/SecureRandom;", nullptr, $STATIC, $staticMethod(SunJCE, getRandom, $SecureRandom*)},
	{"ps", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PRIVATE, $method(SunJCE, ps, void, $String*, $String*, $String*)},
	{"ps", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/util/List;Ljava/util/HashMap;)V", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/util/List<Ljava/lang/String;>;Ljava/util/HashMap<Ljava/lang/String;Ljava/lang/String;>;)V", $PRIVATE, $method(SunJCE, ps, void, $String*, $String*, $String*, $List*, $HashMap*)},
	{"psA", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/util/HashMap;)V", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/util/HashMap<Ljava/lang/String;Ljava/lang/String;>;)V", $PRIVATE, $method(SunJCE, psA, void, $String*, $String*, $String*, $HashMap*)},
	{"putEntries", "()V", nullptr, 0, $method(SunJCE, putEntries, void)},
	{}
};

$InnerClassInfo _SunJCE_InnerClassesInfo_[] = {
	{"com.sun.crypto.provider.SunJCE$SecureRandomHolder", "com.sun.crypto.provider.SunJCE", "SecureRandomHolder", $PRIVATE | $STATIC},
	{"com.sun.crypto.provider.SunJCE$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _SunJCE_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"com.sun.crypto.provider.SunJCE",
	"java.security.Provider",
	nullptr,
	_SunJCE_FieldInfo_,
	_SunJCE_MethodInfo_,
	nullptr,
	nullptr,
	_SunJCE_InnerClassesInfo_,
	nullptr,
	nullptr,
	"com.sun.crypto.provider.SunJCE$SecureRandomHolder,com.sun.crypto.provider.SunJCE$1"
};

$Object* allocate$SunJCE($Class* clazz) {
	return $of($alloc(SunJCE));
}

$String* SunJCE::info = nullptr;
$volatile(SunJCE*) SunJCE::instance = nullptr;

$SecureRandom* SunJCE::getRandom() {
	$init(SunJCE);
	$init($SunJCE$SecureRandomHolder);
	return $SunJCE$SecureRandomHolder::RANDOM;
}

void SunJCE::ps($String* type, $String* algo, $String* cn) {
	putService($$new($Provider$Service, this, type, algo, cn, nullptr, nullptr));
}

void SunJCE::ps($String* type, $String* algo, $String* cn, $List* als, $HashMap* attrs) {
	putService($$new($Provider$Service, this, type, algo, cn, als, attrs));
}

void SunJCE::psA($String* type, $String* algo, $String* cn, $HashMap* attrs) {
	$useLocalCurrentObjectStackCache();
	putService($$new($Provider$Service, this, type, algo, cn, $($SecurityProviderConstants::getAliases(algo)), attrs));
}

void SunJCE::init$() {
	$beforeCallerSensitive();
	$init($SecurityConstants);
	$Provider::init$("SunJCE"_s, $SecurityConstants::PROVIDER_VER, SunJCE::info);
	if ($System::getSecurityManager() == nullptr) {
		putEntries();
	} else {
		$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($SunJCE$1, this)));
	}
	if (SunJCE::instance == nullptr) {
		$assignStatic(SunJCE::instance, this);
	}
}

void SunJCE::putEntries() {
	$useLocalCurrentObjectStackCache();
	$var($HashMap, attrs, $new($HashMap, 3));
	attrs->put("SupportedModes"_s, "ECB"_s);
	attrs->put("SupportedPaddings"_s, "NOPADDING|PKCS1PADDING|OAEPPADDING|OAEPWITHMD5ANDMGF1PADDING|OAEPWITHSHA1ANDMGF1PADDING|OAEPWITHSHA-1ANDMGF1PADDING|OAEPWITHSHA-224ANDMGF1PADDING|OAEPWITHSHA-256ANDMGF1PADDING|OAEPWITHSHA-384ANDMGF1PADDING|OAEPWITHSHA-512ANDMGF1PADDING|OAEPWITHSHA-512/224ANDMGF1PADDING|OAEPWITHSHA-512/256ANDMGF1PADDING"_s);
	attrs->put("SupportedKeyClasses"_s, "java.security.interfaces.RSAPublicKey|java.security.interfaces.RSAPrivateKey"_s);
	ps("Cipher"_s, "RSA"_s, "com.sun.crypto.provider.RSACipher"_s, nullptr, attrs);
	$var($String, BLOCK_MODES, "ECB|CBC|PCBC|CTR|CTS|CFB|OFB|CFB8|CFB16|CFB24|CFB32|CFB40|CFB48|CFB56|CFB64|OFB8|OFB16|OFB24|OFB32|OFB40|OFB48|OFB56|OFB64"_s);
	$var($String, BLOCK_MODES128, $str({BLOCK_MODES, "|CFB72|CFB80|CFB88|CFB96|CFB104|CFB112|CFB120|CFB128|OFB72|OFB80|OFB88|OFB96|OFB104|OFB112|OFB120|OFB128"_s}));
	$var($String, BLOCK_PADS, "NOPADDING|PKCS5PADDING|ISO10126PADDING"_s);
	attrs->clear();
	attrs->put("SupportedModes"_s, BLOCK_MODES);
	attrs->put("SupportedPaddings"_s, BLOCK_PADS);
	attrs->put("SupportedKeyFormats"_s, "RAW"_s);
	ps("Cipher"_s, "DES"_s, "com.sun.crypto.provider.DESCipher"_s, nullptr, attrs);
	psA("Cipher"_s, "DESede"_s, "com.sun.crypto.provider.DESedeCipher"_s, attrs);
	ps("Cipher"_s, "Blowfish"_s, "com.sun.crypto.provider.BlowfishCipher"_s, nullptr, attrs);
	ps("Cipher"_s, "RC2"_s, "com.sun.crypto.provider.RC2Cipher"_s, nullptr, attrs);
	attrs->clear();
	attrs->put("SupportedModes"_s, BLOCK_MODES128);
	attrs->put("SupportedPaddings"_s, BLOCK_PADS);
	attrs->put("SupportedKeyFormats"_s, "RAW"_s);
	psA("Cipher"_s, "AES"_s, "com.sun.crypto.provider.AESCipher$General"_s, attrs);
	attrs->clear();
	attrs->put("SupportedKeyFormats"_s, "RAW"_s);
	psA("Cipher"_s, "AES/KW/NoPadding"_s, "com.sun.crypto.provider.KeyWrapCipher$AES_KW_NoPadding"_s, attrs);
	ps("Cipher"_s, "AES/KW/PKCS5Padding"_s, "com.sun.crypto.provider.KeyWrapCipher$AES_KW_PKCS5Padding"_s, nullptr, attrs);
	psA("Cipher"_s, "AES/KWP/NoPadding"_s, "com.sun.crypto.provider.KeyWrapCipher$AES_KWP_NoPadding"_s, attrs);
	psA("Cipher"_s, "AES_128/ECB/NoPadding"_s, "com.sun.crypto.provider.AESCipher$AES128_ECB_NoPadding"_s, attrs);
	psA("Cipher"_s, "AES_128/CBC/NoPadding"_s, "com.sun.crypto.provider.AESCipher$AES128_CBC_NoPadding"_s, attrs);
	psA("Cipher"_s, "AES_128/OFB/NoPadding"_s, "com.sun.crypto.provider.AESCipher$AES128_OFB_NoPadding"_s, attrs);
	psA("Cipher"_s, "AES_128/CFB/NoPadding"_s, "com.sun.crypto.provider.AESCipher$AES128_CFB_NoPadding"_s, attrs);
	psA("Cipher"_s, "AES_128/KW/NoPadding"_s, "com.sun.crypto.provider.KeyWrapCipher$AES128_KW_NoPadding"_s, attrs);
	ps("Cipher"_s, "AES_128/KW/PKCS5Padding"_s, "com.sun.crypto.provider.KeyWrapCipher$AES128_KW_PKCS5Padding"_s, nullptr, attrs);
	psA("Cipher"_s, "AES_128/KWP/NoPadding"_s, "com.sun.crypto.provider.KeyWrapCipher$AES128_KWP_NoPadding"_s, attrs);
	psA("Cipher"_s, "AES_192/ECB/NoPadding"_s, "com.sun.crypto.provider.AESCipher$AES192_ECB_NoPadding"_s, attrs);
	psA("Cipher"_s, "AES_192/CBC/NoPadding"_s, "com.sun.crypto.provider.AESCipher$AES192_CBC_NoPadding"_s, attrs);
	psA("Cipher"_s, "AES_192/OFB/NoPadding"_s, "com.sun.crypto.provider.AESCipher$AES192_OFB_NoPadding"_s, attrs);
	psA("Cipher"_s, "AES_192/CFB/NoPadding"_s, "com.sun.crypto.provider.AESCipher$AES192_CFB_NoPadding"_s, attrs);
	psA("Cipher"_s, "AES_192/KW/NoPadding"_s, "com.sun.crypto.provider.KeyWrapCipher$AES192_KW_NoPadding"_s, attrs);
	ps("Cipher"_s, "AES_192/KW/PKCS5Padding"_s, "com.sun.crypto.provider.KeyWrapCipher$AES192_KW_PKCS5Padding"_s, nullptr, attrs);
	psA("Cipher"_s, "AES_192/KWP/NoPadding"_s, "com.sun.crypto.provider.KeyWrapCipher$AES192_KWP_NoPadding"_s, attrs);
	psA("Cipher"_s, "AES_256/ECB/NoPadding"_s, "com.sun.crypto.provider.AESCipher$AES256_ECB_NoPadding"_s, attrs);
	psA("Cipher"_s, "AES_256/CBC/NoPadding"_s, "com.sun.crypto.provider.AESCipher$AES256_CBC_NoPadding"_s, attrs);
	psA("Cipher"_s, "AES_256/OFB/NoPadding"_s, "com.sun.crypto.provider.AESCipher$AES256_OFB_NoPadding"_s, attrs);
	psA("Cipher"_s, "AES_256/CFB/NoPadding"_s, "com.sun.crypto.provider.AESCipher$AES256_CFB_NoPadding"_s, attrs);
	psA("Cipher"_s, "AES_256/KW/NoPadding"_s, "com.sun.crypto.provider.KeyWrapCipher$AES256_KW_NoPadding"_s, attrs);
	ps("Cipher"_s, "AES_256/KW/PKCS5Padding"_s, "com.sun.crypto.provider.KeyWrapCipher$AES256_KW_PKCS5Padding"_s, nullptr, attrs);
	psA("Cipher"_s, "AES_256/KWP/NoPadding"_s, "com.sun.crypto.provider.KeyWrapCipher$AES256_KWP_NoPadding"_s, attrs);
	attrs->clear();
	attrs->put("SupportedModes"_s, "GCM"_s);
	attrs->put("SupportedKeyFormats"_s, "RAW"_s);
	ps("Cipher"_s, "AES/GCM/NoPadding"_s, "com.sun.crypto.provider.GaloisCounterMode$AESGCM"_s, nullptr, attrs);
	psA("Cipher"_s, "AES_128/GCM/NoPadding"_s, "com.sun.crypto.provider.GaloisCounterMode$AES128"_s, attrs);
	psA("Cipher"_s, "AES_192/GCM/NoPadding"_s, "com.sun.crypto.provider.GaloisCounterMode$AES192"_s, attrs);
	psA("Cipher"_s, "AES_256/GCM/NoPadding"_s, "com.sun.crypto.provider.GaloisCounterMode$AES256"_s, attrs);
	attrs->clear();
	attrs->put("SupportedModes"_s, "CBC"_s);
	attrs->put("SupportedPaddings"_s, "NOPADDING"_s);
	attrs->put("SupportedKeyFormats"_s, "RAW"_s);
	ps("Cipher"_s, "DESedeWrap"_s, "com.sun.crypto.provider.DESedeWrapCipher"_s, nullptr, attrs);
	attrs->clear();
	attrs->put("SupportedModes"_s, "ECB"_s);
	attrs->put("SupportedPaddings"_s, "NOPADDING"_s);
	attrs->put("SupportedKeyFormats"_s, "RAW"_s);
	psA("Cipher"_s, "ARCFOUR"_s, "com.sun.crypto.provider.ARCFOURCipher"_s, attrs);
	attrs->clear();
	attrs->put("SupportedKeyFormats"_s, "RAW"_s);
	ps("Cipher"_s, "ChaCha20"_s, "com.sun.crypto.provider.ChaCha20Cipher$ChaCha20Only"_s, nullptr, attrs);
	psA("Cipher"_s, "ChaCha20-Poly1305"_s, "com.sun.crypto.provider.ChaCha20Cipher$ChaCha20Poly1305"_s, attrs);
	psA("Cipher"_s, "PBEWithMD5AndDES"_s, "com.sun.crypto.provider.PBEWithMD5AndDESCipher"_s, nullptr);
	ps("Cipher"_s, "PBEWithMD5AndTripleDES"_s, "com.sun.crypto.provider.PBEWithMD5AndTripleDESCipher"_s);
	psA("Cipher"_s, "PBEWithSHA1AndDESede"_s, "com.sun.crypto.provider.PKCS12PBECipherCore$PBEWithSHA1AndDESede"_s, nullptr);
	psA("Cipher"_s, "PBEWithSHA1AndRC2_40"_s, "com.sun.crypto.provider.PKCS12PBECipherCore$PBEWithSHA1AndRC2_40"_s, nullptr);
	psA("Cipher"_s, "PBEWithSHA1AndRC2_128"_s, "com.sun.crypto.provider.PKCS12PBECipherCore$PBEWithSHA1AndRC2_128"_s, nullptr);
	psA("Cipher"_s, "PBEWithSHA1AndRC4_40"_s, "com.sun.crypto.provider.PKCS12PBECipherCore$PBEWithSHA1AndRC4_40"_s, nullptr);
	psA("Cipher"_s, "PBEWithSHA1AndRC4_128"_s, "com.sun.crypto.provider.PKCS12PBECipherCore$PBEWithSHA1AndRC4_128"_s, nullptr);
	ps("Cipher"_s, "PBEWithHmacSHA1AndAES_128"_s, "com.sun.crypto.provider.PBES2Core$HmacSHA1AndAES_128"_s);
	ps("Cipher"_s, "PBEWithHmacSHA224AndAES_128"_s, "com.sun.crypto.provider.PBES2Core$HmacSHA224AndAES_128"_s);
	ps("Cipher"_s, "PBEWithHmacSHA256AndAES_128"_s, "com.sun.crypto.provider.PBES2Core$HmacSHA256AndAES_128"_s);
	ps("Cipher"_s, "PBEWithHmacSHA384AndAES_128"_s, "com.sun.crypto.provider.PBES2Core$HmacSHA384AndAES_128"_s);
	ps("Cipher"_s, "PBEWithHmacSHA512AndAES_128"_s, "com.sun.crypto.provider.PBES2Core$HmacSHA512AndAES_128"_s);
	ps("Cipher"_s, "PBEWithHmacSHA1AndAES_256"_s, "com.sun.crypto.provider.PBES2Core$HmacSHA1AndAES_256"_s);
	ps("Cipher"_s, "PBEWithHmacSHA224AndAES_256"_s, "com.sun.crypto.provider.PBES2Core$HmacSHA224AndAES_256"_s);
	ps("Cipher"_s, "PBEWithHmacSHA256AndAES_256"_s, "com.sun.crypto.provider.PBES2Core$HmacSHA256AndAES_256"_s);
	ps("Cipher"_s, "PBEWithHmacSHA384AndAES_256"_s, "com.sun.crypto.provider.PBES2Core$HmacSHA384AndAES_256"_s);
	ps("Cipher"_s, "PBEWithHmacSHA512AndAES_256"_s, "com.sun.crypto.provider.PBES2Core$HmacSHA512AndAES_256"_s);
	ps("KeyGenerator"_s, "DES"_s, "com.sun.crypto.provider.DESKeyGenerator"_s);
	psA("KeyGenerator"_s, "DESede"_s, "com.sun.crypto.provider.DESedeKeyGenerator"_s, nullptr);
	ps("KeyGenerator"_s, "Blowfish"_s, "com.sun.crypto.provider.BlowfishKeyGenerator"_s);
	psA("KeyGenerator"_s, "AES"_s, "com.sun.crypto.provider.AESKeyGenerator"_s, nullptr);
	ps("KeyGenerator"_s, "RC2"_s, "com.sun.crypto.provider.KeyGeneratorCore$RC2KeyGenerator"_s);
	psA("KeyGenerator"_s, "ARCFOUR"_s, "com.sun.crypto.provider.KeyGeneratorCore$ARCFOURKeyGenerator"_s, nullptr);
	ps("KeyGenerator"_s, "ChaCha20"_s, "com.sun.crypto.provider.KeyGeneratorCore$ChaCha20KeyGenerator"_s);
	ps("KeyGenerator"_s, "HmacMD5"_s, "com.sun.crypto.provider.HmacMD5KeyGenerator"_s);
	psA("KeyGenerator"_s, "HmacSHA1"_s, "com.sun.crypto.provider.HmacSHA1KeyGenerator"_s, nullptr);
	psA("KeyGenerator"_s, "HmacSHA224"_s, "com.sun.crypto.provider.KeyGeneratorCore$HmacKG$SHA224"_s, nullptr);
	psA("KeyGenerator"_s, "HmacSHA256"_s, "com.sun.crypto.provider.KeyGeneratorCore$HmacKG$SHA256"_s, nullptr);
	psA("KeyGenerator"_s, "HmacSHA384"_s, "com.sun.crypto.provider.KeyGeneratorCore$HmacKG$SHA384"_s, nullptr);
	psA("KeyGenerator"_s, "HmacSHA512"_s, "com.sun.crypto.provider.KeyGeneratorCore$HmacKG$SHA512"_s, nullptr);
	psA("KeyGenerator"_s, "HmacSHA512/224"_s, "com.sun.crypto.provider.KeyGeneratorCore$HmacKG$SHA512_224"_s, nullptr);
	psA("KeyGenerator"_s, "HmacSHA512/256"_s, "com.sun.crypto.provider.KeyGeneratorCore$HmacKG$SHA512_256"_s, nullptr);
	psA("KeyGenerator"_s, "HmacSHA3-224"_s, "com.sun.crypto.provider.KeyGeneratorCore$HmacKG$SHA3_224"_s, nullptr);
	psA("KeyGenerator"_s, "HmacSHA3-256"_s, "com.sun.crypto.provider.KeyGeneratorCore$HmacKG$SHA3_256"_s, nullptr);
	psA("KeyGenerator"_s, "HmacSHA3-384"_s, "com.sun.crypto.provider.KeyGeneratorCore$HmacKG$SHA3_384"_s, nullptr);
	psA("KeyGenerator"_s, "HmacSHA3-512"_s, "com.sun.crypto.provider.KeyGeneratorCore$HmacKG$SHA3_512"_s, nullptr);
	psA("KeyPairGenerator"_s, "DiffieHellman"_s, "com.sun.crypto.provider.DHKeyPairGenerator"_s, nullptr);
	psA("AlgorithmParameterGenerator"_s, "DiffieHellman"_s, "com.sun.crypto.provider.DHParameterGenerator"_s, nullptr);
	attrs->clear();
	attrs->put("SupportedKeyClasses"_s, "javax.crypto.interfaces.DHPublicKey|javax.crypto.interfaces.DHPrivateKey"_s);
	psA("KeyAgreement"_s, "DiffieHellman"_s, "com.sun.crypto.provider.DHKeyAgreement"_s, attrs);
	psA("AlgorithmParameters"_s, "DiffieHellman"_s, "com.sun.crypto.provider.DHParameters"_s, nullptr);
	ps("AlgorithmParameters"_s, "DES"_s, "com.sun.crypto.provider.DESParameters"_s);
	psA("AlgorithmParameters"_s, "DESede"_s, "com.sun.crypto.provider.DESedeParameters"_s, nullptr);
	psA("AlgorithmParameters"_s, "PBEWithMD5AndDES"_s, "com.sun.crypto.provider.PBEParameters"_s, nullptr);
	ps("AlgorithmParameters"_s, "PBEWithMD5AndTripleDES"_s, "com.sun.crypto.provider.PBEParameters"_s);
	psA("AlgorithmParameters"_s, "PBEWithSHA1AndDESede"_s, "com.sun.crypto.provider.PBEParameters"_s, nullptr);
	psA("AlgorithmParameters"_s, "PBEWithSHA1AndRC2_40"_s, "com.sun.crypto.provider.PBEParameters"_s, nullptr);
	psA("AlgorithmParameters"_s, "PBEWithSHA1AndRC2_128"_s, "com.sun.crypto.provider.PBEParameters"_s, nullptr);
	psA("AlgorithmParameters"_s, "PBEWithSHA1AndRC4_40"_s, "com.sun.crypto.provider.PBEParameters"_s, nullptr);
	psA("AlgorithmParameters"_s, "PBEWithSHA1AndRC4_128"_s, "com.sun.crypto.provider.PBEParameters"_s, nullptr);
	psA("AlgorithmParameters"_s, "PBES2"_s, "com.sun.crypto.provider.PBES2Parameters$General"_s, nullptr);
	ps("AlgorithmParameters"_s, "PBEWithHmacSHA1AndAES_128"_s, "com.sun.crypto.provider.PBES2Parameters$HmacSHA1AndAES_128"_s);
	ps("AlgorithmParameters"_s, "PBEWithHmacSHA224AndAES_128"_s, "com.sun.crypto.provider.PBES2Parameters$HmacSHA224AndAES_128"_s);
	ps("AlgorithmParameters"_s, "PBEWithHmacSHA256AndAES_128"_s, "com.sun.crypto.provider.PBES2Parameters$HmacSHA256AndAES_128"_s);
	ps("AlgorithmParameters"_s, "PBEWithHmacSHA384AndAES_128"_s, "com.sun.crypto.provider.PBES2Parameters$HmacSHA384AndAES_128"_s);
	ps("AlgorithmParameters"_s, "PBEWithHmacSHA512AndAES_128"_s, "com.sun.crypto.provider.PBES2Parameters$HmacSHA512AndAES_128"_s);
	ps("AlgorithmParameters"_s, "PBEWithHmacSHA1AndAES_256"_s, "com.sun.crypto.provider.PBES2Parameters$HmacSHA1AndAES_256"_s);
	ps("AlgorithmParameters"_s, "PBEWithHmacSHA224AndAES_256"_s, "com.sun.crypto.provider.PBES2Parameters$HmacSHA224AndAES_256"_s);
	ps("AlgorithmParameters"_s, "PBEWithHmacSHA256AndAES_256"_s, "com.sun.crypto.provider.PBES2Parameters$HmacSHA256AndAES_256"_s);
	ps("AlgorithmParameters"_s, "PBEWithHmacSHA384AndAES_256"_s, "com.sun.crypto.provider.PBES2Parameters$HmacSHA384AndAES_256"_s);
	ps("AlgorithmParameters"_s, "PBEWithHmacSHA512AndAES_256"_s, "com.sun.crypto.provider.PBES2Parameters$HmacSHA512AndAES_256"_s);
	ps("AlgorithmParameters"_s, "Blowfish"_s, "com.sun.crypto.provider.BlowfishParameters"_s);
	psA("AlgorithmParameters"_s, "AES"_s, "com.sun.crypto.provider.AESParameters"_s, nullptr);
	ps("AlgorithmParameters"_s, "GCM"_s, "com.sun.crypto.provider.GCMParameters"_s);
	ps("AlgorithmParameters"_s, "RC2"_s, "com.sun.crypto.provider.RC2Parameters"_s);
	ps("AlgorithmParameters"_s, "OAEP"_s, "com.sun.crypto.provider.OAEPParameters"_s);
	psA("AlgorithmParameters"_s, "ChaCha20-Poly1305"_s, "com.sun.crypto.provider.ChaCha20Poly1305Parameters"_s, nullptr);
	psA("KeyFactory"_s, "DiffieHellman"_s, "com.sun.crypto.provider.DHKeyFactory"_s, nullptr);
	ps("SecretKeyFactory"_s, "DES"_s, "com.sun.crypto.provider.DESKeyFactory"_s);
	psA("SecretKeyFactory"_s, "DESede"_s, "com.sun.crypto.provider.DESedeKeyFactory"_s, nullptr);
	psA("SecretKeyFactory"_s, "PBEWithMD5AndDES"_s, "com.sun.crypto.provider.PBEKeyFactory$PBEWithMD5AndDES"_s, nullptr);
	ps("SecretKeyFactory"_s, "PBEWithMD5AndTripleDES"_s, "com.sun.crypto.provider.PBEKeyFactory$PBEWithMD5AndTripleDES"_s);
	psA("SecretKeyFactory"_s, "PBEWithSHA1AndDESede"_s, "com.sun.crypto.provider.PBEKeyFactory$PBEWithSHA1AndDESede"_s, nullptr);
	psA("SecretKeyFactory"_s, "PBEWithSHA1AndRC2_40"_s, "com.sun.crypto.provider.PBEKeyFactory$PBEWithSHA1AndRC2_40"_s, nullptr);
	psA("SecretKeyFactory"_s, "PBEWithSHA1AndRC2_128"_s, "com.sun.crypto.provider.PBEKeyFactory$PBEWithSHA1AndRC2_128"_s, nullptr);
	psA("SecretKeyFactory"_s, "PBEWithSHA1AndRC4_40"_s, "com.sun.crypto.provider.PBEKeyFactory$PBEWithSHA1AndRC4_40"_s, nullptr);
	psA("SecretKeyFactory"_s, "PBEWithSHA1AndRC4_128"_s, "com.sun.crypto.provider.PBEKeyFactory$PBEWithSHA1AndRC4_128"_s, nullptr);
	ps("SecretKeyFactory"_s, "PBEWithHmacSHA1AndAES_128"_s, "com.sun.crypto.provider.PBEKeyFactory$PBEWithHmacSHA1AndAES_128"_s);
	ps("SecretKeyFactory"_s, "PBEWithHmacSHA224AndAES_128"_s, "com.sun.crypto.provider.PBEKeyFactory$PBEWithHmacSHA224AndAES_128"_s);
	ps("SecretKeyFactory"_s, "PBEWithHmacSHA256AndAES_128"_s, "com.sun.crypto.provider.PBEKeyFactory$PBEWithHmacSHA256AndAES_128"_s);
	ps("SecretKeyFactory"_s, "PBEWithHmacSHA384AndAES_128"_s, "com.sun.crypto.provider.PBEKeyFactory$PBEWithHmacSHA384AndAES_128"_s);
	ps("SecretKeyFactory"_s, "PBEWithHmacSHA512AndAES_128"_s, "com.sun.crypto.provider.PBEKeyFactory$PBEWithHmacSHA512AndAES_128"_s);
	ps("SecretKeyFactory"_s, "PBEWithHmacSHA1AndAES_256"_s, "com.sun.crypto.provider.PBEKeyFactory$PBEWithHmacSHA1AndAES_256"_s);
	ps("SecretKeyFactory"_s, "PBEWithHmacSHA224AndAES_256"_s, "com.sun.crypto.provider.PBEKeyFactory$PBEWithHmacSHA224AndAES_256"_s);
	ps("SecretKeyFactory"_s, "PBEWithHmacSHA256AndAES_256"_s, "com.sun.crypto.provider.PBEKeyFactory$PBEWithHmacSHA256AndAES_256"_s);
	ps("SecretKeyFactory"_s, "PBEWithHmacSHA384AndAES_256"_s, "com.sun.crypto.provider.PBEKeyFactory$PBEWithHmacSHA384AndAES_256"_s);
	ps("SecretKeyFactory"_s, "PBEWithHmacSHA512AndAES_256"_s, "com.sun.crypto.provider.PBEKeyFactory$PBEWithHmacSHA512AndAES_256"_s);
	psA("SecretKeyFactory"_s, "PBKDF2WithHmacSHA1"_s, "com.sun.crypto.provider.PBKDF2Core$HmacSHA1"_s, nullptr);
	ps("SecretKeyFactory"_s, "PBKDF2WithHmacSHA224"_s, "com.sun.crypto.provider.PBKDF2Core$HmacSHA224"_s);
	ps("SecretKeyFactory"_s, "PBKDF2WithHmacSHA256"_s, "com.sun.crypto.provider.PBKDF2Core$HmacSHA256"_s);
	ps("SecretKeyFactory"_s, "PBKDF2WithHmacSHA384"_s, "com.sun.crypto.provider.PBKDF2Core$HmacSHA384"_s);
	ps("SecretKeyFactory"_s, "PBKDF2WithHmacSHA512"_s, "com.sun.crypto.provider.PBKDF2Core$HmacSHA512"_s);
	attrs->clear();
	attrs->put("SupportedKeyFormats"_s, "RAW"_s);
	ps("Mac"_s, "HmacMD5"_s, "com.sun.crypto.provider.HmacMD5"_s, nullptr, attrs);
	psA("Mac"_s, "HmacSHA1"_s, "com.sun.crypto.provider.HmacSHA1"_s, attrs);
	psA("Mac"_s, "HmacSHA224"_s, "com.sun.crypto.provider.HmacCore$HmacSHA224"_s, attrs);
	psA("Mac"_s, "HmacSHA256"_s, "com.sun.crypto.provider.HmacCore$HmacSHA256"_s, attrs);
	psA("Mac"_s, "HmacSHA384"_s, "com.sun.crypto.provider.HmacCore$HmacSHA384"_s, attrs);
	psA("Mac"_s, "HmacSHA512"_s, "com.sun.crypto.provider.HmacCore$HmacSHA512"_s, attrs);
	psA("Mac"_s, "HmacSHA512/224"_s, "com.sun.crypto.provider.HmacCore$HmacSHA512_224"_s, attrs);
	psA("Mac"_s, "HmacSHA512/256"_s, "com.sun.crypto.provider.HmacCore$HmacSHA512_256"_s, attrs);
	psA("Mac"_s, "HmacSHA3-224"_s, "com.sun.crypto.provider.HmacCore$HmacSHA3_224"_s, attrs);
	psA("Mac"_s, "HmacSHA3-256"_s, "com.sun.crypto.provider.HmacCore$HmacSHA3_256"_s, attrs);
	psA("Mac"_s, "HmacSHA3-384"_s, "com.sun.crypto.provider.HmacCore$HmacSHA3_384"_s, attrs);
	psA("Mac"_s, "HmacSHA3-512"_s, "com.sun.crypto.provider.HmacCore$HmacSHA3_512"_s, attrs);
	ps("Mac"_s, "HmacPBESHA1"_s, "com.sun.crypto.provider.HmacPKCS12PBECore$HmacPKCS12PBE_SHA1"_s, nullptr, attrs);
	ps("Mac"_s, "HmacPBESHA224"_s, "com.sun.crypto.provider.HmacPKCS12PBECore$HmacPKCS12PBE_SHA224"_s, nullptr, attrs);
	ps("Mac"_s, "HmacPBESHA256"_s, "com.sun.crypto.provider.HmacPKCS12PBECore$HmacPKCS12PBE_SHA256"_s, nullptr, attrs);
	ps("Mac"_s, "HmacPBESHA384"_s, "com.sun.crypto.provider.HmacPKCS12PBECore$HmacPKCS12PBE_SHA384"_s, nullptr, attrs);
	ps("Mac"_s, "HmacPBESHA512"_s, "com.sun.crypto.provider.HmacPKCS12PBECore$HmacPKCS12PBE_SHA512"_s, nullptr, attrs);
	ps("Mac"_s, "HmacPBESHA512/224"_s, "com.sun.crypto.provider.HmacPKCS12PBECore$HmacPKCS12PBE_SHA512_224"_s, nullptr, attrs);
	ps("Mac"_s, "HmacPBESHA512/256"_s, "com.sun.crypto.provider.HmacPKCS12PBECore$HmacPKCS12PBE_SHA512_256"_s, nullptr, attrs);
	ps("Mac"_s, "PBEWithHmacSHA1"_s, "com.sun.crypto.provider.PBMAC1Core$HmacSHA1"_s, nullptr, attrs);
	ps("Mac"_s, "PBEWithHmacSHA224"_s, "com.sun.crypto.provider.PBMAC1Core$HmacSHA224"_s, nullptr, attrs);
	ps("Mac"_s, "PBEWithHmacSHA256"_s, "com.sun.crypto.provider.PBMAC1Core$HmacSHA256"_s, nullptr, attrs);
	ps("Mac"_s, "PBEWithHmacSHA384"_s, "com.sun.crypto.provider.PBMAC1Core$HmacSHA384"_s, nullptr, attrs);
	ps("Mac"_s, "PBEWithHmacSHA512"_s, "com.sun.crypto.provider.PBMAC1Core$HmacSHA512"_s, nullptr, attrs);
	ps("Mac"_s, "SslMacMD5"_s, "com.sun.crypto.provider.SslMacCore$SslMacMD5"_s, nullptr, attrs);
	ps("Mac"_s, "SslMacSHA1"_s, "com.sun.crypto.provider.SslMacCore$SslMacSHA1"_s, nullptr, attrs);
	ps("KeyStore"_s, "JCEKS"_s, "com.sun.crypto.provider.JceKeyStore"_s);
	ps("KeyGenerator"_s, "SunTlsPrf"_s, "com.sun.crypto.provider.TlsPrfGenerator$V10"_s);
	ps("KeyGenerator"_s, "SunTls12Prf"_s, "com.sun.crypto.provider.TlsPrfGenerator$V12"_s);
	ps("KeyGenerator"_s, "SunTlsMasterSecret"_s, "com.sun.crypto.provider.TlsMasterSecretGenerator"_s, $($List::of("SunTls12MasterSecret"_s, "SunTlsExtendedMasterSecret"_s)), nullptr);
	ps("KeyGenerator"_s, "SunTlsKeyMaterial"_s, "com.sun.crypto.provider.TlsKeyMaterialGenerator"_s, $($List::of($of("SunTls12KeyMaterial"_s))), nullptr);
	ps("KeyGenerator"_s, "SunTlsRsaPremasterSecret"_s, "com.sun.crypto.provider.TlsRsaPremasterSecretGenerator"_s, $($List::of($of("SunTls12RsaPremasterSecret"_s))), nullptr);
}

SunJCE* SunJCE::getInstance() {
	$init(SunJCE);
	if (SunJCE::instance == nullptr) {
		return $new(SunJCE);
	}
	return SunJCE::instance;
}

SunJCE::SunJCE() {
}

void clinit$SunJCE($Class* class$) {
	$assignStatic(SunJCE::info, "SunJCE Provider (implements RSA, DES, Triple DES, AES, Blowfish, ARCFOUR, RC2, PBE, Diffie-Hellman, HMAC, ChaCha20)"_s);
}

$Class* SunJCE::load$($String* name, bool initialize) {
	$loadClass(SunJCE, name, initialize, &_SunJCE_ClassInfo_, clinit$SunJCE, allocate$SunJCE);
	return class$;
}

$Class* SunJCE::class$ = nullptr;

			} // provider
		} // crypto
	} // sun
} // com