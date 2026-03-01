#include <sun/security/provider/JavaKeyStore.h>

#include <java/io/ByteArrayInputStream.h>
#include <java/io/DataInputStream.h>
#include <java/io/DataOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/StandardCharsets.h>
#include <java/security/DigestInputStream.h>
#include <java/security/DigestOutputStream.h>
#include <java/security/Key.h>
#include <java/security/KeyStoreException.h>
#include <java/security/KeyStoreSpi.h>
#include <java/security/MessageDigest.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/PrivateKey.h>
#include <java/security/UnrecoverableKeyException.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/CertificateFactory.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Date.h>
#include <java/util/Enumeration.h>
#include <java/util/Hashtable.h>
#include <java/util/List.h>
#include <sun/security/pkcs/EncryptedPrivateKeyInfo.h>
#include <sun/security/provider/JavaKeyStore$KeyEntry.h>
#include <sun/security/provider/JavaKeyStore$TrustedCertEntry.h>
#include <sun/security/provider/KeyProtector.h>
#include <sun/security/util/Debug.h>
#include <sun/security/util/IOUtils.h>
#include <jcpp.h>

#undef MAGIC
#undef UTF_8
#undef VERSION_1
#undef VERSION_2

using $CertificateArray = $Array<::java::security::cert::Certificate>;
using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $DataInputStream = ::java::io::DataInputStream;
using $DataOutputStream = ::java::io::DataOutputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $DigestInputStream = ::java::security::DigestInputStream;
using $DigestOutputStream = ::java::security::DigestOutputStream;
using $Key = ::java::security::Key;
using $KeyStoreException = ::java::security::KeyStoreException;
using $KeyStoreSpi = ::java::security::KeyStoreSpi;
using $MessageDigest = ::java::security::MessageDigest;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $PrivateKey = ::java::security::PrivateKey;
using $UnrecoverableKeyException = ::java::security::UnrecoverableKeyException;
using $Certificate = ::java::security::cert::Certificate;
using $CertificateFactory = ::java::security::cert::CertificateFactory;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Date = ::java::util::Date;
using $Enumeration = ::java::util::Enumeration;
using $Hashtable = ::java::util::Hashtable;
using $List = ::java::util::List;
using $EncryptedPrivateKeyInfo = ::sun::security::pkcs::EncryptedPrivateKeyInfo;
using $JavaKeyStore$KeyEntry = ::sun::security::provider::JavaKeyStore$KeyEntry;
using $JavaKeyStore$TrustedCertEntry = ::sun::security::provider::JavaKeyStore$TrustedCertEntry;
using $KeyProtector = ::sun::security::provider::KeyProtector;
using $Debug = ::sun::security::util::Debug;
using $IOUtils = ::sun::security::util::IOUtils;

namespace sun {
	namespace security {
		namespace provider {

$FieldInfo _JavaKeyStore_FieldInfo_[] = {
	{"debug", "Lsun/security/util/Debug;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JavaKeyStore, debug)},
	{"MAGIC", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(JavaKeyStore, MAGIC)},
	{"VERSION_1", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(JavaKeyStore, VERSION_1)},
	{"VERSION_2", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(JavaKeyStore, VERSION_2)},
	{"entries", "Ljava/util/Hashtable;", "Ljava/util/Hashtable<Ljava/lang/String;Ljava/lang/Object;>;", $PRIVATE | $FINAL, $field(JavaKeyStore, entries)},
	{}
};

$MethodInfo _JavaKeyStore_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(JavaKeyStore, init$, void)},
	{"convertAlias", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $ABSTRACT, $virtualMethod(JavaKeyStore, convertAlias, $String*, $String*)},
	{"convertToBytes", "([C)[B", nullptr, $PRIVATE, $method(JavaKeyStore, convertToBytes, $bytes*, $chars*)},
	{"engineAliases", "()Ljava/util/Enumeration;", "()Ljava/util/Enumeration<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(JavaKeyStore, engineAliases, $Enumeration*)},
	{"engineContainsAlias", "(Ljava/lang/String;)Z", nullptr, $PUBLIC, $virtualMethod(JavaKeyStore, engineContainsAlias, bool, $String*)},
	{"engineDeleteEntry", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(JavaKeyStore, engineDeleteEntry, void, $String*), "java.security.KeyStoreException"},
	{"engineGetCertificate", "(Ljava/lang/String;)Ljava/security/cert/Certificate;", nullptr, $PUBLIC, $virtualMethod(JavaKeyStore, engineGetCertificate, $Certificate*, $String*)},
	{"engineGetCertificateAlias", "(Ljava/security/cert/Certificate;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(JavaKeyStore, engineGetCertificateAlias, $String*, $Certificate*)},
	{"engineGetCertificateChain", "(Ljava/lang/String;)[Ljava/security/cert/Certificate;", nullptr, $PUBLIC, $virtualMethod(JavaKeyStore, engineGetCertificateChain, $CertificateArray*, $String*)},
	{"engineGetCreationDate", "(Ljava/lang/String;)Ljava/util/Date;", nullptr, $PUBLIC, $virtualMethod(JavaKeyStore, engineGetCreationDate, $Date*, $String*)},
	{"engineGetKey", "(Ljava/lang/String;[C)Ljava/security/Key;", nullptr, $PUBLIC, $virtualMethod(JavaKeyStore, engineGetKey, $Key*, $String*, $chars*), "java.security.NoSuchAlgorithmException,java.security.UnrecoverableKeyException"},
	{"engineIsCertificateEntry", "(Ljava/lang/String;)Z", nullptr, $PUBLIC, $virtualMethod(JavaKeyStore, engineIsCertificateEntry, bool, $String*)},
	{"engineIsKeyEntry", "(Ljava/lang/String;)Z", nullptr, $PUBLIC, $virtualMethod(JavaKeyStore, engineIsKeyEntry, bool, $String*)},
	{"engineLoad", "(Ljava/io/InputStream;[C)V", nullptr, $PUBLIC, $virtualMethod(JavaKeyStore, engineLoad, void, $InputStream*, $chars*), "java.io.IOException,java.security.NoSuchAlgorithmException,java.security.cert.CertificateException"},
	{"engineSetCertificateEntry", "(Ljava/lang/String;Ljava/security/cert/Certificate;)V", nullptr, $PUBLIC, $virtualMethod(JavaKeyStore, engineSetCertificateEntry, void, $String*, $Certificate*), "java.security.KeyStoreException"},
	{"engineSetKeyEntry", "(Ljava/lang/String;Ljava/security/Key;[C[Ljava/security/cert/Certificate;)V", nullptr, $PUBLIC, $virtualMethod(JavaKeyStore, engineSetKeyEntry, void, $String*, $Key*, $chars*, $CertificateArray*), "java.security.KeyStoreException"},
	{"engineSetKeyEntry", "(Ljava/lang/String;[B[Ljava/security/cert/Certificate;)V", nullptr, $PUBLIC, $virtualMethod(JavaKeyStore, engineSetKeyEntry, void, $String*, $bytes*, $CertificateArray*), "java.security.KeyStoreException"},
	{"engineSize", "()I", nullptr, $PUBLIC, $virtualMethod(JavaKeyStore, engineSize, int32_t)},
	{"engineStore", "(Ljava/io/OutputStream;[C)V", nullptr, $PUBLIC, $virtualMethod(JavaKeyStore, engineStore, void, $OutputStream*, $chars*), "java.io.IOException,java.security.NoSuchAlgorithmException,java.security.cert.CertificateException"},
	{"getPreKeyedHash", "([C)Ljava/security/MessageDigest;", nullptr, $PRIVATE, $method(JavaKeyStore, getPreKeyedHash, $MessageDigest*, $chars*), "java.security.NoSuchAlgorithmException"},
	{}
};

$InnerClassInfo _JavaKeyStore_InnerClassesInfo_[] = {
	{"sun.security.provider.JavaKeyStore$TrustedCertEntry", "sun.security.provider.JavaKeyStore", "TrustedCertEntry", $PRIVATE | $STATIC},
	{"sun.security.provider.JavaKeyStore$KeyEntry", "sun.security.provider.JavaKeyStore", "KeyEntry", $PRIVATE | $STATIC},
	{"sun.security.provider.JavaKeyStore$DualFormatJKS", "sun.security.provider.JavaKeyStore", "DualFormatJKS", $PUBLIC | $STATIC | $FINAL},
	{"sun.security.provider.JavaKeyStore$CaseExactJKS", "sun.security.provider.JavaKeyStore", "CaseExactJKS", $PUBLIC | $STATIC | $FINAL},
	{"sun.security.provider.JavaKeyStore$JKS", "sun.security.provider.JavaKeyStore", "JKS", $PUBLIC | $STATIC | $FINAL},
	{}
};

$ClassInfo _JavaKeyStore_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"sun.security.provider.JavaKeyStore",
	"java.security.KeyStoreSpi",
	nullptr,
	_JavaKeyStore_FieldInfo_,
	_JavaKeyStore_MethodInfo_,
	nullptr,
	nullptr,
	_JavaKeyStore_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.provider.JavaKeyStore$TrustedCertEntry,sun.security.provider.JavaKeyStore$KeyEntry,sun.security.provider.JavaKeyStore$DualFormatJKS,sun.security.provider.JavaKeyStore$CaseExactJKS,sun.security.provider.JavaKeyStore$JKS"
};

$Object* allocate$JavaKeyStore($Class* clazz) {
	return $of($alloc(JavaKeyStore));
}

$Debug* JavaKeyStore::debug = nullptr;

void JavaKeyStore::init$() {
	$KeyStoreSpi::init$();
	$set(this, entries, $new($Hashtable));
}

$Key* JavaKeyStore::engineGetKey($String* alias, $chars* password) {
	$useLocalCurrentObjectStackCache();
	$var($Object, entry, $nc(this->entries)->get($(convertAlias(alias))));
	if (entry == nullptr || !($instanceOf($JavaKeyStore$KeyEntry, entry))) {
		return nullptr;
	}
	if (password == nullptr) {
		$throwNew($UnrecoverableKeyException, "Password must not be null"_s);
	}
	$var($bytes, passwordBytes, convertToBytes(password));
	$var($KeyProtector, keyProtector, $new($KeyProtector, passwordBytes));
	$var($bytes, encrBytes, $nc(($cast($JavaKeyStore$KeyEntry, entry)))->protectedPrivKey);
	$var($EncryptedPrivateKeyInfo, encrInfo, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		$var($Key, var$2, nullptr);
		bool return$1 = false;
		try {
			try {
				$assign(encrInfo, $new($EncryptedPrivateKeyInfo, encrBytes));
				$assign(var$2, keyProtector->recover(encrInfo));
				return$1 = true;
				goto $finally;
			} catch ($IOException& ioe) {
				$throwNew($UnrecoverableKeyException, "Private key not stored as PKCS #8 EncryptedPrivateKeyInfo"_s);
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$Arrays::fill(passwordBytes, (int8_t)0);
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

$CertificateArray* JavaKeyStore::engineGetCertificateChain($String* alias) {
	$useLocalCurrentObjectStackCache();
	$var($Object, entry, $nc(this->entries)->get($(convertAlias(alias))));
	if (entry != nullptr && $instanceOf($JavaKeyStore$KeyEntry, entry)) {
		if ($nc(($cast($JavaKeyStore$KeyEntry, entry)))->chain == nullptr) {
			return nullptr;
		} else {
			return $cast($CertificateArray, $nc($nc(($cast($JavaKeyStore$KeyEntry, entry)))->chain)->clone());
		}
	} else {
		return nullptr;
	}
}

$Certificate* JavaKeyStore::engineGetCertificate($String* alias) {
	$useLocalCurrentObjectStackCache();
	$var($Object, entry, $nc(this->entries)->get($(convertAlias(alias))));
	if (entry != nullptr) {
		if ($instanceOf($JavaKeyStore$TrustedCertEntry, entry)) {
			return $nc(($cast($JavaKeyStore$TrustedCertEntry, entry)))->cert;
		} else if ($nc(($cast($JavaKeyStore$KeyEntry, entry)))->chain == nullptr) {
			return nullptr;
		} else {
			return $nc($nc(($cast($JavaKeyStore$KeyEntry, entry)))->chain)->get(0);
		}
	} else {
		return nullptr;
	}
}

$Date* JavaKeyStore::engineGetCreationDate($String* alias) {
	$useLocalCurrentObjectStackCache();
	$var($Object, entry, $nc(this->entries)->get($(convertAlias(alias))));
	if (entry != nullptr) {
		if ($instanceOf($JavaKeyStore$TrustedCertEntry, entry)) {
			return $new($Date, $nc($nc(($cast($JavaKeyStore$TrustedCertEntry, entry)))->date)->getTime());
		} else {
			return $new($Date, $nc($nc(($cast($JavaKeyStore$KeyEntry, entry)))->date)->getTime());
		}
	} else {
		return nullptr;
	}
}

void JavaKeyStore::engineSetKeyEntry($String* alias, $Key* key, $chars* password, $CertificateArray* chain) {
	$useLocalCurrentObjectStackCache();
	$var($KeyProtector, keyProtector, nullptr);
	$var($bytes, passwordBytes, nullptr);
	if (!($instanceOf($PrivateKey, key))) {
		$throwNew($KeyStoreException, "Cannot store non-PrivateKeys"_s);
	}
	if (password == nullptr) {
		$throwNew($KeyStoreException, "password can\'t be null"_s);
	}
	{
		$var($Throwable, var$0, nullptr);
		try {
			try {
				$synchronized(this->entries) {
					$var($JavaKeyStore$KeyEntry, entry, $new($JavaKeyStore$KeyEntry));
					$set(entry, date, $new($Date));
					$assign(passwordBytes, convertToBytes(password));
					$assign(keyProtector, $new($KeyProtector, passwordBytes));
					$set(entry, protectedPrivKey, keyProtector->protect(key));
					if ((chain != nullptr) && (chain->length != 0)) {
						$set(entry, chain, $cast($CertificateArray, chain->clone()));
					} else {
						$set(entry, chain, nullptr);
					}
					$nc(this->entries)->put($(convertAlias(alias)), entry);
				}
			} catch ($NoSuchAlgorithmException& nsae) {
				$throwNew($KeyStoreException, "Key protection algorithm not found"_s);
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			if (passwordBytes != nullptr) {
				$Arrays::fill(passwordBytes, (int8_t)0);
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void JavaKeyStore::engineSetKeyEntry($String* alias, $bytes* key, $CertificateArray* chain) {
	$useLocalCurrentObjectStackCache();
	$synchronized(this->entries) {
		try {
			$new($EncryptedPrivateKeyInfo, key);
		} catch ($IOException& ioe) {
			$throwNew($KeyStoreException, "key is not encoded as EncryptedPrivateKeyInfo"_s);
		}
		$var($JavaKeyStore$KeyEntry, entry, $new($JavaKeyStore$KeyEntry));
		$set(entry, date, $new($Date));
		$set(entry, protectedPrivKey, $cast($bytes, $nc(key)->clone()));
		if ((chain != nullptr) && (chain->length != 0)) {
			$set(entry, chain, $cast($CertificateArray, chain->clone()));
		} else {
			$set(entry, chain, nullptr);
		}
		$nc(this->entries)->put($(convertAlias(alias)), entry);
	}
}

void JavaKeyStore::engineSetCertificateEntry($String* alias, $Certificate* cert) {
	$useLocalCurrentObjectStackCache();
	$synchronized(this->entries) {
		$var($Object, entry, $nc(this->entries)->get($(convertAlias(alias))));
		if ((entry != nullptr) && ($instanceOf($JavaKeyStore$KeyEntry, entry))) {
			$throwNew($KeyStoreException, "Cannot overwrite own certificate"_s);
		}
		$var($JavaKeyStore$TrustedCertEntry, trustedCertEntry, $new($JavaKeyStore$TrustedCertEntry));
		$set(trustedCertEntry, cert, cert);
		$set(trustedCertEntry, date, $new($Date));
		$nc(this->entries)->put($(convertAlias(alias)), trustedCertEntry);
	}
}

void JavaKeyStore::engineDeleteEntry($String* alias) {
	$synchronized(this->entries) {
		$nc(this->entries)->remove($(convertAlias(alias)));
	}
}

$Enumeration* JavaKeyStore::engineAliases() {
	return $nc(this->entries)->keys();
}

bool JavaKeyStore::engineContainsAlias($String* alias) {
	return $nc(this->entries)->containsKey($(convertAlias(alias)));
}

int32_t JavaKeyStore::engineSize() {
	return $nc(this->entries)->size();
}

bool JavaKeyStore::engineIsKeyEntry($String* alias) {
	$useLocalCurrentObjectStackCache();
	$var($Object, entry, $nc(this->entries)->get($(convertAlias(alias))));
	if ((entry != nullptr) && ($instanceOf($JavaKeyStore$KeyEntry, entry))) {
		return true;
	} else {
		return false;
	}
}

bool JavaKeyStore::engineIsCertificateEntry($String* alias) {
	$useLocalCurrentObjectStackCache();
	$var($Object, entry, $nc(this->entries)->get($(convertAlias(alias))));
	if ((entry != nullptr) && ($instanceOf($JavaKeyStore$TrustedCertEntry, entry))) {
		return true;
	} else {
		return false;
	}
}

$String* JavaKeyStore::engineGetCertificateAlias($Certificate* cert) {
	$useLocalCurrentObjectStackCache();
	$var($Certificate, certElem, nullptr);
	{
		$var($Enumeration, e, $nc(this->entries)->keys());
		for (; $nc(e)->hasMoreElements();) {
			$var($String, alias, $cast($String, e->nextElement()));
			$var($Object, entry, $nc(this->entries)->get(alias));
			if ($instanceOf($JavaKeyStore$TrustedCertEntry, entry)) {
				$assign(certElem, $nc(($cast($JavaKeyStore$TrustedCertEntry, entry)))->cert);
			} else if ($nc(($cast($JavaKeyStore$KeyEntry, entry)))->chain != nullptr) {
				$assign(certElem, $nc($nc(($cast($JavaKeyStore$KeyEntry, entry)))->chain)->get(0));
			} else {
				continue;
			}
			if ($nc(certElem)->equals(cert)) {
				return alias;
			}
		}
	}
	return nullptr;
}

void JavaKeyStore::engineStore($OutputStream* stream, $chars* password) {
	$useLocalCurrentObjectStackCache();
	$synchronized(this->entries) {
		if (password == nullptr) {
			$throwNew($IllegalArgumentException, "password can\'t be null"_s);
		}
		$var($bytes, encoded, nullptr);
		$var($MessageDigest, md, getPreKeyedHash(password));
		$var($DataOutputStream, dos, $new($DataOutputStream, $$new($DigestOutputStream, stream, md)));
		dos->writeInt(JavaKeyStore::MAGIC);
		dos->writeInt(JavaKeyStore::VERSION_2);
		dos->writeInt($nc(this->entries)->size());
		{
			$var($Enumeration, e, $nc(this->entries)->keys());
			for (; $nc(e)->hasMoreElements();) {
				$var($String, alias, $cast($String, e->nextElement()));
				$var($Object, entry, $nc(this->entries)->get(alias));
				if ($instanceOf($JavaKeyStore$KeyEntry, entry)) {
					dos->writeInt(1);
					dos->writeUTF(alias);
					dos->writeLong($nc($nc(($cast($JavaKeyStore$KeyEntry, entry)))->date)->getTime());
					dos->writeInt($nc($nc(($cast($JavaKeyStore$KeyEntry, entry)))->protectedPrivKey)->length);
					dos->write($nc(($cast($JavaKeyStore$KeyEntry, entry)))->protectedPrivKey);
					int32_t chainLen = 0;
					if ($nc(($cast($JavaKeyStore$KeyEntry, entry)))->chain == nullptr) {
						chainLen = 0;
					} else {
						chainLen = $nc($nc(($cast($JavaKeyStore$KeyEntry, entry)))->chain)->length;
					}
					dos->writeInt(chainLen);
					for (int32_t i = 0; i < chainLen; ++i) {
						$assign(encoded, $nc($nc($nc(($cast($JavaKeyStore$KeyEntry, entry)))->chain)->get(i))->getEncoded());
						dos->writeUTF($($nc($nc($nc(($cast($JavaKeyStore$KeyEntry, entry)))->chain)->get(i))->getType()));
						dos->writeInt($nc(encoded)->length);
						dos->write(encoded);
					}
				} else {
					dos->writeInt(2);
					dos->writeUTF(alias);
					dos->writeLong($nc($nc(($cast($JavaKeyStore$TrustedCertEntry, entry)))->date)->getTime());
					$assign(encoded, $nc($nc(($cast($JavaKeyStore$TrustedCertEntry, entry)))->cert)->getEncoded());
					dos->writeUTF($($nc($nc(($cast($JavaKeyStore$TrustedCertEntry, entry)))->cert)->getType()));
					dos->writeInt($nc(encoded)->length);
					dos->write(encoded);
				}
			}
		}
		$var($bytes, digest, $nc(md)->digest());
		dos->write(digest);
		dos->flush();
	}
}

void JavaKeyStore::engineLoad($InputStream* stream, $chars* password) {
	$useLocalCurrentObjectStackCache();
	$synchronized(this->entries) {
		$var($DataInputStream, dis, nullptr);
		$var($MessageDigest, md, nullptr);
		$var($CertificateFactory, cf, nullptr);
		$var($Hashtable, cfs, nullptr);
		$var($ByteArrayInputStream, bais, nullptr);
		$var($bytes, encoded, nullptr);
		int32_t trustedKeyCount = 0;
		int32_t privateKeyCount = 0;
		if (stream == nullptr) {
			return;
		}
		if (password != nullptr) {
			$assign(md, getPreKeyedHash(password));
			$assign(dis, $new($DataInputStream, $$new($DigestInputStream, stream, md)));
		} else {
			$assign(dis, $new($DataInputStream, stream));
		}
		int32_t xMagic = $nc(dis)->readInt();
		int32_t xVersion = dis->readInt();
		if (xMagic != JavaKeyStore::MAGIC || (xVersion != JavaKeyStore::VERSION_1 && xVersion != JavaKeyStore::VERSION_2)) {
			$throwNew($IOException, "Invalid keystore format"_s);
		}
		if (xVersion == JavaKeyStore::VERSION_1) {
			$assign(cf, $CertificateFactory::getInstance("X509"_s));
		} else {
			$assign(cfs, $new($Hashtable, 3));
		}
		$nc(this->entries)->clear();
		int32_t count = dis->readInt();
		for (int32_t i = 0; i < count; ++i) {
			int32_t tag = 0;
			$var($String, alias, nullptr);
			tag = dis->readInt();
			if (tag == 1) {
				++privateKeyCount;
				$var($JavaKeyStore$KeyEntry, entry, $new($JavaKeyStore$KeyEntry));
				$assign(alias, dis->readUTF());
				$set(entry, date, $new($Date, dis->readLong()));
				$set(entry, protectedPrivKey, $IOUtils::readExactlyNBytes(dis, dis->readInt()));
				int32_t numOfCerts = dis->readInt();
				if (numOfCerts > 0) {
					$var($List, certs, $new($ArrayList, numOfCerts > 10 ? 10 : numOfCerts));
					for (int32_t j = 0; j < numOfCerts; ++j) {
						if (xVersion == 2) {
							$var($String, certType, dis->readUTF());
							if ($nc(cfs)->containsKey(certType)) {
								$assign(cf, $cast($CertificateFactory, cfs->get(certType)));
							} else {
								$assign(cf, $CertificateFactory::getInstance(certType));
								cfs->put(certType, cf);
							}
						}
						$assign(encoded, $IOUtils::readExactlyNBytes(dis, dis->readInt()));
						$assign(bais, $new($ByteArrayInputStream, encoded));
						certs->add($($nc(cf)->generateCertificate(bais)));
						bais->close();
					}
					$set(entry, chain, $fcast($CertificateArray, certs->toArray($$new($CertificateArray, numOfCerts))));
				}
				$nc(this->entries)->put(alias, entry);
			} else if (tag == 2) {
				++trustedKeyCount;
				$var($JavaKeyStore$TrustedCertEntry, entry, $new($JavaKeyStore$TrustedCertEntry));
				$assign(alias, dis->readUTF());
				$set(entry, date, $new($Date, dis->readLong()));
				if (xVersion == 2) {
					$var($String, certType, dis->readUTF());
					if ($nc(cfs)->containsKey(certType)) {
						$assign(cf, $cast($CertificateFactory, cfs->get(certType)));
					} else {
						$assign(cf, $CertificateFactory::getInstance(certType));
						cfs->put(certType, cf);
					}
				}
				$assign(encoded, $IOUtils::readExactlyNBytes(dis, dis->readInt()));
				$assign(bais, $new($ByteArrayInputStream, encoded));
				$set(entry, cert, $nc(cf)->generateCertificate(bais));
				bais->close();
				$nc(this->entries)->put(alias, entry);
			} else {
				$throwNew($IOException, $$str({"Unrecognized keystore entry: "_s, $$str(tag)}));
			}
		}
		if (JavaKeyStore::debug != nullptr) {
			$nc(JavaKeyStore::debug)->println($$str({"JavaKeyStore load: private key count: "_s, $$str(privateKeyCount), ". trusted key count: "_s, $$str(trustedKeyCount)}));
		}
		if (password != nullptr) {
			$var($bytes, computed, $nc(md)->digest());
			$var($bytes, actual, $IOUtils::readExactlyNBytes(dis, $nc(computed)->length));
			if (!$MessageDigest::isEqual(computed, actual)) {
				$var($Throwable, t, $new($UnrecoverableKeyException, "Password verification failed"_s));
				$throw($cast($IOException, $($$new($IOException, "Keystore was tampered with, or password was incorrect"_s)->initCause(t))));
			}
		}
	}
}

$MessageDigest* JavaKeyStore::getPreKeyedHash($chars* password) {
	$useLocalCurrentObjectStackCache();
	$var($MessageDigest, md, $MessageDigest::getInstance("SHA"_s));
	$var($bytes, passwdBytes, convertToBytes(password));
	$nc(md)->update(passwdBytes);
	$Arrays::fill(passwdBytes, (int8_t)0);
	$init($StandardCharsets);
	md->update($("Mighty Aphrodite"_s->getBytes($StandardCharsets::UTF_8)));
	return md;
}

$bytes* JavaKeyStore::convertToBytes($chars* password) {
	int32_t i = 0;
	int32_t j = 0;
	$var($bytes, passwdBytes, $new($bytes, $nc(password)->length * 2));
	for (i = 0, j = 0; i < password->length; ++i) {
		passwdBytes->set(j++, (int8_t)(password->get(i) >> 8));
		passwdBytes->set(j++, (int8_t)password->get(i));
	}
	return passwdBytes;
}

void clinit$JavaKeyStore($Class* class$) {
	$assignStatic(JavaKeyStore::debug, $Debug::getInstance("keystore"_s));
}

JavaKeyStore::JavaKeyStore() {
}

$Class* JavaKeyStore::load$($String* name, bool initialize) {
	$loadClass(JavaKeyStore, name, initialize, &_JavaKeyStore_ClassInfo_, clinit$JavaKeyStore, allocate$JavaKeyStore);
	return class$;
}

$Class* JavaKeyStore::class$ = nullptr;

		} // provider
	} // security
} // sun