#include <com/sun/crypto/provider/PBEWithMD5AndDESCipher.h>

#include <com/sun/crypto/provider/PBES1Core.h>
#include <java/security/AlgorithmParameters.h>
#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/Key.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/SecureRandom.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <javax/crypto/CipherSpi.h>
#include <javax/crypto/NoSuchPaddingException.h>
#include <jcpp.h>

using $PBES1Core = ::com::sun::crypto::provider::PBES1Core;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AlgorithmParameters = ::java::security::AlgorithmParameters;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $Key = ::java::security::Key;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $SecureRandom = ::java::security::SecureRandom;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $CipherSpi = ::javax::crypto::CipherSpi;
using $NoSuchPaddingException = ::javax::crypto::NoSuchPaddingException;

namespace com {
	namespace sun {
		namespace crypto {
			namespace provider {

$FieldInfo _PBEWithMD5AndDESCipher_FieldInfo_[] = {
	{"core", "Lcom/sun/crypto/provider/PBES1Core;", nullptr, $PRIVATE, $field(PBEWithMD5AndDESCipher, core)},
	{}
};

$MethodInfo _PBEWithMD5AndDESCipher_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(PBEWithMD5AndDESCipher, init$, void), "java.security.NoSuchAlgorithmException,javax.crypto.NoSuchPaddingException"},
	{"engineDoFinal", "([BII)[B", nullptr, $PROTECTED, $virtualMethod(PBEWithMD5AndDESCipher, engineDoFinal, $bytes*, $bytes*, int32_t, int32_t), "javax.crypto.IllegalBlockSizeException,javax.crypto.BadPaddingException"},
	{"engineDoFinal", "([BII[BI)I", nullptr, $PROTECTED, $virtualMethod(PBEWithMD5AndDESCipher, engineDoFinal, int32_t, $bytes*, int32_t, int32_t, $bytes*, int32_t), "javax.crypto.ShortBufferException,javax.crypto.IllegalBlockSizeException,javax.crypto.BadPaddingException"},
	{"engineGetBlockSize", "()I", nullptr, $PROTECTED, $virtualMethod(PBEWithMD5AndDESCipher, engineGetBlockSize, int32_t)},
	{"engineGetIV", "()[B", nullptr, $PROTECTED, $virtualMethod(PBEWithMD5AndDESCipher, engineGetIV, $bytes*)},
	{"engineGetKeySize", "(Ljava/security/Key;)I", nullptr, $PROTECTED, $virtualMethod(PBEWithMD5AndDESCipher, engineGetKeySize, int32_t, $Key*), "java.security.InvalidKeyException"},
	{"engineGetOutputSize", "(I)I", nullptr, $PROTECTED, $virtualMethod(PBEWithMD5AndDESCipher, engineGetOutputSize, int32_t, int32_t)},
	{"engineGetParameters", "()Ljava/security/AlgorithmParameters;", nullptr, $PROTECTED, $virtualMethod(PBEWithMD5AndDESCipher, engineGetParameters, $AlgorithmParameters*)},
	{"engineInit", "(ILjava/security/Key;Ljava/security/SecureRandom;)V", nullptr, $PROTECTED, $virtualMethod(PBEWithMD5AndDESCipher, engineInit, void, int32_t, $Key*, $SecureRandom*), "java.security.InvalidKeyException"},
	{"engineInit", "(ILjava/security/Key;Ljava/security/spec/AlgorithmParameterSpec;Ljava/security/SecureRandom;)V", nullptr, $PROTECTED, $virtualMethod(PBEWithMD5AndDESCipher, engineInit, void, int32_t, $Key*, $AlgorithmParameterSpec*, $SecureRandom*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"engineInit", "(ILjava/security/Key;Ljava/security/AlgorithmParameters;Ljava/security/SecureRandom;)V", nullptr, $PROTECTED, $virtualMethod(PBEWithMD5AndDESCipher, engineInit, void, int32_t, $Key*, $AlgorithmParameters*, $SecureRandom*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"engineSetMode", "(Ljava/lang/String;)V", nullptr, $PROTECTED, $virtualMethod(PBEWithMD5AndDESCipher, engineSetMode, void, $String*), "java.security.NoSuchAlgorithmException"},
	{"engineSetPadding", "(Ljava/lang/String;)V", nullptr, $PROTECTED, $virtualMethod(PBEWithMD5AndDESCipher, engineSetPadding, void, $String*), "javax.crypto.NoSuchPaddingException"},
	{"engineUnwrap", "([BLjava/lang/String;I)Ljava/security/Key;", nullptr, $PROTECTED, $virtualMethod(PBEWithMD5AndDESCipher, engineUnwrap, $Key*, $bytes*, $String*, int32_t), "java.security.InvalidKeyException,java.security.NoSuchAlgorithmException"},
	{"engineUpdate", "([BII)[B", nullptr, $PROTECTED, $virtualMethod(PBEWithMD5AndDESCipher, engineUpdate, $bytes*, $bytes*, int32_t, int32_t)},
	{"engineUpdate", "([BII[BI)I", nullptr, $PROTECTED, $virtualMethod(PBEWithMD5AndDESCipher, engineUpdate, int32_t, $bytes*, int32_t, int32_t, $bytes*, int32_t), "javax.crypto.ShortBufferException"},
	{"engineWrap", "(Ljava/security/Key;)[B", nullptr, $PROTECTED, $virtualMethod(PBEWithMD5AndDESCipher, engineWrap, $bytes*, $Key*), "javax.crypto.IllegalBlockSizeException,java.security.InvalidKeyException"},
	{}
};

$ClassInfo _PBEWithMD5AndDESCipher_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"com.sun.crypto.provider.PBEWithMD5AndDESCipher",
	"javax.crypto.CipherSpi",
	nullptr,
	_PBEWithMD5AndDESCipher_FieldInfo_,
	_PBEWithMD5AndDESCipher_MethodInfo_
};

$Object* allocate$PBEWithMD5AndDESCipher($Class* clazz) {
	return $of($alloc(PBEWithMD5AndDESCipher));
}

void PBEWithMD5AndDESCipher::init$() {
	$CipherSpi::init$();
	$set(this, core, $new($PBES1Core, "DES"_s));
}

void PBEWithMD5AndDESCipher::engineSetMode($String* mode) {
	if ((mode != nullptr) && (!mode->equalsIgnoreCase("CBC"_s))) {
		$throwNew($NoSuchAlgorithmException, $$str({"Invalid cipher mode: "_s, mode}));
	}
}

void PBEWithMD5AndDESCipher::engineSetPadding($String* paddingScheme) {
	if ((paddingScheme != nullptr) && (!paddingScheme->equalsIgnoreCase("PKCS5Padding"_s))) {
		$throwNew($NoSuchPaddingException, $$str({"Invalid padding scheme: "_s, paddingScheme}));
	}
}

int32_t PBEWithMD5AndDESCipher::engineGetBlockSize() {
	return $nc(this->core)->getBlockSize();
}

int32_t PBEWithMD5AndDESCipher::engineGetOutputSize(int32_t inputLen) {
	return $nc(this->core)->getOutputSize(inputLen);
}

$bytes* PBEWithMD5AndDESCipher::engineGetIV() {
	return $nc(this->core)->getIV();
}

$AlgorithmParameters* PBEWithMD5AndDESCipher::engineGetParameters() {
	return $nc(this->core)->getParameters();
}

void PBEWithMD5AndDESCipher::engineInit(int32_t opmode, $Key* key, $SecureRandom* random) {
	try {
		engineInit(opmode, key, ($AlgorithmParameterSpec*)nullptr, random);
	} catch ($InvalidAlgorithmParameterException& ie) {
		$var($InvalidKeyException, ike, $new($InvalidKeyException, "requires PBE parameters"_s));
		ike->initCause(ie);
		$throw(ike);
	}
}

void PBEWithMD5AndDESCipher::engineInit(int32_t opmode, $Key* key, $AlgorithmParameterSpec* params, $SecureRandom* random) {
	$nc(this->core)->init(opmode, key, params, random);
}

void PBEWithMD5AndDESCipher::engineInit(int32_t opmode, $Key* key, $AlgorithmParameters* params, $SecureRandom* random) {
	$nc(this->core)->init(opmode, key, params, random);
}

$bytes* PBEWithMD5AndDESCipher::engineUpdate($bytes* input, int32_t inputOffset, int32_t inputLen) {
	return $nc(this->core)->update(input, inputOffset, inputLen);
}

int32_t PBEWithMD5AndDESCipher::engineUpdate($bytes* input, int32_t inputOffset, int32_t inputLen, $bytes* output, int32_t outputOffset) {
	return $nc(this->core)->update(input, inputOffset, inputLen, output, outputOffset);
}

$bytes* PBEWithMD5AndDESCipher::engineDoFinal($bytes* input, int32_t inputOffset, int32_t inputLen) {
	return $nc(this->core)->doFinal(input, inputOffset, inputLen);
}

int32_t PBEWithMD5AndDESCipher::engineDoFinal($bytes* input, int32_t inputOffset, int32_t inputLen, $bytes* output, int32_t outputOffset) {
	return $nc(this->core)->doFinal(input, inputOffset, inputLen, output, outputOffset);
}

int32_t PBEWithMD5AndDESCipher::engineGetKeySize($Key* key) {
	return 56;
}

$bytes* PBEWithMD5AndDESCipher::engineWrap($Key* key) {
	return $nc(this->core)->wrap(key);
}

$Key* PBEWithMD5AndDESCipher::engineUnwrap($bytes* wrappedKey, $String* wrappedKeyAlgorithm, int32_t wrappedKeyType) {
	$var($bytes, encodedKey, nullptr);
	return $nc(this->core)->unwrap(wrappedKey, wrappedKeyAlgorithm, wrappedKeyType);
}

PBEWithMD5AndDESCipher::PBEWithMD5AndDESCipher() {
}

$Class* PBEWithMD5AndDESCipher::load$($String* name, bool initialize) {
	$loadClass(PBEWithMD5AndDESCipher, name, initialize, &_PBEWithMD5AndDESCipher_ClassInfo_, allocate$PBEWithMD5AndDESCipher);
	return class$;
}

$Class* PBEWithMD5AndDESCipher::class$ = nullptr;

			} // provider
		} // crypto
	} // sun
} // com