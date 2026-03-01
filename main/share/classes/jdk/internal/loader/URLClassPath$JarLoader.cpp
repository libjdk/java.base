#include <jdk/internal/loader/URLClassPath$JarLoader.h>

#include <java/io/File.h>
#include <java/io/FileNotFoundException.h>
#include <java/io/IOException.h>
#include <java/lang/InternalError.h>
#include <java/lang/Runtime$Version.h>
#include <java/lang/SecurityManager.h>
#include <java/net/JarURLConnection.h>
#include <java/net/MalformedURLException.h>
#include <java/net/URI.h>
#include <java/net/URL.h>
#include <java/net/URLConnection.h>
#include <java/net/URLStreamHandler.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessControlException.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedActionException.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/util/Arrays.h>
#include <java/util/Enumeration.h>
#include <java/util/HashMap.h>
#include <java/util/HashSet.h>
#include <java/util/LinkedList.h>
#include <java/util/Set.h>
#include <java/util/StringTokenizer.h>
#include <java/util/jar/Attributes$Name.h>
#include <java/util/jar/Attributes.h>
#include <java/util/jar/JarEntry.h>
#include <java/util/jar/JarFile.h>
#include <java/util/jar/Manifest.h>
#include <java/util/zip/ZipEntry.h>
#include <java/util/zip/ZipFile.h>
#include <jdk/internal/access/JavaUtilJarAccess.h>
#include <jdk/internal/access/JavaUtilZipFileAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jdk/internal/loader/FileURLMapper.h>
#include <jdk/internal/loader/Resource.h>
#include <jdk/internal/loader/URLClassPath$JarLoader$1.h>
#include <jdk/internal/loader/URLClassPath$JarLoader$2.h>
#include <jdk/internal/loader/URLClassPath$JarLoader$3.h>
#include <jdk/internal/loader/URLClassPath$Loader.h>
#include <jdk/internal/loader/URLClassPath.h>
#include <jdk/internal/util/jar/InvalidJarIndexError.h>
#include <jdk/internal/util/jar/JarIndex.h>
#include <sun/net/util/URLUtil.h>
#include <sun/net/www/ParseUtil.h>
#include <jcpp.h>

#undef CLASS_PATH
#undef DEBUG_CP_URL_CHECK
#undef DISABLE_CP_URL_CHECK
#undef DISABLE_JAR_CHECKING
#undef JAVA_VERSION
#undef OPEN_READ

using $URLArray = $Array<::java::net::URL>;
using $File = ::java::io::File;
using $FileNotFoundException = ::java::io::FileNotFoundException;
using $IOException = ::java::io::IOException;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $JarURLConnection = ::java::net::JarURLConnection;
using $MalformedURLException = ::java::net::MalformedURLException;
using $URI = ::java::net::URI;
using $URL = ::java::net::URL;
using $URLConnection = ::java::net::URLConnection;
using $URLStreamHandler = ::java::net::URLStreamHandler;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessControlException = ::java::security::AccessControlException;
using $AccessController = ::java::security::AccessController;
using $PrivilegedActionException = ::java::security::PrivilegedActionException;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $Arrays = ::java::util::Arrays;
using $Enumeration = ::java::util::Enumeration;
using $HashMap = ::java::util::HashMap;
using $HashSet = ::java::util::HashSet;
using $LinkedList = ::java::util::LinkedList;
using $Set = ::java::util::Set;
using $StringTokenizer = ::java::util::StringTokenizer;
using $Attributes = ::java::util::jar::Attributes;
using $Attributes$Name = ::java::util::jar::Attributes$Name;
using $JarEntry = ::java::util::jar::JarEntry;
using $JarFile = ::java::util::jar::JarFile;
using $Manifest = ::java::util::jar::Manifest;
using $ZipEntry = ::java::util::zip::ZipEntry;
using $ZipFile = ::java::util::zip::ZipFile;
using $JavaUtilJarAccess = ::jdk::internal::access::JavaUtilJarAccess;
using $JavaUtilZipFileAccess = ::jdk::internal::access::JavaUtilZipFileAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $FileURLMapper = ::jdk::internal::loader::FileURLMapper;
using $Resource = ::jdk::internal::loader::Resource;
using $URLClassPath = ::jdk::internal::loader::URLClassPath;
using $URLClassPath$JarLoader$1 = ::jdk::internal::loader::URLClassPath$JarLoader$1;
using $URLClassPath$JarLoader$2 = ::jdk::internal::loader::URLClassPath$JarLoader$2;
using $URLClassPath$JarLoader$3 = ::jdk::internal::loader::URLClassPath$JarLoader$3;
using $URLClassPath$Loader = ::jdk::internal::loader::URLClassPath$Loader;
using $InvalidJarIndexError = ::jdk::internal::util::jar::InvalidJarIndexError;
using $JarIndex = ::jdk::internal::util::jar::JarIndex;
using $URLUtil = ::sun::net::util::URLUtil;
using $ParseUtil = ::sun::net::www::ParseUtil;

namespace jdk {
	namespace internal {
		namespace loader {

$FieldInfo _URLClassPath$JarLoader_FieldInfo_[] = {
	{"jar", "Ljava/util/jar/JarFile;", nullptr, $PRIVATE, $field(URLClassPath$JarLoader, jar)},
	{"csu", "Ljava/net/URL;", nullptr, $PRIVATE | $FINAL, $field(URLClassPath$JarLoader, csu)},
	{"index", "Ljdk/internal/util/jar/JarIndex;", nullptr, $PRIVATE, $field(URLClassPath$JarLoader, index)},
	{"handler", "Ljava/net/URLStreamHandler;", nullptr, $PRIVATE, $field(URLClassPath$JarLoader, handler)},
	{"lmap", "Ljava/util/HashMap;", "Ljava/util/HashMap<Ljava/lang/String;Ljdk/internal/loader/URLClassPath$Loader;>;", $PRIVATE | $FINAL, $field(URLClassPath$JarLoader, lmap)},
	{"acc", "Ljava/security/AccessControlContext;", nullptr, $PRIVATE | $FINAL, $field(URLClassPath$JarLoader, acc)},
	{"closed", "Z", nullptr, $PRIVATE, $field(URLClassPath$JarLoader, closed)},
	{"zipAccess", "Ljdk/internal/access/JavaUtilZipFileAccess;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(URLClassPath$JarLoader, zipAccess)},
	{}
};

$MethodInfo _URLClassPath$JarLoader_MethodInfo_[] = {
	{"<init>", "(Ljava/net/URL;Ljava/net/URLStreamHandler;Ljava/util/HashMap;Ljava/security/AccessControlContext;)V", "(Ljava/net/URL;Ljava/net/URLStreamHandler;Ljava/util/HashMap<Ljava/lang/String;Ljdk/internal/loader/URLClassPath$Loader;>;Ljava/security/AccessControlContext;)V", $PRIVATE, $method(URLClassPath$JarLoader, init$, void, $URL*, $URLStreamHandler*, $HashMap*, $AccessControlContext*), "java.io.IOException"},
	{"checkJar", "(Ljava/util/jar/JarFile;)Ljava/util/jar/JarFile;", nullptr, $STATIC, $staticMethod(URLClassPath$JarLoader, checkJar, $JarFile*, $JarFile*), "java.io.IOException"},
	{"checkResource", "(Ljava/lang/String;ZLjava/util/jar/JarEntry;)Ljdk/internal/loader/Resource;", nullptr, 0, $virtualMethod(URLClassPath$JarLoader, checkResource, $Resource*, $String*, bool, $JarEntry*)},
	{"close", "()V", nullptr, $PUBLIC, $virtualMethod(URLClassPath$JarLoader, close, void), "java.io.IOException"},
	{"ensureOpen", "()V", nullptr, $PRIVATE, $method(URLClassPath$JarLoader, ensureOpen, void), "java.io.IOException"},
	{"findResource", "(Ljava/lang/String;Z)Ljava/net/URL;", nullptr, 0, $virtualMethod(URLClassPath$JarLoader, findResource, $URL*, $String*, bool)},
	{"getClassPath", "()[Ljava/net/URL;", nullptr, 0, $virtualMethod(URLClassPath$JarLoader, getClassPath, $URLArray*), "java.io.IOException"},
	{"getIndex", "()Ljdk/internal/util/jar/JarIndex;", nullptr, 0, $virtualMethod(URLClassPath$JarLoader, getIndex, $JarIndex*)},
	{"getJarFile", "()Ljava/util/jar/JarFile;", nullptr, 0, $virtualMethod(URLClassPath$JarLoader, getJarFile, $JarFile*)},
	{"getJarFile", "(Ljava/net/URL;)Ljava/util/jar/JarFile;", nullptr, $PRIVATE, $method(URLClassPath$JarLoader, getJarFile, $JarFile*, $URL*), "java.io.IOException"},
	{"getResource", "(Ljava/lang/String;Z)Ljdk/internal/loader/Resource;", nullptr, 0, $virtualMethod(URLClassPath$JarLoader, getResource, $Resource*, $String*, bool)},
	{"getResource", "(Ljava/lang/String;ZLjava/util/Set;)Ljdk/internal/loader/Resource;", "(Ljava/lang/String;ZLjava/util/Set<Ljava/lang/String;>;)Ljdk/internal/loader/Resource;", 0, $virtualMethod(URLClassPath$JarLoader, getResource, $Resource*, $String*, bool, $Set*)},
	{"isOptimizable", "(Ljava/net/URL;)Z", nullptr, $PRIVATE, $method(URLClassPath$JarLoader, isOptimizable, bool, $URL*)},
	{"isRelative", "(Ljava/lang/String;)Z", nullptr, $STATIC, $staticMethod(URLClassPath$JarLoader, isRelative, bool, $String*)},
	{"parseClassPath", "(Ljava/net/URL;Ljava/lang/String;)[Ljava/net/URL;", nullptr, $PRIVATE | $STATIC, $staticMethod(URLClassPath$JarLoader, parseClassPath, $URLArray*, $URL*, $String*), "java.net.MalformedURLException"},
	{"tryResolve", "(Ljava/net/URL;Ljava/lang/String;)Ljava/net/URL;", nullptr, $STATIC, $staticMethod(URLClassPath$JarLoader, tryResolve, $URL*, $URL*, $String*), "java.net.MalformedURLException"},
	{"tryResolveFile", "(Ljava/net/URL;Ljava/lang/String;)Ljava/net/URL;", nullptr, $STATIC, $staticMethod(URLClassPath$JarLoader, tryResolveFile, $URL*, $URL*, $String*), "java.net.MalformedURLException"},
	{"tryResolveNonFile", "(Ljava/net/URL;Ljava/lang/String;)Ljava/net/URL;", nullptr, $STATIC, $staticMethod(URLClassPath$JarLoader, tryResolveNonFile, $URL*, $URL*, $String*), "java.net.MalformedURLException"},
	{"validIndex", "(Ljava/lang/String;)Z", nullptr, 0, $virtualMethod(URLClassPath$JarLoader, validIndex, bool, $String*)},
	{}
};

$InnerClassInfo _URLClassPath$JarLoader_InnerClassesInfo_[] = {
	{"jdk.internal.loader.URLClassPath$JarLoader", "jdk.internal.loader.URLClassPath", "JarLoader", $PRIVATE | $STATIC},
	{"jdk.internal.loader.URLClassPath$Loader", "jdk.internal.loader.URLClassPath", "Loader", $PRIVATE | $STATIC},
	{"jdk.internal.loader.URLClassPath$JarLoader$3", nullptr, nullptr, 0},
	{"jdk.internal.loader.URLClassPath$JarLoader$2", nullptr, nullptr, 0},
	{"jdk.internal.loader.URLClassPath$JarLoader$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _URLClassPath$JarLoader_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.loader.URLClassPath$JarLoader",
	"jdk.internal.loader.URLClassPath$Loader",
	nullptr,
	_URLClassPath$JarLoader_FieldInfo_,
	_URLClassPath$JarLoader_MethodInfo_,
	nullptr,
	nullptr,
	_URLClassPath$JarLoader_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.loader.URLClassPath"
};

$Object* allocate$URLClassPath$JarLoader($Class* clazz) {
	return $of($alloc(URLClassPath$JarLoader));
}

$JavaUtilZipFileAccess* URLClassPath$JarLoader::zipAccess = nullptr;

void URLClassPath$JarLoader::init$($URL* url, $URLStreamHandler* jarHandler, $HashMap* loaderMap, $AccessControlContext* acc) {
	$useLocalCurrentObjectStackCache();
	$URLClassPath$Loader::init$($$new($URL, "jar"_s, ""_s, -1, $$str({url, "!/"_s}), jarHandler));
	this->closed = false;
	$set(this, csu, url);
	$set(this, handler, jarHandler);
	$set(this, lmap, loaderMap);
	$set(this, acc, acc);
	ensureOpen();
}

void URLClassPath$JarLoader::close() {
	if (!this->closed) {
		this->closed = true;
		ensureOpen();
		$nc(this->jar)->close();
	}
}

$JarFile* URLClassPath$JarLoader::getJarFile() {
	return this->jar;
}

bool URLClassPath$JarLoader::isOptimizable($URL* url) {
	return "file"_s->equals($($nc(url)->getProtocol()));
}

void URLClassPath$JarLoader::ensureOpen() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (this->jar == nullptr) {
		try {
			$AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new($URLClassPath$JarLoader$1, this)), this->acc);
		} catch ($PrivilegedActionException& pae) {
			$throw($cast($IOException, $(pae->getException())));
		}
	}
}

$JarFile* URLClassPath$JarLoader::checkJar($JarFile* jar) {
	$init(URLClassPath$JarLoader);
	$init($URLClassPath);
	bool var$0 = $System::getSecurityManager() != nullptr && !$URLClassPath::DISABLE_JAR_CHECKING;
	if (var$0 && !$nc(URLClassPath$JarLoader::zipAccess)->startsWithLocHeader(jar)) {
		$var($IOException, x, $new($IOException, "Invalid Jar file"_s));
		try {
			$nc(jar)->close();
		} catch ($IOException& ex) {
			x->addSuppressed(ex);
		}
		$throw(x);
	}
	return jar;
}

$JarFile* URLClassPath$JarLoader::getJarFile($URL* url) {
	$useLocalCurrentObjectStackCache();
	if (isOptimizable(url)) {
		$var($FileURLMapper, p, $new($FileURLMapper, url));
		if (!p->exists()) {
			$throwNew($FileNotFoundException, $(p->getPath()));
		}
		$var($File, var$0, $new($File, $(p->getPath())));
		return checkJar($$new($JarFile, var$0, true, $ZipFile::OPEN_READ, $($JarFile::runtimeVersion())));
	}
	$var($URLConnection, uc, ($$new($URL, $(getBaseURL()), "#runtime"_s))->openConnection());
	$init($URLClassPath);
	$nc(uc)->setRequestProperty("UA-Java-Version"_s, $URLClassPath::JAVA_VERSION);
	$var($JarFile, jarFile, $nc(($cast($JarURLConnection, uc)))->getJarFile());
	return checkJar(jarFile);
}

$JarIndex* URLClassPath$JarLoader::getIndex() {
	try {
		ensureOpen();
	} catch ($IOException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	}
	return this->index;
}

$Resource* URLClassPath$JarLoader::checkResource($String* name, bool check, $JarEntry* entry) {
	$useLocalCurrentObjectStackCache();
	$var($URL, url, nullptr);
	try {
		$var($String, nm, nullptr);
		if ($nc(this->jar)->isMultiRelease()) {
			$assign(nm, $nc(entry)->getRealName());
		} else {
			$assign(nm, name);
		}
		$var($URL, var$0, getBaseURL());
		$assign(url, $new($URL, var$0, $($ParseUtil::encodePath(nm, false))));
		if (check) {
			$URLClassPath::check(url);
		}
	} catch ($MalformedURLException& e) {
		return nullptr;
	} catch ($IOException& e) {
		return nullptr;
	} catch ($AccessControlException& e) {
		return nullptr;
	}
	return $new($URLClassPath$JarLoader$2, this, name, url, entry);
}

bool URLClassPath$JarLoader::validIndex($String* name) {
	$useLocalCurrentObjectStackCache();
	$var($String, packageName, name);
	int32_t pos = 0;
	if ((pos = $nc(name)->lastIndexOf((int32_t)u'/')) != -1) {
		$assign(packageName, name->substring(0, pos));
	}
	$var($String, entryName, nullptr);
	$var($ZipEntry, entry, nullptr);
	$var($Enumeration, enum_, $nc(this->jar)->entries());
	while ($nc(enum_)->hasMoreElements()) {
		$assign(entry, $cast($ZipEntry, enum_->nextElement()));
		$assign(entryName, $nc(entry)->getName());
		if ((pos = $nc(entryName)->lastIndexOf((int32_t)u'/')) != -1) {
			$assign(entryName, entryName->substring(0, pos));
		}
		if ($nc(entryName)->equals(packageName)) {
			return true;
		}
	}
	return false;
}

$URL* URLClassPath$JarLoader::findResource($String* name, bool check) {
	$var($Resource, rsc, getResource(name, check));
	if (rsc != nullptr) {
		return rsc->getURL();
	}
	return nullptr;
}

$Resource* URLClassPath$JarLoader::getResource($String* name, bool check) {
	$useLocalCurrentObjectStackCache();
	try {
		ensureOpen();
	} catch ($IOException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	}
	$var($JarEntry, entry, $nc(this->jar)->getJarEntry(name));
	if (entry != nullptr) {
		return checkResource(name, check, entry);
	}
	if (this->index == nullptr) {
		return nullptr;
	}
	$var($HashSet, visited, $new($HashSet));
	return getResource(name, check, visited);
}

$Resource* URLClassPath$JarLoader::getResource($String* name, bool check, $Set* visited) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($Resource, res, nullptr);
	$var($StringArray, jarFiles, nullptr);
	int32_t count = 0;
	$var($LinkedList, jarFilesList, nullptr);
	if (($assign(jarFilesList, $nc(this->index)->get(name))) == nullptr) {
		return nullptr;
	}
	do {
		int32_t size = $nc(jarFilesList)->size();
		$assign(jarFiles, $fcast($StringArray, jarFilesList->toArray($$new($StringArray, size))));
		while (count < size) {
			$var($String, jarName, $nc(jarFiles)->get(count++));
			$var(URLClassPath$JarLoader, newLoader, nullptr);
			$var($URL, url, nullptr);
			try {
				$assign(url, $new($URL, this->csu, jarName));
				$var($String, urlNoFragString, $URLUtil::urlNoFragString(url));
				if (($assign(newLoader, $cast(URLClassPath$JarLoader, $nc(this->lmap)->get(urlNoFragString)))) == nullptr) {
					$assign(newLoader, $cast(URLClassPath$JarLoader, $AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new($URLClassPath$JarLoader$3, this, url)), this->acc)));
					$var($JarIndex, newIndex, $nc(newLoader)->getIndex());
					if (newIndex != nullptr) {
						int32_t pos = $nc(jarName)->lastIndexOf((int32_t)u'/');
						newIndex->merge(this->index, (pos == -1 ? ($String*)nullptr : $(jarName->substring(0, pos + 1))));
					}
					$nc(this->lmap)->put(urlNoFragString, newLoader);
				}
			} catch ($PrivilegedActionException& pae) {
				continue;
			} catch ($MalformedURLException& e) {
				continue;
			}
			bool visitedURL = !$nc(visited)->add($($URLUtil::urlNoFragString(url)));
			if (!visitedURL) {
				try {
					$nc(newLoader)->ensureOpen();
				} catch ($IOException& e) {
					$throwNew($InternalError, static_cast<$Throwable*>(e));
				}
				$var($JarEntry, entry, $nc($nc(newLoader)->jar)->getJarEntry(name));
				if (entry != nullptr) {
					return newLoader->checkResource(name, check, entry);
				}
				if (!newLoader->validIndex(name)) {
					$throwNew($InvalidJarIndexError, "Invalid index"_s);
				}
			}
			if (visitedURL || newLoader == this || $nc(newLoader)->getIndex() == nullptr) {
				continue;
			}
			if (($assign(res, $nc(newLoader)->getResource(name, check, visited))) != nullptr) {
				return res;
			}
		}
		$assign(jarFilesList, $nc(this->index)->get(name));
	} while (count < $nc(jarFilesList)->size());
	return nullptr;
}

$URLArray* URLClassPath$JarLoader::getClassPath() {
	$useLocalCurrentObjectStackCache();
	if (this->index != nullptr) {
		return nullptr;
	}
	ensureOpen();
	if ($nc($($SharedSecrets::javaUtilJarAccess()))->jarFileHasClassPathAttribute(this->jar)) {
		$var($Manifest, man, $nc(this->jar)->getManifest());
		if (man != nullptr) {
			$var($Attributes, attr, man->getMainAttributes());
			if (attr != nullptr) {
				$init($Attributes$Name);
				$var($String, value, attr->getValue($Attributes$Name::CLASS_PATH));
				if (value != nullptr) {
					return parseClassPath(this->csu, value);
				}
			}
		}
	}
	return nullptr;
}

$URLArray* URLClassPath$JarLoader::parseClassPath($URL* base, $String* value) {
	$init(URLClassPath$JarLoader);
	$useLocalCurrentObjectStackCache();
	$var($StringTokenizer, st, $new($StringTokenizer, value));
	$var($URLArray, urls, $new($URLArray, st->countTokens()));
	int32_t i = 0;
	while (st->hasMoreTokens()) {
		$var($String, path, st->nextToken());
		$init($URLClassPath);
		$var($URL, url, $URLClassPath::DISABLE_CP_URL_CHECK ? $new($URL, base, path) : tryResolve(base, path));
		if (url != nullptr) {
			urls->set(i, url);
			++i;
		} else {
			if ($URLClassPath::DEBUG_CP_URL_CHECK) {
				$nc($System::err)->println($$str({"Class-Path entry: \""_s, path, "\" ignored in JAR file "_s, base}));
			}
		}
	}
	if (i == 0) {
		$assign(urls, nullptr);
	} else if (i != urls->length) {
		$assign(urls, $fcast($URLArray, $Arrays::copyOf(urls, i)));
	}
	return urls;
}

$URL* URLClassPath$JarLoader::tryResolve($URL* base, $String* input) {
	$init(URLClassPath$JarLoader);
	if ("file"_s->equalsIgnoreCase($($nc(base)->getProtocol()))) {
		return tryResolveFile(base, input);
	} else {
		return tryResolveNonFile(base, input);
	}
}

$URL* URLClassPath$JarLoader::tryResolveFile($URL* base, $String* input) {
	$init(URLClassPath$JarLoader);
	$useLocalCurrentObjectStackCache();
	$var($URL, retVal, $new($URL, base, input));
	bool var$0 = $nc(input)->indexOf((int32_t)u':') >= 0;
	if (var$0 && !"file"_s->equalsIgnoreCase($(retVal->getProtocol()))) {
		return nullptr;
	}
	return retVal;
}

$URL* URLClassPath$JarLoader::tryResolveNonFile($URL* base, $String* input) {
	$init(URLClassPath$JarLoader);
	$useLocalCurrentObjectStackCache();
	$init($File);
	$var($String, child, $nc(input)->replace($File::separatorChar, u'/'));
	if (isRelative(child)) {
		$var($URL, url, $new($URL, base, child));
		$var($String, bp, $nc(base)->getPath());
		$var($String, urlp, url->getPath());
		int32_t pos = $nc(bp)->lastIndexOf((int32_t)u'/');
		if (pos == -1) {
			pos = bp->length() - 1;
		}
		bool var$0 = $nc(urlp)->regionMatches(0, bp, 0, pos + 1);
		if (var$0 && urlp->indexOf(".."_s, pos) == -1) {
			return url;
		}
	}
	return nullptr;
}

bool URLClassPath$JarLoader::isRelative($String* child) {
	$init(URLClassPath$JarLoader);
	try {
		return !$nc($($URI::create(child)))->isAbsolute();
	} catch ($IllegalArgumentException& e) {
		return false;
	}
	$shouldNotReachHere();
}

void clinit$URLClassPath$JarLoader($Class* class$) {
	$assignStatic(URLClassPath$JarLoader::zipAccess, $SharedSecrets::getJavaUtilZipFileAccess());
}

URLClassPath$JarLoader::URLClassPath$JarLoader() {
}

$Class* URLClassPath$JarLoader::load$($String* name, bool initialize) {
	$loadClass(URLClassPath$JarLoader, name, initialize, &_URLClassPath$JarLoader_ClassInfo_, clinit$URLClassPath$JarLoader, allocate$URLClassPath$JarLoader);
	return class$;
}

$Class* URLClassPath$JarLoader::class$ = nullptr;

		} // loader
	} // internal
} // jdk