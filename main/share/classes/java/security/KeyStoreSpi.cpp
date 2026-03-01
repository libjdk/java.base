#include <java/security/KeyStoreSpi.h>

#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/security/Key.h>
#include <java/security/KeyStore$CallbackHandlerProtection.h>
#include <java/security/KeyStore$Entry.h>
#include <java/security/KeyStore$LoadStoreParameter.h>
#include <java/security/KeyStore$PasswordProtection.h>
#include <java/security/KeyStore$PrivateKeyEntry.h>
#include <java/security/KeyStore$ProtectionParameter.h>
#include <java/security/KeyStore$SecretKeyEntry.h>
#include <java/security/KeyStore$TrustedCertificateEntry.h>
#include <java/security/KeyStoreException.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/PrivateKey.h>
#include <java/security/UnrecoverableKeyException.h>
#include <java/security/cert/Certificate.h>
#include <java/util/Date.h>
#include <java/util/Enumeration.h>
#include <javax/crypto/SecretKey.h>
#include <javax/security/auth/callback/Callback.h>
#include <javax/security/auth/callback/CallbackHandler.h>
#include <javax/security/auth/callback/PasswordCallback.h>
#include <javax/security/auth/callback/UnsupportedCallbackException.h>
#include <jcpp.h>

using $CertificateArray = $Array<::java::security::cert::Certificate>;
using $CallbackArray = $Array<::javax::security::auth::callback::Callback>;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $Key = ::java::security::Key;
using $KeyStore$CallbackHandlerProtection = ::java::security::KeyStore$CallbackHandlerProtection;
using $KeyStore$Entry = ::java::security::KeyStore$Entry;
using $KeyStore$LoadStoreParameter = ::java::security::KeyStore$LoadStoreParameter;
using $KeyStore$PasswordProtection = ::java::security::KeyStore$PasswordProtection;
using $KeyStore$PrivateKeyEntry = ::java::security::KeyStore$PrivateKeyEntry;
using $KeyStore$ProtectionParameter = ::java::security::KeyStore$ProtectionParameter;
using $KeyStore$SecretKeyEntry = ::java::security::KeyStore$SecretKeyEntry;
using $KeyStore$TrustedCertificateEntry = ::java::security::KeyStore$TrustedCertificateEntry;
using $KeyStoreException = ::java::security::KeyStoreException;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $PrivateKey = ::java::security::PrivateKey;
using $UnrecoverableKeyException = ::java::security::UnrecoverableKeyException;
using $Certificate = ::java::security::cert::Certificate;
using $Date = ::java::util::Date;
using $Enumeration = ::java::util::Enumeration;
using $SecretKey = ::javax::crypto::SecretKey;
using $Callback = ::javax::security::auth::callback::Callback;
using $CallbackHandler = ::javax::security::auth::callback::CallbackHandler;
using $PasswordCallback = ::javax::security::auth::callback::PasswordCallback;
using $UnsupportedCallbackException = ::javax::security::auth::callback::UnsupportedCallbackException;

namespace java {
	namespace security {

$MethodInfo _KeyStoreSpi_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(KeyStoreSpi, init$, void)},
	{"engineAliases", "()Ljava/util/Enumeration;", "()Ljava/util/Enumeration<Ljava/lang/String;>;", $PUBLIC | $ABSTRACT, $virtualMethod(KeyStoreSpi, engineAliases, $Enumeration*)},
	{"engineContainsAlias", "(Ljava/lang/String;)Z", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(KeyStoreSpi, engineContainsAlias, bool, $String*)},
	{"engineDeleteEntry", "(Ljava/lang/String;)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(KeyStoreSpi, engineDeleteEntry, void, $String*), "java.security.KeyStoreException"},
	{"engineEntryInstanceOf", "(Ljava/lang/String;Ljava/lang/Class;)Z", "(Ljava/lang/String;Ljava/lang/Class<+Ljava/security/KeyStore$Entry;>;)Z", $PUBLIC, $virtualMethod(KeyStoreSpi, engineEntryInstanceOf, bool, $String*, $Class*)},
	{"engineGetCertificate", "(Ljava/lang/String;)Ljava/security/cert/Certificate;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(KeyStoreSpi, engineGetCertificate, $Certificate*, $String*)},
	{"engineGetCertificateAlias", "(Ljava/security/cert/Certificate;)Ljava/lang/String;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(KeyStoreSpi, engineGetCertificateAlias, $String*, $Certificate*)},
	{"engineGetCertificateChain", "(Ljava/lang/String;)[Ljava/security/cert/Certificate;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(KeyStoreSpi, engineGetCertificateChain, $CertificateArray*, $String*)},
	{"engineGetCreationDate", "(Ljava/lang/String;)Ljava/util/Date;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(KeyStoreSpi, engineGetCreationDate, $Date*, $String*)},
	{"engineGetEntry", "(Ljava/lang/String;Ljava/security/KeyStore$ProtectionParameter;)Ljava/security/KeyStore$Entry;", nullptr, $PUBLIC, $virtualMethod(KeyStoreSpi, engineGetEntry, $KeyStore$Entry*, $String*, $KeyStore$ProtectionParameter*), "java.security.KeyStoreException,java.security.NoSuchAlgorithmException,java.security.UnrecoverableEntryException"},
	{"engineGetKey", "(Ljava/lang/String;[C)Ljava/security/Key;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(KeyStoreSpi, engineGetKey, $Key*, $String*, $chars*), "java.security.NoSuchAlgorithmException,java.security.UnrecoverableKeyException"},
	{"engineIsCertificateEntry", "(Ljava/lang/String;)Z", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(KeyStoreSpi, engineIsCertificateEntry, bool, $String*)},
	{"engineIsKeyEntry", "(Ljava/lang/String;)Z", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(KeyStoreSpi, engineIsKeyEntry, bool, $String*)},
	{"engineLoad", "(Ljava/io/InputStream;[C)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(KeyStoreSpi, engineLoad, void, $InputStream*, $chars*), "java.io.IOException,java.security.NoSuchAlgorithmException,java.security.cert.CertificateException"},
	{"engineLoad", "(Ljava/security/KeyStore$LoadStoreParameter;)V", nullptr, $PUBLIC, $virtualMethod(KeyStoreSpi, engineLoad, void, $KeyStore$LoadStoreParameter*), "java.io.IOException,java.security.NoSuchAlgorithmException,java.security.cert.CertificateException"},
	{"engineLoad", "(Ljava/io/InputStream;Ljava/security/KeyStore$LoadStoreParameter;)V", nullptr, 0, $virtualMethod(KeyStoreSpi, engineLoad, void, $InputStream*, $KeyStore$LoadStoreParameter*), "java.io.IOException,java.security.NoSuchAlgorithmException,java.security.cert.CertificateException"},
	{"engineProbe", "(Ljava/io/InputStream;)Z", nullptr, $PUBLIC, $virtualMethod(KeyStoreSpi, engineProbe, bool, $InputStream*), "java.io.IOException"},
	{"engineSetCertificateEntry", "(Ljava/lang/String;Ljava/security/cert/Certificate;)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(KeyStoreSpi, engineSetCertificateEntry, void, $String*, $Certificate*), "java.security.KeyStoreException"},
	{"engineSetEntry", "(Ljava/lang/String;Ljava/security/KeyStore$Entry;Ljava/security/KeyStore$ProtectionParameter;)V", nullptr, $PUBLIC, $virtualMethod(KeyStoreSpi, engineSetEntry, void, $String*, $KeyStore$Entry*, $KeyStore$ProtectionParameter*), "java.security.KeyStoreException"},
	{"engineSetKeyEntry", "(Ljava/lang/String;Ljava/security/Key;[C[Ljava/security/cert/Certificate;)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(KeyStoreSpi, engineSetKeyEntry, void, $String*, $Key*, $chars*, $CertificateArray*), "java.security.KeyStoreException"},
	{"engineSetKeyEntry", "(Ljava/lang/String;[B[Ljava/security/cert/Certificate;)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(KeyStoreSpi, engineSetKeyEntry, void, $String*, $bytes*, $CertificateArray*), "java.security.KeyStoreException"},
	{"engineSize", "()I", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(KeyStoreSpi, engineSize, int32_t)},
	{"engineStore", "(Ljava/io/OutputStream;[C)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(KeyStoreSpi, engineStore, void, $OutputStream*, $chars*), "java.io.IOException,java.security.NoSuchAlgorithmException,java.security.cert.CertificateException"},
	{"engineStore", "(Ljava/security/KeyStore$LoadStoreParameter;)V", nullptr, $PUBLIC, $virtualMethod(KeyStoreSpi, engineStore, void, $KeyStore$LoadStoreParameter*), "java.io.IOException,java.security.NoSuchAlgorithmException,java.security.cert.CertificateException"},
	{}
};

$ClassInfo _KeyStoreSpi_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"java.security.KeyStoreSpi",
	"java.lang.Object",
	nullptr,
	nullptr,
	_KeyStoreSpi_MethodInfo_
};

$Object* allocate$KeyStoreSpi($Class* clazz) {
	return $of($alloc(KeyStoreSpi));
}

void KeyStoreSpi::init$() {
}

void KeyStoreSpi::engineStore($KeyStore$LoadStoreParameter* param) {
	$throwNew($UnsupportedOperationException);
}

void KeyStoreSpi::engineLoad($KeyStore$LoadStoreParameter* param) {
	engineLoad(($InputStream*)nullptr, param);
}

void KeyStoreSpi::engineLoad($InputStream* stream, $KeyStore$LoadStoreParameter* param) {
	$useLocalCurrentObjectStackCache();
	if (param == nullptr) {
		engineLoad(($InputStream*)nullptr, ($chars*)nullptr);
		return;
	}
	$var($KeyStore$ProtectionParameter, protection, $nc(param)->getProtectionParameter());
	$var($chars, password, nullptr);
	if ($instanceOf($KeyStore$PasswordProtection, protection)) {
		$assign(password, $nc(($cast($KeyStore$PasswordProtection, protection)))->getPassword());
	} else if ($instanceOf($KeyStore$CallbackHandlerProtection, protection)) {
		$var($CallbackHandler, handler, $nc(($cast($KeyStore$CallbackHandlerProtection, protection)))->getCallbackHandler());
		$var($PasswordCallback, callback, $new($PasswordCallback, "Password: "_s, false));
		try {
			$nc(handler)->handle($$new($CallbackArray, {static_cast<$Callback*>(callback)}));
		} catch ($UnsupportedCallbackException& e) {
			$throwNew($NoSuchAlgorithmException, "Could not obtain password"_s, e);
		}
		$assign(password, callback->getPassword());
		callback->clearPassword();
		if (password == nullptr) {
			$throwNew($NoSuchAlgorithmException, "No password provided"_s);
		}
	} else {
		$throwNew($NoSuchAlgorithmException, "ProtectionParameter must be PasswordProtection or CallbackHandlerProtection"_s);
	}
	engineLoad(stream, password);
	return;
}

$KeyStore$Entry* KeyStoreSpi::engineGetEntry($String* alias, $KeyStore$ProtectionParameter* protParam) {
	$useLocalCurrentObjectStackCache();
	if (!engineContainsAlias(alias)) {
		return nullptr;
	}
	if (protParam == nullptr) {
		if (engineIsCertificateEntry(alias)) {
			return $new($KeyStore$TrustedCertificateEntry, $(engineGetCertificate(alias)));
		} else {
			$throwNew($UnrecoverableKeyException, "requested entry requires a password"_s);
		}
	}
	if ($instanceOf($KeyStore$PasswordProtection, protParam)) {
		if (engineIsCertificateEntry(alias)) {
			$throwNew($UnsupportedOperationException, "trusted certificate entries are not password-protected"_s);
		} else if (engineIsKeyEntry(alias)) {
			$var($KeyStore$PasswordProtection, pp, $cast($KeyStore$PasswordProtection, protParam));
			if ($nc(pp)->getProtectionAlgorithm() != nullptr) {
				$throwNew($KeyStoreException, "unsupported password protection algorithm"_s);
			}
			$var($chars, password, $nc(pp)->getPassword());
			$var($Key, key, engineGetKey(alias, password));
			if ($instanceOf($PrivateKey, key)) {
				$var($CertificateArray, chain, engineGetCertificateChain(alias));
				return $new($KeyStore$PrivateKeyEntry, $cast($PrivateKey, key), chain);
			} else if ($instanceOf($SecretKey, key)) {
				return $new($KeyStore$SecretKeyEntry, $cast($SecretKey, key));
			}
		}
	}
	$throwNew($UnsupportedOperationException);
}

void KeyStoreSpi::engineSetEntry($String* alias, $KeyStore$Entry* entry, $KeyStore$ProtectionParameter* protParam) {
	$useLocalCurrentObjectStackCache();
	if (protParam != nullptr && !($instanceOf($KeyStore$PasswordProtection, protParam))) {
		$throwNew($KeyStoreException, "unsupported protection parameter"_s);
	}
	$var($KeyStore$PasswordProtection, pProtect, nullptr);
	if (protParam != nullptr) {
		$assign(pProtect, $cast($KeyStore$PasswordProtection, protParam));
		if (pProtect->getProtectionAlgorithm() != nullptr) {
			$throwNew($KeyStoreException, "unsupported password protection algorithm"_s);
		}
	}
	if ($instanceOf($KeyStore$TrustedCertificateEntry, entry)) {
		if (protParam != nullptr && $nc(pProtect)->getPassword() != nullptr) {
			$throwNew($KeyStoreException, "trusted certificate entries are not password-protected"_s);
		} else {
			$var($KeyStore$TrustedCertificateEntry, tce, $cast($KeyStore$TrustedCertificateEntry, entry));
			engineSetCertificateEntry(alias, $($nc(tce)->getTrustedCertificate()));
			return;
		}
	} else if ($instanceOf($KeyStore$PrivateKeyEntry, entry)) {
		if (pProtect == nullptr || $nc(pProtect)->getPassword() == nullptr) {
			$throwNew($KeyStoreException, "non-null password required to create PrivateKeyEntry"_s);
		} else {
			$var($String, var$0, alias);
			$var($Key, var$1, static_cast<$Key*>($nc(($cast($KeyStore$PrivateKeyEntry, entry)))->getPrivateKey()));
			$var($chars, var$2, pProtect->getPassword());
			engineSetKeyEntry(var$0, var$1, var$2, $(($cast($KeyStore$PrivateKeyEntry, entry))->getCertificateChain()));
			return;
		}
	} else if ($instanceOf($KeyStore$SecretKeyEntry, entry)) {
		if (pProtect == nullptr || $nc(pProtect)->getPassword() == nullptr) {
			$throwNew($KeyStoreException, "non-null password required to create SecretKeyEntry"_s);
		} else {
			$var($String, var$3, alias);
			$var($Key, var$4, static_cast<$Key*>($nc(($cast($KeyStore$SecretKeyEntry, entry)))->getSecretKey()));
			engineSetKeyEntry(var$3, var$4, $(pProtect->getPassword()), ($CertificateArray*)nullptr);
			return;
		}
	}
	$throwNew($KeyStoreException, $$str({"unsupported entry type: "_s, $($nc($of(entry))->getClass()->getName())}));
}

bool KeyStoreSpi::engineEntryInstanceOf($String* alias, $Class* entryClass) {
	$load($KeyStore$TrustedCertificateEntry);
	if (entryClass == $KeyStore$TrustedCertificateEntry::class$) {
		return engineIsCertificateEntry(alias);
	}
	$load($KeyStore$PrivateKeyEntry);
	if (entryClass == $KeyStore$PrivateKeyEntry::class$) {
		bool var$0 = engineIsKeyEntry(alias);
		return var$0 && engineGetCertificate(alias) != nullptr;
	}
	$load($KeyStore$SecretKeyEntry);
	if (entryClass == $KeyStore$SecretKeyEntry::class$) {
		bool var$1 = engineIsKeyEntry(alias);
		return var$1 && engineGetCertificate(alias) == nullptr;
	}
	return false;
}

bool KeyStoreSpi::engineProbe($InputStream* stream) {
	if (stream == nullptr) {
		$throwNew($NullPointerException, "input stream must not be null"_s);
	}
	return false;
}

KeyStoreSpi::KeyStoreSpi() {
}

$Class* KeyStoreSpi::load$($String* name, bool initialize) {
	$loadClass(KeyStoreSpi, name, initialize, &_KeyStoreSpi_ClassInfo_, allocate$KeyStoreSpi);
	return class$;
}

$Class* KeyStoreSpi::class$ = nullptr;

	} // security
} // java