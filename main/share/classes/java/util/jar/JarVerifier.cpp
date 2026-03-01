#include <java/util/jar/JarVerifier.h>

#include <java/io/ByteArrayOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/net/URL.h>
#include <java/security/CodeSigner.h>
#include <java/security/CodeSource.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/SignatureException.h>
#include <java/security/cert/CertPath.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/CertificateException.h>
#include <java/util/AbstractCollection.h>
#include <java/util/AbstractSet.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Enumeration.h>
#include <java/util/HashMap.h>
#include <java/util/HashSet.h>
#include <java/util/Hashtable.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/jar/JarEntry.h>
#include <java/util/jar/JarFile.h>
#include <java/util/jar/JarVerifier$1.h>
#include <java/util/jar/JarVerifier$2.h>
#include <java/util/jar/JarVerifier$3.h>
#include <java/util/jar/JarVerifier$VerifierCodeSource.h>
#include <java/util/zip/ZipEntry.h>
#include <jdk/internal/util/jar/JarIndex.h>
#include <sun/security/util/Debug.h>
#include <sun/security/util/ManifestDigester.h>
#include <sun/security/util/ManifestEntryVerifier.h>
#include <sun/security/util/SignatureFileVerifier.h>
#include <jcpp.h>

#undef ENGLISH
#undef INDEX_NAME
#undef MANIFEST_NAME

using $CodeSignerArray = $Array<::java::security::CodeSigner>;
using $CodeSourceArray = $Array<::java::security::CodeSource>;
using $CertificateArray = $Array<::java::security::cert::Certificate>;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $URL = ::java::net::URL;
using $CodeSigner = ::java::security::CodeSigner;
using $CodeSource = ::java::security::CodeSource;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $SignatureException = ::java::security::SignatureException;
using $CertPath = ::java::security::cert::CertPath;
using $CertificateException = ::java::security::cert::CertificateException;
using $AbstractCollection = ::java::util::AbstractCollection;
using $AbstractSet = ::java::util::AbstractSet;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Enumeration = ::java::util::Enumeration;
using $HashMap = ::java::util::HashMap;
using $HashSet = ::java::util::HashSet;
using $Hashtable = ::java::util::Hashtable;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $JarEntry = ::java::util::jar::JarEntry;
using $JarFile = ::java::util::jar::JarFile;
using $JarVerifier$1 = ::java::util::jar::JarVerifier$1;
using $JarVerifier$2 = ::java::util::jar::JarVerifier$2;
using $JarVerifier$3 = ::java::util::jar::JarVerifier$3;
using $JarVerifier$VerifierCodeSource = ::java::util::jar::JarVerifier$VerifierCodeSource;
using $ZipEntry = ::java::util::zip::ZipEntry;
using $JarIndex = ::jdk::internal::util::jar::JarIndex;
using $Debug = ::sun::security::util::Debug;
using $ManifestDigester = ::sun::security::util::ManifestDigester;
using $ManifestEntryVerifier = ::sun::security::util::ManifestEntryVerifier;
using $SignatureFileVerifier = ::sun::security::util::SignatureFileVerifier;

namespace java {
	namespace util {
		namespace jar {

$CompoundAttribute _JarVerifier_MethodAnnotations_getCerts6[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _JarVerifier_FieldInfo_[] = {
	{"debug", "Lsun/security/util/Debug;", nullptr, $STATIC | $FINAL, $staticField(JarVerifier, debug)},
	{"verifiedSigners", "Ljava/util/Hashtable;", "Ljava/util/Hashtable<Ljava/lang/String;[Ljava/security/CodeSigner;>;", $PRIVATE, $field(JarVerifier, verifiedSigners)},
	{"sigFileSigners", "Ljava/util/Hashtable;", "Ljava/util/Hashtable<Ljava/lang/String;[Ljava/security/CodeSigner;>;", $PRIVATE, $field(JarVerifier, sigFileSigners)},
	{"sigFileData", "Ljava/util/Hashtable;", "Ljava/util/Hashtable<Ljava/lang/String;[B>;", $PRIVATE, $field(JarVerifier, sigFileData)},
	{"pendingBlocks", "Ljava/util/ArrayList;", "Ljava/util/ArrayList<Lsun/security/util/SignatureFileVerifier;>;", $PRIVATE, $field(JarVerifier, pendingBlocks)},
	{"signerCache", "Ljava/util/ArrayList;", "Ljava/util/ArrayList<[Ljava/security/CodeSigner;>;", $PRIVATE, $field(JarVerifier, signerCache)},
	{"parsingBlockOrSF", "Z", nullptr, $PRIVATE, $field(JarVerifier, parsingBlockOrSF)},
	{"parsingMeta", "Z", nullptr, $PRIVATE, $field(JarVerifier, parsingMeta)},
	{"anyToVerify", "Z", nullptr, $PRIVATE, $field(JarVerifier, anyToVerify)},
	{"baos", "Ljava/io/ByteArrayOutputStream;", nullptr, $PRIVATE, $field(JarVerifier, baos)},
	{"manDig", "Lsun/security/util/ManifestDigester;", nullptr, $PRIVATE | $VOLATILE, $field(JarVerifier, manDig)},
	{"manifestRawBytes", "[B", nullptr, 0, $field(JarVerifier, manifestRawBytes)},
	{"manifestName", "Ljava/lang/String;", nullptr, $FINAL, $field(JarVerifier, manifestName)},
	{"eagerValidation", "Z", nullptr, 0, $field(JarVerifier, eagerValidation)},
	{"csdomain", "Ljava/lang/Object;", nullptr, $PRIVATE, $field(JarVerifier, csdomain)},
	{"manifestDigests", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/Object;>;", $PRIVATE, $field(JarVerifier, manifestDigests)},
	{"urlToCodeSourceMap", "Ljava/util/Map;", "Ljava/util/Map<Ljava/net/URL;Ljava/util/Map<[Ljava/security/CodeSigner;Ljava/security/CodeSource;>;>;", $PRIVATE, $field(JarVerifier, urlToCodeSourceMap)},
	{"signerToCodeSource", "Ljava/util/Map;", "Ljava/util/Map<[Ljava/security/CodeSigner;Ljava/security/CodeSource;>;", $PRIVATE, $field(JarVerifier, signerToCodeSource)},
	{"lastURL", "Ljava/net/URL;", nullptr, $PRIVATE, $field(JarVerifier, lastURL)},
	{"lastURLMap", "Ljava/util/Map;", "Ljava/util/Map<[Ljava/security/CodeSigner;Ljava/security/CodeSource;>;", $PRIVATE, $field(JarVerifier, lastURLMap)},
	{"emptySigner", "[Ljava/security/CodeSigner;", nullptr, $PRIVATE, $field(JarVerifier, emptySigner)},
	{"signerMap", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;[Ljava/security/CodeSigner;>;", $PRIVATE, $field(JarVerifier, signerMap$)},
	{"jarCodeSigners", "Ljava/util/List;", "Ljava/util/List<[Ljava/security/CodeSigner;>;", $PRIVATE, $field(JarVerifier, jarCodeSigners)},
	{}
};

$MethodInfo _JarVerifier_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;[B)V", nullptr, $PUBLIC, $method(JarVerifier, init$, void, $String*, $bytes*)},
	{"beginEntry", "(Ljava/util/jar/JarEntry;Lsun/security/util/ManifestEntryVerifier;)V", nullptr, $PUBLIC, $virtualMethod(JarVerifier, beginEntry, void, $JarEntry*, $ManifestEntryVerifier*), "java.io.IOException"},
	{"doneWithMeta", "()V", nullptr, 0, $virtualMethod(JarVerifier, doneWithMeta, void)},
	{"entries2", "(Ljava/util/jar/JarFile;Ljava/util/Enumeration;)Ljava/util/Enumeration;", "(Ljava/util/jar/JarFile;Ljava/util/Enumeration<Ljava/util/jar/JarEntry;>;)Ljava/util/Enumeration<Ljava/util/jar/JarEntry;>;", $PUBLIC, $virtualMethod(JarVerifier, entries2, $Enumeration*, $JarFile*, $Enumeration*)},
	{"entryNames", "(Ljava/util/jar/JarFile;[Ljava/security/CodeSource;)Ljava/util/Enumeration;", "(Ljava/util/jar/JarFile;[Ljava/security/CodeSource;)Ljava/util/Enumeration<Ljava/lang/String;>;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(JarVerifier, entryNames, $Enumeration*, $JarFile*, $CodeSourceArray*)},
	{"findMatchingSigners", "(Ljava/security/CodeSource;)[Ljava/security/CodeSigner;", nullptr, $PRIVATE, $method(JarVerifier, findMatchingSigners, $CodeSignerArray*, $CodeSource*)},
	{"getCerts", "(Ljava/lang/String;)[Ljava/security/cert/Certificate;", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(JarVerifier, getCerts, $CertificateArray*, $String*), nullptr, nullptr, _JarVerifier_MethodAnnotations_getCerts6},
	{"getCerts", "(Ljava/util/jar/JarFile;Ljava/util/jar/JarEntry;)[Ljava/security/cert/Certificate;", nullptr, $PUBLIC, $virtualMethod(JarVerifier, getCerts, $CertificateArray*, $JarFile*, $JarEntry*)},
	{"getCodeSigners", "(Ljava/lang/String;)[Ljava/security/CodeSigner;", nullptr, $PUBLIC, $virtualMethod(JarVerifier, getCodeSigners, $CodeSignerArray*, $String*)},
	{"getCodeSigners", "(Ljava/util/jar/JarFile;Ljava/util/jar/JarEntry;)[Ljava/security/CodeSigner;", nullptr, $PUBLIC, $virtualMethod(JarVerifier, getCodeSigners, $CodeSignerArray*, $JarFile*, $JarEntry*)},
	{"getCodeSource", "(Ljava/net/URL;Ljava/lang/String;)Ljava/security/CodeSource;", nullptr, $PUBLIC, $virtualMethod(JarVerifier, getCodeSource, $CodeSource*, $URL*, $String*)},
	{"getCodeSource", "(Ljava/net/URL;Ljava/util/jar/JarFile;Ljava/util/jar/JarEntry;)Ljava/security/CodeSource;", nullptr, $PUBLIC, $virtualMethod(JarVerifier, getCodeSource, $CodeSource*, $URL*, $JarFile*, $JarEntry*)},
	{"getCodeSources", "(Ljava/util/jar/JarFile;Ljava/net/URL;)[Ljava/security/CodeSource;", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(JarVerifier, getCodeSources, $CodeSourceArray*, $JarFile*, $URL*)},
	{"getJarCodeSigners", "()Ljava/util/List;", "()Ljava/util/List<[Ljava/security/CodeSigner;>;", $PRIVATE | $SYNCHRONIZED, $method(JarVerifier, getJarCodeSigners, $List*)},
	{"getManifestDigests", "()Ljava/util/List;", "()Ljava/util/List<Ljava/lang/Object;>;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(JarVerifier, getManifestDigests, $List*)},
	{"getUnsignedCS", "(Ljava/net/URL;)Ljava/security/CodeSource;", nullptr, $STATIC, $staticMethod(JarVerifier, getUnsignedCS, $CodeSource*, $URL*)},
	{"isSigningRelated", "(Ljava/lang/String;)Z", nullptr, $STATIC, $staticMethod(JarVerifier, isSigningRelated, bool, $String*)},
	{"isTrustedManifestEntry", "(Ljava/lang/String;)Z", nullptr, 0, $virtualMethod(JarVerifier, isTrustedManifestEntry, bool, $String*)},
	{"mapSignersToCertArray", "([Ljava/security/CodeSigner;)[Ljava/security/cert/Certificate;", nullptr, $PRIVATE | $STATIC, $staticMethod(JarVerifier, mapSignersToCertArray, $CertificateArray*, $CodeSignerArray*)},
	{"mapSignersToCodeSource", "(Ljava/net/URL;[Ljava/security/CodeSigner;)Ljava/security/CodeSource;", nullptr, $PRIVATE | $SYNCHRONIZED, $method(JarVerifier, mapSignersToCodeSource, $CodeSource*, $URL*, $CodeSignerArray*)},
	{"mapSignersToCodeSources", "(Ljava/net/URL;Ljava/util/List;Z)[Ljava/security/CodeSource;", "(Ljava/net/URL;Ljava/util/List<[Ljava/security/CodeSigner;>;Z)[Ljava/security/CodeSource;", $PRIVATE, $method(JarVerifier, mapSignersToCodeSources, $CodeSourceArray*, $URL*, $List*, bool)},
	{"nothingToVerify", "()Z", nullptr, 0, $virtualMethod(JarVerifier, nothingToVerify, bool)},
	{"processEntry", "(Lsun/security/util/ManifestEntryVerifier;)V", nullptr, $PRIVATE, $method(JarVerifier, processEntry, void, $ManifestEntryVerifier*), "java.io.IOException"},
	{"setEagerValidation", "(Z)V", nullptr, $PUBLIC, $virtualMethod(JarVerifier, setEagerValidation, void, bool)},
	{"signerMap", "()Ljava/util/Map;", "()Ljava/util/Map<Ljava/lang/String;[Ljava/security/CodeSigner;>;", $PRIVATE | $SYNCHRONIZED, $method(JarVerifier, signerMap, $Map*)},
	{"unsignedEntryNames", "(Ljava/util/jar/JarFile;)Ljava/util/Enumeration;", "(Ljava/util/jar/JarFile;)Ljava/util/Enumeration<Ljava/lang/String;>;", $PRIVATE, $method(JarVerifier, unsignedEntryNames, $Enumeration*, $JarFile*)},
	{"update", "(ILsun/security/util/ManifestEntryVerifier;)V", nullptr, $PUBLIC, $virtualMethod(JarVerifier, update, void, int32_t, $ManifestEntryVerifier*), "java.io.IOException"},
	{"update", "(I[BIILsun/security/util/ManifestEntryVerifier;)V", nullptr, $PUBLIC, $virtualMethod(JarVerifier, update, void, int32_t, $bytes*, int32_t, int32_t, $ManifestEntryVerifier*), "java.io.IOException"},
	{}
};

$InnerClassInfo _JarVerifier_InnerClassesInfo_[] = {
	{"java.util.jar.JarVerifier$VerifierCodeSource", "java.util.jar.JarVerifier", "VerifierCodeSource", $PRIVATE | $STATIC},
	{"java.util.jar.JarVerifier$VerifierStream", "java.util.jar.JarVerifier", "VerifierStream", $STATIC},
	{"java.util.jar.JarVerifier$3", nullptr, nullptr, 0},
	{"java.util.jar.JarVerifier$2", nullptr, nullptr, 0},
	{"java.util.jar.JarVerifier$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _JarVerifier_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.jar.JarVerifier",
	"java.lang.Object",
	nullptr,
	_JarVerifier_FieldInfo_,
	_JarVerifier_MethodInfo_,
	nullptr,
	nullptr,
	_JarVerifier_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.jar.JarVerifier$VerifierCodeSource,java.util.jar.JarVerifier$VerifierStream,java.util.jar.JarVerifier$3,java.util.jar.JarVerifier$2,java.util.jar.JarVerifier$1"
};

$Object* allocate$JarVerifier($Class* clazz) {
	return $of($alloc(JarVerifier));
}

$Debug* JarVerifier::debug = nullptr;

void JarVerifier::init$($String* name, $bytes* rawBytes) {
	this->parsingBlockOrSF = false;
	this->parsingMeta = true;
	this->anyToVerify = true;
	$set(this, manifestRawBytes, nullptr);
	$set(this, csdomain, $new($Object));
	$set(this, urlToCodeSourceMap, $new($HashMap));
	$set(this, signerToCodeSource, $new($HashMap));
	$set(this, emptySigner, $new($CodeSignerArray, 0));
	$set(this, manifestName, name);
	$set(this, manifestRawBytes, rawBytes);
	$set(this, sigFileSigners, $new($Hashtable));
	$set(this, verifiedSigners, $new($Hashtable));
	$set(this, sigFileData, $new($Hashtable, 11));
	$set(this, pendingBlocks, $new($ArrayList));
	$set(this, baos, $new($ByteArrayOutputStream));
	$set(this, manifestDigests, $new($ArrayList));
}

void JarVerifier::beginEntry($JarEntry* je, $ManifestEntryVerifier* mev) {
	$useLocalCurrentObjectStackCache();
	if (je == nullptr) {
		return;
	}
	if (JarVerifier::debug != nullptr) {
		$nc(JarVerifier::debug)->println($$str({"beginEntry "_s, $($nc(je)->getName())}));
	}
	$var($String, name, $nc(je)->getName());
	if (this->parsingMeta) {
		$init($Locale);
		$var($String, uname, $nc(name)->toUpperCase($Locale::ENGLISH));
		bool var$0 = uname->startsWith("META-INF/"_s);
		if (var$0 || uname->startsWith("/META-INF/"_s)) {
			if (je->isDirectory()) {
				$nc(mev)->setEntry(nullptr, je);
				return;
			}
			$init($JarFile);
			bool var$1 = uname->equals($JarFile::MANIFEST_NAME);
			$init($JarIndex);
			if (var$1 || uname->equals($JarIndex::INDEX_NAME)) {
				return;
			}
			if ($SignatureFileVerifier::isBlockOrSF(uname)) {
				this->parsingBlockOrSF = true;
				$nc(this->baos)->reset();
				$nc(mev)->setEntry(nullptr, je);
				return;
			}
		}
	}
	if (this->parsingMeta) {
		doneWithMeta();
	}
	if (je->isDirectory()) {
		$nc(mev)->setEntry(nullptr, je);
		return;
	}
	if ($nc(name)->startsWith("./"_s)) {
		$assign(name, name->substring(2));
	}
	if ($nc(name)->startsWith("/"_s)) {
		$assign(name, name->substring(1));
	}
	$init($JarFile);
	if (!$nc(name)->equalsIgnoreCase($JarFile::MANIFEST_NAME)) {
		bool var$2 = $nc(this->sigFileSigners)->get(name) != nullptr;
		if (var$2 || $nc(this->verifiedSigners)->get(name) != nullptr) {
			$nc(mev)->setEntry(name, je);
			return;
		}
	}
	$nc(mev)->setEntry(nullptr, je);
	return;
}

void JarVerifier::update(int32_t b, $ManifestEntryVerifier* mev) {
	if (b != -1) {
		if (this->parsingBlockOrSF) {
			$nc(this->baos)->write(b);
		} else {
			$nc(mev)->update((int8_t)b);
		}
	} else {
		processEntry(mev);
	}
}

void JarVerifier::update(int32_t n, $bytes* b, int32_t off, int32_t len, $ManifestEntryVerifier* mev) {
	if (n != -1) {
		if (this->parsingBlockOrSF) {
			$nc(this->baos)->write(b, off, n);
		} else {
			$nc(mev)->update(b, off, n);
		}
	} else {
		processEntry(mev);
	}
}

void JarVerifier::processEntry($ManifestEntryVerifier* mev) {
	$useLocalCurrentObjectStackCache();
	if (!this->parsingBlockOrSF) {
		$var($JarEntry, je, $nc(mev)->getEntry());
		if ((je != nullptr) && (je->signers == nullptr)) {
			$set(je, signers, mev->verify(this->verifiedSigners, this->sigFileSigners));
			$set(je, certs, mapSignersToCertArray(je->signers));
		}
	} else {
		try {
			this->parsingBlockOrSF = false;
			if (JarVerifier::debug != nullptr) {
				$nc(JarVerifier::debug)->println("processEntry: processing block"_s);
			}
			$init($Locale);
			$var($String, uname, $nc($($nc($($nc(mev)->getEntry()))->getName()))->toUpperCase($Locale::ENGLISH));
			if (uname->endsWith(".SF"_s)) {
				$var($String, key, uname->substring(0, uname->length() - 3));
				$var($bytes, bytes, $nc(this->baos)->toByteArray());
				$nc(this->sigFileData)->put(key, bytes);
				{
					$var($Iterator, i$, $nc(this->pendingBlocks)->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($SignatureFileVerifier, sfv, $cast($SignatureFileVerifier, i$->next()));
						{
							if ($nc(sfv)->needSignatureFile(key)) {
								if (JarVerifier::debug != nullptr) {
									$nc(JarVerifier::debug)->println("processEntry: processing pending block"_s);
								}
								sfv->setSignatureFile(bytes);
								sfv->process(this->sigFileSigners, this->manifestDigests, this->manifestName);
							}
						}
					}
				}
				return;
			}
			$var($String, key, uname->substring(0, uname->lastIndexOf((int32_t)u'.')));
			if (this->signerCache == nullptr) {
				$set(this, signerCache, $new($ArrayList));
			}
			if (this->manDig == nullptr) {
				$synchronized(this->manifestRawBytes) {
					if (this->manDig == nullptr) {
						$set(this, manDig, $new($ManifestDigester, this->manifestRawBytes));
						$set(this, manifestRawBytes, nullptr);
					}
				}
			}
			$var($SignatureFileVerifier, sfv, $new($SignatureFileVerifier, this->signerCache, this->manDig, uname, $($nc(this->baos)->toByteArray())));
			if (sfv->needSignatureFileBytes()) {
				$var($bytes, bytes, $cast($bytes, $nc(this->sigFileData)->get(key)));
				if (bytes == nullptr) {
					if (JarVerifier::debug != nullptr) {
						$nc(JarVerifier::debug)->println("adding pending block"_s);
					}
					$nc(this->pendingBlocks)->add(sfv);
					return;
				} else {
					sfv->setSignatureFile(bytes);
				}
			}
			sfv->process(this->sigFileSigners, this->manifestDigests, this->manifestName);
		} catch ($IOException& e) {
			if (JarVerifier::debug != nullptr) {
				$nc(JarVerifier::debug)->println($$str({"processEntry caught: "_s, e}));
			}
		} catch ($CertificateException& e) {
			if (JarVerifier::debug != nullptr) {
				$nc(JarVerifier::debug)->println($$str({"processEntry caught: "_s, e}));
			}
		} catch ($NoSuchAlgorithmException& e) {
			if (JarVerifier::debug != nullptr) {
				$nc(JarVerifier::debug)->println($$str({"processEntry caught: "_s, e}));
			}
		} catch ($SignatureException& e) {
			if (JarVerifier::debug != nullptr) {
				$nc(JarVerifier::debug)->println($$str({"processEntry caught: "_s, e}));
			}
		}
	}
}

$CertificateArray* JarVerifier::getCerts($String* name) {
	return mapSignersToCertArray($(getCodeSigners(name)));
}

$CertificateArray* JarVerifier::getCerts($JarFile* jar, $JarEntry* entry) {
	return mapSignersToCertArray($(getCodeSigners(jar, entry)));
}

$CodeSignerArray* JarVerifier::getCodeSigners($String* name) {
	return $cast($CodeSignerArray, $nc(this->verifiedSigners)->get(name));
}

$CodeSignerArray* JarVerifier::getCodeSigners($JarFile* jar, $JarEntry* entry) {
	$useLocalCurrentObjectStackCache();
	$var($String, name, $nc(entry)->getName());
	if (this->eagerValidation && $nc(this->sigFileSigners)->get(name) != nullptr) {
		try {
			$var($InputStream, s, $nc(jar)->getInputStream(entry));
			$var($bytes, buffer, $new($bytes, 1024));
			int32_t n = buffer->length;
			while (n != -1) {
				n = $nc(s)->read(buffer, 0, buffer->length);
			}
			$nc(s)->close();
		} catch ($IOException& e) {
		}
	}
	return getCodeSigners(name);
}

$CertificateArray* JarVerifier::mapSignersToCertArray($CodeSignerArray* signers) {
	$init(JarVerifier);
	$useLocalCurrentObjectStackCache();
	if (signers != nullptr) {
		$var($ArrayList, certChains, $new($ArrayList));
		{
			$var($CodeSignerArray, arr$, signers);
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($CodeSigner, signer, arr$->get(i$));
				{
					certChains->addAll($($nc($($nc(signer)->getSignerCertPath()))->getCertificates()));
				}
			}
		}
		return $fcast($CertificateArray, certChains->toArray($$new($CertificateArray, certChains->size())));
	}
	return nullptr;
}

bool JarVerifier::nothingToVerify() {
	return (this->anyToVerify == false);
}

void JarVerifier::doneWithMeta() {
	this->parsingMeta = false;
	this->anyToVerify = !$nc(this->sigFileSigners)->isEmpty();
	$set(this, baos, nullptr);
	$set(this, sigFileData, nullptr);
	$set(this, pendingBlocks, nullptr);
	$set(this, signerCache, nullptr);
	$set(this, manDig, nullptr);
	if ($nc(this->sigFileSigners)->containsKey(this->manifestName)) {
		$var($CodeSignerArray, codeSigners, $cast($CodeSignerArray, $nc(this->sigFileSigners)->remove(this->manifestName)));
		$nc(this->verifiedSigners)->put(this->manifestName, codeSigners);
	}
}

$CodeSource* JarVerifier::mapSignersToCodeSource($URL* url, $CodeSignerArray* signers) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$var($Map, map, nullptr);
		if (url == this->lastURL) {
			$assign(map, this->lastURLMap);
		} else {
			$assign(map, $cast($Map, $nc(this->urlToCodeSourceMap)->get(url)));
			if (map == nullptr) {
				$assign(map, $new($HashMap));
				$nc(this->urlToCodeSourceMap)->put(url, map);
			}
			$set(this, lastURLMap, map);
			$set(this, lastURL, url);
		}
		$var($CodeSource, cs, $cast($CodeSource, $nc(map)->get(signers)));
		if (cs == nullptr) {
			$assign(cs, $new($JarVerifier$VerifierCodeSource, this->csdomain, url, signers));
			$nc(this->signerToCodeSource)->put(signers, cs);
		}
		return cs;
	}
}

$CodeSourceArray* JarVerifier::mapSignersToCodeSources($URL* url, $List* signers, bool unsigned$) {
	$useLocalCurrentObjectStackCache();
	$var($List, sources, $new($ArrayList));
	{
		$var($Iterator, i$, $nc(signers)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($CodeSignerArray, signer, $cast($CodeSignerArray, i$->next()));
			{
				sources->add($(mapSignersToCodeSource(url, signer)));
			}
		}
	}
	if (unsigned$) {
		sources->add($(mapSignersToCodeSource(url, nullptr)));
	}
	return $fcast($CodeSourceArray, sources->toArray($$new($CodeSourceArray, sources->size())));
}

$CodeSignerArray* JarVerifier::findMatchingSigners($CodeSource* cs) {
	$useLocalCurrentObjectStackCache();
	{
		$var($JarVerifier$VerifierCodeSource, vcs, nullptr);
		bool var$0 = $instanceOf($JarVerifier$VerifierCodeSource, cs);
		if (var$0) {
			$assign(vcs, $cast($JarVerifier$VerifierCodeSource, cs));
			var$0 = true;
		}
		if (var$0) {
			if ($nc(vcs)->isSameDomain(this->csdomain)) {
				return vcs->getPrivateSigners();
			}
		}
	}
	$var($URL, var$1, $nc(cs)->getLocation());
	$var($CodeSourceArray, sources, mapSignersToCodeSources(var$1, $(getJarCodeSigners()), true));
	$var($List, sourceList, $new($ArrayList));
	{
		$var($CodeSourceArray, arr$, sources);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($CodeSource, source, arr$->get(i$));
			{
				sourceList->add(source);
			}
		}
	}
	int32_t j = sourceList->indexOf(cs);
	if (j != -1) {
		$var($CodeSignerArray, match, nullptr);
		$assign(match, $nc(($cast($JarVerifier$VerifierCodeSource, $(sourceList->get(j)))))->getPrivateSigners());
		if (match == nullptr) {
			$assign(match, this->emptySigner);
		}
		return match;
	}
	return nullptr;
}

$Map* JarVerifier::signerMap() {
	$synchronized(this) {
		if (this->signerMap$ == nullptr) {
			int32_t var$0 = $nc(this->verifiedSigners)->size();
			$set(this, signerMap$, $new($HashMap, var$0 + $nc(this->sigFileSigners)->size()));
			$nc(this->signerMap$)->putAll(this->verifiedSigners);
			$nc(this->signerMap$)->putAll(this->sigFileSigners);
		}
		return this->signerMap$;
	}
}

$Enumeration* JarVerifier::entryNames($JarFile* jar, $CodeSourceArray* cs) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$var($Map, map, signerMap());
		$var($Iterator, itor, $nc($($nc(map)->entrySet()))->iterator());
		bool matchUnsigned = false;
		$var($List, req, $new($ArrayList, $nc(cs)->length));
		{
			$var($CodeSourceArray, arr$, cs);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($CodeSource, c, arr$->get(i$));
				{
					$var($CodeSignerArray, match, findMatchingSigners(c));
					if (match != nullptr) {
						if (match->length > 0) {
							req->add(match);
						} else {
							matchUnsigned = true;
						}
					} else {
						matchUnsigned = true;
					}
				}
			}
		}
		$var($List, signersReq, req);
		$var($Enumeration, enum2, matchUnsigned ? unsignedEntryNames(jar) : $Collections::emptyEnumeration());
		return $new($JarVerifier$1, this, itor, signersReq, enum2);
	}
}

$Enumeration* JarVerifier::entries2($JarFile* jar, $Enumeration* e) {
	$useLocalCurrentObjectStackCache();
	$var($Map, map, $new($HashMap));
	map->putAll($(signerMap()));
	$var($Enumeration, enum_, e);
	return $new($JarVerifier$2, this, enum_, jar, map);
}

bool JarVerifier::isSigningRelated($String* name) {
	$init(JarVerifier);
	return $SignatureFileVerifier::isSigningRelated(name);
}

$Enumeration* JarVerifier::unsignedEntryNames($JarFile* jar) {
	$useLocalCurrentObjectStackCache();
	$var($Map, map, signerMap());
	$var($Enumeration, entries, $nc(jar)->entries());
	return $new($JarVerifier$3, this, entries, map);
}

$List* JarVerifier::getJarCodeSigners() {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$var($CodeSignerArray, signers, nullptr);
		if (this->jarCodeSigners == nullptr) {
			$var($HashSet, set, $new($HashSet));
			set->addAll($($nc($(signerMap()))->values()));
			$set(this, jarCodeSigners, $new($ArrayList));
			$nc(this->jarCodeSigners)->addAll(static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractSet*>(set))));
		}
		return this->jarCodeSigners;
	}
}

$CodeSourceArray* JarVerifier::getCodeSources($JarFile* jar, $URL* url) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		bool hasUnsigned = $nc($(unsignedEntryNames(jar)))->hasMoreElements();
		return mapSignersToCodeSources(url, $(getJarCodeSigners()), hasUnsigned);
	}
}

$CodeSource* JarVerifier::getCodeSource($URL* url, $String* name) {
	$useLocalCurrentObjectStackCache();
	$var($CodeSignerArray, signers, nullptr);
	$assign(signers, $cast($CodeSignerArray, $nc($(signerMap()))->get(name)));
	return mapSignersToCodeSource(url, signers);
}

$CodeSource* JarVerifier::getCodeSource($URL* url, $JarFile* jar, $JarEntry* je) {
	$useLocalCurrentObjectStackCache();
	$var($CodeSignerArray, signers, nullptr);
	return mapSignersToCodeSource(url, $(getCodeSigners(jar, je)));
}

void JarVerifier::setEagerValidation(bool eager) {
	this->eagerValidation = eager;
}

$List* JarVerifier::getManifestDigests() {
	$synchronized(this) {
		return $Collections::unmodifiableList(this->manifestDigests);
	}
}

$CodeSource* JarVerifier::getUnsignedCS($URL* url) {
	$init(JarVerifier);
	return $new($JarVerifier$VerifierCodeSource, ($Object*)nullptr, url, ($CertificateArray*)nullptr);
}

bool JarVerifier::isTrustedManifestEntry($String* name) {
	$useLocalCurrentObjectStackCache();
	$var($CodeSignerArray, forMan, $cast($CodeSignerArray, $nc(this->verifiedSigners)->get(this->manifestName)));
	if (forMan == nullptr) {
		return true;
	}
	$var($CodeSignerArray, forName, $cast($CodeSignerArray, $nc(this->sigFileSigners)->get(name)));
	if (forName == nullptr) {
		$assign(forName, $cast($CodeSignerArray, $nc(this->verifiedSigners)->get(name)));
	}
	return forName != nullptr && forName->length == $nc(forMan)->length;
}

void clinit$JarVerifier($Class* class$) {
	$assignStatic(JarVerifier::debug, $Debug::getInstance("jar"_s));
}

JarVerifier::JarVerifier() {
}

$Class* JarVerifier::load$($String* name, bool initialize) {
	$loadClass(JarVerifier, name, initialize, &_JarVerifier_ClassInfo_, clinit$JarVerifier, allocate$JarVerifier);
	return class$;
}

$Class* JarVerifier::class$ = nullptr;

		} // jar
	} // util
} // java