#include <java/security/cert/CertPath$CertPathRep.h>

#include <java/io/ByteArrayInputStream.h>
#include <java/io/InputStream.h>
#include <java/io/NotSerializableException.h>
#include <java/security/cert/CertPath.h>
#include <java/security/cert/CertificateException.h>
#include <java/security/cert/CertificateFactory.h>
#include <jcpp.h>

using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $InputStream = ::java::io::InputStream;
using $NotSerializableException = ::java::io::NotSerializableException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $CertificateException = ::java::security::cert::CertificateException;
using $CertificateFactory = ::java::security::cert::CertificateFactory;

namespace java {
	namespace security {
		namespace cert {

$FieldInfo _CertPath$CertPathRep_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CertPath$CertPathRep, serialVersionUID)},
	{"type", "Ljava/lang/String;", nullptr, $PRIVATE, $field(CertPath$CertPathRep, type)},
	{"data", "[B", nullptr, $PRIVATE, $field(CertPath$CertPathRep, data)},
	{}
};

$MethodInfo _CertPath$CertPathRep_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;[B)V", nullptr, $PROTECTED, $method(CertPath$CertPathRep, init$, void, $String*, $bytes*)},
	{"readResolve", "()Ljava/lang/Object;", nullptr, $PROTECTED, $virtualMethod(CertPath$CertPathRep, readResolve, $Object*), "java.io.ObjectStreamException"},
	{}
};

$InnerClassInfo _CertPath$CertPathRep_InnerClassesInfo_[] = {
	{"java.security.cert.CertPath$CertPathRep", "java.security.cert.CertPath", "CertPathRep", $PROTECTED | $STATIC},
	{}
};

$ClassInfo _CertPath$CertPathRep_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.security.cert.CertPath$CertPathRep",
	"java.lang.Object",
	"java.io.Serializable",
	_CertPath$CertPathRep_FieldInfo_,
	_CertPath$CertPathRep_MethodInfo_,
	nullptr,
	nullptr,
	_CertPath$CertPathRep_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.security.cert.CertPath"
};

$Object* allocate$CertPath$CertPathRep($Class* clazz) {
	return $of($alloc(CertPath$CertPathRep));
}

void CertPath$CertPathRep::init$($String* type, $bytes* data) {
	$set(this, type, type);
	$set(this, data, data);
}

$Object* CertPath$CertPathRep::readResolve() {
	$useLocalCurrentObjectStackCache();
	try {
		$var($CertificateFactory, cf, $CertificateFactory::getInstance(this->type));
		return $of($nc(cf)->generateCertPath(static_cast<$InputStream*>($$new($ByteArrayInputStream, this->data))));
	} catch ($CertificateException& ce) {
		$var($NotSerializableException, nse, $new($NotSerializableException, $$str({"java.security.cert.CertPath: "_s, this->type})));
		nse->initCause(ce);
		$throw(nse);
	}
	$shouldNotReachHere();
}

CertPath$CertPathRep::CertPath$CertPathRep() {
}

$Class* CertPath$CertPathRep::load$($String* name, bool initialize) {
	$loadClass(CertPath$CertPathRep, name, initialize, &_CertPath$CertPathRep_ClassInfo_, allocate$CertPath$CertPathRep);
	return class$;
}

$Class* CertPath$CertPathRep::class$ = nullptr;

		} // cert
	} // security
} // java