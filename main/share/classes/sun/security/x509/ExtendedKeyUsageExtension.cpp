#include <sun/security/x509/ExtendedKeyUsageExtension.h>

#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <java/util/ArrayList.h>
#include <java/util/Enumeration.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Vector.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/KnownOIDs.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <sun/security/x509/AttributeNameEnumeration.h>
#include <sun/security/x509/Extension.h>
#include <sun/security/x509/PKIXExtensions.h>
#include <jcpp.h>

#undef FALSE
#undef IDENT
#undef NAME
#undef USAGES

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
using $Vector = ::java::util::Vector;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;
using $KnownOIDs = ::sun::security::util::KnownOIDs;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;
using $AttributeNameEnumeration = ::sun::security::x509::AttributeNameEnumeration;
using $Extension = ::sun::security::x509::Extension;
using $PKIXExtensions = ::sun::security::x509::PKIXExtensions;

namespace sun {
	namespace security {
		namespace x509 {

$FieldInfo _ExtendedKeyUsageExtension_FieldInfo_[] = {
	{"IDENT", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(ExtendedKeyUsageExtension, IDENT)},
	{"NAME", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(ExtendedKeyUsageExtension, NAME)},
	{"USAGES", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(ExtendedKeyUsageExtension, USAGES)},
	{"keyUsages", "Ljava/util/Vector;", "Ljava/util/Vector<Lsun/security/util/ObjectIdentifier;>;", $PRIVATE, $field(ExtendedKeyUsageExtension, keyUsages)},
	{}
};

$MethodInfo _ExtendedKeyUsageExtension_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC},
	{"<init>", "(Ljava/util/Vector;)V", "(Ljava/util/Vector<Lsun/security/util/ObjectIdentifier;>;)V", $PUBLIC, $method(ExtendedKeyUsageExtension, init$, void, $Vector*), "java.io.IOException"},
	{"<init>", "(Ljava/lang/Boolean;Ljava/util/Vector;)V", "(Ljava/lang/Boolean;Ljava/util/Vector<Lsun/security/util/ObjectIdentifier;>;)V", $PUBLIC, $method(ExtendedKeyUsageExtension, init$, void, $Boolean*, $Vector*), "java.io.IOException"},
	{"<init>", "(Ljava/lang/Boolean;Ljava/lang/Object;)V", nullptr, $PUBLIC, $method(ExtendedKeyUsageExtension, init$, void, $Boolean*, Object$*), "java.io.IOException"},
	{"delete", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(ExtendedKeyUsageExtension, delete$, void, $String*), "java.io.IOException"},
	{"encode", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC, $virtualMethod(ExtendedKeyUsageExtension, encode, void, $OutputStream*), "java.io.IOException"},
	{"encodeThis", "()V", nullptr, $PRIVATE, $method(ExtendedKeyUsageExtension, encodeThis, void), "java.io.IOException"},
	{"get", "(Ljava/lang/String;)Ljava/util/Vector;", "(Ljava/lang/String;)Ljava/util/Vector<Lsun/security/util/ObjectIdentifier;>;", $PUBLIC, $virtualMethod(ExtendedKeyUsageExtension, get, $Object*, $String*), "java.io.IOException"},
	{"getElements", "()Ljava/util/Enumeration;", "()Ljava/util/Enumeration<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(ExtendedKeyUsageExtension, getElements, $Enumeration*)},
	{"getExtendedKeyUsage", "()Ljava/util/List;", "()Ljava/util/List<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(ExtendedKeyUsageExtension, getExtendedKeyUsage, $List*)},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ExtendedKeyUsageExtension, getName, $String*)},
	{"set", "(Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(ExtendedKeyUsageExtension, set, void, $String*, Object$*), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ExtendedKeyUsageExtension, toString, $String*)},
	{}
};

$ClassInfo _ExtendedKeyUsageExtension_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.x509.ExtendedKeyUsageExtension",
	"sun.security.x509.Extension",
	"sun.security.x509.CertAttrSet",
	_ExtendedKeyUsageExtension_FieldInfo_,
	_ExtendedKeyUsageExtension_MethodInfo_,
	"Lsun/security/x509/Extension;Lsun/security/x509/CertAttrSet<Ljava/lang/String;>;"
};

$Object* allocate$ExtendedKeyUsageExtension($Class* clazz) {
	return $of($alloc(ExtendedKeyUsageExtension));
}

int32_t ExtendedKeyUsageExtension::hashCode() {
	 return this->$Extension::hashCode();
}

bool ExtendedKeyUsageExtension::equals(Object$* other) {
	 return this->$Extension::equals(other);
}

$Object* ExtendedKeyUsageExtension::clone() {
	 return this->$Extension::clone();
}

void ExtendedKeyUsageExtension::finalize() {
	this->$Extension::finalize();
}

$String* ExtendedKeyUsageExtension::IDENT = nullptr;
$String* ExtendedKeyUsageExtension::NAME = nullptr;
$String* ExtendedKeyUsageExtension::USAGES = nullptr;

void ExtendedKeyUsageExtension::encodeThis() {
	$useLocalCurrentObjectStackCache();
	if (this->keyUsages == nullptr || $nc(this->keyUsages)->isEmpty()) {
		$set(this, extensionValue, nullptr);
		return;
	}
	$var($DerOutputStream, os, $new($DerOutputStream));
	$var($DerOutputStream, tmp, $new($DerOutputStream));
	for (int32_t i = 0; i < $nc(this->keyUsages)->size(); ++i) {
		tmp->putOID($cast($ObjectIdentifier, $($nc(this->keyUsages)->elementAt(i))));
	}
	os->write($DerValue::tag_Sequence, tmp);
	$set(this, extensionValue, os->toByteArray());
}

void ExtendedKeyUsageExtension::init$($Vector* keyUsages) {
	$init($Boolean);
	ExtendedKeyUsageExtension::init$($Boolean::FALSE, keyUsages);
}

void ExtendedKeyUsageExtension::init$($Boolean* critical, $Vector* keyUsages) {
	$Extension::init$();
	$set(this, keyUsages, keyUsages);
	$init($PKIXExtensions);
	$set(this, extensionId, $PKIXExtensions::ExtendedKeyUsage_Id);
	this->critical = $nc(critical)->booleanValue();
	encodeThis();
}

void ExtendedKeyUsageExtension::init$($Boolean* critical, Object$* value) {
	$useLocalCurrentObjectStackCache();
	$Extension::init$();
	$init($PKIXExtensions);
	$set(this, extensionId, $PKIXExtensions::ExtendedKeyUsage_Id);
	this->critical = $nc(critical)->booleanValue();
	$set(this, extensionValue, $cast($bytes, value));
	$var($DerValue, val, $new($DerValue, this->extensionValue));
	if (val->tag != $DerValue::tag_Sequence) {
		$throwNew($IOException, "Invalid encoding for ExtendedKeyUsageExtension."_s);
	}
	$set(this, keyUsages, $new($Vector));
	while ($nc(val->data$)->available() != 0) {
		$var($DerValue, seq, $nc(val->data$)->getDerValue());
		$var($ObjectIdentifier, usage, $nc(seq)->getOID());
		$nc(this->keyUsages)->addElement(usage);
	}
}

$String* ExtendedKeyUsageExtension::toString() {
	$useLocalCurrentObjectStackCache();
	if (this->keyUsages == nullptr) {
		return ""_s;
	}
	$var($String, usage, "  "_s);
	bool first = true;
	{
		$var($Iterator, i$, $nc(this->keyUsages)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ObjectIdentifier, oid, $cast($ObjectIdentifier, i$->next()));
			{
				if (!first) {
					$plusAssign(usage, "\n  "_s);
				}
				$var($String, res, $nc(oid)->toString());
				$KnownOIDs* os = $KnownOIDs::findMatch(res);
				if (os != nullptr) {
					$plusAssign(usage, $(os->stdName()));
				} else {
					$plusAssign(usage, res);
				}
				first = false;
			}
		}
	}
	return $str({$($Extension::toString()), "ExtendedKeyUsages [\n"_s, usage, "\n]\n"_s});
}

void ExtendedKeyUsageExtension::encode($OutputStream* out) {
	$useLocalCurrentObjectStackCache();
	$var($DerOutputStream, tmp, $new($DerOutputStream));
	if (this->extensionValue == nullptr) {
		$init($PKIXExtensions);
		$set(this, extensionId, $PKIXExtensions::ExtendedKeyUsage_Id);
		this->critical = false;
		encodeThis();
	}
	$Extension::encode(tmp);
	$nc(out)->write($(tmp->toByteArray()));
}

void ExtendedKeyUsageExtension::set($String* name, Object$* obj) {
	if ($nc(name)->equalsIgnoreCase(ExtendedKeyUsageExtension::USAGES)) {
		if (!($instanceOf($Vector, obj))) {
			$throwNew($IOException, "Attribute value should be of type Vector."_s);
		}
		$set(this, keyUsages, $cast($Vector, obj));
	} else {
		$throwNew($IOException, $$str({"Attribute name ["_s, name, "] not recognized by CertAttrSet:ExtendedKeyUsageExtension."_s}));
	}
	encodeThis();
}

$Object* ExtendedKeyUsageExtension::get($String* name) {
	if ($nc(name)->equalsIgnoreCase(ExtendedKeyUsageExtension::USAGES)) {
		return $of(this->keyUsages);
	} else {
		$throwNew($IOException, $$str({"Attribute name ["_s, name, "] not recognized by CertAttrSet:ExtendedKeyUsageExtension."_s}));
	}
}

void ExtendedKeyUsageExtension::delete$($String* name) {
	if ($nc(name)->equalsIgnoreCase(ExtendedKeyUsageExtension::USAGES)) {
		$set(this, keyUsages, nullptr);
	} else {
		$throwNew($IOException, $$str({"Attribute name ["_s, name, "] not recognized by CertAttrSet:ExtendedKeyUsageExtension."_s}));
	}
	encodeThis();
}

$Enumeration* ExtendedKeyUsageExtension::getElements() {
	$var($AttributeNameEnumeration, elements, $new($AttributeNameEnumeration));
	elements->addElement(ExtendedKeyUsageExtension::USAGES);
	return (elements->elements());
}

$String* ExtendedKeyUsageExtension::getName() {
	return (ExtendedKeyUsageExtension::NAME);
}

$List* ExtendedKeyUsageExtension::getExtendedKeyUsage() {
	$useLocalCurrentObjectStackCache();
	$var($List, al, $new($ArrayList, $nc(this->keyUsages)->size()));
	{
		$var($Iterator, i$, $nc(this->keyUsages)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ObjectIdentifier, oid, $cast($ObjectIdentifier, i$->next()));
			{
				al->add($($nc(oid)->toString()));
			}
		}
	}
	return al;
}

ExtendedKeyUsageExtension::ExtendedKeyUsageExtension() {
}

void clinit$ExtendedKeyUsageExtension($Class* class$) {
	$assignStatic(ExtendedKeyUsageExtension::IDENT, "x509.info.extensions.ExtendedKeyUsage"_s);
	$assignStatic(ExtendedKeyUsageExtension::NAME, "ExtendedKeyUsage"_s);
	$assignStatic(ExtendedKeyUsageExtension::USAGES, "usages"_s);
}

$Class* ExtendedKeyUsageExtension::load$($String* name, bool initialize) {
	$loadClass(ExtendedKeyUsageExtension, name, initialize, &_ExtendedKeyUsageExtension_ClassInfo_, clinit$ExtendedKeyUsageExtension, allocate$ExtendedKeyUsageExtension);
	return class$;
}

$Class* ExtendedKeyUsageExtension::class$ = nullptr;

		} // x509
	} // security
} // sun