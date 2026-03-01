#include <sun/security/ssl/SSLEngineInputRecord.h>

#include <java/lang/UnsupportedOperationException.h>
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
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
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

$FieldInfo _SSLEngineInputRecord_FieldInfo_[] = {
	{"formatVerified", "Z", nullptr, $PRIVATE, $field(SSLEngineInputRecord, formatVerified)},
	{"handshakeBuffer", "Ljava/nio/ByteBuffer;", nullptr, $PRIVATE, $field(SSLEngineInputRecord, handshakeBuffer)},
	{}
};

$MethodInfo _SSLEngineInputRecord_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Lsun/security/ssl/HandshakeHash;)V", nullptr, 0, $method(SSLEngineInputRecord, init$, void, $HandshakeHash*)},
	{"bytesInCompletePacket", "([Ljava/nio/ByteBuffer;II)I", nullptr, 0, $virtualMethod(SSLEngineInputRecord, bytesInCompletePacket, int32_t, $ByteBufferArray*, int32_t, int32_t), "java.io.IOException"},
	{"bytesInCompletePacket", "(Ljava/nio/ByteBuffer;)I", nullptr, $PRIVATE, $method(SSLEngineInputRecord, bytesInCompletePacket, int32_t, $ByteBuffer*), "javax.net.ssl.SSLException"},
	{"decode", "([Ljava/nio/ByteBuffer;II)[Lsun/security/ssl/Plaintext;", nullptr, 0, $virtualMethod(SSLEngineInputRecord, decode, $PlaintextArray*, $ByteBufferArray*, int32_t, int32_t), "java.io.IOException,javax.crypto.BadPaddingException"},
	{"decode", "(Ljava/nio/ByteBuffer;)[Lsun/security/ssl/Plaintext;", nullptr, $PRIVATE, $method(SSLEngineInputRecord, decode, $PlaintextArray*, $ByteBuffer*), "java.io.IOException,javax.crypto.BadPaddingException"},
	{"decodeInputRecord", "(Ljava/nio/ByteBuffer;)[Lsun/security/ssl/Plaintext;", nullptr, $PRIVATE, $method(SSLEngineInputRecord, decodeInputRecord, $PlaintextArray*, $ByteBuffer*), "java.io.IOException,javax.crypto.BadPaddingException"},
	{"estimateFragmentSize", "(I)I", nullptr, 0, $virtualMethod(SSLEngineInputRecord, estimateFragmentSize, int32_t, int32_t)},
	{"handleUnknownRecord", "(Ljava/nio/ByteBuffer;)[Lsun/security/ssl/Plaintext;", nullptr, $PRIVATE, $method(SSLEngineInputRecord, handleUnknownRecord, $PlaintextArray*, $ByteBuffer*), "java.io.IOException,javax.crypto.BadPaddingException"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _SSLEngineInputRecord_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.SSLEngineInputRecord",
	"sun.security.ssl.InputRecord",
	"sun.security.ssl.SSLRecord",
	_SSLEngineInputRecord_FieldInfo_,
	_SSLEngineInputRecord_MethodInfo_
};

$Object* allocate$SSLEngineInputRecord($Class* clazz) {
	return $of($alloc(SSLEngineInputRecord));
}

int32_t SSLEngineInputRecord::hashCode() {
	 return this->$InputRecord::hashCode();
}

bool SSLEngineInputRecord::equals(Object$* obj) {
	 return this->$InputRecord::equals(obj);
}

$Object* SSLEngineInputRecord::clone() {
	 return this->$InputRecord::clone();
}

$String* SSLEngineInputRecord::toString() {
	 return this->$InputRecord::toString();
}

void SSLEngineInputRecord::finalize() {
	this->$InputRecord::finalize();
}

void SSLEngineInputRecord::init$($HandshakeHash* handshakeHash) {
	$InputRecord::init$(handshakeHash, $($SSLCipher$SSLReadCipher::nullTlsReadCipher()));
	this->formatVerified = false;
	$set(this, handshakeBuffer, nullptr);
}

int32_t SSLEngineInputRecord::estimateFragmentSize(int32_t packetSize) {
	if (packetSize > 0) {
		return $nc(this->readCipher)->estimateFragmentSize(packetSize, $SSLRecord::headerSize);
	} else {
		return $Record::maxDataSize;
	}
}

int32_t SSLEngineInputRecord::bytesInCompletePacket($ByteBufferArray* srcs, int32_t srcsOffset, int32_t srcsLength) {
	return bytesInCompletePacket($nc(srcs)->get(srcsOffset));
}

int32_t SSLEngineInputRecord::bytesInCompletePacket($ByteBuffer* packet) {
	$useLocalCurrentObjectStackCache();
	if ($nc(packet)->remaining() < 5) {
		return -1;
	}
	int32_t pos = $nc(packet)->position();
	int8_t byteZero = packet->get(pos);
	int32_t len = 0;
	$init($ContentType);
	if (this->formatVerified || (byteZero == $ContentType::HANDSHAKE->id) || (byteZero == $ContentType::ALERT->id)) {
		int8_t majorVersion = packet->get(pos + 1);
		int8_t minorVersion = packet->get(pos + 2);
		if (!$ProtocolVersion::isNegotiable(majorVersion, minorVersion, false, false)) {
			$throwNew($SSLException, $$str({"Unrecognized record version "_s, $($ProtocolVersion::nameOf(majorVersion, minorVersion)), " , plaintext connection?"_s}));
		}
		this->formatVerified = true;
		int32_t var$0 = (((int32_t)(packet->get(pos + 3) & (uint32_t)255)) << 8);
		len = var$0 + ((int32_t)(packet->get(pos + 4) & (uint32_t)255)) + $SSLRecord::headerSize;
	} else {
		bool isShort = (((int32_t)(byteZero & (uint32_t)128)) != 0);
		bool var$1 = isShort;
		if (var$1) {
			bool var$2 = (packet->get(pos + 2) == 1);
			var$1 = (var$2 || packet->get(pos + 2) == 4);
		}
		if (var$1) {
			int8_t majorVersion = packet->get(pos + 3);
			int8_t minorVersion = packet->get(pos + 4);
			if (!$ProtocolVersion::isNegotiable(majorVersion, minorVersion, false, false)) {
				$throwNew($SSLException, $$str({"Unrecognized record version "_s, $($ProtocolVersion::nameOf(majorVersion, minorVersion)), " , plaintext connection?"_s}));
			}
			int32_t mask = (isShort ? 127 : 63);
			len = (((int32_t)(byteZero & (uint32_t)mask)) << 8) + ((int32_t)(packet->get(pos + 1) & (uint32_t)255)) + (isShort ? 2 : 3);
		} else {
			$throwNew($SSLException, "Unrecognized SSL message, plaintext connection?"_s);
		}
	}
	return len;
}

$PlaintextArray* SSLEngineInputRecord::decode($ByteBufferArray* srcs, int32_t srcsOffset, int32_t srcsLength) {
	if (srcs == nullptr || $nc(srcs)->length == 0 || srcsLength == 0) {
		return $new($PlaintextArray, 0);
	} else if (srcsLength == 1) {
		return decode($nc(srcs)->get(srcsOffset));
	} else {
		$var($ByteBuffer, packet, extract(srcs, srcsOffset, srcsLength, $SSLRecord::headerSize));
		return decode(packet);
	}
}

$PlaintextArray* SSLEngineInputRecord::decode($ByteBuffer* packet) {
	if (this->isClosed$) {
		return nullptr;
	}
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("packet"_s)) {
		$SSLLogger::fine("Raw read"_s, $$new($ObjectArray, {$of(packet)}));
	}
	if (!this->formatVerified) {
		this->formatVerified = true;
		int32_t pos = $nc(packet)->position();
		int8_t byteZero = packet->get(pos);
		$init($ContentType);
		if (byteZero != $ContentType::HANDSHAKE->id && byteZero != $ContentType::ALERT->id) {
			return handleUnknownRecord(packet);
		}
	}
	return decodeInputRecord(packet);
}

$PlaintextArray* SSLEngineInputRecord::decodeInputRecord($ByteBuffer* packet) {
	$useLocalCurrentObjectStackCache();
	int32_t srcPos = $nc(packet)->position();
	int32_t srcLim = packet->limit();
	int8_t contentType = packet->get();
	int8_t majorVersion = packet->get();
	int8_t minorVersion = packet->get();
	int32_t contentLen = $Record::getInt16(packet);
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
	int32_t recLim = srcPos + $SSLRecord::headerSize + contentLen;
	packet->limit(recLim);
	packet->position(srcPos + $SSLRecord::headerSize);
	$var($ByteBuffer, fragment, nullptr);
	{
		$var($Throwable, var$3, nullptr);
		try {
			try {
				$var($Plaintext, plaintext, $nc(this->readCipher)->decrypt(contentType, packet, nullptr));
				$assign(fragment, $nc(plaintext)->fragment);
				contentType = plaintext->contentType;
			} catch ($BadPaddingException& bpe) {
				$throw(bpe);
			} catch ($GeneralSecurityException& gse) {
				$throw($cast($SSLProtocolException, $(($$new($SSLProtocolException, "Unexpected exception"_s))->initCause(gse))));
			}
		} catch ($Throwable& var$4) {
			$assign(var$3, var$4);
		} /*finally*/ {
			packet->limit(srcLim);
			packet->position(recLim);
		}
		if (var$3 != nullptr) {
			$throw(var$3);
		}
	}
	$init($ContentType);
	if (contentType != $ContentType::HANDSHAKE->id && this->handshakeBuffer != nullptr && $nc(this->handshakeBuffer)->hasRemaining()) {
		$throwNew($SSLProtocolException, $$str({"Expecting a handshake fragment, but received "_s, $($ContentType::nameOf(contentType))}));
	}
	if (contentType == $ContentType::HANDSHAKE->id) {
		$var($ByteBuffer, handshakeFrag, fragment);
		if ((this->handshakeBuffer != nullptr) && ($nc(this->handshakeBuffer)->remaining() != 0)) {
			int32_t var$5 = $nc(this->handshakeBuffer)->remaining();
			$var($ByteBuffer, bb, $ByteBuffer::wrap($$new($bytes, var$5 + $nc(fragment)->remaining())));
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
			} else if (remaining == handshakeMessageLen) {
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

$PlaintextArray* SSLEngineInputRecord::handleUnknownRecord($ByteBuffer* packet) {
	$useLocalCurrentObjectStackCache();
	int32_t srcPos = $nc(packet)->position();
	int32_t srcLim = packet->limit();
	int8_t firstByte = packet->get(srcPos);
	int8_t thirdByte = packet->get(srcPos + 2);
	if ((((int32_t)(firstByte & (uint32_t)128)) != 0) && (thirdByte == 1)) {
		$init($ProtocolVersion);
		if (this->helloVersion != $ProtocolVersion::SSL20Hello) {
			$throwNew($SSLHandshakeException, "SSLv2Hello is not enabled"_s);
		}
		int8_t majorVersion = packet->get(srcPos + 3);
		int8_t minorVersion = packet->get(srcPos + 4);
		if ((majorVersion == $ProtocolVersion::SSL20Hello->major) && (minorVersion == $ProtocolVersion::SSL20Hello->minor)) {
			$init($SSLLogger);
			if ($SSLLogger::isOn$ && $SSLLogger::isOn("record"_s)) {
				$SSLLogger::fine("Requested to negotiate unsupported SSLv2!"_s, $$new($ObjectArray, 0));
			}
			$throwNew($UnsupportedOperationException, "Unsupported SSL v2.0 ClientHello"_s);
		}
		packet->position(srcPos + 2);
		$nc(this->handshakeHash)->receive(packet);
		packet->position(srcPos);
		$var($ByteBuffer, converted, convertToClientHello(packet));
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

SSLEngineInputRecord::SSLEngineInputRecord() {
}

$Class* SSLEngineInputRecord::load$($String* name, bool initialize) {
	$loadClass(SSLEngineInputRecord, name, initialize, &_SSLEngineInputRecord_ClassInfo_, allocate$SSLEngineInputRecord);
	return class$;
}

$Class* SSLEngineInputRecord::class$ = nullptr;

		} // ssl
	} // security
} // sun