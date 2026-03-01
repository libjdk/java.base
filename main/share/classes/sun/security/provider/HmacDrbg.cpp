#include <sun/security/provider/HmacDrbg.h>

#include <java/lang/InternalError.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/Key.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/NoSuchProviderException.h>
#include <java/security/SecureRandomParameters.h>
#include <java/util/Arrays.h>
#include <java/util/Collections.h>
#include <java/util/HexFormat.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <javax/crypto/Mac.h>
#include <javax/crypto/spec/SecretKeySpec.h>
#include <sun/security/provider/AbstractDrbg.h>
#include <sun/security/provider/AbstractHashDrbg.h>
#include <sun/security/util/Debug.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $Key = ::java::security::Key;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $NoSuchProviderException = ::java::security::NoSuchProviderException;
using $SecureRandomParameters = ::java::security::SecureRandomParameters;
using $Arrays = ::java::util::Arrays;
using $Collections = ::java::util::Collections;
using $HexFormat = ::java::util::HexFormat;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Mac = ::javax::crypto::Mac;
using $SecretKeySpec = ::javax::crypto::spec::SecretKeySpec;
using $AbstractDrbg = ::sun::security::provider::AbstractDrbg;
using $AbstractHashDrbg = ::sun::security::provider::AbstractHashDrbg;
using $Debug = ::sun::security::util::Debug;

namespace sun {
	namespace security {
		namespace provider {

$FieldInfo _HmacDrbg_FieldInfo_[] = {
	{"mac", "Ljavax/crypto/Mac;", nullptr, $PRIVATE, $field(HmacDrbg, mac)},
	{"macAlg", "Ljava/lang/String;", nullptr, $PRIVATE, $field(HmacDrbg, macAlg)},
	{"v", "[B", nullptr, $PRIVATE, $field(HmacDrbg, v)},
	{"k", "[B", nullptr, $PRIVATE, $field(HmacDrbg, k)},
	{}
};

$MethodInfo _HmacDrbg_MethodInfo_[] = {
	{"<init>", "(Ljava/security/SecureRandomParameters;)V", nullptr, $PUBLIC, $method(HmacDrbg, init$, void, $SecureRandomParameters*)},
	{"generateAlgorithm", "([B[B)V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(HmacDrbg, generateAlgorithm, void, $bytes*, $bytes*)},
	{"hashReseedInternal", "(Ljava/util/List;)V", "(Ljava/util/List<[B>;)V", $PROTECTED | $FINAL | $SYNCHRONIZED, $virtualMethod(HmacDrbg, hashReseedInternal, void, $List*)},
	{"initEngine", "()V", nullptr, $PROTECTED, $virtualMethod(HmacDrbg, initEngine, void)},
	{"status", "()V", nullptr, $PRIVATE, $method(HmacDrbg, status, void)},
	{"update", "(Ljava/util/List;)V", "(Ljava/util/List<[B>;)V", $PRIVATE, $method(HmacDrbg, update, void, $List*)},
	{}
};

$ClassInfo _HmacDrbg_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.provider.HmacDrbg",
	"sun.security.provider.AbstractHashDrbg",
	nullptr,
	_HmacDrbg_FieldInfo_,
	_HmacDrbg_MethodInfo_
};

$Object* allocate$HmacDrbg($Class* clazz) {
	return $of($alloc(HmacDrbg));
}

void HmacDrbg::init$($SecureRandomParameters* params) {
	$AbstractHashDrbg::init$();
	$set(this, mechName, "HMAC_DRBG"_s);
	configure(params);
}

void HmacDrbg::status() {
	$useLocalCurrentObjectStackCache();
	$init($AbstractDrbg);
	if ($AbstractDrbg::debug != nullptr) {
		$nc($AbstractDrbg::debug)->println($of(this), $$str({"V = "_s, $($nc($($HexFormat::of()))->formatHex(this->v))}));
		$nc($AbstractDrbg::debug)->println($of(this), $$str({"Key = "_s, $($nc($($HexFormat::of()))->formatHex(this->k))}));
		$nc($AbstractDrbg::debug)->println($of(this), $$str({"reseed counter = "_s, $$str(this->reseedCounter)}));
	}
}

void HmacDrbg::update($List* inputs) {
	$useLocalCurrentObjectStackCache();
	try {
		$nc(this->mac)->init($$new($SecretKeySpec, this->k, this->macAlg));
		$nc(this->mac)->update(this->v);
		$nc(this->mac)->update((int8_t)0);
		{
			$var($Iterator, i$, $nc(inputs)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($bytes, input, $cast($bytes, i$->next()));
				{
					$nc(this->mac)->update(input);
				}
			}
		}
		$set(this, k, $nc(this->mac)->doFinal());
		$nc(this->mac)->init($$new($SecretKeySpec, this->k, this->macAlg));
		$set(this, v, $nc(this->mac)->doFinal(this->v));
		if (!inputs->isEmpty()) {
			$nc(this->mac)->update(this->v);
			$nc(this->mac)->update((int8_t)1);
			{
				$var($Iterator, i$, inputs->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($bytes, input, $cast($bytes, i$->next()));
					{
						$nc(this->mac)->update(input);
					}
				}
			}
			$set(this, k, $nc(this->mac)->doFinal());
			$nc(this->mac)->init($$new($SecretKeySpec, this->k, this->macAlg));
			$set(this, v, $nc(this->mac)->doFinal(this->v));
		}
	} catch ($InvalidKeyException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	}
}

void HmacDrbg::initEngine() {
	$useLocalCurrentObjectStackCache();
	$set(this, macAlg, $str({"HmacSHA"_s, $($nc(this->algorithm)->substring(4))}));
	try {
		$set(this, mac, $Mac::getInstance(this->macAlg, "SunJCE"_s));
	} catch ($NoSuchProviderException& e) {
		try {
			$set(this, mac, $Mac::getInstance(this->macAlg));
		} catch ($NoSuchAlgorithmException& exc) {
			$throwNew($InternalError, $$str({"internal error: "_s, this->macAlg, " not available."_s}), exc);
		}
	} catch ($NoSuchAlgorithmException& e) {
		try {
			$set(this, mac, $Mac::getInstance(this->macAlg));
		} catch ($NoSuchAlgorithmException& exc) {
			$throwNew($InternalError, $$str({"internal error: "_s, this->macAlg, " not available."_s}), exc);
		}
	}
}

void HmacDrbg::hashReseedInternal($List* input) {
	$synchronized(this) {
		if (this->v == nullptr) {
			$set(this, k, $new($bytes, this->outLen));
			$set(this, v, $new($bytes, this->outLen));
			$Arrays::fill(this->v, (int8_t)1);
		}
		update(input);
		this->reseedCounter = 1;
	}
}

void HmacDrbg::generateAlgorithm($bytes* result, $bytes* additionalInput) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$init($AbstractDrbg);
		if ($AbstractDrbg::debug != nullptr) {
			$nc($AbstractDrbg::debug)->println($of(this), "generateAlgorithm"_s);
		}
		if (additionalInput != nullptr) {
			update($($Collections::singletonList(additionalInput)));
		}
		int32_t pos = 0;
		int32_t len = $nc(result)->length;
		while (len > 0) {
			try {
				$nc(this->mac)->init($$new($SecretKeySpec, this->k, this->macAlg));
			} catch ($InvalidKeyException& e) {
				$throwNew($InternalError, static_cast<$Throwable*>(e));
			}
			$set(this, v, $nc(this->mac)->doFinal(this->v));
			$System::arraycopy(this->v, 0, result, pos, len > this->outLen ? this->outLen : len);
			len -= this->outLen;
			if (len <= 0) {
				break;
			}
			pos += this->outLen;
		}
		if (additionalInput != nullptr) {
			update($($Collections::singletonList(additionalInput)));
		} else {
			update($($Collections::emptyList()));
		}
		++this->reseedCounter;
	}
}

HmacDrbg::HmacDrbg() {
}

$Class* HmacDrbg::load$($String* name, bool initialize) {
	$loadClass(HmacDrbg, name, initialize, &_HmacDrbg_ClassInfo_, allocate$HmacDrbg);
	return class$;
}

$Class* HmacDrbg::class$ = nullptr;

		} // provider
	} // security
} // sun