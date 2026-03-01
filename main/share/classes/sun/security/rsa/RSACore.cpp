#include <sun/security/rsa/RSACore.h>

#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/math/BigInteger.h>
#include <java/security/interfaces/RSAKey.h>
#include <java/security/interfaces/RSAPrivateCrtKey.h>
#include <java/security/interfaces/RSAPrivateKey.h>
#include <java/security/interfaces/RSAPublicKey.h>
#include <java/util/Arrays.h>
#include <java/util/Map.h>
#include <java/util/WeakHashMap.h>
#include <java/util/concurrent/ConcurrentLinkedQueue.h>
#include <java/util/concurrent/locks/ReentrantLock.h>
#include <java/util/function/Function.h>
#include <javax/crypto/BadPaddingException.h>
#include <sun/security/rsa/RSACore$BlindingParameters.h>
#include <sun/security/rsa/RSACore$BlindingRandomPair.h>
#include <jcpp.h>

#undef ENABLE_BLINDING

using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $BigInteger = ::java::math::BigInteger;
using $RSAKey = ::java::security::interfaces::RSAKey;
using $RSAPrivateCrtKey = ::java::security::interfaces::RSAPrivateCrtKey;
using $RSAPrivateKey = ::java::security::interfaces::RSAPrivateKey;
using $RSAPublicKey = ::java::security::interfaces::RSAPublicKey;
using $Arrays = ::java::util::Arrays;
using $Map = ::java::util::Map;
using $WeakHashMap = ::java::util::WeakHashMap;
using $ConcurrentLinkedQueue = ::java::util::concurrent::ConcurrentLinkedQueue;
using $ReentrantLock = ::java::util::concurrent::locks::ReentrantLock;
using $Function = ::java::util::function::Function;
using $BadPaddingException = ::javax::crypto::BadPaddingException;
using $RSACore$BlindingParameters = ::sun::security::rsa::RSACore$BlindingParameters;
using $RSACore$BlindingRandomPair = ::sun::security::rsa::RSACore$BlindingRandomPair;

namespace sun {
	namespace security {
		namespace rsa {

class RSACore$$Lambda$lambda$getBlindingRandomPair$0 : public $Function {
	$class(RSACore$$Lambda$lambda$getBlindingRandomPair$0, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* ignored) override {
		 return $of(RSACore::lambda$getBlindingRandomPair$0($cast($BigInteger, ignored)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<RSACore$$Lambda$lambda$getBlindingRandomPair$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo RSACore$$Lambda$lambda$getBlindingRandomPair$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(RSACore$$Lambda$lambda$getBlindingRandomPair$0, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(RSACore$$Lambda$lambda$getBlindingRandomPair$0, apply, $Object*, Object$*)},
	{}
};
$ClassInfo RSACore$$Lambda$lambda$getBlindingRandomPair$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.security.rsa.RSACore$$Lambda$lambda$getBlindingRandomPair$0",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* RSACore$$Lambda$lambda$getBlindingRandomPair$0::load$($String* name, bool initialize) {
	$loadClass(RSACore$$Lambda$lambda$getBlindingRandomPair$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* RSACore$$Lambda$lambda$getBlindingRandomPair$0::class$ = nullptr;

$CompoundAttribute _RSACore_MethodAnnotations_rsa11[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _RSACore_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(RSACore, $assertionsDisabled)},
	{"ENABLE_BLINDING", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RSACore, ENABLE_BLINDING)},
	{"blindingCache", "Ljava/util/Map;", "Ljava/util/Map<Ljava/math/BigInteger;Ljava/util/concurrent/ConcurrentLinkedQueue<Lsun/security/rsa/RSACore$BlindingParameters;>;>;", $PRIVATE | $STATIC | $FINAL, $staticField(RSACore, blindingCache)},
	{"lock", "Ljava/util/concurrent/locks/ReentrantLock;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(RSACore, lock)},
	{}
};

$MethodInfo _RSACore_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(RSACore, init$, void)},
	{"convert", "([BII)[B", nullptr, $PUBLIC | $STATIC, $staticMethod(RSACore, convert, $bytes*, $bytes*, int32_t, int32_t)},
	{"crtCrypt", "([BLjava/security/interfaces/RSAPrivateCrtKey;Z)[B", nullptr, $PRIVATE | $STATIC, $staticMethod(RSACore, crtCrypt, $bytes*, $bytes*, $RSAPrivateCrtKey*, bool), "javax.crypto.BadPaddingException"},
	{"crypt", "([BLjava/math/BigInteger;Ljava/math/BigInteger;)[B", nullptr, $PRIVATE | $STATIC, $staticMethod(RSACore, crypt, $bytes*, $bytes*, $BigInteger*, $BigInteger*), "javax.crypto.BadPaddingException"},
	{"getBlindingRandomPair", "(Ljava/math/BigInteger;Ljava/math/BigInteger;Ljava/math/BigInteger;)Lsun/security/rsa/RSACore$BlindingRandomPair;", nullptr, $PRIVATE | $STATIC, $staticMethod(RSACore, getBlindingRandomPair, $RSACore$BlindingRandomPair*, $BigInteger*, $BigInteger*, $BigInteger*)},
	{"getByteLength", "(Ljava/math/BigInteger;)I", nullptr, $PUBLIC | $STATIC, $staticMethod(RSACore, getByteLength, int32_t, $BigInteger*)},
	{"getByteLength", "(Ljava/security/interfaces/RSAKey;)I", nullptr, $PUBLIC | $STATIC, $staticMethod(RSACore, getByteLength, int32_t, $RSAKey*)},
	{"lambda$getBlindingRandomPair$0", "(Ljava/math/BigInteger;)Ljava/util/concurrent/ConcurrentLinkedQueue;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(RSACore, lambda$getBlindingRandomPair$0, $ConcurrentLinkedQueue*, $BigInteger*)},
	{"parseMsg", "([BLjava/math/BigInteger;)Ljava/math/BigInteger;", nullptr, $PRIVATE | $STATIC, $staticMethod(RSACore, parseMsg, $BigInteger*, $bytes*, $BigInteger*), "javax.crypto.BadPaddingException"},
	{"priCrypt", "([BLjava/math/BigInteger;Ljava/math/BigInteger;)[B", nullptr, $PRIVATE | $STATIC, $staticMethod(RSACore, priCrypt, $bytes*, $bytes*, $BigInteger*, $BigInteger*), "javax.crypto.BadPaddingException"},
	{"rsa", "([BLjava/security/interfaces/RSAPublicKey;)[B", nullptr, $PUBLIC | $STATIC, $staticMethod(RSACore, rsa, $bytes*, $bytes*, $RSAPublicKey*), "javax.crypto.BadPaddingException"},
	{"rsa", "([BLjava/security/interfaces/RSAPrivateKey;)[B", nullptr, $PUBLIC | $STATIC | $DEPRECATED, $staticMethod(RSACore, rsa, $bytes*, $bytes*, $RSAPrivateKey*), "javax.crypto.BadPaddingException", nullptr, _RSACore_MethodAnnotations_rsa11},
	{"rsa", "([BLjava/security/interfaces/RSAPrivateKey;Z)[B", nullptr, $PUBLIC | $STATIC, $staticMethod(RSACore, rsa, $bytes*, $bytes*, $RSAPrivateKey*, bool), "javax.crypto.BadPaddingException"},
	{"toByteArray", "(Ljava/math/BigInteger;I)[B", nullptr, $PRIVATE | $STATIC, $staticMethod(RSACore, toByteArray, $bytes*, $BigInteger*, int32_t)},
	{}
};

$InnerClassInfo _RSACore_InnerClassesInfo_[] = {
	{"sun.security.rsa.RSACore$BlindingParameters", "sun.security.rsa.RSACore", "BlindingParameters", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.rsa.RSACore$BlindingRandomPair", "sun.security.rsa.RSACore", "BlindingRandomPair", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _RSACore_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.rsa.RSACore",
	"java.lang.Object",
	nullptr,
	_RSACore_FieldInfo_,
	_RSACore_MethodInfo_,
	nullptr,
	nullptr,
	_RSACore_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.rsa.RSACore$BlindingParameters,sun.security.rsa.RSACore$BlindingRandomPair"
};

$Object* allocate$RSACore($Class* clazz) {
	return $of($alloc(RSACore));
}

bool RSACore::$assertionsDisabled = false;
$Map* RSACore::blindingCache = nullptr;
$ReentrantLock* RSACore::lock = nullptr;

void RSACore::init$() {
}

int32_t RSACore::getByteLength($BigInteger* b) {
	$init(RSACore);
	int32_t n = $nc(b)->bitLength();
	return (n + 7) >> 3;
}

int32_t RSACore::getByteLength($RSAKey* key) {
	$init(RSACore);
	return getByteLength($($nc(key)->getModulus()));
}

$bytes* RSACore::convert($bytes* b, int32_t ofs, int32_t len) {
	$init(RSACore);
	if ((ofs == 0) && (len == $nc(b)->length)) {
		return b;
	} else {
		$var($bytes, t, $new($bytes, len));
		$System::arraycopy(b, ofs, t, 0, len);
		return t;
	}
}

$bytes* RSACore::rsa($bytes* msg, $RSAPublicKey* key) {
	$init(RSACore);
	$useLocalCurrentObjectStackCache();
	$var($bytes, var$0, msg);
	$var($BigInteger, var$1, $nc(key)->getModulus());
	return crypt(var$0, var$1, $(key->getPublicExponent()));
}

$bytes* RSACore::rsa($bytes* msg, $RSAPrivateKey* key) {
	$init(RSACore);
	return rsa(msg, key, true);
}

$bytes* RSACore::rsa($bytes* msg, $RSAPrivateKey* key, bool verify) {
	$init(RSACore);
	$useLocalCurrentObjectStackCache();
	if ($instanceOf($RSAPrivateCrtKey, key)) {
		return crtCrypt(msg, $cast($RSAPrivateCrtKey, key), verify);
	} else {
		$var($bytes, var$0, msg);
		$var($BigInteger, var$1, $nc(key)->getModulus());
		return priCrypt(var$0, var$1, $(key->getPrivateExponent()));
	}
}

$bytes* RSACore::crypt($bytes* msg, $BigInteger* n, $BigInteger* exp) {
	$init(RSACore);
	$useLocalCurrentObjectStackCache();
	$var($BigInteger, m, parseMsg(msg, n));
	$var($BigInteger, c, $nc(m)->modPow(exp, n));
	return toByteArray(c, getByteLength(n));
}

$bytes* RSACore::priCrypt($bytes* msg, $BigInteger* n, $BigInteger* exp) {
	$init(RSACore);
	$useLocalCurrentObjectStackCache();
	$var($BigInteger, c, parseMsg(msg, n));
	$var($RSACore$BlindingRandomPair, brp, nullptr);
	$var($BigInteger, m, nullptr);
	{
		$assign(brp, getBlindingRandomPair(nullptr, exp, n));
		$assign(c, $nc($($nc(c)->multiply($nc(brp)->u)))->mod(n));
		$assign(m, c->modPow(exp, n));
		$assign(m, $nc($($nc(m)->multiply($nc(brp)->v)))->mod(n));
	}
	return toByteArray(m, getByteLength(n));
}

$bytes* RSACore::crtCrypt($bytes* msg, $RSAPrivateCrtKey* key, bool verify) {
	$init(RSACore);
	$useLocalCurrentObjectStackCache();
	$var($BigInteger, n, $nc(key)->getModulus());
	$var($BigInteger, c0, parseMsg(msg, n));
	$var($BigInteger, c, c0);
	$var($BigInteger, p, key->getPrimeP());
	$var($BigInteger, q, key->getPrimeQ());
	$var($BigInteger, dP, key->getPrimeExponentP());
	$var($BigInteger, dQ, key->getPrimeExponentQ());
	$var($BigInteger, qInv, key->getCrtCoefficient());
	$var($BigInteger, e, key->getPublicExponent());
	$var($BigInteger, d, key->getPrivateExponent());
	$var($RSACore$BlindingRandomPair, brp, nullptr);
	{
		$assign(brp, getBlindingRandomPair(e, d, n));
		$assign(c, $nc($($nc(c)->multiply($nc(brp)->u)))->mod(n));
	}
	$var($BigInteger, m1, $nc(c)->modPow(dP, p));
	$var($BigInteger, m2, c->modPow(dQ, q));
	$var($BigInteger, mtmp, $nc(m1)->subtract(m2));
	if ($nc(mtmp)->signum() < 0) {
		$assign(mtmp, mtmp->add(p));
	}
	$var($BigInteger, h, $nc($($nc(mtmp)->multiply(qInv)))->mod(p));
	$var($BigInteger, m, $nc($($nc(h)->multiply(q)))->add(m2));
	{
		$assign(m, $nc($($nc(m)->multiply($nc(brp)->v)))->mod(n));
	}
	if (verify && !$nc(c0)->equals($($nc(m)->modPow(e, n)))) {
		$throwNew($BadPaddingException, "RSA private key operation failed"_s);
	}
	return toByteArray(m, getByteLength(n));
}

$BigInteger* RSACore::parseMsg($bytes* msg, $BigInteger* n) {
	$init(RSACore);
	$var($BigInteger, m, $new($BigInteger, 1, msg));
	if (m->compareTo(n) >= 0) {
		$throwNew($BadPaddingException, "Message is larger than modulus"_s);
	}
	return m;
}

$bytes* RSACore::toByteArray($BigInteger* bi, int32_t len) {
	$init(RSACore);
	$useLocalCurrentObjectStackCache();
	$var($bytes, b, $nc(bi)->toByteArray());
	int32_t n = $nc(b)->length;
	if (n == len) {
		return b;
	}
	if ((n == len + 1) && (b->get(0) == 0)) {
		$var($bytes, t, $new($bytes, len));
		$System::arraycopy(b, 1, t, 0, len);
		$Arrays::fill(b, (int8_t)0);
		return t;
	}
	if (!RSACore::$assertionsDisabled && !(n < len)) {
		$throwNew($AssertionError);
	}
	$var($bytes, t, $new($bytes, len));
	$System::arraycopy(b, 0, t, (len - n), n);
	$Arrays::fill(b, (int8_t)0);
	return t;
}

$RSACore$BlindingRandomPair* RSACore::getBlindingRandomPair($BigInteger* e, $BigInteger* d, $BigInteger* n) {
	$init(RSACore);
	$useLocalCurrentObjectStackCache();
	$var($ConcurrentLinkedQueue, queue, nullptr);
	$nc(RSACore::lock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$assign(queue, $cast($ConcurrentLinkedQueue, $nc(RSACore::blindingCache)->computeIfAbsent(n, static_cast<$Function*>($$new(RSACore$$Lambda$lambda$getBlindingRandomPair$0)))));
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(RSACore::lock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	$var($RSACore$BlindingParameters, bps, $cast($RSACore$BlindingParameters, $nc(queue)->poll()));
	if (bps == nullptr) {
		$assign(bps, $new($RSACore$BlindingParameters, e, d, n));
	}
	$var($RSACore$BlindingRandomPair, brp, nullptr);
	while (brp == nullptr) {
		$assign(brp, $nc(bps)->getBlindingRandomPair(e, d, n));
		if (brp == nullptr) {
			$assign(bps, $cast($RSACore$BlindingParameters, queue->poll()));
			if (bps == nullptr) {
				$assign(bps, $new($RSACore$BlindingParameters, e, d, n));
			}
		}
	}
	if ($nc(bps)->isReusable()) {
		queue->add(bps);
	}
	return brp;
}

$ConcurrentLinkedQueue* RSACore::lambda$getBlindingRandomPair$0($BigInteger* ignored) {
	$init(RSACore);
	return $new($ConcurrentLinkedQueue);
}

void clinit$RSACore($Class* class$) {
	RSACore::$assertionsDisabled = !RSACore::class$->desiredAssertionStatus();
	$assignStatic(RSACore::blindingCache, $new($WeakHashMap));
	$assignStatic(RSACore::lock, $new($ReentrantLock));
}

RSACore::RSACore() {
}

$Class* RSACore::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(RSACore$$Lambda$lambda$getBlindingRandomPair$0::classInfo$.name)) {
			return RSACore$$Lambda$lambda$getBlindingRandomPair$0::load$(name, initialize);
		}
	}
	$loadClass(RSACore, name, initialize, &_RSACore_ClassInfo_, clinit$RSACore, allocate$RSACore);
	return class$;
}

$Class* RSACore::class$ = nullptr;

		} // rsa
	} // security
} // sun