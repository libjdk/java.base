#include <BadIPv6Addresses.h>

#include <java/net/InetAddress.h>
#include <java/net/UnknownHostException.h>
#include <java/util/ArrayList.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <jcpp.h>

using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $InetAddress = ::java::net::InetAddress;
using $UnknownHostException = ::java::net::UnknownHostException;
using $ArrayList = ::java::util::ArrayList;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;

$MethodInfo _BadIPv6Addresses_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(BadIPv6Addresses, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(BadIPv6Addresses, main, void, $StringArray*), "java.lang.Exception"},
	{}
};

$ClassInfo _BadIPv6Addresses_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"BadIPv6Addresses",
	"java.lang.Object",
	nullptr,
	nullptr,
	_BadIPv6Addresses_MethodInfo_
};

$Object* allocate$BadIPv6Addresses($Class* clazz) {
	return $of($alloc(BadIPv6Addresses));
}

void BadIPv6Addresses::init$() {
}

void BadIPv6Addresses::main($StringArray* args) {
	$useLocalCurrentObjectStackCache();
	$var($StringArray, badAddresses, $new($StringArray, {
		"0:1:2:3:4:5:6:7:8"_s,
		"0:1:2:3:4:5:6"_s,
		"0:1:2:3:4:5:6:x"_s,
		"0:1:2:3:4:5:6::7"_s,
		"0:1:2:3:4:5:6:789abcdef"_s,
		"0:1:2:3::x"_s,
		"0:1:2:::3"_s,
		"0:1:2:3::abcde"_s,
		"0:1"_s,
		"0:0:0:0:0:x:10.0.0.1"_s,
		"0:0:0:0:0:0:10.0.0.x"_s,
		"0:0:0:0:0::0:10.0.0.1"_s,
		"0:0:0:0:0:fffff:10.0.0.1"_s,
		"0:0:0:0:0:0:0:10.0.0.1"_s,
		"0:0:0:0:0:10.0.0.1"_s,
		"0:0:0:0:0:0:10.0.0.0.1"_s,
		"0:0:0:0:0:0:10.0.1"_s,
		"0:0:0:0:0:0:10..0.0.1"_s,
		"::fffx:192.168.0.1"_s,
		"::ffff:192.168.0.x"_s,
		":::ffff:192.168.0.1"_s,
		"::fffff:192.168.0.1"_s,
		"::ffff:1923.168.0.1"_s,
		":ffff:192.168.0.1"_s,
		"::ffff:192.168.0.1.2"_s,
		"::ffff:192.168.0"_s,
		"::ffff:192.168..0.1"_s
	}));
	$var($List, failedAddrs, $new($ArrayList));
	{
		$var($StringArray, arr$, badAddresses);
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, addrStr, arr$->get(i$));
			{
				try {
					$var($InetAddress, addr, $InetAddress::getByName(addrStr));
					failedAddrs->add(addrStr);
				} catch ($UnknownHostException& e) {
				}
			}
		}
	}
	if (failedAddrs->size() > 0) {
		$nc($System::out)->println("We should reject following ipv6 addresses, but we didn\'t:"_s);
		{
			$var($Iterator, i$, failedAddrs->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($String, addr, $cast($String, i$->next()));
				{
					$nc($System::out)->println($$str({"\t"_s, addr}));
				}
			}
		}
		$throwNew($RuntimeException, "Test failed."_s);
	}
}

BadIPv6Addresses::BadIPv6Addresses() {
}

$Class* BadIPv6Addresses::load$($String* name, bool initialize) {
	$loadClass(BadIPv6Addresses, name, initialize, &_BadIPv6Addresses_ClassInfo_, allocate$BadIPv6Addresses);
	return class$;
}

$Class* BadIPv6Addresses::class$ = nullptr;