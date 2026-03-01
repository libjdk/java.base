#include <sun/security/ssl/CookieExtension$CookieSpec.h>

#include <java/nio/ByteBuffer.h>
#include <java/text/MessageFormat.h>
#include <java/util/Locale.h>
#include <javax/net/ssl/SSLException.h>
#include <javax/net/ssl/SSLProtocolException.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/CookieExtension.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/Record.h>
#include <sun/security/ssl/TransportContext.h>
#include <sun/security/ssl/Utilities.h>
#include <sun/security/util/HexDumpEncoder.h>
#include <jcpp.h>

#undef DECODE_ERROR
#undef ENGLISH

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $MessageFormat = ::java::text::MessageFormat;
using $Locale = ::java::util::Locale;
using $SSLProtocolException = ::javax::net::ssl::SSLProtocolException;
using $Alert = ::sun::security::ssl::Alert;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $Record = ::sun::security::ssl::Record;
using $TransportContext = ::sun::security::ssl::TransportContext;
using $Utilities = ::sun::security::ssl::Utilities;
using $HexDumpEncoder = ::sun::security::util::HexDumpEncoder;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _CookieExtension$CookieSpec_FieldInfo_[] = {
	{"cookie", "[B", nullptr, $FINAL, $field(CookieExtension$CookieSpec, cookie)},
	{}
};

$MethodInfo _CookieExtension$CookieSpec_MethodInfo_[] = {
	{"<init>", "(Lsun/security/ssl/HandshakeContext;Ljava/nio/ByteBuffer;)V", nullptr, $PRIVATE, $method(CookieExtension$CookieSpec, init$, void, $HandshakeContext*, $ByteBuffer*), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(CookieExtension$CookieSpec, toString, $String*)},
	{}
};

$InnerClassInfo _CookieExtension$CookieSpec_InnerClassesInfo_[] = {
	{"sun.security.ssl.CookieExtension$CookieSpec", "sun.security.ssl.CookieExtension", "CookieSpec", $STATIC},
	{"sun.security.ssl.SSLExtension$SSLExtensionSpec", "sun.security.ssl.SSLExtension", "SSLExtensionSpec", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _CookieExtension$CookieSpec_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.ssl.CookieExtension$CookieSpec",
	"java.lang.Object",
	"sun.security.ssl.SSLExtension$SSLExtensionSpec",
	_CookieExtension$CookieSpec_FieldInfo_,
	_CookieExtension$CookieSpec_MethodInfo_,
	nullptr,
	nullptr,
	_CookieExtension$CookieSpec_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.CookieExtension"
};

$Object* allocate$CookieExtension$CookieSpec($Class* clazz) {
	return $of($alloc(CookieExtension$CookieSpec));
}

void CookieExtension$CookieSpec::init$($HandshakeContext* hc, $ByteBuffer* m) {
	$useLocalCurrentObjectStackCache();
	if ($nc(m)->remaining() < 3) {
		$init($Alert);
		$throw($($nc($nc(hc)->conContext)->fatal($Alert::DECODE_ERROR, static_cast<$Throwable*>($$new($SSLProtocolException, "Invalid cookie extension: insufficient data"_s)))));
	}
	$set(this, cookie, $Record::getBytes16(m));
}

$String* CookieExtension$CookieSpec::toString() {
	$useLocalCurrentObjectStackCache();
	$init($Locale);
	$var($MessageFormat, messageFormat, $new($MessageFormat, "\"cookie\": \'{\'\n{0}\n\'}\',"_s, $Locale::ENGLISH));
	$var($HexDumpEncoder, hexEncoder, $new($HexDumpEncoder));
	$var($ObjectArray, messageFields, $new($ObjectArray, {$($of($Utilities::indent($(hexEncoder->encode(this->cookie)))))}));
	return messageFormat->format(messageFields);
}

CookieExtension$CookieSpec::CookieExtension$CookieSpec() {
}

$Class* CookieExtension$CookieSpec::load$($String* name, bool initialize) {
	$loadClass(CookieExtension$CookieSpec, name, initialize, &_CookieExtension$CookieSpec_ClassInfo_, allocate$CookieExtension$CookieSpec);
	return class$;
}

$Class* CookieExtension$CookieSpec::class$ = nullptr;

		} // ssl
	} // security
} // sun