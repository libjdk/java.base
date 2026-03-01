#include <java/nio/ByteBuffer.h>

#include <java/lang/AssertionError.h>
#include <java/lang/IndexOutOfBoundsException.h>
#include <java/lang/Math.h>
#include <java/lang/StringBuffer.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/lang/ref/Reference.h>
#include <java/nio/Bits.h>
#include <java/nio/Buffer.h>
#include <java/nio/BufferMismatch.h>
#include <java/nio/BufferOverflowException.h>
#include <java/nio/BufferUnderflowException.h>
#include <java/nio/ByteOrder.h>
#include <java/nio/CharBuffer.h>
#include <java/nio/DirectByteBuffer.h>
#include <java/nio/DoubleBuffer.h>
#include <java/nio/FloatBuffer.h>
#include <java/nio/HeapByteBuffer.h>
#include <java/nio/IntBuffer.h>
#include <java/nio/LongBuffer.h>
#include <java/nio/ReadOnlyBufferException.h>
#include <java/nio/ShortBuffer.h>
#include <java/util/Objects.h>
#include <jdk/internal/access/foreign/MemorySegmentProxy.h>
#include <jdk/internal/misc/ScopedMemoryAccess$Scope.h>
#include <jdk/internal/misc/ScopedMemoryAccess.h>
#include <jdk/internal/misc/Unsafe.h>
#include <jcpp.h>

#undef ARRAY_BASE_OFFSET
#undef BIG_ENDIAN
#undef JNI_COPY_FROM_ARRAY_THRESHOLD
#undef JNI_COPY_TO_ARRAY_THRESHOLD
#undef LITTLE_ENDIAN
#undef SCOPED_MEMORY_ACCESS
#undef UNSAFE

using $AssertionError = ::java::lang::AssertionError;
using $Byte = ::java::lang::Byte;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IndexOutOfBoundsException = ::java::lang::IndexOutOfBoundsException;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $StringBuffer = ::java::lang::StringBuffer;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $Reference = ::java::lang::ref::Reference;
using $Bits = ::java::nio::Bits;
using $Buffer = ::java::nio::Buffer;
using $BufferMismatch = ::java::nio::BufferMismatch;
using $BufferOverflowException = ::java::nio::BufferOverflowException;
using $BufferUnderflowException = ::java::nio::BufferUnderflowException;
using $ByteOrder = ::java::nio::ByteOrder;
using $CharBuffer = ::java::nio::CharBuffer;
using $DirectByteBuffer = ::java::nio::DirectByteBuffer;
using $DoubleBuffer = ::java::nio::DoubleBuffer;
using $FloatBuffer = ::java::nio::FloatBuffer;
using $HeapByteBuffer = ::java::nio::HeapByteBuffer;
using $IntBuffer = ::java::nio::IntBuffer;
using $LongBuffer = ::java::nio::LongBuffer;
using $ReadOnlyBufferException = ::java::nio::ReadOnlyBufferException;
using $ShortBuffer = ::java::nio::ShortBuffer;
using $Objects = ::java::util::Objects;
using $MemorySegmentProxy = ::jdk::internal::access::foreign::MemorySegmentProxy;
using $ScopedMemoryAccess = ::jdk::internal::misc::ScopedMemoryAccess;
using $ScopedMemoryAccess$Scope = ::jdk::internal::misc::ScopedMemoryAccess$Scope;
using $Unsafe = ::jdk::internal::misc::Unsafe;

namespace java {
	namespace nio {

$FieldInfo _ByteBuffer_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(ByteBuffer, $assertionsDisabled)},
	{"ARRAY_BASE_OFFSET", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ByteBuffer, ARRAY_BASE_OFFSET)},
	{"hb", "[B", nullptr, $FINAL, $field(ByteBuffer, hb)},
	{"offset", "I", nullptr, $FINAL, $field(ByteBuffer, offset)},
	{"isReadOnly", "Z", nullptr, 0, $field(ByteBuffer, isReadOnly$)},
	{"bigEndian", "Z", nullptr, 0, $field(ByteBuffer, bigEndian)},
	{"nativeByteOrder", "Z", nullptr, 0, $field(ByteBuffer, nativeByteOrder)},
	{}
};

$MethodInfo _ByteBuffer_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"duplicate", "()Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $ABSTRACT},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "(IIII[BILjdk/internal/access/foreign/MemorySegmentProxy;)V", nullptr, 0, $method(ByteBuffer, init$, void, int32_t, int32_t, int32_t, int32_t, $bytes*, int32_t, $MemorySegmentProxy*)},
	{"<init>", "(IIIILjdk/internal/access/foreign/MemorySegmentProxy;)V", nullptr, 0, $method(ByteBuffer, init$, void, int32_t, int32_t, int32_t, int32_t, $MemorySegmentProxy*)},
	{"<init>", "([BJILjdk/internal/access/foreign/MemorySegmentProxy;)V", nullptr, 0, $method(ByteBuffer, init$, void, $bytes*, int64_t, int32_t, $MemorySegmentProxy*)},
	{"alignedSlice", "(I)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $FINAL, $method(ByteBuffer, alignedSlice, ByteBuffer*, int32_t)},
	{"alignmentOffset", "(II)I", nullptr, $PUBLIC | $FINAL, $method(ByteBuffer, alignmentOffset, int32_t, int32_t, int32_t)},
	{"allocate", "(I)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $STATIC, $staticMethod(ByteBuffer, allocate, ByteBuffer*, int32_t)},
	{"allocateDirect", "(I)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $STATIC, $staticMethod(ByteBuffer, allocateDirect, ByteBuffer*, int32_t)},
	{"array", "()[B", nullptr, $PUBLIC | $FINAL, $virtualMethod(ByteBuffer, array, $Object*)},
	{"arrayOffset", "()I", nullptr, $PUBLIC | $FINAL, $virtualMethod(ByteBuffer, arrayOffset, int32_t)},
	{"asCharBuffer", "()Ljava/nio/CharBuffer;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(ByteBuffer, asCharBuffer, $CharBuffer*)},
	{"asDoubleBuffer", "()Ljava/nio/DoubleBuffer;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(ByteBuffer, asDoubleBuffer, $DoubleBuffer*)},
	{"asFloatBuffer", "()Ljava/nio/FloatBuffer;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(ByteBuffer, asFloatBuffer, $FloatBuffer*)},
	{"asIntBuffer", "()Ljava/nio/IntBuffer;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(ByteBuffer, asIntBuffer, $IntBuffer*)},
	{"asLongBuffer", "()Ljava/nio/LongBuffer;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(ByteBuffer, asLongBuffer, $LongBuffer*)},
	{"asReadOnlyBuffer", "()Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(ByteBuffer, asReadOnlyBuffer, ByteBuffer*)},
	{"asShortBuffer", "()Ljava/nio/ShortBuffer;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(ByteBuffer, asShortBuffer, $ShortBuffer*)},
	{"base", "()Ljava/lang/Object;", nullptr, 0, $virtualMethod(ByteBuffer, base, $Object*)},
	{"clear", "()Ljava/nio/ByteBuffer;", nullptr, $PUBLIC, $virtualMethod(ByteBuffer, clear, ByteBuffer*)},
	{"compact", "()Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(ByteBuffer, compact, ByteBuffer*)},
	{"compare", "(BB)I", nullptr, $PRIVATE | $STATIC, $staticMethod(ByteBuffer, compare, int32_t, int8_t, int8_t)},
	{"compareTo", "(Ljava/nio/ByteBuffer;)I", nullptr, $PUBLIC, $virtualMethod(ByteBuffer, compareTo, int32_t, ByteBuffer*)},
	{"compareTo", "(Ljava/lang/Object;)I", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(ByteBuffer, compareTo, int32_t, Object$*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ByteBuffer, equals, bool, Object$*)},
	{"flip", "()Ljava/nio/ByteBuffer;", nullptr, $PUBLIC, $virtualMethod(ByteBuffer, flip, ByteBuffer*)},
	{"get", "()B", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(ByteBuffer, get, int8_t)},
	{"get", "(I)B", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(ByteBuffer, get, int8_t, int32_t)},
	{"get", "([BII)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC, $virtualMethod(ByteBuffer, get, ByteBuffer*, $bytes*, int32_t, int32_t)},
	{"get", "([B)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC, $virtualMethod(ByteBuffer, get, ByteBuffer*, $bytes*)},
	{"get", "(I[BII)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC, $virtualMethod(ByteBuffer, get, ByteBuffer*, int32_t, $bytes*, int32_t, int32_t)},
	{"get", "(I[B)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC, $virtualMethod(ByteBuffer, get, ByteBuffer*, int32_t, $bytes*)},
	{"getArray", "(I[BII)Ljava/nio/ByteBuffer;", nullptr, $PRIVATE, $method(ByteBuffer, getArray, ByteBuffer*, int32_t, $bytes*, int32_t, int32_t)},
	{"getChar", "()C", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(ByteBuffer, getChar, char16_t)},
	{"getChar", "(I)C", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(ByteBuffer, getChar, char16_t, int32_t)},
	{"getDouble", "()D", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(ByteBuffer, getDouble, double)},
	{"getDouble", "(I)D", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(ByteBuffer, getDouble, double, int32_t)},
	{"getFloat", "()F", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(ByteBuffer, getFloat, float)},
	{"getFloat", "(I)F", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(ByteBuffer, getFloat, float, int32_t)},
	{"getInt", "()I", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(ByteBuffer, getInt, int32_t)},
	{"getInt", "(I)I", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(ByteBuffer, getInt, int32_t, int32_t)},
	{"getLong", "()J", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(ByteBuffer, getLong, int64_t)},
	{"getLong", "(I)J", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(ByteBuffer, getLong, int64_t, int32_t)},
	{"getShort", "()S", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(ByteBuffer, getShort, int16_t)},
	{"getShort", "(I)S", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(ByteBuffer, getShort, int16_t, int32_t)},
	{"hasArray", "()Z", nullptr, $PUBLIC | $FINAL, $virtualMethod(ByteBuffer, hasArray, bool)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(ByteBuffer, hashCode, int32_t)},
	{"isDirect", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{"limit", "(I)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC, $virtualMethod(ByteBuffer, limit, ByteBuffer*, int32_t)},
	{"mark", "()Ljava/nio/ByteBuffer;", nullptr, $PUBLIC, $virtualMethod(ByteBuffer, mark, ByteBuffer*)},
	{"mismatch", "(Ljava/nio/ByteBuffer;)I", nullptr, $PUBLIC, $virtualMethod(ByteBuffer, mismatch, int32_t, ByteBuffer*)},
	{"order", "()Ljava/nio/ByteOrder;", nullptr, $PUBLIC | $FINAL, $method(ByteBuffer, order, $ByteOrder*)},
	{"order", "(Ljava/nio/ByteOrder;)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $FINAL, $method(ByteBuffer, order, ByteBuffer*, $ByteOrder*)},
	{"position", "(I)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC, $virtualMethod(ByteBuffer, position, ByteBuffer*, int32_t)},
	{"put", "(B)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(ByteBuffer, put, ByteBuffer*, int8_t)},
	{"put", "(IB)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(ByteBuffer, put, ByteBuffer*, int32_t, int8_t)},
	{"put", "(Ljava/nio/ByteBuffer;)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC, $virtualMethod(ByteBuffer, put, ByteBuffer*, ByteBuffer*)},
	{"put", "(ILjava/nio/ByteBuffer;II)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC, $virtualMethod(ByteBuffer, put, ByteBuffer*, int32_t, ByteBuffer*, int32_t, int32_t)},
	{"put", "([BII)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC, $virtualMethod(ByteBuffer, put, ByteBuffer*, $bytes*, int32_t, int32_t)},
	{"put", "([B)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $FINAL, $method(ByteBuffer, put, ByteBuffer*, $bytes*)},
	{"put", "(I[BII)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC, $virtualMethod(ByteBuffer, put, ByteBuffer*, int32_t, $bytes*, int32_t, int32_t)},
	{"put", "(I[B)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC, $virtualMethod(ByteBuffer, put, ByteBuffer*, int32_t, $bytes*)},
	{"putArray", "(I[BII)Ljava/nio/ByteBuffer;", nullptr, $PRIVATE, $method(ByteBuffer, putArray, ByteBuffer*, int32_t, $bytes*, int32_t, int32_t)},
	{"putBuffer", "(ILjava/nio/ByteBuffer;II)V", nullptr, 0, $virtualMethod(ByteBuffer, putBuffer, void, int32_t, ByteBuffer*, int32_t, int32_t)},
	{"putChar", "(C)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(ByteBuffer, putChar, ByteBuffer*, char16_t)},
	{"putChar", "(IC)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(ByteBuffer, putChar, ByteBuffer*, int32_t, char16_t)},
	{"putDouble", "(D)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(ByteBuffer, putDouble, ByteBuffer*, double)},
	{"putDouble", "(ID)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(ByteBuffer, putDouble, ByteBuffer*, int32_t, double)},
	{"putFloat", "(F)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(ByteBuffer, putFloat, ByteBuffer*, float)},
	{"putFloat", "(IF)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(ByteBuffer, putFloat, ByteBuffer*, int32_t, float)},
	{"putInt", "(I)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(ByteBuffer, putInt, ByteBuffer*, int32_t)},
	{"putInt", "(II)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(ByteBuffer, putInt, ByteBuffer*, int32_t, int32_t)},
	{"putLong", "(J)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(ByteBuffer, putLong, ByteBuffer*, int64_t)},
	{"putLong", "(IJ)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(ByteBuffer, putLong, ByteBuffer*, int32_t, int64_t)},
	{"putShort", "(S)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(ByteBuffer, putShort, ByteBuffer*, int16_t)},
	{"putShort", "(IS)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(ByteBuffer, putShort, ByteBuffer*, int32_t, int16_t)},
	{"reset", "()Ljava/nio/ByteBuffer;", nullptr, $PUBLIC, $virtualMethod(ByteBuffer, reset, ByteBuffer*)},
	{"rewind", "()Ljava/nio/ByteBuffer;", nullptr, $PUBLIC, $virtualMethod(ByteBuffer, rewind, ByteBuffer*)},
	{"slice", "()Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $ABSTRACT},
	{"slice", "(II)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $ABSTRACT},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ByteBuffer, toString, $String*)},
	{"wrap", "([BII)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $STATIC, $staticMethod(ByteBuffer, wrap, ByteBuffer*, $bytes*, int32_t, int32_t)},
	{"wrap", "([B)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $STATIC, $staticMethod(ByteBuffer, wrap, ByteBuffer*, $bytes*)},
	{}
};

$ClassInfo _ByteBuffer_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"java.nio.ByteBuffer",
	"java.nio.Buffer",
	"java.lang.Comparable",
	_ByteBuffer_FieldInfo_,
	_ByteBuffer_MethodInfo_,
	"Ljava/nio/Buffer;Ljava/lang/Comparable<Ljava/nio/ByteBuffer;>;"
};

$Object* allocate$ByteBuffer($Class* clazz) {
	return $of($alloc(ByteBuffer));
}

$Object* ByteBuffer::clone() {
	 return this->$Buffer::clone();
}

void ByteBuffer::finalize() {
	this->$Buffer::finalize();
}

bool ByteBuffer::$assertionsDisabled = false;
int64_t ByteBuffer::ARRAY_BASE_OFFSET = 0;

void ByteBuffer::init$(int32_t mark, int32_t pos, int32_t lim, int32_t cap, $bytes* hb, int32_t offset, $MemorySegmentProxy* segment) {
	$Buffer::init$(mark, pos, lim, cap, segment);
	this->bigEndian = true;
	$init($ByteOrder);
	this->nativeByteOrder = ($ByteOrder::nativeOrder() == $ByteOrder::BIG_ENDIAN);
	$set(this, hb, hb);
	this->offset = offset;
}

void ByteBuffer::init$(int32_t mark, int32_t pos, int32_t lim, int32_t cap, $MemorySegmentProxy* segment) {
	ByteBuffer::init$(mark, pos, lim, cap, nullptr, 0, segment);
}

void ByteBuffer::init$($bytes* hb, int64_t addr, int32_t cap, $MemorySegmentProxy* segment) {
	$Buffer::init$(addr, cap, segment);
	this->bigEndian = true;
	$init($ByteOrder);
	this->nativeByteOrder = ($ByteOrder::nativeOrder() == $ByteOrder::BIG_ENDIAN);
	$set(this, hb, hb);
	this->offset = 0;
}

$Object* ByteBuffer::base() {
	return $of(this->hb);
}

ByteBuffer* ByteBuffer::allocateDirect(int32_t capacity) {
	$init(ByteBuffer);
	return $new($DirectByteBuffer, capacity);
}

ByteBuffer* ByteBuffer::allocate(int32_t capacity) {
	$init(ByteBuffer);
	if (capacity < 0) {
		$throw($(createCapacityException(capacity)));
	}
	return $new($HeapByteBuffer, capacity, capacity, nullptr);
}

ByteBuffer* ByteBuffer::wrap($bytes* array, int32_t offset, int32_t length) {
	$init(ByteBuffer);
	try {
		return $new($HeapByteBuffer, array, offset, length, nullptr);
	} catch ($IllegalArgumentException& x) {
		$throwNew($IndexOutOfBoundsException);
	}
	$shouldNotReachHere();
}

ByteBuffer* ByteBuffer::wrap($bytes* array) {
	$init(ByteBuffer);
	return wrap(array, 0, $nc(array)->length);
}

ByteBuffer* ByteBuffer::get($bytes* dst, int32_t offset, int32_t length) {
	$Objects::checkFromIndexSize(offset, length, $nc(dst)->length);
	int32_t pos = position();
	if (length > limit() - pos) {
		$throwNew($BufferUnderflowException);
	}
	getArray(pos, dst, offset, length);
	position(pos + length);
	return this;
}

ByteBuffer* ByteBuffer::get($bytes* dst) {
	return get(dst, 0, $nc(dst)->length);
}

ByteBuffer* ByteBuffer::get(int32_t index, $bytes* dst, int32_t offset, int32_t length) {
	$Objects::checkFromIndexSize(index, length, limit());
	$Objects::checkFromIndexSize(offset, length, $nc(dst)->length);
	getArray(index, dst, offset, length);
	return this;
}

ByteBuffer* ByteBuffer::get(int32_t index, $bytes* dst) {
	return get(index, dst, 0, $nc(dst)->length);
}

ByteBuffer* ByteBuffer::getArray(int32_t index, $bytes* dst, int32_t offset, int32_t length) {
	$useLocalCurrentObjectStackCache();
	if (((int64_t)length << 0) > $Bits::JNI_COPY_TO_ARRAY_THRESHOLD) {
		int64_t bufAddr = this->address + ((int64_t)index << 0);
		int64_t dstOffset = ByteBuffer::ARRAY_BASE_OFFSET + ((int64_t)offset << 0);
		int64_t len = (int64_t)length << 0;
		{
			$var($Throwable, var$0, nullptr);
			try {
				$init($Buffer);
				$var($ScopedMemoryAccess$Scope, var$1, scope());
				$nc($Buffer::SCOPED_MEMORY_ACCESS)->copyMemory(var$1, nullptr, $(base()), bufAddr, dst, dstOffset, len);
			} catch ($Throwable& var$2) {
				$assign(var$0, var$2);
			} /*finally*/ {
				$Reference::reachabilityFence(this);
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	} else {
		int32_t end = offset + length;
		{
			int32_t i = offset;
			int32_t j = index;
			for (; i < end; ++i, ++j) {
				$nc(dst)->set(i, get(j));
			}
		}
	}
	return this;
}

ByteBuffer* ByteBuffer::put(ByteBuffer* src) {
	if (src == this) {
		$throw($(createSameBufferException()));
	}
	if (isReadOnly()) {
		$throwNew($ReadOnlyBufferException);
	}
	int32_t srcPos = $nc(src)->position();
	int32_t srcLim = src->limit();
	int32_t srcRem = (srcPos <= srcLim ? srcLim - srcPos : 0);
	int32_t pos = position();
	int32_t lim = limit();
	int32_t rem = (pos <= lim ? lim - pos : 0);
	if (srcRem > rem) {
		$throwNew($BufferOverflowException);
	}
	putBuffer(pos, src, srcPos, srcRem);
	position(pos + srcRem);
	src->position(srcPos + srcRem);
	return this;
}

ByteBuffer* ByteBuffer::put(int32_t index, ByteBuffer* src, int32_t offset, int32_t length) {
	$Objects::checkFromIndexSize(index, length, limit());
	$Objects::checkFromIndexSize(offset, length, $nc(src)->limit());
	if (isReadOnly()) {
		$throwNew($ReadOnlyBufferException);
	}
	putBuffer(index, src, offset, length);
	return this;
}

void ByteBuffer::putBuffer(int32_t pos, ByteBuffer* src, int32_t srcPos, int32_t n) {
	$useLocalCurrentObjectStackCache();
	$var($Object, srcBase, $nc(src)->base());
	if (!ByteBuffer::$assertionsDisabled && !(srcBase != nullptr || src->isDirect())) {
		$throwNew($AssertionError);
	}
	$var($Object, base, this->base());
	if (!ByteBuffer::$assertionsDisabled && !(base != nullptr || isDirect())) {
		$throwNew($AssertionError);
	}
	int64_t srcAddr = src->address + ((int64_t)srcPos << 0);
	int64_t addr = this->address + ((int64_t)pos << 0);
	int64_t len = (int64_t)n << 0;
	{
		$var($Throwable, var$0, nullptr);
		try {
			$init($Buffer);
			$var($ScopedMemoryAccess$Scope, var$1, src->scope());
			$nc($Buffer::SCOPED_MEMORY_ACCESS)->copyMemory(var$1, $(scope()), srcBase, srcAddr, base, addr, len);
		} catch ($Throwable& var$2) {
			$assign(var$0, var$2);
		} /*finally*/ {
			$Reference::reachabilityFence(src);
			$Reference::reachabilityFence(this);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

ByteBuffer* ByteBuffer::put($bytes* src, int32_t offset, int32_t length) {
	if (isReadOnly()) {
		$throwNew($ReadOnlyBufferException);
	}
	$Objects::checkFromIndexSize(offset, length, $nc(src)->length);
	int32_t pos = position();
	if (length > limit() - pos) {
		$throwNew($BufferOverflowException);
	}
	putArray(pos, src, offset, length);
	position(pos + length);
	return this;
}

ByteBuffer* ByteBuffer::put($bytes* src) {
	return put(src, 0, $nc(src)->length);
}

ByteBuffer* ByteBuffer::put(int32_t index, $bytes* src, int32_t offset, int32_t length) {
	if (isReadOnly()) {
		$throwNew($ReadOnlyBufferException);
	}
	$Objects::checkFromIndexSize(index, length, limit());
	$Objects::checkFromIndexSize(offset, length, $nc(src)->length);
	putArray(index, src, offset, length);
	return this;
}

ByteBuffer* ByteBuffer::put(int32_t index, $bytes* src) {
	return put(index, src, 0, $nc(src)->length);
}

ByteBuffer* ByteBuffer::putArray(int32_t index, $bytes* src, int32_t offset, int32_t length) {
	$useLocalCurrentObjectStackCache();
	if (((int64_t)length << 0) > $Bits::JNI_COPY_FROM_ARRAY_THRESHOLD) {
		int64_t bufAddr = this->address + ((int64_t)index << 0);
		int64_t srcOffset = ByteBuffer::ARRAY_BASE_OFFSET + ((int64_t)offset << 0);
		int64_t len = (int64_t)length << 0;
		{
			$var($Throwable, var$0, nullptr);
			try {
				$init($Buffer);
				$var($ScopedMemoryAccess$Scope, var$1, scope());
				$var($Object, var$2, $of(src));
				int64_t var$3 = srcOffset;
				$nc($Buffer::SCOPED_MEMORY_ACCESS)->copyMemory(nullptr, var$1, var$2, var$3, $(base()), bufAddr, len);
			} catch ($Throwable& var$4) {
				$assign(var$0, var$4);
			} /*finally*/ {
				$Reference::reachabilityFence(this);
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	} else {
		int32_t end = offset + length;
		{
			int32_t i = offset;
			int32_t j = index;
			for (; i < end; ++i, ++j) {
				this->put(j, $nc(src)->get(i));
			}
		}
	}
	return this;
}

bool ByteBuffer::hasArray() {
	return (this->hb != nullptr) && !this->isReadOnly$;
}

$Object* ByteBuffer::array() {
	if (this->hb == nullptr) {
		$throwNew($UnsupportedOperationException);
	}
	if (this->isReadOnly$) {
		$throwNew($ReadOnlyBufferException);
	}
	return $of(this->hb);
}

int32_t ByteBuffer::arrayOffset() {
	if (this->hb == nullptr) {
		$throwNew($UnsupportedOperationException);
	}
	if (this->isReadOnly$) {
		$throwNew($ReadOnlyBufferException);
	}
	return this->offset;
}

ByteBuffer* ByteBuffer::position(int32_t newPosition) {
	$Buffer::position(newPosition);
	return this;
}

ByteBuffer* ByteBuffer::limit(int32_t newLimit) {
	$Buffer::limit(newLimit);
	return this;
}

ByteBuffer* ByteBuffer::mark() {
	$Buffer::mark();
	return this;
}

ByteBuffer* ByteBuffer::reset() {
	$Buffer::reset();
	return this;
}

ByteBuffer* ByteBuffer::clear() {
	$Buffer::clear();
	return this;
}

ByteBuffer* ByteBuffer::flip() {
	$Buffer::flip();
	return this;
}

ByteBuffer* ByteBuffer::rewind() {
	$Buffer::rewind();
	return this;
}

$String* ByteBuffer::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuffer, sb, $new($StringBuffer));
	sb->append($($of(this)->getClass()->getName()));
	sb->append("[pos="_s);
	sb->append(position());
	sb->append(" lim="_s);
	sb->append(limit());
	sb->append(" cap="_s);
	sb->append(capacity());
	sb->append("]"_s);
	return sb->toString();
}

int32_t ByteBuffer::hashCode() {
	int32_t h = 1;
	int32_t p = position();
	for (int32_t i = limit() - 1; i >= p; --i) {
		h = 31 * h + (int32_t)get(i);
	}
	return h;
}

bool ByteBuffer::equals(Object$* ob) {
	if ($equals(this, ob)) {
		return true;
	}
	if (!($instanceOf(ByteBuffer, ob))) {
		return false;
	}
	$var(ByteBuffer, that, $cast(ByteBuffer, ob));
	int32_t thisPos = this->position();
	int32_t thisRem = this->limit() - thisPos;
	int32_t thatPos = $nc(that)->position();
	int32_t thatRem = that->limit() - thatPos;
	if (thisRem < 0 || thisRem != thatRem) {
		return false;
	}
	return $BufferMismatch::mismatch(this, thisPos, that, thatPos, thisRem) < 0;
}

int32_t ByteBuffer::compareTo(ByteBuffer* that) {
	int32_t thisPos = this->position();
	int32_t thisRem = this->limit() - thisPos;
	int32_t thatPos = $nc(that)->position();
	int32_t thatRem = that->limit() - thatPos;
	int32_t length = $Math::min(thisRem, thatRem);
	if (length < 0) {
		return -1;
	}
	int32_t i = $BufferMismatch::mismatch(this, thisPos, that, thatPos, length);
	if (i >= 0) {
		int8_t var$0 = this->get(thisPos + i);
		return compare(var$0, that->get(thatPos + i));
	}
	return thisRem - thatRem;
}

int32_t ByteBuffer::compare(int8_t x, int8_t y) {
	$init(ByteBuffer);
	return $Byte::compare(x, y);
}

int32_t ByteBuffer::mismatch(ByteBuffer* that) {
	int32_t thisPos = this->position();
	int32_t thisRem = this->limit() - thisPos;
	int32_t thatPos = $nc(that)->position();
	int32_t thatRem = that->limit() - thatPos;
	int32_t length = $Math::min(thisRem, thatRem);
	if (length < 0) {
		return -1;
	}
	int32_t r = $BufferMismatch::mismatch(this, thisPos, that, thatPos, length);
	return (r == -1 && thisRem != thatRem) ? length : r;
}

$ByteOrder* ByteBuffer::order() {
	$init($ByteOrder);
	return this->bigEndian ? $ByteOrder::BIG_ENDIAN : $ByteOrder::LITTLE_ENDIAN;
}

ByteBuffer* ByteBuffer::order($ByteOrder* bo) {
	$init($ByteOrder);
	this->bigEndian = (bo == $ByteOrder::BIG_ENDIAN);
	this->nativeByteOrder = (this->bigEndian == ($ByteOrder::nativeOrder() == $ByteOrder::BIG_ENDIAN));
	return this;
}

int32_t ByteBuffer::alignmentOffset(int32_t index, int32_t unitSize) {
	$useLocalCurrentObjectStackCache();
	if (index < 0) {
		$throwNew($IllegalArgumentException, $$str({"Index less than zero: "_s, $$str(index)}));
	}
	if (unitSize < 1 || ((int32_t)(unitSize & (uint32_t)(unitSize - 1))) != 0) {
		$throwNew($IllegalArgumentException, $$str({"Unit size not a power of two: "_s, $$str(unitSize)}));
	}
	if (unitSize > 8 && !isDirect()) {
		$throwNew($UnsupportedOperationException, $$str({"Unit size unsupported for non-direct buffers: "_s, $$str(unitSize)}));
	}
	return (int32_t)((int64_t)((this->address + index) & (uint64_t)(int64_t)(unitSize - 1)));
}

ByteBuffer* ByteBuffer::alignedSlice(int32_t unitSize) {
	int32_t pos = position();
	int32_t lim = limit();
	int32_t pos_mod = alignmentOffset(pos, unitSize);
	int32_t lim_mod = alignmentOffset(lim, unitSize);
	int32_t aligned_pos = (pos_mod > 0) ? pos + (unitSize - pos_mod) : pos;
	int32_t aligned_lim = lim - lim_mod;
	if (aligned_pos > lim || aligned_lim < pos) {
		aligned_pos = (aligned_lim = pos);
	}
	return slice(aligned_pos, aligned_lim - aligned_pos);
}

int32_t ByteBuffer::compareTo(Object$* that) {
	return this->compareTo($cast(ByteBuffer, that));
}

void clinit$ByteBuffer($Class* class$) {
	ByteBuffer::$assertionsDisabled = !ByteBuffer::class$->desiredAssertionStatus();
	$init($Buffer);
	$load($bytes);
	ByteBuffer::ARRAY_BASE_OFFSET = $nc($Buffer::UNSAFE)->arrayBaseOffset($getClass($bytes));
}

ByteBuffer::ByteBuffer() {
}

$Class* ByteBuffer::load$($String* name, bool initialize) {
	$loadClass(ByteBuffer, name, initialize, &_ByteBuffer_ClassInfo_, clinit$ByteBuffer, allocate$ByteBuffer);
	return class$;
}

$Class* ByteBuffer::class$ = nullptr;

	} // nio
} // java