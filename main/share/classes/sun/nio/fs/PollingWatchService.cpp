#include <sun/nio/fs/PollingWatchService.h>

#include <java/io/IOException.h>
#include <java/lang/AssertionError.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/nio/file/ClosedWatchServiceException.h>
#include <java/nio/file/Files.h>
#include <java/nio/file/LinkOption.h>
#include <java/nio/file/NotDirectoryException.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/StandardWatchEventKinds.h>
#include <java/nio/file/WatchEvent$Kind.h>
#include <java/nio/file/WatchEvent$Modifier.h>
#include <java/nio/file/WatchKey.h>
#include <java/nio/file/attribute/BasicFileAttributes.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/PrivilegedActionException.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/util/HashMap.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/concurrent/Executors.h>
#include <java/util/concurrent/ScheduledExecutorService.h>
#include <java/util/concurrent/ThreadFactory.h>
#include <sun/nio/fs/AbstractWatchService.h>
#include <sun/nio/fs/ExtendedOptions$InternalOption.h>
#include <sun/nio/fs/ExtendedOptions.h>
#include <sun/nio/fs/PollingWatchService$1.h>
#include <sun/nio/fs/PollingWatchService$2.h>
#include <sun/nio/fs/PollingWatchService$3.h>
#include <sun/nio/fs/PollingWatchService$PollingWatchKey.h>
#include <jcpp.h>

#undef ENTRY_CREATE
#undef ENTRY_DELETE
#undef ENTRY_MODIFY
#undef OVERFLOW
#undef SENSITIVITY_HIGH
#undef SENSITIVITY_LOW
#undef SENSITIVITY_MEDIUM

using $LinkOptionArray = $Array<::java::nio::file::LinkOption>;
using $WatchEvent$KindArray = $Array<::java::nio::file::WatchEvent$Kind>;
using $WatchEvent$ModifierArray = $Array<::java::nio::file::WatchEvent$Modifier>;
using $IOException = ::java::io::IOException;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $ClosedWatchServiceException = ::java::nio::file::ClosedWatchServiceException;
using $Files = ::java::nio::file::Files;
using $NotDirectoryException = ::java::nio::file::NotDirectoryException;
using $Path = ::java::nio::file::Path;
using $StandardWatchEventKinds = ::java::nio::file::StandardWatchEventKinds;
using $WatchEvent$Kind = ::java::nio::file::WatchEvent$Kind;
using $WatchEvent$Modifier = ::java::nio::file::WatchEvent$Modifier;
using $WatchKey = ::java::nio::file::WatchKey;
using $BasicFileAttributes = ::java::nio::file::attribute::BasicFileAttributes;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $PrivilegedActionException = ::java::security::PrivilegedActionException;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $HashMap = ::java::util::HashMap;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;
using $Executors = ::java::util::concurrent::Executors;
using $ThreadFactory = ::java::util::concurrent::ThreadFactory;
using $AbstractWatchService = ::sun::nio::fs::AbstractWatchService;
using $ExtendedOptions = ::sun::nio::fs::ExtendedOptions;
using $ExtendedOptions$InternalOption = ::sun::nio::fs::ExtendedOptions$InternalOption;
using $PollingWatchService$1 = ::sun::nio::fs::PollingWatchService$1;
using $PollingWatchService$2 = ::sun::nio::fs::PollingWatchService$2;
using $PollingWatchService$3 = ::sun::nio::fs::PollingWatchService$3;
using $PollingWatchService$PollingWatchKey = ::sun::nio::fs::PollingWatchService$PollingWatchKey;

namespace sun {
	namespace nio {
		namespace fs {

$FieldInfo _PollingWatchService_FieldInfo_[] = {
	{"map", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/Object;Lsun/nio/fs/PollingWatchService$PollingWatchKey;>;", $PRIVATE | $FINAL, $field(PollingWatchService, map)},
	{"scheduledExecutor", "Ljava/util/concurrent/ScheduledExecutorService;", nullptr, $PRIVATE | $FINAL, $field(PollingWatchService, scheduledExecutor)},
	{}
};

$MethodInfo _PollingWatchService_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(PollingWatchService, init$, void)},
	{"doPrivilegedRegister", "(Ljava/nio/file/Path;Ljava/util/Set;I)Lsun/nio/fs/PollingWatchService$PollingWatchKey;", "(Ljava/nio/file/Path;Ljava/util/Set<+Ljava/nio/file/WatchEvent$Kind<*>;>;I)Lsun/nio/fs/PollingWatchService$PollingWatchKey;", $PRIVATE, $method(PollingWatchService, doPrivilegedRegister, $PollingWatchService$PollingWatchKey*, $Path*, $Set*, int32_t), "java.io.IOException"},
	{"implClose", "()V", nullptr, 0, $virtualMethod(PollingWatchService, implClose, void), "java.io.IOException"},
	{"register", "(Ljava/nio/file/Path;[Ljava/nio/file/WatchEvent$Kind;[Ljava/nio/file/WatchEvent$Modifier;)Ljava/nio/file/WatchKey;", "(Ljava/nio/file/Path;[Ljava/nio/file/WatchEvent$Kind<*>;[Ljava/nio/file/WatchEvent$Modifier;)Ljava/nio/file/WatchKey;", $TRANSIENT, $virtualMethod(PollingWatchService, register$, $WatchKey*, $Path*, $WatchEvent$KindArray*, $WatchEvent$ModifierArray*), "java.io.IOException"},
	{}
};

$InnerClassInfo _PollingWatchService_InnerClassesInfo_[] = {
	{"sun.nio.fs.PollingWatchService$PollingWatchKey", "sun.nio.fs.PollingWatchService", "PollingWatchKey", $PRIVATE},
	{"sun.nio.fs.PollingWatchService$CacheEntry", "sun.nio.fs.PollingWatchService", "CacheEntry", $PRIVATE | $STATIC},
	{"sun.nio.fs.PollingWatchService$3", nullptr, nullptr, 0},
	{"sun.nio.fs.PollingWatchService$2", nullptr, nullptr, 0},
	{"sun.nio.fs.PollingWatchService$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _PollingWatchService_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.fs.PollingWatchService",
	"sun.nio.fs.AbstractWatchService",
	nullptr,
	_PollingWatchService_FieldInfo_,
	_PollingWatchService_MethodInfo_,
	nullptr,
	nullptr,
	_PollingWatchService_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.nio.fs.PollingWatchService$PollingWatchKey,sun.nio.fs.PollingWatchService$PollingWatchKey$1,sun.nio.fs.PollingWatchService$CacheEntry,sun.nio.fs.PollingWatchService$3,sun.nio.fs.PollingWatchService$2,sun.nio.fs.PollingWatchService$1"
};

$Object* allocate$PollingWatchService($Class* clazz) {
	return $of($alloc(PollingWatchService));
}

void PollingWatchService::init$() {
	$AbstractWatchService::init$();
	$set(this, map, $new($HashMap));
	$set(this, scheduledExecutor, $Executors::newSingleThreadScheduledExecutor($$new($PollingWatchService$1, this)));
}

$WatchKey* PollingWatchService::register$($Path* path, $WatchEvent$KindArray* events, $WatchEvent$ModifierArray* modifiers) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($Set, eventSet, $new($HashSet, $nc(events)->length));
	{
		$var($WatchEvent$KindArray, arr$, events);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($WatchEvent$Kind, event, arr$->get(i$));
			{
				$init($StandardWatchEventKinds);
				if (event == $StandardWatchEventKinds::ENTRY_CREATE || event == $StandardWatchEventKinds::ENTRY_MODIFY || event == $StandardWatchEventKinds::ENTRY_DELETE) {
					eventSet->add(event);
					continue;
				}
				if (event == $StandardWatchEventKinds::OVERFLOW) {
					continue;
				}
				if (event == nullptr) {
					$throwNew($NullPointerException, "An element in event set is \'null\'"_s);
				}
				$throwNew($UnsupportedOperationException, $($nc(event)->name()));
			}
		}
	}
	if (eventSet->isEmpty()) {
		$throwNew($IllegalArgumentException, "No events to register"_s);
	}
	int32_t sensitivity = 10;
	if ($nc(modifiers)->length > 0) {
		{
			$var($WatchEvent$ModifierArray, arr$, modifiers);
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($WatchEvent$Modifier, modifier, arr$->get(i$));
				{
					if (modifier == nullptr) {
						$throwNew($NullPointerException);
					}
					$init($ExtendedOptions);
					if ($nc($ExtendedOptions::SENSITIVITY_HIGH)->matches(modifier)) {
						sensitivity = $nc(($cast($Integer, $($nc($ExtendedOptions::SENSITIVITY_HIGH)->parameter()))))->intValue();
					} else {
						if ($nc($ExtendedOptions::SENSITIVITY_MEDIUM)->matches(modifier)) {
							sensitivity = $nc(($cast($Integer, $($nc($ExtendedOptions::SENSITIVITY_MEDIUM)->parameter()))))->intValue();
						} else {
							if ($nc($ExtendedOptions::SENSITIVITY_LOW)->matches(modifier)) {
								sensitivity = $nc(($cast($Integer, $($nc($ExtendedOptions::SENSITIVITY_LOW)->parameter()))))->intValue();
							} else {
								$throwNew($UnsupportedOperationException, "Modifier not supported"_s);
							}
						}
					}
				}
			}
		}
	}
	if (!isOpen()) {
		$throwNew($ClosedWatchServiceException);
	}
	try {
		int32_t value = sensitivity;
		return $cast($WatchKey, $AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new($PollingWatchService$2, this, path, eventSet, value))));
	} catch ($PrivilegedActionException& pae) {
		$var($Throwable, cause, pae->getCause());
		{
			$var($IOException, ioe, nullptr);
			bool var$0 = $instanceOf($IOException, cause);
			if (var$0) {
				$assign(ioe, $cast($IOException, cause));
				var$0 = true;
			}
			if (var$0) {
				$throw(ioe);
			}
		}
		$throwNew($AssertionError, $of(pae));
	}
	$shouldNotReachHere();
}

$PollingWatchService$PollingWatchKey* PollingWatchService::doPrivilegedRegister($Path* path, $Set* events, int32_t sensitivityInSeconds) {
	$useLocalCurrentObjectStackCache();
	$load($BasicFileAttributes);
	$var($BasicFileAttributes, attrs, $Files::readAttributes(path, $BasicFileAttributes::class$, $$new($LinkOptionArray, 0)));
	if (!$nc(attrs)->isDirectory()) {
		$throwNew($NotDirectoryException, $($nc(path)->toString()));
	}
	$var($Object, fileKey, $nc(attrs)->fileKey());
	if (fileKey == nullptr) {
		$throwNew($AssertionError, $of("File keys must be supported"_s));
	}
	$synchronized(closeLock()) {
		if (!isOpen()) {
			$throwNew($ClosedWatchServiceException);
		}
		$var($PollingWatchService$PollingWatchKey, watchKey, nullptr);
		$synchronized(this->map) {
			$assign(watchKey, $cast($PollingWatchService$PollingWatchKey, $nc(this->map)->get(fileKey)));
			if (watchKey == nullptr) {
				$assign(watchKey, $new($PollingWatchService$PollingWatchKey, this, path, this, fileKey));
				$nc(this->map)->put(fileKey, watchKey);
			} else {
				$nc(watchKey)->disable();
			}
		}
		$nc(watchKey)->enable(events, sensitivityInSeconds);
		return watchKey;
	}
}

void PollingWatchService::implClose() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$synchronized(this->map) {
		{
			$var($Iterator, i$, $nc($($nc(this->map)->entrySet()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
				{
					$var($PollingWatchService$PollingWatchKey, watchKey, $cast($PollingWatchService$PollingWatchKey, $nc(entry)->getValue()));
					$nc(watchKey)->disable();
					watchKey->invalidate();
				}
			}
		}
		$nc(this->map)->clear();
	}
	$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($PollingWatchService$3, this)));
}

PollingWatchService::PollingWatchService() {
}

$Class* PollingWatchService::load$($String* name, bool initialize) {
	$loadClass(PollingWatchService, name, initialize, &_PollingWatchService_ClassInfo_, allocate$PollingWatchService);
	return class$;
}

$Class* PollingWatchService::class$ = nullptr;

		} // fs
	} // nio
} // sun