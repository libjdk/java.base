#include <sun/nio/fs/WindowsWatchService$Poller.h>

#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/nio/file/NotDirectoryException.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/StandardWatchEventKinds.h>
#include <java/nio/file/WatchEvent$Kind.h>
#include <java/nio/file/WatchEvent$Modifier.h>
#include <java/nio/file/WatchKey.h>
#include <java/util/Collection.h>
#include <java/util/HashMap.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/function/Consumer.h>
#include <jdk/internal/misc/Unsafe.h>
#include <sun/nio/fs/AbstractPoller.h>
#include <sun/nio/fs/AbstractWatchService.h>
#include <sun/nio/fs/ExtendedOptions$InternalOption.h>
#include <sun/nio/fs/ExtendedOptions.h>
#include <sun/nio/fs/NativeBuffer.h>
#include <sun/nio/fs/NativeBuffers.h>
#include <sun/nio/fs/WindowsException.h>
#include <sun/nio/fs/WindowsFileAttributes.h>
#include <sun/nio/fs/WindowsFileSystem.h>
#include <sun/nio/fs/WindowsNativeDispatcher$CompletionStatus.h>
#include <sun/nio/fs/WindowsNativeDispatcher.h>
#include <sun/nio/fs/WindowsPath.h>
#include <sun/nio/fs/WindowsWatchService$FileKey.h>
#include <sun/nio/fs/WindowsWatchService$WindowsWatchKey.h>
#include <sun/nio/fs/WindowsWatchService.h>
#include <jcpp.h>

#undef ARRAY_CHAR_BASE_OFFSET
#undef CHANGES_BUFFER_SIZE
#undef ENTRY_CREATE
#undef ENTRY_DELETE
#undef ENTRY_MODIFY
#undef FILE_TREE
#undef OFFSETOF_ACTION
#undef OFFSETOF_FILENAME
#undef OFFSETOF_FILENAMELENGTH
#undef OFFSETOF_HEVENT
#undef OFFSETOF_NEXTENTRYOFFSET
#undef OVERFLOW
#undef SENSITIVITY_HIGH
#undef SENSITIVITY_LOW
#undef SENSITIVITY_MEDIUM
#undef SIZEOF_DWORD
#undef SIZEOF_OVERLAPPED
#undef UNSAFE

using $WatchEvent$ModifierArray = $Array<::java::nio::file::WatchEvent$Modifier>;
using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $NotDirectoryException = ::java::nio::file::NotDirectoryException;
using $Path = ::java::nio::file::Path;
using $StandardWatchEventKinds = ::java::nio::file::StandardWatchEventKinds;
using $WatchEvent$Kind = ::java::nio::file::WatchEvent$Kind;
using $WatchEvent$Modifier = ::java::nio::file::WatchEvent$Modifier;
using $WatchKey = ::java::nio::file::WatchKey;
using $Collection = ::java::util::Collection;
using $HashMap = ::java::util::HashMap;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $Consumer = ::java::util::function::Consumer;
using $Unsafe = ::jdk::internal::misc::Unsafe;
using $AbstractPoller = ::sun::nio::fs::AbstractPoller;
using $AbstractWatchService = ::sun::nio::fs::AbstractWatchService;
using $ExtendedOptions = ::sun::nio::fs::ExtendedOptions;
using $ExtendedOptions$InternalOption = ::sun::nio::fs::ExtendedOptions$InternalOption;
using $NativeBuffer = ::sun::nio::fs::NativeBuffer;
using $NativeBuffers = ::sun::nio::fs::NativeBuffers;
using $WindowsException = ::sun::nio::fs::WindowsException;
using $WindowsFileAttributes = ::sun::nio::fs::WindowsFileAttributes;
using $WindowsFileSystem = ::sun::nio::fs::WindowsFileSystem;
using $WindowsNativeDispatcher = ::sun::nio::fs::WindowsNativeDispatcher;
using $WindowsNativeDispatcher$CompletionStatus = ::sun::nio::fs::WindowsNativeDispatcher$CompletionStatus;
using $WindowsPath = ::sun::nio::fs::WindowsPath;
using $WindowsWatchService = ::sun::nio::fs::WindowsWatchService;
using $WindowsWatchService$FileKey = ::sun::nio::fs::WindowsWatchService$FileKey;
using $WindowsWatchService$WindowsWatchKey = ::sun::nio::fs::WindowsWatchService$WindowsWatchKey;

namespace sun {
	namespace nio {
		namespace fs {

class WindowsWatchService$Poller$$Lambda$invalidate : public $Consumer {
	$class(WindowsWatchService$Poller$$Lambda$invalidate, $NO_CLASS_INIT, $Consumer)
public:
	void init$() {
	}
	virtual void accept(Object$* inst$) override {
		$sure($WindowsWatchService$WindowsWatchKey, inst$)->invalidate();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<WindowsWatchService$Poller$$Lambda$invalidate>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo WindowsWatchService$Poller$$Lambda$invalidate::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(WindowsWatchService$Poller$$Lambda$invalidate, init$, void)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(WindowsWatchService$Poller$$Lambda$invalidate, accept, void, Object$*)},
	{}
};
$ClassInfo WindowsWatchService$Poller$$Lambda$invalidate::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.nio.fs.WindowsWatchService$Poller$$Lambda$invalidate",
	"java.lang.Object",
	"java.util.function.Consumer",
	nullptr,
	methodInfos
};
$Class* WindowsWatchService$Poller$$Lambda$invalidate::load$($String* name, bool initialize) {
	$loadClass(WindowsWatchService$Poller$$Lambda$invalidate, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* WindowsWatchService$Poller$$Lambda$invalidate::class$ = nullptr;

$FieldInfo _WindowsWatchService$Poller_FieldInfo_[] = {
	{"UNSAFE", "Ljdk/internal/misc/Unsafe;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(WindowsWatchService$Poller, UNSAFE)},
	{"SIZEOF_DWORD", "S", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(WindowsWatchService$Poller, SIZEOF_DWORD)},
	{"SIZEOF_OVERLAPPED", "S", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(WindowsWatchService$Poller, SIZEOF_OVERLAPPED)},
	{"OFFSETOF_HEVENT", "S", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(WindowsWatchService$Poller, OFFSETOF_HEVENT)},
	{"OFFSETOF_NEXTENTRYOFFSET", "S", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(WindowsWatchService$Poller, OFFSETOF_NEXTENTRYOFFSET)},
	{"OFFSETOF_ACTION", "S", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(WindowsWatchService$Poller, OFFSETOF_ACTION)},
	{"OFFSETOF_FILENAMELENGTH", "S", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(WindowsWatchService$Poller, OFFSETOF_FILENAMELENGTH)},
	{"OFFSETOF_FILENAME", "S", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(WindowsWatchService$Poller, OFFSETOF_FILENAME)},
	{"CHANGES_BUFFER_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(WindowsWatchService$Poller, CHANGES_BUFFER_SIZE)},
	{"fs", "Lsun/nio/fs/WindowsFileSystem;", nullptr, $PRIVATE | $FINAL, $field(WindowsWatchService$Poller, fs)},
	{"watcher", "Lsun/nio/fs/WindowsWatchService;", nullptr, $PRIVATE | $FINAL, $field(WindowsWatchService$Poller, watcher)},
	{"port", "J", nullptr, $PRIVATE | $FINAL, $field(WindowsWatchService$Poller, port)},
	{"ck2key", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/Integer;Lsun/nio/fs/WindowsWatchService$WindowsWatchKey;>;", $PRIVATE | $FINAL, $field(WindowsWatchService$Poller, ck2key)},
	{"fk2key", "Ljava/util/Map;", "Ljava/util/Map<Lsun/nio/fs/WindowsWatchService$FileKey;Lsun/nio/fs/WindowsWatchService$WindowsWatchKey;>;", $PRIVATE | $FINAL, $field(WindowsWatchService$Poller, fk2key)},
	{"lastCompletionKey", "I", nullptr, $PRIVATE, $field(WindowsWatchService$Poller, lastCompletionKey)},
	{}
};

$MethodInfo _WindowsWatchService$Poller_MethodInfo_[] = {
	{"<init>", "(Lsun/nio/fs/WindowsFileSystem;Lsun/nio/fs/WindowsWatchService;J)V", nullptr, 0, $method(WindowsWatchService$Poller, init$, void, $WindowsFileSystem*, $WindowsWatchService*, int64_t)},
	{"closeAttachedEvent", "(J)V", nullptr, $PRIVATE, $method(WindowsWatchService$Poller, closeAttachedEvent, void, int64_t)},
	{"createAndAttachEvent", "(J)V", nullptr, $PRIVATE, $method(WindowsWatchService$Poller, createAndAttachEvent, void, int64_t), "sun.nio.fs.WindowsException"},
	{"implCancelKey", "(Ljava/nio/file/WatchKey;)V", nullptr, 0, $virtualMethod(WindowsWatchService$Poller, implCancelKey, void, $WatchKey*)},
	{"implCloseAll", "()V", nullptr, 0, $virtualMethod(WindowsWatchService$Poller, implCloseAll, void)},
	{"implRegister", "(Ljava/nio/file/Path;Ljava/util/Set;[Ljava/nio/file/WatchEvent$Modifier;)Ljava/lang/Object;", "(Ljava/nio/file/Path;Ljava/util/Set<+Ljava/nio/file/WatchEvent$Kind<*>;>;[Ljava/nio/file/WatchEvent$Modifier;)Ljava/lang/Object;", $TRANSIENT, $virtualMethod(WindowsWatchService$Poller, implRegister, $Object*, $Path*, $Set*, $WatchEvent$ModifierArray*)},
	{"processEvents", "(Lsun/nio/fs/WindowsWatchService$WindowsWatchKey;I)V", nullptr, $PRIVATE, $method(WindowsWatchService$Poller, processEvents, void, $WindowsWatchService$WindowsWatchKey*, int32_t)},
	{"releaseResources", "(Lsun/nio/fs/WindowsWatchService$WindowsWatchKey;)V", nullptr, $PRIVATE, $method(WindowsWatchService$Poller, releaseResources, void, $WindowsWatchService$WindowsWatchKey*)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(WindowsWatchService$Poller, run, void)},
	{"translateActionToEvent", "(I)Ljava/nio/file/WatchEvent$Kind;", "(I)Ljava/nio/file/WatchEvent$Kind<*>;", $PRIVATE, $method(WindowsWatchService$Poller, translateActionToEvent, $WatchEvent$Kind*, int32_t)},
	{"wakeup", "()V", nullptr, 0, $virtualMethod(WindowsWatchService$Poller, wakeup, void), "java.io.IOException"},
	{}
};

$InnerClassInfo _WindowsWatchService$Poller_InnerClassesInfo_[] = {
	{"sun.nio.fs.WindowsWatchService$Poller", "sun.nio.fs.WindowsWatchService", "Poller", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _WindowsWatchService$Poller_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.fs.WindowsWatchService$Poller",
	"sun.nio.fs.AbstractPoller",
	nullptr,
	_WindowsWatchService$Poller_FieldInfo_,
	_WindowsWatchService$Poller_MethodInfo_,
	nullptr,
	nullptr,
	_WindowsWatchService$Poller_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.nio.fs.WindowsWatchService"
};

$Object* allocate$WindowsWatchService$Poller($Class* clazz) {
	return $of($alloc(WindowsWatchService$Poller));
}

$Unsafe* WindowsWatchService$Poller::UNSAFE = nullptr;
int16_t WindowsWatchService$Poller::OFFSETOF_HEVENT = 0;

void WindowsWatchService$Poller::init$($WindowsFileSystem* fs, $WindowsWatchService* watcher, int64_t port) {
	$AbstractPoller::init$();
	$set(this, fs, fs);
	$set(this, watcher, watcher);
	this->port = port;
	$set(this, ck2key, $new($HashMap));
	$set(this, fk2key, $new($HashMap));
	this->lastCompletionKey = 0;
}

void WindowsWatchService$Poller::wakeup() {
	try {
		$WindowsNativeDispatcher::PostQueuedCompletionStatus(this->port, 0);
	} catch ($WindowsException& x) {
		$throwNew($IOException, $(x->getMessage()));
	}
}

$Object* WindowsWatchService$Poller::implRegister($Path* obj, $Set* events, $WatchEvent$ModifierArray* modifiers) {
	$useLocalCurrentObjectStackCache();
	$var($WindowsPath, dir, $cast($WindowsPath, obj));
	bool watchSubtree = false;
	{
		$var($WatchEvent$ModifierArray, arr$, modifiers);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($WatchEvent$Modifier, modifier, arr$->get(i$));
			{
				$init($ExtendedOptions);
				if ($nc($ExtendedOptions::FILE_TREE)->matches(modifier)) {
					watchSubtree = true;
				} else {
					if (modifier == nullptr) {
						return $of($new($NullPointerException));
					}
					bool var$1 = !$nc($ExtendedOptions::SENSITIVITY_HIGH)->matches(modifier);
					bool var$0 = var$1 && !$nc($ExtendedOptions::SENSITIVITY_MEDIUM)->matches(modifier);
					if (var$0 && !$nc($ExtendedOptions::SENSITIVITY_LOW)->matches(modifier)) {
						return $of($new($UnsupportedOperationException, "Modifier not supported"_s));
					}
				}
			}
		}
	}
	int64_t handle = 0;
	try {
		handle = $WindowsNativeDispatcher::CreateFile($($nc(dir)->getPathForWin32Calls()), 1, ((1 | 2) | 4), 3, 0x02000000 | 0x40000000);
	} catch ($WindowsException& x) {
		return $of(x->asIOException(dir));
	}
	bool registered = false;
	{
		$var($Throwable, var$2, nullptr);
		$var($Object, var$4, nullptr);
		bool return$3 = false;
		try {
			$var($WindowsFileAttributes, attrs, nullptr);
			try {
				$assign(attrs, $WindowsFileAttributes::readAttributes(handle));
			} catch ($WindowsException& x) {
				$assign(var$4, x->asIOException(dir));
				return$3 = true;
				goto $finally;
			}
			if (!$nc(attrs)->isDirectory()) {
				$assign(var$4, $new($NotDirectoryException, $($nc(dir)->getPathForExceptionMessage())));
				return$3 = true;
				goto $finally;
			}
			int32_t var$5 = $nc(attrs)->volSerialNumber();
			int32_t var$6 = attrs->fileIndexHigh();
			$var($WindowsWatchService$FileKey, fk, $new($WindowsWatchService$FileKey, var$5, var$6, attrs->fileIndexLow()));
			$var($WindowsWatchService$WindowsWatchKey, existing, $cast($WindowsWatchService$WindowsWatchKey, $nc(this->fk2key)->get(fk)));
			if (existing != nullptr && watchSubtree == existing->watchSubtree()) {
				existing->setEvents(events);
				$assign(var$4, existing);
				return$3 = true;
				goto $finally;
			}
			int32_t completionKey = ++this->lastCompletionKey;
			if (completionKey == 0) {
				completionKey = ++this->lastCompletionKey;
			}
			try {
				$WindowsNativeDispatcher::CreateIoCompletionPort(handle, this->port, completionKey);
			} catch ($WindowsException& x) {
				$assign(var$4, $new($IOException, $(x->getMessage())));
				return$3 = true;
				goto $finally;
			}
			int32_t size = WindowsWatchService$Poller::CHANGES_BUFFER_SIZE + WindowsWatchService$Poller::SIZEOF_DWORD + WindowsWatchService$Poller::SIZEOF_OVERLAPPED;
			$var($NativeBuffer, buffer, $NativeBuffers::getNativeBuffer(size));
			int64_t bufferAddress = $nc(buffer)->address();
			int64_t overlappedAddress = bufferAddress + size - WindowsWatchService$Poller::SIZEOF_OVERLAPPED;
			int64_t countAddress = overlappedAddress - WindowsWatchService$Poller::SIZEOF_DWORD;
			$nc(WindowsWatchService$Poller::UNSAFE)->setMemory(overlappedAddress, WindowsWatchService$Poller::SIZEOF_OVERLAPPED, (int8_t)0);
			try {
				createAndAttachEvent(overlappedAddress);
				$WindowsNativeDispatcher::ReadDirectoryChangesW(handle, bufferAddress, WindowsWatchService$Poller::CHANGES_BUFFER_SIZE, watchSubtree, 351, countAddress, overlappedAddress);
			} catch ($WindowsException& x) {
				closeAttachedEvent(overlappedAddress);
				buffer->release();
				$assign(var$4, $new($IOException, $(x->getMessage())));
				return$3 = true;
				goto $finally;
			}
			$var($WindowsWatchService$WindowsWatchKey, watchKey, nullptr);
			if (existing == nullptr) {
				$assign(watchKey, $$new($WindowsWatchService$WindowsWatchKey, dir, this->watcher, fk)->init(handle, events, watchSubtree, buffer, countAddress, overlappedAddress, completionKey));
				$nc(this->fk2key)->put(fk, watchKey);
			} else {
				$nc(this->ck2key)->remove($($Integer::valueOf($nc(existing)->completionKey())));
				releaseResources(existing);
				$assign(watchKey, $nc(existing)->init(handle, events, watchSubtree, buffer, countAddress, overlappedAddress, completionKey));
			}
			$nc(this->ck2key)->put($($Integer::valueOf(completionKey)), watchKey);
			registered = true;
			$assign(var$4, watchKey);
			return$3 = true;
			goto $finally;
		} catch ($Throwable& var$7) {
			$assign(var$2, var$7);
		} $finally: {
			if (!registered) {
				$WindowsNativeDispatcher::CloseHandle(handle);
			}
		}
		if (var$2 != nullptr) {
			$throw(var$2);
		}
		if (return$3) {
			return var$4;
		}
	}
	$shouldNotReachHere();
}

void WindowsWatchService$Poller::releaseResources($WindowsWatchService$WindowsWatchKey* key) {
	if (!$nc(key)->isErrorStartingOverlapped()) {
		try {
			$WindowsNativeDispatcher::CancelIo(key->handle());
			int64_t var$0 = key->handle();
			$WindowsNativeDispatcher::GetOverlappedResult(var$0, key->overlappedAddress());
		} catch ($WindowsException& expected) {
		}
	}
	$WindowsNativeDispatcher::CloseHandle($nc(key)->handle());
	closeAttachedEvent($nc(key)->overlappedAddress());
	$nc($($nc(key)->buffer()))->free();
}

void WindowsWatchService$Poller::createAndAttachEvent(int64_t ov) {
	int64_t hEvent = $WindowsNativeDispatcher::CreateEvent(false, false);
	$nc(WindowsWatchService$Poller::UNSAFE)->putAddress(ov + WindowsWatchService$Poller::OFFSETOF_HEVENT, hEvent);
}

void WindowsWatchService$Poller::closeAttachedEvent(int64_t ov) {
	int64_t hEvent = $nc(WindowsWatchService$Poller::UNSAFE)->getAddress(ov + WindowsWatchService$Poller::OFFSETOF_HEVENT);
	if (hEvent != 0 && hEvent != (int64_t)-1) {
		$WindowsNativeDispatcher::CloseHandle(hEvent);
	}
}

void WindowsWatchService$Poller::implCancelKey($WatchKey* obj) {
	$useLocalCurrentObjectStackCache();
	$var($WindowsWatchService$WindowsWatchKey, key, $cast($WindowsWatchService$WindowsWatchKey, obj));
	if ($nc(key)->isValid()) {
		$nc(this->fk2key)->remove($(key->fileKey()));
		$nc(this->ck2key)->remove($($Integer::valueOf(key->completionKey())));
		key->invalidate();
	}
}

void WindowsWatchService$Poller::implCloseAll() {
	$useLocalCurrentObjectStackCache();
	$nc($($nc(this->ck2key)->values()))->forEach(static_cast<$Consumer*>($$new(WindowsWatchService$Poller$$Lambda$invalidate)));
	$nc(this->fk2key)->clear();
	$nc(this->ck2key)->clear();
	$WindowsNativeDispatcher::CloseHandle(this->port);
}

$WatchEvent$Kind* WindowsWatchService$Poller::translateActionToEvent(int32_t action) {
	switch (action) {
	case 3:
		{
			$init($StandardWatchEventKinds);
			return $StandardWatchEventKinds::ENTRY_MODIFY;
		}
	case 1:
		{}
	case 5:
		{
			$init($StandardWatchEventKinds);
			return $StandardWatchEventKinds::ENTRY_CREATE;
		}
	case 2:
		{}
	case 4:
		{
			$init($StandardWatchEventKinds);
			return $StandardWatchEventKinds::ENTRY_DELETE;
		}
	default:
		{
			return nullptr;
		}
	}
}

void WindowsWatchService$Poller::processEvents($WindowsWatchService$WindowsWatchKey* key, int32_t size) {
	$useLocalCurrentObjectStackCache();
	int64_t address = $nc($($nc(key)->buffer()))->address();
	int32_t nextOffset = 0;
	do {
		int32_t action = $nc(WindowsWatchService$Poller::UNSAFE)->getInt(address + WindowsWatchService$Poller::OFFSETOF_ACTION);
		$var($WatchEvent$Kind, kind, translateActionToEvent(action));
		if ($nc($(key->events()))->contains(kind)) {
			int32_t nameLengthInBytes = $nc(WindowsWatchService$Poller::UNSAFE)->getInt(address + WindowsWatchService$Poller::OFFSETOF_FILENAMELENGTH);
			if ((nameLengthInBytes % 2) != 0) {
				$throwNew($AssertionError, $of("FileNameLength is not a multiple of 2"_s));
			}
			$var($chars, nameAsArray, $new($chars, nameLengthInBytes / 2));
			$nc(WindowsWatchService$Poller::UNSAFE)->copyMemory(nullptr, address + WindowsWatchService$Poller::OFFSETOF_FILENAME, nameAsArray, $Unsafe::ARRAY_CHAR_BASE_OFFSET, nameLengthInBytes);
			$var($WindowsPath, name, $WindowsPath::createFromNormalizedPath(this->fs, $$new($String, nameAsArray)));
			key->signalEvent(kind, name);
		}
		nextOffset = $nc(WindowsWatchService$Poller::UNSAFE)->getInt(address + WindowsWatchService$Poller::OFFSETOF_NEXTENTRYOFFSET);
		address += (int64_t)nextOffset;
	} while (nextOffset != 0);
}

void WindowsWatchService$Poller::run() {
	$useLocalCurrentObjectStackCache();
	for (;;) {
		$var($WindowsNativeDispatcher$CompletionStatus, info, nullptr);
		try {
			$assign(info, $WindowsNativeDispatcher::GetQueuedCompletionStatus(this->port));
		} catch ($WindowsException& x) {
			x->printStackTrace();
			return;
		}
		if ($nc(info)->completionKey() == 0) {
			bool shutdown = processRequests();
			if (shutdown) {
				return;
			}
			continue;
		}
		$var($WindowsWatchService$WindowsWatchKey, key, $cast($WindowsWatchService$WindowsWatchKey, $nc(this->ck2key)->get($($Integer::valueOf((int32_t)$nc(info)->completionKey())))));
		if (key == nullptr) {
			continue;
		}
		bool criticalError = false;
		int32_t errorCode = $nc(info)->error();
		int32_t messageSize = info->bytesTransferred();
		if (errorCode == 1022) {
			$init($StandardWatchEventKinds);
			$nc(key)->signalEvent($StandardWatchEventKinds::OVERFLOW, nullptr);
		} else if (errorCode != 0 && errorCode != 234) {
			criticalError = true;
		} else {
			if (messageSize > 0) {
				processEvents(key, messageSize);
			} else if (errorCode == 0) {
				$init($StandardWatchEventKinds);
				$nc(key)->signalEvent($StandardWatchEventKinds::OVERFLOW, nullptr);
			}
			try {
				int64_t var$0 = $nc(key)->handle();
				int64_t var$1 = $nc($(key->buffer()))->address();
				int32_t var$2 = WindowsWatchService$Poller::CHANGES_BUFFER_SIZE;
				bool var$3 = key->watchSubtree();
				int64_t var$4 = key->countAddress();
				$WindowsNativeDispatcher::ReadDirectoryChangesW(var$0, var$1, var$2, var$3, 351, var$4, key->overlappedAddress());
			} catch ($WindowsException& x) {
				criticalError = true;
				$nc(key)->setErrorStartingOverlapped(true);
			}
		}
		if (criticalError) {
			implCancelKey(key);
			$nc(key)->signal();
		}
	}
}

void clinit$WindowsWatchService$Poller($Class* class$) {
	$assignStatic(WindowsWatchService$Poller::UNSAFE, $Unsafe::getUnsafe());
	WindowsWatchService$Poller::OFFSETOF_HEVENT = ($nc(WindowsWatchService$Poller::UNSAFE)->addressSize() == 4) ? (int16_t)16 : (int16_t)24;
}

WindowsWatchService$Poller::WindowsWatchService$Poller() {
}

$Class* WindowsWatchService$Poller::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(WindowsWatchService$Poller$$Lambda$invalidate::classInfo$.name)) {
			return WindowsWatchService$Poller$$Lambda$invalidate::load$(name, initialize);
		}
	}
	$loadClass(WindowsWatchService$Poller, name, initialize, &_WindowsWatchService$Poller_ClassInfo_, clinit$WindowsWatchService$Poller, allocate$WindowsWatchService$Poller);
	return class$;
}

$Class* WindowsWatchService$Poller::class$ = nullptr;

		} // fs
	} // nio
} // sun