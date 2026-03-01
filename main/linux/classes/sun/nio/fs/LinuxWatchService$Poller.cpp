#include <sun/nio/fs/LinuxWatchService$Poller.h>

#include <java/io/IOException.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/nio/file/NotDirectoryException.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/StandardWatchEventKinds.h>
#include <java/nio/file/WatchEvent$Kind.h>
#include <java/nio/file/WatchEvent$Modifier.h>
#include <java/nio/file/WatchKey.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <jdk/internal/misc/Unsafe.h>
#include <sun/nio/fs/AbstractPoller.h>
#include <sun/nio/fs/ExtendedOptions$InternalOption.h>
#include <sun/nio/fs/ExtendedOptions.h>
#include <sun/nio/fs/LinuxWatchService$LinuxWatchKey.h>
#include <sun/nio/fs/LinuxWatchService.h>
#include <sun/nio/fs/NativeBuffer.h>
#include <sun/nio/fs/NativeBuffers.h>
#include <sun/nio/fs/UnixConstants.h>
#include <sun/nio/fs/UnixException.h>
#include <sun/nio/fs/UnixFileAttributes.h>
#include <sun/nio/fs/UnixFileSystem.h>
#include <sun/nio/fs/UnixNativeDispatcher.h>
#include <sun/nio/fs/UnixPath.h>
#include <jcpp.h>

#undef ARRAY_BYTE_BASE_OFFSET
#undef BUFFER_SIZE
#undef EAGAIN
#undef ENOSPC
#undef ENTRY_CREATE
#undef ENTRY_DELETE
#undef ENTRY_MODIFY
#undef EWOULDBLOCK
#undef IN_ATTRIB
#undef IN_CREATE
#undef IN_DELETE
#undef IN_IGNORED
#undef IN_MODIFY
#undef IN_MOVED_FROM
#undef IN_MOVED_TO
#undef IN_Q_OVERFLOW
#undef IN_UNMOUNT
#undef OFFSETOF_LEN
#undef OFFSETOF_MASK
#undef OFFSETOF_NAME
#undef OFFSETOF_WD
#undef OVERFLOW
#undef SENSITIVITY_HIGH
#undef SENSITIVITY_LOW
#undef SENSITIVITY_MEDIUM
#undef SIZEOF_INOTIFY_EVENT

using $WatchEvent$ModifierArray = $Array<::java::nio::file::WatchEvent$Modifier>;
using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $NotDirectoryException = ::java::nio::file::NotDirectoryException;
using $Path = ::java::nio::file::Path;
using $StandardWatchEventKinds = ::java::nio::file::StandardWatchEventKinds;
using $WatchEvent$Kind = ::java::nio::file::WatchEvent$Kind;
using $WatchEvent$Modifier = ::java::nio::file::WatchEvent$Modifier;
using $WatchKey = ::java::nio::file::WatchKey;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;
using $Unsafe = ::jdk::internal::misc::Unsafe;
using $AbstractPoller = ::sun::nio::fs::AbstractPoller;
using $ExtendedOptions = ::sun::nio::fs::ExtendedOptions;
using $ExtendedOptions$InternalOption = ::sun::nio::fs::ExtendedOptions$InternalOption;
using $LinuxWatchService = ::sun::nio::fs::LinuxWatchService;
using $LinuxWatchService$LinuxWatchKey = ::sun::nio::fs::LinuxWatchService$LinuxWatchKey;
using $NativeBuffer = ::sun::nio::fs::NativeBuffer;
using $NativeBuffers = ::sun::nio::fs::NativeBuffers;
using $UnixConstants = ::sun::nio::fs::UnixConstants;
using $UnixException = ::sun::nio::fs::UnixException;
using $UnixFileAttributes = ::sun::nio::fs::UnixFileAttributes;
using $UnixFileSystem = ::sun::nio::fs::UnixFileSystem;
using $UnixNativeDispatcher = ::sun::nio::fs::UnixNativeDispatcher;
using $UnixPath = ::sun::nio::fs::UnixPath;

namespace sun {
	namespace nio {
		namespace fs {

$FieldInfo _LinuxWatchService$Poller_FieldInfo_[] = {
	{"SIZEOF_INOTIFY_EVENT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LinuxWatchService$Poller, SIZEOF_INOTIFY_EVENT)},
	{"offsets", "[I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LinuxWatchService$Poller, offsets)},
	{"OFFSETOF_WD", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LinuxWatchService$Poller, OFFSETOF_WD)},
	{"OFFSETOF_MASK", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LinuxWatchService$Poller, OFFSETOF_MASK)},
	{"OFFSETOF_LEN", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LinuxWatchService$Poller, OFFSETOF_LEN)},
	{"OFFSETOF_NAME", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LinuxWatchService$Poller, OFFSETOF_NAME)},
	{"IN_MODIFY", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(LinuxWatchService$Poller, IN_MODIFY)},
	{"IN_ATTRIB", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(LinuxWatchService$Poller, IN_ATTRIB)},
	{"IN_MOVED_FROM", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(LinuxWatchService$Poller, IN_MOVED_FROM)},
	{"IN_MOVED_TO", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(LinuxWatchService$Poller, IN_MOVED_TO)},
	{"IN_CREATE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(LinuxWatchService$Poller, IN_CREATE)},
	{"IN_DELETE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(LinuxWatchService$Poller, IN_DELETE)},
	{"IN_UNMOUNT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(LinuxWatchService$Poller, IN_UNMOUNT)},
	{"IN_Q_OVERFLOW", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(LinuxWatchService$Poller, IN_Q_OVERFLOW)},
	{"IN_IGNORED", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(LinuxWatchService$Poller, IN_IGNORED)},
	{"BUFFER_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(LinuxWatchService$Poller, BUFFER_SIZE)},
	{"fs", "Lsun/nio/fs/UnixFileSystem;", nullptr, $PRIVATE | $FINAL, $field(LinuxWatchService$Poller, fs)},
	{"watcher", "Lsun/nio/fs/LinuxWatchService;", nullptr, $PRIVATE | $FINAL, $field(LinuxWatchService$Poller, watcher)},
	{"ifd", "I", nullptr, $PRIVATE | $FINAL, $field(LinuxWatchService$Poller, ifd)},
	{"socketpair", "[I", nullptr, $PRIVATE | $FINAL, $field(LinuxWatchService$Poller, socketpair)},
	{"wdToKey", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/Integer;Lsun/nio/fs/LinuxWatchService$LinuxWatchKey;>;", $PRIVATE | $FINAL, $field(LinuxWatchService$Poller, wdToKey)},
	{"address", "J", nullptr, $PRIVATE | $FINAL, $field(LinuxWatchService$Poller, address)},
	{}
};

$MethodInfo _LinuxWatchService$Poller_MethodInfo_[] = {
	{"<init>", "(Lsun/nio/fs/UnixFileSystem;Lsun/nio/fs/LinuxWatchService;I[I)V", nullptr, 0, $method(LinuxWatchService$Poller, init$, void, $UnixFileSystem*, $LinuxWatchService*, int32_t, $ints*)},
	{"implCancelKey", "(Ljava/nio/file/WatchKey;)V", nullptr, 0, $virtualMethod(LinuxWatchService$Poller, implCancelKey, void, $WatchKey*)},
	{"implCloseAll", "()V", nullptr, 0, $virtualMethod(LinuxWatchService$Poller, implCloseAll, void)},
	{"implRegister", "(Ljava/nio/file/Path;Ljava/util/Set;[Ljava/nio/file/WatchEvent$Modifier;)Ljava/lang/Object;", "(Ljava/nio/file/Path;Ljava/util/Set<+Ljava/nio/file/WatchEvent$Kind<*>;>;[Ljava/nio/file/WatchEvent$Modifier;)Ljava/lang/Object;", $TRANSIENT, $virtualMethod(LinuxWatchService$Poller, implRegister, $Object*, $Path*, $Set*, $WatchEvent$ModifierArray*)},
	{"maskToEventKind", "(I)Ljava/nio/file/WatchEvent$Kind;", "(I)Ljava/nio/file/WatchEvent$Kind<*>;", $PRIVATE, $method(LinuxWatchService$Poller, maskToEventKind, $WatchEvent$Kind*, int32_t)},
	{"processEvent", "(IILsun/nio/fs/UnixPath;)V", nullptr, $PRIVATE, $method(LinuxWatchService$Poller, processEvent, void, int32_t, int32_t, $UnixPath*)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(LinuxWatchService$Poller, run, void)},
	{"wakeup", "()V", nullptr, 0, $virtualMethod(LinuxWatchService$Poller, wakeup, void), "java.io.IOException"},
	{}
};

$InnerClassInfo _LinuxWatchService$Poller_InnerClassesInfo_[] = {
	{"sun.nio.fs.LinuxWatchService$Poller", "sun.nio.fs.LinuxWatchService", "Poller", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _LinuxWatchService$Poller_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.fs.LinuxWatchService$Poller",
	"sun.nio.fs.AbstractPoller",
	nullptr,
	_LinuxWatchService$Poller_FieldInfo_,
	_LinuxWatchService$Poller_MethodInfo_,
	nullptr,
	nullptr,
	_LinuxWatchService$Poller_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.nio.fs.LinuxWatchService"
};

$Object* allocate$LinuxWatchService$Poller($Class* clazz) {
	return $of($alloc(LinuxWatchService$Poller));
}

int32_t LinuxWatchService$Poller::SIZEOF_INOTIFY_EVENT = 0;
$ints* LinuxWatchService$Poller::offsets = nullptr;
int32_t LinuxWatchService$Poller::OFFSETOF_WD = 0;
int32_t LinuxWatchService$Poller::OFFSETOF_MASK = 0;
int32_t LinuxWatchService$Poller::OFFSETOF_LEN = 0;
int32_t LinuxWatchService$Poller::OFFSETOF_NAME = 0;

void LinuxWatchService$Poller::init$($UnixFileSystem* fs, $LinuxWatchService* watcher, int32_t ifd, $ints* sp) {
	$AbstractPoller::init$();
	$set(this, fs, fs);
	$set(this, watcher, watcher);
	this->ifd = ifd;
	$set(this, socketpair, sp);
	$set(this, wdToKey, $new($HashMap));
	$init($LinuxWatchService);
	this->address = $nc($LinuxWatchService::unsafe)->allocateMemory(LinuxWatchService$Poller::BUFFER_SIZE);
}

void LinuxWatchService$Poller::wakeup() {
	try {
		$UnixNativeDispatcher::write($nc(this->socketpair)->get(1), this->address, 1);
	} catch ($UnixException& x) {
		$throwNew($IOException, $(x->errorString()));
	}
}

$Object* LinuxWatchService$Poller::implRegister($Path* obj, $Set* events, $WatchEvent$ModifierArray* modifiers) {
	$useLocalCurrentObjectStackCache();
	$var($UnixPath, dir, $cast($UnixPath, obj));
	int32_t mask = 0;
	{
		$var($Iterator, i$, $nc(events)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($WatchEvent$Kind, event, $cast($WatchEvent$Kind, i$->next()));
			{
				$init($StandardWatchEventKinds);
				if (event == $StandardWatchEventKinds::ENTRY_CREATE) {
					mask |= LinuxWatchService$Poller::IN_CREATE | LinuxWatchService$Poller::IN_MOVED_TO;
					continue;
				}
				if (event == $StandardWatchEventKinds::ENTRY_DELETE) {
					mask |= LinuxWatchService$Poller::IN_DELETE | LinuxWatchService$Poller::IN_MOVED_FROM;
					continue;
				}
				if (event == $StandardWatchEventKinds::ENTRY_MODIFY) {
					mask |= LinuxWatchService$Poller::IN_MODIFY | LinuxWatchService$Poller::IN_ATTRIB;
					continue;
				}
			}
		}
	}
	if ($nc(modifiers)->length > 0) {
		{
			$var($WatchEvent$ModifierArray, arr$, modifiers);
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($WatchEvent$Modifier, modifier, arr$->get(i$));
				{
					if (modifier == nullptr) {
						return $of($new($NullPointerException));
					}
					$init($ExtendedOptions);
					bool var$1 = !$nc($ExtendedOptions::SENSITIVITY_HIGH)->matches(modifier);
					bool var$0 = var$1 && !$nc($ExtendedOptions::SENSITIVITY_MEDIUM)->matches(modifier);
					if (var$0 && !$nc($ExtendedOptions::SENSITIVITY_LOW)->matches(modifier)) {
						return $of($new($UnsupportedOperationException, "Modifier not supported"_s));
					}
				}
			}
		}
	}
	$var($UnixFileAttributes, attrs, nullptr);
	try {
		$assign(attrs, $UnixFileAttributes::get(dir, true));
	} catch ($UnixException& x) {
		return $of(x->asIOException(dir));
	}
	if (!$nc(attrs)->isDirectory()) {
		return $of($new($NotDirectoryException, $($nc(dir)->getPathForExceptionMessage())));
	}
	int32_t wd = -1;
	try {
		$var($NativeBuffer, buffer, $NativeBuffers::asNativeBuffer($($nc(dir)->getByteArrayForSysCalls())));
		{
			$var($Throwable, var$2, nullptr);
			try {
				wd = $LinuxWatchService::inotifyAddWatch(this->ifd, $nc(buffer)->address(), mask);
			} catch ($Throwable& var$3) {
				$assign(var$2, var$3);
			} /*finally*/ {
				$nc(buffer)->release();
			}
			if (var$2 != nullptr) {
				$throw(var$2);
			}
		}
	} catch ($UnixException& x) {
		$init($UnixConstants);
		if (x->errno$() == $UnixConstants::ENOSPC) {
			return $of($new($IOException, "User limit of inotify watches reached"_s));
		}
		return $of(x->asIOException(dir));
	}
	$var($LinuxWatchService$LinuxWatchKey, key, $cast($LinuxWatchService$LinuxWatchKey, $nc(this->wdToKey)->get($($Integer::valueOf(wd)))));
	if (key == nullptr) {
		$assign(key, $new($LinuxWatchService$LinuxWatchKey, dir, this->watcher, this->ifd, wd));
		$nc(this->wdToKey)->put($($Integer::valueOf(wd)), key);
	}
	return $of(key);
}

void LinuxWatchService$Poller::implCancelKey($WatchKey* obj) {
	$useLocalCurrentObjectStackCache();
	$var($LinuxWatchService$LinuxWatchKey, key, $cast($LinuxWatchService$LinuxWatchKey, obj));
	if ($nc(key)->isValid()) {
		$nc(this->wdToKey)->remove($($Integer::valueOf(key->descriptor())));
		key->invalidate(true);
	}
}

void LinuxWatchService$Poller::implCloseAll() {
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc($($nc(this->wdToKey)->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
			{
				$nc(($cast($LinuxWatchService$LinuxWatchKey, $($nc(entry)->getValue()))))->invalidate(true);
			}
		}
	}
	$nc(this->wdToKey)->clear();
	$init($LinuxWatchService);
	$nc($LinuxWatchService::unsafe)->freeMemory(this->address);
	$UnixNativeDispatcher::close($nc(this->socketpair)->get(0));
	$UnixNativeDispatcher::close($nc(this->socketpair)->get(1));
	$UnixNativeDispatcher::close(this->ifd);
}

void LinuxWatchService$Poller::run() {
	$useLocalCurrentObjectStackCache();
	try {
		for (;;) {
			int32_t nReady = 0;
			int32_t bytesRead = 0;
			nReady = $LinuxWatchService::poll(this->ifd, $nc(this->socketpair)->get(0));
			try {
				bytesRead = $UnixNativeDispatcher::read(this->ifd, this->address, LinuxWatchService$Poller::BUFFER_SIZE);
			} catch ($UnixException& x) {
				$init($UnixConstants);
				bool var$0 = x->errno$() != $UnixConstants::EAGAIN;
				if (var$0 && x->errno$() != $UnixConstants::EWOULDBLOCK) {
					$throw(x);
				}
				bytesRead = 0;
			}
			int32_t offset = 0;
			while (offset < bytesRead) {
				int64_t event = this->address + offset;
				int32_t wd = $nc($LinuxWatchService::unsafe)->getInt(event + LinuxWatchService$Poller::OFFSETOF_WD);
				int32_t mask = $nc($LinuxWatchService::unsafe)->getInt(event + LinuxWatchService$Poller::OFFSETOF_MASK);
				int32_t len = $nc($LinuxWatchService::unsafe)->getInt(event + LinuxWatchService$Poller::OFFSETOF_LEN);
				$var($UnixPath, name, nullptr);
				if (len > 0) {
					int32_t actual = len;
					while (actual > 0) {
						int64_t last = event + LinuxWatchService$Poller::OFFSETOF_NAME + actual - 1;
						if ($nc($LinuxWatchService::unsafe)->getByte(last) != 0) {
							break;
						}
						--actual;
					}
					if (actual > 0) {
						$var($bytes, buf, $new($bytes, actual));
						$nc($LinuxWatchService::unsafe)->copyMemory(nullptr, event + LinuxWatchService$Poller::OFFSETOF_NAME, buf, $Unsafe::ARRAY_BYTE_BASE_OFFSET, actual);
						$assign(name, $new($UnixPath, this->fs, buf));
					}
				}
				processEvent(wd, mask, name);
				offset += (LinuxWatchService$Poller::SIZEOF_INOTIFY_EVENT + len);
			}
			if ((nReady > 1) || (nReady == 1 && bytesRead == 0)) {
				try {
					$UnixNativeDispatcher::read($nc(this->socketpair)->get(0), this->address, LinuxWatchService$Poller::BUFFER_SIZE);
					bool shutdown = processRequests();
					if (shutdown) {
						break;
					}
				} catch ($UnixException& x) {
					$init($UnixConstants);
					bool var$1 = x->errno$() != $UnixConstants::EAGAIN;
					if (var$1 && x->errno$() != $UnixConstants::EWOULDBLOCK) {
						$throw(x);
					}
				}
			}
		}
	} catch ($UnixException& x) {
		x->printStackTrace();
	}
}

$WatchEvent$Kind* LinuxWatchService$Poller::maskToEventKind(int32_t mask) {
	if (((int32_t)(mask & (uint32_t)LinuxWatchService$Poller::IN_MODIFY)) > 0) {
		$init($StandardWatchEventKinds);
		return $StandardWatchEventKinds::ENTRY_MODIFY;
	}
	if (((int32_t)(mask & (uint32_t)LinuxWatchService$Poller::IN_ATTRIB)) > 0) {
		$init($StandardWatchEventKinds);
		return $StandardWatchEventKinds::ENTRY_MODIFY;
	}
	if (((int32_t)(mask & (uint32_t)LinuxWatchService$Poller::IN_CREATE)) > 0) {
		$init($StandardWatchEventKinds);
		return $StandardWatchEventKinds::ENTRY_CREATE;
	}
	if (((int32_t)(mask & (uint32_t)LinuxWatchService$Poller::IN_MOVED_TO)) > 0) {
		$init($StandardWatchEventKinds);
		return $StandardWatchEventKinds::ENTRY_CREATE;
	}
	if (((int32_t)(mask & (uint32_t)LinuxWatchService$Poller::IN_DELETE)) > 0) {
		$init($StandardWatchEventKinds);
		return $StandardWatchEventKinds::ENTRY_DELETE;
	}
	if (((int32_t)(mask & (uint32_t)LinuxWatchService$Poller::IN_MOVED_FROM)) > 0) {
		$init($StandardWatchEventKinds);
		return $StandardWatchEventKinds::ENTRY_DELETE;
	}
	return nullptr;
}

void LinuxWatchService$Poller::processEvent(int32_t wd, int32_t mask, $UnixPath* name) {
	$useLocalCurrentObjectStackCache();
	if (((int32_t)(mask & (uint32_t)LinuxWatchService$Poller::IN_Q_OVERFLOW)) > 0) {
		{
			$var($Iterator, i$, $nc($($nc(this->wdToKey)->entrySet()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
				{
					$init($StandardWatchEventKinds);
					$nc(($cast($LinuxWatchService$LinuxWatchKey, $($nc(entry)->getValue()))))->signalEvent($StandardWatchEventKinds::OVERFLOW, nullptr);
				}
			}
		}
		return;
	}
	$var($LinuxWatchService$LinuxWatchKey, key, $cast($LinuxWatchService$LinuxWatchKey, $nc(this->wdToKey)->get($($Integer::valueOf(wd)))));
	if (key == nullptr) {
		return;
	}
	if (((int32_t)(mask & (uint32_t)LinuxWatchService$Poller::IN_IGNORED)) > 0) {
		$nc(this->wdToKey)->remove($($Integer::valueOf(wd)));
		$nc(key)->invalidate(false);
		key->signal();
		return;
	}
	if (name == nullptr) {
		return;
	}
	$var($WatchEvent$Kind, kind, maskToEventKind(mask));
	if (kind != nullptr) {
		$nc(key)->signalEvent(kind, name);
	}
}

void clinit$LinuxWatchService$Poller($Class* class$) {
	LinuxWatchService$Poller::SIZEOF_INOTIFY_EVENT = $LinuxWatchService::eventSize();
	$assignStatic(LinuxWatchService$Poller::offsets, $LinuxWatchService::eventOffsets());
	LinuxWatchService$Poller::OFFSETOF_WD = $nc(LinuxWatchService$Poller::offsets)->get(0);
	LinuxWatchService$Poller::OFFSETOF_MASK = $nc(LinuxWatchService$Poller::offsets)->get(1);
	LinuxWatchService$Poller::OFFSETOF_LEN = $nc(LinuxWatchService$Poller::offsets)->get(3);
	LinuxWatchService$Poller::OFFSETOF_NAME = $nc(LinuxWatchService$Poller::offsets)->get(4);
}

LinuxWatchService$Poller::LinuxWatchService$Poller() {
}

$Class* LinuxWatchService$Poller::load$($String* name, bool initialize) {
	$loadClass(LinuxWatchService$Poller, name, initialize, &_LinuxWatchService$Poller_ClassInfo_, clinit$LinuxWatchService$Poller, allocate$LinuxWatchService$Poller);
	return class$;
}

$Class* LinuxWatchService$Poller::class$ = nullptr;

		} // fs
	} // nio
} // sun