#include <sun/security/util/SignatureFileVerifier.h>

#include <java/io/ByteArrayInputStream.h>
#include <java/io/InputStream.h>
#include <java/lang/SecurityException.h>
#include <java/security/CodeSigner.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/MessageDigest.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/PrivateKey.h>
#include <java/security/SignatureException.h>
#include <java/security/Timestamp.h>
#include <java/security/cert/CertPath.h>
#include <java/security/cert/CertificateFactory.h>
#include <java/util/ArrayList.h>
#include <java/util/Base64$Decoder.h>
#include <java/util/Base64.h>
#include <java/util/HashMap.h>
#include <java/util/Hashtable.h>
#include <java/util/HexFormat.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/jar/Attributes$Name.h>
#include <java/util/jar/Attributes.h>
#include <java/util/jar/Manifest.h>
#include <sun/security/jca/Providers.h>
#include <sun/security/pkcs/ContentInfo.h>
#include <sun/security/pkcs/PKCS7.h>
#include <sun/security/pkcs/SignerInfo.h>
#include <sun/security/util/ConstraintsParameters.h>
#include <sun/security/util/Debug.h>
#include <sun/security/util/DisabledAlgorithmConstraints.h>
#include <sun/security/util/JarConstraintsParameters.h>
#include <sun/security/util/ManifestDigester$Entry.h>
#include <sun/security/util/ManifestDigester.h>
#include <jcpp.h>

#undef ATTR_DIGEST
#undef ENGLISH
#undef FALSE
#undef MF_MAIN_ATTRS
#undef SIGNATURE_VERSION
#undef TRUE

using $CodeSignerArray = $Array<::java::security::CodeSigner>;
using $SignerInfoArray = $Array<::sun::security::pkcs::SignerInfo>;
using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $InputStream = ::java::io::InputStream;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $SecurityException = ::java::lang::SecurityException;
using $CodeSigner = ::java::security::CodeSigner;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $MessageDigest = ::java::security::MessageDigest;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $PrivateKey = ::java::security::PrivateKey;
using $SignatureException = ::java::security::SignatureException;
using $CertPath = ::java::security::cert::CertPath;
using $CertificateFactory = ::java::security::cert::CertificateFactory;
using $ArrayList = ::java::util::ArrayList;
using $Base64 = ::java::util::Base64;
using $Base64$Decoder = ::java::util::Base64$Decoder;
using $HashMap = ::java::util::HashMap;
using $Hashtable = ::java::util::Hashtable;
using $HexFormat = ::java::util::HexFormat;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;
using $Attributes = ::java::util::jar::Attributes;
using $Attributes$Name = ::java::util::jar::Attributes$Name;
using $Manifest = ::java::util::jar::Manifest;
using $Providers = ::sun::security::jca::Providers;
using $ContentInfo = ::sun::security::pkcs::ContentInfo;
using $PKCS7 = ::sun::security::pkcs::PKCS7;
using $SignerInfo = ::sun::security::pkcs::SignerInfo;
using $ConstraintsParameters = ::sun::security::util::ConstraintsParameters;
using $Debug = ::sun::security::util::Debug;
using $DisabledAlgorithmConstraints = ::sun::security::util::DisabledAlgorithmConstraints;
using $JarConstraintsParameters = ::sun::security::util::JarConstraintsParameters;
using $ManifestDigester = ::sun::security::util::ManifestDigester;
using $ManifestDigester$Entry = ::sun::security::util::ManifestDigester$Entry;

namespace sun {
	namespace security {
		namespace util {

$FieldInfo _SignatureFileVerifier_FieldInfo_[] = {
	{"debug", "Lsun/security/util/Debug;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SignatureFileVerifier, debug)},
	{"signerCache", "Ljava/util/ArrayList;", "Ljava/util/ArrayList<[Ljava/security/CodeSigner;>;", $PRIVATE, $field(SignatureFileVerifier, signerCache)},
	{"ATTR_DIGEST", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SignatureFileVerifier, ATTR_DIGEST)},
	{"block", "Lsun/security/pkcs/PKCS7;", nullptr, $PRIVATE, $field(SignatureFileVerifier, block)},
	{"sfBytes", "[B", nullptr, $PRIVATE, $field(SignatureFileVerifier, sfBytes)},
	{"name", "Ljava/lang/String;", nullptr, $PRIVATE, $field(SignatureFileVerifier, name)},
	{"md", "Lsun/security/util/ManifestDigester;", nullptr, $PRIVATE, $field(SignatureFileVerifier, md)},
	{"createdDigests", "Ljava/util/HashMap;", "Ljava/util/HashMap<Ljava/lang/String;Ljava/security/MessageDigest;>;", $PRIVATE, $field(SignatureFileVerifier, createdDigests)},
	{"workaround", "Z", nullptr, $PRIVATE, $field(SignatureFileVerifier, workaround)},
	{"certificateFactory", "Ljava/security/cert/CertificateFactory;", nullptr, $PRIVATE, $field(SignatureFileVerifier, certificateFactory)},
	{"permittedAlgs", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/Boolean;>;", $PRIVATE, $field(SignatureFileVerifier, permittedAlgs)},
	{"params", "Lsun/security/util/JarConstraintsParameters;", nullptr, $PRIVATE, $field(SignatureFileVerifier, params)},
	{}
};

$MethodInfo _SignatureFileVerifier_MethodInfo_[] = {
	{"<init>", "(Ljava/util/ArrayList;Lsun/security/util/ManifestDigester;Ljava/lang/String;[B)V", "(Ljava/util/ArrayList<[Ljava/security/CodeSigner;>;Lsun/security/util/ManifestDigester;Ljava/lang/String;[B)V", $PUBLIC, $method(SignatureFileVerifier, init$, void, $ArrayList*, $ManifestDigester*, $String*, $bytes*), "java.io.IOException,java.security.cert.CertificateException"},
	{"contains", "([Ljava/security/CodeSigner;Ljava/security/CodeSigner;)Z", nullptr, $STATIC, $staticMethod(SignatureFileVerifier, contains, bool, $CodeSignerArray*, $CodeSigner*)},
	{"getBlockExtension", "(Ljava/security/PrivateKey;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(SignatureFileVerifier, getBlockExtension, $String*, $PrivateKey*)},
	{"getDigest", "(Ljava/lang/String;)Ljava/security/MessageDigest;", nullptr, $PRIVATE, $method(SignatureFileVerifier, getDigest, $MessageDigest*, $String*), "java.security.SignatureException"},
	{"getSigners", "([Lsun/security/pkcs/SignerInfo;Lsun/security/pkcs/PKCS7;)[Ljava/security/CodeSigner;", nullptr, $PRIVATE, $method(SignatureFileVerifier, getSigners, $CodeSignerArray*, $SignerInfoArray*, $PKCS7*), "java.io.IOException,java.security.NoSuchAlgorithmException,java.security.SignatureException,java.security.cert.CertificateException"},
	{"getWeakAlgorithms", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, 0, $virtualMethod(SignatureFileVerifier, getWeakAlgorithms, $String*, $String*)},
	{"isBlockOrSF", "(Ljava/lang/String;)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(SignatureFileVerifier, isBlockOrSF, bool, $String*)},
	{"isSigningRelated", "(Ljava/lang/String;)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(SignatureFileVerifier, isSigningRelated, bool, $String*)},
	{"isSubSet", "([Ljava/security/CodeSigner;[Ljava/security/CodeSigner;)Z", nullptr, $STATIC, $staticMethod(SignatureFileVerifier, isSubSet, bool, $CodeSignerArray*, $CodeSignerArray*)},
	{"matches", "([Ljava/security/CodeSigner;[Ljava/security/CodeSigner;[Ljava/security/CodeSigner;)Z", nullptr, $STATIC, $staticMethod(SignatureFileVerifier, matches, bool, $CodeSignerArray*, $CodeSignerArray*, $CodeSignerArray*)},
	{"needSignatureFile", "(Ljava/lang/String;)Z", nullptr, $PUBLIC, $virtualMethod(SignatureFileVerifier, needSignatureFile, bool, $String*)},
	{"needSignatureFileBytes", "()Z", nullptr, $PUBLIC, $virtualMethod(SignatureFileVerifier, needSignatureFileBytes, bool)},
	{"permittedCheck", "(Ljava/lang/String;Ljava/lang/String;)Z", nullptr, $PRIVATE, $method(SignatureFileVerifier, permittedCheck, bool, $String*, $String*)},
	{"process", "(Ljava/util/Hashtable;Ljava/util/List;Ljava/lang/String;)V", "(Ljava/util/Hashtable<Ljava/lang/String;[Ljava/security/CodeSigner;>;Ljava/util/List<Ljava/lang/Object;>;Ljava/lang/String;)V", $PUBLIC, $virtualMethod(SignatureFileVerifier, process, void, $Hashtable*, $List*, $String*), "java.io.IOException,java.security.SignatureException,java.security.NoSuchAlgorithmException,java.util.jar.JarException,java.security.cert.CertificateException"},
	{"processImpl", "(Ljava/util/Hashtable;Ljava/util/List;Ljava/lang/String;)V", "(Ljava/util/Hashtable<Ljava/lang/String;[Ljava/security/CodeSigner;>;Ljava/util/List<Ljava/lang/Object;>;Ljava/lang/String;)V", $PRIVATE, $method(SignatureFileVerifier, processImpl, void, $Hashtable*, $List*, $String*), "java.io.IOException,java.security.SignatureException,java.security.NoSuchAlgorithmException,java.util.jar.JarException,java.security.cert.CertificateException"},
	{"setSignatureFile", "([B)V", nullptr, $PUBLIC, $virtualMethod(SignatureFileVerifier, setSignatureFile, void, $bytes*)},
	{"updateSigners", "([Ljava/security/CodeSigner;Ljava/util/Hashtable;Ljava/lang/String;)V", "([Ljava/security/CodeSigner;Ljava/util/Hashtable<Ljava/lang/String;[Ljava/security/CodeSigner;>;Ljava/lang/String;)V", 0, $virtualMethod(SignatureFileVerifier, updateSigners, void, $CodeSignerArray*, $Hashtable*, $String*)},
	{"verifyManifestHash", "(Ljava/util/jar/Manifest;Lsun/security/util/ManifestDigester;Ljava/util/List;)Z", "(Ljava/util/jar/Manifest;Lsun/security/util/ManifestDigester;Ljava/util/List<Ljava/lang/Object;>;)Z", $PRIVATE, $method(SignatureFileVerifier, verifyManifestHash, bool, $Manifest*, $ManifestDigester*, $List*), "java.io.IOException,java.security.SignatureException"},
	{"verifyManifestMainAttrs", "(Ljava/util/jar/Manifest;Lsun/security/util/ManifestDigester;)Z", nullptr, $PRIVATE, $method(SignatureFileVerifier, verifyManifestMainAttrs, bool, $Manifest*, $ManifestDigester*), "java.io.IOException,java.security.SignatureException"},
	{"verifySection", "(Ljava/util/jar/Attributes;Ljava/lang/String;Lsun/security/util/ManifestDigester;)Z", nullptr, $PRIVATE, $method(SignatureFileVerifier, verifySection, bool, $Attributes*, $String*, $ManifestDigester*), "java.io.IOException,java.security.SignatureException"},
	{}
};

$ClassInfo _SignatureFileVerifier_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.util.SignatureFileVerifier",
	"java.lang.Object",
	nullptr,
	_SignatureFileVerifier_FieldInfo_,
	_SignatureFileVerifier_MethodInfo_
};

$Object* allocate$SignatureFileVerifier($Class* clazz) {
	return $of($alloc(SignatureFileVerifier));
}

$Debug* SignatureFileVerifier::debug = nullptr;
$String* SignatureFileVerifier::ATTR_DIGEST = nullptr;

void SignatureFileVerifier::init$($ArrayList* signerCache, $ManifestDigester* md, $String* name, $bytes* rawBytes) {
	$useLocalCurrentObjectStackCache();
	this->workaround = false;
	$set(this, certificateFactory, nullptr);
	$set(this, permittedAlgs, $new($HashMap));
	$var($Object, obj, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		try {
			$assign(obj, $Providers::startJarVerification());
			$set(this, block, $new($PKCS7, rawBytes));
			$set(this, sfBytes, $nc($($nc(this->block)->getContentInfo()))->getData());
			$set(this, certificateFactory, $CertificateFactory::getInstance("X509"_s));
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$Providers::stopJarVerification(obj);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	$init($Locale);
	$set(this, name, $($nc(name)->substring(0, name->lastIndexOf((int32_t)u'.')))->toUpperCase($Locale::ENGLISH));
	$set(this, md, md);
	$set(this, signerCache, signerCache);
}

bool SignatureFileVerifier::needSignatureFileBytes() {
	return this->sfBytes == nullptr;
}

bool SignatureFileVerifier::needSignatureFile($String* name) {
	return $nc(this->name)->equalsIgnoreCase(name);
}

void SignatureFileVerifier::setSignatureFile($bytes* sfBytes) {
	$set(this, sfBytes, sfBytes);
}

bool SignatureFileVerifier::isBlockOrSF($String* s) {
	$init(SignatureFileVerifier);
	bool var$2 = $nc(s)->endsWith(".SF"_s);
	bool var$1 = var$2 || $nc(s)->endsWith(".DSA"_s);
	bool var$0 = var$1 || $nc(s)->endsWith(".RSA"_s);
	return var$0 || $nc(s)->endsWith(".EC"_s);
}

$String* SignatureFileVerifier::getBlockExtension($PrivateKey* key) {
	$init(SignatureFileVerifier);
	$useLocalCurrentObjectStackCache();
	$init($Locale);
	$var($String, keyAlgorithm, $nc($($nc(key)->getAlgorithm()))->toUpperCase($Locale::ENGLISH));
	if (keyAlgorithm->equals("RSASSA-PSS"_s)) {
		return "RSA"_s;
	} else {
		bool var$3 = keyAlgorithm->equals("EDDSA"_s);
		bool var$2 = var$3 || keyAlgorithm->equals("ED25519"_s);
		if (var$2 || keyAlgorithm->equals("ED448"_s)) {
			return "EC"_s;
		} else {
			return keyAlgorithm;
		}
	}
}

bool SignatureFileVerifier::isSigningRelated($String* name$renamed) {
	$init(SignatureFileVerifier);
	$useLocalCurrentObjectStackCache();
	$var($String, name, name$renamed);
	$init($Locale);
	$assign(name, $nc(name)->toUpperCase($Locale::ENGLISH));
	if (!name->startsWith("META-INF/"_s)) {
		return false;
	}
	$assign(name, name->substring(9));
	if (name->indexOf((int32_t)u'/') != -1) {
		return false;
	}
	bool var$0 = isBlockOrSF(name);
	if (var$0 || name->equals("MANIFEST.MF"_s)) {
		return true;
	} else if (name->startsWith("SIG-"_s)) {
		int32_t extIndex = name->lastIndexOf((int32_t)u'.');
		if (extIndex != -1) {
			$var($String, ext, name->substring(extIndex + 1));
			bool var$1 = ext->length() > 3;
			if (var$1 || ext->length() < 1) {
				return false;
			}
			for (int32_t index = 0; index < ext->length(); ++index) {
				char16_t cc = ext->charAt(index);
				if ((cc < u'A' || cc > u'Z') && (cc < u'0' || cc > u'9')) {
					return false;
				}
			}
		}
		return true;
	}
	return false;
}

$MessageDigest* SignatureFileVerifier::getDigest($String* algorithm) {
	if (this->createdDigests == nullptr) {
		$set(this, createdDigests, $new($HashMap));
	}
	$var($MessageDigest, digest, $cast($MessageDigest, $nc(this->createdDigests)->get(algorithm)));
	if (digest == nullptr) {
		try {
			$assign(digest, $MessageDigest::getInstance(algorithm));
			$nc(this->createdDigests)->put(algorithm, digest);
		} catch ($NoSuchAlgorithmException& nsae) {
		}
	}
	return digest;
}

void SignatureFileVerifier::process($Hashtable* signers, $List* manifestDigests, $String* manifestName) {
	$useLocalCurrentObjectStackCache();
	$var($Object, obj, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		try {
			$assign(obj, $Providers::startJarVerification());
			processImpl(signers, manifestDigests, manifestName);
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$Providers::stopJarVerification(obj);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void SignatureFileVerifier::processImpl($Hashtable* signers, $List* manifestDigests, $String* manifestName) {
	$useLocalCurrentObjectStackCache();
	$var($Manifest, sf, $new($Manifest));
	sf->read($$new($ByteArrayInputStream, this->sfBytes));
	$init($Attributes$Name);
	$var($String, version, $nc($(sf->getMainAttributes()))->getValue($Attributes$Name::SIGNATURE_VERSION));
	if ((version == nullptr) || !($nc(version)->equalsIgnoreCase("1.0"_s))) {
		return;
	}
	$var($SignerInfoArray, infos, $nc(this->block)->verify(this->sfBytes));
	if (infos == nullptr) {
		$throwNew($SecurityException, $$str({"cannot verify signature block file "_s, this->name}));
	}
	$var($CodeSignerArray, newSigners, getSigners(infos, this->block));
	if (newSigners == nullptr) {
		return;
	}
	$set(this, params, $new($JarConstraintsParameters, newSigners));
	$var($Set, notDisabledAlgorithms, $SignerInfo::verifyAlgorithms(infos, this->params, $$str({this->name, " PKCS7"_s})));
	{
		$var($Iterator, i$, $nc(notDisabledAlgorithms)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, algorithm, $cast($String, i$->next()));
			{
				$init($Boolean);
				$nc(this->permittedAlgs)->put(algorithm, $Boolean::TRUE);
			}
		}
	}
	$var($Iterator, entries, $nc($($nc($(sf->getEntries()))->entrySet()))->iterator());
	bool manifestSigned = verifyManifestHash(sf, this->md, manifestDigests);
	if (!manifestSigned && !verifyManifestMainAttrs(sf, this->md)) {
		$throwNew($SecurityException, "Invalid signature file digest for Manifest main attributes"_s);
	}
	while ($nc(entries)->hasNext()) {
		$var($Map$Entry, e, $cast($Map$Entry, entries->next()));
		$var($String, name, $cast($String, $nc(e)->getKey()));
		if (manifestSigned || (verifySection($cast($Attributes, $(e->getValue())), name, this->md))) {
			if ($nc(name)->startsWith("./"_s)) {
				$assign(name, name->substring(2));
			}
			if ($nc(name)->startsWith("/"_s)) {
				$assign(name, name->substring(1));
			}
			updateSigners(newSigners, signers, name);
			if (SignatureFileVerifier::debug != nullptr) {
				$nc(SignatureFileVerifier::debug)->println($$str({"processSignature signed name = "_s, name}));
			}
		} else if (SignatureFileVerifier::debug != nullptr) {
			$nc(SignatureFileVerifier::debug)->println($$str({"processSignature unsigned name = "_s, name}));
		}
	}
	updateSigners(newSigners, signers, manifestName);
}

bool SignatureFileVerifier::permittedCheck($String* key, $String* algorithm) {
	$useLocalCurrentObjectStackCache();
	$var($Boolean, permitted, $cast($Boolean, $nc(this->permittedAlgs)->get(algorithm)));
	if (permitted == nullptr) {
		try {
			$nc(this->params)->setExtendedExceptionMsg($$str({this->name, ".SF"_s}), $$str({key, " attribute"_s}));
			$nc($($DisabledAlgorithmConstraints::jarConstraints()))->permits(algorithm, static_cast<$ConstraintsParameters*>(this->params));
		} catch ($GeneralSecurityException& e) {
			$init($Boolean);
			$nc(this->permittedAlgs)->put(algorithm, $Boolean::FALSE);
			$nc(this->permittedAlgs)->put($($nc(key)->toUpperCase()), $Boolean::FALSE);
			if (SignatureFileVerifier::debug != nullptr) {
				if (e->getMessage() != nullptr) {
					$nc(SignatureFileVerifier::debug)->println($$str({key, ":  "_s, $(e->getMessage())}));
				} else {
					$nc(SignatureFileVerifier::debug)->println($$str({"Debug info only. "_s, key, ":  "_s, algorithm, " was disabled, no exception msg given."_s}));
					e->printStackTrace();
				}
			}
			return false;
		}
		$init($Boolean);
		$nc(this->permittedAlgs)->put(algorithm, $Boolean::TRUE);
		return true;
	}
	return $nc(permitted)->booleanValue();
}

$String* SignatureFileVerifier::getWeakAlgorithms($String* header) {
	$useLocalCurrentObjectStackCache();
	$var($String, w, ""_s);
	try {
		{
			$var($Iterator, i$, $nc($($nc(this->permittedAlgs)->keySet()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($String, key, $cast($String, i$->next()));
				{
					if ($nc(key)->endsWith(header)) {
						int32_t var$1 = key->length();
						$var($String, var$0, $(key->substring(0, var$1 - $nc(header)->length())));
						$plusAssign(w, $$concat(var$0, " "_s));
					}
				}
			}
		}
	} catch ($RuntimeException& e) {
		$assign(w, $str({"Unknown Algorithm(s).  Error processing "_s, header, ".  "_s, $(e->getMessage())}));
	}
	if (w->isEmpty()) {
		return "Unknown Algorithm(s)"_s;
	}
	return w;
}

bool SignatureFileVerifier::verifyManifestHash($Manifest* sf, $ManifestDigester* md, $List* manifestDigests) {
	$useLocalCurrentObjectStackCache();
	$var($Attributes, mattr, $nc(sf)->getMainAttributes());
	bool manifestSigned = false;
	bool weakAlgs = true;
	bool validEntry = false;
	{
		$var($Iterator, i$, $nc($($nc(mattr)->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, se, $cast($Map$Entry, i$->next()));
			{
				$var($String, key, $nc($of($($nc(se)->getKey())))->toString());
				$init($Locale);
				if ($($nc(key)->toUpperCase($Locale::ENGLISH))->endsWith("-DIGEST-MANIFEST"_s)) {
					$var($String, algorithm, key->substring(0, key->length() - 16));
					validEntry = true;
					if (!permittedCheck(key, algorithm)) {
						continue;
					}
					weakAlgs = false;
					$nc(manifestDigests)->add(key);
					manifestDigests->add($(se->getValue()));
					$var($MessageDigest, digest, getDigest(algorithm));
					if (digest != nullptr) {
						$var($bytes, computedHash, $nc(md)->manifestDigest(digest));
						$var($bytes, expectedHash, $nc($($Base64::getMimeDecoder()))->decode($cast($String, $(se->getValue()))));
						if (SignatureFileVerifier::debug != nullptr) {
							$nc(SignatureFileVerifier::debug)->println($$str({"Signature File: Manifest digest "_s, algorithm}));
							$nc(SignatureFileVerifier::debug)->println($$str({"  sigfile  "_s, $($nc($($HexFormat::of()))->formatHex(expectedHash))}));
							$nc(SignatureFileVerifier::debug)->println($$str({"  computed "_s, $($nc($($HexFormat::of()))->formatHex(computedHash))}));
							$nc(SignatureFileVerifier::debug)->println();
						}
						if ($MessageDigest::isEqual(computedHash, expectedHash)) {
							manifestSigned = true;
						} else {
						}
					}
				}
			}
		}
	}
	if (SignatureFileVerifier::debug != nullptr) {
		$nc(SignatureFileVerifier::debug)->println("PermittedAlgs mapping: "_s);
		{
			$var($Iterator, i$, $nc($($nc(this->permittedAlgs)->keySet()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($String, key, $cast($String, i$->next()));
				{
					$nc(SignatureFileVerifier::debug)->println($$str({key, " : "_s, $($nc(($cast($Boolean, $($nc(this->permittedAlgs)->get(key)))))->toString())}));
				}
			}
		}
	}
	if (validEntry && weakAlgs) {
		$throwNew($SignatureException, $$str({"Manifest hash check failed (DIGEST-MANIFEST). Disabled algorithm(s) used: "_s, $(getWeakAlgorithms("-DIGEST-MANIFEST"_s))}));
	}
	return manifestSigned;
}

bool SignatureFileVerifier::verifyManifestMainAttrs($Manifest* sf, $ManifestDigester* md) {
	$useLocalCurrentObjectStackCache();
	$var($Attributes, mattr, $nc(sf)->getMainAttributes());
	bool attrsVerified = true;
	bool weakAlgs = true;
	bool validEntry = false;
	{
		$var($Iterator, i$, $nc($($nc(mattr)->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, se, $cast($Map$Entry, i$->next()));
			{
				$var($String, key, $nc($of($($nc(se)->getKey())))->toString());
				$init($Locale);
				if ($($nc(key)->toUpperCase($Locale::ENGLISH))->endsWith(SignatureFileVerifier::ATTR_DIGEST)) {
					int32_t var$0 = key->length();
					$var($String, algorithm, key->substring(0, var$0 - $nc(SignatureFileVerifier::ATTR_DIGEST)->length()));
					validEntry = true;
					if (!permittedCheck(key, algorithm)) {
						continue;
					}
					weakAlgs = false;
					$var($MessageDigest, digest, getDigest(algorithm));
					if (digest != nullptr) {
						$var($ManifestDigester$Entry, mde, $nc(md)->getMainAttsEntry(false));
						$var($bytes, computedHash, $nc(mde)->digest(digest));
						$var($bytes, expectedHash, $nc($($Base64::getMimeDecoder()))->decode($cast($String, $(se->getValue()))));
						if (SignatureFileVerifier::debug != nullptr) {
							$nc(SignatureFileVerifier::debug)->println($$str({"Signature File: Manifest Main Attributes digest "_s, $(digest->getAlgorithm())}));
							$nc(SignatureFileVerifier::debug)->println($$str({"  sigfile  "_s, $($nc($($HexFormat::of()))->formatHex(expectedHash))}));
							$nc(SignatureFileVerifier::debug)->println($$str({"  computed "_s, $($nc($($HexFormat::of()))->formatHex(computedHash))}));
							$nc(SignatureFileVerifier::debug)->println();
						}
						if ($MessageDigest::isEqual(computedHash, expectedHash)) {
						} else {
							attrsVerified = false;
							if (SignatureFileVerifier::debug != nullptr) {
								$nc(SignatureFileVerifier::debug)->println("Verification of Manifest main attributes failed"_s);
								$nc(SignatureFileVerifier::debug)->println();
							}
							break;
						}
					}
				}
			}
		}
	}
	if (SignatureFileVerifier::debug != nullptr) {
		$nc(SignatureFileVerifier::debug)->println("PermittedAlgs mapping: "_s);
		{
			$var($Iterator, i$, $nc($($nc(this->permittedAlgs)->keySet()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($String, key, $cast($String, i$->next()));
				{
					$nc(SignatureFileVerifier::debug)->println($$str({key, " : "_s, $($nc(($cast($Boolean, $($nc(this->permittedAlgs)->get(key)))))->toString())}));
				}
			}
		}
	}
	if (validEntry && weakAlgs) {
		$throwNew($SignatureException, $$str({"Manifest Main Attribute check failed ("_s, SignatureFileVerifier::ATTR_DIGEST, ").  Disabled algorithm(s) used: "_s, $(getWeakAlgorithms(SignatureFileVerifier::ATTR_DIGEST))}));
	}
	return attrsVerified;
}

bool SignatureFileVerifier::verifySection($Attributes* sfAttr, $String* name, $ManifestDigester* md) {
	$useLocalCurrentObjectStackCache();
	bool oneDigestVerified = false;
	$var($ManifestDigester$Entry, mde, $nc(md)->get(name, $nc(this->block)->isOldStyle()));
	bool weakAlgs = true;
	bool validEntry = false;
	if (mde == nullptr) {
		$throwNew($SecurityException, $$str({"no manifest section for signature file entry "_s, name}));
	}
	if (sfAttr != nullptr) {
		{
			$var($Iterator, i$, $nc($(sfAttr->entrySet()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Map$Entry, se, $cast($Map$Entry, i$->next()));
				{
					$var($String, key, $nc($of($($nc(se)->getKey())))->toString());
					$init($Locale);
					if ($($nc(key)->toUpperCase($Locale::ENGLISH))->endsWith("-DIGEST"_s)) {
						$var($String, algorithm, key->substring(0, key->length() - 7));
						validEntry = true;
						if (!permittedCheck(key, algorithm)) {
							continue;
						}
						weakAlgs = false;
						$var($MessageDigest, digest, getDigest(algorithm));
						if (digest != nullptr) {
							bool ok = false;
							$var($bytes, expected, $nc($($Base64::getMimeDecoder()))->decode($cast($String, $(se->getValue()))));
							$var($bytes, computed, nullptr);
							if (this->workaround) {
								$assign(computed, $nc(mde)->digestWorkaround(digest));
							} else {
								$assign(computed, $nc(mde)->digest(digest));
							}
							if (SignatureFileVerifier::debug != nullptr) {
								$nc(SignatureFileVerifier::debug)->println($$str({"Signature Block File: "_s, name, " digest="_s, $(digest->getAlgorithm())}));
								$nc(SignatureFileVerifier::debug)->println($$str({"  expected "_s, $($nc($($HexFormat::of()))->formatHex(expected))}));
								$nc(SignatureFileVerifier::debug)->println($$str({"  computed "_s, $($nc($($HexFormat::of()))->formatHex(computed))}));
								$nc(SignatureFileVerifier::debug)->println();
							}
							if ($MessageDigest::isEqual(computed, expected)) {
								oneDigestVerified = true;
								ok = true;
							} else if (!this->workaround) {
								$assign(computed, $nc(mde)->digestWorkaround(digest));
								if ($MessageDigest::isEqual(computed, expected)) {
									if (SignatureFileVerifier::debug != nullptr) {
										$nc(SignatureFileVerifier::debug)->println($$str({"  re-computed "_s, $($nc($($HexFormat::of()))->formatHex(computed))}));
										$nc(SignatureFileVerifier::debug)->println();
									}
									this->workaround = true;
									oneDigestVerified = true;
									ok = true;
								}
							}
							if (!ok) {
								$throwNew($SecurityException, $$str({"invalid "_s, $(digest->getAlgorithm()), " signature file digest for "_s, name}));
							}
						}
					}
				}
			}
		}
	}
	if (SignatureFileVerifier::debug != nullptr) {
		$nc(SignatureFileVerifier::debug)->println("PermittedAlgs mapping: "_s);
		{
			$var($Iterator, i$, $nc($($nc(this->permittedAlgs)->keySet()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($String, key, $cast($String, i$->next()));
				{
					$nc(SignatureFileVerifier::debug)->println($$str({key, " : "_s, $($nc(($cast($Boolean, $($nc(this->permittedAlgs)->get(key)))))->toString())}));
				}
			}
		}
	}
	if (validEntry && weakAlgs) {
		$throwNew($SignatureException, $$str({"Manifest Main Attribute check failed (DIGEST).  Disabled algorithm(s) used: "_s, $(getWeakAlgorithms("DIGEST"_s))}));
	}
	return oneDigestVerified;
}

$CodeSignerArray* SignatureFileVerifier::getSigners($SignerInfoArray* infos, $PKCS7* block) {
	$useLocalCurrentObjectStackCache();
	$var($ArrayList, signers, nullptr);
	for (int32_t i = 0; i < $nc(infos)->length; ++i) {
		$var($SignerInfo, info, infos->get(i));
		$var($ArrayList, chain, $nc(info)->getCertificateChain(block));
		$var($CertPath, certChain, $nc(this->certificateFactory)->generateCertPath(static_cast<$List*>(chain)));
		if (signers == nullptr) {
			$assign(signers, $new($ArrayList));
		}
		$nc(signers)->add($$new($CodeSigner, certChain, $(info->getTimestamp())));
		if (SignatureFileVerifier::debug != nullptr) {
			$nc(SignatureFileVerifier::debug)->println($$str({"Signature Block Certificate: "_s, $($nc(chain)->get(0))}));
		}
	}
	if (signers != nullptr) {
		return $fcast($CodeSignerArray, signers->toArray($$new($CodeSignerArray, signers->size())));
	} else {
		return nullptr;
	}
}

bool SignatureFileVerifier::contains($CodeSignerArray* set, $CodeSigner* signer) {
	$init(SignatureFileVerifier);
	for (int32_t i = 0; i < $nc(set)->length; ++i) {
		if ($nc(set->get(i))->equals(signer)) {
			return true;
		}
	}
	return false;
}

bool SignatureFileVerifier::isSubSet($CodeSignerArray* subset, $CodeSignerArray* set) {
	$init(SignatureFileVerifier);
	if (set == subset) {
		return true;
	}
	bool match = false;
	for (int32_t i = 0; i < $nc(subset)->length; ++i) {
		if (!contains(set, subset->get(i))) {
			return false;
		}
	}
	return true;
}

bool SignatureFileVerifier::matches($CodeSignerArray* signers, $CodeSignerArray* oldSigners, $CodeSignerArray* newSigners) {
	$init(SignatureFileVerifier);
	if ((oldSigners == nullptr) && (signers == newSigners)) {
		return true;
	}
	bool match = false;
	if ((oldSigners != nullptr) && !isSubSet(oldSigners, signers)) {
		return false;
	}
	if (!isSubSet(newSigners, signers)) {
		return false;
	}
	for (int32_t i = 0; i < $nc(signers)->length; ++i) {
		bool var$0 = ((oldSigners != nullptr) && contains(oldSigners, signers->get(i)));
		bool found = var$0 || contains(newSigners, signers->get(i));
		if (!found) {
			return false;
		}
	}
	return true;
}

void SignatureFileVerifier::updateSigners($CodeSignerArray* newSigners, $Hashtable* signers, $String* name) {
	$useLocalCurrentObjectStackCache();
	$var($CodeSignerArray, oldSigners, $cast($CodeSignerArray, $nc(signers)->get(name)));
	$var($CodeSignerArray, cachedSigners, nullptr);
	for (int32_t i = $nc(this->signerCache)->size() - 1; i != -1; --i) {
		$assign(cachedSigners, $cast($CodeSignerArray, $nc(this->signerCache)->get(i)));
		if (matches(cachedSigners, oldSigners, newSigners)) {
			signers->put(name, cachedSigners);
			return;
		}
	}
	if (oldSigners == nullptr) {
		$assign(cachedSigners, newSigners);
	} else {
		$assign(cachedSigners, $new($CodeSignerArray, $nc(oldSigners)->length + $nc(newSigners)->length));
		$System::arraycopy(oldSigners, 0, cachedSigners, 0, oldSigners->length);
		$System::arraycopy(newSigners, 0, cachedSigners, oldSigners->length, newSigners->length);
	}
	$nc(this->signerCache)->add(cachedSigners);
	signers->put(name, cachedSigners);
}

void clinit$SignatureFileVerifier($Class* class$) {
	$assignStatic(SignatureFileVerifier::debug, $Debug::getInstance("jar"_s));
	$init($ManifestDigester);
	$init($Locale);
	$assignStatic(SignatureFileVerifier::ATTR_DIGEST, $str({"-DIGEST-"_s, $($nc($ManifestDigester::MF_MAIN_ATTRS)->toUpperCase($Locale::ENGLISH))}));
}

SignatureFileVerifier::SignatureFileVerifier() {
}

$Class* SignatureFileVerifier::load$($String* name, bool initialize) {
	$loadClass(SignatureFileVerifier, name, initialize, &_SignatureFileVerifier_ClassInfo_, clinit$SignatureFileVerifier, allocate$SignatureFileVerifier);
	return class$;
}

$Class* SignatureFileVerifier::class$ = nullptr;

		} // util
	} // security
} // sun