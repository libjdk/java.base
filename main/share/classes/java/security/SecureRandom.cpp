#include <java/security/SecureRandom.h>

#include <java/lang/CharSequence.h>
#include <java/security/AccessController.h>
#include <java/security/MessageDigest.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/NoSuchProviderException.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/Provider$Service.h>
#include <java/security/Provider.h>
#include <java/security/SecureRandom$1.h>
#include <java/security/SecureRandom$StrongPatternHolder.h>
#include <java/security/SecureRandomParameters.h>
#include <java/security/SecureRandomSpi.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <java/util/Random.h>
#include <java/util/regex/Matcher.h>
#include <java/util/regex/Pattern.h>
#include <sun/security/jca/GetInstance$Instance.h>
#include <sun/security/jca/GetInstance.h>
#include <sun/security/jca/ProviderList.h>
#include <sun/security/jca/Providers.h>
#include <sun/security/provider/SecureRandom.h>
#include <sun/security/provider/SunEntries.h>
#include <sun/security/util/Debug.h>
#include <jcpp.h>

#undef DEF_SECURE_RANDOM_ALGO

using $Boolean = ::java::lang::Boolean;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NamedAttribute = ::java::lang::NamedAttribute;
using $RuntimeException = ::java::lang::RuntimeException;
using $AccessController = ::java::security::AccessController;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $NoSuchProviderException = ::java::security::NoSuchProviderException;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Provider = ::java::security::Provider;
using $Provider$Service = ::java::security::Provider$Service;
using $SecureRandom$1 = ::java::security::SecureRandom$1;
using $SecureRandom$StrongPatternHolder = ::java::security::SecureRandom$StrongPatternHolder;
using $SecureRandomParameters = ::java::security::SecureRandomParameters;
using $SecureRandomSpi = ::java::security::SecureRandomSpi;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $Random = ::java::util::Random;
using $Matcher = ::java::util::regex::Matcher;
using $Pattern = ::java::util::regex::Pattern;
using $GetInstance = ::sun::security::jca::GetInstance;
using $GetInstance$Instance = ::sun::security::jca::GetInstance$Instance;
using $ProviderList = ::sun::security::jca::ProviderList;
using $Providers = ::sun::security::jca::Providers;
using $SecureRandom = ::sun::security::provider::SecureRandom;
using $SunEntries = ::sun::security::provider::SunEntries;
using $Debug = ::sun::security::util::Debug;

namespace java {
	namespace security {

$NamedAttribute SecureRandom_Attribute_var$0[] = {
	{"name", 's', "SecureRandom"},
	{"isStochastic", 'Z', "true"},
	{}
};

$CompoundAttribute _SecureRandom_Annotations_[] = {
	{"Ljdk/internal/util/random/RandomSupport$RandomGeneratorProperties;", SecureRandom_Attribute_var$0},
	{}
};

$FieldInfo _SecureRandom_FieldInfo_[] = {
	{"pdebug", "Lsun/security/util/Debug;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SecureRandom, pdebug)},
	{"skipDebug", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SecureRandom, skipDebug)},
	{"provider", "Ljava/security/Provider;", nullptr, $PRIVATE, $field(SecureRandom, provider)},
	{"secureRandomSpi", "Ljava/security/SecureRandomSpi;", nullptr, $PRIVATE, $field(SecureRandom, secureRandomSpi)},
	{"threadSafe", "Z", nullptr, $PRIVATE | $FINAL, $field(SecureRandom, threadSafe)},
	{"algorithm", "Ljava/lang/String;", nullptr, $PRIVATE, $field(SecureRandom, algorithm)},
	{"seedGenerator", "Ljava/security/SecureRandom;", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(SecureRandom, seedGenerator)},
	{"serialVersionUID", "J", nullptr, $STATIC | $FINAL, $constField(SecureRandom, serialVersionUID)},
	{"state", "[B", nullptr, $PRIVATE, $field(SecureRandom, state)},
	{"digest", "Ljava/security/MessageDigest;", nullptr, $PRIVATE, $field(SecureRandom, digest)},
	{"randomBytes", "[B", nullptr, $PRIVATE, $field(SecureRandom, randomBytes)},
	{"randomBytesUsed", "I", nullptr, $PRIVATE, $field(SecureRandom, randomBytesUsed)},
	{"counter", "J", nullptr, $PRIVATE, $field(SecureRandom, counter)},
	{}
};

$MethodInfo _SecureRandom_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(SecureRandom, init$, void)},
	{"<init>", "([B)V", nullptr, $PUBLIC, $method(SecureRandom, init$, void, $bytes*)},
	{"<init>", "(Ljava/security/SecureRandomSpi;Ljava/security/Provider;)V", nullptr, $PROTECTED, $method(SecureRandom, init$, void, $SecureRandomSpi*, $Provider*)},
	{"<init>", "(Ljava/security/SecureRandomSpi;Ljava/security/Provider;Ljava/lang/String;)V", nullptr, $PRIVATE, $method(SecureRandom, init$, void, $SecureRandomSpi*, $Provider*, $String*)},
	{"generateSeed", "(I)[B", nullptr, $PUBLIC, $virtualMethod(SecureRandom, generateSeed, $bytes*, int32_t)},
	{"getAlgorithm", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SecureRandom, getAlgorithm, $String*)},
	{"getDefaultPRNG", "(Z[B)V", nullptr, $PRIVATE, $method(SecureRandom, getDefaultPRNG, void, bool, $bytes*)},
	{"getInstance", "(Ljava/lang/String;)Ljava/security/SecureRandom;", nullptr, $PUBLIC | $STATIC, $staticMethod(SecureRandom, getInstance, SecureRandom*, $String*), "java.security.NoSuchAlgorithmException"},
	{"getInstance", "(Ljava/lang/String;Ljava/lang/String;)Ljava/security/SecureRandom;", nullptr, $PUBLIC | $STATIC, $staticMethod(SecureRandom, getInstance, SecureRandom*, $String*, $String*), "java.security.NoSuchAlgorithmException,java.security.NoSuchProviderException"},
	{"getInstance", "(Ljava/lang/String;Ljava/security/Provider;)Ljava/security/SecureRandom;", nullptr, $PUBLIC | $STATIC, $staticMethod(SecureRandom, getInstance, SecureRandom*, $String*, $Provider*), "java.security.NoSuchAlgorithmException"},
	{"getInstance", "(Ljava/lang/String;Ljava/security/SecureRandomParameters;)Ljava/security/SecureRandom;", nullptr, $PUBLIC | $STATIC, $staticMethod(SecureRandom, getInstance, SecureRandom*, $String*, $SecureRandomParameters*), "java.security.NoSuchAlgorithmException"},
	{"getInstance", "(Ljava/lang/String;Ljava/security/SecureRandomParameters;Ljava/lang/String;)Ljava/security/SecureRandom;", nullptr, $PUBLIC | $STATIC, $staticMethod(SecureRandom, getInstance, SecureRandom*, $String*, $SecureRandomParameters*, $String*), "java.security.NoSuchAlgorithmException,java.security.NoSuchProviderException"},
	{"getInstance", "(Ljava/lang/String;Ljava/security/SecureRandomParameters;Ljava/security/Provider;)Ljava/security/SecureRandom;", nullptr, $PUBLIC | $STATIC, $staticMethod(SecureRandom, getInstance, SecureRandom*, $String*, $SecureRandomParameters*, $Provider*), "java.security.NoSuchAlgorithmException"},
	{"getInstanceStrong", "()Ljava/security/SecureRandom;", nullptr, $PUBLIC | $STATIC, $staticMethod(SecureRandom, getInstanceStrong, SecureRandom*), "java.security.NoSuchAlgorithmException"},
	{"getParameters", "()Ljava/security/SecureRandomParameters;", nullptr, $PUBLIC, $virtualMethod(SecureRandom, getParameters, $SecureRandomParameters*)},
	{"getProvider", "()Ljava/security/Provider;", nullptr, $PUBLIC | $FINAL, $method(SecureRandom, getProvider, $Provider*)},
	{"getProviderName", "()Ljava/lang/String;", nullptr, $PRIVATE, $method(SecureRandom, getProviderName, $String*)},
	{"getSeed", "(I)[B", nullptr, $PUBLIC | $STATIC, $staticMethod(SecureRandom, getSeed, $bytes*, int32_t)},
	{"getThreadSafe", "()Z", nullptr, $PRIVATE, $method(SecureRandom, getThreadSafe, bool)},
	{"longToByteArray", "(J)[B", nullptr, $PRIVATE | $STATIC, $staticMethod(SecureRandom, longToByteArray, $bytes*, int64_t)},
	{"next", "(I)I", nullptr, $PROTECTED | $FINAL, $virtualMethod(SecureRandom, next, int32_t, int32_t)},
	{"nextBytes", "([B)V", nullptr, $PUBLIC, $virtualMethod(SecureRandom, nextBytes, void, $bytes*)},
	{"nextBytes", "([BLjava/security/SecureRandomParameters;)V", nullptr, $PUBLIC, $virtualMethod(SecureRandom, nextBytes, void, $bytes*, $SecureRandomParameters*)},
	{"reseed", "()V", nullptr, $PUBLIC, $virtualMethod(SecureRandom, reseed, void)},
	{"reseed", "(Ljava/security/SecureRandomParameters;)V", nullptr, $PUBLIC, $virtualMethod(SecureRandom, reseed, void, $SecureRandomParameters*)},
	{"setSeed", "([B)V", nullptr, $PUBLIC, $virtualMethod(SecureRandom, setSeed, void, $bytes*)},
	{"setSeed", "(J)V", nullptr, $PUBLIC, $virtualMethod(SecureRandom, setSeed, void, int64_t)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SecureRandom, toString, $String*)},
	{}
};

$InnerClassInfo _SecureRandom_InnerClassesInfo_[] = {
	{"java.security.SecureRandom$StrongPatternHolder", "java.security.SecureRandom", "StrongPatternHolder", $PRIVATE | $STATIC | $FINAL},
	{"java.security.SecureRandom$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _SecureRandom_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.security.SecureRandom",
	"java.util.Random",
	nullptr,
	_SecureRandom_FieldInfo_,
	_SecureRandom_MethodInfo_,
	nullptr,
	nullptr,
	_SecureRandom_InnerClassesInfo_,
	_SecureRandom_Annotations_,
	nullptr,
	"java.security.SecureRandom$StrongPatternHolder,java.security.SecureRandom$1"
};

$Object* allocate$SecureRandom($Class* clazz) {
	return $of($alloc(SecureRandom));
}

$Debug* SecureRandom::pdebug = nullptr;
bool SecureRandom::skipDebug = false;
$volatile(SecureRandom*) SecureRandom::seedGenerator = nullptr;

void SecureRandom::init$() {
	$Random::init$(0);
	$set(this, provider, nullptr);
	$set(this, secureRandomSpi, nullptr);
	$set(this, digest, nullptr);
	getDefaultPRNG(false, nullptr);
	this->threadSafe = getThreadSafe();
}

bool SecureRandom::getThreadSafe() {
	$useLocalCurrentObjectStackCache();
	if (this->provider == nullptr || this->algorithm == nullptr) {
		return false;
	} else {
		return $Boolean::parseBoolean($($nc(this->provider)->getProperty($$str({"SecureRandom."_s, this->algorithm, " ThreadSafe"_s}), "false"_s)));
	}
}

void SecureRandom::init$($bytes* seed) {
	$Random::init$(0);
	$set(this, provider, nullptr);
	$set(this, secureRandomSpi, nullptr);
	$set(this, digest, nullptr);
	getDefaultPRNG(true, seed);
	this->threadSafe = getThreadSafe();
}

void SecureRandom::getDefaultPRNG(bool setSeed, $bytes* seed) {
	$useLocalCurrentObjectStackCache();
	$var($Provider$Service, prngService, nullptr);
	$var($String, prngAlgorithm, nullptr);
	{
		$var($Iterator, i$, $nc($($nc($($Providers::getProviderList()))->providers()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Provider, p, $cast($Provider, i$->next()));
			{
				if ($nc($($nc(p)->getName()))->equals("SUN"_s)) {
					$init($SunEntries);
					$assign(prngAlgorithm, $SunEntries::DEF_SECURE_RANDOM_ALGO);
					$assign(prngService, p->getService("SecureRandom"_s, prngAlgorithm));
					break;
				} else {
					$assign(prngService, p->getDefaultSecureRandomService());
					if (prngService != nullptr) {
						$assign(prngAlgorithm, prngService->getAlgorithm());
						break;
					}
				}
			}
		}
	}
	if (prngService == nullptr) {
		$assign(prngAlgorithm, "SHA1PRNG"_s);
		$set(this, secureRandomSpi, $new($SecureRandom));
		$set(this, provider, $Providers::getSunProvider());
	} else {
		try {
			$set(this, secureRandomSpi, $cast($SecureRandomSpi, $nc(prngService)->newInstance(nullptr)));
			$set(this, provider, prngService->getProvider());
		} catch ($NoSuchAlgorithmException& nsae) {
			$throwNew($RuntimeException, static_cast<$Throwable*>(nsae));
		}
	}
	if (setSeed) {
		$nc(this->secureRandomSpi)->engineSetSeed(seed);
	}
	if ($of(this)->getClass() == SecureRandom::class$) {
		$set(this, algorithm, prngAlgorithm);
	}
}

void SecureRandom::init$($SecureRandomSpi* secureRandomSpi, $Provider* provider) {
	SecureRandom::init$(secureRandomSpi, provider, nullptr);
}

void SecureRandom::init$($SecureRandomSpi* secureRandomSpi, $Provider* provider, $String* algorithm) {
	$useLocalCurrentObjectStackCache();
	$Random::init$(0);
	$set(this, provider, nullptr);
	$set(this, secureRandomSpi, nullptr);
	$set(this, digest, nullptr);
	$set(this, secureRandomSpi, secureRandomSpi);
	$set(this, provider, provider);
	$set(this, algorithm, algorithm);
	this->threadSafe = getThreadSafe();
	if (!SecureRandom::skipDebug && SecureRandom::pdebug != nullptr) {
		$nc(SecureRandom::pdebug)->println($$str({"SecureRandom."_s, algorithm, " algorithm from: "_s, $(getProviderName())}));
	}
}

$String* SecureRandom::getProviderName() {
	return (this->provider == nullptr) ? "(no provider)"_s : $nc(this->provider)->getName();
}

SecureRandom* SecureRandom::getInstance($String* algorithm) {
	$init(SecureRandom);
	$Objects::requireNonNull($of(algorithm), "null algorithm name"_s);
	$load($SecureRandomSpi);
	$var($GetInstance$Instance, instance, $GetInstance::getInstance("SecureRandom"_s, $SecureRandomSpi::class$, algorithm));
	return $new(SecureRandom, $cast($SecureRandomSpi, $nc(instance)->impl), instance->provider, algorithm);
}

SecureRandom* SecureRandom::getInstance($String* algorithm, $String* provider) {
	$init(SecureRandom);
	$Objects::requireNonNull($of(algorithm), "null algorithm name"_s);
	$load($SecureRandomSpi);
	$var($GetInstance$Instance, instance, $GetInstance::getInstance("SecureRandom"_s, $SecureRandomSpi::class$, algorithm, provider));
	return $new(SecureRandom, $cast($SecureRandomSpi, $nc(instance)->impl), instance->provider, algorithm);
}

SecureRandom* SecureRandom::getInstance($String* algorithm, $Provider* provider) {
	$init(SecureRandom);
	$Objects::requireNonNull($of(algorithm), "null algorithm name"_s);
	$load($SecureRandomSpi);
	$var($GetInstance$Instance, instance, $GetInstance::getInstance("SecureRandom"_s, $SecureRandomSpi::class$, algorithm, provider));
	return $new(SecureRandom, $cast($SecureRandomSpi, $nc(instance)->impl), instance->provider, algorithm);
}

SecureRandom* SecureRandom::getInstance($String* algorithm, $SecureRandomParameters* params) {
	$init(SecureRandom);
	$Objects::requireNonNull($of(algorithm), "null algorithm name"_s);
	if (params == nullptr) {
		$throwNew($IllegalArgumentException, "params cannot be null"_s);
	}
	$load($SecureRandomSpi);
	$var($GetInstance$Instance, instance, $GetInstance::getInstance("SecureRandom"_s, $SecureRandomSpi::class$, algorithm, $of(params)));
	return $new(SecureRandom, $cast($SecureRandomSpi, $nc(instance)->impl), instance->provider, algorithm);
}

SecureRandom* SecureRandom::getInstance($String* algorithm, $SecureRandomParameters* params, $String* provider) {
	$init(SecureRandom);
	$Objects::requireNonNull($of(algorithm), "null algorithm name"_s);
	if (params == nullptr) {
		$throwNew($IllegalArgumentException, "params cannot be null"_s);
	}
	$load($SecureRandomSpi);
	$var($GetInstance$Instance, instance, $GetInstance::getInstance("SecureRandom"_s, $SecureRandomSpi::class$, algorithm, $of(params), provider));
	return $new(SecureRandom, $cast($SecureRandomSpi, $nc(instance)->impl), instance->provider, algorithm);
}

SecureRandom* SecureRandom::getInstance($String* algorithm, $SecureRandomParameters* params, $Provider* provider) {
	$init(SecureRandom);
	$Objects::requireNonNull($of(algorithm), "null algorithm name"_s);
	if (params == nullptr) {
		$throwNew($IllegalArgumentException, "params cannot be null"_s);
	}
	$load($SecureRandomSpi);
	$var($GetInstance$Instance, instance, $GetInstance::getInstance("SecureRandom"_s, $SecureRandomSpi::class$, algorithm, $of(params), provider));
	return $new(SecureRandom, $cast($SecureRandomSpi, $nc(instance)->impl), instance->provider, algorithm);
}

$Provider* SecureRandom::getProvider() {
	return this->provider;
}

$String* SecureRandom::getAlgorithm() {
	return $Objects::toString(this->algorithm, "unknown"_s);
}

$String* SecureRandom::toString() {
	return $nc(this->secureRandomSpi)->toString();
}

$SecureRandomParameters* SecureRandom::getParameters() {
	return $nc(this->secureRandomSpi)->engineGetParameters();
}

void SecureRandom::setSeed($bytes* seed) {
	if (this->threadSafe) {
		$nc(this->secureRandomSpi)->engineSetSeed(seed);
	} else {
		$synchronized(this) {
			$nc(this->secureRandomSpi)->engineSetSeed(seed);
		}
	}
}

void SecureRandom::setSeed(int64_t seed) {
	if (seed != 0) {
		setSeed($(longToByteArray(seed)));
	}
}

void SecureRandom::nextBytes($bytes* bytes) {
	if (this->threadSafe) {
		$nc(this->secureRandomSpi)->engineNextBytes(bytes);
	} else {
		$synchronized(this) {
			$nc(this->secureRandomSpi)->engineNextBytes(bytes);
		}
	}
}

void SecureRandom::nextBytes($bytes* bytes, $SecureRandomParameters* params) {
	if (params == nullptr) {
		$throwNew($IllegalArgumentException, "params cannot be null"_s);
	}
	if (this->threadSafe) {
		$nc(this->secureRandomSpi)->engineNextBytes($cast($bytes, $Objects::requireNonNull(bytes)), params);
	} else {
		$synchronized(this) {
			$nc(this->secureRandomSpi)->engineNextBytes($cast($bytes, $Objects::requireNonNull(bytes)), params);
		}
	}
}

int32_t SecureRandom::next(int32_t numBits) {
	int32_t numBytes = (numBits + 7) / 8;
	$var($bytes, b, $new($bytes, numBytes));
	int32_t next = 0;
	nextBytes(b);
	for (int32_t i = 0; i < numBytes; ++i) {
		next = (next << 8) + ((int32_t)(b->get(i) & (uint32_t)255));
	}
	return $usr(next, numBytes * 8 - numBits);
}

$bytes* SecureRandom::getSeed(int32_t numBytes) {
	$init(SecureRandom);
	$var(SecureRandom, seedGen, SecureRandom::seedGenerator);
	if (seedGen == nullptr) {
		$assign(seedGen, $new(SecureRandom));
		$assignStatic(SecureRandom::seedGenerator, seedGen);
	}
	return $nc(seedGen)->generateSeed(numBytes);
}

$bytes* SecureRandom::generateSeed(int32_t numBytes) {
	if (numBytes < 0) {
		$throwNew($IllegalArgumentException, "numBytes cannot be negative"_s);
	}
	if (this->threadSafe) {
		return $nc(this->secureRandomSpi)->engineGenerateSeed(numBytes);
	} else {
		$synchronized(this) {
			return $nc(this->secureRandomSpi)->engineGenerateSeed(numBytes);
		}
	}
}

$bytes* SecureRandom::longToByteArray(int64_t l) {
	$init(SecureRandom);
	$var($bytes, retVal, $new($bytes, 8));
	for (int32_t i = 0; i < 8; ++i) {
		retVal->set(i, (int8_t)l);
		l >>= 8;
	}
	return retVal;
}

SecureRandom* SecureRandom::getInstanceStrong() {
	$init(SecureRandom);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($String, property, $cast($String, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($SecureRandom$1)))));
	if (property == nullptr || $nc(property)->isEmpty()) {
		$throwNew($NoSuchAlgorithmException, "Null/empty securerandom.strongAlgorithms Security Property"_s);
	}
	$var($String, remainder, property);
	while (remainder != nullptr) {
		$var($Matcher, m, nullptr);
		$init($SecureRandom$StrongPatternHolder);
		if ($nc(($assign(m, $nc($SecureRandom$StrongPatternHolder::pattern)->matcher(remainder))))->matches()) {
			$var($String, alg, $nc(m)->group(1));
			$var($String, prov, m->group(3));
			try {
				if (prov == nullptr) {
					return SecureRandom::getInstance(alg);
				} else {
					return SecureRandom::getInstance(alg, prov);
				}
			} catch ($NoSuchAlgorithmException& e) {
			} catch ($NoSuchProviderException& e) {
			}
			$assign(remainder, m->group(5));
		} else {
			$assign(remainder, nullptr);
		}
	}
	$throwNew($NoSuchAlgorithmException, $$str({"No strong SecureRandom impls available: "_s, property}));
	$shouldNotReachHere();
}

void SecureRandom::reseed() {
	if (this->threadSafe) {
		$nc(this->secureRandomSpi)->engineReseed(nullptr);
	} else {
		$synchronized(this) {
			$nc(this->secureRandomSpi)->engineReseed(nullptr);
		}
	}
}

void SecureRandom::reseed($SecureRandomParameters* params) {
	if (params == nullptr) {
		$throwNew($IllegalArgumentException, "params cannot be null"_s);
	}
	if (this->threadSafe) {
		$nc(this->secureRandomSpi)->engineReseed(params);
	} else {
		$synchronized(this) {
			$nc(this->secureRandomSpi)->engineReseed(params);
		}
	}
}

void clinit$SecureRandom($Class* class$) {
	$assignStatic(SecureRandom::pdebug, $Debug::getInstance("provider"_s, "Provider"_s));
	bool var$0 = $Debug::isOn("engine="_s);
	SecureRandom::skipDebug = var$0 && !$Debug::isOn("securerandom"_s);
}

SecureRandom::SecureRandom() {
}

$Class* SecureRandom::load$($String* name, bool initialize) {
	$loadClass(SecureRandom, name, initialize, &_SecureRandom_ClassInfo_, clinit$SecureRandom, allocate$SecureRandom);
	return class$;
}

$Class* SecureRandom::class$ = nullptr;

	} // security
} // java