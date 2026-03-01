#include <LocalSocketAddress.h>

#include <java/net/DatagramSocket.h>
#include <java/net/Inet6Address.h>
#include <java/net/InetAddress.h>
#include <java/net/NetworkInterface.h>
#include <java/util/ArrayList.h>
#include <java/util/Collections.h>
#include <java/util/Enumeration.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <jcpp.h>

using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $DatagramSocket = ::java::net::DatagramSocket;
using $Inet6Address = ::java::net::Inet6Address;
using $InetAddress = ::java::net::InetAddress;
using $NetworkInterface = ::java::net::NetworkInterface;
using $Collections = ::java::util::Collections;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;

$MethodInfo _LocalSocketAddress_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(LocalSocketAddress, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(LocalSocketAddress, main, void, $StringArray*), "java.net.SocketException"},
	{}
};

$ClassInfo _LocalSocketAddress_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"LocalSocketAddress",
	"java.lang.Object",
	nullptr,
	nullptr,
	_LocalSocketAddress_MethodInfo_
};

$Object* allocate$LocalSocketAddress($Class* clazz) {
	return $of($alloc(LocalSocketAddress));
}

void LocalSocketAddress::init$() {
}

void LocalSocketAddress::main($StringArray* args) {
	$useLocalCurrentObjectStackCache();
	$var($InetAddress, IPv6LoopbackAddr, nullptr);
	$var($DatagramSocket, soc, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		bool return$1 = false;
		try {
			$var($List, nics, $Collections::list($($NetworkInterface::getNetworkInterfaces())));
			{
				$var($Iterator, i$, $nc(nics)->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($NetworkInterface, nic, $cast($NetworkInterface, i$->next()));
					{
						if (!$nc(nic)->isLoopback()) {
							continue;
						}
						$var($List, addrs, $Collections::list($($nc(nic)->getInetAddresses())));
						{
							$var($Iterator, i$, $nc(addrs)->iterator());
							for (; $nc(i$)->hasNext();) {
								$var($InetAddress, addr, $cast($InetAddress, i$->next()));
								{
									if ($instanceOf($Inet6Address, addr)) {
										$assign(IPv6LoopbackAddr, addr);
										break;
									}
								}
							}
						}
					}
				}
			}
			if (IPv6LoopbackAddr == nullptr) {
				$nc($System::out)->println("IPv6 is not available, exiting test."_s);
				return$1 = true;
				goto $finally;
			}
			$assign(soc, $new($DatagramSocket, 0, IPv6LoopbackAddr));
			if (!$nc(IPv6LoopbackAddr)->equals($(soc->getLocalAddress()))) {
				$throwNew($RuntimeException, $$str({"Bound address is "_s, $(soc->getLocalAddress()), ", but should be "_s, IPv6LoopbackAddr}));
			}
		} catch ($Throwable& var$2) {
			$assign(var$0, var$2);
		} $finally: {
			if (soc != nullptr) {
				soc->close();
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return;
		}
	}
}

LocalSocketAddress::LocalSocketAddress() {
}

$Class* LocalSocketAddress::load$($String* name, bool initialize) {
	$loadClass(LocalSocketAddress, name, initialize, &_LocalSocketAddress_ClassInfo_, allocate$LocalSocketAddress);
	return class$;
}

$Class* LocalSocketAddress::class$ = nullptr;