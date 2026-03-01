#include <java/net/InetAddress.h>

#include <java/io/InvalidObjectException.h>
#include <java/io/ObjectInputStream$GetField.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream$PutField.h>
#include <java/io/ObjectOutputStream.h>
#include <java/io/ObjectStreamField.h>
#include <java/lang/CharSequence.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/Error.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/InstantiationException.h>
#include <java/lang/SecurityException.h>
#include <java/lang/SecurityManager.h>
#include <java/net/Inet4Address.h>
#include <java/net/Inet6Address.h>
#include <java/net/InetAddress$1.h>
#include <java/net/InetAddress$Addresses.h>
#include <java/net/InetAddress$CachedAddresses.h>
#include <java/net/InetAddress$CachedLocalHost.h>
#include <java/net/InetAddress$HostsFileNameService.h>
#include <java/net/InetAddress$InetAddressHolder.h>
#include <java/net/InetAddress$NameService.h>
#include <java/net/InetAddress$NameServiceAddresses.h>
#include <java/net/InetAddress$PlatformNameService.h>
#include <java/net/InetAddressImpl.h>
#include <java/net/InetAddressImplFactory.h>
#include <java/net/NetworkInterface.h>
#include <java/net/UnknownHostException.h>
#include <java/util/Iterator.h>
#include <java/util/NavigableSet.h>
#include <java/util/Objects.h>
#include <java/util/Set.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/concurrent/ConcurrentMap.h>
#include <java/util/concurrent/ConcurrentSkipListSet.h>
#include <jdk/internal/access/JavaNetInetAddressAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jdk/internal/loader/BootLoader.h>
#include <jdk/internal/misc/Unsafe.h>
#include <sun/net/util/IPAddressUtil.h>
#include <sun/security/action/GetPropertyAction.h>
#include <jcpp.h>

#undef FIELDS_OFFSET
#undef INADDRSZ
#undef PREFER_IPV4_VALUE
#undef PREFER_IPV6_VALUE
#undef PREFER_SYSTEM_VALUE
#undef TYPE
#undef UNSAFE

using $ObjectStreamFieldArray = $Array<::java::io::ObjectStreamField>;
using $InetAddressArray = $Array<::java::net::InetAddress>;
using $InvalidObjectException = ::java::io::InvalidObjectException;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectInputStream$GetField = ::java::io::ObjectInputStream$GetField;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $ObjectOutputStream$PutField = ::java::io::ObjectOutputStream$PutField;
using $ObjectStreamField = ::java::io::ObjectStreamField;
using $PrintStream = ::java::io::PrintStream;
using $CharSequence = ::java::lang::CharSequence;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $Error = ::java::lang::Error;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InstantiationException = ::java::lang::InstantiationException;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $SecurityException = ::java::lang::SecurityException;
using $SecurityManager = ::java::lang::SecurityManager;
using $Inet4Address = ::java::net::Inet4Address;
using $Inet6Address = ::java::net::Inet6Address;
using $InetAddress$1 = ::java::net::InetAddress$1;
using $InetAddress$Addresses = ::java::net::InetAddress$Addresses;
using $InetAddress$CachedAddresses = ::java::net::InetAddress$CachedAddresses;
using $InetAddress$CachedLocalHost = ::java::net::InetAddress$CachedLocalHost;
using $InetAddress$HostsFileNameService = ::java::net::InetAddress$HostsFileNameService;
using $InetAddress$InetAddressHolder = ::java::net::InetAddress$InetAddressHolder;
using $InetAddress$NameService = ::java::net::InetAddress$NameService;
using $InetAddress$NameServiceAddresses = ::java::net::InetAddress$NameServiceAddresses;
using $InetAddress$PlatformNameService = ::java::net::InetAddress$PlatformNameService;
using $InetAddressImpl = ::java::net::InetAddressImpl;
using $InetAddressImplFactory = ::java::net::InetAddressImplFactory;
using $NetworkInterface = ::java::net::NetworkInterface;
using $UnknownHostException = ::java::net::UnknownHostException;
using $Iterator = ::java::util::Iterator;
using $NavigableSet = ::java::util::NavigableSet;
using $Objects = ::java::util::Objects;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $ConcurrentMap = ::java::util::concurrent::ConcurrentMap;
using $ConcurrentSkipListSet = ::java::util::concurrent::ConcurrentSkipListSet;
using $JavaNetInetAddressAccess = ::jdk::internal::access::JavaNetInetAddressAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $BootLoader = ::jdk::internal::loader::BootLoader;
using $Unsafe = ::jdk::internal::misc::Unsafe;
using $IPAddressUtil = ::sun::net::util::IPAddressUtil;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;

namespace java {
	namespace net {

$FieldInfo _InetAddress_FieldInfo_[] = {
	{"PREFER_IPV4_VALUE", "I", nullptr, $STATIC | $FINAL, $constField(InetAddress, PREFER_IPV4_VALUE)},
	{"PREFER_IPV6_VALUE", "I", nullptr, $STATIC | $FINAL, $constField(InetAddress, PREFER_IPV6_VALUE)},
	{"PREFER_SYSTEM_VALUE", "I", nullptr, $STATIC | $FINAL, $constField(InetAddress, PREFER_SYSTEM_VALUE)},
	{"IPv4", "I", nullptr, $STATIC | $FINAL, $constField(InetAddress, IPv4)},
	{"IPv6", "I", nullptr, $STATIC | $FINAL, $constField(InetAddress, IPv6)},
	{"preferIPv6Address", "I", nullptr, $STATIC | $FINAL | $TRANSIENT, $staticField(InetAddress, preferIPv6Address)},
	{"holder", "Ljava/net/InetAddress$InetAddressHolder;", nullptr, $FINAL | $TRANSIENT, $field(InetAddress, holder$)},
	{"nameService", "Ljava/net/InetAddress$NameService;", nullptr, $PRIVATE | $STATIC | $TRANSIENT, $staticField(InetAddress, nameService)},
	{"canonicalHostName", "Ljava/lang/String;", nullptr, $PRIVATE | $TRANSIENT, $field(InetAddress, canonicalHostName)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(InetAddress, serialVersionUID)},
	{"cache", "Ljava/util/concurrent/ConcurrentMap;", "Ljava/util/concurrent/ConcurrentMap<Ljava/lang/String;Ljava/net/InetAddress$Addresses;>;", $PRIVATE | $STATIC | $FINAL, $staticField(InetAddress, cache)},
	{"expirySet", "Ljava/util/NavigableSet;", "Ljava/util/NavigableSet<Ljava/net/InetAddress$CachedAddresses;>;", $PRIVATE | $STATIC | $FINAL, $staticField(InetAddress, expirySet)},
	{"impl", "Ljava/net/InetAddressImpl;", nullptr, $STATIC | $FINAL, $staticField(InetAddress, impl)},
	{"cachedLocalHost", "Ljava/net/InetAddress$CachedLocalHost;", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(InetAddress, cachedLocalHost)},
	{"UNSAFE", "Ljdk/internal/misc/Unsafe;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InetAddress, UNSAFE)},
	{"FIELDS_OFFSET", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InetAddress, FIELDS_OFFSET)},
	{"serialPersistentFields", "[Ljava/io/ObjectStreamField;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InetAddress, serialPersistentFields)},
	{}
};

$MethodInfo _InetAddress_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(InetAddress, init$, void)},
	{"anyLocalAddress", "()Ljava/net/InetAddress;", nullptr, $STATIC, $staticMethod(InetAddress, anyLocalAddress, InetAddress*)},
	{"checkNumericZone", "(Ljava/lang/String;)I", nullptr, $PRIVATE | $STATIC, $staticMethod(InetAddress, checkNumericZone, int32_t, $String*), "java.net.UnknownHostException"},
	{"createNameService", "()Ljava/net/InetAddress$NameService;", nullptr, $PRIVATE | $STATIC, $staticMethod(InetAddress, createNameService, $InetAddress$NameService*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(InetAddress, equals, bool, Object$*)},
	{"getAddress", "()[B", nullptr, $PUBLIC, $virtualMethod(InetAddress, getAddress, $bytes*)},
	{"getAddressesFromNameService", "(Ljava/lang/String;Ljava/net/InetAddress;)[Ljava/net/InetAddress;", nullptr, $STATIC, $staticMethod(InetAddress, getAddressesFromNameService, $InetAddressArray*, $String*, InetAddress*), "java.net.UnknownHostException"},
	{"getAllByName", "(Ljava/lang/String;)[Ljava/net/InetAddress;", nullptr, $PUBLIC | $STATIC, $staticMethod(InetAddress, getAllByName, $InetAddressArray*, $String*), "java.net.UnknownHostException"},
	{"getAllByName", "(Ljava/lang/String;Ljava/net/InetAddress;)[Ljava/net/InetAddress;", nullptr, $PRIVATE | $STATIC, $staticMethod(InetAddress, getAllByName, $InetAddressArray*, $String*, InetAddress*), "java.net.UnknownHostException"},
	{"getAllByName0", "(Ljava/lang/String;)[Ljava/net/InetAddress;", nullptr, $PRIVATE | $STATIC, $staticMethod(InetAddress, getAllByName0, $InetAddressArray*, $String*), "java.net.UnknownHostException"},
	{"getAllByName0", "(Ljava/lang/String;Z)[Ljava/net/InetAddress;", nullptr, $STATIC, $staticMethod(InetAddress, getAllByName0, $InetAddressArray*, $String*, bool), "java.net.UnknownHostException"},
	{"getAllByName0", "(Ljava/lang/String;Ljava/net/InetAddress;ZZ)[Ljava/net/InetAddress;", nullptr, $PRIVATE | $STATIC, $staticMethod(InetAddress, getAllByName0, $InetAddressArray*, $String*, InetAddress*, bool, bool), "java.net.UnknownHostException"},
	{"getByAddress", "(Ljava/lang/String;[B)Ljava/net/InetAddress;", nullptr, $PUBLIC | $STATIC, $staticMethod(InetAddress, getByAddress, InetAddress*, $String*, $bytes*), "java.net.UnknownHostException"},
	{"getByAddress", "([B)Ljava/net/InetAddress;", nullptr, $PUBLIC | $STATIC, $staticMethod(InetAddress, getByAddress, InetAddress*, $bytes*), "java.net.UnknownHostException"},
	{"getByName", "(Ljava/lang/String;)Ljava/net/InetAddress;", nullptr, $PUBLIC | $STATIC, $staticMethod(InetAddress, getByName, InetAddress*, $String*), "java.net.UnknownHostException"},
	{"getByName", "(Ljava/lang/String;Ljava/net/InetAddress;)Ljava/net/InetAddress;", nullptr, $PRIVATE | $STATIC, $staticMethod(InetAddress, getByName, InetAddress*, $String*, InetAddress*), "java.net.UnknownHostException"},
	{"getCanonicalHostName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(InetAddress, getCanonicalHostName, $String*)},
	{"getHostAddress", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(InetAddress, getHostAddress, $String*)},
	{"getHostFromNameService", "(Ljava/net/InetAddress;Z)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(InetAddress, getHostFromNameService, $String*, InetAddress*, bool)},
	{"getHostName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(InetAddress, getHostName, $String*)},
	{"getHostName", "(Z)Ljava/lang/String;", nullptr, 0, $virtualMethod(InetAddress, getHostName, $String*, bool)},
	{"getLocalHost", "()Ljava/net/InetAddress;", nullptr, $PUBLIC | $STATIC, $staticMethod(InetAddress, getLocalHost, InetAddress*), "java.net.UnknownHostException"},
	{"getLoopbackAddress", "()Ljava/net/InetAddress;", nullptr, $PUBLIC | $STATIC, $staticMethod(InetAddress, getLoopbackAddress, InetAddress*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(InetAddress, hashCode, int32_t)},
	{"holder", "()Ljava/net/InetAddress$InetAddressHolder;", nullptr, 0, $virtualMethod(InetAddress, holder, $InetAddress$InetAddressHolder*)},
	{"init", "()V", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(InetAddress, init, void)},
	{"isAnyLocalAddress", "()Z", nullptr, $PUBLIC, $virtualMethod(InetAddress, isAnyLocalAddress, bool)},
	{"isLinkLocalAddress", "()Z", nullptr, $PUBLIC, $virtualMethod(InetAddress, isLinkLocalAddress, bool)},
	{"isLoopbackAddress", "()Z", nullptr, $PUBLIC, $virtualMethod(InetAddress, isLoopbackAddress, bool)},
	{"isMCGlobal", "()Z", nullptr, $PUBLIC, $virtualMethod(InetAddress, isMCGlobal, bool)},
	{"isMCLinkLocal", "()Z", nullptr, $PUBLIC, $virtualMethod(InetAddress, isMCLinkLocal, bool)},
	{"isMCNodeLocal", "()Z", nullptr, $PUBLIC, $virtualMethod(InetAddress, isMCNodeLocal, bool)},
	{"isMCOrgLocal", "()Z", nullptr, $PUBLIC, $virtualMethod(InetAddress, isMCOrgLocal, bool)},
	{"isMCSiteLocal", "()Z", nullptr, $PUBLIC, $virtualMethod(InetAddress, isMCSiteLocal, bool)},
	{"isMulticastAddress", "()Z", nullptr, $PUBLIC, $virtualMethod(InetAddress, isMulticastAddress, bool)},
	{"isReachable", "(I)Z", nullptr, $PUBLIC, $virtualMethod(InetAddress, isReachable, bool, int32_t), "java.io.IOException"},
	{"isReachable", "(Ljava/net/NetworkInterface;II)Z", nullptr, $PUBLIC, $virtualMethod(InetAddress, isReachable, bool, $NetworkInterface*, int32_t, int32_t), "java.io.IOException"},
	{"isSiteLocalAddress", "()Z", nullptr, $PUBLIC, $virtualMethod(InetAddress, isSiteLocalAddress, bool)},
	{"loadImpl", "(Ljava/lang/String;)Ljava/net/InetAddressImpl;", nullptr, $STATIC, $staticMethod(InetAddress, loadImpl, $InetAddressImpl*, $String*)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(InetAddress, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"readObjectNoData", "()V", nullptr, $PRIVATE, $method(InetAddress, readObjectNoData, void)},
	{"readResolve", "()Ljava/lang/Object;", nullptr, $PRIVATE, $method(InetAddress, readResolve, $Object*), "java.io.ObjectStreamException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(InetAddress, toString, $String*)},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE, $method(InetAddress, writeObject, void, $ObjectOutputStream*), "java.io.IOException"},
	{}
};

#define _METHOD_INDEX_init 25

$InnerClassInfo _InetAddress_InnerClassesInfo_[] = {
	{"java.net.InetAddress$CachedLocalHost", "java.net.InetAddress", "CachedLocalHost", $PRIVATE | $STATIC | $FINAL},
	{"java.net.InetAddress$HostsFileNameService", "java.net.InetAddress", "HostsFileNameService", $PRIVATE | $STATIC | $FINAL},
	{"java.net.InetAddress$PlatformNameService", "java.net.InetAddress", "PlatformNameService", $PRIVATE | $STATIC | $FINAL},
	{"java.net.InetAddress$NameService", "java.net.InetAddress", "NameService", $PRIVATE | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.net.InetAddress$NameServiceAddresses", "java.net.InetAddress", "NameServiceAddresses", $PRIVATE | $STATIC | $FINAL},
	{"java.net.InetAddress$CachedAddresses", "java.net.InetAddress", "CachedAddresses", $PRIVATE | $STATIC | $FINAL},
	{"java.net.InetAddress$Addresses", "java.net.InetAddress", "Addresses", $PRIVATE | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.net.InetAddress$InetAddressHolder", "java.net.InetAddress", "InetAddressHolder", $STATIC},
	{"java.net.InetAddress$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _InetAddress_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.net.InetAddress",
	"java.lang.Object",
	"java.io.Serializable",
	_InetAddress_FieldInfo_,
	_InetAddress_MethodInfo_,
	nullptr,
	nullptr,
	_InetAddress_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.net.InetAddress$CachedLocalHost,java.net.InetAddress$HostsFileNameService,java.net.InetAddress$PlatformNameService,java.net.InetAddress$NameService,java.net.InetAddress$NameServiceAddresses,java.net.InetAddress$CachedAddresses,java.net.InetAddress$Addresses,java.net.InetAddress$InetAddressHolder,java.net.InetAddress$1"
};

$Object* allocate$InetAddress($Class* clazz) {
	return $of($alloc(InetAddress));
}

int32_t InetAddress::preferIPv6Address = 0;
$InetAddress$NameService* InetAddress::nameService = nullptr;
$ConcurrentMap* InetAddress::cache = nullptr;
$NavigableSet* InetAddress::expirySet = nullptr;
$InetAddressImpl* InetAddress::impl = nullptr;
$volatile($InetAddress$CachedLocalHost*) InetAddress::cachedLocalHost = nullptr;
$Unsafe* InetAddress::UNSAFE = nullptr;
int64_t InetAddress::FIELDS_OFFSET = 0;
$ObjectStreamFieldArray* InetAddress::serialPersistentFields = nullptr;

$InetAddress$InetAddressHolder* InetAddress::holder() {
	return this->holder$;
}

void InetAddress::init$() {
	$set(this, canonicalHostName, nullptr);
	$set(this, holder$, $new($InetAddress$InetAddressHolder));
}

$Object* InetAddress::readResolve() {
	$useLocalCurrentObjectStackCache();
	$var($String, var$0, $nc($(holder()))->getHostName());
	return $of($new($Inet4Address, var$0, $nc($(holder()))->getAddress()));
}

bool InetAddress::isMulticastAddress() {
	return false;
}

bool InetAddress::isAnyLocalAddress() {
	return false;
}

bool InetAddress::isLoopbackAddress() {
	return false;
}

bool InetAddress::isLinkLocalAddress() {
	return false;
}

bool InetAddress::isSiteLocalAddress() {
	return false;
}

bool InetAddress::isMCGlobal() {
	return false;
}

bool InetAddress::isMCNodeLocal() {
	return false;
}

bool InetAddress::isMCLinkLocal() {
	return false;
}

bool InetAddress::isMCSiteLocal() {
	return false;
}

bool InetAddress::isMCOrgLocal() {
	return false;
}

bool InetAddress::isReachable(int32_t timeout) {
	return isReachable(nullptr, 0, timeout);
}

bool InetAddress::isReachable($NetworkInterface* netif, int32_t ttl, int32_t timeout) {
	if (ttl < 0) {
		$throwNew($IllegalArgumentException, "ttl can\'t be negative"_s);
	}
	if (timeout < 0) {
		$throwNew($IllegalArgumentException, "timeout can\'t be negative"_s);
	}
	return $nc(InetAddress::impl)->isReachable(this, timeout, netif, ttl);
}

$String* InetAddress::getHostName() {
	return getHostName(true);
}

$String* InetAddress::getHostName(bool check) {
	$useLocalCurrentObjectStackCache();
	if ($nc($(holder()))->getHostName() == nullptr) {
		$set($nc($(holder())), hostName, InetAddress::getHostFromNameService(this, check));
	}
	return $nc($(holder()))->getHostName();
}

$String* InetAddress::getCanonicalHostName() {
	$var($String, value, this->canonicalHostName);
	if (value == nullptr) {
		$set(this, canonicalHostName, ($assign(value, InetAddress::getHostFromNameService(this, true))));
	}
	return value;
}

$String* InetAddress::getHostFromNameService(InetAddress* addr, bool check) {
	$init(InetAddress);
	$useLocalCurrentObjectStackCache();
	$var($String, host, nullptr);
	try {
		$assign(host, $nc(InetAddress::nameService)->getHostByAddr($($nc(addr)->getAddress())));
		if (check) {
			$var($SecurityManager, sec, $System::getSecurityManager());
			if (sec != nullptr) {
				sec->checkConnect(host, -1);
			}
		}
		$var($InetAddressArray, arr, InetAddress::getAllByName0(host, check));
		bool ok = false;
		if (arr != nullptr) {
			for (int32_t i = 0; !ok && i < arr->length; ++i) {
				ok = $nc(addr)->equals(arr->get(i));
			}
		}
		if (!ok) {
			$assign(host, $nc(addr)->getHostAddress());
			return host;
		}
	} catch ($SecurityException& e) {
		$assign(host, $nc(addr)->getHostAddress());
	} catch ($UnknownHostException& e) {
		$assign(host, $nc(addr)->getHostAddress());
	}
	return host;
}

$bytes* InetAddress::getAddress() {
	return nullptr;
}

$String* InetAddress::getHostAddress() {
	return nullptr;
}

int32_t InetAddress::hashCode() {
	return -1;
}

bool InetAddress::equals(Object$* obj) {
	return false;
}

$String* InetAddress::toString() {
	$useLocalCurrentObjectStackCache();
	$var($String, hostName, $nc($(holder()))->getHostName());
	$var($String, var$0, $$str({$($Objects::toString(hostName, ""_s)), "/"_s}));
	return $concat(var$0, $(getHostAddress()));
}

$InetAddress$NameService* InetAddress::createNameService() {
	$init(InetAddress);
	$useLocalCurrentObjectStackCache();
	$var($String, hostsFileName, $GetPropertyAction::privilegedGetProperty("jdk.net.hosts.file"_s));
	$var($InetAddress$NameService, theNameService, nullptr);
	if (hostsFileName != nullptr) {
		$assign(theNameService, $new($InetAddress$HostsFileNameService, hostsFileName));
	} else {
		$assign(theNameService, $new($InetAddress$PlatformNameService));
	}
	return theNameService;
}

InetAddress* InetAddress::getByAddress($String* host$renamed, $bytes* addr) {
	$init(InetAddress);
	$useLocalCurrentObjectStackCache();
	$var($String, host, host$renamed);
	bool var$0 = host != nullptr && !host->isEmpty();
	if (var$0 && host->charAt(0) == u'[') {
		if (host->charAt(host->length() - 1) == u']') {
			$assign(host, host->substring(1, host->length() - 1));
		}
	}
	if (addr != nullptr) {
		if (addr->length == $Inet4Address::INADDRSZ) {
			return $new($Inet4Address, host, addr);
		} else if (addr->length == $Inet6Address::INADDRSZ) {
			$var($bytes, newAddr, $IPAddressUtil::convertFromIPv4MappedAddress(addr));
			if (newAddr != nullptr) {
				return $new($Inet4Address, host, newAddr);
			} else {
				return $new($Inet6Address, host, addr);
			}
		}
	}
	$throwNew($UnknownHostException, "addr is of illegal length"_s);
}

InetAddress* InetAddress::getByName($String* host) {
	$init(InetAddress);
	return $nc($(InetAddress::getAllByName(host)))->get(0);
}

InetAddress* InetAddress::getByName($String* host, InetAddress* reqAddr) {
	$init(InetAddress);
	return $nc($(InetAddress::getAllByName(host, reqAddr)))->get(0);
}

$InetAddressArray* InetAddress::getAllByName($String* host) {
	$init(InetAddress);
	return getAllByName(host, nullptr);
}

$InetAddressArray* InetAddress::getAllByName($String* host$renamed, InetAddress* reqAddr) {
	$init(InetAddress);
	$useLocalCurrentObjectStackCache();
	$var($String, host, host$renamed);
	if (host == nullptr || $nc(host)->isEmpty()) {
		$var($InetAddressArray, ret, $new($InetAddressArray, 1));
		ret->set(0, $($nc(InetAddress::impl)->loopbackAddress()));
		return ret;
	}
	bool ipv6Expected = false;
	if ($nc(host)->charAt(0) == u'[') {
		bool var$0 = host->length() > 2;
		if (var$0 && host->charAt(host->length() - 1) == u']') {
			$assign(host, host->substring(1, host->length() - 1));
			ipv6Expected = true;
		} else {
			$throwNew($UnknownHostException, $$str({host, ": invalid IPv6 address"_s}));
		}
	}
	bool var$1 = $Character::digit($nc(host)->charAt(0), 16) != -1;
	if (var$1 || ($nc(host)->charAt(0) == u':')) {
		$var($bytes, addr, nullptr);
		int32_t numericZone = -1;
		$var($String, ifname, nullptr);
		$assign(addr, $IPAddressUtil::textToNumericFormatV4(host));
		if (addr == nullptr) {
			int32_t pos = 0;
			if ((pos = host->indexOf((int32_t)u'%')) != -1) {
				numericZone = checkNumericZone(host);
				if (numericZone == -1) {
					$assign(ifname, host->substring(pos + 1));
				}
			}
			bool var$2 = ($assign(addr, $IPAddressUtil::textToNumericFormatV6(host))) == nullptr;
			if (var$2 && host->contains(":"_s)) {
				$throwNew($UnknownHostException, $$str({host, ": invalid IPv6 address"_s}));
			}
		} else if (ipv6Expected) {
			$throwNew($UnknownHostException, $$str({"["_s, host, "]"_s}));
		}
		$var($InetAddressArray, ret, $new($InetAddressArray, 1));
		if (addr != nullptr) {
			if (addr->length == $Inet4Address::INADDRSZ) {
				ret->set(0, $$new($Inet4Address, ($String*)nullptr, addr));
			} else if (ifname != nullptr) {
				ret->set(0, $$new($Inet6Address, ($String*)nullptr, addr, ifname));
			} else {
				ret->set(0, $$new($Inet6Address, ($String*)nullptr, addr, numericZone));
			}
			return ret;
		}
	} else if (ipv6Expected) {
		$throwNew($UnknownHostException, $$str({"["_s, host, "]"_s}));
	}
	return getAllByName0(host, reqAddr, true, true);
}

InetAddress* InetAddress::getLoopbackAddress() {
	$init(InetAddress);
	return $nc(InetAddress::impl)->loopbackAddress();
}

int32_t InetAddress::checkNumericZone($String* s) {
	$init(InetAddress);
	int32_t percent = $nc(s)->indexOf((int32_t)u'%');
	int32_t slen = s->length();
	int32_t digit = 0;
	int32_t zone = 0;
	if (percent == -1) {
		return -1;
	}
	for (int32_t i = percent + 1; i < slen; ++i) {
		char16_t c = s->charAt(i);
		if (c == u']') {
			if (i == percent + 1) {
				return -1;
			}
			break;
		}
		if ((digit = $Character::digit(c, 10)) < 0) {
			return -1;
		}
		zone = (zone * 10) + digit;
	}
	return zone;
}

$InetAddressArray* InetAddress::getAllByName0($String* host) {
	$init(InetAddress);
	return getAllByName0(host, true);
}

$InetAddressArray* InetAddress::getAllByName0($String* host, bool check) {
	$init(InetAddress);
	return getAllByName0(host, nullptr, check, true);
}

$InetAddressArray* InetAddress::getAllByName0($String* host, InetAddress* reqAddr, bool check, bool useCache) {
	$init(InetAddress);
	$useLocalCurrentObjectStackCache();
	if (check) {
		$var($SecurityManager, security, $System::getSecurityManager());
		if (security != nullptr) {
			security->checkConnect(host, -1);
		}
	}
	int64_t now = $System::nanoTime();
	{
		$var($Iterator, i$, $nc(InetAddress::expirySet)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($InetAddress$CachedAddresses, caddrs, $cast($InetAddress$CachedAddresses, i$->next()));
			{
				if (($nc(caddrs)->expiryTime - now) < (int64_t)0) {
					if ($nc(InetAddress::expirySet)->remove(caddrs)) {
						$nc(InetAddress::cache)->remove(caddrs->host, caddrs);
					}
				} else {
					break;
				}
			}
		}
	}
	$var($InetAddress$Addresses, addrs, nullptr);
	if (useCache) {
		$assign(addrs, $cast($InetAddress$Addresses, $nc(InetAddress::cache)->get(host)));
	} else {
		$assign(addrs, $cast($InetAddress$Addresses, $nc(InetAddress::cache)->remove(host)));
		if (addrs != nullptr) {
			if ($instanceOf($InetAddress$CachedAddresses, addrs)) {
				$nc(InetAddress::expirySet)->remove(addrs);
			}
			$assign(addrs, nullptr);
		}
	}
	if (addrs == nullptr) {
		$var($InetAddress$Addresses, oldAddrs, $cast($InetAddress$Addresses, $nc(InetAddress::cache)->putIfAbsent(host, $assign(addrs, $new($InetAddress$NameServiceAddresses, host, reqAddr)))));
		if (oldAddrs != nullptr) {
			$assign(addrs, oldAddrs);
		}
	}
	return $cast($InetAddressArray, $nc($($nc(addrs)->get()))->clone());
}

$InetAddressArray* InetAddress::getAddressesFromNameService($String* host, InetAddress* reqAddr) {
	$init(InetAddress);
	$useLocalCurrentObjectStackCache();
	$var($InetAddressArray, addresses, nullptr);
	$var($UnknownHostException, ex, nullptr);
	try {
		$assign(addresses, $nc(InetAddress::nameService)->lookupAllHostAddr(host));
	} catch ($UnknownHostException& uhe) {
		if ($nc(host)->equalsIgnoreCase("localhost"_s)) {
			$assign(addresses, $new($InetAddressArray, {$($nc(InetAddress::impl)->loopbackAddress())}));
		} else {
			$assign(ex, uhe);
		}
	}
	if (addresses == nullptr) {
		$throw(ex == nullptr ? $$new($UnknownHostException, host) : ex);
	}
	if (reqAddr != nullptr && $nc(addresses)->length > 1 && !$nc(addresses->get(0))->equals(reqAddr)) {
		int32_t i = 1;
		for (; i < addresses->length; ++i) {
			if ($nc(addresses->get(i))->equals(reqAddr)) {
				break;
			}
		}
		if (i < addresses->length) {
			$var(InetAddress, tmp, nullptr);
			$var(InetAddress, tmp2, reqAddr);
			for (int32_t j = 0; j < i; ++j) {
				$assign(tmp, addresses->get(j));
				addresses->set(j, tmp2);
				$assign(tmp2, tmp);
			}
			addresses->set(i, tmp2);
		}
	}
	return addresses;
}

InetAddress* InetAddress::getByAddress($bytes* addr) {
	$init(InetAddress);
	return getByAddress(nullptr, addr);
}

InetAddress* InetAddress::getLocalHost() {
	$init(InetAddress);
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, security, $System::getSecurityManager());
	try {
		$var($InetAddress$CachedLocalHost, clh, InetAddress::cachedLocalHost);
		if (clh != nullptr && (clh->expiryTime - $System::nanoTime()) >= (int64_t)0) {
			if (security != nullptr) {
				security->checkConnect(clh->host, -1);
			}
			return clh->addr;
		}
		$var($String, local, $nc(InetAddress::impl)->getLocalHostName());
		if (security != nullptr) {
			security->checkConnect(local, -1);
		}
		$var(InetAddress, localAddr, nullptr);
		if ($nc(local)->equals("localhost"_s)) {
			$assign(localAddr, $nc(InetAddress::impl)->loopbackAddress());
		} else {
			try {
				$assign(localAddr, $nc($(getAllByName0(local, nullptr, false, false)))->get(0));
			} catch ($UnknownHostException& uhe) {
				$var($UnknownHostException, uhe2, $new($UnknownHostException, $$str({local, ": "_s, $(uhe->getMessage())})));
				uhe2->initCause(uhe);
				$throw(uhe2);
			}
		}
		$assignStatic(InetAddress::cachedLocalHost, $new($InetAddress$CachedLocalHost, local, localAddr));
		return localAddr;
	} catch ($SecurityException& e) {
		return $nc(InetAddress::impl)->loopbackAddress();
	}
	$shouldNotReachHere();
}

void InetAddress::init() {
	$init(InetAddress);
	$prepareNativeStatic(InetAddress, init, void);
	$invokeNativeStatic();
	$finishNativeStatic();
}

InetAddress* InetAddress::anyLocalAddress() {
	$init(InetAddress);
	return $nc(InetAddress::impl)->anyLocalAddress();
}

$InetAddressImpl* InetAddress::loadImpl($String* implName) {
	$init(InetAddress);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($Object, impl, nullptr);
	$var($String, prefix, $GetPropertyAction::privilegedGetProperty("impl.prefix"_s, ""_s));
	try {
		$var($Object, tmp, $Class::forName($$str({"java.net."_s, prefix, implName}))->newInstance());
		$assign(impl, tmp);
	} catch ($ClassNotFoundException& e) {
		$nc($System::err)->println($$str({"Class not found: java.net."_s, prefix, implName, ":\ncheck impl.prefix property in your properties file."_s}));
	} catch ($InstantiationException& e) {
		$nc($System::err)->println($$str({"Could not instantiate: java.net."_s, prefix, implName, ":\ncheck impl.prefix property in your properties file."_s}));
	} catch ($IllegalAccessException& e) {
		$nc($System::err)->println($$str({"Cannot access class: java.net."_s, prefix, implName, ":\ncheck impl.prefix property in your properties file."_s}));
	}
	if (impl == nullptr) {
		try {
			$var($Object, tmp, $Class::forName(implName)->newInstance());
			$assign(impl, tmp);
		} catch ($Exception& e) {
			$throwNew($Error, "System property impl.prefix incorrect"_s);
		}
	}
	return $cast($InetAddressImpl, impl);
}

void InetAddress::readObjectNoData() {
	$beforeCallerSensitive();
	if ($of(this)->getClass()->getClassLoader() != nullptr) {
		$throwNew($SecurityException, "invalid address type"_s);
	}
}

void InetAddress::readObject($ObjectInputStream* s) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if ($of(this)->getClass()->getClassLoader() != nullptr) {
		$throwNew($SecurityException, "invalid address type"_s);
	}
	$var($ObjectInputStream$GetField, gf, $nc(s)->readFields());
	$var($String, host, $cast($String, $nc(gf)->get("hostName"_s, ($Object*)nullptr)));
	int32_t address = gf->get("address"_s, 0);
	int32_t family = gf->get("family"_s, 0);
	if (family != InetAddress::IPv4 && family != InetAddress::IPv6) {
		$throwNew($InvalidObjectException, $$str({"invalid address family type: "_s, $$str(family)}));
	}
	$var($InetAddress$InetAddressHolder, h, $new($InetAddress$InetAddressHolder, host, address, family));
	$nc(InetAddress::UNSAFE)->putReference(this, InetAddress::FIELDS_OFFSET, h);
}

void InetAddress::writeObject($ObjectOutputStream* s) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if ($of(this)->getClass()->getClassLoader() != nullptr) {
		$throwNew($SecurityException, "invalid address type"_s);
	}
	$var($ObjectOutputStream$PutField, pf, $nc(s)->putFields());
	$nc(pf)->put("hostName"_s, $($of($nc($(holder()))->getHostName())));
	pf->put("address"_s, $nc($(holder()))->getAddress());
	pf->put("family"_s, $nc($(holder()))->getFamily());
	s->writeFields();
}

void clinit$InetAddress($Class* class$) {
	$useLocalCurrentObjectStackCache();
	{
		$var($String, str, $GetPropertyAction::privilegedGetProperty("java.net.preferIPv6Addresses"_s));
		if (str == nullptr) {
			InetAddress::preferIPv6Address = InetAddress::PREFER_IPV4_VALUE;
		} else if ($nc(str)->equalsIgnoreCase("true"_s)) {
			InetAddress::preferIPv6Address = InetAddress::PREFER_IPV6_VALUE;
		} else if (str->equalsIgnoreCase("false"_s)) {
			InetAddress::preferIPv6Address = InetAddress::PREFER_IPV4_VALUE;
		} else if (str->equalsIgnoreCase("system"_s)) {
			InetAddress::preferIPv6Address = InetAddress::PREFER_SYSTEM_VALUE;
		} else {
			InetAddress::preferIPv6Address = InetAddress::PREFER_IPV4_VALUE;
		}
		$BootLoader::loadLibrary("net"_s);
		$SharedSecrets::setJavaNetInetAddressAccess($$new($InetAddress$1));
		InetAddress::init();
	}
	$assignStatic(InetAddress::cache, $new($ConcurrentHashMap));
	$assignStatic(InetAddress::expirySet, $new($ConcurrentSkipListSet));
	{
		$assignStatic(InetAddress::impl, $InetAddressImplFactory::create());
		$assignStatic(InetAddress::nameService, InetAddress::createNameService());
	}
	$assignStatic(InetAddress::UNSAFE, $Unsafe::getUnsafe());
	InetAddress::FIELDS_OFFSET = $nc(InetAddress::UNSAFE)->objectFieldOffset(InetAddress::class$, "holder"_s);
	$init($Integer);
	$assignStatic(InetAddress::serialPersistentFields, $new($ObjectStreamFieldArray, {
		$$new($ObjectStreamField, "hostName"_s, $String::class$),
		$$new($ObjectStreamField, "address"_s, $Integer::TYPE),
		$$new($ObjectStreamField, "family"_s, $Integer::TYPE)
	}));
}

InetAddress::InetAddress() {
}

$Class* InetAddress::load$($String* name, bool initialize) {
	$loadClass(InetAddress, name, initialize, &_InetAddress_ClassInfo_, clinit$InetAddress, allocate$InetAddress);
	return class$;
}

$Class* InetAddress::class$ = nullptr;

	} // net
} // java