#include <java/net/URLClassLoader.h>

#include <java/io/Closeable.h>
#include <java/io/File.h>
#include <java/io/FilePermission.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/lang/AssertionError.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/Package.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityException.h>
#include <java/lang/SecurityManager.h>
#include <java/net/JarURLConnection.h>
#include <java/net/SocketPermission.h>
#include <java/net/URL.h>
#include <java/net/URLClassLoader$1.h>
#include <java/net/URLClassLoader$2.h>
#include <java/net/URLClassLoader$3.h>
#include <java/net/URLClassLoader$4.h>
#include <java/net/URLClassLoader$5.h>
#include <java/net/URLClassLoader$6.h>
#include <java/net/URLConnection.h>
#include <java/net/URLStreamHandlerFactory.h>
#include <java/nio/ByteBuffer.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/CodeSigner.h>
#include <java/security/CodeSource.h>
#include <java/security/Permission.h>
#include <java/security/PermissionCollection.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/PrivilegedActionException.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/security/SecureClassLoader.h>
#include <java/util/Enumeration.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <java/util/Set.h>
#include <java/util/WeakHashMap.h>
#include <java/util/jar/Attributes$Name.h>
#include <java/util/jar/Attributes.h>
#include <java/util/jar/JarFile.h>
#include <java/util/jar/Manifest.h>
#include <jdk/internal/access/JavaUtilJarAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jdk/internal/loader/Resource.h>
#include <jdk/internal/loader/URLClassPath.h>
#include <jdk/internal/perf/PerfCounter.h>
#include <sun/net/www/ParseUtil.h>
#include <sun/net/www/protocol/file/FileURLConnection.h>
#include <sun/security/util/SecurityConstants.h>
#include <jcpp.h>

#undef FILE_READ_ACTION
#undef IMPLEMENTATION_TITLE
#undef IMPLEMENTATION_VENDOR
#undef IMPLEMENTATION_VERSION
#undef SEALED
#undef SOCKET_CONNECT_ACCEPT_ACTION
#undef SPECIFICATION_TITLE
#undef SPECIFICATION_VENDOR
#undef SPECIFICATION_VERSION

using $URLArray = $Array<::java::net::URL>;
using $CodeSignerArray = $Array<::java::security::CodeSigner>;
using $Closeable = ::java::io::Closeable;
using $File = ::java::io::File;
using $FilePermission = ::java::io::FilePermission;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Package = ::java::lang::Package;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityException = ::java::lang::SecurityException;
using $SecurityManager = ::java::lang::SecurityManager;
using $JarURLConnection = ::java::net::JarURLConnection;
using $SocketPermission = ::java::net::SocketPermission;
using $URL = ::java::net::URL;
using $URLClassLoader$1 = ::java::net::URLClassLoader$1;
using $URLClassLoader$2 = ::java::net::URLClassLoader$2;
using $URLClassLoader$3 = ::java::net::URLClassLoader$3;
using $URLClassLoader$4 = ::java::net::URLClassLoader$4;
using $URLClassLoader$5 = ::java::net::URLClassLoader$5;
using $URLClassLoader$6 = ::java::net::URLClassLoader$6;
using $URLConnection = ::java::net::URLConnection;
using $URLStreamHandlerFactory = ::java::net::URLStreamHandlerFactory;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $CodeSource = ::java::security::CodeSource;
using $Permission = ::java::security::Permission;
using $PermissionCollection = ::java::security::PermissionCollection;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $PrivilegedActionException = ::java::security::PrivilegedActionException;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $SecureClassLoader = ::java::security::SecureClassLoader;
using $Enumeration = ::java::util::Enumeration;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $Set = ::java::util::Set;
using $WeakHashMap = ::java::util::WeakHashMap;
using $Attributes = ::java::util::jar::Attributes;
using $Attributes$Name = ::java::util::jar::Attributes$Name;
using $JarFile = ::java::util::jar::JarFile;
using $Manifest = ::java::util::jar::Manifest;
using $JavaUtilJarAccess = ::jdk::internal::access::JavaUtilJarAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $Resource = ::jdk::internal::loader::Resource;
using $URLClassPath = ::jdk::internal::loader::URLClassPath;
using $PerfCounter = ::jdk::internal::perf::PerfCounter;
using $ParseUtil = ::sun::net::www::ParseUtil;
using $FileURLConnection = ::sun::net::www::protocol::file::FileURLConnection;
using $SecurityConstants = ::sun::security::util::SecurityConstants;

namespace java {
	namespace net {

$FieldInfo _URLClassLoader_FieldInfo_[] = {
	{"ucp", "Ljdk/internal/loader/URLClassPath;", nullptr, $PRIVATE | $FINAL, $field(URLClassLoader, ucp)},
	{"acc", "Ljava/security/AccessControlContext;", nullptr, $PRIVATE | $FINAL, $field(URLClassLoader, acc)},
	{"closeables", "Ljava/util/WeakHashMap;", "Ljava/util/WeakHashMap<Ljava/io/Closeable;Ljava/lang/Void;>;", $PRIVATE, $field(URLClassLoader, closeables)},
	{}
};

$MethodInfo _URLClassLoader_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "([Ljava/net/URL;Ljava/lang/ClassLoader;)V", nullptr, $PUBLIC, $method(URLClassLoader, init$, void, $URLArray*, $ClassLoader*)},
	{"<init>", "(Ljava/lang/String;[Ljava/net/URL;Ljava/lang/ClassLoader;Ljava/security/AccessControlContext;)V", nullptr, 0, $method(URLClassLoader, init$, void, $String*, $URLArray*, $ClassLoader*, $AccessControlContext*)},
	{"<init>", "([Ljava/net/URL;)V", nullptr, $PUBLIC, $method(URLClassLoader, init$, void, $URLArray*)},
	{"<init>", "([Ljava/net/URL;Ljava/security/AccessControlContext;)V", nullptr, 0, $method(URLClassLoader, init$, void, $URLArray*, $AccessControlContext*)},
	{"<init>", "([Ljava/net/URL;Ljava/lang/ClassLoader;Ljava/net/URLStreamHandlerFactory;)V", nullptr, $PUBLIC, $method(URLClassLoader, init$, void, $URLArray*, $ClassLoader*, $URLStreamHandlerFactory*)},
	{"<init>", "(Ljava/lang/String;[Ljava/net/URL;Ljava/lang/ClassLoader;)V", nullptr, $PUBLIC, $method(URLClassLoader, init$, void, $String*, $URLArray*, $ClassLoader*)},
	{"<init>", "(Ljava/lang/String;[Ljava/net/URL;Ljava/lang/ClassLoader;Ljava/net/URLStreamHandlerFactory;)V", nullptr, $PUBLIC, $method(URLClassLoader, init$, void, $String*, $URLArray*, $ClassLoader*, $URLStreamHandlerFactory*)},
	{"addURL", "(Ljava/net/URL;)V", nullptr, $PROTECTED, $virtualMethod(URLClassLoader, addURL, void, $URL*)},
	{"close", "()V", nullptr, $PUBLIC, $virtualMethod(URLClassLoader, close, void), "java.io.IOException"},
	{"defineClass", "(Ljava/lang/String;Ljdk/internal/loader/Resource;)Ljava/lang/Class;", "(Ljava/lang/String;Ljdk/internal/loader/Resource;)Ljava/lang/Class<*>;", $PRIVATE, $method(URLClassLoader, defineClass, $Class*, $String*, $Resource*), "java.io.IOException"},
	{"definePackage", "(Ljava/lang/String;Ljava/util/jar/Manifest;Ljava/net/URL;)Ljava/lang/Package;", nullptr, $PROTECTED, $virtualMethod(URLClassLoader, definePackage, $Package*, $String*, $Manifest*, $URL*)},
	{"findClass", "(Ljava/lang/String;)Ljava/lang/Class;", "(Ljava/lang/String;)Ljava/lang/Class<*>;", $PROTECTED, $virtualMethod(URLClassLoader, findClass, $Class*, $String*), "java.lang.ClassNotFoundException"},
	{"findResource", "(Ljava/lang/String;)Ljava/net/URL;", nullptr, $PUBLIC, $virtualMethod(URLClassLoader, findResource, $URL*, $String*)},
	{"findResources", "(Ljava/lang/String;)Ljava/util/Enumeration;", "(Ljava/lang/String;)Ljava/util/Enumeration<Ljava/net/URL;>;", $PUBLIC, $virtualMethod(URLClassLoader, findResources, $Enumeration*, $String*), "java.io.IOException"},
	{"getAndVerifyPackage", "(Ljava/lang/String;Ljava/util/jar/Manifest;Ljava/net/URL;)Ljava/lang/Package;", nullptr, $PRIVATE, $method(URLClassLoader, getAndVerifyPackage, $Package*, $String*, $Manifest*, $URL*)},
	{"getPermissions", "(Ljava/security/CodeSource;)Ljava/security/PermissionCollection;", nullptr, $PROTECTED, $virtualMethod(URLClassLoader, getPermissions, $PermissionCollection*, $CodeSource*)},
	{"getResourceAsStream", "(Ljava/lang/String;)Ljava/io/InputStream;", nullptr, $PUBLIC, $virtualMethod(URLClassLoader, getResourceAsStream, $InputStream*, $String*)},
	{"getURLs", "()[Ljava/net/URL;", nullptr, $PUBLIC, $virtualMethod(URLClassLoader, getURLs, $URLArray*)},
	{"isSealed", "(Ljava/lang/String;Ljava/util/jar/Manifest;)Z", nullptr, $PRIVATE, $method(URLClassLoader, isSealed, bool, $String*, $Manifest*)},
	{"newInstance", "([Ljava/net/URL;Ljava/lang/ClassLoader;)Ljava/net/URLClassLoader;", nullptr, $PUBLIC | $STATIC, $staticMethod(URLClassLoader, newInstance, URLClassLoader*, $URLArray*, $ClassLoader*)},
	{"newInstance", "([Ljava/net/URL;)Ljava/net/URLClassLoader;", nullptr, $PUBLIC | $STATIC, $staticMethod(URLClassLoader, newInstance, URLClassLoader*, $URLArray*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _URLClassLoader_InnerClassesInfo_[] = {
	{"java.net.URLClassLoader$6", nullptr, nullptr, 0},
	{"java.net.URLClassLoader$5", nullptr, nullptr, 0},
	{"java.net.URLClassLoader$4", nullptr, nullptr, 0},
	{"java.net.URLClassLoader$3", nullptr, nullptr, 0},
	{"java.net.URLClassLoader$2", nullptr, nullptr, 0},
	{"java.net.URLClassLoader$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _URLClassLoader_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.net.URLClassLoader",
	"java.security.SecureClassLoader",
	"java.io.Closeable",
	_URLClassLoader_FieldInfo_,
	_URLClassLoader_MethodInfo_,
	nullptr,
	nullptr,
	_URLClassLoader_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.net.URLClassLoader$6,java.net.URLClassLoader$5,java.net.URLClassLoader$4,java.net.URLClassLoader$3,java.net.URLClassLoader$3$1,java.net.URLClassLoader$2,java.net.URLClassLoader$1"
};

$Object* allocate$URLClassLoader($Class* clazz) {
	return $of($alloc(URLClassLoader));
}

int32_t URLClassLoader::hashCode() {
	 return this->$SecureClassLoader::hashCode();
}

bool URLClassLoader::equals(Object$* obj) {
	 return this->$SecureClassLoader::equals(obj);
}

$Object* URLClassLoader::clone() {
	 return this->$SecureClassLoader::clone();
}

$String* URLClassLoader::toString() {
	 return this->$SecureClassLoader::toString();
}

void URLClassLoader::finalize() {
	this->$SecureClassLoader::finalize();
}

void URLClassLoader::init$($URLArray* urls, $ClassLoader* parent) {
	$SecureClassLoader::init$(parent);
	$set(this, closeables, $new($WeakHashMap));
	$set(this, acc, $AccessController::getContext());
	$set(this, ucp, $new($URLClassPath, urls, this->acc));
}

void URLClassLoader::init$($String* name, $URLArray* urls, $ClassLoader* parent, $AccessControlContext* acc) {
	$SecureClassLoader::init$(name, parent);
	$set(this, closeables, $new($WeakHashMap));
	$set(this, acc, acc);
	$set(this, ucp, $new($URLClassPath, urls, acc));
}

void URLClassLoader::init$($URLArray* urls) {
	$SecureClassLoader::init$();
	$set(this, closeables, $new($WeakHashMap));
	$set(this, acc, $AccessController::getContext());
	$set(this, ucp, $new($URLClassPath, urls, this->acc));
}

void URLClassLoader::init$($URLArray* urls, $AccessControlContext* acc) {
	$SecureClassLoader::init$();
	$set(this, closeables, $new($WeakHashMap));
	$set(this, acc, acc);
	$set(this, ucp, $new($URLClassPath, urls, acc));
}

void URLClassLoader::init$($URLArray* urls, $ClassLoader* parent, $URLStreamHandlerFactory* factory) {
	$SecureClassLoader::init$(parent);
	$set(this, closeables, $new($WeakHashMap));
	$set(this, acc, $AccessController::getContext());
	$set(this, ucp, $new($URLClassPath, urls, factory, this->acc));
}

void URLClassLoader::init$($String* name, $URLArray* urls, $ClassLoader* parent) {
	$SecureClassLoader::init$(name, parent);
	$set(this, closeables, $new($WeakHashMap));
	$set(this, acc, $AccessController::getContext());
	$set(this, ucp, $new($URLClassPath, urls, this->acc));
}

void URLClassLoader::init$($String* name, $URLArray* urls, $ClassLoader* parent, $URLStreamHandlerFactory* factory) {
	$SecureClassLoader::init$(name, parent);
	$set(this, closeables, $new($WeakHashMap));
	$set(this, acc, $AccessController::getContext());
	$set(this, ucp, $new($URLClassPath, urls, factory, this->acc));
}

$InputStream* URLClassLoader::getResourceAsStream($String* name) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(name);
	$var($URL, url, getResource(name));
	try {
		if (url == nullptr) {
			return nullptr;
		}
		$var($URLConnection, urlc, $nc(url)->openConnection());
		$var($InputStream, is, $nc(urlc)->getInputStream());
		{
			$var($JarURLConnection, juc, nullptr);
			bool var$0 = $instanceOf($JarURLConnection, urlc);
			if (var$0) {
				$assign(juc, $cast($JarURLConnection, urlc));
				var$0 = true;
			}
			if (var$0) {
				$var($JarFile, jar, $nc(juc)->getJarFile());
				$synchronized(this->closeables) {
					if (!$nc(this->closeables)->containsKey(jar)) {
						$nc(this->closeables)->put(jar, nullptr);
					}
				}
			} else if ($instanceOf($FileURLConnection, urlc)) {
				$synchronized(this->closeables) {
					$nc(this->closeables)->put(is, nullptr);
				}
			}
		}
		return is;
	} catch ($IOException& e) {
		return nullptr;
	}
	$shouldNotReachHere();
}

void URLClassLoader::close() {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, security, $System::getSecurityManager());
	if (security != nullptr) {
		security->checkPermission($$new($RuntimePermission, "closeClassLoader"_s));
	}
	$var($List, errors, $nc(this->ucp)->closeLoaders());
	$synchronized(this->closeables) {
		$var($Set, keys, $nc(this->closeables)->keySet());
		{
			$var($Iterator, i$, $nc(keys)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Closeable, c, $cast($Closeable, i$->next()));
				{
					try {
						$nc(c)->close();
					} catch ($IOException& ioex) {
						$nc(errors)->add(ioex);
					}
				}
			}
		}
		$nc(this->closeables)->clear();
	}
	if ($nc(errors)->isEmpty()) {
		return;
	}
	$var($IOException, firstex, $cast($IOException, $nc(errors)->remove(0)));
	{
		$var($Iterator, i$, errors->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($IOException, error, $cast($IOException, i$->next()));
			{
				$nc(firstex)->addSuppressed(error);
			}
		}
	}
	$throw(firstex);
}

void URLClassLoader::addURL($URL* url) {
	$nc(this->ucp)->addURL(url);
}

$URLArray* URLClassLoader::getURLs() {
	return $nc(this->ucp)->getURLs();
}

$Class* URLClassLoader::findClass($String* name) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$Class* result = nullptr;
	try {
		result = $cast($Class, $AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new($URLClassLoader$1, this, name)), this->acc));
	} catch ($PrivilegedActionException& pae) {
		$throw($cast($ClassNotFoundException, $(pae->getException())));
	}
	if (result == nullptr) {
		$throwNew($ClassNotFoundException, name);
	}
	return result;
}

$Package* URLClassLoader::getAndVerifyPackage($String* pkgname, $Manifest* man, $URL* url) {
	$useLocalCurrentObjectStackCache();
	$var($Package, pkg, getDefinedPackage(pkgname));
	if (pkg != nullptr) {
		if (pkg->isSealed()) {
			if (!pkg->isSealed(url)) {
				$throwNew($SecurityException, $$str({"sealing violation: package "_s, pkgname, " is sealed"_s}));
			}
		} else if ((man != nullptr) && isSealed(pkgname, man)) {
			$throwNew($SecurityException, $$str({"sealing violation: can\'t seal package "_s, pkgname, ": already loaded"_s}));
		}
	}
	return pkg;
}

$Class* URLClassLoader::defineClass($String* name, $Resource* res) {
	$useLocalCurrentObjectStackCache();
	int64_t t0 = $System::nanoTime();
	int32_t i = $nc(name)->lastIndexOf((int32_t)u'.');
	$var($URL, url, $nc(res)->getCodeSourceURL());
	if (i != -1) {
		$var($String, pkgname, name->substring(0, i));
		$var($Manifest, man, res->getManifest());
		if (getAndVerifyPackage(pkgname, man, url) == nullptr) {
			try {
				if (man != nullptr) {
					definePackage(pkgname, man, url);
				} else {
					definePackage(pkgname, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr);
				}
			} catch ($IllegalArgumentException& iae) {
				if (getAndVerifyPackage(pkgname, man, url) == nullptr) {
					$throwNew($AssertionError, $of($$str({"Cannot find package "_s, pkgname})));
				}
			}
		}
	}
	$var($ByteBuffer, bb, res->getByteBuffer());
	if (bb != nullptr) {
		$var($CodeSignerArray, signers, res->getCodeSigners());
		$var($CodeSource, cs, $new($CodeSource, url, signers));
		$nc($($PerfCounter::getReadClassBytesTime()))->addElapsedTimeFrom(t0);
		return defineClass(name, bb, cs);
	} else {
		$var($bytes, b, res->getBytes());
		$var($CodeSignerArray, signers, res->getCodeSigners());
		$var($CodeSource, cs, $new($CodeSource, url, signers));
		$nc($($PerfCounter::getReadClassBytesTime()))->addElapsedTimeFrom(t0);
		return defineClass(name, b, 0, $nc(b)->length, cs);
	}
}

$Package* URLClassLoader::definePackage($String* name, $Manifest* man, $URL* url) {
	$useLocalCurrentObjectStackCache();
	$var($String, specTitle, nullptr);
	$var($String, specVersion, nullptr);
	$var($String, specVendor, nullptr);
	$var($String, implTitle, nullptr);
	$var($String, implVersion, nullptr);
	$var($String, implVendor, nullptr);
	$var($String, sealed, nullptr);
	$var($URL, sealBase, nullptr);
	$var($Attributes, attr, $nc($($SharedSecrets::javaUtilJarAccess()))->getTrustedAttributes(man, $($($nc(name)->replace(u'.', u'/'))->concat("/"_s))));
	if (attr != nullptr) {
		$init($Attributes$Name);
		$assign(specTitle, attr->getValue($Attributes$Name::SPECIFICATION_TITLE));
		$assign(specVersion, attr->getValue($Attributes$Name::SPECIFICATION_VERSION));
		$assign(specVendor, attr->getValue($Attributes$Name::SPECIFICATION_VENDOR));
		$assign(implTitle, attr->getValue($Attributes$Name::IMPLEMENTATION_TITLE));
		$assign(implVersion, attr->getValue($Attributes$Name::IMPLEMENTATION_VERSION));
		$assign(implVendor, attr->getValue($Attributes$Name::IMPLEMENTATION_VENDOR));
		$assign(sealed, attr->getValue($Attributes$Name::SEALED));
	}
	$assign(attr, $nc(man)->getMainAttributes());
	if (attr != nullptr) {
		if (specTitle == nullptr) {
			$init($Attributes$Name);
			$assign(specTitle, attr->getValue($Attributes$Name::SPECIFICATION_TITLE));
		}
		if (specVersion == nullptr) {
			$init($Attributes$Name);
			$assign(specVersion, attr->getValue($Attributes$Name::SPECIFICATION_VERSION));
		}
		if (specVendor == nullptr) {
			$init($Attributes$Name);
			$assign(specVendor, attr->getValue($Attributes$Name::SPECIFICATION_VENDOR));
		}
		if (implTitle == nullptr) {
			$init($Attributes$Name);
			$assign(implTitle, attr->getValue($Attributes$Name::IMPLEMENTATION_TITLE));
		}
		if (implVersion == nullptr) {
			$init($Attributes$Name);
			$assign(implVersion, attr->getValue($Attributes$Name::IMPLEMENTATION_VERSION));
		}
		if (implVendor == nullptr) {
			$init($Attributes$Name);
			$assign(implVendor, attr->getValue($Attributes$Name::IMPLEMENTATION_VENDOR));
		}
		if (sealed == nullptr) {
			$init($Attributes$Name);
			$assign(sealed, attr->getValue($Attributes$Name::SEALED));
		}
	}
	if ("true"_s->equalsIgnoreCase(sealed)) {
		$assign(sealBase, url);
	}
	return definePackage(name, specTitle, specVersion, specVendor, implTitle, implVersion, implVendor, sealBase);
}

bool URLClassLoader::isSealed($String* name, $Manifest* man) {
	$useLocalCurrentObjectStackCache();
	$var($Attributes, attr, $nc($($SharedSecrets::javaUtilJarAccess()))->getTrustedAttributes(man, $($($nc(name)->replace(u'.', u'/'))->concat("/"_s))));
	$var($String, sealed, nullptr);
	if (attr != nullptr) {
		$init($Attributes$Name);
		$assign(sealed, attr->getValue($Attributes$Name::SEALED));
	}
	if (sealed == nullptr) {
		if (($assign(attr, $nc(man)->getMainAttributes())) != nullptr) {
			$init($Attributes$Name);
			$assign(sealed, $nc(attr)->getValue($Attributes$Name::SEALED));
		}
	}
	return "true"_s->equalsIgnoreCase(sealed);
}

$URL* URLClassLoader::findResource($String* name) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($URL, url, $cast($URL, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($URLClassLoader$2, this, name)), this->acc)));
	return url != nullptr ? $URLClassPath::checkURL(url) : ($URL*)nullptr;
}

$Enumeration* URLClassLoader::findResources($String* name) {
	$var($Enumeration, e, $nc(this->ucp)->findResources(name, true));
	return $new($URLClassLoader$3, this, e);
}

$PermissionCollection* URLClassLoader::getPermissions($CodeSource* codesource) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($PermissionCollection, perms, $SecureClassLoader::getPermissions(codesource));
	$var($URL, url, $nc(codesource)->getLocation());
	$var($Permission, p, nullptr);
	$var($URLConnection, urlConnection, nullptr);
	try {
		$assign(urlConnection, $nc(url)->openConnection());
		$assign(p, $nc(urlConnection)->getPermission());
	} catch ($IOException& ioe) {
		$assign(p, nullptr);
		$assign(urlConnection, nullptr);
	}
	if ($instanceOf($FilePermission, p)) {
		$var($String, path, $nc(p)->getName());
		$init($File);
		if ($nc(path)->endsWith($File::separator)) {
			$plusAssign(path, "-"_s);
			$init($SecurityConstants);
			$assign(p, $new($FilePermission, path, $SecurityConstants::FILE_READ_ACTION));
		}
	} else if ((p == nullptr) && ($nc($($nc(url)->getProtocol()))->equals("file"_s))) {
		$init($File);
		$var($String, path, $nc($(url->getFile()))->replace(u'/', $File::separatorChar));
		$assign(path, $ParseUtil::decode(path));
		if ($nc(path)->endsWith($File::separator)) {
			$plusAssign(path, "-"_s);
		}
		$init($SecurityConstants);
		$assign(p, $new($FilePermission, path, $SecurityConstants::FILE_READ_ACTION));
	} else {
		$var($URL, locUrl, url);
		if ($instanceOf($JarURLConnection, urlConnection)) {
			$assign(locUrl, $nc(($cast($JarURLConnection, urlConnection)))->getJarFileURL());
		}
		$var($String, host, locUrl->getHost());
		if (host != nullptr && !host->isEmpty()) {
			$init($SecurityConstants);
			$assign(p, $new($SocketPermission, host, $SecurityConstants::SOCKET_CONNECT_ACCEPT_ACTION));
		}
	}
	if (p != nullptr) {
		$var($SecurityManager, sm, $System::getSecurityManager());
		if (sm != nullptr) {
			$var($Permission, fp, p);
			$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($URLClassLoader$4, this, sm, fp)), this->acc);
		}
		$nc(perms)->add(p);
	}
	return perms;
}

URLClassLoader* URLClassLoader::newInstance($URLArray* urls, $ClassLoader* parent) {
	$init(URLClassLoader);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($AccessControlContext, acc, $AccessController::getContext());
	$var(URLClassLoader, ucl, $cast(URLClassLoader, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($URLClassLoader$5, urls, parent, acc)))));
	return ucl;
}

URLClassLoader* URLClassLoader::newInstance($URLArray* urls) {
	$init(URLClassLoader);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($AccessControlContext, acc, $AccessController::getContext());
	$var(URLClassLoader, ucl, $cast(URLClassLoader, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($URLClassLoader$6, urls, acc)))));
	return ucl;
}

void clinit$URLClassLoader($Class* class$) {
	$beforeCallerSensitive();
	{
		$ClassLoader::registerAsParallelCapable();
	}
}

URLClassLoader::URLClassLoader() {
}

$Class* URLClassLoader::load$($String* name, bool initialize) {
	$loadClass(URLClassLoader, name, initialize, &_URLClassLoader_ClassInfo_, clinit$URLClassLoader, allocate$URLClassLoader);
	return class$;
}

$Class* URLClassLoader::class$ = nullptr;

	} // net
} // java