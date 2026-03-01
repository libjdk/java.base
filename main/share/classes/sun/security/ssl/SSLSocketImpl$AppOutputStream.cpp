#include <sun/security/ssl/SSLSocketImpl$AppOutputStream.h>

#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <java/lang/IndexOutOfBoundsException.h>
#include <java/net/SocketException.h>
#include <javax/net/ssl/SSLException.h>
#include <javax/net/ssl/SSLHandshakeException.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/OutputRecord.h>
#include <sun/security/ssl/SSLCipher$SSLWriteCipher.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/SSLSessionImpl.h>
#include <sun/security/ssl/SSLSocketImpl.h>
#include <sun/security/ssl/TransportContext.h>
#include <jcpp.h>

#undef HANDSHAKE_FAILURE
#undef UNEXPECTED_MESSAGE

using $IOException = ::java::io::IOException;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IndexOutOfBoundsException = ::java::lang::IndexOutOfBoundsException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $SocketException = ::java::net::SocketException;
using $SSLException = ::javax::net::ssl::SSLException;
using $SSLHandshakeException = ::javax::net::ssl::SSLHandshakeException;
using $Alert = ::sun::security::ssl::Alert;
using $OutputRecord = ::sun::security::ssl::OutputRecord;
using $SSLCipher$SSLWriteCipher = ::sun::security::ssl::SSLCipher$SSLWriteCipher;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $SSLSocketImpl = ::sun::security::ssl::SSLSocketImpl;
using $TransportContext = ::sun::security::ssl::TransportContext;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _SSLSocketImpl$AppOutputStream_FieldInfo_[] = {
	{"this$0", "Lsun/security/ssl/SSLSocketImpl;", nullptr, $FINAL | $SYNTHETIC, $field(SSLSocketImpl$AppOutputStream, this$0)},
	{"oneByte", "[B", nullptr, $PRIVATE | $FINAL, $field(SSLSocketImpl$AppOutputStream, oneByte)},
	{}
};

$MethodInfo _SSLSocketImpl$AppOutputStream_MethodInfo_[] = {
	{"<init>", "(Lsun/security/ssl/SSLSocketImpl;)V", nullptr, $PRIVATE, $method(SSLSocketImpl$AppOutputStream, init$, void, $SSLSocketImpl*)},
	{"close", "()V", nullptr, $PUBLIC, $virtualMethod(SSLSocketImpl$AppOutputStream, close, void), "java.io.IOException"},
	{"write", "(I)V", nullptr, $PUBLIC, $virtualMethod(SSLSocketImpl$AppOutputStream, write, void, int32_t), "java.io.IOException"},
	{"write", "([BII)V", nullptr, $PUBLIC, $virtualMethod(SSLSocketImpl$AppOutputStream, write, void, $bytes*, int32_t, int32_t), "java.io.IOException"},
	{}
};

$InnerClassInfo _SSLSocketImpl$AppOutputStream_InnerClassesInfo_[] = {
	{"sun.security.ssl.SSLSocketImpl$AppOutputStream", "sun.security.ssl.SSLSocketImpl", "AppOutputStream", $PRIVATE},
	{}
};

$ClassInfo _SSLSocketImpl$AppOutputStream_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.ssl.SSLSocketImpl$AppOutputStream",
	"java.io.OutputStream",
	nullptr,
	_SSLSocketImpl$AppOutputStream_FieldInfo_,
	_SSLSocketImpl$AppOutputStream_MethodInfo_,
	nullptr,
	nullptr,
	_SSLSocketImpl$AppOutputStream_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.SSLSocketImpl"
};

$Object* allocate$SSLSocketImpl$AppOutputStream($Class* clazz) {
	return $of($alloc(SSLSocketImpl$AppOutputStream));
}

void SSLSocketImpl$AppOutputStream::init$($SSLSocketImpl* this$0) {
	$set(this, this$0, this$0);
	$OutputStream::init$();
	$set(this, oneByte, $new($bytes, 1));
}

void SSLSocketImpl$AppOutputStream::write(int32_t i) {
	$nc(this->oneByte)->set(0, (int8_t)i);
	write(this->oneByte, 0, 1);
}

void SSLSocketImpl$AppOutputStream::write($bytes* b, int32_t off, int32_t len) {
	$useLocalCurrentObjectStackCache();
	if (b == nullptr) {
		$throwNew($NullPointerException, "the source buffer is null"_s);
	} else if (off < 0 || len < 0 || len > $nc(b)->length - off) {
		$throwNew($IndexOutOfBoundsException, $$str({"buffer length: "_s, $$str(b->length), ", offset; "_s, $$str(off), ", bytes to read:"_s, $$str(len)}));
	} else if (len == 0) {
		return;
	}
	bool var$0 = !$nc(this->this$0->conContext)->isNegotiated && !$nc(this->this$0->conContext)->isBroken && !$nc(this->this$0->conContext)->isInboundClosed();
	if (var$0 && !$nc(this->this$0->conContext)->isOutboundClosed()) {
		this->this$0->ensureNegotiated(true);
	}
	if (!$nc(this->this$0->conContext)->isNegotiated || $nc(this->this$0->conContext)->isBroken || $nc(this->this$0->conContext)->isOutboundClosed()) {
		$throwNew($SocketException, "Connection or outbound has closed"_s);
	}
	try {
		$nc($nc(this->this$0->conContext)->outputRecord)->deliver(b, off, len);
	} catch ($SSLHandshakeException& she) {
		$init($Alert);
		$throw($($nc(this->this$0->conContext)->fatal($Alert::HANDSHAKE_FAILURE, static_cast<$Throwable*>(she))));
	} catch ($SSLException& ssle) {
		$init($Alert);
		$throw($($nc(this->this$0->conContext)->fatal($Alert::UNEXPECTED_MESSAGE, static_cast<$Throwable*>(ssle))));
	}
	bool var$1 = $nc($nc(this->this$0->conContext)->outputRecord)->seqNumIsHuge();
	if (var$1 || $nc($nc($nc(this->this$0->conContext)->outputRecord)->writeCipher)->atKeyLimit()) {
		this->this$0->tryKeyUpdate();
	}
	if ($nc($nc(this->this$0->conContext)->conSession)->updateNST) {
		$nc($nc(this->this$0->conContext)->conSession)->updateNST = false;
		this->this$0->tryNewSessionTicket();
	}
}

void SSLSocketImpl$AppOutputStream::close() {
	$useLocalCurrentObjectStackCache();
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
		$SSLLogger::finest("Closing output stream"_s, $$new($ObjectArray, 0));
	}
	try {
		this->this$0->close();
	} catch ($IOException& ioe) {
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
			$SSLLogger::warning("output stream close failed. Debug info only. Exception details:"_s, $$new($ObjectArray, {$of(ioe)}));
		}
	}
}

SSLSocketImpl$AppOutputStream::SSLSocketImpl$AppOutputStream() {
}

$Class* SSLSocketImpl$AppOutputStream::load$($String* name, bool initialize) {
	$loadClass(SSLSocketImpl$AppOutputStream, name, initialize, &_SSLSocketImpl$AppOutputStream_ClassInfo_, allocate$SSLSocketImpl$AppOutputStream);
	return class$;
}

$Class* SSLSocketImpl$AppOutputStream::class$ = nullptr;

		} // ssl
	} // security
} // sun