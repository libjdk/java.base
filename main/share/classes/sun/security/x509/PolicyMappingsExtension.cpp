#include <sun/security/x509/PolicyMappingsExtension.h>

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
#include <sun/security/x509/CertificatePolicyMap.h>
#include <sun/security/x509/Extension.h>
#include <sun/security/x509/PKIXExtensions.h>
#include <jcpp.h>

#undef IDENT
#undef MAP
#undef NAME

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
using $AttributeNameEnumeration = ::sun::security::x509::AttributeNameEnumeration;
using $CertificatePolicyMap = ::sun::security::x509::CertificatePolicyMap;
using $Extension = ::sun::security::x509::Extension;
using $PKIXExtensions = ::sun::security::x509::PKIXExtensions;

namespace sun {
	namespace security {
		namespace x509 {

$FieldInfo _PolicyMappingsExtension_FieldInfo_[] = {
	{"IDENT", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(PolicyMappingsExtension, IDENT)},
	{"NAME", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(PolicyMappingsExtension, NAME)},
	{"MAP", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(PolicyMappingsExtension, MAP)},
	{"maps", "Ljava/util/List;", "Ljava/util/List<Lsun/security/x509/CertificatePolicyMap;>;", $PRIVATE, $field(PolicyMappingsExtension, maps)},
	{}
};

$MethodInfo _PolicyMappingsExtension_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC},
	{"<init>", "(Ljava/util/List;)V", "(Ljava/util/List<Lsun/security/x509/CertificatePolicyMap;>;)V", $PUBLIC, $method(PolicyMappingsExtension, init$, void, $List*), "java.io.IOException"},
	{"<init>", "()V", nullptr, $PUBLIC, $method(PolicyMappingsExtension, init$, void)},
	{"<init>", "(Ljava/lang/Boolean;Ljava/lang/Object;)V", nullptr, $PUBLIC, $method(PolicyMappingsExtension, init$, void, $Boolean*, Object$*), "java.io.IOException"},
	{"delete", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(PolicyMappingsExtension, delete$, void, $String*), "java.io.IOException"},
	{"encode", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC, $virtualMethod(PolicyMappingsExtension, encode, void, $OutputStream*), "java.io.IOException"},
	{"encodeThis", "()V", nullptr, $PRIVATE, $method(PolicyMappingsExtension, encodeThis, void), "java.io.IOException"},
	{"get", "(Ljava/lang/String;)Ljava/util/List;", "(Ljava/lang/String;)Ljava/util/List<Lsun/security/x509/CertificatePolicyMap;>;", $PUBLIC, $virtualMethod(PolicyMappingsExtension, get, $Object*, $String*), "java.io.IOException"},
	{"getElements", "()Ljava/util/Enumeration;", "()Ljava/util/Enumeration<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(PolicyMappingsExtension, getElements, $Enumeration*)},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(PolicyMappingsExtension, getName, $String*)},
	{"set", "(Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(PolicyMappingsExtension, set, void, $String*, Object$*), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(PolicyMappingsExtension, toString, $String*)},
	{}
};

$ClassInfo _PolicyMappingsExtension_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.x509.PolicyMappingsExtension",
	"sun.security.x509.Extension",
	"sun.security.x509.CertAttrSet",
	_PolicyMappingsExtension_FieldInfo_,
	_PolicyMappingsExtension_MethodInfo_,
	"Lsun/security/x509/Extension;Lsun/security/x509/CertAttrSet<Ljava/lang/String;>;"
};

$Object* allocate$PolicyMappingsExtension($Class* clazz) {
	return $of($alloc(PolicyMappingsExtension));
}

int32_t PolicyMappingsExtension::hashCode() {
	 return this->$Extension::hashCode();
}

bool PolicyMappingsExtension::equals(Object$* other) {
	 return this->$Extension::equals(other);
}

$Object* PolicyMappingsExtension::clone() {
	 return this->$Extension::clone();
}

void PolicyMappingsExtension::finalize() {
	this->$Extension::finalize();
}

$String* PolicyMappingsExtension::IDENT = nullptr;
$String* PolicyMappingsExtension::NAME = nullptr;
$String* PolicyMappingsExtension::MAP = nullptr;

void PolicyMappingsExtension::encodeThis() {
	$useLocalCurrentObjectStackCache();
	if (this->maps == nullptr || $nc(this->maps)->isEmpty()) {
		$set(this, extensionValue, nullptr);
		return;
	}
	$var($DerOutputStream, os, $new($DerOutputStream));
	$var($DerOutputStream, tmp, $new($DerOutputStream));
	{
		$var($Iterator, i$, $nc(this->maps)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($CertificatePolicyMap, map, $cast($CertificatePolicyMap, i$->next()));
			{
				$nc(map)->encode(tmp);
			}
		}
	}
	os->write($DerValue::tag_Sequence, tmp);
	$set(this, extensionValue, os->toByteArray());
}

void PolicyMappingsExtension::init$($List* maps) {
	$Extension::init$();
	$set(this, maps, maps);
	$init($PKIXExtensions);
	$set(this, extensionId, $PKIXExtensions::PolicyMappings_Id);
	this->critical = true;
	encodeThis();
}

void PolicyMappingsExtension::init$() {
	$Extension::init$();
	$init($PKIXExtensions);
	$set(this, extensionId, $PKIXExtensions::PolicyMappings_Id);
	this->critical = true;
	$set(this, maps, $Collections::emptyList());
}

void PolicyMappingsExtension::init$($Boolean* critical, Object$* value) {
	$useLocalCurrentObjectStackCache();
	$Extension::init$();
	$init($PKIXExtensions);
	$set(this, extensionId, $PKIXExtensions::PolicyMappings_Id);
	this->critical = $nc(critical)->booleanValue();
	$set(this, extensionValue, $cast($bytes, value));
	$var($DerValue, val, $new($DerValue, this->extensionValue));
	if (val->tag != $DerValue::tag_Sequence) {
		$throwNew($IOException, "Invalid encoding for PolicyMappingsExtension."_s);
	}
	$set(this, maps, $new($ArrayList));
	while ($nc(val->data$)->available() != 0) {
		$var($DerValue, seq, $nc(val->data$)->getDerValue());
		$var($CertificatePolicyMap, map, $new($CertificatePolicyMap, seq));
		$nc(this->maps)->add(map);
	}
}

$String* PolicyMappingsExtension::toString() {
	$useLocalCurrentObjectStackCache();
	if (this->maps == nullptr) {
		return ""_s;
	}
	$var($String, var$1, $$str({$($Extension::toString()), "PolicyMappings [\n"_s}));
	$var($String, var$0, $$concat(var$1, $($nc($of(this->maps))->toString())));
	$var($String, s, $concat(var$0, "]\n"_s));
	return (s);
}

void PolicyMappingsExtension::encode($OutputStream* out) {
	$useLocalCurrentObjectStackCache();
	$var($DerOutputStream, tmp, $new($DerOutputStream));
	if (this->extensionValue == nullptr) {
		$init($PKIXExtensions);
		$set(this, extensionId, $PKIXExtensions::PolicyMappings_Id);
		this->critical = true;
		encodeThis();
	}
	$Extension::encode(tmp);
	$nc(out)->write($(tmp->toByteArray()));
}

void PolicyMappingsExtension::set($String* name, Object$* obj) {
	if ($nc(name)->equalsIgnoreCase(PolicyMappingsExtension::MAP)) {
		if (!($instanceOf($List, obj))) {
			$throwNew($IOException, "Attribute value should be of type List."_s);
		}
		$set(this, maps, $cast($List, obj));
	} else {
		$throwNew($IOException, "Attribute name not recognized by CertAttrSet:PolicyMappingsExtension."_s);
	}
	encodeThis();
}

$Object* PolicyMappingsExtension::get($String* name) {
	if ($nc(name)->equalsIgnoreCase(PolicyMappingsExtension::MAP)) {
		return $of((this->maps));
	} else {
		$throwNew($IOException, "Attribute name not recognized by CertAttrSet:PolicyMappingsExtension."_s);
	}
}

void PolicyMappingsExtension::delete$($String* name) {
	if ($nc(name)->equalsIgnoreCase(PolicyMappingsExtension::MAP)) {
		$set(this, maps, nullptr);
	} else {
		$throwNew($IOException, "Attribute name not recognized by CertAttrSet:PolicyMappingsExtension."_s);
	}
	encodeThis();
}

$Enumeration* PolicyMappingsExtension::getElements() {
	$var($AttributeNameEnumeration, elements, $new($AttributeNameEnumeration));
	elements->addElement(PolicyMappingsExtension::MAP);
	return elements->elements();
}

$String* PolicyMappingsExtension::getName() {
	return (PolicyMappingsExtension::NAME);
}

PolicyMappingsExtension::PolicyMappingsExtension() {
}

void clinit$PolicyMappingsExtension($Class* class$) {
	$assignStatic(PolicyMappingsExtension::IDENT, "x509.info.extensions.PolicyMappings"_s);
	$assignStatic(PolicyMappingsExtension::NAME, "PolicyMappings"_s);
	$assignStatic(PolicyMappingsExtension::MAP, "map"_s);
}

$Class* PolicyMappingsExtension::load$($String* name, bool initialize) {
	$loadClass(PolicyMappingsExtension, name, initialize, &_PolicyMappingsExtension_ClassInfo_, clinit$PolicyMappingsExtension, allocate$PolicyMappingsExtension);
	return class$;
}

$Class* PolicyMappingsExtension::class$ = nullptr;

		} // x509
	} // security
} // sun