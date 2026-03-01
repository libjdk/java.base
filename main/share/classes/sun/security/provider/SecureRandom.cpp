#include <sun/security/provider/SecureRandom.h>

#include <java/io/ObjectInputStream.h>
#include <java/lang/InternalError.h>
#include <java/security/MessageDigest.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/NoSuchProviderException.h>
#include <java/security/SecureRandomSpi.h>
#include <sun/security/provider/SecureRandom$SeederHolder.h>
#include <sun/security/provider/SeedGenerator.h>
#include <jcpp.h>

#undef DIGEST_SIZE

using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $MessageDigest = ::java::security::MessageDigest;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $NoSuchProviderException = ::java::security::NoSuchProviderException;
using $SecureRandomSpi = ::java::security::SecureRandomSpi;
using $SecureRandom$SeederHolder = ::sun::security::provider::SecureRandom$SeederHolder;
using $SeedGenerator = ::sun::security::provider::SeedGenerator;

namespace sun {
	namespace security {
		namespace provider {

$FieldInfo _SecureRandom_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SecureRandom, serialVersionUID)},
	{"DIGEST_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SecureRandom, DIGEST_SIZE)},
	{"digest", "Ljava/security/MessageDigest;", nullptr, $PRIVATE | $TRANSIENT, $field(SecureRandom, digest)},
	{"state", "[B", nullptr, $PRIVATE, $field(SecureRandom, state)},
	{"remainder", "[B", nullptr, $PRIVATE, $field(SecureRandom, remainder)},
	{"remCount", "I", nullptr, $PRIVATE, $field(SecureRandom, remCount)},
	{}
};

$MethodInfo _SecureRandom_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(SecureRandom, init$, void)},
	{"<init>", "([B)V", nullptr, $PRIVATE, $method(SecureRandom, init$, void, $bytes*)},
	{"engineGenerateSeed", "(I)[B", nullptr, $PUBLIC, $virtualMethod(SecureRandom, engineGenerateSeed, $bytes*, int32_t)},
	{"engineNextBytes", "([B)V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(SecureRandom, engineNextBytes, void, $bytes*)},
	{"engineSetSeed", "([B)V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(SecureRandom, engineSetSeed, void, $bytes*)},
	{"init", "([B)V", nullptr, $PRIVATE, $method(SecureRandom, init, void, $bytes*)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(SecureRandom, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"updateState", "([B[B)V", nullptr, $PRIVATE | $STATIC, $staticMethod(SecureRandom, updateState, void, $bytes*, $bytes*)},
	{}
};

$InnerClassInfo _SecureRandom_InnerClassesInfo_[] = {
	{"sun.security.provider.SecureRandom$SeederHolder", "sun.security.provider.SecureRandom", "SeederHolder", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _SecureRandom_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.provider.SecureRandom",
	"java.security.SecureRandomSpi",
	nullptr,
	_SecureRandom_FieldInfo_,
	_SecureRandom_MethodInfo_,
	nullptr,
	nullptr,
	_SecureRandom_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.provider.SecureRandom$SeederHolder"
};

$Object* allocate$SecureRandom($Class* clazz) {
	return $of($alloc(SecureRandom));
}

void SecureRandom::init$() {
	$SecureRandomSpi::init$();
	init(nullptr);
}

void SecureRandom::init$($bytes* seed) {
	$SecureRandomSpi::init$();
	init(seed);
}

void SecureRandom::init($bytes* seed) {
	try {
		$set(this, digest, $MessageDigest::getInstance("SHA"_s, "SUN"_s));
	} catch ($NoSuchProviderException& e) {
		try {
			$set(this, digest, $MessageDigest::getInstance("SHA"_s));
		} catch ($NoSuchAlgorithmException& exc) {
			$throwNew($InternalError, "internal error: SHA-1 not available."_s, exc);
		}
	} catch ($NoSuchAlgorithmException& e) {
		try {
			$set(this, digest, $MessageDigest::getInstance("SHA"_s));
		} catch ($NoSuchAlgorithmException& exc) {
			$throwNew($InternalError, "internal error: SHA-1 not available."_s, exc);
		}
	}
	if (seed != nullptr) {
		engineSetSeed(seed);
	}
}

$bytes* SecureRandom::engineGenerateSeed(int32_t numBytes) {
	$var($bytes, b, $new($bytes, numBytes));
	$SeedGenerator::generateSeed(b);
	return b;
}

void SecureRandom::engineSetSeed($bytes* seed) {
	$synchronized(this) {
		if (this->state != nullptr) {
			$nc(this->digest)->update(this->state);
			for (int32_t i = 0; i < $nc(this->state)->length; ++i) {
				$nc(this->state)->set(i, (int8_t)0);
			}
		}
		$set(this, state, $nc(this->digest)->digest(seed));
		this->remCount = 0;
	}
}

void SecureRandom::updateState($bytes* state, $bytes* output) {
	$init(SecureRandom);
	int32_t last = 1;
	int32_t v = 0;
	int8_t t = 0;
	bool zf = false;
	for (int32_t i = 0; i < $nc(state)->length; ++i) {
		v = (int32_t)state->get(i) + (int32_t)$nc(output)->get(i) + last;
		t = (int8_t)v;
		zf = zf | (state->get(i) != t);
		state->set(i, t);
		last = v >> 8;
	}
	if (!zf) {
		++(*$nc(state))[0];
	}
}

void SecureRandom::engineNextBytes($bytes* result) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		int32_t index = 0;
		int32_t todo = 0;
		$var($bytes, output, this->remainder);
		if (this->state == nullptr) {
			$var($bytes, seed, $new($bytes, SecureRandom::DIGEST_SIZE));
			$init($SecureRandom$SeederHolder);
			$nc($SecureRandom$SeederHolder::seeder)->engineNextBytes(seed);
			$set(this, state, $nc(this->digest)->digest(seed));
		}
		int32_t r = this->remCount;
		if (r > 0) {
			todo = ($nc(result)->length - index) < (SecureRandom::DIGEST_SIZE - r) ? ($nc(result)->length - index) : (SecureRandom::DIGEST_SIZE - r);
			for (int32_t i = 0; i < todo; ++i) {
				result->set(i, $nc(output)->get(r));
				output->set(r++, (int8_t)0);
			}
			this->remCount += todo;
			index += todo;
		}
		while (index < $nc(result)->length) {
			$nc(this->digest)->update(this->state);
			$assign(output, $nc(this->digest)->digest());
			updateState(this->state, output);
			todo = (result->length - index) > SecureRandom::DIGEST_SIZE ? SecureRandom::DIGEST_SIZE : result->length - index;
			for (int32_t i = 0; i < todo; ++i) {
				result->set(index++, $nc(output)->get(i));
				output->set(i, (int8_t)0);
			}
			this->remCount += todo;
		}
		$set(this, remainder, output);
		$modAssign(this->remCount, SecureRandom::DIGEST_SIZE);
	}
}

void SecureRandom::readObject($ObjectInputStream* s) {
	$nc(s)->defaultReadObject();
	try {
		$set(this, digest, $MessageDigest::getInstance("SHA"_s, "SUN"_s));
	} catch ($NoSuchProviderException& e) {
		try {
			$set(this, digest, $MessageDigest::getInstance("SHA"_s));
		} catch ($NoSuchAlgorithmException& exc) {
			$throwNew($InternalError, "internal error: SHA-1 not available."_s, exc);
		}
	} catch ($NoSuchAlgorithmException& e) {
		try {
			$set(this, digest, $MessageDigest::getInstance("SHA"_s));
		} catch ($NoSuchAlgorithmException& exc) {
			$throwNew($InternalError, "internal error: SHA-1 not available."_s, exc);
		}
	}
}

SecureRandom::SecureRandom() {
}

$Class* SecureRandom::load$($String* name, bool initialize) {
	$loadClass(SecureRandom, name, initialize, &_SecureRandom_ClassInfo_, allocate$SecureRandom);
	return class$;
}

$Class* SecureRandom::class$ = nullptr;

		} // provider
	} // security
} // sun