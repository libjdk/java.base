#include <jdk/internal/icu/util/CodePointTrie.h>

#include <java/io/DataOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <java/io/UncheckedIOException.h>
#include <java/lang/AssertionError.h>
#include <java/lang/InternalError.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/ByteOrder.h>
#include <jdk/internal/icu/impl/ICUBinary.h>
#include <jdk/internal/icu/util/CodePointMap$Range.h>
#include <jdk/internal/icu/util/CodePointMap$ValueFilter.h>
#include <jdk/internal/icu/util/CodePointMap.h>
#include <jdk/internal/icu/util/CodePointTrie$1.h>
#include <jdk/internal/icu/util/CodePointTrie$Data.h>
#include <jdk/internal/icu/util/CodePointTrie$Fast16.h>
#include <jdk/internal/icu/util/CodePointTrie$Fast32.h>
#include <jdk/internal/icu/util/CodePointTrie$Fast8.h>
#include <jdk/internal/icu/util/CodePointTrie$Small16.h>
#include <jdk/internal/icu/util/CodePointTrie$Small32.h>
#include <jdk/internal/icu/util/CodePointTrie$Small8.h>
#include <jdk/internal/icu/util/CodePointTrie$Type.h>
#include <jdk/internal/icu/util/CodePointTrie$ValueWidth.h>
#include <jcpp.h>

#undef ASCII_LIMIT
#undef BIG_ENDIAN
#undef BITS_16
#undef BITS_32
#undef BITS_8
#undef BMP_INDEX_LENGTH
#undef CP_PER_INDEX_2_ENTRY
#undef ERROR_VALUE_NEG_DATA_OFFSET
#undef FAST
#undef FAST_DATA_BLOCK_LENGTH
#undef FAST_DATA_MASK
#undef FAST_SHIFT
#undef HIGH_VALUE_NEG_DATA_OFFSET
#undef INDEX_2_BLOCK_LENGTH
#undef INDEX_2_MASK
#undef INDEX_3_BLOCK_LENGTH
#undef INDEX_3_MASK
#undef LITTLE_ENDIAN
#undef MAX_UNICODE
#undef NO_DATA_NULL_OFFSET
#undef NO_INDEX3_NULL_OFFSET
#undef OMITTED_BMP_INDEX_1_LENGTH
#undef OPTIONS_DATA_LENGTH_MASK
#undef OPTIONS_DATA_NULL_OFFSET_MASK
#undef OPTIONS_RESERVED_MASK
#undef OPTIONS_VALUE_BITS_MASK
#undef SHIFT_1
#undef SHIFT_1_2
#undef SHIFT_2
#undef SHIFT_2_3
#undef SHIFT_3
#undef SMALL
#undef SMALL_DATA_BLOCK_LENGTH
#undef SMALL_DATA_MASK
#undef SMALL_INDEX_LENGTH
#undef SMALL_LIMIT
#undef SMALL_MAX

using $DataOutputStream = ::java::io::DataOutputStream;
using $IOException = ::java::io::IOException;
using $OutputStream = ::java::io::OutputStream;
using $UncheckedIOException = ::java::io::UncheckedIOException;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $ByteOrder = ::java::nio::ByteOrder;
using $ICUBinary = ::jdk::internal::icu::impl::ICUBinary;
using $CodePointMap = ::jdk::internal::icu::util::CodePointMap;
using $CodePointMap$Range = ::jdk::internal::icu::util::CodePointMap$Range;
using $CodePointMap$ValueFilter = ::jdk::internal::icu::util::CodePointMap$ValueFilter;
using $CodePointTrie$1 = ::jdk::internal::icu::util::CodePointTrie$1;
using $CodePointTrie$Data = ::jdk::internal::icu::util::CodePointTrie$Data;
using $CodePointTrie$Fast16 = ::jdk::internal::icu::util::CodePointTrie$Fast16;
using $CodePointTrie$Fast32 = ::jdk::internal::icu::util::CodePointTrie$Fast32;
using $CodePointTrie$Fast8 = ::jdk::internal::icu::util::CodePointTrie$Fast8;
using $CodePointTrie$Small16 = ::jdk::internal::icu::util::CodePointTrie$Small16;
using $CodePointTrie$Small32 = ::jdk::internal::icu::util::CodePointTrie$Small32;
using $CodePointTrie$Small8 = ::jdk::internal::icu::util::CodePointTrie$Small8;
using $CodePointTrie$Type = ::jdk::internal::icu::util::CodePointTrie$Type;
using $CodePointTrie$ValueWidth = ::jdk::internal::icu::util::CodePointTrie$ValueWidth;

namespace jdk {
	namespace internal {
		namespace icu {
			namespace util {

$CompoundAttribute _CodePointTrie_FieldAnnotations_data[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _CodePointTrie_FieldAnnotations_dataLength[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _CodePointTrie_FieldAnnotations_highStart[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _CodePointTrie_MethodAnnotations_cpIndex2[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _CodePointTrie_MethodAnnotations_fastIndex3[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _CodePointTrie_MethodAnnotations_smallIndex11[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _CodePointTrie_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(CodePointTrie, $assertionsDisabled)},
	{"MAX_UNICODE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CodePointTrie, MAX_UNICODE)},
	{"ASCII_LIMIT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CodePointTrie, ASCII_LIMIT)},
	{"FAST_SHIFT", "I", nullptr, $STATIC | $FINAL, $constField(CodePointTrie, FAST_SHIFT)},
	{"FAST_DATA_BLOCK_LENGTH", "I", nullptr, $STATIC | $FINAL, $constField(CodePointTrie, FAST_DATA_BLOCK_LENGTH)},
	{"FAST_DATA_MASK", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CodePointTrie, FAST_DATA_MASK)},
	{"SMALL_MAX", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CodePointTrie, SMALL_MAX)},
	{"ERROR_VALUE_NEG_DATA_OFFSET", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CodePointTrie, ERROR_VALUE_NEG_DATA_OFFSET)},
	{"HIGH_VALUE_NEG_DATA_OFFSET", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CodePointTrie, HIGH_VALUE_NEG_DATA_OFFSET)},
	{"BMP_INDEX_LENGTH", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CodePointTrie, BMP_INDEX_LENGTH)},
	{"SMALL_LIMIT", "I", nullptr, $STATIC | $FINAL, $constField(CodePointTrie, SMALL_LIMIT)},
	{"SMALL_INDEX_LENGTH", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CodePointTrie, SMALL_INDEX_LENGTH)},
	{"SHIFT_3", "I", nullptr, $STATIC | $FINAL, $constField(CodePointTrie, SHIFT_3)},
	{"SHIFT_2", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CodePointTrie, SHIFT_2)},
	{"SHIFT_1", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CodePointTrie, SHIFT_1)},
	{"SHIFT_2_3", "I", nullptr, $STATIC | $FINAL, $constField(CodePointTrie, SHIFT_2_3)},
	{"SHIFT_1_2", "I", nullptr, $STATIC | $FINAL, $constField(CodePointTrie, SHIFT_1_2)},
	{"OMITTED_BMP_INDEX_1_LENGTH", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CodePointTrie, OMITTED_BMP_INDEX_1_LENGTH)},
	{"INDEX_2_BLOCK_LENGTH", "I", nullptr, $STATIC | $FINAL, $constField(CodePointTrie, INDEX_2_BLOCK_LENGTH)},
	{"INDEX_2_MASK", "I", nullptr, $STATIC | $FINAL, $constField(CodePointTrie, INDEX_2_MASK)},
	{"CP_PER_INDEX_2_ENTRY", "I", nullptr, $STATIC | $FINAL, $constField(CodePointTrie, CP_PER_INDEX_2_ENTRY)},
	{"INDEX_3_BLOCK_LENGTH", "I", nullptr, $STATIC | $FINAL, $constField(CodePointTrie, INDEX_3_BLOCK_LENGTH)},
	{"INDEX_3_MASK", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CodePointTrie, INDEX_3_MASK)},
	{"SMALL_DATA_BLOCK_LENGTH", "I", nullptr, $STATIC | $FINAL, $constField(CodePointTrie, SMALL_DATA_BLOCK_LENGTH)},
	{"SMALL_DATA_MASK", "I", nullptr, $STATIC | $FINAL, $constField(CodePointTrie, SMALL_DATA_MASK)},
	{"OPTIONS_DATA_LENGTH_MASK", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CodePointTrie, OPTIONS_DATA_LENGTH_MASK)},
	{"OPTIONS_DATA_NULL_OFFSET_MASK", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CodePointTrie, OPTIONS_DATA_NULL_OFFSET_MASK)},
	{"OPTIONS_RESERVED_MASK", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CodePointTrie, OPTIONS_RESERVED_MASK)},
	{"OPTIONS_VALUE_BITS_MASK", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CodePointTrie, OPTIONS_VALUE_BITS_MASK)},
	{"NO_INDEX3_NULL_OFFSET", "I", nullptr, $STATIC | $FINAL, $constField(CodePointTrie, NO_INDEX3_NULL_OFFSET)},
	{"NO_DATA_NULL_OFFSET", "I", nullptr, $STATIC | $FINAL, $constField(CodePointTrie, NO_DATA_NULL_OFFSET)},
	{"ascii", "[I", nullptr, $PRIVATE | $FINAL, $field(CodePointTrie, ascii)},
	{"index", "[C", nullptr, $PRIVATE | $FINAL, $field(CodePointTrie, index)},
	{"data", "Ljdk/internal/icu/util/CodePointTrie$Data;", nullptr, $PROTECTED | $FINAL | $DEPRECATED, $field(CodePointTrie, data), _CodePointTrie_FieldAnnotations_data},
	{"dataLength", "I", nullptr, $PROTECTED | $FINAL | $DEPRECATED, $field(CodePointTrie, dataLength), _CodePointTrie_FieldAnnotations_dataLength},
	{"highStart", "I", nullptr, $PROTECTED | $FINAL | $DEPRECATED, $field(CodePointTrie, highStart), _CodePointTrie_FieldAnnotations_highStart},
	{"index3NullOffset", "I", nullptr, $PRIVATE | $FINAL, $field(CodePointTrie, index3NullOffset)},
	{"dataNullOffset", "I", nullptr, $PRIVATE | $FINAL, $field(CodePointTrie, dataNullOffset)},
	{"nullValue", "I", nullptr, $PRIVATE | $FINAL, $field(CodePointTrie, nullValue)},
	{}
};

$MethodInfo _CodePointTrie_MethodInfo_[] = {
	{"<init>", "([CLjdk/internal/icu/util/CodePointTrie$Data;III)V", nullptr, $PRIVATE, $method(CodePointTrie, init$, void, $chars*, $CodePointTrie$Data*, int32_t, int32_t, int32_t)},
	{"asciiGet", "(I)I", nullptr, $PUBLIC | $FINAL, $method(CodePointTrie, asciiGet, int32_t, int32_t)},
	{"cpIndex", "(I)I", nullptr, $PROTECTED | $ABSTRACT | $DEPRECATED, $virtualMethod(CodePointTrie, cpIndex, int32_t, int32_t), nullptr, nullptr, _CodePointTrie_MethodAnnotations_cpIndex2},
	{"fastIndex", "(I)I", nullptr, $PROTECTED | $FINAL | $DEPRECATED, $method(CodePointTrie, fastIndex, int32_t, int32_t), nullptr, nullptr, _CodePointTrie_MethodAnnotations_fastIndex3},
	{"fromBinary", "(Ljdk/internal/icu/util/CodePointTrie$Type;Ljdk/internal/icu/util/CodePointTrie$ValueWidth;Ljava/nio/ByteBuffer;)Ljdk/internal/icu/util/CodePointTrie;", nullptr, $PUBLIC | $STATIC, $staticMethod(CodePointTrie, fromBinary, CodePointTrie*, $CodePointTrie$Type*, $CodePointTrie$ValueWidth*, $ByteBuffer*)},
	{"get", "(I)I", nullptr, $PUBLIC, $virtualMethod(CodePointTrie, get, int32_t, int32_t)},
	{"getRange", "(ILjdk/internal/icu/util/CodePointMap$ValueFilter;Ljdk/internal/icu/util/CodePointMap$Range;)Z", nullptr, $PUBLIC | $FINAL, $virtualMethod(CodePointTrie, getRange, bool, int32_t, $CodePointMap$ValueFilter*, $CodePointMap$Range*)},
	{"getType", "()Ljdk/internal/icu/util/CodePointTrie$Type;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(CodePointTrie, getType, $CodePointTrie$Type*)},
	{"getValueWidth", "()Ljdk/internal/icu/util/CodePointTrie$ValueWidth;", nullptr, $PUBLIC | $FINAL, $method(CodePointTrie, getValueWidth, $CodePointTrie$ValueWidth*)},
	{"internalSmallIndex", "(Ljdk/internal/icu/util/CodePointTrie$Type;I)I", nullptr, $PRIVATE | $FINAL, $method(CodePointTrie, internalSmallIndex, int32_t, $CodePointTrie$Type*, int32_t)},
	{"maybeFilterValue", "(IIILjdk/internal/icu/util/CodePointMap$ValueFilter;)I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticMethod(CodePointTrie, maybeFilterValue, int32_t, int32_t, int32_t, int32_t, $CodePointMap$ValueFilter*)},
	{"smallIndex", "(Ljdk/internal/icu/util/CodePointTrie$Type;I)I", nullptr, $PROTECTED | $FINAL | $DEPRECATED, $method(CodePointTrie, smallIndex, int32_t, $CodePointTrie$Type*, int32_t), nullptr, nullptr, _CodePointTrie_MethodAnnotations_smallIndex11},
	{"toBinary", "(Ljava/io/OutputStream;)I", nullptr, $PUBLIC | $FINAL, $method(CodePointTrie, toBinary, int32_t, $OutputStream*)},
	{}
};

$InnerClassInfo _CodePointTrie_InnerClassesInfo_[] = {
	{"jdk.internal.icu.util.CodePointTrie$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{"jdk.internal.icu.util.CodePointTrie$Small8", "jdk.internal.icu.util.CodePointTrie", "Small8", $PUBLIC | $STATIC | $FINAL},
	{"jdk.internal.icu.util.CodePointTrie$Small32", "jdk.internal.icu.util.CodePointTrie", "Small32", $PUBLIC | $STATIC | $FINAL},
	{"jdk.internal.icu.util.CodePointTrie$Small16", "jdk.internal.icu.util.CodePointTrie", "Small16", $PUBLIC | $STATIC | $FINAL},
	{"jdk.internal.icu.util.CodePointTrie$Fast8", "jdk.internal.icu.util.CodePointTrie", "Fast8", $PUBLIC | $STATIC | $FINAL},
	{"jdk.internal.icu.util.CodePointTrie$Fast32", "jdk.internal.icu.util.CodePointTrie", "Fast32", $PUBLIC | $STATIC | $FINAL},
	{"jdk.internal.icu.util.CodePointTrie$Fast16", "jdk.internal.icu.util.CodePointTrie", "Fast16", $PUBLIC | $STATIC | $FINAL},
	{"jdk.internal.icu.util.CodePointTrie$Small", "jdk.internal.icu.util.CodePointTrie", "Small", $PUBLIC | $STATIC | $ABSTRACT},
	{"jdk.internal.icu.util.CodePointTrie$Fast", "jdk.internal.icu.util.CodePointTrie", "Fast", $PUBLIC | $STATIC | $ABSTRACT},
	{"jdk.internal.icu.util.CodePointTrie$Data8", "jdk.internal.icu.util.CodePointTrie", "Data8", $PRIVATE | $STATIC | $FINAL},
	{"jdk.internal.icu.util.CodePointTrie$Data32", "jdk.internal.icu.util.CodePointTrie", "Data32", $PRIVATE | $STATIC | $FINAL},
	{"jdk.internal.icu.util.CodePointTrie$Data16", "jdk.internal.icu.util.CodePointTrie", "Data16", $PRIVATE | $STATIC | $FINAL},
	{"jdk.internal.icu.util.CodePointTrie$Data", "jdk.internal.icu.util.CodePointTrie", "Data", $PRIVATE | $STATIC | $ABSTRACT},
	{"jdk.internal.icu.util.CodePointTrie$ValueWidth", "jdk.internal.icu.util.CodePointTrie", "ValueWidth", $PUBLIC | $STATIC | $FINAL | $ENUM},
	{"jdk.internal.icu.util.CodePointTrie$Type", "jdk.internal.icu.util.CodePointTrie", "Type", $PUBLIC | $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _CodePointTrie_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"jdk.internal.icu.util.CodePointTrie",
	"jdk.internal.icu.util.CodePointMap",
	nullptr,
	_CodePointTrie_FieldInfo_,
	_CodePointTrie_MethodInfo_,
	nullptr,
	nullptr,
	_CodePointTrie_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.icu.util.CodePointTrie$1,jdk.internal.icu.util.CodePointTrie$Small8,jdk.internal.icu.util.CodePointTrie$Small32,jdk.internal.icu.util.CodePointTrie$Small16,jdk.internal.icu.util.CodePointTrie$Fast8,jdk.internal.icu.util.CodePointTrie$Fast32,jdk.internal.icu.util.CodePointTrie$Fast16,jdk.internal.icu.util.CodePointTrie$Small,jdk.internal.icu.util.CodePointTrie$Small$SmallStringIterator,jdk.internal.icu.util.CodePointTrie$Fast,jdk.internal.icu.util.CodePointTrie$Fast$FastStringIterator,jdk.internal.icu.util.CodePointTrie$Data8,jdk.internal.icu.util.CodePointTrie$Data32,jdk.internal.icu.util.CodePointTrie$Data16,jdk.internal.icu.util.CodePointTrie$Data,jdk.internal.icu.util.CodePointTrie$ValueWidth,jdk.internal.icu.util.CodePointTrie$Type"
};

$Object* allocate$CodePointTrie($Class* clazz) {
	return $of($alloc(CodePointTrie));
}

bool CodePointTrie::$assertionsDisabled = false;

void CodePointTrie::init$($chars* index, $CodePointTrie$Data* data, int32_t highStart, int32_t index3NullOffset, int32_t dataNullOffset) {
	$CodePointMap::init$();
	$set(this, ascii, $new($ints, CodePointTrie::ASCII_LIMIT));
	$set(this, index, index);
	$set(this, data, data);
	this->dataLength = $nc(data)->getDataLength();
	this->highStart = highStart;
	this->index3NullOffset = index3NullOffset;
	this->dataNullOffset = dataNullOffset;
	for (int32_t c = 0; c < CodePointTrie::ASCII_LIMIT; ++c) {
		$nc(this->ascii)->set(c, data->getFromIndex(c));
	}
	int32_t nullValueOffset = dataNullOffset;
	if (nullValueOffset >= this->dataLength) {
		nullValueOffset = this->dataLength - CodePointTrie::HIGH_VALUE_NEG_DATA_OFFSET;
	}
	this->nullValue = data->getFromIndex(nullValueOffset);
}

CodePointTrie* CodePointTrie::fromBinary($CodePointTrie$Type* type$renamed, $CodePointTrie$ValueWidth* valueWidth$renamed, $ByteBuffer* bytes) {
	$init(CodePointTrie);
	$useLocalCurrentObjectStackCache();
	$var($CodePointTrie$ValueWidth, valueWidth, valueWidth$renamed);
	$var($CodePointTrie$Type, type, type$renamed);
	$var($ByteOrder, outerByteOrder, $nc(bytes)->order());
	{
		$var($Throwable, var$0, nullptr);
		$var(CodePointTrie, var$2, nullptr);
		bool return$1 = false;
		try {
			if (bytes->remaining() < 16) {
				$throwNew($InternalError, "Buffer too short for a CodePointTrie header"_s);
			}
			int32_t signature = bytes->getInt();
			{
				bool isBigEndian = false;
				switch (signature) {
				case 0x54726933:
					{
						break;
					}
				case 0x33697254:
					{
						$init($ByteOrder);
						isBigEndian = outerByteOrder == $ByteOrder::BIG_ENDIAN;
						bytes->order(isBigEndian ? $ByteOrder::LITTLE_ENDIAN : $ByteOrder::BIG_ENDIAN);
						signature = 0x54726933;
						break;
					}
				default:
					{
						$throwNew($InternalError, "Buffer does not contain a serialized CodePointTrie"_s);
					}
				}
			}
			int32_t options = bytes->getChar();
			int32_t indexLength = bytes->getChar();
			int32_t dataLength = bytes->getChar();
			int32_t index3NullOffset = bytes->getChar();
			int32_t dataNullOffset = bytes->getChar();
			int32_t shiftedHighStart = bytes->getChar();
			int32_t typeInt = (int32_t)((options >> 6) & (uint32_t)3);
			$CodePointTrie$Type* actualType = nullptr;
			switch (typeInt) {
			case 0:
				{
					$init($CodePointTrie$Type);
					actualType = $CodePointTrie$Type::FAST;
					break;
				}
			case 1:
				{
					$init($CodePointTrie$Type);
					actualType = $CodePointTrie$Type::SMALL;
					break;
				}
			default:
				{
					$throwNew($InternalError, "CodePointTrie data header has an unsupported type"_s);
				}
			}
			int32_t valueWidthInt = (int32_t)(options & (uint32_t)CodePointTrie::OPTIONS_VALUE_BITS_MASK);
			$CodePointTrie$ValueWidth* actualValueWidth = nullptr;
			switch (valueWidthInt) {
			case 0:
				{
					$init($CodePointTrie$ValueWidth);
					actualValueWidth = $CodePointTrie$ValueWidth::BITS_16;
					break;
				}
			case 1:
				{
					$init($CodePointTrie$ValueWidth);
					actualValueWidth = $CodePointTrie$ValueWidth::BITS_32;
					break;
				}
			case 2:
				{
					$init($CodePointTrie$ValueWidth);
					actualValueWidth = $CodePointTrie$ValueWidth::BITS_8;
					break;
				}
			default:
				{
					$throwNew($InternalError, "CodePointTrie data header has an unsupported value width"_s);
				}
			}
			if (((int32_t)(options & (uint32_t)CodePointTrie::OPTIONS_RESERVED_MASK)) != 0) {
				$throwNew($InternalError, "CodePointTrie data header has unsupported options"_s);
			}
			if (type == nullptr) {
				type = actualType;
			}
			if (valueWidth == nullptr) {
				valueWidth = actualValueWidth;
			}
			if (type != actualType || valueWidth != actualValueWidth) {
				$throwNew($InternalError, "CodePointTrie data header has a different type or value width than required"_s);
			}
			dataLength |= (((int32_t)(options & (uint32_t)CodePointTrie::OPTIONS_DATA_LENGTH_MASK)) << 4);
			dataNullOffset |= (((int32_t)(options & (uint32_t)CodePointTrie::OPTIONS_DATA_NULL_OFFSET_MASK)) << 8);
			int32_t highStart = $sl(shiftedHighStart, CodePointTrie::SHIFT_2);
			int32_t actualLength = indexLength * 2;
			$init($CodePointTrie$ValueWidth);
			if (valueWidth == $CodePointTrie$ValueWidth::BITS_16) {
				actualLength += dataLength * 2;
			} else {
				if (valueWidth == $CodePointTrie$ValueWidth::BITS_32) {
					actualLength += dataLength * 4;
				} else {
					actualLength += dataLength;
				}
			}
			if (bytes->remaining() < actualLength) {
				$throwNew($InternalError, "Buffer too short for the CodePointTrie data"_s);
			}
			$var($chars, index, $ICUBinary::getChars(bytes, indexLength, 0));
			$init($CodePointTrie$1);
			switch ($nc($CodePointTrie$1::$SwitchMap$jdk$internal$icu$util$CodePointTrie$ValueWidth)->get($nc((valueWidth))->ordinal())) {
			case 1:
				{
					{
						$var($chars, data16, $ICUBinary::getChars(bytes, dataLength, 0));
						$init($CodePointTrie$Type);
						$assign(var$2, type == $CodePointTrie$Type::FAST ? static_cast<CodePointTrie*>($new($CodePointTrie$Fast16, index, data16, highStart, index3NullOffset, dataNullOffset)) : static_cast<CodePointTrie*>($new($CodePointTrie$Small16, index, data16, highStart, index3NullOffset, dataNullOffset)));
						return$1 = true;
						goto $finally;
					}
				}
			case 2:
				{
					{
						$var($ints, data32, $ICUBinary::getInts(bytes, dataLength, 0));
						$init($CodePointTrie$Type);
						$assign(var$2, type == $CodePointTrie$Type::FAST ? static_cast<CodePointTrie*>($new($CodePointTrie$Fast32, index, data32, highStart, index3NullOffset, dataNullOffset)) : static_cast<CodePointTrie*>($new($CodePointTrie$Small32, index, data32, highStart, index3NullOffset, dataNullOffset)));
						return$1 = true;
						goto $finally;
					}
				}
			case 3:
				{
					{
						$var($bytes, data8, $ICUBinary::getBytes(bytes, dataLength, 0));
						$init($CodePointTrie$Type);
						$assign(var$2, type == $CodePointTrie$Type::FAST ? static_cast<CodePointTrie*>($new($CodePointTrie$Fast8, index, data8, highStart, index3NullOffset, dataNullOffset)) : static_cast<CodePointTrie*>($new($CodePointTrie$Small8, index, data8, highStart, index3NullOffset, dataNullOffset)));
						return$1 = true;
						goto $finally;
					}
				}
			default:
				{
					$throwNew($AssertionError, $of("should be unreachable"_s));
				}
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			bytes->order(outerByteOrder);
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

$CodePointTrie$ValueWidth* CodePointTrie::getValueWidth() {
	return $nc(this->data)->getValueWidth();
}

int32_t CodePointTrie::get(int32_t c) {
	return $nc(this->data)->getFromIndex(cpIndex(c));
}

int32_t CodePointTrie::asciiGet(int32_t c) {
	return $nc(this->ascii)->get(c);
}

int32_t CodePointTrie::maybeFilterValue(int32_t value, int32_t trieNullValue, int32_t nullValue, $CodePointMap$ValueFilter* filter) {
	$init(CodePointTrie);
	if (value == trieNullValue) {
		value = nullValue;
	} else if (filter != nullptr) {
		value = filter->apply(value);
	}
	return value;
}

bool CodePointTrie::getRange(int32_t start, $CodePointMap$ValueFilter* filter, $CodePointMap$Range* range) {
	if (start < 0 || CodePointTrie::MAX_UNICODE < start) {
		return false;
	}
	if (start >= this->highStart) {
		int32_t di = this->dataLength - CodePointTrie::HIGH_VALUE_NEG_DATA_OFFSET;
		int32_t value = $nc(this->data)->getFromIndex(di);
		if (filter != nullptr) {
			value = filter->apply(value);
		}
		$nc(range)->set(start, CodePointTrie::MAX_UNICODE, value);
		return true;
	}
	int32_t nullValue = this->nullValue;
	if (filter != nullptr) {
		nullValue = filter->apply(nullValue);
	}
	$CodePointTrie$Type* type = getType();
	int32_t prevI3Block = -1;
	int32_t prevBlock = -1;
	int32_t c = start;
	int32_t trieValue = 0;
	int32_t value = 0;
	bool haveValue = false;
	do {
		int32_t i3Block = 0;
		int32_t i3 = 0;
		int32_t i3BlockLength = 0;
		int32_t dataBlockLength = 0;
		$init($CodePointTrie$Type);
		if (c <= 0x0000FFFF && (type == $CodePointTrie$Type::FAST || c <= CodePointTrie::SMALL_MAX)) {
			i3Block = 0;
			i3 = $sr(c, CodePointTrie::FAST_SHIFT);
			i3BlockLength = type == $CodePointTrie$Type::FAST ? CodePointTrie::BMP_INDEX_LENGTH : CodePointTrie::SMALL_INDEX_LENGTH;
			dataBlockLength = CodePointTrie::FAST_DATA_BLOCK_LENGTH;
		} else {
			int32_t i1 = $sr(c, CodePointTrie::SHIFT_1);
			if (type == $CodePointTrie$Type::FAST) {
				if (!CodePointTrie::$assertionsDisabled && !(0x0000FFFF < c && c < this->highStart)) {
					$throwNew($AssertionError);
				}
				i1 += CodePointTrie::BMP_INDEX_LENGTH - CodePointTrie::OMITTED_BMP_INDEX_1_LENGTH;
			} else {
				if (!CodePointTrie::$assertionsDisabled && !(c < this->highStart && this->highStart > CodePointTrie::SMALL_LIMIT)) {
					$throwNew($AssertionError);
				}
				i1 += CodePointTrie::SMALL_INDEX_LENGTH;
			}
			i3Block = $nc(this->index)->get($nc(this->index)->get(i1) + ((int32_t)(($sr(c, CodePointTrie::SHIFT_2)) & (uint32_t)CodePointTrie::INDEX_2_MASK)));
			if (i3Block == prevI3Block && (c - start) >= CodePointTrie::CP_PER_INDEX_2_ENTRY) {
				if (!CodePointTrie::$assertionsDisabled && !(((int32_t)(c & (uint32_t)(CodePointTrie::CP_PER_INDEX_2_ENTRY - 1))) == 0)) {
					$throwNew($AssertionError);
				}
				c += CodePointTrie::CP_PER_INDEX_2_ENTRY;
				continue;
			}
			prevI3Block = i3Block;
			if (i3Block == this->index3NullOffset) {
				if (haveValue) {
					if (nullValue != value) {
						$nc(range)->set(start, c - 1, value);
						return true;
					}
				} else {
					trieValue = this->nullValue;
					value = nullValue;
					haveValue = true;
				}
				prevBlock = this->dataNullOffset;
				c = (int32_t)((c + CodePointTrie::CP_PER_INDEX_2_ENTRY) & (uint32_t)~(CodePointTrie::CP_PER_INDEX_2_ENTRY - 1));
				continue;
			}
			i3 = (int32_t)(($sr(c, CodePointTrie::SHIFT_3)) & (uint32_t)CodePointTrie::INDEX_3_MASK);
			i3BlockLength = CodePointTrie::INDEX_3_BLOCK_LENGTH;
			dataBlockLength = CodePointTrie::SMALL_DATA_BLOCK_LENGTH;
		}
		do {
			int32_t block = 0;
			if (((int32_t)(i3Block & (uint32_t)32768)) == 0) {
				block = $nc(this->index)->get(i3Block + i3);
			} else {
				int32_t group = ((int32_t)(i3Block & (uint32_t)32767)) + ((int32_t)(i3 & (uint32_t)~7)) + (i3 >> 3);
				int32_t gi = (int32_t)(i3 & (uint32_t)7);
				block = (int32_t)(($sl((int32_t)$nc(this->index)->get(group++), 2 + (2 * gi))) & (uint32_t)0x00030000);
				block |= $nc(this->index)->get(group + gi);
			}
			if (block == prevBlock && (c - start) >= dataBlockLength) {
				if (!CodePointTrie::$assertionsDisabled && !(((int32_t)(c & (uint32_t)(dataBlockLength - 1))) == 0)) {
					$throwNew($AssertionError);
				}
				c += dataBlockLength;
			} else {
				int32_t dataMask = dataBlockLength - 1;
				prevBlock = block;
				if (block == this->dataNullOffset) {
					if (haveValue) {
						if (nullValue != value) {
							$nc(range)->set(start, c - 1, value);
							return true;
						}
					} else {
						trieValue = this->nullValue;
						value = nullValue;
						haveValue = true;
					}
					c = (int32_t)((c + dataBlockLength) & (uint32_t)~dataMask);
				} else {
					int32_t di = block + ((int32_t)(c & (uint32_t)dataMask));
					int32_t trieValue2 = $nc(this->data)->getFromIndex(di);
					if (haveValue) {
						if (trieValue2 != trieValue) {
							if (filter == nullptr || maybeFilterValue(trieValue2, this->nullValue, nullValue, filter) != value) {
								$nc(range)->set(start, c - 1, value);
								return true;
							}
							trieValue = trieValue2;
						}
					} else {
						trieValue = trieValue2;
						value = maybeFilterValue(trieValue2, this->nullValue, nullValue, filter);
						haveValue = true;
					}
					while (((int32_t)(++c & (uint32_t)dataMask)) != 0) {
						trieValue2 = $nc(this->data)->getFromIndex(++di);
						if (trieValue2 != trieValue) {
							if (filter == nullptr || maybeFilterValue(trieValue2, this->nullValue, nullValue, filter) != value) {
								$nc(range)->set(start, c - 1, value);
								return true;
							}
							trieValue = trieValue2;
						}
					}
				}
			}
		} while (++i3 < i3BlockLength);
	} while (c < this->highStart);
	if (!CodePointTrie::$assertionsDisabled && !(haveValue)) {
		$throwNew($AssertionError);
	}
	int32_t di = this->dataLength - CodePointTrie::HIGH_VALUE_NEG_DATA_OFFSET;
	int32_t highValue = $nc(this->data)->getFromIndex(di);
	if (maybeFilterValue(highValue, this->nullValue, nullValue, filter) != value) {
		--c;
	} else {
		c = CodePointTrie::MAX_UNICODE;
	}
	$nc(range)->set(start, c, value);
	return true;
}

int32_t CodePointTrie::toBinary($OutputStream* os) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($DataOutputStream, dos, $new($DataOutputStream, os));
		dos->writeInt(0x54726933);
		int32_t var$0 = ((((int32_t)(this->dataLength & (uint32_t)0x000F0000)) >> 4) | (((int32_t)(this->dataNullOffset & (uint32_t)0x000F0000)) >> 8)) | ($nc($(getType()))->ordinal() << 6);
		dos->writeChar(var$0 | $nc($(getValueWidth()))->ordinal());
		dos->writeChar($nc(this->index)->length);
		dos->writeChar(this->dataLength);
		dos->writeChar(this->index3NullOffset);
		dos->writeChar(this->dataNullOffset);
		dos->writeChar($sr(this->highStart, CodePointTrie::SHIFT_2));
		int32_t length = 16;
		{
			$var($chars, arr$, this->index);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				char16_t i = arr$->get(i$);
				{
					dos->writeChar(i);
				}
			}
		}
		length += $nc(this->index)->length * 2;
		length += $nc(this->data)->write(dos);
		return length;
	} catch ($IOException& e) {
		$throwNew($UncheckedIOException, e);
	}
	$shouldNotReachHere();
}

int32_t CodePointTrie::fastIndex(int32_t c) {
	return $nc(this->index)->get($sr(c, CodePointTrie::FAST_SHIFT)) + ((int32_t)(c & (uint32_t)CodePointTrie::FAST_DATA_MASK));
}

int32_t CodePointTrie::smallIndex($CodePointTrie$Type* type, int32_t c) {
	if (c >= this->highStart) {
		return this->dataLength - CodePointTrie::HIGH_VALUE_NEG_DATA_OFFSET;
	}
	return internalSmallIndex(type, c);
}

int32_t CodePointTrie::internalSmallIndex($CodePointTrie$Type* type, int32_t c) {
	int32_t i1 = $sr(c, CodePointTrie::SHIFT_1);
	$init($CodePointTrie$Type);
	if (type == $CodePointTrie$Type::FAST) {
		if (!CodePointTrie::$assertionsDisabled && !(0x0000FFFF < c && c < this->highStart)) {
			$throwNew($AssertionError);
		}
		i1 += CodePointTrie::BMP_INDEX_LENGTH - CodePointTrie::OMITTED_BMP_INDEX_1_LENGTH;
	} else {
		if (!CodePointTrie::$assertionsDisabled && !(0 <= c && c < this->highStart && this->highStart > CodePointTrie::SMALL_LIMIT)) {
			$throwNew($AssertionError);
		}
		i1 += CodePointTrie::SMALL_INDEX_LENGTH;
	}
	int32_t i3Block = $nc(this->index)->get($nc(this->index)->get(i1) + ((int32_t)(($sr(c, CodePointTrie::SHIFT_2)) & (uint32_t)CodePointTrie::INDEX_2_MASK)));
	int32_t i3 = (int32_t)(($sr(c, CodePointTrie::SHIFT_3)) & (uint32_t)CodePointTrie::INDEX_3_MASK);
	int32_t dataBlock = 0;
	if (((int32_t)(i3Block & (uint32_t)32768)) == 0) {
		dataBlock = $nc(this->index)->get(i3Block + i3);
	} else {
		i3Block = ((int32_t)(i3Block & (uint32_t)32767)) + ((int32_t)(i3 & (uint32_t)~7)) + (i3 >> 3);
		i3 &= (uint32_t)7;
		dataBlock = (int32_t)(($sl((int32_t)$nc(this->index)->get(i3Block++), 2 + (2 * i3))) & (uint32_t)0x00030000);
		dataBlock |= $nc(this->index)->get(i3Block + i3);
	}
	return dataBlock + ((int32_t)(c & (uint32_t)CodePointTrie::SMALL_DATA_MASK));
}

void clinit$CodePointTrie($Class* class$) {
	CodePointTrie::$assertionsDisabled = !CodePointTrie::class$->desiredAssertionStatus();
}

CodePointTrie::CodePointTrie() {
}

$Class* CodePointTrie::load$($String* name, bool initialize) {
	$loadClass(CodePointTrie, name, initialize, &_CodePointTrie_ClassInfo_, clinit$CodePointTrie, allocate$CodePointTrie);
	return class$;
}

$Class* CodePointTrie::class$ = nullptr;

			} // util
		} // icu
	} // internal
} // jdk