#include <sun/security/x509/X509CertInfo.h>

#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <java/security/PublicKey.h>
#include <java/security/cert/CertificateEncodingException.h>
#include <java/security/cert/CertificateException.h>
#include <java/security/cert/CertificateParsingException.h>
#include <java/util/Collection.h>
#include <java/util/Date.h>
#include <java/util/Enumeration.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/Map.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/HexDumpEncoder.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <sun/security/x509/AlgorithmId.h>
#include <sun/security/x509/AttributeNameEnumeration.h>
#include <sun/security/x509/CertificateAlgorithmId.h>
#include <sun/security/x509/CertificateExtensions.h>
#include <sun/security/x509/CertificateSerialNumber.h>
#include <sun/security/x509/CertificateValidity.h>
#include <sun/security/x509/CertificateVersion.h>
#include <sun/security/x509/CertificateX509Key.h>
#include <sun/security/x509/Extension.h>
#include <sun/security/x509/GeneralNames.h>
#include <sun/security/x509/OIDMap.h>
#include <sun/security/x509/SerialNumber.h>
#include <sun/security/x509/SubjectAlternativeNameExtension.h>
#include <sun/security/x509/UniqueIdentity.h>
#include <sun/security/x509/X500Name.h>
#include <sun/security/x509/X509AttributeName.h>
#include <jcpp.h>

#undef ALGORITHM_ID
#undef ATTR_ALGORITHM
#undef ATTR_EXTENSIONS
#undef ATTR_ISSUER
#undef ATTR_ISSUER_ID
#undef ATTR_KEY
#undef ATTR_SERIAL
#undef ATTR_SUBJECT
#undef ATTR_SUBJECT_ID
#undef ATTR_VALIDITY
#undef ATTR_VERSION
#undef DN_NAME
#undef EXTENSIONS
#undef IDENT
#undef ISSUER
#undef ISSUER_ID
#undef KEY
#undef NAME
#undef SERIAL_NUMBER
#undef SUBJECT
#undef SUBJECT_ID
#undef SUBJECT_NAME
#undef TAG_CONTEXT
#undef VALIDITY
#undef VERSION

using $ExtensionArray = $Array<::sun::security::x509::Extension>;
using $IOException = ::java::io::IOException;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $CertificateEncodingException = ::java::security::cert::CertificateEncodingException;
using $CertificateException = ::java::security::cert::CertificateException;
using $CertificateParsingException = ::java::security::cert::CertificateParsingException;
using $Collection = ::java::util::Collection;
using $Enumeration = ::java::util::Enumeration;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $Map = ::java::util::Map;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;
using $HexDumpEncoder = ::sun::security::util::HexDumpEncoder;
using $AttributeNameEnumeration = ::sun::security::x509::AttributeNameEnumeration;
using $CertificateAlgorithmId = ::sun::security::x509::CertificateAlgorithmId;
using $CertificateExtensions = ::sun::security::x509::CertificateExtensions;
using $CertificateSerialNumber = ::sun::security::x509::CertificateSerialNumber;
using $CertificateValidity = ::sun::security::x509::CertificateValidity;
using $CertificateVersion = ::sun::security::x509::CertificateVersion;
using $CertificateX509Key = ::sun::security::x509::CertificateX509Key;
using $Extension = ::sun::security::x509::Extension;
using $GeneralNames = ::sun::security::x509::GeneralNames;
using $OIDMap = ::sun::security::x509::OIDMap;
using $SubjectAlternativeNameExtension = ::sun::security::x509::SubjectAlternativeNameExtension;
using $UniqueIdentity = ::sun::security::x509::UniqueIdentity;
using $X500Name = ::sun::security::x509::X500Name;
using $X509AttributeName = ::sun::security::x509::X509AttributeName;

namespace sun {
	namespace security {
		namespace x509 {

$FieldInfo _X509CertInfo_FieldInfo_[] = {
	{"IDENT", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X509CertInfo, IDENT)},
	{"NAME", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X509CertInfo, NAME)},
	{"DN_NAME", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X509CertInfo, DN_NAME)},
	{"VERSION", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X509CertInfo, VERSION)},
	{"SERIAL_NUMBER", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X509CertInfo, SERIAL_NUMBER)},
	{"ALGORITHM_ID", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X509CertInfo, ALGORITHM_ID)},
	{"ISSUER", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X509CertInfo, ISSUER)},
	{"SUBJECT", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X509CertInfo, SUBJECT)},
	{"VALIDITY", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X509CertInfo, VALIDITY)},
	{"KEY", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X509CertInfo, KEY)},
	{"ISSUER_ID", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X509CertInfo, ISSUER_ID)},
	{"SUBJECT_ID", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X509CertInfo, SUBJECT_ID)},
	{"EXTENSIONS", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(X509CertInfo, EXTENSIONS)},
	{"version", "Lsun/security/x509/CertificateVersion;", nullptr, $PROTECTED, $field(X509CertInfo, version)},
	{"serialNum", "Lsun/security/x509/CertificateSerialNumber;", nullptr, $PROTECTED, $field(X509CertInfo, serialNum)},
	{"algId", "Lsun/security/x509/CertificateAlgorithmId;", nullptr, $PROTECTED, $field(X509CertInfo, algId)},
	{"issuer", "Lsun/security/x509/X500Name;", nullptr, $PROTECTED, $field(X509CertInfo, issuer)},
	{"subject", "Lsun/security/x509/X500Name;", nullptr, $PROTECTED, $field(X509CertInfo, subject)},
	{"interval", "Lsun/security/x509/CertificateValidity;", nullptr, $PROTECTED, $field(X509CertInfo, interval)},
	{"pubKey", "Lsun/security/x509/CertificateX509Key;", nullptr, $PROTECTED, $field(X509CertInfo, pubKey)},
	{"issuerUniqueId", "Lsun/security/x509/UniqueIdentity;", nullptr, $PROTECTED, $field(X509CertInfo, issuerUniqueId)},
	{"subjectUniqueId", "Lsun/security/x509/UniqueIdentity;", nullptr, $PROTECTED, $field(X509CertInfo, subjectUniqueId)},
	{"extensions", "Lsun/security/x509/CertificateExtensions;", nullptr, $PROTECTED, $field(X509CertInfo, extensions)},
	{"ATTR_VERSION", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(X509CertInfo, ATTR_VERSION)},
	{"ATTR_SERIAL", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(X509CertInfo, ATTR_SERIAL)},
	{"ATTR_ALGORITHM", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(X509CertInfo, ATTR_ALGORITHM)},
	{"ATTR_ISSUER", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(X509CertInfo, ATTR_ISSUER)},
	{"ATTR_VALIDITY", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(X509CertInfo, ATTR_VALIDITY)},
	{"ATTR_SUBJECT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(X509CertInfo, ATTR_SUBJECT)},
	{"ATTR_KEY", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(X509CertInfo, ATTR_KEY)},
	{"ATTR_ISSUER_ID", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(X509CertInfo, ATTR_ISSUER_ID)},
	{"ATTR_SUBJECT_ID", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(X509CertInfo, ATTR_SUBJECT_ID)},
	{"ATTR_EXTENSIONS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(X509CertInfo, ATTR_EXTENSIONS)},
	{"rawCertInfo", "[B", nullptr, $PRIVATE, $field(X509CertInfo, rawCertInfo)},
	{"map", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/Integer;>;", $PRIVATE | $STATIC | $FINAL, $staticField(X509CertInfo, map)},
	{}
};

$MethodInfo _X509CertInfo_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(X509CertInfo, init$, void)},
	{"<init>", "([B)V", nullptr, $PUBLIC, $method(X509CertInfo, init$, void, $bytes*), "java.security.cert.CertificateParsingException"},
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(X509CertInfo, init$, void, $DerValue*), "java.security.cert.CertificateParsingException"},
	{"attributeMap", "(Ljava/lang/String;)I", nullptr, $PRIVATE, $method(X509CertInfo, attributeMap, int32_t, $String*)},
	{"delete", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(X509CertInfo, delete$, void, $String*), "java.security.cert.CertificateException,java.io.IOException"},
	{"emit", "(Lsun/security/util/DerOutputStream;)V", nullptr, $PRIVATE, $method(X509CertInfo, emit, void, $DerOutputStream*), "java.security.cert.CertificateException,java.io.IOException"},
	{"encode", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC, $virtualMethod(X509CertInfo, encode, void, $OutputStream*), "java.security.cert.CertificateException,java.io.IOException"},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(X509CertInfo, equals, bool, Object$*)},
	{"equals", "(Lsun/security/x509/X509CertInfo;)Z", nullptr, $PUBLIC, $virtualMethod(X509CertInfo, equals, bool, X509CertInfo*)},
	{"get", "(Ljava/lang/String;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(X509CertInfo, get, $Object*, $String*), "java.security.cert.CertificateException,java.io.IOException"},
	{"getElements", "()Ljava/util/Enumeration;", "()Ljava/util/Enumeration<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(X509CertInfo, getElements, $Enumeration*)},
	{"getEncodedInfo", "()[B", nullptr, $PUBLIC, $virtualMethod(X509CertInfo, getEncodedInfo, $bytes*), "java.security.cert.CertificateEncodingException"},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(X509CertInfo, getName, $String*)},
	{"getX500Name", "(Ljava/lang/String;Z)Ljava/lang/Object;", nullptr, $PRIVATE, $method(X509CertInfo, getX500Name, $Object*, $String*, bool), "java.io.IOException"},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(X509CertInfo, hashCode, int32_t)},
	{"parse", "(Lsun/security/util/DerValue;)V", nullptr, $PRIVATE, $method(X509CertInfo, parse, void, $DerValue*), "java.security.cert.CertificateParsingException,java.io.IOException"},
	{"set", "(Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(X509CertInfo, set, void, $String*, Object$*), "java.security.cert.CertificateException,java.io.IOException"},
	{"setAlgorithmId", "(Ljava/lang/Object;)V", nullptr, $PRIVATE, $method(X509CertInfo, setAlgorithmId, void, Object$*), "java.security.cert.CertificateException"},
	{"setExtensions", "(Ljava/lang/Object;)V", nullptr, $PRIVATE, $method(X509CertInfo, setExtensions, void, Object$*), "java.security.cert.CertificateException"},
	{"setIssuer", "(Ljava/lang/Object;)V", nullptr, $PRIVATE, $method(X509CertInfo, setIssuer, void, Object$*), "java.security.cert.CertificateException"},
	{"setIssuerUniqueId", "(Ljava/lang/Object;)V", nullptr, $PRIVATE, $method(X509CertInfo, setIssuerUniqueId, void, Object$*), "java.security.cert.CertificateException"},
	{"setKey", "(Ljava/lang/Object;)V", nullptr, $PRIVATE, $method(X509CertInfo, setKey, void, Object$*), "java.security.cert.CertificateException"},
	{"setSerialNumber", "(Ljava/lang/Object;)V", nullptr, $PRIVATE, $method(X509CertInfo, setSerialNumber, void, Object$*), "java.security.cert.CertificateException"},
	{"setSubject", "(Ljava/lang/Object;)V", nullptr, $PRIVATE, $method(X509CertInfo, setSubject, void, Object$*), "java.security.cert.CertificateException"},
	{"setSubjectUniqueId", "(Ljava/lang/Object;)V", nullptr, $PRIVATE, $method(X509CertInfo, setSubjectUniqueId, void, Object$*), "java.security.cert.CertificateException"},
	{"setValidity", "(Ljava/lang/Object;)V", nullptr, $PRIVATE, $method(X509CertInfo, setValidity, void, Object$*), "java.security.cert.CertificateException"},
	{"setVersion", "(Ljava/lang/Object;)V", nullptr, $PRIVATE, $method(X509CertInfo, setVersion, void, Object$*), "java.security.cert.CertificateException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(X509CertInfo, toString, $String*)},
	{"verifyCert", "(Lsun/security/x509/X500Name;Lsun/security/x509/CertificateExtensions;)V", nullptr, $PRIVATE, $method(X509CertInfo, verifyCert, void, $X500Name*, $CertificateExtensions*), "java.security.cert.CertificateParsingException,java.io.IOException"},
	{}
};

$ClassInfo _X509CertInfo_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.x509.X509CertInfo",
	"java.lang.Object",
	"sun.security.x509.CertAttrSet",
	_X509CertInfo_FieldInfo_,
	_X509CertInfo_MethodInfo_,
	"Ljava/lang/Object;Lsun/security/x509/CertAttrSet<Ljava/lang/String;>;"
};

$Object* allocate$X509CertInfo($Class* clazz) {
	return $of($alloc(X509CertInfo));
}

$String* X509CertInfo::IDENT = nullptr;
$String* X509CertInfo::NAME = nullptr;
$String* X509CertInfo::DN_NAME = nullptr;
$String* X509CertInfo::VERSION = nullptr;
$String* X509CertInfo::SERIAL_NUMBER = nullptr;
$String* X509CertInfo::ALGORITHM_ID = nullptr;
$String* X509CertInfo::ISSUER = nullptr;
$String* X509CertInfo::SUBJECT = nullptr;
$String* X509CertInfo::VALIDITY = nullptr;
$String* X509CertInfo::KEY = nullptr;
$String* X509CertInfo::ISSUER_ID = nullptr;
$String* X509CertInfo::SUBJECT_ID = nullptr;
$String* X509CertInfo::EXTENSIONS = nullptr;
$Map* X509CertInfo::map = nullptr;

void X509CertInfo::init$() {
	$set(this, version, $new($CertificateVersion));
	$set(this, serialNum, nullptr);
	$set(this, algId, nullptr);
	$set(this, issuer, nullptr);
	$set(this, subject, nullptr);
	$set(this, interval, nullptr);
	$set(this, pubKey, nullptr);
	$set(this, issuerUniqueId, nullptr);
	$set(this, subjectUniqueId, nullptr);
	$set(this, extensions, nullptr);
	$set(this, rawCertInfo, nullptr);
}

void X509CertInfo::init$($bytes* cert) {
	$set(this, version, $new($CertificateVersion));
	$set(this, serialNum, nullptr);
	$set(this, algId, nullptr);
	$set(this, issuer, nullptr);
	$set(this, subject, nullptr);
	$set(this, interval, nullptr);
	$set(this, pubKey, nullptr);
	$set(this, issuerUniqueId, nullptr);
	$set(this, subjectUniqueId, nullptr);
	$set(this, extensions, nullptr);
	$set(this, rawCertInfo, nullptr);
	try {
		$var($DerValue, in, $new($DerValue, cert));
		parse(in);
	} catch ($IOException& e) {
		$throwNew($CertificateParsingException, static_cast<$Throwable*>(e));
	}
}

void X509CertInfo::init$($DerValue* derVal) {
	$set(this, version, $new($CertificateVersion));
	$set(this, serialNum, nullptr);
	$set(this, algId, nullptr);
	$set(this, issuer, nullptr);
	$set(this, subject, nullptr);
	$set(this, interval, nullptr);
	$set(this, pubKey, nullptr);
	$set(this, issuerUniqueId, nullptr);
	$set(this, subjectUniqueId, nullptr);
	$set(this, extensions, nullptr);
	$set(this, rawCertInfo, nullptr);
	try {
		parse(derVal);
	} catch ($IOException& e) {
		$throwNew($CertificateParsingException, static_cast<$Throwable*>(e));
	}
}

void X509CertInfo::encode($OutputStream* out) {
	$useLocalCurrentObjectStackCache();
	if (this->rawCertInfo == nullptr) {
		$var($DerOutputStream, tmp, $new($DerOutputStream));
		emit(tmp);
		$set(this, rawCertInfo, tmp->toByteArray());
	}
	$nc(out)->write($cast($bytes, $($nc(this->rawCertInfo)->clone())));
}

$Enumeration* X509CertInfo::getElements() {
	$var($AttributeNameEnumeration, elements, $new($AttributeNameEnumeration));
	elements->addElement(X509CertInfo::VERSION);
	elements->addElement(X509CertInfo::SERIAL_NUMBER);
	elements->addElement(X509CertInfo::ALGORITHM_ID);
	elements->addElement(X509CertInfo::ISSUER);
	elements->addElement(X509CertInfo::VALIDITY);
	elements->addElement(X509CertInfo::SUBJECT);
	elements->addElement(X509CertInfo::KEY);
	elements->addElement(X509CertInfo::ISSUER_ID);
	elements->addElement(X509CertInfo::SUBJECT_ID);
	elements->addElement(X509CertInfo::EXTENSIONS);
	return elements->elements();
}

$String* X509CertInfo::getName() {
	return (X509CertInfo::NAME);
}

$bytes* X509CertInfo::getEncodedInfo() {
	$useLocalCurrentObjectStackCache();
	try {
		if (this->rawCertInfo == nullptr) {
			$var($DerOutputStream, tmp, $new($DerOutputStream));
			emit(tmp);
			$set(this, rawCertInfo, tmp->toByteArray());
		}
		return $cast($bytes, $nc(this->rawCertInfo)->clone());
	} catch ($IOException& e) {
		$throwNew($CertificateEncodingException, $(e->toString()));
	} catch ($CertificateException& e) {
		$throwNew($CertificateEncodingException, $(e->toString()));
	}
	$shouldNotReachHere();
}

bool X509CertInfo::equals(Object$* other) {
	if ($instanceOf(X509CertInfo, other)) {
		return equals($cast(X509CertInfo, other));
	} else {
		return false;
	}
}

bool X509CertInfo::equals(X509CertInfo* other) {
	if (this == other) {
		return (true);
	} else if (this->rawCertInfo == nullptr || other->rawCertInfo == nullptr) {
		return (false);
	} else if ($nc(this->rawCertInfo)->length != $nc(other->rawCertInfo)->length) {
		return (false);
	}
	for (int32_t i = 0; i < $nc(this->rawCertInfo)->length; ++i) {
		if ($nc(this->rawCertInfo)->get(i) != $nc($nc(other)->rawCertInfo)->get(i)) {
			return (false);
		}
	}
	return (true);
}

int32_t X509CertInfo::hashCode() {
	int32_t retval = 0;
	for (int32_t i = 1; i < $nc(this->rawCertInfo)->length; ++i) {
		retval += $nc(this->rawCertInfo)->get(i) * i;
	}
	return (retval);
}

$String* X509CertInfo::toString() {
	$useLocalCurrentObjectStackCache();
	if (this->subject == nullptr || this->pubKey == nullptr || this->interval == nullptr || this->issuer == nullptr || this->algId == nullptr || this->serialNum == nullptr) {
		$throwNew($NullPointerException, "X.509 cert is incomplete"_s);
	}
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append("[\n"_s)->append("  "_s)->append($of(this->version))->append(u'\n')->append("  Subject: "_s)->append($of(this->subject))->append(u'\n')->append("  Signature Algorithm: "_s)->append($of(this->algId))->append(u'\n')->append("  Key:  "_s)->append($of(this->pubKey))->append(u'\n')->append("  "_s)->append($of(this->interval))->append(u'\n')->append("  Issuer: "_s)->append($of(this->issuer))->append(u'\n')->append("  "_s)->append($of(this->serialNum))->append(u'\n');
	if (this->issuerUniqueId != nullptr) {
		sb->append("  Issuer Id:\n"_s)->append($of(this->issuerUniqueId))->append(u'\n');
	}
	if (this->subjectUniqueId != nullptr) {
		sb->append("  Subject Id:\n"_s)->append($of(this->subjectUniqueId))->append(u'\n');
	}
	if (this->extensions != nullptr) {
		$var($Collection, allExts, $nc(this->extensions)->getAllExtensions());
		$var($ExtensionArray, exts, $fcast($ExtensionArray, $nc(allExts)->toArray($$new($ExtensionArray, 0))));
		sb->append("\nCertificate Extensions: "_s)->append($nc(exts)->length);
		for (int32_t i = 0; i < $nc(exts)->length; ++i) {
			sb->append("\n["_s)->append(i + 1)->append("]: "_s);
			$var($Extension, ext, exts->get(i));
			try {
				if ($OIDMap::getClass($($nc(ext)->getExtensionId())) == nullptr) {
					sb->append($of(ext));
					$var($bytes, extValue, $nc(ext)->getExtensionValue());
					if (extValue != nullptr) {
						$var($DerOutputStream, out, $new($DerOutputStream));
						out->putOctetString(extValue);
						$assign(extValue, out->toByteArray());
						$var($HexDumpEncoder, enc, $new($HexDumpEncoder));
						sb->append("Extension unknown: "_s)->append("DER encoded OCTET string =\n"_s)->append($(enc->encodeBuffer(extValue)))->append(u'\n');
					}
				} else {
					sb->append($of(ext));
				}
			} catch ($Exception& e) {
				sb->append(", Error parsing this extension"_s);
			}
		}
		$var($Map, invalid, $nc(this->extensions)->getUnparseableExtensions());
		if ($nc(invalid)->isEmpty() == false) {
			sb->append("\nUnparseable certificate extensions: "_s)->append(invalid->size());
			int32_t i = 1;
			{
				$var($Iterator, i$, $nc($(invalid->values()))->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($Extension, ext, $cast($Extension, i$->next()));
					{
						sb->append("\n["_s)->append(i++)->append("]: "_s)->append($of(ext));
					}
				}
			}
		}
	}
	sb->append("\n]"_s);
	return sb->toString();
}

void X509CertInfo::set($String* name, Object$* val) {
	$useLocalCurrentObjectStackCache();
	$var($X509AttributeName, attrName, $new($X509AttributeName, name));
	int32_t attr = attributeMap($(attrName->getPrefix()));
	if (attr == 0) {
		$throwNew($CertificateException, $$str({"Attribute name not recognized: "_s, name}));
	}
	$set(this, rawCertInfo, nullptr);
	$var($String, suffix, attrName->getSuffix());
	switch (attr) {
	case X509CertInfo::ATTR_VERSION:
		{
			if (suffix == nullptr) {
				setVersion(val);
			} else {
				$nc(this->version)->set(suffix, val);
			}
			break;
		}
	case X509CertInfo::ATTR_SERIAL:
		{
			if (suffix == nullptr) {
				setSerialNumber(val);
			} else {
				$nc(this->serialNum)->set(suffix, val);
			}
			break;
		}
	case X509CertInfo::ATTR_ALGORITHM:
		{
			if (suffix == nullptr) {
				setAlgorithmId(val);
			} else {
				$nc(this->algId)->set(suffix, val);
			}
			break;
		}
	case X509CertInfo::ATTR_ISSUER:
		{
			setIssuer(val);
			break;
		}
	case X509CertInfo::ATTR_VALIDITY:
		{
			if (suffix == nullptr) {
				setValidity(val);
			} else {
				$nc(this->interval)->set(suffix, val);
			}
			break;
		}
	case X509CertInfo::ATTR_SUBJECT:
		{
			setSubject(val);
			break;
		}
	case X509CertInfo::ATTR_KEY:
		{
			if (suffix == nullptr) {
				setKey(val);
			} else {
				$nc(this->pubKey)->set(suffix, val);
			}
			break;
		}
	case X509CertInfo::ATTR_ISSUER_ID:
		{
			setIssuerUniqueId(val);
			break;
		}
	case X509CertInfo::ATTR_SUBJECT_ID:
		{
			setSubjectUniqueId(val);
			break;
		}
	case X509CertInfo::ATTR_EXTENSIONS:
		{
			if (suffix == nullptr) {
				setExtensions(val);
			} else {
				if (this->extensions == nullptr) {
					$set(this, extensions, $new($CertificateExtensions));
				}
				$nc(this->extensions)->set(suffix, val);
			}
			break;
		}
	}
}

void X509CertInfo::delete$($String* name) {
	$useLocalCurrentObjectStackCache();
	$var($X509AttributeName, attrName, $new($X509AttributeName, name));
	int32_t attr = attributeMap($(attrName->getPrefix()));
	if (attr == 0) {
		$throwNew($CertificateException, $$str({"Attribute name not recognized: "_s, name}));
	}
	$set(this, rawCertInfo, nullptr);
	$var($String, suffix, attrName->getSuffix());
	do {
		if (attr == X509CertInfo::ATTR_VERSION) {
			goto case$0;
		}
		if (attr == (X509CertInfo::ATTR_SERIAL)) {
			goto case$1;
		}
		if (attr == (X509CertInfo::ATTR_ALGORITHM)) {
			goto case$2;
		}
		if (attr == (X509CertInfo::ATTR_ISSUER)) {
			goto case$3;
		}
		if (attr == (X509CertInfo::ATTR_VALIDITY)) {
			goto case$4;
		}
		if (attr == (X509CertInfo::ATTR_SUBJECT)) {
			goto case$5;
		}
		if (attr == (X509CertInfo::ATTR_KEY)) {
			goto case$6;
		}
		if (attr == (X509CertInfo::ATTR_ISSUER_ID)) {
			goto case$7;
		}
		if (attr == (X509CertInfo::ATTR_SUBJECT_ID)) {
			goto case$8;
		}
		if (attr == (X509CertInfo::ATTR_EXTENSIONS)) {
			goto case$9;
		}
		break;
case$0:
		// ATTR_VERSION
		{
			if (suffix == nullptr) {
				$set(this, version, nullptr);
			} else {
				$nc(this->version)->delete$(suffix);
			}
			break;
		}
case$1:
		// (ATTR_SERIAL)
		{
			if (suffix == nullptr) {
				$set(this, serialNum, nullptr);
			} else {
				$nc(this->serialNum)->delete$(suffix);
			}
			break;
		}
case$2:
		// (ATTR_ALGORITHM)
		{
			if (suffix == nullptr) {
				$set(this, algId, nullptr);
			} else {
				$nc(this->algId)->delete$(suffix);
			}
			break;
		}
case$3:
		// (ATTR_ISSUER)
		{
			$set(this, issuer, nullptr);
			break;
		}
case$4:
		// (ATTR_VALIDITY)
		{
			if (suffix == nullptr) {
				$set(this, interval, nullptr);
			} else {
				$nc(this->interval)->delete$(suffix);
			}
			break;
		}
case$5:
		// (ATTR_SUBJECT)
		{
			$set(this, subject, nullptr);
			break;
		}
case$6:
		// (ATTR_KEY)
		{
			if (suffix == nullptr) {
				$set(this, pubKey, nullptr);
			} else {
				$nc(this->pubKey)->delete$(suffix);
			}
			break;
		}
case$7:
		// (ATTR_ISSUER_ID)
		{
			$set(this, issuerUniqueId, nullptr);
			break;
		}
case$8:
		// (ATTR_SUBJECT_ID)
		{
			$set(this, subjectUniqueId, nullptr);
			break;
		}
case$9:
		// (ATTR_EXTENSIONS)
		{
			if (suffix == nullptr) {
				$set(this, extensions, nullptr);
			} else if (this->extensions != nullptr) {
				$nc(this->extensions)->delete$(suffix);
			}
			break;
		}
	} while (false);
}

$Object* X509CertInfo::get($String* name) {
	$useLocalCurrentObjectStackCache();
	$var($X509AttributeName, attrName, $new($X509AttributeName, name));
	int32_t attr = attributeMap($(attrName->getPrefix()));
	if (attr == 0) {
		$throwNew($CertificateParsingException, $$str({"Attribute name not recognized: "_s, name}));
	}
	$var($String, suffix, attrName->getSuffix());
	do {
		if (attr == (X509CertInfo::ATTR_EXTENSIONS)) {
			goto case$10;
		}
		if (attr == (X509CertInfo::ATTR_SUBJECT)) {
			goto case$11;
		}
		if (attr == (X509CertInfo::ATTR_ISSUER)) {
			goto case$12;
		}
		if (attr == (X509CertInfo::ATTR_KEY)) {
			goto case$13;
		}
		if (attr == (X509CertInfo::ATTR_ALGORITHM)) {
			goto case$14;
		}
		if (attr == (X509CertInfo::ATTR_VALIDITY)) {
			goto case$15;
		}
		if (attr == (X509CertInfo::ATTR_VERSION)) {
			goto case$16;
		}
		if (attr == (X509CertInfo::ATTR_SERIAL)) {
			goto case$17;
		}
		if (attr == (X509CertInfo::ATTR_ISSUER_ID)) {
			goto case$18;
		}
		if (attr == (X509CertInfo::ATTR_SUBJECT_ID)) {
			goto case$19;
		}
		break;
case$10:
		// (ATTR_EXTENSIONS)
		{
			if (suffix == nullptr) {
				return $of((this->extensions));
			} else if (this->extensions == nullptr) {
				return $of(nullptr);
			} else {
				return $of(($nc(this->extensions)->get(suffix)));
			}
		}
case$11:
		// (ATTR_SUBJECT)
		{
			if (suffix == nullptr) {
				return $of((this->subject));
			} else {
				return $of((getX500Name(suffix, false)));
			}
		}
case$12:
		// (ATTR_ISSUER)
		{
			if (suffix == nullptr) {
				return $of((this->issuer));
			} else {
				return $of((getX500Name(suffix, true)));
			}
		}
case$13:
		// (ATTR_KEY)
		{
			if (suffix == nullptr) {
				return $of((this->pubKey));
			} else {
				return $of(($nc(this->pubKey)->get(suffix)));
			}
		}
case$14:
		// (ATTR_ALGORITHM)
		{
			if (suffix == nullptr) {
				return $of((this->algId));
			} else {
				return $of(($nc(this->algId)->get(suffix)));
			}
		}
case$15:
		// (ATTR_VALIDITY)
		{
			if (suffix == nullptr) {
				return $of((this->interval));
			} else {
				return $of(($nc(this->interval)->get(suffix)));
			}
		}
case$16:
		// (ATTR_VERSION)
		{
			if (suffix == nullptr) {
				return $of((this->version));
			} else {
				return $of(($nc(this->version)->get(suffix)));
			}
		}
case$17:
		// (ATTR_SERIAL)
		{
			if (suffix == nullptr) {
				return $of((this->serialNum));
			} else {
				return $of(($nc(this->serialNum)->get(suffix)));
			}
		}
case$18:
		// (ATTR_ISSUER_ID)
		{
			return $of((this->issuerUniqueId));
		}
case$19:
		// (ATTR_SUBJECT_ID)
		{
			return $of((this->subjectUniqueId));
		}
	} while (false);
	return $of(nullptr);
}

$Object* X509CertInfo::getX500Name($String* name, bool getIssuer) {
	if ($nc(name)->equalsIgnoreCase(X509CertInfo::DN_NAME)) {
		return $of(getIssuer ? $of(this->issuer) : $of(this->subject));
	} else if (name->equalsIgnoreCase("x500principal"_s)) {
		return $of(getIssuer ? $of($nc(this->issuer)->asX500Principal()) : $of($nc(this->subject)->asX500Principal()));
	} else {
		$throwNew($IOException, "Attribute name not recognized."_s);
	}
}

void X509CertInfo::parse($DerValue* val) {
	$useLocalCurrentObjectStackCache();
	$var($DerInputStream, in, nullptr);
	$var($DerValue, tmp, nullptr);
	if ($nc(val)->tag != $DerValue::tag_Sequence) {
		$throwNew($CertificateParsingException, "signed fields invalid"_s);
	}
	$set(this, rawCertInfo, $nc(val)->toByteArray());
	$assign(in, val->data$);
	$assign(tmp, $nc(in)->getDerValue());
	if ($nc(tmp)->isContextSpecific((int8_t)0)) {
		$set(this, version, $new($CertificateVersion, tmp));
		$assign(tmp, in->getDerValue());
	}
	$set(this, serialNum, $new($CertificateSerialNumber, tmp));
	$set(this, algId, $new($CertificateAlgorithmId, in));
	$set(this, issuer, $new($X500Name, in));
	if ($nc(this->issuer)->isEmpty()) {
		$throwNew($CertificateParsingException, "Empty issuer DN not allowed in X509Certificates"_s);
	}
	$set(this, interval, $new($CertificateValidity, in));
	$set(this, subject, $new($X500Name, in));
	bool var$0 = ($nc(this->version)->compare($CertificateVersion::V1) == 0);
	if (var$0 && $nc(this->subject)->isEmpty()) {
		$throwNew($CertificateParsingException, "Empty subject DN not allowed in v1 certificate"_s);
	}
	$set(this, pubKey, $new($CertificateX509Key, in));
	if (in->available() != 0) {
		if ($nc(this->version)->compare($CertificateVersion::V1) == 0) {
			$throwNew($CertificateParsingException, "no more data allowed for version 1 certificate"_s);
		}
	} else {
		return;
	}
	$assign(tmp, in->getDerValue());
	if ($nc(tmp)->isContextSpecific((int8_t)1)) {
		$set(this, issuerUniqueId, $new($UniqueIdentity, tmp));
		if (in->available() == 0) {
			return;
		}
		$assign(tmp, in->getDerValue());
	}
	if ($nc(tmp)->isContextSpecific((int8_t)2)) {
		$set(this, subjectUniqueId, $new($UniqueIdentity, tmp));
		if (in->available() == 0) {
			return;
		}
		$assign(tmp, in->getDerValue());
	}
	if ($nc(this->version)->compare($CertificateVersion::V3) != 0) {
		$throwNew($CertificateParsingException, "Extensions not allowed in v2 certificate"_s);
	}
	bool var$1 = $nc(tmp)->isConstructed();
	if (var$1 && tmp->isContextSpecific((int8_t)3)) {
		$set(this, extensions, $new($CertificateExtensions, tmp->data$));
	}
	verifyCert(this->subject, this->extensions);
}

void X509CertInfo::verifyCert($X500Name* subject, $CertificateExtensions* extensions) {
	$useLocalCurrentObjectStackCache();
	if ($nc(subject)->isEmpty()) {
		if (extensions == nullptr) {
			$throwNew($CertificateParsingException, "X.509 Certificate is incomplete: subject field is empty, and certificate has no extensions"_s);
		}
		$var($SubjectAlternativeNameExtension, subjectAltNameExt, nullptr);
		$var($SubjectAlternativeNameExtension, extValue, nullptr);
		$var($GeneralNames, names, nullptr);
		try {
			$init($SubjectAlternativeNameExtension);
			$assign(subjectAltNameExt, $cast($SubjectAlternativeNameExtension, $cast($Extension, $nc(extensions)->get($SubjectAlternativeNameExtension::NAME))));
			$assign(names, $cast($GeneralNames, $nc(subjectAltNameExt)->get($SubjectAlternativeNameExtension::SUBJECT_NAME)));
		} catch ($IOException& e) {
			$throwNew($CertificateParsingException, "X.509 Certificate is incomplete: subject field is empty, and SubjectAlternativeName extension is absent"_s);
		}
		if (names == nullptr || $nc(names)->isEmpty()) {
			$throwNew($CertificateParsingException, "X.509 Certificate is incomplete: subject field is empty, and SubjectAlternativeName extension is empty"_s);
		} else if ($nc(subjectAltNameExt)->isCritical() == false) {
			$throwNew($CertificateParsingException, "X.509 Certificate is incomplete: SubjectAlternativeName extension MUST be marked critical when subject field is empty"_s);
		}
	}
}

void X509CertInfo::emit($DerOutputStream* out) {
	$var($DerOutputStream, tmp, $new($DerOutputStream));
	$nc(this->version)->encode(tmp);
	$nc(this->serialNum)->encode(tmp);
	$nc(this->algId)->encode(tmp);
	bool var$0 = ($nc(this->version)->compare($CertificateVersion::V1) == 0);
	if (var$0 && ($nc(this->issuer)->toString() == nullptr)) {
		$throwNew($CertificateParsingException, "Null issuer DN not allowed in v1 certificate"_s);
	}
	$nc(this->issuer)->encode(tmp);
	$nc(this->interval)->encode(tmp);
	bool var$1 = ($nc(this->version)->compare($CertificateVersion::V1) == 0);
	if (var$1 && ($nc(this->subject)->toString() == nullptr)) {
		$throwNew($CertificateParsingException, "Null subject DN not allowed in v1 certificate"_s);
	}
	$nc(this->subject)->encode(tmp);
	$nc(this->pubKey)->encode(tmp);
	if (this->issuerUniqueId != nullptr) {
		$nc(this->issuerUniqueId)->encode(tmp, $DerValue::createTag($DerValue::TAG_CONTEXT, false, (int8_t)1));
	}
	if (this->subjectUniqueId != nullptr) {
		$nc(this->subjectUniqueId)->encode(tmp, $DerValue::createTag($DerValue::TAG_CONTEXT, false, (int8_t)2));
	}
	if (this->extensions != nullptr) {
		$nc(this->extensions)->encode(tmp);
	}
	$nc(out)->write($DerValue::tag_Sequence, tmp);
}

int32_t X509CertInfo::attributeMap($String* name) {
	$var($Integer, num, $cast($Integer, $nc(X509CertInfo::map)->get(name)));
	if (num == nullptr) {
		return 0;
	}
	return $nc(num)->intValue();
}

void X509CertInfo::setVersion(Object$* val) {
	if (!($instanceOf($CertificateVersion, val))) {
		$throwNew($CertificateException, "Version class type invalid."_s);
	}
	$set(this, version, $cast($CertificateVersion, val));
}

void X509CertInfo::setSerialNumber(Object$* val) {
	if (!($instanceOf($CertificateSerialNumber, val))) {
		$throwNew($CertificateException, "SerialNumber class type invalid."_s);
	}
	$set(this, serialNum, $cast($CertificateSerialNumber, val));
}

void X509CertInfo::setAlgorithmId(Object$* val) {
	if (!($instanceOf($CertificateAlgorithmId, val))) {
		$throwNew($CertificateException, "AlgorithmId class type invalid."_s);
	}
	$set(this, algId, $cast($CertificateAlgorithmId, val));
}

void X509CertInfo::setIssuer(Object$* val) {
	if (!($instanceOf($X500Name, val))) {
		$throwNew($CertificateException, "Issuer class type invalid."_s);
	}
	$set(this, issuer, $cast($X500Name, val));
}

void X509CertInfo::setValidity(Object$* val) {
	if (!($instanceOf($CertificateValidity, val))) {
		$throwNew($CertificateException, "CertificateValidity class type invalid."_s);
	}
	$set(this, interval, $cast($CertificateValidity, val));
}

void X509CertInfo::setSubject(Object$* val) {
	if (!($instanceOf($X500Name, val))) {
		$throwNew($CertificateException, "Subject class type invalid."_s);
	}
	$set(this, subject, $cast($X500Name, val));
}

void X509CertInfo::setKey(Object$* val) {
	if (!($instanceOf($CertificateX509Key, val))) {
		$throwNew($CertificateException, "Key class type invalid."_s);
	}
	$set(this, pubKey, $cast($CertificateX509Key, val));
}

void X509CertInfo::setIssuerUniqueId(Object$* val) {
	if ($nc(this->version)->compare($CertificateVersion::V2) < 0) {
		$throwNew($CertificateException, "Invalid version"_s);
	}
	if (!($instanceOf($UniqueIdentity, val))) {
		$throwNew($CertificateException, "IssuerUniqueId class type invalid."_s);
	}
	$set(this, issuerUniqueId, $cast($UniqueIdentity, val));
}

void X509CertInfo::setSubjectUniqueId(Object$* val) {
	if ($nc(this->version)->compare($CertificateVersion::V2) < 0) {
		$throwNew($CertificateException, "Invalid version"_s);
	}
	if (!($instanceOf($UniqueIdentity, val))) {
		$throwNew($CertificateException, "SubjectUniqueId class type invalid."_s);
	}
	$set(this, subjectUniqueId, $cast($UniqueIdentity, val));
}

void X509CertInfo::setExtensions(Object$* val) {
	if ($nc(this->version)->compare($CertificateVersion::V3) < 0) {
		$throwNew($CertificateException, "Invalid version"_s);
	}
	if (!($instanceOf($CertificateExtensions, val))) {
		$throwNew($CertificateException, "Extensions class type invalid."_s);
	}
	$set(this, extensions, $cast($CertificateExtensions, val));
}

void clinit$X509CertInfo($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(X509CertInfo::IDENT, "x509.info"_s);
	$assignStatic(X509CertInfo::NAME, "info"_s);
	$assignStatic(X509CertInfo::DN_NAME, "dname"_s);
	$init($CertificateVersion);
	$assignStatic(X509CertInfo::VERSION, $CertificateVersion::NAME);
	$init($CertificateSerialNumber);
	$assignStatic(X509CertInfo::SERIAL_NUMBER, $CertificateSerialNumber::NAME);
	$init($CertificateAlgorithmId);
	$assignStatic(X509CertInfo::ALGORITHM_ID, $CertificateAlgorithmId::NAME);
	$assignStatic(X509CertInfo::ISSUER, "issuer"_s);
	$assignStatic(X509CertInfo::SUBJECT, "subject"_s);
	$init($CertificateValidity);
	$assignStatic(X509CertInfo::VALIDITY, $CertificateValidity::NAME);
	$init($CertificateX509Key);
	$assignStatic(X509CertInfo::KEY, $CertificateX509Key::NAME);
	$assignStatic(X509CertInfo::ISSUER_ID, "issuerID"_s);
	$assignStatic(X509CertInfo::SUBJECT_ID, "subjectID"_s);
	$init($CertificateExtensions);
	$assignStatic(X509CertInfo::EXTENSIONS, $CertificateExtensions::NAME);
	$assignStatic(X509CertInfo::map, $new($HashMap));
	{
		$nc(X509CertInfo::map)->put(X509CertInfo::VERSION, $($Integer::valueOf(X509CertInfo::ATTR_VERSION)));
		$nc(X509CertInfo::map)->put(X509CertInfo::SERIAL_NUMBER, $($Integer::valueOf(X509CertInfo::ATTR_SERIAL)));
		$nc(X509CertInfo::map)->put(X509CertInfo::ALGORITHM_ID, $($Integer::valueOf(X509CertInfo::ATTR_ALGORITHM)));
		$nc(X509CertInfo::map)->put(X509CertInfo::ISSUER, $($Integer::valueOf(X509CertInfo::ATTR_ISSUER)));
		$nc(X509CertInfo::map)->put(X509CertInfo::VALIDITY, $($Integer::valueOf(X509CertInfo::ATTR_VALIDITY)));
		$nc(X509CertInfo::map)->put(X509CertInfo::SUBJECT, $($Integer::valueOf(X509CertInfo::ATTR_SUBJECT)));
		$nc(X509CertInfo::map)->put(X509CertInfo::KEY, $($Integer::valueOf(X509CertInfo::ATTR_KEY)));
		$nc(X509CertInfo::map)->put(X509CertInfo::ISSUER_ID, $($Integer::valueOf(X509CertInfo::ATTR_ISSUER_ID)));
		$nc(X509CertInfo::map)->put(X509CertInfo::SUBJECT_ID, $($Integer::valueOf(X509CertInfo::ATTR_SUBJECT_ID)));
		$nc(X509CertInfo::map)->put(X509CertInfo::EXTENSIONS, $($Integer::valueOf(X509CertInfo::ATTR_EXTENSIONS)));
	}
}

X509CertInfo::X509CertInfo() {
}

$Class* X509CertInfo::load$($String* name, bool initialize) {
	$loadClass(X509CertInfo, name, initialize, &_X509CertInfo_ClassInfo_, clinit$X509CertInfo, allocate$X509CertInfo);
	return class$;
}

$Class* X509CertInfo::class$ = nullptr;

		} // x509
	} // security
} // sun