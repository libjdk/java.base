#include <NetworkChannelTests$3.h>

#include <NetworkChannelTests.h>
#include <java/nio/channels/DatagramChannel.h>
#include <java/nio/channels/NetworkChannel.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $DatagramChannel = ::java::nio::channels::DatagramChannel;
using $NetworkChannel = ::java::nio::channels::NetworkChannel;

$MethodInfo _NetworkChannelTests$3_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(NetworkChannelTests$3, init$, void)},
	{"open", "()Ljava/nio/channels/NetworkChannel;", nullptr, $PUBLIC, $virtualMethod(NetworkChannelTests$3, open, $NetworkChannel*), "java.io.IOException"},
	{}
};

$EnclosingMethodInfo _NetworkChannelTests$3_EnclosingMethodInfo_ = {
	"NetworkChannelTests",
	"main",
	"([Ljava/lang/String;)V"
};

$InnerClassInfo _NetworkChannelTests$3_InnerClassesInfo_[] = {
	{"NetworkChannelTests$3", nullptr, nullptr, 0},
	{"NetworkChannelTests$ChannelFactory", "NetworkChannelTests", "ChannelFactory", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _NetworkChannelTests$3_ClassInfo_ = {
	$ACC_SUPER,
	"NetworkChannelTests$3",
	"java.lang.Object",
	"NetworkChannelTests$ChannelFactory",
	nullptr,
	_NetworkChannelTests$3_MethodInfo_,
	nullptr,
	&_NetworkChannelTests$3_EnclosingMethodInfo_,
	_NetworkChannelTests$3_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"NetworkChannelTests"
};

$Object* allocate$NetworkChannelTests$3($Class* clazz) {
	return $of($alloc(NetworkChannelTests$3));
}

void NetworkChannelTests$3::init$() {
}

$NetworkChannel* NetworkChannelTests$3::open() {
	return $DatagramChannel::open();
}

NetworkChannelTests$3::NetworkChannelTests$3() {
}

$Class* NetworkChannelTests$3::load$($String* name, bool initialize) {
	$loadClass(NetworkChannelTests$3, name, initialize, &_NetworkChannelTests$3_ClassInfo_, allocate$NetworkChannelTests$3);
	return class$;
}

$Class* NetworkChannelTests$3::class$ = nullptr;