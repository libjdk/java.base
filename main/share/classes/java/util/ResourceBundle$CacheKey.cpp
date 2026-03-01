#include <java/util/ResourceBundle$CacheKey.h>

#include <java/lang/ClassCastException.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/Module.h>
#include <java/lang/ref/Reference.h>
#include <java/lang/ref/ReferenceQueue.h>
#include <java/util/Locale.h>
#include <java/util/Objects.h>
#include <java/util/ResourceBundle$KeyElementReference.h>
#include <java/util/ResourceBundle.h>
#include <java/util/ServiceLoader.h>
#include <jcpp.h>

#undef TRUE

using $Boolean = ::java::lang::Boolean;
using $ClassCastException = ::java::lang::ClassCastException;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Module = ::java::lang::Module;
using $NullPointerException = ::java::lang::NullPointerException;
using $Locale = ::java::util::Locale;
using $Objects = ::java::util::Objects;
using $ResourceBundle = ::java::util::ResourceBundle;
using $ResourceBundle$KeyElementReference = ::java::util::ResourceBundle$KeyElementReference;
using $ServiceLoader = ::java::util::ServiceLoader;

namespace java {
	namespace util {

$FieldInfo _ResourceBundle$CacheKey_FieldInfo_[] = {
	{"name", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(ResourceBundle$CacheKey, name)},
	{"locale", "Ljava/util/Locale;", nullptr, $PRIVATE | $VOLATILE, $field(ResourceBundle$CacheKey, locale)},
	{"moduleRef", "Ljava/util/ResourceBundle$KeyElementReference;", "Ljava/util/ResourceBundle$KeyElementReference<Ljava/lang/Module;>;", $PRIVATE | $FINAL, $field(ResourceBundle$CacheKey, moduleRef)},
	{"callerRef", "Ljava/util/ResourceBundle$KeyElementReference;", "Ljava/util/ResourceBundle$KeyElementReference<Ljava/lang/Module;>;", $PRIVATE | $FINAL, $field(ResourceBundle$CacheKey, callerRef)},
	{"modulesHash", "I", nullptr, $PRIVATE | $FINAL, $field(ResourceBundle$CacheKey, modulesHash)},
	{"format", "Ljava/lang/String;", nullptr, $PRIVATE | $VOLATILE, $field(ResourceBundle$CacheKey, format)},
	{"loadTime", "J", nullptr, $PRIVATE | $VOLATILE, $field(ResourceBundle$CacheKey, loadTime)},
	{"expirationTime", "J", nullptr, $PRIVATE | $VOLATILE, $field(ResourceBundle$CacheKey, expirationTime)},
	{"cause", "Ljava/lang/Throwable;", nullptr, $PRIVATE | $VOLATILE, $field(ResourceBundle$CacheKey, cause)},
	{"providers", "Ljava/util/ServiceLoader;", "Ljava/util/ServiceLoader<Ljava/util/spi/ResourceBundleProvider;>;", $PRIVATE | $VOLATILE, $field(ResourceBundle$CacheKey, providers)},
	{"providersChecked", "Z", nullptr, $PRIVATE | $VOLATILE, $field(ResourceBundle$CacheKey, providersChecked)},
	{"callerHasProvider", "Ljava/lang/Boolean;", nullptr, $PRIVATE | $VOLATILE, $field(ResourceBundle$CacheKey, callerHasProvider$)},
	{}
};

$MethodInfo _ResourceBundle$CacheKey_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Ljava/util/Locale;Ljava/lang/Module;Ljava/lang/Module;)V", nullptr, 0, $method(ResourceBundle$CacheKey, init$, void, $String*, $Locale*, $Module*, $Module*)},
	{"<init>", "(Ljava/util/ResourceBundle$CacheKey;)V", nullptr, 0, $method(ResourceBundle$CacheKey, init$, void, ResourceBundle$CacheKey*)},
	{"callerHasProvider", "()Z", nullptr, 0, $method(ResourceBundle$CacheKey, callerHasProvider, bool)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ResourceBundle$CacheKey, equals, bool, Object$*)},
	{"getCallerModule", "()Ljava/lang/Module;", nullptr, 0, $method(ResourceBundle$CacheKey, getCallerModule, $Module*)},
	{"getCause", "()Ljava/lang/Throwable;", nullptr, $PRIVATE, $method(ResourceBundle$CacheKey, getCause, $Throwable*)},
	{"getFormat", "()Ljava/lang/String;", nullptr, 0, $method(ResourceBundle$CacheKey, getFormat, $String*)},
	{"getLocale", "()Ljava/util/Locale;", nullptr, 0, $method(ResourceBundle$CacheKey, getLocale, $Locale*)},
	{"getModule", "()Ljava/lang/Module;", nullptr, 0, $method(ResourceBundle$CacheKey, getModule, $Module*)},
	{"getName", "()Ljava/lang/String;", nullptr, 0, $method(ResourceBundle$CacheKey, getName, $String*)},
	{"getProviders", "()Ljava/util/ServiceLoader;", "()Ljava/util/ServiceLoader<Ljava/util/spi/ResourceBundleProvider;>;", 0, $method(ResourceBundle$CacheKey, getProviders, $ServiceLoader*)},
	{"hasProviders", "()Z", nullptr, 0, $method(ResourceBundle$CacheKey, hasProviders, bool)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(ResourceBundle$CacheKey, hashCode, int32_t)},
	{"setCause", "(Ljava/lang/Throwable;)V", nullptr, $PRIVATE, $method(ResourceBundle$CacheKey, setCause, void, $Throwable*)},
	{"setFormat", "(Ljava/lang/String;)V", nullptr, 0, $method(ResourceBundle$CacheKey, setFormat, void, $String*)},
	{"setLocale", "(Ljava/util/Locale;)Ljava/util/ResourceBundle$CacheKey;", nullptr, 0, $method(ResourceBundle$CacheKey, setLocale, ResourceBundle$CacheKey*, $Locale*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ResourceBundle$CacheKey, toString, $String*)},
	{}
};

$InnerClassInfo _ResourceBundle$CacheKey_InnerClassesInfo_[] = {
	{"java.util.ResourceBundle$CacheKey", "java.util.ResourceBundle", "CacheKey", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _ResourceBundle$CacheKey_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.ResourceBundle$CacheKey",
	"java.lang.Object",
	nullptr,
	_ResourceBundle$CacheKey_FieldInfo_,
	_ResourceBundle$CacheKey_MethodInfo_,
	nullptr,
	nullptr,
	_ResourceBundle$CacheKey_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.ResourceBundle"
};

$Object* allocate$ResourceBundle$CacheKey($Class* clazz) {
	return $of($alloc(ResourceBundle$CacheKey));
}

void ResourceBundle$CacheKey::init$($String* baseName, $Locale* locale, $Module* module, $Module* caller) {
	$Objects::requireNonNull(module);
	$Objects::requireNonNull(caller);
	$set(this, name, baseName);
	$set(this, locale, locale);
	$init($ResourceBundle);
	$set(this, moduleRef, $new($ResourceBundle$KeyElementReference, module, $ResourceBundle::referenceQueue, this));
	$set(this, callerRef, $new($ResourceBundle$KeyElementReference, caller, $ResourceBundle::referenceQueue, this));
	int32_t var$0 = $of(module)->hashCode();
	this->modulesHash = var$0 ^ $of(caller)->hashCode();
}

void ResourceBundle$CacheKey::init$(ResourceBundle$CacheKey* src) {
	$useLocalCurrentObjectStackCache();
	$init($ResourceBundle);
	$set(this, moduleRef, $new($ResourceBundle$KeyElementReference, $cast($Module, $Objects::requireNonNull($($nc(src)->getModule()))), $ResourceBundle::referenceQueue, this));
	$set(this, callerRef, $new($ResourceBundle$KeyElementReference, $cast($Module, $Objects::requireNonNull($($nc(src)->getCallerModule()))), $ResourceBundle::referenceQueue, this));
	$set(this, name, $nc(src)->name);
	$set(this, locale, src->locale);
	this->modulesHash = src->modulesHash;
	$set(this, format, src->format);
	this->loadTime = src->loadTime;
	this->expirationTime = src->expirationTime;
}

$String* ResourceBundle$CacheKey::getName() {
	return this->name;
}

$Locale* ResourceBundle$CacheKey::getLocale() {
	return this->locale;
}

ResourceBundle$CacheKey* ResourceBundle$CacheKey::setLocale($Locale* locale) {
	$set(this, locale, locale);
	return this;
}

$Module* ResourceBundle$CacheKey::getModule() {
	return $cast($Module, $nc(this->moduleRef)->get());
}

$Module* ResourceBundle$CacheKey::getCallerModule() {
	return $cast($Module, $nc(this->callerRef)->get());
}

$ServiceLoader* ResourceBundle$CacheKey::getProviders() {
	if (!this->providersChecked) {
		$set(this, providers, $ResourceBundle::getServiceLoader($(getModule()), this->name));
		this->providersChecked = true;
	}
	return this->providers;
}

bool ResourceBundle$CacheKey::hasProviders() {
	return getProviders() != nullptr;
}

bool ResourceBundle$CacheKey::callerHasProvider() {
	$init($Boolean);
	return this->callerHasProvider$ == $Boolean::TRUE;
}

bool ResourceBundle$CacheKey::equals(Object$* other) {
	$useLocalCurrentObjectStackCache();
	if ($equals(this, other)) {
		return true;
	}
	try {
		$var(ResourceBundle$CacheKey, otherEntry, $cast(ResourceBundle$CacheKey, other));
		if (this->modulesHash != $nc(otherEntry)->modulesHash) {
			return false;
		}
		if (!$nc(this->name)->equals($nc(otherEntry)->name)) {
			return false;
		}
		if (!$nc(this->locale)->equals($nc(otherEntry)->locale)) {
			return false;
		}
		$var($Module, module, getModule());
		$var($Module, caller, getCallerModule());
		bool var$0 = (module != nullptr) && ($of(module)->equals($($nc(otherEntry)->getModule()))) && (caller != nullptr);
		return (var$0 && ($of(caller)->equals($($nc(otherEntry)->getCallerModule()))));
	} catch ($NullPointerException& e) {
	} catch ($ClassCastException& e) {
	}
	return false;
}

int32_t ResourceBundle$CacheKey::hashCode() {
	int32_t var$0 = ($nc(this->name)->hashCode() << 3);
	return (var$0 ^ $nc(this->locale)->hashCode()) ^ this->modulesHash;
}

$String* ResourceBundle$CacheKey::getFormat() {
	return this->format;
}

void ResourceBundle$CacheKey::setFormat($String* format) {
	$set(this, format, format);
}

void ResourceBundle$CacheKey::setCause($Throwable* cause) {
	if (this->cause == nullptr) {
		$set(this, cause, cause);
	} else if ($instanceOf($ClassNotFoundException, this->cause)) {
		$set(this, cause, cause);
	}
}

$Throwable* ResourceBundle$CacheKey::getCause() {
	return this->cause;
}

$String* ResourceBundle$CacheKey::toString() {
	$useLocalCurrentObjectStackCache();
	$var($String, l, $nc(this->locale)->toString());
	if ($nc(l)->isEmpty()) {
		if (!$nc($($nc(this->locale)->getVariant()))->isEmpty()) {
			$assign(l, $str({"__"_s, $($nc(this->locale)->getVariant())}));
		} else {
			$assign(l, "\"\""_s);
		}
	}
	$var($String, var$3, $$str({"CacheKey["_s, this->name, ", locale="_s, l, ", module="_s, $(getModule()), ", callerModule="_s}));
	$var($String, var$2, $$concat(var$3, $(getCallerModule())));
	$var($String, var$1, $$concat(var$2, ", format="_s));
	$var($String, var$0, $$concat(var$1, this->format));
	return $concat(var$0, "]"_s);
}

ResourceBundle$CacheKey::ResourceBundle$CacheKey() {
}

$Class* ResourceBundle$CacheKey::load$($String* name, bool initialize) {
	$loadClass(ResourceBundle$CacheKey, name, initialize, &_ResourceBundle$CacheKey_ClassInfo_, allocate$ResourceBundle$CacheKey);
	return class$;
}

$Class* ResourceBundle$CacheKey::class$ = nullptr;

	} // util
} // java