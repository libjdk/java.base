#include <sun/nio/cs/StreamDecoder.h>

#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/Reader.h>
#include <java/io/UnsupportedEncodingException.h>
#include <java/lang/AssertionError.h>
#include <java/lang/IndexOutOfBoundsException.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/CharBuffer.h>
#include <java/nio/channels/FileChannel.h>
#include <java/nio/channels/ReadableByteChannel.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/CharsetDecoder.h>
#include <java/nio/charset/CoderResult.h>
#include <java/nio/charset/CodingErrorAction.h>
#include <java/nio/charset/IllegalCharsetNameException.h>
#include <java/nio/charset/UnsupportedCharsetException.h>
#include <sun/nio/cs/HistoricallyNamedCharset.h>
#include <jcpp.h>

#undef DEFAULT_BYTE_BUFFER_SIZE
#undef MIN_BYTE_BUFFER_SIZE
#undef REPLACE

using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $Reader = ::java::io::Reader;
using $UnsupportedEncodingException = ::java::io::UnsupportedEncodingException;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IndexOutOfBoundsException = ::java::lang::IndexOutOfBoundsException;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $CharBuffer = ::java::nio::CharBuffer;
using $FileChannel = ::java::nio::channels::FileChannel;
using $ReadableByteChannel = ::java::nio::channels::ReadableByteChannel;
using $Charset = ::java::nio::charset::Charset;
using $CharsetDecoder = ::java::nio::charset::CharsetDecoder;
using $CoderResult = ::java::nio::charset::CoderResult;
using $CodingErrorAction = ::java::nio::charset::CodingErrorAction;
using $IllegalCharsetNameException = ::java::nio::charset::IllegalCharsetNameException;
using $UnsupportedCharsetException = ::java::nio::charset::UnsupportedCharsetException;
using $HistoricallyNamedCharset = ::sun::nio::cs::HistoricallyNamedCharset;

namespace sun {
	namespace nio {
		namespace cs {

$FieldInfo _StreamDecoder_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(StreamDecoder, $assertionsDisabled)},
	{"MIN_BYTE_BUFFER_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StreamDecoder, MIN_BYTE_BUFFER_SIZE)},
	{"DEFAULT_BYTE_BUFFER_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StreamDecoder, DEFAULT_BYTE_BUFFER_SIZE)},
	{"closed", "Z", nullptr, $PRIVATE | $VOLATILE, $field(StreamDecoder, closed)},
	{"haveLeftoverChar", "Z", nullptr, $PRIVATE, $field(StreamDecoder, haveLeftoverChar)},
	{"leftoverChar", "C", nullptr, $PRIVATE, $field(StreamDecoder, leftoverChar)},
	{"cs", "Ljava/nio/charset/Charset;", nullptr, $PRIVATE | $FINAL, $field(StreamDecoder, cs)},
	{"decoder", "Ljava/nio/charset/CharsetDecoder;", nullptr, $PRIVATE | $FINAL, $field(StreamDecoder, decoder)},
	{"bb", "Ljava/nio/ByteBuffer;", nullptr, $PRIVATE | $FINAL, $field(StreamDecoder, bb)},
	{"in", "Ljava/io/InputStream;", nullptr, $PRIVATE | $FINAL, $field(StreamDecoder, in)},
	{"ch", "Ljava/nio/channels/ReadableByteChannel;", nullptr, $PRIVATE | $FINAL, $field(StreamDecoder, ch)},
	{}
};

$MethodInfo _StreamDecoder_MethodInfo_[] = {
	{"<init>", "(Ljava/io/InputStream;Ljava/lang/Object;Ljava/nio/charset/Charset;)V", nullptr, 0, $method(StreamDecoder, init$, void, $InputStream*, Object$*, $Charset*)},
	{"<init>", "(Ljava/io/InputStream;Ljava/lang/Object;Ljava/nio/charset/CharsetDecoder;)V", nullptr, 0, $method(StreamDecoder, init$, void, $InputStream*, Object$*, $CharsetDecoder*)},
	{"<init>", "(Ljava/nio/channels/ReadableByteChannel;Ljava/nio/charset/CharsetDecoder;I)V", nullptr, 0, $method(StreamDecoder, init$, void, $ReadableByteChannel*, $CharsetDecoder*, int32_t)},
	{"close", "()V", nullptr, $PUBLIC, $virtualMethod(StreamDecoder, close, void), "java.io.IOException"},
	{"encodingName", "()Ljava/lang/String;", nullptr, 0, $virtualMethod(StreamDecoder, encodingName, $String*)},
	{"ensureOpen", "()V", nullptr, $PRIVATE, $method(StreamDecoder, ensureOpen, void), "java.io.IOException"},
	{"forDecoder", "(Ljava/nio/channels/ReadableByteChannel;Ljava/nio/charset/CharsetDecoder;I)Lsun/nio/cs/StreamDecoder;", nullptr, $PUBLIC | $STATIC, $staticMethod(StreamDecoder, forDecoder, StreamDecoder*, $ReadableByteChannel*, $CharsetDecoder*, int32_t)},
	{"forInputStreamReader", "(Ljava/io/InputStream;Ljava/lang/Object;Ljava/lang/String;)Lsun/nio/cs/StreamDecoder;", nullptr, $PUBLIC | $STATIC, $staticMethod(StreamDecoder, forInputStreamReader, StreamDecoder*, $InputStream*, Object$*, $String*), "java.io.UnsupportedEncodingException"},
	{"forInputStreamReader", "(Ljava/io/InputStream;Ljava/lang/Object;Ljava/nio/charset/Charset;)Lsun/nio/cs/StreamDecoder;", nullptr, $PUBLIC | $STATIC, $staticMethod(StreamDecoder, forInputStreamReader, StreamDecoder*, $InputStream*, Object$*, $Charset*)},
	{"forInputStreamReader", "(Ljava/io/InputStream;Ljava/lang/Object;Ljava/nio/charset/CharsetDecoder;)Lsun/nio/cs/StreamDecoder;", nullptr, $PUBLIC | $STATIC, $staticMethod(StreamDecoder, forInputStreamReader, StreamDecoder*, $InputStream*, Object$*, $CharsetDecoder*)},
	{"getEncoding", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(StreamDecoder, getEncoding, $String*)},
	{"implClose", "()V", nullptr, 0, $virtualMethod(StreamDecoder, implClose, void), "java.io.IOException"},
	{"implRead", "([CII)I", nullptr, 0, $virtualMethod(StreamDecoder, implRead, int32_t, $chars*, int32_t, int32_t), "java.io.IOException"},
	{"implReady", "()Z", nullptr, 0, $virtualMethod(StreamDecoder, implReady, bool)},
	{"inReady", "()Z", nullptr, $PRIVATE, $method(StreamDecoder, inReady, bool)},
	{"isOpen", "()Z", nullptr, $PRIVATE, $method(StreamDecoder, isOpen, bool)},
	{"read", "()I", nullptr, $PUBLIC, $virtualMethod(StreamDecoder, read, int32_t), "java.io.IOException"},
	{"read", "([CII)I", nullptr, $PUBLIC, $virtualMethod(StreamDecoder, read, int32_t, $chars*, int32_t, int32_t), "java.io.IOException"},
	{"read0", "()I", nullptr, $PRIVATE, $method(StreamDecoder, read0, int32_t), "java.io.IOException"},
	{"readBytes", "()I", nullptr, $PRIVATE, $method(StreamDecoder, readBytes, int32_t), "java.io.IOException"},
	{"ready", "()Z", nullptr, $PUBLIC, $virtualMethod(StreamDecoder, ready, bool), "java.io.IOException"},
	{}
};

$ClassInfo _StreamDecoder_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.nio.cs.StreamDecoder",
	"java.io.Reader",
	nullptr,
	_StreamDecoder_FieldInfo_,
	_StreamDecoder_MethodInfo_
};

$Object* allocate$StreamDecoder($Class* clazz) {
	return $of($alloc(StreamDecoder));
}

bool StreamDecoder::$assertionsDisabled = false;

void StreamDecoder::ensureOpen() {
	if (this->closed) {
		$throwNew($IOException, "Stream closed"_s);
	}
}

StreamDecoder* StreamDecoder::forInputStreamReader($InputStream* in, Object$* lock, $String* charsetName) {
	$init(StreamDecoder);
	$useLocalCurrentObjectStackCache();
	$var($String, csn, charsetName);
	if (csn == nullptr) {
		$assign(csn, $nc($($Charset::defaultCharset()))->name());
	}
	try {
		return $new(StreamDecoder, in, lock, $($Charset::forName(csn)));
	} catch ($IllegalCharsetNameException& x) {
		$throwNew($UnsupportedEncodingException, csn);
	} catch ($UnsupportedCharsetException& x) {
		$throwNew($UnsupportedEncodingException, csn);
	}
	$shouldNotReachHere();
}

StreamDecoder* StreamDecoder::forInputStreamReader($InputStream* in, Object$* lock, $Charset* cs) {
	$init(StreamDecoder);
	return $new(StreamDecoder, in, lock, cs);
}

StreamDecoder* StreamDecoder::forInputStreamReader($InputStream* in, Object$* lock, $CharsetDecoder* dec) {
	$init(StreamDecoder);
	return $new(StreamDecoder, in, lock, dec);
}

StreamDecoder* StreamDecoder::forDecoder($ReadableByteChannel* ch, $CharsetDecoder* dec, int32_t minBufferCap) {
	$init(StreamDecoder);
	return $new(StreamDecoder, ch, dec, minBufferCap);
}

$String* StreamDecoder::getEncoding() {
	if (isOpen()) {
		return encodingName();
	}
	return nullptr;
}

int32_t StreamDecoder::read() {
	return read0();
}

int32_t StreamDecoder::read0() {
	$synchronized(this->lock) {
		if (this->haveLeftoverChar) {
			this->haveLeftoverChar = false;
			return this->leftoverChar;
		}
		$var($chars, cb, $new($chars, 2));
		int32_t n = read(cb, 0, 2);
		switch (n) {
		case -1:
			{
				return -1;
			}
		case 2:
			{
				this->leftoverChar = cb->get(1);
				this->haveLeftoverChar = true;
			}
		case 1:
			{
				return cb->get(0);
			}
		default:
			{
				if (!StreamDecoder::$assertionsDisabled) {
					$throwNew($AssertionError, n);
				}
				return -1;
			}
		}
	}
}

int32_t StreamDecoder::read($chars* cbuf, int32_t offset, int32_t length) {
	int32_t off = offset;
	int32_t len = length;
	$synchronized(this->lock) {
		ensureOpen();
		if ((off < 0) || (off > $nc(cbuf)->length) || (len < 0) || ((off + len) > $nc(cbuf)->length) || ((off + len) < 0)) {
			$throwNew($IndexOutOfBoundsException);
		}
		if (len == 0) {
			return 0;
		}
		int32_t n = 0;
		if (this->haveLeftoverChar) {
			$nc(cbuf)->set(off, this->leftoverChar);
			++off;
			--len;
			this->haveLeftoverChar = false;
			n = 1;
			if ((len == 0) || !implReady()) {
				return n;
			}
		}
		if (len == 1) {
			int32_t c = read0();
			if (c == -1) {
				return (n == 0) ? -1 : n;
			}
			$nc(cbuf)->set(off, (char16_t)c);
			return n + 1;
		}
		return n + implRead(cbuf, off, off + len);
	}
}

bool StreamDecoder::ready() {
	$synchronized(this->lock) {
		ensureOpen();
		return this->haveLeftoverChar || implReady();
	}
}

void StreamDecoder::close() {
	$synchronized(this->lock) {
		if (this->closed) {
			return;
		}
		{
			$var($Throwable, var$0, nullptr);
			try {
				implClose();
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				this->closed = true;
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
}

bool StreamDecoder::isOpen() {
	return !this->closed;
}

void StreamDecoder::init$($InputStream* in, Object$* lock, $Charset* cs) {
	$useLocalCurrentObjectStackCache();
	$init($CodingErrorAction);
	StreamDecoder::init$(in, lock, $($nc($($nc($($nc(cs)->newDecoder()))->onMalformedInput($CodingErrorAction::REPLACE)))->onUnmappableCharacter($CodingErrorAction::REPLACE)));
}

void StreamDecoder::init$($InputStream* in, Object$* lock, $CharsetDecoder* dec) {
	$Reader::init$(lock);
	this->haveLeftoverChar = false;
	$set(this, cs, $nc(dec)->charset());
	$set(this, decoder, dec);
	$set(this, in, in);
	$set(this, ch, nullptr);
	$set(this, bb, $ByteBuffer::allocate(StreamDecoder::DEFAULT_BYTE_BUFFER_SIZE));
	$nc(this->bb)->flip();
}

void StreamDecoder::init$($ReadableByteChannel* ch, $CharsetDecoder* dec, int32_t mbc) {
	$Reader::init$();
	this->haveLeftoverChar = false;
	$set(this, in, nullptr);
	$set(this, ch, ch);
	$set(this, decoder, dec);
	$set(this, cs, $nc(dec)->charset());
	$set(this, bb, $ByteBuffer::allocate(mbc < 0 ? StreamDecoder::DEFAULT_BYTE_BUFFER_SIZE : (mbc < StreamDecoder::MIN_BYTE_BUFFER_SIZE ? StreamDecoder::MIN_BYTE_BUFFER_SIZE : mbc)));
	$nc(this->bb)->flip();
}

int32_t StreamDecoder::readBytes() {
	$useLocalCurrentObjectStackCache();
	$nc(this->bb)->compact();
	{
		$var($Throwable, var$0, nullptr);
		int32_t var$2 = 0;
		bool return$1 = false;
		try {
			if (this->ch != nullptr) {
				int32_t n = $nc(this->ch)->read(this->bb);
				if (n < 0) {
					var$2 = n;
					return$1 = true;
					goto $finally;
				}
			} else {
				int32_t lim = $nc(this->bb)->limit();
				int32_t pos = $nc(this->bb)->position();
				if (!StreamDecoder::$assertionsDisabled && !(pos <= lim)) {
					$throwNew($AssertionError);
				}
				int32_t rem = (pos <= lim ? lim - pos : 0);
				$var($bytes, var$3, $cast($bytes, $nc(this->bb)->array()));
				int32_t n = $nc(this->in)->read(var$3, $nc(this->bb)->arrayOffset() + pos, rem);
				if (n < 0) {
					var$2 = n;
					return$1 = true;
					goto $finally;
				}
				if (n == 0) {
					$throwNew($IOException, "Underlying input stream returned zero bytes"_s);
				}
				if (!StreamDecoder::$assertionsDisabled && !(n <= rem)) {
					$throwNew($AssertionError, $of($$str({"n = "_s, $$str(n), ", rem = "_s, $$str(rem)})));
				}
				$nc(this->bb)->position(pos + n);
			}
		} catch ($Throwable& var$4) {
			$assign(var$0, var$4);
		} $finally: {
			$nc(this->bb)->flip();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	int32_t rem = $nc(this->bb)->remaining();
	if (!StreamDecoder::$assertionsDisabled && !(rem != 0)) {
		$throwNew($AssertionError, rem);
	}
	return rem;
}

int32_t StreamDecoder::implRead($chars* cbuf, int32_t off, int32_t end) {
	$useLocalCurrentObjectStackCache();
	if (!StreamDecoder::$assertionsDisabled && !(end - off > 1)) {
		$throwNew($AssertionError);
	}
	$var($CharBuffer, cb, $CharBuffer::wrap(cbuf, off, end - off));
	if ($nc(cb)->position() != 0) {
		$assign(cb, cb->slice());
	}
	bool eof = false;
	for (;;) {
		$var($CoderResult, cr, $nc(this->decoder)->decode(this->bb, cb, eof));
		if ($nc(cr)->isUnderflow()) {
			if (eof) {
				break;
			}
			if (!$nc(cb)->hasRemaining()) {
				break;
			}
			bool var$0 = ($nc(cb)->position() > 0);
			if (var$0 && !inReady()) {
				break;
			}
			int32_t n = readBytes();
			if (n < 0) {
				eof = true;
				bool var$1 = ($nc(cb)->position() == 0);
				if (var$1 && (!$nc(this->bb)->hasRemaining())) {
					break;
				}
				$nc(this->decoder)->reset();
			}
			continue;
		}
		if ($nc(cr)->isOverflow()) {
			if (!StreamDecoder::$assertionsDisabled && !($nc(cb)->position() > 0)) {
				$throwNew($AssertionError);
			}
			break;
		}
		$nc(cr)->throwException();
	}
	if (eof) {
		$nc(this->decoder)->reset();
	}
	if ($nc(cb)->position() == 0) {
		if (eof) {
			return -1;
		}
		if (!StreamDecoder::$assertionsDisabled) {
			$throwNew($AssertionError);
		}
	}
	return $nc(cb)->position();
}

$String* StreamDecoder::encodingName() {
	return (($instanceOf($HistoricallyNamedCharset, this->cs)) ? $nc(($cast($HistoricallyNamedCharset, this->cs)))->historicalName() : $nc(this->cs)->name());
}

bool StreamDecoder::inReady() {
	try {
		return (((this->in != nullptr) && ($nc(this->in)->available() > 0)) || ($instanceOf($FileChannel, this->ch)));
	} catch ($IOException& x) {
		return false;
	}
	$shouldNotReachHere();
}

bool StreamDecoder::implReady() {
	bool var$0 = $nc(this->bb)->hasRemaining();
	return var$0 || inReady();
}

void StreamDecoder::implClose() {
	if (this->ch != nullptr) {
		$nc(this->ch)->close();
	} else {
		$nc(this->in)->close();
	}
}

void clinit$StreamDecoder($Class* class$) {
	StreamDecoder::$assertionsDisabled = !StreamDecoder::class$->desiredAssertionStatus();
}

StreamDecoder::StreamDecoder() {
}

$Class* StreamDecoder::load$($String* name, bool initialize) {
	$loadClass(StreamDecoder, name, initialize, &_StreamDecoder_ClassInfo_, clinit$StreamDecoder, allocate$StreamDecoder);
	return class$;
}

$Class* StreamDecoder::class$ = nullptr;

		} // cs
	} // nio
} // sun