#include <sun/security/x509/X500Name.h>

#include <java/io/IOException.h>
#include <java/lang/CharSequence.h>
#include <java/lang/InternalError.h>
#include <java/lang/Math.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Field.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/StringJoiner.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/KnownOIDs.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <sun/security/x509/AVA.h>
#include <sun/security/x509/GeneralNameInterface.h>
#include <sun/security/x509/RDN.h>
#include <sun/security/x509/X500Name$1.h>
#include <jcpp.h>

#undef DNQUALIFIER_OID
#undef DOMAIN_COMPONENT_OID
#undef GENERATIONQUALIFIER_OID
#undef GIVENNAME_OID
#undef INITIALS_OID
#undef NAME_DIFF_TYPE
#undef NAME_DIRECTORY
#undef NAME_MATCH
#undef NAME_NARROWS
#undef NAME_SAME_TYPE
#undef NAME_WIDENS
#undef SERIALNUMBER_OID
#undef SURNAME_OID

using $DerValueArray = $Array<::sun::security::util::DerValue>;
using $RDNArray = $Array<::sun::security::x509::RDN>;
using $IOException = ::java::io::IOException;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $RuntimeException = ::java::lang::RuntimeException;
using $Constructor = ::java::lang::reflect::Constructor;
using $Field = ::java::lang::reflect::Field;
using $AccessController = ::java::security::AccessController;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $StringJoiner = ::java::util::StringJoiner;
using $X500Principal = ::javax::security::auth::x500::X500Principal;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;
using $KnownOIDs = ::sun::security::util::KnownOIDs;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;
using $AVA = ::sun::security::x509::AVA;
using $GeneralNameInterface = ::sun::security::x509::GeneralNameInterface;
using $RDN = ::sun::security::x509::RDN;
using $X500Name$1 = ::sun::security::x509::X500Name$1;

namespace sun {
	namespace security {
		namespace x509 {

$CompoundAttribute _X500Name_MethodAnnotations_emit16[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _X500Name_FieldInfo_[] = {
	{"dn", "Ljava/lang/String;", nullptr, $PRIVATE, $field(X500Name, dn)},
	{"rfc1779Dn", "Ljava/lang/String;", nullptr, $PRIVATE, $field(X500Name, rfc1779Dn)},
	{"rfc2253Dn", "Ljava/lang/String;", nullptr, $PRIVATE, $field(X500Name, rfc2253Dn)},
	{"canonicalDn", "Ljava/lang/String;", nullptr, $PRIVATE, $field(X500Name, canonicalDn)},
	{"names", "[Lsun/security/x509/RDN;", nullptr, $PRIVATE, $field(X500Name, names)},
	{"x500Principal", "Ljavax/security/auth/x500/X500Principal;", nullptr, $PRIVATE, $field(X500Name, x500Principal)},
	{"encoded", "[B", nullptr, $PRIVATE, $field(X500Name, encoded)},
	{"rdnList", "Ljava/util/List;", "Ljava/util/List<Lsun/security/x509/RDN;>;", $PRIVATE | $VOLATILE, $field(X500Name, rdnList)},
	{"allAvaList", "Ljava/util/List;", "Ljava/util/List<Lsun/security/x509/AVA;>;", $PRIVATE | $VOLATILE, $field(X500Name, allAvaList)},
	{"commonName_oid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X500Name, commonName_oid)},
	{"SURNAME_OID", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X500Name, SURNAME_OID)},
	{"SERIALNUMBER_OID", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X500Name, SERIALNUMBER_OID)},
	{"countryName_oid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X500Name, countryName_oid)},
	{"localityName_oid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X500Name, localityName_oid)},
	{"stateName_oid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X500Name, stateName_oid)},
	{"streetAddress_oid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X500Name, streetAddress_oid)},
	{"orgName_oid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X500Name, orgName_oid)},
	{"orgUnitName_oid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X500Name, orgUnitName_oid)},
	{"title_oid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X500Name, title_oid)},
	{"GIVENNAME_OID", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X500Name, GIVENNAME_OID)},
	{"INITIALS_OID", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X500Name, INITIALS_OID)},
	{"GENERATIONQUALIFIER_OID", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X500Name, GENERATIONQUALIFIER_OID)},
	{"DNQUALIFIER_OID", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X500Name, DNQUALIFIER_OID)},
	{"ipAddress_oid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X500Name, ipAddress_oid)},
	{"DOMAIN_COMPONENT_OID", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X500Name, DOMAIN_COMPONENT_OID)},
	{"userid_oid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X500Name, userid_oid)},
	{"principalConstructor", "Ljava/lang/reflect/Constructor;", "Ljava/lang/reflect/Constructor<Ljavax/security/auth/x500/X500Principal;>;", $PRIVATE | $STATIC | $FINAL, $staticField(X500Name, principalConstructor)},
	{"principalField", "Ljava/lang/reflect/Field;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(X500Name, principalField)},
	{}
};

$MethodInfo _X500Name_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(X500Name, init$, void, $String*), "java.io.IOException"},
	{"<init>", "(Ljava/lang/String;Ljava/util/Map;)V", "(Ljava/lang/String;Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;)V", $PUBLIC, $method(X500Name, init$, void, $String*, $Map*), "java.io.IOException"},
	{"<init>", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(X500Name, init$, void, $String*, $String*), "java.io.IOException"},
	{"<init>", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(X500Name, init$, void, $String*, $String*, $String*, $String*), "java.io.IOException"},
	{"<init>", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(X500Name, init$, void, $String*, $String*, $String*, $String*, $String*, $String*), "java.io.IOException"},
	{"<init>", "([Lsun/security/x509/RDN;)V", nullptr, $PUBLIC, $method(X500Name, init$, void, $RDNArray*), "java.io.IOException"},
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(X500Name, init$, void, $DerValue*), "java.io.IOException"},
	{"<init>", "(Lsun/security/util/DerInputStream;)V", nullptr, $PUBLIC, $method(X500Name, init$, void, $DerInputStream*), "java.io.IOException"},
	{"<init>", "([B)V", nullptr, $PUBLIC, $method(X500Name, init$, void, $bytes*), "java.io.IOException"},
	{"allAvas", "()Ljava/util/List;", "()Ljava/util/List<Lsun/security/x509/AVA;>;", $PUBLIC, $virtualMethod(X500Name, allAvas, $List*)},
	{"asX500Name", "(Ljavax/security/auth/x500/X500Principal;)Lsun/security/x509/X500Name;", nullptr, $PUBLIC | $STATIC, $staticMethod(X500Name, asX500Name, X500Name*, $X500Principal*)},
	{"asX500Principal", "()Ljavax/security/auth/x500/X500Principal;", nullptr, $PUBLIC, $virtualMethod(X500Name, asX500Principal, $X500Principal*)},
	{"avaSize", "()I", nullptr, $PUBLIC, $virtualMethod(X500Name, avaSize, int32_t)},
	{"commonAncestor", "(Lsun/security/x509/X500Name;)Lsun/security/x509/X500Name;", nullptr, $PUBLIC, $virtualMethod(X500Name, commonAncestor, X500Name*, X500Name*)},
	{"constrains", "(Lsun/security/x509/GeneralNameInterface;)I", nullptr, $PUBLIC, $virtualMethod(X500Name, constrains, int32_t, $GeneralNameInterface*), "java.lang.UnsupportedOperationException"},
	{"countQuotes", "(Ljava/lang/String;II)I", nullptr, $STATIC, $staticMethod(X500Name, countQuotes, int32_t, $String*, int32_t, int32_t)},
	{"emit", "(Lsun/security/util/DerOutputStream;)V", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(X500Name, emit, void, $DerOutputStream*), "java.io.IOException", nullptr, _X500Name_MethodAnnotations_emit16},
	{"encode", "(Lsun/security/util/DerOutputStream;)V", nullptr, $PUBLIC, $virtualMethod(X500Name, encode, void, $DerOutputStream*), "java.io.IOException"},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(X500Name, equals, bool, Object$*)},
	{"escaped", "(IILjava/lang/String;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(X500Name, escaped, bool, int32_t, int32_t, $String*)},
	{"findAttribute", "(Lsun/security/util/ObjectIdentifier;)Lsun/security/util/DerValue;", nullptr, $PRIVATE, $method(X500Name, findAttribute, $DerValue*, $ObjectIdentifier*)},
	{"findMostSpecificAttribute", "(Lsun/security/util/ObjectIdentifier;)Lsun/security/util/DerValue;", nullptr, $PUBLIC, $virtualMethod(X500Name, findMostSpecificAttribute, $DerValue*, $ObjectIdentifier*)},
	{"generateDN", "()V", nullptr, $PRIVATE, $method(X500Name, generateDN, void)},
	{"generateRFC1779DN", "(Ljava/util/Map;)Ljava/lang/String;", "(Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;)Ljava/lang/String;", $PRIVATE, $method(X500Name, generateRFC1779DN, $String*, $Map*)},
	{"generateRFC2253DN", "(Ljava/util/Map;)Ljava/lang/String;", "(Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;)Ljava/lang/String;", $PRIVATE, $method(X500Name, generateRFC2253DN, $String*, $Map*)},
	{"getCommonName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(X500Name, getCommonName, $String*), "java.io.IOException"},
	{"getCountry", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(X500Name, getCountry, $String*), "java.io.IOException"},
	{"getDNQualifier", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(X500Name, getDNQualifier, $String*), "java.io.IOException"},
	{"getDomain", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(X500Name, getDomain, $String*), "java.io.IOException"},
	{"getEncoded", "()[B", nullptr, $PUBLIC, $virtualMethod(X500Name, getEncoded, $bytes*), "java.io.IOException"},
	{"getEncodedInternal", "()[B", nullptr, $PUBLIC, $virtualMethod(X500Name, getEncodedInternal, $bytes*), "java.io.IOException"},
	{"getGeneration", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(X500Name, getGeneration, $String*), "java.io.IOException"},
	{"getGivenName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(X500Name, getGivenName, $String*), "java.io.IOException"},
	{"getIP", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(X500Name, getIP, $String*), "java.io.IOException"},
	{"getInitials", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(X500Name, getInitials, $String*), "java.io.IOException"},
	{"getLocality", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(X500Name, getLocality, $String*), "java.io.IOException"},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(X500Name, getName, $String*)},
	{"getOrganization", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(X500Name, getOrganization, $String*), "java.io.IOException"},
	{"getOrganizationalUnit", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(X500Name, getOrganizationalUnit, $String*), "java.io.IOException"},
	{"getRFC1779Name", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(X500Name, getRFC1779Name, $String*)},
	{"getRFC1779Name", "(Ljava/util/Map;)Ljava/lang/String;", "(Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;)Ljava/lang/String;", $PUBLIC, $virtualMethod(X500Name, getRFC1779Name, $String*, $Map*), "java.lang.IllegalArgumentException"},
	{"getRFC2253CanonicalName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(X500Name, getRFC2253CanonicalName, $String*)},
	{"getRFC2253Name", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(X500Name, getRFC2253Name, $String*)},
	{"getRFC2253Name", "(Ljava/util/Map;)Ljava/lang/String;", "(Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;)Ljava/lang/String;", $PUBLIC, $virtualMethod(X500Name, getRFC2253Name, $String*, $Map*)},
	{"getState", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(X500Name, getState, $String*), "java.io.IOException"},
	{"getString", "(Lsun/security/util/DerValue;)Ljava/lang/String;", nullptr, $PRIVATE, $method(X500Name, getString, $String*, $DerValue*), "java.io.IOException"},
	{"getSurname", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(X500Name, getSurname, $String*), "java.io.IOException"},
	{"getType", "()I", nullptr, $PUBLIC, $virtualMethod(X500Name, getType, int32_t)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(X500Name, hashCode, int32_t)},
	{"isEmpty", "()Z", nullptr, $PUBLIC, $virtualMethod(X500Name, isEmpty, bool)},
	{"isWithinSubtree", "(Lsun/security/x509/X500Name;)Z", nullptr, $PRIVATE, $method(X500Name, isWithinSubtree, bool, X500Name*)},
	{"parseDER", "(Lsun/security/util/DerInputStream;)V", nullptr, $PRIVATE, $method(X500Name, parseDER, void, $DerInputStream*), "java.io.IOException"},
	{"parseDN", "(Ljava/lang/String;Ljava/util/Map;)V", "(Ljava/lang/String;Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;)V", $PRIVATE, $method(X500Name, parseDN, void, $String*, $Map*), "java.io.IOException"},
	{"parseRFC2253DN", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(X500Name, parseRFC2253DN, void, $String*), "java.io.IOException"},
	{"rdns", "()Ljava/util/List;", "()Ljava/util/List<Lsun/security/x509/RDN;>;", $PUBLIC, $virtualMethod(X500Name, rdns, $List*)},
	{"size", "()I", nullptr, $PUBLIC, $virtualMethod(X500Name, size, int32_t)},
	{"subtreeDepth", "()I", nullptr, $PUBLIC, $virtualMethod(X500Name, subtreeDepth, int32_t), "java.lang.UnsupportedOperationException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(X500Name, toString, $String*)},
	{}
};

$InnerClassInfo _X500Name_InnerClassesInfo_[] = {
	{"sun.security.x509.X500Name$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _X500Name_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.x509.X500Name",
	"java.lang.Object",
	"sun.security.x509.GeneralNameInterface,java.security.Principal",
	_X500Name_FieldInfo_,
	_X500Name_MethodInfo_,
	nullptr,
	nullptr,
	_X500Name_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.x509.X500Name$1"
};

$Object* allocate$X500Name($Class* clazz) {
	return $of($alloc(X500Name));
}

$Object* X500Name::clone() {
	 return this->$GeneralNameInterface::clone();
}

void X500Name::finalize() {
	this->$GeneralNameInterface::finalize();
}

$ObjectIdentifier* X500Name::commonName_oid = nullptr;
$ObjectIdentifier* X500Name::SURNAME_OID = nullptr;
$ObjectIdentifier* X500Name::SERIALNUMBER_OID = nullptr;
$ObjectIdentifier* X500Name::countryName_oid = nullptr;
$ObjectIdentifier* X500Name::localityName_oid = nullptr;
$ObjectIdentifier* X500Name::stateName_oid = nullptr;
$ObjectIdentifier* X500Name::streetAddress_oid = nullptr;
$ObjectIdentifier* X500Name::orgName_oid = nullptr;
$ObjectIdentifier* X500Name::orgUnitName_oid = nullptr;
$ObjectIdentifier* X500Name::title_oid = nullptr;
$ObjectIdentifier* X500Name::GIVENNAME_OID = nullptr;
$ObjectIdentifier* X500Name::INITIALS_OID = nullptr;
$ObjectIdentifier* X500Name::GENERATIONQUALIFIER_OID = nullptr;
$ObjectIdentifier* X500Name::DNQUALIFIER_OID = nullptr;
$ObjectIdentifier* X500Name::ipAddress_oid = nullptr;
$ObjectIdentifier* X500Name::DOMAIN_COMPONENT_OID = nullptr;
$ObjectIdentifier* X500Name::userid_oid = nullptr;
$Constructor* X500Name::principalConstructor = nullptr;
$Field* X500Name::principalField = nullptr;

void X500Name::init$($String* dname) {
	X500Name::init$(dname, $($Collections::emptyMap()));
}

void X500Name::init$($String* dname, $Map* keywordMap) {
	parseDN(dname, keywordMap);
}

void X500Name::init$($String* dname, $String* format) {
	$useLocalCurrentObjectStackCache();
	if (dname == nullptr) {
		$throwNew($NullPointerException, "Name must not be null"_s);
	}
	if ($nc(format)->equalsIgnoreCase("RFC2253"_s)) {
		parseRFC2253DN(dname);
	} else if (format->equalsIgnoreCase("DEFAULT"_s)) {
		parseDN(dname, $($Collections::emptyMap()));
	} else {
		$throwNew($IOException, $$str({"Unsupported format "_s, format}));
	}
}

void X500Name::init$($String* commonName, $String* organizationUnit, $String* organizationName, $String* country) {
	$useLocalCurrentObjectStackCache();
	$set(this, names, $new($RDNArray, 4));
	$nc(this->names)->set(3, $$new($RDN, 1));
	$nc($nc($nc(this->names)->get(3))->assertion)->set(0, $$new($AVA, X500Name::commonName_oid, $$new($DerValue, commonName)));
	$nc(this->names)->set(2, $$new($RDN, 1));
	$nc($nc($nc(this->names)->get(2))->assertion)->set(0, $$new($AVA, X500Name::orgUnitName_oid, $$new($DerValue, organizationUnit)));
	$nc(this->names)->set(1, $$new($RDN, 1));
	$nc($nc($nc(this->names)->get(1))->assertion)->set(0, $$new($AVA, X500Name::orgName_oid, $$new($DerValue, organizationName)));
	$nc(this->names)->set(0, $$new($RDN, 1));
	$nc($nc($nc(this->names)->get(0))->assertion)->set(0, $$new($AVA, X500Name::countryName_oid, $$new($DerValue, country)));
}

void X500Name::init$($String* commonName, $String* organizationUnit, $String* organizationName, $String* localityName, $String* stateName, $String* country) {
	$useLocalCurrentObjectStackCache();
	$set(this, names, $new($RDNArray, 6));
	$nc(this->names)->set(5, $$new($RDN, 1));
	$nc($nc($nc(this->names)->get(5))->assertion)->set(0, $$new($AVA, X500Name::commonName_oid, $$new($DerValue, commonName)));
	$nc(this->names)->set(4, $$new($RDN, 1));
	$nc($nc($nc(this->names)->get(4))->assertion)->set(0, $$new($AVA, X500Name::orgUnitName_oid, $$new($DerValue, organizationUnit)));
	$nc(this->names)->set(3, $$new($RDN, 1));
	$nc($nc($nc(this->names)->get(3))->assertion)->set(0, $$new($AVA, X500Name::orgName_oid, $$new($DerValue, organizationName)));
	$nc(this->names)->set(2, $$new($RDN, 1));
	$nc($nc($nc(this->names)->get(2))->assertion)->set(0, $$new($AVA, X500Name::localityName_oid, $$new($DerValue, localityName)));
	$nc(this->names)->set(1, $$new($RDN, 1));
	$nc($nc($nc(this->names)->get(1))->assertion)->set(0, $$new($AVA, X500Name::stateName_oid, $$new($DerValue, stateName)));
	$nc(this->names)->set(0, $$new($RDN, 1));
	$nc($nc($nc(this->names)->get(0))->assertion)->set(0, $$new($AVA, X500Name::countryName_oid, $$new($DerValue, country)));
}

void X500Name::init$($RDNArray* rdnArray) {
	if (rdnArray == nullptr) {
		$set(this, names, $new($RDNArray, 0));
	} else {
		$set(this, names, $cast($RDNArray, $nc(rdnArray)->clone()));
		for (int32_t i = 0; i < $nc(this->names)->length; ++i) {
			if ($nc(this->names)->get(i) == nullptr) {
				$throwNew($IOException, "Cannot create an X500Name"_s);
			}
		}
	}
}

void X500Name::init$($DerValue* value) {
	X500Name::init$($($nc(value)->toDerInputStream()));
}

void X500Name::init$($DerInputStream* in) {
	parseDER(in);
}

void X500Name::init$($bytes* name) {
	$var($DerInputStream, in, $new($DerInputStream, name));
	parseDER(in);
}

$List* X500Name::rdns() {
	$useLocalCurrentObjectStackCache();
	$var($List, list, this->rdnList);
	if (list == nullptr) {
		$assign(list, $Collections::unmodifiableList($($Arrays::asList(this->names))));
		$set(this, rdnList, list);
	}
	return list;
}

int32_t X500Name::size() {
	return $nc(this->names)->length;
}

$List* X500Name::allAvas() {
	$useLocalCurrentObjectStackCache();
	$var($List, list, this->allAvaList);
	if (list == nullptr) {
		$assign(list, $new($ArrayList));
		for (int32_t i = 0; i < $nc(this->names)->length; ++i) {
			list->addAll($($nc($nc(this->names)->get(i))->avas()));
		}
		$assign(list, $Collections::unmodifiableList(list));
		$set(this, allAvaList, list);
	}
	return list;
}

int32_t X500Name::avaSize() {
	return $nc($(allAvas()))->size();
}

bool X500Name::isEmpty() {
	int32_t n = $nc(this->names)->length;
	for (int32_t i = 0; i < n; ++i) {
		if ($nc($nc($nc(this->names)->get(i))->assertion)->length != 0) {
			return false;
		}
	}
	return true;
}

int32_t X500Name::hashCode() {
	return $nc($(getRFC2253CanonicalName()))->hashCode();
}

bool X500Name::equals(Object$* obj) {
	$useLocalCurrentObjectStackCache();
	if ($equals(this, obj)) {
		return true;
	}
	if ($instanceOf(X500Name, obj) == false) {
		return false;
	}
	$var(X500Name, other, $cast(X500Name, obj));
	if ((this->canonicalDn != nullptr) && ($nc(other)->canonicalDn != nullptr)) {
		return $nc(this->canonicalDn)->equals(other->canonicalDn);
	}
	int32_t n = $nc(this->names)->length;
	if (n != $nc($nc(other)->names)->length) {
		return false;
	}
	for (int32_t i = 0; i < n; ++i) {
		$var($RDN, r1, $nc(this->names)->get(i));
		$var($RDN, r2, $nc($nc(other)->names)->get(i));
		if ($nc($nc(r1)->assertion)->length != $nc($nc(r2)->assertion)->length) {
			return false;
		}
	}
	$var($String, thisCanonical, this->getRFC2253CanonicalName());
	$var($String, otherCanonical, $nc(other)->getRFC2253CanonicalName());
	return $nc(thisCanonical)->equals(otherCanonical);
}

$String* X500Name::getString($DerValue* attribute) {
	$useLocalCurrentObjectStackCache();
	if (attribute == nullptr) {
		return nullptr;
	}
	$var($String, value, $nc(attribute)->getAsString());
	if (value == nullptr) {
		$throwNew($IOException, $$str({"not a DER string encoding, "_s, $$str(attribute->tag)}));
	} else {
		return value;
	}
}

int32_t X500Name::getType() {
	return ($GeneralNameInterface::NAME_DIRECTORY);
}

$String* X500Name::getCountry() {
	$var($DerValue, attr, findAttribute(X500Name::countryName_oid));
	return getString(attr);
}

$String* X500Name::getOrganization() {
	$var($DerValue, attr, findAttribute(X500Name::orgName_oid));
	return getString(attr);
}

$String* X500Name::getOrganizationalUnit() {
	$var($DerValue, attr, findAttribute(X500Name::orgUnitName_oid));
	return getString(attr);
}

$String* X500Name::getCommonName() {
	$var($DerValue, attr, findAttribute(X500Name::commonName_oid));
	return getString(attr);
}

$String* X500Name::getLocality() {
	$var($DerValue, attr, findAttribute(X500Name::localityName_oid));
	return getString(attr);
}

$String* X500Name::getState() {
	$var($DerValue, attr, findAttribute(X500Name::stateName_oid));
	return getString(attr);
}

$String* X500Name::getDomain() {
	$var($DerValue, attr, findAttribute(X500Name::DOMAIN_COMPONENT_OID));
	return getString(attr);
}

$String* X500Name::getDNQualifier() {
	$var($DerValue, attr, findAttribute(X500Name::DNQUALIFIER_OID));
	return getString(attr);
}

$String* X500Name::getSurname() {
	$var($DerValue, attr, findAttribute(X500Name::SURNAME_OID));
	return getString(attr);
}

$String* X500Name::getGivenName() {
	$var($DerValue, attr, findAttribute(X500Name::GIVENNAME_OID));
	return getString(attr);
}

$String* X500Name::getInitials() {
	$var($DerValue, attr, findAttribute(X500Name::INITIALS_OID));
	return getString(attr);
}

$String* X500Name::getGeneration() {
	$var($DerValue, attr, findAttribute(X500Name::GENERATIONQUALIFIER_OID));
	return getString(attr);
}

$String* X500Name::getIP() {
	$var($DerValue, attr, findAttribute(X500Name::ipAddress_oid));
	return getString(attr);
}

$String* X500Name::toString() {
	if (this->dn == nullptr) {
		generateDN();
	}
	return this->dn;
}

$String* X500Name::getRFC1779Name() {
	return getRFC1779Name($($Collections::emptyMap()));
}

$String* X500Name::getRFC1779Name($Map* oidMap) {
	if ($nc(oidMap)->isEmpty()) {
		if (this->rfc1779Dn != nullptr) {
			return this->rfc1779Dn;
		} else {
			$set(this, rfc1779Dn, generateRFC1779DN(oidMap));
			return this->rfc1779Dn;
		}
	}
	return generateRFC1779DN(oidMap);
}

$String* X500Name::getRFC2253Name() {
	return getRFC2253Name($($Collections::emptyMap()));
}

$String* X500Name::getRFC2253Name($Map* oidMap) {
	if ($nc(oidMap)->isEmpty()) {
		if (this->rfc2253Dn != nullptr) {
			return this->rfc2253Dn;
		} else {
			$set(this, rfc2253Dn, generateRFC2253DN(oidMap));
			return this->rfc2253Dn;
		}
	}
	return generateRFC2253DN(oidMap);
}

$String* X500Name::generateRFC2253DN($Map* oidMap) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->names)->length == 0) {
		return ""_s;
	}
	$var($StringJoiner, sj, $new($StringJoiner, ","_s));
	for (int32_t i = $nc(this->names)->length - 1; i >= 0; --i) {
		sj->add($($nc($nc(this->names)->get(i))->toRFC2253String(oidMap)));
	}
	return sj->toString();
}

$String* X500Name::getRFC2253CanonicalName() {
	$useLocalCurrentObjectStackCache();
	if (this->canonicalDn != nullptr) {
		return this->canonicalDn;
	}
	if ($nc(this->names)->length == 0) {
		$set(this, canonicalDn, ""_s);
		return this->canonicalDn;
	}
	$var($StringJoiner, sj, $new($StringJoiner, ","_s));
	for (int32_t i = $nc(this->names)->length - 1; i >= 0; --i) {
		sj->add($($nc($nc(this->names)->get(i))->toRFC2253String(true)));
	}
	$set(this, canonicalDn, sj->toString());
	return this->canonicalDn;
}

$String* X500Name::getName() {
	return toString();
}

$DerValue* X500Name::findAttribute($ObjectIdentifier* attribute) {
	$useLocalCurrentObjectStackCache();
	if (this->names != nullptr) {
		for (int32_t i = 0; i < $nc(this->names)->length; ++i) {
			$var($DerValue, value, $nc($nc(this->names)->get(i))->findAttribute(attribute));
			if (value != nullptr) {
				return value;
			}
		}
	}
	return nullptr;
}

$DerValue* X500Name::findMostSpecificAttribute($ObjectIdentifier* attribute) {
	$useLocalCurrentObjectStackCache();
	if (this->names != nullptr) {
		for (int32_t i = $nc(this->names)->length - 1; i >= 0; --i) {
			$var($DerValue, value, $nc($nc(this->names)->get(i))->findAttribute(attribute));
			if (value != nullptr) {
				return value;
			}
		}
	}
	return nullptr;
}

void X500Name::parseDER($DerInputStream* in) {
	$useLocalCurrentObjectStackCache();
	$var($DerValueArray, nameseq, nullptr);
	$var($bytes, derBytes, $nc(in)->toByteArray());
	try {
		$assign(nameseq, in->getSequence(5));
	} catch ($IOException& ioe) {
		if (derBytes == nullptr) {
			$assign(nameseq, nullptr);
		} else {
			$var($DerValue, derVal, $new($DerValue, $DerValue::tag_Sequence, derBytes));
			$assign(derBytes, derVal->toByteArray());
			$assign(nameseq, $$new($DerInputStream, derBytes)->getSequence(5));
		}
	}
	if (nameseq == nullptr) {
		$set(this, names, $new($RDNArray, 0));
	} else {
		$set(this, names, $new($RDNArray, $nc(nameseq)->length));
		for (int32_t i = 0; i < nameseq->length; ++i) {
			$nc(this->names)->set(i, $$new($RDN, nameseq->get(i)));
		}
	}
}

void X500Name::emit($DerOutputStream* out) {
	encode(out);
}

void X500Name::encode($DerOutputStream* out) {
	$var($DerOutputStream, tmp, $new($DerOutputStream));
	for (int32_t i = 0; i < $nc(this->names)->length; ++i) {
		$nc($nc(this->names)->get(i))->encode(tmp);
	}
	$nc(out)->write($DerValue::tag_Sequence, tmp);
}

$bytes* X500Name::getEncodedInternal() {
	$useLocalCurrentObjectStackCache();
	if (this->encoded == nullptr) {
		$var($DerOutputStream, out, $new($DerOutputStream));
		$var($DerOutputStream, tmp, $new($DerOutputStream));
		for (int32_t i = 0; i < $nc(this->names)->length; ++i) {
			$nc($nc(this->names)->get(i))->encode(tmp);
		}
		out->write($DerValue::tag_Sequence, tmp);
		$set(this, encoded, out->toByteArray());
	}
	return this->encoded;
}

$bytes* X500Name::getEncoded() {
	return $cast($bytes, $nc($(getEncodedInternal()))->clone());
}

void X500Name::parseDN($String* input, $Map* keywordMap) {
	$useLocalCurrentObjectStackCache();
	if (input == nullptr || $nc(input)->isEmpty()) {
		$set(this, names, $new($RDNArray, 0));
		return;
	}
	$var($List, dnVector, $new($ArrayList));
	int32_t dnOffset = 0;
	int32_t rdnEnd = 0;
	$var($String, rdnString, nullptr);
	int32_t quoteCount = 0;
	$var($String, dnString, input);
	int32_t searchOffset = 0;
	int32_t nextComma = $nc(dnString)->indexOf((int32_t)u',');
	int32_t nextSemiColon = dnString->indexOf((int32_t)u';');
	while (nextComma >= 0 || nextSemiColon >= 0) {
		if (nextSemiColon < 0) {
			rdnEnd = nextComma;
		} else if (nextComma < 0) {
			rdnEnd = nextSemiColon;
		} else {
			rdnEnd = $Math::min(nextComma, nextSemiColon);
		}
		quoteCount += countQuotes(dnString, searchOffset, rdnEnd);
		if (rdnEnd >= 0 && quoteCount != 1 && !escaped(rdnEnd, searchOffset, dnString)) {
			$assign(rdnString, dnString->substring(dnOffset, rdnEnd));
			$var($RDN, rdn, $new($RDN, rdnString, keywordMap));
			dnVector->add(rdn);
			dnOffset = rdnEnd + 1;
			quoteCount = 0;
		}
		searchOffset = rdnEnd + 1;
		nextComma = dnString->indexOf((int32_t)u',', searchOffset);
		nextSemiColon = dnString->indexOf((int32_t)u';', searchOffset);
	}
	$assign(rdnString, dnString->substring(dnOffset));
	$var($RDN, rdn, $new($RDN, rdnString, keywordMap));
	dnVector->add(rdn);
	$Collections::reverse(dnVector);
	$set(this, names, $fcast($RDNArray, dnVector->toArray($$new($RDNArray, dnVector->size()))));
}

void X500Name::parseRFC2253DN($String* dnString) {
	$useLocalCurrentObjectStackCache();
	if ($nc(dnString)->isEmpty()) {
		$set(this, names, $new($RDNArray, 0));
		return;
	}
	$var($List, dnVector, $new($ArrayList));
	int32_t dnOffset = 0;
	$var($String, rdnString, nullptr);
	int32_t searchOffset = 0;
	int32_t rdnEnd = $nc(dnString)->indexOf((int32_t)u',');
	while (rdnEnd >= 0) {
		if (rdnEnd > 0 && !escaped(rdnEnd, searchOffset, dnString)) {
			$assign(rdnString, dnString->substring(dnOffset, rdnEnd));
			$var($RDN, rdn, $new($RDN, rdnString, "RFC2253"_s));
			dnVector->add(rdn);
			dnOffset = rdnEnd + 1;
		}
		searchOffset = rdnEnd + 1;
		rdnEnd = dnString->indexOf((int32_t)u',', searchOffset);
	}
	$assign(rdnString, dnString->substring(dnOffset));
	$var($RDN, rdn, $new($RDN, rdnString, "RFC2253"_s));
	dnVector->add(rdn);
	$Collections::reverse(dnVector);
	$set(this, names, $fcast($RDNArray, dnVector->toArray($$new($RDNArray, dnVector->size()))));
}

int32_t X500Name::countQuotes($String* string, int32_t from, int32_t to) {
	$init(X500Name);
	int32_t count = 0;
	for (int32_t i = from; i < to; ++i) {
		bool var$0 = ($nc(string)->charAt(i) == u'\"' && i == from);
		if (!var$0) {
			bool var$1 = $nc(string)->charAt(i) == u'\"';
			var$0 = (var$1 && string->charAt(i - 1) != u'\\');
		}
		if (var$0) {
			++count;
		}
	}
	return count;
}

bool X500Name::escaped(int32_t rdnEnd, int32_t searchOffset, $String* dnString) {
	$init(X500Name);
	if (rdnEnd == 1 && $nc(dnString)->charAt(rdnEnd - 1) == u'\\') {
		return true;
	} else {
		bool var$1 = rdnEnd > 1 && dnString->charAt(rdnEnd - 1) == u'\\';
		if (var$1 && dnString->charAt(rdnEnd - 2) != u'\\') {
			return true;
		} else {
			bool var$3 = rdnEnd > 1 && dnString->charAt(rdnEnd - 1) == u'\\';
			if (var$3 && dnString->charAt(rdnEnd - 2) == u'\\') {
				int32_t count = 0;
				--rdnEnd;
				while (rdnEnd >= searchOffset) {
					if (dnString->charAt(rdnEnd) == u'\\') {
						++count;
					}
					--rdnEnd;
				}
				return (count % 2) != 0 ? true : false;
			} else {
				return false;
			}
		}
	}
}

void X500Name::generateDN() {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->names)->length == 1) {
		$set(this, dn, $nc($nc(this->names)->get(0))->toString());
		return;
	}
	if (this->names == nullptr) {
		$set(this, dn, ""_s);
		return;
	}
	$var($StringJoiner, sj, $new($StringJoiner, ", "_s));
	for (int32_t i = $nc(this->names)->length - 1; i >= 0; --i) {
		sj->add($($nc($nc(this->names)->get(i))->toString()));
	}
	$set(this, dn, sj->toString());
}

$String* X500Name::generateRFC1779DN($Map* oidMap) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->names)->length == 1) {
		return $nc($nc(this->names)->get(0))->toRFC1779String(oidMap);
	}
	if (this->names == nullptr) {
		return ""_s;
	}
	$var($StringJoiner, sj, $new($StringJoiner, ", "_s));
	for (int32_t i = $nc(this->names)->length - 1; i >= 0; --i) {
		sj->add($($nc($nc(this->names)->get(i))->toRFC1779String(oidMap)));
	}
	return sj->toString();
}

int32_t X500Name::constrains($GeneralNameInterface* inputName) {
	int32_t constraintType = 0;
	if (inputName == nullptr) {
		constraintType = $GeneralNameInterface::NAME_DIFF_TYPE;
	} else if ($nc(inputName)->getType() != $GeneralNameInterface::NAME_DIRECTORY) {
		constraintType = $GeneralNameInterface::NAME_DIFF_TYPE;
	} else {
		$var(X500Name, inputX500, $cast(X500Name, inputName));
		if (inputX500->equals(this)) {
			constraintType = $GeneralNameInterface::NAME_MATCH;
		} else if ($nc(inputX500->names)->length == 0) {
			constraintType = $GeneralNameInterface::NAME_WIDENS;
		} else if ($nc(this->names)->length == 0) {
			constraintType = $GeneralNameInterface::NAME_NARROWS;
		} else if (inputX500->isWithinSubtree(this)) {
			constraintType = $GeneralNameInterface::NAME_NARROWS;
		} else if (isWithinSubtree(inputX500)) {
			constraintType = $GeneralNameInterface::NAME_WIDENS;
		} else {
			constraintType = $GeneralNameInterface::NAME_SAME_TYPE;
		}
	}
	return constraintType;
}

bool X500Name::isWithinSubtree(X500Name* other) {
	if (this == other) {
		return true;
	}
	if (other == nullptr) {
		return false;
	}
	if ($nc($nc(other)->names)->length == 0) {
		return true;
	}
	if ($nc(this->names)->length == 0) {
		return false;
	}
	if ($nc(this->names)->length < $nc($nc(other)->names)->length) {
		return false;
	}
	for (int32_t i = 0; i < $nc($nc(other)->names)->length; ++i) {
		if (!$nc($nc(this->names)->get(i))->equals($nc(other->names)->get(i))) {
			return false;
		}
	}
	return true;
}

int32_t X500Name::subtreeDepth() {
	return $nc(this->names)->length;
}

X500Name* X500Name::commonAncestor(X500Name* other) {
	$useLocalCurrentObjectStackCache();
	if (other == nullptr) {
		return nullptr;
	}
	int32_t otherLen = $nc($nc(other)->names)->length;
	int32_t thisLen = $nc(this->names)->length;
	if (thisLen == 0 || otherLen == 0) {
		return nullptr;
	}
	int32_t minLen = (thisLen < otherLen) ? thisLen : otherLen;
	int32_t i = 0;
	for (; i < minLen; ++i) {
		if (!$nc($nc(this->names)->get(i))->equals($nc(other->names)->get(i))) {
			if (i == 0) {
				return nullptr;
			} else {
				break;
			}
		}
	}
	$var($RDNArray, ancestor, $new($RDNArray, i));
	for (int32_t j = 0; j < i; ++j) {
		ancestor->set(j, $nc(this->names)->get(j));
	}
	$var(X500Name, commonAncestor, nullptr);
	try {
		$assign(commonAncestor, $new(X500Name, ancestor));
	} catch ($IOException& ioe) {
		return nullptr;
	}
	return commonAncestor;
}

$X500Principal* X500Name::asX500Principal() {
	$beforeCallerSensitive();
	if (this->x500Principal == nullptr) {
		try {
			$var($ObjectArray, args, $new($ObjectArray, {$of(this)}));
			$set(this, x500Principal, $cast($X500Principal, $nc(X500Name::principalConstructor)->newInstance(args)));
		} catch ($Exception& e) {
			$throwNew($RuntimeException, "Unexpected exception"_s, e);
		}
	}
	return this->x500Principal;
}

X500Name* X500Name::asX500Name($X500Principal* p) {
	$init(X500Name);
	$beforeCallerSensitive();
	try {
		$var(X500Name, name, $cast(X500Name, $nc(X500Name::principalField)->get(p)));
		$set($nc(name), x500Principal, p);
		return name;
	} catch ($Exception& e) {
		$throwNew($RuntimeException, "Unexpected exception"_s, e);
	}
	$shouldNotReachHere();
}

void clinit$X500Name($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$init($KnownOIDs);
	$assignStatic(X500Name::commonName_oid, $ObjectIdentifier::of($KnownOIDs::CommonName));
	$assignStatic(X500Name::SURNAME_OID, $ObjectIdentifier::of($KnownOIDs::Surname));
	$assignStatic(X500Name::SERIALNUMBER_OID, $ObjectIdentifier::of($KnownOIDs::SerialNumber));
	$assignStatic(X500Name::countryName_oid, $ObjectIdentifier::of($KnownOIDs::CountryName));
	$assignStatic(X500Name::localityName_oid, $ObjectIdentifier::of($KnownOIDs::LocalityName));
	$assignStatic(X500Name::stateName_oid, $ObjectIdentifier::of($KnownOIDs::StateName));
	$assignStatic(X500Name::streetAddress_oid, $ObjectIdentifier::of($KnownOIDs::StreetAddress));
	$assignStatic(X500Name::orgName_oid, $ObjectIdentifier::of($KnownOIDs::OrgName));
	$assignStatic(X500Name::orgUnitName_oid, $ObjectIdentifier::of($KnownOIDs::OrgUnitName));
	$assignStatic(X500Name::title_oid, $ObjectIdentifier::of($KnownOIDs::Title));
	$assignStatic(X500Name::GIVENNAME_OID, $ObjectIdentifier::of($KnownOIDs::GivenName));
	$assignStatic(X500Name::INITIALS_OID, $ObjectIdentifier::of($KnownOIDs::Initials));
	$assignStatic(X500Name::GENERATIONQUALIFIER_OID, $ObjectIdentifier::of($KnownOIDs::GenerationQualifier));
	$assignStatic(X500Name::DNQUALIFIER_OID, $ObjectIdentifier::of($KnownOIDs::DNQualifier));
	$assignStatic(X500Name::ipAddress_oid, $ObjectIdentifier::of($KnownOIDs::SkipIPAddress));
	$assignStatic(X500Name::DOMAIN_COMPONENT_OID, $ObjectIdentifier::of($KnownOIDs::UCL_DomainComponent));
	$assignStatic(X500Name::userid_oid, $ObjectIdentifier::of($KnownOIDs::UCL_UserID));
	{
		$var($PrivilegedExceptionAction, pa, $new($X500Name$1));
		try {
			$var($ObjectArray, result, $cast($ObjectArray, $AccessController::doPrivileged(pa)));
			$var($Constructor, constr, $cast($Constructor, $nc(result)->get(0)));
			$assignStatic(X500Name::principalConstructor, constr);
			$assignStatic(X500Name::principalField, $cast($Field, result->get(1)));
		} catch ($Exception& e) {
			$throwNew($InternalError, "Could not obtain X500Principal access"_s, e);
		}
	}
}

X500Name::X500Name() {
}

$Class* X500Name::load$($String* name, bool initialize) {
	$loadClass(X500Name, name, initialize, &_X500Name_ClassInfo_, clinit$X500Name, allocate$X500Name);
	return class$;
}

$Class* X500Name::class$ = nullptr;

		} // x509
	} // security
} // sun