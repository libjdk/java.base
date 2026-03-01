#include <sun/security/pkcs12/PKCS12KeyStore.h>

#include <java/io/ByteArrayInputStream.h>
#include <java/io/DataInputStream.h>
#include <java/io/File.h>
#include <java/io/FileInputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/CharSequence.h>
#include <java/lang/NumberFormatException.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/StandardCharsets.h>
#include <java/security/AccessController.h>
#include <java/security/AlgorithmParameters.h>
#include <java/security/InvalidAlgorithmParameterException.h>
#include <java/security/Key.h>
#include <java/security/KeyFactory.h>
#include <java/security/KeyStore$Entry$Attribute.h>
#include <java/security/KeyStore$Entry.h>
#include <java/security/KeyStore$PasswordProtection.h>
#include <java/security/KeyStore$PrivateKeyEntry.h>
#include <java/security/KeyStore$ProtectionParameter.h>
#include <java/security/KeyStore$SecretKeyEntry.h>
#include <java/security/KeyStore$TrustedCertificateEntry.h>
#include <java/security/KeyStore.h>
#include <java/security/KeyStoreException.h>
#include <java/security/KeyStoreSpi.h>
#include <java/security/MessageDigest.h>
#include <java/security/PKCS12Attribute.h>
#include <java/security/PrivateKey.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/SecureRandom.h>
#include <java/security/UnrecoverableKeyException.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/CertificateFactory.h>
#include <java/security/cert/X509Certificate.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/security/spec/EncodedKeySpec.h>
#include <java/security/spec/InvalidParameterSpecException.h>
#include <java/security/spec/KeySpec.h>
#include <java/security/spec/PKCS8EncodedKeySpec.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Date.h>
#include <java/util/Enumeration.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedHashMap.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <javax/crypto/Cipher.h>
#include <javax/crypto/Mac.h>
#include <javax/crypto/SecretKey.h>
#include <javax/crypto/SecretKeyFactory.h>
#include <javax/crypto/spec/PBEKeySpec.h>
#include <javax/crypto/spec/PBEParameterSpec.h>
#include <javax/crypto/spec/SecretKeySpec.h>
#include <javax/security/auth/DestroyFailedException.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <jdk/internal/access/JavaSecuritySpecAccess.h>
#include <jdk/internal/access/JavaxCryptoSpecAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <sun/security/action/GetPropertyAction.h>
#include <sun/security/pkcs/ContentInfo.h>
#include <sun/security/pkcs/EncryptedPrivateKeyInfo.h>
#include <sun/security/pkcs12/MacData.h>
#include <sun/security/pkcs12/PKCS12KeyStore$1.h>
#include <sun/security/pkcs12/PKCS12KeyStore$CertEntry.h>
#include <sun/security/pkcs12/PKCS12KeyStore$Entry.h>
#include <sun/security/pkcs12/PKCS12KeyStore$KeyEntry.h>
#include <sun/security/pkcs12/PKCS12KeyStore$PrivateKeyEntry.h>
#include <sun/security/pkcs12/PKCS12KeyStore$RetryWithZero.h>
#include <sun/security/pkcs12/PKCS12KeyStore$SecretKeyEntry.h>
#include <sun/security/tools/KeyStoreUtil.h>
#include <sun/security/util/Debug.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/KnownOIDs.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <sun/security/util/SecurityProperties.h>
#include <sun/security/x509/AlgorithmId.h>
#include <sun/security/x509/AuthorityKeyIdentifierExtension.h>
#include <jcpp.h>

#undef CORE_ATTRIBUTES
#undef DATA_OID
#undef DECRYPT_MODE
#undef DEFAULT_CERT_PBE_ALGORITHM
#undef DEFAULT_CERT_PBE_ITERATION_COUNT
#undef DEFAULT_KEY_PBE_ALGORITHM
#undef DEFAULT_KEY_PBE_ITERATION_COUNT
#undef DEFAULT_MAC_ALGORITHM
#undef DEFAULT_MAC_ITERATION_COUNT
#undef ENCRYPTED_DATA_OID
#undef ENCRYPT_MODE
#undef ENGLISH
#undef LEGACY_CERT_PBE_ALGORITHM
#undef LEGACY_KEY_PBE_ALGORITHM
#undef LEGACY_MAC_ALGORITHM
#undef LEGACY_MAC_ITERATION_COUNT
#undef LEGACY_PBE_ITERATION_COUNT
#undef MAX_ITERATION_COUNT
#undef PBES2
#undef PKCS12_HEADER_MASKS
#undef PKCS12_HEADER_PATTERNS
#undef SALT_LEN
#undef TAG_CONTEXT
#undef USE_LEGACY_PROP
#undef UTF_8
#undef VERSION_3

using $CertificateArray = $Array<::java::security::cert::Certificate>;
using $PKCS12KeyStore$PrivateKeyEntryArray = $Array<::sun::security::pkcs12::PKCS12KeyStore$PrivateKeyEntry>;
using $DerValueArray = $Array<::sun::security::util::DerValue>;
using $KnownOIDsArray = $Array<::sun::security::util::KnownOIDs>;
using $ObjectIdentifierArray = $Array<::sun::security::util::ObjectIdentifier>;
using $longArray2 = $Array<int64_t, 2>;
using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $DataInputStream = ::java::io::DataInputStream;
using $File = ::java::io::File;
using $FileInputStream = ::java::io::FileInputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $Serializable = ::java::io::Serializable;
using $Boolean = ::java::lang::Boolean;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $Void = ::java::lang::Void;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $AccessController = ::java::security::AccessController;
using $AlgorithmParameters = ::java::security::AlgorithmParameters;
using $InvalidAlgorithmParameterException = ::java::security::InvalidAlgorithmParameterException;
using $Key = ::java::security::Key;
using $KeyFactory = ::java::security::KeyFactory;
using $KeyStore$Entry = ::java::security::KeyStore$Entry;
using $KeyStore$Entry$Attribute = ::java::security::KeyStore$Entry$Attribute;
using $KeyStore$PasswordProtection = ::java::security::KeyStore$PasswordProtection;
using $KeyStore$PrivateKeyEntry = ::java::security::KeyStore$PrivateKeyEntry;
using $KeyStore$ProtectionParameter = ::java::security::KeyStore$ProtectionParameter;
using $KeyStore$SecretKeyEntry = ::java::security::KeyStore$SecretKeyEntry;
using $KeyStore$TrustedCertificateEntry = ::java::security::KeyStore$TrustedCertificateEntry;
using $KeyStoreException = ::java::security::KeyStoreException;
using $KeyStoreSpi = ::java::security::KeyStoreSpi;
using $MessageDigest = ::java::security::MessageDigest;
using $PKCS12Attribute = ::java::security::PKCS12Attribute;
using $PrivateKey = ::java::security::PrivateKey;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $SecureRandom = ::java::security::SecureRandom;
using $UnrecoverableKeyException = ::java::security::UnrecoverableKeyException;
using $Certificate = ::java::security::cert::Certificate;
using $CertificateFactory = ::java::security::cert::CertificateFactory;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $EncodedKeySpec = ::java::security::spec::EncodedKeySpec;
using $InvalidParameterSpecException = ::java::security::spec::InvalidParameterSpecException;
using $KeySpec = ::java::security::spec::KeySpec;
using $PKCS8EncodedKeySpec = ::java::security::spec::PKCS8EncodedKeySpec;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Date = ::java::util::Date;
using $Enumeration = ::java::util::Enumeration;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $LinkedHashMap = ::java::util::LinkedHashMap;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $Cipher = ::javax::crypto::Cipher;
using $Mac = ::javax::crypto::Mac;
using $SecretKey = ::javax::crypto::SecretKey;
using $SecretKeyFactory = ::javax::crypto::SecretKeyFactory;
using $PBEKeySpec = ::javax::crypto::spec::PBEKeySpec;
using $PBEParameterSpec = ::javax::crypto::spec::PBEParameterSpec;
using $SecretKeySpec = ::javax::crypto::spec::SecretKeySpec;
using $DestroyFailedException = ::javax::security::auth::DestroyFailedException;
using $X500Principal = ::javax::security::auth::x500::X500Principal;
using $JavaSecuritySpecAccess = ::jdk::internal::access::JavaSecuritySpecAccess;
using $JavaxCryptoSpecAccess = ::jdk::internal::access::JavaxCryptoSpecAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;
using $ContentInfo = ::sun::security::pkcs::ContentInfo;
using $EncryptedPrivateKeyInfo = ::sun::security::pkcs::EncryptedPrivateKeyInfo;
using $MacData = ::sun::security::pkcs12::MacData;
using $PKCS12KeyStore$1 = ::sun::security::pkcs12::PKCS12KeyStore$1;
using $PKCS12KeyStore$CertEntry = ::sun::security::pkcs12::PKCS12KeyStore$CertEntry;
using $PKCS12KeyStore$Entry = ::sun::security::pkcs12::PKCS12KeyStore$Entry;
using $PKCS12KeyStore$KeyEntry = ::sun::security::pkcs12::PKCS12KeyStore$KeyEntry;
using $PKCS12KeyStore$PrivateKeyEntry = ::sun::security::pkcs12::PKCS12KeyStore$PrivateKeyEntry;
using $PKCS12KeyStore$RetryWithZero = ::sun::security::pkcs12::PKCS12KeyStore$RetryWithZero;
using $PKCS12KeyStore$SecretKeyEntry = ::sun::security::pkcs12::PKCS12KeyStore$SecretKeyEntry;
using $KeyStoreUtil = ::sun::security::tools::KeyStoreUtil;
using $Debug = ::sun::security::util::Debug;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;
using $KnownOIDs = ::sun::security::util::KnownOIDs;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;
using $SecurityProperties = ::sun::security::util::SecurityProperties;
using $AlgorithmId = ::sun::security::x509::AlgorithmId;
using $AuthorityKeyIdentifierExtension = ::sun::security::x509::AuthorityKeyIdentifierExtension;

namespace sun {
	namespace security {
		namespace pkcs12 {

class PKCS12KeyStore$$Lambda$lambda$engineGetKey$0 : public $PKCS12KeyStore$RetryWithZero {
	$class(PKCS12KeyStore$$Lambda$lambda$engineGetKey$0, $NO_CLASS_INIT, $PKCS12KeyStore$RetryWithZero)
public:
	void init$(PKCS12KeyStore* inst, $ObjectIdentifier* algOid, $AlgorithmParameters* algParams, $bytes* encryptedKey, $PKCS12KeyStore$Entry* entry, $String* alias, int32_t ic) {
		$set(this, inst$, inst);
		$set(this, algOid, algOid);
		$set(this, algParams, algParams);
		$set(this, encryptedKey, encryptedKey);
		$set(this, entry, entry);
		$set(this, alias, alias);
		this->ic = ic;
	}
	virtual $Object* tryOnce($chars* pass) override {
		 return $of($nc(inst$)->lambda$engineGetKey$0(algOid, algParams, encryptedKey, entry, alias, ic, pass));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<PKCS12KeyStore$$Lambda$lambda$engineGetKey$0>());
	}
	PKCS12KeyStore* inst$ = nullptr;
	$ObjectIdentifier* algOid = nullptr;
	$AlgorithmParameters* algParams = nullptr;
	$bytes* encryptedKey = nullptr;
	$PKCS12KeyStore$Entry* entry = nullptr;
	$String* alias = nullptr;
	int32_t ic = 0;
	static $FieldInfo fieldInfos[8];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo PKCS12KeyStore$$Lambda$lambda$engineGetKey$0::fieldInfos[8] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(PKCS12KeyStore$$Lambda$lambda$engineGetKey$0, inst$)},
	{"algOid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC, $field(PKCS12KeyStore$$Lambda$lambda$engineGetKey$0, algOid)},
	{"algParams", "Ljava/security/AlgorithmParameters;", nullptr, $PUBLIC, $field(PKCS12KeyStore$$Lambda$lambda$engineGetKey$0, algParams)},
	{"encryptedKey", "[B", nullptr, $PUBLIC, $field(PKCS12KeyStore$$Lambda$lambda$engineGetKey$0, encryptedKey)},
	{"entry", "Lsun/security/pkcs12/PKCS12KeyStore$Entry;", nullptr, $PUBLIC, $field(PKCS12KeyStore$$Lambda$lambda$engineGetKey$0, entry)},
	{"alias", "Ljava/lang/String;", nullptr, $PUBLIC, $field(PKCS12KeyStore$$Lambda$lambda$engineGetKey$0, alias)},
	{"ic", "I", nullptr, $PUBLIC, $field(PKCS12KeyStore$$Lambda$lambda$engineGetKey$0, ic)},
	{}
};
$MethodInfo PKCS12KeyStore$$Lambda$lambda$engineGetKey$0::methodInfos[3] = {
	{"<init>", "(Lsun/security/pkcs12/PKCS12KeyStore;Lsun/security/util/ObjectIdentifier;Ljava/security/AlgorithmParameters;[BLsun/security/pkcs12/PKCS12KeyStore$Entry;Ljava/lang/String;I)V", nullptr, $PUBLIC, $method(PKCS12KeyStore$$Lambda$lambda$engineGetKey$0, init$, void, PKCS12KeyStore*, $ObjectIdentifier*, $AlgorithmParameters*, $bytes*, $PKCS12KeyStore$Entry*, $String*, int32_t)},
	{"tryOnce", "([C)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(PKCS12KeyStore$$Lambda$lambda$engineGetKey$0, tryOnce, $Object*, $chars*)},
	{}
};
$ClassInfo PKCS12KeyStore$$Lambda$lambda$engineGetKey$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.security.pkcs12.PKCS12KeyStore$$Lambda$lambda$engineGetKey$0",
	"java.lang.Object",
	"sun.security.pkcs12.PKCS12KeyStore$RetryWithZero",
	fieldInfos,
	methodInfos
};
$Class* PKCS12KeyStore$$Lambda$lambda$engineGetKey$0::load$($String* name, bool initialize) {
	$loadClass(PKCS12KeyStore$$Lambda$lambda$engineGetKey$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* PKCS12KeyStore$$Lambda$lambda$engineGetKey$0::class$ = nullptr;

class PKCS12KeyStore$$Lambda$lambda$engineLoad$1$1 : public $PKCS12KeyStore$RetryWithZero {
	$class(PKCS12KeyStore$$Lambda$lambda$engineLoad$1$1, $NO_CLASS_INIT, $PKCS12KeyStore$RetryWithZero)
public:
	void init$(PKCS12KeyStore* inst, $ObjectIdentifier* algOid, $AlgorithmParameters* algParams, $bytes* rawData) {
		$set(this, inst$, inst);
		$set(this, algOid, algOid);
		$set(this, algParams, algParams);
		$set(this, rawData, rawData);
	}
	virtual $Object* tryOnce($chars* pass) override {
		 return $nc(inst$)->lambda$engineLoad$1(algOid, algParams, rawData, pass);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<PKCS12KeyStore$$Lambda$lambda$engineLoad$1$1>());
	}
	PKCS12KeyStore* inst$ = nullptr;
	$ObjectIdentifier* algOid = nullptr;
	$AlgorithmParameters* algParams = nullptr;
	$bytes* rawData = nullptr;
	static $FieldInfo fieldInfos[5];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo PKCS12KeyStore$$Lambda$lambda$engineLoad$1$1::fieldInfos[5] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(PKCS12KeyStore$$Lambda$lambda$engineLoad$1$1, inst$)},
	{"algOid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC, $field(PKCS12KeyStore$$Lambda$lambda$engineLoad$1$1, algOid)},
	{"algParams", "Ljava/security/AlgorithmParameters;", nullptr, $PUBLIC, $field(PKCS12KeyStore$$Lambda$lambda$engineLoad$1$1, algParams)},
	{"rawData", "[B", nullptr, $PUBLIC, $field(PKCS12KeyStore$$Lambda$lambda$engineLoad$1$1, rawData)},
	{}
};
$MethodInfo PKCS12KeyStore$$Lambda$lambda$engineLoad$1$1::methodInfos[3] = {
	{"<init>", "(Lsun/security/pkcs12/PKCS12KeyStore;Lsun/security/util/ObjectIdentifier;Ljava/security/AlgorithmParameters;[B)V", nullptr, $PUBLIC, $method(PKCS12KeyStore$$Lambda$lambda$engineLoad$1$1, init$, void, PKCS12KeyStore*, $ObjectIdentifier*, $AlgorithmParameters*, $bytes*)},
	{"tryOnce", "([C)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(PKCS12KeyStore$$Lambda$lambda$engineLoad$1$1, tryOnce, $Object*, $chars*)},
	{}
};
$ClassInfo PKCS12KeyStore$$Lambda$lambda$engineLoad$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.security.pkcs12.PKCS12KeyStore$$Lambda$lambda$engineLoad$1$1",
	"java.lang.Object",
	"sun.security.pkcs12.PKCS12KeyStore$RetryWithZero",
	fieldInfos,
	methodInfos
};
$Class* PKCS12KeyStore$$Lambda$lambda$engineLoad$1$1::load$($String* name, bool initialize) {
	$loadClass(PKCS12KeyStore$$Lambda$lambda$engineLoad$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* PKCS12KeyStore$$Lambda$lambda$engineLoad$1$1::class$ = nullptr;

class PKCS12KeyStore$$Lambda$lambda$engineLoad$2$2 : public $PKCS12KeyStore$RetryWithZero {
	$class(PKCS12KeyStore$$Lambda$lambda$engineLoad$2$2, $NO_CLASS_INIT, $PKCS12KeyStore$RetryWithZero)
public:
	void init$(PKCS12KeyStore* inst, $Mac* m, $PBEParameterSpec* params, $bytes* authSafeData, int32_t ic, $MacData* macData) {
		$set(this, inst$, inst);
		$set(this, m, m);
		$set(this, params, params);
		$set(this, authSafeData, authSafeData);
		this->ic = ic;
		$set(this, macData, macData);
	}
	virtual $Object* tryOnce($chars* pass) override {
		 return $of($nc(inst$)->lambda$engineLoad$2(m, params, authSafeData, ic, macData, pass));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<PKCS12KeyStore$$Lambda$lambda$engineLoad$2$2>());
	}
	PKCS12KeyStore* inst$ = nullptr;
	$Mac* m = nullptr;
	$PBEParameterSpec* params = nullptr;
	$bytes* authSafeData = nullptr;
	int32_t ic = 0;
	$MacData* macData = nullptr;
	static $FieldInfo fieldInfos[7];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo PKCS12KeyStore$$Lambda$lambda$engineLoad$2$2::fieldInfos[7] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(PKCS12KeyStore$$Lambda$lambda$engineLoad$2$2, inst$)},
	{"m", "Ljavax/crypto/Mac;", nullptr, $PUBLIC, $field(PKCS12KeyStore$$Lambda$lambda$engineLoad$2$2, m)},
	{"params", "Ljavax/crypto/spec/PBEParameterSpec;", nullptr, $PUBLIC, $field(PKCS12KeyStore$$Lambda$lambda$engineLoad$2$2, params)},
	{"authSafeData", "[B", nullptr, $PUBLIC, $field(PKCS12KeyStore$$Lambda$lambda$engineLoad$2$2, authSafeData)},
	{"ic", "I", nullptr, $PUBLIC, $field(PKCS12KeyStore$$Lambda$lambda$engineLoad$2$2, ic)},
	{"macData", "Lsun/security/pkcs12/MacData;", nullptr, $PUBLIC, $field(PKCS12KeyStore$$Lambda$lambda$engineLoad$2$2, macData)},
	{}
};
$MethodInfo PKCS12KeyStore$$Lambda$lambda$engineLoad$2$2::methodInfos[3] = {
	{"<init>", "(Lsun/security/pkcs12/PKCS12KeyStore;Ljavax/crypto/Mac;Ljavax/crypto/spec/PBEParameterSpec;[BILsun/security/pkcs12/MacData;)V", nullptr, $PUBLIC, $method(PKCS12KeyStore$$Lambda$lambda$engineLoad$2$2, init$, void, PKCS12KeyStore*, $Mac*, $PBEParameterSpec*, $bytes*, int32_t, $MacData*)},
	{"tryOnce", "([C)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(PKCS12KeyStore$$Lambda$lambda$engineLoad$2$2, tryOnce, $Object*, $chars*)},
	{}
};
$ClassInfo PKCS12KeyStore$$Lambda$lambda$engineLoad$2$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.security.pkcs12.PKCS12KeyStore$$Lambda$lambda$engineLoad$2$2",
	"java.lang.Object",
	"sun.security.pkcs12.PKCS12KeyStore$RetryWithZero",
	fieldInfos,
	methodInfos
};
$Class* PKCS12KeyStore$$Lambda$lambda$engineLoad$2$2::load$($String* name, bool initialize) {
	$loadClass(PKCS12KeyStore$$Lambda$lambda$engineLoad$2$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* PKCS12KeyStore$$Lambda$lambda$engineLoad$2$2::class$ = nullptr;

$FieldInfo _PKCS12KeyStore_FieldInfo_[] = {
	{"DEFAULT_CERT_PBE_ALGORITHM", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PKCS12KeyStore, DEFAULT_CERT_PBE_ALGORITHM)},
	{"DEFAULT_KEY_PBE_ALGORITHM", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PKCS12KeyStore, DEFAULT_KEY_PBE_ALGORITHM)},
	{"DEFAULT_MAC_ALGORITHM", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PKCS12KeyStore, DEFAULT_MAC_ALGORITHM)},
	{"DEFAULT_CERT_PBE_ITERATION_COUNT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(PKCS12KeyStore, DEFAULT_CERT_PBE_ITERATION_COUNT)},
	{"DEFAULT_KEY_PBE_ITERATION_COUNT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(PKCS12KeyStore, DEFAULT_KEY_PBE_ITERATION_COUNT)},
	{"DEFAULT_MAC_ITERATION_COUNT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(PKCS12KeyStore, DEFAULT_MAC_ITERATION_COUNT)},
	{"LEGACY_CERT_PBE_ALGORITHM", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PKCS12KeyStore, LEGACY_CERT_PBE_ALGORITHM)},
	{"LEGACY_KEY_PBE_ALGORITHM", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PKCS12KeyStore, LEGACY_KEY_PBE_ALGORITHM)},
	{"LEGACY_MAC_ALGORITHM", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PKCS12KeyStore, LEGACY_MAC_ALGORITHM)},
	{"LEGACY_PBE_ITERATION_COUNT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(PKCS12KeyStore, LEGACY_PBE_ITERATION_COUNT)},
	{"LEGACY_MAC_ITERATION_COUNT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(PKCS12KeyStore, LEGACY_MAC_ITERATION_COUNT)},
	{"USE_LEGACY_PROP", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PKCS12KeyStore, USE_LEGACY_PROP)},
	{"VERSION_3", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(PKCS12KeyStore, VERSION_3)},
	{"MAX_ITERATION_COUNT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(PKCS12KeyStore, MAX_ITERATION_COUNT)},
	{"SALT_LEN", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(PKCS12KeyStore, SALT_LEN)},
	{"CORE_ATTRIBUTES", "[Lsun/security/util/KnownOIDs;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PKCS12KeyStore, CORE_ATTRIBUTES)},
	{"debug", "Lsun/security/util/Debug;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PKCS12KeyStore, debug)},
	{"PKCS8ShroudedKeyBag_OID", "Lsun/security/util/ObjectIdentifier;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PKCS12KeyStore, PKCS8ShroudedKeyBag_OID)},
	{"CertBag_OID", "Lsun/security/util/ObjectIdentifier;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PKCS12KeyStore, CertBag_OID)},
	{"SecretBag_OID", "Lsun/security/util/ObjectIdentifier;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PKCS12KeyStore, SecretBag_OID)},
	{"PKCS9FriendlyName_OID", "Lsun/security/util/ObjectIdentifier;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PKCS12KeyStore, PKCS9FriendlyName_OID)},
	{"PKCS9LocalKeyId_OID", "Lsun/security/util/ObjectIdentifier;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PKCS12KeyStore, PKCS9LocalKeyId_OID)},
	{"PKCS9CertType_OID", "Lsun/security/util/ObjectIdentifier;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PKCS12KeyStore, PKCS9CertType_OID)},
	{"pbes2_OID", "Lsun/security/util/ObjectIdentifier;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PKCS12KeyStore, pbes2_OID)},
	{"TrustedKeyUsage_OID", "Lsun/security/util/ObjectIdentifier;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PKCS12KeyStore, TrustedKeyUsage_OID)},
	{"AnyUsage", "[Lsun/security/util/ObjectIdentifier;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PKCS12KeyStore, AnyUsage)},
	{"counter", "I", nullptr, $PRIVATE, $field(PKCS12KeyStore, counter)},
	{"privateKeyCount", "I", nullptr, $PRIVATE, $field(PKCS12KeyStore, privateKeyCount)},
	{"secretKeyCount", "I", nullptr, $PRIVATE, $field(PKCS12KeyStore, secretKeyCount)},
	{"certificateCount", "I", nullptr, $PRIVATE, $field(PKCS12KeyStore, certificateCount)},
	{"certProtectionAlgorithm", "Ljava/lang/String;", nullptr, $PRIVATE, $field(PKCS12KeyStore, certProtectionAlgorithm)},
	{"certPbeIterationCount", "I", nullptr, $PRIVATE, $field(PKCS12KeyStore, certPbeIterationCount)},
	{"macAlgorithm", "Ljava/lang/String;", nullptr, $PRIVATE, $field(PKCS12KeyStore, macAlgorithm)},
	{"macIterationCount", "I", nullptr, $PRIVATE, $field(PKCS12KeyStore, macIterationCount)},
	{"random", "Ljava/security/SecureRandom;", nullptr, $PRIVATE, $field(PKCS12KeyStore, random)},
	{"entries", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Lsun/security/pkcs12/PKCS12KeyStore$Entry;>;", $PRIVATE, $field(PKCS12KeyStore, entries)},
	{"keyList", "Ljava/util/ArrayList;", "Ljava/util/ArrayList<Lsun/security/pkcs12/PKCS12KeyStore$KeyEntry;>;", $PRIVATE, $field(PKCS12KeyStore, keyList)},
	{"allCerts", "Ljava/util/List;", "Ljava/util/List<Ljava/security/cert/X509Certificate;>;", $PRIVATE, $field(PKCS12KeyStore, allCerts)},
	{"certEntries", "Ljava/util/ArrayList;", "Ljava/util/ArrayList<Lsun/security/pkcs12/PKCS12KeyStore$CertEntry;>;", $PRIVATE, $field(PKCS12KeyStore, certEntries)},
	{"PKCS12_HEADER_PATTERNS", "[[J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PKCS12KeyStore, PKCS12_HEADER_PATTERNS)},
	{"PKCS12_HEADER_MASKS", "[[J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PKCS12KeyStore, PKCS12_HEADER_MASKS)},
	{}
};

$MethodInfo _PKCS12KeyStore_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(PKCS12KeyStore, init$, void)},
	{"calculateMac", "([C[B)[B", nullptr, $PRIVATE, $method(PKCS12KeyStore, calculateMac, $bytes*, $chars*, $bytes*), "java.io.IOException"},
	{"checkX509Certs", "([Ljava/security/cert/Certificate;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(PKCS12KeyStore, checkX509Certs, void, $CertificateArray*), "java.security.KeyStoreException"},
	{"createEncryptedData", "([C)[B", nullptr, $PRIVATE, $method(PKCS12KeyStore, createEncryptedData, $bytes*, $chars*), "java.security.cert.CertificateException,java.io.IOException"},
	{"createSafeContent", "()[B", nullptr, $PRIVATE, $method(PKCS12KeyStore, createSafeContent, $bytes*), "java.security.cert.CertificateException,java.io.IOException"},
	{"defaultCertPbeIterationCount", "()I", nullptr, $PRIVATE | $STATIC, $staticMethod(PKCS12KeyStore, defaultCertPbeIterationCount, int32_t)},
	{"defaultCertProtectionAlgorithm", "()Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(PKCS12KeyStore, defaultCertProtectionAlgorithm, $String*)},
	{"defaultKeyPbeIterationCount", "()I", nullptr, $PRIVATE | $STATIC, $staticMethod(PKCS12KeyStore, defaultKeyPbeIterationCount, int32_t)},
	{"defaultKeyProtectionAlgorithm", "()Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(PKCS12KeyStore, defaultKeyProtectionAlgorithm, $String*)},
	{"defaultMacAlgorithm", "()Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(PKCS12KeyStore, defaultMacAlgorithm, $String*)},
	{"defaultMacIterationCount", "()I", nullptr, $PRIVATE | $STATIC, $staticMethod(PKCS12KeyStore, defaultMacIterationCount, int32_t)},
	{"destroyPBEKey", "(Ljavax/crypto/SecretKey;)V", nullptr, $PRIVATE, $method(PKCS12KeyStore, destroyPBEKey, void, $SecretKey*)},
	{"encryptContent", "([B[C)[B", nullptr, $PRIVATE, $method(PKCS12KeyStore, encryptContent, $bytes*, $bytes*, $chars*), "java.io.IOException"},
	{"encryptPrivateKey", "([BLjava/security/KeyStore$PasswordProtection;)[B", nullptr, $PRIVATE, $method(PKCS12KeyStore, encryptPrivateKey, $bytes*, $bytes*, $KeyStore$PasswordProtection*), "java.io.IOException,java.security.NoSuchAlgorithmException,java.security.UnrecoverableKeyException"},
	{"engineAliases", "()Ljava/util/Enumeration;", "()Ljava/util/Enumeration<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(PKCS12KeyStore, engineAliases, $Enumeration*)},
	{"engineContainsAlias", "(Ljava/lang/String;)Z", nullptr, $PUBLIC, $virtualMethod(PKCS12KeyStore, engineContainsAlias, bool, $String*)},
	{"engineDeleteEntry", "(Ljava/lang/String;)V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(PKCS12KeyStore, engineDeleteEntry, void, $String*), "java.security.KeyStoreException"},
	{"engineEntryInstanceOf", "(Ljava/lang/String;Ljava/lang/Class;)Z", "(Ljava/lang/String;Ljava/lang/Class<+Ljava/security/KeyStore$Entry;>;)Z", $PUBLIC, $virtualMethod(PKCS12KeyStore, engineEntryInstanceOf, bool, $String*, $Class*)},
	{"engineGetCertificate", "(Ljava/lang/String;)Ljava/security/cert/Certificate;", nullptr, $PUBLIC, $virtualMethod(PKCS12KeyStore, engineGetCertificate, $Certificate*, $String*)},
	{"engineGetCertificateAlias", "(Ljava/security/cert/Certificate;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(PKCS12KeyStore, engineGetCertificateAlias, $String*, $Certificate*)},
	{"engineGetCertificateChain", "(Ljava/lang/String;)[Ljava/security/cert/Certificate;", nullptr, $PUBLIC, $virtualMethod(PKCS12KeyStore, engineGetCertificateChain, $CertificateArray*, $String*)},
	{"engineGetCreationDate", "(Ljava/lang/String;)Ljava/util/Date;", nullptr, $PUBLIC, $virtualMethod(PKCS12KeyStore, engineGetCreationDate, $Date*, $String*)},
	{"engineGetEntry", "(Ljava/lang/String;Ljava/security/KeyStore$ProtectionParameter;)Ljava/security/KeyStore$Entry;", nullptr, $PUBLIC, $virtualMethod(PKCS12KeyStore, engineGetEntry, $KeyStore$Entry*, $String*, $KeyStore$ProtectionParameter*), "java.security.KeyStoreException,java.security.NoSuchAlgorithmException,java.security.UnrecoverableEntryException"},
	{"engineGetKey", "(Ljava/lang/String;[C)Ljava/security/Key;", nullptr, $PUBLIC, $virtualMethod(PKCS12KeyStore, engineGetKey, $Key*, $String*, $chars*), "java.security.NoSuchAlgorithmException,java.security.UnrecoverableKeyException"},
	{"engineIsCertificateEntry", "(Ljava/lang/String;)Z", nullptr, $PUBLIC, $virtualMethod(PKCS12KeyStore, engineIsCertificateEntry, bool, $String*)},
	{"engineIsKeyEntry", "(Ljava/lang/String;)Z", nullptr, $PUBLIC, $virtualMethod(PKCS12KeyStore, engineIsKeyEntry, bool, $String*)},
	{"engineLoad", "(Ljava/io/InputStream;[C)V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(PKCS12KeyStore, engineLoad, void, $InputStream*, $chars*), "java.io.IOException,java.security.NoSuchAlgorithmException,java.security.cert.CertificateException"},
	{"engineProbe", "(Ljava/io/InputStream;)Z", nullptr, $PUBLIC, $virtualMethod(PKCS12KeyStore, engineProbe, bool, $InputStream*), "java.io.IOException"},
	{"engineSetCertificateEntry", "(Ljava/lang/String;Ljava/security/cert/Certificate;)V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(PKCS12KeyStore, engineSetCertificateEntry, void, $String*, $Certificate*), "java.security.KeyStoreException"},
	{"engineSetEntry", "(Ljava/lang/String;Ljava/security/KeyStore$Entry;Ljava/security/KeyStore$ProtectionParameter;)V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(PKCS12KeyStore, engineSetEntry, void, $String*, $KeyStore$Entry*, $KeyStore$ProtectionParameter*), "java.security.KeyStoreException"},
	{"engineSetKeyEntry", "(Ljava/lang/String;Ljava/security/Key;[C[Ljava/security/cert/Certificate;)V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(PKCS12KeyStore, engineSetKeyEntry, void, $String*, $Key*, $chars*, $CertificateArray*), "java.security.KeyStoreException"},
	{"engineSetKeyEntry", "(Ljava/lang/String;[B[Ljava/security/cert/Certificate;)V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(PKCS12KeyStore, engineSetKeyEntry, void, $String*, $bytes*, $CertificateArray*), "java.security.KeyStoreException"},
	{"engineSize", "()I", nullptr, $PUBLIC, $virtualMethod(PKCS12KeyStore, engineSize, int32_t)},
	{"engineStore", "(Ljava/io/OutputStream;[C)V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(PKCS12KeyStore, engineStore, void, $OutputStream*, $chars*), "java.io.IOException,java.security.NoSuchAlgorithmException,java.security.cert.CertificateException"},
	{"findIssuer", "(Ljava/security/cert/X509Certificate;)Ljava/security/cert/X509Certificate;", nullptr, $PRIVATE, $method(PKCS12KeyStore, findIssuer, $X509Certificate*, $X509Certificate*)},
	{"findMatchedCertificate", "(Lsun/security/pkcs12/PKCS12KeyStore$PrivateKeyEntry;)Ljava/security/cert/X509Certificate;", nullptr, $PRIVATE, $method(PKCS12KeyStore, findMatchedCertificate, $X509Certificate*, $PKCS12KeyStore$PrivateKeyEntry*)},
	{"getAttributes", "(Lsun/security/pkcs12/PKCS12KeyStore$Entry;)Ljava/util/Set;", "(Lsun/security/pkcs12/PKCS12KeyStore$Entry;)Ljava/util/Set<Ljava/security/KeyStore$Entry$Attribute;>;", $PRIVATE, $method(PKCS12KeyStore, getAttributes, $Set*, $PKCS12KeyStore$Entry*)},
	{"getBagAttributes", "(Ljava/lang/String;[BLjava/util/Set;)[B", "(Ljava/lang/String;[BLjava/util/Set<Ljava/security/KeyStore$Entry$Attribute;>;)[B", $PRIVATE, $method(PKCS12KeyStore, getBagAttributes, $bytes*, $String*, $bytes*, $Set*), "java.io.IOException"},
	{"getBagAttributes", "(Ljava/lang/String;[B[Lsun/security/util/ObjectIdentifier;Ljava/util/Set;)[B", "(Ljava/lang/String;[B[Lsun/security/util/ObjectIdentifier;Ljava/util/Set<Ljava/security/KeyStore$Entry$Attribute;>;)[B", $PRIVATE, $method(PKCS12KeyStore, getBagAttributes, $bytes*, $String*, $bytes*, $ObjectIdentifierArray*, $Set*), "java.io.IOException"},
	{"getPBEAlgorithmParameters", "(Ljava/lang/String;I)Ljava/security/AlgorithmParameters;", nullptr, $PRIVATE, $method(PKCS12KeyStore, getPBEAlgorithmParameters, $AlgorithmParameters*, $String*, int32_t), "java.io.IOException"},
	{"getPBEKey", "([C)Ljavax/crypto/SecretKey;", nullptr, $PRIVATE, $method(PKCS12KeyStore, getPBEKey, $SecretKey*, $chars*), "java.io.IOException"},
	{"getSalt", "()[B", nullptr, $PRIVATE, $method(PKCS12KeyStore, getSalt, $bytes*)},
	{"getUnfriendlyName", "()Ljava/lang/String;", nullptr, $PRIVATE, $method(PKCS12KeyStore, getUnfriendlyName, $String*)},
	{"isPasswordless", "(Ljava/io/File;)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(PKCS12KeyStore, isPasswordless, bool, $File*), "java.io.IOException"},
	{"lambda$engineGetKey$0", "(Lsun/security/util/ObjectIdentifier;Ljava/security/AlgorithmParameters;[BLsun/security/pkcs12/PKCS12KeyStore$Entry;Ljava/lang/String;I[C)Ljava/security/Key;", nullptr, $PRIVATE | $SYNTHETIC, $method(PKCS12KeyStore, lambda$engineGetKey$0, $Key*, $ObjectIdentifier*, $AlgorithmParameters*, $bytes*, $PKCS12KeyStore$Entry*, $String*, int32_t, $chars*), "java.lang.Exception"},
	{"lambda$engineLoad$1", "(Lsun/security/util/ObjectIdentifier;Ljava/security/AlgorithmParameters;[B[C)Ljava/lang/Object;", nullptr, $PRIVATE | $SYNTHETIC, $method(PKCS12KeyStore, lambda$engineLoad$1, $Object*, $ObjectIdentifier*, $AlgorithmParameters*, $bytes*, $chars*), "java.lang.Exception"},
	{"lambda$engineLoad$2", "(Ljavax/crypto/Mac;Ljavax/crypto/spec/PBEParameterSpec;[BILsun/security/pkcs12/MacData;[C)Ljava/lang/Void;", nullptr, $PRIVATE | $SYNTHETIC, $method(PKCS12KeyStore, lambda$engineLoad$2, $Void*, $Mac*, $PBEParameterSpec*, $bytes*, int32_t, $MacData*, $chars*), "java.lang.Exception"},
	{"loadSafeContents", "(Lsun/security/util/DerInputStream;)V", nullptr, $PRIVATE, $method(PKCS12KeyStore, loadSafeContents, void, $DerInputStream*), "java.io.IOException,java.security.NoSuchAlgorithmException,java.security.cert.CertificateException"},
	{"mapPBEAlgorithmToOID", "(Ljava/lang/String;)Lsun/security/util/ObjectIdentifier;", nullptr, $PRIVATE | $STATIC, $staticMethod(PKCS12KeyStore, mapPBEAlgorithmToOID, $ObjectIdentifier*, $String*), "java.security.NoSuchAlgorithmException"},
	{"mapPBEParamsToAlgorithm", "(Lsun/security/util/ObjectIdentifier;Ljava/security/AlgorithmParameters;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(PKCS12KeyStore, mapPBEParamsToAlgorithm, $String*, $ObjectIdentifier*, $AlgorithmParameters*), "java.security.NoSuchAlgorithmException"},
	{"parseAlgParameters", "(Lsun/security/util/ObjectIdentifier;Lsun/security/util/DerInputStream;)Ljava/security/AlgorithmParameters;", nullptr, $PRIVATE, $method(PKCS12KeyStore, parseAlgParameters, $AlgorithmParameters*, $ObjectIdentifier*, $DerInputStream*), "java.io.IOException"},
	{"setCertEntry", "(Ljava/lang/String;Ljava/security/cert/Certificate;Ljava/util/Set;)V", "(Ljava/lang/String;Ljava/security/cert/Certificate;Ljava/util/Set<Ljava/security/KeyStore$Entry$Attribute;>;)V", $PRIVATE, $method(PKCS12KeyStore, setCertEntry, void, $String*, $Certificate*, $Set*), "java.security.KeyStoreException"},
	{"setKeyEntry", "(Ljava/lang/String;Ljava/security/Key;Ljava/security/KeyStore$PasswordProtection;[Ljava/security/cert/Certificate;Ljava/util/Set;)V", "(Ljava/lang/String;Ljava/security/Key;Ljava/security/KeyStore$PasswordProtection;[Ljava/security/cert/Certificate;Ljava/util/Set<Ljava/security/KeyStore$Entry$Attribute;>;)V", $PRIVATE, $method(PKCS12KeyStore, setKeyEntry, void, $String*, $Key*, $KeyStore$PasswordProtection*, $CertificateArray*, $Set*), "java.security.KeyStoreException"},
	{"string2IC", "(Ljava/lang/String;Ljava/lang/String;)I", nullptr, $PRIVATE | $STATIC, $staticMethod(PKCS12KeyStore, string2IC, int32_t, $String*, $String*)},
	{"useLegacy", "()Z", nullptr, $PRIVATE | $STATIC, $staticMethod(PKCS12KeyStore, useLegacy, bool)},
	{"validateChain", "([Ljava/security/cert/Certificate;)Z", nullptr, $PRIVATE, $method(PKCS12KeyStore, validateChain, bool, $CertificateArray*)},
	{}
};

$InnerClassInfo _PKCS12KeyStore_InnerClassesInfo_[] = {
	{"sun.security.pkcs12.PKCS12KeyStore$RetryWithZero", "sun.security.pkcs12.PKCS12KeyStore", "RetryWithZero", $PRIVATE | $STATIC | $INTERFACE | $ABSTRACT},
	{"sun.security.pkcs12.PKCS12KeyStore$CertEntry", "sun.security.pkcs12.PKCS12KeyStore", "CertEntry", $PRIVATE | $STATIC},
	{"sun.security.pkcs12.PKCS12KeyStore$SecretKeyEntry", "sun.security.pkcs12.PKCS12KeyStore", "SecretKeyEntry", $PRIVATE | $STATIC},
	{"sun.security.pkcs12.PKCS12KeyStore$PrivateKeyEntry", "sun.security.pkcs12.PKCS12KeyStore", "PrivateKeyEntry", $PRIVATE | $STATIC},
	{"sun.security.pkcs12.PKCS12KeyStore$KeyEntry", "sun.security.pkcs12.PKCS12KeyStore", "KeyEntry", $PRIVATE | $STATIC},
	{"sun.security.pkcs12.PKCS12KeyStore$Entry", "sun.security.pkcs12.PKCS12KeyStore", "Entry", $PRIVATE | $STATIC},
	{"sun.security.pkcs12.PKCS12KeyStore$DualFormatPKCS12", "sun.security.pkcs12.PKCS12KeyStore", "DualFormatPKCS12", $PUBLIC | $STATIC | $FINAL},
	{"sun.security.pkcs12.PKCS12KeyStore$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _PKCS12KeyStore_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.pkcs12.PKCS12KeyStore",
	"java.security.KeyStoreSpi",
	nullptr,
	_PKCS12KeyStore_FieldInfo_,
	_PKCS12KeyStore_MethodInfo_,
	nullptr,
	nullptr,
	_PKCS12KeyStore_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.pkcs12.PKCS12KeyStore$RetryWithZero,sun.security.pkcs12.PKCS12KeyStore$CertEntry,sun.security.pkcs12.PKCS12KeyStore$SecretKeyEntry,sun.security.pkcs12.PKCS12KeyStore$PrivateKeyEntry,sun.security.pkcs12.PKCS12KeyStore$KeyEntry,sun.security.pkcs12.PKCS12KeyStore$Entry,sun.security.pkcs12.PKCS12KeyStore$DualFormatPKCS12,sun.security.pkcs12.PKCS12KeyStore$1"
};

$Object* allocate$PKCS12KeyStore($Class* clazz) {
	return $of($alloc(PKCS12KeyStore));
}

$String* PKCS12KeyStore::DEFAULT_CERT_PBE_ALGORITHM = nullptr;
$String* PKCS12KeyStore::DEFAULT_KEY_PBE_ALGORITHM = nullptr;
$String* PKCS12KeyStore::DEFAULT_MAC_ALGORITHM = nullptr;
$String* PKCS12KeyStore::LEGACY_CERT_PBE_ALGORITHM = nullptr;
$String* PKCS12KeyStore::LEGACY_KEY_PBE_ALGORITHM = nullptr;
$String* PKCS12KeyStore::LEGACY_MAC_ALGORITHM = nullptr;
$String* PKCS12KeyStore::USE_LEGACY_PROP = nullptr;
$KnownOIDsArray* PKCS12KeyStore::CORE_ATTRIBUTES = nullptr;
$Debug* PKCS12KeyStore::debug = nullptr;
$ObjectIdentifier* PKCS12KeyStore::PKCS8ShroudedKeyBag_OID = nullptr;
$ObjectIdentifier* PKCS12KeyStore::CertBag_OID = nullptr;
$ObjectIdentifier* PKCS12KeyStore::SecretBag_OID = nullptr;
$ObjectIdentifier* PKCS12KeyStore::PKCS9FriendlyName_OID = nullptr;
$ObjectIdentifier* PKCS12KeyStore::PKCS9LocalKeyId_OID = nullptr;
$ObjectIdentifier* PKCS12KeyStore::PKCS9CertType_OID = nullptr;
$ObjectIdentifier* PKCS12KeyStore::pbes2_OID = nullptr;
$ObjectIdentifier* PKCS12KeyStore::TrustedKeyUsage_OID = nullptr;
$ObjectIdentifierArray* PKCS12KeyStore::AnyUsage = nullptr;
$longArray2* PKCS12KeyStore::PKCS12_HEADER_PATTERNS = nullptr;
$longArray2* PKCS12KeyStore::PKCS12_HEADER_MASKS = nullptr;

void PKCS12KeyStore::init$() {
	$KeyStoreSpi::init$();
	this->counter = 0;
	this->privateKeyCount = 0;
	this->secretKeyCount = 0;
	this->certificateCount = 0;
	$set(this, certProtectionAlgorithm, nullptr);
	this->certPbeIterationCount = -1;
	$set(this, macAlgorithm, nullptr);
	this->macIterationCount = -1;
	$set(this, entries, $Collections::synchronizedMap($$new($LinkedHashMap)));
	$set(this, keyList, $new($ArrayList));
	$set(this, allCerts, $new($ArrayList));
	$set(this, certEntries, $new($ArrayList));
}

$Key* PKCS12KeyStore::engineGetKey($String* alias, $chars* password) {
	$useLocalCurrentObjectStackCache();
	$init($Locale);
	$var($PKCS12KeyStore$Entry, entry, $cast($PKCS12KeyStore$Entry, $nc(this->entries)->get($($nc(alias)->toLowerCase($Locale::ENGLISH)))));
	$var($Key, key, nullptr);
	if (entry == nullptr || (!($instanceOf($PKCS12KeyStore$KeyEntry, entry)))) {
		return nullptr;
	}
	$var($bytes, encrBytes, nullptr);
	if ($instanceOf($PKCS12KeyStore$PrivateKeyEntry, entry)) {
		$assign(encrBytes, $nc(($cast($PKCS12KeyStore$PrivateKeyEntry, entry)))->protectedPrivKey);
	} else if ($instanceOf($PKCS12KeyStore$SecretKeyEntry, entry)) {
		$assign(encrBytes, $nc(($cast($PKCS12KeyStore$SecretKeyEntry, entry)))->protectedSecretKey);
	} else {
		$throwNew($UnrecoverableKeyException, "Error locating key"_s);
	}
	$var($bytes, encryptedKey, nullptr);
	$var($AlgorithmParameters, algParams, nullptr);
	$var($ObjectIdentifier, algOid, nullptr);
	try {
		$var($EncryptedPrivateKeyInfo, encrInfo, $new($EncryptedPrivateKeyInfo, encrBytes));
		$assign(encryptedKey, encrInfo->getEncryptedData());
		$var($DerValue, val, $new($DerValue, $($nc($(encrInfo->getAlgorithm()))->encode())));
		$var($DerInputStream, in, val->toDerInputStream());
		$assign(algOid, $nc(in)->getOID());
		$assign(algParams, parseAlgParameters(algOid, in));
	} catch ($IOException& ioe) {
		$var($UnrecoverableKeyException, uke, $new($UnrecoverableKeyException, $$str({"Private key not stored as PKCS#8 EncryptedPrivateKeyInfo: "_s, ioe})));
		uke->initCause(ioe);
		$throw(uke);
	}
	try {
		$var($PBEParameterSpec, pbeSpec, nullptr);
		int32_t ic = 0;
		if (algParams != nullptr) {
			try {
				$load($PBEParameterSpec);
				$assign(pbeSpec, $cast($PBEParameterSpec, algParams->getParameterSpec($PBEParameterSpec::class$)));
			} catch ($InvalidParameterSpecException& ipse) {
				$throwNew($IOException, "Invalid PBE algorithm parameters"_s);
			}
			ic = $nc(pbeSpec)->getIterationCount();
			if (ic > PKCS12KeyStore::MAX_ITERATION_COUNT) {
				$throwNew($IOException, "key PBE iteration count too large"_s);
			}
		} else {
			ic = 0;
		}
		$assign(key, $cast($Key, $PKCS12KeyStore$RetryWithZero::run(static_cast<$PKCS12KeyStore$RetryWithZero*>($$new(PKCS12KeyStore$$Lambda$lambda$engineGetKey$0, this, algOid, algParams, encryptedKey, entry, alias, ic)), password)));
	} catch ($Exception& e) {
		$var($UnrecoverableKeyException, uke, $new($UnrecoverableKeyException, $$str({"Get Key failed: "_s, $(e->getMessage())})));
		uke->initCause(e);
		$throw(uke);
	}
	return key;
}

$CertificateArray* PKCS12KeyStore::engineGetCertificateChain($String* alias) {
	$useLocalCurrentObjectStackCache();
	$init($Locale);
	$var($PKCS12KeyStore$Entry, entry, $cast($PKCS12KeyStore$Entry, $nc(this->entries)->get($($nc(alias)->toLowerCase($Locale::ENGLISH)))));
	if (entry != nullptr && $instanceOf($PKCS12KeyStore$PrivateKeyEntry, entry)) {
		if ($nc(($cast($PKCS12KeyStore$PrivateKeyEntry, entry)))->chain == nullptr) {
			return nullptr;
		} else {
			if (PKCS12KeyStore::debug != nullptr) {
				$nc(PKCS12KeyStore::debug)->println($$str({"Retrieved a "_s, $$str($nc($nc(($cast($PKCS12KeyStore$PrivateKeyEntry, entry)))->chain)->length), "-certificate chain at alias \'"_s, alias, "\'"_s}));
			}
			return $cast($CertificateArray, $nc($nc(($cast($PKCS12KeyStore$PrivateKeyEntry, entry)))->chain)->clone());
		}
	} else {
		return nullptr;
	}
}

$Certificate* PKCS12KeyStore::engineGetCertificate($String* alias) {
	$useLocalCurrentObjectStackCache();
	$init($Locale);
	$var($PKCS12KeyStore$Entry, entry, $cast($PKCS12KeyStore$Entry, $nc(this->entries)->get($($nc(alias)->toLowerCase($Locale::ENGLISH)))));
	if (entry == nullptr) {
		return nullptr;
	}
	if ($instanceOf($PKCS12KeyStore$CertEntry, entry) && $nc(($cast($PKCS12KeyStore$CertEntry, entry)))->trustedKeyUsage != nullptr) {
		if (PKCS12KeyStore::debug != nullptr) {
			if ($Arrays::equals(PKCS12KeyStore::AnyUsage, $nc(($cast($PKCS12KeyStore$CertEntry, entry)))->trustedKeyUsage)) {
				$nc(PKCS12KeyStore::debug)->println($$str({"Retrieved a certificate at alias \'"_s, alias, "\' (trusted for any purpose)"_s}));
			} else {
				$nc(PKCS12KeyStore::debug)->println($$str({"Retrieved a certificate at alias \'"_s, alias, "\' (trusted for limited purposes)"_s}));
			}
		}
		return $nc(($cast($PKCS12KeyStore$CertEntry, entry)))->cert;
	} else if ($instanceOf($PKCS12KeyStore$PrivateKeyEntry, entry)) {
		if ($nc(($cast($PKCS12KeyStore$PrivateKeyEntry, entry)))->chain == nullptr) {
			return nullptr;
		} else {
			if (PKCS12KeyStore::debug != nullptr) {
				$nc(PKCS12KeyStore::debug)->println($$str({"Retrieved a certificate at alias \'"_s, alias, "\'"_s}));
			}
			return $nc($nc(($cast($PKCS12KeyStore$PrivateKeyEntry, entry)))->chain)->get(0);
		}
	} else {
		return nullptr;
	}
}

$Date* PKCS12KeyStore::engineGetCreationDate($String* alias) {
	$useLocalCurrentObjectStackCache();
	$init($Locale);
	$var($PKCS12KeyStore$Entry, entry, $cast($PKCS12KeyStore$Entry, $nc(this->entries)->get($($nc(alias)->toLowerCase($Locale::ENGLISH)))));
	if (entry != nullptr) {
		return $new($Date, $nc(entry->date)->getTime());
	} else {
		return nullptr;
	}
}

void PKCS12KeyStore::engineSetKeyEntry($String* alias, $Key* key, $chars* password, $CertificateArray* chain) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$var($KeyStore$PasswordProtection, passwordProtection, $new($KeyStore$PasswordProtection, password));
		{
			$var($Throwable, var$0, nullptr);
			try {
				setKeyEntry(alias, key, passwordProtection, chain, nullptr);
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				try {
					passwordProtection->destroy();
				} catch ($DestroyFailedException& dfe) {
				}
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
}

void PKCS12KeyStore::setKeyEntry($String* alias, $Key* key, $KeyStore$PasswordProtection* passwordProtection, $CertificateArray* chain, $Set* attributes) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($PKCS12KeyStore$Entry, entry, nullptr);
		if ($instanceOf($PrivateKey, key)) {
			checkX509Certs(chain);
			$var($PKCS12KeyStore$PrivateKeyEntry, keyEntry, $new($PKCS12KeyStore$PrivateKeyEntry));
			$set(keyEntry, date, $new($Date));
			bool var$0 = ($nc($($nc(key)->getFormat()))->equals("PKCS#8"_s));
			if (var$0 || ($nc($($nc(key)->getFormat()))->equals("PKCS8"_s))) {
				if (PKCS12KeyStore::debug != nullptr) {
					$nc(PKCS12KeyStore::debug)->println($$str({"Setting a protected private key at alias \'"_s, alias, "\'"_s}));
				}
				$var($bytes, encoded, key->getEncoded());
				{
					$var($Throwable, var$1, nullptr);
					try {
						$set(keyEntry, protectedPrivKey, encryptPrivateKey(encoded, passwordProtection));
					} catch ($Throwable& var$2) {
						$assign(var$1, var$2);
					} /*finally*/ {
						if (encoded != nullptr) {
							$Arrays::fill(encoded, (int8_t)0);
						}
					}
					if (var$1 != nullptr) {
						$throw(var$1);
					}
				}
			} else {
				$throwNew($KeyStoreException, "Private key is not encodedas PKCS#8"_s);
			}
			if (chain != nullptr) {
				if ((chain->length > 1) && (!validateChain(chain))) {
					$throwNew($KeyStoreException, "Certificate chain is not valid"_s);
				}
				$set(keyEntry, chain, $cast($CertificateArray, chain->clone()));
				this->certificateCount += chain->length;
				if (PKCS12KeyStore::debug != nullptr) {
					$nc(PKCS12KeyStore::debug)->println($$str({"Setting a "_s, $$str(chain->length), "-certificate chain at alias \'"_s, alias, "\'"_s}));
				}
			}
			++this->privateKeyCount;
			$assign(entry, keyEntry);
		} else if ($instanceOf($SecretKey, key)) {
			$var($PKCS12KeyStore$SecretKeyEntry, keyEntry, $new($PKCS12KeyStore$SecretKeyEntry));
			$set(keyEntry, date, $new($Date));
			$var($DerOutputStream, secretKeyInfo, $new($DerOutputStream));
			secretKeyInfo->putInteger(0);
			$var($AlgorithmId, algId, $AlgorithmId::get($($nc(key)->getAlgorithm())));
			$nc(algId)->encode(secretKeyInfo);
			$var($bytes, encoded, $nc(key)->getEncoded());
			secretKeyInfo->putOctetString(encoded);
			$Arrays::fill(encoded, (int8_t)0);
			$var($DerValue, pkcs8, $DerValue::wrap($DerValue::tag_Sequence, secretKeyInfo));
			$var($bytes, p8Array, $nc(pkcs8)->toByteArray());
			pkcs8->clear();
			{
				$var($Throwable, var$3, nullptr);
				try {
					$set(keyEntry, protectedSecretKey, encryptPrivateKey(p8Array, passwordProtection));
				} catch ($Throwable& var$4) {
					$assign(var$3, var$4);
				} /*finally*/ {
					$Arrays::fill(p8Array, (int8_t)0);
				}
				if (var$3 != nullptr) {
					$throw(var$3);
				}
			}
			if (PKCS12KeyStore::debug != nullptr) {
				$nc(PKCS12KeyStore::debug)->println($$str({"Setting a protected secret key at alias \'"_s, alias, "\'"_s}));
			}
			++this->secretKeyCount;
			$assign(entry, keyEntry);
		} else {
			$throwNew($KeyStoreException, "Unsupported Key type"_s);
		}
		$set($nc(entry), attributes, $new($HashSet));
		if (attributes != nullptr) {
			$nc(entry->attributes)->addAll(attributes);
		}
		$init($StandardCharsets);
		$set(entry, keyId, $nc(($$str({"Time "_s, $$str($nc((entry->date))->getTime())})))->getBytes($StandardCharsets::UTF_8));
		$init($Locale);
		$set(entry, alias, $nc(alias)->toLowerCase($Locale::ENGLISH));
		$nc(this->entries)->put($(alias->toLowerCase($Locale::ENGLISH)), entry);
	} catch ($KeyStoreException& kse) {
		$throw(kse);
	} catch ($Exception& nsae) {
		$throwNew($KeyStoreException, $$str({"Key protection algorithm not found: "_s, nsae}), nsae);
	}
}

void PKCS12KeyStore::engineSetKeyEntry($String* alias, $bytes* key, $CertificateArray* chain) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		checkX509Certs(chain);
		try {
			$new($EncryptedPrivateKeyInfo, key);
		} catch ($IOException& ioe) {
			$throwNew($KeyStoreException, $$str({"Private key is not stored as PKCS#8 EncryptedPrivateKeyInfo: "_s, ioe}), ioe);
		}
		$var($PKCS12KeyStore$PrivateKeyEntry, entry, $new($PKCS12KeyStore$PrivateKeyEntry));
		$set(entry, date, $new($Date));
		if (PKCS12KeyStore::debug != nullptr) {
			$nc(PKCS12KeyStore::debug)->println($$str({"Setting a protected private key at alias \'"_s, alias, "\'"_s}));
		}
		$init($StandardCharsets);
		$set(entry, keyId, $nc(($$str({"Time "_s, $$str($nc((entry->date))->getTime())})))->getBytes($StandardCharsets::UTF_8));
		$init($Locale);
		$set(entry, alias, $nc(alias)->toLowerCase($Locale::ENGLISH));
		$set(entry, protectedPrivKey, $cast($bytes, $nc(key)->clone()));
		if (chain != nullptr) {
			if ((chain->length > 1) && (!validateChain(chain))) {
				$throwNew($KeyStoreException, "Certificate chain is not valid"_s);
			}
			$set(entry, chain, $cast($CertificateArray, chain->clone()));
			this->certificateCount += chain->length;
			if (PKCS12KeyStore::debug != nullptr) {
				$nc(PKCS12KeyStore::debug)->println($$str({"Setting a "_s, $$str($nc(entry->chain)->length), "-certificate chain at alias \'"_s, alias, "\'"_s}));
			}
		}
		++this->privateKeyCount;
		$nc(this->entries)->put($(alias->toLowerCase($Locale::ENGLISH)), entry);
	}
}

$bytes* PKCS12KeyStore::getSalt() {
	$var($bytes, salt, $new($bytes, PKCS12KeyStore::SALT_LEN));
	if (this->random == nullptr) {
		$set(this, random, $new($SecureRandom));
	}
	$nc(this->random)->nextBytes(salt);
	return salt;
}

$AlgorithmParameters* PKCS12KeyStore::getPBEAlgorithmParameters($String* algorithm, int32_t iterationCount) {
	$useLocalCurrentObjectStackCache();
	$var($AlgorithmParameters, algParams, nullptr);
	$var($bytes, salt, getSalt());
	$init($KnownOIDs);
	if ($KnownOIDs::findMatch(algorithm) == $KnownOIDs::PBEWithMD5AndDES) {
		$assign(salt, $Arrays::copyOf(salt, 8));
	}
	$var($PBEParameterSpec, paramSpec, $new($PBEParameterSpec, salt, iterationCount));
	try {
		$assign(algParams, $AlgorithmParameters::getInstance(algorithm));
		$nc(algParams)->init(static_cast<$AlgorithmParameterSpec*>(paramSpec));
	} catch ($Exception& e) {
		$throwNew($IOException, $$str({"getPBEAlgorithmParameters failed: "_s, $(e->getMessage())}), e);
	}
	return algParams;
}

$AlgorithmParameters* PKCS12KeyStore::parseAlgParameters($ObjectIdentifier* algorithm, $DerInputStream* in) {
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
			if ($nc(algorithm)->equals(PKCS12KeyStore::pbes2_OID)) {
				$assign(algParams, $AlgorithmParameters::getInstance("PBES2"_s));
			} else {
				$assign(algParams, $AlgorithmParameters::getInstance("PBE"_s));
			}
			$nc(algParams)->init($(params->toByteArray()));
		}
	} catch ($Exception& e) {
		$throwNew($IOException, $$str({"parseAlgParameters failed: "_s, $(e->getMessage())}), e);
	}
	return algParams;
}

$SecretKey* PKCS12KeyStore::getPBEKey($chars* password) {
	$useLocalCurrentObjectStackCache();
	$var($SecretKey, skey, nullptr);
	try {
		$var($PBEKeySpec, keySpec, $new($PBEKeySpec, password));
		$var($SecretKeyFactory, skFac, $SecretKeyFactory::getInstance("PBE"_s));
		$assign(skey, $nc(skFac)->generateSecret(keySpec));
		keySpec->clearPassword();
	} catch ($Exception& e) {
		$throwNew($IOException, $$str({"getSecretKey failed: "_s, $(e->getMessage())}), e);
	}
	return skey;
}

void PKCS12KeyStore::destroyPBEKey($SecretKey* key) {
	try {
		$nc(key)->destroy();
	} catch ($DestroyFailedException& e) {
	}
}

$bytes* PKCS12KeyStore::encryptPrivateKey($bytes* data, $KeyStore$PasswordProtection* passwordProtection) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, key, nullptr);
	try {
		$var($String, algorithm, nullptr);
		$var($AlgorithmParameters, algParams, nullptr);
		$var($AlgorithmId, algid, nullptr);
		$assign(algorithm, $nc(passwordProtection)->getProtectionAlgorithm());
		if (algorithm != nullptr) {
			$var($AlgorithmParameterSpec, algParamSpec, passwordProtection->getProtectionParameters());
			if (algParamSpec != nullptr) {
				$assign(algParams, $AlgorithmParameters::getInstance(algorithm));
				$nc(algParams)->init(algParamSpec);
			} else {
				$assign(algParams, getPBEAlgorithmParameters(algorithm, defaultKeyPbeIterationCount()));
			}
		} else {
			$assign(algorithm, defaultKeyProtectionAlgorithm());
			$assign(algParams, getPBEAlgorithmParameters(algorithm, defaultKeyPbeIterationCount()));
		}
		$var($ObjectIdentifier, pbeOID, mapPBEAlgorithmToOID(algorithm));
		if (pbeOID == nullptr) {
			$throwNew($IOException, $$str({"PBE algorithm \'"_s, algorithm, " \'is not supported for key entry protection"_s}));
		}
		$var($Cipher, cipher, $Cipher::getInstance(algorithm));
		$var($SecretKey, skey, getPBEKey($(passwordProtection->getPassword())));
		{
			$var($Throwable, var$0, nullptr);
			try {
				$nc(cipher)->init($Cipher::ENCRYPT_MODE, static_cast<$Key*>(skey), algParams);
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				destroyPBEKey(skey);
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
		$var($bytes, encryptedKey, $nc(cipher)->doFinal(data));
		$assign(algid, $new($AlgorithmId, pbeOID, $(cipher->getParameters())));
		if (PKCS12KeyStore::debug != nullptr) {
			$nc(PKCS12KeyStore::debug)->println($$str({"  (Cipher algorithm: "_s, $(cipher->getAlgorithm()), ")"_s}));
		}
		$var($EncryptedPrivateKeyInfo, encrInfo, $new($EncryptedPrivateKeyInfo, algid, encryptedKey));
		$assign(key, encrInfo->getEncoded());
	} catch ($Exception& e) {
		$var($UnrecoverableKeyException, uke, $new($UnrecoverableKeyException, $$str({"Encrypt Private Key failed: "_s, $(e->getMessage())})));
		uke->initCause(e);
		$throw(uke);
	}
	return key;
}

$ObjectIdentifier* PKCS12KeyStore::mapPBEAlgorithmToOID($String* algorithm) {
	$init(PKCS12KeyStore);
	$useLocalCurrentObjectStackCache();
	$init($Locale);
	if ($($nc(algorithm)->toLowerCase($Locale::ENGLISH))->startsWith("pbewithhmacsha"_s)) {
		return PKCS12KeyStore::pbes2_OID;
	}
	return $nc($($AlgorithmId::get(algorithm)))->getOID();
}

$String* PKCS12KeyStore::mapPBEParamsToAlgorithm($ObjectIdentifier* algorithm, $AlgorithmParameters* algParams) {
	$init(PKCS12KeyStore);
	if ($nc(algorithm)->equals(PKCS12KeyStore::pbes2_OID) && algParams != nullptr) {
		return algParams->toString();
	}
	return $$new($AlgorithmId, algorithm)->getName();
}

void PKCS12KeyStore::engineSetCertificateEntry($String* alias, $Certificate* cert) {
	$synchronized(this) {
		setCertEntry(alias, cert, nullptr);
	}
}

void PKCS12KeyStore::setCertEntry($String* alias, $Certificate* cert, $Set* attributes) {
	$useLocalCurrentObjectStackCache();
	if (cert != nullptr && (!($instanceOf($X509Certificate, cert)))) {
		$throwNew($KeyStoreException, $$str({"Only X.509 certificates are supported - rejecting class: "_s, $($of(cert)->getClass()->getName())}));
	}
	$init($Locale);
	$var($PKCS12KeyStore$Entry, entry, $cast($PKCS12KeyStore$Entry, $nc(this->entries)->get($($nc(alias)->toLowerCase($Locale::ENGLISH)))));
	if (entry != nullptr && $instanceOf($PKCS12KeyStore$KeyEntry, entry)) {
		$throwNew($KeyStoreException, "Cannot overwrite own certificate"_s);
	}
	$var($PKCS12KeyStore$CertEntry, certEntry, $new($PKCS12KeyStore$CertEntry, $cast($X509Certificate, cert), nullptr, alias, PKCS12KeyStore::AnyUsage, attributes));
	++this->certificateCount;
	$nc(this->entries)->put($($nc(alias)->toLowerCase($Locale::ENGLISH)), certEntry);
	if (PKCS12KeyStore::debug != nullptr) {
		$nc(PKCS12KeyStore::debug)->println($$str({"Setting a trusted certificate at alias \'"_s, alias, "\'"_s}));
	}
}

void PKCS12KeyStore::engineDeleteEntry($String* alias) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (PKCS12KeyStore::debug != nullptr) {
			$nc(PKCS12KeyStore::debug)->println($$str({"Removing entry at alias \'"_s, alias, "\'"_s}));
		}
		$init($Locale);
		$var($PKCS12KeyStore$Entry, entry, $cast($PKCS12KeyStore$Entry, $nc(this->entries)->get($($nc(alias)->toLowerCase($Locale::ENGLISH)))));
		if ($instanceOf($PKCS12KeyStore$PrivateKeyEntry, entry)) {
			$var($PKCS12KeyStore$PrivateKeyEntry, keyEntry, $cast($PKCS12KeyStore$PrivateKeyEntry, entry));
			if ($nc(keyEntry)->chain != nullptr) {
				this->certificateCount -= $nc(keyEntry->chain)->length;
			}
			--this->privateKeyCount;
		} else if ($instanceOf($PKCS12KeyStore$CertEntry, entry)) {
			--this->certificateCount;
		} else if ($instanceOf($PKCS12KeyStore$SecretKeyEntry, entry)) {
			--this->secretKeyCount;
		}
		$nc(this->entries)->remove($($nc(alias)->toLowerCase($Locale::ENGLISH)));
	}
}

$Enumeration* PKCS12KeyStore::engineAliases() {
	return $Collections::enumeration($($nc(this->entries)->keySet()));
}

bool PKCS12KeyStore::engineContainsAlias($String* alias) {
	$init($Locale);
	return $nc(this->entries)->containsKey($($nc(alias)->toLowerCase($Locale::ENGLISH)));
}

int32_t PKCS12KeyStore::engineSize() {
	return $nc(this->entries)->size();
}

bool PKCS12KeyStore::engineIsKeyEntry($String* alias) {
	$useLocalCurrentObjectStackCache();
	$init($Locale);
	$var($PKCS12KeyStore$Entry, entry, $cast($PKCS12KeyStore$Entry, $nc(this->entries)->get($($nc(alias)->toLowerCase($Locale::ENGLISH)))));
	if (entry != nullptr && $instanceOf($PKCS12KeyStore$KeyEntry, entry)) {
		return true;
	} else {
		return false;
	}
}

bool PKCS12KeyStore::engineIsCertificateEntry($String* alias) {
	$useLocalCurrentObjectStackCache();
	$init($Locale);
	$var($PKCS12KeyStore$Entry, entry, $cast($PKCS12KeyStore$Entry, $nc(this->entries)->get($($nc(alias)->toLowerCase($Locale::ENGLISH)))));
	if (entry != nullptr && $instanceOf($PKCS12KeyStore$CertEntry, entry) && $nc(($cast($PKCS12KeyStore$CertEntry, entry)))->trustedKeyUsage != nullptr) {
		return true;
	} else {
		return false;
	}
}

bool PKCS12KeyStore::engineEntryInstanceOf($String* alias, $Class* entryClass) {
	$useLocalCurrentObjectStackCache();
	$load($KeyStore$TrustedCertificateEntry);
	if (entryClass == $KeyStore$TrustedCertificateEntry::class$) {
		return engineIsCertificateEntry(alias);
	}
	$init($Locale);
	$var($PKCS12KeyStore$Entry, entry, $cast($PKCS12KeyStore$Entry, $nc(this->entries)->get($($nc(alias)->toLowerCase($Locale::ENGLISH)))));
	$load($KeyStore$PrivateKeyEntry);
	if (entryClass == $KeyStore$PrivateKeyEntry::class$) {
		return (entry != nullptr && $instanceOf($PKCS12KeyStore$PrivateKeyEntry, entry));
	}
	$load($KeyStore$SecretKeyEntry);
	if (entryClass == $KeyStore$SecretKeyEntry::class$) {
		return (entry != nullptr && $instanceOf($PKCS12KeyStore$SecretKeyEntry, entry));
	}
	return false;
}

$String* PKCS12KeyStore::engineGetCertificateAlias($Certificate* cert) {
	$useLocalCurrentObjectStackCache();
	$var($Certificate, certElem, nullptr);
	{
		$var($Enumeration, e, engineAliases());
		for (; $nc(e)->hasMoreElements();) {
			$var($String, alias, $cast($String, e->nextElement()));
			$var($PKCS12KeyStore$Entry, entry, $cast($PKCS12KeyStore$Entry, $nc(this->entries)->get(alias)));
			if ($instanceOf($PKCS12KeyStore$PrivateKeyEntry, entry)) {
				if ($nc(($cast($PKCS12KeyStore$PrivateKeyEntry, entry)))->chain != nullptr) {
					$assign(certElem, $nc($nc(($cast($PKCS12KeyStore$PrivateKeyEntry, entry)))->chain)->get(0));
				}
			} else if ($instanceOf($PKCS12KeyStore$CertEntry, entry) && $nc(($cast($PKCS12KeyStore$CertEntry, entry)))->trustedKeyUsage != nullptr) {
				$assign(certElem, $nc(($cast($PKCS12KeyStore$CertEntry, entry)))->cert);
			} else {
				continue;
			}
			if (certElem != nullptr && certElem->equals(cert)) {
				return alias;
			}
		}
	}
	return nullptr;
}

void PKCS12KeyStore::engineStore($OutputStream* stream, $chars* password) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$var($DerOutputStream, pfx, $new($DerOutputStream));
		$var($DerOutputStream, version, $new($DerOutputStream));
		version->putInteger(PKCS12KeyStore::VERSION_3);
		$var($bytes, pfxVersion, version->toByteArray());
		pfx->write(pfxVersion);
		$var($DerOutputStream, authSafe, $new($DerOutputStream));
		$var($DerOutputStream, authSafeContentInfo, $new($DerOutputStream));
		if (this->privateKeyCount > 0 || this->secretKeyCount > 0) {
			if (PKCS12KeyStore::debug != nullptr) {
				$nc(PKCS12KeyStore::debug)->println($$str({"Storing "_s, $$str((this->privateKeyCount + this->secretKeyCount)), " protected key(s) in a PKCS#7 data"_s}));
			}
			$var($bytes, safeContentData, createSafeContent());
			$var($ContentInfo, dataContentInfo, $new($ContentInfo, safeContentData));
			dataContentInfo->encode(authSafeContentInfo);
		}
		if (this->certificateCount > 0) {
			if (this->certProtectionAlgorithm == nullptr) {
				$set(this, certProtectionAlgorithm, defaultCertProtectionAlgorithm());
			}
			if (this->certPbeIterationCount < 0) {
				this->certPbeIterationCount = defaultCertPbeIterationCount();
			}
			if (PKCS12KeyStore::debug != nullptr) {
				$nc(PKCS12KeyStore::debug)->println($$str({"Storing "_s, $$str(this->certificateCount), " certificate(s) in a PKCS#7 encryptedData"_s}));
			}
			$var($bytes, encrData, createEncryptedData(password));
			if (!$nc(this->certProtectionAlgorithm)->equalsIgnoreCase("NONE"_s)) {
				$init($ContentInfo);
				$var($ContentInfo, encrContentInfo, $new($ContentInfo, $ContentInfo::ENCRYPTED_DATA_OID, $$new($DerValue, encrData)));
				encrContentInfo->encode(authSafeContentInfo);
			} else {
				$var($ContentInfo, dataContentInfo, $new($ContentInfo, encrData));
				dataContentInfo->encode(authSafeContentInfo);
			}
		}
		$var($DerOutputStream, cInfo, $new($DerOutputStream));
		cInfo->write($DerValue::tag_SequenceOf, authSafeContentInfo);
		$var($bytes, authenticatedSafe, cInfo->toByteArray());
		$var($ContentInfo, contentInfo, $new($ContentInfo, authenticatedSafe));
		contentInfo->encode(authSafe);
		$var($bytes, authSafeData, authSafe->toByteArray());
		pfx->write(authSafeData);
		if (this->macAlgorithm == nullptr) {
			$set(this, macAlgorithm, defaultMacAlgorithm());
		}
		if (this->macIterationCount < 0) {
			this->macIterationCount = defaultMacIterationCount();
		}
		if (!$nc(this->macAlgorithm)->equalsIgnoreCase("NONE"_s)) {
			$var($bytes, macData, calculateMac(password, authenticatedSafe));
			pfx->write(macData);
		}
		$var($DerOutputStream, pfxout, $new($DerOutputStream));
		pfxout->write($DerValue::tag_Sequence, pfx);
		$var($bytes, pfxData, pfxout->toByteArray());
		$nc(stream)->write(pfxData);
		stream->flush();
	}
}

$KeyStore$Entry* PKCS12KeyStore::engineGetEntry($String* alias, $KeyStore$ProtectionParameter* protParam) {
	$useLocalCurrentObjectStackCache();
	if (!engineContainsAlias(alias)) {
		return nullptr;
	}
	$init($Locale);
	$var($PKCS12KeyStore$Entry, entry, $cast($PKCS12KeyStore$Entry, $nc(this->entries)->get($($nc(alias)->toLowerCase($Locale::ENGLISH)))));
	if (protParam == nullptr) {
		if (engineIsCertificateEntry(alias)) {
			if ($instanceOf($PKCS12KeyStore$CertEntry, entry) && $nc(($cast($PKCS12KeyStore$CertEntry, entry)))->trustedKeyUsage != nullptr) {
				if (PKCS12KeyStore::debug != nullptr) {
					$nc(PKCS12KeyStore::debug)->println($$str({"Retrieved a trusted certificate at alias \'"_s, alias, "\'"_s}));
				}
				return $new($KeyStore$TrustedCertificateEntry, $nc(($cast($PKCS12KeyStore$CertEntry, entry)))->cert, $(getAttributes(entry)));
			}
		} else {
			$throwNew($UnrecoverableKeyException, "requested entry requires a password"_s);
		}
	}
	if ($instanceOf($KeyStore$PasswordProtection, protParam)) {
		if (engineIsCertificateEntry(alias)) {
			$throwNew($UnsupportedOperationException, "trusted certificate entries are not password-protected"_s);
		} else if (engineIsKeyEntry(alias)) {
			$var($KeyStore$PasswordProtection, pp, $cast($KeyStore$PasswordProtection, protParam));
			$var($chars, password, $nc(pp)->getPassword());
			$var($Key, key, engineGetKey(alias, password));
			if ($instanceOf($PrivateKey, key)) {
				$var($CertificateArray, chain, engineGetCertificateChain(alias));
				return $new($KeyStore$PrivateKeyEntry, $cast($PrivateKey, key), chain, $(getAttributes(entry)));
			} else if ($instanceOf($SecretKey, key)) {
				return $new($KeyStore$SecretKeyEntry, $cast($SecretKey, key), $(getAttributes(entry)));
			}
		} else if (!engineIsKeyEntry(alias)) {
			$throwNew($UnsupportedOperationException, "untrusted certificate entries are not password-protected"_s);
		}
	}
	$throwNew($UnsupportedOperationException);
}

void PKCS12KeyStore::engineSetEntry($String* alias, $KeyStore$Entry* entry, $KeyStore$ProtectionParameter* protParam) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (protParam != nullptr && !($instanceOf($KeyStore$PasswordProtection, protParam))) {
			$throwNew($KeyStoreException, "unsupported protection parameter"_s);
		}
		$var($KeyStore$PasswordProtection, pProtect, nullptr);
		if (protParam != nullptr) {
			$assign(pProtect, $cast($KeyStore$PasswordProtection, protParam));
		}
		if ($instanceOf($KeyStore$TrustedCertificateEntry, entry)) {
			if (protParam != nullptr && $nc(pProtect)->getPassword() != nullptr) {
				$throwNew($KeyStoreException, "trusted certificate entries are not password-protected"_s);
			} else {
				$var($KeyStore$TrustedCertificateEntry, tce, $cast($KeyStore$TrustedCertificateEntry, entry));
				$var($String, var$0, alias);
				$var($Certificate, var$1, $nc(tce)->getTrustedCertificate());
				setCertEntry(var$0, var$1, $(tce->getAttributes()));
				return;
			}
		} else if ($instanceOf($KeyStore$PrivateKeyEntry, entry)) {
			if (pProtect == nullptr || $nc(pProtect)->getPassword() == nullptr) {
				$throwNew($KeyStoreException, "non-null password required to create PrivateKeyEntry"_s);
			} else {
				$var($KeyStore$PrivateKeyEntry, pke, $cast($KeyStore$PrivateKeyEntry, entry));
				$var($String, var$2, alias);
				$var($Key, var$3, static_cast<$Key*>($nc(pke)->getPrivateKey()));
				$var($KeyStore$PasswordProtection, var$4, pProtect);
				$var($CertificateArray, var$5, pke->getCertificateChain());
				setKeyEntry(var$2, var$3, var$4, var$5, $(pke->getAttributes()));
				return;
			}
		} else if ($instanceOf($KeyStore$SecretKeyEntry, entry)) {
			if (pProtect == nullptr || $nc(pProtect)->getPassword() == nullptr) {
				$throwNew($KeyStoreException, "non-null password required to create SecretKeyEntry"_s);
			} else {
				$var($KeyStore$SecretKeyEntry, ske, $cast($KeyStore$SecretKeyEntry, entry));
				$var($String, var$6, alias);
				$var($Key, var$7, static_cast<$Key*>($nc(ske)->getSecretKey()));
				$var($KeyStore$PasswordProtection, var$8, pProtect);
				$var($CertificateArray, var$9, ($CertificateArray*)nullptr);
				setKeyEntry(var$6, var$7, var$8, var$9, $(ske->getAttributes()));
				return;
			}
		}
		$throwNew($KeyStoreException, $$str({"unsupported entry type: "_s, $($nc($of(entry))->getClass()->getName())}));
	}
}

$Set* PKCS12KeyStore::getAttributes($PKCS12KeyStore$Entry* entry) {
	$useLocalCurrentObjectStackCache();
	if ($nc(entry)->attributes == nullptr) {
		$set(entry, attributes, $new($HashSet));
	}
	$nc($nc(entry)->attributes)->add($$new($PKCS12Attribute, $($nc(PKCS12KeyStore::PKCS9FriendlyName_OID)->toString()), entry->alias));
	$var($bytes, keyIdValue, entry->keyId);
	if (keyIdValue != nullptr) {
		$var($String, var$0, $nc(PKCS12KeyStore::PKCS9LocalKeyId_OID)->toString());
		$nc(entry->attributes)->add($$new($PKCS12Attribute, var$0, $($Debug::toString(keyIdValue))));
	}
	if ($instanceOf($PKCS12KeyStore$CertEntry, entry)) {
		$var($ObjectIdentifierArray, trustedKeyUsageValue, $nc(($cast($PKCS12KeyStore$CertEntry, entry)))->trustedKeyUsage);
		if (trustedKeyUsageValue != nullptr) {
			if (trustedKeyUsageValue->length == 1) {
				$var($String, var$1, $nc(PKCS12KeyStore::TrustedKeyUsage_OID)->toString());
				$nc(entry->attributes)->add($$new($PKCS12Attribute, var$1, $($nc(trustedKeyUsageValue->get(0))->toString())));
			} else {
				$var($String, var$2, $nc(PKCS12KeyStore::TrustedKeyUsage_OID)->toString());
				$nc(entry->attributes)->add($$new($PKCS12Attribute, var$2, $($Arrays::toString(trustedKeyUsageValue))));
			}
		}
	}
	return entry->attributes;
}

$bytes* PKCS12KeyStore::calculateMac($chars* passwd, $bytes* data) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, mData, nullptr);
	$var($String, algName, $nc(this->macAlgorithm)->substring(7));
	try {
		$var($bytes, salt, getSalt());
		$var($Mac, m, $Mac::getInstance(this->macAlgorithm));
		$var($PBEParameterSpec, params, $new($PBEParameterSpec, salt, this->macIterationCount));
		$var($SecretKey, key, getPBEKey(passwd));
		{
			$var($Throwable, var$0, nullptr);
			try {
				$nc(m)->init(key, params);
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				destroyPBEKey(key);
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
		$nc(m)->update(data);
		$var($bytes, macResult, m->doFinal());
		$var($MacData, macData, $new($MacData, algName, macResult, salt, this->macIterationCount));
		$var($DerOutputStream, bytes, $new($DerOutputStream));
		bytes->write($(macData->getEncoded()));
		$assign(mData, bytes->toByteArray());
	} catch ($Exception& e) {
		$throwNew($IOException, $$str({"calculateMac failed: "_s, e}), e);
	}
	return mData;
}

bool PKCS12KeyStore::validateChain($CertificateArray* certChain) {
	$useLocalCurrentObjectStackCache();
	for (int32_t i = 0; i < $nc(certChain)->length - 1; ++i) {
		$var($X500Principal, issuerDN, $nc(($cast($X509Certificate, certChain->get(i))))->getIssuerX500Principal());
		$var($X500Principal, subjectDN, $nc(($cast($X509Certificate, certChain->get(i + 1))))->getSubjectX500Principal());
		if (!($nc(issuerDN)->equals(subjectDN))) {
			return false;
		}
	}
	$var($Set, set, $new($HashSet, $(static_cast<$Collection*>($Arrays::asList(certChain)))));
	return set->size() == $nc(certChain)->length;
}

void PKCS12KeyStore::checkX509Certs($CertificateArray* certs) {
	$init(PKCS12KeyStore);
	$useLocalCurrentObjectStackCache();
	if (certs != nullptr) {
		{
			$var($CertificateArray, arr$, certs);
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($Certificate, cert, arr$->get(i$));
				{
					if (!($instanceOf($X509Certificate, cert))) {
						$throwNew($KeyStoreException, $$str({"Only X.509 certificates are supported - rejecting class: "_s, $($nc($of(cert))->getClass()->getName())}));
					}
				}
			}
		}
	}
}

$bytes* PKCS12KeyStore::getBagAttributes($String* alias, $bytes* keyId, $Set* attributes) {
	return getBagAttributes(alias, keyId, nullptr, attributes);
}

$bytes* PKCS12KeyStore::getBagAttributes($String* alias, $bytes* keyId, $ObjectIdentifierArray* trustedUsage, $Set* attributes) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, localKeyID, nullptr);
	$var($bytes, friendlyName, nullptr);
	$var($bytes, trustedKeyUsage, nullptr);
	if ((alias == nullptr) && (keyId == nullptr) && (trustedKeyUsage == nullptr)) {
		return nullptr;
	}
	$var($DerOutputStream, bagAttrs, $new($DerOutputStream));
	if (alias != nullptr) {
		$var($DerOutputStream, bagAttr1, $new($DerOutputStream));
		bagAttr1->putOID(PKCS12KeyStore::PKCS9FriendlyName_OID);
		$var($DerOutputStream, bagAttrContent1, $new($DerOutputStream));
		$var($DerOutputStream, bagAttrValue1, $new($DerOutputStream));
		bagAttrContent1->putBMPString(alias);
		bagAttr1->write($DerValue::tag_Set, bagAttrContent1);
		bagAttrValue1->write($DerValue::tag_Sequence, bagAttr1);
		$assign(friendlyName, bagAttrValue1->toByteArray());
	}
	if (keyId != nullptr) {
		$var($DerOutputStream, bagAttr2, $new($DerOutputStream));
		bagAttr2->putOID(PKCS12KeyStore::PKCS9LocalKeyId_OID);
		$var($DerOutputStream, bagAttrContent2, $new($DerOutputStream));
		$var($DerOutputStream, bagAttrValue2, $new($DerOutputStream));
		bagAttrContent2->putOctetString(keyId);
		bagAttr2->write($DerValue::tag_Set, bagAttrContent2);
		bagAttrValue2->write($DerValue::tag_Sequence, bagAttr2);
		$assign(localKeyID, bagAttrValue2->toByteArray());
	}
	if (trustedUsage != nullptr) {
		$var($DerOutputStream, bagAttr3, $new($DerOutputStream));
		bagAttr3->putOID(PKCS12KeyStore::TrustedKeyUsage_OID);
		$var($DerOutputStream, bagAttrContent3, $new($DerOutputStream));
		$var($DerOutputStream, bagAttrValue3, $new($DerOutputStream));
		{
			$var($ObjectIdentifierArray, arr$, trustedUsage);
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($ObjectIdentifier, usage, arr$->get(i$));
				{
					bagAttrContent3->putOID(usage);
				}
			}
		}
		bagAttr3->write($DerValue::tag_Set, bagAttrContent3);
		bagAttrValue3->write($DerValue::tag_Sequence, bagAttr3);
		$assign(trustedKeyUsage, bagAttrValue3->toByteArray());
	}
	$var($DerOutputStream, attrs, $new($DerOutputStream));
	if (friendlyName != nullptr) {
		attrs->write(friendlyName);
	}
	if (localKeyID != nullptr) {
		attrs->write(localKeyID);
	}
	if (trustedKeyUsage != nullptr) {
		attrs->write(trustedKeyUsage);
	}
	if (attributes != nullptr) {
		{
			$var($Iterator, i$, attributes->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($KeyStore$Entry$Attribute, attribute, $cast($KeyStore$Entry$Attribute, i$->next()));
				{
					$var($String, attributeName, $nc(attribute)->getName());
					bool var$1 = $nc($($nc($nc(PKCS12KeyStore::CORE_ATTRIBUTES)->get(0))->value()))->equals(attributeName);
					bool var$0 = var$1 || $nc($($nc($nc(PKCS12KeyStore::CORE_ATTRIBUTES)->get(1))->value()))->equals(attributeName);
					if (var$0 || $nc($($nc($nc(PKCS12KeyStore::CORE_ATTRIBUTES)->get(2))->value()))->equals(attributeName)) {
						continue;
					}
					attrs->write($($nc(($cast($PKCS12Attribute, attribute)))->getEncoded()));
				}
			}
		}
	}
	bagAttrs->write($DerValue::tag_Set, attrs);
	return bagAttrs->toByteArray();
}

$bytes* PKCS12KeyStore::createEncryptedData($chars* password) {
	$useLocalCurrentObjectStackCache();
	$var($DerOutputStream, out, $new($DerOutputStream));
	{
		$var($Enumeration, e, engineAliases());
		for (; $nc(e)->hasMoreElements();) {
			$var($String, alias, $cast($String, e->nextElement()));
			$var($PKCS12KeyStore$Entry, entry, $cast($PKCS12KeyStore$Entry, $nc(this->entries)->get(alias)));
			$var($CertificateArray, certs, nullptr);
			if ($instanceOf($PKCS12KeyStore$PrivateKeyEntry, entry)) {
				$var($PKCS12KeyStore$PrivateKeyEntry, keyEntry, $cast($PKCS12KeyStore$PrivateKeyEntry, entry));
				if ($nc(keyEntry)->chain != nullptr) {
					$assign(certs, keyEntry->chain);
				} else {
					$assign(certs, $new($CertificateArray, 0));
				}
			} else if ($instanceOf($PKCS12KeyStore$CertEntry, entry)) {
				$assign(certs, $new($CertificateArray, {static_cast<$Certificate*>($nc(($cast($PKCS12KeyStore$CertEntry, entry)))->cert)}));
			} else {
				$assign(certs, $new($CertificateArray, 0));
			}
			for (int32_t i = 0; i < $nc(certs)->length; ++i) {
				$var($DerOutputStream, safeBag, $new($DerOutputStream));
				safeBag->putOID(PKCS12KeyStore::CertBag_OID);
				$var($DerOutputStream, certBag, $new($DerOutputStream));
				certBag->putOID(PKCS12KeyStore::PKCS9CertType_OID);
				$var($DerOutputStream, certValue, $new($DerOutputStream));
				$var($X509Certificate, cert, $cast($X509Certificate, certs->get(i)));
				certValue->putOctetString($($nc(cert)->getEncoded()));
				certBag->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)0), certValue);
				$var($DerOutputStream, certout, $new($DerOutputStream));
				certout->write($DerValue::tag_Sequence, certBag);
				$var($bytes, certBagValue, certout->toByteArray());
				$var($DerOutputStream, bagValue, $new($DerOutputStream));
				bagValue->write(certBagValue);
				safeBag->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)0), bagValue);
				$var($bytes, bagAttrs, nullptr);
				if (i == 0) {
					if ($instanceOf($PKCS12KeyStore$KeyEntry, entry)) {
						$var($PKCS12KeyStore$KeyEntry, keyEntry, $cast($PKCS12KeyStore$KeyEntry, entry));
						$assign(bagAttrs, getBagAttributes($nc(keyEntry)->alias, keyEntry->keyId, keyEntry->attributes));
					} else {
						$var($PKCS12KeyStore$CertEntry, certEntry, $cast($PKCS12KeyStore$CertEntry, entry));
						$assign(bagAttrs, getBagAttributes($nc(certEntry)->alias, certEntry->keyId, certEntry->trustedKeyUsage, certEntry->attributes));
					}
				} else {
					$assign(bagAttrs, getBagAttributes($($nc($($nc(cert)->getSubjectX500Principal()))->getName()), nullptr, $nc(entry)->attributes));
				}
				if (bagAttrs != nullptr) {
					safeBag->write(bagAttrs);
				}
				out->write($DerValue::tag_Sequence, safeBag);
			}
		}
	}
	$var($DerOutputStream, safeBagValue, $new($DerOutputStream));
	safeBagValue->write($DerValue::tag_SequenceOf, out);
	$var($bytes, safeBagData, safeBagValue->toByteArray());
	if (!$nc(this->certProtectionAlgorithm)->equalsIgnoreCase("NONE"_s)) {
		$var($bytes, encrContentInfo, encryptContent(safeBagData, password));
		$var($DerOutputStream, encrData, $new($DerOutputStream));
		$var($DerOutputStream, encrDataContent, $new($DerOutputStream));
		encrData->putInteger(0);
		encrData->write(encrContentInfo);
		encrDataContent->write($DerValue::tag_Sequence, encrData);
		return encrDataContent->toByteArray();
	} else {
		return safeBagData;
	}
}

$bytes* PKCS12KeyStore::createSafeContent() {
	$useLocalCurrentObjectStackCache();
	$var($DerOutputStream, out, $new($DerOutputStream));
	{
		$var($Enumeration, e, engineAliases());
		for (; $nc(e)->hasMoreElements();) {
			$var($String, alias, $cast($String, e->nextElement()));
			$var($PKCS12KeyStore$Entry, entry, $cast($PKCS12KeyStore$Entry, $nc(this->entries)->get(alias)));
			if (entry == nullptr || (!($instanceOf($PKCS12KeyStore$KeyEntry, entry)))) {
				continue;
			}
			$var($DerOutputStream, safeBag, $new($DerOutputStream));
			$var($PKCS12KeyStore$KeyEntry, keyEntry, $cast($PKCS12KeyStore$KeyEntry, entry));
			if ($instanceOf($PKCS12KeyStore$PrivateKeyEntry, keyEntry)) {
				safeBag->putOID(PKCS12KeyStore::PKCS8ShroudedKeyBag_OID);
				$var($bytes, encrBytes, $nc(($cast($PKCS12KeyStore$PrivateKeyEntry, keyEntry)))->protectedPrivKey);
				$var($EncryptedPrivateKeyInfo, encrInfo, nullptr);
				try {
					$assign(encrInfo, $new($EncryptedPrivateKeyInfo, encrBytes));
				} catch ($IOException& ioe) {
					$throwNew($IOException, $$str({"Private key not stored as PKCS#8 EncryptedPrivateKeyInfo"_s, $(ioe->getMessage())}));
				}
				$var($DerOutputStream, bagValue, $new($DerOutputStream));
				bagValue->write($($nc(encrInfo)->getEncoded()));
				safeBag->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)0), bagValue);
			} else if ($instanceOf($PKCS12KeyStore$SecretKeyEntry, keyEntry)) {
				safeBag->putOID(PKCS12KeyStore::SecretBag_OID);
				$var($DerOutputStream, secretBag, $new($DerOutputStream));
				secretBag->putOID(PKCS12KeyStore::PKCS8ShroudedKeyBag_OID);
				$var($DerOutputStream, secretKeyValue, $new($DerOutputStream));
				secretKeyValue->putOctetString($nc(($cast($PKCS12KeyStore$SecretKeyEntry, keyEntry)))->protectedSecretKey);
				secretBag->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)0), secretKeyValue);
				$var($DerOutputStream, secretBagSeq, $new($DerOutputStream));
				secretBagSeq->write($DerValue::tag_Sequence, secretBag);
				$var($bytes, secretBagValue, secretBagSeq->toByteArray());
				$var($DerOutputStream, bagValue, $new($DerOutputStream));
				bagValue->write(secretBagValue);
				safeBag->write($DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)0), bagValue);
			} else {
				continue;
			}
			$var($bytes, bagAttrs, getBagAttributes(alias, $nc(entry)->keyId, entry->attributes));
			safeBag->write(bagAttrs);
			out->write($DerValue::tag_Sequence, safeBag);
		}
	}
	$var($DerOutputStream, safeBagValue, $new($DerOutputStream));
	safeBagValue->write($DerValue::tag_Sequence, out);
	return safeBagValue->toByteArray();
}

$bytes* PKCS12KeyStore::encryptContent($bytes* data, $chars* password) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, encryptedData, nullptr);
	try {
		$var($AlgorithmParameters, algParams, getPBEAlgorithmParameters(this->certProtectionAlgorithm, this->certPbeIterationCount));
		$var($DerOutputStream, bytes, $new($DerOutputStream));
		$var($Cipher, cipher, $Cipher::getInstance(this->certProtectionAlgorithm));
		$var($SecretKey, skey, getPBEKey(password));
		{
			$var($Throwable, var$0, nullptr);
			try {
				$nc(cipher)->init($Cipher::ENCRYPT_MODE, static_cast<$Key*>(skey), algParams);
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				destroyPBEKey(skey);
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
		$assign(encryptedData, $nc(cipher)->doFinal(data));
		$var($ObjectIdentifier, var$2, mapPBEAlgorithmToOID(this->certProtectionAlgorithm));
		$var($AlgorithmId, algId, $new($AlgorithmId, var$2, $(cipher->getParameters())));
		algId->encode(bytes);
		$var($bytes, encodedAlgId, bytes->toByteArray());
		if (PKCS12KeyStore::debug != nullptr) {
			$nc(PKCS12KeyStore::debug)->println($$str({"  (Cipher algorithm: "_s, $(cipher->getAlgorithm()), ")"_s}));
		}
		$var($DerOutputStream, bytes2, $new($DerOutputStream));
		$init($ContentInfo);
		bytes2->putOID($ContentInfo::DATA_OID);
		bytes2->write(encodedAlgId);
		$var($DerOutputStream, tmpout2, $new($DerOutputStream));
		tmpout2->putOctetString(encryptedData);
		bytes2->writeImplicit($DerValue::createTag($DerValue::TAG_CONTEXT, false, (int8_t)0), tmpout2);
		$var($DerOutputStream, out, $new($DerOutputStream));
		out->write($DerValue::tag_Sequence, bytes2);
		return out->toByteArray();
	} catch ($IOException& ioe) {
		$throw(ioe);
	} catch ($Exception& e) {
		$throwNew($IOException, $$str({"Failed to encrypt safe contents entry: "_s, e}), e);
	}
	$shouldNotReachHere();
}

void PKCS12KeyStore::engineLoad($InputStream* stream, $chars* password) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$set(this, certProtectionAlgorithm, nullptr);
		this->certPbeIterationCount = -1;
		$set(this, macAlgorithm, nullptr);
		this->macIterationCount = -1;
		if (stream == nullptr) {
			return;
		}
		this->counter = 0;
		$var($DerValue, val, $new($DerValue, stream));
		$var($DerInputStream, s, val->toDerInputStream());
		int32_t version = $nc(s)->getInteger();
		if (version != PKCS12KeyStore::VERSION_3) {
			$throwNew($IOException, "PKCS12 keystore not in version 3 format"_s);
		}
		$nc(this->entries)->clear();
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
		this->privateKeyCount = 0;
		this->secretKeyCount = 0;
		this->certificateCount = 0;
		bool seeEncBag = false;
		for (int32_t i = 0; i < count; ++i) {
			$var($ContentInfo, safeContents, nullptr);
			$var($DerInputStream, sci, nullptr);
			$var($bytes, eAlgId, nullptr);
			$assign(sci, $new($DerInputStream, $($nc(safeContentsArray->get(i))->toByteArray())));
			$assign(safeContents, $new($ContentInfo, sci));
			$assign(contentType, safeContents->getContentType());
			if ($nc(contentType)->equals($ContentInfo::DATA_OID)) {
				if (PKCS12KeyStore::debug != nullptr) {
					$nc(PKCS12KeyStore::debug)->println("Loading PKCS#7 data"_s);
				}
				loadSafeContents($$new($DerInputStream, $(safeContents->getData())));
			} else {
				if (contentType->equals($ContentInfo::ENCRYPTED_DATA_OID)) {
					if (password == nullptr) {
						if (PKCS12KeyStore::debug != nullptr) {
							$nc(PKCS12KeyStore::debug)->println("Warning: skipping PKCS#7 encryptedData - no password was supplied"_s);
						}
						continue;
					}
					$var($DerInputStream, edi, $nc($(safeContents->getContent()))->toDerInputStream());
					int32_t edVersion = $nc(edi)->getInteger();
					$var($DerValueArray, seq, edi->getSequence(3));
					if ($nc(seq)->length != 3) {
						$throwNew($IOException, "Invalid length for EncryptedContentInfo"_s);
					}
					$var($ObjectIdentifier, edContentType, $nc($nc(seq)->get(0))->getOID());
					$assign(eAlgId, $nc(seq->get(1))->toByteArray());
					if (!$nc(seq->get(2))->isContextSpecific((int8_t)0)) {
						$throwNew($IOException, $$str({"unsupported encrypted content type "_s, $$str($nc(seq->get(2))->tag)}));
					}
					int8_t newTag = $DerValue::tag_OctetString;
					if ($nc(seq->get(2))->isConstructed()) {
						newTag |= 32;
					}
					$nc(seq->get(2))->resetTag(newTag);
					$var($bytes, rawData, $nc(seq->get(2))->getOctetString());
					$var($DerInputStream, in, $nc(seq->get(1))->toDerInputStream());
					$var($ObjectIdentifier, algOid, $nc(in)->getOID());
					$var($AlgorithmParameters, algParams, parseAlgParameters(algOid, in));
					$var($PBEParameterSpec, pbeSpec, nullptr);
					int32_t ic = 0;
					if (algParams != nullptr) {
						try {
							$load($PBEParameterSpec);
							$assign(pbeSpec, $cast($PBEParameterSpec, algParams->getParameterSpec($PBEParameterSpec::class$)));
						} catch ($InvalidParameterSpecException& ipse) {
							$throwNew($IOException, "Invalid PBE algorithm parameters"_s);
						}
						ic = $nc(pbeSpec)->getIterationCount();
						if (ic > PKCS12KeyStore::MAX_ITERATION_COUNT) {
							$throwNew($IOException, "cert PBE iteration count too large"_s);
						}
						$set(this, certProtectionAlgorithm, mapPBEParamsToAlgorithm(algOid, algParams));
						this->certPbeIterationCount = ic;
						seeEncBag = true;
					}
					if (PKCS12KeyStore::debug != nullptr) {
						$nc(PKCS12KeyStore::debug)->println($$str({"Loading PKCS#7 encryptedData ("_s, $(mapPBEParamsToAlgorithm(algOid, algParams)), " iterations: "_s, $$str(ic), ")"_s}));
					}
					try {
						$PKCS12KeyStore$RetryWithZero::run(static_cast<$PKCS12KeyStore$RetryWithZero*>($$new(PKCS12KeyStore$$Lambda$lambda$engineLoad$1$1, this, algOid, algParams, rawData)), password);
					} catch ($Exception& e) {
						$throwNew($IOException, "keystore password was incorrect"_s, $$new($UnrecoverableKeyException, $$str({"failed to decrypt safe contents entry: "_s, e})));
					}
				} else {
					$throwNew($IOException, "public key protected PKCS12 not supported"_s);
				}
			}
		}
		if (!seeEncBag && this->certificateCount > 0) {
			$set(this, certProtectionAlgorithm, "NONE"_s);
		}
		if (s->available() > 0) {
			if (password != nullptr) {
				$var($MacData, macData, $new($MacData, s));
				int32_t ic = macData->getIterations();
				try {
					if (ic > PKCS12KeyStore::MAX_ITERATION_COUNT) {
						$throwNew($InvalidAlgorithmParameterException, $$str({"MAC iteration count too large: "_s, $$str(ic)}));
					}
					$init($Locale);
					$var($String, algName, $nc($(macData->getDigestAlgName()))->toUpperCase($Locale::ENGLISH));
					$assign(algName, algName->replace(static_cast<$CharSequence*>("-"_s), static_cast<$CharSequence*>(""_s)));
					$set(this, macAlgorithm, $str({"HmacPBE"_s, algName}));
					this->macIterationCount = ic;
					$var($Mac, m, $Mac::getInstance(this->macAlgorithm));
					$var($PBEParameterSpec, params, $new($PBEParameterSpec, $(macData->getSalt()), ic));
					$PKCS12KeyStore$RetryWithZero::run(static_cast<$PKCS12KeyStore$RetryWithZero*>($$new(PKCS12KeyStore$$Lambda$lambda$engineLoad$2$2, this, m, params, authSafeData, ic, macData)), password);
				} catch ($Exception& e) {
					$throwNew($IOException, $$str({"Integrity check failed: "_s, e}), e);
				}
			}
		} else {
			$set(this, macAlgorithm, "NONE"_s);
		}
		$var($PKCS12KeyStore$PrivateKeyEntryArray, list, $fcast($PKCS12KeyStore$PrivateKeyEntryArray, $nc(this->keyList)->toArray($$new($PKCS12KeyStore$PrivateKeyEntryArray, $nc(this->keyList)->size()))));
		for (int32_t m = 0; m < $nc(list)->length; ++m) {
			$var($PKCS12KeyStore$PrivateKeyEntry, entry, list->get(m));
			if ($nc(entry)->keyId != nullptr) {
				$var($ArrayList, chain, $new($ArrayList));
				$var($X509Certificate, cert, findMatchedCertificate(entry));
				bool mainloop$break = false;
				while (cert != nullptr) {
					if (!chain->isEmpty()) {
						{
							$var($Iterator, i$, chain->iterator());
							for (; $nc(i$)->hasNext();) {
								$var($X509Certificate, chainCert, $cast($X509Certificate, i$->next()));
								{
									if (cert->equals(chainCert)) {
										if (PKCS12KeyStore::debug != nullptr) {
											$nc(PKCS12KeyStore::debug)->println($$str({"Loop detected in certificate chain. Skip adding repeated cert to chain. Subject: "_s, $($nc($(cert->getSubjectX500Principal()))->toString())}));
										}
										mainloop$break = true;
										break;
									}
								}
							}
							if (mainloop$break) {
								break;
							}
						}
					}
					chain->add(cert);
					if ($KeyStoreUtil::isSelfSigned(cert)) {
						break;
					}
					$assign(cert, findIssuer(cert));
				}
				if (chain->size() > 0) {
					$set(entry, chain, $fcast($CertificateArray, chain->toArray($$new($CertificateArray, chain->size()))));
				} else {
					$nc(this->entries)->remove(entry);
				}
			}
		}
		if (PKCS12KeyStore::debug != nullptr) {
			$nc(PKCS12KeyStore::debug)->println($$str({"PKCS12KeyStore load: private key count: "_s, $$str(this->privateKeyCount), ". secret key count: "_s, $$str(this->secretKeyCount), ". certificate count: "_s, $$str(this->certificateCount)}));
		}
		$nc(this->certEntries)->clear();
		$nc(this->allCerts)->clear();
		$nc(this->keyList)->clear();
	}
}

$X509Certificate* PKCS12KeyStore::findIssuer($X509Certificate* input) {
	$useLocalCurrentObjectStackCache();
	$var($X509Certificate, fallback, nullptr);
	$var($X500Principal, issuerPrinc, $nc(input)->getIssuerX500Principal());
	$init($KnownOIDs);
	$var($bytes, issuerIdExtension, input->getExtensionValue($($KnownOIDs::AuthorityKeyID->value())));
	$var($bytes, issuerId, nullptr);
	if (issuerIdExtension != nullptr) {
		try {
			$var($Boolean, var$0, $Boolean::valueOf(false));
			$assign(issuerId, $$new($AuthorityKeyIdentifierExtension, var$0, $($$new($DerValue, issuerIdExtension)->getOctetString()))->getEncodedKeyIdentifier());
		} catch ($IOException& e) {
		}
	}
	{
		$var($Iterator, i$, $nc(this->allCerts)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($X509Certificate, cert, $cast($X509Certificate, i$->next()));
			{
				if ($nc($($nc(cert)->getSubjectX500Principal()))->equals(issuerPrinc)) {
					if (issuerId != nullptr) {
						$var($bytes, subjectIdExtension, cert->getExtensionValue($($KnownOIDs::SubjectKeyID->value())));
						$var($bytes, subjectId, nullptr);
						if (subjectIdExtension != nullptr) {
							try {
								$assign(subjectId, $$new($DerValue, subjectIdExtension)->getOctetString());
							} catch ($IOException& e) {
							}
						}
						if (subjectId != nullptr) {
							if ($Arrays::equals(issuerId, subjectId)) {
								return cert;
							} else {
								continue;
							}
						} else {
							$assign(fallback, cert);
						}
					} else {
						return cert;
					}
				}
			}
		}
	}
	return fallback;
}

bool PKCS12KeyStore::isPasswordless($File* f) {
	$init(PKCS12KeyStore);
	$useLocalCurrentObjectStackCache();
	{
		$var($FileInputStream, stream, $new($FileInputStream, f));
		{
			$var($Throwable, var$0, nullptr);
			bool var$2 = false;
			bool return$1 = false;
			try {
				try {
					$var($DerValue, val, $new($DerValue, static_cast<$InputStream*>(stream)));
					$var($DerInputStream, s, val->toDerInputStream());
					$nc(s)->getInteger();
					$var($ContentInfo, authSafe, $new($ContentInfo, s));
					$var($DerInputStream, as, $new($DerInputStream, $(authSafe->getData())));
					{
						$var($DerValueArray, arr$, as->getSequence(2));
						int32_t len$ = $nc(arr$)->length;
						int32_t i$ = 0;
						for (; i$ < len$; ++i$) {
							$var($DerValue, seq, arr$->get(i$));
							{
								$var($DerInputStream, sci, $new($DerInputStream, $($nc(seq)->toByteArray())));
								$var($ContentInfo, safeContents, $new($ContentInfo, sci));
								if ($nc($(safeContents->getContentType()))->equals($ContentInfo::ENCRYPTED_DATA_OID)) {
									var$2 = false;
									return$1 = true;
									goto $finally;
								}
							}
						}
					}
					if (s->available() > 0) {
						var$2 = false;
						return$1 = true;
						goto $finally;
					}
				} catch ($Throwable& t$) {
					try {
						stream->close();
					} catch ($Throwable& x2) {
						t$->addSuppressed(x2);
					}
					$throw(t$);
				}
			} catch ($Throwable& var$3) {
				$assign(var$0, var$3);
			} $finally: {
				stream->close();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
			if (return$1) {
				return var$2;
			}
		}
	}
	return true;
}

$X509Certificate* PKCS12KeyStore::findMatchedCertificate($PKCS12KeyStore$PrivateKeyEntry* entry) {
	$useLocalCurrentObjectStackCache();
	$var($PKCS12KeyStore$CertEntry, keyIdMatch, nullptr);
	$var($PKCS12KeyStore$CertEntry, aliasMatch, nullptr);
	{
		$var($Iterator, i$, $nc(this->certEntries)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($PKCS12KeyStore$CertEntry, ce, $cast($PKCS12KeyStore$CertEntry, i$->next()));
			{
				if ($Arrays::equals($nc(entry)->keyId, $nc(ce)->keyId)) {
					$assign(keyIdMatch, ce);
					if ($nc($nc(entry)->alias)->equalsIgnoreCase($nc(ce)->alias)) {
						return $nc(ce)->cert;
					}
				} else if ($nc($nc(entry)->alias)->equalsIgnoreCase($nc(ce)->alias)) {
					$assign(aliasMatch, ce);
				}
			}
		}
	}
	if (keyIdMatch != nullptr) {
		return keyIdMatch->cert;
	} else if (aliasMatch != nullptr) {
		return aliasMatch->cert;
	} else {
		return nullptr;
	}
}

void PKCS12KeyStore::loadSafeContents($DerInputStream* stream) {
	$useLocalCurrentObjectStackCache();
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
		if ($nc(bagId)->equals(PKCS12KeyStore::PKCS8ShroudedKeyBag_OID)) {
			$var($PKCS12KeyStore$PrivateKeyEntry, kEntry, $new($PKCS12KeyStore$PrivateKeyEntry));
			$set(kEntry, protectedPrivKey, bagValue->toByteArray());
			$assign(bagItem, kEntry);
			++this->privateKeyCount;
		} else if (bagId->equals(PKCS12KeyStore::CertBag_OID)) {
			$var($DerInputStream, cs, $new($DerInputStream, $(bagValue->toByteArray())));
			$var($DerValueArray, certValues, cs->getSequence(2));
			if ($nc(certValues)->length != 2) {
				$throwNew($IOException, "Invalid length for CertBag"_s);
			}
			$var($ObjectIdentifier, certId, $nc($nc(certValues)->get(0))->getOID());
			if (!$nc(certValues->get(1))->isContextSpecific((int8_t)0)) {
				$throwNew($IOException, $$str({"unsupported PKCS12 cert value type "_s, $$str($nc(certValues->get(1))->tag)}));
			}
			$var($DerValue, certValue, $nc($nc(certValues->get(1))->data$)->getDerValue());
			$var($CertificateFactory, cf, $CertificateFactory::getInstance("X509"_s));
			$var($X509Certificate, cert, nullptr);
			$assign(cert, $cast($X509Certificate, $nc(cf)->generateCertificate($$new($ByteArrayInputStream, $($nc(certValue)->getOctetString())))));
			$assign(bagItem, cert);
			++this->certificateCount;
		} else if (bagId->equals(PKCS12KeyStore::SecretBag_OID)) {
			$var($DerInputStream, ss, $new($DerInputStream, $(bagValue->toByteArray())));
			$var($DerValueArray, secretValues, ss->getSequence(2));
			if ($nc(secretValues)->length != 2) {
				$throwNew($IOException, "Invalid length for SecretBag"_s);
			}
			$var($ObjectIdentifier, secretId, $nc($nc(secretValues)->get(0))->getOID());
			if (!$nc(secretValues->get(1))->isContextSpecific((int8_t)0)) {
				$throwNew($IOException, $$str({"unsupported PKCS12 secret value type "_s, $$str($nc(secretValues->get(1))->tag)}));
			}
			$var($DerValue, secretValue, $nc($nc(secretValues->get(1))->data$)->getDerValue());
			$var($PKCS12KeyStore$SecretKeyEntry, kEntry, $new($PKCS12KeyStore$SecretKeyEntry));
			$set(kEntry, protectedSecretKey, $nc(secretValue)->getOctetString());
			$assign(bagItem, kEntry);
			++this->secretKeyCount;
		} else if (PKCS12KeyStore::debug != nullptr) {
			$nc(PKCS12KeyStore::debug)->println($$str({"Unsupported PKCS12 bag type: "_s, bagId}));
		}
		$var($DerValueArray, attrSet, nullptr);
		try {
			$assign(attrSet, sbi->getSet(3));
		} catch ($IOException& e) {
			$assign(attrSet, nullptr);
		}
		$var($String, alias, nullptr);
		$var($bytes, keyId, nullptr);
		$var($ObjectIdentifierArray, trustedKeyUsage, nullptr);
		$var($Set, attributes, $new($HashSet));
		if (attrSet != nullptr) {
			for (int32_t j = 0; j < attrSet->length; ++j) {
				$var($bytes, encoded, $nc(attrSet->get(j))->toByteArray());
				$var($DerInputStream, as, $new($DerInputStream, encoded));
				$var($DerValueArray, attrSeq, as->getSequence(2));
				if ($nc(attrSeq)->length != 2) {
					$throwNew($IOException, "Invalid length for Attribute"_s);
				}
				$var($ObjectIdentifier, attrId, $nc($nc(attrSeq)->get(0))->getOID());
				$var($DerInputStream, vs, $new($DerInputStream, $($nc(attrSeq->get(1))->toByteArray())));
				$var($DerValueArray, valSet, nullptr);
				try {
					$assign(valSet, vs->getSet(1));
				} catch ($IOException& e) {
					$var($String, var$0, $$str({"Attribute "_s, attrId, " should have a value "_s}));
					$throwNew($IOException, $$concat(var$0, $(e->getMessage())));
				}
				if ($nc(attrId)->equals(PKCS12KeyStore::PKCS9FriendlyName_OID)) {
					$assign(alias, $nc($nc(valSet)->get(0))->getBMPString());
				} else if (attrId->equals(PKCS12KeyStore::PKCS9LocalKeyId_OID)) {
					$assign(keyId, $nc($nc(valSet)->get(0))->getOctetString());
				} else if (attrId->equals(PKCS12KeyStore::TrustedKeyUsage_OID)) {
					$assign(trustedKeyUsage, $new($ObjectIdentifierArray, $nc(valSet)->length));
					for (int32_t k = 0; k < valSet->length; ++k) {
						trustedKeyUsage->set(k, $($nc(valSet->get(k))->getOID()));
					}
				} else {
					attributes->add($$new($PKCS12Attribute, encoded));
				}
			}
		}
		if ($instanceOf($PKCS12KeyStore$KeyEntry, bagItem)) {
			$var($PKCS12KeyStore$KeyEntry, entry, $cast($PKCS12KeyStore$KeyEntry, bagItem));
			if (keyId == nullptr) {
				if ($instanceOf($PKCS12KeyStore$PrivateKeyEntry, bagItem)) {
					if (this->privateKeyCount == 1) {
						$init($StandardCharsets);
						$assign(keyId, "01"_s->getBytes($StandardCharsets::UTF_8));
					} else {
						continue;
					}
				} else {
					$init($StandardCharsets);
					$assign(keyId, "00"_s->getBytes($StandardCharsets::UTF_8));
				}
			}
			$set($nc(entry), keyId, keyId);
			$init($StandardCharsets);
			$var($String, keyIdStr, $new($String, keyId, $StandardCharsets::UTF_8));
			$var($Date, date, nullptr);
			if (keyIdStr->startsWith("Time "_s)) {
				try {
					$assign(date, $new($Date, $Long::parseLong($(keyIdStr->substring(5)))));
				} catch ($Exception& e) {
					$assign(date, nullptr);
				}
			}
			if (date == nullptr) {
				$assign(date, $new($Date));
			}
			$set(entry, date, date);
			if ($instanceOf($PKCS12KeyStore$PrivateKeyEntry, bagItem)) {
				$nc(this->keyList)->add($cast($PKCS12KeyStore$PrivateKeyEntry, entry));
			}
			if (entry->attributes == nullptr) {
				$set(entry, attributes, $new($HashSet));
			}
			$nc(entry->attributes)->addAll(attributes);
			if (alias == nullptr) {
				$assign(alias, getUnfriendlyName());
			}
			$set(entry, alias, alias);
			$init($Locale);
			$nc(this->entries)->put($($nc(alias)->toLowerCase($Locale::ENGLISH)), entry);
		} else if ($instanceOf($X509Certificate, bagItem)) {
			$var($X509Certificate, cert, $cast($X509Certificate, bagItem));
			if ((keyId == nullptr) && (this->privateKeyCount == 1)) {
				if (i == 0) {
					$init($StandardCharsets);
					$assign(keyId, "01"_s->getBytes($StandardCharsets::UTF_8));
				}
			}
			if (trustedKeyUsage != nullptr) {
				if (alias == nullptr) {
					$assign(alias, getUnfriendlyName());
				}
				$var($PKCS12KeyStore$CertEntry, certEntry, $new($PKCS12KeyStore$CertEntry, cert, keyId, alias, trustedKeyUsage, attributes));
				$init($Locale);
				$nc(this->entries)->put($($nc(alias)->toLowerCase($Locale::ENGLISH)), certEntry);
			} else {
				$nc(this->certEntries)->add($$new($PKCS12KeyStore$CertEntry, cert, keyId, alias));
			}
			$nc(this->allCerts)->add(cert);
		}
	}
}

$String* PKCS12KeyStore::getUnfriendlyName() {
	++this->counter;
	return ($String::valueOf(this->counter));
}

bool PKCS12KeyStore::engineProbe($InputStream* stream) {
	$var($DataInputStream, dataStream, nullptr);
	if ($instanceOf($DataInputStream, stream)) {
		$assign(dataStream, $cast($DataInputStream, stream));
	} else {
		$assign(dataStream, $new($DataInputStream, stream));
	}
	int64_t firstPeek = $nc(dataStream)->readLong();
	int64_t nextPeek = dataStream->readLong();
	int64_t finalPeek = dataStream->readLong();
	bool result = false;
	for (int32_t i = 0; i < $nc(PKCS12KeyStore::PKCS12_HEADER_PATTERNS)->length; ++i) {
		if ($nc($nc(PKCS12KeyStore::PKCS12_HEADER_PATTERNS)->get(i))->get(0) == ((int64_t)(firstPeek & (uint64_t)$nc($nc(PKCS12KeyStore::PKCS12_HEADER_MASKS)->get(i))->get(0))) && ($nc($nc(PKCS12KeyStore::PKCS12_HEADER_PATTERNS)->get(i))->get(1) == ((int64_t)(nextPeek & (uint64_t)$nc($nc(PKCS12KeyStore::PKCS12_HEADER_MASKS)->get(i))->get(1)))) && ($nc($nc(PKCS12KeyStore::PKCS12_HEADER_PATTERNS)->get(i))->get(2) == ((int64_t)(finalPeek & (uint64_t)$nc($nc(PKCS12KeyStore::PKCS12_HEADER_MASKS)->get(i))->get(2))))) {
			result = true;
			break;
		}
	}
	return result;
}

bool PKCS12KeyStore::useLegacy() {
	$init(PKCS12KeyStore);
	return $GetPropertyAction::privilegedGetProperty(PKCS12KeyStore::USE_LEGACY_PROP) != nullptr;
}

$String* PKCS12KeyStore::defaultCertProtectionAlgorithm() {
	$init(PKCS12KeyStore);
	if (useLegacy()) {
		return PKCS12KeyStore::LEGACY_CERT_PBE_ALGORITHM;
	}
	$var($String, result, $SecurityProperties::privilegedGetOverridable("keystore.pkcs12.certProtectionAlgorithm"_s));
	return (result != nullptr && !result->isEmpty()) ? result : PKCS12KeyStore::DEFAULT_CERT_PBE_ALGORITHM;
}

int32_t PKCS12KeyStore::defaultCertPbeIterationCount() {
	$init(PKCS12KeyStore);
	if (useLegacy()) {
		return PKCS12KeyStore::LEGACY_PBE_ITERATION_COUNT;
	}
	$var($String, result, $SecurityProperties::privilegedGetOverridable("keystore.pkcs12.certPbeIterationCount"_s));
	return (result != nullptr && !result->isEmpty()) ? string2IC("certPbeIterationCount"_s, result) : PKCS12KeyStore::DEFAULT_CERT_PBE_ITERATION_COUNT;
}

$String* PKCS12KeyStore::defaultKeyProtectionAlgorithm() {
	$init(PKCS12KeyStore);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (useLegacy()) {
		return PKCS12KeyStore::LEGACY_KEY_PBE_ALGORITHM;
	}
	$var($String, result, $cast($String, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($PKCS12KeyStore$1)))));
	return (result != nullptr && !result->isEmpty()) ? result : PKCS12KeyStore::DEFAULT_KEY_PBE_ALGORITHM;
}

int32_t PKCS12KeyStore::defaultKeyPbeIterationCount() {
	$init(PKCS12KeyStore);
	if (useLegacy()) {
		return PKCS12KeyStore::LEGACY_PBE_ITERATION_COUNT;
	}
	$var($String, result, $SecurityProperties::privilegedGetOverridable("keystore.pkcs12.keyPbeIterationCount"_s));
	return (result != nullptr && !result->isEmpty()) ? string2IC("keyPbeIterationCount"_s, result) : PKCS12KeyStore::DEFAULT_KEY_PBE_ITERATION_COUNT;
}

$String* PKCS12KeyStore::defaultMacAlgorithm() {
	$init(PKCS12KeyStore);
	if (useLegacy()) {
		return PKCS12KeyStore::LEGACY_MAC_ALGORITHM;
	}
	$var($String, result, $SecurityProperties::privilegedGetOverridable("keystore.pkcs12.macAlgorithm"_s));
	return (result != nullptr && !result->isEmpty()) ? result : PKCS12KeyStore::DEFAULT_MAC_ALGORITHM;
}

int32_t PKCS12KeyStore::defaultMacIterationCount() {
	$init(PKCS12KeyStore);
	if (useLegacy()) {
		return PKCS12KeyStore::LEGACY_MAC_ITERATION_COUNT;
	}
	$var($String, result, $SecurityProperties::privilegedGetOverridable("keystore.pkcs12.macIterationCount"_s));
	return (result != nullptr && !result->isEmpty()) ? string2IC("macIterationCount"_s, result) : PKCS12KeyStore::DEFAULT_MAC_ITERATION_COUNT;
}

int32_t PKCS12KeyStore::string2IC($String* type, $String* value) {
	$init(PKCS12KeyStore);
	$useLocalCurrentObjectStackCache();
	int32_t number = 0;
	try {
		number = $Integer::parseInt(value);
	} catch ($NumberFormatException& e) {
		$throwNew($IllegalArgumentException, $$str({"keystore.pkcs12."_s, type, " is not a number: "_s, value}));
	}
	if (number <= 0 || number > PKCS12KeyStore::MAX_ITERATION_COUNT) {
		$throwNew($IllegalArgumentException, $$str({"Invalid keystore.pkcs12."_s, type, ": "_s, value}));
	}
	return number;
}

$Void* PKCS12KeyStore::lambda$engineLoad$2($Mac* m, $PBEParameterSpec* params, $bytes* authSafeData, int32_t ic, $MacData* macData, $chars* pass) {
	$useLocalCurrentObjectStackCache();
	$var($SecretKey, key, getPBEKey(pass));
	{
		$var($Throwable, var$0, nullptr);
		try {
			$nc(m)->init(key, params);
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			destroyPBEKey(key);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	$nc(m)->update(authSafeData);
	$var($bytes, macResult, m->doFinal());
	if (PKCS12KeyStore::debug != nullptr) {
		$nc(PKCS12KeyStore::debug)->println($$str({"Checking keystore integrity ("_s, $(m->getAlgorithm()), " iterations: "_s, $$str(ic), ")"_s}));
	}
	if (!$MessageDigest::isEqual($($nc(macData)->getDigest()), macResult)) {
		$throwNew($UnrecoverableKeyException, "Failed PKCS12 integrity checking"_s);
	}
	return ($Void*)nullptr;
}

$Object* PKCS12KeyStore::lambda$engineLoad$1($ObjectIdentifier* algOid, $AlgorithmParameters* algParams, $bytes* rawData, $chars* pass) {
	$useLocalCurrentObjectStackCache();
	$var($Cipher, cipher, $Cipher::getInstance($(mapPBEParamsToAlgorithm(algOid, algParams))));
	$var($SecretKey, skey, getPBEKey(pass));
	{
		$var($Throwable, var$0, nullptr);
		try {
			$nc(cipher)->init($Cipher::DECRYPT_MODE, static_cast<$Key*>(skey), algParams);
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			destroyPBEKey(skey);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	loadSafeContents($$new($DerInputStream, $($nc(cipher)->doFinal(rawData))));
	return $of(nullptr);
}

$Key* PKCS12KeyStore::lambda$engineGetKey$0($ObjectIdentifier* algOid, $AlgorithmParameters* algParams, $bytes* encryptedKey, $PKCS12KeyStore$Entry* entry, $String* alias, int32_t ic, $chars* pass) {
	$useLocalCurrentObjectStackCache();
	$var($Cipher, cipher, $Cipher::getInstance($(mapPBEParamsToAlgorithm(algOid, algParams))));
	$var($SecretKey, skey, getPBEKey(pass));
	{
		$var($Throwable, var$0, nullptr);
		try {
			$nc(cipher)->init($Cipher::DECRYPT_MODE, static_cast<$Key*>(skey), algParams);
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			destroyPBEKey(skey);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	$var($bytes, keyInfo, $nc(cipher)->doFinal(encryptedKey));
	$var($DerValue, val, $new($DerValue, keyInfo));
	{
		$var($Throwable, var$2, nullptr);
		$var($Key, var$4, nullptr);
		bool return$3 = false;
		try {
			$var($DerInputStream, in, val->toDerInputStream());
			int32_t i = $nc(in)->getInteger();
			$var($DerValueArray, value, in->getSequence(2));
			if ($nc(value)->length < 1 || $nc(value)->length > 2) {
				$throwNew($IOException, "Invalid length for AlgorithmIdentifier"_s);
			}
			$var($AlgorithmId, algId, $new($AlgorithmId, $($nc($nc(value)->get(0))->getOID())));
			$var($String, keyAlgo, algId->getName());
			if ($instanceOf($PKCS12KeyStore$PrivateKeyEntry, entry)) {
				$var($KeyFactory, kfac, $KeyFactory::getInstance(keyAlgo));
				$var($PKCS8EncodedKeySpec, kspec, $new($PKCS8EncodedKeySpec, keyInfo));
				{
					$var($Throwable, var$5, nullptr);
					$var($Key, var$7, nullptr);
					bool return$6 = false;
					try {
						$var($Key, tmp, $nc(kfac)->generatePrivate(kspec));
						if (PKCS12KeyStore::debug != nullptr) {
							$nc(PKCS12KeyStore::debug)->println($$str({"Retrieved a protected private key at alias \'"_s, alias, "\' ("_s, $(mapPBEParamsToAlgorithm(algOid, algParams)), " iterations: "_s, $$str(ic), ")"_s}));
						}
						$assign(var$7, tmp);
						return$6 = true;
						goto $finally2;
					} catch ($Throwable& var$8) {
						$assign(var$5, var$8);
					} $finally2: {
						$nc($($SharedSecrets::getJavaSecuritySpecAccess()))->clearEncodedKeySpec(kspec);
					}
					if (var$5 != nullptr) {
						$throw(var$5);
					}
					if (return$6) {
						$assign(var$4, var$7);
						return$3 = true;
						goto $finally1;
					}
				}
			} else {
				$var($bytes, keyBytes, in->getOctetString());
				$var($SecretKeySpec, secretKeySpec, $new($SecretKeySpec, keyBytes, keyAlgo));
				{
					$var($Throwable, var$9, nullptr);
					$var($Key, var$11, nullptr);
					bool return$10 = false;
					try {
						$var($Key, tmp, nullptr);
						if ($nc(keyAlgo)->startsWith("PBE"_s)) {
							$var($SecretKeyFactory, sKeyFactory, $SecretKeyFactory::getInstance(keyAlgo));
							$load($PBEKeySpec);
							$var($KeySpec, pbeKeySpec, $nc(sKeyFactory)->getKeySpec(secretKeySpec, $PBEKeySpec::class$));
							{
								$var($Throwable, var$12, nullptr);
								try {
									$assign(tmp, sKeyFactory->generateSecret(pbeKeySpec));
								} catch ($Throwable& var$13) {
									$assign(var$12, var$13);
								} /*finally*/ {
									$nc(($cast($PBEKeySpec, pbeKeySpec)))->clearPassword();
									$nc($($SharedSecrets::getJavaxCryptoSpecAccess()))->clearSecretKeySpec(secretKeySpec);
								}
								if (var$12 != nullptr) {
									$throw(var$12);
								}
							}
						} else {
							$assign(tmp, secretKeySpec);
						}
						if (PKCS12KeyStore::debug != nullptr) {
							$nc(PKCS12KeyStore::debug)->println($$str({"Retrieved a protected secret key at alias \'"_s, alias, "\' ("_s, $(mapPBEParamsToAlgorithm(algOid, algParams)), " iterations: "_s, $$str(ic), ")"_s}));
						}
						$assign(var$11, tmp);
						return$10 = true;
						goto $finally3;
					} catch ($Throwable& var$14) {
						$assign(var$9, var$14);
					} $finally3: {
						$Arrays::fill(keyBytes, (int8_t)0);
					}
					if (var$9 != nullptr) {
						$throw(var$9);
					}
					if (return$10) {
						$assign(var$4, var$11);
						return$3 = true;
						goto $finally1;
					}
				}
			}
		} catch ($Throwable& var$15) {
			$assign(var$2, var$15);
		} $finally1: {
			val->clear();
			$Arrays::fill(keyInfo, (int8_t)0);
		}
		if (var$2 != nullptr) {
			$throw(var$2);
		}
		if (return$3) {
			return var$4;
		}
	}
	$shouldNotReachHere();
}

void clinit$PKCS12KeyStore($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(PKCS12KeyStore::DEFAULT_CERT_PBE_ALGORITHM, "PBEWithHmacSHA256AndAES_256"_s);
	$assignStatic(PKCS12KeyStore::DEFAULT_KEY_PBE_ALGORITHM, "PBEWithHmacSHA256AndAES_256"_s);
	$assignStatic(PKCS12KeyStore::DEFAULT_MAC_ALGORITHM, "HmacPBESHA256"_s);
	$assignStatic(PKCS12KeyStore::LEGACY_CERT_PBE_ALGORITHM, "PBEWithSHA1AndRC2_40"_s);
	$assignStatic(PKCS12KeyStore::LEGACY_KEY_PBE_ALGORITHM, "PBEWithSHA1AndDESede"_s);
	$assignStatic(PKCS12KeyStore::LEGACY_MAC_ALGORITHM, "HmacPBESHA1"_s);
	$assignStatic(PKCS12KeyStore::USE_LEGACY_PROP, "keystore.pkcs12.legacy"_s);
	$init($KnownOIDs);
	$assignStatic(PKCS12KeyStore::CORE_ATTRIBUTES, $new($KnownOIDsArray, {
		$KnownOIDs::FriendlyName,
		$KnownOIDs::LocalKeyID,
		$KnownOIDs::ORACLE_TrustedKeyUsage
	}));
	$assignStatic(PKCS12KeyStore::debug, $Debug::getInstance("pkcs12"_s));
	$assignStatic(PKCS12KeyStore::PKCS8ShroudedKeyBag_OID, $ObjectIdentifier::of($KnownOIDs::PKCS8ShroudedKeyBag));
	$assignStatic(PKCS12KeyStore::CertBag_OID, $ObjectIdentifier::of($KnownOIDs::CertBag));
	$assignStatic(PKCS12KeyStore::SecretBag_OID, $ObjectIdentifier::of($KnownOIDs::SecretBag));
	$assignStatic(PKCS12KeyStore::PKCS9FriendlyName_OID, $ObjectIdentifier::of($KnownOIDs::FriendlyName));
	$assignStatic(PKCS12KeyStore::PKCS9LocalKeyId_OID, $ObjectIdentifier::of($KnownOIDs::LocalKeyID));
	$assignStatic(PKCS12KeyStore::PKCS9CertType_OID, $ObjectIdentifier::of($KnownOIDs::CertTypeX509));
	$assignStatic(PKCS12KeyStore::pbes2_OID, $ObjectIdentifier::of($KnownOIDs::PBES2));
	$assignStatic(PKCS12KeyStore::TrustedKeyUsage_OID, $ObjectIdentifier::of($KnownOIDs::ORACLE_TrustedKeyUsage));
	$assignStatic(PKCS12KeyStore::AnyUsage, $new($ObjectIdentifierArray, {$($ObjectIdentifier::of($KnownOIDs::anyExtendedKeyUsage))}));
	$assignStatic(PKCS12KeyStore::PKCS12_HEADER_PATTERNS, $new($longArray2, {
		$$new($longs, {
			(int64_t)0x3080020103308006,
			(int64_t)0x092A864886F70D01,
			(int64_t)0x0701A08024800400
		}),
		$$new($longs, {
			(int64_t)0x3082000002010330,
			(int64_t)0x82000006092A8648,
			(int64_t)0x86F70D010701A080
		}),
		$$new($longs, {
			(int64_t)0x3000020103300006,
			(int64_t)0x092A864886F70D01,
			(int64_t)0x0701A00004000000
		}),
		$$new($longs, {
			(int64_t)0x3081000201033081,
			(int64_t)0x0006092A864886F7,
			(int64_t)0x0D010701A0810004
		}),
		$$new($longs, {
			(int64_t)0x3082000002010330,
			(int64_t)0x810006092A864886,
			(int64_t)0xF70D010701A08100
		}),
		$$new($longs, {
			(int64_t)0x3083000000020103,
			(int64_t)0x3082000006092A86,
			(int64_t)0x4886F70D010701A0
		}),
		$$new($longs, {
			(int64_t)0x3083000000020103,
			(int64_t)0x308300000006092A,
			(int64_t)0x864886F70D010701
		}),
		$$new($longs, {
			(int64_t)0x3084000000000201,
			(int64_t)0x0330830000000609,
			(int64_t)0x2A864886F70D0107
		}),
		$$new($longs, {
			(int64_t)0x3084000000000201,
			(int64_t)0x0330840000000006,
			(int64_t)0x092A864886F70D01
		})
	}));
	$assignStatic(PKCS12KeyStore::PKCS12_HEADER_MASKS, $new($longArray2, {
		$$new($longs, {
			(int64_t)-1,
			(int64_t)-1,
			(int64_t)-256
		}),
		$$new($longs, {
			(int64_t)0xFFFF0000FFFFFFFF,
			(int64_t)0xFF0000FFFFFFFFFF,
			(int64_t)-16
		}),
		$$new($longs, {
			(int64_t)0xFF00FFFFFFFF00FF,
			(int64_t)-1,
			(int64_t)0xFFFFFF00FF000000
		}),
		$$new($longs, {
			(int64_t)0xFFFF00FFFFFFFFFF,
			(int64_t)0x00FFFFFFFFFFFFFF,
			(int64_t)-65281
		}),
		$$new($longs, {
			(int64_t)0xFFFF0000FFFFFFFF,
			(int64_t)0xFF00FFFFFFFFFFFF,
			(int64_t)-256
		}),
		$$new($longs, {
			(int64_t)0xFFFF000000FFFFFF,
			(int64_t)0xFFFF0000FFFFFFFF,
			(int64_t)-1
		}),
		$$new($longs, {
			(int64_t)0xFFFF000000FFFFFF,
			(int64_t)0xFFFF000000FFFFFF,
			(int64_t)-1
		}),
		$$new($longs, {
			(int64_t)0xFFFF00000000FFFF,
			(int64_t)0xFFFFFF000000FFFF,
			(int64_t)-1
		}),
		$$new($longs, {
			(int64_t)0xFFFF00000000FFFF,
			(int64_t)0xFFFFFF00000000FF,
			(int64_t)-1
		})
	}));
}

PKCS12KeyStore::PKCS12KeyStore() {
}

$Class* PKCS12KeyStore::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(PKCS12KeyStore$$Lambda$lambda$engineGetKey$0::classInfo$.name)) {
			return PKCS12KeyStore$$Lambda$lambda$engineGetKey$0::load$(name, initialize);
		}
		if (name->equals(PKCS12KeyStore$$Lambda$lambda$engineLoad$1$1::classInfo$.name)) {
			return PKCS12KeyStore$$Lambda$lambda$engineLoad$1$1::load$(name, initialize);
		}
		if (name->equals(PKCS12KeyStore$$Lambda$lambda$engineLoad$2$2::classInfo$.name)) {
			return PKCS12KeyStore$$Lambda$lambda$engineLoad$2$2::load$(name, initialize);
		}
	}
	$loadClass(PKCS12KeyStore, name, initialize, &_PKCS12KeyStore_ClassInfo_, clinit$PKCS12KeyStore, allocate$PKCS12KeyStore);
	return class$;
}

$Class* PKCS12KeyStore::class$ = nullptr;

		} // pkcs12
	} // security
} // sun