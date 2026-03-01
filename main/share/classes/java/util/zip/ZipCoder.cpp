#include <java/util/zip/ZipCoder.h>

#include <java/lang/CharSequence.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/CharBuffer.h>
#include <java/nio/charset/CharacterCodingException.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/CharsetDecoder.h>
#include <java/nio/charset/CharsetEncoder.h>
#include <java/nio/charset/CodingErrorAction.h>
#include <java/util/Arrays.h>
#include <java/util/zip/ZipCoder$UTF8ZipCoder.h>
#include <jdk/internal/access/JavaLangAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <sun/nio/cs/UTF_8.h>
#include <jcpp.h>

#undef INSTANCE
#undef JLA
#undef REPORT
#undef UTF8

using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $CharBuffer = ::java::nio::CharBuffer;
using $CharacterCodingException = ::java::nio::charset::CharacterCodingException;
using $Charset = ::java::nio::charset::Charset;
using $CharsetDecoder = ::java::nio::charset::CharsetDecoder;
using $CharsetEncoder = ::java::nio::charset::CharsetEncoder;
using $CodingErrorAction = ::java::nio::charset::CodingErrorAction;
using $Arrays = ::java::util::Arrays;
using $ZipCoder$UTF8ZipCoder = ::java::util::zip::ZipCoder$UTF8ZipCoder;
using $JavaLangAccess = ::jdk::internal::access::JavaLangAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $UTF_8 = ::sun::nio::cs::UTF_8;

namespace java {
	namespace util {
		namespace zip {

$FieldInfo _ZipCoder_FieldInfo_[] = {
	{"JLA", "Ljdk/internal/access/JavaLangAccess;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ZipCoder, JLA)},
	{"UTF8", "Ljava/util/zip/ZipCoder$UTF8ZipCoder;", nullptr, $STATIC | $FINAL, $staticField(ZipCoder, UTF8)},
	{"slashBytes", "[B", nullptr, $PRIVATE, $field(ZipCoder, slashBytes$)},
	{"cs", "Ljava/nio/charset/Charset;", nullptr, $PRIVATE | $FINAL, $field(ZipCoder, cs)},
	{"dec", "Ljava/nio/charset/CharsetDecoder;", nullptr, $PROTECTED, $field(ZipCoder, dec)},
	{"enc", "Ljava/nio/charset/CharsetEncoder;", nullptr, $PRIVATE, $field(ZipCoder, enc)},
	{}
};

$MethodInfo _ZipCoder_MethodInfo_[] = {
	{"<init>", "(Ljava/nio/charset/Charset;)V", nullptr, $PRIVATE, $method(ZipCoder, init$, void, $Charset*)},
	{"checkedHash", "([BII)I", nullptr, 0, $virtualMethod(ZipCoder, checkedHash, int32_t, $bytes*, int32_t, int32_t), "java.lang.Exception"},
	{"decoder", "()Ljava/nio/charset/CharsetDecoder;", nullptr, $PROTECTED, $virtualMethod(ZipCoder, decoder, $CharsetDecoder*)},
	{"encoder", "()Ljava/nio/charset/CharsetEncoder;", nullptr, $PRIVATE, $method(ZipCoder, encoder, $CharsetEncoder*)},
	{"get", "(Ljava/nio/charset/Charset;)Ljava/util/zip/ZipCoder;", nullptr, $PUBLIC | $STATIC, $staticMethod(ZipCoder, get, ZipCoder*, $Charset*)},
	{"getBytes", "(Ljava/lang/String;)[B", nullptr, 0, $virtualMethod(ZipCoder, getBytes, $bytes*, $String*)},
	{"hasTrailingSlash", "([BI)Z", nullptr, 0, $virtualMethod(ZipCoder, hasTrailingSlash, bool, $bytes*, int32_t)},
	{"hash", "(Ljava/lang/String;)I", nullptr, $STATIC, $staticMethod(ZipCoder, hash, int32_t, $String*)},
	{"isUTF8", "()Z", nullptr, 0, $virtualMethod(ZipCoder, isUTF8, bool)},
	{"slashBytes", "()[B", nullptr, $PRIVATE, $method(ZipCoder, slashBytes, $bytes*)},
	{"toString", "([BII)Ljava/lang/String;", nullptr, 0, $virtualMethod(ZipCoder, toString, $String*, $bytes*, int32_t, int32_t)},
	{"toString", "([BI)Ljava/lang/String;", nullptr, 0, $virtualMethod(ZipCoder, toString, $String*, $bytes*, int32_t)},
	{"toString", "([B)Ljava/lang/String;", nullptr, 0, $virtualMethod(ZipCoder, toString, $String*, $bytes*)},
	{"toStringUTF8", "([BI)Ljava/lang/String;", nullptr, $STATIC, $staticMethod(ZipCoder, toStringUTF8, $String*, $bytes*, int32_t)},
	{}
};

$InnerClassInfo _ZipCoder_InnerClassesInfo_[] = {
	{"java.util.zip.ZipCoder$UTF8ZipCoder", "java.util.zip.ZipCoder", "UTF8ZipCoder", $STATIC | $FINAL},
	{}
};

$ClassInfo _ZipCoder_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.zip.ZipCoder",
	"java.lang.Object",
	nullptr,
	_ZipCoder_FieldInfo_,
	_ZipCoder_MethodInfo_,
	nullptr,
	nullptr,
	_ZipCoder_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.zip.ZipCoder$UTF8ZipCoder"
};

$Object* allocate$ZipCoder($Class* clazz) {
	return $of($alloc(ZipCoder));
}

$JavaLangAccess* ZipCoder::JLA = nullptr;
$ZipCoder$UTF8ZipCoder* ZipCoder::UTF8 = nullptr;

ZipCoder* ZipCoder::get($Charset* charset) {
	$init(ZipCoder);
	$init($UTF_8);
	if ($equals(charset, $UTF_8::INSTANCE)) {
		return ZipCoder::UTF8;
	}
	return $new(ZipCoder, charset);
}

$String* ZipCoder::toString($bytes* ba, int32_t off, int32_t length) {
	$useLocalCurrentObjectStackCache();
	try {
		return $nc($($nc($(decoder()))->decode($($ByteBuffer::wrap(ba, off, length)))))->toString();
	} catch ($CharacterCodingException& x) {
		$throwNew($IllegalArgumentException, static_cast<$Throwable*>(x));
	}
	$shouldNotReachHere();
}

$String* ZipCoder::toString($bytes* ba, int32_t length) {
	return toString(ba, 0, length);
}

$String* ZipCoder::toString($bytes* ba) {
	return toString(ba, 0, $nc(ba)->length);
}

$bytes* ZipCoder::getBytes($String* s) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($ByteBuffer, bb, $nc($(encoder()))->encode($($CharBuffer::wrap(static_cast<$CharSequence*>(s)))));
		int32_t pos = $nc(bb)->position();
		int32_t limit = bb->limit();
		bool var$0 = bb->hasArray() && pos == 0;
		if (var$0 && limit == bb->capacity()) {
			return $cast($bytes, bb->array());
		}
		int32_t var$1 = bb->limit();
		$var($bytes, bytes, $new($bytes, var$1 - bb->position()));
		bb->get(bytes);
		return bytes;
	} catch ($CharacterCodingException& x) {
		$throwNew($IllegalArgumentException, static_cast<$Throwable*>(x));
	}
	$shouldNotReachHere();
}

$String* ZipCoder::toStringUTF8($bytes* ba, int32_t len) {
	$init(ZipCoder);
	return $nc(ZipCoder::UTF8)->toString(ba, 0, len);
}

bool ZipCoder::isUTF8() {
	return false;
}

int32_t ZipCoder::checkedHash($bytes* a, int32_t off, int32_t len) {
	$useLocalCurrentObjectStackCache();
	if (len == 0) {
		return 0;
	}
	int32_t h = 0;
	$var($CharBuffer, cb, $nc($(decoder()))->decode($($ByteBuffer::wrap(a, off, len))));
	int32_t limit = $nc(cb)->limit();
	$var($chars, decoded, $cast($chars, cb->array()));
	for (int32_t i = 0; i < limit; ++i) {
		h = 31 * h + $nc(decoded)->get(i);
	}
	if (limit > 0 && $nc(decoded)->get(limit - 1) != u'/') {
		h = 31 * h + u'/';
	}
	return h;
}

int32_t ZipCoder::hash($String* name) {
	$init(ZipCoder);
	int32_t hsh = $nc(name)->hashCode();
	int32_t len = name->length();
	if (len > 0 && name->charAt(len - 1) != u'/') {
		hsh = hsh * 31 + u'/';
	}
	return hsh;
}

bool ZipCoder::hasTrailingSlash($bytes* a, int32_t end) {
	$var($bytes, slashBytes, this->slashBytes());
	return end >= $nc(slashBytes)->length && $Arrays::mismatch(a, end - slashBytes->length, end, slashBytes, 0, slashBytes->length) == -1;
}

void ZipCoder::init$($Charset* cs) {
	$set(this, cs, cs);
}

$CharsetDecoder* ZipCoder::decoder() {
	$useLocalCurrentObjectStackCache();
	if (this->dec == nullptr) {
		$init($CodingErrorAction);
		$set(this, dec, $nc($($nc($($nc(this->cs)->newDecoder()))->onMalformedInput($CodingErrorAction::REPORT)))->onUnmappableCharacter($CodingErrorAction::REPORT));
	}
	return this->dec;
}

$CharsetEncoder* ZipCoder::encoder() {
	$useLocalCurrentObjectStackCache();
	if (this->enc == nullptr) {
		$init($CodingErrorAction);
		$set(this, enc, $nc($($nc($($nc(this->cs)->newEncoder()))->onMalformedInput($CodingErrorAction::REPORT)))->onUnmappableCharacter($CodingErrorAction::REPORT));
	}
	return this->enc;
}

$bytes* ZipCoder::slashBytes() {
	$useLocalCurrentObjectStackCache();
	if (this->slashBytes$ == nullptr) {
		$var($bytes, slash, "/"_s->getBytes(this->cs));
		$var($bytes, doubleSlash, "//"_s->getBytes(this->cs));
		$set(this, slashBytes$, $Arrays::copyOfRange(doubleSlash, slash->length, doubleSlash->length));
	}
	return this->slashBytes$;
}

void clinit$ZipCoder($Class* class$) {
	$assignStatic(ZipCoder::JLA, $SharedSecrets::getJavaLangAccess());
	$init($UTF_8);
	$assignStatic(ZipCoder::UTF8, $new($ZipCoder$UTF8ZipCoder, $UTF_8::INSTANCE));
}

ZipCoder::ZipCoder() {
}

$Class* ZipCoder::load$($String* name, bool initialize) {
	$loadClass(ZipCoder, name, initialize, &_ZipCoder_ClassInfo_, clinit$ZipCoder, allocate$ZipCoder);
	return class$;
}

$Class* ZipCoder::class$ = nullptr;

		} // zip
	} // util
} // java