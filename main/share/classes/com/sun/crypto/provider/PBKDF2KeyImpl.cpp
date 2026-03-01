#include <com/sun/crypto/provider/PBKDF2KeyImpl.h>

#include <com/sun/crypto/provider/PBKDF2KeyImpl$1.h>
#include <com/sun/crypto/provider/SunJCE.h>
#include <java/io/Serializable.h>
#include <java/lang/Runnable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/ref/Cleaner$Cleanable.h>
#include <java/lang/ref/Cleaner.h>
#include <java/lang/ref/Reference.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/CharBuffer.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/StandardCharsets.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/Key.h>
#include <java/security/KeyRep$Type.h>
#include <java/security/KeyRep.h>
#include <java/security/MessageDigest.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/Provider.h>
#include <java/security/spec/InvalidKeySpecException.h>
#include <java/util/Arrays.h>
#include <java/util/Locale.h>
#include <javax/crypto/Mac.h>
#include <javax/crypto/SecretKey.h>
#include <javax/crypto/spec/PBEKeySpec.h>
#include <jdk/internal/ref/CleanerFactory.h>
#include <jcpp.h>

#undef ENGLISH
#undef SECRET
#undef UTF_8

using $PBKDF2KeyImpl$1 = ::com::sun::crypto::provider::PBKDF2KeyImpl$1;
using $SunJCE = ::com::sun::crypto::provider::SunJCE;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $RuntimeException = ::java::lang::RuntimeException;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Cleaner = ::java::lang::ref::Cleaner;
using $Reference = ::java::lang::ref::Reference;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $CharBuffer = ::java::nio::CharBuffer;
using $Charset = ::java::nio::charset::Charset;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $Key = ::java::security::Key;
using $KeyRep = ::java::security::KeyRep;
using $KeyRep$Type = ::java::security::KeyRep$Type;
using $MessageDigest = ::java::security::MessageDigest;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $Provider = ::java::security::Provider;
using $InvalidKeySpecException = ::java::security::spec::InvalidKeySpecException;
using $Arrays = ::java::util::Arrays;
using $Locale = ::java::util::Locale;
using $Mac = ::javax::crypto::Mac;
using $SecretKey = ::javax::crypto::SecretKey;
using $PBEKeySpec = ::javax::crypto::spec::PBEKeySpec;
using $CleanerFactory = ::jdk::internal::ref::CleanerFactory;

namespace com {
	namespace sun {
		namespace crypto {
			namespace provider {

class PBKDF2KeyImpl$$Lambda$lambda$new$0 : public $Runnable {
	$class(PBKDF2KeyImpl$$Lambda$lambda$new$0, $NO_CLASS_INIT, $Runnable)
public:
	void init$($bytes* k, $chars* p) {
		$set(this, k, k);
		$set(this, p, p);
	}
	virtual void run() override {
		PBKDF2KeyImpl::lambda$new$0(k, p);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<PBKDF2KeyImpl$$Lambda$lambda$new$0>());
	}
	$bytes* k = nullptr;
	$chars* p = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo PBKDF2KeyImpl$$Lambda$lambda$new$0::fieldInfos[3] = {
	{"k", "[B", nullptr, $PUBLIC, $field(PBKDF2KeyImpl$$Lambda$lambda$new$0, k)},
	{"p", "[C", nullptr, $PUBLIC, $field(PBKDF2KeyImpl$$Lambda$lambda$new$0, p)},
	{}
};
$MethodInfo PBKDF2KeyImpl$$Lambda$lambda$new$0::methodInfos[3] = {
	{"<init>", "([B[C)V", nullptr, $PUBLIC, $method(PBKDF2KeyImpl$$Lambda$lambda$new$0, init$, void, $bytes*, $chars*)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(PBKDF2KeyImpl$$Lambda$lambda$new$0, run, void)},
	{}
};
$ClassInfo PBKDF2KeyImpl$$Lambda$lambda$new$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"com.sun.crypto.provider.PBKDF2KeyImpl$$Lambda$lambda$new$0",
	"java.lang.Object",
	"java.lang.Runnable",
	fieldInfos,
	methodInfos
};
$Class* PBKDF2KeyImpl$$Lambda$lambda$new$0::load$($String* name, bool initialize) {
	$loadClass(PBKDF2KeyImpl$$Lambda$lambda$new$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* PBKDF2KeyImpl$$Lambda$lambda$new$0::class$ = nullptr;

$FieldInfo _PBKDF2KeyImpl_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $STATIC | $FINAL, $constField(PBKDF2KeyImpl, serialVersionUID)},
	{"passwd", "[C", nullptr, $PRIVATE, $field(PBKDF2KeyImpl, passwd)},
	{"salt", "[B", nullptr, $PRIVATE, $field(PBKDF2KeyImpl, salt)},
	{"iterCount", "I", nullptr, $PRIVATE, $field(PBKDF2KeyImpl, iterCount)},
	{"key", "[B", nullptr, $PRIVATE, $field(PBKDF2KeyImpl, key)},
	{"prf", "Ljavax/crypto/Mac;", nullptr, $PRIVATE, $field(PBKDF2KeyImpl, prf)},
	{}
};

$MethodInfo _PBKDF2KeyImpl_MethodInfo_[] = {
	{"<init>", "(Ljavax/crypto/spec/PBEKeySpec;Ljava/lang/String;)V", nullptr, 0, $method(PBKDF2KeyImpl, init$, void, $PBEKeySpec*, $String*), "java.security.spec.InvalidKeySpecException"},
	{"clearPassword", "()V", nullptr, $PUBLIC, $method(PBKDF2KeyImpl, clearPassword, void)},
	{"deriveKey", "(Ljavax/crypto/Mac;[B[BII)[B", nullptr, $PRIVATE | $STATIC, $staticMethod(PBKDF2KeyImpl, deriveKey, $bytes*, $Mac*, $bytes*, $bytes*, int32_t, int32_t)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(PBKDF2KeyImpl, equals, bool, Object$*)},
	{"getAlgorithm", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(PBKDF2KeyImpl, getAlgorithm, $String*)},
	{"getEncoded", "()[B", nullptr, $PUBLIC, $virtualMethod(PBKDF2KeyImpl, getEncoded, $bytes*)},
	{"getFormat", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(PBKDF2KeyImpl, getFormat, $String*)},
	{"getIterationCount", "()I", nullptr, $PUBLIC, $virtualMethod(PBKDF2KeyImpl, getIterationCount, int32_t)},
	{"getPassword", "()[C", nullptr, $PUBLIC, $virtualMethod(PBKDF2KeyImpl, getPassword, $chars*)},
	{"getPasswordBytes", "([C)[B", nullptr, $PRIVATE | $STATIC, $staticMethod(PBKDF2KeyImpl, getPasswordBytes, $bytes*, $chars*)},
	{"getSalt", "()[B", nullptr, $PUBLIC, $virtualMethod(PBKDF2KeyImpl, getSalt, $bytes*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(PBKDF2KeyImpl, hashCode, int32_t)},
	{"lambda$new$0", "([B[C)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(PBKDF2KeyImpl, lambda$new$0, void, $bytes*, $chars*)},
	{"writeReplace", "()Ljava/lang/Object;", nullptr, $PRIVATE, $method(PBKDF2KeyImpl, writeReplace, $Object*), "java.io.ObjectStreamException"},
	{}
};

$InnerClassInfo _PBKDF2KeyImpl_InnerClassesInfo_[] = {
	{"com.sun.crypto.provider.PBKDF2KeyImpl$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _PBKDF2KeyImpl_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"com.sun.crypto.provider.PBKDF2KeyImpl",
	"java.lang.Object",
	"javax.crypto.interfaces.PBEKey",
	_PBKDF2KeyImpl_FieldInfo_,
	_PBKDF2KeyImpl_MethodInfo_,
	nullptr,
	nullptr,
	_PBKDF2KeyImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	"com.sun.crypto.provider.PBKDF2KeyImpl$1"
};

$Object* allocate$PBKDF2KeyImpl($Class* clazz) {
	return $of($alloc(PBKDF2KeyImpl));
}

$bytes* PBKDF2KeyImpl::getPasswordBytes($chars* passwd) {
	$init(PBKDF2KeyImpl);
	$useLocalCurrentObjectStackCache();
	$var($CharBuffer, cb, $CharBuffer::wrap(passwd));
	$init($StandardCharsets);
	$var($ByteBuffer, bb, $nc($StandardCharsets::UTF_8)->encode(cb));
	int32_t len = $nc(bb)->limit();
	$var($bytes, passwdBytes, $new($bytes, len));
	bb->get(passwdBytes, 0, len);
	$nc($(bb->clear()))->put($$new($bytes, len));
	return passwdBytes;
}

void PBKDF2KeyImpl::init$($PBEKeySpec* keySpec, $String* prfAlgo) {
	$useLocalCurrentObjectStackCache();
	$var($chars, passwd, $nc(keySpec)->getPassword());
	if (passwd == nullptr) {
		$set(this, passwd, $new($chars, 0));
	} else {
		$set(this, passwd, $cast($chars, $nc(passwd)->clone()));
	}
	$var($bytes, passwdBytes, getPasswordBytes(this->passwd));
	if (passwd != nullptr) {
		$Arrays::fill(passwd, u'\0');
	}
	{
		$var($Throwable, var$0, nullptr);
		try {
			try {
				$set(this, salt, keySpec->getSalt());
				if (this->salt == nullptr) {
					$throwNew($InvalidKeySpecException, "Salt not found"_s);
				}
				this->iterCount = keySpec->getIterationCount();
				if (this->iterCount == 0) {
					$throwNew($InvalidKeySpecException, "Iteration count not found"_s);
				} else if (this->iterCount < 0) {
					$throwNew($InvalidKeySpecException, "Iteration count is negative"_s);
				}
				int32_t keyLength = keySpec->getKeyLength();
				if (keyLength == 0) {
					$throwNew($InvalidKeySpecException, "Key length not found"_s);
				} else if (keyLength < 0) {
					$throwNew($InvalidKeySpecException, "Key length is negative"_s);
				}
				$set(this, prf, $Mac::getInstance(prfAlgo, $(static_cast<$Provider*>($SunJCE::getInstance()))));
				$set(this, key, deriveKey(this->prf, passwdBytes, this->salt, this->iterCount, keyLength));
			} catch ($NoSuchAlgorithmException& nsae) {
				$var($InvalidKeySpecException, ike, $new($InvalidKeySpecException));
				ike->initCause(nsae);
				$throw(ike);
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$Arrays::fill(passwdBytes, (int8_t)0);
			$var($bytes, k, this->key);
			$var($chars, p, this->passwd);
			$nc($($CleanerFactory::cleaner()))->register$(this, static_cast<$Runnable*>($$new(PBKDF2KeyImpl$$Lambda$lambda$new$0, k, p)));
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

$bytes* PBKDF2KeyImpl::deriveKey($Mac* prf, $bytes* password, $bytes* salt, int32_t iterCount, int32_t keyLengthInBit) {
	$init(PBKDF2KeyImpl);
	$useLocalCurrentObjectStackCache();
	int32_t keyLength = keyLengthInBit / 8;
	$var($bytes, key, $new($bytes, keyLength));
	try {
		int32_t hlen = $nc(prf)->getMacLength();
		int32_t intL = $div((keyLength + hlen - 1), hlen);
		int32_t intR = keyLength - (intL - 1) * hlen;
		$var($bytes, ui, $new($bytes, hlen));
		$var($bytes, ti, $new($bytes, hlen));
		$var($SecretKey, macKey, $new($PBKDF2KeyImpl$1, prf, password));
		prf->init(macKey);
		$var($bytes, ibytes, $new($bytes, 4));
		for (int32_t i = 1; i <= intL; ++i) {
			prf->update(salt);
			ibytes->set(3, (int8_t)i);
			ibytes->set(2, (int8_t)((int32_t)((i >> 8) & (uint32_t)255)));
			ibytes->set(1, (int8_t)((int32_t)((i >> 16) & (uint32_t)255)));
			ibytes->set(0, (int8_t)((int32_t)((i >> 24) & (uint32_t)255)));
			prf->update(ibytes);
			prf->doFinal(ui, 0);
			$System::arraycopy(ui, 0, ti, 0, ui->length);
			for (int32_t j = 2; j <= iterCount; ++j) {
				prf->update(ui);
				prf->doFinal(ui, 0);
				for (int32_t k = 0; k < ui->length; ++k) {
					(*ti)[k] ^= ui->get(k);
				}
			}
			if (i == intL) {
				$System::arraycopy(ti, 0, key, (i - 1) * hlen, intR);
			} else {
				$System::arraycopy(ti, 0, key, (i - 1) * hlen, hlen);
			}
		}
	} catch ($GeneralSecurityException& gse) {
		$throwNew($RuntimeException, "Error deriving PBKDF2 keys"_s, gse);
	}
	return key;
}

$bytes* PBKDF2KeyImpl::getEncoded() {
	$var($bytes, result, $cast($bytes, $nc(this->key)->clone()));
	$Reference::reachabilityFence(this);
	return result;
}

$String* PBKDF2KeyImpl::getAlgorithm() {
	return $str({"PBKDF2With"_s, $($nc(this->prf)->getAlgorithm())});
}

int32_t PBKDF2KeyImpl::getIterationCount() {
	return this->iterCount;
}

void PBKDF2KeyImpl::clearPassword() {
	$Arrays::fill(this->passwd, (char16_t)0);
}

$chars* PBKDF2KeyImpl::getPassword() {
	$var($chars, result, $cast($chars, $nc(this->passwd)->clone()));
	$Reference::reachabilityFence(this);
	return result;
}

$bytes* PBKDF2KeyImpl::getSalt() {
	return $cast($bytes, $nc(this->salt)->clone());
}

$String* PBKDF2KeyImpl::getFormat() {
	return "RAW"_s;
}

int32_t PBKDF2KeyImpl::hashCode() {
	$useLocalCurrentObjectStackCache();
	int32_t retval = 0;
	for (int32_t i = 1; i < $nc(this->key)->length; ++i) {
		retval += $nc(this->key)->get(i) * i;
	}
	$init($Locale);
	return (retval ^= $($nc($(getAlgorithm()))->toLowerCase($Locale::ENGLISH))->hashCode());
}

bool PBKDF2KeyImpl::equals(Object$* obj) {
	$useLocalCurrentObjectStackCache();
	if ($equals(obj, this)) {
		return true;
	}
	if (!($instanceOf($SecretKey, obj))) {
		return false;
	}
	$var($SecretKey, that, $cast($SecretKey, obj));
	if (!($nc($($nc(that)->getAlgorithm()))->equalsIgnoreCase($(getAlgorithm())))) {
		return false;
	}
	if (!($nc($($nc(that)->getFormat()))->equalsIgnoreCase("RAW"_s))) {
		return false;
	}
	$var($bytes, thatEncoded, $nc(that)->getEncoded());
	bool ret = $MessageDigest::isEqual(this->key, thatEncoded);
	$Arrays::fill(thatEncoded, (int8_t)0);
	return ret;
}

$Object* PBKDF2KeyImpl::writeReplace() {
	$useLocalCurrentObjectStackCache();
	$init($KeyRep$Type);
	$var($KeyRep$Type, var$0, $KeyRep$Type::SECRET);
	$var($String, var$1, getAlgorithm());
	return $of($new($KeyRep, var$0, var$1, $(getFormat()), this->key));
}

void PBKDF2KeyImpl::lambda$new$0($bytes* k, $chars* p) {
	$init(PBKDF2KeyImpl);
	$Arrays::fill(k, (int8_t)0);
	$Arrays::fill(p, u'\0');
}

PBKDF2KeyImpl::PBKDF2KeyImpl() {
}

$Class* PBKDF2KeyImpl::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(PBKDF2KeyImpl$$Lambda$lambda$new$0::classInfo$.name)) {
			return PBKDF2KeyImpl$$Lambda$lambda$new$0::load$(name, initialize);
		}
	}
	$loadClass(PBKDF2KeyImpl, name, initialize, &_PBKDF2KeyImpl_ClassInfo_, allocate$PBKDF2KeyImpl);
	return class$;
}

$Class* PBKDF2KeyImpl::class$ = nullptr;

			} // provider
		} // crypto
	} // sun
} // com