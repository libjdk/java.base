#include <jdk/internal/icu/impl/Utility.h>

#include <java/io/IOException.h>
#include <java/lang/Appendable.h>
#include <java/lang/CharSequence.h>
#include <java/util/Locale.h>
#include <jdk/internal/icu/impl/UCharacterProperty.h>
#include <jdk/internal/icu/lang/UCharacter.h>
#include <jdk/internal/icu/text/UTF16.h>
#include <jcpp.h>

#undef DIGITS
#undef ENGLISH
#undef MIN_VALUE
#undef UNESCAPE_MAP

using $IOException = ::java::io::IOException;
using $Appendable = ::java::lang::Appendable;
using $CharSequence = ::java::lang::CharSequence;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Locale = ::java::util::Locale;
using $UCharacterProperty = ::jdk::internal::icu::impl::UCharacterProperty;
using $UCharacter = ::jdk::internal::icu::lang::UCharacter;
using $UTF16 = ::jdk::internal::icu::text::UTF16;

namespace jdk {
	namespace internal {
		namespace icu {
			namespace impl {

$FieldInfo _Utility_FieldInfo_[] = {
	{"UNESCAPE_MAP", "[C", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Utility, UNESCAPE_MAP)},
	{"DIGITS", "[C", nullptr, $STATIC | $FINAL, $staticField(Utility, DIGITS)},
	{}
};

$MethodInfo _Utility_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Utility, init$, void)},
	{"escape", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticMethod(Utility, escape, $String*, $String*)},
	{"escapeUnprintable", "(Ljava/lang/Appendable;I)Z", "<T::Ljava/lang/Appendable;>(TT;I)Z", $PUBLIC | $STATIC, $staticMethod(Utility, escapeUnprintable, bool, $Appendable*, int32_t)},
	{"hex", "(JI)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(Utility, hex, $String*, int64_t, int32_t)},
	{"isUnprintable", "(I)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(Utility, isUnprintable, bool, int32_t)},
	{"unescapeAt", "(Ljava/lang/String;[I)I", nullptr, $PUBLIC | $STATIC, $staticMethod(Utility, unescapeAt, int32_t, $String*, $ints*)},
	{}
};

$ClassInfo _Utility_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.icu.impl.Utility",
	"java.lang.Object",
	nullptr,
	_Utility_FieldInfo_,
	_Utility_MethodInfo_
};

$Object* allocate$Utility($Class* clazz) {
	return $of($alloc(Utility));
}

$chars* Utility::UNESCAPE_MAP = nullptr;
$chars* Utility::DIGITS = nullptr;

void Utility::init$() {
}

$String* Utility::escape($String* s) {
	$init(Utility);
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, buf, $new($StringBuilder));
	for (int32_t i = 0; i < $nc(s)->length();) {
		int32_t c = $Character::codePointAt(static_cast<$CharSequence*>(s), i);
		i += $UTF16::getCharCount(c);
		if (c >= u' ' && c <= 127) {
			if (c == u'\\') {
				buf->append("\\\\"_s);
			} else {
				buf->append((char16_t)c);
			}
		} else {
			bool four = c <= 0x0000FFFF;
			buf->append(four ? "\\u"_s : "\\U"_s);
			buf->append($(hex(c, four ? 4 : 8)));
		}
	}
	return buf->toString();
}

int32_t Utility::unescapeAt($String* s, $ints* offset16) {
	$init(Utility);
	int32_t c = 0;
	int32_t result = 0;
	int32_t n = 0;
	int32_t minDig = 0;
	int32_t maxDig = 0;
	int32_t bitsPerDigit = 4;
	int32_t dig = 0;
	int32_t i = 0;
	bool braces = false;
	int32_t offset = $nc(offset16)->get(0);
	int32_t length = $nc(s)->length();
	if (offset < 0 || offset >= length) {
		return -1;
	}
	c = $Character::codePointAt(static_cast<$CharSequence*>(s), offset);
	offset += $UTF16::getCharCount(c);
	switch (c) {
	case u'u':
		{
			minDig = (maxDig = 4);
			break;
		}
	case u'U':
		{
			minDig = (maxDig = 8);
			break;
		}
	case u'x':
		{
			minDig = 1;
			if (offset < length && $UTF16::charAt(s, offset) == 123) {
				++offset;
				braces = true;
				maxDig = 8;
			} else {
				maxDig = 2;
			}
			break;
		}
	default:
		{
			dig = $UCharacter::digit(c, 8);
			if (dig >= 0) {
				minDig = 1;
				maxDig = 3;
				n = 1;
				bitsPerDigit = 3;
				result = dig;
			}
			break;
		}
	}
	if (minDig != 0) {
		while (offset < length && n < maxDig) {
			c = $UTF16::charAt(s, offset);
			dig = $UCharacter::digit(c, (bitsPerDigit == 3) ? 8 : 16);
			if (dig < 0) {
				break;
			}
			result = ($sl(result, bitsPerDigit)) | dig;
			offset += $UTF16::getCharCount(c);
			++n;
		}
		if (n < minDig) {
			return -1;
		}
		if (braces) {
			if (c != 125) {
				return -1;
			}
			++offset;
		}
		if (result < 0 || result >= 0x00110000) {
			return -1;
		}
		if (offset < length && $UTF16::isLeadSurrogate((char16_t)result)) {
			int32_t ahead = offset + 1;
			c = s->charAt(offset);
			if (c == u'\\' && ahead < length) {
				$var($ints, o, $new($ints, {ahead}));
				c = unescapeAt(s, o);
				ahead = o->get(0);
			}
			if ($UTF16::isTrailSurrogate((char16_t)c)) {
				offset = ahead;
				result = $UCharacterProperty::getRawSupplementary((char16_t)result, (char16_t)c);
			}
		}
		offset16->set(0, offset);
		return result;
	}
	for (i = 0; i < $nc(Utility::UNESCAPE_MAP)->length; i += 2) {
		if (c == $nc(Utility::UNESCAPE_MAP)->get(i)) {
			offset16->set(0, offset);
			return $nc(Utility::UNESCAPE_MAP)->get(i + 1);
		} else {
			if (c < $nc(Utility::UNESCAPE_MAP)->get(i)) {
				break;
			}
		}
	}
	if (c == u'c' && offset < length) {
		c = $UTF16::charAt(s, offset);
		offset16->set(0, offset + $UTF16::getCharCount(c));
		return (int32_t)(31 & (uint32_t)c);
	}
	offset16->set(0, offset);
	return c;
}

$String* Utility::hex(int64_t i, int32_t places) {
	$init(Utility);
	$useLocalCurrentObjectStackCache();
	if (i == $Long::MIN_VALUE) {
		return "-8000000000000000"_s;
	}
	bool negative = i < 0;
	if (negative) {
		i = -i;
	}
	$init($Locale);
	$var($String, result, $nc($($Long::toString(i, 16)))->toUpperCase($Locale::ENGLISH));
	if (result->length() < places) {
		$assign(result, $str({$("0000000000000000"_s->substring(result->length(), places)), result}));
	}
	if (negative) {
		return $str({$$str(u'-'), result});
	}
	return result;
}

bool Utility::isUnprintable(int32_t c) {
	$init(Utility);
	return !(c >= 32 && c <= 126);
}

bool Utility::escapeUnprintable($Appendable* result, int32_t c) {
	$init(Utility);
	try {
		if (isUnprintable(c)) {
			$nc(result)->append(u'\\');
			if (((int32_t)(c & (uint32_t)~0x0000FFFF)) != 0) {
				result->append(u'U');
				result->append($nc(Utility::DIGITS)->get((int32_t)(15 & (uint32_t)(c >> 28))));
				result->append($nc(Utility::DIGITS)->get((int32_t)(15 & (uint32_t)(c >> 24))));
				result->append($nc(Utility::DIGITS)->get((int32_t)(15 & (uint32_t)(c >> 20))));
				result->append($nc(Utility::DIGITS)->get((int32_t)(15 & (uint32_t)(c >> 16))));
			} else {
				result->append(u'u');
			}
			result->append($nc(Utility::DIGITS)->get((int32_t)(15 & (uint32_t)(c >> 12))));
			result->append($nc(Utility::DIGITS)->get((int32_t)(15 & (uint32_t)(c >> 8))));
			result->append($nc(Utility::DIGITS)->get((int32_t)(15 & (uint32_t)(c >> 4))));
			result->append($nc(Utility::DIGITS)->get((int32_t)(15 & (uint32_t)c)));
			return true;
		}
		return false;
	} catch ($IOException& e) {
		$throwNew($IllegalArgumentException, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

void clinit$Utility($Class* class$) {
	$assignStatic(Utility::UNESCAPE_MAP, $new($chars, {
		(char16_t)97,
		(char16_t)7,
		(char16_t)98,
		(char16_t)8,
		(char16_t)101,
		(char16_t)27,
		(char16_t)102,
		(char16_t)12,
		(char16_t)110,
		(char16_t)10,
		(char16_t)114,
		(char16_t)13,
		(char16_t)116,
		(char16_t)9,
		(char16_t)118,
		(char16_t)11
	}));
	$assignStatic(Utility::DIGITS, $new($chars, {
		u'0',
		u'1',
		u'2',
		u'3',
		u'4',
		u'5',
		u'6',
		u'7',
		u'8',
		u'9',
		u'A',
		u'B',
		u'C',
		u'D',
		u'E',
		u'F',
		u'G',
		u'H',
		u'I',
		u'J',
		u'K',
		u'L',
		u'M',
		u'N',
		u'O',
		u'P',
		u'Q',
		u'R',
		u'S',
		u'T',
		u'U',
		u'V',
		u'W',
		u'X',
		u'Y',
		u'Z'
	}));
}

Utility::Utility() {
}

$Class* Utility::load$($String* name, bool initialize) {
	$loadClass(Utility, name, initialize, &_Utility_ClassInfo_, clinit$Utility, allocate$Utility);
	return class$;
}

$Class* Utility::class$ = nullptr;

			} // impl
		} // icu
	} // internal
} // jdk