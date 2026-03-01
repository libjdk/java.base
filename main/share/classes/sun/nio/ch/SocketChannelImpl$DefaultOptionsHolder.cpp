#include <sun/nio/ch/SocketChannelImpl$DefaultOptionsHolder.h>

#include <java/net/SocketOption.h>
#include <java/net/StandardSocketOptions.h>
#include <java/util/AbstractCollection.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/HashSet.h>
#include <java/util/Set.h>
#include <sun/net/ext/ExtendedSocketOptions.h>
#include <sun/nio/ch/ExtendedSocketOption.h>
#include <sun/nio/ch/Net.h>
#include <sun/nio/ch/SocketChannelImpl.h>
#include <jcpp.h>

#undef IP_TOS
#undef SO_KEEPALIVE
#undef SO_LINGER
#undef SO_OOBINLINE
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
using $ExtendedSocketOption = ::sun::nio::ch::ExtendedSocketOption;
using $Net = ::sun::nio::ch::Net;

namespace sun {
	namespace nio {
		namespace ch {

$FieldInfo _SocketChannelImpl$DefaultOptionsHolder_FieldInfo_[] = {
	{"defaultInetOptions", "Ljava/util/Set;", "Ljava/util/Set<Ljava/net/SocketOption<*>;>;", $STATIC | $FINAL, $staticField(SocketChannelImpl$DefaultOptionsHolder, defaultInetOptions$)},
	{"defaultUnixOptions", "Ljava/util/Set;", "Ljava/util/Set<Ljava/net/SocketOption<*>;>;", $STATIC | $FINAL, $staticField(SocketChannelImpl$DefaultOptionsHolder, defaultUnixOptions$)},
	{}
};

$MethodInfo _SocketChannelImpl$DefaultOptionsHolder_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(SocketChannelImpl$DefaultOptionsHolder, init$, void)},
	{"defaultInetOptions", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/net/SocketOption<*>;>;", $PRIVATE | $STATIC, $staticMethod(SocketChannelImpl$DefaultOptionsHolder, defaultInetOptions, $Set*)},
	{"defaultUnixOptions", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/net/SocketOption<*>;>;", $PRIVATE | $STATIC, $staticMethod(SocketChannelImpl$DefaultOptionsHolder, defaultUnixOptions, $Set*)},
	{}
};

$InnerClassInfo _SocketChannelImpl$DefaultOptionsHolder_InnerClassesInfo_[] = {
	{"sun.nio.ch.SocketChannelImpl$DefaultOptionsHolder", "sun.nio.ch.SocketChannelImpl", "DefaultOptionsHolder", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _SocketChannelImpl$DefaultOptionsHolder_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.ch.SocketChannelImpl$DefaultOptionsHolder",
	"java.lang.Object",
	nullptr,
	_SocketChannelImpl$DefaultOptionsHolder_FieldInfo_,
	_SocketChannelImpl$DefaultOptionsHolder_MethodInfo_,
	nullptr,
	nullptr,
	_SocketChannelImpl$DefaultOptionsHolder_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.nio.ch.SocketChannelImpl"
};

$Object* allocate$SocketChannelImpl$DefaultOptionsHolder($Class* clazz) {
	return $of($alloc(SocketChannelImpl$DefaultOptionsHolder));
}

$Set* SocketChannelImpl$DefaultOptionsHolder::defaultInetOptions$ = nullptr;
$Set* SocketChannelImpl$DefaultOptionsHolder::defaultUnixOptions$ = nullptr;

void SocketChannelImpl$DefaultOptionsHolder::init$() {
}

$Set* SocketChannelImpl$DefaultOptionsHolder::defaultInetOptions() {
	$init(SocketChannelImpl$DefaultOptionsHolder);
	$useLocalCurrentObjectStackCache();
	$var($HashSet, set, $new($HashSet));
	$init($StandardSocketOptions);
	set->add($StandardSocketOptions::SO_SNDBUF);
	set->add($StandardSocketOptions::SO_RCVBUF);
	set->add($StandardSocketOptions::SO_KEEPALIVE);
	set->add($StandardSocketOptions::SO_REUSEADDR);
	if ($Net::isReusePortAvailable()) {
		set->add($StandardSocketOptions::SO_REUSEPORT);
	}
	set->add($StandardSocketOptions::SO_LINGER);
	set->add($StandardSocketOptions::TCP_NODELAY);
	set->add($StandardSocketOptions::IP_TOS);
	$init($ExtendedSocketOption);
	set->add($ExtendedSocketOption::SO_OOBINLINE);
	set->addAll($($ExtendedSocketOptions::clientSocketOptions()));
	return $Collections::unmodifiableSet(set);
}

$Set* SocketChannelImpl$DefaultOptionsHolder::defaultUnixOptions() {
	$init(SocketChannelImpl$DefaultOptionsHolder);
	$useLocalCurrentObjectStackCache();
	$var($HashSet, set, $new($HashSet));
	$init($StandardSocketOptions);
	set->add($StandardSocketOptions::SO_SNDBUF);
	set->add($StandardSocketOptions::SO_RCVBUF);
	set->add($StandardSocketOptions::SO_LINGER);
	set->addAll($($ExtendedSocketOptions::unixDomainSocketOptions()));
	return $Collections::unmodifiableSet(set);
}

void clinit$SocketChannelImpl$DefaultOptionsHolder($Class* class$) {
	$assignStatic(SocketChannelImpl$DefaultOptionsHolder::defaultInetOptions$, SocketChannelImpl$DefaultOptionsHolder::defaultInetOptions());
	$assignStatic(SocketChannelImpl$DefaultOptionsHolder::defaultUnixOptions$, SocketChannelImpl$DefaultOptionsHolder::defaultUnixOptions());
}

SocketChannelImpl$DefaultOptionsHolder::SocketChannelImpl$DefaultOptionsHolder() {
}

$Class* SocketChannelImpl$DefaultOptionsHolder::load$($String* name, bool initialize) {
	$loadClass(SocketChannelImpl$DefaultOptionsHolder, name, initialize, &_SocketChannelImpl$DefaultOptionsHolder_ClassInfo_, clinit$SocketChannelImpl$DefaultOptionsHolder, allocate$SocketChannelImpl$DefaultOptionsHolder);
	return class$;
}

$Class* SocketChannelImpl$DefaultOptionsHolder::class$ = nullptr;

		} // ch
	} // nio
} // sun