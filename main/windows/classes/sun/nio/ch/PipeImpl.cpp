#include <sun/nio/ch/PipeImpl.h>

#include <java/io/IOException.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/net/InetAddress.h>
#include <java/net/InetSocketAddress.h>
#include <java/net/ProtocolFamily.h>
#include <java/net/SocketAddress.h>
#include <java/net/SocketOption.h>
#include <java/net/StandardProtocolFamily.h>
#include <java/net/StandardSocketOptions.h>
#include <java/nio/channels/NetworkChannel.h>
#include <java/nio/channels/Pipe$SinkChannel.h>
#include <java/nio/channels/Pipe$SourceChannel.h>
#include <java/nio/channels/Pipe.h>
#include <java/nio/channels/ServerSocketChannel.h>
#include <java/nio/channels/spi/AbstractInterruptibleChannel.h>
#include <java/nio/channels/spi/SelectorProvider.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedActionException.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/security/SecureRandom.h>
#include <java/util/Random.h>
#include <sun/nio/ch/PipeImpl$Initializer.h>
#include <sun/nio/ch/SinkChannelImpl.h>
#include <sun/nio/ch/SourceChannelImpl.h>
#include <jcpp.h>

#undef NUM_SECRET_BYTES
#undef RANDOM_NUMBER_GENERATOR
#undef TCP_NODELAY
#undef UNIX

using $IOException = ::java::io::IOException;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $InetAddress = ::java::net::InetAddress;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $ProtocolFamily = ::java::net::ProtocolFamily;
using $SocketAddress = ::java::net::SocketAddress;
using $StandardProtocolFamily = ::java::net::StandardProtocolFamily;
using $StandardSocketOptions = ::java::net::StandardSocketOptions;
using $Pipe = ::java::nio::channels::Pipe;
using $Pipe$SinkChannel = ::java::nio::channels::Pipe$SinkChannel;
using $Pipe$SourceChannel = ::java::nio::channels::Pipe$SourceChannel;
using $ServerSocketChannel = ::java::nio::channels::ServerSocketChannel;
using $SelectorProvider = ::java::nio::channels::spi::SelectorProvider;
using $AccessController = ::java::security::AccessController;
using $PrivilegedActionException = ::java::security::PrivilegedActionException;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $SecureRandom = ::java::security::SecureRandom;
using $Random = ::java::util::Random;
using $PipeImpl$Initializer = ::sun::nio::ch::PipeImpl$Initializer;
using $SinkChannelImpl = ::sun::nio::ch::SinkChannelImpl;

namespace sun {
	namespace nio {
		namespace ch {

$FieldInfo _PipeImpl_FieldInfo_[] = {
	{"NUM_SECRET_BYTES", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(PipeImpl, NUM_SECRET_BYTES)},
	{"RANDOM_NUMBER_GENERATOR", "Ljava/util/Random;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PipeImpl, RANDOM_NUMBER_GENERATOR)},
	{"source", "Lsun/nio/ch/SourceChannelImpl;", nullptr, $PRIVATE | $FINAL, $field(PipeImpl, source$)},
	{"sink", "Lsun/nio/ch/SinkChannelImpl;", nullptr, $PRIVATE | $FINAL, $field(PipeImpl, sink$)},
	{"noUnixDomainSockets", "Z", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(PipeImpl, noUnixDomainSockets)},
	{}
};

$MethodInfo _PipeImpl_MethodInfo_[] = {
	{"<init>", "(Ljava/nio/channels/spi/SelectorProvider;)V", nullptr, 0, $method(PipeImpl, init$, void, $SelectorProvider*), "java.io.IOException"},
	{"<init>", "(Ljava/nio/channels/spi/SelectorProvider;Z)V", nullptr, 0, $method(PipeImpl, init$, void, $SelectorProvider*, bool), "java.io.IOException"},
	{"createListener", "()Ljava/nio/channels/ServerSocketChannel;", nullptr, $PRIVATE | $STATIC, $staticMethod(PipeImpl, createListener, $ServerSocketChannel*), "java.io.IOException"},
	{"sink", "()Lsun/nio/ch/SinkChannelImpl;", nullptr, $PUBLIC, $virtualMethod(PipeImpl, sink, $Pipe$SinkChannel*)},
	{"source", "()Lsun/nio/ch/SourceChannelImpl;", nullptr, $PUBLIC, $virtualMethod(PipeImpl, source, $Pipe$SourceChannel*)},
	{}
};

$InnerClassInfo _PipeImpl_InnerClassesInfo_[] = {
	{"sun.nio.ch.PipeImpl$Initializer", "sun.nio.ch.PipeImpl", "Initializer", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _PipeImpl_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.ch.PipeImpl",
	"java.nio.channels.Pipe",
	nullptr,
	_PipeImpl_FieldInfo_,
	_PipeImpl_MethodInfo_,
	nullptr,
	nullptr,
	_PipeImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.nio.ch.PipeImpl$Initializer,sun.nio.ch.PipeImpl$Initializer$LoopbackConnector,sun.nio.ch.PipeImpl$Initializer$1"
};

$Object* allocate$PipeImpl($Class* clazz) {
	return $of($alloc(PipeImpl));
}

$Random* PipeImpl::RANDOM_NUMBER_GENERATOR = nullptr;
$volatile(bool) PipeImpl::noUnixDomainSockets = false;

void PipeImpl::init$($SelectorProvider* sp) {
	PipeImpl::init$(sp, true);
}

void PipeImpl::init$($SelectorProvider* sp, bool buffering) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$Pipe::init$();
	$var($PipeImpl$Initializer, initializer, $new($PipeImpl$Initializer, sp));
	try {
		$AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>(initializer));
		$var($SinkChannelImpl, sink, initializer->sink);
		if ($nc(sink)->isNetSocket() && !buffering) {
			$init($StandardSocketOptions);
			sink->setOption($StandardSocketOptions::TCP_NODELAY, $($Boolean::valueOf(true)));
		}
	} catch ($PrivilegedActionException& pae) {
		$throw($cast($IOException, $(pae->getCause())));
	}
	$set(this, source$, initializer->source);
	$set(this, sink$, initializer->sink);
}

$Pipe$SourceChannel* PipeImpl::source() {
	return this->source$;
}

$Pipe$SinkChannel* PipeImpl::sink() {
	return this->sink$;
}

$ServerSocketChannel* PipeImpl::createListener() {
	$init(PipeImpl);
	$useLocalCurrentObjectStackCache();
	$var($ServerSocketChannel, listener, nullptr);
	if (!PipeImpl::noUnixDomainSockets) {
		try {
			$init($StandardProtocolFamily);
			$assign(listener, $ServerSocketChannel::open($StandardProtocolFamily::UNIX));
			return $cast($ServerSocketChannel, $nc(listener)->bind(nullptr));
		} catch ($UnsupportedOperationException& e) {
			PipeImpl::noUnixDomainSockets = true;
			if (listener != nullptr) {
				listener->close();
			}
		} catch ($IOException& e) {
			PipeImpl::noUnixDomainSockets = true;
			if (listener != nullptr) {
				listener->close();
			}
		}
	}
	$assign(listener, $ServerSocketChannel::open());
	$var($InetAddress, lb, $InetAddress::getLoopbackAddress());
	$nc(listener)->bind($$new($InetSocketAddress, lb, 0));
	return listener;
}

void clinit$PipeImpl($Class* class$) {
	$assignStatic(PipeImpl::RANDOM_NUMBER_GENERATOR, $new($SecureRandom));
}

PipeImpl::PipeImpl() {
}

$Class* PipeImpl::load$($String* name, bool initialize) {
	$loadClass(PipeImpl, name, initialize, &_PipeImpl_ClassInfo_, clinit$PipeImpl, allocate$PipeImpl);
	return class$;
}

$Class* PipeImpl::class$ = nullptr;

		} // ch
	} // nio
} // sun