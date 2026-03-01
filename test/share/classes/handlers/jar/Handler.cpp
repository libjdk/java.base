#include <handlers/jar/Handler.h>

#include <java/net/URL.h>
#include <java/net/URLConnection.h>
#include <java/net/URLStreamHandler.h>
#include <java/util/Collections.h>
#include <java/util/HashSet.h>
#include <java/util/Set.h>
#include <jcpp.h>

#undef URLS

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $URL = ::java::net::URL;
using $URLConnection = ::java::net::URLConnection;
using $URLStreamHandler = ::java::net::URLStreamHandler;
using $Collections = ::java::util::Collections;
using $HashSet = ::java::util::HashSet;
using $Set = ::java::util::Set;

namespace handlers {
	namespace jar {

$FieldInfo _Handler_FieldInfo_[] = {
	{"URLS", "Ljava/util/Set;", "Ljava/util/Set<Ljava/net/URL;>;", $PUBLIC | $STATIC, $staticField(Handler, URLS)},
	{}
};

$MethodInfo _Handler_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Handler, init$, void)},
	{"openConnection", "(Ljava/net/URL;)Ljava/net/URLConnection;", nullptr, $PROTECTED, $virtualMethod(Handler, openConnection, $URLConnection*, $URL*), "java.io.IOException"},
	{}
};

$ClassInfo _Handler_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"handlers.jar.Handler",
	"java.net.URLStreamHandler",
	nullptr,
	_Handler_FieldInfo_,
	_Handler_MethodInfo_
};

$Object* allocate$Handler($Class* clazz) {
	return $of($alloc(Handler));
}

$Set* Handler::URLS = nullptr;

void Handler::init$() {
	$URLStreamHandler::init$();
}

$URLConnection* Handler::openConnection($URL* u) {
	$nc(Handler::URLS)->add(u);
	return nullptr;
}

void clinit$Handler($Class* class$) {
	$assignStatic(Handler::URLS, $Collections::synchronizedSet($$new($HashSet)));
}

Handler::Handler() {
}

$Class* Handler::load$($String* name, bool initialize) {
	$loadClass(Handler, name, initialize, &_Handler_ClassInfo_, clinit$Handler, allocate$Handler);
	return class$;
}

$Class* Handler::class$ = nullptr;

	} // jar
} // handlers