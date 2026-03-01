#include <sun/security/ssl/HandshakeHash$T13HandshakeHash.h>

#include <java/lang/Cloneable.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/security/MessageDigest.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <sun/security/ssl/CipherSuite$HashAlg.h>
#include <sun/security/ssl/CipherSuite.h>
#include <sun/security/ssl/HandshakeHash$CloneableHash.h>
#include <sun/security/ssl/HandshakeHash$NonCloneableHash.h>
#include <sun/security/ssl/HandshakeHash$TranscriptHash.h>
#include <sun/security/ssl/HandshakeHash.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $Cloneable = ::java::lang::Cloneable;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $MessageDigest = ::java::security::MessageDigest;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $CipherSuite = ::sun::security::ssl::CipherSuite;
using $HandshakeHash$CloneableHash = ::sun::security::ssl::HandshakeHash$CloneableHash;
using $HandshakeHash$NonCloneableHash = ::sun::security::ssl::HandshakeHash$NonCloneableHash;
using $HandshakeHash$TranscriptHash = ::sun::security::ssl::HandshakeHash$TranscriptHash;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _HandshakeHash$T13HandshakeHash_FieldInfo_[] = {
	{"transcriptHash", "Lsun/security/ssl/HandshakeHash$TranscriptHash;", nullptr, $PRIVATE | $FINAL, $field(HandshakeHash$T13HandshakeHash, transcriptHash)},
	{}
};

$MethodInfo _HandshakeHash$T13HandshakeHash_MethodInfo_[] = {
	{"<init>", "(Lsun/security/ssl/CipherSuite;)V", nullptr, 0, $method(HandshakeHash$T13HandshakeHash, init$, void, $CipherSuite*)},
	{"archived", "()[B", nullptr, $PUBLIC, $virtualMethod(HandshakeHash$T13HandshakeHash, archived, $bytes*)},
	{"digest", "()[B", nullptr, $PUBLIC, $virtualMethod(HandshakeHash$T13HandshakeHash, digest, $bytes*)},
	{"update", "([BII)V", nullptr, $PUBLIC, $virtualMethod(HandshakeHash$T13HandshakeHash, update, void, $bytes*, int32_t, int32_t)},
	{}
};

$InnerClassInfo _HandshakeHash$T13HandshakeHash_InnerClassesInfo_[] = {
	{"sun.security.ssl.HandshakeHash$T13HandshakeHash", "sun.security.ssl.HandshakeHash", "T13HandshakeHash", $STATIC | $FINAL},
	{"sun.security.ssl.HandshakeHash$TranscriptHash", "sun.security.ssl.HandshakeHash", "TranscriptHash", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _HandshakeHash$T13HandshakeHash_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.HandshakeHash$T13HandshakeHash",
	"java.lang.Object",
	"sun.security.ssl.HandshakeHash$TranscriptHash",
	_HandshakeHash$T13HandshakeHash_FieldInfo_,
	_HandshakeHash$T13HandshakeHash_MethodInfo_,
	nullptr,
	nullptr,
	_HandshakeHash$T13HandshakeHash_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.HandshakeHash"
};

$Object* allocate$HandshakeHash$T13HandshakeHash($Class* clazz) {
	return $of($alloc(HandshakeHash$T13HandshakeHash));
}

void HandshakeHash$T13HandshakeHash::init$($CipherSuite* cipherSuite) {
	$useLocalCurrentObjectStackCache();
	$var($MessageDigest, md, nullptr);
	try {
		$assign(md, $MessageDigest::getInstance($nc(cipherSuite)->hashAlg->name$));
	} catch ($NoSuchAlgorithmException& nsae) {
		$throwNew($RuntimeException, $$str({"Hash algorithm "_s, $nc(cipherSuite)->hashAlg->name$, " is not available"_s}), nsae);
	}
	if ($instanceOf($Cloneable, md)) {
		$set(this, transcriptHash, $new($HandshakeHash$CloneableHash, md));
	} else {
		$set(this, transcriptHash, $new($HandshakeHash$NonCloneableHash, md));
	}
}

void HandshakeHash$T13HandshakeHash::update($bytes* input, int32_t offset, int32_t length) {
	$nc(this->transcriptHash)->update(input, offset, length);
}

$bytes* HandshakeHash$T13HandshakeHash::digest() {
	return $nc(this->transcriptHash)->digest();
}

$bytes* HandshakeHash$T13HandshakeHash::archived() {
	$throwNew($UnsupportedOperationException, "TLS 1.3 does not require archived."_s);
	$shouldNotReachHere();
}

HandshakeHash$T13HandshakeHash::HandshakeHash$T13HandshakeHash() {
}

$Class* HandshakeHash$T13HandshakeHash::load$($String* name, bool initialize) {
	$loadClass(HandshakeHash$T13HandshakeHash, name, initialize, &_HandshakeHash$T13HandshakeHash_ClassInfo_, allocate$HandshakeHash$T13HandshakeHash);
	return class$;
}

$Class* HandshakeHash$T13HandshakeHash::class$ = nullptr;

		} // ssl
	} // security
} // sun