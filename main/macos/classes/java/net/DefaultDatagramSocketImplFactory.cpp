#include <java/net/DefaultDatagramSocketImplFactory.h>

#include <java/net/DatagramSocketImpl.h>
#include <java/net/PlainDatagramSocketImpl.h>
#include <java/net/SocketException.h>
#include <sun/security/action/GetPropertyAction.h>
#include <jcpp.h>

using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $DatagramSocketImpl = ::java::net::DatagramSocketImpl;
using $PlainDatagramSocketImpl = ::java::net::PlainDatagramSocketImpl;
using $SocketException = ::java::net::SocketException;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;

namespace java {
	namespace net {

$FieldInfo _DefaultDatagramSocketImplFactory_FieldInfo_[] = {
	{"prefixImplClass", "Ljava/lang/Class;", "Ljava/lang/Class<*>;", $STATIC, $staticField(DefaultDatagramSocketImplFactory, prefixImplClass)},
	{}
};

$MethodInfo _DefaultDatagramSocketImplFactory_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(DefaultDatagramSocketImplFactory, init$, void)},
	{"createDatagramSocketImpl", "(Z)Ljava/net/DatagramSocketImpl;", nullptr, $STATIC, $staticMethod(DefaultDatagramSocketImplFactory, createDatagramSocketImpl, $DatagramSocketImpl*, bool), "java.net.SocketException"},
	{}
};

$ClassInfo _DefaultDatagramSocketImplFactory_ClassInfo_ = {
	$ACC_SUPER,
	"java.net.DefaultDatagramSocketImplFactory",
	"java.lang.Object",
	nullptr,
	_DefaultDatagramSocketImplFactory_FieldInfo_,
	_DefaultDatagramSocketImplFactory_MethodInfo_
};

$Object* allocate$DefaultDatagramSocketImplFactory($Class* clazz) {
	return $of($alloc(DefaultDatagramSocketImplFactory));
}

$Class* DefaultDatagramSocketImplFactory::prefixImplClass = nullptr;

void DefaultDatagramSocketImplFactory::init$() {
}

$DatagramSocketImpl* DefaultDatagramSocketImplFactory::createDatagramSocketImpl(bool isMulticast) {
	$init(DefaultDatagramSocketImplFactory);
	$beforeCallerSensitive();
	if (DefaultDatagramSocketImplFactory::prefixImplClass != nullptr) {
		try {
			$var($DatagramSocketImpl, result, $cast($DatagramSocketImpl, $nc(DefaultDatagramSocketImplFactory::prefixImplClass)->newInstance()));
			return result;
		} catch ($Exception& e) {
			$throwNew($SocketException, "can\'t instantiate DatagramSocketImpl"_s);
		}
	} else {
		return $new($PlainDatagramSocketImpl, isMulticast);
	}
}

void clinit$DefaultDatagramSocketImplFactory($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$assignStatic(DefaultDatagramSocketImplFactory::prefixImplClass, nullptr);
	{
		$var($String, prefix, nullptr);
		try {
			$assign(prefix, $GetPropertyAction::privilegedGetProperty("impl.prefix"_s));
			if (prefix != nullptr) {
				$assignStatic(DefaultDatagramSocketImplFactory::prefixImplClass, $Class::forName($$str({"java.net."_s, prefix, "DatagramSocketImpl"_s})));
			}
		} catch ($Exception& e) {
			$nc($System::err)->println($$str({"Can\'t find class: java.net."_s, prefix, "DatagramSocketImpl: check impl.prefix property"_s}));
		}
	}
}

DefaultDatagramSocketImplFactory::DefaultDatagramSocketImplFactory() {
}

$Class* DefaultDatagramSocketImplFactory::load$($String* name, bool initialize) {
	$loadClass(DefaultDatagramSocketImplFactory, name, initialize, &_DefaultDatagramSocketImplFactory_ClassInfo_, clinit$DefaultDatagramSocketImplFactory, allocate$DefaultDatagramSocketImplFactory);
	return class$;
}

$Class* DefaultDatagramSocketImplFactory::class$ = nullptr;

	} // net
} // java