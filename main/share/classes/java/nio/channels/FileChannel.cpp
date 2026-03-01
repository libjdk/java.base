#include <java/nio/channels/FileChannel.h>

#include <java/nio/ByteBuffer.h>
#include <java/nio/MappedByteBuffer.h>
#include <java/nio/channels/FileChannel$MapMode.h>
#include <java/nio/channels/FileLock.h>
#include <java/nio/channels/ReadableByteChannel.h>
#include <java/nio/channels/WritableByteChannel.h>
#include <java/nio/channels/spi/AbstractInterruptibleChannel.h>
#include <java/nio/file/FileSystem.h>
#include <java/nio/file/OpenOption.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/attribute/FileAttribute.h>
#include <java/nio/file/spi/FileSystemProvider.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/HashSet.h>
#include <java/util/Set.h>
#include <jcpp.h>

#undef MAX_VALUE
#undef NO_ATTRIBUTES

using $ByteBufferArray = $Array<::java::nio::ByteBuffer>;
using $OpenOptionArray = $Array<::java::nio::file::OpenOption>;
using $FileAttributeArray = $Array<::java::nio::file::attribute::FileAttribute>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $MappedByteBuffer = ::java::nio::MappedByteBuffer;
using $FileChannel$MapMode = ::java::nio::channels::FileChannel$MapMode;
using $FileLock = ::java::nio::channels::FileLock;
using $ReadableByteChannel = ::java::nio::channels::ReadableByteChannel;
using $WritableByteChannel = ::java::nio::channels::WritableByteChannel;
using $AbstractInterruptibleChannel = ::java::nio::channels::spi::AbstractInterruptibleChannel;
using $FileSystem = ::java::nio::file::FileSystem;
using $Path = ::java::nio::file::Path;
using $FileSystemProvider = ::java::nio::file::spi::FileSystemProvider;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $HashSet = ::java::util::HashSet;
using $Set = ::java::util::Set;

namespace java {
	namespace nio {
		namespace channels {

$FieldInfo _FileChannel_FieldInfo_[] = {
	{"NO_ATTRIBUTES", "[Ljava/nio/file/attribute/FileAttribute;", "[Ljava/nio/file/attribute/FileAttribute<*>;", $PRIVATE | $STATIC | $FINAL, $staticField(FileChannel, NO_ATTRIBUTES)},
	{}
};

$MethodInfo _FileChannel_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*close", "()V", nullptr, $PUBLIC | $FINAL},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, $PROTECTED, $method(FileChannel, init$, void)},
	{"force", "(Z)V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(FileChannel, force, void, bool), "java.io.IOException"},
	{"*isOpen", "()Z", nullptr, $PUBLIC | $FINAL},
	{"lock", "(JJZ)Ljava/nio/channels/FileLock;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(FileChannel, lock, $FileLock*, int64_t, int64_t, bool), "java.io.IOException"},
	{"lock", "()Ljava/nio/channels/FileLock;", nullptr, $PUBLIC | $FINAL, $method(FileChannel, lock, $FileLock*), "java.io.IOException"},
	{"map", "(Ljava/nio/channels/FileChannel$MapMode;JJ)Ljava/nio/MappedByteBuffer;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(FileChannel, map, $MappedByteBuffer*, $FileChannel$MapMode*, int64_t, int64_t), "java.io.IOException"},
	{"open", "(Ljava/nio/file/Path;Ljava/util/Set;[Ljava/nio/file/attribute/FileAttribute;)Ljava/nio/channels/FileChannel;", "(Ljava/nio/file/Path;Ljava/util/Set<+Ljava/nio/file/OpenOption;>;[Ljava/nio/file/attribute/FileAttribute<*>;)Ljava/nio/channels/FileChannel;", $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(FileChannel, open, FileChannel*, $Path*, $Set*, $FileAttributeArray*), "java.io.IOException"},
	{"open", "(Ljava/nio/file/Path;[Ljava/nio/file/OpenOption;)Ljava/nio/channels/FileChannel;", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(FileChannel, open, FileChannel*, $Path*, $OpenOptionArray*), "java.io.IOException"},
	{"position", "()J", nullptr, $PUBLIC | $ABSTRACT},
	{"position", "(J)Ljava/nio/channels/SeekableByteChannel;", nullptr, $PUBLIC | $ABSTRACT},
	{"read", "(Ljava/nio/ByteBuffer;)I", nullptr, $PUBLIC | $ABSTRACT},
	{"read", "([Ljava/nio/ByteBuffer;II)J", nullptr, $PUBLIC | $ABSTRACT},
	{"read", "([Ljava/nio/ByteBuffer;)J", nullptr, $PUBLIC | $FINAL, $virtualMethod(FileChannel, read, int64_t, $ByteBufferArray*), "java.io.IOException"},
	{"read", "(Ljava/nio/ByteBuffer;J)I", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(FileChannel, read, int32_t, $ByteBuffer*, int64_t), "java.io.IOException"},
	{"size", "()J", nullptr, $PUBLIC | $ABSTRACT},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"transferFrom", "(Ljava/nio/channels/ReadableByteChannel;JJ)J", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(FileChannel, transferFrom, int64_t, $ReadableByteChannel*, int64_t, int64_t), "java.io.IOException"},
	{"transferTo", "(JJLjava/nio/channels/WritableByteChannel;)J", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(FileChannel, transferTo, int64_t, int64_t, int64_t, $WritableByteChannel*), "java.io.IOException"},
	{"truncate", "(J)Ljava/nio/channels/SeekableByteChannel;", nullptr, $PUBLIC | $ABSTRACT},
	{"tryLock", "(JJZ)Ljava/nio/channels/FileLock;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(FileChannel, tryLock, $FileLock*, int64_t, int64_t, bool), "java.io.IOException"},
	{"tryLock", "()Ljava/nio/channels/FileLock;", nullptr, $PUBLIC | $FINAL, $method(FileChannel, tryLock, $FileLock*), "java.io.IOException"},
	{"write", "(Ljava/nio/ByteBuffer;)I", nullptr, $PUBLIC | $ABSTRACT},
	{"write", "([Ljava/nio/ByteBuffer;II)J", nullptr, $PUBLIC | $ABSTRACT},
	{"write", "([Ljava/nio/ByteBuffer;)J", nullptr, $PUBLIC | $FINAL, $virtualMethod(FileChannel, write, int64_t, $ByteBufferArray*), "java.io.IOException"},
	{"write", "(Ljava/nio/ByteBuffer;J)I", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(FileChannel, write, int32_t, $ByteBuffer*, int64_t), "java.io.IOException"},
	{}
};

$InnerClassInfo _FileChannel_InnerClassesInfo_[] = {
	{"java.nio.channels.FileChannel$MapMode", "java.nio.channels.FileChannel", "MapMode", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _FileChannel_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"java.nio.channels.FileChannel",
	"java.nio.channels.spi.AbstractInterruptibleChannel",
	"java.nio.channels.SeekableByteChannel,java.nio.channels.GatheringByteChannel,java.nio.channels.ScatteringByteChannel",
	_FileChannel_FieldInfo_,
	_FileChannel_MethodInfo_,
	nullptr,
	nullptr,
	_FileChannel_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.nio.channels.FileChannel$MapMode"
};

$Object* allocate$FileChannel($Class* clazz) {
	return $of($alloc(FileChannel));
}

void FileChannel::close() {
	this->$AbstractInterruptibleChannel::close();
}

bool FileChannel::isOpen() {
	 return this->$AbstractInterruptibleChannel::isOpen();
}

int32_t FileChannel::hashCode() {
	 return this->$AbstractInterruptibleChannel::hashCode();
}

bool FileChannel::equals(Object$* obj) {
	 return this->$AbstractInterruptibleChannel::equals(obj);
}

$Object* FileChannel::clone() {
	 return this->$AbstractInterruptibleChannel::clone();
}

$String* FileChannel::toString() {
	 return this->$AbstractInterruptibleChannel::toString();
}

void FileChannel::finalize() {
	this->$AbstractInterruptibleChannel::finalize();
}

$FileAttributeArray* FileChannel::NO_ATTRIBUTES = nullptr;

void FileChannel::init$() {
	$AbstractInterruptibleChannel::init$();
}

FileChannel* FileChannel::open($Path* path, $Set* options, $FileAttributeArray* attrs) {
	$init(FileChannel);
	$useLocalCurrentObjectStackCache();
	$var($FileSystemProvider, provider, $nc($($nc(path)->getFileSystem()))->provider());
	return $nc(provider)->newFileChannel(path, options, attrs);
}

FileChannel* FileChannel::open($Path* path, $OpenOptionArray* options) {
	$init(FileChannel);
	$var($Set, set, nullptr);
	if ($nc(options)->length == 0) {
		$assign(set, $Collections::emptySet());
	} else {
		$assign(set, $new($HashSet));
		$Collections::addAll(set, options);
	}
	return open(path, set, FileChannel::NO_ATTRIBUTES);
}

int64_t FileChannel::read($ByteBufferArray* dsts) {
	return read(dsts, 0, $nc(dsts)->length);
}

int64_t FileChannel::write($ByteBufferArray* srcs) {
	return write(srcs, 0, $nc(srcs)->length);
}

$FileLock* FileChannel::lock() {
	return lock(0, $Long::MAX_VALUE, false);
}

$FileLock* FileChannel::tryLock() {
	return tryLock(0, $Long::MAX_VALUE, false);
}

void clinit$FileChannel($Class* class$) {
	$assignStatic(FileChannel::NO_ATTRIBUTES, $new($FileAttributeArray, 0));
}

FileChannel::FileChannel() {
}

$Class* FileChannel::load$($String* name, bool initialize) {
	$loadClass(FileChannel, name, initialize, &_FileChannel_ClassInfo_, clinit$FileChannel, allocate$FileChannel);
	return class$;
}

$Class* FileChannel::class$ = nullptr;

		} // channels
	} // nio
} // java