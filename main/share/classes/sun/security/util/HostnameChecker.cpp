#include <sun/security/util/HostnameChecker.h>

#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/CharSequence.h>
#include <java/lang/SecurityException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/IDN.h>
#include <java/net/InetAddress.h>
#include <java/net/UnknownHostException.h>
#include <java/security/Principal.h>
#include <java/security/cert/CertificateException.h>
#include <java/security/cert/CertificateParsingException.h>
#include <java/security/cert/X509Certificate.h>
#include <java/text/Normalizer$Form.h>
#include <java/text/Normalizer.h>
#include <java/util/Collection.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/Optional.h>
#include <java/util/StringTokenizer.h>
#include <java/util/function/Function.h>
#include <java/util/function/Predicate.h>
#include <javax/net/ssl/SNIHostName.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <sun/net/util/IPAddressUtil.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <sun/security/util/RegisteredDomain$Type.h>
#include <sun/security/util/RegisteredDomain.h>
#include <sun/security/x509/X500Name.h>
#include <jcpp.h>

#undef ALTNAME_DNS
#undef ALTNAME_IP
#undef ENGLISH
#undef ICANN
#undef INSTANCE_LDAP
#undef INSTANCE_TLS
#undef NFKC
#undef TYPE_LDAP
#undef TYPE_TLS

using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $SecurityException = ::java::lang::SecurityException;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $IDN = ::java::net::IDN;
using $InetAddress = ::java::net::InetAddress;
using $UnknownHostException = ::java::net::UnknownHostException;
using $Principal = ::java::security::Principal;
using $CertificateException = ::java::security::cert::CertificateException;
using $CertificateParsingException = ::java::security::cert::CertificateParsingException;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $Normalizer = ::java::text::Normalizer;
using $Normalizer$Form = ::java::text::Normalizer$Form;
using $Collection = ::java::util::Collection;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Optional = ::java::util::Optional;
using $StringTokenizer = ::java::util::StringTokenizer;
using $Function = ::java::util::function::Function;
using $Predicate = ::java::util::function::Predicate;
using $SNIHostName = ::javax::net::ssl::SNIHostName;
using $X500Principal = ::javax::security::auth::x500::X500Principal;
using $IPAddressUtil = ::sun::net::util::IPAddressUtil;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $DerValue = ::sun::security::util::DerValue;
using $RegisteredDomain = ::sun::security::util::RegisteredDomain;
using $RegisteredDomain$Type = ::sun::security::util::RegisteredDomain$Type;
using $X500Name = ::sun::security::x509::X500Name;

namespace sun {
	namespace security {
		namespace util {

class HostnameChecker$$Lambda$lambda$hasIllegalWildcard$0 : public $Predicate {
	$class(HostnameChecker$$Lambda$lambda$hasIllegalWildcard$0, $NO_CLASS_INIT, $Predicate)
public:
	void init$() {
	}
	virtual bool test(Object$* d) override {
		 return HostnameChecker::lambda$hasIllegalWildcard$0($cast($RegisteredDomain, d));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HostnameChecker$$Lambda$lambda$hasIllegalWildcard$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo HostnameChecker$$Lambda$lambda$hasIllegalWildcard$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(HostnameChecker$$Lambda$lambda$hasIllegalWildcard$0, init$, void)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(HostnameChecker$$Lambda$lambda$hasIllegalWildcard$0, test, bool, Object$*)},
	{}
};
$ClassInfo HostnameChecker$$Lambda$lambda$hasIllegalWildcard$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.security.util.HostnameChecker$$Lambda$lambda$hasIllegalWildcard$0",
	"java.lang.Object",
	"java.util.function.Predicate",
	nullptr,
	methodInfos
};
$Class* HostnameChecker$$Lambda$lambda$hasIllegalWildcard$0::load$($String* name, bool initialize) {
	$loadClass(HostnameChecker$$Lambda$lambda$hasIllegalWildcard$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HostnameChecker$$Lambda$lambda$hasIllegalWildcard$0::class$ = nullptr;

class HostnameChecker$$Lambda$publicSuffix$1 : public $Function {
	$class(HostnameChecker$$Lambda$publicSuffix$1, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $of($sure($RegisteredDomain, inst$)->publicSuffix());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HostnameChecker$$Lambda$publicSuffix$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo HostnameChecker$$Lambda$publicSuffix$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(HostnameChecker$$Lambda$publicSuffix$1, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(HostnameChecker$$Lambda$publicSuffix$1, apply, $Object*, Object$*)},
	{}
};
$ClassInfo HostnameChecker$$Lambda$publicSuffix$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.security.util.HostnameChecker$$Lambda$publicSuffix$1",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* HostnameChecker$$Lambda$publicSuffix$1::load$($String* name, bool initialize) {
	$loadClass(HostnameChecker$$Lambda$publicSuffix$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HostnameChecker$$Lambda$publicSuffix$1::class$ = nullptr;

$FieldInfo _HostnameChecker_FieldInfo_[] = {
	{"TYPE_TLS", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HostnameChecker, TYPE_TLS)},
	{"INSTANCE_TLS", "Lsun/security/util/HostnameChecker;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HostnameChecker, INSTANCE_TLS)},
	{"TYPE_LDAP", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HostnameChecker, TYPE_LDAP)},
	{"INSTANCE_LDAP", "Lsun/security/util/HostnameChecker;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HostnameChecker, INSTANCE_LDAP)},
	{"ALTNAME_DNS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(HostnameChecker, ALTNAME_DNS)},
	{"ALTNAME_IP", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(HostnameChecker, ALTNAME_IP)},
	{"checkType", "B", nullptr, $PRIVATE | $FINAL, $field(HostnameChecker, checkType)},
	{}
};

$MethodInfo _HostnameChecker_MethodInfo_[] = {
	{"<init>", "(B)V", nullptr, $PRIVATE, $method(HostnameChecker, init$, void, int8_t)},
	{"getInstance", "(B)Lsun/security/util/HostnameChecker;", nullptr, $PUBLIC | $STATIC, $staticMethod(HostnameChecker, getInstance, HostnameChecker*, int8_t)},
	{"getSubjectX500Name", "(Ljava/security/cert/X509Certificate;)Lsun/security/x509/X500Name;", nullptr, $PUBLIC | $STATIC, $staticMethod(HostnameChecker, getSubjectX500Name, $X500Name*, $X509Certificate*), "java.security.cert.CertificateParsingException"},
	{"hasIllegalWildcard", "(Ljava/lang/String;Z)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(HostnameChecker, hasIllegalWildcard, bool, $String*, bool)},
	{"isIpAddress", "(Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(HostnameChecker, isIpAddress, bool, $String*)},
	{"isMatched", "(Ljava/lang/String;Ljava/lang/String;Z)Z", nullptr, $PRIVATE, $method(HostnameChecker, isMatched, bool, $String*, $String*, bool)},
	{"lambda$hasIllegalWildcard$0", "(Lsun/security/util/RegisteredDomain;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(HostnameChecker, lambda$hasIllegalWildcard$0, bool, $RegisteredDomain*)},
	{"match", "(Ljava/lang/String;Ljava/security/cert/X509Certificate;Z)V", nullptr, $PUBLIC, $virtualMethod(HostnameChecker, match, void, $String*, $X509Certificate*, bool), "java.security.cert.CertificateException"},
	{"match", "(Ljava/lang/String;Ljava/security/cert/X509Certificate;)V", nullptr, $PUBLIC, $virtualMethod(HostnameChecker, match, void, $String*, $X509Certificate*), "java.security.cert.CertificateException"},
	{"matchAllWildcards", "(Ljava/lang/String;Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(HostnameChecker, matchAllWildcards, bool, $String*, $String*)},
	{"matchDNS", "(Ljava/lang/String;Ljava/security/cert/X509Certificate;Z)V", nullptr, $PRIVATE, $method(HostnameChecker, matchDNS, void, $String*, $X509Certificate*, bool), "java.security.cert.CertificateException"},
	{"matchIP", "(Ljava/lang/String;Ljava/security/cert/X509Certificate;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(HostnameChecker, matchIP, void, $String*, $X509Certificate*), "java.security.cert.CertificateException"},
	{"matchLeftmostWildcard", "(Ljava/lang/String;Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(HostnameChecker, matchLeftmostWildcard, bool, $String*, $String*)},
	{"matchWildCards", "(Ljava/lang/String;Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(HostnameChecker, matchWildCards, bool, $String*, $String*)},
	{}
};

$ClassInfo _HostnameChecker_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.util.HostnameChecker",
	"java.lang.Object",
	nullptr,
	_HostnameChecker_FieldInfo_,
	_HostnameChecker_MethodInfo_
};

$Object* allocate$HostnameChecker($Class* clazz) {
	return $of($alloc(HostnameChecker));
}

HostnameChecker* HostnameChecker::INSTANCE_TLS = nullptr;
HostnameChecker* HostnameChecker::INSTANCE_LDAP = nullptr;

void HostnameChecker::init$(int8_t checkType) {
	this->checkType = checkType;
}

HostnameChecker* HostnameChecker::getInstance(int8_t checkType) {
	$init(HostnameChecker);
	$useLocalCurrentObjectStackCache();
	if (checkType == HostnameChecker::TYPE_TLS) {
		return HostnameChecker::INSTANCE_TLS;
	} else if (checkType == HostnameChecker::TYPE_LDAP) {
		return HostnameChecker::INSTANCE_LDAP;
	}
	$throwNew($IllegalArgumentException, $$str({"Unknown check type: "_s, $$str(checkType)}));
}

void HostnameChecker::match($String* expectedName, $X509Certificate* cert, bool chainsToPublicCA) {
	if (expectedName == nullptr) {
		$throwNew($CertificateException, "Hostname or IP address is undefined."_s);
	}
	if (isIpAddress(expectedName)) {
		matchIP(expectedName, cert);
	} else {
		matchDNS(expectedName, cert, chainsToPublicCA);
	}
}

void HostnameChecker::match($String* expectedName, $X509Certificate* cert) {
	match(expectedName, cert, false);
}

bool HostnameChecker::isIpAddress($String* name) {
	$init(HostnameChecker);
	bool var$0 = $IPAddressUtil::isIPv4LiteralAddress(name);
	if (var$0 || $IPAddressUtil::isIPv6LiteralAddress(name)) {
		return true;
	} else {
		return false;
	}
}

void HostnameChecker::matchIP($String* expectedIP, $X509Certificate* cert) {
	$init(HostnameChecker);
	$useLocalCurrentObjectStackCache();
	$var($Collection, subjAltNames, $nc(cert)->getSubjectAlternativeNames());
	if (subjAltNames == nullptr) {
		$throwNew($CertificateException, "No subject alternative names present"_s);
	}
	{
		$var($Iterator, i$, $nc(subjAltNames)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($List, next, $cast($List, i$->next()));
			{
				if ($nc(($cast($Integer, $($nc(next)->get(0)))))->intValue() == HostnameChecker::ALTNAME_IP) {
					$var($String, ipAddress, $cast($String, next->get(1)));
					if ($nc(expectedIP)->equalsIgnoreCase(ipAddress)) {
						return;
					} else {
						try {
							if ($nc($($InetAddress::getByName(expectedIP)))->equals($($InetAddress::getByName(ipAddress)))) {
								return;
							}
						} catch ($UnknownHostException& e) {
						} catch ($SecurityException& e) {
						}
					}
				}
			}
		}
	}
	$throwNew($CertificateException, $$str({"No subject alternative names matching IP address "_s, expectedIP, " found"_s}));
}

void HostnameChecker::matchDNS($String* expectedName, $X509Certificate* cert, bool chainsToPublicCA) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($SNIHostName, sni, $new($SNIHostName, expectedName));
	} catch ($IllegalArgumentException& iae) {
		$throwNew($CertificateException, $$str({"Illegal given domain name: "_s, expectedName}), iae);
	}
	$var($Collection, subjAltNames, $nc(cert)->getSubjectAlternativeNames());
	if (subjAltNames != nullptr) {
		bool foundDNS = false;
		{
			$var($Iterator, i$, subjAltNames->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($List, next, $cast($List, i$->next()));
				{
					if ($nc(($cast($Integer, $($nc(next)->get(0)))))->intValue() == HostnameChecker::ALTNAME_DNS) {
						foundDNS = true;
						$var($String, dnsName, $cast($String, next->get(1)));
						if (isMatched(expectedName, dnsName, chainsToPublicCA)) {
							return;
						}
					}
				}
			}
		}
		if (foundDNS) {
			$throwNew($CertificateException, $$str({"No subject alternative DNS name matching "_s, expectedName, " found."_s}));
		}
	}
	$var($X500Name, subjectName, getSubjectX500Name(cert));
	$init($X500Name);
	$var($DerValue, derValue, $nc(subjectName)->findMostSpecificAttribute($X500Name::commonName_oid));
	if (derValue != nullptr) {
		try {
			$var($String, cname, derValue->getAsString());
			$init($Normalizer$Form);
			if (!$Normalizer::isNormalized(cname, $Normalizer$Form::NFKC)) {
				$throwNew($CertificateException, $$str({"Not a formal name "_s, cname}));
			}
			if (isMatched(expectedName, cname, chainsToPublicCA)) {
				return;
			}
		} catch ($IOException& e) {
		}
	}
	$var($String, msg, $str({"No name matching "_s, expectedName, " found"_s}));
	$throwNew($CertificateException, msg);
}

$X500Name* HostnameChecker::getSubjectX500Name($X509Certificate* cert) {
	$init(HostnameChecker);
	$useLocalCurrentObjectStackCache();
	try {
		$var($Principal, subjectDN, $nc(cert)->getSubjectDN());
		if ($instanceOf($X500Name, subjectDN)) {
			return $cast($X500Name, subjectDN);
		} else {
			$var($X500Principal, subjectX500, cert->getSubjectX500Principal());
			return $new($X500Name, $($nc(subjectX500)->getEncoded()));
		}
	} catch ($IOException& e) {
		$throw($cast($CertificateParsingException, $($$new($CertificateParsingException)->initCause(e))));
	}
	$shouldNotReachHere();
}

bool HostnameChecker::isMatched($String* name$renamed, $String* template$$renamed, bool chainsToPublicCA) {
	$useLocalCurrentObjectStackCache();
	$var($String, template$, template$$renamed);
	$var($String, name, name$renamed);
	try {
		$assign(name, $IDN::toUnicode($($IDN::toASCII(name))));
		$assign(template$, $IDN::toUnicode($($IDN::toASCII(template$))));
	} catch ($RuntimeException& re) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$) {
			$SSLLogger::fine($$str({"Failed to normalize to Unicode: "_s, re}), $$new($ObjectArray, 0));
		}
		return false;
	}
	if (hasIllegalWildcard(template$, chainsToPublicCA)) {
		return false;
	}
	try {
		$new($SNIHostName, $($nc(template$)->replace(u'*', u'z')));
	} catch ($IllegalArgumentException& iae) {
		return false;
	}
	if (this->checkType == HostnameChecker::TYPE_TLS) {
		return matchAllWildcards(name, template$);
	} else if (this->checkType == HostnameChecker::TYPE_LDAP) {
		return matchLeftmostWildcard(name, template$);
	} else {
		return false;
	}
}

bool HostnameChecker::hasIllegalWildcard($String* template$, bool chainsToPublicCA) {
	$init(HostnameChecker);
	$useLocalCurrentObjectStackCache();
	bool var$0 = $nc(template$)->equals("*"_s);
	if (var$0 || $nc(template$)->equals("*."_s)) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$) {
			$SSLLogger::fine($$str({"Certificate domain name has illegal single wildcard character: "_s, template$}), $$new($ObjectArray, 0));
		}
		return true;
	}
	int32_t lastWildcardIndex = $nc(template$)->lastIndexOf("*"_s);
	if (lastWildcardIndex == -1) {
		return false;
	}
	$var($String, afterWildcard, template$->substring(lastWildcardIndex));
	int32_t firstDotIndex = afterWildcard->indexOf("."_s);
	if (firstDotIndex == -1) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$) {
			$SSLLogger::fine($$str({"Certificate domain name has illegal wildcard, no dot after wildcard character: "_s, template$}), $$new($ObjectArray, 0));
		}
		return true;
	}
	if (!chainsToPublicCA) {
		return false;
	}
	$var($String, wildcardedDomain, afterWildcard->substring(firstDotIndex + 1));
	$var($String, templateDomainSuffix, $cast($String, $nc($($nc($($nc($($RegisteredDomain::from($$str({"z."_s, wildcardedDomain}))))->filter(static_cast<$Predicate*>($$new(HostnameChecker$$Lambda$lambda$hasIllegalWildcard$0)))))->map(static_cast<$Function*>($$new(HostnameChecker$$Lambda$publicSuffix$1)))))->orElse(nullptr)));
	if (templateDomainSuffix == nullptr) {
		return false;
	}
	if (wildcardedDomain->equalsIgnoreCase(templateDomainSuffix)) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$) {
			$SSLLogger::fine($$str({"Certificate domain name has illegal wildcard for top-level public suffix: "_s, template$}), $$new($ObjectArray, 0));
		}
		return true;
	}
	return false;
}

bool HostnameChecker::matchAllWildcards($String* name$renamed, $String* template$$renamed) {
	$init(HostnameChecker);
	$useLocalCurrentObjectStackCache();
	$var($String, template$, template$$renamed);
	$var($String, name, name$renamed);
	$init($Locale);
	$assign(name, $nc(name)->toLowerCase($Locale::ENGLISH));
	$assign(template$, $nc(template$)->toLowerCase($Locale::ENGLISH));
	$var($StringTokenizer, nameSt, $new($StringTokenizer, name, "."_s));
	$var($StringTokenizer, templateSt, $new($StringTokenizer, template$, "."_s));
	int32_t var$0 = nameSt->countTokens();
	if (var$0 != templateSt->countTokens()) {
		return false;
	}
	while (nameSt->hasMoreTokens()) {
		$var($String, var$1, nameSt->nextToken());
		if (!matchWildCards(var$1, $(templateSt->nextToken()))) {
			return false;
		}
	}
	return true;
}

bool HostnameChecker::matchLeftmostWildcard($String* name$renamed, $String* template$$renamed) {
	$init(HostnameChecker);
	$useLocalCurrentObjectStackCache();
	$var($String, template$, template$$renamed);
	$var($String, name, name$renamed);
	$init($Locale);
	$assign(name, $nc(name)->toLowerCase($Locale::ENGLISH));
	$assign(template$, $nc(template$)->toLowerCase($Locale::ENGLISH));
	int32_t templateIdx = template$->indexOf("."_s);
	int32_t nameIdx = name->indexOf("."_s);
	if (templateIdx == -1) {
		templateIdx = template$->length();
	}
	if (nameIdx == -1) {
		nameIdx = name->length();
	}
	$var($String, var$0, name->substring(0, nameIdx));
	if (matchWildCards(var$0, $(template$->substring(0, templateIdx)))) {
		return $(template$->substring(templateIdx))->equals($(name->substring(nameIdx)));
	} else {
		return false;
	}
}

bool HostnameChecker::matchWildCards($String* name$renamed, $String* template$) {
	$init(HostnameChecker);
	$useLocalCurrentObjectStackCache();
	$var($String, name, name$renamed);
	int32_t wildcardIdx = $nc(template$)->indexOf("*"_s);
	if (wildcardIdx == -1) {
		return $nc(name)->equals(template$);
	}
	bool isBeginning = true;
	$var($String, beforeWildcard, ""_s);
	$var($String, afterWildcard, template$);
	while (wildcardIdx != -1) {
		$assign(beforeWildcard, afterWildcard->substring(0, wildcardIdx));
		$assign(afterWildcard, afterWildcard->substring(wildcardIdx + 1));
		int32_t beforeStartIdx = $nc(name)->indexOf(beforeWildcard);
		if ((beforeStartIdx == -1) || (isBeginning && beforeStartIdx != 0)) {
			return false;
		}
		isBeginning = false;
		$assign(name, name->substring(beforeStartIdx + beforeWildcard->length()));
		wildcardIdx = afterWildcard->indexOf("*"_s);
	}
	return $nc(name)->endsWith(afterWildcard);
}

bool HostnameChecker::lambda$hasIllegalWildcard$0($RegisteredDomain* d) {
	$init(HostnameChecker);
	$init($RegisteredDomain$Type);
	return $nc(d)->type() == $RegisteredDomain$Type::ICANN;
}

void clinit$HostnameChecker($Class* class$) {
	$assignStatic(HostnameChecker::INSTANCE_TLS, $new(HostnameChecker, HostnameChecker::TYPE_TLS));
	$assignStatic(HostnameChecker::INSTANCE_LDAP, $new(HostnameChecker, HostnameChecker::TYPE_LDAP));
}

HostnameChecker::HostnameChecker() {
}

$Class* HostnameChecker::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(HostnameChecker$$Lambda$lambda$hasIllegalWildcard$0::classInfo$.name)) {
			return HostnameChecker$$Lambda$lambda$hasIllegalWildcard$0::load$(name, initialize);
		}
		if (name->equals(HostnameChecker$$Lambda$publicSuffix$1::classInfo$.name)) {
			return HostnameChecker$$Lambda$publicSuffix$1::load$(name, initialize);
		}
	}
	$loadClass(HostnameChecker, name, initialize, &_HostnameChecker_ClassInfo_, clinit$HostnameChecker, allocate$HostnameChecker);
	return class$;
}

$Class* HostnameChecker::class$ = nullptr;

		} // util
	} // security
} // sun