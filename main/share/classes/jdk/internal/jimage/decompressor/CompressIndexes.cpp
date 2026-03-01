#include <jdk/internal/jimage/decompressor/CompressIndexes.h>

#include <java/io/DataInputStream.h>
#include <java/lang/Math.h>
#include <java/util/ArrayList.h>
#include <java/util/List.h>
#include <jcpp.h>

#undef BYTES
#undef COMPRESSED_FLAG
#undef HEADER_SHIFT
#undef HEADER_WIDTH
#undef SIZE

using $DataInputStream = ::java::io::DataInputStream;
using $Byte = ::java::lang::Byte;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $Integer = ::java::lang::Integer;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $ArrayList = ::java::util::ArrayList;
using $List = ::java::util::List;

namespace jdk {
	namespace internal {
		namespace jimage {
			namespace decompressor {

$FieldInfo _CompressIndexes_FieldInfo_[] = {
	{"COMPRESSED_FLAG", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CompressIndexes, COMPRESSED_FLAG)},
	{"HEADER_WIDTH", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CompressIndexes, HEADER_WIDTH)},
	{"HEADER_SHIFT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CompressIndexes, HEADER_SHIFT)},
	{}
};

$MethodInfo _CompressIndexes_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(CompressIndexes, init$, void)},
	{"compress", "(I)[B", nullptr, $PUBLIC | $STATIC, $staticMethod(CompressIndexes, compress, $bytes*, int32_t)},
	{"decompress", "([BI)I", nullptr, $PUBLIC | $STATIC, $staticMethod(CompressIndexes, decompress, int32_t, $bytes*, int32_t)},
	{"decompressFlow", "([B)Ljava/util/List;", "([B)Ljava/util/List<Ljava/lang/Integer;>;", $PUBLIC | $STATIC, $staticMethod(CompressIndexes, decompressFlow, $List*, $bytes*)},
	{"getHeaderLength", "(B)I", nullptr, $PRIVATE | $STATIC, $staticMethod(CompressIndexes, getHeaderLength, int32_t, int8_t)},
	{"getHeaderValue", "(B)I", nullptr, $PRIVATE | $STATIC, $staticMethod(CompressIndexes, getHeaderValue, int32_t, int8_t)},
	{"isCompressed", "(B)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(CompressIndexes, isCompressed, bool, int8_t)},
	{"readInt", "(Ljava/io/DataInputStream;)I", nullptr, $PUBLIC | $STATIC, $staticMethod(CompressIndexes, readInt, int32_t, $DataInputStream*), "java.io.IOException"},
	{}
};

$ClassInfo _CompressIndexes_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.jimage.decompressor.CompressIndexes",
	"java.lang.Object",
	nullptr,
	_CompressIndexes_FieldInfo_,
	_CompressIndexes_MethodInfo_
};

$Object* allocate$CompressIndexes($Class* clazz) {
	return $of($alloc(CompressIndexes));
}

void CompressIndexes::init$() {
}

$List* CompressIndexes::decompressFlow($bytes* values) {
	$useLocalCurrentObjectStackCache();
	$var($List, lst, $new($ArrayList));
	for (int32_t i = 0; i < $nc(values)->length; i += getHeaderLength($nc(values)->get(i))) {
		int32_t decompressed = decompress(values, i);
		lst->add($($Integer::valueOf(decompressed)));
	}
	return lst;
}

int32_t CompressIndexes::readInt($DataInputStream* cr) {
	int8_t header = $nc(cr)->readByte();
	int32_t size = getHeaderLength(header);
	int32_t result = getHeaderValue(header);
	for (int32_t i = 1; i < size; ++i) {
		result <<= $Byte::SIZE;
		result |= (int32_t)(cr->readByte() & (uint32_t)255);
	}
	return result;
}

bool CompressIndexes::isCompressed(int8_t b) {
	return ((int32_t)(b & (uint32_t)CompressIndexes::COMPRESSED_FLAG)) != 0;
}

int32_t CompressIndexes::getHeaderLength(int8_t b) {
	return isCompressed(b) ? (int32_t)(($sr((int32_t)b, CompressIndexes::HEADER_SHIFT)) & (uint32_t)3) : $Integer::BYTES;
}

int32_t CompressIndexes::getHeaderValue(int8_t b) {
	return isCompressed(b) ? (int32_t)(b & (uint32_t)(($sl(1, CompressIndexes::HEADER_SHIFT)) - 1)) : (int32_t)b;
}

int32_t CompressIndexes::decompress($bytes* value, int32_t offset) {
	int8_t header = $nc(value)->get(offset);
	int32_t size = getHeaderLength(header);
	int32_t result = getHeaderValue(header);
	for (int32_t i = 1; i < size; ++i) {
		result <<= $Byte::SIZE;
		result |= (int32_t)(value->get(offset + i) & (uint32_t)255);
	}
	return result;
}

$bytes* CompressIndexes::compress(int32_t value) {
	if (value < 0) {
		$throwNew($IllegalArgumentException, "value < 0"_s);
	}
	int32_t width = 32 - $Integer::numberOfLeadingZeros(value);
	int32_t size = $Math::min(((width + CompressIndexes::HEADER_WIDTH - 1) >> 3) + 1, $Integer::BYTES);
	$var($bytes, result, $new($bytes, size));
	for (int32_t i = 0; i < size; ++i) {
		result->set(i, (int8_t)($sr(value, (size - i - 1) * $Byte::SIZE)));
	}
	if (size < $Integer::BYTES) {
		(*result)[0] |= (int8_t)(CompressIndexes::COMPRESSED_FLAG | ($sl(size, CompressIndexes::HEADER_SHIFT)));
	}
	return result;
}

CompressIndexes::CompressIndexes() {
}

$Class* CompressIndexes::load$($String* name, bool initialize) {
	$loadClass(CompressIndexes, name, initialize, &_CompressIndexes_ClassInfo_, allocate$CompressIndexes);
	return class$;
}

$Class* CompressIndexes::class$ = nullptr;

			} // decompressor
		} // jimage
	} // internal
} // jdk