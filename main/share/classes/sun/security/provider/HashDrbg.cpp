#include <sun/security/provider/HashDrbg.h>

#include <java/lang/AssertionError.h>
#include <java/lang/InternalError.h>
#include <java/math/BigInteger.h>
#include <java/security/DigestException.h>
#include <java/security/MessageDigest.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/NoSuchProviderException.h>
#include <java/security/SecureRandomParameters.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/HexFormat.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <sun/security/provider/AbstractDrbg.h>
#include <sun/security/provider/AbstractHashDrbg.h>
#include <sun/security/util/Debug.h>
#include <jcpp.h>

#undef ONE
#undef ZERO

using $byteArray2 = $Array<int8_t, 2>;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $BigInteger = ::java::math::BigInteger;
using $DigestException = ::java::security::DigestException;
using $MessageDigest = ::java::security::MessageDigest;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $NoSuchProviderException = ::java::security::NoSuchProviderException;
using $SecureRandomParameters = ::java::security::SecureRandomParameters;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $HexFormat = ::java::util::HexFormat;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $AbstractDrbg = ::sun::security::provider::AbstractDrbg;
using $AbstractHashDrbg = ::sun::security::provider::AbstractHashDrbg;
using $Debug = ::sun::security::util::Debug;

namespace sun {
	namespace security {
		namespace provider {

$FieldInfo _HashDrbg_FieldInfo_[] = {
	{"ZERO", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HashDrbg, ZERO)},
	{"ONE", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HashDrbg, ONE)},
	{"digest", "Ljava/security/MessageDigest;", nullptr, $PRIVATE, $field(HashDrbg, digest)},
	{"v", "[B", nullptr, $PRIVATE, $field(HashDrbg, v)},
	{"c", "[B", nullptr, $PRIVATE, $field(HashDrbg, c)},
	{}
};

$MethodInfo _HashDrbg_MethodInfo_[] = {
	{"<init>", "(Ljava/security/SecureRandomParameters;)V", nullptr, $PUBLIC, $method(HashDrbg, init$, void, $SecureRandomParameters*)},
	{"addBytes", "([BI[[B)V", nullptr, $PRIVATE | $STATIC | $TRANSIENT, $staticMethod(HashDrbg, addBytes, void, $bytes*, int32_t, $byteArray2*)},
	{"generateAlgorithm", "([B[B)V", nullptr, $PUBLIC | $FINAL | $SYNCHRONIZED, $virtualMethod(HashDrbg, generateAlgorithm, void, $bytes*, $bytes*)},
	{"hashDf", "(ILjava/util/List;)[B", "(ILjava/util/List<[B>;)[B", $PRIVATE, $method(HashDrbg, hashDf, $bytes*, int32_t, $List*)},
	{"hashDf", "(Ljava/security/MessageDigest;IILjava/util/List;)[B", "(Ljava/security/MessageDigest;IILjava/util/List<[B>;)[B", $PUBLIC | $STATIC, $staticMethod(HashDrbg, hashDf, $bytes*, $MessageDigest*, int32_t, int32_t, $List*)},
	{"hashGen", "([B[B)V", nullptr, $PRIVATE, $method(HashDrbg, hashGen, void, $bytes*, $bytes*)},
	{"hashReseedInternal", "(Ljava/util/List;)V", "(Ljava/util/List<[B>;)V", $PROTECTED | $FINAL | $SYNCHRONIZED, $virtualMethod(HashDrbg, hashReseedInternal, void, $List*)},
	{"initEngine", "()V", nullptr, $PROTECTED, $virtualMethod(HashDrbg, initEngine, void)},
	{"status", "()V", nullptr, $PRIVATE, $method(HashDrbg, status, void)},
	{}
};

$ClassInfo _HashDrbg_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.provider.HashDrbg",
	"sun.security.provider.AbstractHashDrbg",
	nullptr,
	_HashDrbg_FieldInfo_,
	_HashDrbg_MethodInfo_
};

$Object* allocate$HashDrbg($Class* clazz) {
	return $of($alloc(HashDrbg));
}

$bytes* HashDrbg::ZERO = nullptr;
$bytes* HashDrbg::ONE = nullptr;

void HashDrbg::init$($SecureRandomParameters* params) {
	$AbstractHashDrbg::init$();
	$set(this, mechName, "Hash_DRBG"_s);
	configure(params);
}

void HashDrbg::initEngine() {
	$useLocalCurrentObjectStackCache();
	try {
		$set(this, digest, $MessageDigest::getInstance(this->algorithm, "SUN"_s));
	} catch ($NoSuchProviderException& e) {
		try {
			$set(this, digest, $MessageDigest::getInstance(this->algorithm));
		} catch ($NoSuchAlgorithmException& exc) {
			$throwNew($InternalError, $$str({"internal error: "_s, this->algorithm, " not available."_s}), exc);
		}
	} catch ($NoSuchAlgorithmException& e) {
		try {
			$set(this, digest, $MessageDigest::getInstance(this->algorithm));
		} catch ($NoSuchAlgorithmException& exc) {
			$throwNew($InternalError, $$str({"internal error: "_s, this->algorithm, " not available."_s}), exc);
		}
	}
}

$bytes* HashDrbg::hashDf(int32_t requested, $List* inputs) {
	return hashDf(this->digest, this->outLen, requested, inputs);
}

$bytes* HashDrbg::hashDf($MessageDigest* digest, int32_t outLen, int32_t requested, $List* inputs) {
	$init(HashDrbg);
	$useLocalCurrentObjectStackCache();
	int32_t len = $div((requested + outLen - 1), outLen);
	$var($bytes, temp, $new($bytes, len * outLen));
	int32_t counter = 1;
	for (int32_t i = 0; i < len; ++i) {
		$nc(digest)->update((int8_t)counter);
		digest->update((int8_t)(requested >> 21));
		digest->update((int8_t)(requested >> 13));
		digest->update((int8_t)(requested >> 5));
		digest->update((int8_t)(requested << 3));
		{
			$var($Iterator, i$, $nc(inputs)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($bytes, input, $cast($bytes, i$->next()));
				{
					digest->update(input);
				}
			}
		}
		try {
			digest->digest(temp, i * outLen, outLen);
		} catch ($DigestException& e) {
			$throwNew($AssertionError, "will not happen"_s, e);
		}
		++counter;
	}
	return temp->length == requested ? temp : $Arrays::copyOf(temp, requested);
}

void HashDrbg::hashReseedInternal($List* inputs$renamed) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$var($List, inputs, inputs$renamed);
		$var($bytes, seed, nullptr);
		if (this->v != nullptr) {
			$nc(inputs)->add(0, HashDrbg::ONE);
			inputs->add(1, this->v);
			$assign(seed, hashDf(this->seedLen, inputs));
		} else {
			$assign(seed, hashDf(this->seedLen, inputs));
		}
		$set(this, v, seed);
		$assign(inputs, $new($ArrayList, 2));
		inputs->add(HashDrbg::ZERO);
		inputs->add(this->v);
		$set(this, c, hashDf(this->seedLen, inputs));
		this->reseedCounter = 1;
	}
}

void HashDrbg::status() {
	$useLocalCurrentObjectStackCache();
	$init($AbstractDrbg);
	if ($AbstractDrbg::debug != nullptr) {
		$nc($AbstractDrbg::debug)->println($of(this), $$str({"V = "_s, $($nc($($HexFormat::of()))->formatHex(this->v))}));
		$nc($AbstractDrbg::debug)->println($of(this), $$str({"C = "_s, $($nc($($HexFormat::of()))->formatHex(this->c))}));
		$nc($AbstractDrbg::debug)->println($of(this), $$str({"reseed counter = "_s, $$str(this->reseedCounter)}));
	}
}

void HashDrbg::addBytes($bytes* out, int32_t len, $byteArray2* data) {
	$init(HashDrbg);
	$useLocalCurrentObjectStackCache();
	{
		$var($byteArray2, arr$, data);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($bytes, d, arr$->get(i$));
			{
				int32_t dlen = $nc(d)->length;
				int32_t carry = 0;
				for (int32_t i = 0; i < len; ++i) {
					int32_t sum = ((int32_t)($nc(out)->get(len - i - 1) & (uint32_t)255)) + carry;
					if (i < dlen) {
						sum += ((int32_t)(d->get(dlen - i - 1) & (uint32_t)255));
					}
					out->set(len - i - 1, (int8_t)sum);
					carry = sum >> 8;
					if (i >= dlen - 1 && carry == 0) {
						break;
					}
				}
			}
		}
	}
}

void HashDrbg::generateAlgorithm($bytes* result, $bytes* additionalInput) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$init($AbstractDrbg);
		if ($AbstractDrbg::debug != nullptr) {
			$nc($AbstractDrbg::debug)->println($of(this), "generateAlgorithm"_s);
		}
		if (additionalInput != nullptr) {
			$nc(this->digest)->update((int8_t)2);
			$nc(this->digest)->update(this->v);
			$nc(this->digest)->update(additionalInput);
			addBytes(this->v, this->seedLen, $$new($byteArray2, {$($nc(this->digest)->digest())}));
		}
		hashGen(result, this->v);
		$nc(this->digest)->update((int8_t)3);
		$nc(this->digest)->update(this->v);
		$var($bytes, h, $nc(this->digest)->digest());
		$var($bytes, rcBytes, nullptr);
		if (this->reseedCounter < 256) {
			$assign(rcBytes, $new($bytes, {(int8_t)this->reseedCounter}));
		} else {
			$assign(rcBytes, $nc($($BigInteger::valueOf((int64_t)this->reseedCounter)))->toByteArray());
		}
		addBytes(this->v, this->seedLen, $$new($byteArray2, {
			h,
			this->c,
			rcBytes
		}));
		++this->reseedCounter;
	}
}

void HashDrbg::hashGen($bytes* output, $bytes* v) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, data, v);
	int32_t pos = 0;
	int32_t len = $nc(output)->length;
	while (len > 0) {
		$nc(this->digest)->update(data);
		if (len < this->outLen) {
			$var($bytes, out, $nc(this->digest)->digest());
			$System::arraycopy(out, 0, output, pos, len);
			$Arrays::fill(out, (int8_t)0);
		} else {
			try {
				$nc(this->digest)->digest(output, pos, this->outLen);
			} catch ($DigestException& e) {
				$throwNew($AssertionError, "will not happen"_s, e);
			}
		}
		len -= this->outLen;
		if (len <= 0) {
			break;
		}
		if (data == v) {
			$assign(data, $Arrays::copyOf(v, $nc(v)->length));
		}
		addBytes(data, this->seedLen, $$new($byteArray2, {HashDrbg::ONE}));
		pos += this->outLen;
	}
}

void clinit$HashDrbg($Class* class$) {
	$assignStatic(HashDrbg::ZERO, $new($bytes, 1));
	$assignStatic(HashDrbg::ONE, $new($bytes, {(int8_t)1}));
}

HashDrbg::HashDrbg() {
}

$Class* HashDrbg::load$($String* name, bool initialize) {
	$loadClass(HashDrbg, name, initialize, &_HashDrbg_ClassInfo_, clinit$HashDrbg, allocate$HashDrbg);
	return class$;
}

$Class* HashDrbg::class$ = nullptr;

		} // provider
	} // security
} // sun