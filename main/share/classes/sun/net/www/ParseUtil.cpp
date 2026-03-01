#include <sun/net/www/ParseUtil.h>

#include <java/io/File.h>
#include <java/lang/Appendable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/CharSequence.h>
#include <java/lang/NumberFormatException.h>
#include <java/net/URI.h>
#include <java/net/URISyntaxException.h>
#include <java/net/URL.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/CharBuffer.h>
#include <java/nio/charset/CharacterCodingException.h>
#include <java/nio/charset/CharsetDecoder.h>
#include <java/nio/charset/CharsetEncoder.h>
#include <java/nio/charset/CoderResult.h>
#include <java/nio/charset/CodingErrorAction.h>
#include <java/util/HexFormat.h>
#include <sun/nio/cs/UTF_8.h>
#include <jcpp.h>

#undef HEX_UPPERCASE
#undef H_ALPHA
#undef H_ALPHANUM
#undef H_DASH
#undef H_DIGIT
#undef H_ENCODED
#undef H_ESCAPED
#undef H_HEX
#undef H_LOWALPHA
#undef H_MARK
#undef H_PATH
#undef H_PCHAR
#undef H_REG_NAME
#undef H_RESERVED
#undef H_SERVER
#undef H_UNRESERVED
#undef H_UPALPHA
#undef H_URIC
#undef H_USERINFO
#undef INSTANCE
#undef L_ALPHA
#undef L_ALPHANUM
#undef L_DASH
#undef L_DIGIT
#undef L_ENCODED
#undef L_ESCAPED
#undef L_HEX
#undef L_LOWALPHA
#undef L_MARK
#undef L_PATH
#undef L_PCHAR
#undef L_REG_NAME
#undef L_RESERVED
#undef L_SERVER
#undef L_UNRESERVED
#undef L_UPALPHA
#undef L_URIC
#undef L_USERINFO
#undef MAX_VALUE
#undef REPORT

using $File = ::java::io::File;
using $Appendable = ::java::lang::Appendable;
using $AssertionError = ::java::lang::AssertionError;
using $CharSequence = ::java::lang::CharSequence;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $URI = ::java::net::URI;
using $URISyntaxException = ::java::net::URISyntaxException;
using $URL = ::java::net::URL;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $CharBuffer = ::java::nio::CharBuffer;
using $CharacterCodingException = ::java::nio::charset::CharacterCodingException;
using $CharsetDecoder = ::java::nio::charset::CharsetDecoder;
using $CharsetEncoder = ::java::nio::charset::CharsetEncoder;
using $CoderResult = ::java::nio::charset::CoderResult;
using $CodingErrorAction = ::java::nio::charset::CodingErrorAction;
using $HexFormat = ::java::util::HexFormat;
using $UTF_8 = ::sun::nio::cs::UTF_8;

namespace sun {
	namespace net {
		namespace www {

$FieldInfo _ParseUtil_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(ParseUtil, $assertionsDisabled)},
	{"HEX_UPPERCASE", "Ljava/util/HexFormat;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ParseUtil, HEX_UPPERCASE)},
	{"L_DIGIT", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ParseUtil, L_DIGIT)},
	{"H_DIGIT", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ParseUtil, H_DIGIT)},
	{"L_HEX", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ParseUtil, L_HEX)},
	{"H_HEX", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ParseUtil, H_HEX)},
	{"L_UPALPHA", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ParseUtil, L_UPALPHA)},
	{"H_UPALPHA", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ParseUtil, H_UPALPHA)},
	{"L_LOWALPHA", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ParseUtil, L_LOWALPHA)},
	{"H_LOWALPHA", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ParseUtil, H_LOWALPHA)},
	{"L_ALPHA", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ParseUtil, L_ALPHA)},
	{"H_ALPHA", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ParseUtil, H_ALPHA)},
	{"L_ALPHANUM", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ParseUtil, L_ALPHANUM)},
	{"H_ALPHANUM", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ParseUtil, H_ALPHANUM)},
	{"L_MARK", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ParseUtil, L_MARK)},
	{"H_MARK", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ParseUtil, H_MARK)},
	{"L_UNRESERVED", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ParseUtil, L_UNRESERVED)},
	{"H_UNRESERVED", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ParseUtil, H_UNRESERVED)},
	{"L_RESERVED", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ParseUtil, L_RESERVED)},
	{"H_RESERVED", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ParseUtil, H_RESERVED)},
	{"L_ESCAPED", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ParseUtil, L_ESCAPED)},
	{"H_ESCAPED", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ParseUtil, H_ESCAPED)},
	{"L_URIC", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ParseUtil, L_URIC)},
	{"H_URIC", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ParseUtil, H_URIC)},
	{"L_PCHAR", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ParseUtil, L_PCHAR)},
	{"H_PCHAR", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ParseUtil, H_PCHAR)},
	{"L_PATH", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ParseUtil, L_PATH)},
	{"H_PATH", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ParseUtil, H_PATH)},
	{"L_DASH", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ParseUtil, L_DASH)},
	{"H_DASH", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ParseUtil, H_DASH)},
	{"L_USERINFO", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ParseUtil, L_USERINFO)},
	{"H_USERINFO", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ParseUtil, H_USERINFO)},
	{"L_REG_NAME", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ParseUtil, L_REG_NAME)},
	{"H_REG_NAME", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ParseUtil, H_REG_NAME)},
	{"L_SERVER", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ParseUtil, L_SERVER)},
	{"H_SERVER", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ParseUtil, H_SERVER)},
	{"L_ENCODED", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ParseUtil, L_ENCODED)},
	{"H_ENCODED", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ParseUtil, H_ENCODED)},
	{}
};

$MethodInfo _ParseUtil_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(ParseUtil, init$, void)},
	{"appendAuthority", "(Ljava/lang/StringBuilder;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;I)V", nullptr, $PRIVATE | $STATIC, $staticMethod(ParseUtil, appendAuthority, void, $StringBuilder*, $String*, $String*, $String*, int32_t)},
	{"appendEncoded", "(Ljava/nio/charset/CharsetEncoder;Ljava/lang/StringBuilder;C)V", nullptr, $PRIVATE | $STATIC, $staticMethod(ParseUtil, appendEncoded, void, $CharsetEncoder*, $StringBuilder*, char16_t)},
	{"appendEscape", "(Ljava/lang/StringBuilder;B)V", nullptr, $PRIVATE | $STATIC, $staticMethod(ParseUtil, appendEscape, void, $StringBuilder*, int8_t)},
	{"appendFragment", "(Ljava/lang/StringBuilder;Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(ParseUtil, appendFragment, void, $StringBuilder*, $String*)},
	{"appendSchemeSpecificPart", "(Ljava/lang/StringBuilder;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;ILjava/lang/String;Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(ParseUtil, appendSchemeSpecificPart, void, $StringBuilder*, $String*, $String*, $String*, $String*, int32_t, $String*, $String*)},
	{"checkPath", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(ParseUtil, checkPath, void, $String*, $String*, $String*), "java.net.URISyntaxException"},
	{"createURI", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/net/URI;", nullptr, $PRIVATE | $STATIC, $staticMethod(ParseUtil, createURI, $URI*, $String*, $String*, $String*, $String*, $String*), "java.net.URISyntaxException"},
	{"decode", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(ParseUtil, decode, $String*, $String*)},
	{"encodePath", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(ParseUtil, encodePath, $String*, $String*)},
	{"encodePath", "(Ljava/lang/String;Z)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(ParseUtil, encodePath, $String*, $String*, bool)},
	{"encodePath", "(Ljava/lang/String;IC)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(ParseUtil, encodePath, $String*, $String*, int32_t, char16_t)},
	{"escape", "([CCI)I", nullptr, $PRIVATE | $STATIC, $staticMethod(ParseUtil, escape, int32_t, $chars*, char16_t, int32_t)},
	{"fileToEncodedURL", "(Ljava/io/File;)Ljava/net/URL;", nullptr, $PUBLIC | $STATIC, $staticMethod(ParseUtil, fileToEncodedURL, $URL*, $File*), "java.net.MalformedURLException"},
	{"firstEncodeIndex", "(Ljava/lang/String;)I", nullptr, $PRIVATE | $STATIC, $staticMethod(ParseUtil, firstEncodeIndex, int32_t, $String*)},
	{"isEscaped", "(Ljava/lang/String;I)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(ParseUtil, isEscaped, bool, $String*, int32_t)},
	{"match", "(CJJ)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(ParseUtil, match, bool, char16_t, int64_t, int64_t)},
	{"quote", "(Ljava/lang/String;JJ)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(ParseUtil, quote, $String*, $String*, int64_t, int64_t)},
	{"toString", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(ParseUtil, toString, $String*, $String*, $String*, $String*, $String*, $String*, int32_t, $String*, $String*, $String*)},
	{"toURI", "(Ljava/net/URL;)Ljava/net/URI;", nullptr, $PUBLIC | $STATIC, $staticMethod(ParseUtil, toURI, $URI*, $URL*)},
	{"unescape", "(Ljava/lang/String;I)B", nullptr, $PRIVATE | $STATIC, $staticMethod(ParseUtil, unescape, int8_t, $String*, int32_t)},
	{}
};

$ClassInfo _ParseUtil_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.net.www.ParseUtil",
	"java.lang.Object",
	nullptr,
	_ParseUtil_FieldInfo_,
	_ParseUtil_MethodInfo_
};

$Object* allocate$ParseUtil($Class* clazz) {
	return $of($alloc(ParseUtil));
}

bool ParseUtil::$assertionsDisabled = false;
$HexFormat* ParseUtil::HEX_UPPERCASE = nullptr;

void ParseUtil::init$() {
}

$String* ParseUtil::encodePath($String* path) {
	$init(ParseUtil);
	return encodePath(path, true);
}

$String* ParseUtil::encodePath($String* path, bool flag) {
	$init(ParseUtil);
	$init($File);
	if (flag && $File::separatorChar != u'/') {
		return encodePath(path, 0, $File::separatorChar);
	} else {
		int32_t index = firstEncodeIndex(path);
		if (index > -1) {
			return encodePath(path, index, u'/');
		} else {
			return path;
		}
	}
}

int32_t ParseUtil::firstEncodeIndex($String* path) {
	$init(ParseUtil);
	int32_t len = $nc(path)->length();
	for (int32_t i = 0; i < len; ++i) {
		char16_t c = path->charAt(i);
		if (c >= u'a' && c <= u'z' || c >= u'&' && c <= u':' || c >= u'A' && c <= u'Z') {
			continue;
		} else if (c > 127 || match(c, ParseUtil::L_ENCODED, ParseUtil::H_ENCODED)) {
			return i;
		}
	}
	return -1;
}

$String* ParseUtil::encodePath($String* path, int32_t index, char16_t sep) {
	$init(ParseUtil);
	$useLocalCurrentObjectStackCache();
	$var($chars, pathCC, $nc(path)->toCharArray());
	$var($chars, retCC, $new($chars, pathCC->length * 2 + 16 - index));
	if (index > 0) {
		$System::arraycopy(pathCC, 0, retCC, 0, index);
	}
	int32_t retLen = index;
	for (int32_t i = index; i < pathCC->length; ++i) {
		char16_t c = pathCC->get(i);
		if (c == sep) {
			$nc(retCC)->set(retLen++, u'/');
		} else if (c <= 127) {
			if (c >= u'a' && c <= u'z' || c >= u'A' && c <= u'Z' || c >= u'0' && c <= u'9') {
				$nc(retCC)->set(retLen++, c);
			} else if (match(c, ParseUtil::L_ENCODED, ParseUtil::H_ENCODED)) {
				retLen = escape(retCC, c, retLen);
			} else {
				$nc(retCC)->set(retLen++, c);
			}
		} else if (c > 2047) {
			retLen = escape(retCC, (char16_t)(224 | ((int32_t)((c >> 12) & (uint32_t)15))), retLen);
			retLen = escape(retCC, (char16_t)(128 | ((int32_t)((c >> 6) & (uint32_t)63))), retLen);
			retLen = escape(retCC, (char16_t)(128 | ((int32_t)((c >> 0) & (uint32_t)63))), retLen);
		} else {
			retLen = escape(retCC, (char16_t)(192 | ((int32_t)((c >> 6) & (uint32_t)31))), retLen);
			retLen = escape(retCC, (char16_t)(128 | ((int32_t)((c >> 0) & (uint32_t)63))), retLen);
		}
		if (retLen + 9 > $nc(retCC)->length) {
			int32_t newLen = retCC->length * 2 + 16;
			if (newLen < 0) {
				newLen = $Integer::MAX_VALUE;
			}
			$var($chars, buf, $new($chars, newLen));
			$System::arraycopy(retCC, 0, buf, 0, retLen);
			$assign(retCC, buf);
		}
	}
	return $new($String, retCC, 0, retLen);
}

int32_t ParseUtil::escape($chars* cc, char16_t c, int32_t index) {
	$init(ParseUtil);
	$nc(cc)->set(index++, u'%');
	cc->set(index++, $Character::forDigit((int32_t)((c >> 4) & (uint32_t)15), 16));
	cc->set(index++, $Character::forDigit((int32_t)(c & (uint32_t)15), 16));
	return index;
}

int8_t ParseUtil::unescape($String* s, int32_t i) {
	$init(ParseUtil);
	return (int8_t)$Integer::parseInt(s, i + 1, i + 3, 16);
}

$String* ParseUtil::decode($String* s) {
	$init(ParseUtil);
	$useLocalCurrentObjectStackCache();
	int32_t n = $nc(s)->length();
	if ((n == 0) || (s->indexOf((int32_t)u'%') < 0)) {
		return s;
	}
	$var($StringBuilder, sb, $new($StringBuilder, n));
	$var($ByteBuffer, bb, $ByteBuffer::allocate(n));
	$var($CharBuffer, cb, $CharBuffer::allocate(n));
	$init($UTF_8);
	$init($CodingErrorAction);
	$var($CharsetDecoder, dec, $nc($($nc($($nc($UTF_8::INSTANCE)->newDecoder()))->onMalformedInput($CodingErrorAction::REPORT)))->onUnmappableCharacter($CodingErrorAction::REPORT));
	char16_t c = s->charAt(0);
	for (int32_t i = 0; i < n;) {
		if (!ParseUtil::$assertionsDisabled && !(c == s->charAt(i))) {
			$throwNew($AssertionError);
		}
		if (c != u'%') {
			sb->append(c);
			if (++i >= n) {
				break;
			}
			c = s->charAt(i);
			continue;
		}
		$nc(bb)->clear();
		int32_t ui = i;
		for (;;) {
			if (!ParseUtil::$assertionsDisabled && !(n - i >= 2)) {
				$throwNew($AssertionError);
			}
			try {
				bb->put(unescape(s, i));
			} catch ($NumberFormatException& e) {
				$throwNew($IllegalArgumentException);
			}
			i += 3;
			if (i >= n) {
				break;
			}
			c = s->charAt(i);
			if (c != u'%') {
				break;
			}
		}
		bb->flip();
		$nc(cb)->clear();
		$nc(dec)->reset();
		$var($CoderResult, cr, dec->decode(bb, cb, true));
		if ($nc(cr)->isError()) {
			$throwNew($IllegalArgumentException, "Error decoding percent encoded characters"_s);
		}
		$assign(cr, dec->flush(cb));
		if ($nc(cr)->isError()) {
			$throwNew($IllegalArgumentException, "Error decoding percent encoded characters"_s);
		}
		sb->append($($nc($(cb->flip()))->toString()));
	}
	return sb->toString();
}

$URL* ParseUtil::fileToEncodedURL($File* file) {
	$init(ParseUtil);
	$var($String, path, $nc(file)->getAbsolutePath());
	$assign(path, ParseUtil::encodePath(path));
	if (!$nc(path)->startsWith("/"_s)) {
		$assign(path, $str({"/"_s, path}));
	}
	bool var$0 = !$nc(path)->endsWith("/"_s);
	if (var$0 && file->isDirectory()) {
		$assign(path, $str({path, "/"_s}));
	}
	return $new($URL, "file"_s, ""_s, path);
}

$URI* ParseUtil::toURI($URL* url) {
	$init(ParseUtil);
	$useLocalCurrentObjectStackCache();
	$var($String, protocol, $nc(url)->getProtocol());
	$var($String, auth, url->getAuthority());
	$var($String, path, url->getPath());
	$var($String, query, url->getQuery());
	$var($String, ref, url->getRef());
	if (path != nullptr && !(path->startsWith("/"_s))) {
		$assign(path, $str({"/"_s, path}));
	}
	if (auth != nullptr && auth->endsWith(":-1"_s)) {
		$assign(auth, auth->substring(0, auth->length() - 3));
	}
	$var($URI, uri, nullptr);
	try {
		$assign(uri, createURI(protocol, auth, path, query, ref));
	} catch ($URISyntaxException& e) {
		$assign(uri, nullptr);
	}
	return uri;
}

$URI* ParseUtil::createURI($String* scheme, $String* authority, $String* path, $String* query, $String* fragment) {
	$init(ParseUtil);
	$var($String, s, toString(scheme, nullptr, authority, nullptr, nullptr, -1, path, query, fragment));
	checkPath(s, scheme, path);
	return $new($URI, s);
}

$String* ParseUtil::toString($String* scheme, $String* opaquePart, $String* authority, $String* userInfo, $String* host, int32_t port, $String* path, $String* query, $String* fragment) {
	$init(ParseUtil);
	$var($StringBuilder, sb, $new($StringBuilder));
	if (scheme != nullptr) {
		sb->append(scheme);
		sb->append(u':');
	}
	appendSchemeSpecificPart(sb, opaquePart, authority, userInfo, host, port, path, query);
	appendFragment(sb, fragment);
	return sb->toString();
}

void ParseUtil::appendSchemeSpecificPart($StringBuilder* sb, $String* opaquePart, $String* authority, $String* userInfo, $String* host, int32_t port, $String* path, $String* query) {
	$init(ParseUtil);
	$useLocalCurrentObjectStackCache();
	if (opaquePart != nullptr) {
		if (opaquePart->startsWith("//["_s)) {
			int32_t end = opaquePart->indexOf((int32_t)u']');
			if (end != -1 && opaquePart->indexOf((int32_t)u':') != -1) {
				$var($String, doquote, nullptr);
				$var($String, dontquote, nullptr);
				if (end == opaquePart->length()) {
					$assign(dontquote, opaquePart);
					$assign(doquote, ""_s);
				} else {
					$assign(dontquote, opaquePart->substring(0, end + 1));
					$assign(doquote, opaquePart->substring(end + 1));
				}
				$nc(sb)->append(dontquote);
				sb->append($(quote(doquote, ParseUtil::L_URIC, ParseUtil::H_URIC)));
			}
		} else {
			$nc(sb)->append($(quote(opaquePart, ParseUtil::L_URIC, ParseUtil::H_URIC)));
		}
	} else {
		appendAuthority(sb, authority, userInfo, host, port);
		if (path != nullptr) {
			$nc(sb)->append($(quote(path, ParseUtil::L_PATH, ParseUtil::H_PATH)));
		}
		if (query != nullptr) {
			$nc(sb)->append(u'?');
			sb->append($(quote(query, ParseUtil::L_URIC, ParseUtil::H_URIC)));
		}
	}
}

void ParseUtil::appendAuthority($StringBuilder* sb, $String* authority, $String* userInfo, $String* host, int32_t port) {
	$init(ParseUtil);
	$useLocalCurrentObjectStackCache();
	if (host != nullptr) {
		$nc(sb)->append("//"_s);
		if (userInfo != nullptr) {
			sb->append($(quote(userInfo, ParseUtil::L_USERINFO, ParseUtil::H_USERINFO)));
			sb->append(u'@');
		}
		bool var$1 = (host->indexOf((int32_t)u':') >= 0);
		bool var$0 = var$1 && !host->startsWith("["_s);
		bool needBrackets = (var$0 && !host->endsWith("]"_s));
		if (needBrackets) {
			sb->append(u'[');
		}
		sb->append(host);
		if (needBrackets) {
			sb->append(u']');
		}
		if (port != -1) {
			sb->append(u':');
			sb->append(port);
		}
	} else if (authority != nullptr) {
		$nc(sb)->append("//"_s);
		if (authority->startsWith("["_s)) {
			int32_t end = authority->indexOf((int32_t)u']');
			if (end != -1 && authority->indexOf((int32_t)u':') != -1) {
				$var($String, doquote, nullptr);
				$var($String, dontquote, nullptr);
				if (end == authority->length()) {
					$assign(dontquote, authority);
					$assign(doquote, ""_s);
				} else {
					$assign(dontquote, authority->substring(0, end + 1));
					$assign(doquote, authority->substring(end + 1));
				}
				sb->append(dontquote);
				sb->append($(quote(doquote, ParseUtil::L_REG_NAME | ParseUtil::L_SERVER, ParseUtil::H_REG_NAME | ParseUtil::H_SERVER)));
			}
		} else {
			sb->append($(quote(authority, ParseUtil::L_REG_NAME | ParseUtil::L_SERVER, ParseUtil::H_REG_NAME | ParseUtil::H_SERVER)));
		}
	}
}

void ParseUtil::appendFragment($StringBuilder* sb, $String* fragment) {
	$init(ParseUtil);
	if (fragment != nullptr) {
		$nc(sb)->append(u'#');
		sb->append($(quote(fragment, ParseUtil::L_URIC, ParseUtil::H_URIC)));
	}
}

$String* ParseUtil::quote($String* s, int64_t lowMask, int64_t highMask) {
	$init(ParseUtil);
	$useLocalCurrentObjectStackCache();
	int32_t n = $nc(s)->length();
	$var($StringBuilder, sb, nullptr);
	$var($CharsetEncoder, encoder, nullptr);
	bool allowNonASCII = (((int64_t)(lowMask & (uint64_t)ParseUtil::L_ESCAPED)) != 0);
	for (int32_t i = 0; i < s->length(); ++i) {
		char16_t c = s->charAt(i);
		if (c < (char16_t)0x80) {
			bool var$0 = !match(c, lowMask, highMask);
			if (var$0 && !isEscaped(s, i)) {
				if (sb == nullptr) {
					$assign(sb, $new($StringBuilder));
					sb->append(static_cast<$CharSequence*>(s), 0, i);
				}
				appendEscape(sb, (int8_t)c);
			} else if (sb != nullptr) {
				sb->append(c);
			}
		} else {
			bool var$3 = allowNonASCII;
			if (var$3) {
				bool var$4 = $Character::isSpaceChar(c);
				var$3 = (var$4 || $Character::isISOControl(c));
			}
			if (var$3) {
				if (encoder == nullptr) {
					$init($UTF_8);
					$assign(encoder, $nc($UTF_8::INSTANCE)->newEncoder());
				}
				if (sb == nullptr) {
					$assign(sb, $new($StringBuilder));
					sb->append(static_cast<$CharSequence*>(s), 0, i);
				}
				appendEncoded(encoder, sb, c);
			} else if (sb != nullptr) {
				sb->append(c);
			}
		}
	}
	return (sb == nullptr) ? s : $nc(sb)->toString();
}

bool ParseUtil::isEscaped($String* s, int32_t pos) {
	$init(ParseUtil);
	if (s == nullptr || ($nc(s)->length() <= (pos + 2))) {
		return false;
	}
	bool var$1 = $nc(s)->charAt(pos) == u'%';
	bool var$0 = var$1 && match(s->charAt(pos + 1), ParseUtil::L_HEX, ParseUtil::H_HEX);
	return var$0 && match(s->charAt(pos + 2), ParseUtil::L_HEX, ParseUtil::H_HEX);
}

void ParseUtil::appendEncoded($CharsetEncoder* encoder, $StringBuilder* sb, char16_t c) {
	$init(ParseUtil);
	$useLocalCurrentObjectStackCache();
	$var($ByteBuffer, bb, nullptr);
	try {
		$assign(bb, $nc(encoder)->encode($($CharBuffer::wrap(static_cast<$CharSequence*>($$str({""_s, $$str(c)}))))));
	} catch ($CharacterCodingException& x) {
		if (!ParseUtil::$assertionsDisabled) {
			$throwNew($AssertionError);
		}
	}
	while ($nc(bb)->hasRemaining()) {
		int32_t b = (int32_t)(bb->get() & (uint32_t)255);
		if (b >= 128) {
			appendEscape(sb, (int8_t)b);
		} else {
			$nc(sb)->append((char16_t)b);
		}
	}
}

void ParseUtil::appendEscape($StringBuilder* sb, int8_t b) {
	$init(ParseUtil);
	$nc(sb)->append(u'%');
	$nc(ParseUtil::HEX_UPPERCASE)->toHexDigits(static_cast<$Appendable*>(sb), b);
}

bool ParseUtil::match(char16_t c, int64_t lowMask, int64_t highMask) {
	$init(ParseUtil);
	if (c < 64) {
		return ((int64_t)(($sl((int64_t)1, c)) & (uint64_t)lowMask)) != 0;
	}
	if (c < 128) {
		return ((int64_t)(($sl((int64_t)1, c - 64)) & (uint64_t)highMask)) != 0;
	}
	return false;
}

void ParseUtil::checkPath($String* s, $String* scheme, $String* path) {
	$init(ParseUtil);
	if (scheme != nullptr) {
		bool var$0 = path != nullptr && !path->isEmpty();
		if (var$0 && path->charAt(0) != u'/') {
			$throwNew($URISyntaxException, s, "Relative path in absolute URI"_s);
		}
	}
}

void clinit$ParseUtil($Class* class$) {
	ParseUtil::$assertionsDisabled = !ParseUtil::class$->desiredAssertionStatus();
	$assignStatic(ParseUtil::HEX_UPPERCASE, $nc($($HexFormat::of()))->withUpperCase());
}

ParseUtil::ParseUtil() {
}

$Class* ParseUtil::load$($String* name, bool initialize) {
	$loadClass(ParseUtil, name, initialize, &_ParseUtil_ClassInfo_, clinit$ParseUtil, allocate$ParseUtil);
	return class$;
}

$Class* ParseUtil::class$ = nullptr;

		} // www
	} // net
} // sun