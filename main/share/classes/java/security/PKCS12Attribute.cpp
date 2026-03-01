#include <java/security/PKCS12Attribute.h>

#include <java/io/IOException.h>
#include <java/lang/CharSequence.h>
#include <java/math/BigInteger.h>
#include <java/util/Arrays.h>
#include <java/util/Date.h>
#include <java/util/regex/Matcher.h>
#include <java/util/regex/Pattern.h>
#include <sun/security/util/Debug.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <jcpp.h>

#undef COLON_SEPARATED_HEX_PAIRS

using $DerValueArray = $Array<::sun::security::util::DerValue>;
using $IOException = ::java::io::IOException;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $BigInteger = ::java::math::BigInteger;
using $Arrays = ::java::util::Arrays;
using $Date = ::java::util::Date;
using $Matcher = ::java::util::regex::Matcher;
using $Pattern = ::java::util::regex::Pattern;
using $Debug = ::sun::security::util::Debug;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;

namespace java {
	namespace security {

$FieldInfo _PKCS12Attribute_FieldInfo_[] = {
	{"COLON_SEPARATED_HEX_PAIRS", "Ljava/util/regex/Pattern;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PKCS12Attribute, COLON_SEPARATED_HEX_PAIRS)},
	{"name", "Ljava/lang/String;", nullptr, $PRIVATE, $field(PKCS12Attribute, name)},
	{"value", "Ljava/lang/String;", nullptr, $PRIVATE, $field(PKCS12Attribute, value)},
	{"encoded", "[B", nullptr, $PRIVATE | $FINAL, $field(PKCS12Attribute, encoded)},
	{"hashValue", "I", nullptr, $PRIVATE, $field(PKCS12Attribute, hashValue)},
	{}
};

$MethodInfo _PKCS12Attribute_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(PKCS12Attribute, init$, void, $String*, $String*)},
	{"<init>", "([B)V", nullptr, $PUBLIC, $method(PKCS12Attribute, init$, void, $bytes*)},
	{"encode", "(Lsun/security/util/ObjectIdentifier;[Ljava/lang/String;)[B", nullptr, $PRIVATE, $method(PKCS12Attribute, encode, $bytes*, $ObjectIdentifier*, $StringArray*), "java.io.IOException"},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(PKCS12Attribute, equals, bool, Object$*)},
	{"getEncoded", "()[B", nullptr, $PUBLIC, $method(PKCS12Attribute, getEncoded, $bytes*)},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(PKCS12Attribute, getName, $String*)},
	{"getValue", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(PKCS12Attribute, getValue, $String*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(PKCS12Attribute, hashCode, int32_t)},
	{"parse", "([B)V", nullptr, $PRIVATE, $method(PKCS12Attribute, parse, void, $bytes*), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(PKCS12Attribute, toString, $String*)},
	{}
};

$InnerClassInfo _PKCS12Attribute_InnerClassesInfo_[] = {
	{"java.security.KeyStore$Entry", "java.security.KeyStore", "Entry", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.security.KeyStore$Entry$Attribute", "java.security.KeyStore$Entry", "Attribute", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _PKCS12Attribute_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.security.PKCS12Attribute",
	"java.lang.Object",
	"java.security.KeyStore$Entry$Attribute",
	_PKCS12Attribute_FieldInfo_,
	_PKCS12Attribute_MethodInfo_,
	nullptr,
	nullptr,
	_PKCS12Attribute_InnerClassesInfo_
};

$Object* allocate$PKCS12Attribute($Class* clazz) {
	return $of($alloc(PKCS12Attribute));
}

$Pattern* PKCS12Attribute::COLON_SEPARATED_HEX_PAIRS = nullptr;

void PKCS12Attribute::init$($String* name, $String* value) {
	$useLocalCurrentObjectStackCache();
	this->hashValue = -1;
	if (name == nullptr || value == nullptr) {
		$throwNew($NullPointerException);
	}
	$var($ObjectIdentifier, type, nullptr);
	try {
		$assign(type, $ObjectIdentifier::of(name));
	} catch ($IOException& e) {
		$throwNew($IllegalArgumentException, "Incorrect format: name"_s, e);
	}
	$set(this, name, name);
	int32_t length = $nc(value)->length();
	$var($StringArray, values, nullptr);
	bool var$0 = length > 1 && value->charAt(0) == u'[';
	if (var$0 && value->charAt(length - 1) == u']') {
		$assign(values, $(value->substring(1, length - 1))->split(", "_s));
	} else {
		$assign(values, $new($StringArray, {value}));
	}
	$set(this, value, value);
	try {
		$set(this, encoded, encode(type, values));
	} catch ($IOException& e) {
		$throwNew($IllegalArgumentException, "Incorrect format: value"_s, e);
	}
}

void PKCS12Attribute::init$($bytes* encoded) {
	this->hashValue = -1;
	if (encoded == nullptr) {
		$throwNew($NullPointerException);
	}
	$set(this, encoded, $cast($bytes, $nc(encoded)->clone()));
	try {
		parse(encoded);
	} catch ($IOException& e) {
		$throwNew($IllegalArgumentException, "Incorrect format: encoded"_s, e);
	}
}

$String* PKCS12Attribute::getName() {
	return this->name;
}

$String* PKCS12Attribute::getValue() {
	return this->value;
}

$bytes* PKCS12Attribute::getEncoded() {
	return $cast($bytes, $nc(this->encoded)->clone());
}

bool PKCS12Attribute::equals(Object$* obj) {
	if ($equals(this, obj)) {
		return true;
	}
	if (!($instanceOf(PKCS12Attribute, obj))) {
		return false;
	}
	return $Arrays::equals(this->encoded, $nc(($cast(PKCS12Attribute, obj)))->encoded);
}

int32_t PKCS12Attribute::hashCode() {
	int32_t h = this->hashValue;
	if (h == -1) {
		this->hashValue = (h = $Arrays::hashCode(this->encoded));
	}
	return h;
}

$String* PKCS12Attribute::toString() {
	return ($str({this->name, "="_s, this->value}));
}

$bytes* PKCS12Attribute::encode($ObjectIdentifier* type, $StringArray* values) {
	$useLocalCurrentObjectStackCache();
	$var($DerOutputStream, attribute, $new($DerOutputStream));
	attribute->putOID(type);
	$var($DerOutputStream, attrContent, $new($DerOutputStream));
	{
		$var($StringArray, arr$, values);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, value, arr$->get(i$));
			{
				if ($nc($($nc(PKCS12Attribute::COLON_SEPARATED_HEX_PAIRS)->matcher(value)))->matches()) {
					$var($bytes, bytes, $$new($BigInteger, $($nc(value)->replace(static_cast<$CharSequence*>(":"_s), static_cast<$CharSequence*>(""_s))), 16)->toByteArray());
					if ($nc(bytes)->get(0) == 0) {
						$assign(bytes, $Arrays::copyOfRange(bytes, 1, bytes->length));
					}
					attrContent->putOctetString(bytes);
				} else {
					attrContent->putUTF8String(value);
				}
			}
		}
	}
	attribute->write($DerValue::tag_Set, attrContent);
	$var($DerOutputStream, attributeValue, $new($DerOutputStream));
	attributeValue->write($DerValue::tag_Sequence, attribute);
	return attributeValue->toByteArray();
}

void PKCS12Attribute::parse($bytes* encoded) {
	$useLocalCurrentObjectStackCache();
	$var($DerInputStream, attributeValue, $new($DerInputStream, encoded));
	$var($DerValueArray, attrSeq, attributeValue->getSequence(2));
	if ($nc(attrSeq)->length != 2) {
		$throwNew($IOException, "Invalid length for PKCS12Attribute"_s);
	}
	$var($ObjectIdentifier, type, $nc($nc(attrSeq)->get(0))->getOID());
	$var($DerInputStream, attrContent, $new($DerInputStream, $($nc(attrSeq->get(1))->toByteArray())));
	$var($DerValueArray, attrValueSet, attrContent->getSet(1));
	$var($StringArray, values, $new($StringArray, $nc(attrValueSet)->length));
	$var($String, printableString, nullptr);
	for (int32_t i = 0; i < attrValueSet->length; ++i) {
		if ($nc(attrValueSet->get(i))->tag == $DerValue::tag_OctetString) {
			values->set(i, $($Debug::toString($($nc(attrValueSet->get(i))->getOctetString()))));
		} else if (($assign(printableString, $nc(attrValueSet->get(i))->getAsString())) != nullptr) {
			values->set(i, printableString);
		} else if ($nc(attrValueSet->get(i))->tag == $DerValue::tag_ObjectId) {
			values->set(i, $($nc($($nc(attrValueSet->get(i))->getOID()))->toString()));
		} else if ($nc(attrValueSet->get(i))->tag == $DerValue::tag_GeneralizedTime) {
			values->set(i, $($nc($($nc(attrValueSet->get(i))->getGeneralizedTime()))->toString()));
		} else if ($nc(attrValueSet->get(i))->tag == $DerValue::tag_UtcTime) {
			values->set(i, $($nc($($nc(attrValueSet->get(i))->getUTCTime()))->toString()));
		} else if ($nc(attrValueSet->get(i))->tag == $DerValue::tag_Integer) {
			values->set(i, $($nc($($nc(attrValueSet->get(i))->getBigInteger()))->toString()));
		} else if ($nc(attrValueSet->get(i))->tag == $DerValue::tag_Boolean) {
			values->set(i, $($String::valueOf($nc(attrValueSet->get(i))->getBoolean())));
		} else {
			values->set(i, $($Debug::toString($($nc(attrValueSet->get(i))->getDataBytes()))));
		}
	}
	$set(this, name, $nc(type)->toString());
	$set(this, value, values->length == 1 ? values->get(0) : $Arrays::toString(values));
}

void clinit$PKCS12Attribute($Class* class$) {
	$assignStatic(PKCS12Attribute::COLON_SEPARATED_HEX_PAIRS, $Pattern::compile("^[0-9a-fA-F]{2}(:[0-9a-fA-F]{2})+$"_s));
}

PKCS12Attribute::PKCS12Attribute() {
}

$Class* PKCS12Attribute::load$($String* name, bool initialize) {
	$loadClass(PKCS12Attribute, name, initialize, &_PKCS12Attribute_ClassInfo_, clinit$PKCS12Attribute, allocate$PKCS12Attribute);
	return class$;
}

$Class* PKCS12Attribute::class$ = nullptr;

	} // security
} // java