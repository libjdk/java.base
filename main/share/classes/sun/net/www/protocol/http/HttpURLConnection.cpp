#include <sun/net/www/protocol/http/HttpURLConnection.h>

#include <java/io/FileNotFoundException.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/CharSequence.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/NoSuchFieldException.h>
#include <java/lang/NumberFormatException.h>
#include <java/lang/SecurityException.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/reflect/Field.h>
#include <java/net/Authenticator$RequestorType.h>
#include <java/net/Authenticator.h>
#include <java/net/CacheRequest.h>
#include <java/net/CacheResponse.h>
#include <java/net/CookieHandler.h>
#include <java/net/HttpCookie.h>
#include <java/net/HttpRetryException.h>
#include <java/net/HttpURLConnection.h>
#include <java/net/InetAddress.h>
#include <java/net/InetSocketAddress.h>
#include <java/net/MalformedURLException.h>
#include <java/net/PasswordAuthentication.h>
#include <java/net/ProtocolException.h>
#include <java/net/Proxy$Type.h>
#include <java/net/Proxy.h>
#include <java/net/ProxySelector.h>
#include <java/net/ResponseCache.h>
#include <java/net/SecureCacheResponse.h>
#include <java/net/SocketAddress.h>
#include <java/net/SocketPermission.h>
#include <java/net/SocketTimeoutException.h>
#include <java/net/URI.h>
#include <java/net/URL.h>
#include <java/net/URLConnection.h>
#include <java/net/URLPermission.h>
#include <java/net/UnknownHostException.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/PrivilegedActionException.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/text/SimpleDateFormat.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Collections.h>
#include <java/util/Date.h>
#include <java/util/HashMap.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Properties.h>
#include <java/util/Set.h>
#include <java/util/StringJoiner.h>
#include <java/util/StringTokenizer.h>
#include <java/util/TimeZone.h>
#include <java/util/concurrent/locks/ReentrantLock.h>
#include <jdk/internal/access/JavaNetHttpCookieAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <sun/net/ApplicationProxy.h>
#include <sun/net/NetProperties.h>
#include <sun/net/NetworkClient.h>
#include <sun/net/ProgressMonitor.h>
#include <sun/net/ProgressSource.h>
#include <sun/net/util/IPAddressUtil.h>
#include <sun/net/www/HeaderParser.h>
#include <sun/net/www/MessageHeader.h>
#include <sun/net/www/MeteredStream.h>
#include <sun/net/www/ParseUtil.h>
#include <sun/net/www/http/ChunkedInputStream.h>
#include <sun/net/www/http/ChunkedOutputStream.h>
#include <sun/net/www/http/HttpClient.h>
#include <sun/net/www/http/PosterOutputStream.h>
#include <sun/net/www/protocol/http/AuthScheme.h>
#include <sun/net/www/protocol/http/AuthenticationHeader.h>
#include <sun/net/www/protocol/http/AuthenticationInfo.h>
#include <sun/net/www/protocol/http/AuthenticatorKeys.h>
#include <sun/net/www/protocol/http/BasicAuthentication.h>
#include <sun/net/www/protocol/http/DigestAuthentication$Parameters.h>
#include <sun/net/www/protocol/http/DigestAuthentication.h>
#include <sun/net/www/protocol/http/EmptyInputStream.h>
#include <sun/net/www/protocol/http/Handler.h>
#include <sun/net/www/protocol/http/HttpAuthenticator.h>
#include <sun/net/www/protocol/http/HttpCallerInfo.h>
#include <sun/net/www/protocol/http/HttpURLConnection$1.h>
#include <sun/net/www/protocol/http/HttpURLConnection$10.h>
#include <sun/net/www/protocol/http/HttpURLConnection$11.h>
#include <sun/net/www/protocol/http/HttpURLConnection$12.h>
#include <sun/net/www/protocol/http/HttpURLConnection$13.h>
#include <sun/net/www/protocol/http/HttpURLConnection$2.h>
#include <sun/net/www/protocol/http/HttpURLConnection$3.h>
#include <sun/net/www/protocol/http/HttpURLConnection$4.h>
#include <sun/net/www/protocol/http/HttpURLConnection$5.h>
#include <sun/net/www/protocol/http/HttpURLConnection$6.h>
#include <sun/net/www/protocol/http/HttpURLConnection$7.h>
#include <sun/net/www/protocol/http/HttpURLConnection$8.h>
#include <sun/net/www/protocol/http/HttpURLConnection$9.h>
#include <sun/net/www/protocol/http/HttpURLConnection$ErrorStream.h>
#include <sun/net/www/protocol/http/HttpURLConnection$HttpInputStream.h>
#include <sun/net/www/protocol/http/HttpURLConnection$StreamingOutputStream.h>
#include <sun/net/www/protocol/http/HttpURLConnection$TunnelState.h>
#include <sun/net/www/protocol/http/NTLMAuthenticationProxy.h>
#include <sun/net/www/protocol/http/NegotiateAuthentication.h>
#include <sun/security/action/GetIntegerAction.h>
#include <sun/security/action/GetPropertyAction.h>
#include <sun/util/logging/PlatformLogger$Level.h>
#include <sun/util/logging/PlatformLogger.h>
#include <jcpp.h>

#undef BASIC
#undef CHECK_SET_HOST
#undef CHECK_SUBPATH
#undef DEFAULT_CONNECT_TIMEOUT
#undef DEFAULT_READ_TIMEOUT
#undef DIGEST
#undef EXCLUDE_HEADERS
#undef EXCLUDE_HEADERS2
#undef FINE
#undef FINER
#undef FINEST
#undef HTTP
#undef HTTP_CONNECT
#undef HTTP_NOT_MODIFIED
#undef HTTP_NO_CONTENT
#undef HTTP_OK
#undef HTTP_PROXY_AUTH
#undef HTTP_UNAUTHORIZED
#undef HTTP_USE_PROXY
#undef KERBEROS
#undef LF
#undef NEGOTIATE
#undef NONE
#undef NO_PROXY
#undef NTLM
#undef PROXY
#undef RETRY_MSG1
#undef RETRY_MSG2
#undef RETRY_MSG3
#undef ROOT
#undef SERVER
#undef SETUP
#undef SET_COOKIE
#undef SET_COOKIE2
#undef TUNNELING
#undef UNKNOWN
#undef US
#undef WARNING

using $PermissionArray = $Array<::java::security::Permission>;
using $FileNotFoundException = ::java::io::FileNotFoundException;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $NoSuchFieldException = ::java::lang::NoSuchFieldException;
using $NullPointerException = ::java::lang::NullPointerException;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $RuntimeException = ::java::lang::RuntimeException;
using $SecurityException = ::java::lang::SecurityException;
using $SecurityManager = ::java::lang::SecurityManager;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Field = ::java::lang::reflect::Field;
using $Authenticator = ::java::net::Authenticator;
using $Authenticator$RequestorType = ::java::net::Authenticator$RequestorType;
using $CacheRequest = ::java::net::CacheRequest;
using $CacheResponse = ::java::net::CacheResponse;
using $CookieHandler = ::java::net::CookieHandler;
using $HttpCookie = ::java::net::HttpCookie;
using $HttpRetryException = ::java::net::HttpRetryException;
using $HttpURLConnection = ::java::net::HttpURLConnection;
using $InetAddress = ::java::net::InetAddress;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $MalformedURLException = ::java::net::MalformedURLException;
using $PasswordAuthentication = ::java::net::PasswordAuthentication;
using $ProtocolException = ::java::net::ProtocolException;
using $Proxy = ::java::net::Proxy;
using $Proxy$Type = ::java::net::Proxy$Type;
using $ProxySelector = ::java::net::ProxySelector;
using $ResponseCache = ::java::net::ResponseCache;
using $SecureCacheResponse = ::java::net::SecureCacheResponse;
using $SocketAddress = ::java::net::SocketAddress;
using $SocketPermission = ::java::net::SocketPermission;
using $SocketTimeoutException = ::java::net::SocketTimeoutException;
using $URI = ::java::net::URI;
using $URL = ::java::net::URL;
using $URLConnection = ::java::net::URLConnection;
using $URLPermission = ::java::net::URLPermission;
using $UnknownHostException = ::java::net::UnknownHostException;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $Permission = ::java::security::Permission;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $PrivilegedActionException = ::java::security::PrivilegedActionException;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $SimpleDateFormat = ::java::text::SimpleDateFormat;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Collections = ::java::util::Collections;
using $Date = ::java::util::Date;
using $HashMap = ::java::util::HashMap;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Objects = ::java::util::Objects;
using $Properties = ::java::util::Properties;
using $Set = ::java::util::Set;
using $StringJoiner = ::java::util::StringJoiner;
using $StringTokenizer = ::java::util::StringTokenizer;
using $TimeZone = ::java::util::TimeZone;
using $ReentrantLock = ::java::util::concurrent::locks::ReentrantLock;
using $JavaNetHttpCookieAccess = ::jdk::internal::access::JavaNetHttpCookieAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $ApplicationProxy = ::sun::net::ApplicationProxy;
using $NetProperties = ::sun::net::NetProperties;
using $NetworkClient = ::sun::net::NetworkClient;
using $ProgressMonitor = ::sun::net::ProgressMonitor;
using $ProgressSource = ::sun::net::ProgressSource;
using $IPAddressUtil = ::sun::net::util::IPAddressUtil;
using $HeaderParser = ::sun::net::www::HeaderParser;
using $MessageHeader = ::sun::net::www::MessageHeader;
using $MeteredStream = ::sun::net::www::MeteredStream;
using $ParseUtil = ::sun::net::www::ParseUtil;
using $ChunkedInputStream = ::sun::net::www::http::ChunkedInputStream;
using $ChunkedOutputStream = ::sun::net::www::http::ChunkedOutputStream;
using $HttpClient = ::sun::net::www::http::HttpClient;
using $PosterOutputStream = ::sun::net::www::http::PosterOutputStream;
using $AuthScheme = ::sun::net::www::protocol::http::AuthScheme;
using $AuthenticationHeader = ::sun::net::www::protocol::http::AuthenticationHeader;
using $AuthenticationInfo = ::sun::net::www::protocol::http::AuthenticationInfo;
using $AuthenticatorKeys = ::sun::net::www::protocol::http::AuthenticatorKeys;
using $BasicAuthentication = ::sun::net::www::protocol::http::BasicAuthentication;
using $DigestAuthentication = ::sun::net::www::protocol::http::DigestAuthentication;
using $DigestAuthentication$Parameters = ::sun::net::www::protocol::http::DigestAuthentication$Parameters;
using $EmptyInputStream = ::sun::net::www::protocol::http::EmptyInputStream;
using $Handler = ::sun::net::www::protocol::http::Handler;
using $HttpAuthenticator = ::sun::net::www::protocol::http::HttpAuthenticator;
using $HttpCallerInfo = ::sun::net::www::protocol::http::HttpCallerInfo;
using $HttpURLConnection$1 = ::sun::net::www::protocol::http::HttpURLConnection$1;
using $HttpURLConnection$10 = ::sun::net::www::protocol::http::HttpURLConnection$10;
using $HttpURLConnection$11 = ::sun::net::www::protocol::http::HttpURLConnection$11;
using $HttpURLConnection$12 = ::sun::net::www::protocol::http::HttpURLConnection$12;
using $HttpURLConnection$13 = ::sun::net::www::protocol::http::HttpURLConnection$13;
using $HttpURLConnection$2 = ::sun::net::www::protocol::http::HttpURLConnection$2;
using $HttpURLConnection$3 = ::sun::net::www::protocol::http::HttpURLConnection$3;
using $HttpURLConnection$4 = ::sun::net::www::protocol::http::HttpURLConnection$4;
using $HttpURLConnection$5 = ::sun::net::www::protocol::http::HttpURLConnection$5;
using $HttpURLConnection$6 = ::sun::net::www::protocol::http::HttpURLConnection$6;
using $HttpURLConnection$7 = ::sun::net::www::protocol::http::HttpURLConnection$7;
using $HttpURLConnection$8 = ::sun::net::www::protocol::http::HttpURLConnection$8;
using $HttpURLConnection$9 = ::sun::net::www::protocol::http::HttpURLConnection$9;
using $HttpURLConnection$ErrorStream = ::sun::net::www::protocol::http::HttpURLConnection$ErrorStream;
using $HttpURLConnection$HttpInputStream = ::sun::net::www::protocol::http::HttpURLConnection$HttpInputStream;
using $HttpURLConnection$StreamingOutputStream = ::sun::net::www::protocol::http::HttpURLConnection$StreamingOutputStream;
using $HttpURLConnection$TunnelState = ::sun::net::www::protocol::http::HttpURLConnection$TunnelState;
using $NTLMAuthenticationProxy = ::sun::net::www::protocol::http::NTLMAuthenticationProxy;
using $NegotiateAuthentication = ::sun::net::www::protocol::http::NegotiateAuthentication;
using $GetIntegerAction = ::sun::security::action::GetIntegerAction;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;
using $PlatformLogger = ::sun::util::logging::PlatformLogger;
using $PlatformLogger$Level = ::sun::util::logging::PlatformLogger$Level;

namespace sun {
	namespace net {
		namespace www {
			namespace protocol {
				namespace http {

class HttpURLConnection$$Lambda$lambda$getNetProperty$0 : public $PrivilegedAction {
	$class(HttpURLConnection$$Lambda$lambda$getNetProperty$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$($String* name) {
		$set(this, name, name);
	}
	virtual $Object* run() override {
		 return $of(HttpURLConnection::lambda$getNetProperty$0(name));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpURLConnection$$Lambda$lambda$getNetProperty$0>());
	}
	$String* name = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HttpURLConnection$$Lambda$lambda$getNetProperty$0::fieldInfos[2] = {
	{"name", "Ljava/lang/String;", nullptr, $PUBLIC, $field(HttpURLConnection$$Lambda$lambda$getNetProperty$0, name)},
	{}
};
$MethodInfo HttpURLConnection$$Lambda$lambda$getNetProperty$0::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(HttpURLConnection$$Lambda$lambda$getNetProperty$0, init$, void, $String*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection$$Lambda$lambda$getNetProperty$0, run, $Object*)},
	{}
};
$ClassInfo HttpURLConnection$$Lambda$lambda$getNetProperty$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.net.www.protocol.http.HttpURLConnection$$Lambda$lambda$getNetProperty$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* HttpURLConnection$$Lambda$lambda$getNetProperty$0::load$($String* name, bool initialize) {
	$loadClass(HttpURLConnection$$Lambda$lambda$getNetProperty$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpURLConnection$$Lambda$lambda$getNetProperty$0::class$ = nullptr;

$CompoundAttribute _HttpURLConnection_FieldAnnotations_defaultAuth[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _HttpURLConnection_MethodAnnotations_setDefaultAuthenticator74[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _HttpURLConnection_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(HttpURLConnection, $assertionsDisabled)},
	{"HTTP_CONNECT", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(HttpURLConnection, HTTP_CONNECT)},
	{"version", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(HttpURLConnection, version)},
	{"userAgent", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(HttpURLConnection, userAgent)},
	{"defaultmaxRedirects", "I", nullptr, $STATIC | $FINAL, $constField(HttpURLConnection, defaultmaxRedirects)},
	{"maxRedirects", "I", nullptr, $STATIC | $FINAL, $staticField(HttpURLConnection, maxRedirects)},
	{"validateProxy", "Z", nullptr, $STATIC | $FINAL, $staticField(HttpURLConnection, validateProxy)},
	{"validateServer", "Z", nullptr, $STATIC | $FINAL, $staticField(HttpURLConnection, validateServer)},
	{"disabledProxyingSchemes", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/String;>;", $STATIC | $FINAL, $staticField(HttpURLConnection, disabledProxyingSchemes)},
	{"disabledTunnelingSchemes", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/String;>;", $STATIC | $FINAL, $staticField(HttpURLConnection, disabledTunnelingSchemes)},
	{"strOutputStream", "Lsun/net/www/protocol/http/HttpURLConnection$StreamingOutputStream;", nullptr, $PRIVATE, $field(HttpURLConnection, strOutputStream)},
	{"RETRY_MSG1", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HttpURLConnection, RETRY_MSG1)},
	{"RETRY_MSG2", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HttpURLConnection, RETRY_MSG2)},
	{"RETRY_MSG3", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HttpURLConnection, RETRY_MSG3)},
	{"enableESBuffer", "Z", nullptr, $PRIVATE | $STATIC, $staticField(HttpURLConnection, enableESBuffer)},
	{"timeout4ESBuffer", "I", nullptr, $PRIVATE | $STATIC, $staticField(HttpURLConnection, timeout4ESBuffer)},
	{"bufSize4ES", "I", nullptr, $PRIVATE | $STATIC, $staticField(HttpURLConnection, bufSize4ES)},
	{"allowRestrictedHeaders", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HttpURLConnection, allowRestrictedHeaders)},
	{"restrictedHeaderSet", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE | $STATIC | $FINAL, $staticField(HttpURLConnection, restrictedHeaderSet)},
	{"restrictedHeaders", "[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HttpURLConnection, restrictedHeaders)},
	{"httpVersion", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(HttpURLConnection, httpVersion)},
	{"acceptString", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(HttpURLConnection, acceptString)},
	{"EXCLUDE_HEADERS", "[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HttpURLConnection, EXCLUDE_HEADERS)},
	{"EXCLUDE_HEADERS2", "[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HttpURLConnection, EXCLUDE_HEADERS2)},
	{"http", "Lsun/net/www/http/HttpClient;", nullptr, $PROTECTED, $field(HttpURLConnection, http)},
	{"handler", "Lsun/net/www/protocol/http/Handler;", nullptr, $PROTECTED, $field(HttpURLConnection, handler)},
	{"instProxy", "Ljava/net/Proxy;", nullptr, $PROTECTED, $field(HttpURLConnection, instProxy)},
	{"authenticator", "Ljava/net/Authenticator;", nullptr, $PROTECTED | $VOLATILE, $field(HttpURLConnection, authenticator)},
	{"authenticatorKey", "Ljava/lang/String;", nullptr, $PROTECTED | $VOLATILE, $field(HttpURLConnection, authenticatorKey)},
	{"cookieHandler", "Ljava/net/CookieHandler;", nullptr, $PRIVATE, $field(HttpURLConnection, cookieHandler)},
	{"cacheHandler", "Ljava/net/ResponseCache;", nullptr, $PRIVATE | $FINAL, $field(HttpURLConnection, cacheHandler)},
	{"usingProxy", "Z", nullptr, $PRIVATE | $VOLATILE, $field(HttpURLConnection, usingProxy$)},
	{"cachedResponse", "Ljava/net/CacheResponse;", nullptr, $PROTECTED, $field(HttpURLConnection, cachedResponse)},
	{"cachedHeaders", "Lsun/net/www/MessageHeader;", nullptr, $PRIVATE, $field(HttpURLConnection, cachedHeaders)},
	{"cachedInputStream", "Ljava/io/InputStream;", nullptr, $PRIVATE, $field(HttpURLConnection, cachedInputStream)},
	{"ps", "Ljava/io/PrintStream;", nullptr, $PROTECTED, $field(HttpURLConnection, ps)},
	{"errorStream", "Ljava/io/InputStream;", nullptr, $PRIVATE, $field(HttpURLConnection, errorStream)},
	{"setUserCookies", "Z", nullptr, $PRIVATE, $field(HttpURLConnection, setUserCookies)},
	{"userCookies", "Ljava/lang/String;", nullptr, $PRIVATE, $field(HttpURLConnection, userCookies)},
	{"userCookies2", "Ljava/lang/String;", nullptr, $PRIVATE, $field(HttpURLConnection, userCookies2)},
	{"defaultAuth", "Lsun/net/www/protocol/http/HttpAuthenticator;", nullptr, $PRIVATE | $STATIC | $DEPRECATED, $staticField(HttpURLConnection, defaultAuth), _HttpURLConnection_FieldAnnotations_defaultAuth},
	{"requests", "Lsun/net/www/MessageHeader;", nullptr, $PRIVATE, $field(HttpURLConnection, requests)},
	{"userHeaders", "Lsun/net/www/MessageHeader;", nullptr, $PRIVATE, $field(HttpURLConnection, userHeaders)},
	{"connecting", "Z", nullptr, $PRIVATE, $field(HttpURLConnection, connecting)},
	{"domain", "Ljava/lang/String;", nullptr, 0, $field(HttpURLConnection, domain)},
	{"digestparams", "Lsun/net/www/protocol/http/DigestAuthentication$Parameters;", nullptr, 0, $field(HttpURLConnection, digestparams)},
	{"currentProxyCredentials", "Lsun/net/www/protocol/http/AuthenticationInfo;", nullptr, 0, $field(HttpURLConnection, currentProxyCredentials)},
	{"currentServerCredentials", "Lsun/net/www/protocol/http/AuthenticationInfo;", nullptr, 0, $field(HttpURLConnection, currentServerCredentials)},
	{"needToCheck", "Z", nullptr, 0, $field(HttpURLConnection, needToCheck)},
	{"doingNTLM2ndStage", "Z", nullptr, $PRIVATE, $field(HttpURLConnection, doingNTLM2ndStage)},
	{"doingNTLMp2ndStage", "Z", nullptr, $PRIVATE, $field(HttpURLConnection, doingNTLMp2ndStage)},
	{"tryTransparentNTLMServer", "Z", nullptr, $PRIVATE, $field(HttpURLConnection, tryTransparentNTLMServer)},
	{"tryTransparentNTLMProxy", "Z", nullptr, $PRIVATE, $field(HttpURLConnection, tryTransparentNTLMProxy)},
	{"useProxyResponseCode", "Z", nullptr, $PRIVATE, $field(HttpURLConnection, useProxyResponseCode)},
	{"authObj", "Ljava/lang/Object;", nullptr, $PRIVATE, $field(HttpURLConnection, authObj$)},
	{"isUserServerAuth", "Z", nullptr, 0, $field(HttpURLConnection, isUserServerAuth)},
	{"isUserProxyAuth", "Z", nullptr, 0, $field(HttpURLConnection, isUserProxyAuth)},
	{"serverAuthKey", "Ljava/lang/String;", nullptr, 0, $field(HttpURLConnection, serverAuthKey)},
	{"proxyAuthKey", "Ljava/lang/String;", nullptr, 0, $field(HttpURLConnection, proxyAuthKey)},
	{"pi", "Lsun/net/ProgressSource;", nullptr, $PROTECTED, $field(HttpURLConnection, pi)},
	{"responses", "Lsun/net/www/MessageHeader;", nullptr, $PRIVATE, $field(HttpURLConnection, responses)},
	{"inputStream", "Ljava/io/InputStream;", nullptr, $PRIVATE, $field(HttpURLConnection, inputStream)},
	{"poster", "Lsun/net/www/http/PosterOutputStream;", nullptr, $PRIVATE, $field(HttpURLConnection, poster)},
	{"setRequests", "Z", nullptr, $PRIVATE, $field(HttpURLConnection, setRequests)},
	{"failedOnce", "Z", nullptr, $PRIVATE, $field(HttpURLConnection, failedOnce)},
	{"rememberedException", "Ljava/lang/Exception;", nullptr, $PRIVATE, $field(HttpURLConnection, rememberedException)},
	{"reuseClient", "Lsun/net/www/http/HttpClient;", nullptr, $PRIVATE, $field(HttpURLConnection, reuseClient)},
	{"tunnelState", "Lsun/net/www/protocol/http/HttpURLConnection$TunnelState;", nullptr, $PRIVATE, $field(HttpURLConnection, tunnelState$)},
	{"connectTimeout", "I", nullptr, $PRIVATE, $field(HttpURLConnection, connectTimeout)},
	{"readTimeout", "I", nullptr, $PRIVATE, $field(HttpURLConnection, readTimeout)},
	{"socketPermission", "Ljava/net/SocketPermission;", nullptr, $PRIVATE, $field(HttpURLConnection, socketPermission)},
	{"logger", "Lsun/util/logging/PlatformLogger;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HttpURLConnection, logger)},
	{"connectionLock", "Ljava/util/concurrent/locks/ReentrantLock;", nullptr, $PRIVATE | $FINAL, $field(HttpURLConnection, connectionLock)},
	{"requestURI", "Ljava/lang/String;", nullptr, 0, $field(HttpURLConnection, requestURI)},
	{"cdata", "[B", nullptr, 0, $field(HttpURLConnection, cdata)},
	{"SET_COOKIE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HttpURLConnection, SET_COOKIE)},
	{"SET_COOKIE2", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HttpURLConnection, SET_COOKIE2)},
	{"filteredHeaders", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/util/List<Ljava/lang/String;>;>;", $PRIVATE, $field(HttpURLConnection, filteredHeaders)},
	{}
};

$MethodInfo _HttpURLConnection_MethodInfo_[] = {
	{"<init>", "(Ljava/net/URL;Lsun/net/www/protocol/http/Handler;)V", nullptr, $PROTECTED, $method(HttpURLConnection, init$, void, $URL*, $Handler*), "java.io.IOException"},
	{"<init>", "(Ljava/net/URL;Ljava/lang/String;I)V", nullptr, $PUBLIC, $method(HttpURLConnection, init$, void, $URL*, $String*, int32_t), "java.io.IOException"},
	{"<init>", "(Ljava/net/URL;Ljava/net/Proxy;)V", nullptr, $PUBLIC, $method(HttpURLConnection, init$, void, $URL*, $Proxy*), "java.io.IOException"},
	{"<init>", "(Ljava/net/URL;Ljava/net/Proxy;Lsun/net/www/protocol/http/Handler;)V", nullptr, $PROTECTED, $method(HttpURLConnection, init$, void, $URL*, $Proxy*, $Handler*), "java.io.IOException"},
	{"URLtoSocketPermission", "(Ljava/net/URL;)Ljava/net/SocketPermission;", nullptr, 0, $virtualMethod(HttpURLConnection, URLtoSocketPermission, $SocketPermission*, $URL*), "java.io.IOException"},
	{"addRequestProperty", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection, addRequestProperty, void, $String*, $String*)},
	{"authObj", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection, authObj, $Object*)},
	{"authObj", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection, authObj, void, Object$*)},
	{"checkHost", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(HttpURLConnection, checkHost, $String*, $String*), "java.io.IOException"},
	{"checkMessageHeader", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PRIVATE, $method(HttpURLConnection, checkMessageHeader, void, $String*, $String*)},
	{"checkResponseCredentials", "(Z)V", nullptr, $PRIVATE, $method(HttpURLConnection, checkResponseCredentials, void, bool), "java.io.IOException"},
	{"checkReuseConnection", "()Z", nullptr, $PRIVATE, $method(HttpURLConnection, checkReuseConnection, bool)},
	{"checkSetHost", "()Z", nullptr, $PRIVATE, $method(HttpURLConnection, checkSetHost, bool)},
	{"checkURL", "(Ljava/net/URL;)Ljava/net/URL;", nullptr, $PRIVATE | $STATIC, $staticMethod(HttpURLConnection, checkURL, $URL*, $URL*), "java.io.IOException"},
	{"checkURLFile", "()V", nullptr, $PRIVATE, $method(HttpURLConnection, checkURLFile, void)},
	{"connect", "()V", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection, connect, void), "java.io.IOException"},
	{"connectRequestURI", "(Ljava/net/URL;)Ljava/lang/String;", nullptr, $STATIC, $staticMethod(HttpURLConnection, connectRequestURI, $String*, $URL*)},
	{"disconnect", "()V", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection, disconnect, void)},
	{"disconnectInternal", "()V", nullptr, $PRIVATE, $method(HttpURLConnection, disconnectInternal, void)},
	{"disconnectWeb", "()V", nullptr, $PRIVATE, $method(HttpURLConnection, disconnectWeb, void), "java.io.IOException"},
	{"doTunneling", "()V", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection, doTunneling, void), "java.io.IOException"},
	{"doTunneling0", "()V", nullptr, $PRIVATE, $method(HttpURLConnection, doTunneling0, void), "java.io.IOException"},
	{"expect100Continue", "()V", nullptr, $PRIVATE, $method(HttpURLConnection, expect100Continue, void), "java.io.IOException"},
	{"filterHeaderField", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE, $method(HttpURLConnection, filterHeaderField, $String*, $String*, $String*)},
	{"followRedirect", "()Z", nullptr, $PRIVATE, $method(HttpURLConnection, followRedirect, bool), "java.io.IOException"},
	{"followRedirect0", "(Ljava/lang/String;ILjava/net/URL;)Z", nullptr, $PRIVATE, $method(HttpURLConnection, followRedirect0, bool, $String*, int32_t, $URL*), "java.io.IOException"},
	{"getAuthenticatorKey", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection, getAuthenticatorKey, $String*)},
	{"getChainedException", "(Ljava/io/IOException;)Ljava/io/IOException;", nullptr, $PRIVATE, $method(HttpURLConnection, getChainedException, $IOException*, $IOException*)},
	{"getConnectTimeout", "()I", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection, getConnectTimeout, int32_t)},
	{"getCookieHandler", "()Ljava/net/CookieHandler;", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection, getCookieHandler, $CookieHandler*)},
	{"getErrorStream", "()Ljava/io/InputStream;", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection, getErrorStream, $InputStream*)},
	{"getFilteredHeaderFields", "()Ljava/util/Map;", "()Ljava/util/Map<Ljava/lang/String;Ljava/util/List<Ljava/lang/String;>;>;", $PRIVATE, $method(HttpURLConnection, getFilteredHeaderFields, $Map*)},
	{"getHeaderField", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection, getHeaderField, $String*, $String*)},
	{"getHeaderField", "(I)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection, getHeaderField, $String*, int32_t)},
	{"getHeaderFieldKey", "(I)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection, getHeaderFieldKey, $String*, int32_t)},
	{"getHeaderFields", "()Ljava/util/Map;", "()Ljava/util/Map<Ljava/lang/String;Ljava/util/List<Ljava/lang/String;>;>;", $PUBLIC, $virtualMethod(HttpURLConnection, getHeaderFields, $Map*)},
	{"getHostAndPort", "(Ljava/net/URL;)Ljava/lang/String;", nullptr, $PRIVATE, $method(HttpURLConnection, getHostAndPort, $String*, $URL*)},
	{"getHttpLogger", "()Lsun/util/logging/PlatformLogger;", nullptr, $PUBLIC | $STATIC, $staticMethod(HttpURLConnection, getHttpLogger, $PlatformLogger*)},
	{"getHttpProxyAuthentication", "(Lsun/net/www/protocol/http/AuthenticationHeader;)Lsun/net/www/protocol/http/AuthenticationInfo;", nullptr, $PRIVATE, $method(HttpURLConnection, getHttpProxyAuthentication, $AuthenticationInfo*, $AuthenticationHeader*)},
	{"getInputStream", "()Ljava/io/InputStream;", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection, getInputStream, $InputStream*), "java.io.IOException"},
	{"getInputStream0", "()Ljava/io/InputStream;", nullptr, $PRIVATE, $method(HttpURLConnection, getInputStream0, $InputStream*), "java.io.IOException"},
	{"getMethod", "()Ljava/lang/String;", nullptr, 0, $virtualMethod(HttpURLConnection, getMethod, $String*)},
	{"getNetProperty", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(HttpURLConnection, getNetProperty, $String*, $String*)},
	{"getNewHttpClient", "(Ljava/net/URL;Ljava/net/Proxy;I)Lsun/net/www/http/HttpClient;", nullptr, $PROTECTED, $virtualMethod(HttpURLConnection, getNewHttpClient, $HttpClient*, $URL*, $Proxy*, int32_t), "java.io.IOException"},
	{"getNewHttpClient", "(Ljava/net/URL;Ljava/net/Proxy;IZ)Lsun/net/www/http/HttpClient;", nullptr, $PROTECTED, $virtualMethod(HttpURLConnection, getNewHttpClient, $HttpClient*, $URL*, $Proxy*, int32_t, bool), "java.io.IOException"},
	{"getOutputStream", "()Ljava/io/OutputStream;", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection, getOutputStream, $OutputStream*), "java.io.IOException"},
	{"getOutputStream0", "()Ljava/io/OutputStream;", nullptr, $PRIVATE, $method(HttpURLConnection, getOutputStream0, $OutputStream*), "java.io.IOException"},
	{"getReadTimeout", "()I", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection, getReadTimeout, int32_t)},
	{"getRequestProperties", "()Ljava/util/Map;", "()Ljava/util/Map<Ljava/lang/String;Ljava/util/List<Ljava/lang/String;>;>;", $PUBLIC, $virtualMethod(HttpURLConnection, getRequestProperties, $Map*)},
	{"getRequestProperty", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection, getRequestProperty, $String*, $String*)},
	{"getRequestURI", "()Ljava/lang/String;", nullptr, 0, $virtualMethod(HttpURLConnection, getRequestURI, $String*), "java.io.IOException"},
	{"getServerAuthentication", "(Lsun/net/www/protocol/http/AuthenticationHeader;)Lsun/net/www/protocol/http/AuthenticationInfo;", nullptr, $PRIVATE, $method(HttpURLConnection, getServerAuthentication, $AuthenticationInfo*, $AuthenticationHeader*)},
	{"getUserSetHeaders", "()Lsun/net/www/MessageHeader;", nullptr, 0, $virtualMethod(HttpURLConnection, getUserSetHeaders, $MessageHeader*)},
	{"hostsEqual", "(Ljava/net/URL;Ljava/net/URL;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(HttpURLConnection, hostsEqual, bool, $URL*, $URL*)},
	{"isExternalMessageHeaderAllowed", "(Ljava/lang/String;Ljava/lang/String;)Z", nullptr, $PRIVATE, $method(HttpURLConnection, isExternalMessageHeaderAllowed, bool, $String*, $String*)},
	{"isLockHeldByCurrentThread", "()Z", nullptr, $PUBLIC | $FINAL, $method(HttpURLConnection, isLockHeldByCurrentThread, bool)},
	{"isRestrictedHeader", "(Ljava/lang/String;Ljava/lang/String;)Z", nullptr, $PRIVATE, $method(HttpURLConnection, isRestrictedHeader, bool, $String*, $String*)},
	{"lambda$getNetProperty$0", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(HttpURLConnection, lambda$getNetProperty$0, $String*, $String*)},
	{"lock", "()V", nullptr, $PRIVATE | $FINAL, $method(HttpURLConnection, lock, void)},
	{"mapToMessageHeader", "(Ljava/util/Map;)Lsun/net/www/MessageHeader;", "(Ljava/util/Map<Ljava/lang/String;Ljava/util/List<Ljava/lang/String;>;>;)Lsun/net/www/MessageHeader;", $PRIVATE, $method(HttpURLConnection, mapToMessageHeader, $MessageHeader*, $Map*)},
	{"openConnectionCheckRedirects", "(Ljava/net/URLConnection;)Ljava/io/InputStream;", nullptr, $PUBLIC | $STATIC, $staticMethod(HttpURLConnection, openConnectionCheckRedirects, $InputStream*, $URLConnection*), "java.io.IOException"},
	{"plainConnect", "()V", nullptr, $PROTECTED, $virtualMethod(HttpURLConnection, plainConnect, void), "java.io.IOException"},
	{"plainConnect0", "()V", nullptr, $PROTECTED, $virtualMethod(HttpURLConnection, plainConnect0, void), "java.io.IOException"},
	{"privilegedRequestPasswordAuthentication", "(Ljava/net/Authenticator;Ljava/lang/String;Ljava/net/InetAddress;ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/net/URL;Ljava/net/Authenticator$RequestorType;)Ljava/net/PasswordAuthentication;", nullptr, $PRIVATE | $STATIC, $staticMethod(HttpURLConnection, privilegedRequestPasswordAuthentication, $PasswordAuthentication*, $Authenticator*, $String*, $InetAddress*, int32_t, $String*, $String*, $String*, $URL*, $Authenticator$RequestorType*)},
	{"proxiedConnect", "(Ljava/net/URL;Ljava/lang/String;IZ)V", nullptr, $PROTECTED, $virtualMethod(HttpURLConnection, proxiedConnect, void, $URL*, $String*, int32_t, bool), "java.io.IOException"},
	{"reset", "()V", nullptr, $PRIVATE, $method(HttpURLConnection, reset, void), "java.io.IOException"},
	{"resetProxyAuthentication", "(Lsun/net/www/protocol/http/AuthenticationInfo;Lsun/net/www/protocol/http/AuthenticationHeader;)Lsun/net/www/protocol/http/AuthenticationInfo;", nullptr, $PRIVATE, $method(HttpURLConnection, resetProxyAuthentication, $AuthenticationInfo*, $AuthenticationInfo*, $AuthenticationHeader*), "java.io.IOException"},
	{"sameDestination", "(Ljava/net/URL;Ljava/net/URL;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(HttpURLConnection, sameDestination, bool, $URL*, $URL*)},
	{"schemesListToSet", "(Ljava/lang/String;)Ljava/util/Set;", "(Ljava/lang/String;)Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE | $STATIC, $staticMethod(HttpURLConnection, schemesListToSet, $Set*, $String*)},
	{"sendCONNECTRequest", "()V", nullptr, $PRIVATE, $method(HttpURLConnection, sendCONNECTRequest, void), "java.io.IOException"},
	{"setAuthenticationProperty", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection, setAuthenticationProperty, void, $String*, $String*)},
	{"setAuthenticator", "(Ljava/net/Authenticator;)V", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection, setAuthenticator, void, $Authenticator*)},
	{"setConnectTimeout", "(I)V", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection, setConnectTimeout, void, int32_t)},
	{"setCookieHeader", "()V", nullptr, $PRIVATE, $method(HttpURLConnection, setCookieHeader, void), "java.io.IOException"},
	{"setDefaultAuthenticator", "(Lsun/net/www/protocol/http/HttpAuthenticator;)V", nullptr, $PUBLIC | $STATIC | $DEPRECATED, $staticMethod(HttpURLConnection, setDefaultAuthenticator, void, $HttpAuthenticator*), nullptr, nullptr, _HttpURLConnection_MethodAnnotations_setDefaultAuthenticator74},
	{"setNewClient", "(Ljava/net/URL;)V", nullptr, $PROTECTED, $virtualMethod(HttpURLConnection, setNewClient, void, $URL*), "java.io.IOException"},
	{"setNewClient", "(Ljava/net/URL;Z)V", nullptr, $PROTECTED, $virtualMethod(HttpURLConnection, setNewClient, void, $URL*, bool), "java.io.IOException"},
	{"setPreemptiveProxyAuthentication", "(Lsun/net/www/MessageHeader;)V", nullptr, $PRIVATE, $method(HttpURLConnection, setPreemptiveProxyAuthentication, void, $MessageHeader*), "java.io.IOException"},
	{"setProxiedClient", "(Ljava/net/URL;Ljava/lang/String;I)V", nullptr, $PROTECTED, $virtualMethod(HttpURLConnection, setProxiedClient, void, $URL*, $String*, int32_t), "java.io.IOException"},
	{"setProxiedClient", "(Ljava/net/URL;Ljava/lang/String;IZ)V", nullptr, $PROTECTED, $virtualMethod(HttpURLConnection, setProxiedClient, void, $URL*, $String*, int32_t, bool), "java.io.IOException"},
	{"setReadTimeout", "(I)V", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection, setReadTimeout, void, int32_t)},
	{"setRequestMethod", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection, setRequestMethod, void, $String*), "java.net.ProtocolException"},
	{"setRequestProperty", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection, setRequestProperty, void, $String*, $String*)},
	{"setTunnelState", "(Lsun/net/www/protocol/http/HttpURLConnection$TunnelState;)V", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection, setTunnelState, void, $HttpURLConnection$TunnelState*)},
	{"streaming", "()Z", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection, streaming, bool)},
	{"stripIPv6ZoneId", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $STATIC, $staticMethod(HttpURLConnection, stripIPv6ZoneId, $String*, $String*)},
	{"tunnelState", "()Lsun/net/www/protocol/http/HttpURLConnection$TunnelState;", nullptr, 0, $virtualMethod(HttpURLConnection, tunnelState, $HttpURLConnection$TunnelState*)},
	{"unlock", "()V", nullptr, $PRIVATE | $FINAL, $method(HttpURLConnection, unlock, void)},
	{"usingProxy", "()Z", nullptr, $PUBLIC, $virtualMethod(HttpURLConnection, usingProxy, bool)},
	{"usingProxyInternal", "()Z", nullptr, 0, $virtualMethod(HttpURLConnection, usingProxyInternal, bool)},
	{"writeRequests", "()V", nullptr, $PRIVATE, $method(HttpURLConnection, writeRequests, void), "java.io.IOException"},
	{}
};

$InnerClassInfo _HttpURLConnection_InnerClassesInfo_[] = {
	{"sun.net.www.protocol.http.HttpURLConnection$13", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{"sun.net.www.protocol.http.HttpURLConnection$ErrorStream", "sun.net.www.protocol.http.HttpURLConnection", "ErrorStream", $STATIC},
	{"sun.net.www.protocol.http.HttpURLConnection$StreamingOutputStream", "sun.net.www.protocol.http.HttpURLConnection", "StreamingOutputStream", 0},
	{"sun.net.www.protocol.http.HttpURLConnection$HttpInputStream", "sun.net.www.protocol.http.HttpURLConnection", "HttpInputStream", 0},
	{"sun.net.www.protocol.http.HttpURLConnection$TunnelState", "sun.net.www.protocol.http.HttpURLConnection", "TunnelState", $PUBLIC | $STATIC | $FINAL | $ENUM},
	{"sun.net.www.protocol.http.HttpURLConnection$12", nullptr, nullptr, 0},
	{"sun.net.www.protocol.http.HttpURLConnection$11", nullptr, nullptr, 0},
	{"sun.net.www.protocol.http.HttpURLConnection$10", nullptr, nullptr, 0},
	{"sun.net.www.protocol.http.HttpURLConnection$9", nullptr, nullptr, 0},
	{"sun.net.www.protocol.http.HttpURLConnection$8", nullptr, nullptr, 0},
	{"sun.net.www.protocol.http.HttpURLConnection$7", nullptr, nullptr, 0},
	{"sun.net.www.protocol.http.HttpURLConnection$6", nullptr, nullptr, 0},
	{"sun.net.www.protocol.http.HttpURLConnection$5", nullptr, nullptr, 0},
	{"sun.net.www.protocol.http.HttpURLConnection$4", nullptr, nullptr, 0},
	{"sun.net.www.protocol.http.HttpURLConnection$3", nullptr, nullptr, 0},
	{"sun.net.www.protocol.http.HttpURLConnection$2", nullptr, nullptr, 0},
	{"sun.net.www.protocol.http.HttpURLConnection$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _HttpURLConnection_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.net.www.protocol.http.HttpURLConnection",
	"java.net.HttpURLConnection",
	nullptr,
	_HttpURLConnection_FieldInfo_,
	_HttpURLConnection_MethodInfo_,
	nullptr,
	nullptr,
	_HttpURLConnection_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.net.www.protocol.http.HttpURLConnection$13,sun.net.www.protocol.http.HttpURLConnection$ErrorStream,sun.net.www.protocol.http.HttpURLConnection$StreamingOutputStream,sun.net.www.protocol.http.HttpURLConnection$HttpInputStream,sun.net.www.protocol.http.HttpURLConnection$TunnelState,sun.net.www.protocol.http.HttpURLConnection$12,sun.net.www.protocol.http.HttpURLConnection$11,sun.net.www.protocol.http.HttpURLConnection$10,sun.net.www.protocol.http.HttpURLConnection$9,sun.net.www.protocol.http.HttpURLConnection$8,sun.net.www.protocol.http.HttpURLConnection$7,sun.net.www.protocol.http.HttpURLConnection$6,sun.net.www.protocol.http.HttpURLConnection$5,sun.net.www.protocol.http.HttpURLConnection$4,sun.net.www.protocol.http.HttpURLConnection$3,sun.net.www.protocol.http.HttpURLConnection$2,sun.net.www.protocol.http.HttpURLConnection$1"
};

$Object* allocate$HttpURLConnection($Class* clazz) {
	return $of($alloc(HttpURLConnection));
}

bool HttpURLConnection::$assertionsDisabled = false;
$String* HttpURLConnection::HTTP_CONNECT = nullptr;
$String* HttpURLConnection::version = nullptr;
$String* HttpURLConnection::userAgent = nullptr;
int32_t HttpURLConnection::maxRedirects = 0;
bool HttpURLConnection::validateProxy = false;
bool HttpURLConnection::validateServer = false;
$Set* HttpURLConnection::disabledProxyingSchemes = nullptr;
$Set* HttpURLConnection::disabledTunnelingSchemes = nullptr;
$String* HttpURLConnection::RETRY_MSG1 = nullptr;
$String* HttpURLConnection::RETRY_MSG2 = nullptr;
$String* HttpURLConnection::RETRY_MSG3 = nullptr;
bool HttpURLConnection::enableESBuffer = false;
int32_t HttpURLConnection::timeout4ESBuffer = 0;
int32_t HttpURLConnection::bufSize4ES = 0;
bool HttpURLConnection::allowRestrictedHeaders = false;
$Set* HttpURLConnection::restrictedHeaderSet = nullptr;
$StringArray* HttpURLConnection::restrictedHeaders = nullptr;
$String* HttpURLConnection::httpVersion = nullptr;
$String* HttpURLConnection::acceptString = nullptr;
$StringArray* HttpURLConnection::EXCLUDE_HEADERS = nullptr;
$StringArray* HttpURLConnection::EXCLUDE_HEADERS2 = nullptr;
$HttpAuthenticator* HttpURLConnection::defaultAuth = nullptr;
$PlatformLogger* HttpURLConnection::logger = nullptr;
$String* HttpURLConnection::SET_COOKIE = nullptr;
$String* HttpURLConnection::SET_COOKIE2 = nullptr;

$String* HttpURLConnection::getNetProperty($String* name) {
	$init(HttpURLConnection);
	$beforeCallerSensitive();
	$var($PrivilegedAction, pa, static_cast<$PrivilegedAction*>($new(HttpURLConnection$$Lambda$lambda$getNetProperty$0, name)));
	return $cast($String, $AccessController::doPrivileged(pa));
}

$Set* HttpURLConnection::schemesListToSet($String* list) {
	$init(HttpURLConnection);
	$useLocalCurrentObjectStackCache();
	if (list == nullptr || $nc(list)->isEmpty()) {
		return $Collections::emptySet();
	}
	$var($Set, s, $new($HashSet));
	$var($StringArray, parts, $nc(list)->split("\\s*,\\s*"_s));
	{
		$var($StringArray, arr$, parts);
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, part, arr$->get(i$));
			$init($Locale);
			s->add($($nc(part)->toLowerCase($Locale::ROOT)));
		}
	}
	return s;
}

void HttpURLConnection::lock() {
	$nc(this->connectionLock)->lock();
}

void HttpURLConnection::unlock() {
	$nc(this->connectionLock)->unlock();
}

bool HttpURLConnection::isLockHeldByCurrentThread() {
	return $nc(this->connectionLock)->isHeldByCurrentThread();
}

$PasswordAuthentication* HttpURLConnection::privilegedRequestPasswordAuthentication($Authenticator* authenticator, $String* host, $InetAddress* addr, int32_t port, $String* protocol, $String* prompt, $String* scheme, $URL* url, $Authenticator$RequestorType* authType) {
	$init(HttpURLConnection);
	$beforeCallerSensitive();
	return $cast($PasswordAuthentication, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($HttpURLConnection$1, host, url, authenticator, addr, port, protocol, prompt, scheme, authType))));
}

bool HttpURLConnection::isRestrictedHeader($String* key$renamed, $String* value) {
	$var($String, key, key$renamed);
	if (HttpURLConnection::allowRestrictedHeaders) {
		return false;
	}
	$assign(key, $nc(key)->toLowerCase());
	if ($nc(HttpURLConnection::restrictedHeaderSet)->contains(key)) {
		bool var$0 = key->equals("connection"_s);
		if (var$0 && $nc(value)->equalsIgnoreCase("close"_s)) {
			return false;
		}
		return true;
	} else if (key->startsWith("sec-"_s)) {
		return true;
	}
	return false;
}

bool HttpURLConnection::isExternalMessageHeaderAllowed($String* key, $String* value) {
	checkMessageHeader(key, value);
	if (!isRestrictedHeader(key, value)) {
		return true;
	}
	return false;
}

$PlatformLogger* HttpURLConnection::getHttpLogger() {
	$init(HttpURLConnection);
	return HttpURLConnection::logger;
}

$Object* HttpURLConnection::authObj() {
	return $of(this->authObj$);
}

void HttpURLConnection::authObj(Object$* authObj) {
	$set(this, authObj$, authObj);
}

void HttpURLConnection::setAuthenticator($Authenticator* auth) {
	lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			if (this->connecting || this->connected) {
				$throwNew($IllegalStateException, "Authenticator must be set before connecting"_s);
			}
			$set(this, authenticator, $cast($Authenticator, $Objects::requireNonNull(auth)));
			$set(this, authenticatorKey, $AuthenticatorKeys::getKey(this->authenticator));
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

$String* HttpURLConnection::getAuthenticatorKey() {
	$var($String, k, this->authenticatorKey);
	if (k == nullptr) {
		return $AuthenticatorKeys::getKey(this->authenticator);
	}
	return k;
}

void HttpURLConnection::checkMessageHeader($String* key, $String* value) {
	$useLocalCurrentObjectStackCache();
	char16_t LF = u'\n';
	int32_t index = $nc(key)->indexOf((int32_t)LF);
	int32_t index1 = key->indexOf((int32_t)u':');
	if (index != -1 || index1 != -1) {
		$throwNew($IllegalArgumentException, $$str({"Illegal character(s) in message header field: "_s, key}));
	} else {
		if (value == nullptr) {
			return;
		}
		index = $nc(value)->indexOf((int32_t)LF);
		while (index != -1) {
			++index;
			if (index < value->length()) {
				char16_t c = value->charAt(index);
				if ((c == u' ') || (c == u'\t')) {
					index = value->indexOf((int32_t)LF, index);
					continue;
				}
			}
			$throwNew($IllegalArgumentException, $$str({"Illegal character(s) in message header value: "_s, value}));
		}
	}
}

void HttpURLConnection::setRequestMethod($String* method) {
	lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			if (this->connecting) {
				$throwNew($IllegalStateException, "connect in progress"_s);
			}
			$HttpURLConnection::setRequestMethod(method);
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void HttpURLConnection::writeRequests() {
	$useLocalCurrentObjectStackCache();
	if (!HttpURLConnection::$assertionsDisabled && !isLockHeldByCurrentThread()) {
		$throwNew($AssertionError);
	}
	$init($HttpURLConnection$TunnelState);
	if ($nc(this->http)->usingProxy && tunnelState() != $HttpURLConnection$TunnelState::TUNNELING) {
		setPreemptiveProxyAuthentication(this->requests);
	}
	if (!this->setRequests) {
		if (!this->failedOnce) {
			checkURLFile();
			$nc(this->requests)->prepend($$str({this->method, " "_s, $(getRequestURI()), " "_s, HttpURLConnection::httpVersion}), nullptr);
		}
		if (!getUseCaches()) {
			$nc(this->requests)->setIfNotSet("Cache-Control"_s, "no-cache"_s);
			$nc(this->requests)->setIfNotSet("Pragma"_s, "no-cache"_s);
		}
		$nc(this->requests)->setIfNotSet("User-Agent"_s, HttpURLConnection::userAgent);
		int32_t port = $nc(this->url)->getPort();
		$var($String, host, stripIPv6ZoneId($($nc(this->url)->getHost())));
		if (port != -1 && port != $nc(this->url)->getDefaultPort()) {
			$plusAssign(host, $$str({":"_s, $($String::valueOf(port))}));
		}
		$var($String, reqHost, $nc(this->requests)->findValue("Host"_s));
		bool var$0 = reqHost == nullptr;
		if (!var$0) {
			bool var$1 = !$nc(reqHost)->equalsIgnoreCase(host);
			var$0 = (var$1 && !checkSetHost());
		}
		if (var$0) {
			$nc(this->requests)->set("Host"_s, host);
		}
		$nc(this->requests)->setIfNotSet("Accept"_s, HttpURLConnection::acceptString);
		if (!this->failedOnce && $nc(this->http)->getHttpKeepAliveSet()) {
			if ($nc(this->http)->usingProxy && tunnelState() != $HttpURLConnection$TunnelState::TUNNELING) {
				$nc(this->requests)->setIfNotSet("Proxy-Connection"_s, "keep-alive"_s);
			} else {
				$nc(this->requests)->setIfNotSet("Connection"_s, "keep-alive"_s);
			}
		} else {
			$nc(this->requests)->setIfNotSet("Connection"_s, "close"_s);
		}
		int64_t modTime = getIfModifiedSince();
		if (modTime != 0) {
			$var($Date, date, $new($Date, modTime));
			$init($Locale);
			$var($SimpleDateFormat, fo, $new($SimpleDateFormat, "EEE, dd MMM yyyy HH:mm:ss \'GMT\'"_s, $Locale::US));
			fo->setTimeZone($($TimeZone::getTimeZone("GMT"_s)));
			$nc(this->requests)->setIfNotSet("If-Modified-Since"_s, $(fo->format(date)));
		}
		$var($AuthenticationInfo, sauth, $AuthenticationInfo::getServerAuth(this->url, $(getAuthenticatorKey())));
		if (sauth != nullptr && sauth->supportsPreemptiveAuthorization()) {
			$var($String, var$2, sauth->getHeaderName());
			$nc(this->requests)->setIfNotSet(var$2, $(sauth->getHeaderValue(this->url, this->method)));
			$set(this, currentServerCredentials, sauth);
		}
		bool var$3 = !$nc(this->method)->equals("PUT"_s);
		if (var$3 && (this->poster != nullptr || streaming())) {
			$nc(this->requests)->setIfNotSet("Content-type"_s, "application/x-www-form-urlencoded"_s);
		}
		bool chunked = false;
		if (streaming()) {
			if (this->chunkLength != -1) {
				$nc(this->requests)->set("Transfer-Encoding"_s, "chunked"_s);
				chunked = true;
			} else if (this->fixedContentLengthLong != -1) {
				$nc(this->requests)->set("Content-Length"_s, $($String::valueOf(this->fixedContentLengthLong)));
			} else if (this->fixedContentLength != -1) {
				$nc(this->requests)->set("Content-Length"_s, $($String::valueOf(this->fixedContentLength)));
			}
		} else if (this->poster != nullptr) {
			$synchronized(this->poster) {
				$nc(this->poster)->close();
				$nc(this->requests)->set("Content-Length"_s, $($String::valueOf($nc(this->poster)->size())));
			}
		}
		if (!chunked) {
			if ($nc(this->requests)->findValue("Transfer-Encoding"_s) != nullptr) {
				$nc(this->requests)->remove("Transfer-Encoding"_s);
				$init($PlatformLogger$Level);
				if ($nc(HttpURLConnection::logger)->isLoggable($PlatformLogger$Level::WARNING)) {
					$nc(HttpURLConnection::logger)->warning("use streaming mode for chunked encoding"_s);
				}
			}
		}
		setCookieHeader();
		this->setRequests = true;
	}
	$init($PlatformLogger$Level);
	if ($nc(HttpURLConnection::logger)->isLoggable($PlatformLogger$Level::FINE)) {
		$nc(HttpURLConnection::logger)->fine($($nc(this->requests)->toString()));
	}
	$nc(this->http)->writeRequests(this->requests, this->poster, streaming());
	if ($nc(this->ps)->checkError()) {
		$var($String, proxyHost, $nc(this->http)->getProxyHostUsed());
		int32_t proxyPort = $nc(this->http)->getProxyPortUsed();
		disconnectInternal();
		if (this->failedOnce) {
			$throwNew($IOException, "Error writing to server"_s);
		} else {
			this->failedOnce = true;
			if (proxyHost != nullptr) {
				setProxiedClient(this->url, proxyHost, proxyPort);
			} else {
				setNewClient(this->url);
			}
			$set(this, ps, $cast($PrintStream, $nc(this->http)->getOutputStream()));
			this->connected = true;
			$set(this, responses, $new($MessageHeader));
			this->setRequests = false;
			writeRequests();
		}
	}
}

bool HttpURLConnection::checkSetHost() {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, s, $System::getSecurityManager());
	if (s != nullptr) {
		$var($String, name, $of(s)->getClass()->getName());
		bool var$2 = $nc(name)->equals("sun.plugin2.applet.AWTAppletSecurityManager"_s);
		bool var$1 = var$2 || $nc(name)->equals("sun.plugin2.applet.FXAppletSecurityManager"_s);
		bool var$0 = var$1 || $nc(name)->equals("com.sun.javaws.security.JavaWebStartSecurity"_s);
		if (var$0 || $nc(name)->equals("sun.plugin.security.ActivatorSecurityManager"_s)) {
			int32_t CHECK_SET_HOST = -2;
			try {
				s->checkConnect($($nc(this->url)->toExternalForm()), CHECK_SET_HOST);
			} catch ($SecurityException& ex) {
				return false;
			}
		}
	}
	return true;
}

void HttpURLConnection::checkURLFile() {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, s, $System::getSecurityManager());
	if (s != nullptr) {
		$var($String, name, $of(s)->getClass()->getName());
		bool var$2 = $nc(name)->equals("sun.plugin2.applet.AWTAppletSecurityManager"_s);
		bool var$1 = var$2 || $nc(name)->equals("sun.plugin2.applet.FXAppletSecurityManager"_s);
		bool var$0 = var$1 || $nc(name)->equals("com.sun.javaws.security.JavaWebStartSecurity"_s);
		if (var$0 || $nc(name)->equals("sun.plugin.security.ActivatorSecurityManager"_s)) {
			int32_t CHECK_SUBPATH = -3;
			try {
				s->checkConnect($($nc(this->url)->toExternalForm()), CHECK_SUBPATH);
			} catch ($SecurityException& ex) {
				$throwNew($SecurityException, "denied access outside a permitted URL subpath"_s, ex);
			}
		}
	}
}

void HttpURLConnection::setNewClient($URL* url) {
	setNewClient(url, false);
}

void HttpURLConnection::setNewClient($URL* url, bool useCache) {
	$set(this, http, $HttpClient::New(url, nullptr, -1, useCache, this->connectTimeout, this));
	$nc(this->http)->setReadTimeout(this->readTimeout);
}

void HttpURLConnection::setProxiedClient($URL* url, $String* proxyHost, int32_t proxyPort) {
	setProxiedClient(url, proxyHost, proxyPort, false);
}

void HttpURLConnection::setProxiedClient($URL* url, $String* proxyHost, int32_t proxyPort, bool useCache) {
	proxiedConnect(url, proxyHost, proxyPort, useCache);
}

void HttpURLConnection::proxiedConnect($URL* url, $String* proxyHost, int32_t proxyPort, bool useCache) {
	$set(this, http, $HttpClient::New(url, proxyHost, proxyPort, useCache, this->connectTimeout, this));
	$nc(this->http)->setReadTimeout(this->readTimeout);
}

void HttpURLConnection::init$($URL* u, $Handler* handler) {
	HttpURLConnection::init$(u, ($Proxy*)nullptr, handler);
}

$String* HttpURLConnection::checkHost($String* h) {
	$init(HttpURLConnection);
	if (h != nullptr) {
		if (h->indexOf((int32_t)u'\n') > -1) {
			$throwNew($MalformedURLException, "Illegal character in host"_s);
		}
	}
	return h;
}

void HttpURLConnection::init$($URL* u, $String* host, int32_t port) {
	$useLocalCurrentObjectStackCache();
	$init($Proxy$Type);
	HttpURLConnection::init$(u, $$new($Proxy, $Proxy$Type::HTTP, $($InetSocketAddress::createUnresolved($(checkHost(host)), port))));
}

void HttpURLConnection::init$($URL* u, $Proxy* p) {
	HttpURLConnection::init$(u, p, $$new($Handler));
}

$URL* HttpURLConnection::checkURL($URL* u) {
	$init(HttpURLConnection);
	$useLocalCurrentObjectStackCache();
	if (u != nullptr) {
		if ($nc($(u->toExternalForm()))->indexOf((int32_t)u'\n') > -1) {
			$throwNew($MalformedURLException, "Illegal character in URL"_s);
		}
	}
	$var($String, s, $IPAddressUtil::checkAuthority(u));
	if (s != nullptr) {
		$throwNew($MalformedURLException, s);
	}
	return u;
}

void HttpURLConnection::init$($URL* u, $Proxy* p, $Handler* handler) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$HttpURLConnection::init$($(checkURL(u)));
	$set(this, ps, nullptr);
	$set(this, errorStream, nullptr);
	this->setUserCookies = true;
	$set(this, userCookies, nullptr);
	$set(this, userCookies2, nullptr);
	this->connecting = false;
	$set(this, currentProxyCredentials, nullptr);
	$set(this, currentServerCredentials, nullptr);
	this->needToCheck = true;
	this->doingNTLM2ndStage = false;
	this->doingNTLMp2ndStage = false;
	this->tryTransparentNTLMServer = true;
	this->tryTransparentNTLMProxy = true;
	this->useProxyResponseCode = false;
	$set(this, inputStream, nullptr);
	$set(this, poster, nullptr);
	this->setRequests = false;
	this->failedOnce = false;
	$set(this, rememberedException, nullptr);
	$set(this, reuseClient, nullptr);
	$init($HttpURLConnection$TunnelState);
	$set(this, tunnelState$, $HttpURLConnection$TunnelState::NONE);
	this->connectTimeout = $NetworkClient::DEFAULT_CONNECT_TIMEOUT;
	this->readTimeout = $NetworkClient::DEFAULT_READ_TIMEOUT;
	$set(this, connectionLock, $new($ReentrantLock));
	$set(this, requestURI, nullptr);
	$set(this, cdata, $new($bytes, 128));
	$set(this, requests, $new($MessageHeader));
	$set(this, responses, $new($MessageHeader));
	$set(this, userHeaders, $new($MessageHeader));
	$set(this, handler, handler);
	$set(this, instProxy, p);
	if ($instanceOf($ApplicationProxy, this->instProxy)) {
		try {
			$set(this, cookieHandler, $CookieHandler::getDefault());
		} catch ($SecurityException& se) {
		}
	} else {
		$set(this, cookieHandler, $cast($CookieHandler, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($HttpURLConnection$2, this)))));
	}
	$set(this, cacheHandler, $cast($ResponseCache, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($HttpURLConnection$3, this)))));
}

void HttpURLConnection::setDefaultAuthenticator($HttpAuthenticator* a) {
	$init(HttpURLConnection);
	$assignStatic(HttpURLConnection::defaultAuth, a);
}

$InputStream* HttpURLConnection::openConnectionCheckRedirects($URLConnection* c$renamed) {
	$init(HttpURLConnection);
	$useLocalCurrentObjectStackCache();
	$var($URLConnection, c, c$renamed);
	bool redir = false;
	int32_t redirects = 0;
	$var($InputStream, in, nullptr);
	$var($Authenticator, a, nullptr);
	do {
		if ($instanceOf(HttpURLConnection, c)) {
			$nc(($cast(HttpURLConnection, c)))->setInstanceFollowRedirects(false);
			if (a == nullptr) {
				$assign(a, ($cast(HttpURLConnection, c))->authenticator);
			}
		}
		$assign(in, $nc(c)->getInputStream());
		redir = false;
		if ($instanceOf(HttpURLConnection, c)) {
			$var(HttpURLConnection, http, $cast(HttpURLConnection, c));
			int32_t stat = http->getResponseCode();
			if (stat >= 300 && stat <= 307 && stat != 306 && stat != HttpURLConnection::HTTP_NOT_MODIFIED) {
				$var($URL, base, http->getURL());
				$var($String, loc, http->getHeaderField("Location"_s));
				$var($URL, target, nullptr);
				if (loc != nullptr) {
					$assign(target, $new($URL, base, loc));
				}
				http->disconnect();
				bool var$1 = target == nullptr || !$nc($($nc(base)->getProtocol()))->equals($($nc(target)->getProtocol()));
				if (!var$1) {
					int32_t var$2 = $nc(base)->getPort();
					var$1 = var$2 != $nc(target)->getPort();
				}
				bool var$0 = var$1;
				if (var$0 || !hostsEqual(base, target) || redirects >= 5) {
					$throwNew($SecurityException, "illegal URL redirect"_s);
				}
				redir = true;
				$assign(c, $nc(target)->openConnection());
				if (a != nullptr && $instanceOf(HttpURLConnection, c)) {
					$nc(($cast(HttpURLConnection, c)))->setAuthenticator(a);
				}
				++redirects;
			}
		}
	} while (redir);
	return in;
}

bool HttpURLConnection::hostsEqual($URL* u1, $URL* u2) {
	$init(HttpURLConnection);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($String, h1, $nc(u1)->getHost());
	$var($String, h2, $nc(u2)->getHost());
	if (h1 == nullptr) {
		return h2 == nullptr;
	} else if (h2 == nullptr) {
		return false;
	} else if ($nc(h1)->equalsIgnoreCase(h2)) {
		return true;
	}
	$var($booleans, result, $new($booleans, {false}));
	$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($HttpURLConnection$4, h1, h2, result)));
	return result->get(0);
}

void HttpURLConnection::connect() {
	lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			this->connecting = true;
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	plainConnect();
}

bool HttpURLConnection::checkReuseConnection() {
	if (this->connected) {
		return true;
	}
	if (this->reuseClient != nullptr) {
		$set(this, http, this->reuseClient);
		$nc(this->http)->setReadTimeout(getReadTimeout());
		$nc(this->http)->reuse = false;
		$set(this, reuseClient, nullptr);
		this->connected = true;
		return true;
	}
	return false;
}

$String* HttpURLConnection::getHostAndPort($URL* url) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($String, host, $nc(url)->getHost());
	$var($String, hostarg, host);
	try {
		$assign(host, $cast($String, $AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new($HttpURLConnection$5, this, hostarg)))));
	} catch ($PrivilegedActionException& e) {
	}
	int32_t port = url->getPort();
	if (port == -1) {
		$var($String, scheme, url->getProtocol());
		if ("http"_s->equals(scheme)) {
			return $str({host, ":80"_s});
		} else {
			return $str({host, ":443"_s});
		}
	}
	return $str({host, ":"_s, $($Integer::toString(port))});
}

void HttpURLConnection::plainConnect() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	lock();
	{
		$var($Throwable, var$0, nullptr);
		bool return$1 = false;
		try {
			if (this->connected) {
				return$1 = true;
				goto $finally;
			}
		} catch ($Throwable& var$2) {
			$assign(var$0, var$2);
		} $finally: {
			unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return;
		}
	}
	$var($SocketPermission, p, URLtoSocketPermission(this->url));
	if (p != nullptr) {
		try {
			$AccessController::doPrivilegedWithCombiner(static_cast<$PrivilegedExceptionAction*>($$new($HttpURLConnection$6, this)), ($AccessControlContext*)nullptr, $$new($PermissionArray, {static_cast<$Permission*>(p)}));
		} catch ($PrivilegedActionException& e) {
			$throw($cast($IOException, $(e->getException())));
		}
	} else {
		plainConnect0();
	}
}

$SocketPermission* HttpURLConnection::URLtoSocketPermission($URL* url) {
	$useLocalCurrentObjectStackCache();
	if (this->socketPermission != nullptr) {
		return this->socketPermission;
	}
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm == nullptr) {
		return nullptr;
	}
	$var($SocketPermission, newPerm, $new($SocketPermission, $(getHostAndPort(url)), "connect"_s));
	$var($String, var$0, $$str({$(getRequestMethod()), ":"_s}));
	$var($String, actions, $concat(var$0, $($nc($(getUserSetHeaders()))->getHeaderNamesInList())));
	$var($String, var$2, $$str({$($nc(url)->getProtocol()), "://"_s}));
	$var($String, var$1, $$concat(var$2, $(url->getAuthority())));
	$var($String, urlstring, $concat(var$1, $(url->getPath())));
	$var($URLPermission, p, $new($URLPermission, urlstring, actions));
	try {
		$nc(sm)->checkPermission(p);
		$set(this, socketPermission, newPerm);
		return this->socketPermission;
	} catch ($SecurityException& e) {
	}
	return nullptr;
}

void HttpURLConnection::plainConnect0() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (this->cacheHandler != nullptr && getUseCaches()) {
		try {
			$var($URI, uri, $ParseUtil::toURI(this->url));
			if (uri != nullptr) {
				$var($URI, var$0, uri);
				$var($String, var$1, getRequestMethod());
				$set(this, cachedResponse, $nc(this->cacheHandler)->get(var$0, var$1, $($nc($(getUserSetHeaders()))->getHeaders())));
				if ("https"_s->equalsIgnoreCase($(uri->getScheme())) && !($instanceOf($SecureCacheResponse, this->cachedResponse))) {
					$set(this, cachedResponse, nullptr);
				}
				$init($PlatformLogger$Level);
				if ($nc(HttpURLConnection::logger)->isLoggable($PlatformLogger$Level::FINEST)) {
					$var($String, var$2, $$str({"Cache Request for "_s, uri, " / "_s}));
					$nc(HttpURLConnection::logger)->finest($$concat(var$2, $(getRequestMethod())));
					$nc(HttpURLConnection::logger)->finest($$str({"From cache: "_s, (this->cachedResponse != nullptr ? $($nc($of(this->cachedResponse))->toString()) : "null"_s)}));
				}
				if (this->cachedResponse != nullptr) {
					$set(this, cachedHeaders, mapToMessageHeader($($nc(this->cachedResponse)->getHeaders())));
					$set(this, cachedInputStream, $nc(this->cachedResponse)->getBody());
				}
			}
		} catch ($IOException& ioex) {
		}
		if (this->cachedHeaders != nullptr && this->cachedInputStream != nullptr) {
			this->connected = true;
			return;
		} else {
			$set(this, cachedResponse, nullptr);
		}
	}
	try {
		if (this->instProxy == nullptr) {
			$var($ProxySelector, sel, $cast($ProxySelector, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($HttpURLConnection$7, this)))));
			if (sel != nullptr) {
				$var($URI, uri, $ParseUtil::toURI(this->url));
				$init($PlatformLogger$Level);
				if ($nc(HttpURLConnection::logger)->isLoggable($PlatformLogger$Level::FINEST)) {
					$nc(HttpURLConnection::logger)->finest($$str({"ProxySelector Request for "_s, uri}));
				}
				$var($List, proxies, nullptr);
				try {
					$assign(proxies, sel->select(uri));
				} catch ($IllegalArgumentException& iae) {
					$throwNew($IOException, "Failed to select a proxy"_s, iae);
				}
				$var($Iterator, it, $nc(proxies)->iterator());
				$var($Proxy, p, nullptr);
				while ($nc(it)->hasNext()) {
					$assign(p, $cast($Proxy, it->next()));
					try {
						if (!this->failedOnce) {
							$set(this, http, getNewHttpClient(this->url, p, this->connectTimeout));
							$nc(this->http)->setReadTimeout(this->readTimeout);
						} else {
							$set(this, http, getNewHttpClient(this->url, p, this->connectTimeout, false));
							$nc(this->http)->setReadTimeout(this->readTimeout);
						}
						if ($nc(HttpURLConnection::logger)->isLoggable($PlatformLogger$Level::FINEST)) {
							if (p != nullptr) {
								$nc(HttpURLConnection::logger)->finest($$str({"Proxy used: "_s, $(p->toString())}));
							}
						}
						break;
					} catch ($IOException& ioex) {
						$init($Proxy);
						if (p != $Proxy::NO_PROXY) {
							sel->connectFailed(uri, $($nc(p)->address()), ioex);
							if (!it->hasNext()) {
								if ($nc(HttpURLConnection::logger)->isLoggable($PlatformLogger$Level::FINEST)) {
									$nc(HttpURLConnection::logger)->finest($$str({"Retrying with proxy: "_s, $($nc(p)->toString())}));
								}
								$set(this, http, getNewHttpClient(this->url, p, this->connectTimeout, false));
								$nc(this->http)->setReadTimeout(this->readTimeout);
								break;
							}
						} else {
							$throw(ioex);
						}
						continue;
					}
				}
			} else if (!this->failedOnce) {
				$set(this, http, getNewHttpClient(this->url, nullptr, this->connectTimeout));
				$nc(this->http)->setReadTimeout(this->readTimeout);
			} else {
				$set(this, http, getNewHttpClient(this->url, nullptr, this->connectTimeout, false));
				$nc(this->http)->setReadTimeout(this->readTimeout);
			}
		} else if (!this->failedOnce) {
			$set(this, http, getNewHttpClient(this->url, this->instProxy, this->connectTimeout));
			$nc(this->http)->setReadTimeout(this->readTimeout);
		} else {
			$set(this, http, getNewHttpClient(this->url, this->instProxy, this->connectTimeout, false));
			$nc(this->http)->setReadTimeout(this->readTimeout);
		}
		this->usingProxy$ = this->usingProxy$ || usingProxyInternal();
		$set(this, ps, $cast($PrintStream, $nc(this->http)->getOutputStream()));
	} catch ($IOException& e) {
		$throw(e);
	}
	this->connected = true;
}

$HttpClient* HttpURLConnection::getNewHttpClient($URL* url, $Proxy* p, int32_t connectTimeout) {
	return $HttpClient::New(url, p, connectTimeout, this);
}

$HttpClient* HttpURLConnection::getNewHttpClient($URL* url, $Proxy* p, int32_t connectTimeout, bool useCache) {
	return $HttpClient::New(url, p, connectTimeout, useCache, this);
}

void HttpURLConnection::expect100Continue() {
	$useLocalCurrentObjectStackCache();
	int32_t oldTimeout = $nc(this->http)->getReadTimeout();
	bool enforceTimeOut = false;
	bool timedOut = false;
	if (oldTimeout <= 0) {
		$nc(this->http)->setReadTimeout(5000);
		enforceTimeOut = true;
	}
	try {
		$nc(this->http)->parseHTTP(this->responses, this->pi, this);
	} catch ($SocketTimeoutException& se) {
		if (!enforceTimeOut) {
			$throw(se);
		}
		timedOut = true;
		$nc(this->http)->setIgnoreContinue(true);
	}
	if (!timedOut) {
		$var($String, resp, $nc(this->responses)->getValue(0));
		if (resp != nullptr && resp->startsWith("HTTP/"_s)) {
			$var($StringArray, sa, resp->split("\\s+"_s));
			this->responseCode = -1;
			try {
				if (sa->length > 1) {
					this->responseCode = $Integer::parseInt(sa->get(1));
				}
			} catch ($NumberFormatException& numberFormatException) {
			}
		}
		if (this->responseCode != 100) {
			$throwNew($ProtocolException, "Server rejected operation"_s);
		}
	}
	$nc(this->http)->setReadTimeout(oldTimeout);
	this->responseCode = -1;
	$nc(this->responses)->reset();
}

$OutputStream* HttpURLConnection::getOutputStream() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	lock();
	{
		$var($Throwable, var$0, nullptr);
		$var($OutputStream, var$2, nullptr);
		bool return$1 = false;
		try {
			this->connecting = true;
			$var($SocketPermission, p, URLtoSocketPermission(this->url));
			if (p != nullptr) {
				try {
					$assign(var$2, $cast($OutputStream, $AccessController::doPrivilegedWithCombiner(static_cast<$PrivilegedExceptionAction*>($$new($HttpURLConnection$8, this)), ($AccessControlContext*)nullptr, $$new($PermissionArray, {static_cast<$Permission*>(p)}))));
					return$1 = true;
					goto $finally;
				} catch ($PrivilegedActionException& e) {
					$throw($cast($IOException, $(e->getException())));
				}
			} else {
				$assign(var$2, getOutputStream0());
				return$1 = true;
				goto $finally;
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

$OutputStream* HttpURLConnection::getOutputStream0() {
	$useLocalCurrentObjectStackCache();
	if (!HttpURLConnection::$assertionsDisabled && !isLockHeldByCurrentThread()) {
		$throwNew($AssertionError);
	}
	try {
		if (!this->doOutput) {
			$throwNew($ProtocolException, "cannot write to a URLConnection if doOutput=false - call setDoOutput(true)"_s);
		}
		if ($nc(this->method)->equals("GET"_s)) {
			$set(this, method, "POST"_s);
		}
		bool var$0 = "TRACE"_s->equals(this->method);
		if (var$0 && "http"_s->equals($($nc(this->url)->getProtocol()))) {
			$throwNew($ProtocolException, "HTTP method TRACE doesn\'t support output"_s);
		}
		if (this->inputStream != nullptr) {
			$throwNew($ProtocolException, "Cannot write output after reading input."_s);
		}
		if (!checkReuseConnection()) {
			connect();
		}
		bool expectContinue = false;
		$var($String, expects, $nc(this->requests)->findValue("Expect"_s));
		bool var$1 = "100-Continue"_s->equalsIgnoreCase(expects);
		if (var$1 && streaming()) {
			$nc(this->http)->setIgnoreContinue(false);
			expectContinue = true;
		}
		if (streaming() && this->strOutputStream == nullptr) {
			writeRequests();
		}
		if (expectContinue) {
			expect100Continue();
		}
		$set(this, ps, $cast($PrintStream, $nc(this->http)->getOutputStream()));
		if (streaming()) {
			if (this->strOutputStream == nullptr) {
				if (this->chunkLength != -1) {
					$set(this, strOutputStream, $new($HttpURLConnection$StreamingOutputStream, this, $$new($ChunkedOutputStream, this->ps, this->chunkLength), -1));
				} else {
					int64_t length = 0;
					if (this->fixedContentLengthLong != -1) {
						length = this->fixedContentLengthLong;
					} else if (this->fixedContentLength != -1) {
						length = this->fixedContentLength;
					}
					$set(this, strOutputStream, $new($HttpURLConnection$StreamingOutputStream, this, this->ps, length));
				}
			}
			return this->strOutputStream;
		} else {
			if (this->poster == nullptr) {
				$set(this, poster, $new($PosterOutputStream));
			}
			return this->poster;
		}
	} catch ($RuntimeException& e) {
		disconnectInternal();
		$throw(e);
	} catch ($ProtocolException& e) {
		int32_t i = this->responseCode;
		disconnectInternal();
		this->responseCode = i;
		$throw(e);
	} catch ($IOException& e) {
		disconnectInternal();
		$throw(e);
	}
	$shouldNotReachHere();
}

bool HttpURLConnection::streaming() {
	return (this->fixedContentLength != -1) || (this->fixedContentLengthLong != -1) || (this->chunkLength != -1);
}

void HttpURLConnection::setCookieHeader() {
	$useLocalCurrentObjectStackCache();
	if (this->cookieHandler != nullptr) {
		if (!HttpURLConnection::$assertionsDisabled && !isLockHeldByCurrentThread()) {
			$throwNew($AssertionError);
		}
		if (this->setUserCookies) {
			int32_t k = $nc(this->requests)->getKey("Cookie"_s);
			if (k != -1) {
				$set(this, userCookies, $nc(this->requests)->getValue(k));
			}
			k = $nc(this->requests)->getKey("Cookie2"_s);
			if (k != -1) {
				$set(this, userCookies2, $nc(this->requests)->getValue(k));
			}
			this->setUserCookies = false;
		}
		$nc(this->requests)->remove("Cookie"_s);
		$nc(this->requests)->remove("Cookie2"_s);
		$var($URI, uri, $ParseUtil::toURI(this->url));
		if (uri != nullptr) {
			$init($PlatformLogger$Level);
			if ($nc(HttpURLConnection::logger)->isLoggable($PlatformLogger$Level::FINEST)) {
				$nc(HttpURLConnection::logger)->finest($$str({"CookieHandler request for "_s, uri}));
			}
			$var($Map, cookies, $nc(this->cookieHandler)->get(uri, $($nc(this->requests)->getHeaders(HttpURLConnection::EXCLUDE_HEADERS))));
			if (!$nc(cookies)->isEmpty()) {
				if ($nc(HttpURLConnection::logger)->isLoggable($PlatformLogger$Level::FINEST)) {
					$nc(HttpURLConnection::logger)->finest($$str({"Cookies retrieved: "_s, $($of(cookies)->toString())}));
				}
				{
					$var($Iterator, i$, $nc($(cookies->entrySet()))->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
						{
							$var($String, key, $cast($String, $nc(entry)->getKey()));
							bool var$0 = !"Cookie"_s->equalsIgnoreCase(key);
							if (var$0 && !"Cookie2"_s->equalsIgnoreCase(key)) {
								continue;
							}
							$var($List, l, $cast($List, entry->getValue()));
							if (l != nullptr && !l->isEmpty()) {
								$var($StringJoiner, cookieValue, $new($StringJoiner, "; "_s));
								{
									$var($Iterator, i$, l->iterator());
									for (; $nc(i$)->hasNext();) {
										$var($String, value, $cast($String, i$->next()));
										{
											cookieValue->add(value);
										}
									}
								}
								$nc(this->requests)->add(key, $(cookieValue->toString()));
							}
						}
					}
				}
			}
		}
		if (this->userCookies != nullptr) {
			int32_t k = 0;
			if ((k = $nc(this->requests)->getKey("Cookie"_s)) != -1) {
				$nc(this->requests)->set("Cookie"_s, $$str({$($nc(this->requests)->getValue(k)), ";"_s, this->userCookies}));
			} else {
				$nc(this->requests)->set("Cookie"_s, this->userCookies);
			}
		}
		if (this->userCookies2 != nullptr) {
			int32_t k = 0;
			if ((k = $nc(this->requests)->getKey("Cookie2"_s)) != -1) {
				$nc(this->requests)->set("Cookie2"_s, $$str({$($nc(this->requests)->getValue(k)), ";"_s, this->userCookies2}));
			} else {
				$nc(this->requests)->set("Cookie2"_s, this->userCookies2);
			}
		}
	}
}

$InputStream* HttpURLConnection::getInputStream() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	lock();
	{
		$var($Throwable, var$0, nullptr);
		$var($InputStream, var$2, nullptr);
		bool return$1 = false;
		try {
			this->connecting = true;
			$var($SocketPermission, p, URLtoSocketPermission(this->url));
			if (p != nullptr) {
				try {
					$assign(var$2, $cast($InputStream, $AccessController::doPrivilegedWithCombiner(static_cast<$PrivilegedExceptionAction*>($$new($HttpURLConnection$9, this)), ($AccessControlContext*)nullptr, $$new($PermissionArray, {static_cast<$Permission*>(p)}))));
					return$1 = true;
					goto $finally;
				} catch ($PrivilegedActionException& e) {
					$throw($cast($IOException, $(e->getException())));
				}
			} else {
				$assign(var$2, getInputStream0());
				return$1 = true;
				goto $finally;
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

$InputStream* HttpURLConnection::getInputStream0() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (!HttpURLConnection::$assertionsDisabled && !isLockHeldByCurrentThread()) {
		$throwNew($AssertionError);
	}
	if (!this->doInput) {
		$throwNew($ProtocolException, "Cannot read from URLConnection if doInput=false (call setDoInput(true))"_s);
	}
	if (this->rememberedException != nullptr) {
		if ($instanceOf($RuntimeException, this->rememberedException)) {
			$throwNew($RuntimeException, static_cast<$Throwable*>(this->rememberedException));
		} else {
			$throw($(getChainedException($cast($IOException, this->rememberedException))));
		}
	}
	if (this->inputStream != nullptr) {
		return this->inputStream;
	}
	if (streaming()) {
		if (this->strOutputStream == nullptr) {
			getOutputStream();
		}
		$nc(this->strOutputStream)->close();
		if (!$nc(this->strOutputStream)->writtenOK()) {
			$throwNew($IOException, "Incomplete output stream"_s);
		}
	}
	int32_t redirects = 0;
	int32_t respCode = 0;
	int64_t cl = -1;
	$var($AuthenticationInfo, serverAuthentication, nullptr);
	$var($AuthenticationInfo, proxyAuthentication, nullptr);
	$var($AuthenticationHeader, srvHdr, nullptr);
	bool inNegotiate = false;
	bool inNegotiateProxy = false;
	this->isUserServerAuth = $nc(this->requests)->getKey("Authorization"_s) != -1;
	this->isUserProxyAuth = $nc(this->requests)->getKey("Proxy-Authorization"_s) != -1;
	{
		$var($Throwable, var$0, nullptr);
		$var($InputStream, var$2, nullptr);
		bool return$1 = false;
		try {
			try {
				do {
					if (!checkReuseConnection()) {
						connect();
					}
					if (this->cachedInputStream != nullptr) {
						$assign(var$2, this->cachedInputStream);
						return$1 = true;
						goto $finally;
					}
					bool meteredInput = $nc($($ProgressMonitor::getDefault()))->shouldMeterInput(this->url, this->method);
					if (meteredInput) {
						$set(this, pi, $new($ProgressSource, this->url, this->method));
						$nc(this->pi)->beginTracking();
					}
					$set(this, ps, $cast($PrintStream, $nc(this->http)->getOutputStream()));
					if (!streaming()) {
						writeRequests();
					}
					$nc(this->http)->parseHTTP(this->responses, this->pi, this);
					$init($PlatformLogger$Level);
					if ($nc(HttpURLConnection::logger)->isLoggable($PlatformLogger$Level::FINE)) {
						$nc(HttpURLConnection::logger)->fine($($nc(this->responses)->toString()));
					}
					bool b1 = $nc(this->responses)->filterNTLMResponses("WWW-Authenticate"_s);
					bool b2 = $nc(this->responses)->filterNTLMResponses("Proxy-Authenticate"_s);
					if (b1 || b2) {
						if ($nc(HttpURLConnection::logger)->isLoggable($PlatformLogger$Level::FINE)) {
							$nc(HttpURLConnection::logger)->fine(">>>> Headers are filtered"_s);
							$nc(HttpURLConnection::logger)->fine($($nc(this->responses)->toString()));
						}
					}
					$set(this, inputStream, $nc(this->http)->getInputStream());
					respCode = getResponseCode();
					if (respCode == -1) {
						disconnectInternal();
						$throwNew($IOException, "Invalid Http response"_s);
					}
					if (respCode == $HttpURLConnection::HTTP_PROXY_AUTH) {
						if (streaming()) {
							disconnectInternal();
							$throwNew($HttpRetryException, HttpURLConnection::RETRY_MSG1, $HttpURLConnection::HTTP_PROXY_AUTH);
						}
						bool dontUseNegotiate = false;
						$var($Iterator, iter, $nc(this->responses)->multiValueIterator("Proxy-Authenticate"_s));
						while ($nc(iter)->hasNext()) {
							$var($String, value, $nc(($cast($String, $(iter->next()))))->trim());
							bool var$3 = value->equalsIgnoreCase("Negotiate"_s);
							if (var$3 || value->equalsIgnoreCase("Kerberos"_s)) {
								if (!inNegotiateProxy) {
									inNegotiateProxy = true;
								} else {
									dontUseNegotiate = true;
									this->doingNTLMp2ndStage = false;
									$assign(proxyAuthentication, nullptr);
								}
								break;
							}
						}
						$var($URL, var$4, this->url);
						$var($String, var$5, $nc(this->http)->getProxyHostUsed());
						$var($AuthenticationHeader, authhdr, $new($AuthenticationHeader, "Proxy-Authenticate"_s, this->responses, $$new($HttpCallerInfo, var$4, var$5, $nc(this->http)->getProxyPortUsed(), this->authenticator), dontUseNegotiate, HttpURLConnection::disabledProxyingSchemes));
						if (!this->doingNTLMp2ndStage) {
							$assign(proxyAuthentication, resetProxyAuthentication(proxyAuthentication, authhdr));
							if (proxyAuthentication != nullptr) {
								++redirects;
								disconnectInternal();
								continue;
							}
						} else {
							$var($String, raw, $nc(this->responses)->findValue("Proxy-Authenticate"_s));
							reset();
							if (!$nc(proxyAuthentication)->setHeaders(this, $(authhdr->headerParser()), raw)) {
								disconnectInternal();
								$throwNew($IOException, "Authentication failure"_s);
							}
							if (serverAuthentication != nullptr && srvHdr != nullptr && !serverAuthentication->setHeaders(this, $(srvHdr->headerParser()), raw)) {
								disconnectInternal();
								$throwNew($IOException, "Authentication failure"_s);
							}
							$set(this, authObj$, nullptr);
							this->doingNTLMp2ndStage = false;
							continue;
						}
					} else {
						inNegotiateProxy = false;
						this->doingNTLMp2ndStage = false;
						if (!this->isUserProxyAuth) {
							$nc(this->requests)->remove("Proxy-Authorization"_s);
						}
					}
					if (proxyAuthentication != nullptr) {
						proxyAuthentication->addToCache();
					}
					if (respCode == $HttpURLConnection::HTTP_UNAUTHORIZED) {
						if (streaming()) {
							disconnectInternal();
							$throwNew($HttpRetryException, HttpURLConnection::RETRY_MSG2, $HttpURLConnection::HTTP_UNAUTHORIZED);
						}
						bool dontUseNegotiate = false;
						$var($Iterator, iter, $nc(this->responses)->multiValueIterator("WWW-Authenticate"_s));
						while ($nc(iter)->hasNext()) {
							$var($String, value, $nc(($cast($String, $(iter->next()))))->trim());
							bool var$6 = value->equalsIgnoreCase("Negotiate"_s);
							if (var$6 || value->equalsIgnoreCase("Kerberos"_s)) {
								if (!inNegotiate) {
									inNegotiate = true;
								} else {
									dontUseNegotiate = true;
									this->doingNTLM2ndStage = false;
									$assign(serverAuthentication, nullptr);
								}
								break;
							}
						}
						$assign(srvHdr, $new($AuthenticationHeader, "WWW-Authenticate"_s, this->responses, $$new($HttpCallerInfo, this->url, this->authenticator), dontUseNegotiate));
						$var($String, raw, srvHdr->raw());
						if (!this->doingNTLM2ndStage) {
							$init($AuthScheme);
							if ((serverAuthentication != nullptr) && serverAuthentication->getAuthScheme() != $AuthScheme::NTLM) {
								if (serverAuthentication->isAuthorizationStale(raw)) {
									disconnectWeb();
									++redirects;
									$var($String, var$7, serverAuthentication->getHeaderName());
									$nc(this->requests)->set(var$7, $(serverAuthentication->getHeaderValue(this->url, this->method)));
									$set(this, currentServerCredentials, serverAuthentication);
									setCookieHeader();
									continue;
								} else {
									serverAuthentication->removeFromCache();
								}
							}
							$assign(serverAuthentication, getServerAuthentication(srvHdr));
							$set(this, currentServerCredentials, serverAuthentication);
							if (serverAuthentication != nullptr) {
								disconnectWeb();
								++redirects;
								setCookieHeader();
								continue;
							}
						} else {
							reset();
							if (!$nc(serverAuthentication)->setHeaders(this, nullptr, raw)) {
								disconnectWeb();
								$throwNew($IOException, "Authentication failure"_s);
							}
							this->doingNTLM2ndStage = false;
							$set(this, authObj$, nullptr);
							setCookieHeader();
							continue;
						}
					}
					if (serverAuthentication != nullptr) {
						if (!($instanceOf($DigestAuthentication, serverAuthentication)) || (this->domain == nullptr)) {
							if ($instanceOf($BasicAuthentication, serverAuthentication)) {
								$var($String, npath, $AuthenticationInfo::reducePath($($nc(this->url)->getPath())));
								$var($String, opath, serverAuthentication->path);
								bool var$8 = !$nc(opath)->startsWith(npath);
								if (!var$8) {
									int32_t var$9 = $nc(npath)->length();
									var$8 = var$9 >= $nc(opath)->length();
								}
								if (var$8) {
									$assign(npath, $BasicAuthentication::getRootPath(opath, npath));
								}
								$var($BasicAuthentication, a, $cast($BasicAuthentication, serverAuthentication->clone()));
								serverAuthentication->removeFromCache();
								$set($nc(a), path, npath);
								$assign(serverAuthentication, a);
							}
							serverAuthentication->addToCache();
						} else {
							$var($DigestAuthentication, srv, $cast($DigestAuthentication, serverAuthentication));
							$var($StringTokenizer, tok, $new($StringTokenizer, this->domain, " "_s));
							$var($String, realm, srv->realm);
							$var($PasswordAuthentication, pw, srv->pw);
							$set(this, digestparams, srv->params);
							while (tok->hasMoreTokens()) {
								$var($String, path, tok->nextToken());
								try {
									$var($URL, u, $new($URL, this->url, path));
									$var($DigestAuthentication, d, $new($DigestAuthentication, false, u, realm, "Digest"_s, pw, this->digestparams, srv->authenticatorKey));
									d->addToCache();
								} catch ($Exception& e) {
								}
							}
						}
					}
					inNegotiate = false;
					inNegotiateProxy = false;
					this->doingNTLMp2ndStage = false;
					this->doingNTLM2ndStage = false;
					if (!this->isUserServerAuth) {
						$nc(this->requests)->remove("Authorization"_s);
					}
					if (!this->isUserProxyAuth) {
						$nc(this->requests)->remove("Proxy-Authorization"_s);
					}
					if (respCode == $HttpURLConnection::HTTP_OK) {
						checkResponseCredentials(false);
					} else {
						this->needToCheck = false;
					}
					this->needToCheck = true;
					if (followRedirect()) {
						++redirects;
						setCookieHeader();
						continue;
					}
					try {
						cl = $Long::parseLong($($nc(this->responses)->findValue("content-length"_s)));
					} catch ($Exception& exc) {
					}
					if ($nc(this->method)->equals("HEAD"_s) || cl == 0 || respCode == $HttpURLConnection::HTTP_NOT_MODIFIED || respCode == $HttpURLConnection::HTTP_NO_CONTENT) {
						if (this->pi != nullptr) {
							$nc(this->pi)->finishTracking();
							$set(this, pi, nullptr);
						}
						$nc(this->http)->finished();
						$set(this, http, nullptr);
						$set(this, inputStream, $new($EmptyInputStream));
						this->connected = false;
					}
					if (respCode == 200 || respCode == 203 || respCode == 206 || respCode == 300 || respCode == 301 || respCode == 410) {
						if (this->cacheHandler != nullptr && getUseCaches()) {
							$var($URI, uri, $ParseUtil::toURI(this->url));
							if (uri != nullptr) {
								$var($URLConnection, uconn, this);
								if ("https"_s->equalsIgnoreCase($(uri->getScheme()))) {
									try {
										$assign(uconn, $cast($URLConnection, $nc($($of(this)->getClass()->getField("httpsURLConnection"_s)))->get(this)));
									} catch ($IllegalAccessException& e) {
									} catch ($NoSuchFieldException& e) {
									}
								}
								$var($CacheRequest, cacheRequest, $nc(this->cacheHandler)->put(uri, uconn));
								if (cacheRequest != nullptr && this->http != nullptr) {
									$nc(this->http)->setCacheRequest(cacheRequest);
									$set(this, inputStream, $new($HttpURLConnection$HttpInputStream, this, this->inputStream, cacheRequest));
								}
							}
						}
					}
					if (!($instanceOf($HttpURLConnection$HttpInputStream, this->inputStream))) {
						$set(this, inputStream, $new($HttpURLConnection$HttpInputStream, this, this->inputStream));
					}
					if (respCode >= 400) {
						if (respCode == 404 || respCode == 410) {
							$throwNew($FileNotFoundException, $($nc(this->url)->toString()));
						} else {
							$throwNew($IOException, $$str({"Server returned HTTP response code: "_s, $$str(respCode), " for URL: "_s, $($nc(this->url)->toString())}));
						}
					}
					$set(this, poster, nullptr);
					$set(this, strOutputStream, nullptr);
					$assign(var$2, this->inputStream);
					return$1 = true;
					goto $finally;
				} while (redirects < HttpURLConnection::maxRedirects);
				$throwNew($ProtocolException, $$str({"Server redirected too many  times ("_s, $$str(redirects), ")"_s}));
			} catch ($RuntimeException& e) {
				disconnectInternal();
				$set(this, rememberedException, e);
				$throw(e);
			} catch ($IOException& e) {
				$set(this, rememberedException, e);
				$var($String, te, $nc(this->responses)->findValue("Transfer-Encoding"_s));
				bool var$10 = this->http != nullptr && $nc(this->http)->isKeepingAlive() && HttpURLConnection::enableESBuffer;
				if (var$10 && (cl > 0 || (te != nullptr && te->equalsIgnoreCase("chunked"_s)))) {
					$set(this, errorStream, $HttpURLConnection$ErrorStream::getErrorStream(this->inputStream, cl, this->http));
				}
				$throw(e);
			}
		} catch ($Throwable& var$11) {
			$assign(var$0, var$11);
		} $finally: {
			if (this->proxyAuthKey != nullptr) {
				$AuthenticationInfo::endAuthRequest(this->proxyAuthKey);
			}
			if (this->serverAuthKey != nullptr) {
				$AuthenticationInfo::endAuthRequest(this->serverAuthKey);
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

$IOException* HttpURLConnection::getChainedException($IOException* rememberedException) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	try {
		$var($ObjectArray, args, $new($ObjectArray, {$($of($nc(rememberedException)->getMessage()))}));
		$var($IOException, chainedException, $cast($IOException, $AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new($HttpURLConnection$10, this, rememberedException, args)))));
		$nc(chainedException)->initCause(rememberedException);
		return chainedException;
	} catch ($Exception& ignored) {
		return rememberedException;
	}
	$shouldNotReachHere();
}

$InputStream* HttpURLConnection::getErrorStream() {
	if (this->connected && this->responseCode >= 400) {
		if (this->errorStream != nullptr) {
			return this->errorStream;
		} else if (this->inputStream != nullptr) {
			return this->inputStream;
		}
	}
	return nullptr;
}

$AuthenticationInfo* HttpURLConnection::resetProxyAuthentication($AuthenticationInfo* proxyAuthentication$renamed, $AuthenticationHeader* auth) {
	$useLocalCurrentObjectStackCache();
	$var($AuthenticationInfo, proxyAuthentication, proxyAuthentication$renamed);
	if (!HttpURLConnection::$assertionsDisabled && !isLockHeldByCurrentThread()) {
		$throwNew($AssertionError);
	}
	$init($AuthScheme);
	if ((proxyAuthentication != nullptr) && proxyAuthentication->getAuthScheme() != $AuthScheme::NTLM) {
		$var($String, raw, $nc(auth)->raw());
		if (proxyAuthentication->isAuthorizationStale(raw)) {
			$var($String, value, nullptr);
			if ($instanceOf($DigestAuthentication, proxyAuthentication)) {
				$var($DigestAuthentication, digestProxy, $cast($DigestAuthentication, proxyAuthentication));
				$init($HttpURLConnection$TunnelState);
				if (tunnelState() == $HttpURLConnection$TunnelState::SETUP) {
					$assign(value, digestProxy->getHeaderValue($(connectRequestURI(this->url)), HttpURLConnection::HTTP_CONNECT));
				} else {
					$assign(value, digestProxy->getHeaderValue($(getRequestURI()), this->method));
				}
			} else {
				$assign(value, proxyAuthentication->getHeaderValue(this->url, this->method));
			}
			$nc(this->requests)->set($(proxyAuthentication->getHeaderName()), value);
			$set(this, currentProxyCredentials, proxyAuthentication);
			return proxyAuthentication;
		} else {
			proxyAuthentication->removeFromCache();
		}
	}
	$assign(proxyAuthentication, getHttpProxyAuthentication(auth));
	$set(this, currentProxyCredentials, proxyAuthentication);
	return proxyAuthentication;
}

$HttpURLConnection$TunnelState* HttpURLConnection::tunnelState() {
	return this->tunnelState$;
}

void HttpURLConnection::setTunnelState($HttpURLConnection$TunnelState* tunnelState) {
	$set(this, tunnelState$, tunnelState);
}

void HttpURLConnection::doTunneling() {
	lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			doTunneling0();
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void HttpURLConnection::doTunneling0() {
	$useLocalCurrentObjectStackCache();
	int32_t retryTunnel = 0;
	$var($String, statusLine, ""_s);
	int32_t respCode = 0;
	$var($AuthenticationInfo, proxyAuthentication, nullptr);
	$var($String, proxyHost, nullptr);
	int32_t proxyPort = -1;
	if (!HttpURLConnection::$assertionsDisabled && !isLockHeldByCurrentThread()) {
		$throwNew($AssertionError);
	}
	$var($MessageHeader, savedRequests, this->requests);
	$set(this, requests, $new($MessageHeader));
	bool inNegotiateProxy = false;
	{
		$var($Throwable, var$0, nullptr);
		try {
			$init($HttpURLConnection$TunnelState);
			setTunnelState($HttpURLConnection$TunnelState::SETUP);
			do {
				if (!checkReuseConnection()) {
					proxiedConnect(this->url, proxyHost, proxyPort, false);
				}
				sendCONNECTRequest();
				$nc(this->responses)->reset();
				$nc(this->http)->parseHTTP(this->responses, nullptr, this);
				$init($PlatformLogger$Level);
				if ($nc(HttpURLConnection::logger)->isLoggable($PlatformLogger$Level::FINE)) {
					$nc(HttpURLConnection::logger)->fine($($nc(this->responses)->toString()));
				}
				if ($nc(this->responses)->filterNTLMResponses("Proxy-Authenticate"_s)) {
					if ($nc(HttpURLConnection::logger)->isLoggable($PlatformLogger$Level::FINE)) {
						$nc(HttpURLConnection::logger)->fine(">>>> Headers are filtered"_s);
						$nc(HttpURLConnection::logger)->fine($($nc(this->responses)->toString()));
					}
				}
				$assign(statusLine, $nc(this->responses)->getValue(0));
				$var($StringTokenizer, st, $new($StringTokenizer, statusLine));
				st->nextToken();
				respCode = $Integer::parseInt($($nc($(st->nextToken()))->trim()));
				if (respCode == $HttpURLConnection::HTTP_PROXY_AUTH) {
					bool dontUseNegotiate = false;
					$var($Iterator, iter, $nc(this->responses)->multiValueIterator("Proxy-Authenticate"_s));
					while ($nc(iter)->hasNext()) {
						$var($String, value, $nc(($cast($String, $(iter->next()))))->trim());
						bool var$1 = value->equalsIgnoreCase("Negotiate"_s);
						if (var$1 || value->equalsIgnoreCase("Kerberos"_s)) {
							if (!inNegotiateProxy) {
								inNegotiateProxy = true;
							} else {
								dontUseNegotiate = true;
								this->doingNTLMp2ndStage = false;
								$assign(proxyAuthentication, nullptr);
							}
							break;
						}
					}
					$var($URL, var$2, this->url);
					$var($String, var$3, $nc(this->http)->getProxyHostUsed());
					$var($AuthenticationHeader, authhdr, $new($AuthenticationHeader, "Proxy-Authenticate"_s, this->responses, $$new($HttpCallerInfo, var$2, var$3, $nc(this->http)->getProxyPortUsed(), this->authenticator), dontUseNegotiate, HttpURLConnection::disabledTunnelingSchemes));
					if (!this->doingNTLMp2ndStage) {
						$assign(proxyAuthentication, resetProxyAuthentication(proxyAuthentication, authhdr));
						if (proxyAuthentication != nullptr) {
							$assign(proxyHost, $nc(this->http)->getProxyHostUsed());
							proxyPort = $nc(this->http)->getProxyPortUsed();
							disconnectInternal();
							++retryTunnel;
							continue;
						}
					} else {
						$var($String, raw, $nc(this->responses)->findValue("Proxy-Authenticate"_s));
						reset();
						if (!$nc(proxyAuthentication)->setHeaders(this, $(authhdr->headerParser()), raw)) {
							disconnectInternal();
							$throwNew($IOException, "Authentication failure"_s);
						}
						$set(this, authObj$, nullptr);
						this->doingNTLMp2ndStage = false;
						continue;
					}
				}
				if (proxyAuthentication != nullptr) {
					proxyAuthentication->addToCache();
				}
				if (respCode == $HttpURLConnection::HTTP_OK) {
					setTunnelState($HttpURLConnection$TunnelState::TUNNELING);
					break;
				}
				disconnectInternal();
				setTunnelState($HttpURLConnection$TunnelState::NONE);
				break;
			} while (retryTunnel < HttpURLConnection::maxRedirects);
			if (retryTunnel >= HttpURLConnection::maxRedirects || (respCode != $HttpURLConnection::HTTP_OK)) {
				if (respCode != $HttpURLConnection::HTTP_PROXY_AUTH) {
					$nc(this->responses)->reset();
				}
				$throwNew($IOException, $$str({"Unable to tunnel through proxy. Proxy returns \""_s, statusLine, "\""_s}));
			}
		} catch ($Throwable& var$4) {
			$assign(var$0, var$4);
		} /*finally*/ {
			if (this->proxyAuthKey != nullptr) {
				$AuthenticationInfo::endAuthRequest(this->proxyAuthKey);
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	$set(this, requests, savedRequests);
	$nc(this->responses)->reset();
}

$String* HttpURLConnection::connectRequestURI($URL* url) {
	$init(HttpURLConnection);
	$useLocalCurrentObjectStackCache();
	$var($String, host, $nc(url)->getHost());
	int32_t port = url->getPort();
	port = port != -1 ? port : url->getDefaultPort();
	return $str({host, ":"_s, $$str(port)});
}

void HttpURLConnection::sendCONNECTRequest() {
	$useLocalCurrentObjectStackCache();
	int32_t port = $nc(this->url)->getPort();
	$nc(this->requests)->set(0, $$str({HttpURLConnection::HTTP_CONNECT, " "_s, $(connectRequestURI(this->url)), " "_s, HttpURLConnection::httpVersion}), nullptr);
	$nc(this->requests)->setIfNotSet("User-Agent"_s, HttpURLConnection::userAgent);
	$var($String, host, $nc(this->url)->getHost());
	if (port != -1 && port != $nc(this->url)->getDefaultPort()) {
		$plusAssign(host, $$str({":"_s, $($String::valueOf(port))}));
	}
	$nc(this->requests)->setIfNotSet("Host"_s, host);
	$nc(this->requests)->setIfNotSet("Accept"_s, HttpURLConnection::acceptString);
	if ($nc(this->http)->getHttpKeepAliveSet()) {
		$nc(this->requests)->setIfNotSet("Proxy-Connection"_s, "keep-alive"_s);
	}
	setPreemptiveProxyAuthentication(this->requests);
	$init($PlatformLogger$Level);
	if ($nc(HttpURLConnection::logger)->isLoggable($PlatformLogger$Level::FINE)) {
		$nc(HttpURLConnection::logger)->fine($($nc(this->requests)->toString()));
	}
	$nc(this->http)->writeRequests(this->requests, nullptr);
}

void HttpURLConnection::setPreemptiveProxyAuthentication($MessageHeader* requests) {
	$useLocalCurrentObjectStackCache();
	$var($String, var$0, $nc(this->http)->getProxyHostUsed());
	int32_t var$1 = $nc(this->http)->getProxyPortUsed();
	$var($AuthenticationInfo, pauth, $AuthenticationInfo::getProxyAuth(var$0, var$1, $(getAuthenticatorKey())));
	if (pauth != nullptr && pauth->supportsPreemptiveAuthorization()) {
		$var($String, value, nullptr);
		if ($instanceOf($DigestAuthentication, pauth)) {
			$var($DigestAuthentication, digestProxy, $cast($DigestAuthentication, pauth));
			$init($HttpURLConnection$TunnelState);
			if (tunnelState() == $HttpURLConnection$TunnelState::SETUP) {
				$assign(value, digestProxy->getHeaderValue($(connectRequestURI(this->url)), HttpURLConnection::HTTP_CONNECT));
			} else {
				$assign(value, digestProxy->getHeaderValue($(getRequestURI()), this->method));
			}
		} else {
			$assign(value, pauth->getHeaderValue(this->url, this->method));
		}
		$nc(requests)->set($(pauth->getHeaderName()), value);
		$set(this, currentProxyCredentials, pauth);
	}
}

$AuthenticationInfo* HttpURLConnection::getHttpProxyAuthentication($AuthenticationHeader* authhdr) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (!HttpURLConnection::$assertionsDisabled && !isLockHeldByCurrentThread()) {
		$throwNew($AssertionError);
	}
	$var($AuthenticationInfo, ret, nullptr);
	$var($String, raw, $nc(authhdr)->raw());
	$var($String, host, $nc(this->http)->getProxyHostUsed());
	int32_t port = $nc(this->http)->getProxyPortUsed();
	if (host != nullptr && authhdr->isPresent()) {
		$var($HeaderParser, p, authhdr->headerParser());
		$var($String, realm, $nc(p)->findValue("realm"_s));
		$var($String, charset, p->findValue("charset"_s));
		bool isUTF8 = (charset != nullptr && charset->equalsIgnoreCase("UTF-8"_s));
		$var($String, scheme, authhdr->scheme());
		$init($AuthScheme);
		$AuthScheme* authScheme = $AuthScheme::UNKNOWN;
		if ("basic"_s->equalsIgnoreCase(scheme)) {
			authScheme = $AuthScheme::BASIC;
		} else if ("digest"_s->equalsIgnoreCase(scheme)) {
			authScheme = $AuthScheme::DIGEST;
		} else if ("ntlm"_s->equalsIgnoreCase(scheme)) {
			authScheme = $AuthScheme::NTLM;
			this->doingNTLMp2ndStage = true;
		} else if ("Kerberos"_s->equalsIgnoreCase(scheme)) {
			authScheme = $AuthScheme::KERBEROS;
			this->doingNTLMp2ndStage = true;
		} else if ("Negotiate"_s->equalsIgnoreCase(scheme)) {
			authScheme = $AuthScheme::NEGOTIATE;
			this->doingNTLMp2ndStage = true;
		}
		if (realm == nullptr) {
			$assign(realm, ""_s);
		}
		$set(this, proxyAuthKey, $AuthenticationInfo::getProxyAuthKey(host, port, realm, authScheme, $(getAuthenticatorKey())));
		$assign(ret, $AuthenticationInfo::getProxyAuth(this->proxyAuthKey));
		if (ret == nullptr) {
			$init($HttpURLConnection$13);
			{
				$var($InetAddress, addr, nullptr)
				$var($PasswordAuthentication, a, nullptr)
				switch ($nc($HttpURLConnection$13::$SwitchMap$sun$net$www$protocol$http$AuthScheme)->get($nc((authScheme))->ordinal())) {
				case 1:
					{
						$assign(addr, nullptr);
						try {
							$var($String, finalHost, host);
							$assign(addr, $cast($InetAddress, $AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new($HttpURLConnection$11, this, finalHost)))));
						} catch ($PrivilegedActionException& ignored) {
						}
						$init($Authenticator$RequestorType);
						$assign(a, privilegedRequestPasswordAuthentication(this->authenticator, host, addr, port, "http"_s, realm, scheme, this->url, $Authenticator$RequestorType::PROXY));
						if (a != nullptr) {
							$assign(ret, $new($BasicAuthentication, true, host, port, realm, a, isUTF8, $(getAuthenticatorKey())));
						}
						break;
					}
				case 2:
					{
						$init($Authenticator$RequestorType);
						$assign(a, privilegedRequestPasswordAuthentication(this->authenticator, host, nullptr, port, $($nc(this->url)->getProtocol()), realm, scheme, this->url, $Authenticator$RequestorType::PROXY));
						if (a != nullptr) {
							$var($DigestAuthentication$Parameters, params, $new($DigestAuthentication$Parameters));
							$assign(ret, $new($DigestAuthentication, true, host, port, realm, scheme, a, params, $(getAuthenticatorKey())));
						}
						break;
					}
				case 3:
					{
						$init($NTLMAuthenticationProxy);
						if ($NTLMAuthenticationProxy::supported) {
							if (this->tryTransparentNTLMProxy) {
								this->tryTransparentNTLMProxy = $NTLMAuthenticationProxy::supportsTransparentAuth$;
								if (this->tryTransparentNTLMProxy && this->useProxyResponseCode) {
									this->tryTransparentNTLMProxy = false;
								}
							}
							$assign(a, nullptr);
							if (this->tryTransparentNTLMProxy) {
								$nc(HttpURLConnection::logger)->finest("Trying Transparent NTLM authentication"_s);
							} else {
								$init($Authenticator$RequestorType);
								$assign(a, privilegedRequestPasswordAuthentication(this->authenticator, host, nullptr, port, $($nc(this->url)->getProtocol()), ""_s, scheme, this->url, $Authenticator$RequestorType::PROXY));
							}
							if (this->tryTransparentNTLMProxy || (!this->tryTransparentNTLMProxy && a != nullptr)) {
								$assign(ret, $nc($NTLMAuthenticationProxy::proxy)->create(true, host, port, a, $(getAuthenticatorKey())));
							}
							this->tryTransparentNTLMProxy = false;
						}
						break;
					}
				case 4:
					{
						$assign(ret, $new($NegotiateAuthentication, $$new($HttpCallerInfo, $(authhdr->getHttpCallerInfo()), "Negotiate"_s)));
						break;
					}
				case 5:
					{
						$assign(ret, $new($NegotiateAuthentication, $$new($HttpCallerInfo, $(authhdr->getHttpCallerInfo()), "Kerberos"_s)));
						break;
					}
				case 6:
					{
						$init($PlatformLogger$Level);
						if ($nc(HttpURLConnection::logger)->isLoggable($PlatformLogger$Level::FINEST)) {
							$nc(HttpURLConnection::logger)->finest($$str({"Unknown/Unsupported authentication scheme: "_s, scheme}));
						}
					}
				default:
					{
						$throwNew($AssertionError, $of("should not reach here"_s));
					}
				}
			}
		}
		if (ret == nullptr && HttpURLConnection::defaultAuth != nullptr && $nc(HttpURLConnection::defaultAuth)->schemeSupported(scheme)) {
			try {
				$var($URL, u, $new($URL, "http"_s, host, port, "/"_s));
				$var($String, a, $nc(HttpURLConnection::defaultAuth)->authString(u, scheme, realm));
				if (a != nullptr) {
					$assign(ret, $new($BasicAuthentication, true, host, port, realm, a, $(getAuthenticatorKey())));
				}
			} catch ($MalformedURLException& ignored) {
			}
		}
		if (ret != nullptr) {
			if (!ret->setHeaders(this, p, raw)) {
				$assign(ret, nullptr);
			}
		}
	}
	$init($PlatformLogger$Level);
	if ($nc(HttpURLConnection::logger)->isLoggable($PlatformLogger$Level::FINER)) {
		$var($String, var$0, $$str({"Proxy Authentication for "_s, $(authhdr->toString()), " returned "_s}));
		$nc(HttpURLConnection::logger)->finer($$concat(var$0, (ret != nullptr ? $($nc($of(ret))->toString()) : "null"_s)));
	}
	return ret;
}

$AuthenticationInfo* HttpURLConnection::getServerAuthentication($AuthenticationHeader* authhdr) {
	$useLocalCurrentObjectStackCache();
	if (!HttpURLConnection::$assertionsDisabled && !isLockHeldByCurrentThread()) {
		$throwNew($AssertionError);
	}
	$var($AuthenticationInfo, ret, nullptr);
	$var($String, raw, $nc(authhdr)->raw());
	if (authhdr->isPresent()) {
		$var($HeaderParser, p, authhdr->headerParser());
		$var($String, realm, $nc(p)->findValue("realm"_s));
		$var($String, scheme, authhdr->scheme());
		$var($String, charset, p->findValue("charset"_s));
		bool isUTF8 = (charset != nullptr && charset->equalsIgnoreCase("UTF-8"_s));
		$init($AuthScheme);
		$AuthScheme* authScheme = $AuthScheme::UNKNOWN;
		if ("basic"_s->equalsIgnoreCase(scheme)) {
			authScheme = $AuthScheme::BASIC;
		} else if ("digest"_s->equalsIgnoreCase(scheme)) {
			authScheme = $AuthScheme::DIGEST;
		} else if ("ntlm"_s->equalsIgnoreCase(scheme)) {
			authScheme = $AuthScheme::NTLM;
			this->doingNTLM2ndStage = true;
		} else if ("Kerberos"_s->equalsIgnoreCase(scheme)) {
			authScheme = $AuthScheme::KERBEROS;
			this->doingNTLM2ndStage = true;
		} else if ("Negotiate"_s->equalsIgnoreCase(scheme)) {
			authScheme = $AuthScheme::NEGOTIATE;
			this->doingNTLM2ndStage = true;
		}
		$set(this, domain, p->findValue("domain"_s));
		if (realm == nullptr) {
			$assign(realm, ""_s);
		}
		$set(this, serverAuthKey, $AuthenticationInfo::getServerAuthKey(this->url, realm, authScheme, $(getAuthenticatorKey())));
		$assign(ret, $AuthenticationInfo::getServerAuth(this->serverAuthKey));
		$var($InetAddress, addr, nullptr);
		if (ret == nullptr) {
			try {
				$assign(addr, $InetAddress::getByName($($nc(this->url)->getHost())));
			} catch ($UnknownHostException& ignored) {
			}
		}
		int32_t port = $nc(this->url)->getPort();
		if (port == -1) {
			port = $nc(this->url)->getDefaultPort();
		}
		if (ret == nullptr) {
			$init($HttpURLConnection$13);
			{
				$var($PasswordAuthentication, a, nullptr)
				switch ($nc($HttpURLConnection$13::$SwitchMap$sun$net$www$protocol$http$AuthScheme)->get($nc((authScheme))->ordinal())) {
				case 5:
					{
						$assign(ret, $new($NegotiateAuthentication, $$new($HttpCallerInfo, $(authhdr->getHttpCallerInfo()), "Kerberos"_s)));
						break;
					}
				case 4:
					{
						$assign(ret, $new($NegotiateAuthentication, $$new($HttpCallerInfo, $(authhdr->getHttpCallerInfo()), "Negotiate"_s)));
						break;
					}
				case 1:
					{
						$var($Authenticator, var$0, this->authenticator);
						$var($String, var$1, $nc(this->url)->getHost());
						$var($InetAddress, var$2, addr);
						int32_t var$3 = port;
						$init($Authenticator$RequestorType);
						$assign(a, privilegedRequestPasswordAuthentication(var$0, var$1, var$2, var$3, $($nc(this->url)->getProtocol()), realm, scheme, this->url, $Authenticator$RequestorType::SERVER));
						if (a != nullptr) {
							$assign(ret, $new($BasicAuthentication, false, this->url, realm, a, isUTF8, $(getAuthenticatorKey())));
						}
						break;
					}
				case 2:
					{
						$var($Authenticator, var$4, this->authenticator);
						$var($String, var$5, $nc(this->url)->getHost());
						$var($InetAddress, var$6, addr);
						int32_t var$7 = port;
						$init($Authenticator$RequestorType);
						$assign(a, privilegedRequestPasswordAuthentication(var$4, var$5, var$6, var$7, $($nc(this->url)->getProtocol()), realm, scheme, this->url, $Authenticator$RequestorType::SERVER));
						if (a != nullptr) {
							$set(this, digestparams, $new($DigestAuthentication$Parameters));
							$assign(ret, $new($DigestAuthentication, false, this->url, realm, scheme, a, this->digestparams, $(getAuthenticatorKey())));
						}
						break;
					}
				case 3:
					{
						$init($NTLMAuthenticationProxy);
						if ($NTLMAuthenticationProxy::supported) {
							$var($URL, url1, nullptr);
							try {
								$assign(url1, $new($URL, this->url, "/"_s));
							} catch ($Exception& e) {
								$assign(url1, this->url);
							}
							if (this->tryTransparentNTLMServer) {
								this->tryTransparentNTLMServer = $NTLMAuthenticationProxy::supportsTransparentAuth$;
								if (this->tryTransparentNTLMServer) {
									this->tryTransparentNTLMServer = $NTLMAuthenticationProxy::isTrustedSite(this->url);
								}
							}
							$assign(a, nullptr);
							if (this->tryTransparentNTLMServer) {
								$nc(HttpURLConnection::logger)->finest("Trying Transparent NTLM authentication"_s);
							} else {
								$var($Authenticator, var$8, this->authenticator);
								$var($String, var$9, $nc(this->url)->getHost());
								$var($InetAddress, var$10, addr);
								int32_t var$11 = port;
								$init($Authenticator$RequestorType);
								$assign(a, privilegedRequestPasswordAuthentication(var$8, var$9, var$10, var$11, $($nc(this->url)->getProtocol()), ""_s, scheme, this->url, $Authenticator$RequestorType::SERVER));
							}
							if (this->tryTransparentNTLMServer || (!this->tryTransparentNTLMServer && a != nullptr)) {
								$assign(ret, $nc($NTLMAuthenticationProxy::proxy)->create(false, url1, a, $(getAuthenticatorKey())));
							}
							this->tryTransparentNTLMServer = false;
						}
						break;
					}
				case 6:
					{
						$init($PlatformLogger$Level);
						if ($nc(HttpURLConnection::logger)->isLoggable($PlatformLogger$Level::FINEST)) {
							$nc(HttpURLConnection::logger)->finest($$str({"Unknown/Unsupported authentication scheme: "_s, scheme}));
						}
					}
				default:
					{
						$throwNew($AssertionError, $of("should not reach here"_s));
					}
				}
			}
		}
		if (ret == nullptr && HttpURLConnection::defaultAuth != nullptr && $nc(HttpURLConnection::defaultAuth)->schemeSupported(scheme)) {
			$var($String, a, $nc(HttpURLConnection::defaultAuth)->authString(this->url, scheme, realm));
			if (a != nullptr) {
				$assign(ret, $new($BasicAuthentication, false, this->url, realm, a, $(getAuthenticatorKey())));
			}
		}
		if (ret != nullptr) {
			if (!ret->setHeaders(this, p, raw)) {
				$assign(ret, nullptr);
			}
		}
	}
	$init($PlatformLogger$Level);
	if ($nc(HttpURLConnection::logger)->isLoggable($PlatformLogger$Level::FINER)) {
		$var($String, var$12, $$str({"Server Authentication for "_s, $(authhdr->toString()), " returned "_s}));
		$nc(HttpURLConnection::logger)->finer($$concat(var$12, (ret != nullptr ? $($nc($of(ret))->toString()) : "null"_s)));
	}
	return ret;
}

void HttpURLConnection::checkResponseCredentials(bool inClose) {
	$useLocalCurrentObjectStackCache();
	try {
		if (!this->needToCheck) {
			return;
		}
		if ((HttpURLConnection::validateProxy && this->currentProxyCredentials != nullptr) && ($instanceOf($DigestAuthentication, this->currentProxyCredentials))) {
			$var($String, raw, $nc(this->responses)->findValue("Proxy-Authentication-Info"_s));
			if (inClose || (raw != nullptr)) {
				$var($DigestAuthentication, da, $cast($DigestAuthentication, this->currentProxyCredentials));
				$nc(da)->checkResponse(raw, this->method, $(getRequestURI()));
				$set(this, currentProxyCredentials, nullptr);
			}
		}
		if ((HttpURLConnection::validateServer && this->currentServerCredentials != nullptr) && ($instanceOf($DigestAuthentication, this->currentServerCredentials))) {
			$var($String, raw, $nc(this->responses)->findValue("Authentication-Info"_s));
			if (inClose || (raw != nullptr)) {
				$var($DigestAuthentication, da, $cast($DigestAuthentication, this->currentServerCredentials));
				$nc(da)->checkResponse(raw, this->method, this->url);
				$set(this, currentServerCredentials, nullptr);
			}
		}
		if ((this->currentServerCredentials == nullptr) && (this->currentProxyCredentials == nullptr)) {
			this->needToCheck = false;
		}
	} catch ($IOException& e) {
		disconnectInternal();
		this->connected = false;
		$throw(e);
	}
}

$String* HttpURLConnection::getRequestURI() {
	if (this->requestURI == nullptr) {
		$set(this, requestURI, $nc(this->http)->getURLFile());
	}
	return this->requestURI;
}

bool HttpURLConnection::followRedirect() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (!getInstanceFollowRedirects()) {
		return false;
	}
	int32_t stat = getResponseCode();
	if (stat < 300 || stat > 307 || stat == 306 || stat == $HttpURLConnection::HTTP_NOT_MODIFIED) {
		return false;
	}
	$var($String, loc, getHeaderField("Location"_s));
	if (loc == nullptr) {
		return false;
	}
	$var($URL, locUrl, nullptr);
	try {
		$assign(locUrl, $new($URL, loc));
		if (!$nc($($nc(this->url)->getProtocol()))->equalsIgnoreCase($(locUrl->getProtocol()))) {
			return false;
		}
	} catch ($MalformedURLException& mue) {
		$assign(locUrl, $new($URL, this->url, loc));
	}
	$var($URL, locUrl0, locUrl);
	$set(this, socketPermission, nullptr);
	$var($SocketPermission, p, URLtoSocketPermission(locUrl));
	if (p != nullptr) {
		try {
			return $nc(($cast($Boolean, $($AccessController::doPrivilegedWithCombiner(static_cast<$PrivilegedExceptionAction*>($$new($HttpURLConnection$12, this, loc, stat, locUrl0)), ($AccessControlContext*)nullptr, $$new($PermissionArray, {static_cast<$Permission*>(p)}))))))->booleanValue();
		} catch ($PrivilegedActionException& e) {
			$throw($cast($IOException, $(e->getException())));
		}
	} else {
		return followRedirect0(loc, stat, locUrl);
	}
}

bool HttpURLConnection::followRedirect0($String* loc, int32_t stat, $URL* locUrl) {
	$useLocalCurrentObjectStackCache();
	if (!HttpURLConnection::$assertionsDisabled && !isLockHeldByCurrentThread()) {
		$throwNew($AssertionError);
	}
	disconnectInternal();
	if (streaming()) {
		$throwNew($HttpRetryException, HttpURLConnection::RETRY_MSG3, stat, loc);
	}
	$init($PlatformLogger$Level);
	if ($nc(HttpURLConnection::logger)->isLoggable($PlatformLogger$Level::FINE)) {
		$nc(HttpURLConnection::logger)->fine($$str({"Redirected from "_s, this->url, " to "_s, locUrl}));
	}
	$set(this, responses, $new($MessageHeader));
	if (stat == $HttpURLConnection::HTTP_USE_PROXY) {
		$var($String, proxyHost, $nc(locUrl)->getHost());
		int32_t proxyPort = locUrl->getPort();
		$var($SecurityManager, security, $System::getSecurityManager());
		if (security != nullptr) {
			security->checkConnect(proxyHost, proxyPort);
		}
		setProxiedClient(this->url, proxyHost, proxyPort);
		$nc(this->requests)->set(0, $$str({this->method, " "_s, $(getRequestURI()), " "_s, HttpURLConnection::httpVersion}), nullptr);
		this->connected = true;
		this->useProxyResponseCode = true;
	} else {
		$var($URL, prevURL, this->url);
		$set(this, url, locUrl);
		$set(this, requestURI, nullptr);
		bool var$0 = $nc(this->method)->equals("POST"_s);
		if (var$0 && !$Boolean::getBoolean("http.strictPostRedirect"_s) && (stat != 307)) {
			$set(this, requests, $new($MessageHeader));
			this->setRequests = false;
			$HttpURLConnection::setRequestMethod("GET"_s);
			$set(this, poster, nullptr);
			if (!checkReuseConnection()) {
				connect();
			}
			if (!sameDestination(prevURL, this->url)) {
				$set(this, userCookies, nullptr);
				$set(this, userCookies2, nullptr);
			}
		} else {
			if (!checkReuseConnection()) {
				connect();
			}
			if (this->http != nullptr) {
				$nc(this->requests)->set(0, $$str({this->method, " "_s, $(getRequestURI()), " "_s, HttpURLConnection::httpVersion}), nullptr);
				int32_t port = $nc(this->url)->getPort();
				$var($String, host, stripIPv6ZoneId($($nc(this->url)->getHost())));
				if (port != -1 && port != $nc(this->url)->getDefaultPort()) {
					$plusAssign(host, $$str({":"_s, $($String::valueOf(port))}));
				}
				$nc(this->requests)->set("Host"_s, host);
			}
			if (!sameDestination(prevURL, this->url)) {
				$set(this, userCookies, nullptr);
				$set(this, userCookies2, nullptr);
				$nc(this->requests)->remove("Cookie"_s);
				$nc(this->requests)->remove("Cookie2"_s);
				$nc(this->requests)->remove("Authorization"_s);
				$var($AuthenticationInfo, sauth, $AuthenticationInfo::getServerAuth(this->url, $(getAuthenticatorKey())));
				if (sauth != nullptr && sauth->supportsPreemptiveAuthorization()) {
					$var($String, var$1, sauth->getHeaderName());
					$nc(this->requests)->setIfNotSet(var$1, $(sauth->getHeaderValue(this->url, this->method)));
					$set(this, currentServerCredentials, sauth);
				}
			}
		}
	}
	return true;
}

bool HttpURLConnection::sameDestination($URL* firstURL, $URL* secondURL) {
	$init(HttpURLConnection);
	$useLocalCurrentObjectStackCache();
	if (!HttpURLConnection::$assertionsDisabled && !$nc($($nc(firstURL)->getProtocol()))->equalsIgnoreCase($($nc(secondURL)->getProtocol()))) {
		$throwNew($AssertionError, $of($$str({"protocols not equal: "_s, firstURL, " - "_s, secondURL})));
	}
	if (!$nc($($nc(firstURL)->getHost()))->equalsIgnoreCase($($nc(secondURL)->getHost()))) {
		return false;
	}
	int32_t firstPort = $nc(firstURL)->getPort();
	if (firstPort == -1) {
		firstPort = firstURL->getDefaultPort();
	}
	int32_t secondPort = $nc(secondURL)->getPort();
	if (secondPort == -1) {
		secondPort = secondURL->getDefaultPort();
	}
	if (firstPort != secondPort) {
		return false;
	}
	return true;
}

void HttpURLConnection::reset() {
	$useLocalCurrentObjectStackCache();
	$nc(this->http)->reuse = true;
	$set(this, reuseClient, this->http);
	$var($InputStream, is, $nc(this->http)->getInputStream());
	if (!$nc(this->method)->equals("HEAD"_s)) {
		try {
			if (($instanceOf($ChunkedInputStream, is)) || ($instanceOf($MeteredStream, is))) {
				while ($nc(is)->read(this->cdata) > 0) {
				}
			} else {
				int64_t cl = 0;
				int32_t n = 0;
				$var($String, cls, $nc(this->responses)->findValue("Content-Length"_s));
				if (cls != nullptr) {
					try {
						cl = $Long::parseLong(cls);
					} catch ($NumberFormatException& e) {
						cl = 0;
					}
				}
				for (int64_t i = 0; i < cl;) {
					if ((n = $nc(is)->read(this->cdata)) == -1) {
						break;
					} else {
						i += n;
					}
				}
			}
		} catch ($IOException& e) {
			$nc(this->http)->reuse = false;
			$set(this, reuseClient, nullptr);
			disconnectInternal();
			return;
		}
		try {
			if ($instanceOf($MeteredStream, is)) {
				$nc(is)->close();
			}
		} catch ($IOException& e) {
		}
	}
	this->responseCode = -1;
	$set(this, responses, $new($MessageHeader));
	this->connected = false;
}

void HttpURLConnection::disconnectWeb() {
	bool var$0 = usingProxyInternal();
	if (var$0 && $nc(this->http)->isKeepingAlive()) {
		this->responseCode = -1;
		reset();
	} else {
		disconnectInternal();
	}
}

void HttpURLConnection::disconnectInternal() {
	this->responseCode = -1;
	$set(this, inputStream, nullptr);
	if (this->pi != nullptr) {
		$nc(this->pi)->finishTracking();
		$set(this, pi, nullptr);
	}
	if (this->http != nullptr) {
		$nc(this->http)->closeServer();
		$set(this, http, nullptr);
		this->connected = false;
	}
}

void HttpURLConnection::disconnect() {
	this->responseCode = -1;
	if (this->pi != nullptr) {
		$nc(this->pi)->finishTracking();
		$set(this, pi, nullptr);
	}
	if (this->http != nullptr) {
		if (this->inputStream != nullptr) {
			$var($HttpClient, hc, this->http);
			bool ka = $nc(hc)->isKeepingAlive();
			try {
				$nc(this->inputStream)->close();
			} catch ($IOException& ioe) {
			}
			if (ka) {
				hc->closeIdleConnection();
			}
		} else {
			$nc(this->http)->setDoNotRetry(true);
			$nc(this->http)->closeServer();
		}
		$set(this, http, nullptr);
		this->connected = false;
	}
	$set(this, cachedInputStream, nullptr);
	if (this->cachedHeaders != nullptr) {
		$nc(this->cachedHeaders)->reset();
	}
}

bool HttpURLConnection::usingProxyInternal() {
	if (this->http != nullptr) {
		return ($nc(this->http)->getProxyHostUsed() != nullptr);
	}
	return false;
}

bool HttpURLConnection::usingProxy() {
	if (this->usingProxy$ || usingProxyInternal()) {
		return true;
	}
	if (this->instProxy != nullptr) {
		$init($Proxy$Type);
		return $nc($($nc(this->instProxy)->type()))->equals($Proxy$Type::HTTP);
	}
	return false;
}

$String* HttpURLConnection::filterHeaderField($String* name, $String* value) {
	$useLocalCurrentObjectStackCache();
	if (value == nullptr) {
		return nullptr;
	}
	bool var$0 = $nc(HttpURLConnection::SET_COOKIE)->equalsIgnoreCase(name);
	if (var$0 || $nc(HttpURLConnection::SET_COOKIE2)->equalsIgnoreCase(name)) {
		if (this->cookieHandler == nullptr || $nc(value)->isEmpty()) {
			return value;
		}
		$var($JavaNetHttpCookieAccess, access, $SharedSecrets::getJavaNetHttpCookieAccess());
		$var($StringJoiner, retValue, $new($StringJoiner, ","_s));
		$var($List, cookies, $nc(access)->parse(value));
		{
			$var($Iterator, i$, $nc(cookies)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($HttpCookie, cookie, $cast($HttpCookie, i$->next()));
				{
					if (!$nc(cookie)->isHttpOnly()) {
						retValue->add($(access->header(cookie)));
					}
				}
			}
		}
		return retValue->toString();
	}
	return value;
}

$Map* HttpURLConnection::getFilteredHeaderFields() {
	$useLocalCurrentObjectStackCache();
	if (this->filteredHeaders != nullptr) {
		return this->filteredHeaders;
	}
	$var($Map, headers, nullptr);
	$var($Map, tmpMap, $new($HashMap));
	if (this->cachedHeaders != nullptr) {
		$assign(headers, $nc(this->cachedHeaders)->getHeaders());
	} else {
		$assign(headers, $nc(this->responses)->getHeaders());
	}
	{
		$var($Iterator, i$, $nc($($nc(headers)->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
			{
				$var($String, key, $cast($String, $nc(e)->getKey()));
				$var($List, values, $cast($List, e->getValue()));
				$var($List, filteredVals, $new($ArrayList));
				{
					$var($Iterator, i$, $nc(values)->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($String, value, $cast($String, i$->next()));
						{
							$var($String, fVal, filterHeaderField(key, value));
							if (fVal != nullptr) {
								filteredVals->add(fVal);
							}
						}
					}
				}
				if (!filteredVals->isEmpty()) {
					tmpMap->put(key, $($Collections::unmodifiableList(filteredVals)));
				}
			}
		}
	}
	return $set(this, filteredHeaders, $Collections::unmodifiableMap(tmpMap));
}

$String* HttpURLConnection::getHeaderField($String* name) {
	$useLocalCurrentObjectStackCache();
	try {
		getInputStream();
	} catch ($IOException& e) {
	}
	if (this->cachedHeaders != nullptr) {
		return filterHeaderField(name, $($nc(this->cachedHeaders)->findValue(name)));
	}
	return filterHeaderField(name, $($nc(this->responses)->findValue(name)));
}

$Map* HttpURLConnection::getHeaderFields() {
	try {
		getInputStream();
	} catch ($IOException& e) {
	}
	return getFilteredHeaderFields();
}

$String* HttpURLConnection::getHeaderField(int32_t n) {
	$useLocalCurrentObjectStackCache();
	try {
		getInputStream();
	} catch ($IOException& e) {
	}
	if (this->cachedHeaders != nullptr) {
		$var($String, var$0, $nc(this->cachedHeaders)->getKey(n));
		return filterHeaderField(var$0, $($nc(this->cachedHeaders)->getValue(n)));
	}
	$var($String, var$1, $nc(this->responses)->getKey(n));
	return filterHeaderField(var$1, $($nc(this->responses)->getValue(n)));
}

$String* HttpURLConnection::getHeaderFieldKey(int32_t n) {
	try {
		getInputStream();
	} catch ($IOException& e) {
	}
	if (this->cachedHeaders != nullptr) {
		return $nc(this->cachedHeaders)->getKey(n);
	}
	return $nc(this->responses)->getKey(n);
}

void HttpURLConnection::setRequestProperty($String* key, $String* value) {
	lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			if (this->connected || this->connecting) {
				$throwNew($IllegalStateException, "Already connected"_s);
			}
			if (key == nullptr) {
				$throwNew($NullPointerException, "key is null"_s);
			}
			if (isExternalMessageHeaderAllowed(key, value)) {
				$nc(this->requests)->set(key, value);
				if (!$nc(key)->equalsIgnoreCase("Content-Type"_s)) {
					$nc(this->userHeaders)->set(key, value);
				}
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

$MessageHeader* HttpURLConnection::getUserSetHeaders() {
	return this->userHeaders;
}

void HttpURLConnection::addRequestProperty($String* key, $String* value) {
	lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			if (this->connected || this->connecting) {
				$throwNew($IllegalStateException, "Already connected"_s);
			}
			if (key == nullptr) {
				$throwNew($NullPointerException, "key is null"_s);
			}
			if (isExternalMessageHeaderAllowed(key, value)) {
				$nc(this->requests)->add(key, value);
				if (!$nc(key)->equalsIgnoreCase("Content-Type"_s)) {
					$nc(this->userHeaders)->add(key, value);
				}
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void HttpURLConnection::setAuthenticationProperty($String* key, $String* value) {
	if (!HttpURLConnection::$assertionsDisabled && !isLockHeldByCurrentThread()) {
		$throwNew($AssertionError);
	}
	checkMessageHeader(key, value);
	$nc(this->requests)->set(key, value);
}

$String* HttpURLConnection::getRequestProperty($String* key) {
	$useLocalCurrentObjectStackCache();
	lock();
	{
		$var($Throwable, var$0, nullptr);
		$var($String, var$2, nullptr);
		bool return$1 = false;
		try {
			if (key == nullptr) {
				$assign(var$2, nullptr);
				return$1 = true;
				goto $finally;
			}
			for (int32_t i = 0; i < $nc(HttpURLConnection::EXCLUDE_HEADERS)->length; ++i) {
				if ($nc(key)->equalsIgnoreCase($nc(HttpURLConnection::EXCLUDE_HEADERS)->get(i))) {
					$assign(var$2, nullptr);
					return$1 = true;
					goto $finally;
				}
			}
			if (!this->setUserCookies) {
				if ($nc(key)->equalsIgnoreCase("Cookie"_s)) {
					$assign(var$2, this->userCookies);
					return$1 = true;
					goto $finally;
				}
				if ($nc(key)->equalsIgnoreCase("Cookie2"_s)) {
					$assign(var$2, this->userCookies2);
					return$1 = true;
					goto $finally;
				}
			}
			$assign(var$2, $nc(this->requests)->findValue(key));
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

$Map* HttpURLConnection::getRequestProperties() {
	$useLocalCurrentObjectStackCache();
	lock();
	{
		$var($Throwable, var$0, nullptr);
		$var($Map, var$2, nullptr);
		bool return$1 = false;
		try {
			if (this->connected) {
				$throwNew($IllegalStateException, "Already connected"_s);
			}
			if (this->setUserCookies) {
				$assign(var$2, $nc(this->requests)->getHeaders(HttpURLConnection::EXCLUDE_HEADERS));
				return$1 = true;
				goto $finally;
			}
			$var($Map, userCookiesMap, nullptr);
			if (this->userCookies != nullptr || this->userCookies2 != nullptr) {
				$assign(userCookiesMap, $new($HashMap));
				if (this->userCookies != nullptr) {
					userCookiesMap->put("Cookie"_s, $($Arrays::asList($$new($StringArray, {this->userCookies}))));
				}
				if (this->userCookies2 != nullptr) {
					userCookiesMap->put("Cookie2"_s, $($Arrays::asList($$new($StringArray, {this->userCookies2}))));
				}
			}
			$assign(var$2, $nc(this->requests)->filterAndAddHeaders(HttpURLConnection::EXCLUDE_HEADERS2, userCookiesMap));
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

void HttpURLConnection::setConnectTimeout(int32_t timeout) {
	if (timeout < 0) {
		$throwNew($IllegalArgumentException, "timeouts can\'t be negative"_s);
	}
	this->connectTimeout = timeout;
}

int32_t HttpURLConnection::getConnectTimeout() {
	return (this->connectTimeout < 0 ? 0 : this->connectTimeout);
}

void HttpURLConnection::setReadTimeout(int32_t timeout) {
	if (timeout < 0) {
		$throwNew($IllegalArgumentException, "timeouts can\'t be negative"_s);
	}
	this->readTimeout = timeout;
}

int32_t HttpURLConnection::getReadTimeout() {
	return this->readTimeout < 0 ? 0 : this->readTimeout;
}

$CookieHandler* HttpURLConnection::getCookieHandler() {
	return this->cookieHandler;
}

$String* HttpURLConnection::getMethod() {
	return this->method;
}

$MessageHeader* HttpURLConnection::mapToMessageHeader($Map* map) {
	$useLocalCurrentObjectStackCache();
	$var($MessageHeader, headers, $new($MessageHeader));
	if (map == nullptr || $nc(map)->isEmpty()) {
		return headers;
	}
	{
		$var($Iterator, i$, $nc($($nc(map)->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
			{
				$var($String, key, $cast($String, $nc(entry)->getKey()));
				$var($List, values, $cast($List, entry->getValue()));
				{
					$var($Iterator, i$, $nc(values)->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($String, value, $cast($String, i$->next()));
						{
							if (key == nullptr) {
								headers->prepend(key, value);
							} else {
								headers->add(key, value);
							}
						}
					}
				}
			}
		}
	}
	return headers;
}

$String* HttpURLConnection::stripIPv6ZoneId($String* host) {
	$init(HttpURLConnection);
	if ($nc(host)->charAt(0) != u'[') {
		return host;
	}
	int32_t i = $nc(host)->lastIndexOf((int32_t)u'%');
	if (i == -1) {
		return host;
	}
	return $str({$(host->substring(0, i)), "]"_s});
}

$String* HttpURLConnection::lambda$getNetProperty$0($String* name) {
	$init(HttpURLConnection);
	return $NetProperties::get(name);
}

void clinit$HttpURLConnection($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(HttpURLConnection::HTTP_CONNECT, "CONNECT"_s);
	$assignStatic(HttpURLConnection::RETRY_MSG1, "cannot retry due to proxy authentication, in streaming mode"_s);
	$assignStatic(HttpURLConnection::RETRY_MSG2, "cannot retry due to server authentication, in streaming mode"_s);
	$assignStatic(HttpURLConnection::RETRY_MSG3, "cannot retry due to redirection, in streaming mode"_s);
	$assignStatic(HttpURLConnection::httpVersion, "HTTP/1.1"_s);
	$assignStatic(HttpURLConnection::acceptString, "text/html, image/gif, image/jpeg, *; q=.2, */*; q=.2"_s);
	$assignStatic(HttpURLConnection::SET_COOKIE, "set-cookie"_s);
	$assignStatic(HttpURLConnection::SET_COOKIE2, "set-cookie2"_s);
	HttpURLConnection::$assertionsDisabled = !HttpURLConnection::class$->desiredAssertionStatus();
	HttpURLConnection::enableESBuffer = false;
	HttpURLConnection::timeout4ESBuffer = 0;
	HttpURLConnection::bufSize4ES = 0;
	$assignStatic(HttpURLConnection::restrictedHeaders, $new($StringArray, {
		"Access-Control-Request-Headers"_s,
		"Access-Control-Request-Method"_s,
		"Connection"_s,
		"Content-Length"_s,
		"Content-Transfer-Encoding"_s,
		"Host"_s,
		"Keep-Alive"_s,
		"Origin"_s,
		"Trailer"_s,
		"Transfer-Encoding"_s,
		"Upgrade"_s,
		"Via"_s
	}));
	{
		$var($Properties, props, $GetPropertyAction::privilegedGetProperties());
		HttpURLConnection::maxRedirects = $nc($($GetIntegerAction::privilegedGetProperty("http.maxRedirects"_s, HttpURLConnection::defaultmaxRedirects)))->intValue();
		$assignStatic(HttpURLConnection::version, $nc(props)->getProperty("java.version"_s));
		$var($String, agent, props->getProperty("http.agent"_s));
		if (agent == nullptr) {
			$assign(agent, $str({"Java/"_s, HttpURLConnection::version}));
		} else {
			$assign(agent, $str({agent, " Java/"_s, HttpURLConnection::version}));
		}
		$assignStatic(HttpURLConnection::userAgent, agent);
		$var($String, p, HttpURLConnection::getNetProperty("jdk.http.auth.tunneling.disabledSchemes"_s));
		$assignStatic(HttpURLConnection::disabledTunnelingSchemes, HttpURLConnection::schemesListToSet(p));
		$assign(p, HttpURLConnection::getNetProperty("jdk.http.auth.proxying.disabledSchemes"_s));
		$assignStatic(HttpURLConnection::disabledProxyingSchemes, HttpURLConnection::schemesListToSet(p));
		HttpURLConnection::validateProxy = $Boolean::parseBoolean($(props->getProperty("http.auth.digest.validateProxy"_s)));
		HttpURLConnection::validateServer = $Boolean::parseBoolean($(props->getProperty("http.auth.digest.validateServer"_s)));
		HttpURLConnection::enableESBuffer = $Boolean::parseBoolean($(props->getProperty("sun.net.http.errorstream.enableBuffering"_s)));
		HttpURLConnection::timeout4ESBuffer = $nc($($GetIntegerAction::privilegedGetProperty("sun.net.http.errorstream.timeout"_s, 300)))->intValue();
		if (HttpURLConnection::timeout4ESBuffer <= 0) {
			HttpURLConnection::timeout4ESBuffer = 300;
		}
		HttpURLConnection::bufSize4ES = $nc($($GetIntegerAction::privilegedGetProperty("sun.net.http.errorstream.bufferSize"_s, 4096)))->intValue();
		if (HttpURLConnection::bufSize4ES <= 0) {
			HttpURLConnection::bufSize4ES = 4096;
		}
		HttpURLConnection::allowRestrictedHeaders = $Boolean::parseBoolean($(props->getProperty("sun.net.http.allowRestrictedHeaders"_s)));
		if (!HttpURLConnection::allowRestrictedHeaders) {
			$assignStatic(HttpURLConnection::restrictedHeaderSet, $new($HashSet, $nc(HttpURLConnection::restrictedHeaders)->length));
			for (int32_t i = 0; i < $nc(HttpURLConnection::restrictedHeaders)->length; ++i) {
				$nc(HttpURLConnection::restrictedHeaderSet)->add($($nc($nc(HttpURLConnection::restrictedHeaders)->get(i))->toLowerCase()));
			}
		} else {
			$assignStatic(HttpURLConnection::restrictedHeaderSet, nullptr);
		}
	}
	$assignStatic(HttpURLConnection::EXCLUDE_HEADERS, $new($StringArray, {
		"Proxy-Authorization"_s,
		"Authorization"_s
	}));
	$assignStatic(HttpURLConnection::EXCLUDE_HEADERS2, $new($StringArray, {
		"Proxy-Authorization"_s,
		"Authorization"_s,
		"Cookie"_s,
		"Cookie2"_s
	}));
	$assignStatic(HttpURLConnection::logger, $PlatformLogger::getLogger("sun.net.www.protocol.http.HttpURLConnection"_s));
}

HttpURLConnection::HttpURLConnection() {
}

$Class* HttpURLConnection::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(HttpURLConnection$$Lambda$lambda$getNetProperty$0::classInfo$.name)) {
			return HttpURLConnection$$Lambda$lambda$getNetProperty$0::load$(name, initialize);
		}
	}
	$loadClass(HttpURLConnection, name, initialize, &_HttpURLConnection_ClassInfo_, clinit$HttpURLConnection, allocate$HttpURLConnection);
	return class$;
}

$Class* HttpURLConnection::class$ = nullptr;

				} // http
			} // protocol
		} // www
	} // net
} // sun