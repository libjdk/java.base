#include <java/security/Security.h>

#include <java/io/BufferedInputStream.h>
#include <java/io/File.h>
#include <java/io/FileInputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/lang/AssertionError.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/SecurityException.h>
#include <java/lang/SecurityManager.h>
#include <java/net/URL.h>
#include <java/security/AccessController.h>
#include <java/security/InvalidParameterException.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/Provider.h>
#include <java/security/Security$1.h>
#include <java/security/Security$ProviderProperty.h>
#include <java/security/SecurityPermission.h>
#include <java/util/AbstractMap.h>
#include <java/util/Collections.h>
#include <java/util/Enumeration.h>
#include <java/util/HashSet.h>
#include <java/util/Hashtable.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedHashSet.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/Map.h>
#include <java/util/Properties.h>
#include <java/util/Set.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <jdk/internal/access/JavaLangAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jdk/internal/event/EventHelper.h>
#include <jdk/internal/event/SecurityPropertyModificationEvent.h>
#include <jdk/internal/util/StaticProperty.h>
#include <sun/security/jca/GetInstance$Instance.h>
#include <sun/security/jca/GetInstance.h>
#include <sun/security/jca/ProviderList.h>
#include <sun/security/jca/Providers.h>
#include <sun/security/util/Debug.h>
#include <sun/security/util/PropertyExpander.h>
#include <jcpp.h>

#undef ENGLISH

using $ProviderArray = $Array<::java::security::Provider>;
using $BufferedInputStream = ::java::io::BufferedInputStream;
using $File = ::java::io::File;
using $FileInputStream = ::java::io::FileInputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $SecurityException = ::java::lang::SecurityException;
using $SecurityManager = ::java::lang::SecurityManager;
using $URL = ::java::net::URL;
using $AccessController = ::java::security::AccessController;
using $InvalidParameterException = ::java::security::InvalidParameterException;
using $Permission = ::java::security::Permission;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Provider = ::java::security::Provider;
using $Security$1 = ::java::security::Security$1;
using $Security$ProviderProperty = ::java::security::Security$ProviderProperty;
using $SecurityPermission = ::java::security::SecurityPermission;
using $AbstractMap = ::java::util::AbstractMap;
using $Collections = ::java::util::Collections;
using $Enumeration = ::java::util::Enumeration;
using $HashSet = ::java::util::HashSet;
using $Hashtable = ::java::util::Hashtable;
using $Iterator = ::java::util::Iterator;
using $LinkedHashSet = ::java::util::LinkedHashSet;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $Properties = ::java::util::Properties;
using $Set = ::java::util::Set;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $JavaLangAccess = ::jdk::internal::access::JavaLangAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $EventHelper = ::jdk::internal::event::EventHelper;
using $SecurityPropertyModificationEvent = ::jdk::internal::event::SecurityPropertyModificationEvent;
using $StaticProperty = ::jdk::internal::util::StaticProperty;
using $GetInstance = ::sun::security::jca::GetInstance;
using $GetInstance$Instance = ::sun::security::jca::GetInstance$Instance;
using $ProviderList = ::sun::security::jca::ProviderList;
using $Providers = ::sun::security::jca::Providers;
using $Debug = ::sun::security::util::Debug;
using $PropertyExpander = ::sun::security::util::PropertyExpander;

namespace java {
	namespace security {

$CompoundAttribute _Security_MethodAnnotations_getAlgorithmProperty4[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _Security_FieldInfo_[] = {
	{"sdebug", "Lsun/security/util/Debug;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Security, sdebug)},
	{"props", "Ljava/util/Properties;", nullptr, $PRIVATE | $STATIC, $staticField(Security, props)},
	{"spiMap", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/Class<*>;>;", $PRIVATE | $STATIC | $FINAL, $staticField(Security, spiMap)},
	{}
};

$MethodInfo _Security_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(Security, init$, void)},
	{"addProvider", "(Ljava/security/Provider;)I", nullptr, $PUBLIC | $STATIC, $staticMethod(Security, addProvider, int32_t, $Provider*)},
	{"check", "(Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Security, check, void, $String*)},
	{"checkInsertProvider", "(Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Security, checkInsertProvider, void, $String*)},
	{"getAlgorithmProperty", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $DEPRECATED, $staticMethod(Security, getAlgorithmProperty, $String*, $String*, $String*), nullptr, nullptr, _Security_MethodAnnotations_getAlgorithmProperty4},
	{"getAlgorithms", "(Ljava/lang/String;)Ljava/util/Set;", "(Ljava/lang/String;)Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC | $STATIC, $staticMethod(Security, getAlgorithms, $Set*, $String*)},
	{"getAllQualifyingCandidates", "(Ljava/lang/String;Ljava/lang/String;[Ljava/security/Provider;)Ljava/util/LinkedHashSet;", "(Ljava/lang/String;Ljava/lang/String;[Ljava/security/Provider;)Ljava/util/LinkedHashSet<Ljava/security/Provider;>;", $PRIVATE | $STATIC, $staticMethod(Security, getAllQualifyingCandidates, $LinkedHashSet*, $String*, $String*, $ProviderArray*)},
	{"getFilterComponents", "(Ljava/lang/String;Ljava/lang/String;)[Ljava/lang/String;", nullptr, $STATIC, $staticMethod(Security, getFilterComponents, $StringArray*, $String*, $String*)},
	{"getImpl", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)[Ljava/lang/Object;", nullptr, $STATIC, $staticMethod(Security, getImpl, $ObjectArray*, $String*, $String*, $String*), "java.security.NoSuchAlgorithmException,java.security.NoSuchProviderException"},
	{"getImpl", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/Object;)[Ljava/lang/Object;", nullptr, $STATIC, $staticMethod(Security, getImpl, $ObjectArray*, $String*, $String*, $String*, Object$*), "java.security.NoSuchAlgorithmException,java.security.NoSuchProviderException,java.security.InvalidAlgorithmParameterException"},
	{"getImpl", "(Ljava/lang/String;Ljava/lang/String;Ljava/security/Provider;)[Ljava/lang/Object;", nullptr, $STATIC, $staticMethod(Security, getImpl, $ObjectArray*, $String*, $String*, $Provider*), "java.security.NoSuchAlgorithmException"},
	{"getImpl", "(Ljava/lang/String;Ljava/lang/String;Ljava/security/Provider;Ljava/lang/Object;)[Ljava/lang/Object;", nullptr, $STATIC, $staticMethod(Security, getImpl, $ObjectArray*, $String*, $String*, $Provider*, Object$*), "java.security.NoSuchAlgorithmException,java.security.InvalidAlgorithmParameterException"},
	{"getProperty", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(Security, getProperty, $String*, $String*)},
	{"getProvider", "(Ljava/lang/String;)Ljava/security/Provider;", nullptr, $PUBLIC | $STATIC, $staticMethod(Security, getProvider, $Provider*, $String*)},
	{"getProviderProperty", "(Ljava/lang/String;)Ljava/security/Security$ProviderProperty;", nullptr, $PRIVATE | $STATIC, $staticMethod(Security, getProviderProperty, $Security$ProviderProperty*, $String*)},
	{"getProviderProperty", "(Ljava/lang/String;Ljava/security/Provider;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(Security, getProviderProperty, $String*, $String*, $Provider*)},
	{"getProviders", "()[Ljava/security/Provider;", nullptr, $PUBLIC | $STATIC, $staticMethod(Security, getProviders, $ProviderArray*)},
	{"getProviders", "(Ljava/lang/String;)[Ljava/security/Provider;", nullptr, $PUBLIC | $STATIC, $staticMethod(Security, getProviders, $ProviderArray*, $String*)},
	{"getProviders", "(Ljava/util/Map;)[Ljava/security/Provider;", "(Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;)[Ljava/security/Provider;", $PUBLIC | $STATIC, $staticMethod(Security, getProviders, $ProviderArray*, $Map*)},
	{"getProvidersNotUsingCache", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;[Ljava/security/Provider;)Ljava/util/LinkedHashSet;", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;[Ljava/security/Provider;)Ljava/util/LinkedHashSet<Ljava/security/Provider;>;", $PRIVATE | $STATIC, $staticMethod(Security, getProvidersNotUsingCache, $LinkedHashSet*, $String*, $String*, $String*, $String*, $ProviderArray*)},
	{"getSpiClass", "(Ljava/lang/String;)Ljava/lang/Class;", "(Ljava/lang/String;)Ljava/lang/Class<*>;", $PRIVATE | $STATIC, $staticMethod(Security, getSpiClass, $Class*, $String*)},
	{"initialize", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(Security, initialize, void)},
	{"initializeStatic", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(Security, initializeStatic, void)},
	{"insertProviderAt", "(Ljava/security/Provider;I)I", nullptr, $PUBLIC | $STATIC | $SYNCHRONIZED, $staticMethod(Security, insertProviderAt, int32_t, $Provider*, int32_t)},
	{"invalidateSMCache", "(Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Security, invalidateSMCache, void, $String*)},
	{"isConstraintSatisfied", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(Security, isConstraintSatisfied, bool, $String*, $String*, $String*)},
	{"isCriterionSatisfied", "(Ljava/security/Provider;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(Security, isCriterionSatisfied, bool, $Provider*, $String*, $String*, $String*, $String*)},
	{"isStandardAttr", "(Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(Security, isStandardAttr, bool, $String*)},
	{"removeProvider", "(Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC | $SYNCHRONIZED, $staticMethod(Security, removeProvider, void, $String*)},
	{"securityPropFile", "(Ljava/lang/String;)Ljava/io/File;", nullptr, $PRIVATE | $STATIC, $staticMethod(Security, securityPropFile, $File*, $String*)},
	{"setProperty", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(Security, setProperty, void, $String*, $String*)},
	{}
};

$InnerClassInfo _Security_InnerClassesInfo_[] = {
	{"java.security.Security$ProviderProperty", "java.security.Security", "ProviderProperty", $PRIVATE | $STATIC},
	{"java.security.Security$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Security_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.security.Security",
	"java.lang.Object",
	nullptr,
	_Security_FieldInfo_,
	_Security_MethodInfo_,
	nullptr,
	nullptr,
	_Security_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.security.Security$ProviderProperty,java.security.Security$1"
};

$Object* allocate$Security($Class* clazz) {
	return $of($alloc(Security));
}

$Debug* Security::sdebug = nullptr;
$Properties* Security::props = nullptr;
$Map* Security::spiMap = nullptr;

void Security::initialize() {
	$init(Security);
	$useLocalCurrentObjectStackCache();
	$assignStatic(Security::props, $new($Properties));
	bool loadedProps = false;
	bool overrideAll = false;
	$var($File, propFile, securityPropFile("java.security"_s));
	if ($nc(propFile)->exists()) {
		$var($InputStream, is, nullptr);
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					$var($FileInputStream, fis, $new($FileInputStream, propFile));
					$assign(is, $new($BufferedInputStream, fis));
					$nc(Security::props)->load(is);
					loadedProps = true;
					if (Security::sdebug != nullptr) {
						$nc(Security::sdebug)->println($$str({"reading security properties file: "_s, propFile}));
					}
				} catch ($IOException& e) {
					if (Security::sdebug != nullptr) {
						$nc(Security::sdebug)->println($$str({"unable to load security properties from "_s, propFile}));
						e->printStackTrace();
					}
				}
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				if (is != nullptr) {
					try {
						is->close();
					} catch ($IOException& ioe) {
						if (Security::sdebug != nullptr) {
							$nc(Security::sdebug)->println("unable to close input stream"_s);
						}
					}
				}
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
	if ("true"_s->equalsIgnoreCase($($nc(Security::props)->getProperty("security.overridePropertiesFile"_s)))) {
		$var($String, extraPropFile, $System::getProperty("java.security.properties"_s));
		if (extraPropFile != nullptr && extraPropFile->startsWith("="_s)) {
			overrideAll = true;
			$assign(extraPropFile, extraPropFile->substring(1));
		}
		if (overrideAll) {
			$assignStatic(Security::props, $new($Properties));
			if (Security::sdebug != nullptr) {
				$nc(Security::sdebug)->println("overriding other security properties files!"_s);
			}
		}
		if (extraPropFile != nullptr) {
			$var($BufferedInputStream, bis, nullptr);
			{
				$var($Throwable, var$2, nullptr);
				try {
					try {
						$var($URL, propURL, nullptr);
						$assign(extraPropFile, $PropertyExpander::expand(extraPropFile));
						$assign(propFile, $new($File, extraPropFile));
						if (propFile->exists()) {
							$assign(propURL, $new($URL, $$str({"file:"_s, $(propFile->getCanonicalPath())})));
						} else {
							$assign(propURL, $new($URL, extraPropFile));
						}
						$assign(bis, $new($BufferedInputStream, $($nc(propURL)->openStream())));
						$nc(Security::props)->load(static_cast<$InputStream*>(bis));
						loadedProps = true;
						if (Security::sdebug != nullptr) {
							$nc(Security::sdebug)->println($$str({"reading security properties file: "_s, propURL}));
							if (overrideAll) {
								$nc(Security::sdebug)->println("overriding other security properties files!"_s);
							}
						}
					} catch ($Exception& e) {
						if (Security::sdebug != nullptr) {
							$nc(Security::sdebug)->println($$str({"unable to load security properties from "_s, extraPropFile}));
							e->printStackTrace();
						}
					}
				} catch ($Throwable& var$3) {
					$assign(var$2, var$3);
				} /*finally*/ {
					if (bis != nullptr) {
						try {
							bis->close();
						} catch ($IOException& ioe) {
							if (Security::sdebug != nullptr) {
								$nc(Security::sdebug)->println("unable to close input stream"_s);
							}
						}
					}
				}
				if (var$2 != nullptr) {
					$throw(var$2);
				}
			}
		}
	}
	if (!loadedProps) {
		initializeStatic();
		if (Security::sdebug != nullptr) {
			$nc(Security::sdebug)->println("unable to load security properties -- using defaults"_s);
		}
	}
}

void Security::initializeStatic() {
	$init(Security);
	$nc(Security::props)->put("security.provider.1"_s, "sun.security.provider.Sun"_s);
	$nc(Security::props)->put("security.provider.2"_s, "sun.security.rsa.SunRsaSign"_s);
	$nc(Security::props)->put("security.provider.3"_s, "sun.security.ssl.SunJSSE"_s);
	$nc(Security::props)->put("security.provider.4"_s, "com.sun.crypto.provider.SunJCE"_s);
	$nc(Security::props)->put("security.provider.5"_s, "sun.security.jgss.SunProvider"_s);
	$nc(Security::props)->put("security.provider.6"_s, "com.sun.security.sasl.Provider"_s);
}

void Security::init$() {
}

$File* Security::securityPropFile($String* filename) {
	$init(Security);
	$useLocalCurrentObjectStackCache();
	$init($File);
	$var($String, sep, $File::separator);
	return $new($File, $$str({$($StaticProperty::javaHome()), sep, "conf"_s, sep, "security"_s, sep, filename}));
}

$Security$ProviderProperty* Security::getProviderProperty($String* key) {
	$init(Security);
	$useLocalCurrentObjectStackCache();
	$var($Security$ProviderProperty, entry, nullptr);
	$var($List, providers, $nc($($Providers::getProviderList()))->providers());
	for (int32_t i = 0; i < $nc(providers)->size(); ++i) {
		$var($String, matchKey, nullptr);
		$var($Provider, prov, $cast($Provider, providers->get(i)));
		$var($String, prop, $nc(prov)->getProperty(key));
		if (prop == nullptr) {
			{
				$var($Enumeration, e, prov->keys());
				for (; $nc(e)->hasMoreElements() && prop == nullptr;) {
					$assign(matchKey, $cast($String, e->nextElement()));
					if ($nc(key)->equalsIgnoreCase(matchKey)) {
						$assign(prop, prov->getProperty(matchKey));
						break;
					}
				}
			}
		}
		if (prop != nullptr) {
			$var($Security$ProviderProperty, newEntry, $new($Security$ProviderProperty));
			$set(newEntry, className, prop);
			$set(newEntry, provider, prov);
			return newEntry;
		}
	}
	return entry;
}

$String* Security::getProviderProperty($String* key, $Provider* provider) {
	$init(Security);
	$useLocalCurrentObjectStackCache();
	$var($String, prop, $nc(provider)->getProperty(key));
	if (prop == nullptr) {
		{
			$var($Enumeration, e, provider->keys());
			for (; $nc(e)->hasMoreElements() && prop == nullptr;) {
				$var($String, matchKey, $cast($String, e->nextElement()));
				if ($nc(key)->equalsIgnoreCase(matchKey)) {
					$assign(prop, provider->getProperty(matchKey));
					break;
				}
			}
		}
	}
	return prop;
}

$String* Security::getAlgorithmProperty($String* algName, $String* propName) {
	$init(Security);
	$useLocalCurrentObjectStackCache();
	$var($Security$ProviderProperty, entry, getProviderProperty($$str({"Alg."_s, propName, "."_s, algName})));
	if (entry != nullptr) {
		return entry->className;
	} else {
		return nullptr;
	}
}

int32_t Security::insertProviderAt($Provider* provider, int32_t position) {
	$load(Security);
	$synchronized(class$) {
		$init(Security);
		$useLocalCurrentObjectStackCache();
		$var($String, providerName, $nc(provider)->getName());
		checkInsertProvider(providerName);
		$var($ProviderList, list, $Providers::getFullProviderList());
		$var($ProviderList, newList, $ProviderList::insertAt(list, provider, position - 1));
		if (list == newList) {
			return -1;
		}
		$Providers::setProviderList(newList);
		return $nc(newList)->getIndex(providerName) + 1;
	}
}

int32_t Security::addProvider($Provider* provider) {
	$init(Security);
	return insertProviderAt(provider, 0);
}

void Security::removeProvider($String* name) {
	$load(Security);
	$synchronized(class$) {
		$init(Security);
		$useLocalCurrentObjectStackCache();
		check($$str({"removeProvider."_s, name}));
		$var($ProviderList, list, $Providers::getFullProviderList());
		$var($ProviderList, newList, $ProviderList::remove(list, name));
		$Providers::setProviderList(newList);
	}
}

$ProviderArray* Security::getProviders() {
	$init(Security);
	return $nc($($Providers::getFullProviderList()))->toArray();
}

$Provider* Security::getProvider($String* name) {
	$init(Security);
	return $nc($($Providers::getProviderList()))->getProvider(name);
}

$ProviderArray* Security::getProviders($String* filter) {
	$init(Security);
	$useLocalCurrentObjectStackCache();
	$var($String, key, nullptr);
	$var($String, value, nullptr);
	int32_t index = $nc(filter)->indexOf((int32_t)u':');
	if (index == -1) {
		$assign(key, filter);
		$assign(value, ""_s);
	} else {
		$assign(key, filter->substring(0, index));
		$assign(value, filter->substring(index + 1));
	}
	$var($Hashtable, hashtableFilter, $new($Hashtable, 1));
	hashtableFilter->put(key, value);
	return (getProviders(static_cast<$Map*>(hashtableFilter)));
}

$ProviderArray* Security::getProviders($Map* filter) {
	$init(Security);
	$useLocalCurrentObjectStackCache();
	$var($ProviderArray, allProviders, Security::getProviders());
	$var($Set, keySet, $nc(filter)->keySet());
	$var($LinkedHashSet, candidates, $new($LinkedHashSet, 5));
	if ((keySet == nullptr) || (allProviders == nullptr)) {
		return allProviders;
	}
	bool firstSearch = true;
	{
		$var($Iterator, ite, $nc(keySet)->iterator());
		for (; $nc(ite)->hasNext();) {
			$var($String, key, $cast($String, ite->next()));
			$var($String, value, $cast($String, filter->get(key)));
			$var($LinkedHashSet, newCandidates, getAllQualifyingCandidates(key, value, allProviders));
			if (firstSearch) {
				$assign(candidates, newCandidates);
				firstSearch = false;
			}
			if ((newCandidates != nullptr) && !newCandidates->isEmpty()) {
				{
					$var($Iterator, cansIte, $nc(candidates)->iterator());
					for (; $nc(cansIte)->hasNext();) {
						$var($Provider, prov, $cast($Provider, cansIte->next()));
						if (!newCandidates->contains(prov)) {
							cansIte->remove();
						}
					}
				}
			} else {
				$assign(candidates, nullptr);
				break;
			}
		}
	}
	if (candidates == nullptr || $nc(candidates)->isEmpty()) {
		return nullptr;
	}
	$var($ObjectArray, candidatesArray, $nc(candidates)->toArray());
	$var($ProviderArray, result, $new($ProviderArray, $nc(candidatesArray)->length));
	for (int32_t i = 0; i < result->length; ++i) {
		result->set(i, $cast($Provider, candidatesArray->get(i)));
	}
	return result;
}

$Class* Security::getSpiClass($String* type) {
	$init(Security);
	$beforeCallerSensitive();
	$Class* clazz = $cast($Class, $nc(Security::spiMap)->get(type));
	if (clazz != nullptr) {
		return clazz;
	}
	try {
		clazz = $Class::forName($$str({"java.security."_s, type, "Spi"_s}));
		$nc(Security::spiMap)->put(type, clazz);
		return clazz;
	} catch ($ClassNotFoundException& e) {
		$throwNew($AssertionError, "Spi class not found"_s, e);
	}
	$shouldNotReachHere();
}

$ObjectArray* Security::getImpl($String* algorithm, $String* type, $String* provider) {
	$init(Security);
	$useLocalCurrentObjectStackCache();
	if (provider == nullptr) {
		return $nc($($GetInstance::getInstance(type, getSpiClass(type), algorithm)))->toArray();
	} else {
		return $nc($($GetInstance::getInstance(type, getSpiClass(type), algorithm, provider)))->toArray();
	}
}

$ObjectArray* Security::getImpl($String* algorithm, $String* type, $String* provider, Object$* params) {
	$init(Security);
	$useLocalCurrentObjectStackCache();
	if (provider == nullptr) {
		return $nc($($GetInstance::getInstance(type, getSpiClass(type), algorithm, params)))->toArray();
	} else {
		return $nc($($GetInstance::getInstance(type, getSpiClass(type), algorithm, params, provider)))->toArray();
	}
}

$ObjectArray* Security::getImpl($String* algorithm, $String* type, $Provider* provider) {
	$init(Security);
	return $nc($($GetInstance::getInstance(type, getSpiClass(type), algorithm, provider)))->toArray();
}

$ObjectArray* Security::getImpl($String* algorithm, $String* type, $Provider* provider, Object$* params) {
	$init(Security);
	return $nc($($GetInstance::getInstance(type, getSpiClass(type), algorithm, params, provider)))->toArray();
}

$String* Security::getProperty($String* key) {
	$init(Security);
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission($$new($SecurityPermission, $$str({"getProperty."_s, key})));
	}
	$var($String, name, $nc(Security::props)->getProperty(key));
	if (name != nullptr) {
		$assign(name, name->trim());
	}
	return name;
}

void Security::setProperty($String* key, $String* datum) {
	$init(Security);
	$useLocalCurrentObjectStackCache();
	check($$str({"setProperty."_s, key}));
	$nc(Security::props)->put(key, datum);
	invalidateSMCache(key);
	$var($SecurityPropertyModificationEvent, spe, $new($SecurityPropertyModificationEvent));
	$set(spe, key, key);
	$set(spe, value, datum);
	spe->commit();
	if ($EventHelper::isLoggingSecurity()) {
		$EventHelper::logSecurityPropertyEvent(key, datum);
	}
}

void Security::invalidateSMCache($String* key) {
	$init(Security);
	bool pa = $nc(key)->equals("package.access"_s);
	bool pd = key->equals("package.definition"_s);
	if (pa || pd) {
		$nc($($SharedSecrets::getJavaLangAccess()))->invalidatePackageAccessCache();
	}
}

void Security::check($String* directive) {
	$init(Security);
	$var($SecurityManager, security, $System::getSecurityManager());
	if (security != nullptr) {
		security->checkSecurityAccess(directive);
	}
}

void Security::checkInsertProvider($String* name) {
	$init(Security);
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, security, $System::getSecurityManager());
	if (security != nullptr) {
		try {
			security->checkSecurityAccess("insertProvider"_s);
		} catch ($SecurityException& se1) {
			try {
				security->checkSecurityAccess($$str({"insertProvider."_s, name}));
			} catch ($SecurityException& se2) {
				se1->addSuppressed(se2);
				$throw(se1);
			}
		}
	}
}

$LinkedHashSet* Security::getAllQualifyingCandidates($String* filterKey, $String* filterValue, $ProviderArray* allProviders) {
	$init(Security);
	$useLocalCurrentObjectStackCache();
	$var($StringArray, filterComponents, getFilterComponents(filterKey, filterValue));
	$var($String, serviceName, $nc(filterComponents)->get(0));
	$var($String, algName, filterComponents->get(1));
	$var($String, attrName, filterComponents->get(2));
	return getProvidersNotUsingCache(serviceName, algName, attrName, filterValue, allProviders);
}

$LinkedHashSet* Security::getProvidersNotUsingCache($String* serviceName, $String* algName, $String* attrName, $String* filterValue, $ProviderArray* allProviders) {
	$init(Security);
	$var($LinkedHashSet, candidates, $new($LinkedHashSet, 5));
	for (int32_t i = 0; i < $nc(allProviders)->length; ++i) {
		if (isCriterionSatisfied(allProviders->get(i), serviceName, algName, attrName, filterValue)) {
			candidates->add(allProviders->get(i));
		}
	}
	return candidates;
}

bool Security::isCriterionSatisfied($Provider* prov, $String* serviceName, $String* algName, $String* attrName, $String* filterValue) {
	$init(Security);
	$useLocalCurrentObjectStackCache();
	$var($String, key, $str({serviceName, $$str(u'.'), algName}));
	if (attrName != nullptr) {
		$plusAssign(key, $$str({$$str(u' '), attrName}));
	}
	$var($String, propValue, getProviderProperty(key, prov));
	if (propValue == nullptr) {
		$var($String, standardName, getProviderProperty($$str({"Alg.Alias."_s, serviceName, "."_s, algName}), prov));
		if (standardName != nullptr) {
			$assign(key, $str({serviceName, "."_s, standardName}));
			if (attrName != nullptr) {
				$plusAssign(key, $$str({$$str(u' '), attrName}));
			}
			$assign(propValue, getProviderProperty(key, prov));
		}
		if (propValue == nullptr) {
			return false;
		}
	}
	if (attrName == nullptr) {
		return true;
	}
	if (isStandardAttr(attrName)) {
		return isConstraintSatisfied(attrName, filterValue, propValue);
	} else {
		return $nc(filterValue)->equalsIgnoreCase(propValue);
	}
}

bool Security::isStandardAttr($String* attribute) {
	$init(Security);
	if ($nc(attribute)->equalsIgnoreCase("KeySize"_s)) {
		return true;
	}
	if ($nc(attribute)->equalsIgnoreCase("ImplementedIn"_s)) {
		return true;
	}
	return false;
}

bool Security::isConstraintSatisfied($String* attribute, $String* value, $String* prop) {
	$init(Security);
	if ($nc(attribute)->equalsIgnoreCase("KeySize"_s)) {
		int32_t requestedSize = $Integer::parseInt(value);
		int32_t maxSize = $Integer::parseInt(prop);
		if (requestedSize <= maxSize) {
			return true;
		} else {
			return false;
		}
	}
	if ($nc(attribute)->equalsIgnoreCase("ImplementedIn"_s)) {
		return $nc(value)->equalsIgnoreCase(prop);
	}
	return false;
}

$StringArray* Security::getFilterComponents($String* filterKey, $String* filterValue) {
	$init(Security);
	$useLocalCurrentObjectStackCache();
	int32_t algIndex = $nc(filterKey)->indexOf((int32_t)u'.');
	if (algIndex < 0) {
		$throwNew($InvalidParameterException, "Invalid filter"_s);
	}
	$var($String, serviceName, filterKey->substring(0, algIndex));
	$var($String, algName, nullptr);
	$var($String, attrName, nullptr);
	if ($nc(filterValue)->isEmpty()) {
		$assign(algName, $(filterKey->substring(algIndex + 1))->trim());
		if (algName->isEmpty()) {
			$throwNew($InvalidParameterException, "Invalid filter"_s);
		}
	} else {
		int32_t attrIndex = filterKey->indexOf((int32_t)u' ');
		if (attrIndex == -1) {
			$throwNew($InvalidParameterException, "Invalid filter"_s);
		} else {
			$assign(attrName, $(filterKey->substring(attrIndex + 1))->trim());
			if (attrName->isEmpty()) {
				$throwNew($InvalidParameterException, "Invalid filter"_s);
			}
		}
		if ((attrIndex < algIndex) || (algIndex == attrIndex - 1)) {
			$throwNew($InvalidParameterException, "Invalid filter"_s);
		} else {
			$assign(algName, filterKey->substring(algIndex + 1, attrIndex));
		}
	}
	$var($StringArray, result, $new($StringArray, 3));
	result->set(0, serviceName);
	result->set(1, algName);
	result->set(2, attrName);
	return result;
}

$Set* Security::getAlgorithms($String* serviceName) {
	$init(Security);
	$useLocalCurrentObjectStackCache();
	bool var$0 = (serviceName == nullptr) || ($nc(serviceName)->isEmpty());
	if (var$0 || ($nc(serviceName)->endsWith("."_s))) {
		return $Collections::emptySet();
	}
	$var($HashSet, result, $new($HashSet));
	$var($ProviderArray, providers, Security::getProviders());
	for (int32_t i = 0; i < $nc(providers)->length; ++i) {
		{
			$var($Enumeration, e, $nc(providers->get(i))->keys());
			for (; $nc(e)->hasMoreElements();) {
				$init($Locale);
				$var($String, currentKey, $nc(($cast($String, $(e->nextElement()))))->toUpperCase($Locale::ENGLISH));
				if (currentKey->startsWith($($nc(serviceName)->toUpperCase($Locale::ENGLISH)))) {
					if (currentKey->indexOf((int32_t)u' ') < 0) {
						result->add($(currentKey->substring($nc(serviceName)->length() + 1)));
					}
				}
			}
		}
	}
	return $Collections::unmodifiableSet(result);
}

void clinit$Security($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$assignStatic(Security::sdebug, $Debug::getInstance("properties"_s));
	{
		$var($Object, dummy, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($Security$1))));
	}
	$assignStatic(Security::spiMap, static_cast<$Map*>(static_cast<$AbstractMap*>($new($ConcurrentHashMap))));
}

Security::Security() {
}

$Class* Security::load$($String* name, bool initialize) {
	$loadClass(Security, name, initialize, &_Security_ClassInfo_, clinit$Security, allocate$Security);
	return class$;
}

$Class* Security::class$ = nullptr;

	} // security
} // java