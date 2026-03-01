#include <sun/nio/ch/AsynchronousServerSocketChannelImpl$DefaultOptionsHolder.h>

#include <java/net/SocketOption.h>
#include <java/net/StandardSocketOptions.h>
#include <java/util/AbstractCollection.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/HashSet.h>
#include <java/util/Set.h>
#include <sun/net/ext/ExtendedSocketOptions.h>
#include <sun/nio/ch/AsynchronousServerSocketChannelImpl.h>
#include <sun/nio/ch/Net.h>
#include <jcpp.h>

#undef SO_RCVBUF
#undef SO_REUSEADDR
#undef SO_REUSEPORT

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

$FieldInfo _AsynchronousServerSocketChannelImpl$DefaultOptionsHolder_FieldInfo_[] = {
	{"defaultOptions", "Ljava/util/Set;", "Ljava/util/Set<Ljava/net/SocketOption<*>;>;", $STATIC | $FINAL, $staticField(AsynchronousServerSocketChannelImpl$DefaultOptionsHolder, defaultOptions$)},
	{}
};

$MethodInfo _AsynchronousServerSocketChannelImpl$DefaultOptionsHolder_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(AsynchronousServerSocketChannelImpl$DefaultOptionsHolder, init$, void)},
	{"defaultOptions", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/net/SocketOption<*>;>;", $PRIVATE | $STATIC, $staticMethod(AsynchronousServerSocketChannelImpl$DefaultOptionsHolder, defaultOptions, $Set*)},
	{}
};

$InnerClassInfo _AsynchronousServerSocketChannelImpl$DefaultOptionsHolder_InnerClassesInfo_[] = {
	{"sun.nio.ch.AsynchronousServerSocketChannelImpl$DefaultOptionsHolder", "sun.nio.ch.AsynchronousServerSocketChannelImpl", "DefaultOptionsHolder", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _AsynchronousServerSocketChannelImpl$DefaultOptionsHolder_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.ch.AsynchronousServerSocketChannelImpl$DefaultOptionsHolder",
	"java.lang.Object",
	nullptr,
	_AsynchronousServerSocketChannelImpl$DefaultOptionsHolder_FieldInfo_,
	_AsynchronousServerSocketChannelImpl$DefaultOptionsHolder_MethodInfo_,
	nullptr,
	nullptr,
	_AsynchronousServerSocketChannelImpl$DefaultOptionsHolder_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.nio.ch.AsynchronousServerSocketChannelImpl"
};

$Object* allocate$AsynchronousServerSocketChannelImpl$DefaultOptionsHolder($Class* clazz) {
	return $of($alloc(AsynchronousServerSocketChannelImpl$DefaultOptionsHolder));
}

$Set* AsynchronousServerSocketChannelImpl$DefaultOptionsHolder::defaultOptions$ = nullptr;

void AsynchronousServerSocketChannelImpl$DefaultOptionsHolder::init$() {
}

$Set* AsynchronousServerSocketChannelImpl$DefaultOptionsHolder::defaultOptions() {
	$init(AsynchronousServerSocketChannelImpl$DefaultOptionsHolder);
	$useLocalCurrentObjectStackCache();
	$var($HashSet, set, $new($HashSet, 2));
	$init($StandardSocketOptions);
	set->add($StandardSocketOptions::SO_RCVBUF);
	set->add($StandardSocketOptions::SO_REUSEADDR);
	if ($Net::isReusePortAvailable()) {
		set->add($StandardSocketOptions::SO_REUSEPORT);
	}
	set->addAll($($ExtendedSocketOptions::serverSocketOptions()));
	return $Collections::unmodifiableSet(set);
}

void clinit$AsynchronousServerSocketChannelImpl$DefaultOptionsHolder($Class* class$) {
	$assignStatic(AsynchronousServerSocketChannelImpl$DefaultOptionsHolder::defaultOptions$, AsynchronousServerSocketChannelImpl$DefaultOptionsHolder::defaultOptions());
}

AsynchronousServerSocketChannelImpl$DefaultOptionsHolder::AsynchronousServerSocketChannelImpl$DefaultOptionsHolder() {
}

$Class* AsynchronousServerSocketChannelImpl$DefaultOptionsHolder::load$($String* name, bool initialize) {
	$loadClass(AsynchronousServerSocketChannelImpl$DefaultOptionsHolder, name, initialize, &_AsynchronousServerSocketChannelImpl$DefaultOptionsHolder_ClassInfo_, clinit$AsynchronousServerSocketChannelImpl$DefaultOptionsHolder, allocate$AsynchronousServerSocketChannelImpl$DefaultOptionsHolder);
	return class$;
}

$Class* AsynchronousServerSocketChannelImpl$DefaultOptionsHolder::class$ = nullptr;

		} // ch
	} // nio
} // sun