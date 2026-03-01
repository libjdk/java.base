#include <java/util/HexFormat.h>

#include <java/io/IOException.h>
#include <java/io/UncheckedIOException.h>
#include <java/lang/Appendable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/CharSequence.h>
#include <java/lang/NumberFormatException.h>
#include <java/lang/OutOfMemoryError.h>
#include <java/nio/CharBuffer.h>
#include <java/nio/charset/CharacterCodingException.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/StandardCharsets.h>
#include <java/util/Arrays.h>
#include <java/util/Objects.h>
#include <jdk/internal/access/JavaLangAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jcpp.h>

#undef DIGITS
#undef EMPTY_BYTES
#undef HEX_FORMAT
#undef LOWERCASE_DIGITS
#undef MAX_VALUE
#undef UPPERCASE_DIGITS

using $IOException = ::java::io::IOException;
using $UncheckedIOException = ::java::io::UncheckedIOException;
using $Appendable = ::java::lang::Appendable;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $OutOfMemoryError = ::java::lang::OutOfMemoryError;
using $CharBuffer = ::java::nio::CharBuffer;
using $CharacterCodingException = ::java::nio::charset::CharacterCodingException;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $Arrays = ::java::util::Arrays;
using $Objects = ::java::util::Objects;
using $JavaLangAccess = ::jdk::internal::access::JavaLangAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;

namespace java {
	namespace util {

$FieldInfo _HexFormat_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(HexFormat, $assertionsDisabled)},
	{"jla", "Ljdk/internal/access/JavaLangAccess;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HexFormat, jla)},
	{"UPPERCASE_DIGITS", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HexFormat, UPPERCASE_DIGITS)},
	{"LOWERCASE_DIGITS", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HexFormat, LOWERCASE_DIGITS)},
	{"DIGITS", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HexFormat, DIGITS)},
	{"HEX_FORMAT", "Ljava/util/HexFormat;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HexFormat, HEX_FORMAT)},
	{"EMPTY_BYTES", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HexFormat, EMPTY_BYTES)},
	{"delimiter", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(HexFormat, delimiter$)},
	{"prefix", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(HexFormat, prefix$)},
	{"suffix", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(HexFormat, suffix$)},
	{"digits", "[B", nullptr, $PRIVATE | $FINAL, $field(HexFormat, digits)},
	{}
};

$MethodInfo _HexFormat_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;[B)V", nullptr, $PRIVATE, $method(HexFormat, init$, void, $String*, $String*, $String*, $bytes*)},
	{"checkDigitCount", "(III)I", nullptr, $PRIVATE | $STATIC, $staticMethod(HexFormat, checkDigitCount, int32_t, int32_t, int32_t, int32_t)},
	{"checkLiteral", "(Ljava/lang/CharSequence;ILjava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(HexFormat, checkLiteral, void, $CharSequence*, int32_t, $String*)},
	{"checkMaxArraySize", "(J)I", nullptr, $PRIVATE | $STATIC, $staticMethod(HexFormat, checkMaxArraySize, int32_t, int64_t)},
	{"delimiter", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(HexFormat, delimiter, $String*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(HexFormat, equals, bool, Object$*)},
	{"escapeNL", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(HexFormat, escapeNL, $String*, $String*)},
	{"formatHex", "([B)Ljava/lang/String;", nullptr, $PUBLIC, $method(HexFormat, formatHex, $String*, $bytes*)},
	{"formatHex", "([BII)Ljava/lang/String;", nullptr, $PUBLIC, $method(HexFormat, formatHex, $String*, $bytes*, int32_t, int32_t)},
	{"formatHex", "(Ljava/lang/Appendable;[B)Ljava/lang/Appendable;", "<A::Ljava/lang/Appendable;>(TA;[B)TA;", $PUBLIC, $method(HexFormat, formatHex, $Appendable*, $Appendable*, $bytes*)},
	{"formatHex", "(Ljava/lang/Appendable;[BII)Ljava/lang/Appendable;", "<A::Ljava/lang/Appendable;>(TA;[BII)TA;", $PUBLIC, $method(HexFormat, formatHex, $Appendable*, $Appendable*, $bytes*, int32_t, int32_t)},
	{"formatOptDelimiter", "([BII)Ljava/lang/String;", nullptr, $PRIVATE, $method(HexFormat, formatOptDelimiter, $String*, $bytes*, int32_t, int32_t)},
	{"fromHexDigit", "(I)I", nullptr, $PUBLIC | $STATIC, $staticMethod(HexFormat, fromHexDigit, int32_t, int32_t)},
	{"fromHexDigits", "(Ljava/lang/CharSequence;I)I", nullptr, $PRIVATE | $STATIC, $staticMethod(HexFormat, fromHexDigits, int32_t, $CharSequence*, int32_t)},
	{"fromHexDigits", "(Ljava/lang/CharSequence;)I", nullptr, $PUBLIC | $STATIC, $staticMethod(HexFormat, fromHexDigits, int32_t, $CharSequence*)},
	{"fromHexDigits", "(Ljava/lang/CharSequence;II)I", nullptr, $PUBLIC | $STATIC, $staticMethod(HexFormat, fromHexDigits, int32_t, $CharSequence*, int32_t, int32_t)},
	{"fromHexDigitsToLong", "(Ljava/lang/CharSequence;)J", nullptr, $PUBLIC | $STATIC, $staticMethod(HexFormat, fromHexDigitsToLong, int64_t, $CharSequence*)},
	{"fromHexDigitsToLong", "(Ljava/lang/CharSequence;II)J", nullptr, $PUBLIC | $STATIC, $staticMethod(HexFormat, fromHexDigitsToLong, int64_t, $CharSequence*, int32_t, int32_t)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(HexFormat, hashCode, int32_t)},
	{"isHexDigit", "(I)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(HexFormat, isHexDigit, bool, int32_t)},
	{"isUpperCase", "()Z", nullptr, $PUBLIC, $method(HexFormat, isUpperCase, bool)},
	{"of", "()Ljava/util/HexFormat;", nullptr, $PUBLIC | $STATIC, $staticMethod(HexFormat, of, HexFormat*)},
	{"ofDelimiter", "(Ljava/lang/String;)Ljava/util/HexFormat;", nullptr, $PUBLIC | $STATIC, $staticMethod(HexFormat, ofDelimiter, HexFormat*, $String*)},
	{"parseHex", "(Ljava/lang/CharSequence;)[B", nullptr, $PUBLIC, $method(HexFormat, parseHex, $bytes*, $CharSequence*)},
	{"parseHex", "(Ljava/lang/CharSequence;II)[B", nullptr, $PUBLIC, $method(HexFormat, parseHex, $bytes*, $CharSequence*, int32_t, int32_t)},
	{"parseHex", "([CII)[B", nullptr, $PUBLIC, $method(HexFormat, parseHex, $bytes*, $chars*, int32_t, int32_t)},
	{"parseNoDelimiter", "(Ljava/lang/CharSequence;)[B", nullptr, $PRIVATE | $STATIC, $staticMethod(HexFormat, parseNoDelimiter, $bytes*, $CharSequence*)},
	{"prefix", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(HexFormat, prefix, $String*)},
	{"suffix", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(HexFormat, suffix, $String*)},
	{"toHexDigits", "(Ljava/lang/Appendable;B)Ljava/lang/Appendable;", "<A::Ljava/lang/Appendable;>(TA;B)TA;", $PUBLIC, $method(HexFormat, toHexDigits, $Appendable*, $Appendable*, int8_t)},
	{"toHexDigits", "(B)Ljava/lang/String;", nullptr, $PUBLIC, $method(HexFormat, toHexDigits, $String*, int8_t)},
	{"toHexDigits", "(C)Ljava/lang/String;", nullptr, $PUBLIC, $method(HexFormat, toHexDigits, $String*, char16_t)},
	{"toHexDigits", "(S)Ljava/lang/String;", nullptr, $PUBLIC, $method(HexFormat, toHexDigits, $String*, int16_t)},
	{"toHexDigits", "(I)Ljava/lang/String;", nullptr, $PUBLIC, $method(HexFormat, toHexDigits, $String*, int32_t)},
	{"toHexDigits", "(J)Ljava/lang/String;", nullptr, $PUBLIC, $method(HexFormat, toHexDigits, $String*, int64_t)},
	{"toHexDigits", "(JI)Ljava/lang/String;", nullptr, $PUBLIC, $method(HexFormat, toHexDigits, $String*, int64_t, int32_t)},
	{"toHighHexDigit", "(I)C", nullptr, $PUBLIC, $method(HexFormat, toHighHexDigit, char16_t, int32_t)},
	{"toLowHexDigit", "(I)C", nullptr, $PUBLIC, $method(HexFormat, toLowHexDigit, char16_t, int32_t)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(HexFormat, toString, $String*)},
	{"withDelimiter", "(Ljava/lang/String;)Ljava/util/HexFormat;", nullptr, $PUBLIC, $method(HexFormat, withDelimiter, HexFormat*, $String*)},
	{"withLowerCase", "()Ljava/util/HexFormat;", nullptr, $PUBLIC, $method(HexFormat, withLowerCase, HexFormat*)},
	{"withPrefix", "(Ljava/lang/String;)Ljava/util/HexFormat;", nullptr, $PUBLIC, $method(HexFormat, withPrefix, HexFormat*, $String*)},
	{"withSuffix", "(Ljava/lang/String;)Ljava/util/HexFormat;", nullptr, $PUBLIC, $method(HexFormat, withSuffix, HexFormat*, $String*)},
	{"withUpperCase", "()Ljava/util/HexFormat;", nullptr, $PUBLIC, $method(HexFormat, withUpperCase, HexFormat*)},
	{}
};

$ClassInfo _HexFormat_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.util.HexFormat",
	"java.lang.Object",
	nullptr,
	_HexFormat_FieldInfo_,
	_HexFormat_MethodInfo_
};

$Object* allocate$HexFormat($Class* clazz) {
	return $of($alloc(HexFormat));
}

bool HexFormat::$assertionsDisabled = false;
$JavaLangAccess* HexFormat::jla = nullptr;
$bytes* HexFormat::UPPERCASE_DIGITS = nullptr;
$bytes* HexFormat::LOWERCASE_DIGITS = nullptr;
$bytes* HexFormat::DIGITS = nullptr;
HexFormat* HexFormat::HEX_FORMAT = nullptr;
$bytes* HexFormat::EMPTY_BYTES = nullptr;

void HexFormat::init$($String* delimiter, $String* prefix, $String* suffix, $bytes* digits) {
	$set(this, delimiter$, $cast($String, $Objects::requireNonNull($of(delimiter), "delimiter"_s)));
	$set(this, prefix$, $cast($String, $Objects::requireNonNull($of(prefix), "prefix"_s)));
	$set(this, suffix$, $cast($String, $Objects::requireNonNull($of(suffix), "suffix"_s)));
	$set(this, digits, digits);
}

HexFormat* HexFormat::of() {
	$init(HexFormat);
	return HexFormat::HEX_FORMAT;
}

HexFormat* HexFormat::ofDelimiter($String* delimiter) {
	$init(HexFormat);
	return $new(HexFormat, delimiter, ""_s, ""_s, HexFormat::LOWERCASE_DIGITS);
}

HexFormat* HexFormat::withDelimiter($String* delimiter) {
	return $new(HexFormat, delimiter, this->prefix$, this->suffix$, this->digits);
}

HexFormat* HexFormat::withPrefix($String* prefix) {
	return $new(HexFormat, this->delimiter$, prefix, this->suffix$, this->digits);
}

HexFormat* HexFormat::withSuffix($String* suffix) {
	return $new(HexFormat, this->delimiter$, this->prefix$, suffix, this->digits);
}

HexFormat* HexFormat::withUpperCase() {
	return $new(HexFormat, this->delimiter$, this->prefix$, this->suffix$, HexFormat::UPPERCASE_DIGITS);
}

HexFormat* HexFormat::withLowerCase() {
	return $new(HexFormat, this->delimiter$, this->prefix$, this->suffix$, HexFormat::LOWERCASE_DIGITS);
}

$String* HexFormat::delimiter() {
	return this->delimiter$;
}

$String* HexFormat::prefix() {
	return this->prefix$;
}

$String* HexFormat::suffix() {
	return this->suffix$;
}

bool HexFormat::isUpperCase() {
	return $Arrays::equals(this->digits, HexFormat::UPPERCASE_DIGITS);
}

$String* HexFormat::formatHex($bytes* bytes) {
	return formatHex(bytes, 0, $nc(bytes)->length);
}

$String* HexFormat::formatHex($bytes* bytes, int32_t fromIndex, int32_t toIndex) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(bytes), "bytes"_s);
	$Objects::checkFromToIndex(fromIndex, toIndex, $nc(bytes)->length);
	if (toIndex - fromIndex == 0) {
		return ""_s;
	}
	$var($String, s, formatOptDelimiter(bytes, fromIndex, toIndex));
	if (s == nullptr) {
		int64_t var$1 = $nc(this->prefix$)->length() + (int64_t)2;
		int64_t var$0 = var$1 + $nc(this->suffix$)->length();
		int64_t stride = var$0 + $nc(this->delimiter$)->length();
		int32_t capacity = checkMaxArraySize((toIndex - fromIndex) * stride - $nc(this->delimiter$)->length());
		$var($StringBuilder, sb, $new($StringBuilder, capacity));
		formatHex(sb, bytes, fromIndex, toIndex);
		$assign(s, sb->toString());
	}
	return s;
}

$Appendable* HexFormat::formatHex($Appendable* out, $bytes* bytes) {
	return formatHex(out, bytes, 0, $nc(bytes)->length);
}

$Appendable* HexFormat::formatHex($Appendable* out, $bytes* bytes, int32_t fromIndex, int32_t toIndex) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(out), "out"_s);
	$Objects::requireNonNull($of(bytes), "bytes"_s);
	$Objects::checkFromToIndex(fromIndex, toIndex, $nc(bytes)->length);
	int32_t length = toIndex - fromIndex;
	if (length > 0) {
		try {
			$var($String, between, $str({this->suffix$, this->delimiter$, this->prefix$}));
			$nc(out)->append(static_cast<$CharSequence*>(this->prefix$));
			toHexDigits(out, $nc(bytes)->get(fromIndex));
			if ($nc(between)->isEmpty()) {
				for (int32_t i = 1; i < length; ++i) {
					toHexDigits(out, $nc(bytes)->get(fromIndex + i));
				}
			} else {
				for (int32_t i = 1; i < length; ++i) {
					out->append(static_cast<$CharSequence*>(between));
					toHexDigits(out, $nc(bytes)->get(fromIndex + i));
				}
			}
			out->append(static_cast<$CharSequence*>(this->suffix$));
		} catch ($IOException& ioe) {
			$throwNew($UncheckedIOException, $(ioe->getMessage()), ioe);
		}
	}
	return out;
}

$String* HexFormat::formatOptDelimiter($bytes* bytes, int32_t fromIndex, int32_t toIndex) {
	$var($bytes, rep, nullptr);
	bool var$0 = !$nc(this->prefix$)->isEmpty();
	if (var$0 || !$nc(this->suffix$)->isEmpty()) {
		return nullptr;
	}
	int32_t length = toIndex - fromIndex;
	if ($nc(this->delimiter$)->isEmpty()) {
		$assign(rep, $new($bytes, checkMaxArraySize(length * (int64_t)2)));
		for (int32_t i = 0; i < length; ++i) {
			rep->set(i * 2, (int8_t)toHighHexDigit($nc(bytes)->get(fromIndex + i)));
			rep->set(i * 2 + 1, (int8_t)toLowHexDigit($nc(bytes)->get(fromIndex + i)));
		}
	} else {
		bool var$2 = $nc(this->delimiter$)->length() == 1;
		if (var$2 && $nc(this->delimiter$)->charAt(0) < 256) {
			char16_t sep = $nc(this->delimiter$)->charAt(0);
			$assign(rep, $new($bytes, checkMaxArraySize(length * (int64_t)3 - (int64_t)1)));
			rep->set(0, (int8_t)toHighHexDigit($nc(bytes)->get(fromIndex)));
			rep->set(1, (int8_t)toLowHexDigit($nc(bytes)->get(fromIndex)));
			for (int32_t i = 1; i < length; ++i) {
				rep->set(i * 3 - 1, (int8_t)sep);
				rep->set(i * 3, (int8_t)toHighHexDigit($nc(bytes)->get(fromIndex + i)));
				rep->set(i * 3 + 1, (int8_t)toLowHexDigit($nc(bytes)->get(fromIndex + i)));
			}
		} else {
			return nullptr;
		}
	}
	try {
		$init($StandardCharsets);
		return $nc(HexFormat::jla)->newStringNoRepl(rep, $StandardCharsets::ISO_8859_1);
	} catch ($CharacterCodingException& cce) {
		$throwNew($AssertionError, $of(cce));
	}
	$shouldNotReachHere();
}

int32_t HexFormat::checkMaxArraySize(int64_t length) {
	$init(HexFormat);
	$useLocalCurrentObjectStackCache();
	if (length > $Integer::MAX_VALUE) {
		$throwNew($OutOfMemoryError, $$str({"String size "_s, $$str(length), " exceeds maximum "_s, $$str($Integer::MAX_VALUE)}));
	}
	return (int32_t)length;
}

$bytes* HexFormat::parseHex($CharSequence* string) {
	return parseHex(string, 0, $nc(string)->length());
}

$bytes* HexFormat::parseHex($CharSequence* string$renamed, int32_t fromIndex, int32_t toIndex) {
	$useLocalCurrentObjectStackCache();
	$var($CharSequence, string, string$renamed);
	$Objects::requireNonNull($of(string), "string"_s);
	$Objects::checkFromToIndex(fromIndex, toIndex, $nc(string)->length());
	if (fromIndex != 0 || toIndex != $nc(string)->length()) {
		$assign(string, string->subSequence(fromIndex, toIndex));
	}
	if ($nc(string)->isEmpty()) {
		return HexFormat::EMPTY_BYTES;
	}
	bool var$1 = $nc(this->delimiter$)->isEmpty();
	bool var$0 = var$1 && $nc(this->prefix$)->isEmpty();
	if (var$0 && $nc(this->suffix$)->isEmpty()) {
		return parseNoDelimiter(string);
	}
	int64_t var$2 = $nc(this->prefix$)->length() + (int64_t)2;
	int64_t valueChars = var$2 + $nc(this->suffix$)->length();
	int64_t stride = valueChars + $nc(this->delimiter$)->length();
	if ($mod(($nc(string)->length() - valueChars), stride) != 0) {
		$throwNew($IllegalArgumentException, "extra or missing delimiters or values consisting of prefix, two hexadecimal digits, and suffix"_s);
	}
	checkLiteral(string, 0, this->prefix$);
	int32_t var$3 = $nc(string)->length();
	checkLiteral(string, var$3 - $nc(this->suffix$)->length(), this->suffix$);
	$var($String, between, $str({this->suffix$, this->delimiter$, this->prefix$}));
	int32_t len = (int32_t)($div(($nc(string)->length() - valueChars), stride) + (int64_t)1);
	$var($bytes, bytes, $new($bytes, len));
	int32_t i = 0;
	int32_t offset = 0;
	for (i = 0, offset = $nc(this->prefix$)->length(); i < len - 1; ++i, offset += 2 + $nc(between)->length()) {
		bytes->set(i, (int8_t)fromHexDigits(string, offset));
		checkLiteral(string, offset + 2, between);
	}
	bytes->set(i, (int8_t)fromHexDigits(string, offset));
	return bytes;
}

$bytes* HexFormat::parseHex($chars* chars, int32_t fromIndex, int32_t toIndex) {
	$Objects::requireNonNull($of(chars), "chars"_s);
	$Objects::checkFromToIndex(fromIndex, toIndex, $nc(chars)->length);
	$var($CharBuffer, cb, $CharBuffer::wrap(chars, fromIndex, toIndex - fromIndex));
	return parseHex(cb);
}

void HexFormat::checkLiteral($CharSequence* string, int32_t index, $String* literal) {
	$init(HexFormat);
	$useLocalCurrentObjectStackCache();
	bool var$0 = !HexFormat::$assertionsDisabled;
	if (var$0) {
		int32_t var$1 = index;
		int32_t var$3 = $nc(string)->length();
		int32_t var$2 = var$3 - $nc(literal)->length();
		var$0 = !(var$1 <= var$2);
	}
	if (var$0) {
		$throwNew($AssertionError, $of("pre-checked invariant error"_s));
	}
	bool var$4 = $nc(literal)->isEmpty();
	if (!var$4) {
		bool var$5 = $nc(literal)->length() == 1;
		if (var$5) {
			char16_t var$6 = literal->charAt(0);
			var$5 = var$6 == $nc(string)->charAt(index);
		}
		var$4 = (var$5);
	}
	if (var$4) {
		return;
	}
	for (int32_t i = 0; i < $nc(literal)->length(); ++i) {
		char16_t var$7 = $nc(string)->charAt(index + i);
		if (var$7 != literal->charAt(i)) {
			$var($String, var$8, $$str({"found: \""_s, $(string->subSequence(index, index + literal->length())), "\", expected: \""_s, literal, "\", index: "_s, $$str(index), " ch: "_s}));
			$throwNew($IllegalArgumentException, $(escapeNL($$concat(var$8, $$str((int32_t)string->charAt(index + i))))));
		}
	}
}

$String* HexFormat::escapeNL($String* string) {
	$init(HexFormat);
	return $($nc(string)->replace(static_cast<$CharSequence*>("\n"_s), static_cast<$CharSequence*>("\\n"_s)))->replace(static_cast<$CharSequence*>("\r"_s), static_cast<$CharSequence*>("\\r"_s));
}

char16_t HexFormat::toLowHexDigit(int32_t value) {
	return (char16_t)$nc(this->digits)->get((int32_t)(value & (uint32_t)15));
}

char16_t HexFormat::toHighHexDigit(int32_t value) {
	return (char16_t)$nc(this->digits)->get((int32_t)((value >> 4) & (uint32_t)15));
}

$Appendable* HexFormat::toHexDigits($Appendable* out, int8_t value) {
	$Objects::requireNonNull($of(out), "out"_s);
	try {
		$nc(out)->append(toHighHexDigit(value));
		out->append(toLowHexDigit(value));
		return out;
	} catch ($IOException& ioe) {
		$throwNew($UncheckedIOException, $(ioe->getMessage()), ioe);
	}
	$shouldNotReachHere();
}

$String* HexFormat::toHexDigits(int8_t value) {
	$var($bytes, rep, $new($bytes, 2));
	rep->set(0, (int8_t)toHighHexDigit(value));
	rep->set(1, (int8_t)toLowHexDigit(value));
	try {
		$init($StandardCharsets);
		return $nc(HexFormat::jla)->newStringNoRepl(rep, $StandardCharsets::ISO_8859_1);
	} catch ($CharacterCodingException& cce) {
		$throwNew($AssertionError, $of(cce));
	}
	$shouldNotReachHere();
}

$String* HexFormat::toHexDigits(char16_t value) {
	return toHexDigits((int16_t)value);
}

$String* HexFormat::toHexDigits(int16_t value) {
	$var($bytes, rep, $new($bytes, 4));
	rep->set(0, (int8_t)toHighHexDigit((int8_t)(value >> 8)));
	rep->set(1, (int8_t)toLowHexDigit((int8_t)(value >> 8)));
	rep->set(2, (int8_t)toHighHexDigit((int8_t)value));
	rep->set(3, (int8_t)toLowHexDigit((int8_t)value));
	try {
		$init($StandardCharsets);
		return $nc(HexFormat::jla)->newStringNoRepl(rep, $StandardCharsets::ISO_8859_1);
	} catch ($CharacterCodingException& cce) {
		$throwNew($AssertionError, $of(cce));
	}
	$shouldNotReachHere();
}

$String* HexFormat::toHexDigits(int32_t value) {
	$var($bytes, rep, $new($bytes, 8));
	rep->set(0, (int8_t)toHighHexDigit((int8_t)(value >> 24)));
	rep->set(1, (int8_t)toLowHexDigit((int8_t)(value >> 24)));
	rep->set(2, (int8_t)toHighHexDigit((int8_t)(value >> 16)));
	rep->set(3, (int8_t)toLowHexDigit((int8_t)(value >> 16)));
	rep->set(4, (int8_t)toHighHexDigit((int8_t)(value >> 8)));
	rep->set(5, (int8_t)toLowHexDigit((int8_t)(value >> 8)));
	rep->set(6, (int8_t)toHighHexDigit((int8_t)value));
	rep->set(7, (int8_t)toLowHexDigit((int8_t)value));
	try {
		$init($StandardCharsets);
		return $nc(HexFormat::jla)->newStringNoRepl(rep, $StandardCharsets::ISO_8859_1);
	} catch ($CharacterCodingException& cce) {
		$throwNew($AssertionError, $of(cce));
	}
	$shouldNotReachHere();
}

$String* HexFormat::toHexDigits(int64_t value) {
	$var($bytes, rep, $new($bytes, 16));
	rep->set(0, (int8_t)toHighHexDigit((int8_t)((int64_t)((uint64_t)value >> 56))));
	rep->set(1, (int8_t)toLowHexDigit((int8_t)((int64_t)((uint64_t)value >> 56))));
	rep->set(2, (int8_t)toHighHexDigit((int8_t)((int64_t)((uint64_t)value >> 48))));
	rep->set(3, (int8_t)toLowHexDigit((int8_t)((int64_t)((uint64_t)value >> 48))));
	rep->set(4, (int8_t)toHighHexDigit((int8_t)((int64_t)((uint64_t)value >> 40))));
	rep->set(5, (int8_t)toLowHexDigit((int8_t)((int64_t)((uint64_t)value >> 40))));
	rep->set(6, (int8_t)toHighHexDigit((int8_t)((int64_t)((uint64_t)value >> 32))));
	rep->set(7, (int8_t)toLowHexDigit((int8_t)((int64_t)((uint64_t)value >> 32))));
	rep->set(8, (int8_t)toHighHexDigit((int8_t)((int64_t)((uint64_t)value >> 24))));
	rep->set(9, (int8_t)toLowHexDigit((int8_t)((int64_t)((uint64_t)value >> 24))));
	rep->set(10, (int8_t)toHighHexDigit((int8_t)((int64_t)((uint64_t)value >> 16))));
	rep->set(11, (int8_t)toLowHexDigit((int8_t)((int64_t)((uint64_t)value >> 16))));
	rep->set(12, (int8_t)toHighHexDigit((int8_t)((int64_t)((uint64_t)value >> 8))));
	rep->set(13, (int8_t)toLowHexDigit((int8_t)((int64_t)((uint64_t)value >> 8))));
	rep->set(14, (int8_t)toHighHexDigit((int8_t)value));
	rep->set(15, (int8_t)toLowHexDigit((int8_t)value));
	try {
		$init($StandardCharsets);
		return $nc(HexFormat::jla)->newStringNoRepl(rep, $StandardCharsets::ISO_8859_1);
	} catch ($CharacterCodingException& cce) {
		$throwNew($AssertionError, $of(cce));
	}
	$shouldNotReachHere();
}

$String* HexFormat::toHexDigits(int64_t value, int32_t digits) {
	$useLocalCurrentObjectStackCache();
	if (digits < 0 || digits > 16) {
		$throwNew($IllegalArgumentException, $$str({"number of digits: "_s, $$str(digits)}));
	}
	if (digits == 0) {
		return ""_s;
	}
	$var($bytes, rep, $new($bytes, digits));
	for (int32_t i = rep->length - 1; i >= 0; --i) {
		rep->set(i, (int8_t)toLowHexDigit((int8_t)(value)));
		value = (int64_t)((uint64_t)value >> 4);
	}
	try {
		$init($StandardCharsets);
		return $nc(HexFormat::jla)->newStringNoRepl(rep, $StandardCharsets::ISO_8859_1);
	} catch ($CharacterCodingException& cce) {
		$throwNew($AssertionError, $of(cce));
	}
	$shouldNotReachHere();
}

$bytes* HexFormat::parseNoDelimiter($CharSequence* string) {
	$init(HexFormat);
	$useLocalCurrentObjectStackCache();
	if (((int32_t)($nc(string)->length() & (uint32_t)1)) != 0) {
		$throwNew($IllegalArgumentException, $$str({"string length not even: "_s, $$str(string->length())}));
	}
	$var($bytes, bytes, $new($bytes, $nc(string)->length() / 2));
	for (int32_t i = 0; i < bytes->length; ++i) {
		bytes->set(i, (int8_t)fromHexDigits(string, i * 2));
	}
	return bytes;
}

int32_t HexFormat::checkDigitCount(int32_t fromIndex, int32_t toIndex, int32_t limit) {
	$init(HexFormat);
	$useLocalCurrentObjectStackCache();
	int32_t length = toIndex - fromIndex;
	if (length > limit) {
		$throwNew($IllegalArgumentException, $$str({"string length greater than "_s, $$str(limit), ": "_s, $$str(length)}));
	}
	return length;
}

bool HexFormat::isHexDigit(int32_t ch) {
	$init(HexFormat);
	return (((int32_t)((uint32_t)ch >> 8)) == 0 && $nc(HexFormat::DIGITS)->get(ch) >= 0);
}

int32_t HexFormat::fromHexDigit(int32_t ch) {
	$init(HexFormat);
	$useLocalCurrentObjectStackCache();
	int32_t value = 0;
	if (((int32_t)((uint32_t)ch >> 8)) == 0 && (value = $nc(HexFormat::DIGITS)->get(ch)) >= 0) {
		return value;
	}
	$throwNew($NumberFormatException, $$str({"not a hexadecimal digit: \""_s, $$str((char16_t)ch), "\" = "_s, $$str(ch)}));
}

int32_t HexFormat::fromHexDigits($CharSequence* string, int32_t index) {
	$init(HexFormat);
	int32_t high = fromHexDigit($nc(string)->charAt(index));
	int32_t low = fromHexDigit($nc(string)->charAt(index + 1));
	return (high << 4) | low;
}

int32_t HexFormat::fromHexDigits($CharSequence* string) {
	$init(HexFormat);
	return fromHexDigits(string, 0, $nc(string)->length());
}

int32_t HexFormat::fromHexDigits($CharSequence* string, int32_t fromIndex, int32_t toIndex) {
	$init(HexFormat);
	$Objects::requireNonNull($of(string), "string"_s);
	$Objects::checkFromToIndex(fromIndex, toIndex, $nc(string)->length());
	int32_t length = checkDigitCount(fromIndex, toIndex, 8);
	int32_t value = 0;
	for (int32_t i = 0; i < length; ++i) {
		value = (value << 4) + fromHexDigit($nc(string)->charAt(fromIndex + i));
	}
	return value;
}

int64_t HexFormat::fromHexDigitsToLong($CharSequence* string) {
	$init(HexFormat);
	return fromHexDigitsToLong(string, 0, $nc(string)->length());
}

int64_t HexFormat::fromHexDigitsToLong($CharSequence* string, int32_t fromIndex, int32_t toIndex) {
	$init(HexFormat);
	$Objects::requireNonNull($of(string), "string"_s);
	$Objects::checkFromToIndex(fromIndex, toIndex, $nc(string)->length());
	int32_t length = checkDigitCount(fromIndex, toIndex, 16);
	int64_t value = 0;
	for (int32_t i = 0; i < length; ++i) {
		value = (value << 4) + fromHexDigit($nc(string)->charAt(fromIndex + i));
	}
	return value;
}

bool HexFormat::equals(Object$* o) {
	if ($equals(this, o)) {
		return true;
	}
	bool var$0 = o == nullptr;
	if (!var$0) {
		var$0 = $of(this)->getClass() != $nc($of(o))->getClass();
	}
	if (var$0) {
		return false;
	}
	$var(HexFormat, otherHex, $cast(HexFormat, o));
	bool var$3 = $Arrays::equals(this->digits, $nc(otherHex)->digits);
	bool var$2 = var$3 && $nc(this->delimiter$)->equals($nc(otherHex)->delimiter$);
	bool var$1 = var$2 && $nc(this->prefix$)->equals($nc(otherHex)->prefix$);
	return var$1 && $nc(this->suffix$)->equals($nc(otherHex)->suffix$);
}

int32_t HexFormat::hashCode() {
	int32_t result = $Objects::hash($$new($ObjectArray, {
		$of(this->delimiter$),
		$of(this->prefix$),
		$of(this->suffix$)
	}));
	result = 31 * result + $Boolean::hashCode($Arrays::equals(this->digits, HexFormat::UPPERCASE_DIGITS));
	return result;
}

$String* HexFormat::toString() {
	$useLocalCurrentObjectStackCache();
	return escapeNL($$str({"uppercase: "_s, $$str($Arrays::equals(this->digits, HexFormat::UPPERCASE_DIGITS)), ", delimiter: \""_s, this->delimiter$, "\", prefix: \""_s, this->prefix$, "\", suffix: \""_s, this->suffix$, "\""_s}));
}

void clinit$HexFormat($Class* class$) {
	HexFormat::$assertionsDisabled = !HexFormat::class$->desiredAssertionStatus();
	$assignStatic(HexFormat::jla, $SharedSecrets::getJavaLangAccess());
	$assignStatic(HexFormat::UPPERCASE_DIGITS, $new($bytes, {
		(int8_t)u'0',
		(int8_t)u'1',
		(int8_t)u'2',
		(int8_t)u'3',
		(int8_t)u'4',
		(int8_t)u'5',
		(int8_t)u'6',
		(int8_t)u'7',
		(int8_t)u'8',
		(int8_t)u'9',
		(int8_t)u'A',
		(int8_t)u'B',
		(int8_t)u'C',
		(int8_t)u'D',
		(int8_t)u'E',
		(int8_t)u'F'
	}));
	$assignStatic(HexFormat::LOWERCASE_DIGITS, $new($bytes, {
		(int8_t)u'0',
		(int8_t)u'1',
		(int8_t)u'2',
		(int8_t)u'3',
		(int8_t)u'4',
		(int8_t)u'5',
		(int8_t)u'6',
		(int8_t)u'7',
		(int8_t)u'8',
		(int8_t)u'9',
		(int8_t)u'a',
		(int8_t)u'b',
		(int8_t)u'c',
		(int8_t)u'd',
		(int8_t)u'e',
		(int8_t)u'f'
	}));
	$assignStatic(HexFormat::DIGITS, $new($bytes, {
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)0,
		(int8_t)1,
		(int8_t)2,
		(int8_t)3,
		(int8_t)4,
		(int8_t)5,
		(int8_t)6,
		(int8_t)7,
		(int8_t)8,
		(int8_t)9,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)10,
		(int8_t)11,
		(int8_t)12,
		(int8_t)13,
		(int8_t)14,
		(int8_t)15,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)10,
		(int8_t)11,
		(int8_t)12,
		(int8_t)13,
		(int8_t)14,
		(int8_t)15,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1,
		(int8_t)-1
	}));
	$assignStatic(HexFormat::HEX_FORMAT, $new(HexFormat, ""_s, ""_s, ""_s, HexFormat::LOWERCASE_DIGITS));
	$assignStatic(HexFormat::EMPTY_BYTES, $new($bytes, 0));
}

HexFormat::HexFormat() {
}

$Class* HexFormat::load$($String* name, bool initialize) {
	$loadClass(HexFormat, name, initialize, &_HexFormat_ClassInfo_, clinit$HexFormat, allocate$HexFormat);
	return class$;
}

$Class* HexFormat::class$ = nullptr;

	} // util
} // java