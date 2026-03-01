#include <java/net/HttpURLConnection.h>

#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/NumberFormatException.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/net/Authenticator.h>
#include <java/net/NetPermission.h>
#include <java/net/ProtocolException.h>
#include <java/net/SocketPermission.h>
#include <java/net/URL.h>
#include <java/net/URLConnection.h>
#include <java/security/Permission.h>
#include <java/util/Date.h>
#include <jcpp.h>

#undef DEFAULT_CHUNK_SIZE
#undef HTTP_ACCEPTED
#undef HTTP_BAD_GATEWAY
#undef HTTP_BAD_METHOD
#undef HTTP_BAD_REQUEST
#undef HTTP_CLIENT_TIMEOUT
#undef HTTP_CONFLICT
#undef HTTP_CREATED
#undef HTTP_ENTITY_TOO_LARGE
#undef HTTP_FORBIDDEN
#undef HTTP_GATEWAY_TIMEOUT
#undef HTTP_GONE
#undef HTTP_INTERNAL_ERROR
#undef HTTP_LENGTH_REQUIRED
#undef HTTP_MOVED_PERM
#undef HTTP_MOVED_TEMP
#undef HTTP_MULT_CHOICE
#undef HTTP_NOT_ACCEPTABLE
#undef HTTP_NOT_AUTHORITATIVE
#undef HTTP_NOT_FOUND
#undef HTTP_NOT_IMPLEMENTED
#undef HTTP_NOT_MODIFIED
#undef HTTP_NO_CONTENT
#undef HTTP_OK
#undef HTTP_PARTIAL
#undef HTTP_PAYMENT_REQUIRED
#undef HTTP_PRECON_FAILED
#undef HTTP_PROXY_AUTH
#undef HTTP_REQ_TOO_LONG
#undef HTTP_RESET
#undef HTTP_SEE_OTHER
#undef HTTP_SERVER_ERROR
#undef HTTP_UNAUTHORIZED
#undef HTTP_UNAVAILABLE
#undef HTTP_UNSUPPORTED_TYPE
#undef HTTP_USE_PROXY
#undef HTTP_VERSION

using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $RuntimeException = ::java::lang::RuntimeException;
using $SecurityManager = ::java::lang::SecurityManager;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $Authenticator = ::java::net::Authenticator;
using $NetPermission = ::java::net::NetPermission;
using $ProtocolException = ::java::net::ProtocolException;
using $SocketPermission = ::java::net::SocketPermission;
using $URL = ::java::net::URL;
using $URLConnection = ::java::net::URLConnection;
using $Permission = ::java::security::Permission;
using $Date = ::java::util::Date;

namespace java {
	namespace net {

$CompoundAttribute _HttpURLConnection_FieldAnnotations_HTTP_SERVER_ERROR[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _HttpURLConnection_FieldInfo_[] = {
	{"method", "Ljava/lang/String;", nullptr, $PROTECTED, $field(HttpURLConnection, method)},
	{"chunkLength", "I", nullptr, $PROTECTED, $field(HttpURLConnection, chunkLength)},
	{"fixedContentLength", "I", nullptr, $PROTECTED, $field(HttpURLConnection, fixedContentLength)},
	{"fixedContentLengthLong", "J", nullptr, $PROTECTED, $field(HttpURLConnection, fixedContentLengthLong)},
	{"DEFAULT_CHUNK_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(HttpURLConnection, DEFAULT_CHUNK_SIZE)},
	{"responseCode", "I", nullptr, $PROTECTED, $field(HttpURLConnection, responseCode)},
	{"responseMessage", "Ljava/lang/String;", nullptr, $PROTECTED, $field(HttpURLConnection, responseMessage)},
	{"followRedirects", "Z", nullptr, $PRIVATE | $STATIC, $staticField(HttpURLConnection, followRedirects)},
	{"instanceFollowRedirects", "Z", nullptr, $PROTECTED, $field(HttpURLConnection, instanceFollowRedirects)},
	{"methods", "[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HttpURLConnection, methods)},
	{"HTTP_OK", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HttpURLConnection, HTTP_OK)},
	{"HTTP_CREATED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HttpURLConnection, HTTP_CREATED)},
	{"HTTP_ACCEPTED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HttpURLConnection, HTTP_ACCEPTED)},
	{"HTTP_NOT_AUTHORITATIVE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HttpURLConnection, HTTP_NOT_AUTHORITATIVE)},
	{"HTTP_NO_CONTENT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HttpURLConnection, HTTP_NO_CONTENT)},
	{"HTTP_RESET", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HttpURLConnection, HTTP_RESET)},
	{"HTTP_PARTIAL", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HttpURLConnection, HTTP_PARTIAL)},
	{"HTTP_MULT_CHOICE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HttpURLConnection, HTTP_MULT_CHOICE)},
	{"HTTP_MOVED_PERM", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HttpURLConnection, HTTP_MOVED_PERM)},
	{"HTTP_MOVED_TEMP", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HttpURLConnection, HTTP_MOVED_TEMP)},
	{"HTTP_SEE_OTHER", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HttpURLConnection, HTTP_SEE_OTHER)},
	{"HTTP_NOT_MODIFIED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HttpURLConnection, HTTP_NOT_MODIFIED)},
	{"HTTP_USE_PROXY", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HttpURLConnection, HTTP_USE_PROXY)},
	{"HTTP_BAD_REQUEST", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HttpURLConnection, HTTP_BAD_REQUEST)},
	{"HTTP_UNAUTHORIZED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HttpURLConnection, HTTP_UNAUTHORIZED)},
	{"HTTP_PAYMENT_REQUIRED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HttpURLConnection, HTTP_PAYMENT_REQUIRED)},
	{"HTTP_FORBIDDEN", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HttpURLConnection, HTTP_FORBIDDEN)},
	{"HTTP_NOT_FOUND", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HttpURLConnection, HTTP_NOT_FOUND)},
	{"HTTP_BAD_METHOD", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HttpURLConnection, HTTP_BAD_METHOD)},
	{"HTTP_NOT_ACCEPTABLE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HttpURLConnection, HTTP_NOT_ACCEPTABLE)},
	{"HTTP_PROXY_AUTH", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HttpURLConnection, HTTP_PROXY_AUTH)},
	{"HTTP_CLIENT_TIMEOUT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HttpURLConnection, HTTP_CLIENT_TIMEOUT)},
	{"HTTP_CONFLICT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HttpURLConnection, HTTP_CONFLICT)},
	{"HTTP_GONE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HttpURLConnection, HTTP_GONE)},
	{"HTTP_LENGTH_REQUIRED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HttpURLConnection, HTTP_LENGTH_REQUIRED)},
	{"HTTP_PRECON_FAILED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HttpURLConnection, HTTP_PRECON_FAILED)},
	{"HTTP_ENTITY_TOO_LARGE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HttpURLConnection, HTTP_ENTITY_TOO_LARGE)},
	{"HTTP_REQ_TOO_LONG", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HttpURLConnection, HTTP_REQ_TOO_LONG)},
	{"HTTP_UNSUPPORTED_TYPE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HttpURLConnection, HTTP_UNSUPPORTED_TYPE)},
	{"HTTP_SERVER_ERROR", "I", nullptr, $PUBLIC | $STATIC | $FINAL | $DEPRECATED, $constField(HttpURLConnection, HTTP_SERVER_ERROR), _HttpURLConnection_FieldAnnotations_HTTP_SERVER_ERROR},
	{"HTTP_INTERNAL_ERROR", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HttpURLConnection, HTTP_INTERNAL_ERROR)},
	{"HTTP_NOT_IMPLEMENTED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HttpURLConnection, HTTP_NOT_IMPLEMENTED)},
	{"HTTP_BAD_GATEWAY", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HttpURLConnection, HTTP_BAD_GATEWAY)},
	{"HTTP_UNAVAILABLE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HttpURLConnection, HTTP_UNAVAILABLE)},
	{"HTTP_GATEWAY_TIMEOUT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HttpURLConnection, HTTP_GATEWAY_TIMEOUT)},
	{"HTTP_VERSION", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HttpURLConnection, HTTP_VERSION)},
	{}
};

$MethodInfo _HttpURLConnection_MethodInfo_[] = {
	{"<init>", "(Ljava/net/URL;)V", nullptr, $PROTECTED, $method(HttpURLConnection, init$, void, $URL*)},
	{"disconnect", "()V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(HttpURLConnection, disconnect, void)},
	{"getErrorStream", "()Ljava/io/InputStream;", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection, getErrorStream, $InputStream*)},
	{"getFollowRedirects", "()Z", nullptr, $PUBLIC | $STATIC, $staticMethod(HttpURLConnection, getFollowRedirects, bool)},
	{"getHeaderField", "(I)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection, getHeaderField, $String*, int32_t)},
	{"getHeaderFieldDate", "(Ljava/lang/String;J)J", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection, getHeaderFieldDate, int64_t, $String*, int64_t)},
	{"getHeaderFieldKey", "(I)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection, getHeaderFieldKey, $String*, int32_t)},
	{"getInstanceFollowRedirects", "()Z", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection, getInstanceFollowRedirects, bool)},
	{"getPermission", "()Ljava/security/Permission;", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection, getPermission, $Permission*), "java.io.IOException"},
	{"getRequestMethod", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection, getRequestMethod, $String*)},
	{"getResponseCode", "()I", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection, getResponseCode, int32_t), "java.io.IOException"},
	{"getResponseMessage", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection, getResponseMessage, $String*), "java.io.IOException"},
	{"setAuthenticator", "(Ljava/net/Authenticator;)V", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection, setAuthenticator, void, $Authenticator*)},
	{"setChunkedStreamingMode", "(I)V", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection, setChunkedStreamingMode, void, int32_t)},
	{"setFixedLengthStreamingMode", "(I)V", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection, setFixedLengthStreamingMode, void, int32_t)},
	{"setFixedLengthStreamingMode", "(J)V", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection, setFixedLengthStreamingMode, void, int64_t)},
	{"setFollowRedirects", "(Z)V", nullptr, $PUBLIC | $STATIC, $staticMethod(HttpURLConnection, setFollowRedirects, void, bool)},
	{"setInstanceFollowRedirects", "(Z)V", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection, setInstanceFollowRedirects, void, bool)},
	{"setRequestMethod", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection, setRequestMethod, void, $String*), "java.net.ProtocolException"},
	{"usingProxy", "()Z", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(HttpURLConnection, usingProxy, bool)},
	{}
};

$ClassInfo _HttpURLConnection_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"java.net.HttpURLConnection",
	"java.net.URLConnection",
	nullptr,
	_HttpURLConnection_FieldInfo_,
	_HttpURLConnection_MethodInfo_
};

$Object* allocate$HttpURLConnection($Class* clazz) {
	return $of($alloc(HttpURLConnection));
}

bool HttpURLConnection::followRedirects = false;
$StringArray* HttpURLConnection::methods = nullptr;

void HttpURLConnection::setAuthenticator($Authenticator* auth) {
	$throwNew($UnsupportedOperationException, $$str({"Supplying an authenticator is not supported by "_s, $of(this)->getClass()}));
}

$String* HttpURLConnection::getHeaderFieldKey(int32_t n) {
	return nullptr;
}

void HttpURLConnection::setFixedLengthStreamingMode(int32_t contentLength) {
	if (this->connected) {
		$throwNew($IllegalStateException, "Already connected"_s);
	}
	if (this->chunkLength != -1) {
		$throwNew($IllegalStateException, "Chunked encoding streaming mode set"_s);
	}
	if (contentLength < 0) {
		$throwNew($IllegalArgumentException, "invalid content length"_s);
	}
	this->fixedContentLength = contentLength;
}

void HttpURLConnection::setFixedLengthStreamingMode(int64_t contentLength) {
	if (this->connected) {
		$throwNew($IllegalStateException, "Already connected"_s);
	}
	if (this->chunkLength != -1) {
		$throwNew($IllegalStateException, "Chunked encoding streaming mode set"_s);
	}
	if (contentLength < 0) {
		$throwNew($IllegalArgumentException, "invalid content length"_s);
	}
	this->fixedContentLengthLong = contentLength;
}

void HttpURLConnection::setChunkedStreamingMode(int32_t chunklen) {
	if (this->connected) {
		$throwNew($IllegalStateException, "Can\'t set streaming mode: already connected"_s);
	}
	if (this->fixedContentLength != -1 || this->fixedContentLengthLong != -1) {
		$throwNew($IllegalStateException, "Fixed length streaming mode set"_s);
	}
	this->chunkLength = chunklen <= 0 ? HttpURLConnection::DEFAULT_CHUNK_SIZE : chunklen;
}

$String* HttpURLConnection::getHeaderField(int32_t n) {
	return nullptr;
}

void HttpURLConnection::init$($URL* u) {
	$URLConnection::init$(u);
	$set(this, method, "GET"_s);
	this->chunkLength = -1;
	this->fixedContentLength = -1;
	this->fixedContentLengthLong = -1;
	this->responseCode = -1;
	$set(this, responseMessage, nullptr);
	this->instanceFollowRedirects = HttpURLConnection::followRedirects;
}

void HttpURLConnection::setFollowRedirects(bool set) {
	$init(HttpURLConnection);
	$var($SecurityManager, sec, $System::getSecurityManager());
	if (sec != nullptr) {
		sec->checkSetFactory();
	}
	HttpURLConnection::followRedirects = set;
}

bool HttpURLConnection::getFollowRedirects() {
	$init(HttpURLConnection);
	return HttpURLConnection::followRedirects;
}

void HttpURLConnection::setInstanceFollowRedirects(bool followRedirects) {
	this->instanceFollowRedirects = followRedirects;
}

bool HttpURLConnection::getInstanceFollowRedirects() {
	return this->instanceFollowRedirects;
}

void HttpURLConnection::setRequestMethod($String* method) {
	$useLocalCurrentObjectStackCache();
	if (this->connected) {
		$throwNew($ProtocolException, "Can\'t reset method: already connected"_s);
	}
	for (int32_t i = 0; i < $nc(HttpURLConnection::methods)->length; ++i) {
		if ($nc($nc(HttpURLConnection::methods)->get(i))->equals(method)) {
			if ($nc(method)->equals("TRACE"_s)) {
				$var($SecurityManager, s, $System::getSecurityManager());
				if (s != nullptr) {
					s->checkPermission($$new($NetPermission, "allowHttpTrace"_s));
				}
			}
			$set(this, method, method);
			return;
		}
	}
	$throwNew($ProtocolException, $$str({"Invalid HTTP method: "_s, method}));
}

$String* HttpURLConnection::getRequestMethod() {
	return this->method;
}

int32_t HttpURLConnection::getResponseCode() {
	$useLocalCurrentObjectStackCache();
	if (this->responseCode != -1) {
		return this->responseCode;
	}
	$var($Exception, exc, nullptr);
	try {
		getInputStream();
	} catch ($Exception& e) {
		$assign(exc, e);
	}
	$var($String, statusLine, getHeaderField(0));
	if (statusLine == nullptr) {
		if (exc != nullptr) {
			if ($instanceOf($RuntimeException, exc)) {
				$throw($cast($RuntimeException, exc));
			} else {
				$throw($cast($IOException, exc));
			}
		}
		return -1;
	}
	if ($nc(statusLine)->startsWith("HTTP/1."_s)) {
		int32_t codePos = statusLine->indexOf((int32_t)u' ');
		if (codePos > 0) {
			int32_t phrasePos = statusLine->indexOf((int32_t)u' ', codePos + 1);
			if (phrasePos > 0 && phrasePos < statusLine->length()) {
				$set(this, responseMessage, statusLine->substring(phrasePos + 1));
			}
			if (phrasePos < 0) {
				phrasePos = statusLine->length();
			}
			try {
				this->responseCode = $Integer::parseInt($(statusLine->substring(codePos + 1, phrasePos)));
				return this->responseCode;
			} catch ($NumberFormatException& e) {
			}
		}
	}
	return -1;
}

$String* HttpURLConnection::getResponseMessage() {
	getResponseCode();
	return this->responseMessage;
}

int64_t HttpURLConnection::getHeaderFieldDate($String* name, int64_t Default) {
	$var($String, dateString, getHeaderField(name));
	try {
		if ($nc(dateString)->indexOf("GMT"_s) == -1) {
			$assign(dateString, $str({dateString, " GMT"_s}));
		}
		return $Date::parse(dateString);
	} catch ($Exception& e) {
	}
	return Default;
}

$Permission* HttpURLConnection::getPermission() {
	$useLocalCurrentObjectStackCache();
	int32_t port = $nc(this->url)->getPort();
	port = port < 0 ? 80 : port;
	$var($String, host, $str({$($nc(this->url)->getHost()), ":"_s, $$str(port)}));
	$var($Permission, permission, $new($SocketPermission, host, "connect"_s));
	return permission;
}

$InputStream* HttpURLConnection::getErrorStream() {
	return nullptr;
}

void clinit$HttpURLConnection($Class* class$) {
	HttpURLConnection::followRedirects = true;
	$assignStatic(HttpURLConnection::methods, $new($StringArray, {
		"GET"_s,
		"POST"_s,
		"HEAD"_s,
		"OPTIONS"_s,
		"PUT"_s,
		"DELETE"_s,
		"TRACE"_s
	}));
}

HttpURLConnection::HttpURLConnection() {
}

$Class* HttpURLConnection::load$($String* name, bool initialize) {
	$loadClass(HttpURLConnection, name, initialize, &_HttpURLConnection_ClassInfo_, clinit$HttpURLConnection, allocate$HttpURLConnection);
	return class$;
}

$Class* HttpURLConnection::class$ = nullptr;

	} // net
} // java