#include <sun/net/www/protocol/jrt/Handler.h>

#include <java/net/URL.h>
#include <java/net/URLConnection.h>
#include <java/net/URLStreamHandler.h>
#include <sun/net/www/protocol/jrt/JavaRuntimeURLConnection.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $URL = ::java::net::URL;
using $URLConnection = ::java::net::URLConnection;
using $URLStreamHandler = ::java::net::URLStreamHandler;
using $JavaRuntimeURLConnection = ::sun::net::www::protocol::jrt::JavaRuntimeURLConnection;

namespace sun {
	namespace net {
		namespace www {
			namespace protocol {
				namespace jrt {

$MethodInfo _Handler_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Handler, init$, void)},
	{"openConnection", "(Ljava/net/URL;)Ljava/net/URLConnection;", nullptr, $PROTECTED, $virtualMethod(Handler, openConnection, $URLConnection*, $URL*), "java.io.IOException"},
	{}
};

$ClassInfo _Handler_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.net.www.protocol.jrt.Handler",
	"java.net.URLStreamHandler",
	nullptr,
	nullptr,
	_Handler_MethodInfo_
};

$Object* allocate$Handler($Class* clazz) {
	return $of($alloc(Handler));
}

void Handler::init$() {
	$URLStreamHandler::init$();
}

$URLConnection* Handler::openConnection($URL* url) {
	return $new($JavaRuntimeURLConnection, url);
}

Handler::Handler() {
}

$Class* Handler::load$($String* name, bool initialize) {
	$loadClass(Handler, name, initialize, &_Handler_ClassInfo_, allocate$Handler);
	return class$;
}

$Class* Handler::class$ = nullptr;

				} // jrt
			} // protocol
		} // www
	} // net
} // sun