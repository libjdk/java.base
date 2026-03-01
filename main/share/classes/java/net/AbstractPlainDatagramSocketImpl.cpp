#include <java/net/AbstractPlainDatagramSocketImpl.h>

#include <java/io/FileDescriptor.h>
#include <java/lang/AssertionError.h>
#include <java/lang/CharSequence.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/net/DatagramPacket.h>
#include <java/net/DatagramSocketImpl.h>
#include <java/net/InetAddress$InetAddressHolder.h>
#include <java/net/InetAddress.h>
#include <java/net/InetSocketAddress.h>
#include <java/net/NetworkInterface.h>
#include <java/net/SocketAddress.h>
#include <java/net/SocketCleanable.h>
#include <java/net/SocketException.h>
#include <java/net/SocketOption.h>
#include <java/net/SocketOptions.h>
#include <java/net/StandardSocketOptions.h>
#include <java/util/AbstractCollection.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/HashSet.h>
#include <java/util/Objects.h>
#include <java/util/Set.h>
#include <jdk/internal/loader/BootLoader.h>
#include <sun/net/ResourceManager.h>
#include <sun/net/ext/ExtendedSocketOptions.h>
#include <sun/net/util/IPAddressUtil.h>
#include <sun/security/action/GetPropertyAction.h>
#include <jcpp.h>

#undef IP_MULTICAST_IF
#undef IP_MULTICAST_IF2
#undef IP_MULTICAST_LOOP
#undef IP_MULTICAST_TTL
#undef IP_TOS
#undef SO_BINDADDR
#undef SO_BROADCAST
#undef SO_RCVBUF
#undef SO_REUSEADDR
#undef SO_REUSEPORT
#undef SO_SNDBUF
#undef SO_TIMEOUT

using $FileDescriptor = ::java::io::FileDescriptor;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $DatagramPacket = ::java::net::DatagramPacket;
using $DatagramSocketImpl = ::java::net::DatagramSocketImpl;
using $InetAddress = ::java::net::InetAddress;
using $InetAddress$InetAddressHolder = ::java::net::InetAddress$InetAddressHolder;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $NetworkInterface = ::java::net::NetworkInterface;
using $SocketAddress = ::java::net::SocketAddress;
using $SocketCleanable = ::java::net::SocketCleanable;
using $SocketException = ::java::net::SocketException;
using $SocketOption = ::java::net::SocketOption;
using $SocketOptions = ::java::net::SocketOptions;
using $StandardSocketOptions = ::java::net::StandardSocketOptions;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $HashSet = ::java::util::HashSet;
using $Objects = ::java::util::Objects;
using $Set = ::java::util::Set;
using $BootLoader = ::jdk::internal::loader::BootLoader;
using $ResourceManager = ::sun::net::ResourceManager;
using $ExtendedSocketOptions = ::sun::net::ext::ExtendedSocketOptions;
using $IPAddressUtil = ::sun::net::util::IPAddressUtil;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;

namespace java {
	namespace net {

$FieldInfo _AbstractPlainDatagramSocketImpl_FieldInfo_[] = {
	{"timeout", "I", nullptr, 0, $field(AbstractPlainDatagramSocketImpl, timeout)},
	{"connected", "Z", nullptr, 0, $field(AbstractPlainDatagramSocketImpl, connected)},
	{"trafficClass", "I", nullptr, $PRIVATE, $field(AbstractPlainDatagramSocketImpl, trafficClass)},
	{"connectedAddress", "Ljava/net/InetAddress;", nullptr, $PROTECTED, $field(AbstractPlainDatagramSocketImpl, connectedAddress)},
	{"connectedPort", "I", nullptr, $PRIVATE, $field(AbstractPlainDatagramSocketImpl, connectedPort)},
	{"isMulticast", "Z", nullptr, $PRIVATE | $FINAL, $field(AbstractPlainDatagramSocketImpl, isMulticast)},
	{"os", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(AbstractPlainDatagramSocketImpl, os)},
	{"connectDisabled", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(AbstractPlainDatagramSocketImpl, connectDisabled)},
	{"checkedReusePort", "Z", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(AbstractPlainDatagramSocketImpl, checkedReusePort)},
	{"isReusePortAvailable", "Z", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(AbstractPlainDatagramSocketImpl, isReusePortAvailable$)},
	{"extendedOptions", "Lsun/net/ext/ExtendedSocketOptions;", nullptr, $STATIC | $FINAL, $staticField(AbstractPlainDatagramSocketImpl, extendedOptions)},
	{"datagramSocketOptions", "Ljava/util/Set;", "Ljava/util/Set<Ljava/net/SocketOption<*>;>;", $PRIVATE | $STATIC | $FINAL, $staticField(AbstractPlainDatagramSocketImpl, datagramSocketOptions$)},
	{}
};

$MethodInfo _AbstractPlainDatagramSocketImpl_MethodInfo_[] = {
	{"dataAvailable", "()I", nullptr, $ABSTRACT},
	{"getTTL", "()B", nullptr, $PROTECTED | $ABSTRACT | $DEPRECATED},
	{"getTimeToLive", "()I", nullptr, $PROTECTED | $ABSTRACT},
	{"<init>", "(Z)V", nullptr, 0, $method(AbstractPlainDatagramSocketImpl, init$, void, bool)},
	{"bind", "(ILjava/net/InetAddress;)V", nullptr, $PROTECTED | $SYNCHRONIZED, $virtualMethod(AbstractPlainDatagramSocketImpl, bind, void, int32_t, $InetAddress*), "java.net.SocketException"},
	{"bind0", "(ILjava/net/InetAddress;)V", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(AbstractPlainDatagramSocketImpl, bind0, void, int32_t, $InetAddress*), "java.net.SocketException"},
	{"close", "()V", nullptr, $PROTECTED, $virtualMethod(AbstractPlainDatagramSocketImpl, close, void)},
	{"connect", "(Ljava/net/InetAddress;I)V", nullptr, $PROTECTED, $virtualMethod(AbstractPlainDatagramSocketImpl, connect, void, $InetAddress*, int32_t), "java.net.SocketException"},
	{"connect0", "(Ljava/net/InetAddress;I)V", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(AbstractPlainDatagramSocketImpl, connect0, void, $InetAddress*, int32_t), "java.net.SocketException"},
	{"create", "()V", nullptr, $PROTECTED | $SYNCHRONIZED, $virtualMethod(AbstractPlainDatagramSocketImpl, create, void), "java.net.SocketException"},
	{"datagramSocketClose", "()V", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(AbstractPlainDatagramSocketImpl, datagramSocketClose, void)},
	{"datagramSocketCreate", "()V", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(AbstractPlainDatagramSocketImpl, datagramSocketCreate, void), "java.net.SocketException"},
	{"datagramSocketOptions", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/net/SocketOption<*>;>;", $PRIVATE | $STATIC, $staticMethod(AbstractPlainDatagramSocketImpl, datagramSocketOptions, $Set*)},
	{"disconnect", "()V", nullptr, $PROTECTED, $virtualMethod(AbstractPlainDatagramSocketImpl, disconnect, void)},
	{"disconnect0", "(I)V", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(AbstractPlainDatagramSocketImpl, disconnect0, void, int32_t)},
	{"getOption", "(I)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(AbstractPlainDatagramSocketImpl, getOption, $Object*, int32_t), "java.net.SocketException"},
	{"getOption", "(Ljava/net/SocketOption;)Ljava/lang/Object;", "<T:Ljava/lang/Object;>(Ljava/net/SocketOption<TT;>;)TT;", $PROTECTED, $virtualMethod(AbstractPlainDatagramSocketImpl, getOption, $Object*, $SocketOption*), "java.io.IOException"},
	{"isClosed", "()Z", nullptr, $PROTECTED, $virtualMethod(AbstractPlainDatagramSocketImpl, isClosed, bool)},
	{"isReusePortAvailable", "()Z", nullptr, $STATIC, $staticMethod(AbstractPlainDatagramSocketImpl, isReusePortAvailable, bool)},
	{"isReusePortAvailable0", "()Z", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(AbstractPlainDatagramSocketImpl, isReusePortAvailable0, bool)},
	{"join", "(Ljava/net/InetAddress;)V", nullptr, $PROTECTED, $virtualMethod(AbstractPlainDatagramSocketImpl, join, void, $InetAddress*), "java.io.IOException"},
	{"join", "(Ljava/net/InetAddress;Ljava/net/NetworkInterface;)V", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(AbstractPlainDatagramSocketImpl, join, void, $InetAddress*, $NetworkInterface*), "java.io.IOException"},
	{"joinGroup", "(Ljava/net/SocketAddress;Ljava/net/NetworkInterface;)V", nullptr, $PROTECTED, $virtualMethod(AbstractPlainDatagramSocketImpl, joinGroup, void, $SocketAddress*, $NetworkInterface*), "java.io.IOException"},
	{"leave", "(Ljava/net/InetAddress;)V", nullptr, $PROTECTED, $virtualMethod(AbstractPlainDatagramSocketImpl, leave, void, $InetAddress*), "java.io.IOException"},
	{"leave", "(Ljava/net/InetAddress;Ljava/net/NetworkInterface;)V", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(AbstractPlainDatagramSocketImpl, leave, void, $InetAddress*, $NetworkInterface*), "java.io.IOException"},
	{"leaveGroup", "(Ljava/net/SocketAddress;Ljava/net/NetworkInterface;)V", nullptr, $PROTECTED, $virtualMethod(AbstractPlainDatagramSocketImpl, leaveGroup, void, $SocketAddress*, $NetworkInterface*), "java.io.IOException"},
	{"nativeConnectDisabled", "()Z", nullptr, $PROTECTED, $virtualMethod(AbstractPlainDatagramSocketImpl, nativeConnectDisabled, bool)},
	{"peek", "(Ljava/net/InetAddress;)I", nullptr, $PROTECTED | $ABSTRACT},
	{"peekData", "(Ljava/net/DatagramPacket;)I", nullptr, $PROTECTED | $ABSTRACT},
	{"receive", "(Ljava/net/DatagramPacket;)V", nullptr, $PROTECTED | $SYNCHRONIZED, $virtualMethod(AbstractPlainDatagramSocketImpl, receive, void, $DatagramPacket*), "java.io.IOException"},
	{"receive0", "(Ljava/net/DatagramPacket;)V", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(AbstractPlainDatagramSocketImpl, receive0, void, $DatagramPacket*), "java.io.IOException"},
	{"send", "(Ljava/net/DatagramPacket;)V", nullptr, $PROTECTED, $virtualMethod(AbstractPlainDatagramSocketImpl, send, void, $DatagramPacket*), "java.io.IOException"},
	{"send0", "(Ljava/net/DatagramPacket;)V", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(AbstractPlainDatagramSocketImpl, send0, void, $DatagramPacket*), "java.io.IOException"},
	{"setOption", "(ILjava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(AbstractPlainDatagramSocketImpl, setOption, void, int32_t, Object$*), "java.net.SocketException"},
	{"setOption", "(Ljava/net/SocketOption;Ljava/lang/Object;)V", "<T:Ljava/lang/Object;>(Ljava/net/SocketOption<TT;>;TT;)V", $PROTECTED, $virtualMethod(AbstractPlainDatagramSocketImpl, setOption, void, $SocketOption*, Object$*), "java.io.IOException"},
	{"setTTL", "(B)V", nullptr, $PROTECTED | $ABSTRACT | $DEPRECATED},
	{"setTimeToLive", "(I)V", nullptr, $PROTECTED | $ABSTRACT},
	{"socketGetOption", "(I)Ljava/lang/Object;", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(AbstractPlainDatagramSocketImpl, socketGetOption, $Object*, int32_t), "java.net.SocketException"},
	{"socketSetOption", "(ILjava/lang/Object;)V", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(AbstractPlainDatagramSocketImpl, socketSetOption, void, int32_t, Object$*), "java.net.SocketException"},
	{"supportedOptions", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/net/SocketOption<*>;>;", $PROTECTED, $virtualMethod(AbstractPlainDatagramSocketImpl, supportedOptions, $Set*)},
	{}
};

#define _METHOD_INDEX_isReusePortAvailable0 19

$ClassInfo _AbstractPlainDatagramSocketImpl_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"java.net.AbstractPlainDatagramSocketImpl",
	"java.net.DatagramSocketImpl",
	nullptr,
	_AbstractPlainDatagramSocketImpl_FieldInfo_,
	_AbstractPlainDatagramSocketImpl_MethodInfo_
};

$Object* allocate$AbstractPlainDatagramSocketImpl($Class* clazz) {
	return $of($alloc(AbstractPlainDatagramSocketImpl));
}

int32_t AbstractPlainDatagramSocketImpl::dataAvailable() {
	 return this->$DatagramSocketImpl::dataAvailable();
}

$String* AbstractPlainDatagramSocketImpl::os = nullptr;
bool AbstractPlainDatagramSocketImpl::connectDisabled = false;
$volatile(bool) AbstractPlainDatagramSocketImpl::checkedReusePort = false;
$volatile(bool) AbstractPlainDatagramSocketImpl::isReusePortAvailable$ = false;
$ExtendedSocketOptions* AbstractPlainDatagramSocketImpl::extendedOptions = nullptr;
$Set* AbstractPlainDatagramSocketImpl::datagramSocketOptions$ = nullptr;

bool AbstractPlainDatagramSocketImpl::isReusePortAvailable() {
	$init(AbstractPlainDatagramSocketImpl);
	if (!AbstractPlainDatagramSocketImpl::checkedReusePort) {
		AbstractPlainDatagramSocketImpl::isReusePortAvailable$ = isReusePortAvailable0();
		AbstractPlainDatagramSocketImpl::checkedReusePort = true;
	}
	return AbstractPlainDatagramSocketImpl::isReusePortAvailable$;
}

void AbstractPlainDatagramSocketImpl::init$(bool isMulticast) {
	$DatagramSocketImpl::init$();
	this->timeout = 0;
	this->connected = false;
	this->trafficClass = 0;
	$set(this, connectedAddress, nullptr);
	this->connectedPort = -1;
	this->isMulticast = isMulticast;
}

void AbstractPlainDatagramSocketImpl::create() {
	$synchronized(this) {
		$ResourceManager::beforeUdpCreate();
		$set(this, fd, $new($FileDescriptor));
		try {
			datagramSocketCreate();
			$SocketCleanable::register$(this->fd, false);
		} catch ($SocketException& ioe) {
			$ResourceManager::afterUdpClose();
			$set(this, fd, nullptr);
			$throw(ioe);
		}
	}
}

void AbstractPlainDatagramSocketImpl::bind(int32_t lport, $InetAddress* laddr$renamed) {
	$synchronized(this) {
		$var($InetAddress, laddr, laddr$renamed);
		if ($nc(laddr)->isLinkLocalAddress()) {
			$assign(laddr, $IPAddressUtil::toScopedAddress(laddr));
		}
		bind0(lport, laddr);
	}
}

void AbstractPlainDatagramSocketImpl::send($DatagramPacket* p$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($DatagramPacket, p, p$renamed);
	$var($InetAddress, orig, $nc(p)->getAddress());
	if ($nc(orig)->isLinkLocalAddress()) {
		$var($InetAddress, scoped, $IPAddressUtil::toScopedAddress(orig));
		if (orig != scoped) {
			$var($bytes, var$0, p->getData());
			int32_t var$1 = p->getOffset();
			int32_t var$2 = p->getLength();
			$var($InetAddress, var$3, scoped);
			$assign(p, $new($DatagramPacket, var$0, var$1, var$2, var$3, p->getPort()));
		}
	}
	send0(p);
}

void AbstractPlainDatagramSocketImpl::connect($InetAddress* address$renamed, int32_t port) {
	$var($InetAddress, address, address$renamed);
	if ($nc(address)->isLinkLocalAddress()) {
		$assign(address, $IPAddressUtil::toScopedAddress(address));
	}
	connect0(address, port);
	$set(this, connectedAddress, address);
	this->connectedPort = port;
	this->connected = true;
}

void AbstractPlainDatagramSocketImpl::disconnect() {
	disconnect0($nc($($nc(this->connectedAddress)->holder()))->getFamily());
	this->connected = false;
	$set(this, connectedAddress, nullptr);
	this->connectedPort = -1;
}

void AbstractPlainDatagramSocketImpl::receive($DatagramPacket* p) {
	$synchronized(this) {
		receive0(p);
	}
}

void AbstractPlainDatagramSocketImpl::join($InetAddress* inetaddr) {
	join(inetaddr, nullptr);
}

void AbstractPlainDatagramSocketImpl::leave($InetAddress* inetaddr) {
	leave(inetaddr, nullptr);
}

void AbstractPlainDatagramSocketImpl::joinGroup($SocketAddress* mcastaddr, $NetworkInterface* netIf) {
	$useLocalCurrentObjectStackCache();
	$var($InetSocketAddress, addr, nullptr);
	bool var$0 = $instanceOf($InetSocketAddress, mcastaddr);
	if (var$0) {
		$assign(addr, $cast($InetSocketAddress, mcastaddr));
		var$0 = true;
	}
	if (!(var$0)) {
		$throwNew($IllegalArgumentException, "Unsupported address type"_s);
	}
	join($($nc(addr)->getAddress()), netIf);
}

void AbstractPlainDatagramSocketImpl::leaveGroup($SocketAddress* mcastaddr, $NetworkInterface* netIf) {
	$useLocalCurrentObjectStackCache();
	$var($InetSocketAddress, addr, nullptr);
	bool var$0 = $instanceOf($InetSocketAddress, mcastaddr);
	if (var$0) {
		$assign(addr, $cast($InetSocketAddress, mcastaddr));
		var$0 = true;
	}
	if (!(var$0)) {
		$throwNew($IllegalArgumentException, "Unsupported address type"_s);
	}
	leave($($nc(addr)->getAddress()), netIf);
}

void AbstractPlainDatagramSocketImpl::close() {
	if (this->fd != nullptr) {
		$SocketCleanable::unregister(this->fd);
		datagramSocketClose();
		$ResourceManager::afterUdpClose();
		$set(this, fd, nullptr);
	}
}

bool AbstractPlainDatagramSocketImpl::isClosed() {
	return (this->fd == nullptr) ? true : false;
}

void AbstractPlainDatagramSocketImpl::setOption(int32_t optID, Object$* o) {
	$useLocalCurrentObjectStackCache();
	if (isClosed()) {
		$throwNew($SocketException, "Socket Closed"_s);
	}
	{
		int32_t tmp = 0;
		switch (optID) {
		case $SocketOptions::SO_TIMEOUT:
			{
				if (!($instanceOf($Integer, o))) {
					$throwNew($SocketException, "bad argument for SO_TIMEOUT"_s);
				}
				tmp = $nc(($cast($Integer, o)))->intValue();
				if (tmp < 0) {
					$throwNew($IllegalArgumentException, "timeout < 0"_s);
				}
				this->timeout = tmp;
				return;
			}
		case $SocketOptions::IP_TOS:
			{
				if (!($instanceOf($Integer, o))) {
					$throwNew($SocketException, "bad argument for IP_TOS"_s);
				}
				this->trafficClass = ($cast($Integer, o))->intValue();
				break;
			}
		case $SocketOptions::SO_REUSEADDR:
			{
				if (!($instanceOf($Boolean, o))) {
					$throwNew($SocketException, "bad argument for SO_REUSEADDR"_s);
				}
				break;
			}
		case $SocketOptions::SO_BROADCAST:
			{
				if (!($instanceOf($Boolean, o))) {
					$throwNew($SocketException, "bad argument for SO_BROADCAST"_s);
				}
				break;
			}
		case $SocketOptions::SO_BINDADDR:
			{
				$throwNew($SocketException, "Cannot re-bind Socket"_s);
			}
		case $SocketOptions::SO_RCVBUF:
			{}
		case $SocketOptions::SO_SNDBUF:
			{
				if (!($instanceOf($Integer, o)) || ($cast($Integer, o))->intValue() < 0) {
					$throwNew($SocketException, "bad argument for SO_SNDBUF or SO_RCVBUF"_s);
				}
				break;
			}
		case $SocketOptions::IP_MULTICAST_IF:
			{
				if (!($instanceOf($InetAddress, o))) {
					$throwNew($SocketException, "bad argument for IP_MULTICAST_IF"_s);
				}
				break;
			}
		case $SocketOptions::IP_MULTICAST_IF2:
			{
				if (!($instanceOf($NetworkInterface, o))) {
					$throwNew($SocketException, "bad argument for IP_MULTICAST_IF2"_s);
				}
				break;
			}
		case $SocketOptions::IP_MULTICAST_LOOP:
			{
				if (!($instanceOf($Boolean, o))) {
					$throwNew($SocketException, "bad argument for IP_MULTICAST_LOOP"_s);
				}
				break;
			}
		case $SocketOptions::SO_REUSEPORT:
			{
				if (!($instanceOf($Boolean, o))) {
					$throwNew($SocketException, "bad argument for SO_REUSEPORT"_s);
				}
				$init($StandardSocketOptions);
				if (!$nc($(supportedOptions()))->contains($StandardSocketOptions::SO_REUSEPORT)) {
					$throwNew($UnsupportedOperationException, "unsupported option"_s);
				}
				break;
			}
		default:
			{
				$throwNew($SocketException, $$str({"invalid option: "_s, $$str(optID)}));
			}
		}
	}
	socketSetOption(optID, o);
}

$Object* AbstractPlainDatagramSocketImpl::getOption(int32_t optID) {
	$useLocalCurrentObjectStackCache();
	if (isClosed()) {
		$throwNew($SocketException, "Socket Closed"_s);
	}
	$var($Object, result, nullptr);
	switch (optID) {
	case $SocketOptions::SO_TIMEOUT:
		{
			$assign(result, $Integer::valueOf(this->timeout));
			break;
		}
	case $SocketOptions::IP_TOS:
		{
			$assign(result, socketGetOption(optID));
			if ($nc(($cast($Integer, result)))->intValue() == -1) {
				$assign(result, $Integer::valueOf(this->trafficClass));
			}
			break;
		}
	case $SocketOptions::SO_BINDADDR:
		{}
	case $SocketOptions::IP_MULTICAST_IF:
		{}
	case $SocketOptions::IP_MULTICAST_IF2:
		{}
	case $SocketOptions::SO_RCVBUF:
		{}
	case $SocketOptions::SO_SNDBUF:
		{}
	case $SocketOptions::IP_MULTICAST_LOOP:
		{}
	case $SocketOptions::SO_REUSEADDR:
		{}
	case $SocketOptions::SO_BROADCAST:
		{
			$assign(result, socketGetOption(optID));
			break;
		}
	case $SocketOptions::SO_REUSEPORT:
		{
			$init($StandardSocketOptions);
			if (!$nc($(supportedOptions()))->contains($StandardSocketOptions::SO_REUSEPORT)) {
				$throwNew($UnsupportedOperationException, "unsupported option"_s);
			}
			$assign(result, socketGetOption(optID));
			break;
		}
	default:
		{
			$throwNew($SocketException, $$str({"invalid option: "_s, $$str(optID)}));
		}
	}
	return $of(result);
}

$Set* AbstractPlainDatagramSocketImpl::datagramSocketOptions() {
	$init(AbstractPlainDatagramSocketImpl);
	$useLocalCurrentObjectStackCache();
	$var($HashSet, options, $new($HashSet));
	$init($StandardSocketOptions);
	options->add($StandardSocketOptions::SO_SNDBUF);
	options->add($StandardSocketOptions::SO_RCVBUF);
	options->add($StandardSocketOptions::SO_REUSEADDR);
	options->add($StandardSocketOptions::SO_BROADCAST);
	options->add($StandardSocketOptions::IP_TOS);
	options->add($StandardSocketOptions::IP_MULTICAST_IF);
	options->add($StandardSocketOptions::IP_MULTICAST_TTL);
	options->add($StandardSocketOptions::IP_MULTICAST_LOOP);
	if (isReusePortAvailable()) {
		options->add($StandardSocketOptions::SO_REUSEPORT);
	}
	options->addAll($($ExtendedSocketOptions::datagramSocketOptions()));
	return $Collections::unmodifiableSet(options);
}

$Set* AbstractPlainDatagramSocketImpl::supportedOptions() {
	return AbstractPlainDatagramSocketImpl::datagramSocketOptions$;
}

void AbstractPlainDatagramSocketImpl::setOption($SocketOption* name, Object$* value) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(name);
	if (!$nc($(supportedOptions()))->contains(name)) {
		$throwNew($UnsupportedOperationException, $$str({"\'"_s, name, "\' not supported"_s}));
	}
	if (!$nc(name->type())->isInstance(value)) {
		$throwNew($IllegalArgumentException, $$str({"Invalid value \'"_s, value, "\'"_s}));
	}
	if (isClosed()) {
		$throwNew($SocketException, "Socket closed"_s);
	}
	$init($StandardSocketOptions);
	if (name == $StandardSocketOptions::SO_SNDBUF) {
		if ($nc(($cast($Integer, value)))->intValue() < 0) {
			$throwNew($IllegalArgumentException, $$str({"Invalid send buffer size:"_s, value}));
		}
		setOption($SocketOptions::SO_SNDBUF, value);
	} else {
		if (name == $StandardSocketOptions::SO_RCVBUF) {
			if ($nc(($cast($Integer, value)))->intValue() < 0) {
				$throwNew($IllegalArgumentException, $$str({"Invalid recv buffer size:"_s, value}));
			}
			setOption($SocketOptions::SO_RCVBUF, value);
		} else {
			if (name == $StandardSocketOptions::SO_REUSEADDR) {
				setOption($SocketOptions::SO_REUSEADDR, value);
			} else {
				if (name == $StandardSocketOptions::SO_REUSEPORT) {
					setOption($SocketOptions::SO_REUSEPORT, value);
				} else {
					if (name == $StandardSocketOptions::SO_BROADCAST) {
						setOption($SocketOptions::SO_BROADCAST, value);
					} else {
						if (name == $StandardSocketOptions::IP_TOS) {
							int32_t i = $nc(($cast($Integer, value)))->intValue();
							if (i < 0 || i > 255) {
								$throwNew($IllegalArgumentException, $$str({"Invalid IP_TOS value: "_s, value}));
							}
							setOption($SocketOptions::IP_TOS, value);
						} else {
							if (name == $StandardSocketOptions::IP_MULTICAST_IF) {
								setOption($SocketOptions::IP_MULTICAST_IF2, value);
							} else {
								if (name == $StandardSocketOptions::IP_MULTICAST_TTL) {
									int32_t i = $nc(($cast($Integer, value)))->intValue();
									if (i < 0 || i > 255) {
										$throwNew($IllegalArgumentException, $$str({"Invalid TTL/hop value: "_s, value}));
									}
									setTimeToLive(($cast($Integer, value))->intValue());
								} else {
									if (name == $StandardSocketOptions::IP_MULTICAST_LOOP) {
										bool enable = $nc(($cast($Boolean, value)))->booleanValue();
										setOption($SocketOptions::IP_MULTICAST_LOOP, $($of($Boolean::valueOf(!enable))));
									} else if ($nc(AbstractPlainDatagramSocketImpl::extendedOptions)->isOptionSupported(name)) {
										$nc(AbstractPlainDatagramSocketImpl::extendedOptions)->setOption(this->fd, name, value);
									} else {
										$throwNew($AssertionError, $of($$str({"unknown option :"_s, name})));
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

$Object* AbstractPlainDatagramSocketImpl::getOption($SocketOption* name) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(name);
	if (!$nc($(supportedOptions()))->contains(name)) {
		$throwNew($UnsupportedOperationException, $$str({"\'"_s, name, "\' not supported"_s}));
	}
	if (isClosed()) {
		$throwNew($SocketException, "Socket closed"_s);
	}
	$init($StandardSocketOptions);
	if (name == $StandardSocketOptions::SO_SNDBUF) {
		return $of(getOption($SocketOptions::SO_SNDBUF));
	} else {
		if (name == $StandardSocketOptions::SO_RCVBUF) {
			return $of(getOption($SocketOptions::SO_RCVBUF));
		} else {
			if (name == $StandardSocketOptions::SO_REUSEADDR) {
				return $of(getOption($SocketOptions::SO_REUSEADDR));
			} else {
				if (name == $StandardSocketOptions::SO_REUSEPORT) {
					return $of(getOption($SocketOptions::SO_REUSEPORT));
				} else {
					if (name == $StandardSocketOptions::SO_BROADCAST) {
						return $of(getOption($SocketOptions::SO_BROADCAST));
					} else {
						if (name == $StandardSocketOptions::IP_TOS) {
							return $of(getOption($SocketOptions::IP_TOS));
						} else {
							if (name == $StandardSocketOptions::IP_MULTICAST_IF) {
								return $of(getOption($SocketOptions::IP_MULTICAST_IF2));
							} else {
								if (name == $StandardSocketOptions::IP_MULTICAST_TTL) {
									return $of($of(($Integer::valueOf(getTimeToLive()))));
								} else {
									if (name == $StandardSocketOptions::IP_MULTICAST_LOOP) {
										bool disabled = $nc(($cast($Boolean, $(getOption($SocketOptions::IP_MULTICAST_LOOP)))))->booleanValue();
										return $of($of($Boolean::valueOf(!disabled)));
									} else if ($nc(AbstractPlainDatagramSocketImpl::extendedOptions)->isOptionSupported(name)) {
										return $of($nc(AbstractPlainDatagramSocketImpl::extendedOptions)->getOption(this->fd, name));
									} else {
										$throwNew($AssertionError, $of($$str({"unknown option: "_s, name})));
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

bool AbstractPlainDatagramSocketImpl::nativeConnectDisabled() {
	return AbstractPlainDatagramSocketImpl::connectDisabled;
}

bool AbstractPlainDatagramSocketImpl::isReusePortAvailable0() {
	$init(AbstractPlainDatagramSocketImpl);
	bool $ret = false;
	$prepareNativeStatic(AbstractPlainDatagramSocketImpl, isReusePortAvailable0, bool);
	$ret = $invokeNativeStatic();
	$finishNativeStatic();
	return $ret;
}

void clinit$AbstractPlainDatagramSocketImpl($Class* class$) {
	$assignStatic(AbstractPlainDatagramSocketImpl::os, $GetPropertyAction::privilegedGetProperty("os.name"_s));
	AbstractPlainDatagramSocketImpl::connectDisabled = $nc(AbstractPlainDatagramSocketImpl::os)->contains("OS X"_s);
	{
		$BootLoader::loadLibrary("net"_s);
	}
	$assignStatic(AbstractPlainDatagramSocketImpl::extendedOptions, $ExtendedSocketOptions::getInstance());
	$assignStatic(AbstractPlainDatagramSocketImpl::datagramSocketOptions$, AbstractPlainDatagramSocketImpl::datagramSocketOptions());
}

AbstractPlainDatagramSocketImpl::AbstractPlainDatagramSocketImpl() {
}

$Class* AbstractPlainDatagramSocketImpl::load$($String* name, bool initialize) {
	$loadClass(AbstractPlainDatagramSocketImpl, name, initialize, &_AbstractPlainDatagramSocketImpl_ClassInfo_, clinit$AbstractPlainDatagramSocketImpl, allocate$AbstractPlainDatagramSocketImpl);
	return class$;
}

$Class* AbstractPlainDatagramSocketImpl::class$ = nullptr;

	} // net
} // java