#include <jdk/internal/loader/URLClassPath.h>

#include <java/io/File.h>
#include <java/io/FilePermission.h>
#include <java/io/IOException.h>
#include <java/lang/SecurityException.h>
#include <java/lang/SecurityManager.h>
#include <java/net/JarURLConnection.h>
#include <java/net/SocketPermission.h>
#include <java/net/URL.h>
#include <java/net/URLConnection.h>
#include <java/net/URLStreamHandler.h>
#include <java/net/URLStreamHandlerFactory.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedActionException.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/util/ArrayDeque.h>
#include <java/util/ArrayList.h>
#include <java/util/Collections.h>
#include <java/util/Enumeration.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedList.h>
#include <java/util/List.h>
#include <java/util/Properties.h>
#include <jdk/internal/access/JavaNetURLAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jdk/internal/loader/Resource.h>
#include <jdk/internal/loader/URLClassPath$1.h>
#include <jdk/internal/loader/URLClassPath$2.h>
#include <jdk/internal/loader/URLClassPath$3.h>
#include <jdk/internal/loader/URLClassPath$Loader.h>
#include <sun/net/util/URLUtil.h>
#include <sun/net/www/ParseUtil.h>
#include <sun/net/www/protocol/jar/Handler.h>
#include <sun/security/action/GetPropertyAction.h>
#include <jcpp.h>

#undef DEBUG
#undef DEBUG_CP_URL_CHECK
#undef DISABLE_ACC_CHECKING
#undef DISABLE_CP_URL_CHECK
#undef DISABLE_JAR_CHECKING
#undef JAVA_VERSION
#undef JNUA
#undef USER_AGENT_JAVA_VERSION

using $URLArray = $Array<::java::net::URL>;
using $File = ::java::io::File;
using $FilePermission = ::java::io::FilePermission;
using $IOException = ::java::io::IOException;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $SecurityException = ::java::lang::SecurityException;
using $SecurityManager = ::java::lang::SecurityManager;
using $JarURLConnection = ::java::net::JarURLConnection;
using $SocketPermission = ::java::net::SocketPermission;
using $URL = ::java::net::URL;
using $URLConnection = ::java::net::URLConnection;
using $URLStreamHandler = ::java::net::URLStreamHandler;
using $URLStreamHandlerFactory = ::java::net::URLStreamHandlerFactory;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $Permission = ::java::security::Permission;
using $PrivilegedActionException = ::java::security::PrivilegedActionException;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $ArrayDeque = ::java::util::ArrayDeque;
using $ArrayList = ::java::util::ArrayList;
using $Collections = ::java::util::Collections;
using $Enumeration = ::java::util::Enumeration;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $LinkedList = ::java::util::LinkedList;
using $List = ::java::util::List;
using $Properties = ::java::util::Properties;
using $JavaNetURLAccess = ::jdk::internal::access::JavaNetURLAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $Resource = ::jdk::internal::loader::Resource;
using $URLClassPath$1 = ::jdk::internal::loader::URLClassPath$1;
using $URLClassPath$2 = ::jdk::internal::loader::URLClassPath$2;
using $URLClassPath$3 = ::jdk::internal::loader::URLClassPath$3;
using $URLClassPath$Loader = ::jdk::internal::loader::URLClassPath$Loader;
using $URLUtil = ::sun::net::util::URLUtil;
using $ParseUtil = ::sun::net::www::ParseUtil;
using $Handler = ::sun::net::www::protocol::jar::Handler;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;

namespace jdk {
	namespace internal {
		namespace loader {

$FieldInfo _URLClassPath_FieldInfo_[] = {
	{"USER_AGENT_JAVA_VERSION", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(URLClassPath, USER_AGENT_JAVA_VERSION)},
	{"JAVA_VERSION", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(URLClassPath, JAVA_VERSION)},
	{"DEBUG", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(URLClassPath, DEBUG)},
	{"DISABLE_JAR_CHECKING", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(URLClassPath, DISABLE_JAR_CHECKING)},
	{"DISABLE_ACC_CHECKING", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(URLClassPath, DISABLE_ACC_CHECKING)},
	{"DISABLE_CP_URL_CHECK", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(URLClassPath, DISABLE_CP_URL_CHECK)},
	{"DEBUG_CP_URL_CHECK", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(URLClassPath, DEBUG_CP_URL_CHECK)},
	{"path", "Ljava/util/ArrayList;", "Ljava/util/ArrayList<Ljava/net/URL;>;", $PRIVATE | $FINAL, $field(URLClassPath, path)},
	{"unopenedUrls", "Ljava/util/ArrayDeque;", "Ljava/util/ArrayDeque<Ljava/net/URL;>;", $PRIVATE | $FINAL, $field(URLClassPath, unopenedUrls)},
	{"loaders", "Ljava/util/ArrayList;", "Ljava/util/ArrayList<Ljdk/internal/loader/URLClassPath$Loader;>;", $PRIVATE | $FINAL, $field(URLClassPath, loaders)},
	{"lmap", "Ljava/util/HashMap;", "Ljava/util/HashMap<Ljava/lang/String;Ljdk/internal/loader/URLClassPath$Loader;>;", $PRIVATE | $FINAL, $field(URLClassPath, lmap)},
	{"jarHandler", "Ljava/net/URLStreamHandler;", nullptr, $PRIVATE | $FINAL, $field(URLClassPath, jarHandler)},
	{"closed", "Z", nullptr, $PRIVATE, $field(URLClassPath, closed)},
	{"acc", "Ljava/security/AccessControlContext;", nullptr, $PRIVATE | $FINAL, $field(URLClassPath, acc)},
	{"JNUA", "Ljdk/internal/access/JavaNetURLAccess;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(URLClassPath, JNUA)},
	{}
};

$MethodInfo _URLClassPath_MethodInfo_[] = {
	{"<init>", "([Ljava/net/URL;Ljava/net/URLStreamHandlerFactory;Ljava/security/AccessControlContext;)V", nullptr, $PUBLIC, $method(URLClassPath, init$, void, $URLArray*, $URLStreamHandlerFactory*, $AccessControlContext*)},
	{"<init>", "([Ljava/net/URL;Ljava/security/AccessControlContext;)V", nullptr, $PUBLIC, $method(URLClassPath, init$, void, $URLArray*, $AccessControlContext*)},
	{"<init>", "(Ljava/lang/String;Z)V", nullptr, 0, $method(URLClassPath, init$, void, $String*, bool)},
	{"addFile", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(URLClassPath, addFile, void, $String*)},
	{"addURL", "(Ljava/net/URL;)V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(URLClassPath, addURL, void, $URL*)},
	{"check", "(Ljava/net/URL;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(URLClassPath, check, void, $URL*), "java.io.IOException"},
	{"checkURL", "(Ljava/net/URL;)Ljava/net/URL;", nullptr, $PUBLIC | $STATIC, $staticMethod(URLClassPath, checkURL, $URL*, $URL*)},
	{"closeLoaders", "()Ljava/util/List;", "()Ljava/util/List<Ljava/io/IOException;>;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(URLClassPath, closeLoaders, $List*)},
	{"findResource", "(Ljava/lang/String;Z)Ljava/net/URL;", nullptr, $PUBLIC, $virtualMethod(URLClassPath, findResource, $URL*, $String*, bool)},
	{"findResources", "(Ljava/lang/String;Z)Ljava/util/Enumeration;", "(Ljava/lang/String;Z)Ljava/util/Enumeration<Ljava/net/URL;>;", $PUBLIC, $virtualMethod(URLClassPath, findResources, $Enumeration*, $String*, bool)},
	{"getLoader", "(I)Ljdk/internal/loader/URLClassPath$Loader;", nullptr, $PRIVATE | $SYNCHRONIZED, $method(URLClassPath, getLoader, $URLClassPath$Loader*, int32_t)},
	{"getLoader", "(Ljava/net/URL;)Ljdk/internal/loader/URLClassPath$Loader;", nullptr, $PRIVATE, $method(URLClassPath, getLoader, $URLClassPath$Loader*, $URL*), "java.io.IOException"},
	{"getResource", "(Ljava/lang/String;Z)Ljdk/internal/loader/Resource;", nullptr, $PUBLIC, $virtualMethod(URLClassPath, getResource, $Resource*, $String*, bool)},
	{"getResource", "(Ljava/lang/String;)Ljdk/internal/loader/Resource;", nullptr, $PUBLIC, $virtualMethod(URLClassPath, getResource, $Resource*, $String*)},
	{"getResources", "(Ljava/lang/String;Z)Ljava/util/Enumeration;", "(Ljava/lang/String;Z)Ljava/util/Enumeration<Ljdk/internal/loader/Resource;>;", $PUBLIC, $virtualMethod(URLClassPath, getResources, $Enumeration*, $String*, bool)},
	{"getResources", "(Ljava/lang/String;)Ljava/util/Enumeration;", "(Ljava/lang/String;)Ljava/util/Enumeration<Ljdk/internal/loader/Resource;>;", $PUBLIC, $virtualMethod(URLClassPath, getResources, $Enumeration*, $String*)},
	{"getURLs", "()[Ljava/net/URL;", nullptr, $PUBLIC, $virtualMethod(URLClassPath, getURLs, $URLArray*)},
	{"isDefaultJarHandler", "(Ljava/net/URL;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(URLClassPath, isDefaultJarHandler, bool, $URL*)},
	{"push", "([Ljava/net/URL;)V", nullptr, $PRIVATE, $method(URLClassPath, push, void, $URLArray*)},
	{"toFileURL", "(Ljava/lang/String;)Ljava/net/URL;", nullptr, $PRIVATE | $STATIC, $staticMethod(URLClassPath, toFileURL, $URL*, $String*)},
	{}
};

$InnerClassInfo _URLClassPath_InnerClassesInfo_[] = {
	{"jdk.internal.loader.URLClassPath$FileLoader", "jdk.internal.loader.URLClassPath", "FileLoader", $PRIVATE | $STATIC},
	{"jdk.internal.loader.URLClassPath$JarLoader", "jdk.internal.loader.URLClassPath", "JarLoader", $PRIVATE | $STATIC},
	{"jdk.internal.loader.URLClassPath$Loader", "jdk.internal.loader.URLClassPath", "Loader", $PRIVATE | $STATIC},
	{"jdk.internal.loader.URLClassPath$3", nullptr, nullptr, 0},
	{"jdk.internal.loader.URLClassPath$2", nullptr, nullptr, 0},
	{"jdk.internal.loader.URLClassPath$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _URLClassPath_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.loader.URLClassPath",
	"java.lang.Object",
	nullptr,
	_URLClassPath_FieldInfo_,
	_URLClassPath_MethodInfo_,
	nullptr,
	nullptr,
	_URLClassPath_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.loader.URLClassPath$FileLoader,jdk.internal.loader.URLClassPath$FileLoader$1,jdk.internal.loader.URLClassPath$JarLoader,jdk.internal.loader.URLClassPath$JarLoader$3,jdk.internal.loader.URLClassPath$JarLoader$2,jdk.internal.loader.URLClassPath$JarLoader$1,jdk.internal.loader.URLClassPath$Loader,jdk.internal.loader.URLClassPath$Loader$1,jdk.internal.loader.URLClassPath$3,jdk.internal.loader.URLClassPath$2,jdk.internal.loader.URLClassPath$1"
};

$Object* allocate$URLClassPath($Class* clazz) {
	return $of($alloc(URLClassPath));
}

$String* URLClassPath::USER_AGENT_JAVA_VERSION = nullptr;
$String* URLClassPath::JAVA_VERSION = nullptr;
bool URLClassPath::DEBUG = false;
bool URLClassPath::DISABLE_JAR_CHECKING = false;
bool URLClassPath::DISABLE_ACC_CHECKING = false;
bool URLClassPath::DISABLE_CP_URL_CHECK = false;
bool URLClassPath::DEBUG_CP_URL_CHECK = false;
$JavaNetURLAccess* URLClassPath::JNUA = nullptr;

void URLClassPath::init$($URLArray* urls, $URLStreamHandlerFactory* factory, $AccessControlContext* acc) {
	$useLocalCurrentObjectStackCache();
	$set(this, loaders, $new($ArrayList));
	$set(this, lmap, $new($HashMap));
	this->closed = false;
	$var($ArrayList, path, $new($ArrayList, $nc(urls)->length));
	$var($ArrayDeque, unopenedUrls, $new($ArrayDeque, $nc(urls)->length));
	{
		$var($URLArray, arr$, urls);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($URL, url, arr$->get(i$));
			{
				path->add(url);
				unopenedUrls->add(url);
			}
		}
	}
	$set(this, path, path);
	$set(this, unopenedUrls, unopenedUrls);
	if (factory != nullptr) {
		$set(this, jarHandler, factory->createURLStreamHandler("jar"_s));
	} else {
		$set(this, jarHandler, nullptr);
	}
	if (URLClassPath::DISABLE_ACC_CHECKING) {
		$set(this, acc, nullptr);
	} else {
		$set(this, acc, acc);
	}
}

void URLClassPath::init$($URLArray* urls, $AccessControlContext* acc) {
	URLClassPath::init$(urls, nullptr, acc);
}

void URLClassPath::init$($String* cp, bool skipEmptyElements) {
	$useLocalCurrentObjectStackCache();
	$set(this, loaders, $new($ArrayList));
	$set(this, lmap, $new($HashMap));
	this->closed = false;
	$var($ArrayList, path, $new($ArrayList));
	if (cp != nullptr) {
		int32_t off = 0;
		int32_t next = 0;
		do {
			$init($File);
			next = cp->indexOf($File::pathSeparator, off);
			$var($String, element, (next == -1) ? cp->substring(off) : cp->substring(off, next));
			if (!$nc(element)->isEmpty() || !skipEmptyElements) {
				$var($URL, url, toFileURL(element));
				if (url != nullptr) {
					path->add(url);
				}
			}
			off = next + 1;
		} while (next != -1);
	}
	int32_t size = path->size();
	$var($ArrayDeque, unopenedUrls, $new($ArrayDeque, size));
	for (int32_t i = 0; i < size; ++i) {
		unopenedUrls->add($cast($URL, $(path->get(i))));
	}
	$set(this, unopenedUrls, unopenedUrls);
	$set(this, path, path);
	$set(this, jarHandler, nullptr);
	$set(this, acc, nullptr);
}

$List* URLClassPath::closeLoaders() {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (this->closed) {
			return $Collections::emptyList();
		}
		$var($List, result, $new($LinkedList));
		{
			$var($Iterator, i$, $nc(this->loaders)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($URLClassPath$Loader, loader, $cast($URLClassPath$Loader, i$->next()));
				{
					try {
						$nc(loader)->close();
					} catch ($IOException& e) {
						result->add(e);
					}
				}
			}
		}
		this->closed = true;
		return result;
	}
}

void URLClassPath::addURL($URL* url) {
	$synchronized(this) {
		if (this->closed || url == nullptr) {
			return;
		}
		$synchronized(this->unopenedUrls) {
			if (!$nc(this->path)->contains(url)) {
				$nc(this->unopenedUrls)->addLast(url);
				$nc(this->path)->add(url);
			}
		}
	}
}

void URLClassPath::addFile($String* s) {
	$var($URL, url, toFileURL(s));
	if (url != nullptr) {
		addURL(url);
	}
}

$URL* URLClassPath::toFileURL($String* s) {
	$init(URLClassPath);
	$useLocalCurrentObjectStackCache();
	try {
		$var($File, f, $$new($File, s)->getCanonicalFile());
		return $ParseUtil::fileToEncodedURL(f);
	} catch ($IOException& e) {
		return nullptr;
	}
	$shouldNotReachHere();
}

$URLArray* URLClassPath::getURLs() {
	$synchronized(this->unopenedUrls) {
		return $fcast($URLArray, $nc(this->path)->toArray($$new($URLArray, 0)));
	}
}

$URL* URLClassPath::findResource($String* name, bool check) {
	$useLocalCurrentObjectStackCache();
	$var($URLClassPath$Loader, loader, nullptr);
	for (int32_t i = 0; ($assign(loader, getLoader(i))) != nullptr; ++i) {
		$var($URL, url, $nc(loader)->findResource(name, check));
		if (url != nullptr) {
			return url;
		}
	}
	return nullptr;
}

$Resource* URLClassPath::getResource($String* name, bool check) {
	$useLocalCurrentObjectStackCache();
	if (URLClassPath::DEBUG) {
		$nc($System::err)->println($$str({"URLClassPath.getResource(\""_s, name, "\")"_s}));
	}
	$var($URLClassPath$Loader, loader, nullptr);
	for (int32_t i = 0; ($assign(loader, getLoader(i))) != nullptr; ++i) {
		$var($Resource, res, $nc(loader)->getResource(name, check));
		if (res != nullptr) {
			return res;
		}
	}
	return nullptr;
}

$Enumeration* URLClassPath::findResources($String* name, bool check) {
	return $new($URLClassPath$1, this, name, check);
}

$Resource* URLClassPath::getResource($String* name) {
	return getResource(name, true);
}

$Enumeration* URLClassPath::getResources($String* name, bool check) {
	return $new($URLClassPath$2, this, name, check);
}

$Enumeration* URLClassPath::getResources($String* name) {
	return getResources(name, true);
}

$URLClassPath$Loader* URLClassPath::getLoader(int32_t index) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (this->closed) {
			return nullptr;
		}
		while ($nc(this->loaders)->size() < index + 1) {
			$var($URL, url, nullptr);
			$synchronized(this->unopenedUrls) {
				$assign(url, $cast($URL, $nc(this->unopenedUrls)->pollFirst()));
				if (url == nullptr) {
					return nullptr;
				}
			}
			$var($String, urlNoFragString, $URLUtil::urlNoFragString(url));
			if ($nc(this->lmap)->containsKey(urlNoFragString)) {
				continue;
			}
			$var($URLClassPath$Loader, loader, nullptr);
			try {
				$assign(loader, getLoader(url));
				$var($URLArray, urls, $nc(loader)->getClassPath());
				if (urls != nullptr) {
					push(urls);
				}
			} catch ($IOException& e) {
				continue;
			} catch ($SecurityException& se) {
				if (URLClassPath::DEBUG) {
					$nc($System::err)->println($$str({"Failed to access "_s, url, ", "_s, se}));
				}
				continue;
			}
			$nc(this->loaders)->add(loader);
			$nc(this->lmap)->put(urlNoFragString, loader);
		}
		return $cast($URLClassPath$Loader, $nc(this->loaders)->get(index));
	}
}

$URLClassPath$Loader* URLClassPath::getLoader($URL* url) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	try {
		return $cast($URLClassPath$Loader, $AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new($URLClassPath$3, this, url)), this->acc));
	} catch ($PrivilegedActionException& pae) {
		$throw($cast($IOException, $(pae->getException())));
	}
	$shouldNotReachHere();
}

bool URLClassPath::isDefaultJarHandler($URL* u) {
	$init(URLClassPath);
	$var($URLStreamHandler, h, $nc(URLClassPath::JNUA)->getHandler(u));
	return $instanceOf($Handler, h);
}

void URLClassPath::push($URLArray* urls) {
	$synchronized(this->unopenedUrls) {
		for (int32_t i = $nc(urls)->length - 1; i >= 0; --i) {
			$nc(this->unopenedUrls)->addFirst(urls->get(i));
		}
	}
}

$URL* URLClassPath::checkURL($URL* url) {
	$init(URLClassPath);
	if (url != nullptr) {
		try {
			check(url);
		} catch ($Exception& e) {
			return nullptr;
		}
	}
	return url;
}

void URLClassPath::check($URL* url) {
	$init(URLClassPath);
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, security, $System::getSecurityManager());
	if (security != nullptr) {
		$var($URLConnection, urlConnection, $nc(url)->openConnection());
		$var($Permission, perm, $nc(urlConnection)->getPermission());
		if (perm != nullptr) {
			try {
				security->checkPermission(perm);
			} catch ($SecurityException& se) {
				if (($instanceOf($FilePermission, perm)) && $nc($(perm->getActions()))->indexOf("read"_s) != -1) {
					security->checkRead($(perm->getName()));
				} else if (($instanceOf($SocketPermission, perm)) && $nc($(perm->getActions()))->indexOf("connect"_s) != -1) {
					$var($URL, locUrl, url);
					if ($instanceOf($JarURLConnection, urlConnection)) {
						$assign(locUrl, $nc(($cast($JarURLConnection, urlConnection)))->getJarFileURL());
					}
					$var($String, var$0, locUrl->getHost());
					security->checkConnect(var$0, locUrl->getPort());
				} else {
					$throw(se);
				}
			}
		}
	}
}

void clinit$URLClassPath($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(URLClassPath::USER_AGENT_JAVA_VERSION, "UA-Java-Version"_s);
	{
		$var($Properties, props, $GetPropertyAction::privilegedGetProperties());
		$assignStatic(URLClassPath::JAVA_VERSION, $nc(props)->getProperty("java.version"_s));
		URLClassPath::DEBUG = (props->getProperty("sun.misc.URLClassPath.debug"_s) != nullptr);
		$var($String, p, props->getProperty("sun.misc.URLClassPath.disableJarChecking"_s));
		bool var$0 = false;
		if (p != nullptr) {
			bool var$1 = $nc(p)->equals("true"_s);
			var$0 = var$1 || p->isEmpty();
		} else {
			var$0 = false;
		}
		URLClassPath::DISABLE_JAR_CHECKING = var$0;
		$assign(p, props->getProperty("jdk.net.URLClassPath.disableRestrictedPermissions"_s));
		bool var$2 = false;
		if (p != nullptr) {
			bool var$3 = $nc(p)->equals("true"_s);
			var$2 = var$3 || p->isEmpty();
		} else {
			var$2 = false;
		}
		URLClassPath::DISABLE_ACC_CHECKING = var$2;
		$assign(p, props->getProperty("jdk.net.URLClassPath.disableClassPathURLCheck"_s));
		bool var$4 = false;
		if (p != nullptr) {
			bool var$5 = $nc(p)->equals("true"_s);
			var$4 = var$5 || p->isEmpty();
		} else {
			var$4 = false;
		}
		URLClassPath::DISABLE_CP_URL_CHECK = var$4;
		$assign(p, props->getProperty("jdk.net.URLClassPath.showIgnoredClassPathEntries"_s));
		bool var$6 = false;
		if (p != nullptr) {
			bool var$7 = $nc(p)->equals("true"_s);
			var$6 = var$7 || p->isEmpty();
		} else {
			var$6 = false;
		}
		URLClassPath::DEBUG_CP_URL_CHECK = var$6;
	}
	$assignStatic(URLClassPath::JNUA, $SharedSecrets::getJavaNetURLAccess());
}

URLClassPath::URLClassPath() {
}

$Class* URLClassPath::load$($String* name, bool initialize) {
	$loadClass(URLClassPath, name, initialize, &_URLClassPath_ClassInfo_, clinit$URLClassPath, allocate$URLClassPath);
	return class$;
}

$Class* URLClassPath::class$ = nullptr;

		} // loader
	} // internal
} // jdk