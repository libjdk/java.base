#include <URIToURLTest2.h>

#include <java/net/MalformedURLException.h>
#include <java/net/URI.h>
#include <java/net/URL.h>
#include <java/util/ArrayList.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <jcpp.h>

using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $MalformedURLException = ::java::net::MalformedURLException;
using $URI = ::java::net::URI;
using $URL = ::java::net::URL;
using $ArrayList = ::java::util::ArrayList;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;

$MethodInfo _URIToURLTest2_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(URIToURLTest2, init$, void)},
	{"hasFtp", "()Z", nullptr, $PRIVATE | $STATIC, $staticMethod(URIToURLTest2, hasFtp, bool)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(URIToURLTest2, main, void, $StringArray*), "java.lang.Exception"},
	{}
};

$ClassInfo _URIToURLTest2_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"URIToURLTest2",
	"java.lang.Object",
	nullptr,
	nullptr,
	_URIToURLTest2_MethodInfo_
};

$Object* allocate$URIToURLTest2($Class* clazz) {
	return $of($alloc(URIToURLTest2));
}

void URIToURLTest2::init$() {
}

void URIToURLTest2::main($StringArray* args) {
	$useLocalCurrentObjectStackCache();
	$var($List, uris, $new($ArrayList));
	uris->add("http://jag:cafebabe@java.sun.com:94/b/c/d?q#g"_s);
	uris->add("http://[1080:0:0:0:8:800:200C:417A]/index.html"_s);
	uris->add("http://a/b/c/d;p?q"_s);
	uris->add("mailto:mduerst@ifi.unizh.ch"_s);
	uris->add("http:comp.infosystems.www.servers.unix"_s);
	if (hasFtp()) {
		uris->add("ftp://ftp.is.co.za/rfc/rfc1808.txt"_s);
	}
	{
		$var($Iterator, i$, uris->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, uriStr, $cast($String, i$->next()));
			{
				$var($URI, uri, $new($URI, uriStr));
				$var($URL, url, uri->toURL());
				$var($String, scheme, uri->getScheme());
				bool schemeCheck = scheme == nullptr ? $nc(url)->getProtocol() == nullptr : $nc(scheme)->equals($(url->getProtocol()));
				if (!schemeCheck) {
					$throwNew($RuntimeException, $$str({"uri.scheme is "_s, scheme, " url.protocol is "_s, $(url->getProtocol())}));
				}
				if (uri->isOpaque()) {
					$var($String, ssp, uri->getSchemeSpecificPart());
					bool sspCheck = ssp == nullptr ? uri->getPath() == nullptr : $nc(ssp)->equals($(url->getPath()));
					if (!sspCheck) {
						$throwNew($RuntimeException, $$str({"uri.ssp is "_s, ssp, " url.path is "_s, $(url->getPath())}));
					}
				} else {
					$var($String, authority, uri->getAuthority());
					bool authorityCheck = authority == nullptr ? url->getAuthority() == nullptr : $nc(authority)->equals($(url->getAuthority()));
					if (!authorityCheck) {
						$throwNew($RuntimeException, $$str({"uri.authority is "_s, authority, " url\'s is "_s, $(url->getAuthority())}));
					}
					$var($String, host, uri->getHost());
					bool hostCheck = host == nullptr ? url->getHost() == nullptr : $nc(host)->equals($(url->getHost()));
					if (!hostCheck) {
						$throwNew($RuntimeException, $$str({"uri.host is "_s, host, " url\'s is "_s, $(url->getHost())}));
					}
					if (host != nullptr) {
						$var($String, userInfo, uri->getUserInfo());
						bool userInfoCheck = userInfo == nullptr ? url->getUserInfo() == nullptr : $nc(userInfo)->equals($(url->getUserInfo()));
						int32_t var$0 = uri->getPort();
						if (var$0 != url->getPort()) {
							$var($String, var$1, $$str({"uri.port is "_s, $$str(uri->getPort()), " url\'s is "_s}));
							$throwNew($RuntimeException, $$concat(var$1, $$str(url->getPort())));
						}
					}
					$var($String, path, uri->getPath());
					bool pathCheck = path == nullptr ? url->getPath() == nullptr : $nc(path)->equals($(url->getPath()));
					if (!pathCheck) {
						$throwNew($RuntimeException, $$str({"uri.path is "_s, path, " url.path is "_s, $(url->getPath())}));
					}
					$var($String, query, uri->getQuery());
					bool queryCheck = query == nullptr ? url->getQuery() == nullptr : $nc(query)->equals($(url->getQuery()));
					if (!queryCheck) {
						$throwNew($RuntimeException, $$str({"uri.query is "_s, query, " url.query is "_s, $(url->getQuery())}));
					}
				}
				$var($String, frag, uri->getFragment());
				bool fragCheck = frag == nullptr ? url->getRef() == nullptr : $nc(frag)->equals($(url->getRef()));
				if (!fragCheck) {
					$throwNew($RuntimeException, $$str({"uri.frag is "_s, frag, " url.ref is "_s, $(url->getRef())}));
				}
			}
		}
	}
}

bool URIToURLTest2::hasFtp() {
	try {
		return $new($URL, "ftp://"_s) != nullptr;
	} catch ($MalformedURLException& x) {
		$nc($System::out)->println("FTP not supported by this runtime."_s);
		return false;
	}
	$shouldNotReachHere();
}

URIToURLTest2::URIToURLTest2() {
}

$Class* URIToURLTest2::load$($String* name, bool initialize) {
	$loadClass(URIToURLTest2, name, initialize, &_URIToURLTest2_ClassInfo_, allocate$URIToURLTest2);
	return class$;
}

$Class* URIToURLTest2::class$ = nullptr;