#include <sun/nio/ch/InheritedChannel.h>

#include <java/io/FileDescriptor.h>
#include <java/io/IOException.h>
#include <java/lang/AssertionError.h>
#include <java/lang/InternalError.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/reflect/Constructor.h>
#include <java/net/Inet6Address.h>
#include <java/net/InetAddress.h>
#include <java/net/InetSocketAddress.h>
#include <java/net/ProtocolFamily.h>
#include <java/net/SocketAddress.h>
#include <java/net/StandardProtocolFamily.h>
#include <java/net/UnixDomainSocketAddress.h>
#include <java/nio/channels/Channel.h>
#include <java/nio/channels/DatagramChannel.h>
#include <java/nio/channels/InterruptibleChannel.h>
#include <java/nio/channels/SelectableChannel.h>
#include <java/nio/channels/ServerSocketChannel.h>
#include <java/nio/channels/SocketChannel.h>
#include <java/nio/channels/spi/AbstractInterruptibleChannel.h>
#include <java/nio/channels/spi/AbstractSelectableChannel.h>
#include <java/nio/channels/spi/SelectorProvider.h>
#include <java/security/Permission.h>
#include <sun/nio/ch/DatagramChannelImpl.h>
#include <sun/nio/ch/IOUtil.h>
#include <sun/nio/ch/InheritedChannel$InheritedDatagramChannelImpl.h>
#include <sun/nio/ch/InheritedChannel$InheritedServerSocketChannelImpl.h>
#include <sun/nio/ch/InheritedChannel$InheritedSocketChannelImpl.h>
#include <sun/nio/ch/Reflect.h>
#include <sun/nio/ch/SelectorProviderImpl.h>
#include <sun/nio/ch/ServerSocketChannelImpl.h>
#include <sun/nio/ch/SocketChannelImpl.h>
#include <jcpp.h>

#undef AF_INET
#undef AF_INET6
#undef AF_UNIX
#undef AF_UNKNOWN
#undef INET
#undef INET6
#undef O_RDONLY
#undef O_RDWR
#undef O_WRONLY
#undef SOCK_DGRAM
#undef SOCK_STREAM
#undef TYPE
#undef UNIX
#undef UNKNOWN

using $FileDescriptor = ::java::io::FileDescriptor;
using $IOException = ::java::io::IOException;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityManager = ::java::lang::SecurityManager;
using $Constructor = ::java::lang::reflect::Constructor;
using $Inet6Address = ::java::net::Inet6Address;
using $InetAddress = ::java::net::InetAddress;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $ProtocolFamily = ::java::net::ProtocolFamily;
using $SocketAddress = ::java::net::SocketAddress;
using $StandardProtocolFamily = ::java::net::StandardProtocolFamily;
using $UnixDomainSocketAddress = ::java::net::UnixDomainSocketAddress;
using $Channel = ::java::nio::channels::Channel;
using $DatagramChannel = ::java::nio::channels::DatagramChannel;
using $InterruptibleChannel = ::java::nio::channels::InterruptibleChannel;
using $SelectableChannel = ::java::nio::channels::SelectableChannel;
using $ServerSocketChannel = ::java::nio::channels::ServerSocketChannel;
using $SocketChannel = ::java::nio::channels::SocketChannel;
using $AbstractInterruptibleChannel = ::java::nio::channels::spi::AbstractInterruptibleChannel;
using $AbstractSelectableChannel = ::java::nio::channels::spi::AbstractSelectableChannel;
using $SelectorProvider = ::java::nio::channels::spi::SelectorProvider;
using $Permission = ::java::security::Permission;
using $DatagramChannelImpl = ::sun::nio::ch::DatagramChannelImpl;
using $IOUtil = ::sun::nio::ch::IOUtil;
using $InheritedChannel$InheritedDatagramChannelImpl = ::sun::nio::ch::InheritedChannel$InheritedDatagramChannelImpl;
using $InheritedChannel$InheritedServerSocketChannelImpl = ::sun::nio::ch::InheritedChannel$InheritedServerSocketChannelImpl;
using $InheritedChannel$InheritedSocketChannelImpl = ::sun::nio::ch::InheritedChannel$InheritedSocketChannelImpl;
using $Reflect = ::sun::nio::ch::Reflect;
using $SelectorProviderImpl = ::sun::nio::ch::SelectorProviderImpl;
using $ServerSocketChannelImpl = ::sun::nio::ch::ServerSocketChannelImpl;
using $SocketChannelImpl = ::sun::nio::ch::SocketChannelImpl;

namespace sun {
	namespace nio {
		namespace ch {

$FieldInfo _InheritedChannel_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(InheritedChannel, $assertionsDisabled)},
	{"UNKNOWN", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(InheritedChannel, UNKNOWN)},
	{"SOCK_STREAM", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(InheritedChannel, SOCK_STREAM)},
	{"SOCK_DGRAM", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(InheritedChannel, SOCK_DGRAM)},
	{"AF_UNKNOWN", "I", nullptr, $STATIC | $FINAL, $constField(InheritedChannel, AF_UNKNOWN)},
	{"AF_INET", "I", nullptr, $STATIC | $FINAL, $constField(InheritedChannel, AF_INET)},
	{"AF_INET6", "I", nullptr, $STATIC | $FINAL, $constField(InheritedChannel, AF_INET6)},
	{"AF_UNIX", "I", nullptr, $STATIC | $FINAL, $constField(InheritedChannel, AF_UNIX)},
	{"O_RDONLY", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(InheritedChannel, O_RDONLY)},
	{"O_WRONLY", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(InheritedChannel, O_WRONLY)},
	{"O_RDWR", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(InheritedChannel, O_RDWR)},
	{"devnull", "I", nullptr, $PRIVATE | $STATIC, $staticField(InheritedChannel, devnull)},
	{"haveChannel", "Z", nullptr, $PRIVATE | $STATIC, $staticField(InheritedChannel, haveChannel)},
	{"channel", "Ljava/nio/channels/Channel;", nullptr, $PRIVATE | $STATIC, $staticField(InheritedChannel, channel)},
	{}
};

$MethodInfo _InheritedChannel_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(InheritedChannel, init$, void)},
	{"addressFamily", "(I)I", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(InheritedChannel, addressFamily, int32_t, int32_t)},
	{"checkAccess", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(InheritedChannel, checkAccess, void)},
	{"close0", "(I)V", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(InheritedChannel, close0, void, int32_t), "java.io.IOException"},
	{"createChannel", "()Ljava/nio/channels/Channel;", nullptr, $PRIVATE | $STATIC, $staticMethod(InheritedChannel, createChannel, $Channel*), "java.io.IOException"},
	{"detachIOStreams", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(InheritedChannel, detachIOStreams, void)},
	{"dup", "(I)I", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(InheritedChannel, dup, int32_t, int32_t), "java.io.IOException"},
	{"dup2", "(II)V", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(InheritedChannel, dup2, void, int32_t, int32_t), "java.io.IOException"},
	{"getChannel", "()Ljava/nio/channels/Channel;", nullptr, $PUBLIC | $STATIC | $SYNCHRONIZED, $staticMethod(InheritedChannel, getChannel, $Channel*), "java.io.IOException"},
	{"inetPeerAddress0", "(I)Ljava/net/InetAddress;", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(InheritedChannel, inetPeerAddress0, $InetAddress*, int32_t)},
	{"initIDs", "()V", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(InheritedChannel, initIDs, void)},
	{"isConnected", "(I)Z", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(InheritedChannel, isConnected, bool, int32_t)},
	{"open0", "(Ljava/lang/String;I)I", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(InheritedChannel, open0, int32_t, $String*, int32_t), "java.io.IOException"},
	{"peerPort0", "(I)I", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(InheritedChannel, peerPort0, int32_t, int32_t)},
	{"protocolFamily", "(Ljava/net/SocketAddress;)Ljava/net/ProtocolFamily;", nullptr, $STATIC, $staticMethod(InheritedChannel, protocolFamily, $ProtocolFamily*, $SocketAddress*)},
	{"protocolFamily", "(I)Ljava/net/ProtocolFamily;", nullptr, $STATIC, $staticMethod(InheritedChannel, protocolFamily, $ProtocolFamily*, int32_t)},
	{"soType0", "(I)I", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(InheritedChannel, soType0, int32_t, int32_t)},
	{"unixPeerAddress", "(I)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(InheritedChannel, unixPeerAddress, $String*, int32_t), "java.io.IOException"},
	{"unixPeerAddress0", "(I)[B", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(InheritedChannel, unixPeerAddress0, $bytes*, int32_t)},
	{}
};

#define _METHOD_INDEX_addressFamily 1
#define _METHOD_INDEX_close0 3
#define _METHOD_INDEX_dup 6
#define _METHOD_INDEX_dup2 7
#define _METHOD_INDEX_inetPeerAddress0 9
#define _METHOD_INDEX_initIDs 10
#define _METHOD_INDEX_isConnected 11
#define _METHOD_INDEX_open0 12
#define _METHOD_INDEX_peerPort0 13
#define _METHOD_INDEX_soType0 16
#define _METHOD_INDEX_unixPeerAddress0 18

$InnerClassInfo _InheritedChannel_InnerClassesInfo_[] = {
	{"sun.nio.ch.InheritedChannel$InheritedDatagramChannelImpl", "sun.nio.ch.InheritedChannel", "InheritedDatagramChannelImpl", $PUBLIC | $STATIC},
	{"sun.nio.ch.InheritedChannel$InheritedServerSocketChannelImpl", "sun.nio.ch.InheritedChannel", "InheritedServerSocketChannelImpl", $PUBLIC | $STATIC},
	{"sun.nio.ch.InheritedChannel$InheritedSocketChannelImpl", "sun.nio.ch.InheritedChannel", "InheritedSocketChannelImpl", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _InheritedChannel_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.ch.InheritedChannel",
	"java.lang.Object",
	nullptr,
	_InheritedChannel_FieldInfo_,
	_InheritedChannel_MethodInfo_,
	nullptr,
	nullptr,
	_InheritedChannel_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.nio.ch.InheritedChannel$InheritedDatagramChannelImpl,sun.nio.ch.InheritedChannel$InheritedServerSocketChannelImpl,sun.nio.ch.InheritedChannel$InheritedSocketChannelImpl"
};

$Object* allocate$InheritedChannel($Class* clazz) {
	return $of($alloc(InheritedChannel));
}

bool InheritedChannel::$assertionsDisabled = false;
int32_t InheritedChannel::devnull = 0;
bool InheritedChannel::haveChannel = false;
$Channel* InheritedChannel::channel = nullptr;

void InheritedChannel::init$() {
}

void InheritedChannel::detachIOStreams() {
	$init(InheritedChannel);
	try {
		dup2(InheritedChannel::devnull, 0);
		dup2(InheritedChannel::devnull, 1);
		dup2(InheritedChannel::devnull, 2);
	} catch ($IOException& ioe) {
		$throwNew($InternalError, static_cast<$Throwable*>(ioe));
	}
}

$ProtocolFamily* InheritedChannel::protocolFamily($SocketAddress* sa) {
	$init(InheritedChannel);
	$useLocalCurrentObjectStackCache();
	if ($instanceOf($UnixDomainSocketAddress, sa)) {
		$init($StandardProtocolFamily);
		return $StandardProtocolFamily::UNIX;
	} else {
		$var($InetSocketAddress, isa, $cast($InetSocketAddress, sa));
		$init($StandardProtocolFamily);
		return ($instanceOf($Inet6Address, $($nc(isa)->getAddress()))) ? static_cast<$ProtocolFamily*>($StandardProtocolFamily::INET6) : static_cast<$ProtocolFamily*>($StandardProtocolFamily::INET);
	}
}

$ProtocolFamily* InheritedChannel::protocolFamily(int32_t family) {
	$init(InheritedChannel);

	$var($ProtocolFamily, var$0, nullptr)
	switch (family) {
	case InheritedChannel::AF_INET:
		{
			$init($StandardProtocolFamily);
			$assign(var$0, $StandardProtocolFamily::INET);
			break;
		}
	case InheritedChannel::AF_INET6:
		{
			$init($StandardProtocolFamily);
			$assign(var$0, $StandardProtocolFamily::INET6);
			break;
		}
	case InheritedChannel::AF_UNIX:
		{
			$init($StandardProtocolFamily);
			$assign(var$0, $StandardProtocolFamily::UNIX);
			break;
		}
	default:
		{
			$throwNew($IllegalArgumentException);
		}
	}
	return var$0;
}

void InheritedChannel::checkAccess() {
	$init(InheritedChannel);
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission($$new($RuntimePermission, "inheritedChannel"_s));
	}
}

$Channel* InheritedChannel::createChannel() {
	$init(InheritedChannel);
	$useLocalCurrentObjectStackCache();
	int32_t fdVal = dup(0);
	int32_t st = 0;
	st = soType0(fdVal);
	if (st != InheritedChannel::SOCK_STREAM && st != InheritedChannel::SOCK_DGRAM) {
		close0(fdVal);
		return nullptr;
	}
	$init($Integer);
	$var($ClassArray, paramTypes, $new($ClassArray, {$Integer::TYPE}));
	$var($Constructor, ctr, $Reflect::lookupConstructor("java.io.FileDescriptor"_s, paramTypes));
	$var($ObjectArray, args, $new($ObjectArray, {$($of($Integer::valueOf(fdVal)))}));
	$var($FileDescriptor, fd, $cast($FileDescriptor, $Reflect::invoke(ctr, args)));
	$var($SelectorProvider, provider, $SelectorProvider::provider());
	if (!InheritedChannel::$assertionsDisabled && !$instanceOf($SelectorProviderImpl, provider)) {
		$throwNew($AssertionError);
	}
	$var($Channel, c, nullptr);
	if (st == InheritedChannel::SOCK_STREAM) {
		int32_t family = addressFamily(fdVal);
		if (family == InheritedChannel::AF_UNKNOWN) {
			return nullptr;
		}
		$var($ProtocolFamily, pfamily, protocolFamily(family));
		if (family == InheritedChannel::AF_UNIX) {
			if (isConnected(fdVal)) {
				$var($UnixDomainSocketAddress, sa, $UnixDomainSocketAddress::of($(unixPeerAddress(fdVal))));
				return static_cast<$Channel*>(static_cast<$InterruptibleChannel*>(static_cast<$AbstractInterruptibleChannel*>(static_cast<$SelectableChannel*>(static_cast<$AbstractSelectableChannel*>(static_cast<$SocketChannel*>(static_cast<$SocketChannelImpl*>($new($InheritedChannel$InheritedSocketChannelImpl, provider, fd, sa))))))));
			} else {
				return static_cast<$Channel*>(static_cast<$InterruptibleChannel*>(static_cast<$AbstractInterruptibleChannel*>(static_cast<$SelectableChannel*>(static_cast<$AbstractSelectableChannel*>(static_cast<$ServerSocketChannel*>(static_cast<$ServerSocketChannelImpl*>($new($InheritedChannel$InheritedServerSocketChannelImpl, provider, pfamily, fd))))))));
			}
		}
		$var($InetAddress, ia, inetPeerAddress0(fdVal));
		if (ia == nullptr) {
			$assign(c, static_cast<$Channel*>(static_cast<$InterruptibleChannel*>(static_cast<$AbstractInterruptibleChannel*>(static_cast<$SelectableChannel*>(static_cast<$AbstractSelectableChannel*>(static_cast<$ServerSocketChannel*>(static_cast<$ServerSocketChannelImpl*>($new($InheritedChannel$InheritedServerSocketChannelImpl, provider, pfamily, fd)))))))));
		} else {
			int32_t port = peerPort0(fdVal);
			if (!InheritedChannel::$assertionsDisabled && !(port > 0)) {
				$throwNew($AssertionError);
			}
			$var($InetSocketAddress, isa, $new($InetSocketAddress, ia, port));
			$assign(c, static_cast<$Channel*>(static_cast<$InterruptibleChannel*>(static_cast<$AbstractInterruptibleChannel*>(static_cast<$SelectableChannel*>(static_cast<$AbstractSelectableChannel*>(static_cast<$SocketChannel*>(static_cast<$SocketChannelImpl*>($new($InheritedChannel$InheritedSocketChannelImpl, provider, fd, isa)))))))));
		}
	} else {
		$assign(c, static_cast<$Channel*>(static_cast<$InterruptibleChannel*>(static_cast<$AbstractInterruptibleChannel*>(static_cast<$SelectableChannel*>(static_cast<$AbstractSelectableChannel*>(static_cast<$DatagramChannel*>(static_cast<$DatagramChannelImpl*>($new($InheritedChannel$InheritedDatagramChannelImpl, provider, fd)))))))));
	}
	return c;
}

$Channel* InheritedChannel::getChannel() {
	$load(InheritedChannel);
	$synchronized(class$) {
		$init(InheritedChannel);
		if (InheritedChannel::devnull < 0) {
			InheritedChannel::devnull = open0("/dev/null"_s, InheritedChannel::O_RDWR);
		}
		if (!InheritedChannel::haveChannel) {
			$assignStatic(InheritedChannel::channel, createChannel());
			InheritedChannel::haveChannel = true;
		}
		if (InheritedChannel::channel != nullptr) {
			checkAccess();
		}
		return InheritedChannel::channel;
	}
}

$String* InheritedChannel::unixPeerAddress(int32_t fd) {
	$init(InheritedChannel);
	$var($bytes, bytes, unixPeerAddress0(fd));
	return $new($String, bytes);
}

void InheritedChannel::initIDs() {
	$init(InheritedChannel);
	$prepareNativeStatic(InheritedChannel, initIDs, void);
	$invokeNativeStatic();
	$finishNativeStatic();
}

int32_t InheritedChannel::dup(int32_t fd) {
	$init(InheritedChannel);
	int32_t $ret = 0;
	$prepareNativeStatic(InheritedChannel, dup, int32_t, int32_t fd);
	$ret = $invokeNativeStatic(fd);
	$finishNativeStatic();
	return $ret;
}

void InheritedChannel::dup2(int32_t fd, int32_t fd2) {
	$init(InheritedChannel);
	$prepareNativeStatic(InheritedChannel, dup2, void, int32_t fd, int32_t fd2);
	$invokeNativeStatic(fd, fd2);
	$finishNativeStatic();
}

int32_t InheritedChannel::open0($String* path, int32_t oflag) {
	$init(InheritedChannel);
	int32_t $ret = 0;
	$prepareNativeStatic(InheritedChannel, open0, int32_t, $String* path, int32_t oflag);
	$ret = $invokeNativeStatic(path, oflag);
	$finishNativeStatic();
	return $ret;
}

void InheritedChannel::close0(int32_t fd) {
	$init(InheritedChannel);
	$prepareNativeStatic(InheritedChannel, close0, void, int32_t fd);
	$invokeNativeStatic(fd);
	$finishNativeStatic();
}

int32_t InheritedChannel::soType0(int32_t fd) {
	$init(InheritedChannel);
	int32_t $ret = 0;
	$prepareNativeStatic(InheritedChannel, soType0, int32_t, int32_t fd);
	$ret = $invokeNativeStatic(fd);
	$finishNativeStatic();
	return $ret;
}

int32_t InheritedChannel::addressFamily(int32_t fd) {
	$init(InheritedChannel);
	int32_t $ret = 0;
	$prepareNativeStatic(InheritedChannel, addressFamily, int32_t, int32_t fd);
	$ret = $invokeNativeStatic(fd);
	$finishNativeStatic();
	return $ret;
}

$InetAddress* InheritedChannel::inetPeerAddress0(int32_t fd) {
	$init(InheritedChannel);
	$var($InetAddress, $ret, nullptr);
	$prepareNativeStatic(InheritedChannel, inetPeerAddress0, $InetAddress*, int32_t fd);
	$assign($ret, $invokeNativeStaticObject(fd));
	$finishNativeStatic();
	return $ret;
}

$bytes* InheritedChannel::unixPeerAddress0(int32_t fd) {
	$init(InheritedChannel);
	$var($bytes, $ret, nullptr);
	$prepareNativeStatic(InheritedChannel, unixPeerAddress0, $bytes*, int32_t fd);
	$assign($ret, $invokeNativeStaticObject(fd));
	$finishNativeStatic();
	return $ret;
}

int32_t InheritedChannel::peerPort0(int32_t fd) {
	$init(InheritedChannel);
	int32_t $ret = 0;
	$prepareNativeStatic(InheritedChannel, peerPort0, int32_t, int32_t fd);
	$ret = $invokeNativeStatic(fd);
	$finishNativeStatic();
	return $ret;
}

bool InheritedChannel::isConnected(int32_t fd) {
	$init(InheritedChannel);
	bool $ret = false;
	$prepareNativeStatic(InheritedChannel, isConnected, bool, int32_t fd);
	$ret = $invokeNativeStatic(fd);
	$finishNativeStatic();
	return $ret;
}

void clinit$InheritedChannel($Class* class$) {
	InheritedChannel::$assertionsDisabled = !InheritedChannel::class$->desiredAssertionStatus();
	InheritedChannel::devnull = -1;
	InheritedChannel::haveChannel = false;
	$assignStatic(InheritedChannel::channel, nullptr);
	{
		$IOUtil::load();
		InheritedChannel::initIDs();
	}
}

InheritedChannel::InheritedChannel() {
}

$Class* InheritedChannel::load$($String* name, bool initialize) {
	$loadClass(InheritedChannel, name, initialize, &_InheritedChannel_ClassInfo_, clinit$InheritedChannel, allocate$InheritedChannel);
	return class$;
}

$Class* InheritedChannel::class$ = nullptr;

		} // ch
	} // nio
} // sun