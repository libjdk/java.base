#include <javax/net/SocketFactory.h>

#include <java/lang/UnsupportedOperationException.h>
#include <java/net/InetAddress.h>
#include <java/net/Socket.h>
#include <java/net/SocketException.h>
#include <javax/net/DefaultSocketFactory.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $InetAddress = ::java::net::InetAddress;
using $Socket = ::java::net::Socket;
using $SocketException = ::java::net::SocketException;
using $DefaultSocketFactory = ::javax::net::DefaultSocketFactory;

namespace javax {
	namespace net {

$FieldInfo _SocketFactory_FieldInfo_[] = {
	{"theFactory", "Ljavax/net/SocketFactory;", nullptr, $PRIVATE | $STATIC, $staticField(SocketFactory, theFactory)},
	{}
};

$MethodInfo _SocketFactory_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PROTECTED, $method(SocketFactory, init$, void)},
	{"createSocket", "()Ljava/net/Socket;", nullptr, $PUBLIC, $virtualMethod(SocketFactory, createSocket, $Socket*), "java.io.IOException"},
	{"createSocket", "(Ljava/lang/String;I)Ljava/net/Socket;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(SocketFactory, createSocket, $Socket*, $String*, int32_t), "java.io.IOException,java.net.UnknownHostException"},
	{"createSocket", "(Ljava/lang/String;ILjava/net/InetAddress;I)Ljava/net/Socket;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(SocketFactory, createSocket, $Socket*, $String*, int32_t, $InetAddress*, int32_t), "java.io.IOException,java.net.UnknownHostException"},
	{"createSocket", "(Ljava/net/InetAddress;I)Ljava/net/Socket;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(SocketFactory, createSocket, $Socket*, $InetAddress*, int32_t), "java.io.IOException"},
	{"createSocket", "(Ljava/net/InetAddress;ILjava/net/InetAddress;I)Ljava/net/Socket;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(SocketFactory, createSocket, $Socket*, $InetAddress*, int32_t, $InetAddress*, int32_t), "java.io.IOException"},
	{"getDefault", "()Ljavax/net/SocketFactory;", nullptr, $PUBLIC | $STATIC, $staticMethod(SocketFactory, getDefault, SocketFactory*)},
	{}
};

$ClassInfo _SocketFactory_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"javax.net.SocketFactory",
	"java.lang.Object",
	nullptr,
	_SocketFactory_FieldInfo_,
	_SocketFactory_MethodInfo_
};

$Object* allocate$SocketFactory($Class* clazz) {
	return $of($alloc(SocketFactory));
}

SocketFactory* SocketFactory::theFactory = nullptr;

void SocketFactory::init$() {
}

SocketFactory* SocketFactory::getDefault() {
	$load(SocketFactory);
	$synchronized(SocketFactory::class$) {
		$init(SocketFactory);
		if (SocketFactory::theFactory == nullptr) {
			$assignStatic(SocketFactory::theFactory, $new($DefaultSocketFactory));
		}
	}
	$init(SocketFactory);
	return SocketFactory::theFactory;
}

$Socket* SocketFactory::createSocket() {
	$useLocalCurrentObjectStackCache();
	$var($UnsupportedOperationException, uop, $new($UnsupportedOperationException));
	$var($SocketException, se, $new($SocketException, "Unconnected sockets not implemented"_s));
	se->initCause(uop);
	$throw(se);
	$shouldNotReachHere();
}

SocketFactory::SocketFactory() {
}

$Class* SocketFactory::load$($String* name, bool initialize) {
	$loadClass(SocketFactory, name, initialize, &_SocketFactory_ClassInfo_, allocate$SocketFactory);
	return class$;
}

$Class* SocketFactory::class$ = nullptr;

	} // net
} // javax