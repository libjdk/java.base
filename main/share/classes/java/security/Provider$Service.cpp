#include <java/security/Provider$Service.h>

#include <java/lang/ClassLoader.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/NoSuchMethodException.h>
#include <java/lang/ref/WeakReference.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/InvocationTargetException.h>
#include <java/lang/reflect/Modifier.h>
#include <java/security/InvalidParameterException.h>
#include <java/security/Key.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/Provider$EngineDescription.h>
#include <java/security/Provider$UString.h>
#include <java/security/Provider.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <jcpp.h>

#undef CLASS0
#undef EMPTY

using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NoSuchMethodException = ::java::lang::NoSuchMethodException;
using $NullPointerException = ::java::lang::NullPointerException;
using $WeakReference = ::java::lang::ref::WeakReference;
using $Constructor = ::java::lang::reflect::Constructor;
using $InvocationTargetException = ::java::lang::reflect::InvocationTargetException;
using $Modifier = ::java::lang::reflect::Modifier;
using $InvalidParameterException = ::java::security::InvalidParameterException;
using $Key = ::java::security::Key;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $Provider = ::java::security::Provider;
using $Provider$EngineDescription = ::java::security::Provider$EngineDescription;
using $Provider$UString = ::java::security::Provider$UString;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;

namespace java {
	namespace security {

$FieldInfo _Provider$Service_FieldInfo_[] = {
	{"type", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(Provider$Service, type)},
	{"algorithm", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(Provider$Service, algorithm)},
	{"className", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Provider$Service, className)},
	{"provider", "Ljava/security/Provider;", nullptr, $PRIVATE | $FINAL, $field(Provider$Service, provider)},
	{"aliases", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/String;>;", $PRIVATE, $field(Provider$Service, aliases)},
	{"attributes", "Ljava/util/Map;", "Ljava/util/Map<Ljava/security/Provider$UString;Ljava/lang/String;>;", $PRIVATE, $field(Provider$Service, attributes)},
	{"engineDescription", "Ljava/security/Provider$EngineDescription;", nullptr, $PRIVATE | $FINAL, $field(Provider$Service, engineDescription)},
	{"classCache", "Ljava/lang/Object;", nullptr, $PRIVATE, $field(Provider$Service, classCache)},
	{"constructorCache", "Ljava/lang/Object;", nullptr, $PRIVATE, $field(Provider$Service, constructorCache)},
	{"hasKeyAttributes", "Ljava/lang/Boolean;", nullptr, $PRIVATE | $VOLATILE, $field(Provider$Service, hasKeyAttributes$)},
	{"supportedFormats", "[Ljava/lang/String;", nullptr, $PRIVATE, $field(Provider$Service, supportedFormats)},
	{"supportedClasses", "[Ljava/lang/Class;", "[Ljava/lang/Class<*>;", $PRIVATE, $field(Provider$Service, supportedClasses)},
	{"registered", "Z", nullptr, $PRIVATE, $field(Provider$Service, registered)},
	{"CLASS0", "[Ljava/lang/Class;", "[Ljava/lang/Class<*>;", $PRIVATE | $STATIC | $FINAL, $staticField(Provider$Service, CLASS0)},
	{}
};

$MethodInfo _Provider$Service_MethodInfo_[] = {
	{"<init>", "(Ljava/security/Provider;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PRIVATE, $method(Provider$Service, init$, void, $Provider*, $String*, $String*)},
	{"<init>", "(Ljava/security/Provider;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/util/List;Ljava/util/Map;)V", "(Ljava/security/Provider;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/util/List<Ljava/lang/String;>;Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;)V", $PUBLIC, $method(Provider$Service, init$, void, $Provider*, $String*, $String*, $String*, $List*, $Map*)},
	{"addAlias", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(Provider$Service, addAlias, void, $String*)},
	{"addAttribute", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, 0, $virtualMethod(Provider$Service, addAttribute, void, $String*, $String*)},
	{"getAlgorithm", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL, $method(Provider$Service, getAlgorithm, $String*)},
	{"getAliases", "()Ljava/util/List;", "()Ljava/util/List<Ljava/lang/String;>;", $PRIVATE | $FINAL, $method(Provider$Service, getAliases, $List*)},
	{"getAttribute", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $FINAL, $method(Provider$Service, getAttribute, $String*, $String*)},
	{"getClassName", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL, $method(Provider$Service, getClassName, $String*)},
	{"getDefaultConstructor", "()Ljava/lang/reflect/Constructor;", "()Ljava/lang/reflect/Constructor<*>;", $PRIVATE, $method(Provider$Service, getDefaultConstructor, $Constructor*), "java.security.NoSuchAlgorithmException,java.lang.NoSuchMethodException"},
	{"getImplClass", "()Ljava/lang/Class;", "()Ljava/lang/Class<*>;", $PRIVATE, $method(Provider$Service, getImplClass, $Class*), "java.security.NoSuchAlgorithmException"},
	{"getKeyClass", "(Ljava/lang/String;)Ljava/lang/Class;", "(Ljava/lang/String;)Ljava/lang/Class<*>;", $PRIVATE, $method(Provider$Service, getKeyClass, $Class*, $String*)},
	{"getProvider", "()Ljava/security/Provider;", nullptr, $PUBLIC | $FINAL, $method(Provider$Service, getProvider, $Provider*)},
	{"getType", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL, $method(Provider$Service, getType, $String*)},
	{"hasKeyAttributes", "()Z", nullptr, $PRIVATE, $method(Provider$Service, hasKeyAttributes, bool)},
	{"isValid", "()Z", nullptr, $PRIVATE, $method(Provider$Service, isValid, bool)},
	{"newInstance", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Provider$Service, newInstance, $Object*, Object$*), "java.security.NoSuchAlgorithmException"},
	{"newInstanceOf", "()Ljava/lang/Object;", nullptr, $PRIVATE, $method(Provider$Service, newInstanceOf, $Object*), "java.lang.Exception"},
	{"newInstanceUtil", "(Ljava/lang/Class;Ljava/lang/Object;)Ljava/lang/Object;", "(Ljava/lang/Class<*>;Ljava/lang/Object;)Ljava/lang/Object;", $PRIVATE, $method(Provider$Service, newInstanceUtil, $Object*, $Class*, Object$*), "java.lang.Exception"},
	{"supportsKeyClass", "(Ljava/security/Key;)Z", nullptr, $PRIVATE, $method(Provider$Service, supportsKeyClass, bool, $Key*)},
	{"supportsKeyFormat", "(Ljava/security/Key;)Z", nullptr, $PRIVATE, $method(Provider$Service, supportsKeyFormat, bool, $Key*)},
	{"supportsParameter", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(Provider$Service, supportsParameter, bool, Object$*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Provider$Service, toString, $String*)},
	{}
};

$InnerClassInfo _Provider$Service_InnerClassesInfo_[] = {
	{"java.security.Provider$Service", "java.security.Provider", "Service", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _Provider$Service_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.security.Provider$Service",
	"java.lang.Object",
	nullptr,
	_Provider$Service_FieldInfo_,
	_Provider$Service_MethodInfo_,
	nullptr,
	nullptr,
	_Provider$Service_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.security.Provider"
};

$Object* allocate$Provider$Service($Class* clazz) {
	return $of($alloc(Provider$Service));
}

$ClassArray* Provider$Service::CLASS0 = nullptr;

void Provider$Service::init$($Provider* provider, $String* type, $String* algorithm) {
	$set(this, provider, provider);
	$set(this, type, type);
	$set(this, algorithm, algorithm);
	$init($Provider);
	$set(this, engineDescription, $cast($Provider$EngineDescription, $nc($Provider::knownEngines)->get(type)));
	$set(this, aliases, $Collections::emptyList());
	$set(this, attributes, $Collections::emptyMap());
}

bool Provider$Service::isValid() {
	return (this->type != nullptr) && (this->algorithm != nullptr) && (this->className != nullptr);
}

void Provider$Service::addAlias($String* alias) {
	if ($nc(this->aliases)->isEmpty()) {
		$set(this, aliases, $new($ArrayList, 2));
	}
	$nc(this->aliases)->add(alias);
}

void Provider$Service::addAttribute($String* type, $String* value) {
	if ($nc(this->attributes)->isEmpty()) {
		$set(this, attributes, $new($HashMap, 8));
	}
	$nc(this->attributes)->put($$new($Provider$UString, type), value);
}

void Provider$Service::init$($Provider* provider, $String* type, $String* algorithm, $String* className, $List* aliases, $Map* attributes) {
	$useLocalCurrentObjectStackCache();
	if ((provider == nullptr) || (type == nullptr) || (algorithm == nullptr) || (className == nullptr)) {
		$throwNew($NullPointerException);
	}
	$set(this, provider, provider);
	$set(this, type, $Provider::getEngineName(type));
	$set(this, engineDescription, $cast($Provider$EngineDescription, $nc($Provider::knownEngines)->get(type)));
	$set(this, algorithm, algorithm);
	$set(this, className, className);
	if (aliases == nullptr) {
		$set(this, aliases, $Collections::emptyList());
	} else {
		$set(this, aliases, $new($ArrayList, static_cast<$Collection*>(aliases)));
	}
	if (attributes == nullptr) {
		$set(this, attributes, $Collections::emptyMap());
	} else {
		$set(this, attributes, $new($HashMap));
		{
			$var($Iterator, i$, $nc($($nc(attributes)->entrySet()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
				{
					$var($Object, var$0, $of($new($Provider$UString, $cast($String, $($nc(entry)->getKey())))));
					$nc(this->attributes)->put(var$0, $cast($String, $($nc(entry)->getValue())));
				}
			}
		}
	}
}

$String* Provider$Service::getType() {
	return this->type;
}

$String* Provider$Service::getAlgorithm() {
	return this->algorithm;
}

$Provider* Provider$Service::getProvider() {
	return this->provider;
}

$String* Provider$Service::getClassName() {
	return this->className;
}

$List* Provider$Service::getAliases() {
	return this->aliases;
}

$String* Provider$Service::getAttribute($String* name) {
	if (name == nullptr) {
		$throwNew($NullPointerException);
	}
	return $cast($String, $nc(this->attributes)->get($$new($Provider$UString, name)));
}

$Object* Provider$Service::newInstance(Object$* constructorParameter) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (this->registered == false) {
		if ($nc(this->provider)->getService(this->type, this->algorithm) != this) {
			$throwNew($NoSuchAlgorithmException, $$str({"Service not registered with Provider "_s, $($nc(this->provider)->getName()), ": "_s, this}));
		}
		this->registered = true;
	}
	$Class* ctrParamClz = nullptr;
	try {
		$var($Provider$EngineDescription, cap, this->engineDescription);
		if (cap == nullptr) {
			ctrParamClz = constructorParameter == nullptr ? ($Class*)nullptr : $nc($of(constructorParameter))->getClass();
		} else {
			ctrParamClz = $nc(cap)->constructorParameterClassName == nullptr ? ($Class*)nullptr : $Class::forName($nc(cap)->constructorParameterClassName);
			if (constructorParameter != nullptr) {
				if (ctrParamClz == nullptr) {
					$throwNew($InvalidParameterException, $$str({"constructorParameter not used with "_s, this->type, " engines"_s}));
				} else {
					$Class* argClass = $of(constructorParameter)->getClass();
					if ($nc(ctrParamClz)->isAssignableFrom(argClass) == false) {
						$throwNew($InvalidParameterException, $$str({"constructorParameter must be instanceof "_s, $($nc($nc(cap)->constructorParameterClassName)->replace(u'$', u'.')), " for engine type "_s, this->type}));
					}
				}
			}
		}
		return $of(newInstanceUtil(ctrParamClz, constructorParameter));
	} catch ($NoSuchAlgorithmException& e) {
		$throw(e);
	} catch ($InvocationTargetException& e) {
		$var($String, var$0, $str({"Error constructing implementation (algorithm: "_s, this->algorithm, ", provider: "_s, $($nc(this->provider)->getName()), ", class: "_s, this->className, ")"_s}));
		$throwNew($NoSuchAlgorithmException, var$0, $(e->getCause()));
	} catch ($Exception& e) {
		$throwNew($NoSuchAlgorithmException, $$str({"Error constructing implementation (algorithm: "_s, this->algorithm, ", provider: "_s, $($nc(this->provider)->getName()), ", class: "_s, this->className, ")"_s}), e);
	}
	$shouldNotReachHere();
}

$Object* Provider$Service::newInstanceOf() {
	$beforeCallerSensitive();
	$var($Constructor, con, getDefaultConstructor());
	$init($Provider);
	return $of($nc(con)->newInstance($Provider::EMPTY));
}

$Object* Provider$Service::newInstanceUtil($Class* ctrParamClz, Object$* ctorParamObj) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (ctrParamClz == nullptr) {
		return $of(newInstanceOf());
	} else {
		try {
			$var($Constructor, con, $nc(getImplClass())->getConstructor($$new($ClassArray, {ctrParamClz})));
			return $of($nc(con)->newInstance($$new($ObjectArray, {ctorParamObj})));
		} catch ($NoSuchMethodException& nsme) {
			if (ctorParamObj == nullptr) {
				try {
					return $of(newInstanceOf());
				} catch ($NoSuchMethodException& nsme2) {
					nsme->addSuppressed(nsme2);
					$throw(nsme);
				}
			} else {
				$throw(nsme);
			}
		}
	}
	$shouldNotReachHere();
}

$Class* Provider$Service::getImplClass() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	try {
		$var($Object, cache, this->classCache);
		{
			$Class* clazz = nullptr;
			bool var$0 = $instanceOf($Class, cache);
			if (var$0) {
				clazz = $cast($Class, cache);
				var$0 = true;
			}
			if (var$0) {
				return clazz;
			}
		}
		$Class* clazz = nullptr;
		{
			$var($WeakReference, ref, nullptr);
			bool var$1 = $instanceOf($WeakReference, cache);
			if (var$1) {
				$assign(ref, $cast($WeakReference, cache));
				var$1 = true;
			}
			if (var$1) {
				clazz = $cast($Class, $nc(ref)->get());
			}
		}
		if (clazz == nullptr) {
			$var($ClassLoader, cl, $nc($of(this->provider))->getClass()->getClassLoader());
			if (cl == nullptr) {
				clazz = $Class::forName(this->className);
			} else {
				clazz = $nc(cl)->loadClass(this->className);
			}
			if (!$Modifier::isPublic($nc(clazz)->getModifiers())) {
				$throwNew($NoSuchAlgorithmException, $$str({"class configured for "_s, this->type, " (provider: "_s, $($nc(this->provider)->getName()), ") is not public."_s}));
			}
			$set(this, classCache, (cl == nullptr) ? $of(clazz) : $of($new($WeakReference, clazz)));
		}
		return clazz;
	} catch ($ClassNotFoundException& e) {
		$throwNew($NoSuchAlgorithmException, $$str({"class configured for "_s, this->type, " (provider: "_s, $($nc(this->provider)->getName()), ") cannot be found."_s}), e);
	}
	$shouldNotReachHere();
}

$Constructor* Provider$Service::getDefaultConstructor() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($Object, cache, this->constructorCache);
	{
		$var($Constructor, con, nullptr);
		bool var$0 = $instanceOf($Constructor, cache);
		if (var$0) {
			$assign(con, $cast($Constructor, cache));
			var$0 = true;
		}
		if (var$0) {
			return con;
		}
	}
	$var($Constructor, con, nullptr);
	{
		$var($WeakReference, ref, nullptr);
		bool var$1 = $instanceOf($WeakReference, cache);
		if (var$1) {
			$assign(ref, $cast($WeakReference, cache));
			var$1 = true;
		}
		if (var$1) {
			$assign(con, $cast($Constructor, $nc(ref)->get()));
		}
	}
	if (con == nullptr) {
		$Class* clazz = getImplClass();
		$assign(con, $nc(clazz)->getConstructor($$new($ClassArray, 0)));
		$set(this, constructorCache, (clazz->getClassLoader() == nullptr) ? $of(con) : $of($new($WeakReference, con)));
	}
	return con;
}

bool Provider$Service::supportsParameter(Object$* parameter) {
	$useLocalCurrentObjectStackCache();
	$var($Provider$EngineDescription, cap, this->engineDescription);
	if (cap == nullptr) {
		return true;
	}
	if (!$nc(cap)->supportsParameter) {
		$throwNew($InvalidParameterException, $$str({"supportsParameter() not used with "_s, this->type, " engines"_s}));
	}
	if ((parameter != nullptr) && (!($instanceOf($Key, parameter)))) {
		$throwNew($InvalidParameterException, $$str({"Parameter must be instanceof Key for engine "_s, this->type}));
	}
	if (!hasKeyAttributes()) {
		return true;
	}
	if (parameter == nullptr) {
		return false;
	}
	$var($Key, key, $cast($Key, parameter));
	if (supportsKeyFormat(key)) {
		return true;
	}
	if (supportsKeyClass(key)) {
		return true;
	}
	return false;
}

bool Provider$Service::hasKeyAttributes() {
	$useLocalCurrentObjectStackCache();
	$var($Boolean, b, this->hasKeyAttributes$);
	if (b == nullptr) {
		$synchronized(this) {
			$assign(b, this->hasKeyAttributes$);
			if (b == nullptr) {
				$var($String, s, nullptr);
				$assign(s, getAttribute("SupportedKeyFormats"_s));
				if (s != nullptr) {
					$set(this, supportedFormats, s->split("\\|"_s));
				}
				$assign(s, getAttribute("SupportedKeyClasses"_s));
				if (s != nullptr) {
					$var($StringArray, classNames, s->split("\\|"_s));
					$var($List, classList, $new($ArrayList, classNames->length));
					{
						$var($StringArray, arr$, classNames);
						int32_t len$ = arr$->length;
						int32_t i$ = 0;
						for (; i$ < len$; ++i$) {
							$var($String, className, arr$->get(i$));
							{
								$Class* clazz = getKeyClass(className);
								if (clazz != nullptr) {
									classList->add(clazz);
								}
							}
						}
					}
					$set(this, supportedClasses, $fcast($ClassArray, classList->toArray(Provider$Service::CLASS0)));
				}
				bool bool$ = (this->supportedFormats != nullptr) || (this->supportedClasses != nullptr);
				$assign(b, $Boolean::valueOf(bool$));
				$set(this, hasKeyAttributes$, b);
			}
		}
	}
	return $nc(b)->booleanValue();
}

$Class* Provider$Service::getKeyClass($String* name) {
	$beforeCallerSensitive();
	try {
		return $Class::forName(name);
	} catch ($ClassNotFoundException& e) {
	}
	try {
		$var($ClassLoader, cl, $nc($of(this->provider))->getClass()->getClassLoader());
		if (cl != nullptr) {
			return cl->loadClass(name);
		}
	} catch ($ClassNotFoundException& e) {
	}
	return nullptr;
}

bool Provider$Service::supportsKeyFormat($Key* key) {
	$useLocalCurrentObjectStackCache();
	if (this->supportedFormats == nullptr) {
		return false;
	}
	$var($String, format, $nc(key)->getFormat());
	if (format == nullptr) {
		return false;
	}
	{
		$var($StringArray, arr$, this->supportedFormats);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, supportedFormat, arr$->get(i$));
			{
				if ($nc(supportedFormat)->equals(format)) {
					return true;
				}
			}
		}
	}
	return false;
}

bool Provider$Service::supportsKeyClass($Key* key) {
	if (this->supportedClasses == nullptr) {
		return false;
	}
	$Class* keyClass = $nc($of(key))->getClass();
	{
		$var($ClassArray, arr$, this->supportedClasses);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$Class* clazz = arr$->get(i$);
			{
				if ($nc(clazz)->isAssignableFrom(keyClass)) {
					return true;
				}
			}
		}
	}
	return false;
}

$String* Provider$Service::toString() {
	$useLocalCurrentObjectStackCache();
	$var($String, aString, $nc(this->aliases)->isEmpty() ? ""_s : $str({"\r\n  aliases: "_s, $($nc($of(this->aliases))->toString())}));
	$var($String, attrs, $nc(this->attributes)->isEmpty() ? ""_s : $str({"\r\n  attributes: "_s, $($nc($of(this->attributes))->toString())}));
	return $str({$($nc(this->provider)->getName()), ": "_s, this->type, "."_s, this->algorithm, " -> "_s, this->className, aString, attrs, "\r\n"_s});
}

void clinit$Provider$Service($Class* class$) {
	$assignStatic(Provider$Service::CLASS0, $new($ClassArray, 0));
}

Provider$Service::Provider$Service() {
}

$Class* Provider$Service::load$($String* name, bool initialize) {
	$loadClass(Provider$Service, name, initialize, &_Provider$Service_ClassInfo_, clinit$Provider$Service, allocate$Provider$Service);
	return class$;
}

$Class* Provider$Service::class$ = nullptr;

	} // security
} // java