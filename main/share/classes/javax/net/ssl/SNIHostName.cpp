#include <javax/net/ssl/SNIHostName.h>

#include <java/net/IDN.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/CharBuffer.h>
#include <java/nio/charset/CharacterCodingException.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/CharsetDecoder.h>
#include <java/nio/charset/CodingErrorAction.h>
#include <java/nio/charset/StandardCharsets.h>
#include <java/util/Locale.h>
#include <java/util/Objects.h>
#include <javax/net/ssl/SNIHostName$SNIHostNameMatcher.h>
#include <javax/net/ssl/SNIMatcher.h>
#include <javax/net/ssl/SNIServerName.h>
#include <javax/net/ssl/StandardConstants.h>
#include <jcpp.h>

#undef ENGLISH
#undef REPORT
#undef SNI_HOST_NAME
#undef USE_STD3_ASCII_RULES
#undef US_ASCII
#undef UTF_8

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $RuntimeException = ::java::lang::RuntimeException;
using $IDN = ::java::net::IDN;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $CharBuffer = ::java::nio::CharBuffer;
using $CharacterCodingException = ::java::nio::charset::CharacterCodingException;
using $Charset = ::java::nio::charset::Charset;
using $CharsetDecoder = ::java::nio::charset::CharsetDecoder;
using $CodingErrorAction = ::java::nio::charset::CodingErrorAction;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $Locale = ::java::util::Locale;
using $Objects = ::java::util::Objects;
using $SNIHostName$SNIHostNameMatcher = ::javax::net::ssl::SNIHostName$SNIHostNameMatcher;
using $SNIMatcher = ::javax::net::ssl::SNIMatcher;
using $SNIServerName = ::javax::net::ssl::SNIServerName;
using $StandardConstants = ::javax::net::ssl::StandardConstants;

namespace javax {
	namespace net {
		namespace ssl {

$FieldInfo _SNIHostName_FieldInfo_[] = {
	{"hostname", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(SNIHostName, hostname)},
	{}
};

$MethodInfo _SNIHostName_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(SNIHostName, init$, void, $String*)},
	{"<init>", "([B)V", nullptr, $PUBLIC, $method(SNIHostName, init$, void, $bytes*)},
	{"checkHostName", "()V", nullptr, $PRIVATE, $method(SNIHostName, checkHostName, void)},
	{"createSNIMatcher", "(Ljava/lang/String;)Ljavax/net/ssl/SNIMatcher;", nullptr, $PUBLIC | $STATIC, $staticMethod(SNIHostName, createSNIMatcher, $SNIMatcher*, $String*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(SNIHostName, equals, bool, Object$*)},
	{"getAsciiName", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(SNIHostName, getAsciiName, $String*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(SNIHostName, hashCode, int32_t)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SNIHostName, toString, $String*)},
	{}
};

$InnerClassInfo _SNIHostName_InnerClassesInfo_[] = {
	{"javax.net.ssl.SNIHostName$SNIHostNameMatcher", "javax.net.ssl.SNIHostName", "SNIHostNameMatcher", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _SNIHostName_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"javax.net.ssl.SNIHostName",
	"javax.net.ssl.SNIServerName",
	nullptr,
	_SNIHostName_FieldInfo_,
	_SNIHostName_MethodInfo_,
	nullptr,
	nullptr,
	_SNIHostName_InnerClassesInfo_,
	nullptr,
	nullptr,
	"javax.net.ssl.SNIHostName$SNIHostNameMatcher"
};

$Object* allocate$SNIHostName($Class* clazz) {
	return $of($alloc(SNIHostName));
}

void SNIHostName::init$($String* hostname$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($String, hostname, hostname$renamed);
	$init($StandardCharsets);
	$SNIServerName::init$($StandardConstants::SNI_HOST_NAME, $($nc(($assign(hostname, $IDN::toASCII($cast($String, $Objects::requireNonNull($of(hostname), "Server name value of host_name cannot be null"_s)), $IDN::USE_STD3_ASCII_RULES))))->getBytes($StandardCharsets::US_ASCII)));
	$set(this, hostname, hostname);
	checkHostName();
}

void SNIHostName::init$($bytes* encoded) {
	$useLocalCurrentObjectStackCache();
	$SNIServerName::init$($StandardConstants::SNI_HOST_NAME, encoded);
	try {
		$init($StandardCharsets);
		$init($CodingErrorAction);
		$var($CharsetDecoder, decoder, $nc($($nc($($nc($StandardCharsets::UTF_8)->newDecoder()))->onMalformedInput($CodingErrorAction::REPORT)))->onUnmappableCharacter($CodingErrorAction::REPORT));
		$set(this, hostname, $IDN::toASCII($($nc($($nc(decoder)->decode($($ByteBuffer::wrap(encoded)))))->toString()), $IDN::USE_STD3_ASCII_RULES));
	} catch ($RuntimeException& e) {
		$throwNew($IllegalArgumentException, "The encoded server name value is invalid"_s, e);
	} catch ($CharacterCodingException& e) {
		$throwNew($IllegalArgumentException, "The encoded server name value is invalid"_s, e);
	}
	checkHostName();
}

$String* SNIHostName::getAsciiName() {
	return this->hostname;
}

bool SNIHostName::equals(Object$* other) {
	if ($equals(this, other)) {
		return true;
	}
	if ($instanceOf(SNIHostName, other)) {
		return $nc(this->hostname)->equalsIgnoreCase($nc(($cast(SNIHostName, other)))->hostname);
	}
	return false;
}

int32_t SNIHostName::hashCode() {
	int32_t result = 17;
	$init($Locale);
	result = 31 * result + $($nc(this->hostname)->toUpperCase($Locale::ENGLISH))->hashCode();
	return result;
}

$String* SNIHostName::toString() {
	return $str({"type=host_name (0), value="_s, this->hostname});
}

$SNIMatcher* SNIHostName::createSNIMatcher($String* regex) {
	$init(SNIHostName);
	if (regex == nullptr) {
		$throwNew($NullPointerException, "The regular expression cannot be null"_s);
	}
	return $new($SNIHostName$SNIHostNameMatcher, regex);
}

void SNIHostName::checkHostName() {
	if ($nc(this->hostname)->isEmpty()) {
		$throwNew($IllegalArgumentException, "Server name value of host_name cannot be empty"_s);
	}
	if ($nc(this->hostname)->endsWith("."_s)) {
		$throwNew($IllegalArgumentException, "Server name value of host_name cannot have the trailing dot"_s);
	}
}

SNIHostName::SNIHostName() {
}

$Class* SNIHostName::load$($String* name, bool initialize) {
	$loadClass(SNIHostName, name, initialize, &_SNIHostName_ClassInfo_, allocate$SNIHostName);
	return class$;
}

$Class* SNIHostName::class$ = nullptr;

		} // ssl
	} // net
} // javax