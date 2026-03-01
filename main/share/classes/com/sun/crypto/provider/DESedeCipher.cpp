#include <com/sun/crypto/provider/DESedeCipher.h>

#include <com/sun/crypto/provider/CipherCore.h>
#include <com/sun/crypto/provider/DESConstants.h>
#include <com/sun/crypto/provider/DESedeCrypt.h>
#include <com/sun/crypto/provider/SymmetricCipher.h>
#include <java/security/AlgorithmParameters.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/Key.h>
#include <java/security/SecureRandom.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/util/Arrays.h>
#include <javax/crypto/CipherSpi.h>
#include <jcpp.h>

#undef DES_BLOCK_SIZE

using $CipherCore = ::com::sun::crypto::provider::CipherCore;
using $DESConstants = ::com::sun::crypto::provider::DESConstants;
using $DESedeCrypt = ::com::sun::crypto::provider::DESedeCrypt;
using $SymmetricCipher = ::com::sun::crypto::provider::SymmetricCipher;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AlgorithmParameters = ::java::security::AlgorithmParameters;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $Key = ::java::security::Key;
using $SecureRandom = ::java::security::SecureRandom;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $Arrays = ::java::util::Arrays;
using $CipherSpi = ::javax::crypto::CipherSpi;

namespace com {
	namespace sun {
		namespace crypto {
			namespace provider {

$FieldInfo _DESedeCipher_FieldInfo_[] = {
	{"core", "Lcom/sun/crypto/provider/CipherCore;", nullptr, $PRIVATE, $field(DESedeCipher, core)},
	{}
};

$MethodInfo _DESedeCipher_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(DESedeCipher, init$, void)},
	{"engineDoFinal", "([BII)[B", nullptr, $PROTECTED, $virtualMethod(DESedeCipher, engineDoFinal, $bytes*, $bytes*, int32_t, int32_t), "javax.crypto.IllegalBlockSizeException,javax.crypto.BadPaddingException"},
	{"engineDoFinal", "([BII[BI)I", nullptr, $PROTECTED, $virtualMethod(DESedeCipher, engineDoFinal, int32_t, $bytes*, int32_t, int32_t, $bytes*, int32_t), "javax.crypto.IllegalBlockSizeException,javax.crypto.ShortBufferException,javax.crypto.BadPaddingException"},
	{"engineGetBlockSize", "()I", nullptr, $PROTECTED, $virtualMethod(DESedeCipher, engineGetBlockSize, int32_t)},
	{"engineGetIV", "()[B", nullptr, $PROTECTED, $virtualMethod(DESedeCipher, engineGetIV, $bytes*)},
	{"engineGetKeySize", "(Ljava/security/Key;)I", nullptr, $PROTECTED, $virtualMethod(DESedeCipher, engineGetKeySize, int32_t, $Key*), "java.security.InvalidKeyException"},
	{"engineGetOutputSize", "(I)I", nullptr, $PROTECTED, $virtualMethod(DESedeCipher, engineGetOutputSize, int32_t, int32_t)},
	{"engineGetParameters", "()Ljava/security/AlgorithmParameters;", nullptr, $PROTECTED, $virtualMethod(DESedeCipher, engineGetParameters, $AlgorithmParameters*)},
	{"engineInit", "(ILjava/security/Key;Ljava/security/SecureRandom;)V", nullptr, $PROTECTED, $virtualMethod(DESedeCipher, engineInit, void, int32_t, $Key*, $SecureRandom*), "java.security.InvalidKeyException"},
	{"engineInit", "(ILjava/security/Key;Ljava/security/spec/AlgorithmParameterSpec;Ljava/security/SecureRandom;)V", nullptr, $PROTECTED, $virtualMethod(DESedeCipher, engineInit, void, int32_t, $Key*, $AlgorithmParameterSpec*, $SecureRandom*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"engineInit", "(ILjava/security/Key;Ljava/security/AlgorithmParameters;Ljava/security/SecureRandom;)V", nullptr, $PROTECTED, $virtualMethod(DESedeCipher, engineInit, void, int32_t, $Key*, $AlgorithmParameters*, $SecureRandom*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"engineSetMode", "(Ljava/lang/String;)V", nullptr, $PROTECTED, $virtualMethod(DESedeCipher, engineSetMode, void, $String*), "java.security.NoSuchAlgorithmException"},
	{"engineSetPadding", "(Ljava/lang/String;)V", nullptr, $PROTECTED, $virtualMethod(DESedeCipher, engineSetPadding, void, $String*), "javax.crypto.NoSuchPaddingException"},
	{"engineUnwrap", "([BLjava/lang/String;I)Ljava/security/Key;", nullptr, $PROTECTED, $virtualMethod(DESedeCipher, engineUnwrap, $Key*, $bytes*, $String*, int32_t), "java.security.InvalidKeyException,java.security.NoSuchAlgorithmException"},
	{"engineUpdate", "([BII)[B", nullptr, $PROTECTED, $virtualMethod(DESedeCipher, engineUpdate, $bytes*, $bytes*, int32_t, int32_t)},
	{"engineUpdate", "([BII[BI)I", nullptr, $PROTECTED, $virtualMethod(DESedeCipher, engineUpdate, int32_t, $bytes*, int32_t, int32_t, $bytes*, int32_t), "javax.crypto.ShortBufferException"},
	{"engineWrap", "(Ljava/security/Key;)[B", nullptr, $PROTECTED, $virtualMethod(DESedeCipher, engineWrap, $bytes*, $Key*), "javax.crypto.IllegalBlockSizeException,java.security.InvalidKeyException"},
	{}
};

$ClassInfo _DESedeCipher_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"com.sun.crypto.provider.DESedeCipher",
	"javax.crypto.CipherSpi",
	nullptr,
	_DESedeCipher_FieldInfo_,
	_DESedeCipher_MethodInfo_
};

$Object* allocate$DESedeCipher($Class* clazz) {
	return $of($alloc(DESedeCipher));
}

void DESedeCipher::init$() {
	$CipherSpi::init$();
	$set(this, core, nullptr);
	$set(this, core, $new($CipherCore, $$new($DESedeCrypt), $DESConstants::DES_BLOCK_SIZE));
}

void DESedeCipher::engineSetMode($String* mode) {
	$nc(this->core)->setMode(mode);
}

void DESedeCipher::engineSetPadding($String* paddingScheme) {
	$nc(this->core)->setPadding(paddingScheme);
}

int32_t DESedeCipher::engineGetBlockSize() {
	return $DESConstants::DES_BLOCK_SIZE;
}

int32_t DESedeCipher::engineGetOutputSize(int32_t inputLen) {
	return $nc(this->core)->getOutputSize(inputLen);
}

$bytes* DESedeCipher::engineGetIV() {
	return $nc(this->core)->getIV();
}

void DESedeCipher::engineInit(int32_t opmode, $Key* key, $SecureRandom* random) {
	$nc(this->core)->init(opmode, key, random);
}

void DESedeCipher::engineInit(int32_t opmode, $Key* key, $AlgorithmParameterSpec* params, $SecureRandom* random) {
	$nc(this->core)->init(opmode, key, params, random);
}

void DESedeCipher::engineInit(int32_t opmode, $Key* key, $AlgorithmParameters* params, $SecureRandom* random) {
	$nc(this->core)->init(opmode, key, params, random);
}

$bytes* DESedeCipher::engineUpdate($bytes* input, int32_t inputOffset, int32_t inputLen) {
	return $nc(this->core)->update(input, inputOffset, inputLen);
}

int32_t DESedeCipher::engineUpdate($bytes* input, int32_t inputOffset, int32_t inputLen, $bytes* output, int32_t outputOffset) {
	return $nc(this->core)->update(input, inputOffset, inputLen, output, outputOffset);
}

$bytes* DESedeCipher::engineDoFinal($bytes* input, int32_t inputOffset, int32_t inputLen) {
	return $nc(this->core)->doFinal(input, inputOffset, inputLen);
}

int32_t DESedeCipher::engineDoFinal($bytes* input, int32_t inputOffset, int32_t inputLen, $bytes* output, int32_t outputOffset) {
	return $nc(this->core)->doFinal(input, inputOffset, inputLen, output, outputOffset);
}

$AlgorithmParameters* DESedeCipher::engineGetParameters() {
	return $nc(this->core)->getParameters("DESede"_s);
}

int32_t DESedeCipher::engineGetKeySize($Key* key) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, encoded, $nc(key)->getEncoded());
	$Arrays::fill(encoded, (int8_t)0);
	if ($nc(encoded)->length != 24) {
		$throwNew($InvalidKeyException, $$str({"Invalid key length: "_s, $$str(encoded->length), " bytes"_s}));
	}
	return 112;
}

$bytes* DESedeCipher::engineWrap($Key* key) {
	return $nc(this->core)->wrap(key);
}

$Key* DESedeCipher::engineUnwrap($bytes* wrappedKey, $String* wrappedKeyAlgorithm, int32_t wrappedKeyType) {
	return $nc(this->core)->unwrap(wrappedKey, wrappedKeyAlgorithm, wrappedKeyType);
}

DESedeCipher::DESedeCipher() {
}

$Class* DESedeCipher::load$($String* name, bool initialize) {
	$loadClass(DESedeCipher, name, initialize, &_DESedeCipher_ClassInfo_, allocate$DESedeCipher);
	return class$;
}

$Class* DESedeCipher::class$ = nullptr;

			} // provider
		} // crypto
	} // sun
} // com