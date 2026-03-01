#include <java/util/concurrent/atomic/Striped64.h>

#include <java/lang/ExceptionInInitializerError.h>
#include <java/lang/Number.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/Runtime.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/VarHandle.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/Arrays.h>
#include <java/util/concurrent/ThreadLocalRandom.h>
#include <java/util/concurrent/atomic/Striped64$1.h>
#include <java/util/concurrent/atomic/Striped64$Cell.h>
#include <java/util/function/DoubleBinaryOperator.h>
#include <java/util/function/LongBinaryOperator.h>
#include <jcpp.h>

#undef BASE
#undef CELLSBUSY
#undef NCPU
#undef THREAD_PROBE
#undef TYPE

using $Striped64$CellArray = $Array<::java::util::concurrent::atomic::Striped64$Cell>;
using $ClassInfo = ::java::lang::ClassInfo;
using $Double = ::java::lang::Double;
using $ExceptionInInitializerError = ::java::lang::ExceptionInInitializerError;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Number = ::java::lang::Number;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $Runtime = ::java::lang::Runtime;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $VarHandle = ::java::lang::invoke::VarHandle;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Arrays = ::java::util::Arrays;
using $ThreadLocalRandom = ::java::util::concurrent::ThreadLocalRandom;
using $Striped64$1 = ::java::util::concurrent::atomic::Striped64$1;
using $Striped64$Cell = ::java::util::concurrent::atomic::Striped64$Cell;
using $DoubleBinaryOperator = ::java::util::function::DoubleBinaryOperator;
using $LongBinaryOperator = ::java::util::function::LongBinaryOperator;

namespace java {
	namespace util {
		namespace concurrent {
			namespace atomic {

$FieldInfo _Striped64_FieldInfo_[] = {
	{"NCPU", "I", nullptr, $STATIC | $FINAL, $staticField(Striped64, NCPU)},
	{"cells", "[Ljava/util/concurrent/atomic/Striped64$Cell;", nullptr, $VOLATILE | $TRANSIENT, $field(Striped64, cells)},
	{"base", "J", nullptr, $VOLATILE | $TRANSIENT, $field(Striped64, base)},
	{"cellsBusy", "I", nullptr, $VOLATILE | $TRANSIENT, $field(Striped64, cellsBusy)},
	{"BASE", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Striped64, BASE)},
	{"CELLSBUSY", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Striped64, CELLSBUSY)},
	{"THREAD_PROBE", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Striped64, THREAD_PROBE)},
	{}
};

$MethodInfo _Striped64_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(Striped64, init$, void)},
	{"advanceProbe", "(I)I", nullptr, $STATIC | $FINAL, $staticMethod(Striped64, advanceProbe, int32_t, int32_t)},
	{"apply", "(Ljava/util/function/DoubleBinaryOperator;JD)J", nullptr, $PRIVATE | $STATIC, $staticMethod(Striped64, apply, int64_t, $DoubleBinaryOperator*, int64_t, double)},
	{"casBase", "(JJ)Z", nullptr, $FINAL, $method(Striped64, casBase, bool, int64_t, int64_t)},
	{"casCellsBusy", "()Z", nullptr, $FINAL, $method(Striped64, casCellsBusy, bool)},
	{"doubleAccumulate", "(DLjava/util/function/DoubleBinaryOperator;ZI)V", nullptr, $FINAL, $method(Striped64, doubleAccumulate, void, double, $DoubleBinaryOperator*, bool, int32_t)},
	{"getAndSetBase", "(J)J", nullptr, $FINAL, $method(Striped64, getAndSetBase, int64_t, int64_t)},
	{"getProbe", "()I", nullptr, $STATIC | $FINAL, $staticMethod(Striped64, getProbe, int32_t)},
	{"longAccumulate", "(JLjava/util/function/LongBinaryOperator;ZI)V", nullptr, $FINAL, $method(Striped64, longAccumulate, void, int64_t, $LongBinaryOperator*, bool, int32_t)},
	{}
};

$InnerClassInfo _Striped64_InnerClassesInfo_[] = {
	{"java.util.concurrent.atomic.Striped64$Cell", "java.util.concurrent.atomic.Striped64", "Cell", $STATIC | $FINAL},
	{"java.util.concurrent.atomic.Striped64$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Striped64_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"java.util.concurrent.atomic.Striped64",
	"java.lang.Number",
	nullptr,
	_Striped64_FieldInfo_,
	_Striped64_MethodInfo_,
	nullptr,
	nullptr,
	_Striped64_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.concurrent.atomic.Striped64$Cell,java.util.concurrent.atomic.Striped64$1"
};

$Object* allocate$Striped64($Class* clazz) {
	return $of($alloc(Striped64));
}

int32_t Striped64::NCPU = 0;
$VarHandle* Striped64::BASE = nullptr;
$VarHandle* Striped64::CELLSBUSY = nullptr;
$VarHandle* Striped64::THREAD_PROBE = nullptr;

void Striped64::init$() {
	$Number::init$();
}

bool Striped64::casBase(int64_t cmp, int64_t val) {
	return $nc(Striped64::BASE)->weakCompareAndSetRelease($$new($ObjectArray, {$of(this), $$of(cmp), $$of(val)}));
}

int64_t Striped64::getAndSetBase(int64_t val) {
	return $longValue($nc(Striped64::BASE)->getAndSet($$new($ObjectArray, {$of(this), $$of(val)})));
}

bool Striped64::casCellsBusy() {
	return $nc(Striped64::CELLSBUSY)->compareAndSet($$new($ObjectArray, {$of(this), $$of(0), $$of(1)}));
}

int32_t Striped64::getProbe() {
	$init(Striped64);
	$useLocalCurrentObjectStackCache();
	return $intValue($nc(Striped64::THREAD_PROBE)->get($$new($ObjectArray, {$($of($Thread::currentThread()))})));
}

int32_t Striped64::advanceProbe(int32_t probe) {
	$init(Striped64);
	$useLocalCurrentObjectStackCache();
	probe ^= probe << 13;
	probe ^= (int32_t)((uint32_t)probe >> 17);
	probe ^= probe << 5;
	$nc(Striped64::THREAD_PROBE)->set($$new($ObjectArray, {$($of($Thread::currentThread())), $$of(probe)}));
	return probe;
}

void Striped64::longAccumulate(int64_t x, $LongBinaryOperator* fn, bool wasUncontended, int32_t index) {
	$useLocalCurrentObjectStackCache();
	if (index == 0) {
		$ThreadLocalRandom::current();
		index = getProbe();
		wasUncontended = true;
	}
	for (bool collide = false;;) {
		$var($Striped64$CellArray, cs, nullptr);
		$var($Striped64$Cell, c, nullptr);
		int32_t n = 0;
		int64_t v = 0;
		bool var$0 = ($assign(cs, this->cells)) != nullptr;
		if (var$0 && (n = $nc(cs)->length) > 0) {
			if (($assign(c, cs->get((int32_t)((n - 1) & (uint32_t)index)))) == nullptr) {
				if (this->cellsBusy == 0) {
					$var($Striped64$Cell, r, $new($Striped64$Cell, x));
					if (this->cellsBusy == 0 && casCellsBusy()) {
						{
							$var($Throwable, var$1, nullptr);
							bool break$2 = false;
							try {
								$var($Striped64$CellArray, rs, nullptr);
								int32_t m = 0;
								int32_t j = 0;
								bool var$4 = ($assign(rs, this->cells)) != nullptr;
								bool var$3 = var$4 && (m = $nc(rs)->length) > 0;
								if (var$3 && rs->get(j = (int32_t)((m - 1) & (uint32_t)index)) == nullptr) {
									rs->set(j, r);
									// break;
									break$2 = true;
									goto $finally;
								}
							} catch ($Throwable& var$5) {
								$assign(var$1, var$5);
							} $finally: {
								this->cellsBusy = 0;
							}
							if (var$1 != nullptr) {
								$throw(var$1);
							}
							if (break$2) {
								break;
							}
						}
						continue;
					}
				}
				collide = false;
			} else if (!wasUncontended) {
				wasUncontended = true;
			} else {
				int64_t var$7 = v = c->value;
				if ($nc(c)->cas(var$7, (fn == nullptr) ? v + x : $nc(fn)->applyAsLong(v, x))) {
					break;
				} else if (n >= Striped64::NCPU || this->cells != cs) {
					collide = false;
				} else if (!collide) {
					collide = true;
				} else if (this->cellsBusy == 0 && casCellsBusy()) {
					{
						$var($Throwable, var$8, nullptr);
						try {
							if (this->cells == cs) {
								$set(this, cells, $fcast($Striped64$CellArray, $Arrays::copyOf(cs, n << 1)));
							}
						} catch ($Throwable& var$9) {
							$assign(var$8, var$9);
						} /*finally*/ {
							this->cellsBusy = 0;
						}
						if (var$8 != nullptr) {
							$throw(var$8);
						}
					}
					collide = false;
					continue;
				}
			}
			index = advanceProbe(index);
		} else if (this->cellsBusy == 0 && this->cells == cs && casCellsBusy()) {
			{
				$var($Throwable, var$10, nullptr);
				bool break$11 = false;
				try {
					if (this->cells == cs) {
						$var($Striped64$CellArray, rs, $new($Striped64$CellArray, 2));
						rs->set((int32_t)(index & (uint32_t)1), $$new($Striped64$Cell, x));
						$set(this, cells, rs);
						// break;
						break$11 = true;
						goto $finally2;
					}
				} catch ($Throwable& var$12) {
					$assign(var$10, var$12);
				} $finally2: {
					this->cellsBusy = 0;
				}
				if (var$10 != nullptr) {
					$throw(var$10);
				}
				if (break$11) {
					break;
				}
			}
		} else {
			int64_t var$14 = v = this->base;
			if (casBase(var$14, (fn == nullptr) ? v + x : $nc(fn)->applyAsLong(v, x))) {
				break;
			}
		}
	}
}

int64_t Striped64::apply($DoubleBinaryOperator* fn, int64_t v, double x) {
	$init(Striped64);
	double d = $Double::longBitsToDouble(v);
	d = (fn == nullptr) ? d + x : $nc(fn)->applyAsDouble(d, x);
	return $Double::doubleToRawLongBits(d);
}

void Striped64::doubleAccumulate(double x, $DoubleBinaryOperator* fn, bool wasUncontended, int32_t index) {
	$useLocalCurrentObjectStackCache();
	if (index == 0) {
		$ThreadLocalRandom::current();
		index = getProbe();
		wasUncontended = true;
	}
	for (bool collide = false;;) {
		$var($Striped64$CellArray, cs, nullptr);
		$var($Striped64$Cell, c, nullptr);
		int32_t n = 0;
		int64_t v = 0;
		bool var$0 = ($assign(cs, this->cells)) != nullptr;
		if (var$0 && (n = $nc(cs)->length) > 0) {
			if (($assign(c, cs->get((int32_t)((n - 1) & (uint32_t)index)))) == nullptr) {
				if (this->cellsBusy == 0) {
					$var($Striped64$Cell, r, $new($Striped64$Cell, $Double::doubleToRawLongBits(x)));
					if (this->cellsBusy == 0 && casCellsBusy()) {
						{
							$var($Throwable, var$1, nullptr);
							bool break$2 = false;
							try {
								$var($Striped64$CellArray, rs, nullptr);
								int32_t m = 0;
								int32_t j = 0;
								bool var$4 = ($assign(rs, this->cells)) != nullptr;
								bool var$3 = var$4 && (m = $nc(rs)->length) > 0;
								if (var$3 && rs->get(j = (int32_t)((m - 1) & (uint32_t)index)) == nullptr) {
									rs->set(j, r);
									// break;
									break$2 = true;
									goto $finally;
								}
							} catch ($Throwable& var$5) {
								$assign(var$1, var$5);
							} $finally: {
								this->cellsBusy = 0;
							}
							if (var$1 != nullptr) {
								$throw(var$1);
							}
							if (break$2) {
								break;
							}
						}
						continue;
					}
				}
				collide = false;
			} else if (!wasUncontended) {
				wasUncontended = true;
			} else {
				int64_t var$7 = v = c->value;
				if ($nc(c)->cas(var$7, apply(fn, v, x))) {
					break;
				} else if (n >= Striped64::NCPU || this->cells != cs) {
					collide = false;
				} else if (!collide) {
					collide = true;
				} else if (this->cellsBusy == 0 && casCellsBusy()) {
					{
						$var($Throwable, var$8, nullptr);
						try {
							if (this->cells == cs) {
								$set(this, cells, $fcast($Striped64$CellArray, $Arrays::copyOf(cs, n << 1)));
							}
						} catch ($Throwable& var$9) {
							$assign(var$8, var$9);
						} /*finally*/ {
							this->cellsBusy = 0;
						}
						if (var$8 != nullptr) {
							$throw(var$8);
						}
					}
					collide = false;
					continue;
				}
			}
			index = advanceProbe(index);
		} else if (this->cellsBusy == 0 && this->cells == cs && casCellsBusy()) {
			{
				$var($Throwable, var$10, nullptr);
				bool break$11 = false;
				try {
					if (this->cells == cs) {
						$var($Striped64$CellArray, rs, $new($Striped64$CellArray, 2));
						rs->set((int32_t)(index & (uint32_t)1), $$new($Striped64$Cell, $Double::doubleToRawLongBits(x)));
						$set(this, cells, rs);
						// break;
						break$11 = true;
						goto $finally2;
					}
				} catch ($Throwable& var$12) {
					$assign(var$10, var$12);
				} $finally2: {
					this->cellsBusy = 0;
				}
				if (var$10 != nullptr) {
					$throw(var$10);
				}
				if (break$11) {
					break;
				}
			}
		} else {
			int64_t var$14 = v = this->base;
			if (casBase(var$14, apply(fn, v, x))) {
				break;
			}
		}
	}
}

void clinit$Striped64($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	Striped64::NCPU = $nc($($Runtime::getRuntime()))->availableProcessors();
	{
		try {
			$var($MethodHandles$Lookup, l, $MethodHandles::lookup());
			$init($Long);
			$assignStatic(Striped64::BASE, $nc(l)->findVarHandle(Striped64::class$, "base"_s, $Long::TYPE));
			$init($Integer);
			$assignStatic(Striped64::CELLSBUSY, l->findVarHandle(Striped64::class$, "cellsBusy"_s, $Integer::TYPE));
			$assign(l, $cast($MethodHandles$Lookup, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($Striped64$1)))));
			$assignStatic(Striped64::THREAD_PROBE, l->findVarHandle($Thread::class$, "threadLocalRandomProbe"_s, $Integer::TYPE));
		} catch ($ReflectiveOperationException& e) {
			$throwNew($ExceptionInInitializerError, static_cast<$Throwable*>(e));
		}
	}
}

Striped64::Striped64() {
}

$Class* Striped64::load$($String* name, bool initialize) {
	$loadClass(Striped64, name, initialize, &_Striped64_ClassInfo_, clinit$Striped64, allocate$Striped64);
	return class$;
}

$Class* Striped64::class$ = nullptr;

			} // atomic
		} // concurrent
	} // util
} // java