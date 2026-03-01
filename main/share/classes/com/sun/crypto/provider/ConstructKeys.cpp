#include <com/sun/crypto/provider/ConstructKeys.h>

#include <com/sun/crypto/provider/SunJCE.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/Key.h>
#include <java/security/KeyFactory.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/PrivateKey.h>
#include <java/security/Provider.h>
#include <java/security/PublicKey.h>
#include <java/security/spec/EncodedKeySpec.h>
#include <java/security/spec/InvalidKeySpecException.h>
#include <java/security/spec/KeySpec.h>
#include <java/security/spec/PKCS8EncodedKeySpec.h>
#include <java/security/spec/X509EncodedKeySpec.h>
#include <java/util/Arrays.h>
#include <javax/crypto/Cipher.h>
#include <javax/crypto/SecretKey.h>
#include <javax/crypto/spec/SecretKeySpec.h>
#include <jdk/internal/access/JavaSecuritySpecAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jcpp.h>

#undef PRIVATE_KEY
#undef PUBLIC_KEY
#undef SECRET_KEY

using $SunJCE = ::com::sun::crypto::provider::SunJCE;
using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $Key = ::java::security::Key;
using $KeyFactory = ::java::security::KeyFactory;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $PrivateKey = ::java::security::PrivateKey;
using $Provider = ::java::security::Provider;
using $PublicKey = ::java::security::PublicKey;
using $EncodedKeySpec = ::java::security::spec::EncodedKeySpec;
using $InvalidKeySpecException = ::java::security::spec::InvalidKeySpecException;
using $KeySpec = ::java::security::spec::KeySpec;
using $PKCS8EncodedKeySpec = ::java::security::spec::PKCS8EncodedKeySpec;
using $X509EncodedKeySpec = ::java::security::spec::X509EncodedKeySpec;
using $Arrays = ::java::util::Arrays;
using $Cipher = ::javax::crypto::Cipher;
using $SecretKey = ::javax::crypto::SecretKey;
using $SecretKeySpec = ::javax::crypto::spec::SecretKeySpec;
using $JavaSecuritySpecAccess = ::jdk::internal::access::JavaSecuritySpecAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;

namespace com {
	namespace sun {
		namespace crypto {
			namespace provider {

$MethodInfo _ConstructKeys_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(ConstructKeys, init$, void)},
	{"constructKey", "([BLjava/lang/String;I)Ljava/security/Key;", nullptr, $STATIC | $FINAL, $staticMethod(ConstructKeys, constructKey, $Key*, $bytes*, $String*, int32_t), "java.security.InvalidKeyException,java.security.NoSuchAlgorithmException"},
	{"constructKey", "([BIILjava/lang/String;I)Ljava/security/Key;", nullptr, $STATIC | $FINAL, $staticMethod(ConstructKeys, constructKey, $Key*, $bytes*, int32_t, int32_t, $String*, int32_t), "java.security.InvalidKeyException,java.security.NoSuchAlgorithmException"},
	{"constructPrivateKey", "([BIILjava/lang/String;)Ljava/security/PrivateKey;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticMethod(ConstructKeys, constructPrivateKey, $PrivateKey*, $bytes*, int32_t, int32_t, $String*), "java.security.InvalidKeyException,java.security.NoSuchAlgorithmException"},
	{"constructPublicKey", "([BIILjava/lang/String;)Ljava/security/PublicKey;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticMethod(ConstructKeys, constructPublicKey, $PublicKey*, $bytes*, int32_t, int32_t, $String*), "java.security.InvalidKeyException,java.security.NoSuchAlgorithmException"},
	{"constructSecretKey", "([BIILjava/lang/String;)Ljavax/crypto/SecretKey;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticMethod(ConstructKeys, constructSecretKey, $SecretKey*, $bytes*, int32_t, int32_t, $String*)},
	{}
};

$ClassInfo _ConstructKeys_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"com.sun.crypto.provider.ConstructKeys",
	"java.lang.Object",
	nullptr,
	nullptr,
	_ConstructKeys_MethodInfo_
};

$Object* allocate$ConstructKeys($Class* clazz) {
	return $of($alloc(ConstructKeys));
}

void ConstructKeys::init$() {
}

$PublicKey* ConstructKeys::constructPublicKey($bytes* encodedKey, int32_t ofs, int32_t len, $String* encodedKeyAlgorithm) {
	$useLocalCurrentObjectStackCache();
	$var($PublicKey, key, nullptr);
	$var($bytes, keyBytes, (ofs == 0 && $nc(encodedKey)->length == len) ? encodedKey : $Arrays::copyOfRange(encodedKey, ofs, ofs + len));
	$var($X509EncodedKeySpec, keySpec, $new($X509EncodedKeySpec, keyBytes));
	try {
		$var($KeyFactory, keyFactory, $KeyFactory::getInstance(encodedKeyAlgorithm, $(static_cast<$Provider*>($SunJCE::getInstance()))));
		$assign(key, $nc(keyFactory)->generatePublic(keySpec));
	} catch ($NoSuchAlgorithmException& nsae) {
		try {
			$var($KeyFactory, keyFactory, $KeyFactory::getInstance(encodedKeyAlgorithm));
			$assign(key, $nc(keyFactory)->generatePublic(keySpec));
		} catch ($NoSuchAlgorithmException& nsae2) {
			$throwNew($NoSuchAlgorithmException, $$str({"No installed providers can create keys for the "_s, encodedKeyAlgorithm, "algorithm"_s}));
		} catch ($InvalidKeySpecException& ikse2) {
			$var($InvalidKeyException, ike, $new($InvalidKeyException, "Cannot construct public key"_s));
			ike->initCause(ikse2);
			$throw(ike);
		}
	} catch ($InvalidKeySpecException& ikse) {
		$var($InvalidKeyException, ike, $new($InvalidKeyException, "Cannot construct public key"_s));
		ike->initCause(ikse);
		$throw(ike);
	}
	return key;
}

$PrivateKey* ConstructKeys::constructPrivateKey($bytes* encodedKey, int32_t ofs, int32_t len, $String* encodedKeyAlgorithm) {
	$useLocalCurrentObjectStackCache();
	$var($PrivateKey, key, nullptr);
	$var($bytes, keyBytes, (ofs == 0 && $nc(encodedKey)->length == len) ? encodedKey : $Arrays::copyOfRange(encodedKey, ofs, ofs + len));
	$var($PKCS8EncodedKeySpec, keySpec, $new($PKCS8EncodedKeySpec, keyBytes));
	{
		$var($Throwable, var$0, nullptr);
		$var($PrivateKey, var$2, nullptr);
		bool return$1 = false;
		try {
			try {
				$var($KeyFactory, keyFactory, $KeyFactory::getInstance(encodedKeyAlgorithm, $(static_cast<$Provider*>($SunJCE::getInstance()))));
				$assign(var$2, $nc(keyFactory)->generatePrivate(keySpec));
				return$1 = true;
				goto $finally;
			} catch ($NoSuchAlgorithmException& nsae) {
				try {
					$var($KeyFactory, keyFactory, $KeyFactory::getInstance(encodedKeyAlgorithm));
					$assign(key, $nc(keyFactory)->generatePrivate(keySpec));
				} catch ($NoSuchAlgorithmException& nsae2) {
					$throwNew($NoSuchAlgorithmException, $$str({"No installed providers can create keys for the "_s, encodedKeyAlgorithm, "algorithm"_s}));
				} catch ($InvalidKeySpecException& ikse2) {
					$var($InvalidKeyException, ike, $new($InvalidKeyException, "Cannot construct private key"_s));
					ike->initCause(ikse2);
					$throw(ike);
				}
			} catch ($InvalidKeySpecException& ikse) {
				$var($InvalidKeyException, ike, $new($InvalidKeyException, "Cannot construct private key"_s));
				ike->initCause(ikse);
				$throw(ike);
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc($($SharedSecrets::getJavaSecuritySpecAccess()))->clearEncodedKeySpec(keySpec);
			if (keyBytes != encodedKey) {
				$Arrays::fill(keyBytes, (int8_t)0);
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	return key;
}

$SecretKey* ConstructKeys::constructSecretKey($bytes* encodedKey, int32_t ofs, int32_t len, $String* encodedKeyAlgorithm) {
	return ($new($SecretKeySpec, encodedKey, ofs, len, encodedKeyAlgorithm));
}

$Key* ConstructKeys::constructKey($bytes* encoding, $String* keyAlgorithm, int32_t keyType) {
	return constructKey(encoding, 0, $nc(encoding)->length, keyAlgorithm, keyType);
}

$Key* ConstructKeys::constructKey($bytes* encoding, int32_t ofs, int32_t len, $String* keyAlgorithm, int32_t keyType) {

	$var($Key, var$0, nullptr)
	switch (keyType) {
	case $Cipher::SECRET_KEY:
		{
			$assign(var$0, ConstructKeys::constructSecretKey(encoding, ofs, len, keyAlgorithm));
			break;
		}
	case $Cipher::PRIVATE_KEY:
		{
			$assign(var$0, ConstructKeys::constructPrivateKey(encoding, ofs, len, keyAlgorithm));
			break;
		}
	case $Cipher::PUBLIC_KEY:
		{
			$assign(var$0, ConstructKeys::constructPublicKey(encoding, ofs, len, keyAlgorithm));
			break;
		}
	default:
		{
			$throwNew($NoSuchAlgorithmException, "Unsupported key type"_s);
		}
	}
	return var$0;
}

ConstructKeys::ConstructKeys() {
}

$Class* ConstructKeys::load$($String* name, bool initialize) {
	$loadClass(ConstructKeys, name, initialize, &_ConstructKeys_ClassInfo_, allocate$ConstructKeys);
	return class$;
}

$Class* ConstructKeys::class$ = nullptr;

			} // provider
		} // crypto
	} // sun
} // com