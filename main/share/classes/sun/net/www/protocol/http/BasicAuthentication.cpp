#include <sun/net/www/protocol/http/BasicAuthentication.h>

#include <java/lang/AssertionError.h>
#include <java/net/PasswordAuthentication.h>
#include <java/net/URI.h>
#include <java/net/URISyntaxException.h>
#include <java/net/URL.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/CharBuffer.h>
#include <java/nio/charset/Charset.h>
#include <java/util/Arrays.h>
#include <java/util/Base64$Encoder.h>
#include <java/util/Base64.h>
#include <java/util/Objects.h>
#include <sun/net/www/HeaderParser.h>
#include <sun/net/www/protocol/http/AuthScheme.h>
#include <sun/net/www/protocol/http/AuthenticationInfo.h>
#include <sun/net/www/protocol/http/HttpURLConnection.h>
#include <sun/nio/cs/ISO_8859_1.h>
#include <sun/nio/cs/UTF_8.h>
#include <jcpp.h>

#undef BASIC
#undef INSTANCE
#undef PROXY_AUTHENTICATION
#undef SERVER_AUTHENTICATION

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PasswordAuthentication = ::java::net::PasswordAuthentication;
using $URI = ::java::net::URI;
using $URISyntaxException = ::java::net::URISyntaxException;
using $URL = ::java::net::URL;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $CharBuffer = ::java::nio::CharBuffer;
using $Charset = ::java::nio::charset::Charset;
using $Arrays = ::java::util::Arrays;
using $Base64 = ::java::util::Base64;
using $Base64$Encoder = ::java::util::Base64$Encoder;
using $Objects = ::java::util::Objects;
using $HeaderParser = ::sun::net::www::HeaderParser;
using $AuthScheme = ::sun::net::www::protocol::http::AuthScheme;
using $AuthenticationInfo = ::sun::net::www::protocol::http::AuthenticationInfo;
using $HttpURLConnection = ::sun::net::www::protocol::http::HttpURLConnection;
using $ISO_8859_1 = ::sun::nio::cs::ISO_8859_1;
using $UTF_8 = ::sun::nio::cs::UTF_8;

namespace sun {
	namespace net {
		namespace www {
			namespace protocol {
				namespace http {

$FieldInfo _BasicAuthentication_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(BasicAuthentication, $assertionsDisabled)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(BasicAuthentication, serialVersionUID)},
	{"auth", "Ljava/lang/String;", nullptr, $FINAL, $field(BasicAuthentication, auth)},
	{}
};

$MethodInfo _BasicAuthentication_MethodInfo_[] = {
	{"<init>", "(ZLjava/lang/String;ILjava/lang/String;Ljava/net/PasswordAuthentication;ZLjava/lang/String;)V", nullptr, $PUBLIC, $method(BasicAuthentication, init$, void, bool, $String*, int32_t, $String*, $PasswordAuthentication*, bool, $String*)},
	{"<init>", "(ZLjava/lang/String;ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(BasicAuthentication, init$, void, bool, $String*, int32_t, $String*, $String*, $String*)},
	{"<init>", "(ZLjava/net/URL;Ljava/lang/String;Ljava/net/PasswordAuthentication;ZLjava/lang/String;)V", nullptr, $PUBLIC, $method(BasicAuthentication, init$, void, bool, $URL*, $String*, $PasswordAuthentication*, bool, $String*)},
	{"<init>", "(ZLjava/net/URL;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(BasicAuthentication, init$, void, bool, $URL*, $String*, $String*, $String*)},
	{"authValueFrom", "(Ljava/net/PasswordAuthentication;Z)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(BasicAuthentication, authValueFrom, $String*, $PasswordAuthentication*, bool)},
	{"getHeaderValue", "(Ljava/net/URL;Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(BasicAuthentication, getHeaderValue, $String*, $URL*, $String*)},
	{"getRootPath", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", nullptr, $STATIC, $staticMethod(BasicAuthentication, getRootPath, $String*, $String*, $String*)},
	{"isAuthorizationStale", "(Ljava/lang/String;)Z", nullptr, $PUBLIC, $virtualMethod(BasicAuthentication, isAuthorizationStale, bool, $String*)},
	{"setHeaders", "(Lsun/net/www/protocol/http/HttpURLConnection;Lsun/net/www/HeaderParser;Ljava/lang/String;)Z", nullptr, $PUBLIC, $virtualMethod(BasicAuthentication, setHeaders, bool, $HttpURLConnection*, $HeaderParser*, $String*)},
	{"supportsPreemptiveAuthorization", "()Z", nullptr, $PUBLIC, $virtualMethod(BasicAuthentication, supportsPreemptiveAuthorization, bool)},
	{}
};

$ClassInfo _BasicAuthentication_ClassInfo_ = {
	$ACC_SUPER,
	"sun.net.www.protocol.http.BasicAuthentication",
	"sun.net.www.protocol.http.AuthenticationInfo",
	nullptr,
	_BasicAuthentication_FieldInfo_,
	_BasicAuthentication_MethodInfo_
};

$Object* allocate$BasicAuthentication($Class* clazz) {
	return $of($alloc(BasicAuthentication));
}

bool BasicAuthentication::$assertionsDisabled = false;

void BasicAuthentication::init$(bool isProxy, $String* host, int32_t port, $String* realm, $PasswordAuthentication* pw, bool isUTF8, $String* authenticatorKey) {
	$init($AuthScheme);
	$AuthenticationInfo::init$(isProxy ? $AuthenticationInfo::PROXY_AUTHENTICATION : $AuthenticationInfo::SERVER_AUTHENTICATION, $AuthScheme::BASIC, host, port, realm, $cast($String, $Objects::requireNonNull(authenticatorKey)));
	$set(this, auth, authValueFrom(pw, isUTF8));
	$set(this, pw, pw);
}

void BasicAuthentication::init$(bool isProxy, $String* host, int32_t port, $String* realm, $String* auth, $String* authenticatorKey) {
	$init($AuthScheme);
	$AuthenticationInfo::init$(isProxy ? $AuthenticationInfo::PROXY_AUTHENTICATION : $AuthenticationInfo::SERVER_AUTHENTICATION, $AuthScheme::BASIC, host, port, realm, $cast($String, $Objects::requireNonNull(authenticatorKey)));
	$set(this, auth, $str({"Basic "_s, auth}));
}

void BasicAuthentication::init$(bool isProxy, $URL* url, $String* realm, $PasswordAuthentication* pw, bool isUTF8, $String* authenticatorKey) {
	$init($AuthScheme);
	$AuthenticationInfo::init$(isProxy ? $AuthenticationInfo::PROXY_AUTHENTICATION : $AuthenticationInfo::SERVER_AUTHENTICATION, $AuthScheme::BASIC, url, realm, $cast($String, $Objects::requireNonNull(authenticatorKey)));
	$set(this, auth, authValueFrom(pw, isUTF8));
	$set(this, pw, pw);
}

$String* BasicAuthentication::authValueFrom($PasswordAuthentication* pw, bool isUTF8) {
	$init(BasicAuthentication);
	$useLocalCurrentObjectStackCache();
	$var($String, plain, $str({$($nc(pw)->getUserName()), ":"_s}));
	$var($chars, password, pw->getPassword());
	$var($CharBuffer, cbuf, $CharBuffer::allocate($nc(plain)->length() + $nc(password)->length));
	$nc($($nc($($nc(cbuf)->put(plain)))->put(password)))->flip();
	$init($UTF_8);
	$init($ISO_8859_1);
	$var($Charset, charset, isUTF8 ? static_cast<$Charset*>($UTF_8::INSTANCE) : static_cast<$Charset*>($ISO_8859_1::INSTANCE));
	$var($ByteBuffer, buf, $nc(charset)->encode(cbuf));
	$var($ByteBuffer, enc, $nc($($Base64::getEncoder()))->encode(buf));
	$var($String, var$0, "Basic "_s);
	$var($bytes, var$1, $cast($bytes, $nc(enc)->array()));
	int32_t var$2 = enc->position();
	$var($String, ret, $concat(var$0, $$new($String, var$1, var$2, enc->remaining(), static_cast<$Charset*>($ISO_8859_1::INSTANCE))));
	$Arrays::fill($($cast($bytes, $nc(buf)->array())), (int8_t)0);
	$Arrays::fill($($cast($bytes, $nc(enc)->array())), (int8_t)0);
	$Arrays::fill($($cast($chars, cbuf->array())), (char16_t)0);
	return ret;
}

void BasicAuthentication::init$(bool isProxy, $URL* url, $String* realm, $String* auth, $String* authenticatorKey) {
	$init($AuthScheme);
	$AuthenticationInfo::init$(isProxy ? $AuthenticationInfo::PROXY_AUTHENTICATION : $AuthenticationInfo::SERVER_AUTHENTICATION, $AuthScheme::BASIC, url, realm, $cast($String, $Objects::requireNonNull(authenticatorKey)));
	$set(this, auth, $str({"Basic "_s, auth}));
}

bool BasicAuthentication::supportsPreemptiveAuthorization() {
	return true;
}

bool BasicAuthentication::setHeaders($HttpURLConnection* conn, $HeaderParser* p, $String* raw) {
	$useLocalCurrentObjectStackCache();
	if (!BasicAuthentication::$assertionsDisabled && !$nc(conn)->isLockHeldByCurrentThread()) {
		$throwNew($AssertionError);
	}
	$var($String, var$0, getHeaderName());
	$nc(conn)->setAuthenticationProperty(var$0, $(getHeaderValue(nullptr, nullptr)));
	return true;
}

$String* BasicAuthentication::getHeaderValue($URL* url, $String* method) {
	return this->auth;
}

bool BasicAuthentication::isAuthorizationStale($String* header) {
	return false;
}

$String* BasicAuthentication::getRootPath($String* npath$renamed, $String* opath$renamed) {
	$init(BasicAuthentication);
	$useLocalCurrentObjectStackCache();
	$var($String, npath, npath$renamed);
	$var($String, opath, opath$renamed);
	int32_t index = 0;
	int32_t toindex = 0;
	try {
		$assign(npath, $nc($($$new($URI, npath)->normalize()))->getPath());
		$assign(opath, $nc($($$new($URI, opath)->normalize()))->getPath());
	} catch ($URISyntaxException& e) {
	}
	while (index < $nc(opath)->length()) {
		toindex = opath->indexOf((int32_t)u'/', index + 1);
		if (toindex != -1 && opath->regionMatches(0, npath, 0, toindex + 1)) {
			index = toindex;
		} else {
			return opath->substring(0, index + 1);
		}
	}
	return npath;
}

void clinit$BasicAuthentication($Class* class$) {
	BasicAuthentication::$assertionsDisabled = !BasicAuthentication::class$->desiredAssertionStatus();
}

BasicAuthentication::BasicAuthentication() {
}

$Class* BasicAuthentication::load$($String* name, bool initialize) {
	$loadClass(BasicAuthentication, name, initialize, &_BasicAuthentication_ClassInfo_, clinit$BasicAuthentication, allocate$BasicAuthentication);
	return class$;
}

$Class* BasicAuthentication::class$ = nullptr;

				} // http
			} // protocol
		} // www
	} // net
} // sun