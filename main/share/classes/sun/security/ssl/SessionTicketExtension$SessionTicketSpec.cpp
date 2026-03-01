#include <sun/security/ssl/SessionTicketExtension$SessionTicketSpec.h>

#include <java/nio/ByteBuffer.h>
#include <java/security/Key.h>
#include <java/security/SecureRandom.h>
#include <java/security/spec/AlgorithmParameterSpec.h>
#include <java/text/MessageFormat.h>
#include <java/util/Locale.h>
#include <javax/crypto/Cipher.h>
#include <javax/crypto/SecretKey.h>
#include <javax/crypto/spec/GCMParameterSpec.h>
#include <javax/net/ssl/SSLException.h>
#include <javax/net/ssl/SSLProtocolException.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/SSLContextImpl.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/SSLSessionImpl.h>
#include <sun/security/ssl/SessionTicketExtension$KeyState.h>
#include <sun/security/ssl/SessionTicketExtension$StatelessKey.h>
#include <sun/security/ssl/SessionTicketExtension.h>
#include <sun/security/ssl/TransportContext.h>
#include <sun/security/ssl/Utilities.h>
#include <sun/security/util/HexDumpEncoder.h>
#include <jcpp.h>

#undef BYTES
#undef DECODE_ERROR
#undef DECRYPT_MODE
#undef ENCRYPT_MODE
#undef ENGLISH
#undef GCM_TAG_LEN

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $Key = ::java::security::Key;
using $SecureRandom = ::java::security::SecureRandom;
using $AlgorithmParameterSpec = ::java::security::spec::AlgorithmParameterSpec;
using $MessageFormat = ::java::text::MessageFormat;
using $Locale = ::java::util::Locale;
using $Cipher = ::javax::crypto::Cipher;
using $GCMParameterSpec = ::javax::crypto::spec::GCMParameterSpec;
using $SSLProtocolException = ::javax::net::ssl::SSLProtocolException;
using $Alert = ::sun::security::ssl::Alert;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $SSLContextImpl = ::sun::security::ssl::SSLContextImpl;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $SSLSessionImpl = ::sun::security::ssl::SSLSessionImpl;
using $SessionTicketExtension$KeyState = ::sun::security::ssl::SessionTicketExtension$KeyState;
using $SessionTicketExtension$StatelessKey = ::sun::security::ssl::SessionTicketExtension$StatelessKey;
using $TransportContext = ::sun::security::ssl::TransportContext;
using $Utilities = ::sun::security::ssl::Utilities;
using $HexDumpEncoder = ::sun::security::util::HexDumpEncoder;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _SessionTicketExtension$SessionTicketSpec_FieldInfo_[] = {
	{"GCM_TAG_LEN", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SessionTicketExtension$SessionTicketSpec, GCM_TAG_LEN)},
	{"data", "Ljava/nio/ByteBuffer;", nullptr, 0, $field(SessionTicketExtension$SessionTicketSpec, data)},
	{"zero", "Ljava/nio/ByteBuffer;", nullptr, $STATIC | $FINAL, $staticField(SessionTicketExtension$SessionTicketSpec, zero)},
	{}
};

$MethodInfo _SessionTicketExtension$SessionTicketSpec_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(SessionTicketExtension$SessionTicketSpec, init$, void)},
	{"<init>", "(Lsun/security/ssl/HandshakeContext;[B)V", nullptr, 0, $method(SessionTicketExtension$SessionTicketSpec, init$, void, $HandshakeContext*, $bytes*), "java.io.IOException"},
	{"<init>", "(Lsun/security/ssl/HandshakeContext;Ljava/nio/ByteBuffer;)V", nullptr, 0, $method(SessionTicketExtension$SessionTicketSpec, init$, void, $HandshakeContext*, $ByteBuffer*), "java.io.IOException"},
	{"decrypt", "(Lsun/security/ssl/HandshakeContext;)Ljava/nio/ByteBuffer;", nullptr, 0, $method(SessionTicketExtension$SessionTicketSpec, decrypt, $ByteBuffer*, $HandshakeContext*)},
	{"encrypt", "(Lsun/security/ssl/HandshakeContext;Lsun/security/ssl/SSLSessionImpl;)[B", nullptr, $PUBLIC, $method(SessionTicketExtension$SessionTicketSpec, encrypt, $bytes*, $HandshakeContext*, $SSLSessionImpl*)},
	{"getEncoded", "()[B", nullptr, 0, $method(SessionTicketExtension$SessionTicketSpec, getEncoded, $bytes*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SessionTicketExtension$SessionTicketSpec, toString, $String*)},
	{}
};

$InnerClassInfo _SessionTicketExtension$SessionTicketSpec_InnerClassesInfo_[] = {
	{"sun.security.ssl.SessionTicketExtension$SessionTicketSpec", "sun.security.ssl.SessionTicketExtension", "SessionTicketSpec", $STATIC | $FINAL},
	{"sun.security.ssl.SSLExtension$SSLExtensionSpec", "sun.security.ssl.SSLExtension", "SSLExtensionSpec", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _SessionTicketExtension$SessionTicketSpec_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.SessionTicketExtension$SessionTicketSpec",
	"java.lang.Object",
	"sun.security.ssl.SSLExtension$SSLExtensionSpec",
	_SessionTicketExtension$SessionTicketSpec_FieldInfo_,
	_SessionTicketExtension$SessionTicketSpec_MethodInfo_,
	nullptr,
	nullptr,
	_SessionTicketExtension$SessionTicketSpec_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.SessionTicketExtension"
};

$Object* allocate$SessionTicketExtension$SessionTicketSpec($Class* clazz) {
	return $of($alloc(SessionTicketExtension$SessionTicketSpec));
}

$ByteBuffer* SessionTicketExtension$SessionTicketSpec::zero = nullptr;

void SessionTicketExtension$SessionTicketSpec::init$() {
	$set(this, data, SessionTicketExtension$SessionTicketSpec::zero);
}

void SessionTicketExtension$SessionTicketSpec::init$($HandshakeContext* hc, $bytes* b) {
	SessionTicketExtension$SessionTicketSpec::init$(hc, $($ByteBuffer::wrap(b)));
}

void SessionTicketExtension$SessionTicketSpec::init$($HandshakeContext* hc, $ByteBuffer* buf) {
	$useLocalCurrentObjectStackCache();
	if (buf == nullptr) {
		$init($Alert);
		$throw($($nc($nc(hc)->conContext)->fatal($Alert::DECODE_ERROR, static_cast<$Throwable*>($$new($SSLProtocolException, "SessionTicket buffer too small"_s)))));
	}
	if ($nc(buf)->remaining() > 0x00010000) {
		$init($Alert);
		$throw($($nc($nc(hc)->conContext)->fatal($Alert::DECODE_ERROR, static_cast<$Throwable*>($$new($SSLProtocolException, $$str({"SessionTicket buffer too large. "_s, $$str(buf->remaining())}))))));
	}
	$set(this, data, buf);
}

$bytes* SessionTicketExtension$SessionTicketSpec::encrypt($HandshakeContext* hc, $SSLSessionImpl* session) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, encrypted, nullptr);
	if (!$nc(hc)->statelessResumption || !$nc($nc(hc)->handshakeSession)->isStatelessable()) {
		return $new($bytes, 0);
	}
	try {
		$var($SessionTicketExtension$StatelessKey, key, $SessionTicketExtension$KeyState::getCurrentKey(hc));
		$var($bytes, iv, $new($bytes, 16));
		$var($SecureRandom, random, $nc($nc(hc)->sslContext)->getSecureRandom());
		$nc(random)->nextBytes(iv);
		$var($Cipher, c, $Cipher::getInstance("AES/GCM/NoPadding"_s));
		$nc(c)->init($Cipher::ENCRYPT_MODE, static_cast<$Key*>($nc(key)->key), static_cast<$AlgorithmParameterSpec*>($$new($GCMParameterSpec, SessionTicketExtension$SessionTicketSpec::GCM_TAG_LEN, iv)));
		c->updateAAD($$new($bytes, {
			(int8_t)((int32_t)((uint32_t)$nc(key)->num >> 24)),
			(int8_t)((int32_t)((uint32_t)key->num >> 16)),
			(int8_t)((int32_t)((uint32_t)key->num >> 8)),
			(int8_t)(key->num)
		}));
		$var($bytes, data, $nc(session)->write());
		if ($nc(data)->length == 0) {
			return data;
		}
		$assign(encrypted, c->doFinal(data));
		$var($bytes, result, $new($bytes, $nc(encrypted)->length + $Integer::BYTES + iv->length));
		result->set(0, (int8_t)((int32_t)((uint32_t)$nc(key)->num >> 24)));
		result->set(1, (int8_t)((int32_t)((uint32_t)key->num >> 16)));
		result->set(2, (int8_t)((int32_t)((uint32_t)key->num >> 8)));
		result->set(3, (int8_t)(key->num));
		$System::arraycopy(iv, 0, result, $Integer::BYTES, iv->length);
		$System::arraycopy(encrypted, 0, result, $Integer::BYTES + iv->length, encrypted->length);
		return result;
	} catch ($Exception& e) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
			$SSLLogger::fine($$str({"Encryption failed."_s, e}), $$new($ObjectArray, 0));
		}
		return $new($bytes, 0);
	}
	$shouldNotReachHere();
}

$ByteBuffer* SessionTicketExtension$SessionTicketSpec::decrypt($HandshakeContext* hc) {
	$useLocalCurrentObjectStackCache();
	int32_t keyID = 0;
	$var($bytes, iv, nullptr);
	try {
		keyID = $nc(this->data)->getInt();
		$var($SessionTicketExtension$StatelessKey, key, $SessionTicketExtension$KeyState::getKey(hc, keyID));
		if (key == nullptr) {
			return nullptr;
		}
		$assign(iv, $new($bytes, 16));
		$nc(this->data)->get(iv);
		$var($Cipher, c, $Cipher::getInstance("AES/GCM/NoPadding"_s));
		$nc(c)->init($Cipher::DECRYPT_MODE, static_cast<$Key*>($nc(key)->key), static_cast<$AlgorithmParameterSpec*>($$new($GCMParameterSpec, SessionTicketExtension$SessionTicketSpec::GCM_TAG_LEN, iv)));
		c->updateAAD($$new($bytes, {
			(int8_t)((int32_t)((uint32_t)keyID >> 24)),
			(int8_t)((int32_t)((uint32_t)keyID >> 16)),
			(int8_t)((int32_t)((uint32_t)keyID >> 8)),
			(int8_t)(keyID)
		}));
		$var($ByteBuffer, out, nullptr);
		$assign(out, $ByteBuffer::allocate($nc(this->data)->remaining() - SessionTicketExtension$SessionTicketSpec::GCM_TAG_LEN / 8));
		c->doFinal(this->data, out);
		$nc(out)->flip();
		return out;
	} catch ($Exception& e) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
			$SSLLogger::fine($$str({"Decryption failed."_s, $(e->getMessage())}), $$new($ObjectArray, 0));
		}
	}
	return nullptr;
}

$bytes* SessionTicketExtension$SessionTicketSpec::getEncoded() {
	$useLocalCurrentObjectStackCache();
	$var($bytes, out, $new($bytes, $nc(this->data)->capacity()));
	$nc($($nc(this->data)->duplicate()))->get(out);
	return out;
}

$String* SessionTicketExtension$SessionTicketSpec::toString() {
	$useLocalCurrentObjectStackCache();
	if (this->data == nullptr) {
		return "<null>"_s;
	}
	if ($nc(this->data)->capacity() == 0) {
		return "<empty>"_s;
	}
	$init($Locale);
	$var($MessageFormat, messageFormat, $new($MessageFormat, "  \"ticket\" : \'{\'\n{0}\n  \'}\'"_s, $Locale::ENGLISH));
	$var($HexDumpEncoder, hexEncoder, $new($HexDumpEncoder));
	$var($ObjectArray, messageFields, $new($ObjectArray, {$($of($Utilities::indent($(hexEncoder->encode($($nc(this->data)->duplicate()))), "    "_s)))}));
	return messageFormat->format(messageFields);
}

void clinit$SessionTicketExtension$SessionTicketSpec($Class* class$) {
	$assignStatic(SessionTicketExtension$SessionTicketSpec::zero, $ByteBuffer::wrap($$new($bytes, 0)));
}

SessionTicketExtension$SessionTicketSpec::SessionTicketExtension$SessionTicketSpec() {
}

$Class* SessionTicketExtension$SessionTicketSpec::load$($String* name, bool initialize) {
	$loadClass(SessionTicketExtension$SessionTicketSpec, name, initialize, &_SessionTicketExtension$SessionTicketSpec_ClassInfo_, clinit$SessionTicketExtension$SessionTicketSpec, allocate$SessionTicketExtension$SessionTicketSpec);
	return class$;
}

$Class* SessionTicketExtension$SessionTicketSpec::class$ = nullptr;

		} // ssl
	} // security
} // sun