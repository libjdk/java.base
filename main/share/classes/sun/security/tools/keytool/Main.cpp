#include <sun/security/tools/keytool/Main.h>

#include <java/io/BufferedReader.h>
#include <java/io/ByteArrayInputStream.h>
#include <java/io/ByteArrayOutputStream.h>
#include <java/io/Console.h>
#include <java/io/File.h>
#include <java/io/FileInputStream.h>
#include <java/io/FileNotFoundException.h>
#include <java/io/FileOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/InputStreamReader.h>
#include <java/io/OutputStream.h>
#include <java/io/Reader.h>
#include <java/io/Serializable.h>
#include <java/lang/ClassCastException.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/Enum.h>
#include <java/lang/NumberFormatException.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/math/BigInteger.h>
#include <java/net/URI.h>
#include <java/net/URL.h>
#include <java/net/URLClassLoader.h>
#include <java/nio/file/CopyOption.h>
#include <java/nio/file/Files.h>
#include <java/nio/file/Path.h>
#include <java/security/AlgorithmParameters.h>
#include <java/security/CodeSigner.h>
#include <java/security/CryptoPrimitive.h>
#include <java/security/Key.h>
#include <java/security/KeyStore$Entry.h>
#include <java/security/KeyStore$PasswordProtection.h>
#include <java/security/KeyStore$PrivateKeyEntry.h>
#include <java/security/KeyStore$ProtectionParameter.h>
#include <java/security/KeyStore$SecretKeyEntry.h>
#include <java/security/KeyStore$TrustedCertificateEntry.h>
#include <java/security/KeyStore.h>
#include <java/security/KeyStoreException.h>
#include <java/security/MessageDigest.h>
#include <java/security/Principal.h>
#include <java/security/PrivateKey.h>
#include <java/security/Provider.h>
#include <java/security/PublicKey.h>
#include <java/security/SecureRandom.h>
#include <java/security/Security.h>
#include <java/security/Timestamp.h>
#include <java/security/UnrecoverableEntryException.h>
#include <java/security/UnrecoverableKeyException.h>
#include <java/security/cert/CRL.h>
#include <java/security/cert/CRLSelector.h>
#include <java/security/cert/CertPath.h>
#include <java/security/cert/CertSelector.h>
#include <java/security/cert/CertStore.h>
#include <java/security/cert/CertStoreException.h>
#include <java/security/cert/CertStoreParameters.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/CertificateException.h>
#include <java/security/cert/CertificateFactory.h>
#include <java/security/cert/URICertStoreParameters.h>
#include <java/security/cert/X509CRL.h>
#include <java/security/cert/X509CRLEntry.h>
#include <java/security/cert/X509CRLSelector.h>
#include <java/security/cert/X509Certificate.h>
#include <java/security/interfaces/ECKey.h>
#include <java/security/interfaces/EdECKey.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/security/spec/ECParameterSpec.h>
#include <java/security/spec/KeySpec.h>
#include <java/security/spec/NamedParameterSpec.h>
#include <java/text/Collator.h>
#include <java/text/MessageFormat.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Base64$Encoder.h>
#include <java/util/Base64.h>
#include <java/util/Calendar.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Comparator.h>
#include <java/util/Date.h>
#include <java/util/EnumSet.h>
#include <java/util/Enumeration.h>
#include <java/util/GregorianCalendar.h>
#include <java/util/HashSet.h>
#include <java/util/Hashtable.h>
#include <java/util/HexFormat.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/Map.h>
#include <java/util/Random.h>
#include <java/util/ResourceBundle.h>
#include <java/util/Set.h>
#include <java/util/Vector.h>
#include <java/util/function/BiFunction.h>
#include <java/util/function/Predicate.h>
#include <java/util/jar/JarEntry.h>
#include <java/util/jar/JarFile.h>
#include <java/util/stream/Stream.h>
#include <java/util/zip/ZipEntry.h>
#include <javax/crypto/KeyGenerator.h>
#include <javax/crypto/SecretKey.h>
#include <javax/crypto/SecretKeyFactory.h>
#include <javax/crypto/spec/PBEKeySpec.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <sun/security/pkcs/PKCS9Attribute.h>
#include <sun/security/pkcs10/PKCS10.h>
#include <sun/security/pkcs10/PKCS10Attribute.h>
#include <sun/security/pkcs10/PKCS10Attributes.h>
#include <sun/security/pkcs12/PKCS12KeyStore.h>
#include <sun/security/provider/X509Factory.h>
#include <sun/security/provider/certpath/ssl/SSLServerCertStore.h>
#include <sun/security/tools/KeyStoreUtil.h>
#include <sun/security/tools/PathList.h>
#include <sun/security/tools/keytool/CertAndKeyGen.h>
#include <sun/security/tools/keytool/Main$Command.h>
#include <sun/security/tools/keytool/Main$Option.h>
#include <sun/security/tools/keytool/Pair.h>
#include <sun/security/tools/keytool/ShowInfo.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/DisabledAlgorithmConstraints.h>
#include <sun/security/util/ECKeySizeParameterSpec.h>
#include <sun/security/util/HexDumpEncoder.h>
#include <sun/security/util/KeyUtil.h>
#include <sun/security/util/KnownOIDs.h>
#include <sun/security/util/NamedCurve.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <sun/security/util/Password.h>
#include <sun/security/util/Pem.h>
#include <sun/security/util/SecurityProperties.h>
#include <sun/security/util/SecurityProviderConstants.h>
#include <sun/security/util/SignatureUtil.h>
#include <sun/security/x509/AccessDescription.h>
#include <sun/security/x509/AlgorithmId.h>
#include <sun/security/x509/AuthorityInfoAccessExtension.h>
#include <sun/security/x509/AuthorityKeyIdentifierExtension.h>
#include <sun/security/x509/BasicConstraintsExtension.h>
#include <sun/security/x509/CRLDistributionPointsExtension.h>
#include <sun/security/x509/CRLExtensions.h>
#include <sun/security/x509/CRLReasonCodeExtension.h>
#include <sun/security/x509/CertificateExtensions.h>
#include <sun/security/x509/CertificateSerialNumber.h>
#include <sun/security/x509/CertificateValidity.h>
#include <sun/security/x509/CertificateVersion.h>
#include <sun/security/x509/CertificateX509Key.h>
#include <sun/security/x509/DNSName.h>
#include <sun/security/x509/DistributionPoint.h>
#include <sun/security/x509/ExtendedKeyUsageExtension.h>
#include <sun/security/x509/Extension.h>
#include <sun/security/x509/GeneralName.h>
#include <sun/security/x509/GeneralNameInterface.h>
#include <sun/security/x509/GeneralNames.h>
#include <sun/security/x509/IPAddressName.h>
#include <sun/security/x509/IssuerAlternativeNameExtension.h>
#include <sun/security/x509/KeyIdentifier.h>
#include <sun/security/x509/KeyUsageExtension.h>
#include <sun/security/x509/OIDName.h>
#include <sun/security/x509/PKIXExtensions.h>
#include <sun/security/x509/RFC822Name.h>
#include <sun/security/x509/SerialNumber.h>
#include <sun/security/x509/SubjectAlternativeNameExtension.h>
#include <sun/security/x509/SubjectInfoAccessExtension.h>
#include <sun/security/x509/SubjectKeyIdentifierExtension.h>
#include <sun/security/x509/URIName.h>
#include <sun/security/x509/X500Name.h>
#include <sun/security/x509/X509CRLEntryImpl.h>
#include <sun/security/x509/X509CRLImpl.h>
#include <sun/security/x509/X509CertImpl.h>
#include <sun/security/x509/X509CertInfo.h>
#include <jcpp.h>

#undef BEGIN_CERT
#undef CERTREQ
#undef CHANGEALIAS
#undef CRLF
#undef DATE
#undef DEF_DH_KEY_SIZE
#undef DEF_DSA_KEY_SIZE
#undef DEF_EC_KEY_SIZE
#undef DEF_ED_KEY_SIZE
#undef DEF_RSA_KEY_SIZE
#undef DEF_XEC_KEY_SIZE
#undef DELETE
#undef DISABLED_CHECK
#undef DN_NAME
#undef END_CERT
#undef ENGLISH
#undef EXPORTCERT
#undef EXTENSIONS
#undef EXTENSION_REQUEST_OID
#undef GENCERT
#undef GENCRL
#undef GENKEYPAIR
#undef GENSECKEY
#undef HOUR
#undef HOUR_OF_DAY
#undef IDENTITYDB
#undef IMPORTCERT
#undef IMPORTKEYSTORE
#undef IMPORTPASS
#undef INFO
#undef ISSUER
#undef KEY
#undef KEYCLONE
#undef KEYPASSWD
#undef LEGACY_CHECK
#undef LIST
#undef MAX_VALUE
#undef MILLISECOND
#undef MINUTE
#undef MONTH
#undef NAME
#undef NAME_URI
#undef NONE
#undef OCSP
#undef P11KEYSTORE
#undef P12KEYSTORE
#undef POINTS
#undef PRIMARY
#undef PRINTCERT
#undef PRINTCERTREQ
#undef PRINTCRL
#undef PROPERTY_CERTPATH_DISABLED_ALGS
#undef PROPERTY_JAR_DISABLED_ALGS
#undef PROPERTY_SECURITY_LEGACY_ALGS
#undef ROOT
#undef SECOND
#undef SELFCERT
#undef SERIAL_NUMBER
#undef SHOWINFO
#undef SIGNATURE
#undef SIG_PRIMITIVE_SET
#undef STOREPASSWD
#undef SUBJECT
#undef VALIDITY
#undef VERSION
#undef YEAR

using $URLArray = $Array<::java::net::URL>;
using $CopyOptionArray = $Array<::java::nio::file::CopyOption>;
using $CodeSignerArray = $Array<::java::security::CodeSigner>;
using $CertificateArray = $Array<::java::security::cert::Certificate>;
using $X509CRLEntryArray = $Array<::java::security::cert::X509CRLEntry>;
using $X509CertificateArray = $Array<::java::security::cert::X509Certificate>;
using $Main$CommandArray = $Array<::sun::security::tools::keytool::Main$Command>;
using $Main$OptionArray = $Array<::sun::security::tools::keytool::Main$Option>;
using $KnownOIDsArray = $Array<::sun::security::util::KnownOIDs>;
using $BufferedReader = ::java::io::BufferedReader;
using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $File = ::java::io::File;
using $FileInputStream = ::java::io::FileInputStream;
using $FileNotFoundException = ::java::io::FileNotFoundException;
using $FileOutputStream = ::java::io::FileOutputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $InputStreamReader = ::java::io::InputStreamReader;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $Reader = ::java::io::Reader;
using $Serializable = ::java::io::Serializable;
using $Boolean = ::java::lang::Boolean;
using $ClassCastException = ::java::lang::ClassCastException;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $Enum = ::java::lang::Enum;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $RuntimeException = ::java::lang::RuntimeException;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $BigInteger = ::java::math::BigInteger;
using $URI = ::java::net::URI;
using $URL = ::java::net::URL;
using $URLClassLoader = ::java::net::URLClassLoader;
using $Files = ::java::nio::file::Files;
using $Path = ::java::nio::file::Path;
using $AlgorithmParameters = ::java::security::AlgorithmParameters;
using $CodeSigner = ::java::security::CodeSigner;
using $CryptoPrimitive = ::java::security::CryptoPrimitive;
using $Key = ::java::security::Key;
using $KeyStore = ::java::security::KeyStore;
using $KeyStore$Entry = ::java::security::KeyStore$Entry;
using $KeyStore$PasswordProtection = ::java::security::KeyStore$PasswordProtection;
using $KeyStore$PrivateKeyEntry = ::java::security::KeyStore$PrivateKeyEntry;
using $KeyStore$ProtectionParameter = ::java::security::KeyStore$ProtectionParameter;
using $KeyStore$SecretKeyEntry = ::java::security::KeyStore$SecretKeyEntry;
using $KeyStore$TrustedCertificateEntry = ::java::security::KeyStore$TrustedCertificateEntry;
using $KeyStoreException = ::java::security::KeyStoreException;
using $MessageDigest = ::java::security::MessageDigest;
using $Principal = ::java::security::Principal;
using $PrivateKey = ::java::security::PrivateKey;
using $Provider = ::java::security::Provider;
using $PublicKey = ::java::security::PublicKey;
using $SecureRandom = ::java::security::SecureRandom;
using $Security = ::java::security::Security;
using $Timestamp = ::java::security::Timestamp;
using $UnrecoverableEntryException = ::java::security::UnrecoverableEntryException;
using $UnrecoverableKeyException = ::java::security::UnrecoverableKeyException;
using $CRL = ::java::security::cert::CRL;
using $CRLSelector = ::java::security::cert::CRLSelector;
using $CertPath = ::java::security::cert::CertPath;
using $CertSelector = ::java::security::cert::CertSelector;
using $CertStore = ::java::security::cert::CertStore;
using $CertStoreException = ::java::security::cert::CertStoreException;
using $CertStoreParameters = ::java::security::cert::CertStoreParameters;
using $Certificate = ::java::security::cert::Certificate;
using $CertificateException = ::java::security::cert::CertificateException;
using $CertificateFactory = ::java::security::cert::CertificateFactory;
using $URICertStoreParameters = ::java::security::cert::URICertStoreParameters;
using $X509CRL = ::java::security::cert::X509CRL;
using $X509CRLEntry = ::java::security::cert::X509CRLEntry;
using $X509CRLSelector = ::java::security::cert::X509CRLSelector;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $ECKey = ::java::security::interfaces::ECKey;
using $EdECKey = ::java::security::interfaces::EdECKey;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $ECParameterSpec = ::java::security::spec::ECParameterSpec;
using $KeySpec = ::java::security::spec::KeySpec;
using $NamedParameterSpec = ::java::security::spec::NamedParameterSpec;
using $Collator = ::java::text::Collator;
using $MessageFormat = ::java::text::MessageFormat;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Base64 = ::java::util::Base64;
using $Base64$Encoder = ::java::util::Base64$Encoder;
using $Calendar = ::java::util::Calendar;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Comparator = ::java::util::Comparator;
using $Date = ::java::util::Date;
using $EnumSet = ::java::util::EnumSet;
using $Enumeration = ::java::util::Enumeration;
using $GregorianCalendar = ::java::util::GregorianCalendar;
using $HashSet = ::java::util::HashSet;
using $Hashtable = ::java::util::Hashtable;
using $HexFormat = ::java::util::HexFormat;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $Random = ::java::util::Random;
using $ResourceBundle = ::java::util::ResourceBundle;
using $Set = ::java::util::Set;
using $Vector = ::java::util::Vector;
using $BiFunction = ::java::util::function::BiFunction;
using $Predicate = ::java::util::function::Predicate;
using $JarEntry = ::java::util::jar::JarEntry;
using $JarFile = ::java::util::jar::JarFile;
using $Stream = ::java::util::stream::Stream;
using $ZipEntry = ::java::util::zip::ZipEntry;
using $KeyGenerator = ::javax::crypto::KeyGenerator;
using $SecretKey = ::javax::crypto::SecretKey;
using $SecretKeyFactory = ::javax::crypto::SecretKeyFactory;
using $PBEKeySpec = ::javax::crypto::spec::PBEKeySpec;
using $X500Principal = ::javax::security::auth::x500::X500Principal;
using $PKCS9Attribute = ::sun::security::pkcs::PKCS9Attribute;
using $PKCS10 = ::sun::security::pkcs10::PKCS10;
using $PKCS10Attribute = ::sun::security::pkcs10::PKCS10Attribute;
using $PKCS10Attributes = ::sun::security::pkcs10::PKCS10Attributes;
using $PKCS12KeyStore = ::sun::security::pkcs12::PKCS12KeyStore;
using $X509Factory = ::sun::security::provider::X509Factory;
using $SSLServerCertStore = ::sun::security::provider::certpath::ssl::SSLServerCertStore;
using $KeyStoreUtil = ::sun::security::tools::KeyStoreUtil;
using $PathList = ::sun::security::tools::PathList;
using $CertAndKeyGen = ::sun::security::tools::keytool::CertAndKeyGen;
using $Main$Command = ::sun::security::tools::keytool::Main$Command;
using $Main$Option = ::sun::security::tools::keytool::Main$Option;
using $Pair = ::sun::security::tools::keytool::Pair;
using $ShowInfo = ::sun::security::tools::keytool::ShowInfo;
using $DerValue = ::sun::security::util::DerValue;
using $DisabledAlgorithmConstraints = ::sun::security::util::DisabledAlgorithmConstraints;
using $ECKeySizeParameterSpec = ::sun::security::util::ECKeySizeParameterSpec;
using $HexDumpEncoder = ::sun::security::util::HexDumpEncoder;
using $KeyUtil = ::sun::security::util::KeyUtil;
using $KnownOIDs = ::sun::security::util::KnownOIDs;
using $NamedCurve = ::sun::security::util::NamedCurve;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;
using $Password = ::sun::security::util::Password;
using $Pem = ::sun::security::util::Pem;
using $SecurityProperties = ::sun::security::util::SecurityProperties;
using $SecurityProviderConstants = ::sun::security::util::SecurityProviderConstants;
using $SignatureUtil = ::sun::security::util::SignatureUtil;
using $AccessDescription = ::sun::security::x509::AccessDescription;
using $AuthorityInfoAccessExtension = ::sun::security::x509::AuthorityInfoAccessExtension;
using $AuthorityKeyIdentifierExtension = ::sun::security::x509::AuthorityKeyIdentifierExtension;
using $BasicConstraintsExtension = ::sun::security::x509::BasicConstraintsExtension;
using $CRLDistributionPointsExtension = ::sun::security::x509::CRLDistributionPointsExtension;
using $CRLExtensions = ::sun::security::x509::CRLExtensions;
using $CRLReasonCodeExtension = ::sun::security::x509::CRLReasonCodeExtension;
using $CertificateExtensions = ::sun::security::x509::CertificateExtensions;
using $CertificateSerialNumber = ::sun::security::x509::CertificateSerialNumber;
using $CertificateValidity = ::sun::security::x509::CertificateValidity;
using $CertificateVersion = ::sun::security::x509::CertificateVersion;
using $CertificateX509Key = ::sun::security::x509::CertificateX509Key;
using $DNSName = ::sun::security::x509::DNSName;
using $DistributionPoint = ::sun::security::x509::DistributionPoint;
using $ExtendedKeyUsageExtension = ::sun::security::x509::ExtendedKeyUsageExtension;
using $Extension = ::sun::security::x509::Extension;
using $GeneralName = ::sun::security::x509::GeneralName;
using $GeneralNameInterface = ::sun::security::x509::GeneralNameInterface;
using $GeneralNames = ::sun::security::x509::GeneralNames;
using $IPAddressName = ::sun::security::x509::IPAddressName;
using $IssuerAlternativeNameExtension = ::sun::security::x509::IssuerAlternativeNameExtension;
using $KeyIdentifier = ::sun::security::x509::KeyIdentifier;
using $KeyUsageExtension = ::sun::security::x509::KeyUsageExtension;
using $OIDName = ::sun::security::x509::OIDName;
using $PKIXExtensions = ::sun::security::x509::PKIXExtensions;
using $RFC822Name = ::sun::security::x509::RFC822Name;
using $SerialNumber = ::sun::security::x509::SerialNumber;
using $SubjectAlternativeNameExtension = ::sun::security::x509::SubjectAlternativeNameExtension;
using $SubjectInfoAccessExtension = ::sun::security::x509::SubjectInfoAccessExtension;
using $SubjectKeyIdentifierExtension = ::sun::security::x509::SubjectKeyIdentifierExtension;
using $URIName = ::sun::security::x509::URIName;
using $X500Name = ::sun::security::x509::X500Name;
using $X509CRLEntryImpl = ::sun::security::x509::X509CRLEntryImpl;
using $X509CRLImpl = ::sun::security::x509::X509CRLImpl;
using $X509CertImpl = ::sun::security::x509::X509CertImpl;
using $X509CertInfo = ::sun::security::x509::X509CertInfo;

namespace sun {
	namespace security {
		namespace tools {
			namespace keytool {

class Main$$Lambda$lambda$parseArgs$0 : public $Predicate {
	$class(Main$$Lambda$lambda$parseArgs$0, $NO_CLASS_INIT, $Predicate)
public:
	void init$() {
	}
	virtual bool test(Object$* x) override {
		 return Main::lambda$parseArgs$0($cast($String, x));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Main$$Lambda$lambda$parseArgs$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Main$$Lambda$lambda$parseArgs$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Main$$Lambda$lambda$parseArgs$0, init$, void)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(Main$$Lambda$lambda$parseArgs$0, test, bool, Object$*)},
	{}
};
$ClassInfo Main$$Lambda$lambda$parseArgs$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.security.tools.keytool.Main$$Lambda$lambda$parseArgs$0",
	"java.lang.Object",
	"java.util.function.Predicate",
	nullptr,
	methodInfos
};
$Class* Main$$Lambda$lambda$parseArgs$0::load$($String* name, bool initialize) {
	$loadClass(Main$$Lambda$lambda$parseArgs$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Main$$Lambda$lambda$parseArgs$0::class$ = nullptr;

class Main$$Lambda$compareTo$1 : public $Comparator {
	$class(Main$$Lambda$compareTo$1, $NO_CLASS_INIT, $Comparator)
public:
	void init$() {
	}
	virtual int32_t compare(Object$* inst$, Object$* anotherString) override {
		 return $sure($String, inst$)->compareTo($cast($String, anotherString));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Main$$Lambda$compareTo$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Main$$Lambda$compareTo$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Main$$Lambda$compareTo$1, init$, void)},
	{"compare", "(Ljava/lang/Object;Ljava/lang/Object;)I", nullptr, $PUBLIC, $virtualMethod(Main$$Lambda$compareTo$1, compare, int32_t, Object$*, Object$*)},
	{}
};
$ClassInfo Main$$Lambda$compareTo$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.security.tools.keytool.Main$$Lambda$compareTo$1",
	"java.lang.Object",
	"java.util.Comparator",
	nullptr,
	methodInfos
};
$Class* Main$$Lambda$compareTo$1::load$($String* name, bool initialize) {
	$loadClass(Main$$Lambda$compareTo$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Main$$Lambda$compareTo$1::class$ = nullptr;

class Main$$Lambda$lambda$oneOf$1$2 : public $BiFunction {
	$class(Main$$Lambda$lambda$oneOf$1$2, $NO_CLASS_INIT, $BiFunction)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* a, Object$* b) override {
		 return $of(Main::lambda$oneOf$1($cast($String, a), $cast($String, b)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Main$$Lambda$lambda$oneOf$1$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Main$$Lambda$lambda$oneOf$1$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Main$$Lambda$lambda$oneOf$1$2, init$, void)},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Main$$Lambda$lambda$oneOf$1$2, apply, $Object*, Object$*, Object$*)},
	{}
};
$ClassInfo Main$$Lambda$lambda$oneOf$1$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.security.tools.keytool.Main$$Lambda$lambda$oneOf$1$2",
	"java.lang.Object",
	"java.util.function.BiFunction",
	nullptr,
	methodInfos
};
$Class* Main$$Lambda$lambda$oneOf$1$2::load$($String* name, bool initialize) {
	$loadClass(Main$$Lambda$lambda$oneOf$1$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Main$$Lambda$lambda$oneOf$1$2::class$ = nullptr;

class Main$$Lambda$lambda$oneOf$2$3 : public $BiFunction {
	$class(Main$$Lambda$lambda$oneOf$2$3, $NO_CLASS_INIT, $BiFunction)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* a, Object$* b) override {
		 return $of(Main::lambda$oneOf$2($cast($String, a), $cast($String, b)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Main$$Lambda$lambda$oneOf$2$3>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Main$$Lambda$lambda$oneOf$2$3::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Main$$Lambda$lambda$oneOf$2$3, init$, void)},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Main$$Lambda$lambda$oneOf$2$3, apply, $Object*, Object$*, Object$*)},
	{}
};
$ClassInfo Main$$Lambda$lambda$oneOf$2$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.security.tools.keytool.Main$$Lambda$lambda$oneOf$2$3",
	"java.lang.Object",
	"java.util.function.BiFunction",
	nullptr,
	methodInfos
};
$Class* Main$$Lambda$lambda$oneOf$2$3::load$($String* name, bool initialize) {
	$loadClass(Main$$Lambda$lambda$oneOf$2$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Main$$Lambda$lambda$oneOf$2$3::class$ = nullptr;

class Main$$Lambda$lambda$oneOf$3$4 : public $BiFunction {
	$class(Main$$Lambda$lambda$oneOf$3$4, $NO_CLASS_INIT, $BiFunction)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* a, Object$* b) override {
		 return $of(Main::lambda$oneOf$3($cast($String, a), $cast($String, b)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Main$$Lambda$lambda$oneOf$3$4>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Main$$Lambda$lambda$oneOf$3$4::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Main$$Lambda$lambda$oneOf$3$4, init$, void)},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Main$$Lambda$lambda$oneOf$3$4, apply, $Object*, Object$*, Object$*)},
	{}
};
$ClassInfo Main$$Lambda$lambda$oneOf$3$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.security.tools.keytool.Main$$Lambda$lambda$oneOf$3$4",
	"java.lang.Object",
	"java.util.function.BiFunction",
	nullptr,
	methodInfos
};
$Class* Main$$Lambda$lambda$oneOf$3$4::load$($String* name, bool initialize) {
	$loadClass(Main$$Lambda$lambda$oneOf$3$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Main$$Lambda$lambda$oneOf$3$4::class$ = nullptr;

$FieldInfo _Main_FieldInfo_[] = {
	{"CRLF", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Main, CRLF)},
	{"debug", "Z", nullptr, $PRIVATE, $field(Main, debug)},
	{"command", "Lsun/security/tools/keytool/Main$Command;", nullptr, $PRIVATE, $field(Main, command)},
	{"sigAlgName", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Main, sigAlgName)},
	{"keyAlgName", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Main, keyAlgName)},
	{"verbose", "Z", nullptr, $PRIVATE, $field(Main, verbose)},
	{"keysize", "I", nullptr, $PRIVATE, $field(Main, keysize)},
	{"groupName", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Main, groupName)},
	{"rfc", "Z", nullptr, $PRIVATE, $field(Main, rfc)},
	{"validity", "J", nullptr, $PRIVATE, $field(Main, validity)},
	{"alias", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Main, alias)},
	{"dname", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Main, dname)},
	{"dest", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Main, dest)},
	{"filename", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Main, filename)},
	{"infilename", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Main, infilename)},
	{"outfilename", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Main, outfilename)},
	{"srcksfname", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Main, srcksfname)},
	{"providers", "Ljava/util/Set;", "Ljava/util/Set<Lsun/security/tools/keytool/Pair<Ljava/lang/String;Ljava/lang/String;>;>;", $PRIVATE, $field(Main, providers)},
	{"providerClasses", "Ljava/util/Set;", "Ljava/util/Set<Lsun/security/tools/keytool/Pair<Ljava/lang/String;Ljava/lang/String;>;>;", $PRIVATE, $field(Main, providerClasses)},
	{"storetype", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Main, storetype)},
	{"srcProviderName", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Main, srcProviderName)},
	{"providerName", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Main, providerName)},
	{"pathlist", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Main, pathlist)},
	{"storePass", "[C", nullptr, $PRIVATE, $field(Main, storePass)},
	{"storePassNew", "[C", nullptr, $PRIVATE, $field(Main, storePassNew)},
	{"keyPass", "[C", nullptr, $PRIVATE, $field(Main, keyPass)},
	{"keyPassNew", "[C", nullptr, $PRIVATE, $field(Main, keyPassNew)},
	{"newPass", "[C", nullptr, $PRIVATE, $field(Main, newPass)},
	{"destKeyPass", "[C", nullptr, $PRIVATE, $field(Main, destKeyPass)},
	{"srckeyPass", "[C", nullptr, $PRIVATE, $field(Main, srckeyPass)},
	{"ksfname", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Main, ksfname)},
	{"ksfile", "Ljava/io/File;", nullptr, $PRIVATE, $field(Main, ksfile)},
	{"ksStream", "Ljava/io/InputStream;", nullptr, $PRIVATE, $field(Main, ksStream)},
	{"sslserver", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Main, sslserver)},
	{"jarfile", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Main, jarfile)},
	{"keyStore", "Ljava/security/KeyStore;", nullptr, $PRIVATE, $field(Main, keyStore)},
	{"token", "Z", nullptr, $PRIVATE, $field(Main, token)},
	{"nullStream", "Z", nullptr, $PRIVATE, $field(Main, nullStream)},
	{"kssave", "Z", nullptr, $PRIVATE, $field(Main, kssave)},
	{"noprompt", "Z", nullptr, $PRIVATE, $field(Main, noprompt)},
	{"trustcacerts", "Z", nullptr, $PRIVATE, $field(Main, trustcacerts)},
	{"protectedPath", "Z", nullptr, $PRIVATE, $field(Main, protectedPath)},
	{"srcprotectedPath", "Z", nullptr, $PRIVATE, $field(Main, srcprotectedPath)},
	{"cacerts", "Z", nullptr, $PRIVATE, $field(Main, cacerts)},
	{"nowarn", "Z", nullptr, $PRIVATE, $field(Main, nowarn)},
	{"caks", "Ljava/security/KeyStore;", nullptr, $PRIVATE, $field(Main, caks)},
	{"srcstorePass", "[C", nullptr, $PRIVATE, $field(Main, srcstorePass)},
	{"srcstoretype", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Main, srcstoretype)},
	{"passwords", "Ljava/util/Set;", "Ljava/util/Set<[C>;", $PRIVATE, $field(Main, passwords)},
	{"startDate", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Main, startDate)},
	{"signerAlias", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Main, signerAlias)},
	{"signerKeyPass", "[C", nullptr, $PRIVATE, $field(Main, signerKeyPass)},
	{"tlsInfo", "Z", nullptr, $PRIVATE, $field(Main, tlsInfo)},
	{"ids", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/String;>;", $PRIVATE, $field(Main, ids)},
	{"v3ext", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/String;>;", $PRIVATE, $field(Main, v3ext)},
	{"inplaceImport", "Z", nullptr, $PRIVATE, $field(Main, inplaceImport)},
	{"inplaceBackupName", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Main, inplaceBackupName)},
	{"weakWarnings", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/String;>;", $PRIVATE, $field(Main, weakWarnings)},
	{"DISABLED_CHECK", "Lsun/security/util/DisabledAlgorithmConstraints;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Main, DISABLED_CHECK)},
	{"LEGACY_CHECK", "Lsun/security/util/DisabledAlgorithmConstraints;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Main, LEGACY_CHECK)},
	{"SIG_PRIMITIVE_SET", "Ljava/util/Set;", "Ljava/util/Set<Ljava/security/CryptoPrimitive;>;", $PRIVATE | $STATIC | $FINAL, $staticField(Main, SIG_PRIMITIVE_SET)},
	{"isPasswordlessKeyStore", "Z", nullptr, $PRIVATE, $field(Main, isPasswordlessKeyStore)},
	{"NONE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Main, NONE)},
	{"P11KEYSTORE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Main, P11KEYSTORE)},
	{"P12KEYSTORE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Main, P12KEYSTORE)},
	{"keyAlias", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Main, keyAlias)},
	{"rb", "Ljava/util/ResourceBundle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Main, rb)},
	{"collator", "Ljava/text/Collator;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Main, collator)},
	{"extSupported", "[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Main, extSupported)},
	{}
};

$MethodInfo _Main_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(Main, init$, void)},
	{"addTrustedCert", "(Ljava/lang/String;Ljava/io/InputStream;)Z", nullptr, $PRIVATE, $method(Main, addTrustedCert, bool, $String*, $InputStream*), "java.lang.Exception"},
	{"buildChain", "(Lsun/security/tools/keytool/Pair;Ljava/util/Vector;Ljava/util/Hashtable;)Z", "(Lsun/security/tools/keytool/Pair<Ljava/lang/String;Ljava/security/cert/X509Certificate;>;Ljava/util/Vector<Lsun/security/tools/keytool/Pair<Ljava/lang/String;Ljava/security/cert/X509Certificate;>;>;Ljava/util/Hashtable<Ljava/security/Principal;Ljava/util/Vector<Lsun/security/tools/keytool/Pair<Ljava/lang/String;Ljava/security/cert/X509Certificate;>;>;>;)Z", $PRIVATE, $method(Main, buildChain, bool, $Pair*, $Vector*, $Hashtable*)},
	{"checkWeak", "(Ljava/lang/String;Ljava/lang/String;Ljava/security/Key;)V", nullptr, $PRIVATE, $method(Main, checkWeak, void, $String*, $String*, $Key*)},
	{"checkWeak", "(Ljava/lang/String;[Ljava/security/cert/Certificate;)V", nullptr, $PRIVATE, $method(Main, checkWeak, void, $String*, $CertificateArray*), "java.security.KeyStoreException"},
	{"checkWeak", "(Ljava/lang/String;Ljava/security/cert/Certificate;)V", nullptr, $PRIVATE, $method(Main, checkWeak, void, $String*, $Certificate*), "java.security.KeyStoreException"},
	{"checkWeak", "(Ljava/lang/String;Lsun/security/pkcs10/PKCS10;)V", nullptr, $PRIVATE, $method(Main, checkWeak, void, $String*, $PKCS10*)},
	{"checkWeak", "(Ljava/lang/String;Ljava/security/cert/CRL;Ljava/security/Key;)V", nullptr, $PRIVATE, $method(Main, checkWeak, void, $String*, $CRL*, $Key*)},
	{"createGeneralName", "(Ljava/lang/String;Ljava/lang/String;I)Lsun/security/x509/GeneralName;", nullptr, $PRIVATE, $method(Main, createGeneralName, $GeneralName*, $String*, $String*, int32_t), "java.lang.Exception"},
	{"createV3Extensions", "(Lsun/security/x509/CertificateExtensions;Lsun/security/x509/CertificateExtensions;Ljava/util/List;Ljava/security/PublicKey;Lsun/security/x509/KeyIdentifier;)Lsun/security/x509/CertificateExtensions;", "(Lsun/security/x509/CertificateExtensions;Lsun/security/x509/CertificateExtensions;Ljava/util/List<Ljava/lang/String;>;Ljava/security/PublicKey;Lsun/security/x509/KeyIdentifier;)Lsun/security/x509/CertificateExtensions;", $PRIVATE, $method(Main, createV3Extensions, $CertificateExtensions*, $CertificateExtensions*, $CertificateExtensions*, $List*, $PublicKey*, $KeyIdentifier*), "java.lang.Exception"},
	{"doCertReq", "(Ljava/lang/String;Ljava/lang/String;Ljava/io/PrintStream;)V", nullptr, $PRIVATE, $method(Main, doCertReq, void, $String*, $String*, $PrintStream*), "java.lang.Exception"},
	{"doChangeKeyPasswd", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(Main, doChangeKeyPasswd, void, $String*), "java.lang.Exception"},
	{"doChangeStorePasswd", "()V", nullptr, $PRIVATE, $method(Main, doChangeStorePasswd, void), "java.lang.Exception"},
	{"doCloneEntry", "(Ljava/lang/String;Ljava/lang/String;Z)V", nullptr, $PRIVATE, $method(Main, doCloneEntry, void, $String*, $String*, bool), "java.lang.Exception"},
	{"doCommands", "(Ljava/io/PrintStream;)V", nullptr, 0, $method(Main, doCommands, void, $PrintStream*), "java.lang.Exception"},
	{"doDeleteEntry", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(Main, doDeleteEntry, void, $String*), "java.lang.Exception"},
	{"doExportCert", "(Ljava/lang/String;Ljava/io/PrintStream;)V", nullptr, $PRIVATE, $method(Main, doExportCert, void, $String*, $PrintStream*), "java.lang.Exception"},
	{"doGenCRL", "(Ljava/io/PrintStream;)V", nullptr, $PRIVATE, $method(Main, doGenCRL, void, $PrintStream*), "java.lang.Exception"},
	{"doGenCert", "(Ljava/lang/String;Ljava/lang/String;Ljava/io/InputStream;Ljava/io/PrintStream;)V", nullptr, $PRIVATE, $method(Main, doGenCert, void, $String*, $String*, $InputStream*, $PrintStream*), "java.lang.Exception"},
	{"doGenKeyPair", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PRIVATE, $method(Main, doGenKeyPair, void, $String*, $String*, $String*, int32_t, $String*, $String*, $String*), "java.lang.Exception"},
	{"doGenSecretKey", "(Ljava/lang/String;Ljava/lang/String;I)V", nullptr, $PRIVATE, $method(Main, doGenSecretKey, void, $String*, $String*, int32_t), "java.lang.Exception"},
	{"doImportIdentityDatabase", "(Ljava/io/InputStream;)V", nullptr, $PRIVATE, $method(Main, doImportIdentityDatabase, void, $InputStream*), "java.lang.Exception"},
	{"doImportKeyStore", "(Ljava/security/KeyStore;)V", nullptr, $PRIVATE, $method(Main, doImportKeyStore, void, $KeyStore*), "java.lang.Exception"},
	{"doImportKeyStoreAll", "(Ljava/security/KeyStore;)V", nullptr, $PRIVATE, $method(Main, doImportKeyStoreAll, void, $KeyStore*), "java.lang.Exception"},
	{"doImportKeyStoreSingle", "(Ljava/security/KeyStore;Ljava/lang/String;)I", nullptr, $PRIVATE, $method(Main, doImportKeyStoreSingle, int32_t, $KeyStore*, $String*), "java.lang.Exception"},
	{"doPrintCRL", "(Ljava/lang/String;Ljava/io/PrintStream;)V", nullptr, $PRIVATE, $method(Main, doPrintCRL, void, $String*, $PrintStream*), "java.lang.Exception"},
	{"doPrintCert", "(Ljava/io/PrintStream;)V", nullptr, $PRIVATE, $method(Main, doPrintCert, void, $PrintStream*), "java.lang.Exception"},
	{"doPrintCertReq", "(Ljava/io/InputStream;Ljava/io/PrintStream;)V", nullptr, $PRIVATE, $method(Main, doPrintCertReq, void, $InputStream*, $PrintStream*), "java.lang.Exception"},
	{"doPrintEntries", "(Ljava/io/PrintStream;)V", nullptr, $PRIVATE, $method(Main, doPrintEntries, void, $PrintStream*), "java.lang.Exception"},
	{"doPrintEntry", "(Ljava/lang/String;Ljava/lang/String;Ljava/io/PrintStream;)V", nullptr, $PRIVATE, $method(Main, doPrintEntry, void, $String*, $String*, $PrintStream*), "java.lang.Exception"},
	{"doSelfCert", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PRIVATE, $method(Main, doSelfCert, void, $String*, $String*, $String*), "java.lang.Exception"},
	{"doShowInfo", "()V", nullptr, $PRIVATE, $method(Main, doShowInfo, void), "java.lang.Exception"},
	{"dumpCert", "(Ljava/security/cert/Certificate;Ljava/io/PrintStream;)V", nullptr, $PRIVATE, $method(Main, dumpCert, void, $Certificate*, $PrintStream*), "java.io.IOException,java.security.cert.CertificateException"},
	{"ecGroupNameForSize", "(I)Ljava/lang/String;", nullptr, $PRIVATE, $method(Main, ecGroupNameForSize, $String*, int32_t), "java.lang.Exception"},
	{"errorNeedArgument", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(Main, errorNeedArgument, void, $String*)},
	{"establishCertChain", "(Ljava/security/cert/Certificate;Ljava/security/cert/Certificate;)[Ljava/security/cert/Certificate;", nullptr, $PRIVATE, $method(Main, establishCertChain, $CertificateArray*, $Certificate*, $Certificate*), "java.lang.Exception"},
	{"findOidForExtName", "(Ljava/lang/String;)Lsun/security/util/ObjectIdentifier;", nullptr, $PRIVATE, $method(Main, findOidForExtName, $ObjectIdentifier*, $String*), "java.lang.Exception"},
	{"fullDisplayAlgName", "(Ljava/security/Key;)Ljava/lang/String;", nullptr, $PRIVATE, $method(Main, fullDisplayAlgName, $String*, $Key*)},
	{"generateCertificate", "(Ljava/io/InputStream;)Ljava/security/cert/Certificate;", nullptr, $PRIVATE, $method(Main, generateCertificate, $Certificate*, $InputStream*), "java.security.cert.CertificateException,java.io.IOException"},
	{"generateCertificates", "(Ljava/io/InputStream;)Ljava/util/Collection;", "(Ljava/io/InputStream;)Ljava/util/Collection<+Ljava/security/cert/Certificate;>;", $PRIVATE, $method(Main, generateCertificates, $Collection*, $InputStream*), "java.security.cert.CertificateException,java.io.IOException"},
	{"getAlias", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE, $method(Main, getAlias, $String*, $String*), "java.lang.Exception"},
	{"getCertFingerPrint", "(Ljava/lang/String;Ljava/security/cert/Certificate;)Ljava/lang/String;", nullptr, $PRIVATE, $method(Main, getCertFingerPrint, $String*, $String*, $Certificate*), "java.lang.Exception"},
	{"getCompatibleSigAlgName", "(Ljava/security/PrivateKey;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(Main, getCompatibleSigAlgName, $String*, $PrivateKey*), "java.lang.Exception"},
	{"getKeyPasswd", "(Ljava/lang/String;Ljava/lang/String;[C)[C", nullptr, $PRIVATE, $method(Main, getKeyPasswd, $chars*, $String*, $String*, $chars*), "java.lang.Exception"},
	{"getNewPasswd", "(Ljava/lang/String;[C)[C", nullptr, $PRIVATE, $method(Main, getNewPasswd, $chars*, $String*, $chars*), "java.lang.Exception"},
	{"getPass", "(Ljava/lang/String;Ljava/lang/String;)[C", nullptr, $PRIVATE, $method(Main, getPass, $chars*, $String*, $String*)},
	{"getSigner", "(Ljava/security/cert/Certificate;Ljava/security/KeyStore;)Lsun/security/tools/keytool/Pair;", "(Ljava/security/cert/Certificate;Ljava/security/KeyStore;)Lsun/security/tools/keytool/Pair<Ljava/lang/String;Ljava/security/cert/Certificate;>;", $PRIVATE | $STATIC, $staticMethod(Main, getSigner, $Pair*, $Certificate*, $KeyStore*), "java.lang.Exception"},
	{"getStartDate", "(Ljava/lang/String;)Ljava/util/Date;", nullptr, $PRIVATE | $STATIC, $staticMethod(Main, getStartDate, $Date*, $String*), "java.io.IOException"},
	{"getX500Name", "()Lsun/security/x509/X500Name;", nullptr, $PRIVATE, $method(Main, getX500Name, $X500Name*), "java.io.IOException"},
	{"getYesNoReply", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE, $method(Main, getYesNoReply, $String*, $String*), "java.io.IOException"},
	{"inplaceImportCheck", "()Z", nullptr, 0, $method(Main, inplaceImportCheck, bool), "java.lang.Exception"},
	{"inputString", "(Ljava/io/BufferedReader;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE, $method(Main, inputString, $String*, $BufferedReader*, $String*, $String*), "java.io.IOException"},
	{"inputStringFromStdin", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE, $method(Main, inputStringFromStdin, $String*, $String*), "java.lang.Exception"},
	{"installReply", "(Ljava/lang/String;Ljava/io/InputStream;)Z", nullptr, $PRIVATE, $method(Main, installReply, bool, $String*, $InputStream*), "java.lang.Exception"},
	{"isKeyStoreRelated", "(Lsun/security/tools/keytool/Main$Command;)Z", nullptr, 0, $method(Main, isKeyStoreRelated, bool, $Main$Command*)},
	{"isTrustedCert", "(Ljava/security/cert/Certificate;)Z", nullptr, $PRIVATE, $method(Main, isTrustedCert, bool, $Certificate*), "java.security.KeyStoreException"},
	{"keystorecerts2Hashtable", "(Ljava/security/KeyStore;Ljava/util/Hashtable;)V", "(Ljava/security/KeyStore;Ljava/util/Hashtable<Ljava/security/Principal;Ljava/util/Vector<Lsun/security/tools/keytool/Pair<Ljava/lang/String;Ljava/security/cert/X509Certificate;>;>;>;)V", $PRIVATE, $method(Main, keystorecerts2Hashtable, void, $KeyStore*, $Hashtable*), "java.lang.Exception"},
	{"lambda$oneOf$1", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/Boolean;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Main, lambda$oneOf$1, $Boolean*, $String*, $String*)},
	{"lambda$oneOf$2", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/Boolean;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Main, lambda$oneOf$2, $Boolean*, $String*, $String*)},
	{"lambda$oneOf$3", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/Boolean;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Main, lambda$oneOf$3, $Boolean*, $String*, $String*)},
	{"lambda$parseArgs$0", "(Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(Main, lambda$parseArgs$0, bool, $String*)},
	{"loadCRLs", "(Ljava/lang/String;)Ljava/util/Collection;", "(Ljava/lang/String;)Ljava/util/Collection<+Ljava/security/cert/CRL;>;", $PUBLIC | $STATIC, $staticMethod(Main, loadCRLs, $Collection*, $String*), "java.lang.Exception"},
	{"loadSourceKeyStore", "()Ljava/security/KeyStore;", nullptr, 0, $method(Main, loadSourceKeyStore, $KeyStore*), "java.lang.Exception"},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(Main, main, void, $StringArray*), "java.lang.Exception"},
	{"oneInMany", "(Ljava/lang/String;II)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(Main, oneInMany, $String*, $String*, int32_t, int32_t)},
	{"oneOf", "(Ljava/lang/String;[Lsun/security/util/KnownOIDs;)I", nullptr, $PRIVATE | $STATIC | $TRANSIENT, $staticMethod(Main, oneOf, int32_t, $String*, $KnownOIDsArray*), "java.lang.Exception"},
	{"oneOf", "(Ljava/lang/String;[Ljava/lang/String;)I", nullptr, $PRIVATE | $STATIC | $TRANSIENT, $staticMethod(Main, oneOf, int32_t, $String*, $StringArray*), "java.lang.Exception"},
	{"oneOfMatch", "(Ljava/util/function/BiFunction;Ljava/lang/String;[Ljava/lang/String;)I", "(Ljava/util/function/BiFunction<Ljava/lang/String;Ljava/lang/String;Ljava/lang/Boolean;>;Ljava/lang/String;[Ljava/lang/String;)I", $PRIVATE | $STATIC | $TRANSIENT, $staticMethod(Main, oneOfMatch, int32_t, $BiFunction*, $String*, $StringArray*), "java.lang.Exception"},
	{"parseArgs", "([Ljava/lang/String;)[Ljava/lang/String;", nullptr, 0, $method(Main, parseArgs, $StringArray*, $StringArray*), "java.lang.Exception"},
	{"printCRL", "(Ljava/security/cert/CRL;Ljava/io/PrintStream;)V", nullptr, $PRIVATE, $method(Main, printCRL, void, $CRL*, $PrintStream*), "java.lang.Exception"},
	{"printCertFromStream", "(Ljava/io/InputStream;Ljava/io/PrintStream;)V", nullptr, $PRIVATE, $method(Main, printCertFromStream, void, $InputStream*, $PrintStream*), "java.lang.Exception"},
	{"printExtensions", "(Ljava/lang/String;Lsun/security/x509/CertificateExtensions;Ljava/io/PrintStream;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Main, printExtensions, void, $String*, $CertificateExtensions*, $PrintStream*), "java.lang.Exception"},
	{"printNoIntegrityWarning", "()V", nullptr, $PRIVATE, $method(Main, printNoIntegrityWarning, void)},
	{"printWeakWarnings", "(Z)V", nullptr, $PRIVATE, $method(Main, printWeakWarnings, void, bool)},
	{"printX509Cert", "(Ljava/security/cert/X509Certificate;Ljava/io/PrintStream;)V", nullptr, $PRIVATE, $method(Main, printX509Cert, void, $X509Certificate*, $PrintStream*), "java.lang.Exception"},
	{"promptForCredential", "()[C", nullptr, $PRIVATE, $method(Main, promptForCredential, $chars*), "java.lang.Exception"},
	{"promptForKeyPass", "(Ljava/lang/String;Ljava/lang/String;[C)[C", nullptr, $PRIVATE, $method(Main, promptForKeyPass, $chars*, $String*, $String*, $chars*), "java.lang.Exception"},
	{"readCRLsFromCert", "(Ljava/security/cert/X509Certificate;)Ljava/util/List;", "(Ljava/security/cert/X509Certificate;)Ljava/util/List<Ljava/security/cert/CRL;>;", $PUBLIC | $STATIC, $staticMethod(Main, readCRLsFromCert, $List*, $X509Certificate*), "java.lang.Exception"},
	{"recoverEntry", "(Ljava/security/KeyStore;Ljava/lang/String;[C[C)Lsun/security/tools/keytool/Pair;", "(Ljava/security/KeyStore;Ljava/lang/String;[C[C)Lsun/security/tools/keytool/Pair<Ljava/security/KeyStore$Entry;[C>;", $PRIVATE, $method(Main, recoverEntry, $Pair*, $KeyStore*, $String*, $chars*, $chars*), "java.lang.Exception"},
	{"recoverKey", "(Ljava/lang/String;[C[C)Lsun/security/tools/keytool/Pair;", "(Ljava/lang/String;[C[C)Lsun/security/tools/keytool/Pair<Ljava/security/Key;[C>;", $PRIVATE, $method(Main, recoverKey, $Pair*, $String*, $chars*, $chars*), "java.lang.Exception"},
	{"run", "([Ljava/lang/String;Ljava/io/PrintStream;)V", nullptr, $PRIVATE, $method(Main, run, void, $StringArray*, $PrintStream*), "java.lang.Exception"},
	{"setExt", "(Lsun/security/x509/CertificateExtensions;Lsun/security/x509/Extension;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Main, setExt, void, $CertificateExtensions*, $Extension*), "java.io.IOException"},
	{"tinyHelp", "()V", nullptr, $PRIVATE, $method(Main, tinyHelp, void)},
	{"usage", "()V", nullptr, $PRIVATE, $method(Main, usage, void)},
	{"validateReply", "(Ljava/lang/String;Ljava/security/cert/Certificate;[Ljava/security/cert/Certificate;)[Ljava/security/cert/Certificate;", nullptr, $PRIVATE, $method(Main, validateReply, $CertificateArray*, $String*, $Certificate*, $CertificateArray*), "java.lang.Exception"},
	{"verifyCRL", "(Ljava/security/KeyStore;Ljava/security/cert/CRL;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(Main, verifyCRL, $String*, $KeyStore*, $CRL*), "java.lang.Exception"},
	{"withWeak", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE, $method(Main, withWeak, $String*, $String*)},
	{"withWeak", "(Ljava/security/Key;)Ljava/lang/String;", nullptr, $PRIVATE, $method(Main, withWeak, $String*, $Key*)},
	{}
};

$InnerClassInfo _Main_InnerClassesInfo_[] = {
	{"sun.security.tools.keytool.Main$Option", "sun.security.tools.keytool.Main", "Option", $STATIC | $FINAL | $ENUM},
	{"sun.security.tools.keytool.Main$Command", "sun.security.tools.keytool.Main", "Command", $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _Main_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.tools.keytool.Main",
	"java.lang.Object",
	nullptr,
	_Main_FieldInfo_,
	_Main_MethodInfo_,
	nullptr,
	nullptr,
	_Main_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.tools.keytool.Main$Option,sun.security.tools.keytool.Main$Command"
};

$Object* allocate$Main($Class* clazz) {
	return $of($alloc(Main));
}

$bytes* Main::CRLF = nullptr;
$DisabledAlgorithmConstraints* Main::DISABLED_CHECK = nullptr;
$DisabledAlgorithmConstraints* Main::LEGACY_CHECK = nullptr;
$Set* Main::SIG_PRIMITIVE_SET = nullptr;
$String* Main::NONE = nullptr;
$String* Main::P11KEYSTORE = nullptr;
$String* Main::P12KEYSTORE = nullptr;
$String* Main::keyAlias = nullptr;
$ResourceBundle* Main::rb = nullptr;
$Collator* Main::collator = nullptr;
$StringArray* Main::extSupported = nullptr;

void Main::init$() {
	this->debug = false;
	$set(this, command, nullptr);
	$set(this, sigAlgName, nullptr);
	$set(this, keyAlgName, nullptr);
	this->verbose = false;
	this->keysize = -1;
	$set(this, groupName, nullptr);
	this->rfc = false;
	this->validity = (int64_t)90;
	$set(this, alias, nullptr);
	$set(this, dname, nullptr);
	$set(this, dest, nullptr);
	$set(this, filename, nullptr);
	$set(this, infilename, nullptr);
	$set(this, outfilename, nullptr);
	$set(this, srcksfname, nullptr);
	$set(this, providers, nullptr);
	$set(this, providerClasses, nullptr);
	$set(this, storetype, nullptr);
	$set(this, srcProviderName, nullptr);
	$set(this, providerName, nullptr);
	$set(this, pathlist, nullptr);
	$set(this, storePass, nullptr);
	$set(this, storePassNew, nullptr);
	$set(this, keyPass, nullptr);
	$set(this, keyPassNew, nullptr);
	$set(this, newPass, nullptr);
	$set(this, destKeyPass, nullptr);
	$set(this, srckeyPass, nullptr);
	$set(this, ksfname, nullptr);
	$set(this, ksfile, nullptr);
	$set(this, ksStream, nullptr);
	$set(this, sslserver, nullptr);
	$set(this, jarfile, nullptr);
	$set(this, keyStore, nullptr);
	this->token = false;
	this->nullStream = false;
	this->kssave = false;
	this->noprompt = false;
	this->trustcacerts = false;
	this->protectedPath = false;
	this->srcprotectedPath = false;
	this->cacerts = false;
	this->nowarn = false;
	$set(this, caks, nullptr);
	$set(this, srcstorePass, nullptr);
	$set(this, srcstoretype, nullptr);
	$set(this, passwords, $new($HashSet));
	$set(this, startDate, nullptr);
	$set(this, signerAlias, nullptr);
	$set(this, signerKeyPass, nullptr);
	this->tlsInfo = false;
	$set(this, ids, $new($ArrayList));
	$set(this, v3ext, $new($ArrayList));
	this->inplaceImport = false;
	$set(this, inplaceBackupName, nullptr);
	$set(this, weakWarnings, $new($ArrayList));
	this->isPasswordlessKeyStore = false;
}

void Main::main($StringArray* args) {
	$init(Main);
	$var(Main, kt, $new(Main));
	kt->run(args, $System::out);
}

void Main::run($StringArray* args$renamed, $PrintStream* out) {
	$useLocalCurrentObjectStackCache();
	$var($StringArray, args, args$renamed);
	{
		$var($Throwable, var$0, nullptr);
		try {
			try {
				$assign(args, parseArgs(args));
				if (this->command != nullptr) {
					doCommands(out);
				}
			} catch ($Exception& e) {
				$nc($System::out)->println($$str({$($nc(Main::rb)->getString("keytool.error."_s)), e}));
				if (this->verbose) {
					e->printStackTrace($System::out);
				}
				if (!this->debug) {
					$System::exit(1);
				} else {
					$throw(e);
				}
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			printWeakWarnings(false);
			{
				$var($Iterator, i$, $nc(this->passwords)->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($chars, pass, $cast($chars, i$->next()));
					{
						if (pass != nullptr) {
							$Arrays::fill(pass, u' ');
							$assign(pass, nullptr);
						}
					}
				}
			}
			if (this->ksStream != nullptr) {
				$nc(this->ksStream)->close();
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

$StringArray* Main::parseArgs($StringArray* args$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($StringArray, args, args$renamed);
	int32_t i = 0;
	bool help = $nc(args)->length == 0;
	$var($String, confFile, nullptr);
	$var($Set, optionsSet, $new($HashSet));
	for (i = 0; i < args->length; ++i) {
		$var($String, flags, args->get(i));
		if ($nc(flags)->startsWith("-"_s)) {
			$init($Locale);
			$var($String, lowerFlags, flags->toLowerCase($Locale::ROOT));
			if (optionsSet->contains(lowerFlags)) {
				{
					$var($String, s18948$, lowerFlags);
					int32_t tmp18948$ = -1;
					switch (s18948$->hashCode()) {
					case 0x0015FED4:
						{
							if (s18948$->equals("-ext"_s)) {
								tmp18948$ = 0;
							}
							break;
						}
					case 0x0000B608:
						{
							if (s18948$->equals("-id"_s)) {
								tmp18948$ = 1;
							}
							break;
						}
					case (int32_t)0xD52B891E:
						{
							if (s18948$->equals("-provider"_s)) {
								tmp18948$ = 2;
							}
							break;
						}
					case (int32_t)0xE1715F45:
						{
							if (s18948$->equals("-addprovider"_s)) {
								tmp18948$ = 3;
							}
							break;
						}
					case (int32_t)0xAE79231A:
						{
							if (s18948$->equals("-providerclass"_s)) {
								tmp18948$ = 4;
							}
							break;
						}
					case (int32_t)0xD54AF478:
						{
							if (s18948$->equals("-providerarg"_s)) {
								tmp18948$ = 5;
							}
							break;
						}
					}
					switch (tmp18948$) {
					case 0:
						{}
					case 1:
						{}
					case 2:
						{}
					case 3:
						{}
					case 4:
						{}
					case 5:
						{
							break;
						}
					default:
						{
							$nc(this->weakWarnings)->add($($String::format($($nc(Main::rb)->getString("option.1.set.twice"_s)), $$new($ObjectArray, {$of(lowerFlags)}))));
						}
					}
				}
			} else {
				optionsSet->add(lowerFlags);
			}
			if ($nc(Main::collator)->compare(flags, "-conf"_s) == 0) {
				if (i == args->length - 1) {
					errorNeedArgument(flags);
				}
				$assign(confFile, args->get(++i));
			} else {
				$Main$Command* c = $Main$Command::getCommand(flags);
				if (c != nullptr) {
					if (this->command == nullptr) {
						$set(this, command, c);
					} else {
						$throwNew($Exception, $($String::format($($nc(Main::rb)->getString("multiple.commands.1.2"_s)), $$new($ObjectArray, {
							$of($nc(this->command)->name$),
							$of(c->name$)
						}))));
					}
				}
			}
		}
	}
	if (confFile != nullptr && this->command != nullptr) {
		$var($String, var$0, "keytool"_s);
		$var($String, var$1, confFile);
		$var($String, var$2, $nc(this->command)->toString());
		$assign(args, $KeyStoreUtil::expandArgs(var$0, var$1, var$2, $($nc(this->command)->getAltName()), args));
	}
	this->debug = $nc($($Arrays::stream(args)))->anyMatch(static_cast<$Predicate*>($$new(Main$$Lambda$lambda$parseArgs$0)));
	if (this->debug) {
		$nc($System::out)->println($$str({"Command line args: "_s, $($Arrays::toString(args))}));
	}
	for (i = 0; (i < args->length) && $nc(args->get(i))->startsWith("-"_s); ++i) {
		$var($String, flags, args->get(i));
		if (i == args->length - 1) {
			{
				$var($Main$OptionArray, arr$, $Main$Option::values());
				int32_t len$ = $nc(arr$)->length;
				int32_t i$ = 0;
				for (; i$ < len$; ++i$) {
					$Main$Option* option = arr$->get(i$);
					{
						if ($nc(Main::collator)->compare(flags, $($nc(option)->toString())) == 0) {
							if ($nc(option)->arg != nullptr) {
								errorNeedArgument(flags);
							}
							break;
						}
					}
				}
			}
		}
		$var($String, modifier, nullptr);
		int32_t pos = $nc(flags)->indexOf((int32_t)u':');
		if (pos > 0) {
			$assign(modifier, flags->substring(pos + 1));
			$assign(flags, flags->substring(0, pos));
		}
		$Main$Command* c = $Main$Command::getCommand(flags);
		if (c != nullptr) {
			$set(this, command, c);
		} else {
			bool var$8 = $nc(Main::collator)->compare(flags, "--help"_s) == 0;
			bool var$7 = var$8 || $nc(Main::collator)->compare(flags, "-h"_s) == 0;
			bool var$6 = var$7 || $nc(Main::collator)->compare(flags, "-?"_s) == 0;
			if (var$6 || $nc(Main::collator)->compare(flags, "-help"_s) == 0) {
				help = true;
			} else if ($nc(Main::collator)->compare(flags, "-conf"_s) == 0) {
				++i;
			} else if ($nc(Main::collator)->compare(flags, "-nowarn"_s) == 0) {
				this->nowarn = true;
			} else if ($nc(Main::collator)->compare(flags, "-keystore"_s) == 0) {
				$set(this, ksfname, args->get(++i));
				if ($nc($($$new($File, this->ksfname)->getCanonicalPath()))->equals($($$new($File, $($KeyStoreUtil::getCacerts()))->getCanonicalPath()))) {
					$nc($System::err)->println($($nc(Main::rb)->getString("warning.cacerts.option"_s)));
				}
			} else if ($nc(Main::collator)->compare(flags, "-destkeystore"_s) == 0) {
				$set(this, ksfname, args->get(++i));
			} else if ($nc(Main::collator)->compare(flags, "-cacerts"_s) == 0) {
				this->cacerts = true;
			} else {
				bool var$10 = $nc(Main::collator)->compare(flags, "-storepass"_s) == 0;
				if (var$10 || $nc(Main::collator)->compare(flags, "-deststorepass"_s) == 0) {
					$set(this, storePass, getPass(modifier, args->get(++i)));
					$nc(this->passwords)->add(this->storePass);
				} else {
					bool var$12 = $nc(Main::collator)->compare(flags, "-storetype"_s) == 0;
					if (var$12 || $nc(Main::collator)->compare(flags, "-deststoretype"_s) == 0) {
						$set(this, storetype, $KeyStoreUtil::niceStoreTypeName(args->get(++i)));
					} else if ($nc(Main::collator)->compare(flags, "-srcstorepass"_s) == 0) {
						$set(this, srcstorePass, getPass(modifier, args->get(++i)));
						$nc(this->passwords)->add(this->srcstorePass);
					} else if ($nc(Main::collator)->compare(flags, "-srcstoretype"_s) == 0) {
						$set(this, srcstoretype, $KeyStoreUtil::niceStoreTypeName(args->get(++i)));
					} else if ($nc(Main::collator)->compare(flags, "-srckeypass"_s) == 0) {
						$set(this, srckeyPass, getPass(modifier, args->get(++i)));
						$nc(this->passwords)->add(this->srckeyPass);
					} else if ($nc(Main::collator)->compare(flags, "-srcprovidername"_s) == 0) {
						$set(this, srcProviderName, args->get(++i));
					} else {
						bool var$14 = $nc(Main::collator)->compare(flags, "-providername"_s) == 0;
						if (var$14 || $nc(Main::collator)->compare(flags, "-destprovidername"_s) == 0) {
							$set(this, providerName, args->get(++i));
						} else if ($nc(Main::collator)->compare(flags, "-providerpath"_s) == 0) {
							$set(this, pathlist, args->get(++i));
						} else if ($nc(Main::collator)->compare(flags, "-keypass"_s) == 0) {
							$set(this, keyPass, getPass(modifier, args->get(++i)));
							$nc(this->passwords)->add(this->keyPass);
						} else if ($nc(Main::collator)->compare(flags, "-new"_s) == 0) {
							$set(this, newPass, getPass(modifier, args->get(++i)));
							$nc(this->passwords)->add(this->newPass);
						} else if ($nc(Main::collator)->compare(flags, "-destkeypass"_s) == 0) {
							$set(this, destKeyPass, getPass(modifier, args->get(++i)));
							$nc(this->passwords)->add(this->destKeyPass);
						} else {
							bool var$16 = $nc(Main::collator)->compare(flags, "-alias"_s) == 0;
							if (var$16 || $nc(Main::collator)->compare(flags, "-srcalias"_s) == 0) {
								$set(this, alias, args->get(++i));
							} else {
								bool var$18 = $nc(Main::collator)->compare(flags, "-dest"_s) == 0;
								if (var$18 || $nc(Main::collator)->compare(flags, "-destalias"_s) == 0) {
									$set(this, dest, args->get(++i));
								} else if ($nc(Main::collator)->compare(flags, "-dname"_s) == 0) {
									$set(this, dname, args->get(++i));
								} else if ($nc(Main::collator)->compare(flags, "-keysize"_s) == 0) {
									this->keysize = $Integer::parseInt(args->get(++i));
								} else if ($nc(Main::collator)->compare(flags, "-groupname"_s) == 0) {
									$set(this, groupName, args->get(++i));
								} else if ($nc(Main::collator)->compare(flags, "-keyalg"_s) == 0) {
									$set(this, keyAlgName, args->get(++i));
								} else if ($nc(Main::collator)->compare(flags, "-sigalg"_s) == 0) {
									$set(this, sigAlgName, args->get(++i));
								} else if ($nc(Main::collator)->compare(flags, "-signer"_s) == 0) {
									$set(this, signerAlias, args->get(++i));
								} else if ($nc(Main::collator)->compare(flags, "-signerkeypass"_s) == 0) {
									$set(this, signerKeyPass, getPass(modifier, args->get(++i)));
									$nc(this->passwords)->add(this->signerKeyPass);
								} else if ($nc(Main::collator)->compare(flags, "-startdate"_s) == 0) {
									$set(this, startDate, args->get(++i));
								} else if ($nc(Main::collator)->compare(flags, "-validity"_s) == 0) {
									this->validity = $Long::parseLong(args->get(++i));
								} else if ($nc(Main::collator)->compare(flags, "-ext"_s) == 0) {
									$nc(this->v3ext)->add(args->get(++i));
								} else if ($nc(Main::collator)->compare(flags, "-id"_s) == 0) {
									$nc(this->ids)->add(args->get(++i));
								} else if ($nc(Main::collator)->compare(flags, "-file"_s) == 0) {
									$set(this, filename, args->get(++i));
								} else if ($nc(Main::collator)->compare(flags, "-infile"_s) == 0) {
									$set(this, infilename, args->get(++i));
								} else if ($nc(Main::collator)->compare(flags, "-outfile"_s) == 0) {
									$set(this, outfilename, args->get(++i));
								} else if ($nc(Main::collator)->compare(flags, "-sslserver"_s) == 0) {
									$set(this, sslserver, args->get(++i));
								} else if ($nc(Main::collator)->compare(flags, "-jarfile"_s) == 0) {
									$set(this, jarfile, args->get(++i));
								} else if ($nc(Main::collator)->compare(flags, "-srckeystore"_s) == 0) {
									$set(this, srcksfname, args->get(++i));
								} else {
									bool var$20 = $nc(Main::collator)->compare(flags, "-provider"_s) == 0;
									if (var$20 || $nc(Main::collator)->compare(flags, "-providerclass"_s) == 0) {
										if (this->providerClasses == nullptr) {
											$set(this, providerClasses, $new($HashSet, 3));
										}
										$var($String, providerClass, args->get(++i));
										$var($String, providerArg, nullptr);
										if (args->length > (i + 1)) {
											$assign(flags, args->get(i + 1));
											if ($nc(Main::collator)->compare(flags, "-providerarg"_s) == 0) {
												if (args->length == (i + 2)) {
													errorNeedArgument(flags);
												}
												$assign(providerArg, args->get(i + 2));
												i += 2;
											}
										}
										$nc(this->providerClasses)->add($($Pair::of(providerClass, providerArg)));
									} else if ($nc(Main::collator)->compare(flags, "-addprovider"_s) == 0) {
										if (this->providers == nullptr) {
											$set(this, providers, $new($HashSet, 3));
										}
										$var($String, provider, args->get(++i));
										$var($String, providerArg, nullptr);
										if (args->length > (i + 1)) {
											$assign(flags, args->get(i + 1));
											if ($nc(Main::collator)->compare(flags, "-providerarg"_s) == 0) {
												if (args->length == (i + 2)) {
													errorNeedArgument(flags);
												}
												$assign(providerArg, args->get(i + 2));
												i += 2;
											}
										}
										$nc(this->providers)->add($($Pair::of(provider, providerArg)));
									} else if ($nc(Main::collator)->compare(flags, "-v"_s) == 0) {
										this->verbose = true;
									} else if ($nc(Main::collator)->compare(flags, "-debug"_s) == 0) {
									} else if ($nc(Main::collator)->compare(flags, "-rfc"_s) == 0) {
										this->rfc = true;
									} else if ($nc(Main::collator)->compare(flags, "-noprompt"_s) == 0) {
										this->noprompt = true;
									} else if ($nc(Main::collator)->compare(flags, "-trustcacerts"_s) == 0) {
										this->trustcacerts = true;
									} else {
										bool var$22 = $nc(Main::collator)->compare(flags, "-protected"_s) == 0;
										if (var$22 || $nc(Main::collator)->compare(flags, "-destprotected"_s) == 0) {
											this->protectedPath = true;
										} else if ($nc(Main::collator)->compare(flags, "-srcprotected"_s) == 0) {
											this->srcprotectedPath = true;
										} else if ($nc(Main::collator)->compare(flags, "-tls"_s) == 0) {
											this->tlsInfo = true;
										} else {
											$nc($System::err)->println($$str({$($nc(Main::rb)->getString("Illegal.option."_s)), flags}));
											tinyHelp();
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (i < args->length) {
		$nc($System::err)->println($$str({$($nc(Main::rb)->getString("Illegal.option."_s)), args->get(i)}));
		tinyHelp();
	}
	if (this->command == nullptr) {
		if (help) {
			usage();
		} else {
			$nc($System::err)->println($($nc(Main::rb)->getString("Usage.error.no.command.provided"_s)));
			tinyHelp();
		}
	} else if (help) {
		usage();
		$set(this, command, nullptr);
	}
	return args;
}

bool Main::isKeyStoreRelated($Main$Command* cmd) {
	$init($Main$Command);
	return cmd != $Main$Command::PRINTCERTREQ && cmd != $Main$Command::SHOWINFO;
}

void Main::doCommands($PrintStream* out$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($PrintStream, out, out$renamed);
	$beforeCallerSensitive();
	if (this->cacerts) {
		if (this->ksfname != nullptr || this->storetype != nullptr) {
			$throwNew($IllegalArgumentException, $($nc(Main::rb)->getString("the.keystore.or.storetype.option.cannot.be.used.with.the.cacerts.option"_s)));
		}
		$set(this, ksfname, $KeyStoreUtil::getCacerts());
	}
	bool var$0 = $nc(Main::P11KEYSTORE)->equalsIgnoreCase(this->storetype);
	if (var$0 || $KeyStoreUtil::isWindowsKeyStore(this->storetype)) {
		this->token = true;
		if (this->ksfname == nullptr) {
			$set(this, ksfname, Main::NONE);
		}
	}
	if ($nc(Main::NONE)->equals(this->ksfname)) {
		this->nullStream = true;
	}
	if (this->token && !this->nullStream) {
		$nc($System::err)->println($($MessageFormat::format($($nc(Main::rb)->getString(".keystore.must.be.NONE.if.storetype.is.{0}"_s)), $$new($ObjectArray, {$of(this->storetype)}))));
		$nc($System::err)->println();
		tinyHelp();
	}
	$init($Main$Command);
	if (this->token && (this->command == $Main$Command::KEYPASSWD || this->command == $Main$Command::STOREPASSWD)) {
		$throwNew($UnsupportedOperationException, $($MessageFormat::format($($nc(Main::rb)->getString(".storepasswd.and.keypasswd.commands.not.supported.if.storetype.is.{0}"_s)), $$new($ObjectArray, {$of(this->storetype)}))));
	}
	if (this->token && (this->keyPass != nullptr || this->newPass != nullptr || this->destKeyPass != nullptr)) {
		$throwNew($IllegalArgumentException, $($MessageFormat::format($($nc(Main::rb)->getString(".keypass.and.new.can.not.be.specified.if.storetype.is.{0}"_s)), $$new($ObjectArray, {$of(this->storetype)}))));
	}
	if (this->protectedPath) {
		if (this->storePass != nullptr || this->keyPass != nullptr || this->newPass != nullptr || this->destKeyPass != nullptr) {
			$throwNew($IllegalArgumentException, $($nc(Main::rb)->getString("if.protected.is.specified.then.storepass.keypass.and.new.must.not.be.specified"_s)));
		}
	}
	if (this->srcprotectedPath) {
		if (this->srcstorePass != nullptr || this->srckeyPass != nullptr) {
			$throwNew($IllegalArgumentException, $($nc(Main::rb)->getString("if.srcprotected.is.specified.then.srcstorepass.and.srckeypass.must.not.be.specified"_s)));
		}
	}
	if ($KeyStoreUtil::isWindowsKeyStore(this->storetype)) {
		if (this->storePass != nullptr || this->keyPass != nullptr || this->newPass != nullptr || this->destKeyPass != nullptr) {
			$throwNew($IllegalArgumentException, $($nc(Main::rb)->getString("if.keystore.is.not.password.protected.then.storepass.keypass.and.new.must.not.be.specified"_s)));
		}
	}
	if ($KeyStoreUtil::isWindowsKeyStore(this->srcstoretype)) {
		if (this->srcstorePass != nullptr || this->srckeyPass != nullptr) {
			$throwNew($IllegalArgumentException, $($nc(Main::rb)->getString("if.source.keystore.is.not.password.protected.then.srcstorepass.and.srckeypass.must.not.be.specified"_s)));
		}
	}
	if (this->validity <= (int64_t)0) {
		$throwNew($Exception, $($nc(Main::rb)->getString("Validity.must.be.greater.than.zero"_s)));
	}
	if (this->providers != nullptr) {
		{
			$var($Iterator, i$, $nc(this->providers)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Pair, provider, $cast($Pair, i$->next()));
				{
					try {
						$KeyStoreUtil::loadProviderByName($cast($String, $nc(provider)->fst), $cast($String, provider->snd));
						if (this->debug) {
							$nc($System::out)->println($$str({"loadProviderByName: "_s, $cast($String, $nc(provider)->fst)}));
						}
					} catch ($IllegalArgumentException& e) {
						$throwNew($Exception, $($String::format($($nc(Main::rb)->getString("provider.name.not.found"_s)), $$new($ObjectArray, {$nc(provider)->fst}))));
					}
				}
			}
		}
	}
	if (this->providerClasses != nullptr) {
		$var($ClassLoader, cl, nullptr);
		if (this->pathlist != nullptr) {
			$var($String, path, nullptr);
			$assign(path, $PathList::appendPath(path, $($System::getProperty("java.class.path"_s))));
			$assign(path, $PathList::appendPath(path, $($System::getProperty("env.class.path"_s))));
			$assign(path, $PathList::appendPath(path, this->pathlist));
			$var($URLArray, urls, $PathList::pathToURLs(path));
			$assign(cl, $new($URLClassLoader, urls));
		} else {
			$assign(cl, $ClassLoader::getSystemClassLoader());
		}
		{
			$var($Iterator, i$, $nc(this->providerClasses)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Pair, provider, $cast($Pair, i$->next()));
				{
					try {
						$KeyStoreUtil::loadProviderByClass($cast($String, $nc(provider)->fst), $cast($String, provider->snd), cl);
						if (this->debug) {
							$nc($System::out)->println($$str({"loadProviderByClass: "_s, $cast($String, $nc(provider)->fst)}));
						}
					} catch ($ClassCastException& cce) {
						$throwNew($Exception, $($String::format($($nc(Main::rb)->getString("provclass.not.a.provider"_s)), $$new($ObjectArray, {$nc(provider)->fst}))));
					} catch ($IllegalArgumentException& e) {
						$var($String, var$1, $String::format($($nc(Main::rb)->getString("provider.class.not.found"_s)), $$new($ObjectArray, {$nc(provider)->fst})));
						$throwNew($Exception, var$1, $(e->getCause()));
					}
				}
			}
		}
	}
	if (this->command == $Main$Command::LIST && this->verbose && this->rfc) {
		$nc($System::err)->println($($nc(Main::rb)->getString("Must.not.specify.both.v.and.rfc.with.list.command"_s)));
		tinyHelp();
	}
	if (this->command == $Main$Command::GENKEYPAIR && this->keyPass != nullptr && $nc(this->keyPass)->length < 6) {
		$throwNew($Exception, $($nc(Main::rb)->getString("Key.password.must.be.at.least.6.characters"_s)));
	}
	if (this->newPass != nullptr && $nc(this->newPass)->length < 6) {
		$throwNew($Exception, $($nc(Main::rb)->getString("New.password.must.be.at.least.6.characters"_s)));
	}
	if (this->destKeyPass != nullptr && $nc(this->destKeyPass)->length < 6) {
		$throwNew($Exception, $($nc(Main::rb)->getString("New.password.must.be.at.least.6.characters"_s)));
	}
	if (this->ksfname == nullptr) {
		$init($File);
		$set(this, ksfname, $str({$($System::getProperty("user.home"_s)), $File::separator, ".keystore"_s}));
	}
	$var($KeyStore, srcKeyStore, nullptr);
	if (this->command == $Main$Command::IMPORTKEYSTORE) {
		this->inplaceImport = inplaceImportCheck();
		if (this->inplaceImport) {
			$assign(srcKeyStore, loadSourceKeyStore());
			if (this->storePass == nullptr) {
				$set(this, storePass, this->srcstorePass);
			}
		}
	}
	if (isKeyStoreRelated(this->command) && !this->nullStream && !this->inplaceImport) {
		try {
			$set(this, ksfile, $new($File, this->ksfname));
			bool var$2 = $nc(this->ksfile)->exists();
			if (var$2 && $nc(this->ksfile)->length() == 0) {
				$throwNew($Exception, $$str({$($nc(Main::rb)->getString("Keystore.file.exists.but.is.empty."_s)), this->ksfname}));
			}
			$set(this, ksStream, $new($FileInputStream, this->ksfile));
		} catch ($FileNotFoundException& e) {
			if (this->command != $Main$Command::GENKEYPAIR && this->command != $Main$Command::GENSECKEY && this->command != $Main$Command::IDENTITYDB && this->command != $Main$Command::IMPORTCERT && this->command != $Main$Command::IMPORTPASS && this->command != $Main$Command::IMPORTKEYSTORE && this->command != $Main$Command::PRINTCRL && this->command != $Main$Command::PRINTCERT) {
				$throwNew($Exception, $$str({$($nc(Main::rb)->getString("Keystore.file.does.not.exist."_s)), this->ksfname}));
			}
		}
	}
	if ((this->command == $Main$Command::KEYCLONE || this->command == $Main$Command::CHANGEALIAS) && this->dest == nullptr) {
		$set(this, dest, getAlias("destination"_s));
		if (""_s->equals(this->dest)) {
			$throwNew($Exception, $($nc(Main::rb)->getString("Must.specify.destination.alias"_s)));
		}
	}
	if (this->command == $Main$Command::DELETE && this->alias == nullptr) {
		$set(this, alias, getAlias(nullptr));
		if (""_s->equals(this->alias)) {
			$throwNew($Exception, $($nc(Main::rb)->getString("Must.specify.alias"_s)));
		}
	}
	if (this->ksfile != nullptr && this->ksStream != nullptr && this->providerName == nullptr && !this->inplaceImport) {
		if (this->storetype == nullptr) {
			$set(this, keyStore, $KeyStore::getInstance(this->ksfile, this->storePass));
			$set(this, storetype, $nc(this->keyStore)->getType());
		} else {
			$set(this, keyStore, $KeyStore::getInstance(this->storetype));
			$nc(this->keyStore)->load(this->ksStream, this->storePass);
		}
		if ($nc(this->storetype)->equalsIgnoreCase("pkcs12"_s)) {
			try {
				this->isPasswordlessKeyStore = $PKCS12KeyStore::isPasswordless(this->ksfile);
			} catch ($IOException& ioe) {
			}
		}
	} else {
		if (this->storetype == nullptr) {
			$set(this, storetype, $KeyStore::getDefaultType());
		}
		if (this->providerName == nullptr) {
			$set(this, keyStore, $KeyStore::getInstance(this->storetype));
		} else {
			$set(this, keyStore, $KeyStore::getInstance(this->storetype, this->providerName));
		}
		if ($nc(this->storetype)->equalsIgnoreCase("pkcs12"_s)) {
			bool var$3 = "NONE"_s->equals($($SecurityProperties::privilegedGetOverridable("keystore.pkcs12.certProtectionAlgorithm"_s)));
			this->isPasswordlessKeyStore = var$3 && "NONE"_s->equals($($SecurityProperties::privilegedGetOverridable("keystore.pkcs12.macAlgorithm"_s)));
		}
		if (!this->nullStream) {
			if (this->inplaceImport) {
				$nc(this->keyStore)->load(nullptr, this->storePass);
			} else {
				$nc(this->keyStore)->load(this->ksStream, this->storePass);
			}
		}
	}
	if ($nc(Main::P12KEYSTORE)->equalsIgnoreCase(this->storetype) && this->command == $Main$Command::KEYPASSWD) {
		$throwNew($UnsupportedOperationException, $($nc(Main::rb)->getString(".keypasswd.commands.not.supported.if.storetype.is.PKCS12"_s)));
	}
	if (this->nullStream && this->storePass != nullptr) {
		$nc(this->keyStore)->load(nullptr, this->storePass);
	} else if (!this->nullStream && this->storePass != nullptr) {
		if (this->ksStream == nullptr && $nc(this->storePass)->length < 6) {
			$throwNew($Exception, $($nc(Main::rb)->getString("Keystore.password.must.be.at.least.6.characters"_s)));
		}
	} else if (this->storePass == nullptr) {
		bool var$4 = !this->protectedPath && !$KeyStoreUtil::isWindowsKeyStore(this->storetype);
		if (var$4 && isKeyStoreRelated(this->command) && !this->isPasswordlessKeyStore) {
			if (this->command == $Main$Command::CERTREQ || this->command == $Main$Command::DELETE || this->command == $Main$Command::GENKEYPAIR || this->command == $Main$Command::GENSECKEY || this->command == $Main$Command::IMPORTCERT || this->command == $Main$Command::IMPORTPASS || this->command == $Main$Command::IMPORTKEYSTORE || this->command == $Main$Command::KEYCLONE || this->command == $Main$Command::CHANGEALIAS || this->command == $Main$Command::SELFCERT || this->command == $Main$Command::STOREPASSWD || this->command == $Main$Command::KEYPASSWD || this->command == $Main$Command::IDENTITYDB) {
				int32_t count = 0;
				do {
					if (this->command == $Main$Command::IMPORTKEYSTORE) {
						$nc($System::err)->print($($nc(Main::rb)->getString("Enter.destination.keystore.password."_s)));
					} else {
						$nc($System::err)->print($($nc(Main::rb)->getString("Enter.keystore.password."_s)));
					}
					$nc($System::err)->flush();
					$set(this, storePass, $Password::readPassword($System::in));
					$nc(this->passwords)->add(this->storePass);
					if (!this->nullStream && (this->storePass == nullptr || $nc(this->storePass)->length < 6)) {
						$nc($System::err)->println($($nc(Main::rb)->getString("Keystore.password.is.too.short.must.be.at.least.6.characters"_s)));
						$set(this, storePass, nullptr);
					}
					if (this->storePass != nullptr && !this->nullStream && this->ksStream == nullptr) {
						$nc($System::err)->print($($nc(Main::rb)->getString("Re.enter.new.password."_s)));
						$var($chars, storePassAgain, $Password::readPassword($System::in));
						$nc(this->passwords)->add(storePassAgain);
						if (!$Arrays::equals(this->storePass, storePassAgain)) {
							$nc($System::err)->println($($nc(Main::rb)->getString("They.don.t.match.Try.again"_s)));
							$set(this, storePass, nullptr);
						}
					}
					++count;
				} while ((this->storePass == nullptr) && count < 3);
				if (this->storePass == nullptr) {
					$nc($System::err)->println($($nc(Main::rb)->getString("Too.many.failures.try.later"_s)));
					return;
				}
			} else {
				if (this->command != $Main$Command::PRINTCRL && this->command != $Main$Command::PRINTCERT) {
					$nc($System::err)->print($($nc(Main::rb)->getString("Enter.keystore.password."_s)));
					$nc($System::err)->flush();
					$set(this, storePass, $Password::readPassword($System::in));
					$nc(this->passwords)->add(this->storePass);
				}
			}
		}
		if (this->nullStream) {
			$nc(this->keyStore)->load(nullptr, this->storePass);
		} else if (this->ksStream != nullptr) {
			{
				$var($FileInputStream, fis, $new($FileInputStream, this->ksfile));
				{
					$var($Throwable, var$5, nullptr);
					try {
						try {
							$nc(this->keyStore)->load(fis, this->storePass);
						} catch ($Throwable& t$) {
							try {
								fis->close();
							} catch ($Throwable& x2) {
								t$->addSuppressed(x2);
							}
							$throw(t$);
						}
					} catch ($Throwable& var$6) {
						$assign(var$5, var$6);
					} /*finally*/ {
						fis->close();
					}
					if (var$5 != nullptr) {
						$throw(var$5);
					}
				}
			}
		}
	}
	if (this->storePass != nullptr && $nc(Main::P12KEYSTORE)->equalsIgnoreCase(this->storetype)) {
		$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("Warning.Different.store.and.key.passwords.not.supported.for.PKCS12.KeyStores.Ignoring.user.specified.command.value."_s))));
		if (this->keyPass != nullptr && !$Arrays::equals(this->storePass, this->keyPass)) {
			$var($ObjectArray, source, $new($ObjectArray, {$of("-keypass"_s)}));
			$nc($System::err)->println($(form->format(source)));
			$set(this, keyPass, this->storePass);
		}
		if (this->destKeyPass != nullptr && !$Arrays::equals(this->storePass, this->destKeyPass)) {
			$var($ObjectArray, source, $new($ObjectArray, {$of("-destkeypass"_s)}));
			$nc($System::err)->println($(form->format(source)));
			$set(this, destKeyPass, this->storePass);
		}
	}
	if (this->command != $Main$Command::IMPORTCERT && this->command != $Main$Command::PRINTCERT && this->command != $Main$Command::PRINTCRL) {
		this->trustcacerts = false;
	}
	if (this->trustcacerts) {
		$set(this, caks, $KeyStoreUtil::getCacertsKeyStore());
	}
	if (this->command == $Main$Command::CERTREQ) {
		if (this->filename != nullptr) {
			{
				$var($PrintStream, ps, $new($PrintStream, static_cast<$OutputStream*>($$new($FileOutputStream, this->filename))));
				{
					$var($Throwable, var$7, nullptr);
					try {
						try {
							doCertReq(this->alias, this->sigAlgName, ps);
						} catch ($Throwable& t$) {
							try {
								ps->close();
							} catch ($Throwable& x2) {
								t$->addSuppressed(x2);
							}
							$throw(t$);
						}
					} catch ($Throwable& var$8) {
						$assign(var$7, var$8);
					} /*finally*/ {
						ps->close();
					}
					if (var$7 != nullptr) {
						$throw(var$7);
					}
				}
			}
		} else {
			doCertReq(this->alias, this->sigAlgName, out);
		}
		if (this->verbose && this->filename != nullptr) {
			$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("Certification.request.stored.in.file.filename."_s))));
			$var($ObjectArray, source, $new($ObjectArray, {$of(this->filename)}));
			$nc($System::err)->println($(form->format(source)));
			$nc($System::err)->println($($nc(Main::rb)->getString("Submit.this.to.your.CA"_s)));
		}
	} else {
		if (this->command == $Main$Command::DELETE) {
			doDeleteEntry(this->alias);
			this->kssave = true;
		} else {
			if (this->command == $Main$Command::EXPORTCERT) {
				if (this->filename != nullptr) {
					{
						$var($PrintStream, ps, $new($PrintStream, static_cast<$OutputStream*>($$new($FileOutputStream, this->filename))));
						{
							$var($Throwable, var$9, nullptr);
							try {
								try {
									doExportCert(this->alias, ps);
								} catch ($Throwable& t$) {
									try {
										ps->close();
									} catch ($Throwable& x2) {
										t$->addSuppressed(x2);
									}
									$throw(t$);
								}
							} catch ($Throwable& var$10) {
								$assign(var$9, var$10);
							} /*finally*/ {
								ps->close();
							}
							if (var$9 != nullptr) {
								$throw(var$9);
							}
						}
					}
				} else {
					doExportCert(this->alias, out);
				}
				if (this->filename != nullptr) {
					$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("Certificate.stored.in.file.filename."_s))));
					$var($ObjectArray, source, $new($ObjectArray, {$of(this->filename)}));
					$nc($System::err)->println($(form->format(source)));
				}
			} else {
				if (this->command == $Main$Command::GENKEYPAIR) {
					if (this->keyAlgName == nullptr) {
						$throwNew($Exception, $($nc(Main::rb)->getString("keyalg.option.missing.error"_s)));
					}
					doGenKeyPair(this->alias, this->dname, this->keyAlgName, this->keysize, this->groupName, this->sigAlgName, this->signerAlias);
					this->kssave = true;
				} else {
					if (this->command == $Main$Command::GENSECKEY) {
						if (this->keyAlgName == nullptr) {
							$throwNew($Exception, $($nc(Main::rb)->getString("keyalg.option.missing.error"_s)));
						}
						doGenSecretKey(this->alias, this->keyAlgName, this->keysize);
						this->kssave = true;
					} else {
						if (this->command == $Main$Command::IMPORTPASS) {
							if (this->keyAlgName == nullptr) {
								$set(this, keyAlgName, "PBE"_s);
							}
							doGenSecretKey(this->alias, this->keyAlgName, this->keysize);
							this->kssave = true;
						} else {
							if (this->command == $Main$Command::IDENTITYDB) {
								if (this->filename != nullptr) {
									{
										$var($InputStream, inStream, $new($FileInputStream, this->filename));
										{
											$var($Throwable, var$11, nullptr);
											try {
												try {
													doImportIdentityDatabase(inStream);
												} catch ($Throwable& t$) {
													try {
														inStream->close();
													} catch ($Throwable& x2) {
														t$->addSuppressed(x2);
													}
													$throw(t$);
												}
											} catch ($Throwable& var$12) {
												$assign(var$11, var$12);
											} /*finally*/ {
												inStream->close();
											}
											if (var$11 != nullptr) {
												$throw(var$11);
											}
										}
									}
								} else {
									doImportIdentityDatabase($System::in);
								}
							} else {
								if (this->command == $Main$Command::IMPORTCERT) {
									$var($InputStream, inStream, $System::in);
									if (this->filename != nullptr) {
										$assign(inStream, $new($FileInputStream, this->filename));
									}
									$var($String, importAlias, (this->alias != nullptr) ? this->alias : Main::keyAlias);
									{
										$var($Throwable, var$13, nullptr);
										try {
											$load($KeyStore$PrivateKeyEntry);
											if ($nc(this->keyStore)->entryInstanceOf(importAlias, $KeyStore$PrivateKeyEntry::class$)) {
												this->kssave = installReply(importAlias, inStream);
												if (this->kssave) {
													$nc($System::err)->println($($nc(Main::rb)->getString("Certificate.reply.was.installed.in.keystore"_s)));
												} else {
													$nc($System::err)->println($($nc(Main::rb)->getString("Certificate.reply.was.not.installed.in.keystore"_s)));
												}
											} else {
												bool var$15 = !$nc(this->keyStore)->containsAlias(importAlias);
												$load($KeyStore$TrustedCertificateEntry);
												if (var$15 || $nc(this->keyStore)->entryInstanceOf(importAlias, $KeyStore$TrustedCertificateEntry::class$)) {
													this->kssave = addTrustedCert(importAlias, inStream);
													if (this->kssave) {
														$nc($System::err)->println($($nc(Main::rb)->getString("Certificate.was.added.to.keystore"_s)));
													} else {
														$nc($System::err)->println($($nc(Main::rb)->getString("Certificate.was.not.added.to.keystore"_s)));
													}
												}
											}
										} catch ($Throwable& var$16) {
											$assign(var$13, var$16);
										} /*finally*/ {
											if (inStream != $System::in) {
												$nc(inStream)->close();
											}
										}
										if (var$13 != nullptr) {
											$throw(var$13);
										}
									}
								} else {
									if (this->command == $Main$Command::IMPORTKEYSTORE) {
										if (srcKeyStore == nullptr) {
											$assign(srcKeyStore, loadSourceKeyStore());
										}
										doImportKeyStore(srcKeyStore);
										this->kssave = true;
									} else {
										if (this->command == $Main$Command::KEYCLONE) {
											$set(this, keyPassNew, this->newPass);
											if (this->alias == nullptr) {
												$set(this, alias, Main::keyAlias);
											}
											if ($nc(this->keyStore)->containsAlias(this->alias) == false) {
												$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("Alias.alias.does.not.exist"_s))));
												$var($ObjectArray, source, $new($ObjectArray, {$of(this->alias)}));
												$throwNew($Exception, $(form->format(source)));
											}
											$load($KeyStore$PrivateKeyEntry);
											if (!$nc(this->keyStore)->entryInstanceOf(this->alias, $KeyStore$PrivateKeyEntry::class$)) {
												$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("Alias.alias.references.an.entry.type.that.is.not.a.private.key.entry.The.keyclone.command.only.supports.cloning.of.private.key"_s))));
												$var($ObjectArray, source, $new($ObjectArray, {$of(this->alias)}));
												$throwNew($Exception, $(form->format(source)));
											}
											doCloneEntry(this->alias, this->dest, true);
											this->kssave = true;
										} else {
											if (this->command == $Main$Command::CHANGEALIAS) {
												if (this->alias == nullptr) {
													$set(this, alias, Main::keyAlias);
												}
												doCloneEntry(this->alias, this->dest, false);
												if ($nc(this->keyStore)->containsAlias(this->alias)) {
													doDeleteEntry(this->alias);
												}
												this->kssave = true;
											} else {
												if (this->command == $Main$Command::KEYPASSWD) {
													$set(this, keyPassNew, this->newPass);
													doChangeKeyPasswd(this->alias);
													this->kssave = true;
												} else {
													if (this->command == $Main$Command::LIST) {
														if (this->storePass == nullptr && !$KeyStoreUtil::isWindowsKeyStore(this->storetype) && !this->isPasswordlessKeyStore) {
															printNoIntegrityWarning();
														}
														if (this->alias != nullptr) {
															doPrintEntry($($nc(Main::rb)->getString("the.certificate"_s)), this->alias, out);
														} else {
															doPrintEntries(out);
														}
													} else {
														if (this->command == $Main$Command::PRINTCERT) {
															doPrintCert(out);
														} else {
															if (this->command == $Main$Command::SELFCERT) {
																doSelfCert(this->alias, this->dname, this->sigAlgName);
																this->kssave = true;
															} else {
																if (this->command == $Main$Command::STOREPASSWD) {
																	doChangeStorePasswd();
																	this->kssave = true;
																} else {
																	if (this->command == $Main$Command::GENCERT) {
																		if (this->alias == nullptr) {
																			$set(this, alias, Main::keyAlias);
																		}
																		$var($InputStream, inStream, $System::in);
																		if (this->infilename != nullptr) {
																			$assign(inStream, $new($FileInputStream, this->infilename));
																		}
																		$var($PrintStream, ps, nullptr);
																		if (this->outfilename != nullptr) {
																			$assign(ps, $new($PrintStream, static_cast<$OutputStream*>($$new($FileOutputStream, this->outfilename))));
																			$assign(out, ps);
																		}
																		{
																			$var($Throwable, var$17, nullptr);
																			try {
																				doGenCert(this->alias, this->sigAlgName, inStream, out);
																			} catch ($Throwable& var$18) {
																				$assign(var$17, var$18);
																			} /*finally*/ {
																				if (inStream != $System::in) {
																					$nc(inStream)->close();
																				}
																				if (ps != nullptr) {
																					ps->close();
																				}
																			}
																			if (var$17 != nullptr) {
																				$throw(var$17);
																			}
																		}
																	} else {
																		if (this->command == $Main$Command::GENCRL) {
																			if (this->alias == nullptr) {
																				$set(this, alias, Main::keyAlias);
																			}
																			if (this->filename != nullptr) {
																				{
																					$var($PrintStream, ps, $new($PrintStream, static_cast<$OutputStream*>($$new($FileOutputStream, this->filename))));
																					{
																						$var($Throwable, var$19, nullptr);
																						try {
																							try {
																								doGenCRL(ps);
																							} catch ($Throwable& t$) {
																								try {
																									ps->close();
																								} catch ($Throwable& x2) {
																									t$->addSuppressed(x2);
																								}
																								$throw(t$);
																							}
																						} catch ($Throwable& var$20) {
																							$assign(var$19, var$20);
																						} /*finally*/ {
																							ps->close();
																						}
																						if (var$19 != nullptr) {
																							$throw(var$19);
																						}
																					}
																				}
																			} else {
																				doGenCRL(out);
																			}
																		} else {
																			if (this->command == $Main$Command::PRINTCERTREQ) {
																				if (this->filename != nullptr) {
																					{
																						$var($InputStream, inStream, $new($FileInputStream, this->filename));
																						{
																							$var($Throwable, var$21, nullptr);
																							try {
																								try {
																									doPrintCertReq(inStream, out);
																								} catch ($Throwable& t$) {
																									try {
																										inStream->close();
																									} catch ($Throwable& x2) {
																										t$->addSuppressed(x2);
																									}
																									$throw(t$);
																								}
																							} catch ($Throwable& var$22) {
																								$assign(var$21, var$22);
																							} /*finally*/ {
																								inStream->close();
																							}
																							if (var$21 != nullptr) {
																								$throw(var$21);
																							}
																						}
																					}
																				} else {
																					doPrintCertReq($System::in, out);
																				}
																			} else {
																				if (this->command == $Main$Command::PRINTCRL) {
																					doPrintCRL(this->filename, out);
																				} else {
																					if (this->command == $Main$Command::SHOWINFO) {
																						doShowInfo();
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (this->kssave) {
		if (this->verbose) {
			$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString(".Storing.ksfname."_s))));
			$var($ObjectArray, source, $new($ObjectArray, {this->nullStream ? $of("keystore"_s) : $of(this->ksfname)}));
			$nc($System::err)->println($(form->format(source)));
		}
		if (this->token) {
			$nc(this->keyStore)->store(nullptr, nullptr);
		} else {
			$var($chars, pass, (this->storePassNew != nullptr) ? this->storePassNew : this->storePass);
			if (this->nullStream) {
				$nc(this->keyStore)->store(nullptr, pass);
			} else {
				$var($ByteArrayOutputStream, bout, $new($ByteArrayOutputStream));
				$nc(this->keyStore)->store(bout, pass);
				{
					$var($FileOutputStream, fout, $new($FileOutputStream, this->ksfname));
					{
						$var($Throwable, var$23, nullptr);
						try {
							try {
								fout->write($(bout->toByteArray()));
							} catch ($Throwable& t$) {
								try {
									fout->close();
								} catch ($Throwable& x2) {
									t$->addSuppressed(x2);
								}
								$throw(t$);
							}
						} catch ($Throwable& var$24) {
							$assign(var$23, var$24);
						} /*finally*/ {
							fout->close();
						}
						if (var$23 != nullptr) {
							$throw(var$23);
						}
					}
				}
			}
		}
	}
	if (isKeyStoreRelated(this->command) && !this->token && !this->nullStream && this->ksfname != nullptr) {
		$var($File, f, $new($File, this->ksfname));
		$var($chars, pass, (this->storePassNew != nullptr) ? this->storePassNew : this->storePass);
		if (f->exists()) {
			$var($String, realType, this->storetype);
			try {
				$set(this, keyStore, $KeyStore::getInstance(f, pass));
				$assign(realType, $nc(this->keyStore)->getType());
				bool var$25 = $nc(realType)->equalsIgnoreCase("JKS"_s);
				if (var$25 || $nc(realType)->equalsIgnoreCase("JCEKS"_s)) {
					bool allCerts = true;
					{
						$var($Iterator, i$, $nc($($Collections::list($($nc(this->keyStore)->aliases()))))->iterator());
						for (; $nc(i$)->hasNext();) {
							$var($String, a, $cast($String, i$->next()));
							{
								$load($KeyStore$TrustedCertificateEntry);
								if (!$nc(this->keyStore)->entryInstanceOf(a, $KeyStore$TrustedCertificateEntry::class$)) {
									allCerts = false;
									break;
								}
							}
						}
					}
					if (!allCerts) {
						$nc(this->weakWarnings)->add($($String::format($($nc(Main::rb)->getString("jks.storetype.warning"_s)), $$new($ObjectArray, {
							$of(realType),
							$of(this->ksfname)
						}))));
					}
				}
			} catch ($KeyStoreException& e) {
			}
			if (this->inplaceImport) {
				$var($String, realSourceStoreType, this->srcstoretype);
				try {
					$assign(realSourceStoreType, $nc($($KeyStore::getInstance($$new($File, this->inplaceBackupName), this->srcstorePass)))->getType());
				} catch ($KeyStoreException& e) {
				}
				$var($String, format, $nc(realType)->equalsIgnoreCase(realSourceStoreType) ? $nc(Main::rb)->getString("backup.keystore.warning"_s) : $nc(Main::rb)->getString("migrate.keystore.warning"_s));
				$nc(this->weakWarnings)->add($($String::format(format, $$new($ObjectArray, {
					$of(this->srcksfname),
					$of(realSourceStoreType),
					$of(this->inplaceBackupName),
					$of(realType)
				}))));
			}
		}
	}
}

void Main::doGenCert($String* alias, $String* sigAlgName$renamed, $InputStream* in, $PrintStream* out) {
	$useLocalCurrentObjectStackCache();
	$var($String, sigAlgName, sigAlgName$renamed);
	if ($nc(this->keyStore)->containsAlias(alias) == false) {
		$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("Alias.alias.does.not.exist"_s))));
		$var($ObjectArray, source, $new($ObjectArray, {$of(alias)}));
		$throwNew($Exception, $(form->format(source)));
	}
	$var($Certificate, signerCert, $nc(this->keyStore)->getCertificate(alias));
	$var($bytes, encoded, $nc(signerCert)->getEncoded());
	$var($X509CertImpl, signerCertImpl, $new($X509CertImpl, encoded));
	$init($X509CertImpl);
	$var($X509CertInfo, signerCertInfo, $cast($X509CertInfo, signerCertImpl->get($$str({$X509CertImpl::NAME, "."_s, $X509CertImpl::INFO}))));
	$init($X509CertInfo);
	$var($X500Name, issuer, $cast($X500Name, $nc(signerCertInfo)->get($$str({$X509CertInfo::SUBJECT, "."_s, $X509CertInfo::DN_NAME}))));
	$var($Date, firstDate, getStartDate(this->startDate));
	$var($Date, lastDate, $new($Date));
	lastDate->setTime($nc(firstDate)->getTime() + this->validity * (int64_t)1000 * (int64_t)24 * (int64_t)60 * (int64_t)60);
	$var($CertificateValidity, interval, $new($CertificateValidity, firstDate, lastDate));
	$var($PrivateKey, privateKey, $cast($PrivateKey, $nc($(recoverKey(alias, this->storePass, this->keyPass)))->fst));
	if (sigAlgName == nullptr) {
		$assign(sigAlgName, getCompatibleSigAlgName(privateKey));
	}
	$var($X509CertInfo, info, $new($X509CertInfo));
	info->set($X509CertInfo::VALIDITY, interval);
	info->set($X509CertInfo::SERIAL_NUMBER, $($CertificateSerialNumber::newRandom64bit($$new($SecureRandom))));
	info->set($X509CertInfo::VERSION, $$new($CertificateVersion, $CertificateVersion::V3));
	info->set($X509CertInfo::ISSUER, issuer);
	$var($BufferedReader, reader, $new($BufferedReader, $$new($InputStreamReader, in)));
	bool canRead = false;
	$var($StringBuilder, sb, $new($StringBuilder));
	while (true) {
		$var($String, s, reader->readLine());
		if (s == nullptr) {
			break;
		}
		bool var$0 = $nc(s)->startsWith("-----BEGIN"_s);
		if (var$0 && s->indexOf("REQUEST"_s) >= 0) {
			canRead = true;
		} else {
			bool var$2 = s->startsWith("-----END"_s);
			if (var$2 && s->indexOf("REQUEST"_s) >= 0) {
				break;
			} else if (canRead) {
				sb->append(s);
			}
		}
	}
	$var($bytes, rawReq, $Pem::decode($$new($String, sb)));
	$var($PKCS10, req, $new($PKCS10, rawReq));
	checkWeak($($nc(Main::rb)->getString("the.certificate.request"_s)), req);
	info->set($X509CertInfo::KEY, $$new($CertificateX509Key, $(req->getSubjectPublicKeyInfo())));
	info->set($X509CertInfo::SUBJECT, this->dname == nullptr ? $($of(req->getSubjectName())) : $of($$new($X500Name, this->dname)));
	$var($CertificateExtensions, reqex, nullptr);
	$var($Iterator, attrs, $nc($($nc($(req->getAttributes()))->getAttributes()))->iterator());
	while ($nc(attrs)->hasNext()) {
		$var($PKCS10Attribute, attr, $cast($PKCS10Attribute, attrs->next()));
		$init($PKCS9Attribute);
		if ($nc($($nc(attr)->getAttributeId()))->equals($PKCS9Attribute::EXTENSION_REQUEST_OID)) {
			$assign(reqex, $cast($CertificateExtensions, attr->getAttributeValue()));
		}
	}
	$var($PublicKey, subjectPubKey, req->getSubjectPublicKeyInfo());
	$var($PublicKey, issuerPubKey, signerCert->getPublicKey());
	$var($KeyIdentifier, signerSubjectKeyId, nullptr);
	$var($bytes, var$3, $nc(subjectPubKey)->getEncoded());
	if ($Arrays::equals(var$3, $($nc(issuerPubKey)->getEncoded()))) {
		$assign(signerSubjectKeyId, nullptr);
	} else {
		$var($X509CertImpl, certImpl, nullptr);
		if ($instanceOf($X509CertImpl, signerCert)) {
			$assign(certImpl, $cast($X509CertImpl, signerCert));
		} else {
			$assign(certImpl, $new($X509CertImpl, $(signerCert->getEncoded())));
		}
		$assign(signerSubjectKeyId, $nc(certImpl)->getSubjectKeyId());
		if (signerSubjectKeyId == nullptr) {
			$assign(signerSubjectKeyId, $new($KeyIdentifier, issuerPubKey));
		}
	}
	$var($CertificateExtensions, ext, createV3Extensions(reqex, nullptr, this->v3ext, subjectPubKey, signerSubjectKeyId));
	info->set($X509CertInfo::EXTENSIONS, ext);
	$var($X509CertImpl, cert, $new($X509CertImpl, info));
	cert->sign(privateKey, sigAlgName);
	dumpCert(cert, out);
	{
		$var($CertificateArray, arr$, $nc(this->keyStore)->getCertificateChain(alias));
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Certificate, ca, arr$->get(i$));
			{
				if ($instanceOf($X509Certificate, ca)) {
					$var($X509Certificate, xca, $cast($X509Certificate, ca));
					if (!$KeyStoreUtil::isSelfSigned(xca)) {
						dumpCert(xca, out);
					}
				}
			}
		}
	}
	$var($String, var$4, $nc(Main::rb)->getString("the.issuer"_s));
	checkWeak(var$4, $($nc(this->keyStore)->getCertificateChain(alias)));
	checkWeak($($nc(Main::rb)->getString("the.generated.certificate"_s)), static_cast<$Certificate*>(cert));
}

void Main::doGenCRL($PrintStream* out) {
	$useLocalCurrentObjectStackCache();
	if (this->ids == nullptr) {
		$throwNew($Exception, "Must provide -id when -gencrl"_s);
	}
	$var($Certificate, signerCert, $nc(this->keyStore)->getCertificate(this->alias));
	$var($bytes, encoded, $nc(signerCert)->getEncoded());
	$var($X509CertImpl, signerCertImpl, $new($X509CertImpl, encoded));
	$init($X509CertImpl);
	$var($X509CertInfo, signerCertInfo, $cast($X509CertInfo, signerCertImpl->get($$str({$X509CertImpl::NAME, "."_s, $X509CertImpl::INFO}))));
	$init($X509CertInfo);
	$var($X500Name, owner, $cast($X500Name, $nc(signerCertInfo)->get($$str({$X509CertInfo::SUBJECT, "."_s, $X509CertInfo::DN_NAME}))));
	$var($Date, firstDate, getStartDate(this->startDate));
	$var($Date, lastDate, $cast($Date, $nc(firstDate)->clone()));
	$nc(lastDate)->setTime(lastDate->getTime() + this->validity * 1000 * 24 * 60 * 60);
	$var($CertificateValidity, interval, $new($CertificateValidity, firstDate, lastDate));
	$var($PrivateKey, privateKey, $cast($PrivateKey, $nc($(recoverKey(this->alias, this->storePass, this->keyPass)))->fst));
	if (this->sigAlgName == nullptr) {
		$set(this, sigAlgName, getCompatibleSigAlgName(privateKey));
	}
	$var($X509CRLEntryArray, badCerts, $new($X509CRLEntryArray, $nc(this->ids)->size()));
	for (int32_t i = 0; i < $nc(this->ids)->size(); ++i) {
		$var($String, id, $cast($String, $nc(this->ids)->get(i)));
		int32_t d = $nc(id)->indexOf((int32_t)u':');
		if (d >= 0) {
			$var($CRLExtensions, ext, $new($CRLExtensions));
			ext->set("Reason"_s, $$new($CRLReasonCodeExtension, $Integer::parseInt($(id->substring(d + 1)))));
			badCerts->set(i, $$new($X509CRLEntryImpl, $$new($BigInteger, $(id->substring(0, d))), firstDate, ext));
		} else {
			badCerts->set(i, $$new($X509CRLEntryImpl, $$new($BigInteger, $cast($String, $($nc(this->ids)->get(i)))), firstDate));
		}
	}
	$var($X509CRLImpl, crl, $new($X509CRLImpl, owner, firstDate, lastDate, badCerts));
	crl->sign(privateKey, this->sigAlgName);
	if (this->rfc) {
		$nc(out)->println("-----BEGIN X509 CRL-----"_s);
		out->println($($nc($($Base64::getMimeEncoder(64, Main::CRLF)))->encodeToString($(crl->getEncodedInternal()))));
		out->println("-----END X509 CRL-----"_s);
	} else {
		$nc(out)->write($(crl->getEncodedInternal()));
	}
	checkWeak($($nc(Main::rb)->getString("the.generated.crl"_s)), static_cast<$CRL*>(crl), static_cast<$Key*>(privateKey));
}

void Main::doCertReq($String* alias$renamed, $String* sigAlgName$renamed, $PrintStream* out) {
	$useLocalCurrentObjectStackCache();
	$var($String, alias, alias$renamed);
	$var($String, sigAlgName, sigAlgName$renamed);
	if (alias == nullptr) {
		$assign(alias, Main::keyAlias);
	}
	$var($Pair, objs, recoverKey(alias, this->storePass, this->keyPass));
	$var($PrivateKey, privKey, $cast($PrivateKey, $nc(objs)->fst));
	if (this->keyPass == nullptr) {
		$set(this, keyPass, $cast($chars, objs->snd));
	}
	$var($Certificate, cert, $nc(this->keyStore)->getCertificate(alias));
	if (cert == nullptr) {
		$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("alias.has.no.public.key.certificate."_s))));
		$var($ObjectArray, source, $new($ObjectArray, {$of(alias)}));
		$throwNew($Exception, $(form->format(source)));
	}
	$var($PKCS10, request, $new($PKCS10, $($nc(cert)->getPublicKey())));
	$var($CertificateExtensions, ext, createV3Extensions(nullptr, nullptr, this->v3ext, $($nc(cert)->getPublicKey()), nullptr));
	$init($X509CertInfo);
	$init($PKCS9Attribute);
	$nc($(request->getAttributes()))->setAttribute($X509CertInfo::EXTENSIONS, $$new($PKCS10Attribute, $PKCS9Attribute::EXTENSION_REQUEST_OID, ext));
	if (sigAlgName == nullptr) {
		$assign(sigAlgName, getCompatibleSigAlgName(privKey));
	}
	$var($X500Name, subject, this->dname == nullptr ? $new($X500Name, $($nc($($nc(($cast($X509Certificate, cert)))->getSubjectX500Principal()))->getEncoded())) : $new($X500Name, this->dname));
	request->encodeAndSign(subject, privKey, sigAlgName);
	request->print(out);
	checkWeak($($nc(Main::rb)->getString("the.generated.certificate.request"_s)), request);
}

void Main::doDeleteEntry($String* alias) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->keyStore)->containsAlias(alias) == false) {
		$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("Alias.alias.does.not.exist"_s))));
		$var($ObjectArray, source, $new($ObjectArray, {$of(alias)}));
		$throwNew($Exception, $(form->format(source)));
	}
	$nc(this->keyStore)->deleteEntry(alias);
}

void Main::doExportCert($String* alias$renamed, $PrintStream* out) {
	$useLocalCurrentObjectStackCache();
	$var($String, alias, alias$renamed);
	if (this->storePass == nullptr && !$KeyStoreUtil::isWindowsKeyStore(this->storetype) && !this->isPasswordlessKeyStore) {
		printNoIntegrityWarning();
	}
	if (alias == nullptr) {
		$assign(alias, Main::keyAlias);
	}
	if ($nc(this->keyStore)->containsAlias(alias) == false) {
		$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("Alias.alias.does.not.exist"_s))));
		$var($ObjectArray, source, $new($ObjectArray, {$of(alias)}));
		$throwNew($Exception, $(form->format(source)));
	}
	$var($X509Certificate, cert, $cast($X509Certificate, $nc(this->keyStore)->getCertificate(alias)));
	if (cert == nullptr) {
		$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("Alias.alias.has.no.certificate"_s))));
		$var($ObjectArray, source, $new($ObjectArray, {$of(alias)}));
		$throwNew($Exception, $(form->format(source)));
	}
	dumpCert(cert, out);
	checkWeak($($nc(Main::rb)->getString("the.certificate"_s)), static_cast<$Certificate*>(cert));
}

$chars* Main::promptForKeyPass($String* alias, $String* orig, $chars* origPass) {
	$useLocalCurrentObjectStackCache();
	if (origPass != nullptr && $nc(Main::P12KEYSTORE)->equalsIgnoreCase(this->storetype)) {
		return origPass;
	} else if (!this->token && !this->protectedPath) {
		int32_t count = 0;
		for (count = 0; count < 3; ++count) {
			$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("Enter.key.password.for.alias."_s))));
			$var($ObjectArray, source, $new($ObjectArray, {$of(alias)}));
			$nc($System::err)->print($(form->format(source)));
			if (origPass != nullptr) {
				$nc($System::err)->println();
				if (orig == nullptr) {
					$nc($System::err)->print($($nc(Main::rb)->getString(".RETURN.if.same.as.keystore.password."_s)));
				} else {
					$assign(form, $new($MessageFormat, $($nc(Main::rb)->getString(".RETURN.if.same.as.for.otherAlias."_s))));
					$var($ObjectArray, src, $new($ObjectArray, {$of(orig)}));
					$nc($System::err)->print($(form->format(src)));
				}
			}
			$nc($System::err)->flush();
			$var($chars, entered, $Password::readPassword($System::in));
			$nc(this->passwords)->add(entered);
			if (entered == nullptr && origPass != nullptr) {
				return origPass;
			} else if (entered != nullptr && entered->length >= 6) {
				$nc($System::err)->print($($nc(Main::rb)->getString("Re.enter.new.password."_s)));
				$var($chars, passAgain, $Password::readPassword($System::in));
				$nc(this->passwords)->add(passAgain);
				if (!$Arrays::equals(entered, passAgain)) {
					$nc($System::err)->println($($nc(Main::rb)->getString("They.don.t.match.Try.again"_s)));
					continue;
				}
				return entered;
			} else {
				$nc($System::err)->println($($nc(Main::rb)->getString("Key.password.is.too.short.must.be.at.least.6.characters"_s)));
			}
		}
		if (count == 3) {
			$init($Main$Command);
			if (this->command == $Main$Command::KEYCLONE) {
				$throwNew($Exception, $($nc(Main::rb)->getString("Too.many.failures.Key.entry.not.cloned"_s)));
			} else {
				$throwNew($Exception, $($nc(Main::rb)->getString("Too.many.failures.key.not.added.to.keystore"_s)));
			}
		}
	}
	return nullptr;
}

$chars* Main::promptForCredential() {
	$useLocalCurrentObjectStackCache();
	if ($System::console() == nullptr) {
		$var($chars, importPass, $Password::readPassword($System::in));
		$nc(this->passwords)->add(importPass);
		return importPass;
	}
	int32_t count = 0;
	for (count = 0; count < 3; ++count) {
		$nc($System::err)->print($($nc(Main::rb)->getString("Enter.the.password.to.be.stored."_s)));
		$nc($System::err)->flush();
		$var($chars, entered, $Password::readPassword($System::in));
		$nc(this->passwords)->add(entered);
		$nc($System::err)->print($($nc(Main::rb)->getString("Re.enter.password."_s)));
		$var($chars, passAgain, $Password::readPassword($System::in));
		$nc(this->passwords)->add(passAgain);
		if (!$Arrays::equals(entered, passAgain)) {
			$nc($System::err)->println($($nc(Main::rb)->getString("They.don.t.match.Try.again"_s)));
			continue;
		}
		return entered;
	}
	if (count == 3) {
		$throwNew($Exception, $($nc(Main::rb)->getString("Too.many.failures.key.not.added.to.keystore"_s)));
	}
	return nullptr;
}

void Main::doGenSecretKey($String* alias$renamed, $String* keyAlgName, int32_t keysize) {
	$useLocalCurrentObjectStackCache();
	$var($String, alias, alias$renamed);
	if (alias == nullptr) {
		$assign(alias, Main::keyAlias);
	}
	if ($nc(this->keyStore)->containsAlias(alias)) {
		$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("Secret.key.not.generated.alias.alias.already.exists"_s))));
		$var($ObjectArray, source, $new($ObjectArray, {$of(alias)}));
		$throwNew($Exception, $(form->format(source)));
	}
	bool useDefaultPBEAlgorithm = true;
	$var($SecretKey, secKey, nullptr);
	$init($Locale);
	if ($($nc(keyAlgName)->toUpperCase($Locale::ENGLISH))->startsWith("PBE"_s)) {
		$var($SecretKeyFactory, factory, $SecretKeyFactory::getInstance("PBE"_s));
		$assign(secKey, $nc(factory)->generateSecret($$new($PBEKeySpec, $(promptForCredential()))));
		if (!"PBE"_s->equalsIgnoreCase(keyAlgName)) {
			useDefaultPBEAlgorithm = false;
		}
		if (this->verbose) {
			$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("Generated.keyAlgName.secret.key"_s))));
			$var($ObjectArray, source, $new($ObjectArray, {useDefaultPBEAlgorithm ? $of("PBE"_s) : $($of($nc(secKey)->getAlgorithm()))}));
			$nc($System::err)->println($(form->format(source)));
		}
	} else {
		$var($KeyGenerator, keygen, $KeyGenerator::getInstance(keyAlgName));
		if (keysize == -1) {
			if ("DES"_s->equalsIgnoreCase(keyAlgName)) {
				keysize = 56;
			} else if ("DESede"_s->equalsIgnoreCase(keyAlgName)) {
				keysize = 168;
			} else {
				$throwNew($Exception, $($nc(Main::rb)->getString("Please.provide.keysize.for.secret.key.generation"_s)));
			}
		}
		$nc(keygen)->init(keysize);
		$assign(secKey, keygen->generateKey());
		$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("Generated.keysize.bit.keyAlgName.secret.key"_s))));
		$var($ObjectArray, source, $new($ObjectArray, {
			$($of($Integer::valueOf(keysize))),
			$($of($nc(secKey)->getAlgorithm()))
		}));
		$nc($System::err)->println($(form->format(source)));
	}
	if (this->keyPass == nullptr) {
		$set(this, keyPass, promptForKeyPass(alias, nullptr, this->storePass));
	}
	if (useDefaultPBEAlgorithm) {
		$nc(this->keyStore)->setKeyEntry(alias, secKey, this->keyPass, nullptr);
	} else {
		$var($String, var$0, alias);
		$var($KeyStore$Entry, var$1, static_cast<$KeyStore$Entry*>($new($KeyStore$SecretKeyEntry, secKey)));
		$nc(this->keyStore)->setEntry(var$0, var$1, $$new($KeyStore$PasswordProtection, this->keyPass, keyAlgName, nullptr));
	}
}

$String* Main::getCompatibleSigAlgName($PrivateKey* key) {
	$init(Main);
	$useLocalCurrentObjectStackCache();
	$var($String, result, $SignatureUtil::getDefaultSigAlgForKey(key));
	if (result != nullptr) {
		return result;
	} else {
		$throwNew($Exception, $($nc(Main::rb)->getString("Cannot.derive.signature.algorithm"_s)));
	}
}

void Main::doGenKeyPair($String* alias$renamed, $String* dname, $String* keyAlgName, int32_t keysize, $String* groupName, $String* sigAlgName, $String* signerAlias) {
	$useLocalCurrentObjectStackCache();
	$var($String, alias, alias$renamed);
	if (groupName != nullptr) {
		if (keysize != -1) {
			$throwNew($Exception, $($nc(Main::rb)->getString("groupname.keysize.coexist"_s)));
		}
	} else if (keysize == -1) {
		if ("EC"_s->equalsIgnoreCase(keyAlgName)) {
			$init($SecurityProviderConstants);
			keysize = $SecurityProviderConstants::DEF_EC_KEY_SIZE;
		} else if ("RSA"_s->equalsIgnoreCase(keyAlgName)) {
			$init($SecurityProviderConstants);
			keysize = $SecurityProviderConstants::DEF_RSA_KEY_SIZE;
		} else if ("DSA"_s->equalsIgnoreCase(keyAlgName)) {
			$init($SecurityProviderConstants);
			keysize = $SecurityProviderConstants::DEF_DSA_KEY_SIZE;
		} else if ("EdDSA"_s->equalsIgnoreCase(keyAlgName)) {
			$init($SecurityProviderConstants);
			keysize = $SecurityProviderConstants::DEF_ED_KEY_SIZE;
		} else if ("Ed25519"_s->equalsIgnoreCase(keyAlgName)) {
			keysize = 255;
		} else if ("Ed448"_s->equalsIgnoreCase(keyAlgName)) {
			keysize = 448;
		} else if ("XDH"_s->equalsIgnoreCase(keyAlgName)) {
			$init($SecurityProviderConstants);
			keysize = $SecurityProviderConstants::DEF_XEC_KEY_SIZE;
		} else if ("X25519"_s->equalsIgnoreCase(keyAlgName)) {
			keysize = 255;
		} else if ("X448"_s->equalsIgnoreCase(keyAlgName)) {
			keysize = 448;
		} else if ("DH"_s->equalsIgnoreCase(keyAlgName)) {
			$init($SecurityProviderConstants);
			keysize = $SecurityProviderConstants::DEF_DH_KEY_SIZE;
		}
	} else if ("EC"_s->equalsIgnoreCase(keyAlgName)) {
		$var($String, var$0, $nc(Main::rb)->getString("deprecate.keysize.for.ec"_s));
		$nc(this->weakWarnings)->add($($String::format(var$0, $$new($ObjectArray, {$($of(ecGroupNameForSize(keysize)))}))));
	}
	if (alias == nullptr) {
		$assign(alias, Main::keyAlias);
	}
	if ($nc(this->keyStore)->containsAlias(alias)) {
		$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("Key.pair.not.generated.alias.alias.already.exists"_s))));
		$var($ObjectArray, source, $new($ObjectArray, {$of(alias)}));
		$throwNew($Exception, $(form->format(source)));
	}
	$var($CertAndKeyGen, keypair, nullptr);
	$var($KeyIdentifier, signerSubjectKeyId, nullptr);
	if (signerAlias != nullptr) {
		$var($PrivateKey, signerPrivateKey, $cast($PrivateKey, $nc($(recoverKey(signerAlias, this->storePass, this->signerKeyPass)))->fst));
		$var($Certificate, signerCert, $nc(this->keyStore)->getCertificate(signerAlias));
		$var($X509CertImpl, signerCertImpl, nullptr);
		if ($instanceOf($X509CertImpl, signerCert)) {
			$assign(signerCertImpl, $cast($X509CertImpl, signerCert));
		} else {
			$assign(signerCertImpl, $new($X509CertImpl, $($nc(signerCert)->getEncoded())));
		}
		$init($X509CertImpl);
		$var($X509CertInfo, signerCertInfo, $cast($X509CertInfo, $nc(signerCertImpl)->get($$str({$X509CertImpl::NAME, "."_s, $X509CertImpl::INFO}))));
		$init($X509CertInfo);
		$var($X500Name, signerSubjectName, $cast($X500Name, $nc(signerCertInfo)->get($$str({$X509CertInfo::SUBJECT, "."_s, $X509CertInfo::DN_NAME}))));
		$assign(keypair, $new($CertAndKeyGen, keyAlgName, sigAlgName, this->providerName, signerPrivateKey, signerSubjectName));
		$assign(signerSubjectKeyId, signerCertImpl->getSubjectKeyId());
		if (signerSubjectKeyId == nullptr) {
			$assign(signerSubjectKeyId, $new($KeyIdentifier, $($nc(signerCert)->getPublicKey())));
		}
	} else {
		$assign(keypair, $new($CertAndKeyGen, keyAlgName, sigAlgName, this->providerName));
	}
	$var($X500Name, x500Name, nullptr);
	if (dname == nullptr) {
		printWeakWarnings(true);
		$assign(x500Name, getX500Name());
	} else {
		$assign(x500Name, $new($X500Name, dname));
	}
	if (groupName != nullptr) {
		$nc(keypair)->generate(groupName);
	} else {
		$nc(keypair)->generate(keysize);
	}
	$var($CertificateExtensions, ext, createV3Extensions(nullptr, nullptr, this->v3ext, $($nc(keypair)->getPublicKeyAnyway()), signerSubjectKeyId));
	$var($PrivateKey, privKey, $nc(keypair)->getPrivateKey());
	$var($X509Certificate, newCert, keypair->getSelfCertificate(x500Name, $(getStartDate(this->startDate)), this->validity * (int64_t)24 * (int64_t)60 * (int64_t)60, ext));
	if (signerAlias != nullptr) {
		$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("Generating.keysize.bit.keyAlgName.key.pair.and.a.certificate.sigAlgName.issued.by.signerAlias.with.a.validity.of.validality.days.for"_s))));
		$var($ObjectArray, source, $new($ObjectArray, {
			$($of($Integer::valueOf(groupName == nullptr ? keysize : $KeyUtil::getKeySize(static_cast<$Key*>(privKey))))),
			$($of(fullDisplayAlgName(privKey))),
			$($of($nc(newCert)->getSigAlgName())),
			$of(signerAlias),
			$($of($Long::valueOf(this->validity))),
			$of(x500Name)
		}));
		$nc($System::err)->println($(form->format(source)));
	} else {
		$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("Generating.keysize.bit.keyAlgName.key.pair.and.self.signed.certificate.sigAlgName.with.a.validity.of.validality.days.for"_s))));
		$var($ObjectArray, source, $new($ObjectArray, {
			$($of($Integer::valueOf(groupName == nullptr ? keysize : $KeyUtil::getKeySize(static_cast<$Key*>(privKey))))),
			$($of(fullDisplayAlgName(privKey))),
			$($of($nc(newCert)->getSigAlgName())),
			$($of($Long::valueOf(this->validity))),
			$of(x500Name)
		}));
		$nc($System::err)->println($(form->format(source)));
	}
	if (this->keyPass == nullptr) {
		$set(this, keyPass, promptForKeyPass(alias, nullptr, this->storePass));
	}
	$var($CertificateArray, finalChain, nullptr);
	if (signerAlias != nullptr) {
		$var($CertificateArray, signerChain, $nc(this->keyStore)->getCertificateChain(signerAlias));
		$assign(finalChain, $fcast($CertificateArray, $new($X509CertificateArray, $nc(signerChain)->length + 1)));
		finalChain->set(0, newCert);
		$System::arraycopy(signerChain, 0, finalChain, 1, signerChain->length);
	} else {
		$assign(finalChain, $new($CertificateArray, {static_cast<$Certificate*>(newCert)}));
	}
	checkWeak($($nc(Main::rb)->getString("the.generated.certificate"_s)), finalChain);
	$nc(this->keyStore)->setKeyEntry(alias, privKey, this->keyPass, finalChain);
}

$String* Main::ecGroupNameForSize(int32_t size) {
	$useLocalCurrentObjectStackCache();
	$var($AlgorithmParameters, ap, $AlgorithmParameters::getInstance("EC"_s));
	$nc(ap)->init(static_cast<$AlgorithmParameterSpec*>($$new($ECKeySizeParameterSpec, size)));
	return $($nc($(ap->toString()))->split(" "_s))->get(0);
}

void Main::doCloneEntry($String* orig$renamed, $String* dest, bool changePassword) {
	$useLocalCurrentObjectStackCache();
	$var($String, orig, orig$renamed);
	if (orig == nullptr) {
		$assign(orig, Main::keyAlias);
	}
	if ($nc(this->keyStore)->containsAlias(dest)) {
		$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("Destination.alias.dest.already.exists"_s))));
		$var($ObjectArray, source, $new($ObjectArray, {$of(dest)}));
		$throwNew($Exception, $(form->format(source)));
	}
	$var($Pair, objs, recoverEntry(this->keyStore, orig, this->storePass, this->keyPass));
	$var($KeyStore$Entry, entry, $cast($KeyStore$Entry, $nc(objs)->fst));
	$set(this, keyPass, $cast($chars, objs->snd));
	$var($KeyStore$PasswordProtection, pp, nullptr);
	if (this->keyPass != nullptr) {
		if (!changePassword || $nc(Main::P12KEYSTORE)->equalsIgnoreCase(this->storetype)) {
			$set(this, keyPassNew, this->keyPass);
		} else if (this->keyPassNew == nullptr) {
			$set(this, keyPassNew, promptForKeyPass(dest, orig, this->keyPass));
		}
		$assign(pp, $new($KeyStore$PasswordProtection, this->keyPassNew));
	}
	$nc(this->keyStore)->setEntry(dest, entry, pp);
}

void Main::doChangeKeyPasswd($String* alias$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($String, alias, alias$renamed);
	if (alias == nullptr) {
		$assign(alias, Main::keyAlias);
	}
	$var($Pair, objs, recoverKey(alias, this->storePass, this->keyPass));
	$var($Key, privKey, $cast($Key, $nc(objs)->fst));
	if (this->keyPass == nullptr) {
		$set(this, keyPass, $cast($chars, objs->snd));
	}
	if (this->keyPassNew == nullptr) {
		$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("key.password.for.alias."_s))));
		$var($ObjectArray, source, $new($ObjectArray, {$of(alias)}));
		$set(this, keyPassNew, getNewPasswd($(form->format(source)), this->keyPass));
	}
	$nc(this->keyStore)->setKeyEntry(alias, privKey, this->keyPassNew, $($nc(this->keyStore)->getCertificateChain(alias)));
}

void Main::doImportIdentityDatabase($InputStream* in) {
	$nc($System::err)->println($($nc(Main::rb)->getString("No.entries.from.identity.database.added"_s)));
}

void Main::doPrintEntry($String* label, $String* alias, $PrintStream* out) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->keyStore)->containsAlias(alias) == false) {
		$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("Alias.alias.does.not.exist"_s))));
		$var($ObjectArray, source, $new($ObjectArray, {$of(alias)}));
		$throwNew($Exception, $(form->format(source)));
	}
	if (this->verbose || this->rfc || this->debug) {
		$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("Alias.name.alias"_s))));
		$var($ObjectArray, source, $new($ObjectArray, {$of(alias)}));
		$nc(out)->println($(form->format(source)));
		if (!this->token) {
			$assign(form, $new($MessageFormat, $($nc(Main::rb)->getString("Creation.date.keyStore.getCreationDate.alias."_s))));
			$var($ObjectArray, src, $new($ObjectArray, {$($of($nc(this->keyStore)->getCreationDate(alias)))}));
			out->println($(form->format(src)));
		}
	} else if (!this->token) {
		$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("alias.keyStore.getCreationDate.alias."_s))));
		$var($ObjectArray, source, $new($ObjectArray, {
			$of(alias),
			$($of($nc(this->keyStore)->getCreationDate(alias)))
		}));
		$nc(out)->print($(form->format(source)));
	} else {
		$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("alias."_s))));
		$var($ObjectArray, source, $new($ObjectArray, {$of(alias)}));
		$nc(out)->print($(form->format(source)));
	}
	$load($KeyStore$SecretKeyEntry);
	if ($nc(this->keyStore)->entryInstanceOf(alias, $KeyStore$SecretKeyEntry::class$)) {
		if (this->verbose || this->rfc || this->debug) {
			$var($ObjectArray, source, $new($ObjectArray, {$of("SecretKeyEntry"_s)}));
			$nc(out)->println($($$new($MessageFormat, $($nc(Main::rb)->getString("Entry.type.type."_s)))->format(source)));
		} else {
			$nc(out)->println("SecretKeyEntry, "_s);
		}
	} else {
		$load($KeyStore$PrivateKeyEntry);
		if ($nc(this->keyStore)->entryInstanceOf(alias, $KeyStore$PrivateKeyEntry::class$)) {
			if (this->verbose || this->rfc || this->debug) {
				$var($ObjectArray, source, $new($ObjectArray, {$of("PrivateKeyEntry"_s)}));
				$nc(out)->println($($$new($MessageFormat, $($nc(Main::rb)->getString("Entry.type.type."_s)))->format(source)));
			} else {
				$nc(out)->println("PrivateKeyEntry, "_s);
			}
			$var($CertificateArray, chain, $nc(this->keyStore)->getCertificateChain(alias));
			if (chain != nullptr) {
				if (this->verbose || this->rfc || this->debug) {
					$nc(out)->println($$str({$($nc(Main::rb)->getString("Certificate.chain.length."_s)), $$str(chain->length)}));
					for (int32_t i = 0; i < chain->length; ++i) {
						$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("Certificate.i.1."_s))));
						$var($ObjectArray, source, $new($ObjectArray, {$($of($Integer::valueOf((i + 1))))}));
						out->println($(form->format(source)));
						if (this->verbose && ($instanceOf($X509Certificate, chain->get(i)))) {
							printX509Cert(($cast($X509Certificate, chain->get(i))), out);
						} else if (this->debug) {
							out->println($($nc(chain->get(i))->toString()));
						} else {
							dumpCert(chain->get(i), out);
						}
						checkWeak(label, chain->get(i));
					}
				} else {
					$var($String, var$0, $($nc(Main::rb)->getString("Certificate.fingerprint.SHA.256."_s)));
					$nc(out)->println($$concat(var$0, $(getCertFingerPrint("SHA-256"_s, chain->get(0)))));
					checkWeak(label, chain);
				}
			} else {
				$nc(out)->println($$str({$($nc(Main::rb)->getString("Certificate.chain.length."_s)), $$str(0)}));
			}
		} else {
			$load($KeyStore$TrustedCertificateEntry);
			if ($nc(this->keyStore)->entryInstanceOf(alias, $KeyStore$TrustedCertificateEntry::class$)) {
				$var($Certificate, cert, $nc(this->keyStore)->getCertificate(alias));
				$var($ObjectArray, source, $new($ObjectArray, {$of("trustedCertEntry"_s)}));
				$var($String, mf, $str({$($$new($MessageFormat, $($nc(Main::rb)->getString("Entry.type.type."_s)))->format(source)), "\n"_s}));
				if (this->verbose && ($instanceOf($X509Certificate, cert))) {
					$nc(out)->println(mf);
					printX509Cert($cast($X509Certificate, cert), out);
				} else if (this->rfc) {
					$nc(out)->println(mf);
					dumpCert(cert, out);
				} else if (this->debug) {
					$nc(out)->println($($nc(cert)->toString()));
				} else {
					$nc(out)->println("trustedCertEntry, "_s);
					$var($String, var$1, $($nc(Main::rb)->getString("Certificate.fingerprint.SHA.256."_s)));
					out->println($$concat(var$1, $(getCertFingerPrint("SHA-256"_s, cert))));
				}
				checkWeak(label, cert);
			} else {
				$nc(out)->println($($nc(Main::rb)->getString("Unknown.Entry.Type"_s)));
			}
		}
	}
}

bool Main::inplaceImportCheck() {
	$useLocalCurrentObjectStackCache();
	bool var$0 = $nc(Main::P11KEYSTORE)->equalsIgnoreCase(this->srcstoretype);
	if (var$0 || $KeyStoreUtil::isWindowsKeyStore(this->srcstoretype)) {
		return false;
	}
	if (this->srcksfname != nullptr) {
		$var($File, srcksfile, $new($File, this->srcksfname));
		bool var$1 = srcksfile->exists();
		if (var$1 && srcksfile->length() == 0) {
			$throwNew($Exception, $$str({$($nc(Main::rb)->getString("Source.keystore.file.exists.but.is.empty."_s)), this->srcksfname}));
		}
		if ($nc($(srcksfile->getCanonicalFile()))->equals($($$new($File, this->ksfname)->getCanonicalFile()))) {
			return true;
		} else {
			$nc($System::err)->println($($String::format($($nc(Main::rb)->getString("importing.keystore.status"_s)), $$new($ObjectArray, {
				$of(this->srcksfname),
				$of(this->ksfname)
			}))));
			return false;
		}
	} else {
		$throwNew($Exception, $($nc(Main::rb)->getString("Please.specify.srckeystore"_s)));
	}
}

$KeyStore* Main::loadSourceKeyStore() {
	$useLocalCurrentObjectStackCache();
	$var($InputStream, is, nullptr);
	$var($File, srcksfile, nullptr);
	bool srcIsPasswordless = false;
	bool var$0 = $nc(Main::P11KEYSTORE)->equalsIgnoreCase(this->srcstoretype);
	if (var$0 || $KeyStoreUtil::isWindowsKeyStore(this->srcstoretype)) {
		if (!$nc(Main::NONE)->equals(this->srcksfname)) {
			$nc($System::err)->println($($MessageFormat::format($($nc(Main::rb)->getString(".keystore.must.be.NONE.if.storetype.is.{0}"_s)), $$new($ObjectArray, {$of(this->srcstoretype)}))));
			$nc($System::err)->println();
			tinyHelp();
		}
	} else {
		$assign(srcksfile, $new($File, this->srcksfname));
		$assign(is, $new($FileInputStream, srcksfile));
	}
	$var($KeyStore, store, nullptr);
	{
		$var($Throwable, var$1, nullptr);
		try {
			if (srcksfile != nullptr && is != nullptr && this->srcProviderName == nullptr && this->srcstoretype == nullptr) {
				$assign(store, $KeyStore::getInstance(srcksfile, this->srcstorePass));
				$set(this, srcstoretype, $nc(store)->getType());
				if ($nc(this->srcstoretype)->equalsIgnoreCase("pkcs12"_s)) {
					srcIsPasswordless = $PKCS12KeyStore::isPasswordless(srcksfile);
				}
			} else {
				if (this->srcstoretype == nullptr) {
					$set(this, srcstoretype, $KeyStore::getDefaultType());
				}
				if (this->srcProviderName == nullptr) {
					$assign(store, $KeyStore::getInstance(this->srcstoretype));
				} else {
					$assign(store, $KeyStore::getInstance(this->srcstoretype, this->srcProviderName));
				}
			}
			if (this->srcstorePass == nullptr && !this->srcprotectedPath && !$KeyStoreUtil::isWindowsKeyStore(this->srcstoretype) && !srcIsPasswordless) {
				$nc($System::err)->print($($nc(Main::rb)->getString("Enter.source.keystore.password."_s)));
				$nc($System::err)->flush();
				$set(this, srcstorePass, $Password::readPassword($System::in));
				$nc(this->passwords)->add(this->srcstorePass);
			}
			if ($nc(Main::P12KEYSTORE)->equalsIgnoreCase(this->srcstoretype)) {
				if (this->srckeyPass != nullptr && this->srcstorePass != nullptr && !$Arrays::equals(this->srcstorePass, this->srckeyPass)) {
					$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("Warning.Different.store.and.key.passwords.not.supported.for.PKCS12.KeyStores.Ignoring.user.specified.command.value."_s))));
					$var($ObjectArray, source, $new($ObjectArray, {$of("-srckeypass"_s)}));
					$nc($System::err)->println($(form->format(source)));
					$set(this, srckeyPass, this->srcstorePass);
				}
			}
			$nc(store)->load(is, this->srcstorePass);
		} catch ($Throwable& var$2) {
			$assign(var$1, var$2);
		} /*finally*/ {
			if (is != nullptr) {
				is->close();
			}
		}
		if (var$1 != nullptr) {
			$throw(var$1);
		}
	}
	if (this->srcstorePass == nullptr && !srcIsPasswordless && !$KeyStoreUtil::isWindowsKeyStore(this->srcstoretype)) {
		$nc($System::err)->println();
		$nc($System::err)->println($($nc(Main::rb)->getString(".WARNING.WARNING.WARNING."_s)));
		$nc($System::err)->println($($nc(Main::rb)->getString(".The.integrity.of.the.information.stored.in.the.srckeystore."_s)));
		$nc($System::err)->println($($nc(Main::rb)->getString(".WARNING.WARNING.WARNING."_s)));
		$nc($System::err)->println();
	}
	return store;
}

void Main::doImportKeyStore($KeyStore* srcKS) {
	$useLocalCurrentObjectStackCache();
	if (this->alias != nullptr) {
		doImportKeyStoreSingle(srcKS, this->alias);
	} else {
		if (this->dest != nullptr || this->srckeyPass != nullptr) {
			$throwNew($Exception, $($nc(Main::rb)->getString("if.alias.not.specified.destalias.and.srckeypass.must.not.be.specified"_s)));
		}
		doImportKeyStoreAll(srcKS);
	}
	if (this->inplaceImport) {
		for (int32_t n = 1;; ++n) {
			$set(this, inplaceBackupName, $str({this->srcksfname, ".old"_s, (n == 1 ? static_cast<$Serializable*>(""_s) : $(static_cast<$Serializable*>($Integer::valueOf(n))))}));
			$var($File, bkFile, $new($File, this->inplaceBackupName));
			if (!bkFile->exists()) {
				$var($Path, var$0, $Path::of(this->srcksfname, $$new($StringArray, 0)));
				$Files::copy(var$0, $(bkFile->toPath()), $$new($CopyOptionArray, 0));
				break;
			}
		}
	}
}

int32_t Main::doImportKeyStoreSingle($KeyStore* srckeystore, $String* alias) {
	$useLocalCurrentObjectStackCache();
	$var($String, newAlias, (this->dest == nullptr) ? alias : this->dest);
	if ($nc(this->keyStore)->containsAlias(newAlias)) {
		$var($ObjectArray, source, $new($ObjectArray, {$of(alias)}));
		if (this->noprompt) {
			$nc($System::err)->println($($$new($MessageFormat, $($nc(Main::rb)->getString("Warning.Overwriting.existing.alias.alias.in.destination.keystore"_s)))->format(source)));
		} else {
			$var($String, reply, getYesNoReply($($$new($MessageFormat, $($nc(Main::rb)->getString("Existing.entry.alias.alias.exists.overwrite.no."_s)))->format(source))));
			if ("NO"_s->equals(reply)) {
				$assign(newAlias, inputStringFromStdin($($nc(Main::rb)->getString("Enter.new.alias.name.RETURN.to.cancel.import.for.this.entry."_s))));
				if (""_s->equals(newAlias)) {
					$nc($System::err)->println($($$new($MessageFormat, $($nc(Main::rb)->getString("Entry.for.alias.alias.not.imported."_s)))->format(source)));
					return 0;
				}
			}
		}
	}
	$var($Pair, objs, recoverEntry(srckeystore, alias, this->srcstorePass, this->srckeyPass));
	$var($KeyStore$Entry, entry, $cast($KeyStore$Entry, $nc(objs)->fst));
	$var($KeyStore$PasswordProtection, pp, nullptr);
	$var($chars, newPass, nullptr);
	if (this->destKeyPass != nullptr) {
		$assign(newPass, this->destKeyPass);
		$assign(pp, $new($KeyStore$PasswordProtection, this->destKeyPass));
	} else if (objs->snd != nullptr) {
		if ($nc(Main::P12KEYSTORE)->equalsIgnoreCase(this->storetype)) {
			if (this->isPasswordlessKeyStore) {
				$assign(newPass, $cast($chars, objs->snd));
			} else {
				$assign(newPass, this->storePass);
			}
		} else {
			$assign(newPass, $cast($chars, objs->snd));
		}
		$assign(pp, $new($KeyStore$PasswordProtection, newPass));
	}
	try {
		$var($Certificate, c, $nc(srckeystore)->getCertificate(alias));
		if (c != nullptr) {
			checkWeak($$str({"<"_s, newAlias, ">"_s}), c);
		}
		$nc(this->keyStore)->setEntry(newAlias, entry, pp);
		if ($nc(Main::P12KEYSTORE)->equalsIgnoreCase(this->storetype) && !this->isPasswordlessKeyStore) {
			if (newPass != nullptr && !$Arrays::equals(newPass, this->storePass)) {
				$throwNew($Exception, $($nc(Main::rb)->getString("The.destination.pkcs12.keystore.has.different.storepass.and.keypass.Please.retry.with.destkeypass.specified."_s)));
			}
		}
		return 1;
	} catch ($KeyStoreException& kse) {
		$var($ObjectArray, source2, $new($ObjectArray, {
			$of(alias),
			$($of(kse->toString()))
		}));
		$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("Problem.importing.entry.for.alias.alias.exception.Entry.for.alias.alias.not.imported."_s))));
		$nc($System::err)->println($(form->format(source2)));
		return 2;
	}
	$shouldNotReachHere();
}

void Main::doImportKeyStoreAll($KeyStore* srckeystore) {
	$useLocalCurrentObjectStackCache();
	int32_t ok = 0;
	int32_t count = $nc(srckeystore)->size();
	{
		$var($Enumeration, e, srckeystore->aliases());
		for (; $nc(e)->hasMoreElements();) {
			$var($String, alias, $cast($String, e->nextElement()));
			int32_t result = doImportKeyStoreSingle(srckeystore, alias);
			if (result == 1) {
				++ok;
				$var($ObjectArray, source, $new($ObjectArray, {$of(alias)}));
				$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("Entry.for.alias.alias.successfully.imported."_s))));
				$nc($System::err)->println($(form->format(source)));
			} else if (result == 2) {
				if (!this->noprompt) {
					$var($String, reply, getYesNoReply("Do you want to quit the import process? [no]:  "_s));
					if ("YES"_s->equals(reply)) {
						break;
					}
				}
			}
		}
	}
	$var($ObjectArray, source, $new($ObjectArray, {
		$($of($Integer::valueOf(ok))),
		$($of($Integer::valueOf(count - ok)))
	}));
	$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("Import.command.completed.ok.entries.successfully.imported.fail.entries.failed.or.cancelled"_s))));
	$nc($System::err)->println($(form->format(source)));
}

void Main::doPrintEntries($PrintStream* out) {
	$useLocalCurrentObjectStackCache();
	$var($String, var$0, $($nc(Main::rb)->getString("Keystore.type."_s)));
	$nc(out)->println($$concat(var$0, $($nc(this->keyStore)->getType())));
	$var($String, var$1, $($nc(Main::rb)->getString("Keystore.provider."_s)));
	out->println($$concat(var$1, $($nc($($nc(this->keyStore)->getProvider()))->getName())));
	out->println();
	$var($MessageFormat, form, nullptr);
	$assign(form, ($nc(this->keyStore)->size() == 1) ? $new($MessageFormat, $($nc(Main::rb)->getString("Your.keystore.contains.keyStore.size.entry"_s))) : $new($MessageFormat, $($nc(Main::rb)->getString("Your.keystore.contains.keyStore.size.entries"_s))));
	$var($ObjectArray, source, $new($ObjectArray, {$($of($Integer::valueOf($nc(this->keyStore)->size())))}));
	out->println($($nc(form)->format(source)));
	out->println();
	$var($List, aliases, $Collections::list($($nc(this->keyStore)->aliases())));
	$nc(aliases)->sort(static_cast<$Comparator*>($$new(Main$$Lambda$compareTo$1)));
	{
		$var($Iterator, i$, aliases->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, alias, $cast($String, i$->next()));
			{
				doPrintEntry($$str({"<"_s, alias, ">"_s}), alias, out);
				if (this->verbose || this->rfc) {
					out->println($($nc(Main::rb)->getString("NEWLINE"_s)));
					out->println($($nc(Main::rb)->getString("STAR"_s)));
					out->println($($nc(Main::rb)->getString("STARNN"_s)));
				}
			}
		}
	}
}

$Collection* Main::loadCRLs($String* src) {
	$init(Main);
	$useLocalCurrentObjectStackCache();
	$var($InputStream, in, nullptr);
	$var($URI, uri, nullptr);
	if (src == nullptr) {
		$assign(in, $System::in);
	} else {
		try {
			$assign(uri, $new($URI, src));
			if ($nc($(uri->getScheme()))->equals("ldap"_s)) {
			} else {
				$assign(in, $nc($(uri->toURL()))->openStream());
			}
		} catch ($Exception& e) {
			try {
				$assign(in, $new($FileInputStream, src));
			} catch ($Exception& e2) {
				if (uri == nullptr || $nc(uri)->getScheme() == nullptr) {
					$throw(e2);
				} else {
					$throw(e);
				}
			}
		}
	}
	if (in != nullptr) {
		{
			$var($Throwable, var$0, nullptr);
			$var($Collection, var$2, nullptr);
			bool return$1 = false;
			try {
				$var($bytes, bytes, in->readAllBytes());
				$assign(var$2, $nc($($CertificateFactory::getInstance("X509"_s)))->generateCRLs($$new($ByteArrayInputStream, bytes)));
				return$1 = true;
				goto $finally;
			} catch ($Throwable& var$3) {
				$assign(var$0, var$3);
			} $finally: {
				if (in != $System::in) {
					in->close();
				}
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
			if (return$1) {
				return var$2;
			}
		}
	} else {
		$var($URICertStoreParameters, params, $new($URICertStoreParameters, uri));
		$var($CertStore, s, $CertStore::getInstance("LDAP"_s, params));
		return $nc(s)->getCRLs($$new($X509CRLSelector));
	}
}

$List* Main::readCRLsFromCert($X509Certificate* cert) {
	$init(Main);
	$useLocalCurrentObjectStackCache();
	$var($List, crls, $new($ArrayList));
	$var($CRLDistributionPointsExtension, ext, $nc($($X509CertImpl::toImpl(cert)))->getCRLDistributionPointsExtension());
	if (ext == nullptr) {
		return crls;
	}
	$init($CRLDistributionPointsExtension);
	$var($List, distPoints, $cast($List, $nc(ext)->get($CRLDistributionPointsExtension::POINTS)));
	{
		$var($Iterator, i$, $nc(distPoints)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($DistributionPoint, o, $cast($DistributionPoint, i$->next()));
			{
				$var($GeneralNames, names, $nc(o)->getFullName());
				if (names != nullptr) {
					{
						$var($Iterator, i$, $nc($(names->names()))->iterator());
						for (; $nc(i$)->hasNext();) {
							$var($GeneralName, name, $cast($GeneralName, i$->next()));
							{
								if ($nc(name)->getType() == $GeneralNameInterface::NAME_URI) {
									$var($URIName, uriName, $cast($URIName, name->getName()));
									{
										$var($Iterator, i$, $nc($(loadCRLs($($nc(uriName)->getName()))))->iterator());
										for (; $nc(i$)->hasNext();) {
											$var($CRL, crl, $cast($CRL, i$->next()));
											{
												if ($instanceOf($X509CRL, crl)) {
													crls->add($cast($X509CRL, crl));
												}
											}
										}
									}
									break;
								}
							}
						}
					}
				}
			}
		}
	}
	return crls;
}

$String* Main::verifyCRL($KeyStore* ks, $CRL* crl) {
	$init(Main);
	$useLocalCurrentObjectStackCache();
	$var($X509CRL, xcrl, $cast($X509CRL, crl));
	$var($X500Principal, issuer, $nc(xcrl)->getIssuerX500Principal());
	{
		$var($Iterator, i$, $nc($($Collections::list($($nc(ks)->aliases()))))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, s, $cast($String, i$->next()));
			{
				$var($Certificate, cert, $nc(ks)->getCertificate(s));
				if ($instanceOf($X509Certificate, cert)) {
					$var($X509Certificate, xcert, $cast($X509Certificate, cert));
					if ($nc($($nc(xcert)->getSubjectX500Principal()))->equals(issuer)) {
						try {
							$nc(($cast($X509CRL, crl)))->verify($($nc(cert)->getPublicKey()));
							return s;
						} catch ($Exception& e) {
						}
					}
				}
			}
		}
	}
	return nullptr;
}

void Main::doPrintCRL($String* src, $PrintStream* out) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc($(loadCRLs(src)))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($CRL, crl, $cast($CRL, i$->next()));
			{
				printCRL(crl, out);
				$var($String, issuer, nullptr);
				$var($Certificate, signer, nullptr);
				if (this->caks != nullptr) {
					$assign(issuer, verifyCRL(this->caks, crl));
					if (issuer != nullptr) {
						$assign(signer, $nc(this->caks)->getCertificate(issuer));
						$var($String, var$0, $nc(Main::rb)->getString("verified.by.s.in.s.weak"_s));
						$nc(out)->printf(var$0, $$new($ObjectArray, {
							$of(issuer),
							$of("cacerts"_s),
							$($of(withWeak($(static_cast<$Key*>($nc(signer)->getPublicKey())))))
						}));
						out->println();
					}
				}
				if (issuer == nullptr && this->keyStore != nullptr) {
					$assign(issuer, verifyCRL(this->keyStore, crl));
					if (issuer != nullptr) {
						$assign(signer, $nc(this->keyStore)->getCertificate(issuer));
						$var($String, var$1, $nc(Main::rb)->getString("verified.by.s.in.s.weak"_s));
						$nc(out)->printf(var$1, $$new($ObjectArray, {
							$of(issuer),
							$of("keystore"_s),
							$($of(withWeak($(static_cast<$Key*>($nc(signer)->getPublicKey())))))
						}));
						out->println();
					}
				}
				if (issuer == nullptr) {
					$nc(out)->println($($nc(Main::rb)->getString("STAR"_s)));
					if (this->trustcacerts) {
						out->println($($nc(Main::rb)->getString("warning.not.verified.make.sure.keystore.is.correct"_s)));
					} else {
						out->println($($nc(Main::rb)->getString("warning.not.verified.make.sure.keystore.is.correct.or.specify.trustcacerts"_s)));
					}
					out->println($($nc(Main::rb)->getString("STARNN"_s)));
				}
				$var($String, var$2, $nc(Main::rb)->getString("the.crl"_s));
				$var($CRL, var$3, crl);
				checkWeak(var$2, var$3, signer == nullptr ? ($Key*)nullptr : $(static_cast<$Key*>($nc(signer)->getPublicKey())));
			}
		}
	}
}

void Main::printCRL($CRL* crl, $PrintStream* out) {
	$useLocalCurrentObjectStackCache();
	$var($X509CRL, xcrl, $cast($X509CRL, crl));
	if (this->rfc) {
		$nc(out)->println("-----BEGIN X509 CRL-----"_s);
		out->println($($nc($($Base64::getMimeEncoder(64, Main::CRLF)))->encodeToString($($nc(xcrl)->getEncoded()))));
		out->println("-----END X509 CRL-----"_s);
	} else {
		$var($String, s, nullptr);
		if ($instanceOf($X509CRLImpl, crl)) {
			$var($X509CRLImpl, x509crl, $cast($X509CRLImpl, crl));
			$assign(s, $nc(x509crl)->toStringWithAlgName($(withWeak($$str({""_s, $(x509crl->getSigAlgId())})))));
		} else {
			$assign(s, $nc(crl)->toString());
		}
		$nc(out)->println(s);
	}
}

void Main::doPrintCertReq($InputStream* in, $PrintStream* out) {
	$useLocalCurrentObjectStackCache();
	$var($BufferedReader, reader, $new($BufferedReader, $$new($InputStreamReader, in)));
	$var($StringBuilder, sb, $new($StringBuilder));
	bool started = false;
	while (true) {
		$var($String, s, reader->readLine());
		if (s == nullptr) {
			break;
		}
		if (!started) {
			if ($nc(s)->startsWith("-----"_s)) {
				started = true;
			}
		} else {
			if ($nc(s)->startsWith("-----"_s)) {
				break;
			}
			sb->append(s);
		}
	}
	$var($PKCS10, req, $new($PKCS10, $($Pem::decode($$new($String, sb)))));
	$var($PublicKey, pkey, req->getSubjectPublicKeyInfo());
	$var($String, var$0, $nc(Main::rb)->getString("PKCS.10.with.weak"_s));
	$nc(out)->printf(var$0, $$new($ObjectArray, {
		$($of(req->getSubjectName())),
		$($of($nc(pkey)->getFormat())),
		$($of(withWeak(static_cast<$Key*>(pkey)))),
		$($of(withWeak($(req->getSigAlg()))))
	}));
	{
		$var($Iterator, i$, $nc($($nc($(req->getAttributes()))->getAttributes()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($PKCS10Attribute, attr, $cast($PKCS10Attribute, i$->next()));
			{
				$var($ObjectIdentifier, oid, $nc(attr)->getAttributeId());
				$init($PKCS9Attribute);
				if ($nc(oid)->equals($PKCS9Attribute::EXTENSION_REQUEST_OID)) {
					$var($CertificateExtensions, exts, $cast($CertificateExtensions, attr->getAttributeValue()));
					if (exts != nullptr) {
						printExtensions($($nc(Main::rb)->getString("Extension.Request."_s)), exts, out);
					}
				} else {
					out->println($$str({"Attribute: "_s, $(attr->getAttributeId())}));
					$var($ObjectIdentifier, var$1, attr->getAttributeId());
					$var($PKCS9Attribute, pkcs9Attr, $new($PKCS9Attribute, var$1, $(attr->getAttributeValue())));
					out->print($$str({$(pkcs9Attr->getName()), ": "_s}));
					$var($Object, attrVal, attr->getAttributeValue());
					out->println($instanceOf($StringArray, attrVal) ? $($of($Arrays::toString($cast($StringArray, attrVal)))) : attrVal);
				}
			}
		}
	}
	if (this->debug) {
		out->println($of(req));
	}
	checkWeak($($nc(Main::rb)->getString("the.certificate.request"_s)), req);
}

void Main::printCertFromStream($InputStream* in, $PrintStream* out) {
	$useLocalCurrentObjectStackCache();
	$var($Collection, c, nullptr);
	try {
		$assign(c, generateCertificates(in));
	} catch ($CertificateException& ce) {
		$throwNew($Exception, $($nc(Main::rb)->getString("Failed.to.parse.input"_s)), ce);
	}
	if ($nc(c)->isEmpty()) {
		$throwNew($Exception, $($nc(Main::rb)->getString("Empty.input"_s)));
	}
	$var($CertificateArray, certs, $fcast($CertificateArray, $nc(c)->toArray($$new($CertificateArray, c->size()))));
	for (int32_t i = 0; i < $nc(certs)->length; ++i) {
		$var($X509Certificate, x509Cert, nullptr);
		try {
			$assign(x509Cert, $cast($X509Certificate, certs->get(i)));
		} catch ($ClassCastException& cce) {
			$throwNew($Exception, $($nc(Main::rb)->getString("Not.X.509.certificate"_s)));
		}
		if (certs->length > 1) {
			$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("Certificate.i.1."_s))));
			$var($ObjectArray, source, $new($ObjectArray, {$($of($Integer::valueOf(i + 1)))}));
			$nc(out)->println($(form->format(source)));
		}
		if (this->rfc) {
			dumpCert(x509Cert, out);
		} else {
			printX509Cert(x509Cert, out);
		}
		if (i < (certs->length - 1)) {
			$nc(out)->println();
		}
		checkWeak($(oneInMany($($nc(Main::rb)->getString("the.certificate"_s)), i, certs->length)), static_cast<$Certificate*>(x509Cert));
	}
}

void Main::doShowInfo() {
	if (this->tlsInfo) {
		$ShowInfo::tls(this->verbose);
	} else {
		$nc($System::out)->println($($nc(Main::rb)->getString("showinfo.no.option"_s)));
	}
}

$Collection* Main::generateCertificates($InputStream* in) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, data, $nc(in)->readAllBytes());
	try {
		return $nc($($CertificateFactory::getInstance("X.509"_s)))->generateCertificates($$new($ByteArrayInputStream, data));
	} catch ($CertificateException& e) {
		if (this->providerName != nullptr) {
			try {
				return $nc($($CertificateFactory::getInstance("X.509"_s, this->providerName)))->generateCertificates($$new($ByteArrayInputStream, data));
			} catch ($Exception& e2) {
				e->addSuppressed(e2);
			}
		}
		$throw(e);
	}
	$shouldNotReachHere();
}

$Certificate* Main::generateCertificate($InputStream* in) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, data, $nc(in)->readAllBytes());
	try {
		return $nc($($CertificateFactory::getInstance("X.509"_s)))->generateCertificate($$new($ByteArrayInputStream, data));
	} catch ($CertificateException& e) {
		if (this->providerName != nullptr) {
			try {
				return $nc($($CertificateFactory::getInstance("X.509"_s, this->providerName)))->generateCertificate($$new($ByteArrayInputStream, data));
			} catch ($Exception& e2) {
				e->addSuppressed(e2);
			}
		}
		$throw(e);
	}
	$shouldNotReachHere();
}

$String* Main::oneInMany($String* label, int32_t i, int32_t num) {
	$init(Main);
	$useLocalCurrentObjectStackCache();
	if (num == 1) {
		return label;
	} else {
		$var($String, var$0, $nc(Main::rb)->getString("one.in.many"_s));
		return $String::format(var$0, $$new($ObjectArray, {
			$of(label),
			$($of($Integer::valueOf(i + 1))),
			$($of($Integer::valueOf(num)))
		}));
	}
}

void Main::doPrintCert($PrintStream* out) {
	$useLocalCurrentObjectStackCache();
	if (this->jarfile != nullptr) {
		$init($DisabledAlgorithmConstraints);
		$Security::setProperty($DisabledAlgorithmConstraints::PROPERTY_JAR_DISABLED_ALGS, ""_s);
		$var($JarFile, jf, $new($JarFile, this->jarfile, true));
		$var($Enumeration, entries, jf->entries());
		$var($Set, ss, $new($HashSet));
		$var($bytes, buffer, $new($bytes, 8192));
		int32_t pos = 0;
		while ($nc(entries)->hasMoreElements()) {
			$var($JarEntry, je, $cast($JarEntry, entries->nextElement()));
			{
				$var($InputStream, is, jf->getInputStream(je));
				{
					$var($Throwable, var$0, nullptr);
					try {
						try {
							while ($nc(is)->read(buffer) != -1) {
							}
						} catch ($Throwable& t$) {
							if (is != nullptr) {
								try {
									is->close();
								} catch ($Throwable& x2) {
									t$->addSuppressed(x2);
								}
							}
							$throw(t$);
						}
					} catch ($Throwable& var$1) {
						$assign(var$0, var$1);
					} /*finally*/ {
						if (is != nullptr) {
							is->close();
						}
					}
					if (var$0 != nullptr) {
						$throw(var$0);
					}
				}
			}
			$var($CodeSignerArray, signers, $nc(je)->getCodeSigners());
			if (signers != nullptr) {
				{
					$var($CodeSignerArray, arr$, signers);
					int32_t len$ = arr$->length;
					int32_t i$ = 0;
					for (; i$ < len$; ++i$) {
						$var($CodeSigner, signer, arr$->get(i$));
						{
							if (!ss->contains(signer)) {
								ss->add(signer);
								$var($String, var$2, $nc(Main::rb)->getString("Signer.d."_s));
								$nc(out)->printf(var$2, $$new($ObjectArray, {$($of($Integer::valueOf(++pos)))}));
								out->println();
								out->println();
								out->println($($nc(Main::rb)->getString("Signature."_s)));
								out->println();
								$var($List, certs, $nc($($nc(signer)->getSignerCertPath()))->getCertificates());
								int32_t cc = 0;
								{
									$var($Iterator, i$, $nc(certs)->iterator());
									for (; $nc(i$)->hasNext();) {
										$var($Certificate, cert, $cast($Certificate, i$->next()));
										{
											$var($X509Certificate, x, $cast($X509Certificate, cert));
											if (this->rfc) {
												$var($String, var$4, $($nc(Main::rb)->getString("Certificate.owner."_s)));
												$var($String, var$3, $$concat(var$4, $($nc(x)->getSubjectX500Principal())));
												out->println($$concat(var$3, "\n"_s));
												dumpCert(x, out);
											} else {
												printX509Cert(x, out);
											}
											out->println();
											$var($String, var$5, $nc(Main::rb)->getString("the.certificate"_s));
											int32_t var$6 = cc++;
											checkWeak($(oneInMany(var$5, var$6, certs->size())), static_cast<$Certificate*>(x));
										}
									}
								}
								$var($Timestamp, ts, signer->getTimestamp());
								if (ts != nullptr) {
									out->println($($nc(Main::rb)->getString("Timestamp."_s)));
									out->println();
									$assign(certs, $nc($(ts->getSignerCertPath()))->getCertificates());
									cc = 0;
									{
										$var($Iterator, i$, $nc(certs)->iterator());
										for (; $nc(i$)->hasNext();) {
											$var($Certificate, cert, $cast($Certificate, i$->next()));
											{
												$var($X509Certificate, x, $cast($X509Certificate, cert));
												if (this->rfc) {
													$var($String, var$8, $($nc(Main::rb)->getString("Certificate.owner."_s)));
													$var($String, var$7, $$concat(var$8, $($nc(x)->getSubjectX500Principal())));
													out->println($$concat(var$7, "\n"_s));
													dumpCert(x, out);
												} else {
													printX509Cert(x, out);
												}
												out->println();
												$var($String, var$9, $nc(Main::rb)->getString("the.tsa.certificate"_s));
												int32_t var$10 = cc++;
												checkWeak($(oneInMany(var$9, var$10, certs->size())), static_cast<$Certificate*>(x));
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		jf->close();
		if (ss->isEmpty()) {
			$nc(out)->println($($nc(Main::rb)->getString("Not.a.signed.jar.file"_s)));
		}
	} else if (this->sslserver != nullptr) {
		$var($CertStore, cs, $SSLServerCertStore::getInstance($$new($URI, $$str({"https://"_s, this->sslserver}))));
		$var($Collection, chain, nullptr);
		try {
			$assign(chain, $nc(cs)->getCertificates(nullptr));
			if ($nc(chain)->isEmpty()) {
				$throwNew($Exception, $($nc(Main::rb)->getString("No.certificate.from.the.SSL.server"_s)));
			}
		} catch ($CertStoreException& cse) {
			if ($instanceOf($IOException, $(cse->getCause()))) {
				$var($String, var$11, $nc(Main::rb)->getString("No.certificate.from.the.SSL.server"_s));
				$throwNew($Exception, var$11, $(cse->getCause()));
			} else {
				$throw(cse);
			}
		}
		int32_t i = 0;
		{
			$var($Iterator, i$, $nc(chain)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Certificate, cert, $cast($Certificate, i$->next()));
				{
					try {
						if (this->rfc) {
							dumpCert(cert, out);
						} else {
							$nc(out)->println($$str({"Certificate #"_s, $$str(i)}));
							out->println("===================================="_s);
							printX509Cert($cast($X509Certificate, cert), out);
							out->println();
						}
						$var($String, var$12, $nc(Main::rb)->getString("the.certificate"_s));
						int32_t var$13 = i++;
						checkWeak($(oneInMany(var$12, var$13, chain->size())), cert);
					} catch ($Exception& e) {
						if (this->debug) {
							e->printStackTrace();
						}
					}
				}
			}
		}
	} else if (this->filename != nullptr) {
		{
			$var($FileInputStream, inStream, $new($FileInputStream, this->filename));
			{
				$var($Throwable, var$14, nullptr);
				try {
					try {
						printCertFromStream(inStream, out);
					} catch ($Throwable& t$) {
						try {
							inStream->close();
						} catch ($Throwable& x2) {
							t$->addSuppressed(x2);
						}
						$throw(t$);
					}
				} catch ($Throwable& var$15) {
					$assign(var$14, var$15);
				} /*finally*/ {
					inStream->close();
				}
				if (var$14 != nullptr) {
					$throw(var$14);
				}
			}
		}
	} else {
		printCertFromStream($System::in, out);
	}
}

void Main::doChangeStorePasswd() {
	$useLocalCurrentObjectStackCache();
	$set(this, storePassNew, this->newPass);
	if (this->storePassNew == nullptr) {
		$set(this, storePassNew, getNewPasswd("keystore password"_s, this->storePass));
	}
	if ($nc(Main::P12KEYSTORE)->equalsIgnoreCase(this->storetype)) {
		{
			$var($Iterator, i$, $nc($($Collections::list($($nc(this->keyStore)->aliases()))))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($String, alias, $cast($String, i$->next()));
				{
					if (!$nc(this->keyStore)->isCertificateEntry(alias)) {
						$var($Pair, objs, recoverEntry(this->keyStore, alias, this->storePass, this->keyPass));
						$nc(this->keyStore)->setEntry(alias, $cast($KeyStore$Entry, $nc(objs)->fst), $$new($KeyStore$PasswordProtection, this->storePassNew));
					}
				}
			}
		}
	}
}

void Main::doSelfCert($String* alias$renamed, $String* dname, $String* sigAlgName$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($String, alias, alias$renamed);
	$var($String, sigAlgName, sigAlgName$renamed);
	if (alias == nullptr) {
		$assign(alias, Main::keyAlias);
	}
	$var($Pair, objs, recoverKey(alias, this->storePass, this->keyPass));
	$var($PrivateKey, privKey, $cast($PrivateKey, $nc(objs)->fst));
	if (this->keyPass == nullptr) {
		$set(this, keyPass, $cast($chars, objs->snd));
	}
	if (sigAlgName == nullptr) {
		$assign(sigAlgName, getCompatibleSigAlgName(privKey));
	}
	$var($Certificate, oldCert, $nc(this->keyStore)->getCertificate(alias));
	if (oldCert == nullptr) {
		$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("alias.has.no.public.key"_s))));
		$var($ObjectArray, source, $new($ObjectArray, {$of(alias)}));
		$throwNew($Exception, $(form->format(source)));
	}
	if (!($instanceOf($X509Certificate, oldCert))) {
		$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("alias.has.no.X.509.certificate"_s))));
		$var($ObjectArray, source, $new($ObjectArray, {$of(alias)}));
		$throwNew($Exception, $(form->format(source)));
	}
	$var($bytes, encoded, $nc(oldCert)->getEncoded());
	$var($X509CertImpl, certImpl, $new($X509CertImpl, encoded));
	$init($X509CertImpl);
	$var($X509CertInfo, certInfo, $cast($X509CertInfo, certImpl->get($$str({$X509CertImpl::NAME, "."_s, $X509CertImpl::INFO}))));
	$var($Date, firstDate, getStartDate(this->startDate));
	$var($Date, lastDate, $new($Date));
	lastDate->setTime($nc(firstDate)->getTime() + this->validity * (int64_t)1000 * (int64_t)24 * (int64_t)60 * (int64_t)60);
	$var($CertificateValidity, interval, $new($CertificateValidity, firstDate, lastDate));
	$init($X509CertInfo);
	$nc(certInfo)->set($X509CertInfo::VALIDITY, interval);
	certInfo->set($X509CertInfo::SERIAL_NUMBER, $($CertificateSerialNumber::newRandom64bit($$new($SecureRandom))));
	$var($X500Name, owner, nullptr);
	if (dname == nullptr) {
		$assign(owner, $cast($X500Name, certInfo->get($$str({$X509CertInfo::SUBJECT, "."_s, $X509CertInfo::DN_NAME}))));
	} else {
		$assign(owner, $new($X500Name, dname));
		certInfo->set($$str({$X509CertInfo::SUBJECT, "."_s, $X509CertInfo::DN_NAME}), owner);
	}
	certInfo->set($$str({$X509CertInfo::ISSUER, "."_s, $X509CertInfo::DN_NAME}), owner);
	certInfo->set($X509CertInfo::VERSION, $$new($CertificateVersion, $CertificateVersion::V3));
	$var($CertificateExtensions, var$0, $cast($CertificateExtensions, certInfo->get($X509CertInfo::EXTENSIONS)));
	$var($List, var$1, this->v3ext);
	$var($CertificateExtensions, ext, createV3Extensions(nullptr, var$0, var$1, $(oldCert->getPublicKey()), nullptr));
	certInfo->set($X509CertInfo::EXTENSIONS, ext);
	$var($X509CertImpl, newCert, $new($X509CertImpl, certInfo));
	newCert->sign(privKey, sigAlgName);
	$nc(this->keyStore)->setKeyEntry(alias, privKey, (this->keyPass != nullptr) ? this->keyPass : this->storePass, $$new($CertificateArray, {static_cast<$Certificate*>(newCert)}));
	if (this->verbose) {
		$nc($System::err)->println($($nc(Main::rb)->getString("New.certificate.self.signed."_s)));
		$nc($System::err)->print($(newCert->toString()));
		$nc($System::err)->println();
	}
}

bool Main::installReply($String* alias$renamed, $InputStream* in) {
	$useLocalCurrentObjectStackCache();
	$var($String, alias, alias$renamed);
	if (alias == nullptr) {
		$assign(alias, Main::keyAlias);
	}
	$var($Pair, objs, recoverKey(alias, this->storePass, this->keyPass));
	$var($PrivateKey, privKey, $cast($PrivateKey, $nc(objs)->fst));
	if (this->keyPass == nullptr) {
		$set(this, keyPass, $cast($chars, objs->snd));
	}
	$var($Certificate, userCert, $nc(this->keyStore)->getCertificate(alias));
	if (userCert == nullptr) {
		$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("alias.has.no.public.key.certificate."_s))));
		$var($ObjectArray, source, $new($ObjectArray, {$of(alias)}));
		$throwNew($Exception, $(form->format(source)));
	}
	$var($Collection, c, generateCertificates(in));
	if ($nc(c)->isEmpty()) {
		$throwNew($Exception, $($nc(Main::rb)->getString("Reply.has.no.certificates"_s)));
	}
	$var($CertificateArray, replyCerts, $fcast($CertificateArray, $nc(c)->toArray($$new($CertificateArray, c->size()))));
	$var($CertificateArray, newChain, nullptr);
	if ($nc(replyCerts)->length == 1) {
		$assign(newChain, establishCertChain(userCert, replyCerts->get(0)));
	} else {
		$assign(newChain, validateReply(alias, userCert, replyCerts));
	}
	if (newChain != nullptr) {
		$nc(this->keyStore)->setKeyEntry(alias, privKey, (this->keyPass != nullptr) ? this->keyPass : this->storePass, newChain);
		return true;
	} else {
		return false;
	}
}

bool Main::addTrustedCert($String* alias, $InputStream* in) {
	$useLocalCurrentObjectStackCache();
	if (alias == nullptr) {
		$throwNew($Exception, $($nc(Main::rb)->getString("Must.specify.alias"_s)));
	}
	if ($nc(this->keyStore)->containsAlias(alias)) {
		$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("Certificate.not.imported.alias.alias.already.exists"_s))));
		$var($ObjectArray, source, $new($ObjectArray, {$of(alias)}));
		$throwNew($Exception, $(form->format(source)));
	}
	$var($X509Certificate, cert, nullptr);
	try {
		$assign(cert, $cast($X509Certificate, generateCertificate(in)));
	} catch ($ClassCastException& ce) {
		$throwNew($Exception, $($nc(Main::rb)->getString("Input.not.an.X.509.certificate"_s)));
	} catch ($CertificateException& ce) {
		$throwNew($Exception, $($nc(Main::rb)->getString("Input.not.an.X.509.certificate"_s)));
	}
	if (this->noprompt) {
		checkWeak($($nc(Main::rb)->getString("the.input"_s)), static_cast<$Certificate*>(cert));
		$nc(this->keyStore)->setCertificateEntry(alias, cert);
		return true;
	}
	bool selfSigned = false;
	if ($KeyStoreUtil::isSelfSigned(cert)) {
		$nc(cert)->verify($(cert->getPublicKey()));
		selfSigned = true;
	}
	$var($String, reply, nullptr);
	$var($String, trustalias, $nc(this->keyStore)->getCertificateAlias(cert));
	if (trustalias != nullptr) {
		$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("Certificate.already.exists.in.keystore.under.alias.trustalias."_s))));
		$var($ObjectArray, source, $new($ObjectArray, {$of(trustalias)}));
		$nc($System::err)->println($(form->format(source)));
		checkWeak($($nc(Main::rb)->getString("the.input"_s)), static_cast<$Certificate*>(cert));
		printWeakWarnings(true);
		$assign(reply, getYesNoReply($($nc(Main::rb)->getString("Do.you.still.want.to.add.it.no."_s))));
	} else if (selfSigned) {
		if (this->trustcacerts && (this->caks != nullptr) && (($assign(trustalias, $nc(this->caks)->getCertificateAlias(cert))) != nullptr)) {
			$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("Certificate.already.exists.in.system.wide.CA.keystore.under.alias.trustalias."_s))));
			$var($ObjectArray, source, $new($ObjectArray, {$of(trustalias)}));
			$nc($System::err)->println($(form->format(source)));
			checkWeak($($nc(Main::rb)->getString("the.input"_s)), static_cast<$Certificate*>(cert));
			printWeakWarnings(true);
			$assign(reply, getYesNoReply($($nc(Main::rb)->getString("Do.you.still.want.to.add.it.to.your.own.keystore.no."_s))));
		}
		if (trustalias == nullptr) {
			printX509Cert(cert, $System::out);
			checkWeak($($nc(Main::rb)->getString("the.input"_s)), static_cast<$Certificate*>(cert));
			printWeakWarnings(true);
			$assign(reply, getYesNoReply($($nc(Main::rb)->getString("Trust.this.certificate.no."_s))));
		}
	}
	if (reply != nullptr) {
		if ("YES"_s->equals(reply)) {
			$nc(this->keyStore)->setCertificateEntry(alias, cert);
			return true;
		} else {
			return false;
		}
	}
	try {
		$var($CertificateArray, chain, establishCertChain(nullptr, cert));
		if (chain != nullptr) {
			$nc(this->keyStore)->setCertificateEntry(alias, cert);
			return true;
		}
	} catch ($Exception& e) {
		printX509Cert(cert, $System::out);
		checkWeak($($nc(Main::rb)->getString("the.input"_s)), static_cast<$Certificate*>(cert));
		printWeakWarnings(true);
		$assign(reply, getYesNoReply($($nc(Main::rb)->getString("Trust.this.certificate.no."_s))));
		if ("YES"_s->equals(reply)) {
			$nc(this->keyStore)->setCertificateEntry(alias, cert);
			return true;
		} else {
			return false;
		}
	}
	return false;
}

$chars* Main::getNewPasswd($String* prompt, $chars* oldPasswd) {
	$useLocalCurrentObjectStackCache();
	$var($chars, entered, nullptr);
	$var($chars, reentered, nullptr);
	for (int32_t count = 0; count < 3; ++count) {
		$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("New.prompt."_s))));
		$var($ObjectArray, source, $new($ObjectArray, {$of(prompt)}));
		$nc($System::err)->print($(form->format(source)));
		$assign(entered, $Password::readPassword($System::in));
		$nc(this->passwords)->add(entered);
		if (entered == nullptr || $nc(entered)->length < 6) {
			$nc($System::err)->println($($nc(Main::rb)->getString("Password.is.too.short.must.be.at.least.6.characters"_s)));
		} else if ($Arrays::equals(entered, oldPasswd)) {
			$nc($System::err)->println($($nc(Main::rb)->getString("Passwords.must.differ"_s)));
		} else {
			$assign(form, $new($MessageFormat, $($nc(Main::rb)->getString("Re.enter.new.prompt."_s))));
			$var($ObjectArray, src, $new($ObjectArray, {$of(prompt)}));
			$nc($System::err)->print($(form->format(src)));
			$assign(reentered, $Password::readPassword($System::in));
			$nc(this->passwords)->add(reentered);
			if (!$Arrays::equals(entered, reentered)) {
				$nc($System::err)->println($($nc(Main::rb)->getString("They.don.t.match.Try.again"_s)));
			} else {
				$Arrays::fill(reentered, u' ');
				return entered;
			}
		}
		if (entered != nullptr) {
			$Arrays::fill(entered, u' ');
			$assign(entered, nullptr);
		}
		if (reentered != nullptr) {
			$Arrays::fill(reentered, u' ');
			$assign(reentered, nullptr);
		}
	}
	$throwNew($Exception, $($nc(Main::rb)->getString("Too.many.failures.try.later"_s)));
}

$String* Main::getAlias($String* prompt) {
	$useLocalCurrentObjectStackCache();
	if (prompt != nullptr) {
		$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("Enter.prompt.alias.name."_s))));
		$var($ObjectArray, source, $new($ObjectArray, {$of(prompt)}));
		$nc($System::err)->print($(form->format(source)));
	} else {
		$nc($System::err)->print($($nc(Main::rb)->getString("Enter.alias.name."_s)));
	}
	return ($$new($BufferedReader, $$new($InputStreamReader, $System::in)))->readLine();
}

$String* Main::inputStringFromStdin($String* prompt) {
	$useLocalCurrentObjectStackCache();
	$nc($System::err)->print(prompt);
	return ($$new($BufferedReader, $$new($InputStreamReader, $System::in)))->readLine();
}

$chars* Main::getKeyPasswd($String* alias, $String* otherAlias, $chars* otherKeyPass) {
	$useLocalCurrentObjectStackCache();
	int32_t count = 0;
	$var($chars, keyPass, nullptr);
	do {
		if (otherKeyPass != nullptr) {
			$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("Enter.key.password.for.alias."_s))));
			$var($ObjectArray, source, $new($ObjectArray, {$of(alias)}));
			$nc($System::err)->println($(form->format(source)));
			$assign(form, $new($MessageFormat, $($nc(Main::rb)->getString(".RETURN.if.same.as.for.otherAlias."_s))));
			$var($ObjectArray, src, $new($ObjectArray, {$of(otherAlias)}));
			$nc($System::err)->print($(form->format(src)));
		} else {
			$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("Enter.key.password.for.alias."_s))));
			$var($ObjectArray, source, $new($ObjectArray, {$of(alias)}));
			$nc($System::err)->print($(form->format(source)));
		}
		$nc($System::err)->flush();
		$assign(keyPass, $Password::readPassword($System::in));
		$nc(this->passwords)->add(keyPass);
		if (keyPass == nullptr) {
			$assign(keyPass, otherKeyPass);
		}
		++count;
	} while ((keyPass == nullptr) && count < 3);
	if (keyPass == nullptr) {
		$throwNew($Exception, $($nc(Main::rb)->getString("Too.many.failures.try.later"_s)));
	}
	return keyPass;
}

$String* Main::withWeak($String* alg) {
	$useLocalCurrentObjectStackCache();
	if ($nc(Main::DISABLED_CHECK)->permits(Main::SIG_PRIMITIVE_SET, alg, ($AlgorithmParameters*)nullptr)) {
		if ($nc(Main::LEGACY_CHECK)->permits(Main::SIG_PRIMITIVE_SET, alg, ($AlgorithmParameters*)nullptr)) {
			return alg;
		} else {
			return $String::format($($nc(Main::rb)->getString("with.weak"_s)), $$new($ObjectArray, {$of(alg)}));
		}
	} else {
		return $String::format($($nc(Main::rb)->getString("with.disabled"_s)), $$new($ObjectArray, {$of(alg)}));
	}
}

$String* Main::fullDisplayAlgName($Key* key) {
	$useLocalCurrentObjectStackCache();
	$var($String, result, $nc(key)->getAlgorithm());
	if ($instanceOf($ECKey, key)) {
		$var($ECParameterSpec, paramSpec, $nc(($cast($ECKey, key)))->getParams());
		if ($instanceOf($NamedCurve, paramSpec)) {
			$var($NamedCurve, nc, $cast($NamedCurve, paramSpec));
			$plusAssign(result, $$str({" ("_s, $nc($($nc(nc)->getNameAndAliases()))->get(0), ")"_s}));
		}
	} else if ($instanceOf($EdECKey, key)) {
		$assign(result, $nc($($nc(($cast($EdECKey, key)))->getParams()))->getName());
	}
	return result;
}

$String* Main::withWeak($Key* key) {
	$useLocalCurrentObjectStackCache();
	int32_t kLen = $KeyUtil::getKeySize(key);
	$var($String, displayAlg, fullDisplayAlgName(key));
	if ($nc(Main::DISABLED_CHECK)->permits(Main::SIG_PRIMITIVE_SET, key)) {
		if ($nc(Main::LEGACY_CHECK)->permits(Main::SIG_PRIMITIVE_SET, key)) {
			if (kLen >= 0) {
				$var($String, var$0, $nc(Main::rb)->getString("key.bit"_s));
				return $String::format(var$0, $$new($ObjectArray, {
					$($of($Integer::valueOf(kLen))),
					$of(displayAlg)
				}));
			} else {
				return $String::format($($nc(Main::rb)->getString("unknown.size.1"_s)), $$new($ObjectArray, {$of(displayAlg)}));
			}
		} else {
			$var($String, var$1, $nc(Main::rb)->getString("key.bit.weak"_s));
			return $String::format(var$1, $$new($ObjectArray, {
				$($of($Integer::valueOf(kLen))),
				$of(displayAlg)
			}));
		}
	} else {
		$var($String, var$2, $nc(Main::rb)->getString("key.bit.disabled"_s));
		return $String::format(var$2, $$new($ObjectArray, {
			$($of($Integer::valueOf(kLen))),
			$of(displayAlg)
		}));
	}
}

void Main::printX509Cert($X509Certificate* cert, $PrintStream* out) {
	$useLocalCurrentObjectStackCache();
	$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString(".PATTERN.printX509Cert.with.weak"_s))));
	$var($PublicKey, pkey, $nc(cert)->getPublicKey());
	$var($String, sigName, cert->getSigAlgName());
	if (!isTrustedCert(cert)) {
		$assign(sigName, withWeak(sigName));
	}
	$var($ObjectArray, source, $new($ObjectArray, {
		$($of($nc($(cert->getSubjectX500Principal()))->toString())),
		$($of($nc($(cert->getIssuerX500Principal()))->toString())),
		$($of($nc($(cert->getSerialNumber()))->toString(16))),
		$($of($nc($(cert->getNotBefore()))->toString())),
		$($of($nc($(cert->getNotAfter()))->toString())),
		$($of(getCertFingerPrint("SHA-1"_s, cert))),
		$($of(getCertFingerPrint("SHA-256"_s, cert))),
		$of(sigName),
		$($of(withWeak(static_cast<$Key*>(pkey)))),
		$($of($Integer::valueOf(cert->getVersion())))
	}));
	$nc(out)->println($(form->format(source)));
	if ($instanceOf($X509CertImpl, cert)) {
		$var($X509CertImpl, impl, $cast($X509CertImpl, cert));
		$init($X509CertImpl);
		$var($X509CertInfo, certInfo, $cast($X509CertInfo, impl->get($$str({$X509CertImpl::NAME, "."_s, $X509CertImpl::INFO}))));
		$init($X509CertInfo);
		$var($CertificateExtensions, exts, $cast($CertificateExtensions, $nc(certInfo)->get($X509CertInfo::EXTENSIONS)));
		if (exts != nullptr) {
			printExtensions($($nc(Main::rb)->getString("Extensions."_s)), exts, out);
		}
	}
}

void Main::printExtensions($String* title, $CertificateExtensions* exts, $PrintStream* out) {
	$init(Main);
	$useLocalCurrentObjectStackCache();
	int32_t extnum = 0;
	$var($Iterator, i1, $nc($($nc(exts)->getAllExtensions()))->iterator());
	$var($Iterator, i2, $nc($($nc($(exts->getUnparseableExtensions()))->values()))->iterator());
	while (true) {
		bool var$0 = $nc(i1)->hasNext();
		if (!(var$0 || $nc(i2)->hasNext())) {
			break;
		}
		{
			$var($Extension, ext, $nc(i1)->hasNext() ? $cast($Extension, $nc(i1)->next()) : $cast($Extension, i2->next()));
			if (extnum == 0) {
				$nc(out)->println();
				out->println(title);
				out->println();
			}
			$nc(out)->print($$str({"#"_s, $$str((++extnum)), ": "_s, ext}));
			$load($Extension);
			if ($nc($of(ext))->getClass() == $Extension::class$) {
				$var($bytes, v, ext->getExtensionValue());
				if ($nc(v)->length == 0) {
					out->println($($nc(Main::rb)->getString(".Empty.value."_s)));
				} else {
					$$new($HexDumpEncoder)->encodeBuffer($(ext->getExtensionValue()), static_cast<$OutputStream*>(out));
					out->println();
				}
			}
			out->println();
		}
	}
}

$Pair* Main::getSigner($Certificate* cert, $KeyStore* ks) {
	$init(Main);
	$useLocalCurrentObjectStackCache();
	if ($nc(ks)->getCertificateAlias(cert) != nullptr) {
		return $new($Pair, ""_s, cert);
	}
	{
		$var($Enumeration, aliases, $nc(ks)->aliases());
		for (; $nc(aliases)->hasMoreElements();) {
			$var($String, name, $cast($String, aliases->nextElement()));
			$var($Certificate, trustedCert, ks->getCertificate(name));
			if (trustedCert != nullptr) {
				try {
					$nc(cert)->verify($(trustedCert->getPublicKey()));
					return $new($Pair, name, trustedCert);
				} catch ($Exception& e) {
				}
			}
		}
	}
	return nullptr;
}

$X500Name* Main::getX500Name() {
	$useLocalCurrentObjectStackCache();
	$var($BufferedReader, in, nullptr);
	$assign(in, $new($BufferedReader, $$new($InputStreamReader, $System::in)));
	$var($String, commonName, "Unknown"_s);
	$var($String, organizationalUnit, "Unknown"_s);
	$var($String, organization, "Unknown"_s);
	$var($String, city, "Unknown"_s);
	$var($String, state, "Unknown"_s);
	$var($String, country, "Unknown"_s);
	$var($X500Name, name, nullptr);
	$var($String, userInput, nullptr);
	int32_t maxRetry = 20;
	bool var$2 = false;
	do {
		if (maxRetry-- < 0) {
			$throwNew($RuntimeException, $($nc(Main::rb)->getString("Too.many.retries.program.terminated"_s)));
		}
		$assign(commonName, inputString(in, $($nc(Main::rb)->getString("What.is.your.first.and.last.name."_s)), commonName));
		$assign(organizationalUnit, inputString(in, $($nc(Main::rb)->getString("What.is.the.name.of.your.organizational.unit."_s)), organizationalUnit));
		$assign(organization, inputString(in, $($nc(Main::rb)->getString("What.is.the.name.of.your.organization."_s)), organization));
		$assign(city, inputString(in, $($nc(Main::rb)->getString("What.is.the.name.of.your.City.or.Locality."_s)), city));
		$assign(state, inputString(in, $($nc(Main::rb)->getString("What.is.the.name.of.your.State.or.Province."_s)), state));
		$assign(country, inputString(in, $($nc(Main::rb)->getString("What.is.the.two.letter.country.code.for.this.unit."_s)), country));
		$assign(name, $new($X500Name, commonName, organizationalUnit, organization, city, state, country));
		$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("Is.name.correct."_s))));
		$var($ObjectArray, source, $new($ObjectArray, {$of(name)}));
		$var($BufferedReader, var$0, in);
		$var($String, var$1, form->format(source));
		$assign(userInput, inputString(var$0, var$1, $($nc(Main::rb)->getString("no"_s))));
		var$2 = $nc(Main::collator)->compare(userInput, $($nc(Main::rb)->getString("yes"_s))) != 0;
	} while (var$2 && $nc(Main::collator)->compare(userInput, $($nc(Main::rb)->getString("y"_s))) != 0);
	$nc($System::err)->println();
	return name;
}

$String* Main::inputString($BufferedReader* in, $String* prompt, $String* defaultValue) {
	$useLocalCurrentObjectStackCache();
	$nc($System::err)->println(prompt);
	$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString(".defaultValue."_s))));
	$var($ObjectArray, source, $new($ObjectArray, {$of(defaultValue)}));
	$nc($System::err)->print($(form->format(source)));
	$nc($System::err)->flush();
	$var($String, value, $nc(in)->readLine());
	if (value == nullptr || $nc(Main::collator)->compare(value, ""_s) == 0) {
		$assign(value, defaultValue);
	}
	return value;
}

void Main::dumpCert($Certificate* cert, $PrintStream* out) {
	$useLocalCurrentObjectStackCache();
	if (this->rfc) {
		$init($X509Factory);
		$nc(out)->println($X509Factory::BEGIN_CERT);
		out->println($($nc($($Base64::getMimeEncoder(64, Main::CRLF)))->encodeToString($($nc(cert)->getEncoded()))));
		out->println($X509Factory::END_CERT);
	} else {
		$nc(out)->write($($nc(cert)->getEncoded()));
	}
}

$Pair* Main::recoverKey($String* alias, $chars* storePass, $chars* keyPass$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($chars, keyPass, keyPass$renamed);
	$var($Key, key, nullptr);
	if ($KeyStoreUtil::isWindowsKeyStore(this->storetype)) {
		$assign(key, $nc(this->keyStore)->getKey(alias, nullptr));
		return $Pair::of(key, nullptr);
	}
	if ($nc(this->keyStore)->containsAlias(alias) == false) {
		$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("Alias.alias.does.not.exist"_s))));
		$var($ObjectArray, source, $new($ObjectArray, {$of(alias)}));
		$throwNew($Exception, $(form->format(source)));
	}
	$load($KeyStore$PrivateKeyEntry);
	bool var$0 = !$nc(this->keyStore)->entryInstanceOf(alias, $KeyStore$PrivateKeyEntry::class$);
	$load($KeyStore$SecretKeyEntry);
	if (var$0 && !$nc(this->keyStore)->entryInstanceOf(alias, $KeyStore$SecretKeyEntry::class$)) {
		$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("Alias.alias.has.no.key"_s))));
		$var($ObjectArray, source, $new($ObjectArray, {$of(alias)}));
		$throwNew($Exception, $(form->format(source)));
	}
	if (keyPass == nullptr) {
		if (storePass != nullptr) {
			try {
				$assign(key, $nc(this->keyStore)->getKey(alias, storePass));
				$nc(this->passwords)->add(storePass);
				return $Pair::of(key, storePass);
			} catch ($UnrecoverableKeyException& e) {
				if (this->token) {
					$throw(e);
				}
			}
		}
		$assign(keyPass, getKeyPasswd(alias, nullptr, nullptr));
		$assign(key, $nc(this->keyStore)->getKey(alias, keyPass));
		return $Pair::of(key, keyPass);
	} else {
		$assign(key, $nc(this->keyStore)->getKey(alias, keyPass));
		return $Pair::of(key, keyPass);
	}
}

$Pair* Main::recoverEntry($KeyStore* ks, $String* alias, $chars* pstore, $chars* pkey$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($chars, pkey, pkey$renamed);
	if (!$nc(ks)->containsAlias(alias)) {
		$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("Alias.alias.does.not.exist"_s))));
		$var($ObjectArray, source, $new($ObjectArray, {$of(alias)}));
		$throwNew($Exception, $(form->format(source)));
	}
	try {
		$var($KeyStore$Entry, entry, $nc(ks)->getEntry(alias, nullptr));
		return $Pair::of(entry, nullptr);
	} catch ($UnrecoverableEntryException& une) {
		bool var$0 = $nc(Main::P11KEYSTORE)->equalsIgnoreCase($($nc(ks)->getType()));
		if (var$0 || $KeyStoreUtil::isWindowsKeyStore($($nc(ks)->getType()))) {
			$throw(une);
		}
	}
	if (pkey != nullptr) {
		$var($KeyStore$PasswordProtection, pp, $new($KeyStore$PasswordProtection, pkey));
		$var($KeyStore$Entry, entry, $nc(ks)->getEntry(alias, pp));
		return $Pair::of(entry, pkey);
	}
	if (pstore != nullptr) {
		try {
			$var($KeyStore$PasswordProtection, pp, $new($KeyStore$PasswordProtection, pstore));
			$var($KeyStore$Entry, entry, $nc(ks)->getEntry(alias, pp));
			return $Pair::of(entry, pstore);
		} catch ($UnrecoverableEntryException& une) {
			if ($nc(Main::P12KEYSTORE)->equalsIgnoreCase($($nc(ks)->getType()))) {
				$throw(une);
			}
		}
	}
	$assign(pkey, getKeyPasswd(alias, nullptr, nullptr));
	$var($KeyStore$PasswordProtection, pp, $new($KeyStore$PasswordProtection, pkey));
	$var($KeyStore$Entry, entry, $nc(ks)->getEntry(alias, pp));
	return $Pair::of(entry, pkey);
}

$String* Main::getCertFingerPrint($String* mdAlg, $Certificate* cert) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, encCertInfo, $nc(cert)->getEncoded());
	$var($MessageDigest, md, $MessageDigest::getInstance(mdAlg));
	$var($bytes, digest, $nc(md)->digest(encCertInfo));
	return $nc($($nc($($HexFormat::ofDelimiter(":"_s)))->withUpperCase()))->formatHex(digest);
}

void Main::printNoIntegrityWarning() {
	$useLocalCurrentObjectStackCache();
	$nc($System::err)->println();
	$nc($System::err)->println($($nc(Main::rb)->getString(".WARNING.WARNING.WARNING."_s)));
	$nc($System::err)->println($($nc(Main::rb)->getString(".The.integrity.of.the.information.stored.in.your.keystore."_s)));
	$nc($System::err)->println($($nc(Main::rb)->getString(".WARNING.WARNING.WARNING."_s)));
	$nc($System::err)->println();
}

$CertificateArray* Main::validateReply($String* alias, $Certificate* userCert, $CertificateArray* replyCerts$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($CertificateArray, replyCerts, replyCerts$renamed);
	checkWeak($($nc(Main::rb)->getString("reply"_s)), replyCerts);
	int32_t i = 0;
	$var($PublicKey, userPubKey, $nc(userCert)->getPublicKey());
	$var($HashSet, nodup, $new($HashSet, $(static_cast<$Collection*>($Arrays::asList(replyCerts)))));
	$assign(replyCerts, $fcast($CertificateArray, nodup->toArray($$new($CertificateArray, nodup->size()))));
	for (i = 0; i < $nc(replyCerts)->length; ++i) {
		if ($nc($of(userPubKey))->equals($($nc(replyCerts->get(i))->getPublicKey()))) {
			break;
		}
	}
	if (i == $nc(replyCerts)->length) {
		$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("Certificate.reply.does.not.contain.public.key.for.alias."_s))));
		$var($ObjectArray, source, $new($ObjectArray, {$of(alias)}));
		$throwNew($Exception, $(form->format(source)));
	}
	$var($Certificate, tmpCert, $nc(replyCerts)->get(0));
	replyCerts->set(0, replyCerts->get(i));
	replyCerts->set(i, tmpCert);
	$var($X509Certificate, thisCert, $cast($X509Certificate, replyCerts->get(0)));
	for (i = 1; i < replyCerts->length - 1; ++i) {
		int32_t j = 0;
		for (j = i; j < replyCerts->length; ++j) {
			if ($KeyStoreUtil::signedBy(thisCert, $cast($X509Certificate, replyCerts->get(j)))) {
				$assign(tmpCert, replyCerts->get(i));
				replyCerts->set(i, replyCerts->get(j));
				replyCerts->set(j, tmpCert);
				$assign(thisCert, $cast($X509Certificate, replyCerts->get(i)));
				break;
			}
		}
		if (j == replyCerts->length) {
			$throwNew($Exception, $($nc(Main::rb)->getString("Incomplete.certificate.chain.in.reply"_s)));
		}
	}
	if (this->noprompt) {
		return replyCerts;
	}
	$var($Certificate, topCert, replyCerts->get(replyCerts->length - 1));
	bool fromKeyStore = true;
	$var($Pair, root, getSigner(topCert, this->keyStore));
	if (root == nullptr && this->trustcacerts && this->caks != nullptr) {
		$assign(root, getSigner(topCert, this->caks));
		fromKeyStore = false;
	}
	if (root == nullptr) {
		$nc($System::err)->println();
		$nc($System::err)->println($($nc(Main::rb)->getString("Top.level.certificate.in.reply."_s)));
		printX509Cert($cast($X509Certificate, topCert), $System::out);
		$nc($System::err)->println();
		$nc($System::err)->print($($nc(Main::rb)->getString(".is.not.trusted."_s)));
		printWeakWarnings(true);
		$var($String, reply, getYesNoReply($($nc(Main::rb)->getString("Install.reply.anyway.no."_s))));
		if ("NO"_s->equals(reply)) {
			return nullptr;
		}
	} else if (!$equals($nc(root)->snd, topCert)) {
		$var($CertificateArray, tmpCerts, $new($CertificateArray, replyCerts->length + 1));
		$System::arraycopy(replyCerts, 0, tmpCerts, 0, replyCerts->length);
		tmpCerts->set(tmpCerts->length - 1, $cast($Certificate, root->snd));
		$assign(replyCerts, tmpCerts);
		checkWeak($($String::format(fromKeyStore ? $($nc(Main::rb)->getString("alias.in.keystore"_s)) : $($nc(Main::rb)->getString("alias.in.cacerts"_s)), $$new($ObjectArray, {root->fst}))), $cast($Certificate, root->snd));
	}
	return replyCerts;
}

$CertificateArray* Main::establishCertChain($Certificate* userCert, $Certificate* certToVerify) {
	$useLocalCurrentObjectStackCache();
	if (userCert != nullptr) {
		$var($PublicKey, origPubKey, userCert->getPublicKey());
		$var($PublicKey, replyPubKey, $nc(certToVerify)->getPublicKey());
		if (!$nc($of(origPubKey))->equals(replyPubKey)) {
			$throwNew($Exception, $($nc(Main::rb)->getString("Public.keys.in.reply.and.keystore.don.t.match"_s)));
		}
		if (certToVerify->equals(userCert)) {
			$throwNew($Exception, $($nc(Main::rb)->getString("Certificate.reply.and.certificate.in.keystore.are.identical"_s)));
		}
	}
	$var($Hashtable, certs, nullptr);
	if ($nc(this->keyStore)->size() > 0) {
		$assign(certs, $new($Hashtable, 11));
		keystorecerts2Hashtable(this->keyStore, certs);
	}
	if (this->trustcacerts) {
		if (this->caks != nullptr && $nc(this->caks)->size() > 0) {
			if (certs == nullptr) {
				$assign(certs, $new($Hashtable, 11));
			}
			keystorecerts2Hashtable(this->caks, certs);
		}
	}
	$var($Vector, chain, $new($Vector, 2));
	if (buildChain($$new($Pair, $($nc(Main::rb)->getString("the.input"_s)), $cast($X509Certificate, certToVerify)), chain, certs)) {
		{
			$var($Iterator, i$, chain->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Pair, p, $cast($Pair, i$->next()));
				{
					checkWeak($cast($String, $nc(p)->fst), $cast($Certificate, p->snd));
				}
			}
		}
		$var($CertificateArray, newChain, $new($CertificateArray, chain->size()));
		int32_t j = 0;
		for (int32_t i = chain->size() - 1; i >= 0; --i) {
			newChain->set(j, $cast($Certificate, $nc(($cast($Pair, $(chain->elementAt(i)))))->snd));
			++j;
		}
		return newChain;
	} else {
		$throwNew($Exception, $($nc(Main::rb)->getString("Failed.to.establish.chain.from.reply"_s)));
	}
}

bool Main::buildChain($Pair* certToVerify, $Vector* chain, $Hashtable* certs) {
	$useLocalCurrentObjectStackCache();
	if ($KeyStoreUtil::isSelfSigned($cast($X509Certificate, $nc(certToVerify)->snd))) {
		$nc(chain)->addElement(certToVerify);
		return true;
	}
	$var($Principal, issuer, $nc(($cast($X509Certificate, $nc(certToVerify)->snd)))->getIssuerX500Principal());
	$var($Vector, vec, $cast($Vector, $nc(certs)->get(issuer)));
	if (vec == nullptr) {
		return false;
	}
	{
		$var($Enumeration, issuerCerts, $nc(vec)->elements());
		for (; $nc(issuerCerts)->hasMoreElements();) {
			$var($Pair, issuerCert, $cast($Pair, issuerCerts->nextElement()));
			$var($PublicKey, issuerPubKey, $nc(($cast($X509Certificate, $nc(issuerCert)->snd)))->getPublicKey());
			try {
				$nc(($cast($X509Certificate, certToVerify->snd)))->verify(issuerPubKey);
			} catch ($Exception& e) {
				continue;
			}
			if (buildChain(issuerCert, chain, certs)) {
				$nc(chain)->addElement(certToVerify);
				return true;
			}
		}
	}
	return false;
}

$String* Main::getYesNoReply($String* prompt) {
	$useLocalCurrentObjectStackCache();
	$var($String, reply, nullptr);
	int32_t maxRetry = 20;
	do {
		if (maxRetry-- < 0) {
			$throwNew($RuntimeException, $($nc(Main::rb)->getString("Too.many.retries.program.terminated"_s)));
		}
		$nc($System::err)->print(prompt);
		$nc($System::err)->flush();
		$assign(reply, ($$new($BufferedReader, $$new($InputStreamReader, $System::in)))->readLine());
		bool var$1 = reply == nullptr || $nc(Main::collator)->compare(reply, ""_s) == 0;
		bool var$0 = var$1 || $nc(Main::collator)->compare(reply, $($nc(Main::rb)->getString("n"_s))) == 0;
		if (var$0 || $nc(Main::collator)->compare(reply, $($nc(Main::rb)->getString("no"_s))) == 0) {
			$assign(reply, "NO"_s);
		} else {
			bool var$3 = $nc(Main::collator)->compare(reply, $($nc(Main::rb)->getString("y"_s))) == 0;
			if (var$3 || $nc(Main::collator)->compare(reply, $($nc(Main::rb)->getString("yes"_s))) == 0) {
				$assign(reply, "YES"_s);
			} else {
				$nc($System::err)->println($($nc(Main::rb)->getString("Wrong.answer.try.again"_s)));
				$assign(reply, nullptr);
			}
		}
	} while (reply == nullptr);
	return reply;
}

void Main::keystorecerts2Hashtable($KeyStore* ks, $Hashtable* hash) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Enumeration, aliases, $nc(ks)->aliases());
		for (; $nc(aliases)->hasMoreElements();) {
			$var($String, alias, $cast($String, aliases->nextElement()));
			$var($Certificate, cert, ks->getCertificate(alias));
			if (cert != nullptr) {
				$var($Principal, subjectDN, $nc(($cast($X509Certificate, cert)))->getSubjectX500Principal());
				$var($Pair, pair, $new($Pair, $($String::format($($nc(Main::rb)->getString(ks == this->caks ? "alias.in.cacerts"_s : "alias.in.keystore"_s)), $$new($ObjectArray, {$of(alias)}))), $cast($X509Certificate, cert)));
				$var($Vector, vec, $cast($Vector, $nc(hash)->get(subjectDN)));
				if (vec == nullptr) {
					$assign(vec, $new($Vector));
					vec->addElement(pair);
				} else if (!$nc(vec)->contains(pair)) {
					vec->addElement(pair);
				}
				hash->put(subjectDN, vec);
			}
		}
	}
}

$Date* Main::getStartDate($String* s) {
	$init(Main);
	$useLocalCurrentObjectStackCache();
	$var($Calendar, c, $new($GregorianCalendar));
	if (s != nullptr) {
		$var($IOException, ioe, $new($IOException, $($nc(Main::rb)->getString("Illegal.startdate.value"_s))));
		int32_t len = s->length();
		if (len == 0) {
			$throw(ioe);
		}
		bool var$0 = s->charAt(0) == u'-';
		if (var$0 || s->charAt(0) == u'+') {
			int32_t start = 0;
			while (start < len) {
				int32_t sign = 0;
				switch (s->charAt(start)) {
				case u'+':
					{
						sign = 1;
						break;
					}
				case u'-':
					{
						sign = -1;
						break;
					}
				default:
					{
						$throw(ioe);
					}
				}
				int32_t i = start + 1;
				for (; i < len; ++i) {
					char16_t ch = s->charAt(i);
					if (ch < u'0' || ch > u'9') {
						break;
					}
				}
				if (i == start + 1) {
					$throw(ioe);
				}
				int32_t number = $Integer::parseInt($(s->substring(start + 1, i)));
				if (i >= len) {
					$throw(ioe);
				}
				int32_t unit = 0;
				switch (s->charAt(i)) {
				case u'y':
					{
						unit = $Calendar::YEAR;
						break;
					}
				case u'm':
					{
						unit = $Calendar::MONTH;
						break;
					}
				case u'd':
					{
						unit = $Calendar::DATE;
						break;
					}
				case u'H':
					{
						unit = $Calendar::HOUR;
						break;
					}
				case u'M':
					{
						unit = $Calendar::MINUTE;
						break;
					}
				case u'S':
					{
						unit = $Calendar::SECOND;
						break;
					}
				default:
					{
						$throw(ioe);
					}
				}
				c->add(unit, sign * number);
				start = i + 1;
			}
		} else {
			$var($String, date, nullptr);
			$var($String, time, nullptr);
			if (len == 19) {
				$assign(date, s->substring(0, 10));
				$assign(time, s->substring(11));
				if (s->charAt(10) != u' ') {
					$throw(ioe);
				}
			} else if (len == 10) {
				$assign(date, s);
			} else if (len == 8) {
				$assign(time, s);
			} else {
				$throw(ioe);
			}
			if (date != nullptr) {
				if (date->matches("\\d\\d\\d\\d\\/\\d\\d\\/\\d\\d"_s)) {
					int32_t var$1 = $nc($($Integer::valueOf($(date->substring(0, 4)))))->intValue();
					int32_t var$2 = $nc($($Integer::valueOf($(date->substring(5, 7)))))->intValue() - 1;
					c->set(var$1, var$2, $nc($($Integer::valueOf($(date->substring(8, 10)))))->intValue());
				} else {
					$throw(ioe);
				}
			}
			if (time != nullptr) {
				if (time->matches("\\d\\d:\\d\\d:\\d\\d"_s)) {
					c->set($Calendar::HOUR_OF_DAY, $nc($($Integer::valueOf($(time->substring(0, 2)))))->intValue());
					c->set($Calendar::MINUTE, $nc($($Integer::valueOf($(time->substring(3, 5)))))->intValue());
					c->set($Calendar::SECOND, $nc($($Integer::valueOf($(time->substring(6, 8)))))->intValue());
					c->set($Calendar::MILLISECOND, 0);
				} else {
					$throw(ioe);
				}
			}
		}
	}
	return c->getTime();
}

int32_t Main::oneOf($String* s, $KnownOIDsArray* list) {
	$init(Main);
	$useLocalCurrentObjectStackCache();
	$var($StringArray, convertedList, $new($StringArray, $nc(list)->length));
	for (int32_t i = 0; i < list->length; ++i) {
		convertedList->set(i, $($nc(list->get(i))->stdName()));
	}
	return oneOf(s, convertedList);
}

int32_t Main::oneOf($String* s, $StringArray* list) {
	$init(Main);
	$useLocalCurrentObjectStackCache();
	int32_t res = oneOfMatch(static_cast<$BiFunction*>($$new(Main$$Lambda$lambda$oneOf$1$2)), s, list);
	if (res >= 0) {
		return res;
	}
	res = oneOfMatch(static_cast<$BiFunction*>($$new(Main$$Lambda$lambda$oneOf$2$3)), s, list);
	if (res >= 0) {
		return res;
	}
	return oneOfMatch(static_cast<$BiFunction*>($$new(Main$$Lambda$lambda$oneOf$3$4)), s, list);
}

int32_t Main::oneOfMatch($BiFunction* matcher, $String* s, $StringArray* list) {
	$init(Main);
	$useLocalCurrentObjectStackCache();
	$var($ints, match, $new($ints, $nc(list)->length));
	int32_t nmatch = 0;
	int32_t experiment = $Integer::MAX_VALUE;
	for (int32_t i = 0; i < list->length; ++i) {
		$var($String, one, list->get(i));
		if (one == nullptr) {
			experiment = i;
			continue;
		}
		if ($nc(($cast($Boolean, $($nc(matcher)->apply(s, one)))))->booleanValue()) {
			match->set(nmatch++, i);
		}
	}
	if (nmatch == 0) {
		return -1;
	} else if (nmatch == 1) {
		return match->get(0);
	} else {
		if (match->get(1) > experiment) {
			return match->get(0);
		}
		$var($StringBuilder, sb, $new($StringBuilder));
		$var($MessageFormat, form, $new($MessageFormat, $($nc(Main::rb)->getString("command.{0}.is.ambiguous."_s))));
		$var($ObjectArray, source, $new($ObjectArray, {$of(s)}));
		sb->append($(form->format(source)));
		sb->append("\n    "_s);
		for (int32_t i = 0; i < nmatch && match->get(i) < experiment; ++i) {
			sb->append(u' ');
			sb->append(list->get(match->get(i)));
		}
		$throwNew($Exception, $(sb->toString()));
	}
}

$GeneralName* Main::createGeneralName($String* t, $String* v, int32_t exttype) {
	$useLocalCurrentObjectStackCache();
	$var($GeneralNameInterface, gn, nullptr);
	int32_t p = oneOf(t, $$new($StringArray, {
		"EMAIL"_s,
		"URI"_s,
		"DNS"_s,
		"IP"_s,
		"OID"_s
	}));
	if (p < 0) {
		$throwNew($Exception, $$str({$($nc(Main::rb)->getString("Unrecognized.GeneralName.type."_s)), t}));
	}
	switch (p) {
	case 0:
		{
			$assign(gn, $new($RFC822Name, v));
			break;
		}
	case 1:
		{
			$assign(gn, $new($URIName, v));
			break;
		}
	case 2:
		{
			if (exttype == 3) {
				$assign(gn, $new($DNSName, v, true));
			} else {
				$assign(gn, $new($DNSName, v));
			}
			break;
		}
	case 3:
		{
			$assign(gn, $new($IPAddressName, v));
			break;
		}
	default:
		{
			$assign(gn, $new($OIDName, v));
			break;
		}
	}
	return $new($GeneralName, gn);
}

$ObjectIdentifier* Main::findOidForExtName($String* type) {
	switch (oneOf(type, Main::extSupported)) {
	case 0:
		{
			$init($PKIXExtensions);
			return $PKIXExtensions::BasicConstraints_Id;
		}
	case 1:
		{
			$init($PKIXExtensions);
			return $PKIXExtensions::KeyUsage_Id;
		}
	case 2:
		{
			$init($PKIXExtensions);
			return $PKIXExtensions::ExtendedKeyUsage_Id;
		}
	case 3:
		{
			$init($PKIXExtensions);
			return $PKIXExtensions::SubjectAlternativeName_Id;
		}
	case 4:
		{
			$init($PKIXExtensions);
			return $PKIXExtensions::IssuerAlternativeName_Id;
		}
	case 5:
		{
			$init($PKIXExtensions);
			return $PKIXExtensions::SubjectInfoAccess_Id;
		}
	case 6:
		{
			$init($PKIXExtensions);
			return $PKIXExtensions::AuthInfoAccess_Id;
		}
	case 8:
		{
			$init($PKIXExtensions);
			return $PKIXExtensions::CRLDistributionPoints_Id;
		}
	default:
		{
			return $ObjectIdentifier::of(type);
		}
	}
}

void Main::setExt($CertificateExtensions* result, $Extension* ex) {
	$init(Main);
	$nc(result)->set($($nc(ex)->getId()), ex);
}

$CertificateExtensions* Main::createV3Extensions($CertificateExtensions* requestedEx, $CertificateExtensions* existingEx, $List* extstrs, $PublicKey* pkey, $KeyIdentifier* aSubjectKeyId) {
	$useLocalCurrentObjectStackCache();
	if (existingEx != nullptr && requestedEx != nullptr) {
		$throwNew($Exception, "One of request and original should be null."_s);
	}
	$var($CertificateExtensions, result, $new($CertificateExtensions));
	if (existingEx != nullptr) {
		{
			$var($Iterator, i$, $nc($(existingEx->getAllExtensions()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Extension, ex, $cast($Extension, i$->next()));
				{
					setExt(result, ex);
				}
			}
		}
	}
	try {
		setExt(result, $$new($SubjectKeyIdentifierExtension, $($$new($KeyIdentifier, pkey)->getIdentifier())));
		if (aSubjectKeyId != nullptr) {
			setExt(result, $$new($AuthorityKeyIdentifierExtension, aSubjectKeyId, nullptr, nullptr));
		}
		if (requestedEx != nullptr) {
			$var($CertificateExtensions, request2, $new($CertificateExtensions));
			{
				$var($Iterator, i$, $nc($(requestedEx->getAllExtensions()))->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($Extension, ex, $cast($Extension, i$->next()));
					{
						request2->set($($nc(ex)->getId()), ex);
					}
				}
			}
			{
				$var($Iterator, i$, $nc(extstrs)->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($String, extstr, $cast($String, i$->next()));
					{
						$init($Locale);
						if ($($nc(extstr)->toLowerCase($Locale::ENGLISH))->startsWith("honored="_s)) {
							$var($List, list, $Arrays::asList($($($(extstr->toLowerCase($Locale::ENGLISH))->substring(8))->split(","_s))));
							if ($nc(list)->contains("all"_s)) {
								{
									$var($Iterator, i$, $nc($(request2->getAllExtensions()))->iterator());
									for (; $nc(i$)->hasNext();) {
										$var($Extension, ex, $cast($Extension, i$->next()));
										{
											setExt(result, ex);
										}
									}
								}
							}
							{
								$var($Iterator, i$, $nc(list)->iterator());
								for (; $nc(i$)->hasNext();) {
									$var($String, item, $cast($String, i$->next()));
									{
										if ($nc(item)->equals("all"_s)) {
											continue;
										}
										bool add = false;
										int32_t action = -1;
										$var($String, type, nullptr);
										if ($nc(item)->startsWith("-"_s)) {
											add = false;
											$assign(type, item->substring(1));
										} else {
											add = true;
											int32_t colonpos = item->indexOf((int32_t)u':');
											if (colonpos >= 0) {
												$assign(type, item->substring(0, colonpos));
												action = oneOf($(item->substring(colonpos + 1)), $$new($StringArray, {
													"critical"_s,
													"non-critical"_s
												}));
												if (action == -1) {
													$throwNew($Exception, $$str({$($nc(Main::rb)->getString("Illegal.value."_s)), item}));
												}
											} else {
												$assign(type, item);
											}
										}
										$var($String, n, $nc($(findOidForExtName(type)))->toString());
										if (add) {
											$var($Extension, e, $cast($Extension, request2->get(n)));
											bool var$0 = !$nc(e)->isCritical() && action == 0;
											if (var$0 || $nc(e)->isCritical() && action == 1) {
												$var($ObjectIdentifier, var$1, e->getExtensionId());
												bool var$2 = !e->isCritical();
												$assign(e, $Extension::newExtension(var$1, var$2, $(e->getExtensionValue())));
											}
											setExt(result, e);
										} else {
											result->delete$(n);
										}
									}
								}
							}
							break;
						}
					}
				}
			}
		}
		{
			$var($Iterator, i$, $nc(extstrs)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($String, extstr, $cast($String, i$->next()));
				{
					$var($String, name, nullptr);
					$var($String, value, nullptr);
					bool isCritical = false;
					int32_t eqpos = $nc(extstr)->indexOf((int32_t)u'=');
					if (eqpos >= 0) {
						$assign(name, extstr->substring(0, eqpos));
						$assign(value, extstr->substring(eqpos + 1));
					} else {
						$assign(name, extstr);
						$assign(value, nullptr);
					}
					int32_t colonpos = $nc(name)->indexOf((int32_t)u':');
					if (colonpos >= 0) {
						if (oneOf($(name->substring(colonpos + 1)), $$new($StringArray, {"critical"_s})) == 0) {
							isCritical = true;
						}
						$assign(name, name->substring(0, colonpos));
					}
					if (name->equalsIgnoreCase("honored"_s)) {
						continue;
					}
					int32_t exttype = oneOf(name, Main::extSupported);
					{
						int32_t pathLen = 0;
						bool isCA = false;
						$var($ObjectIdentifier, oid, nullptr)
						$var($bytes, data, nullptr)
						switch (exttype) {
						case 0:
							{
								pathLen = -1;
								isCA = false;
								if (value == nullptr) {
									isCA = true;
								} else {
									try {
										pathLen = $Integer::parseInt(value);
										isCA = true;
									} catch ($NumberFormatException& ufe) {
										{
											$var($StringArray, arr$, $nc(value)->split(","_s));
											int32_t len$ = arr$->length;
											int32_t i$ = 0;
											for (; i$ < len$; ++i$) {
												$var($String, part, arr$->get(i$));
												{
													$var($StringArray, nv, $nc(part)->split(":"_s));
													if (nv->length != 2) {
														$throwNew($Exception, $$str({$($nc(Main::rb)->getString("Illegal.value."_s)), extstr}));
													} else if ($nc(nv->get(0))->equalsIgnoreCase("ca"_s)) {
														isCA = $Boolean::parseBoolean(nv->get(1));
													} else if ($nc(nv->get(0))->equalsIgnoreCase("pathlen"_s)) {
														pathLen = $Integer::parseInt(nv->get(1));
													} else {
														$throwNew($Exception, $$str({$($nc(Main::rb)->getString("Illegal.value."_s)), extstr}));
													}
												}
											}
										}
									}
								}
								setExt(result, $$new($BasicConstraintsExtension, $($Boolean::valueOf(isCritical)), isCA, pathLen));
								break;
							}
						case 1:
							{
								if (value != nullptr) {
									$var($booleans, ok, $new($booleans, 9));
									{
										$var($StringArray, arr$, value->split(","_s));
										int32_t len$ = arr$->length;
										int32_t i$ = 0;
										for (; i$ < len$; ++i$) {
											$var($String, s, arr$->get(i$));
											{
												int32_t p = oneOf(s, $$new($StringArray, {
													"digitalSignature"_s,
													"nonRepudiation"_s,
													"keyEncipherment"_s,
													"dataEncipherment"_s,
													"keyAgreement"_s,
													"keyCertSign"_s,
													"cRLSign"_s,
													"encipherOnly"_s,
													"decipherOnly"_s,
													"contentCommitment"_s
												}));
												if (p < 0) {
													$throwNew($Exception, $$str({$($nc(Main::rb)->getString("Unknown.keyUsage.type."_s)), s}));
												}
												if (p == 9) {
													p = 1;
												}
												ok->set(p, true);
											}
										}
									}
									$var($KeyUsageExtension, kue, $new($KeyUsageExtension, ok));
									$var($ObjectIdentifier, var$3, kue->getExtensionId());
									bool var$4 = isCritical;
									setExt(result, $($Extension::newExtension(var$3, var$4, $(kue->getExtensionValue()))));
								} else {
									$throwNew($Exception, $$str({$($nc(Main::rb)->getString("Illegal.value."_s)), extstr}));
								}
								break;
							}
						case 2:
							{
								if (value != nullptr) {
									$var($Vector, v, $new($Vector));
									$init($KnownOIDs);
									$var($KnownOIDsArray, choices, $new($KnownOIDsArray, {
										$KnownOIDs::anyExtendedKeyUsage,
										$KnownOIDs::serverAuth,
										$KnownOIDs::clientAuth,
										$KnownOIDs::codeSigning,
										$KnownOIDs::emailProtection,
										$KnownOIDs::KP_TimeStamping,
										$KnownOIDs::OCSPSigning
									}));
									{
										$var($StringArray, arr$, value->split(","_s));
										int32_t len$ = arr$->length;
										int32_t i$ = 0;
										for (; i$ < len$; ++i$) {
											$var($String, s, arr$->get(i$));
											{
												int32_t p = oneOf(s, choices);
												$var($String, o, s);
												if (p >= 0) {
													$assign(o, $nc(choices->get(p))->value());
												}
												try {
													v->add($($ObjectIdentifier::of(o)));
												} catch ($Exception& e) {
													$throwNew($Exception, $$str({$($nc(Main::rb)->getString("Unknown.extendedkeyUsage.type."_s)), s}));
												}
											}
										}
									}
									setExt(result, $$new($ExtendedKeyUsageExtension, $($Boolean::valueOf(isCritical)), v));
								} else {
									$throwNew($Exception, $$str({$($nc(Main::rb)->getString("Illegal.value."_s)), extstr}));
								}
								break;
							}
						case 3:
							{}
						case 4:
							{
								if (value != nullptr) {
									$var($StringArray, ps, value->split(","_s));
									$var($GeneralNames, gnames, $new($GeneralNames));
									{
										$var($StringArray, arr$, ps);
										int32_t len$ = arr$->length;
										int32_t i$ = 0;
										for (; i$ < len$; ++i$) {
											$var($String, item, arr$->get(i$));
											{
												colonpos = $nc(item)->indexOf((int32_t)u':');
												if (colonpos < 0) {
													$throwNew($Exception, $$str({"Illegal item "_s, item, " in "_s, extstr}));
												}
												$var($String, t, item->substring(0, colonpos));
												$var($String, v, item->substring(colonpos + 1));
												gnames->add($(createGeneralName(t, v, exttype)));
											}
										}
									}
									if (exttype == 3) {
										setExt(result, $$new($SubjectAlternativeNameExtension, $($Boolean::valueOf(isCritical)), gnames));
									} else {
										setExt(result, $$new($IssuerAlternativeNameExtension, $($Boolean::valueOf(isCritical)), gnames));
									}
								} else {
									$throwNew($Exception, $$str({$($nc(Main::rb)->getString("Illegal.value."_s)), extstr}));
								}
								break;
							}
						case 5:
							{}
						case 6:
							{
								if (isCritical) {
									$throwNew($Exception, $$str({$($nc(Main::rb)->getString("This.extension.cannot.be.marked.as.critical."_s)), extstr}));
								}
								if (value != nullptr) {
									$var($List, accessDescriptions, $new($ArrayList));
									$var($StringArray, ps, value->split(","_s));
									{
										$var($StringArray, arr$, ps);
										int32_t len$ = arr$->length;
										int32_t i$ = 0;
										for (; i$ < len$; ++i$) {
											$var($String, item, arr$->get(i$));
											{
												colonpos = $nc(item)->indexOf((int32_t)u':');
												int32_t colonpos2 = item->indexOf((int32_t)u':', colonpos + 1);
												if (colonpos < 0 || colonpos2 < 0) {
													$throwNew($Exception, $$str({$($nc(Main::rb)->getString("Illegal.value."_s)), extstr}));
												}
												$var($String, m, item->substring(0, colonpos));
												$var($String, t, item->substring(colonpos + 1, colonpos2));
												$var($String, v, item->substring(colonpos2 + 1));
												$init($KnownOIDs);
												$var($KnownOIDsArray, choices, $new($KnownOIDsArray, {
													$KnownOIDs::OCSP,
													$KnownOIDs::caIssuers,
													$KnownOIDs::AD_TimeStamping,
													$KnownOIDs::caRepository
												}));
												int32_t p = oneOf(m, choices);
												$var($ObjectIdentifier, oid, nullptr);
												if (p >= 0) {
													$assign(oid, $ObjectIdentifier::of(choices->get(p)));
												} else {
													try {
														$assign(oid, $ObjectIdentifier::of(m));
													} catch ($Exception& e) {
														$throwNew($Exception, $$str({$($nc(Main::rb)->getString("Unknown.AccessDescription.type."_s)), m}));
													}
												}
												accessDescriptions->add($$new($AccessDescription, oid, $(createGeneralName(t, v, exttype))));
											}
										}
									}
									if (exttype == 5) {
										setExt(result, $$new($SubjectInfoAccessExtension, accessDescriptions));
									} else {
										setExt(result, $$new($AuthorityInfoAccessExtension, accessDescriptions));
									}
								} else {
									$throwNew($Exception, $$str({$($nc(Main::rb)->getString("Illegal.value."_s)), extstr}));
								}
								break;
							}
						case 8:
							{
								if (value != nullptr) {
									$var($StringArray, ps, value->split(","_s));
									$var($GeneralNames, gnames, $new($GeneralNames));
									{
										$var($StringArray, arr$, ps);
										int32_t len$ = arr$->length;
										int32_t i$ = 0;
										for (; i$ < len$; ++i$) {
											$var($String, item, arr$->get(i$));
											{
												colonpos = $nc(item)->indexOf((int32_t)u':');
												if (colonpos < 0) {
													$throwNew($Exception, $$str({"Illegal item "_s, item, " in "_s, extstr}));
												}
												$var($String, t, item->substring(0, colonpos));
												$var($String, v, item->substring(colonpos + 1));
												gnames->add($(createGeneralName(t, v, exttype)));
											}
										}
									}
									setExt(result, $$new($CRLDistributionPointsExtension, isCritical, $($Collections::singletonList($$new($DistributionPoint, gnames, ($booleans*)nullptr, ($GeneralNames*)nullptr)))));
								} else {
									$throwNew($Exception, $$str({$($nc(Main::rb)->getString("Illegal.value."_s)), extstr}));
								}
								break;
							}
						case -1:
							{
								$assign(oid, $ObjectIdentifier::of(name));
								$assign(data, nullptr);
								if (value != nullptr) {
									$assign(data, $new($bytes, value->length() / 2 + 1));
									int32_t pos = 0;
									{
										$var($chars, arr$, value->toCharArray());
										int32_t len$ = arr$->length;
										int32_t i$ = 0;
										for (; i$ < len$; ++i$) {
											char16_t c = arr$->get(i$);
											{
												if (!$HexFormat::isHexDigit(c)) {
													continue;
												}
												int32_t hex = $HexFormat::fromHexDigit(c);
												if (pos % 2 == 0) {
													data->set(pos / 2, (int8_t)(hex << 4));
												} else {
													(*data)[pos / 2] += hex;
												}
												++pos;
											}
										}
									}
									if (pos % 2 != 0) {
										$throwNew($Exception, $$str({$($nc(Main::rb)->getString("Odd.number.of.hex.digits.found."_s)), extstr}));
									}
									$assign(data, $Arrays::copyOf(data, pos / 2));
								} else {
									$assign(data, $new($bytes, 0));
								}
								setExt(result, $$new($Extension, oid, isCritical, $($$new($DerValue, $DerValue::tag_OctetString, data)->toByteArray())));
								break;
							}
						default:
							{
								$throwNew($Exception, $$str({$($nc(Main::rb)->getString("Unknown.extension.type."_s)), extstr}));
							}
						}
					}
				}
			}
		}
	} catch ($IOException& e) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(e));
	}
	return result;
}

bool Main::isTrustedCert($Certificate* cert) {
	if (this->caks != nullptr && $nc(this->caks)->getCertificateAlias(cert) != nullptr) {
		return true;
	} else {
		$var($String, inKS, $nc(this->keyStore)->getCertificateAlias(cert));
		return inKS != nullptr && $nc(this->keyStore)->isCertificateEntry(inKS);
	}
}

void Main::checkWeak($String* label, $String* sigAlg, $Key* key) {
	$useLocalCurrentObjectStackCache();
	if (sigAlg != nullptr) {
		if (!$nc(Main::DISABLED_CHECK)->permits(Main::SIG_PRIMITIVE_SET, sigAlg, ($AlgorithmParameters*)nullptr)) {
			$nc(this->weakWarnings)->add($($String::format($($nc(Main::rb)->getString("whose.sigalg.disabled"_s)), $$new($ObjectArray, {
				$of(label),
				$of(sigAlg)
			}))));
		} else if (!$nc(Main::LEGACY_CHECK)->permits(Main::SIG_PRIMITIVE_SET, sigAlg, ($AlgorithmParameters*)nullptr)) {
			$nc(this->weakWarnings)->add($($String::format($($nc(Main::rb)->getString("whose.sigalg.weak"_s)), $$new($ObjectArray, {
				$of(label),
				$of(sigAlg)
			}))));
		}
	}
	if (key != nullptr) {
		if (!$nc(Main::DISABLED_CHECK)->permits(Main::SIG_PRIMITIVE_SET, key)) {
			$var($String, var$0, $nc(Main::rb)->getString("whose.key.disabled"_s));
			$var($String, var$1, $nc(Main::rb)->getString("key.bit"_s));
			$nc(this->weakWarnings)->add($($String::format(var$0, $$new($ObjectArray, {
				$of(label),
				$($of($String::format(var$1, $$new($ObjectArray, {
					$($of($Integer::valueOf($KeyUtil::getKeySize(key)))),
					$($of(fullDisplayAlgName(key)))
				}))))
			}))));
		} else if (!$nc(Main::LEGACY_CHECK)->permits(Main::SIG_PRIMITIVE_SET, key)) {
			$var($String, var$2, $nc(Main::rb)->getString("whose.key.weak"_s));
			$var($String, var$3, $nc(Main::rb)->getString("key.bit"_s));
			$nc(this->weakWarnings)->add($($String::format(var$2, $$new($ObjectArray, {
				$of(label),
				$($of($String::format(var$3, $$new($ObjectArray, {
					$($of($Integer::valueOf($KeyUtil::getKeySize(key)))),
					$($of(fullDisplayAlgName(key)))
				}))))
			}))));
		}
	}
}

void Main::checkWeak($String* label, $CertificateArray* certs) {
	$useLocalCurrentObjectStackCache();
	for (int32_t i = 0; i < $nc(certs)->length; ++i) {
		$var($Certificate, cert, certs->get(i));
		if ($instanceOf($X509Certificate, cert)) {
			$var($X509Certificate, xc, $cast($X509Certificate, cert));
			$var($String, fullLabel, label);
			if (certs->length > 1) {
				$assign(fullLabel, oneInMany(label, i, certs->length));
			}
			checkWeak(fullLabel, static_cast<$Certificate*>(xc));
		}
	}
}

void Main::checkWeak($String* label, $Certificate* cert) {
	$useLocalCurrentObjectStackCache();
	if ($instanceOf($X509Certificate, cert)) {
		$var($X509Certificate, xc, $cast($X509Certificate, cert));
		$var($String, sigAlg, isTrustedCert(cert) ? ($String*)nullptr : $nc(xc)->getSigAlgName());
		checkWeak(label, sigAlg, $(static_cast<$Key*>(xc->getPublicKey())));
	}
}

void Main::checkWeak($String* label, $PKCS10* p10) {
	$useLocalCurrentObjectStackCache();
	$var($String, var$0, label);
	$var($String, var$1, $nc(p10)->getSigAlg());
	checkWeak(var$0, var$1, $(static_cast<$Key*>(p10->getSubjectPublicKeyInfo())));
}

void Main::checkWeak($String* label, $CRL* crl, $Key* key) {
	$useLocalCurrentObjectStackCache();
	if ($instanceOf($X509CRLImpl, crl)) {
		$var($X509CRLImpl, impl, $cast($X509CRLImpl, crl));
		checkWeak(label, $($nc(impl)->getSigAlgName()), key);
	}
}

void Main::printWeakWarnings(bool newLine) {
	$useLocalCurrentObjectStackCache();
	if (!$nc(this->weakWarnings)->isEmpty() && !this->nowarn) {
		$nc($System::err)->println("\nWarning:"_s);
		{
			$var($Iterator, i$, $nc(this->weakWarnings)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($String, warning, $cast($String, i$->next()));
				{
					$nc($System::err)->println(warning);
				}
			}
		}
		if (newLine) {
			$nc($System::err)->println();
		}
	}
	$nc(this->weakWarnings)->clear();
}

void Main::usage() {
	$useLocalCurrentObjectStackCache();
	if (this->command != nullptr) {
		$var($String, var$0, $$str({"keytool "_s, this->command}));
		$nc($System::err)->println($$concat(var$0, $($nc(Main::rb)->getString(".OPTION."_s))));
		$nc($System::err)->println();
		$nc($System::err)->println($($nc(Main::rb)->getString($nc(this->command)->description)));
		$nc($System::err)->println();
		$nc($System::err)->println($($nc(Main::rb)->getString("Options."_s)));
		$nc($System::err)->println();
		$var($StringArray, left, $new($StringArray, $nc($nc(this->command)->options)->length));
		$var($StringArray, right, $new($StringArray, $nc($nc(this->command)->options)->length));
		int32_t lenLeft = 0;
		for (int32_t j = 0; j < $nc($nc(this->command)->options)->length; ++j) {
			$Main$Option* opt = $nc($nc(this->command)->options)->get(j);
			left->set(j, $($nc(opt)->toString()));
			if (opt->arg != nullptr) {
				$nc(left)->plusAssign(j, $$str({" "_s, opt->arg}));
			}
			$var($StringArray, lefts, $nc(left->get(j))->split("\n"_s));
			{
				$var($StringArray, arr$, lefts);
				int32_t len$ = arr$->length;
				int32_t i$ = 0;
				for (; i$ < len$; ++i$) {
					$var($String, s, arr$->get(i$));
					{
						if ($nc(s)->length() > lenLeft) {
							lenLeft = s->length();
						}
					}
				}
			}
			right->set(j, $($nc(Main::rb)->getString(opt->description)));
		}
		for (int32_t j = 0; j < left->length; ++j) {
			$var($StringArray, lefts, $nc(left->get(j))->split("\n"_s));
			$var($StringArray, rights, $nc(right->get(j))->split("\n"_s));
			for (int32_t i = 0; i < lefts->length && i < rights->length; ++i) {
				$var($String, s1, i < lefts->length ? lefts->get(i) : ""_s);
				$var($String, s2, i < rights->length ? rights->get(i) : ""_s);
				if (i == 0) {
					$nc($System::err)->printf($$str({" %-"_s, $$str(lenLeft), "s  %s\n"_s}), $$new($ObjectArray, {
						$of(s1),
						$of(s2)
					}));
				} else {
					$nc($System::err)->printf($$str({"   %-"_s, $$str(lenLeft), "s  %s\n"_s}), $$new($ObjectArray, {
						$of(s1),
						$of(s2)
					}));
				}
			}
		}
		$nc($System::err)->println();
		$nc($System::err)->println($($nc(Main::rb)->getString("Use.keytool.help.for.all.available.commands"_s)));
	} else {
		$nc($System::err)->println($($nc(Main::rb)->getString("Key.and.Certificate.Management.Tool"_s)));
		$nc($System::err)->println();
		$nc($System::err)->println($($nc(Main::rb)->getString("Commands."_s)));
		$nc($System::err)->println();
		{
			$var($Main$CommandArray, arr$, $Main$Command::values());
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$Main$Command* c = arr$->get(i$);
				{
					if (c == $Main$Command::KEYCLONE) {
						break;
					}
					$nc($System::err)->printf(" %-20s%s\n"_s, $$new($ObjectArray, {
						$of(c),
						$($of($nc(Main::rb)->getString($nc(c)->description)))
					}));
				}
			}
		}
		$nc($System::err)->println();
		$nc($System::err)->println($($nc(Main::rb)->getString("Use.keytool.help.for.all.available.commands"_s)));
		$nc($System::err)->println($($nc(Main::rb)->getString("Use.keytool.command.name.help.for.usage.of.command.name"_s)));
	}
}

void Main::tinyHelp() {
	usage();
	if (this->debug) {
		$throwNew($RuntimeException, "NO BIG ERROR, SORRY"_s);
	} else {
		$System::exit(1);
	}
}

void Main::errorNeedArgument($String* flag) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, source, $new($ObjectArray, {$of(flag)}));
	$nc($System::err)->println($($$new($MessageFormat, $($nc(Main::rb)->getString("Command.option.flag.needs.an.argument."_s)))->format(source)));
	tinyHelp();
}

$chars* Main::getPass($String* modifier, $String* arg) {
	$var($chars, output, $KeyStoreUtil::getPassWithModifier(modifier, arg, Main::rb, Main::collator));
	if (output != nullptr) {
		return output;
	}
	tinyHelp();
	return nullptr;
}

$Boolean* Main::lambda$oneOf$3($String* a, $String* b) {
	$init(Main);
	$useLocalCurrentObjectStackCache();
	bool var$0 = $nc(a)->equalsIgnoreCase($($nc(b)->replaceAll("(?<!^)[a-z]"_s, ""_s)));
	$init($Locale);
	return $Boolean::valueOf(var$0 || $($nc(b)->toUpperCase($Locale::ROOT))->startsWith($($nc(a)->toUpperCase($Locale::ROOT))));
}

$Boolean* Main::lambda$oneOf$2($String* a, $String* b) {
	$init(Main);
	bool var$0 = $nc(a)->equals($($nc(b)->replaceAll("(?<!^)[a-z]"_s, ""_s)));
	return $Boolean::valueOf(var$0 || $nc(b)->startsWith(a));
}

$Boolean* Main::lambda$oneOf$1($String* a, $String* b) {
	$init(Main);
	return $Boolean::valueOf($nc(a)->equals(b));
}

bool Main::lambda$parseArgs$0($String* x) {
	$init(Main);
	return $nc(Main::collator)->compare(x, "-debug"_s) == 0;
}

void clinit$Main($Class* class$) {
	$assignStatic(Main::NONE, "NONE"_s);
	$assignStatic(Main::P11KEYSTORE, "PKCS11"_s);
	$assignStatic(Main::P12KEYSTORE, "PKCS12"_s);
	$assignStatic(Main::keyAlias, "mykey"_s);
	$beforeCallerSensitive();
	$assignStatic(Main::CRLF, $new($bytes, {
		(int8_t)u'\r',
		(int8_t)u'\n'
	}));
	$init($DisabledAlgorithmConstraints);
	$assignStatic(Main::DISABLED_CHECK, $new($DisabledAlgorithmConstraints, $DisabledAlgorithmConstraints::PROPERTY_CERTPATH_DISABLED_ALGS));
	$assignStatic(Main::LEGACY_CHECK, $new($DisabledAlgorithmConstraints, $DisabledAlgorithmConstraints::PROPERTY_SECURITY_LEGACY_ALGS));
	$init($CryptoPrimitive);
	$assignStatic(Main::SIG_PRIMITIVE_SET, $Collections::unmodifiableSet($($EnumSet::of($CryptoPrimitive::SIGNATURE))));
	{
		$init($Main$Command);
		$Main$Command::GENKEYPAIR->setAltName("-genkey"_s);
		$Main$Command::IMPORTCERT->setAltName("-import"_s);
		$Main$Command::EXPORTCERT->setAltName("-export"_s);
		$Main$Command::IMPORTPASS->setAltName("-importpassword"_s);
	}
	$assignStatic(Main::rb, $ResourceBundle::getBundle("sun.security.tools.keytool.Resources"_s));
	$assignStatic(Main::collator, $Collator::getInstance());
	{
		$nc(Main::collator)->setStrength($Collator::PRIMARY);
	}
	$assignStatic(Main::extSupported, $new($StringArray, {
		"BasicConstraints"_s,
		"KeyUsage"_s,
		"ExtendedKeyUsage"_s,
		"SubjectAlternativeName"_s,
		"IssuerAlternativeName"_s,
		"SubjectInfoAccess"_s,
		"AuthorityInfoAccess"_s,
		($String*)nullptr,
		"CRLDistributionPoints"_s
	}));
}

Main::Main() {
}

$Class* Main::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Main$$Lambda$lambda$parseArgs$0::classInfo$.name)) {
			return Main$$Lambda$lambda$parseArgs$0::load$(name, initialize);
		}
		if (name->equals(Main$$Lambda$compareTo$1::classInfo$.name)) {
			return Main$$Lambda$compareTo$1::load$(name, initialize);
		}
		if (name->equals(Main$$Lambda$lambda$oneOf$1$2::classInfo$.name)) {
			return Main$$Lambda$lambda$oneOf$1$2::load$(name, initialize);
		}
		if (name->equals(Main$$Lambda$lambda$oneOf$2$3::classInfo$.name)) {
			return Main$$Lambda$lambda$oneOf$2$3::load$(name, initialize);
		}
		if (name->equals(Main$$Lambda$lambda$oneOf$3$4::classInfo$.name)) {
			return Main$$Lambda$lambda$oneOf$3$4::load$(name, initialize);
		}
	}
	$loadClass(Main, name, initialize, &_Main_ClassInfo_, clinit$Main, allocate$Main);
	return class$;
}

$Class* Main::class$ = nullptr;

			} // keytool
		} // tools
	} // security
} // sun