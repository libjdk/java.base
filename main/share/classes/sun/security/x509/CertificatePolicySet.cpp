#include <sun/security/x509/CertificatePolicySet.h>

#include <java/util/Collections.h>
#include <java/util/List.h>
#include <java/util/Vector.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/x509/CertificatePolicyId.h>
#include <jcpp.h>

using $DerValueArray = $Array<::sun::security::util::DerValue>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Collections = ::java::util::Collections;
using $List = ::java::util::List;
using $Vector = ::java::util::Vector;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;
using $CertificatePolicyId = ::sun::security::x509::CertificatePolicyId;

namespace sun {
	namespace security {
		namespace x509 {

$FieldInfo _CertificatePolicySet_FieldInfo_[] = {
	{"ids", "Ljava/util/Vector;", "Ljava/util/Vector<Lsun/security/x509/CertificatePolicyId;>;", $PRIVATE | $FINAL, $field(CertificatePolicySet, ids)},
	{}
};

$MethodInfo _CertificatePolicySet_MethodInfo_[] = {
	{"<init>", "(Ljava/util/Vector;)V", "(Ljava/util/Vector<Lsun/security/x509/CertificatePolicyId;>;)V", $PUBLIC, $method(CertificatePolicySet, init$, void, $Vector*)},
	{"<init>", "(Lsun/security/util/DerInputStream;)V", nullptr, $PUBLIC, $method(CertificatePolicySet, init$, void, $DerInputStream*), "java.io.IOException"},
	{"encode", "(Lsun/security/util/DerOutputStream;)V", nullptr, $PUBLIC, $virtualMethod(CertificatePolicySet, encode, void, $DerOutputStream*), "java.io.IOException"},
	{"getCertPolicyIds", "()Ljava/util/List;", "()Ljava/util/List<Lsun/security/x509/CertificatePolicyId;>;", $PUBLIC, $virtualMethod(CertificatePolicySet, getCertPolicyIds, $List*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(CertificatePolicySet, toString, $String*)},
	{}
};

$ClassInfo _CertificatePolicySet_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.x509.CertificatePolicySet",
	"java.lang.Object",
	nullptr,
	_CertificatePolicySet_FieldInfo_,
	_CertificatePolicySet_MethodInfo_
};

$Object* allocate$CertificatePolicySet($Class* clazz) {
	return $of($alloc(CertificatePolicySet));
}

void CertificatePolicySet::init$($Vector* ids) {
	$set(this, ids, ids);
}

void CertificatePolicySet::init$($DerInputStream* in) {
	$useLocalCurrentObjectStackCache();
	$set(this, ids, $new($Vector));
	$var($DerValueArray, seq, $nc(in)->getSequence(5));
	for (int32_t i = 0; i < $nc(seq)->length; ++i) {
		$var($CertificatePolicyId, id, $new($CertificatePolicyId, seq->get(i)));
		$nc(this->ids)->addElement(id);
	}
}

$String* CertificatePolicySet::toString() {
	$useLocalCurrentObjectStackCache();
	$var($String, s, $str({"CertificatePolicySet:[\n"_s, $($nc(this->ids)->toString()), "]\n"_s}));
	return (s);
}

void CertificatePolicySet::encode($DerOutputStream* out) {
	$useLocalCurrentObjectStackCache();
	$var($DerOutputStream, tmp, $new($DerOutputStream));
	for (int32_t i = 0; i < $nc(this->ids)->size(); ++i) {
		$nc(($cast($CertificatePolicyId, $($nc(this->ids)->elementAt(i)))))->encode(tmp);
	}
	$nc(out)->write($DerValue::tag_Sequence, tmp);
}

$List* CertificatePolicySet::getCertPolicyIds() {
	return $Collections::unmodifiableList(this->ids);
}

CertificatePolicySet::CertificatePolicySet() {
}

$Class* CertificatePolicySet::load$($String* name, bool initialize) {
	$loadClass(CertificatePolicySet, name, initialize, &_CertificatePolicySet_ClassInfo_, allocate$CertificatePolicySet);
	return class$;
}

$Class* CertificatePolicySet::class$ = nullptr;

		} // x509
	} // security
} // sun