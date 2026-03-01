#include <java/net/HttpCookie.h>

#include <java/lang/CharSequence.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/Cloneable.h>
#include <java/net/HttpCookie$1.h>
#include <java/net/HttpCookie$10.h>
#include <java/net/HttpCookie$11.h>
#include <java/net/HttpCookie$12.h>
#include <java/net/HttpCookie$2.h>
#include <java/net/HttpCookie$3.h>
#include <java/net/HttpCookie$4.h>
#include <java/net/HttpCookie$5.h>
#include <java/net/HttpCookie$6.h>
#include <java/net/HttpCookie$7.h>
#include <java/net/HttpCookie$8.h>
#include <java/net/HttpCookie$9.h>
#include <java/net/HttpCookie$CookieAttributeAssignor.h>
#include <java/text/SimpleDateFormat.h>
#include <java/util/ArrayList.h>
#include <java/util/Calendar.h>
#include <java/util/Date.h>
#include <java/util/GregorianCalendar.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/Map.h>
#include <java/util/NoSuchElementException.h>
#include <java/util/Objects.h>
#include <java/util/StringTokenizer.h>
#include <java/util/TimeZone.h>
#include <jdk/internal/access/JavaNetHttpCookieAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jcpp.h>

#undef COOKIE_DATE_FORMATS
#undef D
#undef GMT
#undef H
#undef MAX_AGE_UNSPECIFIED
#undef SET_COOKIE
#undef SET_COOKIE2
#undef US
#undef YEAR

using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $Cloneable = ::java::lang::Cloneable;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $HttpCookie$1 = ::java::net::HttpCookie$1;
using $HttpCookie$10 = ::java::net::HttpCookie$10;
using $HttpCookie$11 = ::java::net::HttpCookie$11;
using $HttpCookie$12 = ::java::net::HttpCookie$12;
using $HttpCookie$2 = ::java::net::HttpCookie$2;
using $HttpCookie$3 = ::java::net::HttpCookie$3;
using $HttpCookie$4 = ::java::net::HttpCookie$4;
using $HttpCookie$5 = ::java::net::HttpCookie$5;
using $HttpCookie$6 = ::java::net::HttpCookie$6;
using $HttpCookie$7 = ::java::net::HttpCookie$7;
using $HttpCookie$8 = ::java::net::HttpCookie$8;
using $HttpCookie$9 = ::java::net::HttpCookie$9;
using $HttpCookie$CookieAttributeAssignor = ::java::net::HttpCookie$CookieAttributeAssignor;
using $SimpleDateFormat = ::java::text::SimpleDateFormat;
using $ArrayList = ::java::util::ArrayList;
using $Calendar = ::java::util::Calendar;
using $GregorianCalendar = ::java::util::GregorianCalendar;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $NoSuchElementException = ::java::util::NoSuchElementException;
using $Objects = ::java::util::Objects;
using $StringTokenizer = ::java::util::StringTokenizer;
using $TimeZone = ::java::util::TimeZone;
using $JavaNetHttpCookieAccess = ::jdk::internal::access::JavaNetHttpCookieAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;

namespace java {
	namespace net {

$FieldInfo _HttpCookie_FieldInfo_[] = {
	{"name", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(HttpCookie, name)},
	{"value", "Ljava/lang/String;", nullptr, $PRIVATE, $field(HttpCookie, value)},
	{"comment", "Ljava/lang/String;", nullptr, $PRIVATE, $field(HttpCookie, comment)},
	{"commentURL", "Ljava/lang/String;", nullptr, $PRIVATE, $field(HttpCookie, commentURL)},
	{"toDiscard", "Z", nullptr, $PRIVATE, $field(HttpCookie, toDiscard)},
	{"domain", "Ljava/lang/String;", nullptr, $PRIVATE, $field(HttpCookie, domain)},
	{"maxAge", "J", nullptr, $PRIVATE, $field(HttpCookie, maxAge)},
	{"path", "Ljava/lang/String;", nullptr, $PRIVATE, $field(HttpCookie, path)},
	{"portlist", "Ljava/lang/String;", nullptr, $PRIVATE, $field(HttpCookie, portlist)},
	{"secure", "Z", nullptr, $PRIVATE, $field(HttpCookie, secure)},
	{"httpOnly", "Z", nullptr, $PRIVATE, $field(HttpCookie, httpOnly)},
	{"version", "I", nullptr, $PRIVATE, $field(HttpCookie, version)},
	{"header", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(HttpCookie, header$)},
	{"whenCreated", "J", nullptr, $PRIVATE | $FINAL, $field(HttpCookie, whenCreated)},
	{"MAX_AGE_UNSPECIFIED", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(HttpCookie, MAX_AGE_UNSPECIFIED)},
	{"COOKIE_DATE_FORMATS", "[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HttpCookie, COOKIE_DATE_FORMATS)},
	{"SET_COOKIE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HttpCookie, SET_COOKIE)},
	{"SET_COOKIE2", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HttpCookie, SET_COOKIE2)},
	{"tspecials", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HttpCookie, tspecials)},
	{"assignors", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/net/HttpCookie$CookieAttributeAssignor;>;", $STATIC | $FINAL, $staticField(HttpCookie, assignors)},
	{"GMT", "Ljava/util/TimeZone;", nullptr, $STATIC | $FINAL, $staticField(HttpCookie, GMT)},
	{}
};

$MethodInfo _HttpCookie_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(HttpCookie, init$, void, $String*, $String*)},
	{"<init>", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PRIVATE, $method(HttpCookie, init$, void, $String*, $String*, $String*)},
	{"<init>", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;J)V", nullptr, 0, $method(HttpCookie, init$, void, $String*, $String*, $String*, int64_t)},
	{"assignAttribute", "(Ljava/net/HttpCookie;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(HttpCookie, assignAttribute, void, HttpCookie*, $String*, $String*)},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(HttpCookie, clone, $Object*)},
	{"domainMatches", "(Ljava/lang/String;Ljava/lang/String;)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(HttpCookie, domainMatches, bool, $String*, $String*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(HttpCookie, equals, bool, Object$*)},
	{"equalsIgnoreCase", "(Ljava/lang/String;Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(HttpCookie, equalsIgnoreCase, bool, $String*, $String*)},
	{"expiryDate2DeltaSeconds", "(Ljava/lang/String;)J", nullptr, $PRIVATE, $method(HttpCookie, expiryDate2DeltaSeconds, int64_t, $String*)},
	{"getComment", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(HttpCookie, getComment, $String*)},
	{"getCommentURL", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(HttpCookie, getCommentURL, $String*)},
	{"getCreationTime", "()J", nullptr, 0, $method(HttpCookie, getCreationTime, int64_t)},
	{"getDiscard", "()Z", nullptr, $PUBLIC, $method(HttpCookie, getDiscard, bool)},
	{"getDomain", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(HttpCookie, getDomain, $String*)},
	{"getMaxAge", "()J", nullptr, $PUBLIC, $method(HttpCookie, getMaxAge, int64_t)},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(HttpCookie, getName, $String*)},
	{"getPath", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(HttpCookie, getPath, $String*)},
	{"getPortlist", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(HttpCookie, getPortlist, $String*)},
	{"getSecure", "()Z", nullptr, $PUBLIC, $method(HttpCookie, getSecure, bool)},
	{"getValue", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(HttpCookie, getValue, $String*)},
	{"getVersion", "()I", nullptr, $PUBLIC, $method(HttpCookie, getVersion, int32_t)},
	{"guessCookieVersion", "(Ljava/lang/String;)I", nullptr, $PRIVATE | $STATIC, $staticMethod(HttpCookie, guessCookieVersion, int32_t, $String*)},
	{"hasExpired", "()Z", nullptr, $PUBLIC, $method(HttpCookie, hasExpired, bool)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(HttpCookie, hashCode, int32_t)},
	{"header", "()Ljava/lang/String;", nullptr, $PRIVATE, $method(HttpCookie, header, $String*)},
	{"isHttpOnly", "()Z", nullptr, $PUBLIC, $method(HttpCookie, isHttpOnly, bool)},
	{"isToken", "(Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(HttpCookie, isToken, bool, $String*)},
	{"parse", "(Ljava/lang/String;)Ljava/util/List;", "(Ljava/lang/String;)Ljava/util/List<Ljava/net/HttpCookie;>;", $PUBLIC | $STATIC, $staticMethod(HttpCookie, parse, $List*, $String*)},
	{"parse", "(Ljava/lang/String;Z)Ljava/util/List;", "(Ljava/lang/String;Z)Ljava/util/List<Ljava/net/HttpCookie;>;", $PRIVATE | $STATIC, $staticMethod(HttpCookie, parse, $List*, $String*, bool)},
	{"parseInternal", "(Ljava/lang/String;Z)Ljava/net/HttpCookie;", nullptr, $PRIVATE | $STATIC, $staticMethod(HttpCookie, parseInternal, HttpCookie*, $String*, bool)},
	{"setComment", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(HttpCookie, setComment, void, $String*)},
	{"setCommentURL", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(HttpCookie, setCommentURL, void, $String*)},
	{"setDiscard", "(Z)V", nullptr, $PUBLIC, $method(HttpCookie, setDiscard, void, bool)},
	{"setDomain", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(HttpCookie, setDomain, void, $String*)},
	{"setHttpOnly", "(Z)V", nullptr, $PUBLIC, $method(HttpCookie, setHttpOnly, void, bool)},
	{"setMaxAge", "(J)V", nullptr, $PUBLIC, $method(HttpCookie, setMaxAge, void, int64_t)},
	{"setPath", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(HttpCookie, setPath, void, $String*)},
	{"setPortlist", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(HttpCookie, setPortlist, void, $String*)},
	{"setSecure", "(Z)V", nullptr, $PUBLIC, $method(HttpCookie, setSecure, void, bool)},
	{"setValue", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(HttpCookie, setValue, void, $String*)},
	{"setVersion", "(I)V", nullptr, $PUBLIC, $method(HttpCookie, setVersion, void, int32_t)},
	{"splitMultiCookies", "(Ljava/lang/String;)Ljava/util/List;", "(Ljava/lang/String;)Ljava/util/List<Ljava/lang/String;>;", $PRIVATE | $STATIC, $staticMethod(HttpCookie, splitMultiCookies, $List*, $String*)},
	{"startsWithIgnoreCase", "(Ljava/lang/String;Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(HttpCookie, startsWithIgnoreCase, bool, $String*, $String*)},
	{"stripOffSurroundingQuote", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(HttpCookie, stripOffSurroundingQuote, $String*, $String*)},
	{"toNetscapeHeaderString", "()Ljava/lang/String;", nullptr, $PRIVATE, $method(HttpCookie, toNetscapeHeaderString, $String*)},
	{"toRFC2965HeaderString", "()Ljava/lang/String;", nullptr, $PRIVATE, $method(HttpCookie, toRFC2965HeaderString, $String*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(HttpCookie, toString, $String*)},
	{}
};

$InnerClassInfo _HttpCookie_InnerClassesInfo_[] = {
	{"java.net.HttpCookie$CookieAttributeAssignor", "java.net.HttpCookie", "CookieAttributeAssignor", $STATIC | $INTERFACE | $ABSTRACT},
	{"java.net.HttpCookie$12", nullptr, nullptr, 0},
	{"java.net.HttpCookie$11", nullptr, nullptr, 0},
	{"java.net.HttpCookie$10", nullptr, nullptr, 0},
	{"java.net.HttpCookie$9", nullptr, nullptr, 0},
	{"java.net.HttpCookie$8", nullptr, nullptr, 0},
	{"java.net.HttpCookie$7", nullptr, nullptr, 0},
	{"java.net.HttpCookie$6", nullptr, nullptr, 0},
	{"java.net.HttpCookie$5", nullptr, nullptr, 0},
	{"java.net.HttpCookie$4", nullptr, nullptr, 0},
	{"java.net.HttpCookie$3", nullptr, nullptr, 0},
	{"java.net.HttpCookie$2", nullptr, nullptr, 0},
	{"java.net.HttpCookie$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _HttpCookie_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.net.HttpCookie",
	"java.lang.Object",
	"java.lang.Cloneable",
	_HttpCookie_FieldInfo_,
	_HttpCookie_MethodInfo_,
	nullptr,
	nullptr,
	_HttpCookie_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.net.HttpCookie$CookieAttributeAssignor,java.net.HttpCookie$12,java.net.HttpCookie$11,java.net.HttpCookie$10,java.net.HttpCookie$9,java.net.HttpCookie$8,java.net.HttpCookie$7,java.net.HttpCookie$6,java.net.HttpCookie$5,java.net.HttpCookie$4,java.net.HttpCookie$3,java.net.HttpCookie$2,java.net.HttpCookie$1"
};

$Object* allocate$HttpCookie($Class* clazz) {
	return $of($alloc(HttpCookie));
}

$StringArray* HttpCookie::COOKIE_DATE_FORMATS = nullptr;
$String* HttpCookie::SET_COOKIE = nullptr;
$String* HttpCookie::SET_COOKIE2 = nullptr;
$String* HttpCookie::tspecials = nullptr;
$Map* HttpCookie::assignors = nullptr;
$TimeZone* HttpCookie::GMT = nullptr;

void HttpCookie::init$($String* name, $String* value) {
	HttpCookie::init$(name, value, nullptr);
}

void HttpCookie::init$($String* name, $String* value, $String* header) {
	HttpCookie::init$(name, value, header, $System::currentTimeMillis());
}

void HttpCookie::init$($String* name$renamed, $String* value, $String* header, int64_t creationTime) {
	$var($String, name, name$renamed);
	this->maxAge = HttpCookie::MAX_AGE_UNSPECIFIED;
	this->version = 1;
	$assign(name, $nc(name)->trim());
	bool var$1 = name->isEmpty();
	bool var$0 = var$1 || !isToken(name);
	if (var$0 || name->charAt(0) == u'$') {
		$throwNew($IllegalArgumentException, "Illegal cookie name"_s);
	}
	$set(this, name, name);
	$set(this, value, value);
	this->toDiscard = false;
	this->secure = false;
	this->whenCreated = creationTime;
	$set(this, portlist, nullptr);
	$set(this, header$, header);
}

$List* HttpCookie::parse($String* header) {
	$init(HttpCookie);
	return parse(header, false);
}

$List* HttpCookie::parse($String* header$renamed, bool retainHeader) {
	$init(HttpCookie);
	$useLocalCurrentObjectStackCache();
	$var($String, header, header$renamed);
	int32_t version = guessCookieVersion(header);
	if (startsWithIgnoreCase(header, HttpCookie::SET_COOKIE2)) {
		$assign(header, $nc(header)->substring($nc(HttpCookie::SET_COOKIE2)->length()));
	} else {
		if (startsWithIgnoreCase(header, HttpCookie::SET_COOKIE)) {
			$assign(header, $nc(header)->substring($nc(HttpCookie::SET_COOKIE)->length()));
		}
	}
	$var($List, cookies, $new($ArrayList));
	if (version == 0) {
		$var(HttpCookie, cookie, parseInternal(header, retainHeader));
		$nc(cookie)->setVersion(0);
		cookies->add(cookie);
	} else {
		$var($List, cookieStrings, splitMultiCookies(header));
		{
			$var($Iterator, i$, $nc(cookieStrings)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($String, cookieStr, $cast($String, i$->next()));
				{
					$var(HttpCookie, cookie, parseInternal(cookieStr, retainHeader));
					$nc(cookie)->setVersion(1);
					cookies->add(cookie);
				}
			}
		}
	}
	return cookies;
}

bool HttpCookie::hasExpired() {
	if (this->maxAge == 0) {
		return true;
	}
	if (this->maxAge < 0) {
		return false;
	}
	int64_t deltaSecond = ($System::currentTimeMillis() - this->whenCreated) / 1000;
	if (deltaSecond > this->maxAge) {
		return true;
	} else {
		return false;
	}
}

void HttpCookie::setComment($String* purpose) {
	$set(this, comment, purpose);
}

$String* HttpCookie::getComment() {
	return this->comment;
}

void HttpCookie::setCommentURL($String* purpose) {
	$set(this, commentURL, purpose);
}

$String* HttpCookie::getCommentURL() {
	return this->commentURL;
}

void HttpCookie::setDiscard(bool discard) {
	this->toDiscard = discard;
}

bool HttpCookie::getDiscard() {
	return this->toDiscard;
}

void HttpCookie::setPortlist($String* ports) {
	$set(this, portlist, ports);
}

$String* HttpCookie::getPortlist() {
	return this->portlist;
}

void HttpCookie::setDomain($String* pattern) {
	if (pattern != nullptr) {
		$set(this, domain, pattern->toLowerCase());
	} else {
		$set(this, domain, pattern);
	}
}

$String* HttpCookie::getDomain() {
	return this->domain;
}

void HttpCookie::setMaxAge(int64_t expiry) {
	this->maxAge = expiry;
}

int64_t HttpCookie::getMaxAge() {
	return this->maxAge;
}

void HttpCookie::setPath($String* uri) {
	$set(this, path, uri);
}

$String* HttpCookie::getPath() {
	return this->path;
}

void HttpCookie::setSecure(bool flag) {
	this->secure = flag;
}

bool HttpCookie::getSecure() {
	return this->secure;
}

$String* HttpCookie::getName() {
	return this->name;
}

void HttpCookie::setValue($String* newValue) {
	$set(this, value, newValue);
}

$String* HttpCookie::getValue() {
	return this->value;
}

int32_t HttpCookie::getVersion() {
	return this->version;
}

void HttpCookie::setVersion(int32_t v) {
	if (v != 0 && v != 1) {
		$throwNew($IllegalArgumentException, "cookie version should be 0 or 1"_s);
	}
	this->version = v;
}

bool HttpCookie::isHttpOnly() {
	return this->httpOnly;
}

void HttpCookie::setHttpOnly(bool httpOnly) {
	this->httpOnly = httpOnly;
}

bool HttpCookie::domainMatches($String* domain, $String* host) {
	$init(HttpCookie);
	$useLocalCurrentObjectStackCache();
	if (domain == nullptr || host == nullptr) {
		return false;
	}
	bool isLocalDomain = ".local"_s->equalsIgnoreCase(domain);
	int32_t embeddedDotInDomain = $nc(domain)->indexOf((int32_t)u'.');
	if (embeddedDotInDomain == 0) {
		embeddedDotInDomain = domain->indexOf((int32_t)u'.', 1);
	}
	if (!isLocalDomain && (embeddedDotInDomain == -1 || embeddedDotInDomain == domain->length() - 1)) {
		return false;
	}
	int32_t firstDotInHost = $nc(host)->indexOf((int32_t)u'.');
	if (firstDotInHost == -1 && (isLocalDomain || domain->equalsIgnoreCase($$str({host, ".local"_s})))) {
		return true;
	}
	int32_t domainLength = domain->length();
	int32_t lengthDiff = host->length() - domainLength;
	if (lengthDiff == 0) {
		return host->equalsIgnoreCase(domain);
	} else if (lengthDiff > 0) {
		$var($String, H, host->substring(0, lengthDiff));
		$var($String, D, host->substring(lengthDiff));
		bool var$0 = H->indexOf((int32_t)u'.') == -1;
		return (var$0 && D->equalsIgnoreCase(domain));
	} else if (lengthDiff == -1) {
		bool var$1 = domain->charAt(0) == u'.';
		return (var$1 && host->equalsIgnoreCase($(domain->substring(1))));
	}
	return false;
}

$String* HttpCookie::toString() {
	if (getVersion() > 0) {
		return toRFC2965HeaderString();
	} else {
		return toNetscapeHeaderString();
	}
}

bool HttpCookie::equals(Object$* obj) {
	$useLocalCurrentObjectStackCache();
	if ($equals(obj, this)) {
		return true;
	}
	$var(HttpCookie, other, nullptr);
	bool var$0 = $instanceOf(HttpCookie, obj);
	if (var$0) {
		$assign(other, $cast(HttpCookie, obj));
		var$0 = true;
	}
	if (!(var$0)) {
		return false;
	}
	$var($String, var$3, getName());
	bool var$2 = equalsIgnoreCase(var$3, $($nc(other)->getName()));
	if (var$2) {
		$var($String, var$4, getDomain());
		var$2 = equalsIgnoreCase(var$4, $($nc(other)->getDomain()));
	}
	bool var$1 = var$2;
	if (var$1) {
		$var($Object, var$5, $of(getPath()));
		var$1 = $Objects::equals(var$5, $($nc(other)->getPath()));
	}
	return var$1;
}

int32_t HttpCookie::hashCode() {
	$useLocalCurrentObjectStackCache();
	int32_t h1 = $($nc(this->name)->toLowerCase())->hashCode();
	int32_t h2 = (this->domain != nullptr) ? $($nc(this->domain)->toLowerCase())->hashCode() : 0;
	int32_t h3 = (this->path != nullptr) ? $nc(this->path)->hashCode() : 0;
	return h1 + h2 + h3;
}

$Object* HttpCookie::clone() {
	try {
		return $of($Cloneable::clone());
	} catch ($CloneNotSupportedException& e) {
		$throwNew($RuntimeException, $(e->getMessage()));
	}
	$shouldNotReachHere();
}

int64_t HttpCookie::getCreationTime() {
	return this->whenCreated;
}

bool HttpCookie::isToken($String* value) {
	$init(HttpCookie);
	int32_t len = $nc(value)->length();
	for (int32_t i = 0; i < len; ++i) {
		char16_t c = value->charAt(i);
		if (c < 32 || c >= 127 || $nc(HttpCookie::tspecials)->indexOf((int32_t)c) != -1) {
			return false;
		}
	}
	return true;
}

HttpCookie* HttpCookie::parseInternal($String* header, bool retainHeader) {
	$init(HttpCookie);
	$useLocalCurrentObjectStackCache();
	$var(HttpCookie, cookie, nullptr);
	$var($String, namevaluePair, nullptr);
	$var($StringTokenizer, tokenizer, $new($StringTokenizer, header, ";"_s));
	try {
		$assign(namevaluePair, tokenizer->nextToken());
		int32_t index = $nc(namevaluePair)->indexOf((int32_t)u'=');
		if (index != -1) {
			$var($String, name, $(namevaluePair->substring(0, index))->trim());
			$var($String, value, $(namevaluePair->substring(index + 1))->trim());
			if (retainHeader) {
				$assign(cookie, $new(HttpCookie, name, $(stripOffSurroundingQuote(value)), header));
			} else {
				$assign(cookie, $new(HttpCookie, name, $(stripOffSurroundingQuote(value))));
			}
		} else {
			$throwNew($IllegalArgumentException, "Invalid cookie name-value pair"_s);
		}
	} catch ($NoSuchElementException& ignored) {
		$throwNew($IllegalArgumentException, "Empty cookie header string"_s);
	}
	while (tokenizer->hasMoreTokens()) {
		$assign(namevaluePair, tokenizer->nextToken());
		int32_t index = $nc(namevaluePair)->indexOf((int32_t)u'=');
		$var($String, name, nullptr);
		$var($String, value, nullptr);
		if (index != -1) {
			$assign(name, $(namevaluePair->substring(0, index))->trim());
			$assign(value, $(namevaluePair->substring(index + 1))->trim());
		} else {
			$assign(name, namevaluePair->trim());
			$assign(value, nullptr);
		}
		assignAttribute(cookie, name, value);
	}
	return cookie;
}

void HttpCookie::assignAttribute(HttpCookie* cookie, $String* attrName, $String* attrValue$renamed) {
	$init(HttpCookie);
	$useLocalCurrentObjectStackCache();
	$var($String, attrValue, attrValue$renamed);
	$assign(attrValue, stripOffSurroundingQuote(attrValue));
	$var($HttpCookie$CookieAttributeAssignor, assignor, $cast($HttpCookie$CookieAttributeAssignor, $nc(HttpCookie::assignors)->get($($nc(attrName)->toLowerCase()))));
	if (assignor != nullptr) {
		assignor->assign(cookie, attrName, attrValue);
	} else {
	}
}

$String* HttpCookie::header() {
	return this->header$;
}

$String* HttpCookie::toNetscapeHeaderString() {
	$useLocalCurrentObjectStackCache();
	$var($String, var$0, $$str({$(getName()), "="_s}));
	return $concat(var$0, $(getValue()));
}

$String* HttpCookie::toRFC2965HeaderString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append($(getName()))->append("=\""_s)->append($(getValue()))->append(u'\"');
	if (getPath() != nullptr) {
		sb->append(";$Path=\""_s)->append($(getPath()))->append(u'\"');
	}
	if (getDomain() != nullptr) {
		sb->append(";$Domain=\""_s)->append($(getDomain()))->append(u'\"');
	}
	if (getPortlist() != nullptr) {
		sb->append(";$Port=\""_s)->append($(getPortlist()))->append(u'\"');
	}
	return sb->toString();
}

int64_t HttpCookie::expiryDate2DeltaSeconds($String* dateString) {
	$useLocalCurrentObjectStackCache();
	$var($Calendar, cal, $new($GregorianCalendar, HttpCookie::GMT));
	for (int32_t i = 0; i < $nc(HttpCookie::COOKIE_DATE_FORMATS)->length; ++i) {
		$init($Locale);
		$var($SimpleDateFormat, df, $new($SimpleDateFormat, $nc(HttpCookie::COOKIE_DATE_FORMATS)->get(i), $Locale::US));
		cal->set(1970, 0, 1, 0, 0, 0);
		df->setTimeZone(HttpCookie::GMT);
		df->setLenient(false);
		df->set2DigitYearStart($(cal->getTime()));
		try {
			cal->setTime($(df->parse(dateString)));
			if (!$nc($nc(HttpCookie::COOKIE_DATE_FORMATS)->get(i))->contains("yyyy"_s)) {
				int32_t year = cal->get($Calendar::YEAR);
				$modAssign(year, 100);
				if (year < 70) {
					year += 2000;
				} else {
					year += 1900;
				}
				cal->set($Calendar::YEAR, year);
			}
			return (cal->getTimeInMillis() - this->whenCreated) / 1000;
		} catch ($Exception& e) {
		}
	}
	return 0;
}

int32_t HttpCookie::guessCookieVersion($String* header$renamed) {
	$init(HttpCookie);
	$var($String, header, header$renamed);
	int32_t version = 0;
	$assign(header, $nc(header)->toLowerCase());
	if (header->indexOf("expires="_s) != -1) {
		version = 0;
	} else if (header->indexOf("version="_s) != -1) {
		version = 1;
	} else if (header->indexOf("max-age"_s) != -1) {
		version = 1;
	} else {
		if (startsWithIgnoreCase(header, HttpCookie::SET_COOKIE2)) {
			version = 1;
		}
	}
	return version;
}

$String* HttpCookie::stripOffSurroundingQuote($String* str) {
	$init(HttpCookie);
	bool var$1 = str != nullptr && str->length() > 2;
	bool var$0 = var$1 && str->charAt(0) == u'\"';
	if (var$0 && str->charAt(str->length() - 1) == u'\"') {
		return str->substring(1, str->length() - 1);
	}
	bool var$3 = str != nullptr && str->length() > 2;
	bool var$2 = var$3 && str->charAt(0) == u'\'';
	if (var$2 && str->charAt(str->length() - 1) == u'\'') {
		return str->substring(1, str->length() - 1);
	}
	return str;
}

bool HttpCookie::equalsIgnoreCase($String* s, $String* t) {
	$init(HttpCookie);
	if (s == t) {
		return true;
	}
	if ((s != nullptr) && (t != nullptr)) {
		return s->equalsIgnoreCase(t);
	}
	return false;
}

bool HttpCookie::startsWithIgnoreCase($String* s, $String* start) {
	$init(HttpCookie);
	if (s == nullptr || start == nullptr) {
		return false;
	}
	int32_t var$1 = $nc(s)->length();
	bool var$0 = var$1 >= $nc(start)->length();
	if (var$0 && start->equalsIgnoreCase($(s->substring(0, start->length())))) {
		return true;
	}
	return false;
}

$List* HttpCookie::splitMultiCookies($String* header) {
	$init(HttpCookie);
	$useLocalCurrentObjectStackCache();
	$var($List, cookies, $new($ArrayList));
	int32_t quoteCount = 0;
	int32_t p = 0;
	int32_t q = 0;
	for (p = 0, q = 0; p < $nc(header)->length(); ++p) {
		char16_t c = header->charAt(p);
		if (c == u'\"') {
			++quoteCount;
		}
		if (c == u',' && (quoteCount % 2 == 0)) {
			cookies->add($(header->substring(q, p)));
			q = p + 1;
		}
	}
	cookies->add($($nc(header)->substring(q)));
	return cookies;
}

void clinit$HttpCookie($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(HttpCookie::SET_COOKIE, "set-cookie:"_s);
	$assignStatic(HttpCookie::SET_COOKIE2, "set-cookie2:"_s);
	$assignStatic(HttpCookie::tspecials, ",; "_s);
	$assignStatic(HttpCookie::COOKIE_DATE_FORMATS, $new($StringArray, {
		"EEE\',\' dd-MMM-yyyy HH:mm:ss \'GMT\'"_s,
		"EEE\',\' dd MMM yyyy HH:mm:ss \'GMT\'"_s,
		"EEE MMM dd yyyy HH:mm:ss \'GMT\'Z"_s,
		"EEE\',\' dd-MMM-yy HH:mm:ss \'GMT\'"_s,
		"EEE\',\' dd MMM yy HH:mm:ss \'GMT\'"_s,
		"EEE MMM dd yy HH:mm:ss \'GMT\'Z"_s
	}));
	$assignStatic(HttpCookie::assignors, $new($HashMap));
	{
		$nc(HttpCookie::assignors)->put("comment"_s, $$new($HttpCookie$1));
		$nc(HttpCookie::assignors)->put("commenturl"_s, $$new($HttpCookie$2));
		$nc(HttpCookie::assignors)->put("discard"_s, $$new($HttpCookie$3));
		$nc(HttpCookie::assignors)->put("domain"_s, $$new($HttpCookie$4));
		$nc(HttpCookie::assignors)->put("max-age"_s, $$new($HttpCookie$5));
		$nc(HttpCookie::assignors)->put("path"_s, $$new($HttpCookie$6));
		$nc(HttpCookie::assignors)->put("port"_s, $$new($HttpCookie$7));
		$nc(HttpCookie::assignors)->put("secure"_s, $$new($HttpCookie$8));
		$nc(HttpCookie::assignors)->put("httponly"_s, $$new($HttpCookie$9));
		$nc(HttpCookie::assignors)->put("version"_s, $$new($HttpCookie$10));
		$nc(HttpCookie::assignors)->put("expires"_s, $$new($HttpCookie$11));
	}
	{
		$SharedSecrets::setJavaNetHttpCookieAccess($$new($HttpCookie$12));
	}
	$assignStatic(HttpCookie::GMT, $TimeZone::getTimeZone("GMT"_s));
}

HttpCookie::HttpCookie() {
}

$Class* HttpCookie::load$($String* name, bool initialize) {
	$loadClass(HttpCookie, name, initialize, &_HttpCookie_ClassInfo_, clinit$HttpCookie, allocate$HttpCookie);
	return class$;
}

$Class* HttpCookie::class$ = nullptr;

	} // net
} // java