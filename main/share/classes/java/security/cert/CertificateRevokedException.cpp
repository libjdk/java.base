#include <java/security/cert/CertificateRevokedException.h>

#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream.h>
#include <java/security/cert/CRLReason.h>
#include <java/security/cert/CertificateException.h>
#include <java/security/cert/Extension.h>
#include <java/util/Collections.h>
#include <java/util/Date.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <sun/security/util/IOUtils.h>
#include <sun/security/util/KnownOIDs.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <sun/security/x509/Extension.h>
#include <sun/security/x509/InvalidityDateExtension.h>
#include <jcpp.h>

using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $CRLReason = ::java::security::cert::CRLReason;
using $CertificateException = ::java::security::cert::CertificateException;
using $Extension = ::java::security::cert::Extension;
using $Collections = ::java::util::Collections;
using $Date = ::java::util::Date;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;
using $X500Principal = ::javax::security::auth::x500::X500Principal;
using $IOUtils = ::sun::security::util::IOUtils;
using $KnownOIDs = ::sun::security::util::KnownOIDs;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;
using $1Extension = ::sun::security::x509::Extension;
using $InvalidityDateExtension = ::sun::security::x509::InvalidityDateExtension;

namespace java {
	namespace security {
		namespace cert {

$FieldInfo _CertificateRevokedException_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CertificateRevokedException, serialVersionUID)},
	{"revocationDate", "Ljava/util/Date;", nullptr, $PRIVATE, $field(CertificateRevokedException, revocationDate)},
	{"reason", "Ljava/security/cert/CRLReason;", nullptr, $PRIVATE | $FINAL, $field(CertificateRevokedException, reason)},
	{"authority", "Ljavax/security/auth/x500/X500Principal;", nullptr, $PRIVATE | $FINAL, $field(CertificateRevokedException, authority)},
	{"extensions", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/security/cert/Extension;>;", $PRIVATE | $TRANSIENT, $field(CertificateRevokedException, extensions)},
	{}
};

$MethodInfo _CertificateRevokedException_MethodInfo_[] = {
	{"<init>", "(Ljava/util/Date;Ljava/security/cert/CRLReason;Ljavax/security/auth/x500/X500Principal;Ljava/util/Map;)V", "(Ljava/util/Date;Ljava/security/cert/CRLReason;Ljavax/security/auth/x500/X500Principal;Ljava/util/Map<Ljava/lang/String;Ljava/security/cert/Extension;>;)V", $PUBLIC, $method(CertificateRevokedException, init$, void, $Date*, $CRLReason*, $X500Principal*, $Map*)},
	{"getAuthorityName", "()Ljavax/security/auth/x500/X500Principal;", nullptr, $PUBLIC, $virtualMethod(CertificateRevokedException, getAuthorityName, $X500Principal*)},
	{"getExtensions", "()Ljava/util/Map;", "()Ljava/util/Map<Ljava/lang/String;Ljava/security/cert/Extension;>;", $PUBLIC, $virtualMethod(CertificateRevokedException, getExtensions, $Map*)},
	{"getInvalidityDate", "()Ljava/util/Date;", nullptr, $PUBLIC, $virtualMethod(CertificateRevokedException, getInvalidityDate, $Date*)},
	{"getMessage", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(CertificateRevokedException, getMessage, $String*)},
	{"getRevocationDate", "()Ljava/util/Date;", nullptr, $PUBLIC, $virtualMethod(CertificateRevokedException, getRevocationDate, $Date*)},
	{"getRevocationReason", "()Ljava/security/cert/CRLReason;", nullptr, $PUBLIC, $virtualMethod(CertificateRevokedException, getRevocationReason, $CRLReason*)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(CertificateRevokedException, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE, $method(CertificateRevokedException, writeObject, void, $ObjectOutputStream*), "java.io.IOException"},
	{}
};

$ClassInfo _CertificateRevokedException_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.security.cert.CertificateRevokedException",
	"java.security.cert.CertificateException",
	nullptr,
	_CertificateRevokedException_FieldInfo_,
	_CertificateRevokedException_MethodInfo_
};

$Object* allocate$CertificateRevokedException($Class* clazz) {
	return $of($alloc(CertificateRevokedException));
}

void CertificateRevokedException::init$($Date* revocationDate, $CRLReason* reason, $X500Principal* authority, $Map* extensions) {
	$CertificateException::init$();
	if (revocationDate == nullptr || reason == nullptr || authority == nullptr || extensions == nullptr) {
		$throwNew($NullPointerException);
	}
	$set(this, revocationDate, $new($Date, $nc(revocationDate)->getTime()));
	$set(this, reason, reason);
	$set(this, authority, authority);
	$load($Extension);
	$set(this, extensions, $Collections::checkedMap($$new($HashMap), $String::class$, $Extension::class$));
	$nc(this->extensions)->putAll(extensions);
}

$Date* CertificateRevokedException::getRevocationDate() {
	return $cast($Date, $nc(this->revocationDate)->clone());
}

$CRLReason* CertificateRevokedException::getRevocationReason() {
	return this->reason;
}

$X500Principal* CertificateRevokedException::getAuthorityName() {
	return this->authority;
}

$Date* CertificateRevokedException::getInvalidityDate() {
	$useLocalCurrentObjectStackCache();
	$init($KnownOIDs);
	$var($Extension, ext, $cast($Extension, $nc($(getExtensions()))->get($($KnownOIDs::InvalidityDate->value()))));
	if (ext == nullptr) {
		return nullptr;
	} else {
		try {
			$var($Date, invalidity, $cast($Date, $nc($($InvalidityDateExtension::toImpl(ext)))->get("DATE"_s)));
			return $new($Date, $nc(invalidity)->getTime());
		} catch ($IOException& ioe) {
			return nullptr;
		}
	}
	$shouldNotReachHere();
}

$Map* CertificateRevokedException::getExtensions() {
	return $Collections::unmodifiableMap(this->extensions);
}

$String* CertificateRevokedException::getMessage() {
	$useLocalCurrentObjectStackCache();
	$var($String, var$0, $$str({"Certificate has been revoked, reason: "_s, this->reason, ", revocation date: "_s, this->revocationDate, ", authority: "_s, this->authority, ", extension OIDs: "_s}));
	return $concat(var$0, $($nc(this->extensions)->keySet()));
}

void CertificateRevokedException::writeObject($ObjectOutputStream* oos) {
	$useLocalCurrentObjectStackCache();
	$nc(oos)->defaultWriteObject();
	oos->writeInt($nc(this->extensions)->size());
	{
		$var($Iterator, i$, $nc($($nc(this->extensions)->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
			{
				$var($Extension, ext, $cast($Extension, $nc(entry)->getValue()));
				oos->writeObject($($nc(ext)->getId()));
				oos->writeBoolean($nc(ext)->isCritical());
				$var($bytes, extVal, $nc(ext)->getValue());
				oos->writeInt($nc(extVal)->length);
				oos->write(extVal);
			}
		}
	}
}

void CertificateRevokedException::readObject($ObjectInputStream* ois) {
	$useLocalCurrentObjectStackCache();
	$nc(ois)->defaultReadObject();
	$set(this, revocationDate, $new($Date, $nc(this->revocationDate)->getTime()));
	int32_t size = ois->readInt();
	if (size == 0) {
		$set(this, extensions, $Collections::emptyMap());
	} else if (size < 0) {
		$throwNew($IOException, "size cannot be negative"_s);
	} else {
		$set(this, extensions, $new($HashMap, size > 20 ? 20 : size));
	}
	for (int32_t i = 0; i < size; ++i) {
		$var($String, oid, $cast($String, ois->readObject()));
		bool critical = ois->readBoolean();
		$var($bytes, extVal, $IOUtils::readExactlyNBytes(ois, ois->readInt()));
		$var($Extension, ext, $1Extension::newExtension($($ObjectIdentifier::of(oid)), critical, extVal));
		$nc(this->extensions)->put(oid, ext);
	}
}

CertificateRevokedException::CertificateRevokedException() {
}

CertificateRevokedException::CertificateRevokedException(const CertificateRevokedException& e) : $CertificateException(e) {
}

void CertificateRevokedException::throw$() {
	throw *this;
}

$Class* CertificateRevokedException::load$($String* name, bool initialize) {
	$loadClass(CertificateRevokedException, name, initialize, &_CertificateRevokedException_ClassInfo_, allocate$CertificateRevokedException);
	return class$;
}

$Class* CertificateRevokedException::class$ = nullptr;

		} // cert
	} // security
} // java