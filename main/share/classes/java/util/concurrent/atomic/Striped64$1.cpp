#include <java/util/concurrent/atomic/Striped64$1.h>

#include <java/lang/ExceptionInInitializerError.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/util/concurrent/atomic/Striped64.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $ExceptionInInitializerError = ::java::lang::ExceptionInInitializerError;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $MethodHandles = ::java::lang::invoke::MethodHandles;

namespace java {
	namespace util {
		namespace concurrent {
			namespace atomic {

$MethodInfo _Striped64$1_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(Striped64$1, init$, void)},
	{"run", "()Ljava/lang/invoke/MethodHandles$Lookup;", nullptr, $PUBLIC, $virtualMethod(Striped64$1, run, $Object*)},
	{}
};

$EnclosingMethodInfo _Striped64$1_EnclosingMethodInfo_ = {
	"java.util.concurrent.atomic.Striped64",
	nullptr,
	nullptr
};

$InnerClassInfo _Striped64$1_InnerClassesInfo_[] = {
	{"java.util.concurrent.atomic.Striped64$1", nullptr, nullptr, 0},
	{"java.lang.invoke.MethodHandles$Lookup", "java.lang.invoke.MethodHandles", "Lookup", $PUBLIC | $STATIC | $FINAL},
	{}
};

$ClassInfo _Striped64$1_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.concurrent.atomic.Striped64$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	_Striped64$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/invoke/MethodHandles$Lookup;>;",
	&_Striped64$1_EnclosingMethodInfo_,
	_Striped64$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.concurrent.atomic.Striped64"
};

$Object* allocate$Striped64$1($Class* clazz) {
	return $of($alloc(Striped64$1));
}

void Striped64$1::init$() {
}

$Object* Striped64$1::run() {
	$beforeCallerSensitive();
	try {
		return $of($MethodHandles::privateLookupIn($Thread::class$, $($MethodHandles::lookup())));
	} catch ($ReflectiveOperationException& e) {
		$throwNew($ExceptionInInitializerError, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

Striped64$1::Striped64$1() {
}

$Class* Striped64$1::load$($String* name, bool initialize) {
	$loadClass(Striped64$1, name, initialize, &_Striped64$1_ClassInfo_, allocate$Striped64$1);
	return class$;
}

$Class* Striped64$1::class$ = nullptr;

			} // atomic
		} // concurrent
	} // util
} // java