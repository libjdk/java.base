#include <java/nio/channels/spi/SelectorProvider$Holder.h>

#include <java/io/Serializable.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/InstantiationException.h>
#include <java/lang/NoSuchMethodException.h>
#include <java/lang/SecurityException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/InvocationTargetException.h>
#include <java/nio/channels/spi/SelectorProvider.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/Iterator.h>
#include <java/util/ServiceConfigurationError.h>
#include <java/util/ServiceLoader.h>
#include <sun/nio/ch/DefaultSelectorProvider.h>
#include <sun/nio/ch/SelectorProviderImpl.h>
#include <jcpp.h>

#undef INSTANCE

using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InstantiationException = ::java::lang::InstantiationException;
using $MethodInfo = ::java::lang::MethodInfo;
using $NoSuchMethodException = ::java::lang::NoSuchMethodException;
using $SecurityException = ::java::lang::SecurityException;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Constructor = ::java::lang::reflect::Constructor;
using $InvocationTargetException = ::java::lang::reflect::InvocationTargetException;
using $SelectorProvider = ::java::nio::channels::spi::SelectorProvider;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Iterator = ::java::util::Iterator;
using $ServiceConfigurationError = ::java::util::ServiceConfigurationError;
using $ServiceLoader = ::java::util::ServiceLoader;
using $DefaultSelectorProvider = ::sun::nio::ch::DefaultSelectorProvider;

namespace java {
	namespace nio {
		namespace channels {
			namespace spi {

class SelectorProvider$Holder$$Lambda$lambda$provider$0 : public $PrivilegedAction {
	$class(SelectorProvider$Holder$$Lambda$lambda$provider$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(SelectorProvider$Holder::lambda$provider$0());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SelectorProvider$Holder$$Lambda$lambda$provider$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo SelectorProvider$Holder$$Lambda$lambda$provider$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(SelectorProvider$Holder$$Lambda$lambda$provider$0, init$, void)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(SelectorProvider$Holder$$Lambda$lambda$provider$0, run, $Object*)},
	{}
};
$ClassInfo SelectorProvider$Holder$$Lambda$lambda$provider$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.nio.channels.spi.SelectorProvider$Holder$$Lambda$lambda$provider$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* SelectorProvider$Holder$$Lambda$lambda$provider$0::load$($String* name, bool initialize) {
	$loadClass(SelectorProvider$Holder$$Lambda$lambda$provider$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SelectorProvider$Holder$$Lambda$lambda$provider$0::class$ = nullptr;

$FieldInfo _SelectorProvider$Holder_FieldInfo_[] = {
	{"INSTANCE", "Ljava/nio/channels/spi/SelectorProvider;", nullptr, $STATIC | $FINAL, $staticField(SelectorProvider$Holder, INSTANCE)},
	{}
};

$MethodInfo _SelectorProvider$Holder_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(SelectorProvider$Holder, init$, void)},
	{"lambda$provider$0", "()Ljava/nio/channels/spi/SelectorProvider;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(SelectorProvider$Holder, lambda$provider$0, $SelectorProvider*)},
	{"loadProviderAsService", "()Ljava/nio/channels/spi/SelectorProvider;", nullptr, $PRIVATE | $STATIC, $staticMethod(SelectorProvider$Holder, loadProviderAsService, $SelectorProvider*)},
	{"loadProviderFromProperty", "()Ljava/nio/channels/spi/SelectorProvider;", nullptr, $PRIVATE | $STATIC, $staticMethod(SelectorProvider$Holder, loadProviderFromProperty, $SelectorProvider*)},
	{"provider", "()Ljava/nio/channels/spi/SelectorProvider;", nullptr, $STATIC, $staticMethod(SelectorProvider$Holder, provider, $SelectorProvider*)},
	{}
};

$InnerClassInfo _SelectorProvider$Holder_InnerClassesInfo_[] = {
	{"java.nio.channels.spi.SelectorProvider$Holder", "java.nio.channels.spi.SelectorProvider", "Holder", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _SelectorProvider$Holder_ClassInfo_ = {
	$ACC_SUPER,
	"java.nio.channels.spi.SelectorProvider$Holder",
	"java.lang.Object",
	nullptr,
	_SelectorProvider$Holder_FieldInfo_,
	_SelectorProvider$Holder_MethodInfo_,
	nullptr,
	nullptr,
	_SelectorProvider$Holder_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.nio.channels.spi.SelectorProvider"
};

$Object* allocate$SelectorProvider$Holder($Class* clazz) {
	return $of($alloc(SelectorProvider$Holder));
}

$SelectorProvider* SelectorProvider$Holder::INSTANCE = nullptr;

void SelectorProvider$Holder::init$() {
}

$SelectorProvider* SelectorProvider$Holder::provider() {
	$init(SelectorProvider$Holder);
	$beforeCallerSensitive();
	$var($PrivilegedAction, pa, static_cast<$PrivilegedAction*>($new(SelectorProvider$Holder$$Lambda$lambda$provider$0)));
	return $cast($SelectorProvider, $AccessController::doPrivileged(pa));
}

$SelectorProvider* SelectorProvider$Holder::loadProviderFromProperty() {
	$init(SelectorProvider$Holder);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($String, cn, $System::getProperty("java.nio.channels.spi.SelectorProvider"_s));
	if (cn == nullptr) {
		return nullptr;
	}
	try {
		$Class* clazz = $Class::forName(cn, true, $($ClassLoader::getSystemClassLoader()));
		return $cast($SelectorProvider, $nc($($nc(clazz)->getConstructor($$new($ClassArray, 0))))->newInstance($$new($ObjectArray, 0)));
	} catch ($ClassNotFoundException& x) {
		$throwNew($ServiceConfigurationError, nullptr, x);
	} catch ($NoSuchMethodException& x) {
		$throwNew($ServiceConfigurationError, nullptr, x);
	} catch ($IllegalAccessException& x) {
		$throwNew($ServiceConfigurationError, nullptr, x);
	} catch ($InvocationTargetException& x) {
		$throwNew($ServiceConfigurationError, nullptr, x);
	} catch ($InstantiationException& x) {
		$throwNew($ServiceConfigurationError, nullptr, x);
	} catch ($SecurityException& x) {
		$throwNew($ServiceConfigurationError, nullptr, x);
	}
	$shouldNotReachHere();
}

$SelectorProvider* SelectorProvider$Holder::loadProviderAsService() {
	$init(SelectorProvider$Holder);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$load($SelectorProvider);
	$var($ServiceLoader, sl, $ServiceLoader::load($SelectorProvider::class$, $($ClassLoader::getSystemClassLoader())));
	$var($Iterator, i, $nc(sl)->iterator());
	for (;;) {
		try {
			return $nc(i)->hasNext() ? $cast($SelectorProvider, $nc(i)->next()) : ($SelectorProvider*)nullptr;
		} catch ($ServiceConfigurationError& sce) {
			if ($instanceOf($SecurityException, $(sce->getCause()))) {
				continue;
			}
			$throw(sce);
		}
	}
	$shouldNotReachHere();
}

$SelectorProvider* SelectorProvider$Holder::lambda$provider$0() {
	$init(SelectorProvider$Holder);
	$var($SelectorProvider, sp, nullptr);
	if (($assign(sp, loadProviderFromProperty())) != nullptr) {
		return sp;
	}
	if (($assign(sp, loadProviderAsService())) != nullptr) {
		return sp;
	}
	return $DefaultSelectorProvider::get();
}

void clinit$SelectorProvider$Holder($Class* class$) {
	$assignStatic(SelectorProvider$Holder::INSTANCE, SelectorProvider$Holder::provider());
}

SelectorProvider$Holder::SelectorProvider$Holder() {
}

$Class* SelectorProvider$Holder::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(SelectorProvider$Holder$$Lambda$lambda$provider$0::classInfo$.name)) {
			return SelectorProvider$Holder$$Lambda$lambda$provider$0::load$(name, initialize);
		}
	}
	$loadClass(SelectorProvider$Holder, name, initialize, &_SelectorProvider$Holder_ClassInfo_, clinit$SelectorProvider$Holder, allocate$SelectorProvider$Holder);
	return class$;
}

$Class* SelectorProvider$Holder::class$ = nullptr;

			} // spi
		} // channels
	} // nio
} // java