#include <sun/security/util/SignatureUtil$EdDSADigestAlgHolder.h>

#include <java/io/IOException.h>
#include <java/lang/AssertionError.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/KnownOIDs.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <sun/security/util/SignatureUtil.h>
#include <sun/security/x509/AlgorithmId.h>
#include <jcpp.h>

#undef SHAKE256
#undef SHAKE256_LEN

using $IOException = ::java::io::IOException;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $DerValue = ::sun::security::util::DerValue;
using $KnownOIDs = ::sun::security::util::KnownOIDs;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;
using $AlgorithmId = ::sun::security::x509::AlgorithmId;

namespace sun {
	namespace security {
		namespace util {

$FieldInfo _SignatureUtil$EdDSADigestAlgHolder_FieldInfo_[] = {
	{"sha512", "Lsun/security/x509/AlgorithmId;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(SignatureUtil$EdDSADigestAlgHolder, sha512)},
	{"shake256", "Lsun/security/x509/AlgorithmId;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(SignatureUtil$EdDSADigestAlgHolder, shake256)},
	{"shake256$512", "Lsun/security/x509/AlgorithmId;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(SignatureUtil$EdDSADigestAlgHolder, shake256$512)},
	{}
};

$MethodInfo _SignatureUtil$EdDSADigestAlgHolder_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(SignatureUtil$EdDSADigestAlgHolder, init$, void)},
	{}
};

$InnerClassInfo _SignatureUtil$EdDSADigestAlgHolder_InnerClassesInfo_[] = {
	{"sun.security.util.SignatureUtil$EdDSADigestAlgHolder", "sun.security.util.SignatureUtil", "EdDSADigestAlgHolder", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _SignatureUtil$EdDSADigestAlgHolder_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.util.SignatureUtil$EdDSADigestAlgHolder",
	"java.lang.Object",
	nullptr,
	_SignatureUtil$EdDSADigestAlgHolder_FieldInfo_,
	_SignatureUtil$EdDSADigestAlgHolder_MethodInfo_,
	nullptr,
	nullptr,
	_SignatureUtil$EdDSADigestAlgHolder_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.util.SignatureUtil"
};

$Object* allocate$SignatureUtil$EdDSADigestAlgHolder($Class* clazz) {
	return $of($alloc(SignatureUtil$EdDSADigestAlgHolder));
}

$AlgorithmId* SignatureUtil$EdDSADigestAlgHolder::sha512 = nullptr;
$AlgorithmId* SignatureUtil$EdDSADigestAlgHolder::shake256 = nullptr;
$AlgorithmId* SignatureUtil$EdDSADigestAlgHolder::shake256$512 = nullptr;

void SignatureUtil$EdDSADigestAlgHolder::init$() {
}

void clinit$SignatureUtil$EdDSADigestAlgHolder($Class* class$) {
	$useLocalCurrentObjectStackCache();
	{
		try {
			$init($KnownOIDs);
			$assignStatic(SignatureUtil$EdDSADigestAlgHolder::sha512, $new($AlgorithmId, $($ObjectIdentifier::of($KnownOIDs::SHA_512))));
			$assignStatic(SignatureUtil$EdDSADigestAlgHolder::shake256, $new($AlgorithmId, $($ObjectIdentifier::of($KnownOIDs::SHAKE256))));
			$var($ObjectIdentifier, var$0, $ObjectIdentifier::of($KnownOIDs::SHAKE256_LEN));
			$assignStatic(SignatureUtil$EdDSADigestAlgHolder::shake256$512, $new($AlgorithmId, var$0, $$new($DerValue, (int8_t)2, $$new($bytes, {
				(int8_t)2,
				(int8_t)0
			}))));
		} catch ($IOException& e) {
			$throwNew($AssertionError, "Should not happen"_s, e);
		}
	}
}

SignatureUtil$EdDSADigestAlgHolder::SignatureUtil$EdDSADigestAlgHolder() {
}

$Class* SignatureUtil$EdDSADigestAlgHolder::load$($String* name, bool initialize) {
	$loadClass(SignatureUtil$EdDSADigestAlgHolder, name, initialize, &_SignatureUtil$EdDSADigestAlgHolder_ClassInfo_, clinit$SignatureUtil$EdDSADigestAlgHolder, allocate$SignatureUtil$EdDSADigestAlgHolder);
	return class$;
}

$Class* SignatureUtil$EdDSADigestAlgHolder::class$ = nullptr;

		} // util
	} // security
} // sun