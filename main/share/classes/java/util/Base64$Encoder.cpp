#include <java/util/Base64$Encoder.h>

#include <java/io/OutputStream.h>
#include <java/lang/Math.h>
#include <java/lang/OutOfMemoryError.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/Arrays.h>
#include <java/util/Base64$EncOutputStream.h>
#include <java/util/Base64.h>
#include <java/util/Objects.h>
#include <jcpp.h>

#undef CRLF
#undef MIMELINEMAX

using $OutputStream = ::java::io::OutputStream;
using $ArithmeticException = ::java::lang::ArithmeticException;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $OutOfMemoryError = ::java::lang::OutOfMemoryError;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $Arrays = ::java::util::Arrays;
using $Base64$EncOutputStream = ::java::util::Base64$EncOutputStream;
using $Objects = ::java::util::Objects;

namespace java {
	namespace util {

$CompoundAttribute _Base64$Encoder_MethodAnnotations_encodeBlock5[] = {
	{"Ljdk/internal/vm/annotation/IntrinsicCandidate;", nullptr},
	{}
};

$FieldInfo _Base64$Encoder_FieldInfo_[] = {
	{"newline", "[B", nullptr, $PRIVATE | $FINAL, $field(Base64$Encoder, newline)},
	{"linemax", "I", nullptr, $PRIVATE | $FINAL, $field(Base64$Encoder, linemax)},
	{"isURL", "Z", nullptr, $PRIVATE | $FINAL, $field(Base64$Encoder, isURL)},
	{"doPadding", "Z", nullptr, $PRIVATE | $FINAL, $field(Base64$Encoder, doPadding)},
	{"toBase64", "[C", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Base64$Encoder, toBase64)},
	{"toBase64URL", "[C", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Base64$Encoder, toBase64URL)},
	{"MIMELINEMAX", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Base64$Encoder, MIMELINEMAX)},
	{"CRLF", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Base64$Encoder, CRLF)},
	{"RFC4648", "Ljava/util/Base64$Encoder;", nullptr, $STATIC | $FINAL, $staticField(Base64$Encoder, RFC4648)},
	{"RFC4648_URLSAFE", "Ljava/util/Base64$Encoder;", nullptr, $STATIC | $FINAL, $staticField(Base64$Encoder, RFC4648_URLSAFE)},
	{"RFC2045", "Ljava/util/Base64$Encoder;", nullptr, $STATIC | $FINAL, $staticField(Base64$Encoder, RFC2045)},
	{}
};

$MethodInfo _Base64$Encoder_MethodInfo_[] = {
	{"<init>", "(Z[BIZ)V", nullptr, $PRIVATE, $method(Base64$Encoder, init$, void, bool, $bytes*, int32_t, bool)},
	{"encode", "([B)[B", nullptr, $PUBLIC, $virtualMethod(Base64$Encoder, encode, $bytes*, $bytes*)},
	{"encode", "([B[B)I", nullptr, $PUBLIC, $virtualMethod(Base64$Encoder, encode, int32_t, $bytes*, $bytes*)},
	{"encode", "(Ljava/nio/ByteBuffer;)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC, $virtualMethod(Base64$Encoder, encode, $ByteBuffer*, $ByteBuffer*)},
	{"encode0", "([BII[B)I", nullptr, $PRIVATE, $method(Base64$Encoder, encode0, int32_t, $bytes*, int32_t, int32_t, $bytes*)},
	{"encodeBlock", "([BII[BIZ)V", nullptr, $PRIVATE, $method(Base64$Encoder, encodeBlock, void, $bytes*, int32_t, int32_t, $bytes*, int32_t, bool), nullptr, nullptr, _Base64$Encoder_MethodAnnotations_encodeBlock5},
	{"encodeToString", "([B)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Base64$Encoder, encodeToString, $String*, $bytes*)},
	{"encodedOutLength", "(IZ)I", nullptr, $PRIVATE | $FINAL, $method(Base64$Encoder, encodedOutLength, int32_t, int32_t, bool)},
	{"withoutPadding", "()Ljava/util/Base64$Encoder;", nullptr, $PUBLIC, $virtualMethod(Base64$Encoder, withoutPadding, Base64$Encoder*)},
	{"wrap", "(Ljava/io/OutputStream;)Ljava/io/OutputStream;", nullptr, $PUBLIC, $virtualMethod(Base64$Encoder, wrap, $OutputStream*, $OutputStream*)},
	{}
};

$InnerClassInfo _Base64$Encoder_InnerClassesInfo_[] = {
	{"java.util.Base64$Encoder", "java.util.Base64", "Encoder", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _Base64$Encoder_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.Base64$Encoder",
	"java.lang.Object",
	nullptr,
	_Base64$Encoder_FieldInfo_,
	_Base64$Encoder_MethodInfo_,
	nullptr,
	nullptr,
	_Base64$Encoder_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.Base64"
};

$Object* allocate$Base64$Encoder($Class* clazz) {
	return $of($alloc(Base64$Encoder));
}

$chars* Base64$Encoder::toBase64 = nullptr;
$chars* Base64$Encoder::toBase64URL = nullptr;
$bytes* Base64$Encoder::CRLF = nullptr;
Base64$Encoder* Base64$Encoder::RFC4648 = nullptr;
Base64$Encoder* Base64$Encoder::RFC4648_URLSAFE = nullptr;
Base64$Encoder* Base64$Encoder::RFC2045 = nullptr;

void Base64$Encoder::init$(bool isURL, $bytes* newline, int32_t linemax, bool doPadding) {
	this->isURL = isURL;
	$set(this, newline, newline);
	this->linemax = linemax;
	this->doPadding = doPadding;
}

int32_t Base64$Encoder::encodedOutLength(int32_t srclen, bool throwOOME) {
	int32_t len = 0;
	try {
		if (this->doPadding) {
			len = $Math::multiplyExact(4, ($Math::addExact(srclen, 2) / 3));
		} else {
			int32_t n = srclen % 3;
			len = $Math::addExact($Math::multiplyExact(4, (srclen / 3)), (n == 0 ? 0 : n + 1));
		}
		if (this->linemax > 0) {
			len = $Math::addExact(len, $div((len - 1), this->linemax) * $nc(this->newline)->length);
		}
	} catch ($ArithmeticException& ex) {
		if (throwOOME) {
			$throwNew($OutOfMemoryError, "Encoded size is too large"_s);
		} else {
			len = -1;
		}
	}
	return len;
}

$bytes* Base64$Encoder::encode($bytes* src) {
	int32_t len = encodedOutLength($nc(src)->length, true);
	$var($bytes, dst, $new($bytes, len));
	int32_t ret = encode0(src, 0, $nc(src)->length, dst);
	if (ret != dst->length) {
		return $Arrays::copyOf(dst, ret);
	}
	return dst;
}

int32_t Base64$Encoder::encode($bytes* src, $bytes* dst) {
	int32_t len = encodedOutLength($nc(src)->length, false);
	if ($nc(dst)->length < len || len == -1) {
		$throwNew($IllegalArgumentException, "Output byte array is too small for encoding all input bytes"_s);
	}
	return encode0(src, 0, $nc(src)->length, dst);
}

$String* Base64$Encoder::encodeToString($bytes* src) {
	$var($bytes, encoded, encode(src));
	return $new($String, encoded, 0, 0, $nc(encoded)->length);
}

$ByteBuffer* Base64$Encoder::encode($ByteBuffer* buffer) {
	$useLocalCurrentObjectStackCache();
	int32_t len = encodedOutLength($nc(buffer)->remaining(), true);
	$var($bytes, dst, $new($bytes, len));
	int32_t ret = 0;
	if ($nc(buffer)->hasArray()) {
		$var($bytes, var$0, $cast($bytes, buffer->array()));
		int32_t var$2 = buffer->arrayOffset();
		int32_t var$1 = var$2 + buffer->position();
		int32_t var$3 = buffer->arrayOffset();
		ret = encode0(var$0, var$1, var$3 + buffer->limit(), dst);
		buffer->position(buffer->limit());
	} else {
		$var($bytes, src, $new($bytes, buffer->remaining()));
		buffer->get(src);
		ret = encode0(src, 0, src->length, dst);
	}
	if (ret != dst->length) {
		$assign(dst, $Arrays::copyOf(dst, ret));
	}
	return $ByteBuffer::wrap(dst);
}

$OutputStream* Base64$Encoder::wrap($OutputStream* os) {
	$Objects::requireNonNull(os);
	return $new($Base64$EncOutputStream, os, this->isURL ? Base64$Encoder::toBase64URL : Base64$Encoder::toBase64, this->newline, this->linemax, this->doPadding);
}

Base64$Encoder* Base64$Encoder::withoutPadding() {
	if (!this->doPadding) {
		return this;
	}
	return $new(Base64$Encoder, this->isURL, this->newline, this->linemax, false);
}

void Base64$Encoder::encodeBlock($bytes* src, int32_t sp, int32_t sl, $bytes* dst, int32_t dp, bool isURL) {
	$var($chars, base64, isURL ? Base64$Encoder::toBase64URL : Base64$Encoder::toBase64);
	{
		int32_t sp0 = sp;
		int32_t dp0 = dp;
		for (; sp0 < sl;) {
			int32_t var$1 = ((int32_t)($nc(src)->get(sp0++) & (uint32_t)255)) << 16;
			int32_t var$0 = var$1 | (((int32_t)(src->get(sp0++) & (uint32_t)255)) << 8);
			int32_t bits = var$0 | ((int32_t)(src->get(sp0++) & (uint32_t)255));
			$nc(dst)->set(dp0++, (int8_t)$nc(base64)->get((int32_t)(((int32_t)((uint32_t)bits >> 18)) & (uint32_t)63)));
			dst->set(dp0++, (int8_t)base64->get((int32_t)(((int32_t)((uint32_t)bits >> 12)) & (uint32_t)63)));
			dst->set(dp0++, (int8_t)base64->get((int32_t)(((int32_t)((uint32_t)bits >> 6)) & (uint32_t)63)));
			dst->set(dp0++, (int8_t)base64->get((int32_t)(bits & (uint32_t)63)));
		}
	}
}

int32_t Base64$Encoder::encode0($bytes* src, int32_t off, int32_t end, $bytes* dst) {
	$useLocalCurrentObjectStackCache();
	$var($chars, base64, this->isURL ? Base64$Encoder::toBase64URL : Base64$Encoder::toBase64);
	int32_t sp = off;
	int32_t slen = (end - off) / 3 * 3;
	int32_t sl = off + slen;
	if (this->linemax > 0 && slen > this->linemax / 4 * 3) {
		slen = this->linemax / 4 * 3;
	}
	int32_t dp = 0;
	while (sp < sl) {
		int32_t sl0 = $Math::min(sp + slen, sl);
		encodeBlock(src, sp, sl0, dst, dp, this->isURL);
		int32_t dlen = (sl0 - sp) / 3 * 4;
		dp += dlen;
		sp = sl0;
		if (dlen == this->linemax && sp < end) {
			{
				$var($bytes, arr$, this->newline);
				int32_t len$ = $nc(arr$)->length;
				int32_t i$ = 0;
				for (; i$ < len$; ++i$) {
					int8_t b = arr$->get(i$);
					{
						$nc(dst)->set(dp++, b);
					}
				}
			}
		}
	}
	if (sp < end) {
		int32_t b0 = (int32_t)($nc(src)->get(sp++) & (uint32_t)255);
		$nc(dst)->set(dp++, (int8_t)$nc(base64)->get(b0 >> 2));
		if (sp == end) {
			dst->set(dp++, (int8_t)base64->get((int32_t)((b0 << 4) & (uint32_t)63)));
			if (this->doPadding) {
				dst->set(dp++, (int8_t)u'=');
				dst->set(dp++, (int8_t)u'=');
			}
		} else {
			int32_t b1 = (int32_t)(src->get(sp++) & (uint32_t)255);
			dst->set(dp++, (int8_t)base64->get(((int32_t)((b0 << 4) & (uint32_t)63)) | (b1 >> 4)));
			dst->set(dp++, (int8_t)base64->get((int32_t)((b1 << 2) & (uint32_t)63)));
			if (this->doPadding) {
				dst->set(dp++, (int8_t)u'=');
			}
		}
	}
	return dp;
}

void clinit$Base64$Encoder($Class* class$) {
	$assignStatic(Base64$Encoder::toBase64, $new($chars, {
		u'A',
		u'B',
		u'C',
		u'D',
		u'E',
		u'F',
		u'G',
		u'H',
		u'I',
		u'J',
		u'K',
		u'L',
		u'M',
		u'N',
		u'O',
		u'P',
		u'Q',
		u'R',
		u'S',
		u'T',
		u'U',
		u'V',
		u'W',
		u'X',
		u'Y',
		u'Z',
		u'a',
		u'b',
		u'c',
		u'd',
		u'e',
		u'f',
		u'g',
		u'h',
		u'i',
		u'j',
		u'k',
		u'l',
		u'm',
		u'n',
		u'o',
		u'p',
		u'q',
		u'r',
		u's',
		u't',
		u'u',
		u'v',
		u'w',
		u'x',
		u'y',
		u'z',
		u'0',
		u'1',
		u'2',
		u'3',
		u'4',
		u'5',
		u'6',
		u'7',
		u'8',
		u'9',
		u'+',
		u'/'
	}));
	$assignStatic(Base64$Encoder::toBase64URL, $new($chars, {
		u'A',
		u'B',
		u'C',
		u'D',
		u'E',
		u'F',
		u'G',
		u'H',
		u'I',
		u'J',
		u'K',
		u'L',
		u'M',
		u'N',
		u'O',
		u'P',
		u'Q',
		u'R',
		u'S',
		u'T',
		u'U',
		u'V',
		u'W',
		u'X',
		u'Y',
		u'Z',
		u'a',
		u'b',
		u'c',
		u'd',
		u'e',
		u'f',
		u'g',
		u'h',
		u'i',
		u'j',
		u'k',
		u'l',
		u'm',
		u'n',
		u'o',
		u'p',
		u'q',
		u'r',
		u's',
		u't',
		u'u',
		u'v',
		u'w',
		u'x',
		u'y',
		u'z',
		u'0',
		u'1',
		u'2',
		u'3',
		u'4',
		u'5',
		u'6',
		u'7',
		u'8',
		u'9',
		u'-',
		u'_'
	}));
	$assignStatic(Base64$Encoder::CRLF, $new($bytes, {
		(int8_t)u'\r',
		(int8_t)u'\n'
	}));
	$assignStatic(Base64$Encoder::RFC4648, $new(Base64$Encoder, false, nullptr, -1, true));
	$assignStatic(Base64$Encoder::RFC4648_URLSAFE, $new(Base64$Encoder, true, nullptr, -1, true));
	$assignStatic(Base64$Encoder::RFC2045, $new(Base64$Encoder, false, Base64$Encoder::CRLF, Base64$Encoder::MIMELINEMAX, true));
}

Base64$Encoder::Base64$Encoder() {
}

$Class* Base64$Encoder::load$($String* name, bool initialize) {
	$loadClass(Base64$Encoder, name, initialize, &_Base64$Encoder_ClassInfo_, clinit$Base64$Encoder, allocate$Base64$Encoder);
	return class$;
}

$Class* Base64$Encoder::class$ = nullptr;

	} // util
} // java