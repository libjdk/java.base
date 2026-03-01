#include <sun/security/x509/CertificatePoliciesExtension.h>

#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <java/util/ArrayList.h>
#include <java/util/Enumeration.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <sun/security/x509/AttributeNameEnumeration.h>
#include <sun/security/x509/Extension.h>
#include <sun/security/x509/PKIXExtensions.h>
#include <sun/security/x509/PolicyInformation.h>
#include <jcpp.h>

#undef FALSE
#undef IDENT
#undef NAME
#undef POLICIES

using $IOException = ::java::io::IOException;
using $OutputStream = ::java::io::OutputStream;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ArrayList = ::java::util::ArrayList;
using $Enumeration = ::java::util::Enumeration;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;
using $AttributeNameEnumeration = ::sun::security::x509::AttributeNameEnumeration;
using $Extension = ::sun::security::x509::Extension;
using $PKIXExtensions = ::sun::security::x509::PKIXExtensions;
using $PolicyInformation = ::sun::security::x509::PolicyInformation;

namespace sun {
	namespace security {
		namespace x509 {

$FieldInfo _CertificatePoliciesExtension_FieldInfo_[] = {
	{"IDENT", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(CertificatePoliciesExtension, IDENT)},
	{"NAME", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(CertificatePoliciesExtension, NAME)},
	{"POLICIES", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(CertificatePoliciesExtension, POLICIES)},
	{"certPolicies", "Ljava/util/List;", "Ljava/util/List<Lsun/security/x509/PolicyInformation;>;", $PRIVATE, $field(CertificatePoliciesExtension, certPolicies)},
	{}
};

$MethodInfo _CertificatePoliciesExtension_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC},
	{"<init>", "(Ljava/util/List;)V", "(Ljava/util/List<Lsun/security/x509/PolicyInformation;>;)V", $PUBLIC, $method(CertificatePoliciesExtension, init$, void, $List*), "java.io.IOException"},
	{"<init>", "(Ljava/lang/Boolean;Ljava/util/List;)V", "(Ljava/lang/Boolean;Ljava/util/List<Lsun/security/x509/PolicyInformation;>;)V", $PUBLIC, $method(CertificatePoliciesExtension, init$, void, $Boolean*, $List*), "java.io.IOException"},
	{"<init>", "(Ljava/lang/Boolean;Ljava/lang/Object;)V", nullptr, $PUBLIC, $method(CertificatePoliciesExtension, init$, void, $Boolean*, Object$*), "java.io.IOException"},
	{"delete", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(CertificatePoliciesExtension, delete$, void, $String*), "java.io.IOException"},
	{"encode", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC, $virtualMethod(CertificatePoliciesExtension, encode, void, $OutputStream*), "java.io.IOException"},
	{"encodeThis", "()V", nullptr, $PRIVATE, $method(CertificatePoliciesExtension, encodeThis, void), "java.io.IOException"},
	{"get", "(Ljava/lang/String;)Ljava/util/List;", "(Ljava/lang/String;)Ljava/util/List<Lsun/security/x509/PolicyInformation;>;", $PUBLIC, $virtualMethod(CertificatePoliciesExtension, get, $Object*, $String*), "java.io.IOException"},
	{"getElements", "()Ljava/util/Enumeration;", "()Ljava/util/Enumeration<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(CertificatePoliciesExtension, getElements, $Enumeration*)},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(CertificatePoliciesExtension, getName, $String*)},
	{"set", "(Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(CertificatePoliciesExtension, set, void, $String*, Object$*), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(CertificatePoliciesExtension, toString, $String*)},
	{}
};

$ClassInfo _CertificatePoliciesExtension_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.x509.CertificatePoliciesExtension",
	"sun.security.x509.Extension",
	"sun.security.x509.CertAttrSet",
	_CertificatePoliciesExtension_FieldInfo_,
	_CertificatePoliciesExtension_MethodInfo_,
	"Lsun/security/x509/Extension;Lsun/security/x509/CertAttrSet<Ljava/lang/String;>;"
};

$Object* allocate$CertificatePoliciesExtension($Class* clazz) {
	return $of($alloc(CertificatePoliciesExtension));
}

int32_t CertificatePoliciesExtension::hashCode() {
	 return this->$Extension::hashCode();
}

bool CertificatePoliciesExtension::equals(Object$* other) {
	 return this->$Extension::equals(other);
}

$Object* CertificatePoliciesExtension::clone() {
	 return this->$Extension::clone();
}

void CertificatePoliciesExtension::finalize() {
	this->$Extension::finalize();
}

$String* CertificatePoliciesExtension::IDENT = nullptr;
$String* CertificatePoliciesExtension::NAME = nullptr;
$String* CertificatePoliciesExtension::POLICIES = nullptr;

void CertificatePoliciesExtension::encodeThis() {
	$useLocalCurrentObjectStackCache();
	if (this->certPolicies == nullptr || $nc(this->certPolicies)->isEmpty()) {
		$set(this, extensionValue, nullptr);
	} else {
		$var($DerOutputStream, os, $new($DerOutputStream));
		$var($DerOutputStream, tmp, $new($DerOutputStream));
		{
			$var($Iterator, i$, $nc(this->certPolicies)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($PolicyInformation, info, $cast($PolicyInformation, i$->next()));
				{
					$nc(info)->encode(tmp);
				}
			}
		}
		os->write($DerValue::tag_Sequence, tmp);
		$set(this, extensionValue, os->toByteArray());
	}
}

void CertificatePoliciesExtension::init$($List* certPolicies) {
	$init($Boolean);
	CertificatePoliciesExtension::init$($Boolean::FALSE, certPolicies);
}

void CertificatePoliciesExtension::init$($Boolean* critical, $List* certPolicies) {
	$Extension::init$();
	$set(this, certPolicies, certPolicies);
	$init($PKIXExtensions);
	$set(this, extensionId, $PKIXExtensions::CertificatePolicies_Id);
	this->critical = $nc(critical)->booleanValue();
	encodeThis();
}

void CertificatePoliciesExtension::init$($Boolean* critical, Object$* value) {
	$useLocalCurrentObjectStackCache();
	$Extension::init$();
	$init($PKIXExtensions);
	$set(this, extensionId, $PKIXExtensions::CertificatePolicies_Id);
	this->critical = $nc(critical)->booleanValue();
	$set(this, extensionValue, $cast($bytes, value));
	$var($DerValue, val, $new($DerValue, this->extensionValue));
	if (val->tag != $DerValue::tag_Sequence) {
		$throwNew($IOException, "Invalid encoding for CertificatePoliciesExtension."_s);
	}
	$set(this, certPolicies, $new($ArrayList));
	while ($nc(val->data$)->available() != 0) {
		$var($DerValue, seq, $nc(val->data$)->getDerValue());
		$var($PolicyInformation, policy, $new($PolicyInformation, seq));
		$nc(this->certPolicies)->add(policy);
	}
}

$String* CertificatePoliciesExtension::toString() {
	$useLocalCurrentObjectStackCache();
	if (this->certPolicies == nullptr) {
		return ""_s;
	}
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append($($Extension::toString()))->append("CertificatePolicies [\n"_s);
	{
		$var($Iterator, i$, $nc(this->certPolicies)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($PolicyInformation, info, $cast($PolicyInformation, i$->next()));
			{
				sb->append($of(info));
			}
		}
	}
	sb->append("]\n"_s);
	return sb->toString();
}

void CertificatePoliciesExtension::encode($OutputStream* out) {
	$useLocalCurrentObjectStackCache();
	$var($DerOutputStream, tmp, $new($DerOutputStream));
	if (this->extensionValue == nullptr) {
		$init($PKIXExtensions);
		$set(this, extensionId, $PKIXExtensions::CertificatePolicies_Id);
		this->critical = false;
		encodeThis();
	}
	$Extension::encode(tmp);
	$nc(out)->write($(tmp->toByteArray()));
}

void CertificatePoliciesExtension::set($String* name, Object$* obj) {
	if ($nc(name)->equalsIgnoreCase(CertificatePoliciesExtension::POLICIES)) {
		if (!($instanceOf($List, obj))) {
			$throwNew($IOException, "Attribute value should be of type List."_s);
		}
		$set(this, certPolicies, $cast($List, obj));
	} else {
		$throwNew($IOException, $$str({"Attribute name ["_s, name, "] not recognized by CertAttrSet:CertificatePoliciesExtension."_s}));
	}
	encodeThis();
}

$Object* CertificatePoliciesExtension::get($String* name) {
	if ($nc(name)->equalsIgnoreCase(CertificatePoliciesExtension::POLICIES)) {
		return $of(this->certPolicies);
	} else {
		$throwNew($IOException, $$str({"Attribute name ["_s, name, "] not recognized by CertAttrSet:CertificatePoliciesExtension."_s}));
	}
}

void CertificatePoliciesExtension::delete$($String* name) {
	if ($nc(name)->equalsIgnoreCase(CertificatePoliciesExtension::POLICIES)) {
		$set(this, certPolicies, nullptr);
	} else {
		$throwNew($IOException, $$str({"Attribute name ["_s, name, "] not recognized by CertAttrSet:CertificatePoliciesExtension."_s}));
	}
	encodeThis();
}

$Enumeration* CertificatePoliciesExtension::getElements() {
	$var($AttributeNameEnumeration, elements, $new($AttributeNameEnumeration));
	elements->addElement(CertificatePoliciesExtension::POLICIES);
	return (elements->elements());
}

$String* CertificatePoliciesExtension::getName() {
	return (CertificatePoliciesExtension::NAME);
}

CertificatePoliciesExtension::CertificatePoliciesExtension() {
}

void clinit$CertificatePoliciesExtension($Class* class$) {
	$assignStatic(CertificatePoliciesExtension::IDENT, "x509.info.extensions.CertificatePolicies"_s);
	$assignStatic(CertificatePoliciesExtension::NAME, "CertificatePolicies"_s);
	$assignStatic(CertificatePoliciesExtension::POLICIES, "policies"_s);
}

$Class* CertificatePoliciesExtension::load$($String* name, bool initialize) {
	$loadClass(CertificatePoliciesExtension, name, initialize, &_CertificatePoliciesExtension_ClassInfo_, clinit$CertificatePoliciesExtension, allocate$CertificatePoliciesExtension);
	return class$;
}

$Class* CertificatePoliciesExtension::class$ = nullptr;

		} // x509
	} // security
} // sun