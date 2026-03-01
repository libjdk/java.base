#include <sun/net/ftp/impl/FtpClient.h>

#include <java/io/BufferedInputStream.h>
#include <java/io/BufferedOutputStream.h>
#include <java/io/BufferedReader.h>
#include <java/io/FileNotFoundException.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/InputStreamReader.h>
#include <java/io/OutputStream.h>
#include <java/io/Reader.h>
#include <java/io/Serializable.h>
#include <java/io/UnsupportedEncodingException.h>
#include <java/lang/CharSequence.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/IndexOutOfBoundsException.h>
#include <java/lang/InternalError.h>
#include <java/lang/NumberFormatException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/Inet6Address.h>
#include <java/net/InetAddress.h>
#include <java/net/InetSocketAddress.h>
#include <java/net/Proxy$Type.h>
#include <java/net/Proxy.h>
#include <java/net/ServerSocket.h>
#include <java/net/Socket.h>
#include <java/net/SocketAddress.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/text/DateFormat.h>
#include <java/time/Instant.h>
#include <java/time/ZoneId.h>
#include <java/time/ZoneOffset.h>
#include <java/time/ZonedDateTime.h>
#include <java/time/format/DateTimeFormatter.h>
#include <java/time/format/DateTimeParseException.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Base64$Decoder.h>
#include <java/util/Base64$Encoder.h>
#include <java/util/Base64.h>
#include <java/util/Date.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/Optional.h>
#include <java/util/Vector.h>
#include <java/util/function/Function.h>
#include <java/util/function/Predicate.h>
#include <java/util/regex/Matcher.h>
#include <java/util/regex/Pattern.h>
#include <java/util/stream/Stream.h>
#include <javax/net/SocketFactory.h>
#include <javax/net/ssl/SSLException.h>
#include <javax/net/ssl/SSLSession.h>
#include <javax/net/ssl/SSLSocket.h>
#include <javax/net/ssl/SSLSocketFactory.h>
#include <sun/net/TelnetInputStream.h>
#include <sun/net/TelnetOutputStream.h>
#include <sun/net/ftp/FtpClient$TransferType.h>
#include <sun/net/ftp/FtpClient.h>
#include <sun/net/ftp/FtpDirParser.h>
#include <sun/net/ftp/FtpProtocolException.h>
#include <sun/net/ftp/FtpReplyCode.h>
#include <sun/net/ftp/impl/FtpClient$1.h>
#include <sun/net/ftp/impl/FtpClient$DefaultParser.h>
#include <sun/net/ftp/impl/FtpClient$FtpFileIterator.h>
#include <sun/net/ftp/impl/FtpClient$MLSxParser.h>
#include <sun/net/util/IPAddressUtil.h>
#include <sun/util/logging/PlatformLogger$Level.h>
#include <sun/util/logging/PlatformLogger.h>
#include <jcpp.h>

#undef ASCII
#undef BAD_SEQUENCE
#undef BINARY
#undef CLOSING_DATA_CONNECTION
#undef EBCDIC
#undef ERROR_MSG
#undef FILE_STATUS
#undef FILE_UNAVAILABLE
#undef FINEST
#undef MEDIUM
#undef NEED_ACCOUNT
#undef NEED_PASSWORD
#undef NO_PROXY
#undef SOCKS
#undef US
#undef UTC

using $InetAddressArray = $Array<::java::net::InetAddress>;
using $PatternArray = $Array<::java::util::regex::Pattern>;
using $intArray2 = $Array<int32_t, 2>;
using $BufferedInputStream = ::java::io::BufferedInputStream;
using $BufferedOutputStream = ::java::io::BufferedOutputStream;
using $BufferedReader = ::java::io::BufferedReader;
using $FileNotFoundException = ::java::io::FileNotFoundException;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $InputStreamReader = ::java::io::InputStreamReader;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $Reader = ::java::io::Reader;
using $Serializable = ::java::io::Serializable;
using $UnsupportedEncodingException = ::java::io::UnsupportedEncodingException;
using $Boolean = ::java::lang::Boolean;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $IndexOutOfBoundsException = ::java::lang::IndexOutOfBoundsException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Inet6Address = ::java::net::Inet6Address;
using $InetAddress = ::java::net::InetAddress;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $Proxy = ::java::net::Proxy;
using $Proxy$Type = ::java::net::Proxy$Type;
using $ServerSocket = ::java::net::ServerSocket;
using $Socket = ::java::net::Socket;
using $SocketAddress = ::java::net::SocketAddress;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $DateFormat = ::java::text::DateFormat;
using $ZoneId = ::java::time::ZoneId;
using $ZoneOffset = ::java::time::ZoneOffset;
using $ZonedDateTime = ::java::time::ZonedDateTime;
using $DateTimeFormatter = ::java::time::format::DateTimeFormatter;
using $DateTimeParseException = ::java::time::format::DateTimeParseException;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Base64 = ::java::util::Base64;
using $Base64$Decoder = ::java::util::Base64$Decoder;
using $Base64$Encoder = ::java::util::Base64$Encoder;
using $Date = ::java::util::Date;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Optional = ::java::util::Optional;
using $Vector = ::java::util::Vector;
using $Function = ::java::util::function::Function;
using $Predicate = ::java::util::function::Predicate;
using $Matcher = ::java::util::regex::Matcher;
using $Pattern = ::java::util::regex::Pattern;
using $Stream = ::java::util::stream::Stream;
using $SSLException = ::javax::net::ssl::SSLException;
using $SSLSession = ::javax::net::ssl::SSLSession;
using $SSLSocket = ::javax::net::ssl::SSLSocket;
using $SSLSocketFactory = ::javax::net::ssl::SSLSocketFactory;
using $TelnetInputStream = ::sun::net::TelnetInputStream;
using $TelnetOutputStream = ::sun::net::TelnetOutputStream;
using $FtpClient = ::sun::net::ftp::FtpClient;
using $FtpClient$TransferType = ::sun::net::ftp::FtpClient$TransferType;
using $FtpDirParser = ::sun::net::ftp::FtpDirParser;
using $FtpProtocolException = ::sun::net::ftp::FtpProtocolException;
using $FtpReplyCode = ::sun::net::ftp::FtpReplyCode;
using $FtpClient$1 = ::sun::net::ftp::impl::FtpClient$1;
using $FtpClient$DefaultParser = ::sun::net::ftp::impl::FtpClient$DefaultParser;
using $FtpClient$FtpFileIterator = ::sun::net::ftp::impl::FtpClient$FtpFileIterator;
using $FtpClient$MLSxParser = ::sun::net::ftp::impl::FtpClient$MLSxParser;
using $IPAddressUtil = ::sun::net::util::IPAddressUtil;
using $PlatformLogger = ::sun::util::logging::PlatformLogger;
using $PlatformLogger$Level = ::sun::util::logging::PlatformLogger$Level;

namespace sun {
	namespace net {
		namespace ftp {
			namespace impl {

class FtpClient$$Lambda$lambda$openPassiveDataConnection$0 : public $PrivilegedAction {
	$class(FtpClient$$Lambda$lambda$openPassiveDataConnection$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$(FtpClient* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* run() override {
		 return $of($nc(inst$)->lambda$openPassiveDataConnection$0());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<FtpClient$$Lambda$lambda$openPassiveDataConnection$0>());
	}
	FtpClient* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo FtpClient$$Lambda$lambda$openPassiveDataConnection$0::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(FtpClient$$Lambda$lambda$openPassiveDataConnection$0, inst$)},
	{}
};
$MethodInfo FtpClient$$Lambda$lambda$openPassiveDataConnection$0::methodInfos[3] = {
	{"<init>", "(Lsun/net/ftp/impl/FtpClient;)V", nullptr, $PUBLIC, $method(FtpClient$$Lambda$lambda$openPassiveDataConnection$0, init$, void, FtpClient*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(FtpClient$$Lambda$lambda$openPassiveDataConnection$0, run, $Object*)},
	{}
};
$ClassInfo FtpClient$$Lambda$lambda$openPassiveDataConnection$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.net.ftp.impl.FtpClient$$Lambda$lambda$openPassiveDataConnection$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* FtpClient$$Lambda$lambda$openPassiveDataConnection$0::load$($String* name, bool initialize) {
	$loadClass(FtpClient$$Lambda$lambda$openPassiveDataConnection$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* FtpClient$$Lambda$lambda$openPassiveDataConnection$0::class$ = nullptr;

class FtpClient$$Lambda$lambda$openPassiveDataConnection$1$1 : public $PrivilegedAction {
	$class(FtpClient$$Lambda$lambda$openPassiveDataConnection$1$1, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$(FtpClient* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* run() override {
		 return $of($nc(inst$)->lambda$openPassiveDataConnection$1());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<FtpClient$$Lambda$lambda$openPassiveDataConnection$1$1>());
	}
	FtpClient* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo FtpClient$$Lambda$lambda$openPassiveDataConnection$1$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(FtpClient$$Lambda$lambda$openPassiveDataConnection$1$1, inst$)},
	{}
};
$MethodInfo FtpClient$$Lambda$lambda$openPassiveDataConnection$1$1::methodInfos[3] = {
	{"<init>", "(Lsun/net/ftp/impl/FtpClient;)V", nullptr, $PUBLIC, $method(FtpClient$$Lambda$lambda$openPassiveDataConnection$1$1, init$, void, FtpClient*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(FtpClient$$Lambda$lambda$openPassiveDataConnection$1$1, run, $Object*)},
	{}
};
$ClassInfo FtpClient$$Lambda$lambda$openPassiveDataConnection$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.net.ftp.impl.FtpClient$$Lambda$lambda$openPassiveDataConnection$1$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* FtpClient$$Lambda$lambda$openPassiveDataConnection$1$1::load$($String* name, bool initialize) {
	$loadClass(FtpClient$$Lambda$lambda$openPassiveDataConnection$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* FtpClient$$Lambda$lambda$openPassiveDataConnection$1$1::class$ = nullptr;

class FtpClient$$Lambda$getHostAddress$2 : public $Function {
	$class(FtpClient$$Lambda$getHostAddress$2, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $of($sure($InetAddress, inst$)->getHostAddress());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<FtpClient$$Lambda$getHostAddress$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo FtpClient$$Lambda$getHostAddress$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(FtpClient$$Lambda$getHostAddress$2, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(FtpClient$$Lambda$getHostAddress$2, apply, $Object*, Object$*)},
	{}
};
$ClassInfo FtpClient$$Lambda$getHostAddress$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.net.ftp.impl.FtpClient$$Lambda$getHostAddress$2",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* FtpClient$$Lambda$getHostAddress$2::load$($String* name, bool initialize) {
	$loadClass(FtpClient$$Lambda$getHostAddress$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* FtpClient$$Lambda$getHostAddress$2::class$ = nullptr;

class FtpClient$$Lambda$equalsIgnoreCase$3 : public $Predicate {
	$class(FtpClient$$Lambda$equalsIgnoreCase$3, $NO_CLASS_INIT, $Predicate)
public:
	void init$($String* inst) {
		$set(this, inst$, inst);
	}
	virtual bool test(Object$* anotherString) override {
		 return $nc(inst$)->equalsIgnoreCase($cast($String, anotherString));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<FtpClient$$Lambda$equalsIgnoreCase$3>());
	}
	$String* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo FtpClient$$Lambda$equalsIgnoreCase$3::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(FtpClient$$Lambda$equalsIgnoreCase$3, inst$)},
	{}
};
$MethodInfo FtpClient$$Lambda$equalsIgnoreCase$3::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(FtpClient$$Lambda$equalsIgnoreCase$3, init$, void, $String*)},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(FtpClient$$Lambda$equalsIgnoreCase$3, test, bool, Object$*)},
	{}
};
$ClassInfo FtpClient$$Lambda$equalsIgnoreCase$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.net.ftp.impl.FtpClient$$Lambda$equalsIgnoreCase$3",
	"java.lang.Object",
	"java.util.function.Predicate",
	fieldInfos,
	methodInfos
};
$Class* FtpClient$$Lambda$equalsIgnoreCase$3::load$($String* name, bool initialize) {
	$loadClass(FtpClient$$Lambda$equalsIgnoreCase$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* FtpClient$$Lambda$equalsIgnoreCase$3::class$ = nullptr;

class FtpClient$$Lambda$getLocalHost$4 : public $PrivilegedExceptionAction {
	$class(FtpClient$$Lambda$getLocalHost$4, $NO_CLASS_INIT, $PrivilegedExceptionAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of($InetAddress::getLocalHost());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<FtpClient$$Lambda$getLocalHost$4>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo FtpClient$$Lambda$getLocalHost$4::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(FtpClient$$Lambda$getLocalHost$4, init$, void)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(FtpClient$$Lambda$getLocalHost$4, run, $Object*)},
	{}
};
$ClassInfo FtpClient$$Lambda$getLocalHost$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.net.ftp.impl.FtpClient$$Lambda$getLocalHost$4",
	"java.lang.Object",
	"java.security.PrivilegedExceptionAction",
	nullptr,
	methodInfos
};
$Class* FtpClient$$Lambda$getLocalHost$4::load$($String* name, bool initialize) {
	$loadClass(FtpClient$$Lambda$getLocalHost$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* FtpClient$$Lambda$getLocalHost$4::class$ = nullptr;

class FtpClient$$Lambda$lambda$privilegedGetAllByName$2$5 : public $PrivilegedExceptionAction {
	$class(FtpClient$$Lambda$lambda$privilegedGetAllByName$2$5, $NO_CLASS_INIT, $PrivilegedExceptionAction)
public:
	void init$($String* hostName) {
		$set(this, hostName, hostName);
	}
	virtual $Object* run() override {
		 return $of(FtpClient::lambda$privilegedGetAllByName$2(hostName));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<FtpClient$$Lambda$lambda$privilegedGetAllByName$2$5>());
	}
	$String* hostName = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo FtpClient$$Lambda$lambda$privilegedGetAllByName$2$5::fieldInfos[2] = {
	{"hostName", "Ljava/lang/String;", nullptr, $PUBLIC, $field(FtpClient$$Lambda$lambda$privilegedGetAllByName$2$5, hostName)},
	{}
};
$MethodInfo FtpClient$$Lambda$lambda$privilegedGetAllByName$2$5::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(FtpClient$$Lambda$lambda$privilegedGetAllByName$2$5, init$, void, $String*)},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(FtpClient$$Lambda$lambda$privilegedGetAllByName$2$5, run, $Object*)},
	{}
};
$ClassInfo FtpClient$$Lambda$lambda$privilegedGetAllByName$2$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.net.ftp.impl.FtpClient$$Lambda$lambda$privilegedGetAllByName$2$5",
	"java.lang.Object",
	"java.security.PrivilegedExceptionAction",
	fieldInfos,
	methodInfos
};
$Class* FtpClient$$Lambda$lambda$privilegedGetAllByName$2$5::load$($String* name, bool initialize) {
	$loadClass(FtpClient$$Lambda$lambda$privilegedGetAllByName$2$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* FtpClient$$Lambda$lambda$privilegedGetAllByName$2$5::class$ = nullptr;

$FieldInfo _FtpClient_FieldInfo_[] = {
	{"defaultSoTimeout", "I", nullptr, $PRIVATE | $STATIC, $staticField(FtpClient, defaultSoTimeout)},
	{"defaultConnectTimeout", "I", nullptr, $PRIVATE | $STATIC, $staticField(FtpClient, defaultConnectTimeout)},
	{"logger", "Lsun/util/logging/PlatformLogger;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(FtpClient, logger)},
	{"proxy", "Ljava/net/Proxy;", nullptr, $PRIVATE, $field(FtpClient, proxy)},
	{"server", "Ljava/net/Socket;", nullptr, $PRIVATE, $field(FtpClient, server)},
	{"out", "Ljava/io/PrintStream;", nullptr, $PRIVATE, $field(FtpClient, out)},
	{"in", "Ljava/io/InputStream;", nullptr, $PRIVATE, $field(FtpClient, in)},
	{"readTimeout", "I", nullptr, $PRIVATE, $field(FtpClient, readTimeout)},
	{"connectTimeout", "I", nullptr, $PRIVATE, $field(FtpClient, connectTimeout)},
	{"encoding", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticField(FtpClient, encoding)},
	{"serverAddr", "Ljava/net/InetSocketAddress;", nullptr, $PRIVATE, $field(FtpClient, serverAddr)},
	{"replyPending", "Z", nullptr, $PRIVATE, $field(FtpClient, replyPending)},
	{"loggedIn", "Z", nullptr, $PRIVATE, $field(FtpClient, loggedIn)},
	{"useCrypto", "Z", nullptr, $PRIVATE, $field(FtpClient, useCrypto)},
	{"sslFact", "Ljavax/net/ssl/SSLSocketFactory;", nullptr, $PRIVATE, $field(FtpClient, sslFact)},
	{"oldSocket", "Ljava/net/Socket;", nullptr, $PRIVATE, $field(FtpClient, oldSocket)},
	{"serverResponse", "Ljava/util/Vector;", "Ljava/util/Vector<Ljava/lang/String;>;", $PRIVATE, $field(FtpClient, serverResponse)},
	{"lastReplyCode", "Lsun/net/ftp/FtpReplyCode;", nullptr, $PRIVATE, $field(FtpClient, lastReplyCode)},
	{"welcomeMsg", "Ljava/lang/String;", nullptr, $PRIVATE, $field(FtpClient, welcomeMsg)},
	{"passiveMode", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(FtpClient, passiveMode)},
	{"type", "Lsun/net/ftp/FtpClient$TransferType;", nullptr, $PRIVATE, $field(FtpClient, type)},
	{"restartOffset", "J", nullptr, $PRIVATE, $field(FtpClient, restartOffset)},
	{"lastTransSize", "J", nullptr, $PRIVATE, $field(FtpClient, lastTransSize)},
	{"lastFileName", "Ljava/lang/String;", nullptr, $PRIVATE, $field(FtpClient, lastFileName)},
	{"patStrings", "[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticField(FtpClient, patStrings)},
	{"patternGroups", "[[I", nullptr, $PRIVATE | $STATIC, $staticField(FtpClient, patternGroups)},
	{"patterns", "[Ljava/util/regex/Pattern;", nullptr, $PRIVATE | $STATIC, $staticField(FtpClient, patterns)},
	{"linkp", "Ljava/util/regex/Pattern;", nullptr, $PRIVATE | $STATIC, $staticField(FtpClient, linkp)},
	{"df", "Ljava/text/DateFormat;", nullptr, $PRIVATE, $field(FtpClient, df)},
	{"acceptPasvAddressVal", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(FtpClient, acceptPasvAddressVal)},
	{"parser", "Lsun/net/ftp/FtpDirParser;", nullptr, $PRIVATE, $field(FtpClient, parser)},
	{"mlsxParser", "Lsun/net/ftp/FtpDirParser;", nullptr, $PRIVATE, $field(FtpClient, mlsxParser)},
	{"transPat", "Ljava/util/regex/Pattern;", nullptr, $PRIVATE | $STATIC, $staticField(FtpClient, transPat)},
	{"epsvPat", "Ljava/util/regex/Pattern;", nullptr, $PRIVATE | $STATIC, $staticField(FtpClient, epsvPat)},
	{"pasvPat", "Ljava/util/regex/Pattern;", nullptr, $PRIVATE | $STATIC, $staticField(FtpClient, pasvPat)},
	{"ERROR_MSG", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(FtpClient, ERROR_MSG)},
	{"RFC3659_DATETIME_FORMAT", "Ljava/time/format/DateTimeFormatter;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(FtpClient, RFC3659_DATETIME_FORMAT)},
	{}
};

$MethodInfo _FtpClient_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PROTECTED, $method(FtpClient, init$, void)},
	{"abort", "()Lsun/net/ftp/FtpClient;", nullptr, $PUBLIC, $virtualMethod(FtpClient, abort, $FtpClient*), "sun.net.ftp.FtpProtocolException,java.io.IOException"},
	{"allocate", "(J)Lsun/net/ftp/FtpClient;", nullptr, $PUBLIC, $virtualMethod(FtpClient, allocate, $FtpClient*, int64_t), "sun.net.ftp.FtpProtocolException,java.io.IOException"},
	{"appendFile", "(Ljava/lang/String;Ljava/io/InputStream;)Lsun/net/ftp/FtpClient;", nullptr, $PUBLIC, $virtualMethod(FtpClient, appendFile, $FtpClient*, $String*, $InputStream*), "sun.net.ftp.FtpProtocolException,java.io.IOException"},
	{"changeDirectory", "(Ljava/lang/String;)Lsun/net/ftp/FtpClient;", nullptr, $PUBLIC, $virtualMethod(FtpClient, changeDirectory, $FtpClient*, $String*), "sun.net.ftp.FtpProtocolException,java.io.IOException"},
	{"changeToParentDirectory", "()Lsun/net/ftp/FtpClient;", nullptr, $PUBLIC, $virtualMethod(FtpClient, changeToParentDirectory, $FtpClient*), "sun.net.ftp.FtpProtocolException,java.io.IOException"},
	{"close", "()V", nullptr, $PUBLIC, $virtualMethod(FtpClient, close, void), "java.io.IOException"},
	{"completePending", "()Lsun/net/ftp/FtpClient;", nullptr, $PUBLIC, $virtualMethod(FtpClient, completePending, $FtpClient*), "sun.net.ftp.FtpProtocolException,java.io.IOException"},
	{"connect", "(Ljava/net/SocketAddress;)Lsun/net/ftp/FtpClient;", nullptr, $PUBLIC, $virtualMethod(FtpClient, connect, $FtpClient*, $SocketAddress*), "sun.net.ftp.FtpProtocolException,java.io.IOException"},
	{"connect", "(Ljava/net/SocketAddress;I)Lsun/net/ftp/FtpClient;", nullptr, $PUBLIC, $virtualMethod(FtpClient, connect, $FtpClient*, $SocketAddress*, int32_t), "sun.net.ftp.FtpProtocolException,java.io.IOException"},
	{"create", "()Lsun/net/ftp/FtpClient;", nullptr, $PUBLIC | $STATIC, $staticMethod(FtpClient, create, $FtpClient*)},
	{"createInputStream", "(Ljava/io/InputStream;)Ljava/io/InputStream;", nullptr, $PRIVATE, $method(FtpClient, createInputStream, $InputStream*, $InputStream*)},
	{"createOutputStream", "(Ljava/io/OutputStream;)Ljava/io/OutputStream;", nullptr, $PRIVATE, $method(FtpClient, createOutputStream, $OutputStream*, $OutputStream*)},
	{"deleteFile", "(Ljava/lang/String;)Lsun/net/ftp/FtpClient;", nullptr, $PUBLIC, $virtualMethod(FtpClient, deleteFile, $FtpClient*, $String*), "sun.net.ftp.FtpProtocolException,java.io.IOException"},
	{"disconnect", "()V", nullptr, $PRIVATE, $method(FtpClient, disconnect, void), "java.io.IOException"},
	{"doConnect", "(Ljava/net/InetSocketAddress;I)Ljava/net/Socket;", nullptr, $PRIVATE, $method(FtpClient, doConnect, $Socket*, $InetSocketAddress*, int32_t), "java.io.IOException"},
	{"enablePassiveMode", "(Z)Lsun/net/ftp/FtpClient;", nullptr, $PUBLIC, $virtualMethod(FtpClient, enablePassiveMode, $FtpClient*, bool)},
	{"endSecureSession", "()Lsun/net/ftp/FtpClient;", nullptr, $PUBLIC, $virtualMethod(FtpClient, endSecureSession, $FtpClient*), "sun.net.ftp.FtpProtocolException,java.io.IOException"},
	{"getConnectTimeout", "()I", nullptr, $PUBLIC, $virtualMethod(FtpClient, getConnectTimeout, int32_t)},
	{"getFeatures", "()Ljava/util/List;", "()Ljava/util/List<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(FtpClient, getFeatures, $List*), "sun.net.ftp.FtpProtocolException,java.io.IOException"},
	{"getFile", "(Ljava/lang/String;Ljava/io/OutputStream;)Lsun/net/ftp/FtpClient;", nullptr, $PUBLIC, $virtualMethod(FtpClient, getFile, $FtpClient*, $String*, $OutputStream*), "sun.net.ftp.FtpProtocolException,java.io.IOException"},
	{"getFileStream", "(Ljava/lang/String;)Ljava/io/InputStream;", nullptr, $PUBLIC, $virtualMethod(FtpClient, getFileStream, $InputStream*, $String*), "sun.net.ftp.FtpProtocolException,java.io.IOException"},
	{"getHelp", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(FtpClient, getHelp, $String*, $String*), "sun.net.ftp.FtpProtocolException,java.io.IOException"},
	{"getLastFileName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(FtpClient, getLastFileName, $String*)},
	{"getLastModified", "(Ljava/lang/String;)Ljava/util/Date;", nullptr, $PUBLIC, $virtualMethod(FtpClient, getLastModified, $Date*, $String*), "sun.net.ftp.FtpProtocolException,java.io.IOException"},
	{"getLastReplyCode", "()Lsun/net/ftp/FtpReplyCode;", nullptr, $PUBLIC, $virtualMethod(FtpClient, getLastReplyCode, $FtpReplyCode*)},
	{"getLastResponseString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(FtpClient, getLastResponseString, $String*)},
	{"getLastTransferSize", "()J", nullptr, $PUBLIC, $virtualMethod(FtpClient, getLastTransferSize, int64_t)},
	{"getProxy", "()Ljava/net/Proxy;", nullptr, $PUBLIC, $virtualMethod(FtpClient, getProxy, $Proxy*)},
	{"getReadTimeout", "()I", nullptr, $PUBLIC, $virtualMethod(FtpClient, getReadTimeout, int32_t)},
	{"getResponseString", "()Ljava/lang/String;", nullptr, $PRIVATE, $method(FtpClient, getResponseString, $String*)},
	{"getResponseStrings", "()Ljava/util/Vector;", "()Ljava/util/Vector<Ljava/lang/String;>;", $PRIVATE, $method(FtpClient, getResponseStrings, $Vector*)},
	{"getSecurityData", "()[B", nullptr, $PRIVATE, $method(FtpClient, getSecurityData, $bytes*)},
	{"getServerAddress", "()Ljava/net/SocketAddress;", nullptr, $PUBLIC, $virtualMethod(FtpClient, getServerAddress, $SocketAddress*)},
	{"getSize", "(Ljava/lang/String;)J", nullptr, $PUBLIC, $virtualMethod(FtpClient, getSize, int64_t, $String*), "sun.net.ftp.FtpProtocolException,java.io.IOException"},
	{"getStatus", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(FtpClient, getStatus, $String*, $String*), "sun.net.ftp.FtpProtocolException,java.io.IOException"},
	{"getSystem", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(FtpClient, getSystem, $String*), "sun.net.ftp.FtpProtocolException,java.io.IOException"},
	{"getTransferName", "()V", nullptr, $PRIVATE, $method(FtpClient, getTransferName, void)},
	{"getTransferSize", "()V", nullptr, $PRIVATE, $method(FtpClient, getTransferSize, void)},
	{"getWelcomeMsg", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(FtpClient, getWelcomeMsg, $String*)},
	{"getWorkingDirectory", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(FtpClient, getWorkingDirectory, $String*), "sun.net.ftp.FtpProtocolException,java.io.IOException"},
	{"isASCIISuperset", "(Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(FtpClient, isASCIISuperset, bool, $String*), "java.lang.Exception"},
	{"isConnected", "()Z", nullptr, $PUBLIC, $virtualMethod(FtpClient, isConnected, bool)},
	{"isLoggedIn", "()Z", nullptr, $PUBLIC, $virtualMethod(FtpClient, isLoggedIn, bool)},
	{"isPassiveModeEnabled", "()Z", nullptr, $PUBLIC, $virtualMethod(FtpClient, isPassiveModeEnabled, bool)},
	{"issueCommand", "(Ljava/lang/String;)Z", nullptr, $PRIVATE, $method(FtpClient, issueCommand, bool, $String*), "java.io.IOException,sun.net.ftp.FtpProtocolException"},
	{"issueCommandCheck", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(FtpClient, issueCommandCheck, void, $String*), "sun.net.ftp.FtpProtocolException,java.io.IOException"},
	{"lambda$openPassiveDataConnection$0", "()Ljava/net/Socket;", nullptr, $PRIVATE | $SYNTHETIC, $method(FtpClient, lambda$openPassiveDataConnection$0, $Socket*)},
	{"lambda$openPassiveDataConnection$1", "()Ljava/net/InetAddress;", nullptr, $PRIVATE | $SYNTHETIC, $method(FtpClient, lambda$openPassiveDataConnection$1, $InetAddress*)},
	{"lambda$privilegedGetAllByName$2", "(Ljava/lang/String;)[Ljava/net/InetAddress;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(FtpClient, lambda$privilegedGetAllByName$2, $InetAddressArray*, $String*), "java.lang.Exception"},
	{"list", "(Ljava/lang/String;)Ljava/io/InputStream;", nullptr, $PUBLIC, $virtualMethod(FtpClient, list, $InputStream*, $String*), "sun.net.ftp.FtpProtocolException,java.io.IOException"},
	{"listFiles", "(Ljava/lang/String;)Ljava/util/Iterator;", "(Ljava/lang/String;)Ljava/util/Iterator<Lsun/net/ftp/FtpDirEntry;>;", $PUBLIC, $virtualMethod(FtpClient, listFiles, $Iterator*, $String*), "sun.net.ftp.FtpProtocolException,java.io.IOException"},
	{"login", "(Ljava/lang/String;[C)Lsun/net/ftp/FtpClient;", nullptr, $PUBLIC, $virtualMethod(FtpClient, login, $FtpClient*, $String*, $chars*), "sun.net.ftp.FtpProtocolException,java.io.IOException"},
	{"login", "(Ljava/lang/String;[CLjava/lang/String;)Lsun/net/ftp/FtpClient;", nullptr, $PUBLIC, $virtualMethod(FtpClient, login, $FtpClient*, $String*, $chars*, $String*), "sun.net.ftp.FtpProtocolException,java.io.IOException"},
	{"makeDirectory", "(Ljava/lang/String;)Lsun/net/ftp/FtpClient;", nullptr, $PUBLIC, $virtualMethod(FtpClient, makeDirectory, $FtpClient*, $String*), "sun.net.ftp.FtpProtocolException,java.io.IOException"},
	{"nameList", "(Ljava/lang/String;)Ljava/io/InputStream;", nullptr, $PUBLIC, $virtualMethod(FtpClient, nameList, $InputStream*, $String*), "sun.net.ftp.FtpProtocolException,java.io.IOException"},
	{"noop", "()Lsun/net/ftp/FtpClient;", nullptr, $PUBLIC, $virtualMethod(FtpClient, noop, $FtpClient*), "sun.net.ftp.FtpProtocolException,java.io.IOException"},
	{"openDataConnection", "(Ljava/lang/String;)Ljava/net/Socket;", nullptr, $PRIVATE, $method(FtpClient, openDataConnection, $Socket*, $String*), "sun.net.ftp.FtpProtocolException,java.io.IOException"},
	{"openPassiveDataConnection", "(Ljava/lang/String;)Ljava/net/Socket;", nullptr, $PRIVATE, $method(FtpClient, openPassiveDataConnection, $Socket*, $String*), "sun.net.ftp.FtpProtocolException,java.io.IOException"},
	{"parseRfc3659TimeValue", "(Ljava/lang/String;)Ljava/util/Date;", nullptr, $PRIVATE | $STATIC, $staticMethod(FtpClient, parseRfc3659TimeValue, $Date*, $String*)},
	{"privilegedGetAllByName", "(Ljava/lang/String;)[Ljava/net/InetAddress;", nullptr, $PRIVATE | $STATIC, $staticMethod(FtpClient, privilegedGetAllByName, $InetAddressArray*, $String*), "sun.net.ftp.FtpProtocolException"},
	{"privilegedLocalHost", "()Ljava/net/InetAddress;", nullptr, $PRIVATE | $STATIC, $staticMethod(FtpClient, privilegedLocalHost, $InetAddress*), "sun.net.ftp.FtpProtocolException"},
	{"putFile", "(Ljava/lang/String;Ljava/io/InputStream;Z)Lsun/net/ftp/FtpClient;", nullptr, $PUBLIC, $virtualMethod(FtpClient, putFile, $FtpClient*, $String*, $InputStream*, bool), "sun.net.ftp.FtpProtocolException,java.io.IOException"},
	{"putFileStream", "(Ljava/lang/String;Z)Ljava/io/OutputStream;", nullptr, $PUBLIC, $virtualMethod(FtpClient, putFileStream, $OutputStream*, $String*, bool), "sun.net.ftp.FtpProtocolException,java.io.IOException"},
	{"reInit", "()Lsun/net/ftp/FtpClient;", nullptr, $PUBLIC, $virtualMethod(FtpClient, reInit, $FtpClient*), "sun.net.ftp.FtpProtocolException,java.io.IOException"},
	{"readReply", "()Z", nullptr, $PRIVATE, $method(FtpClient, readReply, bool), "java.io.IOException"},
	{"readServerResponse", "()I", nullptr, $PRIVATE, $method(FtpClient, readServerResponse, int32_t), "java.io.IOException"},
	{"removeDirectory", "(Ljava/lang/String;)Lsun/net/ftp/FtpClient;", nullptr, $PUBLIC, $virtualMethod(FtpClient, removeDirectory, $FtpClient*, $String*), "sun.net.ftp.FtpProtocolException,java.io.IOException"},
	{"rename", "(Ljava/lang/String;Ljava/lang/String;)Lsun/net/ftp/FtpClient;", nullptr, $PUBLIC, $virtualMethod(FtpClient, rename, $FtpClient*, $String*, $String*), "sun.net.ftp.FtpProtocolException,java.io.IOException"},
	{"sendSecurityData", "([B)Z", nullptr, $PRIVATE, $method(FtpClient, sendSecurityData, bool, $bytes*), "java.io.IOException,sun.net.ftp.FtpProtocolException"},
	{"sendServer", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(FtpClient, sendServer, void, $String*)},
	{"setConnectTimeout", "(I)Lsun/net/ftp/FtpClient;", nullptr, $PUBLIC, $virtualMethod(FtpClient, setConnectTimeout, $FtpClient*, int32_t)},
	{"setDirParser", "(Lsun/net/ftp/FtpDirParser;)Lsun/net/ftp/FtpClient;", nullptr, $PUBLIC, $virtualMethod(FtpClient, setDirParser, $FtpClient*, $FtpDirParser*)},
	{"setProxy", "(Ljava/net/Proxy;)Lsun/net/ftp/FtpClient;", nullptr, $PUBLIC, $virtualMethod(FtpClient, setProxy, $FtpClient*, $Proxy*)},
	{"setReadTimeout", "(I)Lsun/net/ftp/FtpClient;", nullptr, $PUBLIC, $virtualMethod(FtpClient, setReadTimeout, $FtpClient*, int32_t)},
	{"setRestartOffset", "(J)Lsun/net/ftp/FtpClient;", nullptr, $PUBLIC, $virtualMethod(FtpClient, setRestartOffset, $FtpClient*, int64_t)},
	{"setType", "(Lsun/net/ftp/FtpClient$TransferType;)Lsun/net/ftp/FtpClient;", nullptr, $PUBLIC, $virtualMethod(FtpClient, setType, $FtpClient*, $FtpClient$TransferType*), "sun.net.ftp.FtpProtocolException,java.io.IOException"},
	{"siteCmd", "(Ljava/lang/String;)Lsun/net/ftp/FtpClient;", nullptr, $PUBLIC, $virtualMethod(FtpClient, siteCmd, $FtpClient*, $String*), "sun.net.ftp.FtpProtocolException,java.io.IOException"},
	{"startSecureSession", "()Lsun/net/ftp/FtpClient;", nullptr, $PUBLIC, $virtualMethod(FtpClient, startSecureSession, $FtpClient*), "sun.net.ftp.FtpProtocolException,java.io.IOException"},
	{"structureMount", "(Ljava/lang/String;)Lsun/net/ftp/FtpClient;", nullptr, $PUBLIC, $virtualMethod(FtpClient, structureMount, $FtpClient*, $String*), "sun.net.ftp.FtpProtocolException,java.io.IOException"},
	{"tryConnect", "(Ljava/net/InetSocketAddress;I)V", nullptr, $PRIVATE, $method(FtpClient, tryConnect, void, $InetSocketAddress*, int32_t), "java.io.IOException"},
	{"tryLogin", "(Ljava/lang/String;[C)V", nullptr, $PRIVATE, $method(FtpClient, tryLogin, void, $String*, $chars*), "sun.net.ftp.FtpProtocolException,java.io.IOException"},
	{"useKerberos", "()Lsun/net/ftp/FtpClient;", nullptr, $PUBLIC, $virtualMethod(FtpClient, useKerberos, $FtpClient*), "sun.net.ftp.FtpProtocolException,java.io.IOException"},
	{"validatePasvAddress", "(ILjava/lang/String;Ljava/net/InetAddress;)Ljava/net/InetSocketAddress;", nullptr, $PRIVATE, $method(FtpClient, validatePasvAddress, $InetSocketAddress*, int32_t, $String*, $InetAddress*), "sun.net.ftp.FtpProtocolException"},
	{}
};

$InnerClassInfo _FtpClient_InnerClassesInfo_[] = {
	{"sun.net.ftp.impl.FtpClient$FtpFileIterator", "sun.net.ftp.impl.FtpClient", "FtpFileIterator", $PRIVATE | $STATIC},
	{"sun.net.ftp.impl.FtpClient$MLSxParser", "sun.net.ftp.impl.FtpClient", "MLSxParser", $PRIVATE | $STATIC},
	{"sun.net.ftp.impl.FtpClient$DefaultParser", "sun.net.ftp.impl.FtpClient", "DefaultParser", $PRIVATE},
	{"sun.net.ftp.impl.FtpClient$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _FtpClient_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.net.ftp.impl.FtpClient",
	"sun.net.ftp.FtpClient",
	nullptr,
	_FtpClient_FieldInfo_,
	_FtpClient_MethodInfo_,
	nullptr,
	nullptr,
	_FtpClient_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.net.ftp.impl.FtpClient$FtpFileIterator,sun.net.ftp.impl.FtpClient$MLSxParser,sun.net.ftp.impl.FtpClient$DefaultParser,sun.net.ftp.impl.FtpClient$1"
};

$Object* allocate$FtpClient($Class* clazz) {
	return $of($alloc(FtpClient));
}

int32_t FtpClient::defaultSoTimeout = 0;
int32_t FtpClient::defaultConnectTimeout = 0;
$PlatformLogger* FtpClient::logger = nullptr;
$String* FtpClient::encoding = nullptr;
$StringArray* FtpClient::patStrings = nullptr;
$intArray2* FtpClient::patternGroups = nullptr;
$PatternArray* FtpClient::patterns = nullptr;
$Pattern* FtpClient::linkp = nullptr;
bool FtpClient::acceptPasvAddressVal = false;
$Pattern* FtpClient::transPat = nullptr;
$Pattern* FtpClient::epsvPat = nullptr;
$Pattern* FtpClient::pasvPat = nullptr;
$String* FtpClient::ERROR_MSG = nullptr;
$DateTimeFormatter* FtpClient::RFC3659_DATETIME_FORMAT = nullptr;

bool FtpClient::isASCIISuperset($String* encoding) {
	$init(FtpClient);
	$useLocalCurrentObjectStackCache();
	$var($String, chkS, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz-_.!~*\'();/?:@&=+$,"_s);
	$var($bytes, chkB, $new($bytes, {
		(int8_t)48,
		(int8_t)49,
		(int8_t)50,
		(int8_t)51,
		(int8_t)52,
		(int8_t)53,
		(int8_t)54,
		(int8_t)55,
		(int8_t)56,
		(int8_t)57,
		(int8_t)65,
		(int8_t)66,
		(int8_t)67,
		(int8_t)68,
		(int8_t)69,
		(int8_t)70,
		(int8_t)71,
		(int8_t)72,
		(int8_t)73,
		(int8_t)74,
		(int8_t)75,
		(int8_t)76,
		(int8_t)77,
		(int8_t)78,
		(int8_t)79,
		(int8_t)80,
		(int8_t)81,
		(int8_t)82,
		(int8_t)83,
		(int8_t)84,
		(int8_t)85,
		(int8_t)86,
		(int8_t)87,
		(int8_t)88,
		(int8_t)89,
		(int8_t)90,
		(int8_t)97,
		(int8_t)98,
		(int8_t)99,
		(int8_t)100,
		(int8_t)101,
		(int8_t)102,
		(int8_t)103,
		(int8_t)104,
		(int8_t)105,
		(int8_t)106,
		(int8_t)107,
		(int8_t)108,
		(int8_t)109,
		(int8_t)110,
		(int8_t)111,
		(int8_t)112,
		(int8_t)113,
		(int8_t)114,
		(int8_t)115,
		(int8_t)116,
		(int8_t)117,
		(int8_t)118,
		(int8_t)119,
		(int8_t)120,
		(int8_t)121,
		(int8_t)122,
		(int8_t)45,
		(int8_t)95,
		(int8_t)46,
		(int8_t)33,
		(int8_t)126,
		(int8_t)42,
		(int8_t)39,
		(int8_t)40,
		(int8_t)41,
		(int8_t)59,
		(int8_t)47,
		(int8_t)63,
		(int8_t)58,
		(int8_t)64,
		(int8_t)38,
		(int8_t)61,
		(int8_t)43,
		(int8_t)36,
		(int8_t)44
	}));
	$var($bytes, b, chkS->getBytes(encoding));
	return $Arrays::equals(b, chkB);
}

void FtpClient::getTransferSize() {
	$useLocalCurrentObjectStackCache();
	this->lastTransSize = -1;
	$var($String, response, getLastResponseString());
	if (FtpClient::transPat == nullptr) {
		$assignStatic(FtpClient::transPat, $Pattern::compile("150 Opening .*\\((\\d+) bytes\\)."_s));
	}
	$var($Matcher, m, $nc(FtpClient::transPat)->matcher(response));
	if ($nc(m)->find()) {
		$var($String, s, m->group(1));
		this->lastTransSize = $Long::parseLong(s);
	}
}

void FtpClient::getTransferName() {
	$set(this, lastFileName, nullptr);
	$var($String, response, getLastResponseString());
	int32_t i = $nc(response)->indexOf("unique file name:"_s);
	int32_t e = response->lastIndexOf((int32_t)u')');
	if (i >= 0) {
		i += 17;
		$set(this, lastFileName, response->substring(i, e));
	}
}

int32_t FtpClient::readServerResponse() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, replyBuf, $new($StringBuilder, 32));
	int32_t c = 0;
	int32_t continuingCode = -1;
	int32_t code = 0;
	$var($String, response, nullptr);
	$nc(this->serverResponse)->setSize(0);
	while (true) {
		while ((c = $nc(this->in)->read()) != -1) {
			if (c == u'\r') {
				if ((c = $nc(this->in)->read()) != u'\n') {
					replyBuf->append(u'\r');
				}
			}
			replyBuf->append((char16_t)c);
			if (c == u'\n') {
				break;
			}
		}
		$assign(response, replyBuf->toString());
		replyBuf->setLength(0);
		$init($PlatformLogger$Level);
		if ($nc(FtpClient::logger)->isLoggable($PlatformLogger$Level::FINEST)) {
			$nc(FtpClient::logger)->finest($$str({"Server ["_s, this->serverAddr, "] --> "_s, response}));
		}
		if ($nc(response)->isEmpty()) {
			code = -1;
		} else {
			try {
				code = $Integer::parseInt(response, 0, 3, 10);
			} catch ($NumberFormatException& e) {
				code = -1;
			} catch ($IndexOutOfBoundsException& e) {
				continue;
			}
		}
		$nc(this->serverResponse)->addElement(response);
		if (continuingCode != -1) {
			bool var$0 = code != continuingCode;
			if (!var$0) {
				bool var$1 = $nc(response)->length() >= 4;
				var$0 = (var$1 && response->charAt(3) == u'-');
			}
			if (var$0) {
				continue;
			} else {
				continuingCode = -1;
				break;
			}
		} else {
			bool var$3 = $nc(response)->length() >= 4;
			if (var$3 && response->charAt(3) == u'-') {
				continuingCode = code;
				continue;
			} else {
				break;
			}
		}
	}
	return code;
}

void FtpClient::sendServer($String* cmd) {
	$nc(this->out)->print(cmd);
	$init($PlatformLogger$Level);
	if ($nc(FtpClient::logger)->isLoggable($PlatformLogger$Level::FINEST)) {
		$nc(FtpClient::logger)->finest($$str({"Server ["_s, this->serverAddr, "] <-- "_s, cmd}));
	}
}

$String* FtpClient::getResponseString() {
	return $cast($String, $nc(this->serverResponse)->elementAt(0));
}

$Vector* FtpClient::getResponseStrings() {
	return this->serverResponse;
}

bool FtpClient::readReply() {
	$set(this, lastReplyCode, $FtpReplyCode::find(readServerResponse()));
	if ($nc(this->lastReplyCode)->isPositivePreliminary()) {
		this->replyPending = true;
		return true;
	}
	bool var$0 = $nc(this->lastReplyCode)->isPositiveCompletion();
	if (var$0 || $nc(this->lastReplyCode)->isPositiveIntermediate()) {
		if (this->lastReplyCode == $FtpReplyCode::CLOSING_DATA_CONNECTION) {
			getTransferName();
		}
		return true;
	}
	return false;
}

bool FtpClient::issueCommand($String* cmd) {
	$useLocalCurrentObjectStackCache();
	if (!isConnected()) {
		$throwNew($IllegalStateException, "Not connected"_s);
	}
	if (this->replyPending) {
		try {
			completePending();
		} catch ($FtpProtocolException& e) {
		}
	}
	if ($nc(cmd)->indexOf((int32_t)u'\n') != -1) {
		$var($FtpProtocolException, ex, $new($FtpProtocolException, "Illegal FTP command"_s));
		ex->initCause($$new($IllegalArgumentException, "Illegal carriage return"_s));
		$throw(ex);
	}
	sendServer($$str({cmd, "\r\n"_s}));
	return readReply();
}

void FtpClient::issueCommandCheck($String* cmd) {
	$useLocalCurrentObjectStackCache();
	if (!issueCommand(cmd)) {
		$var($String, var$0, $str({cmd, ":"_s, $(getResponseString())}));
		$throwNew($FtpProtocolException, var$0, $(getLastReplyCode()));
	}
}

$Socket* FtpClient::openPassiveDataConnection($String* cmd) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($String, serverAnswer, nullptr);
	int32_t port = 0;
	$var($InetSocketAddress, dest, nullptr);
	if (issueCommand("EPSV ALL"_s)) {
		issueCommandCheck("EPSV"_s);
		$assign(serverAnswer, getResponseString());
		if (FtpClient::epsvPat == nullptr) {
			$assignStatic(FtpClient::epsvPat, $Pattern::compile("^229 .* \\(\\|\\|\\|(\\d+)\\|\\)"_s));
		}
		$var($Matcher, m, $nc(FtpClient::epsvPat)->matcher(serverAnswer));
		if (!$nc(m)->find()) {
			$throwNew($FtpProtocolException, $$str({"EPSV failed : "_s, serverAnswer}));
		}
		$var($String, s, $nc(m)->group(1));
		port = $Integer::parseInt(s);
		$var($InetAddress, add, $nc(this->server)->getInetAddress());
		if (add != nullptr) {
			$assign(dest, $new($InetSocketAddress, add, port));
		} else {
			$assign(dest, $InetSocketAddress::createUnresolved($($nc(this->serverAddr)->getHostName()), port));
		}
	} else {
		issueCommandCheck("PASV"_s);
		$assign(serverAnswer, getResponseString());
		if (FtpClient::pasvPat == nullptr) {
			$assignStatic(FtpClient::pasvPat, $Pattern::compile("227 .* \\(?(\\d{1,3},\\d{1,3},\\d{1,3},\\d{1,3}),(\\d{1,3}),(\\d{1,3})\\)?"_s));
		}
		$var($Matcher, m, $nc(FtpClient::pasvPat)->matcher(serverAnswer));
		if (!$nc(m)->find()) {
			$throwNew($FtpProtocolException, $$str({"PASV failed : "_s, serverAnswer}));
		}
		int32_t var$0 = $Integer::parseInt($($nc(m)->group(3)));
		port = var$0 + ($Integer::parseInt($($nc(m)->group(2))) << 8);
		$var($String, s, $nc($($nc(m)->group(1)))->replace(u',', u'.'));
		if (!$IPAddressUtil::isIPv4LiteralAddress(s)) {
			$throwNew($FtpProtocolException, $$str({"PASV failed : "_s, serverAnswer}));
		}
		if (FtpClient::acceptPasvAddressVal) {
			$assign(dest, $new($InetSocketAddress, s, port));
		} else {
			$assign(dest, validatePasvAddress(port, s, $($nc(this->server)->getInetAddress())));
		}
	}
	$var($Socket, s, nullptr);
	if (this->proxy != nullptr) {
		$init($Proxy$Type);
		if ($nc(this->proxy)->type() == $Proxy$Type::SOCKS) {
			$var($PrivilegedAction, pa, static_cast<$PrivilegedAction*>($new(FtpClient$$Lambda$lambda$openPassiveDataConnection$0, this)));
			$var($Socket, tmp, $cast($Socket, $AccessController::doPrivileged(pa)));
			$assign(s, tmp);
		} else {
			$init($Proxy);
			$assign(s, $new($Socket, $Proxy::NO_PROXY));
		}
	} else {
		$assign(s, $new($Socket));
	}
	$var($PrivilegedAction, pa, static_cast<$PrivilegedAction*>($new(FtpClient$$Lambda$lambda$openPassiveDataConnection$1$1, this)));
	$var($InetAddress, serverAddress, $cast($InetAddress, $AccessController::doPrivileged(pa)));
	$nc(s)->bind($$new($InetSocketAddress, serverAddress, 0));
	if (this->connectTimeout >= 0) {
		s->connect(dest, this->connectTimeout);
	} else if (FtpClient::defaultConnectTimeout > 0) {
		s->connect(dest, FtpClient::defaultConnectTimeout);
	} else {
		s->connect(dest);
	}
	if (this->readTimeout >= 0) {
		s->setSoTimeout(this->readTimeout);
	} else if (FtpClient::defaultSoTimeout > 0) {
		s->setSoTimeout(FtpClient::defaultSoTimeout);
	}
	if (this->useCrypto) {
		try {
			$var($Socket, var$1, s);
			$var($String, var$2, $nc(dest)->getHostName());
			$assign(s, $nc(this->sslFact)->createSocket(var$1, var$2, dest->getPort(), true));
		} catch ($Exception& e) {
			$throwNew($FtpProtocolException, $$str({"Can\'t open secure data channel: "_s, e}));
		}
	}
	if (!issueCommand(cmd)) {
		s->close();
		$init($FtpReplyCode);
		if (getLastReplyCode() == $FtpReplyCode::FILE_UNAVAILABLE) {
			$throwNew($FileNotFoundException, cmd);
		}
		$var($String, var$3, $str({cmd, ":"_s, $(getResponseString())}));
		$throwNew($FtpProtocolException, var$3, $(getLastReplyCode()));
	}
	return s;
}

$InetSocketAddress* FtpClient::validatePasvAddress(int32_t port, $String* s, $InetAddress* address) {
	$useLocalCurrentObjectStackCache();
	if (address == nullptr) {
		return $InetSocketAddress::createUnresolved($($nc(this->serverAddr)->getHostName()), port);
	}
	$var($String, serverAddress, $nc(address)->getHostAddress());
	if ($nc(serverAddress)->equals(s)) {
		return $new($InetSocketAddress, s, port);
	} else {
		bool var$1 = address->isLoopbackAddress();
		if (var$1 && $nc(s)->startsWith("127."_s)) {
			return $new($InetSocketAddress, s, port);
		} else if (address->isLoopbackAddress()) {
			if ($nc($($nc($(privilegedLocalHost()))->getHostAddress()))->equals(s)) {
				return $new($InetSocketAddress, s, port);
			} else {
				$throwNew($FtpProtocolException, FtpClient::ERROR_MSG);
			}
		} else if (s->startsWith("127."_s)) {
			if ($nc($(privilegedLocalHost()))->equals(address)) {
				return $new($InetSocketAddress, s, port);
			} else {
				$throwNew($FtpProtocolException, FtpClient::ERROR_MSG);
			}
		}
	}
	$var($String, hostName, address->getHostName());
	bool var$2 = $IPAddressUtil::isIPv4LiteralAddress(hostName);
	if (!(var$2 || $IPAddressUtil::isIPv6LiteralAddress(hostName))) {
		$var($InetAddressArray, names, privilegedGetAllByName(hostName));
		$var($String, resAddress, $cast($String, $nc($($nc($($nc($($nc($($Arrays::stream(names)))->map(static_cast<$Function*>($$new(FtpClient$$Lambda$getHostAddress$2)))))->filter(static_cast<$Predicate*>($$new(FtpClient$$Lambda$equalsIgnoreCase$3, static_cast<$String*>($nc(s)))))))->findFirst()))->orElse(nullptr)));
		if (resAddress != nullptr) {
			return $new($InetSocketAddress, s, port);
		}
	}
	$throwNew($FtpProtocolException, FtpClient::ERROR_MSG);
}

$InetAddress* FtpClient::privilegedLocalHost() {
	$init(FtpClient);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($PrivilegedExceptionAction, action, static_cast<$PrivilegedExceptionAction*>($new(FtpClient$$Lambda$getLocalHost$4)));
	try {
		$var($InetAddress, tmp, $cast($InetAddress, $AccessController::doPrivileged(action)));
		return tmp;
	} catch ($Exception& e) {
		$var($FtpProtocolException, ftpEx, $new($FtpProtocolException, FtpClient::ERROR_MSG));
		ftpEx->initCause(e);
		$throw(ftpEx);
	}
	$shouldNotReachHere();
}

$InetAddressArray* FtpClient::privilegedGetAllByName($String* hostName) {
	$init(FtpClient);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($PrivilegedExceptionAction, pAction, static_cast<$PrivilegedExceptionAction*>($new(FtpClient$$Lambda$lambda$privilegedGetAllByName$2$5, hostName)));
	try {
		$var($InetAddressArray, tmp, $cast($InetAddressArray, $AccessController::doPrivileged(pAction)));
		return tmp;
	} catch ($Exception& e) {
		$var($FtpProtocolException, ftpEx, $new($FtpProtocolException, FtpClient::ERROR_MSG));
		ftpEx->initCause(e);
		$throw(ftpEx);
	}
	$shouldNotReachHere();
}

$Socket* FtpClient::openDataConnection($String* cmd) {
	$useLocalCurrentObjectStackCache();
	$var($Socket, clientSocket, nullptr);
	{
		try {
			return openPassiveDataConnection(cmd);
		} catch ($FtpProtocolException& e) {
			$var($String, errmsg, e->getMessage());
			bool var$0 = !$nc(errmsg)->startsWith("PASV"_s);
			if (var$0 && !errmsg->startsWith("EPSV"_s)) {
				$throw(e);
			}
		}
	}
	$var($ServerSocket, portSocket, nullptr);
	$var($InetAddress, myAddress, nullptr);
	$var($String, portCmd, nullptr);
	$init($Proxy$Type);
	if (this->proxy != nullptr && $nc(this->proxy)->type() == $Proxy$Type::SOCKS) {
		$throwNew($FtpProtocolException, "Passive mode failed"_s);
	}
	$assign(portSocket, $new($ServerSocket, 0, 1, $($nc(this->server)->getLocalAddress())));
	{
		$var($Throwable, var$1, nullptr);
		try {
			$assign(myAddress, portSocket->getInetAddress());
			if ($nc(myAddress)->isAnyLocalAddress()) {
				$assign(myAddress, $nc(this->server)->getLocalAddress());
			}
			$var($String, var$3, $$str({"EPRT |"_s, (($instanceOf($Inet6Address, myAddress)) ? "2"_s : "1"_s), "|"_s, $($nc(myAddress)->getHostAddress()), "|"_s}));
			$var($String, var$2, $$concat(var$3, $$str(portSocket->getLocalPort())));
			$assign(portCmd, $concat(var$2, "|"_s));
			bool var$4 = !issueCommand(portCmd);
			if (var$4 || !issueCommand(cmd)) {
				$assign(portCmd, "PORT "_s);
				$var($bytes, addr, myAddress->getAddress());
				for (int32_t i = 0; i < $nc(addr)->length; ++i) {
					$assign(portCmd, $str({portCmd, $$str(((int32_t)(addr->get(i) & (uint32_t)255))), ","_s}));
				}
				$var($String, var$5, $$str({portCmd, $$str(((int32_t)(((int32_t)((uint32_t)portSocket->getLocalPort() >> 8)) & (uint32_t)255))), ","_s}));
				$assign(portCmd, $concat(var$5, $$str(((int32_t)(portSocket->getLocalPort() & (uint32_t)255)))));
				issueCommandCheck(portCmd);
				issueCommandCheck(cmd);
			}
			if (this->connectTimeout >= 0) {
				portSocket->setSoTimeout(this->connectTimeout);
			} else if (FtpClient::defaultConnectTimeout > 0) {
				portSocket->setSoTimeout(FtpClient::defaultConnectTimeout);
			}
			$assign(clientSocket, portSocket->accept());
			if (this->readTimeout >= 0) {
				$nc(clientSocket)->setSoTimeout(this->readTimeout);
			} else if (FtpClient::defaultSoTimeout > 0) {
				$nc(clientSocket)->setSoTimeout(FtpClient::defaultSoTimeout);
			}
		} catch ($Throwable& var$6) {
			$assign(var$1, var$6);
		} /*finally*/ {
			portSocket->close();
		}
		if (var$1 != nullptr) {
			$throw(var$1);
		}
	}
	if (this->useCrypto) {
		try {
			$var($Socket, var$7, clientSocket);
			$var($String, var$8, $nc(this->serverAddr)->getHostName());
			$assign(clientSocket, $nc(this->sslFact)->createSocket(var$7, var$8, $nc(this->serverAddr)->getPort(), true));
		} catch ($Exception& ex) {
			$throwNew($IOException, $(ex->getLocalizedMessage()));
		}
	}
	return clientSocket;
}

$InputStream* FtpClient::createInputStream($InputStream* in) {
	$init($FtpClient$TransferType);
	if (this->type == $FtpClient$TransferType::ASCII) {
		return $new($TelnetInputStream, in, false);
	}
	return in;
}

$OutputStream* FtpClient::createOutputStream($OutputStream* out) {
	$init($FtpClient$TransferType);
	if (this->type == $FtpClient$TransferType::ASCII) {
		return $new($TelnetOutputStream, out, false);
	}
	return out;
}

void FtpClient::init$() {
	$FtpClient::init$();
	this->readTimeout = -1;
	this->connectTimeout = -1;
	this->replyPending = false;
	this->loggedIn = false;
	this->useCrypto = false;
	$set(this, serverResponse, $new($Vector, 1));
	$set(this, lastReplyCode, nullptr);
	$init($FtpClient$TransferType);
	$set(this, type, $FtpClient$TransferType::BINARY);
	this->restartOffset = 0;
	this->lastTransSize = -1;
	$init($Locale);
	$set(this, df, $DateFormat::getDateInstance($DateFormat::MEDIUM, $Locale::US));
	$set(this, parser, $new($FtpClient$DefaultParser, this));
	$set(this, mlsxParser, $new($FtpClient$MLSxParser));
}

$FtpClient* FtpClient::create() {
	$init(FtpClient);
	return $new(FtpClient);
}

$FtpClient* FtpClient::enablePassiveMode(bool passive) {
	return this;
}

bool FtpClient::isPassiveModeEnabled() {
	return FtpClient::passiveMode;
}

$FtpClient* FtpClient::setConnectTimeout(int32_t timeout) {
	this->connectTimeout = timeout;
	return this;
}

int32_t FtpClient::getConnectTimeout() {
	return this->connectTimeout;
}

$FtpClient* FtpClient::setReadTimeout(int32_t timeout) {
	this->readTimeout = timeout;
	return this;
}

int32_t FtpClient::getReadTimeout() {
	return this->readTimeout;
}

$FtpClient* FtpClient::setProxy($Proxy* p) {
	$set(this, proxy, p);
	return this;
}

$Proxy* FtpClient::getProxy() {
	return this->proxy;
}

void FtpClient::tryConnect($InetSocketAddress* dest, int32_t timeout) {
	$useLocalCurrentObjectStackCache();
	if (isConnected()) {
		disconnect();
	}
	$set(this, server, doConnect(dest, timeout));
	try {
		$set(this, out, $new($PrintStream, static_cast<$OutputStream*>($$new($BufferedOutputStream, $($nc(this->server)->getOutputStream()))), true, FtpClient::encoding));
	} catch ($UnsupportedEncodingException& e) {
		$throwNew($InternalError, $$str({FtpClient::encoding, "encoding not found"_s}), e);
	}
	$set(this, in, $new($BufferedInputStream, $($nc(this->server)->getInputStream())));
}

$Socket* FtpClient::doConnect($InetSocketAddress* dest, int32_t timeout) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($Socket, s, nullptr);
	if (this->proxy != nullptr) {
		$init($Proxy$Type);
		if ($nc(this->proxy)->type() == $Proxy$Type::SOCKS) {
			$var($PrivilegedAction, pa, static_cast<$PrivilegedAction*>($new(FtpClient$$Lambda$lambda$openPassiveDataConnection$0, this)));
			$var($Socket, tmp, $cast($Socket, $AccessController::doPrivileged(pa)));
			$assign(s, tmp);
		} else {
			$init($Proxy);
			$assign(s, $new($Socket, $Proxy::NO_PROXY));
		}
	} else {
		$assign(s, $new($Socket));
	}
	if (timeout >= 0) {
		$nc(s)->connect(dest, timeout);
	} else if (this->connectTimeout >= 0) {
		$nc(s)->connect(dest, this->connectTimeout);
	} else if (FtpClient::defaultConnectTimeout > 0) {
		$nc(s)->connect(dest, FtpClient::defaultConnectTimeout);
	} else {
		$nc(s)->connect(dest);
	}
	if (this->readTimeout >= 0) {
		$nc(s)->setSoTimeout(this->readTimeout);
	} else if (FtpClient::defaultSoTimeout > 0) {
		$nc(s)->setSoTimeout(FtpClient::defaultSoTimeout);
	}
	return s;
}

void FtpClient::disconnect() {
	if (isConnected()) {
		$nc(this->server)->close();
	}
	$set(this, server, nullptr);
	$set(this, in, nullptr);
	$set(this, out, nullptr);
	this->lastTransSize = -1;
	$set(this, lastFileName, nullptr);
	this->restartOffset = 0;
	$set(this, welcomeMsg, nullptr);
	$set(this, lastReplyCode, nullptr);
	$nc(this->serverResponse)->setSize(0);
}

bool FtpClient::isConnected() {
	return this->server != nullptr;
}

$SocketAddress* FtpClient::getServerAddress() {
	return this->server == nullptr ? ($SocketAddress*)nullptr : $nc(this->server)->getRemoteSocketAddress();
}

$FtpClient* FtpClient::connect($SocketAddress* dest) {
	return connect(dest, -1);
}

$FtpClient* FtpClient::connect($SocketAddress* dest, int32_t timeout) {
	$useLocalCurrentObjectStackCache();
	if (!($instanceOf($InetSocketAddress, dest))) {
		$throwNew($IllegalArgumentException, "Wrong address type"_s);
	}
	$set(this, serverAddr, $cast($InetSocketAddress, dest));
	tryConnect(this->serverAddr, timeout);
	if (!readReply()) {
		$throwNew($FtpProtocolException, $$str({"Welcome message: "_s, $(getResponseString())}), this->lastReplyCode);
	}
	$set(this, welcomeMsg, $nc($(getResponseString()))->substring(4));
	return this;
}

void FtpClient::tryLogin($String* user, $chars* password) {
	$useLocalCurrentObjectStackCache();
	issueCommandCheck($$str({"USER "_s, user}));
	$init($FtpReplyCode);
	if (this->lastReplyCode == $FtpReplyCode::NEED_PASSWORD) {
		if ((password != nullptr) && (password->length > 0)) {
			issueCommandCheck($$str({"PASS "_s, $($String::valueOf(password))}));
		}
	}
}

$FtpClient* FtpClient::login($String* user, $chars* password) {
	$useLocalCurrentObjectStackCache();
	if (!isConnected()) {
		$init($FtpReplyCode);
		$throwNew($FtpProtocolException, "Not connected yet"_s, $FtpReplyCode::BAD_SEQUENCE);
	}
	if (user == nullptr || $nc(user)->isEmpty()) {
		$throwNew($IllegalArgumentException, "User name can\'t be null or empty"_s);
	}
	tryLogin(user, password);
	$var($String, l, nullptr);
	$var($StringBuilder, sb, $new($StringBuilder));
	for (int32_t i = 0; i < $nc(this->serverResponse)->size(); ++i) {
		$assign(l, $cast($String, $nc(this->serverResponse)->elementAt(i)));
		if (l != nullptr) {
			bool var$0 = l->length() >= 4;
			if (var$0 && l->startsWith("230"_s)) {
				$assign(l, l->substring(4));
			}
			sb->append(l);
		}
	}
	$set(this, welcomeMsg, sb->toString());
	this->loggedIn = true;
	return this;
}

$FtpClient* FtpClient::login($String* user, $chars* password, $String* account) {
	$useLocalCurrentObjectStackCache();
	if (!isConnected()) {
		$init($FtpReplyCode);
		$throwNew($FtpProtocolException, "Not connected yet"_s, $FtpReplyCode::BAD_SEQUENCE);
	}
	if (user == nullptr || $nc(user)->isEmpty()) {
		$throwNew($IllegalArgumentException, "User name can\'t be null or empty"_s);
	}
	tryLogin(user, password);
	$init($FtpReplyCode);
	if (this->lastReplyCode == $FtpReplyCode::NEED_ACCOUNT) {
		issueCommandCheck($$str({"ACCT "_s, account}));
	}
	$var($StringBuilder, sb, $new($StringBuilder));
	if (this->serverResponse != nullptr) {
		{
			$var($Iterator, i$, $nc(this->serverResponse)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($String, l, $cast($String, i$->next()));
				{
					if (l != nullptr) {
						bool var$0 = l->length() >= 4;
						if (var$0 && l->startsWith("230"_s)) {
							$assign(l, l->substring(4));
						}
						sb->append(l);
					}
				}
			}
		}
	}
	$set(this, welcomeMsg, sb->toString());
	this->loggedIn = true;
	return this;
}

void FtpClient::close() {
	if (isConnected()) {
		try {
			issueCommand("QUIT"_s);
		} catch ($FtpProtocolException& e) {
		}
		this->loggedIn = false;
	}
	disconnect();
}

bool FtpClient::isLoggedIn() {
	return this->loggedIn;
}

$FtpClient* FtpClient::changeDirectory($String* remoteDirectory) {
	if (remoteDirectory == nullptr || $nc(remoteDirectory)->isEmpty()) {
		$throwNew($IllegalArgumentException, "directory can\'t be null or empty"_s);
	}
	issueCommandCheck($$str({"CWD "_s, remoteDirectory}));
	return this;
}

$FtpClient* FtpClient::changeToParentDirectory() {
	issueCommandCheck("CDUP"_s);
	return this;
}

$String* FtpClient::getWorkingDirectory() {
	issueCommandCheck("PWD"_s);
	$var($String, answ, getResponseString());
	if (!$nc(answ)->startsWith("257"_s)) {
		return nullptr;
	}
	return $nc(answ)->substring(5, answ->lastIndexOf((int32_t)u'\"'));
}

$FtpClient* FtpClient::setRestartOffset(int64_t offset) {
	if (offset < 0) {
		$throwNew($IllegalArgumentException, "offset can\'t be negative"_s);
	}
	this->restartOffset = offset;
	return this;
}

$FtpClient* FtpClient::getFile($String* name, $OutputStream* local) {
	$useLocalCurrentObjectStackCache();
	if (this->restartOffset > 0) {
		$var($Socket, s, nullptr);
		{
			$var($Throwable, var$0, nullptr);
			try {
				$assign(s, openDataConnection($$str({"REST "_s, $$str(this->restartOffset)})));
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				this->restartOffset = 0;
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
		issueCommandCheck($$str({"RETR "_s, name}));
		getTransferSize();
		{
			$var($InputStream, remote, createInputStream($($nc(s)->getInputStream())));
			{
				$var($Throwable, var$2, nullptr);
				try {
					try {
						$nc(remote)->transferTo(local);
					} catch ($Throwable& t$) {
						if (remote != nullptr) {
							try {
								remote->close();
							} catch ($Throwable& x2) {
								t$->addSuppressed(x2);
							}
						}
						$throw(t$);
					}
				} catch ($Throwable& var$3) {
					$assign(var$2, var$3);
				} /*finally*/ {
					if (remote != nullptr) {
						remote->close();
					}
				}
				if (var$2 != nullptr) {
					$throw(var$2);
				}
			}
		}
	} else {
		$var($Socket, s, openDataConnection($$str({"RETR "_s, name})));
		getTransferSize();
		{
			$var($InputStream, remote, createInputStream($($nc(s)->getInputStream())));
			{
				$var($Throwable, var$4, nullptr);
				try {
					try {
						$nc(remote)->transferTo(local);
					} catch ($Throwable& t$) {
						if (remote != nullptr) {
							try {
								remote->close();
							} catch ($Throwable& x2) {
								t$->addSuppressed(x2);
							}
						}
						$throw(t$);
					}
				} catch ($Throwable& var$5) {
					$assign(var$4, var$5);
				} /*finally*/ {
					if (remote != nullptr) {
						remote->close();
					}
				}
				if (var$4 != nullptr) {
					$throw(var$4);
				}
			}
		}
	}
	return completePending();
}

$InputStream* FtpClient::getFileStream($String* name) {
	$useLocalCurrentObjectStackCache();
	$var($Socket, s, nullptr);
	if (this->restartOffset > 0) {
		{
			$var($Throwable, var$0, nullptr);
			try {
				$assign(s, openDataConnection($$str({"REST "_s, $$str(this->restartOffset)})));
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				this->restartOffset = 0;
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
		if (s == nullptr) {
			return nullptr;
		}
		issueCommandCheck($$str({"RETR "_s, name}));
		getTransferSize();
		return createInputStream($($nc(s)->getInputStream()));
	}
	$assign(s, openDataConnection($$str({"RETR "_s, name})));
	if (s == nullptr) {
		return nullptr;
	}
	getTransferSize();
	return createInputStream($($nc(s)->getInputStream()));
}

$OutputStream* FtpClient::putFileStream($String* name, bool unique) {
	$useLocalCurrentObjectStackCache();
	$var($String, cmd, unique ? "STOU "_s : "STOR "_s);
	$var($Socket, s, openDataConnection($$str({cmd, name})));
	if (s == nullptr) {
		return nullptr;
	}
	$init($FtpClient$TransferType);
	bool bm = (this->type == $FtpClient$TransferType::BINARY);
	return $new($TelnetOutputStream, $($nc(s)->getOutputStream()), bm);
}

$FtpClient* FtpClient::putFile($String* name, $InputStream* local, bool unique) {
	$useLocalCurrentObjectStackCache();
	$var($String, cmd, unique ? "STOU "_s : "STOR "_s);
	$init($FtpClient$TransferType);
	if (this->type == $FtpClient$TransferType::BINARY) {
		$var($Socket, s, openDataConnection($$str({cmd, name})));
		{
			$var($OutputStream, remote, createOutputStream($($nc(s)->getOutputStream())));
			{
				$var($Throwable, var$0, nullptr);
				try {
					try {
						$nc(local)->transferTo(remote);
					} catch ($Throwable& t$) {
						if (remote != nullptr) {
							try {
								remote->close();
							} catch ($Throwable& x2) {
								t$->addSuppressed(x2);
							}
						}
						$throw(t$);
					}
				} catch ($Throwable& var$1) {
					$assign(var$0, var$1);
				} /*finally*/ {
					if (remote != nullptr) {
						remote->close();
					}
				}
				if (var$0 != nullptr) {
					$throw(var$0);
				}
			}
		}
	}
	return completePending();
}

$FtpClient* FtpClient::appendFile($String* name, $InputStream* local) {
	$useLocalCurrentObjectStackCache();
	$var($Socket, s, openDataConnection($$str({"APPE "_s, name})));
	{
		$var($OutputStream, remote, createOutputStream($($nc(s)->getOutputStream())));
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					$nc(local)->transferTo(remote);
				} catch ($Throwable& t$) {
					if (remote != nullptr) {
						try {
							remote->close();
						} catch ($Throwable& x2) {
							t$->addSuppressed(x2);
						}
					}
					$throw(t$);
				}
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				if (remote != nullptr) {
					remote->close();
				}
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
	return completePending();
}

$FtpClient* FtpClient::rename($String* from, $String* to) {
	$useLocalCurrentObjectStackCache();
	issueCommandCheck($$str({"RNFR "_s, from}));
	issueCommandCheck($$str({"RNTO "_s, to}));
	return this;
}

$FtpClient* FtpClient::deleteFile($String* name) {
	issueCommandCheck($$str({"DELE "_s, name}));
	return this;
}

$FtpClient* FtpClient::makeDirectory($String* name) {
	issueCommandCheck($$str({"MKD "_s, name}));
	return this;
}

$FtpClient* FtpClient::removeDirectory($String* name) {
	issueCommandCheck($$str({"RMD "_s, name}));
	return this;
}

$FtpClient* FtpClient::noop() {
	issueCommandCheck("NOOP"_s);
	return this;
}

$String* FtpClient::getStatus($String* name) {
	$useLocalCurrentObjectStackCache();
	issueCommandCheck((name == nullptr ? "STAT"_s : $$str({"STAT "_s, name})));
	$var($Vector, resp, getResponseStrings());
	$var($StringBuilder, sb, $new($StringBuilder));
	for (int32_t i = 1; i < $nc(resp)->size() - 1; ++i) {
		sb->append($cast($String, $(resp->get(i))));
	}
	return sb->toString();
}

$List* FtpClient::getFeatures() {
	$useLocalCurrentObjectStackCache();
	$var($ArrayList, features, $new($ArrayList));
	issueCommandCheck("FEAT"_s);
	$var($Vector, resp, getResponseStrings());
	for (int32_t i = 1; i < $nc(resp)->size() - 1; ++i) {
		$var($String, s, $cast($String, resp->get(i)));
		features->add($($nc(s)->substring(1, s->length() - 1)));
	}
	return features;
}

$FtpClient* FtpClient::abort() {
	issueCommandCheck("ABOR"_s);
	return this;
}

$FtpClient* FtpClient::completePending() {
	$useLocalCurrentObjectStackCache();
	while (this->replyPending) {
		this->replyPending = false;
		if (!readReply()) {
			$throwNew($FtpProtocolException, $(getLastResponseString()), this->lastReplyCode);
		}
	}
	return this;
}

$FtpClient* FtpClient::reInit() {
	$useLocalCurrentObjectStackCache();
	issueCommandCheck("REIN"_s);
	this->loggedIn = false;
	if (this->useCrypto) {
		if ($instanceOf($SSLSocket, this->server)) {
			$var($SSLSession, session, $nc(($cast($SSLSocket, this->server)))->getSession());
			$nc(session)->invalidate();
			$set(this, server, this->oldSocket);
			$set(this, oldSocket, nullptr);
			try {
				$set(this, out, $new($PrintStream, static_cast<$OutputStream*>($$new($BufferedOutputStream, $($nc(this->server)->getOutputStream()))), true, FtpClient::encoding));
			} catch ($UnsupportedEncodingException& e) {
				$throwNew($InternalError, $$str({FtpClient::encoding, "encoding not found"_s}), e);
			}
			$set(this, in, $new($BufferedInputStream, $($nc(this->server)->getInputStream())));
		}
	}
	this->useCrypto = false;
	return this;
}

$FtpClient* FtpClient::setType($FtpClient$TransferType* type) {
	$var($String, cmd, "NOOP"_s);
	$set(this, type, type);
	$init($FtpClient$TransferType);
	if (type == $FtpClient$TransferType::ASCII) {
		$assign(cmd, "TYPE A"_s);
	}
	if (type == $FtpClient$TransferType::BINARY) {
		$assign(cmd, "TYPE I"_s);
	}
	if (type == $FtpClient$TransferType::EBCDIC) {
		$assign(cmd, "TYPE E"_s);
	}
	issueCommandCheck(cmd);
	return this;
}

$InputStream* FtpClient::list($String* path) {
	$useLocalCurrentObjectStackCache();
	$var($Socket, s, nullptr);
	$assign(s, openDataConnection(path == nullptr ? "LIST"_s : $$str({"LIST "_s, path})));
	if (s != nullptr) {
		return createInputStream($(s->getInputStream()));
	}
	return nullptr;
}

$InputStream* FtpClient::nameList($String* path) {
	$useLocalCurrentObjectStackCache();
	$var($Socket, s, nullptr);
	$assign(s, openDataConnection(path == nullptr ? "NLST"_s : $$str({"NLST "_s, path})));
	if (s != nullptr) {
		return createInputStream($(s->getInputStream()));
	}
	return nullptr;
}

int64_t FtpClient::getSize($String* path) {
	$useLocalCurrentObjectStackCache();
	if (path == nullptr || $nc(path)->isEmpty()) {
		$throwNew($IllegalArgumentException, "path can\'t be null or empty"_s);
	}
	issueCommandCheck($$str({"SIZE "_s, path}));
	$init($FtpReplyCode);
	if (this->lastReplyCode == $FtpReplyCode::FILE_STATUS) {
		$var($String, s, getResponseString());
		$assign(s, $nc(s)->substring(4, s->length() - 1));
		return $Long::parseLong(s);
	}
	return -1;
}

$Date* FtpClient::getLastModified($String* path) {
	$useLocalCurrentObjectStackCache();
	issueCommandCheck($$str({"MDTM "_s, path}));
	$init($FtpReplyCode);
	if (this->lastReplyCode == $FtpReplyCode::FILE_STATUS) {
		$var($String, s, getResponseString());
		return parseRfc3659TimeValue($($nc(s)->substring(4, s->length() - 1)));
	}
	return nullptr;
}

$Date* FtpClient::parseRfc3659TimeValue($String* s) {
	$init(FtpClient);
	$useLocalCurrentObjectStackCache();
	$var($Date, result, nullptr);
	try {
		$var($ZonedDateTime, d, $ZonedDateTime::parse(s, FtpClient::RFC3659_DATETIME_FORMAT));
		$assign(result, $Date::from($($nc(d)->toInstant())));
	} catch ($DateTimeParseException& ex) {
	}
	return result;
}

$FtpClient* FtpClient::setDirParser($FtpDirParser* p) {
	$set(this, parser, p);
	return this;
}

$Iterator* FtpClient::listFiles($String* path) {
	$useLocalCurrentObjectStackCache();
	$var($Socket, s, nullptr);
	$var($BufferedReader, sin, nullptr);
	try {
		$assign(s, openDataConnection(path == nullptr ? "MLSD"_s : $$str({"MLSD "_s, path})));
	} catch ($FtpProtocolException& FtpException) {
	}
	if (s != nullptr) {
		$assign(sin, $new($BufferedReader, $$new($InputStreamReader, $(s->getInputStream()))));
		return $new($FtpClient$FtpFileIterator, this->mlsxParser, sin);
	} else {
		$assign(s, openDataConnection(path == nullptr ? "LIST"_s : $$str({"LIST "_s, path})));
		if (s != nullptr) {
			$assign(sin, $new($BufferedReader, $$new($InputStreamReader, $(s->getInputStream()))));
			return $new($FtpClient$FtpFileIterator, this->parser, sin);
		}
	}
	return nullptr;
}

bool FtpClient::sendSecurityData($bytes* buf) {
	$useLocalCurrentObjectStackCache();
	$var($String, s, $nc($($Base64::getMimeEncoder()))->encodeToString(buf));
	return issueCommand($$str({"ADAT "_s, s}));
}

$bytes* FtpClient::getSecurityData() {
	$useLocalCurrentObjectStackCache();
	$var($String, s, getLastResponseString());
	if ($($nc(s)->substring(4, 9))->equalsIgnoreCase("ADAT="_s)) {
		return $nc($($Base64::getMimeDecoder()))->decode($(s->substring(9, s->length() - 1)));
	}
	return nullptr;
}

$FtpClient* FtpClient::useKerberos() {
	return this;
}

$String* FtpClient::getWelcomeMsg() {
	return this->welcomeMsg;
}

$FtpReplyCode* FtpClient::getLastReplyCode() {
	return this->lastReplyCode;
}

$String* FtpClient::getLastResponseString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	if (this->serverResponse != nullptr) {
		{
			$var($Iterator, i$, $nc(this->serverResponse)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($String, l, $cast($String, i$->next()));
				{
					if (l != nullptr) {
						sb->append(l);
					}
				}
			}
		}
	}
	return sb->toString();
}

int64_t FtpClient::getLastTransferSize() {
	return this->lastTransSize;
}

$String* FtpClient::getLastFileName() {
	return this->lastFileName;
}

$FtpClient* FtpClient::startSecureSession() {
	$useLocalCurrentObjectStackCache();
	if (!isConnected()) {
		$init($FtpReplyCode);
		$throwNew($FtpProtocolException, "Not connected yet"_s, $FtpReplyCode::BAD_SEQUENCE);
	}
	if (this->sslFact == nullptr) {
		try {
			$set(this, sslFact, $cast($SSLSocketFactory, $SSLSocketFactory::getDefault()));
		} catch ($Exception& e) {
			$throwNew($IOException, $(e->getLocalizedMessage()));
		}
	}
	issueCommandCheck("AUTH TLS"_s);
	$var($Socket, s, nullptr);
	try {
		$var($Socket, var$0, this->server);
		$var($String, var$1, $nc(this->serverAddr)->getHostName());
		$assign(s, $nc(this->sslFact)->createSocket(var$0, var$1, $nc(this->serverAddr)->getPort(), true));
	} catch ($SSLException& ssle) {
		try {
			disconnect();
		} catch ($Exception& e) {
		}
		$throw(ssle);
	}
	$set(this, oldSocket, this->server);
	$set(this, server, s);
	try {
		$set(this, out, $new($PrintStream, static_cast<$OutputStream*>($$new($BufferedOutputStream, $($nc(this->server)->getOutputStream()))), true, FtpClient::encoding));
	} catch ($UnsupportedEncodingException& e) {
		$throwNew($InternalError, $$str({FtpClient::encoding, "encoding not found"_s}), e);
	}
	$set(this, in, $new($BufferedInputStream, $($nc(this->server)->getInputStream())));
	issueCommandCheck("PBSZ 0"_s);
	issueCommandCheck("PROT P"_s);
	this->useCrypto = true;
	return this;
}

$FtpClient* FtpClient::endSecureSession() {
	$useLocalCurrentObjectStackCache();
	if (!this->useCrypto) {
		return this;
	}
	issueCommandCheck("CCC"_s);
	issueCommandCheck("PROT C"_s);
	this->useCrypto = false;
	$set(this, server, this->oldSocket);
	$set(this, oldSocket, nullptr);
	try {
		$set(this, out, $new($PrintStream, static_cast<$OutputStream*>($$new($BufferedOutputStream, $($nc(this->server)->getOutputStream()))), true, FtpClient::encoding));
	} catch ($UnsupportedEncodingException& e) {
		$throwNew($InternalError, $$str({FtpClient::encoding, "encoding not found"_s}), e);
	}
	$set(this, in, $new($BufferedInputStream, $($nc(this->server)->getInputStream())));
	return this;
}

$FtpClient* FtpClient::allocate(int64_t size) {
	$useLocalCurrentObjectStackCache();
	issueCommandCheck($$str({"ALLO "_s, $$str(size)}));
	return this;
}

$FtpClient* FtpClient::structureMount($String* struct$) {
	issueCommandCheck($$str({"SMNT "_s, struct$}));
	return this;
}

$String* FtpClient::getSystem() {
	issueCommandCheck("SYST"_s);
	$var($String, resp, getResponseString());
	return $nc(resp)->substring(4);
}

$String* FtpClient::getHelp($String* cmd) {
	$useLocalCurrentObjectStackCache();
	issueCommandCheck($$str({"HELP "_s, cmd}));
	$var($Vector, resp, getResponseStrings());
	if ($nc(resp)->size() == 1) {
		return $nc(($cast($String, $(resp->get(0)))))->substring(4);
	}
	$var($StringBuilder, sb, $new($StringBuilder));
	for (int32_t i = 1; i < $nc(resp)->size() - 1; ++i) {
		sb->append($($nc(($cast($String, $(resp->get(i)))))->substring(3)));
	}
	return sb->toString();
}

$FtpClient* FtpClient::siteCmd($String* cmd) {
	issueCommandCheck($$str({"SITE "_s, cmd}));
	return this;
}

$InetAddressArray* FtpClient::lambda$privilegedGetAllByName$2($String* hostName) {
	$init(FtpClient);
	return $InetAddress::getAllByName(hostName);
}

$InetAddress* FtpClient::lambda$openPassiveDataConnection$1() {
	return $nc(this->server)->getLocalAddress();
}

$Socket* FtpClient::lambda$openPassiveDataConnection$0() {
	return $new($Socket, this->proxy);
}

void clinit$FtpClient($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(FtpClient::ERROR_MSG, "Address should be the same as originating server"_s);
	$beforeCallerSensitive();
	$assignStatic(FtpClient::logger, $PlatformLogger::getLogger("sun.net.ftp.FtpClient"_s));
	$assignStatic(FtpClient::encoding, "ISO8859_1"_s);
	$assignStatic(FtpClient::patStrings, $new($StringArray, {
		"([\\-ld](?:[r\\-][w\\-][x\\-]){3})\\s*\\d+ (\\w+)\\s*(\\w+)\\s*(\\d+)\\s*([A-Z][a-z][a-z]\\s*\\d+)\\s*(\\d\\d:\\d\\d)\\s*(\\p{Print}*)"_s,
		"([\\-ld](?:[r\\-][w\\-][x\\-]){3})\\s*\\d+ (\\w+)\\s*(\\w+)\\s*(\\d+)\\s*([A-Z][a-z][a-z]\\s*\\d+)\\s*(\\d{4})\\s*(\\p{Print}*)"_s,
		"(\\d{2}/\\d{2}/\\d{4})\\s*(\\d{2}:\\d{2}[ap])\\s*((?:[0-9,]+)|(?:<DIR>))\\s*(\\p{Graph}*)"_s,
		"(\\d{2}-\\d{2}-\\d{2})\\s*(\\d{2}:\\d{2}[AP]M)\\s*((?:[0-9,]+)|(?:<DIR>))\\s*(\\p{Graph}*)"_s
	}));
	$assignStatic(FtpClient::patternGroups, $new($intArray2, {
		$$new($ints, {
			7,
			4,
			5,
			6,
			0,
			1,
			2,
			3
		}),
		$$new($ints, {
			7,
			4,
			5,
			0,
			6,
			1,
			2,
			3
		}),
		$$new($ints, {
			4,
			3,
			1,
			2,
			0,
			0,
			0,
			0
		}),
		$$new($ints, {
			4,
			3,
			1,
			2,
			0,
			0,
			0,
			0
		})
	}));
	$assignStatic(FtpClient::linkp, $Pattern::compile("(\\p{Print}+) \\-\\> (\\p{Print}+)$"_s));
	{
		$var($ints, vals, $new($ints, {
			0,
			0
		}));
		$var($StringArray, acceptPasvAddress, $new($StringArray, {($String*)nullptr}));
		$var($String, enc, $cast($String, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($FtpClient$1, acceptPasvAddress, vals)))));
		if (vals->get(0) == 0) {
			FtpClient::defaultSoTimeout = -1;
		} else {
			FtpClient::defaultSoTimeout = vals->get(0);
		}
		if (vals->get(1) == 0) {
			FtpClient::defaultConnectTimeout = -1;
		} else {
			FtpClient::defaultConnectTimeout = vals->get(1);
		}
		$assignStatic(FtpClient::encoding, enc);
		try {
			if (!FtpClient::isASCIISuperset(FtpClient::encoding)) {
				$assignStatic(FtpClient::encoding, "ISO8859_1"_s);
			}
		} catch ($Exception& e) {
			$assignStatic(FtpClient::encoding, "ISO8859_1"_s);
		}
		$assignStatic(FtpClient::patterns, $new($PatternArray, $nc(FtpClient::patStrings)->length));
		for (int32_t i = 0; i < $nc(FtpClient::patStrings)->length; ++i) {
			$nc(FtpClient::patterns)->set(i, $($Pattern::compile($nc(FtpClient::patStrings)->get(i))));
		}
		FtpClient::acceptPasvAddressVal = $Boolean::parseBoolean(acceptPasvAddress->get(0));
	}
	$assignStatic(FtpClient::transPat, nullptr);
	$assignStatic(FtpClient::epsvPat, nullptr);
	$assignStatic(FtpClient::pasvPat, nullptr);
	$init($ZoneOffset);
	$assignStatic(FtpClient::RFC3659_DATETIME_FORMAT, $nc($($DateTimeFormatter::ofPattern("yyyyMMddHHmmss[.SSS]"_s)))->withZone($ZoneOffset::UTC));
}

FtpClient::FtpClient() {
}

$Class* FtpClient::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(FtpClient$$Lambda$lambda$openPassiveDataConnection$0::classInfo$.name)) {
			return FtpClient$$Lambda$lambda$openPassiveDataConnection$0::load$(name, initialize);
		}
		if (name->equals(FtpClient$$Lambda$lambda$openPassiveDataConnection$1$1::classInfo$.name)) {
			return FtpClient$$Lambda$lambda$openPassiveDataConnection$1$1::load$(name, initialize);
		}
		if (name->equals(FtpClient$$Lambda$getHostAddress$2::classInfo$.name)) {
			return FtpClient$$Lambda$getHostAddress$2::load$(name, initialize);
		}
		if (name->equals(FtpClient$$Lambda$equalsIgnoreCase$3::classInfo$.name)) {
			return FtpClient$$Lambda$equalsIgnoreCase$3::load$(name, initialize);
		}
		if (name->equals(FtpClient$$Lambda$getLocalHost$4::classInfo$.name)) {
			return FtpClient$$Lambda$getLocalHost$4::load$(name, initialize);
		}
		if (name->equals(FtpClient$$Lambda$lambda$privilegedGetAllByName$2$5::classInfo$.name)) {
			return FtpClient$$Lambda$lambda$privilegedGetAllByName$2$5::load$(name, initialize);
		}
	}
	$loadClass(FtpClient, name, initialize, &_FtpClient_ClassInfo_, clinit$FtpClient, allocate$FtpClient);
	return class$;
}

$Class* FtpClient::class$ = nullptr;

			} // impl
		} // ftp
	} // net
} // sun