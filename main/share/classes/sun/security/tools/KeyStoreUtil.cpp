#include <sun/security/tools/KeyStoreUtil.h>

#include <java/io/BufferedReader.h>
#include <java/io/File.h>
#include <java/io/FileInputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/InputStreamReader.h>
#include <java/io/Reader.h>
#include <java/io/StreamTokenizer.h>
#include <java/io/StringReader.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/reflect/Constructor.h>
#include <java/net/MalformedURLException.h>
#include <java/net/URI.h>
#include <java/net/URL.h>
#include <java/security/KeyStore.h>
#include <java/security/Provider.h>
#include <java/security/PublicKey.h>
#include <java/security/Security.h>
#include <java/security/cert/X509Certificate.h>
#include <java/text/Collator.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/Properties.h>
#include <java/util/ResourceBundle.h>
#include <java/util/ServiceLoader.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <sun/security/util/FilePaths.h>
#include <sun/security/util/PropertyExpander.h>
#include <jcpp.h>

#undef ENGLISH
#undef TT_EOF

using $BufferedReader = ::java::io::BufferedReader;
using $File = ::java::io::File;
using $FileInputStream = ::java::io::FileInputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $InputStreamReader = ::java::io::InputStreamReader;
using $PrintStream = ::java::io::PrintStream;
using $Reader = ::java::io::Reader;
using $StreamTokenizer = ::java::io::StreamTokenizer;
using $StringReader = ::java::io::StringReader;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $Exception = ::java::lang::Exception;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $Constructor = ::java::lang::reflect::Constructor;
using $MalformedURLException = ::java::net::MalformedURLException;
using $URI = ::java::net::URI;
using $URL = ::java::net::URL;
using $KeyStore = ::java::security::KeyStore;
using $Provider = ::java::security::Provider;
using $Security = ::java::security::Security;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $Collator = ::java::text::Collator;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Properties = ::java::util::Properties;
using $ResourceBundle = ::java::util::ResourceBundle;
using $ServiceLoader = ::java::util::ServiceLoader;
using $X500Principal = ::javax::security::auth::x500::X500Principal;
using $FilePaths = ::sun::security::util::FilePaths;
using $PropertyExpander = ::sun::security::util::PropertyExpander;

namespace sun {
	namespace security {
		namespace tools {

$MethodInfo _KeyStoreUtil_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(KeyStoreUtil, init$, void)},
	{"expandArgs", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;[Ljava/lang/String;)[Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(KeyStoreUtil, expandArgs, $StringArray*, $String*, $String*, $String*, $String*, $StringArray*), "java.io.IOException,sun.security.util.PropertyExpander$ExpandException"},
	{"getCacerts", "()Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(KeyStoreUtil, getCacerts, $String*)},
	{"getCacertsKeyStore", "()Ljava/security/KeyStore;", nullptr, $PUBLIC | $STATIC, $staticMethod(KeyStoreUtil, getCacertsKeyStore, $KeyStore*), "java.lang.Exception"},
	{"getPassWithModifier", "(Ljava/lang/String;Ljava/lang/String;Ljava/util/ResourceBundle;Ljava/text/Collator;)[C", nullptr, $PUBLIC | $STATIC, $staticMethod(KeyStoreUtil, getPassWithModifier, $chars*, $String*, $String*, $ResourceBundle*, $Collator*)},
	{"isSelfSigned", "(Ljava/security/cert/X509Certificate;)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(KeyStoreUtil, isSelfSigned, bool, $X509Certificate*)},
	{"isWindowsKeyStore", "(Ljava/lang/String;)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(KeyStoreUtil, isWindowsKeyStore, bool, $String*)},
	{"loadProviderByClass", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/ClassLoader;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(KeyStoreUtil, loadProviderByClass, void, $String*, $String*, $ClassLoader*)},
	{"loadProviderByName", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(KeyStoreUtil, loadProviderByName, void, $String*, $String*)},
	{"niceStoreTypeName", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(KeyStoreUtil, niceStoreTypeName, $String*, $String*)},
	{"parseArgsLine", "(Ljava/util/List;Ljava/lang/String;)V", "(Ljava/util/List<Ljava/lang/String;>;Ljava/lang/String;)V", $PRIVATE | $STATIC, $staticMethod(KeyStoreUtil, parseArgsLine, void, $List*, $String*), "java.io.IOException,sun.security.util.PropertyExpander$ExpandException"},
	{"signedBy", "(Ljava/security/cert/X509Certificate;Ljava/security/cert/X509Certificate;)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(KeyStoreUtil, signedBy, bool, $X509Certificate*, $X509Certificate*)},
	{}
};

$ClassInfo _KeyStoreUtil_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.tools.KeyStoreUtil",
	"java.lang.Object",
	nullptr,
	nullptr,
	_KeyStoreUtil_MethodInfo_
};

$Object* allocate$KeyStoreUtil($Class* clazz) {
	return $of($alloc(KeyStoreUtil));
}

void KeyStoreUtil::init$() {
}

bool KeyStoreUtil::isSelfSigned($X509Certificate* cert) {
	return signedBy(cert, cert);
}

bool KeyStoreUtil::signedBy($X509Certificate* end, $X509Certificate* ca) {
	$useLocalCurrentObjectStackCache();
	if (!$nc($($nc(ca)->getSubjectX500Principal()))->equals($($nc(end)->getIssuerX500Principal()))) {
		return false;
	}
	try {
		$nc(end)->verify($($nc(ca)->getPublicKey()));
		return true;
	} catch ($Exception& e) {
		return false;
	}
	$shouldNotReachHere();
}

bool KeyStoreUtil::isWindowsKeyStore($String* storetype) {
	bool var$0 = storetype != nullptr;
	if (var$0) {
		bool var$1 = storetype->equalsIgnoreCase("Windows-MY"_s);
		var$0 = (var$1 || storetype->equalsIgnoreCase("Windows-ROOT"_s));
	}
	return var$0;
}

$String* KeyStoreUtil::niceStoreTypeName($String* storetype) {
	if ($nc(storetype)->equalsIgnoreCase("Windows-MY"_s)) {
		return "Windows-MY"_s;
	} else if (storetype->equalsIgnoreCase("Windows-ROOT"_s)) {
		return "Windows-ROOT"_s;
	} else {
		$init($Locale);
		return storetype->toUpperCase($Locale::ENGLISH);
	}
}

$String* KeyStoreUtil::getCacerts() {
	return $FilePaths::cacerts();
}

$KeyStore* KeyStoreUtil::getCacertsKeyStore() {
	$useLocalCurrentObjectStackCache();
	$var($File, file, $new($File, $(getCacerts())));
	if (!file->exists()) {
		return nullptr;
	}
	return $KeyStore::getInstance(file, ($chars*)nullptr);
}

$chars* KeyStoreUtil::getPassWithModifier($String* modifier, $String* arg, $ResourceBundle* rb, $Collator* collator) {
	$useLocalCurrentObjectStackCache();
	if (modifier == nullptr) {
		return $nc(arg)->toCharArray();
	} else if ($nc(collator)->compare(modifier, "env"_s) == 0) {
		$var($String, value, $System::getenv(arg));
		if (value == nullptr) {
			$nc($System::err)->println($$str({$($nc(rb)->getString("Cannot.find.environment.variable."_s)), arg}));
			return nullptr;
		} else {
			return $nc(value)->toCharArray();
		}
	} else if (collator->compare(modifier, "file"_s) == 0) {
		try {
			$var($URL, url, nullptr);
			try {
				$assign(url, $new($URL, arg));
			} catch ($MalformedURLException& mue) {
				$var($File, f, $new($File, arg));
				if (f->exists()) {
					$assign(url, $nc($(f->toURI()))->toURL());
				} else {
					$nc($System::err)->println($$str({$($nc(rb)->getString("Cannot.find.file."_s)), arg}));
					return nullptr;
				}
			}
			{
				$var($BufferedReader, br, $new($BufferedReader, $$new($InputStreamReader, $($nc(url)->openStream()))));
				{
					$var($Throwable, var$0, nullptr);
					$var($chars, var$2, nullptr);
					bool return$1 = false;
					try {
						try {
							$var($String, value, br->readLine());
							if (value == nullptr) {
								$assign(var$2, $new($chars, 0));
								return$1 = true;
								goto $finally;
							}
							$assign(var$2, $nc(value)->toCharArray());
							return$1 = true;
							goto $finally;
						} catch ($Throwable& t$) {
							try {
								br->close();
							} catch ($Throwable& x2) {
								t$->addSuppressed(x2);
							}
							$throw(t$);
						}
					} catch ($Throwable& var$3) {
						$assign(var$0, var$3);
					} $finally: {
						br->close();
					}
					if (var$0 != nullptr) {
						$throw(var$0);
					}
					if (return$1) {
						return var$2;
					}
				}
			}
		} catch ($IOException& ioe) {
			$nc($System::err)->println($of(ioe));
			return nullptr;
		}
	} else {
		$nc($System::err)->println($$str({$($nc(rb)->getString("Unknown.password.type."_s)), modifier}));
		return nullptr;
	}
}

void KeyStoreUtil::parseArgsLine($List* list, $String* s) {
	$useLocalCurrentObjectStackCache();
	$var($StreamTokenizer, st, $new($StreamTokenizer, static_cast<$Reader*>($$new($StringReader, s))));
	st->resetSyntax();
	st->whitespaceChars(0, 32);
	st->wordChars(33, 255);
	st->quoteChar(u'\"');
	st->quoteChar(u'\'');
	while (true) {
		if (st->nextToken() == $StreamTokenizer::TT_EOF) {
			break;
		}
		$nc(list)->add($($PropertyExpander::expand(st->sval)));
	}
}

$StringArray* KeyStoreUtil::expandArgs($String* tool, $String* file, $String* c1, $String* c2, $StringArray* args) {
	$useLocalCurrentObjectStackCache();
	$var($List, result, $new($ArrayList));
	$var($Properties, p, $new($Properties));
	p->load(static_cast<$InputStream*>($$new($FileInputStream, file)));
	$var($String, s, p->getProperty($$str({tool, ".all"_s})));
	if (s != nullptr) {
		parseArgsLine(result, s);
	}
	$var($String, s1, p->getProperty($$str({tool, "."_s, $($nc(c1)->substring(1))})));
	$var($String, s2, nullptr);
	if (c2 != nullptr) {
		$assign(s2, p->getProperty($$str({tool, "."_s, $(c2->substring(1))})));
	}
	if (s1 != nullptr && s2 != nullptr) {
		$throwNew($IOException, $$str({"Cannot have both "_s, c1, " and "_s, c2, " as pre-configured options"_s}));
	}
	if (s1 == nullptr) {
		$assign(s1, s2);
	}
	if (s1 != nullptr) {
		parseArgsLine(result, s1);
	}
	if (result->isEmpty()) {
		return args;
	} else {
		result->addAll($($Arrays::asList(args)));
		return $fcast($StringArray, result->toArray($$new($StringArray, result->size())));
	}
}

void KeyStoreUtil::loadProviderByName($String* provName, $String* arg) {
	$load(KeyStoreUtil);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($Provider, loaded, $Security::getProvider(provName));
	if (loaded != nullptr) {
		if (arg != nullptr) {
			$assign(loaded, loaded->configure(arg));
			$Security::addProvider(loaded);
		}
		return;
	}
	{
		$load($Provider);
		$var($Iterator, i$, $nc($($ServiceLoader::load($Provider::class$, $($ClassLoader::getSystemClassLoader()))))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Provider, p, $cast($Provider, i$->next()));
			{
				if ($nc($($nc(p)->getName()))->equals(provName)) {
					if (arg != nullptr) {
						$assign(p, p->configure(arg));
					}
					$Security::addProvider(p);
					return;
				}
			}
		}
	}
	$throwNew($IllegalArgumentException, "No provider found"_s);
}

void KeyStoreUtil::loadProviderByClass($String* provClass, $String* arg, $ClassLoader* cl) {
	$load(KeyStoreUtil);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if ($nc(provClass)->equals("sun.security.pkcs11.SunPKCS11"_s)) {
		loadProviderByName("SunPKCS11"_s, arg);
		return;
	} else if (provClass->equals("sun.security.mscapi.SunMSCAPI"_s)) {
		loadProviderByName("SunMSCAPI"_s, arg);
		return;
	}
	$var($Provider, prov, nullptr);
	try {
		$Class* clazz = $Class::forName(provClass, false, cl);
		$assign(prov, $cast($Provider, $nc($($nc(clazz)->getConstructor($$new($ClassArray, 0))))->newInstance($$new($ObjectArray, 0))));
	} catch ($ReflectiveOperationException& e) {
		$throwNew($IllegalArgumentException, static_cast<$Throwable*>(e));
	}
	if (arg != nullptr) {
		$assign(prov, $nc(prov)->configure(arg));
	}
	$Security::addProvider(prov);
}

KeyStoreUtil::KeyStoreUtil() {
}

$Class* KeyStoreUtil::load$($String* name, bool initialize) {
	$loadClass(KeyStoreUtil, name, initialize, &_KeyStoreUtil_ClassInfo_, allocate$KeyStoreUtil);
	return class$;
}

$Class* KeyStoreUtil::class$ = nullptr;

		} // tools
	} // security
} // sun