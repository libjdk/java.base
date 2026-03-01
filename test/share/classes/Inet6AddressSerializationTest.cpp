#include <Inet6AddressSerializationTest.h>

#include <MockE1000g0Inet6Address.h>
#include <MockLo0Inet6Address.h>
#include <java/io/ByteArrayInputStream.h>
#include <java/io/ByteArrayOutputStream.h>
#include <java/io/FileNotFoundException.h>
#include <java/io/FileOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream.h>
#include <java/io/OutputStream.h>
#include <java/lang/CharSequence.h>
#include <java/net/Inet6Address.h>
#include <java/net/InetAddress.h>
#include <java/net/NetworkInterface.h>
#include <java/net/UnknownHostException.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Enumeration.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <jcpp.h>

#undef IN6ADDR_ANY_INIT
#undef LOCALHOSTNAME
#undef LOOPBACKIPV6ADDRESS
#undef LOOPBACK_SCOPE_ID
#undef NETWORK_IF_LO0
#undef SCOPE_ID_LO0
#undef SCOPE_ID_ZERO

using $MockE1000g0Inet6Address = ::MockE1000g0Inet6Address;
using $MockLo0Inet6Address = ::MockLo0Inet6Address;
using $InetAddressArray = $Array<::java::net::InetAddress>;
using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $FileNotFoundException = ::java::io::FileNotFoundException;
using $FileOutputStream = ::java::io::FileOutputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $Byte = ::java::lang::Byte;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $Inet6Address = ::java::net::Inet6Address;
using $InetAddress = ::java::net::InetAddress;
using $NetworkInterface = ::java::net::NetworkInterface;
using $UnknownHostException = ::java::net::UnknownHostException;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Enumeration = ::java::util::Enumeration;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;

$FieldInfo _Inet6AddressSerializationTest_FieldInfo_[] = {
	{"failed", "Z", nullptr, $STATIC, $staticField(Inet6AddressSerializationTest, failed)},
	{"isWindows", "Z", nullptr, $STATIC, $staticField(Inet6AddressSerializationTest, isWindows)},
	{"LOOPBACK_SCOPE_ID", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Inet6AddressSerializationTest, LOOPBACK_SCOPE_ID)},
	{"IN6ADDR_ANY_INIT", "[B", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Inet6AddressSerializationTest, IN6ADDR_ANY_INIT)},
	{"LOOPBACKIPV6ADDRESS", "[B", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Inet6AddressSerializationTest, LOOPBACKIPV6ADDRESS)},
	{"E1000G0IPV6ADDRESS", "[B", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Inet6AddressSerializationTest, E1000G0IPV6ADDRESS)},
	{"E1000G0HOSTNAME", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Inet6AddressSerializationTest, E1000G0HOSTNAME)},
	{"LOCALHOSTNAME", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Inet6AddressSerializationTest, LOCALHOSTNAME)},
	{"NETWORK_IF_E1000G0", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Inet6AddressSerializationTest, NETWORK_IF_E1000G0)},
	{"NETWORK_IF_LO0", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Inet6AddressSerializationTest, NETWORK_IF_LO0)},
	{"SCOPE_ID_E1000G0", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Inet6AddressSerializationTest, SCOPE_ID_E1000G0)},
	{"SCOPE_ID_LO0", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Inet6AddressSerializationTest, SCOPE_ID_LO0)},
	{"SCOPE_ID_ZERO", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Inet6AddressSerializationTest, SCOPE_ID_ZERO)},
	{"JDK7Inet6AddressSerialData", "[B", nullptr, $STATIC | $FINAL, $staticField(Inet6AddressSerializationTest, JDK7Inet6AddressSerialData)},
	{"JDK8Inet6AddressSerialData", "[B", nullptr, $STATIC | $FINAL, $staticField(Inet6AddressSerializationTest, JDK8Inet6AddressSerialData)},
	{"SerialData_ifname_e1000g0", "[B", nullptr, $STATIC | $FINAL, $staticField(Inet6AddressSerializationTest, SerialData_ifname_e1000g0)},
	{"SerialData_ifname_lo0", "[B", nullptr, $STATIC | $FINAL, $staticField(Inet6AddressSerializationTest, SerialData_ifname_lo0)},
	{}
};

$MethodInfo _Inet6AddressSerializationTest_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Inet6AddressSerializationTest, init$, void)},
	{"assertAddressEqual", "([B[B)V", nullptr, $STATIC, $staticMethod(Inet6AddressSerializationTest, assertAddressEqual, void, $bytes*, $bytes*)},
	{"assertHostAddressEqual", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $STATIC, $staticMethod(Inet6AddressSerializationTest, assertHostAddressEqual, void, $String*, $String*)},
	{"assertHostNameEqual", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $STATIC, $staticMethod(Inet6AddressSerializationTest, assertHostNameEqual, void, $String*, $String*)},
	{"assertNetworkInterfaceEqual", "(Ljava/net/NetworkInterface;Ljava/net/NetworkInterface;)V", nullptr, $STATIC, $staticMethod(Inet6AddressSerializationTest, assertNetworkInterfaceEqual, void, $NetworkInterface*, $NetworkInterface*)},
	{"assertNetworkInterfaceNameEqual", "(Ljava/lang/String;Ljava/net/NetworkInterface;)V", nullptr, $STATIC, $staticMethod(Inet6AddressSerializationTest, assertNetworkInterfaceNameEqual, void, $String*, $NetworkInterface*)},
	{"assertScopeIdEqual", "(II)V", nullptr, $STATIC, $staticMethod(Inet6AddressSerializationTest, assertScopeIdEqual, void, int32_t, int32_t)},
	{"createOutputFileName", "(Ljava/net/Inet6Address;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(Inet6AddressSerializationTest, createOutputFileName, $String*, $Inet6Address*)},
	{"displayExpectedInet6Address", "(Ljava/net/Inet6Address;)V", nullptr, $STATIC, $staticMethod(Inet6AddressSerializationTest, displayExpectedInet6Address, void, $Inet6Address*)},
	{"equal", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $STATIC, $staticMethod(Inet6AddressSerializationTest, equal, void, Object$*, Object$*)},
	{"generateAllInet6AddressSerializedData", "()V", nullptr, $STATIC, $staticMethod(Inet6AddressSerializationTest, generateAllInet6AddressSerializedData, void), "java.io.IOException"},
	{"generateSerializedInet6AddressData", "(Ljava/net/Inet6Address;Ljava/io/PrintStream;Z)[B", nullptr, $STATIC, $staticMethod(Inet6AddressSerializationTest, generateSerializedInet6AddressData, $bytes*, $Inet6Address*, $PrintStream*, bool), "java.io.IOException"},
	{"getAllInet6Addresses", "()Ljava/util/List;", "()Ljava/util/List<Ljava/net/Inet6Address;>;", $STATIC, $staticMethod(Inet6AddressSerializationTest, getAllInet6Addresses, $List*), "java.lang.Exception"},
	{"getIfName", "(Ljava/net/Inet6Address;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(Inet6AddressSerializationTest, getIfName, $String*, $Inet6Address*)},
	{"getThisHostIPV6Address", "(Ljava/lang/String;)[B", nullptr, $PRIVATE | $STATIC, $staticMethod(Inet6AddressSerializationTest, getThisHostIPV6Address, $bytes*, $String*), "java.lang.Exception"},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(Inet6AddressSerializationTest, main, void, $StringArray*), "java.lang.Exception"},
	{"runTests", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(Inet6AddressSerializationTest, runTests, void), "java.net.UnknownHostException,java.lang.Exception,java.io.IOException"},
	{"serializeInet6AddressToFile", "(Ljava/net/Inet6Address;)V", nullptr, $STATIC, $staticMethod(Inet6AddressSerializationTest, serializeInet6AddressToFile, void, $Inet6Address*)},
	{"testAllNetworkInterfaces", "()V", nullptr, $STATIC, $staticMethod(Inet6AddressSerializationTest, testAllNetworkInterfaces, void), "java.lang.Exception"},
	{"testInet6AddressSerialization", "(Ljava/net/Inet6Address;[B)V", nullptr, $STATIC, $staticMethod(Inet6AddressSerializationTest, testInet6AddressSerialization, void, $Inet6Address*, $bytes*), "java.io.IOException"},
	{"testSerializedE1000gInet6Address", "()V", nullptr, $STATIC, $staticMethod(Inet6AddressSerializationTest, testSerializedE1000gInet6Address, void), "java.io.IOException"},
	{"testSerializedLo0Inet6Address", "()V", nullptr, $STATIC, $staticMethod(Inet6AddressSerializationTest, testSerializedLo0Inet6Address, void), "java.io.IOException"},
	{}
};

$ClassInfo _Inet6AddressSerializationTest_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"Inet6AddressSerializationTest",
	"java.lang.Object",
	nullptr,
	_Inet6AddressSerializationTest_FieldInfo_,
	_Inet6AddressSerializationTest_MethodInfo_
};

$Object* allocate$Inet6AddressSerializationTest($Class* clazz) {
	return $of($alloc(Inet6AddressSerializationTest));
}

bool Inet6AddressSerializationTest::failed = false;
bool Inet6AddressSerializationTest::isWindows = false;
$bytes* Inet6AddressSerializationTest::IN6ADDR_ANY_INIT = nullptr;
$bytes* Inet6AddressSerializationTest::LOOPBACKIPV6ADDRESS = nullptr;
$bytes* Inet6AddressSerializationTest::E1000G0IPV6ADDRESS = nullptr;
$String* Inet6AddressSerializationTest::E1000G0HOSTNAME = nullptr;
$String* Inet6AddressSerializationTest::LOCALHOSTNAME = nullptr;
$String* Inet6AddressSerializationTest::NETWORK_IF_E1000G0 = nullptr;
$String* Inet6AddressSerializationTest::NETWORK_IF_LO0 = nullptr;
$bytes* Inet6AddressSerializationTest::JDK7Inet6AddressSerialData = nullptr;
$bytes* Inet6AddressSerializationTest::JDK8Inet6AddressSerialData = nullptr;
$bytes* Inet6AddressSerializationTest::SerialData_ifname_e1000g0 = nullptr;
$bytes* Inet6AddressSerializationTest::SerialData_ifname_lo0 = nullptr;

void Inet6AddressSerializationTest::init$() {
}

void Inet6AddressSerializationTest::main($StringArray* args) {
	$init(Inet6AddressSerializationTest);
	$useLocalCurrentObjectStackCache();
	if ($nc(args)->length != 0) {
		if ($nc(args->get(0))->equals("generate-loopback"_s)) {
			generateSerializedInet6AddressData($($Inet6Address::getByAddress($($nc($($InetAddress::getLoopbackAddress()))->getHostName()), Inet6AddressSerializationTest::LOOPBACKIPV6ADDRESS, Inet6AddressSerializationTest::LOOPBACK_SCOPE_ID)), $System::out, true);
		} else {
			generateAllInet6AddressSerializedData();
		}
	} else {
		runTests();
	}
}

void Inet6AddressSerializationTest::runTests() {
	$init(Inet6AddressSerializationTest);
	$useLocalCurrentObjectStackCache();
	$var($bytes, thisHostIPV6Address, nullptr);
	int32_t scope_id = Inet6AddressSerializationTest::LOOPBACK_SCOPE_ID;
	$nc($System::out)->println($$str({"Hostname: "_s, $($nc($($InetAddress::getLocalHost()))->getHostName())}));
	$nc($System::out)->println($$str({"LocalHost isLoopback : "_s, $$str($nc($($InetAddress::getLocalHost()))->isLoopbackAddress())}));
	$assign(thisHostIPV6Address, getThisHostIPV6Address($($nc($($InetAddress::getLocalHost()))->getHostName())));
	if (thisHostIPV6Address == nullptr) {
		$assign(thisHostIPV6Address, Inet6AddressSerializationTest::IN6ADDR_ANY_INIT);
	}
	testInet6AddressSerialization($($Inet6Address::getByAddress($($nc($($InetAddress::getLoopbackAddress()))->getHostName()), Inet6AddressSerializationTest::LOOPBACKIPV6ADDRESS, scope_id)), Inet6AddressSerializationTest::JDK7Inet6AddressSerialData);
	testInet6AddressSerialization($($Inet6Address::getByAddress($($nc($($InetAddress::getLoopbackAddress()))->getHostName()), Inet6AddressSerializationTest::LOOPBACKIPV6ADDRESS, scope_id)), Inet6AddressSerializationTest::JDK8Inet6AddressSerialData);
	testInet6AddressSerialization($($Inet6Address::getByAddress($($nc($($InetAddress::getLocalHost()))->getHostName()), Inet6AddressSerializationTest::IN6ADDR_ANY_INIT, scope_id)), nullptr);
	testInet6AddressSerialization($($Inet6Address::getByAddress($($nc($($InetAddress::getLocalHost()))->getHostName()), thisHostIPV6Address, scope_id)), nullptr);
	testAllNetworkInterfaces();
	testSerializedLo0Inet6Address();
	testSerializedE1000gInet6Address();
	if (Inet6AddressSerializationTest::failed) {
		$throwNew($RuntimeException, "Some tests failed, check output"_s);
	}
}

$bytes* Inet6AddressSerializationTest::getThisHostIPV6Address($String* hostName) {
	$init(Inet6AddressSerializationTest);
	$useLocalCurrentObjectStackCache();
	$var($InetAddressArray, thisHostIPAddresses, nullptr);
	try {
		$assign(thisHostIPAddresses, $InetAddress::getAllByName($($nc($($InetAddress::getLocalHost()))->getHostName())));
	} catch ($UnknownHostException& uhEx) {
		uhEx->printStackTrace();
		$throw(uhEx);
	}
	$var($bytes, thisHostIPV6Address, nullptr);
	{
		$var($InetAddressArray, arr$, thisHostIPAddresses);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($InetAddress, inetAddress, arr$->get(i$));
			{
				if ($instanceOf($Inet6Address, inetAddress)) {
					if ($nc($($nc(inetAddress)->getHostName()))->equals(hostName)) {
						$assign(thisHostIPV6Address, inetAddress->getAddress());
						break;
					}
				}
			}
		}
	}
	return thisHostIPV6Address;
}

void Inet6AddressSerializationTest::testAllNetworkInterfaces() {
	$init(Inet6AddressSerializationTest);
	$useLocalCurrentObjectStackCache();
	$nc($System::err)->println("\n testAllNetworkInterfaces: \n "_s);
	{
		$var($Enumeration, e, $NetworkInterface::getNetworkInterfaces());
		for (; $nc(e)->hasMoreElements();) {
			$var($NetworkInterface, netIF, $cast($NetworkInterface, e->nextElement()));
			if (Inet6AddressSerializationTest::isWindows) {
				$var($String, dName, $nc(netIF)->getDisplayName());
				if (dName != nullptr && dName->contains("Teredo"_s)) {
					continue;
				}
			}
			{
				$var($Enumeration, iadrs, $nc(netIF)->getInetAddresses());
				for (; $nc(iadrs)->hasMoreElements();) {
					$var($InetAddress, iadr, $cast($InetAddress, iadrs->nextElement()));
					if ($instanceOf($Inet6Address, iadr)) {
						$nc($System::err)->println($$str({"Test NetworkInterface:  "_s, netIF}));
						$var($Inet6Address, i6adr, $cast($Inet6Address, iadr));
						$nc($System::err)->println($$str({"Testing with "_s, iadr}));
						$nc($System::err)->println($$str({" scoped iface: "_s, $($nc(i6adr)->getScopedInterface())}));
						$nc($System::err)->println($$str({" hostname: "_s, $($nc(i6adr)->getHostName())}));
						testInet6AddressSerialization(i6adr, nullptr);
					}
				}
			}
		}
	}
}

void Inet6AddressSerializationTest::displayExpectedInet6Address($Inet6Address* expectedInet6Address) {
	$init(Inet6AddressSerializationTest);
	$useLocalCurrentObjectStackCache();
	$var($String, expectedHostName, $nc(expectedInet6Address)->getHostName());
	$var($bytes, expectedAddress, expectedInet6Address->getAddress());
	$var($String, expectedHostAddress, expectedInet6Address->getHostAddress());
	int32_t expectedScopeId = expectedInet6Address->getScopeId();
	$var($NetworkInterface, expectedNetIf, expectedInet6Address->getScopedInterface());
	$nc($System::err)->println($$str({"Excpected HostName: "_s, expectedHostName}));
	$nc($System::err)->println($$str({"Expected Address: "_s, $($Arrays::toString(expectedAddress))}));
	$nc($System::err)->println($$str({"Expected HostAddress: "_s, expectedHostAddress}));
	$nc($System::err)->println($$str({"Expected Scope Id "_s, $$str(expectedScopeId)}));
	$nc($System::err)->println($$str({"Expected NetworkInterface "_s, expectedNetIf}));
	$nc($System::err)->println($$str({"Expected Inet6Address "_s, expectedInet6Address}));
}

void Inet6AddressSerializationTest::testInet6AddressSerialization($Inet6Address* expectedInet6Address, $bytes* serializedAddress) {
	$init(Inet6AddressSerializationTest);
	$useLocalCurrentObjectStackCache();
	$nc($System::err)->println("\n testInet6AddressSerialization:  enter \n"_s);
	$var($bytes, serialData, serializedAddress != nullptr ? serializedAddress : generateSerializedInet6AddressData(expectedInet6Address, nullptr, false));
	try {
		$var($ByteArrayInputStream, bis, $new($ByteArrayInputStream, serialData));
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					$var($ObjectInputStream, oin, $new($ObjectInputStream, bis));
					{
						$var($Throwable, var$1, nullptr);
						try {
							try {
								$var($Inet6Address, deserializedIPV6Addr, $cast($Inet6Address, oin->readObject()));
								$nc($System::err)->println($$str({"Deserialized Inet6Address "_s, deserializedIPV6Addr}));
								$var($String, var$2, $nc(expectedInet6Address)->getHostName());
								assertHostNameEqual(var$2, $($nc(deserializedIPV6Addr)->getHostName()));
								$var($String, var$3, $nc(expectedInet6Address)->getHostAddress());
								assertHostAddressEqual(var$3, $($nc(deserializedIPV6Addr)->getHostAddress()));
								$var($bytes, var$4, $nc(expectedInet6Address)->getAddress());
								assertAddressEqual(var$4, $($nc(deserializedIPV6Addr)->getAddress()));
								int32_t var$5 = $nc(expectedInet6Address)->getScopeId();
								assertScopeIdEqual(var$5, $nc(deserializedIPV6Addr)->getScopeId());
								$var($NetworkInterface, var$6, $nc(expectedInet6Address)->getScopedInterface());
								assertNetworkInterfaceEqual(var$6, $($nc(deserializedIPV6Addr)->getScopedInterface()));
							} catch ($Throwable& t$) {
								try {
									oin->close();
								} catch ($Throwable& x2) {
									t$->addSuppressed(x2);
								}
								$throw(t$);
							}
						} catch ($Throwable& var$7) {
							$assign(var$1, var$7);
						} /*finally*/ {
							oin->close();
						}
						if (var$1 != nullptr) {
							$throw(var$1);
						}
					}
				} catch ($Throwable& t$) {
					try {
						bis->close();
					} catch ($Throwable& x2) {
						t$->addSuppressed(x2);
					}
					$throw(t$);
				}
			} catch ($Throwable& var$8) {
				$assign(var$0, var$8);
			} /*finally*/ {
				bis->close();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	} catch ($Exception& e) {
		$nc($System::err)->println("Exception caught during deserialization"_s);
		Inet6AddressSerializationTest::failed = true;
		e->printStackTrace();
	}
}

void Inet6AddressSerializationTest::testSerializedE1000gInet6Address() {
	$init(Inet6AddressSerializationTest);
	$useLocalCurrentObjectStackCache();
	$nc($System::err)->println("\n testSerializedE1000gInet6Address:  enter \n"_s);
	bool testWithNetIf = true;
	bool useMockInet6Address = false;
	$var($NetworkInterface, testNetIf, $NetworkInterface::getByName(Inet6AddressSerializationTest::NETWORK_IF_E1000G0));
	$var($Inet6Address, expectedInet6Address, nullptr);
	if (testNetIf != nullptr) {
		$nc($System::err)->println("\n testSerializedE1000gInet6Address:  using netif \n"_s);
		try {
			$assign(expectedInet6Address, $Inet6Address::getByAddress(Inet6AddressSerializationTest::E1000G0HOSTNAME, Inet6AddressSerializationTest::E1000G0IPV6ADDRESS, testNetIf));
		} catch ($UnknownHostException& ukhEx) {
			ukhEx->printStackTrace();
			testWithNetIf = true;
			useMockInet6Address = true;
		}
	} else {
		$nc($System::err)->println("\n testSerializedE1000gInet6Address:  using index \n"_s);
		try {
			$assign(expectedInet6Address, $Inet6Address::getByAddress(Inet6AddressSerializationTest::E1000G0HOSTNAME, Inet6AddressSerializationTest::E1000G0IPV6ADDRESS, Inet6AddressSerializationTest::SCOPE_ID_ZERO));
		} catch ($UnknownHostException& ukhEx1) {
			ukhEx1->printStackTrace();
			useMockInet6Address = true;
		}
		testWithNetIf = false;
	}
	$var($bytes, serializedAddress, Inet6AddressSerializationTest::SerialData_ifname_e1000g0);
	try {
		$var($ByteArrayInputStream, bis, $new($ByteArrayInputStream, serializedAddress));
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					$var($ObjectInputStream, oin, $new($ObjectInputStream, bis));
					{
						$var($Throwable, var$1, nullptr);
						try {
							try {
								$var($Inet6Address, deserializedIPV6Addr, $cast($Inet6Address, oin->readObject()));
								$nc($System::err)->println($$str({"Deserialized Inet6Address "_s, deserializedIPV6Addr}));
								if (!useMockInet6Address) {
									$var($String, var$2, $nc(expectedInet6Address)->getHostName());
									assertHostNameEqual(var$2, $($nc(deserializedIPV6Addr)->getHostName()));
									if (testWithNetIf) {
										$var($String, var$3, $nc(expectedInet6Address)->getHostAddress());
										assertHostAddressEqual(var$3, $($nc(deserializedIPV6Addr)->getHostAddress()));
									} else {
										$var($String, var$4, $MockE1000g0Inet6Address::getBareHostAddress());
										assertHostAddressEqual(var$4, $($nc(deserializedIPV6Addr)->getHostAddress()));
									}
									$var($bytes, var$5, $nc(expectedInet6Address)->getAddress());
									assertAddressEqual(var$5, $($nc(deserializedIPV6Addr)->getAddress()));
									int32_t var$6 = $nc(expectedInet6Address)->getScopeId();
									assertScopeIdEqual(var$6, $nc(deserializedIPV6Addr)->getScopeId());
									if (testWithNetIf) {
										$var($NetworkInterface, var$7, $nc(expectedInet6Address)->getScopedInterface());
										assertNetworkInterfaceEqual(var$7, $($nc(deserializedIPV6Addr)->getScopedInterface()));
									} else {
										assertNetworkInterfaceEqual(nullptr, $($nc(deserializedIPV6Addr)->getScopedInterface()));
									}
								} else {
									$var($String, var$8, $MockE1000g0Inet6Address::getHostName());
									assertHostNameEqual(var$8, $($nc(deserializedIPV6Addr)->getHostName()));
									if (testWithNetIf) {
										$var($String, var$9, $MockE1000g0Inet6Address::getHostAddress());
										assertHostAddressEqual(var$9, $($nc(deserializedIPV6Addr)->getHostAddress()));
									} else {
										$var($String, var$10, $MockE1000g0Inet6Address::getHostAddressWithIndex());
										assertHostAddressEqual(var$10, $($nc(deserializedIPV6Addr)->getHostAddress()));
									}
									$var($bytes, var$11, $MockE1000g0Inet6Address::getAddress());
									assertAddressEqual(var$11, $($nc(deserializedIPV6Addr)->getAddress()));
									if (testWithNetIf) {
										int32_t var$12 = $MockE1000g0Inet6Address::getScopeId();
										assertScopeIdEqual(var$12, $nc(deserializedIPV6Addr)->getScopeId());
									} else {
										int32_t var$13 = $MockE1000g0Inet6Address::getScopeZero();
										assertScopeIdEqual(var$13, $nc(deserializedIPV6Addr)->getScopeId());
									}
									$var($String, var$14, $MockE1000g0Inet6Address::getScopeIfName());
									assertNetworkInterfaceNameEqual(var$14, $($nc(deserializedIPV6Addr)->getScopedInterface()));
								}
							} catch ($Throwable& t$) {
								try {
									oin->close();
								} catch ($Throwable& x2) {
									t$->addSuppressed(x2);
								}
								$throw(t$);
							}
						} catch ($Throwable& var$15) {
							$assign(var$1, var$15);
						} /*finally*/ {
							oin->close();
						}
						if (var$1 != nullptr) {
							$throw(var$1);
						}
					}
				} catch ($Throwable& t$) {
					try {
						bis->close();
					} catch ($Throwable& x2) {
						t$->addSuppressed(x2);
					}
					$throw(t$);
				}
			} catch ($Throwable& var$16) {
				$assign(var$0, var$16);
			} /*finally*/ {
				bis->close();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	} catch ($Exception& e) {
		$nc($System::err)->println("Exception caught during deserialization"_s);
		Inet6AddressSerializationTest::failed = true;
		e->printStackTrace();
	}
}

void Inet6AddressSerializationTest::testSerializedLo0Inet6Address() {
	$init(Inet6AddressSerializationTest);
	$useLocalCurrentObjectStackCache();
	$nc($System::err)->println("\n testSerializedLo0Inet6Address:  enter \n"_s);
	bool testWithNetIf = true;
	bool useMockInet6Address = false;
	$var($NetworkInterface, testNetIf, $NetworkInterface::getByName(Inet6AddressSerializationTest::NETWORK_IF_LO0));
	$var($Inet6Address, expectedInet6Address, nullptr);
	if (testNetIf != nullptr) {
		$nc($System::err)->println("\n testSerializedLo0Inet6Address:  using netif \n"_s);
		try {
			$assign(expectedInet6Address, $Inet6Address::getByAddress(Inet6AddressSerializationTest::LOCALHOSTNAME, Inet6AddressSerializationTest::LOOPBACKIPV6ADDRESS, testNetIf));
		} catch ($UnknownHostException& ukhEx) {
			ukhEx->printStackTrace();
			testWithNetIf = true;
			useMockInet6Address = true;
		}
	} else {
		$nc($System::err)->println("\n testSerializedLo0Inet6Address:  using index \n"_s);
		try {
			$assign(expectedInet6Address, $Inet6Address::getByAddress(Inet6AddressSerializationTest::LOCALHOSTNAME, Inet6AddressSerializationTest::LOOPBACKIPV6ADDRESS, Inet6AddressSerializationTest::SCOPE_ID_ZERO));
		} catch ($UnknownHostException& ukhEx1) {
			ukhEx1->printStackTrace();
			useMockInet6Address = true;
		}
		testWithNetIf = false;
	}
	$var($bytes, serializedAddress, Inet6AddressSerializationTest::SerialData_ifname_lo0);
	try {
		$var($ByteArrayInputStream, bis, $new($ByteArrayInputStream, serializedAddress));
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					$var($ObjectInputStream, oin, $new($ObjectInputStream, bis));
					{
						$var($Throwable, var$1, nullptr);
						try {
							try {
								$var($Inet6Address, deserializedIPV6Addr, $cast($Inet6Address, oin->readObject()));
								$nc($System::err)->println($$str({"Deserialized Inet6Address "_s, deserializedIPV6Addr}));
								if (!useMockInet6Address) {
									$var($String, var$2, $nc(expectedInet6Address)->getHostName());
									assertHostNameEqual(var$2, $($nc(deserializedIPV6Addr)->getHostName()));
									if (testWithNetIf) {
										$var($String, var$3, $nc(expectedInet6Address)->getHostAddress());
										assertHostAddressEqual(var$3, $($nc(deserializedIPV6Addr)->getHostAddress()));
									} else {
										$var($String, var$4, $MockLo0Inet6Address::getBareHostAddress());
										assertHostAddressEqual(var$4, $($nc(deserializedIPV6Addr)->getHostAddress()));
									}
									$var($bytes, var$5, $nc(expectedInet6Address)->getAddress());
									assertAddressEqual(var$5, $($nc(deserializedIPV6Addr)->getAddress()));
									int32_t var$6 = $nc(expectedInet6Address)->getScopeId();
									assertScopeIdEqual(var$6, $nc(deserializedIPV6Addr)->getScopeId());
									if (testWithNetIf) {
										$var($NetworkInterface, var$7, $nc(expectedInet6Address)->getScopedInterface());
										assertNetworkInterfaceEqual(var$7, $($nc(deserializedIPV6Addr)->getScopedInterface()));
									} else {
										assertNetworkInterfaceEqual(nullptr, $($nc(deserializedIPV6Addr)->getScopedInterface()));
									}
								} else {
									$var($String, var$8, $MockLo0Inet6Address::getHostName());
									assertHostNameEqual(var$8, $($nc(deserializedIPV6Addr)->getHostName()));
									if (testWithNetIf) {
										$var($String, var$9, $MockLo0Inet6Address::getHostAddress());
										assertHostAddressEqual(var$9, $($nc(deserializedIPV6Addr)->getHostAddress()));
									} else {
										$var($String, var$10, $MockLo0Inet6Address::getHostAddressWithIndex());
										assertHostAddressEqual(var$10, $($nc(deserializedIPV6Addr)->getHostAddress()));
									}
									$var($bytes, var$11, $MockLo0Inet6Address::getAddress());
									assertAddressEqual(var$11, $($nc(deserializedIPV6Addr)->getAddress()));
									if (testWithNetIf) {
										int32_t var$12 = $MockLo0Inet6Address::getScopeId();
										assertScopeIdEqual(var$12, $nc(deserializedIPV6Addr)->getScopeId());
									} else {
										int32_t var$13 = $MockLo0Inet6Address::getScopeZero();
										assertScopeIdEqual(var$13, $nc(deserializedIPV6Addr)->getScopeId());
									}
									$var($String, var$14, $MockLo0Inet6Address::getScopeIfName());
									assertNetworkInterfaceNameEqual(var$14, $($nc(deserializedIPV6Addr)->getScopedInterface()));
								}
							} catch ($Throwable& t$) {
								try {
									oin->close();
								} catch ($Throwable& x2) {
									t$->addSuppressed(x2);
								}
								$throw(t$);
							}
						} catch ($Throwable& var$15) {
							$assign(var$1, var$15);
						} /*finally*/ {
							oin->close();
						}
						if (var$1 != nullptr) {
							$throw(var$1);
						}
					}
				} catch ($Throwable& t$) {
					try {
						bis->close();
					} catch ($Throwable& x2) {
						t$->addSuppressed(x2);
					}
					$throw(t$);
				}
			} catch ($Throwable& var$16) {
				$assign(var$0, var$16);
			} /*finally*/ {
				bis->close();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	} catch ($Exception& e) {
		$nc($System::err)->println("Exception caught during deserialization"_s);
		Inet6AddressSerializationTest::failed = true;
		e->printStackTrace();
	}
}

$List* Inet6AddressSerializationTest::getAllInet6Addresses() {
	$init(Inet6AddressSerializationTest);
	$useLocalCurrentObjectStackCache();
	$var($ArrayList, inet6Addresses, $new($ArrayList));
	{
		$var($Enumeration, e, $NetworkInterface::getNetworkInterfaces());
		for (; $nc(e)->hasMoreElements();) {
			$var($NetworkInterface, netIF, $cast($NetworkInterface, e->nextElement()));
			{
				$var($Enumeration, iadrs, $nc(netIF)->getInetAddresses());
				for (; $nc(iadrs)->hasMoreElements();) {
					$var($InetAddress, iadr, $cast($InetAddress, iadrs->nextElement()));
					if ($instanceOf($Inet6Address, iadr)) {
						$nc($System::err)->println($$str({"Test NetworkInterface:  "_s, netIF}));
						$var($Inet6Address, i6adr, $cast($Inet6Address, iadr));
						$nc($System::err)->println($$str({" address "_s, iadr}));
						$nc($System::err)->println($$str({" scoped iface: "_s, $($nc(i6adr)->getScopedInterface())}));
						$nc($System::err)->println($$str({" hostName: "_s, $($nc(i6adr)->getHostName())}));
						inet6Addresses->add(i6adr);
					}
				}
			}
		}
	}
	return inet6Addresses;
}

void Inet6AddressSerializationTest::assertHostNameEqual($String* expectedHostName, $String* deserializedHostName) {
	$init(Inet6AddressSerializationTest);
	$useLocalCurrentObjectStackCache();
	$nc($System::err)->println("Inet6AddressSerializationTest.assertHostNameEqual:"_s);
	if (expectedHostName == nullptr) {
		if (deserializedHostName == nullptr) {
		} else {
			$nc($System::err)->println($$str({"Error checking  HostName, expected:"_s, expectedHostName, ", got :"_s, deserializedHostName}));
			Inet6AddressSerializationTest::failed = true;
		}
	} else if (!$nc(expectedHostName)->equals(deserializedHostName)) {
		$nc($System::err)->println($$str({"Error checking  HostName, expected:"_s, expectedHostName, ", got :"_s, deserializedHostName}));
		Inet6AddressSerializationTest::failed = true;
	} else {
		$nc($System::err)->println($$str({"HostName equality  HostName, expected:"_s, expectedHostName, ", got :"_s, deserializedHostName}));
	}
}

void Inet6AddressSerializationTest::assertHostAddressEqual($String* expectedHostAddress, $String* deserializedHostAddress) {
	$init(Inet6AddressSerializationTest);
	$useLocalCurrentObjectStackCache();
	$nc($System::err)->println("Inet6AddressSerializationTest.assertHostAddressEqual:"_s);
	if (expectedHostAddress == nullptr) {
		if (deserializedHostAddress == nullptr) {
		} else {
			$nc($System::err)->println($$str({"Error checking  HostAddress, expected: "_s, expectedHostAddress, ", got: "_s, deserializedHostAddress}));
			Inet6AddressSerializationTest::failed = true;
		}
	} else if (!$nc(expectedHostAddress)->equals(deserializedHostAddress)) {
		$nc($System::err)->println($$str({"Error checking  HostAddress, expected: "_s, expectedHostAddress, ", got: "_s, deserializedHostAddress}));
		Inet6AddressSerializationTest::failed = true;
	} else {
		$nc($System::err)->println($$str({"HostAddress equality  HostAddress, expected: "_s, expectedHostAddress, ", got: "_s, deserializedHostAddress}));
	}
}

void Inet6AddressSerializationTest::assertAddressEqual($bytes* expectedAddress, $bytes* deserializedAddress) {
	$init(Inet6AddressSerializationTest);
	$useLocalCurrentObjectStackCache();
	$nc($System::err)->println("Inet6AddressSerializationTest.assertAddressEqual:"_s);
	if (expectedAddress == nullptr) {
		if (deserializedAddress == nullptr) {
		} else {
			$var($String, var$0, $$str({"Error checking  Address, expected:"_s, $($Arrays::toString(expectedAddress)), ", got: "_s}));
			$nc($System::err)->println($$concat(var$0, $($Arrays::toString(deserializedAddress))));
			Inet6AddressSerializationTest::failed = true;
		}
	} else if (!$Arrays::equals(expectedAddress, deserializedAddress)) {
		$var($String, var$1, $$str({"Error checking  Address, expected: "_s, $($Arrays::toString(expectedAddress)), ", got: "_s}));
		$nc($System::err)->println($$concat(var$1, $($Arrays::toString(deserializedAddress))));
		Inet6AddressSerializationTest::failed = true;
	} else {
		$var($String, var$2, $$str({"Address equality  Address, expected: "_s, $($Arrays::toString(expectedAddress)), ", got: "_s}));
		$nc($System::err)->println($$concat(var$2, $($Arrays::toString(deserializedAddress))));
	}
}

void Inet6AddressSerializationTest::assertScopeIdEqual(int32_t expectedScopeId, int32_t deserializedScopeId) {
	$init(Inet6AddressSerializationTest);
	$useLocalCurrentObjectStackCache();
	$nc($System::err)->println("Inet6AddressSerializationTest.assertScopeIdEqual:"_s);
	if (expectedScopeId != deserializedScopeId) {
		$nc($System::err)->println($$str({"Error checking  ScopeId, expected:"_s, $$str(expectedScopeId), ", got: "_s, $$str(deserializedScopeId)}));
		Inet6AddressSerializationTest::failed = true;
	} else {
		$nc($System::err)->println($$str({"ScopeId equality  ScopeId, expected: "_s, $$str(expectedScopeId), ", got: "_s, $$str(deserializedScopeId)}));
	}
}

void Inet6AddressSerializationTest::assertNetworkInterfaceNameEqual($String* expectedNetworkIfName, $NetworkInterface* deserializedNetworkInterface) {
	$init(Inet6AddressSerializationTest);
	$useLocalCurrentObjectStackCache();
	if (deserializedNetworkInterface != nullptr) {
		$var($String, deserializedNetworkIfName, deserializedNetworkInterface->getName());
		$nc($System::err)->println("Inet6AddressSerializationTest.assertHostNameEqual:"_s);
		if (expectedNetworkIfName == nullptr) {
			if (deserializedNetworkIfName == nullptr) {
			} else {
				$nc($System::err)->println($$str({"Error checking  NetworkIfName, expected: "_s, expectedNetworkIfName, ", got: "_s, deserializedNetworkIfName}));
				Inet6AddressSerializationTest::failed = true;
			}
		} else if (!$nc(expectedNetworkIfName)->equals(deserializedNetworkIfName)) {
			$nc($System::err)->println($$str({"Error checking  NetworkIfName, expected: "_s, expectedNetworkIfName, ", got: "_s, deserializedNetworkIfName}));
			Inet6AddressSerializationTest::failed = true;
		} else {
			$nc($System::err)->println($$str({"NetworkIfName equality  NetworkIfName, expected: "_s, expectedNetworkIfName, ", got: "_s, deserializedNetworkIfName}));
		}
	} else {
		$nc($System::err)->println("Warning  NetworkInterface  expected, but is null - ifname not relevant on deserializing host"_s);
	}
}

void Inet6AddressSerializationTest::assertNetworkInterfaceEqual($NetworkInterface* expectedNetworkInterface, $NetworkInterface* deserializedNetworkInterface) {
	$init(Inet6AddressSerializationTest);
	$useLocalCurrentObjectStackCache();
	$nc($System::err)->println("Inet6AddressSerializationTest.assertNetworkInterfaceEqual:"_s);
	if (expectedNetworkInterface == nullptr) {
		if (deserializedNetworkInterface == nullptr) {
			$nc($System::err)->println($$str({"Network Interface equality  NetworkInterface, expected:"_s, expectedNetworkInterface, ", got :"_s, deserializedNetworkInterface}));
		} else {
			$nc($System::err)->println($$str({"Error checking  NetworkInterface, expected:"_s, expectedNetworkInterface, ", got :"_s, deserializedNetworkInterface}));
			Inet6AddressSerializationTest::failed = true;
		}
	} else if (!$nc(expectedNetworkInterface)->equals(deserializedNetworkInterface)) {
		$nc($System::err)->println($$str({"Error checking  NetworkInterface, expected:"_s, expectedNetworkInterface, ", got :"_s, deserializedNetworkInterface}));
		Inet6AddressSerializationTest::failed = true;
	} else {
		$nc($System::err)->println($$str({"Network Interface equality  NetworkInterface, expected:"_s, expectedNetworkInterface, ", got :"_s, deserializedNetworkInterface}));
	}
}

void Inet6AddressSerializationTest::equal(Object$* expected, Object$* got) {
	$init(Inet6AddressSerializationTest);
	$useLocalCurrentObjectStackCache();
	if (expected == nullptr) {
		if (got == nullptr) {
		} else {
			$nc($System::err)->println($$str({"Error checking  serial data, expected:"_s, expected, ", got :"_s, got}));
			Inet6AddressSerializationTest::failed = true;
		}
	} else if (!$nc($of(expected))->equals(got)) {
		$nc($System::err)->println($$str({"Error checking  serial data, expected:"_s, expected, ", got :"_s, got}));
		Inet6AddressSerializationTest::failed = true;
	}
}

$bytes* Inet6AddressSerializationTest::generateSerializedInet6AddressData($Inet6Address* addr, $PrintStream* out, bool outputToFile) {
	$init(Inet6AddressSerializationTest);
	$useLocalCurrentObjectStackCache();
	$var($ByteArrayOutputStream, bos, $new($ByteArrayOutputStream));
	{
		$var($ObjectOutputStream, oos, $new($ObjectOutputStream, bos));
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					oos->writeObject(addr);
				} catch ($Throwable& t$) {
					try {
						oos->close();
					} catch ($Throwable& x2) {
						t$->addSuppressed(x2);
					}
					$throw(t$);
				}
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				oos->close();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
	$var($String, ifname, getIfName(addr));
	$var($bytes, ba, bos->toByteArray());
	if (out != nullptr) {
		out->format($$str({"static final byte[] SerialData"_s, ifname, " = {\n"_s}), $$new($ObjectArray, 0));
		for (int32_t i = 0; i < $nc(ba)->length; ++i) {
			out->format(" (byte)0x%02X"_s, $$new($ObjectArray, {$($of($Byte::valueOf(ba->get(i))))}));
			if (i != (ba->length - 1)) {
				out->format(","_s, $$new($ObjectArray, 0));
			}
			if (((i + 1) % 6) == 0) {
				out->format("\n"_s, $$new($ObjectArray, 0));
			}
		}
		out->format(" };\n \n"_s, $$new($ObjectArray, 0));
	}
	if (outputToFile) {
		serializeInet6AddressToFile(addr);
	}
	return ba;
}

$String* Inet6AddressSerializationTest::getIfName($Inet6Address* inet6Addr) {
	$init(Inet6AddressSerializationTest);
	$useLocalCurrentObjectStackCache();
	$var($String, ifname, nullptr);
	if ($nc(inet6Addr)->getScopedInterface() != nullptr) {
		$assign(ifname, $str({"_ifname_"_s, $($nc($(inet6Addr->getScopedInterface()))->getName())}));
	} else {
		$assign(ifname, $str({"_ifname_"_s, $($nc($($Integer::valueOf(inet6Addr->getScopeId())))->toString())}));
	}
	return ifname;
}

void Inet6AddressSerializationTest::generateAllInet6AddressSerializedData() {
	$init(Inet6AddressSerializationTest);
	$useLocalCurrentObjectStackCache();
	$var($List, inet6Addresses, nullptr);
	try {
		$assign(inet6Addresses, getAllInet6Addresses());
	} catch ($Exception& e) {
		e->printStackTrace();
		$throwNew($IOException, static_cast<$Throwable*>(e));
	}
	{
		$var($Iterator, i$, $nc(inet6Addresses)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Inet6Address, inet6Address, $cast($Inet6Address, i$->next()));
			{
				generateSerializedInet6AddressData(inet6Address, $System::out, true);
			}
		}
	}
}

void Inet6AddressSerializationTest::serializeInet6AddressToFile($Inet6Address* inet6Addr) {
	$init(Inet6AddressSerializationTest);
	$useLocalCurrentObjectStackCache();
	$var($FileOutputStream, fOut, nullptr);
	$var($String, inet6AddressOutputFilename, nullptr);
	$assign(inet6AddressOutputFilename, createOutputFileName(inet6Addr));
	try {
		$assign(fOut, $new($FileOutputStream, inet6AddressOutputFilename));
	} catch ($FileNotFoundException& fnfEx) {
		fnfEx->printStackTrace();
	}
	$var($ObjectOutputStream, ooStream, nullptr);
	try {
		if (fOut != nullptr) {
			$assign(ooStream, $new($ObjectOutputStream, fOut));
		} else {
			$nc($System::err)->println("Problem initilising Object output stream "_s);
			$System::exit(-1);
		}
	} catch ($IOException& e) {
		e->printStackTrace();
		$System::exit(-1);
	}
	try {
		$nc(ooStream)->writeObject(inet6Addr);
	} catch ($Exception& ex) {
		ex->printStackTrace();
		$System::exit(-1);
	}
	try {
		$nc(ooStream)->close();
	} catch ($IOException& e) {
		e->printStackTrace();
	}
}

$String* Inet6AddressSerializationTest::createOutputFileName($Inet6Address* inet6Addr) {
	$init(Inet6AddressSerializationTest);
	$useLocalCurrentObjectStackCache();
	$var($String, inet6AddressOutputFilename, nullptr);
	if ($nc(inet6Addr)->getScopedInterface() != nullptr) {
		$assign(inet6AddressOutputFilename, $str({"IPV6Address_"_s, $($nc($(inet6Addr->getScopedInterface()))->getName()), ".out"_s}));
	} else {
		$assign(inet6AddressOutputFilename, $str({"IPV6Address_"_s, $($nc($($Integer::valueOf(inet6Addr->getScopeId())))->toString()), ".out"_s}));
	}
	return inet6AddressOutputFilename;
}

void clinit$Inet6AddressSerializationTest($Class* class$) {
	$assignStatic(Inet6AddressSerializationTest::E1000G0HOSTNAME, "fe80:0:0:0:21b:24ff:febd:f29c%e1000g0"_s);
	$assignStatic(Inet6AddressSerializationTest::LOCALHOSTNAME, "localhost"_s);
	$assignStatic(Inet6AddressSerializationTest::NETWORK_IF_E1000G0, "e1000g0"_s);
	$assignStatic(Inet6AddressSerializationTest::NETWORK_IF_LO0, "lo0"_s);
	Inet6AddressSerializationTest::isWindows = $nc($($System::getProperty("os.name"_s)))->startsWith("Windows"_s);
	$assignStatic(Inet6AddressSerializationTest::IN6ADDR_ANY_INIT, $new($bytes, {
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0
	}));
	$assignStatic(Inet6AddressSerializationTest::LOOPBACKIPV6ADDRESS, $new($bytes, {
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)1
	}));
	$assignStatic(Inet6AddressSerializationTest::E1000G0IPV6ADDRESS, $new($bytes, {
		(int8_t)254,
		(int8_t)128,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)2,
		(int8_t)27,
		(int8_t)36,
		(int8_t)255,
		(int8_t)254,
		(int8_t)189,
		(int8_t)242,
		(int8_t)156
	}));
	$assignStatic(Inet6AddressSerializationTest::JDK7Inet6AddressSerialData, $new($bytes, {
		(int8_t)172,
		(int8_t)237,
		(int8_t)0,
		(int8_t)5,
		(int8_t)115,
		(int8_t)114,
		(int8_t)0,
		(int8_t)21,
		(int8_t)106,
		(int8_t)97,
		(int8_t)118,
		(int8_t)97,
		(int8_t)46,
		(int8_t)110,
		(int8_t)101,
		(int8_t)116,
		(int8_t)46,
		(int8_t)73,
		(int8_t)110,
		(int8_t)101,
		(int8_t)116,
		(int8_t)54,
		(int8_t)65,
		(int8_t)100,
		(int8_t)100,
		(int8_t)114,
		(int8_t)101,
		(int8_t)115,
		(int8_t)115,
		(int8_t)95,
		(int8_t)124,
		(int8_t)32,
		(int8_t)129,
		(int8_t)82,
		(int8_t)44,
		(int8_t)128,
		(int8_t)33,
		(int8_t)3,
		(int8_t)0,
		(int8_t)5,
		(int8_t)73,
		(int8_t)0,
		(int8_t)8,
		(int8_t)115,
		(int8_t)99,
		(int8_t)111,
		(int8_t)112,
		(int8_t)101,
		(int8_t)95,
		(int8_t)105,
		(int8_t)100,
		(int8_t)90,
		(int8_t)0,
		(int8_t)12,
		(int8_t)115,
		(int8_t)99,
		(int8_t)111,
		(int8_t)112,
		(int8_t)101,
		(int8_t)95,
		(int8_t)105,
		(int8_t)100,
		(int8_t)95,
		(int8_t)115,
		(int8_t)101,
		(int8_t)116,
		(int8_t)90,
		(int8_t)0,
		(int8_t)16,
		(int8_t)115,
		(int8_t)99,
		(int8_t)111,
		(int8_t)112,
		(int8_t)101,
		(int8_t)95,
		(int8_t)105,
		(int8_t)102,
		(int8_t)110,
		(int8_t)97,
		(int8_t)109,
		(int8_t)101,
		(int8_t)95,
		(int8_t)115,
		(int8_t)101,
		(int8_t)116,
		(int8_t)76,
		(int8_t)0,
		(int8_t)6,
		(int8_t)105,
		(int8_t)102,
		(int8_t)110,
		(int8_t)97,
		(int8_t)109,
		(int8_t)101,
		(int8_t)116,
		(int8_t)0,
		(int8_t)18,
		(int8_t)76,
		(int8_t)106,
		(int8_t)97,
		(int8_t)118,
		(int8_t)97,
		(int8_t)47,
		(int8_t)108,
		(int8_t)97,
		(int8_t)110,
		(int8_t)103,
		(int8_t)47,
		(int8_t)83,
		(int8_t)116,
		(int8_t)114,
		(int8_t)105,
		(int8_t)110,
		(int8_t)103,
		(int8_t)59,
		(int8_t)91,
		(int8_t)0,
		(int8_t)9,
		(int8_t)105,
		(int8_t)112,
		(int8_t)97,
		(int8_t)100,
		(int8_t)100,
		(int8_t)114,
		(int8_t)101,
		(int8_t)115,
		(int8_t)115,
		(int8_t)116,
		(int8_t)0,
		(int8_t)2,
		(int8_t)91,
		(int8_t)66,
		(int8_t)120,
		(int8_t)114,
		(int8_t)0,
		(int8_t)20,
		(int8_t)106,
		(int8_t)97,
		(int8_t)118,
		(int8_t)97,
		(int8_t)46,
		(int8_t)110,
		(int8_t)101,
		(int8_t)116,
		(int8_t)46,
		(int8_t)73,
		(int8_t)110,
		(int8_t)101,
		(int8_t)116,
		(int8_t)65,
		(int8_t)100,
		(int8_t)100,
		(int8_t)114,
		(int8_t)101,
		(int8_t)115,
		(int8_t)115,
		(int8_t)45,
		(int8_t)155,
		(int8_t)87,
		(int8_t)175,
		(int8_t)159,
		(int8_t)227,
		(int8_t)235,
		(int8_t)219,
		(int8_t)2,
		(int8_t)0,
		(int8_t)3,
		(int8_t)73,
		(int8_t)0,
		(int8_t)7,
		(int8_t)97,
		(int8_t)100,
		(int8_t)100,
		(int8_t)114,
		(int8_t)101,
		(int8_t)115,
		(int8_t)115,
		(int8_t)73,
		(int8_t)0,
		(int8_t)6,
		(int8_t)102,
		(int8_t)97,
		(int8_t)109,
		(int8_t)105,
		(int8_t)108,
		(int8_t)121,
		(int8_t)76,
		(int8_t)0,
		(int8_t)8,
		(int8_t)104,
		(int8_t)111,
		(int8_t)115,
		(int8_t)116,
		(int8_t)78,
		(int8_t)97,
		(int8_t)109,
		(int8_t)101,
		(int8_t)113,
		(int8_t)0,
		(int8_t)126,
		(int8_t)0,
		(int8_t)1,
		(int8_t)120,
		(int8_t)112,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)2,
		(int8_t)116,
		(int8_t)0,
		(int8_t)9,
		(int8_t)108,
		(int8_t)111,
		(int8_t)99,
		(int8_t)97,
		(int8_t)108,
		(int8_t)104,
		(int8_t)111,
		(int8_t)115,
		(int8_t)116,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)1,
		(int8_t)0,
		(int8_t)112,
		(int8_t)117,
		(int8_t)114,
		(int8_t)0,
		(int8_t)2,
		(int8_t)91,
		(int8_t)66,
		(int8_t)172,
		(int8_t)243,
		(int8_t)23,
		(int8_t)248,
		(int8_t)6,
		(int8_t)8,
		(int8_t)84,
		(int8_t)224,
		(int8_t)2,
		(int8_t)0,
		(int8_t)0,
		(int8_t)120,
		(int8_t)112,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)16,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)1,
		(int8_t)120
	}));
	$assignStatic(Inet6AddressSerializationTest::JDK8Inet6AddressSerialData, $new($bytes, {
		(int8_t)172,
		(int8_t)237,
		(int8_t)0,
		(int8_t)5,
		(int8_t)115,
		(int8_t)114,
		(int8_t)0,
		(int8_t)21,
		(int8_t)106,
		(int8_t)97,
		(int8_t)118,
		(int8_t)97,
		(int8_t)46,
		(int8_t)110,
		(int8_t)101,
		(int8_t)116,
		(int8_t)46,
		(int8_t)73,
		(int8_t)110,
		(int8_t)101,
		(int8_t)116,
		(int8_t)54,
		(int8_t)65,
		(int8_t)100,
		(int8_t)100,
		(int8_t)114,
		(int8_t)101,
		(int8_t)115,
		(int8_t)115,
		(int8_t)95,
		(int8_t)124,
		(int8_t)32,
		(int8_t)129,
		(int8_t)82,
		(int8_t)44,
		(int8_t)128,
		(int8_t)33,
		(int8_t)3,
		(int8_t)0,
		(int8_t)5,
		(int8_t)73,
		(int8_t)0,
		(int8_t)8,
		(int8_t)115,
		(int8_t)99,
		(int8_t)111,
		(int8_t)112,
		(int8_t)101,
		(int8_t)95,
		(int8_t)105,
		(int8_t)100,
		(int8_t)90,
		(int8_t)0,
		(int8_t)12,
		(int8_t)115,
		(int8_t)99,
		(int8_t)111,
		(int8_t)112,
		(int8_t)101,
		(int8_t)95,
		(int8_t)105,
		(int8_t)100,
		(int8_t)95,
		(int8_t)115,
		(int8_t)101,
		(int8_t)116,
		(int8_t)90,
		(int8_t)0,
		(int8_t)16,
		(int8_t)115,
		(int8_t)99,
		(int8_t)111,
		(int8_t)112,
		(int8_t)101,
		(int8_t)95,
		(int8_t)105,
		(int8_t)102,
		(int8_t)110,
		(int8_t)97,
		(int8_t)109,
		(int8_t)101,
		(int8_t)95,
		(int8_t)115,
		(int8_t)101,
		(int8_t)116,
		(int8_t)76,
		(int8_t)0,
		(int8_t)6,
		(int8_t)105,
		(int8_t)102,
		(int8_t)110,
		(int8_t)97,
		(int8_t)109,
		(int8_t)101,
		(int8_t)116,
		(int8_t)0,
		(int8_t)18,
		(int8_t)76,
		(int8_t)106,
		(int8_t)97,
		(int8_t)118,
		(int8_t)97,
		(int8_t)47,
		(int8_t)108,
		(int8_t)97,
		(int8_t)110,
		(int8_t)103,
		(int8_t)47,
		(int8_t)83,
		(int8_t)116,
		(int8_t)114,
		(int8_t)105,
		(int8_t)110,
		(int8_t)103,
		(int8_t)59,
		(int8_t)91,
		(int8_t)0,
		(int8_t)9,
		(int8_t)105,
		(int8_t)112,
		(int8_t)97,
		(int8_t)100,
		(int8_t)100,
		(int8_t)114,
		(int8_t)101,
		(int8_t)115,
		(int8_t)115,
		(int8_t)116,
		(int8_t)0,
		(int8_t)2,
		(int8_t)91,
		(int8_t)66,
		(int8_t)120,
		(int8_t)114,
		(int8_t)0,
		(int8_t)20,
		(int8_t)106,
		(int8_t)97,
		(int8_t)118,
		(int8_t)97,
		(int8_t)46,
		(int8_t)110,
		(int8_t)101,
		(int8_t)116,
		(int8_t)46,
		(int8_t)73,
		(int8_t)110,
		(int8_t)101,
		(int8_t)116,
		(int8_t)65,
		(int8_t)100,
		(int8_t)100,
		(int8_t)114,
		(int8_t)101,
		(int8_t)115,
		(int8_t)115,
		(int8_t)45,
		(int8_t)155,
		(int8_t)87,
		(int8_t)175,
		(int8_t)159,
		(int8_t)227,
		(int8_t)235,
		(int8_t)219,
		(int8_t)2,
		(int8_t)0,
		(int8_t)3,
		(int8_t)73,
		(int8_t)0,
		(int8_t)7,
		(int8_t)97,
		(int8_t)100,
		(int8_t)100,
		(int8_t)114,
		(int8_t)101,
		(int8_t)115,
		(int8_t)115,
		(int8_t)73,
		(int8_t)0,
		(int8_t)6,
		(int8_t)102,
		(int8_t)97,
		(int8_t)109,
		(int8_t)105,
		(int8_t)108,
		(int8_t)121,
		(int8_t)76,
		(int8_t)0,
		(int8_t)8,
		(int8_t)104,
		(int8_t)111,
		(int8_t)115,
		(int8_t)116,
		(int8_t)78,
		(int8_t)97,
		(int8_t)109,
		(int8_t)101,
		(int8_t)113,
		(int8_t)0,
		(int8_t)126,
		(int8_t)0,
		(int8_t)1,
		(int8_t)120,
		(int8_t)112,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)2,
		(int8_t)116,
		(int8_t)0,
		(int8_t)9,
		(int8_t)108,
		(int8_t)111,
		(int8_t)99,
		(int8_t)97,
		(int8_t)108,
		(int8_t)104,
		(int8_t)111,
		(int8_t)115,
		(int8_t)116,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)1,
		(int8_t)0,
		(int8_t)112,
		(int8_t)117,
		(int8_t)114,
		(int8_t)0,
		(int8_t)2,
		(int8_t)91,
		(int8_t)66,
		(int8_t)172,
		(int8_t)243,
		(int8_t)23,
		(int8_t)248,
		(int8_t)6,
		(int8_t)8,
		(int8_t)84,
		(int8_t)224,
		(int8_t)2,
		(int8_t)0,
		(int8_t)0,
		(int8_t)120,
		(int8_t)112,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)16,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)1,
		(int8_t)120
	}));
	$assignStatic(Inet6AddressSerializationTest::SerialData_ifname_e1000g0, $new($bytes, {
		(int8_t)172,
		(int8_t)237,
		(int8_t)0,
		(int8_t)5,
		(int8_t)115,
		(int8_t)114,
		(int8_t)0,
		(int8_t)21,
		(int8_t)106,
		(int8_t)97,
		(int8_t)118,
		(int8_t)97,
		(int8_t)46,
		(int8_t)110,
		(int8_t)101,
		(int8_t)116,
		(int8_t)46,
		(int8_t)73,
		(int8_t)110,
		(int8_t)101,
		(int8_t)116,
		(int8_t)54,
		(int8_t)65,
		(int8_t)100,
		(int8_t)100,
		(int8_t)114,
		(int8_t)101,
		(int8_t)115,
		(int8_t)115,
		(int8_t)95,
		(int8_t)124,
		(int8_t)32,
		(int8_t)129,
		(int8_t)82,
		(int8_t)44,
		(int8_t)128,
		(int8_t)33,
		(int8_t)3,
		(int8_t)0,
		(int8_t)5,
		(int8_t)73,
		(int8_t)0,
		(int8_t)8,
		(int8_t)115,
		(int8_t)99,
		(int8_t)111,
		(int8_t)112,
		(int8_t)101,
		(int8_t)95,
		(int8_t)105,
		(int8_t)100,
		(int8_t)90,
		(int8_t)0,
		(int8_t)12,
		(int8_t)115,
		(int8_t)99,
		(int8_t)111,
		(int8_t)112,
		(int8_t)101,
		(int8_t)95,
		(int8_t)105,
		(int8_t)100,
		(int8_t)95,
		(int8_t)115,
		(int8_t)101,
		(int8_t)116,
		(int8_t)90,
		(int8_t)0,
		(int8_t)16,
		(int8_t)115,
		(int8_t)99,
		(int8_t)111,
		(int8_t)112,
		(int8_t)101,
		(int8_t)95,
		(int8_t)105,
		(int8_t)102,
		(int8_t)110,
		(int8_t)97,
		(int8_t)109,
		(int8_t)101,
		(int8_t)95,
		(int8_t)115,
		(int8_t)101,
		(int8_t)116,
		(int8_t)76,
		(int8_t)0,
		(int8_t)6,
		(int8_t)105,
		(int8_t)102,
		(int8_t)110,
		(int8_t)97,
		(int8_t)109,
		(int8_t)101,
		(int8_t)116,
		(int8_t)0,
		(int8_t)18,
		(int8_t)76,
		(int8_t)106,
		(int8_t)97,
		(int8_t)118,
		(int8_t)97,
		(int8_t)47,
		(int8_t)108,
		(int8_t)97,
		(int8_t)110,
		(int8_t)103,
		(int8_t)47,
		(int8_t)83,
		(int8_t)116,
		(int8_t)114,
		(int8_t)105,
		(int8_t)110,
		(int8_t)103,
		(int8_t)59,
		(int8_t)91,
		(int8_t)0,
		(int8_t)9,
		(int8_t)105,
		(int8_t)112,
		(int8_t)97,
		(int8_t)100,
		(int8_t)100,
		(int8_t)114,
		(int8_t)101,
		(int8_t)115,
		(int8_t)115,
		(int8_t)116,
		(int8_t)0,
		(int8_t)2,
		(int8_t)91,
		(int8_t)66,
		(int8_t)120,
		(int8_t)114,
		(int8_t)0,
		(int8_t)20,
		(int8_t)106,
		(int8_t)97,
		(int8_t)118,
		(int8_t)97,
		(int8_t)46,
		(int8_t)110,
		(int8_t)101,
		(int8_t)116,
		(int8_t)46,
		(int8_t)73,
		(int8_t)110,
		(int8_t)101,
		(int8_t)116,
		(int8_t)65,
		(int8_t)100,
		(int8_t)100,
		(int8_t)114,
		(int8_t)101,
		(int8_t)115,
		(int8_t)115,
		(int8_t)45,
		(int8_t)155,
		(int8_t)87,
		(int8_t)175,
		(int8_t)159,
		(int8_t)227,
		(int8_t)235,
		(int8_t)219,
		(int8_t)2,
		(int8_t)0,
		(int8_t)3,
		(int8_t)73,
		(int8_t)0,
		(int8_t)7,
		(int8_t)97,
		(int8_t)100,
		(int8_t)100,
		(int8_t)114,
		(int8_t)101,
		(int8_t)115,
		(int8_t)115,
		(int8_t)73,
		(int8_t)0,
		(int8_t)6,
		(int8_t)102,
		(int8_t)97,
		(int8_t)109,
		(int8_t)105,
		(int8_t)108,
		(int8_t)121,
		(int8_t)76,
		(int8_t)0,
		(int8_t)8,
		(int8_t)104,
		(int8_t)111,
		(int8_t)115,
		(int8_t)116,
		(int8_t)78,
		(int8_t)97,
		(int8_t)109,
		(int8_t)101,
		(int8_t)113,
		(int8_t)0,
		(int8_t)126,
		(int8_t)0,
		(int8_t)1,
		(int8_t)120,
		(int8_t)112,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)2,
		(int8_t)116,
		(int8_t)0,
		(int8_t)37,
		(int8_t)102,
		(int8_t)101,
		(int8_t)56,
		(int8_t)48,
		(int8_t)58,
		(int8_t)48,
		(int8_t)58,
		(int8_t)48,
		(int8_t)58,
		(int8_t)48,
		(int8_t)58,
		(int8_t)50,
		(int8_t)49,
		(int8_t)98,
		(int8_t)58,
		(int8_t)50,
		(int8_t)52,
		(int8_t)102,
		(int8_t)102,
		(int8_t)58,
		(int8_t)102,
		(int8_t)101,
		(int8_t)98,
		(int8_t)100,
		(int8_t)58,
		(int8_t)102,
		(int8_t)50,
		(int8_t)57,
		(int8_t)99,
		(int8_t)37,
		(int8_t)101,
		(int8_t)49,
		(int8_t)48,
		(int8_t)48,
		(int8_t)48,
		(int8_t)103,
		(int8_t)48,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)2,
		(int8_t)1,
		(int8_t)1,
		(int8_t)116,
		(int8_t)0,
		(int8_t)7,
		(int8_t)101,
		(int8_t)49,
		(int8_t)48,
		(int8_t)48,
		(int8_t)48,
		(int8_t)103,
		(int8_t)48,
		(int8_t)117,
		(int8_t)114,
		(int8_t)0,
		(int8_t)2,
		(int8_t)91,
		(int8_t)66,
		(int8_t)172,
		(int8_t)243,
		(int8_t)23,
		(int8_t)248,
		(int8_t)6,
		(int8_t)8,
		(int8_t)84,
		(int8_t)224,
		(int8_t)2,
		(int8_t)0,
		(int8_t)0,
		(int8_t)120,
		(int8_t)112,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)16,
		(int8_t)254,
		(int8_t)128,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)2,
		(int8_t)27,
		(int8_t)36,
		(int8_t)255,
		(int8_t)254,
		(int8_t)189,
		(int8_t)242,
		(int8_t)156,
		(int8_t)120
	}));
	$assignStatic(Inet6AddressSerializationTest::SerialData_ifname_lo0, $new($bytes, {
		(int8_t)172,
		(int8_t)237,
		(int8_t)0,
		(int8_t)5,
		(int8_t)115,
		(int8_t)114,
		(int8_t)0,
		(int8_t)21,
		(int8_t)106,
		(int8_t)97,
		(int8_t)118,
		(int8_t)97,
		(int8_t)46,
		(int8_t)110,
		(int8_t)101,
		(int8_t)116,
		(int8_t)46,
		(int8_t)73,
		(int8_t)110,
		(int8_t)101,
		(int8_t)116,
		(int8_t)54,
		(int8_t)65,
		(int8_t)100,
		(int8_t)100,
		(int8_t)114,
		(int8_t)101,
		(int8_t)115,
		(int8_t)115,
		(int8_t)95,
		(int8_t)124,
		(int8_t)32,
		(int8_t)129,
		(int8_t)82,
		(int8_t)44,
		(int8_t)128,
		(int8_t)33,
		(int8_t)3,
		(int8_t)0,
		(int8_t)5,
		(int8_t)73,
		(int8_t)0,
		(int8_t)8,
		(int8_t)115,
		(int8_t)99,
		(int8_t)111,
		(int8_t)112,
		(int8_t)101,
		(int8_t)95,
		(int8_t)105,
		(int8_t)100,
		(int8_t)90,
		(int8_t)0,
		(int8_t)12,
		(int8_t)115,
		(int8_t)99,
		(int8_t)111,
		(int8_t)112,
		(int8_t)101,
		(int8_t)95,
		(int8_t)105,
		(int8_t)100,
		(int8_t)95,
		(int8_t)115,
		(int8_t)101,
		(int8_t)116,
		(int8_t)90,
		(int8_t)0,
		(int8_t)16,
		(int8_t)115,
		(int8_t)99,
		(int8_t)111,
		(int8_t)112,
		(int8_t)101,
		(int8_t)95,
		(int8_t)105,
		(int8_t)102,
		(int8_t)110,
		(int8_t)97,
		(int8_t)109,
		(int8_t)101,
		(int8_t)95,
		(int8_t)115,
		(int8_t)101,
		(int8_t)116,
		(int8_t)76,
		(int8_t)0,
		(int8_t)6,
		(int8_t)105,
		(int8_t)102,
		(int8_t)110,
		(int8_t)97,
		(int8_t)109,
		(int8_t)101,
		(int8_t)116,
		(int8_t)0,
		(int8_t)18,
		(int8_t)76,
		(int8_t)106,
		(int8_t)97,
		(int8_t)118,
		(int8_t)97,
		(int8_t)47,
		(int8_t)108,
		(int8_t)97,
		(int8_t)110,
		(int8_t)103,
		(int8_t)47,
		(int8_t)83,
		(int8_t)116,
		(int8_t)114,
		(int8_t)105,
		(int8_t)110,
		(int8_t)103,
		(int8_t)59,
		(int8_t)91,
		(int8_t)0,
		(int8_t)9,
		(int8_t)105,
		(int8_t)112,
		(int8_t)97,
		(int8_t)100,
		(int8_t)100,
		(int8_t)114,
		(int8_t)101,
		(int8_t)115,
		(int8_t)115,
		(int8_t)116,
		(int8_t)0,
		(int8_t)2,
		(int8_t)91,
		(int8_t)66,
		(int8_t)120,
		(int8_t)114,
		(int8_t)0,
		(int8_t)20,
		(int8_t)106,
		(int8_t)97,
		(int8_t)118,
		(int8_t)97,
		(int8_t)46,
		(int8_t)110,
		(int8_t)101,
		(int8_t)116,
		(int8_t)46,
		(int8_t)73,
		(int8_t)110,
		(int8_t)101,
		(int8_t)116,
		(int8_t)65,
		(int8_t)100,
		(int8_t)100,
		(int8_t)114,
		(int8_t)101,
		(int8_t)115,
		(int8_t)115,
		(int8_t)45,
		(int8_t)155,
		(int8_t)87,
		(int8_t)175,
		(int8_t)159,
		(int8_t)227,
		(int8_t)235,
		(int8_t)219,
		(int8_t)2,
		(int8_t)0,
		(int8_t)3,
		(int8_t)73,
		(int8_t)0,
		(int8_t)7,
		(int8_t)97,
		(int8_t)100,
		(int8_t)100,
		(int8_t)114,
		(int8_t)101,
		(int8_t)115,
		(int8_t)115,
		(int8_t)73,
		(int8_t)0,
		(int8_t)6,
		(int8_t)102,
		(int8_t)97,
		(int8_t)109,
		(int8_t)105,
		(int8_t)108,
		(int8_t)121,
		(int8_t)76,
		(int8_t)0,
		(int8_t)8,
		(int8_t)104,
		(int8_t)111,
		(int8_t)115,
		(int8_t)116,
		(int8_t)78,
		(int8_t)97,
		(int8_t)109,
		(int8_t)101,
		(int8_t)113,
		(int8_t)0,
		(int8_t)126,
		(int8_t)0,
		(int8_t)1,
		(int8_t)120,
		(int8_t)112,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)2,
		(int8_t)116,
		(int8_t)0,
		(int8_t)9,
		(int8_t)108,
		(int8_t)111,
		(int8_t)99,
		(int8_t)97,
		(int8_t)108,
		(int8_t)104,
		(int8_t)111,
		(int8_t)115,
		(int8_t)116,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)1,
		(int8_t)1,
		(int8_t)1,
		(int8_t)116,
		(int8_t)0,
		(int8_t)3,
		(int8_t)108,
		(int8_t)111,
		(int8_t)48,
		(int8_t)117,
		(int8_t)114,
		(int8_t)0,
		(int8_t)2,
		(int8_t)91,
		(int8_t)66,
		(int8_t)172,
		(int8_t)243,
		(int8_t)23,
		(int8_t)248,
		(int8_t)6,
		(int8_t)8,
		(int8_t)84,
		(int8_t)224,
		(int8_t)2,
		(int8_t)0,
		(int8_t)0,
		(int8_t)120,
		(int8_t)112,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)16,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)0,
		(int8_t)1,
		(int8_t)120
	}));
}

Inet6AddressSerializationTest::Inet6AddressSerializationTest() {
}

$Class* Inet6AddressSerializationTest::load$($String* name, bool initialize) {
	$loadClass(Inet6AddressSerializationTest, name, initialize, &_Inet6AddressSerializationTest_ClassInfo_, clinit$Inet6AddressSerializationTest, allocate$Inet6AddressSerializationTest);
	return class$;
}

$Class* Inet6AddressSerializationTest::class$ = nullptr;