#include <java/util/concurrent/ForkJoinTask$Aux.h>

#include <java/lang/ExceptionInInitializerError.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/VarHandle.h>
#include <java/util/concurrent/ForkJoinTask.h>
#include <jcpp.h>

#undef NEXT

using $ClassInfo = ::java::lang::ClassInfo;
using $ExceptionInInitializerError = ::java::lang::ExceptionInInitializerError;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $VarHandle = ::java::lang::invoke::VarHandle;

namespace java {
	namespace util {
		namespace concurrent {

$FieldInfo _ForkJoinTask$Aux_FieldInfo_[] = {
	{"thread", "Ljava/lang/Thread;", nullptr, $FINAL, $field(ForkJoinTask$Aux, thread)},
	{"ex", "Ljava/lang/Throwable;", nullptr, $FINAL, $field(ForkJoinTask$Aux, ex)},
	{"next", "Ljava/util/concurrent/ForkJoinTask$Aux;", nullptr, 0, $field(ForkJoinTask$Aux, next)},
	{"NEXT", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ForkJoinTask$Aux, NEXT)},
	{}
};

$MethodInfo _ForkJoinTask$Aux_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/Thread;Ljava/lang/Throwable;)V", nullptr, 0, $method(ForkJoinTask$Aux, init$, void, $Thread*, $Throwable*)},
	{"casNext", "(Ljava/util/concurrent/ForkJoinTask$Aux;Ljava/util/concurrent/ForkJoinTask$Aux;)Z", nullptr, $FINAL, $method(ForkJoinTask$Aux, casNext, bool, ForkJoinTask$Aux*, ForkJoinTask$Aux*)},
	{}
};

$InnerClassInfo _ForkJoinTask$Aux_InnerClassesInfo_[] = {
	{"java.util.concurrent.ForkJoinTask$Aux", "java.util.concurrent.ForkJoinTask", "Aux", $STATIC | $FINAL},
	{}
};

$ClassInfo _ForkJoinTask$Aux_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.concurrent.ForkJoinTask$Aux",
	"java.lang.Object",
	nullptr,
	_ForkJoinTask$Aux_FieldInfo_,
	_ForkJoinTask$Aux_MethodInfo_,
	nullptr,
	nullptr,
	_ForkJoinTask$Aux_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.concurrent.ForkJoinTask"
};

$Object* allocate$ForkJoinTask$Aux($Class* clazz) {
	return $of($alloc(ForkJoinTask$Aux));
}

$VarHandle* ForkJoinTask$Aux::NEXT = nullptr;

void ForkJoinTask$Aux::init$($Thread* thread, $Throwable* ex) {
	$set(this, thread, thread);
	$set(this, ex, ex);
}

bool ForkJoinTask$Aux::casNext(ForkJoinTask$Aux* c, ForkJoinTask$Aux* v) {
	return $nc(ForkJoinTask$Aux::NEXT)->compareAndSet($$new($ObjectArray, {$of(this), $of(c), $of(v)}));
}

void clinit$ForkJoinTask$Aux($Class* class$) {
	$beforeCallerSensitive();
	{
		try {
			$assignStatic(ForkJoinTask$Aux::NEXT, $nc($($MethodHandles::lookup()))->findVarHandle(ForkJoinTask$Aux::class$, "next"_s, ForkJoinTask$Aux::class$));
		} catch ($ReflectiveOperationException& e) {
			$throwNew($ExceptionInInitializerError, static_cast<$Throwable*>(e));
		}
	}
}

ForkJoinTask$Aux::ForkJoinTask$Aux() {
}

$Class* ForkJoinTask$Aux::load$($String* name, bool initialize) {
	$loadClass(ForkJoinTask$Aux, name, initialize, &_ForkJoinTask$Aux_ClassInfo_, clinit$ForkJoinTask$Aux, allocate$ForkJoinTask$Aux);
	return class$;
}

$Class* ForkJoinTask$Aux::class$ = nullptr;

		} // concurrent
	} // util
} // java