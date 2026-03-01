#include <sun/security/pkcs/PKCS9Attribute.h>

#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/ExceptionInInitializerError.h>
#include <java/security/cert/CertificateException.h>
#include <java/util/Date.h>
#include <sun/security/pkcs/SignerInfo.h>
#include <sun/security/pkcs/SigningCertificateInfo.h>
#include <sun/security/util/Debug.h>
#include <sun/security/util/DerEncoder.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/HexDumpEncoder.h>
#include <sun/security/util/KnownOIDs.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <sun/security/x509/CertificateExtensions.h>
#include <jcpp.h>

#undef BYTE_ARRAY_CLASS
#undef CHALLENGE_PASSWORD_OID
#undef CMS_ALGORITHM_PROTECTION_OID
#undef CONTENT_TYPE_OID
#undef COUNTERSIGNATURE_OID
#undef EMAIL_ADDRESS_OID
#undef EXTENDED_CERTIFICATE_ATTRIBUTES_OID
#undef EXTENSION_REQUEST_OID
#undef ISSUER_SERIALNUMBER_OID
#undef MESSAGE_DIGEST_OID
#undef PKCS9_OIDS
#undef PKCS9_VALUE_TAGS
#undef SIGNATURE_TIMESTAMP_TOKEN_OID
#undef SIGNING_CERTIFICATE_OID
#undef SIGNING_TIME_OID
#undef SINGLE_VALUED
#undef UNSTRUCTURED_ADDRESS_OID
#undef UNSTRUCTURED_NAME_OID
#undef VALUE_CLASSES

using $ByteArray = $Array<::java::lang::Byte>;
using $SignerInfoArray = $Array<::sun::security::pkcs::SignerInfo>;
using $DerEncoderArray = $Array<::sun::security::util::DerEncoder>;
using $DerOutputStreamArray = $Array<::sun::security::util::DerOutputStream>;
using $DerValueArray = $Array<::sun::security::util::DerValue>;
using $ObjectIdentifierArray = $Array<::sun::security::util::ObjectIdentifier>;
using $ByteArray2 = $Array<::java::lang::Byte, 2>;
using $IOException = ::java::io::IOException;
using $OutputStream = ::java::io::OutputStream;
using $Byte = ::java::lang::Byte;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $ExceptionInInitializerError = ::java::lang::ExceptionInInitializerError;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $CertificateException = ::java::security::cert::CertificateException;
using $Date = ::java::util::Date;
using $SignerInfo = ::sun::security::pkcs::SignerInfo;
using $SigningCertificateInfo = ::sun::security::pkcs::SigningCertificateInfo;
using $Debug = ::sun::security::util::Debug;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;
using $HexDumpEncoder = ::sun::security::util::HexDumpEncoder;
using $KnownOIDs = ::sun::security::util::KnownOIDs;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;
using $CertificateExtensions = ::sun::security::x509::CertificateExtensions;

namespace sun {
	namespace security {
		namespace pkcs {

$FieldInfo _PKCS9Attribute_FieldInfo_[] = {
	{"debug", "Lsun/security/util/Debug;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PKCS9Attribute, debug)},
	{"PKCS9_OIDS", "[Lsun/security/util/ObjectIdentifier;", nullptr, $STATIC | $FINAL, $staticField(PKCS9Attribute, PKCS9_OIDS)},
	{"BYTE_ARRAY_CLASS", "Ljava/lang/Class;", "Ljava/lang/Class<*>;", $PRIVATE | $STATIC | $FINAL, $staticField(PKCS9Attribute, BYTE_ARRAY_CLASS)},
	{"EMAIL_ADDRESS_OID", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(PKCS9Attribute, EMAIL_ADDRESS_OID)},
	{"UNSTRUCTURED_NAME_OID", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(PKCS9Attribute, UNSTRUCTURED_NAME_OID)},
	{"CONTENT_TYPE_OID", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(PKCS9Attribute, CONTENT_TYPE_OID)},
	{"MESSAGE_DIGEST_OID", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(PKCS9Attribute, MESSAGE_DIGEST_OID)},
	{"SIGNING_TIME_OID", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(PKCS9Attribute, SIGNING_TIME_OID)},
	{"COUNTERSIGNATURE_OID", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(PKCS9Attribute, COUNTERSIGNATURE_OID)},
	{"CHALLENGE_PASSWORD_OID", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(PKCS9Attribute, CHALLENGE_PASSWORD_OID)},
	{"UNSTRUCTURED_ADDRESS_OID", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(PKCS9Attribute, UNSTRUCTURED_ADDRESS_OID)},
	{"EXTENDED_CERTIFICATE_ATTRIBUTES_OID", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(PKCS9Attribute, EXTENDED_CERTIFICATE_ATTRIBUTES_OID)},
	{"ISSUER_SERIALNUMBER_OID", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(PKCS9Attribute, ISSUER_SERIALNUMBER_OID)},
	{"EXTENSION_REQUEST_OID", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(PKCS9Attribute, EXTENSION_REQUEST_OID)},
	{"SIGNING_CERTIFICATE_OID", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(PKCS9Attribute, SIGNING_CERTIFICATE_OID)},
	{"SIGNATURE_TIMESTAMP_TOKEN_OID", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(PKCS9Attribute, SIGNATURE_TIMESTAMP_TOKEN_OID)},
	{"CMS_ALGORITHM_PROTECTION_OID", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(PKCS9Attribute, CMS_ALGORITHM_PROTECTION_OID)},
	{"PKCS9_VALUE_TAGS", "[[Ljava/lang/Byte;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PKCS9Attribute, PKCS9_VALUE_TAGS)},
	{"VALUE_CLASSES", "[Ljava/lang/Class;", "[Ljava/lang/Class<*>;", $PRIVATE | $STATIC | $FINAL, $staticField(PKCS9Attribute, VALUE_CLASSES)},
	{"SINGLE_VALUED", "[Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PKCS9Attribute, SINGLE_VALUED)},
	{"oid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PRIVATE, $field(PKCS9Attribute, oid)},
	{"index", "I", nullptr, $PRIVATE, $field(PKCS9Attribute, index)},
	{"value", "Ljava/lang/Object;", nullptr, $PRIVATE, $field(PKCS9Attribute, value)},
	{}
};

$MethodInfo _PKCS9Attribute_MethodInfo_[] = {
	{"<init>", "(Lsun/security/util/ObjectIdentifier;Ljava/lang/Object;)V", nullptr, $PUBLIC, $method(PKCS9Attribute, init$, void, $ObjectIdentifier*, Object$*), "java.lang.IllegalArgumentException"},
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(PKCS9Attribute, init$, void, $DerValue*), "java.io.IOException"},
	{"derEncode", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC, $virtualMethod(PKCS9Attribute, derEncode, void, $OutputStream*), "java.io.IOException"},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(PKCS9Attribute, getName, $String*)},
	{"getName", "(Lsun/security/util/ObjectIdentifier;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(PKCS9Attribute, getName, $String*, $ObjectIdentifier*)},
	{"getOID", "()Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC, $virtualMethod(PKCS9Attribute, getOID, $ObjectIdentifier*)},
	{"getOID", "(Ljava/lang/String;)Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC | $STATIC, $staticMethod(PKCS9Attribute, getOID, $ObjectIdentifier*, $String*)},
	{"getValue", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(PKCS9Attribute, getValue, $Object*)},
	{"indexOf", "(Ljava/lang/Object;[Ljava/lang/Object;I)I", nullptr, $STATIC, $staticMethod(PKCS9Attribute, indexOf, int32_t, Object$*, $ObjectArray*, int32_t)},
	{"init", "(Lsun/security/util/ObjectIdentifier;Ljava/lang/Object;)V", nullptr, $PRIVATE, $method(PKCS9Attribute, init, void, $ObjectIdentifier*, Object$*), "java.lang.IllegalArgumentException"},
	{"isKnown", "()Z", nullptr, $PUBLIC, $virtualMethod(PKCS9Attribute, isKnown, bool)},
	{"isSingleValued", "()Z", nullptr, $PUBLIC, $virtualMethod(PKCS9Attribute, isSingleValued, bool)},
	{"throwSingleValuedException", "()V", nullptr, $PRIVATE, $method(PKCS9Attribute, throwSingleValuedException, void), "java.io.IOException"},
	{"throwTagException", "(Ljava/lang/Byte;)V", nullptr, $PRIVATE, $method(PKCS9Attribute, throwTagException, void, $Byte*), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(PKCS9Attribute, toString, $String*)},
	{}
};

$ClassInfo _PKCS9Attribute_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.pkcs.PKCS9Attribute",
	"java.lang.Object",
	"sun.security.util.DerEncoder",
	_PKCS9Attribute_FieldInfo_,
	_PKCS9Attribute_MethodInfo_
};

$Object* allocate$PKCS9Attribute($Class* clazz) {
	return $of($alloc(PKCS9Attribute));
}

$Debug* PKCS9Attribute::debug = nullptr;
$ObjectIdentifierArray* PKCS9Attribute::PKCS9_OIDS = nullptr;
$Class* PKCS9Attribute::BYTE_ARRAY_CLASS = nullptr;
$ObjectIdentifier* PKCS9Attribute::EMAIL_ADDRESS_OID = nullptr;
$ObjectIdentifier* PKCS9Attribute::UNSTRUCTURED_NAME_OID = nullptr;
$ObjectIdentifier* PKCS9Attribute::CONTENT_TYPE_OID = nullptr;
$ObjectIdentifier* PKCS9Attribute::MESSAGE_DIGEST_OID = nullptr;
$ObjectIdentifier* PKCS9Attribute::SIGNING_TIME_OID = nullptr;
$ObjectIdentifier* PKCS9Attribute::COUNTERSIGNATURE_OID = nullptr;
$ObjectIdentifier* PKCS9Attribute::CHALLENGE_PASSWORD_OID = nullptr;
$ObjectIdentifier* PKCS9Attribute::UNSTRUCTURED_ADDRESS_OID = nullptr;
$ObjectIdentifier* PKCS9Attribute::EXTENDED_CERTIFICATE_ATTRIBUTES_OID = nullptr;
$ObjectIdentifier* PKCS9Attribute::ISSUER_SERIALNUMBER_OID = nullptr;
$ObjectIdentifier* PKCS9Attribute::EXTENSION_REQUEST_OID = nullptr;
$ObjectIdentifier* PKCS9Attribute::SIGNING_CERTIFICATE_OID = nullptr;
$ObjectIdentifier* PKCS9Attribute::SIGNATURE_TIMESTAMP_TOKEN_OID = nullptr;
$ObjectIdentifier* PKCS9Attribute::CMS_ALGORITHM_PROTECTION_OID = nullptr;
$ByteArray2* PKCS9Attribute::PKCS9_VALUE_TAGS = nullptr;
$ClassArray* PKCS9Attribute::VALUE_CLASSES = nullptr;
$booleans* PKCS9Attribute::SINGLE_VALUED = nullptr;

void PKCS9Attribute::init$($ObjectIdentifier* oid, Object$* value) {
	init(oid, value);
}

void PKCS9Attribute::init($ObjectIdentifier* oid, Object$* value) {
	$useLocalCurrentObjectStackCache();
	$set(this, oid, oid);
	this->index = indexOf(oid, PKCS9Attribute::PKCS9_OIDS, 1);
	$Class* clazz = this->index == -1 ? PKCS9Attribute::BYTE_ARRAY_CLASS : $nc(PKCS9Attribute::VALUE_CLASSES)->get(this->index);
	if (!$nc(clazz)->isInstance(value)) {
		$var($String, var$2, $$str({"Wrong value class  for attribute "_s, oid, " constructing PKCS9Attribute; was "_s}));
		$var($String, var$1, $$concat(var$2, $($nc($of(value))->getClass()->toString())));
		$var($String, var$0, $$concat(var$1, ", should be "_s));
		$throwNew($IllegalArgumentException, $$concat(var$0, $(clazz->toString())));
	}
	$set(this, value, value);
}

void PKCS9Attribute::init$($DerValue* derVal) {
	$useLocalCurrentObjectStackCache();
	$var($DerInputStream, derIn, $new($DerInputStream, $($nc(derVal)->toByteArray())));
	$var($DerValueArray, val, derIn->getSequence(2));
	if (derIn->available() != 0) {
		$throwNew($IOException, "Excess data parsing PKCS9Attribute"_s);
	}
	if ($nc(val)->length != 2) {
		$throwNew($IOException, "PKCS9Attribute doesn\'t have two components"_s);
	}
	$set(this, oid, $nc($nc(val)->get(0))->getOID());
	$var($bytes, content, $nc(val->get(1))->toByteArray());
	$var($DerValueArray, elems, $$new($DerInputStream, content)->getSet(1));
	this->index = indexOf(this->oid, PKCS9Attribute::PKCS9_OIDS, 1);
	if (this->index == -1) {
		if (PKCS9Attribute::debug != nullptr) {
			$nc(PKCS9Attribute::debug)->println($$str({"Unsupported signer attribute: "_s, this->oid}));
		}
		$set(this, value, content);
		return;
	}
	if ($nc(PKCS9Attribute::SINGLE_VALUED)->get(this->index) && $nc(elems)->length > 1) {
		throwSingleValuedException();
	}
	$var($Byte, tag, nullptr);
	{
		$var($DerValueArray, arr$, elems);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($DerValue, elem, arr$->get(i$));
			{
				$assign(tag, $Byte::valueOf($nc(elem)->tag));
				if (indexOf(tag, $nc(PKCS9Attribute::PKCS9_VALUE_TAGS)->get(this->index), 0) == -1) {
					throwTagException(tag);
				}
			}
		}
	}
	{
		int8_t elemTag = 0;
		$var($DerInputStream, dis, nullptr)
		switch (this->index) {
		case 1:
			{}
		case 2:
			{}
		case 8:
			{
				{
					$var($StringArray, values, $new($StringArray, $nc(elems)->length));
					for (int32_t i = 0; i < elems->length; ++i) {
						values->set(i, $($nc(elems->get(i))->getAsString()));
					}
					$set(this, value, values);
				}
				break;
			}
		case 3:
			{
				$set(this, value, $nc($nc(elems)->get(0))->getOID());
				break;
			}
		case 4:
			{
				$set(this, value, $nc($nc(elems)->get(0))->getOctetString());
				break;
			}
		case 5:
			{
				elemTag = $nc($nc(elems)->get(0))->getTag();
				$assign(dis, $new($DerInputStream, $($nc(elems->get(0))->toByteArray())));
				$set(this, value, (elemTag == $DerValue::tag_GeneralizedTime) ? $of($nc(dis)->getGeneralizedTime()) : $of(dis->getUTCTime()));
				break;
			}
		case 6:
			{
				{
					$var($SignerInfoArray, values, $new($SignerInfoArray, elems->length));
					for (int32_t i = 0; i < elems->length; ++i) {
						values->set(i, $$new($SignerInfo, $($nc(elems->get(i))->toDerInputStream())));
					}
					$set(this, value, values);
				}
				break;
			}
		case 7:
			{
				$set(this, value, $nc(elems->get(0))->getAsString());
				break;
			}
		case 9:
			{
				$throwNew($IOException, "PKCS9 extended-certificate attribute not supported."_s);
			}
		case 10:
			{
				$throwNew($IOException, "PKCS9 IssuerAndSerialNumberattribute not supported."_s);
			}
		case 11:
			{}
		case 12:
			{
				$throwNew($IOException, "PKCS9 RSA DSI attributes11 and 12, not supported."_s);
			}
		case 13:
			{
				$throwNew($IOException, "PKCS9 attribute #13 not supported."_s);
			}
		case 14:
			{
				$set(this, value, $new($CertificateExtensions, $$new($DerInputStream, $($nc(elems->get(0))->toByteArray()))));
				break;
			}
		case 15:
			{
				$throwNew($IOException, "PKCS9 SMIMECapability attribute not supported."_s);
			}
		case 16:
			{
				$set(this, value, $new($SigningCertificateInfo, $($nc(elems->get(0))->toByteArray())));
				break;
			}
		case 17:
			{
				$set(this, value, $nc(elems->get(0))->toByteArray());
				break;
			}
		case 18:
			{
				$set(this, value, $nc(elems->get(0))->toByteArray());
				break;
			}
		default:
			{}
		}
	}
}

void PKCS9Attribute::derEncode($OutputStream* out) {
	$useLocalCurrentObjectStackCache();
	$var($DerOutputStream, temp, $new($DerOutputStream));
	temp->putOID(this->oid);
	switch (this->index) {
	case -1:
		{
			temp->write($cast($bytes, this->value));
			break;
		}
	case 1:
		{}
	case 2:
		{
			{
				$var($StringArray, values, $cast($StringArray, this->value));
				$var($DerOutputStreamArray, temps, $new($DerOutputStreamArray, $nc(values)->length));
				for (int32_t i = 0; i < values->length; ++i) {
					temps->set(i, $$new($DerOutputStream));
					$nc(temps->get(i))->putIA5String(values->get(i));
				}
				temp->putOrderedSetOf($DerValue::tag_Set, $fcast($DerEncoderArray, temps));
			}
			break;
		}
	case 3:
		{
			{
				$var($DerOutputStream, temp2, $new($DerOutputStream));
				temp2->putOID($cast($ObjectIdentifier, this->value));
				temp->write($DerValue::tag_Set, $(temp2->toByteArray()));
			}
			break;
		}
	case 4:
		{
			{
				$var($DerOutputStream, temp2, $new($DerOutputStream));
				temp2->putOctetString($cast($bytes, this->value));
				temp->write($DerValue::tag_Set, $(temp2->toByteArray()));
			}
			break;
		}
	case 5:
		{
			{
				$var($DerOutputStream, temp2, $new($DerOutputStream));
				temp2->putUTCTime($cast($Date, this->value));
				temp->write($DerValue::tag_Set, $(temp2->toByteArray()));
			}
			break;
		}
	case 6:
		{
			temp->putOrderedSetOf($DerValue::tag_Set, $cast($DerEncoderArray, this->value));
			break;
		}
	case 7:
		{
			{
				$var($DerOutputStream, temp2, $new($DerOutputStream));
				temp2->putPrintableString($cast($String, this->value));
				temp->write($DerValue::tag_Set, $(temp2->toByteArray()));
			}
			break;
		}
	case 8:
		{
			{
				$var($StringArray, values, $cast($StringArray, this->value));
				$var($DerOutputStreamArray, temps, $new($DerOutputStreamArray, $nc(values)->length));
				for (int32_t i = 0; i < values->length; ++i) {
					temps->set(i, $$new($DerOutputStream));
					$nc(temps->get(i))->putPrintableString(values->get(i));
				}
				temp->putOrderedSetOf($DerValue::tag_Set, $fcast($DerEncoderArray, temps));
			}
			break;
		}
	case 9:
		{
			$throwNew($IOException, "PKCS9 extended-certificate attribute not supported."_s);
		}
	case 10:
		{
			$throwNew($IOException, "PKCS9 IssuerAndSerialNumberattribute not supported."_s);
		}
	case 11:
		{}
	case 12:
		{
			$throwNew($IOException, "PKCS9 RSA DSI attributes11 and 12, not supported."_s);
		}
	case 13:
		{
			$throwNew($IOException, "PKCS9 attribute #13 not supported."_s);
		}
	case 14:
		{
			{
				$var($DerOutputStream, temp2, $new($DerOutputStream));
				$var($CertificateExtensions, exts, $cast($CertificateExtensions, this->value));
				try {
					$nc(exts)->encode(temp2, true);
				} catch ($CertificateException& ex) {
					$throwNew($IOException, $(ex->toString()));
				}
				temp->write($DerValue::tag_Set, $(temp2->toByteArray()));
			}
			break;
		}
	case 15:
		{
			$throwNew($IOException, "PKCS9 attribute #15 not supported."_s);
		}
	case 16:
		{
			$throwNew($IOException, "PKCS9 SigningCertificate attribute not supported."_s);
		}
	case 17:
		{
			temp->write($DerValue::tag_Set, $cast($bytes, this->value));
			break;
		}
	case 18:
		{
			temp->write($DerValue::tag_Set, $cast($bytes, this->value));
			break;
		}
	default:
		{}
	}
	$var($DerOutputStream, derOut, $new($DerOutputStream));
	derOut->write($DerValue::tag_Sequence, $(temp->toByteArray()));
	$nc(out)->write($(derOut->toByteArray()));
}

bool PKCS9Attribute::isKnown() {
	return this->index != -1;
}

$Object* PKCS9Attribute::getValue() {
	return $of(this->value);
}

bool PKCS9Attribute::isSingleValued() {
	return this->index == -1 || $nc(PKCS9Attribute::SINGLE_VALUED)->get(this->index);
}

$ObjectIdentifier* PKCS9Attribute::getOID() {
	return this->oid;
}

$String* PKCS9Attribute::getName() {
	$var($String, n, $nc(this->oid)->toString());
	$KnownOIDs* os = $KnownOIDs::findMatch(n);
	return (os == nullptr ? n : $nc(os)->stdName());
}

$ObjectIdentifier* PKCS9Attribute::getOID($String* name) {
	$init(PKCS9Attribute);
	$KnownOIDs* o = $KnownOIDs::findMatch(name);
	if (o != nullptr) {
		return $ObjectIdentifier::of(o);
	} else {
		return nullptr;
	}
}

$String* PKCS9Attribute::getName($ObjectIdentifier* oid) {
	$init(PKCS9Attribute);
	$useLocalCurrentObjectStackCache();
	return $nc($($KnownOIDs::findMatch($($nc(oid)->toString()))))->stdName();
}

$String* PKCS9Attribute::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder, 100));
	sb->append("["_s);
	if (this->index == -1) {
		sb->append($($nc(this->oid)->toString()));
	} else {
		sb->append($(getName(this->oid)));
	}
	sb->append(": "_s);
	if (this->index == -1 || $nc(PKCS9Attribute::SINGLE_VALUED)->get(this->index)) {
		if ($instanceOf($bytes, this->value)) {
			$var($HexDumpEncoder, hexDump, $new($HexDumpEncoder));
			sb->append($(hexDump->encodeBuffer($cast($bytes, this->value))));
		} else {
			sb->append($($nc($of(this->value))->toString()));
		}
		sb->append("]"_s);
		return sb->toString();
	} else {
		bool first = true;
		$var($ObjectArray, values, $cast($ObjectArray, this->value));
		{
			$var($ObjectArray, arr$, values);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($Object0, curVal, arr$->get(i$));
				{
					if (first) {
						first = false;
					} else {
						sb->append(", "_s);
					}
					sb->append($($nc($of(curVal))->toString()));
				}
			}
		}
		return sb->toString();
	}
}

int32_t PKCS9Attribute::indexOf(Object$* obj, $ObjectArray* a, int32_t start) {
	$init(PKCS9Attribute);
	for (int32_t i = start; i < $nc(a)->length; ++i) {
		if ($nc($of(obj))->equals(a->get(i))) {
			return i;
		}
	}
	return -1;
}

void PKCS9Attribute::throwSingleValuedException() {
	$useLocalCurrentObjectStackCache();
	$var($String, var$1, $$str({"Single-value attribute "_s, this->oid, " ("_s}));
	$var($String, var$0, $$concat(var$1, $(getName())));
	$throwNew($IOException, $$concat(var$0, ") has multiple values."_s));
}

void PKCS9Attribute::throwTagException($Byte* tag) {
	$useLocalCurrentObjectStackCache();
	$var($ByteArray, expectedTags, $nc(PKCS9Attribute::PKCS9_VALUE_TAGS)->get(this->index));
	$var($StringBuilder, msg, $new($StringBuilder, 100));
	msg->append("Value of attribute "_s);
	msg->append($($nc(this->oid)->toString()));
	msg->append(" ("_s);
	msg->append($(getName()));
	msg->append(") has wrong tag: "_s);
	msg->append($($nc(tag)->toString()));
	msg->append(".  Expected tags: "_s);
	msg->append($($nc($nc(expectedTags)->get(0))->toString()));
	for (int32_t i = 1; i < $nc(expectedTags)->length; ++i) {
		msg->append(", "_s);
		msg->append($($nc(expectedTags->get(i))->toString()));
	}
	msg->append("."_s);
	$throwNew($IOException, $(msg->toString()));
}

void clinit$PKCS9Attribute($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$assignStatic(PKCS9Attribute::debug, $Debug::getInstance("jar"_s));
	$assignStatic(PKCS9Attribute::PKCS9_OIDS, $new($ObjectIdentifierArray, 19));
	{
		$nc(PKCS9Attribute::PKCS9_OIDS)->set(0, $nc(PKCS9Attribute::PKCS9_OIDS)->set(11, $nc(PKCS9Attribute::PKCS9_OIDS)->set(12, $nc(PKCS9Attribute::PKCS9_OIDS)->set(13, $nc(PKCS9Attribute::PKCS9_OIDS)->set(15, nullptr)))));
		try {
			$assignStatic(PKCS9Attribute::BYTE_ARRAY_CLASS, $Class::forName("[B"_s));
		} catch ($ClassNotFoundException& e) {
			$throwNew($ExceptionInInitializerError, $(e->toString()));
		}
	}
	$init($KnownOIDs);
	$assignStatic(PKCS9Attribute::EMAIL_ADDRESS_OID, ($nc(PKCS9Attribute::PKCS9_OIDS)->set(1, $($ObjectIdentifier::of($KnownOIDs::EmailAddress)))));
	$assignStatic(PKCS9Attribute::UNSTRUCTURED_NAME_OID, ($nc(PKCS9Attribute::PKCS9_OIDS)->set(2, $($ObjectIdentifier::of($KnownOIDs::UnstructuredName)))));
	$assignStatic(PKCS9Attribute::CONTENT_TYPE_OID, ($nc(PKCS9Attribute::PKCS9_OIDS)->set(3, $($ObjectIdentifier::of($KnownOIDs::ContentType)))));
	$assignStatic(PKCS9Attribute::MESSAGE_DIGEST_OID, ($nc(PKCS9Attribute::PKCS9_OIDS)->set(4, $($ObjectIdentifier::of($KnownOIDs::MessageDigest)))));
	$assignStatic(PKCS9Attribute::SIGNING_TIME_OID, ($nc(PKCS9Attribute::PKCS9_OIDS)->set(5, $($ObjectIdentifier::of($KnownOIDs::SigningTime)))));
	$assignStatic(PKCS9Attribute::COUNTERSIGNATURE_OID, ($nc(PKCS9Attribute::PKCS9_OIDS)->set(6, $($ObjectIdentifier::of($KnownOIDs::CounterSignature)))));
	$assignStatic(PKCS9Attribute::CHALLENGE_PASSWORD_OID, ($nc(PKCS9Attribute::PKCS9_OIDS)->set(7, $($ObjectIdentifier::of($KnownOIDs::ChallengePassword)))));
	$assignStatic(PKCS9Attribute::UNSTRUCTURED_ADDRESS_OID, ($nc(PKCS9Attribute::PKCS9_OIDS)->set(8, $($ObjectIdentifier::of($KnownOIDs::UnstructuredAddress)))));
	$assignStatic(PKCS9Attribute::EXTENDED_CERTIFICATE_ATTRIBUTES_OID, ($nc(PKCS9Attribute::PKCS9_OIDS)->set(9, $($ObjectIdentifier::of($KnownOIDs::ExtendedCertificateAttributes)))));
	$assignStatic(PKCS9Attribute::ISSUER_SERIALNUMBER_OID, ($nc(PKCS9Attribute::PKCS9_OIDS)->set(10, $($ObjectIdentifier::of($KnownOIDs::IssuerAndSerialNumber)))));
	$assignStatic(PKCS9Attribute::EXTENSION_REQUEST_OID, ($nc(PKCS9Attribute::PKCS9_OIDS)->set(14, $($ObjectIdentifier::of($KnownOIDs::ExtensionRequest)))));
	$assignStatic(PKCS9Attribute::SIGNING_CERTIFICATE_OID, ($nc(PKCS9Attribute::PKCS9_OIDS)->set(16, $($ObjectIdentifier::of($KnownOIDs::SigningCertificate)))));
	$assignStatic(PKCS9Attribute::SIGNATURE_TIMESTAMP_TOKEN_OID, ($nc(PKCS9Attribute::PKCS9_OIDS)->set(17, $($ObjectIdentifier::of($KnownOIDs::SignatureTimestampToken)))));
	$assignStatic(PKCS9Attribute::CMS_ALGORITHM_PROTECTION_OID, ($nc(PKCS9Attribute::PKCS9_OIDS)->set(18, $($ObjectIdentifier::of($KnownOIDs::CMSAlgorithmProtection)))));
	$assignStatic(PKCS9Attribute::PKCS9_VALUE_TAGS, $new($ByteArray2, {
		($ByteArray*)nullptr,
		$$new($ByteArray, {$($Byte::valueOf($DerValue::tag_IA5String))}),
		$$new($ByteArray, {
			$($Byte::valueOf($DerValue::tag_IA5String)),
			$($Byte::valueOf($DerValue::tag_PrintableString)),
			$($Byte::valueOf($DerValue::tag_T61String)),
			$($Byte::valueOf($DerValue::tag_BMPString)),
			$($Byte::valueOf($DerValue::tag_UniversalString)),
			$($Byte::valueOf($DerValue::tag_UTF8String))
		}),
		$$new($ByteArray, {$($Byte::valueOf($DerValue::tag_ObjectId))}),
		$$new($ByteArray, {$($Byte::valueOf($DerValue::tag_OctetString))}),
		$$new($ByteArray, {
			$($Byte::valueOf($DerValue::tag_UtcTime)),
			$($Byte::valueOf($DerValue::tag_GeneralizedTime))
		}),
		$$new($ByteArray, {$($Byte::valueOf($DerValue::tag_Sequence))}),
		$$new($ByteArray, {
			$($Byte::valueOf($DerValue::tag_PrintableString)),
			$($Byte::valueOf($DerValue::tag_T61String)),
			$($Byte::valueOf($DerValue::tag_BMPString)),
			$($Byte::valueOf($DerValue::tag_UniversalString)),
			$($Byte::valueOf($DerValue::tag_UTF8String))
		}),
		$$new($ByteArray, {
			$($Byte::valueOf($DerValue::tag_PrintableString)),
			$($Byte::valueOf($DerValue::tag_T61String)),
			$($Byte::valueOf($DerValue::tag_BMPString)),
			$($Byte::valueOf($DerValue::tag_UniversalString)),
			$($Byte::valueOf($DerValue::tag_UTF8String))
		}),
		$$new($ByteArray, {$($Byte::valueOf($DerValue::tag_SetOf))}),
		$$new($ByteArray, {$($Byte::valueOf($DerValue::tag_Sequence))}),
		($ByteArray*)nullptr,
		($ByteArray*)nullptr,
		($ByteArray*)nullptr,
		$$new($ByteArray, {$($Byte::valueOf($DerValue::tag_Sequence))}),
		$$new($ByteArray, {$($Byte::valueOf($DerValue::tag_Sequence))}),
		$$new($ByteArray, {$($Byte::valueOf($DerValue::tag_Sequence))}),
		$$new($ByteArray, {$($Byte::valueOf($DerValue::tag_Sequence))}),
		$$new($ByteArray, {$($Byte::valueOf($DerValue::tag_Sequence))})
	}));
	$assignStatic(PKCS9Attribute::VALUE_CLASSES, $new($ClassArray, 19));
	{
		try {
			$Class* str = $Class::forName("[Ljava.lang.String;"_s);
			$nc(PKCS9Attribute::VALUE_CLASSES)->set(0, nullptr);
			$nc(PKCS9Attribute::VALUE_CLASSES)->set(1, str);
			$nc(PKCS9Attribute::VALUE_CLASSES)->set(2, str);
			$nc(PKCS9Attribute::VALUE_CLASSES)->set(3, $Class::forName("sun.security.util.ObjectIdentifier"_s));
			$nc(PKCS9Attribute::VALUE_CLASSES)->set(4, PKCS9Attribute::BYTE_ARRAY_CLASS);
			$nc(PKCS9Attribute::VALUE_CLASSES)->set(5, $Class::forName("java.util.Date"_s));
			$nc(PKCS9Attribute::VALUE_CLASSES)->set(6, $Class::forName("[Lsun.security.pkcs.SignerInfo;"_s));
			$nc(PKCS9Attribute::VALUE_CLASSES)->set(7, $Class::forName("java.lang.String"_s));
			$nc(PKCS9Attribute::VALUE_CLASSES)->set(8, str);
			$nc(PKCS9Attribute::VALUE_CLASSES)->set(9, nullptr);
			$nc(PKCS9Attribute::VALUE_CLASSES)->set(10, nullptr);
			$nc(PKCS9Attribute::VALUE_CLASSES)->set(11, nullptr);
			$nc(PKCS9Attribute::VALUE_CLASSES)->set(12, nullptr);
			$nc(PKCS9Attribute::VALUE_CLASSES)->set(13, nullptr);
			$nc(PKCS9Attribute::VALUE_CLASSES)->set(14, $Class::forName("sun.security.x509.CertificateExtensions"_s));
			$nc(PKCS9Attribute::VALUE_CLASSES)->set(15, nullptr);
			$nc(PKCS9Attribute::VALUE_CLASSES)->set(16, nullptr);
			$nc(PKCS9Attribute::VALUE_CLASSES)->set(17, PKCS9Attribute::BYTE_ARRAY_CLASS);
			$nc(PKCS9Attribute::VALUE_CLASSES)->set(18, PKCS9Attribute::BYTE_ARRAY_CLASS);
		} catch ($ClassNotFoundException& e) {
			$throwNew($ExceptionInInitializerError, $(e->toString()));
		}
	}
	$assignStatic(PKCS9Attribute::SINGLE_VALUED, $new($booleans, {
		false,
		false,
		false,
		true,
		true,
		true,
		false,
		true,
		false,
		false,
		true,
		false,
		false,
		false,
		true,
		true,
		true,
		true,
		true
	}));
}

PKCS9Attribute::PKCS9Attribute() {
}

$Class* PKCS9Attribute::load$($String* name, bool initialize) {
	$loadClass(PKCS9Attribute, name, initialize, &_PKCS9Attribute_ClassInfo_, clinit$PKCS9Attribute, allocate$PKCS9Attribute);
	return class$;
}

$Class* PKCS9Attribute::class$ = nullptr;

		} // pkcs
	} // security
} // sun