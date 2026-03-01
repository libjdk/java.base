#include <java/io/FileInputStream.h>

#include <java/io/Closeable.h>
#include <java/io/File.h>
#include <java/io/FileCleanable.h>
#include <java/io/FileDescriptor.h>
#include <java/io/FileInputStream$1.h>
#include <java/io/FileNotFoundException.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/lang/InternalError.h>
#include <java/lang/Math.h>
#include <java/lang/OutOfMemoryError.h>
#include <java/lang/SecurityManager.h>
#include <java/nio/channels/FileChannel.h>
#include <java/util/Arrays.h>
#include <jdk/internal/util/ArraysSupport.h>
#include <sun/nio/ch/FileChannelImpl.h>
#include <jcpp.h>

#undef DEFAULT_BUFFER_SIZE
#undef MAX_VALUE

using $Closeable = ::java::io::Closeable;
using $File = ::java::io::File;
using $FileCleanable = ::java::io::FileCleanable;
using $FileDescriptor = ::java::io::FileDescriptor;
using $FileInputStream$1 = ::java::io::FileInputStream$1;
using $FileNotFoundException = ::java::io::FileNotFoundException;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $OutOfMemoryError = ::java::lang::OutOfMemoryError;
using $SecurityManager = ::java::lang::SecurityManager;
using $FileChannel = ::java::nio::channels::FileChannel;
using $Arrays = ::java::util::Arrays;
using $ArraysSupport = ::jdk::internal::util::ArraysSupport;
using $FileChannelImpl = ::sun::nio::ch::FileChannelImpl;

namespace java {
	namespace io {

$FieldInfo _FileInputStream_FieldInfo_[] = {
	{"DEFAULT_BUFFER_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(FileInputStream, DEFAULT_BUFFER_SIZE)},
	{"fd", "Ljava/io/FileDescriptor;", nullptr, $PRIVATE | $FINAL, $field(FileInputStream, fd)},
	{"path", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(FileInputStream, path)},
	{"channel", "Ljava/nio/channels/FileChannel;", nullptr, $PRIVATE | $VOLATILE, $field(FileInputStream, channel)},
	{"closeLock", "Ljava/lang/Object;", nullptr, $PRIVATE | $FINAL, $field(FileInputStream, closeLock)},
	{"closed", "Z", nullptr, $PRIVATE | $VOLATILE, $field(FileInputStream, closed)},
	{}
};

$MethodInfo _FileInputStream_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(FileInputStream, init$, void, $String*), "java.io.FileNotFoundException"},
	{"<init>", "(Ljava/io/File;)V", nullptr, $PUBLIC, $method(FileInputStream, init$, void, $File*), "java.io.FileNotFoundException"},
	{"<init>", "(Ljava/io/FileDescriptor;)V", nullptr, $PUBLIC, $method(FileInputStream, init$, void, $FileDescriptor*)},
	{"available", "()I", nullptr, $PUBLIC, $virtualMethod(FileInputStream, available, int32_t), "java.io.IOException"},
	{"available0", "()I", nullptr, $PRIVATE | $NATIVE, $method(FileInputStream, available0, int32_t), "java.io.IOException"},
	{"close", "()V", nullptr, $PUBLIC, $virtualMethod(FileInputStream, close, void), "java.io.IOException"},
	{"getChannel", "()Ljava/nio/channels/FileChannel;", nullptr, $PUBLIC, $virtualMethod(FileInputStream, getChannel, $FileChannel*)},
	{"getFD", "()Ljava/io/FileDescriptor;", nullptr, $PUBLIC | $FINAL, $method(FileInputStream, getFD, $FileDescriptor*), "java.io.IOException"},
	{"initIDs", "()V", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(FileInputStream, initIDs, void)},
	{"length", "()J", nullptr, $PRIVATE, $method(FileInputStream, length, int64_t), "java.io.IOException"},
	{"length0", "()J", nullptr, $PRIVATE | $NATIVE, $method(FileInputStream, length0, int64_t), "java.io.IOException"},
	{"open", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(FileInputStream, open, void, $String*), "java.io.FileNotFoundException"},
	{"open0", "(Ljava/lang/String;)V", nullptr, $PRIVATE | $NATIVE, $method(FileInputStream, open0, void, $String*), "java.io.FileNotFoundException"},
	{"position", "()J", nullptr, $PRIVATE, $method(FileInputStream, position, int64_t), "java.io.IOException"},
	{"position0", "()J", nullptr, $PRIVATE | $NATIVE, $method(FileInputStream, position0, int64_t), "java.io.IOException"},
	{"read", "()I", nullptr, $PUBLIC, $virtualMethod(FileInputStream, read, int32_t), "java.io.IOException"},
	{"read", "([B)I", nullptr, $PUBLIC, $virtualMethod(FileInputStream, read, int32_t, $bytes*), "java.io.IOException"},
	{"read", "([BII)I", nullptr, $PUBLIC, $virtualMethod(FileInputStream, read, int32_t, $bytes*, int32_t, int32_t), "java.io.IOException"},
	{"read0", "()I", nullptr, $PRIVATE | $NATIVE, $method(FileInputStream, read0, int32_t), "java.io.IOException"},
	{"readAllBytes", "()[B", nullptr, $PUBLIC, $virtualMethod(FileInputStream, readAllBytes, $bytes*), "java.io.IOException"},
	{"readBytes", "([BII)I", nullptr, $PRIVATE | $NATIVE, $method(FileInputStream, readBytes, int32_t, $bytes*, int32_t, int32_t), "java.io.IOException"},
	{"readNBytes", "(I)[B", nullptr, $PUBLIC, $virtualMethod(FileInputStream, readNBytes, $bytes*, int32_t), "java.io.IOException"},
	{"skip", "(J)J", nullptr, $PUBLIC, $virtualMethod(FileInputStream, skip, int64_t, int64_t), "java.io.IOException"},
	{"skip0", "(J)J", nullptr, $PRIVATE | $NATIVE, $method(FileInputStream, skip0, int64_t, int64_t), "java.io.IOException"},
	{}
};

#define _METHOD_INDEX_available0 4
#define _METHOD_INDEX_initIDs 8
#define _METHOD_INDEX_length0 10
#define _METHOD_INDEX_open0 12
#define _METHOD_INDEX_position0 14
#define _METHOD_INDEX_read0 18
#define _METHOD_INDEX_readBytes 20
#define _METHOD_INDEX_skip0 23

$InnerClassInfo _FileInputStream_InnerClassesInfo_[] = {
	{"java.io.FileInputStream$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _FileInputStream_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.io.FileInputStream",
	"java.io.InputStream",
	nullptr,
	_FileInputStream_FieldInfo_,
	_FileInputStream_MethodInfo_,
	nullptr,
	nullptr,
	_FileInputStream_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.io.FileInputStream$1"
};

$Object* allocate$FileInputStream($Class* clazz) {
	return $of($alloc(FileInputStream));
}

void FileInputStream::init$($String* name) {
	FileInputStream::init$(name != nullptr ? $$new($File, name) : ($File*)nullptr);
}

void FileInputStream::init$($File* file) {
	$useLocalCurrentObjectStackCache();
	$InputStream::init$();
	$set(this, closeLock, $new($Object));
	$var($String, name, file != nullptr ? $nc(file)->getPath() : ($String*)nullptr);
	$var($SecurityManager, security, $System::getSecurityManager());
	if (security != nullptr) {
		security->checkRead(name);
	}
	if (name == nullptr) {
		$throwNew($NullPointerException);
	}
	if (file->isInvalid()) {
		$throwNew($FileNotFoundException, "Invalid file path"_s);
	}
	$set(this, fd, $new($FileDescriptor));
	$nc(this->fd)->attach(this);
	$set(this, path, name);
	open(name);
	$FileCleanable::register$(this->fd);
}

void FileInputStream::init$($FileDescriptor* fdObj) {
	$InputStream::init$();
	$set(this, closeLock, $new($Object));
	$var($SecurityManager, security, $System::getSecurityManager());
	if (fdObj == nullptr) {
		$throwNew($NullPointerException);
	}
	if (security != nullptr) {
		security->checkRead(fdObj);
	}
	$set(this, fd, fdObj);
	$set(this, path, nullptr);
	$nc(this->fd)->attach(this);
}

void FileInputStream::open0($String* name) {
	$prepareNative(FileInputStream, open0, void, $String* name);
	$invokeNative(name);
	$finishNative();
}

void FileInputStream::open($String* name) {
	open0(name);
}

int32_t FileInputStream::read() {
	return read0();
}

int32_t FileInputStream::read0() {
	int32_t $ret = 0;
	$prepareNative(FileInputStream, read0, int32_t);
	$ret = $invokeNative();
	$finishNative();
	return $ret;
}

int32_t FileInputStream::readBytes($bytes* b, int32_t off, int32_t len) {
	int32_t $ret = 0;
	$prepareNative(FileInputStream, readBytes, int32_t, $bytes* b, int32_t off, int32_t len);
	$ret = $invokeNative(b, off, len);
	$finishNative();
	return $ret;
}

int32_t FileInputStream::read($bytes* b) {
	return readBytes(b, 0, $nc(b)->length);
}

int32_t FileInputStream::read($bytes* b, int32_t off, int32_t len) {
	return readBytes(b, off, len);
}

$bytes* FileInputStream::readAllBytes() {
	$useLocalCurrentObjectStackCache();
	int64_t length = this->length();
	int64_t position = this->position();
	int64_t size = length - position;
	if (length <= 0 || size <= 0) {
		return $InputStream::readAllBytes();
	}
	if (size > (int64_t)$Integer::MAX_VALUE) {
		$var($String, msg, $String::format("Required array size too large for %s: %d = %d - %d"_s, $$new($ObjectArray, {
			$of(this->path),
			$($of($Long::valueOf(size))),
			$($of($Long::valueOf(length))),
			$($of($Long::valueOf(position)))
		})));
		$throwNew($OutOfMemoryError, msg);
	}
	int32_t capacity = (int32_t)size;
	$var($bytes, buf, $new($bytes, capacity));
	int32_t nread = 0;
	int32_t n = 0;
	for (;;) {
		while ((n = read(buf, nread, capacity - nread)) > 0) {
			nread += n;
		}
		if (n < 0 || (n = read()) < 0) {
			break;
		}
		capacity = $Math::max($ArraysSupport::newLength(capacity, 1, capacity), FileInputStream::DEFAULT_BUFFER_SIZE);
		$assign(buf, $Arrays::copyOf(buf, capacity));
		buf->set(nread++, (int8_t)n);
	}
	return (capacity == nread) ? buf : $Arrays::copyOf(buf, nread);
}

$bytes* FileInputStream::readNBytes(int32_t len) {
	if (len < 0) {
		$throwNew($IllegalArgumentException, "len < 0"_s);
	}
	if (len == 0) {
		return $new($bytes, 0);
	}
	int64_t length = this->length();
	int64_t position = this->position();
	int64_t size = length - position;
	if (length <= 0 || size <= 0) {
		return $InputStream::readNBytes(len);
	}
	int32_t capacity = (int32_t)$Math::min((int64_t)len, size);
	$var($bytes, buf, $new($bytes, capacity));
	int32_t remaining = capacity;
	int32_t nread = 0;
	int32_t n = 0;
	do {
		n = read(buf, nread, remaining);
		if (n > 0) {
			nread += n;
			remaining -= n;
		} else if (n == 0) {
			int8_t b = (int8_t)read();
			if (b == -1) {
				break;
			}
			buf->set(nread++, b);
			--remaining;
		}
	} while (n >= 0 && remaining > 0);
	return (capacity == nread) ? buf : $Arrays::copyOf(buf, nread);
}

int64_t FileInputStream::length() {
	return length0();
}

int64_t FileInputStream::length0() {
	int64_t $ret = 0;
	$prepareNative(FileInputStream, length0, int64_t);
	$ret = $invokeNative();
	$finishNative();
	return $ret;
}

int64_t FileInputStream::position() {
	return position0();
}

int64_t FileInputStream::position0() {
	int64_t $ret = 0;
	$prepareNative(FileInputStream, position0, int64_t);
	$ret = $invokeNative();
	$finishNative();
	return $ret;
}

int64_t FileInputStream::skip(int64_t n) {
	return skip0(n);
}

int64_t FileInputStream::skip0(int64_t n) {
	int64_t $ret = 0;
	$prepareNative(FileInputStream, skip0, int64_t, int64_t n);
	$ret = $invokeNative(n);
	$finishNative();
	return $ret;
}

int32_t FileInputStream::available() {
	return available0();
}

int32_t FileInputStream::available0() {
	int32_t $ret = 0;
	$prepareNative(FileInputStream, available0, int32_t);
	$ret = $invokeNative();
	$finishNative();
	return $ret;
}

void FileInputStream::close() {
	$useLocalCurrentObjectStackCache();
	if (this->closed) {
		return;
	}
	$synchronized(this->closeLock) {
		if (this->closed) {
			return;
		}
		this->closed = true;
	}
	$var($FileChannel, fc, this->channel);
	if (fc != nullptr) {
		fc->close();
	}
	$nc(this->fd)->closeAll($$new($FileInputStream$1, this));
}

$FileDescriptor* FileInputStream::getFD() {
	if (this->fd != nullptr) {
		return this->fd;
	}
	$throwNew($IOException);
}

$FileChannel* FileInputStream::getChannel() {
	$var($FileChannel, fc, this->channel);
	if (fc == nullptr) {
		$synchronized(this) {
			$assign(fc, this->channel);
			if (fc == nullptr) {
				$set(this, channel, ($assign(fc, $FileChannelImpl::open(this->fd, this->path, true, false, false, this))));
				if (this->closed) {
					try {
						$nc(fc)->close();
					} catch ($IOException& ioe) {
						$throwNew($InternalError, static_cast<$Throwable*>(ioe));
					}
				}
			}
		}
	}
	return fc;
}

void FileInputStream::initIDs() {
	$init(FileInputStream);
	$prepareNativeStatic(FileInputStream, initIDs, void);
	$invokeNativeStatic();
	$finishNativeStatic();
}

void clinit$FileInputStream($Class* class$) {
	{
		FileInputStream::initIDs();
	}
}

FileInputStream::FileInputStream() {
}

$Class* FileInputStream::load$($String* name, bool initialize) {
	$loadClass(FileInputStream, name, initialize, &_FileInputStream_ClassInfo_, clinit$FileInputStream, allocate$FileInputStream);
	return class$;
}

$Class* FileInputStream::class$ = nullptr;

	} // io
} // java