#include <sun/security/provider/DRBG.h>

#include <java/io/ObjectInputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/NumberFormatException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/security/AccessController.h>
#include <java/security/DrbgParameters$Capability.h>
#include <java/security/DrbgParameters$Instantiation.h>
#include <java/security/DrbgParameters.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/SecureRandomParameters.h>
#include <java/security/SecureRandomSpi.h>
#include <java/security/Security.h>
#include <java/util/Locale.h>
#include <sun/security/provider/AbstractDrbg.h>
#include <sun/security/provider/CtrDrbg.h>
#include <sun/security/provider/EntropySource.h>
#include <sun/security/provider/HashDrbg.h>
#include <sun/security/provider/HmacDrbg.h>
#include <sun/security/provider/MoreDrbgParameters.h>
#include <jcpp.h>

#undef DRBG
#undef NONE
#undef PROP_NAME
#undef PR_AND_RESEED
#undef RESEED_ONLY
#undef ROOT

using $ObjectInputStream = ::java::io::ObjectInputStream;
using $Serializable = ::java::io::Serializable;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $AccessController = ::java::security::AccessController;
using $DrbgParameters = ::java::security::DrbgParameters;
using $DrbgParameters$Capability = ::java::security::DrbgParameters$Capability;
using $DrbgParameters$Instantiation = ::java::security::DrbgParameters$Instantiation;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $SecureRandomParameters = ::java::security::SecureRandomParameters;
using $SecureRandomSpi = ::java::security::SecureRandomSpi;
using $Security = ::java::security::Security;
using $Locale = ::java::util::Locale;
using $AbstractDrbg = ::sun::security::provider::AbstractDrbg;
using $CtrDrbg = ::sun::security::provider::CtrDrbg;
using $EntropySource = ::sun::security::provider::EntropySource;
using $HashDrbg = ::sun::security::provider::HashDrbg;
using $HmacDrbg = ::sun::security::provider::HmacDrbg;
using $MoreDrbgParameters = ::sun::security::provider::MoreDrbgParameters;

namespace sun {
	namespace security {
		namespace provider {

class DRBG$$Lambda$lambda$new$0 : public $PrivilegedAction {
	$class(DRBG$$Lambda$lambda$new$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(DRBG::lambda$new$0());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DRBG$$Lambda$lambda$new$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo DRBG$$Lambda$lambda$new$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(DRBG$$Lambda$lambda$new$0, init$, void)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(DRBG$$Lambda$lambda$new$0, run, $Object*)},
	{}
};
$ClassInfo DRBG$$Lambda$lambda$new$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.security.provider.DRBG$$Lambda$lambda$new$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* DRBG$$Lambda$lambda$new$0::load$($String* name, bool initialize) {
	$loadClass(DRBG$$Lambda$lambda$new$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DRBG$$Lambda$lambda$new$0::class$ = nullptr;

$FieldInfo _DRBG_FieldInfo_[] = {
	{"PROP_NAME", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DRBG, PROP_NAME)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(DRBG, serialVersionUID)},
	{"impl", "Lsun/security/provider/AbstractDrbg;", nullptr, $PRIVATE | $TRANSIENT, $field(DRBG, impl)},
	{"mdp", "Lsun/security/provider/MoreDrbgParameters;", nullptr, $PRIVATE | $FINAL, $field(DRBG, mdp)},
	{}
};

$MethodInfo _DRBG_MethodInfo_[] = {
	{"<init>", "(Ljava/security/SecureRandomParameters;)V", nullptr, $PUBLIC, $method(DRBG, init$, void, $SecureRandomParameters*)},
	{"checkTwice", "(ZLjava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(DRBG, checkTwice, void, bool, $String*)},
	{"createImpl", "()V", nullptr, $PRIVATE, $method(DRBG, createImpl, void)},
	{"engineGenerateSeed", "(I)[B", nullptr, $PROTECTED, $virtualMethod(DRBG, engineGenerateSeed, $bytes*, int32_t)},
	{"engineGetParameters", "()Ljava/security/SecureRandomParameters;", nullptr, $PROTECTED, $virtualMethod(DRBG, engineGetParameters, $SecureRandomParameters*)},
	{"engineNextBytes", "([B)V", nullptr, $PROTECTED, $virtualMethod(DRBG, engineNextBytes, void, $bytes*)},
	{"engineNextBytes", "([BLjava/security/SecureRandomParameters;)V", nullptr, $PROTECTED, $virtualMethod(DRBG, engineNextBytes, void, $bytes*, $SecureRandomParameters*)},
	{"engineReseed", "(Ljava/security/SecureRandomParameters;)V", nullptr, $PROTECTED, $virtualMethod(DRBG, engineReseed, void, $SecureRandomParameters*)},
	{"engineSetSeed", "([B)V", nullptr, $PROTECTED, $virtualMethod(DRBG, engineSetSeed, void, $bytes*)},
	{"lambda$new$0", "()Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(DRBG, lambda$new$0, $String*)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(DRBG, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(DRBG, toString, $String*)},
	{}
};

$ClassInfo _DRBG_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.provider.DRBG",
	"java.security.SecureRandomSpi",
	nullptr,
	_DRBG_FieldInfo_,
	_DRBG_MethodInfo_
};

$Object* allocate$DRBG($Class* clazz) {
	return $of($alloc(DRBG));
}

$String* DRBG::PROP_NAME = nullptr;

void DRBG::init$($SecureRandomParameters* params$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($SecureRandomParameters, params, params$renamed);
	$beforeCallerSensitive();
	$SecureRandomSpi::init$();
	$var($String, mech, nullptr);
	$var($Boolean, usedf, nullptr);
	$var($String, algorithm, nullptr);
	int32_t strength = -1;
	$DrbgParameters$Capability* cap = nullptr;
	$var($bytes, ps, nullptr);
	$var($EntropySource, es, nullptr);
	$var($bytes, nonce, nullptr);
	$var($String, config, $cast($String, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(DRBG$$Lambda$lambda$new$0)))));
	if (config != nullptr && !config->isEmpty()) {
		{
			$var($StringArray, arr$, config->split(","_s));
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($String, part, arr$->get(i$));
				{
					$assign(part, $nc(part)->trim());
					{
						$init($Locale);
						$var($String, s3856$, part->toLowerCase($Locale::ROOT));
						int32_t tmp3856$ = -1;
						switch (s3856$->hashCode()) {
						case 0:
							{
								if (s3856$->equals(""_s)) {
									tmp3856$ = 0;
								}
								break;
							}
						case 0x4A3B70E9:
							{
								if (s3856$->equals("pr_and_reseed"_s)) {
									tmp3856$ = 1;
								}
								break;
							}
						case (int32_t)0xD44EA3E7:
							{
								if (s3856$->equals("reseed_only"_s)) {
									tmp3856$ = 2;
								}
								break;
							}
						case 0x0033AF38:
							{
								if (s3856$->equals("none"_s)) {
									tmp3856$ = 3;
								}
								break;
							}
						case 0x126D9DE4:
							{
								if (s3856$->equals("hash_drbg"_s)) {
									tmp3856$ = 4;
								}
								break;
							}
						case 0x304352AB:
							{
								if (s3856$->equals("hmac_drbg"_s)) {
									tmp3856$ = 5;
								}
								break;
							}
						case (int32_t)0xEC5990B1:
							{
								if (s3856$->equals("ctr_drbg"_s)) {
									tmp3856$ = 6;
								}
								break;
							}
						case 0x0641FFC0:
							{
								if (s3856$->equals("no_df"_s)) {
									tmp3856$ = 7;
								}
								break;
							}
						case (int32_t)0xCE2AEA3A:
							{
								if (s3856$->equals("use_df"_s)) {
									tmp3856$ = 8;
								}
								break;
							}
						}
						switch (tmp3856$) {
						case 0:
							{
								$throwNew($IllegalArgumentException, $$str({"aspect in "_s, DRBG::PROP_NAME, " cannot be empty"_s}));
							}
						case 1:
							{
								checkTwice(cap != nullptr, "capability"_s);
								$init($DrbgParameters$Capability);
								cap = $DrbgParameters$Capability::PR_AND_RESEED;
								break;
							}
						case 2:
							{
								checkTwice(cap != nullptr, "capability"_s);
								$init($DrbgParameters$Capability);
								cap = $DrbgParameters$Capability::RESEED_ONLY;
								break;
							}
						case 3:
							{
								checkTwice(cap != nullptr, "capability"_s);
								$init($DrbgParameters$Capability);
								cap = $DrbgParameters$Capability::NONE;
								break;
							}
						case 4:
							{}
						case 5:
							{}
						case 6:
							{
								checkTwice(mech != nullptr, "mechanism name"_s);
								$assign(mech, part);
								break;
							}
						case 7:
							{
								checkTwice(usedf != nullptr, "usedf flag"_s);
								$assign(usedf, $Boolean::valueOf(false));
								break;
							}
						case 8:
							{
								checkTwice(usedf != nullptr, "usedf flag"_s);
								$assign(usedf, $Boolean::valueOf(true));
								break;
							}
						default:
							{
								try {
									int32_t tmp = $Integer::parseInt(part);
									if (tmp < 0) {
										$throwNew($IllegalArgumentException, $$str({"strength in "_s, DRBG::PROP_NAME, " cannot be negative: "_s, part}));
									}
									checkTwice(strength >= 0, "strength"_s);
									strength = tmp;
								} catch ($NumberFormatException& e) {
									checkTwice(algorithm != nullptr, "algorithm name"_s);
									$assign(algorithm, part);
								}
							}
						}
					}
				}
			}
		}
	}
	if (params != nullptr) {
		if ($instanceOf($MoreDrbgParameters, params)) {
			$var($MoreDrbgParameters, m, $cast($MoreDrbgParameters, params));
			$assign(params, $DrbgParameters::instantiation(m->strength, m->capability, m->personalizationString));
			$assign(es, m->es);
			$assign(nonce, m->nonce);
			if (m->mech != nullptr) {
				$assign(mech, m->mech);
			}
			if (m->algorithm != nullptr) {
				$assign(algorithm, m->algorithm);
			}
			$assign(usedf, $Boolean::valueOf(m->usedf));
		}
		if ($instanceOf($DrbgParameters$Instantiation, params)) {
			$var($DrbgParameters$Instantiation, dp, $cast($DrbgParameters$Instantiation, params));
			$assign(ps, dp->getPersonalizationString());
			int32_t tmp = dp->getStrength();
			if (tmp != -1) {
				strength = tmp;
			}
			cap = dp->getCapability();
		} else {
			$throwNew($IllegalArgumentException, $$str({"Unsupported params: "_s, $of(params)->getClass()}));
		}
	}
	if (cap == nullptr) {
		$init($DrbgParameters$Capability);
		cap = $DrbgParameters$Capability::NONE;
	}
	if (mech == nullptr) {
		$assign(mech, "Hash_DRBG"_s);
	}
	if (usedf == nullptr) {
		$assign(usedf, $Boolean::valueOf(true));
	}
	$var($EntropySource, var$0, es);
	$var($String, var$1, mech);
	$var($String, var$2, algorithm);
	$var($bytes, var$3, nonce);
	bool var$4 = $nc(usedf)->booleanValue();
	$set(this, mdp, $new($MoreDrbgParameters, var$0, var$1, var$2, var$3, var$4, $($DrbgParameters::instantiation(strength, cap, ps))));
	createImpl();
}

void DRBG::createImpl() {
	$useLocalCurrentObjectStackCache();
	{
		$init($Locale);
		$var($String, s7993$, $nc($nc(this->mdp)->mech)->toLowerCase($Locale::ROOT));
		int32_t tmp7993$ = -1;
		switch (s7993$->hashCode()) {
		case 0x126D9DE4:
			{
				if (s7993$->equals("hash_drbg"_s)) {
					tmp7993$ = 0;
				}
				break;
			}
		case 0x304352AB:
			{
				if (s7993$->equals("hmac_drbg"_s)) {
					tmp7993$ = 1;
				}
				break;
			}
		case (int32_t)0xEC5990B1:
			{
				if (s7993$->equals("ctr_drbg"_s)) {
					tmp7993$ = 2;
				}
				break;
			}
		}
		switch (tmp7993$) {
		case 0:
			{
				$set(this, impl, $new($HashDrbg, this->mdp));
				break;
			}
		case 1:
			{
				$set(this, impl, $new($HmacDrbg, this->mdp));
				break;
			}
		case 2:
			{
				$set(this, impl, $new($CtrDrbg, this->mdp));
				break;
			}
		default:
			{
				$throwNew($IllegalArgumentException, $$str({"Unsupported mech: "_s, $nc(this->mdp)->mech}));
			}
		}
	}
}

void DRBG::engineSetSeed($bytes* seed) {
	$nc(this->impl)->engineSetSeed(seed);
}

void DRBG::engineNextBytes($bytes* bytes) {
	$nc(this->impl)->engineNextBytes(bytes);
}

$bytes* DRBG::engineGenerateSeed(int32_t numBytes) {
	return $nc(this->impl)->engineGenerateSeed(numBytes);
}

void DRBG::engineNextBytes($bytes* bytes, $SecureRandomParameters* params) {
	$nc(this->impl)->engineNextBytes(bytes, params);
}

void DRBG::engineReseed($SecureRandomParameters* params) {
	$nc(this->impl)->engineReseed(params);
}

$SecureRandomParameters* DRBG::engineGetParameters() {
	return $nc(this->impl)->engineGetParameters();
}

$String* DRBG::toString() {
	return $nc(this->impl)->toString();
}

void DRBG::checkTwice(bool flag, $String* name) {
	$init(DRBG);
	if (flag) {
		$throwNew($IllegalArgumentException, $$str({name, " cannot be provided more than once in "_s, DRBG::PROP_NAME}));
	}
}

void DRBG::readObject($ObjectInputStream* s) {
	$nc(s)->defaultReadObject();
	if ($nc(this->mdp)->mech == nullptr) {
		$throwNew($IllegalArgumentException, "Input data is corrupted"_s);
	}
	createImpl();
}

$String* DRBG::lambda$new$0() {
	$init(DRBG);
	return $Security::getProperty(DRBG::PROP_NAME);
}

DRBG::DRBG() {
}

void clinit$DRBG($Class* class$) {
	$assignStatic(DRBG::PROP_NAME, "securerandom.drbg.config"_s);
}

$Class* DRBG::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(DRBG$$Lambda$lambda$new$0::classInfo$.name)) {
			return DRBG$$Lambda$lambda$new$0::load$(name, initialize);
		}
	}
	$loadClass(DRBG, name, initialize, &_DRBG_ClassInfo_, clinit$DRBG, allocate$DRBG);
	return class$;
}

$Class* DRBG::class$ = nullptr;

		} // provider
	} // security
} // sun