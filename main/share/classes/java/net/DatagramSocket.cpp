#include <java/net/DatagramSocket.h>

#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/InternalError.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/DatagramPacket.h>
#include <java/net/DatagramSocket$1.h>
#include <java/net/DatagramSocketImpl.h>
#include <java/net/DatagramSocketImplFactory.h>
#include <java/net/DefaultDatagramSocketImplFactory.h>
#include <java/net/InetAddress.h>
#include <java/net/InetSocketAddress.h>
#include <java/net/MulticastSocket.h>
#include <java/net/NetMulticastSocket.h>
#include <java/net/NetworkInterface.h>
#include <java/net/SocketAddress.h>
#include <java/net/SocketException.h>
#include <java/net/SocketOption.h>
#include <java/nio/channels/DatagramChannel.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/Set.h>
#include <sun/net/NetProperties.h>
#include <sun/nio/ch/DatagramSocketAdaptor.h>
#include <sun/nio/ch/DefaultSelectorProvider.h>
#include <sun/nio/ch/SelectorProviderImpl.h>
#include <jcpp.h>

#undef NO_DELEGATE
#undef USE_PLAINDATAGRAMSOCKET

using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $NamedAttribute = ::java::lang::NamedAttribute;
using $SecurityManager = ::java::lang::SecurityManager;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $DatagramPacket = ::java::net::DatagramPacket;
using $DatagramSocket$1 = ::java::net::DatagramSocket$1;
using $DatagramSocketImpl = ::java::net::DatagramSocketImpl;
using $DatagramSocketImplFactory = ::java::net::DatagramSocketImplFactory;
using $DefaultDatagramSocketImplFactory = ::java::net::DefaultDatagramSocketImplFactory;
using $InetAddress = ::java::net::InetAddress;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $MulticastSocket = ::java::net::MulticastSocket;
using $NetMulticastSocket = ::java::net::NetMulticastSocket;
using $NetworkInterface = ::java::net::NetworkInterface;
using $SocketAddress = ::java::net::SocketAddress;
using $SocketException = ::java::net::SocketException;
using $SocketOption = ::java::net::SocketOption;
using $DatagramChannel = ::java::nio::channels::DatagramChannel;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Set = ::java::util::Set;
using $NetProperties = ::sun::net::NetProperties;
using $DatagramSocketAdaptor = ::sun::nio::ch::DatagramSocketAdaptor;
using $DefaultSelectorProvider = ::sun::nio::ch::DefaultSelectorProvider;
using $SelectorProviderImpl = ::sun::nio::ch::SelectorProviderImpl;

namespace java {
	namespace net {

class DatagramSocket$$Lambda$lambda$usePlainDatagramSocketImpl$0 : public $PrivilegedAction {
	$class(DatagramSocket$$Lambda$lambda$usePlainDatagramSocketImpl$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(DatagramSocket::lambda$usePlainDatagramSocketImpl$0());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DatagramSocket$$Lambda$lambda$usePlainDatagramSocketImpl$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo DatagramSocket$$Lambda$lambda$usePlainDatagramSocketImpl$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(DatagramSocket$$Lambda$lambda$usePlainDatagramSocketImpl$0, init$, void)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(DatagramSocket$$Lambda$lambda$usePlainDatagramSocketImpl$0, run, $Object*)},
	{}
};
$ClassInfo DatagramSocket$$Lambda$lambda$usePlainDatagramSocketImpl$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.net.DatagramSocket$$Lambda$lambda$usePlainDatagramSocketImpl$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* DatagramSocket$$Lambda$lambda$usePlainDatagramSocketImpl$0::load$($String* name, bool initialize) {
	$loadClass(DatagramSocket$$Lambda$lambda$usePlainDatagramSocketImpl$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DatagramSocket$$Lambda$lambda$usePlainDatagramSocketImpl$0::class$ = nullptr;

$NamedAttribute DatagramSocket_Attribute_var$0[] = {
	{"since", 's', "17"},
	{}
};

$CompoundAttribute _DatagramSocket_MethodAnnotations_setDatagramSocketImplFactory36[] = {
	{"Ljava/lang/Deprecated;", DatagramSocket_Attribute_var$0},
	{}
};

$FieldInfo _DatagramSocket_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(DatagramSocket, $assertionsDisabled)},
	{"delegate", "Ljava/net/DatagramSocket;", nullptr, $PRIVATE | $FINAL, $field(DatagramSocket, delegate$)},
	{"factory", "Ljava/net/DatagramSocketImplFactory;", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(DatagramSocket, factory)},
	{"NO_DELEGATE", "Ljava/net/SocketAddress;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DatagramSocket, NO_DELEGATE)},
	{"USE_PLAINDATAGRAMSOCKET", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DatagramSocket, USE_PLAINDATAGRAMSOCKET)},
	{}
};

$MethodInfo _DatagramSocket_MethodInfo_[] = {
	{"<init>", "(Ljava/net/DatagramSocket;)V", nullptr, 0, $method(DatagramSocket, init$, void, DatagramSocket*)},
	{"<init>", "()V", nullptr, $PUBLIC, $method(DatagramSocket, init$, void), "java.net.SocketException"},
	{"<init>", "(Ljava/net/DatagramSocketImpl;)V", nullptr, $PROTECTED, $method(DatagramSocket, init$, void, $DatagramSocketImpl*)},
	{"<init>", "(Ljava/net/SocketAddress;)V", nullptr, $PUBLIC, $method(DatagramSocket, init$, void, $SocketAddress*), "java.net.SocketException"},
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(DatagramSocket, init$, void, int32_t), "java.net.SocketException"},
	{"<init>", "(ILjava/net/InetAddress;)V", nullptr, $PUBLIC, $method(DatagramSocket, init$, void, int32_t, $InetAddress*), "java.net.SocketException"},
	{"bind", "(Ljava/net/SocketAddress;)V", nullptr, $PUBLIC, $virtualMethod(DatagramSocket, bind, void, $SocketAddress*), "java.net.SocketException"},
	{"close", "()V", nullptr, $PUBLIC, $virtualMethod(DatagramSocket, close, void)},
	{"connect", "(Ljava/net/InetAddress;I)V", nullptr, $PUBLIC, $virtualMethod(DatagramSocket, connect, void, $InetAddress*, int32_t)},
	{"connect", "(Ljava/net/SocketAddress;)V", nullptr, $PUBLIC, $virtualMethod(DatagramSocket, connect, void, $SocketAddress*), "java.net.SocketException"},
	{"createDelegate", "(Ljava/net/SocketAddress;Ljava/lang/Class;)Ljava/net/DatagramSocket;", "<T:Ljava/net/DatagramSocket;>(Ljava/net/SocketAddress;Ljava/lang/Class<TT;>;)TT;", $STATIC, $staticMethod(DatagramSocket, createDelegate, DatagramSocket*, $SocketAddress*, $Class*), "java.net.SocketException"},
	{"delegate", "()Ljava/net/DatagramSocket;", nullptr, 0, $virtualMethod(DatagramSocket, delegate, DatagramSocket*)},
	{"disconnect", "()V", nullptr, $PUBLIC, $virtualMethod(DatagramSocket, disconnect, void)},
	{"getBroadcast", "()Z", nullptr, $PUBLIC, $virtualMethod(DatagramSocket, getBroadcast, bool), "java.net.SocketException"},
	{"getChannel", "()Ljava/nio/channels/DatagramChannel;", nullptr, $PUBLIC, $virtualMethod(DatagramSocket, getChannel, $DatagramChannel*)},
	{"getInetAddress", "()Ljava/net/InetAddress;", nullptr, $PUBLIC, $virtualMethod(DatagramSocket, getInetAddress, $InetAddress*)},
	{"getLocalAddress", "()Ljava/net/InetAddress;", nullptr, $PUBLIC, $virtualMethod(DatagramSocket, getLocalAddress, $InetAddress*)},
	{"getLocalPort", "()I", nullptr, $PUBLIC, $virtualMethod(DatagramSocket, getLocalPort, int32_t)},
	{"getLocalSocketAddress", "()Ljava/net/SocketAddress;", nullptr, $PUBLIC, $virtualMethod(DatagramSocket, getLocalSocketAddress, $SocketAddress*)},
	{"getOption", "(Ljava/net/SocketOption;)Ljava/lang/Object;", "<T:Ljava/lang/Object;>(Ljava/net/SocketOption<TT;>;)TT;", $PUBLIC, $virtualMethod(DatagramSocket, getOption, $Object*, $SocketOption*), "java.io.IOException"},
	{"getPort", "()I", nullptr, $PUBLIC, $virtualMethod(DatagramSocket, getPort, int32_t)},
	{"getReceiveBufferSize", "()I", nullptr, $PUBLIC, $virtualMethod(DatagramSocket, getReceiveBufferSize, int32_t), "java.net.SocketException"},
	{"getRemoteSocketAddress", "()Ljava/net/SocketAddress;", nullptr, $PUBLIC, $virtualMethod(DatagramSocket, getRemoteSocketAddress, $SocketAddress*)},
	{"getReuseAddress", "()Z", nullptr, $PUBLIC, $virtualMethod(DatagramSocket, getReuseAddress, bool), "java.net.SocketException"},
	{"getSendBufferSize", "()I", nullptr, $PUBLIC, $virtualMethod(DatagramSocket, getSendBufferSize, int32_t), "java.net.SocketException"},
	{"getSoTimeout", "()I", nullptr, $PUBLIC, $virtualMethod(DatagramSocket, getSoTimeout, int32_t), "java.net.SocketException"},
	{"getTrafficClass", "()I", nullptr, $PUBLIC, $virtualMethod(DatagramSocket, getTrafficClass, int32_t), "java.net.SocketException"},
	{"isBound", "()Z", nullptr, $PUBLIC, $virtualMethod(DatagramSocket, isBound, bool)},
	{"isClosed", "()Z", nullptr, $PUBLIC, $virtualMethod(DatagramSocket, isClosed, bool)},
	{"isConnected", "()Z", nullptr, $PUBLIC, $virtualMethod(DatagramSocket, isConnected, bool)},
	{"joinGroup", "(Ljava/net/SocketAddress;Ljava/net/NetworkInterface;)V", nullptr, $PUBLIC, $virtualMethod(DatagramSocket, joinGroup, void, $SocketAddress*, $NetworkInterface*), "java.io.IOException"},
	{"lambda$usePlainDatagramSocketImpl$0", "()Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(DatagramSocket, lambda$usePlainDatagramSocketImpl$0, $String*)},
	{"leaveGroup", "(Ljava/net/SocketAddress;Ljava/net/NetworkInterface;)V", nullptr, $PUBLIC, $virtualMethod(DatagramSocket, leaveGroup, void, $SocketAddress*, $NetworkInterface*), "java.io.IOException"},
	{"receive", "(Ljava/net/DatagramPacket;)V", nullptr, $PUBLIC, $virtualMethod(DatagramSocket, receive, void, $DatagramPacket*), "java.io.IOException"},
	{"send", "(Ljava/net/DatagramPacket;)V", nullptr, $PUBLIC, $virtualMethod(DatagramSocket, send, void, $DatagramPacket*), "java.io.IOException"},
	{"setBroadcast", "(Z)V", nullptr, $PUBLIC, $virtualMethod(DatagramSocket, setBroadcast, void, bool), "java.net.SocketException"},
	{"setDatagramSocketImplFactory", "(Ljava/net/DatagramSocketImplFactory;)V", nullptr, $PUBLIC | $STATIC | $SYNCHRONIZED | $DEPRECATED, $staticMethod(DatagramSocket, setDatagramSocketImplFactory, void, $DatagramSocketImplFactory*), "java.io.IOException", nullptr, _DatagramSocket_MethodAnnotations_setDatagramSocketImplFactory36},
	{"setOption", "(Ljava/net/SocketOption;Ljava/lang/Object;)Ljava/net/DatagramSocket;", "<T:Ljava/lang/Object;>(Ljava/net/SocketOption<TT;>;TT;)Ljava/net/DatagramSocket;", $PUBLIC, $virtualMethod(DatagramSocket, setOption, DatagramSocket*, $SocketOption*, Object$*), "java.io.IOException"},
	{"setReceiveBufferSize", "(I)V", nullptr, $PUBLIC, $virtualMethod(DatagramSocket, setReceiveBufferSize, void, int32_t), "java.net.SocketException"},
	{"setReuseAddress", "(Z)V", nullptr, $PUBLIC, $virtualMethod(DatagramSocket, setReuseAddress, void, bool), "java.net.SocketException"},
	{"setSendBufferSize", "(I)V", nullptr, $PUBLIC, $virtualMethod(DatagramSocket, setSendBufferSize, void, int32_t), "java.net.SocketException"},
	{"setSoTimeout", "(I)V", nullptr, $PUBLIC, $virtualMethod(DatagramSocket, setSoTimeout, void, int32_t), "java.net.SocketException"},
	{"setTrafficClass", "(I)V", nullptr, $PUBLIC, $virtualMethod(DatagramSocket, setTrafficClass, void, int32_t), "java.net.SocketException"},
	{"supportedOptions", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/net/SocketOption<*>;>;", $PUBLIC, $virtualMethod(DatagramSocket, supportedOptions, $Set*)},
	{"toSocketException", "(Ljava/io/IOException;)Ljava/net/SocketException;", nullptr, $PRIVATE | $STATIC, $staticMethod(DatagramSocket, toSocketException, $SocketException*, $IOException*)},
	{"usePlainDatagramSocketImpl", "()Z", nullptr, $PRIVATE | $STATIC, $staticMethod(DatagramSocket, usePlainDatagramSocketImpl, bool)},
	{}
};

$InnerClassInfo _DatagramSocket_InnerClassesInfo_[] = {
	{"java.net.DatagramSocket$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _DatagramSocket_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.net.DatagramSocket",
	"java.lang.Object",
	"java.io.Closeable",
	_DatagramSocket_FieldInfo_,
	_DatagramSocket_MethodInfo_,
	nullptr,
	nullptr,
	_DatagramSocket_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.net.DatagramSocket$1"
};

$Object* allocate$DatagramSocket($Class* clazz) {
	return $of($alloc(DatagramSocket));
}

bool DatagramSocket::$assertionsDisabled = false;
$volatile($DatagramSocketImplFactory*) DatagramSocket::factory = nullptr;
$SocketAddress* DatagramSocket::NO_DELEGATE = nullptr;
bool DatagramSocket::USE_PLAINDATAGRAMSOCKET = false;

DatagramSocket* DatagramSocket::delegate() {
	if (this->delegate$ == nullptr) {
		$throwNew($InternalError, "Should not get here"_s);
	}
	return this->delegate$;
}

void DatagramSocket::init$(DatagramSocket* delegate) {
	if (!DatagramSocket::$assertionsDisabled && !(delegate == nullptr || $instanceOf($NetMulticastSocket, delegate) || $instanceOf($DatagramSocketAdaptor, delegate))) {
		$throwNew($AssertionError);
	}
	$set(this, delegate$, delegate);
}

void DatagramSocket::init$() {
	DatagramSocket::init$(static_cast<$SocketAddress*>($$new($InetSocketAddress, 0)));
}

void DatagramSocket::init$($DatagramSocketImpl* impl) {
	DatagramSocket::init$(static_cast<DatagramSocket*>($$new($NetMulticastSocket, impl)));
}

void DatagramSocket::init$($SocketAddress* bindaddr) {
	DatagramSocket::init$($(createDelegate(bindaddr, DatagramSocket::class$)));
}

void DatagramSocket::init$(int32_t port) {
	DatagramSocket::init$(port, nullptr);
}

void DatagramSocket::init$(int32_t port, $InetAddress* laddr) {
	DatagramSocket::init$(static_cast<$SocketAddress*>($$new($InetSocketAddress, laddr, port)));
}

void DatagramSocket::bind($SocketAddress* addr) {
	$nc($(delegate()))->bind(addr);
}

void DatagramSocket::connect($InetAddress* address, int32_t port) {
	$nc($(delegate()))->connect(address, port);
}

void DatagramSocket::connect($SocketAddress* addr) {
	$nc($(delegate()))->connect(addr);
}

void DatagramSocket::disconnect() {
	$nc($(delegate()))->disconnect();
}

bool DatagramSocket::isBound() {
	return $nc($(delegate()))->isBound();
}

bool DatagramSocket::isConnected() {
	return $nc($(delegate()))->isConnected();
}

$InetAddress* DatagramSocket::getInetAddress() {
	return $nc($(delegate()))->getInetAddress();
}

int32_t DatagramSocket::getPort() {
	return $nc($(delegate()))->getPort();
}

$SocketAddress* DatagramSocket::getRemoteSocketAddress() {
	return $nc($(delegate()))->getRemoteSocketAddress();
}

$SocketAddress* DatagramSocket::getLocalSocketAddress() {
	return $nc($(delegate()))->getLocalSocketAddress();
}

void DatagramSocket::send($DatagramPacket* p) {
	$nc($(delegate()))->send(p);
}

void DatagramSocket::receive($DatagramPacket* p) {
	$nc($(delegate()))->receive(p);
}

$InetAddress* DatagramSocket::getLocalAddress() {
	return $nc($(delegate()))->getLocalAddress();
}

int32_t DatagramSocket::getLocalPort() {
	return $nc($(delegate()))->getLocalPort();
}

void DatagramSocket::setSoTimeout(int32_t timeout) {
	$nc($(delegate()))->setSoTimeout(timeout);
}

int32_t DatagramSocket::getSoTimeout() {
	return $nc($(delegate()))->getSoTimeout();
}

void DatagramSocket::setSendBufferSize(int32_t size) {
	$nc($(delegate()))->setSendBufferSize(size);
}

int32_t DatagramSocket::getSendBufferSize() {
	return $nc($(delegate()))->getSendBufferSize();
}

void DatagramSocket::setReceiveBufferSize(int32_t size) {
	$nc($(delegate()))->setReceiveBufferSize(size);
}

int32_t DatagramSocket::getReceiveBufferSize() {
	return $nc($(delegate()))->getReceiveBufferSize();
}

void DatagramSocket::setReuseAddress(bool on) {
	$nc($(delegate()))->setReuseAddress(on);
}

bool DatagramSocket::getReuseAddress() {
	return $nc($(delegate()))->getReuseAddress();
}

void DatagramSocket::setBroadcast(bool on) {
	$nc($(delegate()))->setBroadcast(on);
}

bool DatagramSocket::getBroadcast() {
	return $nc($(delegate()))->getBroadcast();
}

void DatagramSocket::setTrafficClass(int32_t tc) {
	$nc($(delegate()))->setTrafficClass(tc);
}

int32_t DatagramSocket::getTrafficClass() {
	return $nc($(delegate()))->getTrafficClass();
}

void DatagramSocket::close() {
	$nc($(delegate()))->close();
}

bool DatagramSocket::isClosed() {
	return $nc($(delegate()))->isClosed();
}

$DatagramChannel* DatagramSocket::getChannel() {
	return nullptr;
}

void DatagramSocket::setDatagramSocketImplFactory($DatagramSocketImplFactory* fac) {
	$load(DatagramSocket);
	$synchronized(class$) {
		$init(DatagramSocket);
		if (DatagramSocket::factory != nullptr) {
			$throwNew($SocketException, "factory already defined"_s);
		}
		$var($SecurityManager, security, $System::getSecurityManager());
		if (security != nullptr) {
			security->checkSetFactory();
		}
		$assignStatic(DatagramSocket::factory, fac);
	}
}

DatagramSocket* DatagramSocket::setOption($SocketOption* name, Object$* value) {
	$nc($(delegate()))->setOption(name, value);
	return this;
}

$Object* DatagramSocket::getOption($SocketOption* name) {
	return $of($nc($(delegate()))->getOption(name));
}

$Set* DatagramSocket::supportedOptions() {
	return $nc($(delegate()))->supportedOptions();
}

void DatagramSocket::joinGroup($SocketAddress* mcastaddr, $NetworkInterface* netIf) {
	$nc($(delegate()))->joinGroup(mcastaddr, netIf);
}

void DatagramSocket::leaveGroup($SocketAddress* mcastaddr, $NetworkInterface* netIf) {
	$nc($(delegate()))->leaveGroup(mcastaddr, netIf);
}

bool DatagramSocket::usePlainDatagramSocketImpl() {
	$init(DatagramSocket);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($PrivilegedAction, pa, static_cast<$PrivilegedAction*>($new(DatagramSocket$$Lambda$lambda$usePlainDatagramSocketImpl$0)));
	$var($String, s, $cast($String, $AccessController::doPrivileged(pa)));
	bool var$0 = (s != nullptr);
	if (var$0) {
		bool var$1 = s->isEmpty();
		var$0 = (var$1 || s->equalsIgnoreCase("true"_s));
	}
	return var$0;
}

$SocketException* DatagramSocket::toSocketException($IOException* e) {
	$init(DatagramSocket);
	$useLocalCurrentObjectStackCache();
	if ($instanceOf($SocketException, e)) {
		return $cast($SocketException, e);
	}
	$var($Throwable, cause, $nc(e)->getCause());
	if ($instanceOf($SocketException, cause)) {
		return $cast($SocketException, cause);
	}
	$var($SocketException, se, $new($SocketException, $(e->getMessage())));
	se->initCause(e);
	return se;
}

DatagramSocket* DatagramSocket::createDelegate($SocketAddress* bindaddr, $Class* type) {
	$init(DatagramSocket);
	$useLocalCurrentObjectStackCache();
	if (bindaddr == DatagramSocket::NO_DELEGATE) {
		return nullptr;
	}
	$load($MulticastSocket);
	if (!DatagramSocket::$assertionsDisabled && !(type == DatagramSocket::class$ || type == $MulticastSocket::class$)) {
		$throwNew($AssertionError);
	}
	bool multicast = (type == $MulticastSocket::class$);
	$var(DatagramSocket, delegate, nullptr);
	bool initialized = false;
	{
		$var($Throwable, var$0, nullptr);
		try {
			try {
				$var($DatagramSocketImplFactory, factory, DatagramSocket::factory);
				if (DatagramSocket::USE_PLAINDATAGRAMSOCKET || factory != nullptr) {
					$var($DatagramSocketImpl, impl, nullptr);
					if (factory != nullptr) {
						$assign(impl, factory->createDatagramSocketImpl());
					} else {
						$assign(impl, $DefaultDatagramSocketImplFactory::createDatagramSocketImpl(multicast));
					}
					$assign(delegate, $new($NetMulticastSocket, impl));
					$nc(($cast($NetMulticastSocket, delegate)))->getImpl();
				} else {
					$assign(delegate, $nc($($nc($($DefaultSelectorProvider::get()))->openUninterruptibleDatagramChannel()))->socket());
				}
				if (multicast) {
					$nc(delegate)->setReuseAddress(true);
				}
				if (bindaddr != nullptr) {
					$nc(delegate)->bind(bindaddr);
				}
				try {
					$nc(delegate)->setBroadcast(true);
				} catch ($IOException& ioe) {
				}
				initialized = true;
			} catch ($IOException& ioe) {
				$throw($(toSocketException(ioe)));
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			if (!initialized && delegate != nullptr) {
				delegate->close();
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	$var(DatagramSocket, result, delegate);
	return result;
}

$String* DatagramSocket::lambda$usePlainDatagramSocketImpl$0() {
	$init(DatagramSocket);
	return $NetProperties::get("jdk.net.usePlainDatagramSocketImpl"_s);
}

void clinit$DatagramSocket($Class* class$) {
	DatagramSocket::$assertionsDisabled = !DatagramSocket::class$->desiredAssertionStatus();
	$assignStatic(DatagramSocket::NO_DELEGATE, $new($DatagramSocket$1));
	DatagramSocket::USE_PLAINDATAGRAMSOCKET = DatagramSocket::usePlainDatagramSocketImpl();
}

DatagramSocket::DatagramSocket() {
}

$Class* DatagramSocket::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(DatagramSocket$$Lambda$lambda$usePlainDatagramSocketImpl$0::classInfo$.name)) {
			return DatagramSocket$$Lambda$lambda$usePlainDatagramSocketImpl$0::load$(name, initialize);
		}
	}
	$loadClass(DatagramSocket, name, initialize, &_DatagramSocket_ClassInfo_, clinit$DatagramSocket, allocate$DatagramSocket);
	return class$;
}

$Class* DatagramSocket::class$ = nullptr;

	} // net
} // java