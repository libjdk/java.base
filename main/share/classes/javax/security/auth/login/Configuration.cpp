#include <javax/security/auth/login/Configuration.h>

#include <java/lang/InstantiationException.h>
#include <java/lang/SecurityException.h>
#include <java/lang/SecurityManager.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/PrivilegedActionException.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/security/Provider.h>
#include <java/util/Objects.h>
#include <javax/security/auth/AuthPermission.h>
#include <javax/security/auth/login/AppConfigurationEntry.h>
#include <javax/security/auth/login/Configuration$1.h>
#include <javax/security/auth/login/Configuration$2.h>
#include <javax/security/auth/login/Configuration$3.h>
#include <javax/security/auth/login/Configuration$ConfigDelegate.h>
#include <javax/security/auth/login/Configuration$Parameters.h>
#include <javax/security/auth/login/ConfigurationSpi.h>
#include <sun/security/jca/GetInstance$Instance.h>
#include <sun/security/jca/GetInstance.h>
#include <jcpp.h>

using $AppConfigurationEntryArray = $Array<::javax::security::auth::login::AppConfigurationEntry>;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InstantiationException = ::java::lang::InstantiationException;
using $MethodInfo = ::java::lang::MethodInfo;
using $SecurityException = ::java::lang::SecurityException;
using $SecurityManager = ::java::lang::SecurityManager;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $Permission = ::java::security::Permission;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $PrivilegedActionException = ::java::security::PrivilegedActionException;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $Provider = ::java::security::Provider;
using $Objects = ::java::util::Objects;
using $AuthPermission = ::javax::security::auth::AuthPermission;
using $Configuration$1 = ::javax::security::auth::login::Configuration$1;
using $Configuration$2 = ::javax::security::auth::login::Configuration$2;
using $Configuration$3 = ::javax::security::auth::login::Configuration$3;
using $Configuration$ConfigDelegate = ::javax::security::auth::login::Configuration$ConfigDelegate;
using $Configuration$Parameters = ::javax::security::auth::login::Configuration$Parameters;
using $ConfigurationSpi = ::javax::security::auth::login::ConfigurationSpi;
using $GetInstance = ::sun::security::jca::GetInstance;
using $GetInstance$Instance = ::sun::security::jca::GetInstance$Instance;

namespace javax {
	namespace security {
		namespace auth {
			namespace login {

$FieldInfo _Configuration_FieldInfo_[] = {
	{"configuration", "Ljavax/security/auth/login/Configuration;", nullptr, $PRIVATE | $STATIC, $staticField(Configuration, configuration)},
	{"acc", "Ljava/security/AccessControlContext;", nullptr, $PRIVATE | $FINAL, $field(Configuration, acc)},
	{}
};

$MethodInfo _Configuration_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PROTECTED, $method(Configuration, init$, void)},
	{"checkPermission", "(Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Configuration, checkPermission, void, $String*)},
	{"getAppConfigurationEntry", "(Ljava/lang/String;)[Ljavax/security/auth/login/AppConfigurationEntry;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Configuration, getAppConfigurationEntry, $AppConfigurationEntryArray*, $String*)},
	{"getConfiguration", "()Ljavax/security/auth/login/Configuration;", nullptr, $PUBLIC | $STATIC, $staticMethod(Configuration, getConfiguration, Configuration*)},
	{"getInstance", "(Ljava/lang/String;Ljavax/security/auth/login/Configuration$Parameters;)Ljavax/security/auth/login/Configuration;", nullptr, $PUBLIC | $STATIC, $staticMethod(Configuration, getInstance, Configuration*, $String*, $Configuration$Parameters*), "java.security.NoSuchAlgorithmException"},
	{"getInstance", "(Ljava/lang/String;Ljavax/security/auth/login/Configuration$Parameters;Ljava/lang/String;)Ljavax/security/auth/login/Configuration;", nullptr, $PUBLIC | $STATIC, $staticMethod(Configuration, getInstance, Configuration*, $String*, $Configuration$Parameters*, $String*), "java.security.NoSuchProviderException,java.security.NoSuchAlgorithmException"},
	{"getInstance", "(Ljava/lang/String;Ljavax/security/auth/login/Configuration$Parameters;Ljava/security/Provider;)Ljavax/security/auth/login/Configuration;", nullptr, $PUBLIC | $STATIC, $staticMethod(Configuration, getInstance, Configuration*, $String*, $Configuration$Parameters*, $Provider*), "java.security.NoSuchAlgorithmException"},
	{"getParameters", "()Ljavax/security/auth/login/Configuration$Parameters;", nullptr, $PUBLIC, $virtualMethod(Configuration, getParameters, $Configuration$Parameters*)},
	{"getProvider", "()Ljava/security/Provider;", nullptr, $PUBLIC, $virtualMethod(Configuration, getProvider, $Provider*)},
	{"getType", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Configuration, getType, $String*)},
	{"handleException", "(Ljava/security/NoSuchAlgorithmException;)Ljavax/security/auth/login/Configuration;", nullptr, $PRIVATE | $STATIC, $staticMethod(Configuration, handleException, Configuration*, $NoSuchAlgorithmException*), "java.security.NoSuchAlgorithmException"},
	{"refresh", "()V", nullptr, $PUBLIC, $virtualMethod(Configuration, refresh, void)},
	{"setConfiguration", "(Ljavax/security/auth/login/Configuration;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(Configuration, setConfiguration, void, Configuration*)},
	{}
};

$InnerClassInfo _Configuration_InnerClassesInfo_[] = {
	{"javax.security.auth.login.Configuration$Parameters", "javax.security.auth.login.Configuration", "Parameters", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"javax.security.auth.login.Configuration$ConfigDelegate", "javax.security.auth.login.Configuration", "ConfigDelegate", $PRIVATE | $STATIC},
	{"javax.security.auth.login.Configuration$3", nullptr, nullptr, 0},
	{"javax.security.auth.login.Configuration$2", nullptr, nullptr, 0},
	{"javax.security.auth.login.Configuration$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Configuration_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"javax.security.auth.login.Configuration",
	"java.lang.Object",
	nullptr,
	_Configuration_FieldInfo_,
	_Configuration_MethodInfo_,
	nullptr,
	nullptr,
	_Configuration_InnerClassesInfo_,
	nullptr,
	nullptr,
	"javax.security.auth.login.Configuration$Parameters,javax.security.auth.login.Configuration$ConfigDelegate,javax.security.auth.login.Configuration$3,javax.security.auth.login.Configuration$2,javax.security.auth.login.Configuration$1"
};

$Object* allocate$Configuration($Class* clazz) {
	return $of($alloc(Configuration));
}

Configuration* Configuration::configuration = nullptr;

void Configuration::checkPermission($String* type) {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission($$new($AuthPermission, $$str({"createLoginConfiguration."_s, type})));
	}
}

void Configuration::init$() {
	$set(this, acc, $AccessController::getContext());
}

Configuration* Configuration::getConfiguration() {
	$load(Configuration);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission($$new($AuthPermission, "getLoginConfiguration"_s));
	}
	$synchronized(Configuration::class$) {
		$init(Configuration);
		if (Configuration::configuration == nullptr) {
			$var($String, config_class, nullptr);
			$assign(config_class, $cast($String, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($Configuration$1)))));
			if (config_class == nullptr) {
				$assign(config_class, "sun.security.provider.ConfigFile"_s);
			}
			try {
				$var($String, finalClass, config_class);
				$var(Configuration, untrustedImpl, $cast(Configuration, $AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new($Configuration$2, finalClass)))));
				$var($PrivilegedExceptionAction, var$0, static_cast<$PrivilegedExceptionAction*>($new($Configuration$3, untrustedImpl)));
				$AccessController::doPrivileged(var$0, $cast($AccessControlContext, $Objects::requireNonNull($nc(untrustedImpl)->acc)));
			} catch ($PrivilegedActionException& e) {
				$var($Exception, ee, e->getException());
				if ($instanceOf($InstantiationException, ee)) {
					$throw($cast($SecurityException, $($$new($SecurityException, $$str({"Configuration error:"_s, $($nc($($nc(ee)->getCause()))->getMessage()), "\n"_s}))->initCause($($nc(ee)->getCause())))));
				} else {
					$throw($cast($SecurityException, $($$new($SecurityException, $$str({"Configuration error: "_s, $($nc(ee)->toString()), "\n"_s}))->initCause(ee))));
				}
			}
		}
		return Configuration::configuration;
	}
}

void Configuration::setConfiguration(Configuration* configuration) {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission($$new($AuthPermission, "setLoginConfiguration"_s));
	}
	$init(Configuration);
	$assignStatic(Configuration::configuration, configuration);
}

Configuration* Configuration::getInstance($String* type, $Configuration$Parameters* params) {
	$Objects::requireNonNull($of(type), "null type name"_s);
	checkPermission(type);
	try {
		$load($ConfigurationSpi);
		$var($GetInstance$Instance, instance, $GetInstance::getInstance("Configuration"_s, $ConfigurationSpi::class$, type, $of(params)));
		return $new($Configuration$ConfigDelegate, $cast($ConfigurationSpi, $nc(instance)->impl), instance->provider, type, params);
	} catch ($NoSuchAlgorithmException& nsae) {
		return handleException(nsae);
	}
	$shouldNotReachHere();
}

Configuration* Configuration::getInstance($String* type, $Configuration$Parameters* params, $String* provider) {
	$Objects::requireNonNull($of(type), "null type name"_s);
	if (provider == nullptr || $nc(provider)->isEmpty()) {
		$throwNew($IllegalArgumentException, "missing provider"_s);
	}
	checkPermission(type);
	try {
		$load($ConfigurationSpi);
		$var($GetInstance$Instance, instance, $GetInstance::getInstance("Configuration"_s, $ConfigurationSpi::class$, type, $of(params), provider));
		return $new($Configuration$ConfigDelegate, $cast($ConfigurationSpi, $nc(instance)->impl), instance->provider, type, params);
	} catch ($NoSuchAlgorithmException& nsae) {
		return handleException(nsae);
	}
	$shouldNotReachHere();
}

Configuration* Configuration::getInstance($String* type, $Configuration$Parameters* params, $Provider* provider) {
	$Objects::requireNonNull($of(type), "null type name"_s);
	if (provider == nullptr) {
		$throwNew($IllegalArgumentException, "missing provider"_s);
	}
	checkPermission(type);
	try {
		$load($ConfigurationSpi);
		$var($GetInstance$Instance, instance, $GetInstance::getInstance("Configuration"_s, $ConfigurationSpi::class$, type, $of(params), provider));
		return $new($Configuration$ConfigDelegate, $cast($ConfigurationSpi, $nc(instance)->impl), instance->provider, type, params);
	} catch ($NoSuchAlgorithmException& nsae) {
		return handleException(nsae);
	}
	$shouldNotReachHere();
}

Configuration* Configuration::handleException($NoSuchAlgorithmException* nsae) {
	$var($Throwable, cause, $nc(nsae)->getCause());
	if ($instanceOf($IllegalArgumentException, cause)) {
		$throw($cast($IllegalArgumentException, cause));
	}
	$throw(nsae);
	$shouldNotReachHere();
}

$Provider* Configuration::getProvider() {
	return nullptr;
}

$String* Configuration::getType() {
	return nullptr;
}

$Configuration$Parameters* Configuration::getParameters() {
	return nullptr;
}

void Configuration::refresh() {
}

Configuration::Configuration() {
}

$Class* Configuration::load$($String* name, bool initialize) {
	$loadClass(Configuration, name, initialize, &_Configuration_ClassInfo_, allocate$Configuration);
	return class$;
}

$Class* Configuration::class$ = nullptr;

			} // login
		} // auth
	} // security
} // javax