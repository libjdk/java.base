#include <Open.h>

#include <java/net/SocketException.h>
#include <java/nio/channels/DatagramChannel.h>
#include <java/nio/channels/Pipe.h>
#include <java/nio/channels/ServerSocketChannel.h>
#include <java/nio/channels/SocketChannel.h>
#include <java/nio/channels/spi/SelectorProvider.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $MethodInfo = ::java::lang::MethodInfo;
using $SocketException = ::java::net::SocketException;
using $DatagramChannel = ::java::nio::channels::DatagramChannel;
using $Pipe = ::java::nio::channels::Pipe;
using $ServerSocketChannel = ::java::nio::channels::ServerSocketChannel;
using $SocketChannel = ::java::nio::channels::SocketChannel;
using $SelectorProvider = ::java::nio::channels::spi::SelectorProvider;

$MethodInfo _Open_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Open, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(Open, main, void, $StringArray*), "java.lang.Exception"},
	{"test1", "()V", nullptr, $STATIC, $staticMethod(Open, test1, void)},
	{"test2", "()V", nullptr, $STATIC, $staticMethod(Open, test2, void)},
	{"test3", "()V", nullptr, $STATIC, $staticMethod(Open, test3, void)},
	{"test4", "()V", nullptr, $STATIC, $staticMethod(Open, test4, void)},
	{}
};

$ClassInfo _Open_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"Open",
	"java.lang.Object",
	nullptr,
	nullptr,
	_Open_MethodInfo_
};

$Object* allocate$Open($Class* clazz) {
	return $of($alloc(Open));
}

void Open::init$() {
}

void Open::test1() {
	$useLocalCurrentObjectStackCache();
	for (int32_t i = 0; i < 11000; ++i) {
		try {
			$var($SocketChannel, sc, $SocketChannel::open());
		} catch ($Exception& e) {
		}
	}
}

void Open::test2() {
	$useLocalCurrentObjectStackCache();
	for (int32_t i = 0; i < 11000; ++i) {
		try {
			$var($DatagramChannel, sc, $DatagramChannel::open());
		} catch ($Exception& e) {
		}
	}
}

void Open::test3() {
	$useLocalCurrentObjectStackCache();
	$var($SelectorProvider, sp, $SelectorProvider::provider());
	for (int32_t i = 0; i < 11000; ++i) {
		try {
			$var($Pipe, p, $nc(sp)->openPipe());
		} catch ($Exception& e) {
		}
	}
}

void Open::test4() {
	$useLocalCurrentObjectStackCache();
	for (int32_t i = 0; i < 11000; ++i) {
		try {
			$var($ServerSocketChannel, sc, $ServerSocketChannel::open());
		} catch ($Exception& e) {
		}
	}
}

void Open::main($StringArray* args) {
	$useLocalCurrentObjectStackCache();
	$var($DatagramChannel, dc, $DatagramChannel::open());
	$var($Exception, se, $new($SocketException));
	$var($SelectorProvider, sp, $SelectorProvider::provider());
	$var($Pipe, p, $nc(sp)->openPipe());
	$var($ServerSocketChannel, ssc, $ServerSocketChannel::open());
	test1();
	test2();
	test3();
	test4();
}

Open::Open() {
}

$Class* Open::load$($String* name, bool initialize) {
	$loadClass(Open, name, initialize, &_Open_ClassInfo_, allocate$Open);
	return class$;
}

$Class* Open::class$ = nullptr;