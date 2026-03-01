#include <sun/nio/ch/Util.h>

#include <java/io/FileDescriptor.h>
#include <java/io/IOException.h>
#include <java/lang/AssertionError.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/InstantiationException.h>
#include <java/lang/InternalError.h>
#include <java/lang/NumberFormatException.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/Runnable.h>
#include <java/lang/ThreadLocal.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/InvocationTargetException.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/MappedByteBuffer.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/Set.h>
#include <jdk/internal/misc/Unsafe.h>
#include <jdk/internal/ref/Cleaner.h>
#include <sun/nio/ch/DirectBuffer.h>
#include <sun/nio/ch/IOUtil.h>
#include <sun/nio/ch/Util$1.h>
#include <sun/nio/ch/Util$2.h>
#include <sun/nio/ch/Util$3.h>
#include <sun/nio/ch/Util$4.h>
#include <sun/nio/ch/Util$BufferCache.h>
#include <sun/security/action/GetPropertyAction.h>
#include <jcpp.h>

#undef IOV_MAX
#undef MAX_CACHED_BUFFER_SIZE
#undef MAX_VALUE
#undef TEMP_BUF_POOL_SIZE

using $ByteBufferArray = $Array<::java::nio::ByteBuffer>;
using $FileDescriptor = ::java::io::FileDescriptor;
using $IOException = ::java::io::IOException;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InstantiationException = ::java::lang::InstantiationException;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $Runnable = ::java::lang::Runnable;
using $ThreadLocal = ::java::lang::ThreadLocal;
using $Constructor = ::java::lang::reflect::Constructor;
using $InvocationTargetException = ::java::lang::reflect::InvocationTargetException;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $MappedByteBuffer = ::java::nio::MappedByteBuffer;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Set = ::java::util::Set;
using $Unsafe = ::jdk::internal::misc::Unsafe;
using $Cleaner = ::jdk::internal::ref::Cleaner;
using $DirectBuffer = ::sun::nio::ch::DirectBuffer;
using $IOUtil = ::sun::nio::ch::IOUtil;
using $Util$1 = ::sun::nio::ch::Util$1;
using $Util$2 = ::sun::nio::ch::Util$2;
using $Util$3 = ::sun::nio::ch::Util$3;
using $Util$4 = ::sun::nio::ch::Util$4;
using $Util$BufferCache = ::sun::nio::ch::Util$BufferCache;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;

namespace sun {
	namespace nio {
		namespace ch {

$FieldInfo _Util_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Util, $assertionsDisabled)},
	{"TEMP_BUF_POOL_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Util, TEMP_BUF_POOL_SIZE)},
	{"MAX_CACHED_BUFFER_SIZE", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Util, MAX_CACHED_BUFFER_SIZE)},
	{"bufferCache", "Ljava/lang/ThreadLocal;", "Ljava/lang/ThreadLocal<Lsun/nio/ch/Util$BufferCache;>;", $PRIVATE | $STATIC, $staticField(Util, bufferCache)},
	{"unsafe", "Ljdk/internal/misc/Unsafe;", nullptr, $PRIVATE | $STATIC, $staticField(Util, unsafe$)},
	{"pageSize", "I", nullptr, $PRIVATE | $STATIC, $staticField(Util, pageSize$)},
	{"directByteBufferConstructor", "Ljava/lang/reflect/Constructor;", "Ljava/lang/reflect/Constructor<*>;", $PRIVATE | $STATIC | $VOLATILE, $staticField(Util, directByteBufferConstructor)},
	{"directByteBufferRConstructor", "Ljava/lang/reflect/Constructor;", "Ljava/lang/reflect/Constructor<*>;", $PRIVATE | $STATIC | $VOLATILE, $staticField(Util, directByteBufferRConstructor)},
	{}
};

$MethodInfo _Util_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Util, init$, void)},
	{"_get", "(J)B", nullptr, $PRIVATE | $STATIC, $staticMethod(Util, _get, int8_t, int64_t)},
	{"_put", "(JB)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Util, _put, void, int64_t, int8_t)},
	{"checkBufferPositionAligned", "(Ljava/nio/ByteBuffer;II)V", nullptr, $STATIC, $staticMethod(Util, checkBufferPositionAligned, void, $ByteBuffer*, int32_t, int32_t), "java.io.IOException"},
	{"checkChannelPositionAligned", "(JI)V", nullptr, $STATIC, $staticMethod(Util, checkChannelPositionAligned, void, int64_t, int32_t), "java.io.IOException"},
	{"checkRemainingBufferSizeAligned", "(II)V", nullptr, $STATIC, $staticMethod(Util, checkRemainingBufferSizeAligned, void, int32_t, int32_t), "java.io.IOException"},
	{"erase", "(Ljava/nio/ByteBuffer;)V", nullptr, $STATIC, $staticMethod(Util, erase, void, $ByteBuffer*)},
	{"free", "(Ljava/nio/ByteBuffer;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Util, free, void, $ByteBuffer*)},
	{"getMaxCachedBufferSize", "()J", nullptr, $PRIVATE | $STATIC, $staticMethod(Util, getMaxCachedBufferSize, int64_t)},
	{"getTemporaryAlignedDirectBuffer", "(II)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $STATIC, $staticMethod(Util, getTemporaryAlignedDirectBuffer, $ByteBuffer*, int32_t, int32_t)},
	{"getTemporaryDirectBuffer", "(I)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $STATIC, $staticMethod(Util, getTemporaryDirectBuffer, $ByteBuffer*, int32_t)},
	{"initDBBConstructor", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(Util, initDBBConstructor, void)},
	{"initDBBRConstructor", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(Util, initDBBRConstructor, void)},
	{"isBufferTooLarge", "(I)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(Util, isBufferTooLarge, bool, int32_t)},
	{"isBufferTooLarge", "(Ljava/nio/ByteBuffer;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(Util, isBufferTooLarge, bool, $ByteBuffer*)},
	{"newMappedByteBuffer", "(IJLjava/io/FileDescriptor;Ljava/lang/Runnable;Z)Ljava/nio/MappedByteBuffer;", nullptr, $STATIC, $staticMethod(Util, newMappedByteBuffer, $MappedByteBuffer*, int32_t, int64_t, $FileDescriptor*, $Runnable*, bool)},
	{"newMappedByteBufferR", "(IJLjava/io/FileDescriptor;Ljava/lang/Runnable;Z)Ljava/nio/MappedByteBuffer;", nullptr, $STATIC, $staticMethod(Util, newMappedByteBufferR, $MappedByteBuffer*, int32_t, int64_t, $FileDescriptor*, $Runnable*, bool)},
	{"offerFirstTemporaryDirectBuffer", "(Ljava/nio/ByteBuffer;)V", nullptr, $STATIC, $staticMethod(Util, offerFirstTemporaryDirectBuffer, void, $ByteBuffer*)},
	{"offerLastTemporaryDirectBuffer", "(Ljava/nio/ByteBuffer;)V", nullptr, $STATIC, $staticMethod(Util, offerLastTemporaryDirectBuffer, void, $ByteBuffer*)},
	{"pageSize", "()I", nullptr, $STATIC, $staticMethod(Util, pageSize, int32_t)},
	{"releaseTemporaryDirectBuffer", "(Ljava/nio/ByteBuffer;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(Util, releaseTemporaryDirectBuffer, void, $ByteBuffer*)},
	{"subsequence", "([Ljava/nio/ByteBuffer;II)[Ljava/nio/ByteBuffer;", nullptr, $STATIC, $staticMethod(Util, subsequence, $ByteBufferArray*, $ByteBufferArray*, int32_t, int32_t)},
	{"ungrowableSet", "(Ljava/util/Set;)Ljava/util/Set;", "<E:Ljava/lang/Object;>(Ljava/util/Set<TE;>;)Ljava/util/Set<TE;>;", $STATIC, $staticMethod(Util, ungrowableSet, $Set*, $Set*)},
	{"unsafe", "()Ljdk/internal/misc/Unsafe;", nullptr, $STATIC, $staticMethod(Util, unsafe, $Unsafe*)},
	{}
};

$InnerClassInfo _Util_InnerClassesInfo_[] = {
	{"sun.nio.ch.Util$BufferCache", "sun.nio.ch.Util", "BufferCache", $PRIVATE | $STATIC},
	{"sun.nio.ch.Util$4", nullptr, nullptr, 0},
	{"sun.nio.ch.Util$3", nullptr, nullptr, 0},
	{"sun.nio.ch.Util$2", nullptr, nullptr, 0},
	{"sun.nio.ch.Util$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Util_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.nio.ch.Util",
	"java.lang.Object",
	nullptr,
	_Util_FieldInfo_,
	_Util_MethodInfo_,
	nullptr,
	nullptr,
	_Util_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.nio.ch.Util$BufferCache,sun.nio.ch.Util$4,sun.nio.ch.Util$3,sun.nio.ch.Util$2,sun.nio.ch.Util$1"
};

$Object* allocate$Util($Class* clazz) {
	return $of($alloc(Util));
}

bool Util::$assertionsDisabled = false;
int32_t Util::TEMP_BUF_POOL_SIZE = 0;
int64_t Util::MAX_CACHED_BUFFER_SIZE = 0;
$ThreadLocal* Util::bufferCache = nullptr;
$Unsafe* Util::unsafe$ = nullptr;
int32_t Util::pageSize$ = 0;
$volatile($Constructor*) Util::directByteBufferConstructor = nullptr;
$volatile($Constructor*) Util::directByteBufferRConstructor = nullptr;

void Util::init$() {
}

int64_t Util::getMaxCachedBufferSize() {
	$init(Util);
	$var($String, s, $GetPropertyAction::privilegedGetProperty("jdk.nio.maxCachedBufferSize"_s));
	if (s != nullptr) {
		try {
			int64_t m = $Long::parseLong(s);
			if (m >= 0) {
				return m;
			} else {
			}
		} catch ($NumberFormatException& e) {
		}
	}
	return $Long::MAX_VALUE;
}

bool Util::isBufferTooLarge(int32_t size) {
	$init(Util);
	return size > Util::MAX_CACHED_BUFFER_SIZE;
}

bool Util::isBufferTooLarge($ByteBuffer* buf) {
	$init(Util);
	return isBufferTooLarge($nc(buf)->capacity());
}

$ByteBuffer* Util::getTemporaryDirectBuffer(int32_t size) {
	$init(Util);
	$useLocalCurrentObjectStackCache();
	if (isBufferTooLarge(size)) {
		return $ByteBuffer::allocateDirect(size);
	}
	$var($Util$BufferCache, cache, $cast($Util$BufferCache, $nc(Util::bufferCache)->get()));
	$var($ByteBuffer, buf, $nc(cache)->get(size));
	if (buf != nullptr) {
		return buf;
	} else {
		if (!cache->isEmpty()) {
			$assign(buf, cache->removeFirst());
			free(buf);
		}
		return $ByteBuffer::allocateDirect(size);
	}
}

$ByteBuffer* Util::getTemporaryAlignedDirectBuffer(int32_t size, int32_t alignment) {
	$init(Util);
	$useLocalCurrentObjectStackCache();
	if (isBufferTooLarge(size)) {
		return $nc($($ByteBuffer::allocateDirect(size + alignment - 1)))->alignedSlice(alignment);
	}
	$var($Util$BufferCache, cache, $cast($Util$BufferCache, $nc(Util::bufferCache)->get()));
	$var($ByteBuffer, buf, $nc(cache)->get(size));
	if (buf != nullptr) {
		if (buf->alignmentOffset(0, alignment) == 0) {
			return buf;
		}
	} else if (!cache->isEmpty()) {
		$assign(buf, cache->removeFirst());
		free(buf);
	}
	return $nc($($ByteBuffer::allocateDirect(size + alignment - 1)))->alignedSlice(alignment);
}

void Util::releaseTemporaryDirectBuffer($ByteBuffer* buf) {
	$init(Util);
	offerFirstTemporaryDirectBuffer(buf);
}

void Util::offerFirstTemporaryDirectBuffer($ByteBuffer* buf) {
	$init(Util);
	if (isBufferTooLarge(buf)) {
		free(buf);
		return;
	}
	if (!Util::$assertionsDisabled && !(buf != nullptr)) {
		$throwNew($AssertionError);
	}
	$var($Util$BufferCache, cache, $cast($Util$BufferCache, $nc(Util::bufferCache)->get()));
	if (!$nc(cache)->offerFirst(buf)) {
		free(buf);
	}
}

void Util::offerLastTemporaryDirectBuffer($ByteBuffer* buf) {
	$init(Util);
	if (isBufferTooLarge(buf)) {
		free(buf);
		return;
	}
	if (!Util::$assertionsDisabled && !(buf != nullptr)) {
		$throwNew($AssertionError);
	}
	$var($Util$BufferCache, cache, $cast($Util$BufferCache, $nc(Util::bufferCache)->get()));
	if (!$nc(cache)->offerLast(buf)) {
		free(buf);
	}
}

void Util::free($ByteBuffer* buf) {
	$init(Util);
	$nc($($nc(($cast($DirectBuffer, buf)))->cleaner()))->clean();
}

$ByteBufferArray* Util::subsequence($ByteBufferArray* bs, int32_t offset, int32_t length) {
	$init(Util);
	if ((offset == 0) && (length == $nc(bs)->length)) {
		return bs;
	}
	int32_t n = length;
	$var($ByteBufferArray, bs2, $new($ByteBufferArray, n));
	for (int32_t i = 0; i < n; ++i) {
		bs2->set(i, $nc(bs)->get(offset + i));
	}
	return bs2;
}

$Set* Util::ungrowableSet($Set* s) {
	$init(Util);
	return $new($Util$2, s);
}

int8_t Util::_get(int64_t a) {
	$init(Util);
	return $nc(Util::unsafe$)->getByte(a);
}

void Util::_put(int64_t a, int8_t b) {
	$init(Util);
	$nc(Util::unsafe$)->putByte(a, b);
}

void Util::erase($ByteBuffer* bb) {
	$init(Util);
	int64_t var$0 = $nc(($cast($DirectBuffer, bb)))->address();
	$nc(Util::unsafe$)->setMemory(var$0, $nc(bb)->capacity(), (int8_t)0);
}

$Unsafe* Util::unsafe() {
	$init(Util);
	return Util::unsafe$;
}

int32_t Util::pageSize() {
	$init(Util);
	if (Util::pageSize$ == -1) {
		Util::pageSize$ = $nc($(unsafe()))->pageSize();
	}
	return Util::pageSize$;
}

void Util::initDBBConstructor() {
	$init(Util);
	$beforeCallerSensitive();
	$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($Util$3)));
}

$MappedByteBuffer* Util::newMappedByteBuffer(int32_t size, int64_t addr, $FileDescriptor* fd, $Runnable* unmapper, bool isSync) {
	$init(Util);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($MappedByteBuffer, dbb, nullptr);
	if (Util::directByteBufferConstructor == nullptr) {
		initDBBConstructor();
	}
	try {
		$assign(dbb, $cast($MappedByteBuffer, $nc(Util::directByteBufferConstructor)->newInstance($$new($ObjectArray, {
			$($of($Integer::valueOf(size))),
			$($of($Long::valueOf(addr))),
			$of(fd),
			$of(unmapper),
			$($of($Boolean::valueOf(isSync))),
			($Object*)nullptr
		}))));
	} catch ($InstantiationException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	} catch ($IllegalAccessException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	} catch ($InvocationTargetException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	}
	return dbb;
}

void Util::initDBBRConstructor() {
	$init(Util);
	$beforeCallerSensitive();
	$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($Util$4)));
}

$MappedByteBuffer* Util::newMappedByteBufferR(int32_t size, int64_t addr, $FileDescriptor* fd, $Runnable* unmapper, bool isSync) {
	$init(Util);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($MappedByteBuffer, dbb, nullptr);
	if (Util::directByteBufferRConstructor == nullptr) {
		initDBBRConstructor();
	}
	try {
		$assign(dbb, $cast($MappedByteBuffer, $nc(Util::directByteBufferRConstructor)->newInstance($$new($ObjectArray, {
			$($of($Integer::valueOf(size))),
			$($of($Long::valueOf(addr))),
			$of(fd),
			$of(unmapper),
			$($of($Boolean::valueOf(isSync))),
			($Object*)nullptr
		}))));
	} catch ($InstantiationException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	} catch ($IllegalAccessException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	} catch ($InvocationTargetException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	}
	return dbb;
}

void Util::checkBufferPositionAligned($ByteBuffer* bb, int32_t pos, int32_t alignment) {
	$init(Util);
	$useLocalCurrentObjectStackCache();
	if ($nc(bb)->alignmentOffset(pos, alignment) != 0) {
		$throwNew($IOException, $$str({"Current location of the bytebuffer ("_s, $$str(pos), ") is not a multiple of the block size ("_s, $$str(alignment), ")"_s}));
	}
}

void Util::checkRemainingBufferSizeAligned(int32_t rem, int32_t alignment) {
	$init(Util);
	$useLocalCurrentObjectStackCache();
	if ($mod(rem, alignment) != 0) {
		$throwNew($IOException, $$str({"Number of remaining bytes ("_s, $$str(rem), ") is not a multiple of the block size ("_s, $$str(alignment), ")"_s}));
	}
}

void Util::checkChannelPositionAligned(int64_t position, int32_t alignment) {
	$init(Util);
	$useLocalCurrentObjectStackCache();
	if ($mod(position, alignment) != 0) {
		$throwNew($IOException, $$str({"Channel position ("_s, $$str(position), ") is not a multiple of the block size ("_s, $$str(alignment), ")"_s}));
	}
}

void clinit$Util($Class* class$) {
	Util::$assertionsDisabled = !Util::class$->desiredAssertionStatus();
	$init($IOUtil);
	Util::TEMP_BUF_POOL_SIZE = $IOUtil::IOV_MAX;
	Util::MAX_CACHED_BUFFER_SIZE = Util::getMaxCachedBufferSize();
	$assignStatic(Util::bufferCache, $new($Util$1));
	$assignStatic(Util::unsafe$, $Unsafe::getUnsafe());
	Util::pageSize$ = -1;
}

Util::Util() {
}

$Class* Util::load$($String* name, bool initialize) {
	$loadClass(Util, name, initialize, &_Util_ClassInfo_, clinit$Util, allocate$Util);
	return class$;
}

$Class* Util::class$ = nullptr;

		} // ch
	} // nio
} // sun