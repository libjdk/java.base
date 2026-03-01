#include <sun/security/x509/PolicyInformation.h>

#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <java/security/cert/PolicyQualifierInfo.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Enumeration.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedHashSet.h>
#include <java/util/Set.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/x509/AttributeNameEnumeration.h>
#include <sun/security/x509/CertificatePolicyId.h>
#include <jcpp.h>

#undef ID
#undef NAME
#undef QUALIFIERS

using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $PolicyQualifierInfo = ::java::security::cert::PolicyQualifierInfo;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Enumeration = ::java::util::Enumeration;
using $Iterator = ::java::util::Iterator;
using $LinkedHashSet = ::java::util::LinkedHashSet;
using $Set = ::java::util::Set;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;
using $AttributeNameEnumeration = ::sun::security::x509::AttributeNameEnumeration;
using $CertificatePolicyId = ::sun::security::x509::CertificatePolicyId;

namespace sun {
	namespace security {
		namespace x509 {

$FieldInfo _PolicyInformation_FieldInfo_[] = {
	{"NAME", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(PolicyInformation, NAME)},
	{"ID", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(PolicyInformation, ID)},
	{"QUALIFIERS", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(PolicyInformation, QUALIFIERS)},
	{"policyIdentifier", "Lsun/security/x509/CertificatePolicyId;", nullptr, $PRIVATE, $field(PolicyInformation, policyIdentifier)},
	{"policyQualifiers", "Ljava/util/Set;", "Ljava/util/Set<Ljava/security/cert/PolicyQualifierInfo;>;", $PRIVATE, $field(PolicyInformation, policyQualifiers)},
	{}
};

$MethodInfo _PolicyInformation_MethodInfo_[] = {
	{"<init>", "(Lsun/security/x509/CertificatePolicyId;Ljava/util/Set;)V", "(Lsun/security/x509/CertificatePolicyId;Ljava/util/Set<Ljava/security/cert/PolicyQualifierInfo;>;)V", $PUBLIC, $method(PolicyInformation, init$, void, $CertificatePolicyId*, $Set*), "java.io.IOException"},
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(PolicyInformation, init$, void, $DerValue*), "java.io.IOException"},
	{"delete", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(PolicyInformation, delete$, void, $String*), "java.io.IOException"},
	{"encode", "(Lsun/security/util/DerOutputStream;)V", nullptr, $PUBLIC, $virtualMethod(PolicyInformation, encode, void, $DerOutputStream*), "java.io.IOException"},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(PolicyInformation, equals, bool, Object$*)},
	{"get", "(Ljava/lang/String;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(PolicyInformation, get, $Object*, $String*), "java.io.IOException"},
	{"getElements", "()Ljava/util/Enumeration;", "()Ljava/util/Enumeration<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(PolicyInformation, getElements, $Enumeration*)},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(PolicyInformation, getName, $String*)},
	{"getPolicyIdentifier", "()Lsun/security/x509/CertificatePolicyId;", nullptr, $PUBLIC, $virtualMethod(PolicyInformation, getPolicyIdentifier, $CertificatePolicyId*)},
	{"getPolicyQualifiers", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/security/cert/PolicyQualifierInfo;>;", $PUBLIC, $virtualMethod(PolicyInformation, getPolicyQualifiers, $Set*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(PolicyInformation, hashCode, int32_t)},
	{"set", "(Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(PolicyInformation, set, void, $String*, Object$*), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(PolicyInformation, toString, $String*)},
	{}
};

$ClassInfo _PolicyInformation_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.x509.PolicyInformation",
	"java.lang.Object",
	nullptr,
	_PolicyInformation_FieldInfo_,
	_PolicyInformation_MethodInfo_
};

$Object* allocate$PolicyInformation($Class* clazz) {
	return $of($alloc(PolicyInformation));
}

$String* PolicyInformation::NAME = nullptr;
$String* PolicyInformation::ID = nullptr;
$String* PolicyInformation::QUALIFIERS = nullptr;

void PolicyInformation::init$($CertificatePolicyId* policyIdentifier, $Set* policyQualifiers) {
	if (policyQualifiers == nullptr) {
		$throwNew($NullPointerException, "policyQualifiers is null"_s);
	}
	$set(this, policyQualifiers, $new($LinkedHashSet, static_cast<$Collection*>(policyQualifiers)));
	$set(this, policyIdentifier, policyIdentifier);
}

void PolicyInformation::init$($DerValue* val) {
	$useLocalCurrentObjectStackCache();
	if ($nc(val)->tag != $DerValue::tag_Sequence) {
		$throwNew($IOException, "Invalid encoding of PolicyInformation"_s);
	}
	$set(this, policyIdentifier, $new($CertificatePolicyId, $($nc($nc(val)->data$)->getDerValue())));
	if ($nc($nc(val)->data$)->available() != 0) {
		$set(this, policyQualifiers, $new($LinkedHashSet));
		$var($DerValue, opt, $nc(val->data$)->getDerValue());
		if ($nc(opt)->tag != $DerValue::tag_Sequence) {
			$throwNew($IOException, "Invalid encoding of PolicyInformation"_s);
		}
		if ($nc($nc(opt)->data$)->available() == 0) {
			$throwNew($IOException, "No data available in policyQualifiers"_s);
		}
		while ($nc($nc(opt)->data$)->available() != 0) {
			$nc(this->policyQualifiers)->add($$new($PolicyQualifierInfo, $($nc($($nc(opt->data$)->getDerValue()))->toByteArray())));
		}
	} else {
		$set(this, policyQualifiers, $Collections::emptySet());
	}
}

bool PolicyInformation::equals(Object$* other) {
	$useLocalCurrentObjectStackCache();
	if (!($instanceOf(PolicyInformation, other))) {
		return false;
	}
	$var(PolicyInformation, piOther, $cast(PolicyInformation, other));
	if (!$nc(this->policyIdentifier)->equals($($nc(piOther)->getPolicyIdentifier()))) {
		return false;
	}
	return $nc(this->policyQualifiers)->equals($($nc(piOther)->getPolicyQualifiers()));
}

int32_t PolicyInformation::hashCode() {
	int32_t myhash = 37 + $nc(this->policyIdentifier)->hashCode();
	myhash = 37 * myhash + $nc(this->policyQualifiers)->hashCode();
	return myhash;
}

$CertificatePolicyId* PolicyInformation::getPolicyIdentifier() {
	return this->policyIdentifier;
}

$Set* PolicyInformation::getPolicyQualifiers() {
	return this->policyQualifiers;
}

$Object* PolicyInformation::get($String* name) {
	if ($nc(name)->equalsIgnoreCase(PolicyInformation::ID)) {
		return $of(this->policyIdentifier);
	} else if (name->equalsIgnoreCase(PolicyInformation::QUALIFIERS)) {
		return $of(this->policyQualifiers);
	} else {
		$throwNew($IOException, $$str({"Attribute name ["_s, name, "] not recognized by PolicyInformation."_s}));
	}
}

void PolicyInformation::set($String* name, Object$* obj) {
	$useLocalCurrentObjectStackCache();
	if ($nc(name)->equalsIgnoreCase(PolicyInformation::ID)) {
		if ($instanceOf($CertificatePolicyId, obj)) {
			$set(this, policyIdentifier, $cast($CertificatePolicyId, obj));
		} else {
			$throwNew($IOException, "Attribute value must be instance of CertificatePolicyId."_s);
		}
	} else if (name->equalsIgnoreCase(PolicyInformation::QUALIFIERS)) {
		if (this->policyIdentifier == nullptr) {
			$throwNew($IOException, "Attribute must have a CertificatePolicyIdentifier value before PolicyQualifierInfo can be set."_s);
		}
		if ($instanceOf($Set, obj)) {
			$var($Iterator, i, $nc(($cast($Set, obj)))->iterator());
			while ($nc(i)->hasNext()) {
				$var($Object, obj1, i->next());
				if (!($instanceOf($PolicyQualifierInfo, obj1))) {
					$throwNew($IOException, "Attribute value must be aSet of PolicyQualifierInfo objects."_s);
				}
			}
			$set(this, policyQualifiers, $cast($Set, obj));
		} else {
			$throwNew($IOException, "Attribute value must be of type Set."_s);
		}
	} else {
		$throwNew($IOException, $$str({"Attribute name ["_s, name, "] not recognized by PolicyInformation"_s}));
	}
}

void PolicyInformation::delete$($String* name) {
	if ($nc(name)->equalsIgnoreCase(PolicyInformation::QUALIFIERS)) {
		$set(this, policyQualifiers, $Collections::emptySet());
	} else if (name->equalsIgnoreCase(PolicyInformation::ID)) {
		$throwNew($IOException, "Attribute ID may not be deleted from PolicyInformation."_s);
	} else {
		$throwNew($IOException, $$str({"Attribute name ["_s, name, "] not recognized by PolicyInformation."_s}));
	}
}

$Enumeration* PolicyInformation::getElements() {
	$var($AttributeNameEnumeration, elements, $new($AttributeNameEnumeration));
	elements->addElement(PolicyInformation::ID);
	elements->addElement(PolicyInformation::QUALIFIERS);
	return elements->elements();
}

$String* PolicyInformation::getName() {
	return PolicyInformation::NAME;
}

$String* PolicyInformation::toString() {
	return $str({"  ["_s, this->policyIdentifier, this->policyQualifiers, "  ]\n"_s});
}

void PolicyInformation::encode($DerOutputStream* out) {
	$useLocalCurrentObjectStackCache();
	$var($DerOutputStream, tmp, $new($DerOutputStream));
	$nc(this->policyIdentifier)->encode(tmp);
	if (!$nc(this->policyQualifiers)->isEmpty()) {
		$var($DerOutputStream, tmp2, $new($DerOutputStream));
		{
			$var($Iterator, i$, $nc(this->policyQualifiers)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($PolicyQualifierInfo, pq, $cast($PolicyQualifierInfo, i$->next()));
				{
					tmp2->write($($nc(pq)->getEncoded()));
				}
			}
		}
		tmp->write($DerValue::tag_Sequence, tmp2);
	}
	$nc(out)->write($DerValue::tag_Sequence, tmp);
}

PolicyInformation::PolicyInformation() {
}

void clinit$PolicyInformation($Class* class$) {
	$assignStatic(PolicyInformation::NAME, "PolicyInformation"_s);
	$assignStatic(PolicyInformation::ID, "id"_s);
	$assignStatic(PolicyInformation::QUALIFIERS, "qualifiers"_s);
}

$Class* PolicyInformation::load$($String* name, bool initialize) {
	$loadClass(PolicyInformation, name, initialize, &_PolicyInformation_ClassInfo_, clinit$PolicyInformation, allocate$PolicyInformation);
	return class$;
}

$Class* PolicyInformation::class$ = nullptr;

		} // x509
	} // security
} // sun