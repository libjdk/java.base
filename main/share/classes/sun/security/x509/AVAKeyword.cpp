#include <sun/security/x509/AVAKeyword.h>

#include <java/io/IOException.h>
#include <java/util/Collections.h>
#include <java/util/HashMap.h>
#include <java/util/Locale.h>
#include <java/util/Map.h>
#include <sun/security/pkcs/PKCS9Attribute.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <sun/security/x509/AVA.h>
#include <sun/security/x509/X500Name.h>
#include <jcpp.h>

#undef DEFAULT
#undef DNQUALIFIER_OID
#undef DOMAIN_COMPONENT_OID
#undef EMAIL_ADDRESS_OID
#undef ENGLISH
#undef GENERATIONQUALIFIER_OID
#undef GIVENNAME_OID
#undef INITIALS_OID
#undef SERIALNUMBER_OID
#undef SURNAME_OID

using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $Collections = ::java::util::Collections;
using $HashMap = ::java::util::HashMap;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $PKCS9Attribute = ::sun::security::pkcs::PKCS9Attribute;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;
using $AVA = ::sun::security::x509::AVA;
using $X500Name = ::sun::security::x509::X500Name;

namespace sun {
	namespace security {
		namespace x509 {

$FieldInfo _AVAKeyword_FieldInfo_[] = {
	{"oidMap", "Ljava/util/Map;", "Ljava/util/Map<Lsun/security/util/ObjectIdentifier;Lsun/security/x509/AVAKeyword;>;", $PRIVATE | $STATIC | $FINAL, $staticField(AVAKeyword, oidMap)},
	{"keywordMap", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Lsun/security/x509/AVAKeyword;>;", $PRIVATE | $STATIC | $FINAL, $staticField(AVAKeyword, keywordMap)},
	{"keyword", "Ljava/lang/String;", nullptr, $PRIVATE, $field(AVAKeyword, keyword)},
	{"oid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PRIVATE, $field(AVAKeyword, oid)},
	{"rfc1779Compliant", "Z", nullptr, $PRIVATE, $field(AVAKeyword, rfc1779Compliant)},
	{"rfc2253Compliant", "Z", nullptr, $PRIVATE, $field(AVAKeyword, rfc2253Compliant)},
	{}
};

$MethodInfo _AVAKeyword_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Lsun/security/util/ObjectIdentifier;ZZ)V", nullptr, $PRIVATE, $method(AVAKeyword, init$, void, $String*, $ObjectIdentifier*, bool, bool)},
	{"getKeyword", "(Lsun/security/util/ObjectIdentifier;I)Ljava/lang/String;", nullptr, $STATIC, $staticMethod(AVAKeyword, getKeyword, $String*, $ObjectIdentifier*, int32_t)},
	{"getKeyword", "(Lsun/security/util/ObjectIdentifier;ILjava/util/Map;)Ljava/lang/String;", "(Lsun/security/util/ObjectIdentifier;ILjava/util/Map<Ljava/lang/String;Ljava/lang/String;>;)Ljava/lang/String;", $STATIC, $staticMethod(AVAKeyword, getKeyword, $String*, $ObjectIdentifier*, int32_t, $Map*)},
	{"getOID", "(Ljava/lang/String;ILjava/util/Map;)Lsun/security/util/ObjectIdentifier;", "(Ljava/lang/String;ILjava/util/Map<Ljava/lang/String;Ljava/lang/String;>;)Lsun/security/util/ObjectIdentifier;", $STATIC, $staticMethod(AVAKeyword, getOID, $ObjectIdentifier*, $String*, int32_t, $Map*), "java.io.IOException"},
	{"hasKeyword", "(Lsun/security/util/ObjectIdentifier;I)Z", nullptr, $STATIC, $staticMethod(AVAKeyword, hasKeyword, bool, $ObjectIdentifier*, int32_t)},
	{"isCompliant", "(I)Z", nullptr, $PRIVATE, $method(AVAKeyword, isCompliant, bool, int32_t)},
	{}
};

$ClassInfo _AVAKeyword_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.x509.AVAKeyword",
	"java.lang.Object",
	nullptr,
	_AVAKeyword_FieldInfo_,
	_AVAKeyword_MethodInfo_
};

$Object* allocate$AVAKeyword($Class* clazz) {
	return $of($alloc(AVAKeyword));
}

$Map* AVAKeyword::oidMap = nullptr;
$Map* AVAKeyword::keywordMap = nullptr;

void AVAKeyword::init$($String* keyword, $ObjectIdentifier* oid, bool rfc1779Compliant, bool rfc2253Compliant) {
	$set(this, keyword, keyword);
	$set(this, oid, oid);
	this->rfc1779Compliant = rfc1779Compliant;
	this->rfc2253Compliant = rfc2253Compliant;
	$nc(AVAKeyword::oidMap)->put(oid, this);
	$nc(AVAKeyword::keywordMap)->put(keyword, this);
}

bool AVAKeyword::isCompliant(int32_t standard) {
	$useLocalCurrentObjectStackCache();
	switch (standard) {
	case $AVA::RFC1779:
		{
			return this->rfc1779Compliant;
		}
	case $AVA::RFC2253:
		{
			return this->rfc2253Compliant;
		}
	case $AVA::DEFAULT:
		{
			return true;
		}
	default:
		{
			$throwNew($IllegalArgumentException, $$str({"Invalid standard "_s, $$str(standard)}));
		}
	}
}

$ObjectIdentifier* AVAKeyword::getOID($String* keyword$renamed, int32_t standard, $Map* extraKeywordMap) {
	$init(AVAKeyword);
	$useLocalCurrentObjectStackCache();
	$var($String, keyword, keyword$renamed);
	$init($Locale);
	$assign(keyword, $nc(keyword)->toUpperCase($Locale::ENGLISH));
	if (standard == $AVA::RFC2253) {
		bool var$0 = keyword->startsWith(" "_s);
		if (var$0 || keyword->endsWith(" "_s)) {
			$throwNew($IOException, $$str({"Invalid leading or trailing space in keyword \""_s, keyword, "\""_s}));
		}
	} else {
		$assign(keyword, keyword->trim());
	}
	$var($String, oidString, $cast($String, $nc(extraKeywordMap)->get(keyword)));
	if (oidString == nullptr) {
		$var(AVAKeyword, ak, $cast(AVAKeyword, $nc(AVAKeyword::keywordMap)->get(keyword)));
		if ((ak != nullptr) && ak->isCompliant(standard)) {
			return ak->oid;
		}
	} else {
		return $ObjectIdentifier::of(oidString);
	}
	if (standard == $AVA::DEFAULT && keyword->startsWith("OID."_s)) {
		$assign(keyword, keyword->substring(4));
	}
	bool number = false;
	if (!keyword->isEmpty()) {
		char16_t ch = keyword->charAt(0);
		if ((ch >= u'0') && (ch <= u'9')) {
			number = true;
		}
	}
	if (number == false) {
		$throwNew($IOException, $$str({"Invalid keyword \""_s, keyword, "\""_s}));
	}
	return $ObjectIdentifier::of(keyword);
}

$String* AVAKeyword::getKeyword($ObjectIdentifier* oid, int32_t standard) {
	$init(AVAKeyword);
	return getKeyword(oid, standard, $($Collections::emptyMap()));
}

$String* AVAKeyword::getKeyword($ObjectIdentifier* oid, int32_t standard, $Map* extraOidMap) {
	$init(AVAKeyword);
	$useLocalCurrentObjectStackCache();
	$var($String, oidString, $nc(oid)->toString());
	$var($String, keywordString, $cast($String, $nc(extraOidMap)->get(oidString)));
	if (keywordString == nullptr) {
		$var(AVAKeyword, ak, $cast(AVAKeyword, $nc(AVAKeyword::oidMap)->get(oid)));
		if ((ak != nullptr) && ak->isCompliant(standard)) {
			return ak->keyword;
		}
	} else {
		if ($nc(keywordString)->isEmpty()) {
			$throwNew($IllegalArgumentException, "keyword cannot be empty"_s);
		}
		$assign(keywordString, $nc(keywordString)->trim());
		char16_t c = keywordString->charAt(0);
		if (c < 65 || c > 122 || (c > 90 && c < 97)) {
			$throwNew($IllegalArgumentException, "keyword does not start with letter"_s);
		}
		for (int32_t i = 1; i < keywordString->length(); ++i) {
			c = keywordString->charAt(i);
			if ((c < 65 || c > 122 || (c > 90 && c < 97)) && (c < 48 || c > 57) && c != u'_') {
				$throwNew($IllegalArgumentException, "keyword character is not a letter, digit, or underscore"_s);
			}
		}
		return keywordString;
	}
	if (standard == $AVA::RFC2253) {
		return oidString;
	} else {
		return $str({"OID."_s, oidString});
	}
}

bool AVAKeyword::hasKeyword($ObjectIdentifier* oid, int32_t standard) {
	$init(AVAKeyword);
	$var(AVAKeyword, ak, $cast(AVAKeyword, $nc(AVAKeyword::oidMap)->get(oid)));
	if (ak == nullptr) {
		return false;
	}
	return $nc(ak)->isCompliant(standard);
}

void clinit$AVAKeyword($Class* class$) {
	{
		$assignStatic(AVAKeyword::oidMap, $new($HashMap));
		$assignStatic(AVAKeyword::keywordMap, $new($HashMap));
		$init($X500Name);
		$new(AVAKeyword, "CN"_s, $X500Name::commonName_oid, true, true);
		$new(AVAKeyword, "C"_s, $X500Name::countryName_oid, true, true);
		$new(AVAKeyword, "L"_s, $X500Name::localityName_oid, true, true);
		$new(AVAKeyword, "S"_s, $X500Name::stateName_oid, false, false);
		$new(AVAKeyword, "ST"_s, $X500Name::stateName_oid, true, true);
		$new(AVAKeyword, "O"_s, $X500Name::orgName_oid, true, true);
		$new(AVAKeyword, "OU"_s, $X500Name::orgUnitName_oid, true, true);
		$new(AVAKeyword, "T"_s, $X500Name::title_oid, false, false);
		$new(AVAKeyword, "IP"_s, $X500Name::ipAddress_oid, false, false);
		$new(AVAKeyword, "STREET"_s, $X500Name::streetAddress_oid, true, true);
		$new(AVAKeyword, "DC"_s, $X500Name::DOMAIN_COMPONENT_OID, false, true);
		$new(AVAKeyword, "DNQUALIFIER"_s, $X500Name::DNQUALIFIER_OID, false, false);
		$new(AVAKeyword, "DNQ"_s, $X500Name::DNQUALIFIER_OID, false, false);
		$new(AVAKeyword, "SURNAME"_s, $X500Name::SURNAME_OID, false, false);
		$new(AVAKeyword, "GIVENNAME"_s, $X500Name::GIVENNAME_OID, false, false);
		$new(AVAKeyword, "INITIALS"_s, $X500Name::INITIALS_OID, false, false);
		$new(AVAKeyword, "GENERATION"_s, $X500Name::GENERATIONQUALIFIER_OID, false, false);
		$init($PKCS9Attribute);
		$new(AVAKeyword, "EMAIL"_s, $PKCS9Attribute::EMAIL_ADDRESS_OID, false, false);
		$new(AVAKeyword, "EMAILADDRESS"_s, $PKCS9Attribute::EMAIL_ADDRESS_OID, false, false);
		$new(AVAKeyword, "UID"_s, $X500Name::userid_oid, false, true);
		$new(AVAKeyword, "SERIALNUMBER"_s, $X500Name::SERIALNUMBER_OID, false, false);
	}
}

AVAKeyword::AVAKeyword() {
}

$Class* AVAKeyword::load$($String* name, bool initialize) {
	$loadClass(AVAKeyword, name, initialize, &_AVAKeyword_ClassInfo_, clinit$AVAKeyword, allocate$AVAKeyword);
	return class$;
}

$Class* AVAKeyword::class$ = nullptr;

		} // x509
	} // security
} // sun