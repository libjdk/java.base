#include <jdk/internal/jimage/ImageStringsReader.h>

#include <java/io/UTFDataFormatException.h>
#include <java/lang/InternalError.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/StandardCharsets.h>
#include <java/util/Objects.h>
#include <jdk/internal/jimage/BasicImageReader.h>
#include <jcpp.h>

#undef HASH_MULTIPLIER
#undef POSITIVE_MASK
#undef US_ASCII

using $UTFDataFormatException = ::java::io::UTFDataFormatException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $Objects = ::java::util::Objects;
using $BasicImageReader = ::jdk::internal::jimage::BasicImageReader;

namespace jdk {
	namespace internal {
		namespace jimage {

$FieldInfo _ImageStringsReader_FieldInfo_[] = {
	{"HASH_MULTIPLIER", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(ImageStringsReader, HASH_MULTIPLIER)},
	{"POSITIVE_MASK", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(ImageStringsReader, POSITIVE_MASK)},
	{"reader", "Ljdk/internal/jimage/BasicImageReader;", nullptr, $PRIVATE | $FINAL, $field(ImageStringsReader, reader)},
	{}
};

$MethodInfo _ImageStringsReader_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/jimage/BasicImageReader;)V", nullptr, 0, $method(ImageStringsReader, init$, void, $BasicImageReader*)},
	{"add", "(Ljava/lang/String;)I", nullptr, $PUBLIC, $virtualMethod(ImageStringsReader, add, int32_t, $String*)},
	{"charsFromByteBuffer", "([CLjava/nio/ByteBuffer;I)V", nullptr, $PRIVATE | $STATIC, $staticMethod(ImageStringsReader, charsFromByteBuffer, void, $chars*, $ByteBuffer*, int32_t)},
	{"charsFromByteBufferLength", "(Ljava/nio/ByteBuffer;I)I", nullptr, $PRIVATE | $STATIC, $staticMethod(ImageStringsReader, charsFromByteBufferLength, int32_t, $ByteBuffer*, int32_t)},
	{"charsFromMUTF8", "([C[BII)V", nullptr, $STATIC, $staticMethod(ImageStringsReader, charsFromMUTF8, void, $chars*, $bytes*, int32_t, int32_t), "java.io.UTFDataFormatException"},
	{"charsFromMUTF8Length", "([BII)I", nullptr, $STATIC, $staticMethod(ImageStringsReader, charsFromMUTF8Length, int32_t, $bytes*, int32_t, int32_t)},
	{"get", "(I)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ImageStringsReader, get, $String*, int32_t)},
	{"hashCode", "(Ljava/lang/String;)I", nullptr, $PUBLIC | $STATIC, $staticMethod(ImageStringsReader, hashCode, int32_t, $String*)},
	{"hashCode", "(Ljava/lang/String;I)I", nullptr, $PUBLIC | $STATIC, $staticMethod(ImageStringsReader, hashCode, int32_t, $String*, int32_t)},
	{"hashCode", "(Ljava/lang/String;Ljava/lang/String;)I", nullptr, $PUBLIC | $STATIC, $staticMethod(ImageStringsReader, hashCode, int32_t, $String*, $String*)},
	{"hashCode", "(Ljava/lang/String;Ljava/lang/String;I)I", nullptr, $PUBLIC | $STATIC, $staticMethod(ImageStringsReader, hashCode, int32_t, $String*, $String*, int32_t)},
	{"match", "(ILjava/lang/String;I)I", nullptr, $PUBLIC, $virtualMethod(ImageStringsReader, match, int32_t, int32_t, $String*, int32_t)},
	{"mutf8FromString", "([BILjava/lang/String;)V", nullptr, $STATIC, $staticMethod(ImageStringsReader, mutf8FromString, void, $bytes*, int32_t, $String*)},
	{"mutf8FromString", "(Ljava/lang/String;)[B", nullptr, $PUBLIC | $STATIC, $staticMethod(ImageStringsReader, mutf8FromString, $bytes*, $String*)},
	{"mutf8FromStringLength", "(Ljava/lang/String;)I", nullptr, $STATIC, $staticMethod(ImageStringsReader, mutf8FromStringLength, int32_t, $String*)},
	{"stringFromByteBuffer", "(Ljava/nio/ByteBuffer;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(ImageStringsReader, stringFromByteBuffer, $String*, $ByteBuffer*)},
	{"stringFromByteBuffer", "(Ljava/nio/ByteBuffer;I)Ljava/lang/String;", nullptr, $STATIC, $staticMethod(ImageStringsReader, stringFromByteBuffer, $String*, $ByteBuffer*, int32_t)},
	{"stringFromByteBufferMatches", "(Ljava/nio/ByteBuffer;ILjava/lang/String;I)I", nullptr, $STATIC, $staticMethod(ImageStringsReader, stringFromByteBufferMatches, int32_t, $ByteBuffer*, int32_t, $String*, int32_t)},
	{"stringFromMUTF8", "([BII)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(ImageStringsReader, stringFromMUTF8, $String*, $bytes*, int32_t, int32_t)},
	{"stringFromMUTF8", "([B)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(ImageStringsReader, stringFromMUTF8, $String*, $bytes*)},
	{"unmaskedHashCode", "(Ljava/lang/String;I)I", nullptr, $PUBLIC | $STATIC, $staticMethod(ImageStringsReader, unmaskedHashCode, int32_t, $String*, int32_t)},
	{}
};

$ClassInfo _ImageStringsReader_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.jimage.ImageStringsReader",
	"java.lang.Object",
	"jdk.internal.jimage.ImageStrings",
	_ImageStringsReader_FieldInfo_,
	_ImageStringsReader_MethodInfo_
};

$Object* allocate$ImageStringsReader($Class* clazz) {
	return $of($alloc(ImageStringsReader));
}

void ImageStringsReader::init$($BasicImageReader* reader) {
	$set(this, reader, $cast($BasicImageReader, $Objects::requireNonNull(reader)));
}

$String* ImageStringsReader::get(int32_t offset) {
	return $nc(this->reader)->getString(offset);
}

int32_t ImageStringsReader::match(int32_t offset, $String* string, int32_t stringOffset) {
	return $nc(this->reader)->match(offset, string, stringOffset);
}

int32_t ImageStringsReader::add($String* string) {
	$throwNew($InternalError, "Can not add strings at runtime"_s);
	$shouldNotReachHere();
}

int32_t ImageStringsReader::hashCode($String* s) {
	$init(ImageStringsReader);
	return hashCode(s, ImageStringsReader::HASH_MULTIPLIER);
}

int32_t ImageStringsReader::hashCode($String* s, int32_t seed) {
	$init(ImageStringsReader);
	return (int32_t)(unmaskedHashCode(s, seed) & (uint32_t)ImageStringsReader::POSITIVE_MASK);
}

int32_t ImageStringsReader::hashCode($String* module, $String* name) {
	$init(ImageStringsReader);
	return hashCode(module, name, ImageStringsReader::HASH_MULTIPLIER);
}

int32_t ImageStringsReader::hashCode($String* module, $String* name, int32_t seed) {
	$init(ImageStringsReader);
	seed = (seed * ImageStringsReader::HASH_MULTIPLIER) ^ (u'/');
	seed = unmaskedHashCode(module, seed);
	seed = (seed * ImageStringsReader::HASH_MULTIPLIER) ^ (u'/');
	seed = unmaskedHashCode(name, seed);
	return (int32_t)(seed & (uint32_t)ImageStringsReader::POSITIVE_MASK);
}

int32_t ImageStringsReader::unmaskedHashCode($String* s, int32_t seed) {
	$init(ImageStringsReader);
	int32_t slen = $nc(s)->length();
	$var($bytes, buffer, nullptr);
	for (int32_t i = 0; i < slen; ++i) {
		int32_t uch = s->charAt(i);
		if (((int32_t)(uch & (uint32_t)~127)) != 0) {
			if (buffer == nullptr) {
				$assign(buffer, $new($bytes, 8));
			}
			int32_t mask = ~63;
			int32_t n = 0;
			do {
				$nc(buffer)->set(n++, (int8_t)(128 | ((int32_t)(uch & (uint32_t)63))));
				uch >>= 6;
				mask >>= 1;
			} while (((int32_t)(uch & (uint32_t)mask)) != 0);
			$nc(buffer)->set(n, (int8_t)((mask << 1) | uch));
			do {
				seed = (seed * ImageStringsReader::HASH_MULTIPLIER) ^ ((int32_t)(buffer->get(n--) & (uint32_t)255));
			} while (0 <= n);
		} else if (uch == 0) {
			seed = (seed * ImageStringsReader::HASH_MULTIPLIER) ^ (192);
			seed = (seed * ImageStringsReader::HASH_MULTIPLIER) ^ (128);
		} else {
			seed = (seed * ImageStringsReader::HASH_MULTIPLIER) ^ (uch);
		}
	}
	return seed;
}

int32_t ImageStringsReader::charsFromMUTF8Length($bytes* bytes, int32_t offset, int32_t count) {
	$init(ImageStringsReader);
	int32_t length = 0;
	for (int32_t i = offset; i < offset + count; ++i) {
		int8_t ch = $nc(bytes)->get(i);
		if (ch == 0) {
			break;
		}
		if (((int32_t)(ch & (uint32_t)192)) != 128) {
			++length;
		}
	}
	return length;
}

void ImageStringsReader::charsFromMUTF8($chars* chars, $bytes* bytes, int32_t offset, int32_t count) {
	$init(ImageStringsReader);
	$useLocalCurrentObjectStackCache();
	int32_t j = 0;
	for (int32_t i = offset; i < offset + count; ++i) {
		int8_t ch = $nc(bytes)->get(i);
		if (ch == 0) {
			break;
		}
		bool is_unicode = ((int32_t)(ch & (uint32_t)128)) != 0;
		int32_t uch = (int32_t)(ch & (uint32_t)127);
		if (is_unicode) {
			int32_t mask = 64;
			while (((int32_t)(uch & (uint32_t)mask)) != 0) {
				ch = bytes->get(++i);
				if (((int32_t)(ch & (uint32_t)192)) != 128) {
					$throwNew($UTFDataFormatException, $$str({"bad continuation 0x"_s, $($Integer::toHexString(ch))}));
				}
				uch = (((int32_t)(uch & (uint32_t)~mask)) << 6) | ((int32_t)(ch & (uint32_t)63));
				mask <<= 6 - 1;
			}
			if (((int32_t)(uch & (uint32_t)0x0000FFFF)) != uch) {
				$throwNew($UTFDataFormatException, $$str({"character out of range \\u"_s, $($Integer::toHexString(uch))}));
			}
		}
		$nc(chars)->set(j++, (char16_t)uch);
	}
}

$String* ImageStringsReader::stringFromMUTF8($bytes* bytes, int32_t offset, int32_t count) {
	$init(ImageStringsReader);
	int32_t length = charsFromMUTF8Length(bytes, offset, count);
	$var($chars, chars, $new($chars, length));
	try {
		charsFromMUTF8(chars, bytes, offset, count);
	} catch ($UTFDataFormatException& ex) {
		$throwNew($InternalError, "Attempt to convert non modified UTF-8 byte sequence"_s, ex);
	}
	return $new($String, chars);
}

$String* ImageStringsReader::stringFromMUTF8($bytes* bytes) {
	$init(ImageStringsReader);
	return stringFromMUTF8(bytes, 0, $nc(bytes)->length);
}

int32_t ImageStringsReader::charsFromByteBufferLength($ByteBuffer* buffer, int32_t offset) {
	$init(ImageStringsReader);
	int32_t length = 0;
	int32_t limit = $nc(buffer)->limit();
	bool asciiOnly = true;
	while (offset < limit) {
		int8_t ch = buffer->get(offset++);
		if (ch < 0) {
			asciiOnly = false;
		} else if (ch == 0) {
			return asciiOnly ? length : -length;
		}
		if (((int32_t)(ch & (uint32_t)192)) != 128) {
			++length;
		}
	}
	$throwNew($InternalError, "No terminating zero byte for modified UTF-8 byte sequence"_s);
}

void ImageStringsReader::charsFromByteBuffer($chars* chars, $ByteBuffer* buffer, int32_t offset) {
	$init(ImageStringsReader);
	$useLocalCurrentObjectStackCache();
	int32_t j = 0;
	int32_t limit = $nc(buffer)->limit();
	while (offset < limit) {
		int8_t ch = buffer->get(offset++);
		if (ch == 0) {
			return;
		}
		bool is_unicode = ((int32_t)(ch & (uint32_t)128)) != 0;
		int32_t uch = (int32_t)(ch & (uint32_t)127);
		if (is_unicode) {
			int32_t mask = 64;
			while (((int32_t)(uch & (uint32_t)mask)) != 0) {
				ch = buffer->get(offset++);
				if (((int32_t)(ch & (uint32_t)192)) != 128) {
					$throwNew($InternalError, $$str({"Bad continuation in modified UTF-8 byte sequence: "_s, $$str(ch)}));
				}
				uch = (((int32_t)(uch & (uint32_t)~mask)) << 6) | ((int32_t)(ch & (uint32_t)63));
				mask <<= 6 - 1;
			}
		}
		if (((int32_t)(uch & (uint32_t)0x0000FFFF)) != uch) {
			$throwNew($InternalError, $$str({"UTF-32 char in modified UTF-8 byte sequence: "_s, $$str(uch)}));
		}
		$nc(chars)->set(j++, (char16_t)uch);
	}
	$throwNew($InternalError, "No terminating zero byte for modified UTF-8 byte sequence"_s);
}

$String* ImageStringsReader::stringFromByteBuffer($ByteBuffer* buffer) {
	$init(ImageStringsReader);
	return stringFromByteBuffer(buffer, 0);
}

$String* ImageStringsReader::stringFromByteBuffer($ByteBuffer* buffer, int32_t offset) {
	$init(ImageStringsReader);
	$useLocalCurrentObjectStackCache();
	int32_t length = charsFromByteBufferLength(buffer, offset);
	if (length > 0) {
		$var($bytes, asciiBytes, $new($bytes, length));
		for (int32_t i = 0; i < length; ++i) {
			asciiBytes->set(i, $nc(buffer)->get(offset++));
		}
		$init($StandardCharsets);
		return $new($String, asciiBytes, $StandardCharsets::US_ASCII);
	}
	$var($chars, chars, $new($chars, -length));
	charsFromByteBuffer(chars, buffer, offset);
	return $new($String, chars);
}

int32_t ImageStringsReader::stringFromByteBufferMatches($ByteBuffer* buffer, int32_t offset, $String* string, int32_t stringOffset) {
	$init(ImageStringsReader);
	int32_t limit = $nc(buffer)->limit();
	int32_t current = offset;
	int32_t slen = $nc(string)->length();
	while (current < limit) {
		int8_t ch = buffer->get(current);
		if (ch <= 0) {
			if (ch == 0) {
				return current - offset;
			}
			break;
		}
		if (slen <= stringOffset || string->charAt(stringOffset) != (char16_t)ch) {
			return -1;
		}
		++stringOffset;
		++current;
	}
	int32_t length = -charsFromByteBufferLength(buffer, current);
	$var($chars, chars, $new($chars, length));
	charsFromByteBuffer(chars, buffer, current);
	for (int32_t i = 0; i < length; ++i) {
		if (string->charAt(stringOffset++) != chars->get(i)) {
			return -1;
		}
	}
	return length;
}

int32_t ImageStringsReader::mutf8FromStringLength($String* s) {
	$init(ImageStringsReader);
	int32_t length = 0;
	int32_t slen = $nc(s)->length();
	for (int32_t i = 0; i < slen; ++i) {
		char16_t ch = s->charAt(i);
		int32_t uch = (int32_t)(ch & (uint32_t)0x0000FFFF);
		if (((int32_t)(uch & (uint32_t)~127)) != 0) {
			int32_t mask = ~63;
			int32_t n = 0;
			do {
				++n;
				uch >>= 6;
				mask >>= 1;
			} while (((int32_t)(uch & (uint32_t)mask)) != 0);
			length += n + 1;
		} else if (uch == 0) {
			length += 2;
		} else {
			++length;
		}
	}
	return length;
}

void ImageStringsReader::mutf8FromString($bytes* bytes, int32_t offset, $String* s) {
	$init(ImageStringsReader);
	int32_t j = offset;
	$var($bytes, buffer, nullptr);
	int32_t slen = $nc(s)->length();
	for (int32_t i = 0; i < slen; ++i) {
		char16_t ch = s->charAt(i);
		int32_t uch = (int32_t)(ch & (uint32_t)0x0000FFFF);
		if (((int32_t)(uch & (uint32_t)~127)) != 0) {
			if (buffer == nullptr) {
				$assign(buffer, $new($bytes, 8));
			}
			int32_t mask = ~63;
			int32_t n = 0;
			do {
				$nc(buffer)->set(n++, (int8_t)(128 | ((int32_t)(uch & (uint32_t)63))));
				uch >>= 6;
				mask >>= 1;
			} while (((int32_t)(uch & (uint32_t)mask)) != 0);
			$nc(buffer)->set(n, (int8_t)((mask << 1) | uch));
			do {
				$nc(bytes)->set(j++, buffer->get(n--));
			} while (0 <= n);
		} else if (uch == 0) {
			$nc(bytes)->set(j++, (int8_t)192);
			bytes->set(j++, (int8_t)128);
		} else {
			$nc(bytes)->set(j++, (int8_t)uch);
		}
	}
}

$bytes* ImageStringsReader::mutf8FromString($String* string) {
	$init(ImageStringsReader);
	int32_t length = mutf8FromStringLength(string);
	$var($bytes, bytes, $new($bytes, length));
	mutf8FromString(bytes, 0, string);
	return bytes;
}

ImageStringsReader::ImageStringsReader() {
}

$Class* ImageStringsReader::load$($String* name, bool initialize) {
	$loadClass(ImageStringsReader, name, initialize, &_ImageStringsReader_ClassInfo_, allocate$ImageStringsReader);
	return class$;
}

$Class* ImageStringsReader::class$ = nullptr;

		} // jimage
	} // internal
} // jdk