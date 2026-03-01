#include <java/util/concurrent/Exchanger.h>

#include <java/lang/ExceptionInInitializerError.h>
#include <java/lang/InterruptedException.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/Runtime.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/VarHandle.h>
#include <java/util/concurrent/Exchanger$Node.h>
#include <java/util/concurrent/Exchanger$Participant.h>
#include <java/util/concurrent/TimeUnit.h>
#include <java/util/concurrent/TimeoutException.h>
#include <java/util/concurrent/locks/LockSupport.h>
#include <jcpp.h>

#undef AA
#undef ASHIFT
#undef BOUND
#undef FULL
#undef MATCH
#undef MMASK
#undef NCPU
#undef NULL_ITEM
#undef SEQ
#undef SLOT
#undef SPINS
#undef TIMED_OUT
#undef TYPE

using $Exchanger$NodeArray = $Array<::java::util::concurrent::Exchanger$Node>;
using $ClassInfo = ::java::lang::ClassInfo;
using $ExceptionInInitializerError = ::java::lang::ExceptionInInitializerError;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InterruptedException = ::java::lang::InterruptedException;
using $MethodInfo = ::java::lang::MethodInfo;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $Runtime = ::java::lang::Runtime;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $VarHandle = ::java::lang::invoke::VarHandle;
using $Exchanger$Node = ::java::util::concurrent::Exchanger$Node;
using $Exchanger$Participant = ::java::util::concurrent::Exchanger$Participant;
using $TimeUnit = ::java::util::concurrent::TimeUnit;
using $TimeoutException = ::java::util::concurrent::TimeoutException;
using $LockSupport = ::java::util::concurrent::locks::LockSupport;

namespace java {
	namespace util {
		namespace concurrent {

$FieldInfo _Exchanger_FieldInfo_[] = {
	{"ASHIFT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Exchanger, ASHIFT)},
	{"MMASK", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Exchanger, MMASK)},
	{"SEQ", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Exchanger, SEQ)},
	{"NCPU", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Exchanger, NCPU)},
	{"FULL", "I", nullptr, $STATIC | $FINAL, $staticField(Exchanger, FULL)},
	{"SPINS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Exchanger, SPINS)},
	{"NULL_ITEM", "Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Exchanger, NULL_ITEM)},
	{"TIMED_OUT", "Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Exchanger, TIMED_OUT)},
	{"participant", "Ljava/util/concurrent/Exchanger$Participant;", nullptr, $PRIVATE | $FINAL, $field(Exchanger, participant)},
	{"arena", "[Ljava/util/concurrent/Exchanger$Node;", nullptr, $PRIVATE | $VOLATILE, $field(Exchanger, arena)},
	{"slot", "Ljava/util/concurrent/Exchanger$Node;", nullptr, $PRIVATE | $VOLATILE, $field(Exchanger, slot)},
	{"bound", "I", nullptr, $PRIVATE | $VOLATILE, $field(Exchanger, bound)},
	{"BOUND", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Exchanger, BOUND)},
	{"SLOT", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Exchanger, SLOT)},
	{"MATCH", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Exchanger, MATCH)},
	{"AA", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Exchanger, AA)},
	{}
};

$MethodInfo _Exchanger_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Exchanger, init$, void)},
	{"arenaExchange", "(Ljava/lang/Object;ZJ)Ljava/lang/Object;", nullptr, $PRIVATE | $FINAL, $method(Exchanger, arenaExchange, $Object*, Object$*, bool, int64_t)},
	{"exchange", "(Ljava/lang/Object;)Ljava/lang/Object;", "(TV;)TV;", $PUBLIC, $virtualMethod(Exchanger, exchange, $Object*, Object$*), "java.lang.InterruptedException"},
	{"exchange", "(Ljava/lang/Object;JLjava/util/concurrent/TimeUnit;)Ljava/lang/Object;", "(TV;JLjava/util/concurrent/TimeUnit;)TV;", $PUBLIC, $virtualMethod(Exchanger, exchange, $Object*, Object$*, int64_t, $TimeUnit*), "java.lang.InterruptedException,java.util.concurrent.TimeoutException"},
	{"slotExchange", "(Ljava/lang/Object;ZJ)Ljava/lang/Object;", nullptr, $PRIVATE | $FINAL, $method(Exchanger, slotExchange, $Object*, Object$*, bool, int64_t)},
	{}
};

$InnerClassInfo _Exchanger_InnerClassesInfo_[] = {
	{"java.util.concurrent.Exchanger$Participant", "java.util.concurrent.Exchanger", "Participant", $STATIC | $FINAL},
	{"java.util.concurrent.Exchanger$Node", "java.util.concurrent.Exchanger", "Node", $STATIC | $FINAL},
	{}
};

$ClassInfo _Exchanger_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.concurrent.Exchanger",
	"java.lang.Object",
	nullptr,
	_Exchanger_FieldInfo_,
	_Exchanger_MethodInfo_,
	"<V:Ljava/lang/Object;>Ljava/lang/Object;",
	nullptr,
	_Exchanger_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.concurrent.Exchanger$Participant,java.util.concurrent.Exchanger$Node"
};

$Object* allocate$Exchanger($Class* clazz) {
	return $of($alloc(Exchanger));
}

int32_t Exchanger::NCPU = 0;
int32_t Exchanger::FULL = 0;
$Object* Exchanger::NULL_ITEM = nullptr;
$Object* Exchanger::TIMED_OUT = nullptr;
$VarHandle* Exchanger::BOUND = nullptr;
$VarHandle* Exchanger::SLOT = nullptr;
$VarHandle* Exchanger::MATCH = nullptr;
$VarHandle* Exchanger::AA = nullptr;

$Object* Exchanger::arenaExchange(Object$* item, bool timed, int64_t ns) {
	$useLocalCurrentObjectStackCache();
	$var($Exchanger$NodeArray, a, this->arena);
	int32_t alen = $nc(a)->length;
	$var($Exchanger$Node, p, $cast($Exchanger$Node, $nc(this->participant)->get()));
	for (int32_t i = $nc(p)->index;;) {
		int32_t b = 0;
		int32_t m = 0;
		int32_t c = 0;
		int32_t j = ($sl(i, Exchanger::ASHIFT)) + (($sl(1, Exchanger::ASHIFT)) - 1);
		if (j < 0 || j >= alen) {
			j = alen - 1;
		}
		$var($Exchanger$Node, q, $cast($Exchanger$Node, $nc(Exchanger::AA)->getAcquire($$new($ObjectArray, {$of(a), $$of(j)}))));
		if (q != nullptr && $nc(Exchanger::AA)->compareAndSet($$new($ObjectArray, {$of(a), $$of(j), $of(q), ($Object*)nullptr}))) {
			$var($Object, v, q->item);
			$set(q, match, item);
			$var($Thread, w, q->parked);
			if (w != nullptr) {
				$LockSupport::unpark(w);
			}
			return $of(v);
		} else if (i <= (m = (int32_t)((b = this->bound) & (uint32_t)Exchanger::MMASK)) && q == nullptr) {
			$set(p, item, item);
			if ($nc(Exchanger::AA)->compareAndSet($$new($ObjectArray, {$of(a), $$of(j), ($Object*)nullptr, $of(p)}))) {
				int64_t end = (timed && m == 0) ? $System::nanoTime() + ns : (int64_t)0;
				$var($Thread, t, $Thread::currentThread());
				{
					int32_t h = p->hash;
					int32_t spins = Exchanger::SPINS;
					for (;;) {
						$var($Object, v, p->match);
						if (v != nullptr) {
							$nc(Exchanger::MATCH)->setRelease($$new($ObjectArray, {$of(p), ($Object*)nullptr}));
							$set(p, item, nullptr);
							p->hash = h;
							return $of(v);
						} else if (spins > 0) {
							h ^= h << 1;
							h ^= (int32_t)((uint32_t)h >> 3);
							h ^= h << 10;
							if (h == 0) {
								h = Exchanger::SPINS | (int32_t)t->getId();
							} else if (h < 0 && ((int32_t)(--spins & (uint32_t)(((int32_t)((uint32_t)Exchanger::SPINS >> 1)) - 1))) == 0) {
								$Thread::yield();
							}
						} else if (!$equals($nc(Exchanger::AA)->getAcquire($$new($ObjectArray, {$of(a), $$of(j)})), p)) {
							spins = Exchanger::SPINS;
						} else {
							bool var$1 = !t->isInterrupted() && m == 0;
							if (var$1 && (!timed || (ns = end - $System::nanoTime()) > (int64_t)0)) {
								$set(p, parked, t);
								if ($equals($nc(Exchanger::AA)->getAcquire($$new($ObjectArray, {$of(a), $$of(j)})), p)) {
									if (ns == (int64_t)0) {
										$LockSupport::park(this);
									} else {
										$LockSupport::parkNanos(this, ns);
									}
								}
								$set(p, parked, nullptr);
							} else {
								bool var$3 = $equals($nc(Exchanger::AA)->getAcquire($$new($ObjectArray, {$of(a), $$of(j)})), p);
								if (var$3 && $nc(Exchanger::AA)->compareAndSet($$new($ObjectArray, {$of(a), $$of(j), $of(p), ($Object*)nullptr}))) {
									if (m != 0) {
										$nc(Exchanger::BOUND)->compareAndSet($$new($ObjectArray, {$of(this), $$of(b), $$of((b + Exchanger::SEQ - 1))}));
									}
									$set(p, item, nullptr);
									p->hash = h;
									i = $usrAssign(p->index, 1);
									if ($Thread::interrupted()) {
										return $of(nullptr);
									}
									if (timed && m == 0 && ns <= (int64_t)0) {
										return $of(Exchanger::TIMED_OUT);
									}
									break;
								}
							}
						}
					}
				}
			} else {
				$set(p, item, nullptr);
			}
		} else {
			if (p->bound != b) {
				p->bound = b;
				p->collides = 0;
				i = (i != m || m == 0) ? m : m - 1;
			} else if ((c = p->collides) < m || m == Exchanger::FULL || !$nc(Exchanger::BOUND)->compareAndSet($$new($ObjectArray, {$of(this), $$of(b), $$of((b + Exchanger::SEQ + 1))}))) {
				p->collides = c + 1;
				i = (i == 0) ? m : i - 1;
			} else {
				i = m + 1;
			}
			p->index = i;
		}
	}
}

$Object* Exchanger::slotExchange(Object$* item, bool timed, int64_t ns) {
	$useLocalCurrentObjectStackCache();
	$var($Exchanger$Node, p, $cast($Exchanger$Node, $nc(this->participant)->get()));
	$var($Thread, t, $Thread::currentThread());
	if (t->isInterrupted()) {
		return $of(nullptr);
	}
	{
		$var($Exchanger$Node, q, nullptr);
		for (;;) {
			if (($assign(q, this->slot)) != nullptr) {
				if ($nc(Exchanger::SLOT)->compareAndSet($$new($ObjectArray, {$of(this), $of(q), ($Object*)nullptr}))) {
					$var($Object, v, $nc(q)->item);
					$set(q, match, item);
					$var($Thread, w, q->parked);
					if (w != nullptr) {
						$LockSupport::unpark(w);
					}
					return $of(v);
				}
				if (Exchanger::NCPU > 1 && this->bound == 0 && $nc(Exchanger::BOUND)->compareAndSet($$new($ObjectArray, {$of(this), $$of(0), $$of(Exchanger::SEQ)}))) {
					$set(this, arena, $new($Exchanger$NodeArray, $sl(Exchanger::FULL + 2, Exchanger::ASHIFT)));
				}
			} else if (this->arena != nullptr) {
				return $of(nullptr);
			} else {
				$set($nc(p), item, item);
				if ($nc(Exchanger::SLOT)->compareAndSet($$new($ObjectArray, {$of(this), ($Object*)nullptr, $of(p)}))) {
					break;
				}
				$set(p, item, nullptr);
			}
		}
	}
	int32_t h = $nc(p)->hash;
	int64_t end = timed ? $System::nanoTime() + ns : (int64_t)0;
	int32_t spins = (Exchanger::NCPU > 1) ? Exchanger::SPINS : 1;
	$var($Object, v, nullptr);
	while (($assign(v, p->match)) == nullptr) {
		if (spins > 0) {
			h ^= h << 1;
			h ^= (int32_t)((uint32_t)h >> 3);
			h ^= h << 10;
			if (h == 0) {
				h = Exchanger::SPINS | (int32_t)t->getId();
			} else if (h < 0 && ((int32_t)(--spins & (uint32_t)(((int32_t)((uint32_t)Exchanger::SPINS >> 1)) - 1))) == 0) {
				$Thread::yield();
			}
		} else if (this->slot != p) {
			spins = Exchanger::SPINS;
		} else {
			bool var$1 = !t->isInterrupted() && this->arena == nullptr;
			if (var$1 && (!timed || (ns = end - $System::nanoTime()) > (int64_t)0)) {
				$set(p, parked, t);
				if (this->slot == p) {
					if (ns == (int64_t)0) {
						$LockSupport::park(this);
					} else {
						$LockSupport::parkNanos(this, ns);
					}
				}
				$set(p, parked, nullptr);
			} else if ($nc(Exchanger::SLOT)->compareAndSet($$new($ObjectArray, {$of(this), $of(p), ($Object*)nullptr}))) {
				$assign(v, timed && ns <= (int64_t)0 && !t->isInterrupted() ? Exchanger::TIMED_OUT : ($Object*)nullptr);
				break;
			}
		}
	}
	$nc(Exchanger::MATCH)->setRelease($$new($ObjectArray, {$of(p), ($Object*)nullptr}));
	$set(p, item, nullptr);
	p->hash = h;
	return $of(v);
}

void Exchanger::init$() {
	$set(this, participant, $new($Exchanger$Participant));
}

$Object* Exchanger::exchange(Object$* x) {
	$useLocalCurrentObjectStackCache();
	$var($Object, v, nullptr);
	$var($Exchanger$NodeArray, a, nullptr);
	$var($Object, item, (x == nullptr) ? Exchanger::NULL_ITEM : $of(x));
	bool var$0 = (($assign(a, this->arena)) != nullptr || ($assign(v, slotExchange(item, false, 0))) == nullptr);
	if (var$0) {
		bool var$1 = $Thread::interrupted();
		var$0 = (var$1 || ($assign(v, arenaExchange(item, false, 0))) == nullptr);
	}
	if (var$0) {
		$throwNew($InterruptedException);
	}
	return $of(($equals(v, Exchanger::NULL_ITEM)) ? ($Object*)nullptr : v);
}

$Object* Exchanger::exchange(Object$* x, int64_t timeout, $TimeUnit* unit) {
	$useLocalCurrentObjectStackCache();
	$var($Object, v, nullptr);
	$var($Object, item, (x == nullptr) ? Exchanger::NULL_ITEM : $of(x));
	int64_t ns = $nc(unit)->toNanos(timeout);
	bool var$0 = (this->arena != nullptr || ($assign(v, slotExchange(item, true, ns))) == nullptr);
	if (var$0) {
		bool var$1 = $Thread::interrupted();
		var$0 = (var$1 || ($assign(v, arenaExchange(item, true, ns))) == nullptr);
	}
	if (var$0) {
		$throwNew($InterruptedException);
	}
	if ($equals(v, Exchanger::TIMED_OUT)) {
		$throwNew($TimeoutException);
	}
	return $of(($equals(v, Exchanger::NULL_ITEM)) ? ($Object*)nullptr : v);
}

void clinit$Exchanger($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	Exchanger::NCPU = $nc($($Runtime::getRuntime()))->availableProcessors();
	Exchanger::FULL = (Exchanger::NCPU >= (Exchanger::MMASK << 1)) ? Exchanger::MMASK : (int32_t)((uint32_t)Exchanger::NCPU >> 1);
	$assignStatic(Exchanger::NULL_ITEM, $new($Object));
	$assignStatic(Exchanger::TIMED_OUT, $new($Object));
	{
		try {
			$var($MethodHandles$Lookup, l, $MethodHandles::lookup());
			$init($Integer);
			$assignStatic(Exchanger::BOUND, $nc(l)->findVarHandle(Exchanger::class$, "bound"_s, $Integer::TYPE));
			$load($Exchanger$Node);
			$assignStatic(Exchanger::SLOT, l->findVarHandle(Exchanger::class$, "slot"_s, $Exchanger$Node::class$));
			$assignStatic(Exchanger::MATCH, l->findVarHandle($Exchanger$Node::class$, "match"_s, $Object::class$));
			$load($Exchanger$NodeArray);
			$assignStatic(Exchanger::AA, $MethodHandles::arrayElementVarHandle($getClass($Exchanger$NodeArray)));
		} catch ($ReflectiveOperationException& e) {
			$throwNew($ExceptionInInitializerError, static_cast<$Throwable*>(e));
		}
	}
}

Exchanger::Exchanger() {
}

$Class* Exchanger::load$($String* name, bool initialize) {
	$loadClass(Exchanger, name, initialize, &_Exchanger_ClassInfo_, clinit$Exchanger, allocate$Exchanger);
	return class$;
}

$Class* Exchanger::class$ = nullptr;

		} // concurrent
	} // util
} // java