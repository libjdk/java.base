#include <sun/security/ssl/SSLTransport.h>

#include <java/io/EOFException.h>
#include <java/io/IOException.h>
#include <java/io/InterruptedIOException.h>
#include <java/lang/Math.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/net/SocketException.h>
#include <java/nio/ByteBuffer.h>
#include <javax/crypto/AEADBadTagException.h>
#include <javax/crypto/BadPaddingException.h>
#include <javax/net/ssl/SSLException.h>
#include <javax/net/ssl/SSLHandshakeException.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/ContentType.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/InputRecord.h>
#include <sun/security/ssl/OutputRecord.h>
#include <sun/security/ssl/Plaintext.h>
#include <sun/security/ssl/SSLConfiguration.h>
#include <sun/security/ssl/SSLContextImpl.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/TransportContext.h>
#include <jcpp.h>

#undef APPLICATION_DATA
#undef BAD_RECORD_MAC
#undef HANDSHAKE_FAILURE
#undef INTERNAL_ERROR
#undef PLAINTEXT_NULL
#undef UNEXPECTED_MESSAGE

using $ByteBufferArray = $Array<::java::nio::ByteBuffer>;
using $PlaintextArray = $Array<::sun::security::ssl::Plaintext>;
using $EOFException = ::java::io::EOFException;
using $IOException = ::java::io::IOException;
using $InterruptedIOException = ::java::io::InterruptedIOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $SocketException = ::java::net::SocketException;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $AEADBadTagException = ::javax::crypto::AEADBadTagException;
using $BadPaddingException = ::javax::crypto::BadPaddingException;
using $SSLHandshakeException = ::javax::net::ssl::SSLHandshakeException;
using $Alert = ::sun::security::ssl::Alert;
using $ContentType = ::sun::security::ssl::ContentType;
using $InputRecord = ::sun::security::ssl::InputRecord;
using $OutputRecord = ::sun::security::ssl::OutputRecord;
using $Plaintext = ::sun::security::ssl::Plaintext;
using $SSLContextImpl = ::sun::security::ssl::SSLContextImpl;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $TransportContext = ::sun::security::ssl::TransportContext;

namespace sun {
	namespace security {
		namespace ssl {

$MethodInfo _SSLTransport_MethodInfo_[] = {
	{"decode", "(Lsun/security/ssl/TransportContext;[Ljava/nio/ByteBuffer;II[Ljava/nio/ByteBuffer;II)Lsun/security/ssl/Plaintext;", nullptr, $PUBLIC | $STATIC, $staticMethod(SSLTransport, decode, $Plaintext*, $TransportContext*, $ByteBufferArray*, int32_t, int32_t, $ByteBufferArray*, int32_t, int32_t), "java.io.IOException"},
	{"getPeerHost", "()Ljava/lang/String;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(SSLTransport, getPeerHost, $String*)},
	{"getPeerPort", "()I", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(SSLTransport, getPeerPort, int32_t)},
	{"shutdown", "()V", nullptr, $PUBLIC, $virtualMethod(SSLTransport, shutdown, void), "java.io.IOException"},
	{"useDelegatedTask", "()Z", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(SSLTransport, useDelegatedTask, bool)},
	{}
};

$ClassInfo _SSLTransport_ClassInfo_ = {
	$INTERFACE | $ABSTRACT,
	"sun.security.ssl.SSLTransport",
	nullptr,
	nullptr,
	nullptr,
	_SSLTransport_MethodInfo_
};

$Object* allocate$SSLTransport($Class* clazz) {
	return $of($alloc(SSLTransport));
}

void SSLTransport::shutdown() {
}

$Plaintext* SSLTransport::decode($TransportContext* context, $ByteBufferArray* srcs, int32_t srcsOffset, int32_t srcsLength, $ByteBufferArray* dsts, int32_t dstsOffset, int32_t dstsLength) {
	$useLocalCurrentObjectStackCache();
	$var($PlaintextArray, plaintexts, nullptr);
	try {
		$assign(plaintexts, $nc($nc(context)->inputRecord)->decode(srcs, srcsOffset, srcsLength));
	} catch ($UnsupportedOperationException& unsoe) {
		if (!$nc($nc(context)->sslContext)->isDTLS()) {
			$nc(context->outputRecord)->encodeV2NoCipher();
			$init($SSLLogger);
			if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
				$SSLLogger::finest("may be talking to SSLv2"_s, $$new($ObjectArray, 0));
			}
		}
		$init($Alert);
		$throw($($nc(context)->fatal($Alert::UNEXPECTED_MESSAGE, static_cast<$Throwable*>(unsoe))));
	} catch ($AEADBadTagException& bte) {
		$init($Alert);
		$throw($($nc(context)->fatal($Alert::BAD_RECORD_MAC, static_cast<$Throwable*>(bte))));
	} catch ($BadPaddingException& bpe) {
		$init($Alert);
		$Alert* alert = ($nc(context)->handshakeContext != nullptr) ? $Alert::HANDSHAKE_FAILURE : $Alert::BAD_RECORD_MAC;
		$throw($($nc(context)->fatal(alert, static_cast<$Throwable*>(bpe))));
	} catch ($SSLHandshakeException& she) {
		$init($Alert);
		$throw($($nc(context)->fatal($Alert::HANDSHAKE_FAILURE, static_cast<$Throwable*>(she))));
	} catch ($EOFException& eofe) {
		$throw(eofe);
	} catch ($InterruptedIOException& se) {
		$throw(se);
	} catch ($SocketException& se) {
		$throw(se);
	} catch ($IOException& ioe) {
		$init($Alert);
		$throw($($nc(context)->fatal($Alert::UNEXPECTED_MESSAGE, static_cast<$Throwable*>(ioe))));
	}
	if (plaintexts == nullptr || $nc(plaintexts)->length == 0) {
		$init($Plaintext);
		return $Plaintext::PLAINTEXT_NULL;
	}
	$init($Plaintext);
	$var($Plaintext, finalPlaintext, $Plaintext::PLAINTEXT_NULL);
	{
		$var($PlaintextArray, arr$, plaintexts);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Plaintext, plainText, arr$->get(i$));
			{
				if (plainText == $Plaintext::PLAINTEXT_NULL) {
					if ($nc(context)->handshakeContext != nullptr && $nc($nc(context->handshakeContext)->sslConfig)->enableRetransmissions && $nc(context->sslContext)->isDTLS()) {
						$init($SSLLogger);
						if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,verbose"_s)) {
							$SSLLogger::finest("retransmited handshake flight"_s, $$new($ObjectArray, 0));
						}
						$nc(context->outputRecord)->launchRetransmission();
					}
				} else {
					$init($ContentType);
					if (plainText != nullptr && plainText->contentType != $ContentType::APPLICATION_DATA->id) {
						$nc(context)->dispatch(plainText);
					}
				}
				if (plainText == nullptr) {
					$assign(plainText, $Plaintext::PLAINTEXT_NULL);
				} else {
					$init($ContentType);
					if ($nc(plainText)->contentType == $ContentType::APPLICATION_DATA->id) {
						if (!$nc(context)->isNegotiated) {
							$init($SSLLogger);
							if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,verbose"_s)) {
								$SSLLogger::warning("unexpected application data before handshake completion"_s, $$new($ObjectArray, 0));
							}
							$init($Alert);
							$throw($(context->fatal($Alert::UNEXPECTED_MESSAGE, "Receiving application data before handshake complete"_s)));
						}
						if ((dsts != nullptr) && (dstsLength > 0)) {
							$var($ByteBuffer, fragment, plainText->fragment);
							int32_t remains = $nc(fragment)->remaining();
							int32_t limit = dstsOffset + dstsLength;
							for (int32_t i = dstsOffset; ((i < limit) && (remains > 0)); ++i) {
								int32_t amount = $Math::min($nc(dsts->get(i))->remaining(), remains);
								fragment->limit(fragment->position() + amount);
								$nc(dsts->get(i))->put(fragment);
								remains -= amount;
								if (!$nc(dsts->get(i))->hasRemaining()) {
									++dstsOffset;
								}
							}
							if (remains > 0) {
								$init($Alert);
								$throw($($nc(context)->fatal($Alert::INTERNAL_ERROR, "no sufficient room in the destination buffers"_s)));
							}
						}
					}
				}
				$assign(finalPlaintext, plainText);
			}
		}
	}
	return finalPlaintext;
}

$Class* SSLTransport::load$($String* name, bool initialize) {
	$loadClass(SSLTransport, name, initialize, &_SSLTransport_ClassInfo_, allocate$SSLTransport);
	return class$;
}

$Class* SSLTransport::class$ = nullptr;

		} // ssl
	} // security
} // sun