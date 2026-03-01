#include <sun/nio/cs/StreamEncoder.h>

#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <java/io/UnsupportedEncodingException.h>
#include <java/io/Writer.h>
#include <java/lang/AssertionError.h>
#include <java/lang/IndexOutOfBoundsException.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/CharBuffer.h>
#include <java/nio/channels/WritableByteChannel.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/CharsetEncoder.h>
#include <java/nio/charset/CoderResult.h>
#include <java/nio/charset/CodingErrorAction.h>
#include <java/nio/charset/IllegalCharsetNameException.h>
#include <java/nio/charset/UnsupportedCharsetException.h>
#include <sun/nio/cs/HistoricallyNamedCharset.h>
#include <jcpp.h>

#undef DEFAULT_BYTE_BUFFER_SIZE
#undef REPLACE

using $IOException = ::java::io::IOException;
using $OutputStream = ::java::io::OutputStream;
using $UnsupportedEncodingException = ::java::io::UnsupportedEncodingException;
using $Writer = ::java::io::Writer;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IndexOutOfBoundsException = ::java::lang::IndexOutOfBoundsException;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $CharBuffer = ::java::nio::CharBuffer;
using $WritableByteChannel = ::java::nio::channels::WritableByteChannel;
using $Charset = ::java::nio::charset::Charset;
using $CharsetEncoder = ::java::nio::charset::CharsetEncoder;
using $CoderResult = ::java::nio::charset::CoderResult;
using $CodingErrorAction = ::java::nio::charset::CodingErrorAction;
using $IllegalCharsetNameException = ::java::nio::charset::IllegalCharsetNameException;
using $UnsupportedCharsetException = ::java::nio::charset::UnsupportedCharsetException;
using $HistoricallyNamedCharset = ::sun::nio::cs::HistoricallyNamedCharset;

namespace sun {
	namespace nio {
		namespace cs {

$FieldInfo _StreamEncoder_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(StreamEncoder, $assertionsDisabled)},
	{"DEFAULT_BYTE_BUFFER_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StreamEncoder, DEFAULT_BYTE_BUFFER_SIZE)},
	{"closed", "Z", nullptr, $PRIVATE | $VOLATILE, $field(StreamEncoder, closed)},
	{"cs", "Ljava/nio/charset/Charset;", nullptr, $PRIVATE | $FINAL, $field(StreamEncoder, cs)},
	{"encoder", "Ljava/nio/charset/CharsetEncoder;", nullptr, $PRIVATE | $FINAL, $field(StreamEncoder, encoder)},
	{"bb", "Ljava/nio/ByteBuffer;", nullptr, $PRIVATE | $FINAL, $field(StreamEncoder, bb)},
	{"out", "Ljava/io/OutputStream;", nullptr, $PRIVATE | $FINAL, $field(StreamEncoder, out)},
	{"ch", "Ljava/nio/channels/WritableByteChannel;", nullptr, $PRIVATE | $FINAL, $field(StreamEncoder, ch)},
	{"haveLeftoverChar", "Z", nullptr, $PRIVATE, $field(StreamEncoder, haveLeftoverChar)},
	{"leftoverChar", "C", nullptr, $PRIVATE, $field(StreamEncoder, leftoverChar)},
	{"lcb", "Ljava/nio/CharBuffer;", nullptr, $PRIVATE, $field(StreamEncoder, lcb)},
	{}
};

$MethodInfo _StreamEncoder_MethodInfo_[] = {
	{"<init>", "(Ljava/io/OutputStream;Ljava/lang/Object;Ljava/nio/charset/Charset;)V", nullptr, $PRIVATE, $method(StreamEncoder, init$, void, $OutputStream*, Object$*, $Charset*)},
	{"<init>", "(Ljava/io/OutputStream;Ljava/lang/Object;Ljava/nio/charset/CharsetEncoder;)V", nullptr, $PRIVATE, $method(StreamEncoder, init$, void, $OutputStream*, Object$*, $CharsetEncoder*)},
	{"<init>", "(Ljava/nio/channels/WritableByteChannel;Ljava/nio/charset/CharsetEncoder;I)V", nullptr, $PRIVATE, $method(StreamEncoder, init$, void, $WritableByteChannel*, $CharsetEncoder*, int32_t)},
	{"close", "()V", nullptr, $PUBLIC, $virtualMethod(StreamEncoder, close, void), "java.io.IOException"},
	{"encodingName", "()Ljava/lang/String;", nullptr, 0, $virtualMethod(StreamEncoder, encodingName, $String*)},
	{"ensureOpen", "()V", nullptr, $PRIVATE, $method(StreamEncoder, ensureOpen, void), "java.io.IOException"},
	{"flush", "()V", nullptr, $PUBLIC, $virtualMethod(StreamEncoder, flush, void), "java.io.IOException"},
	{"flushBuffer", "()V", nullptr, $PUBLIC, $virtualMethod(StreamEncoder, flushBuffer, void), "java.io.IOException"},
	{"flushLeftoverChar", "(Ljava/nio/CharBuffer;Z)V", nullptr, $PRIVATE, $method(StreamEncoder, flushLeftoverChar, void, $CharBuffer*, bool), "java.io.IOException"},
	{"forEncoder", "(Ljava/nio/channels/WritableByteChannel;Ljava/nio/charset/CharsetEncoder;I)Lsun/nio/cs/StreamEncoder;", nullptr, $PUBLIC | $STATIC, $staticMethod(StreamEncoder, forEncoder, StreamEncoder*, $WritableByteChannel*, $CharsetEncoder*, int32_t)},
	{"forOutputStreamWriter", "(Ljava/io/OutputStream;Ljava/lang/Object;Ljava/lang/String;)Lsun/nio/cs/StreamEncoder;", nullptr, $PUBLIC | $STATIC, $staticMethod(StreamEncoder, forOutputStreamWriter, StreamEncoder*, $OutputStream*, Object$*, $String*), "java.io.UnsupportedEncodingException"},
	{"forOutputStreamWriter", "(Ljava/io/OutputStream;Ljava/lang/Object;Ljava/nio/charset/Charset;)Lsun/nio/cs/StreamEncoder;", nullptr, $PUBLIC | $STATIC, $staticMethod(StreamEncoder, forOutputStreamWriter, StreamEncoder*, $OutputStream*, Object$*, $Charset*)},
	{"forOutputStreamWriter", "(Ljava/io/OutputStream;Ljava/lang/Object;Ljava/nio/charset/CharsetEncoder;)Lsun/nio/cs/StreamEncoder;", nullptr, $PUBLIC | $STATIC, $staticMethod(StreamEncoder, forOutputStreamWriter, StreamEncoder*, $OutputStream*, Object$*, $CharsetEncoder*)},
	{"getEncoding", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(StreamEncoder, getEncoding, $String*)},
	{"implClose", "()V", nullptr, 0, $virtualMethod(StreamEncoder, implClose, void), "java.io.IOException"},
	{"implFlush", "()V", nullptr, 0, $virtualMethod(StreamEncoder, implFlush, void), "java.io.IOException"},
	{"implFlushBuffer", "()V", nullptr, 0, $virtualMethod(StreamEncoder, implFlushBuffer, void), "java.io.IOException"},
	{"implWrite", "([CII)V", nullptr, 0, $virtualMethod(StreamEncoder, implWrite, void, $chars*, int32_t, int32_t), "java.io.IOException"},
	{"implWrite", "(Ljava/nio/CharBuffer;)V", nullptr, 0, $virtualMethod(StreamEncoder, implWrite, void, $CharBuffer*), "java.io.IOException"},
	{"isOpen", "()Z", nullptr, $PRIVATE, $method(StreamEncoder, isOpen, bool)},
	{"write", "(I)V", nullptr, $PUBLIC, $virtualMethod(StreamEncoder, write, void, int32_t), "java.io.IOException"},
	{"write", "([CII)V", nullptr, $PUBLIC, $virtualMethod(StreamEncoder, write, void, $chars*, int32_t, int32_t), "java.io.IOException"},
	{"write", "(Ljava/lang/String;II)V", nullptr, $PUBLIC, $virtualMethod(StreamEncoder, write, void, $String*, int32_t, int32_t), "java.io.IOException"},
	{"write", "(Ljava/nio/CharBuffer;)V", nullptr, $PUBLIC, $virtualMethod(StreamEncoder, write, void, $CharBuffer*), "java.io.IOException"},
	{"writeBytes", "()V", nullptr, $PRIVATE, $method(StreamEncoder, writeBytes, void), "java.io.IOException"},
	{}
};

$ClassInfo _StreamEncoder_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.nio.cs.StreamEncoder",
	"java.io.Writer",
	nullptr,
	_StreamEncoder_FieldInfo_,
	_StreamEncoder_MethodInfo_
};

$Object* allocate$StreamEncoder($Class* clazz) {
	return $of($alloc(StreamEncoder));
}

bool StreamEncoder::$assertionsDisabled = false;

void StreamEncoder::ensureOpen() {
	if (this->closed) {
		$throwNew($IOException, "Stream closed"_s);
	}
}

StreamEncoder* StreamEncoder::forOutputStreamWriter($OutputStream* out, Object$* lock, $String* charsetName) {
	$init(StreamEncoder);
	$useLocalCurrentObjectStackCache();
	$var($String, csn, charsetName);
	if (csn == nullptr) {
		$assign(csn, $nc($($Charset::defaultCharset()))->name());
	}
	try {
		return $new(StreamEncoder, out, lock, $($Charset::forName(csn)));
	} catch ($IllegalCharsetNameException& x) {
		$throwNew($UnsupportedEncodingException, csn);
	} catch ($UnsupportedCharsetException& x) {
		$throwNew($UnsupportedEncodingException, csn);
	}
	$shouldNotReachHere();
}

StreamEncoder* StreamEncoder::forOutputStreamWriter($OutputStream* out, Object$* lock, $Charset* cs) {
	$init(StreamEncoder);
	return $new(StreamEncoder, out, lock, cs);
}

StreamEncoder* StreamEncoder::forOutputStreamWriter($OutputStream* out, Object$* lock, $CharsetEncoder* enc) {
	$init(StreamEncoder);
	return $new(StreamEncoder, out, lock, enc);
}

StreamEncoder* StreamEncoder::forEncoder($WritableByteChannel* ch, $CharsetEncoder* enc, int32_t minBufferCap) {
	$init(StreamEncoder);
	return $new(StreamEncoder, ch, enc, minBufferCap);
}

$String* StreamEncoder::getEncoding() {
	if (isOpen()) {
		return encodingName();
	}
	return nullptr;
}

void StreamEncoder::flushBuffer() {
	$synchronized(this->lock) {
		if (isOpen()) {
			implFlushBuffer();
		} else {
			$throwNew($IOException, "Stream closed"_s);
		}
	}
}

void StreamEncoder::write(int32_t c) {
	$var($chars, cbuf, $new($chars, 1));
	cbuf->set(0, (char16_t)c);
	write(cbuf, 0, 1);
}

void StreamEncoder::write($chars* cbuf, int32_t off, int32_t len) {
	$synchronized(this->lock) {
		ensureOpen();
		if ((off < 0) || (off > $nc(cbuf)->length) || (len < 0) || ((off + len) > $nc(cbuf)->length) || ((off + len) < 0)) {
			$throwNew($IndexOutOfBoundsException);
		} else if (len == 0) {
			return;
		}
		implWrite(cbuf, off, len);
	}
}

void StreamEncoder::write($String* str, int32_t off, int32_t len) {
	if (len < 0) {
		$throwNew($IndexOutOfBoundsException);
	}
	$var($chars, cbuf, $new($chars, len));
	$nc(str)->getChars(off, off + len, cbuf, 0);
	write(cbuf, 0, len);
}

void StreamEncoder::write($CharBuffer* cb) {
	int32_t position = $nc(cb)->position();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$synchronized(this->lock) {
				ensureOpen();
				implWrite(cb);
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			cb->position(position);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void StreamEncoder::flush() {
	$synchronized(this->lock) {
		ensureOpen();
		implFlush();
	}
}

void StreamEncoder::close() {
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

bool StreamEncoder::isOpen() {
	return !this->closed;
}

void StreamEncoder::init$($OutputStream* out, Object$* lock, $Charset* cs) {
	$useLocalCurrentObjectStackCache();
	$init($CodingErrorAction);
	StreamEncoder::init$(out, lock, $($nc($($nc($($nc(cs)->newEncoder()))->onMalformedInput($CodingErrorAction::REPLACE)))->onUnmappableCharacter($CodingErrorAction::REPLACE)));
}

void StreamEncoder::init$($OutputStream* out, Object$* lock, $CharsetEncoder* enc) {
	$Writer::init$(lock);
	this->haveLeftoverChar = false;
	$set(this, lcb, nullptr);
	$set(this, out, out);
	$set(this, ch, nullptr);
	$set(this, cs, $nc(enc)->charset());
	$set(this, encoder, enc);
	$set(this, bb, $ByteBuffer::allocate(StreamEncoder::DEFAULT_BYTE_BUFFER_SIZE));
}

void StreamEncoder::init$($WritableByteChannel* ch, $CharsetEncoder* enc, int32_t mbc) {
	$Writer::init$();
	this->haveLeftoverChar = false;
	$set(this, lcb, nullptr);
	$set(this, out, nullptr);
	$set(this, ch, ch);
	$set(this, cs, $nc(enc)->charset());
	$set(this, encoder, enc);
	$set(this, bb, $ByteBuffer::allocate(mbc < 0 ? StreamEncoder::DEFAULT_BYTE_BUFFER_SIZE : mbc));
}

void StreamEncoder::writeBytes() {
	$nc(this->bb)->flip();
	int32_t lim = $nc(this->bb)->limit();
	int32_t pos = $nc(this->bb)->position();
	if (!StreamEncoder::$assertionsDisabled && !(pos <= lim)) {
		$throwNew($AssertionError);
	}
	int32_t rem = (pos <= lim ? lim - pos : 0);
	if (rem > 0) {
		if (this->ch != nullptr) {
			int32_t wc = $nc(this->ch)->write(this->bb);
			if (!StreamEncoder::$assertionsDisabled && !(wc == rem)) {
				$throwNew($AssertionError, rem);
			}
		} else {
			$var($bytes, var$0, $cast($bytes, $nc(this->bb)->array()));
			$nc(this->out)->write(var$0, $nc(this->bb)->arrayOffset() + pos, rem);
		}
	}
	$nc(this->bb)->clear();
}

void StreamEncoder::flushLeftoverChar($CharBuffer* cb, bool endOfInput) {
	$useLocalCurrentObjectStackCache();
	if (!this->haveLeftoverChar && !endOfInput) {
		return;
	}
	if (this->lcb == nullptr) {
		$set(this, lcb, $CharBuffer::allocate(2));
	} else {
		$nc(this->lcb)->clear();
	}
	if (this->haveLeftoverChar) {
		$nc(this->lcb)->put(this->leftoverChar);
	}
	if ((cb != nullptr) && cb->hasRemaining()) {
		$nc(this->lcb)->put(cb->get());
	}
	$nc(this->lcb)->flip();
	while ($nc(this->lcb)->hasRemaining() || endOfInput) {
		$var($CoderResult, cr, $nc(this->encoder)->encode(this->lcb, this->bb, endOfInput));
		if ($nc(cr)->isUnderflow()) {
			if ($nc(this->lcb)->hasRemaining()) {
				this->leftoverChar = $nc(this->lcb)->get();
				if (cb != nullptr && cb->hasRemaining()) {
					$nc(this->lcb)->clear();
					$nc($($nc($($nc(this->lcb)->put(this->leftoverChar)))->put(cb->get())))->flip();
					continue;
				}
				return;
			}
			break;
		}
		if ($nc(cr)->isOverflow()) {
			if (!StreamEncoder::$assertionsDisabled && !($nc(this->bb)->position() > 0)) {
				$throwNew($AssertionError);
			}
			writeBytes();
			continue;
		}
		$nc(cr)->throwException();
	}
	this->haveLeftoverChar = false;
}

void StreamEncoder::implWrite($chars* cbuf, int32_t off, int32_t len) {
	$var($CharBuffer, cb, $CharBuffer::wrap(cbuf, off, len));
	implWrite(cb);
}

void StreamEncoder::implWrite($CharBuffer* cb) {
	$useLocalCurrentObjectStackCache();
	if (this->haveLeftoverChar) {
		flushLeftoverChar(cb, false);
	}
	while ($nc(cb)->hasRemaining()) {
		$var($CoderResult, cr, $nc(this->encoder)->encode(cb, this->bb, false));
		if ($nc(cr)->isUnderflow()) {
			if (!StreamEncoder::$assertionsDisabled && !(cb->remaining() <= 1)) {
				$throwNew($AssertionError, cb->remaining());
			}
			if (cb->remaining() == 1) {
				this->haveLeftoverChar = true;
				this->leftoverChar = cb->get();
			}
			break;
		}
		if ($nc(cr)->isOverflow()) {
			if (!StreamEncoder::$assertionsDisabled && !($nc(this->bb)->position() > 0)) {
				$throwNew($AssertionError);
			}
			writeBytes();
			continue;
		}
		$nc(cr)->throwException();
	}
}

void StreamEncoder::implFlushBuffer() {
	if ($nc(this->bb)->position() > 0) {
		writeBytes();
	}
}

void StreamEncoder::implFlush() {
	implFlushBuffer();
	if (this->out != nullptr) {
		$nc(this->out)->flush();
	}
}

void StreamEncoder::implClose() {
	$useLocalCurrentObjectStackCache();
	flushLeftoverChar(nullptr, true);
	try {
		for (;;) {
			$var($CoderResult, cr, $nc(this->encoder)->flush(this->bb));
			if ($nc(cr)->isUnderflow()) {
				break;
			}
			if ($nc(cr)->isOverflow()) {
				if (!StreamEncoder::$assertionsDisabled && !($nc(this->bb)->position() > 0)) {
					$throwNew($AssertionError);
				}
				writeBytes();
				continue;
			}
			$nc(cr)->throwException();
		}
		if ($nc(this->bb)->position() > 0) {
			writeBytes();
		}
		if (this->ch != nullptr) {
			$nc(this->ch)->close();
		} else {
			{
				$var($Throwable, var$0, nullptr);
				try {
					$nc(this->out)->flush();
				} catch ($Throwable& var$1) {
					$assign(var$0, var$1);
				} /*finally*/ {
					$nc(this->out)->close();
				}
				if (var$0 != nullptr) {
					$throw(var$0);
				}
			}
		}
	} catch ($IOException& x) {
		$nc(this->encoder)->reset();
		$throw(x);
	}
}

$String* StreamEncoder::encodingName() {
	return (($instanceOf($HistoricallyNamedCharset, this->cs)) ? $nc(($cast($HistoricallyNamedCharset, this->cs)))->historicalName() : $nc(this->cs)->name());
}

void clinit$StreamEncoder($Class* class$) {
	StreamEncoder::$assertionsDisabled = !StreamEncoder::class$->desiredAssertionStatus();
}

StreamEncoder::StreamEncoder() {
}

$Class* StreamEncoder::load$($String* name, bool initialize) {
	$loadClass(StreamEncoder, name, initialize, &_StreamEncoder_ClassInfo_, clinit$StreamEncoder, allocate$StreamEncoder);
	return class$;
}

$Class* StreamEncoder::class$ = nullptr;

		} // cs
	} // nio
} // sun