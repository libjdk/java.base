#include <java/nio/channels/AsynchronousFileChannel.h>

#include <java/nio/ByteBuffer.h>
#include <java/nio/channels/CompletionHandler.h>
#include <java/nio/channels/FileLock.h>
#include <java/nio/file/FileSystem.h>
#include <java/nio/file/OpenOption.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/attribute/FileAttribute.h>
#include <java/nio/file/spi/FileSystemProvider.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/HashSet.h>
#include <java/util/Set.h>
#include <java/util/concurrent/ExecutorService.h>
#include <java/util/concurrent/Future.h>
#include <jcpp.h>

#undef MAX_VALUE
#undef NO_ATTRIBUTES

using $OpenOptionArray = $Array<::java::nio::file::OpenOption>;
using $FileAttributeArray = $Array<::java::nio::file::attribute::FileAttribute>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $CompletionHandler = ::java::nio::channels::CompletionHandler;
using $FileLock = ::java::nio::channels::FileLock;
using $FileSystem = ::java::nio::file::FileSystem;
using $Path = ::java::nio::file::Path;
using $FileSystemProvider = ::java::nio::file::spi::FileSystemProvider;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $HashSet = ::java::util::HashSet;
using $Set = ::java::util::Set;
using $ExecutorService = ::java::util::concurrent::ExecutorService;
using $Future = ::java::util::concurrent::Future;

namespace java {
	namespace nio {
		namespace channels {

$FieldInfo _AsynchronousFileChannel_FieldInfo_[] = {
	{"NO_ATTRIBUTES", "[Ljava/nio/file/attribute/FileAttribute;", "[Ljava/nio/file/attribute/FileAttribute<*>;", $PRIVATE | $STATIC | $FINAL, $staticField(AsynchronousFileChannel, NO_ATTRIBUTES)},
	{}
};

$MethodInfo _AsynchronousFileChannel_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PROTECTED, $method(AsynchronousFileChannel, init$, void)},
	{"force", "(Z)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(AsynchronousFileChannel, force, void, bool), "java.io.IOException"},
	{"lock", "(JJZLjava/lang/Object;Ljava/nio/channels/CompletionHandler;)V", "<A:Ljava/lang/Object;>(JJZTA;Ljava/nio/channels/CompletionHandler<Ljava/nio/channels/FileLock;-TA;>;)V", $PUBLIC | $ABSTRACT, $virtualMethod(AsynchronousFileChannel, lock, void, int64_t, int64_t, bool, Object$*, $CompletionHandler*)},
	{"lock", "(Ljava/lang/Object;Ljava/nio/channels/CompletionHandler;)V", "<A:Ljava/lang/Object;>(TA;Ljava/nio/channels/CompletionHandler<Ljava/nio/channels/FileLock;-TA;>;)V", $PUBLIC | $FINAL, $method(AsynchronousFileChannel, lock, void, Object$*, $CompletionHandler*)},
	{"lock", "(JJZ)Ljava/util/concurrent/Future;", "(JJZ)Ljava/util/concurrent/Future<Ljava/nio/channels/FileLock;>;", $PUBLIC | $ABSTRACT, $virtualMethod(AsynchronousFileChannel, lock, $Future*, int64_t, int64_t, bool)},
	{"lock", "()Ljava/util/concurrent/Future;", "()Ljava/util/concurrent/Future<Ljava/nio/channels/FileLock;>;", $PUBLIC | $FINAL, $method(AsynchronousFileChannel, lock, $Future*)},
	{"open", "(Ljava/nio/file/Path;Ljava/util/Set;Ljava/util/concurrent/ExecutorService;[Ljava/nio/file/attribute/FileAttribute;)Ljava/nio/channels/AsynchronousFileChannel;", "(Ljava/nio/file/Path;Ljava/util/Set<+Ljava/nio/file/OpenOption;>;Ljava/util/concurrent/ExecutorService;[Ljava/nio/file/attribute/FileAttribute<*>;)Ljava/nio/channels/AsynchronousFileChannel;", $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(AsynchronousFileChannel, open, AsynchronousFileChannel*, $Path*, $Set*, $ExecutorService*, $FileAttributeArray*), "java.io.IOException"},
	{"open", "(Ljava/nio/file/Path;[Ljava/nio/file/OpenOption;)Ljava/nio/channels/AsynchronousFileChannel;", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(AsynchronousFileChannel, open, AsynchronousFileChannel*, $Path*, $OpenOptionArray*), "java.io.IOException"},
	{"read", "(Ljava/nio/ByteBuffer;JLjava/lang/Object;Ljava/nio/channels/CompletionHandler;)V", "<A:Ljava/lang/Object;>(Ljava/nio/ByteBuffer;JTA;Ljava/nio/channels/CompletionHandler<Ljava/lang/Integer;-TA;>;)V", $PUBLIC | $ABSTRACT, $virtualMethod(AsynchronousFileChannel, read, void, $ByteBuffer*, int64_t, Object$*, $CompletionHandler*)},
	{"read", "(Ljava/nio/ByteBuffer;J)Ljava/util/concurrent/Future;", "(Ljava/nio/ByteBuffer;J)Ljava/util/concurrent/Future<Ljava/lang/Integer;>;", $PUBLIC | $ABSTRACT, $virtualMethod(AsynchronousFileChannel, read, $Future*, $ByteBuffer*, int64_t)},
	{"size", "()J", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(AsynchronousFileChannel, size, int64_t), "java.io.IOException"},
	{"truncate", "(J)Ljava/nio/channels/AsynchronousFileChannel;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(AsynchronousFileChannel, truncate, AsynchronousFileChannel*, int64_t), "java.io.IOException"},
	{"tryLock", "(JJZ)Ljava/nio/channels/FileLock;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(AsynchronousFileChannel, tryLock, $FileLock*, int64_t, int64_t, bool), "java.io.IOException"},
	{"tryLock", "()Ljava/nio/channels/FileLock;", nullptr, $PUBLIC | $FINAL, $method(AsynchronousFileChannel, tryLock, $FileLock*), "java.io.IOException"},
	{"write", "(Ljava/nio/ByteBuffer;JLjava/lang/Object;Ljava/nio/channels/CompletionHandler;)V", "<A:Ljava/lang/Object;>(Ljava/nio/ByteBuffer;JTA;Ljava/nio/channels/CompletionHandler<Ljava/lang/Integer;-TA;>;)V", $PUBLIC | $ABSTRACT, $virtualMethod(AsynchronousFileChannel, write, void, $ByteBuffer*, int64_t, Object$*, $CompletionHandler*)},
	{"write", "(Ljava/nio/ByteBuffer;J)Ljava/util/concurrent/Future;", "(Ljava/nio/ByteBuffer;J)Ljava/util/concurrent/Future<Ljava/lang/Integer;>;", $PUBLIC | $ABSTRACT, $virtualMethod(AsynchronousFileChannel, write, $Future*, $ByteBuffer*, int64_t)},
	{}
};

$ClassInfo _AsynchronousFileChannel_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"java.nio.channels.AsynchronousFileChannel",
	"java.lang.Object",
	"java.nio.channels.AsynchronousChannel",
	_AsynchronousFileChannel_FieldInfo_,
	_AsynchronousFileChannel_MethodInfo_
};

$Object* allocate$AsynchronousFileChannel($Class* clazz) {
	return $of($alloc(AsynchronousFileChannel));
}

$FileAttributeArray* AsynchronousFileChannel::NO_ATTRIBUTES = nullptr;

void AsynchronousFileChannel::init$() {
}

AsynchronousFileChannel* AsynchronousFileChannel::open($Path* file, $Set* options, $ExecutorService* executor, $FileAttributeArray* attrs) {
	$init(AsynchronousFileChannel);
	$useLocalCurrentObjectStackCache();
	$var($FileSystemProvider, provider, $nc($($nc(file)->getFileSystem()))->provider());
	return $nc(provider)->newAsynchronousFileChannel(file, options, executor, attrs);
}

AsynchronousFileChannel* AsynchronousFileChannel::open($Path* file, $OpenOptionArray* options) {
	$init(AsynchronousFileChannel);
	$var($Set, set, nullptr);
	if ($nc(options)->length == 0) {
		$assign(set, $Collections::emptySet());
	} else {
		$assign(set, $new($HashSet));
		$Collections::addAll(set, options);
	}
	return open(file, set, nullptr, AsynchronousFileChannel::NO_ATTRIBUTES);
}

void AsynchronousFileChannel::lock(Object$* attachment, $CompletionHandler* handler) {
	lock(0, $Long::MAX_VALUE, false, attachment, handler);
}

$Future* AsynchronousFileChannel::lock() {
	return lock(0, $Long::MAX_VALUE, false);
}

$FileLock* AsynchronousFileChannel::tryLock() {
	return tryLock(0, $Long::MAX_VALUE, false);
}

void clinit$AsynchronousFileChannel($Class* class$) {
	$assignStatic(AsynchronousFileChannel::NO_ATTRIBUTES, $new($FileAttributeArray, 0));
}

AsynchronousFileChannel::AsynchronousFileChannel() {
}

$Class* AsynchronousFileChannel::load$($String* name, bool initialize) {
	$loadClass(AsynchronousFileChannel, name, initialize, &_AsynchronousFileChannel_ClassInfo_, clinit$AsynchronousFileChannel, allocate$AsynchronousFileChannel);
	return class$;
}

$Class* AsynchronousFileChannel::class$ = nullptr;

		} // channels
	} // nio
} // java