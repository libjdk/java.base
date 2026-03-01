#include <javax/net/ssl/SNIHostName$SNIHostNameMatcher.h>

#include <java/lang/CharSequence.h>
#include <java/net/IDN.h>
#include <java/util/regex/Matcher.h>
#include <java/util/regex/Pattern.h>
#include <javax/net/ssl/SNIHostName.h>
#include <javax/net/ssl/SNIMatcher.h>
#include <javax/net/ssl/SNIServerName.h>
#include <javax/net/ssl/StandardConstants.h>
#include <jcpp.h>

#undef CASE_INSENSITIVE
#undef SNI_HOST_NAME

using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $IDN = ::java::net::IDN;
using $Matcher = ::java::util::regex::Matcher;
using $Pattern = ::java::util::regex::Pattern;
using $SNIHostName = ::javax::net::ssl::SNIHostName;
using $SNIMatcher = ::javax::net::ssl::SNIMatcher;
using $SNIServerName = ::javax::net::ssl::SNIServerName;
using $StandardConstants = ::javax::net::ssl::StandardConstants;

namespace javax {
	namespace net {
		namespace ssl {

$FieldInfo _SNIHostName$SNIHostNameMatcher_FieldInfo_[] = {
	{"pattern", "Ljava/util/regex/Pattern;", nullptr, $PRIVATE | $FINAL, $field(SNIHostName$SNIHostNameMatcher, pattern)},
	{}
};

$MethodInfo _SNIHostName$SNIHostNameMatcher_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, 0, $method(SNIHostName$SNIHostNameMatcher, init$, void, $String*)},
	{"matches", "(Ljavax/net/ssl/SNIServerName;)Z", nullptr, $PUBLIC, $virtualMethod(SNIHostName$SNIHostNameMatcher, matches, bool, $SNIServerName*)},
	{}
};

$InnerClassInfo _SNIHostName$SNIHostNameMatcher_InnerClassesInfo_[] = {
	{"javax.net.ssl.SNIHostName$SNIHostNameMatcher", "javax.net.ssl.SNIHostName", "SNIHostNameMatcher", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _SNIHostName$SNIHostNameMatcher_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"javax.net.ssl.SNIHostName$SNIHostNameMatcher",
	"javax.net.ssl.SNIMatcher",
	nullptr,
	_SNIHostName$SNIHostNameMatcher_FieldInfo_,
	_SNIHostName$SNIHostNameMatcher_MethodInfo_,
	nullptr,
	nullptr,
	_SNIHostName$SNIHostNameMatcher_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"javax.net.ssl.SNIHostName"
};

$Object* allocate$SNIHostName$SNIHostNameMatcher($Class* clazz) {
	return $of($alloc(SNIHostName$SNIHostNameMatcher));
}

void SNIHostName$SNIHostNameMatcher::init$($String* regex) {
	$SNIMatcher::init$($StandardConstants::SNI_HOST_NAME);
	$set(this, pattern, $Pattern::compile(regex, $Pattern::CASE_INSENSITIVE));
}

bool SNIHostName$SNIHostNameMatcher::matches($SNIServerName* serverName) {
	$useLocalCurrentObjectStackCache();
	if (serverName == nullptr) {
		$throwNew($NullPointerException, "The SNIServerName argument cannot be null"_s);
	}
	$var($SNIHostName, hostname, nullptr);
	if (!($instanceOf($SNIHostName, serverName))) {
		if ($nc(serverName)->getType() != $StandardConstants::SNI_HOST_NAME) {
			$throwNew($IllegalArgumentException, "The server name type is not host_name"_s);
		}
		try {
			$assign(hostname, $new($SNIHostName, $($nc(serverName)->getEncoded())));
		} catch ($NullPointerException& e) {
			return false;
		} catch ($IllegalArgumentException& e) {
			return false;
		}
	} else {
		$assign(hostname, $cast($SNIHostName, serverName));
	}
	$var($String, asciiName, $nc(hostname)->getAsciiName());
	if ($nc($($nc(this->pattern)->matcher(asciiName)))->matches()) {
		return true;
	}
	return $nc($($nc(this->pattern)->matcher($($IDN::toUnicode(asciiName)))))->matches();
}

SNIHostName$SNIHostNameMatcher::SNIHostName$SNIHostNameMatcher() {
}

$Class* SNIHostName$SNIHostNameMatcher::load$($String* name, bool initialize) {
	$loadClass(SNIHostName$SNIHostNameMatcher, name, initialize, &_SNIHostName$SNIHostNameMatcher_ClassInfo_, allocate$SNIHostName$SNIHostNameMatcher);
	return class$;
}

$Class* SNIHostName$SNIHostNameMatcher::class$ = nullptr;

		} // ssl
	} // net
} // javax