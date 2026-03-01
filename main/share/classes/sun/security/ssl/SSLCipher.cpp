#include <sun/security/ssl/SSLCipher.h>

#include <java/lang/CharSequence.h>
#include <java/lang/Enum.h>
#include <java/lang/Math.h>
#include <java/lang/NumberFormatException.h>
#include <java/nio/ByteBuffer.h>
#include <java/security/AccessController.h>
#include <java/security/Key.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/SecureRandom.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/util/AbstractMap$SimpleImmutableEntry.h>
#include <java/util/HashMap.h>
#include <java/util/Map$Entry.h>
#include <javax/crypto/BadPaddingException.h>
#include <javax/crypto/Cipher.h>
#include <javax/crypto/NoSuchPaddingException.h>
#include <javax/crypto/SecretKey.h>
#include <javax/crypto/spec/IvParameterSpec.h>
#include <sun/security/ssl/Authenticator$MAC.h>
#include <sun/security/ssl/Authenticator.h>
#include <sun/security/ssl/CipherSuite$MacAlg.h>
#include <sun/security/ssl/CipherType.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/SSLCipher$1.h>
#include <sun/security/ssl/SSLCipher$NullReadCipherGenerator.h>
#include <sun/security/ssl/SSLCipher$NullWriteCipherGenerator.h>
#include <sun/security/ssl/SSLCipher$ReadCipherGenerator.h>
#include <sun/security/ssl/SSLCipher$SSLReadCipher.h>
#include <sun/security/ssl/SSLCipher$SSLWriteCipher.h>
#include <sun/security/ssl/SSLCipher$StreamReadCipherGenerator.h>
#include <sun/security/ssl/SSLCipher$StreamWriteCipherGenerator.h>
#include <sun/security/ssl/SSLCipher$T10BlockReadCipherGenerator.h>
#include <sun/security/ssl/SSLCipher$T10BlockWriteCipherGenerator.h>
#include <sun/security/ssl/SSLCipher$T11BlockReadCipherGenerator.h>
#include <sun/security/ssl/SSLCipher$T11BlockWriteCipherGenerator.h>
#include <sun/security/ssl/SSLCipher$T12CC20P1305ReadCipherGenerator.h>
#include <sun/security/ssl/SSLCipher$T12CC20P1305WriteCipherGenerator.h>
#include <sun/security/ssl/SSLCipher$T12GcmReadCipherGenerator.h>
#include <sun/security/ssl/SSLCipher$T12GcmWriteCipherGenerator.h>
#include <sun/security/ssl/SSLCipher$T13CC20P1305ReadCipherGenerator.h>
#include <sun/security/ssl/SSLCipher$T13CC20P1305WriteCipherGenerator.h>
#include <sun/security/ssl/SSLCipher$T13GcmReadCipherGenerator.h>
#include <sun/security/ssl/SSLCipher$T13GcmWriteCipherGenerator.h>
#include <sun/security/ssl/SSLCipher$WriteCipherGenerator.h>
#include <sun/security/ssl/SSLLogger.h>
#include <jcpp.h>

#undef AEAD_CIPHER
#undef BLOCK_CIPHER
#undef B_3DES
#undef B_AES_128
#undef B_AES_128_GCM
#undef B_AES_128_GCM_IV
#undef B_AES_256
#undef B_AES_256_GCM
#undef B_AES_256_GCM_IV
#undef B_DES
#undef B_DES_40
#undef B_IDEA
#undef B_NULL
#undef NULL_CIPHER
#undef PROTOCOLS_OF_11
#undef PROTOCOLS_OF_12
#undef PROTOCOLS_OF_13
#undef PROTOCOLS_OF_NONE
#undef PROTOCOLS_TO_10
#undef PROTOCOLS_TO_12
#undef PROTOCOLS_TO_13
#undef STREAM_CIPHER

using $Map$EntryArray = $Array<::java::util::Map$Entry>;
using $ProtocolVersionArray = $Array<::sun::security::ssl::ProtocolVersion>;
using $SSLCipherArray = $Array<::sun::security::ssl::SSLCipher>;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $Double = ::java::lang::Double;
using $Enum = ::java::lang::Enum;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $RuntimeException = ::java::lang::RuntimeException;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $AccessController = ::java::security::AccessController;
using $Key = ::java::security::Key;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $SecureRandom = ::java::security::SecureRandom;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $AbstractMap$SimpleImmutableEntry = ::java::util::AbstractMap$SimpleImmutableEntry;
using $HashMap = ::java::util::HashMap;
using $Map$Entry = ::java::util::Map$Entry;
using $BadPaddingException = ::javax::crypto::BadPaddingException;
using $Cipher = ::javax::crypto::Cipher;
using $NoSuchPaddingException = ::javax::crypto::NoSuchPaddingException;
using $SecretKey = ::javax::crypto::SecretKey;
using $IvParameterSpec = ::javax::crypto::spec::IvParameterSpec;
using $Authenticator = ::sun::security::ssl::Authenticator;
using $Authenticator$MAC = ::sun::security::ssl::Authenticator$MAC;
using $CipherType = ::sun::security::ssl::CipherType;
using $ProtocolVersion = ::sun::security::ssl::ProtocolVersion;
using $SSLCipher$1 = ::sun::security::ssl::SSLCipher$1;
using $SSLCipher$NullReadCipherGenerator = ::sun::security::ssl::SSLCipher$NullReadCipherGenerator;
using $SSLCipher$NullWriteCipherGenerator = ::sun::security::ssl::SSLCipher$NullWriteCipherGenerator;
using $SSLCipher$ReadCipherGenerator = ::sun::security::ssl::SSLCipher$ReadCipherGenerator;
using $SSLCipher$SSLReadCipher = ::sun::security::ssl::SSLCipher$SSLReadCipher;
using $SSLCipher$SSLWriteCipher = ::sun::security::ssl::SSLCipher$SSLWriteCipher;
using $SSLCipher$StreamReadCipherGenerator = ::sun::security::ssl::SSLCipher$StreamReadCipherGenerator;
using $SSLCipher$StreamWriteCipherGenerator = ::sun::security::ssl::SSLCipher$StreamWriteCipherGenerator;
using $SSLCipher$T10BlockReadCipherGenerator = ::sun::security::ssl::SSLCipher$T10BlockReadCipherGenerator;
using $SSLCipher$T10BlockWriteCipherGenerator = ::sun::security::ssl::SSLCipher$T10BlockWriteCipherGenerator;
using $SSLCipher$T11BlockReadCipherGenerator = ::sun::security::ssl::SSLCipher$T11BlockReadCipherGenerator;
using $SSLCipher$T11BlockWriteCipherGenerator = ::sun::security::ssl::SSLCipher$T11BlockWriteCipherGenerator;
using $SSLCipher$T12CC20P1305ReadCipherGenerator = ::sun::security::ssl::SSLCipher$T12CC20P1305ReadCipherGenerator;
using $SSLCipher$T12CC20P1305WriteCipherGenerator = ::sun::security::ssl::SSLCipher$T12CC20P1305WriteCipherGenerator;
using $SSLCipher$T12GcmReadCipherGenerator = ::sun::security::ssl::SSLCipher$T12GcmReadCipherGenerator;
using $SSLCipher$T12GcmWriteCipherGenerator = ::sun::security::ssl::SSLCipher$T12GcmWriteCipherGenerator;
using $SSLCipher$T13CC20P1305ReadCipherGenerator = ::sun::security::ssl::SSLCipher$T13CC20P1305ReadCipherGenerator;
using $SSLCipher$T13CC20P1305WriteCipherGenerator = ::sun::security::ssl::SSLCipher$T13CC20P1305WriteCipherGenerator;
using $SSLCipher$T13GcmReadCipherGenerator = ::sun::security::ssl::SSLCipher$T13GcmReadCipherGenerator;
using $SSLCipher$T13GcmWriteCipherGenerator = ::sun::security::ssl::SSLCipher$T13GcmWriteCipherGenerator;
using $SSLCipher$WriteCipherGenerator = ::sun::security::ssl::SSLCipher$WriteCipherGenerator;
using $SSLLogger = ::sun::security::ssl::SSLLogger;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _SSLCipher_FieldInfo_[] = {
	{"B_NULL", "Lsun/security/ssl/SSLCipher;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SSLCipher, B_NULL)},
	{"B_RC4_40", "Lsun/security/ssl/SSLCipher;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SSLCipher, B_RC4_40)},
	{"B_RC2_40", "Lsun/security/ssl/SSLCipher;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SSLCipher, B_RC2_40)},
	{"B_DES_40", "Lsun/security/ssl/SSLCipher;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SSLCipher, B_DES_40)},
	{"B_RC4_128", "Lsun/security/ssl/SSLCipher;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SSLCipher, B_RC4_128)},
	{"B_DES", "Lsun/security/ssl/SSLCipher;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SSLCipher, B_DES)},
	{"B_3DES", "Lsun/security/ssl/SSLCipher;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SSLCipher, B_3DES)},
	{"B_IDEA", "Lsun/security/ssl/SSLCipher;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SSLCipher, B_IDEA)},
	{"B_AES_128", "Lsun/security/ssl/SSLCipher;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SSLCipher, B_AES_128)},
	{"B_AES_256", "Lsun/security/ssl/SSLCipher;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SSLCipher, B_AES_256)},
	{"B_AES_128_GCM", "Lsun/security/ssl/SSLCipher;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SSLCipher, B_AES_128_GCM)},
	{"B_AES_256_GCM", "Lsun/security/ssl/SSLCipher;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SSLCipher, B_AES_256_GCM)},
	{"B_AES_128_GCM_IV", "Lsun/security/ssl/SSLCipher;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SSLCipher, B_AES_128_GCM_IV)},
	{"B_AES_256_GCM_IV", "Lsun/security/ssl/SSLCipher;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SSLCipher, B_AES_256_GCM_IV)},
	{"B_CC20_P1305", "Lsun/security/ssl/SSLCipher;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SSLCipher, B_CC20_P1305)},
	{"$VALUES", "[Lsun/security/ssl/SSLCipher;", nullptr, $PRIVATE | $STATIC | $FINAL | $SYNTHETIC, $staticField(SSLCipher, $VALUES)},
	{"description", "Ljava/lang/String;", nullptr, $FINAL, $field(SSLCipher, description)},
	{"transformation", "Ljava/lang/String;", nullptr, $FINAL, $field(SSLCipher, transformation)},
	{"algorithm", "Ljava/lang/String;", nullptr, $FINAL, $field(SSLCipher, algorithm)},
	{"allowed", "Z", nullptr, $FINAL, $field(SSLCipher, allowed)},
	{"keySize", "I", nullptr, $FINAL, $field(SSLCipher, keySize)},
	{"expandedKeySize", "I", nullptr, $FINAL, $field(SSLCipher, expandedKeySize)},
	{"ivSize", "I", nullptr, $FINAL, $field(SSLCipher, ivSize)},
	{"fixedIvSize", "I", nullptr, $FINAL, $field(SSLCipher, fixedIvSize)},
	{"exportable", "Z", nullptr, $FINAL, $field(SSLCipher, exportable)},
	{"cipherType", "Lsun/security/ssl/CipherType;", nullptr, $FINAL, $field(SSLCipher, cipherType)},
	{"tagSize", "I", nullptr, $STATIC | $FINAL, $constField(SSLCipher, tagSize)},
	{"isAvailable", "Z", nullptr, $PRIVATE | $FINAL, $field(SSLCipher, isAvailable$)},
	{"readCipherGenerators", "[Ljava/util/Map$Entry;", "[Ljava/util/Map$Entry<Lsun/security/ssl/SSLCipher$ReadCipherGenerator;[Lsun/security/ssl/ProtocolVersion;>;", $PRIVATE | $FINAL, $field(SSLCipher, readCipherGenerators)},
	{"writeCipherGenerators", "[Ljava/util/Map$Entry;", "[Ljava/util/Map$Entry<Lsun/security/ssl/SSLCipher$WriteCipherGenerator;[Lsun/security/ssl/ProtocolVersion;>;", $PRIVATE | $FINAL, $field(SSLCipher, writeCipherGenerators)},
	{"cipherLimits", "Ljava/util/HashMap;", "Ljava/util/HashMap<Ljava/lang/String;Ljava/lang/Long;>;", $PRIVATE | $STATIC | $FINAL, $staticField(SSLCipher, cipherLimits)},
	{"tag", "[Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(SSLCipher, tag)},
	{}
};

$MethodInfo _SSLCipher_MethodInfo_[] = {
	{"$values", "()[Lsun/security/ssl/SSLCipher;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(SSLCipher, $values, $SSLCipherArray*)},
	{"<init>", "(Ljava/lang/String;ILjava/lang/String;Lsun/security/ssl/CipherType;IIIIZZ[Ljava/util/Map$Entry;[Ljava/util/Map$Entry;)V", "(Ljava/lang/String;Lsun/security/ssl/CipherType;IIIIZZ[Ljava/util/Map$Entry<Lsun/security/ssl/SSLCipher$ReadCipherGenerator;[Lsun/security/ssl/ProtocolVersion;>;[Ljava/util/Map$Entry<Lsun/security/ssl/SSLCipher$WriteCipherGenerator;[Lsun/security/ssl/ProtocolVersion;>;)V", $PRIVATE, $method(SSLCipher, init$, void, $String*, int32_t, $String*, $CipherType*, int32_t, int32_t, int32_t, int32_t, bool, bool, $Map$EntryArray*, $Map$EntryArray*)},
	{"addMac", "(Lsun/security/ssl/Authenticator$MAC;Ljava/nio/ByteBuffer;B)V", nullptr, $PRIVATE | $STATIC, $staticMethod(SSLCipher, addMac, void, $Authenticator$MAC*, $ByteBuffer*, int8_t)},
	{"addPadding", "(Ljava/nio/ByteBuffer;I)I", nullptr, $PRIVATE | $STATIC, $staticMethod(SSLCipher, addPadding, int32_t, $ByteBuffer*, int32_t)},
	{"calculateRemainingLen", "(Lsun/security/ssl/Authenticator$MAC;II)I", nullptr, $PRIVATE | $STATIC, $staticMethod(SSLCipher, calculateRemainingLen, int32_t, $Authenticator$MAC*, int32_t, int32_t)},
	{"checkCBCMac", "(Lsun/security/ssl/Authenticator$MAC;Ljava/nio/ByteBuffer;BI[B)V", nullptr, $PRIVATE | $STATIC, $staticMethod(SSLCipher, checkCBCMac, void, $Authenticator$MAC*, $ByteBuffer*, int8_t, int32_t, $bytes*), "javax.crypto.BadPaddingException"},
	{"checkMacTags", "(BLjava/nio/ByteBuffer;Lsun/security/ssl/Authenticator$MAC;[BZ)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(SSLCipher, checkMacTags, bool, int8_t, $ByteBuffer*, $Authenticator$MAC*, $bytes*, bool)},
	{"checkPadding", "(Ljava/nio/ByteBuffer;B)[I", nullptr, $PRIVATE | $STATIC, $staticMethod(SSLCipher, checkPadding, $ints*, $ByteBuffer*, int8_t)},
	{"checkStreamMac", "(Lsun/security/ssl/Authenticator$MAC;Ljava/nio/ByteBuffer;B[B)V", nullptr, $PRIVATE | $STATIC, $staticMethod(SSLCipher, checkStreamMac, void, $Authenticator$MAC*, $ByteBuffer*, int8_t, $bytes*), "javax.crypto.BadPaddingException"},
	{"compareMacTags", "(Ljava/nio/ByteBuffer;[B)[I", nullptr, $PRIVATE | $STATIC, $staticMethod(SSLCipher, compareMacTags, $ints*, $ByteBuffer*, $bytes*)},
	{"createReadCipher", "(Lsun/security/ssl/Authenticator;Lsun/security/ssl/ProtocolVersion;Ljavax/crypto/SecretKey;Ljavax/crypto/spec/IvParameterSpec;Ljava/security/SecureRandom;)Lsun/security/ssl/SSLCipher$SSLReadCipher;", nullptr, 0, $method(SSLCipher, createReadCipher, $SSLCipher$SSLReadCipher*, $Authenticator*, $ProtocolVersion*, $SecretKey*, $IvParameterSpec*, $SecureRandom*), "java.security.GeneralSecurityException"},
	{"createWriteCipher", "(Lsun/security/ssl/Authenticator;Lsun/security/ssl/ProtocolVersion;Ljavax/crypto/SecretKey;Ljavax/crypto/spec/IvParameterSpec;Ljava/security/SecureRandom;)Lsun/security/ssl/SSLCipher$SSLWriteCipher;", nullptr, 0, $method(SSLCipher, createWriteCipher, $SSLCipher$SSLWriteCipher*, $Authenticator*, $ProtocolVersion*, $SecretKey*, $IvParameterSpec*, $SecureRandom*), "java.security.GeneralSecurityException"},
	{"isAvailable", "()Z", nullptr, 0, $method(SSLCipher, isAvailable, bool)},
	{"isTransformationAvailable", "(Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(SSLCipher, isTransformationAvailable, bool, $String*)},
	{"isUnlimited", "(ILjava/lang/String;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(SSLCipher, isUnlimited, bool, int32_t, $String*)},
	{"removePadding", "(Ljava/nio/ByteBuffer;IILsun/security/ssl/ProtocolVersion;)I", nullptr, $PRIVATE | $STATIC, $staticMethod(SSLCipher, removePadding, int32_t, $ByteBuffer*, int32_t, int32_t, $ProtocolVersion*), "javax.crypto.BadPaddingException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SSLCipher, toString, $String*)},
	{"valueOf", "(Ljava/lang/String;)Lsun/security/ssl/SSLCipher;", nullptr, $PUBLIC | $STATIC, $staticMethod(SSLCipher, valueOf, SSLCipher*, $String*)},
	{"values", "()[Lsun/security/ssl/SSLCipher;", nullptr, $PUBLIC | $STATIC, $staticMethod(SSLCipher, values, $SSLCipherArray*)},
	{}
};

$InnerClassInfo _SSLCipher_InnerClassesInfo_[] = {
	{"sun.security.ssl.SSLCipher$T13CC20P1305WriteCipherGenerator", "sun.security.ssl.SSLCipher", "T13CC20P1305WriteCipherGenerator", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.SSLCipher$T13CC20P1305ReadCipherGenerator", "sun.security.ssl.SSLCipher", "T13CC20P1305ReadCipherGenerator", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.SSLCipher$T12CC20P1305WriteCipherGenerator", "sun.security.ssl.SSLCipher", "T12CC20P1305WriteCipherGenerator", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.SSLCipher$T12CC20P1305ReadCipherGenerator", "sun.security.ssl.SSLCipher", "T12CC20P1305ReadCipherGenerator", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.SSLCipher$T13GcmWriteCipherGenerator", "sun.security.ssl.SSLCipher", "T13GcmWriteCipherGenerator", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.SSLCipher$T13GcmReadCipherGenerator", "sun.security.ssl.SSLCipher", "T13GcmReadCipherGenerator", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.SSLCipher$T12GcmWriteCipherGenerator", "sun.security.ssl.SSLCipher", "T12GcmWriteCipherGenerator", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.SSLCipher$T12GcmReadCipherGenerator", "sun.security.ssl.SSLCipher", "T12GcmReadCipherGenerator", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.SSLCipher$T11BlockWriteCipherGenerator", "sun.security.ssl.SSLCipher", "T11BlockWriteCipherGenerator", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.SSLCipher$T11BlockReadCipherGenerator", "sun.security.ssl.SSLCipher", "T11BlockReadCipherGenerator", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.SSLCipher$T10BlockWriteCipherGenerator", "sun.security.ssl.SSLCipher", "T10BlockWriteCipherGenerator", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.SSLCipher$T10BlockReadCipherGenerator", "sun.security.ssl.SSLCipher", "T10BlockReadCipherGenerator", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.SSLCipher$StreamWriteCipherGenerator", "sun.security.ssl.SSLCipher", "StreamWriteCipherGenerator", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.SSLCipher$StreamReadCipherGenerator", "sun.security.ssl.SSLCipher", "StreamReadCipherGenerator", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.SSLCipher$NullWriteCipherGenerator", "sun.security.ssl.SSLCipher", "NullWriteCipherGenerator", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.SSLCipher$NullReadCipherGenerator", "sun.security.ssl.SSLCipher", "NullReadCipherGenerator", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.SSLCipher$SSLWriteCipher", "sun.security.ssl.SSLCipher", "SSLWriteCipher", $STATIC | $ABSTRACT},
	{"sun.security.ssl.SSLCipher$WriteCipherGenerator", "sun.security.ssl.SSLCipher", "WriteCipherGenerator", $STATIC | $INTERFACE | $ABSTRACT},
	{"sun.security.ssl.SSLCipher$SSLReadCipher", "sun.security.ssl.SSLCipher", "SSLReadCipher", $STATIC | $ABSTRACT},
	{"sun.security.ssl.SSLCipher$ReadCipherGenerator", "sun.security.ssl.SSLCipher", "ReadCipherGenerator", $STATIC | $INTERFACE | $ABSTRACT},
	{"sun.security.ssl.SSLCipher$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _SSLCipher_ClassInfo_ = {
	$FINAL | $ACC_SUPER | $ENUM,
	"sun.security.ssl.SSLCipher",
	"java.lang.Enum",
	nullptr,
	_SSLCipher_FieldInfo_,
	_SSLCipher_MethodInfo_,
	"Ljava/lang/Enum<Lsun/security/ssl/SSLCipher;>;",
	nullptr,
	_SSLCipher_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.ssl.SSLCipher$T13CC20P1305WriteCipherGenerator,sun.security.ssl.SSLCipher$T13CC20P1305WriteCipherGenerator$CC20P1305WriteCipher,sun.security.ssl.SSLCipher$T13CC20P1305ReadCipherGenerator,sun.security.ssl.SSLCipher$T13CC20P1305ReadCipherGenerator$CC20P1305ReadCipher,sun.security.ssl.SSLCipher$T12CC20P1305WriteCipherGenerator,sun.security.ssl.SSLCipher$T12CC20P1305WriteCipherGenerator$CC20P1305WriteCipher,sun.security.ssl.SSLCipher$T12CC20P1305ReadCipherGenerator,sun.security.ssl.SSLCipher$T12CC20P1305ReadCipherGenerator$CC20P1305ReadCipher,sun.security.ssl.SSLCipher$T13GcmWriteCipherGenerator,sun.security.ssl.SSLCipher$T13GcmWriteCipherGenerator$GcmWriteCipher,sun.security.ssl.SSLCipher$T13GcmReadCipherGenerator,sun.security.ssl.SSLCipher$T13GcmReadCipherGenerator$GcmReadCipher,sun.security.ssl.SSLCipher$T12GcmWriteCipherGenerator,sun.security.ssl.SSLCipher$T12GcmWriteCipherGenerator$GcmWriteCipher,sun.security.ssl.SSLCipher$T12GcmReadCipherGenerator,sun.security.ssl.SSLCipher$T12GcmReadCipherGenerator$GcmReadCipher,sun.security.ssl.SSLCipher$T11BlockWriteCipherGenerator,sun.security.ssl.SSLCipher$T11BlockWriteCipherGenerator$BlockWriteCipher,sun.security.ssl.SSLCipher$T11BlockReadCipherGenerator,sun.security.ssl.SSLCipher$T11BlockReadCipherGenerator$BlockReadCipher,sun.security.ssl.SSLCipher$T10BlockWriteCipherGenerator,sun.security.ssl.SSLCipher$T10BlockWriteCipherGenerator$BlockWriteCipher,sun.security.ssl.SSLCipher$T10BlockReadCipherGenerator,sun.security.ssl.SSLCipher$T10BlockReadCipherGenerator$BlockReadCipher,sun.security.ssl.SSLCipher$StreamWriteCipherGenerator,sun.security.ssl.SSLCipher$StreamWriteCipherGenerator$StreamWriteCipher,sun.security.ssl.SSLCipher$StreamReadCipherGenerator,sun.security.ssl.SSLCipher$StreamReadCipherGenerator$StreamReadCipher,sun.security.ssl.SSLCipher$NullWriteCipherGenerator,sun.security.ssl.SSLCipher$NullWriteCipherGenerator$NullWriteCipher,sun.security.ssl.SSLCipher$NullReadCipherGenerator,sun.security.ssl.SSLCipher$NullReadCipherGenerator$NullReadCipher,sun.security.ssl.SSLCipher$SSLWriteCipher,sun.security.ssl.SSLCipher$WriteCipherGenerator,sun.security.ssl.SSLCipher$SSLReadCipher,sun.security.ssl.SSLCipher$ReadCipherGenerator,sun.security.ssl.SSLCipher$1"
};

$Object* allocate$SSLCipher($Class* clazz) {
	return $of($alloc(SSLCipher));
}

SSLCipher* SSLCipher::B_NULL = nullptr;
SSLCipher* SSLCipher::B_RC4_40 = nullptr;
SSLCipher* SSLCipher::B_RC2_40 = nullptr;
SSLCipher* SSLCipher::B_DES_40 = nullptr;
SSLCipher* SSLCipher::B_RC4_128 = nullptr;
SSLCipher* SSLCipher::B_DES = nullptr;
SSLCipher* SSLCipher::B_3DES = nullptr;
SSLCipher* SSLCipher::B_IDEA = nullptr;
SSLCipher* SSLCipher::B_AES_128 = nullptr;
SSLCipher* SSLCipher::B_AES_256 = nullptr;
SSLCipher* SSLCipher::B_AES_128_GCM = nullptr;
SSLCipher* SSLCipher::B_AES_256_GCM = nullptr;
SSLCipher* SSLCipher::B_AES_128_GCM_IV = nullptr;
SSLCipher* SSLCipher::B_AES_256_GCM_IV = nullptr;
SSLCipher* SSLCipher::B_CC20_P1305 = nullptr;
$SSLCipherArray* SSLCipher::$VALUES = nullptr;
$HashMap* SSLCipher::cipherLimits = nullptr;
$StringArray* SSLCipher::tag = nullptr;

$SSLCipherArray* SSLCipher::$values() {
	$init(SSLCipher);
	return $new($SSLCipherArray, {
		SSLCipher::B_NULL,
		SSLCipher::B_RC4_40,
		SSLCipher::B_RC2_40,
		SSLCipher::B_DES_40,
		SSLCipher::B_RC4_128,
		SSLCipher::B_DES,
		SSLCipher::B_3DES,
		SSLCipher::B_IDEA,
		SSLCipher::B_AES_128,
		SSLCipher::B_AES_256,
		SSLCipher::B_AES_128_GCM,
		SSLCipher::B_AES_256_GCM,
		SSLCipher::B_AES_128_GCM_IV,
		SSLCipher::B_AES_256_GCM_IV,
		SSLCipher::B_CC20_P1305
	});
}

$SSLCipherArray* SSLCipher::values() {
	$init(SSLCipher);
	return $cast($SSLCipherArray, SSLCipher::$VALUES->clone());
}

SSLCipher* SSLCipher::valueOf($String* name) {
	$init(SSLCipher);
	return $cast(SSLCipher, $Enum::valueOf(SSLCipher::class$, name));
}

void SSLCipher::init$($String* $enum$name, int32_t $enum$ordinal, $String* transformation, $CipherType* cipherType, int32_t keySize, int32_t expandedKeySize, int32_t ivSize, int32_t fixedIvSize, bool allowed, bool exportable, $Map$EntryArray* readCipherGenerators, $Map$EntryArray* writeCipherGenerators) {
	$useLocalCurrentObjectStackCache();
	$Enum::init$($enum$name, $enum$ordinal);
	$set(this, transformation, transformation);
	$var($StringArray, splits, $nc(transformation)->split("/"_s));
	$set(this, algorithm, splits->get(0));
	$set(this, cipherType, cipherType);
	$set(this, description, $str({this->algorithm, "/"_s, $$str((keySize << 3))}));
	this->keySize = keySize;
	this->ivSize = ivSize;
	this->fixedIvSize = fixedIvSize;
	this->allowed = allowed;
	this->expandedKeySize = expandedKeySize;
	this->exportable = exportable;
	bool var$0 = allowed && isUnlimited(keySize, transformation);
	this->isAvailable$ = var$0 && isTransformationAvailable(transformation);
	$set(this, readCipherGenerators, readCipherGenerators);
	$set(this, writeCipherGenerators, writeCipherGenerators);
}

bool SSLCipher::isTransformationAvailable($String* transformation) {
	$init(SSLCipher);
	$useLocalCurrentObjectStackCache();
	if ($nc(transformation)->equals("NULL"_s)) {
		return true;
	}
	try {
		$Cipher::getInstance(transformation);
		return true;
	} catch ($NoSuchAlgorithmException& e) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
			$SSLLogger::fine($$str({"Transformation "_s, transformation, " is not available."_s}), $$new($ObjectArray, 0));
		}
	} catch ($NoSuchPaddingException& e) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
			$SSLLogger::fine($$str({"Transformation "_s, transformation, " is not available."_s}), $$new($ObjectArray, 0));
		}
	}
	return false;
}

$SSLCipher$SSLReadCipher* SSLCipher::createReadCipher($Authenticator* authenticator, $ProtocolVersion* protocolVersion, $SecretKey* key, $IvParameterSpec* iv, $SecureRandom* random) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->readCipherGenerators)->length == 0) {
		return nullptr;
	}
	$var($SSLCipher$ReadCipherGenerator, rcg, nullptr);
	{
		$var($Map$EntryArray, arr$, this->readCipherGenerators);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Map$Entry, me, arr$->get(i$));
			{
				{
					$var($ProtocolVersionArray, arr$, $cast($ProtocolVersionArray, $nc(me)->getValue()));
					int32_t len$ = arr$->length;
					int32_t i$ = 0;
					for (; i$ < len$; ++i$) {
						$ProtocolVersion* pv = arr$->get(i$);
						{
							if (protocolVersion == pv) {
								$assign(rcg, $cast($SSLCipher$ReadCipherGenerator, me->getKey()));
								break;
							}
						}
					}
				}
			}
		}
	}
	if (rcg != nullptr) {
		return rcg->createCipher(this, authenticator, protocolVersion, this->transformation, key, iv, random);
	}
	return nullptr;
}

$SSLCipher$SSLWriteCipher* SSLCipher::createWriteCipher($Authenticator* authenticator, $ProtocolVersion* protocolVersion, $SecretKey* key, $IvParameterSpec* iv, $SecureRandom* random) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->writeCipherGenerators)->length == 0) {
		return nullptr;
	}
	$var($SSLCipher$WriteCipherGenerator, wcg, nullptr);
	{
		$var($Map$EntryArray, arr$, this->writeCipherGenerators);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Map$Entry, me, arr$->get(i$));
			{
				{
					$var($ProtocolVersionArray, arr$, $cast($ProtocolVersionArray, $nc(me)->getValue()));
					int32_t len$ = arr$->length;
					int32_t i$ = 0;
					for (; i$ < len$; ++i$) {
						$ProtocolVersion* pv = arr$->get(i$);
						{
							if (protocolVersion == pv) {
								$assign(wcg, $cast($SSLCipher$WriteCipherGenerator, me->getKey()));
								break;
							}
						}
					}
				}
			}
		}
	}
	if (wcg != nullptr) {
		return wcg->createCipher(this, authenticator, protocolVersion, this->transformation, key, iv, random);
	}
	return nullptr;
}

bool SSLCipher::isAvailable() {
	return this->isAvailable$;
}

bool SSLCipher::isUnlimited(int32_t keySize, $String* transformation) {
	$init(SSLCipher);
	int32_t keySizeInBits = keySize * 8;
	if (keySizeInBits > 128) {
		try {
			if ($Cipher::getMaxAllowedKeyLength(transformation) < keySizeInBits) {
				return false;
			}
		} catch ($Exception& e) {
			return false;
		}
	}
	return true;
}

$String* SSLCipher::toString() {
	return this->description;
}

void SSLCipher::addMac($Authenticator$MAC* signer, $ByteBuffer* destination, int8_t contentType) {
	$init(SSLCipher);
	$useLocalCurrentObjectStackCache();
	if ($nc($($nc(signer)->macAlg()))->size != 0) {
		int32_t dstContent = $nc(destination)->position();
		$var($bytes, hash, signer->compute(contentType, destination, false));
		destination->limit(destination->limit() + $nc(hash)->length);
		destination->put(hash);
		destination->position(dstContent);
	}
}

void SSLCipher::checkStreamMac($Authenticator$MAC* signer, $ByteBuffer* bb, int8_t contentType, $bytes* sequence) {
	$init(SSLCipher);
	int32_t tagLen = $nc($($nc(signer)->macAlg()))->size;
	if (tagLen != 0) {
		int32_t contentLen = $nc(bb)->remaining() - tagLen;
		if (contentLen < 0) {
			$throwNew($BadPaddingException, "bad record"_s);
		}
		if (checkMacTags(contentType, bb, signer, sequence, false)) {
			$throwNew($BadPaddingException, "bad record MAC"_s);
		}
	}
}

void SSLCipher::checkCBCMac($Authenticator$MAC* signer, $ByteBuffer* bb, int8_t contentType, int32_t cipheredLength, $bytes* sequence) {
	$init(SSLCipher);
	$useLocalCurrentObjectStackCache();
	$var($BadPaddingException, reservedBPE, nullptr);
	int32_t tagLen = $nc($($nc(signer)->macAlg()))->size;
	int32_t pos = $nc(bb)->position();
	if (tagLen != 0) {
		int32_t contentLen = bb->remaining() - tagLen;
		if (contentLen < 0) {
			$assign(reservedBPE, $new($BadPaddingException, "bad record"_s));
			contentLen = cipheredLength - tagLen;
			bb->limit(pos + cipheredLength);
		}
		if (checkMacTags(contentType, bb, signer, sequence, false)) {
			if (reservedBPE == nullptr) {
				$assign(reservedBPE, $new($BadPaddingException, "bad record MAC"_s));
			}
		}
		int32_t remainingLen = calculateRemainingLen(signer, cipheredLength, contentLen);
		remainingLen += $nc($(signer->macAlg()))->size;
		$var($ByteBuffer, temporary, $ByteBuffer::allocate(remainingLen));
		checkMacTags(contentType, temporary, signer, sequence, true);
	}
	if (reservedBPE != nullptr) {
		$throw(reservedBPE);
	}
}

bool SSLCipher::checkMacTags(int8_t contentType, $ByteBuffer* bb, $Authenticator$MAC* signer, $bytes* sequence, bool isSimulated) {
	$init(SSLCipher);
	$useLocalCurrentObjectStackCache();
	int32_t tagLen = $nc($($nc(signer)->macAlg()))->size;
	int32_t position = $nc(bb)->position();
	int32_t lim = bb->limit();
	int32_t macOffset = lim - tagLen;
	bb->limit(macOffset);
	$var($bytes, hash, signer->compute(contentType, bb, sequence, isSimulated));
	if (hash == nullptr || tagLen != $nc(hash)->length) {
		$throwNew($RuntimeException, "Internal MAC error"_s);
	}
	bb->position(macOffset);
	bb->limit(lim);
	{
		$var($Throwable, var$0, nullptr);
		bool var$2 = false;
		bool return$1 = false;
		try {
			$var($ints, results, compareMacTags(bb, hash));
			var$2 = ($nc(results)->get(0) != 0);
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			bb->position(position);
			bb->limit(macOffset);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

$ints* SSLCipher::compareMacTags($ByteBuffer* bb, $bytes* tag) {
	$init(SSLCipher);
	$useLocalCurrentObjectStackCache();
	$var($ints, results, $new($ints, {
		0,
		0
	}));
	{
		$var($bytes, arr$, tag);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			int8_t t = arr$->get(i$);
			{
				if ($nc(bb)->get() != t) {
					++(*results)[0];
				} else {
					++(*results)[1];
				}
			}
		}
	}
	return results;
}

int32_t SSLCipher::calculateRemainingLen($Authenticator$MAC* signer, int32_t fullLen, int32_t usedLen) {
	$init(SSLCipher);
	$useLocalCurrentObjectStackCache();
	int32_t blockLen = $nc($($nc(signer)->macAlg()))->hashBlockSize;
	int32_t minimalPaddingLen = $nc($(signer->macAlg()))->minimalPaddingSize;
	fullLen += 13 - (blockLen - minimalPaddingLen);
	usedLen += 13 - (blockLen - minimalPaddingLen);
	int32_t var$0 = 1;
	double var$2 = $Math::ceil(fullLen / (1.0 * blockLen));
	int32_t var$1 = $cast(int32_t, (var$2 - $Math::ceil(usedLen / (1.0 * blockLen)))) * blockLen;
	return var$0 + var$1;
}

int32_t SSLCipher::addPadding($ByteBuffer* bb, int32_t blockSize) {
	$init(SSLCipher);
	int32_t len = $nc(bb)->remaining();
	int32_t offset = bb->position();
	int32_t newlen = len + 1;
	int8_t pad = 0;
	int32_t i = 0;
	if (($mod(newlen, blockSize)) != 0) {
		newlen += blockSize - 1;
		newlen -= $mod(newlen, blockSize);
	}
	pad = (int8_t)(newlen - len);
	bb->limit(newlen + offset);
	for (i = 0, offset += len; i < pad; ++i) {
		bb->put(offset++, (int8_t)(pad - 1));
	}
	bb->position(offset);
	bb->limit(offset);
	return newlen;
}

int32_t SSLCipher::removePadding($ByteBuffer* bb, int32_t tagLen, int32_t blockSize, $ProtocolVersion* protocolVersion) {
	$init(SSLCipher);
	$useLocalCurrentObjectStackCache();
	int32_t len = $nc(bb)->remaining();
	int32_t offset = bb->position();
	int32_t padOffset = offset + len - 1;
	int32_t padLen = (int32_t)(bb->get(padOffset) & (uint32_t)255);
	int32_t newLen = len - (padLen + 1);
	if ((newLen - tagLen) < 0) {
		checkPadding($(bb->duplicate()), (int8_t)((int32_t)(padLen & (uint32_t)255)));
		$throwNew($BadPaddingException, $$str({"Invalid Padding length: "_s, $$str(padLen)}));
	}
	$var($ints, results, checkPadding($($nc($(bb->duplicate()))->position(offset + newLen)), (int8_t)((int32_t)(padLen & (uint32_t)255))));
	if ($nc(protocolVersion)->useTLS10PlusSpec()) {
		if ($nc(results)->get(0) != 0) {
			$throwNew($BadPaddingException, "Invalid TLS padding data"_s);
		}
	} else if (padLen > blockSize) {
		$throwNew($BadPaddingException, $$str({"Padding length ("_s, $$str(padLen), ") of SSLv3 message should not be bigger than the block size ("_s, $$str(blockSize), ")"_s}));
	}
	bb->limit(offset + newLen);
	return newLen;
}

$ints* SSLCipher::checkPadding($ByteBuffer* bb, int8_t pad) {
	$init(SSLCipher);
	if (!$nc(bb)->hasRemaining()) {
		$throwNew($RuntimeException, "hasRemaining() must be positive"_s);
	}
	$var($ints, results, $new($ints, {
		0,
		0
	}));
	$nc(bb)->mark();
	for (int32_t i = 0; i <= 256; bb->reset()) {
		for (; bb->hasRemaining() && i <= 256; ++i) {
			if (bb->get() != pad) {
				++(*results)[0];
			} else {
				++(*results)[1];
			}
		}
	}
	return results;
}

void clinit$SSLCipher($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	int64_t max = 0x4000000000000000;
	$var($String, var$0, "B_NULL"_s);
	$var($String, var$1, "NULL"_s);
	$init($CipherType);
	$var($CipherType, var$2, $CipherType::NULL_CIPHER);
	$init($ProtocolVersion);
	$var($Map$EntryArray, var$3, ($new($Map$EntryArray, {
		static_cast<$Map$Entry*>($$new($AbstractMap$SimpleImmutableEntry, $$new($SSLCipher$NullReadCipherGenerator), $ProtocolVersion::PROTOCOLS_OF_NONE)),
		static_cast<$Map$Entry*>($$new($AbstractMap$SimpleImmutableEntry, $$new($SSLCipher$NullReadCipherGenerator), $ProtocolVersion::PROTOCOLS_TO_13))
	})));
	$assignStatic(SSLCipher::B_NULL, $new(SSLCipher, var$0, 0, var$1, var$2, 0, 0, 0, 0, true, true, var$3, ($$new($Map$EntryArray, {
		static_cast<$Map$Entry*>($$new($AbstractMap$SimpleImmutableEntry, $$new($SSLCipher$NullWriteCipherGenerator), $ProtocolVersion::PROTOCOLS_OF_NONE)),
		static_cast<$Map$Entry*>($$new($AbstractMap$SimpleImmutableEntry, $$new($SSLCipher$NullWriteCipherGenerator), $ProtocolVersion::PROTOCOLS_TO_13))
	}))));
	$var($String, var$4, "B_RC4_40"_s);
	$var($String, var$5, "RC4"_s);
	$var($CipherType, var$6, $CipherType::STREAM_CIPHER);
	$var($Map$EntryArray, var$7, ($new($Map$EntryArray, {static_cast<$Map$Entry*>($$new($AbstractMap$SimpleImmutableEntry, $$new($SSLCipher$StreamReadCipherGenerator), $ProtocolVersion::PROTOCOLS_TO_10))})));
	$assignStatic(SSLCipher::B_RC4_40, $new(SSLCipher, var$4, 1, var$5, var$6, 5, 16, 0, 0, true, true, var$7, ($$new($Map$EntryArray, {static_cast<$Map$Entry*>($$new($AbstractMap$SimpleImmutableEntry, $$new($SSLCipher$StreamWriteCipherGenerator), $ProtocolVersion::PROTOCOLS_TO_10))}))));
	$var($String, var$8, "B_RC2_40"_s);
	$var($String, var$9, "RC2"_s);
	$var($CipherType, var$10, $CipherType::BLOCK_CIPHER);
	$var($Map$EntryArray, var$11, ($new($Map$EntryArray, {static_cast<$Map$Entry*>($$new($AbstractMap$SimpleImmutableEntry, $$new($SSLCipher$StreamReadCipherGenerator), $ProtocolVersion::PROTOCOLS_TO_10))})));
	$assignStatic(SSLCipher::B_RC2_40, $new(SSLCipher, var$8, 2, var$9, var$10, 5, 16, 8, 0, false, true, var$11, ($$new($Map$EntryArray, {static_cast<$Map$Entry*>($$new($AbstractMap$SimpleImmutableEntry, $$new($SSLCipher$StreamWriteCipherGenerator), $ProtocolVersion::PROTOCOLS_TO_10))}))));
	$var($String, var$12, "B_DES_40"_s);
	$var($String, var$13, "DES/CBC/NoPadding"_s);
	$var($CipherType, var$14, $CipherType::BLOCK_CIPHER);
	$var($Map$EntryArray, var$15, ($new($Map$EntryArray, {static_cast<$Map$Entry*>($$new($AbstractMap$SimpleImmutableEntry, $$new($SSLCipher$T10BlockReadCipherGenerator), $ProtocolVersion::PROTOCOLS_TO_10))})));
	$assignStatic(SSLCipher::B_DES_40, $new(SSLCipher, var$12, 3, var$13, var$14, 5, 8, 8, 0, true, true, var$15, ($$new($Map$EntryArray, {static_cast<$Map$Entry*>($$new($AbstractMap$SimpleImmutableEntry, $$new($SSLCipher$T10BlockWriteCipherGenerator), $ProtocolVersion::PROTOCOLS_TO_10))}))));
	$var($String, var$16, "B_RC4_128"_s);
	$var($String, var$17, "RC4"_s);
	$var($CipherType, var$18, $CipherType::STREAM_CIPHER);
	$var($Map$EntryArray, var$19, ($new($Map$EntryArray, {static_cast<$Map$Entry*>($$new($AbstractMap$SimpleImmutableEntry, $$new($SSLCipher$StreamReadCipherGenerator), $ProtocolVersion::PROTOCOLS_TO_12))})));
	$assignStatic(SSLCipher::B_RC4_128, $new(SSLCipher, var$16, 4, var$17, var$18, 16, 16, 0, 0, true, false, var$19, ($$new($Map$EntryArray, {static_cast<$Map$Entry*>($$new($AbstractMap$SimpleImmutableEntry, $$new($SSLCipher$StreamWriteCipherGenerator), $ProtocolVersion::PROTOCOLS_TO_12))}))));
	$var($String, var$20, "B_DES"_s);
	$var($String, var$21, "DES/CBC/NoPadding"_s);
	$var($CipherType, var$22, $CipherType::BLOCK_CIPHER);
	$var($Map$EntryArray, var$23, ($new($Map$EntryArray, {
		static_cast<$Map$Entry*>($$new($AbstractMap$SimpleImmutableEntry, $$new($SSLCipher$T10BlockReadCipherGenerator), $ProtocolVersion::PROTOCOLS_TO_10)),
		static_cast<$Map$Entry*>($$new($AbstractMap$SimpleImmutableEntry, $$new($SSLCipher$T11BlockReadCipherGenerator), $ProtocolVersion::PROTOCOLS_OF_11))
	})));
	$assignStatic(SSLCipher::B_DES, $new(SSLCipher, var$20, 5, var$21, var$22, 8, 8, 8, 0, true, false, var$23, ($$new($Map$EntryArray, {
		static_cast<$Map$Entry*>($$new($AbstractMap$SimpleImmutableEntry, $$new($SSLCipher$T10BlockWriteCipherGenerator), $ProtocolVersion::PROTOCOLS_TO_10)),
		static_cast<$Map$Entry*>($$new($AbstractMap$SimpleImmutableEntry, $$new($SSLCipher$T11BlockWriteCipherGenerator), $ProtocolVersion::PROTOCOLS_OF_11))
	}))));
	$var($String, var$24, "B_3DES"_s);
	$var($String, var$25, "DESede/CBC/NoPadding"_s);
	$var($CipherType, var$26, $CipherType::BLOCK_CIPHER);
	$var($Map$EntryArray, var$27, ($new($Map$EntryArray, {
		static_cast<$Map$Entry*>($$new($AbstractMap$SimpleImmutableEntry, $$new($SSLCipher$T10BlockReadCipherGenerator), $ProtocolVersion::PROTOCOLS_TO_10)),
		static_cast<$Map$Entry*>($$new($AbstractMap$SimpleImmutableEntry, $$new($SSLCipher$T11BlockReadCipherGenerator), $ProtocolVersion::PROTOCOLS_11_12))
	})));
	$assignStatic(SSLCipher::B_3DES, $new(SSLCipher, var$24, 6, var$25, var$26, 24, 24, 8, 0, true, false, var$27, ($$new($Map$EntryArray, {
		static_cast<$Map$Entry*>($$new($AbstractMap$SimpleImmutableEntry, $$new($SSLCipher$T10BlockWriteCipherGenerator), $ProtocolVersion::PROTOCOLS_TO_10)),
		static_cast<$Map$Entry*>($$new($AbstractMap$SimpleImmutableEntry, $$new($SSLCipher$T11BlockWriteCipherGenerator), $ProtocolVersion::PROTOCOLS_11_12))
	}))));
	$var($String, var$28, "B_IDEA"_s);
	$var($String, var$29, "IDEA"_s);
	$var($CipherType, var$30, $CipherType::BLOCK_CIPHER);
	$var($Map$EntryArray, var$31, ($new($Map$EntryArray, {static_cast<$Map$Entry*>($$new($AbstractMap$SimpleImmutableEntry, nullptr, $ProtocolVersion::PROTOCOLS_TO_12))})));
	$assignStatic(SSLCipher::B_IDEA, $new(SSLCipher, var$28, 7, var$29, var$30, 16, 16, 8, 0, false, false, var$31, ($$new($Map$EntryArray, {static_cast<$Map$Entry*>($$new($AbstractMap$SimpleImmutableEntry, nullptr, $ProtocolVersion::PROTOCOLS_TO_12))}))));
	$var($String, var$32, "B_AES_128"_s);
	$var($String, var$33, "AES/CBC/NoPadding"_s);
	$var($CipherType, var$34, $CipherType::BLOCK_CIPHER);
	$var($Map$EntryArray, var$35, ($new($Map$EntryArray, {
		static_cast<$Map$Entry*>($$new($AbstractMap$SimpleImmutableEntry, $$new($SSLCipher$T10BlockReadCipherGenerator), $ProtocolVersion::PROTOCOLS_TO_10)),
		static_cast<$Map$Entry*>($$new($AbstractMap$SimpleImmutableEntry, $$new($SSLCipher$T11BlockReadCipherGenerator), $ProtocolVersion::PROTOCOLS_11_12))
	})));
	$assignStatic(SSLCipher::B_AES_128, $new(SSLCipher, var$32, 8, var$33, var$34, 16, 16, 16, 0, true, false, var$35, ($$new($Map$EntryArray, {
		static_cast<$Map$Entry*>($$new($AbstractMap$SimpleImmutableEntry, $$new($SSLCipher$T10BlockWriteCipherGenerator), $ProtocolVersion::PROTOCOLS_TO_10)),
		static_cast<$Map$Entry*>($$new($AbstractMap$SimpleImmutableEntry, $$new($SSLCipher$T11BlockWriteCipherGenerator), $ProtocolVersion::PROTOCOLS_11_12))
	}))));
	$var($String, var$36, "B_AES_256"_s);
	$var($String, var$37, "AES/CBC/NoPadding"_s);
	$var($CipherType, var$38, $CipherType::BLOCK_CIPHER);
	$var($Map$EntryArray, var$39, ($new($Map$EntryArray, {
		static_cast<$Map$Entry*>($$new($AbstractMap$SimpleImmutableEntry, $$new($SSLCipher$T10BlockReadCipherGenerator), $ProtocolVersion::PROTOCOLS_TO_10)),
		static_cast<$Map$Entry*>($$new($AbstractMap$SimpleImmutableEntry, $$new($SSLCipher$T11BlockReadCipherGenerator), $ProtocolVersion::PROTOCOLS_11_12))
	})));
	$assignStatic(SSLCipher::B_AES_256, $new(SSLCipher, var$36, 9, var$37, var$38, 32, 32, 16, 0, true, false, var$39, ($$new($Map$EntryArray, {
		static_cast<$Map$Entry*>($$new($AbstractMap$SimpleImmutableEntry, $$new($SSLCipher$T10BlockWriteCipherGenerator), $ProtocolVersion::PROTOCOLS_TO_10)),
		static_cast<$Map$Entry*>($$new($AbstractMap$SimpleImmutableEntry, $$new($SSLCipher$T11BlockWriteCipherGenerator), $ProtocolVersion::PROTOCOLS_11_12))
	}))));
	$var($String, var$40, "B_AES_128_GCM"_s);
	$var($String, var$41, "AES/GCM/NoPadding"_s);
	$var($CipherType, var$42, $CipherType::AEAD_CIPHER);
	$var($Map$EntryArray, var$43, ($new($Map$EntryArray, {static_cast<$Map$Entry*>($$new($AbstractMap$SimpleImmutableEntry, $$new($SSLCipher$T12GcmReadCipherGenerator), $ProtocolVersion::PROTOCOLS_OF_12))})));
	$assignStatic(SSLCipher::B_AES_128_GCM, $new(SSLCipher, var$40, 10, var$41, var$42, 16, 16, 12, 4, true, false, var$43, ($$new($Map$EntryArray, {static_cast<$Map$Entry*>($$new($AbstractMap$SimpleImmutableEntry, $$new($SSLCipher$T12GcmWriteCipherGenerator), $ProtocolVersion::PROTOCOLS_OF_12))}))));
	$var($String, var$44, "B_AES_256_GCM"_s);
	$var($String, var$45, "AES/GCM/NoPadding"_s);
	$var($CipherType, var$46, $CipherType::AEAD_CIPHER);
	$var($Map$EntryArray, var$47, ($new($Map$EntryArray, {static_cast<$Map$Entry*>($$new($AbstractMap$SimpleImmutableEntry, $$new($SSLCipher$T12GcmReadCipherGenerator), $ProtocolVersion::PROTOCOLS_OF_12))})));
	$assignStatic(SSLCipher::B_AES_256_GCM, $new(SSLCipher, var$44, 11, var$45, var$46, 32, 32, 12, 4, true, false, var$47, ($$new($Map$EntryArray, {static_cast<$Map$Entry*>($$new($AbstractMap$SimpleImmutableEntry, $$new($SSLCipher$T12GcmWriteCipherGenerator), $ProtocolVersion::PROTOCOLS_OF_12))}))));
	$var($String, var$48, "B_AES_128_GCM_IV"_s);
	$var($String, var$49, "AES/GCM/NoPadding"_s);
	$var($CipherType, var$50, $CipherType::AEAD_CIPHER);
	$var($Map$EntryArray, var$51, ($new($Map$EntryArray, {static_cast<$Map$Entry*>($$new($AbstractMap$SimpleImmutableEntry, $$new($SSLCipher$T13GcmReadCipherGenerator), $ProtocolVersion::PROTOCOLS_OF_13))})));
	$assignStatic(SSLCipher::B_AES_128_GCM_IV, $new(SSLCipher, var$48, 12, var$49, var$50, 16, 16, 12, 0, true, false, var$51, ($$new($Map$EntryArray, {static_cast<$Map$Entry*>($$new($AbstractMap$SimpleImmutableEntry, $$new($SSLCipher$T13GcmWriteCipherGenerator), $ProtocolVersion::PROTOCOLS_OF_13))}))));
	$var($String, var$52, "B_AES_256_GCM_IV"_s);
	$var($String, var$53, "AES/GCM/NoPadding"_s);
	$var($CipherType, var$54, $CipherType::AEAD_CIPHER);
	$var($Map$EntryArray, var$55, ($new($Map$EntryArray, {static_cast<$Map$Entry*>($$new($AbstractMap$SimpleImmutableEntry, $$new($SSLCipher$T13GcmReadCipherGenerator), $ProtocolVersion::PROTOCOLS_OF_13))})));
	$assignStatic(SSLCipher::B_AES_256_GCM_IV, $new(SSLCipher, var$52, 13, var$53, var$54, 32, 32, 12, 0, true, false, var$55, ($$new($Map$EntryArray, {static_cast<$Map$Entry*>($$new($AbstractMap$SimpleImmutableEntry, $$new($SSLCipher$T13GcmWriteCipherGenerator), $ProtocolVersion::PROTOCOLS_OF_13))}))));
	$var($String, var$56, "B_CC20_P1305"_s);
	$var($String, var$57, "ChaCha20-Poly1305"_s);
	$var($CipherType, var$58, $CipherType::AEAD_CIPHER);
	$var($Map$EntryArray, var$59, ($new($Map$EntryArray, {
		static_cast<$Map$Entry*>($$new($AbstractMap$SimpleImmutableEntry, $$new($SSLCipher$T12CC20P1305ReadCipherGenerator), $ProtocolVersion::PROTOCOLS_OF_12)),
		static_cast<$Map$Entry*>($$new($AbstractMap$SimpleImmutableEntry, $$new($SSLCipher$T13CC20P1305ReadCipherGenerator), $ProtocolVersion::PROTOCOLS_OF_13))
	})));
	$assignStatic(SSLCipher::B_CC20_P1305, $new(SSLCipher, var$56, 14, var$57, var$58, 32, 32, 12, 12, true, false, var$59, ($$new($Map$EntryArray, {
		static_cast<$Map$Entry*>($$new($AbstractMap$SimpleImmutableEntry, $$new($SSLCipher$T12CC20P1305WriteCipherGenerator), $ProtocolVersion::PROTOCOLS_OF_12)),
		static_cast<$Map$Entry*>($$new($AbstractMap$SimpleImmutableEntry, $$new($SSLCipher$T13CC20P1305WriteCipherGenerator), $ProtocolVersion::PROTOCOLS_OF_13))
	}))));
	$assignStatic(SSLCipher::$VALUES, SSLCipher::$values());
	$assignStatic(SSLCipher::cipherLimits, $new($HashMap));
	$assignStatic(SSLCipher::tag, $new($StringArray, {"KEYUPDATE"_s}));
	{
		int64_t max = 0x4000000000000000;
		$var($String, prop, $cast($String, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($SSLCipher$1)))));
		if (prop != nullptr) {
			$var($StringArray, propvalue, prop->split(","_s));
			{
				$var($StringArray, arr$, propvalue);
				int32_t len$ = arr$->length;
				int32_t i$ = 0;
				for (; i$ < len$; ++i$) {
					$var($String, entry, arr$->get(i$));
					{
						int32_t index = 0;
						$var($StringArray, values, $($($nc(entry)->trim())->toUpperCase())->split(" "_s));
						if ($nc(values->get(1))->contains($nc(SSLCipher::tag)->get(0))) {
							index = 0;
						} else {
							$init($SSLLogger);
							if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
								$SSLLogger::fine($$str({"jdk.tls.keyLimits:  Unknown action:  "_s, entry}), $$new($ObjectArray, 0));
							}
							continue;
						}
						int64_t size = 0;
						int32_t i = $nc(values->get(2))->indexOf("^"_s);
						try {
							if (i >= 0) {
								size = $cast(int64_t, $Math::pow((double)2, (double)$Integer::parseInt($($nc(values->get(2))->substring(i + 1)))));
							} else {
								size = $Long::parseLong(values->get(2));
							}
							if (size < 1 || size > max) {
								$throwNew($NumberFormatException, "Length exceeded limits"_s);
							}
						} catch ($NumberFormatException& e) {
							$init($SSLLogger);
							if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
								$SSLLogger::fine($$str({"jdk.tls.keyLimits:  "_s, $(e->getMessage()), ":  "_s, entry}), $$new($ObjectArray, 0));
							}
							continue;
						}
						$init($SSLLogger);
						if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
							$SSLLogger::fine($$str({"jdk.tls.keyLimits:  entry = "_s, entry, ". "_s, values->get(0), ":"_s, $nc(SSLCipher::tag)->get(index), " = "_s, $$str(size)}), $$new($ObjectArray, 0));
						}
						$nc(SSLCipher::cipherLimits)->put($$str({values->get(0), ":"_s, $nc(SSLCipher::tag)->get(index)}), $($Long::valueOf(size)));
					}
				}
			}
		}
	}
}

SSLCipher::SSLCipher() {
}

$Class* SSLCipher::load$($String* name, bool initialize) {
	$loadClass(SSLCipher, name, initialize, &_SSLCipher_ClassInfo_, clinit$SSLCipher, allocate$SSLCipher);
	return class$;
}

$Class* SSLCipher::class$ = nullptr;

		} // ssl
	} // security
} // sun