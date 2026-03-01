#include <sun/nio/fs/AbstractWatchService.h>

#include <java/nio/file/ClosedWatchServiceException.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/WatchEvent$Kind.h>
#include <java/nio/file/WatchEvent$Modifier.h>
#include <java/nio/file/WatchKey.h>
#include <java/util/concurrent/LinkedBlockingDeque.h>
#include <java/util/concurrent/TimeUnit.h>
#include <sun/nio/fs/AbstractWatchService$1.h>
#include <jcpp.h>

#undef CLOSE_KEY

using $WatchEvent$KindArray = $Array<::java::nio::file::WatchEvent$Kind>;
using $WatchEvent$ModifierArray = $Array<::java::nio::file::WatchEvent$Modifier>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ClosedWatchServiceException = ::java::nio::file::ClosedWatchServiceException;
using $Path = ::java::nio::file::Path;
using $WatchKey = ::java::nio::file::WatchKey;
using $LinkedBlockingDeque = ::java::util::concurrent::LinkedBlockingDeque;
using $TimeUnit = ::java::util::concurrent::TimeUnit;
using $AbstractWatchService$1 = ::sun::nio::fs::AbstractWatchService$1;

namespace sun {
	namespace nio {
		namespace fs {

$FieldInfo _AbstractWatchService_FieldInfo_[] = {
	{"pendingKeys", "Ljava/util/concurrent/LinkedBlockingDeque;", "Ljava/util/concurrent/LinkedBlockingDeque<Ljava/nio/file/WatchKey;>;", $PRIVATE | $FINAL, $field(AbstractWatchService, pendingKeys)},
	{"CLOSE_KEY", "Ljava/nio/file/WatchKey;", nullptr, $PRIVATE | $FINAL, $field(AbstractWatchService, CLOSE_KEY)},
	{"closed", "Z", nullptr, $PRIVATE | $VOLATILE, $field(AbstractWatchService, closed)},
	{"closeLock", "Ljava/lang/Object;", nullptr, $PRIVATE | $FINAL, $field(AbstractWatchService, closeLock$)},
	{}
};

$MethodInfo _AbstractWatchService_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PROTECTED, $method(AbstractWatchService, init$, void)},
	{"checkKey", "(Ljava/nio/file/WatchKey;)V", nullptr, $PRIVATE, $method(AbstractWatchService, checkKey, void, $WatchKey*)},
	{"checkOpen", "()V", nullptr, $PRIVATE, $method(AbstractWatchService, checkOpen, void)},
	{"close", "()V", nullptr, $PUBLIC | $FINAL, $virtualMethod(AbstractWatchService, close, void), "java.io.IOException"},
	{"closeLock", "()Ljava/lang/Object;", nullptr, $FINAL, $method(AbstractWatchService, closeLock, $Object*)},
	{"enqueueKey", "(Ljava/nio/file/WatchKey;)V", nullptr, $FINAL, $method(AbstractWatchService, enqueueKey, void, $WatchKey*)},
	{"implClose", "()V", nullptr, $ABSTRACT, $virtualMethod(AbstractWatchService, implClose, void), "java.io.IOException"},
	{"isOpen", "()Z", nullptr, $FINAL, $method(AbstractWatchService, isOpen, bool)},
	{"poll", "()Ljava/nio/file/WatchKey;", nullptr, $PUBLIC | $FINAL, $virtualMethod(AbstractWatchService, poll, $WatchKey*)},
	{"poll", "(JLjava/util/concurrent/TimeUnit;)Ljava/nio/file/WatchKey;", nullptr, $PUBLIC | $FINAL, $virtualMethod(AbstractWatchService, poll, $WatchKey*, int64_t, $TimeUnit*), "java.lang.InterruptedException"},
	{"register", "(Ljava/nio/file/Path;[Ljava/nio/file/WatchEvent$Kind;[Ljava/nio/file/WatchEvent$Modifier;)Ljava/nio/file/WatchKey;", "(Ljava/nio/file/Path;[Ljava/nio/file/WatchEvent$Kind<*>;[Ljava/nio/file/WatchEvent$Modifier;)Ljava/nio/file/WatchKey;", $TRANSIENT | $ABSTRACT, $virtualMethod(AbstractWatchService, register$, $WatchKey*, $Path*, $WatchEvent$KindArray*, $WatchEvent$ModifierArray*), "java.io.IOException"},
	{"take", "()Ljava/nio/file/WatchKey;", nullptr, $PUBLIC | $FINAL, $virtualMethod(AbstractWatchService, take, $WatchKey*), "java.lang.InterruptedException"},
	{}
};

$InnerClassInfo _AbstractWatchService_InnerClassesInfo_[] = {
	{"sun.nio.fs.AbstractWatchService$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _AbstractWatchService_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"sun.nio.fs.AbstractWatchService",
	"java.lang.Object",
	"java.nio.file.WatchService",
	_AbstractWatchService_FieldInfo_,
	_AbstractWatchService_MethodInfo_,
	nullptr,
	nullptr,
	_AbstractWatchService_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.nio.fs.AbstractWatchService$1"
};

$Object* allocate$AbstractWatchService($Class* clazz) {
	return $of($alloc(AbstractWatchService));
}

void AbstractWatchService::init$() {
	$set(this, pendingKeys, $new($LinkedBlockingDeque));
	$set(this, CLOSE_KEY, $new($AbstractWatchService$1, this, nullptr, nullptr));
	$set(this, closeLock$, $new($Object));
}

void AbstractWatchService::enqueueKey($WatchKey* key) {
	$nc(this->pendingKeys)->offer(key);
}

void AbstractWatchService::checkOpen() {
	if (this->closed) {
		$throwNew($ClosedWatchServiceException);
	}
}

void AbstractWatchService::checkKey($WatchKey* key) {
	if (key == this->CLOSE_KEY) {
		enqueueKey(key);
	}
	checkOpen();
}

$WatchKey* AbstractWatchService::poll() {
	checkOpen();
	$var($WatchKey, key, $cast($WatchKey, $nc(this->pendingKeys)->poll()));
	checkKey(key);
	return key;
}

$WatchKey* AbstractWatchService::poll(int64_t timeout, $TimeUnit* unit) {
	checkOpen();
	$var($WatchKey, key, $cast($WatchKey, $nc(this->pendingKeys)->poll(timeout, unit)));
	checkKey(key);
	return key;
}

$WatchKey* AbstractWatchService::take() {
	checkOpen();
	$var($WatchKey, key, $cast($WatchKey, $nc(this->pendingKeys)->take()));
	checkKey(key);
	return key;
}

bool AbstractWatchService::isOpen() {
	return !this->closed;
}

$Object* AbstractWatchService::closeLock() {
	return $of(this->closeLock$);
}

void AbstractWatchService::close() {
	$synchronized(this->closeLock$) {
		if (this->closed) {
			return;
		}
		this->closed = true;
		implClose();
		$nc(this->pendingKeys)->clear();
		$nc(this->pendingKeys)->offer(this->CLOSE_KEY);
	}
}

AbstractWatchService::AbstractWatchService() {
}

$Class* AbstractWatchService::load$($String* name, bool initialize) {
	$loadClass(AbstractWatchService, name, initialize, &_AbstractWatchService_ClassInfo_, allocate$AbstractWatchService);
	return class$;
}

$Class* AbstractWatchService::class$ = nullptr;

		} // fs
	} // nio
} // sun