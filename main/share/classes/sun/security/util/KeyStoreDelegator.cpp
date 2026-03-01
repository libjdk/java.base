#include <sun/security/util/KeyStoreDelegator.h>

#include <java/io/BufferedInputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/InstantiationException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/security/AccessController.h>
#include <java/security/Key.h>
#include <java/security/KeyStore$Entry.h>
#include <java/security/KeyStore$ProtectionParameter.h>
#include <java/security/KeyStoreSpi.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/Security.h>
#include <java/security/UnrecoverableKeyException.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/CertificateException.h>
#include <java/util/Date.h>
#include <java/util/Enumeration.h>
#include <sun/security/util/Debug.h>
#include <jcpp.h>

#undef KEYSTORE_TYPE_COMPAT
#undef MAX_VALUE

using $CertificateArray = $Array<::java::security::cert::Certificate>;
using $BufferedInputStream = ::java::io::BufferedInputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $InstantiationException = ::java::lang::InstantiationException;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $AccessController = ::java::security::AccessController;
using $Key = ::java::security::Key;
using $KeyStore$Entry = ::java::security::KeyStore$Entry;
using $KeyStore$ProtectionParameter = ::java::security::KeyStore$ProtectionParameter;
using $KeyStoreSpi = ::java::security::KeyStoreSpi;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Security = ::java::security::Security;
using $UnrecoverableKeyException = ::java::security::UnrecoverableKeyException;
using $Certificate = ::java::security::cert::Certificate;
using $CertificateException = ::java::security::cert::CertificateException;
using $Date = ::java::util::Date;
using $Enumeration = ::java::util::Enumeration;
using $Debug = ::sun::security::util::Debug;

namespace sun {
	namespace security {
		namespace util {

class KeyStoreDelegator$$Lambda$lambda$new$0 : public $PrivilegedAction {
	$class(KeyStoreDelegator$$Lambda$lambda$new$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(KeyStoreDelegator::lambda$new$0());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<KeyStoreDelegator$$Lambda$lambda$new$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo KeyStoreDelegator$$Lambda$lambda$new$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(KeyStoreDelegator$$Lambda$lambda$new$0, init$, void)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(KeyStoreDelegator$$Lambda$lambda$new$0, run, $Object*)},
	{}
};
$ClassInfo KeyStoreDelegator$$Lambda$lambda$new$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.security.util.KeyStoreDelegator$$Lambda$lambda$new$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* KeyStoreDelegator$$Lambda$lambda$new$0::load$($String* name, bool initialize) {
	$loadClass(KeyStoreDelegator$$Lambda$lambda$new$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* KeyStoreDelegator$$Lambda$lambda$new$0::class$ = nullptr;

$FieldInfo _KeyStoreDelegator_FieldInfo_[] = {
	{"KEYSTORE_TYPE_COMPAT", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(KeyStoreDelegator, KEYSTORE_TYPE_COMPAT)},
	{"debug", "Lsun/security/util/Debug;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(KeyStoreDelegator, debug)},
	{"primaryType", "Ljava/lang/String;", nullptr, $PRIVATE, $field(KeyStoreDelegator, primaryType)},
	{"secondaryType", "Ljava/lang/String;", nullptr, $PRIVATE, $field(KeyStoreDelegator, secondaryType)},
	{"primaryKeyStore", "Ljava/lang/Class;", "Ljava/lang/Class<+Ljava/security/KeyStoreSpi;>;", $PRIVATE, $field(KeyStoreDelegator, primaryKeyStore)},
	{"secondaryKeyStore", "Ljava/lang/Class;", "Ljava/lang/Class<+Ljava/security/KeyStoreSpi;>;", $PRIVATE, $field(KeyStoreDelegator, secondaryKeyStore)},
	{"type", "Ljava/lang/String;", nullptr, $PRIVATE, $field(KeyStoreDelegator, type)},
	{"keystore", "Ljava/security/KeyStoreSpi;", nullptr, $PRIVATE, $field(KeyStoreDelegator, keystore)},
	{"compatModeEnabled", "Z", nullptr, $PRIVATE, $field(KeyStoreDelegator, compatModeEnabled)},
	{}
};

$MethodInfo _KeyStoreDelegator_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Ljava/lang/Class;Ljava/lang/String;Ljava/lang/Class;)V", "(Ljava/lang/String;Ljava/lang/Class<+Ljava/security/KeyStoreSpi;>;Ljava/lang/String;Ljava/lang/Class<+Ljava/security/KeyStoreSpi;>;)V", $PUBLIC, $method(KeyStoreDelegator, init$, void, $String*, $Class*, $String*, $Class*)},
	{"engineAliases", "()Ljava/util/Enumeration;", "()Ljava/util/Enumeration<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(KeyStoreDelegator, engineAliases, $Enumeration*)},
	{"engineContainsAlias", "(Ljava/lang/String;)Z", nullptr, $PUBLIC, $virtualMethod(KeyStoreDelegator, engineContainsAlias, bool, $String*)},
	{"engineDeleteEntry", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(KeyStoreDelegator, engineDeleteEntry, void, $String*), "java.security.KeyStoreException"},
	{"engineEntryInstanceOf", "(Ljava/lang/String;Ljava/lang/Class;)Z", "(Ljava/lang/String;Ljava/lang/Class<+Ljava/security/KeyStore$Entry;>;)Z", $PUBLIC, $virtualMethod(KeyStoreDelegator, engineEntryInstanceOf, bool, $String*, $Class*)},
	{"engineGetCertificate", "(Ljava/lang/String;)Ljava/security/cert/Certificate;", nullptr, $PUBLIC, $virtualMethod(KeyStoreDelegator, engineGetCertificate, $Certificate*, $String*)},
	{"engineGetCertificateAlias", "(Ljava/security/cert/Certificate;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(KeyStoreDelegator, engineGetCertificateAlias, $String*, $Certificate*)},
	{"engineGetCertificateChain", "(Ljava/lang/String;)[Ljava/security/cert/Certificate;", nullptr, $PUBLIC, $virtualMethod(KeyStoreDelegator, engineGetCertificateChain, $CertificateArray*, $String*)},
	{"engineGetCreationDate", "(Ljava/lang/String;)Ljava/util/Date;", nullptr, $PUBLIC, $virtualMethod(KeyStoreDelegator, engineGetCreationDate, $Date*, $String*)},
	{"engineGetEntry", "(Ljava/lang/String;Ljava/security/KeyStore$ProtectionParameter;)Ljava/security/KeyStore$Entry;", nullptr, $PUBLIC, $virtualMethod(KeyStoreDelegator, engineGetEntry, $KeyStore$Entry*, $String*, $KeyStore$ProtectionParameter*), "java.security.KeyStoreException,java.security.NoSuchAlgorithmException,java.security.UnrecoverableEntryException"},
	{"engineGetKey", "(Ljava/lang/String;[C)Ljava/security/Key;", nullptr, $PUBLIC, $virtualMethod(KeyStoreDelegator, engineGetKey, $Key*, $String*, $chars*), "java.security.NoSuchAlgorithmException,java.security.UnrecoverableKeyException"},
	{"engineIsCertificateEntry", "(Ljava/lang/String;)Z", nullptr, $PUBLIC, $virtualMethod(KeyStoreDelegator, engineIsCertificateEntry, bool, $String*)},
	{"engineIsKeyEntry", "(Ljava/lang/String;)Z", nullptr, $PUBLIC, $virtualMethod(KeyStoreDelegator, engineIsKeyEntry, bool, $String*)},
	{"engineLoad", "(Ljava/io/InputStream;[C)V", nullptr, $PUBLIC, $virtualMethod(KeyStoreDelegator, engineLoad, void, $InputStream*, $chars*), "java.io.IOException,java.security.NoSuchAlgorithmException,java.security.cert.CertificateException"},
	{"engineProbe", "(Ljava/io/InputStream;)Z", nullptr, $PUBLIC, $virtualMethod(KeyStoreDelegator, engineProbe, bool, $InputStream*), "java.io.IOException"},
	{"engineSetCertificateEntry", "(Ljava/lang/String;Ljava/security/cert/Certificate;)V", nullptr, $PUBLIC, $virtualMethod(KeyStoreDelegator, engineSetCertificateEntry, void, $String*, $Certificate*), "java.security.KeyStoreException"},
	{"engineSetEntry", "(Ljava/lang/String;Ljava/security/KeyStore$Entry;Ljava/security/KeyStore$ProtectionParameter;)V", nullptr, $PUBLIC, $virtualMethod(KeyStoreDelegator, engineSetEntry, void, $String*, $KeyStore$Entry*, $KeyStore$ProtectionParameter*), "java.security.KeyStoreException"},
	{"engineSetKeyEntry", "(Ljava/lang/String;Ljava/security/Key;[C[Ljava/security/cert/Certificate;)V", nullptr, $PUBLIC, $virtualMethod(KeyStoreDelegator, engineSetKeyEntry, void, $String*, $Key*, $chars*, $CertificateArray*), "java.security.KeyStoreException"},
	{"engineSetKeyEntry", "(Ljava/lang/String;[B[Ljava/security/cert/Certificate;)V", nullptr, $PUBLIC, $virtualMethod(KeyStoreDelegator, engineSetKeyEntry, void, $String*, $bytes*, $CertificateArray*), "java.security.KeyStoreException"},
	{"engineSize", "()I", nullptr, $PUBLIC, $virtualMethod(KeyStoreDelegator, engineSize, int32_t)},
	{"engineStore", "(Ljava/io/OutputStream;[C)V", nullptr, $PUBLIC, $virtualMethod(KeyStoreDelegator, engineStore, void, $OutputStream*, $chars*), "java.io.IOException,java.security.NoSuchAlgorithmException,java.security.cert.CertificateException"},
	{"lambda$new$0", "()Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(KeyStoreDelegator, lambda$new$0, $String*)},
	{}
};

$ClassInfo _KeyStoreDelegator_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.util.KeyStoreDelegator",
	"java.security.KeyStoreSpi",
	nullptr,
	_KeyStoreDelegator_FieldInfo_,
	_KeyStoreDelegator_MethodInfo_
};

$Object* allocate$KeyStoreDelegator($Class* clazz) {
	return $of($alloc(KeyStoreDelegator));
}

$String* KeyStoreDelegator::KEYSTORE_TYPE_COMPAT = nullptr;
$Debug* KeyStoreDelegator::debug = nullptr;

void KeyStoreDelegator::init$($String* primaryType, $Class* primaryKeyStore, $String* secondaryType, $Class* secondaryKeyStore) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$KeyStoreSpi::init$();
	this->compatModeEnabled = true;
	$var($String, prop, $cast($String, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(KeyStoreDelegator$$Lambda$lambda$new$0)))));
	this->compatModeEnabled = "true"_s->equalsIgnoreCase(prop);
	if (this->compatModeEnabled) {
		$set(this, primaryType, primaryType);
		$set(this, secondaryType, secondaryType);
		$set(this, primaryKeyStore, primaryKeyStore);
		$set(this, secondaryKeyStore, secondaryKeyStore);
	} else {
		$set(this, primaryType, primaryType);
		$set(this, secondaryType, nullptr);
		$set(this, primaryKeyStore, primaryKeyStore);
		$set(this, secondaryKeyStore, nullptr);
		if (KeyStoreDelegator::debug != nullptr) {
			$nc(KeyStoreDelegator::debug)->println($$str({"WARNING: compatibility mode disabled for "_s, primaryType, " and "_s, secondaryType, " keystore types"_s}));
		}
	}
}

$Key* KeyStoreDelegator::engineGetKey($String* alias, $chars* password) {
	return $nc(this->keystore)->engineGetKey(alias, password);
}

$CertificateArray* KeyStoreDelegator::engineGetCertificateChain($String* alias) {
	return $nc(this->keystore)->engineGetCertificateChain(alias);
}

$Certificate* KeyStoreDelegator::engineGetCertificate($String* alias) {
	return $nc(this->keystore)->engineGetCertificate(alias);
}

$Date* KeyStoreDelegator::engineGetCreationDate($String* alias) {
	return $nc(this->keystore)->engineGetCreationDate(alias);
}

void KeyStoreDelegator::engineSetKeyEntry($String* alias, $Key* key, $chars* password, $CertificateArray* chain) {
	$nc(this->keystore)->engineSetKeyEntry(alias, key, password, chain);
}

void KeyStoreDelegator::engineSetKeyEntry($String* alias, $bytes* key, $CertificateArray* chain) {
	$nc(this->keystore)->engineSetKeyEntry(alias, key, chain);
}

void KeyStoreDelegator::engineSetCertificateEntry($String* alias, $Certificate* cert) {
	$nc(this->keystore)->engineSetCertificateEntry(alias, cert);
}

void KeyStoreDelegator::engineDeleteEntry($String* alias) {
	$nc(this->keystore)->engineDeleteEntry(alias);
}

$Enumeration* KeyStoreDelegator::engineAliases() {
	return $nc(this->keystore)->engineAliases();
}

bool KeyStoreDelegator::engineContainsAlias($String* alias) {
	return $nc(this->keystore)->engineContainsAlias(alias);
}

int32_t KeyStoreDelegator::engineSize() {
	return $nc(this->keystore)->engineSize();
}

bool KeyStoreDelegator::engineIsKeyEntry($String* alias) {
	return $nc(this->keystore)->engineIsKeyEntry(alias);
}

bool KeyStoreDelegator::engineIsCertificateEntry($String* alias) {
	return $nc(this->keystore)->engineIsCertificateEntry(alias);
}

$String* KeyStoreDelegator::engineGetCertificateAlias($Certificate* cert) {
	return $nc(this->keystore)->engineGetCertificateAlias(cert);
}

$KeyStore$Entry* KeyStoreDelegator::engineGetEntry($String* alias, $KeyStore$ProtectionParameter* protParam) {
	return $nc(this->keystore)->engineGetEntry(alias, protParam);
}

void KeyStoreDelegator::engineSetEntry($String* alias, $KeyStore$Entry* entry, $KeyStore$ProtectionParameter* protParam) {
	$nc(this->keystore)->engineSetEntry(alias, entry, protParam);
}

bool KeyStoreDelegator::engineEntryInstanceOf($String* alias, $Class* entryClass) {
	return $nc(this->keystore)->engineEntryInstanceOf(alias, entryClass);
}

void KeyStoreDelegator::engineStore($OutputStream* stream, $chars* password) {
	if (KeyStoreDelegator::debug != nullptr) {
		$nc(KeyStoreDelegator::debug)->println($$str({"Storing keystore in "_s, this->type, " format"_s}));
	}
	$nc(this->keystore)->engineStore(stream, password);
}

void KeyStoreDelegator::engineLoad($InputStream* stream, $chars* password) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (stream == nullptr) {
		try {
			$var($KeyStoreSpi, tmp, $cast($KeyStoreSpi, $nc(this->primaryKeyStore)->newInstance()));
			$set(this, keystore, tmp);
		} catch ($InstantiationException& e) {
		} catch ($IllegalAccessException& e) {
		}
		$set(this, type, this->primaryType);
		if (KeyStoreDelegator::debug != nullptr) {
			$nc(KeyStoreDelegator::debug)->println($$str({"Creating a new keystore in "_s, this->type, " format"_s}));
		}
		$nc(this->keystore)->engineLoad(stream, password);
	} else {
		$var($InputStream, bufferedStream, $new($BufferedInputStream, stream));
		bufferedStream->mark($Integer::MAX_VALUE);
		try {
			$var($KeyStoreSpi, tmp, $cast($KeyStoreSpi, $nc(this->primaryKeyStore)->newInstance()));
			$nc(tmp)->engineLoad(bufferedStream, password);
			$set(this, keystore, tmp);
			$set(this, type, this->primaryType);
		} catch ($Exception& e) {
			if ($instanceOf($IOException, e) && $instanceOf($UnrecoverableKeyException, $(e->getCause()))) {
				$throw($cast($IOException, e));
			}
			try {
				if (!this->compatModeEnabled) {
					$throw(e);
				}
				$var($KeyStoreSpi, tmp, $cast($KeyStoreSpi, $nc(this->secondaryKeyStore)->newInstance()));
				bufferedStream->reset();
				$nc(tmp)->engineLoad(bufferedStream, password);
				$set(this, keystore, tmp);
				$set(this, type, this->secondaryType);
				if (KeyStoreDelegator::debug != nullptr) {
					$nc(KeyStoreDelegator::debug)->println($$str({"WARNING: switching from "_s, this->primaryType, " to "_s, this->secondaryType, " keystore file format has altered the keystore security level"_s}));
				}
			} catch ($InstantiationException& e2) {
			} catch ($IllegalAccessException& e2) {
			} catch ($IOException& e3) {
				if ($instanceOf($IOException, e3) && $instanceOf($UnrecoverableKeyException, $(e3->getCause()))) {
					$throw($cast($IOException, e3));
				}
				if ($instanceOf($IOException, e)) {
					$throw($cast($IOException, e));
				} else if ($instanceOf($CertificateException, e)) {
					$throw($cast($CertificateException, e));
				} else if ($instanceOf($NoSuchAlgorithmException, e)) {
					$throw($cast($NoSuchAlgorithmException, e));
				} else if ($instanceOf($RuntimeException, e)) {
					$throw($cast($RuntimeException, e));
				}
			} catch ($NoSuchAlgorithmException& e3) {
				if ($instanceOf($IOException, e3) && $instanceOf($UnrecoverableKeyException, $(e3->getCause()))) {
					$throw($cast($IOException, e3));
				}
				if ($instanceOf($IOException, e)) {
					$throw($cast($IOException, e));
				} else if ($instanceOf($CertificateException, e)) {
					$throw($cast($CertificateException, e));
				} else if ($instanceOf($NoSuchAlgorithmException, e)) {
					$throw($cast($NoSuchAlgorithmException, e));
				} else if ($instanceOf($RuntimeException, e)) {
					$throw($cast($RuntimeException, e));
				}
			} catch ($CertificateException& e3) {
				if ($instanceOf($IOException, e3) && $instanceOf($UnrecoverableKeyException, $(e3->getCause()))) {
					$throw($cast($IOException, e3));
				}
				if ($instanceOf($IOException, e)) {
					$throw($cast($IOException, e));
				} else if ($instanceOf($CertificateException, e)) {
					$throw($cast($CertificateException, e));
				} else if ($instanceOf($NoSuchAlgorithmException, e)) {
					$throw($cast($NoSuchAlgorithmException, e));
				} else if ($instanceOf($RuntimeException, e)) {
					$throw($cast($RuntimeException, e));
				}
			}
		}
		if (KeyStoreDelegator::debug != nullptr) {
			$nc(KeyStoreDelegator::debug)->println($$str({"Loaded a keystore in "_s, this->type, " format"_s}));
		}
	}
}

bool KeyStoreDelegator::engineProbe($InputStream* stream) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	bool result = false;
	{
		$var($Throwable, var$0, nullptr);
		try {
			try {
				$var($KeyStoreSpi, tmp, $cast($KeyStoreSpi, $nc(this->primaryKeyStore)->newInstance()));
				$set(this, keystore, tmp);
				$set(this, type, this->primaryType);
				result = $nc(this->keystore)->engineProbe(stream);
			} catch ($Exception& e) {
				$throwNew($IOException, static_cast<$Throwable*>(e));
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			if (result == false) {
				$set(this, type, nullptr);
				$set(this, keystore, nullptr);
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	return result;
}

$String* KeyStoreDelegator::lambda$new$0() {
	$init(KeyStoreDelegator);
	return $Security::getProperty(KeyStoreDelegator::KEYSTORE_TYPE_COMPAT);
}

void clinit$KeyStoreDelegator($Class* class$) {
	$assignStatic(KeyStoreDelegator::KEYSTORE_TYPE_COMPAT, "keystore.type.compat"_s);
	$assignStatic(KeyStoreDelegator::debug, $Debug::getInstance("keystore"_s));
}

KeyStoreDelegator::KeyStoreDelegator() {
}

$Class* KeyStoreDelegator::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(KeyStoreDelegator$$Lambda$lambda$new$0::classInfo$.name)) {
			return KeyStoreDelegator$$Lambda$lambda$new$0::load$(name, initialize);
		}
	}
	$loadClass(KeyStoreDelegator, name, initialize, &_KeyStoreDelegator_ClassInfo_, clinit$KeyStoreDelegator, allocate$KeyStoreDelegator);
	return class$;
}

$Class* KeyStoreDelegator::class$ = nullptr;

		} // util
	} // security
} // sun