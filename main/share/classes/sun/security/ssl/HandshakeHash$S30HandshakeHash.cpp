#include <sun/security/ssl/HandshakeHash$S30HandshakeHash.h>

#include <java/io/ByteArrayOutputStream.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/Cloneable.h>
#include <java/security/MessageDigest.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/util/Arrays.h>
#include <javax/crypto/SecretKey.h>
#include <sun/security/ssl/CipherSuite.h>
#include <sun/security/ssl/HandshakeHash$CloneableHash.h>
#include <sun/security/ssl/HandshakeHash$NonCloneableHash.h>
#include <sun/security/ssl/HandshakeHash$TranscriptHash.h>
#include <sun/security/ssl/HandshakeHash.h>
#include <sun/security/util/MessageDigestSpi2.h>
#include <jcpp.h>

#undef SSL_CLIENT
#undef SSL_SERVER

using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $Cloneable = ::java::lang::Cloneable;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $MessageDigest = ::java::security::MessageDigest;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $Arrays = ::java::util::Arrays;
using $SecretKey = ::javax::crypto::SecretKey;
using $CipherSuite = ::sun::security::ssl::CipherSuite;
using $HandshakeHash$CloneableHash = ::sun::security::ssl::HandshakeHash$CloneableHash;
using $HandshakeHash$NonCloneableHash = ::sun::security::ssl::HandshakeHash$NonCloneableHash;
using $HandshakeHash$TranscriptHash = ::sun::security::ssl::HandshakeHash$TranscriptHash;
using $MessageDigestSpi2 = ::sun::security::util::MessageDigestSpi2;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _HandshakeHash$S30HandshakeHash_FieldInfo_[] = {
	{"MD5_pad1", "[B", nullptr, $STATIC | $FINAL, $staticField(HandshakeHash$S30HandshakeHash, MD5_pad1)},
	{"MD5_pad2", "[B", nullptr, $STATIC | $FINAL, $staticField(HandshakeHash$S30HandshakeHash, MD5_pad2)},
	{"SHA_pad1", "[B", nullptr, $STATIC | $FINAL, $staticField(HandshakeHash$S30HandshakeHash, SHA_pad1)},
	{"SHA_pad2", "[B", nullptr, $STATIC | $FINAL, $staticField(HandshakeHash$S30HandshakeHash, SHA_pad2)},
	{"SSL_CLIENT", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HandshakeHash$S30HandshakeHash, SSL_CLIENT)},
	{"SSL_SERVER", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HandshakeHash$S30HandshakeHash, SSL_SERVER)},
	{"mdMD5", "Ljava/security/MessageDigest;", nullptr, $PRIVATE | $FINAL, $field(HandshakeHash$S30HandshakeHash, mdMD5)},
	{"mdSHA", "Ljava/security/MessageDigest;", nullptr, $PRIVATE | $FINAL, $field(HandshakeHash$S30HandshakeHash, mdSHA)},
	{"md5", "Lsun/security/ssl/HandshakeHash$TranscriptHash;", nullptr, $PRIVATE | $FINAL, $field(HandshakeHash$S30HandshakeHash, md5)},
	{"sha", "Lsun/security/ssl/HandshakeHash$TranscriptHash;", nullptr, $PRIVATE | $FINAL, $field(HandshakeHash$S30HandshakeHash, sha)},
	{"baos", "Ljava/io/ByteArrayOutputStream;", nullptr, $PRIVATE | $FINAL, $field(HandshakeHash$S30HandshakeHash, baos)},
	{}
};

$MethodInfo _HandshakeHash$S30HandshakeHash_MethodInfo_[] = {
	{"<init>", "(Lsun/security/ssl/CipherSuite;)V", nullptr, 0, $method(HandshakeHash$S30HandshakeHash, init$, void, $CipherSuite*)},
	{"archived", "()[B", nullptr, $PUBLIC, $virtualMethod(HandshakeHash$S30HandshakeHash, archived, $bytes*)},
	{"cloneMd5", "()Ljava/security/MessageDigest;", nullptr, $PRIVATE, $method(HandshakeHash$S30HandshakeHash, cloneMd5, $MessageDigest*)},
	{"cloneSha", "()Ljava/security/MessageDigest;", nullptr, $PRIVATE, $method(HandshakeHash$S30HandshakeHash, cloneSha, $MessageDigest*)},
	{"digest", "()[B", nullptr, $PUBLIC, $virtualMethod(HandshakeHash$S30HandshakeHash, digest, $bytes*)},
	{"digest", "(ZLjavax/crypto/SecretKey;)[B", nullptr, 0, $method(HandshakeHash$S30HandshakeHash, digest, $bytes*, bool, $SecretKey*)},
	{"digest", "(Ljava/lang/String;Ljavax/crypto/SecretKey;)[B", nullptr, 0, $method(HandshakeHash$S30HandshakeHash, digest, $bytes*, $String*, $SecretKey*)},
	{"digestKey", "(Ljava/security/MessageDigest;Ljavax/crypto/SecretKey;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(HandshakeHash$S30HandshakeHash, digestKey, void, $MessageDigest*, $SecretKey*)},
	{"genPad", "(II)[B", nullptr, $PRIVATE | $STATIC, $staticMethod(HandshakeHash$S30HandshakeHash, genPad, $bytes*, int32_t, int32_t)},
	{"update", "([BII)V", nullptr, $PUBLIC, $virtualMethod(HandshakeHash$S30HandshakeHash, update, void, $bytes*, int32_t, int32_t)},
	{"updateDigest", "(Ljava/security/MessageDigest;[B[BLjavax/crypto/SecretKey;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(HandshakeHash$S30HandshakeHash, updateDigest, void, $MessageDigest*, $bytes*, $bytes*, $SecretKey*)},
	{}
};

$InnerClassInfo _HandshakeHash$S30HandshakeHash_InnerClassesInfo_[] = {
	{"sun.security.ssl.HandshakeHash$S30HandshakeHash", "sun.security.ssl.HandshakeHash", "S30HandshakeHash", $STATIC | $FINAL},
	{"sun.security.ssl.HandshakeHash$TranscriptHash", "sun.security.ssl.HandshakeHash", "TranscriptHash", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _HandshakeHash$S30HandshakeHash_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.HandshakeHash$S30HandshakeHash",
	"java.lang.Object",
	"sun.security.ssl.HandshakeHash$TranscriptHash",
	_HandshakeHash$S30HandshakeHash_FieldInfo_,
	_HandshakeHash$S30HandshakeHash_MethodInfo_,
	nullptr,
	nullptr,
	_HandshakeHash$S30HandshakeHash_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.HandshakeHash"
};

$Object* allocate$HandshakeHash$S30HandshakeHash($Class* clazz) {
	return $of($alloc(HandshakeHash$S30HandshakeHash));
}

$bytes* HandshakeHash$S30HandshakeHash::MD5_pad1 = nullptr;
$bytes* HandshakeHash$S30HandshakeHash::MD5_pad2 = nullptr;
$bytes* HandshakeHash$S30HandshakeHash::SHA_pad1 = nullptr;
$bytes* HandshakeHash$S30HandshakeHash::SHA_pad2 = nullptr;
$bytes* HandshakeHash$S30HandshakeHash::SSL_CLIENT = nullptr;
$bytes* HandshakeHash$S30HandshakeHash::SSL_SERVER = nullptr;

void HandshakeHash$S30HandshakeHash::init$($CipherSuite* cipherSuite) {
	try {
		$set(this, mdMD5, $MessageDigest::getInstance("MD5"_s));
		$set(this, mdSHA, $MessageDigest::getInstance("SHA"_s));
	} catch ($NoSuchAlgorithmException& nsae) {
		$throwNew($RuntimeException, "Hash algorithm MD5 or SHA is not available"_s, nsae);
	}
	bool hasArchived = false;
	if ($instanceOf($Cloneable, this->mdMD5)) {
		$set(this, md5, $new($HandshakeHash$CloneableHash, this->mdMD5));
	} else {
		hasArchived = true;
		$set(this, md5, $new($HandshakeHash$NonCloneableHash, this->mdMD5));
	}
	if ($instanceOf($Cloneable, this->mdSHA)) {
		$set(this, sha, $new($HandshakeHash$CloneableHash, this->mdSHA));
	} else {
		hasArchived = true;
		$set(this, sha, $new($HandshakeHash$NonCloneableHash, this->mdSHA));
	}
	if (hasArchived) {
		$set(this, baos, nullptr);
	} else {
		$set(this, baos, $new($ByteArrayOutputStream));
	}
}

void HandshakeHash$S30HandshakeHash::update($bytes* input, int32_t offset, int32_t length) {
	$nc(this->md5)->update(input, offset, length);
	$nc(this->sha)->update(input, offset, length);
	if (this->baos != nullptr) {
		$nc(this->baos)->write(input, offset, length);
	}
}

$bytes* HandshakeHash$S30HandshakeHash::digest() {
	$useLocalCurrentObjectStackCache();
	$var($bytes, digest, $new($bytes, 36));
	$System::arraycopy($($nc(this->md5)->digest()), 0, digest, 0, 16);
	$System::arraycopy($($nc(this->sha)->digest()), 0, digest, 16, 20);
	return digest;
}

$bytes* HandshakeHash$S30HandshakeHash::archived() {
	if (this->baos != nullptr) {
		return $nc(this->baos)->toByteArray();
	} else if ($instanceOf($HandshakeHash$NonCloneableHash, this->md5)) {
		return $nc(this->md5)->archived();
	} else {
		return $nc(this->sha)->archived();
	}
}

$bytes* HandshakeHash$S30HandshakeHash::digest(bool useClientLabel, $SecretKey* masterSecret) {
	$useLocalCurrentObjectStackCache();
	$var($MessageDigest, md5Clone, cloneMd5());
	$var($MessageDigest, shaClone, cloneSha());
	if (useClientLabel) {
		$nc(md5Clone)->update(HandshakeHash$S30HandshakeHash::SSL_CLIENT);
		$nc(shaClone)->update(HandshakeHash$S30HandshakeHash::SSL_CLIENT);
	} else {
		$nc(md5Clone)->update(HandshakeHash$S30HandshakeHash::SSL_SERVER);
		$nc(shaClone)->update(HandshakeHash$S30HandshakeHash::SSL_SERVER);
	}
	updateDigest(md5Clone, HandshakeHash$S30HandshakeHash::MD5_pad1, HandshakeHash$S30HandshakeHash::MD5_pad2, masterSecret);
	updateDigest(shaClone, HandshakeHash$S30HandshakeHash::SHA_pad1, HandshakeHash$S30HandshakeHash::SHA_pad2, masterSecret);
	$var($bytes, digest, $new($bytes, 36));
	$System::arraycopy($($nc(md5Clone)->digest()), 0, digest, 0, 16);
	$System::arraycopy($($nc(shaClone)->digest()), 0, digest, 16, 20);
	return digest;
}

$bytes* HandshakeHash$S30HandshakeHash::digest($String* algorithm, $SecretKey* masterSecret) {
	$useLocalCurrentObjectStackCache();
	if ("RSA"_s->equalsIgnoreCase(algorithm)) {
		$var($MessageDigest, md5Clone, cloneMd5());
		$var($MessageDigest, shaClone, cloneSha());
		updateDigest(md5Clone, HandshakeHash$S30HandshakeHash::MD5_pad1, HandshakeHash$S30HandshakeHash::MD5_pad2, masterSecret);
		updateDigest(shaClone, HandshakeHash$S30HandshakeHash::SHA_pad1, HandshakeHash$S30HandshakeHash::SHA_pad2, masterSecret);
		$var($bytes, digest, $new($bytes, 36));
		$System::arraycopy($($nc(md5Clone)->digest()), 0, digest, 0, 16);
		$System::arraycopy($($nc(shaClone)->digest()), 0, digest, 16, 20);
		return digest;
	} else {
		$var($MessageDigest, shaClone, cloneSha());
		updateDigest(shaClone, HandshakeHash$S30HandshakeHash::SHA_pad1, HandshakeHash$S30HandshakeHash::SHA_pad2, masterSecret);
		return $nc(shaClone)->digest();
	}
}

$bytes* HandshakeHash$S30HandshakeHash::genPad(int32_t b, int32_t count) {
	$init(HandshakeHash$S30HandshakeHash);
	$var($bytes, padding, $new($bytes, count));
	$Arrays::fill(padding, (int8_t)b);
	return padding;
}

$MessageDigest* HandshakeHash$S30HandshakeHash::cloneMd5() {
	$useLocalCurrentObjectStackCache();
	$var($MessageDigest, md5Clone, nullptr);
	if ($instanceOf($Cloneable, this->mdMD5)) {
		try {
			$assign(md5Clone, $cast($MessageDigest, $nc(this->mdMD5)->clone()));
		} catch ($CloneNotSupportedException& ex) {
			$throwNew($RuntimeException, "MessageDigest does no support clone operation"_s);
		}
	} else {
		try {
			$assign(md5Clone, $MessageDigest::getInstance("MD5"_s));
		} catch ($NoSuchAlgorithmException& nsae) {
			$throwNew($RuntimeException, "Hash algorithm MD5 is not available"_s, nsae);
		}
		$nc(md5Clone)->update($($nc(this->md5)->archived()));
	}
	return md5Clone;
}

$MessageDigest* HandshakeHash$S30HandshakeHash::cloneSha() {
	$useLocalCurrentObjectStackCache();
	$var($MessageDigest, shaClone, nullptr);
	if ($instanceOf($Cloneable, this->mdSHA)) {
		try {
			$assign(shaClone, $cast($MessageDigest, $nc(this->mdSHA)->clone()));
		} catch ($CloneNotSupportedException& ex) {
			$throwNew($RuntimeException, "MessageDigest does no support clone operation"_s);
		}
	} else {
		try {
			$assign(shaClone, $MessageDigest::getInstance("SHA"_s));
		} catch ($NoSuchAlgorithmException& nsae) {
			$throwNew($RuntimeException, "Hash algorithm SHA is not available"_s, nsae);
		}
		$nc(shaClone)->update($($nc(this->sha)->archived()));
	}
	return shaClone;
}

void HandshakeHash$S30HandshakeHash::updateDigest($MessageDigest* md, $bytes* pad1, $bytes* pad2, $SecretKey* masterSecret) {
	$init(HandshakeHash$S30HandshakeHash);
	$useLocalCurrentObjectStackCache();
	$var($bytes, keyBytes, "RAW"_s->equals($($nc(masterSecret)->getFormat())) ? $nc(masterSecret)->getEncoded() : ($bytes*)nullptr);
	if (keyBytes != nullptr) {
		$nc(md)->update(keyBytes);
	} else {
		digestKey(md, masterSecret);
	}
	$nc(md)->update(pad1);
	$var($bytes, temp, md->digest());
	if (keyBytes != nullptr) {
		md->update(keyBytes);
	} else {
		digestKey(md, masterSecret);
	}
	md->update(pad2);
	md->update(temp);
}

void HandshakeHash$S30HandshakeHash::digestKey($MessageDigest* md, $SecretKey* key) {
	$init(HandshakeHash$S30HandshakeHash);
	try {
		if ($instanceOf($MessageDigestSpi2, md)) {
			$nc(($cast($MessageDigestSpi2, md)))->engineUpdate(key);
		} else {
			$throwNew($Exception, "Digest does not support implUpdate(SecretKey)"_s);
		}
	} catch ($Exception& e) {
		$throwNew($RuntimeException, "Could not obtain encoded key and MessageDigest cannot digest key"_s, e);
	}
}

void clinit$HandshakeHash$S30HandshakeHash($Class* class$) {
	$assignStatic(HandshakeHash$S30HandshakeHash::MD5_pad1, HandshakeHash$S30HandshakeHash::genPad(54, 48));
	$assignStatic(HandshakeHash$S30HandshakeHash::MD5_pad2, HandshakeHash$S30HandshakeHash::genPad(92, 48));
	$assignStatic(HandshakeHash$S30HandshakeHash::SHA_pad1, HandshakeHash$S30HandshakeHash::genPad(54, 40));
	$assignStatic(HandshakeHash$S30HandshakeHash::SHA_pad2, HandshakeHash$S30HandshakeHash::genPad(92, 40));
	$assignStatic(HandshakeHash$S30HandshakeHash::SSL_CLIENT, $new($bytes, {
		(int8_t)67,
		(int8_t)76,
		(int8_t)78,
		(int8_t)84
	}));
	$assignStatic(HandshakeHash$S30HandshakeHash::SSL_SERVER, $new($bytes, {
		(int8_t)83,
		(int8_t)82,
		(int8_t)86,
		(int8_t)82
	}));
}

HandshakeHash$S30HandshakeHash::HandshakeHash$S30HandshakeHash() {
}

$Class* HandshakeHash$S30HandshakeHash::load$($String* name, bool initialize) {
	$loadClass(HandshakeHash$S30HandshakeHash, name, initialize, &_HandshakeHash$S30HandshakeHash_ClassInfo_, clinit$HandshakeHash$S30HandshakeHash, allocate$HandshakeHash$S30HandshakeHash);
	return class$;
}

$Class* HandshakeHash$S30HandshakeHash::class$ = nullptr;

		} // ssl
	} // security
} // sun