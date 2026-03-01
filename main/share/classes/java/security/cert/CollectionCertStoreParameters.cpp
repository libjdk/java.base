#include <java/security/cert/CollectionCertStoreParameters.h>

#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/InternalError.h>
#include <java/security/cert/CertStoreParameters.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Set.h>
#include <jcpp.h>

#undef EMPTY_SET

using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $FieldInfo = ::java::lang::FieldInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $CertStoreParameters = ::java::security::cert::CertStoreParameters;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;

namespace java {
	namespace security {
		namespace cert {

$FieldInfo _CollectionCertStoreParameters_FieldInfo_[] = {
	{"coll", "Ljava/util/Collection;", "Ljava/util/Collection<*>;", $PRIVATE, $field(CollectionCertStoreParameters, coll)},
	{}
};

$MethodInfo _CollectionCertStoreParameters_MethodInfo_[] = {
	{"<init>", "(Ljava/util/Collection;)V", "(Ljava/util/Collection<*>;)V", $PUBLIC, $method(CollectionCertStoreParameters, init$, void, $Collection*)},
	{"<init>", "()V", nullptr, $PUBLIC, $method(CollectionCertStoreParameters, init$, void)},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(CollectionCertStoreParameters, clone, $Object*)},
	{"getCollection", "()Ljava/util/Collection;", "()Ljava/util/Collection<*>;", $PUBLIC, $virtualMethod(CollectionCertStoreParameters, getCollection, $Collection*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(CollectionCertStoreParameters, toString, $String*)},
	{}
};

$ClassInfo _CollectionCertStoreParameters_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.security.cert.CollectionCertStoreParameters",
	"java.lang.Object",
	"java.security.cert.CertStoreParameters",
	_CollectionCertStoreParameters_FieldInfo_,
	_CollectionCertStoreParameters_MethodInfo_
};

$Object* allocate$CollectionCertStoreParameters($Class* clazz) {
	return $of($alloc(CollectionCertStoreParameters));
}

void CollectionCertStoreParameters::init$($Collection* collection) {
	if (collection == nullptr) {
		$throwNew($NullPointerException);
	}
	$set(this, coll, collection);
}

void CollectionCertStoreParameters::init$() {
	$init($Collections);
	$set(this, coll, $Collections::EMPTY_SET);
}

$Collection* CollectionCertStoreParameters::getCollection() {
	return this->coll;
}

$Object* CollectionCertStoreParameters::clone() {
	try {
		return $of($CertStoreParameters::clone());
	} catch ($CloneNotSupportedException& e) {
		$throwNew($InternalError, $(e->toString()), e);
	}
	$shouldNotReachHere();
}

$String* CollectionCertStoreParameters::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append("CollectionCertStoreParameters: [\n"_s);
	sb->append($$str({"  collection: "_s, this->coll, "\n"_s}));
	sb->append("]"_s);
	return sb->toString();
}

CollectionCertStoreParameters::CollectionCertStoreParameters() {
}

$Class* CollectionCertStoreParameters::load$($String* name, bool initialize) {
	$loadClass(CollectionCertStoreParameters, name, initialize, &_CollectionCertStoreParameters_ClassInfo_, allocate$CollectionCertStoreParameters);
	return class$;
}

$Class* CollectionCertStoreParameters::class$ = nullptr;

		} // cert
	} // security
} // java