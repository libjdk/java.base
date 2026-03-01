#include <java/net/AbstractPlainSocketImpl.h>

#include <java/io/FileDescriptor.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/InternalError.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/InetAddress.h>
#include <java/net/InetAddressContainer.h>
#include <java/net/InetSocketAddress.h>
#include <java/net/SocketAddress.h>
#include <java/net/SocketCleanable.h>
#include <java/net/SocketException.h>
#include <java/net/SocketImpl.h>
#include <java/net/SocketInputStream.h>
#include <java/net/SocketOption.h>
#include <java/net/SocketOptions.h>
#include <java/net/SocketOutputStream.h>
#include <java/net/StandardSocketOptions.h>
#include <java/net/UnknownHostException.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedActionException.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/util/AbstractCollection.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/HashSet.h>
#include <java/util/Objects.h>
#include <java/util/Set.h>
#include <jdk/internal/loader/BootLoader.h>
#include <sun/net/ConnectionResetException.h>
#include <sun/net/NetHooks.h>
#include <sun/net/ResourceManager.h>
#include <sun/net/ext/ExtendedSocketOptions.h>
#include <sun/net/util/IPAddressUtil.h>
#include <sun/net/util/SocketExceptions.h>
#include <jcpp.h>

#undef FALSE
#undef IP_TOS
#undef SHUT_RD
#undef SHUT_WR
#undef SO_BINDADDR
#undef SO_KEEPALIVE
#undef SO_LINGER
#undef SO_OOBINLINE
#undef SO_RCVBUF
#undef SO_REUSEADDR
#undef SO_REUSEPORT
#undef SO_SNDBUF
#undef SO_TIMEOUT
#undef TCP_NODELAY

using $FileDescriptor = ::java::io::FileDescriptor;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $InetAddress = ::java::net::InetAddress;
using $InetAddressContainer = ::java::net::InetAddressContainer;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $SocketAddress = ::java::net::SocketAddress;
using $SocketCleanable = ::java::net::SocketCleanable;
using $SocketException = ::java::net::SocketException;
using $SocketImpl = ::java::net::SocketImpl;
using $SocketInputStream = ::java::net::SocketInputStream;
using $SocketOption = ::java::net::SocketOption;
using $SocketOptions = ::java::net::SocketOptions;
using $SocketOutputStream = ::java::net::SocketOutputStream;
using $StandardSocketOptions = ::java::net::StandardSocketOptions;
using $UnknownHostException = ::java::net::UnknownHostException;
using $AccessController = ::java::security::AccessController;
using $PrivilegedActionException = ::java::security::PrivilegedActionException;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $HashSet = ::java::util::HashSet;
using $Objects = ::java::util::Objects;
using $Set = ::java::util::Set;
using $BootLoader = ::jdk::internal::loader::BootLoader;
using $ConnectionResetException = ::sun::net::ConnectionResetException;
using $NetHooks = ::sun::net::NetHooks;
using $ResourceManager = ::sun::net::ResourceManager;
using $ExtendedSocketOptions = ::sun::net::ext::ExtendedSocketOptions;
using $IPAddressUtil = ::sun::net::util::IPAddressUtil;
using $SocketExceptions = ::sun::net::util::SocketExceptions;

namespace java {
	namespace net {

class AbstractPlainSocketImpl$$Lambda$lambda$getInputStream$0 : public $PrivilegedExceptionAction {
	$class(AbstractPlainSocketImpl$$Lambda$lambda$getInputStream$0, $NO_CLASS_INIT, $PrivilegedExceptionAction)
public:
	void init$(AbstractPlainSocketImpl* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* run() override {
		 return $of($nc(inst$)->lambda$getInputStream$0());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<AbstractPlainSocketImpl$$Lambda$lambda$getInputStream$0>());
	}
	AbstractPlainSocketImpl* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo AbstractPlainSocketImpl$$Lambda$lambda$getInputStream$0::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(AbstractPlainSocketImpl$$Lambda$lambda$getInputStream$0, inst$)},
	{}
};
$MethodInfo AbstractPlainSocketImpl$$Lambda$lambda$getInputStream$0::methodInfos[3] = {
	{"<init>", "(Ljava/net/AbstractPlainSocketImpl;)V", nullptr, $PUBLIC, $method(AbstractPlainSocketImpl$$Lambda$lambda$getInputStream$0, init$, void, AbstractPlainSocketImpl*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(AbstractPlainSocketImpl$$Lambda$lambda$getInputStream$0, run, $Object*)},
	{}
};
$ClassInfo AbstractPlainSocketImpl$$Lambda$lambda$getInputStream$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.net.AbstractPlainSocketImpl$$Lambda$lambda$getInputStream$0",
	"java.lang.Object",
	"java.security.PrivilegedExceptionAction",
	fieldInfos,
	methodInfos
};
$Class* AbstractPlainSocketImpl$$Lambda$lambda$getInputStream$0::load$($String* name, bool initialize) {
	$loadClass(AbstractPlainSocketImpl$$Lambda$lambda$getInputStream$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* AbstractPlainSocketImpl$$Lambda$lambda$getInputStream$0::class$ = nullptr;

class AbstractPlainSocketImpl$$Lambda$lambda$getOutputStream$1$1 : public $PrivilegedExceptionAction {
	$class(AbstractPlainSocketImpl$$Lambda$lambda$getOutputStream$1$1, $NO_CLASS_INIT, $PrivilegedExceptionAction)
public:
	void init$(AbstractPlainSocketImpl* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* run() override {
		 return $of($nc(inst$)->lambda$getOutputStream$1());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<AbstractPlainSocketImpl$$Lambda$lambda$getOutputStream$1$1>());
	}
	AbstractPlainSocketImpl* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo AbstractPlainSocketImpl$$Lambda$lambda$getOutputStream$1$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(AbstractPlainSocketImpl$$Lambda$lambda$getOutputStream$1$1, inst$)},
	{}
};
$MethodInfo AbstractPlainSocketImpl$$Lambda$lambda$getOutputStream$1$1::methodInfos[3] = {
	{"<init>", "(Ljava/net/AbstractPlainSocketImpl;)V", nullptr, $PUBLIC, $method(AbstractPlainSocketImpl$$Lambda$lambda$getOutputStream$1$1, init$, void, AbstractPlainSocketImpl*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(AbstractPlainSocketImpl$$Lambda$lambda$getOutputStream$1$1, run, $Object*)},
	{}
};
$ClassInfo AbstractPlainSocketImpl$$Lambda$lambda$getOutputStream$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.net.AbstractPlainSocketImpl$$Lambda$lambda$getOutputStream$1$1",
	"java.lang.Object",
	"java.security.PrivilegedExceptionAction",
	fieldInfos,
	methodInfos
};
$Class* AbstractPlainSocketImpl$$Lambda$lambda$getOutputStream$1$1::load$($String* name, bool initialize) {
	$loadClass(AbstractPlainSocketImpl$$Lambda$lambda$getOutputStream$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* AbstractPlainSocketImpl$$Lambda$lambda$getOutputStream$1$1::class$ = nullptr;

$FieldInfo _AbstractPlainSocketImpl_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(AbstractPlainSocketImpl, $assertionsDisabled)},
	{"timeout", "I", nullptr, 0, $field(AbstractPlainSocketImpl, timeout)},
	{"trafficClass", "I", nullptr, $PRIVATE, $field(AbstractPlainSocketImpl, trafficClass)},
	{"shut_rd", "Z", nullptr, $PRIVATE, $field(AbstractPlainSocketImpl, shut_rd)},
	{"shut_wr", "Z", nullptr, $PRIVATE, $field(AbstractPlainSocketImpl, shut_wr)},
	{"socketInputStream", "Ljava/net/SocketInputStream;", nullptr, $PRIVATE, $field(AbstractPlainSocketImpl, socketInputStream)},
	{"socketOutputStream", "Ljava/net/SocketOutputStream;", nullptr, $PRIVATE, $field(AbstractPlainSocketImpl, socketOutputStream)},
	{"fdUseCount", "I", nullptr, $PROTECTED, $field(AbstractPlainSocketImpl, fdUseCount)},
	{"fdLock", "Ljava/lang/Object;", nullptr, $PROTECTED | $FINAL, $field(AbstractPlainSocketImpl, fdLock)},
	{"closePending", "Z", nullptr, $PROTECTED, $field(AbstractPlainSocketImpl, closePending)},
	{"connectionReset", "Z", nullptr, $PRIVATE | $VOLATILE, $field(AbstractPlainSocketImpl, connectionReset)},
	{"isBound", "Z", nullptr, 0, $field(AbstractPlainSocketImpl, isBound)},
	{"isConnected", "Z", nullptr, $VOLATILE, $field(AbstractPlainSocketImpl, isConnected)},
	{"stream", "Z", nullptr, $PROTECTED, $field(AbstractPlainSocketImpl, stream)},
	{"isServer", "Z", nullptr, $FINAL, $field(AbstractPlainSocketImpl, isServer)},
	{"checkedReusePort", "Z", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(AbstractPlainSocketImpl, checkedReusePort)},
	{"isReusePortAvailable", "Z", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(AbstractPlainSocketImpl, isReusePortAvailable$)},
	{"extendedOptions", "Lsun/net/ext/ExtendedSocketOptions;", nullptr, $STATIC | $FINAL, $staticField(AbstractPlainSocketImpl, extendedOptions)},
	{"clientSocketOptions", "Ljava/util/Set;", "Ljava/util/Set<Ljava/net/SocketOption<*>;>;", $PRIVATE | $STATIC | $FINAL, $staticField(AbstractPlainSocketImpl, clientSocketOptions$)},
	{"serverSocketOptions", "Ljava/util/Set;", "Ljava/util/Set<Ljava/net/SocketOption<*>;>;", $PRIVATE | $STATIC | $FINAL, $staticField(AbstractPlainSocketImpl, serverSocketOptions$)},
	{"SHUT_RD", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(AbstractPlainSocketImpl, SHUT_RD)},
	{"SHUT_WR", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(AbstractPlainSocketImpl, SHUT_WR)},
	{}
};

$MethodInfo _AbstractPlainSocketImpl_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Z)V", nullptr, 0, $method(AbstractPlainSocketImpl, init$, void, bool)},
	{"accept", "(Ljava/net/SocketImpl;)V", nullptr, $PROTECTED, $virtualMethod(AbstractPlainSocketImpl, accept, void, $SocketImpl*), "java.io.IOException"},
	{"acquireFD", "()Ljava/io/FileDescriptor;", nullptr, 0, $virtualMethod(AbstractPlainSocketImpl, acquireFD, $FileDescriptor*)},
	{"available", "()I", nullptr, $PROTECTED | $SYNCHRONIZED, $virtualMethod(AbstractPlainSocketImpl, available, int32_t), "java.io.IOException"},
	{"bind", "(Ljava/net/InetAddress;I)V", nullptr, $PROTECTED | $SYNCHRONIZED, $virtualMethod(AbstractPlainSocketImpl, bind, void, $InetAddress*, int32_t), "java.io.IOException"},
	{"clientSocketOptions", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/net/SocketOption<*>;>;", $PRIVATE | $STATIC, $staticMethod(AbstractPlainSocketImpl, clientSocketOptions, $Set*)},
	{"close", "()V", nullptr, $PROTECTED, $virtualMethod(AbstractPlainSocketImpl, close, void), "java.io.IOException"},
	{"connect", "(Ljava/lang/String;I)V", nullptr, $PROTECTED, $virtualMethod(AbstractPlainSocketImpl, connect, void, $String*, int32_t), "java.net.UnknownHostException,java.io.IOException"},
	{"connect", "(Ljava/net/InetAddress;I)V", nullptr, $PROTECTED, $virtualMethod(AbstractPlainSocketImpl, connect, void, $InetAddress*, int32_t), "java.io.IOException"},
	{"connect", "(Ljava/net/SocketAddress;I)V", nullptr, $PROTECTED, $virtualMethod(AbstractPlainSocketImpl, connect, void, $SocketAddress*, int32_t), "java.io.IOException"},
	{"connectToAddress", "(Ljava/net/InetAddress;II)V", nullptr, $PRIVATE, $method(AbstractPlainSocketImpl, connectToAddress, void, $InetAddress*, int32_t, int32_t), "java.io.IOException"},
	{"create", "(Z)V", nullptr, $PROTECTED | $SYNCHRONIZED, $virtualMethod(AbstractPlainSocketImpl, create, void, bool), "java.io.IOException"},
	{"doConnect", "(Ljava/net/InetAddress;II)V", nullptr, $SYNCHRONIZED, $virtualMethod(AbstractPlainSocketImpl, doConnect, void, $InetAddress*, int32_t, int32_t), "java.io.IOException"},
	{"getInputStream", "()Ljava/io/InputStream;", nullptr, $PROTECTED | $SYNCHRONIZED, $virtualMethod(AbstractPlainSocketImpl, getInputStream, $InputStream*), "java.io.IOException"},
	{"getOption", "(I)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(AbstractPlainSocketImpl, getOption, $Object*, int32_t), "java.net.SocketException"},
	{"getOption", "(Ljava/net/SocketOption;)Ljava/lang/Object;", "<T:Ljava/lang/Object;>(Ljava/net/SocketOption<TT;>;)TT;", $PROTECTED, $virtualMethod(AbstractPlainSocketImpl, getOption, $Object*, $SocketOption*), "java.io.IOException"},
	{"getOutputStream", "()Ljava/io/OutputStream;", nullptr, $PROTECTED | $SYNCHRONIZED, $virtualMethod(AbstractPlainSocketImpl, getOutputStream, $OutputStream*), "java.io.IOException"},
	{"getTimeout", "()I", nullptr, $PUBLIC, $virtualMethod(AbstractPlainSocketImpl, getTimeout, int32_t)},
	{"isClosedOrPending", "()Z", nullptr, $PUBLIC, $virtualMethod(AbstractPlainSocketImpl, isClosedOrPending, bool)},
	{"isConnectionReset", "()Z", nullptr, 0, $virtualMethod(AbstractPlainSocketImpl, isConnectionReset, bool)},
	{"isReusePortAvailable", "()Z", nullptr, $STATIC, $staticMethod(AbstractPlainSocketImpl, isReusePortAvailable, bool)},
	{"isReusePortAvailable0", "()Z", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(AbstractPlainSocketImpl, isReusePortAvailable0, bool)},
	{"lambda$getInputStream$0", "()Ljava/net/SocketInputStream;", nullptr, $PRIVATE | $SYNTHETIC, $method(AbstractPlainSocketImpl, lambda$getInputStream$0, $SocketInputStream*), "java.lang.Exception"},
	{"lambda$getOutputStream$1", "()Ljava/net/SocketOutputStream;", nullptr, $PRIVATE | $SYNTHETIC, $method(AbstractPlainSocketImpl, lambda$getOutputStream$1, $SocketOutputStream*), "java.lang.Exception"},
	{"listen", "(I)V", nullptr, $PROTECTED | $SYNCHRONIZED, $virtualMethod(AbstractPlainSocketImpl, listen, void, int32_t), "java.io.IOException"},
	{"releaseFD", "()V", nullptr, 0, $virtualMethod(AbstractPlainSocketImpl, releaseFD, void)},
	{"reset", "()V", nullptr, 0, $virtualMethod(AbstractPlainSocketImpl, reset, void)},
	{"sendUrgentData", "(I)V", nullptr, $PROTECTED, $virtualMethod(AbstractPlainSocketImpl, sendUrgentData, void, int32_t), "java.io.IOException"},
	{"serverSocketOptions", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/net/SocketOption<*>;>;", $PRIVATE | $STATIC, $staticMethod(AbstractPlainSocketImpl, serverSocketOptions, $Set*)},
	{"setAddress", "(Ljava/net/InetAddress;)V", nullptr, 0, $virtualMethod(AbstractPlainSocketImpl, setAddress, void, $InetAddress*)},
	{"setConnectionReset", "()V", nullptr, 0, $virtualMethod(AbstractPlainSocketImpl, setConnectionReset, void)},
	{"setFileDescriptor", "(Ljava/io/FileDescriptor;)V", nullptr, 0, $virtualMethod(AbstractPlainSocketImpl, setFileDescriptor, void, $FileDescriptor*)},
	{"setInputStream", "(Ljava/net/SocketInputStream;)V", nullptr, 0, $virtualMethod(AbstractPlainSocketImpl, setInputStream, void, $SocketInputStream*)},
	{"setLocalPort", "(I)V", nullptr, 0, $virtualMethod(AbstractPlainSocketImpl, setLocalPort, void, int32_t)},
	{"setOption", "(ILjava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(AbstractPlainSocketImpl, setOption, void, int32_t, Object$*), "java.net.SocketException"},
	{"setOption", "(Ljava/net/SocketOption;Ljava/lang/Object;)V", "<T:Ljava/lang/Object;>(Ljava/net/SocketOption<TT;>;TT;)V", $PROTECTED, $virtualMethod(AbstractPlainSocketImpl, setOption, void, $SocketOption*, Object$*), "java.io.IOException"},
	{"setPort", "(I)V", nullptr, 0, $virtualMethod(AbstractPlainSocketImpl, setPort, void, int32_t)},
	{"shutdownInput", "()V", nullptr, $PROTECTED, $virtualMethod(AbstractPlainSocketImpl, shutdownInput, void), "java.io.IOException"},
	{"shutdownOutput", "()V", nullptr, $PROTECTED, $virtualMethod(AbstractPlainSocketImpl, shutdownOutput, void), "java.io.IOException"},
	{"socketAccept", "(Ljava/net/SocketImpl;)V", nullptr, $ABSTRACT, $virtualMethod(AbstractPlainSocketImpl, socketAccept, void, $SocketImpl*), "java.io.IOException"},
	{"socketAvailable", "()I", nullptr, $ABSTRACT, $virtualMethod(AbstractPlainSocketImpl, socketAvailable, int32_t), "java.io.IOException"},
	{"socketBind", "(Ljava/net/InetAddress;I)V", nullptr, $ABSTRACT, $virtualMethod(AbstractPlainSocketImpl, socketBind, void, $InetAddress*, int32_t), "java.io.IOException"},
	{"socketClose", "()V", nullptr, $PROTECTED, $virtualMethod(AbstractPlainSocketImpl, socketClose, void), "java.io.IOException"},
	{"socketClose0", "(Z)V", nullptr, $ABSTRACT, $virtualMethod(AbstractPlainSocketImpl, socketClose0, void, bool), "java.io.IOException"},
	{"socketConnect", "(Ljava/net/InetAddress;II)V", nullptr, $ABSTRACT, $virtualMethod(AbstractPlainSocketImpl, socketConnect, void, $InetAddress*, int32_t, int32_t), "java.io.IOException"},
	{"socketCreate", "(Z)V", nullptr, $ABSTRACT, $virtualMethod(AbstractPlainSocketImpl, socketCreate, void, bool), "java.io.IOException"},
	{"socketGetOption", "(ILjava/lang/Object;)I", nullptr, $ABSTRACT, $virtualMethod(AbstractPlainSocketImpl, socketGetOption, int32_t, int32_t, Object$*), "java.net.SocketException"},
	{"socketListen", "(I)V", nullptr, $ABSTRACT, $virtualMethod(AbstractPlainSocketImpl, socketListen, void, int32_t), "java.io.IOException"},
	{"socketPreClose", "()V", nullptr, $PRIVATE, $method(AbstractPlainSocketImpl, socketPreClose, void), "java.io.IOException"},
	{"socketSendUrgentData", "(I)V", nullptr, $ABSTRACT, $virtualMethod(AbstractPlainSocketImpl, socketSendUrgentData, void, int32_t), "java.io.IOException"},
	{"socketSetOption", "(IZLjava/lang/Object;)V", nullptr, $ABSTRACT, $virtualMethod(AbstractPlainSocketImpl, socketSetOption, void, int32_t, bool, Object$*), "java.net.SocketException"},
	{"socketShutdown", "(I)V", nullptr, $ABSTRACT, $virtualMethod(AbstractPlainSocketImpl, socketShutdown, void, int32_t), "java.io.IOException"},
	{"supportedOptions", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/net/SocketOption<*>;>;", $PROTECTED, $virtualMethod(AbstractPlainSocketImpl, supportedOptions, $Set*)},
	{"supportsUrgentData", "()Z", nullptr, $PROTECTED, $virtualMethod(AbstractPlainSocketImpl, supportsUrgentData, bool)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

#define _METHOD_INDEX_isReusePortAvailable0 25

$ClassInfo _AbstractPlainSocketImpl_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"java.net.AbstractPlainSocketImpl",
	"java.net.SocketImpl",
	"sun.net.PlatformSocketImpl",
	_AbstractPlainSocketImpl_FieldInfo_,
	_AbstractPlainSocketImpl_MethodInfo_
};

$Object* allocate$AbstractPlainSocketImpl($Class* clazz) {
	return $of($alloc(AbstractPlainSocketImpl));
}

$String* AbstractPlainSocketImpl::toString() {
	 return this->$SocketImpl::toString();
}

int32_t AbstractPlainSocketImpl::hashCode() {
	 return this->$SocketImpl::hashCode();
}

bool AbstractPlainSocketImpl::equals(Object$* obj) {
	 return this->$SocketImpl::equals(obj);
}

$Object* AbstractPlainSocketImpl::clone() {
	 return this->$SocketImpl::clone();
}

void AbstractPlainSocketImpl::finalize() {
	this->$SocketImpl::finalize();
}

bool AbstractPlainSocketImpl::$assertionsDisabled = false;
$volatile(bool) AbstractPlainSocketImpl::checkedReusePort = false;
$volatile(bool) AbstractPlainSocketImpl::isReusePortAvailable$ = false;
$ExtendedSocketOptions* AbstractPlainSocketImpl::extendedOptions = nullptr;
$Set* AbstractPlainSocketImpl::clientSocketOptions$ = nullptr;
$Set* AbstractPlainSocketImpl::serverSocketOptions$ = nullptr;

bool AbstractPlainSocketImpl::isReusePortAvailable() {
	$init(AbstractPlainSocketImpl);
	if (!AbstractPlainSocketImpl::checkedReusePort) {
		AbstractPlainSocketImpl::isReusePortAvailable$ = isReusePortAvailable0();
		AbstractPlainSocketImpl::checkedReusePort = true;
	}
	return AbstractPlainSocketImpl::isReusePortAvailable$;
}

void AbstractPlainSocketImpl::init$(bool isServer) {
	$SocketImpl::init$();
	this->shut_rd = false;
	this->shut_wr = false;
	$set(this, socketInputStream, nullptr);
	$set(this, socketOutputStream, nullptr);
	this->fdUseCount = 0;
	$set(this, fdLock, $new($Object));
	this->closePending = false;
	this->isServer = isServer;
}

void AbstractPlainSocketImpl::create(bool stream) {
	$synchronized(this) {
		this->stream = stream;
		if (!stream) {
			$ResourceManager::beforeUdpCreate();
			$set(this, fd, $new($FileDescriptor));
			try {
				socketCreate(false);
				$SocketCleanable::register$(this->fd, false);
			} catch ($IOException& ioe) {
				$ResourceManager::afterUdpClose();
				$set(this, fd, nullptr);
				$throw(ioe);
			}
		} else {
			$set(this, fd, $new($FileDescriptor));
			socketCreate(true);
			$SocketCleanable::register$(this->fd, true);
		}
	}
}

void AbstractPlainSocketImpl::connect($String* host, int32_t port) {
	$useLocalCurrentObjectStackCache();
	bool connected = false;
	{
		$var($Throwable, var$0, nullptr);
		try {
			$var($InetAddress, address, $InetAddress::getByName(host));
			$set(this, address, address);
			this->port = port;
			if ($nc(address)->isLinkLocalAddress()) {
				$assign(address, $IPAddressUtil::toScopedAddress(address));
			}
			connectToAddress(address, port, this->timeout);
			connected = true;
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			if (!connected) {
				try {
					close();
				} catch ($IOException& ioe) {
				}
			}
			this->isConnected = connected;
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void AbstractPlainSocketImpl::connect($InetAddress* address$renamed, int32_t port) {
	$var($InetAddress, address, address$renamed);
	$set(this, address, address);
	this->port = port;
	if ($nc(address)->isLinkLocalAddress()) {
		$assign(address, $IPAddressUtil::toScopedAddress(address));
	}
	try {
		connectToAddress(address, port, this->timeout);
		this->isConnected = true;
		return;
	} catch ($IOException& e) {
		close();
		$throw(e);
	}
}

void AbstractPlainSocketImpl::connect($SocketAddress* address, int32_t timeout) {
	$useLocalCurrentObjectStackCache();
	bool connected = false;
	{
		$var($Throwable, var$0, nullptr);
		try {
			$var($InetSocketAddress, addr, nullptr);
			bool var$1 = $instanceOf($InetSocketAddress, address);
			if (var$1) {
				$assign(addr, $cast($InetSocketAddress, address));
				var$1 = true;
			}
			if (!(var$1)) {
				$throwNew($IllegalArgumentException, "unsupported address type"_s);
			}
			if ($nc(addr)->isUnresolved()) {
				$throwNew($UnknownHostException, $(addr->getHostName()));
			}
			$var($InetAddress, ia, $nc(addr)->getAddress());
			$set(this, address, ia);
			this->port = addr->getPort();
			if ($nc(ia)->isLinkLocalAddress()) {
				$assign(ia, $IPAddressUtil::toScopedAddress(ia));
			}
			connectToAddress(ia, this->port, timeout);
			connected = true;
		} catch ($Throwable& var$2) {
			$assign(var$0, var$2);
		} /*finally*/ {
			if (!connected) {
				try {
					close();
				} catch ($IOException& ioe) {
				}
			}
			this->isConnected = connected;
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void AbstractPlainSocketImpl::connectToAddress($InetAddress* address, int32_t port, int32_t timeout) {
	if ($nc(address)->isAnyLocalAddress()) {
		doConnect($($InetAddress::getLocalHost()), port, timeout);
	} else {
		doConnect(address, port, timeout);
	}
}

void AbstractPlainSocketImpl::setOption(int32_t opt, Object$* val) {
	$useLocalCurrentObjectStackCache();
	if (isClosedOrPending()) {
		$throwNew($SocketException, "Socket Closed"_s);
	}
	bool on = true;
	{
		int32_t tmp = 0;
		switch (opt) {
		case $SocketOptions::SO_LINGER:
			{
				if (!($instanceOf($Integer, val)) && !($instanceOf($Boolean, val))) {
					$throwNew($SocketException, "Bad parameter for option"_s);
				}
				if ($instanceOf($Boolean, val)) {
					on = false;
				}
				break;
			}
		case $SocketOptions::SO_TIMEOUT:
			{
				if (!($instanceOf($Integer, val))) {
					$throwNew($SocketException, "Bad parameter for SO_TIMEOUT"_s);
				}
				tmp = $nc(($cast($Integer, val)))->intValue();
				if (tmp < 0) {
					$throwNew($IllegalArgumentException, "timeout < 0"_s);
				}
				this->timeout = tmp;
				break;
			}
		case $SocketOptions::IP_TOS:
			{
				if (!($instanceOf($Integer, val))) {
					$throwNew($SocketException, "bad argument for IP_TOS"_s);
				}
				this->trafficClass = ($cast($Integer, val))->intValue();
				break;
			}
		case $SocketOptions::SO_BINDADDR:
			{
				$throwNew($SocketException, "Cannot re-bind socket"_s);
			}
		case $SocketOptions::TCP_NODELAY:
			{
				if (!($instanceOf($Boolean, val))) {
					$throwNew($SocketException, "bad parameter for TCP_NODELAY"_s);
				}
				on = $nc(($cast($Boolean, val)))->booleanValue();
				break;
			}
		case $SocketOptions::SO_SNDBUF:
			{}
		case $SocketOptions::SO_RCVBUF:
			{
				if (!($instanceOf($Integer, val)) || !(($cast($Integer, val))->intValue() > 0)) {
					$throwNew($SocketException, "bad parameter for SO_SNDBUF or SO_RCVBUF"_s);
				}
				break;
			}
		case $SocketOptions::SO_KEEPALIVE:
			{
				if (!($instanceOf($Boolean, val))) {
					$throwNew($SocketException, "bad parameter for SO_KEEPALIVE"_s);
				}
				on = $nc(($cast($Boolean, val)))->booleanValue();
				break;
			}
		case $SocketOptions::SO_OOBINLINE:
			{
				if (!($instanceOf($Boolean, val))) {
					$throwNew($SocketException, "bad parameter for SO_OOBINLINE"_s);
				}
				on = $nc(($cast($Boolean, val)))->booleanValue();
				break;
			}
		case $SocketOptions::SO_REUSEADDR:
			{
				if (!($instanceOf($Boolean, val))) {
					$throwNew($SocketException, "bad parameter for SO_REUSEADDR"_s);
				}
				on = $nc(($cast($Boolean, val)))->booleanValue();
				break;
			}
		case $SocketOptions::SO_REUSEPORT:
			{
				if (!($instanceOf($Boolean, val))) {
					$throwNew($SocketException, "bad parameter for SO_REUSEPORT"_s);
				}
				$init($StandardSocketOptions);
				if (!$nc($(supportedOptions()))->contains($StandardSocketOptions::SO_REUSEPORT)) {
					$throwNew($UnsupportedOperationException, "unsupported option"_s);
				}
				on = $nc(($cast($Boolean, val)))->booleanValue();
				break;
			}
		default:
			{
				$throwNew($SocketException, $$str({"unrecognized TCP option: "_s, $$str(opt)}));
			}
		}
	}
	socketSetOption(opt, on, val);
}

$Object* AbstractPlainSocketImpl::getOption(int32_t opt) {
	$useLocalCurrentObjectStackCache();
	if (isClosedOrPending()) {
		$throwNew($SocketException, "Socket Closed"_s);
	}
	if (opt == $SocketOptions::SO_TIMEOUT) {
		return $of($Integer::valueOf(this->timeout));
	}
	int32_t ret = 0;
	{
		$var($InetAddressContainer, in, nullptr)
		switch (opt) {
		case $SocketOptions::TCP_NODELAY:
			{
				ret = socketGetOption(opt, nullptr);
				return $of($Boolean::valueOf(ret != -1));
			}
		case $SocketOptions::SO_OOBINLINE:
			{
				ret = socketGetOption(opt, nullptr);
				return $of($Boolean::valueOf(ret != -1));
			}
		case $SocketOptions::SO_LINGER:
			{
				ret = socketGetOption(opt, nullptr);
				$init($Boolean);
				return $of((ret == -1) ? $of($Boolean::FALSE) : $of($Integer::valueOf((ret))));
			}
		case $SocketOptions::SO_REUSEADDR:
			{
				ret = socketGetOption(opt, nullptr);
				return $of($Boolean::valueOf(ret != -1));
			}
		case $SocketOptions::SO_BINDADDR:
			{
				$assign(in, $new($InetAddressContainer));
				ret = socketGetOption(opt, in);
				return $of($nc(in)->addr);
			}
		case $SocketOptions::SO_SNDBUF:
			{}
		case $SocketOptions::SO_RCVBUF:
			{
				ret = socketGetOption(opt, nullptr);
				return $of($Integer::valueOf(ret));
			}
		case $SocketOptions::IP_TOS:
			{
				try {
					ret = socketGetOption(opt, nullptr);
					if (ret == -1) {
						return $of($Integer::valueOf(this->trafficClass));
					} else {
						return $of($Integer::valueOf(ret));
					}
				} catch ($SocketException& se) {
					return $of($Integer::valueOf(this->trafficClass));
				}
			}
		case $SocketOptions::SO_KEEPALIVE:
			{
				ret = socketGetOption(opt, nullptr);
				return $of($Boolean::valueOf(ret != -1));
			}
		case $SocketOptions::SO_REUSEPORT:
			{
				$init($StandardSocketOptions);
				if (!$nc($(supportedOptions()))->contains($StandardSocketOptions::SO_REUSEPORT)) {
					$throwNew($UnsupportedOperationException, "unsupported option"_s);
				}
				ret = socketGetOption(opt, nullptr);
				return $of($Boolean::valueOf(ret != -1));
			}
		default:
			{
				return $of(nullptr);
			}
		}
	}
}

$Set* AbstractPlainSocketImpl::clientSocketOptions() {
	$init(AbstractPlainSocketImpl);
	$useLocalCurrentObjectStackCache();
	$var($HashSet, options, $new($HashSet));
	$init($StandardSocketOptions);
	options->add($StandardSocketOptions::SO_KEEPALIVE);
	options->add($StandardSocketOptions::SO_SNDBUF);
	options->add($StandardSocketOptions::SO_RCVBUF);
	options->add($StandardSocketOptions::SO_REUSEADDR);
	options->add($StandardSocketOptions::SO_LINGER);
	options->add($StandardSocketOptions::IP_TOS);
	options->add($StandardSocketOptions::TCP_NODELAY);
	if (isReusePortAvailable()) {
		options->add($StandardSocketOptions::SO_REUSEPORT);
	}
	options->addAll($($ExtendedSocketOptions::clientSocketOptions()));
	return $Collections::unmodifiableSet(options);
}

$Set* AbstractPlainSocketImpl::serverSocketOptions() {
	$init(AbstractPlainSocketImpl);
	$useLocalCurrentObjectStackCache();
	$var($HashSet, options, $new($HashSet));
	$init($StandardSocketOptions);
	options->add($StandardSocketOptions::SO_RCVBUF);
	options->add($StandardSocketOptions::SO_REUSEADDR);
	options->add($StandardSocketOptions::IP_TOS);
	if (isReusePortAvailable()) {
		options->add($StandardSocketOptions::SO_REUSEPORT);
	}
	options->addAll($($ExtendedSocketOptions::serverSocketOptions()));
	return $Collections::unmodifiableSet(options);
}

$Set* AbstractPlainSocketImpl::supportedOptions() {
	if (this->isServer) {
		return AbstractPlainSocketImpl::serverSocketOptions$;
	} else {
		return AbstractPlainSocketImpl::clientSocketOptions$;
	}
}

void AbstractPlainSocketImpl::setOption($SocketOption* name, Object$* value) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(name);
	if (!$nc($(supportedOptions()))->contains(name)) {
		$throwNew($UnsupportedOperationException, $$str({"\'"_s, name, "\' not supported"_s}));
	}
	if (!$nc(name->type())->isInstance(value)) {
		$throwNew($IllegalArgumentException, $$str({"Invalid value \'"_s, value, "\'"_s}));
	}
	if (isClosedOrPending()) {
		$throwNew($SocketException, "Socket closed"_s);
	}
	$init($StandardSocketOptions);
	if (name == $StandardSocketOptions::SO_KEEPALIVE) {
		setOption($SocketOptions::SO_KEEPALIVE, value);
	} else {
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
						if (name == $StandardSocketOptions::SO_LINGER) {
							if ($nc(($cast($Integer, value)))->intValue() < 0) {
								setOption($SocketOptions::SO_LINGER, $($of($Boolean::valueOf(false))));
							} else {
								setOption($SocketOptions::SO_LINGER, value);
							}
						} else {
							if (name == $StandardSocketOptions::IP_TOS) {
								int32_t i = $nc(($cast($Integer, value)))->intValue();
								if (i < 0 || i > 255) {
									$throwNew($IllegalArgumentException, $$str({"Invalid IP_TOS value: "_s, value}));
								}
								setOption($SocketOptions::IP_TOS, value);
							} else {
								if (name == $StandardSocketOptions::TCP_NODELAY) {
									setOption($SocketOptions::TCP_NODELAY, value);
								} else if ($nc(AbstractPlainSocketImpl::extendedOptions)->isOptionSupported(name)) {
									$nc(AbstractPlainSocketImpl::extendedOptions)->setOption(this->fd, name, value);
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

$Object* AbstractPlainSocketImpl::getOption($SocketOption* name) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(name);
	if (!$nc($(supportedOptions()))->contains(name)) {
		$throwNew($UnsupportedOperationException, $$str({"\'"_s, name, "\' not supported"_s}));
	}
	if (isClosedOrPending()) {
		$throwNew($SocketException, "Socket closed"_s);
	}
	$init($StandardSocketOptions);
	if (name == $StandardSocketOptions::SO_KEEPALIVE) {
		return $of(getOption($SocketOptions::SO_KEEPALIVE));
	} else {
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
						if (name == $StandardSocketOptions::SO_LINGER) {
							$var($Object, value, getOption($SocketOptions::SO_LINGER));
							if ($instanceOf($Boolean, value)) {
								if (!AbstractPlainSocketImpl::$assertionsDisabled && !($nc(($cast($Boolean, value)))->booleanValue() == false)) {
									$throwNew($AssertionError);
								}
								$assign(value, $Integer::valueOf(-1));
							}
							return $of(value);
						} else {
							if (name == $StandardSocketOptions::IP_TOS) {
								return $of(getOption($SocketOptions::IP_TOS));
							} else {
								if (name == $StandardSocketOptions::TCP_NODELAY) {
									return $of(getOption($SocketOptions::TCP_NODELAY));
								} else if ($nc(AbstractPlainSocketImpl::extendedOptions)->isOptionSupported(name)) {
									return $of($nc(AbstractPlainSocketImpl::extendedOptions)->getOption(this->fd, name));
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

void AbstractPlainSocketImpl::doConnect($InetAddress* address, int32_t port, int32_t timeout) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$synchronized(this->fdLock) {
			if (!this->closePending && !this->isBound) {
				$NetHooks::beforeTcpConnect(this->fd, address, port);
			}
		}
		try {
			acquireFD();
			{
				$var($Throwable, var$0, nullptr);
				try {
					socketConnect(address, port, timeout);
					$synchronized(this->fdLock) {
						if (this->closePending) {
							$throwNew($SocketException, "Socket closed"_s);
						}
					}
				} catch ($Throwable& var$1) {
					$assign(var$0, var$1);
				} /*finally*/ {
					releaseFD();
				}
				if (var$0 != nullptr) {
					$throw(var$0);
				}
			}
		} catch ($IOException& e) {
			close();
			$throw($($SocketExceptions::of(e, $$new($InetSocketAddress, address, port))));
		}
	}
}

void AbstractPlainSocketImpl::bind($InetAddress* address$renamed, int32_t lport) {
	$synchronized(this) {
		$var($InetAddress, address, address$renamed);
		$synchronized(this->fdLock) {
			if (!this->closePending && !this->isBound) {
				$NetHooks::beforeTcpBind(this->fd, address, lport);
			}
		}
		if ($nc(address)->isLinkLocalAddress()) {
			$assign(address, $IPAddressUtil::toScopedAddress(address));
		}
		socketBind(address, lport);
		this->isBound = true;
	}
}

void AbstractPlainSocketImpl::listen(int32_t count) {
	$synchronized(this) {
		socketListen(count);
	}
}

void AbstractPlainSocketImpl::accept($SocketImpl* si) {
	$set($nc(si), fd, $new($FileDescriptor));
	acquireFD();
	{
		$var($Throwable, var$0, nullptr);
		try {
			socketAccept(si);
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			releaseFD();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	$SocketCleanable::register$(si->fd, true);
}

$InputStream* AbstractPlainSocketImpl::getInputStream() {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$beforeCallerSensitive();
		$synchronized(this->fdLock) {
			if (isClosedOrPending()) {
				$throwNew($IOException, "Socket Closed"_s);
			}
			if (this->shut_rd) {
				$throwNew($IOException, "Socket input is shutdown"_s);
			}
			if (this->socketInputStream == nullptr) {
				$var($PrivilegedExceptionAction, pa, static_cast<$PrivilegedExceptionAction*>($new(AbstractPlainSocketImpl$$Lambda$lambda$getInputStream$0, this)));
				try {
					$set(this, socketInputStream, $cast($SocketInputStream, $AccessController::doPrivileged(pa)));
				} catch ($PrivilegedActionException& e) {
					$throw($cast($IOException, $(e->getCause())));
				}
			}
		}
		return this->socketInputStream;
	}
}

void AbstractPlainSocketImpl::setInputStream($SocketInputStream* in) {
	$set(this, socketInputStream, in);
}

$OutputStream* AbstractPlainSocketImpl::getOutputStream() {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$beforeCallerSensitive();
		$synchronized(this->fdLock) {
			if (isClosedOrPending()) {
				$throwNew($IOException, "Socket Closed"_s);
			}
			if (this->shut_wr) {
				$throwNew($IOException, "Socket output is shutdown"_s);
			}
			if (this->socketOutputStream == nullptr) {
				$var($PrivilegedExceptionAction, pa, static_cast<$PrivilegedExceptionAction*>($new(AbstractPlainSocketImpl$$Lambda$lambda$getOutputStream$1$1, this)));
				try {
					$set(this, socketOutputStream, $cast($SocketOutputStream, $AccessController::doPrivileged(pa)));
				} catch ($PrivilegedActionException& e) {
					$throw($cast($IOException, $(e->getCause())));
				}
			}
		}
		return this->socketOutputStream;
	}
}

void AbstractPlainSocketImpl::setFileDescriptor($FileDescriptor* fd) {
	$set(this, fd, fd);
}

void AbstractPlainSocketImpl::setAddress($InetAddress* address) {
	$set(this, address, address);
}

void AbstractPlainSocketImpl::setPort(int32_t port) {
	this->port = port;
}

void AbstractPlainSocketImpl::setLocalPort(int32_t localport) {
	this->localport = localport;
}

int32_t AbstractPlainSocketImpl::available() {
	$synchronized(this) {
		if (isClosedOrPending()) {
			$throwNew($IOException, "Stream closed."_s);
		}
		if (isConnectionReset() || this->shut_rd) {
			return 0;
		}
		int32_t n = 0;
		try {
			n = socketAvailable();
		} catch ($ConnectionResetException& exc1) {
			setConnectionReset();
		}
		return n;
	}
}

void AbstractPlainSocketImpl::close() {
	$synchronized(this->fdLock) {
		if (this->fd != nullptr) {
			if (this->fdUseCount == 0) {
				if (this->closePending) {
					return;
				}
				this->closePending = true;
				{
					$var($Throwable, var$0, nullptr);
					try {
						socketPreClose();
					} catch ($Throwable& var$1) {
						$assign(var$0, var$1);
					} /*finally*/ {
						socketClose();
					}
					if (var$0 != nullptr) {
						$throw(var$0);
					}
				}
				$set(this, fd, nullptr);
				return;
			} else if (!this->closePending) {
				this->closePending = true;
				--this->fdUseCount;
				socketPreClose();
			}
		}
	}
}

void AbstractPlainSocketImpl::reset() {
	$throwNew($InternalError, "should not get here"_s);
}

void AbstractPlainSocketImpl::shutdownInput() {
	if (this->fd != nullptr) {
		socketShutdown(AbstractPlainSocketImpl::SHUT_RD);
		if (this->socketInputStream != nullptr) {
			$nc(this->socketInputStream)->setEOF(true);
		}
		this->shut_rd = true;
	}
}

void AbstractPlainSocketImpl::shutdownOutput() {
	if (this->fd != nullptr) {
		socketShutdown(AbstractPlainSocketImpl::SHUT_WR);
		this->shut_wr = true;
	}
}

bool AbstractPlainSocketImpl::supportsUrgentData() {
	return true;
}

void AbstractPlainSocketImpl::sendUrgentData(int32_t data) {
	if (this->fd == nullptr) {
		$throwNew($IOException, "Socket Closed"_s);
	}
	socketSendUrgentData(data);
}

$FileDescriptor* AbstractPlainSocketImpl::acquireFD() {
	$synchronized(this->fdLock) {
		++this->fdUseCount;
		return this->fd;
	}
}

void AbstractPlainSocketImpl::releaseFD() {
	$synchronized(this->fdLock) {
		--this->fdUseCount;
		if (this->fdUseCount == -1) {
			if (this->fd != nullptr) {
				{
					$var($Throwable, var$0, nullptr);
					try {
						try {
							socketClose();
						} catch ($IOException& e) {
						}
					} catch ($Throwable& var$1) {
						$assign(var$0, var$1);
					} /*finally*/ {
						$set(this, fd, nullptr);
					}
					if (var$0 != nullptr) {
						$throw(var$0);
					}
				}
			}
		}
	}
}

bool AbstractPlainSocketImpl::isConnectionReset() {
	return this->connectionReset;
}

void AbstractPlainSocketImpl::setConnectionReset() {
	this->connectionReset = true;
}

bool AbstractPlainSocketImpl::isClosedOrPending() {
	$synchronized(this->fdLock) {
		if (this->closePending || (this->fd == nullptr)) {
			return true;
		} else {
			return false;
		}
	}
}

int32_t AbstractPlainSocketImpl::getTimeout() {
	return this->timeout;
}

void AbstractPlainSocketImpl::socketPreClose() {
	socketClose0(true);
}

void AbstractPlainSocketImpl::socketClose() {
	$SocketCleanable::unregister(this->fd);
	{
		$var($Throwable, var$0, nullptr);
		try {
			socketClose0(false);
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			if (!this->stream) {
				$ResourceManager::afterUdpClose();
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

bool AbstractPlainSocketImpl::isReusePortAvailable0() {
	$init(AbstractPlainSocketImpl);
	bool $ret = false;
	$prepareNativeStatic(AbstractPlainSocketImpl, isReusePortAvailable0, bool);
	$ret = $invokeNativeStatic();
	$finishNativeStatic();
	return $ret;
}

$SocketOutputStream* AbstractPlainSocketImpl::lambda$getOutputStream$1() {
	return $new($SocketOutputStream, this);
}

$SocketInputStream* AbstractPlainSocketImpl::lambda$getInputStream$0() {
	return $new($SocketInputStream, this);
}

void clinit$AbstractPlainSocketImpl($Class* class$) {
	AbstractPlainSocketImpl::$assertionsDisabled = !AbstractPlainSocketImpl::class$->desiredAssertionStatus();
	{
		$BootLoader::loadLibrary("net"_s);
	}
	$assignStatic(AbstractPlainSocketImpl::extendedOptions, $ExtendedSocketOptions::getInstance());
	$assignStatic(AbstractPlainSocketImpl::clientSocketOptions$, AbstractPlainSocketImpl::clientSocketOptions());
	$assignStatic(AbstractPlainSocketImpl::serverSocketOptions$, AbstractPlainSocketImpl::serverSocketOptions());
}

AbstractPlainSocketImpl::AbstractPlainSocketImpl() {
}

$Class* AbstractPlainSocketImpl::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(AbstractPlainSocketImpl$$Lambda$lambda$getInputStream$0::classInfo$.name)) {
			return AbstractPlainSocketImpl$$Lambda$lambda$getInputStream$0::load$(name, initialize);
		}
		if (name->equals(AbstractPlainSocketImpl$$Lambda$lambda$getOutputStream$1$1::classInfo$.name)) {
			return AbstractPlainSocketImpl$$Lambda$lambda$getOutputStream$1$1::load$(name, initialize);
		}
	}
	$loadClass(AbstractPlainSocketImpl, name, initialize, &_AbstractPlainSocketImpl_ClassInfo_, clinit$AbstractPlainSocketImpl, allocate$AbstractPlainSocketImpl);
	return class$;
}

$Class* AbstractPlainSocketImpl::class$ = nullptr;

	} // net
} // java