#include <java/security/cert/PKIXCertPathChecker.h>

#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/InternalError.h>
#include <java/security/cert/CertPathChecker.h>
#include <java/security/cert/Certificate.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Set.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $CertPathChecker = ::java::security::cert::CertPathChecker;
using $Certificate = ::java::security::cert::Certificate;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Set = ::java::util::Set;

namespace java {
	namespace security {
		namespace cert {

$MethodInfo _PKIXCertPathChecker_MethodInfo_[] = {
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"init", "(Z)V", nullptr, $PUBLIC | $ABSTRACT},
	{"<init>", "()V", nullptr, $PROTECTED, $method(PKIXCertPathChecker, init$, void)},
	{"check", "(Ljava/security/cert/Certificate;Ljava/util/Collection;)V", "(Ljava/security/cert/Certificate;Ljava/util/Collection<Ljava/lang/String;>;)V", $PUBLIC | $ABSTRACT, $virtualMethod(PKIXCertPathChecker, check, void, $Certificate*, $Collection*), "java.security.cert.CertPathValidatorException"},
	{"check", "(Ljava/security/cert/Certificate;)V", nullptr, $PUBLIC, $virtualMethod(PKIXCertPathChecker, check, void, $Certificate*), "java.security.cert.CertPathValidatorException"},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(PKIXCertPathChecker, clone, $Object*)},
	{"getSupportedExtensions", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC | $ABSTRACT, $virtualMethod(PKIXCertPathChecker, getSupportedExtensions, $Set*)},
	{"isForwardCheckingSupported", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _PKIXCertPathChecker_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"java.security.cert.PKIXCertPathChecker",
	"java.lang.Object",
	"java.security.cert.CertPathChecker,java.lang.Cloneable",
	nullptr,
	_PKIXCertPathChecker_MethodInfo_
};

$Object* allocate$PKIXCertPathChecker($Class* clazz) {
	return $of($alloc(PKIXCertPathChecker));
}

int32_t PKIXCertPathChecker::hashCode() {
	 return this->$CertPathChecker::hashCode();
}

bool PKIXCertPathChecker::equals(Object$* obj) {
	 return this->$CertPathChecker::equals(obj);
}

$String* PKIXCertPathChecker::toString() {
	 return this->$CertPathChecker::toString();
}

void PKIXCertPathChecker::finalize() {
	this->$CertPathChecker::finalize();
}

void PKIXCertPathChecker::init$() {
}

void PKIXCertPathChecker::check($Certificate* cert) {
	check(cert, $($Collections::emptySet()));
}

$Object* PKIXCertPathChecker::clone() {
	try {
		return $of($CertPathChecker::clone());
	} catch ($CloneNotSupportedException& e) {
		$throwNew($InternalError, $(e->toString()), e);
	}
	$shouldNotReachHere();
}

PKIXCertPathChecker::PKIXCertPathChecker() {
}

$Class* PKIXCertPathChecker::load$($String* name, bool initialize) {
	$loadClass(PKIXCertPathChecker, name, initialize, &_PKIXCertPathChecker_ClassInfo_, allocate$PKIXCertPathChecker);
	return class$;
}

$Class* PKIXCertPathChecker::class$ = nullptr;

		} // cert
	} // security
} // java