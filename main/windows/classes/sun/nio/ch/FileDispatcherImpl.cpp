#include <sun/nio/ch/FileDispatcherImpl.h>

#include <java/io/File.h>
#include <java/io/FileDescriptor.h>
#include <java/io/IOException.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/nio/CharBuffer.h>
#include <java/nio/channels/SelectableChannel.h>
#include <jdk/internal/access/JavaIOFileDescriptorAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <sun/nio/ch/FileDispatcher.h>
#include <sun/nio/ch/IOUtil.h>
#include <sun/security/action/GetPropertyAction.h>
#include <jcpp.h>

using $File = ::java::io::File;
using $FileDescriptor = ::java::io::FileDescriptor;
using $IOException = ::java::io::IOException;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $CharBuffer = ::java::nio::CharBuffer;
using $SelectableChannel = ::java::nio::channels::SelectableChannel;
using $JavaIOFileDescriptorAccess = ::jdk::internal::access::JavaIOFileDescriptorAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $FileDispatcher = ::sun::nio::ch::FileDispatcher;
using $IOUtil = ::sun::nio::ch::IOUtil;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;

namespace sun {
	namespace nio {
		namespace ch {

$FieldInfo _FileDispatcherImpl_FieldInfo_[] = {
	{"fdAccess", "Ljdk/internal/access/JavaIOFileDescriptorAccess;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(FileDispatcherImpl, fdAccess)},
	{"fastFileTransfer", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(FileDispatcherImpl, fastFileTransfer)},
	{}
};

$MethodInfo _FileDispatcherImpl_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(FileDispatcherImpl, init$, void)},
	{"canTransferToDirectly", "(Ljava/nio/channels/SelectableChannel;)Z", nullptr, 0, $virtualMethod(FileDispatcherImpl, canTransferToDirectly, bool, $SelectableChannel*)},
	{"close", "(Ljava/io/FileDescriptor;)V", nullptr, 0, $virtualMethod(FileDispatcherImpl, close, void, $FileDescriptor*), "java.io.IOException"},
	{"close0", "(Ljava/io/FileDescriptor;)V", nullptr, $STATIC | $NATIVE, $staticMethod(FileDispatcherImpl, close0, void, $FileDescriptor*), "java.io.IOException"},
	{"duplicateForMapping", "(Ljava/io/FileDescriptor;)Ljava/io/FileDescriptor;", nullptr, 0, $virtualMethod(FileDispatcherImpl, duplicateForMapping, $FileDescriptor*, $FileDescriptor*), "java.io.IOException"},
	{"duplicateHandle", "(J)J", nullptr, $STATIC | $NATIVE, $staticMethod(FileDispatcherImpl, duplicateHandle, int64_t, int64_t), "java.io.IOException"},
	{"force", "(Ljava/io/FileDescriptor;Z)I", nullptr, 0, $virtualMethod(FileDispatcherImpl, force, int32_t, $FileDescriptor*, bool), "java.io.IOException"},
	{"force0", "(Ljava/io/FileDescriptor;Z)I", nullptr, $STATIC | $NATIVE, $staticMethod(FileDispatcherImpl, force0, int32_t, $FileDescriptor*, bool), "java.io.IOException"},
	{"isFastFileTransferRequested", "()Z", nullptr, $STATIC, $staticMethod(FileDispatcherImpl, isFastFileTransferRequested, bool)},
	{"lock", "(Ljava/io/FileDescriptor;ZJJZ)I", nullptr, 0, $virtualMethod(FileDispatcherImpl, lock, int32_t, $FileDescriptor*, bool, int64_t, int64_t, bool), "java.io.IOException"},
	{"lock0", "(Ljava/io/FileDescriptor;ZJJZ)I", nullptr, $STATIC | $NATIVE, $staticMethod(FileDispatcherImpl, lock0, int32_t, $FileDescriptor*, bool, int64_t, int64_t, bool), "java.io.IOException"},
	{"needsPositionLock", "()Z", nullptr, 0, $virtualMethod(FileDispatcherImpl, needsPositionLock, bool)},
	{"pread", "(Ljava/io/FileDescriptor;JIJ)I", nullptr, 0, $virtualMethod(FileDispatcherImpl, pread, int32_t, $FileDescriptor*, int64_t, int32_t, int64_t), "java.io.IOException"},
	{"pread0", "(Ljava/io/FileDescriptor;JIJ)I", nullptr, $STATIC | $NATIVE, $staticMethod(FileDispatcherImpl, pread0, int32_t, $FileDescriptor*, int64_t, int32_t, int64_t), "java.io.IOException"},
	{"pwrite", "(Ljava/io/FileDescriptor;JIJ)I", nullptr, 0, $virtualMethod(FileDispatcherImpl, pwrite, int32_t, $FileDescriptor*, int64_t, int32_t, int64_t), "java.io.IOException"},
	{"pwrite0", "(Ljava/io/FileDescriptor;JIJ)I", nullptr, $STATIC | $NATIVE, $staticMethod(FileDispatcherImpl, pwrite0, int32_t, $FileDescriptor*, int64_t, int32_t, int64_t), "java.io.IOException"},
	{"read", "(Ljava/io/FileDescriptor;JI)I", nullptr, 0, $virtualMethod(FileDispatcherImpl, read, int32_t, $FileDescriptor*, int64_t, int32_t), "java.io.IOException"},
	{"read0", "(Ljava/io/FileDescriptor;JI)I", nullptr, $STATIC | $NATIVE, $staticMethod(FileDispatcherImpl, read0, int32_t, $FileDescriptor*, int64_t, int32_t), "java.io.IOException"},
	{"readv", "(Ljava/io/FileDescriptor;JI)J", nullptr, 0, $virtualMethod(FileDispatcherImpl, readv, int64_t, $FileDescriptor*, int64_t, int32_t), "java.io.IOException"},
	{"readv0", "(Ljava/io/FileDescriptor;JI)J", nullptr, $STATIC | $NATIVE, $staticMethod(FileDispatcherImpl, readv0, int64_t, $FileDescriptor*, int64_t, int32_t), "java.io.IOException"},
	{"release", "(Ljava/io/FileDescriptor;JJ)V", nullptr, 0, $virtualMethod(FileDispatcherImpl, release, void, $FileDescriptor*, int64_t, int64_t), "java.io.IOException"},
	{"release0", "(Ljava/io/FileDescriptor;JJ)V", nullptr, $STATIC | $NATIVE, $staticMethod(FileDispatcherImpl, release0, void, $FileDescriptor*, int64_t, int64_t), "java.io.IOException"},
	{"seek", "(Ljava/io/FileDescriptor;J)J", nullptr, 0, $virtualMethod(FileDispatcherImpl, seek, int64_t, $FileDescriptor*, int64_t), "java.io.IOException"},
	{"seek0", "(Ljava/io/FileDescriptor;J)J", nullptr, $STATIC | $NATIVE, $staticMethod(FileDispatcherImpl, seek0, int64_t, $FileDescriptor*, int64_t), "java.io.IOException"},
	{"setDirect0", "(Ljava/io/FileDescriptor;Ljava/nio/CharBuffer;)I", nullptr, $STATIC | $NATIVE, $staticMethod(FileDispatcherImpl, setDirect0, int32_t, $FileDescriptor*, $CharBuffer*), "java.io.IOException"},
	{"setDirectIO", "(Ljava/io/FileDescriptor;Ljava/lang/String;)I", nullptr, 0, $virtualMethod(FileDispatcherImpl, setDirectIO, int32_t, $FileDescriptor*, $String*)},
	{"size", "(Ljava/io/FileDescriptor;)J", nullptr, 0, $virtualMethod(FileDispatcherImpl, size, int64_t, $FileDescriptor*), "java.io.IOException"},
	{"size0", "(Ljava/io/FileDescriptor;)J", nullptr, $STATIC | $NATIVE, $staticMethod(FileDispatcherImpl, size0, int64_t, $FileDescriptor*), "java.io.IOException"},
	{"transferToDirectlyNeedsPositionLock", "()Z", nullptr, 0, $virtualMethod(FileDispatcherImpl, transferToDirectlyNeedsPositionLock, bool)},
	{"truncate", "(Ljava/io/FileDescriptor;J)I", nullptr, 0, $virtualMethod(FileDispatcherImpl, truncate, int32_t, $FileDescriptor*, int64_t), "java.io.IOException"},
	{"truncate0", "(Ljava/io/FileDescriptor;J)I", nullptr, $STATIC | $NATIVE, $staticMethod(FileDispatcherImpl, truncate0, int32_t, $FileDescriptor*, int64_t), "java.io.IOException"},
	{"write", "(Ljava/io/FileDescriptor;JI)I", nullptr, 0, $virtualMethod(FileDispatcherImpl, write, int32_t, $FileDescriptor*, int64_t, int32_t), "java.io.IOException"},
	{"write0", "(Ljava/io/FileDescriptor;JIZ)I", nullptr, $STATIC | $NATIVE, $staticMethod(FileDispatcherImpl, write0, int32_t, $FileDescriptor*, int64_t, int32_t, bool), "java.io.IOException"},
	{"writev", "(Ljava/io/FileDescriptor;JI)J", nullptr, 0, $virtualMethod(FileDispatcherImpl, writev, int64_t, $FileDescriptor*, int64_t, int32_t), "java.io.IOException"},
	{"writev0", "(Ljava/io/FileDescriptor;JIZ)J", nullptr, $STATIC | $NATIVE, $staticMethod(FileDispatcherImpl, writev0, int64_t, $FileDescriptor*, int64_t, int32_t, bool), "java.io.IOException"},
	{}
};

#define _METHOD_INDEX_close0 3
#define _METHOD_INDEX_duplicateHandle 5
#define _METHOD_INDEX_force0 7
#define _METHOD_INDEX_lock0 10
#define _METHOD_INDEX_pread0 13
#define _METHOD_INDEX_pwrite0 15
#define _METHOD_INDEX_read0 17
#define _METHOD_INDEX_readv0 19
#define _METHOD_INDEX_release0 21
#define _METHOD_INDEX_seek0 23
#define _METHOD_INDEX_setDirect0 24
#define _METHOD_INDEX_size0 27
#define _METHOD_INDEX_truncate0 30
#define _METHOD_INDEX_write0 32
#define _METHOD_INDEX_writev0 34

$ClassInfo _FileDispatcherImpl_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.ch.FileDispatcherImpl",
	"sun.nio.ch.FileDispatcher",
	nullptr,
	_FileDispatcherImpl_FieldInfo_,
	_FileDispatcherImpl_MethodInfo_
};

$Object* allocate$FileDispatcherImpl($Class* clazz) {
	return $of($alloc(FileDispatcherImpl));
}

$JavaIOFileDescriptorAccess* FileDispatcherImpl::fdAccess = nullptr;
bool FileDispatcherImpl::fastFileTransfer = false;

void FileDispatcherImpl::init$() {
	$FileDispatcher::init$();
}

bool FileDispatcherImpl::needsPositionLock() {
	return true;
}

int32_t FileDispatcherImpl::read($FileDescriptor* fd, int64_t address, int32_t len) {
	return read0(fd, address, len);
}

int32_t FileDispatcherImpl::pread($FileDescriptor* fd, int64_t address, int32_t len, int64_t position) {
	return pread0(fd, address, len, position);
}

int64_t FileDispatcherImpl::readv($FileDescriptor* fd, int64_t address, int32_t len) {
	return readv0(fd, address, len);
}

int32_t FileDispatcherImpl::write($FileDescriptor* fd, int64_t address, int32_t len) {
	return write0(fd, address, len, $nc(FileDispatcherImpl::fdAccess)->getAppend(fd));
}

int32_t FileDispatcherImpl::pwrite($FileDescriptor* fd, int64_t address, int32_t len, int64_t position) {
	return pwrite0(fd, address, len, position);
}

int64_t FileDispatcherImpl::writev($FileDescriptor* fd, int64_t address, int32_t len) {
	return writev0(fd, address, len, $nc(FileDispatcherImpl::fdAccess)->getAppend(fd));
}

int64_t FileDispatcherImpl::seek($FileDescriptor* fd, int64_t offset) {
	return seek0(fd, offset);
}

int32_t FileDispatcherImpl::force($FileDescriptor* fd, bool metaData) {
	return force0(fd, metaData);
}

int32_t FileDispatcherImpl::truncate($FileDescriptor* fd, int64_t size) {
	return truncate0(fd, size);
}

int64_t FileDispatcherImpl::size($FileDescriptor* fd) {
	return size0(fd);
}

int32_t FileDispatcherImpl::lock($FileDescriptor* fd, bool blocking, int64_t pos, int64_t size, bool shared) {
	return lock0(fd, blocking, pos, size, shared);
}

void FileDispatcherImpl::release($FileDescriptor* fd, int64_t pos, int64_t size) {
	release0(fd, pos, size);
}

void FileDispatcherImpl::close($FileDescriptor* fd) {
	$nc(FileDispatcherImpl::fdAccess)->close(fd);
}

$FileDescriptor* FileDispatcherImpl::duplicateForMapping($FileDescriptor* fd) {
	$var($FileDescriptor, result, $new($FileDescriptor));
	int64_t handle = duplicateHandle($nc(FileDispatcherImpl::fdAccess)->getHandle(fd));
	$nc(FileDispatcherImpl::fdAccess)->setHandle(result, handle);
	$nc(FileDispatcherImpl::fdAccess)->registerCleanup(result);
	return result;
}

bool FileDispatcherImpl::canTransferToDirectly($SelectableChannel* sc) {
	return FileDispatcherImpl::fastFileTransfer && $nc(sc)->isBlocking();
}

bool FileDispatcherImpl::transferToDirectlyNeedsPositionLock() {
	return true;
}

int32_t FileDispatcherImpl::setDirectIO($FileDescriptor* fd, $String* path) {
	$useLocalCurrentObjectStackCache();
	int32_t result = -1;
	$init($File);
	$var($String, filePath, $nc(path)->substring(0, path->lastIndexOf($File::separator)));
	$var($CharBuffer, buffer, $CharBuffer::allocate(filePath->length()));
	$nc(buffer)->put(filePath);
	try {
		result = setDirect0(fd, buffer);
	} catch ($IOException& e) {
		$throwNew($UnsupportedOperationException, "Error setting up DirectIO"_s, e);
	}
	return result;
}

bool FileDispatcherImpl::isFastFileTransferRequested() {
	$init(FileDispatcherImpl);
	$var($String, fileTransferProp, $GetPropertyAction::privilegedGetProperty("jdk.nio.enableFastFileTransfer"_s, "false"_s));
	return $nc(fileTransferProp)->isEmpty() ? true : $Boolean::parseBoolean(fileTransferProp);
}

int32_t FileDispatcherImpl::read0($FileDescriptor* fd, int64_t address, int32_t len) {
	$init(FileDispatcherImpl);
	int32_t $ret = 0;
	$prepareNativeStatic(FileDispatcherImpl, read0, int32_t, $FileDescriptor* fd, int64_t address, int32_t len);
	$ret = $invokeNativeStatic(fd, address, len);
	$finishNativeStatic();
	return $ret;
}

int32_t FileDispatcherImpl::pread0($FileDescriptor* fd, int64_t address, int32_t len, int64_t position) {
	$init(FileDispatcherImpl);
	int32_t $ret = 0;
	$prepareNativeStatic(FileDispatcherImpl, pread0, int32_t, $FileDescriptor* fd, int64_t address, int32_t len, int64_t position);
	$ret = $invokeNativeStatic(fd, address, len, position);
	$finishNativeStatic();
	return $ret;
}

int64_t FileDispatcherImpl::readv0($FileDescriptor* fd, int64_t address, int32_t len) {
	$init(FileDispatcherImpl);
	int64_t $ret = 0;
	$prepareNativeStatic(FileDispatcherImpl, readv0, int64_t, $FileDescriptor* fd, int64_t address, int32_t len);
	$ret = $invokeNativeStatic(fd, address, len);
	$finishNativeStatic();
	return $ret;
}

int32_t FileDispatcherImpl::write0($FileDescriptor* fd, int64_t address, int32_t len, bool append) {
	$init(FileDispatcherImpl);
	int32_t $ret = 0;
	$prepareNativeStatic(FileDispatcherImpl, write0, int32_t, $FileDescriptor* fd, int64_t address, int32_t len, bool append);
	$ret = $invokeNativeStatic(fd, address, len, append);
	$finishNativeStatic();
	return $ret;
}

int32_t FileDispatcherImpl::pwrite0($FileDescriptor* fd, int64_t address, int32_t len, int64_t position) {
	$init(FileDispatcherImpl);
	int32_t $ret = 0;
	$prepareNativeStatic(FileDispatcherImpl, pwrite0, int32_t, $FileDescriptor* fd, int64_t address, int32_t len, int64_t position);
	$ret = $invokeNativeStatic(fd, address, len, position);
	$finishNativeStatic();
	return $ret;
}

int64_t FileDispatcherImpl::writev0($FileDescriptor* fd, int64_t address, int32_t len, bool append) {
	$init(FileDispatcherImpl);
	int64_t $ret = 0;
	$prepareNativeStatic(FileDispatcherImpl, writev0, int64_t, $FileDescriptor* fd, int64_t address, int32_t len, bool append);
	$ret = $invokeNativeStatic(fd, address, len, append);
	$finishNativeStatic();
	return $ret;
}

int64_t FileDispatcherImpl::seek0($FileDescriptor* fd, int64_t offset) {
	$init(FileDispatcherImpl);
	int64_t $ret = 0;
	$prepareNativeStatic(FileDispatcherImpl, seek0, int64_t, $FileDescriptor* fd, int64_t offset);
	$ret = $invokeNativeStatic(fd, offset);
	$finishNativeStatic();
	return $ret;
}

int32_t FileDispatcherImpl::force0($FileDescriptor* fd, bool metaData) {
	$init(FileDispatcherImpl);
	int32_t $ret = 0;
	$prepareNativeStatic(FileDispatcherImpl, force0, int32_t, $FileDescriptor* fd, bool metaData);
	$ret = $invokeNativeStatic(fd, metaData);
	$finishNativeStatic();
	return $ret;
}

int32_t FileDispatcherImpl::truncate0($FileDescriptor* fd, int64_t size) {
	$init(FileDispatcherImpl);
	int32_t $ret = 0;
	$prepareNativeStatic(FileDispatcherImpl, truncate0, int32_t, $FileDescriptor* fd, int64_t size);
	$ret = $invokeNativeStatic(fd, size);
	$finishNativeStatic();
	return $ret;
}

int64_t FileDispatcherImpl::size0($FileDescriptor* fd) {
	$init(FileDispatcherImpl);
	int64_t $ret = 0;
	$prepareNativeStatic(FileDispatcherImpl, size0, int64_t, $FileDescriptor* fd);
	$ret = $invokeNativeStatic(fd);
	$finishNativeStatic();
	return $ret;
}

int32_t FileDispatcherImpl::lock0($FileDescriptor* fd, bool blocking, int64_t pos, int64_t size, bool shared) {
	$init(FileDispatcherImpl);
	int32_t $ret = 0;
	$prepareNativeStatic(FileDispatcherImpl, lock0, int32_t, $FileDescriptor* fd, bool blocking, int64_t pos, int64_t size, bool shared);
	$ret = $invokeNativeStatic(fd, blocking, pos, size, shared);
	$finishNativeStatic();
	return $ret;
}

void FileDispatcherImpl::release0($FileDescriptor* fd, int64_t pos, int64_t size) {
	$init(FileDispatcherImpl);
	$prepareNativeStatic(FileDispatcherImpl, release0, void, $FileDescriptor* fd, int64_t pos, int64_t size);
	$invokeNativeStatic(fd, pos, size);
	$finishNativeStatic();
}

void FileDispatcherImpl::close0($FileDescriptor* fd) {
	$init(FileDispatcherImpl);
	$prepareNativeStatic(FileDispatcherImpl, close0, void, $FileDescriptor* fd);
	$invokeNativeStatic(fd);
	$finishNativeStatic();
}

int64_t FileDispatcherImpl::duplicateHandle(int64_t fd) {
	$init(FileDispatcherImpl);
	int64_t $ret = 0;
	$prepareNativeStatic(FileDispatcherImpl, duplicateHandle, int64_t, int64_t fd);
	$ret = $invokeNativeStatic(fd);
	$finishNativeStatic();
	return $ret;
}

int32_t FileDispatcherImpl::setDirect0($FileDescriptor* fd, $CharBuffer* buffer) {
	$init(FileDispatcherImpl);
	int32_t $ret = 0;
	$prepareNativeStatic(FileDispatcherImpl, setDirect0, int32_t, $FileDescriptor* fd, $CharBuffer* buffer);
	$ret = $invokeNativeStatic(fd, buffer);
	$finishNativeStatic();
	return $ret;
}

void clinit$FileDispatcherImpl($Class* class$) {
	$assignStatic(FileDispatcherImpl::fdAccess, $SharedSecrets::getJavaIOFileDescriptorAccess());
	{
		$IOUtil::load();
		FileDispatcherImpl::fastFileTransfer = FileDispatcherImpl::isFastFileTransferRequested();
	}
}

FileDispatcherImpl::FileDispatcherImpl() {
}

$Class* FileDispatcherImpl::load$($String* name, bool initialize) {
	$loadClass(FileDispatcherImpl, name, initialize, &_FileDispatcherImpl_ClassInfo_, clinit$FileDispatcherImpl, allocate$FileDispatcherImpl);
	return class$;
}

$Class* FileDispatcherImpl::class$ = nullptr;

		} // ch
	} // nio
} // sun