#include <BadProxySelector$HTTPProxySelector.h>

#include <BadProxySelector.h>
#include <java/io/IOException.h>
#include <java/net/InetSocketAddress.h>
#include <java/net/Proxy$Type.h>
#include <java/net/Proxy.h>
#include <java/net/ProxySelector.h>
#include <java/net/SocketAddress.h>
#include <java/net/URI.h>
#include <java/util/ArrayList.h>
#include <java/util/List.h>
#include <jcpp.h>

#undef HTTP

using $IOException = ::java::io::IOException;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $Proxy = ::java::net::Proxy;
using $Proxy$Type = ::java::net::Proxy$Type;
using $ProxySelector = ::java::net::ProxySelector;
using $SocketAddress = ::java::net::SocketAddress;
using $URI = ::java::net::URI;
using $ArrayList = ::java::util::ArrayList;
using $List = ::java::util::List;

$MethodInfo _BadProxySelector$HTTPProxySelector_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(BadProxySelector$HTTPProxySelector, init$, void)},
	{"connectFailed", "(Ljava/net/URI;Ljava/net/SocketAddress;Ljava/io/IOException;)V", nullptr, $PUBLIC, $virtualMethod(BadProxySelector$HTTPProxySelector, connectFailed, void, $URI*, $SocketAddress*, $IOException*)},
	{"select", "(Ljava/net/URI;)Ljava/util/List;", "(Ljava/net/URI;)Ljava/util/List<Ljava/net/Proxy;>;", $PUBLIC, $virtualMethod(BadProxySelector$HTTPProxySelector, select, $List*, $URI*)},
	{}
};

$InnerClassInfo _BadProxySelector$HTTPProxySelector_InnerClassesInfo_[] = {
	{"BadProxySelector$HTTPProxySelector", "BadProxySelector", "HTTPProxySelector", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _BadProxySelector$HTTPProxySelector_ClassInfo_ = {
	$ACC_SUPER,
	"BadProxySelector$HTTPProxySelector",
	"java.net.ProxySelector",
	nullptr,
	nullptr,
	_BadProxySelector$HTTPProxySelector_MethodInfo_,
	nullptr,
	nullptr,
	_BadProxySelector$HTTPProxySelector_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"BadProxySelector"
};

$Object* allocate$BadProxySelector$HTTPProxySelector($Class* clazz) {
	return $of($alloc(BadProxySelector$HTTPProxySelector));
}

void BadProxySelector$HTTPProxySelector::init$() {
	$ProxySelector::init$();
}

void BadProxySelector$HTTPProxySelector::connectFailed($URI* uri, $SocketAddress* sa, $IOException* ioe) {
}

$List* BadProxySelector$HTTPProxySelector::select($URI* uri) {
	$useLocalCurrentObjectStackCache();
	$nc($System::out)->println($$str({$($of(this)->getClass()->getSimpleName()), " called for "_s, uri}));
	$var($List, proxies, $new($ArrayList));
	$init($Proxy$Type);
	proxies->add($$new($Proxy, $Proxy$Type::HTTP, $$new($InetSocketAddress, "localhost"_s, 0)));
	proxies->add($$new($Proxy, $Proxy$Type::HTTP, $$new($InetSocketAddress, "localhost"_s, 0)));
	return proxies;
}

BadProxySelector$HTTPProxySelector::BadProxySelector$HTTPProxySelector() {
}

$Class* BadProxySelector$HTTPProxySelector::load$($String* name, bool initialize) {
	$loadClass(BadProxySelector$HTTPProxySelector, name, initialize, &_BadProxySelector$HTTPProxySelector_ClassInfo_, allocate$BadProxySelector$HTTPProxySelector);
	return class$;
}

$Class* BadProxySelector$HTTPProxySelector::class$ = nullptr;