#include <sun/security/provider/DomainKeyStore.h>

#include <java/io/File.h>
#include <java/io/FileOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/InputStreamReader.h>
#include <java/io/OutputStream.h>
#include <java/io/Reader.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/net/MalformedURLException.h>
#include <java/net/URI.h>
#include <java/net/URISyntaxException.h>
#include <java/net/URL.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/StandardCharsets.h>
#include <java/security/DomainLoadStoreParameter.h>
#include <java/security/Key.h>
#include <java/security/KeyStore$Builder.h>
#include <java/security/KeyStore$LoadStoreParameter.h>
#include <java/security/KeyStore$PasswordProtection.h>
#include <java/security/KeyStore$ProtectionParameter.h>
#include <java/security/KeyStore.h>
#include <java/security/KeyStoreException.h>
#include <java/security/KeyStoreSpi.h>
#include <java/security/Provider.h>
#include <java/security/Security.h>
#include <java/security/cert/Certificate.h>
#include <java/util/AbstractMap$SimpleEntry.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Date.h>
#include <java/util/Enumeration.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <sun/security/provider/DomainKeyStore$1.h>
#include <sun/security/provider/DomainKeyStore$KeyStoreBuilderComponents.h>
#include <sun/security/provider/PolicyParser$DomainEntry.h>
#include <sun/security/provider/PolicyParser$KeyStoreEntry.h>
#include <sun/security/provider/PolicyParser$ParsingException.h>
#include <sun/security/provider/PolicyParser.h>
#include <sun/security/util/PolicyUtil.h>
#include <jcpp.h>

#undef DEFAULT_KEYSTORE_TYPE
#undef DEFAULT_STREAM_PREFIX
#undef ENTRY_NAME_SEPARATOR
#undef KEYSTORE_PASSWORD_ENV
#undef KEYSTORE_PROVIDER_NAME
#undef KEYSTORE_TYPE
#undef KEYSTORE_URI
#undef REGEX_META
#undef UTF_8

using $CertificateArray = $Array<::java::security::cert::Certificate>;
using $File = ::java::io::File;
using $FileOutputStream = ::java::io::FileOutputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $InputStreamReader = ::java::io::InputStreamReader;
using $OutputStream = ::java::io::OutputStream;
using $Reader = ::java::io::Reader;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $MalformedURLException = ::java::net::MalformedURLException;
using $URI = ::java::net::URI;
using $URISyntaxException = ::java::net::URISyntaxException;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $DomainLoadStoreParameter = ::java::security::DomainLoadStoreParameter;
using $Key = ::java::security::Key;
using $KeyStore = ::java::security::KeyStore;
using $KeyStore$Builder = ::java::security::KeyStore$Builder;
using $KeyStore$LoadStoreParameter = ::java::security::KeyStore$LoadStoreParameter;
using $KeyStore$PasswordProtection = ::java::security::KeyStore$PasswordProtection;
using $KeyStore$ProtectionParameter = ::java::security::KeyStore$ProtectionParameter;
using $KeyStoreException = ::java::security::KeyStoreException;
using $KeyStoreSpi = ::java::security::KeyStoreSpi;
using $Provider = ::java::security::Provider;
using $Security = ::java::security::Security;
using $Certificate = ::java::security::cert::Certificate;
using $AbstractMap$SimpleEntry = ::java::util::AbstractMap$SimpleEntry;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Date = ::java::util::Date;
using $Enumeration = ::java::util::Enumeration;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;
using $DomainKeyStore$1 = ::sun::security::provider::DomainKeyStore$1;
using $DomainKeyStore$KeyStoreBuilderComponents = ::sun::security::provider::DomainKeyStore$KeyStoreBuilderComponents;
using $PolicyParser = ::sun::security::provider::PolicyParser;
using $PolicyParser$DomainEntry = ::sun::security::provider::PolicyParser$DomainEntry;
using $PolicyParser$KeyStoreEntry = ::sun::security::provider::PolicyParser$KeyStoreEntry;
using $PolicyParser$ParsingException = ::sun::security::provider::PolicyParser$ParsingException;
using $PolicyUtil = ::sun::security::util::PolicyUtil;

namespace sun {
	namespace security {
		namespace provider {

$FieldInfo _DomainKeyStore_FieldInfo_[] = {
	{"ENTRY_NAME_SEPARATOR", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DomainKeyStore, ENTRY_NAME_SEPARATOR)},
	{"KEYSTORE_PROVIDER_NAME", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DomainKeyStore, KEYSTORE_PROVIDER_NAME)},
	{"KEYSTORE_TYPE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DomainKeyStore, KEYSTORE_TYPE)},
	{"KEYSTORE_URI", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DomainKeyStore, KEYSTORE_URI)},
	{"KEYSTORE_PASSWORD_ENV", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DomainKeyStore, KEYSTORE_PASSWORD_ENV)},
	{"REGEX_META", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DomainKeyStore, REGEX_META)},
	{"DEFAULT_STREAM_PREFIX", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DomainKeyStore, DEFAULT_STREAM_PREFIX)},
	{"streamCounter", "I", nullptr, $PRIVATE, $field(DomainKeyStore, streamCounter)},
	{"entryNameSeparator", "Ljava/lang/String;", nullptr, $PRIVATE, $field(DomainKeyStore, entryNameSeparator)},
	{"entryNameSeparatorRegEx", "Ljava/lang/String;", nullptr, $PRIVATE, $field(DomainKeyStore, entryNameSeparatorRegEx)},
	{"DEFAULT_KEYSTORE_TYPE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DomainKeyStore, DEFAULT_KEYSTORE_TYPE)},
	{"keystores", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/security/KeyStore;>;", $PRIVATE | $FINAL, $field(DomainKeyStore, keystores)},
	{}
};

$MethodInfo _DomainKeyStore_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(DomainKeyStore, init$, void)},
	{"convertAlias", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $ABSTRACT, $virtualMethod(DomainKeyStore, convertAlias, $String*, $String*)},
	{"engineAliases", "()Ljava/util/Enumeration;", "()Ljava/util/Enumeration<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(DomainKeyStore, engineAliases, $Enumeration*)},
	{"engineContainsAlias", "(Ljava/lang/String;)Z", nullptr, $PUBLIC, $virtualMethod(DomainKeyStore, engineContainsAlias, bool, $String*)},
	{"engineDeleteEntry", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(DomainKeyStore, engineDeleteEntry, void, $String*), "java.security.KeyStoreException"},
	{"engineGetCertificate", "(Ljava/lang/String;)Ljava/security/cert/Certificate;", nullptr, $PUBLIC, $virtualMethod(DomainKeyStore, engineGetCertificate, $Certificate*, $String*)},
	{"engineGetCertificateAlias", "(Ljava/security/cert/Certificate;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(DomainKeyStore, engineGetCertificateAlias, $String*, $Certificate*)},
	{"engineGetCertificateChain", "(Ljava/lang/String;)[Ljava/security/cert/Certificate;", nullptr, $PUBLIC, $virtualMethod(DomainKeyStore, engineGetCertificateChain, $CertificateArray*, $String*)},
	{"engineGetCreationDate", "(Ljava/lang/String;)Ljava/util/Date;", nullptr, $PUBLIC, $virtualMethod(DomainKeyStore, engineGetCreationDate, $Date*, $String*)},
	{"engineGetKey", "(Ljava/lang/String;[C)Ljava/security/Key;", nullptr, $PUBLIC, $virtualMethod(DomainKeyStore, engineGetKey, $Key*, $String*, $chars*), "java.security.NoSuchAlgorithmException,java.security.UnrecoverableKeyException"},
	{"engineIsCertificateEntry", "(Ljava/lang/String;)Z", nullptr, $PUBLIC, $virtualMethod(DomainKeyStore, engineIsCertificateEntry, bool, $String*)},
	{"engineIsKeyEntry", "(Ljava/lang/String;)Z", nullptr, $PUBLIC, $virtualMethod(DomainKeyStore, engineIsKeyEntry, bool, $String*)},
	{"engineLoad", "(Ljava/io/InputStream;[C)V", nullptr, $PUBLIC, $virtualMethod(DomainKeyStore, engineLoad, void, $InputStream*, $chars*), "java.io.IOException,java.security.NoSuchAlgorithmException,java.security.cert.CertificateException"},
	{"engineLoad", "(Ljava/security/KeyStore$LoadStoreParameter;)V", nullptr, $PUBLIC, $virtualMethod(DomainKeyStore, engineLoad, void, $KeyStore$LoadStoreParameter*), "java.io.IOException,java.security.NoSuchAlgorithmException,java.security.cert.CertificateException"},
	{"engineSetCertificateEntry", "(Ljava/lang/String;Ljava/security/cert/Certificate;)V", nullptr, $PUBLIC, $virtualMethod(DomainKeyStore, engineSetCertificateEntry, void, $String*, $Certificate*), "java.security.KeyStoreException"},
	{"engineSetKeyEntry", "(Ljava/lang/String;Ljava/security/Key;[C[Ljava/security/cert/Certificate;)V", nullptr, $PUBLIC, $virtualMethod(DomainKeyStore, engineSetKeyEntry, void, $String*, $Key*, $chars*, $CertificateArray*), "java.security.KeyStoreException"},
	{"engineSetKeyEntry", "(Ljava/lang/String;[B[Ljava/security/cert/Certificate;)V", nullptr, $PUBLIC, $virtualMethod(DomainKeyStore, engineSetKeyEntry, void, $String*, $bytes*, $CertificateArray*), "java.security.KeyStoreException"},
	{"engineSize", "()I", nullptr, $PUBLIC, $virtualMethod(DomainKeyStore, engineSize, int32_t)},
	{"engineStore", "(Ljava/io/OutputStream;[C)V", nullptr, $PUBLIC, $virtualMethod(DomainKeyStore, engineStore, void, $OutputStream*, $chars*), "java.io.IOException,java.security.NoSuchAlgorithmException,java.security.cert.CertificateException"},
	{"engineStore", "(Ljava/security/KeyStore$LoadStoreParameter;)V", nullptr, $PUBLIC, $virtualMethod(DomainKeyStore, engineStore, void, $KeyStore$LoadStoreParameter*), "java.io.IOException,java.security.NoSuchAlgorithmException,java.security.cert.CertificateException"},
	{"getBuilders", "(Ljava/net/URI;Ljava/util/Map;)Ljava/util/List;", "(Ljava/net/URI;Ljava/util/Map<Ljava/lang/String;Ljava/security/KeyStore$ProtectionParameter;>;)Ljava/util/List<Lsun/security/provider/DomainKeyStore$KeyStoreBuilderComponents;>;", $PRIVATE, $method(DomainKeyStore, getBuilders, $List*, $URI*, $Map*), "java.io.IOException"},
	{"getKeystoreForWriting", "(Ljava/lang/String;)Ljava/util/AbstractMap$SimpleEntry;", "(Ljava/lang/String;)Ljava/util/AbstractMap$SimpleEntry<Ljava/lang/String;Ljava/util/AbstractMap$SimpleEntry<Ljava/lang/String;Ljava/security/KeyStore;>;>;", $PRIVATE, $method(DomainKeyStore, getKeystoreForWriting, $AbstractMap$SimpleEntry*, $String*)},
	{"getKeystoresForReading", "(Ljava/lang/String;)Ljava/util/AbstractMap$SimpleEntry;", "(Ljava/lang/String;)Ljava/util/AbstractMap$SimpleEntry<Ljava/lang/String;Ljava/util/Collection<Ljava/security/KeyStore;>;>;", $PRIVATE, $method(DomainKeyStore, getKeystoresForReading, $AbstractMap$SimpleEntry*, $String*)},
	{}
};

$InnerClassInfo _DomainKeyStore_InnerClassesInfo_[] = {
	{"sun.security.provider.DomainKeyStore$KeyStoreBuilderComponents", "sun.security.provider.DomainKeyStore", "KeyStoreBuilderComponents", $STATIC},
	{"sun.security.provider.DomainKeyStore$DKS", "sun.security.provider.DomainKeyStore", "DKS", $PUBLIC | $STATIC | $FINAL},
	{"sun.security.provider.DomainKeyStore$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _DomainKeyStore_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"sun.security.provider.DomainKeyStore",
	"java.security.KeyStoreSpi",
	nullptr,
	_DomainKeyStore_FieldInfo_,
	_DomainKeyStore_MethodInfo_,
	nullptr,
	nullptr,
	_DomainKeyStore_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.provider.DomainKeyStore$KeyStoreBuilderComponents,sun.security.provider.DomainKeyStore$DKS,sun.security.provider.DomainKeyStore$1"
};

$Object* allocate$DomainKeyStore($Class* clazz) {
	return $of($alloc(DomainKeyStore));
}

$String* DomainKeyStore::ENTRY_NAME_SEPARATOR = nullptr;
$String* DomainKeyStore::KEYSTORE_PROVIDER_NAME = nullptr;
$String* DomainKeyStore::KEYSTORE_TYPE = nullptr;
$String* DomainKeyStore::KEYSTORE_URI = nullptr;
$String* DomainKeyStore::KEYSTORE_PASSWORD_ENV = nullptr;
$String* DomainKeyStore::REGEX_META = nullptr;
$String* DomainKeyStore::DEFAULT_STREAM_PREFIX = nullptr;
$String* DomainKeyStore::DEFAULT_KEYSTORE_TYPE = nullptr;

void DomainKeyStore::init$() {
	$KeyStoreSpi::init$();
	this->streamCounter = 1;
	$set(this, entryNameSeparator, " "_s);
	$set(this, entryNameSeparatorRegEx, " "_s);
	$set(this, keystores, $new($HashMap));
}

$Key* DomainKeyStore::engineGetKey($String* alias, $chars* password) {
	$useLocalCurrentObjectStackCache();
	$var($AbstractMap$SimpleEntry, pair, getKeystoresForReading(alias));
	$var($Key, key, nullptr);
	try {
		$var($String, entryAlias, $cast($String, $nc(pair)->getKey()));
		{
			$var($Iterator, i$, $nc(($cast($Collection, $(pair->getValue()))))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($KeyStore, keystore, $cast($KeyStore, i$->next()));
				{
					$assign(key, $nc(keystore)->getKey(entryAlias, password));
					if (key != nullptr) {
						break;
					}
				}
			}
		}
	} catch ($KeyStoreException& e) {
		$throwNew($IllegalStateException, static_cast<$Throwable*>(e));
	}
	return key;
}

$CertificateArray* DomainKeyStore::engineGetCertificateChain($String* alias) {
	$useLocalCurrentObjectStackCache();
	$var($AbstractMap$SimpleEntry, pair, getKeystoresForReading(alias));
	$var($CertificateArray, chain, nullptr);
	try {
		$var($String, entryAlias, $cast($String, $nc(pair)->getKey()));
		{
			$var($Iterator, i$, $nc(($cast($Collection, $(pair->getValue()))))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($KeyStore, keystore, $cast($KeyStore, i$->next()));
				{
					$assign(chain, $nc(keystore)->getCertificateChain(entryAlias));
					if (chain != nullptr) {
						break;
					}
				}
			}
		}
	} catch ($KeyStoreException& e) {
		$throwNew($IllegalStateException, static_cast<$Throwable*>(e));
	}
	return chain;
}

$Certificate* DomainKeyStore::engineGetCertificate($String* alias) {
	$useLocalCurrentObjectStackCache();
	$var($AbstractMap$SimpleEntry, pair, getKeystoresForReading(alias));
	$var($Certificate, cert, nullptr);
	try {
		$var($String, entryAlias, $cast($String, $nc(pair)->getKey()));
		{
			$var($Iterator, i$, $nc(($cast($Collection, $(pair->getValue()))))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($KeyStore, keystore, $cast($KeyStore, i$->next()));
				{
					$assign(cert, $nc(keystore)->getCertificate(entryAlias));
					if (cert != nullptr) {
						break;
					}
				}
			}
		}
	} catch ($KeyStoreException& e) {
		$throwNew($IllegalStateException, static_cast<$Throwable*>(e));
	}
	return cert;
}

$Date* DomainKeyStore::engineGetCreationDate($String* alias) {
	$useLocalCurrentObjectStackCache();
	$var($AbstractMap$SimpleEntry, pair, getKeystoresForReading(alias));
	$var($Date, date, nullptr);
	try {
		$var($String, entryAlias, $cast($String, $nc(pair)->getKey()));
		{
			$var($Iterator, i$, $nc(($cast($Collection, $(pair->getValue()))))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($KeyStore, keystore, $cast($KeyStore, i$->next()));
				{
					$assign(date, $nc(keystore)->getCreationDate(entryAlias));
					if (date != nullptr) {
						break;
					}
				}
			}
		}
	} catch ($KeyStoreException& e) {
		$throwNew($IllegalStateException, static_cast<$Throwable*>(e));
	}
	return date;
}

void DomainKeyStore::engineSetKeyEntry($String* alias, $Key* key, $chars* password, $CertificateArray* chain) {
	$useLocalCurrentObjectStackCache();
	$var($AbstractMap$SimpleEntry, pair, getKeystoreForWriting(alias));
	if (pair == nullptr) {
		$throwNew($KeyStoreException, $$str({"Error setting key entry for \'"_s, alias, "\'"_s}));
	}
	$var($String, entryAlias, $cast($String, $nc(pair)->getKey()));
	$var($Map$Entry, keystore, $cast($Map$Entry, pair->getValue()));
	$nc(($cast($KeyStore, $($nc(keystore)->getValue()))))->setKeyEntry(entryAlias, key, password, chain);
}

void DomainKeyStore::engineSetKeyEntry($String* alias, $bytes* key, $CertificateArray* chain) {
	$useLocalCurrentObjectStackCache();
	$var($AbstractMap$SimpleEntry, pair, getKeystoreForWriting(alias));
	if (pair == nullptr) {
		$throwNew($KeyStoreException, $$str({"Error setting protected key entry for \'"_s, alias, "\'"_s}));
	}
	$var($String, entryAlias, $cast($String, $nc(pair)->getKey()));
	$var($Map$Entry, keystore, $cast($Map$Entry, pair->getValue()));
	$nc(($cast($KeyStore, $($nc(keystore)->getValue()))))->setKeyEntry(entryAlias, key, chain);
}

void DomainKeyStore::engineSetCertificateEntry($String* alias, $Certificate* cert) {
	$useLocalCurrentObjectStackCache();
	$var($AbstractMap$SimpleEntry, pair, getKeystoreForWriting(alias));
	if (pair == nullptr) {
		$throwNew($KeyStoreException, $$str({"Error setting certificate entry for \'"_s, alias, "\'"_s}));
	}
	$var($String, entryAlias, $cast($String, $nc(pair)->getKey()));
	$var($Map$Entry, keystore, $cast($Map$Entry, pair->getValue()));
	$nc(($cast($KeyStore, $($nc(keystore)->getValue()))))->setCertificateEntry(entryAlias, cert);
}

void DomainKeyStore::engineDeleteEntry($String* alias) {
	$useLocalCurrentObjectStackCache();
	$var($AbstractMap$SimpleEntry, pair, getKeystoreForWriting(alias));
	if (pair == nullptr) {
		$throwNew($KeyStoreException, $$str({"Error deleting entry for \'"_s, alias, "\'"_s}));
	}
	$var($String, entryAlias, $cast($String, $nc(pair)->getKey()));
	$var($Map$Entry, keystore, $cast($Map$Entry, pair->getValue()));
	$nc(($cast($KeyStore, $($nc(keystore)->getValue()))))->deleteEntry(entryAlias);
}

$Enumeration* DomainKeyStore::engineAliases() {
	$useLocalCurrentObjectStackCache();
	$var($Iterator, iterator, $nc($($nc(this->keystores)->entrySet()))->iterator());
	return $new($DomainKeyStore$1, this, iterator);
}

bool DomainKeyStore::engineContainsAlias($String* alias) {
	$useLocalCurrentObjectStackCache();
	$var($AbstractMap$SimpleEntry, pair, getKeystoresForReading(alias));
	try {
		$var($String, entryAlias, $cast($String, $nc(pair)->getKey()));
		{
			$var($Iterator, i$, $nc(($cast($Collection, $(pair->getValue()))))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($KeyStore, keystore, $cast($KeyStore, i$->next()));
				{
					if ($nc(keystore)->containsAlias(entryAlias)) {
						return true;
					}
				}
			}
		}
	} catch ($KeyStoreException& e) {
		$throwNew($IllegalStateException, static_cast<$Throwable*>(e));
	}
	return false;
}

int32_t DomainKeyStore::engineSize() {
	$useLocalCurrentObjectStackCache();
	int32_t size = 0;
	try {
		{
			$var($Iterator, i$, $nc($($nc(this->keystores)->values()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($KeyStore, keystore, $cast($KeyStore, i$->next()));
				{
					size += $nc(keystore)->size();
				}
			}
		}
	} catch ($KeyStoreException& e) {
		$throwNew($IllegalStateException, static_cast<$Throwable*>(e));
	}
	return size;
}

bool DomainKeyStore::engineIsKeyEntry($String* alias) {
	$useLocalCurrentObjectStackCache();
	$var($AbstractMap$SimpleEntry, pair, getKeystoresForReading(alias));
	try {
		$var($String, entryAlias, $cast($String, $nc(pair)->getKey()));
		{
			$var($Iterator, i$, $nc(($cast($Collection, $(pair->getValue()))))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($KeyStore, keystore, $cast($KeyStore, i$->next()));
				{
					if ($nc(keystore)->isKeyEntry(entryAlias)) {
						return true;
					}
				}
			}
		}
	} catch ($KeyStoreException& e) {
		$throwNew($IllegalStateException, static_cast<$Throwable*>(e));
	}
	return false;
}

bool DomainKeyStore::engineIsCertificateEntry($String* alias) {
	$useLocalCurrentObjectStackCache();
	$var($AbstractMap$SimpleEntry, pair, getKeystoresForReading(alias));
	try {
		$var($String, entryAlias, $cast($String, $nc(pair)->getKey()));
		{
			$var($Iterator, i$, $nc(($cast($Collection, $(pair->getValue()))))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($KeyStore, keystore, $cast($KeyStore, i$->next()));
				{
					if ($nc(keystore)->isCertificateEntry(entryAlias)) {
						return true;
					}
				}
			}
		}
	} catch ($KeyStoreException& e) {
		$throwNew($IllegalStateException, static_cast<$Throwable*>(e));
	}
	return false;
}

$AbstractMap$SimpleEntry* DomainKeyStore::getKeystoresForReading($String* alias) {
	$useLocalCurrentObjectStackCache();
	$var($StringArray, splits, $nc(alias)->split(this->entryNameSeparatorRegEx, 2));
	if (splits->length == 2) {
		$var($KeyStore, keystore, $cast($KeyStore, $nc(this->keystores)->get(splits->get(0))));
		if (keystore != nullptr) {
			return $new($AbstractMap$SimpleEntry, splits->get(1), static_cast<$Collection*>($($Collections::singleton(keystore))));
		}
	} else if (splits->length == 1) {
		return $new($AbstractMap$SimpleEntry, alias, $($nc(this->keystores)->values()));
	}
	return $new($AbstractMap$SimpleEntry, ""_s, static_cast<$Collection*>($($Collections::emptyList())));
}

$AbstractMap$SimpleEntry* DomainKeyStore::getKeystoreForWriting($String* alias) {
	$useLocalCurrentObjectStackCache();
	$var($StringArray, splits, $nc(alias)->split(this->entryNameSeparator, 2));
	if (splits->length == 2) {
		$var($KeyStore, keystore, $cast($KeyStore, $nc(this->keystores)->get(splits->get(0))));
		if (keystore != nullptr) {
			return $new($AbstractMap$SimpleEntry, splits->get(1), $$new($AbstractMap$SimpleEntry, splits->get(0), keystore));
		}
	}
	return nullptr;
}

$String* DomainKeyStore::engineGetCertificateAlias($Certificate* cert) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($String, alias, nullptr);
		{
			$var($Iterator, i$, $nc($($nc(this->keystores)->values()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($KeyStore, keystore, $cast($KeyStore, i$->next()));
				{
					if (($assign(alias, $nc(keystore)->getCertificateAlias(cert))) != nullptr) {
						break;
					}
				}
			}
		}
		return alias;
	} catch ($KeyStoreException& e) {
		$throwNew($IllegalStateException, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

void DomainKeyStore::engineStore($OutputStream* stream, $chars* password) {
	$useLocalCurrentObjectStackCache();
	try {
		if ($nc(this->keystores)->size() == 1) {
			$nc(($cast($KeyStore, $($nc($($nc($($nc(this->keystores)->values()))->iterator()))->next()))))->store(stream, password);
			return;
		}
	} catch ($KeyStoreException& e) {
		$throwNew($IllegalStateException, static_cast<$Throwable*>(e));
	}
	$throwNew($UnsupportedOperationException, "This keystore must be stored using a DomainLoadStoreParameter"_s);
}

void DomainKeyStore::engineStore($KeyStore$LoadStoreParameter* param) {
	$useLocalCurrentObjectStackCache();
	if ($instanceOf($DomainLoadStoreParameter, param)) {
		$var($DomainLoadStoreParameter, domainParameter, $cast($DomainLoadStoreParameter, param));
		$var($URI, var$0, $nc(domainParameter)->getConfiguration());
		$var($List, builders, getBuilders(var$0, $(domainParameter->getProtectionParams())));
		{
			$var($Iterator, i$, $nc(builders)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($DomainKeyStore$KeyStoreBuilderComponents, builder, $cast($DomainKeyStore$KeyStoreBuilderComponents, i$->next()));
				{
					try {
						$var($KeyStore$ProtectionParameter, pp, $nc(builder)->protection);
						if (!($instanceOf($KeyStore$PasswordProtection, pp))) {
							$throwNew($KeyStoreException, static_cast<$Throwable*>($$new($IllegalArgumentException, "ProtectionParameter must be a KeyStore.PasswordProtection"_s)));
						}
						$var($chars, password, $nc(($cast($KeyStore$PasswordProtection, builder->protection)))->getPassword());
						$var($KeyStore, keystore, $cast($KeyStore, $nc(this->keystores)->get(builder->name)));
						{
							$var($FileOutputStream, stream, $new($FileOutputStream, builder->file));
							{
								$var($Throwable, var$1, nullptr);
								try {
									try {
										$nc(keystore)->store(stream, password);
									} catch ($Throwable& t$) {
										try {
											stream->close();
										} catch ($Throwable& x2) {
											t$->addSuppressed(x2);
										}
										$throw(t$);
									}
								} catch ($Throwable& var$2) {
									$assign(var$1, var$2);
								} /*finally*/ {
									stream->close();
								}
								if (var$1 != nullptr) {
									$throw(var$1);
								}
							}
						}
					} catch ($KeyStoreException& e) {
						$throwNew($IOException, static_cast<$Throwable*>(e));
					}
				}
			}
		}
	} else {
		$throwNew($UnsupportedOperationException, "This keystore must be stored using a DomainLoadStoreParameter"_s);
	}
}

void DomainKeyStore::engineLoad($InputStream* stream, $chars* password) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($KeyStore, keystore, nullptr);
		try {
			$assign(keystore, $KeyStore::getInstance("JKS"_s));
			$nc(keystore)->load(stream, password);
		} catch ($Exception& e) {
			if (!"JKS"_s->equalsIgnoreCase(DomainKeyStore::DEFAULT_KEYSTORE_TYPE)) {
				$assign(keystore, $KeyStore::getInstance(DomainKeyStore::DEFAULT_KEYSTORE_TYPE));
				$nc(keystore)->load(stream, password);
			} else {
				$throw(e);
			}
		}
		$var($String, var$0, DomainKeyStore::DEFAULT_STREAM_PREFIX);
		$var($String, keystoreName, $concat(var$0, $$str(this->streamCounter++)));
		$nc(this->keystores)->put(keystoreName, keystore);
	} catch ($Exception& e) {
		$throwNew($UnsupportedOperationException, "This keystore must be loaded using a DomainLoadStoreParameter"_s);
	}
}

void DomainKeyStore::engineLoad($KeyStore$LoadStoreParameter* param) {
	$useLocalCurrentObjectStackCache();
	if ($instanceOf($DomainLoadStoreParameter, param)) {
		$var($DomainLoadStoreParameter, domainParameter, $cast($DomainLoadStoreParameter, param));
		$var($URI, var$0, $nc(domainParameter)->getConfiguration());
		$var($List, builders, getBuilders(var$0, $(domainParameter->getProtectionParams())));
		{
			$var($Iterator, i$, $nc(builders)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($DomainKeyStore$KeyStoreBuilderComponents, builder, $cast($DomainKeyStore$KeyStoreBuilderComponents, i$->next()));
				{
					try {
						if ($nc(builder)->file != nullptr) {
							$nc(this->keystores)->put(builder->name, $($nc($($KeyStore$Builder::newInstance(builder->type, builder->provider, builder->file, builder->protection)))->getKeyStore()));
						} else {
							$nc(this->keystores)->put(builder->name, $($nc($($KeyStore$Builder::newInstance(builder->type, builder->provider, builder->protection)))->getKeyStore()));
						}
					} catch ($KeyStoreException& e) {
						$throwNew($IOException, static_cast<$Throwable*>(e));
					}
				}
			}
		}
	} else {
		$throwNew($UnsupportedOperationException, "This keystore must be loaded using a DomainLoadStoreParameter"_s);
	}
}

$List* DomainKeyStore::getBuilders($URI* configuration, $Map* passwords) {
	$useLocalCurrentObjectStackCache();
	$var($PolicyParser, parser, $new($PolicyParser, true));
	$var($Collection, domains, nullptr);
	$var($List, builders, $new($ArrayList));
	$var($String, uriDomain, $nc(configuration)->getFragment());
	try {
		$init($StandardCharsets);
		$var($InputStreamReader, configurationReader, $new($InputStreamReader, $($PolicyUtil::getInputStream($(configuration->toURL()))), $StandardCharsets::UTF_8));
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					parser->read(configurationReader);
					$assign(domains, parser->getDomainEntries());
				} catch ($Throwable& t$) {
					try {
						configurationReader->close();
					} catch ($Throwable& x2) {
						t$->addSuppressed(x2);
					}
					$throw(t$);
				}
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				configurationReader->close();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	} catch ($MalformedURLException& mue) {
		$throwNew($IOException, static_cast<$Throwable*>(mue));
	} catch ($PolicyParser$ParsingException& pe) {
		$throwNew($IOException, static_cast<$Throwable*>(pe));
	}
	{
		$var($Iterator, i$, $nc(domains)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($PolicyParser$DomainEntry, domain, $cast($PolicyParser$DomainEntry, i$->next()));
			{
				$var($Map, domainProperties, $nc(domain)->getProperties());
				if (uriDomain != nullptr && (!uriDomain->equalsIgnoreCase($(domain->getName())))) {
					continue;
				}
				if ($nc(domainProperties)->containsKey(DomainKeyStore::ENTRY_NAME_SEPARATOR)) {
					$set(this, entryNameSeparator, $cast($String, domainProperties->get(DomainKeyStore::ENTRY_NAME_SEPARATOR)));
					char16_t ch = (char16_t)0;
					$var($StringBuilder, s, $new($StringBuilder));
					for (int32_t i = 0; i < $nc(this->entryNameSeparator)->length(); ++i) {
						ch = $nc(this->entryNameSeparator)->charAt(i);
						if ($nc(DomainKeyStore::REGEX_META)->indexOf((int32_t)ch) != -1) {
							s->append(u'\\');
						}
						s->append(ch);
					}
					$set(this, entryNameSeparatorRegEx, s->toString());
				}
				$var($Collection, keystores, domain->getEntries());
				{
					$var($Iterator, i$, $nc(keystores)->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($PolicyParser$KeyStoreEntry, keystore, $cast($PolicyParser$KeyStoreEntry, i$->next()));
						{
							$var($String, keystoreName, $nc(keystore)->getName());
							$var($Map, properties, $new($HashMap, domainProperties));
							properties->putAll($(keystore->getProperties()));
							$var($String, keystoreType, DomainKeyStore::DEFAULT_KEYSTORE_TYPE);
							if (properties->containsKey(DomainKeyStore::KEYSTORE_TYPE)) {
								$assign(keystoreType, $cast($String, properties->get(DomainKeyStore::KEYSTORE_TYPE)));
							}
							$var($Provider, keystoreProvider, nullptr);
							if (properties->containsKey(DomainKeyStore::KEYSTORE_PROVIDER_NAME)) {
								$var($String, keystoreProviderName, $cast($String, properties->get(DomainKeyStore::KEYSTORE_PROVIDER_NAME)));
								$assign(keystoreProvider, $Security::getProvider(keystoreProviderName));
								if (keystoreProvider == nullptr) {
									$throwNew($IOException, $$str({"Error locating JCE provider: "_s, keystoreProviderName}));
								}
							}
							$var($File, keystoreFile, nullptr);
							if (properties->containsKey(DomainKeyStore::KEYSTORE_URI)) {
								$var($String, uri, $cast($String, properties->get(DomainKeyStore::KEYSTORE_URI)));
								try {
									if ($nc(uri)->startsWith("file://"_s)) {
										$assign(keystoreFile, $new($File, $$new($URI, uri)));
									} else {
										$assign(keystoreFile, $new($File, uri));
									}
								} catch ($URISyntaxException& e) {
									$throwNew($IOException, $$str({"Error processing keystore property: keystoreURI=\""_s, uri, "\""_s}), e);
								} catch ($IllegalArgumentException& e) {
									$throwNew($IOException, $$str({"Error processing keystore property: keystoreURI=\""_s, uri, "\""_s}), e);
								}
							}
							$var($KeyStore$ProtectionParameter, keystoreProtection, nullptr);
							if ($nc(passwords)->containsKey(keystoreName)) {
								$assign(keystoreProtection, $cast($KeyStore$ProtectionParameter, passwords->get(keystoreName)));
							} else if (properties->containsKey(DomainKeyStore::KEYSTORE_PASSWORD_ENV)) {
								$var($String, env, $cast($String, properties->get(DomainKeyStore::KEYSTORE_PASSWORD_ENV)));
								$var($String, pwd, $System::getenv(env));
								if (pwd != nullptr) {
									$assign(keystoreProtection, $new($KeyStore$PasswordProtection, $(pwd->toCharArray())));
								} else {
									$throwNew($IOException, $$str({"Error processing keystore property: keystorePasswordEnv=\""_s, env, "\""_s}));
								}
							} else {
								$assign(keystoreProtection, $new($KeyStore$PasswordProtection, nullptr));
							}
							builders->add($$new($DomainKeyStore$KeyStoreBuilderComponents, keystoreName, keystoreType, keystoreProvider, keystoreFile, keystoreProtection));
						}
					}
				}
				break;
			}
		}
	}
	if (builders->isEmpty()) {
		$throwNew($IOException, $$str({"Error locating domain configuration data for: "_s, configuration}));
	}
	return builders;
}

void clinit$DomainKeyStore($Class* class$) {
	$assignStatic(DomainKeyStore::ENTRY_NAME_SEPARATOR, "entrynameseparator"_s);
	$assignStatic(DomainKeyStore::KEYSTORE_PROVIDER_NAME, "keystoreprovidername"_s);
	$assignStatic(DomainKeyStore::KEYSTORE_TYPE, "keystoretype"_s);
	$assignStatic(DomainKeyStore::KEYSTORE_URI, "keystoreuri"_s);
	$assignStatic(DomainKeyStore::KEYSTORE_PASSWORD_ENV, "keystorepasswordenv"_s);
	$assignStatic(DomainKeyStore::REGEX_META, ".$|()[{^?*+\\"_s);
	$assignStatic(DomainKeyStore::DEFAULT_STREAM_PREFIX, "iostream"_s);
	$assignStatic(DomainKeyStore::DEFAULT_KEYSTORE_TYPE, $KeyStore::getDefaultType());
}

DomainKeyStore::DomainKeyStore() {
}

$Class* DomainKeyStore::load$($String* name, bool initialize) {
	$loadClass(DomainKeyStore, name, initialize, &_DomainKeyStore_ClassInfo_, clinit$DomainKeyStore, allocate$DomainKeyStore);
	return class$;
}

$Class* DomainKeyStore::class$ = nullptr;

		} // provider
	} // security
} // sun