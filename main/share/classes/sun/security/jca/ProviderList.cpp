#include <sun/security/jca/ProviderList.h>

#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/Provider$Service.h>
#include <java/security/Provider.h>
#include <java/security/Security.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <sun/security/jca/ProviderConfig.h>
#include <sun/security/jca/ProviderList$1.h>
#include <sun/security/jca/ProviderList$2.h>
#include <sun/security/jca/ProviderList$3.h>
#include <sun/security/jca/ProviderList$PreferredEntry.h>
#include <sun/security/jca/ProviderList$PreferredList.h>
#include <sun/security/jca/ProviderList$ServiceList.h>
#include <sun/security/jca/ServiceId.h>
#include <sun/security/util/Debug.h>
#include <jcpp.h>

#undef EMPTY
#undef EMPTY_PROVIDER
#undef PC0

using $ProviderArray = $Array<::java::security::Provider>;
using $ProviderConfigArray = $Array<::sun::security::jca::ProviderConfig>;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Provider = ::java::security::Provider;
using $Provider$Service = ::java::security::Provider$Service;
using $Security = ::java::security::Security;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $ProviderConfig = ::sun::security::jca::ProviderConfig;
using $ProviderList$1 = ::sun::security::jca::ProviderList$1;
using $ProviderList$2 = ::sun::security::jca::ProviderList$2;
using $ProviderList$3 = ::sun::security::jca::ProviderList$3;
using $ProviderList$PreferredEntry = ::sun::security::jca::ProviderList$PreferredEntry;
using $ProviderList$PreferredList = ::sun::security::jca::ProviderList$PreferredList;
using $ProviderList$ServiceList = ::sun::security::jca::ProviderList$ServiceList;
using $ServiceId = ::sun::security::jca::ServiceId;
using $Debug = ::sun::security::util::Debug;

namespace sun {
	namespace security {
		namespace jca {

$CompoundAttribute _ProviderList_MethodAnnotations_getServices11[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _ProviderList_FieldInfo_[] = {
	{"debug", "Lsun/security/util/Debug;", nullptr, $STATIC | $FINAL, $staticField(ProviderList, debug)},
	{"PC0", "[Lsun/security/jca/ProviderConfig;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProviderList, PC0)},
	{"P0", "[Ljava/security/Provider;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProviderList, P0)},
	{"EMPTY", "Lsun/security/jca/ProviderList;", nullptr, $STATIC | $FINAL, $staticField(ProviderList, EMPTY)},
	{"preferredPropList", "Lsun/security/jca/ProviderList$PreferredList;", nullptr, $PRIVATE | $STATIC, $staticField(ProviderList, preferredPropList)},
	{"EMPTY_PROVIDER", "Ljava/security/Provider;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProviderList, EMPTY_PROVIDER)},
	{"configs", "[Lsun/security/jca/ProviderConfig;", nullptr, $PRIVATE | $FINAL, $field(ProviderList, configs)},
	{"allLoaded", "Z", nullptr, $PRIVATE | $VOLATILE, $field(ProviderList, allLoaded)},
	{"userList", "Ljava/util/List;", "Ljava/util/List<Ljava/security/Provider;>;", $PRIVATE | $FINAL, $field(ProviderList, userList)},
	{"SHA2Group", "[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProviderList, SHA2Group)},
	{"HmacSHA2Group", "[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProviderList, HmacSHA2Group)},
	{"SHA2RSAGroup", "[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProviderList, SHA2RSAGroup)},
	{"SHA2DSAGroup", "[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProviderList, SHA2DSAGroup)},
	{"SHA2ECDSAGroup", "[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProviderList, SHA2ECDSAGroup)},
	{"SHA3Group", "[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProviderList, SHA3Group)},
	{"HmacSHA3Group", "[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProviderList, HmacSHA3Group)},
	{}
};

$MethodInfo _ProviderList_MethodInfo_[] = {
	{"<init>", "([Lsun/security/jca/ProviderConfig;Z)V", nullptr, $PRIVATE, $method(ProviderList, init$, void, $ProviderConfigArray*, bool)},
	{"<init>", "()V", nullptr, $PRIVATE, $method(ProviderList, init$, void)},
	{"add", "(Lsun/security/jca/ProviderList;Ljava/security/Provider;)Lsun/security/jca/ProviderList;", nullptr, $PUBLIC | $STATIC, $staticMethod(ProviderList, add, ProviderList*, ProviderList*, $Provider*)},
	{"fromSecurityProperties", "()Lsun/security/jca/ProviderList;", nullptr, $STATIC, $staticMethod(ProviderList, fromSecurityProperties, ProviderList*)},
	{"getIndex", "(Ljava/lang/String;)I", nullptr, $PUBLIC, $method(ProviderList, getIndex, int32_t, $String*)},
	{"getJarList", "([Ljava/lang/String;)Lsun/security/jca/ProviderList;", nullptr, 0, $method(ProviderList, getJarList, ProviderList*, $StringArray*)},
	{"getProvider", "(I)Ljava/security/Provider;", nullptr, 0, $method(ProviderList, getProvider, $Provider*, int32_t)},
	{"getProvider", "(Ljava/lang/String;)Ljava/security/Provider;", nullptr, $PUBLIC, $method(ProviderList, getProvider, $Provider*, $String*)},
	{"getProviderConfig", "(Ljava/lang/String;)Lsun/security/jca/ProviderConfig;", nullptr, $PRIVATE, $method(ProviderList, getProviderConfig, $ProviderConfig*, $String*)},
	{"getService", "(Ljava/lang/String;Ljava/lang/String;)Ljava/security/Provider$Service;", nullptr, $PUBLIC, $method(ProviderList, getService, $Provider$Service*, $String*, $String*)},
	{"getServices", "(Ljava/lang/String;Ljava/lang/String;)Ljava/util/List;", "(Ljava/lang/String;Ljava/lang/String;)Ljava/util/List<Ljava/security/Provider$Service;>;", $PUBLIC, $method(ProviderList, getServices, $List*, $String*, $String*)},
	{"getServices", "(Ljava/lang/String;Ljava/util/List;)Ljava/util/List;", "(Ljava/lang/String;Ljava/util/List<Ljava/lang/String;>;)Ljava/util/List<Ljava/security/Provider$Service;>;", $PUBLIC | $DEPRECATED, $method(ProviderList, getServices, $List*, $String*, $List*), nullptr, nullptr, _ProviderList_MethodAnnotations_getServices11},
	{"getServices", "(Ljava/util/List;)Ljava/util/List;", "(Ljava/util/List<Lsun/security/jca/ServiceId;>;)Ljava/util/List<Ljava/security/Provider$Service;>;", $PUBLIC, $method(ProviderList, getServices, $List*, $List*)},
	{"insertAt", "(Lsun/security/jca/ProviderList;Ljava/security/Provider;I)Lsun/security/jca/ProviderList;", nullptr, $PUBLIC | $STATIC, $staticMethod(ProviderList, insertAt, ProviderList*, ProviderList*, $Provider*, int32_t)},
	{"loadAll", "()I", nullptr, $PRIVATE, $method(ProviderList, loadAll, int32_t)},
	{"newList", "([Ljava/security/Provider;)Lsun/security/jca/ProviderList;", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(ProviderList, newList, ProviderList*, $ProviderArray*)},
	{"providers", "()Ljava/util/List;", "()Ljava/util/List<Ljava/security/Provider;>;", $PUBLIC, $method(ProviderList, providers, $List*)},
	{"remove", "(Lsun/security/jca/ProviderList;Ljava/lang/String;)Lsun/security/jca/ProviderList;", nullptr, $PUBLIC | $STATIC, $staticMethod(ProviderList, remove, ProviderList*, ProviderList*, $String*)},
	{"removeInvalid", "()Lsun/security/jca/ProviderList;", nullptr, 0, $method(ProviderList, removeInvalid, ProviderList*)},
	{"size", "()I", nullptr, $PUBLIC, $method(ProviderList, size, int32_t)},
	{"toArray", "()[Ljava/security/Provider;", nullptr, $PUBLIC, $method(ProviderList, toArray, $ProviderArray*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ProviderList, toString, $String*)},
	{}
};

$InnerClassInfo _ProviderList_InnerClassesInfo_[] = {
	{"sun.security.jca.ProviderList$PreferredEntry", "sun.security.jca.ProviderList", "PreferredEntry", $PRIVATE | $STATIC},
	{"sun.security.jca.ProviderList$PreferredList", "sun.security.jca.ProviderList", "PreferredList", $STATIC | $FINAL},
	{"sun.security.jca.ProviderList$ServiceList", "sun.security.jca.ProviderList", "ServiceList", $PRIVATE | $FINAL},
	{"sun.security.jca.ProviderList$3", nullptr, nullptr, 0},
	{"sun.security.jca.ProviderList$2", nullptr, nullptr, 0},
	{"sun.security.jca.ProviderList$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ProviderList_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.jca.ProviderList",
	"java.lang.Object",
	nullptr,
	_ProviderList_FieldInfo_,
	_ProviderList_MethodInfo_,
	nullptr,
	nullptr,
	_ProviderList_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.jca.ProviderList$PreferredEntry,sun.security.jca.ProviderList$PreferredList,sun.security.jca.ProviderList$ServiceList,sun.security.jca.ProviderList$ServiceList$1,sun.security.jca.ProviderList$3,sun.security.jca.ProviderList$2,sun.security.jca.ProviderList$1"
};

$Object* allocate$ProviderList($Class* clazz) {
	return $of($alloc(ProviderList));
}

$Debug* ProviderList::debug = nullptr;
$ProviderConfigArray* ProviderList::PC0 = nullptr;
$ProviderArray* ProviderList::P0 = nullptr;
ProviderList* ProviderList::EMPTY = nullptr;
$ProviderList$PreferredList* ProviderList::preferredPropList = nullptr;
$Provider* ProviderList::EMPTY_PROVIDER = nullptr;
$StringArray* ProviderList::SHA2Group = nullptr;
$StringArray* ProviderList::HmacSHA2Group = nullptr;
$StringArray* ProviderList::SHA2RSAGroup = nullptr;
$StringArray* ProviderList::SHA2DSAGroup = nullptr;
$StringArray* ProviderList::SHA2ECDSAGroup = nullptr;
$StringArray* ProviderList::SHA3Group = nullptr;
$StringArray* ProviderList::HmacSHA3Group = nullptr;

ProviderList* ProviderList::fromSecurityProperties() {
	$init(ProviderList);
	$beforeCallerSensitive();
	return $cast(ProviderList, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($ProviderList$2))));
}

ProviderList* ProviderList::add(ProviderList* providerList, $Provider* p) {
	$init(ProviderList);
	return insertAt(providerList, p, -1);
}

ProviderList* ProviderList::insertAt(ProviderList* providerList, $Provider* p, int32_t position) {
	$init(ProviderList);
	$useLocalCurrentObjectStackCache();
	if ($nc(providerList)->getProvider($($nc(p)->getName())) != nullptr) {
		return providerList;
	}
	$var($List, list, $new($ArrayList, $(static_cast<$Collection*>($Arrays::asList($nc(providerList)->configs)))));
	int32_t n = list->size();
	if ((position < 0) || (position > n)) {
		position = n;
	}
	list->add(position, $$new($ProviderConfig, p));
	return $new(ProviderList, $fcast($ProviderConfigArray, $(list->toArray(ProviderList::PC0))), true);
}

ProviderList* ProviderList::remove(ProviderList* providerList, $String* name) {
	$init(ProviderList);
	$useLocalCurrentObjectStackCache();
	if ($nc(providerList)->getProvider(name) == nullptr) {
		return providerList;
	}
	$var($ProviderConfigArray, configs, $new($ProviderConfigArray, $nc(providerList)->size() - 1));
	int32_t j = 0;
	{
		$var($ProviderConfigArray, arr$, providerList->configs);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($ProviderConfig, config, arr$->get(i$));
			{
				if ($nc($($nc($($nc(config)->getProvider()))->getName()))->equals(name) == false) {
					configs->set(j++, config);
				}
			}
		}
	}
	return $new(ProviderList, configs, true);
}

ProviderList* ProviderList::newList($ProviderArray* providers) {
	$init(ProviderList);
	$useLocalCurrentObjectStackCache();
	$var($ProviderConfigArray, configs, $new($ProviderConfigArray, $nc(providers)->length));
	for (int32_t i = 0; i < providers->length; ++i) {
		configs->set(i, $$new($ProviderConfig, providers->get(i)));
	}
	return $new(ProviderList, configs, true);
}

void ProviderList::init$($ProviderConfigArray* configs, bool allLoaded) {
	$set(this, userList, $new($ProviderList$3, this));
	$set(this, configs, configs);
	this->allLoaded = allLoaded;
}

void ProviderList::init$() {
	$useLocalCurrentObjectStackCache();
	$set(this, userList, $new($ProviderList$3, this));
	$var($List, configList, $new($ArrayList));
	$var($String, entry, nullptr);
	int32_t i = 1;
	while (($assign(entry, $Security::getProperty($$str({"security.provider."_s, $$str(i)})))) != nullptr) {
		$assign(entry, $nc(entry)->trim());
		if (entry->isEmpty()) {
			$nc($System::err)->println($$str({"invalid entry for security.provider."_s, $$str(i)}));
			break;
		}
		int32_t k = entry->indexOf((int32_t)u' ');
		$var($ProviderConfig, config, nullptr);
		if (k == -1) {
			$assign(config, $new($ProviderConfig, entry));
		} else {
			$var($String, provName, entry->substring(0, k));
			$var($String, argument, $(entry->substring(k + 1))->trim());
			$assign(config, $new($ProviderConfig, provName, argument));
		}
		if (configList->contains(config) == false) {
			configList->add(config);
		}
		++i;
	}
	$set(this, configs, $fcast($ProviderConfigArray, configList->toArray(ProviderList::PC0)));
	$assign(entry, $Security::getProperty("jdk.security.provider.preferred"_s));
	if (entry != nullptr && !$nc(($assign(entry, entry->trim())))->isEmpty()) {
		$var($StringArray, entries, entry->split(","_s));
		if (ProviderList::preferredPropList == nullptr) {
			$assignStatic(ProviderList::preferredPropList, $new($ProviderList$PreferredList));
		}
		{
			$var($StringArray, arr$, entries);
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($String, e, arr$->get(i$));
				{
					i = $nc(e)->indexOf((int32_t)u':');
					if (i < 0) {
						if (ProviderList::debug != nullptr) {
							$nc(ProviderList::debug)->println($$str({"invalid preferred entry skipped.  Missing colon delimiter \""_s, e, "\""_s}));
						}
						continue;
					}
					$var($String, var$0, $(e->substring(0, i))->trim());
					$nc(ProviderList::preferredPropList)->add($$new($ProviderList$PreferredEntry, var$0, $($(e->substring(i + 1))->trim())));
				}
			}
		}
	}
	if (ProviderList::debug != nullptr) {
		$nc(ProviderList::debug)->println($$str({"provider configuration: "_s, configList}));
		$nc(ProviderList::debug)->println($$str({"config configuration: "_s, ProviderList::preferredPropList}));
	}
}

ProviderList* ProviderList::getJarList($StringArray* jarProvNames) {
	$useLocalCurrentObjectStackCache();
	$var($List, newConfigs, $new($ArrayList));
	{
		$var($StringArray, arr$, jarProvNames);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, provName, arr$->get(i$));
			{
				$var($ProviderConfig, newConfig, $new($ProviderConfig, provName));
				{
					$var($ProviderConfigArray, arr$, this->configs);
					int32_t len$ = arr$->length;
					int32_t i$ = 0;
					for (; i$ < len$; ++i$) {
						$var($ProviderConfig, config, arr$->get(i$));
						{
							if ($nc(config)->equals(newConfig)) {
								$assign(newConfig, config);
								break;
							}
						}
					}
				}
				newConfigs->add(newConfig);
			}
		}
	}
	$var($ProviderConfigArray, configArray, $fcast($ProviderConfigArray, newConfigs->toArray(ProviderList::PC0)));
	return $new(ProviderList, configArray, false);
}

int32_t ProviderList::size() {
	return $nc(this->configs)->length;
}

$Provider* ProviderList::getProvider(int32_t index) {
	$var($Provider, p, $nc($nc(this->configs)->get(index))->getProvider());
	return (p != nullptr) ? p : ProviderList::EMPTY_PROVIDER;
}

$List* ProviderList::providers() {
	return this->userList;
}

$ProviderConfig* ProviderList::getProviderConfig($String* name) {
	int32_t index = getIndex(name);
	return (index != -1) ? $nc(this->configs)->get(index) : ($ProviderConfig*)nullptr;
}

$Provider* ProviderList::getProvider($String* name) {
	$var($ProviderConfig, config, getProviderConfig(name));
	return (config == nullptr) ? ($Provider*)nullptr : $nc(config)->getProvider();
}

int32_t ProviderList::getIndex($String* name) {
	$useLocalCurrentObjectStackCache();
	for (int32_t i = 0; i < $nc(this->configs)->length; ++i) {
		$var($Provider, p, getProvider(i));
		if ($nc($($nc(p)->getName()))->equals(name)) {
			return i;
		}
	}
	return -1;
}

int32_t ProviderList::loadAll() {
	$useLocalCurrentObjectStackCache();
	if (this->allLoaded) {
		return $nc(this->configs)->length;
	}
	if (ProviderList::debug != nullptr) {
		$nc(ProviderList::debug)->println("Loading all providers"_s);
		$$new($Exception, "Debug Info. Call trace:"_s)->printStackTrace();
	}
	int32_t n = 0;
	for (int32_t i = 0; i < $nc(this->configs)->length; ++i) {
		$var($Provider, p, $nc($nc(this->configs)->get(i))->getProvider());
		if (p != nullptr) {
			++n;
		}
	}
	if (n == $nc(this->configs)->length) {
		this->allLoaded = true;
	}
	return n;
}

ProviderList* ProviderList::removeInvalid() {
	$useLocalCurrentObjectStackCache();
	int32_t n = loadAll();
	if (n == $nc(this->configs)->length) {
		return this;
	}
	$var($ProviderConfigArray, newConfigs, $new($ProviderConfigArray, n));
	{
		int32_t i = 0;
		int32_t j = 0;
		for (; i < $nc(this->configs)->length; ++i) {
			$var($ProviderConfig, config, $nc(this->configs)->get(i));
			if ($nc(config)->isLoaded()) {
				newConfigs->set(j++, config);
			}
		}
	}
	return $new(ProviderList, newConfigs, true);
}

$ProviderArray* ProviderList::toArray() {
	return $fcast($ProviderArray, $nc($(providers()))->toArray(ProviderList::P0));
}

$String* ProviderList::toString() {
	return $nc($of($($Arrays::asList(this->configs))))->toString();
}

$Provider$Service* ProviderList::getService($String* type, $String* name) {
	$useLocalCurrentObjectStackCache();
	$var($ArrayList, pList, nullptr);
	int32_t i = 0;
	if (ProviderList::preferredPropList != nullptr && ($assign(pList, $nc(ProviderList::preferredPropList)->getAll(type, name))) != nullptr) {
		for (i = 0; i < $nc(pList)->size(); ++i) {
			$var($Provider, p, getProvider($nc(($cast($ProviderList$PreferredEntry, $(pList->get(i)))))->provider));
			$var($Provider$Service, s, $nc(p)->getService(type, name));
			if (s != nullptr) {
				return s;
			}
		}
	}
	for (i = 0; i < $nc(this->configs)->length; ++i) {
		$var($Provider, p, getProvider(i));
		$var($Provider$Service, s, $nc(p)->getService(type, name));
		if (s != nullptr) {
			return s;
		}
	}
	return nullptr;
}

$List* ProviderList::getServices($String* type, $String* algorithm) {
	return $new($ProviderList$ServiceList, this, type, algorithm);
}

$List* ProviderList::getServices($String* type, $List* algorithms) {
	$useLocalCurrentObjectStackCache();
	$var($List, ids, $new($ArrayList));
	{
		$var($Iterator, i$, $nc(algorithms)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, alg, $cast($String, i$->next()));
			{
				ids->add($$new($ServiceId, type, alg));
			}
		}
	}
	return getServices(ids);
}

$List* ProviderList::getServices($List* ids) {
	return $new($ProviderList$ServiceList, this, ids);
}

void clinit$ProviderList($Class* class$) {
	$assignStatic(ProviderList::debug, $Debug::getInstance("jca"_s, "ProviderList"_s));
	$assignStatic(ProviderList::PC0, $new($ProviderConfigArray, 0));
	$assignStatic(ProviderList::P0, $new($ProviderArray, 0));
	$assignStatic(ProviderList::EMPTY, $new(ProviderList, ProviderList::PC0, true));
	$assignStatic(ProviderList::preferredPropList, nullptr);
	$assignStatic(ProviderList::EMPTY_PROVIDER, $new($ProviderList$1, "##Empty##"_s, "1.0"_s, "initialization in progress"_s));
	$assignStatic(ProviderList::SHA2Group, $new($StringArray, {
		"SHA-224"_s,
		"SHA-256"_s,
		"SHA-384"_s,
		"SHA-512"_s,
		"SHA-512/224"_s,
		"SHA-512/256"_s
	}));
	$assignStatic(ProviderList::HmacSHA2Group, $new($StringArray, {
		"HmacSHA224"_s,
		"HmacSHA256"_s,
		"HmacSHA384"_s,
		"HmacSHA512"_s
	}));
	$assignStatic(ProviderList::SHA2RSAGroup, $new($StringArray, {
		"SHA224withRSA"_s,
		"SHA256withRSA"_s,
		"SHA384withRSA"_s,
		"SHA512withRSA"_s
	}));
	$assignStatic(ProviderList::SHA2DSAGroup, $new($StringArray, {
		"SHA224withDSA"_s,
		"SHA256withDSA"_s,
		"SHA384withDSA"_s,
		"SHA512withDSA"_s
	}));
	$assignStatic(ProviderList::SHA2ECDSAGroup, $new($StringArray, {
		"SHA224withECDSA"_s,
		"SHA256withECDSA"_s,
		"SHA384withECDSA"_s,
		"SHA512withECDSA"_s
	}));
	$assignStatic(ProviderList::SHA3Group, $new($StringArray, {
		"SHA3-224"_s,
		"SHA3-256"_s,
		"SHA3-384"_s,
		"SHA3-512"_s
	}));
	$assignStatic(ProviderList::HmacSHA3Group, $new($StringArray, {
		"HmacSHA3-224"_s,
		"HmacSHA3-256"_s,
		"HmacSHA3-384"_s,
		"HmacSHA3-512"_s
	}));
}

ProviderList::ProviderList() {
}

$Class* ProviderList::load$($String* name, bool initialize) {
	$loadClass(ProviderList, name, initialize, &_ProviderList_ClassInfo_, clinit$ProviderList, allocate$ProviderList);
	return class$;
}

$Class* ProviderList::class$ = nullptr;

		} // jca
	} // security
} // sun