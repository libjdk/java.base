#include <java/security/cert/CertPath.h>

#include <java/io/NotSerializableException.h>
#include <java/security/cert/CertPath$CertPathRep.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/CertificateException.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <jcpp.h>

using $NotSerializableException = ::java::io::NotSerializableException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $CertPath$CertPathRep = ::java::security::cert::CertPath$CertPathRep;
using $Certificate = ::java::security::cert::Certificate;
using $CertificateException = ::java::security::cert::CertificateException;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;

namespace java {
	namespace security {
		namespace cert {

$FieldInfo _CertPath_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CertPath, serialVersionUID)},
	{"type", "Ljava/lang/String;", nullptr, $PRIVATE, $field(CertPath, type)},
	{}
};

$MethodInfo _CertPath_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PROTECTED, $method(CertPath, init$, void, $String*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(CertPath, equals, bool, Object$*)},
	{"getCertificates", "()Ljava/util/List;", "()Ljava/util/List<+Ljava/security/cert/Certificate;>;", $PUBLIC | $ABSTRACT, $virtualMethod(CertPath, getCertificates, $List*)},
	{"getEncoded", "()[B", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(CertPath, getEncoded, $bytes*), "java.security.cert.CertificateEncodingException"},
	{"getEncoded", "(Ljava/lang/String;)[B", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(CertPath, getEncoded, $bytes*, $String*), "java.security.cert.CertificateEncodingException"},
	{"getEncodings", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<Ljava/lang/String;>;", $PUBLIC | $ABSTRACT, $virtualMethod(CertPath, getEncodings, $Iterator*)},
	{"getType", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(CertPath, getType, $String*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(CertPath, hashCode, int32_t)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(CertPath, toString, $String*)},
	{"writeReplace", "()Ljava/lang/Object;", nullptr, $PROTECTED, $virtualMethod(CertPath, writeReplace, $Object*), "java.io.ObjectStreamException"},
	{}
};

$InnerClassInfo _CertPath_InnerClassesInfo_[] = {
	{"java.security.cert.CertPath$CertPathRep", "java.security.cert.CertPath", "CertPathRep", $PROTECTED | $STATIC},
	{}
};

$ClassInfo _CertPath_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"java.security.cert.CertPath",
	"java.lang.Object",
	"java.io.Serializable",
	_CertPath_FieldInfo_,
	_CertPath_MethodInfo_,
	nullptr,
	nullptr,
	_CertPath_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.security.cert.CertPath$CertPathRep"
};

$Object* allocate$CertPath($Class* clazz) {
	return $of($alloc(CertPath));
}

void CertPath::init$($String* type) {
	$set(this, type, type);
}

$String* CertPath::getType() {
	return this->type;
}

bool CertPath::equals(Object$* other) {
	$useLocalCurrentObjectStackCache();
	if ($equals(this, other)) {
		return true;
	}
	$var(CertPath, that, nullptr);
	bool var$2 = $instanceOf(CertPath, other);
	if (var$2) {
		$assign(that, $cast(CertPath, other));
		var$2 = true;
	}
	bool var$1 = var$2;
	bool var$0 = var$1 && $nc($($nc(that)->getType()))->equals(this->type);
	return var$0 && $nc($(this->getCertificates()))->equals($(that->getCertificates()));
}

int32_t CertPath::hashCode() {
	int32_t hashCode = $nc(this->type)->hashCode();
	hashCode = 31 * hashCode + $nc($(getCertificates()))->hashCode();
	return hashCode;
}

$String* CertPath::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	$var($Iterator, stringIterator, $nc($(getCertificates()))->iterator());
	sb->append($$str({"\n"_s, this->type, " Cert Path: length = "_s, $$str($nc($(getCertificates()))->size()), ".\n"_s}));
	sb->append("[\n"_s);
	int32_t i = 1;
	while ($nc(stringIterator)->hasNext()) {
		sb->append($$str({"=========================================================Certificate "_s, $$str(i), " start.\n"_s}));
		$var($Certificate, stringCert, $cast($Certificate, stringIterator->next()));
		sb->append($($nc(stringCert)->toString()));
		sb->append($$str({"\n=========================================================Certificate "_s, $$str(i), " end.\n\n\n"_s}));
		++i;
	}
	sb->append("\n]"_s);
	return sb->toString();
}

$Object* CertPath::writeReplace() {
	$useLocalCurrentObjectStackCache();
	try {
		return $of($new($CertPath$CertPathRep, this->type, $(getEncoded())));
	} catch ($CertificateException& ce) {
		$var($NotSerializableException, nse, $new($NotSerializableException, $$str({"java.security.cert.CertPath: "_s, this->type})));
		nse->initCause(ce);
		$throw(nse);
	}
	$shouldNotReachHere();
}

CertPath::CertPath() {
}

$Class* CertPath::load$($String* name, bool initialize) {
	$loadClass(CertPath, name, initialize, &_CertPath_ClassInfo_, allocate$CertPath);
	return class$;
}

$Class* CertPath::class$ = nullptr;

		} // cert
	} // security
} // java