#include <javax/crypto/Cipher.h>

#include <java/lang/AssertionError.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/SecurityException.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/ReadOnlyBufferException.h>
#include <java/security/AlgorithmParameters.h>
#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/InvalidParameterException.h>
#include <java/security/Key.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/NoSuchProviderException.h>
#include <java/security/Permission.h>
#include <java/security/Provider$Service.h>
#include <java/security/Provider.h>
#include <java/security/ProviderException.h>
#include <java/security/PublicKey.h>
#include <java/security/SecureRandom.h>
#include <java/security/Security.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/X509Certificate.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/security/spec/InvalidParameterSpecException.h>
#include <java/util/ArrayList.h>
#include <java/util/Collections.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/NoSuchElementException.h>
#include <java/util/Set.h>
#include <java/util/StringTokenizer.h>
#include <javax/crypto/Cipher$Transform.h>
#include <javax/crypto/CipherSpi.h>
#include <javax/crypto/CryptoAllPermission.h>
#include <javax/crypto/CryptoPermission.h>
#include <javax/crypto/ExemptionMechanism.h>
#include <javax/crypto/ExemptionMechanismException.h>
#include <javax/crypto/JceSecurity.h>
#include <javax/crypto/JceSecurityManager.h>
#include <javax/crypto/NoSuchPaddingException.h>
#include <javax/crypto/NullCipher.h>
#include <javax/crypto/spec/IvParameterSpec.h>
#include <javax/crypto/spec/PBEParameterSpec.h>
#include <javax/crypto/spec/RC2ParameterSpec.h>
#include <javax/crypto/spec/RC5ParameterSpec.h>
#include <sun/security/jca/GetInstance.h>
#include <sun/security/jca/JCAUtil.h>
#include <sun/security/jca/ServiceId.h>
#include <sun/security/util/Debug.h>
#include <sun/security/util/KnownOIDs.h>
#include <jcpp.h>

#undef ATTR_MODE
#undef ATTR_PAD
#undef DECRYPT_MODE
#undef ENCRYPT_MODE
#undef ENGLISH
#undef INSTANCE
#undef I_CERT
#undef I_KEY
#undef I_PARAMS
#undef I_PARAMSPEC
#undef PRIVATE_KEY
#undef PUBLIC_KEY
#undef SECRET_KEY
#undef S_MAYBE
#undef S_NO
#undef S_YES
#undef UNWRAP_MODE
#undef WRAP_MODE

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $RuntimeException = ::java::lang::RuntimeException;
using $SecurityException = ::java::lang::SecurityException;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $ReadOnlyBufferException = ::java::nio::ReadOnlyBufferException;
using $AlgorithmParameters = ::java::security::AlgorithmParameters;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $InvalidParameterException = ::java::security::InvalidParameterException;
using $Key = ::java::security::Key;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $NoSuchProviderException = ::java::security::NoSuchProviderException;
using $Permission = ::java::security::Permission;
using $Provider = ::java::security::Provider;
using $Provider$Service = ::java::security::Provider$Service;
using $ProviderException = ::java::security::ProviderException;
using $PublicKey = ::java::security::PublicKey;
using $SecureRandom = ::java::security::SecureRandom;
using $Security = ::java::security::Security;
using $Certificate = ::java::security::cert::Certificate;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $InvalidParameterSpecException = ::java::security::spec::InvalidParameterSpecException;
using $ArrayList = ::java::util::ArrayList;
using $Collections = ::java::util::Collections;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $NoSuchElementException = ::java::util::NoSuchElementException;
using $Set = ::java::util::Set;
using $StringTokenizer = ::java::util::StringTokenizer;
using $Cipher$Transform = ::javax::crypto::Cipher$Transform;
using $CipherSpi = ::javax::crypto::CipherSpi;
using $CryptoAllPermission = ::javax::crypto::CryptoAllPermission;
using $CryptoPermission = ::javax::crypto::CryptoPermission;
using $ExemptionMechanism = ::javax::crypto::ExemptionMechanism;
using $ExemptionMechanismException = ::javax::crypto::ExemptionMechanismException;
using $JceSecurity = ::javax::crypto::JceSecurity;
using $JceSecurityManager = ::javax::crypto::JceSecurityManager;
using $NoSuchPaddingException = ::javax::crypto::NoSuchPaddingException;
using $NullCipher = ::javax::crypto::NullCipher;
using $IvParameterSpec = ::javax::crypto::spec::IvParameterSpec;
using $PBEParameterSpec = ::javax::crypto::spec::PBEParameterSpec;
using $RC2ParameterSpec = ::javax::crypto::spec::RC2ParameterSpec;
using $RC5ParameterSpec = ::javax::crypto::spec::RC5ParameterSpec;
using $GetInstance = ::sun::security::jca::GetInstance;
using $JCAUtil = ::sun::security::jca::JCAUtil;
using $ServiceId = ::sun::security::jca::ServiceId;
using $Debug = ::sun::security::util::Debug;
using $KnownOIDs = ::sun::security::util::KnownOIDs;

namespace javax {
	namespace crypto {

$FieldInfo _Cipher_FieldInfo_[] = {
	{"debug", "Lsun/security/util/Debug;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Cipher, debug)},
	{"pdebug", "Lsun/security/util/Debug;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Cipher, pdebug)},
	{"skipDebug", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Cipher, skipDebug)},
	{"ENCRYPT_MODE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Cipher, ENCRYPT_MODE)},
	{"DECRYPT_MODE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Cipher, DECRYPT_MODE)},
	{"WRAP_MODE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Cipher, WRAP_MODE)},
	{"UNWRAP_MODE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Cipher, UNWRAP_MODE)},
	{"PUBLIC_KEY", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Cipher, PUBLIC_KEY)},
	{"PRIVATE_KEY", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Cipher, PRIVATE_KEY)},
	{"SECRET_KEY", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Cipher, SECRET_KEY)},
	{"provider", "Ljava/security/Provider;", nullptr, $PRIVATE, $field(Cipher, provider)},
	{"spi", "Ljavax/crypto/CipherSpi;", nullptr, $PRIVATE, $field(Cipher, spi)},
	{"transformation", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Cipher, transformation)},
	{"cryptoPerm", "Ljavax/crypto/CryptoPermission;", nullptr, $PRIVATE, $field(Cipher, cryptoPerm)},
	{"exmech", "Ljavax/crypto/ExemptionMechanism;", nullptr, $PRIVATE, $field(Cipher, exmech)},
	{"initialized", "Z", nullptr, $PRIVATE, $field(Cipher, initialized)},
	{"opmode", "I", nullptr, $PRIVATE, $field(Cipher, opmode)},
	{"firstSpi", "Ljavax/crypto/CipherSpi;", nullptr, $PRIVATE, $field(Cipher, firstSpi)},
	{"firstService", "Ljava/security/Provider$Service;", nullptr, $PRIVATE, $field(Cipher, firstService)},
	{"serviceIterator", "Ljava/util/Iterator;", "Ljava/util/Iterator<Ljava/security/Provider$Service;>;", $PRIVATE, $field(Cipher, serviceIterator)},
	{"transforms", "Ljava/util/List;", "Ljava/util/List<Ljavax/crypto/Cipher$Transform;>;", $PRIVATE, $field(Cipher, transforms)},
	{"lock", "Ljava/lang/Object;", nullptr, $PRIVATE | $FINAL, $field(Cipher, lock)},
	{"ATTR_MODE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Cipher, ATTR_MODE)},
	{"ATTR_PAD", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Cipher, ATTR_PAD)},
	{"S_NO", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Cipher, S_NO)},
	{"S_MAYBE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Cipher, S_MAYBE)},
	{"S_YES", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Cipher, S_YES)},
	{"warnCount", "I", nullptr, $PRIVATE | $STATIC, $staticField(Cipher, warnCount)},
	{"I_KEY", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Cipher, I_KEY)},
	{"I_PARAMSPEC", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Cipher, I_PARAMSPEC)},
	{"I_PARAMS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Cipher, I_PARAMS)},
	{"I_CERT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Cipher, I_CERT)},
	{}
};

$MethodInfo _Cipher_MethodInfo_[] = {
	{"<init>", "(Ljavax/crypto/CipherSpi;Ljava/security/Provider;Ljava/lang/String;)V", nullptr, $PROTECTED, $method(Cipher, init$, void, $CipherSpi*, $Provider*, $String*)},
	{"<init>", "(Ljavax/crypto/CipherSpi;Ljava/lang/String;)V", nullptr, 0, $method(Cipher, init$, void, $CipherSpi*, $String*)},
	{"<init>", "(Ljavax/crypto/CipherSpi;Ljava/security/Provider$Service;Ljava/util/Iterator;Ljava/lang/String;Ljava/util/List;)V", "(Ljavax/crypto/CipherSpi;Ljava/security/Provider$Service;Ljava/util/Iterator<Ljava/security/Provider$Service;>;Ljava/lang/String;Ljava/util/List<Ljavax/crypto/Cipher$Transform;>;)V", $PRIVATE, $method(Cipher, init$, void, $CipherSpi*, $Provider$Service*, $Iterator*, $String*, $List*)},
	{"checkCipherState", "()V", nullptr, $PRIVATE, $method(Cipher, checkCipherState, void)},
	{"checkCryptoPerm", "(Ljavax/crypto/CipherSpi;Ljava/security/Key;)V", nullptr, $PRIVATE, $method(Cipher, checkCryptoPerm, void, $CipherSpi*, $Key*), "java.security.InvalidKeyException"},
	{"checkCryptoPerm", "(Ljavax/crypto/CipherSpi;Ljava/security/Key;Ljava/security/spec/AlgorithmParameterSpec;)V", nullptr, $PRIVATE, $method(Cipher, checkCryptoPerm, void, $CipherSpi*, $Key*, $AlgorithmParameterSpec*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"checkCryptoPerm", "(Ljavax/crypto/CipherSpi;Ljava/security/Key;Ljava/security/AlgorithmParameters;)V", nullptr, $PRIVATE, $method(Cipher, checkCryptoPerm, void, $CipherSpi*, $Key*, $AlgorithmParameters*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"checkOpmode", "(I)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Cipher, checkOpmode, void, int32_t)},
	{"chooseFirstProvider", "()V", nullptr, 0, $virtualMethod(Cipher, chooseFirstProvider, void)},
	{"chooseProvider", "(IILjava/security/Key;Ljava/security/spec/AlgorithmParameterSpec;Ljava/security/AlgorithmParameters;Ljava/security/SecureRandom;)V", nullptr, $PRIVATE, $method(Cipher, chooseProvider, void, int32_t, int32_t, $Key*, $AlgorithmParameterSpec*, $AlgorithmParameters*, $SecureRandom*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"doFinal", "()[B", nullptr, $PUBLIC | $FINAL, $method(Cipher, doFinal, $bytes*), "javax.crypto.IllegalBlockSizeException,javax.crypto.BadPaddingException"},
	{"doFinal", "([BI)I", nullptr, $PUBLIC | $FINAL, $method(Cipher, doFinal, int32_t, $bytes*, int32_t), "javax.crypto.IllegalBlockSizeException,javax.crypto.ShortBufferException,javax.crypto.BadPaddingException"},
	{"doFinal", "([B)[B", nullptr, $PUBLIC | $FINAL, $method(Cipher, doFinal, $bytes*, $bytes*), "javax.crypto.IllegalBlockSizeException,javax.crypto.BadPaddingException"},
	{"doFinal", "([BII)[B", nullptr, $PUBLIC | $FINAL, $method(Cipher, doFinal, $bytes*, $bytes*, int32_t, int32_t), "javax.crypto.IllegalBlockSizeException,javax.crypto.BadPaddingException"},
	{"doFinal", "([BII[B)I", nullptr, $PUBLIC | $FINAL, $method(Cipher, doFinal, int32_t, $bytes*, int32_t, int32_t, $bytes*), "javax.crypto.ShortBufferException,javax.crypto.IllegalBlockSizeException,javax.crypto.BadPaddingException"},
	{"doFinal", "([BII[BI)I", nullptr, $PUBLIC | $FINAL, $method(Cipher, doFinal, int32_t, $bytes*, int32_t, int32_t, $bytes*, int32_t), "javax.crypto.ShortBufferException,javax.crypto.IllegalBlockSizeException,javax.crypto.BadPaddingException"},
	{"doFinal", "(Ljava/nio/ByteBuffer;Ljava/nio/ByteBuffer;)I", nullptr, $PUBLIC | $FINAL, $method(Cipher, doFinal, int32_t, $ByteBuffer*, $ByteBuffer*), "javax.crypto.ShortBufferException,javax.crypto.IllegalBlockSizeException,javax.crypto.BadPaddingException"},
	{"getAlgorithm", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL, $method(Cipher, getAlgorithm, $String*)},
	{"getAlgorithmParameterSpec", "(Ljava/security/AlgorithmParameters;)Ljava/security/spec/AlgorithmParameterSpec;", nullptr, $PRIVATE, $method(Cipher, getAlgorithmParameterSpec, $AlgorithmParameterSpec*, $AlgorithmParameters*), "java.security.spec.InvalidParameterSpecException"},
	{"getBlockSize", "()I", nullptr, $PUBLIC | $FINAL, $method(Cipher, getBlockSize, int32_t)},
	{"getConfiguredPermission", "(Ljava/lang/String;)Ljavax/crypto/CryptoPermission;", nullptr, $PRIVATE | $STATIC, $staticMethod(Cipher, getConfiguredPermission, $CryptoPermission*, $String*), "java.lang.NullPointerException,java.security.NoSuchAlgorithmException"},
	{"getExemptionMechanism", "()Ljavax/crypto/ExemptionMechanism;", nullptr, $PUBLIC | $FINAL, $method(Cipher, getExemptionMechanism, $ExemptionMechanism*)},
	{"getIV", "()[B", nullptr, $PUBLIC | $FINAL, $method(Cipher, getIV, $bytes*)},
	{"getInstance", "(Ljava/lang/String;)Ljavax/crypto/Cipher;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticMethod(Cipher, getInstance, Cipher*, $String*), "java.security.NoSuchAlgorithmException,javax.crypto.NoSuchPaddingException"},
	{"getInstance", "(Ljava/lang/String;Ljava/lang/String;)Ljavax/crypto/Cipher;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticMethod(Cipher, getInstance, Cipher*, $String*, $String*), "java.security.NoSuchAlgorithmException,java.security.NoSuchProviderException,javax.crypto.NoSuchPaddingException"},
	{"getInstance", "(Ljava/lang/String;Ljava/security/Provider;)Ljavax/crypto/Cipher;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticMethod(Cipher, getInstance, Cipher*, $String*, $Provider*), "java.security.NoSuchAlgorithmException,javax.crypto.NoSuchPaddingException"},
	{"getMaxAllowedKeyLength", "(Ljava/lang/String;)I", nullptr, $PUBLIC | $STATIC | $FINAL, $staticMethod(Cipher, getMaxAllowedKeyLength, int32_t, $String*), "java.security.NoSuchAlgorithmException"},
	{"getMaxAllowedParameterSpec", "(Ljava/lang/String;)Ljava/security/spec/AlgorithmParameterSpec;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticMethod(Cipher, getMaxAllowedParameterSpec, $AlgorithmParameterSpec*, $String*), "java.security.NoSuchAlgorithmException"},
	{"getOutputSize", "(I)I", nullptr, $PUBLIC | $FINAL, $method(Cipher, getOutputSize, int32_t, int32_t)},
	{"getParameters", "()Ljava/security/AlgorithmParameters;", nullptr, $PUBLIC | $FINAL, $method(Cipher, getParameters, $AlgorithmParameters*)},
	{"getProvider", "()Ljava/security/Provider;", nullptr, $PUBLIC | $FINAL, $method(Cipher, getProvider, $Provider*)},
	{"getProviderName", "()Ljava/lang/String;", nullptr, $PRIVATE, $method(Cipher, getProviderName, $String*)},
	{"getTransform", "(Ljava/security/Provider$Service;Ljava/util/List;)Ljavax/crypto/Cipher$Transform;", "(Ljava/security/Provider$Service;Ljava/util/List<Ljavax/crypto/Cipher$Transform;>;)Ljavax/crypto/Cipher$Transform;", $PRIVATE | $STATIC, $staticMethod(Cipher, getTransform, $Cipher$Transform*, $Provider$Service*, $List*)},
	{"getTransforms", "(Ljava/lang/String;)Ljava/util/List;", "(Ljava/lang/String;)Ljava/util/List<Ljavax/crypto/Cipher$Transform;>;", $PRIVATE | $STATIC, $staticMethod(Cipher, getTransforms, $List*, $String*), "java.security.NoSuchAlgorithmException"},
	{"implInit", "(Ljavax/crypto/CipherSpi;IILjava/security/Key;Ljava/security/spec/AlgorithmParameterSpec;Ljava/security/AlgorithmParameters;Ljava/security/SecureRandom;)V", nullptr, $PRIVATE, $method(Cipher, implInit, void, $CipherSpi*, int32_t, int32_t, $Key*, $AlgorithmParameterSpec*, $AlgorithmParameters*, $SecureRandom*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"init", "(ILjava/security/Key;)V", nullptr, $PUBLIC | $FINAL, $method(Cipher, init, void, int32_t, $Key*), "java.security.InvalidKeyException"},
	{"init", "(ILjava/security/Key;Ljava/security/SecureRandom;)V", nullptr, $PUBLIC | $FINAL, $method(Cipher, init, void, int32_t, $Key*, $SecureRandom*), "java.security.InvalidKeyException"},
	{"init", "(ILjava/security/Key;Ljava/security/spec/AlgorithmParameterSpec;)V", nullptr, $PUBLIC | $FINAL, $method(Cipher, init, void, int32_t, $Key*, $AlgorithmParameterSpec*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"init", "(ILjava/security/Key;Ljava/security/spec/AlgorithmParameterSpec;Ljava/security/SecureRandom;)V", nullptr, $PUBLIC | $FINAL, $method(Cipher, init, void, int32_t, $Key*, $AlgorithmParameterSpec*, $SecureRandom*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"init", "(ILjava/security/Key;Ljava/security/AlgorithmParameters;)V", nullptr, $PUBLIC | $FINAL, $method(Cipher, init, void, int32_t, $Key*, $AlgorithmParameters*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"init", "(ILjava/security/Key;Ljava/security/AlgorithmParameters;Ljava/security/SecureRandom;)V", nullptr, $PUBLIC | $FINAL, $method(Cipher, init, void, int32_t, $Key*, $AlgorithmParameters*, $SecureRandom*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"init", "(ILjava/security/cert/Certificate;)V", nullptr, $PUBLIC | $FINAL, $method(Cipher, init, void, int32_t, $Certificate*), "java.security.InvalidKeyException"},
	{"init", "(ILjava/security/cert/Certificate;Ljava/security/SecureRandom;)V", nullptr, $PUBLIC | $FINAL, $method(Cipher, init, void, int32_t, $Certificate*, $SecureRandom*), "java.security.InvalidKeyException"},
	{"initCryptoPermission", "()V", nullptr, $PRIVATE, $method(Cipher, initCryptoPermission, void), "java.security.NoSuchAlgorithmException"},
	{"passCryptoPermCheck", "(Ljavax/crypto/CipherSpi;Ljava/security/Key;Ljava/security/spec/AlgorithmParameterSpec;)Z", nullptr, $PRIVATE, $method(Cipher, passCryptoPermCheck, bool, $CipherSpi*, $Key*, $AlgorithmParameterSpec*), "java.security.InvalidKeyException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Cipher, toString, $String*)},
	{"tokenizeTransformation", "(Ljava/lang/String;)[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(Cipher, tokenizeTransformation, $StringArray*, $String*), "java.security.NoSuchAlgorithmException"},
	{"unwrap", "([BLjava/lang/String;I)Ljava/security/Key;", nullptr, $PUBLIC | $FINAL, $method(Cipher, unwrap, $Key*, $bytes*, $String*, int32_t), "java.security.InvalidKeyException,java.security.NoSuchAlgorithmException"},
	{"update", "([B)[B", nullptr, $PUBLIC | $FINAL, $method(Cipher, update, $bytes*, $bytes*)},
	{"update", "([BII)[B", nullptr, $PUBLIC | $FINAL, $method(Cipher, update, $bytes*, $bytes*, int32_t, int32_t)},
	{"update", "([BII[B)I", nullptr, $PUBLIC | $FINAL, $method(Cipher, update, int32_t, $bytes*, int32_t, int32_t, $bytes*), "javax.crypto.ShortBufferException"},
	{"update", "([BII[BI)I", nullptr, $PUBLIC | $FINAL, $method(Cipher, update, int32_t, $bytes*, int32_t, int32_t, $bytes*, int32_t), "javax.crypto.ShortBufferException"},
	{"update", "(Ljava/nio/ByteBuffer;Ljava/nio/ByteBuffer;)I", nullptr, $PUBLIC | $FINAL, $method(Cipher, update, int32_t, $ByteBuffer*, $ByteBuffer*), "javax.crypto.ShortBufferException"},
	{"updateAAD", "([B)V", nullptr, $PUBLIC | $FINAL, $method(Cipher, updateAAD, void, $bytes*)},
	{"updateAAD", "([BII)V", nullptr, $PUBLIC | $FINAL, $method(Cipher, updateAAD, void, $bytes*, int32_t, int32_t)},
	{"updateAAD", "(Ljava/nio/ByteBuffer;)V", nullptr, $PUBLIC | $FINAL, $method(Cipher, updateAAD, void, $ByteBuffer*)},
	{"wrap", "(Ljava/security/Key;)[B", nullptr, $PUBLIC | $FINAL, $method(Cipher, wrap, $bytes*, $Key*), "javax.crypto.IllegalBlockSizeException,java.security.InvalidKeyException"},
	{}
};

$InnerClassInfo _Cipher_InnerClassesInfo_[] = {
	{"javax.crypto.Cipher$Transform", "javax.crypto.Cipher", "Transform", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _Cipher_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"javax.crypto.Cipher",
	"java.lang.Object",
	nullptr,
	_Cipher_FieldInfo_,
	_Cipher_MethodInfo_,
	nullptr,
	nullptr,
	_Cipher_InnerClassesInfo_,
	nullptr,
	nullptr,
	"javax.crypto.Cipher$Transform"
};

$Object* allocate$Cipher($Class* clazz) {
	return $of($alloc(Cipher));
}

$Debug* Cipher::debug = nullptr;
$Debug* Cipher::pdebug = nullptr;
bool Cipher::skipDebug = false;
$String* Cipher::ATTR_MODE = nullptr;
$String* Cipher::ATTR_PAD = nullptr;
int32_t Cipher::warnCount = 0;

void Cipher::init$($CipherSpi* cipherSpi, $Provider* provider, $String* transformation) {
	this->initialized = false;
	this->opmode = 0;
	$init($JceSecurityManager);
	if (!$nc($JceSecurityManager::INSTANCE)->isCallerTrusted(provider)) {
		$throwNew($IllegalArgumentException, "Cannot construct cipher"_s);
	}
	$set(this, spi, cipherSpi);
	$set(this, provider, provider);
	$set(this, transformation, transformation);
	$init($CryptoAllPermission);
	$set(this, cryptoPerm, $CryptoAllPermission::INSTANCE);
	$set(this, lock, nullptr);
}

void Cipher::init$($CipherSpi* cipherSpi, $String* transformation) {
	this->initialized = false;
	this->opmode = 0;
	$set(this, spi, cipherSpi);
	$set(this, transformation, transformation);
	$init($CryptoAllPermission);
	$set(this, cryptoPerm, $CryptoAllPermission::INSTANCE);
	$set(this, lock, nullptr);
}

void Cipher::init$($CipherSpi* firstSpi, $Provider$Service* firstService, $Iterator* serviceIterator, $String* transformation, $List* transforms) {
	this->initialized = false;
	this->opmode = 0;
	$set(this, firstSpi, firstSpi);
	$set(this, firstService, firstService);
	$set(this, serviceIterator, serviceIterator);
	$set(this, transforms, transforms);
	$set(this, transformation, transformation);
	$set(this, lock, $new($Object));
}

$StringArray* Cipher::tokenizeTransformation($String* transformation) {
	$init(Cipher);
	$useLocalCurrentObjectStackCache();
	if (transformation == nullptr) {
		$throwNew($NoSuchAlgorithmException, "No transformation given"_s);
	}
	$var($StringArray, parts, $new($StringArray, 3));
	int32_t count = 0;
	$var($StringTokenizer, parser, $new($StringTokenizer, transformation, "/"_s));
	try {
		while (parser->hasMoreTokens() && count < 3) {
			parts->set(count++, $($nc($(parser->nextToken()))->trim()));
		}
		if (count == 0 || count == 2) {
			$throwNew($NoSuchAlgorithmException, $$str({"Invalid transformation format:"_s, transformation}));
		}
		if (count == 3 && parser->hasMoreTokens()) {
			parts->set(2, $$str({parts->get(2), $(parser->nextToken("\r\n"_s))}));
		}
	} catch ($NoSuchElementException& e) {
		$throwNew($NoSuchAlgorithmException, $$str({"Invalid transformation format:"_s, transformation}));
	}
	if ((parts->get(0) == nullptr) || ($nc(parts->get(0))->isEmpty())) {
		$throwNew($NoSuchAlgorithmException, $$str({"Invalid transformation:algorithm not specified-"_s, transformation}));
	}
	return parts;
}

$List* Cipher::getTransforms($String* transformation) {
	$init(Cipher);
	$useLocalCurrentObjectStackCache();
	$var($StringArray, parts, tokenizeTransformation(transformation));
	$var($String, alg, $nc(parts)->get(0));
	$var($String, mode, parts->get(1));
	$var($String, pad, parts->get(2));
	if ((mode != nullptr) && (mode->isEmpty())) {
		$assign(mode, nullptr);
	}
	if ((pad != nullptr) && (pad->isEmpty())) {
		$assign(pad, nullptr);
	}
	if ((mode == nullptr) && (pad == nullptr)) {
		$var($Cipher$Transform, tr, $new($Cipher$Transform, alg, ""_s, nullptr, nullptr));
		return $Collections::singletonList(tr);
	} else {
		$var($List, list, $new($ArrayList, 4));
		list->add($$new($Cipher$Transform, alg, $$str({"/"_s, mode, "/"_s, pad}), nullptr, nullptr));
		list->add($$new($Cipher$Transform, alg, $$str({"/"_s, mode}), nullptr, pad));
		list->add($$new($Cipher$Transform, alg, $$str({"//"_s, pad}), mode, nullptr));
		list->add($$new($Cipher$Transform, alg, ""_s, mode, pad));
		return list;
	}
}

$Cipher$Transform* Cipher::getTransform($Provider$Service* s, $List* transforms) {
	$init(Cipher);
	$useLocalCurrentObjectStackCache();
	$init($Locale);
	$var($String, alg, $nc($($nc(s)->getAlgorithm()))->toUpperCase($Locale::ENGLISH));
	{
		$var($Iterator, i$, $nc(transforms)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Cipher$Transform, tr, $cast($Cipher$Transform, i$->next()));
			{
				if (alg->endsWith($nc(tr)->suffix)) {
					return tr;
				}
			}
		}
	}
	return nullptr;
}

Cipher* Cipher::getInstance($String* transformation) {
	$init(Cipher);
	$useLocalCurrentObjectStackCache();
	if ((transformation == nullptr) || $nc(transformation)->isEmpty()) {
		$throwNew($NoSuchAlgorithmException, "Null or empty transformation"_s);
	}
	$var($List, transforms, getTransforms(transformation));
	$var($List, cipherServices, $new($ArrayList, $nc(transforms)->size()));
	{
		$var($Iterator, i$, $nc(transforms)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Cipher$Transform, transform, $cast($Cipher$Transform, i$->next()));
			{
				cipherServices->add($$new($ServiceId, "Cipher"_s, $nc(transform)->transform));
			}
		}
	}
	$var($List, services, $GetInstance::getServices(cipherServices));
	$var($Iterator, t, $nc(services)->iterator());
	$var($Exception, failure, nullptr);
	while ($nc(t)->hasNext()) {
		$var($Provider$Service, s, $cast($Provider$Service, t->next()));
		if ($JceSecurity::canUseProvider($($nc(s)->getProvider())) == false) {
			continue;
		}
		$var($Cipher$Transform, tr, getTransform(s, transforms));
		if (tr == nullptr) {
			continue;
		}
		int32_t canuse = $nc(tr)->supportsModePadding(s);
		if (canuse == Cipher::S_NO) {
			continue;
		}
		try {
			$var($CipherSpi, spi, $cast($CipherSpi, $nc(s)->newInstance(nullptr)));
			tr->setModePadding(spi);
			return $new(Cipher, nullptr, s, t, transformation, transforms);
		} catch ($Exception& e) {
			$assign(failure, e);
		}
	}
	$throwNew($NoSuchAlgorithmException, $$str({"Cannot find any provider supporting "_s, transformation}), failure);
	$shouldNotReachHere();
}

Cipher* Cipher::getInstance($String* transformation, $String* provider) {
	$init(Cipher);
	$useLocalCurrentObjectStackCache();
	if ((transformation == nullptr) || $nc(transformation)->isEmpty()) {
		$throwNew($NoSuchAlgorithmException, "Null or empty transformation"_s);
	}
	if ((provider == nullptr) || ($nc(provider)->isEmpty())) {
		$throwNew($IllegalArgumentException, "Missing provider"_s);
	}
	$var($Provider, p, $Security::getProvider(provider));
	if (p == nullptr) {
		$throwNew($NoSuchProviderException, $$str({"No such provider: "_s, provider}));
	}
	return getInstance(transformation, p);
}

$String* Cipher::getProviderName() {
	return (this->provider == nullptr) ? "(no provider)"_s : $nc(this->provider)->getName();
}

Cipher* Cipher::getInstance($String* transformation, $Provider* provider) {
	$init(Cipher);
	$useLocalCurrentObjectStackCache();
	if ((transformation == nullptr) || $nc(transformation)->isEmpty()) {
		$throwNew($NoSuchAlgorithmException, "Null or empty transformation"_s);
	}
	if (provider == nullptr) {
		$throwNew($IllegalArgumentException, "Missing provider"_s);
	}
	$var($Exception, failure, nullptr);
	$var($List, transforms, getTransforms(transformation));
	bool providerChecked = false;
	$var($String, paddingError, nullptr);
	{
		$var($Iterator, i$, $nc(transforms)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Cipher$Transform, tr, $cast($Cipher$Transform, i$->next()));
			{
				$var($Provider$Service, s, $nc(provider)->getService("Cipher"_s, $nc(tr)->transform));
				if (s == nullptr) {
					continue;
				}
				if (providerChecked == false) {
					$var($Exception, ve, $JceSecurity::getVerificationResult(provider));
					if (ve != nullptr) {
						$var($String, msg, $str({"JCE cannot authenticate the provider "_s, $(provider->getName())}));
						$throwNew($SecurityException, msg, ve);
					}
					providerChecked = true;
				}
				if ($nc(tr)->supportsMode(s) == Cipher::S_NO) {
					continue;
				}
				if ($nc(tr)->supportsPadding(s) == Cipher::S_NO) {
					$assign(paddingError, tr->pad);
					continue;
				}
				try {
					$var($CipherSpi, spi, $cast($CipherSpi, $nc(s)->newInstance(nullptr)));
					$nc(tr)->setModePadding(spi);
					$var(Cipher, cipher, $new(Cipher, spi, transformation));
					$set(cipher, provider, s->getProvider());
					cipher->initCryptoPermission();
					return cipher;
				} catch ($Exception& e) {
					$assign(failure, e);
				}
			}
		}
	}
	if ($instanceOf($NoSuchPaddingException, failure)) {
		$throw($cast($NoSuchPaddingException, failure));
	}
	if (paddingError != nullptr) {
		$throwNew($NoSuchPaddingException, $$str({"Padding not supported: "_s, paddingError}));
	}
	$throwNew($NoSuchAlgorithmException, $$str({"No such algorithm: "_s, transformation}), failure);
	$shouldNotReachHere();
}

void Cipher::initCryptoPermission() {
	if ($JceSecurity::isRestricted() == false) {
		$init($CryptoAllPermission);
		$set(this, cryptoPerm, $CryptoAllPermission::INSTANCE);
		$set(this, exmech, nullptr);
		return;
	}
	$set(this, cryptoPerm, getConfiguredPermission(this->transformation));
	$var($String, exmechName, $nc(this->cryptoPerm)->getExemptionMechanism());
	if (exmechName != nullptr) {
		$set(this, exmech, $ExemptionMechanism::getInstance(exmechName));
	}
}

void Cipher::chooseFirstProvider() {
	$useLocalCurrentObjectStackCache();
	if (this->spi != nullptr) {
		return;
	}
	$synchronized(this->lock) {
		if (this->spi != nullptr) {
			return;
		}
		if (Cipher::debug != nullptr) {
			int32_t w = --Cipher::warnCount;
			if (w >= 0) {
				$nc(Cipher::debug)->println("Cipher.init() not first method called, disabling delayed provider selection"_s);
				if (w == 0) {
					$nc(Cipher::debug)->println("Further warnings of this type will be suppressed"_s);
				}
				$$new($Exception, "Call trace"_s)->printStackTrace();
			}
		}
		$var($Exception, lastException, nullptr);
		while ((this->firstService != nullptr) || $nc(this->serviceIterator)->hasNext()) {
			$var($Provider$Service, s, nullptr);
			$var($CipherSpi, thisSpi, nullptr);
			if (this->firstService != nullptr) {
				$assign(s, this->firstService);
				$assign(thisSpi, this->firstSpi);
				$set(this, firstService, nullptr);
				$set(this, firstSpi, nullptr);
			} else {
				$assign(s, $cast($Provider$Service, $nc(this->serviceIterator)->next()));
				$assign(thisSpi, nullptr);
			}
			if ($JceSecurity::canUseProvider($($nc(s)->getProvider())) == false) {
				continue;
			}
			$var($Cipher$Transform, tr, getTransform(s, this->transforms));
			if (tr == nullptr) {
				continue;
			}
			if ($nc(tr)->supportsModePadding(s) == Cipher::S_NO) {
				continue;
			}
			try {
				if (thisSpi == nullptr) {
					$var($Object, obj, $nc(s)->newInstance(nullptr));
					if ($instanceOf($CipherSpi, obj) == false) {
						continue;
					}
					$assign(thisSpi, $cast($CipherSpi, obj));
				}
				$nc(tr)->setModePadding(thisSpi);
				initCryptoPermission();
				$set(this, spi, thisSpi);
				$set(this, provider, $nc(s)->getProvider());
				$set(this, firstService, nullptr);
				$set(this, serviceIterator, nullptr);
				$set(this, transforms, nullptr);
				return;
			} catch ($Exception& e) {
				$assign(lastException, e);
			}
		}
		$var($ProviderException, e, $new($ProviderException, "Could not construct CipherSpi instance"_s));
		if (lastException != nullptr) {
			e->initCause(lastException);
		}
		$throw(e);
	}
}

void Cipher::implInit($CipherSpi* thisSpi, int32_t type, int32_t opmode, $Key* key, $AlgorithmParameterSpec* paramSpec, $AlgorithmParameters* params, $SecureRandom* random) {
	$useLocalCurrentObjectStackCache();
	switch (type) {
	case Cipher::I_KEY:
		{
			checkCryptoPerm(thisSpi, key);
			$nc(thisSpi)->engineInit(opmode, key, random);
			break;
		}
	case Cipher::I_PARAMSPEC:
		{
			checkCryptoPerm(thisSpi, key, paramSpec);
			$nc(thisSpi)->engineInit(opmode, key, paramSpec, random);
			break;
		}
	case Cipher::I_PARAMS:
		{
			checkCryptoPerm(thisSpi, key, params);
			$nc(thisSpi)->engineInit(opmode, key, params, random);
			break;
		}
	case Cipher::I_CERT:
		{
			checkCryptoPerm(thisSpi, key);
			$nc(thisSpi)->engineInit(opmode, key, random);
			break;
		}
	default:
		{
			$throwNew($AssertionError, $of($$str({"Internal Cipher error: "_s, $$str(type)})));
		}
	}
}

void Cipher::chooseProvider(int32_t initType, int32_t opmode, $Key* key, $AlgorithmParameterSpec* paramSpec, $AlgorithmParameters* params, $SecureRandom* random) {
	$useLocalCurrentObjectStackCache();
	$synchronized(this->lock) {
		if (this->spi != nullptr) {
			implInit(this->spi, initType, opmode, key, paramSpec, params, random);
			return;
		}
		$var($Exception, lastException, nullptr);
		while ((this->firstService != nullptr) || $nc(this->serviceIterator)->hasNext()) {
			$var($Provider$Service, s, nullptr);
			$var($CipherSpi, thisSpi, nullptr);
			if (this->firstService != nullptr) {
				$assign(s, this->firstService);
				$assign(thisSpi, this->firstSpi);
				$set(this, firstService, nullptr);
				$set(this, firstSpi, nullptr);
			} else {
				$assign(s, $cast($Provider$Service, $nc(this->serviceIterator)->next()));
				$assign(thisSpi, nullptr);
			}
			if ($nc(s)->supportsParameter(key) == false) {
				continue;
			}
			if ($JceSecurity::canUseProvider($($nc(s)->getProvider())) == false) {
				continue;
			}
			$var($Cipher$Transform, tr, getTransform(s, this->transforms));
			if (tr == nullptr) {
				continue;
			}
			if ($nc(tr)->supportsModePadding(s) == Cipher::S_NO) {
				continue;
			}
			try {
				if (thisSpi == nullptr) {
					$assign(thisSpi, $cast($CipherSpi, $nc(s)->newInstance(nullptr)));
				}
				$nc(tr)->setModePadding(thisSpi);
				initCryptoPermission();
				implInit(thisSpi, initType, opmode, key, paramSpec, params, random);
				$set(this, provider, $nc(s)->getProvider());
				$set(this, spi, thisSpi);
				$set(this, firstService, nullptr);
				$set(this, serviceIterator, nullptr);
				$set(this, transforms, nullptr);
				return;
			} catch ($Exception& e) {
				if (lastException == nullptr) {
					$assign(lastException, e);
				}
			}
		}
		if ($instanceOf($InvalidKeyException, lastException)) {
			$throw($cast($InvalidKeyException, lastException));
		}
		if ($instanceOf($InvalidAlgorithmParameterException, lastException)) {
			$throw($cast($InvalidAlgorithmParameterException, lastException));
		}
		if ($instanceOf($RuntimeException, lastException)) {
			$throw($cast($RuntimeException, lastException));
		}
		$var($String, kName, (key != nullptr) ? $nc($of(key))->getClass()->getName() : "(null)"_s);
		$throwNew($InvalidKeyException, $$str({"No installed provider supports this key: "_s, kName}), lastException);
	}
}

$Provider* Cipher::getProvider() {
	chooseFirstProvider();
	return this->provider;
}

$String* Cipher::getAlgorithm() {
	return this->transformation;
}

int32_t Cipher::getBlockSize() {
	chooseFirstProvider();
	return $nc(this->spi)->engineGetBlockSize();
}

int32_t Cipher::getOutputSize(int32_t inputLen) {
	if (!this->initialized && !($instanceOf($NullCipher, this))) {
		$throwNew($IllegalStateException, "Cipher not initialized"_s);
	}
	if (inputLen < 0) {
		$throwNew($IllegalArgumentException, "Input size must be equal to or greater than zero"_s);
	}
	chooseFirstProvider();
	return $nc(this->spi)->engineGetOutputSize(inputLen);
}

$bytes* Cipher::getIV() {
	chooseFirstProvider();
	return $nc(this->spi)->engineGetIV();
}

$AlgorithmParameters* Cipher::getParameters() {
	chooseFirstProvider();
	return $nc(this->spi)->engineGetParameters();
}

$ExemptionMechanism* Cipher::getExemptionMechanism() {
	chooseFirstProvider();
	return this->exmech;
}

void Cipher::checkCryptoPerm($CipherSpi* checkSpi, $Key* key) {
	$useLocalCurrentObjectStackCache();
	$init($CryptoAllPermission);
	if ($equals(this->cryptoPerm, $CryptoAllPermission::INSTANCE)) {
		return;
	}
	$var($AlgorithmParameterSpec, params, nullptr);
	try {
		$assign(params, getAlgorithmParameterSpec($($nc(checkSpi)->engineGetParameters())));
	} catch ($InvalidParameterSpecException& ipse) {
		$throwNew($InvalidKeyException, "Unsupported default algorithm parameters"_s);
	}
	if (!passCryptoPermCheck(checkSpi, key, params)) {
		$throwNew($InvalidKeyException, "Illegal key size or default parameters"_s);
	}
}

void Cipher::checkCryptoPerm($CipherSpi* checkSpi, $Key* key, $AlgorithmParameterSpec* params) {
	$init($CryptoAllPermission);
	if ($equals(this->cryptoPerm, $CryptoAllPermission::INSTANCE)) {
		return;
	}
	if (!passCryptoPermCheck(checkSpi, key, nullptr)) {
		$throwNew($InvalidKeyException, "Illegal key size"_s);
	}
	if ((params != nullptr) && (!passCryptoPermCheck(checkSpi, key, params))) {
		$throwNew($InvalidAlgorithmParameterException, "Illegal parameters"_s);
	}
}

void Cipher::checkCryptoPerm($CipherSpi* checkSpi, $Key* key, $AlgorithmParameters* params) {
	$init($CryptoAllPermission);
	if ($equals(this->cryptoPerm, $CryptoAllPermission::INSTANCE)) {
		return;
	}
	$var($AlgorithmParameterSpec, pSpec, nullptr);
	try {
		$assign(pSpec, getAlgorithmParameterSpec(params));
	} catch ($InvalidParameterSpecException& ipse) {
		$throwNew($InvalidAlgorithmParameterException, "Failed to retrieve algorithm parameter specification"_s);
	}
	checkCryptoPerm(checkSpi, key, pSpec);
}

bool Cipher::passCryptoPermCheck($CipherSpi* checkSpi, $Key* key, $AlgorithmParameterSpec* params) {
	$useLocalCurrentObjectStackCache();
	$var($String, em, $nc(this->cryptoPerm)->getExemptionMechanism());
	int32_t keySize = $nc(checkSpi)->engineGetKeySize(key);
	$var($String, algComponent, nullptr);
	int32_t index = $nc(this->transformation)->indexOf((int32_t)u'/');
	if (index != -1) {
		$assign(algComponent, $nc(this->transformation)->substring(0, index));
	} else {
		$assign(algComponent, this->transformation);
	}
	$var($CryptoPermission, checkPerm, $new($CryptoPermission, algComponent, keySize, params, em));
	if (!$nc(this->cryptoPerm)->implies(checkPerm)) {
		if (Cipher::debug != nullptr) {
			$nc(Cipher::debug)->println("Crypto Permission check failed"_s);
			$nc(Cipher::debug)->println($$str({"granted: "_s, this->cryptoPerm}));
			$nc(Cipher::debug)->println($$str({"requesting: "_s, checkPerm}));
		}
		return false;
	}
	if (this->exmech == nullptr) {
		return true;
	}
	try {
		if (!$nc(this->exmech)->isCryptoAllowed(key)) {
			if (Cipher::debug != nullptr) {
				$nc(Cipher::debug)->println($$str({$($nc(this->exmech)->getName()), " isn\'t enforced"_s}));
			}
			return false;
		}
	} catch ($ExemptionMechanismException& eme) {
		if (Cipher::debug != nullptr) {
			$nc(Cipher::debug)->println($$str({"Cannot determine whether "_s, $($nc(this->exmech)->getName()), " has been enforced"_s}));
			eme->printStackTrace();
		}
		return false;
	}
	return true;
}

void Cipher::checkOpmode(int32_t opmode) {
	$init(Cipher);
	if ((opmode < Cipher::ENCRYPT_MODE) || (opmode > Cipher::UNWRAP_MODE)) {
		$throwNew($InvalidParameterException, "Invalid operation mode"_s);
	}
}

void Cipher::init(int32_t opmode, $Key* key) {
	init(opmode, key, $($JCAUtil::getDefSecureRandom()));
}

void Cipher::init(int32_t opmode, $Key* key, $SecureRandom* random) {
	this->initialized = false;
	checkOpmode(opmode);
	if (this->spi != nullptr) {
		checkCryptoPerm(this->spi, key);
		$nc(this->spi)->engineInit(opmode, key, random);
	} else {
		try {
			chooseProvider(Cipher::I_KEY, opmode, key, nullptr, nullptr, random);
		} catch ($InvalidAlgorithmParameterException& e) {
			$throwNew($InvalidKeyException, static_cast<$Throwable*>(e));
		}
	}
	this->initialized = true;
	this->opmode = opmode;
	if (!Cipher::skipDebug && Cipher::pdebug != nullptr) {
		$nc(Cipher::pdebug)->println($(this->toString()));
	}
}

void Cipher::init(int32_t opmode, $Key* key, $AlgorithmParameterSpec* params) {
	init(opmode, key, params, $($JCAUtil::getDefSecureRandom()));
}

void Cipher::init(int32_t opmode, $Key* key, $AlgorithmParameterSpec* params, $SecureRandom* random) {
	this->initialized = false;
	checkOpmode(opmode);
	if (this->spi != nullptr) {
		checkCryptoPerm(this->spi, key, params);
		$nc(this->spi)->engineInit(opmode, key, params, random);
	} else {
		chooseProvider(Cipher::I_PARAMSPEC, opmode, key, params, nullptr, random);
	}
	this->initialized = true;
	this->opmode = opmode;
	if (!Cipher::skipDebug && Cipher::pdebug != nullptr) {
		$nc(Cipher::pdebug)->println($(this->toString()));
	}
}

void Cipher::init(int32_t opmode, $Key* key, $AlgorithmParameters* params) {
	init(opmode, key, params, $($JCAUtil::getDefSecureRandom()));
}

void Cipher::init(int32_t opmode, $Key* key, $AlgorithmParameters* params, $SecureRandom* random) {
	this->initialized = false;
	checkOpmode(opmode);
	if (this->spi != nullptr) {
		checkCryptoPerm(this->spi, key, params);
		$nc(this->spi)->engineInit(opmode, key, params, random);
	} else {
		chooseProvider(Cipher::I_PARAMS, opmode, key, nullptr, params, random);
	}
	this->initialized = true;
	this->opmode = opmode;
	if (!Cipher::skipDebug && Cipher::pdebug != nullptr) {
		$nc(Cipher::pdebug)->println($(this->toString()));
	}
}

void Cipher::init(int32_t opmode, $Certificate* certificate) {
	init(opmode, certificate, $($JCAUtil::getDefSecureRandom()));
}

void Cipher::init(int32_t opmode, $Certificate* certificate, $SecureRandom* random) {
	$useLocalCurrentObjectStackCache();
	this->initialized = false;
	checkOpmode(opmode);
	if ($instanceOf($X509Certificate, certificate)) {
		$var($X509Certificate, cert, $cast($X509Certificate, certificate));
		$var($Set, critSet, $nc(cert)->getCriticalExtensionOIDs());
		bool var$0 = critSet != nullptr && !critSet->isEmpty();
		$init($KnownOIDs);
		if (var$0 && critSet->contains($($KnownOIDs::KeyUsage->value()))) {
			$var($booleans, keyUsageInfo, cert->getKeyUsage());
			if ((keyUsageInfo != nullptr) && (((opmode == Cipher::ENCRYPT_MODE) && (keyUsageInfo->length > 3) && (keyUsageInfo->get(3) == false)) || ((opmode == Cipher::WRAP_MODE) && ($nc(keyUsageInfo)->length > 2) && (keyUsageInfo->get(2) == false)))) {
				$throwNew($InvalidKeyException, "Wrong key usage"_s);
			}
		}
	}
	$var($PublicKey, publicKey, certificate == nullptr ? ($PublicKey*)nullptr : $nc(certificate)->getPublicKey());
	if (this->spi != nullptr) {
		checkCryptoPerm(this->spi, publicKey);
		$nc(this->spi)->engineInit(opmode, publicKey, random);
	} else {
		try {
			chooseProvider(Cipher::I_CERT, opmode, publicKey, nullptr, nullptr, random);
		} catch ($InvalidAlgorithmParameterException& e) {
			$throwNew($InvalidKeyException, static_cast<$Throwable*>(e));
		}
	}
	this->initialized = true;
	this->opmode = opmode;
	if (!Cipher::skipDebug && Cipher::pdebug != nullptr) {
		$nc(Cipher::pdebug)->println($(this->toString()));
	}
}

void Cipher::checkCipherState() {
	if (!($instanceOf($NullCipher, this))) {
		if (!this->initialized) {
			$throwNew($IllegalStateException, "Cipher not initialized"_s);
		}
		if ((this->opmode != Cipher::ENCRYPT_MODE) && (this->opmode != Cipher::DECRYPT_MODE)) {
			$throwNew($IllegalStateException, "Cipher not initialized for encryption/decryption"_s);
		}
	}
}

$bytes* Cipher::update($bytes* input) {
	checkCipherState();
	if (input == nullptr) {
		$throwNew($IllegalArgumentException, "Null input buffer"_s);
	}
	chooseFirstProvider();
	if ($nc(input)->length == 0) {
		return nullptr;
	}
	return $nc(this->spi)->engineUpdate(input, 0, $nc(input)->length);
}

$bytes* Cipher::update($bytes* input, int32_t inputOffset, int32_t inputLen) {
	checkCipherState();
	if (input == nullptr || inputOffset < 0 || inputLen > ($nc(input)->length - inputOffset) || inputLen < 0) {
		$throwNew($IllegalArgumentException, "Bad arguments"_s);
	}
	chooseFirstProvider();
	if (inputLen == 0) {
		return nullptr;
	}
	return $nc(this->spi)->engineUpdate(input, inputOffset, inputLen);
}

int32_t Cipher::update($bytes* input, int32_t inputOffset, int32_t inputLen, $bytes* output) {
	checkCipherState();
	if (input == nullptr || inputOffset < 0 || inputLen > ($nc(input)->length - inputOffset) || inputLen < 0) {
		$throwNew($IllegalArgumentException, "Bad arguments"_s);
	}
	chooseFirstProvider();
	if (inputLen == 0) {
		return 0;
	}
	return $nc(this->spi)->engineUpdate(input, inputOffset, inputLen, output, 0);
}

int32_t Cipher::update($bytes* input, int32_t inputOffset, int32_t inputLen, $bytes* output, int32_t outputOffset) {
	checkCipherState();
	if (input == nullptr || inputOffset < 0 || inputLen > ($nc(input)->length - inputOffset) || inputLen < 0 || outputOffset < 0) {
		$throwNew($IllegalArgumentException, "Bad arguments"_s);
	}
	chooseFirstProvider();
	if (inputLen == 0) {
		return 0;
	}
	return $nc(this->spi)->engineUpdate(input, inputOffset, inputLen, output, outputOffset);
}

int32_t Cipher::update($ByteBuffer* input, $ByteBuffer* output) {
	checkCipherState();
	if ((input == nullptr) || (output == nullptr)) {
		$throwNew($IllegalArgumentException, "Buffers must not be null"_s);
	}
	if (input == output) {
		$throwNew($IllegalArgumentException, "Input and output buffers must not be the same object, consider using buffer.duplicate()"_s);
	}
	if ($nc(output)->isReadOnly()) {
		$throwNew($ReadOnlyBufferException);
	}
	chooseFirstProvider();
	return $nc(this->spi)->engineUpdate(input, output);
}

$bytes* Cipher::doFinal() {
	checkCipherState();
	chooseFirstProvider();
	return $nc(this->spi)->engineDoFinal(nullptr, 0, 0);
}

int32_t Cipher::doFinal($bytes* output, int32_t outputOffset) {
	checkCipherState();
	if ((output == nullptr) || (outputOffset < 0)) {
		$throwNew($IllegalArgumentException, "Bad arguments"_s);
	}
	chooseFirstProvider();
	return $nc(this->spi)->engineDoFinal(nullptr, 0, 0, output, outputOffset);
}

$bytes* Cipher::doFinal($bytes* input) {
	checkCipherState();
	if (input == nullptr) {
		$throwNew($IllegalArgumentException, "Null input buffer"_s);
	}
	chooseFirstProvider();
	return $nc(this->spi)->engineDoFinal(input, 0, $nc(input)->length);
}

$bytes* Cipher::doFinal($bytes* input, int32_t inputOffset, int32_t inputLen) {
	checkCipherState();
	if (input == nullptr || inputOffset < 0 || inputLen > ($nc(input)->length - inputOffset) || inputLen < 0) {
		$throwNew($IllegalArgumentException, "Bad arguments"_s);
	}
	chooseFirstProvider();
	return $nc(this->spi)->engineDoFinal(input, inputOffset, inputLen);
}

int32_t Cipher::doFinal($bytes* input, int32_t inputOffset, int32_t inputLen, $bytes* output) {
	checkCipherState();
	if (input == nullptr || inputOffset < 0 || inputLen > ($nc(input)->length - inputOffset) || inputLen < 0) {
		$throwNew($IllegalArgumentException, "Bad arguments"_s);
	}
	chooseFirstProvider();
	return $nc(this->spi)->engineDoFinal(input, inputOffset, inputLen, output, 0);
}

int32_t Cipher::doFinal($bytes* input, int32_t inputOffset, int32_t inputLen, $bytes* output, int32_t outputOffset) {
	checkCipherState();
	if (input == nullptr || inputOffset < 0 || inputLen > ($nc(input)->length - inputOffset) || inputLen < 0 || outputOffset < 0) {
		$throwNew($IllegalArgumentException, "Bad arguments"_s);
	}
	chooseFirstProvider();
	return $nc(this->spi)->engineDoFinal(input, inputOffset, inputLen, output, outputOffset);
}

int32_t Cipher::doFinal($ByteBuffer* input, $ByteBuffer* output) {
	checkCipherState();
	if ((input == nullptr) || (output == nullptr)) {
		$throwNew($IllegalArgumentException, "Buffers must not be null"_s);
	}
	if (input == output) {
		$throwNew($IllegalArgumentException, "Input and output buffers must not be the same object, consider using buffer.duplicate()"_s);
	}
	if ($nc(output)->isReadOnly()) {
		$throwNew($ReadOnlyBufferException);
	}
	chooseFirstProvider();
	return $nc(this->spi)->engineDoFinal(input, output);
}

$bytes* Cipher::wrap($Key* key) {
	if (!($instanceOf($NullCipher, this))) {
		if (!this->initialized) {
			$throwNew($IllegalStateException, "Cipher not initialized"_s);
		}
		if (this->opmode != Cipher::WRAP_MODE) {
			$throwNew($IllegalStateException, "Cipher not initialized for wrapping keys"_s);
		}
	}
	chooseFirstProvider();
	return $nc(this->spi)->engineWrap(key);
}

$Key* Cipher::unwrap($bytes* wrappedKey, $String* wrappedKeyAlgorithm, int32_t wrappedKeyType) {
	if (!($instanceOf($NullCipher, this))) {
		if (!this->initialized) {
			$throwNew($IllegalStateException, "Cipher not initialized"_s);
		}
		if (this->opmode != Cipher::UNWRAP_MODE) {
			$throwNew($IllegalStateException, "Cipher not initialized for unwrapping keys"_s);
		}
	}
	if ((wrappedKeyType != Cipher::SECRET_KEY) && (wrappedKeyType != Cipher::PRIVATE_KEY) && (wrappedKeyType != Cipher::PUBLIC_KEY)) {
		$throwNew($InvalidParameterException, "Invalid key type"_s);
	}
	chooseFirstProvider();
	return $nc(this->spi)->engineUnwrap(wrappedKey, wrappedKeyAlgorithm, wrappedKeyType);
}

$AlgorithmParameterSpec* Cipher::getAlgorithmParameterSpec($AlgorithmParameters* params) {
	$useLocalCurrentObjectStackCache();
	if (params == nullptr) {
		return nullptr;
	}
	$init($Locale);
	$var($String, alg, $nc($($nc(params)->getAlgorithm()))->toUpperCase($Locale::ENGLISH));
	if (alg->equalsIgnoreCase("RC2"_s)) {
		$load($RC2ParameterSpec);
		return params->getParameterSpec($RC2ParameterSpec::class$);
	}
	if (alg->equalsIgnoreCase("RC5"_s)) {
		$load($RC5ParameterSpec);
		return params->getParameterSpec($RC5ParameterSpec::class$);
	}
	if (alg->startsWith("PBE"_s)) {
		$load($PBEParameterSpec);
		return params->getParameterSpec($PBEParameterSpec::class$);
	}
	if (alg->startsWith("DES"_s)) {
		$load($IvParameterSpec);
		return params->getParameterSpec($IvParameterSpec::class$);
	}
	return nullptr;
}

$CryptoPermission* Cipher::getConfiguredPermission($String* transformation) {
	$init(Cipher);
	if (transformation == nullptr) {
		$throwNew($NullPointerException);
	}
	$var($StringArray, parts, tokenizeTransformation(transformation));
	$init($JceSecurityManager);
	return $nc($JceSecurityManager::INSTANCE)->getCryptoPermission($nc(parts)->get(0));
}

int32_t Cipher::getMaxAllowedKeyLength($String* transformation) {
	$init(Cipher);
	$var($CryptoPermission, cp, getConfiguredPermission(transformation));
	return $nc(cp)->getMaxKeySize();
}

$AlgorithmParameterSpec* Cipher::getMaxAllowedParameterSpec($String* transformation) {
	$init(Cipher);
	$var($CryptoPermission, cp, getConfiguredPermission(transformation));
	return $nc(cp)->getAlgorithmParameterSpec();
}

void Cipher::updateAAD($bytes* src) {
	if (src == nullptr) {
		$throwNew($IllegalArgumentException, "src buffer is null"_s);
	}
	updateAAD(src, 0, $nc(src)->length);
}

void Cipher::updateAAD($bytes* src, int32_t offset, int32_t len) {
	checkCipherState();
	if ((src == nullptr) || (offset < 0) || (len < 0) || len > ($nc(src)->length - offset)) {
		$throwNew($IllegalArgumentException, "Bad arguments"_s);
	}
	chooseFirstProvider();
	if (len == 0) {
		return;
	}
	$nc(this->spi)->engineUpdateAAD(src, offset, len);
}

void Cipher::updateAAD($ByteBuffer* src) {
	checkCipherState();
	if (src == nullptr) {
		$throwNew($IllegalArgumentException, "src ByteBuffer is null"_s);
	}
	chooseFirstProvider();
	if ($nc(src)->remaining() == 0) {
		return;
	}
	$nc(this->spi)->engineUpdateAAD(src);
}

$String* Cipher::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append("Cipher."_s)->append(this->transformation)->append(", mode: "_s);
	switch (this->opmode) {
	case 0:
		{
			sb->append("not initialized"_s);
			break;
		}
	case Cipher::ENCRYPT_MODE:
		{
			sb->append("encryption"_s);
			break;
		}
	case Cipher::DECRYPT_MODE:
		{
			sb->append("decryption"_s);
			break;
		}
	case Cipher::WRAP_MODE:
		{
			sb->append("key wrapping"_s);
			break;
		}
	case Cipher::UNWRAP_MODE:
		{
			sb->append("key unwrapping"_s);
			break;
		}
	default:
		{
			sb->append("error:"_s)->append($($Integer::toString(this->opmode)));
		}
	}
	sb->append(", algorithm from: "_s)->append($(getProviderName()));
	return sb->toString();
}

void clinit$Cipher($Class* class$) {
	$assignStatic(Cipher::ATTR_MODE, "SupportedModes"_s);
	$assignStatic(Cipher::ATTR_PAD, "SupportedPaddings"_s);
	$assignStatic(Cipher::debug, $Debug::getInstance("jca"_s, "Cipher"_s));
	$assignStatic(Cipher::pdebug, $Debug::getInstance("provider"_s, "Provider"_s));
	bool var$0 = $Debug::isOn("engine="_s);
	Cipher::skipDebug = var$0 && !$Debug::isOn("cipher"_s);
	Cipher::warnCount = 10;
}

Cipher::Cipher() {
}

$Class* Cipher::load$($String* name, bool initialize) {
	$loadClass(Cipher, name, initialize, &_Cipher_ClassInfo_, clinit$Cipher, allocate$Cipher);
	return class$;
}

$Class* Cipher::class$ = nullptr;

	} // crypto
} // javax