#include <java/io/FileDescriptor.h>

#include <java/io/Closeable.h>
#include <java/io/FileDescriptor$1.h>
#include <java/io/IOException.h>
#include <java/util/ArrayList.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <jdk/internal/access/JavaIOFileDescriptorAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jdk/internal/ref/PhantomCleanable.h>
#include <jcpp.h>

using $Closeable = ::java::io::Closeable;
using $FileDescriptor$1 = ::java::io::FileDescriptor$1;
using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ArrayList = ::java::util::ArrayList;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $JavaIOFileDescriptorAccess = ::jdk::internal::access::JavaIOFileDescriptorAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $PhantomCleanable = ::jdk::internal::ref::PhantomCleanable;

namespace java {
	namespace io {

$FieldInfo _FileDescriptor_FieldInfo_[] = {
	{"fd", "I", nullptr, $PRIVATE, $field(FileDescriptor, fd)},
	{"handle", "J", nullptr, $PRIVATE, $field(FileDescriptor, handle)},
	{"parent", "Ljava/io/Closeable;", nullptr, $PRIVATE, $field(FileDescriptor, parent)},
	{"otherParents", "Ljava/util/List;", "Ljava/util/List<Ljava/io/Closeable;>;", $PRIVATE, $field(FileDescriptor, otherParents)},
	{"closed", "Z", nullptr, $PRIVATE, $field(FileDescriptor, closed)},
	{"append", "Z", nullptr, $PRIVATE, $field(FileDescriptor, append)},
	{"cleanup", "Ljdk/internal/ref/PhantomCleanable;", "Ljdk/internal/ref/PhantomCleanable<Ljava/io/FileDescriptor;>;", $PRIVATE, $field(FileDescriptor, cleanup)},
	{"in", "Ljava/io/FileDescriptor;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(FileDescriptor, in)},
	{"out", "Ljava/io/FileDescriptor;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(FileDescriptor, out)},
	{"err", "Ljava/io/FileDescriptor;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(FileDescriptor, err)},
	{}
};

$MethodInfo _FileDescriptor_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(FileDescriptor, init$, void)},
	{"<init>", "(I)V", nullptr, $PRIVATE, $method(FileDescriptor, init$, void, int32_t)},
	{"attach", "(Ljava/io/Closeable;)V", nullptr, $SYNCHRONIZED, $method(FileDescriptor, attach, void, $Closeable*)},
	{"close", "()V", nullptr, $SYNCHRONIZED, $method(FileDescriptor, close, void), "java.io.IOException"},
	{"close0", "()V", nullptr, $PRIVATE | $NATIVE, $method(FileDescriptor, close0, void), "java.io.IOException"},
	{"closeAll", "(Ljava/io/Closeable;)V", nullptr, $SYNCHRONIZED, $method(FileDescriptor, closeAll, void, $Closeable*), "java.io.IOException"},
	{"getAppend", "(I)Z", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(FileDescriptor, getAppend, bool, int32_t)},
	{"getHandle", "(I)J", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(FileDescriptor, getHandle, int64_t, int32_t)},
	{"initIDs", "()V", nullptr, $PRIVATE | $STATIC | $NATIVE, $staticMethod(FileDescriptor, initIDs, void)},
	{"registerCleanup", "(Ljdk/internal/ref/PhantomCleanable;)V", "(Ljdk/internal/ref/PhantomCleanable<Ljava/io/FileDescriptor;>;)V", $SYNCHRONIZED, $method(FileDescriptor, registerCleanup, void, $PhantomCleanable*)},
	{"set", "(I)V", nullptr, $SYNCHRONIZED, $method(FileDescriptor, set, void, int32_t)},
	{"setHandle", "(J)V", nullptr, 0, $method(FileDescriptor, setHandle, void, int64_t)},
	{"sync", "()V", nullptr, $PUBLIC | $NATIVE, $method(FileDescriptor, sync, void), "java.io.SyncFailedException"},
	{"unregisterCleanup", "()V", nullptr, $SYNCHRONIZED, $method(FileDescriptor, unregisterCleanup, void)},
	{"valid", "()Z", nullptr, $PUBLIC, $method(FileDescriptor, valid, bool)},
	{}
};

#define _METHOD_INDEX_close0 4
#define _METHOD_INDEX_getAppend 6
#define _METHOD_INDEX_getHandle 7
#define _METHOD_INDEX_initIDs 8
#define _METHOD_INDEX_sync 12

$InnerClassInfo _FileDescriptor_InnerClassesInfo_[] = {
	{"java.io.FileDescriptor$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _FileDescriptor_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.io.FileDescriptor",
	"java.lang.Object",
	nullptr,
	_FileDescriptor_FieldInfo_,
	_FileDescriptor_MethodInfo_,
	nullptr,
	nullptr,
	_FileDescriptor_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.io.FileDescriptor$1"
};

$Object* allocate$FileDescriptor($Class* clazz) {
	return $of($alloc(FileDescriptor));
}

FileDescriptor* FileDescriptor::in = nullptr;
FileDescriptor* FileDescriptor::out = nullptr;
FileDescriptor* FileDescriptor::err = nullptr;

void FileDescriptor::init$() {
	this->fd = -1;
	this->handle = -1;
}

void FileDescriptor::init$(int32_t fd) {
	this->fd = fd;
	this->handle = getHandle(fd);
	this->append = getAppend(fd);
}

bool FileDescriptor::valid() {
	return (this->handle != -1) || (this->fd != -1);
}

void FileDescriptor::sync() {
	$prepareNative(FileDescriptor, sync, void);
	$invokeNative();
	$finishNative();
}

void FileDescriptor::initIDs() {
	$init(FileDescriptor);
	$prepareNativeStatic(FileDescriptor, initIDs, void);
	$invokeNativeStatic();
	$finishNativeStatic();
}

int64_t FileDescriptor::getHandle(int32_t d) {
	$init(FileDescriptor);
	int64_t $ret = 0;
	$prepareNativeStatic(FileDescriptor, getHandle, int64_t, int32_t d);
	$ret = $invokeNativeStatic(d);
	$finishNativeStatic();
	return $ret;
}

bool FileDescriptor::getAppend(int32_t fd) {
	$init(FileDescriptor);
	bool $ret = false;
	$prepareNativeStatic(FileDescriptor, getAppend, bool, int32_t fd);
	$ret = $invokeNativeStatic(fd);
	$finishNativeStatic();
	return $ret;
}

void FileDescriptor::set(int32_t fd) {
	$synchronized(this) {
		if (fd == -1 && this->cleanup != nullptr) {
			$nc(this->cleanup)->clear();
			$set(this, cleanup, nullptr);
		}
		this->fd = fd;
	}
}

void FileDescriptor::setHandle(int64_t handle) {
	if (handle == -1 && this->cleanup != nullptr) {
		$nc(this->cleanup)->clear();
		$set(this, cleanup, nullptr);
	}
	this->handle = handle;
}

void FileDescriptor::registerCleanup($PhantomCleanable* cleanable) {
	$synchronized(this) {
		$Objects::requireNonNull($of(cleanable), "cleanable"_s);
		if (this->cleanup != nullptr) {
			$nc(this->cleanup)->clear();
		}
		$set(this, cleanup, cleanable);
	}
}

void FileDescriptor::unregisterCleanup() {
	$synchronized(this) {
		if (this->cleanup != nullptr) {
			$nc(this->cleanup)->clear();
		}
		$set(this, cleanup, nullptr);
	}
}

void FileDescriptor::close() {
	$synchronized(this) {
		unregisterCleanup();
		close0();
	}
}

void FileDescriptor::close0() {
	$prepareNative(FileDescriptor, close0, void);
	$invokeNative();
	$finishNative();
}

void FileDescriptor::attach($Closeable* c) {
	$synchronized(this) {
		if (this->parent == nullptr) {
			$set(this, parent, c);
		} else if (this->otherParents == nullptr) {
			$set(this, otherParents, $new($ArrayList));
			$nc(this->otherParents)->add(this->parent);
			$nc(this->otherParents)->add(c);
		} else {
			$nc(this->otherParents)->add(c);
		}
	}
}

void FileDescriptor::closeAll($Closeable* releaser) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (!this->closed) {
			this->closed = true;
			$var($IOException, ioe, nullptr);
			{
				$var($Throwable, var$0, nullptr);
				try {
					try {
						$var($Closeable, twrVar0$, releaser);
						{
							$var($Throwable, var$1, nullptr);
							try {
								try {
									if (this->otherParents != nullptr) {
										{
											$var($Iterator, i$, $nc(this->otherParents)->iterator());
											for (; $nc(i$)->hasNext();) {
												$var($Closeable, referent, $cast($Closeable, i$->next()));
												{
													try {
														$nc(referent)->close();
													} catch ($IOException& x) {
														if (ioe == nullptr) {
															$assign(ioe, x);
														} else {
															$nc(ioe)->addSuppressed(x);
														}
													}
												}
											}
										}
									}
								} catch ($Throwable& t$) {
									if (twrVar0$ != nullptr) {
										try {
											twrVar0$->close();
										} catch ($Throwable& x2) {
											t$->addSuppressed(x2);
										}
									}
									$throw(t$);
								}
							} catch ($Throwable& var$2) {
								$assign(var$1, var$2);
							} /*finally*/ {
								if (twrVar0$ != nullptr) {
									twrVar0$->close();
								}
							}
							if (var$1 != nullptr) {
								$throw(var$1);
							}
						}
					} catch ($IOException& ex) {
						if (ioe != nullptr) {
							ex->addSuppressed(ioe);
						}
						$assign(ioe, ex);
					}
				} catch ($Throwable& var$3) {
					$assign(var$0, var$3);
				} /*finally*/ {
					if (ioe != nullptr) {
						$throw(ioe);
					}
				}
				if (var$0 != nullptr) {
					$throw(var$0);
				}
			}
		}
	}
}

void clinit$FileDescriptor($Class* class$) {
	{
		FileDescriptor::initIDs();
	}
	{
		$SharedSecrets::setJavaIOFileDescriptorAccess($$new($FileDescriptor$1));
	}
	$assignStatic(FileDescriptor::in, $new(FileDescriptor, 0));
	$assignStatic(FileDescriptor::out, $new(FileDescriptor, 1));
	$assignStatic(FileDescriptor::err, $new(FileDescriptor, 2));
}

FileDescriptor::FileDescriptor() {
}

$Class* FileDescriptor::load$($String* name, bool initialize) {
	$loadClass(FileDescriptor, name, initialize, &_FileDescriptor_ClassInfo_, clinit$FileDescriptor, allocate$FileDescriptor);
	return class$;
}

$Class* FileDescriptor::class$ = nullptr;

	} // io
} // java