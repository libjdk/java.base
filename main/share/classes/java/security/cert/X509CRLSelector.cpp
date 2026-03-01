#include <java/security/cert/X509CRLSelector.h>

#include <java/io/IOException.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/InternalError.h>
#include <java/math/BigInteger.h>
#include <java/security/cert/CRL.h>
#include <java/security/cert/CRLSelector.h>
#include <java/security/cert/CertPathHelperImpl.h>
#include <java/security/cert/X509CRL.h>
#include <java/security/cert/X509Certificate.h>
#include <java/util/AbstractCollection.h>
#include <java/util/AbstractSet.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Date.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <sun/security/util/Debug.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/KnownOIDs.h>
#include <sun/security/x509/CRLNumberExtension.h>
#include <sun/security/x509/X500Name.h>
#include <jcpp.h>

#undef FALSE
#undef NUMBER

using $IOException = ::java::io::IOException;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $NamedAttribute = ::java::lang::NamedAttribute;
using $RuntimeException = ::java::lang::RuntimeException;
using $BigInteger = ::java::math::BigInteger;
using $CRL = ::java::security::cert::CRL;
using $CRLSelector = ::java::security::cert::CRLSelector;
using $CertPathHelperImpl = ::java::security::cert::CertPathHelperImpl;
using $X509CRL = ::java::security::cert::X509CRL;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $AbstractCollection = ::java::util::AbstractCollection;
using $AbstractSet = ::java::util::AbstractSet;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Date = ::java::util::Date;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $X500Principal = ::javax::security::auth::x500::X500Principal;
using $Debug = ::sun::security::util::Debug;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $KnownOIDs = ::sun::security::util::KnownOIDs;
using $CRLNumberExtension = ::sun::security::x509::CRLNumberExtension;
using $X500Name = ::sun::security::x509::X500Name;

namespace java {
	namespace security {
		namespace cert {

$NamedAttribute X509CRLSelector_Attribute_var$0[] = {
	{"since", 's', "16"},
	{}
};

$CompoundAttribute _X509CRLSelector_MethodAnnotations_addIssuerName2[] = {
	{"Ljava/lang/Deprecated;", X509CRLSelector_Attribute_var$0},
	{}
};

$FieldInfo _X509CRLSelector_FieldInfo_[] = {
	{"debug", "Lsun/security/util/Debug;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(X509CRLSelector, debug)},
	{"issuerNames", "Ljava/util/HashSet;", "Ljava/util/HashSet<Ljava/lang/Object;>;", $PRIVATE, $field(X509CRLSelector, issuerNames)},
	{"issuerX500Principals", "Ljava/util/HashSet;", "Ljava/util/HashSet<Ljavax/security/auth/x500/X500Principal;>;", $PRIVATE, $field(X509CRLSelector, issuerX500Principals)},
	{"minCRL", "Ljava/math/BigInteger;", nullptr, $PRIVATE, $field(X509CRLSelector, minCRL)},
	{"maxCRL", "Ljava/math/BigInteger;", nullptr, $PRIVATE, $field(X509CRLSelector, maxCRL)},
	{"dateAndTime", "Ljava/util/Date;", nullptr, $PRIVATE, $field(X509CRLSelector, dateAndTime)},
	{"certChecking", "Ljava/security/cert/X509Certificate;", nullptr, $PRIVATE, $field(X509CRLSelector, certChecking)},
	{"skew", "J", nullptr, $PRIVATE, $field(X509CRLSelector, skew)},
	{}
};

$MethodInfo _X509CRLSelector_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(X509CRLSelector, init$, void)},
	{"addIssuer", "(Ljavax/security/auth/x500/X500Principal;)V", nullptr, $PUBLIC, $virtualMethod(X509CRLSelector, addIssuer, void, $X500Principal*)},
	{"addIssuerName", "(Ljava/lang/String;)V", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(X509CRLSelector, addIssuerName, void, $String*), "java.io.IOException", nullptr, _X509CRLSelector_MethodAnnotations_addIssuerName2},
	{"addIssuerName", "([B)V", nullptr, $PUBLIC, $virtualMethod(X509CRLSelector, addIssuerName, void, $bytes*), "java.io.IOException"},
	{"addIssuerNameInternal", "(Ljava/lang/Object;Ljavax/security/auth/x500/X500Principal;)V", nullptr, $PRIVATE, $method(X509CRLSelector, addIssuerNameInternal, void, Object$*, $X500Principal*)},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(X509CRLSelector, clone, $Object*)},
	{"cloneAndCheckIssuerNames", "(Ljava/util/Collection;)Ljava/util/HashSet;", "(Ljava/util/Collection<*>;)Ljava/util/HashSet<Ljava/lang/Object;>;", $PRIVATE | $STATIC, $staticMethod(X509CRLSelector, cloneAndCheckIssuerNames, $HashSet*, $Collection*), "java.io.IOException"},
	{"cloneIssuerNames", "(Ljava/util/Collection;)Ljava/util/HashSet;", "(Ljava/util/Collection<Ljava/lang/Object;>;)Ljava/util/HashSet<Ljava/lang/Object;>;", $PRIVATE | $STATIC, $staticMethod(X509CRLSelector, cloneIssuerNames, $HashSet*, $Collection*)},
	{"getCertificateChecking", "()Ljava/security/cert/X509Certificate;", nullptr, $PUBLIC, $virtualMethod(X509CRLSelector, getCertificateChecking, $X509Certificate*)},
	{"getDateAndTime", "()Ljava/util/Date;", nullptr, $PUBLIC, $virtualMethod(X509CRLSelector, getDateAndTime, $Date*)},
	{"getIssuerNames", "()Ljava/util/Collection;", "()Ljava/util/Collection<Ljava/lang/Object;>;", $PUBLIC, $virtualMethod(X509CRLSelector, getIssuerNames, $Collection*)},
	{"getIssuers", "()Ljava/util/Collection;", "()Ljava/util/Collection<Ljavax/security/auth/x500/X500Principal;>;", $PUBLIC, $virtualMethod(X509CRLSelector, getIssuers, $Collection*)},
	{"getMaxCRL", "()Ljava/math/BigInteger;", nullptr, $PUBLIC, $virtualMethod(X509CRLSelector, getMaxCRL, $BigInteger*)},
	{"getMinCRL", "()Ljava/math/BigInteger;", nullptr, $PUBLIC, $virtualMethod(X509CRLSelector, getMinCRL, $BigInteger*)},
	{"match", "(Ljava/security/cert/CRL;)Z", nullptr, $PUBLIC, $virtualMethod(X509CRLSelector, match, bool, $CRL*)},
	{"parseIssuerNames", "(Ljava/util/Collection;)Ljava/util/HashSet;", "(Ljava/util/Collection<Ljava/lang/Object;>;)Ljava/util/HashSet<Ljavax/security/auth/x500/X500Principal;>;", $PRIVATE | $STATIC, $staticMethod(X509CRLSelector, parseIssuerNames, $HashSet*, $Collection*), "java.io.IOException"},
	{"setCertificateChecking", "(Ljava/security/cert/X509Certificate;)V", nullptr, $PUBLIC, $virtualMethod(X509CRLSelector, setCertificateChecking, void, $X509Certificate*)},
	{"setDateAndTime", "(Ljava/util/Date;)V", nullptr, $PUBLIC, $virtualMethod(X509CRLSelector, setDateAndTime, void, $Date*)},
	{"setDateAndTime", "(Ljava/util/Date;J)V", nullptr, 0, $virtualMethod(X509CRLSelector, setDateAndTime, void, $Date*, int64_t)},
	{"setIssuerNames", "(Ljava/util/Collection;)V", "(Ljava/util/Collection<*>;)V", $PUBLIC, $virtualMethod(X509CRLSelector, setIssuerNames, void, $Collection*), "java.io.IOException"},
	{"setIssuers", "(Ljava/util/Collection;)V", "(Ljava/util/Collection<Ljavax/security/auth/x500/X500Principal;>;)V", $PUBLIC, $virtualMethod(X509CRLSelector, setIssuers, void, $Collection*)},
	{"setMaxCRLNumber", "(Ljava/math/BigInteger;)V", nullptr, $PUBLIC, $virtualMethod(X509CRLSelector, setMaxCRLNumber, void, $BigInteger*)},
	{"setMinCRLNumber", "(Ljava/math/BigInteger;)V", nullptr, $PUBLIC, $virtualMethod(X509CRLSelector, setMinCRLNumber, void, $BigInteger*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(X509CRLSelector, toString, $String*)},
	{}
};

$ClassInfo _X509CRLSelector_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.security.cert.X509CRLSelector",
	"java.lang.Object",
	"java.security.cert.CRLSelector",
	_X509CRLSelector_FieldInfo_,
	_X509CRLSelector_MethodInfo_
};

$Object* allocate$X509CRLSelector($Class* clazz) {
	return $of($alloc(X509CRLSelector));
}

$Debug* X509CRLSelector::debug = nullptr;

void X509CRLSelector::init$() {
	this->skew = 0;
}

void X509CRLSelector::setIssuers($Collection* issuers) {
	$useLocalCurrentObjectStackCache();
	if ((issuers == nullptr) || $nc(issuers)->isEmpty()) {
		$set(this, issuerNames, nullptr);
		$set(this, issuerX500Principals, nullptr);
	} else {
		$set(this, issuerX500Principals, $new($HashSet, issuers));
		$set(this, issuerNames, $new($HashSet));
		{
			$var($Iterator, i$, $nc(this->issuerX500Principals)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($X500Principal, p, $cast($X500Principal, i$->next()));
				{
					$nc(this->issuerNames)->add($($nc(p)->getEncoded()));
				}
			}
		}
	}
}

void X509CRLSelector::setIssuerNames($Collection* names) {
	if (names == nullptr || $nc(names)->size() == 0) {
		$set(this, issuerNames, nullptr);
		$set(this, issuerX500Principals, nullptr);
	} else {
		$var($HashSet, tempNames, cloneAndCheckIssuerNames(names));
		$set(this, issuerX500Principals, parseIssuerNames(static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractSet*>(tempNames)))));
		$set(this, issuerNames, tempNames);
	}
}

void X509CRLSelector::addIssuer($X500Principal* issuer) {
	addIssuerNameInternal($($nc(issuer)->getEncoded()), issuer);
}

void X509CRLSelector::addIssuerName($String* name) {
	$useLocalCurrentObjectStackCache();
	addIssuerNameInternal(name, $($$new($X500Name, name)->asX500Principal()));
}

void X509CRLSelector::addIssuerName($bytes* name) {
	$useLocalCurrentObjectStackCache();
	$var($Object, var$0, $nc(name)->clone());
	addIssuerNameInternal(var$0, $($$new($X500Name, name)->asX500Principal()));
}

void X509CRLSelector::addIssuerNameInternal(Object$* name, $X500Principal* principal) {
	if (this->issuerNames == nullptr) {
		$set(this, issuerNames, $new($HashSet));
	}
	if (this->issuerX500Principals == nullptr) {
		$set(this, issuerX500Principals, $new($HashSet));
	}
	$nc(this->issuerNames)->add(name);
	$nc(this->issuerX500Principals)->add(principal);
}

$HashSet* X509CRLSelector::cloneAndCheckIssuerNames($Collection* names) {
	$init(X509CRLSelector);
	$useLocalCurrentObjectStackCache();
	$var($HashSet, namesCopy, $new($HashSet));
	$var($Iterator, i, $nc(names)->iterator());
	while ($nc(i)->hasNext()) {
		$var($Object, nameObject, i->next());
		if (!($instanceOf($bytes, nameObject)) && !($instanceOf($String, nameObject))) {
			$throwNew($IOException, "name not byte array or String"_s);
		}
		if ($instanceOf($bytes, nameObject)) {
			namesCopy->add($($nc(($cast($bytes, nameObject)))->clone()));
		} else {
			namesCopy->add(nameObject);
		}
	}
	return (namesCopy);
}

$HashSet* X509CRLSelector::cloneIssuerNames($Collection* names) {
	$init(X509CRLSelector);
	try {
		return cloneAndCheckIssuerNames(names);
	} catch ($IOException& ioe) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(ioe));
	}
	$shouldNotReachHere();
}

$HashSet* X509CRLSelector::parseIssuerNames($Collection* names) {
	$init(X509CRLSelector);
	$useLocalCurrentObjectStackCache();
	$var($HashSet, x500Principals, $new($HashSet));
	{
		$var($Iterator, t, $nc(names)->iterator());
		for (; $nc(t)->hasNext();) {
			$var($Object, nameObject, t->next());
			if ($instanceOf($String, nameObject)) {
				x500Principals->add($($$new($X500Name, $cast($String, nameObject))->asX500Principal()));
			} else {
				try {
					x500Principals->add($$new($X500Principal, $cast($bytes, nameObject)));
				} catch ($IllegalArgumentException& e) {
					$throw($cast($IOException, $($$new($IOException, "Invalid name"_s)->initCause(e))));
				}
			}
		}
	}
	return x500Principals;
}

void X509CRLSelector::setMinCRLNumber($BigInteger* minCRL) {
	$set(this, minCRL, minCRL);
}

void X509CRLSelector::setMaxCRLNumber($BigInteger* maxCRL) {
	$set(this, maxCRL, maxCRL);
}

void X509CRLSelector::setDateAndTime($Date* dateAndTime) {
	if (dateAndTime == nullptr) {
		$set(this, dateAndTime, nullptr);
	} else {
		$set(this, dateAndTime, $new($Date, $nc(dateAndTime)->getTime()));
	}
	this->skew = 0;
}

void X509CRLSelector::setDateAndTime($Date* dateAndTime, int64_t skew) {
	$set(this, dateAndTime, dateAndTime == nullptr ? ($Date*)nullptr : $new($Date, $nc(dateAndTime)->getTime()));
	this->skew = skew;
}

void X509CRLSelector::setCertificateChecking($X509Certificate* cert) {
	$set(this, certChecking, cert);
}

$Collection* X509CRLSelector::getIssuers() {
	if (this->issuerX500Principals == nullptr) {
		return nullptr;
	}
	return $Collections::unmodifiableCollection(static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractSet*>(this->issuerX500Principals))));
}

$Collection* X509CRLSelector::getIssuerNames() {
	if (this->issuerNames == nullptr) {
		return nullptr;
	}
	return static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractSet*>(cloneIssuerNames(static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractSet*>(this->issuerNames)))))));
}

$BigInteger* X509CRLSelector::getMinCRL() {
	return this->minCRL;
}

$BigInteger* X509CRLSelector::getMaxCRL() {
	return this->maxCRL;
}

$Date* X509CRLSelector::getDateAndTime() {
	if (this->dateAndTime == nullptr) {
		return nullptr;
	}
	return $cast($Date, $nc(this->dateAndTime)->clone());
}

$X509Certificate* X509CRLSelector::getCertificateChecking() {
	return this->certChecking;
}

$String* X509CRLSelector::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append("X509CRLSelector: [\n"_s);
	if (this->issuerNames != nullptr) {
		sb->append("  IssuerNames:\n"_s);
		$var($Iterator, i, $nc(this->issuerNames)->iterator());
		while ($nc(i)->hasNext()) {
			sb->append($$str({"    "_s, $(i->next()), "\n"_s}));
		}
	}
	if (this->minCRL != nullptr) {
		sb->append($$str({"  minCRLNumber: "_s, this->minCRL, "\n"_s}));
	}
	if (this->maxCRL != nullptr) {
		sb->append($$str({"  maxCRLNumber: "_s, this->maxCRL, "\n"_s}));
	}
	if (this->dateAndTime != nullptr) {
		sb->append($$str({"  dateAndTime: "_s, this->dateAndTime, "\n"_s}));
	}
	if (this->certChecking != nullptr) {
		sb->append($$str({"  Certificate being checked: "_s, this->certChecking, "\n"_s}));
	}
	sb->append("]"_s);
	return sb->toString();
}

bool X509CRLSelector::match($CRL* crl) {
	$useLocalCurrentObjectStackCache();
	$var($X509CRL, xcrl, nullptr);
	bool var$0 = $instanceOf($X509CRL, crl);
	if (var$0) {
		$assign(xcrl, $cast($X509CRL, crl));
		var$0 = true;
	}
	if (!(var$0)) {
		return false;
	}
	if (this->issuerNames != nullptr) {
		$var($X500Principal, issuer, $nc(xcrl)->getIssuerX500Principal());
		$var($Iterator, i, $nc(this->issuerX500Principals)->iterator());
		bool found = false;
		while (!found && $nc(i)->hasNext()) {
			if ($nc(($cast($X500Principal, $(i->next()))))->equals(issuer)) {
				found = true;
			}
		}
		if (!found) {
			if (X509CRLSelector::debug != nullptr) {
				$nc(X509CRLSelector::debug)->println("X509CRLSelector.match: issuer DNs don\'t match"_s);
			}
			return false;
		}
	}
	if ((this->minCRL != nullptr) || (this->maxCRL != nullptr)) {
		$init($KnownOIDs);
		$var($bytes, crlNumExtVal, $nc(xcrl)->getExtensionValue($($KnownOIDs::CRLNumber->value())));
		if (crlNumExtVal == nullptr) {
			if (X509CRLSelector::debug != nullptr) {
				$nc(X509CRLSelector::debug)->println("X509CRLSelector.match: no CRLNumber"_s);
			}
		}
		$var($BigInteger, crlNum, nullptr);
		try {
			$var($DerInputStream, in, $new($DerInputStream, crlNumExtVal));
			$var($bytes, encoded, in->getOctetString());
			$init($Boolean);
			$var($CRLNumberExtension, crlNumExt, $new($CRLNumberExtension, $Boolean::FALSE, encoded));
			$init($CRLNumberExtension);
			$assign(crlNum, $cast($BigInteger, crlNumExt->get($CRLNumberExtension::NUMBER)));
		} catch ($IOException& ex) {
			if (X509CRLSelector::debug != nullptr) {
				$nc(X509CRLSelector::debug)->println("X509CRLSelector.match: exception in decoding CRL number"_s);
			}
			return false;
		}
		if (this->minCRL != nullptr) {
			if ($nc(crlNum)->compareTo(this->minCRL) < 0) {
				if (X509CRLSelector::debug != nullptr) {
					$nc(X509CRLSelector::debug)->println("X509CRLSelector.match: CRLNumber too small"_s);
				}
				return false;
			}
		}
		if (this->maxCRL != nullptr) {
			if ($nc(crlNum)->compareTo(this->maxCRL) > 0) {
				if (X509CRLSelector::debug != nullptr) {
					$nc(X509CRLSelector::debug)->println("X509CRLSelector.match: CRLNumber too large"_s);
				}
				return false;
			}
		}
	}
	if (this->dateAndTime != nullptr) {
		$var($Date, crlThisUpdate, $nc(xcrl)->getThisUpdate());
		$var($Date, nextUpdate, xcrl->getNextUpdate());
		if (nextUpdate == nullptr) {
			if (X509CRLSelector::debug != nullptr) {
				$nc(X509CRLSelector::debug)->println("X509CRLSelector.match: nextUpdate null"_s);
			}
			return false;
		}
		$var($Date, nowPlusSkew, this->dateAndTime);
		$var($Date, nowMinusSkew, this->dateAndTime);
		if (this->skew > 0) {
			$assign(nowPlusSkew, $new($Date, $nc(this->dateAndTime)->getTime() + this->skew));
			$assign(nowMinusSkew, $new($Date, $nc(this->dateAndTime)->getTime() - this->skew));
		}
		bool var$1 = $nc(nowMinusSkew)->after(nextUpdate);
		if (var$1 || $nc(nowPlusSkew)->before(crlThisUpdate)) {
			if (X509CRLSelector::debug != nullptr) {
				$nc(X509CRLSelector::debug)->println("X509CRLSelector.match: update out-of-range"_s);
			}
			return false;
		}
	}
	return true;
}

$Object* X509CRLSelector::clone() {
	$useLocalCurrentObjectStackCache();
	try {
		$var(X509CRLSelector, copy, $cast(X509CRLSelector, $CRLSelector::clone()));
		if (this->issuerNames != nullptr) {
			$set($nc(copy), issuerNames, $new($HashSet, static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractSet*>(this->issuerNames)))));
			$set(copy, issuerX500Principals, $new($HashSet, static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractSet*>(this->issuerX500Principals)))));
		}
		return $of(copy);
	} catch ($CloneNotSupportedException& e) {
		$throwNew($InternalError, $(e->toString()), e);
	}
	$shouldNotReachHere();
}

void clinit$X509CRLSelector($Class* class$) {
	{
		$CertPathHelperImpl::initialize();
	}
	$assignStatic(X509CRLSelector::debug, $Debug::getInstance("certpath"_s));
}

X509CRLSelector::X509CRLSelector() {
}

$Class* X509CRLSelector::load$($String* name, bool initialize) {
	$loadClass(X509CRLSelector, name, initialize, &_X509CRLSelector_ClassInfo_, clinit$X509CRLSelector, allocate$X509CRLSelector);
	return class$;
}

$Class* X509CRLSelector::class$ = nullptr;

		} // cert
	} // security
} // java