#include <sun/nio/ch/FileChannelImpl.h>

#include <java/io/Closeable.h>
#include <java/io/FileDescriptor.h>
#include <java/io/IOException.h>
#include <java/io/UncheckedIOException.h>
#include <java/lang/AssertionError.h>
#include <java/lang/InterruptedException.h>
#include <java/lang/Math.h>
#include <java/lang/OutOfMemoryError.h>
#include <java/lang/Runnable.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/lang/ref/Cleaner$Cleanable.h>
#include <java/lang/ref/Cleaner.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/MappedByteBuffer.h>
#include <java/nio/channels/Channel.h>
#include <java/nio/channels/ClosedByInterruptException.h>
#include <java/nio/channels/ClosedChannelException.h>
#include <java/nio/channels/FileChannel$MapMode.h>
#include <java/nio/channels/FileChannel.h>
#include <java/nio/channels/FileLock.h>
#include <java/nio/channels/FileLockInterruptionException.h>
#include <java/nio/channels/InterruptibleChannel.h>
#include <java/nio/channels/NonReadableChannelException.h>
#include <java/nio/channels/NonWritableChannelException.h>
#include <java/nio/channels/ReadableByteChannel.h>
#include <java/nio/channels/SeekableByteChannel.h>
#include <java/nio/channels/SelectableChannel.h>
#include <java/nio/channels/WritableByteChannel.h>
#include <java/nio/channels/spi/AbstractInterruptibleChannel.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <jdk/internal/access/JavaIOFileDescriptorAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jdk/internal/misc/ExtendedMapMode.h>
#include <jdk/internal/misc/Unsafe.h>
#include <jdk/internal/misc/VM$BufferPool.h>
#include <jdk/internal/misc/VM.h>
#include <jdk/internal/ref/Cleaner.h>
#include <jdk/internal/ref/CleanerFactory.h>
#include <sun/nio/ch/DirectBuffer.h>
#include <sun/nio/ch/FileChannelImpl$1.h>
#include <sun/nio/ch/FileChannelImpl$2.h>
#include <sun/nio/ch/FileChannelImpl$Closer.h>
#include <sun/nio/ch/FileChannelImpl$DefaultUnmapper.h>
#include <sun/nio/ch/FileChannelImpl$SyncUnmapper.h>
#include <sun/nio/ch/FileChannelImpl$Unmapper.h>
#include <sun/nio/ch/FileDispatcher.h>
#include <sun/nio/ch/FileDispatcherImpl.h>
#include <sun/nio/ch/FileLockImpl.h>
#include <sun/nio/ch/FileLockTable.h>
#include <sun/nio/ch/IOStatus.h>
#include <sun/nio/ch/IOUtil.h>
#include <sun/nio/ch/NativeDispatcher.h>
#include <sun/nio/ch/NativeThreadSet.h>
#include <sun/nio/ch/SelChImpl.h>
#include <sun/nio/ch/SinkChannelImpl.h>
#include <sun/nio/ch/Util.h>
#include <jcpp.h>

#undef INTERRUPTED
#undef MAPPED_TRANSFER_SIZE
#undef MAP_INVALID
#undef MAP_PV
#undef MAP_RO
#undef MAP_RW
#undef MAX_VALUE
#undef NO_LOCK
#undef PRIVATE
#undef READ_ONLY
#undef READ_ONLY_SYNC
#undef READ_WRITE
#undef READ_WRITE_SYNC
#undef RET_EX_LOCK
#undef TRANSFER_SIZE
#undef UNSUPPORTED
#undef UNSUPPORTED_CASE

using $ByteBufferArray = $Array<::java::nio::ByteBuffer>;
using $Closeable = ::java::io::Closeable;
using $FileDescriptor = ::java::io::FileDescriptor;
using $IOException = ::java::io::IOException;
using $UncheckedIOException = ::java::io::UncheckedIOException;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InterruptedException = ::java::lang::InterruptedException;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $OutOfMemoryError = ::java::lang::OutOfMemoryError;
using $Runnable = ::java::lang::Runnable;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $Cleaner = ::java::lang::ref::Cleaner;
using $Cleaner$Cleanable = ::java::lang::ref::Cleaner$Cleanable;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $MappedByteBuffer = ::java::nio::MappedByteBuffer;
using $Channel = ::java::nio::channels::Channel;
using $ClosedByInterruptException = ::java::nio::channels::ClosedByInterruptException;
using $ClosedChannelException = ::java::nio::channels::ClosedChannelException;
using $FileChannel = ::java::nio::channels::FileChannel;
using $FileChannel$MapMode = ::java::nio::channels::FileChannel$MapMode;
using $FileLock = ::java::nio::channels::FileLock;
using $FileLockInterruptionException = ::java::nio::channels::FileLockInterruptionException;
using $InterruptibleChannel = ::java::nio::channels::InterruptibleChannel;
using $NonReadableChannelException = ::java::nio::channels::NonReadableChannelException;
using $NonWritableChannelException = ::java::nio::channels::NonWritableChannelException;
using $ReadableByteChannel = ::java::nio::channels::ReadableByteChannel;
using $SeekableByteChannel = ::java::nio::channels::SeekableByteChannel;
using $SelectableChannel = ::java::nio::channels::SelectableChannel;
using $WritableByteChannel = ::java::nio::channels::WritableByteChannel;
using $AbstractInterruptibleChannel = ::java::nio::channels::spi::AbstractInterruptibleChannel;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $JavaIOFileDescriptorAccess = ::jdk::internal::access::JavaIOFileDescriptorAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $ExtendedMapMode = ::jdk::internal::misc::ExtendedMapMode;
using $Unsafe = ::jdk::internal::misc::Unsafe;
using $VM = ::jdk::internal::misc::VM;
using $VM$BufferPool = ::jdk::internal::misc::VM$BufferPool;
using $1Cleaner = ::jdk::internal::ref::Cleaner;
using $CleanerFactory = ::jdk::internal::ref::CleanerFactory;
using $DirectBuffer = ::sun::nio::ch::DirectBuffer;
using $FileChannelImpl$1 = ::sun::nio::ch::FileChannelImpl$1;
using $FileChannelImpl$2 = ::sun::nio::ch::FileChannelImpl$2;
using $FileChannelImpl$Closer = ::sun::nio::ch::FileChannelImpl$Closer;
using $FileChannelImpl$DefaultUnmapper = ::sun::nio::ch::FileChannelImpl$DefaultUnmapper;
using $FileChannelImpl$SyncUnmapper = ::sun::nio::ch::FileChannelImpl$SyncUnmapper;
using $FileChannelImpl$Unmapper = ::sun::nio::ch::FileChannelImpl$Unmapper;
using $FileDispatcher = ::sun::nio::ch::FileDispatcher;
using $FileDispatcherImpl = ::sun::nio::ch::FileDispatcherImpl;
using $FileLockImpl = ::sun::nio::ch::FileLockImpl;
using $FileLockTable = ::sun::nio::ch::FileLockTable;
using $IOStatus = ::sun::nio::ch::IOStatus;
using $IOUtil = ::sun::nio::ch::IOUtil;
using $NativeDispatcher = ::sun::nio::ch::NativeDispatcher;
using $NativeThreadSet = ::sun::nio::ch::NativeThreadSet;
using $SelChImpl = ::sun::nio::ch::SelChImpl;
using $SinkChannelImpl = ::sun::nio::ch::SinkChannelImpl;
using $Util = ::sun::nio::ch::Util;

namespace sun {
	namespace nio {
		namespace ch {

$FieldInfo _FileChannelImpl_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(FileChannelImpl, $assertionsDisabled)},
	{"allocationGranularity", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(FileChannelImpl, allocationGranularity)},
	{"fdAccess", "Ljdk/internal/access/JavaIOFileDescriptorAccess;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(FileChannelImpl, fdAccess)},
	{"nd", "Lsun/nio/ch/FileDispatcher;", nullptr, $PRIVATE | $FINAL, $field(FileChannelImpl, nd)},
	{"fd", "Ljava/io/FileDescriptor;", nullptr, $PRIVATE | $FINAL, $field(FileChannelImpl, fd)},
	{"writable", "Z", nullptr, $PRIVATE | $FINAL, $field(FileChannelImpl, writable)},
	{"readable", "Z", nullptr, $PRIVATE | $FINAL, $field(FileChannelImpl, readable)},
	{"parent", "Ljava/lang/Object;", nullptr, $PRIVATE | $FINAL, $field(FileChannelImpl, parent)},
	{"path", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(FileChannelImpl, path)},
	{"threads", "Lsun/nio/ch/NativeThreadSet;", nullptr, $PRIVATE | $FINAL, $field(FileChannelImpl, threads)},
	{"positionLock", "Ljava/lang/Object;", nullptr, $PRIVATE | $FINAL, $field(FileChannelImpl, positionLock)},
	{"uninterruptible", "Z", nullptr, $PRIVATE | $VOLATILE, $field(FileChannelImpl, uninterruptible)},
	{"direct", "Z", nullptr, $PRIVATE | $FINAL, $field(FileChannelImpl, direct)},
	{"alignment", "I", nullptr, $PRIVATE | $FINAL, $field(FileChannelImpl, alignment)},
	{"closer", "Ljava/lang/ref/Cleaner$Cleanable;", nullptr, $PRIVATE | $FINAL, $field(FileChannelImpl, closer)},
	{"transferSupported", "Z", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(FileChannelImpl, transferSupported)},
	{"pipeSupported", "Z", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(FileChannelImpl, pipeSupported)},
	{"fileSupported", "Z", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(FileChannelImpl, fileSupported)},
	{"MAPPED_TRANSFER_SIZE", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(FileChannelImpl, MAPPED_TRANSFER_SIZE)},
	{"TRANSFER_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(FileChannelImpl, TRANSFER_SIZE)},
	{"MAP_INVALID", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(FileChannelImpl, MAP_INVALID)},
	{"MAP_RO", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(FileChannelImpl, MAP_RO)},
	{"MAP_RW", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(FileChannelImpl, MAP_RW)},
	{"MAP_PV", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(FileChannelImpl, MAP_PV)},
	{"fileLockTable", "Lsun/nio/ch/FileLockTable;", nullptr, $PRIVATE | $VOLATILE, $field(FileChannelImpl, fileLockTable$)},
	{}
};

$MethodInfo _FileChannelImpl_MethodInfo_[] = {
	{"<init>", "(Ljava/io/FileDescriptor;Ljava/lang/String;ZZZLjava/lang/Object;)V", nullptr, $PRIVATE, $method(FileChannelImpl, init$, void, $FileDescriptor*, $String*, bool, bool, bool, Object$*)},
	{"beginBlocking", "()V", nullptr, $PRIVATE, $method(FileChannelImpl, beginBlocking, void)},
	{"checkMode", "(Ljava/nio/channels/FileChannel$MapMode;IZ)V", nullptr, $PRIVATE, $method(FileChannelImpl, checkMode, void, $FileChannel$MapMode*, int32_t, bool)},
	{"endBlocking", "(Z)V", nullptr, $PRIVATE, $method(FileChannelImpl, endBlocking, void, bool), "java.nio.channels.AsynchronousCloseException"},
	{"ensureOpen", "()V", nullptr, $PRIVATE, $method(FileChannelImpl, ensureOpen, void), "java.io.IOException"},
	{"fileLockTable", "()Lsun/nio/ch/FileLockTable;", nullptr, $PRIVATE, $method(FileChannelImpl, fileLockTable, $FileLockTable*), "java.io.IOException"},
	{"force", "(Z)V", nullptr, $PUBLIC, $virtualMethod(FileChannelImpl, force, void, bool), "java.io.IOException"},
	{"getMappedBufferPool", "()Ljdk/internal/misc/VM$BufferPool;", nullptr, $PUBLIC | $STATIC, $staticMethod(FileChannelImpl, getMappedBufferPool, $VM$BufferPool*)},
	{"getSyncMappedBufferPool", "()Ljdk/internal/misc/VM$BufferPool;", nullptr, $PUBLIC | $STATIC, $staticMethod(FileChannelImpl, getSyncMappedBufferPool, $VM$BufferPool*)},
	{"implCloseChannel", "()V", nullptr, $PROTECTED, $virtualMethod(FileChannelImpl, implCloseChannel, void), "java.io.IOException"},
	{"initIDs", "()J", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(FileChannelImpl, initIDs, int64_t)},
	{"isSync", "(Ljava/nio/channels/FileChannel$MapMode;)Z", nullptr, $PRIVATE, $method(FileChannelImpl, isSync, bool, $FileChannel$MapMode*)},
	{"lock", "(JJZ)Ljava/nio/channels/FileLock;", nullptr, $PUBLIC, $virtualMethod(FileChannelImpl, lock, $FileLock*, int64_t, int64_t, bool), "java.io.IOException"},
	{"map", "(Ljava/nio/channels/FileChannel$MapMode;JJ)Ljava/nio/MappedByteBuffer;", nullptr, $PUBLIC, $virtualMethod(FileChannelImpl, map, $MappedByteBuffer*, $FileChannel$MapMode*, int64_t, int64_t), "java.io.IOException"},
	{"map0", "(IJJZ)J", nullptr, $PRIVATE | $NATIVE, $method(FileChannelImpl, map0, int64_t, int32_t, int64_t, int64_t, bool), "java.io.IOException"},
	{"mapInternal", "(Ljava/nio/channels/FileChannel$MapMode;JJ)Lsun/nio/ch/FileChannelImpl$Unmapper;", nullptr, $PUBLIC, $virtualMethod(FileChannelImpl, mapInternal, $FileChannelImpl$Unmapper*, $FileChannel$MapMode*, int64_t, int64_t), "java.io.IOException"},
	{"mapInternal", "(Ljava/nio/channels/FileChannel$MapMode;JJIZ)Lsun/nio/ch/FileChannelImpl$Unmapper;", nullptr, $PRIVATE, $method(FileChannelImpl, mapInternal, $FileChannelImpl$Unmapper*, $FileChannel$MapMode*, int64_t, int64_t, int32_t, bool), "java.io.IOException"},
	{"open", "(Ljava/io/FileDescriptor;Ljava/lang/String;ZZZLjava/lang/Object;)Ljava/nio/channels/FileChannel;", nullptr, $PUBLIC | $STATIC, $staticMethod(FileChannelImpl, open, $FileChannel*, $FileDescriptor*, $String*, bool, bool, bool, Object$*)},
	{"position", "()J", nullptr, $PUBLIC, $virtualMethod(FileChannelImpl, position, int64_t), "java.io.IOException"},
	{"position", "(J)Ljava/nio/channels/FileChannel;", nullptr, $PUBLIC, $virtualMethod(FileChannelImpl, position, $SeekableByteChannel*, int64_t), "java.io.IOException"},
	{"read", "(Ljava/nio/ByteBuffer;)I", nullptr, $PUBLIC, $virtualMethod(FileChannelImpl, read, int32_t, $ByteBuffer*), "java.io.IOException"},
	{"read", "([Ljava/nio/ByteBuffer;II)J", nullptr, $PUBLIC, $virtualMethod(FileChannelImpl, read, int64_t, $ByteBufferArray*, int32_t, int32_t), "java.io.IOException"},
	{"read", "(Ljava/nio/ByteBuffer;J)I", nullptr, $PUBLIC, $virtualMethod(FileChannelImpl, read, int32_t, $ByteBuffer*, int64_t), "java.io.IOException"},
	{"readInternal", "(Ljava/nio/ByteBuffer;J)I", nullptr, $PRIVATE, $method(FileChannelImpl, readInternal, int32_t, $ByteBuffer*, int64_t), "java.io.IOException"},
	{"release", "(Lsun/nio/ch/FileLockImpl;)V", nullptr, 0, $virtualMethod(FileChannelImpl, release, void, $FileLockImpl*), "java.io.IOException"},
	{"setUninterruptible", "()V", nullptr, $PUBLIC, $virtualMethod(FileChannelImpl, setUninterruptible, void)},
	{"size", "()J", nullptr, $PUBLIC, $virtualMethod(FileChannelImpl, size, int64_t), "java.io.IOException"},
	{"toProt", "(Ljava/nio/channels/FileChannel$MapMode;)I", nullptr, $PRIVATE, $method(FileChannelImpl, toProt, int32_t, $FileChannel$MapMode*)},
	{"transferFrom", "(Ljava/nio/channels/ReadableByteChannel;JJ)J", nullptr, $PUBLIC, $virtualMethod(FileChannelImpl, transferFrom, int64_t, $ReadableByteChannel*, int64_t, int64_t), "java.io.IOException"},
	{"transferFromArbitraryChannel", "(Ljava/nio/channels/ReadableByteChannel;JJ)J", nullptr, $PRIVATE, $method(FileChannelImpl, transferFromArbitraryChannel, int64_t, $ReadableByteChannel*, int64_t, int64_t), "java.io.IOException"},
	{"transferFromFileChannel", "(Lsun/nio/ch/FileChannelImpl;JJ)J", nullptr, $PRIVATE, $method(FileChannelImpl, transferFromFileChannel, int64_t, FileChannelImpl*, int64_t, int64_t), "java.io.IOException"},
	{"transferTo", "(JJLjava/nio/channels/WritableByteChannel;)J", nullptr, $PUBLIC, $virtualMethod(FileChannelImpl, transferTo, int64_t, int64_t, int64_t, $WritableByteChannel*), "java.io.IOException"},
	{"transferTo0", "(Ljava/io/FileDescriptor;JJLjava/io/FileDescriptor;)J", nullptr, $PRIVATE | $NATIVE, $method(FileChannelImpl, transferTo0, int64_t, $FileDescriptor*, int64_t, int64_t, $FileDescriptor*)},
	{"transferToArbitraryChannel", "(JILjava/nio/channels/WritableByteChannel;)J", nullptr, $PRIVATE, $method(FileChannelImpl, transferToArbitraryChannel, int64_t, int64_t, int32_t, $WritableByteChannel*), "java.io.IOException"},
	{"transferToDirectly", "(JILjava/nio/channels/WritableByteChannel;)J", nullptr, $PRIVATE, $method(FileChannelImpl, transferToDirectly, int64_t, int64_t, int32_t, $WritableByteChannel*), "java.io.IOException"},
	{"transferToDirectlyInternal", "(JILjava/nio/channels/WritableByteChannel;Ljava/io/FileDescriptor;)J", nullptr, $PRIVATE, $method(FileChannelImpl, transferToDirectlyInternal, int64_t, int64_t, int32_t, $WritableByteChannel*, $FileDescriptor*), "java.io.IOException"},
	{"transferToTrustedChannel", "(JJLjava/nio/channels/WritableByteChannel;)J", nullptr, $PRIVATE, $method(FileChannelImpl, transferToTrustedChannel, int64_t, int64_t, int64_t, $WritableByteChannel*), "java.io.IOException"},
	{"truncate", "(J)Ljava/nio/channels/FileChannel;", nullptr, $PUBLIC, $virtualMethod(FileChannelImpl, truncate, $SeekableByteChannel*, int64_t), "java.io.IOException"},
	{"tryLock", "(JJZ)Ljava/nio/channels/FileLock;", nullptr, $PUBLIC, $virtualMethod(FileChannelImpl, tryLock, $FileLock*, int64_t, int64_t, bool), "java.io.IOException"},
	{"unmap", "(Ljava/nio/MappedByteBuffer;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(FileChannelImpl, unmap, void, $MappedByteBuffer*)},
	{"unmap0", "(JJ)I", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(FileChannelImpl, unmap0, int32_t, int64_t, int64_t)},
	{"write", "(Ljava/nio/ByteBuffer;)I", nullptr, $PUBLIC, $virtualMethod(FileChannelImpl, write, int32_t, $ByteBuffer*), "java.io.IOException"},
	{"write", "([Ljava/nio/ByteBuffer;II)J", nullptr, $PUBLIC, $virtualMethod(FileChannelImpl, write, int64_t, $ByteBufferArray*, int32_t, int32_t), "java.io.IOException"},
	{"write", "(Ljava/nio/ByteBuffer;J)I", nullptr, $PUBLIC, $virtualMethod(FileChannelImpl, write, int32_t, $ByteBuffer*, int64_t), "java.io.IOException"},
	{"writeInternal", "(Ljava/nio/ByteBuffer;J)I", nullptr, $PRIVATE, $method(FileChannelImpl, writeInternal, int32_t, $ByteBuffer*, int64_t), "java.io.IOException"},
	{}
};

#define _METHOD_INDEX_initIDs 10
#define _METHOD_INDEX_map0 14
#define _METHOD_INDEX_transferTo0 32
#define _METHOD_INDEX_unmap0 40

$InnerClassInfo _FileChannelImpl_InnerClassesInfo_[] = {
	{"sun.nio.ch.FileChannelImpl$SyncUnmapper", "sun.nio.ch.FileChannelImpl", "SyncUnmapper", $PRIVATE | $STATIC},
	{"sun.nio.ch.FileChannelImpl$DefaultUnmapper", "sun.nio.ch.FileChannelImpl", "DefaultUnmapper", $PRIVATE | $STATIC},
	{"sun.nio.ch.FileChannelImpl$Unmapper", "sun.nio.ch.FileChannelImpl", "Unmapper", $PRIVATE | $STATIC | $ABSTRACT},
	{"sun.nio.ch.FileChannelImpl$Closer", "sun.nio.ch.FileChannelImpl", "Closer", $PRIVATE | $STATIC},
	{"sun.nio.ch.FileChannelImpl$2", nullptr, nullptr, 0},
	{"sun.nio.ch.FileChannelImpl$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _FileChannelImpl_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.nio.ch.FileChannelImpl",
	"java.nio.channels.FileChannel",
	nullptr,
	_FileChannelImpl_FieldInfo_,
	_FileChannelImpl_MethodInfo_,
	nullptr,
	nullptr,
	_FileChannelImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.nio.ch.FileChannelImpl$SyncUnmapper,sun.nio.ch.FileChannelImpl$DefaultUnmapper,sun.nio.ch.FileChannelImpl$Unmapper,sun.nio.ch.FileChannelImpl$Closer,sun.nio.ch.FileChannelImpl$2,sun.nio.ch.FileChannelImpl$1"
};

$Object* allocate$FileChannelImpl($Class* clazz) {
	return $of($alloc(FileChannelImpl));
}

bool FileChannelImpl::$assertionsDisabled = false;
int64_t FileChannelImpl::allocationGranularity = 0;
$JavaIOFileDescriptorAccess* FileChannelImpl::fdAccess = nullptr;
$volatile(bool) FileChannelImpl::transferSupported = false;
$volatile(bool) FileChannelImpl::pipeSupported = false;
$volatile(bool) FileChannelImpl::fileSupported = false;

void FileChannelImpl::init$($FileDescriptor* fd, $String* path, bool readable, bool writable, bool direct, Object$* parent) {
	$useLocalCurrentObjectStackCache();
	$FileChannel::init$();
	$set(this, threads, $new($NativeThreadSet, 2));
	$set(this, positionLock, $new($Object));
	$set(this, fd, fd);
	this->readable = readable;
	this->writable = writable;
	$set(this, parent, parent);
	$set(this, path, path);
	this->direct = direct;
	$set(this, nd, $new($FileDispatcherImpl));
	if (direct) {
		if (!FileChannelImpl::$assertionsDisabled && !(path != nullptr)) {
			$throwNew($AssertionError);
		}
		this->alignment = $nc(this->nd)->setDirectIO(fd, path);
	} else {
		this->alignment = -1;
	}
	$set(this, closer, parent != nullptr ? ($Cleaner$Cleanable*)nullptr : $nc($($CleanerFactory::cleaner()))->register$(this, $$new($FileChannelImpl$Closer, fd)));
}

$FileChannel* FileChannelImpl::open($FileDescriptor* fd, $String* path, bool readable, bool writable, bool direct, Object$* parent) {
	$init(FileChannelImpl);
	return $new(FileChannelImpl, fd, path, readable, writable, direct, parent);
}

void FileChannelImpl::ensureOpen() {
	if (!isOpen()) {
		$throwNew($ClosedChannelException);
	}
}

void FileChannelImpl::setUninterruptible() {
	this->uninterruptible = true;
}

void FileChannelImpl::beginBlocking() {
	if (!this->uninterruptible) {
		begin();
	}
}

void FileChannelImpl::endBlocking(bool completed) {
	if (!this->uninterruptible) {
		end(completed);
	}
}

void FileChannelImpl::implCloseChannel() {
	$useLocalCurrentObjectStackCache();
	if (!$nc(this->fd)->valid()) {
		return;
	}
	if (this->fileLockTable$ != nullptr) {
		{
			$var($Iterator, i$, $nc($($nc(this->fileLockTable$)->removeAll()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($FileLock, fl, $cast($FileLock, i$->next()));
				{
					$synchronized(fl) {
						if ($nc(fl)->isValid()) {
							$var($FileDescriptor, var$0, this->fd);
							int64_t var$1 = fl->position();
							$nc(this->nd)->release(var$0, var$1, fl->size());
							$nc(($cast($FileLockImpl, fl)))->invalidate();
						}
					}
				}
			}
		}
	}
	$nc(this->threads)->signalAndWait();
	if (this->parent != nullptr) {
		$nc(($cast($Closeable, this->parent)))->close();
	} else if (this->closer != nullptr) {
		try {
			$nc(this->closer)->clean();
		} catch ($UncheckedIOException& uioe) {
			$throw($($cast($IOException, uioe->getCause())));
		}
	} else {
		$nc(FileChannelImpl::fdAccess)->close(this->fd);
	}
}

int32_t FileChannelImpl::read($ByteBuffer* dst) {
	ensureOpen();
	if (!this->readable) {
		$throwNew($NonReadableChannelException);
	}
	$synchronized(this->positionLock) {
		if (this->direct) {
			$Util::checkChannelPositionAligned(position(), this->alignment);
		}
		int32_t n = 0;
		int32_t ti = -1;
		{
			$var($Throwable, var$0, nullptr);
			int32_t var$2 = 0;
			bool return$1 = false;
			try {
				beginBlocking();
				ti = $nc(this->threads)->add();
				if (!isOpen()) {
					var$2 = 0;
					return$1 = true;
					goto $finally;
				}
				do {
					n = $IOUtil::read(this->fd, dst, -1, this->direct, this->alignment, this->nd);
				} while ((n == $IOStatus::INTERRUPTED) && isOpen());
				var$2 = $IOStatus::normalize(n);
				return$1 = true;
				goto $finally;
			} catch ($Throwable& var$3) {
				$assign(var$0, var$3);
			} $finally: {
				$nc(this->threads)->remove(ti);
				endBlocking(n > 0);
				if (!FileChannelImpl::$assertionsDisabled && !$IOStatus::check(n)) {
					$throwNew($AssertionError);
				}
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
			if (return$1) {
				return var$2;
			}
		}
	}
	$shouldNotReachHere();
}

int64_t FileChannelImpl::read($ByteBufferArray* dsts, int32_t offset, int32_t length) {
	$Objects::checkFromIndexSize(offset, length, $nc(dsts)->length);
	ensureOpen();
	if (!this->readable) {
		$throwNew($NonReadableChannelException);
	}
	$synchronized(this->positionLock) {
		if (this->direct) {
			$Util::checkChannelPositionAligned(position(), this->alignment);
		}
		int64_t n = 0;
		int32_t ti = -1;
		{
			$var($Throwable, var$0, nullptr);
			int64_t var$2 = 0;
			bool return$1 = false;
			try {
				beginBlocking();
				ti = $nc(this->threads)->add();
				if (!isOpen()) {
					var$2 = 0;
					return$1 = true;
					goto $finally;
				}
				do {
					n = $IOUtil::read(this->fd, dsts, offset, length, this->direct, this->alignment, static_cast<$NativeDispatcher*>(this->nd));
				} while ((n == $IOStatus::INTERRUPTED) && isOpen());
				var$2 = $IOStatus::normalize(n);
				return$1 = true;
				goto $finally;
			} catch ($Throwable& var$3) {
				$assign(var$0, var$3);
			} $finally: {
				$nc(this->threads)->remove(ti);
				endBlocking(n > 0);
				if (!FileChannelImpl::$assertionsDisabled && !$IOStatus::check(n)) {
					$throwNew($AssertionError);
				}
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
			if (return$1) {
				return var$2;
			}
		}
	}
	$shouldNotReachHere();
}

int32_t FileChannelImpl::write($ByteBuffer* src) {
	ensureOpen();
	if (!this->writable) {
		$throwNew($NonWritableChannelException);
	}
	$synchronized(this->positionLock) {
		if (this->direct) {
			$Util::checkChannelPositionAligned(position(), this->alignment);
		}
		int32_t n = 0;
		int32_t ti = -1;
		{
			$var($Throwable, var$0, nullptr);
			int32_t var$2 = 0;
			bool return$1 = false;
			try {
				beginBlocking();
				ti = $nc(this->threads)->add();
				if (!isOpen()) {
					var$2 = 0;
					return$1 = true;
					goto $finally;
				}
				do {
					n = $IOUtil::write(this->fd, src, -1, this->direct, this->alignment, this->nd);
				} while ((n == $IOStatus::INTERRUPTED) && isOpen());
				var$2 = $IOStatus::normalize(n);
				return$1 = true;
				goto $finally;
			} catch ($Throwable& var$3) {
				$assign(var$0, var$3);
			} $finally: {
				$nc(this->threads)->remove(ti);
				endBlocking(n > 0);
				if (!FileChannelImpl::$assertionsDisabled && !$IOStatus::check(n)) {
					$throwNew($AssertionError);
				}
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
			if (return$1) {
				return var$2;
			}
		}
	}
	$shouldNotReachHere();
}

int64_t FileChannelImpl::write($ByteBufferArray* srcs, int32_t offset, int32_t length) {
	$Objects::checkFromIndexSize(offset, length, $nc(srcs)->length);
	ensureOpen();
	if (!this->writable) {
		$throwNew($NonWritableChannelException);
	}
	$synchronized(this->positionLock) {
		if (this->direct) {
			$Util::checkChannelPositionAligned(position(), this->alignment);
		}
		int64_t n = 0;
		int32_t ti = -1;
		{
			$var($Throwable, var$0, nullptr);
			int64_t var$2 = 0;
			bool return$1 = false;
			try {
				beginBlocking();
				ti = $nc(this->threads)->add();
				if (!isOpen()) {
					var$2 = 0;
					return$1 = true;
					goto $finally;
				}
				do {
					n = $IOUtil::write(this->fd, srcs, offset, length, this->direct, this->alignment, static_cast<$NativeDispatcher*>(this->nd));
				} while ((n == $IOStatus::INTERRUPTED) && isOpen());
				var$2 = $IOStatus::normalize(n);
				return$1 = true;
				goto $finally;
			} catch ($Throwable& var$3) {
				$assign(var$0, var$3);
			} $finally: {
				$nc(this->threads)->remove(ti);
				endBlocking(n > 0);
				if (!FileChannelImpl::$assertionsDisabled && !$IOStatus::check(n)) {
					$throwNew($AssertionError);
				}
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
			if (return$1) {
				return var$2;
			}
		}
	}
	$shouldNotReachHere();
}

int64_t FileChannelImpl::position() {
	ensureOpen();
	$synchronized(this->positionLock) {
		int64_t p = -1;
		int32_t ti = -1;
		{
			$var($Throwable, var$0, nullptr);
			int64_t var$2 = 0;
			bool return$1 = false;
			try {
				beginBlocking();
				ti = $nc(this->threads)->add();
				if (!isOpen()) {
					var$2 = 0;
					return$1 = true;
					goto $finally;
				}
				bool append = $nc(FileChannelImpl::fdAccess)->getAppend(this->fd);
				do {
					p = (append) ? $nc(this->nd)->size(this->fd) : $nc(this->nd)->seek(this->fd, -1);
				} while ((p == $IOStatus::INTERRUPTED) && isOpen());
				var$2 = $IOStatus::normalize(p);
				return$1 = true;
				goto $finally;
			} catch ($Throwable& var$3) {
				$assign(var$0, var$3);
			} $finally: {
				$nc(this->threads)->remove(ti);
				endBlocking(p > -1);
				if (!FileChannelImpl::$assertionsDisabled && !$IOStatus::check(p)) {
					$throwNew($AssertionError);
				}
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
			if (return$1) {
				return var$2;
			}
		}
	}
	$shouldNotReachHere();
}

$SeekableByteChannel* FileChannelImpl::position(int64_t newPosition) {
	$useLocalCurrentObjectStackCache();
	ensureOpen();
	if (newPosition < 0) {
		$throwNew($IllegalArgumentException);
	}
	$synchronized(this->positionLock) {
		int64_t p = -1;
		int32_t ti = -1;
		{
			$var($Throwable, var$0, nullptr);
			$var($SeekableByteChannel, var$2, nullptr);
			bool return$1 = false;
			try {
				beginBlocking();
				ti = $nc(this->threads)->add();
				if (!isOpen()) {
					$assign(var$2, nullptr);
					return$1 = true;
					goto $finally;
				}
				do {
					p = $nc(this->nd)->seek(this->fd, newPosition);
				} while ((p == $IOStatus::INTERRUPTED) && isOpen());
				$assign(var$2, this);
				return$1 = true;
				goto $finally;
			} catch ($Throwable& var$3) {
				$assign(var$0, var$3);
			} $finally: {
				$nc(this->threads)->remove(ti);
				endBlocking(p > -1);
				if (!FileChannelImpl::$assertionsDisabled && !$IOStatus::check(p)) {
					$throwNew($AssertionError);
				}
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
			if (return$1) {
				return var$2;
			}
		}
	}
	$shouldNotReachHere();
}

int64_t FileChannelImpl::size() {
	ensureOpen();
	$synchronized(this->positionLock) {
		int64_t s = -1;
		int32_t ti = -1;
		{
			$var($Throwable, var$0, nullptr);
			int64_t var$2 = 0;
			bool return$1 = false;
			try {
				beginBlocking();
				ti = $nc(this->threads)->add();
				if (!isOpen()) {
					var$2 = -1;
					return$1 = true;
					goto $finally;
				}
				do {
					s = $nc(this->nd)->size(this->fd);
				} while ((s == $IOStatus::INTERRUPTED) && isOpen());
				var$2 = $IOStatus::normalize(s);
				return$1 = true;
				goto $finally;
			} catch ($Throwable& var$3) {
				$assign(var$0, var$3);
			} $finally: {
				$nc(this->threads)->remove(ti);
				endBlocking(s > -1);
				if (!FileChannelImpl::$assertionsDisabled && !$IOStatus::check(s)) {
					$throwNew($AssertionError);
				}
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
			if (return$1) {
				return var$2;
			}
		}
	}
	$shouldNotReachHere();
}

$SeekableByteChannel* FileChannelImpl::truncate(int64_t newSize) {
	$useLocalCurrentObjectStackCache();
	ensureOpen();
	if (newSize < 0) {
		$throwNew($IllegalArgumentException, "Negative size"_s);
	}
	if (!this->writable) {
		$throwNew($NonWritableChannelException);
	}
	$synchronized(this->positionLock) {
		int32_t rv = -1;
		int64_t p = -1;
		int32_t ti = -1;
		int64_t rp = -1;
		{
			$var($Throwable, var$0, nullptr);
			$var($SeekableByteChannel, var$2, nullptr);
			bool return$1 = false;
			try {
				beginBlocking();
				ti = $nc(this->threads)->add();
				if (!isOpen()) {
					$assign(var$2, nullptr);
					return$1 = true;
					goto $finally;
				}
				int64_t size = 0;
				do {
					size = $nc(this->nd)->size(this->fd);
				} while ((size == $IOStatus::INTERRUPTED) && isOpen());
				if (!isOpen()) {
					$assign(var$2, nullptr);
					return$1 = true;
					goto $finally;
				}
				do {
					p = $nc(this->nd)->seek(this->fd, -1);
				} while ((p == $IOStatus::INTERRUPTED) && isOpen());
				if (!isOpen()) {
					$assign(var$2, nullptr);
					return$1 = true;
					goto $finally;
				}
				if (!FileChannelImpl::$assertionsDisabled && !(p >= 0)) {
					$throwNew($AssertionError);
				}
				if (newSize < size) {
					do {
						rv = $nc(this->nd)->truncate(this->fd, newSize);
					} while ((rv == $IOStatus::INTERRUPTED) && isOpen());
					if (!isOpen()) {
						$assign(var$2, nullptr);
						return$1 = true;
						goto $finally;
					}
				}
				if (p > newSize) {
					p = newSize;
				}
				do {
					rp = $nc(this->nd)->seek(this->fd, p);
				} while ((rp == $IOStatus::INTERRUPTED) && isOpen());
				$assign(var$2, this);
				return$1 = true;
				goto $finally;
			} catch ($Throwable& var$3) {
				$assign(var$0, var$3);
			} $finally: {
				$nc(this->threads)->remove(ti);
				endBlocking(rv > -1);
				if (!FileChannelImpl::$assertionsDisabled && !$IOStatus::check(rv)) {
					$throwNew($AssertionError);
				}
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
			if (return$1) {
				return var$2;
			}
		}
	}
	$shouldNotReachHere();
}

void FileChannelImpl::force(bool metaData) {
	ensureOpen();
	int32_t rv = -1;
	int32_t ti = -1;
	{
		$var($Throwable, var$0, nullptr);
		bool return$1 = false;
		try {
			beginBlocking();
			ti = $nc(this->threads)->add();
			if (!isOpen()) {
				return$1 = true;
				goto $finally;
			}
			do {
				rv = $nc(this->nd)->force(this->fd, metaData);
			} while ((rv == $IOStatus::INTERRUPTED) && isOpen());
		} catch ($Throwable& var$2) {
			$assign(var$0, var$2);
		} $finally: {
			$nc(this->threads)->remove(ti);
			endBlocking(rv > -1);
			if (!FileChannelImpl::$assertionsDisabled && !$IOStatus::check(rv)) {
				$throwNew($AssertionError);
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return;
		}
	}
}

int64_t FileChannelImpl::transferToDirectlyInternal(int64_t position, int32_t icount, $WritableByteChannel* target, $FileDescriptor* targetFD) {
	bool var$0 = !FileChannelImpl::$assertionsDisabled;
	if (var$0) {
		bool var$1 = !$nc(this->nd)->transferToDirectlyNeedsPositionLock();
		var$0 = !(var$1 || $Thread::holdsLock(this->positionLock));
	}
	if (var$0) {
		$throwNew($AssertionError);
	}
	int64_t n = -1;
	int32_t ti = -1;
	{
		$var($Throwable, var$2, nullptr);
		int64_t var$4 = 0;
		bool return$3 = false;
		try {
			beginBlocking();
			ti = $nc(this->threads)->add();
			if (!isOpen()) {
				var$4 = -1;
				return$3 = true;
				goto $finally;
			}
			do {
				n = transferTo0(this->fd, position, icount, targetFD);
			} while ((n == $IOStatus::INTERRUPTED) && isOpen());
			if (n == $IOStatus::UNSUPPORTED_CASE) {
				if ($instanceOf($SinkChannelImpl, target)) {
					FileChannelImpl::pipeSupported = false;
				}
				if ($instanceOf(FileChannelImpl, target)) {
					FileChannelImpl::fileSupported = false;
				}
				var$4 = $IOStatus::UNSUPPORTED_CASE;
				return$3 = true;
				goto $finally;
			}
			if (n == $IOStatus::UNSUPPORTED) {
				FileChannelImpl::transferSupported = false;
				var$4 = $IOStatus::UNSUPPORTED;
				return$3 = true;
				goto $finally;
			}
			var$4 = $IOStatus::normalize(n);
			return$3 = true;
			goto $finally;
		} catch ($Throwable& var$5) {
			$assign(var$2, var$5);
		} $finally: {
			$nc(this->threads)->remove(ti);
			end(n > -1);
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

int64_t FileChannelImpl::transferToDirectly(int64_t position, int32_t icount, $WritableByteChannel* target) {
	$useLocalCurrentObjectStackCache();
	if (!FileChannelImpl::transferSupported) {
		return $IOStatus::UNSUPPORTED;
	}
	$var($FileDescriptor, targetFD, nullptr);
	if ($instanceOf(FileChannelImpl, target)) {
		if (!FileChannelImpl::fileSupported) {
			return $IOStatus::UNSUPPORTED_CASE;
		}
		$assign(targetFD, $nc(($cast(FileChannelImpl, target)))->fd);
	} else if ($instanceOf($SelChImpl, target)) {
		if (($instanceOf($SinkChannelImpl, target)) && !FileChannelImpl::pipeSupported) {
			return $IOStatus::UNSUPPORTED_CASE;
		}
		$var($SelectableChannel, sc, $cast($SelectableChannel, target));
		if (!$nc(this->nd)->canTransferToDirectly(sc)) {
			return $IOStatus::UNSUPPORTED_CASE;
		}
		$assign(targetFD, $nc(($cast($SelChImpl, target)))->getFD());
	}
	if (targetFD == nullptr) {
		return $IOStatus::UNSUPPORTED;
	}
	int32_t thisFDVal = $IOUtil::fdVal(this->fd);
	int32_t targetFDVal = $IOUtil::fdVal(targetFD);
	if (thisFDVal == targetFDVal) {
		return $IOStatus::UNSUPPORTED;
	}
	if ($nc(this->nd)->transferToDirectlyNeedsPositionLock()) {
		$synchronized(this->positionLock) {
			int64_t pos = this->position();
			{
				$var($Throwable, var$0, nullptr);
				int64_t var$2 = 0;
				bool return$1 = false;
				try {
					var$2 = transferToDirectlyInternal(position, icount, target, targetFD);
					return$1 = true;
					goto $finally;
				} catch ($Throwable& var$3) {
					$assign(var$0, var$3);
				} $finally: {
					this->position(pos);
				}
				if (var$0 != nullptr) {
					$throw(var$0);
				}
				if (return$1) {
					return var$2;
				}
			}
		}
	} else {
		return transferToDirectlyInternal(position, icount, target, targetFD);
	}
}

int64_t FileChannelImpl::transferToTrustedChannel(int64_t position, int64_t count, $WritableByteChannel* target) {
	$useLocalCurrentObjectStackCache();
	bool isSelChImpl = ($instanceOf($SelChImpl, target));
	if (!(($instanceOf(FileChannelImpl, target)) || isSelChImpl)) {
		return $IOStatus::UNSUPPORTED;
	}
	int64_t remaining = count;
	while (remaining > (int64_t)0) {
		int64_t size = $Math::min(remaining, FileChannelImpl::MAPPED_TRANSFER_SIZE);
		try {
			$init($FileChannel$MapMode);
			$var($MappedByteBuffer, dbb, map($FileChannel$MapMode::READ_ONLY, position, size));
			{
				$var($Throwable, var$0, nullptr);
				bool break$1 = false;
				try {
					int32_t n = $nc(target)->write(dbb);
					if (!FileChannelImpl::$assertionsDisabled && !(n >= 0)) {
						$throwNew($AssertionError);
					}
					remaining -= n;
					if (isSelChImpl) {
						// break;
						break$1 = true;
						goto $finally;
					}
					if (!FileChannelImpl::$assertionsDisabled && !(n > 0)) {
						$throwNew($AssertionError);
					}
					position += n;
				} catch ($Throwable& var$2) {
					$assign(var$0, var$2);
				} $finally: {
					unmap(dbb);
				}
				if (var$0 != nullptr) {
					$throw(var$0);
				}
				if (break$1) {
					break;
				}
			}
		} catch ($ClosedByInterruptException& e) {
			if (!FileChannelImpl::$assertionsDisabled && ! !$nc(target)->isOpen()) {
				$throwNew($AssertionError);
			}
			try {
				close();
			} catch ($Throwable& suppressed) {
				e->addSuppressed(suppressed);
			}
			$throw(e);
		} catch ($IOException& ioe) {
			if (remaining == count) {
				$throw(ioe);
			}
			break;
		}
	}
	return count - remaining;
}

int64_t FileChannelImpl::transferToArbitraryChannel(int64_t position, int32_t icount, $WritableByteChannel* target) {
	int32_t c = $Math::min(icount, FileChannelImpl::TRANSFER_SIZE);
	$var($ByteBuffer, bb, $ByteBuffer::allocate(c));
	int64_t tw = 0;
	int64_t pos = position;
	try {
		while (tw < icount) {
			$nc(bb)->limit($Math::min((int32_t)(icount - tw), FileChannelImpl::TRANSFER_SIZE));
			int32_t nr = read(bb, pos);
			if (nr <= 0) {
				break;
			}
			bb->flip();
			int32_t nw = $nc(target)->write(bb);
			tw += nw;
			if (nw != nr) {
				break;
			}
			pos += nw;
			bb->clear();
		}
		return tw;
	} catch ($IOException& x) {
		if (tw > 0) {
			return tw;
		}
		$throw(x);
	}
	$shouldNotReachHere();
}

int64_t FileChannelImpl::transferTo(int64_t position, int64_t count, $WritableByteChannel* target) {
	ensureOpen();
	if (!$nc(target)->isOpen()) {
		$throwNew($ClosedChannelException);
	}
	if (!this->readable) {
		$throwNew($NonReadableChannelException);
	}
	if ($instanceOf(FileChannelImpl, target) && !$nc(($cast(FileChannelImpl, target)))->writable) {
		$throwNew($NonWritableChannelException);
	}
	if ((position < 0) || (count < 0)) {
		$throwNew($IllegalArgumentException);
	}
	int64_t sz = size();
	if (position > sz) {
		return 0;
	}
	int32_t icount = (int32_t)$Math::min(count, (int64_t)$Integer::MAX_VALUE);
	if ((sz - position) < icount) {
		icount = (int32_t)(sz - position);
	}
	int64_t n = 0;
	if ((n = transferToDirectly(position, icount, target)) >= 0) {
		return n;
	}
	if ((n = transferToTrustedChannel(position, icount, target)) >= 0) {
		return n;
	}
	return transferToArbitraryChannel(position, icount, target);
}

int64_t FileChannelImpl::transferFromFileChannel(FileChannelImpl* src, int64_t position, int64_t count) {
	$useLocalCurrentObjectStackCache();
	if (!$nc(src)->readable) {
		$throwNew($NonReadableChannelException);
	}
	$synchronized($nc(src)->positionLock) {
		int64_t pos = src->position();
		int64_t max = $Math::min(count, src->size() - pos);
		int64_t remaining = max;
		int64_t p = pos;
		while (remaining > (int64_t)0) {
			int64_t size = $Math::min(remaining, FileChannelImpl::MAPPED_TRANSFER_SIZE);
			$init($FileChannel$MapMode);
			$var($MappedByteBuffer, bb, src->map($FileChannel$MapMode::READ_ONLY, p, size));
			{
				$var($Throwable, var$0, nullptr);
				bool break$1 = false;
				try {
					try {
						int64_t n = write(bb, position);
						if (!FileChannelImpl::$assertionsDisabled && !(n > 0)) {
							$throwNew($AssertionError);
						}
						p += n;
						position += n;
						remaining -= n;
					} catch ($IOException& ioe) {
						if (remaining == max) {
							$throw(ioe);
						}
						// break;
						break$1 = true;
						goto $finally;
					}
				} catch ($Throwable& var$2) {
					$assign(var$0, var$2);
				} $finally: {
					unmap(bb);
				}
				if (var$0 != nullptr) {
					$throw(var$0);
				}
				if (break$1) {
					break;
				}
			}
		}
		int64_t nwritten = max - remaining;
		src->position(pos + nwritten);
		return nwritten;
	}
}

int64_t FileChannelImpl::transferFromArbitraryChannel($ReadableByteChannel* src, int64_t position, int64_t count) {
	int32_t c = (int32_t)$Math::min(count, (int64_t)FileChannelImpl::TRANSFER_SIZE);
	$var($ByteBuffer, bb, $ByteBuffer::allocate(c));
	int64_t tw = 0;
	int64_t pos = position;
	try {
		while (tw < count) {
			$nc(bb)->limit((int32_t)$Math::min((count - tw), (int64_t)FileChannelImpl::TRANSFER_SIZE));
			int32_t nr = $nc(src)->read(bb);
			if (nr <= 0) {
				break;
			}
			bb->flip();
			int32_t nw = write(bb, pos);
			tw += nw;
			if (nw != nr) {
				break;
			}
			pos += nw;
			bb->clear();
		}
		return tw;
	} catch ($IOException& x) {
		if (tw > 0) {
			return tw;
		}
		$throw(x);
	}
	$shouldNotReachHere();
}

int64_t FileChannelImpl::transferFrom($ReadableByteChannel* src, int64_t position, int64_t count) {
	ensureOpen();
	if (!$nc(src)->isOpen()) {
		$throwNew($ClosedChannelException);
	}
	if (!this->writable) {
		$throwNew($NonWritableChannelException);
	}
	if ((position < 0) || (count < 0)) {
		$throwNew($IllegalArgumentException);
	}
	if (position > size()) {
		return 0;
	}
	if ($instanceOf(FileChannelImpl, src)) {
		return transferFromFileChannel($cast(FileChannelImpl, src), position, count);
	}
	return transferFromArbitraryChannel(src, position, count);
}

int32_t FileChannelImpl::read($ByteBuffer* dst, int64_t position) {
	if (dst == nullptr) {
		$throwNew($NullPointerException);
	}
	if (position < 0) {
		$throwNew($IllegalArgumentException, "Negative position"_s);
	}
	ensureOpen();
	if (!this->readable) {
		$throwNew($NonReadableChannelException);
	}
	if (this->direct) {
		$Util::checkChannelPositionAligned(position, this->alignment);
	}
	if ($nc(this->nd)->needsPositionLock()) {
		$synchronized(this->positionLock) {
			return readInternal(dst, position);
		}
	} else {
		return readInternal(dst, position);
	}
}

int32_t FileChannelImpl::readInternal($ByteBuffer* dst, int64_t position) {
	bool var$0 = !FileChannelImpl::$assertionsDisabled;
	if (var$0) {
		bool var$1 = !$nc(this->nd)->needsPositionLock();
		var$0 = !(var$1 || $Thread::holdsLock(this->positionLock));
	}
	if (var$0) {
		$throwNew($AssertionError);
	}
	int32_t n = 0;
	int32_t ti = -1;
	{
		$var($Throwable, var$2, nullptr);
		int32_t var$4 = 0;
		bool return$3 = false;
		try {
			beginBlocking();
			ti = $nc(this->threads)->add();
			if (!isOpen()) {
				var$4 = -1;
				return$3 = true;
				goto $finally;
			}
			do {
				n = $IOUtil::read(this->fd, dst, position, this->direct, this->alignment, this->nd);
			} while ((n == $IOStatus::INTERRUPTED) && isOpen());
			var$4 = $IOStatus::normalize(n);
			return$3 = true;
			goto $finally;
		} catch ($Throwable& var$5) {
			$assign(var$2, var$5);
		} $finally: {
			$nc(this->threads)->remove(ti);
			endBlocking(n > 0);
			if (!FileChannelImpl::$assertionsDisabled && !$IOStatus::check(n)) {
				$throwNew($AssertionError);
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

int32_t FileChannelImpl::write($ByteBuffer* src, int64_t position) {
	if (src == nullptr) {
		$throwNew($NullPointerException);
	}
	if (position < 0) {
		$throwNew($IllegalArgumentException, "Negative position"_s);
	}
	ensureOpen();
	if (!this->writable) {
		$throwNew($NonWritableChannelException);
	}
	if (this->direct) {
		$Util::checkChannelPositionAligned(position, this->alignment);
	}
	if ($nc(this->nd)->needsPositionLock()) {
		$synchronized(this->positionLock) {
			return writeInternal(src, position);
		}
	} else {
		return writeInternal(src, position);
	}
}

int32_t FileChannelImpl::writeInternal($ByteBuffer* src, int64_t position) {
	bool var$0 = !FileChannelImpl::$assertionsDisabled;
	if (var$0) {
		bool var$1 = !$nc(this->nd)->needsPositionLock();
		var$0 = !(var$1 || $Thread::holdsLock(this->positionLock));
	}
	if (var$0) {
		$throwNew($AssertionError);
	}
	int32_t n = 0;
	int32_t ti = -1;
	{
		$var($Throwable, var$2, nullptr);
		int32_t var$4 = 0;
		bool return$3 = false;
		try {
			beginBlocking();
			ti = $nc(this->threads)->add();
			if (!isOpen()) {
				var$4 = -1;
				return$3 = true;
				goto $finally;
			}
			do {
				n = $IOUtil::write(this->fd, src, position, this->direct, this->alignment, this->nd);
			} while ((n == $IOStatus::INTERRUPTED) && isOpen());
			var$4 = $IOStatus::normalize(n);
			return$3 = true;
			goto $finally;
		} catch ($Throwable& var$5) {
			$assign(var$2, var$5);
		} $finally: {
			$nc(this->threads)->remove(ti);
			endBlocking(n > 0);
			if (!FileChannelImpl::$assertionsDisabled && !$IOStatus::check(n)) {
				$throwNew($AssertionError);
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

void FileChannelImpl::unmap($MappedByteBuffer* bb) {
	$init(FileChannelImpl);
	$var($1Cleaner, cl, $nc(($cast($DirectBuffer, bb)))->cleaner());
	if (cl != nullptr) {
		cl->clean();
	}
}

$MappedByteBuffer* FileChannelImpl::map($FileChannel$MapMode* mode, int64_t position, int64_t size) {
	$useLocalCurrentObjectStackCache();
	if (size > $Integer::MAX_VALUE) {
		$throwNew($IllegalArgumentException, "Size exceeds Integer.MAX_VALUE"_s);
	}
	bool isSync = this->isSync($cast($FileChannel$MapMode, $Objects::requireNonNull($of(mode), "Mode is null"_s)));
	int32_t prot = toProt(mode);
	$var($FileChannelImpl$Unmapper, unmapper, mapInternal(mode, position, size, prot, isSync));
	if (unmapper == nullptr) {
		$var($FileDescriptor, dummy, $new($FileDescriptor));
		if ((!this->writable) || (prot == FileChannelImpl::MAP_RO)) {
			return $Util::newMappedByteBufferR(0, 0, dummy, nullptr, isSync);
		} else {
			return $Util::newMappedByteBuffer(0, 0, dummy, nullptr, isSync);
		}
	} else if ((!this->writable) || (prot == FileChannelImpl::MAP_RO)) {
		return $Util::newMappedByteBufferR((int32_t)$nc(unmapper)->cap, unmapper->address$ + unmapper->pagePosition, unmapper->fd, unmapper, isSync);
	} else {
		return $Util::newMappedByteBuffer((int32_t)$nc(unmapper)->cap, unmapper->address$ + unmapper->pagePosition, unmapper->fd, unmapper, isSync);
	}
}

$FileChannelImpl$Unmapper* FileChannelImpl::mapInternal($FileChannel$MapMode* mode, int64_t position, int64_t size) {
	bool isSync = this->isSync($cast($FileChannel$MapMode, $Objects::requireNonNull($of(mode), "Mode is null"_s)));
	int32_t prot = toProt(mode);
	return mapInternal(mode, position, size, prot, isSync);
}

$FileChannelImpl$Unmapper* FileChannelImpl::mapInternal($FileChannel$MapMode* mode, int64_t position, int64_t size, int32_t prot, bool isSync) {
	$useLocalCurrentObjectStackCache();
	ensureOpen();
	if (mode == nullptr) {
		$throwNew($NullPointerException, "Mode is null"_s);
	}
	if (position < (int64_t)0) {
		$throwNew($IllegalArgumentException, "Negative position"_s);
	}
	if (size < (int64_t)0) {
		$throwNew($IllegalArgumentException, "Negative size"_s);
	}
	if (position + size < 0) {
		$throwNew($IllegalArgumentException, "Position + size overflow"_s);
	}
	checkMode(mode, prot, isSync);
	int64_t addr = -1;
	int32_t ti = -1;
	{
		$var($Throwable, var$0, nullptr);
		$var($FileChannelImpl$Unmapper, var$2, nullptr);
		bool return$1 = false;
		try {
			beginBlocking();
			ti = $nc(this->threads)->add();
			if (!isOpen()) {
				$assign(var$2, nullptr);
				return$1 = true;
				goto $finally;
			}
			int64_t mapSize = 0;
			int32_t pagePosition = 0;
			$synchronized(this->positionLock) {
				int64_t filesize = 0;
				do {
					filesize = $nc(this->nd)->size(this->fd);
				} while ((filesize == $IOStatus::INTERRUPTED) && isOpen());
				if (!isOpen()) {
					$assign(var$2, nullptr);
					return$1 = true;
					goto $finally;
				}
				if (filesize < position + size) {
					if (!this->writable) {
						$throwNew($IOException, "Channel not open for writing - cannot extend file to required size"_s);
					}
					int32_t rv = 0;
					do {
						rv = $nc(this->nd)->truncate(this->fd, position + size);
					} while ((rv == $IOStatus::INTERRUPTED) && isOpen());
					if (!isOpen()) {
						$assign(var$2, nullptr);
						return$1 = true;
						goto $finally;
					}
				}
				if (size == 0) {
					$assign(var$2, nullptr);
					return$1 = true;
					goto $finally;
				}
				pagePosition = (int32_t)($mod(position, FileChannelImpl::allocationGranularity));
				int64_t mapPosition = position - pagePosition;
				mapSize = size + pagePosition;
				try {
					addr = map0(prot, mapPosition, mapSize, isSync);
				} catch ($OutOfMemoryError& x) {
					$System::gc();
					try {
						$Thread::sleep(100);
					} catch ($InterruptedException& y) {
						$($Thread::currentThread())->interrupt();
					}
					try {
						addr = map0(prot, mapPosition, mapSize, isSync);
					} catch ($OutOfMemoryError& y) {
						$throwNew($IOException, "Map failed"_s, y);
					}
				}
			}
			$var($FileDescriptor, mfd, nullptr);
			try {
				$assign(mfd, $nc(this->nd)->duplicateForMapping(this->fd));
			} catch ($IOException& ioe) {
				unmap0(addr, mapSize);
				$throw(ioe);
			}
			if (!FileChannelImpl::$assertionsDisabled && !($IOStatus::checkAll(addr))) {
				$throwNew($AssertionError);
			}
			if (!FileChannelImpl::$assertionsDisabled && !($mod(addr, FileChannelImpl::allocationGranularity) == 0)) {
				$throwNew($AssertionError);
			}
			$var($FileChannelImpl$Unmapper, um, isSync ? static_cast<$FileChannelImpl$Unmapper*>($new($FileChannelImpl$SyncUnmapper, addr, mapSize, size, mfd, pagePosition)) : static_cast<$FileChannelImpl$Unmapper*>($new($FileChannelImpl$DefaultUnmapper, addr, mapSize, size, mfd, pagePosition)));
			$assign(var$2, um);
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc(this->threads)->remove(ti);
			endBlocking($IOStatus::checkAll(addr));
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

bool FileChannelImpl::isSync($FileChannel$MapMode* mode) {
	$init($ExtendedMapMode);
	return !$VM::isModuleSystemInited() ? false : (mode == $ExtendedMapMode::READ_ONLY_SYNC || mode == $ExtendedMapMode::READ_WRITE_SYNC);
}

int32_t FileChannelImpl::toProt($FileChannel$MapMode* mode) {
	int32_t prot = 0;
	$init($FileChannel$MapMode);
	if (mode == $FileChannel$MapMode::READ_ONLY) {
		prot = FileChannelImpl::MAP_RO;
	} else {
		if (mode == $FileChannel$MapMode::READ_WRITE) {
			prot = FileChannelImpl::MAP_RW;
		} else {
			if (mode == $FileChannel$MapMode::PRIVATE) {
				prot = FileChannelImpl::MAP_PV;
			} else {
				$init($ExtendedMapMode);
				if (mode == $ExtendedMapMode::READ_ONLY_SYNC) {
					prot = FileChannelImpl::MAP_RO;
				} else {
					if (mode == $ExtendedMapMode::READ_WRITE_SYNC) {
						prot = FileChannelImpl::MAP_RW;
					} else {
						prot = FileChannelImpl::MAP_INVALID;
					}
				}
			}
		}
	}
	return prot;
}

void FileChannelImpl::checkMode($FileChannel$MapMode* mode, int32_t prot, bool isSync) {
	if (prot == FileChannelImpl::MAP_INVALID) {
		$throwNew($UnsupportedOperationException);
	}
	$init($FileChannel$MapMode);
	$init($ExtendedMapMode);
	if ((mode != $FileChannel$MapMode::READ_ONLY) && mode != $ExtendedMapMode::READ_ONLY_SYNC && !this->writable) {
		$throwNew($NonWritableChannelException);
	}
	if (!this->readable) {
		$throwNew($NonReadableChannelException);
	}
	if (isSync && !$Unsafe::isWritebackEnabled()) {
		$throwNew($UnsupportedOperationException);
	}
}

$VM$BufferPool* FileChannelImpl::getMappedBufferPool() {
	$init(FileChannelImpl);
	return $new($FileChannelImpl$1);
}

$VM$BufferPool* FileChannelImpl::getSyncMappedBufferPool() {
	$init(FileChannelImpl);
	return $new($FileChannelImpl$2);
}

$FileLockTable* FileChannelImpl::fileLockTable() {
	if (this->fileLockTable$ == nullptr) {
		$synchronized(this) {
			if (this->fileLockTable$ == nullptr) {
				int32_t ti = $nc(this->threads)->add();
				{
					$var($Throwable, var$0, nullptr);
					try {
						ensureOpen();
						$set(this, fileLockTable$, $new($FileLockTable, static_cast<$Channel*>(static_cast<$InterruptibleChannel*>(static_cast<$AbstractInterruptibleChannel*>(static_cast<$FileChannel*>(this)))), this->fd));
					} catch ($Throwable& var$1) {
						$assign(var$0, var$1);
					} /*finally*/ {
						$nc(this->threads)->remove(ti);
					}
					if (var$0 != nullptr) {
						$throw(var$0);
					}
				}
			}
		}
	}
	return this->fileLockTable$;
}

$FileLock* FileChannelImpl::lock(int64_t position, int64_t size, bool shared) {
	$useLocalCurrentObjectStackCache();
	ensureOpen();
	if (shared && !this->readable) {
		$throwNew($NonReadableChannelException);
	}
	if (!shared && !this->writable) {
		$throwNew($NonWritableChannelException);
	}
	$var($FileLockImpl, fli, $new($FileLockImpl, static_cast<$FileChannel*>(this), position, size, shared));
	$var($FileLockTable, flt, fileLockTable());
	$nc(flt)->add(fli);
	bool completed = false;
	int32_t ti = -1;
	{
		$var($Throwable, var$0, nullptr);
		$var($FileLock, var$2, nullptr);
		bool return$1 = false;
		try {
			beginBlocking();
			ti = $nc(this->threads)->add();
			if (!isOpen()) {
				$assign(var$2, nullptr);
				return$1 = true;
				goto $finally;
			}
			int32_t n = 0;
			do {
				n = $nc(this->nd)->lock(this->fd, true, position, size, shared);
			} while ((n == $FileDispatcher::INTERRUPTED) && isOpen());
			if (isOpen()) {
				if (n == $FileDispatcher::RET_EX_LOCK) {
					if (!FileChannelImpl::$assertionsDisabled && !shared) {
						$throwNew($AssertionError);
					}
					$var($FileLockImpl, fli2, $new($FileLockImpl, static_cast<$FileChannel*>(this), position, size, false));
					flt->replace(fli, fli2);
					$assign(fli, fli2);
				}
				completed = true;
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			if (!completed) {
				flt->remove(fli);
			}
			$nc(this->threads)->remove(ti);
			try {
				endBlocking(completed);
			} catch ($ClosedByInterruptException& e) {
				$throwNew($FileLockInterruptionException);
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	return fli;
}

$FileLock* FileChannelImpl::tryLock(int64_t position, int64_t size, bool shared) {
	$useLocalCurrentObjectStackCache();
	ensureOpen();
	if (shared && !this->readable) {
		$throwNew($NonReadableChannelException);
	}
	if (!shared && !this->writable) {
		$throwNew($NonWritableChannelException);
	}
	$var($FileLockImpl, fli, $new($FileLockImpl, static_cast<$FileChannel*>(this), position, size, shared));
	$var($FileLockTable, flt, fileLockTable());
	$nc(flt)->add(fli);
	int32_t result = 0;
	int32_t ti = $nc(this->threads)->add();
	{
		$var($Throwable, var$0, nullptr);
		$var($FileLock, var$2, nullptr);
		bool return$1 = false;
		try {
			try {
				ensureOpen();
				result = $nc(this->nd)->lock(this->fd, false, position, size, shared);
			} catch ($IOException& e) {
				flt->remove(fli);
				$throw(e);
			}
			if (result == $FileDispatcher::NO_LOCK) {
				flt->remove(fli);
				$assign(var$2, nullptr);
				return$1 = true;
				goto $finally;
			}
			if (result == $FileDispatcher::RET_EX_LOCK) {
				if (!FileChannelImpl::$assertionsDisabled && !shared) {
					$throwNew($AssertionError);
				}
				$var($FileLockImpl, fli2, $new($FileLockImpl, static_cast<$FileChannel*>(this), position, size, false));
				flt->replace(fli, fli2);
				$assign(var$2, fli2);
				return$1 = true;
				goto $finally;
			}
			$assign(var$2, fli);
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc(this->threads)->remove(ti);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

void FileChannelImpl::release($FileLockImpl* fli) {
	$useLocalCurrentObjectStackCache();
	int32_t ti = $nc(this->threads)->add();
	{
		$var($Throwable, var$0, nullptr);
		try {
			ensureOpen();
			$var($FileDescriptor, var$1, this->fd);
			int64_t var$2 = $nc(fli)->position();
			$nc(this->nd)->release(var$1, var$2, fli->size());
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} /*finally*/ {
			$nc(this->threads)->remove(ti);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	if (!FileChannelImpl::$assertionsDisabled && !(this->fileLockTable$ != nullptr)) {
		$throwNew($AssertionError);
	}
	$nc(this->fileLockTable$)->remove(fli);
}

int64_t FileChannelImpl::map0(int32_t prot, int64_t position, int64_t length, bool isSync) {
	int64_t $ret = 0;
	$prepareNative(FileChannelImpl, map0, int64_t, int32_t prot, int64_t position, int64_t length, bool isSync);
	$ret = $invokeNative(prot, position, length, isSync);
	$finishNative();
	return $ret;
}

int32_t FileChannelImpl::unmap0(int64_t address, int64_t length) {
	$init(FileChannelImpl);
	int32_t $ret = 0;
	$prepareNativeStatic(FileChannelImpl, unmap0, int32_t, int64_t address, int64_t length);
	$ret = $invokeNativeStatic(address, length);
	$finishNativeStatic();
	return $ret;
}

int64_t FileChannelImpl::transferTo0($FileDescriptor* src, int64_t position, int64_t count, $FileDescriptor* dst) {
	int64_t $ret = 0;
	$prepareNative(FileChannelImpl, transferTo0, int64_t, $FileDescriptor* src, int64_t position, int64_t count, $FileDescriptor* dst);
	$ret = $invokeNative(src, position, count, dst);
	$finishNative();
	return $ret;
}

int64_t FileChannelImpl::initIDs() {
	$init(FileChannelImpl);
	int64_t $ret = 0;
	$prepareNativeStatic(FileChannelImpl, initIDs, int64_t);
	$ret = $invokeNativeStatic();
	$finishNativeStatic();
	return $ret;
}

void clinit$FileChannelImpl($Class* class$) {
	FileChannelImpl::$assertionsDisabled = !FileChannelImpl::class$->desiredAssertionStatus();
	$assignStatic(FileChannelImpl::fdAccess, $SharedSecrets::getJavaIOFileDescriptorAccess());
	FileChannelImpl::transferSupported = true;
	FileChannelImpl::pipeSupported = true;
	FileChannelImpl::fileSupported = true;
	{
		$IOUtil::load();
		FileChannelImpl::allocationGranularity = FileChannelImpl::initIDs();
	}
}

FileChannelImpl::FileChannelImpl() {
}

$Class* FileChannelImpl::load$($String* name, bool initialize) {
	$loadClass(FileChannelImpl, name, initialize, &_FileChannelImpl_ClassInfo_, clinit$FileChannelImpl, allocate$FileChannelImpl);
	return class$;
}

$Class* FileChannelImpl::class$ = nullptr;

		} // ch
	} // nio
} // sun