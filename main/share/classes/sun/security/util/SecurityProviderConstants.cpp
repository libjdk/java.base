#include <sun/security/util/SecurityProviderConstants.h>

#include <java/lang/NumberFormatException.h>
#include <java/security/InvalidParameterException.h>
#include <java/security/ProviderException.h>
#include <java/util/ArrayList.h>
#include <java/util/List.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/regex/PatternSyntaxException.h>
#include <sun/security/action/GetPropertyAction.h>
#include <sun/security/util/Debug.h>
#include <sun/security/util/KnownOIDs.h>
#include <jcpp.h>

#undef ARCFOUR
#undef DEF_DH_KEY_SIZE
#undef DEF_DSA_KEY_SIZE
#undef DEF_EC_KEY_SIZE
#undef DEF_ED_KEY_SIZE
#undef DEF_RSASSA_PSS_KEY_SIZE
#undef DEF_RSA_KEY_SIZE
#undef DEF_XEC_KEY_SIZE
#undef DSA
#undef EC
#undef KEY_LENGTH_PROP
#undef OIW_DSA
#undef PKCS1
#undef RSA
#undef SHA_1

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $InvalidParameterException = ::java::security::InvalidParameterException;
using $ProviderException = ::java::security::ProviderException;
using $ArrayList = ::java::util::ArrayList;
using $List = ::java::util::List;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $PatternSyntaxException = ::java::util::regex::PatternSyntaxException;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;
using $Debug = ::sun::security::util::Debug;
using $KnownOIDs = ::sun::security::util::KnownOIDs;

namespace sun {
	namespace security {
		namespace util {

$FieldInfo _SecurityProviderConstants_FieldInfo_[] = {
	{"debug", "Lsun/security/util/Debug;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SecurityProviderConstants, debug)},
	{"aliasesMap", "Ljava/util/concurrent/ConcurrentHashMap;", "Ljava/util/concurrent/ConcurrentHashMap<Ljava/lang/String;Ljava/util/List<Ljava/lang/String;>;>;", $PRIVATE | $STATIC | $FINAL, $staticField(SecurityProviderConstants, aliasesMap)},
	{"DEF_DSA_KEY_SIZE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(SecurityProviderConstants, DEF_DSA_KEY_SIZE)},
	{"DEF_RSA_KEY_SIZE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(SecurityProviderConstants, DEF_RSA_KEY_SIZE)},
	{"DEF_RSASSA_PSS_KEY_SIZE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(SecurityProviderConstants, DEF_RSASSA_PSS_KEY_SIZE)},
	{"DEF_DH_KEY_SIZE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(SecurityProviderConstants, DEF_DH_KEY_SIZE)},
	{"DEF_EC_KEY_SIZE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(SecurityProviderConstants, DEF_EC_KEY_SIZE)},
	{"DEF_ED_KEY_SIZE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(SecurityProviderConstants, DEF_ED_KEY_SIZE)},
	{"DEF_XEC_KEY_SIZE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(SecurityProviderConstants, DEF_XEC_KEY_SIZE)},
	{"KEY_LENGTH_PROP", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SecurityProviderConstants, KEY_LENGTH_PROP)},
	{}
};

$MethodInfo _SecurityProviderConstants_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(SecurityProviderConstants, init$, void)},
	{"getAliases", "(Ljava/lang/String;)Ljava/util/List;", "(Ljava/lang/String;)Ljava/util/List<Ljava/lang/String;>;", $PUBLIC | $STATIC, $staticMethod(SecurityProviderConstants, getAliases, $List*, $String*)},
	{"getDefDSASubprimeSize", "(I)I", nullptr, $PUBLIC | $STATIC | $FINAL, $staticMethod(SecurityProviderConstants, getDefDSASubprimeSize, int32_t, int32_t)},
	{"store", "(Ljava/lang/String;Lsun/security/util/KnownOIDs;[Ljava/lang/String;)Ljava/util/List;", "(Ljava/lang/String;Lsun/security/util/KnownOIDs;[Ljava/lang/String;)Ljava/util/List<Ljava/lang/String;>;", $PRIVATE | $STATIC | $TRANSIENT, $staticMethod(SecurityProviderConstants, store, $List*, $String*, $KnownOIDs*, $StringArray*)},
	{}
};

$ClassInfo _SecurityProviderConstants_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.util.SecurityProviderConstants",
	"java.lang.Object",
	nullptr,
	_SecurityProviderConstants_FieldInfo_,
	_SecurityProviderConstants_MethodInfo_
};

$Object* allocate$SecurityProviderConstants($Class* clazz) {
	return $of($alloc(SecurityProviderConstants));
}

$Debug* SecurityProviderConstants::debug = nullptr;
$ConcurrentHashMap* SecurityProviderConstants::aliasesMap = nullptr;
int32_t SecurityProviderConstants::DEF_DSA_KEY_SIZE = 0;
int32_t SecurityProviderConstants::DEF_RSA_KEY_SIZE = 0;
int32_t SecurityProviderConstants::DEF_RSASSA_PSS_KEY_SIZE = 0;
int32_t SecurityProviderConstants::DEF_DH_KEY_SIZE = 0;
int32_t SecurityProviderConstants::DEF_EC_KEY_SIZE = 0;
int32_t SecurityProviderConstants::DEF_ED_KEY_SIZE = 0;
int32_t SecurityProviderConstants::DEF_XEC_KEY_SIZE = 0;
$String* SecurityProviderConstants::KEY_LENGTH_PROP = nullptr;

void SecurityProviderConstants::init$() {
}

$List* SecurityProviderConstants::store($String* stdName, $KnownOIDs* oid, $StringArray* extraAliases) {
	$init(SecurityProviderConstants);
	$useLocalCurrentObjectStackCache();
	$var($List, value, nullptr);
	if (oid == nullptr && $nc(extraAliases)->length != 0) {
		$assign(value, $List::of(extraAliases));
	} else {
		$assign(value, $new($ArrayList));
		if (oid != nullptr) {
			value->add($$str({"OID."_s, $(oid->value())}));
			value->add($(oid->value()));
			$var($StringArray, knownAliases, oid->aliases());
			if (knownAliases != nullptr) {
				{
					$var($StringArray, arr$, knownAliases);
					int32_t len$ = arr$->length;
					int32_t i$ = 0;
					for (; i$ < len$; ++i$) {
						$var($String, ka, arr$->get(i$));
						{
							value->add(ka);
						}
					}
				}
			}
		}
		{
			$var($StringArray, arr$, extraAliases);
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($String, ea, arr$->get(i$));
				{
					value->add(ea);
				}
			}
		}
	}
	$nc(SecurityProviderConstants::aliasesMap)->put(stdName, value);
	return value;
}

$List* SecurityProviderConstants::getAliases($String* o) {
	$init(SecurityProviderConstants);
	$useLocalCurrentObjectStackCache();
	$var($List, res, $cast($List, $nc(SecurityProviderConstants::aliasesMap)->get(o)));
	if (res == nullptr) {
		$KnownOIDs* e = $KnownOIDs::findMatch(o);
		if (e != nullptr) {
			return store(o, e, $$new($StringArray, 0));
		}
		$var($ProviderException, pe, $new($ProviderException, $$str({"Cannot find aliases for "_s, o})));
		$throw(pe);
	}
	return res;
}

int32_t SecurityProviderConstants::getDefDSASubprimeSize(int32_t primeSize) {
	$init(SecurityProviderConstants);
	$useLocalCurrentObjectStackCache();
	if (primeSize <= 1024) {
		return 160;
	} else if (primeSize == 2048) {
		return 224;
	} else if (primeSize == 3072) {
		return 256;
	} else {
		$throwNew($InvalidParameterException, $$str({"Invalid DSA Prime Size: "_s, $$str(primeSize)}));
	}
}

void clinit$SecurityProviderConstants($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(SecurityProviderConstants::KEY_LENGTH_PROP, "jdk.security.defaultKeySize"_s);
	$assignStatic(SecurityProviderConstants::debug, $Debug::getInstance("jca"_s, "ProviderConfig"_s));
	{
		$var($String, keyLengthStr, $GetPropertyAction::privilegedGetProperty(SecurityProviderConstants::KEY_LENGTH_PROP));
		int32_t dsaKeySize = 2048;
		int32_t rsaKeySize = 2048;
		int32_t rsaSsaPssKeySize = rsaKeySize;
		int32_t dhKeySize = 2048;
		int32_t ecKeySize = 256;
		int32_t edKeySize = 255;
		int32_t xecKeySize = 255;
		if (keyLengthStr != nullptr) {
			try {
				$var($StringArray, pairs, keyLengthStr->split(","_s));
				{
					$var($StringArray, arr$, pairs);
					int32_t len$ = arr$->length;
					int32_t i$ = 0;
					for (; i$ < len$; ++i$) {
						$var($String, p, arr$->get(i$));
						{
							$var($StringArray, algoAndValue, $nc(p)->split(":"_s));
							if (algoAndValue->length != 2) {
								if (SecurityProviderConstants::debug != nullptr) {
									$nc(SecurityProviderConstants::debug)->println($$str({"Ignoring invalid pair in "_s, SecurityProviderConstants::KEY_LENGTH_PROP, " property: "_s, p}));
								}
								continue;
							}
							$var($String, algoName, $($nc(algoAndValue->get(0))->trim())->toUpperCase());
							int32_t value = -1;
							try {
								value = $Integer::parseInt($($nc(algoAndValue->get(1))->trim()));
							} catch ($NumberFormatException& nfe) {
								if (SecurityProviderConstants::debug != nullptr) {
									$nc(SecurityProviderConstants::debug)->println($$str({"Ignoring invalid value in "_s, SecurityProviderConstants::KEY_LENGTH_PROP, " property: "_s, p}));
								}
								continue;
							}
							if (algoName->equals("DSA"_s)) {
								dsaKeySize = value;
							} else if (algoName->equals("RSA"_s)) {
								rsaKeySize = value;
							} else if (algoName->equals("RSASSA-PSS"_s)) {
								rsaSsaPssKeySize = value;
							} else if (algoName->equals("DH"_s)) {
								dhKeySize = value;
							} else if (algoName->equals("EC"_s)) {
								ecKeySize = value;
							} else if (algoName->equalsIgnoreCase("EdDSA"_s)) {
								edKeySize = value;
							} else if (algoName->equals("XDH"_s)) {
								xecKeySize = value;
							} else {
								if (SecurityProviderConstants::debug != nullptr) {
									$nc(SecurityProviderConstants::debug)->println($$str({"Ignoring unsupported algo in "_s, SecurityProviderConstants::KEY_LENGTH_PROP, " property: "_s, p}));
								}
								continue;
							}
							if (SecurityProviderConstants::debug != nullptr) {
								$nc(SecurityProviderConstants::debug)->println($$str({"Overriding default "_s, algoName, " keysize with value from "_s, SecurityProviderConstants::KEY_LENGTH_PROP, " property: "_s, $$str(value)}));
							}
						}
					}
				}
			} catch ($PatternSyntaxException& pse) {
				if (SecurityProviderConstants::debug != nullptr) {
					$nc(SecurityProviderConstants::debug)->println($$str({"Unexpected exception while parsing "_s, SecurityProviderConstants::KEY_LENGTH_PROP, " property: "_s, pse}));
				}
			}
		}
		SecurityProviderConstants::DEF_DSA_KEY_SIZE = dsaKeySize;
		SecurityProviderConstants::DEF_RSA_KEY_SIZE = rsaKeySize;
		SecurityProviderConstants::DEF_RSASSA_PSS_KEY_SIZE = rsaSsaPssKeySize;
		SecurityProviderConstants::DEF_DH_KEY_SIZE = dhKeySize;
		SecurityProviderConstants::DEF_EC_KEY_SIZE = ecKeySize;
		SecurityProviderConstants::DEF_ED_KEY_SIZE = edKeySize;
		SecurityProviderConstants::DEF_XEC_KEY_SIZE = xecKeySize;
		$assignStatic(SecurityProviderConstants::aliasesMap, $new($ConcurrentHashMap));
		$init($KnownOIDs);
		SecurityProviderConstants::store("SHA1withDSA"_s, $KnownOIDs::SHA1withDSA, $$new($StringArray, {
			$($KnownOIDs::OIW_JDK_SHA1withDSA->value()),
			$($KnownOIDs::OIW_SHA1withDSA->value()),
			"DSA"_s,
			"SHA/DSA"_s,
			"SHA-1/DSA"_s,
			"SHA1/DSA"_s,
			"SHAwithDSA"_s,
			"DSAWithSHA1"_s
		}));
		SecurityProviderConstants::store("DSA"_s, $KnownOIDs::DSA, $$new($StringArray, {$($KnownOIDs::OIW_DSA->value())}));
		SecurityProviderConstants::store("SHA1withRSA"_s, $KnownOIDs::SHA1withRSA, $$new($StringArray, {$($KnownOIDs::OIW_SHA1withRSA->value())}));
		SecurityProviderConstants::store("SHA-1"_s, $KnownOIDs::SHA_1, $$new($StringArray, 0));
		SecurityProviderConstants::store("PBEWithMD5AndDES"_s, $KnownOIDs::PBEWithMD5AndDES, $$new($StringArray, {"PBE"_s}));
		SecurityProviderConstants::store("DiffieHellman"_s, $KnownOIDs::DiffieHellman, $$new($StringArray, 0));
		SecurityProviderConstants::store("EC"_s, $KnownOIDs::EC, $$new($StringArray, {"EllipticCurve"_s}));
		SecurityProviderConstants::store("X.509"_s, nullptr, $$new($StringArray, {"X509"_s}));
		SecurityProviderConstants::store("NONEwithDSA"_s, nullptr, $$new($StringArray, {"RawDSA"_s}));
		SecurityProviderConstants::store("DESede"_s, nullptr, $$new($StringArray, {"TripleDES"_s}));
		SecurityProviderConstants::store("ARCFOUR"_s, $KnownOIDs::ARCFOUR, $$new($StringArray, 0));
		SecurityProviderConstants::store("PKCS1"_s, $KnownOIDs::PKCS1, $$new($StringArray, {$($KnownOIDs::RSA->value())}));
		SecurityProviderConstants::store("AES/KW/NoPadding"_s, nullptr, $$new($StringArray, {"AESWrap"_s}));
		SecurityProviderConstants::store("AES/KWP/NoPadding"_s, nullptr, $$new($StringArray, {"AESWrapPad"_s}));
	}
}

SecurityProviderConstants::SecurityProviderConstants() {
}

$Class* SecurityProviderConstants::load$($String* name, bool initialize) {
	$loadClass(SecurityProviderConstants, name, initialize, &_SecurityProviderConstants_ClassInfo_, clinit$SecurityProviderConstants, allocate$SecurityProviderConstants);
	return class$;
}

$Class* SecurityProviderConstants::class$ = nullptr;

		} // util
	} // security
} // sun