#include <java/net/InetAddress$HostsFileNameService.h>

#include <java/io/File.h>
#include <java/io/IOException.h>
#include <java/lang/CharSequence.h>
#include <java/net/Inet4Address.h>
#include <java/net/Inet6Address.h>
#include <java/net/InetAddress.h>
#include <java/net/UnknownHostException.h>
#include <java/nio/charset/Charset.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/List.h>
#include <java/util/Scanner.h>
#include <sun/net/util/IPAddressUtil.h>
#include <sun/nio/cs/UTF_8.h>
#include <sun/security/action/GetPropertyAction.h>
#include <jcpp.h>

#undef EMPTY_ARRAY
#undef INSTANCE

using $InetAddressArray = $Array<::java::net::InetAddress>;
using $File = ::java::io::File;
using $IOException = ::java::io::IOException;
using $Boolean = ::java::lang::Boolean;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Inet4Address = ::java::net::Inet4Address;
using $Inet6Address = ::java::net::Inet6Address;
using $InetAddress = ::java::net::InetAddress;
using $UnknownHostException = ::java::net::UnknownHostException;
using $Charset = ::java::nio::charset::Charset;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $List = ::java::util::List;
using $Scanner = ::java::util::Scanner;
using $IPAddressUtil = ::sun::net::util::IPAddressUtil;
using $UTF_8 = ::sun::nio::cs::UTF_8;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;

namespace java {
	namespace net {

$FieldInfo _InetAddress$HostsFileNameService_FieldInfo_[] = {
	{"EMPTY_ARRAY", "[Ljava/net/InetAddress;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InetAddress$HostsFileNameService, EMPTY_ARRAY)},
	{"preferIPv4Stack", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(InetAddress$HostsFileNameService, preferIPv4Stack)},
	{"hostsFile", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(InetAddress$HostsFileNameService, hostsFile)},
	{}
};

$MethodInfo _InetAddress$HostsFileNameService_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(InetAddress$HostsFileNameService, init$, void, $String*)},
	{"concatAddresses", "(Ljava/util/List;Ljava/util/List;)Ljava/util/List;", "(Ljava/util/List<Ljava/net/InetAddress;>;Ljava/util/List<Ljava/net/InetAddress;>;)Ljava/util/List<Ljava/net/InetAddress;>;", $PRIVATE | $STATIC, $staticMethod(InetAddress$HostsFileNameService, concatAddresses, $List*, $List*, $List*)},
	{"createAddressByteArray", "(Ljava/lang/String;)[B", nullptr, $PRIVATE, $method(InetAddress$HostsFileNameService, createAddressByteArray, $bytes*, $String*)},
	{"extractHostAddr", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE, $method(InetAddress$HostsFileNameService, extractHostAddr, $String*, $String*, $String*)},
	{"getHostByAddr", "([B)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(InetAddress$HostsFileNameService, getHostByAddr, $String*, $bytes*), "java.net.UnknownHostException"},
	{"lookupAllHostAddr", "(Ljava/lang/String;)[Ljava/net/InetAddress;", nullptr, $PUBLIC, $virtualMethod(InetAddress$HostsFileNameService, lookupAllHostAddr, $InetAddressArray*, $String*), "java.net.UnknownHostException"},
	{"removeComments", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE, $method(InetAddress$HostsFileNameService, removeComments, $String*, $String*)},
	{}
};

$InnerClassInfo _InetAddress$HostsFileNameService_InnerClassesInfo_[] = {
	{"java.net.InetAddress$HostsFileNameService", "java.net.InetAddress", "HostsFileNameService", $PRIVATE | $STATIC | $FINAL},
	{"java.net.InetAddress$NameService", "java.net.InetAddress", "NameService", $PRIVATE | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _InetAddress$HostsFileNameService_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.net.InetAddress$HostsFileNameService",
	"java.lang.Object",
	"java.net.InetAddress$NameService",
	_InetAddress$HostsFileNameService_FieldInfo_,
	_InetAddress$HostsFileNameService_MethodInfo_,
	nullptr,
	nullptr,
	_InetAddress$HostsFileNameService_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.net.InetAddress"
};

$Object* allocate$InetAddress$HostsFileNameService($Class* clazz) {
	return $of($alloc(InetAddress$HostsFileNameService));
}

$InetAddressArray* InetAddress$HostsFileNameService::EMPTY_ARRAY = nullptr;
bool InetAddress$HostsFileNameService::preferIPv4Stack = false;

void InetAddress$HostsFileNameService::init$($String* hostsFileName) {
	$set(this, hostsFile, hostsFileName);
}

$String* InetAddress$HostsFileNameService::getHostByAddr($bytes* addr) {
	$useLocalCurrentObjectStackCache();
	$var($String, hostEntry, nullptr);
	$var($String, host, nullptr);
	try {
		$init($UTF_8);
		$var($Scanner, hostsFileScanner, $new($Scanner, $$new($File, this->hostsFile), static_cast<$Charset*>($UTF_8::INSTANCE)));
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					while (hostsFileScanner->hasNextLine()) {
						$assign(hostEntry, hostsFileScanner->nextLine());
						if (!$nc(hostEntry)->startsWith("#"_s)) {
							$assign(hostEntry, removeComments(hostEntry));
							$var($StringArray, mapping, $nc(hostEntry)->split("\\s+"_s));
							if (mapping->length >= 2 && $Arrays::equals(addr, $(createAddressByteArray(mapping->get(0))))) {
								$assign(host, mapping->get(1));
								break;
							}
						}
					}
				} catch ($Throwable& t$) {
					try {
						hostsFileScanner->close();
					} catch ($Throwable& x2) {
						t$->addSuppressed(x2);
					}
					$throw(t$);
				}
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				hostsFileScanner->close();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	} catch ($IOException& e) {
		$throwNew($UnknownHostException, $$str({"Unable to resolve address "_s, $($Arrays::toString(addr)), " as hosts file "_s, this->hostsFile, " not found "_s}));
	}
	bool var$2 = (host == nullptr) || ($nc(host)->isEmpty());
	if (var$2 || ($nc(host)->equals(" "_s))) {
		$throwNew($UnknownHostException, $$str({"Requested address "_s, $($Arrays::toString(addr)), " resolves to an invalid entry in hosts file "_s, this->hostsFile}));
	}
	return host;
}

$InetAddressArray* InetAddress$HostsFileNameService::lookupAllHostAddr($String* host) {
	$useLocalCurrentObjectStackCache();
	$var($String, hostEntry, nullptr);
	$var($String, addrStr, nullptr);
	$var($bytes, addr, nullptr);
	$var($List, inetAddresses, $new($ArrayList));
	$var($List, inet4Addresses, $new($ArrayList));
	$var($List, inet6Addresses, $new($ArrayList));
	try {
		$init($UTF_8);
		$var($Scanner, hostsFileScanner, $new($Scanner, $$new($File, this->hostsFile), static_cast<$Charset*>($UTF_8::INSTANCE)));
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					while (hostsFileScanner->hasNextLine()) {
						$assign(hostEntry, hostsFileScanner->nextLine());
						if (!$nc(hostEntry)->startsWith("#"_s)) {
							$assign(hostEntry, removeComments(hostEntry));
							if ($nc(hostEntry)->contains(host)) {
								$assign(addrStr, extractHostAddr(hostEntry, host));
								if ((addrStr != nullptr) && (!addrStr->isEmpty())) {
									$assign(addr, createAddressByteArray(addrStr));
									if (addr != nullptr) {
										$var($InetAddress, address, $InetAddress::getByAddress(host, addr));
										inetAddresses->add(address);
										if ($instanceOf($Inet4Address, address)) {
											inet4Addresses->add(address);
										}
										if ($instanceOf($Inet6Address, address)) {
											inet6Addresses->add(address);
										}
									}
								}
							}
						}
					}
				} catch ($Throwable& t$) {
					try {
						hostsFileScanner->close();
					} catch ($Throwable& x2) {
						t$->addSuppressed(x2);
					}
					$throw(t$);
				}
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				hostsFileScanner->close();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	} catch ($IOException& e) {
		$throwNew($UnknownHostException, $$str({"Unable to resolve host "_s, host, " as hosts file "_s, this->hostsFile, " not found "_s}));
	}
	$var($List, res, nullptr);
	if (InetAddress$HostsFileNameService::preferIPv4Stack) {
		$assign(res, inet4Addresses);
	} else {
		$init($InetAddress);

		$var($List, var$2, nullptr)
		switch ($InetAddress::preferIPv6Address) {
		case 0:
			{
				$assign(var$2, concatAddresses(inet4Addresses, inet6Addresses));
				break;
			}
		case 1:
			{
				$assign(var$2, concatAddresses(inet6Addresses, inet4Addresses));
				break;
			}
		default:
			{
				$assign(var$2, inetAddresses);
				break;
			}
		}
		$assign(res, var$2);
	}
	if ($nc(res)->isEmpty()) {
		$throwNew($UnknownHostException, $$str({"Unable to resolve host "_s, host, " in hosts file "_s, this->hostsFile}));
	}
	return $fcast($InetAddressArray, $nc(res)->toArray(InetAddress$HostsFileNameService::EMPTY_ARRAY));
}

$List* InetAddress$HostsFileNameService::concatAddresses($List* firstPart, $List* secondPart) {
	$init(InetAddress$HostsFileNameService);
	$var($List, result, $new($ArrayList, static_cast<$Collection*>(firstPart)));
	result->addAll(secondPart);
	return result;
}

$String* InetAddress$HostsFileNameService::removeComments($String* hostsEntry) {
	$var($String, filteredEntry, hostsEntry);
	int32_t hashIndex = 0;
	if ((hashIndex = $nc(hostsEntry)->indexOf("#"_s)) != -1) {
		$assign(filteredEntry, hostsEntry->substring(0, hashIndex));
	}
	return filteredEntry;
}

$bytes* InetAddress$HostsFileNameService::createAddressByteArray($String* addrStr) {
	$var($bytes, addrArray, nullptr);
	$assign(addrArray, $IPAddressUtil::textToNumericFormatV4(addrStr));
	if (addrArray == nullptr) {
		$assign(addrArray, $IPAddressUtil::textToNumericFormatV6(addrStr));
	}
	return addrArray;
}

$String* InetAddress$HostsFileNameService::extractHostAddr($String* hostEntry, $String* host) {
	$useLocalCurrentObjectStackCache();
	$var($StringArray, mapping, $nc(hostEntry)->split("\\s+"_s));
	$var($String, hostAddr, nullptr);
	if (mapping->length >= 2) {
		for (int32_t i = 1; i < mapping->length; ++i) {
			if ($nc(mapping->get(i))->equalsIgnoreCase(host)) {
				$assign(hostAddr, mapping->get(0));
			}
		}
	}
	return hostAddr;
}

void clinit$InetAddress$HostsFileNameService($Class* class$) {
	$assignStatic(InetAddress$HostsFileNameService::EMPTY_ARRAY, $new($InetAddressArray, 0));
	InetAddress$HostsFileNameService::preferIPv4Stack = $Boolean::parseBoolean($($GetPropertyAction::privilegedGetProperty("java.net.preferIPv4Stack"_s)));
}

InetAddress$HostsFileNameService::InetAddress$HostsFileNameService() {
}

$Class* InetAddress$HostsFileNameService::load$($String* name, bool initialize) {
	$loadClass(InetAddress$HostsFileNameService, name, initialize, &_InetAddress$HostsFileNameService_ClassInfo_, clinit$InetAddress$HostsFileNameService, allocate$InetAddress$HostsFileNameService);
	return class$;
}

$Class* InetAddress$HostsFileNameService::class$ = nullptr;

	} // net
} // java