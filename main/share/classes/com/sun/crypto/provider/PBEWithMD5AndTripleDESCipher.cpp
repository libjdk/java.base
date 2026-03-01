#include <com/sun/crypto/provider/PBEWithMD5AndTripleDESCipher.h>

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

$FieldInfo _PBEWithMD5AndTripleDESCipher_FieldInfo_[] = {
	{"core", "Lcom/sun/crypto/provider/PBES1Core;", nullptr, $PRIVATE, $field(PBEWithMD5AndTripleDESCipher, core)},
	{}
};

$MethodInfo _PBEWithMD5AndTripleDESCipher_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(PBEWithMD5AndTripleDESCipher, init$, void), "java.security.NoSuchAlgorithmException,javax.crypto.NoSuchPaddingException"},
	{"engineDoFinal", "([BII)[B", nullptr, $PROTECTED, $virtualMethod(PBEWithMD5AndTripleDESCipher, engineDoFinal, $bytes*, $bytes*, int32_t, int32_t), "javax.crypto.IllegalBlockSizeException,javax.crypto.BadPaddingException"},
	{"engineDoFinal", "([BII[BI)I", nullptr, $PROTECTED, $virtualMethod(PBEWithMD5AndTripleDESCipher, engineDoFinal, int32_t, $bytes*, int32_t, int32_t, $bytes*, int32_t), "javax.crypto.ShortBufferException,javax.crypto.IllegalBlockSizeException,javax.crypto.BadPaddingException"},
	{"engineGetBlockSize", "()I", nullptr, $PROTECTED, $virtualMethod(PBEWithMD5AndTripleDESCipher, engineGetBlockSize, int32_t)},
	{"engineGetIV", "()[B", nullptr, $PROTECTED, $virtualMethod(PBEWithMD5AndTripleDESCipher, engineGetIV, $bytes*)},
	{"engineGetKeySize", "(Ljava/security/Key;)I", nullptr, $PROTECTED, $virtualMethod(PBEWithMD5AndTripleDESCipher, engineGetKeySize, int32_t, $Key*), "java.security.InvalidKeyException"},
	{"engineGetOutputSize", "(I)I", nullptr, $PROTECTED, $virtualMethod(PBEWithMD5AndTripleDESCipher, engineGetOutputSize, int32_t, int32_t)},
	{"engineGetParameters", "()Ljava/security/AlgorithmParameters;", nullptr, $PROTECTED, $virtualMethod(PBEWithMD5AndTripleDESCipher, engineGetParameters, $AlgorithmParameters*)},
	{"engineInit", "(ILjava/security/Key;Ljava/security/SecureRandom;)V", nullptr, $PROTECTED, $virtualMethod(PBEWithMD5AndTripleDESCipher, engineInit, void, int32_t, $Key*, $SecureRandom*), "java.security.InvalidKeyException"},
	{"engineInit", "(ILjava/security/Key;Ljava/security/spec/AlgorithmParameterSpec;Ljava/security/SecureRandom;)V", nullptr, $PROTECTED, $virtualMethod(PBEWithMD5AndTripleDESCipher, engineInit, void, int32_t, $Key*, $AlgorithmParameterSpec*, $SecureRandom*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"engineInit", "(ILjava/security/Key;Ljava/security/AlgorithmParameters;Ljava/security/SecureRandom;)V", nullptr, $PROTECTED, $virtualMethod(PBEWithMD5AndTripleDESCipher, engineInit, void, int32_t, $Key*, $AlgorithmParameters*, $SecureRandom*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"engineSetMode", "(Ljava/lang/String;)V", nullptr, $PROTECTED, $virtualMethod(PBEWithMD5AndTripleDESCipher, engineSetMode, void, $String*), "java.security.NoSuchAlgorithmException"},
	{"engineSetPadding", "(Ljava/lang/String;)V", nullptr, $PROTECTED, $virtualMethod(PBEWithMD5AndTripleDESCipher, engineSetPadding, void, $String*), "javax.crypto.NoSuchPaddingException"},
	{"engineUnwrap", "([BLjava/lang/String;I)Ljava/security/Key;", nullptr, $PROTECTED, $virtualMethod(PBEWithMD5AndTripleDESCipher, engineUnwrap, $Key*, $bytes*, $String*, int32_t), "java.security.InvalidKeyException,java.security.NoSuchAlgorithmException"},
	{"engineUpdate", "([BII)[B", nullptr, $PROTECTED, $virtualMethod(PBEWithMD5AndTripleDESCipher, engineUpdate, $bytes*, $bytes*, int32_t, int32_t)},
	{"engineUpdate", "([BII[BI)I", nullptr, $PROTECTED, $virtualMethod(PBEWithMD5AndTripleDESCipher, engineUpdate, int32_t, $bytes*, int32_t, int32_t, $bytes*, int32_t), "javax.crypto.ShortBufferException"},
	{"engineWrap", "(Ljava/security/Key;)[B", nullptr, $PROTECTED, $virtualMethod(PBEWithMD5AndTripleDESCipher, engineWrap, $bytes*, $Key*), "javax.crypto.IllegalBlockSizeException,java.security.InvalidKeyException"},
	{}
};

$ClassInfo _PBEWithMD5AndTripleDESCipher_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"com.sun.crypto.provider.PBEWithMD5AndTripleDESCipher",
	"javax.crypto.CipherSpi",
	nullptr,
	_PBEWithMD5AndTripleDESCipher_FieldInfo_,
	_PBEWithMD5AndTripleDESCipher_MethodInfo_
};

$Object* allocate$PBEWithMD5AndTripleDESCipher($Class* clazz) {
	return $of($alloc(PBEWithMD5AndTripleDESCipher));
}

void PBEWithMD5AndTripleDESCipher::init$() {
	$CipherSpi::init$();
	$set(this, core, $new($PBES1Core, "DESede"_s));
}

void PBEWithMD5AndTripleDESCipher::engineSetMode($String* mode) {
	if ((mode != nullptr) && (!mode->equalsIgnoreCase("CBC"_s))) {
		$throwNew($NoSuchAlgorithmException, $$str({"Invalid cipher mode: "_s, mode}));
	}
}

void PBEWithMD5AndTripleDESCipher::engineSetPadding($String* paddingScheme) {
	if ((paddingScheme != nullptr) && (!paddingScheme->equalsIgnoreCase("PKCS5Padding"_s))) {
		$throwNew($NoSuchPaddingException, $$str({"Invalid padding scheme: "_s, paddingScheme}));
	}
}

int32_t PBEWithMD5AndTripleDESCipher::engineGetBlockSize() {
	return $nc(this->core)->getBlockSize();
}

int32_t PBEWithMD5AndTripleDESCipher::engineGetOutputSize(int32_t inputLen) {
	return $nc(this->core)->getOutputSize(inputLen);
}

$bytes* PBEWithMD5AndTripleDESCipher::engineGetIV() {
	return $nc(this->core)->getIV();
}

$AlgorithmParameters* PBEWithMD5AndTripleDESCipher::engineGetParameters() {
	return $nc(this->core)->getParameters();
}

void PBEWithMD5AndTripleDESCipher::engineInit(int32_t opmode, $Key* key, $SecureRandom* random) {
	try {
		$nc(this->core)->init(opmode, key, ($AlgorithmParameterSpec*)nullptr, random);
	} catch ($InvalidAlgorithmParameterException& ie) {
		$var($InvalidKeyException, ike, $new($InvalidKeyException, "requires PBE parameters"_s));
		ike->initCause(ie);
		$throw(ike);
	}
}

void PBEWithMD5AndTripleDESCipher::engineInit(int32_t opmode, $Key* key, $AlgorithmParameterSpec* params, $SecureRandom* random) {
	$nc(this->core)->init(opmode, key, params, random);
}

void PBEWithMD5AndTripleDESCipher::engineInit(int32_t opmode, $Key* key, $AlgorithmParameters* params, $SecureRandom* random) {
	$nc(this->core)->init(opmode, key, params, random);
}

$bytes* PBEWithMD5AndTripleDESCipher::engineUpdate($bytes* input, int32_t inputOffset, int32_t inputLen) {
	return $nc(this->core)->update(input, inputOffset, inputLen);
}

int32_t PBEWithMD5AndTripleDESCipher::engineUpdate($bytes* input, int32_t inputOffset, int32_t inputLen, $bytes* output, int32_t outputOffset) {
	return $nc(this->core)->update(input, inputOffset, inputLen, output, outputOffset);
}

$bytes* PBEWithMD5AndTripleDESCipher::engineDoFinal($bytes* input, int32_t inputOffset, int32_t inputLen) {
	return $nc(this->core)->doFinal(input, inputOffset, inputLen);
}

int32_t PBEWithMD5AndTripleDESCipher::engineDoFinal($bytes* input, int32_t inputOffset, int32_t inputLen, $bytes* output, int32_t outputOffset) {
	return $nc(this->core)->doFinal(input, inputOffset, inputLen, output, outputOffset);
}

int32_t PBEWithMD5AndTripleDESCipher::engineGetKeySize($Key* key) {
	return 168;
}

$bytes* PBEWithMD5AndTripleDESCipher::engineWrap($Key* key) {
	return $nc(this->core)->wrap(key);
}

$Key* PBEWithMD5AndTripleDESCipher::engineUnwrap($bytes* wrappedKey, $String* wrappedKeyAlgorithm, int32_t wrappedKeyType) {
	return $nc(this->core)->unwrap(wrappedKey, wrappedKeyAlgorithm, wrappedKeyType);
}

PBEWithMD5AndTripleDESCipher::PBEWithMD5AndTripleDESCipher() {
}

$Class* PBEWithMD5AndTripleDESCipher::load$($String* name, bool initialize) {
	$loadClass(PBEWithMD5AndTripleDESCipher, name, initialize, &_PBEWithMD5AndTripleDESCipher_ClassInfo_, allocate$PBEWithMD5AndTripleDESCipher);
	return class$;
}

$Class* PBEWithMD5AndTripleDESCipher::class$ = nullptr;

			} // provider
		} // crypto
	} // sun
} // com