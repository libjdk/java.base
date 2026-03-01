#include <java/security/Provider.h>

#include <java/io/InputStream.h>
#include <java/io/ObjectInputStream.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/NumberFormatException.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/security/Provider$EngineDescription.h>
#include <java/security/Provider$Service.h>
#include <java/security/Provider$ServiceKey.h>
#include <java/util/AbstractMap.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Enumeration.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedHashMap.h>
#include <java/util/LinkedHashSet.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Properties.h>
#include <java/util/Set.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/BiFunction.h>
#include <java/util/function/Function.h>
#include <sun/security/util/Debug.h>
#include <jcpp.h>

#undef ALIAS_LENGTH
#undef ALIAS_PREFIX
#undef ALIAS_PREFIX_LOWER
#undef EMPTY
#undef ENGLISH

using $InputStream = ::java::io::InputStream;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Double = ::java::lang::Double;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NamedAttribute = ::java::lang::NamedAttribute;
using $NullPointerException = ::java::lang::NullPointerException;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $RuntimeException = ::java::lang::RuntimeException;
using $SecurityManager = ::java::lang::SecurityManager;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $Provider$EngineDescription = ::java::security::Provider$EngineDescription;
using $Provider$Service = ::java::security::Provider$Service;
using $Provider$ServiceKey = ::java::security::Provider$ServiceKey;
using $AbstractMap = ::java::util::AbstractMap;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Enumeration = ::java::util::Enumeration;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $LinkedHashMap = ::java::util::LinkedHashMap;
using $LinkedHashSet = ::java::util::LinkedHashSet;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Objects = ::java::util::Objects;
using $Properties = ::java::util::Properties;
using $Set = ::java::util::Set;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $BiConsumer = ::java::util::function::BiConsumer;
using $BiFunction = ::java::util::function::BiFunction;
using $Function = ::java::util::function::Function;
using $Debug = ::sun::security::util::Debug;

namespace java {
	namespace security {

$NamedAttribute Provider_Attribute_var$0[] = {
	{"since", 's', "9"},
	{}
};

$CompoundAttribute _Provider_MethodAnnotations_init$0[] = {
	{"Ljava/lang/Deprecated;", Provider_Attribute_var$0},
	{}
};

$NamedAttribute Provider_Attribute_var$1[] = {
	{"since", 's', "9"},
	{}
};

$CompoundAttribute _Provider_MethodAnnotations_getVersion25[] = {
	{"Ljava/lang/Deprecated;", Provider_Attribute_var$1},
	{}
};

$FieldInfo _Provider_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Provider, serialVersionUID)},
	{"debug", "Lsun/security/util/Debug;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Provider, debug)},
	{"name", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Provider, name)},
	{"info", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Provider, info)},
	{"version", "D", nullptr, $PRIVATE, $field(Provider, version)},
	{"versionStr", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Provider, versionStr)},
	{"entrySet", "Ljava/util/Set;", "Ljava/util/Set<Ljava/util/Map$Entry<Ljava/lang/Object;Ljava/lang/Object;>;>;", $PRIVATE | $TRANSIENT, $field(Provider, entrySet$)},
	{"entrySetCallCount", "I", nullptr, $PRIVATE | $TRANSIENT, $field(Provider, entrySetCallCount)},
	{"initialized", "Z", nullptr, $PRIVATE | $TRANSIENT, $field(Provider, initialized)},
	{"EMPTY", "[Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Provider, EMPTY)},
	{"legacyChanged", "Z", nullptr, $PRIVATE | $TRANSIENT, $field(Provider, legacyChanged)},
	{"servicesChanged", "Z", nullptr, $PRIVATE | $VOLATILE | $TRANSIENT, $field(Provider, servicesChanged)},
	{"legacyStrings", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;", $PRIVATE | $TRANSIENT, $field(Provider, legacyStrings)},
	{"serviceMap", "Ljava/util/Map;", "Ljava/util/Map<Ljava/security/Provider$ServiceKey;Ljava/security/Provider$Service;>;", $PRIVATE | $TRANSIENT, $field(Provider, serviceMap)},
	{"prngAlgos", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE | $TRANSIENT, $field(Provider, prngAlgos)},
	{"legacyMap", "Ljava/util/Map;", "Ljava/util/Map<Ljava/security/Provider$ServiceKey;Ljava/security/Provider$Service;>;", $PRIVATE | $TRANSIENT, $field(Provider, legacyMap)},
	{"serviceSet", "Ljava/util/Set;", "Ljava/util/Set<Ljava/security/Provider$Service;>;", $PRIVATE | $TRANSIENT, $field(Provider, serviceSet)},
	{"ALIAS_PREFIX", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Provider, ALIAS_PREFIX)},
	{"ALIAS_PREFIX_LOWER", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Provider, ALIAS_PREFIX_LOWER)},
	{"ALIAS_LENGTH", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Provider, ALIAS_LENGTH)},
	{"previousKey", "Ljava/security/Provider$ServiceKey;", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(Provider, previousKey)},
	{"knownEngines", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/security/Provider$EngineDescription;>;", $PRIVATE | $STATIC | $FINAL, $staticField(Provider, knownEngines)},
	{}
};

$MethodInfo _Provider_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;DLjava/lang/String;)V", nullptr, $PROTECTED | $DEPRECATED, $method(Provider, init$, void, $String*, double, $String*), nullptr, nullptr, _Provider_MethodAnnotations_init$0},
	{"<init>", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PROTECTED, $method(Provider, init$, void, $String*, $String*, $String*)},
	{"addEngine", "(Ljava/lang/String;ZLjava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Provider, addEngine, void, $String*, bool, $String*)},
	{"check", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(Provider, check, void, $String*)},
	{"checkInitialized", "()V", nullptr, $PRIVATE, $method(Provider, checkInitialized, void)},
	{"checkLegacy", "(Ljava/lang/Object;)Z", nullptr, $PRIVATE, $method(Provider, checkLegacy, bool, Object$*)},
	{"clear", "()V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Provider, clear, void)},
	{"compute", "(Ljava/lang/Object;Ljava/util/function/BiFunction;)Ljava/lang/Object;", "(Ljava/lang/Object;Ljava/util/function/BiFunction<-Ljava/lang/Object;-Ljava/lang/Object;+Ljava/lang/Object;>;)Ljava/lang/Object;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Provider, compute, $Object*, Object$*, $BiFunction*)},
	{"computeIfAbsent", "(Ljava/lang/Object;Ljava/util/function/Function;)Ljava/lang/Object;", "(Ljava/lang/Object;Ljava/util/function/Function<-Ljava/lang/Object;+Ljava/lang/Object;>;)Ljava/lang/Object;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Provider, computeIfAbsent, $Object*, Object$*, $Function*)},
	{"computeIfPresent", "(Ljava/lang/Object;Ljava/util/function/BiFunction;)Ljava/lang/Object;", "(Ljava/lang/Object;Ljava/util/function/BiFunction<-Ljava/lang/Object;-Ljava/lang/Object;+Ljava/lang/Object;>;)Ljava/lang/Object;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Provider, computeIfPresent, $Object*, Object$*, $BiFunction*)},
	{"configure", "(Ljava/lang/String;)Ljava/security/Provider;", nullptr, $PUBLIC, $virtualMethod(Provider, configure, Provider*, $String*)},
	{"elements", "()Ljava/util/Enumeration;", "()Ljava/util/Enumeration<Ljava/lang/Object;>;", $PUBLIC, $virtualMethod(Provider, elements, $Enumeration*)},
	{"ensureLegacyParsed", "()V", nullptr, $PRIVATE, $method(Provider, ensureLegacyParsed, void)},
	{"entrySet", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/util/Map$Entry<Ljava/lang/Object;Ljava/lang/Object;>;>;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Provider, entrySet, $Set*)},
	{"forEach", "(Ljava/util/function/BiConsumer;)V", "(Ljava/util/function/BiConsumer<-Ljava/lang/Object;-Ljava/lang/Object;>;)V", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Provider, forEach, void, $BiConsumer*)},
	{"get", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Provider, get, $Object*, Object$*)},
	{"getDefaultSecureRandomService", "()Ljava/security/Provider$Service;", nullptr, $SYNCHRONIZED, $virtualMethod(Provider, getDefaultSecureRandomService, $Provider$Service*)},
	{"getEngineName", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(Provider, getEngineName, $String*, $String*)},
	{"getInfo", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Provider, getInfo, $String*)},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Provider, getName, $String*)},
	{"getOrDefault", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Provider, getOrDefault, $Object*, Object$*, Object$*)},
	{"getProperty", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Provider, getProperty, $String*, $String*)},
	{"getService", "(Ljava/lang/String;Ljava/lang/String;)Ljava/security/Provider$Service;", nullptr, $PUBLIC, $virtualMethod(Provider, getService, $Provider$Service*, $String*, $String*)},
	{"getServices", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/security/Provider$Service;>;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Provider, getServices, $Set*)},
	{"getTypeAndAlgorithm", "(Ljava/lang/String;)[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(Provider, getTypeAndAlgorithm, $StringArray*, $String*)},
	{"getVersion", "()D", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(Provider, getVersion, double), nullptr, nullptr, _Provider_MethodAnnotations_getVersion25},
	{"getVersionStr", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Provider, getVersionStr, $String*)},
	{"implClear", "()V", nullptr, $PRIVATE, $method(Provider, implClear, void)},
	{"implCompute", "(Ljava/lang/Object;Ljava/util/function/BiFunction;)Ljava/lang/Object;", "(Ljava/lang/Object;Ljava/util/function/BiFunction<-Ljava/lang/Object;-Ljava/lang/Object;+Ljava/lang/Object;>;)Ljava/lang/Object;", $PRIVATE, $method(Provider, implCompute, $Object*, Object$*, $BiFunction*)},
	{"implComputeIfAbsent", "(Ljava/lang/Object;Ljava/util/function/Function;)Ljava/lang/Object;", "(Ljava/lang/Object;Ljava/util/function/Function<-Ljava/lang/Object;+Ljava/lang/Object;>;)Ljava/lang/Object;", $PRIVATE, $method(Provider, implComputeIfAbsent, $Object*, Object$*, $Function*)},
	{"implComputeIfPresent", "(Ljava/lang/Object;Ljava/util/function/BiFunction;)Ljava/lang/Object;", "(Ljava/lang/Object;Ljava/util/function/BiFunction<-Ljava/lang/Object;-Ljava/lang/Object;+Ljava/lang/Object;>;)Ljava/lang/Object;", $PRIVATE, $method(Provider, implComputeIfPresent, $Object*, Object$*, $BiFunction*)},
	{"implMerge", "(Ljava/lang/Object;Ljava/lang/Object;Ljava/util/function/BiFunction;)Ljava/lang/Object;", "(Ljava/lang/Object;Ljava/lang/Object;Ljava/util/function/BiFunction<-Ljava/lang/Object;-Ljava/lang/Object;+Ljava/lang/Object;>;)Ljava/lang/Object;", $PRIVATE, $method(Provider, implMerge, $Object*, Object$*, Object$*, $BiFunction*)},
	{"implPut", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PRIVATE, $method(Provider, implPut, $Object*, Object$*, Object$*)},
	{"implPutAll", "(Ljava/util/Map;)V", "(Ljava/util/Map<**>;)V", $PRIVATE, $method(Provider, implPutAll, void, $Map*)},
	{"implPutIfAbsent", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PRIVATE, $method(Provider, implPutIfAbsent, $Object*, Object$*, Object$*)},
	{"implRemove", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PRIVATE, $method(Provider, implRemove, $Object*, Object$*)},
	{"implRemove", "(Ljava/lang/Object;Ljava/lang/Object;)Z", nullptr, $PRIVATE, $method(Provider, implRemove, bool, Object$*, Object$*)},
	{"implRemoveService", "(Ljava/security/Provider$Service;)V", nullptr, $PRIVATE, $method(Provider, implRemoveService, void, $Provider$Service*)},
	{"implReplace", "(Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;)Z", nullptr, $PRIVATE, $method(Provider, implReplace, bool, Object$*, Object$*, Object$*)},
	{"implReplace", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PRIVATE, $method(Provider, implReplace, $Object*, Object$*, Object$*)},
	{"implReplaceAll", "(Ljava/util/function/BiFunction;)V", "(Ljava/util/function/BiFunction<-Ljava/lang/Object;-Ljava/lang/Object;+Ljava/lang/Object;>;)V", $PRIVATE, $method(Provider, implReplaceAll, void, $BiFunction*)},
	{"isConfigured", "()Z", nullptr, $PUBLIC, $virtualMethod(Provider, isConfigured, bool)},
	{"keySet", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/Object;>;", $PUBLIC, $virtualMethod(Provider, keySet, $Set*)},
	{"keys", "()Ljava/util/Enumeration;", "()Ljava/util/Enumeration<Ljava/lang/Object;>;", $PUBLIC, $virtualMethod(Provider, keys, $Enumeration*)},
	{"load", "(Ljava/io/InputStream;)V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Provider, load, void, $InputStream*), "java.io.IOException"},
	{"merge", "(Ljava/lang/Object;Ljava/lang/Object;Ljava/util/function/BiFunction;)Ljava/lang/Object;", "(Ljava/lang/Object;Ljava/lang/Object;Ljava/util/function/BiFunction<-Ljava/lang/Object;-Ljava/lang/Object;+Ljava/lang/Object;>;)Ljava/lang/Object;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Provider, merge, $Object*, Object$*, Object$*, $BiFunction*)},
	{"parseLegacyPut", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PRIVATE, $method(Provider, parseLegacyPut, void, $String*, $String*)},
	{"parseVersionStr", "(Ljava/lang/String;)D", nullptr, $PRIVATE | $STATIC, $staticMethod(Provider, parseVersionStr, double, $String*)},
	{"put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Provider, put, $Object*, Object$*, Object$*)},
	{"putAll", "(Ljava/util/Map;)V", "(Ljava/util/Map<**>;)V", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Provider, putAll, void, $Map*)},
	{"putId", "()V", nullptr, $PRIVATE, $method(Provider, putId, void)},
	{"putIfAbsent", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Provider, putIfAbsent, $Object*, Object$*, Object$*)},
	{"putPropertyStrings", "(Ljava/security/Provider$Service;)V", nullptr, $PRIVATE, $method(Provider, putPropertyStrings, void, $Provider$Service*)},
	{"putService", "(Ljava/security/Provider$Service;)V", nullptr, $PROTECTED, $virtualMethod(Provider, putService, void, $Provider$Service*)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(Provider, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"remove", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Provider, remove, $Object*, Object$*)},
	{"remove", "(Ljava/lang/Object;Ljava/lang/Object;)Z", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Provider, remove, bool, Object$*, Object$*)},
	{"removeInvalidServices", "(Ljava/util/Map;)V", "(Ljava/util/Map<Ljava/security/Provider$ServiceKey;Ljava/security/Provider$Service;>;)V", $PRIVATE, $method(Provider, removeInvalidServices, void, $Map*)},
	{"removePropertyStrings", "(Ljava/security/Provider$Service;)V", nullptr, $PRIVATE, $method(Provider, removePropertyStrings, void, $Provider$Service*)},
	{"removeService", "(Ljava/security/Provider$Service;)V", nullptr, $PROTECTED, $virtualMethod(Provider, removeService, void, $Provider$Service*)},
	{"replace", "(Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;)Z", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Provider, replace, bool, Object$*, Object$*, Object$*)},
	{"replace", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Provider, replace, $Object*, Object$*, Object$*)},
	{"replaceAll", "(Ljava/util/function/BiFunction;)V", "(Ljava/util/function/BiFunction<-Ljava/lang/Object;-Ljava/lang/Object;+Ljava/lang/Object;>;)V", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Provider, replaceAll, void, $BiFunction*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Provider, toString, $String*)},
	{"updateSecureRandomEntries", "(ZLjava/lang/String;)V", nullptr, $PRIVATE, $method(Provider, updateSecureRandomEntries, void, bool, $String*)},
	{"values", "()Ljava/util/Collection;", "()Ljava/util/Collection<Ljava/lang/Object;>;", $PUBLIC, $virtualMethod(Provider, values, $Collection*)},
	{}
};

$InnerClassInfo _Provider_InnerClassesInfo_[] = {
	{"java.security.Provider$Service", "java.security.Provider", "Service", $PUBLIC | $STATIC},
	{"java.security.Provider$EngineDescription", "java.security.Provider", "EngineDescription", $PRIVATE | $STATIC},
	{"java.security.Provider$UString", "java.security.Provider", "UString", $PRIVATE | $STATIC},
	{"java.security.Provider$ServiceKey", "java.security.Provider", "ServiceKey", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _Provider_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"java.security.Provider",
	"java.util.Properties",
	nullptr,
	_Provider_FieldInfo_,
	_Provider_MethodInfo_,
	nullptr,
	nullptr,
	_Provider_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.security.Provider$Service,java.security.Provider$EngineDescription,java.security.Provider$UString,java.security.Provider$ServiceKey"
};

$Object* allocate$Provider($Class* clazz) {
	return $of($alloc(Provider));
}

$Debug* Provider::debug = nullptr;
$ObjectArray* Provider::EMPTY = nullptr;
$String* Provider::ALIAS_PREFIX = nullptr;
$String* Provider::ALIAS_PREFIX_LOWER = nullptr;
int32_t Provider::ALIAS_LENGTH = 0;
$volatile($Provider$ServiceKey*) Provider::previousKey = nullptr;
$Map* Provider::knownEngines = nullptr;

double Provider::parseVersionStr($String* s$renamed) {
	$init(Provider);
	$var($String, s, s$renamed);
	try {
		int32_t firstDotIdx = $nc(s)->indexOf((int32_t)u'.');
		int32_t nextDotIdx = s->indexOf((int32_t)u'.', firstDotIdx + 1);
		if (nextDotIdx != -1) {
			$assign(s, s->substring(0, nextDotIdx));
		}
		int32_t endIdx = s->indexOf((int32_t)u'-');
		if (endIdx > 0) {
			$assign(s, s->substring(0, endIdx));
		}
		endIdx = s->indexOf((int32_t)u'+');
		if (endIdx > 0) {
			$assign(s, s->substring(0, endIdx));
		}
		return $Double::parseDouble(s);
	} catch ($NullPointerException& e) {
		return 0.0;
	} catch ($NumberFormatException& e) {
		return 0.0;
	}
	$shouldNotReachHere();
}

void Provider::init$($String* name, double version, $String* info) {
	$Properties::init$();
	$set(this, entrySet$, nullptr);
	this->entrySetCallCount = 0;
	$set(this, name, name);
	this->version = version;
	$set(this, versionStr, $Double::toString(version));
	$set(this, info, info);
	$set(this, serviceMap, static_cast<$Map*>(static_cast<$AbstractMap*>($new($ConcurrentHashMap))));
	putId();
	this->initialized = true;
}

void Provider::init$($String* name, $String* versionStr, $String* info) {
	$Properties::init$();
	$set(this, entrySet$, nullptr);
	this->entrySetCallCount = 0;
	$set(this, name, name);
	$set(this, versionStr, versionStr);
	this->version = parseVersionStr(versionStr);
	$set(this, info, info);
	$set(this, serviceMap, static_cast<$Map*>(static_cast<$AbstractMap*>($new($ConcurrentHashMap))));
	putId();
	this->initialized = true;
}

Provider* Provider::configure($String* configArg) {
	$throwNew($UnsupportedOperationException, "configure is not supported"_s);
	$shouldNotReachHere();
}

bool Provider::isConfigured() {
	return true;
}

$String* Provider::getName() {
	return this->name;
}

double Provider::getVersion() {
	return this->version;
}

$String* Provider::getVersionStr() {
	return this->versionStr;
}

$String* Provider::getInfo() {
	return this->info;
}

$String* Provider::toString() {
	return $str({this->name, " version "_s, this->versionStr});
}

void Provider::clear() {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		check($$str({"clearProviderProperties."_s, this->name}));
		if (Provider::debug != nullptr) {
			$nc(Provider::debug)->println($$str({"Remove "_s, this->name, " provider properties"_s}));
		}
		implClear();
	}
}

void Provider::load($InputStream* inStream) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		check($$str({"putProviderProperty."_s, this->name}));
		if (Provider::debug != nullptr) {
			$nc(Provider::debug)->println($$str({"Load "_s, this->name, " provider properties"_s}));
		}
		$var($Properties, tempProperties, $new($Properties));
		tempProperties->load(inStream);
		implPutAll(tempProperties);
	}
}

void Provider::putAll($Map* t) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		check($$str({"putProviderProperty."_s, this->name}));
		if (Provider::debug != nullptr) {
			$nc(Provider::debug)->println($$str({"Put all "_s, this->name, " provider properties"_s}));
		}
		implPutAll(t);
	}
}

$Set* Provider::entrySet() {
	$synchronized(this) {
		checkInitialized();
		if (this->entrySet$ == nullptr) {
			if (this->entrySetCallCount++ == 0) {
				$set(this, entrySet$, $nc($($Collections::unmodifiableMap(this)))->entrySet());
			} else {
				return $Properties::entrySet();
			}
		}
		if (this->entrySetCallCount != 2) {
			$throwNew($RuntimeException, "Internal error."_s);
		}
		return this->entrySet$;
	}
}

$Set* Provider::keySet() {
	checkInitialized();
	return $Collections::unmodifiableSet($($Properties::keySet()));
}

$Collection* Provider::values() {
	checkInitialized();
	return $Collections::unmodifiableCollection($($Properties::values()));
}

$Object* Provider::put(Object$* key, Object$* value) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		check($$str({"putProviderProperty."_s, this->name}));
		if (Provider::debug != nullptr) {
			$nc(Provider::debug)->println($$str({"Set "_s, this->name, " provider property ["_s, key, "/"_s, value, "]"_s}));
		}
		return $of(implPut(key, value));
	}
}

$Object* Provider::putIfAbsent(Object$* key, Object$* value) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		check($$str({"putProviderProperty."_s, this->name}));
		if (Provider::debug != nullptr) {
			$nc(Provider::debug)->println($$str({"Set "_s, this->name, " provider property ["_s, key, "/"_s, value, "]"_s}));
		}
		return $of(implPutIfAbsent(key, value));
	}
}

$Object* Provider::remove(Object$* key) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		check($$str({"removeProviderProperty."_s, this->name}));
		if (Provider::debug != nullptr) {
			$nc(Provider::debug)->println($$str({"Remove "_s, this->name, " provider property "_s, key}));
		}
		return $of(implRemove(key));
	}
}

bool Provider::remove(Object$* key, Object$* value) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		check($$str({"removeProviderProperty."_s, this->name}));
		if (Provider::debug != nullptr) {
			$nc(Provider::debug)->println($$str({"Remove "_s, this->name, " provider property "_s, key}));
		}
		return implRemove(key, value);
	}
}

bool Provider::replace(Object$* key, Object$* oldValue, Object$* newValue) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		check($$str({"putProviderProperty."_s, this->name}));
		if (Provider::debug != nullptr) {
			$nc(Provider::debug)->println($$str({"Replace "_s, this->name, " provider property "_s, key}));
		}
		return implReplace(key, oldValue, newValue);
	}
}

$Object* Provider::replace(Object$* key, Object$* value) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		check($$str({"putProviderProperty."_s, this->name}));
		if (Provider::debug != nullptr) {
			$nc(Provider::debug)->println($$str({"Replace "_s, this->name, " provider property "_s, key}));
		}
		return $of(implReplace(key, value));
	}
}

void Provider::replaceAll($BiFunction* function) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		check($$str({"putProviderProperty."_s, this->name}));
		if (Provider::debug != nullptr) {
			$nc(Provider::debug)->println($$str({"ReplaceAll "_s, this->name, " provider property "_s}));
		}
		implReplaceAll(function);
	}
}

$Object* Provider::compute(Object$* key, $BiFunction* remappingFunction) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		check($$str({"putProviderProperty."_s, this->name}));
		check($$str({"removeProviderProperty."_s, this->name}));
		if (Provider::debug != nullptr) {
			$nc(Provider::debug)->println($$str({"Compute "_s, this->name, " provider property "_s, key}));
		}
		return $of(implCompute(key, remappingFunction));
	}
}

$Object* Provider::computeIfAbsent(Object$* key, $Function* mappingFunction) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		check($$str({"putProviderProperty."_s, this->name}));
		check($$str({"removeProviderProperty."_s, this->name}));
		if (Provider::debug != nullptr) {
			$nc(Provider::debug)->println($$str({"ComputeIfAbsent "_s, this->name, " provider property "_s, key}));
		}
		return $of(implComputeIfAbsent(key, mappingFunction));
	}
}

$Object* Provider::computeIfPresent(Object$* key, $BiFunction* remappingFunction) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		check($$str({"putProviderProperty."_s, this->name}));
		check($$str({"removeProviderProperty."_s, this->name}));
		if (Provider::debug != nullptr) {
			$nc(Provider::debug)->println($$str({"ComputeIfPresent "_s, this->name, " provider property "_s, key}));
		}
		return $of(implComputeIfPresent(key, remappingFunction));
	}
}

$Object* Provider::merge(Object$* key, Object$* value, $BiFunction* remappingFunction) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		check($$str({"putProviderProperty."_s, this->name}));
		check($$str({"removeProviderProperty."_s, this->name}));
		if (Provider::debug != nullptr) {
			$nc(Provider::debug)->println($$str({"Merge "_s, this->name, " provider property "_s, key}));
		}
		return $of(implMerge(key, value, remappingFunction));
	}
}

$Object* Provider::get(Object$* key) {
	checkInitialized();
	return $of($Properties::get(key));
}

$Object* Provider::getOrDefault(Object$* key, Object$* defaultValue) {
	$synchronized(this) {
		checkInitialized();
		return $of($Properties::getOrDefault(key, defaultValue));
	}
}

void Provider::forEach($BiConsumer* action) {
	$synchronized(this) {
		checkInitialized();
		$Properties::forEach(action);
	}
}

$Enumeration* Provider::keys() {
	checkInitialized();
	return $Properties::keys();
}

$Enumeration* Provider::elements() {
	checkInitialized();
	return $Properties::elements();
}

$String* Provider::getProperty($String* key) {
	checkInitialized();
	return $Properties::getProperty(key);
}

void Provider::checkInitialized() {
	if (!this->initialized) {
		$throwNew($IllegalStateException);
	}
}

void Provider::check($String* directive) {
	checkInitialized();
	$var($SecurityManager, security, $System::getSecurityManager());
	if (security != nullptr) {
		security->checkSecurityAccess(directive);
	}
}

void Provider::putId() {
	$useLocalCurrentObjectStackCache();
	$Properties::put("Provider.id name"_s, $($String::valueOf($of(this->name))));
	$Properties::put("Provider.id version"_s, $($String::valueOf($of(this->versionStr))));
	$Properties::put("Provider.id info"_s, $($String::valueOf($of(this->info))));
	$Properties::put("Provider.id className"_s, $($of(this)->getClass()->getName()));
}

void Provider::readObject($ObjectInputStream* in) {
	$useLocalCurrentObjectStackCache();
	$var($Map, copy, $new($HashMap));
	{
		$var($Iterator, i$, $nc($($Properties::entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
			{
				$var($Object, var$0, $nc(entry)->getKey());
				copy->put(var$0, $(entry->getValue()));
			}
		}
	}
	$set(this, defaults, nullptr);
	$nc(in)->defaultReadObject();
	if (this->versionStr == nullptr) {
		$set(this, versionStr, $Double::toString(this->version));
	} else {
		this->version = parseVersionStr(this->versionStr);
	}
	$set(this, serviceMap, static_cast<$Map*>(static_cast<$AbstractMap*>($new($ConcurrentHashMap))));
	implClear();
	this->initialized = true;
	putAll(copy);
}

bool Provider::checkLegacy(Object$* key) {
	$var($String, keyString, $cast($String, key));
	if ($nc(keyString)->startsWith("Provider."_s)) {
		return false;
	}
	this->legacyChanged = true;
	if (this->legacyStrings == nullptr) {
		$set(this, legacyStrings, $new($LinkedHashMap));
	}
	return true;
}

void Provider::implPutAll($Map* t) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc($($nc(t)->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
			{
				$var($Object, var$0, $nc(e)->getKey());
				implPut(var$0, $(e->getValue()));
			}
		}
	}
}

$Object* Provider::implRemove(Object$* key) {
	if ($instanceOf($String, key)) {
		if (!checkLegacy(key)) {
			return $of(nullptr);
		}
		$nc(this->legacyStrings)->remove($cast($String, key));
	}
	return $of($Properties::remove(key));
}

bool Provider::implRemove(Object$* key, Object$* value) {
	if ($instanceOf($String, key) && $instanceOf($String, value)) {
		if (!checkLegacy(key)) {
			return false;
		}
		$nc(this->legacyStrings)->remove($cast($String, key), $cast($String, value));
	}
	return $Properties::remove(key, value);
}

bool Provider::implReplace(Object$* key, Object$* oldValue, Object$* newValue) {
	if (($instanceOf($String, key)) && ($instanceOf($String, oldValue)) && ($instanceOf($String, newValue))) {
		if (!checkLegacy(key)) {
			return false;
		}
		$nc(this->legacyStrings)->replace($cast($String, key), $cast($String, oldValue), $cast($String, newValue));
	}
	return $Properties::replace(key, oldValue, newValue);
}

$Object* Provider::implReplace(Object$* key, Object$* value) {
	if (($instanceOf($String, key)) && ($instanceOf($String, value))) {
		if (!checkLegacy(key)) {
			return $of(nullptr);
		}
		$nc(this->legacyStrings)->replace($cast($String, key), $cast($String, value));
	}
	return $of($Properties::replace(key, value));
}

void Provider::implReplaceAll($BiFunction* function) {
	this->legacyChanged = true;
	if (this->legacyStrings == nullptr) {
		$set(this, legacyStrings, $new($LinkedHashMap));
	} else {
		$nc(this->legacyStrings)->replaceAll(function);
	}
	$Properties::replaceAll(function);
}

$Object* Provider::implMerge(Object$* key, Object$* value, $BiFunction* remappingFunction) {
	if (($instanceOf($String, key)) && ($instanceOf($String, value))) {
		if (!checkLegacy(key)) {
			return $of(nullptr);
		}
		$nc(this->legacyStrings)->merge($cast($String, key), $cast($String, value), remappingFunction);
	}
	return $of($Properties::merge(key, value, remappingFunction));
}

$Object* Provider::implCompute(Object$* key, $BiFunction* remappingFunction) {
	if ($instanceOf($String, key)) {
		if (!checkLegacy(key)) {
			return $of(nullptr);
		}
		$nc(this->legacyStrings)->compute($cast($String, key), remappingFunction);
	}
	return $of($Properties::compute(key, remappingFunction));
}

$Object* Provider::implComputeIfAbsent(Object$* key, $Function* mappingFunction) {
	if ($instanceOf($String, key)) {
		if (!checkLegacy(key)) {
			return $of(nullptr);
		}
		$nc(this->legacyStrings)->computeIfAbsent($cast($String, key), mappingFunction);
	}
	return $of($Properties::computeIfAbsent(key, mappingFunction));
}

$Object* Provider::implComputeIfPresent(Object$* key, $BiFunction* remappingFunction) {
	if ($instanceOf($String, key)) {
		if (!checkLegacy(key)) {
			return $of(nullptr);
		}
		$nc(this->legacyStrings)->computeIfPresent($cast($String, key), remappingFunction);
	}
	return $of($Properties::computeIfPresent(key, remappingFunction));
}

$Object* Provider::implPut(Object$* key, Object$* value) {
	if (($instanceOf($String, key)) && ($instanceOf($String, value))) {
		if (!checkLegacy(key)) {
			return $of(nullptr);
		}
		$nc(this->legacyStrings)->put($cast($String, key), $cast($String, value));
	}
	return $of($Properties::put(key, value));
}

$Object* Provider::implPutIfAbsent(Object$* key, Object$* value) {
	if (($instanceOf($String, key)) && ($instanceOf($String, value))) {
		if (!checkLegacy(key)) {
			return $of(nullptr);
		}
		$nc(this->legacyStrings)->putIfAbsent($cast($String, key), $cast($String, value));
	}
	return $of($Properties::putIfAbsent(key, value));
}

void Provider::implClear() {
	if (this->legacyStrings != nullptr) {
		$nc(this->legacyStrings)->clear();
	}
	if (this->legacyMap != nullptr) {
		$nc(this->legacyMap)->clear();
	}
	$nc(this->serviceMap)->clear();
	this->legacyChanged = false;
	this->servicesChanged = false;
	$set(this, serviceSet, nullptr);
	$set(this, prngAlgos, nullptr);
	$Properties::clear();
	putId();
}

void Provider::ensureLegacyParsed() {
	$useLocalCurrentObjectStackCache();
	if (this->legacyChanged == false || (this->legacyStrings == nullptr)) {
		return;
	}
	$set(this, serviceSet, nullptr);
	if (this->legacyMap == nullptr) {
		$set(this, legacyMap, static_cast<$Map*>(static_cast<$AbstractMap*>($new($ConcurrentHashMap))));
	} else {
		$nc(this->legacyMap)->clear();
	}
	{
		$var($Iterator, i$, $nc($($nc(this->legacyStrings)->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
			{
				$var($String, var$0, $cast($String, $nc(entry)->getKey()));
				parseLegacyPut(var$0, $cast($String, $(entry->getValue())));
			}
		}
	}
	removeInvalidServices(this->legacyMap);
	this->legacyChanged = false;
}

void Provider::removeInvalidServices($Map* map) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, t, $nc($($nc(map)->entrySet()))->iterator());
		for (; $nc(t)->hasNext();) {
			$var($Provider$Service, s, $cast($Provider$Service, $nc(($cast($Map$Entry, $(t->next()))))->getValue()));
			if ($nc(s)->isValid() == false) {
				t->remove();
			}
		}
	}
}

$StringArray* Provider::getTypeAndAlgorithm($String* key) {
	$init(Provider);
	$useLocalCurrentObjectStackCache();
	int32_t i = $nc(key)->indexOf((int32_t)u'.');
	if (i < 1) {
		if (Provider::debug != nullptr) {
			$nc(Provider::debug)->println($$str({"Ignoring invalid entry in provider: "_s, key}));
		}
		return nullptr;
	}
	$var($String, type, key->substring(0, i));
	$var($String, alg, key->substring(i + 1));
	return $new($StringArray, {
		type,
		alg
	});
}

void Provider::parseLegacyPut($String* name, $String* value) {
	$useLocalCurrentObjectStackCache();
	$init($Locale);
	if ($($nc(name)->toLowerCase($Locale::ENGLISH))->startsWith(Provider::ALIAS_PREFIX_LOWER)) {
		$var($String, stdAlg, value);
		$var($String, aliasKey, name->substring(Provider::ALIAS_LENGTH));
		$var($StringArray, typeAndAlg, getTypeAndAlgorithm(aliasKey));
		if (typeAndAlg == nullptr) {
			return;
		}
		$var($String, type, getEngineName($nc(typeAndAlg)->get(0)));
		$var($String, aliasAlg, $nc($nc(typeAndAlg)->get(1))->intern());
		$var($Provider$ServiceKey, key, $new($Provider$ServiceKey, type, stdAlg, true));
		$var($Provider$Service, s, $cast($Provider$Service, $nc(this->legacyMap)->get(key)));
		if (s == nullptr) {
			$assign(s, $new($Provider$Service, this, type, stdAlg));
			$nc(this->legacyMap)->put(key, s);
		}
		$nc(this->legacyMap)->put($$new($Provider$ServiceKey, type, aliasAlg, true), s);
		$nc(s)->addAlias(aliasAlg);
	} else {
		$var($StringArray, typeAndAlg, getTypeAndAlgorithm(name));
		if (typeAndAlg == nullptr) {
			return;
		}
		int32_t i = $nc($nc(typeAndAlg)->get(1))->indexOf((int32_t)u' ');
		if (i == -1) {
			$var($String, type, getEngineName(typeAndAlg->get(0)));
			$var($String, stdAlg, $nc(typeAndAlg->get(1))->intern());
			$var($String, className, value);
			$var($Provider$ServiceKey, key, $new($Provider$ServiceKey, type, stdAlg, true));
			$var($Provider$Service, s, $cast($Provider$Service, $nc(this->legacyMap)->get(key)));
			if (s == nullptr) {
				$assign(s, $new($Provider$Service, this, type, stdAlg));
				$nc(this->legacyMap)->put(key, s);
			}
			$set($nc(s), className, className);
			if ($nc(type)->equals("SecureRandom"_s)) {
				updateSecureRandomEntries(true, s->algorithm);
			}
		} else {
			$var($String, attributeValue, value);
			$var($String, type, getEngineName(typeAndAlg->get(0)));
			$var($String, attributeString, typeAndAlg->get(1));
			$var($String, stdAlg, $($nc(attributeString)->substring(0, i))->intern());
			$var($String, attributeName, attributeString->substring(i + 1));
			while (attributeName->startsWith(" "_s)) {
				$assign(attributeName, attributeName->substring(1));
			}
			$assign(attributeName, attributeName->intern());
			$var($Provider$ServiceKey, key, $new($Provider$ServiceKey, type, stdAlg, true));
			$var($Provider$Service, s, $cast($Provider$Service, $nc(this->legacyMap)->get(key)));
			if (s == nullptr) {
				$assign(s, $new($Provider$Service, this, type, stdAlg));
				$nc(this->legacyMap)->put(key, s);
			}
			$nc(s)->addAttribute(attributeName, attributeValue);
		}
	}
}

$Provider$Service* Provider::getService($String* type, $String* algorithm) {
	$useLocalCurrentObjectStackCache();
	checkInitialized();
	$var($Provider$ServiceKey, key, Provider::previousKey);
	if ($nc(key)->matches(type, algorithm) == false) {
		$assign(key, $new($Provider$ServiceKey, type, algorithm, false));
		$assignStatic(Provider::previousKey, key);
	}
	if (!$nc(this->serviceMap)->isEmpty()) {
		$var($Provider$Service, s, $cast($Provider$Service, $nc(this->serviceMap)->get(key)));
		if (s != nullptr) {
			return s;
		}
	}
	$synchronized(this) {
		ensureLegacyParsed();
		if (this->legacyMap != nullptr && !$nc(this->legacyMap)->isEmpty()) {
			return $cast($Provider$Service, $nc(this->legacyMap)->get(key));
		}
	}
	return nullptr;
}

$Set* Provider::getServices() {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		checkInitialized();
		if (this->legacyChanged || this->servicesChanged) {
			$set(this, serviceSet, nullptr);
		}
		if (this->serviceSet == nullptr) {
			ensureLegacyParsed();
			$var($Set, set, $new($LinkedHashSet));
			if (!$nc(this->serviceMap)->isEmpty()) {
				set->addAll($($nc(this->serviceMap)->values()));
			}
			if (this->legacyMap != nullptr && !$nc(this->legacyMap)->isEmpty()) {
				set->addAll($($nc(this->legacyMap)->values()));
			}
			$set(this, serviceSet, $Collections::unmodifiableSet(set));
			this->servicesChanged = false;
		}
		return this->serviceSet;
	}
}

void Provider::putService($Provider$Service* s) {
	$useLocalCurrentObjectStackCache();
	check($$str({"putProviderProperty."_s, this->name}));
	if (Provider::debug != nullptr) {
		$nc(Provider::debug)->println($$str({this->name, ".putService(): "_s, s}));
	}
	if (s == nullptr) {
		$throwNew($NullPointerException);
	}
	if ($nc(s)->getProvider() != this) {
		$throwNew($IllegalArgumentException, "service.getProvider() must match this Provider object"_s);
	}
	$var($String, type, $nc(s)->getType());
	$var($String, algorithm, s->getAlgorithm());
	$var($Provider$ServiceKey, key, $new($Provider$ServiceKey, type, algorithm, true));
	implRemoveService($cast($Provider$Service, $($nc(this->serviceMap)->get(key))));
	$nc(this->serviceMap)->put(key, s);
	{
		$var($Iterator, i$, $nc($(s->getAliases()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, alias, $cast($String, i$->next()));
			{
				$nc(this->serviceMap)->put($$new($Provider$ServiceKey, type, alias, true), s);
			}
		}
	}
	this->servicesChanged = true;
	$synchronized(this) {
		putPropertyStrings(s);
		if ($nc(type)->equals("SecureRandom"_s)) {
			updateSecureRandomEntries(true, s->algorithm);
		}
	}
}

void Provider::updateSecureRandomEntries(bool doAdd, $String* s) {
	$Objects::requireNonNull(s);
	if (doAdd) {
		if (this->prngAlgos == nullptr) {
			$set(this, prngAlgos, $new($LinkedHashSet));
		}
		$nc(this->prngAlgos)->add(s);
	} else {
		$nc(this->prngAlgos)->remove(s);
	}
	if (Provider::debug != nullptr) {
		$nc(Provider::debug)->println($$str({(doAdd ? "Add"_s : "Remove"_s), " SecureRandom algo "_s, s}));
	}
}

$Provider$Service* Provider::getDefaultSecureRandomService() {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		checkInitialized();
		if (this->legacyChanged) {
			$set(this, prngAlgos, nullptr);
			ensureLegacyParsed();
		}
		if (this->prngAlgos != nullptr && !$nc(this->prngAlgos)->isEmpty()) {
			return getService("SecureRandom"_s, $cast($String, $($nc($($nc(this->prngAlgos)->iterator()))->next())));
		}
		return nullptr;
	}
}

void Provider::putPropertyStrings($Provider$Service* s) {
	$useLocalCurrentObjectStackCache();
	$var($String, type, $nc(s)->getType());
	$var($String, algorithm, s->getAlgorithm());
	$Properties::put($$str({type, "."_s, algorithm}), $(s->getClassName()));
	{
		$var($Iterator, i$, $nc($(s->getAliases()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, alias, $cast($String, i$->next()));
			{
				$Properties::put($$str({Provider::ALIAS_PREFIX, type, "."_s, alias}), algorithm);
			}
		}
	}
	{
		$var($Iterator, i$, $nc($($nc(s->attributes)->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
			{
				$var($String, key, $str({type, "."_s, algorithm, " "_s, $($nc(entry)->getKey())}));
				$Properties::put(key, $(entry->getValue()));
			}
		}
	}
}

void Provider::removePropertyStrings($Provider$Service* s) {
	$useLocalCurrentObjectStackCache();
	$var($String, type, $nc(s)->getType());
	$var($String, algorithm, s->getAlgorithm());
	$Properties::remove($$str({type, "."_s, algorithm}));
	{
		$var($Iterator, i$, $nc($(s->getAliases()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, alias, $cast($String, i$->next()));
			{
				$Properties::remove($$str({Provider::ALIAS_PREFIX, type, "."_s, alias}));
			}
		}
	}
	{
		$var($Iterator, i$, $nc($($nc(s->attributes)->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
			{
				$var($String, key, $str({type, "."_s, algorithm, " "_s, $($nc(entry)->getKey())}));
				$Properties::remove(key);
			}
		}
	}
}

void Provider::removeService($Provider$Service* s) {
	$useLocalCurrentObjectStackCache();
	check($$str({"removeProviderProperty."_s, this->name}));
	if (Provider::debug != nullptr) {
		$nc(Provider::debug)->println($$str({this->name, ".removeService(): "_s, s}));
	}
	if (s == nullptr) {
		$throwNew($NullPointerException);
	}
	implRemoveService(s);
}

void Provider::implRemoveService($Provider$Service* s) {
	$useLocalCurrentObjectStackCache();
	if ((s == nullptr) || $nc(this->serviceMap)->isEmpty()) {
		return;
	}
	$var($String, type, $nc(s)->getType());
	$var($String, algorithm, s->getAlgorithm());
	$var($Provider$ServiceKey, key, $new($Provider$ServiceKey, type, algorithm, false));
	$var($Provider$Service, oldService, $cast($Provider$Service, $nc(this->serviceMap)->get(key)));
	if (s != oldService) {
		return;
	}
	this->servicesChanged = true;
	$nc(this->serviceMap)->remove(key);
	{
		$var($Iterator, i$, $nc($(s->getAliases()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, alias, $cast($String, i$->next()));
			{
				$nc(this->serviceMap)->remove($$new($Provider$ServiceKey, type, alias, false));
			}
		}
	}
	$synchronized(this) {
		removePropertyStrings(s);
		if ($nc(type)->equals("SecureRandom"_s)) {
			updateSecureRandomEntries(false, s->algorithm);
		}
	}
}

void Provider::addEngine($String* name, bool sp, $String* paramName) {
	$init(Provider);
	$useLocalCurrentObjectStackCache();
	$var($Provider$EngineDescription, ed, $new($Provider$EngineDescription, name, sp, paramName));
	$init($Locale);
	$nc(Provider::knownEngines)->put($($nc(name)->toLowerCase($Locale::ENGLISH)), ed);
	$nc(Provider::knownEngines)->put(name, ed);
}

$String* Provider::getEngineName($String* s) {
	$init(Provider);
	$useLocalCurrentObjectStackCache();
	$var($Provider$EngineDescription, e, $cast($Provider$EngineDescription, $nc(Provider::knownEngines)->get(s)));
	if (e == nullptr) {
		$init($Locale);
		$assign(e, $cast($Provider$EngineDescription, $nc(Provider::knownEngines)->get($($nc(s)->toLowerCase($Locale::ENGLISH)))));
	}
	return (e == nullptr) ? s : $nc(e)->name;
}

void clinit$Provider($Class* class$) {
	$assignStatic(Provider::ALIAS_PREFIX, "Alg.Alias."_s);
	$assignStatic(Provider::ALIAS_PREFIX_LOWER, "alg.alias."_s);
	$assignStatic(Provider::debug, $Debug::getInstance("provider"_s, "Provider"_s));
	$assignStatic(Provider::EMPTY, $new($ObjectArray, 0));
	Provider::ALIAS_LENGTH = $nc(Provider::ALIAS_PREFIX)->length();
	$assignStatic(Provider::previousKey, $new($Provider$ServiceKey, ""_s, ""_s, false));
	{
		$assignStatic(Provider::knownEngines, $new($HashMap));
		Provider::addEngine("AlgorithmParameterGenerator"_s, false, nullptr);
		Provider::addEngine("AlgorithmParameters"_s, false, nullptr);
		Provider::addEngine("KeyFactory"_s, false, nullptr);
		Provider::addEngine("KeyPairGenerator"_s, false, nullptr);
		Provider::addEngine("KeyStore"_s, false, nullptr);
		Provider::addEngine("MessageDigest"_s, false, nullptr);
		Provider::addEngine("SecureRandom"_s, false, "java.security.SecureRandomParameters"_s);
		Provider::addEngine("Signature"_s, true, nullptr);
		Provider::addEngine("CertificateFactory"_s, false, nullptr);
		Provider::addEngine("CertPathBuilder"_s, false, nullptr);
		Provider::addEngine("CertPathValidator"_s, false, nullptr);
		Provider::addEngine("CertStore"_s, false, "java.security.cert.CertStoreParameters"_s);
		Provider::addEngine("Cipher"_s, true, nullptr);
		Provider::addEngine("ExemptionMechanism"_s, false, nullptr);
		Provider::addEngine("Mac"_s, true, nullptr);
		Provider::addEngine("KeyAgreement"_s, true, nullptr);
		Provider::addEngine("KeyGenerator"_s, false, nullptr);
		Provider::addEngine("SecretKeyFactory"_s, false, nullptr);
		Provider::addEngine("KeyManagerFactory"_s, false, nullptr);
		Provider::addEngine("SSLContext"_s, false, nullptr);
		Provider::addEngine("TrustManagerFactory"_s, false, nullptr);
		Provider::addEngine("GssApiMechanism"_s, false, nullptr);
		Provider::addEngine("SaslClientFactory"_s, false, nullptr);
		Provider::addEngine("SaslServerFactory"_s, false, nullptr);
		Provider::addEngine("Policy"_s, false, "java.security.Policy$Parameters"_s);
		Provider::addEngine("Configuration"_s, false, "javax.security.auth.login.Configuration$Parameters"_s);
		Provider::addEngine("XMLSignatureFactory"_s, false, nullptr);
		Provider::addEngine("KeyInfoFactory"_s, false, nullptr);
		Provider::addEngine("TransformService"_s, false, nullptr);
		Provider::addEngine("TerminalFactory"_s, false, "java.lang.Object"_s);
	}
}

Provider::Provider() {
}

$Class* Provider::load$($String* name, bool initialize) {
	$loadClass(Provider, name, initialize, &_Provider_ClassInfo_, clinit$Provider, allocate$Provider);
	return class$;
}

$Class* Provider::class$ = nullptr;

	} // security
} // java