#include <sun/nio/ch/AsynchronousSocketChannelImpl$DefaultOptionsHolder.h>

#include <java/net/SocketOption.h>
#include <java/net/StandardSocketOptions.h>
#include <java/util/AbstractCollection.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/HashSet.h>
#include <java/util/Set.h>
#include <sun/net/ext/ExtendedSocketOptions.h>
#include <sun/nio/ch/AsynchronousSocketChannelImpl.h>
#include <sun/nio/ch/Net.h>
#include <jcpp.h>

#undef SO_KEEPALIVE
#undef SO_RCVBUF
#undef SO_REUSEADDR
#undef SO_REUSEPORT
#undef SO_SNDBUF
#undef TCP_NODELAY

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $StandardSocketOptions = ::java::net::StandardSocketOptions;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $HashSet = ::java::util::HashSet;
using $Set = ::java::util::Set;
using $ExtendedSocketOptions = ::sun::net::ext::ExtendedSocketOptions;
using $Net = ::sun::nio::ch::Net;

namespace sun {
	namespace nio {
		namespace ch {

$FieldInfo _AsynchronousSocketChannelImpl$DefaultOptionsHolder_FieldInfo_[] = {
	{"defaultOptions", "Ljava/util/Set;", "Ljava/util/Set<Ljava/net/SocketOption<*>;>;", $STATIC | $FINAL, $staticField(AsynchronousSocketChannelImpl$DefaultOptionsHolder, defaultOptions$)},
	{}
};

$MethodInfo _AsynchronousSocketChannelImpl$DefaultOptionsHolder_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(AsynchronousSocketChannelImpl$DefaultOptionsHolder, init$, void)},
	{"defaultOptions", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/net/SocketOption<*>;>;", $PRIVATE | $STATIC, $staticMethod(AsynchronousSocketChannelImpl$DefaultOptionsHolder, defaultOptions, $Set*)},
	{}
};

$InnerClassInfo _AsynchronousSocketChannelImpl$DefaultOptionsHolder_InnerClassesInfo_[] = {
	{"sun.nio.ch.AsynchronousSocketChannelImpl$DefaultOptionsHolder", "sun.nio.ch.AsynchronousSocketChannelImpl", "DefaultOptionsHolder", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _AsynchronousSocketChannelImpl$DefaultOptionsHolder_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.ch.AsynchronousSocketChannelImpl$DefaultOptionsHolder",
	"java.lang.Object",
	nullptr,
	_AsynchronousSocketChannelImpl$DefaultOptionsHolder_FieldInfo_,
	_AsynchronousSocketChannelImpl$DefaultOptionsHolder_MethodInfo_,
	nullptr,
	nullptr,
	_AsynchronousSocketChannelImpl$DefaultOptionsHolder_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.nio.ch.AsynchronousSocketChannelImpl"
};

$Object* allocate$AsynchronousSocketChannelImpl$DefaultOptionsHolder($Class* clazz) {
	return $of($alloc(AsynchronousSocketChannelImpl$DefaultOptionsHolder));
}

$Set* AsynchronousSocketChannelImpl$DefaultOptionsHolder::defaultOptions$ = nullptr;

void AsynchronousSocketChannelImpl$DefaultOptionsHolder::init$() {
}

$Set* AsynchronousSocketChannelImpl$DefaultOptionsHolder::defaultOptions() {
	$init(AsynchronousSocketChannelImpl$DefaultOptionsHolder);
	$useLocalCurrentObjectStackCache();
	$var($HashSet, set, $new($HashSet, 5));
	$init($StandardSocketOptions);
	set->add($StandardSocketOptions::SO_SNDBUF);
	set->add($StandardSocketOptions::SO_RCVBUF);
	set->add($StandardSocketOptions::SO_KEEPALIVE);
	set->add($StandardSocketOptions::SO_REUSEADDR);
	if ($Net::isReusePortAvailable()) {
		set->add($StandardSocketOptions::SO_REUSEPORT);
	}
	set->add($StandardSocketOptions::TCP_NODELAY);
	set->addAll($($ExtendedSocketOptions::clientSocketOptions()));
	return $Collections::unmodifiableSet(set);
}

void clinit$AsynchronousSocketChannelImpl$DefaultOptionsHolder($Class* class$) {
	$assignStatic(AsynchronousSocketChannelImpl$DefaultOptionsHolder::defaultOptions$, AsynchronousSocketChannelImpl$DefaultOptionsHolder::defaultOptions());
}

AsynchronousSocketChannelImpl$DefaultOptionsHolder::AsynchronousSocketChannelImpl$DefaultOptionsHolder() {
}

$Class* AsynchronousSocketChannelImpl$DefaultOptionsHolder::load$($String* name, bool initialize) {
	$loadClass(AsynchronousSocketChannelImpl$DefaultOptionsHolder, name, initialize, &_AsynchronousSocketChannelImpl$DefaultOptionsHolder_ClassInfo_, clinit$AsynchronousSocketChannelImpl$DefaultOptionsHolder, allocate$AsynchronousSocketChannelImpl$DefaultOptionsHolder);
	return class$;
}

$Class* AsynchronousSocketChannelImpl$DefaultOptionsHolder::class$ = nullptr;

		} // ch
	} // nio
} // sun