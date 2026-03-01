#include <sun/net/www/protocol/mailto/Handler.h>

#include <java/net/URL.h>
#include <java/net/URLConnection.h>
#include <java/net/URLStreamHandler.h>
#include <sun/net/www/protocol/mailto/MailToURLConnection.h>
#include <jcpp.h>

using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $URL = ::java::net::URL;
using $URLConnection = ::java::net::URLConnection;
using $URLStreamHandler = ::java::net::URLStreamHandler;
using $MailToURLConnection = ::sun::net::www::protocol::mailto::MailToURLConnection;

namespace sun {
	namespace net {
		namespace www {
			namespace protocol {
				namespace mailto {

$MethodInfo _Handler_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Handler, init$, void)},
	{"openConnection", "(Ljava/net/URL;)Ljava/net/URLConnection;", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Handler, openConnection, $URLConnection*, $URL*)},
	{"parseURL", "(Ljava/net/URL;Ljava/lang/String;II)V", nullptr, $PUBLIC, $virtualMethod(Handler, parseURL, void, $URL*, $String*, int32_t, int32_t)},
	{"setURLHandler", "(Ljava/net/URL;Ljava/lang/String;Ljava/lang/String;ILjava/lang/String;Ljava/lang/String;)V", nullptr, $PRIVATE, $method(Handler, setURLHandler, void, $URL*, $String*, $String*, int32_t, $String*, $String*)},
	{}
};

$ClassInfo _Handler_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.net.www.protocol.mailto.Handler",
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

$URLConnection* Handler::openConnection($URL* u) {
	$synchronized(this) {
		return $new($MailToURLConnection, u);
	}
}

void Handler::parseURL($URL* u, $String* spec, int32_t start, int32_t limit) {
	$useLocalCurrentObjectStackCache();
	$var($String, protocol, $nc(u)->getProtocol());
	$var($String, host, ""_s);
	int32_t port = u->getPort();
	$var($String, file, ""_s);
	if (start < limit) {
		$assign(file, $nc(spec)->substring(start, limit));
	}
	bool nogood = false;
	if (file == nullptr || file->isEmpty()) {
		nogood = true;
	} else {
		bool allwhites = true;
		for (int32_t i = 0; i < file->length(); ++i) {
			if (!$Character::isWhitespace(file->charAt(i))) {
				allwhites = false;
			}
		}
		if (allwhites) {
			nogood = true;
		}
	}
	if (nogood) {
		$throwNew($RuntimeException, "No email address"_s);
	}
	setURLHandler(u, protocol, host, port, file, nullptr);
}

void Handler::setURLHandler($URL* u, $String* protocol, $String* host, int32_t port, $String* file, $String* ref) {
	setURL(u, protocol, host, port, file, nullptr);
}

Handler::Handler() {
}

$Class* Handler::load$($String* name, bool initialize) {
	$loadClass(Handler, name, initialize, &_Handler_ClassInfo_, allocate$Handler);
	return class$;
}

$Class* Handler::class$ = nullptr;

				} // mailto
			} // protocol
		} // www
	} // net
} // sun