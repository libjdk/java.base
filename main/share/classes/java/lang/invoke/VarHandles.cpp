#include <java/lang/invoke/VarHandles.h>

#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/ClassValue.h>
#include <java/lang/Error.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/IncompatibleClassChangeError.h>
#include <java/lang/InternalError.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/lang/invoke/BoundMethodHandle.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/DelegatingMethodHandle.h>
#include <java/lang/invoke/DirectMethodHandle.h>
#include <java/lang/invoke/IndirectVarHandle.h>
#include <java/lang/invoke/InfoFromMemberName.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MemberName.h>
#include <java/lang/invoke/MemoryAccessVarHandleByteHelper.h>
#include <java/lang/invoke/MemoryAccessVarHandleCharHelper.h>
#include <java/lang/invoke/MemoryAccessVarHandleDoubleHelper.h>
#include <java/lang/invoke/MemoryAccessVarHandleFloatHelper.h>
#include <java/lang/invoke/MemoryAccessVarHandleIntHelper.h>
#include <java/lang/invoke/MemoryAccessVarHandleLongHelper.h>
#include <java/lang/invoke/MemoryAccessVarHandleShortHelper.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandleInfo.h>
#include <java/lang/invoke/MethodHandleNatives.h>
#include <java/lang/invoke/MethodHandleStatics.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/invoke/TypeDescriptor$OfField.h>
#include <java/lang/invoke/TypeDescriptor$OfMethod.h>
#include <java/lang/invoke/VarHandle$AccessMode.h>
#include <java/lang/invoke/VarHandle$AccessType.h>
#include <java/lang/invoke/VarHandle.h>
#include <java/lang/invoke/VarHandleBooleans$Array.h>
#include <java/lang/invoke/VarHandleBooleans$FieldInstanceReadOnly.h>
#include <java/lang/invoke/VarHandleBooleans$FieldInstanceReadWrite.h>
#include <java/lang/invoke/VarHandleBooleans$FieldStaticReadOnly.h>
#include <java/lang/invoke/VarHandleBooleans$FieldStaticReadWrite.h>
#include <java/lang/invoke/VarHandleByteArrayAsChars$ArrayHandle.h>
#include <java/lang/invoke/VarHandleByteArrayAsChars$ByteBufferHandle.h>
#include <java/lang/invoke/VarHandleByteArrayAsDoubles$ArrayHandle.h>
#include <java/lang/invoke/VarHandleByteArrayAsDoubles$ByteBufferHandle.h>
#include <java/lang/invoke/VarHandleByteArrayAsFloats$ArrayHandle.h>
#include <java/lang/invoke/VarHandleByteArrayAsFloats$ByteBufferHandle.h>
#include <java/lang/invoke/VarHandleByteArrayAsInts$ArrayHandle.h>
#include <java/lang/invoke/VarHandleByteArrayAsInts$ByteBufferHandle.h>
#include <java/lang/invoke/VarHandleByteArrayAsLongs$ArrayHandle.h>
#include <java/lang/invoke/VarHandleByteArrayAsLongs$ByteBufferHandle.h>
#include <java/lang/invoke/VarHandleByteArrayAsShorts$ArrayHandle.h>
#include <java/lang/invoke/VarHandleByteArrayAsShorts$ByteBufferHandle.h>
#include <java/lang/invoke/VarHandleBytes$Array.h>
#include <java/lang/invoke/VarHandleBytes$FieldInstanceReadOnly.h>
#include <java/lang/invoke/VarHandleBytes$FieldInstanceReadWrite.h>
#include <java/lang/invoke/VarHandleBytes$FieldStaticReadOnly.h>
#include <java/lang/invoke/VarHandleBytes$FieldStaticReadWrite.h>
#include <java/lang/invoke/VarHandleChars$Array.h>
#include <java/lang/invoke/VarHandleChars$FieldInstanceReadOnly.h>
#include <java/lang/invoke/VarHandleChars$FieldInstanceReadWrite.h>
#include <java/lang/invoke/VarHandleChars$FieldStaticReadOnly.h>
#include <java/lang/invoke/VarHandleChars$FieldStaticReadWrite.h>
#include <java/lang/invoke/VarHandleDoubles$Array.h>
#include <java/lang/invoke/VarHandleDoubles$FieldInstanceReadOnly.h>
#include <java/lang/invoke/VarHandleDoubles$FieldInstanceReadWrite.h>
#include <java/lang/invoke/VarHandleDoubles$FieldStaticReadOnly.h>
#include <java/lang/invoke/VarHandleDoubles$FieldStaticReadWrite.h>
#include <java/lang/invoke/VarHandleFloats$Array.h>
#include <java/lang/invoke/VarHandleFloats$FieldInstanceReadOnly.h>
#include <java/lang/invoke/VarHandleFloats$FieldInstanceReadWrite.h>
#include <java/lang/invoke/VarHandleFloats$FieldStaticReadOnly.h>
#include <java/lang/invoke/VarHandleFloats$FieldStaticReadWrite.h>
#include <java/lang/invoke/VarHandleInts$Array.h>
#include <java/lang/invoke/VarHandleInts$FieldInstanceReadOnly.h>
#include <java/lang/invoke/VarHandleInts$FieldInstanceReadWrite.h>
#include <java/lang/invoke/VarHandleInts$FieldStaticReadOnly.h>
#include <java/lang/invoke/VarHandleInts$FieldStaticReadWrite.h>
#include <java/lang/invoke/VarHandleLongs$Array.h>
#include <java/lang/invoke/VarHandleLongs$FieldInstanceReadOnly.h>
#include <java/lang/invoke/VarHandleLongs$FieldInstanceReadWrite.h>
#include <java/lang/invoke/VarHandleLongs$FieldStaticReadOnly.h>
#include <java/lang/invoke/VarHandleLongs$FieldStaticReadWrite.h>
#include <java/lang/invoke/VarHandleReferences$Array.h>
#include <java/lang/invoke/VarHandleReferences$FieldInstanceReadOnly.h>
#include <java/lang/invoke/VarHandleReferences$FieldInstanceReadWrite.h>
#include <java/lang/invoke/VarHandleReferences$FieldStaticReadOnly.h>
#include <java/lang/invoke/VarHandleReferences$FieldStaticReadWrite.h>
#include <java/lang/invoke/VarHandleShorts$Array.h>
#include <java/lang/invoke/VarHandleShorts$FieldInstanceReadOnly.h>
#include <java/lang/invoke/VarHandleShorts$FieldInstanceReadWrite.h>
#include <java/lang/invoke/VarHandleShorts$FieldStaticReadOnly.h>
#include <java/lang/invoke/VarHandleShorts$FieldStaticReadWrite.h>
#include <java/lang/invoke/VarHandles$1.h>
#include <java/lang/invoke/VarHandles$2.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Field.h>
#include <java/lang/reflect/Member.h>
#include <java/lang/reflect/Method.h>
#include <java/lang/reflect/Modifier.h>
#include <java/nio/ByteOrder.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <java/util/function/BiFunction.h>
#include <java/util/function/Predicate.h>
#include <java/util/stream/Stream.h>
#include <jdk/internal/misc/Unsafe.h>
#include <sun/invoke/util/Wrapper.h>
#include <jcpp.h>

#undef ADDRESS_FACTORIES
#undef BIG_ENDIAN
#undef GET
#undef IMPL_LOOKUP
#undef TYPE
#undef UNSAFE
#undef VAR_HANDLE_IDENTITY_ADAPT

using $MethodHandleArray = $Array<::java::lang::invoke::MethodHandle>;
using $FieldArray = $Array<::java::lang::reflect::Field>;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $Byte = ::java::lang::Byte;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassValue = ::java::lang::ClassValue;
using $Double = ::java::lang::Double;
using $Error = ::java::lang::Error;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $IncompatibleClassChangeError = ::java::lang::IncompatibleClassChangeError;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $Short = ::java::lang::Short;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $Void = ::java::lang::Void;
using $BoundMethodHandle = ::java::lang::invoke::BoundMethodHandle;
using $DelegatingMethodHandle = ::java::lang::invoke::DelegatingMethodHandle;
using $DirectMethodHandle = ::java::lang::invoke::DirectMethodHandle;
using $IndirectVarHandle = ::java::lang::invoke::IndirectVarHandle;
using $InfoFromMemberName = ::java::lang::invoke::InfoFromMemberName;
using $MemberName = ::java::lang::invoke::MemberName;
using $MemoryAccessVarHandleByteHelper = ::java::lang::invoke::MemoryAccessVarHandleByteHelper;
using $MemoryAccessVarHandleCharHelper = ::java::lang::invoke::MemoryAccessVarHandleCharHelper;
using $MemoryAccessVarHandleDoubleHelper = ::java::lang::invoke::MemoryAccessVarHandleDoubleHelper;
using $MemoryAccessVarHandleFloatHelper = ::java::lang::invoke::MemoryAccessVarHandleFloatHelper;
using $MemoryAccessVarHandleIntHelper = ::java::lang::invoke::MemoryAccessVarHandleIntHelper;
using $MemoryAccessVarHandleLongHelper = ::java::lang::invoke::MemoryAccessVarHandleLongHelper;
using $MemoryAccessVarHandleShortHelper = ::java::lang::invoke::MemoryAccessVarHandleShortHelper;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandleInfo = ::java::lang::invoke::MethodHandleInfo;
using $MethodHandleNatives = ::java::lang::invoke::MethodHandleNatives;
using $MethodHandleStatics = ::java::lang::invoke::MethodHandleStatics;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $VarHandle = ::java::lang::invoke::VarHandle;
using $VarHandle$AccessMode = ::java::lang::invoke::VarHandle$AccessMode;
using $VarHandle$AccessType = ::java::lang::invoke::VarHandle$AccessType;
using $VarHandleBooleans$Array = ::java::lang::invoke::VarHandleBooleans$Array;
using $VarHandleBooleans$FieldInstanceReadOnly = ::java::lang::invoke::VarHandleBooleans$FieldInstanceReadOnly;
using $VarHandleBooleans$FieldInstanceReadWrite = ::java::lang::invoke::VarHandleBooleans$FieldInstanceReadWrite;
using $VarHandleBooleans$FieldStaticReadOnly = ::java::lang::invoke::VarHandleBooleans$FieldStaticReadOnly;
using $VarHandleBooleans$FieldStaticReadWrite = ::java::lang::invoke::VarHandleBooleans$FieldStaticReadWrite;
using $VarHandleByteArrayAsChars$ArrayHandle = ::java::lang::invoke::VarHandleByteArrayAsChars$ArrayHandle;
using $VarHandleByteArrayAsChars$ByteBufferHandle = ::java::lang::invoke::VarHandleByteArrayAsChars$ByteBufferHandle;
using $VarHandleByteArrayAsDoubles$ArrayHandle = ::java::lang::invoke::VarHandleByteArrayAsDoubles$ArrayHandle;
using $VarHandleByteArrayAsDoubles$ByteBufferHandle = ::java::lang::invoke::VarHandleByteArrayAsDoubles$ByteBufferHandle;
using $VarHandleByteArrayAsFloats$ArrayHandle = ::java::lang::invoke::VarHandleByteArrayAsFloats$ArrayHandle;
using $VarHandleByteArrayAsFloats$ByteBufferHandle = ::java::lang::invoke::VarHandleByteArrayAsFloats$ByteBufferHandle;
using $VarHandleByteArrayAsInts$ArrayHandle = ::java::lang::invoke::VarHandleByteArrayAsInts$ArrayHandle;
using $VarHandleByteArrayAsInts$ByteBufferHandle = ::java::lang::invoke::VarHandleByteArrayAsInts$ByteBufferHandle;
using $VarHandleByteArrayAsLongs$ArrayHandle = ::java::lang::invoke::VarHandleByteArrayAsLongs$ArrayHandle;
using $VarHandleByteArrayAsLongs$ByteBufferHandle = ::java::lang::invoke::VarHandleByteArrayAsLongs$ByteBufferHandle;
using $VarHandleByteArrayAsShorts$ArrayHandle = ::java::lang::invoke::VarHandleByteArrayAsShorts$ArrayHandle;
using $VarHandleByteArrayAsShorts$ByteBufferHandle = ::java::lang::invoke::VarHandleByteArrayAsShorts$ByteBufferHandle;
using $VarHandleBytes$Array = ::java::lang::invoke::VarHandleBytes$Array;
using $VarHandleBytes$FieldInstanceReadOnly = ::java::lang::invoke::VarHandleBytes$FieldInstanceReadOnly;
using $VarHandleBytes$FieldInstanceReadWrite = ::java::lang::invoke::VarHandleBytes$FieldInstanceReadWrite;
using $VarHandleBytes$FieldStaticReadOnly = ::java::lang::invoke::VarHandleBytes$FieldStaticReadOnly;
using $VarHandleBytes$FieldStaticReadWrite = ::java::lang::invoke::VarHandleBytes$FieldStaticReadWrite;
using $VarHandleChars$Array = ::java::lang::invoke::VarHandleChars$Array;
using $VarHandleChars$FieldInstanceReadOnly = ::java::lang::invoke::VarHandleChars$FieldInstanceReadOnly;
using $VarHandleChars$FieldInstanceReadWrite = ::java::lang::invoke::VarHandleChars$FieldInstanceReadWrite;
using $VarHandleChars$FieldStaticReadOnly = ::java::lang::invoke::VarHandleChars$FieldStaticReadOnly;
using $VarHandleChars$FieldStaticReadWrite = ::java::lang::invoke::VarHandleChars$FieldStaticReadWrite;
using $VarHandleDoubles$Array = ::java::lang::invoke::VarHandleDoubles$Array;
using $VarHandleDoubles$FieldInstanceReadOnly = ::java::lang::invoke::VarHandleDoubles$FieldInstanceReadOnly;
using $VarHandleDoubles$FieldInstanceReadWrite = ::java::lang::invoke::VarHandleDoubles$FieldInstanceReadWrite;
using $VarHandleDoubles$FieldStaticReadOnly = ::java::lang::invoke::VarHandleDoubles$FieldStaticReadOnly;
using $VarHandleDoubles$FieldStaticReadWrite = ::java::lang::invoke::VarHandleDoubles$FieldStaticReadWrite;
using $VarHandleFloats$Array = ::java::lang::invoke::VarHandleFloats$Array;
using $VarHandleFloats$FieldInstanceReadOnly = ::java::lang::invoke::VarHandleFloats$FieldInstanceReadOnly;
using $VarHandleFloats$FieldInstanceReadWrite = ::java::lang::invoke::VarHandleFloats$FieldInstanceReadWrite;
using $VarHandleFloats$FieldStaticReadOnly = ::java::lang::invoke::VarHandleFloats$FieldStaticReadOnly;
using $VarHandleFloats$FieldStaticReadWrite = ::java::lang::invoke::VarHandleFloats$FieldStaticReadWrite;
using $VarHandleInts$Array = ::java::lang::invoke::VarHandleInts$Array;
using $VarHandleInts$FieldInstanceReadOnly = ::java::lang::invoke::VarHandleInts$FieldInstanceReadOnly;
using $VarHandleInts$FieldInstanceReadWrite = ::java::lang::invoke::VarHandleInts$FieldInstanceReadWrite;
using $VarHandleInts$FieldStaticReadOnly = ::java::lang::invoke::VarHandleInts$FieldStaticReadOnly;
using $VarHandleInts$FieldStaticReadWrite = ::java::lang::invoke::VarHandleInts$FieldStaticReadWrite;
using $VarHandleLongs$Array = ::java::lang::invoke::VarHandleLongs$Array;
using $VarHandleLongs$FieldInstanceReadOnly = ::java::lang::invoke::VarHandleLongs$FieldInstanceReadOnly;
using $VarHandleLongs$FieldInstanceReadWrite = ::java::lang::invoke::VarHandleLongs$FieldInstanceReadWrite;
using $VarHandleLongs$FieldStaticReadOnly = ::java::lang::invoke::VarHandleLongs$FieldStaticReadOnly;
using $VarHandleLongs$FieldStaticReadWrite = ::java::lang::invoke::VarHandleLongs$FieldStaticReadWrite;
using $VarHandleReferences$Array = ::java::lang::invoke::VarHandleReferences$Array;
using $VarHandleReferences$FieldInstanceReadOnly = ::java::lang::invoke::VarHandleReferences$FieldInstanceReadOnly;
using $VarHandleReferences$FieldInstanceReadWrite = ::java::lang::invoke::VarHandleReferences$FieldInstanceReadWrite;
using $VarHandleReferences$FieldStaticReadOnly = ::java::lang::invoke::VarHandleReferences$FieldStaticReadOnly;
using $VarHandleReferences$FieldStaticReadWrite = ::java::lang::invoke::VarHandleReferences$FieldStaticReadWrite;
using $VarHandleShorts$Array = ::java::lang::invoke::VarHandleShorts$Array;
using $VarHandleShorts$FieldInstanceReadOnly = ::java::lang::invoke::VarHandleShorts$FieldInstanceReadOnly;
using $VarHandleShorts$FieldInstanceReadWrite = ::java::lang::invoke::VarHandleShorts$FieldInstanceReadWrite;
using $VarHandleShorts$FieldStaticReadOnly = ::java::lang::invoke::VarHandleShorts$FieldStaticReadOnly;
using $VarHandleShorts$FieldStaticReadWrite = ::java::lang::invoke::VarHandleShorts$FieldStaticReadWrite;
using $VarHandles$1 = ::java::lang::invoke::VarHandles$1;
using $VarHandles$2 = ::java::lang::invoke::VarHandles$2;
using $Constructor = ::java::lang::reflect::Constructor;
using $Field = ::java::lang::reflect::Field;
using $Method = ::java::lang::reflect::Method;
using $Modifier = ::java::lang::reflect::Modifier;
using $ByteOrder = ::java::nio::ByteOrder;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $BiFunction = ::java::util::function::BiFunction;
using $Predicate = ::java::util::function::Predicate;
using $Stream = ::java::util::stream::Stream;
using $Unsafe = ::jdk::internal::misc::Unsafe;
using $Wrapper = ::sun::invoke::util::Wrapper;

namespace java {
	namespace lang {
		namespace invoke {

class VarHandles$$Lambda$lambda$filterValue$0 : public $BiFunction {
	$class(VarHandles$$Lambda$lambda$filterValue$0, $NO_CLASS_INIT, $BiFunction)
public:
	void init$($MethodHandle* filterFromTarget, $MethodHandle* filterToTarget, $List* additionalCoordinates) {
		$set(this, filterFromTarget, filterFromTarget);
		$set(this, filterToTarget, filterToTarget);
		$set(this, additionalCoordinates, additionalCoordinates);
	}
	virtual $Object* apply(Object$* mode, Object$* modeHandle) override {
		 return $of(VarHandles::lambda$filterValue$0(filterFromTarget, filterToTarget, additionalCoordinates, $cast($VarHandle$AccessMode, mode), $cast($MethodHandle, modeHandle)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<VarHandles$$Lambda$lambda$filterValue$0>());
	}
	$MethodHandle* filterFromTarget = nullptr;
	$MethodHandle* filterToTarget = nullptr;
	$List* additionalCoordinates = nullptr;
	static $FieldInfo fieldInfos[4];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo VarHandles$$Lambda$lambda$filterValue$0::fieldInfos[4] = {
	{"filterFromTarget", "Ljava/lang/invoke/MethodHandle;", nullptr, $PUBLIC, $field(VarHandles$$Lambda$lambda$filterValue$0, filterFromTarget)},
	{"filterToTarget", "Ljava/lang/invoke/MethodHandle;", nullptr, $PUBLIC, $field(VarHandles$$Lambda$lambda$filterValue$0, filterToTarget)},
	{"additionalCoordinates", "Ljava/util/List;", nullptr, $PUBLIC, $field(VarHandles$$Lambda$lambda$filterValue$0, additionalCoordinates)},
	{}
};
$MethodInfo VarHandles$$Lambda$lambda$filterValue$0::methodInfos[3] = {
	{"<init>", "(Ljava/lang/invoke/MethodHandle;Ljava/lang/invoke/MethodHandle;Ljava/util/List;)V", nullptr, $PUBLIC, $method(VarHandles$$Lambda$lambda$filterValue$0, init$, void, $MethodHandle*, $MethodHandle*, $List*)},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(VarHandles$$Lambda$lambda$filterValue$0, apply, $Object*, Object$*, Object$*)},
	{}
};
$ClassInfo VarHandles$$Lambda$lambda$filterValue$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.invoke.VarHandles$$Lambda$lambda$filterValue$0",
	"java.lang.Object",
	"java.util.function.BiFunction",
	fieldInfos,
	methodInfos
};
$Class* VarHandles$$Lambda$lambda$filterValue$0::load$($String* name, bool initialize) {
	$loadClass(VarHandles$$Lambda$lambda$filterValue$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* VarHandles$$Lambda$lambda$filterValue$0::class$ = nullptr;

class VarHandles$$Lambda$lambda$filterCoordinates$1$1 : public $BiFunction {
	$class(VarHandles$$Lambda$lambda$filterCoordinates$1$1, $NO_CLASS_INIT, $BiFunction)
public:
	void init$(int32_t pos, $MethodHandleArray* filters) {
		this->pos = pos;
		$set(this, filters, filters);
	}
	virtual $Object* apply(Object$* mode, Object$* modeHandle) override {
		 return $of(VarHandles::lambda$filterCoordinates$1(pos, filters, $cast($VarHandle$AccessMode, mode), $cast($MethodHandle, modeHandle)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<VarHandles$$Lambda$lambda$filterCoordinates$1$1>());
	}
	int32_t pos = 0;
	$MethodHandleArray* filters = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo VarHandles$$Lambda$lambda$filterCoordinates$1$1::fieldInfos[3] = {
	{"pos", "I", nullptr, $PUBLIC, $field(VarHandles$$Lambda$lambda$filterCoordinates$1$1, pos)},
	{"filters", "[Ljava/lang/invoke/MethodHandle;", nullptr, $PUBLIC, $field(VarHandles$$Lambda$lambda$filterCoordinates$1$1, filters)},
	{}
};
$MethodInfo VarHandles$$Lambda$lambda$filterCoordinates$1$1::methodInfos[3] = {
	{"<init>", "(I[Ljava/lang/invoke/MethodHandle;)V", nullptr, $PUBLIC, $method(VarHandles$$Lambda$lambda$filterCoordinates$1$1, init$, void, int32_t, $MethodHandleArray*)},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(VarHandles$$Lambda$lambda$filterCoordinates$1$1, apply, $Object*, Object$*, Object$*)},
	{}
};
$ClassInfo VarHandles$$Lambda$lambda$filterCoordinates$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.invoke.VarHandles$$Lambda$lambda$filterCoordinates$1$1",
	"java.lang.Object",
	"java.util.function.BiFunction",
	fieldInfos,
	methodInfos
};
$Class* VarHandles$$Lambda$lambda$filterCoordinates$1$1::load$($String* name, bool initialize) {
	$loadClass(VarHandles$$Lambda$lambda$filterCoordinates$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* VarHandles$$Lambda$lambda$filterCoordinates$1$1::class$ = nullptr;

class VarHandles$$Lambda$lambda$insertCoordinates$2$2 : public $BiFunction {
	$class(VarHandles$$Lambda$lambda$insertCoordinates$2$2, $NO_CLASS_INIT, $BiFunction)
public:
	void init$(int32_t pos, $ObjectArray* values) {
		this->pos = pos;
		$set(this, values, values);
	}
	virtual $Object* apply(Object$* mode, Object$* modeHandle) override {
		 return $of(VarHandles::lambda$insertCoordinates$2(pos, values, $cast($VarHandle$AccessMode, mode), $cast($MethodHandle, modeHandle)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<VarHandles$$Lambda$lambda$insertCoordinates$2$2>());
	}
	int32_t pos = 0;
	$ObjectArray* values = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo VarHandles$$Lambda$lambda$insertCoordinates$2$2::fieldInfos[3] = {
	{"pos", "I", nullptr, $PUBLIC, $field(VarHandles$$Lambda$lambda$insertCoordinates$2$2, pos)},
	{"values", "[Ljava/lang/Object;", nullptr, $PUBLIC, $field(VarHandles$$Lambda$lambda$insertCoordinates$2$2, values)},
	{}
};
$MethodInfo VarHandles$$Lambda$lambda$insertCoordinates$2$2::methodInfos[3] = {
	{"<init>", "(I[Ljava/lang/Object;)V", nullptr, $PUBLIC, $method(VarHandles$$Lambda$lambda$insertCoordinates$2$2, init$, void, int32_t, $ObjectArray*)},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(VarHandles$$Lambda$lambda$insertCoordinates$2$2, apply, $Object*, Object$*, Object$*)},
	{}
};
$ClassInfo VarHandles$$Lambda$lambda$insertCoordinates$2$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.invoke.VarHandles$$Lambda$lambda$insertCoordinates$2$2",
	"java.lang.Object",
	"java.util.function.BiFunction",
	fieldInfos,
	methodInfos
};
$Class* VarHandles$$Lambda$lambda$insertCoordinates$2$2::load$($String* name, bool initialize) {
	$loadClass(VarHandles$$Lambda$lambda$insertCoordinates$2$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* VarHandles$$Lambda$lambda$insertCoordinates$2$2::class$ = nullptr;

class VarHandles$$Lambda$lambda$permuteCoordinates$3$3 : public $BiFunction {
	$class(VarHandles$$Lambda$lambda$permuteCoordinates$3$3, $NO_CLASS_INIT, $BiFunction)
public:
	void init$($List* targetCoordinates, $List* newCoordinates, $ints* reorder) {
		$set(this, targetCoordinates, targetCoordinates);
		$set(this, newCoordinates, newCoordinates);
		$set(this, reorder, reorder);
	}
	virtual $Object* apply(Object$* mode, Object$* modeHandle) override {
		 return $of(VarHandles::lambda$permuteCoordinates$3(targetCoordinates, newCoordinates, reorder, $cast($VarHandle$AccessMode, mode), $cast($MethodHandle, modeHandle)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<VarHandles$$Lambda$lambda$permuteCoordinates$3$3>());
	}
	$List* targetCoordinates = nullptr;
	$List* newCoordinates = nullptr;
	$ints* reorder = nullptr;
	static $FieldInfo fieldInfos[4];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo VarHandles$$Lambda$lambda$permuteCoordinates$3$3::fieldInfos[4] = {
	{"targetCoordinates", "Ljava/util/List;", nullptr, $PUBLIC, $field(VarHandles$$Lambda$lambda$permuteCoordinates$3$3, targetCoordinates)},
	{"newCoordinates", "Ljava/util/List;", nullptr, $PUBLIC, $field(VarHandles$$Lambda$lambda$permuteCoordinates$3$3, newCoordinates)},
	{"reorder", "[I", nullptr, $PUBLIC, $field(VarHandles$$Lambda$lambda$permuteCoordinates$3$3, reorder)},
	{}
};
$MethodInfo VarHandles$$Lambda$lambda$permuteCoordinates$3$3::methodInfos[3] = {
	{"<init>", "(Ljava/util/List;Ljava/util/List;[I)V", nullptr, $PUBLIC, $method(VarHandles$$Lambda$lambda$permuteCoordinates$3$3, init$, void, $List*, $List*, $ints*)},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(VarHandles$$Lambda$lambda$permuteCoordinates$3$3, apply, $Object*, Object$*, Object$*)},
	{}
};
$ClassInfo VarHandles$$Lambda$lambda$permuteCoordinates$3$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.invoke.VarHandles$$Lambda$lambda$permuteCoordinates$3$3",
	"java.lang.Object",
	"java.util.function.BiFunction",
	fieldInfos,
	methodInfos
};
$Class* VarHandles$$Lambda$lambda$permuteCoordinates$3$3::load$($String* name, bool initialize) {
	$loadClass(VarHandles$$Lambda$lambda$permuteCoordinates$3$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* VarHandles$$Lambda$lambda$permuteCoordinates$3$3::class$ = nullptr;

class VarHandles$$Lambda$lambda$collectCoordinates$4$4 : public $BiFunction {
	$class(VarHandles$$Lambda$lambda$collectCoordinates$4$4, $NO_CLASS_INIT, $BiFunction)
public:
	void init$(int32_t pos, $MethodHandle* filter) {
		this->pos = pos;
		$set(this, filter, filter);
	}
	virtual $Object* apply(Object$* mode, Object$* modeHandle) override {
		 return $of(VarHandles::lambda$collectCoordinates$4(pos, filter, $cast($VarHandle$AccessMode, mode), $cast($MethodHandle, modeHandle)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<VarHandles$$Lambda$lambda$collectCoordinates$4$4>());
	}
	int32_t pos = 0;
	$MethodHandle* filter = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo VarHandles$$Lambda$lambda$collectCoordinates$4$4::fieldInfos[3] = {
	{"pos", "I", nullptr, $PUBLIC, $field(VarHandles$$Lambda$lambda$collectCoordinates$4$4, pos)},
	{"filter", "Ljava/lang/invoke/MethodHandle;", nullptr, $PUBLIC, $field(VarHandles$$Lambda$lambda$collectCoordinates$4$4, filter)},
	{}
};
$MethodInfo VarHandles$$Lambda$lambda$collectCoordinates$4$4::methodInfos[3] = {
	{"<init>", "(ILjava/lang/invoke/MethodHandle;)V", nullptr, $PUBLIC, $method(VarHandles$$Lambda$lambda$collectCoordinates$4$4, init$, void, int32_t, $MethodHandle*)},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(VarHandles$$Lambda$lambda$collectCoordinates$4$4, apply, $Object*, Object$*, Object$*)},
	{}
};
$ClassInfo VarHandles$$Lambda$lambda$collectCoordinates$4$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.invoke.VarHandles$$Lambda$lambda$collectCoordinates$4$4",
	"java.lang.Object",
	"java.util.function.BiFunction",
	fieldInfos,
	methodInfos
};
$Class* VarHandles$$Lambda$lambda$collectCoordinates$4$4::load$($String* name, bool initialize) {
	$loadClass(VarHandles$$Lambda$lambda$collectCoordinates$4$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* VarHandles$$Lambda$lambda$collectCoordinates$4$4::class$ = nullptr;

class VarHandles$$Lambda$lambda$dropCoordinates$5$5 : public $BiFunction {
	$class(VarHandles$$Lambda$lambda$dropCoordinates$5$5, $NO_CLASS_INIT, $BiFunction)
public:
	void init$(int32_t pos, $ClassArray* valueTypes) {
		this->pos = pos;
		$set(this, valueTypes, valueTypes);
	}
	virtual $Object* apply(Object$* mode, Object$* modeHandle) override {
		 return $of(VarHandles::lambda$dropCoordinates$5(pos, valueTypes, $cast($VarHandle$AccessMode, mode), $cast($MethodHandle, modeHandle)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<VarHandles$$Lambda$lambda$dropCoordinates$5$5>());
	}
	int32_t pos = 0;
	$ClassArray* valueTypes = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo VarHandles$$Lambda$lambda$dropCoordinates$5$5::fieldInfos[3] = {
	{"pos", "I", nullptr, $PUBLIC, $field(VarHandles$$Lambda$lambda$dropCoordinates$5$5, pos)},
	{"valueTypes", "[Ljava/lang/Class;", nullptr, $PUBLIC, $field(VarHandles$$Lambda$lambda$dropCoordinates$5$5, valueTypes)},
	{}
};
$MethodInfo VarHandles$$Lambda$lambda$dropCoordinates$5$5::methodInfos[3] = {
	{"<init>", "(I[Ljava/lang/Class;)V", nullptr, $PUBLIC, $method(VarHandles$$Lambda$lambda$dropCoordinates$5$5, init$, void, int32_t, $ClassArray*)},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(VarHandles$$Lambda$lambda$dropCoordinates$5$5, apply, $Object*, Object$*, Object$*)},
	{}
};
$ClassInfo VarHandles$$Lambda$lambda$dropCoordinates$5$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.invoke.VarHandles$$Lambda$lambda$dropCoordinates$5$5",
	"java.lang.Object",
	"java.util.function.BiFunction",
	fieldInfos,
	methodInfos
};
$Class* VarHandles$$Lambda$lambda$dropCoordinates$5$5::load$($String* name, bool initialize) {
	$loadClass(VarHandles$$Lambda$lambda$dropCoordinates$5$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* VarHandles$$Lambda$lambda$dropCoordinates$5$5::class$ = nullptr;

class VarHandles$$Lambda$isCheckedException$6 : public $Predicate {
	$class(VarHandles$$Lambda$isCheckedException$6, $NO_CLASS_INIT, $Predicate)
public:
	void init$() {
	}
	virtual bool test(Object$* clazz) override {
		 return VarHandles::isCheckedException($cast($Class, clazz));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<VarHandles$$Lambda$isCheckedException$6>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo VarHandles$$Lambda$isCheckedException$6::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(VarHandles$$Lambda$isCheckedException$6, init$, void)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(VarHandles$$Lambda$isCheckedException$6, test, bool, Object$*)},
	{}
};
$ClassInfo VarHandles$$Lambda$isCheckedException$6::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.invoke.VarHandles$$Lambda$isCheckedException$6",
	"java.lang.Object",
	"java.util.function.Predicate",
	nullptr,
	methodInfos
};
$Class* VarHandles$$Lambda$isCheckedException$6::load$($String* name, bool initialize) {
	$loadClass(VarHandles$$Lambda$isCheckedException$6, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* VarHandles$$Lambda$isCheckedException$6::class$ = nullptr;

$FieldInfo _VarHandles_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(VarHandles, $assertionsDisabled)},
	{"ADDRESS_FACTORIES", "Ljava/lang/ClassValue;", "Ljava/lang/ClassValue<Ljava/util/concurrent/ConcurrentMap<Ljava/lang/Integer;Ljava/lang/invoke/MethodHandle;>;>;", $STATIC, $staticField(VarHandles, ADDRESS_FACTORIES)},
	{}
};

$MethodInfo _VarHandles_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(VarHandles, init$, void)},
	{"byteArrayViewHandle", "(Ljava/lang/Class;Z)Ljava/lang/invoke/VarHandle;", "(Ljava/lang/Class<*>;Z)Ljava/lang/invoke/VarHandle;", $STATIC, $staticMethod(VarHandles, byteArrayViewHandle, $VarHandle*, $Class*, bool)},
	{"collectCoordinates", "(Ljava/lang/invoke/VarHandle;ILjava/lang/invoke/MethodHandle;)Ljava/lang/invoke/VarHandle;", nullptr, $PUBLIC | $STATIC, $staticMethod(VarHandles, collectCoordinates, $VarHandle*, $VarHandle*, int32_t, $MethodHandle*)},
	{"dropCoordinates", "(Ljava/lang/invoke/VarHandle;I[Ljava/lang/Class;)Ljava/lang/invoke/VarHandle;", "(Ljava/lang/invoke/VarHandle;I[Ljava/lang/Class<*>;)Ljava/lang/invoke/VarHandle;", $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(VarHandles, dropCoordinates, $VarHandle*, $VarHandle*, int32_t, $ClassArray*)},
	{"filterCoordinates", "(Ljava/lang/invoke/VarHandle;I[Ljava/lang/invoke/MethodHandle;)Ljava/lang/invoke/VarHandle;", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(VarHandles, filterCoordinates, $VarHandle*, $VarHandle*, int32_t, $MethodHandleArray*)},
	{"filterValue", "(Ljava/lang/invoke/VarHandle;Ljava/lang/invoke/MethodHandle;Ljava/lang/invoke/MethodHandle;)Ljava/lang/invoke/VarHandle;", nullptr, $PUBLIC | $STATIC, $staticMethod(VarHandles, filterValue, $VarHandle*, $VarHandle*, $MethodHandle*, $MethodHandle*)},
	{"getFieldFromReceiverAndOffset", "(Ljava/lang/Class;JLjava/lang/Class;)Ljava/lang/reflect/Field;", "(Ljava/lang/Class<*>;JLjava/lang/Class<*>;)Ljava/lang/reflect/Field;", $STATIC, $staticMethod(VarHandles, getFieldFromReceiverAndOffset, $Field*, $Class*, int64_t, $Class*)},
	{"getStaticFieldFromBaseAndOffset", "(Ljava/lang/Object;JLjava/lang/Class;)Ljava/lang/reflect/Field;", "(Ljava/lang/Object;JLjava/lang/Class<*>;)Ljava/lang/reflect/Field;", $STATIC, $staticMethod(VarHandles, getStaticFieldFromBaseAndOffset, $Field*, Object$*, int64_t, $Class*)},
	{"insertCoordinates", "(Ljava/lang/invoke/VarHandle;I[Ljava/lang/Object;)Ljava/lang/invoke/VarHandle;", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(VarHandles, insertCoordinates, $VarHandle*, $VarHandle*, int32_t, $ObjectArray*)},
	{"isCheckedException", "(Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;)Z", $PRIVATE | $STATIC, $staticMethod(VarHandles, isCheckedException, bool, $Class*)},
	{"joinDuplicateArgs", "(Ljava/lang/invoke/MethodHandle;III)Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC, $staticMethod(VarHandles, joinDuplicateArgs, $MethodHandle*, $MethodHandle*, int32_t, int32_t, int32_t)},
	{"lambda$collectCoordinates$4", "(ILjava/lang/invoke/MethodHandle;Ljava/lang/invoke/VarHandle$AccessMode;Ljava/lang/invoke/MethodHandle;)Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(VarHandles, lambda$collectCoordinates$4, $MethodHandle*, int32_t, $MethodHandle*, $VarHandle$AccessMode*, $MethodHandle*)},
	{"lambda$dropCoordinates$5", "(I[Ljava/lang/Class;Ljava/lang/invoke/VarHandle$AccessMode;Ljava/lang/invoke/MethodHandle;)Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(VarHandles, lambda$dropCoordinates$5, $MethodHandle*, int32_t, $ClassArray*, $VarHandle$AccessMode*, $MethodHandle*)},
	{"lambda$filterCoordinates$1", "(I[Ljava/lang/invoke/MethodHandle;Ljava/lang/invoke/VarHandle$AccessMode;Ljava/lang/invoke/MethodHandle;)Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(VarHandles, lambda$filterCoordinates$1, $MethodHandle*, int32_t, $MethodHandleArray*, $VarHandle$AccessMode*, $MethodHandle*)},
	{"lambda$filterValue$0", "(Ljava/lang/invoke/MethodHandle;Ljava/lang/invoke/MethodHandle;Ljava/util/List;Ljava/lang/invoke/VarHandle$AccessMode;Ljava/lang/invoke/MethodHandle;)Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(VarHandles, lambda$filterValue$0, $MethodHandle*, $MethodHandle*, $MethodHandle*, $List*, $VarHandle$AccessMode*, $MethodHandle*)},
	{"lambda$insertCoordinates$2", "(I[Ljava/lang/Object;Ljava/lang/invoke/VarHandle$AccessMode;Ljava/lang/invoke/MethodHandle;)Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(VarHandles, lambda$insertCoordinates$2, $MethodHandle*, int32_t, $ObjectArray*, $VarHandle$AccessMode*, $MethodHandle*)},
	{"lambda$permuteCoordinates$3", "(Ljava/util/List;Ljava/util/List;[ILjava/lang/invoke/VarHandle$AccessMode;Ljava/lang/invoke/MethodHandle;)Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(VarHandles, lambda$permuteCoordinates$3, $MethodHandle*, $List*, $List*, $ints*, $VarHandle$AccessMode*, $MethodHandle*)},
	{"makeArrayElementHandle", "(Ljava/lang/Class;)Ljava/lang/invoke/VarHandle;", "(Ljava/lang/Class<*>;)Ljava/lang/invoke/VarHandle;", $STATIC, $staticMethod(VarHandles, makeArrayElementHandle, $VarHandle*, $Class*)},
	{"makeByteBufferViewHandle", "(Ljava/lang/Class;Z)Ljava/lang/invoke/VarHandle;", "(Ljava/lang/Class<*>;Z)Ljava/lang/invoke/VarHandle;", $STATIC, $staticMethod(VarHandles, makeByteBufferViewHandle, $VarHandle*, $Class*, bool)},
	{"makeFieldHandle", "(Ljava/lang/invoke/MemberName;Ljava/lang/Class;Ljava/lang/Class;Z)Ljava/lang/invoke/VarHandle;", "(Ljava/lang/invoke/MemberName;Ljava/lang/Class<*>;Ljava/lang/Class<*>;Z)Ljava/lang/invoke/VarHandle;", $STATIC, $staticMethod(VarHandles, makeFieldHandle, $VarHandle*, $MemberName*, $Class*, $Class*, bool)},
	{"makeMemoryAddressViewHandle", "(Ljava/lang/Class;ZJLjava/nio/ByteOrder;)Ljava/lang/invoke/VarHandle;", "(Ljava/lang/Class<*>;ZJLjava/nio/ByteOrder;)Ljava/lang/invoke/VarHandle;", $STATIC, $staticMethod(VarHandles, makeMemoryAddressViewHandle, $VarHandle*, $Class*, bool, int64_t, $ByteOrder*)},
	{"maybeAdapt", "(Ljava/lang/invoke/VarHandle;)Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC, $staticMethod(VarHandles, maybeAdapt, $VarHandle*, $VarHandle*)},
	{"methodTypeFor", "(Ljava/lang/invoke/VarHandle$AccessType;Ljava/lang/invoke/MethodType;Ljava/util/List;Ljava/util/List;)Ljava/lang/invoke/MethodType;", "(Ljava/lang/invoke/VarHandle$AccessType;Ljava/lang/invoke/MethodType;Ljava/util/List<Ljava/lang/Class<*>;>;Ljava/util/List<Ljava/lang/Class<*>;>;)Ljava/lang/invoke/MethodType;", $PRIVATE | $STATIC, $staticMethod(VarHandles, methodTypeFor, $MethodType*, $VarHandle$AccessType*, $MethodType*, $List*, $List*)},
	{"noCheckedExceptions", "(Ljava/lang/invoke/MethodHandle;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(VarHandles, noCheckedExceptions, void, $MethodHandle*)},
	{"numTrailingArgs", "(Ljava/lang/invoke/VarHandle$AccessType;)I", nullptr, $PRIVATE | $STATIC, $staticMethod(VarHandles, numTrailingArgs, int32_t, $VarHandle$AccessType*)},
	{"permuteCoordinates", "(Ljava/lang/invoke/VarHandle;Ljava/util/List;[I)Ljava/lang/invoke/VarHandle;", "(Ljava/lang/invoke/VarHandle;Ljava/util/List<Ljava/lang/Class<*>;>;[I)Ljava/lang/invoke/VarHandle;", $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(VarHandles, permuteCoordinates, $VarHandle*, $VarHandle*, $List*, $ints*)},
	{"reorderArrayFor", "(Ljava/lang/invoke/VarHandle$AccessType;Ljava/util/List;[I)[I", "(Ljava/lang/invoke/VarHandle$AccessType;Ljava/util/List<Ljava/lang/Class<*>;>;[I)[I", $PRIVATE | $STATIC, $staticMethod(VarHandles, reorderArrayFor, $ints*, $VarHandle$AccessType*, $List*, $ints*)},
	{}
};

$InnerClassInfo _VarHandles_InnerClassesInfo_[] = {
	{"java.lang.invoke.VarHandles$2", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{"java.lang.invoke.VarHandles$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _VarHandles_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.lang.invoke.VarHandles",
	"java.lang.Object",
	nullptr,
	_VarHandles_FieldInfo_,
	_VarHandles_MethodInfo_,
	nullptr,
	nullptr,
	_VarHandles_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.lang.invoke.VarHandles$2,java.lang.invoke.VarHandles$1"
};

$Object* allocate$VarHandles($Class* clazz) {
	return $of($alloc(VarHandles));
}

bool VarHandles::$assertionsDisabled = false;
$ClassValue* VarHandles::ADDRESS_FACTORIES = nullptr;

void VarHandles::init$() {
}

$VarHandle* VarHandles::makeFieldHandle($MemberName* f, $Class* refc, $Class* type, bool isWriteAllowedOnFinalFields) {
	$init(VarHandles);
	$useLocalCurrentObjectStackCache();
	if (!$nc(f)->isStatic()) {
		int64_t foffset = $MethodHandleNatives::objectFieldOffset(f);
		if (!$nc(type)->isPrimitive()) {
			return maybeAdapt(f->isFinal() && !isWriteAllowedOnFinalFields ? static_cast<$VarHandle*>($$new($VarHandleReferences$FieldInstanceReadOnly, refc, foffset, type)) : static_cast<$VarHandle*>($$new($VarHandleReferences$FieldInstanceReadWrite, refc, foffset, type)));
		} else {
			$init($Boolean);
			if (type == $Boolean::TYPE) {
				return maybeAdapt(f->isFinal() && !isWriteAllowedOnFinalFields ? static_cast<$VarHandle*>($$new($VarHandleBooleans$FieldInstanceReadOnly, refc, foffset)) : static_cast<$VarHandle*>($$new($VarHandleBooleans$FieldInstanceReadWrite, refc, foffset)));
			} else {
				$init($Byte);
				if (type == $Byte::TYPE) {
					return maybeAdapt(f->isFinal() && !isWriteAllowedOnFinalFields ? static_cast<$VarHandle*>($$new($VarHandleBytes$FieldInstanceReadOnly, refc, foffset)) : static_cast<$VarHandle*>($$new($VarHandleBytes$FieldInstanceReadWrite, refc, foffset)));
				} else {
					$init($Short);
					if (type == $Short::TYPE) {
						return maybeAdapt(f->isFinal() && !isWriteAllowedOnFinalFields ? static_cast<$VarHandle*>($$new($VarHandleShorts$FieldInstanceReadOnly, refc, foffset)) : static_cast<$VarHandle*>($$new($VarHandleShorts$FieldInstanceReadWrite, refc, foffset)));
					} else {
						$init($Character);
						if (type == $Character::TYPE) {
							return maybeAdapt(f->isFinal() && !isWriteAllowedOnFinalFields ? static_cast<$VarHandle*>($$new($VarHandleChars$FieldInstanceReadOnly, refc, foffset)) : static_cast<$VarHandle*>($$new($VarHandleChars$FieldInstanceReadWrite, refc, foffset)));
						} else {
							$init($Integer);
							if (type == $Integer::TYPE) {
								return maybeAdapt(f->isFinal() && !isWriteAllowedOnFinalFields ? static_cast<$VarHandle*>($$new($VarHandleInts$FieldInstanceReadOnly, refc, foffset)) : static_cast<$VarHandle*>($$new($VarHandleInts$FieldInstanceReadWrite, refc, foffset)));
							} else {
								$init($Long);
								if (type == $Long::TYPE) {
									return maybeAdapt(f->isFinal() && !isWriteAllowedOnFinalFields ? static_cast<$VarHandle*>($$new($VarHandleLongs$FieldInstanceReadOnly, refc, foffset)) : static_cast<$VarHandle*>($$new($VarHandleLongs$FieldInstanceReadWrite, refc, foffset)));
								} else {
									$init($Float);
									if (type == $Float::TYPE) {
										return maybeAdapt(f->isFinal() && !isWriteAllowedOnFinalFields ? static_cast<$VarHandle*>($$new($VarHandleFloats$FieldInstanceReadOnly, refc, foffset)) : static_cast<$VarHandle*>($$new($VarHandleFloats$FieldInstanceReadWrite, refc, foffset)));
									} else {
										$init($Double);
										if (type == $Double::TYPE) {
											return maybeAdapt(f->isFinal() && !isWriteAllowedOnFinalFields ? static_cast<$VarHandle*>($$new($VarHandleDoubles$FieldInstanceReadOnly, refc, foffset)) : static_cast<$VarHandle*>($$new($VarHandleDoubles$FieldInstanceReadWrite, refc, foffset)));
										} else {
											$throwNew($UnsupportedOperationException);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	} else {
		$init($MethodHandleStatics);
		if ($nc($MethodHandleStatics::UNSAFE)->shouldBeInitialized(refc)) {
			$nc($MethodHandleStatics::UNSAFE)->ensureClassInitialized(refc);
		}
		$var($Object, base, $MethodHandleNatives::staticFieldBase(f));
		int64_t foffset = $MethodHandleNatives::staticFieldOffset(f);
		if (!$nc(type)->isPrimitive()) {
			return maybeAdapt(f->isFinal() && !isWriteAllowedOnFinalFields ? static_cast<$VarHandle*>($$new($VarHandleReferences$FieldStaticReadOnly, base, foffset, type)) : static_cast<$VarHandle*>($$new($VarHandleReferences$FieldStaticReadWrite, base, foffset, type)));
		} else {
			$init($Boolean);
			if (type == $Boolean::TYPE) {
				return maybeAdapt(f->isFinal() && !isWriteAllowedOnFinalFields ? static_cast<$VarHandle*>($$new($VarHandleBooleans$FieldStaticReadOnly, base, foffset)) : static_cast<$VarHandle*>($$new($VarHandleBooleans$FieldStaticReadWrite, base, foffset)));
			} else {
				$init($Byte);
				if (type == $Byte::TYPE) {
					return maybeAdapt(f->isFinal() && !isWriteAllowedOnFinalFields ? static_cast<$VarHandle*>($$new($VarHandleBytes$FieldStaticReadOnly, base, foffset)) : static_cast<$VarHandle*>($$new($VarHandleBytes$FieldStaticReadWrite, base, foffset)));
				} else {
					$init($Short);
					if (type == $Short::TYPE) {
						return maybeAdapt(f->isFinal() && !isWriteAllowedOnFinalFields ? static_cast<$VarHandle*>($$new($VarHandleShorts$FieldStaticReadOnly, base, foffset)) : static_cast<$VarHandle*>($$new($VarHandleShorts$FieldStaticReadWrite, base, foffset)));
					} else {
						$init($Character);
						if (type == $Character::TYPE) {
							return maybeAdapt(f->isFinal() && !isWriteAllowedOnFinalFields ? static_cast<$VarHandle*>($$new($VarHandleChars$FieldStaticReadOnly, base, foffset)) : static_cast<$VarHandle*>($$new($VarHandleChars$FieldStaticReadWrite, base, foffset)));
						} else {
							$init($Integer);
							if (type == $Integer::TYPE) {
								return maybeAdapt(f->isFinal() && !isWriteAllowedOnFinalFields ? static_cast<$VarHandle*>($$new($VarHandleInts$FieldStaticReadOnly, base, foffset)) : static_cast<$VarHandle*>($$new($VarHandleInts$FieldStaticReadWrite, base, foffset)));
							} else {
								$init($Long);
								if (type == $Long::TYPE) {
									return maybeAdapt(f->isFinal() && !isWriteAllowedOnFinalFields ? static_cast<$VarHandle*>($$new($VarHandleLongs$FieldStaticReadOnly, base, foffset)) : static_cast<$VarHandle*>($$new($VarHandleLongs$FieldStaticReadWrite, base, foffset)));
								} else {
									$init($Float);
									if (type == $Float::TYPE) {
										return maybeAdapt(f->isFinal() && !isWriteAllowedOnFinalFields ? static_cast<$VarHandle*>($$new($VarHandleFloats$FieldStaticReadOnly, base, foffset)) : static_cast<$VarHandle*>($$new($VarHandleFloats$FieldStaticReadWrite, base, foffset)));
									} else {
										$init($Double);
										if (type == $Double::TYPE) {
											return maybeAdapt(f->isFinal() && !isWriteAllowedOnFinalFields ? static_cast<$VarHandle*>($$new($VarHandleDoubles$FieldStaticReadOnly, base, foffset)) : static_cast<$VarHandle*>($$new($VarHandleDoubles$FieldStaticReadWrite, base, foffset)));
										} else {
											$throwNew($UnsupportedOperationException);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

$Field* VarHandles::getFieldFromReceiverAndOffset($Class* receiverType, int64_t offset, $Class* fieldType) {
	$init(VarHandles);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	{
		$var($FieldArray, arr$, $nc(receiverType)->getDeclaredFields());
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Field, f, arr$->get(i$));
			{
				if ($Modifier::isStatic($nc(f)->getModifiers())) {
					continue;
				}
				$init($MethodHandleStatics);
				if (offset == $nc($MethodHandleStatics::UNSAFE)->objectFieldOffset(f)) {
					if (!VarHandles::$assertionsDisabled && !($nc(f)->getType() == fieldType)) {
						$throwNew($AssertionError);
					}
					return f;
				}
			}
		}
	}
	$throwNew($InternalError, "Field not found at offset"_s);
}

$Field* VarHandles::getStaticFieldFromBaseAndOffset(Object$* base, int64_t offset, $Class* fieldType) {
	$init(VarHandles);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$Class* receiverType = $cast($Class, base);
	{
		$var($FieldArray, arr$, $nc(receiverType)->getDeclaredFields());
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Field, f, arr$->get(i$));
			{
				if (!$Modifier::isStatic($nc(f)->getModifiers())) {
					continue;
				}
				$init($MethodHandleStatics);
				if (offset == $nc($MethodHandleStatics::UNSAFE)->staticFieldOffset(f)) {
					if (!VarHandles::$assertionsDisabled && !($nc(f)->getType() == fieldType)) {
						$throwNew($AssertionError);
					}
					return f;
				}
			}
		}
	}
	$throwNew($InternalError, "Static field not found at offset"_s);
}

$VarHandle* VarHandles::makeArrayElementHandle($Class* arrayClass) {
	$init(VarHandles);
	$useLocalCurrentObjectStackCache();
	if (!$nc(arrayClass)->isArray()) {
		$throwNew($IllegalArgumentException, $$str({"not an array: "_s, arrayClass}));
	}
	$Class* componentType = $nc(arrayClass)->getComponentType();
	$init($MethodHandleStatics);
	int32_t aoffset = $nc($MethodHandleStatics::UNSAFE)->arrayBaseOffset(arrayClass);
	int32_t ascale = $nc($MethodHandleStatics::UNSAFE)->arrayIndexScale(arrayClass);
	int32_t ashift = 31 - $Integer::numberOfLeadingZeros(ascale);
	if (!$nc(componentType)->isPrimitive()) {
		return maybeAdapt($$new($VarHandleReferences$Array, aoffset, ashift, arrayClass));
	} else {
		$init($Boolean);
		if (componentType == $Boolean::TYPE) {
			return maybeAdapt($$new($VarHandleBooleans$Array, aoffset, ashift));
		} else {
			$init($Byte);
			if (componentType == $Byte::TYPE) {
				return maybeAdapt($$new($VarHandleBytes$Array, aoffset, ashift));
			} else {
				$init($Short);
				if (componentType == $Short::TYPE) {
					return maybeAdapt($$new($VarHandleShorts$Array, aoffset, ashift));
				} else {
					$init($Character);
					if (componentType == $Character::TYPE) {
						return maybeAdapt($$new($VarHandleChars$Array, aoffset, ashift));
					} else {
						if (componentType == $Integer::TYPE) {
							return maybeAdapt($$new($VarHandleInts$Array, aoffset, ashift));
						} else {
							$init($Long);
							if (componentType == $Long::TYPE) {
								return maybeAdapt($$new($VarHandleLongs$Array, aoffset, ashift));
							} else {
								$init($Float);
								if (componentType == $Float::TYPE) {
									return maybeAdapt($$new($VarHandleFloats$Array, aoffset, ashift));
								} else {
									$init($Double);
									if (componentType == $Double::TYPE) {
										return maybeAdapt($$new($VarHandleDoubles$Array, aoffset, ashift));
									} else {
										$throwNew($UnsupportedOperationException);
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

$VarHandle* VarHandles::byteArrayViewHandle($Class* viewArrayClass, bool be) {
	$init(VarHandles);
	$useLocalCurrentObjectStackCache();
	if (!$nc(viewArrayClass)->isArray()) {
		$throwNew($IllegalArgumentException, $$str({"not an array: "_s, viewArrayClass}));
	}
	$Class* viewComponentType = $nc(viewArrayClass)->getComponentType();
	$init($Long);
	if (viewComponentType == $Long::TYPE) {
		return maybeAdapt($$new($VarHandleByteArrayAsLongs$ArrayHandle, be));
	} else {
		$init($Integer);
		if (viewComponentType == $Integer::TYPE) {
			return maybeAdapt($$new($VarHandleByteArrayAsInts$ArrayHandle, be));
		} else {
			$init($Short);
			if (viewComponentType == $Short::TYPE) {
				return maybeAdapt($$new($VarHandleByteArrayAsShorts$ArrayHandle, be));
			} else {
				$init($Character);
				if (viewComponentType == $Character::TYPE) {
					return maybeAdapt($$new($VarHandleByteArrayAsChars$ArrayHandle, be));
				} else {
					$init($Double);
					if (viewComponentType == $Double::TYPE) {
						return maybeAdapt($$new($VarHandleByteArrayAsDoubles$ArrayHandle, be));
					} else {
						$init($Float);
						if (viewComponentType == $Float::TYPE) {
							return maybeAdapt($$new($VarHandleByteArrayAsFloats$ArrayHandle, be));
						}
					}
				}
			}
		}
	}
	$throwNew($UnsupportedOperationException);
}

$VarHandle* VarHandles::makeByteBufferViewHandle($Class* viewArrayClass, bool be) {
	$init(VarHandles);
	$useLocalCurrentObjectStackCache();
	if (!$nc(viewArrayClass)->isArray()) {
		$throwNew($IllegalArgumentException, $$str({"not an array: "_s, viewArrayClass}));
	}
	$Class* viewComponentType = $nc(viewArrayClass)->getComponentType();
	$init($Long);
	if (viewComponentType == $Long::TYPE) {
		return maybeAdapt($$new($VarHandleByteArrayAsLongs$ByteBufferHandle, be));
	} else {
		$init($Integer);
		if (viewComponentType == $Integer::TYPE) {
			return maybeAdapt($$new($VarHandleByteArrayAsInts$ByteBufferHandle, be));
		} else {
			$init($Short);
			if (viewComponentType == $Short::TYPE) {
				return maybeAdapt($$new($VarHandleByteArrayAsShorts$ByteBufferHandle, be));
			} else {
				$init($Character);
				if (viewComponentType == $Character::TYPE) {
					return maybeAdapt($$new($VarHandleByteArrayAsChars$ByteBufferHandle, be));
				} else {
					$init($Double);
					if (viewComponentType == $Double::TYPE) {
						return maybeAdapt($$new($VarHandleByteArrayAsDoubles$ByteBufferHandle, be));
					} else {
						$init($Float);
						if (viewComponentType == $Float::TYPE) {
							return maybeAdapt($$new($VarHandleByteArrayAsFloats$ByteBufferHandle, be));
						}
					}
				}
			}
		}
	}
	$throwNew($UnsupportedOperationException);
}

$VarHandle* VarHandles::makeMemoryAddressViewHandle($Class* carrier, bool skipAlignmentMaskCheck, int64_t alignmentMask, $ByteOrder* byteOrder) {
	$init(VarHandles);
	$useLocalCurrentObjectStackCache();
	$init($Void);
	$init($Boolean);
	if (!$nc(carrier)->isPrimitive() || carrier == $Void::TYPE || carrier == $Boolean::TYPE) {
		$throwNew($IllegalArgumentException, $$str({"Invalid carrier: "_s, $($nc(carrier)->getName())}));
	}
	int64_t size = $nc($($Wrapper::forPrimitiveType(carrier)))->bitWidth() / 8;
	$init($ByteOrder);
	bool be = byteOrder == $ByteOrder::BIG_ENDIAN;
	bool exact = false;
	$init($Byte);
	if (carrier == $Byte::TYPE) {
		return maybeAdapt($$new($MemoryAccessVarHandleByteHelper, skipAlignmentMaskCheck, be, size, alignmentMask, exact));
	} else {
		$init($Character);
		if (carrier == $Character::TYPE) {
			return maybeAdapt($$new($MemoryAccessVarHandleCharHelper, skipAlignmentMaskCheck, be, size, alignmentMask, exact));
		} else {
			$init($Short);
			if (carrier == $Short::TYPE) {
				return maybeAdapt($$new($MemoryAccessVarHandleShortHelper, skipAlignmentMaskCheck, be, size, alignmentMask, exact));
			} else {
				$init($Integer);
				if (carrier == $Integer::TYPE) {
					return maybeAdapt($$new($MemoryAccessVarHandleIntHelper, skipAlignmentMaskCheck, be, size, alignmentMask, exact));
				} else {
					$init($Float);
					if (carrier == $Float::TYPE) {
						return maybeAdapt($$new($MemoryAccessVarHandleFloatHelper, skipAlignmentMaskCheck, be, size, alignmentMask, exact));
					} else {
						$init($Long);
						if (carrier == $Long::TYPE) {
							return maybeAdapt($$new($MemoryAccessVarHandleLongHelper, skipAlignmentMaskCheck, be, size, alignmentMask, exact));
						} else {
							$init($Double);
							if (carrier == $Double::TYPE) {
								return maybeAdapt($$new($MemoryAccessVarHandleDoubleHelper, skipAlignmentMaskCheck, be, size, alignmentMask, exact));
							} else {
								$throwNew($IllegalStateException, "Cannot get here"_s);
							}
						}
					}
				}
			}
		}
	}
}

$VarHandle* VarHandles::maybeAdapt($VarHandle* target$renamed) {
	$init(VarHandles);
	$useLocalCurrentObjectStackCache();
	$var($VarHandle, target, target$renamed);
	$init($MethodHandleStatics);
	if (!$MethodHandleStatics::VAR_HANDLE_IDENTITY_ADAPT) {
		return target;
	}
	$var($VarHandle, var$0, target);
	$var($MethodHandle, var$1, $MethodHandles::identity($nc(target)->varType()));
	$assign(target, filterValue(var$0, var$1, $($MethodHandles::identity($nc(target)->varType()))));
	$init($VarHandle$AccessMode);
	$var($MethodType, mtype, $nc(target)->accessModeType($VarHandle$AccessMode::GET));
	for (int32_t i = 0; i < $nc(mtype)->parameterCount(); ++i) {
		$assign(target, filterCoordinates(target, i, $$new($MethodHandleArray, {$($MethodHandles::identity($($cast($Class, mtype->parameterType(i)))))})));
	}
	return target;
}

$VarHandle* VarHandles::filterValue($VarHandle* target, $MethodHandle* filterToTarget, $MethodHandle* filterFromTarget) {
	$init(VarHandles);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(target);
	$Objects::requireNonNull(filterToTarget);
	$Objects::requireNonNull(filterFromTarget);
	noCheckedExceptions(filterToTarget);
	noCheckedExceptions(filterFromTarget);
	$var($List, newCoordinates, $new($ArrayList));
	$var($List, additionalCoordinates, $new($ArrayList));
	newCoordinates->addAll($(target->coordinateTypes()));
	int32_t var$0 = $nc($(filterFromTarget->type()))->parameterCount();
	if (var$0 != $nc($(filterToTarget->type()))->parameterCount()) {
		$var($String, var$1, "filterFromTarget and filterToTarget have different arity"_s);
		$var($Object, var$2, $of(filterFromTarget->type()));
		$throw($($MethodHandleStatics::newIllegalArgumentException(var$1, var$2, $(filterToTarget->type()))));
	} else if ($nc($(filterFromTarget->type()))->parameterCount() < 1) {
		$throw($($MethodHandleStatics::newIllegalArgumentException("filterFromTarget filter type has wrong arity"_s, $(filterFromTarget->type()))));
	} else if ($nc($(filterToTarget->type()))->parameterCount() < 1) {
		$throw($($MethodHandleStatics::newIllegalArgumentException("filterToTarget filter type has wrong arity"_s, $(filterFromTarget->type()))));
	} else {
		bool var$4 = $nc($(filterFromTarget->type()))->lastParameterType() != $cast($Class, $nc($(filterToTarget->type()))->returnType());
		if (!var$4) {
			var$4 = $nc($(filterToTarget->type()))->lastParameterType() != $cast($Class, $nc($(filterFromTarget->type()))->returnType());
		}
		if (var$4) {
			$var($String, var$5, "filterFromTarget and filterToTarget filter types do not match"_s);
			$var($Object, var$6, $of(filterFromTarget->type()));
			$throw($($MethodHandleStatics::newIllegalArgumentException(var$5, var$6, $(filterToTarget->type()))));
		} else if (target->varType() != $nc($(filterFromTarget->type()))->lastParameterType()) {
			$var($String, var$7, "filterFromTarget filter type does not match target var handle type"_s);
			$var($Object, var$8, $of(filterFromTarget->type()));
			$throw($($MethodHandleStatics::newIllegalArgumentException(var$7, var$8, target->varType())));
		} else if (target->varType() != $cast($Class, $nc($(filterToTarget->type()))->returnType())) {
			$var($String, var$9, "filterFromTarget filter type does not match target var handle type"_s);
			$var($Object, var$10, $of(filterToTarget->type()));
			$throw($($MethodHandleStatics::newIllegalArgumentException(var$9, var$10, target->varType())));
		} else if ($nc($(filterFromTarget->type()))->parameterCount() > 1) {
			for (int32_t i = 0; i < $nc($(filterFromTarget->type()))->parameterCount() - 1; ++i) {
				if ($cast($Class, $nc($(filterFromTarget->type()))->parameterType(i)) != $cast($Class, $nc($(filterToTarget->type()))->parameterType(i))) {
					$var($String, var$11, "filterFromTarget and filterToTarget filter types do not match"_s);
					$var($Object, var$12, $of(filterFromTarget->type()));
					$throw($($MethodHandleStatics::newIllegalArgumentException(var$11, var$12, $(filterToTarget->type()))));
				} else {
					newCoordinates->add($($nc($(filterFromTarget->type()))->parameterType(i)));
					additionalCoordinates->add(($($nc($(filterFromTarget->type()))->parameterType(i))));
				}
			}
		}
	}
	$var($VarHandle, var$13, target);
	$Class* var$14 = $cast($Class, $nc($(filterFromTarget->type()))->returnType());
	$var($ClassArray, var$15, $fcast($ClassArray, newCoordinates->toArray($$new($ClassArray, 0))));
	return $new($IndirectVarHandle, var$13, var$14, var$15, static_cast<$BiFunction*>($$new(VarHandles$$Lambda$lambda$filterValue$0, filterFromTarget, filterToTarget, additionalCoordinates)));
}

$MethodHandle* VarHandles::joinDuplicateArgs($MethodHandle* handle, int32_t originalStart, int32_t dropStart, int32_t length) {
	$init(VarHandles);
	$useLocalCurrentObjectStackCache();
	$var($ints, perms, $new($ints, $nc($($nc(handle)->type()))->parameterCount()));
	for (int32_t i = 0; i < dropStart; ++i) {
		perms->set(i, i);
	}
	for (int32_t i = 0; i < length; ++i) {
		perms->set(dropStart + i, originalStart + i);
	}
	for (int32_t i = dropStart + length; i < perms->length; ++i) {
		perms->set(i, i - length);
	}
	return $MethodHandles::permuteArguments(handle, $($cast($MethodType, $nc($(handle->type()))->dropParameterTypes(dropStart, dropStart + length))), perms);
}

$VarHandle* VarHandles::filterCoordinates($VarHandle* target, int32_t pos, $MethodHandleArray* filters) {
	$init(VarHandles);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(target);
	$Objects::requireNonNull(filters);
	$var($List, targetCoordinates, target->coordinateTypes());
	if (pos < 0 || pos >= $nc(targetCoordinates)->size()) {
		$throw($($MethodHandleStatics::newIllegalArgumentException($$str({"Invalid position "_s, $$str(pos), " for coordinate types"_s}), targetCoordinates)));
	} else if (pos + filters->length > targetCoordinates->size()) {
		$throwNew($IllegalArgumentException, "Too many filters"_s);
	}
	if (filters->length == 0) {
		return target;
	}
	$var($List, newCoordinates, $new($ArrayList, static_cast<$Collection*>(targetCoordinates)));
	for (int32_t i = 0; i < filters->length; ++i) {
		noCheckedExceptions(filters->get(i));
		$var($MethodType, filterType, $nc(filters->get(i))->type());
		if ($nc(filterType)->parameterCount() != 1) {
			$throw($($MethodHandleStatics::newIllegalArgumentException($$str({"Invalid filter type "_s, filterType}))));
		} else if (!$equals(newCoordinates->get(pos + i), $cast($Class, filterType->returnType()))) {
			$var($String, var$0, $$str({"Invalid filter type "_s, filterType, " for coordinate type "_s}));
			$throw($($MethodHandleStatics::newIllegalArgumentException($$concat(var$0, $(newCoordinates->get(i))))));
		}
		newCoordinates->set(pos + i, $($nc($($nc(filters->get(i))->type()))->parameterType(0)));
	}
	$var($VarHandle, var$1, target);
	$Class* var$2 = target->varType();
	$var($ClassArray, var$3, $fcast($ClassArray, newCoordinates->toArray($$new($ClassArray, 0))));
	return $new($IndirectVarHandle, var$1, var$2, var$3, static_cast<$BiFunction*>($$new(VarHandles$$Lambda$lambda$filterCoordinates$1$1, pos, filters)));
}

$VarHandle* VarHandles::insertCoordinates($VarHandle* target, int32_t pos, $ObjectArray* values) {
	$init(VarHandles);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(target);
	$Objects::requireNonNull(values);
	$var($List, targetCoordinates, target->coordinateTypes());
	if (pos < 0 || pos >= $nc(targetCoordinates)->size()) {
		$throw($($MethodHandleStatics::newIllegalArgumentException($$str({"Invalid position "_s, $$str(pos), " for coordinate types"_s}), targetCoordinates)));
	} else if (pos + values->length > targetCoordinates->size()) {
		$throwNew($IllegalArgumentException, "Too many values"_s);
	}
	if (values->length == 0) {
		return target;
	}
	$var($List, newCoordinates, $new($ArrayList, static_cast<$Collection*>(targetCoordinates)));
	for (int32_t i = 0; i < values->length; ++i) {
		$Class* pt = $cast($Class, newCoordinates->get(pos));
		if ($nc(pt)->isPrimitive()) {
			$Wrapper* w = $Wrapper::forPrimitiveType(pt);
			$nc(w)->convert(values->get(i), pt);
		} else {
			pt->cast(values->get(i));
		}
		newCoordinates->remove(pos);
	}
	$var($VarHandle, var$0, target);
	$Class* var$1 = target->varType();
	$var($ClassArray, var$2, $fcast($ClassArray, newCoordinates->toArray($$new($ClassArray, 0))));
	return $new($IndirectVarHandle, var$0, var$1, var$2, static_cast<$BiFunction*>($$new(VarHandles$$Lambda$lambda$insertCoordinates$2$2, pos, values)));
}

$VarHandle* VarHandles::permuteCoordinates($VarHandle* target, $List* newCoordinates, $ints* reorder) {
	$init(VarHandles);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(target);
	$Objects::requireNonNull(newCoordinates);
	$Objects::requireNonNull(reorder);
	$var($List, targetCoordinates, target->coordinateTypes());
	$var($ints, var$0, reorder);
	$init($Void);
	$var($MethodType, var$1, $MethodType::methodType($Void::TYPE, newCoordinates));
	$MethodHandles::permuteArgumentChecks(var$0, var$1, $($MethodType::methodType($Void::TYPE, targetCoordinates)));
	$var($VarHandle, var$2, target);
	$Class* var$3 = target->varType();
	$var($ClassArray, var$4, $fcast($ClassArray, newCoordinates->toArray($$new($ClassArray, 0))));
	return $new($IndirectVarHandle, var$2, var$3, var$4, static_cast<$BiFunction*>($$new(VarHandles$$Lambda$lambda$permuteCoordinates$3$3, targetCoordinates, newCoordinates, reorder)));
}

int32_t VarHandles::numTrailingArgs($VarHandle$AccessType* at) {
	$init(VarHandles);
	$init($VarHandles$2);

	int32_t var$0 = 0;
	switch ($nc($VarHandles$2::$SwitchMap$java$lang$invoke$VarHandle$AccessType)->get($nc((at))->ordinal())) {
	default:
		{
			$throwNew($IncompatibleClassChangeError);
		}
	case 1:
		{
			var$0 = 0;
			break;
		}
	case 2:
		{}
	case 3:
		{
			var$0 = 1;
			break;
		}
	case 4:
		{}
	case 5:
		{
			var$0 = 2;
			break;
		}
	}
	return var$0;
}

$ints* VarHandles::reorderArrayFor($VarHandle$AccessType* at, $List* newCoordinates, $ints* reorder) {
	$init(VarHandles);
	int32_t numTrailingArgs = VarHandles::numTrailingArgs(at);
	$var($ints, adjustedReorder, $new($ints, $nc(reorder)->length + 1 + numTrailingArgs));
	adjustedReorder->set(0, 0);
	for (int32_t i = 0; i < reorder->length; ++i) {
		adjustedReorder->set(i + 1, reorder->get(i) + 1);
	}
	for (int32_t i = 0; i < numTrailingArgs; ++i) {
		adjustedReorder->set(i + reorder->length + 1, i + $nc(newCoordinates)->size() + 1);
	}
	return adjustedReorder;
}

$MethodType* VarHandles::methodTypeFor($VarHandle$AccessType* at, $MethodType* oldType, $List* oldCoordinates, $List* newCoordinates) {
	$init(VarHandles);
	$useLocalCurrentObjectStackCache();
	int32_t numTrailingArgs = VarHandles::numTrailingArgs(at);
	$Class* var$0 = $cast($Class, $nc(oldType)->returnType());
	$var($MethodType, adjustedType, $MethodType::methodType(var$0, $($cast($Class, oldType->parameterType(0)))));
	$assign(adjustedType, $nc(adjustedType)->appendParameterTypes(newCoordinates));
	for (int32_t i = 0; i < numTrailingArgs; ++i) {
		$assign(adjustedType, adjustedType->appendParameterTypes($$new($ClassArray, {$($cast($Class, $nc(oldType)->parameterType(1 + $nc(oldCoordinates)->size() + i)))})));
	}
	return adjustedType;
}

$VarHandle* VarHandles::collectCoordinates($VarHandle* target, int32_t pos, $MethodHandle* filter) {
	$init(VarHandles);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(target);
	$Objects::requireNonNull(filter);
	noCheckedExceptions(filter);
	$var($List, targetCoordinates, target->coordinateTypes());
	if (pos < 0 || pos >= $nc(targetCoordinates)->size()) {
		$throw($($MethodHandleStatics::newIllegalArgumentException($$str({"Invalid position "_s, $$str(pos), " for coordinate types"_s}), targetCoordinates)));
	} else {
		$init($Void);
		if ($cast($Class, $nc($(filter->type()))->returnType()) == $Void::TYPE) {
			$throw($($MethodHandleStatics::newIllegalArgumentException($$str({"Invalid filter type "_s, $(filter->type()), " ; filter cannot be void"_s}))));
		} else if (!$equals($cast($Class, $nc($(filter->type()))->returnType()), targetCoordinates->get(pos))) {
			$var($String, var$0, $$str({"Invalid filter type "_s, $(filter->type()), " for coordinate type "_s}));
			$throw($($MethodHandleStatics::newIllegalArgumentException($$concat(var$0, $(targetCoordinates->get(pos))))));
		}
	}
	$var($List, newCoordinates, $new($ArrayList, static_cast<$Collection*>(targetCoordinates)));
	newCoordinates->remove(pos);
	newCoordinates->addAll(pos, $($nc($(filter->type()))->parameterList()));
	$var($VarHandle, var$1, target);
	$Class* var$2 = target->varType();
	$var($ClassArray, var$3, $fcast($ClassArray, newCoordinates->toArray($$new($ClassArray, 0))));
	return $new($IndirectVarHandle, var$1, var$2, var$3, static_cast<$BiFunction*>($$new(VarHandles$$Lambda$lambda$collectCoordinates$4$4, pos, filter)));
}

$VarHandle* VarHandles::dropCoordinates($VarHandle* target, int32_t pos, $ClassArray* valueTypes) {
	$init(VarHandles);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(target);
	$Objects::requireNonNull(valueTypes);
	$var($List, targetCoordinates, target->coordinateTypes());
	if (pos < 0 || pos > $nc(targetCoordinates)->size()) {
		$throw($($MethodHandleStatics::newIllegalArgumentException($$str({"Invalid position "_s, $$str(pos), " for coordinate types"_s}), targetCoordinates)));
	}
	if (valueTypes->length == 0) {
		return target;
	}
	$var($List, newCoordinates, $new($ArrayList, static_cast<$Collection*>(targetCoordinates)));
	newCoordinates->addAll(pos, $($List::of(valueTypes)));
	$var($VarHandle, var$0, target);
	$Class* var$1 = target->varType();
	$var($ClassArray, var$2, $fcast($ClassArray, newCoordinates->toArray($$new($ClassArray, 0))));
	return $new($IndirectVarHandle, var$0, var$1, var$2, static_cast<$BiFunction*>($$new(VarHandles$$Lambda$lambda$dropCoordinates$5$5, pos, valueTypes)));
}

void VarHandles::noCheckedExceptions($MethodHandle* handle) {
	$init(VarHandles);
	$useLocalCurrentObjectStackCache();
	{
		$var($DirectMethodHandle, directHandle, nullptr);
		bool var$0 = $instanceOf($DirectMethodHandle, handle);
		if (var$0) {
			$assign(directHandle, $cast($DirectMethodHandle, handle));
			var$0 = true;
		}
		if (var$0) {
			int8_t refKind = $nc($nc(directHandle)->member)->getReferenceKind();
			$init($MethodHandles$Lookup);
			$var($MethodHandleInfo, info, $new($InfoFromMemberName, $MethodHandles$Lookup::IMPL_LOOKUP, directHandle->member, refKind));
			$var($ClassArray, exceptionTypes, nullptr);
			if ($MethodHandleNatives::refKindIsMethod(refKind)) {
				$load($Method);
				$assign(exceptionTypes, $nc(($cast($Method, $(info->reflectAs($Method::class$, $MethodHandles$Lookup::IMPL_LOOKUP)))))->getExceptionTypes());
			} else if ($MethodHandleNatives::refKindIsField(refKind)) {
				$assign(exceptionTypes, nullptr);
			} else if ($MethodHandleNatives::refKindIsConstructor(refKind)) {
				$load($Constructor);
				$assign(exceptionTypes, $nc(($cast($Constructor, $(info->reflectAs($Constructor::class$, $MethodHandles$Lookup::IMPL_LOOKUP)))))->getExceptionTypes());
			} else {
				$throwNew($AssertionError, $of("Cannot get here"_s));
			}
			if (exceptionTypes != nullptr) {
				if ($nc($($Stream::of(exceptionTypes)))->anyMatch(static_cast<$Predicate*>($$new(VarHandles$$Lambda$isCheckedException$6)))) {
					$throw($($MethodHandleStatics::newIllegalArgumentException("Cannot adapt a var handle with a method handle which throws checked exceptions"_s)));
				}
			}
		} else if ($instanceOf($DelegatingMethodHandle, handle)) {
			noCheckedExceptions($($nc(($cast($DelegatingMethodHandle, handle)))->getTarget()));
		} else {
			$var($BoundMethodHandle, boundHandle, $cast($BoundMethodHandle, handle));
			for (int32_t i = 0; i < $nc(boundHandle)->fieldCount(); ++i) {
				$var($Object, arg, boundHandle->arg(i));
				if ($instanceOf($MethodHandle, arg)) {
					noCheckedExceptions($cast($MethodHandle, arg));
				}
			}
		}
	}
}

bool VarHandles::isCheckedException($Class* clazz) {
	$init(VarHandles);
	bool var$1 = $Throwable::class$->isAssignableFrom(clazz);
	$load($RuntimeException);
	bool var$0 = var$1 && !$RuntimeException::class$->isAssignableFrom(clazz);
	$load($Error);
	return var$0 && !$Error::class$->isAssignableFrom(clazz);
}

$MethodHandle* VarHandles::lambda$dropCoordinates$5(int32_t pos, $ClassArray* valueTypes, $VarHandle$AccessMode* mode, $MethodHandle* modeHandle) {
	$init(VarHandles);
	return $MethodHandles::dropArguments(modeHandle, 1 + pos, valueTypes);
}

$MethodHandle* VarHandles::lambda$collectCoordinates$4(int32_t pos, $MethodHandle* filter, $VarHandle$AccessMode* mode, $MethodHandle* modeHandle) {
	$init(VarHandles);
	return $MethodHandles::collectArguments(modeHandle, 1 + pos, filter);
}

$MethodHandle* VarHandles::lambda$permuteCoordinates$3($List* targetCoordinates, $List* newCoordinates, $ints* reorder, $VarHandle$AccessMode* mode, $MethodHandle* modeHandle) {
	$init(VarHandles);
	$useLocalCurrentObjectStackCache();
	$var($MethodHandle, var$0, modeHandle);
	$var($MethodType, var$1, methodTypeFor($nc(mode)->at, $($nc(modeHandle)->type()), targetCoordinates, newCoordinates));
	return $MethodHandles::permuteArguments(var$0, var$1, $(reorderArrayFor($nc(mode)->at, newCoordinates, reorder)));
}

$MethodHandle* VarHandles::lambda$insertCoordinates$2(int32_t pos, $ObjectArray* values, $VarHandle$AccessMode* mode, $MethodHandle* modeHandle) {
	$init(VarHandles);
	return $MethodHandles::insertArguments(modeHandle, 1 + pos, values);
}

$MethodHandle* VarHandles::lambda$filterCoordinates$1(int32_t pos, $MethodHandleArray* filters, $VarHandle$AccessMode* mode, $MethodHandle* modeHandle) {
	$init(VarHandles);
	return $MethodHandles::filterArguments(modeHandle, 1 + pos, filters);
}

$MethodHandle* VarHandles::lambda$filterValue$0($MethodHandle* filterFromTarget, $MethodHandle* filterToTarget, $List* additionalCoordinates, $VarHandle$AccessMode* mode, $MethodHandle* modeHandle) {
	$init(VarHandles);
	$useLocalCurrentObjectStackCache();
	int32_t lastParameterPos = $nc($($nc(modeHandle)->type()))->parameterCount() - 1;
	$init($VarHandles$2);

	$var($MethodHandle, var$0, nullptr)
	switch ($nc($VarHandles$2::$SwitchMap$java$lang$invoke$VarHandle$AccessType)->get(($nc(mode)->at)->ordinal())) {
	default:
		{
			$throwNew($IncompatibleClassChangeError);
		}
	case 1:
		{
			$assign(var$0, $MethodHandles::collectReturnValue(modeHandle, filterFromTarget));
			break;
		}
	case 3:
		{
			$assign(var$0, $MethodHandles::collectArguments(modeHandle, lastParameterPos, filterToTarget));
			break;
		}
	case 2:
		{
			{
				$var($MethodHandle, adapter, $MethodHandles::collectReturnValue(modeHandle, filterFromTarget));
				$var($MethodHandle, res, $MethodHandles::collectArguments(adapter, lastParameterPos, filterToTarget));
				if ($nc(additionalCoordinates)->size() > 0) {
					$var($MethodHandle, var$1, res);
					int32_t var$2 = lastParameterPos;
					int32_t var$3 = lastParameterPos + additionalCoordinates->size() + 1;
					$assign(res, joinDuplicateArgs(var$1, var$2, var$3, additionalCoordinates->size()));
				}
				$assign(var$0, res);
				break;
			}
		}
	case 5:
		{
			{
				$var($MethodHandle, adapter, $MethodHandles::collectReturnValue(modeHandle, filterFromTarget));
				$assign(adapter, $MethodHandles::collectArguments(adapter, lastParameterPos, filterToTarget));
				if ($nc(additionalCoordinates)->size() > 0) {
					$var($MethodHandle, var$4, adapter);
					int32_t var$5 = lastParameterPos;
					int32_t var$6 = lastParameterPos + additionalCoordinates->size() + 1;
					$assign(adapter, joinDuplicateArgs(var$4, var$5, var$6, additionalCoordinates->size()));
				}
				$var($MethodHandle, res, $MethodHandles::collectArguments(adapter, lastParameterPos - 1, filterToTarget));
				if ($nc(additionalCoordinates)->size() > 0) {
					$var($MethodHandle, var$7, res);
					int32_t var$8 = lastParameterPos - 1;
					int32_t var$9 = lastParameterPos + additionalCoordinates->size();
					$assign(res, joinDuplicateArgs(var$7, var$8, var$9, additionalCoordinates->size()));
				}
				$assign(var$0, res);
				break;
			}
		}
	case 4:
		{
			{
				$var($MethodHandle, adapter, $MethodHandles::collectArguments(modeHandle, lastParameterPos, filterToTarget));
				$var($MethodHandle, res, $MethodHandles::collectArguments(adapter, lastParameterPos - 1, filterToTarget));
				if ($nc(additionalCoordinates)->size() > 0) {
					$var($MethodHandle, var$10, res);
					int32_t var$11 = lastParameterPos - 1;
					int32_t var$12 = lastParameterPos + additionalCoordinates->size();
					$assign(res, joinDuplicateArgs(var$10, var$11, var$12, additionalCoordinates->size()));
				}
				$assign(var$0, res);
				break;
			}
		}
	}
	return var$0;
}

void clinit$VarHandles($Class* class$) {
	VarHandles::$assertionsDisabled = !VarHandles::class$->desiredAssertionStatus();
	$assignStatic(VarHandles::ADDRESS_FACTORIES, $new($VarHandles$1));
}

VarHandles::VarHandles() {
}

$Class* VarHandles::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(VarHandles$$Lambda$lambda$filterValue$0::classInfo$.name)) {
			return VarHandles$$Lambda$lambda$filterValue$0::load$(name, initialize);
		}
		if (name->equals(VarHandles$$Lambda$lambda$filterCoordinates$1$1::classInfo$.name)) {
			return VarHandles$$Lambda$lambda$filterCoordinates$1$1::load$(name, initialize);
		}
		if (name->equals(VarHandles$$Lambda$lambda$insertCoordinates$2$2::classInfo$.name)) {
			return VarHandles$$Lambda$lambda$insertCoordinates$2$2::load$(name, initialize);
		}
		if (name->equals(VarHandles$$Lambda$lambda$permuteCoordinates$3$3::classInfo$.name)) {
			return VarHandles$$Lambda$lambda$permuteCoordinates$3$3::load$(name, initialize);
		}
		if (name->equals(VarHandles$$Lambda$lambda$collectCoordinates$4$4::classInfo$.name)) {
			return VarHandles$$Lambda$lambda$collectCoordinates$4$4::load$(name, initialize);
		}
		if (name->equals(VarHandles$$Lambda$lambda$dropCoordinates$5$5::classInfo$.name)) {
			return VarHandles$$Lambda$lambda$dropCoordinates$5$5::load$(name, initialize);
		}
		if (name->equals(VarHandles$$Lambda$isCheckedException$6::classInfo$.name)) {
			return VarHandles$$Lambda$isCheckedException$6::load$(name, initialize);
		}
	}
	$loadClass(VarHandles, name, initialize, &_VarHandles_ClassInfo_, clinit$VarHandles, allocate$VarHandles);
	return class$;
}

$Class* VarHandles::class$ = nullptr;

		} // invoke
	} // lang
} // java