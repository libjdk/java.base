#include <java/net/URLEncoder.h>

#include <java/io/CharArrayWriter.h>
#include <java/io/UnsupportedEncodingException.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/IllegalCharsetNameException.h>
#include <java/nio/charset/UnsupportedCharsetException.h>
#include <java/util/BitSet.h>
#include <java/util/Objects.h>
#include <sun/security/action/GetPropertyAction.h>
#include <jcpp.h>

using $CharArrayWriter = ::java::io::CharArrayWriter;
using $UnsupportedEncodingException = ::java::io::UnsupportedEncodingException;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $Charset = ::java::nio::charset::Charset;
using $IllegalCharsetNameException = ::java::nio::charset::IllegalCharsetNameException;
using $UnsupportedCharsetException = ::java::nio::charset::UnsupportedCharsetException;
using $BitSet = ::java::util::BitSet;
using $Objects = ::java::util::Objects;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;

namespace java {
	namespace net {

$CompoundAttribute _URLEncoder_MethodAnnotations_encode1[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _URLEncoder_FieldInfo_[] = {
	{"dontNeedEncoding", "Ljava/util/BitSet;", nullptr, $STATIC, $staticField(URLEncoder, dontNeedEncoding)},
	{"caseDiff", "I", nullptr, $STATIC | $FINAL, $constField(URLEncoder, caseDiff)},
	{"dfltEncName", "Ljava/lang/String;", nullptr, $STATIC, $staticField(URLEncoder, dfltEncName)},
	{}
};

$MethodInfo _URLEncoder_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(URLEncoder, init$, void)},
	{"encode", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $DEPRECATED, $staticMethod(URLEncoder, encode, $String*, $String*), nullptr, nullptr, _URLEncoder_MethodAnnotations_encode1},
	{"encode", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(URLEncoder, encode, $String*, $String*, $String*), "java.io.UnsupportedEncodingException"},
	{"encode", "(Ljava/lang/String;Ljava/nio/charset/Charset;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(URLEncoder, encode, $String*, $String*, $Charset*)},
	{}
};

$ClassInfo _URLEncoder_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.net.URLEncoder",
	"java.lang.Object",
	nullptr,
	_URLEncoder_FieldInfo_,
	_URLEncoder_MethodInfo_
};

$Object* allocate$URLEncoder($Class* clazz) {
	return $of($alloc(URLEncoder));
}

$BitSet* URLEncoder::dontNeedEncoding = nullptr;
$String* URLEncoder::dfltEncName = nullptr;

void URLEncoder::init$() {
}

$String* URLEncoder::encode($String* s) {
	$init(URLEncoder);
	$var($String, str, nullptr);
	try {
		$assign(str, encode(s, URLEncoder::dfltEncName));
	} catch ($UnsupportedEncodingException& e) {
	}
	return str;
}

$String* URLEncoder::encode($String* s, $String* enc) {
	$init(URLEncoder);
	if (enc == nullptr) {
		$throwNew($NullPointerException, "charsetName"_s);
	}
	try {
		$var($Charset, charset, $Charset::forName(enc));
		return encode(s, charset);
	} catch ($IllegalCharsetNameException& e) {
		$throwNew($UnsupportedEncodingException, enc);
	} catch ($UnsupportedCharsetException& e) {
		$throwNew($UnsupportedEncodingException, enc);
	}
	$shouldNotReachHere();
}

$String* URLEncoder::encode($String* s, $Charset* charset) {
	$init(URLEncoder);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(charset), "charset"_s);
	bool needToChange = false;
	$var($StringBuilder, out, $new($StringBuilder, $nc(s)->length()));
	$var($CharArrayWriter, charArrayWriter, $new($CharArrayWriter));
	for (int32_t i = 0; i < $nc(s)->length();) {
		int32_t c = s->charAt(i);
		if ($nc(URLEncoder::dontNeedEncoding)->get(c)) {
			if (c == u' ') {
				c = u'+';
				needToChange = true;
			}
			out->append((char16_t)c);
			++i;
		} else {
			bool var$0 = false;
			do {
				charArrayWriter->write(c);
				if (c >= 0x0000D800 && c <= 0x0000DBFF) {
					if ((i + 1) < s->length()) {
						int32_t d = s->charAt(i + 1);
						if (d >= 0x0000DC00 && d <= 0x0000DFFF) {
							charArrayWriter->write(d);
							++i;
						}
					}
				}
				++i;
				var$0 = i < s->length();
			} while (var$0 && !$nc(URLEncoder::dontNeedEncoding)->get((c = s->charAt(i))));
			charArrayWriter->flush();
			$var($String, str, charArrayWriter->toString());
			$var($bytes, ba, $nc(str)->getBytes(charset));
			{
				$var($bytes, arr$, ba);
				int32_t len$ = arr$->length;
				int32_t i$ = 0;
				for (; i$ < len$; ++i$) {
					int8_t b = arr$->get(i$);
					{
						out->append(u'%');
						char16_t ch = $Character::forDigit((int32_t)((b >> 4) & (uint32_t)15), 16);
						if ($Character::isLetter(ch)) {
							ch -= URLEncoder::caseDiff;
						}
						out->append(ch);
						ch = $Character::forDigit((int32_t)(b & (uint32_t)15), 16);
						if ($Character::isLetter(ch)) {
							ch -= URLEncoder::caseDiff;
						}
						out->append(ch);
					}
				}
			}
			charArrayWriter->reset();
			needToChange = true;
		}
	}
	return (needToChange ? out->toString() : s);
}

void clinit$URLEncoder($Class* class$) {
	{
		$assignStatic(URLEncoder::dontNeedEncoding, $new($BitSet, 256));
		int32_t i = 0;
		for (i = u'a'; i <= u'z'; ++i) {
			$nc(URLEncoder::dontNeedEncoding)->set(i);
		}
		for (i = u'A'; i <= u'Z'; ++i) {
			$nc(URLEncoder::dontNeedEncoding)->set(i);
		}
		for (i = u'0'; i <= u'9'; ++i) {
			$nc(URLEncoder::dontNeedEncoding)->set(i);
		}
		$nc(URLEncoder::dontNeedEncoding)->set(u' ');
		$nc(URLEncoder::dontNeedEncoding)->set(u'-');
		$nc(URLEncoder::dontNeedEncoding)->set(u'_');
		$nc(URLEncoder::dontNeedEncoding)->set(u'.');
		$nc(URLEncoder::dontNeedEncoding)->set(u'*');
		$assignStatic(URLEncoder::dfltEncName, $GetPropertyAction::privilegedGetProperty("file.encoding"_s));
	}
}

URLEncoder::URLEncoder() {
}

$Class* URLEncoder::load$($String* name, bool initialize) {
	$loadClass(URLEncoder, name, initialize, &_URLEncoder_ClassInfo_, clinit$URLEncoder, allocate$URLEncoder);
	return class$;
}

$Class* URLEncoder::class$ = nullptr;

	} // net
} // java