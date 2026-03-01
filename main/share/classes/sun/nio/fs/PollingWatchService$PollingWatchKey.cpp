#include <sun/nio/fs/PollingWatchService$PollingWatchKey.h>

#include <java/io/IOException.h>
#include <java/lang/Runnable.h>
#include <java/nio/file/DirectoryIteratorException.h>
#include <java/nio/file/DirectoryStream.h>
#include <java/nio/file/Files.h>
#include <java/nio/file/LinkOption.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/StandardWatchEventKinds.h>
#include <java/nio/file/WatchEvent$Kind.h>
#include <java/nio/file/Watchable.h>
#include <java/nio/file/attribute/FileTime.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/concurrent/ScheduledExecutorService.h>
#include <java/util/concurrent/ScheduledFuture.h>
#include <java/util/concurrent/TimeUnit.h>
#include <sun/nio/fs/AbstractWatchKey.h>
#include <sun/nio/fs/AbstractWatchService.h>
#include <sun/nio/fs/PollingWatchService$CacheEntry.h>
#include <sun/nio/fs/PollingWatchService$PollingWatchKey$1.h>
#include <sun/nio/fs/PollingWatchService.h>
#include <jcpp.h>

#undef ENTRY_CREATE
#undef ENTRY_DELETE
#undef ENTRY_MODIFY
#undef NOFOLLOW_LINKS
#undef SECONDS

using $LinkOptionArray = $Array<::java::nio::file::LinkOption>;
using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $DirectoryIteratorException = ::java::nio::file::DirectoryIteratorException;
using $DirectoryStream = ::java::nio::file::DirectoryStream;
using $Files = ::java::nio::file::Files;
using $LinkOption = ::java::nio::file::LinkOption;
using $Path = ::java::nio::file::Path;
using $StandardWatchEventKinds = ::java::nio::file::StandardWatchEventKinds;
using $FileTime = ::java::nio::file::attribute::FileTime;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;
using $ScheduledExecutorService = ::java::util::concurrent::ScheduledExecutorService;
using $ScheduledFuture = ::java::util::concurrent::ScheduledFuture;
using $TimeUnit = ::java::util::concurrent::TimeUnit;
using $AbstractWatchKey = ::sun::nio::fs::AbstractWatchKey;
using $AbstractWatchService = ::sun::nio::fs::AbstractWatchService;
using $PollingWatchService = ::sun::nio::fs::PollingWatchService;
using $PollingWatchService$CacheEntry = ::sun::nio::fs::PollingWatchService$CacheEntry;
using $PollingWatchService$PollingWatchKey$1 = ::sun::nio::fs::PollingWatchService$PollingWatchKey$1;

namespace sun {
	namespace nio {
		namespace fs {

$FieldInfo _PollingWatchService$PollingWatchKey_FieldInfo_[] = {
	{"this$0", "Lsun/nio/fs/PollingWatchService;", nullptr, $FINAL | $SYNTHETIC, $field(PollingWatchService$PollingWatchKey, this$0)},
	{"fileKey", "Ljava/lang/Object;", nullptr, $PRIVATE | $FINAL, $field(PollingWatchService$PollingWatchKey, fileKey$)},
	{"events", "Ljava/util/Set;", "Ljava/util/Set<+Ljava/nio/file/WatchEvent$Kind<*>;>;", $PRIVATE, $field(PollingWatchService$PollingWatchKey, events)},
	{"poller", "Ljava/util/concurrent/ScheduledFuture;", "Ljava/util/concurrent/ScheduledFuture<*>;", $PRIVATE, $field(PollingWatchService$PollingWatchKey, poller)},
	{"valid", "Z", nullptr, $PRIVATE | $VOLATILE, $field(PollingWatchService$PollingWatchKey, valid)},
	{"tickCount", "I", nullptr, $PRIVATE, $field(PollingWatchService$PollingWatchKey, tickCount)},
	{"entries", "Ljava/util/Map;", "Ljava/util/Map<Ljava/nio/file/Path;Lsun/nio/fs/PollingWatchService$CacheEntry;>;", $PRIVATE, $field(PollingWatchService$PollingWatchKey, entries)},
	{}
};

$MethodInfo _PollingWatchService$PollingWatchKey_MethodInfo_[] = {
	{"<init>", "(Lsun/nio/fs/PollingWatchService;Ljava/nio/file/Path;Lsun/nio/fs/PollingWatchService;Ljava/lang/Object;)V", nullptr, 0, $method(PollingWatchService$PollingWatchKey, init$, void, $PollingWatchService*, $Path*, $PollingWatchService*, Object$*), "java.io.IOException"},
	{"cancel", "()V", nullptr, $PUBLIC, $virtualMethod(PollingWatchService$PollingWatchKey, cancel, void)},
	{"disable", "()V", nullptr, 0, $virtualMethod(PollingWatchService$PollingWatchKey, disable, void)},
	{"enable", "(Ljava/util/Set;J)V", "(Ljava/util/Set<+Ljava/nio/file/WatchEvent$Kind<*>;>;J)V", 0, $virtualMethod(PollingWatchService$PollingWatchKey, enable, void, $Set*, int64_t)},
	{"fileKey", "()Ljava/lang/Object;", nullptr, 0, $virtualMethod(PollingWatchService$PollingWatchKey, fileKey, $Object*)},
	{"invalidate", "()V", nullptr, 0, $virtualMethod(PollingWatchService$PollingWatchKey, invalidate, void)},
	{"isValid", "()Z", nullptr, $PUBLIC, $virtualMethod(PollingWatchService$PollingWatchKey, isValid, bool)},
	{"poll", "()V", nullptr, $SYNCHRONIZED, $virtualMethod(PollingWatchService$PollingWatchKey, poll, void)},
	{}
};

$InnerClassInfo _PollingWatchService$PollingWatchKey_InnerClassesInfo_[] = {
	{"sun.nio.fs.PollingWatchService$PollingWatchKey", "sun.nio.fs.PollingWatchService", "PollingWatchKey", $PRIVATE},
	{"sun.nio.fs.PollingWatchService$PollingWatchKey$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _PollingWatchService$PollingWatchKey_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.fs.PollingWatchService$PollingWatchKey",
	"sun.nio.fs.AbstractWatchKey",
	nullptr,
	_PollingWatchService$PollingWatchKey_FieldInfo_,
	_PollingWatchService$PollingWatchKey_MethodInfo_,
	nullptr,
	nullptr,
	_PollingWatchService$PollingWatchKey_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.nio.fs.PollingWatchService"
};

$Object* allocate$PollingWatchService$PollingWatchKey($Class* clazz) {
	return $of($alloc(PollingWatchService$PollingWatchKey));
}

void PollingWatchService$PollingWatchKey::init$($PollingWatchService* this$0, $Path* dir, $PollingWatchService* watcher, Object$* fileKey) {
	$useLocalCurrentObjectStackCache();
	$set(this, this$0, this$0);
	$AbstractWatchKey::init$(dir, watcher);
	$set(this, fileKey$, fileKey);
	this->valid = true;
	this->tickCount = 0;
	$set(this, entries, $new($HashMap));
	try {
		$var($DirectoryStream, stream, $Files::newDirectoryStream(dir));
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					{
						$var($Iterator, i$, $nc(stream)->iterator());
						for (; $nc(i$)->hasNext();) {
							$var($Path, entry, $cast($Path, i$->next()));
							{
								$init($LinkOption);
								int64_t lastModified = $nc($($Files::getLastModifiedTime(entry, $$new($LinkOptionArray, {$LinkOption::NOFOLLOW_LINKS}))))->toMillis();
								$var($Object, var$1, $of($nc(entry)->getFileName()));
								$nc(this->entries)->put(var$1, $$new($PollingWatchService$CacheEntry, lastModified, this->tickCount));
							}
						}
					}
				} catch ($Throwable& t$) {
					if (stream != nullptr) {
						try {
							stream->close();
						} catch ($Throwable& x2) {
							t$->addSuppressed(x2);
						}
					}
					$throw(t$);
				}
			} catch ($Throwable& var$2) {
				$assign(var$0, var$2);
			} /*finally*/ {
				if (stream != nullptr) {
					stream->close();
				}
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	} catch ($DirectoryIteratorException& e) {
		$throw($($cast($IOException, e->getCause())));
	}
}

$Object* PollingWatchService$PollingWatchKey::fileKey() {
	return $of(this->fileKey$);
}

bool PollingWatchService$PollingWatchKey::isValid() {
	return this->valid;
}

void PollingWatchService$PollingWatchKey::invalidate() {
	this->valid = false;
}

void PollingWatchService$PollingWatchKey::enable($Set* events, int64_t period) {
	$synchronized(this) {
		$set(this, events, events);
		$var($Runnable, thunk, $new($PollingWatchService$PollingWatchKey$1, this));
		$init($TimeUnit);
		$set(this, poller, $nc(this->this$0->scheduledExecutor)->scheduleAtFixedRate(thunk, period, period, $TimeUnit::SECONDS));
	}
}

void PollingWatchService$PollingWatchKey::disable() {
	$synchronized(this) {
		if (this->poller != nullptr) {
			$nc(this->poller)->cancel(false);
		}
	}
}

void PollingWatchService$PollingWatchKey::cancel() {
	this->valid = false;
	$synchronized(this->this$0->map) {
		$nc(this->this$0->map)->remove($(fileKey()));
	}
	disable();
}

void PollingWatchService$PollingWatchKey::poll() {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (!this->valid) {
			return;
		}
		++this->tickCount;
		$var($DirectoryStream, stream, nullptr);
		try {
			$assign(stream, $Files::newDirectoryStream($($cast($Path, watchable()))));
		} catch ($IOException& x) {
			cancel();
			signal();
			return;
		}
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					{
						$var($Iterator, i$, $nc(stream)->iterator());
						for (; $nc(i$)->hasNext();) {
							$var($Path, entry, $cast($Path, i$->next()));
							{
								int64_t lastModified = 0;
								try {
									$init($LinkOption);
									lastModified = $nc($($Files::getLastModifiedTime(entry, $$new($LinkOptionArray, {$LinkOption::NOFOLLOW_LINKS}))))->toMillis();
								} catch ($IOException& x) {
									continue;
								}
								$var($PollingWatchService$CacheEntry, e, $cast($PollingWatchService$CacheEntry, $nc(this->entries)->get($($nc(entry)->getFileName()))));
								if (e == nullptr) {
									$var($Object, var$1, $of($nc(entry)->getFileName()));
									$nc(this->entries)->put(var$1, $$new($PollingWatchService$CacheEntry, lastModified, this->tickCount));
									$init($StandardWatchEventKinds);
									if ($nc(this->events)->contains($StandardWatchEventKinds::ENTRY_CREATE)) {
										signalEvent($StandardWatchEventKinds::ENTRY_CREATE, $($nc(entry)->getFileName()));
										continue;
									} else {
										if ($nc(this->events)->contains($StandardWatchEventKinds::ENTRY_MODIFY)) {
											signalEvent($StandardWatchEventKinds::ENTRY_MODIFY, $($nc(entry)->getFileName()));
										}
									}
									continue;
								}
								if ($nc(e)->lastModified$ != lastModified) {
									$init($StandardWatchEventKinds);
									if ($nc(this->events)->contains($StandardWatchEventKinds::ENTRY_MODIFY)) {
										signalEvent($StandardWatchEventKinds::ENTRY_MODIFY, $($nc(entry)->getFileName()));
									}
								}
								$nc(e)->update(lastModified, this->tickCount);
							}
						}
					}
				} catch ($DirectoryIteratorException& e) {
				}
			} catch ($Throwable& var$2) {
				$assign(var$0, var$2);
			} /*finally*/ {
				try {
					$nc(stream)->close();
				} catch ($IOException& x) {
				}
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
		$var($Iterator, i, $nc($($nc(this->entries)->entrySet()))->iterator());
		while ($nc(i)->hasNext()) {
			$var($Map$Entry, mapEntry, $cast($Map$Entry, i->next()));
			$var($PollingWatchService$CacheEntry, entry, $cast($PollingWatchService$CacheEntry, $nc(mapEntry)->getValue()));
			if ($nc(entry)->lastTickCount() != this->tickCount) {
				$var($Path, name, $cast($Path, mapEntry->getKey()));
				i->remove();
				$init($StandardWatchEventKinds);
				if ($nc(this->events)->contains($StandardWatchEventKinds::ENTRY_DELETE)) {
					signalEvent($StandardWatchEventKinds::ENTRY_DELETE, name);
				}
			}
		}
	}
}

PollingWatchService$PollingWatchKey::PollingWatchService$PollingWatchKey() {
}

$Class* PollingWatchService$PollingWatchKey::load$($String* name, bool initialize) {
	$loadClass(PollingWatchService$PollingWatchKey, name, initialize, &_PollingWatchService$PollingWatchKey_ClassInfo_, allocate$PollingWatchService$PollingWatchKey);
	return class$;
}

$Class* PollingWatchService$PollingWatchKey::class$ = nullptr;

		} // fs
	} // nio
} // sun