#include <java/lang/Integer.h>

#include <java/lang/CharSequence.h>
#include <java/lang/IndexOutOfBoundsException.h>
#include <java/lang/Integer$IntegerCache.h>
#include <java/lang/Math.h>
#include <java/lang/Number.h>
#include <java/lang/NumberFormatException.h>
#include <java/lang/StringLatin1.h>
#include <java/lang/StringUTF16.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/util/Objects.h>
#include <java/util/Optional.h>
#include <jcpp.h>

#undef BYTES
#undef COMPACT_STRINGS
#undef MAX_RADIX
#undef MAX_VALUE
#undef MIN_RADIX
#undef MIN_VALUE
#undef SIZE
#undef TYPE

using $CharSequence = ::java::lang::CharSequence;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IndexOutOfBoundsException = ::java::lang::IndexOutOfBoundsException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer$IntegerCache = ::java::lang::Integer$IntegerCache;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $NamedAttribute = ::java::lang::NamedAttribute;
using $NullPointerException = ::java::lang::NullPointerException;
using $Number = ::java::lang::Number;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $StringLatin1 = ::java::lang::StringLatin1;
using $StringUTF16 = ::java::lang::StringUTF16;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $Objects = ::java::util::Objects;
using $Optional = ::java::util::Optional;

namespace java {
	namespace lang {

$CompoundAttribute _Integer_Annotations_[] = {
	{"Ljdk/internal/ValueBased;", nullptr},
	{}
};

$NamedAttribute Integer_Attribute_var$0[] = {
	{"since", 's', "9"},
	{"forRemoval", 'Z', "true"},
	{}
};

$CompoundAttribute _Integer_MethodAnnotations_init$0[] = {
	{"Ljava/lang/Deprecated;", Integer_Attribute_var$0},
	{}
};

$NamedAttribute Integer_Attribute_var$1[] = {
	{"since", 's', "9"},
	{"forRemoval", 'Z', "true"},
	{}
};

$CompoundAttribute _Integer_MethodAnnotations_init$1[] = {
	{"Ljava/lang/Deprecated;", Integer_Attribute_var$1},
	{}
};

$CompoundAttribute _Integer_MethodAnnotations_bitCount2[] = {
	{"Ljdk/internal/vm/annotation/IntrinsicCandidate;", nullptr},
	{}
};

$CompoundAttribute _Integer_MethodAnnotations_intValue23[] = {
	{"Ljdk/internal/vm/annotation/IntrinsicCandidate;", nullptr},
	{}
};

$CompoundAttribute _Integer_MethodAnnotations_numberOfLeadingZeros28[] = {
	{"Ljdk/internal/vm/annotation/IntrinsicCandidate;", nullptr},
	{}
};

$CompoundAttribute _Integer_MethodAnnotations_numberOfTrailingZeros29[] = {
	{"Ljdk/internal/vm/annotation/IntrinsicCandidate;", nullptr},
	{}
};

$CompoundAttribute _Integer_MethodAnnotations_reverseBytes39[] = {
	{"Ljdk/internal/vm/annotation/IntrinsicCandidate;", nullptr},
	{}
};

$CompoundAttribute _Integer_MethodAnnotations_toString50[] = {
	{"Ljdk/internal/vm/annotation/IntrinsicCandidate;", nullptr},
	{}
};

$CompoundAttribute _Integer_MethodAnnotations_valueOf59[] = {
	{"Ljdk/internal/vm/annotation/IntrinsicCandidate;", nullptr},
	{}
};

$FieldInfo _Integer_FieldInfo_[] = {
	{"MIN_VALUE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Integer, MIN_VALUE)},
	{"MAX_VALUE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Integer, MAX_VALUE)},
	{"TYPE", "Ljava/lang/Class;", "Ljava/lang/Class<Ljava/lang/Integer;>;", $PUBLIC | $STATIC | $FINAL, $staticField(Integer, TYPE)},
	{"digits", "[C", nullptr, $STATIC | $FINAL, $staticField(Integer, digits)},
	{"DigitTens", "[B", nullptr, $STATIC | $FINAL, $staticField(Integer, DigitTens)},
	{"DigitOnes", "[B", nullptr, $STATIC | $FINAL, $staticField(Integer, DigitOnes)},
	{"sizeTable", "[I", nullptr, $STATIC | $FINAL, $staticField(Integer, sizeTable)},
	{"value", "I", nullptr, $PRIVATE | $FINAL, $field(Integer, value)},
	{"SIZE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Integer, SIZE)},
	{"BYTES", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Integer, BYTES)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Integer, serialVersionUID)},
	{}
};

$MethodInfo _Integer_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "(I)V", nullptr, $PUBLIC | $DEPRECATED, $method(Integer, init$, void, int32_t), nullptr, nullptr, _Integer_MethodAnnotations_init$0},
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC | $DEPRECATED, $method(Integer, init$, void, $String*), "java.lang.NumberFormatException", nullptr, _Integer_MethodAnnotations_init$1},
	{"bitCount", "(I)I", nullptr, $PUBLIC | $STATIC, $staticMethod(Integer, bitCount, int32_t, int32_t), nullptr, nullptr, _Integer_MethodAnnotations_bitCount2},
	{"byteValue", "()B", nullptr, $PUBLIC, $virtualMethod(Integer, byteValue, int8_t)},
	{"compare", "(II)I", nullptr, $PUBLIC | $STATIC, $staticMethod(Integer, compare, int32_t, int32_t, int32_t)},
	{"compareTo", "(Ljava/lang/Integer;)I", nullptr, $PUBLIC, $method(Integer, compareTo, int32_t, Integer*)},
	{"compareTo", "(Ljava/lang/Object;)I", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(Integer, compareTo, int32_t, Object$*)},
	{"compareUnsigned", "(II)I", nullptr, $PUBLIC | $STATIC, $staticMethod(Integer, compareUnsigned, int32_t, int32_t, int32_t)},
	{"decode", "(Ljava/lang/String;)Ljava/lang/Integer;", nullptr, $PUBLIC | $STATIC, $staticMethod(Integer, decode, Integer*, $String*), "java.lang.NumberFormatException"},
	{"describeConstable", "()Ljava/util/Optional;", "()Ljava/util/Optional<Ljava/lang/Integer;>;", $PUBLIC, $virtualMethod(Integer, describeConstable, $Optional*)},
	{"divideUnsigned", "(II)I", nullptr, $PUBLIC | $STATIC, $staticMethod(Integer, divideUnsigned, int32_t, int32_t, int32_t)},
	{"doubleValue", "()D", nullptr, $PUBLIC, $virtualMethod(Integer, doubleValue, double)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(Integer, equals, bool, Object$*)},
	{"floatValue", "()F", nullptr, $PUBLIC, $virtualMethod(Integer, floatValue, float)},
	{"formatUnsignedInt", "(II[BI)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Integer, formatUnsignedInt, void, int32_t, int32_t, $bytes*, int32_t)},
	{"formatUnsignedIntUTF16", "(II[BI)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Integer, formatUnsignedIntUTF16, void, int32_t, int32_t, $bytes*, int32_t)},
	{"getChars", "(II[B)I", nullptr, $STATIC, $staticMethod(Integer, getChars, int32_t, int32_t, int32_t, $bytes*)},
	{"getInteger", "(Ljava/lang/String;)Ljava/lang/Integer;", nullptr, $PUBLIC | $STATIC, $staticMethod(Integer, getInteger, Integer*, $String*)},
	{"getInteger", "(Ljava/lang/String;I)Ljava/lang/Integer;", nullptr, $PUBLIC | $STATIC, $staticMethod(Integer, getInteger, Integer*, $String*, int32_t)},
	{"getInteger", "(Ljava/lang/String;Ljava/lang/Integer;)Ljava/lang/Integer;", nullptr, $PUBLIC | $STATIC, $staticMethod(Integer, getInteger, Integer*, $String*, Integer*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(Integer, hashCode, int32_t)},
	{"hashCode", "(I)I", nullptr, $PUBLIC | $STATIC, $staticMethod(Integer, hashCode, int32_t, int32_t)},
	{"highestOneBit", "(I)I", nullptr, $PUBLIC | $STATIC, $staticMethod(Integer, highestOneBit, int32_t, int32_t)},
	{"intValue", "()I", nullptr, $PUBLIC, $virtualMethod(Integer, intValue, int32_t), nullptr, nullptr, _Integer_MethodAnnotations_intValue23},
	{"longValue", "()J", nullptr, $PUBLIC, $virtualMethod(Integer, longValue, int64_t)},
	{"lowestOneBit", "(I)I", nullptr, $PUBLIC | $STATIC, $staticMethod(Integer, lowestOneBit, int32_t, int32_t)},
	{"max", "(II)I", nullptr, $PUBLIC | $STATIC, $staticMethod(Integer, max, int32_t, int32_t, int32_t)},
	{"min", "(II)I", nullptr, $PUBLIC | $STATIC, $staticMethod(Integer, min, int32_t, int32_t, int32_t)},
	{"numberOfLeadingZeros", "(I)I", nullptr, $PUBLIC | $STATIC, $staticMethod(Integer, numberOfLeadingZeros, int32_t, int32_t), nullptr, nullptr, _Integer_MethodAnnotations_numberOfLeadingZeros28},
	{"numberOfTrailingZeros", "(I)I", nullptr, $PUBLIC | $STATIC, $staticMethod(Integer, numberOfTrailingZeros, int32_t, int32_t), nullptr, nullptr, _Integer_MethodAnnotations_numberOfTrailingZeros29},
	{"parseInt", "(Ljava/lang/String;I)I", nullptr, $PUBLIC | $STATIC, $staticMethod(Integer, parseInt, int32_t, $String*, int32_t), "java.lang.NumberFormatException"},
	{"parseInt", "(Ljava/lang/CharSequence;III)I", nullptr, $PUBLIC | $STATIC, $staticMethod(Integer, parseInt, int32_t, $CharSequence*, int32_t, int32_t, int32_t), "java.lang.NumberFormatException"},
	{"parseInt", "(Ljava/lang/String;)I", nullptr, $PUBLIC | $STATIC, $staticMethod(Integer, parseInt, int32_t, $String*), "java.lang.NumberFormatException"},
	{"parseUnsignedInt", "(Ljava/lang/String;I)I", nullptr, $PUBLIC | $STATIC, $staticMethod(Integer, parseUnsignedInt, int32_t, $String*, int32_t), "java.lang.NumberFormatException"},
	{"parseUnsignedInt", "(Ljava/lang/CharSequence;III)I", nullptr, $PUBLIC | $STATIC, $staticMethod(Integer, parseUnsignedInt, int32_t, $CharSequence*, int32_t, int32_t, int32_t), "java.lang.NumberFormatException"},
	{"parseUnsignedInt", "(Ljava/lang/String;)I", nullptr, $PUBLIC | $STATIC, $staticMethod(Integer, parseUnsignedInt, int32_t, $String*), "java.lang.NumberFormatException"},
	{"remainderUnsigned", "(II)I", nullptr, $PUBLIC | $STATIC, $staticMethod(Integer, remainderUnsigned, int32_t, int32_t, int32_t)},
	{"resolveConstantDesc", "(Ljava/lang/invoke/MethodHandles$Lookup;)Ljava/lang/Integer;", nullptr, $PUBLIC, $virtualMethod(Integer, resolveConstantDesc, $Object*, $MethodHandles$Lookup*)},
	{"reverse", "(I)I", nullptr, $PUBLIC | $STATIC, $staticMethod(Integer, reverse, int32_t, int32_t)},
	{"reverseBytes", "(I)I", nullptr, $PUBLIC | $STATIC, $staticMethod(Integer, reverseBytes, int32_t, int32_t), nullptr, nullptr, _Integer_MethodAnnotations_reverseBytes39},
	{"rotateLeft", "(II)I", nullptr, $PUBLIC | $STATIC, $staticMethod(Integer, rotateLeft, int32_t, int32_t, int32_t)},
	{"rotateRight", "(II)I", nullptr, $PUBLIC | $STATIC, $staticMethod(Integer, rotateRight, int32_t, int32_t, int32_t)},
	{"shortValue", "()S", nullptr, $PUBLIC, $virtualMethod(Integer, shortValue, int16_t)},
	{"signum", "(I)I", nullptr, $PUBLIC | $STATIC, $staticMethod(Integer, signum, int32_t, int32_t)},
	{"stringSize", "(I)I", nullptr, $STATIC, $staticMethod(Integer, stringSize, int32_t, int32_t)},
	{"sum", "(II)I", nullptr, $PUBLIC | $STATIC, $staticMethod(Integer, sum, int32_t, int32_t, int32_t)},
	{"toBinaryString", "(I)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(Integer, toBinaryString, $String*, int32_t)},
	{"toHexString", "(I)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(Integer, toHexString, $String*, int32_t)},
	{"toOctalString", "(I)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(Integer, toOctalString, $String*, int32_t)},
	{"toString", "(II)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(Integer, toString, $String*, int32_t, int32_t)},
	{"toString", "(I)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(Integer, toString, $String*, int32_t), nullptr, nullptr, _Integer_MethodAnnotations_toString50},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Integer, toString, $String*)},
	{"toStringUTF16", "(II)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(Integer, toStringUTF16, $String*, int32_t, int32_t)},
	{"toUnsignedLong", "(I)J", nullptr, $PUBLIC | $STATIC, $staticMethod(Integer, toUnsignedLong, int64_t, int32_t)},
	{"toUnsignedString", "(II)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(Integer, toUnsignedString, $String*, int32_t, int32_t)},
	{"toUnsignedString", "(I)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(Integer, toUnsignedString, $String*, int32_t)},
	{"toUnsignedString0", "(II)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(Integer, toUnsignedString0, $String*, int32_t, int32_t)},
	{"valueOf", "(Ljava/lang/String;I)Ljava/lang/Integer;", nullptr, $PUBLIC | $STATIC, $staticMethod(Integer, valueOf, Integer*, $String*, int32_t), "java.lang.NumberFormatException"},
	{"valueOf", "(Ljava/lang/String;)Ljava/lang/Integer;", nullptr, $PUBLIC | $STATIC, $staticMethod(Integer, valueOf, Integer*, $String*), "java.lang.NumberFormatException"},
	{"valueOf", "(I)Ljava/lang/Integer;", nullptr, $PUBLIC | $STATIC, $staticMethod(Integer, valueOf, Integer*, int32_t), nullptr, nullptr, _Integer_MethodAnnotations_valueOf59},
	{}
};

$InnerClassInfo _Integer_InnerClassesInfo_[] = {
	{"java.lang.Integer$IntegerCache", "java.lang.Integer", "IntegerCache", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _Integer_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.lang.Integer",
	"java.lang.Number",
	"java.lang.Comparable,java.lang.constant.Constable,java.lang.constant.ConstantDesc",
	_Integer_FieldInfo_,
	_Integer_MethodInfo_,
	"Ljava/lang/Number;Ljava/lang/Comparable<Ljava/lang/Integer;>;Ljava/lang/constant/Constable;Ljava/lang/constant/ConstantDesc;",
	nullptr,
	_Integer_InnerClassesInfo_,
	_Integer_Annotations_,
	nullptr,
	"java.lang.Integer$IntegerCache"
};

$Object* allocate$Integer($Class* clazz) {
	return $of($alloc(Integer));
}

$Object* Integer::clone() {
	 return this->$Number::clone();
}

void Integer::finalize() {
	this->$Number::finalize();
}

$Class* Integer::TYPE = nullptr;
$chars* Integer::digits = nullptr;
$bytes* Integer::DigitTens = nullptr;
$bytes* Integer::DigitOnes = nullptr;
$ints* Integer::sizeTable = nullptr;

$String* Integer::toString(int32_t i, int32_t radix) {
	if (radix < $Character::MIN_RADIX || radix > $Character::MAX_RADIX) {
		radix = 10;
	}
	if (radix == 10) {
		return toString(i);
	}
	if ($String::COMPACT_STRINGS) {
		$var($bytes, buf, $new($bytes, 33));
		bool negative = (i < 0);
		int32_t charPos = 32;
		if (!negative) {
			i = -i;
		}
		while (i <= -radix) {
			$init(Integer);
			buf->set(charPos--, (int8_t)$nc(Integer::digits)->get(-($mod(i, radix))));
			i = $div(i, radix);
		}
		$init(Integer);
		buf->set(charPos, (int8_t)$nc(Integer::digits)->get(-i));
		if (negative) {
			buf->set(--charPos, (int8_t)u'-');
		}
		return $StringLatin1::newString(buf, charPos, (33 - charPos));
	}
	return toStringUTF16(i, radix);
}

$String* Integer::toStringUTF16(int32_t i, int32_t radix) {
	$var($bytes, buf, $new($bytes, 33 * 2));
	bool negative = (i < 0);
	int32_t charPos = 32;
	if (!negative) {
		i = -i;
	}
	while (i <= -radix) {
		$init(Integer);
		$StringUTF16::putChar(buf, charPos--, $nc(Integer::digits)->get(-($mod(i, radix))));
		i = $div(i, radix);
	}
	$init(Integer);
	$StringUTF16::putChar(buf, charPos, $nc(Integer::digits)->get(-i));
	if (negative) {
		$StringUTF16::putChar(buf, --charPos, u'-');
	}
	return $StringUTF16::newString(buf, charPos, (33 - charPos));
}

$String* Integer::toUnsignedString(int32_t i, int32_t radix) {
	return $Long::toUnsignedString(toUnsignedLong(i), radix);
}

$String* Integer::toHexString(int32_t i) {
	return toUnsignedString0(i, 4);
}

$String* Integer::toOctalString(int32_t i) {
	return toUnsignedString0(i, 3);
}

$String* Integer::toBinaryString(int32_t i) {
	return toUnsignedString0(i, 1);
}

$String* Integer::toUnsignedString0(int32_t val, int32_t shift) {
	$useLocalCurrentObjectStackCache();
	int32_t mag = Integer::SIZE - Integer::numberOfLeadingZeros(val);
	int32_t chars = $Math::max(($div((mag + (shift - 1)), shift)), 1);
	if ($String::COMPACT_STRINGS) {
		$var($bytes, buf, $new($bytes, chars));
		formatUnsignedInt(val, shift, buf, chars);
		return $new($String, buf, (int8_t)0);
	} else {
		$var($bytes, buf, $new($bytes, chars * 2));
		formatUnsignedIntUTF16(val, shift, buf, chars);
		return $new($String, buf, (int8_t)1);
	}
}

void Integer::formatUnsignedInt(int32_t val, int32_t shift, $bytes* buf, int32_t len) {
	int32_t charPos = len;
	int32_t radix = $sl(1, shift);
	int32_t mask = radix - 1;
	do {
		$init(Integer);
		$nc(buf)->set(--charPos, (int8_t)$nc(Integer::digits)->get((int32_t)(val & (uint32_t)mask)));
		$usrAssign(val, shift);
	} while (charPos > 0);
}

void Integer::formatUnsignedIntUTF16(int32_t val, int32_t shift, $bytes* buf, int32_t len) {
	int32_t charPos = len;
	int32_t radix = $sl(1, shift);
	int32_t mask = radix - 1;
	do {
		$init(Integer);
		$StringUTF16::putChar(buf, --charPos, $nc(Integer::digits)->get((int32_t)(val & (uint32_t)mask)));
		$usrAssign(val, shift);
	} while (charPos > 0);
}

$String* Integer::toString(int32_t i) {
	$useLocalCurrentObjectStackCache();
	int32_t size = stringSize(i);
	if ($String::COMPACT_STRINGS) {
		$var($bytes, buf, $new($bytes, size));
		getChars(i, size, buf);
		return $new($String, buf, (int8_t)0);
	} else {
		$var($bytes, buf, $new($bytes, size * 2));
		$StringUTF16::getChars(i, size, buf);
		return $new($String, buf, (int8_t)1);
	}
}

$String* Integer::toUnsignedString(int32_t i) {
	return $Long::toString(toUnsignedLong(i));
}

int32_t Integer::getChars(int32_t i, int32_t index, $bytes* buf) {
	int32_t q = 0;
	int32_t r = 0;
	int32_t charPos = index;
	bool negative = i < 0;
	if (!negative) {
		i = -i;
	}
	while (i <= -100) {
		q = i / 100;
		r = (q * 100) - i;
		i = q;
		$init(Integer);
		$nc(buf)->set(--charPos, $nc(Integer::DigitOnes)->get(r));
		buf->set(--charPos, $nc(Integer::DigitTens)->get(r));
	}
	q = i / 10;
	r = (q * 10) - i;
	$nc(buf)->set(--charPos, (int8_t)(u'0' + r));
	if (q < 0) {
		buf->set(--charPos, (int8_t)(u'0' - q));
	}
	if (negative) {
		buf->set(--charPos, (int8_t)u'-');
	}
	return charPos;
}

int32_t Integer::stringSize(int32_t x) {
	int32_t d = 1;
	if (x >= 0) {
		d = 0;
		x = -x;
	}
	int32_t p = -10;
	for (int32_t i = 1; i < 10; ++i) {
		if (x > p) {
			return i + d;
		}
		p = 10 * p;
	}
	return 10 + d;
}

int32_t Integer::parseInt($String* s, int32_t radix) {
	$useLocalCurrentObjectStackCache();
	if (s == nullptr) {
		$throwNew($NumberFormatException, "Cannot parse null string"_s);
	}
	if (radix < $Character::MIN_RADIX) {
		$throwNew($NumberFormatException, $$str({"radix "_s, $$str(radix), " less than Character.MIN_RADIX"_s}));
	}
	if (radix > $Character::MAX_RADIX) {
		$throwNew($NumberFormatException, $$str({"radix "_s, $$str(radix), " greater than Character.MAX_RADIX"_s}));
	}
	bool negative = false;
	int32_t i = 0;
	int32_t len = $nc(s)->length();
	int32_t limit = -Integer::MAX_VALUE;
	if (len > 0) {
		char16_t firstChar = s->charAt(0);
		if (firstChar < u'0') {
			if (firstChar == u'-') {
				negative = true;
				limit = Integer::MIN_VALUE;
			} else if (firstChar != u'+') {
				$throw($($NumberFormatException::forInputString(s, radix)));
			}
			if (len == 1) {
				$throw($($NumberFormatException::forInputString(s, radix)));
			}
			++i;
		}
		int32_t multmin = $div(limit, radix);
		int32_t result = 0;
		while (i < len) {
			int32_t digit = $Character::digit(s->charAt(i++), radix);
			if (digit < 0 || result < multmin) {
				$throw($($NumberFormatException::forInputString(s, radix)));
			}
			result *= radix;
			if (result < limit + digit) {
				$throw($($NumberFormatException::forInputString(s, radix)));
			}
			result -= digit;
		}
		return negative ? result : -result;
	} else {
		$throw($($NumberFormatException::forInputString(s, radix)));
	}
}

int32_t Integer::parseInt($CharSequence* s, int32_t beginIndex, int32_t endIndex, int32_t radix) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(s);
	if (beginIndex < 0 || beginIndex > endIndex || endIndex > s->length()) {
		$throwNew($IndexOutOfBoundsException);
	}
	if (radix < $Character::MIN_RADIX) {
		$throwNew($NumberFormatException, $$str({"radix "_s, $$str(radix), " less than Character.MIN_RADIX"_s}));
	}
	if (radix > $Character::MAX_RADIX) {
		$throwNew($NumberFormatException, $$str({"radix "_s, $$str(radix), " greater than Character.MAX_RADIX"_s}));
	}
	bool negative = false;
	int32_t i = beginIndex;
	int32_t limit = -Integer::MAX_VALUE;
	if (i < endIndex) {
		char16_t firstChar = s->charAt(i);
		if (firstChar < u'0') {
			if (firstChar == u'-') {
				negative = true;
				limit = Integer::MIN_VALUE;
			} else if (firstChar != u'+') {
				$throw($($NumberFormatException::forCharSequence(s, beginIndex, endIndex, i)));
			}
			++i;
			if (i == endIndex) {
				$throw($($NumberFormatException::forCharSequence(s, beginIndex, endIndex, i)));
			}
		}
		int32_t multmin = $div(limit, radix);
		int32_t result = 0;
		while (i < endIndex) {
			int32_t digit = $Character::digit(s->charAt(i), radix);
			if (digit < 0 || result < multmin) {
				$throw($($NumberFormatException::forCharSequence(s, beginIndex, endIndex, i)));
			}
			result *= radix;
			if (result < limit + digit) {
				$throw($($NumberFormatException::forCharSequence(s, beginIndex, endIndex, i)));
			}
			++i;
			result -= digit;
		}
		return negative ? result : -result;
	} else {
		$throw($($NumberFormatException::forInputString(""_s, radix)));
	}
}

int32_t Integer::parseInt($String* s) {
	return parseInt(s, 10);
}

int32_t Integer::parseUnsignedInt($String* s, int32_t radix) {
	$useLocalCurrentObjectStackCache();
	if (s == nullptr) {
		$throwNew($NumberFormatException, "Cannot parse null string"_s);
	}
	int32_t len = $nc(s)->length();
	if (len > 0) {
		char16_t firstChar = s->charAt(0);
		if (firstChar == u'-') {
			$throwNew($NumberFormatException, $($String::format("Illegal leading minus sign on unsigned string %s."_s, $$new($ObjectArray, {$of(s)}))));
		} else if (len <= 5 || (radix == 10 && len <= 9)) {
			return parseInt(s, radix);
		} else {
			int64_t ell = $Long::parseLong(s, radix);
			if (((int64_t)(ell & (uint64_t)(int64_t)0xFFFFFFFF00000000)) == 0) {
				return (int32_t)ell;
			} else {
				$throwNew($NumberFormatException, $($String::format("String value %s exceeds range of unsigned int."_s, $$new($ObjectArray, {$of(s)}))));
			}
		}
	} else {
		$throw($($NumberFormatException::forInputString(s, radix)));
	}
}

int32_t Integer::parseUnsignedInt($CharSequence* s, int32_t beginIndex, int32_t endIndex, int32_t radix) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(s);
	if (beginIndex < 0 || beginIndex > endIndex || endIndex > s->length()) {
		$throwNew($IndexOutOfBoundsException);
	}
	int32_t start = beginIndex;
	int32_t len = endIndex - beginIndex;
	if (len > 0) {
		char16_t firstChar = s->charAt(start);
		if (firstChar == u'-') {
			$throwNew($NumberFormatException, $($String::format("Illegal leading minus sign on unsigned string %s."_s, $$new($ObjectArray, {$of(s)}))));
		} else if (len <= 5 || (radix == 10 && len <= 9)) {
			return parseInt(s, start, start + len, radix);
		} else {
			int64_t ell = $Long::parseLong(s, start, start + len, radix);
			if (((int64_t)(ell & (uint64_t)(int64_t)0xFFFFFFFF00000000)) == 0) {
				return (int32_t)ell;
			} else {
				$throwNew($NumberFormatException, $($String::format("String value %s exceeds range of unsigned int."_s, $$new($ObjectArray, {$of(s)}))));
			}
		}
	} else {
		$throwNew($NumberFormatException, ""_s);
	}
}

int32_t Integer::parseUnsignedInt($String* s) {
	return parseUnsignedInt(s, 10);
}

Integer* Integer::valueOf($String* s, int32_t radix) {
	return Integer::valueOf(parseInt(s, radix));
}

Integer* Integer::valueOf($String* s) {
	return Integer::valueOf(parseInt(s, 10));
}

Integer* Integer::valueOf(int32_t i) {
	$init($Integer$IntegerCache);
	if (i >= $Integer$IntegerCache::low && i <= $Integer$IntegerCache::high) {
		return $nc($Integer$IntegerCache::cache)->get(i + (-$Integer$IntegerCache::low));
	}
	return $new(Integer, i);
}

void Integer::init$(int32_t value) {
	$Number::init$();
	this->value = value;
}

void Integer::init$($String* s) {
	$Number::init$();
	this->value = parseInt(s, 10);
}

int8_t Integer::byteValue() {
	return (int8_t)this->value;
}

int16_t Integer::shortValue() {
	return (int16_t)this->value;
}

int32_t Integer::intValue() {
	return this->value;
}

int64_t Integer::longValue() {
	return (int64_t)this->value;
}

float Integer::floatValue() {
	return (float)this->value;
}

double Integer::doubleValue() {
	return (double)this->value;
}

$String* Integer::toString() {
	return toString(this->value);
}

int32_t Integer::hashCode() {
	return Integer::hashCode(this->value);
}

int32_t Integer::hashCode(int32_t value) {
	return value;
}

bool Integer::equals(Object$* obj) {
	if ($instanceOf(Integer, obj)) {
		return this->value == $nc(($cast(Integer, obj)))->intValue();
	}
	return false;
}

Integer* Integer::getInteger($String* nm) {
	return getInteger(nm, (Integer*)nullptr);
}

Integer* Integer::getInteger($String* nm, int32_t val) {
	$var(Integer, result, getInteger(nm, (Integer*)nullptr));
	return (result == nullptr) ? Integer::valueOf(val) : result;
}

Integer* Integer::getInteger($String* nm, Integer* val) {
	$var($String, v, nullptr);
	try {
		$assign(v, $System::getProperty(nm));
	} catch ($IllegalArgumentException& e) {
	} catch ($NullPointerException& e) {
	}
	if (v != nullptr) {
		try {
			return Integer::decode(v);
		} catch ($NumberFormatException& e) {
		}
	}
	return val;
}

Integer* Integer::decode($String* nm) {
	$useLocalCurrentObjectStackCache();
	int32_t radix = 10;
	int32_t index = 0;
	bool negative = false;
	$var(Integer, result, nullptr);
	if ($nc(nm)->isEmpty()) {
		$throwNew($NumberFormatException, "Zero length string"_s);
	}
	char16_t firstChar = $nc(nm)->charAt(0);
	if (firstChar == u'-') {
		negative = true;
		++index;
	} else if (firstChar == u'+') {
		++index;
	}
	bool var$0 = nm->startsWith("0x"_s, index);
	if (var$0 || nm->startsWith("0X"_s, index)) {
		index += 2;
		radix = 16;
	} else if (nm->startsWith("#"_s, index)) {
		++index;
		radix = 16;
	} else {
		bool var$2 = nm->startsWith("0"_s, index);
		if (var$2 && nm->length() > 1 + index) {
			++index;
			radix = 8;
		}
	}
	bool var$3 = nm->startsWith("-"_s, index);
	if (var$3 || nm->startsWith("+"_s, index)) {
		$throwNew($NumberFormatException, "Sign character in wrong position"_s);
	}
	try {
		$assign(result, Integer::valueOf($(nm->substring(index)), radix));
		$assign(result, negative ? Integer::valueOf(-$nc(result)->intValue()) : result);
	} catch ($NumberFormatException& e) {
		$var($String, constant, negative ? ($str({"-"_s, $(nm->substring(index))})) : nm->substring(index));
		$assign(result, Integer::valueOf(constant, radix));
	}
	return result;
}

int32_t Integer::compareTo(Integer* anotherInteger) {
	return compare(this->value, $nc(anotherInteger)->value);
}

int32_t Integer::compare(int32_t x, int32_t y) {
	return (x < y) ? -1 : ((x == y) ? 0 : 1);
}

int32_t Integer::compareUnsigned(int32_t x, int32_t y) {
	return compare(x + Integer::MIN_VALUE, y + Integer::MIN_VALUE);
}

int64_t Integer::toUnsignedLong(int32_t x) {
	return (int64_t)(((int64_t)x) & (uint64_t)(int64_t)0x00000000FFFFFFFF);
}

int32_t Integer::divideUnsigned(int32_t dividend, int32_t divisor) {
	int64_t var$0 = toUnsignedLong(dividend);
	return (int32_t)($div(var$0, toUnsignedLong(divisor)));
}

int32_t Integer::remainderUnsigned(int32_t dividend, int32_t divisor) {
	int64_t var$0 = toUnsignedLong(dividend);
	return (int32_t)($mod(var$0, toUnsignedLong(divisor)));
}

int32_t Integer::highestOneBit(int32_t i) {
	return (int32_t)(i & (uint32_t)($usr(Integer::MIN_VALUE, numberOfLeadingZeros(i))));
}

int32_t Integer::lowestOneBit(int32_t i) {
	return (int32_t)(i & (uint32_t)-i);
}

int32_t Integer::numberOfLeadingZeros(int32_t i) {
	if (i <= 0) {
		return i == 0 ? 32 : 0;
	}
	int32_t n = 31;
	if (i >= 1 << 16) {
		n -= 16;
		$usrAssign(i, 16);
	}
	if (i >= 1 << 8) {
		n -= 8;
		$usrAssign(i, 8);
	}
	if (i >= 1 << 4) {
		n -= 4;
		$usrAssign(i, 4);
	}
	if (i >= 1 << 2) {
		n -= 2;
		$usrAssign(i, 2);
	}
	return n - ((int32_t)((uint32_t)i >> 1));
}

int32_t Integer::numberOfTrailingZeros(int32_t i) {
	i = (int32_t)(~i & (uint32_t)(i - 1));
	if (i <= 0) {
		return (int32_t)(i & (uint32_t)32);
	}
	int32_t n = 1;
	if (i > 1 << 16) {
		n += 16;
		$usrAssign(i, 16);
	}
	if (i > 1 << 8) {
		n += 8;
		$usrAssign(i, 8);
	}
	if (i > 1 << 4) {
		n += 4;
		$usrAssign(i, 4);
	}
	if (i > 1 << 2) {
		n += 2;
		$usrAssign(i, 2);
	}
	return n + ((int32_t)((uint32_t)i >> 1));
}

int32_t Integer::bitCount(int32_t i) {
	i = i - ((int32_t)(((int32_t)((uint32_t)i >> 1)) & (uint32_t)0x55555555));
	i = ((int32_t)(i & (uint32_t)0x33333333)) + ((int32_t)(((int32_t)((uint32_t)i >> 2)) & (uint32_t)0x33333333));
	i = (int32_t)((i + ((int32_t)((uint32_t)i >> 4))) & (uint32_t)0x0F0F0F0F);
	i = i + ((int32_t)((uint32_t)i >> 8));
	i = i + ((int32_t)((uint32_t)i >> 16));
	return (int32_t)(i & (uint32_t)63);
}

int32_t Integer::rotateLeft(int32_t i, int32_t distance) {
	return ($sl(i, distance)) | ($usr(i, -distance));
}

int32_t Integer::rotateRight(int32_t i, int32_t distance) {
	return ($usr(i, distance)) | ($sl(i, -distance));
}

int32_t Integer::reverse(int32_t i) {
	i = (((int32_t)(i & (uint32_t)0x55555555)) << 1) | ((int32_t)(((int32_t)((uint32_t)i >> 1)) & (uint32_t)0x55555555));
	i = (((int32_t)(i & (uint32_t)0x33333333)) << 2) | ((int32_t)(((int32_t)((uint32_t)i >> 2)) & (uint32_t)0x33333333));
	i = (((int32_t)(i & (uint32_t)0x0F0F0F0F)) << 4) | ((int32_t)(((int32_t)((uint32_t)i >> 4)) & (uint32_t)0x0F0F0F0F));
	return reverseBytes(i);
}

int32_t Integer::signum(int32_t i) {
	return (i >> 31) | ((int32_t)((uint32_t)-i >> 31));
}

int32_t Integer::reverseBytes(int32_t i) {
	return (((i << 24) | (((int32_t)(i & (uint32_t)0x0000FF00)) << 8)) | ((int32_t)(((int32_t)((uint32_t)i >> 8)) & (uint32_t)0x0000FF00))) | ((int32_t)((uint32_t)i >> 24));
}

int32_t Integer::sum(int32_t a, int32_t b) {
	return a + b;
}

int32_t Integer::max(int32_t a, int32_t b) {
	return $Math::max(a, b);
}

int32_t Integer::min(int32_t a, int32_t b) {
	return $Math::min(a, b);
}

$Optional* Integer::describeConstable() {
	return $Optional::of(this);
}

$Object* Integer::resolveConstantDesc($MethodHandles$Lookup* lookup) {
	return $of(this);
}

int32_t Integer::compareTo(Object$* anotherInteger) {
	return this->compareTo($cast(Integer, anotherInteger));
}

void clinit$Integer($Class* class$) {
	$assignStatic(Integer::TYPE, $Class::getPrimitiveClass("int"_s));
	$assignStatic(Integer::digits, $new($chars, {
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
		u'a',
		u'b',
		u'c',
		u'd',
		u'e',
		u'f',
		u'g',
		u'h',
		u'i',
		u'j',
		u'k',
		u'l',
		u'm',
		u'n',
		u'o',
		u'p',
		u'q',
		u'r',
		u's',
		u't',
		u'u',
		u'v',
		u'w',
		u'x',
		u'y',
		u'z'
	}));
	$assignStatic(Integer::DigitTens, $new($bytes, {
		(int8_t)u'0',
		(int8_t)u'0',
		(int8_t)u'0',
		(int8_t)u'0',
		(int8_t)u'0',
		(int8_t)u'0',
		(int8_t)u'0',
		(int8_t)u'0',
		(int8_t)u'0',
		(int8_t)u'0',
		(int8_t)u'1',
		(int8_t)u'1',
		(int8_t)u'1',
		(int8_t)u'1',
		(int8_t)u'1',
		(int8_t)u'1',
		(int8_t)u'1',
		(int8_t)u'1',
		(int8_t)u'1',
		(int8_t)u'1',
		(int8_t)u'2',
		(int8_t)u'2',
		(int8_t)u'2',
		(int8_t)u'2',
		(int8_t)u'2',
		(int8_t)u'2',
		(int8_t)u'2',
		(int8_t)u'2',
		(int8_t)u'2',
		(int8_t)u'2',
		(int8_t)u'3',
		(int8_t)u'3',
		(int8_t)u'3',
		(int8_t)u'3',
		(int8_t)u'3',
		(int8_t)u'3',
		(int8_t)u'3',
		(int8_t)u'3',
		(int8_t)u'3',
		(int8_t)u'3',
		(int8_t)u'4',
		(int8_t)u'4',
		(int8_t)u'4',
		(int8_t)u'4',
		(int8_t)u'4',
		(int8_t)u'4',
		(int8_t)u'4',
		(int8_t)u'4',
		(int8_t)u'4',
		(int8_t)u'4',
		(int8_t)u'5',
		(int8_t)u'5',
		(int8_t)u'5',
		(int8_t)u'5',
		(int8_t)u'5',
		(int8_t)u'5',
		(int8_t)u'5',
		(int8_t)u'5',
		(int8_t)u'5',
		(int8_t)u'5',
		(int8_t)u'6',
		(int8_t)u'6',
		(int8_t)u'6',
		(int8_t)u'6',
		(int8_t)u'6',
		(int8_t)u'6',
		(int8_t)u'6',
		(int8_t)u'6',
		(int8_t)u'6',
		(int8_t)u'6',
		(int8_t)u'7',
		(int8_t)u'7',
		(int8_t)u'7',
		(int8_t)u'7',
		(int8_t)u'7',
		(int8_t)u'7',
		(int8_t)u'7',
		(int8_t)u'7',
		(int8_t)u'7',
		(int8_t)u'7',
		(int8_t)u'8',
		(int8_t)u'8',
		(int8_t)u'8',
		(int8_t)u'8',
		(int8_t)u'8',
		(int8_t)u'8',
		(int8_t)u'8',
		(int8_t)u'8',
		(int8_t)u'8',
		(int8_t)u'8',
		(int8_t)u'9',
		(int8_t)u'9',
		(int8_t)u'9',
		(int8_t)u'9',
		(int8_t)u'9',
		(int8_t)u'9',
		(int8_t)u'9',
		(int8_t)u'9',
		(int8_t)u'9',
		(int8_t)u'9'
	}));
	$assignStatic(Integer::DigitOnes, $new($bytes, {
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
		(int8_t)u'0',
		(int8_t)u'1',
		(int8_t)u'2',
		(int8_t)u'3',
		(int8_t)u'4',
		(int8_t)u'5',
		(int8_t)u'6',
		(int8_t)u'7',
		(int8_t)u'8',
		(int8_t)u'9'
	}));
	$assignStatic(Integer::sizeTable, $new($ints, {
		9,
		99,
		999,
		9999,
		0x0001869F,
		0x000F423F,
		0x0098967F,
		0x05F5E0FF,
		0x3B9AC9FF,
		Integer::MAX_VALUE
	}));
}

Integer::Integer() {
}

$Class* Integer::load$($String* name, bool initialize) {
	$loadClass(Integer, name, initialize, &_Integer_ClassInfo_, clinit$Integer, allocate$Integer);
	return class$;
}

$Class* Integer::class$ = nullptr;

	} // lang
} // java