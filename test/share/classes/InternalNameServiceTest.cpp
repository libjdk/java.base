#include <InternalNameServiceTest.h>

#include <java/io/BufferedWriter.h>
#include <java/io/FileWriter.h>
#include <java/io/PrintWriter.h>
#include <java/io/Writer.h>
#include <java/net/InetAddress.h>
#include <java/net/UnknownHostException.h>
#include <java/util/Arrays.h>
#include <jcpp.h>

#undef HOSTS_FILE_NAME

using $BufferedWriter = ::java::io::BufferedWriter;
using $FileWriter = ::java::io::FileWriter;
using $PrintStream = ::java::io::PrintStream;
using $PrintWriter = ::java::io::PrintWriter;
using $Writer = ::java::io::Writer;
using $Byte = ::java::lang::Byte;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $InetAddress = ::java::net::InetAddress;
using $UnknownHostException = ::java::net::UnknownHostException;
using $Arrays = ::java::util::Arrays;

$FieldInfo _InternalNameServiceTest_FieldInfo_[] = {
	{"HOSTS_FILE_NAME", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(InternalNameServiceTest, HOSTS_FILE_NAME)},
	{}
};

$MethodInfo _InternalNameServiceTest_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(InternalNameServiceTest, init$, void)},
	{"addMappingToHostsFile", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Z)V", nullptr, $PRIVATE | $STATIC, $staticMethod(InternalNameServiceTest, addMappingToHostsFile, void, $String*, $String*, $String*, bool), "java.lang.Exception"},
	{"addrToString", "([B)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(InternalNameServiceTest, addrToString, $String*, $bytes*)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(InternalNameServiceTest, main, void, $StringArray*), "java.lang.Exception"},
	{"testHostToIPAddressMappings", "(Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(InternalNameServiceTest, testHostToIPAddressMappings, void, $String*), "java.lang.Exception,java.net.UnknownHostException"},
	{"testIpAddressToHostNameMappings", "(Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(InternalNameServiceTest, testIpAddressToHostNameMappings, void, $String*), "java.lang.Exception"},
	{}
};

$ClassInfo _InternalNameServiceTest_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"InternalNameServiceTest",
	"java.lang.Object",
	nullptr,
	_InternalNameServiceTest_FieldInfo_,
	_InternalNameServiceTest_MethodInfo_
};

$Object* allocate$InternalNameServiceTest($Class* clazz) {
	return $of($alloc(InternalNameServiceTest));
}

$String* InternalNameServiceTest::HOSTS_FILE_NAME = nullptr;

void InternalNameServiceTest::init$() {
}

void InternalNameServiceTest::main($StringArray* args) {
	$init(InternalNameServiceTest);
	testHostToIPAddressMappings(InternalNameServiceTest::HOSTS_FILE_NAME);
	testIpAddressToHostNameMappings(InternalNameServiceTest::HOSTS_FILE_NAME);
}

void InternalNameServiceTest::testHostToIPAddressMappings($String* hostsFileName) {
	$init(InternalNameServiceTest);
	$useLocalCurrentObjectStackCache();
	$nc($System::out)->println(" TEST HOST TO  IP ADDRESS MAPPINGS "_s);
	$var($InetAddress, testAddress, nullptr);
	$var($bytes, retrievedIpAddr, nullptr);
	$var($bytes, expectedIpAddr1, $new($bytes, {
		(int8_t)1,
		(int8_t)2,
		(int8_t)3,
		(int8_t)4
	}));
	$var($bytes, expectedIpAddr2, $new($bytes, {
		(int8_t)5,
		(int8_t)6,
		(int8_t)7,
		(int8_t)8
	}));
	$var($bytes, expectedIpAddrIpv6_1, $new($bytes, {
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
	addMappingToHostsFile("test hosts file for internal NameService "_s, "#"_s, hostsFileName, false);
	addMappingToHostsFile("host.sample-domain"_s, "1.2.3.4"_s, hostsFileName, true);
	$assign(testAddress, $InetAddress::getByName("host.sample-domain"_s));
	$assign(retrievedIpAddr, $nc(testAddress)->getAddress());
	if (!$Arrays::equals(retrievedIpAddr, expectedIpAddr1)) {
		$throwNew($RuntimeException, "retrievedIpAddr not equal to expectedipAddr"_s);
	}
	addMappingToHostsFile("host1.sample-domain"_s, "5.6.7.8"_s, hostsFileName, true);
	addMappingToHostsFile("host2.sample-domain"_s, "1.2.3.4"_s, hostsFileName, true);
	$assign(testAddress, $InetAddress::getByName("host1.sample-domain"_s));
	$assign(retrievedIpAddr, testAddress->getAddress());
	if (!$Arrays::equals(retrievedIpAddr, expectedIpAddr2)) {
		$throwNew($RuntimeException, "retrievedIpAddr not equal to expectedIpAddr"_s);
	}
	$assign(testAddress, $InetAddress::getByName("host2.sample-domain"_s));
	$assign(retrievedIpAddr, testAddress->getAddress());
	if (!$Arrays::equals(retrievedIpAddr, expectedIpAddr1)) {
		$throwNew($RuntimeException, "retrievedIpAddr not equal to expectedIpAddr"_s);
	}
	try {
		addMappingToHostsFile("host3.sample-domain"_s, ""_s, hostsFileName, true);
		$assign(testAddress, $InetAddress::getByName("host3.sample-domain"_s));
		$throwNew($RuntimeException, "Expected UnknownHostException not thrown"_s);
	} catch ($UnknownHostException& uhEx) {
		$nc($System::out)->println("UnknownHostException as expected for host host3.sample-domain"_s);
	}
	try {
		addMappingToHostsFile("host4.sample-domain"_s, " "_s, hostsFileName, true);
		$assign(testAddress, $InetAddress::getByName("host4.sample-domain"_s));
		$throwNew($RuntimeException, "Expected UnknownHostException not thrown"_s);
	} catch ($UnknownHostException& uhEx) {
		$nc($System::out)->println("UnknownHostException as expected for host host4.sample-domain"_s);
	}
	try {
		addMappingToHostsFile("host5.sample-domain"_s, "  "_s, hostsFileName, true);
		$assign(testAddress, $InetAddress::getByName("host4.sample-domain"_s));
		$throwNew($RuntimeException, "Expected UnknownHostException not thrown"_s);
	} catch ($UnknownHostException& uhEx) {
		$nc($System::out)->println("UnknownHostException as expected for host host5.sample-domain"_s);
	}
	addMappingToHostsFile("host-ipv6.sample-domain"_s, "::1"_s, hostsFileName, true);
	$assign(testAddress, $InetAddress::getByName("host-ipv6.sample-domain"_s));
	$assign(retrievedIpAddr, testAddress->getAddress());
	if (!$Arrays::equals(retrievedIpAddr, expectedIpAddrIpv6_1)) {
		$nc($System::out)->println($$str({"retrieved ipv6 addr == "_s, $($Arrays::toString(retrievedIpAddr))}));
		$nc($System::out)->println($$str({"expected ipv6 addr == "_s, $($Arrays::toString(expectedIpAddrIpv6_1))}));
		$throwNew($RuntimeException, "retrieved IPV6 Addr not equal to expected IPV6 Addr"_s);
	}
}

void InternalNameServiceTest::testIpAddressToHostNameMappings($String* hostsFileName) {
	$init(InternalNameServiceTest);
	$useLocalCurrentObjectStackCache();
	$nc($System::out)->println(" TEST IP ADDRESS TO HOST MAPPINGS "_s);
	$var($InetAddress, testAddress, nullptr);
	$var($String, retrievedHost, nullptr);
	$var($String, expectedHost, "testHost.testDomain"_s);
	$var($bytes, testHostIpAddr, $new($bytes, {
		(int8_t)10,
		(int8_t)2,
		(int8_t)3,
		(int8_t)4
	}));
	$var($bytes, testHostIpAddr2, $new($bytes, {
		(int8_t)10,
		(int8_t)5,
		(int8_t)6,
		(int8_t)7
	}));
	$var($bytes, testHostIpAddr3, $new($bytes, {
		(int8_t)10,
		(int8_t)8,
		(int8_t)9,
		(int8_t)10
	}));
	$var($bytes, testHostIpAddr4, $new($bytes, {
		(int8_t)10,
		(int8_t)8,
		(int8_t)9,
		(int8_t)11
	}));
	addMappingToHostsFile("test hosts file for internal NameService "_s, "#"_s, hostsFileName, false);
	addMappingToHostsFile("testHost.testDomain"_s, "10.2.3.4"_s, hostsFileName, true);
	$assign(testAddress, $InetAddress::getByAddress(testHostIpAddr));
	$nc($System::out)->println($$str({"*******   testAddress == "_s, testAddress}));
	$assign(retrievedHost, $nc(testAddress)->getHostName());
	if (!expectedHost->equals(retrievedHost)) {
		$throwNew($RuntimeException, "retrieved host name not equal to expected host name"_s);
	}
	addMappingToHostsFile("testHost.testDomain"_s, "10.5.6.7"_s, hostsFileName, true);
	$assign(testAddress, $InetAddress::getByAddress(testHostIpAddr2));
	$nc($System::out)->println($$str({"*******   testAddress == "_s, testAddress}));
	$assign(retrievedHost, testAddress->getHostName());
	$nc($System::out)->println($$str({"*******   retrievedHost == "_s, retrievedHost}));
	if (!expectedHost->equals(retrievedHost)) {
		$throwNew($RuntimeException, $$str({"retrieved host name "_s, retrievedHost, " not equal to expected host name"_s, expectedHost}));
	}
	$assign(testAddress, $InetAddress::getByAddress(testHostIpAddr4));
	$nc($System::out)->println($$str({"*******   testAddress == "_s, testAddress}));
	if ("10.8.9.11"_s->equalsIgnoreCase($(testAddress->getCanonicalHostName()))) {
		$nc($System::out)->println($$str({"addr = "_s, $(addrToString(testHostIpAddr4)), "  resolve to a host address as expected"_s}));
	} else {
		$var($String, var$0, $$str({"addr = "_s, $(addrToString(testHostIpAddr4)), " does not resolve as expected, testAddress == "_s}));
		$nc($System::out)->println($$concat(var$0, $(testAddress->getCanonicalHostName())));
		$throwNew($RuntimeException, $$str({"problem with resolving "_s, $(addrToString(testHostIpAddr4))}));
	}
	try {
		addMappingToHostsFile(""_s, "10.8.9.10"_s, hostsFileName, true);
		$assign(testAddress, $InetAddress::getByAddress(testHostIpAddr3));
		$nc($System::out)->println($$str({"*******   testAddress == "_s, testAddress}));
		$assign(retrievedHost, $nc(testAddress)->getCanonicalHostName());
	} catch ($Throwable& t) {
		$throwNew($RuntimeException, $$str({"problem with resolving "_s, $(addrToString(testHostIpAddr3))}));
	}
}

$String* InternalNameServiceTest::addrToString($bytes* addr) {
	$init(InternalNameServiceTest);
	$useLocalCurrentObjectStackCache();
	$var($String, var$4, $$str({$($Byte::toString($nc(addr)->get(0))), "."_s}));
	$var($String, var$3, $$concat(var$4, $($Byte::toString($nc(addr)->get(1)))));
	$var($String, var$2, $$concat(var$3, "."_s));
	$var($String, var$1, $$concat(var$2, $($Byte::toString($nc(addr)->get(2)))));
	$var($String, var$0, $$concat(var$1, "."_s));
	return $concat(var$0, $($Byte::toString($nc(addr)->get(3))));
}

void InternalNameServiceTest::addMappingToHostsFile($String* host, $String* addr, $String* hostsFileName, bool append) {
	$init(InternalNameServiceTest);
	$useLocalCurrentObjectStackCache();
	$var($String, mapping, $str({addr, " "_s, host}));
	{
		$var($PrintWriter, hfPWriter, $new($PrintWriter, static_cast<$Writer*>($$new($BufferedWriter, $$new($FileWriter, hostsFileName, append)))));
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					hfPWriter->println(mapping);
				} catch ($Throwable& t$) {
					try {
						hfPWriter->close();
					} catch ($Throwable& x2) {
						t$->addSuppressed(x2);
					}
					$throw(t$);
				}
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				hfPWriter->close();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
}

void clinit$InternalNameServiceTest($Class* class$) {
	$assignStatic(InternalNameServiceTest::HOSTS_FILE_NAME, $System::getProperty("jdk.net.hosts.file"_s));
}

InternalNameServiceTest::InternalNameServiceTest() {
}

$Class* InternalNameServiceTest::load$($String* name, bool initialize) {
	$loadClass(InternalNameServiceTest, name, initialize, &_InternalNameServiceTest_ClassInfo_, clinit$InternalNameServiceTest, allocate$InternalNameServiceTest);
	return class$;
}

$Class* InternalNameServiceTest::class$ = nullptr;