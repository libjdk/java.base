#include <java/util/ServiceLoader$LazyClassPathLookupIterator.h>

#include <java/io/BufferedReader.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/InputStreamReader.h>
#include <java/io/Reader.h>
#include <java/lang/AssertionError.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/Module.h>
#include <java/lang/reflect/Constructor.h>
#include <java/net/URL.h>
#include <java/net/URLConnection.h>
#include <java/nio/charset/Charset.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/Collections.h>
#include <java/util/Enumeration.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedHashSet.h>
#include <java/util/NoSuchElementException.h>
#include <java/util/ServiceConfigurationError.h>
#include <java/util/ServiceLoader$LazyClassPathLookupIterator$1.h>
#include <java/util/ServiceLoader$LazyClassPathLookupIterator$2.h>
#include <java/util/ServiceLoader$Provider.h>
#include <java/util/ServiceLoader$ProviderImpl.h>
#include <java/util/ServiceLoader.h>
#include <java/util/Set.h>
#include <jdk/internal/loader/BootLoader.h>
#include <jdk/internal/loader/ClassLoaders.h>
#include <sun/nio/cs/UTF_8.h>
#include <jcpp.h>

#undef INSTANCE
#undef PREFIX

using $BufferedReader = ::java::io::BufferedReader;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $InputStreamReader = ::java::io::InputStreamReader;
using $Reader = ::java::io::Reader;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Module = ::java::lang::Module;
using $Constructor = ::java::lang::reflect::Constructor;
using $URL = ::java::net::URL;
using $URLConnection = ::java::net::URLConnection;
using $Charset = ::java::nio::charset::Charset;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Collections = ::java::util::Collections;
using $Enumeration = ::java::util::Enumeration;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $LinkedHashSet = ::java::util::LinkedHashSet;
using $NoSuchElementException = ::java::util::NoSuchElementException;
using $ServiceConfigurationError = ::java::util::ServiceConfigurationError;
using $ServiceLoader = ::java::util::ServiceLoader;
using $ServiceLoader$LazyClassPathLookupIterator$1 = ::java::util::ServiceLoader$LazyClassPathLookupIterator$1;
using $ServiceLoader$LazyClassPathLookupIterator$2 = ::java::util::ServiceLoader$LazyClassPathLookupIterator$2;
using $ServiceLoader$Provider = ::java::util::ServiceLoader$Provider;
using $ServiceLoader$ProviderImpl = ::java::util::ServiceLoader$ProviderImpl;
using $Set = ::java::util::Set;
using $BootLoader = ::jdk::internal::loader::BootLoader;
using $ClassLoaders = ::jdk::internal::loader::ClassLoaders;
using $UTF_8 = ::sun::nio::cs::UTF_8;

namespace java {
	namespace util {

$FieldInfo _ServiceLoader$LazyClassPathLookupIterator_FieldInfo_[] = {
	{"this$0", "Ljava/util/ServiceLoader;", nullptr, $FINAL | $SYNTHETIC, $field(ServiceLoader$LazyClassPathLookupIterator, this$0)},
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(ServiceLoader$LazyClassPathLookupIterator, $assertionsDisabled)},
	{"PREFIX", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(ServiceLoader$LazyClassPathLookupIterator, PREFIX)},
	{"providerNames", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/String;>;", 0, $field(ServiceLoader$LazyClassPathLookupIterator, providerNames)},
	{"configs", "Ljava/util/Enumeration;", "Ljava/util/Enumeration<Ljava/net/URL;>;", 0, $field(ServiceLoader$LazyClassPathLookupIterator, configs)},
	{"pending", "Ljava/util/Iterator;", "Ljava/util/Iterator<Ljava/lang/String;>;", 0, $field(ServiceLoader$LazyClassPathLookupIterator, pending)},
	{"nextProvider", "Ljava/util/ServiceLoader$Provider;", "Ljava/util/ServiceLoader$Provider<TT;>;", 0, $field(ServiceLoader$LazyClassPathLookupIterator, nextProvider)},
	{"nextError", "Ljava/util/ServiceConfigurationError;", nullptr, 0, $field(ServiceLoader$LazyClassPathLookupIterator, nextError)},
	{}
};

$MethodInfo _ServiceLoader$LazyClassPathLookupIterator_MethodInfo_[] = {
	{"<init>", "(Ljava/util/ServiceLoader;)V", nullptr, 0, $method(ServiceLoader$LazyClassPathLookupIterator, init$, void, $ServiceLoader*)},
	{"hasNext", "()Z", nullptr, $PUBLIC, $virtualMethod(ServiceLoader$LazyClassPathLookupIterator, hasNext, bool)},
	{"hasNextService", "()Z", nullptr, $PRIVATE, $method(ServiceLoader$LazyClassPathLookupIterator, hasNextService, bool)},
	{"next", "()Ljava/util/ServiceLoader$Provider;", "()Ljava/util/ServiceLoader$Provider<TT;>;", $PUBLIC, $virtualMethod(ServiceLoader$LazyClassPathLookupIterator, next, $Object*)},
	{"nextProviderClass", "()Ljava/lang/Class;", "()Ljava/lang/Class<*>;", $PRIVATE, $method(ServiceLoader$LazyClassPathLookupIterator, nextProviderClass, $Class*)},
	{"nextService", "()Ljava/util/ServiceLoader$Provider;", "()Ljava/util/ServiceLoader$Provider<TT;>;", $PRIVATE, $method(ServiceLoader$LazyClassPathLookupIterator, nextService, $ServiceLoader$Provider*)},
	{"parse", "(Ljava/net/URL;)Ljava/util/Iterator;", "(Ljava/net/URL;)Ljava/util/Iterator<Ljava/lang/String;>;", $PRIVATE, $method(ServiceLoader$LazyClassPathLookupIterator, parse, $Iterator*, $URL*)},
	{"parseLine", "(Ljava/net/URL;Ljava/io/BufferedReader;ILjava/util/Set;)I", "(Ljava/net/URL;Ljava/io/BufferedReader;ILjava/util/Set<Ljava/lang/String;>;)I", $PRIVATE, $method(ServiceLoader$LazyClassPathLookupIterator, parseLine, int32_t, $URL*, $BufferedReader*, int32_t, $Set*), "java.io.IOException"},
	{}
};

$InnerClassInfo _ServiceLoader$LazyClassPathLookupIterator_InnerClassesInfo_[] = {
	{"java.util.ServiceLoader$LazyClassPathLookupIterator", "java.util.ServiceLoader", "LazyClassPathLookupIterator", $PRIVATE | $FINAL},
	{"java.util.ServiceLoader$LazyClassPathLookupIterator$2", nullptr, nullptr, 0},
	{"java.util.ServiceLoader$LazyClassPathLookupIterator$1", nullptr, nullptr, 0},
	{"java.util.ServiceLoader$Provider", "java.util.ServiceLoader", "Provider", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _ServiceLoader$LazyClassPathLookupIterator_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.ServiceLoader$LazyClassPathLookupIterator",
	"java.lang.Object",
	"java.util.Iterator",
	_ServiceLoader$LazyClassPathLookupIterator_FieldInfo_,
	_ServiceLoader$LazyClassPathLookupIterator_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljava/lang/Object;Ljava/util/Iterator<Ljava/util/ServiceLoader$Provider<TT;>;>;",
	nullptr,
	_ServiceLoader$LazyClassPathLookupIterator_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.ServiceLoader"
};

$Object* allocate$ServiceLoader$LazyClassPathLookupIterator($Class* clazz) {
	return $of($alloc(ServiceLoader$LazyClassPathLookupIterator));
}

bool ServiceLoader$LazyClassPathLookupIterator::$assertionsDisabled = false;
$String* ServiceLoader$LazyClassPathLookupIterator::PREFIX = nullptr;

void ServiceLoader$LazyClassPathLookupIterator::init$($ServiceLoader* this$0) {
	$set(this, this$0, this$0);
	$set(this, providerNames, $new($HashSet));
}

int32_t ServiceLoader$LazyClassPathLookupIterator::parseLine($URL* u, $BufferedReader* r, int32_t lc, $Set* names) {
	$useLocalCurrentObjectStackCache();
	$var($String, ln, $nc(r)->readLine());
	if (ln == nullptr) {
		return -1;
	}
	int32_t ci = $nc(ln)->indexOf((int32_t)u'#');
	if (ci >= 0) {
		$assign(ln, ln->substring(0, ci));
	}
	$assign(ln, ln->trim());
	int32_t n = ln->length();
	if (n != 0) {
		bool var$0 = (ln->indexOf((int32_t)u' ') >= 0);
		if (var$0 || (ln->indexOf((int32_t)u'\t') >= 0)) {
			$ServiceLoader::fail(this->this$0->service, u, lc, "Illegal configuration-file syntax"_s);
		}
		int32_t cp = ln->codePointAt(0);
		if (!$Character::isJavaIdentifierStart(cp)) {
			$ServiceLoader::fail(this->this$0->service, u, lc, $$str({"Illegal provider-class name: "_s, ln}));
		}
		int32_t start = $Character::charCount(cp);
		for (int32_t i = start; i < n; i += $Character::charCount(cp)) {
			cp = ln->codePointAt(i);
			if (!$Character::isJavaIdentifierPart(cp) && (cp != u'.')) {
				$ServiceLoader::fail(this->this$0->service, u, lc, $$str({"Illegal provider-class name: "_s, ln}));
			}
		}
		if ($nc(this->providerNames)->add(ln)) {
			$nc(names)->add(ln);
		}
	}
	return lc + 1;
}

$Iterator* ServiceLoader$LazyClassPathLookupIterator::parse($URL* u) {
	$useLocalCurrentObjectStackCache();
	$var($Set, names, $new($LinkedHashSet));
	try {
		$var($URLConnection, uc, $nc(u)->openConnection());
		$nc(uc)->setUseCaches(false);
		{
			$var($InputStream, in, uc->getInputStream());
			{
				$var($Throwable, var$0, nullptr);
				try {
					try {
						$init($UTF_8);
						$var($BufferedReader, r, $new($BufferedReader, $$new($InputStreamReader, in, static_cast<$Charset*>($UTF_8::INSTANCE))));
						{
							$var($Throwable, var$1, nullptr);
							try {
								try {
									int32_t lc = 1;
									while ((lc = parseLine(u, r, lc, names)) >= 0) {
									}
								} catch ($Throwable& t$) {
									try {
										r->close();
									} catch ($Throwable& x2) {
										t$->addSuppressed(x2);
									}
									$throw(t$);
								}
							} catch ($Throwable& var$2) {
								$assign(var$1, var$2);
							} /*finally*/ {
								r->close();
							}
							if (var$1 != nullptr) {
								$throw(var$1);
							}
						}
					} catch ($Throwable& t$) {
						if (in != nullptr) {
							try {
								in->close();
							} catch ($Throwable& x2) {
								t$->addSuppressed(x2);
							}
						}
						$throw(t$);
					}
				} catch ($Throwable& var$3) {
					$assign(var$0, var$3);
				} /*finally*/ {
					if (in != nullptr) {
						in->close();
					}
				}
				if (var$0 != nullptr) {
					$throw(var$0);
				}
			}
		}
	} catch ($IOException& x) {
		$ServiceLoader::fail(this->this$0->service, "Error accessing configuration file"_s, x);
	}
	return names->iterator();
}

$Class* ServiceLoader$LazyClassPathLookupIterator::nextProviderClass() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (this->configs == nullptr) {
		try {
			$var($String, fullName, $str({ServiceLoader$LazyClassPathLookupIterator::PREFIX, $($nc(this->this$0->service)->getName())}));
			if (this->this$0->loader == nullptr) {
				$set(this, configs, $ClassLoader::getSystemResources(fullName));
			} else if (this->this$0->loader == $ClassLoaders::platformClassLoader()) {
				if ($BootLoader::hasClassPath()) {
					$set(this, configs, $BootLoader::findResources(fullName));
				} else {
					$set(this, configs, $Collections::emptyEnumeration());
				}
			} else {
				$set(this, configs, $nc(this->this$0->loader)->getResources(fullName));
			}
		} catch ($IOException& x) {
			$ServiceLoader::fail(this->this$0->service, "Error locating configuration files"_s, x);
		}
	}
	while ((this->pending == nullptr) || !$nc(this->pending)->hasNext()) {
		if (!$nc(this->configs)->hasMoreElements()) {
			return nullptr;
		}
		$set(this, pending, parse($cast($URL, $($nc(this->configs)->nextElement()))));
	}
	$var($String, cn, $cast($String, $nc(this->pending)->next()));
	try {
		return $Class::forName(cn, false, this->this$0->loader);
	} catch ($ClassNotFoundException& x) {
		$ServiceLoader::fail(this->this$0->service, $$str({"Provider "_s, cn, " not found"_s}));
		return nullptr;
	}
	$shouldNotReachHere();
}

bool ServiceLoader$LazyClassPathLookupIterator::hasNextService() {
	$useLocalCurrentObjectStackCache();
	while (this->nextProvider == nullptr && this->nextError == nullptr) {
		try {
			$Class* clazz = nextProviderClass();
			if (clazz == nullptr) {
				return false;
			}
			if ($nc($($nc(clazz)->getModule()))->isNamed()) {
				continue;
			}
			if ($nc(this->this$0->service)->isAssignableFrom(clazz)) {
				$Class* type = clazz;
				$var($Constructor, ctor, this->this$0->getConstructor(clazz));
				$var($ServiceLoader$ProviderImpl, p, $new($ServiceLoader$ProviderImpl, this->this$0->service, type, ctor, this->this$0->acc));
				$set(this, nextProvider, p);
			} else {
				$ServiceLoader::fail(this->this$0->service, $$str({$($nc(clazz)->getName()), " not a subtype"_s}));
			}
		} catch ($ServiceConfigurationError& e) {
			$set(this, nextError, e);
		}
	}
	return true;
}

$ServiceLoader$Provider* ServiceLoader$LazyClassPathLookupIterator::nextService() {
	$useLocalCurrentObjectStackCache();
	if (!hasNextService()) {
		$throwNew($NoSuchElementException);
	}
	$var($ServiceLoader$Provider, provider, this->nextProvider);
	if (provider != nullptr) {
		$set(this, nextProvider, nullptr);
		return provider;
	} else {
		$var($ServiceConfigurationError, e, this->nextError);
		if (!ServiceLoader$LazyClassPathLookupIterator::$assertionsDisabled && !(e != nullptr)) {
			$throwNew($AssertionError);
		}
		$set(this, nextError, nullptr);
		$throw(e);
	}
}

bool ServiceLoader$LazyClassPathLookupIterator::hasNext() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (this->this$0->acc == nullptr) {
		return hasNextService();
	} else {
		$var($PrivilegedAction, action, $new($ServiceLoader$LazyClassPathLookupIterator$1, this));
		return $nc(($cast($Boolean, $($AccessController::doPrivileged(action, this->this$0->acc)))))->booleanValue();
	}
}

$Object* ServiceLoader$LazyClassPathLookupIterator::next() {
	$beforeCallerSensitive();
	if (this->this$0->acc == nullptr) {
		return $of(nextService());
	} else {
		$var($PrivilegedAction, action, $new($ServiceLoader$LazyClassPathLookupIterator$2, this));
		return $of($cast($ServiceLoader$Provider, $AccessController::doPrivileged(action, this->this$0->acc)));
	}
}

void clinit$ServiceLoader$LazyClassPathLookupIterator($Class* class$) {
	$assignStatic(ServiceLoader$LazyClassPathLookupIterator::PREFIX, "META-INF/services/"_s);
	$load($ServiceLoader);
	ServiceLoader$LazyClassPathLookupIterator::$assertionsDisabled = !$ServiceLoader::class$->desiredAssertionStatus();
}

ServiceLoader$LazyClassPathLookupIterator::ServiceLoader$LazyClassPathLookupIterator() {
}

$Class* ServiceLoader$LazyClassPathLookupIterator::load$($String* name, bool initialize) {
	$loadClass(ServiceLoader$LazyClassPathLookupIterator, name, initialize, &_ServiceLoader$LazyClassPathLookupIterator_ClassInfo_, clinit$ServiceLoader$LazyClassPathLookupIterator, allocate$ServiceLoader$LazyClassPathLookupIterator);
	return class$;
}

$Class* ServiceLoader$LazyClassPathLookupIterator::class$ = nullptr;

	} // util
} // java