#include <sun/security/x509/SubjectInfoAccessExtension.h>

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
#include <sun/security/x509/AccessDescription.h>
#include <sun/security/x509/AttributeNameEnumeration.h>
#include <sun/security/x509/Extension.h>
#include <sun/security/x509/PKIXExtensions.h>
#include <jcpp.h>

#undef DESCRIPTIONS
#undef IDENT
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
using $AccessDescription = ::sun::security::x509::AccessDescription;
using $AttributeNameEnumeration = ::sun::security::x509::AttributeNameEnumeration;
using $Extension = ::sun::security::x509::Extension;
using $PKIXExtensions = ::sun::security::x509::PKIXExtensions;

namespace sun {
	namespace security {
		namespace x509 {

$FieldInfo _SubjectInfoAccessExtension_FieldInfo_[] = {
	{"IDENT", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(SubjectInfoAccessExtension, IDENT)},
	{"NAME", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(SubjectInfoAccessExtension, NAME)},
	{"DESCRIPTIONS", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(SubjectInfoAccessExtension, DESCRIPTIONS)},
	{"accessDescriptions", "Ljava/util/List;", "Ljava/util/List<Lsun/security/x509/AccessDescription;>;", $PRIVATE, $field(SubjectInfoAccessExtension, accessDescriptions)},
	{}
};

$MethodInfo _SubjectInfoAccessExtension_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC},
	{"<init>", "(Ljava/util/List;)V", "(Ljava/util/List<Lsun/security/x509/AccessDescription;>;)V", $PUBLIC, $method(SubjectInfoAccessExtension, init$, void, $List*), "java.io.IOException"},
	{"<init>", "(Ljava/lang/Boolean;Ljava/lang/Object;)V", nullptr, $PUBLIC, $method(SubjectInfoAccessExtension, init$, void, $Boolean*, Object$*), "java.io.IOException"},
	{"delete", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(SubjectInfoAccessExtension, delete$, void, $String*), "java.io.IOException"},
	{"encode", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC, $virtualMethod(SubjectInfoAccessExtension, encode, void, $OutputStream*), "java.io.IOException"},
	{"encodeThis", "()V", nullptr, $PRIVATE, $method(SubjectInfoAccessExtension, encodeThis, void), "java.io.IOException"},
	{"get", "(Ljava/lang/String;)Ljava/util/List;", "(Ljava/lang/String;)Ljava/util/List<Lsun/security/x509/AccessDescription;>;", $PUBLIC, $virtualMethod(SubjectInfoAccessExtension, get, $Object*, $String*), "java.io.IOException"},
	{"getAccessDescriptions", "()Ljava/util/List;", "()Ljava/util/List<Lsun/security/x509/AccessDescription;>;", $PUBLIC, $virtualMethod(SubjectInfoAccessExtension, getAccessDescriptions, $List*)},
	{"getElements", "()Ljava/util/Enumeration;", "()Ljava/util/Enumeration<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(SubjectInfoAccessExtension, getElements, $Enumeration*)},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SubjectInfoAccessExtension, getName, $String*)},
	{"set", "(Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(SubjectInfoAccessExtension, set, void, $String*, Object$*), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SubjectInfoAccessExtension, toString, $String*)},
	{}
};

$ClassInfo _SubjectInfoAccessExtension_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.x509.SubjectInfoAccessExtension",
	"sun.security.x509.Extension",
	"sun.security.x509.CertAttrSet",
	_SubjectInfoAccessExtension_FieldInfo_,
	_SubjectInfoAccessExtension_MethodInfo_,
	"Lsun/security/x509/Extension;Lsun/security/x509/CertAttrSet<Ljava/lang/String;>;"
};

$Object* allocate$SubjectInfoAccessExtension($Class* clazz) {
	return $of($alloc(SubjectInfoAccessExtension));
}

int32_t SubjectInfoAccessExtension::hashCode() {
	 return this->$Extension::hashCode();
}

bool SubjectInfoAccessExtension::equals(Object$* other) {
	 return this->$Extension::equals(other);
}

$Object* SubjectInfoAccessExtension::clone() {
	 return this->$Extension::clone();
}

void SubjectInfoAccessExtension::finalize() {
	this->$Extension::finalize();
}

$String* SubjectInfoAccessExtension::IDENT = nullptr;
$String* SubjectInfoAccessExtension::NAME = nullptr;
$String* SubjectInfoAccessExtension::DESCRIPTIONS = nullptr;

void SubjectInfoAccessExtension::init$($List* accessDescriptions) {
	$Extension::init$();
	$init($PKIXExtensions);
	$set(this, extensionId, $PKIXExtensions::SubjectInfoAccess_Id);
	this->critical = false;
	$set(this, accessDescriptions, accessDescriptions);
	encodeThis();
}

void SubjectInfoAccessExtension::init$($Boolean* critical, Object$* value) {
	$useLocalCurrentObjectStackCache();
	$Extension::init$();
	$init($PKIXExtensions);
	$set(this, extensionId, $PKIXExtensions::SubjectInfoAccess_Id);
	this->critical = $nc(critical)->booleanValue();
	if (!($instanceOf($bytes, value))) {
		$throwNew($IOException, "Illegal argument type"_s);
	}
	$set(this, extensionValue, $cast($bytes, value));
	$var($DerValue, val, $new($DerValue, this->extensionValue));
	if (val->tag != $DerValue::tag_Sequence) {
		$throwNew($IOException, "Invalid encoding for SubjectInfoAccessExtension."_s);
	}
	$set(this, accessDescriptions, $new($ArrayList));
	while ($nc(val->data$)->available() != 0) {
		$var($DerValue, seq, $nc(val->data$)->getDerValue());
		$var($AccessDescription, accessDescription, $new($AccessDescription, seq));
		$nc(this->accessDescriptions)->add(accessDescription);
	}
}

$List* SubjectInfoAccessExtension::getAccessDescriptions() {
	return this->accessDescriptions;
}

$String* SubjectInfoAccessExtension::getName() {
	return SubjectInfoAccessExtension::NAME;
}

void SubjectInfoAccessExtension::encode($OutputStream* out) {
	$useLocalCurrentObjectStackCache();
	$var($DerOutputStream, tmp, $new($DerOutputStream));
	if (this->extensionValue == nullptr) {
		$init($PKIXExtensions);
		$set(this, extensionId, $PKIXExtensions::SubjectInfoAccess_Id);
		this->critical = false;
		encodeThis();
	}
	$Extension::encode(tmp);
	$nc(out)->write($(tmp->toByteArray()));
}

void SubjectInfoAccessExtension::set($String* name, Object$* obj) {
	if ($nc(name)->equalsIgnoreCase(SubjectInfoAccessExtension::DESCRIPTIONS)) {
		if (!($instanceOf($List, obj))) {
			$throwNew($IOException, "Attribute value should be of type List."_s);
		}
		$set(this, accessDescriptions, $cast($List, obj));
	} else {
		$throwNew($IOException, $$str({"Attribute name ["_s, name, "] not recognized by CertAttrSet:SubjectInfoAccessExtension."_s}));
	}
	encodeThis();
}

$Object* SubjectInfoAccessExtension::get($String* name) {
	if ($nc(name)->equalsIgnoreCase(SubjectInfoAccessExtension::DESCRIPTIONS)) {
		return $of(this->accessDescriptions);
	} else {
		$throwNew($IOException, $$str({"Attribute name ["_s, name, "] not recognized by CertAttrSet:SubjectInfoAccessExtension."_s}));
	}
}

void SubjectInfoAccessExtension::delete$($String* name) {
	if ($nc(name)->equalsIgnoreCase(SubjectInfoAccessExtension::DESCRIPTIONS)) {
		$set(this, accessDescriptions, $Collections::emptyList());
	} else {
		$throwNew($IOException, $$str({"Attribute name ["_s, name, "] not recognized by CertAttrSet:SubjectInfoAccessExtension."_s}));
	}
	encodeThis();
}

$Enumeration* SubjectInfoAccessExtension::getElements() {
	$var($AttributeNameEnumeration, elements, $new($AttributeNameEnumeration));
	elements->addElement(SubjectInfoAccessExtension::DESCRIPTIONS);
	return elements->elements();
}

void SubjectInfoAccessExtension::encodeThis() {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->accessDescriptions)->isEmpty()) {
		$set(this, extensionValue, nullptr);
	} else {
		$var($DerOutputStream, ads, $new($DerOutputStream));
		{
			$var($Iterator, i$, $nc(this->accessDescriptions)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($AccessDescription, accessDescription, $cast($AccessDescription, i$->next()));
				{
					$nc(accessDescription)->encode(ads);
				}
			}
		}
		$var($DerOutputStream, seq, $new($DerOutputStream));
		seq->write($DerValue::tag_Sequence, ads);
		$set(this, extensionValue, seq->toByteArray());
	}
}

$String* SubjectInfoAccessExtension::toString() {
	return $str({$($Extension::toString()), "SubjectInfoAccess [\n  "_s, this->accessDescriptions, "\n]\n"_s});
}

SubjectInfoAccessExtension::SubjectInfoAccessExtension() {
}

void clinit$SubjectInfoAccessExtension($Class* class$) {
	$assignStatic(SubjectInfoAccessExtension::IDENT, "x509.info.extensions.SubjectInfoAccess"_s);
	$assignStatic(SubjectInfoAccessExtension::NAME, "SubjectInfoAccess"_s);
	$assignStatic(SubjectInfoAccessExtension::DESCRIPTIONS, "descriptions"_s);
}

$Class* SubjectInfoAccessExtension::load$($String* name, bool initialize) {
	$loadClass(SubjectInfoAccessExtension, name, initialize, &_SubjectInfoAccessExtension_ClassInfo_, clinit$SubjectInfoAccessExtension, allocate$SubjectInfoAccessExtension);
	return class$;
}

$Class* SubjectInfoAccessExtension::class$ = nullptr;

		} // x509
	} // security
} // sun