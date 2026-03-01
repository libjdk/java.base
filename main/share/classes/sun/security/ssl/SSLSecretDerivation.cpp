#include <sun/security/ssl/SSLSecretDerivation.h>

#include <java/io/IOException.h>
#include <java/lang/CharSequence.h>
#include <java/nio/ByteBuffer.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <javax/crypto/SecretKey.h>
#include <javax/net/ssl/SSLHandshakeException.h>
#include <sun/security/ssl/CipherSuite$HashAlg.h>
#include <sun/security/ssl/CipherSuite.h>
#include <sun/security/ssl/HKDF.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/HandshakeHash.h>
#include <sun/security/ssl/Record.h>
#include <sun/security/ssl/SSLSecretDerivation$SecretSchedule.h>
#include <jcpp.h>

#undef H_SHA256
#undef H_SHA384

using $IOException = ::java::io::IOException;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $SecretKey = ::javax::crypto::SecretKey;
using $SSLHandshakeException = ::javax::net::ssl::SSLHandshakeException;
using $CipherSuite$HashAlg = ::sun::security::ssl::CipherSuite$HashAlg;
using $HKDF = ::sun::security::ssl::HKDF;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $HandshakeHash = ::sun::security::ssl::HandshakeHash;
using $Record = ::sun::security::ssl::Record;
using $SSLSecretDerivation$SecretSchedule = ::sun::security::ssl::SSLSecretDerivation$SecretSchedule;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _SSLSecretDerivation_FieldInfo_[] = {
	{"sha256EmptyDigest", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SSLSecretDerivation, sha256EmptyDigest)},
	{"sha384EmptyDigest", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SSLSecretDerivation, sha384EmptyDigest)},
	{"hashAlg", "Lsun/security/ssl/CipherSuite$HashAlg;", nullptr, $PRIVATE | $FINAL, $field(SSLSecretDerivation, hashAlg)},
	{"secret", "Ljavax/crypto/SecretKey;", nullptr, $PRIVATE | $FINAL, $field(SSLSecretDerivation, secret)},
	{"transcriptHash", "[B", nullptr, $PRIVATE | $FINAL, $field(SSLSecretDerivation, transcriptHash)},
	{}
};

$MethodInfo _SSLSecretDerivation_MethodInfo_[] = {
	{"<init>", "(Lsun/security/ssl/HandshakeContext;Ljavax/crypto/SecretKey;)V", nullptr, 0, $method(SSLSecretDerivation, init$, void, $HandshakeContext*, $SecretKey*)},
	{"createHkdfInfo", "([B[BI)[B", nullptr, $PUBLIC | $STATIC, $staticMethod(SSLSecretDerivation, createHkdfInfo, $bytes*, $bytes*, $bytes*, int32_t)},
	{"deriveKey", "(Ljava/lang/String;Ljava/security/spec/AlgorithmParameterSpec;)Ljavax/crypto/SecretKey;", nullptr, $PUBLIC, $virtualMethod(SSLSecretDerivation, deriveKey, $SecretKey*, $String*, $AlgorithmParameterSpec*), "java.io.IOException"},
	{"forContext", "(Lsun/security/ssl/HandshakeContext;)Lsun/security/ssl/SSLSecretDerivation;", nullptr, 0, $method(SSLSecretDerivation, forContext, SSLSecretDerivation*, $HandshakeContext*)},
	{}
};

$InnerClassInfo _SSLSecretDerivation_InnerClassesInfo_[] = {
	{"sun.security.ssl.SSLSecretDerivation$SecretSchedule", "sun.security.ssl.SSLSecretDerivation", "SecretSchedule", $PRIVATE | $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _SSLSecretDerivation_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.SSLSecretDerivation",
	"java.lang.Object",
	"sun.security.ssl.SSLKeyDerivation",
	_SSLSecretDerivation_FieldInfo_,
	_SSLSecretDerivation_MethodInfo_,
	nullptr,
	nullptr,
	_SSLSecretDerivation_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.ssl.SSLSecretDerivation$SecretSchedule"
};

$Object* allocate$SSLSecretDerivation($Class* clazz) {
	return $of($alloc(SSLSecretDerivation));
}

$bytes* SSLSecretDerivation::sha256EmptyDigest = nullptr;
$bytes* SSLSecretDerivation::sha384EmptyDigest = nullptr;

void SSLSecretDerivation::init$($HandshakeContext* context, $SecretKey* secret) {
	$useLocalCurrentObjectStackCache();
	$set(this, secret, secret);
	$set(this, hashAlg, $nc($nc(context)->negotiatedCipherSuite)->hashAlg);
	$var($String, hkdfAlg, $str({"HKDF-Expand/Hmac"_s, $($nc(this->hashAlg->name$)->replace(static_cast<$CharSequence*>("-"_s), static_cast<$CharSequence*>(""_s)))}));
	$nc(context->handshakeHash)->update();
	$set(this, transcriptHash, $nc(context->handshakeHash)->digest());
}

SSLSecretDerivation* SSLSecretDerivation::forContext($HandshakeContext* context) {
	return $new(SSLSecretDerivation, context, this->secret);
}

$SecretKey* SSLSecretDerivation::deriveKey($String* algorithm, $AlgorithmParameterSpec* params) {
	$useLocalCurrentObjectStackCache();
	$SSLSecretDerivation$SecretSchedule* ks = $SSLSecretDerivation$SecretSchedule::valueOf(algorithm);
	try {
		$var($bytes, expandContext, nullptr);
		if (ks == $SSLSecretDerivation$SecretSchedule::TlsSaltSecret) {
			$init($CipherSuite$HashAlg);
			if (this->hashAlg == $CipherSuite$HashAlg::H_SHA256) {
				$assign(expandContext, SSLSecretDerivation::sha256EmptyDigest);
			} else {
				if (this->hashAlg == $CipherSuite$HashAlg::H_SHA384) {
					$assign(expandContext, SSLSecretDerivation::sha384EmptyDigest);
				} else {
					$throwNew($SSLHandshakeException, $$str({"Unexpected unsupported hash algorithm: "_s, algorithm}));
				}
			}
		} else {
			$assign(expandContext, this->transcriptHash);
		}
		$var($bytes, hkdfInfo, createHkdfInfo($nc(ks)->label, expandContext, this->hashAlg->hashLength));
		$var($HKDF, hkdf, $new($HKDF, this->hashAlg->name$));
		return hkdf->expand(this->secret, hkdfInfo, this->hashAlg->hashLength, algorithm);
	} catch ($GeneralSecurityException& gse) {
		$throw($cast($SSLHandshakeException, $($$new($SSLHandshakeException, "Could not generate secret"_s)->initCause(gse))));
	}
	$shouldNotReachHere();
}

$bytes* SSLSecretDerivation::createHkdfInfo($bytes* label, $bytes* context, int32_t length) {
	$init(SSLSecretDerivation);
	$useLocalCurrentObjectStackCache();
	$var($bytes, info, $new($bytes, 4 + $nc(label)->length + $nc(context)->length));
	$var($ByteBuffer, m, $ByteBuffer::wrap(info));
	try {
		$Record::putInt16(m, length);
		$Record::putBytes8(m, label);
		$Record::putBytes8(m, context);
	} catch ($IOException& ioe) {
		$throwNew($RuntimeException, "Unexpected exception"_s, ioe);
	}
	return info;
}

void clinit$SSLSecretDerivation($Class* class$) {
	$assignStatic(SSLSecretDerivation::sha256EmptyDigest, $new($bytes, {
		(int8_t)227,
		(int8_t)176,
		(int8_t)196,
		(int8_t)66,
		(int8_t)152,
		(int8_t)252,
		(int8_t)28,
		(int8_t)20,
		(int8_t)154,
		(int8_t)251,
		(int8_t)244,
		(int8_t)200,
		(int8_t)153,
		(int8_t)111,
		(int8_t)185,
		(int8_t)36,
		(int8_t)39,
		(int8_t)174,
		(int8_t)65,
		(int8_t)228,
		(int8_t)100,
		(int8_t)155,
		(int8_t)147,
		(int8_t)76,
		(int8_t)164,
		(int8_t)149,
		(int8_t)153,
		(int8_t)27,
		(int8_t)120,
		(int8_t)82,
		(int8_t)184,
		(int8_t)85
	}));
	$assignStatic(SSLSecretDerivation::sha384EmptyDigest, $new($bytes, {
		(int8_t)56,
		(int8_t)176,
		(int8_t)96,
		(int8_t)167,
		(int8_t)81,
		(int8_t)172,
		(int8_t)150,
		(int8_t)56,
		(int8_t)76,
		(int8_t)217,
		(int8_t)50,
		(int8_t)126,
		(int8_t)177,
		(int8_t)177,
		(int8_t)227,
		(int8_t)106,
		(int8_t)33,
		(int8_t)253,
		(int8_t)183,
		(int8_t)17,
		(int8_t)20,
		(int8_t)190,
		(int8_t)7,
		(int8_t)67,
		(int8_t)76,
		(int8_t)12,
		(int8_t)199,
		(int8_t)191,
		(int8_t)99,
		(int8_t)246,
		(int8_t)225,
		(int8_t)218,
		(int8_t)39,
		(int8_t)78,
		(int8_t)222,
		(int8_t)191,
		(int8_t)231,
		(int8_t)111,
		(int8_t)101,
		(int8_t)251,
		(int8_t)213,
		(int8_t)26,
		(int8_t)210,
		(int8_t)241,
		(int8_t)72,
		(int8_t)152,
		(int8_t)185,
		(int8_t)91
	}));
}

SSLSecretDerivation::SSLSecretDerivation() {
}

$Class* SSLSecretDerivation::load$($String* name, bool initialize) {
	$loadClass(SSLSecretDerivation, name, initialize, &_SSLSecretDerivation_ClassInfo_, clinit$SSLSecretDerivation, allocate$SSLSecretDerivation);
	return class$;
}

$Class* SSLSecretDerivation::class$ = nullptr;

		} // ssl
	} // security
} // sun