#include <java/util/stream/StreamOpFlag.h>

#include <java/lang/Enum.h>
#include <java/util/Comparator.h>
#include <java/util/EnumMap.h>
#include <java/util/Map.h>
#include <java/util/Spliterator.h>
#include <java/util/stream/StreamOpFlag$MaskBuilder.h>
#include <java/util/stream/StreamOpFlag$Type.h>
#include <jcpp.h>

#undef CLEAR_BITS
#undef DISTINCT
#undef FLAG_MASK
#undef FLAG_MASK_IS
#undef FLAG_MASK_NOT
#undef INITIAL_OPS_VALUE
#undef IS_DISTINCT
#undef IS_ORDERED
#undef IS_SHORT_CIRCUIT
#undef IS_SIZED
#undef IS_SIZE_ADJUSTING
#undef IS_SORTED
#undef NOT_DISTINCT
#undef NOT_ORDERED
#undef NOT_SIZED
#undef NOT_SORTED
#undef OP
#undef OP_MASK
#undef ORDERED
#undef PRESERVE_BITS
#undef SET_BITS
#undef SHORT_CIRCUIT
#undef SIZED
#undef SIZE_ADJUSTING
#undef SORTED
#undef SPLITERATOR
#undef SPLITERATOR_CHARACTERISTICS_MASK
#undef STREAM
#undef STREAM_MASK
#undef TERMINAL_OP
#undef TERMINAL_OP_MASK
#undef UPSTREAM_TERMINAL_OP
#undef UPSTREAM_TERMINAL_OP_MASK

using $StreamOpFlagArray = $Array<::java::util::stream::StreamOpFlag>;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $EnumMap = ::java::util::EnumMap;
using $Map = ::java::util::Map;
using $Spliterator = ::java::util::Spliterator;
using $StreamOpFlag$MaskBuilder = ::java::util::stream::StreamOpFlag$MaskBuilder;
using $StreamOpFlag$Type = ::java::util::stream::StreamOpFlag$Type;

namespace java {
	namespace util {
		namespace stream {

$FieldInfo _StreamOpFlag_FieldInfo_[] = {
	{"DISTINCT", "Ljava/util/stream/StreamOpFlag;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(StreamOpFlag, DISTINCT)},
	{"SORTED", "Ljava/util/stream/StreamOpFlag;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(StreamOpFlag, SORTED)},
	{"ORDERED", "Ljava/util/stream/StreamOpFlag;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(StreamOpFlag, ORDERED)},
	{"SIZED", "Ljava/util/stream/StreamOpFlag;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(StreamOpFlag, SIZED)},
	{"SHORT_CIRCUIT", "Ljava/util/stream/StreamOpFlag;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(StreamOpFlag, SHORT_CIRCUIT)},
	{"SIZE_ADJUSTING", "Ljava/util/stream/StreamOpFlag;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(StreamOpFlag, SIZE_ADJUSTING)},
	{"$VALUES", "[Ljava/util/stream/StreamOpFlag;", nullptr, $PRIVATE | $STATIC | $FINAL | $SYNTHETIC, $staticField(StreamOpFlag, $VALUES)},
	{"SET_BITS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StreamOpFlag, SET_BITS)},
	{"CLEAR_BITS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StreamOpFlag, CLEAR_BITS)},
	{"PRESERVE_BITS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StreamOpFlag, PRESERVE_BITS)},
	{"maskTable", "Ljava/util/Map;", "Ljava/util/Map<Ljava/util/stream/StreamOpFlag$Type;Ljava/lang/Integer;>;", $PRIVATE | $FINAL, $field(StreamOpFlag, maskTable)},
	{"bitPosition", "I", nullptr, $PRIVATE | $FINAL, $field(StreamOpFlag, bitPosition)},
	{"set", "I", nullptr, $PRIVATE | $FINAL, $field(StreamOpFlag, set$)},
	{"clear", "I", nullptr, $PRIVATE | $FINAL, $field(StreamOpFlag, clear$)},
	{"preserve", "I", nullptr, $PRIVATE | $FINAL, $field(StreamOpFlag, preserve)},
	{"SPLITERATOR_CHARACTERISTICS_MASK", "I", nullptr, $STATIC | $FINAL, $staticField(StreamOpFlag, SPLITERATOR_CHARACTERISTICS_MASK)},
	{"STREAM_MASK", "I", nullptr, $STATIC | $FINAL, $staticField(StreamOpFlag, STREAM_MASK)},
	{"OP_MASK", "I", nullptr, $STATIC | $FINAL, $staticField(StreamOpFlag, OP_MASK)},
	{"TERMINAL_OP_MASK", "I", nullptr, $STATIC | $FINAL, $staticField(StreamOpFlag, TERMINAL_OP_MASK)},
	{"UPSTREAM_TERMINAL_OP_MASK", "I", nullptr, $STATIC | $FINAL, $staticField(StreamOpFlag, UPSTREAM_TERMINAL_OP_MASK)},
	{"FLAG_MASK", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(StreamOpFlag, FLAG_MASK)},
	{"FLAG_MASK_IS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(StreamOpFlag, FLAG_MASK_IS)},
	{"FLAG_MASK_NOT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(StreamOpFlag, FLAG_MASK_NOT)},
	{"INITIAL_OPS_VALUE", "I", nullptr, $STATIC | $FINAL, $staticField(StreamOpFlag, INITIAL_OPS_VALUE)},
	{"IS_DISTINCT", "I", nullptr, $STATIC | $FINAL, $staticField(StreamOpFlag, IS_DISTINCT)},
	{"NOT_DISTINCT", "I", nullptr, $STATIC | $FINAL, $staticField(StreamOpFlag, NOT_DISTINCT)},
	{"IS_SORTED", "I", nullptr, $STATIC | $FINAL, $staticField(StreamOpFlag, IS_SORTED)},
	{"NOT_SORTED", "I", nullptr, $STATIC | $FINAL, $staticField(StreamOpFlag, NOT_SORTED)},
	{"IS_ORDERED", "I", nullptr, $STATIC | $FINAL, $staticField(StreamOpFlag, IS_ORDERED)},
	{"NOT_ORDERED", "I", nullptr, $STATIC | $FINAL, $staticField(StreamOpFlag, NOT_ORDERED)},
	{"IS_SIZED", "I", nullptr, $STATIC | $FINAL, $staticField(StreamOpFlag, IS_SIZED)},
	{"NOT_SIZED", "I", nullptr, $STATIC | $FINAL, $staticField(StreamOpFlag, NOT_SIZED)},
	{"IS_SHORT_CIRCUIT", "I", nullptr, $STATIC | $FINAL, $staticField(StreamOpFlag, IS_SHORT_CIRCUIT)},
	{"IS_SIZE_ADJUSTING", "I", nullptr, $STATIC | $FINAL, $staticField(StreamOpFlag, IS_SIZE_ADJUSTING)},
	{}
};

$MethodInfo _StreamOpFlag_MethodInfo_[] = {
	{"$values", "()[Ljava/util/stream/StreamOpFlag;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(StreamOpFlag, $values, $StreamOpFlagArray*)},
	{"<init>", "(Ljava/lang/String;IILjava/util/stream/StreamOpFlag$MaskBuilder;)V", "(ILjava/util/stream/StreamOpFlag$MaskBuilder;)V", $PRIVATE, $method(StreamOpFlag, init$, void, $String*, int32_t, int32_t, $StreamOpFlag$MaskBuilder*)},
	{"canSet", "(Ljava/util/stream/StreamOpFlag$Type;)Z", nullptr, 0, $method(StreamOpFlag, canSet, bool, $StreamOpFlag$Type*)},
	{"clear", "()I", nullptr, 0, $method(StreamOpFlag, clear, int32_t)},
	{"combineOpFlags", "(II)I", nullptr, $STATIC, $staticMethod(StreamOpFlag, combineOpFlags, int32_t, int32_t, int32_t)},
	{"createFlagMask", "()I", nullptr, $PRIVATE | $STATIC, $staticMethod(StreamOpFlag, createFlagMask, int32_t)},
	{"createMask", "(Ljava/util/stream/StreamOpFlag$Type;)I", nullptr, $PRIVATE | $STATIC, $staticMethod(StreamOpFlag, createMask, int32_t, $StreamOpFlag$Type*)},
	{"fromCharacteristics", "(Ljava/util/Spliterator;)I", "(Ljava/util/Spliterator<*>;)I", $STATIC, $staticMethod(StreamOpFlag, fromCharacteristics, int32_t, $Spliterator*)},
	{"fromCharacteristics", "(I)I", nullptr, $STATIC, $staticMethod(StreamOpFlag, fromCharacteristics, int32_t, int32_t)},
	{"getMask", "(I)I", nullptr, $PRIVATE | $STATIC, $staticMethod(StreamOpFlag, getMask, int32_t, int32_t)},
	{"isCleared", "(I)Z", nullptr, 0, $method(StreamOpFlag, isCleared, bool, int32_t)},
	{"isKnown", "(I)Z", nullptr, 0, $method(StreamOpFlag, isKnown, bool, int32_t)},
	{"isPreserved", "(I)Z", nullptr, 0, $method(StreamOpFlag, isPreserved, bool, int32_t)},
	{"isStreamFlag", "()Z", nullptr, 0, $method(StreamOpFlag, isStreamFlag, bool)},
	{"set", "(Ljava/util/stream/StreamOpFlag$Type;)Ljava/util/stream/StreamOpFlag$MaskBuilder;", nullptr, $PRIVATE | $STATIC, $staticMethod(StreamOpFlag, set, $StreamOpFlag$MaskBuilder*, $StreamOpFlag$Type*)},
	{"set", "()I", nullptr, 0, $method(StreamOpFlag, set, int32_t)},
	{"toCharacteristics", "(I)I", nullptr, $STATIC, $staticMethod(StreamOpFlag, toCharacteristics, int32_t, int32_t)},
	{"toStreamFlags", "(I)I", nullptr, $STATIC, $staticMethod(StreamOpFlag, toStreamFlags, int32_t, int32_t)},
	{"valueOf", "(Ljava/lang/String;)Ljava/util/stream/StreamOpFlag;", nullptr, $PUBLIC | $STATIC, $staticMethod(StreamOpFlag, valueOf, StreamOpFlag*, $String*)},
	{"values", "()[Ljava/util/stream/StreamOpFlag;", nullptr, $PUBLIC | $STATIC, $staticMethod(StreamOpFlag, values, $StreamOpFlagArray*)},
	{}
};

$InnerClassInfo _StreamOpFlag_InnerClassesInfo_[] = {
	{"java.util.stream.StreamOpFlag$MaskBuilder", "java.util.stream.StreamOpFlag", "MaskBuilder", $PRIVATE | $STATIC},
	{"java.util.stream.StreamOpFlag$Type", "java.util.stream.StreamOpFlag", "Type", $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _StreamOpFlag_ClassInfo_ = {
	$FINAL | $ACC_SUPER | $ENUM,
	"java.util.stream.StreamOpFlag",
	"java.lang.Enum",
	nullptr,
	_StreamOpFlag_FieldInfo_,
	_StreamOpFlag_MethodInfo_,
	"Ljava/lang/Enum<Ljava/util/stream/StreamOpFlag;>;",
	nullptr,
	_StreamOpFlag_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.stream.StreamOpFlag$MaskBuilder,java.util.stream.StreamOpFlag$Type"
};

$Object* allocate$StreamOpFlag($Class* clazz) {
	return $of($alloc(StreamOpFlag));
}

StreamOpFlag* StreamOpFlag::DISTINCT = nullptr;
StreamOpFlag* StreamOpFlag::SORTED = nullptr;
StreamOpFlag* StreamOpFlag::ORDERED = nullptr;
StreamOpFlag* StreamOpFlag::SIZED = nullptr;
StreamOpFlag* StreamOpFlag::SHORT_CIRCUIT = nullptr;
StreamOpFlag* StreamOpFlag::SIZE_ADJUSTING = nullptr;
$StreamOpFlagArray* StreamOpFlag::$VALUES = nullptr;
int32_t StreamOpFlag::SPLITERATOR_CHARACTERISTICS_MASK = 0;
int32_t StreamOpFlag::STREAM_MASK = 0;
int32_t StreamOpFlag::OP_MASK = 0;
int32_t StreamOpFlag::TERMINAL_OP_MASK = 0;
int32_t StreamOpFlag::UPSTREAM_TERMINAL_OP_MASK = 0;
int32_t StreamOpFlag::FLAG_MASK = 0;
int32_t StreamOpFlag::FLAG_MASK_IS = 0;
int32_t StreamOpFlag::FLAG_MASK_NOT = 0;
int32_t StreamOpFlag::INITIAL_OPS_VALUE = 0;
int32_t StreamOpFlag::IS_DISTINCT = 0;
int32_t StreamOpFlag::NOT_DISTINCT = 0;
int32_t StreamOpFlag::IS_SORTED = 0;
int32_t StreamOpFlag::NOT_SORTED = 0;
int32_t StreamOpFlag::IS_ORDERED = 0;
int32_t StreamOpFlag::NOT_ORDERED = 0;
int32_t StreamOpFlag::IS_SIZED = 0;
int32_t StreamOpFlag::NOT_SIZED = 0;
int32_t StreamOpFlag::IS_SHORT_CIRCUIT = 0;
int32_t StreamOpFlag::IS_SIZE_ADJUSTING = 0;

$StreamOpFlagArray* StreamOpFlag::$values() {
	$init(StreamOpFlag);
	return $new($StreamOpFlagArray, {
		StreamOpFlag::DISTINCT,
		StreamOpFlag::SORTED,
		StreamOpFlag::ORDERED,
		StreamOpFlag::SIZED,
		StreamOpFlag::SHORT_CIRCUIT,
		StreamOpFlag::SIZE_ADJUSTING
	});
}

$StreamOpFlagArray* StreamOpFlag::values() {
	$init(StreamOpFlag);
	return $cast($StreamOpFlagArray, StreamOpFlag::$VALUES->clone());
}

StreamOpFlag* StreamOpFlag::valueOf($String* name) {
	$init(StreamOpFlag);
	return $cast(StreamOpFlag, $Enum::valueOf(StreamOpFlag::class$, name));
}

$StreamOpFlag$MaskBuilder* StreamOpFlag::set($StreamOpFlag$Type* t) {
	$init(StreamOpFlag);
	$useLocalCurrentObjectStackCache();
	$load($StreamOpFlag$Type);
	return $$new($StreamOpFlag$MaskBuilder, $$new($EnumMap, $StreamOpFlag$Type::class$))->set(t);
}

void StreamOpFlag::init$($String* $enum$name, int32_t $enum$ordinal, int32_t position, $StreamOpFlag$MaskBuilder* maskBuilder) {
	$Enum::init$($enum$name, $enum$ordinal);
	$set(this, maskTable, $nc(maskBuilder)->build());
	position *= 2;
	this->bitPosition = position;
	this->set$ = $sl(StreamOpFlag::SET_BITS, position);
	this->clear$ = $sl(StreamOpFlag::CLEAR_BITS, position);
	this->preserve = $sl(StreamOpFlag::PRESERVE_BITS, position);
}

int32_t StreamOpFlag::set() {
	return this->set$;
}

int32_t StreamOpFlag::clear() {
	return this->clear$;
}

bool StreamOpFlag::isStreamFlag() {
	$init($StreamOpFlag$Type);
	return $nc(($cast($Integer, $($nc(this->maskTable)->get($StreamOpFlag$Type::STREAM)))))->intValue() > 0;
}

bool StreamOpFlag::isKnown(int32_t flags) {
	return ((int32_t)(flags & (uint32_t)this->preserve)) == this->set$;
}

bool StreamOpFlag::isCleared(int32_t flags) {
	return ((int32_t)(flags & (uint32_t)this->preserve)) == this->clear$;
}

bool StreamOpFlag::isPreserved(int32_t flags) {
	return ((int32_t)(flags & (uint32_t)this->preserve)) == this->preserve;
}

bool StreamOpFlag::canSet($StreamOpFlag$Type* t) {
	return ((int32_t)($nc(($cast($Integer, $($nc(this->maskTable)->get(t)))))->intValue() & (uint32_t)StreamOpFlag::SET_BITS)) > 0;
}

int32_t StreamOpFlag::createMask($StreamOpFlag$Type* t) {
	$init(StreamOpFlag);
	$useLocalCurrentObjectStackCache();
	int32_t mask = 0;
	{
		$var($StreamOpFlagArray, arr$, StreamOpFlag::values());
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			StreamOpFlag* flag = arr$->get(i$);
			{
				mask |= $sl($nc(($cast($Integer, $($nc($nc(flag)->maskTable)->get(t)))))->intValue(), flag->bitPosition);
			}
		}
	}
	return mask;
}

int32_t StreamOpFlag::createFlagMask() {
	$init(StreamOpFlag);
	int32_t mask = 0;
	{
		$var($StreamOpFlagArray, arr$, StreamOpFlag::values());
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			StreamOpFlag* flag = arr$->get(i$);
			{
				mask |= $nc(flag)->preserve;
			}
		}
	}
	return mask;
}

int32_t StreamOpFlag::getMask(int32_t flags) {
	$init(StreamOpFlag);
	return (flags == 0) ? StreamOpFlag::FLAG_MASK : ~((flags | (((int32_t)(StreamOpFlag::FLAG_MASK_IS & (uint32_t)flags)) << 1)) | (((int32_t)(StreamOpFlag::FLAG_MASK_NOT & (uint32_t)flags)) >> 1));
}

int32_t StreamOpFlag::combineOpFlags(int32_t newStreamOrOpFlags, int32_t prevCombOpFlags) {
	$init(StreamOpFlag);
	return ((int32_t)(prevCombOpFlags & (uint32_t)StreamOpFlag::getMask(newStreamOrOpFlags))) | newStreamOrOpFlags;
}

int32_t StreamOpFlag::toStreamFlags(int32_t combOpFlags) {
	$init(StreamOpFlag);
	return (int32_t)(((int32_t)(((~combOpFlags) >> 1) & (uint32_t)StreamOpFlag::FLAG_MASK_IS)) & (uint32_t)combOpFlags);
}

int32_t StreamOpFlag::toCharacteristics(int32_t streamFlags) {
	$init(StreamOpFlag);
	return (int32_t)(streamFlags & (uint32_t)StreamOpFlag::SPLITERATOR_CHARACTERISTICS_MASK);
}

int32_t StreamOpFlag::fromCharacteristics($Spliterator* spliterator) {
	$init(StreamOpFlag);
	int32_t characteristics = $nc(spliterator)->characteristics();
	if (((int32_t)(characteristics & (uint32_t)$Spliterator::SORTED)) != 0 && spliterator->getComparator() != nullptr) {
		return (int32_t)(((int32_t)(characteristics & (uint32_t)StreamOpFlag::SPLITERATOR_CHARACTERISTICS_MASK)) & (uint32_t)~$Spliterator::SORTED);
	} else {
		return (int32_t)(characteristics & (uint32_t)StreamOpFlag::SPLITERATOR_CHARACTERISTICS_MASK);
	}
}

int32_t StreamOpFlag::fromCharacteristics(int32_t characteristics) {
	$init(StreamOpFlag);
	return (int32_t)(characteristics & (uint32_t)StreamOpFlag::SPLITERATOR_CHARACTERISTICS_MASK);
}

void clinit$StreamOpFlag($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$init($StreamOpFlag$Type);
	$assignStatic(StreamOpFlag::DISTINCT, $new(StreamOpFlag, "DISTINCT"_s, 0, 0, $($nc($($nc($(StreamOpFlag::set($StreamOpFlag$Type::SPLITERATOR)))->set($StreamOpFlag$Type::STREAM)))->setAndClear($StreamOpFlag$Type::OP))));
	$assignStatic(StreamOpFlag::SORTED, $new(StreamOpFlag, "SORTED"_s, 1, 1, $($nc($($nc($(StreamOpFlag::set($StreamOpFlag$Type::SPLITERATOR)))->set($StreamOpFlag$Type::STREAM)))->setAndClear($StreamOpFlag$Type::OP))));
	$assignStatic(StreamOpFlag::ORDERED, $new(StreamOpFlag, "ORDERED"_s, 2, 2, $($nc($($nc($($nc($($nc($(StreamOpFlag::set($StreamOpFlag$Type::SPLITERATOR)))->set($StreamOpFlag$Type::STREAM)))->setAndClear($StreamOpFlag$Type::OP)))->clear($StreamOpFlag$Type::TERMINAL_OP)))->clear($StreamOpFlag$Type::UPSTREAM_TERMINAL_OP))));
	$assignStatic(StreamOpFlag::SIZED, $new(StreamOpFlag, "SIZED"_s, 3, 3, $($nc($($nc($(StreamOpFlag::set($StreamOpFlag$Type::SPLITERATOR)))->set($StreamOpFlag$Type::STREAM)))->clear($StreamOpFlag$Type::OP))));
	$assignStatic(StreamOpFlag::SHORT_CIRCUIT, $new(StreamOpFlag, "SHORT_CIRCUIT"_s, 4, 12, $($nc($(StreamOpFlag::set($StreamOpFlag$Type::OP)))->set($StreamOpFlag$Type::TERMINAL_OP))));
	$assignStatic(StreamOpFlag::SIZE_ADJUSTING, $new(StreamOpFlag, "SIZE_ADJUSTING"_s, 5, 13, $(StreamOpFlag::set($StreamOpFlag$Type::OP))));
	$assignStatic(StreamOpFlag::$VALUES, StreamOpFlag::$values());
	StreamOpFlag::SPLITERATOR_CHARACTERISTICS_MASK = StreamOpFlag::createMask($StreamOpFlag$Type::SPLITERATOR);
	StreamOpFlag::STREAM_MASK = StreamOpFlag::createMask($StreamOpFlag$Type::STREAM);
	StreamOpFlag::OP_MASK = StreamOpFlag::createMask($StreamOpFlag$Type::OP);
	StreamOpFlag::TERMINAL_OP_MASK = StreamOpFlag::createMask($StreamOpFlag$Type::TERMINAL_OP);
	StreamOpFlag::UPSTREAM_TERMINAL_OP_MASK = StreamOpFlag::createMask($StreamOpFlag$Type::UPSTREAM_TERMINAL_OP);
	StreamOpFlag::FLAG_MASK = StreamOpFlag::createFlagMask();
	StreamOpFlag::FLAG_MASK_IS = StreamOpFlag::STREAM_MASK;
	StreamOpFlag::FLAG_MASK_NOT = StreamOpFlag::STREAM_MASK << 1;
	StreamOpFlag::INITIAL_OPS_VALUE = StreamOpFlag::FLAG_MASK_IS | StreamOpFlag::FLAG_MASK_NOT;
	StreamOpFlag::IS_DISTINCT = StreamOpFlag::DISTINCT->set$;
	StreamOpFlag::NOT_DISTINCT = StreamOpFlag::DISTINCT->clear$;
	StreamOpFlag::IS_SORTED = StreamOpFlag::SORTED->set$;
	StreamOpFlag::NOT_SORTED = StreamOpFlag::SORTED->clear$;
	StreamOpFlag::IS_ORDERED = StreamOpFlag::ORDERED->set$;
	StreamOpFlag::NOT_ORDERED = StreamOpFlag::ORDERED->clear$;
	StreamOpFlag::IS_SIZED = StreamOpFlag::SIZED->set$;
	StreamOpFlag::NOT_SIZED = StreamOpFlag::SIZED->clear$;
	StreamOpFlag::IS_SHORT_CIRCUIT = StreamOpFlag::SHORT_CIRCUIT->set$;
	StreamOpFlag::IS_SIZE_ADJUSTING = StreamOpFlag::SIZE_ADJUSTING->set$;
}

StreamOpFlag::StreamOpFlag() {
}

$Class* StreamOpFlag::load$($String* name, bool initialize) {
	$loadClass(StreamOpFlag, name, initialize, &_StreamOpFlag_ClassInfo_, clinit$StreamOpFlag, allocate$StreamOpFlag);
	return class$;
}

$Class* StreamOpFlag::class$ = nullptr;

		} // stream
	} // util
} // java