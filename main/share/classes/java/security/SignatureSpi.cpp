#include <java/security/SignatureSpi.h>

#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/Cloneable.h>
#include <java/lang/Math.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/nio/ByteBuffer.h>
#include <java/security/AlgorithmParameters.h>
#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/PrivateKey.h>
#include <java/security/ProviderException.h>
#include <java/security/PublicKey.h>
#include <java/security/SecureRandom.h>
#include <java/security/SignatureException.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <sun/security/jca/JCAUtil.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $Cloneable = ::java::lang::Cloneable;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $AlgorithmParameters = ::java::security::AlgorithmParameters;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $PrivateKey = ::java::security::PrivateKey;
using $ProviderException = ::java::security::ProviderException;
using $PublicKey = ::java::security::PublicKey;
using $SecureRandom = ::java::security::SecureRandom;
using $SignatureException = ::java::security::SignatureException;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $JCAUtil = ::sun::security::jca::JCAUtil;

namespace java {
	namespace security {

$CompoundAttribute _SignatureSpi_MethodAnnotations_engineGetParameter2[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _SignatureSpi_MethodAnnotations_engineSetParameter9[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _SignatureSpi_FieldInfo_[] = {
	{"appRandom", "Ljava/security/SecureRandom;", nullptr, $PROTECTED, $field(SignatureSpi, appRandom)},
	{}
};

$MethodInfo _SignatureSpi_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(SignatureSpi, init$, void)},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(SignatureSpi, clone, $Object*), "java.lang.CloneNotSupportedException"},
	{"engineGetParameter", "(Ljava/lang/String;)Ljava/lang/Object;", nullptr, $PROTECTED | $ABSTRACT | $DEPRECATED, $virtualMethod(SignatureSpi, engineGetParameter, $Object*, $String*), "java.security.InvalidParameterException", nullptr, _SignatureSpi_MethodAnnotations_engineGetParameter2},
	{"engineGetParameters", "()Ljava/security/AlgorithmParameters;", nullptr, $PROTECTED, $virtualMethod(SignatureSpi, engineGetParameters, $AlgorithmParameters*)},
	{"engineInitSign", "(Ljava/security/PrivateKey;)V", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(SignatureSpi, engineInitSign, void, $PrivateKey*), "java.security.InvalidKeyException"},
	{"engineInitSign", "(Ljava/security/PrivateKey;Ljava/security/SecureRandom;)V", nullptr, $PROTECTED, $virtualMethod(SignatureSpi, engineInitSign, void, $PrivateKey*, $SecureRandom*), "java.security.InvalidKeyException"},
	{"engineInitSign", "(Ljava/security/PrivateKey;Ljava/security/spec/AlgorithmParameterSpec;Ljava/security/SecureRandom;)V", nullptr, 0, $virtualMethod(SignatureSpi, engineInitSign, void, $PrivateKey*, $AlgorithmParameterSpec*, $SecureRandom*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"engineInitVerify", "(Ljava/security/PublicKey;)V", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(SignatureSpi, engineInitVerify, void, $PublicKey*), "java.security.InvalidKeyException"},
	{"engineInitVerify", "(Ljava/security/PublicKey;Ljava/security/spec/AlgorithmParameterSpec;)V", nullptr, 0, $virtualMethod(SignatureSpi, engineInitVerify, void, $PublicKey*, $AlgorithmParameterSpec*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"engineSetParameter", "(Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PROTECTED | $ABSTRACT | $DEPRECATED, $virtualMethod(SignatureSpi, engineSetParameter, void, $String*, Object$*), "java.security.InvalidParameterException", nullptr, _SignatureSpi_MethodAnnotations_engineSetParameter9},
	{"engineSetParameter", "(Ljava/security/spec/AlgorithmParameterSpec;)V", nullptr, $PROTECTED, $virtualMethod(SignatureSpi, engineSetParameter, void, $AlgorithmParameterSpec*), "java.security.InvalidAlgorithmParameterException"},
	{"engineSign", "()[B", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(SignatureSpi, engineSign, $bytes*), "java.security.SignatureException"},
	{"engineSign", "([BII)I", nullptr, $PROTECTED, $virtualMethod(SignatureSpi, engineSign, int32_t, $bytes*, int32_t, int32_t), "java.security.SignatureException"},
	{"engineUpdate", "(B)V", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(SignatureSpi, engineUpdate, void, int8_t), "java.security.SignatureException"},
	{"engineUpdate", "([BII)V", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(SignatureSpi, engineUpdate, void, $bytes*, int32_t, int32_t), "java.security.SignatureException"},
	{"engineUpdate", "(Ljava/nio/ByteBuffer;)V", nullptr, $PROTECTED, $virtualMethod(SignatureSpi, engineUpdate, void, $ByteBuffer*)},
	{"engineVerify", "([B)Z", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(SignatureSpi, engineVerify, bool, $bytes*), "java.security.SignatureException"},
	{"engineVerify", "([BII)Z", nullptr, $PROTECTED, $virtualMethod(SignatureSpi, engineVerify, bool, $bytes*, int32_t, int32_t), "java.security.SignatureException"},
	{}
};

$ClassInfo _SignatureSpi_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"java.security.SignatureSpi",
	"java.lang.Object",
	nullptr,
	_SignatureSpi_FieldInfo_,
	_SignatureSpi_MethodInfo_
};

$Object* allocate$SignatureSpi($Class* clazz) {
	return $of($alloc(SignatureSpi));
}

void SignatureSpi::init$() {
	$set(this, appRandom, nullptr);
}

void SignatureSpi::engineInitVerify($PublicKey* publicKey, $AlgorithmParameterSpec* params) {
	if (params != nullptr) {
		try {
			engineSetParameter(params);
		} catch ($UnsupportedOperationException& usoe) {
			$throwNew($InvalidAlgorithmParameterException, static_cast<$Throwable*>(usoe));
		}
	}
	engineInitVerify(publicKey);
}

void SignatureSpi::engineInitSign($PrivateKey* privateKey, $SecureRandom* random) {
	$set(this, appRandom, random);
	engineInitSign(privateKey);
}

void SignatureSpi::engineInitSign($PrivateKey* privateKey, $AlgorithmParameterSpec* params, $SecureRandom* random) {
	if (params != nullptr) {
		try {
			engineSetParameter(params);
		} catch ($UnsupportedOperationException& usoe) {
			$throwNew($InvalidAlgorithmParameterException, static_cast<$Throwable*>(usoe));
		}
	}
	engineInitSign(privateKey, random);
}

void SignatureSpi::engineUpdate($ByteBuffer* input) {
	$useLocalCurrentObjectStackCache();
	if ($nc(input)->hasRemaining() == false) {
		return;
	}
	try {
		if ($nc(input)->hasArray()) {
			$var($bytes, b, $cast($bytes, input->array()));
			int32_t ofs = input->arrayOffset();
			int32_t pos = input->position();
			int32_t lim = input->limit();
			engineUpdate(b, ofs + pos, lim - pos);
			input->position(lim);
		} else {
			int32_t len = input->remaining();
			$var($bytes, b, $new($bytes, $JCAUtil::getTempArraySize(len)));
			while (len > 0) {
				int32_t chunk = $Math::min(len, b->length);
				input->get(b, 0, chunk);
				engineUpdate(b, 0, chunk);
				len -= chunk;
			}
		}
	} catch ($SignatureException& e) {
		$throwNew($ProviderException, "update() failed"_s, e);
	}
}

int32_t SignatureSpi::engineSign($bytes* outbuf, int32_t offset, int32_t len) {
	$var($bytes, sig, engineSign());
	if (len < $nc(sig)->length) {
		$throwNew($SignatureException, "partial signatures not returned"_s);
	}
	if ($nc(outbuf)->length - offset < $nc(sig)->length) {
		$throwNew($SignatureException, "insufficient space in the output buffer to store the signature"_s);
	}
	$System::arraycopy(sig, 0, outbuf, offset, $nc(sig)->length);
	return $nc(sig)->length;
}

bool SignatureSpi::engineVerify($bytes* sigBytes, int32_t offset, int32_t length) {
	$var($bytes, sigBytesCopy, $new($bytes, length));
	$System::arraycopy(sigBytes, offset, sigBytesCopy, 0, length);
	return engineVerify(sigBytesCopy);
}

void SignatureSpi::engineSetParameter($AlgorithmParameterSpec* params) {
	$throwNew($UnsupportedOperationException);
}

$AlgorithmParameters* SignatureSpi::engineGetParameters() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$Object* SignatureSpi::clone() {
	if ($instanceOf($Cloneable, this)) {
		return $of($Object::clone());
	} else {
		$throwNew($CloneNotSupportedException);
	}
}

SignatureSpi::SignatureSpi() {
}

$Class* SignatureSpi::load$($String* name, bool initialize) {
	$loadClass(SignatureSpi, name, initialize, &_SignatureSpi_ClassInfo_, allocate$SignatureSpi);
	return class$;
}

$Class* SignatureSpi::class$ = nullptr;

	} // security
} // java