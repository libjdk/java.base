#include <SecurityManagerClinit.h>

#include <SecurityManagerClinit$SimplePolicy.h>
#include <java/io/File.h>
#include <java/io/FilePermission.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/lang/Process.h>
#include <java/lang/Runtime.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityManager.h>
#include <java/security/Permission.h>
#include <java/security/Policy.h>
#include <jcpp.h>

using $SecurityManagerClinit$SimplePolicy = ::SecurityManagerClinit$SimplePolicy;
using $PermissionArray = $Array<::java::security::Permission>;
using $File = ::java::io::File;
using $FilePermission = ::java::io::FilePermission;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Process = ::java::lang::Process;
using $Runtime = ::java::lang::Runtime;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityManager = ::java::lang::SecurityManager;
using $Permission = ::java::security::Permission;
using $Policy = ::java::security::Policy;

$MethodInfo _SecurityManagerClinit_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(SecurityManagerClinit, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(SecurityManagerClinit, main, void, $StringArray*), "java.lang.Throwable"},
	{}
};

$InnerClassInfo _SecurityManagerClinit_InnerClassesInfo_[] = {
	{"SecurityManagerClinit$SimplePolicy", "SecurityManagerClinit", "SimplePolicy", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _SecurityManagerClinit_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"SecurityManagerClinit",
	"java.lang.Object",
	nullptr,
	nullptr,
	_SecurityManagerClinit_MethodInfo_,
	nullptr,
	nullptr,
	_SecurityManagerClinit_InnerClassesInfo_,
	nullptr,
	nullptr,
	"SecurityManagerClinit$SimplePolicy"
};

$Object* allocate$SecurityManagerClinit($Class* clazz) {
	return $of($alloc(SecurityManagerClinit));
}

void SecurityManagerClinit::init$() {
}

void SecurityManagerClinit::main($StringArray* args) {
	$load(SecurityManagerClinit);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$init($File);
	$var($String, javaExe, $str({$($System::getProperty("java.home"_s)), $File::separator, "bin"_s, $File::separator, "java"_s}));
	$var($SecurityManagerClinit$SimplePolicy, policy, $new($SecurityManagerClinit$SimplePolicy, $$new($PermissionArray, {
		static_cast<$Permission*>($$new($FilePermission, "<<ALL FILES>>"_s, "execute"_s)),
		static_cast<$Permission*>($$new($RuntimePermission, "setSecurityManager"_s))
	})));
	$Policy::setPolicy(policy);
	$System::setSecurityManager($$new($SecurityManager));
	{
		$var($Throwable, var$0, nullptr);
		try {
			$var($StringArray, cmd, $new($StringArray, {
				javaExe,
				"-version"_s
			}));
			$var($Process, p, $nc($($Runtime::getRuntime()))->exec(cmd));
			$nc($($nc(p)->getOutputStream()))->close();
			$nc($(p->getInputStream()))->close();
			$nc($(p->getErrorStream()))->close();
			p->waitFor();
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$System::setSecurityManager(nullptr);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

SecurityManagerClinit::SecurityManagerClinit() {
}

$Class* SecurityManagerClinit::load$($String* name, bool initialize) {
	$loadClass(SecurityManagerClinit, name, initialize, &_SecurityManagerClinit_ClassInfo_, allocate$SecurityManagerClinit);
	return class$;
}

$Class* SecurityManagerClinit::class$ = nullptr;