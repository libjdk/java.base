#ifndef _jdk_internal_jimage_decompressor_CompressIndexes_h_
#define _jdk_internal_jimage_decompressor_CompressIndexes_h_
//$ class jdk.internal.jimage.decompressor.CompressIndexes
//$ extends java.lang.Object

#include <java/lang/Array.h>
#include <java/lang/Byte.h>

#pragma push_macro("HEADER_WIDTH")
#undef HEADER_WIDTH
#pragma push_macro("COMPRESSED_FLAG")
#undef COMPRESSED_FLAG
#pragma push_macro("SIZE")
#undef SIZE
#pragma push_macro("HEADER_SHIFT")
#undef HEADER_SHIFT

namespace java {
	namespace io {
		class DataInputStream;
	}
}
namespace java {
	namespace util {
		class List;
	}
}

namespace jdk {
	namespace internal {
		namespace jimage {
			namespace decompressor {

class $import CompressIndexes : public ::java::lang::Object {
	$class(CompressIndexes, $NO_CLASS_INIT, ::java::lang::Object)
public:
	CompressIndexes();
	void init$();
	static $bytes* compress(int32_t value);
	static int32_t decompress($bytes* value, int32_t offset);
	static ::java::util::List* decompressFlow($bytes* values);
	static int32_t getHeaderLength(int8_t b);
	static int32_t getHeaderValue(int8_t b);
	static bool isCompressed(int8_t b);
	static int32_t readInt(::java::io::DataInputStream* cr);
	static const int32_t COMPRESSED_FLAG = 128; // 1 << (::java::lang::Byte::SIZE - 1)
	static const int32_t HEADER_WIDTH = 3;
	static const int32_t HEADER_SHIFT = 5; // ::java::lang::Byte::SIZE - HEADER_WIDTH
};

			} // decompressor
		} // jimage
	} // internal
} // jdk

#pragma pop_macro("HEADER_WIDTH")
#pragma pop_macro("COMPRESSED_FLAG")
#pragma pop_macro("SIZE")
#pragma pop_macro("HEADER_SHIFT")

#endif // _jdk_internal_jimage_decompressor_CompressIndexes_h_