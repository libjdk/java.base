#include <sun/security/ssl/Finished$FinishedMessage.h>

#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <java/nio/ByteBuffer.h>
#include <java/security/MessageDigest.h>
#include <java/text/MessageFormat.h>
#include <java/util/Locale.h>
#include <javax/net/ssl/SSLException.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/CipherSuite$HashAlg.h>
#include <sun/security/ssl/CipherSuite.h>
#include <sun/security/ssl/Finished$VerifyDataScheme.h>
#include <sun/security/ssl/Finished.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/HandshakeOutStream.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/SSLHandshake$HandshakeMessage.h>
#include <sun/security/ssl/SSLHandshake.h>
#include <sun/security/ssl/TransportContext.h>
#include <sun/security/ssl/Utilities.h>
#include <sun/security/util/HexDumpEncoder.h>
#include <jcpp.h>

#undef DECODE_ERROR
#undef DECRYPT_ERROR
#undef ENGLISH
#undef FINISHED
#undef ILLEGAL_PARAMETER
#undef SSL30

using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $MessageDigest = ::java::security::MessageDigest;
using $MessageFormat = ::java::text::MessageFormat;
using $Locale = ::java::util::Locale;
using $Alert = ::sun::security::ssl::Alert;
using $Finished$VerifyDataScheme = ::sun::security::ssl::Finished$VerifyDataScheme;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $HandshakeOutStream = ::sun::security::ssl::HandshakeOutStream;
using $ProtocolVersion = ::sun::security::ssl::ProtocolVersion;
using $SSLHandshake = ::sun::security::ssl::SSLHandshake;
using $SSLHandshake$HandshakeMessage = ::sun::security::ssl::SSLHandshake$HandshakeMessage;
using $TransportContext = ::sun::security::ssl::TransportContext;
using $Utilities = ::sun::security::ssl::Utilities;
using $HexDumpEncoder = ::sun::security::util::HexDumpEncoder;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _Finished$FinishedMessage_FieldInfo_[] = {
	{"verifyData", "[B", nullptr, $PRIVATE | $FINAL, $field(Finished$FinishedMessage, verifyData)},
	{}
};

$MethodInfo _Finished$FinishedMessage_MethodInfo_[] = {
	{"<init>", "(Lsun/security/ssl/HandshakeContext;)V", nullptr, 0, $method(Finished$FinishedMessage, init$, void, $HandshakeContext*), "java.io.IOException"},
	{"<init>", "(Lsun/security/ssl/HandshakeContext;Ljava/nio/ByteBuffer;)V", nullptr, 0, $method(Finished$FinishedMessage, init$, void, $HandshakeContext*, $ByteBuffer*), "java.io.IOException"},
	{"handshakeType", "()Lsun/security/ssl/SSLHandshake;", nullptr, $PUBLIC, $virtualMethod(Finished$FinishedMessage, handshakeType, $SSLHandshake*)},
	{"messageLength", "()I", nullptr, $PUBLIC, $virtualMethod(Finished$FinishedMessage, messageLength, int32_t)},
	{"send", "(Lsun/security/ssl/HandshakeOutStream;)V", nullptr, $PUBLIC, $virtualMethod(Finished$FinishedMessage, send, void, $HandshakeOutStream*), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Finished$FinishedMessage, toString, $String*)},
	{}
};

$InnerClassInfo _Finished$FinishedMessage_InnerClassesInfo_[] = {
	{"sun.security.ssl.Finished$FinishedMessage", "sun.security.ssl.Finished", "FinishedMessage", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.SSLHandshake$HandshakeMessage", "sun.security.ssl.SSLHandshake", "HandshakeMessage", $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _Finished$FinishedMessage_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.Finished$FinishedMessage",
	"sun.security.ssl.SSLHandshake$HandshakeMessage",
	nullptr,
	_Finished$FinishedMessage_FieldInfo_,
	_Finished$FinishedMessage_MethodInfo_,
	nullptr,
	nullptr,
	_Finished$FinishedMessage_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.Finished"
};

$Object* allocate$Finished$FinishedMessage($Class* clazz) {
	return $of($alloc(Finished$FinishedMessage));
}

void Finished$FinishedMessage::init$($HandshakeContext* context) {
	$useLocalCurrentObjectStackCache();
	$SSLHandshake$HandshakeMessage::init$(context);
	$Finished$VerifyDataScheme* vds = $Finished$VerifyDataScheme::valueOf($nc(context)->negotiatedProtocol);
	$var($bytes, vd, nullptr);
	try {
		$assign(vd, $nc(vds)->createVerifyData(context, false));
	} catch ($IOException& ioe) {
		$init($Alert);
		$throw($($nc($nc(context)->conContext)->fatal($Alert::ILLEGAL_PARAMETER, "Failed to generate verify_data"_s, ioe)));
	}
	$set(this, verifyData, vd);
}

void Finished$FinishedMessage::init$($HandshakeContext* context, $ByteBuffer* m) {
	$useLocalCurrentObjectStackCache();
	$SSLHandshake$HandshakeMessage::init$(context);
	int32_t verifyDataLen = 12;
	$init($ProtocolVersion);
	if ($nc(context)->negotiatedProtocol == $ProtocolVersion::SSL30) {
		verifyDataLen = 36;
	} else if ($nc(context->negotiatedProtocol)->useTLS13PlusSpec()) {
		verifyDataLen = $nc(context->negotiatedCipherSuite)->hashAlg->hashLength;
	}
	if ($nc(m)->remaining() != verifyDataLen) {
		$init($Alert);
		$throw($($nc($nc(context)->conContext)->fatal($Alert::DECODE_ERROR, $$str({"Inappropriate finished message: need "_s, $$str(verifyDataLen), " but remaining "_s, $$str(m->remaining()), " bytes verify_data"_s}))));
	}
	$set(this, verifyData, $new($bytes, verifyDataLen));
	$nc(m)->get(this->verifyData);
	$Finished$VerifyDataScheme* vd = $Finished$VerifyDataScheme::valueOf($nc(context)->negotiatedProtocol);
	$var($bytes, myVerifyData, nullptr);
	try {
		$assign(myVerifyData, $nc(vd)->createVerifyData(context, true));
	} catch ($IOException& ioe) {
		$init($Alert);
		$throw($($nc($nc(context)->conContext)->fatal($Alert::ILLEGAL_PARAMETER, "Failed to generate verify_data"_s, ioe)));
	}
	if (!$MessageDigest::isEqual(myVerifyData, this->verifyData)) {
		$init($Alert);
		$throw($($nc($nc(context)->conContext)->fatal($Alert::DECRYPT_ERROR, "The Finished message cannot be verified."_s)));
	}
}

$SSLHandshake* Finished$FinishedMessage::handshakeType() {
	$init($SSLHandshake);
	return $SSLHandshake::FINISHED;
}

int32_t Finished$FinishedMessage::messageLength() {
	return $nc(this->verifyData)->length;
}

void Finished$FinishedMessage::send($HandshakeOutStream* hos) {
	$nc(hos)->write(this->verifyData);
}

$String* Finished$FinishedMessage::toString() {
	$useLocalCurrentObjectStackCache();
	$init($Locale);
	$var($MessageFormat, messageFormat, $new($MessageFormat, "\"Finished\": \'{\'\n  \"verify data\": \'{\'\n{0}\n  \'}\'\'}\'"_s, $Locale::ENGLISH));
	$var($HexDumpEncoder, hexEncoder, $new($HexDumpEncoder));
	$var($ObjectArray, messageFields, $new($ObjectArray, {$($of($Utilities::indent($(hexEncoder->encode(this->verifyData)), "    "_s)))}));
	return messageFormat->format(messageFields);
}

Finished$FinishedMessage::Finished$FinishedMessage() {
}

$Class* Finished$FinishedMessage::load$($String* name, bool initialize) {
	$loadClass(Finished$FinishedMessage, name, initialize, &_Finished$FinishedMessage_ClassInfo_, allocate$Finished$FinishedMessage);
	return class$;
}

$Class* Finished$FinishedMessage::class$ = nullptr;

		} // ssl
	} // security
} // sun