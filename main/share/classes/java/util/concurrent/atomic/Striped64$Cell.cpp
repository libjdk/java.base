#include <java/util/concurrent/atomic/Striped64$Cell.h>

#include <java/lang/ExceptionInInitializerError.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/VarHandle.h>
#include <java/util/concurrent/atomic/Striped64.h>
#include <jcpp.h>

#undef TYPE
#undef VALUE

using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $ExceptionInInitializerError = ::java::lang::ExceptionInInitializerError;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $VarHandle = ::java::lang::invoke::VarHandle;

namespace java {
	namespace util {
		namespace concurrent {
			namespace atomic {

$CompoundAttribute _Striped64$Cell_Annotations_[] = {
	{"Ljdk/internal/vm/annotation/Contended;", nullptr},
	{}
};

$FieldInfo _Striped64$Cell_FieldInfo_[] = {
	{"value", "J", nullptr, $VOLATILE, $field(Striped64$Cell, value)},
	{"VALUE", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Striped64$Cell, VALUE)},
	{}
};

$MethodInfo _Striped64$Cell_MethodInfo_[] = {
	{"<init>", "(J)V", nullptr, 0, $method(Striped64$Cell, init$, void, int64_t)},
	{"cas", "(JJ)Z", nullptr, $FINAL, $method(Striped64$Cell, cas, bool, int64_t, int64_t)},
	{"getAndSet", "(J)J", nullptr, $FINAL, $method(Striped64$Cell, getAndSet, int64_t, int64_t)},
	{"reset", "()V", nullptr, $FINAL, $method(Striped64$Cell, reset, void)},
	{"reset", "(J)V", nullptr, $FINAL, $method(Striped64$Cell, reset, void, int64_t)},
	{}
};

$InnerClassInfo _Striped64$Cell_InnerClassesInfo_[] = {
	{"java.util.concurrent.atomic.Striped64$Cell", "java.util.concurrent.atomic.Striped64", "Cell", $STATIC | $FINAL},
	{}
};

$ClassInfo _Striped64$Cell_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.concurrent.atomic.Striped64$Cell",
	"java.lang.Object",
	nullptr,
	_Striped64$Cell_FieldInfo_,
	_Striped64$Cell_MethodInfo_,
	nullptr,
	nullptr,
	_Striped64$Cell_InnerClassesInfo_,
	_Striped64$Cell_Annotations_,
	nullptr,
	nullptr,
	"java.util.concurrent.atomic.Striped64"
};

$Object* allocate$Striped64$Cell($Class* clazz) {
	return $of($alloc(Striped64$Cell));
}

$VarHandle* Striped64$Cell::VALUE = nullptr;

void Striped64$Cell::init$(int64_t x) {
	this->value = x;
}

bool Striped64$Cell::cas(int64_t cmp, int64_t val) {
	return $nc(Striped64$Cell::VALUE)->weakCompareAndSetRelease($$new($ObjectArray, {$of(this), $$of(cmp), $$of(val)}));
}

void Striped64$Cell::reset() {
	$nc(Striped64$Cell::VALUE)->setVolatile($$new($ObjectArray, {$of(this), $$of(0)}));
}

void Striped64$Cell::reset(int64_t identity) {
	$nc(Striped64$Cell::VALUE)->setVolatile($$new($ObjectArray, {$of(this), $$of(identity)}));
}

int64_t Striped64$Cell::getAndSet(int64_t val) {
	return $longValue($nc(Striped64$Cell::VALUE)->getAndSet($$new($ObjectArray, {$of(this), $$of(val)})));
}

void clinit$Striped64$Cell($Class* class$) {
	$beforeCallerSensitive();
	{
		try {
			$var($MethodHandles$Lookup, l, $MethodHandles::lookup());
			$init($Long);
			$assignStatic(Striped64$Cell::VALUE, $nc(l)->findVarHandle(Striped64$Cell::class$, "value"_s, $Long::TYPE));
		} catch ($ReflectiveOperationException& e) {
			$throwNew($ExceptionInInitializerError, static_cast<$Throwable*>(e));
		}
	}
}

Striped64$Cell::Striped64$Cell() {
}

$Class* Striped64$Cell::load$($String* name, bool initialize) {
	$loadClass(Striped64$Cell, name, initialize, &_Striped64$Cell_ClassInfo_, clinit$Striped64$Cell, allocate$Striped64$Cell);
	return class$;
}

$Class* Striped64$Cell::class$ = nullptr;

			} // atomic
		} // concurrent
	} // util
} // java