#include <javax/crypto/KeyAgreement.h>

#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/Key.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/Provider$Service.h>
#include <java/security/Provider.h>
#include <java/security/ProviderException.h>
#include <java/security/SecureRandom.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <javax/crypto/JceSecurity.h>
#include <javax/crypto/KeyAgreementSpi.h>
#include <javax/crypto/SecretKey.h>
#include <sun/security/jca/GetInstance$Instance.h>
#include <sun/security/jca/GetInstance.h>
#include <sun/security/jca/JCAUtil.h>
#include <sun/security/util/Debug.h>
#include <jcpp.h>

#undef I_NO_PARAMS
#undef I_PARAMS

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $Key = ::java::security::Key;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $Provider = ::java::security::Provider;
using $Provider$Service = ::java::security::Provider$Service;
using $ProviderException = ::java::security::ProviderException;
using $SecureRandom = ::java::security::SecureRandom;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $JceSecurity = ::javax::crypto::JceSecurity;
using $KeyAgreementSpi = ::javax::crypto::KeyAgreementSpi;
using $SecretKey = ::javax::crypto::SecretKey;
using $GetInstance = ::sun::security::jca::GetInstance;
using $GetInstance$Instance = ::sun::security::jca::GetInstance$Instance;
using $JCAUtil = ::sun::security::jca::JCAUtil;
using $Debug = ::sun::security::util::Debug;

namespace javax {
	namespace crypto {

$FieldInfo _KeyAgreement_FieldInfo_[] = {
	{"debug", "Lsun/security/util/Debug;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(KeyAgreement, debug)},
	{"pdebug", "Lsun/security/util/Debug;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(KeyAgreement, pdebug)},
	{"skipDebug", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(KeyAgreement, skipDebug)},
	{"provider", "Ljava/security/Provider;", nullptr, $PRIVATE, $field(KeyAgreement, provider)},
	{"spi", "Ljavax/crypto/KeyAgreementSpi;", nullptr, $PRIVATE, $field(KeyAgreement, spi)},
	{"algorithm", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(KeyAgreement, algorithm)},
	{"firstService", "Ljava/security/Provider$Service;", nullptr, $PRIVATE, $field(KeyAgreement, firstService)},
	{"serviceIterator", "Ljava/util/Iterator;", "Ljava/util/Iterator<Ljava/security/Provider$Service;>;", $PRIVATE, $field(KeyAgreement, serviceIterator)},
	{"lock", "Ljava/lang/Object;", nullptr, $PRIVATE | $FINAL, $field(KeyAgreement, lock)},
	{"warnCount", "I", nullptr, $PRIVATE | $STATIC, $staticField(KeyAgreement, warnCount)},
	{"I_NO_PARAMS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(KeyAgreement, I_NO_PARAMS)},
	{"I_PARAMS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(KeyAgreement, I_PARAMS)},
	{}
};

$MethodInfo _KeyAgreement_MethodInfo_[] = {
	{"<init>", "(Ljavax/crypto/KeyAgreementSpi;Ljava/security/Provider;Ljava/lang/String;)V", nullptr, $PROTECTED, $method(KeyAgreement, init$, void, $KeyAgreementSpi*, $Provider*, $String*)},
	{"<init>", "(Ljava/security/Provider$Service;Ljava/util/Iterator;Ljava/lang/String;)V", "(Ljava/security/Provider$Service;Ljava/util/Iterator<Ljava/security/Provider$Service;>;Ljava/lang/String;)V", $PRIVATE, $method(KeyAgreement, init$, void, $Provider$Service*, $Iterator*, $String*)},
	{"chooseFirstProvider", "()V", nullptr, 0, $virtualMethod(KeyAgreement, chooseFirstProvider, void)},
	{"chooseProvider", "(ILjava/security/Key;Ljava/security/spec/AlgorithmParameterSpec;Ljava/security/SecureRandom;)V", nullptr, $PRIVATE, $method(KeyAgreement, chooseProvider, void, int32_t, $Key*, $AlgorithmParameterSpec*, $SecureRandom*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"doPhase", "(Ljava/security/Key;Z)Ljava/security/Key;", nullptr, $PUBLIC | $FINAL, $method(KeyAgreement, doPhase, $Key*, $Key*, bool), "java.security.InvalidKeyException,java.lang.IllegalStateException"},
	{"generateSecret", "()[B", nullptr, $PUBLIC | $FINAL, $method(KeyAgreement, generateSecret, $bytes*), "java.lang.IllegalStateException"},
	{"generateSecret", "([BI)I", nullptr, $PUBLIC | $FINAL, $method(KeyAgreement, generateSecret, int32_t, $bytes*, int32_t), "java.lang.IllegalStateException,javax.crypto.ShortBufferException"},
	{"generateSecret", "(Ljava/lang/String;)Ljavax/crypto/SecretKey;", nullptr, $PUBLIC | $FINAL, $method(KeyAgreement, generateSecret, $SecretKey*, $String*), "java.lang.IllegalStateException,java.security.NoSuchAlgorithmException,java.security.InvalidKeyException"},
	{"getAlgorithm", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL, $method(KeyAgreement, getAlgorithm, $String*)},
	{"getInstance", "(Ljava/lang/String;)Ljavax/crypto/KeyAgreement;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticMethod(KeyAgreement, getInstance, KeyAgreement*, $String*), "java.security.NoSuchAlgorithmException"},
	{"getInstance", "(Ljava/lang/String;Ljava/lang/String;)Ljavax/crypto/KeyAgreement;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticMethod(KeyAgreement, getInstance, KeyAgreement*, $String*, $String*), "java.security.NoSuchAlgorithmException,java.security.NoSuchProviderException"},
	{"getInstance", "(Ljava/lang/String;Ljava/security/Provider;)Ljavax/crypto/KeyAgreement;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticMethod(KeyAgreement, getInstance, KeyAgreement*, $String*, $Provider*), "java.security.NoSuchAlgorithmException"},
	{"getProvider", "()Ljava/security/Provider;", nullptr, $PUBLIC | $FINAL, $method(KeyAgreement, getProvider, $Provider*)},
	{"getProviderName", "()Ljava/lang/String;", nullptr, $PRIVATE, $method(KeyAgreement, getProviderName, $String*)},
	{"implInit", "(Ljavax/crypto/KeyAgreementSpi;ILjava/security/Key;Ljava/security/spec/AlgorithmParameterSpec;Ljava/security/SecureRandom;)V", nullptr, $PRIVATE, $method(KeyAgreement, implInit, void, $KeyAgreementSpi*, int32_t, $Key*, $AlgorithmParameterSpec*, $SecureRandom*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"init", "(Ljava/security/Key;)V", nullptr, $PUBLIC | $FINAL, $method(KeyAgreement, init, void, $Key*), "java.security.InvalidKeyException"},
	{"init", "(Ljava/security/Key;Ljava/security/SecureRandom;)V", nullptr, $PUBLIC | $FINAL, $method(KeyAgreement, init, void, $Key*, $SecureRandom*), "java.security.InvalidKeyException"},
	{"init", "(Ljava/security/Key;Ljava/security/spec/AlgorithmParameterSpec;)V", nullptr, $PUBLIC | $FINAL, $method(KeyAgreement, init, void, $Key*, $AlgorithmParameterSpec*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"init", "(Ljava/security/Key;Ljava/security/spec/AlgorithmParameterSpec;Ljava/security/SecureRandom;)V", nullptr, $PUBLIC | $FINAL, $method(KeyAgreement, init, void, $Key*, $AlgorithmParameterSpec*, $SecureRandom*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{}
};

$ClassInfo _KeyAgreement_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"javax.crypto.KeyAgreement",
	"java.lang.Object",
	nullptr,
	_KeyAgreement_FieldInfo_,
	_KeyAgreement_MethodInfo_
};

$Object* allocate$KeyAgreement($Class* clazz) {
	return $of($alloc(KeyAgreement));
}

$Debug* KeyAgreement::debug = nullptr;
$Debug* KeyAgreement::pdebug = nullptr;
bool KeyAgreement::skipDebug = false;
int32_t KeyAgreement::warnCount = 0;

void KeyAgreement::init$($KeyAgreementSpi* keyAgreeSpi, $Provider* provider, $String* algorithm) {
	$set(this, spi, keyAgreeSpi);
	$set(this, provider, provider);
	$set(this, algorithm, algorithm);
	$set(this, lock, nullptr);
}

void KeyAgreement::init$($Provider$Service* s, $Iterator* t, $String* algorithm) {
	$set(this, firstService, s);
	$set(this, serviceIterator, t);
	$set(this, algorithm, algorithm);
	$set(this, lock, $new($Object));
}

$String* KeyAgreement::getAlgorithm() {
	return this->algorithm;
}

KeyAgreement* KeyAgreement::getInstance($String* algorithm) {
	$init(KeyAgreement);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(algorithm), "null algorithm name"_s);
	$var($List, services, $GetInstance::getServices("KeyAgreement"_s, algorithm));
	$var($Iterator, t, $nc(services)->iterator());
	while ($nc(t)->hasNext()) {
		$var($Provider$Service, s, $cast($Provider$Service, t->next()));
		if ($JceSecurity::canUseProvider($($nc(s)->getProvider())) == false) {
			continue;
		}
		return $new(KeyAgreement, s, t, algorithm);
	}
	$throwNew($NoSuchAlgorithmException, $$str({"Algorithm "_s, algorithm, " not available"_s}));
}

KeyAgreement* KeyAgreement::getInstance($String* algorithm, $String* provider) {
	$init(KeyAgreement);
	$Objects::requireNonNull($of(algorithm), "null algorithm name"_s);
	$load($KeyAgreementSpi);
	$var($GetInstance$Instance, instance, $JceSecurity::getInstance("KeyAgreement"_s, $KeyAgreementSpi::class$, algorithm, provider));
	return $new(KeyAgreement, $cast($KeyAgreementSpi, $nc(instance)->impl), instance->provider, algorithm);
}

KeyAgreement* KeyAgreement::getInstance($String* algorithm, $Provider* provider) {
	$init(KeyAgreement);
	$Objects::requireNonNull($of(algorithm), "null algorithm name"_s);
	$load($KeyAgreementSpi);
	$var($GetInstance$Instance, instance, $JceSecurity::getInstance("KeyAgreement"_s, $KeyAgreementSpi::class$, algorithm, provider));
	return $new(KeyAgreement, $cast($KeyAgreementSpi, $nc(instance)->impl), instance->provider, algorithm);
}

void KeyAgreement::chooseFirstProvider() {
	$useLocalCurrentObjectStackCache();
	if (this->spi != nullptr) {
		return;
	}
	$synchronized(this->lock) {
		if (this->spi != nullptr) {
			return;
		}
		if (KeyAgreement::debug != nullptr) {
			int32_t w = --KeyAgreement::warnCount;
			if (w >= 0) {
				$nc(KeyAgreement::debug)->println("KeyAgreement.init() not first method called, disabling delayed provider selection"_s);
				if (w == 0) {
					$nc(KeyAgreement::debug)->println("Further warnings of this type will be suppressed"_s);
				}
				$$new($Exception, "Call trace"_s)->printStackTrace();
			}
		}
		$var($Exception, lastException, nullptr);
		while ((this->firstService != nullptr) || $nc(this->serviceIterator)->hasNext()) {
			$var($Provider$Service, s, nullptr);
			if (this->firstService != nullptr) {
				$assign(s, this->firstService);
				$set(this, firstService, nullptr);
			} else {
				$assign(s, $cast($Provider$Service, $nc(this->serviceIterator)->next()));
			}
			if ($JceSecurity::canUseProvider($($nc(s)->getProvider())) == false) {
				continue;
			}
			try {
				$var($Object, obj, $nc(s)->newInstance(nullptr));
				if ($instanceOf($KeyAgreementSpi, obj) == false) {
					continue;
				}
				$set(this, spi, $cast($KeyAgreementSpi, obj));
				$set(this, provider, s->getProvider());
				$set(this, firstService, nullptr);
				$set(this, serviceIterator, nullptr);
				return;
			} catch ($Exception& e) {
				$assign(lastException, e);
			}
		}
		$var($ProviderException, e, $new($ProviderException, "Could not construct KeyAgreementSpi instance"_s));
		if (lastException != nullptr) {
			e->initCause(lastException);
		}
		$throw(e);
	}
}

void KeyAgreement::implInit($KeyAgreementSpi* spi, int32_t type, $Key* key, $AlgorithmParameterSpec* params, $SecureRandom* random) {
	if (type == KeyAgreement::I_NO_PARAMS) {
		$nc(spi)->engineInit(key, random);
	} else {
		$nc(spi)->engineInit(key, params, random);
	}
}

void KeyAgreement::chooseProvider(int32_t initType, $Key* key, $AlgorithmParameterSpec* params, $SecureRandom* random) {
	$useLocalCurrentObjectStackCache();
	$synchronized(this->lock) {
		if (this->spi != nullptr) {
			implInit(this->spi, initType, key, params, random);
			return;
		}
		$var($Exception, lastException, nullptr);
		while ((this->firstService != nullptr) || $nc(this->serviceIterator)->hasNext()) {
			$var($Provider$Service, s, nullptr);
			if (this->firstService != nullptr) {
				$assign(s, this->firstService);
				$set(this, firstService, nullptr);
			} else {
				$assign(s, $cast($Provider$Service, $nc(this->serviceIterator)->next()));
			}
			if ($nc(s)->supportsParameter(key) == false) {
				continue;
			}
			if ($JceSecurity::canUseProvider($($nc(s)->getProvider())) == false) {
				continue;
			}
			try {
				$var($KeyAgreementSpi, spi, $cast($KeyAgreementSpi, $nc(s)->newInstance(nullptr)));
				implInit(spi, initType, key, params, random);
				$set(this, provider, s->getProvider());
				$set(this, spi, spi);
				$set(this, firstService, nullptr);
				$set(this, serviceIterator, nullptr);
				return;
			} catch ($Exception& e) {
				if (lastException == nullptr) {
					$assign(lastException, e);
				}
			}
		}
		if ($instanceOf($InvalidKeyException, lastException)) {
			$throw($cast($InvalidKeyException, lastException));
		}
		if ($instanceOf($InvalidAlgorithmParameterException, lastException)) {
			$throw($cast($InvalidAlgorithmParameterException, lastException));
		}
		if ($instanceOf($RuntimeException, lastException)) {
			$throw($cast($RuntimeException, lastException));
		}
		$var($String, kName, (key != nullptr) ? $nc($of(key))->getClass()->getName() : "(null)"_s);
		$throwNew($InvalidKeyException, $$str({"No installed provider supports this key: "_s, kName}), lastException);
	}
}

$Provider* KeyAgreement::getProvider() {
	chooseFirstProvider();
	return this->provider;
}

void KeyAgreement::init($Key* key) {
	init(key, $($JCAUtil::getDefSecureRandom()));
}

void KeyAgreement::init($Key* key, $SecureRandom* random) {
	$useLocalCurrentObjectStackCache();
	if (this->spi != nullptr) {
		$nc(this->spi)->engineInit(key, random);
	} else {
		try {
			chooseProvider(KeyAgreement::I_NO_PARAMS, key, nullptr, random);
		} catch ($InvalidAlgorithmParameterException& e) {
			$throwNew($InvalidKeyException, static_cast<$Throwable*>(e));
		}
	}
	if (!KeyAgreement::skipDebug && KeyAgreement::pdebug != nullptr) {
		$nc(KeyAgreement::pdebug)->println($$str({"KeyAgreement."_s, this->algorithm, " algorithm from: "_s, $(getProviderName())}));
	}
}

void KeyAgreement::init($Key* key, $AlgorithmParameterSpec* params) {
	init(key, params, $($JCAUtil::getDefSecureRandom()));
}

$String* KeyAgreement::getProviderName() {
	return (this->provider == nullptr) ? "(no provider)"_s : $nc(this->provider)->getName();
}

void KeyAgreement::init($Key* key, $AlgorithmParameterSpec* params, $SecureRandom* random) {
	$useLocalCurrentObjectStackCache();
	if (this->spi != nullptr) {
		$nc(this->spi)->engineInit(key, params, random);
	} else {
		chooseProvider(KeyAgreement::I_PARAMS, key, params, random);
	}
	if (!KeyAgreement::skipDebug && KeyAgreement::pdebug != nullptr) {
		$nc(KeyAgreement::pdebug)->println($$str({"KeyAgreement."_s, this->algorithm, " algorithm from: "_s, $(getProviderName())}));
	}
}

$Key* KeyAgreement::doPhase($Key* key, bool lastPhase) {
	chooseFirstProvider();
	return $nc(this->spi)->engineDoPhase(key, lastPhase);
}

$bytes* KeyAgreement::generateSecret() {
	chooseFirstProvider();
	return $nc(this->spi)->engineGenerateSecret();
}

int32_t KeyAgreement::generateSecret($bytes* sharedSecret, int32_t offset) {
	chooseFirstProvider();
	return $nc(this->spi)->engineGenerateSecret(sharedSecret, offset);
}

$SecretKey* KeyAgreement::generateSecret($String* algorithm) {
	chooseFirstProvider();
	return $nc(this->spi)->engineGenerateSecret(algorithm);
}

void clinit$KeyAgreement($Class* class$) {
	$assignStatic(KeyAgreement::debug, $Debug::getInstance("jca"_s, "KeyAgreement"_s));
	$assignStatic(KeyAgreement::pdebug, $Debug::getInstance("provider"_s, "Provider"_s));
	bool var$0 = $Debug::isOn("engine="_s);
	KeyAgreement::skipDebug = var$0 && !$Debug::isOn("keyagreement"_s);
	KeyAgreement::warnCount = 10;
}

KeyAgreement::KeyAgreement() {
}

$Class* KeyAgreement::load$($String* name, bool initialize) {
	$loadClass(KeyAgreement, name, initialize, &_KeyAgreement_ClassInfo_, clinit$KeyAgreement, allocate$KeyAgreement);
	return class$;
}

$Class* KeyAgreement::class$ = nullptr;

	} // crypto
} // javax