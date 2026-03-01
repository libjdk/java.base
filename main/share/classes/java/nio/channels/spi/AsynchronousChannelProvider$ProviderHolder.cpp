#include <java/nio/channels/spi/AsynchronousChannelProvider$ProviderHolder.h>

#include <java/lang/ClassLoader.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/InstantiationException.h>
#include <java/lang/SecurityException.h>
#include <java/nio/channels/spi/AsynchronousChannelProvider$ProviderHolder$1.h>
#include <java/nio/channels/spi/AsynchronousChannelProvider.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/Iterator.h>
#include <java/util/ServiceConfigurationError.h>
#include <java/util/ServiceLoader.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InstantiationException = ::java::lang::InstantiationException;
using $MethodInfo = ::java::lang::MethodInfo;
using $SecurityException = ::java::lang::SecurityException;
using $AsynchronousChannelProvider = ::java::nio::channels::spi::AsynchronousChannelProvider;
using $AsynchronousChannelProvider$ProviderHolder$1 = ::java::nio::channels::spi::AsynchronousChannelProvider$ProviderHolder$1;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Iterator = ::java::util::Iterator;
using $ServiceConfigurationError = ::java::util::ServiceConfigurationError;
using $ServiceLoader = ::java::util::ServiceLoader;

namespace java {
	namespace nio {
		namespace channels {
			namespace spi {

$FieldInfo _AsynchronousChannelProvider$ProviderHolder_FieldInfo_[] = {
	{"provider", "Ljava/nio/channels/spi/AsynchronousChannelProvider;", nullptr, $STATIC | $FINAL, $staticField(AsynchronousChannelProvider$ProviderHolder, provider)},
	{}
};

$MethodInfo _AsynchronousChannelProvider$ProviderHolder_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(AsynchronousChannelProvider$ProviderHolder, init$, void)},
	{"load", "()Ljava/nio/channels/spi/AsynchronousChannelProvider;", nullptr, $PRIVATE | $STATIC, $staticMethod(AsynchronousChannelProvider$ProviderHolder, load, $AsynchronousChannelProvider*)},
	{"loadProviderAsService", "()Ljava/nio/channels/spi/AsynchronousChannelProvider;", nullptr, $PRIVATE | $STATIC, $staticMethod(AsynchronousChannelProvider$ProviderHolder, loadProviderAsService, $AsynchronousChannelProvider*)},
	{"loadProviderFromProperty", "()Ljava/nio/channels/spi/AsynchronousChannelProvider;", nullptr, $PRIVATE | $STATIC, $staticMethod(AsynchronousChannelProvider$ProviderHolder, loadProviderFromProperty, $AsynchronousChannelProvider*)},
	{}
};

$InnerClassInfo _AsynchronousChannelProvider$ProviderHolder_InnerClassesInfo_[] = {
	{"java.nio.channels.spi.AsynchronousChannelProvider$ProviderHolder", "java.nio.channels.spi.AsynchronousChannelProvider", "ProviderHolder", $PRIVATE | $STATIC},
	{"java.nio.channels.spi.AsynchronousChannelProvider$ProviderHolder$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _AsynchronousChannelProvider$ProviderHolder_ClassInfo_ = {
	$ACC_SUPER,
	"java.nio.channels.spi.AsynchronousChannelProvider$ProviderHolder",
	"java.lang.Object",
	nullptr,
	_AsynchronousChannelProvider$ProviderHolder_FieldInfo_,
	_AsynchronousChannelProvider$ProviderHolder_MethodInfo_,
	nullptr,
	nullptr,
	_AsynchronousChannelProvider$ProviderHolder_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.nio.channels.spi.AsynchronousChannelProvider"
};

$Object* allocate$AsynchronousChannelProvider$ProviderHolder($Class* clazz) {
	return $of($alloc(AsynchronousChannelProvider$ProviderHolder));
}

$AsynchronousChannelProvider* AsynchronousChannelProvider$ProviderHolder::provider = nullptr;

void AsynchronousChannelProvider$ProviderHolder::init$() {
}

$AsynchronousChannelProvider* AsynchronousChannelProvider$ProviderHolder::load() {
	$init(AsynchronousChannelProvider$ProviderHolder);
	$beforeCallerSensitive();
	return $cast($AsynchronousChannelProvider, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($AsynchronousChannelProvider$ProviderHolder$1))));
}

$AsynchronousChannelProvider* AsynchronousChannelProvider$ProviderHolder::loadProviderFromProperty() {
	$init(AsynchronousChannelProvider$ProviderHolder);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($String, cn, $System::getProperty("java.nio.channels.spi.AsynchronousChannelProvider"_s));
	if (cn == nullptr) {
		return nullptr;
	}
	try {
		$var($Object, tmp, $Class::forName(cn, true, $($ClassLoader::getSystemClassLoader()))->newInstance());
		return $cast($AsynchronousChannelProvider, tmp);
	} catch ($ClassNotFoundException& x) {
		$throwNew($ServiceConfigurationError, nullptr, x);
	} catch ($IllegalAccessException& x) {
		$throwNew($ServiceConfigurationError, nullptr, x);
	} catch ($InstantiationException& x) {
		$throwNew($ServiceConfigurationError, nullptr, x);
	} catch ($SecurityException& x) {
		$throwNew($ServiceConfigurationError, nullptr, x);
	}
	$shouldNotReachHere();
}

$AsynchronousChannelProvider* AsynchronousChannelProvider$ProviderHolder::loadProviderAsService() {
	$init(AsynchronousChannelProvider$ProviderHolder);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$load($AsynchronousChannelProvider);
	$var($ServiceLoader, sl, $ServiceLoader::load($AsynchronousChannelProvider::class$, $($ClassLoader::getSystemClassLoader())));
	$var($Iterator, i, $nc(sl)->iterator());
	for (;;) {
		try {
			return ($nc(i)->hasNext()) ? $cast($AsynchronousChannelProvider, $nc(i)->next()) : ($AsynchronousChannelProvider*)nullptr;
		} catch ($ServiceConfigurationError& sce) {
			if ($instanceOf($SecurityException, $(sce->getCause()))) {
				continue;
			}
			$throw(sce);
		}
	}
	$shouldNotReachHere();
}

void clinit$AsynchronousChannelProvider$ProviderHolder($Class* class$) {
	$assignStatic(AsynchronousChannelProvider$ProviderHolder::provider, AsynchronousChannelProvider$ProviderHolder::load());
}

AsynchronousChannelProvider$ProviderHolder::AsynchronousChannelProvider$ProviderHolder() {
}

$Class* AsynchronousChannelProvider$ProviderHolder::load$($String* name, bool initialize) {
	$loadClass(AsynchronousChannelProvider$ProviderHolder, name, initialize, &_AsynchronousChannelProvider$ProviderHolder_ClassInfo_, clinit$AsynchronousChannelProvider$ProviderHolder, allocate$AsynchronousChannelProvider$ProviderHolder);
	return class$;
}

$Class* AsynchronousChannelProvider$ProviderHolder::class$ = nullptr;

			} // spi
		} // channels
	} // nio
} // java