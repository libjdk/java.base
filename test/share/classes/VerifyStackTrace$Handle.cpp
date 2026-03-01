#include <VerifyStackTrace$Handle.h>

#include <VerifyStackTrace.h>
#include <java/lang/Error.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/NoSuchMethodException.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/Runnable.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/MethodType.h>
#include <jcpp.h>

#undef TYPE

using $ClassInfo = ::java::lang::ClassInfo;
using $Error = ::java::lang::Error;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NoSuchMethodException = ::java::lang::NoSuchMethodException;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $Runnable = ::java::lang::Runnable;
using $RuntimeException = ::java::lang::RuntimeException;
using $Void = ::java::lang::Void;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;

$FieldInfo _VerifyStackTrace$Handle_FieldInfo_[] = {
	{"impl", "Ljava/lang/Runnable;", nullptr, 0, $field(VerifyStackTrace$Handle, impl)},
	{}
};

$MethodInfo _VerifyStackTrace$Handle_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/Runnable;)V", nullptr, $PUBLIC, $method(VerifyStackTrace$Handle, init$, void, $Runnable*)},
	{"execute", "(Ljava/lang/Runnable;)V", nullptr, $PUBLIC, $virtualMethod(VerifyStackTrace$Handle, execute, void, $Runnable*)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(VerifyStackTrace$Handle, run, void)},
	{}
};

$InnerClassInfo _VerifyStackTrace$Handle_InnerClassesInfo_[] = {
	{"VerifyStackTrace$Handle", "VerifyStackTrace", "Handle", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _VerifyStackTrace$Handle_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"VerifyStackTrace$Handle",
	"java.lang.Object",
	"java.lang.Runnable",
	_VerifyStackTrace$Handle_FieldInfo_,
	_VerifyStackTrace$Handle_MethodInfo_,
	nullptr,
	nullptr,
	_VerifyStackTrace$Handle_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"VerifyStackTrace"
};

$Object* allocate$VerifyStackTrace$Handle($Class* clazz) {
	return $of($alloc(VerifyStackTrace$Handle));
}

void VerifyStackTrace$Handle::init$($Runnable* run) {
	$set(this, impl, run);
}

void VerifyStackTrace$Handle::execute($Runnable* run) {
	$nc(run)->run();
}

void VerifyStackTrace$Handle::run() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($MethodHandles$Lookup, lookup, $MethodHandles::lookup());
	$var($MethodHandle, handle, nullptr);
	try {
		$init($Void);
		$assign(handle, $nc(lookup)->findVirtual(VerifyStackTrace$Handle::class$, "execute"_s, $($MethodType::methodType($Void::TYPE, $Runnable::class$))));
	} catch ($NoSuchMethodException& x) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(x));
	} catch ($IllegalAccessException& x) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(x));
	}
	try {
		$nc(handle)->invoke($$new($ObjectArray, {$of(this), $of(this->impl)}));
	} catch ($Error& x) {
		$throw(x);
	} catch ($RuntimeException& x) {
		$throw(x);
	} catch ($Throwable& t) {
		$throwNew($RuntimeException, $cast($Throwable, t));
	}
}

VerifyStackTrace$Handle::VerifyStackTrace$Handle() {
}

$Class* VerifyStackTrace$Handle::load$($String* name, bool initialize) {
	$loadClass(VerifyStackTrace$Handle, name, initialize, &_VerifyStackTrace$Handle_ClassInfo_, allocate$VerifyStackTrace$Handle);
	return class$;
}

$Class* VerifyStackTrace$Handle::class$ = nullptr;