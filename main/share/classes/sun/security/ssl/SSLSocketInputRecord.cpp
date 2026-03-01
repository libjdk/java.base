#include <sun/security/ssl/SSLSocketInputRecord.h>

#include <java/io/EOFException.h>
#include <java/io/InputStream.h>
#include <java/io/InterruptedIOException.h>
#include <java/io/OutputStream.h>
#include <java/nio/ByteBuffer.h>
#include <java/security/GeneralSecurityException.h>
#include <java/util/ArrayList.h>
#include <javax/crypto/BadPaddingException.h>
#include <javax/net/ssl/SSLException.h>
#include <javax/net/ssl/SSLHandshakeException.h>
#include <javax/net/ssl/SSLProtocolException.h>
#include <sun/security/ssl/ContentType.h>
#include <sun/security/ssl/HandshakeHash.h>
#include <sun/security/ssl/InputRecord.h>
#include <sun/security/ssl/Plaintext.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/Record.h>
#include <sun/security/ssl/SSLCipher$SSLReadCipher.h>
#include <sun/security/ssl/SSLConfiguration.h>
#include <sun/security/ssl/SSLHandshake.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/SSLRecord.h>
#include <jcpp.h>

#undef ALERT
#undef HANDSHAKE

using $ByteBufferArray = $Array<::java::nio::ByteBuffer>;
using $PlaintextArray = $Array<::sun::security::ssl::Plaintext>;
using $EOFException = ::java::io::EOFException;
using $InputStream = ::java::io::InputStream;
using $InterruptedIOException = ::java::io::InterruptedIOException;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $ArrayList = ::java::util::ArrayList;
using $BadPaddingException = ::javax::crypto::BadPaddingException;
using $SSLException = ::javax::net::ssl::SSLException;
using $SSLHandshakeException = ::javax::net::ssl::SSLHandshakeException;
using $SSLProtocolException = ::javax::net::ssl::SSLProtocolException;
using $ContentType = ::sun::security::ssl::ContentType;
using $HandshakeHash = ::sun::security::ssl::HandshakeHash;
using $InputRecord = ::sun::security::ssl::InputRecord;
using $Plaintext = ::sun::security::ssl::Plaintext;
using $ProtocolVersion = ::sun::security::ssl::ProtocolVersion;
using $Record = ::sun::security::ssl::Record;
using $SSLCipher$SSLReadCipher = ::sun::security::ssl::SSLCipher$SSLReadCipher;
using $SSLConfiguration = ::sun::security::ssl::SSLConfiguration;
using $SSLHandshake = ::sun::security::ssl::SSLHandshake;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $SSLRecord = ::sun::security::ssl::SSLRecord;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _SSLSocketInputRecord_FieldInfo_[] = {
	{"is", "Ljava/io/InputStream;", nullptr, $PRIVATE, $field(SSLSocketInputRecord, is)},
	{"os", "Ljava/io/OutputStream;", nullptr, $PRIVATE, $field(SSLSocketInputRecord, os)},
	{"header", "[B", nullptr, $PRIVATE | $FINAL, $field(SSLSocketInputRecord, header)},
	{"headerOff", "I", nullptr, $PRIVATE, $field(SSLSocketInputRecord, headerOff)},
	{"recordBody", "Ljava/nio/ByteBuffer;", nullptr, $PRIVATE, $field(SSLSocketInputRecord, recordBody)},
	{"formatVerified", "Z", nullptr, $PRIVATE, $field(SSLSocketInputRecord, formatVerified)},
	{"handshakeBuffer", "Ljava/nio/ByteBuffer;", nullptr, $PRIVATE, $field(SSLSocketInputRecord, handshakeBuffer)},
	{}
};

$MethodInfo _SSLSocketInputRecord_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Lsun/security/ssl/HandshakeHash;)V", nullptr, 0, $method(SSLSocketInputRecord, init$, void, $HandshakeHash*)},
	{"bytesInCompletePacket", "()I", nullptr, 0, $virtualMethod(SSLSocketInputRecord, bytesInCompletePacket, int32_t), "java.io.IOException"},
	{"decode", "([Ljava/nio/ByteBuffer;II)[Lsun/security/ssl/Plaintext;", nullptr, 0, $virtualMethod(SSLSocketInputRecord, decode, $PlaintextArray*, $ByteBufferArray*, int32_t, int32_t), "java.io.IOException,javax.crypto.BadPaddingException"},
	{"decodeInputRecord", "()[Lsun/security/ssl/Plaintext;", nullptr, $PRIVATE, $method(SSLSocketInputRecord, decodeInputRecord, $PlaintextArray*), "java.io.IOException,javax.crypto.BadPaddingException"},
	{"deplete", "(Z)V", nullptr, 0, $method(SSLSocketInputRecord, deplete, void, bool), "java.io.IOException"},
	{"handleUnknownRecord", "()[Lsun/security/ssl/Plaintext;", nullptr, $PRIVATE, $method(SSLSocketInputRecord, handleUnknownRecord, $PlaintextArray*), "java.io.IOException,javax.crypto.BadPaddingException"},
	{"read", "(Ljava/io/InputStream;[BII)I", nullptr, $PRIVATE | $STATIC, $staticMethod(SSLSocketInputRecord, read, int32_t, $InputStream*, $bytes*, int32_t, int32_t), "java.io.IOException"},
	{"readFully", "(I)I", nullptr, $PRIVATE, $method(SSLSocketInputRecord, readFully, int32_t, int32_t), "java.io.IOException"},
	{"readHeader", "()I", nullptr, $PRIVATE, $method(SSLSocketInputRecord, readHeader, int32_t), "java.io.IOException"},
	{"setDeliverStream", "(Ljava/io/OutputStream;)V", nullptr, 0, $virtualMethod(SSLSocketInputRecord, setDeliverStream, void, $OutputStream*)},
	{"setReceiverStream", "(Ljava/io/InputStream;)V", nullptr, 0, $virtualMethod(SSLSocketInputRecord, setReceiverStream, void, $InputStream*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _SSLSocketInputRecord_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.SSLSocketInputRecord",
	"sun.security.ssl.InputRecord",
	"sun.security.ssl.SSLRecord",
	_SSLSocketInputRecord_FieldInfo_,
	_SSLSocketInputRecord_MethodInfo_
};

$Object* allocate$SSLSocketInputRecord($Class* clazz) {
	return $of($alloc(SSLSocketInputRecord));
}

int32_t SSLSocketInputRecord::hashCode() {
	 return this->$InputRecord::hashCode();
}

bool SSLSocketInputRecord::equals(Object$* obj) {
	 return this->$InputRecord::equals(obj);
}

$Object* SSLSocketInputRecord::clone() {
	 return this->$InputRecord::clone();
}

$String* SSLSocketInputRecord::toString() {
	 return this->$InputRecord::toString();
}

void SSLSocketInputRecord::finalize() {
	this->$InputRecord::finalize();
}

void SSLSocketInputRecord::init$($HandshakeHash* handshakeHash) {
	$InputRecord::init$(handshakeHash, $($SSLCipher$SSLReadCipher::nullTlsReadCipher()));
	$set(this, is, nullptr);
	$set(this, os, nullptr);
	$set(this, header, $new($bytes, $SSLRecord::headerSize));
	this->headerOff = 0;
	$set(this, recordBody, $ByteBuffer::allocate(1024));
	this->formatVerified = false;
	$set(this, handshakeBuffer, nullptr);
}

int32_t SSLSocketInputRecord::bytesInCompletePacket() {
	$useLocalCurrentObjectStackCache();
	try {
		readHeader();
	} catch ($EOFException& eofe) {
		return -1;
	}
	int8_t byteZero = $nc(this->header)->get(0);
	int32_t len = 0;
	$init($ContentType);
	if (this->formatVerified || (byteZero == $ContentType::HANDSHAKE->id) || (byteZero == $ContentType::ALERT->id)) {
		if (!$ProtocolVersion::isNegotiable($nc(this->header)->get(1), $nc(this->header)->get(2), false, false)) {
			$throwNew($SSLException, $$str({"Unrecognized record version "_s, $($ProtocolVersion::nameOf($nc(this->header)->get(1), $nc(this->header)->get(2))), " , plaintext connection?"_s}));
		}
		this->formatVerified = true;
		len = (((int32_t)($nc(this->header)->get(3) & (uint32_t)255)) << 8) + ((int32_t)($nc(this->header)->get(4) & (uint32_t)255)) + $SSLRecord::headerSize;
	} else {
		bool isShort = (((int32_t)(byteZero & (uint32_t)128)) != 0);
		if (isShort && (($nc(this->header)->get(2) == 1) || ($nc(this->header)->get(2) == 4))) {
			if (!$ProtocolVersion::isNegotiable($nc(this->header)->get(3), $nc(this->header)->get(4), false, false)) {
				$throwNew($SSLException, $$str({"Unrecognized record version "_s, $($ProtocolVersion::nameOf($nc(this->header)->get(3), $nc(this->header)->get(4))), " , plaintext connection?"_s}));
			}
			len = (((int32_t)(byteZero & (uint32_t)127)) << 8) + ((int32_t)($nc(this->header)->get(1) & (uint32_t)255)) + 2;
		} else {
			$throwNew($SSLException, "Unrecognized SSL message, plaintext connection?"_s);
		}
	}
	return len;
}

$PlaintextArray* SSLSocketInputRecord::decode($ByteBufferArray* srcs, int32_t srcsOffset, int32_t srcsLength) {
	$useLocalCurrentObjectStackCache();
	if (this->isClosed$) {
		return nullptr;
	}
	readHeader();
	$var($PlaintextArray, plaintext, nullptr);
	bool cleanInBuffer = true;
	{
		$var($Throwable, var$0, nullptr);
		try {
			try {
				if (!this->formatVerified) {
					this->formatVerified = true;
					$init($ContentType);
					if (($nc(this->header)->get(0) != $ContentType::HANDSHAKE->id) && ($nc(this->header)->get(0) != $ContentType::ALERT->id)) {
						$assign(plaintext, handleUnknownRecord());
					}
				}
				if (plaintext == nullptr) {
					$assign(plaintext, decodeInputRecord());
				}
			} catch ($InterruptedIOException& e) {
				cleanInBuffer = false;
				$throw(e);
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			if (cleanInBuffer) {
				this->headerOff = 0;
				$nc(this->recordBody)->clear();
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	return plaintext;
}

void SSLSocketInputRecord::setReceiverStream($InputStream* inputStream) {
	$set(this, is, inputStream);
}

void SSLSocketInputRecord::setDeliverStream($OutputStream* outputStream) {
	$set(this, os, outputStream);
}

$PlaintextArray* SSLSocketInputRecord::decodeInputRecord() {
	$useLocalCurrentObjectStackCache();
	int8_t contentType = $nc(this->header)->get(0);
	int8_t majorVersion = $nc(this->header)->get(1);
	int8_t minorVersion = $nc(this->header)->get(2);
	int32_t contentLen = (((int32_t)($nc(this->header)->get(3) & (uint32_t)255)) << 8) + ((int32_t)($nc(this->header)->get(4) & (uint32_t)255));
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("record"_s)) {
		$var($String, var$2, $$str({"READ: "_s, $($ProtocolVersion::nameOf(majorVersion, minorVersion)), " "_s}));
		$var($String, var$1, $$concat(var$2, $($ContentType::nameOf(contentType))));
		$var($String, var$0, $$concat(var$1, ", length = "_s));
		$SSLLogger::fine($$concat(var$0, $$str(contentLen)), $$new($ObjectArray, 0));
	}
	if (contentLen < 0 || contentLen > $SSLRecord::maxLargeRecordSize - $SSLRecord::headerSize) {
		$throwNew($SSLProtocolException, $$str({"Bad input record size, TLSCiphertext.length = "_s, $$str(contentLen)}));
	}
	if ($nc(this->recordBody)->position() == 0) {
		if ($nc(this->recordBody)->capacity() < contentLen) {
			$set(this, recordBody, $ByteBuffer::allocate(contentLen));
		}
		$nc(this->recordBody)->limit(contentLen);
	} else {
		contentLen = $nc(this->recordBody)->remaining();
	}
	readFully(contentLen);
	$nc(this->recordBody)->flip();
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("record"_s)) {
		$var($String, var$5, $$str({"READ: "_s, $($ProtocolVersion::nameOf(majorVersion, minorVersion)), " "_s}));
		$var($String, var$4, $$concat(var$5, $($ContentType::nameOf(contentType))));
		$var($String, var$3, $$concat(var$4, ", length = "_s));
		$SSLLogger::fine($$concat(var$3, $$str($nc(this->recordBody)->remaining())), $$new($ObjectArray, 0));
	}
	$var($ByteBuffer, fragment, nullptr);
	try {
		$var($Plaintext, plaintext, $nc(this->readCipher)->decrypt(contentType, this->recordBody, nullptr));
		$assign(fragment, $nc(plaintext)->fragment);
		contentType = plaintext->contentType;
	} catch ($BadPaddingException& bpe) {
		$throw(bpe);
	} catch ($GeneralSecurityException& gse) {
		$throw($cast($SSLProtocolException, $(($$new($SSLProtocolException, "Unexpected exception"_s))->initCause(gse))));
	}
	$init($ContentType);
	if (contentType != $ContentType::HANDSHAKE->id && this->handshakeBuffer != nullptr && $nc(this->handshakeBuffer)->hasRemaining()) {
		$throwNew($SSLProtocolException, $$str({"Expecting a handshake fragment, but received "_s, $($ContentType::nameOf(contentType))}));
	}
	if (contentType == $ContentType::HANDSHAKE->id) {
		$var($ByteBuffer, handshakeFrag, fragment);
		if ((this->handshakeBuffer != nullptr) && ($nc(this->handshakeBuffer)->remaining() != 0)) {
			int32_t var$6 = $nc(this->handshakeBuffer)->remaining();
			$var($ByteBuffer, bb, $ByteBuffer::wrap($$new($bytes, var$6 + $nc(fragment)->remaining())));
			$nc(bb)->put(this->handshakeBuffer);
			bb->put(fragment);
			$assign(handshakeFrag, bb->rewind());
			$set(this, handshakeBuffer, nullptr);
		}
		$var($ArrayList, plaintexts, $new($ArrayList, 5));
		while ($nc(handshakeFrag)->hasRemaining()) {
			int32_t remaining = handshakeFrag->remaining();
			if (remaining < $SSLRecord::handshakeHeaderSize) {
				$set(this, handshakeBuffer, $ByteBuffer::wrap($$new($bytes, remaining)));
				$nc(this->handshakeBuffer)->put(handshakeFrag);
				$nc(this->handshakeBuffer)->rewind();
				break;
			}
			handshakeFrag->mark();
			int8_t handshakeType = handshakeFrag->get();
			if (!$SSLHandshake::isKnown(handshakeType)) {
				$throwNew($SSLProtocolException, $$str({"Unknown handshake type size, Handshake.msg_type = "_s, $$str(((int32_t)(handshakeType & (uint32_t)255)))}));
			}
			int32_t handshakeBodyLen = $Record::getInt24(handshakeFrag);
			$init($SSLConfiguration);
			if (handshakeBodyLen > $SSLConfiguration::maxHandshakeMessageSize) {
				$throwNew($SSLProtocolException, $$str({"The size of the handshake message ("_s, $$str(handshakeBodyLen), ") exceeds the maximum allowed size ("_s, $$str($SSLConfiguration::maxHandshakeMessageSize), ")"_s}));
			}
			handshakeFrag->reset();
			int32_t handshakeMessageLen = $SSLRecord::handshakeHeaderSize + handshakeBodyLen;
			if (remaining < handshakeMessageLen) {
				$set(this, handshakeBuffer, $ByteBuffer::wrap($$new($bytes, remaining)));
				$nc(this->handshakeBuffer)->put(handshakeFrag);
				$nc(this->handshakeBuffer)->rewind();
				break;
			}
			if (remaining == handshakeMessageLen) {
				if ($nc(this->handshakeHash)->isHashable(handshakeType)) {
					$nc(this->handshakeHash)->receive(handshakeFrag);
				}
				plaintexts->add($$new($Plaintext, contentType, majorVersion, minorVersion, -1, -1, handshakeFrag));
				break;
			} else {
				int32_t fragPos = handshakeFrag->position();
				int32_t fragLim = handshakeFrag->limit();
				int32_t nextPos = fragPos + handshakeMessageLen;
				handshakeFrag->limit(nextPos);
				if ($nc(this->handshakeHash)->isHashable(handshakeType)) {
					$nc(this->handshakeHash)->receive(handshakeFrag);
				}
				plaintexts->add($$new($Plaintext, contentType, majorVersion, minorVersion, -1, -1, $(handshakeFrag->slice())));
				handshakeFrag->position(nextPos);
				handshakeFrag->limit(fragLim);
			}
		}
		return $fcast($PlaintextArray, plaintexts->toArray($$new($PlaintextArray, 0)));
	}
	return $new($PlaintextArray, {$$new($Plaintext, contentType, majorVersion, minorVersion, -1, -1, fragment)});
}

$PlaintextArray* SSLSocketInputRecord::handleUnknownRecord() {
	$useLocalCurrentObjectStackCache();
	int8_t firstByte = $nc(this->header)->get(0);
	int8_t thirdByte = $nc(this->header)->get(2);
	if ((((int32_t)(firstByte & (uint32_t)128)) != 0) && (thirdByte == 1)) {
		$init($ProtocolVersion);
		if (this->helloVersion != $ProtocolVersion::SSL20Hello) {
			$throwNew($SSLHandshakeException, "SSLv2Hello is not enabled"_s);
		}
		int8_t majorVersion = $nc(this->header)->get(3);
		int8_t minorVersion = $nc(this->header)->get(4);
		if ((majorVersion == $ProtocolVersion::SSL20Hello->major) && (minorVersion == $ProtocolVersion::SSL20Hello->minor)) {
			$init($SSLRecord);
			$nc(this->os)->write($SSLRecord::v2NoCipher);
			$init($SSLLogger);
			if ($SSLLogger::isOn$) {
				if ($SSLLogger::isOn("record"_s)) {
					$SSLLogger::fine("Requested to negotiate unsupported SSLv2!"_s, $$new($ObjectArray, 0));
				}
				if ($SSLLogger::isOn("packet"_s)) {
					$SSLLogger::fine("Raw write"_s, $$new($ObjectArray, {$of($SSLRecord::v2NoCipher)}));
				}
			}
			$throwNew($SSLException, "Unsupported SSL v2.0 ClientHello"_s);
		}
		int32_t msgLen = (((int32_t)($nc(this->header)->get(0) & (uint32_t)127)) << 8) | ((int32_t)($nc(this->header)->get(1) & (uint32_t)255));
		if ($nc(this->recordBody)->position() == 0) {
			if ($nc(this->recordBody)->capacity() < ($SSLRecord::headerSize + msgLen)) {
				$set(this, recordBody, $ByteBuffer::allocate($SSLRecord::headerSize + msgLen));
			}
			$nc(this->recordBody)->limit($SSLRecord::headerSize + msgLen);
			$nc(this->recordBody)->put(this->header, 0, $SSLRecord::headerSize);
		} else {
			msgLen = $nc(this->recordBody)->remaining();
		}
		msgLen -= 3;
		readFully(msgLen);
		$nc(this->recordBody)->flip();
		$nc(this->recordBody)->position(2);
		$nc(this->handshakeHash)->receive(this->recordBody);
		$nc(this->recordBody)->position(0);
		$var($ByteBuffer, converted, convertToClientHello(this->recordBody));
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("packet"_s)) {
			$SSLLogger::fine("[Converted] ClientHello"_s, $$new($ObjectArray, {$of(converted)}));
		}
		$init($ContentType);
		return $new($PlaintextArray, {$$new($Plaintext, $ContentType::HANDSHAKE->id, majorVersion, minorVersion, -1, -1, converted)});
	} else {
		if ((((int32_t)(firstByte & (uint32_t)128)) != 0) && (thirdByte == 4)) {
			$throwNew($SSLException, "SSL V2.0 servers are not supported."_s);
		}
		$throwNew($SSLException, "Unsupported or unrecognized SSL message"_s);
	}
}

int32_t SSLSocketInputRecord::readFully(int32_t len) {
	$useLocalCurrentObjectStackCache();
	int32_t end = len + $nc(this->recordBody)->position();
	int32_t off = $nc(this->recordBody)->position();
	{
		$var($Throwable, var$0, nullptr);
		try {
			while (off < end) {
				off += read(this->is, $($cast($bytes, $nc(this->recordBody)->array())), off, end - off);
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(this->recordBody)->position(off);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	return len;
}

int32_t SSLSocketInputRecord::readHeader() {
	while (this->headerOff < $SSLRecord::headerSize) {
		this->headerOff += read(this->is, this->header, this->headerOff, $SSLRecord::headerSize - this->headerOff);
	}
	return $SSLRecord::headerSize;
}

int32_t SSLSocketInputRecord::read($InputStream* is, $bytes* buf, int32_t off, int32_t len) {
	$init(SSLSocketInputRecord);
	$useLocalCurrentObjectStackCache();
	int32_t readLen = $nc(is)->read(buf, off, len);
	if (readLen < 0) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("packet"_s)) {
			$SSLLogger::fine("Raw read: EOF"_s, $$new($ObjectArray, 0));
		}
		$throwNew($EOFException, "SSL peer shut down incorrectly"_s);
	}
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("packet"_s)) {
		$var($ByteBuffer, bb, $ByteBuffer::wrap(buf, off, readLen));
		$SSLLogger::fine("Raw read"_s, $$new($ObjectArray, {$of(bb)}));
	}
	return readLen;
}

void SSLSocketInputRecord::deplete(bool tryToRead) {
	int32_t remaining = $nc(this->is)->available();
	if (tryToRead && (remaining == 0)) {
		$nc(this->is)->read();
	}
	while ((remaining = $nc(this->is)->available()) != 0) {
		$nc(this->is)->skip(remaining);
	}
}

SSLSocketInputRecord::SSLSocketInputRecord() {
}

$Class* SSLSocketInputRecord::load$($String* name, bool initialize) {
	$loadClass(SSLSocketInputRecord, name, initialize, &_SSLSocketInputRecord_ClassInfo_, allocate$SSLSocketInputRecord);
	return class$;
}

$Class* SSLSocketInputRecord::class$ = nullptr;

		} // ssl
	} // security
} // sun