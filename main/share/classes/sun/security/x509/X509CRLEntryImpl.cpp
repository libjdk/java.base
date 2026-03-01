#include <sun/security/x509/X509CRLEntryImpl.h>

#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <java/math/BigInteger.h>
#include <java/security/cert/CRLException.h>
#include <java/security/cert/CRLReason.h>
#include <java/security/cert/X509CRLEntry.h>
#include <java/security/cert/X509Extension.h>
#include <java/util/AbstractMap.h>
#include <java/util/AbstractSet.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Date.h>
#include <java/util/Enumeration.h>
#include <java/util/Iterator.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/TreeMap.h>
#include <java/util/TreeSet.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/HexDumpEncoder.h>
#include <sun/security/util/KnownOIDs.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <sun/security/x509/CRLExtensions.h>
#include <sun/security/x509/CRLReasonCodeExtension.h>
#include <sun/security/x509/CertificateIssuerExtension.h>
#include <sun/security/x509/CertificateValidity.h>
#include <sun/security/x509/Extension.h>
#include <sun/security/x509/OIDMap.h>
#include <sun/security/x509/PKIXExtensions.h>
#include <sun/security/x509/SerialNumber.h>
#include <jcpp.h>

#undef FALSE
#undef REASON

using $ExtensionArray = $Array<::sun::security::x509::Extension>;
using $IOException = ::java::io::IOException;
using $OutputStream = ::java::io::OutputStream;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $BigInteger = ::java::math::BigInteger;
using $CRLException = ::java::security::cert::CRLException;
using $CRLReason = ::java::security::cert::CRLReason;
using $X509CRLEntry = ::java::security::cert::X509CRLEntry;
using $AbstractMap = ::java::util::AbstractMap;
using $AbstractSet = ::java::util::AbstractSet;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Date = ::java::util::Date;
using $Enumeration = ::java::util::Enumeration;
using $Iterator = ::java::util::Iterator;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $TreeMap = ::java::util::TreeMap;
using $TreeSet = ::java::util::TreeSet;
using $X500Principal = ::javax::security::auth::x500::X500Principal;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;
using $HexDumpEncoder = ::sun::security::util::HexDumpEncoder;
using $KnownOIDs = ::sun::security::util::KnownOIDs;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;
using $CRLExtensions = ::sun::security::x509::CRLExtensions;
using $CRLReasonCodeExtension = ::sun::security::x509::CRLReasonCodeExtension;
using $CertificateIssuerExtension = ::sun::security::x509::CertificateIssuerExtension;
using $CertificateValidity = ::sun::security::x509::CertificateValidity;
using $Extension = ::sun::security::x509::Extension;
using $OIDMap = ::sun::security::x509::OIDMap;
using $PKIXExtensions = ::sun::security::x509::PKIXExtensions;
using $SerialNumber = ::sun::security::x509::SerialNumber;

namespace sun {
	namespace security {
		namespace x509 {

$FieldInfo _X509CRLEntryImpl_FieldInfo_[] = {
	{"serialNumber", "Lsun/security/x509/SerialNumber;", nullptr, $PRIVATE, $field(X509CRLEntryImpl, serialNumber)},
	{"revocationDate", "Ljava/util/Date;", nullptr, $PRIVATE, $field(X509CRLEntryImpl, revocationDate)},
	{"extensions", "Lsun/security/x509/CRLExtensions;", nullptr, $PRIVATE, $field(X509CRLEntryImpl, extensions)},
	{"revokedCert", "[B", nullptr, $PRIVATE, $field(X509CRLEntryImpl, revokedCert)},
	{"certIssuer", "Ljavax/security/auth/x500/X500Principal;", nullptr, $PRIVATE, $field(X509CRLEntryImpl, certIssuer)},
	{"isExplicit", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(X509CRLEntryImpl, isExplicit)},
	{}
};

$MethodInfo _X509CRLEntryImpl_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC},
	{"<init>", "(Ljava/math/BigInteger;Ljava/util/Date;)V", nullptr, $PUBLIC, $method(X509CRLEntryImpl, init$, void, $BigInteger*, $Date*)},
	{"<init>", "(Ljava/math/BigInteger;Ljava/util/Date;Lsun/security/x509/CRLExtensions;)V", nullptr, $PUBLIC, $method(X509CRLEntryImpl, init$, void, $BigInteger*, $Date*, $CRLExtensions*)},
	{"<init>", "([B)V", nullptr, $PUBLIC, $method(X509CRLEntryImpl, init$, void, $bytes*), "java.security.cert.CRLException"},
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(X509CRLEntryImpl, init$, void, $DerValue*), "java.security.cert.CRLException"},
	{"compareTo", "(Lsun/security/x509/X509CRLEntryImpl;)I", nullptr, $PUBLIC, $virtualMethod(X509CRLEntryImpl, compareTo, int32_t, X509CRLEntryImpl*)},
	{"compareTo", "(Ljava/lang/Object;)I", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(X509CRLEntryImpl, compareTo, int32_t, Object$*)},
	{"encode", "(Lsun/security/util/DerOutputStream;)V", nullptr, $PUBLIC, $virtualMethod(X509CRLEntryImpl, encode, void, $DerOutputStream*), "java.security.cert.CRLException"},
	{"getCertificateIssuer", "()Ljavax/security/auth/x500/X500Principal;", nullptr, $PUBLIC, $virtualMethod(X509CRLEntryImpl, getCertificateIssuer, $X500Principal*)},
	{"getCertificateIssuerExtension", "()Lsun/security/x509/CertificateIssuerExtension;", nullptr, 0, $virtualMethod(X509CRLEntryImpl, getCertificateIssuerExtension, $CertificateIssuerExtension*)},
	{"getCriticalExtensionOIDs", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(X509CRLEntryImpl, getCriticalExtensionOIDs, $Set*)},
	{"getEncoded", "()[B", nullptr, $PUBLIC, $virtualMethod(X509CRLEntryImpl, getEncoded, $bytes*), "java.security.cert.CRLException"},
	{"getEncoded0", "()[B", nullptr, $PRIVATE, $method(X509CRLEntryImpl, getEncoded0, $bytes*), "java.security.cert.CRLException"},
	{"getExtension", "(Lsun/security/util/ObjectIdentifier;)Lsun/security/x509/Extension;", nullptr, $PUBLIC, $virtualMethod(X509CRLEntryImpl, getExtension, $Extension*, $ObjectIdentifier*)},
	{"getExtensionValue", "(Ljava/lang/String;)[B", nullptr, $PUBLIC, $virtualMethod(X509CRLEntryImpl, getExtensionValue, $bytes*, $String*)},
	{"getExtensions", "()Ljava/util/Map;", "()Ljava/util/Map<Ljava/lang/String;Ljava/security/cert/Extension;>;", $PUBLIC, $virtualMethod(X509CRLEntryImpl, getExtensions, $Map*)},
	{"getNonCriticalExtensionOIDs", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(X509CRLEntryImpl, getNonCriticalExtensionOIDs, $Set*)},
	{"getReasonCode", "()Ljava/lang/Integer;", nullptr, $PUBLIC, $virtualMethod(X509CRLEntryImpl, getReasonCode, $Integer*), "java.io.IOException"},
	{"getRevocationDate", "()Ljava/util/Date;", nullptr, $PUBLIC, $virtualMethod(X509CRLEntryImpl, getRevocationDate, $Date*)},
	{"getRevocationReason", "()Ljava/security/cert/CRLReason;", nullptr, $PUBLIC, $virtualMethod(X509CRLEntryImpl, getRevocationReason, $CRLReason*)},
	{"getRevocationReason", "(Ljava/security/cert/X509CRLEntry;)Ljava/security/cert/CRLReason;", nullptr, $PUBLIC | $STATIC, $staticMethod(X509CRLEntryImpl, getRevocationReason, $CRLReason*, $X509CRLEntry*)},
	{"getSerialNumber", "()Ljava/math/BigInteger;", nullptr, $PUBLIC, $virtualMethod(X509CRLEntryImpl, getSerialNumber, $BigInteger*)},
	{"hasExtensions", "()Z", nullptr, $PUBLIC, $virtualMethod(X509CRLEntryImpl, hasExtensions, bool)},
	{"hasUnsupportedCriticalExtension", "()Z", nullptr, $PUBLIC, $virtualMethod(X509CRLEntryImpl, hasUnsupportedCriticalExtension, bool)},
	{"parse", "(Lsun/security/util/DerValue;)V", nullptr, $PRIVATE, $method(X509CRLEntryImpl, parse, void, $DerValue*), "java.security.cert.CRLException,java.io.IOException"},
	{"setCertificateIssuer", "(Ljavax/security/auth/x500/X500Principal;Ljavax/security/auth/x500/X500Principal;)V", nullptr, 0, $virtualMethod(X509CRLEntryImpl, setCertificateIssuer, void, $X500Principal*, $X500Principal*)},
	{"toImpl", "(Ljava/security/cert/X509CRLEntry;)Lsun/security/x509/X509CRLEntryImpl;", nullptr, $PUBLIC | $STATIC, $staticMethod(X509CRLEntryImpl, toImpl, X509CRLEntryImpl*, $X509CRLEntry*), "java.security.cert.CRLException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(X509CRLEntryImpl, toString, $String*)},
	{}
};

$ClassInfo _X509CRLEntryImpl_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.x509.X509CRLEntryImpl",
	"java.security.cert.X509CRLEntry",
	"java.lang.Comparable",
	_X509CRLEntryImpl_FieldInfo_,
	_X509CRLEntryImpl_MethodInfo_,
	"Ljava/security/cert/X509CRLEntry;Ljava/lang/Comparable<Lsun/security/x509/X509CRLEntryImpl;>;"
};

$Object* allocate$X509CRLEntryImpl($Class* clazz) {
	return $of($alloc(X509CRLEntryImpl));
}

bool X509CRLEntryImpl::equals(Object$* other) {
	 return this->$X509CRLEntry::equals(other);
}

int32_t X509CRLEntryImpl::hashCode() {
	 return this->$X509CRLEntry::hashCode();
}

$Object* X509CRLEntryImpl::clone() {
	 return this->$X509CRLEntry::clone();
}

void X509CRLEntryImpl::finalize() {
	this->$X509CRLEntry::finalize();
}

void X509CRLEntryImpl::init$($BigInteger* num, $Date* date) {
	$X509CRLEntry::init$();
	$set(this, serialNumber, nullptr);
	$set(this, revocationDate, nullptr);
	$set(this, extensions, nullptr);
	$set(this, revokedCert, nullptr);
	$set(this, serialNumber, $new($SerialNumber, num));
	$set(this, revocationDate, date);
}

void X509CRLEntryImpl::init$($BigInteger* num, $Date* date, $CRLExtensions* crlEntryExts) {
	$X509CRLEntry::init$();
	$set(this, serialNumber, nullptr);
	$set(this, revocationDate, nullptr);
	$set(this, extensions, nullptr);
	$set(this, revokedCert, nullptr);
	$set(this, serialNumber, $new($SerialNumber, num));
	$set(this, revocationDate, date);
	$set(this, extensions, crlEntryExts);
}

void X509CRLEntryImpl::init$($bytes* revokedCert) {
	$useLocalCurrentObjectStackCache();
	$X509CRLEntry::init$();
	$set(this, serialNumber, nullptr);
	$set(this, revocationDate, nullptr);
	$set(this, extensions, nullptr);
	$set(this, revokedCert, nullptr);
	try {
		parse($$new($DerValue, revokedCert));
	} catch ($IOException& e) {
		$set(this, revokedCert, nullptr);
		$throwNew($CRLException, $$str({"Parsing error: "_s, $(e->toString())}));
	}
}

void X509CRLEntryImpl::init$($DerValue* derValue) {
	$useLocalCurrentObjectStackCache();
	$X509CRLEntry::init$();
	$set(this, serialNumber, nullptr);
	$set(this, revocationDate, nullptr);
	$set(this, extensions, nullptr);
	$set(this, revokedCert, nullptr);
	try {
		parse(derValue);
	} catch ($IOException& e) {
		$set(this, revokedCert, nullptr);
		$throwNew($CRLException, $$str({"Parsing error: "_s, $(e->toString())}));
	}
}

bool X509CRLEntryImpl::hasExtensions() {
	return (this->extensions != nullptr);
}

void X509CRLEntryImpl::encode($DerOutputStream* outStrm) {
	$useLocalCurrentObjectStackCache();
	try {
		if (this->revokedCert == nullptr) {
			$var($DerOutputStream, tmp, $new($DerOutputStream));
			$nc(this->serialNumber)->encode(tmp);
			if ($nc(this->revocationDate)->getTime() < $CertificateValidity::YR_2050) {
				tmp->putUTCTime(this->revocationDate);
			} else {
				tmp->putGeneralizedTime(this->revocationDate);
			}
			if (this->extensions != nullptr) {
				$nc(this->extensions)->encode(tmp, X509CRLEntryImpl::isExplicit);
			}
			$var($DerOutputStream, seq, $new($DerOutputStream));
			seq->write($DerValue::tag_Sequence, tmp);
			$set(this, revokedCert, seq->toByteArray());
		}
		$nc(outStrm)->write(this->revokedCert);
	} catch ($IOException& e) {
		$throwNew($CRLException, $$str({"Encoding error: "_s, $(e->toString())}));
	}
}

$bytes* X509CRLEntryImpl::getEncoded() {
	return $cast($bytes, $nc($(getEncoded0()))->clone());
}

$bytes* X509CRLEntryImpl::getEncoded0() {
	if (this->revokedCert == nullptr) {
		this->encode($$new($DerOutputStream));
	}
	return this->revokedCert;
}

$X500Principal* X509CRLEntryImpl::getCertificateIssuer() {
	return this->certIssuer;
}

void X509CRLEntryImpl::setCertificateIssuer($X500Principal* crlIssuer, $X500Principal* certIssuer) {
	if ($nc(crlIssuer)->equals(certIssuer)) {
		$set(this, certIssuer, nullptr);
	} else {
		$set(this, certIssuer, certIssuer);
	}
}

$BigInteger* X509CRLEntryImpl::getSerialNumber() {
	return $nc(this->serialNumber)->getNumber();
}

$Date* X509CRLEntryImpl::getRevocationDate() {
	return $new($Date, $nc(this->revocationDate)->getTime());
}

$CRLReason* X509CRLEntryImpl::getRevocationReason() {
	$useLocalCurrentObjectStackCache();
	$init($PKIXExtensions);
	$var($Extension, ext, getExtension($PKIXExtensions::ReasonCode_Id));
	if (ext == nullptr) {
		return nullptr;
	}
	$var($CRLReasonCodeExtension, rcExt, $cast($CRLReasonCodeExtension, ext));
	return $nc(rcExt)->getReasonCode();
}

$CRLReason* X509CRLEntryImpl::getRevocationReason($X509CRLEntry* crlEntry) {
	$init(X509CRLEntryImpl);
	$useLocalCurrentObjectStackCache();
	try {
		$init($KnownOIDs);
		$var($bytes, ext, $nc(crlEntry)->getExtensionValue($($KnownOIDs::ReasonCode->value())));
		if (ext == nullptr) {
			return nullptr;
		}
		$var($DerValue, val, $new($DerValue, ext));
		$var($bytes, data, val->getOctetString());
		$init($Boolean);
		$var($CRLReasonCodeExtension, rcExt, $new($CRLReasonCodeExtension, $Boolean::FALSE, $of(data)));
		return rcExt->getReasonCode();
	} catch ($IOException& ioe) {
		return nullptr;
	}
	$shouldNotReachHere();
}

$Integer* X509CRLEntryImpl::getReasonCode() {
	$useLocalCurrentObjectStackCache();
	$init($PKIXExtensions);
	$var($Object, obj, getExtension($PKIXExtensions::ReasonCode_Id));
	if (obj == nullptr) {
		return nullptr;
	}
	$var($CRLReasonCodeExtension, reasonCode, $cast($CRLReasonCodeExtension, obj));
	$init($CRLReasonCodeExtension);
	return $cast($Integer, $nc(reasonCode)->get($CRLReasonCodeExtension::REASON));
}

$String* X509CRLEntryImpl::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append($of(this->serialNumber))->append("  On: "_s)->append($of(this->revocationDate));
	if (this->certIssuer != nullptr) {
		sb->append("\n    Certificate issuer: "_s)->append($of(this->certIssuer));
	}
	if (this->extensions != nullptr) {
		$var($Collection, allEntryExts, $nc(this->extensions)->getAllExtensions());
		$var($ExtensionArray, exts, $fcast($ExtensionArray, $nc(allEntryExts)->toArray($$new($ExtensionArray, 0))));
		sb->append("\n    CRL Entry Extensions: "_s)->append($nc(exts)->length);
		for (int32_t i = 0; i < $nc(exts)->length; ++i) {
			sb->append("\n    ["_s)->append(i + 1)->append("]: "_s);
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
	}
	sb->append(u'\n');
	return sb->toString();
}

bool X509CRLEntryImpl::hasUnsupportedCriticalExtension() {
	if (this->extensions == nullptr) {
		return false;
	}
	return $nc(this->extensions)->hasUnsupportedCriticalExtension();
}

$Set* X509CRLEntryImpl::getCriticalExtensionOIDs() {
	$useLocalCurrentObjectStackCache();
	if (this->extensions == nullptr) {
		return nullptr;
	}
	$var($Set, extSet, static_cast<$Set*>(static_cast<$AbstractSet*>($new($TreeSet))));
	{
		$var($Iterator, i$, $nc($($nc(this->extensions)->getAllExtensions()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Extension, ex, $cast($Extension, i$->next()));
			{
				if ($nc(ex)->isCritical()) {
					extSet->add($($nc($(ex->getExtensionId()))->toString()));
				}
			}
		}
	}
	return extSet;
}

$Set* X509CRLEntryImpl::getNonCriticalExtensionOIDs() {
	$useLocalCurrentObjectStackCache();
	if (this->extensions == nullptr) {
		return nullptr;
	}
	$var($Set, extSet, static_cast<$Set*>(static_cast<$AbstractSet*>($new($TreeSet))));
	{
		$var($Iterator, i$, $nc($($nc(this->extensions)->getAllExtensions()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Extension, ex, $cast($Extension, i$->next()));
			{
				if (!$nc(ex)->isCritical()) {
					extSet->add($($nc($(ex->getExtensionId()))->toString()));
				}
			}
		}
	}
	return extSet;
}

$bytes* X509CRLEntryImpl::getExtensionValue($String* oid) {
	$useLocalCurrentObjectStackCache();
	if (this->extensions == nullptr) {
		return nullptr;
	}
	try {
		$var($String, extAlias, $OIDMap::getName($($ObjectIdentifier::of(oid))));
		$var($Extension, crlExt, nullptr);
		if (extAlias == nullptr) {
			$var($ObjectIdentifier, findOID, $ObjectIdentifier::of(oid));
			$var($Extension, ex, nullptr);
			$var($ObjectIdentifier, inCertOID, nullptr);
			{
				$var($Enumeration, e, $nc(this->extensions)->getElements());
				for (; $nc(e)->hasMoreElements();) {
					$assign(ex, $cast($Extension, e->nextElement()));
					$assign(inCertOID, $nc(ex)->getExtensionId());
					if ($nc(inCertOID)->equals(findOID)) {
						$assign(crlExt, ex);
						break;
					}
				}
			}
		} else {
			$assign(crlExt, $nc(this->extensions)->get(extAlias));
		}
		if (crlExt == nullptr) {
			return nullptr;
		}
		$var($bytes, extData, $nc(crlExt)->getExtensionValue());
		if (extData == nullptr) {
			return nullptr;
		}
		$var($DerOutputStream, out, $new($DerOutputStream));
		out->putOctetString(extData);
		return out->toByteArray();
	} catch ($Exception& e) {
		return nullptr;
	}
	$shouldNotReachHere();
}

$Extension* X509CRLEntryImpl::getExtension($ObjectIdentifier* oid) {
	if (this->extensions == nullptr) {
		return nullptr;
	}
	return $nc(this->extensions)->get($($OIDMap::getName(oid)));
}

void X509CRLEntryImpl::parse($DerValue* derVal) {
	$useLocalCurrentObjectStackCache();
	if ($nc(derVal)->tag != $DerValue::tag_Sequence) {
		$throwNew($CRLException, "Invalid encoded RevokedCertificate, starting sequence tag missing."_s);
	}
	if ($nc($nc(derVal)->data$)->available() == 0) {
		$throwNew($CRLException, "No data encoded for RevokedCertificates"_s);
	}
	$set(this, revokedCert, $nc(derVal)->toByteArray());
	$var($DerInputStream, in, derVal->toDerInputStream());
	$var($DerValue, val, $nc(in)->getDerValue());
	$set(this, serialNumber, $new($SerialNumber, val));
	int32_t nextByte = $nc(derVal->data$)->peekByte();
	if ((int8_t)nextByte == $DerValue::tag_UtcTime) {
		$set(this, revocationDate, $nc(derVal->data$)->getUTCTime());
	} else if ((int8_t)nextByte == $DerValue::tag_GeneralizedTime) {
		$set(this, revocationDate, $nc(derVal->data$)->getGeneralizedTime());
	} else {
		$throwNew($CRLException, "Invalid encoding for revocation date"_s);
	}
	if ($nc(derVal->data$)->available() == 0) {
		return;
	}
	$set(this, extensions, $new($CRLExtensions, $(derVal->toDerInputStream())));
}

X509CRLEntryImpl* X509CRLEntryImpl::toImpl($X509CRLEntry* entry) {
	$init(X509CRLEntryImpl);
	if ($instanceOf(X509CRLEntryImpl, entry)) {
		return $cast(X509CRLEntryImpl, entry);
	} else {
		return $new(X509CRLEntryImpl, $($nc(entry)->getEncoded()));
	}
}

$CertificateIssuerExtension* X509CRLEntryImpl::getCertificateIssuerExtension() {
	$init($PKIXExtensions);
	return $cast($CertificateIssuerExtension, getExtension($PKIXExtensions::CertificateIssuer_Id));
}

$Map* X509CRLEntryImpl::getExtensions() {
	$useLocalCurrentObjectStackCache();
	if (this->extensions == nullptr) {
		return $Collections::emptyMap();
	}
	$var($Collection, exts, $nc(this->extensions)->getAllExtensions());
	$var($Map, map, static_cast<$Map*>(static_cast<$AbstractMap*>($new($TreeMap))));
	{
		$var($Iterator, i$, $nc(exts)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Extension, ext, $cast($Extension, i$->next()));
			{
				map->put($($nc(ext)->getId()), ext);
			}
		}
	}
	return map;
}

int32_t X509CRLEntryImpl::compareTo(X509CRLEntryImpl* that) {
	$useLocalCurrentObjectStackCache();
	int32_t compSerial = $nc($(getSerialNumber()))->compareTo($($nc(that)->getSerialNumber()));
	if (compSerial != 0) {
		return compSerial;
	}
	try {
		$var($bytes, thisEncoded, this->getEncoded0());
		$var($bytes, thatEncoded, $nc(that)->getEncoded0());
		for (int32_t i = 0; i < $nc(thisEncoded)->length && i < $nc(thatEncoded)->length; ++i) {
			int32_t a = (int32_t)(thisEncoded->get(i) & (uint32_t)255);
			int32_t b = (int32_t)(thatEncoded->get(i) & (uint32_t)255);
			if (a != b) {
				return a - b;
			}
		}
		return $nc(thisEncoded)->length - $nc(thatEncoded)->length;
	} catch ($CRLException& ce) {
		return -1;
	}
	$shouldNotReachHere();
}

int32_t X509CRLEntryImpl::compareTo(Object$* that) {
	return this->compareTo($cast(X509CRLEntryImpl, that));
}

X509CRLEntryImpl::X509CRLEntryImpl() {
}

$Class* X509CRLEntryImpl::load$($String* name, bool initialize) {
	$loadClass(X509CRLEntryImpl, name, initialize, &_X509CRLEntryImpl_ClassInfo_, allocate$X509CRLEntryImpl);
	return class$;
}

$Class* X509CRLEntryImpl::class$ = nullptr;

		} // x509
	} // security
} // sun