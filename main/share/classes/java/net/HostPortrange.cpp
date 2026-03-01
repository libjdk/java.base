#include <java/net/HostPortrange.h>

#include <java/lang/Appendable.h>
#include <java/lang/CharSequence.h>
#include <java/util/Formatter.h>
#include <java/util/Locale.h>
#include <sun/net/util/IPAddressUtil.h>
#include <jcpp.h>

#undef CASE_DIFF
#undef HTTPS_PORT
#undef HTTP_PORT
#undef NO_PORT
#undef PORT_MAX
#undef PORT_MIN
#undef US

using $Appendable = ::java::lang::Appendable;
using $Byte = ::java::lang::Byte;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $Formatter = ::java::util::Formatter;
using $Locale = ::java::util::Locale;
using $IPAddressUtil = ::sun::net::util::IPAddressUtil;

namespace java {
	namespace net {

$FieldInfo _HostPortrange_FieldInfo_[] = {
	{"hostname", "Ljava/lang/String;", nullptr, 0, $field(HostPortrange, hostname$)},
	{"scheme", "Ljava/lang/String;", nullptr, 0, $field(HostPortrange, scheme)},
	{"portrange", "[I", nullptr, 0, $field(HostPortrange, portrange$)},
	{"wildcard", "Z", nullptr, 0, $field(HostPortrange, wildcard$)},
	{"literal", "Z", nullptr, 0, $field(HostPortrange, literal$)},
	{"ipv6", "Z", nullptr, 0, $field(HostPortrange, ipv6)},
	{"ipv4", "Z", nullptr, 0, $field(HostPortrange, ipv4)},
	{"PORT_MIN", "I", nullptr, $STATIC | $FINAL, $constField(HostPortrange, PORT_MIN)},
	{"PORT_MAX", "I", nullptr, $STATIC | $FINAL, $constField(HostPortrange, PORT_MAX)},
	{"CASE_DIFF", "I", nullptr, $STATIC | $FINAL, $constField(HostPortrange, CASE_DIFF)},
	{"HTTP_PORT", "[I", nullptr, $STATIC | $FINAL, $staticField(HostPortrange, HTTP_PORT)},
	{"HTTPS_PORT", "[I", nullptr, $STATIC | $FINAL, $staticField(HostPortrange, HTTPS_PORT)},
	{"NO_PORT", "[I", nullptr, $STATIC | $FINAL, $staticField(HostPortrange, NO_PORT)},
	{}
};

$MethodInfo _HostPortrange_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, 0, $method(HostPortrange, init$, void, $String*, $String*)},
	{"defaultPort", "()[I", nullptr, 0, $virtualMethod(HostPortrange, defaultPort, $ints*)},
	{"equals", "(Ljava/net/HostPortrange;)Z", nullptr, 0, $virtualMethod(HostPortrange, equals, bool, HostPortrange*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(HostPortrange, hashCode, int32_t)},
	{"hostname", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(HostPortrange, hostname, $String*)},
	{"ipv4Literal", "()Z", nullptr, $PUBLIC, $virtualMethod(HostPortrange, ipv4Literal, bool)},
	{"ipv6Literal", "()Z", nullptr, $PUBLIC, $virtualMethod(HostPortrange, ipv6Literal, bool)},
	{"literal", "()Z", nullptr, $PUBLIC, $virtualMethod(HostPortrange, literal, bool)},
	{"parsePort", "(Ljava/lang/String;)[I", nullptr, 0, $virtualMethod(HostPortrange, parsePort, $ints*, $String*)},
	{"portrange", "()[I", nullptr, $PUBLIC, $virtualMethod(HostPortrange, portrange, $ints*)},
	{"toLowerCase", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $STATIC, $staticMethod(HostPortrange, toLowerCase, $String*, $String*)},
	{"wildcard", "()Z", nullptr, $PUBLIC, $virtualMethod(HostPortrange, wildcard, bool)},
	{}
};

$ClassInfo _HostPortrange_ClassInfo_ = {
	$ACC_SUPER,
	"java.net.HostPortrange",
	"java.lang.Object",
	nullptr,
	_HostPortrange_FieldInfo_,
	_HostPortrange_MethodInfo_
};

$Object* allocate$HostPortrange($Class* clazz) {
	return $of($alloc(HostPortrange));
}

$ints* HostPortrange::HTTP_PORT = nullptr;
$ints* HostPortrange::HTTPS_PORT = nullptr;
$ints* HostPortrange::NO_PORT = nullptr;

bool HostPortrange::equals(HostPortrange* that) {
	return $nc(this->hostname$)->equals($nc(that)->hostname$) && $nc(this->portrange$)->get(0) == $nc($nc(that)->portrange$)->get(0) && $nc(this->portrange$)->get(1) == $nc(that->portrange$)->get(1) && this->wildcard$ == that->wildcard$ && this->literal$ == that->literal$;
}

int32_t HostPortrange::hashCode() {
	return $nc(this->hostname$)->hashCode() + $nc(this->portrange$)->get(0) + $nc(this->portrange$)->get(1);
}

void HostPortrange::init$($String* scheme, $String* str) {
	$useLocalCurrentObjectStackCache();
	$var($String, hoststr, nullptr);
	$var($String, portstr, nullptr);
	$set(this, scheme, scheme);
	if ($nc(str)->charAt(0) == u'[') {
		this->ipv6 = (this->literal$ = true);
		int32_t rb = str->indexOf((int32_t)u']');
		if (rb != -1) {
			$assign(hoststr, str->substring(1, rb));
		} else {
			$throwNew($IllegalArgumentException, $$str({"invalid IPv6 address: "_s, str}));
		}
		int32_t sep = str->indexOf((int32_t)u':', rb + 1);
		if (sep != -1 && str->length() > sep) {
			$assign(portstr, str->substring(sep + 1));
		}
		$var($bytes, ip, $IPAddressUtil::textToNumericFormatV6(hoststr));
		if (ip == nullptr) {
			$throwNew($IllegalArgumentException, "illegal IPv6 address"_s);
		}
		$var($StringBuilder, sb, $new($StringBuilder));
		$init($Locale);
		$var($Formatter, formatter, $new($Formatter, static_cast<$Appendable*>(sb), $Locale::US));
		formatter->format("%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x"_s, $$new($ObjectArray, {
			$($of($Byte::valueOf($nc(ip)->get(0)))),
			$($of($Byte::valueOf($nc(ip)->get(1)))),
			$($of($Byte::valueOf($nc(ip)->get(2)))),
			$($of($Byte::valueOf($nc(ip)->get(3)))),
			$($of($Byte::valueOf($nc(ip)->get(4)))),
			$($of($Byte::valueOf($nc(ip)->get(5)))),
			$($of($Byte::valueOf($nc(ip)->get(6)))),
			$($of($Byte::valueOf($nc(ip)->get(7)))),
			$($of($Byte::valueOf($nc(ip)->get(8)))),
			$($of($Byte::valueOf($nc(ip)->get(9)))),
			$($of($Byte::valueOf($nc(ip)->get(10)))),
			$($of($Byte::valueOf($nc(ip)->get(11)))),
			$($of($Byte::valueOf($nc(ip)->get(12)))),
			$($of($Byte::valueOf($nc(ip)->get(13)))),
			$($of($Byte::valueOf($nc(ip)->get(14)))),
			$($of($Byte::valueOf($nc(ip)->get(15))))
		}));
		$set(this, hostname$, sb->toString());
	} else {
		int32_t sep = str->indexOf((int32_t)u':');
		if (sep != -1 && str->length() > sep) {
			$assign(hoststr, str->substring(0, sep));
			$assign(portstr, str->substring(sep + 1));
		} else {
			$assign(hoststr, sep == -1 ? str : str->substring(0, sep));
		}
		if ($nc(hoststr)->lastIndexOf((int32_t)u'*') > 0) {
			$throwNew($IllegalArgumentException, "invalid host wildcard specification"_s);
		} else if (hoststr->startsWith("*"_s)) {
			this->wildcard$ = true;
			if (hoststr->equals("*"_s)) {
				$assign(hoststr, ""_s);
			} else if (hoststr->startsWith("*."_s)) {
				$assign(hoststr, toLowerCase($(hoststr->substring(1))));
			} else {
				$throwNew($IllegalArgumentException, "invalid host wildcard specification"_s);
			}
		} else {
			int32_t lastdot = hoststr->lastIndexOf((int32_t)u'.');
			if (lastdot != -1 && (hoststr->length() > 1)) {
				bool ipv4 = true;
				{
					int32_t i = lastdot + 1;
					int32_t len = hoststr->length();
					for (; i < len; ++i) {
						char16_t c = hoststr->charAt(i);
						if (c < u'0' || c > u'9') {
							ipv4 = false;
							break;
						}
					}
				}
				this->ipv4 = (this->literal$ = ipv4);
				if (ipv4) {
					$var($bytes, ip, $IPAddressUtil::textToNumericFormatV4(hoststr));
					if (ip == nullptr) {
						$throwNew($IllegalArgumentException, "illegal IPv4 address"_s);
					}
					$var($StringBuilder, sb, $new($StringBuilder));
					$init($Locale);
					$var($Formatter, formatter, $new($Formatter, static_cast<$Appendable*>(sb), $Locale::US));
					formatter->format("%d.%d.%d.%d"_s, $$new($ObjectArray, {
						$($of($Byte::valueOf($nc(ip)->get(0)))),
						$($of($Byte::valueOf($nc(ip)->get(1)))),
						$($of($Byte::valueOf($nc(ip)->get(2)))),
						$($of($Byte::valueOf($nc(ip)->get(3))))
					}));
					$assign(hoststr, sb->toString());
				} else {
					$assign(hoststr, toLowerCase(hoststr));
				}
			}
		}
		$set(this, hostname$, hoststr);
	}
	try {
		$set(this, portrange$, parsePort(portstr));
	} catch ($Exception& e) {
		$throwNew($IllegalArgumentException, $$str({"invalid port range: "_s, portstr}));
	}
}

$String* HostPortrange::toLowerCase($String* s) {
	$init(HostPortrange);
	int32_t len = $nc(s)->length();
	$var($StringBuilder, sb, nullptr);
	for (int32_t i = 0; i < len; ++i) {
		char16_t c = s->charAt(i);
		if ((c >= u'a' && c <= u'z') || (c == u'.')) {
			if (sb != nullptr) {
				sb->append(c);
			}
		} else if ((c >= u'0' && c <= u'9') || (c == u'-')) {
			if (sb != nullptr) {
				sb->append(c);
			}
		} else if (c >= u'A' && c <= u'Z') {
			if (sb == nullptr) {
				$assign(sb, $new($StringBuilder, len));
				sb->append(static_cast<$CharSequence*>(s), 0, i);
			}
			$nc(sb)->append((char16_t)(c - HostPortrange::CASE_DIFF));
		} else {
			$throwNew($IllegalArgumentException, "Invalid characters in hostname"_s);
		}
	}
	return sb == nullptr ? s : $nc(sb)->toString();
}

bool HostPortrange::literal() {
	return this->literal$;
}

bool HostPortrange::ipv4Literal() {
	return this->ipv4;
}

bool HostPortrange::ipv6Literal() {
	return this->ipv6;
}

$String* HostPortrange::hostname() {
	return this->hostname$;
}

$ints* HostPortrange::portrange() {
	return this->portrange$;
}

bool HostPortrange::wildcard() {
	return this->wildcard$;
}

$ints* HostPortrange::defaultPort() {
	if ($nc(this->scheme)->equals("http"_s)) {
		return HostPortrange::HTTP_PORT;
	} else if ($nc(this->scheme)->equals("https"_s)) {
		return HostPortrange::HTTPS_PORT;
	}
	return HostPortrange::NO_PORT;
}

$ints* HostPortrange::parsePort($String* port) {
	$useLocalCurrentObjectStackCache();
	if (port == nullptr || $nc(port)->isEmpty()) {
		return defaultPort();
	}
	if ($nc(port)->equals("*"_s)) {
		return $new($ints, {
			HostPortrange::PORT_MIN,
			HostPortrange::PORT_MAX
		});
	}
	try {
		int32_t dash = $nc(port)->indexOf((int32_t)u'-');
		if (dash == -1) {
			int32_t p = $Integer::parseInt(port);
			return $new($ints, {
				p,
				p
			});
		} else {
			$var($String, low, port->substring(0, dash));
			$var($String, high, port->substring(dash + 1));
			int32_t l = 0;
			int32_t h = 0;
			if (low->isEmpty()) {
				l = HostPortrange::PORT_MIN;
			} else {
				l = $Integer::parseInt(low);
			}
			if (high->isEmpty()) {
				h = HostPortrange::PORT_MAX;
			} else {
				h = $Integer::parseInt(high);
			}
			if (l < 0 || h < 0 || h < l) {
				return defaultPort();
			}
			return $new($ints, {
				l,
				h
			});
		}
	} catch ($IllegalArgumentException& e) {
		return defaultPort();
	}
	$shouldNotReachHere();
}

void clinit$HostPortrange($Class* class$) {
	$assignStatic(HostPortrange::HTTP_PORT, $new($ints, {
		80,
		80
	}));
	$assignStatic(HostPortrange::HTTPS_PORT, $new($ints, {
		443,
		443
	}));
	$assignStatic(HostPortrange::NO_PORT, $new($ints, {
		-1,
		-1
	}));
}

HostPortrange::HostPortrange() {
}

$Class* HostPortrange::load$($String* name, bool initialize) {
	$loadClass(HostPortrange, name, initialize, &_HostPortrange_ClassInfo_, clinit$HostPortrange, allocate$HostPortrange);
	return class$;
}

$Class* HostPortrange::class$ = nullptr;

	} // net
} // java