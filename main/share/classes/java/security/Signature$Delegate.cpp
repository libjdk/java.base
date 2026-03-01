#include <java/security/Signature$Delegate.h>

#include <java/lang/AssertionError.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/Cloneable.h>
#include <java/nio/ByteBuffer.h>
#include <java/security/AlgorithmParameters.h>
#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/InvalidKeyException.h>
#include <java/security/Key.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/PrivateKey.h>
#include <java/security/Provider$Service.h>
#include <java/security/Provider.h>
#include <java/security/ProviderException.h>
#include <java/security/PublicKey.h>
#include <java/security/SecureRandom.h>
#include <java/security/Signature$CipherAdapter.h>
#include <java/security/Signature$Delegate$CloneableDelegate.h>
#include <java/security/Signature.h>
#include <java/security/SignatureSpi.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/util/Iterator.h>
#include <javax/crypto/Cipher.h>
#include <javax/crypto/NoSuchPaddingException.h>
#include <sun/security/util/Debug.h>
#include <jcpp.h>

#undef I_PRIV
#undef I_PRIV_PARAM_SR
#undef I_PRIV_SR
#undef I_PUB
#undef I_PUB_PARAM
#undef S_PARAM

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $Cloneable = ::java::lang::Cloneable;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $AlgorithmParameters = ::java::security::AlgorithmParameters;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $InvalidKeyException = ::java::security::InvalidKeyException;
using $Key = ::java::security::Key;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $PrivateKey = ::java::security::PrivateKey;
using $Provider$Service = ::java::security::Provider$Service;
using $ProviderException = ::java::security::ProviderException;
using $PublicKey = ::java::security::PublicKey;
using $SecureRandom = ::java::security::SecureRandom;
using $Signature = ::java::security::Signature;
using $Signature$CipherAdapter = ::java::security::Signature$CipherAdapter;
using $Signature$Delegate$CloneableDelegate = ::java::security::Signature$Delegate$CloneableDelegate;
using $SignatureSpi = ::java::security::SignatureSpi;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $Iterator = ::java::util::Iterator;
using $Cipher = ::javax::crypto::Cipher;
using $NoSuchPaddingException = ::javax::crypto::NoSuchPaddingException;
using $Debug = ::sun::security::util::Debug;

namespace java {
	namespace security {

$FieldInfo _Signature$Delegate_FieldInfo_[] = {
	{"sigSpi", "Ljava/security/SignatureSpi;", nullptr, $PRIVATE, $field(Signature$Delegate, sigSpi)},
	{"lock", "Ljava/lang/Object;", nullptr, $PRIVATE | $FINAL, $field(Signature$Delegate, lock)},
	{"firstService", "Ljava/security/Provider$Service;", nullptr, $PRIVATE, $field(Signature$Delegate, firstService)},
	{"serviceIterator", "Ljava/util/Iterator;", "Ljava/util/Iterator<Ljava/security/Provider$Service;>;", $PRIVATE, $field(Signature$Delegate, serviceIterator)},
	{"warnCount", "I", nullptr, $PRIVATE | $STATIC, $staticField(Signature$Delegate, warnCount)},
	{"I_PUB", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Signature$Delegate, I_PUB)},
	{"I_PRIV", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Signature$Delegate, I_PRIV)},
	{"I_PRIV_SR", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Signature$Delegate, I_PRIV_SR)},
	{"I_PUB_PARAM", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Signature$Delegate, I_PUB_PARAM)},
	{"I_PRIV_PARAM_SR", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Signature$Delegate, I_PRIV_PARAM_SR)},
	{"S_PARAM", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Signature$Delegate, S_PARAM)},
	{}
};

$MethodInfo _Signature$Delegate_MethodInfo_[] = {
	{"<init>", "(Ljava/security/SignatureSpi;Ljava/lang/String;)V", nullptr, $PRIVATE, $method(Signature$Delegate, init$, void, $SignatureSpi*, $String*)},
	{"<init>", "(Ljava/security/Provider$Service;Ljava/util/Iterator;Ljava/lang/String;)V", "(Ljava/security/Provider$Service;Ljava/util/Iterator<Ljava/security/Provider$Service;>;Ljava/lang/String;)V", $PRIVATE, $method(Signature$Delegate, init$, void, $Provider$Service*, $Iterator*, $String*)},
	{"chooseFirstProvider", "()V", nullptr, 0, $virtualMethod(Signature$Delegate, chooseFirstProvider, void)},
	{"chooseProvider", "(ILjava/security/Key;Ljava/security/spec/AlgorithmParameterSpec;Ljava/security/SecureRandom;)V", nullptr, $PRIVATE, $method(Signature$Delegate, chooseProvider, void, int32_t, $Key*, $AlgorithmParameterSpec*, $SecureRandom*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Signature$Delegate, clone, $Object*), "java.lang.CloneNotSupportedException"},
	{"engineGetParameter", "(Ljava/lang/String;)Ljava/lang/Object;", nullptr, $PROTECTED, $virtualMethod(Signature$Delegate, engineGetParameter, $Object*, $String*), "java.security.InvalidParameterException"},
	{"engineGetParameters", "()Ljava/security/AlgorithmParameters;", nullptr, $PROTECTED, $virtualMethod(Signature$Delegate, engineGetParameters, $AlgorithmParameters*)},
	{"engineInitSign", "(Ljava/security/PrivateKey;)V", nullptr, $PROTECTED, $virtualMethod(Signature$Delegate, engineInitSign, void, $PrivateKey*), "java.security.InvalidKeyException"},
	{"engineInitSign", "(Ljava/security/PrivateKey;Ljava/security/SecureRandom;)V", nullptr, $PROTECTED, $virtualMethod(Signature$Delegate, engineInitSign, void, $PrivateKey*, $SecureRandom*), "java.security.InvalidKeyException"},
	{"engineInitSign", "(Ljava/security/PrivateKey;Ljava/security/spec/AlgorithmParameterSpec;Ljava/security/SecureRandom;)V", nullptr, 0, $virtualMethod(Signature$Delegate, engineInitSign, void, $PrivateKey*, $AlgorithmParameterSpec*, $SecureRandom*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"engineInitVerify", "(Ljava/security/PublicKey;)V", nullptr, $PROTECTED, $virtualMethod(Signature$Delegate, engineInitVerify, void, $PublicKey*), "java.security.InvalidKeyException"},
	{"engineInitVerify", "(Ljava/security/PublicKey;Ljava/security/spec/AlgorithmParameterSpec;)V", nullptr, 0, $virtualMethod(Signature$Delegate, engineInitVerify, void, $PublicKey*, $AlgorithmParameterSpec*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{"engineSetParameter", "(Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PROTECTED, $virtualMethod(Signature$Delegate, engineSetParameter, void, $String*, Object$*), "java.security.InvalidParameterException"},
	{"engineSetParameter", "(Ljava/security/spec/AlgorithmParameterSpec;)V", nullptr, $PROTECTED, $virtualMethod(Signature$Delegate, engineSetParameter, void, $AlgorithmParameterSpec*), "java.security.InvalidAlgorithmParameterException"},
	{"engineSign", "()[B", nullptr, $PROTECTED, $virtualMethod(Signature$Delegate, engineSign, $bytes*), "java.security.SignatureException"},
	{"engineSign", "([BII)I", nullptr, $PROTECTED, $virtualMethod(Signature$Delegate, engineSign, int32_t, $bytes*, int32_t, int32_t), "java.security.SignatureException"},
	{"engineUpdate", "(B)V", nullptr, $PROTECTED, $virtualMethod(Signature$Delegate, engineUpdate, void, int8_t), "java.security.SignatureException"},
	{"engineUpdate", "([BII)V", nullptr, $PROTECTED, $virtualMethod(Signature$Delegate, engineUpdate, void, $bytes*, int32_t, int32_t), "java.security.SignatureException"},
	{"engineUpdate", "(Ljava/nio/ByteBuffer;)V", nullptr, $PROTECTED, $virtualMethod(Signature$Delegate, engineUpdate, void, $ByteBuffer*)},
	{"engineVerify", "([B)Z", nullptr, $PROTECTED, $virtualMethod(Signature$Delegate, engineVerify, bool, $bytes*), "java.security.SignatureException"},
	{"engineVerify", "([BII)Z", nullptr, $PROTECTED, $virtualMethod(Signature$Delegate, engineVerify, bool, $bytes*, int32_t, int32_t), "java.security.SignatureException"},
	{"newInstance", "(Ljava/security/Provider$Service;)Ljava/security/SignatureSpi;", nullptr, $PRIVATE | $STATIC, $staticMethod(Signature$Delegate, newInstance, $SignatureSpi*, $Provider$Service*), "java.security.NoSuchAlgorithmException"},
	{"of", "(Ljava/security/SignatureSpi;Ljava/lang/String;)Ljava/security/Signature$Delegate;", nullptr, $STATIC, $staticMethod(Signature$Delegate, of, Signature$Delegate*, $SignatureSpi*, $String*)},
	{"tryOperation", "(Ljava/security/SignatureSpi;ILjava/security/Key;Ljava/security/spec/AlgorithmParameterSpec;Ljava/security/SecureRandom;)V", nullptr, $PRIVATE, $method(Signature$Delegate, tryOperation, void, $SignatureSpi*, int32_t, $Key*, $AlgorithmParameterSpec*, $SecureRandom*), "java.security.InvalidKeyException,java.security.InvalidAlgorithmParameterException"},
	{}
};

$InnerClassInfo _Signature$Delegate_InnerClassesInfo_[] = {
	{"java.security.Signature$Delegate", "java.security.Signature", "Delegate", $PRIVATE | $STATIC},
	{"java.security.Signature$Delegate$CloneableDelegate", "java.security.Signature$Delegate", "CloneableDelegate", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _Signature$Delegate_ClassInfo_ = {
	$ACC_SUPER,
	"java.security.Signature$Delegate",
	"java.security.Signature",
	nullptr,
	_Signature$Delegate_FieldInfo_,
	_Signature$Delegate_MethodInfo_,
	nullptr,
	nullptr,
	_Signature$Delegate_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.security.Signature"
};

$Object* allocate$Signature$Delegate($Class* clazz) {
	return $of($alloc(Signature$Delegate));
}

int32_t Signature$Delegate::warnCount = 0;

Signature$Delegate* Signature$Delegate::of($SignatureSpi* sigSpi, $String* algorithm) {
	$init(Signature$Delegate);
	if ($instanceOf($Cloneable, sigSpi)) {
		return $new($Signature$Delegate$CloneableDelegate, sigSpi, algorithm);
	} else {
		return $new(Signature$Delegate, sigSpi, algorithm);
	}
}

void Signature$Delegate::init$($SignatureSpi* sigSpi, $String* algorithm) {
	$Signature::init$(algorithm);
	$set(this, sigSpi, sigSpi);
	$set(this, lock, nullptr);
}

void Signature$Delegate::init$($Provider$Service* service, $Iterator* iterator, $String* algorithm) {
	$Signature::init$(algorithm);
	$set(this, firstService, service);
	$set(this, serviceIterator, iterator);
	$set(this, lock, $new($Object));
}

$Object* Signature$Delegate::clone() {
	$useLocalCurrentObjectStackCache();
	chooseFirstProvider();
	if ($instanceOf($Cloneable, this->sigSpi)) {
		$var($Signature, that, $new($Signature$Delegate$CloneableDelegate, $cast($SignatureSpi, $($nc(this->sigSpi)->clone())), $nc((static_cast<$Signature*>(this)))->algorithm));
		$set(that, provider, $nc((static_cast<$Signature*>(this)))->provider);
		return $of(that);
	} else {
		$throwNew($CloneNotSupportedException);
	}
}

$SignatureSpi* Signature$Delegate::newInstance($Provider$Service* s) {
	$init(Signature$Delegate);
	$useLocalCurrentObjectStackCache();
	if ($nc($($nc(s)->getType()))->equals("Cipher"_s)) {
		try {
			$var($Cipher, c, $Cipher::getInstance("RSA/ECB/PKCS1Padding"_s, $(s->getProvider())));
			return $new($Signature$CipherAdapter, c);
		} catch ($NoSuchPaddingException& e) {
			$throwNew($NoSuchAlgorithmException, static_cast<$Throwable*>(e));
		}
	} else {
		$var($Object, o, s->newInstance(nullptr));
		if (!($instanceOf($SignatureSpi, o))) {
			$throwNew($NoSuchAlgorithmException, $$str({"Not a SignatureSpi: "_s, $($nc($of(o))->getClass()->getName())}));
		}
		return $cast($SignatureSpi, o);
	}
}

void Signature$Delegate::chooseFirstProvider() {
	$useLocalCurrentObjectStackCache();
	if (this->sigSpi != nullptr) {
		return;
	}
	$synchronized(this->lock) {
		if (this->sigSpi != nullptr) {
			return;
		}
		$init($Signature);
		if ($Signature::debug != nullptr) {
			int32_t w = --Signature$Delegate::warnCount;
			if (w >= 0) {
				$nc($Signature::debug)->println("Signature.init() not first method called, disabling delayed provider selection"_s);
				if (w == 0) {
					$nc($Signature::debug)->println("Further warnings of this type will be suppressed"_s);
				}
				$$new($Exception, "Debug call trace"_s)->printStackTrace();
			}
		}
		$var($Exception, lastException, nullptr);
		while ((this->firstService != nullptr) || $nc(this->serviceIterator)->hasNext()) {
			$var($Provider$Service, s, nullptr);
			if (this->firstService != nullptr) {
				$assign(s, this->firstService);
				$set(this, firstService, nullptr);
			} else {
				$assign(s, $cast($Provider$Service, $nc(this->serviceIterator)->next()));
			}
			if ($Signature::isSpi(s) == false) {
				continue;
			}
			try {
				$set(this, sigSpi, newInstance(s));
				$set(this, provider, $nc(s)->getProvider());
				$set(this, firstService, nullptr);
				$set(this, serviceIterator, nullptr);
				return;
			} catch ($NoSuchAlgorithmException& e) {
				$assign(lastException, e);
			}
		}
		$var($ProviderException, e, $new($ProviderException, "Could not construct SignatureSpi instance"_s));
		if (lastException != nullptr) {
			e->initCause(lastException);
		}
		$throw(e);
	}
}

void Signature$Delegate::chooseProvider(int32_t type, $Key* key, $AlgorithmParameterSpec* params, $SecureRandom* random) {
	$useLocalCurrentObjectStackCache();
	$synchronized(this->lock) {
		if (this->sigSpi != nullptr) {
			return;
		}
		$var($Exception, lastException, nullptr);
		while ((this->firstService != nullptr) || $nc(this->serviceIterator)->hasNext()) {
			$var($Provider$Service, s, nullptr);
			if (this->firstService != nullptr) {
				$assign(s, this->firstService);
				$set(this, firstService, nullptr);
			} else {
				$assign(s, $cast($Provider$Service, $nc(this->serviceIterator)->next()));
			}
			if (key != nullptr && $nc(s)->supportsParameter(key) == false) {
				continue;
			}
			if ($Signature::isSpi(s) == false) {
				continue;
			}
			try {
				$var($SignatureSpi, spi, newInstance(s));
				tryOperation(spi, type, key, params, random);
				$set(this, provider, $nc(s)->getProvider());
				$set(this, sigSpi, spi);
				$set(this, firstService, nullptr);
				$set(this, serviceIterator, nullptr);
				return;
			} catch ($Exception& e) {
				if (lastException == nullptr) {
					$assign(lastException, e);
				}
			}
		}
		if ($instanceOf($InvalidKeyException, lastException)) {
			$throw($cast($InvalidKeyException, lastException));
		}
		if ($instanceOf($RuntimeException, lastException)) {
			$throw($cast($RuntimeException, lastException));
		}
		if ($instanceOf($InvalidAlgorithmParameterException, lastException)) {
			$throw($cast($InvalidAlgorithmParameterException, lastException));
		}
		$var($String, k, (key != nullptr) ? $nc($of(key))->getClass()->getName() : "(null)"_s);
		$throwNew($InvalidKeyException, $$str({"No installed provider supports this key: "_s, k}), lastException);
	}
}

void Signature$Delegate::tryOperation($SignatureSpi* spi, int32_t type, $Key* key, $AlgorithmParameterSpec* params, $SecureRandom* random) {
	$useLocalCurrentObjectStackCache();
	switch (type) {
	case Signature$Delegate::I_PUB:
		{
			$nc(spi)->engineInitVerify($cast($PublicKey, key));
			break;
		}
	case Signature$Delegate::I_PUB_PARAM:
		{
			$nc(spi)->engineInitVerify($cast($PublicKey, key), params);
			break;
		}
	case Signature$Delegate::I_PRIV:
		{
			$nc(spi)->engineInitSign($cast($PrivateKey, key));
			break;
		}
	case Signature$Delegate::I_PRIV_SR:
		{
			$nc(spi)->engineInitSign($cast($PrivateKey, key), random);
			break;
		}
	case Signature$Delegate::I_PRIV_PARAM_SR:
		{
			$nc(spi)->engineInitSign($cast($PrivateKey, key), params, random);
			break;
		}
	case Signature$Delegate::S_PARAM:
		{
			$nc(spi)->engineSetParameter(params);
			break;
		}
	default:
		{
			$throwNew($AssertionError, $of($$str({"Internal error: "_s, $$str(type)})));
		}
	}
}

void Signature$Delegate::engineInitVerify($PublicKey* publicKey) {
	if (this->sigSpi != nullptr) {
		$nc(this->sigSpi)->engineInitVerify(publicKey);
	} else {
		try {
			chooseProvider(Signature$Delegate::I_PUB, publicKey, nullptr, nullptr);
		} catch ($InvalidAlgorithmParameterException& iape) {
			$throwNew($InvalidKeyException, static_cast<$Throwable*>(iape));
		}
	}
}

void Signature$Delegate::engineInitVerify($PublicKey* publicKey, $AlgorithmParameterSpec* params) {
	if (this->sigSpi != nullptr) {
		$nc(this->sigSpi)->engineInitVerify(publicKey, params);
	} else {
		chooseProvider(Signature$Delegate::I_PUB_PARAM, publicKey, params, nullptr);
	}
}

void Signature$Delegate::engineInitSign($PrivateKey* privateKey) {
	if (this->sigSpi != nullptr) {
		$nc(this->sigSpi)->engineInitSign(privateKey);
	} else {
		try {
			chooseProvider(Signature$Delegate::I_PRIV, privateKey, nullptr, nullptr);
		} catch ($InvalidAlgorithmParameterException& iape) {
			$throwNew($InvalidKeyException, static_cast<$Throwable*>(iape));
		}
	}
}

void Signature$Delegate::engineInitSign($PrivateKey* privateKey, $SecureRandom* sr) {
	if (this->sigSpi != nullptr) {
		$nc(this->sigSpi)->engineInitSign(privateKey, sr);
	} else {
		try {
			chooseProvider(Signature$Delegate::I_PRIV_SR, privateKey, nullptr, sr);
		} catch ($InvalidAlgorithmParameterException& iape) {
			$throwNew($InvalidKeyException, static_cast<$Throwable*>(iape));
		}
	}
}

void Signature$Delegate::engineInitSign($PrivateKey* privateKey, $AlgorithmParameterSpec* params, $SecureRandom* sr) {
	if (this->sigSpi != nullptr) {
		$nc(this->sigSpi)->engineInitSign(privateKey, params, sr);
	} else {
		chooseProvider(Signature$Delegate::I_PRIV_PARAM_SR, privateKey, params, sr);
	}
}

void Signature$Delegate::engineUpdate(int8_t b) {
	chooseFirstProvider();
	$nc(this->sigSpi)->engineUpdate(b);
}

void Signature$Delegate::engineUpdate($bytes* b, int32_t off, int32_t len) {
	chooseFirstProvider();
	$nc(this->sigSpi)->engineUpdate(b, off, len);
}

void Signature$Delegate::engineUpdate($ByteBuffer* data) {
	chooseFirstProvider();
	$nc(this->sigSpi)->engineUpdate(data);
}

$bytes* Signature$Delegate::engineSign() {
	chooseFirstProvider();
	return $nc(this->sigSpi)->engineSign();
}

int32_t Signature$Delegate::engineSign($bytes* outbuf, int32_t offset, int32_t len) {
	chooseFirstProvider();
	return $nc(this->sigSpi)->engineSign(outbuf, offset, len);
}

bool Signature$Delegate::engineVerify($bytes* sigBytes) {
	chooseFirstProvider();
	return $nc(this->sigSpi)->engineVerify(sigBytes);
}

bool Signature$Delegate::engineVerify($bytes* sigBytes, int32_t offset, int32_t length) {
	chooseFirstProvider();
	return $nc(this->sigSpi)->engineVerify(sigBytes, offset, length);
}

void Signature$Delegate::engineSetParameter($String* param, Object$* value) {
	chooseFirstProvider();
	$nc(this->sigSpi)->engineSetParameter(param, value);
}

void Signature$Delegate::engineSetParameter($AlgorithmParameterSpec* params) {
	if (this->sigSpi != nullptr) {
		$nc(this->sigSpi)->engineSetParameter(params);
	} else {
		try {
			chooseProvider(Signature$Delegate::S_PARAM, nullptr, params, nullptr);
		} catch ($InvalidKeyException& ike) {
			$throwNew($InvalidAlgorithmParameterException, static_cast<$Throwable*>(ike));
		}
	}
}

$Object* Signature$Delegate::engineGetParameter($String* param) {
	chooseFirstProvider();
	return $of($nc(this->sigSpi)->engineGetParameter(param));
}

$AlgorithmParameters* Signature$Delegate::engineGetParameters() {
	chooseFirstProvider();
	return $nc(this->sigSpi)->engineGetParameters();
}

void clinit$Signature$Delegate($Class* class$) {
	Signature$Delegate::warnCount = 10;
}

Signature$Delegate::Signature$Delegate() {
}

$Class* Signature$Delegate::load$($String* name, bool initialize) {
	$loadClass(Signature$Delegate, name, initialize, &_Signature$Delegate_ClassInfo_, clinit$Signature$Delegate, allocate$Signature$Delegate);
	return class$;
}

$Class* Signature$Delegate::class$ = nullptr;

	} // security
} // java