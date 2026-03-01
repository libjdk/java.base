#include <sun/nio/ch/PendingIoCache.h>

#include <java/lang/AssertionError.h>
#include <java/lang/InterruptedException.h>
#include <java/lang/Runnable.h>
#include <java/nio/channels/AsynchronousChannel.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <jdk/internal/misc/Unsafe.h>
#include <sun/nio/ch/AsynchronousChannelGroupImpl.h>
#include <sun/nio/ch/Groupable.h>
#include <sun/nio/ch/Iocp$ResultHandler.h>
#include <sun/nio/ch/Iocp.h>
#include <sun/nio/ch/PendingFuture.h>
#include <sun/nio/ch/PendingIoCache$1.h>
#include <jcpp.h>

#undef SIZEOF_OVERLAPPED

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InterruptedException = ::java::lang::InterruptedException;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $Unsafe = ::jdk::internal::misc::Unsafe;
using $Groupable = ::sun::nio::ch::Groupable;
using $Iocp = ::sun::nio::ch::Iocp;
using $Iocp$ResultHandler = ::sun::nio::ch::Iocp$ResultHandler;
using $PendingFuture = ::sun::nio::ch::PendingFuture;
using $PendingIoCache$1 = ::sun::nio::ch::PendingIoCache$1;

namespace sun {
	namespace nio {
		namespace ch {

$FieldInfo _PendingIoCache_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(PendingIoCache, $assertionsDisabled)},
	{"unsafe", "Ljdk/internal/misc/Unsafe;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PendingIoCache, unsafe)},
	{"addressSize", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PendingIoCache, addressSize)},
	{"SIZEOF_OVERLAPPED", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PendingIoCache, SIZEOF_OVERLAPPED)},
	{"closed", "Z", nullptr, $PRIVATE, $field(PendingIoCache, closed)},
	{"closePending", "Z", nullptr, $PRIVATE, $field(PendingIoCache, closePending)},
	{"pendingIoMap", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/Long;Lsun/nio/ch/PendingFuture;>;", $PRIVATE | $FINAL, $field(PendingIoCache, pendingIoMap)},
	{"overlappedCache", "[J", nullptr, $PRIVATE, $field(PendingIoCache, overlappedCache)},
	{"overlappedCacheCount", "I", nullptr, $PRIVATE, $field(PendingIoCache, overlappedCacheCount)},
	{}
};

$MethodInfo _PendingIoCache_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(PendingIoCache, init$, void)},
	{"add", "(Lsun/nio/ch/PendingFuture;)J", "(Lsun/nio/ch/PendingFuture<**>;)J", 0, $virtualMethod(PendingIoCache, add, int64_t, $PendingFuture*)},
	{"clearPendingIoMap", "()V", nullptr, $PRIVATE, $method(PendingIoCache, clearPendingIoMap, void)},
	{"close", "()V", nullptr, 0, $virtualMethod(PendingIoCache, close, void)},
	{"dependsArch", "(II)I", nullptr, $PRIVATE | $STATIC, $staticMethod(PendingIoCache, dependsArch, int32_t, int32_t, int32_t)},
	{"remove", "(J)Lsun/nio/ch/PendingFuture;", "<V:Ljava/lang/Object;A:Ljava/lang/Object;>(J)Lsun/nio/ch/PendingFuture<TV;TA;>;", 0, $virtualMethod(PendingIoCache, remove, $PendingFuture*, int64_t)},
	{}
};

$InnerClassInfo _PendingIoCache_InnerClassesInfo_[] = {
	{"sun.nio.ch.PendingIoCache$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _PendingIoCache_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.ch.PendingIoCache",
	"java.lang.Object",
	nullptr,
	_PendingIoCache_FieldInfo_,
	_PendingIoCache_MethodInfo_,
	nullptr,
	nullptr,
	_PendingIoCache_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.nio.ch.PendingIoCache$1"
};

$Object* allocate$PendingIoCache($Class* clazz) {
	return $of($alloc(PendingIoCache));
}

bool PendingIoCache::$assertionsDisabled = false;
$Unsafe* PendingIoCache::unsafe = nullptr;
int32_t PendingIoCache::addressSize = 0;
int32_t PendingIoCache::SIZEOF_OVERLAPPED = 0;

int32_t PendingIoCache::dependsArch(int32_t value32, int32_t value64) {
	$init(PendingIoCache);
	return (PendingIoCache::addressSize == 4) ? value32 : value64;
}

void PendingIoCache::init$() {
	$set(this, pendingIoMap, $new($HashMap));
	$set(this, overlappedCache, $new($longs, 4));
	this->overlappedCacheCount = 0;
}

int64_t PendingIoCache::add($PendingFuture* result) {
	$synchronized(this) {
		if (this->closed) {
			$throwNew($AssertionError, $of("Should not get here"_s));
		}
		int64_t ov = 0;
		if (this->overlappedCacheCount > 0) {
			ov = $nc(this->overlappedCache)->get(--this->overlappedCacheCount);
		} else {
			ov = $nc(PendingIoCache::unsafe)->allocateMemory(PendingIoCache::SIZEOF_OVERLAPPED);
		}
		$nc(this->pendingIoMap)->put($($Long::valueOf(ov)), result);
		return ov;
	}
}

$PendingFuture* PendingIoCache::remove(int64_t overlapped) {
	$useLocalCurrentObjectStackCache();
	$synchronized(this) {
		$var($PendingFuture, res, $cast($PendingFuture, $nc(this->pendingIoMap)->remove($($Long::valueOf(overlapped)))));
		if (res != nullptr) {
			if (this->overlappedCacheCount < $nc(this->overlappedCache)->length) {
				$nc(this->overlappedCache)->set(this->overlappedCacheCount++, overlapped);
			} else {
				$nc(PendingIoCache::unsafe)->freeMemory(overlapped);
			}
			if (this->closePending) {
				$of(this)->notifyAll();
			}
		}
		return res;
	}
}

void PendingIoCache::close() {
	$synchronized(this) {
		if (this->closed) {
			return;
		}
		if (!$nc(this->pendingIoMap)->isEmpty()) {
			clearPendingIoMap();
		}
		while (this->overlappedCacheCount > 0) {
			$nc(PendingIoCache::unsafe)->freeMemory($nc(this->overlappedCache)->get(--this->overlappedCacheCount));
		}
		this->closed = true;
	}
}

void PendingIoCache::clearPendingIoMap() {
	$useLocalCurrentObjectStackCache();
	if (!PendingIoCache::$assertionsDisabled && !$Thread::holdsLock(this)) {
		$throwNew($AssertionError);
	}
	this->closePending = true;
	try {
		$of(this)->wait(50);
	} catch ($InterruptedException& x) {
		$($Thread::currentThread())->interrupt();
	}
	this->closePending = false;
	if ($nc(this->pendingIoMap)->isEmpty()) {
		return;
	}
	{
		$var($Iterator, i$, $nc($($nc(this->pendingIoMap)->keySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Long, ov, $cast($Long, i$->next()));
			{
				$var($PendingFuture, result, $cast($PendingFuture, $nc(this->pendingIoMap)->get(ov)));
				$var($Iocp, iocp, $cast($Iocp, $nc(($cast($Groupable, $($nc(result)->channel()))))->group()));
				$nc(iocp)->makeStale(ov);
				$var($Iocp$ResultHandler, rh, $cast($Iocp$ResultHandler, result->getContext()));
				$var($Runnable, task, $new($PendingIoCache$1, this, rh));
				iocp->executeOnPooledThread(task);
			}
		}
	}
	$nc(this->pendingIoMap)->clear();
}

void clinit$PendingIoCache($Class* class$) {
	PendingIoCache::$assertionsDisabled = !PendingIoCache::class$->desiredAssertionStatus();
	$assignStatic(PendingIoCache::unsafe, $Unsafe::getUnsafe());
	PendingIoCache::addressSize = $nc(PendingIoCache::unsafe)->addressSize();
	PendingIoCache::SIZEOF_OVERLAPPED = PendingIoCache::dependsArch(20, 32);
}

PendingIoCache::PendingIoCache() {
}

$Class* PendingIoCache::load$($String* name, bool initialize) {
	$loadClass(PendingIoCache, name, initialize, &_PendingIoCache_ClassInfo_, clinit$PendingIoCache, allocate$PendingIoCache);
	return class$;
}

$Class* PendingIoCache::class$ = nullptr;

		} // ch
	} // nio
} // sun