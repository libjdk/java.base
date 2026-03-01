#include <LookupTest.h>

#include <LookupTest$LookupTestPolicy.h>
#include <LookupTest$Server.h>
#include <java/io/BufferedWriter.h>
#include <java/io/FileWriter.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/PrintWriter.h>
#include <java/io/Writer.h>
#include <java/lang/SecurityException.h>
#include <java/lang/SecurityManager.h>
#include <java/net/InetAddress.h>
#include <java/net/ProxySelector.h>
#include <java/net/ServerSocket.h>
#include <java/net/URL.h>
#include <java/net/URLConnection.h>
#include <java/security/Policy.h>
#include <jcpp.h>

#undef DEFAULT_POLICY
#undef HOSTS_FILE_NAME

using $LookupTest$LookupTestPolicy = ::LookupTest$LookupTestPolicy;
using $LookupTest$Server = ::LookupTest$Server;
using $BufferedWriter = ::java::io::BufferedWriter;
using $FileWriter = ::java::io::FileWriter;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $PrintStream = ::java::io::PrintStream;
using $PrintWriter = ::java::io::PrintWriter;
using $Writer = ::java::io::Writer;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $SecurityException = ::java::lang::SecurityException;
using $SecurityManager = ::java::lang::SecurityManager;
using $InetAddress = ::java::net::InetAddress;
using $ProxySelector = ::java::net::ProxySelector;
using $ServerSocket = ::java::net::ServerSocket;
using $URL = ::java::net::URL;
using $URLConnection = ::java::net::URLConnection;
using $Policy = ::java::security::Policy;

$FieldInfo _LookupTest_FieldInfo_[] = {
	{"DEFAULT_POLICY", "Ljava/security/Policy;", nullptr, $STATIC | $FINAL, $staticField(LookupTest, DEFAULT_POLICY)},
	{"port", "I", nullptr, $STATIC, $staticField(LookupTest, port)},
	{"serverSocket", "Ljava/net/ServerSocket;", nullptr, $STATIC | $VOLATILE, $staticField(LookupTest, serverSocket)},
	{"HOSTS_FILE_NAME", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(LookupTest, HOSTS_FILE_NAME)},
	{}
};

$MethodInfo _LookupTest_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(LookupTest, init$, void)},
	{"addMappingToHostsFile", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Z)V", nullptr, $PRIVATE | $STATIC, $staticMethod(LookupTest, addMappingToHostsFile, void, $String*, $String*, $String*, bool), "java.io.IOException"},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(LookupTest, main, void, $StringArray*), "java.lang.Exception"},
	{"test", "(Ljava/lang/String;ZZ)V", nullptr, $STATIC, $staticMethod(LookupTest, test, void, $String*, bool, bool)},
	{}
};

$InnerClassInfo _LookupTest_InnerClassesInfo_[] = {
	{"LookupTest$LookupTestPolicy", "LookupTest", "LookupTestPolicy", $STATIC},
	{"LookupTest$Server", "LookupTest", "Server", $STATIC},
	{}
};

$ClassInfo _LookupTest_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"LookupTest",
	"java.lang.Object",
	nullptr,
	_LookupTest_FieldInfo_,
	_LookupTest_MethodInfo_,
	nullptr,
	nullptr,
	_LookupTest_InnerClassesInfo_,
	nullptr,
	nullptr,
	"LookupTest$LookupTestPolicy,LookupTest$Server"
};

$Object* allocate$LookupTest($Class* clazz) {
	return $of($alloc(LookupTest));
}

$Policy* LookupTest::DEFAULT_POLICY = nullptr;
int32_t LookupTest::port = 0;
$volatile($ServerSocket*) LookupTest::serverSocket = nullptr;
$String* LookupTest::HOSTS_FILE_NAME = nullptr;

void LookupTest::init$() {
}

void LookupTest::test($String* url, bool throwsSecException, bool throwsIOException) {
	$init(LookupTest);
	$useLocalCurrentObjectStackCache();
	$ProxySelector::setDefault(nullptr);
	$var($URL, u, nullptr);
	$var($InputStream, is, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		bool return$1 = false;
		try {
			try {
				$assign(u, $new($URL, url));
				$nc($System::err)->println($$str({"Connecting to "_s, u}));
				$var($URLConnection, urlc, u->openConnection());
				$assign(is, $nc(urlc)->getInputStream());
			} catch ($SecurityException& e) {
				if (!throwsSecException) {
					$throwNew($RuntimeException, "Unexpected SecurityException:"_s, e);
				}
				return$1 = true;
				goto $finally;
			} catch ($IOException& e) {
				if (!throwsIOException) {
					$nc($System::err)->println($$str({"Unexpected IOException:"_s, $(e->getMessage())}));
					$throwNew($RuntimeException, static_cast<$Throwable*>(e));
				}
				return$1 = true;
				goto $finally;
			}
		} catch ($Throwable& var$2) {
			$assign(var$0, var$2);
		} $finally: {
			if (is != nullptr) {
				try {
					is->close();
				} catch ($IOException& e) {
					$nc($System::err)->println($$str({"Unexpected IOException:"_s, $(e->getMessage())}));
					$throwNew($RuntimeException, static_cast<$Throwable*>(e));
				}
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return;
		}
	}
	if (throwsSecException || throwsIOException) {
		$nc($System::err)->printf("was expecting a %s\n"_s, $$new($ObjectArray, {throwsSecException ? $of("security exception"_s) : $of("IOException"_s)}));
		$throwNew($RuntimeException, "was expecting an exception"_s);
	}
}

void LookupTest::main($StringArray* args) {
	$init(LookupTest);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	addMappingToHostsFile("allowedAndFound.com"_s, $($nc($($InetAddress::getLoopbackAddress()))->getHostAddress()), LookupTest::HOSTS_FILE_NAME, false);
	addMappingToHostsFile("notAllowedButFound.com"_s, "99.99.99.99"_s, LookupTest::HOSTS_FILE_NAME, true);
	$var($LookupTest$Server, server, $new($LookupTest$Server));
	{
		$var($Throwable, var$0, nullptr);
		try {
			$Policy::setPolicy($$new($LookupTest$LookupTestPolicy));
			$System::setSecurityManager($$new($SecurityManager));
			server->start();
			test($$str({"http://allowedAndFound.com:"_s, $$str(LookupTest::port), "/foo"_s}), false, false);
			test($$str({"http://notAllowedButFound.com:"_s, $$str(LookupTest::port), "/foo"_s}), true, false);
			test($$str({"http://allowedButNotfound.com:"_s, $$str(LookupTest::port), "/foo"_s}), false, true);
			test($$str({"http://notAllowedAndNotFound.com:"_s, $$str(LookupTest::port), "/foo"_s}), true, false);
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			server->terminate();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void LookupTest::addMappingToHostsFile($String* host, $String* addr, $String* hostsFileName, bool append) {
	$init(LookupTest);
	$useLocalCurrentObjectStackCache();
	$var($String, mapping, $str({addr, " "_s, host}));
	{
		$var($FileWriter, fr, $new($FileWriter, hostsFileName, append));
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					$var($PrintWriter, hfPWriter, $new($PrintWriter, static_cast<$Writer*>($$new($BufferedWriter, fr))));
					{
						$var($Throwable, var$1, nullptr);
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
						} catch ($Throwable& var$2) {
							$assign(var$1, var$2);
						} /*finally*/ {
							hfPWriter->close();
						}
						if (var$1 != nullptr) {
							$throw(var$1);
						}
					}
				} catch ($Throwable& t$) {
					try {
						fr->close();
					} catch ($Throwable& x2) {
						t$->addSuppressed(x2);
					}
					$throw(t$);
				}
			} catch ($Throwable& var$3) {
				$assign(var$0, var$3);
			} /*finally*/ {
				fr->close();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
}

void clinit$LookupTest($Class* class$) {
	$assignStatic(LookupTest::DEFAULT_POLICY, $Policy::getPolicy());
	$assignStatic(LookupTest::HOSTS_FILE_NAME, $System::getProperty("jdk.net.hosts.file"_s));
}

LookupTest::LookupTest() {
}

$Class* LookupTest::load$($String* name, bool initialize) {
	$loadClass(LookupTest, name, initialize, &_LookupTest_ClassInfo_, clinit$LookupTest, allocate$LookupTest);
	return class$;
}

$Class* LookupTest::class$ = nullptr;