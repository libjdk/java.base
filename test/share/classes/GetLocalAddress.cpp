#include <GetLocalAddress.h>

#include <java/io/Serializable.h>
#include <java/lang/Iterable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/DatagramSocket.h>
#include <java/net/InetAddress.h>
#include <java/net/InetSocketAddress.h>
#include <java/net/MulticastSocket.h>
#include <java/net/SocketAddress.h>
#include <java/nio/channels/DatagramChannel.h>
#include <java/nio/channels/NetworkChannel.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedHashMap.h>
#include <java/util/LinkedHashSet.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/function/Consumer.h>
#include <jcpp.h>

using $PrintStream = ::java::io::PrintStream;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $DatagramSocket = ::java::net::DatagramSocket;
using $InetAddress = ::java::net::InetAddress;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $MulticastSocket = ::java::net::MulticastSocket;
using $SocketAddress = ::java::net::SocketAddress;
using $DatagramChannel = ::java::nio::channels::DatagramChannel;
using $Iterator = ::java::util::Iterator;
using $LinkedHashMap = ::java::util::LinkedHashMap;
using $LinkedHashSet = ::java::util::LinkedHashSet;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;
using $Consumer = ::java::util::function::Consumer;

class GetLocalAddress$$Lambda$close : public $Consumer {
	$class(GetLocalAddress$$Lambda$close, $NO_CLASS_INIT, $Consumer)
public:
	void init$() {
	}
	virtual void accept(Object$* socket) override {
		GetLocalAddress::close($cast($DatagramSocket, socket));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<GetLocalAddress$$Lambda$close>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo GetLocalAddress$$Lambda$close::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(GetLocalAddress$$Lambda$close, init$, void)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(GetLocalAddress$$Lambda$close, accept, void, Object$*)},
	{}
};
$ClassInfo GetLocalAddress$$Lambda$close::classInfo$ = {
	$PUBLIC | $FINAL,
	"GetLocalAddress$$Lambda$close",
	"java.lang.Object",
	"java.util.function.Consumer",
	nullptr,
	methodInfos
};
$Class* GetLocalAddress$$Lambda$close::load$($String* name, bool initialize) {
	$loadClass(GetLocalAddress$$Lambda$close, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* GetLocalAddress$$Lambda$close::class$ = nullptr;

$FieldInfo _GetLocalAddress_FieldInfo_[] = {
	{"addressMap", "Ljava/util/Map;", "Ljava/util/Map<Ljava/net/DatagramSocket;Ljava/net/InetAddress;>;", $STATIC | $FINAL, $staticField(GetLocalAddress, addressMap)},
	{"toClose", "Ljava/util/Set;", "Ljava/util/Set<Ljava/net/DatagramSocket;>;", $STATIC | $FINAL, $staticField(GetLocalAddress, toClose)},
	{}
};

$MethodInfo _GetLocalAddress_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(GetLocalAddress, init$, void)},
	{"addToMap", "(Ljava/net/DatagramSocket;)V", nullptr, $STATIC, $staticMethod(GetLocalAddress, addToMap, void, $DatagramSocket*), "java.io.IOException"},
	{"bindAndAddToMap", "(Ljava/net/DatagramSocket;Ljava/net/InetSocketAddress;)V", nullptr, $STATIC, $staticMethod(GetLocalAddress, bindAndAddToMap, void, $DatagramSocket*, $InetSocketAddress*), "java.io.IOException"},
	{"checkAddresses", "(Ljava/net/DatagramSocket;Ljava/net/InetAddress;Ljava/net/InetAddress;)V", nullptr, $STATIC, $staticMethod(GetLocalAddress, checkAddresses, void, $DatagramSocket*, $InetAddress*, $InetAddress*)},
	{"cleanup", "()V", nullptr, $STATIC, $staticMethod(GetLocalAddress, cleanup, void)},
	{"close", "(Ljava/net/DatagramSocket;)V", nullptr, $STATIC, $staticMethod(GetLocalAddress, close, void, $DatagramSocket*)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(GetLocalAddress, main, void, $StringArray*), "java.lang.Exception"},
	{"testAfterClose", "()V", nullptr, $STATIC, $staticMethod(GetLocalAddress, testAfterClose, void), "java.io.IOException"},
	{"testAllSockets", "()V", nullptr, $STATIC, $staticMethod(GetLocalAddress, testAllSockets, void), "java.io.IOException"},
	{"testNullAddress", "(Ljava/net/DatagramSocket;Ljava/lang/Object;Ljava/lang/String;)V", nullptr, $STATIC, $staticMethod(GetLocalAddress, testNullAddress, void, $DatagramSocket*, Object$*, $String*)},
	{"testSocket", "()V", nullptr, $STATIC, $staticMethod(GetLocalAddress, testSocket, void), "java.io.IOException"},
	{"testWildcardAddress", "(Ljava/net/DatagramSocket;Ljava/net/InetAddress;Ljava/lang/String;)V", nullptr, $STATIC, $staticMethod(GetLocalAddress, testWildcardAddress, void, $DatagramSocket*, $InetAddress*, $String*)},
	{}
};

$ClassInfo _GetLocalAddress_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"GetLocalAddress",
	"java.lang.Object",
	nullptr,
	_GetLocalAddress_FieldInfo_,
	_GetLocalAddress_MethodInfo_
};

$Object* allocate$GetLocalAddress($Class* clazz) {
	return $of($alloc(GetLocalAddress));
}

$Map* GetLocalAddress::addressMap = nullptr;
$Set* GetLocalAddress::toClose = nullptr;

void GetLocalAddress::init$() {
}

void GetLocalAddress::main($StringArray* args) {
	$init(GetLocalAddress);
	{
		$var($Throwable, var$0, nullptr);
		try {
			testAllSockets();
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			cleanup();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void GetLocalAddress::testAllSockets() {
	$init(GetLocalAddress);
	$useLocalCurrentObjectStackCache();
	$var($InetSocketAddress, address, $new($InetSocketAddress, $($InetAddress::getLocalHost()), 0));
	bindAndAddToMap($$new($DatagramSocket, ($SocketAddress*)nullptr), address);
	bindAndAddToMap($$new($MulticastSocket, ($SocketAddress*)nullptr), address);
	bindAndAddToMap($($nc($($DatagramChannel::open()))->socket()), address);
	addToMap($$new($DatagramSocket, static_cast<$SocketAddress*>(address)));
	addToMap($$new($MulticastSocket, static_cast<$SocketAddress*>(address)));
	addToMap($($nc($($cast($DatagramChannel, $nc($($DatagramChannel::open()))->bind(address))))->socket()));
	testSocket();
	testAfterClose();
}

void GetLocalAddress::bindAndAddToMap($DatagramSocket* socket, $InetSocketAddress* address) {
	$init(GetLocalAddress);
	$useLocalCurrentObjectStackCache();
	$nc(GetLocalAddress::toClose)->add(socket);
	testNullAddress(socket, $($nc(socket)->getLocalSocketAddress()), "before bind"_s);
	testWildcardAddress(socket, $($nc(socket)->getLocalAddress()), "before bind"_s);
	$nc(socket)->bind(address);
	$nc(GetLocalAddress::addressMap)->put(socket, $($nc(($cast($InetSocketAddress, $(socket->getLocalSocketAddress()))))->getAddress()));
}

void GetLocalAddress::addToMap($DatagramSocket* socket) {
	$init(GetLocalAddress);
	$useLocalCurrentObjectStackCache();
	$nc(GetLocalAddress::toClose)->add(socket);
	$nc(GetLocalAddress::addressMap)->put(socket, $($nc(($cast($InetSocketAddress, $($nc(socket)->getLocalSocketAddress()))))->getAddress()));
}

void GetLocalAddress::testSocket() {
	$init(GetLocalAddress);
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc($($nc(GetLocalAddress::addressMap)->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
			{
				$var($DatagramSocket, socket, $cast($DatagramSocket, $nc(entry)->getKey()));
				$var($DatagramSocket, var$0, socket);
				$var($InetAddress, var$1, $cast($InetAddress, entry->getValue()));
				checkAddresses(var$0, var$1, $($nc(($cast($InetSocketAddress, $($nc(($cast($DatagramSocket, $(entry->getKey()))))->getLocalSocketAddress()))))->getAddress()));
				$var($DatagramSocket, var$2, socket);
				$var($InetAddress, var$3, $cast($InetAddress, entry->getValue()));
				checkAddresses(var$2, var$3, $($nc(($cast($DatagramSocket, $(entry->getKey()))))->getLocalAddress()));
			}
		}
	}
}

void GetLocalAddress::testAfterClose() {
	$init(GetLocalAddress);
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc($($nc(GetLocalAddress::addressMap)->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
			{
				$var($DatagramSocket, socket, $cast($DatagramSocket, $nc(entry)->getKey()));
				$nc(socket)->close();
				$nc(GetLocalAddress::toClose)->remove(socket);
				testNullAddress(socket, $(socket->getLocalSocketAddress()), "after close"_s);
				testNullAddress(socket, $(socket->getLocalAddress()), "after close"_s);
			}
		}
	}
}

void GetLocalAddress::checkAddresses($DatagramSocket* socket, $InetAddress* a1, $InetAddress* a2) {
	$init(GetLocalAddress);
	$useLocalCurrentObjectStackCache();
	$var($String, var$2, $$str({$nc($of(socket))->getClass(), ": Address1: "_s}));
	$var($String, var$1, $$concat(var$2, $($nc(a1)->toString())));
	$var($String, var$0, $$concat(var$1, " Address2: "_s));
	$nc($System::out)->println($$concat(var$0, $($nc(a2)->toString())));
	if (!$nc($($nc(a1)->getHostAddress()))->equals($($nc(a2)->getHostAddress()))) {
		$throwNew($RuntimeException, $$str({"Local address don\'t match for "_s, $nc($of(socket))->getClass()}));
	}
}

void GetLocalAddress::testNullAddress($DatagramSocket* socket, Object$* address, $String* when) {
	$init(GetLocalAddress);
	$useLocalCurrentObjectStackCache();
	$nc($System::out)->println($$str({$nc($of(socket))->getClass(), ": Checking address "_s, when}));
	if (address != nullptr) {
		$var($String, var$0, $$str({"Expected null address "_s, when, ", got: "_s, address, " for "_s}));
		$throwNew($RuntimeException, $$concat(var$0, $($nc($of(socket))->getClass())));
	}
}

void GetLocalAddress::testWildcardAddress($DatagramSocket* socket, $InetAddress* address, $String* when) {
	$init(GetLocalAddress);
	$useLocalCurrentObjectStackCache();
	$nc($System::out)->println($$str({$nc($of(socket))->getClass(), ": Checking address "_s, when}));
	if (address == nullptr || !$nc(address)->isAnyLocalAddress()) {
		$var($String, var$0, $$str({"Expected wildcard address "_s, when, ", got: "_s, address, " for "_s}));
		$throwNew($RuntimeException, $$concat(var$0, $($nc($of(socket))->getClass())));
	}
}

void GetLocalAddress::cleanup() {
	$init(GetLocalAddress);
	$nc(GetLocalAddress::toClose)->forEach(static_cast<$Consumer*>($$new(GetLocalAddress$$Lambda$close)));
	$nc(GetLocalAddress::toClose)->clear();
	$nc(GetLocalAddress::addressMap)->clear();
}

void GetLocalAddress::close($DatagramSocket* socket) {
	$init(GetLocalAddress);
	try {
		$nc(socket)->close();
	} catch ($Throwable& ignore) {
	}
}

void clinit$GetLocalAddress($Class* class$) {
	$assignStatic(GetLocalAddress::addressMap, $new($LinkedHashMap));
	$assignStatic(GetLocalAddress::toClose, $new($LinkedHashSet));
}

GetLocalAddress::GetLocalAddress() {
}

$Class* GetLocalAddress::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(GetLocalAddress$$Lambda$close::classInfo$.name)) {
			return GetLocalAddress$$Lambda$close::load$(name, initialize);
		}
	}
	$loadClass(GetLocalAddress, name, initialize, &_GetLocalAddress_ClassInfo_, clinit$GetLocalAddress, allocate$GetLocalAddress);
	return class$;
}

$Class* GetLocalAddress::class$ = nullptr;