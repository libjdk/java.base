#include <BadProxySelector$NullHTTPProxySelector.h>

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

$MethodInfo _BadProxySelector$NullHTTPProxySelector_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(BadProxySelector$NullHTTPProxySelector, init$, void)},
	{"connectFailed", "(Ljava/net/URI;Ljava/net/SocketAddress;Ljava/io/IOException;)V", nullptr, $PUBLIC, $virtualMethod(BadProxySelector$NullHTTPProxySelector, connectFailed, void, $URI*, $SocketAddress*, $IOException*)},
	{"select", "(Ljava/net/URI;)Ljava/util/List;", "(Ljava/net/URI;)Ljava/util/List<Ljava/net/Proxy;>;", $PUBLIC, $virtualMethod(BadProxySelector$NullHTTPProxySelector, select, $List*, $URI*)},
	{}
};

$InnerClassInfo _BadProxySelector$NullHTTPProxySelector_InnerClassesInfo_[] = {
	{"BadProxySelector$NullHTTPProxySelector", "BadProxySelector", "NullHTTPProxySelector", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _BadProxySelector$NullHTTPProxySelector_ClassInfo_ = {
	$ACC_SUPER,
	"BadProxySelector$NullHTTPProxySelector",
	"java.net.ProxySelector",
	nullptr,
	nullptr,
	_BadProxySelector$NullHTTPProxySelector_MethodInfo_,
	nullptr,
	nullptr,
	_BadProxySelector$NullHTTPProxySelector_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"BadProxySelector"
};

$Object* allocate$BadProxySelector$NullHTTPProxySelector($Class* clazz) {
	return $of($alloc(BadProxySelector$NullHTTPProxySelector));
}

void BadProxySelector$NullHTTPProxySelector::init$() {
	$ProxySelector::init$();
}

void BadProxySelector$NullHTTPProxySelector::connectFailed($URI* uri, $SocketAddress* sa, $IOException* ioe) {
}

$List* BadProxySelector$NullHTTPProxySelector::select($URI* uri) {
	$useLocalCurrentObjectStackCache();
	$nc($System::out)->println($$str({$($of(this)->getClass()->getSimpleName()), " called for "_s, uri}));
	$var($List, proxies, $new($ArrayList));
	proxies->add(nullptr);
	$init($Proxy$Type);
	proxies->add($$new($Proxy, $Proxy$Type::HTTP, $$new($InetSocketAddress, "localhost"_s, 0)));
	return proxies;
}

BadProxySelector$NullHTTPProxySelector::BadProxySelector$NullHTTPProxySelector() {
}

$Class* BadProxySelector$NullHTTPProxySelector::load$($String* name, bool initialize) {
	$loadClass(BadProxySelector$NullHTTPProxySelector, name, initialize, &_BadProxySelector$NullHTTPProxySelector_ClassInfo_, allocate$BadProxySelector$NullHTTPProxySelector);
	return class$;
}

$Class* BadProxySelector$NullHTTPProxySelector::class$ = nullptr;