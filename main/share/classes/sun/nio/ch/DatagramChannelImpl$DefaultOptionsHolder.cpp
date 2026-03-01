#include <sun/nio/ch/DatagramChannelImpl$DefaultOptionsHolder.h>

#include <java/net/SocketOption.h>
#include <java/net/StandardSocketOptions.h>
#include <java/util/AbstractCollection.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/HashSet.h>
#include <java/util/Set.h>
#include <sun/net/ext/ExtendedSocketOptions.h>
#include <sun/nio/ch/DatagramChannelImpl.h>
#include <sun/nio/ch/Net.h>
#include <jcpp.h>

#undef IP_MULTICAST_IF
#undef IP_MULTICAST_LOOP
#undef IP_MULTICAST_TTL
#undef IP_TOS
#undef SO_BROADCAST
#undef SO_RCVBUF
#undef SO_REUSEADDR
#undef SO_REUSEPORT
#undef SO_SNDBUF

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

$FieldInfo _DatagramChannelImpl$DefaultOptionsHolder_FieldInfo_[] = {
	{"defaultOptions", "Ljava/util/Set;", "Ljava/util/Set<Ljava/net/SocketOption<*>;>;", $STATIC | $FINAL, $staticField(DatagramChannelImpl$DefaultOptionsHolder, defaultOptions$)},
	{}
};

$MethodInfo _DatagramChannelImpl$DefaultOptionsHolder_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(DatagramChannelImpl$DefaultOptionsHolder, init$, void)},
	{"defaultOptions", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/net/SocketOption<*>;>;", $PRIVATE | $STATIC, $staticMethod(DatagramChannelImpl$DefaultOptionsHolder, defaultOptions, $Set*)},
	{}
};

$InnerClassInfo _DatagramChannelImpl$DefaultOptionsHolder_InnerClassesInfo_[] = {
	{"sun.nio.ch.DatagramChannelImpl$DefaultOptionsHolder", "sun.nio.ch.DatagramChannelImpl", "DefaultOptionsHolder", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _DatagramChannelImpl$DefaultOptionsHolder_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.ch.DatagramChannelImpl$DefaultOptionsHolder",
	"java.lang.Object",
	nullptr,
	_DatagramChannelImpl$DefaultOptionsHolder_FieldInfo_,
	_DatagramChannelImpl$DefaultOptionsHolder_MethodInfo_,
	nullptr,
	nullptr,
	_DatagramChannelImpl$DefaultOptionsHolder_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.nio.ch.DatagramChannelImpl"
};

$Object* allocate$DatagramChannelImpl$DefaultOptionsHolder($Class* clazz) {
	return $of($alloc(DatagramChannelImpl$DefaultOptionsHolder));
}

$Set* DatagramChannelImpl$DefaultOptionsHolder::defaultOptions$ = nullptr;

void DatagramChannelImpl$DefaultOptionsHolder::init$() {
}

$Set* DatagramChannelImpl$DefaultOptionsHolder::defaultOptions() {
	$init(DatagramChannelImpl$DefaultOptionsHolder);
	$useLocalCurrentObjectStackCache();
	$var($HashSet, set, $new($HashSet));
	$init($StandardSocketOptions);
	set->add($StandardSocketOptions::SO_SNDBUF);
	set->add($StandardSocketOptions::SO_RCVBUF);
	set->add($StandardSocketOptions::SO_REUSEADDR);
	if ($Net::isReusePortAvailable()) {
		set->add($StandardSocketOptions::SO_REUSEPORT);
	}
	set->add($StandardSocketOptions::SO_BROADCAST);
	set->add($StandardSocketOptions::IP_TOS);
	set->add($StandardSocketOptions::IP_MULTICAST_IF);
	set->add($StandardSocketOptions::IP_MULTICAST_TTL);
	set->add($StandardSocketOptions::IP_MULTICAST_LOOP);
	set->addAll($($ExtendedSocketOptions::datagramSocketOptions()));
	return $Collections::unmodifiableSet(set);
}

void clinit$DatagramChannelImpl$DefaultOptionsHolder($Class* class$) {
	$assignStatic(DatagramChannelImpl$DefaultOptionsHolder::defaultOptions$, DatagramChannelImpl$DefaultOptionsHolder::defaultOptions());
}

DatagramChannelImpl$DefaultOptionsHolder::DatagramChannelImpl$DefaultOptionsHolder() {
}

$Class* DatagramChannelImpl$DefaultOptionsHolder::load$($String* name, bool initialize) {
	$loadClass(DatagramChannelImpl$DefaultOptionsHolder, name, initialize, &_DatagramChannelImpl$DefaultOptionsHolder_ClassInfo_, clinit$DatagramChannelImpl$DefaultOptionsHolder, allocate$DatagramChannelImpl$DefaultOptionsHolder);
	return class$;
}

$Class* DatagramChannelImpl$DefaultOptionsHolder::class$ = nullptr;

		} // ch
	} // nio
} // sun