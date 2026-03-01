#include <java/net/DefaultDatagramSocketImplFactory.h>

#include <java/net/DatagramSocketImpl.h>
#include <java/net/SocketException.h>
#include <java/net/TwoStacksPlainDatagramSocketImpl.h>
#include <java/util/Properties.h>
#include <sun/security/action/GetPropertyAction.h>
#include <jcpp.h>

using $PrintStream = ::java::io::PrintStream;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $DatagramSocketImpl = ::java::net::DatagramSocketImpl;
using $SocketException = ::java::net::SocketException;
using $TwoStacksPlainDatagramSocketImpl = ::java::net::TwoStacksPlainDatagramSocketImpl;
using $Properties = ::java::util::Properties;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;

namespace java {
	namespace net {

$FieldInfo _DefaultDatagramSocketImplFactory_FieldInfo_[] = {
	{"prefixImplClass", "Ljava/lang/Class;", "Ljava/lang/Class<*>;", $PRIVATE | $STATIC | $FINAL, $staticField(DefaultDatagramSocketImplFactory, prefixImplClass)},
	{"preferIPv4Stack", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DefaultDatagramSocketImplFactory, preferIPv4Stack)},
	{"exclusiveBind", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DefaultDatagramSocketImplFactory, exclusiveBind)},
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
bool DefaultDatagramSocketImplFactory::preferIPv4Stack = false;
bool DefaultDatagramSocketImplFactory::exclusiveBind = false;

void DefaultDatagramSocketImplFactory::init$() {
}

$DatagramSocketImpl* DefaultDatagramSocketImplFactory::createDatagramSocketImpl(bool isMulticast) {
	$init(DefaultDatagramSocketImplFactory);
	$beforeCallerSensitive();
	if (DefaultDatagramSocketImplFactory::prefixImplClass != nullptr) {
		try {
			$var($Object, result, $nc(DefaultDatagramSocketImplFactory::prefixImplClass)->newInstance());
			return $cast($DatagramSocketImpl, result);
		} catch ($Exception& e) {
			$throwNew($SocketException, "can\'t instantiate DatagramSocketImpl"_s);
		}
	} else {
		return $new($TwoStacksPlainDatagramSocketImpl, DefaultDatagramSocketImplFactory::exclusiveBind && !isMulticast, isMulticast);
	}
}

void clinit$DefaultDatagramSocketImplFactory($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	{
		$Class* prefixImplClassLocal = nullptr;
		$var($Properties, props, $GetPropertyAction::privilegedGetProperties());
		DefaultDatagramSocketImplFactory::preferIPv4Stack = $Boolean::parseBoolean($($nc(props)->getProperty("java.net.preferIPv4Stack"_s)));
		$var($String, exclBindProp, $nc(props)->getProperty("sun.net.useExclusiveBind"_s, ""_s));
		DefaultDatagramSocketImplFactory::exclusiveBind = ($nc(exclBindProp)->isEmpty()) ? true : $Boolean::parseBoolean(exclBindProp);
		$var($String, prefix, nullptr);
		try {
			$assign(prefix, props->getProperty("impl.prefix"_s));
			if (prefix != nullptr) {
				prefixImplClassLocal = $Class::forName($$str({"java.net."_s, prefix, "DatagramSocketImpl"_s}));
			}
		} catch ($Exception& e) {
			$nc($System::err)->println($$str({"Can\'t find class: java.net."_s, prefix, "DatagramSocketImpl: check impl.prefix property"_s}));
		}
		$assignStatic(DefaultDatagramSocketImplFactory::prefixImplClass, prefixImplClassLocal);
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