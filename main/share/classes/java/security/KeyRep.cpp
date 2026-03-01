#include <java/security/KeyRep.h>

#include <java/io/NotSerializableException.h>
#include <java/security/KeyFactory.h>
#include <java/security/KeyRep$Type.h>
#include <java/security/PrivateKey.h>
#include <java/security/PublicKey.h>
#include <java/security/spec/KeySpec.h>
#include <java/security/spec/PKCS8EncodedKeySpec.h>
#include <java/security/spec/X509EncodedKeySpec.h>
#include <java/util/Locale.h>
#include <javax/crypto/spec/SecretKeySpec.h>
#include <jcpp.h>

#undef ENGLISH
#undef PKCS8
#undef PRIVATE
#undef PUBLIC
#undef RAW
#undef SECRET

using $NotSerializableException = ::java::io::NotSerializableException;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $KeyFactory = ::java::security::KeyFactory;
using $KeyRep$Type = ::java::security::KeyRep$Type;
using $KeySpec = ::java::security::spec::KeySpec;
using $PKCS8EncodedKeySpec = ::java::security::spec::PKCS8EncodedKeySpec;
using $X509EncodedKeySpec = ::java::security::spec::X509EncodedKeySpec;
using $Locale = ::java::util::Locale;
using $SecretKeySpec = ::javax::crypto::spec::SecretKeySpec;

namespace java {
	namespace security {

$FieldInfo _KeyRep_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(KeyRep, serialVersionUID)},
	{"PKCS8", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(KeyRep, PKCS8)},
	{"X509", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(KeyRep, X509)},
	{"RAW", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(KeyRep, RAW)},
	{"type", "Ljava/security/KeyRep$Type;", nullptr, $PRIVATE, $field(KeyRep, type)},
	{"algorithm", "Ljava/lang/String;", nullptr, $PRIVATE, $field(KeyRep, algorithm)},
	{"format", "Ljava/lang/String;", nullptr, $PRIVATE, $field(KeyRep, format)},
	{"encoded", "[B", nullptr, $PRIVATE, $field(KeyRep, encoded)},
	{}
};

$MethodInfo _KeyRep_MethodInfo_[] = {
	{"<init>", "(Ljava/security/KeyRep$Type;Ljava/lang/String;Ljava/lang/String;[B)V", nullptr, $PUBLIC, $method(KeyRep, init$, void, $KeyRep$Type*, $String*, $String*, $bytes*)},
	{"readResolve", "()Ljava/lang/Object;", nullptr, $PROTECTED, $virtualMethod(KeyRep, readResolve, $Object*), "java.io.ObjectStreamException"},
	{}
};

$InnerClassInfo _KeyRep_InnerClassesInfo_[] = {
	{"java.security.KeyRep$Type", "java.security.KeyRep", "Type", $PUBLIC | $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _KeyRep_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.security.KeyRep",
	"java.lang.Object",
	"java.io.Serializable",
	_KeyRep_FieldInfo_,
	_KeyRep_MethodInfo_,
	nullptr,
	nullptr,
	_KeyRep_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.security.KeyRep$Type"
};

$Object* allocate$KeyRep($Class* clazz) {
	return $of($alloc(KeyRep));
}

$String* KeyRep::PKCS8 = nullptr;
$String* KeyRep::X509 = nullptr;
$String* KeyRep::RAW = nullptr;

void KeyRep::init$($KeyRep$Type* type, $String* algorithm, $String* format, $bytes* encoded) {
	if (type == nullptr || algorithm == nullptr || format == nullptr || encoded == nullptr) {
		$throwNew($NullPointerException, "invalid null input(s)"_s);
	}
	$set(this, type, type);
	$set(this, algorithm, algorithm);
	$init($Locale);
	$set(this, format, $nc(format)->toUpperCase($Locale::ENGLISH));
	$set(this, encoded, $cast($bytes, $nc(encoded)->clone()));
}

$Object* KeyRep::readResolve() {
	$useLocalCurrentObjectStackCache();
	try {
		$init($KeyRep$Type);
		if (this->type == $KeyRep$Type::SECRET && $nc(KeyRep::RAW)->equals(this->format)) {
			return $of($new($SecretKeySpec, this->encoded, this->algorithm));
		} else {
			if (this->type == $KeyRep$Type::PUBLIC && $nc(KeyRep::X509)->equals(this->format)) {
				$var($KeyFactory, f, $KeyFactory::getInstance(this->algorithm));
				return $of($nc(f)->generatePublic($$new($X509EncodedKeySpec, this->encoded)));
			} else {
				if (this->type == $KeyRep$Type::PRIVATE && $nc(KeyRep::PKCS8)->equals(this->format)) {
					$var($KeyFactory, f, $KeyFactory::getInstance(this->algorithm));
					return $of($nc(f)->generatePrivate($$new($PKCS8EncodedKeySpec, this->encoded)));
				} else {
					$throwNew($NotSerializableException, $$str({"unrecognized type/format combination: "_s, this->type, "/"_s, this->format}));
				}
			}
		}
	} catch ($NotSerializableException& nse) {
		$throw(nse);
	} catch ($Exception& e) {
		$var($NotSerializableException, nse, $new($NotSerializableException, $$str({"java.security.Key: ["_s, this->type, "] ["_s, this->algorithm, "] ["_s, this->format, "]"_s})));
		nse->initCause(e);
		$throw(nse);
	}
	$shouldNotReachHere();
}

KeyRep::KeyRep() {
}

void clinit$KeyRep($Class* class$) {
	$assignStatic(KeyRep::PKCS8, "PKCS#8"_s);
	$assignStatic(KeyRep::X509, "X.509"_s);
	$assignStatic(KeyRep::RAW, "RAW"_s);
}

$Class* KeyRep::load$($String* name, bool initialize) {
	$loadClass(KeyRep, name, initialize, &_KeyRep_ClassInfo_, clinit$KeyRep, allocate$KeyRep);
	return class$;
}

$Class* KeyRep::class$ = nullptr;

	} // security
} // java