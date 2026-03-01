#include <java/io/FileOutputStream.h>

#include <java/io/Closeable.h>
#include <java/io/File.h>
#include <java/io/FileCleanable.h>
#include <java/io/FileDescriptor.h>
#include <java/io/FileNotFoundException.h>
#include <java/io/FileOutputStream$1.h>
#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <java/lang/InternalError.h>
#include <java/lang/SecurityManager.h>
#include <java/nio/channels/FileChannel.h>
#include <jdk/internal/access/JavaIOFileDescriptorAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <sun/nio/ch/FileChannelImpl.h>
#include <jcpp.h>

using $Closeable = ::java::io::Closeable;
using $File = ::java::io::File;
using $FileCleanable = ::java::io::FileCleanable;
using $FileDescriptor = ::java::io::FileDescriptor;
using $FileNotFoundException = ::java::io::FileNotFoundException;
using $FileOutputStream$1 = ::java::io::FileOutputStream$1;
using $IOException = ::java::io::IOException;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $SecurityManager = ::java::lang::SecurityManager;
using $FileChannel = ::java::nio::channels::FileChannel;
using $JavaIOFileDescriptorAccess = ::jdk::internal::access::JavaIOFileDescriptorAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $FileChannelImpl = ::sun::nio::ch::FileChannelImpl;

namespace java {
	namespace io {

$FieldInfo _FileOutputStream_FieldInfo_[] = {
	{"fdAccess", "Ljdk/internal/access/JavaIOFileDescriptorAccess;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(FileOutputStream, fdAccess)},
	{"fd", "Ljava/io/FileDescriptor;", nullptr, $PRIVATE | $FINAL, $field(FileOutputStream, fd)},
	{"channel", "Ljava/nio/channels/FileChannel;", nullptr, $PRIVATE | $VOLATILE, $field(FileOutputStream, channel)},
	{"path", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(FileOutputStream, path)},
	{"closeLock", "Ljava/lang/Object;", nullptr, $PRIVATE | $FINAL, $field(FileOutputStream, closeLock)},
	{"closed", "Z", nullptr, $PRIVATE | $VOLATILE, $field(FileOutputStream, closed)},
	{}
};

$MethodInfo _FileOutputStream_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(FileOutputStream, init$, void, $String*), "java.io.FileNotFoundException"},
	{"<init>", "(Ljava/lang/String;Z)V", nullptr, $PUBLIC, $method(FileOutputStream, init$, void, $String*, bool), "java.io.FileNotFoundException"},
	{"<init>", "(Ljava/io/File;)V", nullptr, $PUBLIC, $method(FileOutputStream, init$, void, $File*), "java.io.FileNotFoundException"},
	{"<init>", "(Ljava/io/File;Z)V", nullptr, $PUBLIC, $method(FileOutputStream, init$, void, $File*, bool), "java.io.FileNotFoundException"},
	{"<init>", "(Ljava/io/FileDescriptor;)V", nullptr, $PUBLIC, $method(FileOutputStream, init$, void, $FileDescriptor*)},
	{"close", "()V", nullptr, $PUBLIC, $virtualMethod(FileOutputStream, close, void), "java.io.IOException"},
	{"getChannel", "()Ljava/nio/channels/FileChannel;", nullptr, $PUBLIC, $virtualMethod(FileOutputStream, getChannel, $FileChannel*)},
	{"getFD", "()Ljava/io/FileDescriptor;", nullptr, $PUBLIC | $FINAL, $method(FileOutputStream, getFD, $FileDescriptor*), "java.io.IOException"},
	{"initIDs", "()V", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(FileOutputStream, initIDs, void)},
	{"open", "(Ljava/lang/String;Z)V", nullptr, $PRIVATE, $method(FileOutputStream, open, void, $String*, bool), "java.io.FileNotFoundException"},
	{"open0", "(Ljava/lang/String;Z)V", nullptr, $PRIVATE | $NATIVE, $method(FileOutputStream, open0, void, $String*, bool), "java.io.FileNotFoundException"},
	{"write", "(IZ)V", nullptr, $PRIVATE | $NATIVE, $method(FileOutputStream, write, void, int32_t, bool), "java.io.IOException"},
	{"write", "(I)V", nullptr, $PUBLIC, $virtualMethod(FileOutputStream, write, void, int32_t), "java.io.IOException"},
	{"write", "([B)V", nullptr, $PUBLIC, $virtualMethod(FileOutputStream, write, void, $bytes*), "java.io.IOException"},
	{"write", "([BII)V", nullptr, $PUBLIC, $virtualMethod(FileOutputStream, write, void, $bytes*, int32_t, int32_t), "java.io.IOException"},
	{"writeBytes", "([BIIZ)V", nullptr, $PRIVATE | $NATIVE, $method(FileOutputStream, writeBytes, void, $bytes*, int32_t, int32_t, bool), "java.io.IOException"},
	{}
};

#define _METHOD_INDEX_initIDs 8
#define _METHOD_INDEX_open0 10
#define _METHOD_INDEX_write 11
#define _METHOD_INDEX_writeBytes 15

$InnerClassInfo _FileOutputStream_InnerClassesInfo_[] = {
	{"java.io.FileOutputStream$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _FileOutputStream_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.io.FileOutputStream",
	"java.io.OutputStream",
	nullptr,
	_FileOutputStream_FieldInfo_,
	_FileOutputStream_MethodInfo_,
	nullptr,
	nullptr,
	_FileOutputStream_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.io.FileOutputStream$1"
};

$Object* allocate$FileOutputStream($Class* clazz) {
	return $of($alloc(FileOutputStream));
}

$JavaIOFileDescriptorAccess* FileOutputStream::fdAccess = nullptr;

void FileOutputStream::init$($String* name) {
	FileOutputStream::init$(name != nullptr ? $$new($File, name) : ($File*)nullptr, false);
}

void FileOutputStream::init$($String* name, bool append) {
	FileOutputStream::init$(name != nullptr ? $$new($File, name) : ($File*)nullptr, append);
}

void FileOutputStream::init$($File* file) {
	FileOutputStream::init$(file, false);
}

void FileOutputStream::init$($File* file, bool append) {
	$useLocalCurrentObjectStackCache();
	$OutputStream::init$();
	$set(this, closeLock, $new($Object));
	$var($String, name, file != nullptr ? $nc(file)->getPath() : ($String*)nullptr);
	$var($SecurityManager, security, $System::getSecurityManager());
	if (security != nullptr) {
		security->checkWrite(name);
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
	open(name, append);
	$FileCleanable::register$(this->fd);
}

void FileOutputStream::init$($FileDescriptor* fdObj) {
	$OutputStream::init$();
	$set(this, closeLock, $new($Object));
	$var($SecurityManager, security, $System::getSecurityManager());
	if (fdObj == nullptr) {
		$throwNew($NullPointerException);
	}
	if (security != nullptr) {
		security->checkWrite(fdObj);
	}
	$set(this, fd, fdObj);
	$set(this, path, nullptr);
	$nc(this->fd)->attach(this);
}

void FileOutputStream::open0($String* name, bool append) {
	$prepareNative(FileOutputStream, open0, void, $String* name, bool append);
	$invokeNative(name, append);
	$finishNative();
}

void FileOutputStream::open($String* name, bool append) {
	open0(name, append);
}

void FileOutputStream::write(int32_t b, bool append) {
	$prepareNative(FileOutputStream, write, void, int32_t b, bool append);
	$invokeNative(b, append);
	$finishNative();
}

void FileOutputStream::write(int32_t b) {
	write(b, $nc(FileOutputStream::fdAccess)->getAppend(this->fd));
}

void FileOutputStream::writeBytes($bytes* b, int32_t off, int32_t len, bool append) {
	$prepareNative(FileOutputStream, writeBytes, void, $bytes* b, int32_t off, int32_t len, bool append);
	$invokeNative(b, off, len, append);
	$finishNative();
}

void FileOutputStream::write($bytes* b) {
	writeBytes(b, 0, $nc(b)->length, $nc(FileOutputStream::fdAccess)->getAppend(this->fd));
}

void FileOutputStream::write($bytes* b, int32_t off, int32_t len) {
	writeBytes(b, off, len, $nc(FileOutputStream::fdAccess)->getAppend(this->fd));
}

void FileOutputStream::close() {
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
	$nc(this->fd)->closeAll($$new($FileOutputStream$1, this));
}

$FileDescriptor* FileOutputStream::getFD() {
	if (this->fd != nullptr) {
		return this->fd;
	}
	$throwNew($IOException);
}

$FileChannel* FileOutputStream::getChannel() {
	$var($FileChannel, fc, this->channel);
	if (fc == nullptr) {
		$synchronized(this) {
			$assign(fc, this->channel);
			if (fc == nullptr) {
				$set(this, channel, ($assign(fc, $FileChannelImpl::open(this->fd, this->path, false, true, false, this))));
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

void FileOutputStream::initIDs() {
	$init(FileOutputStream);
	$prepareNativeStatic(FileOutputStream, initIDs, void);
	$invokeNativeStatic();
	$finishNativeStatic();
}

void clinit$FileOutputStream($Class* class$) {
	$assignStatic(FileOutputStream::fdAccess, $SharedSecrets::getJavaIOFileDescriptorAccess());
	{
		FileOutputStream::initIDs();
	}
}

FileOutputStream::FileOutputStream() {
}

$Class* FileOutputStream::load$($String* name, bool initialize) {
	$loadClass(FileOutputStream, name, initialize, &_FileOutputStream_ClassInfo_, clinit$FileOutputStream, allocate$FileOutputStream);
	return class$;
}

$Class* FileOutputStream::class$ = nullptr;

	} // io
} // java