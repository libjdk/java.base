#include <sun/nio/fs/UnixUserDefinedFileAttributeView.h>

#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/ref/Reference.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/file/FileSystemException.h>
#include <java/util/ArrayList.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/function/Function.h>
#include <java/util/function/Predicate.h>
#include <java/util/stream/Stream.h>
#include <jdk/internal/misc/Unsafe.h>
#include <sun/nio/ch/DirectBuffer.h>
#include <sun/nio/fs/AbstractUserDefinedFileAttributeView.h>
#include <sun/nio/fs/NativeBuffer.h>
#include <sun/nio/fs/NativeBuffers.h>
#include <sun/nio/fs/UnixConstants.h>
#include <sun/nio/fs/UnixException.h>
#include <sun/nio/fs/UnixNativeDispatcher.h>
#include <sun/nio/fs/UnixPath.h>
#include <sun/nio/fs/Util.h>
#include <jcpp.h>

#undef ARRAY_BYTE_BASE_OFFSET
#undef ERANGE
#undef MAX_LISTXATTR_BUF_SIZE
#undef MIN_LISTXATTR_BUF_SIZE
#undef USER_NAMESPACE

using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Reference = ::java::lang::ref::Reference;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $FileSystemException = ::java::nio::file::FileSystemException;
using $ArrayList = ::java::util::ArrayList;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Function = ::java::util::function::Function;
using $Predicate = ::java::util::function::Predicate;
using $Stream = ::java::util::stream::Stream;
using $Unsafe = ::jdk::internal::misc::Unsafe;
using $DirectBuffer = ::sun::nio::ch::DirectBuffer;
using $AbstractUserDefinedFileAttributeView = ::sun::nio::fs::AbstractUserDefinedFileAttributeView;
using $NativeBuffer = ::sun::nio::fs::NativeBuffer;
using $NativeBuffers = ::sun::nio::fs::NativeBuffers;
using $UnixConstants = ::sun::nio::fs::UnixConstants;
using $UnixException = ::sun::nio::fs::UnixException;
using $UnixNativeDispatcher = ::sun::nio::fs::UnixNativeDispatcher;
using $UnixPath = ::sun::nio::fs::UnixPath;
using $Util = ::sun::nio::fs::Util;

namespace sun {
	namespace nio {
		namespace fs {

class UnixUserDefinedFileAttributeView$$Lambda$lambda$list$0 : public $Predicate {
	$class(UnixUserDefinedFileAttributeView$$Lambda$lambda$list$0, $NO_CLASS_INIT, $Predicate)
public:
	void init$() {
	}
	virtual bool test(Object$* s) override {
		 return UnixUserDefinedFileAttributeView::lambda$list$0($cast($String, s));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<UnixUserDefinedFileAttributeView$$Lambda$lambda$list$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo UnixUserDefinedFileAttributeView$$Lambda$lambda$list$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(UnixUserDefinedFileAttributeView$$Lambda$lambda$list$0, init$, void)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(UnixUserDefinedFileAttributeView$$Lambda$lambda$list$0, test, bool, Object$*)},
	{}
};
$ClassInfo UnixUserDefinedFileAttributeView$$Lambda$lambda$list$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.nio.fs.UnixUserDefinedFileAttributeView$$Lambda$lambda$list$0",
	"java.lang.Object",
	"java.util.function.Predicate",
	nullptr,
	methodInfos
};
$Class* UnixUserDefinedFileAttributeView$$Lambda$lambda$list$0::load$($String* name, bool initialize) {
	$loadClass(UnixUserDefinedFileAttributeView$$Lambda$lambda$list$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* UnixUserDefinedFileAttributeView$$Lambda$lambda$list$0::class$ = nullptr;

class UnixUserDefinedFileAttributeView$$Lambda$lambda$list$1$1 : public $Function {
	$class(UnixUserDefinedFileAttributeView$$Lambda$lambda$list$1$1, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* s) override {
		 return $of(UnixUserDefinedFileAttributeView::lambda$list$1($cast($String, s)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<UnixUserDefinedFileAttributeView$$Lambda$lambda$list$1$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo UnixUserDefinedFileAttributeView$$Lambda$lambda$list$1$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(UnixUserDefinedFileAttributeView$$Lambda$lambda$list$1$1, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(UnixUserDefinedFileAttributeView$$Lambda$lambda$list$1$1, apply, $Object*, Object$*)},
	{}
};
$ClassInfo UnixUserDefinedFileAttributeView$$Lambda$lambda$list$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.nio.fs.UnixUserDefinedFileAttributeView$$Lambda$lambda$list$1$1",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* UnixUserDefinedFileAttributeView$$Lambda$lambda$list$1$1::load$($String* name, bool initialize) {
	$loadClass(UnixUserDefinedFileAttributeView$$Lambda$lambda$list$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* UnixUserDefinedFileAttributeView$$Lambda$lambda$list$1$1::class$ = nullptr;

$FieldInfo _UnixUserDefinedFileAttributeView_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(UnixUserDefinedFileAttributeView, $assertionsDisabled)},
	{"unsafe", "Ljdk/internal/misc/Unsafe;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(UnixUserDefinedFileAttributeView, unsafe)},
	{"USER_NAMESPACE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(UnixUserDefinedFileAttributeView, USER_NAMESPACE)},
	{"MIN_LISTXATTR_BUF_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UnixUserDefinedFileAttributeView, MIN_LISTXATTR_BUF_SIZE)},
	{"MAX_LISTXATTR_BUF_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UnixUserDefinedFileAttributeView, MAX_LISTXATTR_BUF_SIZE)},
	{"file", "Lsun/nio/fs/UnixPath;", nullptr, $PRIVATE | $FINAL, $field(UnixUserDefinedFileAttributeView, file)},
	{"followLinks", "Z", nullptr, $PRIVATE | $FINAL, $field(UnixUserDefinedFileAttributeView, followLinks)},
	{}
};

$MethodInfo _UnixUserDefinedFileAttributeView_MethodInfo_[] = {
	{"<init>", "(Lsun/nio/fs/UnixPath;Z)V", nullptr, 0, $method(UnixUserDefinedFileAttributeView, init$, void, $UnixPath*, bool)},
	{"asList", "(JI)Ljava/util/List;", "(JI)Ljava/util/List<Ljava/lang/String;>;", $PRIVATE | $STATIC, $staticMethod(UnixUserDefinedFileAttributeView, asList, $List*, int64_t, int32_t)},
	{"copyExtendedAttribute", "(I[BI)V", nullptr, $PRIVATE | $STATIC, $staticMethod(UnixUserDefinedFileAttributeView, copyExtendedAttribute, void, int32_t, $bytes*, int32_t), "sun.nio.fs.UnixException"},
	{"copyExtendedAttributes", "(II)V", nullptr, $STATIC, $staticMethod(UnixUserDefinedFileAttributeView, copyExtendedAttributes, void, int32_t, int32_t)},
	{"delete", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(UnixUserDefinedFileAttributeView, delete$, void, $String*), "java.io.IOException"},
	{"lambda$list$0", "(Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(UnixUserDefinedFileAttributeView, lambda$list$0, bool, $String*)},
	{"lambda$list$1", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(UnixUserDefinedFileAttributeView, lambda$list$1, $String*, $String*)},
	{"list", "(II)Ljava/util/List;", "(II)Ljava/util/List<Ljava/lang/String;>;", $PRIVATE | $STATIC, $staticMethod(UnixUserDefinedFileAttributeView, list, $List*, int32_t, int32_t), "sun.nio.fs.UnixException"},
	{"list", "()Ljava/util/List;", "()Ljava/util/List<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(UnixUserDefinedFileAttributeView, list, $List*), "java.io.IOException"},
	{"maxNameLength", "()I", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(UnixUserDefinedFileAttributeView, maxNameLength, int32_t)},
	{"nameAsBytes", "(Lsun/nio/fs/UnixPath;Ljava/lang/String;)[B", nullptr, $PRIVATE, $method(UnixUserDefinedFileAttributeView, nameAsBytes, $bytes*, $UnixPath*, $String*), "java.io.IOException"},
	{"read", "(Ljava/lang/String;Ljava/nio/ByteBuffer;)I", nullptr, $PUBLIC, $virtualMethod(UnixUserDefinedFileAttributeView, read, int32_t, $String*, $ByteBuffer*), "java.io.IOException"},
	{"read", "(Ljava/lang/String;JI)I", nullptr, $PRIVATE, $method(UnixUserDefinedFileAttributeView, read, int32_t, $String*, int64_t, int32_t), "java.io.IOException"},
	{"size", "(Ljava/lang/String;)I", nullptr, $PUBLIC, $virtualMethod(UnixUserDefinedFileAttributeView, size, int32_t, $String*), "java.io.IOException"},
	{"write", "(Ljava/lang/String;Ljava/nio/ByteBuffer;)I", nullptr, $PUBLIC, $virtualMethod(UnixUserDefinedFileAttributeView, write, int32_t, $String*, $ByteBuffer*), "java.io.IOException"},
	{"write", "(Ljava/lang/String;JI)V", nullptr, $PRIVATE, $method(UnixUserDefinedFileAttributeView, write, void, $String*, int64_t, int32_t), "java.io.IOException"},
	{}
};

$ClassInfo _UnixUserDefinedFileAttributeView_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"sun.nio.fs.UnixUserDefinedFileAttributeView",
	"sun.nio.fs.AbstractUserDefinedFileAttributeView",
	nullptr,
	_UnixUserDefinedFileAttributeView_FieldInfo_,
	_UnixUserDefinedFileAttributeView_MethodInfo_
};

$Object* allocate$UnixUserDefinedFileAttributeView($Class* clazz) {
	return $of($alloc(UnixUserDefinedFileAttributeView));
}

bool UnixUserDefinedFileAttributeView::$assertionsDisabled = false;
$Unsafe* UnixUserDefinedFileAttributeView::unsafe = nullptr;
$String* UnixUserDefinedFileAttributeView::USER_NAMESPACE = nullptr;

void UnixUserDefinedFileAttributeView::init$($UnixPath* file, bool followLinks) {
	$AbstractUserDefinedFileAttributeView::init$();
	$set(this, file, file);
	this->followLinks = followLinks;
}

$bytes* UnixUserDefinedFileAttributeView::nameAsBytes($UnixPath* file, $String* name$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($String, name, name$renamed);
	if (name == nullptr) {
		$throwNew($NullPointerException, "\'name\' is null"_s);
	}
	$assign(name, $str({UnixUserDefinedFileAttributeView::USER_NAMESPACE, name}));
	$var($bytes, bytes, $Util::toBytes(name));
	if ($nc(bytes)->length > maxNameLength()) {
		$throwNew($FileSystemException, $($nc(file)->getPathForExceptionMessage()), nullptr, $$str({"\'"_s, name, "\' is too big"_s}));
	}
	return bytes;
}

$List* UnixUserDefinedFileAttributeView::asList(int64_t address, int32_t size) {
	$init(UnixUserDefinedFileAttributeView);
	$useLocalCurrentObjectStackCache();
	$var($List, list, $new($ArrayList));
	int32_t start = 0;
	int32_t pos = 0;
	while (pos < size) {
		if ($nc(UnixUserDefinedFileAttributeView::unsafe)->getByte(address + pos) == 0) {
			int32_t len = pos - start;
			$var($bytes, value, $new($bytes, len));
			$init($Unsafe);
			$nc(UnixUserDefinedFileAttributeView::unsafe)->copyMemory(nullptr, address + start, value, $Unsafe::ARRAY_BYTE_BASE_OFFSET, len);
			$var($String, s, $Util::toString(value));
			list->add(s);
			start = pos + 1;
		}
		++pos;
	}
	return list;
}

$List* UnixUserDefinedFileAttributeView::list(int32_t fd, int32_t bufSize) {
	$init(UnixUserDefinedFileAttributeView);
	$useLocalCurrentObjectStackCache();
	try {
		{
			$var($NativeBuffer, buffer, $NativeBuffers::getNativeBuffer(bufSize));
			{
				$var($Throwable, var$0, nullptr);
				$var($List, var$2, nullptr);
				bool return$1 = false;
				try {
					try {
						int32_t n = $UnixNativeDispatcher::flistxattr(fd, $nc(buffer)->address(), bufSize);
						$assign(var$2, asList($nc(buffer)->address(), n));
						return$1 = true;
						goto $finally;
					} catch ($Throwable& t$) {
						if (buffer != nullptr) {
							try {
								buffer->close();
							} catch ($Throwable& x2) {
								t$->addSuppressed(x2);
							}
						}
						$throw(t$);
					}
				} catch ($Throwable& var$3) {
					$assign(var$0, var$3);
				} $finally: {
					if (buffer != nullptr) {
						buffer->close();
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
	} catch ($UnixException& x) {
		$init($UnixConstants);
		if (x->errno$() == $UnixConstants::ERANGE && bufSize < UnixUserDefinedFileAttributeView::MAX_LISTXATTR_BUF_SIZE) {
			return list(fd, bufSize * 2);
		} else {
			$throw(x);
		}
	}
	$shouldNotReachHere();
}

$List* UnixUserDefinedFileAttributeView::list() {
	$useLocalCurrentObjectStackCache();
	if ($System::getSecurityManager() != nullptr) {
		checkAccess($($nc(this->file)->getPathForPermissionCheck()), true, false);
	}
	int32_t fd = -1;
	try {
		fd = $nc(this->file)->openForAttributeAccess(this->followLinks);
	} catch ($UnixException& x) {
		x->rethrowAsIOException(this->file);
	}
	{
		$var($Throwable, var$0, nullptr);
		$var($List, var$2, nullptr);
		bool return$1 = false;
		try {
			try {
				$var($List, attrNames, list(fd, UnixUserDefinedFileAttributeView::MIN_LISTXATTR_BUF_SIZE));
				$assign(var$2, $nc($($nc($($nc($($nc(attrNames)->stream()))->filter(static_cast<$Predicate*>($$new(UnixUserDefinedFileAttributeView$$Lambda$lambda$list$0)))))->map(static_cast<$Function*>($$new(UnixUserDefinedFileAttributeView$$Lambda$lambda$list$1$1)))))->toList());
				return$1 = true;
				goto $finally;
			} catch ($UnixException& x) {
				$var($String, var$3, $nc(this->file)->getPathForExceptionMessage());
				$throwNew($FileSystemException, var$3, nullptr, $$str({"Unable to get list of extended attributes: "_s, $(x->getMessage())}));
			}
		} catch ($Throwable& var$4) {
			$assign(var$0, var$4);
		} $finally: {
			$UnixNativeDispatcher::close(fd);
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

int32_t UnixUserDefinedFileAttributeView::size($String* name) {
	$useLocalCurrentObjectStackCache();
	if ($System::getSecurityManager() != nullptr) {
		checkAccess($($nc(this->file)->getPathForPermissionCheck()), true, false);
	}
	int32_t fd = -1;
	try {
		fd = $nc(this->file)->openForAttributeAccess(this->followLinks);
	} catch ($UnixException& x) {
		x->rethrowAsIOException(this->file);
	}
	{
		$var($Throwable, var$0, nullptr);
		int32_t var$2 = 0;
		bool return$1 = false;
		try {
			try {
				var$2 = $UnixNativeDispatcher::fgetxattr(fd, $(nameAsBytes(this->file, name)), 0, 0);
				return$1 = true;
				goto $finally;
			} catch ($UnixException& x) {
				$var($String, var$3, $nc(this->file)->getPathForExceptionMessage());
				$throwNew($FileSystemException, var$3, nullptr, $$str({"Unable to get size of extended attribute \'"_s, name, "\': "_s, $(x->getMessage())}));
			}
		} catch ($Throwable& var$4) {
			$assign(var$0, var$4);
		} $finally: {
			$UnixNativeDispatcher::close(fd);
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

int32_t UnixUserDefinedFileAttributeView::read($String* name, $ByteBuffer* dst) {
	$useLocalCurrentObjectStackCache();
	if ($System::getSecurityManager() != nullptr) {
		checkAccess($($nc(this->file)->getPathForPermissionCheck()), true, false);
	}
	if ($nc(dst)->isReadOnly()) {
		$throwNew($IllegalArgumentException, "Read-only buffer"_s);
	}
	int32_t pos = $nc(dst)->position();
	int32_t lim = dst->limit();
	if (!UnixUserDefinedFileAttributeView::$assertionsDisabled && !(pos <= lim)) {
		$throwNew($AssertionError);
	}
	int32_t rem = (pos <= lim ? lim - pos : 0);
	{
		$var($DirectBuffer, buf, nullptr);
		bool var$0 = $instanceOf($DirectBuffer, dst);
		if (var$0) {
			$assign(buf, $cast($DirectBuffer, dst));
			var$0 = true;
		}
		if (var$0) {
			{
				$var($Throwable, var$1, nullptr);
				int32_t var$3 = 0;
				bool return$2 = false;
				try {
					int64_t address = $nc(buf)->address() + pos;
					int32_t n = read(name, address, rem);
					dst->position(pos + n);
					var$3 = n;
					return$2 = true;
					goto $finally;
				} catch ($Throwable& var$4) {
					$assign(var$1, var$4);
				} $finally: {
					$Reference::reachabilityFence(buf);
				}
				if (var$1 != nullptr) {
					$throw(var$1);
				}
				if (return$2) {
					return var$3;
				}
			}
		} else {
			{
				$var($NativeBuffer, nb, $NativeBuffers::getNativeBuffer(rem));
				{
					$var($Throwable, var$5, nullptr);
					int32_t var$7 = 0;
					bool return$6 = false;
					try {
						try {
							int64_t address = $nc(nb)->address();
							int32_t n = read(name, address, rem);
							$init($Unsafe);
							int32_t off = dst->arrayOffset() + pos + $Unsafe::ARRAY_BYTE_BASE_OFFSET;
							$nc(UnixUserDefinedFileAttributeView::unsafe)->copyMemory(nullptr, address, $(dst->array()), off, n);
							dst->position(pos + n);
							var$7 = n;
							return$6 = true;
							goto $finally1;
						} catch ($Throwable& t$) {
							if (nb != nullptr) {
								try {
									nb->close();
								} catch ($Throwable& x2) {
									t$->addSuppressed(x2);
								}
							}
							$throw(t$);
						}
					} catch ($Throwable& var$8) {
						$assign(var$5, var$8);
					} $finally1: {
						if (nb != nullptr) {
							nb->close();
						}
					}
					if (var$5 != nullptr) {
						$throw(var$5);
					}
					if (return$6) {
						return var$7;
					}
				}
			}
		}
	}
	$shouldNotReachHere();
}

int32_t UnixUserDefinedFileAttributeView::read($String* name, int64_t address, int32_t rem) {
	$useLocalCurrentObjectStackCache();
	int32_t fd = -1;
	try {
		fd = $nc(this->file)->openForAttributeAccess(this->followLinks);
	} catch ($UnixException& x) {
		x->rethrowAsIOException(this->file);
	}
	{
		$var($Throwable, var$0, nullptr);
		int32_t var$2 = 0;
		bool return$1 = false;
		try {
			try {
				int32_t n = $UnixNativeDispatcher::fgetxattr(fd, $(nameAsBytes(this->file, name)), address, rem);
				if (rem == 0) {
					if (n > 0) {
						$init($UnixConstants);
						$throwNew($UnixException, $UnixConstants::ERANGE);
					}
					var$2 = 0;
					return$1 = true;
					goto $finally;
				}
				var$2 = n;
				return$1 = true;
				goto $finally;
			} catch ($UnixException& x) {
				$init($UnixConstants);
				$var($String, msg, (x->errno$() == $UnixConstants::ERANGE) ? "Insufficient space in buffer"_s : x->getMessage());
				$throwNew($FileSystemException, $($nc(this->file)->getPathForExceptionMessage()), nullptr, $$str({"Error reading extended attribute \'"_s, name, "\': "_s, msg}));
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$UnixNativeDispatcher::close(fd);
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

int32_t UnixUserDefinedFileAttributeView::write($String* name, $ByteBuffer* src) {
	$useLocalCurrentObjectStackCache();
	if ($System::getSecurityManager() != nullptr) {
		checkAccess($($nc(this->file)->getPathForPermissionCheck()), false, true);
	}
	int32_t pos = $nc(src)->position();
	int32_t lim = src->limit();
	if (!UnixUserDefinedFileAttributeView::$assertionsDisabled && !(pos <= lim)) {
		$throwNew($AssertionError);
	}
	int32_t rem = (pos <= lim ? lim - pos : 0);
	{
		$var($DirectBuffer, buf, nullptr);
		bool var$0 = $instanceOf($DirectBuffer, src);
		if (var$0) {
			$assign(buf, $cast($DirectBuffer, src));
			var$0 = true;
		}
		if (var$0) {
			{
				$var($Throwable, var$1, nullptr);
				int32_t var$3 = 0;
				bool return$2 = false;
				try {
					int64_t address = $nc(buf)->address() + pos;
					write(name, address, rem);
					src->position(pos + rem);
					var$3 = rem;
					return$2 = true;
					goto $finally;
				} catch ($Throwable& var$4) {
					$assign(var$1, var$4);
				} $finally: {
					$Reference::reachabilityFence(buf);
				}
				if (var$1 != nullptr) {
					$throw(var$1);
				}
				if (return$2) {
					return var$3;
				}
			}
		} else {
			{
				$var($NativeBuffer, nb, $NativeBuffers::getNativeBuffer(rem));
				{
					$var($Throwable, var$5, nullptr);
					int32_t var$7 = 0;
					bool return$6 = false;
					try {
						try {
							int64_t address = $nc(nb)->address();
							if (src->hasArray()) {
								$init($Unsafe);
								int32_t off = src->arrayOffset() + pos + $Unsafe::ARRAY_BYTE_BASE_OFFSET;
								$nc(UnixUserDefinedFileAttributeView::unsafe)->copyMemory($(src->array()), off, nullptr, address, rem);
							} else {
								$var($bytes, tmp, $new($bytes, rem));
								src->get(tmp);
								src->position(pos);
								$init($Unsafe);
								$nc(UnixUserDefinedFileAttributeView::unsafe)->copyMemory(tmp, $Unsafe::ARRAY_BYTE_BASE_OFFSET, nullptr, address, rem);
							}
							write(name, address, rem);
							src->position(pos + rem);
							var$7 = rem;
							return$6 = true;
							goto $finally1;
						} catch ($Throwable& t$) {
							if (nb != nullptr) {
								try {
									nb->close();
								} catch ($Throwable& x2) {
									t$->addSuppressed(x2);
								}
							}
							$throw(t$);
						}
					} catch ($Throwable& var$8) {
						$assign(var$5, var$8);
					} $finally1: {
						if (nb != nullptr) {
							nb->close();
						}
					}
					if (var$5 != nullptr) {
						$throw(var$5);
					}
					if (return$6) {
						return var$7;
					}
				}
			}
		}
	}
	$shouldNotReachHere();
}

void UnixUserDefinedFileAttributeView::write($String* name, int64_t address, int32_t rem) {
	$useLocalCurrentObjectStackCache();
	int32_t fd = -1;
	try {
		fd = $nc(this->file)->openForAttributeAccess(this->followLinks);
	} catch ($UnixException& x) {
		x->rethrowAsIOException(this->file);
	}
	{
		$var($Throwable, var$0, nullptr);
		try {
			try {
				$UnixNativeDispatcher::fsetxattr(fd, $(nameAsBytes(this->file, name)), address, rem);
			} catch ($UnixException& x) {
				$var($String, var$1, $nc(this->file)->getPathForExceptionMessage());
				$throwNew($FileSystemException, var$1, nullptr, $$str({"Error writing extended attribute \'"_s, name, "\': "_s, $(x->getMessage())}));
			}
		} catch ($Throwable& var$2) {
			$assign(var$0, var$2);
		} /*finally*/ {
			$UnixNativeDispatcher::close(fd);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void UnixUserDefinedFileAttributeView::delete$($String* name) {
	$useLocalCurrentObjectStackCache();
	if ($System::getSecurityManager() != nullptr) {
		checkAccess($($nc(this->file)->getPathForPermissionCheck()), false, true);
	}
	int32_t fd = -1;
	try {
		fd = $nc(this->file)->openForAttributeAccess(this->followLinks);
	} catch ($UnixException& x) {
		x->rethrowAsIOException(this->file);
	}
	{
		$var($Throwable, var$0, nullptr);
		try {
			try {
				$UnixNativeDispatcher::fremovexattr(fd, $(nameAsBytes(this->file, name)));
			} catch ($UnixException& x) {
				$var($String, var$1, $nc(this->file)->getPathForExceptionMessage());
				$throwNew($FileSystemException, var$1, nullptr, $$str({"Unable to delete extended attribute \'"_s, name, "\': "_s, $(x->getMessage())}));
			}
		} catch ($Throwable& var$2) {
			$assign(var$0, var$2);
		} /*finally*/ {
			$UnixNativeDispatcher::close(fd);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void UnixUserDefinedFileAttributeView::copyExtendedAttributes(int32_t ofd, int32_t nfd) {
	$init(UnixUserDefinedFileAttributeView);
	$useLocalCurrentObjectStackCache();
	try {
		$var($List, attrNames, list(ofd, UnixUserDefinedFileAttributeView::MIN_LISTXATTR_BUF_SIZE));
		{
			$var($Iterator, i$, $nc(attrNames)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($String, name, $cast($String, i$->next()));
				{
					try {
						copyExtendedAttribute(ofd, $($Util::toBytes(name)), nfd);
					} catch ($UnixException& ignore) {
					}
				}
			}
		}
	} catch ($UnixException& e) {
		return;
	}
}

void UnixUserDefinedFileAttributeView::copyExtendedAttribute(int32_t ofd, $bytes* name, int32_t nfd) {
	$init(UnixUserDefinedFileAttributeView);
	$useLocalCurrentObjectStackCache();
	int32_t size = $UnixNativeDispatcher::fgetxattr(ofd, name, 0, 0);
	$var($NativeBuffer, buffer, $NativeBuffers::getNativeBuffer(size));
	{
		$var($Throwable, var$0, nullptr);
		try {
			int64_t address = $nc(buffer)->address();
			size = $UnixNativeDispatcher::fgetxattr(ofd, name, address, size);
			$UnixNativeDispatcher::fsetxattr(nfd, name, address, size);
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(buffer)->release();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

$String* UnixUserDefinedFileAttributeView::lambda$list$1($String* s) {
	$init(UnixUserDefinedFileAttributeView);
	return $nc(s)->substring($nc(UnixUserDefinedFileAttributeView::USER_NAMESPACE)->length());
}

bool UnixUserDefinedFileAttributeView::lambda$list$0($String* s) {
	$init(UnixUserDefinedFileAttributeView);
	return $nc(s)->startsWith(UnixUserDefinedFileAttributeView::USER_NAMESPACE);
}

void clinit$UnixUserDefinedFileAttributeView($Class* class$) {
	$assignStatic(UnixUserDefinedFileAttributeView::USER_NAMESPACE, "user."_s);
	UnixUserDefinedFileAttributeView::$assertionsDisabled = !UnixUserDefinedFileAttributeView::class$->desiredAssertionStatus();
	$assignStatic(UnixUserDefinedFileAttributeView::unsafe, $Unsafe::getUnsafe());
}

UnixUserDefinedFileAttributeView::UnixUserDefinedFileAttributeView() {
}

$Class* UnixUserDefinedFileAttributeView::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(UnixUserDefinedFileAttributeView$$Lambda$lambda$list$0::classInfo$.name)) {
			return UnixUserDefinedFileAttributeView$$Lambda$lambda$list$0::load$(name, initialize);
		}
		if (name->equals(UnixUserDefinedFileAttributeView$$Lambda$lambda$list$1$1::classInfo$.name)) {
			return UnixUserDefinedFileAttributeView$$Lambda$lambda$list$1$1::load$(name, initialize);
		}
	}
	$loadClass(UnixUserDefinedFileAttributeView, name, initialize, &_UnixUserDefinedFileAttributeView_ClassInfo_, clinit$UnixUserDefinedFileAttributeView, allocate$UnixUserDefinedFileAttributeView);
	return class$;
}

$Class* UnixUserDefinedFileAttributeView::class$ = nullptr;

		} // fs
	} // nio
} // sun