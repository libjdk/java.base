#include <sun/net/www/protocol/file/Handler.h>

#include <java/io/File.h>
#include <java/io/IOException.h>
#include <java/net/Proxy.h>
#include <java/net/URL.h>
#include <java/net/URLConnection.h>
#include <java/net/URLStreamHandler.h>
#include <sun/net/www/ParseUtil.h>
#include <sun/net/www/protocol/file/FileURLConnection.h>
#include <sun/net/www/protocol/file/UNCFileURLConnection.h>
#include <jcpp.h>

using $File = ::java::io::File;
using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Proxy = ::java::net::Proxy;
using $URL = ::java::net::URL;
using $URLConnection = ::java::net::URLConnection;
using $URLStreamHandler = ::java::net::URLStreamHandler;
using $ParseUtil = ::sun::net::www::ParseUtil;
using $FileURLConnection = ::sun::net::www::protocol::file::FileURLConnection;
using $UNCFileURLConnection = ::sun::net::www::protocol::file::UNCFileURLConnection;

namespace sun {
	namespace net {
		namespace www {
			namespace protocol {
				namespace file {

$MethodInfo _Handler_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Handler, init$, void)},
	{"createFileURLConnection", "(Ljava/net/URL;Ljava/io/File;)Ljava/net/URLConnection;", nullptr, $PROTECTED, $virtualMethod(Handler, createFileURLConnection, $URLConnection*, $URL*, $File*)},
	{"getHost", "(Ljava/net/URL;)Ljava/lang/String;", nullptr, $PRIVATE, $method(Handler, getHost, $String*, $URL*)},
	{"hostsEqual", "(Ljava/net/URL;Ljava/net/URL;)Z", nullptr, $PROTECTED, $virtualMethod(Handler, hostsEqual, bool, $URL*, $URL*)},
	{"openConnection", "(Ljava/net/URL;)Ljava/net/URLConnection;", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Handler, openConnection, $URLConnection*, $URL*), "java.io.IOException"},
	{"openConnection", "(Ljava/net/URL;Ljava/net/Proxy;)Ljava/net/URLConnection;", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Handler, openConnection, $URLConnection*, $URL*, $Proxy*), "java.io.IOException"},
	{"parseURL", "(Ljava/net/URL;Ljava/lang/String;II)V", nullptr, $PROTECTED, $virtualMethod(Handler, parseURL, void, $URL*, $String*, int32_t, int32_t)},
	{}
};

$ClassInfo _Handler_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.net.www.protocol.file.Handler",
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

$String* Handler::getHost($URL* url) {
	$var($String, host, $nc(url)->getHost());
	if (host == nullptr) {
		$assign(host, ""_s);
	}
	return host;
}

void Handler::parseURL($URL* u, $String* spec, int32_t start, int32_t limit) {
	$init($File);
	$URLStreamHandler::parseURL(u, $($nc(spec)->replace($File::separatorChar, u'/')), start, limit);
}

$URLConnection* Handler::openConnection($URL* url) {
	$synchronized(this) {
		return openConnection(url, nullptr);
	}
}

$URLConnection* Handler::openConnection($URL* url, $Proxy* p) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$var($String, path, nullptr);
		$var($String, file, $nc(url)->getFile());
		$var($String, host, url->getHost());
		$assign(path, $ParseUtil::decode(file));
		$assign(path, $nc(path)->replace(u'/', u'\\'));
		$assign(path, path->replace(u'|', u':'));
		bool var$1 = (host == nullptr) || $nc(host)->isEmpty();
		bool var$0 = var$1 || $nc(host)->equalsIgnoreCase("localhost"_s);
		if (var$0 || $nc(host)->equals("~"_s)) {
			return createFileURLConnection(url, $$new($File, path));
		}
		$assign(path, $str({"\\\\"_s, host, path}));
		$var($File, f, $new($File, path));
		if (f->exists()) {
			return $new($UNCFileURLConnection, url, f, path);
		}
		$var($URLConnection, uc, nullptr);
		$var($URL, newurl, nullptr);
		try {
			$assign(newurl, $new($URL, "ftp"_s, host, $$str({file, (url->getRef() == nullptr ? ""_s : $$str({"#"_s, $(url->getRef())}))})));
			if (p != nullptr) {
				$assign(uc, newurl->openConnection(p));
			} else {
				$assign(uc, newurl->openConnection());
			}
		} catch ($IOException& e) {
			$assign(uc, nullptr);
		}
		if (uc == nullptr) {
			$throwNew($IOException, $$str({"Unable to connect to: "_s, $(url->toExternalForm())}));
		}
		return uc;
	}
}

$URLConnection* Handler::createFileURLConnection($URL* url, $File* file) {
	return $new($FileURLConnection, url, file);
}

bool Handler::hostsEqual($URL* u1, $URL* u2) {
	$useLocalCurrentObjectStackCache();
	$var($String, s1, $nc(u1)->getHost());
	$var($String, s2, $nc(u2)->getHost());
	bool var$0 = "localhost"_s->equalsIgnoreCase(s1);
	if (var$0 && (s2 == nullptr || $nc(s2)->isEmpty())) {
		return true;
	}
	bool var$1 = "localhost"_s->equalsIgnoreCase(s2);
	if (var$1 && (s1 == nullptr || $nc(s1)->isEmpty())) {
		return true;
	}
	return $URLStreamHandler::hostsEqual(u1, u2);
}

Handler::Handler() {
}

$Class* Handler::load$($String* name, bool initialize) {
	$loadClass(Handler, name, initialize, &_Handler_ClassInfo_, allocate$Handler);
	return class$;
}

$Class* Handler::class$ = nullptr;

				} // file
			} // protocol
		} // www
	} // net
} // sun