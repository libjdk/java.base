#include <ConfigureBlocking.h>

#include <java/nio/channels/ClosedChannelException.h>
#include <java/nio/channels/DatagramChannel.h>
#include <java/nio/channels/SelectableChannel.h>
#include <java/nio/channels/ServerSocketChannel.h>
#include <java/nio/channels/SocketChannel.h>
#include <jcpp.h>

using $SelectableChannelArray = $Array<::java::nio::channels::SelectableChannel>;
using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $ClosedChannelException = ::java::nio::channels::ClosedChannelException;
using $DatagramChannel = ::java::nio::channels::DatagramChannel;
using $SelectableChannel = ::java::nio::channels::SelectableChannel;
using $ServerSocketChannel = ::java::nio::channels::ServerSocketChannel;
using $SocketChannel = ::java::nio::channels::SocketChannel;

$MethodInfo _ConfigureBlocking_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ConfigureBlocking, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(ConfigureBlocking, main, void, $StringArray*), "java.lang.Exception"},
	{}
};

$ClassInfo _ConfigureBlocking_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"ConfigureBlocking",
	"java.lang.Object",
	nullptr,
	nullptr,
	_ConfigureBlocking_MethodInfo_
};

$Object* allocate$ConfigureBlocking($Class* clazz) {
	return $of($alloc(ConfigureBlocking));
}

void ConfigureBlocking::init$() {
}

void ConfigureBlocking::main($StringArray* str) {
	$useLocalCurrentObjectStackCache();
	$var($SelectableChannelArray, channels, nullptr);
	$assign(channels, $new($SelectableChannelArray, {
		$(static_cast<$SelectableChannel*>($DatagramChannel::open())),
		$(static_cast<$SelectableChannel*>($SocketChannel::open())),
		$(static_cast<$SelectableChannel*>($ServerSocketChannel::open()))
	}));
	for (int32_t i = 0; i < channels->length; ++i) {
		$var($SelectableChannel, channel, channels->get(i));
		$nc(channel)->close();
		try {
			channel->configureBlocking(true);
			$throwNew($RuntimeException, "expected exception not thrown"_s);
		} catch ($ClosedChannelException& e) {
		}
	}
}

ConfigureBlocking::ConfigureBlocking() {
}

$Class* ConfigureBlocking::load$($String* name, bool initialize) {
	$loadClass(ConfigureBlocking, name, initialize, &_ConfigureBlocking_ClassInfo_, allocate$ConfigureBlocking);
	return class$;
}

$Class* ConfigureBlocking::class$ = nullptr;