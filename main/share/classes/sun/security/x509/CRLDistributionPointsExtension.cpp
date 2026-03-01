#include <sun/security/x509/CRLDistributionPointsExtension.h>

#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <java/util/ArrayList.h>
#include <java/util/Collections.h>
#include <java/util/Enumeration.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <sun/security/x509/AttributeNameEnumeration.h>
#include <sun/security/x509/DistributionPoint.h>
#include <sun/security/x509/Extension.h>
#include <sun/security/x509/PKIXExtensions.h>
#include <jcpp.h>

#undef IDENT
#undef NAME
#undef POINTS

using $IOException = ::java::io::IOException;
using $OutputStream = ::java::io::OutputStream;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ArrayList = ::java::util::ArrayList;
using $Collections = ::java::util::Collections;
using $Enumeration = ::java::util::Enumeration;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;
using $AttributeNameEnumeration = ::sun::security::x509::AttributeNameEnumeration;
using $DistributionPoint = ::sun::security::x509::DistributionPoint;
using $Extension = ::sun::security::x509::Extension;
using $PKIXExtensions = ::sun::security::x509::PKIXExtensions;

namespace sun {
	namespace security {
		namespace x509 {

$FieldInfo _CRLDistributionPointsExtension_FieldInfo_[] = {
	{"IDENT", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(CRLDistributionPointsExtension, IDENT)},
	{"NAME", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(CRLDistributionPointsExtension, NAME)},
	{"POINTS", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(CRLDistributionPointsExtension, POINTS)},
	{"distributionPoints", "Ljava/util/List;", "Ljava/util/List<Lsun/security/x509/DistributionPoint;>;", $PRIVATE, $field(CRLDistributionPointsExtension, distributionPoints)},
	{"extensionName", "Ljava/lang/String;", nullptr, $PRIVATE, $field(CRLDistributionPointsExtension, extensionName)},
	{}
};

$MethodInfo _CRLDistributionPointsExtension_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC},
	{"<init>", "(Ljava/util/List;)V", "(Ljava/util/List<Lsun/security/x509/DistributionPoint;>;)V", $PUBLIC, $method(CRLDistributionPointsExtension, init$, void, $List*), "java.io.IOException"},
	{"<init>", "(ZLjava/util/List;)V", "(ZLjava/util/List<Lsun/security/x509/DistributionPoint;>;)V", $PUBLIC, $method(CRLDistributionPointsExtension, init$, void, bool, $List*), "java.io.IOException"},
	{"<init>", "(Lsun/security/util/ObjectIdentifier;ZLjava/util/List;Ljava/lang/String;)V", "(Lsun/security/util/ObjectIdentifier;ZLjava/util/List<Lsun/security/x509/DistributionPoint;>;Ljava/lang/String;)V", $PROTECTED, $method(CRLDistributionPointsExtension, init$, void, $ObjectIdentifier*, bool, $List*, $String*), "java.io.IOException"},
	{"<init>", "(Ljava/lang/Boolean;Ljava/lang/Object;)V", nullptr, $PUBLIC, $method(CRLDistributionPointsExtension, init$, void, $Boolean*, Object$*), "java.io.IOException"},
	{"<init>", "(Lsun/security/util/ObjectIdentifier;Ljava/lang/Boolean;Ljava/lang/Object;Ljava/lang/String;)V", nullptr, $PROTECTED, $method(CRLDistributionPointsExtension, init$, void, $ObjectIdentifier*, $Boolean*, Object$*, $String*), "java.io.IOException"},
	{"delete", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(CRLDistributionPointsExtension, delete$, void, $String*), "java.io.IOException"},
	{"encode", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC, $virtualMethod(CRLDistributionPointsExtension, encode, void, $OutputStream*), "java.io.IOException"},
	{"encode", "(Ljava/io/OutputStream;Lsun/security/util/ObjectIdentifier;Z)V", nullptr, $PROTECTED, $virtualMethod(CRLDistributionPointsExtension, encode, void, $OutputStream*, $ObjectIdentifier*, bool), "java.io.IOException"},
	{"encodeThis", "()V", nullptr, $PRIVATE, $method(CRLDistributionPointsExtension, encodeThis, void), "java.io.IOException"},
	{"get", "(Ljava/lang/String;)Ljava/util/List;", "(Ljava/lang/String;)Ljava/util/List<Lsun/security/x509/DistributionPoint;>;", $PUBLIC, $virtualMethod(CRLDistributionPointsExtension, get, $Object*, $String*), "java.io.IOException"},
	{"getElements", "()Ljava/util/Enumeration;", "()Ljava/util/Enumeration<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(CRLDistributionPointsExtension, getElements, $Enumeration*)},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(CRLDistributionPointsExtension, getName, $String*)},
	{"set", "(Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(CRLDistributionPointsExtension, set, void, $String*, Object$*), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(CRLDistributionPointsExtension, toString, $String*)},
	{}
};

$ClassInfo _CRLDistributionPointsExtension_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.x509.CRLDistributionPointsExtension",
	"sun.security.x509.Extension",
	"sun.security.x509.CertAttrSet",
	_CRLDistributionPointsExtension_FieldInfo_,
	_CRLDistributionPointsExtension_MethodInfo_,
	"Lsun/security/x509/Extension;Lsun/security/x509/CertAttrSet<Ljava/lang/String;>;"
};

$Object* allocate$CRLDistributionPointsExtension($Class* clazz) {
	return $of($alloc(CRLDistributionPointsExtension));
}

int32_t CRLDistributionPointsExtension::hashCode() {
	 return this->$Extension::hashCode();
}

bool CRLDistributionPointsExtension::equals(Object$* other) {
	 return this->$Extension::equals(other);
}

$Object* CRLDistributionPointsExtension::clone() {
	 return this->$Extension::clone();
}

void CRLDistributionPointsExtension::finalize() {
	this->$Extension::finalize();
}

$String* CRLDistributionPointsExtension::IDENT = nullptr;
$String* CRLDistributionPointsExtension::NAME = nullptr;
$String* CRLDistributionPointsExtension::POINTS = nullptr;

void CRLDistributionPointsExtension::init$($List* distributionPoints) {
	CRLDistributionPointsExtension::init$(false, distributionPoints);
}

void CRLDistributionPointsExtension::init$(bool isCritical, $List* distributionPoints) {
	$init($PKIXExtensions);
	CRLDistributionPointsExtension::init$($PKIXExtensions::CRLDistributionPoints_Id, isCritical, distributionPoints, CRLDistributionPointsExtension::NAME);
}

void CRLDistributionPointsExtension::init$($ObjectIdentifier* extensionId, bool isCritical, $List* distributionPoints, $String* extensionName) {
	$Extension::init$();
	$set(this, extensionId, extensionId);
	this->critical = isCritical;
	$set(this, distributionPoints, distributionPoints);
	encodeThis();
	$set(this, extensionName, extensionName);
}

void CRLDistributionPointsExtension::init$($Boolean* critical, Object$* value) {
	$init($PKIXExtensions);
	CRLDistributionPointsExtension::init$($PKIXExtensions::CRLDistributionPoints_Id, critical, value, CRLDistributionPointsExtension::NAME);
}

void CRLDistributionPointsExtension::init$($ObjectIdentifier* extensionId, $Boolean* critical, Object$* value, $String* extensionName) {
	$useLocalCurrentObjectStackCache();
	$Extension::init$();
	$set(this, extensionId, extensionId);
	this->critical = $nc(critical)->booleanValue();
	if (!($instanceOf($bytes, value))) {
		$throwNew($IOException, "Illegal argument type"_s);
	}
	$set(this, extensionValue, $cast($bytes, value));
	$var($DerValue, val, $new($DerValue, this->extensionValue));
	if (val->tag != $DerValue::tag_Sequence) {
		$throwNew($IOException, $$str({"Invalid encoding for "_s, extensionName, " extension."_s}));
	}
	$set(this, distributionPoints, $new($ArrayList));
	while ($nc(val->data$)->available() != 0) {
		$var($DerValue, seq, $nc(val->data$)->getDerValue());
		$var($DistributionPoint, point, $new($DistributionPoint, seq));
		$nc(this->distributionPoints)->add(point);
	}
	$set(this, extensionName, extensionName);
}

$String* CRLDistributionPointsExtension::getName() {
	return this->extensionName;
}

void CRLDistributionPointsExtension::encode($OutputStream* out) {
	$init($PKIXExtensions);
	encode(out, $PKIXExtensions::CRLDistributionPoints_Id, false);
}

void CRLDistributionPointsExtension::encode($OutputStream* out, $ObjectIdentifier* extensionId, bool isCritical) {
	$useLocalCurrentObjectStackCache();
	$var($DerOutputStream, tmp, $new($DerOutputStream));
	if (this->extensionValue == nullptr) {
		$set(this, extensionId, extensionId);
		this->critical = isCritical;
		encodeThis();
	}
	$Extension::encode(tmp);
	$nc(out)->write($(tmp->toByteArray()));
}

void CRLDistributionPointsExtension::set($String* name, Object$* obj) {
	$useLocalCurrentObjectStackCache();
	if ($nc(name)->equalsIgnoreCase(CRLDistributionPointsExtension::POINTS)) {
		if (!($instanceOf($List, obj))) {
			$throwNew($IOException, "Attribute value should be of type List."_s);
		}
		$set(this, distributionPoints, $cast($List, obj));
	} else {
		$throwNew($IOException, $$str({"Attribute name ["_s, name, "] not recognized by CertAttrSet:"_s, this->extensionName, $$str(u'.')}));
	}
	encodeThis();
}

$Object* CRLDistributionPointsExtension::get($String* name) {
	$useLocalCurrentObjectStackCache();
	if ($nc(name)->equalsIgnoreCase(CRLDistributionPointsExtension::POINTS)) {
		return $of(this->distributionPoints);
	} else {
		$throwNew($IOException, $$str({"Attribute name ["_s, name, "] not recognized by CertAttrSet:"_s, this->extensionName, $$str(u'.')}));
	}
}

void CRLDistributionPointsExtension::delete$($String* name) {
	$useLocalCurrentObjectStackCache();
	if ($nc(name)->equalsIgnoreCase(CRLDistributionPointsExtension::POINTS)) {
		$set(this, distributionPoints, $Collections::emptyList());
	} else {
		$throwNew($IOException, $$str({"Attribute name ["_s, name, "] not recognized by CertAttrSet:"_s, this->extensionName, $$str(u'.')}));
	}
	encodeThis();
}

$Enumeration* CRLDistributionPointsExtension::getElements() {
	$var($AttributeNameEnumeration, elements, $new($AttributeNameEnumeration));
	elements->addElement(CRLDistributionPointsExtension::POINTS);
	return elements->elements();
}

void CRLDistributionPointsExtension::encodeThis() {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->distributionPoints)->isEmpty()) {
		$set(this, extensionValue, nullptr);
	} else {
		$var($DerOutputStream, pnts, $new($DerOutputStream));
		{
			$var($Iterator, i$, $nc(this->distributionPoints)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($DistributionPoint, point, $cast($DistributionPoint, i$->next()));
				{
					$nc(point)->encode(pnts);
				}
			}
		}
		$var($DerOutputStream, seq, $new($DerOutputStream));
		seq->write($DerValue::tag_Sequence, pnts);
		$set(this, extensionValue, seq->toByteArray());
	}
}

$String* CRLDistributionPointsExtension::toString() {
	return $str({$($Extension::toString()), this->extensionName, " [\n  "_s, this->distributionPoints, "]\n"_s});
}

CRLDistributionPointsExtension::CRLDistributionPointsExtension() {
}

void clinit$CRLDistributionPointsExtension($Class* class$) {
	$assignStatic(CRLDistributionPointsExtension::IDENT, "x509.info.extensions.CRLDistributionPoints"_s);
	$assignStatic(CRLDistributionPointsExtension::NAME, "CRLDistributionPoints"_s);
	$assignStatic(CRLDistributionPointsExtension::POINTS, "points"_s);
}

$Class* CRLDistributionPointsExtension::load$($String* name, bool initialize) {
	$loadClass(CRLDistributionPointsExtension, name, initialize, &_CRLDistributionPointsExtension_ClassInfo_, clinit$CRLDistributionPointsExtension, allocate$CRLDistributionPointsExtension);
	return class$;
}

$Class* CRLDistributionPointsExtension::class$ = nullptr;

		} // x509
	} // security
} // sun