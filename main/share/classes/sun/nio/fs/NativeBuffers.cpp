#include <sun/nio/fs/NativeBuffers.h>

#include <java/lang/AssertionError.h>
#include <java/lang/ThreadLocal.h>
#include <jdk/internal/misc/Unsafe.h>
#include <sun/nio/fs/NativeBuffer.h>
#include <sun/nio/fs/NativeBuffers$1.h>
#include <jcpp.h>

#undef ARRAY_BYTE_BASE_OFFSET
#undef TEMP_BUF_POOL_SIZE

using $NativeBufferArray = $Array<::sun::nio::fs::NativeBuffer>;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ThreadLocal = ::java::lang::ThreadLocal;
using $Unsafe = ::jdk::internal::misc::Unsafe;
using $NativeBuffer = ::sun::nio::fs::NativeBuffer;
using $NativeBuffers$1 = ::sun::nio::fs::NativeBuffers$1;

namespace sun {
	namespace nio {
		namespace fs {

$FieldInfo _NativeBuffers_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(NativeBuffers, $assertionsDisabled)},
	{"unsafe", "Ljdk/internal/misc/Unsafe;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(NativeBuffers, unsafe)},
	{"TEMP_BUF_POOL_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(NativeBuffers, TEMP_BUF_POOL_SIZE)},
	{"threadLocal", "Ljava/lang/ThreadLocal;", "Ljava/lang/ThreadLocal<[Lsun/nio/fs/NativeBuffer;>;", $PRIVATE | $STATIC, $staticField(NativeBuffers, threadLocal)},
	{}
};

$MethodInfo _NativeBuffers_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(NativeBuffers, init$, void)},
	{"allocNativeBuffer", "(I)Lsun/nio/fs/NativeBuffer;", nullptr, $STATIC, $staticMethod(NativeBuffers, allocNativeBuffer, $NativeBuffer*, int32_t)},
	{"asNativeBuffer", "([B)Lsun/nio/fs/NativeBuffer;", nullptr, $STATIC, $staticMethod(NativeBuffers, asNativeBuffer, $NativeBuffer*, $bytes*)},
	{"copyCStringToNativeBuffer", "([BLsun/nio/fs/NativeBuffer;)V", nullptr, $STATIC, $staticMethod(NativeBuffers, copyCStringToNativeBuffer, void, $bytes*, $NativeBuffer*)},
	{"getNativeBuffer", "(I)Lsun/nio/fs/NativeBuffer;", nullptr, $STATIC, $staticMethod(NativeBuffers, getNativeBuffer, $NativeBuffer*, int32_t)},
	{"getNativeBufferFromCache", "(I)Lsun/nio/fs/NativeBuffer;", nullptr, $STATIC, $staticMethod(NativeBuffers, getNativeBufferFromCache, $NativeBuffer*, int32_t)},
	{"releaseNativeBuffer", "(Lsun/nio/fs/NativeBuffer;)V", nullptr, $STATIC, $staticMethod(NativeBuffers, releaseNativeBuffer, void, $NativeBuffer*)},
	{}
};

$InnerClassInfo _NativeBuffers_InnerClassesInfo_[] = {
	{"sun.nio.fs.NativeBuffers$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _NativeBuffers_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.fs.NativeBuffers",
	"java.lang.Object",
	nullptr,
	_NativeBuffers_FieldInfo_,
	_NativeBuffers_MethodInfo_,
	nullptr,
	nullptr,
	_NativeBuffers_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.nio.fs.NativeBuffers$1"
};

$Object* allocate$NativeBuffers($Class* clazz) {
	return $of($alloc(NativeBuffers));
}

bool NativeBuffers::$assertionsDisabled = false;
$Unsafe* NativeBuffers::unsafe = nullptr;
$ThreadLocal* NativeBuffers::threadLocal = nullptr;

void NativeBuffers::init$() {
}

$NativeBuffer* NativeBuffers::allocNativeBuffer(int32_t size) {
	$init(NativeBuffers);
	if (size < 2048) {
		size = 2048;
	}
	return $new($NativeBuffer, size);
}

$NativeBuffer* NativeBuffers::getNativeBufferFromCache(int32_t size) {
	$init(NativeBuffers);
	$useLocalCurrentObjectStackCache();
	$var($NativeBufferArray, buffers, $cast($NativeBufferArray, $nc(NativeBuffers::threadLocal)->get()));
	if (buffers != nullptr) {
		for (int32_t i = 0; i < NativeBuffers::TEMP_BUF_POOL_SIZE; ++i) {
			$var($NativeBuffer, buffer, buffers->get(i));
			if (buffer != nullptr && buffer->size() >= size) {
				buffers->set(i, nullptr);
				return buffer;
			}
		}
	}
	return nullptr;
}

$NativeBuffer* NativeBuffers::getNativeBuffer(int32_t size) {
	$init(NativeBuffers);
	$var($NativeBuffer, buffer, getNativeBufferFromCache(size));
	if (buffer != nullptr) {
		buffer->setOwner(nullptr);
		return buffer;
	} else {
		return allocNativeBuffer(size);
	}
}

void NativeBuffers::releaseNativeBuffer($NativeBuffer* buffer) {
	$init(NativeBuffers);
	$useLocalCurrentObjectStackCache();
	$var($NativeBufferArray, buffers, $cast($NativeBufferArray, $nc(NativeBuffers::threadLocal)->get()));
	if (buffers == nullptr) {
		$assign(buffers, $new($NativeBufferArray, NativeBuffers::TEMP_BUF_POOL_SIZE));
		buffers->set(0, buffer);
		$nc(NativeBuffers::threadLocal)->set(buffers);
		return;
	}
	for (int32_t i = 0; i < NativeBuffers::TEMP_BUF_POOL_SIZE; ++i) {
		if ($nc(buffers)->get(i) == nullptr) {
			buffers->set(i, buffer);
			return;
		}
	}
	for (int32_t i = 0; i < NativeBuffers::TEMP_BUF_POOL_SIZE; ++i) {
		$var($NativeBuffer, existing, $nc(buffers)->get(i));
		int32_t var$0 = $nc(existing)->size();
		if (var$0 < $nc(buffer)->size()) {
			existing->free();
			buffers->set(i, buffer);
			return;
		}
	}
	$nc(buffer)->free();
}

void NativeBuffers::copyCStringToNativeBuffer($bytes* cstr, $NativeBuffer* buffer) {
	$init(NativeBuffers);
	$init($Unsafe);
	int64_t offset = $Unsafe::ARRAY_BYTE_BASE_OFFSET;
	int64_t len = $nc(cstr)->length;
	if (!NativeBuffers::$assertionsDisabled && !($nc(buffer)->size() >= (len + 1))) {
		$throwNew($AssertionError);
	}
	$nc(NativeBuffers::unsafe)->copyMemory(cstr, offset, nullptr, $nc(buffer)->address(), len);
	$nc(NativeBuffers::unsafe)->putByte($nc(buffer)->address() + len, (int8_t)0);
}

$NativeBuffer* NativeBuffers::asNativeBuffer($bytes* cstr) {
	$init(NativeBuffers);
	$var($NativeBuffer, buffer, getNativeBuffer($nc(cstr)->length + 1));
	copyCStringToNativeBuffer(cstr, buffer);
	return buffer;
}

void clinit$NativeBuffers($Class* class$) {
	NativeBuffers::$assertionsDisabled = !NativeBuffers::class$->desiredAssertionStatus();
	$assignStatic(NativeBuffers::unsafe, $Unsafe::getUnsafe());
	$assignStatic(NativeBuffers::threadLocal, $new($NativeBuffers$1));
}

NativeBuffers::NativeBuffers() {
}

$Class* NativeBuffers::load$($String* name, bool initialize) {
	$loadClass(NativeBuffers, name, initialize, &_NativeBuffers_ClassInfo_, clinit$NativeBuffers, allocate$NativeBuffers);
	return class$;
}

$Class* NativeBuffers::class$ = nullptr;

		} // fs
	} // nio
} // sun