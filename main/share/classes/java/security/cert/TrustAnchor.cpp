#include <java/security/cert/TrustAnchor.h>

#include <java/io/IOException.h>
#include <java/security/PublicKey.h>
#include <java/security/cert/CertPathHelperImpl.h>
#include <java/security/cert/X509Certificate.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <sun/security/util/AnchorCertificates.h>
#include <sun/security/x509/NameConstraintsExtension.h>
#include <jcpp.h>

#undef FALSE

using $IOException = ::java::io::IOException;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $PublicKey = ::java::security::PublicKey;
using $CertPathHelperImpl = ::java::security::cert::CertPathHelperImpl;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $X500Principal = ::javax::security::auth::x500::X500Principal;
using $AnchorCertificates = ::sun::security::util::AnchorCertificates;
using $NameConstraintsExtension = ::sun::security::x509::NameConstraintsExtension;

namespace java {
	namespace security {
		namespace cert {

$FieldInfo _TrustAnchor_FieldInfo_[] = {
	{"pubKey", "Ljava/security/PublicKey;", nullptr, $PRIVATE | $FINAL, $field(TrustAnchor, pubKey)},
	{"caName", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(TrustAnchor, caName)},
	{"caPrincipal", "Ljavax/security/auth/x500/X500Principal;", nullptr, $PRIVATE | $FINAL, $field(TrustAnchor, caPrincipal)},
	{"trustedCert", "Ljava/security/cert/X509Certificate;", nullptr, $PRIVATE | $FINAL, $field(TrustAnchor, trustedCert)},
	{"ncBytes", "[B", nullptr, $PRIVATE, $field(TrustAnchor, ncBytes)},
	{"nc", "Lsun/security/x509/NameConstraintsExtension;", nullptr, $PRIVATE, $field(TrustAnchor, nc)},
	{"jdkCA", "Z", nullptr, $PRIVATE, $field(TrustAnchor, jdkCA)},
	{"hasJdkCABeenChecked", "Z", nullptr, $PRIVATE, $field(TrustAnchor, hasJdkCABeenChecked)},
	{}
};

$MethodInfo _TrustAnchor_MethodInfo_[] = {
	{"<init>", "(Ljava/security/cert/X509Certificate;[B)V", nullptr, $PUBLIC, $method(TrustAnchor, init$, void, $X509Certificate*, $bytes*)},
	{"<init>", "(Ljavax/security/auth/x500/X500Principal;Ljava/security/PublicKey;[B)V", nullptr, $PUBLIC, $method(TrustAnchor, init$, void, $X500Principal*, $PublicKey*, $bytes*)},
	{"<init>", "(Ljava/lang/String;Ljava/security/PublicKey;[B)V", nullptr, $PUBLIC, $method(TrustAnchor, init$, void, $String*, $PublicKey*, $bytes*)},
	{"getCA", "()Ljavax/security/auth/x500/X500Principal;", nullptr, $PUBLIC | $FINAL, $method(TrustAnchor, getCA, $X500Principal*)},
	{"getCAName", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL, $method(TrustAnchor, getCAName, $String*)},
	{"getCAPublicKey", "()Ljava/security/PublicKey;", nullptr, $PUBLIC | $FINAL, $method(TrustAnchor, getCAPublicKey, $PublicKey*)},
	{"getNameConstraints", "()[B", nullptr, $PUBLIC | $FINAL, $method(TrustAnchor, getNameConstraints, $bytes*)},
	{"getTrustedCert", "()Ljava/security/cert/X509Certificate;", nullptr, $PUBLIC | $FINAL, $method(TrustAnchor, getTrustedCert, $X509Certificate*)},
	{"isJdkCA", "()Z", nullptr, $SYNCHRONIZED, $virtualMethod(TrustAnchor, isJdkCA, bool)},
	{"setNameConstraints", "([B)V", nullptr, $PRIVATE, $method(TrustAnchor, setNameConstraints, void, $bytes*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(TrustAnchor, toString, $String*)},
	{}
};

$ClassInfo _TrustAnchor_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.security.cert.TrustAnchor",
	"java.lang.Object",
	nullptr,
	_TrustAnchor_FieldInfo_,
	_TrustAnchor_MethodInfo_
};

$Object* allocate$TrustAnchor($Class* clazz) {
	return $of($alloc(TrustAnchor));
}

void TrustAnchor::init$($X509Certificate* trustedCert, $bytes* nameConstraints) {
	if (trustedCert == nullptr) {
		$throwNew($NullPointerException, "the trustedCert parameter must be non-null"_s);
	}
	$set(this, trustedCert, trustedCert);
	$set(this, pubKey, nullptr);
	$set(this, caName, nullptr);
	$set(this, caPrincipal, nullptr);
	setNameConstraints(nameConstraints);
}

void TrustAnchor::init$($X500Principal* caPrincipal, $PublicKey* pubKey, $bytes* nameConstraints) {
	if ((caPrincipal == nullptr) || (pubKey == nullptr)) {
		$throwNew($NullPointerException);
	}
	$set(this, trustedCert, nullptr);
	$set(this, caPrincipal, caPrincipal);
	$set(this, caName, $nc(caPrincipal)->getName());
	$set(this, pubKey, pubKey);
	setNameConstraints(nameConstraints);
}

void TrustAnchor::init$($String* caName, $PublicKey* pubKey, $bytes* nameConstraints) {
	if (pubKey == nullptr) {
		$throwNew($NullPointerException, "the pubKey parameter must be non-null"_s);
	}
	if (caName == nullptr) {
		$throwNew($NullPointerException, "the caName parameter must be non-null"_s);
	}
	if ($nc(caName)->isEmpty()) {
		$throwNew($IllegalArgumentException, "the caName parameter must be a non-empty String"_s);
	}
	$set(this, caPrincipal, $new($X500Principal, caName));
	$set(this, pubKey, pubKey);
	$set(this, caName, caName);
	$set(this, trustedCert, nullptr);
	setNameConstraints(nameConstraints);
}

$X509Certificate* TrustAnchor::getTrustedCert() {
	return this->trustedCert;
}

$X500Principal* TrustAnchor::getCA() {
	return this->caPrincipal;
}

$String* TrustAnchor::getCAName() {
	return this->caName;
}

$PublicKey* TrustAnchor::getCAPublicKey() {
	return this->pubKey;
}

void TrustAnchor::setNameConstraints($bytes* bytes) {
	$useLocalCurrentObjectStackCache();
	if (bytes == nullptr) {
		$set(this, ncBytes, nullptr);
		$set(this, nc, nullptr);
	} else {
		$set(this, ncBytes, $cast($bytes, $nc(bytes)->clone()));
		try {
			$init($Boolean);
			$set(this, nc, $new($NameConstraintsExtension, $Boolean::FALSE, $of(bytes)));
		} catch ($IOException& ioe) {
			$var($IllegalArgumentException, iae, $new($IllegalArgumentException, $(ioe->getMessage())));
			iae->initCause(ioe);
			$throw(iae);
		}
	}
}

$bytes* TrustAnchor::getNameConstraints() {
	return this->ncBytes == nullptr ? ($bytes*)nullptr : $cast($bytes, $nc(this->ncBytes)->clone());
}

$String* TrustAnchor::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append("[\n"_s);
	if (this->pubKey != nullptr) {
		sb->append($$str({"  Trusted CA Public Key: "_s, $($nc($of(this->pubKey))->toString()), "\n"_s}));
		sb->append($$str({"  Trusted CA Issuer Name: "_s, $($String::valueOf($of(this->caName))), "\n"_s}));
	} else {
		sb->append($$str({"  Trusted CA cert: "_s, $($nc(this->trustedCert)->toString()), "\n"_s}));
	}
	if (this->nc != nullptr) {
		sb->append($$str({"  Name Constraints: "_s, $($nc(this->nc)->toString()), "\n"_s}));
	}
	return sb->toString();
}

bool TrustAnchor::isJdkCA() {
	$synchronized(this) {
		if (!this->hasJdkCABeenChecked) {
			if (this->trustedCert != nullptr) {
				this->jdkCA = $AnchorCertificates::contains(this->trustedCert);
			}
			this->hasJdkCABeenChecked = true;
		}
		return this->jdkCA;
	}
}

void clinit$TrustAnchor($Class* class$) {
	{
		$CertPathHelperImpl::initialize();
	}
}

TrustAnchor::TrustAnchor() {
}

$Class* TrustAnchor::load$($String* name, bool initialize) {
	$loadClass(TrustAnchor, name, initialize, &_TrustAnchor_ClassInfo_, clinit$TrustAnchor, allocate$TrustAnchor);
	return class$;
}

$Class* TrustAnchor::class$ = nullptr;

		} // cert
	} // security
} // java