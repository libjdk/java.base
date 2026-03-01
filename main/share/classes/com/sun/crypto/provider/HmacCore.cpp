#include <com/sun/crypto/provider/HmacCore.h>

#include <java/lang/Cloneable.h>
#include <java/nio/ByteBuffer.h>
#include <java/security/DigestException.h>
#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/Key.h>
#include <java/security/MessageDigest.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/Provider.h>
#include <java/security/ProviderException.h>
#include <java/security/Security.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/util/Arrays.h>
#include <javax/crypto/MacSpi.h>
#include <javax/crypto/SecretKey.h>
#include <jcpp.h>

using $ProviderArray = $Array<::java::security::Provider>;
using $ClassInfo = ::java::lang::ClassInfo;
using $Cloneable = ::java::lang::Cloneable;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $DigestException = ::java::security::DigestException;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $Key = ::java::security::Key;
using $MessageDigest = ::java::security::MessageDigest;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $Provider = ::java::security::Provider;
using $ProviderException = ::java::security::ProviderException;
using $Security = ::java::security::Security;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $Arrays = ::java::util::Arrays;
using $MacSpi = ::javax::crypto::MacSpi;
using $SecretKey = ::javax::crypto::SecretKey;

namespace com {
	namespace sun {
		namespace crypto {
			namespace provider {

$FieldInfo _HmacCore_FieldInfo_[] = {
	{"md", "Ljava/security/MessageDigest;", nullptr, $PRIVATE, $field(HmacCore, md)},
	{"k_ipad", "[B", nullptr, $PRIVATE, $field(HmacCore, k_ipad)},
	{"k_opad", "[B", nullptr, $PRIVATE, $field(HmacCore, k_opad)},
	{"first", "Z", nullptr, $PRIVATE, $field(HmacCore, first)},
	{"blockLen", "I", nullptr, $PRIVATE | $FINAL, $field(HmacCore, blockLen)},
	{}
};

$MethodInfo _HmacCore_MethodInfo_[] = {
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/lang/String;I)V", nullptr, 0, $method(HmacCore, init$, void, $String*, int32_t), "java.security.NoSuchAlgorithmException"},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(HmacCore, clone, $Object*), "java.lang.CloneNotSupportedException"},
	{"engineDoFinal", "()[B", nullptr, $PROTECTED, $virtualMethod(HmacCore, engineDoFinal, $bytes*)},
	{"engineGetMacLength", "()I", nullptr, $PROTECTED, $virtualMethod(HmacCore, engineGetMacLength, int32_t)},
	{"engineInit", "(Ljava/security/Key;Ljava/security/spec/AlgorithmParameterSpec;)V", nullptr, $PROTECTED, $virtualMethod(HmacCore, engineInit, void, $Key*, $AlgorithmParameterSpec*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"engineReset", "()V", nullptr, $PROTECTED, $virtualMethod(HmacCore, engineReset, void)},
	{"engineUpdate", "(B)V", nullptr, $PROTECTED, $virtualMethod(HmacCore, engineUpdate, void, int8_t)},
	{"engineUpdate", "([BII)V", nullptr, $PROTECTED, $virtualMethod(HmacCore, engineUpdate, void, $bytes*, int32_t, int32_t)},
	{"engineUpdate", "(Ljava/nio/ByteBuffer;)V", nullptr, $PROTECTED, $virtualMethod(HmacCore, engineUpdate, void, $ByteBuffer*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _HmacCore_InnerClassesInfo_[] = {
	{"com.sun.crypto.provider.HmacCore$HmacSHA3_512", "com.sun.crypto.provider.HmacCore", "HmacSHA3_512", $PUBLIC | $STATIC | $FINAL},
	{"com.sun.crypto.provider.HmacCore$HmacSHA3_384", "com.sun.crypto.provider.HmacCore", "HmacSHA3_384", $PUBLIC | $STATIC | $FINAL},
	{"com.sun.crypto.provider.HmacCore$HmacSHA3_256", "com.sun.crypto.provider.HmacCore", "HmacSHA3_256", $PUBLIC | $STATIC | $FINAL},
	{"com.sun.crypto.provider.HmacCore$HmacSHA3_224", "com.sun.crypto.provider.HmacCore", "HmacSHA3_224", $PUBLIC | $STATIC | $FINAL},
	{"com.sun.crypto.provider.HmacCore$HmacSHA512_256", "com.sun.crypto.provider.HmacCore", "HmacSHA512_256", $PUBLIC | $STATIC | $FINAL},
	{"com.sun.crypto.provider.HmacCore$HmacSHA512_224", "com.sun.crypto.provider.HmacCore", "HmacSHA512_224", $PUBLIC | $STATIC | $FINAL},
	{"com.sun.crypto.provider.HmacCore$HmacSHA512", "com.sun.crypto.provider.HmacCore", "HmacSHA512", $PUBLIC | $STATIC | $FINAL},
	{"com.sun.crypto.provider.HmacCore$HmacSHA384", "com.sun.crypto.provider.HmacCore", "HmacSHA384", $PUBLIC | $STATIC | $FINAL},
	{"com.sun.crypto.provider.HmacCore$HmacSHA256", "com.sun.crypto.provider.HmacCore", "HmacSHA256", $PUBLIC | $STATIC | $FINAL},
	{"com.sun.crypto.provider.HmacCore$HmacSHA224", "com.sun.crypto.provider.HmacCore", "HmacSHA224", $PUBLIC | $STATIC | $FINAL},
	{}
};

$ClassInfo _HmacCore_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"com.sun.crypto.provider.HmacCore",
	"javax.crypto.MacSpi",
	"java.lang.Cloneable",
	_HmacCore_FieldInfo_,
	_HmacCore_MethodInfo_,
	nullptr,
	nullptr,
	_HmacCore_InnerClassesInfo_,
	nullptr,
	nullptr,
	"com.sun.crypto.provider.HmacCore$HmacSHA3_512,com.sun.crypto.provider.HmacCore$HmacSHA3_384,com.sun.crypto.provider.HmacCore$HmacSHA3_256,com.sun.crypto.provider.HmacCore$HmacSHA3_224,com.sun.crypto.provider.HmacCore$HmacSHA512_256,com.sun.crypto.provider.HmacCore$HmacSHA512_224,com.sun.crypto.provider.HmacCore$HmacSHA512,com.sun.crypto.provider.HmacCore$HmacSHA384,com.sun.crypto.provider.HmacCore$HmacSHA256,com.sun.crypto.provider.HmacCore$HmacSHA224"
};

$Object* allocate$HmacCore($Class* clazz) {
	return $of($alloc(HmacCore));
}

int32_t HmacCore::hashCode() {
	 return this->$MacSpi::hashCode();
}

bool HmacCore::equals(Object$* obj) {
	 return this->$MacSpi::equals(obj);
}

$String* HmacCore::toString() {
	 return this->$MacSpi::toString();
}

void HmacCore::finalize() {
	this->$MacSpi::finalize();
}

void HmacCore::init$($String* digestAlgo, int32_t bl) {
	$useLocalCurrentObjectStackCache();
	$MacSpi::init$();
	$var($MessageDigest, md, $MessageDigest::getInstance(digestAlgo));
	if (!($instanceOf($Cloneable, md))) {
		$var($Provider, sun, $Security::getProvider("SUN"_s));
		if (sun != nullptr) {
			$assign(md, $MessageDigest::getInstance(digestAlgo, sun));
		} else {
			$var($String, noCloneProv, $nc($($nc(md)->getProvider()))->getName());
			$assign(md, nullptr);
			$var($ProviderArray, provs, $Security::getProviders());
			{
				$var($ProviderArray, arr$, provs);
				int32_t len$ = $nc(arr$)->length;
				int32_t i$ = 0;
				for (; i$ < len$; ++i$) {
					$var($Provider, p, arr$->get(i$));
					{
						try {
							if (!$nc($($nc(p)->getName()))->equals(noCloneProv)) {
								$var($MessageDigest, md2, $MessageDigest::getInstance(digestAlgo, p));
								if ($instanceOf($Cloneable, md2)) {
									$assign(md, md2);
									break;
								}
							}
						} catch ($NoSuchAlgorithmException& nsae) {
							continue;
						}
					}
				}
			}
			if (md == nullptr) {
				$throwNew($NoSuchAlgorithmException, $$str({"No Cloneable digest found for "_s, digestAlgo}));
			}
		}
	}
	$set(this, md, md);
	this->blockLen = bl;
	$set(this, k_ipad, $new($bytes, this->blockLen));
	$set(this, k_opad, $new($bytes, this->blockLen));
	this->first = true;
}

int32_t HmacCore::engineGetMacLength() {
	return $nc(this->md)->getDigestLength();
}

void HmacCore::engineInit($Key* key, $AlgorithmParameterSpec* params) {
	$useLocalCurrentObjectStackCache();
	if (params != nullptr) {
		$throwNew($InvalidAlgorithmParameterException, "HMAC does not use parameters"_s);
	}
	if (!($instanceOf($SecretKey, key))) {
		$throwNew($InvalidKeyException, "Secret key expected"_s);
	}
	$var($bytes, secret, $nc(key)->getEncoded());
	if (secret == nullptr) {
		$throwNew($InvalidKeyException, "Missing key data"_s);
	}
	if ($nc(secret)->length > this->blockLen) {
		$var($bytes, tmp, $nc(this->md)->digest(secret));
		$Arrays::fill(secret, (int8_t)0);
		$assign(secret, tmp);
	}
	for (int32_t i = 0; i < this->blockLen; ++i) {
		int32_t si = (i < $nc(secret)->length) ? $nc(secret)->get(i) : (int8_t)0;
		$nc(this->k_ipad)->set(i, (int8_t)(si ^ 54));
		$nc(this->k_opad)->set(i, (int8_t)(si ^ 92));
	}
	$Arrays::fill(secret, (int8_t)0);
	$assign(secret, nullptr);
	engineReset();
}

void HmacCore::engineUpdate(int8_t input) {
	if (this->first == true) {
		$nc(this->md)->update(this->k_ipad);
		this->first = false;
	}
	$nc(this->md)->update(input);
}

void HmacCore::engineUpdate($bytes* input, int32_t offset, int32_t len) {
	if (this->first == true) {
		$nc(this->md)->update(this->k_ipad);
		this->first = false;
	}
	$nc(this->md)->update(input, offset, len);
}

void HmacCore::engineUpdate($ByteBuffer* input) {
	if (this->first == true) {
		$nc(this->md)->update(this->k_ipad);
		this->first = false;
	}
	$nc(this->md)->update(input);
}

$bytes* HmacCore::engineDoFinal() {
	if (this->first == true) {
		$nc(this->md)->update(this->k_ipad);
	} else {
		this->first = true;
	}
	try {
		$var($bytes, tmp, $nc(this->md)->digest());
		$nc(this->md)->update(this->k_opad);
		$nc(this->md)->update(tmp);
		$nc(this->md)->digest(tmp, 0, $nc(tmp)->length);
		return tmp;
	} catch ($DigestException& e) {
		$throwNew($ProviderException, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

void HmacCore::engineReset() {
	if (this->first == false) {
		$nc(this->md)->reset();
		this->first = true;
	}
}

$Object* HmacCore::clone() {
	$var(HmacCore, copy, $cast(HmacCore, $MacSpi::clone()));
	$set($nc(copy), md, $cast($MessageDigest, $nc(this->md)->clone()));
	$set(copy, k_ipad, $cast($bytes, $nc(this->k_ipad)->clone()));
	$set(copy, k_opad, $cast($bytes, $nc(this->k_opad)->clone()));
	return $of(copy);
}

HmacCore::HmacCore() {
}

$Class* HmacCore::load$($String* name, bool initialize) {
	$loadClass(HmacCore, name, initialize, &_HmacCore_ClassInfo_, allocate$HmacCore);
	return class$;
}

$Class* HmacCore::class$ = nullptr;

			} // provider
		} // crypto
	} // sun
} // com