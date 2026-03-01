#include <com/sun/crypto/provider/SealedObjectForKeyProtector.h>

#include <com/sun/crypto/provider/SealedObjectForKeyProtector$DeserializationChecker.h>
#include <com/sun/crypto/provider/SunJCE.h>
#include <java/io/IOException.h>
#include <java/io/InvalidClassException.h>
#include <java/io/ObjectInputFilter.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/CharSequence.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/security/AccessController.h>
#include <java/security/AlgorithmParameters.h>
#include <java/security/Key.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/Provider.h>
#include <javax/crypto/Cipher.h>
#include <javax/crypto/SealedObject.h>
#include <jdk/internal/access/JavaxCryptoSealedObjectAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jcpp.h>

#undef KEY_SERIAL_FILTER

using $SealedObjectForKeyProtector$DeserializationChecker = ::com::sun::crypto::provider::SealedObjectForKeyProtector$DeserializationChecker;
using $SunJCE = ::com::sun::crypto::provider::SunJCE;
using $IOException = ::java::io::IOException;
using $InvalidClassException = ::java::io::InvalidClassException;
using $ObjectInputFilter = ::java::io::ObjectInputFilter;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $Serializable = ::java::io::Serializable;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $Void = ::java::lang::Void;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $AccessController = ::java::security::AccessController;
using $AlgorithmParameters = ::java::security::AlgorithmParameters;
using $Key = ::java::security::Key;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Provider = ::java::security::Provider;
using $Cipher = ::javax::crypto::Cipher;
using $SealedObject = ::javax::crypto::SealedObject;
using $JavaxCryptoSealedObjectAccess = ::jdk::internal::access::JavaxCryptoSealedObjectAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;

namespace com {
	namespace sun {
		namespace crypto {
			namespace provider {

class SealedObjectForKeyProtector$$Lambda$lambda$getKey$0 : public $PrivilegedAction {
	$class(SealedObjectForKeyProtector$$Lambda$lambda$getKey$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$($ObjectInputStream* ois, int32_t maxLength) {
		$set(this, ois, ois);
		this->maxLength = maxLength;
	}
	virtual $Object* run() override {
		 return $of(SealedObjectForKeyProtector::lambda$getKey$0(ois, maxLength));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SealedObjectForKeyProtector$$Lambda$lambda$getKey$0>());
	}
	$ObjectInputStream* ois = nullptr;
	int32_t maxLength = 0;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo SealedObjectForKeyProtector$$Lambda$lambda$getKey$0::fieldInfos[3] = {
	{"ois", "Ljava/io/ObjectInputStream;", nullptr, $PUBLIC, $field(SealedObjectForKeyProtector$$Lambda$lambda$getKey$0, ois)},
	{"maxLength", "I", nullptr, $PUBLIC, $field(SealedObjectForKeyProtector$$Lambda$lambda$getKey$0, maxLength)},
	{}
};
$MethodInfo SealedObjectForKeyProtector$$Lambda$lambda$getKey$0::methodInfos[3] = {
	{"<init>", "(Ljava/io/ObjectInputStream;I)V", nullptr, $PUBLIC, $method(SealedObjectForKeyProtector$$Lambda$lambda$getKey$0, init$, void, $ObjectInputStream*, int32_t)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(SealedObjectForKeyProtector$$Lambda$lambda$getKey$0, run, $Object*)},
	{}
};
$ClassInfo SealedObjectForKeyProtector$$Lambda$lambda$getKey$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"com.sun.crypto.provider.SealedObjectForKeyProtector$$Lambda$lambda$getKey$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* SealedObjectForKeyProtector$$Lambda$lambda$getKey$0::load$($String* name, bool initialize) {
	$loadClass(SealedObjectForKeyProtector$$Lambda$lambda$getKey$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SealedObjectForKeyProtector$$Lambda$lambda$getKey$0::class$ = nullptr;

$FieldInfo _SealedObjectForKeyProtector_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $STATIC | $FINAL, $constField(SealedObjectForKeyProtector, serialVersionUID)},
	{"KEY_SERIAL_FILTER", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SealedObjectForKeyProtector, KEY_SERIAL_FILTER)},
	{}
};

$MethodInfo _SealedObjectForKeyProtector_MethodInfo_[] = {
	{"<init>", "(Ljava/io/Serializable;Ljavax/crypto/Cipher;)V", nullptr, 0, $method(SealedObjectForKeyProtector, init$, void, $Serializable*, $Cipher*), "java.io.IOException,javax.crypto.IllegalBlockSizeException"},
	{"<init>", "(Ljavax/crypto/SealedObject;)V", nullptr, 0, $method(SealedObjectForKeyProtector, init$, void, $SealedObject*)},
	{"getKey", "(Ljavax/crypto/Cipher;I)Ljava/security/Key;", nullptr, $FINAL, $method(SealedObjectForKeyProtector, getKey, $Key*, $Cipher*, int32_t), "java.io.IOException,java.lang.ClassNotFoundException,javax.crypto.IllegalBlockSizeException,javax.crypto.BadPaddingException"},
	{"getParameters", "()Ljava/security/AlgorithmParameters;", nullptr, 0, $method(SealedObjectForKeyProtector, getParameters, $AlgorithmParameters*)},
	{"lambda$getKey$0", "(Ljava/io/ObjectInputStream;I)Ljava/lang/Void;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(SealedObjectForKeyProtector, lambda$getKey$0, $Void*, $ObjectInputStream*, int32_t)},
	{}
};

$InnerClassInfo _SealedObjectForKeyProtector_InnerClassesInfo_[] = {
	{"com.sun.crypto.provider.SealedObjectForKeyProtector$DeserializationChecker", "com.sun.crypto.provider.SealedObjectForKeyProtector", "DeserializationChecker", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _SealedObjectForKeyProtector_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"com.sun.crypto.provider.SealedObjectForKeyProtector",
	"javax.crypto.SealedObject",
	nullptr,
	_SealedObjectForKeyProtector_FieldInfo_,
	_SealedObjectForKeyProtector_MethodInfo_,
	nullptr,
	nullptr,
	_SealedObjectForKeyProtector_InnerClassesInfo_,
	nullptr,
	nullptr,
	"com.sun.crypto.provider.SealedObjectForKeyProtector$DeserializationChecker"
};

$Object* allocate$SealedObjectForKeyProtector($Class* clazz) {
	return $of($alloc(SealedObjectForKeyProtector));
}

$String* SealedObjectForKeyProtector::KEY_SERIAL_FILTER = nullptr;

void SealedObjectForKeyProtector::init$($Serializable* object, $Cipher* c) {
	$SealedObject::init$(object, c);
}

void SealedObjectForKeyProtector::init$($SealedObject* so) {
	$SealedObject::init$(so);
}

$AlgorithmParameters* SealedObjectForKeyProtector::getParameters() {
	$useLocalCurrentObjectStackCache();
	$var($AlgorithmParameters, params, nullptr);
	if (this->encodedParams != nullptr) {
		try {
			$assign(params, $AlgorithmParameters::getInstance("PBE"_s, $(static_cast<$Provider*>($SunJCE::getInstance()))));
			$nc(params)->init(this->encodedParams);
		} catch ($NoSuchAlgorithmException& nsae) {
			$throwNew($RuntimeException, "SunJCE provider is not configured properly"_s);
		} catch ($IOException& io) {
			$throwNew($RuntimeException, $$str({"Parameter failure: "_s, $(io->getMessage())}));
		}
	}
	return params;
}

$Key* SealedObjectForKeyProtector::getKey($Cipher* c, int32_t maxLength) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	{
		$var($ObjectInputStream, ois, $nc($($SharedSecrets::getJavaxCryptoSealedObjectAccess()))->getExtObjectInputStream(this, c));
		{
			$var($Throwable, var$0, nullptr);
			$var($Key, var$2, nullptr);
			bool return$1 = false;
			try {
				try {
					$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(SealedObjectForKeyProtector$$Lambda$lambda$getKey$0, ois, maxLength)));
					try {
						$var($Key, t, $cast($Key, $nc(ois)->readObject()));
						$assign(var$2, t);
						return$1 = true;
						goto $finally;
					} catch ($InvalidClassException& ice) {
						$var($String, msg, ice->getMessage());
						if ($nc(msg)->contains("REJECTED"_s)) {
							$throwNew($IOException, "Rejected by the jceks.key.serialFilter or jdk.serialFilter property"_s, ice);
						} else {
							$throw(ice);
						}
					}
				} catch ($Throwable& t$) {
					if (ois != nullptr) {
						try {
							ois->close();
						} catch ($Throwable& x2) {
							t$->addSuppressed(x2);
						}
					}
					$throw(t$);
				}
			} catch ($Throwable& var$3) {
				$assign(var$0, var$3);
			} $finally: {
				if (ois != nullptr) {
					ois->close();
				}
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
			if (return$1) {
				return var$2;
			}
		}
	}
	$shouldNotReachHere();
}

$Void* SealedObjectForKeyProtector::lambda$getKey$0($ObjectInputStream* ois, int32_t maxLength) {
	$init(SealedObjectForKeyProtector);
	$nc(ois)->setObjectInputFilter($$new($SealedObjectForKeyProtector$DeserializationChecker, maxLength));
	return nullptr;
}

SealedObjectForKeyProtector::SealedObjectForKeyProtector() {
}

void clinit$SealedObjectForKeyProtector($Class* class$) {
	$assignStatic(SealedObjectForKeyProtector::KEY_SERIAL_FILTER, "jceks.key.serialFilter"_s);
}

$Class* SealedObjectForKeyProtector::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(SealedObjectForKeyProtector$$Lambda$lambda$getKey$0::classInfo$.name)) {
			return SealedObjectForKeyProtector$$Lambda$lambda$getKey$0::load$(name, initialize);
		}
	}
	$loadClass(SealedObjectForKeyProtector, name, initialize, &_SealedObjectForKeyProtector_ClassInfo_, clinit$SealedObjectForKeyProtector, allocate$SealedObjectForKeyProtector);
	return class$;
}

$Class* SealedObjectForKeyProtector::class$ = nullptr;

			} // provider
		} // crypto
	} // sun
} // com