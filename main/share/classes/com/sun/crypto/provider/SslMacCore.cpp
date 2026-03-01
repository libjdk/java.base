#include <com/sun/crypto/provider/SslMacCore.h>

#include <java/nio/ByteBuffer.h>
#include <java/security/DigestException.h>
#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/Key.h>
#include <java/security/MessageDigest.h>
#include <java/security/ProviderException.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <javax/crypto/SecretKey.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $DigestException = ::java::security::DigestException;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $Key = ::java::security::Key;
using $MessageDigest = ::java::security::MessageDigest;
using $ProviderException = ::java::security::ProviderException;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $SecretKey = ::javax::crypto::SecretKey;

namespace com {
	namespace sun {
		namespace crypto {
			namespace provider {

$FieldInfo _SslMacCore_FieldInfo_[] = {
	{"md", "Ljava/security/MessageDigest;", nullptr, $PRIVATE | $FINAL, $field(SslMacCore, md)},
	{"pad1", "[B", nullptr, $PRIVATE | $FINAL, $field(SslMacCore, pad1)},
	{"pad2", "[B", nullptr, $PRIVATE | $FINAL, $field(SslMacCore, pad2)},
	{"first", "Z", nullptr, $PRIVATE, $field(SslMacCore, first)},
	{"secret", "[B", nullptr, $PRIVATE, $field(SslMacCore, secret)},
	{}
};

$MethodInfo _SslMacCore_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;[B[B)V", nullptr, 0, $method(SslMacCore, init$, void, $String*, $bytes*, $bytes*), "java.security.NoSuchAlgorithmException"},
	{"doFinal", "()[B", nullptr, 0, $method(SslMacCore, doFinal, $bytes*)},
	{"getDigestLength", "()I", nullptr, 0, $method(SslMacCore, getDigestLength, int32_t)},
	{"init", "(Ljava/security/Key;Ljava/security/spec/AlgorithmParameterSpec;)V", nullptr, 0, $method(SslMacCore, init, void, $Key*, $AlgorithmParameterSpec*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"reset", "()V", nullptr, 0, $method(SslMacCore, reset, void)},
	{"update", "(B)V", nullptr, 0, $method(SslMacCore, update, void, int8_t)},
	{"update", "([BII)V", nullptr, 0, $method(SslMacCore, update, void, $bytes*, int32_t, int32_t)},
	{"update", "(Ljava/nio/ByteBuffer;)V", nullptr, 0, $method(SslMacCore, update, void, $ByteBuffer*)},
	{}
};

$InnerClassInfo _SslMacCore_InnerClassesInfo_[] = {
	{"com.sun.crypto.provider.SslMacCore$SslMacSHA1", "com.sun.crypto.provider.SslMacCore", "SslMacSHA1", $PUBLIC | $STATIC | $FINAL},
	{"com.sun.crypto.provider.SslMacCore$SslMacMD5", "com.sun.crypto.provider.SslMacCore", "SslMacMD5", $PUBLIC | $STATIC | $FINAL},
	{}
};

$ClassInfo _SslMacCore_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"com.sun.crypto.provider.SslMacCore",
	"java.lang.Object",
	nullptr,
	_SslMacCore_FieldInfo_,
	_SslMacCore_MethodInfo_,
	nullptr,
	nullptr,
	_SslMacCore_InnerClassesInfo_,
	nullptr,
	nullptr,
	"com.sun.crypto.provider.SslMacCore$SslMacSHA1,com.sun.crypto.provider.SslMacCore$SslMacMD5"
};

$Object* allocate$SslMacCore($Class* clazz) {
	return $of($alloc(SslMacCore));
}

void SslMacCore::init$($String* digestAlgorithm, $bytes* pad1, $bytes* pad2) {
	$set(this, md, $MessageDigest::getInstance(digestAlgorithm));
	$set(this, pad1, pad1);
	$set(this, pad2, pad2);
	this->first = true;
}

int32_t SslMacCore::getDigestLength() {
	return $nc(this->md)->getDigestLength();
}

void SslMacCore::init($Key* key, $AlgorithmParameterSpec* params) {
	if (params != nullptr) {
		$throwNew($InvalidAlgorithmParameterException, "SslMac does not use parameters"_s);
	}
	if (!($instanceOf($SecretKey, key))) {
		$throwNew($InvalidKeyException, "Secret key expected"_s);
	}
	$set(this, secret, $nc(key)->getEncoded());
	if (this->secret == nullptr || $nc(this->secret)->length == 0) {
		$throwNew($InvalidKeyException, "Missing key data"_s);
	}
	reset();
}

void SslMacCore::update(int8_t input) {
	if (this->first == true) {
		$nc(this->md)->update(this->secret);
		$nc(this->md)->update(this->pad1);
		this->first = false;
	}
	$nc(this->md)->update(input);
}

void SslMacCore::update($bytes* input, int32_t offset, int32_t len) {
	if (this->first == true) {
		$nc(this->md)->update(this->secret);
		$nc(this->md)->update(this->pad1);
		this->first = false;
	}
	$nc(this->md)->update(input, offset, len);
}

void SslMacCore::update($ByteBuffer* input) {
	if (this->first == true) {
		$nc(this->md)->update(this->secret);
		$nc(this->md)->update(this->pad1);
		this->first = false;
	}
	$nc(this->md)->update(input);
}

$bytes* SslMacCore::doFinal() {
	if (this->first == true) {
		$nc(this->md)->update(this->secret);
		$nc(this->md)->update(this->pad1);
	} else {
		this->first = true;
	}
	try {
		$var($bytes, tmp, $nc(this->md)->digest());
		$nc(this->md)->update(this->secret);
		$nc(this->md)->update(this->pad2);
		$nc(this->md)->update(tmp);
		$nc(this->md)->digest(tmp, 0, $nc(tmp)->length);
		return tmp;
	} catch ($DigestException& e) {
		$throwNew($ProviderException, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

void SslMacCore::reset() {
	if (this->first == false) {
		$nc(this->md)->reset();
		this->first = true;
	}
}

SslMacCore::SslMacCore() {
}

$Class* SslMacCore::load$($String* name, bool initialize) {
	$loadClass(SslMacCore, name, initialize, &_SslMacCore_ClassInfo_, allocate$SslMacCore);
	return class$;
}

$Class* SslMacCore::class$ = nullptr;

			} // provider
		} // crypto
	} // sun
} // com