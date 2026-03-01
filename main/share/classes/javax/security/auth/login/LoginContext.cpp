#include <javax/security/auth/login/LoginContext.h>

#include <java/io/PrintWriter.h>
#include <java/io/Serializable.h>
#include <java/io/StringWriter.h>
#include <java/io/Writer.h>
#include <java/lang/AssertionError.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/SecurityException.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/PrivilegedActionException.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/text/MessageFormat.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/Map.h>
#include <java/util/ServiceLoader.h>
#include <javax/security/auth/AuthPermission.h>
#include <javax/security/auth/Subject.h>
#include <javax/security/auth/callback/CallbackHandler.h>
#include <javax/security/auth/login/AppConfigurationEntry$LoginModuleControlFlag.h>
#include <javax/security/auth/login/AppConfigurationEntry.h>
#include <javax/security/auth/login/Configuration.h>
#include <javax/security/auth/login/LoginContext$1.h>
#include <javax/security/auth/login/LoginContext$2.h>
#include <javax/security/auth/login/LoginContext$3.h>
#include <javax/security/auth/login/LoginContext$4.h>
#include <javax/security/auth/login/LoginContext$ModuleInfo.h>
#include <javax/security/auth/login/LoginContext$SecureCallbackHandler.h>
#include <javax/security/auth/login/LoginException.h>
#include <javax/security/auth/spi/LoginModule.h>
#include <sun/security/util/Debug.h>
#include <sun/security/util/PendingException.h>
#include <sun/security/util/ResourcesMgr.h>
#include <jcpp.h>

#undef ABORT_METHOD
#undef COMMIT_METHOD
#undef DEFAULT_HANDLER
#undef LOGIN_METHOD
#undef LOGOUT_METHOD
#undef OTHER
#undef REQUIRED
#undef REQUISITE
#undef SUFFICIENT

using $AppConfigurationEntryArray = $Array<::javax::security::auth::login::AppConfigurationEntry>;
using $LoginContext$ModuleInfoArray = $Array<::javax::security::auth::login::LoginContext$ModuleInfo>;
using $PrintWriter = ::java::io::PrintWriter;
using $Serializable = ::java::io::Serializable;
using $StringWriter = ::java::io::StringWriter;
using $Writer = ::java::io::Writer;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $SecurityException = ::java::lang::SecurityException;
using $SecurityManager = ::java::lang::SecurityManager;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $AccessController = ::java::security::AccessController;
using $Permission = ::java::security::Permission;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $PrivilegedActionException = ::java::security::PrivilegedActionException;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $MessageFormat = ::java::text::MessageFormat;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $Map = ::java::util::Map;
using $ServiceLoader = ::java::util::ServiceLoader;
using $AuthPermission = ::javax::security::auth::AuthPermission;
using $Subject = ::javax::security::auth::Subject;
using $CallbackHandler = ::javax::security::auth::callback::CallbackHandler;
using $AppConfigurationEntry = ::javax::security::auth::login::AppConfigurationEntry;
using $AppConfigurationEntry$LoginModuleControlFlag = ::javax::security::auth::login::AppConfigurationEntry$LoginModuleControlFlag;
using $Configuration = ::javax::security::auth::login::Configuration;
using $LoginContext$1 = ::javax::security::auth::login::LoginContext$1;
using $LoginContext$2 = ::javax::security::auth::login::LoginContext$2;
using $LoginContext$3 = ::javax::security::auth::login::LoginContext$3;
using $LoginContext$4 = ::javax::security::auth::login::LoginContext$4;
using $LoginContext$ModuleInfo = ::javax::security::auth::login::LoginContext$ModuleInfo;
using $LoginContext$SecureCallbackHandler = ::javax::security::auth::login::LoginContext$SecureCallbackHandler;
using $LoginException = ::javax::security::auth::login::LoginException;
using $LoginModule = ::javax::security::auth::spi::LoginModule;
using $Debug = ::sun::security::util::Debug;
using $PendingException = ::sun::security::util::PendingException;
using $ResourcesMgr = ::sun::security::util::ResourcesMgr;

namespace javax {
	namespace security {
		namespace auth {
			namespace login {

class LoginContext$$Lambda$lambda$invoke$0 : public $PrivilegedAction {
	$class(LoginContext$$Lambda$lambda$invoke$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$(LoginContext* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* run() override {
		 return $of($nc(inst$)->lambda$invoke$0());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LoginContext$$Lambda$lambda$invoke$0>());
	}
	LoginContext* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo LoginContext$$Lambda$lambda$invoke$0::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(LoginContext$$Lambda$lambda$invoke$0, inst$)},
	{}
};
$MethodInfo LoginContext$$Lambda$lambda$invoke$0::methodInfos[3] = {
	{"<init>", "(Ljavax/security/auth/login/LoginContext;)V", nullptr, $PUBLIC, $method(LoginContext$$Lambda$lambda$invoke$0, init$, void, LoginContext*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(LoginContext$$Lambda$lambda$invoke$0, run, $Object*)},
	{}
};
$ClassInfo LoginContext$$Lambda$lambda$invoke$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"javax.security.auth.login.LoginContext$$Lambda$lambda$invoke$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* LoginContext$$Lambda$lambda$invoke$0::load$($String* name, bool initialize) {
	$loadClass(LoginContext$$Lambda$lambda$invoke$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LoginContext$$Lambda$lambda$invoke$0::class$ = nullptr;

$FieldInfo _LoginContext_FieldInfo_[] = {
	{"LOGIN_METHOD", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LoginContext, LOGIN_METHOD)},
	{"COMMIT_METHOD", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LoginContext, COMMIT_METHOD)},
	{"ABORT_METHOD", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LoginContext, ABORT_METHOD)},
	{"LOGOUT_METHOD", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LoginContext, LOGOUT_METHOD)},
	{"OTHER", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LoginContext, OTHER)},
	{"DEFAULT_HANDLER", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LoginContext, DEFAULT_HANDLER)},
	{"subject", "Ljavax/security/auth/Subject;", nullptr, $PRIVATE, $field(LoginContext, subject)},
	{"subjectProvided", "Z", nullptr, $PRIVATE, $field(LoginContext, subjectProvided)},
	{"loginSucceeded", "Z", nullptr, $PRIVATE, $field(LoginContext, loginSucceeded)},
	{"callbackHandler", "Ljavax/security/auth/callback/CallbackHandler;", nullptr, $PRIVATE, $field(LoginContext, callbackHandler)},
	{"state", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;*>;", $PRIVATE, $field(LoginContext, state)},
	{"config", "Ljavax/security/auth/login/Configuration;", nullptr, $PRIVATE, $field(LoginContext, config)},
	{"creatorAcc", "Ljava/security/AccessControlContext;", nullptr, $PRIVATE, $field(LoginContext, creatorAcc)},
	{"moduleStack", "[Ljavax/security/auth/login/LoginContext$ModuleInfo;", nullptr, $PRIVATE, $field(LoginContext, moduleStack)},
	{"contextClassLoader", "Ljava/lang/ClassLoader;", nullptr, $PRIVATE, $field(LoginContext, contextClassLoader)},
	{"moduleIndex", "I", nullptr, $PRIVATE, $field(LoginContext, moduleIndex)},
	{"firstError", "Ljavax/security/auth/login/LoginException;", nullptr, $PRIVATE, $field(LoginContext, firstError)},
	{"firstRequiredError", "Ljavax/security/auth/login/LoginException;", nullptr, $PRIVATE, $field(LoginContext, firstRequiredError)},
	{"success", "Z", nullptr, $PRIVATE, $field(LoginContext, success)},
	{"debug", "Lsun/security/util/Debug;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LoginContext, debug)},
	{}
};

$MethodInfo _LoginContext_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(LoginContext, init$, void, $String*), "javax.security.auth.login.LoginException"},
	{"<init>", "(Ljava/lang/String;Ljavax/security/auth/Subject;)V", nullptr, $PUBLIC, $method(LoginContext, init$, void, $String*, $Subject*), "javax.security.auth.login.LoginException"},
	{"<init>", "(Ljava/lang/String;Ljavax/security/auth/callback/CallbackHandler;)V", nullptr, $PUBLIC, $method(LoginContext, init$, void, $String*, $CallbackHandler*), "javax.security.auth.login.LoginException"},
	{"<init>", "(Ljava/lang/String;Ljavax/security/auth/Subject;Ljavax/security/auth/callback/CallbackHandler;)V", nullptr, $PUBLIC, $method(LoginContext, init$, void, $String*, $Subject*, $CallbackHandler*), "javax.security.auth.login.LoginException"},
	{"<init>", "(Ljava/lang/String;Ljavax/security/auth/Subject;Ljavax/security/auth/callback/CallbackHandler;Ljavax/security/auth/login/Configuration;)V", nullptr, $PUBLIC, $method(LoginContext, init$, void, $String*, $Subject*, $CallbackHandler*, $Configuration*), "javax.security.auth.login.LoginException"},
	{"clearState", "()V", nullptr, $PRIVATE, $method(LoginContext, clearState, void)},
	{"getSubject", "()Ljavax/security/auth/Subject;", nullptr, $PUBLIC, $virtualMethod(LoginContext, getSubject, $Subject*)},
	{"init", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(LoginContext, init, void, $String*), "javax.security.auth.login.LoginException"},
	{"invoke", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(LoginContext, invoke, void, $String*), "javax.security.auth.login.LoginException"},
	{"invokePriv", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(LoginContext, invokePriv, void, $String*), "javax.security.auth.login.LoginException"},
	{"lambda$invoke$0", "()Ljava/util/ServiceLoader;", nullptr, $PRIVATE | $SYNTHETIC, $method(LoginContext, lambda$invoke$0, $ServiceLoader*)},
	{"loadDefaultCallbackHandler", "()V", nullptr, $PRIVATE, $method(LoginContext, loadDefaultCallbackHandler, void), "javax.security.auth.login.LoginException"},
	{"login", "()V", nullptr, $PUBLIC, $virtualMethod(LoginContext, login, void), "javax.security.auth.login.LoginException"},
	{"logout", "()V", nullptr, $PUBLIC, $virtualMethod(LoginContext, logout, void), "javax.security.auth.login.LoginException"},
	{"throwException", "(Ljavax/security/auth/login/LoginException;Ljavax/security/auth/login/LoginException;)V", nullptr, $PRIVATE, $method(LoginContext, throwException, void, $LoginException*, $LoginException*), "javax.security.auth.login.LoginException"},
	{}
};

$InnerClassInfo _LoginContext_InnerClassesInfo_[] = {
	{"javax.security.auth.login.LoginContext$ModuleInfo", "javax.security.auth.login.LoginContext", "ModuleInfo", $PRIVATE | $STATIC},
	{"javax.security.auth.login.LoginContext$SecureCallbackHandler", "javax.security.auth.login.LoginContext", "SecureCallbackHandler", $PRIVATE | $STATIC},
	{"javax.security.auth.login.LoginContext$4", nullptr, nullptr, 0},
	{"javax.security.auth.login.LoginContext$3", nullptr, nullptr, 0},
	{"javax.security.auth.login.LoginContext$2", nullptr, nullptr, 0},
	{"javax.security.auth.login.LoginContext$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _LoginContext_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"javax.security.auth.login.LoginContext",
	"java.lang.Object",
	nullptr,
	_LoginContext_FieldInfo_,
	_LoginContext_MethodInfo_,
	nullptr,
	nullptr,
	_LoginContext_InnerClassesInfo_,
	nullptr,
	nullptr,
	"javax.security.auth.login.LoginContext$ModuleInfo,javax.security.auth.login.LoginContext$SecureCallbackHandler,javax.security.auth.login.LoginContext$SecureCallbackHandler$1,javax.security.auth.login.LoginContext$4,javax.security.auth.login.LoginContext$3,javax.security.auth.login.LoginContext$2,javax.security.auth.login.LoginContext$1"
};

$Object* allocate$LoginContext($Class* clazz) {
	return $of($alloc(LoginContext));
}

$String* LoginContext::LOGIN_METHOD = nullptr;
$String* LoginContext::COMMIT_METHOD = nullptr;
$String* LoginContext::ABORT_METHOD = nullptr;
$String* LoginContext::LOGOUT_METHOD = nullptr;
$String* LoginContext::OTHER = nullptr;
$String* LoginContext::DEFAULT_HANDLER = nullptr;
$Debug* LoginContext::debug = nullptr;

void LoginContext::init($String* name) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr && this->creatorAcc == nullptr) {
		sm->checkPermission($$new($AuthPermission, $$str({"createLoginContext."_s, name})));
	}
	if (name == nullptr) {
		$throwNew($LoginException, $($ResourcesMgr::getString("Invalid.null.input.name"_s)));
	}
	if (this->config == nullptr) {
		$set(this, config, $cast($Configuration, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($LoginContext$1, this)))));
	}
	$var($AppConfigurationEntryArray, entries, $nc(this->config)->getAppConfigurationEntry(name));
	if (entries == nullptr) {
		if (sm != nullptr && this->creatorAcc == nullptr) {
			sm->checkPermission($$new($AuthPermission, $$str({"createLoginContext."_s, LoginContext::OTHER})));
		}
		$assign(entries, $nc(this->config)->getAppConfigurationEntry(LoginContext::OTHER));
		if (entries == nullptr) {
			$var($MessageFormat, form, $new($MessageFormat, $($ResourcesMgr::getString("No.LoginModules.configured.for.name"_s))));
			$var($ObjectArray, source, $new($ObjectArray, {$of(name)}));
			$throwNew($LoginException, $(form->format(source)));
		}
	}
	$set(this, moduleStack, $new($LoginContext$ModuleInfoArray, $nc(entries)->length));
	for (int32_t i = 0; i < entries->length; ++i) {
		$var($String, var$0, $nc(entries->get(i))->getLoginModuleName());
		$var($AppConfigurationEntry$LoginModuleControlFlag, var$1, $nc(entries->get(i))->getControlFlag());
		$nc(this->moduleStack)->set(i, $$new($LoginContext$ModuleInfo, $$new($AppConfigurationEntry, var$0, var$1, $($nc(entries->get(i))->getOptions())), nullptr));
	}
	$set(this, contextClassLoader, $cast($ClassLoader, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($LoginContext$2, this)))));
}

void LoginContext::loadDefaultCallbackHandler() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	try {
		$var($ClassLoader, finalLoader, this->contextClassLoader);
		$set(this, callbackHandler, $cast($CallbackHandler, $AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new($LoginContext$3, this, finalLoader)))));
	} catch ($PrivilegedActionException& pae) {
		$throwNew($LoginException, $($nc($(pae->getException()))->toString()));
	}
	if (this->callbackHandler != nullptr && this->creatorAcc == nullptr) {
		$set(this, callbackHandler, $new($LoginContext$SecureCallbackHandler, $($AccessController::getContext()), this->callbackHandler));
	}
}

void LoginContext::init$($String* name) {
	$set(this, subject, nullptr);
	this->subjectProvided = false;
	this->loginSucceeded = false;
	$set(this, state, $new($HashMap));
	$set(this, creatorAcc, nullptr);
	$set(this, contextClassLoader, nullptr);
	this->moduleIndex = 0;
	$set(this, firstError, nullptr);
	$set(this, firstRequiredError, nullptr);
	this->success = false;
	init(name);
	loadDefaultCallbackHandler();
}

void LoginContext::init$($String* name, $Subject* subject) {
	$set(this, subject, nullptr);
	this->subjectProvided = false;
	this->loginSucceeded = false;
	$set(this, state, $new($HashMap));
	$set(this, creatorAcc, nullptr);
	$set(this, contextClassLoader, nullptr);
	this->moduleIndex = 0;
	$set(this, firstError, nullptr);
	$set(this, firstRequiredError, nullptr);
	this->success = false;
	init(name);
	if (subject == nullptr) {
		$throwNew($LoginException, $($ResourcesMgr::getString("invalid.null.Subject.provided"_s)));
	}
	$set(this, subject, subject);
	this->subjectProvided = true;
	loadDefaultCallbackHandler();
}

void LoginContext::init$($String* name, $CallbackHandler* callbackHandler) {
	$useLocalCurrentObjectStackCache();
	$set(this, subject, nullptr);
	this->subjectProvided = false;
	this->loginSucceeded = false;
	$set(this, state, $new($HashMap));
	$set(this, creatorAcc, nullptr);
	$set(this, contextClassLoader, nullptr);
	this->moduleIndex = 0;
	$set(this, firstError, nullptr);
	$set(this, firstRequiredError, nullptr);
	this->success = false;
	init(name);
	if (callbackHandler == nullptr) {
		$throwNew($LoginException, $($ResourcesMgr::getString("invalid.null.CallbackHandler.provided"_s)));
	}
	$set(this, callbackHandler, $new($LoginContext$SecureCallbackHandler, $($AccessController::getContext()), callbackHandler));
}

void LoginContext::init$($String* name, $Subject* subject, $CallbackHandler* callbackHandler) {
	$useLocalCurrentObjectStackCache();
	LoginContext::init$(name, subject);
	if (callbackHandler == nullptr) {
		$throwNew($LoginException, $($ResourcesMgr::getString("invalid.null.CallbackHandler.provided"_s)));
	}
	$set(this, callbackHandler, $new($LoginContext$SecureCallbackHandler, $($AccessController::getContext()), callbackHandler));
}

void LoginContext::init$($String* name, $Subject* subject, $CallbackHandler* callbackHandler, $Configuration* config) {
	$set(this, subject, nullptr);
	this->subjectProvided = false;
	this->loginSucceeded = false;
	$set(this, state, $new($HashMap));
	$set(this, creatorAcc, nullptr);
	$set(this, contextClassLoader, nullptr);
	this->moduleIndex = 0;
	$set(this, firstError, nullptr);
	$set(this, firstRequiredError, nullptr);
	this->success = false;
	$set(this, config, config);
	if (config != nullptr) {
		$set(this, creatorAcc, $AccessController::getContext());
	}
	init(name);
	if (subject != nullptr) {
		$set(this, subject, subject);
		this->subjectProvided = true;
	}
	if (callbackHandler == nullptr) {
		loadDefaultCallbackHandler();
	} else if (this->creatorAcc == nullptr) {
		$set(this, callbackHandler, $new($LoginContext$SecureCallbackHandler, $($AccessController::getContext()), callbackHandler));
	} else {
		$set(this, callbackHandler, callbackHandler);
	}
}

void LoginContext::login() {
	this->loginSucceeded = false;
	if (this->subject == nullptr) {
		$set(this, subject, $new($Subject));
	}
	try {
		invokePriv(LoginContext::LOGIN_METHOD);
		invokePriv(LoginContext::COMMIT_METHOD);
		this->loginSucceeded = true;
	} catch ($LoginException& le) {
		try {
			invokePriv(LoginContext::ABORT_METHOD);
		} catch ($LoginException& le2) {
			$throw(le);
		}
		$throw(le);
	}
}

void LoginContext::logout() {
	if (this->subject == nullptr) {
		$throwNew($LoginException, $($ResourcesMgr::getString("null.subject.logout.called.before.login"_s)));
	}
	invokePriv(LoginContext::LOGOUT_METHOD);
}

$Subject* LoginContext::getSubject() {
	if (!this->loginSucceeded && !this->subjectProvided) {
		return nullptr;
	}
	return this->subject;
}

void LoginContext::clearState() {
	this->moduleIndex = 0;
	$set(this, firstError, nullptr);
	$set(this, firstRequiredError, nullptr);
	this->success = false;
}

void LoginContext::throwException($LoginException* originalError, $LoginException* le) {
	clearState();
	$var($LoginException, error, (originalError != nullptr) ? originalError : le);
	$throw(error);
}

void LoginContext::invokePriv($String* methodName) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	try {
		$AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new($LoginContext$4, this, methodName)), this->creatorAcc);
	} catch ($PrivilegedActionException& pae) {
		$throw($cast($LoginException, $(pae->getException())));
	}
}

void LoginContext::invoke($String* methodName) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	for (int32_t i = this->moduleIndex; i < $nc(this->moduleStack)->length; ++i, ++this->moduleIndex) {
		try {
			if ($nc($nc(this->moduleStack)->get(i))->module == nullptr) {
				$var($String, name, $nc($nc($nc(this->moduleStack)->get(i))->entry)->getLoginModuleName());
				$var($ServiceLoader, sc, $cast($ServiceLoader, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(LoginContext$$Lambda$lambda$invoke$0, this)))));
				{
					$var($Iterator, i$, $nc(sc)->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($LoginModule, m, $cast($LoginModule, i$->next()));
						{
							if ($nc($($nc($of(m))->getClass()->getName()))->equals(name)) {
								$set($nc($nc(this->moduleStack)->get(i)), module, m);
								if (LoginContext::debug != nullptr) {
									$nc(LoginContext::debug)->println($$str({name, " loaded as a service"_s}));
								}
								break;
							}
						}
					}
				}
				if ($nc($nc(this->moduleStack)->get(i))->module == nullptr) {
					try {
						$var($Object, tmp, $Class::forName(name, false, this->contextClassLoader)->newInstance());
						$set($nc($nc(this->moduleStack)->get(i)), module, $cast($LoginModule, tmp));
						if (LoginContext::debug != nullptr) {
							$nc(LoginContext::debug)->println($$str({name, " loaded via reflection"_s}));
						}
					} catch ($ClassNotFoundException& e) {
						$throwNew($LoginException, $$str({"No LoginModule found for "_s, name}));
					}
				}
				$nc($nc($nc(this->moduleStack)->get(i))->module)->initialize(this->subject, this->callbackHandler, this->state, $($nc($nc($nc(this->moduleStack)->get(i))->entry)->getOptions()));
			}
			bool status = false;
			{
				$var($String, s31050$, methodName);
				int32_t tmp31050$ = -1;
				switch ($nc(s31050$)->hashCode()) {
				case 0x0625EF69:
					{
						if (s31050$->equals("login"_s)) {
							tmp31050$ = 0;
						}
						break;
					}
				case (int32_t)0xAF3F2937:
					{
						if (s31050$->equals("commit"_s)) {
							tmp31050$ = 1;
						}
						break;
					}
				case (int32_t)0xBE98158A:
					{
						if (s31050$->equals("logout"_s)) {
							tmp31050$ = 2;
						}
						break;
					}
				case 0x05852330:
					{
						if (s31050$->equals("abort"_s)) {
							tmp31050$ = 3;
						}
						break;
					}
				}
				switch (tmp31050$) {
				case 0:
					{
						status = $nc($nc($nc(this->moduleStack)->get(i))->module)->login();
						break;
					}
				case 1:
					{
						status = $nc($nc($nc(this->moduleStack)->get(i))->module)->commit();
						break;
					}
				case 2:
					{
						status = $nc($nc($nc(this->moduleStack)->get(i))->module)->logout();
						break;
					}
				case 3:
					{
						status = $nc($nc($nc(this->moduleStack)->get(i))->module)->abort();
						break;
					}
				default:
					{
						$throwNew($AssertionError, $of($$str({"Unknown method "_s, methodName})));
					}
				}
			}
			if (status == true) {
				bool var$1 = !$nc(methodName)->equals(LoginContext::ABORT_METHOD);
				bool var$0 = var$1 && !methodName->equals(LoginContext::LOGOUT_METHOD);
				$init($AppConfigurationEntry$LoginModuleControlFlag);
				if (var$0 && $nc($nc($nc(this->moduleStack)->get(i))->entry)->getControlFlag() == $AppConfigurationEntry$LoginModuleControlFlag::SUFFICIENT && this->firstRequiredError == nullptr) {
					clearState();
					if (LoginContext::debug != nullptr) {
						$nc(LoginContext::debug)->println($$str({methodName, " SUFFICIENT success"_s}));
					}
					return;
				}
				if (LoginContext::debug != nullptr) {
					$nc(LoginContext::debug)->println($$str({methodName, " success"_s}));
				}
				this->success = true;
			} else if (LoginContext::debug != nullptr) {
				$nc(LoginContext::debug)->println($$str({methodName, " ignored"_s}));
			}
		} catch ($Exception& ite) {
			$var($LoginException, le, nullptr);
			if ($instanceOf($PendingException, ite) && $nc(methodName)->equals(LoginContext::LOGIN_METHOD)) {
				$throw($cast($PendingException, ite));
			} else if ($instanceOf($LoginException, ite)) {
				$assign(le, $cast($LoginException, ite));
			} else if ($instanceOf($SecurityException, ite)) {
				$assign(le, $new($LoginException, "Security Exception"_s));
				le->initCause($$new($SecurityException));
				if (LoginContext::debug != nullptr) {
					$nc(LoginContext::debug)->println("original security exception with detail msg replaced by new exception with empty detail msg"_s);
					$nc(LoginContext::debug)->println($$str({"original security exception: "_s, $(ite->toString())}));
				}
			} else {
				$var($StringWriter, sw, $new($StringWriter));
				ite->printStackTrace($$new($PrintWriter, static_cast<$Writer*>(sw)));
				sw->flush();
				$assign(le, $new($LoginException, $(sw->toString())));
			}
			$init($AppConfigurationEntry$LoginModuleControlFlag);
			if ($nc($nc($nc(this->moduleStack)->get(i))->entry)->getControlFlag() == $AppConfigurationEntry$LoginModuleControlFlag::REQUISITE) {
				if (LoginContext::debug != nullptr) {
					$nc(LoginContext::debug)->println($$str({methodName, " REQUISITE failure"_s}));
				}
				bool var$2 = $nc(methodName)->equals(LoginContext::ABORT_METHOD);
				if (var$2 || $nc(methodName)->equals(LoginContext::LOGOUT_METHOD)) {
					if (this->firstRequiredError == nullptr) {
						$set(this, firstRequiredError, le);
					}
				} else {
					throwException(this->firstRequiredError, le);
				}
			} else {
				if ($nc($nc($nc(this->moduleStack)->get(i))->entry)->getControlFlag() == $AppConfigurationEntry$LoginModuleControlFlag::REQUIRED) {
					if (LoginContext::debug != nullptr) {
						$nc(LoginContext::debug)->println($$str({methodName, " REQUIRED failure"_s}));
					}
					if (this->firstRequiredError == nullptr) {
						$set(this, firstRequiredError, le);
					}
				} else {
					if (LoginContext::debug != nullptr) {
						$nc(LoginContext::debug)->println($$str({methodName, " OPTIONAL failure"_s}));
					}
					if (this->firstError == nullptr) {
						$set(this, firstError, le);
					}
				}
			}
		}
	}
	if (this->firstRequiredError != nullptr) {
		throwException(this->firstRequiredError, nullptr);
	} else if (this->success == false && this->firstError != nullptr) {
		throwException(this->firstError, nullptr);
	} else if (this->success == false) {
		throwException($$new($LoginException, $($ResourcesMgr::getString("Login.Failure.all.modules.ignored"_s))), nullptr);
	} else {
		clearState();
		return;
	}
}

$ServiceLoader* LoginContext::lambda$invoke$0() {
	$beforeCallerSensitive();
	$load($LoginModule);
	return $ServiceLoader::load($LoginModule::class$, this->contextClassLoader);
}

void clinit$LoginContext($Class* class$) {
	$assignStatic(LoginContext::LOGIN_METHOD, "login"_s);
	$assignStatic(LoginContext::COMMIT_METHOD, "commit"_s);
	$assignStatic(LoginContext::ABORT_METHOD, "abort"_s);
	$assignStatic(LoginContext::LOGOUT_METHOD, "logout"_s);
	$assignStatic(LoginContext::OTHER, "other"_s);
	$assignStatic(LoginContext::DEFAULT_HANDLER, "auth.login.defaultCallbackHandler"_s);
	$assignStatic(LoginContext::debug, $Debug::getInstance("logincontext"_s, "\t[LoginContext]"_s));
}

LoginContext::LoginContext() {
}

$Class* LoginContext::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(LoginContext$$Lambda$lambda$invoke$0::classInfo$.name)) {
			return LoginContext$$Lambda$lambda$invoke$0::load$(name, initialize);
		}
	}
	$loadClass(LoginContext, name, initialize, &_LoginContext_ClassInfo_, clinit$LoginContext, allocate$LoginContext);
	return class$;
}

$Class* LoginContext::class$ = nullptr;

			} // login
		} // auth
	} // security
} // javax