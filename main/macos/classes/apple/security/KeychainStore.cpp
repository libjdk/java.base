#include <apple/security/KeychainStore.h>

#include <apple/security/KeychainStore$CertKeychainItemPair.h>
#include <apple/security/KeychainStore$KeyEntry.h>
#include <apple/security/KeychainStore$TrustedCertEntry.h>
#include <java/io/ByteArrayInputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityManager.h>
#include <java/security/AlgorithmParameters.h>
#include <java/security/Key.h>
#include <java/security/KeyFactory.h>
#include <java/security/KeyStoreException.h>
#include <java/security/KeyStoreSpi.h>
#include <java/security/Permission.h>
#include <java/security/PrivateKey.h>
#include <java/security/SecureRandom.h>
#include <java/security/UnrecoverableKeyException.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/CertificateException.h>
#include <java/security/cert/CertificateFactory.h>
#include <java/security/cert/X509Certificate.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/security/spec/KeySpec.h>
#include <java/security/spec/PKCS8EncodedKeySpec.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Date.h>
#include <java/util/Enumeration.h>
#include <java/util/Hashtable.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <javax/crypto/Cipher.h>
#include <javax/crypto/SecretKey.h>
#include <javax/crypto/SecretKeyFactory.h>
#include <javax/crypto/spec/PBEKeySpec.h>
#include <javax/crypto/spec/PBEParameterSpec.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <jdk/internal/loader/BootLoader.h>
#include <sun/security/pkcs/ContentInfo.h>
#include <sun/security/pkcs/EncryptedPrivateKeyInfo.h>
#include <sun/security/util/Debug.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/KnownOIDs.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <sun/security/x509/AlgorithmId.h>
#include <jcpp.h>

#undef DATA_OID
#undef DECRYPT_MODE
#undef ENCRYPTED_DATA_OID
#undef ENCRYPT_MODE
#undef SALT_LEN

using $KeychainStore$CertKeychainItemPairArray = $Array<::apple::security::KeychainStore$CertKeychainItemPair>;
using $CertificateArray = $Array<::java::security::cert::Certificate>;
using $DerValueArray = $Array<::sun::security::util::DerValue>;
using $byteArray2 = $Array<int8_t, 2>;
using $KeychainStore$CertKeychainItemPair = ::apple::security::KeychainStore$CertKeychainItemPair;
using $KeychainStore$KeyEntry = ::apple::security::KeychainStore$KeyEntry;
using $KeychainStore$TrustedCertEntry = ::apple::security::KeychainStore$TrustedCertEntry;
using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityManager = ::java::lang::SecurityManager;
using $AlgorithmParameters = ::java::security::AlgorithmParameters;
using $Key = ::java::security::Key;
using $KeyFactory = ::java::security::KeyFactory;
using $KeyStoreException = ::java::security::KeyStoreException;
using $KeyStoreSpi = ::java::security::KeyStoreSpi;
using $Permission = ::java::security::Permission;
using $PrivateKey = ::java::security::PrivateKey;
using $SecureRandom = ::java::security::SecureRandom;
using $UnrecoverableKeyException = ::java::security::UnrecoverableKeyException;
using $Certificate = ::java::security::cert::Certificate;
using $CertificateException = ::java::security::cert::CertificateException;
using $CertificateFactory = ::java::security::cert::CertificateFactory;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $KeySpec = ::java::security::spec::KeySpec;
using $PKCS8EncodedKeySpec = ::java::security::spec::PKCS8EncodedKeySpec;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Date = ::java::util::Date;
using $Enumeration = ::java::util::Enumeration;
using $Hashtable = ::java::util::Hashtable;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Cipher = ::javax::crypto::Cipher;
using $SecretKey = ::javax::crypto::SecretKey;
using $SecretKeyFactory = ::javax::crypto::SecretKeyFactory;
using $PBEKeySpec = ::javax::crypto::spec::PBEKeySpec;
using $PBEParameterSpec = ::javax::crypto::spec::PBEParameterSpec;
using $X500Principal = ::javax::security::auth::x500::X500Principal;
using $BootLoader = ::jdk::internal::loader::BootLoader;
using $ContentInfo = ::sun::security::pkcs::ContentInfo;
using $EncryptedPrivateKeyInfo = ::sun::security::pkcs::EncryptedPrivateKeyInfo;
using $Debug = ::sun::security::util::Debug;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerValue = ::sun::security::util::DerValue;
using $KnownOIDs = ::sun::security::util::KnownOIDs;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;
using $AlgorithmId = ::sun::security::x509::AlgorithmId;

namespace apple {
	namespace security {

$FieldInfo _KeychainStore_FieldInfo_[] = {
	{"deletedEntries", "Ljava/util/Hashtable;", "Ljava/util/Hashtable<Ljava/lang/String;Ljava/lang/Object;>;", $PRIVATE, $field(KeychainStore, deletedEntries)},
	{"addedEntries", "Ljava/util/Hashtable;", "Ljava/util/Hashtable<Ljava/lang/String;Ljava/lang/Object;>;", $PRIVATE, $field(KeychainStore, addedEntries)},
	{"entries", "Ljava/util/Hashtable;", "Ljava/util/Hashtable<Ljava/lang/String;Ljava/lang/Object;>;", $PRIVATE, $field(KeychainStore, entries)},
	{"PKCS8ShroudedKeyBag_OID", "Lsun/security/util/ObjectIdentifier;", nullptr, $PRIVATE | $STATIC, $staticField(KeychainStore, PKCS8ShroudedKeyBag_OID)},
	{"pbeWithSHAAnd3KeyTripleDESCBC_OID", "Lsun/security/util/ObjectIdentifier;", nullptr, $PRIVATE | $STATIC, $staticField(KeychainStore, pbeWithSHAAnd3KeyTripleDESCBC_OID)},
	{"iterationCount", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(KeychainStore, iterationCount)},
	{"SALT_LEN", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(KeychainStore, SALT_LEN)},
	{"debug", "Lsun/security/util/Debug;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(KeychainStore, debug)},
	{"random", "Ljava/security/SecureRandom;", nullptr, $PRIVATE, $field(KeychainStore, random)},
	{}
};

$MethodInfo _KeychainStore_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(KeychainStore, init$, void)},
	{"_addItemToKeychain", "(Ljava/lang/String;Z[B[C)J", nullptr, $PRIVATE | $NATIVE, $method(KeychainStore, _addItemToKeychain, int64_t, $String*, bool, $bytes*, $chars*)},
	{"_getEncodedKeyData", "(J[C)[B", nullptr, $PRIVATE | $NATIVE, $method(KeychainStore, _getEncodedKeyData, $bytes*, int64_t, $chars*)},
	{"_releaseKeychainItemRef", "(J)V", nullptr, $PRIVATE | $NATIVE, $method(KeychainStore, _releaseKeychainItemRef, void, int64_t)},
	{"_removeItemFromKeychain", "(J)I", nullptr, $PRIVATE | $NATIVE, $method(KeychainStore, _removeItemFromKeychain, int32_t, int64_t)},
	{"_scanKeychain", "()V", nullptr, $PRIVATE | $NATIVE, $method(KeychainStore, _scanKeychain, void)},
	{"addCertificateToKeychain", "(Ljava/lang/String;Ljava/security/cert/Certificate;)J", nullptr, $PRIVATE, $method(KeychainStore, addCertificateToKeychain, int64_t, $String*, $Certificate*)},
	{"createKeyEntry", "(Ljava/lang/String;JJ[J[[B)V", nullptr, $PRIVATE, $method(KeychainStore, createKeyEntry, void, $String*, int64_t, int64_t, $longs*, $byteArray2*)},
	{"createTrustedCertEntry", "(Ljava/lang/String;JJ[B)V", nullptr, $PRIVATE, $method(KeychainStore, createTrustedCertEntry, void, $String*, int64_t, int64_t, $bytes*)},
	{"encryptPrivateKey", "([B[C)[B", nullptr, $PRIVATE, $method(KeychainStore, encryptPrivateKey, $bytes*, $bytes*, $chars*), "java.io.IOException,java.security.NoSuchAlgorithmException,java.security.UnrecoverableKeyException"},
	{"engineAliases", "()Ljava/util/Enumeration;", "()Ljava/util/Enumeration<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(KeychainStore, engineAliases, $Enumeration*)},
	{"engineContainsAlias", "(Ljava/lang/String;)Z", nullptr, $PUBLIC, $virtualMethod(KeychainStore, engineContainsAlias, bool, $String*)},
	{"engineDeleteEntry", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(KeychainStore, engineDeleteEntry, void, $String*), "java.security.KeyStoreException"},
	{"engineGetCertificate", "(Ljava/lang/String;)Ljava/security/cert/Certificate;", nullptr, $PUBLIC, $virtualMethod(KeychainStore, engineGetCertificate, $Certificate*, $String*)},
	{"engineGetCertificateAlias", "(Ljava/security/cert/Certificate;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(KeychainStore, engineGetCertificateAlias, $String*, $Certificate*)},
	{"engineGetCertificateChain", "(Ljava/lang/String;)[Ljava/security/cert/Certificate;", nullptr, $PUBLIC, $virtualMethod(KeychainStore, engineGetCertificateChain, $CertificateArray*, $String*)},
	{"engineGetCreationDate", "(Ljava/lang/String;)Ljava/util/Date;", nullptr, $PUBLIC, $virtualMethod(KeychainStore, engineGetCreationDate, $Date*, $String*)},
	{"engineGetKey", "(Ljava/lang/String;[C)Ljava/security/Key;", nullptr, $PUBLIC, $virtualMethod(KeychainStore, engineGetKey, $Key*, $String*, $chars*), "java.security.NoSuchAlgorithmException,java.security.UnrecoverableKeyException"},
	{"engineIsCertificateEntry", "(Ljava/lang/String;)Z", nullptr, $PUBLIC, $virtualMethod(KeychainStore, engineIsCertificateEntry, bool, $String*)},
	{"engineIsKeyEntry", "(Ljava/lang/String;)Z", nullptr, $PUBLIC, $virtualMethod(KeychainStore, engineIsKeyEntry, bool, $String*)},
	{"engineLoad", "(Ljava/io/InputStream;[C)V", nullptr, $PUBLIC, $virtualMethod(KeychainStore, engineLoad, void, $InputStream*, $chars*), "java.io.IOException,java.security.NoSuchAlgorithmException,java.security.cert.CertificateException"},
	{"engineSetCertificateEntry", "(Ljava/lang/String;Ljava/security/cert/Certificate;)V", nullptr, $PUBLIC, $virtualMethod(KeychainStore, engineSetCertificateEntry, void, $String*, $Certificate*), "java.security.KeyStoreException"},
	{"engineSetKeyEntry", "(Ljava/lang/String;Ljava/security/Key;[C[Ljava/security/cert/Certificate;)V", nullptr, $PUBLIC, $virtualMethod(KeychainStore, engineSetKeyEntry, void, $String*, $Key*, $chars*, $CertificateArray*), "java.security.KeyStoreException"},
	{"engineSetKeyEntry", "(Ljava/lang/String;[B[Ljava/security/cert/Certificate;)V", nullptr, $PUBLIC, $virtualMethod(KeychainStore, engineSetKeyEntry, void, $String*, $bytes*, $CertificateArray*), "java.security.KeyStoreException"},
	{"engineSize", "()I", nullptr, $PUBLIC, $virtualMethod(KeychainStore, engineSize, int32_t)},
	{"engineStore", "(Ljava/io/OutputStream;[C)V", nullptr, $PUBLIC, $virtualMethod(KeychainStore, engineStore, void, $OutputStream*, $chars*), "java.io.IOException,java.security.NoSuchAlgorithmException,java.security.cert.CertificateException"},
	{"extractKeyData", "(Lsun/security/util/DerInputStream;)[B", nullptr, $PRIVATE, $method(KeychainStore, extractKeyData, $bytes*, $DerInputStream*), "java.io.IOException,java.security.NoSuchAlgorithmException,java.security.cert.CertificateException"},
	{"fetchPrivateKeyFromBag", "([B)[B", nullptr, $PRIVATE, $method(KeychainStore, fetchPrivateKeyFromBag, $bytes*, $bytes*), "java.io.IOException,java.security.NoSuchAlgorithmException,java.security.cert.CertificateException"},
	{"getAlgorithmParameters", "(Ljava/lang/String;)Ljava/security/AlgorithmParameters;", nullptr, $PRIVATE, $method(KeychainStore, getAlgorithmParameters, $AlgorithmParameters*, $String*), "java.io.IOException"},
	{"getPBEKey", "([C)Ljavax/crypto/SecretKey;", nullptr, $PRIVATE, $method(KeychainStore, getPBEKey, $SecretKey*, $chars*), "java.io.IOException"},
	{"getSalt", "()[B", nullptr, $PRIVATE, $method(KeychainStore, getSalt, $bytes*)},
	{"parseAlgParameters", "(Lsun/security/util/DerInputStream;)Ljava/security/AlgorithmParameters;", nullptr, $PRIVATE, $method(KeychainStore, parseAlgParameters, $AlgorithmParameters*, $DerInputStream*), "java.io.IOException"},
	{"permissionCheck", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(KeychainStore, permissionCheck, void)},
	{"validateChain", "([Ljava/security/cert/Certificate;)Z", nullptr, $PRIVATE, $method(KeychainStore, validateChain, bool, $CertificateArray*)},
	{}
};

#define _METHOD_INDEX__addItemToKeychain 1
#define _METHOD_INDEX__getEncodedKeyData 2
#define _METHOD_INDEX__releaseKeychainItemRef 3
#define _METHOD_INDEX__removeItemFromKeychain 4
#define _METHOD_INDEX__scanKeychain 5

$InnerClassInfo _KeychainStore_InnerClassesInfo_[] = {
	{"apple.security.KeychainStore$CertKeychainItemPair", "apple.security.KeychainStore", "CertKeychainItemPair", $PRIVATE | $STATIC},
	{"apple.security.KeychainStore$TrustedCertEntry", "apple.security.KeychainStore", "TrustedCertEntry", $STATIC},
	{"apple.security.KeychainStore$KeyEntry", "apple.security.KeychainStore", "KeyEntry", $STATIC},
	{}
};

$ClassInfo _KeychainStore_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"apple.security.KeychainStore",
	"java.security.KeyStoreSpi",
	nullptr,
	_KeychainStore_FieldInfo_,
	_KeychainStore_MethodInfo_,
	nullptr,
	nullptr,
	_KeychainStore_InnerClassesInfo_,
	nullptr,
	nullptr,
	"apple.security.KeychainStore$CertKeychainItemPair,apple.security.KeychainStore$TrustedCertEntry,apple.security.KeychainStore$KeyEntry"
};

$Object* allocate$KeychainStore($Class* clazz) {
	return $of($alloc(KeychainStore));
}

$ObjectIdentifier* KeychainStore::PKCS8ShroudedKeyBag_OID = nullptr;
$ObjectIdentifier* KeychainStore::pbeWithSHAAnd3KeyTripleDESCBC_OID = nullptr;
$Debug* KeychainStore::debug = nullptr;

void KeychainStore::permissionCheck() {
	$init(KeychainStore);
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sec, $System::getSecurityManager());
	if (sec != nullptr) {
		sec->checkPermission($$new($RuntimePermission, "useKeychainStore"_s));
	}
}

void KeychainStore::init$() {
	$KeyStoreSpi::init$();
	$set(this, deletedEntries, $new($Hashtable));
	$set(this, addedEntries, $new($Hashtable));
	$set(this, entries, $new($Hashtable));
}

$Key* KeychainStore::engineGetKey($String* alias, $chars* password$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($chars, password, password$renamed);
	permissionCheck();
	if (password == nullptr || $nc(password)->length == 0) {
		if (this->random == nullptr) {
			$set(this, random, $new($SecureRandom));
		}
		$assign(password, $nc($($Long::toString($nc(this->random)->nextLong())))->toCharArray());
	}
	$var($Object, entry, $nc(this->entries)->get($($nc(alias)->toLowerCase())));
	if (entry == nullptr || !($instanceOf($KeychainStore$KeyEntry, entry))) {
		return nullptr;
	}
	$var($bytes, exportedKeyInfo, _getEncodedKeyData($nc(($cast($KeychainStore$KeyEntry, entry)))->keyRef, password));
	if (exportedKeyInfo == nullptr) {
		return nullptr;
	}
	$var($PrivateKey, returnValue, nullptr);
	try {
		$var($bytes, pkcs8KeyData, fetchPrivateKeyFromBag(exportedKeyInfo));
		$var($bytes, encryptedKey, nullptr);
		$var($AlgorithmParameters, algParams, nullptr);
		$var($ObjectIdentifier, algOid, nullptr);
		try {
			$var($EncryptedPrivateKeyInfo, encrInfo, $new($EncryptedPrivateKeyInfo, pkcs8KeyData));
			$assign(encryptedKey, encrInfo->getEncryptedData());
			$var($DerValue, val, $new($DerValue, $($nc($(encrInfo->getAlgorithm()))->encode())));
			$var($DerInputStream, in, val->toDerInputStream());
			$assign(algOid, $nc(in)->getOID());
			$assign(algParams, parseAlgParameters(in));
		} catch ($IOException& ioe) {
			$var($UnrecoverableKeyException, uke, $new($UnrecoverableKeyException, $$str({"Private key not stored as PKCS#8 EncryptedPrivateKeyInfo: "_s, ioe})));
			uke->initCause(ioe);
			$throw(uke);
		}
		$var($SecretKey, skey, getPBEKey(password));
		$var($Cipher, cipher, $Cipher::getInstance($($nc(algOid)->toString())));
		$nc(cipher)->init($Cipher::DECRYPT_MODE, static_cast<$Key*>(skey), algParams);
		$var($bytes, decryptedPrivateKey, cipher->doFinal(encryptedKey));
		$var($PKCS8EncodedKeySpec, kspec, $new($PKCS8EncodedKeySpec, decryptedPrivateKey));
		$var($DerValue, val, $new($DerValue, decryptedPrivateKey));
		$var($DerInputStream, in, val->toDerInputStream());
		int32_t i = $nc(in)->getInteger();
		$var($DerValueArray, value, in->getSequence(2));
		if ($nc(value)->length < 1 || $nc(value)->length > 2) {
			$throwNew($IOException, "Invalid length for AlgorithmIdentifier"_s);
		}
		$var($AlgorithmId, algId, $new($AlgorithmId, $($nc($nc(value)->get(0))->getOID())));
		$var($String, algName, algId->getName());
		$var($KeyFactory, kfac, $KeyFactory::getInstance(algName));
		$assign(returnValue, $nc(kfac)->generatePrivate(kspec));
	} catch ($Exception& e) {
		$var($UnrecoverableKeyException, uke, $new($UnrecoverableKeyException, $$str({"Get Key failed: "_s, $(e->getMessage())})));
		uke->initCause(e);
		$throw(uke);
	}
	return returnValue;
}

$bytes* KeychainStore::_getEncodedKeyData(int64_t secKeyRef, $chars* password) {
	$var($bytes, $ret, nullptr);
	$prepareNative(KeychainStore, _getEncodedKeyData, $bytes*, int64_t secKeyRef, $chars* password);
	$assign($ret, $invokeNativeObject(secKeyRef, password));
	$finishNative();
	return $ret;
}

$CertificateArray* KeychainStore::engineGetCertificateChain($String* alias) {
	$useLocalCurrentObjectStackCache();
	permissionCheck();
	$var($Object, entry, $nc(this->entries)->get($($nc(alias)->toLowerCase())));
	if (entry != nullptr && $instanceOf($KeychainStore$KeyEntry, entry)) {
		if ($nc(($cast($KeychainStore$KeyEntry, entry)))->chain == nullptr) {
			return nullptr;
		} else {
			return $cast($CertificateArray, $nc($nc(($cast($KeychainStore$KeyEntry, entry)))->chain)->clone());
		}
	} else {
		return nullptr;
	}
}

$Certificate* KeychainStore::engineGetCertificate($String* alias) {
	$useLocalCurrentObjectStackCache();
	permissionCheck();
	$var($Object, entry, $nc(this->entries)->get($($nc(alias)->toLowerCase())));
	if (entry != nullptr) {
		if ($instanceOf($KeychainStore$TrustedCertEntry, entry)) {
			return $nc(($cast($KeychainStore$TrustedCertEntry, entry)))->cert;
		} else {
			$var($KeychainStore$KeyEntry, ke, $cast($KeychainStore$KeyEntry, entry));
			if (ke->chain == nullptr || $nc(ke->chain)->length == 0) {
				return nullptr;
			}
			return $nc(ke->chain)->get(0);
		}
	} else {
		return nullptr;
	}
}

$Date* KeychainStore::engineGetCreationDate($String* alias) {
	$useLocalCurrentObjectStackCache();
	permissionCheck();
	$var($Object, entry, $nc(this->entries)->get($($nc(alias)->toLowerCase())));
	if (entry != nullptr) {
		if ($instanceOf($KeychainStore$TrustedCertEntry, entry)) {
			return $new($Date, $nc($nc(($cast($KeychainStore$TrustedCertEntry, entry)))->date)->getTime());
		} else {
			return $new($Date, $nc($nc(($cast($KeychainStore$KeyEntry, entry)))->date)->getTime());
		}
	} else {
		return nullptr;
	}
}

void KeychainStore::engineSetKeyEntry($String* alias, $Key* key, $chars* password, $CertificateArray* chain) {
	$useLocalCurrentObjectStackCache();
	permissionCheck();
	$synchronized(this->entries) {
		try {
			$var($KeychainStore$KeyEntry, entry, $new($KeychainStore$KeyEntry));
			$set(entry, date, $new($Date));
			if ($instanceOf($PrivateKey, key)) {
				bool var$0 = ($nc($($nc(key)->getFormat()))->equals("PKCS#8"_s));
				if (var$0 || ($nc($($nc(key)->getFormat()))->equals("PKCS8"_s))) {
					$set(entry, protectedPrivKey, encryptPrivateKey($(key->getEncoded()), password));
					$set(entry, password, $cast($chars, $nc(password)->clone()));
				} else {
					$throwNew($KeyStoreException, "Private key is not encoded as PKCS#8"_s);
				}
			} else {
				$throwNew($KeyStoreException, "Key is not a PrivateKey"_s);
			}
			if (chain != nullptr) {
				if ((chain->length > 1) && !validateChain(chain)) {
					$throwNew($KeyStoreException, "Certificate chain does not validate"_s);
				}
				$set(entry, chain, $cast($CertificateArray, chain->clone()));
				$set(entry, chainRefs, $new($longs, $nc(entry->chain)->length));
			}
			$var($String, lowerAlias, $nc(alias)->toLowerCase());
			if ($nc(this->entries)->get(lowerAlias) != nullptr) {
				$nc(this->deletedEntries)->put(lowerAlias, $($nc(this->entries)->get(lowerAlias)));
			}
			$nc(this->entries)->put(lowerAlias, entry);
			$nc(this->addedEntries)->put(lowerAlias, entry);
		} catch ($Exception& nsae) {
			$var($KeyStoreException, ke, $new($KeyStoreException, $$str({"Key protection algorithm not found: "_s, nsae})));
			ke->initCause(nsae);
			$throw(ke);
		}
	}
}

void KeychainStore::engineSetKeyEntry($String* alias, $bytes* key, $CertificateArray* chain) {
	$useLocalCurrentObjectStackCache();
	permissionCheck();
	$synchronized(this->entries) {
		$var($KeychainStore$KeyEntry, entry, $new($KeychainStore$KeyEntry));
		try {
			$var($EncryptedPrivateKeyInfo, privateKey, $new($EncryptedPrivateKeyInfo, key));
			$set(entry, protectedPrivKey, privateKey->getEncoded());
		} catch ($IOException& ioe) {
			$throwNew($KeyStoreException, "key is not encoded as EncryptedPrivateKeyInfo"_s);
		}
		$set(entry, date, $new($Date));
		if ((chain != nullptr) && (chain->length != 0)) {
			$set(entry, chain, $cast($CertificateArray, chain->clone()));
			$set(entry, chainRefs, $new($longs, $nc(entry->chain)->length));
		}
		$var($String, lowerAlias, $nc(alias)->toLowerCase());
		if ($nc(this->entries)->get(lowerAlias) != nullptr) {
			$nc(this->deletedEntries)->put(lowerAlias, $($nc(this->entries)->get(alias)));
		}
		$nc(this->entries)->put(lowerAlias, entry);
		$nc(this->addedEntries)->put(lowerAlias, entry);
	}
}

void KeychainStore::engineSetCertificateEntry($String* alias, $Certificate* cert) {
	$useLocalCurrentObjectStackCache();
	permissionCheck();
	$synchronized(this->entries) {
		$var($Object, entry, $nc(this->entries)->get($($nc(alias)->toLowerCase())));
		if ((entry != nullptr) && ($instanceOf($KeychainStore$KeyEntry, entry))) {
			$throwNew($KeyStoreException, "Cannot overwrite key entry with certificate"_s);
		}
		$var($Collection, allValues, $nc(this->entries)->values());
		{
			$var($Iterator, i$, $nc(allValues)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Object, value, i$->next());
				{
					if ($instanceOf($KeychainStore$TrustedCertEntry, value)) {
						$var($KeychainStore$TrustedCertEntry, tce, $cast($KeychainStore$TrustedCertEntry, value));
						if ($nc($nc(tce)->cert)->equals(cert)) {
							$throwNew($KeyStoreException, "Keychain does not support mulitple copies of same certificate."_s);
						}
					}
				}
			}
		}
		$var($KeychainStore$TrustedCertEntry, trustedCertEntry, $new($KeychainStore$TrustedCertEntry));
		$set(trustedCertEntry, cert, cert);
		$set(trustedCertEntry, date, $new($Date));
		$var($String, lowerAlias, $nc(alias)->toLowerCase());
		if ($nc(this->entries)->get(lowerAlias) != nullptr) {
			$nc(this->deletedEntries)->put(lowerAlias, $($nc(this->entries)->get(lowerAlias)));
		}
		$nc(this->entries)->put(lowerAlias, trustedCertEntry);
		$nc(this->addedEntries)->put(lowerAlias, trustedCertEntry);
	}
}

void KeychainStore::engineDeleteEntry($String* alias) {
	$useLocalCurrentObjectStackCache();
	permissionCheck();
	$synchronized(this->entries) {
		$var($Object, entry, $nc(this->entries)->remove($($nc(alias)->toLowerCase())));
		$nc(this->deletedEntries)->put($($nc(alias)->toLowerCase()), entry);
	}
}

$Enumeration* KeychainStore::engineAliases() {
	permissionCheck();
	return $nc(this->entries)->keys();
}

bool KeychainStore::engineContainsAlias($String* alias) {
	permissionCheck();
	return $nc(this->entries)->containsKey($($nc(alias)->toLowerCase()));
}

int32_t KeychainStore::engineSize() {
	permissionCheck();
	return $nc(this->entries)->size();
}

bool KeychainStore::engineIsKeyEntry($String* alias) {
	$useLocalCurrentObjectStackCache();
	permissionCheck();
	$var($Object, entry, $nc(this->entries)->get($($nc(alias)->toLowerCase())));
	if ((entry != nullptr) && ($instanceOf($KeychainStore$KeyEntry, entry))) {
		return true;
	} else {
		return false;
	}
}

bool KeychainStore::engineIsCertificateEntry($String* alias) {
	$useLocalCurrentObjectStackCache();
	permissionCheck();
	$var($Object, entry, $nc(this->entries)->get($($nc(alias)->toLowerCase())));
	if ((entry != nullptr) && ($instanceOf($KeychainStore$TrustedCertEntry, entry))) {
		return true;
	} else {
		return false;
	}
}

$String* KeychainStore::engineGetCertificateAlias($Certificate* cert) {
	$useLocalCurrentObjectStackCache();
	permissionCheck();
	$var($Certificate, certElem, nullptr);
	{
		$var($Enumeration, e, $nc(this->entries)->keys());
		for (; $nc(e)->hasMoreElements();) {
			$var($String, alias, $cast($String, e->nextElement()));
			$var($Object, entry, $nc(this->entries)->get(alias));
			if ($instanceOf($KeychainStore$TrustedCertEntry, entry)) {
				$assign(certElem, $nc(($cast($KeychainStore$TrustedCertEntry, entry)))->cert);
			} else {
				$var($KeychainStore$KeyEntry, ke, $cast($KeychainStore$KeyEntry, entry));
				if ($nc(ke)->chain == nullptr || $nc($nc(ke)->chain)->length == 0) {
					continue;
				}
				$assign(certElem, $nc($nc(ke)->chain)->get(0));
			}
			if ($nc(certElem)->equals(cert)) {
				return alias;
			}
		}
	}
	return nullptr;
}

void KeychainStore::engineStore($OutputStream* stream, $chars* password) {
	$useLocalCurrentObjectStackCache();
	permissionCheck();
	{
		$var($Enumeration, e, $nc(this->deletedEntries)->keys());
		for (; $nc(e)->hasMoreElements();) {
			$var($String, alias, $cast($String, e->nextElement()));
			$var($Object, entry, $nc(this->deletedEntries)->get(alias));
			if ($instanceOf($KeychainStore$TrustedCertEntry, entry)) {
				if ($nc(($cast($KeychainStore$TrustedCertEntry, entry)))->certRef != 0) {
					_removeItemFromKeychain($nc(($cast($KeychainStore$TrustedCertEntry, entry)))->certRef);
					_releaseKeychainItemRef($nc(($cast($KeychainStore$TrustedCertEntry, entry)))->certRef);
				}
			} else {
				$var($Certificate, certElem, nullptr);
				$var($KeychainStore$KeyEntry, keyEntry, $cast($KeychainStore$KeyEntry, entry));
				if ($nc(keyEntry)->chain != nullptr) {
					for (int32_t i = 0; i < $nc(keyEntry->chain)->length; ++i) {
						if ($nc(keyEntry->chainRefs)->get(i) != 0) {
							_removeItemFromKeychain($nc(keyEntry->chainRefs)->get(i));
							_releaseKeychainItemRef($nc(keyEntry->chainRefs)->get(i));
						}
					}
					if (keyEntry->keyRef != 0) {
						_removeItemFromKeychain(keyEntry->keyRef);
						_releaseKeychainItemRef(keyEntry->keyRef);
					}
				}
			}
		}
	}
	{
		$var($Enumeration, e, $nc(this->addedEntries)->keys());
		for (; $nc(e)->hasMoreElements();) {
			$var($String, alias, $cast($String, e->nextElement()));
			$var($Object, entry, $nc(this->addedEntries)->get(alias));
			if ($instanceOf($KeychainStore$TrustedCertEntry, entry)) {
				$var($KeychainStore$TrustedCertEntry, tce, $cast($KeychainStore$TrustedCertEntry, entry));
				$var($Certificate, certElem, nullptr);
				$assign(certElem, $nc(tce)->cert);
				tce->certRef = addCertificateToKeychain(alias, certElem);
			} else {
				$var($KeychainStore$KeyEntry, keyEntry, $cast($KeychainStore$KeyEntry, entry));
				if ($nc(keyEntry)->chain != nullptr) {
					for (int32_t i = 0; i < $nc(keyEntry->chain)->length; ++i) {
						$nc(keyEntry->chainRefs)->set(i, addCertificateToKeychain(alias, $nc(keyEntry->chain)->get(i)));
					}
					keyEntry->keyRef = _addItemToKeychain(alias, false, keyEntry->protectedPrivKey, keyEntry->password);
				}
			}
		}
	}
	$nc(this->deletedEntries)->clear();
	$nc(this->addedEntries)->clear();
}

int64_t KeychainStore::addCertificateToKeychain($String* alias, $Certificate* cert) {
	$var($bytes, certblob, nullptr);
	int64_t returnValue = 0;
	try {
		$assign(certblob, $nc(cert)->getEncoded());
		returnValue = _addItemToKeychain(alias, true, certblob, nullptr);
	} catch ($Exception& e) {
		e->printStackTrace();
	}
	return returnValue;
}

int64_t KeychainStore::_addItemToKeychain($String* alias, bool isCertificate, $bytes* datablob, $chars* password) {
	int64_t $ret = 0;
	$prepareNative(KeychainStore, _addItemToKeychain, int64_t, $String* alias, bool isCertificate, $bytes* datablob, $chars* password);
	$ret = $invokeNative(alias, isCertificate, datablob, password);
	$finishNative();
	return $ret;
}

int32_t KeychainStore::_removeItemFromKeychain(int64_t certRef) {
	int32_t $ret = 0;
	$prepareNative(KeychainStore, _removeItemFromKeychain, int32_t, int64_t certRef);
	$ret = $invokeNative(certRef);
	$finishNative();
	return $ret;
}

void KeychainStore::_releaseKeychainItemRef(int64_t keychainItemRef) {
	$prepareNative(KeychainStore, _releaseKeychainItemRef, void, int64_t keychainItemRef);
	$invokeNative(keychainItemRef);
	$finishNative();
}

void KeychainStore::engineLoad($InputStream* stream, $chars* password) {
	$useLocalCurrentObjectStackCache();
	permissionCheck();
	$synchronized(this->entries) {
		{
			$var($Enumeration, e, $nc(this->entries)->keys());
			for (; $nc(e)->hasMoreElements();) {
				$var($String, alias, $cast($String, e->nextElement()));
				$var($Object, entry, $nc(this->entries)->get(alias));
				if ($instanceOf($KeychainStore$TrustedCertEntry, entry)) {
					if ($nc(($cast($KeychainStore$TrustedCertEntry, entry)))->certRef != 0) {
						_releaseKeychainItemRef($nc(($cast($KeychainStore$TrustedCertEntry, entry)))->certRef);
					}
				} else {
					$var($KeychainStore$KeyEntry, keyEntry, $cast($KeychainStore$KeyEntry, entry));
					if ($nc(keyEntry)->chain != nullptr) {
						for (int32_t i = 0; i < $nc(keyEntry->chain)->length; ++i) {
							if ($nc(keyEntry->chainRefs)->get(i) != 0) {
								_releaseKeychainItemRef($nc(keyEntry->chainRefs)->get(i));
							}
						}
						if (keyEntry->keyRef != 0) {
							_releaseKeychainItemRef(keyEntry->keyRef);
						}
					}
				}
			}
		}
		$nc(this->entries)->clear();
		_scanKeychain();
		if (KeychainStore::debug != nullptr) {
			$nc(KeychainStore::debug)->println($$str({"KeychainStore load entry count: "_s, $$str($nc(this->entries)->size())}));
		}
	}
}

void KeychainStore::_scanKeychain() {
	$prepareNative(KeychainStore, _scanKeychain, void);
	$invokeNative();
	$finishNative();
}

void KeychainStore::createTrustedCertEntry($String* alias$renamed, int64_t keychainItemRef, int64_t creationDate, $bytes* derStream) {
	$useLocalCurrentObjectStackCache();
	$var($String, alias, alias$renamed);
	$var($KeychainStore$TrustedCertEntry, tce, $new($KeychainStore$TrustedCertEntry));
	try {
		$var($CertificateFactory, cf, $CertificateFactory::getInstance("X.509"_s));
		$var($InputStream, input, $new($ByteArrayInputStream, derStream));
		$var($X509Certificate, cert, $cast($X509Certificate, $nc(cf)->generateCertificate(input)));
		input->close();
		$set(tce, cert, cert);
		tce->certRef = keychainItemRef;
		if (creationDate != 0) {
			$set(tce, date, $new($Date, creationDate));
		} else {
			$set(tce, date, $new($Date));
		}
		int32_t uniqueVal = 1;
		$var($String, originalAlias, alias);
		while ($nc(this->entries)->containsKey($($nc(alias)->toLowerCase()))) {
			$assign(alias, $str({originalAlias, " "_s, $$str(uniqueVal)}));
			++uniqueVal;
		}
		$nc(this->entries)->put($($nc(alias)->toLowerCase()), tce);
	} catch ($Exception& e) {
		$nc($System::err)->println($$str({"KeychainStore Ignored Exception: "_s, e}));
	}
}

void KeychainStore::createKeyEntry($String* alias$renamed, int64_t creationDate, int64_t secKeyRef, $longs* secCertificateRefs, $byteArray2* rawCertData) {
	$useLocalCurrentObjectStackCache();
	$var($String, alias, alias$renamed);
	$var($KeychainStore$KeyEntry, ke, $new($KeychainStore$KeyEntry));
	$set(ke, protectedPrivKey, nullptr);
	ke->keyRef = secKeyRef;
	if (creationDate != 0) {
		$set(ke, date, $new($Date, creationDate));
	} else {
		$set(ke, date, $new($Date));
	}
	$var($List, createdCerts, $new($ArrayList));
	try {
		$var($CertificateFactory, cf, $CertificateFactory::getInstance("X.509"_s));
		for (int32_t i = 0; i < $nc(rawCertData)->length; ++i) {
			try {
				$var($InputStream, input, $new($ByteArrayInputStream, rawCertData->get(i)));
				$var($X509Certificate, cert, $cast($X509Certificate, $nc(cf)->generateCertificate(input)));
				input->close();
				createdCerts->add($$new($KeychainStore$CertKeychainItemPair, $nc(secCertificateRefs)->get(i), cert));
			} catch ($CertificateException& e) {
				$nc($System::err)->println($$str({"KeychainStore Ignored Exception: "_s, e}));
			}
		}
	} catch ($CertificateException& e) {
		e->printStackTrace();
	} catch ($IOException& ioe) {
		ioe->printStackTrace();
	}
	$var($KeychainStore$CertKeychainItemPairArray, objArray, $fcast($KeychainStore$CertKeychainItemPairArray, createdCerts->toArray($$new($KeychainStore$CertKeychainItemPairArray, 0))));
	$var($CertificateArray, certArray, $new($CertificateArray, $nc(objArray)->length));
	$var($longs, certRefArray, $new($longs, objArray->length));
	for (int32_t i = 0; i < objArray->length; ++i) {
		$var($KeychainStore$CertKeychainItemPair, addedItem, objArray->get(i));
		certArray->set(i, $nc(addedItem)->mCert);
		certRefArray->set(i, addedItem->mCertificateRef);
	}
	$set(ke, chain, certArray);
	$set(ke, chainRefs, certRefArray);
	int32_t uniqueVal = 1;
	$var($String, originalAlias, alias);
	while ($nc(this->entries)->containsKey($($nc(alias)->toLowerCase()))) {
		$assign(alias, $str({originalAlias, " "_s, $$str(uniqueVal)}));
		++uniqueVal;
	}
	$nc(this->entries)->put($($nc(alias)->toLowerCase()), ke);
}

bool KeychainStore::validateChain($CertificateArray* certChain) {
	$useLocalCurrentObjectStackCache();
	for (int32_t i = 0; i < $nc(certChain)->length - 1; ++i) {
		$var($X500Principal, issuerDN, $nc(($cast($X509Certificate, certChain->get(i))))->getIssuerX500Principal());
		$var($X500Principal, subjectDN, $nc(($cast($X509Certificate, certChain->get(i + 1))))->getSubjectX500Principal());
		if (!($nc(issuerDN)->equals(subjectDN))) {
			return false;
		}
	}
	return true;
}

$bytes* KeychainStore::fetchPrivateKeyFromBag($bytes* privateKeyInfo) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, returnValue, nullptr);
	$var($DerValue, val, $new($DerValue, static_cast<$InputStream*>($$new($ByteArrayInputStream, privateKeyInfo))));
	$var($DerInputStream, s, val->toDerInputStream());
	int32_t version = $nc(s)->getInteger();
	if (version != 3) {
		$throwNew($IOException, "PKCS12 keystore not in version 3 format"_s);
	}
	$var($bytes, authSafeData, nullptr);
	$var($ContentInfo, authSafe, $new($ContentInfo, s));
	$var($ObjectIdentifier, contentType, authSafe->getContentType());
	if ($nc(contentType)->equals($ContentInfo::DATA_OID)) {
		$assign(authSafeData, authSafe->getData());
	} else {
		$throwNew($IOException, "public key protected PKCS12 not supported"_s);
	}
	$var($DerInputStream, as, $new($DerInputStream, authSafeData));
	$var($DerValueArray, safeContentsArray, as->getSequence(2));
	int32_t count = $nc(safeContentsArray)->length;
	for (int32_t i = 0; i < count; ++i) {
		$var($bytes, safeContentsData, nullptr);
		$var($ContentInfo, safeContents, nullptr);
		$var($DerInputStream, sci, nullptr);
		$var($bytes, eAlgId, nullptr);
		$assign(sci, $new($DerInputStream, $($nc(safeContentsArray->get(i))->toByteArray())));
		$assign(safeContents, $new($ContentInfo, sci));
		$assign(contentType, safeContents->getContentType());
		$assign(safeContentsData, nullptr);
		if ($nc(contentType)->equals($ContentInfo::DATA_OID)) {
			$assign(safeContentsData, safeContents->getData());
		} else {
			if (contentType->equals($ContentInfo::ENCRYPTED_DATA_OID)) {
				continue;
			} else {
				$throwNew($IOException, "public key protected PKCS12 not supported"_s);
			}
		}
		$var($DerInputStream, sc, $new($DerInputStream, safeContentsData));
		$assign(returnValue, extractKeyData(sc));
	}
	return returnValue;
}

$bytes* KeychainStore::extractKeyData($DerInputStream* stream) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, returnValue, nullptr);
	$var($DerValueArray, safeBags, $nc(stream)->getSequence(2));
	int32_t count = $nc(safeBags)->length;
	for (int32_t i = 0; i < count; ++i) {
		$var($ObjectIdentifier, bagId, nullptr);
		$var($DerInputStream, sbi, nullptr);
		$var($DerValue, bagValue, nullptr);
		$var($Object, bagItem, nullptr);
		$assign(sbi, $nc(safeBags->get(i))->toDerInputStream());
		$assign(bagId, $nc(sbi)->getOID());
		$assign(bagValue, sbi->getDerValue());
		if (!$nc(bagValue)->isContextSpecific((int8_t)0)) {
			$throwNew($IOException, $$str({"unsupported PKCS12 bag value type "_s, $$str(bagValue->tag)}));
		}
		$assign(bagValue, $nc($nc(bagValue)->data$)->getDerValue());
		if ($nc(bagId)->equals(KeychainStore::PKCS8ShroudedKeyBag_OID)) {
			$assign(returnValue, bagValue->toByteArray());
		} else {
			$nc($System::out)->println($$str({"Unsupported bag type \'"_s, bagId, "\'"_s}));
		}
	}
	return returnValue;
}

$AlgorithmParameters* KeychainStore::getAlgorithmParameters($String* algorithm) {
	$useLocalCurrentObjectStackCache();
	$var($AlgorithmParameters, algParams, nullptr);
	$var($PBEParameterSpec, paramSpec, $new($PBEParameterSpec, $(getSalt()), KeychainStore::iterationCount));
	try {
		$assign(algParams, $AlgorithmParameters::getInstance(algorithm));
		$nc(algParams)->init(static_cast<$AlgorithmParameterSpec*>(paramSpec));
	} catch ($Exception& e) {
		$var($IOException, ioe, $new($IOException, $$str({"getAlgorithmParameters failed: "_s, $(e->getMessage())})));
		ioe->initCause(e);
		$throw(ioe);
	}
	return algParams;
}

$bytes* KeychainStore::getSalt() {
	$var($bytes, salt, $new($bytes, KeychainStore::SALT_LEN));
	if (this->random == nullptr) {
		$set(this, random, $new($SecureRandom));
	}
	$nc(this->random)->nextBytes(salt);
	return salt;
}

$AlgorithmParameters* KeychainStore::parseAlgParameters($DerInputStream* in) {
	$useLocalCurrentObjectStackCache();
	$var($AlgorithmParameters, algParams, nullptr);
	try {
		$var($DerValue, params, nullptr);
		if ($nc(in)->available() == 0) {
			$assign(params, nullptr);
		} else {
			$assign(params, in->getDerValue());
			if ($nc(params)->tag == $DerValue::tag_Null) {
				$assign(params, nullptr);
			}
		}
		if (params != nullptr) {
			$assign(algParams, $AlgorithmParameters::getInstance("PBE"_s));
			$nc(algParams)->init($(params->toByteArray()));
		}
	} catch ($Exception& e) {
		$var($IOException, ioe, $new($IOException, $$str({"parseAlgParameters failed: "_s, $(e->getMessage())})));
		ioe->initCause(e);
		$throw(ioe);
	}
	return algParams;
}

$SecretKey* KeychainStore::getPBEKey($chars* password) {
	$useLocalCurrentObjectStackCache();
	$var($SecretKey, skey, nullptr);
	try {
		$var($PBEKeySpec, keySpec, $new($PBEKeySpec, password));
		$var($SecretKeyFactory, skFac, $SecretKeyFactory::getInstance("PBE"_s));
		$assign(skey, $nc(skFac)->generateSecret(keySpec));
	} catch ($Exception& e) {
		$var($IOException, ioe, $new($IOException, $$str({"getSecretKey failed: "_s, $(e->getMessage())})));
		ioe->initCause(e);
		$throw(ioe);
	}
	return skey;
}

$bytes* KeychainStore::encryptPrivateKey($bytes* data, $chars* password) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, key, nullptr);
	try {
		$var($AlgorithmParameters, algParams, getAlgorithmParameters("PBEWithSHA1AndDESede"_s));
		$var($SecretKey, skey, getPBEKey(password));
		$var($Cipher, cipher, $Cipher::getInstance("PBEWithSHA1AndDESede"_s));
		$nc(cipher)->init($Cipher::ENCRYPT_MODE, static_cast<$Key*>(skey), algParams);
		$var($bytes, encryptedKey, cipher->doFinal(data));
		$var($AlgorithmId, algid, $new($AlgorithmId, KeychainStore::pbeWithSHAAnd3KeyTripleDESCBC_OID, algParams));
		$var($EncryptedPrivateKeyInfo, encrInfo, $new($EncryptedPrivateKeyInfo, algid, encryptedKey));
		$assign(key, encrInfo->getEncoded());
	} catch ($Exception& e) {
		$var($UnrecoverableKeyException, uke, $new($UnrecoverableKeyException, $$str({"Encrypt Private Key failed: "_s, $(e->getMessage())})));
		uke->initCause(e);
		$throw(uke);
	}
	return key;
}

void clinit$KeychainStore($Class* class$) {
	$init($KnownOIDs);
	$assignStatic(KeychainStore::PKCS8ShroudedKeyBag_OID, $ObjectIdentifier::of($KnownOIDs::PKCS8ShroudedKeyBag));
	$assignStatic(KeychainStore::pbeWithSHAAnd3KeyTripleDESCBC_OID, $ObjectIdentifier::of($KnownOIDs::PBEWithSHA1AndDESede));
	$assignStatic(KeychainStore::debug, $Debug::getInstance("keystore"_s));
	{
		$BootLoader::loadLibrary("osxsecurity"_s);
	}
}

KeychainStore::KeychainStore() {
}

$Class* KeychainStore::load$($String* name, bool initialize) {
	$loadClass(KeychainStore, name, initialize, &_KeychainStore_ClassInfo_, clinit$KeychainStore, allocate$KeychainStore);
	return class$;
}

$Class* KeychainStore::class$ = nullptr;

	} // security
} // apple