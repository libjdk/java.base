#include <java/util/ResourceBundle$Control.h>

#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/CharSequence.h>
#include <java/lang/ClassCastException.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/InstantiationException.h>
#include <java/lang/Module.h>
#include <java/lang/NoSuchMethodException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/InvocationTargetException.h>
#include <java/lang/reflect/Modifier.h>
#include <java/net/JarURLConnection.h>
#include <java/net/URL.h>
#include <java/net/URLConnection.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/PrivilegedActionException.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/PropertyResourceBundle.h>
#include <java/util/ResourceBundle$Control$1.h>
#include <java/util/ResourceBundle$Control$2.h>
#include <java/util/ResourceBundle$Control$CandidateListCache.h>
#include <java/util/ResourceBundle$NoFallbackControl.h>
#include <java/util/ResourceBundle$SingleFormatControl.h>
#include <java/util/ResourceBundle.h>
#include <java/util/jar/JarEntry.h>
#include <sun/util/locale/BaseLocale.h>
#include <sun/util/resources/Bundles.h>
#include <jcpp.h>

#undef CANDIDATES_CACHE
#undef CLASS_ONLY
#undef CLASS_ONLY_NO_FALLBACK
#undef FORMAT_CLASS
#undef FORMAT_DEFAULT
#undef FORMAT_PROPERTIES
#undef INSTANCE
#undef NO_FALLBACK
#undef PROPERTIES_ONLY
#undef PROPERTIES_ONLY_NO_FALLBACK
#undef ROOT
#undef TTL_DONT_CACHE
#undef TTL_NO_EXPIRATION_CONTROL

using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $CharSequence = ::java::lang::CharSequence;
using $ClassCastException = ::java::lang::ClassCastException;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InstantiationException = ::java::lang::InstantiationException;
using $MethodInfo = ::java::lang::MethodInfo;
using $Module = ::java::lang::Module;
using $NoSuchMethodException = ::java::lang::NoSuchMethodException;
using $NullPointerException = ::java::lang::NullPointerException;
using $Void = ::java::lang::Void;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Constructor = ::java::lang::reflect::Constructor;
using $InvocationTargetException = ::java::lang::reflect::InvocationTargetException;
using $Modifier = ::java::lang::reflect::Modifier;
using $JarURLConnection = ::java::net::JarURLConnection;
using $URL = ::java::net::URL;
using $URLConnection = ::java::net::URLConnection;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $PrivilegedActionException = ::java::security::PrivilegedActionException;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $PropertyResourceBundle = ::java::util::PropertyResourceBundle;
using $ResourceBundle = ::java::util::ResourceBundle;
using $ResourceBundle$Control$1 = ::java::util::ResourceBundle$Control$1;
using $ResourceBundle$Control$2 = ::java::util::ResourceBundle$Control$2;
using $ResourceBundle$Control$CandidateListCache = ::java::util::ResourceBundle$Control$CandidateListCache;
using $ResourceBundle$NoFallbackControl = ::java::util::ResourceBundle$NoFallbackControl;
using $ResourceBundle$SingleFormatControl = ::java::util::ResourceBundle$SingleFormatControl;
using $JarEntry = ::java::util::jar::JarEntry;
using $Bundles = ::sun::util::resources::Bundles;

namespace java {
	namespace util {

class ResourceBundle$Control$$Lambda$lambda$newBundle0$0 : public $PrivilegedAction {
	$class(ResourceBundle$Control$$Lambda$lambda$newBundle0$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$($Constructor* ctor) {
		$set(this, ctor, ctor);
	}
	virtual $Object* run() override {
		 return $of(ResourceBundle$Control::lambda$newBundle0$0(ctor));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ResourceBundle$Control$$Lambda$lambda$newBundle0$0>());
	}
	$Constructor* ctor = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ResourceBundle$Control$$Lambda$lambda$newBundle0$0::fieldInfos[2] = {
	{"ctor", "Ljava/lang/reflect/Constructor;", nullptr, $PUBLIC, $field(ResourceBundle$Control$$Lambda$lambda$newBundle0$0, ctor)},
	{}
};
$MethodInfo ResourceBundle$Control$$Lambda$lambda$newBundle0$0::methodInfos[3] = {
	{"<init>", "(Ljava/lang/reflect/Constructor;)V", nullptr, $PUBLIC, $method(ResourceBundle$Control$$Lambda$lambda$newBundle0$0, init$, void, $Constructor*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ResourceBundle$Control$$Lambda$lambda$newBundle0$0, run, $Object*)},
	{}
};
$ClassInfo ResourceBundle$Control$$Lambda$lambda$newBundle0$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.ResourceBundle$Control$$Lambda$lambda$newBundle0$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* ResourceBundle$Control$$Lambda$lambda$newBundle0$0::load$($String* name, bool initialize) {
	$loadClass(ResourceBundle$Control$$Lambda$lambda$newBundle0$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ResourceBundle$Control$$Lambda$lambda$newBundle0$0::class$ = nullptr;

$FieldInfo _ResourceBundle$Control_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(ResourceBundle$Control, $assertionsDisabled)},
	{"FORMAT_DEFAULT", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/String;>;", $PUBLIC | $STATIC | $FINAL, $staticField(ResourceBundle$Control, FORMAT_DEFAULT)},
	{"FORMAT_CLASS", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/String;>;", $PUBLIC | $STATIC | $FINAL, $staticField(ResourceBundle$Control, FORMAT_CLASS)},
	{"FORMAT_PROPERTIES", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/String;>;", $PUBLIC | $STATIC | $FINAL, $staticField(ResourceBundle$Control, FORMAT_PROPERTIES)},
	{"TTL_DONT_CACHE", "J", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(ResourceBundle$Control, TTL_DONT_CACHE)},
	{"TTL_NO_EXPIRATION_CONTROL", "J", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(ResourceBundle$Control, TTL_NO_EXPIRATION_CONTROL)},
	{"INSTANCE", "Ljava/util/ResourceBundle$Control;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ResourceBundle$Control, INSTANCE)},
	{"CANDIDATES_CACHE", "Ljava/util/ResourceBundle$Control$CandidateListCache;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ResourceBundle$Control, CANDIDATES_CACHE)},
	{}
};

$MethodInfo _ResourceBundle$Control_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PROTECTED, $method(ResourceBundle$Control, init$, void)},
	{"getCandidateLocales", "(Ljava/lang/String;Ljava/util/Locale;)Ljava/util/List;", "(Ljava/lang/String;Ljava/util/Locale;)Ljava/util/List<Ljava/util/Locale;>;", $PUBLIC, $virtualMethod(ResourceBundle$Control, getCandidateLocales, $List*, $String*, $Locale*)},
	{"getControl", "(Ljava/util/List;)Ljava/util/ResourceBundle$Control;", "(Ljava/util/List<Ljava/lang/String;>;)Ljava/util/ResourceBundle$Control;", $PUBLIC | $STATIC | $FINAL, $staticMethod(ResourceBundle$Control, getControl, ResourceBundle$Control*, $List*)},
	{"getFallbackLocale", "(Ljava/lang/String;Ljava/util/Locale;)Ljava/util/Locale;", nullptr, $PUBLIC, $virtualMethod(ResourceBundle$Control, getFallbackLocale, $Locale*, $String*, $Locale*)},
	{"getFormats", "(Ljava/lang/String;)Ljava/util/List;", "(Ljava/lang/String;)Ljava/util/List<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(ResourceBundle$Control, getFormats, $List*, $String*)},
	{"getNoFallbackControl", "(Ljava/util/List;)Ljava/util/ResourceBundle$Control;", "(Ljava/util/List<Ljava/lang/String;>;)Ljava/util/ResourceBundle$Control;", $PUBLIC | $STATIC | $FINAL, $staticMethod(ResourceBundle$Control, getNoFallbackControl, ResourceBundle$Control*, $List*)},
	{"getTimeToLive", "(Ljava/lang/String;Ljava/util/Locale;)J", nullptr, $PUBLIC, $virtualMethod(ResourceBundle$Control, getTimeToLive, int64_t, $String*, $Locale*)},
	{"lambda$newBundle0$0", "(Ljava/lang/reflect/Constructor;)Ljava/lang/Void;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ResourceBundle$Control, lambda$newBundle0$0, $Void*, $Constructor*)},
	{"needsReload", "(Ljava/lang/String;Ljava/util/Locale;Ljava/lang/String;Ljava/lang/ClassLoader;Ljava/util/ResourceBundle;J)Z", nullptr, $PUBLIC, $virtualMethod(ResourceBundle$Control, needsReload, bool, $String*, $Locale*, $String*, $ClassLoader*, $ResourceBundle*, int64_t)},
	{"newBundle", "(Ljava/lang/String;Ljava/util/Locale;Ljava/lang/String;Ljava/lang/ClassLoader;Z)Ljava/util/ResourceBundle;", nullptr, $PUBLIC, $virtualMethod(ResourceBundle$Control, newBundle, $ResourceBundle*, $String*, $Locale*, $String*, $ClassLoader*, bool), "java.lang.IllegalAccessException,java.lang.InstantiationException,java.io.IOException"},
	{"newBundle0", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/ClassLoader;Z)Ljava/util/ResourceBundle;", nullptr, $PRIVATE, $method(ResourceBundle$Control, newBundle0, $ResourceBundle*, $String*, $String*, $ClassLoader*, bool), "java.lang.IllegalAccessException,java.lang.InstantiationException,java.io.IOException"},
	{"toBundleName", "(Ljava/lang/String;Ljava/util/Locale;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ResourceBundle$Control, toBundleName, $String*, $String*, $Locale*)},
	{"toResourceName", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $FINAL, $method(ResourceBundle$Control, toResourceName, $String*, $String*, $String*)},
	{"toResourceName0", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE, $method(ResourceBundle$Control, toResourceName0, $String*, $String*, $String*)},
	{}
};

$InnerClassInfo _ResourceBundle$Control_InnerClassesInfo_[] = {
	{"java.util.ResourceBundle$Control", "java.util.ResourceBundle", "Control", $PUBLIC | $STATIC},
	{"java.util.ResourceBundle$Control$CandidateListCache", "java.util.ResourceBundle$Control", "CandidateListCache", $PRIVATE | $STATIC},
	{"java.util.ResourceBundle$Control$2", nullptr, nullptr, 0},
	{"java.util.ResourceBundle$Control$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ResourceBundle$Control_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.ResourceBundle$Control",
	"java.lang.Object",
	nullptr,
	_ResourceBundle$Control_FieldInfo_,
	_ResourceBundle$Control_MethodInfo_,
	nullptr,
	nullptr,
	_ResourceBundle$Control_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.ResourceBundle"
};

$Object* allocate$ResourceBundle$Control($Class* clazz) {
	return $of($alloc(ResourceBundle$Control));
}

bool ResourceBundle$Control::$assertionsDisabled = false;
$List* ResourceBundle$Control::FORMAT_DEFAULT = nullptr;
$List* ResourceBundle$Control::FORMAT_CLASS = nullptr;
$List* ResourceBundle$Control::FORMAT_PROPERTIES = nullptr;
ResourceBundle$Control* ResourceBundle$Control::INSTANCE = nullptr;
$ResourceBundle$Control$CandidateListCache* ResourceBundle$Control::CANDIDATES_CACHE = nullptr;

void ResourceBundle$Control::init$() {
}

ResourceBundle$Control* ResourceBundle$Control::getControl($List* formats) {
	$init(ResourceBundle$Control);
	if ($nc(formats)->equals(ResourceBundle$Control::FORMAT_PROPERTIES)) {
		$init($ResourceBundle$SingleFormatControl);
		return $ResourceBundle$SingleFormatControl::PROPERTIES_ONLY;
	}
	if ($nc(formats)->equals(ResourceBundle$Control::FORMAT_CLASS)) {
		$init($ResourceBundle$SingleFormatControl);
		return $ResourceBundle$SingleFormatControl::CLASS_ONLY;
	}
	if ($nc(formats)->equals(ResourceBundle$Control::FORMAT_DEFAULT)) {
		return ResourceBundle$Control::INSTANCE;
	}
	$throwNew($IllegalArgumentException);
}

ResourceBundle$Control* ResourceBundle$Control::getNoFallbackControl($List* formats) {
	$init(ResourceBundle$Control);
	if ($nc(formats)->equals(ResourceBundle$Control::FORMAT_DEFAULT)) {
		$init($ResourceBundle$NoFallbackControl);
		return $ResourceBundle$NoFallbackControl::NO_FALLBACK;
	}
	if ($nc(formats)->equals(ResourceBundle$Control::FORMAT_PROPERTIES)) {
		$init($ResourceBundle$NoFallbackControl);
		return $ResourceBundle$NoFallbackControl::PROPERTIES_ONLY_NO_FALLBACK;
	}
	if ($nc(formats)->equals(ResourceBundle$Control::FORMAT_CLASS)) {
		$init($ResourceBundle$NoFallbackControl);
		return $ResourceBundle$NoFallbackControl::CLASS_ONLY_NO_FALLBACK;
	}
	$throwNew($IllegalArgumentException);
}

$List* ResourceBundle$Control::getFormats($String* baseName) {
	if (baseName == nullptr) {
		$throwNew($NullPointerException);
	}
	return ResourceBundle$Control::FORMAT_DEFAULT;
}

$List* ResourceBundle$Control::getCandidateLocales($String* baseName, $Locale* locale) {
	$useLocalCurrentObjectStackCache();
	if (baseName == nullptr) {
		$throwNew($NullPointerException);
	}
	return $new($ArrayList, $cast($Collection, $($nc(ResourceBundle$Control::CANDIDATES_CACHE)->get($($nc(locale)->getBaseLocale())))));
}

$Locale* ResourceBundle$Control::getFallbackLocale($String* baseName, $Locale* locale) {
	if (baseName == nullptr) {
		$throwNew($NullPointerException);
	}
	$var($Locale, defaultLocale, $Locale::getDefault());
	return $nc(locale)->equals(defaultLocale) ? ($Locale*)nullptr : defaultLocale;
}

$ResourceBundle* ResourceBundle$Control::newBundle($String* baseName, $Locale* locale, $String* format, $ClassLoader* loader, bool reload) {
	$useLocalCurrentObjectStackCache();
	$var($String, bundleName, toBundleName(baseName, locale));
	$var($ResourceBundle, bundle, newBundle0(bundleName, format, loader, reload));
	if (bundle == nullptr) {
		$var($String, otherBundleName, $Bundles::toOtherBundleName(baseName, bundleName, locale));
		if (!$nc(bundleName)->equals(otherBundleName)) {
			$assign(bundle, newBundle0(otherBundleName, format, loader, reload));
		}
	}
	return bundle;
}

$ResourceBundle* ResourceBundle$Control::newBundle0($String* bundleName, $String* format, $ClassLoader* loader, bool reload) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($ResourceBundle, bundle, nullptr);
	if ($nc(format)->equals("java.class"_s)) {
		try {
			$Class* c = $nc(loader)->loadClass(bundleName);
			$load($ResourceBundle);
			if ($ResourceBundle::class$->isAssignableFrom(c)) {
				$Class* bundleClass = c;
				$var($Module, m, $nc(bundleClass)->getModule());
				bool var$0 = $nc(m)->isNamed();
				if (var$0 && !m->isOpen($(bundleClass->getPackageName()))) {
					$var($String, var$1, $$str({"unnamed module can\'t load "_s, $(bundleClass->getName()), " in "_s}));
					$throwNew($IllegalAccessException, $$concat(var$1, $(m->toString())));
				}
				try {
					$var($Constructor, ctor, $cast($Constructor, $AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new($ResourceBundle$Control$1, this, bundleClass)))));
					if (!$Modifier::isPublic($nc(ctor)->getModifiers())) {
						$throwNew($IllegalAccessException, $$str({"no-arg constructor in "_s, $(bundleClass->getName()), " is not publicly accessible."_s}));
					}
					$var($PrivilegedAction, pa1, static_cast<$PrivilegedAction*>($new(ResourceBundle$Control$$Lambda$lambda$newBundle0$0, ctor)));
					$AccessController::doPrivileged(pa1);
					$assign(bundle, $cast($ResourceBundle, $nc(ctor)->newInstance(($ObjectArray*)nullptr)));
				} catch ($InvocationTargetException& e) {
					$ResourceBundle::uncheckedThrow(e);
				} catch ($PrivilegedActionException& e) {
					if (!ResourceBundle$Control::$assertionsDisabled && !$instanceOf($NoSuchMethodException, $(e->getCause()))) {
						$throwNew($AssertionError);
					}
					$throwNew($InstantiationException, $$str({"public no-arg constructor does not exist in "_s, $(bundleClass->getName())}));
				}
			} else {
				$throwNew($ClassCastException, $$str({$($nc(c)->getName()), " cannot be cast to ResourceBundle"_s}));
			}
		} catch ($ClassNotFoundException& e) {
		}
	} else if (format->equals("java.properties"_s)) {
		$var($String, resourceName, toResourceName0(bundleName, "properties"_s));
		if (resourceName == nullptr) {
			return bundle;
		}
		bool reloadFlag = reload;
		$var($InputStream, stream, nullptr);
		try {
			$assign(stream, $cast($InputStream, $AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new($ResourceBundle$Control$2, this, loader, resourceName, reloadFlag)))));
		} catch ($PrivilegedActionException& e) {
			$throw($cast($IOException, $(e->getCause())));
		}
		if (stream != nullptr) {
			{
				$var($Throwable, var$2, nullptr);
				try {
					$assign(bundle, $new($PropertyResourceBundle, stream));
				} catch ($Throwable& var$3) {
					$assign(var$2, var$3);
				} /*finally*/ {
					stream->close();
				}
				if (var$2 != nullptr) {
					$throw(var$2);
				}
			}
		}
	} else {
		$throwNew($IllegalArgumentException, $$str({"unknown format: "_s, format}));
	}
	return bundle;
}

int64_t ResourceBundle$Control::getTimeToLive($String* baseName, $Locale* locale) {
	if (baseName == nullptr || locale == nullptr) {
		$throwNew($NullPointerException);
	}
	return ResourceBundle$Control::TTL_NO_EXPIRATION_CONTROL;
}

bool ResourceBundle$Control::needsReload($String* baseName, $Locale* locale, $String* format$renamed, $ClassLoader* loader, $ResourceBundle* bundle, int64_t loadTime) {
	$useLocalCurrentObjectStackCache();
	$var($String, format, format$renamed);
	if (bundle == nullptr) {
		$throwNew($NullPointerException);
	}
	bool var$0 = $nc(format)->equals("java.class"_s);
	if (var$0 || $nc(format)->equals("java.properties"_s)) {
		$assign(format, format->substring(5));
	}
	bool result = false;
	try {
		$var($String, resourceName, toResourceName0($(toBundleName(baseName, locale)), format));
		if (resourceName == nullptr) {
			return result;
		}
		$var($URL, url, $nc(loader)->getResource(resourceName));
		if (url != nullptr) {
			int64_t lastModified = 0;
			$var($URLConnection, connection, url->openConnection());
			if (connection != nullptr) {
				connection->setUseCaches(false);
				if ($instanceOf($JarURLConnection, connection)) {
					$var($JarEntry, ent, $nc(($cast($JarURLConnection, connection)))->getJarEntry());
					if (ent != nullptr) {
						lastModified = ent->getTime();
						if (lastModified == -1) {
							lastModified = 0;
						}
					}
				} else {
					lastModified = connection->getLastModified();
				}
			}
			result = lastModified >= loadTime;
		}
	} catch ($NullPointerException& npe) {
		$throw(npe);
	} catch ($Exception& e) {
	}
	return result;
}

$String* ResourceBundle$Control::toBundleName($String* baseName, $Locale* locale) {
	$useLocalCurrentObjectStackCache();
	$init($Locale);
	if (locale == $Locale::ROOT) {
		return baseName;
	}
	$var($String, language, $nc(locale)->getLanguage());
	$var($String, script, locale->getScript());
	$var($String, country, locale->getCountry());
	$var($String, variant, locale->getVariant());
	if (language == ""_s && country == ""_s && variant == ""_s) {
		return baseName;
	}
	$var($StringBuilder, sb, $new($StringBuilder, baseName));
	sb->append(u'_');
	if (script != ""_s) {
		if (variant != ""_s) {
			sb->append(language)->append(u'_')->append(script)->append(u'_')->append(country)->append(u'_')->append(variant);
		} else if (country != ""_s) {
			sb->append(language)->append(u'_')->append(script)->append(u'_')->append(country);
		} else {
			sb->append(language)->append(u'_')->append(script);
		}
	} else if (variant != ""_s) {
		sb->append(language)->append(u'_')->append(country)->append(u'_')->append(variant);
	} else if (country != ""_s) {
		sb->append(language)->append(u'_')->append(country);
	} else {
		sb->append(language);
	}
	return sb->toString();
}

$String* ResourceBundle$Control::toResourceName($String* bundleName, $String* suffix) {
	$useLocalCurrentObjectStackCache();
	int32_t var$0 = $nc(bundleName)->length() + 1;
	$var($StringBuilder, sb, $new($StringBuilder, var$0 + $nc(suffix)->length()));
	sb->append($($nc(bundleName)->replace(u'.', u'/')))->append(u'.')->append(suffix);
	return sb->toString();
}

$String* ResourceBundle$Control::toResourceName0($String* bundleName, $String* suffix) {
	if ($nc(bundleName)->contains("://"_s)) {
		return nullptr;
	} else {
		return toResourceName(bundleName, suffix);
	}
}

$Void* ResourceBundle$Control::lambda$newBundle0$0($Constructor* ctor) {
	$init(ResourceBundle$Control);
	$beforeCallerSensitive();
	$nc(ctor)->setAccessible(true);
	return nullptr;
}

void clinit$ResourceBundle$Control($Class* class$) {
	$load($ResourceBundle);
	ResourceBundle$Control::$assertionsDisabled = !$ResourceBundle::class$->desiredAssertionStatus();
	$assignStatic(ResourceBundle$Control::FORMAT_DEFAULT, $List::of("java.class"_s, "java.properties"_s));
	$assignStatic(ResourceBundle$Control::FORMAT_CLASS, $List::of($of("java.class"_s)));
	$assignStatic(ResourceBundle$Control::FORMAT_PROPERTIES, $List::of($of("java.properties"_s)));
	$assignStatic(ResourceBundle$Control::INSTANCE, $new(ResourceBundle$Control));
	$assignStatic(ResourceBundle$Control::CANDIDATES_CACHE, $new($ResourceBundle$Control$CandidateListCache));
}

ResourceBundle$Control::ResourceBundle$Control() {
}

$Class* ResourceBundle$Control::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ResourceBundle$Control$$Lambda$lambda$newBundle0$0::classInfo$.name)) {
			return ResourceBundle$Control$$Lambda$lambda$newBundle0$0::load$(name, initialize);
		}
	}
	$loadClass(ResourceBundle$Control, name, initialize, &_ResourceBundle$Control_ClassInfo_, clinit$ResourceBundle$Control, allocate$ResourceBundle$Control);
	return class$;
}

$Class* ResourceBundle$Control::class$ = nullptr;

	} // util
} // java