#include <sun/security/util/PolicyUtil.h>

#include <java/io/BufferedInputStream.h>
#include <java/io/File.h>
#include <java/io/FileInputStream.h>
#include <java/io/InputStream.h>
#include <java/net/MalformedURLException.h>
#include <java/net/URL.h>
#include <java/security/KeyStore.h>
#include <java/util/Arrays.h>
#include <sun/net/www/ParseUtil.h>
#include <sun/security/util/Debug.h>
#include <sun/security/util/Password.h>
#include <jcpp.h>

#undef NONE
#undef P11KEYSTORE

using $BufferedInputStream = ::java::io::BufferedInputStream;
using $File = ::java::io::File;
using $FileInputStream = ::java::io::FileInputStream;
using $InputStream = ::java::io::InputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $MalformedURLException = ::java::net::MalformedURLException;
using $URL = ::java::net::URL;
using $KeyStore = ::java::security::KeyStore;
using $Arrays = ::java::util::Arrays;
using $ParseUtil = ::sun::net::www::ParseUtil;
using $Debug = ::sun::security::util::Debug;
using $Password = ::sun::security::util::Password;

namespace sun {
	namespace security {
		namespace util {

$FieldInfo _PolicyUtil_FieldInfo_[] = {
	{"P11KEYSTORE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PolicyUtil, P11KEYSTORE)},
	{"NONE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PolicyUtil, NONE)},
	{}
};

$MethodInfo _PolicyUtil_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(PolicyUtil, init$, void)},
	{"getInputStream", "(Ljava/net/URL;)Ljava/io/InputStream;", nullptr, $PUBLIC | $STATIC, $staticMethod(PolicyUtil, getInputStream, $InputStream*, $URL*), "java.io.IOException"},
	{"getKeyStore", "(Ljava/net/URL;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Lsun/security/util/Debug;)Ljava/security/KeyStore;", nullptr, $PUBLIC | $STATIC, $staticMethod(PolicyUtil, getKeyStore, $KeyStore*, $URL*, $String*, $String*, $String*, $String*, $Debug*), "java.security.KeyStoreException,java.net.MalformedURLException,java.io.IOException,java.security.NoSuchProviderException,java.security.NoSuchAlgorithmException,java.security.cert.CertificateException"},
	{}
};

$ClassInfo _PolicyUtil_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.util.PolicyUtil",
	"java.lang.Object",
	nullptr,
	_PolicyUtil_FieldInfo_,
	_PolicyUtil_MethodInfo_
};

$Object* allocate$PolicyUtil($Class* clazz) {
	return $of($alloc(PolicyUtil));
}

$String* PolicyUtil::P11KEYSTORE = nullptr;
$String* PolicyUtil::NONE = nullptr;

void PolicyUtil::init$() {
}

$InputStream* PolicyUtil::getInputStream($URL* url) {
	$init(PolicyUtil);
	$useLocalCurrentObjectStackCache();
	if ("file"_s->equals($($nc(url)->getProtocol()))) {
		$init($File);
		$var($String, path, $nc($($nc(url)->getFile()))->replace(u'/', $File::separatorChar));
		$assign(path, $ParseUtil::decode(path));
		return $new($FileInputStream, path);
	} else {
		return $nc(url)->openStream();
	}
}

$KeyStore* PolicyUtil::getKeyStore($URL* policyUrl, $String* keyStoreName, $String* keyStoreType$renamed, $String* keyStoreProvider, $String* storePassURL, $Debug* debug) {
	$init(PolicyUtil);
	$useLocalCurrentObjectStackCache();
	$var($String, keyStoreType, keyStoreType$renamed);
	if (keyStoreName == nullptr) {
		$throwNew($IllegalArgumentException, "null KeyStore name"_s);
	}
	$var($chars, keyStorePassword, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		$var($KeyStore, var$2, nullptr);
		bool return$1 = false;
		try {
			$var($KeyStore, ks, nullptr);
			if (keyStoreType == nullptr) {
				$assign(keyStoreType, $KeyStore::getDefaultType());
			}
			bool var$3 = $nc(PolicyUtil::P11KEYSTORE)->equalsIgnoreCase(keyStoreType);
			if (var$3 && !$nc(PolicyUtil::NONE)->equals(keyStoreName)) {
				$throwNew($IllegalArgumentException, $$str({"Invalid value ("_s, keyStoreName, ") for keystore URL.  If the keystore type is \""_s, PolicyUtil::P11KEYSTORE, "\", the keystore url must be \""_s, PolicyUtil::NONE, "\""_s}));
			}
			if (keyStoreProvider != nullptr) {
				$assign(ks, $KeyStore::getInstance(keyStoreType, keyStoreProvider));
			} else {
				$assign(ks, $KeyStore::getInstance(keyStoreType));
			}
			if (storePassURL != nullptr) {
				$var($URL, passURL, nullptr);
				try {
					$assign(passURL, $new($URL, storePassURL));
				} catch ($MalformedURLException& e) {
					if (policyUrl == nullptr) {
						$throw(e);
					}
					$assign(passURL, $new($URL, policyUrl, storePassURL));
				}
				if (debug != nullptr) {
					debug->println($$str({"reading password"_s, passURL}));
				}
				$var($InputStream, in, nullptr);
				{
					$var($Throwable, var$4, nullptr);
					try {
						$assign(in, $nc(passURL)->openStream());
						$assign(keyStorePassword, $Password::readPassword(in));
					} catch ($Throwable& var$5) {
						$assign(var$4, var$5);
					} /*finally*/ {
						if (in != nullptr) {
							in->close();
						}
					}
					if (var$4 != nullptr) {
						$throw(var$4);
					}
				}
			}
			if ($nc(PolicyUtil::NONE)->equals(keyStoreName)) {
				$nc(ks)->load(nullptr, keyStorePassword);
				$assign(var$2, ks);
				return$1 = true;
				goto $finally;
			} else {
				$var($URL, keyStoreUrl, nullptr);
				try {
					$assign(keyStoreUrl, $new($URL, keyStoreName));
				} catch ($MalformedURLException& e) {
					if (policyUrl == nullptr) {
						$throw(e);
					}
					$assign(keyStoreUrl, $new($URL, policyUrl, keyStoreName));
				}
				if (debug != nullptr) {
					debug->println($$str({"reading keystore"_s, keyStoreUrl}));
				}
				$var($InputStream, inStream, nullptr);
				{
					$var($Throwable, var$6, nullptr);
					try {
						$assign(inStream, $new($BufferedInputStream, $(getInputStream(keyStoreUrl))));
						$nc(ks)->load(inStream, keyStorePassword);
					} catch ($Throwable& var$7) {
						$assign(var$6, var$7);
					} /*finally*/ {
						$nc(inStream)->close();
					}
					if (var$6 != nullptr) {
						$throw(var$6);
					}
				}
				$assign(var$2, ks);
				return$1 = true;
				goto $finally;
			}
		} catch ($Throwable& var$8) {
			$assign(var$0, var$8);
		} $finally: {
			if (keyStorePassword != nullptr) {
				$Arrays::fill(keyStorePassword, u' ');
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

PolicyUtil::PolicyUtil() {
}

void clinit$PolicyUtil($Class* class$) {
	$assignStatic(PolicyUtil::P11KEYSTORE, "PKCS11"_s);
	$assignStatic(PolicyUtil::NONE, "NONE"_s);
}

$Class* PolicyUtil::load$($String* name, bool initialize) {
	$loadClass(PolicyUtil, name, initialize, &_PolicyUtil_ClassInfo_, clinit$PolicyUtil, allocate$PolicyUtil);
	return class$;
}

$Class* PolicyUtil::class$ = nullptr;

		} // util
	} // security
} // sun