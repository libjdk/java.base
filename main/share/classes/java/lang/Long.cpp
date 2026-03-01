#include <java/lang/Long.h>

#include <java/lang/CharSequence.h>
#include <java/lang/IndexOutOfBoundsException.h>
#include <java/lang/Long$LongCache.h>
#include <java/lang/Math.h>
#include <java/lang/Number.h>
#include <java/lang/NumberFormatException.h>
#include <java/lang/StringLatin1.h>
#include <java/lang/StringUTF16.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/math/BigInteger.h>
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
using $Integer = ::java::lang::Integer;
using $Long$LongCache = ::java::lang::Long$LongCache;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $NamedAttribute = ::java::lang::NamedAttribute;
using $NullPointerException = ::java::lang::NullPointerException;
using $Number = ::java::lang::Number;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $StringLatin1 = ::java::lang::StringLatin1;
using $StringUTF16 = ::java::lang::StringUTF16;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $BigInteger = ::java::math::BigInteger;
using $Objects = ::java::util::Objects;
using $Optional = ::java::util::Optional;

namespace java {
	namespace lang {

$CompoundAttribute _Long_Annotations_[] = {
	{"Ljdk/internal/ValueBased;", nullptr},
	{}
};

$NamedAttribute Long_Attribute_var$0[] = {
	{"since", 's', "9"},
	{"forRemoval", 'Z', "true"},
	{}
};

$CompoundAttribute _Long_MethodAnnotations_init$0[] = {
	{"Ljava/lang/Deprecated;", Long_Attribute_var$0},
	{}
};

$NamedAttribute Long_Attribute_var$1[] = {
	{"since", 's', "9"},
	{"forRemoval", 'Z', "true"},
	{}
};

$CompoundAttribute _Long_MethodAnnotations_init$1[] = {
	{"Ljava/lang/Deprecated;", Long_Attribute_var$1},
	{}
};

$CompoundAttribute _Long_MethodAnnotations_bitCount2[] = {
	{"Ljdk/internal/vm/annotation/IntrinsicCandidate;", nullptr},
	{}
};

$CompoundAttribute _Long_MethodAnnotations_longValue25[] = {
	{"Ljdk/internal/vm/annotation/IntrinsicCandidate;", nullptr},
	{}
};

$CompoundAttribute _Long_MethodAnnotations_numberOfLeadingZeros29[] = {
	{"Ljdk/internal/vm/annotation/IntrinsicCandidate;", nullptr},
	{}
};

$CompoundAttribute _Long_MethodAnnotations_numberOfTrailingZeros30[] = {
	{"Ljdk/internal/vm/annotation/IntrinsicCandidate;", nullptr},
	{}
};

$CompoundAttribute _Long_MethodAnnotations_reverseBytes40[] = {
	{"Ljdk/internal/vm/annotation/IntrinsicCandidate;", nullptr},
	{}
};

$CompoundAttribute _Long_MethodAnnotations_valueOf60[] = {
	{"Ljdk/internal/vm/annotation/IntrinsicCandidate;", nullptr},
	{}
};

$FieldInfo _Long_FieldInfo_[] = {
	{"MIN_VALUE", "J", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Long, MIN_VALUE)},
	{"MAX_VALUE", "J", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Long, MAX_VALUE)},
	{"TYPE", "Ljava/lang/Class;", "Ljava/lang/Class<Ljava/lang/Long;>;", $PUBLIC | $STATIC | $FINAL, $staticField(Long, TYPE)},
	{"value", "J", nullptr, $PRIVATE | $FINAL, $field(Long, value)},
	{"SIZE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Long, SIZE)},
	{"BYTES", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Long, BYTES)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Long, serialVersionUID)},
	{}
};

$MethodInfo _Long_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "(J)V", nullptr, $PUBLIC | $DEPRECATED, $method(Long, init$, void, int64_t), nullptr, nullptr, _Long_MethodAnnotations_init$0},
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC | $DEPRECATED, $method(Long, init$, void, $String*), "java.lang.NumberFormatException", nullptr, _Long_MethodAnnotations_init$1},
	{"bitCount", "(J)I", nullptr, $PUBLIC | $STATIC, $staticMethod(Long, bitCount, int32_t, int64_t), nullptr, nullptr, _Long_MethodAnnotations_bitCount2},
	{"byteValue", "()B", nullptr, $PUBLIC, $virtualMethod(Long, byteValue, int8_t)},
	{"compare", "(JJ)I", nullptr, $PUBLIC | $STATIC, $staticMethod(Long, compare, int32_t, int64_t, int64_t)},
	{"compareTo", "(Ljava/lang/Long;)I", nullptr, $PUBLIC, $method(Long, compareTo, int32_t, Long*)},
	{"compareTo", "(Ljava/lang/Object;)I", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(Long, compareTo, int32_t, Object$*)},
	{"compareUnsigned", "(JJ)I", nullptr, $PUBLIC | $STATIC, $staticMethod(Long, compareUnsigned, int32_t, int64_t, int64_t)},
	{"decode", "(Ljava/lang/String;)Ljava/lang/Long;", nullptr, $PUBLIC | $STATIC, $staticMethod(Long, decode, Long*, $String*), "java.lang.NumberFormatException"},
	{"describeConstable", "()Ljava/util/Optional;", "()Ljava/util/Optional<Ljava/lang/Long;>;", $PUBLIC, $virtualMethod(Long, describeConstable, $Optional*)},
	{"divideUnsigned", "(JJ)J", nullptr, $PUBLIC | $STATIC, $staticMethod(Long, divideUnsigned, int64_t, int64_t, int64_t)},
	{"doubleValue", "()D", nullptr, $PUBLIC, $virtualMethod(Long, doubleValue, double)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(Long, equals, bool, Object$*)},
	{"fastUUID", "(JJ)Ljava/lang/String;", nullptr, $STATIC, $staticMethod(Long, fastUUID, $String*, int64_t, int64_t)},
	{"floatValue", "()F", nullptr, $PUBLIC, $virtualMethod(Long, floatValue, float)},
	{"formatUnsignedLong0", "(JI[BII)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Long, formatUnsignedLong0, void, int64_t, int32_t, $bytes*, int32_t, int32_t)},
	{"formatUnsignedLong0UTF16", "(JI[BII)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Long, formatUnsignedLong0UTF16, void, int64_t, int32_t, $bytes*, int32_t, int32_t)},
	{"getChars", "(JI[B)I", nullptr, $STATIC, $staticMethod(Long, getChars, int32_t, int64_t, int32_t, $bytes*)},
	{"getLong", "(Ljava/lang/String;)Ljava/lang/Long;", nullptr, $PUBLIC | $STATIC, $staticMethod(Long, getLong, Long*, $String*)},
	{"getLong", "(Ljava/lang/String;J)Ljava/lang/Long;", nullptr, $PUBLIC | $STATIC, $staticMethod(Long, getLong, Long*, $String*, int64_t)},
	{"getLong", "(Ljava/lang/String;Ljava/lang/Long;)Ljava/lang/Long;", nullptr, $PUBLIC | $STATIC, $staticMethod(Long, getLong, Long*, $String*, Long*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(Long, hashCode, int32_t)},
	{"hashCode", "(J)I", nullptr, $PUBLIC | $STATIC, $staticMethod(Long, hashCode, int32_t, int64_t)},
	{"highestOneBit", "(J)J", nullptr, $PUBLIC | $STATIC, $staticMethod(Long, highestOneBit, int64_t, int64_t)},
	{"intValue", "()I", nullptr, $PUBLIC, $virtualMethod(Long, intValue, int32_t)},
	{"longValue", "()J", nullptr, $PUBLIC, $virtualMethod(Long, longValue, int64_t), nullptr, nullptr, _Long_MethodAnnotations_longValue25},
	{"lowestOneBit", "(J)J", nullptr, $PUBLIC | $STATIC, $staticMethod(Long, lowestOneBit, int64_t, int64_t)},
	{"max", "(JJ)J", nullptr, $PUBLIC | $STATIC, $staticMethod(Long, max, int64_t, int64_t, int64_t)},
	{"min", "(JJ)J", nullptr, $PUBLIC | $STATIC, $staticMethod(Long, min, int64_t, int64_t, int64_t)},
	{"numberOfLeadingZeros", "(J)I", nullptr, $PUBLIC | $STATIC, $staticMethod(Long, numberOfLeadingZeros, int32_t, int64_t), nullptr, nullptr, _Long_MethodAnnotations_numberOfLeadingZeros29},
	{"numberOfTrailingZeros", "(J)I", nullptr, $PUBLIC | $STATIC, $staticMethod(Long, numberOfTrailingZeros, int32_t, int64_t), nullptr, nullptr, _Long_MethodAnnotations_numberOfTrailingZeros30},
	{"parseLong", "(Ljava/lang/String;I)J", nullptr, $PUBLIC | $STATIC, $staticMethod(Long, parseLong, int64_t, $String*, int32_t), "java.lang.NumberFormatException"},
	{"parseLong", "(Ljava/lang/CharSequence;III)J", nullptr, $PUBLIC | $STATIC, $staticMethod(Long, parseLong, int64_t, $CharSequence*, int32_t, int32_t, int32_t), "java.lang.NumberFormatException"},
	{"parseLong", "(Ljava/lang/String;)J", nullptr, $PUBLIC | $STATIC, $staticMethod(Long, parseLong, int64_t, $String*), "java.lang.NumberFormatException"},
	{"parseUnsignedLong", "(Ljava/lang/String;I)J", nullptr, $PUBLIC | $STATIC, $staticMethod(Long, parseUnsignedLong, int64_t, $String*, int32_t), "java.lang.NumberFormatException"},
	{"parseUnsignedLong", "(Ljava/lang/CharSequence;III)J", nullptr, $PUBLIC | $STATIC, $staticMethod(Long, parseUnsignedLong, int64_t, $CharSequence*, int32_t, int32_t, int32_t), "java.lang.NumberFormatException"},
	{"parseUnsignedLong", "(Ljava/lang/String;)J", nullptr, $PUBLIC | $STATIC, $staticMethod(Long, parseUnsignedLong, int64_t, $String*), "java.lang.NumberFormatException"},
	{"remainderUnsigned", "(JJ)J", nullptr, $PUBLIC | $STATIC, $staticMethod(Long, remainderUnsigned, int64_t, int64_t, int64_t)},
	{"resolveConstantDesc", "(Ljava/lang/invoke/MethodHandles$Lookup;)Ljava/lang/Long;", nullptr, $PUBLIC, $virtualMethod(Long, resolveConstantDesc, $Object*, $MethodHandles$Lookup*)},
	{"reverse", "(J)J", nullptr, $PUBLIC | $STATIC, $staticMethod(Long, reverse, int64_t, int64_t)},
	{"reverseBytes", "(J)J", nullptr, $PUBLIC | $STATIC, $staticMethod(Long, reverseBytes, int64_t, int64_t), nullptr, nullptr, _Long_MethodAnnotations_reverseBytes40},
	{"rotateLeft", "(JI)J", nullptr, $PUBLIC | $STATIC, $staticMethod(Long, rotateLeft, int64_t, int64_t, int32_t)},
	{"rotateRight", "(JI)J", nullptr, $PUBLIC | $STATIC, $staticMethod(Long, rotateRight, int64_t, int64_t, int32_t)},
	{"shortValue", "()S", nullptr, $PUBLIC, $virtualMethod(Long, shortValue, int16_t)},
	{"signum", "(J)I", nullptr, $PUBLIC | $STATIC, $staticMethod(Long, signum, int32_t, int64_t)},
	{"stringSize", "(J)I", nullptr, $STATIC, $staticMethod(Long, stringSize, int32_t, int64_t)},
	{"sum", "(JJ)J", nullptr, $PUBLIC | $STATIC, $staticMethod(Long, sum, int64_t, int64_t, int64_t)},
	{"toBinaryString", "(J)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(Long, toBinaryString, $String*, int64_t)},
	{"toHexString", "(J)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(Long, toHexString, $String*, int64_t)},
	{"toOctalString", "(J)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(Long, toOctalString, $String*, int64_t)},
	{"toString", "(JI)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(Long, toString, $String*, int64_t, int32_t)},
	{"toString", "(J)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(Long, toString, $String*, int64_t)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Long, toString, $String*)},
	{"toStringUTF16", "(JI)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(Long, toStringUTF16, $String*, int64_t, int32_t)},
	{"toUnsignedBigInteger", "(J)Ljava/math/BigInteger;", nullptr, $PRIVATE | $STATIC, $staticMethod(Long, toUnsignedBigInteger, $BigInteger*, int64_t)},
	{"toUnsignedString", "(JI)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(Long, toUnsignedString, $String*, int64_t, int32_t)},
	{"toUnsignedString", "(J)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(Long, toUnsignedString, $String*, int64_t)},
	{"toUnsignedString0", "(JI)Ljava/lang/String;", nullptr, $STATIC, $staticMethod(Long, toUnsignedString0, $String*, int64_t, int32_t)},
	{"valueOf", "(Ljava/lang/String;I)Ljava/lang/Long;", nullptr, $PUBLIC | $STATIC, $staticMethod(Long, valueOf, Long*, $String*, int32_t), "java.lang.NumberFormatException"},
	{"valueOf", "(Ljava/lang/String;)Ljava/lang/Long;", nullptr, $PUBLIC | $STATIC, $staticMethod(Long, valueOf, Long*, $String*), "java.lang.NumberFormatException"},
	{"valueOf", "(J)Ljava/lang/Long;", nullptr, $PUBLIC | $STATIC, $staticMethod(Long, valueOf, Long*, int64_t), nullptr, nullptr, _Long_MethodAnnotations_valueOf60},
	{}
};

$InnerClassInfo _Long_InnerClassesInfo_[] = {
	{"java.lang.Long$LongCache", "java.lang.Long", "LongCache", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _Long_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.lang.Long",
	"java.lang.Number",
	"java.lang.Comparable,java.lang.constant.Constable,java.lang.constant.ConstantDesc",
	_Long_FieldInfo_,
	_Long_MethodInfo_,
	"Ljava/lang/Number;Ljava/lang/Comparable<Ljava/lang/Long;>;Ljava/lang/constant/Constable;Ljava/lang/constant/ConstantDesc;",
	nullptr,
	_Long_InnerClassesInfo_,
	_Long_Annotations_,
	nullptr,
	"java.lang.Long$LongCache"
};

$Object* allocate$Long($Class* clazz) {
	return $of($alloc(Long));
}

$Object* Long::clone() {
	 return this->$Number::clone();
}

void Long::finalize() {
	this->$Number::finalize();
}

$Class* Long::TYPE = nullptr;

$String* Long::toString(int64_t i, int32_t radix) {
	$init(Long);
	if (radix < $Character::MIN_RADIX || radix > $Character::MAX_RADIX) {
		radix = 10;
	}
	if (radix == 10) {
		return toString(i);
	}
	if ($String::COMPACT_STRINGS) {
		$var($bytes, buf, $new($bytes, 65));
		int32_t charPos = 64;
		bool negative = (i < 0);
		if (!negative) {
			i = -i;
		}
		while (i <= -radix) {
			$init($Integer);
			buf->set(charPos--, (int8_t)$nc($Integer::digits)->get((int32_t)(-($mod(i, radix)))));
			i = $div(i, radix);
		}
		$init($Integer);
		buf->set(charPos, (int8_t)$nc($Integer::digits)->get((int32_t)(-i)));
		if (negative) {
			buf->set(--charPos, (int8_t)u'-');
		}
		return $StringLatin1::newString(buf, charPos, (65 - charPos));
	}
	return toStringUTF16(i, radix);
}

$String* Long::toStringUTF16(int64_t i, int32_t radix) {
	$init(Long);
	$var($bytes, buf, $new($bytes, 65 * 2));
	int32_t charPos = 64;
	bool negative = (i < 0);
	if (!negative) {
		i = -i;
	}
	while (i <= -radix) {
		$init($Integer);
		$StringUTF16::putChar(buf, charPos--, $nc($Integer::digits)->get((int32_t)(-($mod(i, radix)))));
		i = $div(i, radix);
	}
	$init($Integer);
	$StringUTF16::putChar(buf, charPos, $nc($Integer::digits)->get((int32_t)(-i)));
	if (negative) {
		$StringUTF16::putChar(buf, --charPos, u'-');
	}
	return $StringUTF16::newString(buf, charPos, (65 - charPos));
}

$String* Long::toUnsignedString(int64_t i, int32_t radix) {
	$init(Long);
	$useLocalCurrentObjectStackCache();
	if (i >= 0) {
		return toString(i, radix);
	} else {

		$var($String, var$0, nullptr)
		switch (radix) {
		case 2:
			{
				$assign(var$0, toBinaryString(i));
				break;
			}
		case 4:
			{
				$assign(var$0, toUnsignedString0(i, 2));
				break;
			}
		case 8:
			{
				$assign(var$0, toOctalString(i));
				break;
			}
		case 10:
			{
				{
					int64_t quot = ((int64_t)((uint64_t)i >> 1)) / 5;
					int64_t rem = i - quot * 10;
					$assign(var$0, $str({$(toString(quot)), $$str(rem)}));
					break;
				}
			}
		case 16:
			{
				$assign(var$0, toHexString(i));
				break;
			}
		case 32:
			{
				$assign(var$0, toUnsignedString0(i, 5));
				break;
			}
		default:
			{
				$assign(var$0, $nc($(toUnsignedBigInteger(i)))->toString(radix));
				break;
			}
		}
		return var$0;
	}
}

$BigInteger* Long::toUnsignedBigInteger(int64_t i) {
	$init(Long);
	$useLocalCurrentObjectStackCache();
	if (i >= (int64_t)0) {
		return $BigInteger::valueOf(i);
	} else {
		int32_t upper = (int32_t)((int64_t)((uint64_t)i >> 32));
		int32_t lower = (int32_t)i;
		return $nc($($nc(($($BigInteger::valueOf($Integer::toUnsignedLong(upper)))))->shiftLeft(32)))->add($($BigInteger::valueOf($Integer::toUnsignedLong(lower))));
	}
}

$String* Long::toHexString(int64_t i) {
	$init(Long);
	return toUnsignedString0(i, 4);
}

$String* Long::toOctalString(int64_t i) {
	$init(Long);
	return toUnsignedString0(i, 3);
}

$String* Long::toBinaryString(int64_t i) {
	$init(Long);
	return toUnsignedString0(i, 1);
}

$String* Long::toUnsignedString0(int64_t val, int32_t shift) {
	$init(Long);
	$useLocalCurrentObjectStackCache();
	int32_t mag = Long::SIZE - Long::numberOfLeadingZeros(val);
	int32_t chars = $Math::max(($div((mag + (shift - 1)), shift)), 1);
	if ($String::COMPACT_STRINGS) {
		$var($bytes, buf, $new($bytes, chars));
		formatUnsignedLong0(val, shift, buf, 0, chars);
		return $new($String, buf, (int8_t)0);
	} else {
		$var($bytes, buf, $new($bytes, chars * 2));
		formatUnsignedLong0UTF16(val, shift, buf, 0, chars);
		return $new($String, buf, (int8_t)1);
	}
}

void Long::formatUnsignedLong0(int64_t val, int32_t shift, $bytes* buf, int32_t offset, int32_t len) {
	$init(Long);
	int32_t charPos = offset + len;
	int32_t radix = $sl(1, shift);
	int32_t mask = radix - 1;
	do {
		$init($Integer);
		$nc(buf)->set(--charPos, (int8_t)$nc($Integer::digits)->get((int32_t)(((int32_t)val) & (uint32_t)mask)));
		$usrAssign(val, shift);
	} while (charPos > offset);
}

void Long::formatUnsignedLong0UTF16(int64_t val, int32_t shift, $bytes* buf, int32_t offset, int32_t len) {
	$init(Long);
	int32_t charPos = offset + len;
	int32_t radix = $sl(1, shift);
	int32_t mask = radix - 1;
	do {
		$init($Integer);
		$StringUTF16::putChar(buf, --charPos, $nc($Integer::digits)->get((int32_t)(((int32_t)val) & (uint32_t)mask)));
		$usrAssign(val, shift);
	} while (charPos > offset);
}

$String* Long::fastUUID(int64_t lsb, int64_t msb) {
	$init(Long);
	$useLocalCurrentObjectStackCache();
	if ($String::COMPACT_STRINGS) {
		$var($bytes, buf, $new($bytes, 36));
		formatUnsignedLong0(lsb, 4, buf, 24, 12);
		formatUnsignedLong0((int64_t)((uint64_t)lsb >> 48), 4, buf, 19, 4);
		formatUnsignedLong0(msb, 4, buf, 14, 4);
		formatUnsignedLong0((int64_t)((uint64_t)msb >> 16), 4, buf, 9, 4);
		formatUnsignedLong0((int64_t)((uint64_t)msb >> 32), 4, buf, 0, 8);
		buf->set(23, (int8_t)u'-');
		buf->set(18, (int8_t)u'-');
		buf->set(13, (int8_t)u'-');
		buf->set(8, (int8_t)u'-');
		return $new($String, buf, (int8_t)0);
	} else {
		$var($bytes, buf, $new($bytes, 72));
		formatUnsignedLong0UTF16(lsb, 4, buf, 24, 12);
		formatUnsignedLong0UTF16((int64_t)((uint64_t)lsb >> 48), 4, buf, 19, 4);
		formatUnsignedLong0UTF16(msb, 4, buf, 14, 4);
		formatUnsignedLong0UTF16((int64_t)((uint64_t)msb >> 16), 4, buf, 9, 4);
		formatUnsignedLong0UTF16((int64_t)((uint64_t)msb >> 32), 4, buf, 0, 8);
		$StringUTF16::putChar(buf, 23, u'-');
		$StringUTF16::putChar(buf, 18, u'-');
		$StringUTF16::putChar(buf, 13, u'-');
		$StringUTF16::putChar(buf, 8, u'-');
		return $new($String, buf, (int8_t)1);
	}
}

$String* Long::toString(int64_t i) {
	$init(Long);
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

$String* Long::toUnsignedString(int64_t i) {
	$init(Long);
	return toUnsignedString(i, 10);
}

int32_t Long::getChars(int64_t i, int32_t index, $bytes* buf) {
	$init(Long);
	int64_t q = 0;
	int32_t r = 0;
	int32_t charPos = index;
	bool negative = (i < 0);
	if (!negative) {
		i = -i;
	}
	while (i <= $Integer::MIN_VALUE) {
		q = i / 100;
		r = (int32_t)((q * 100) - i);
		i = q;
		$init($Integer);
		$nc(buf)->set(--charPos, $nc($Integer::DigitOnes)->get(r));
		buf->set(--charPos, $nc($Integer::DigitTens)->get(r));
	}
	int32_t q2 = 0;
	int32_t i2 = (int32_t)i;
	while (i2 <= -100) {
		q2 = i2 / 100;
		r = (q2 * 100) - i2;
		i2 = q2;
		$init($Integer);
		$nc(buf)->set(--charPos, $nc($Integer::DigitOnes)->get(r));
		buf->set(--charPos, $nc($Integer::DigitTens)->get(r));
	}
	q2 = i2 / 10;
	r = (q2 * 10) - i2;
	$nc(buf)->set(--charPos, (int8_t)(u'0' + r));
	if (q2 < 0) {
		buf->set(--charPos, (int8_t)(u'0' - q2));
	}
	if (negative) {
		buf->set(--charPos, (int8_t)u'-');
	}
	return charPos;
}

int32_t Long::stringSize(int64_t x) {
	$init(Long);
	int32_t d = 1;
	if (x >= 0) {
		d = 0;
		x = -x;
	}
	int64_t p = -10;
	for (int32_t i = 1; i < 19; ++i) {
		if (x > p) {
			return i + d;
		}
		p = 10 * p;
	}
	return 19 + d;
}

int64_t Long::parseLong($String* s, int32_t radix) {
	$init(Long);
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
	int64_t limit = -Long::MAX_VALUE;
	if (len > 0) {
		char16_t firstChar = s->charAt(0);
		if (firstChar < u'0') {
			if (firstChar == u'-') {
				negative = true;
				limit = Long::MIN_VALUE;
			} else if (firstChar != u'+') {
				$throw($($NumberFormatException::forInputString(s, radix)));
			}
			if (len == 1) {
				$throw($($NumberFormatException::forInputString(s, radix)));
			}
			++i;
		}
		int64_t multmin = $div(limit, radix);
		int64_t result = 0;
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

int64_t Long::parseLong($CharSequence* s, int32_t beginIndex, int32_t endIndex, int32_t radix) {
	$init(Long);
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
	int64_t limit = -Long::MAX_VALUE;
	if (i < endIndex) {
		char16_t firstChar = s->charAt(i);
		if (firstChar < u'0') {
			if (firstChar == u'-') {
				negative = true;
				limit = Long::MIN_VALUE;
			} else if (firstChar != u'+') {
				$throw($($NumberFormatException::forCharSequence(s, beginIndex, endIndex, i)));
			}
			++i;
		}
		if (i >= endIndex) {
			$throw($($NumberFormatException::forCharSequence(s, beginIndex, endIndex, i)));
		}
		int64_t multmin = $div(limit, radix);
		int64_t result = 0;
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
		$throwNew($NumberFormatException, ""_s);
	}
}

int64_t Long::parseLong($String* s) {
	$init(Long);
	return parseLong(s, 10);
}

int64_t Long::parseUnsignedLong($String* s, int32_t radix) {
	$init(Long);
	$useLocalCurrentObjectStackCache();
	if (s == nullptr) {
		$throwNew($NumberFormatException, "Cannot parse null string"_s);
	}
	int32_t len = $nc(s)->length();
	if (len > 0) {
		char16_t firstChar = s->charAt(0);
		if (firstChar == u'-') {
			$throwNew($NumberFormatException, $($String::format("Illegal leading minus sign on unsigned string %s."_s, $$new($ObjectArray, {$of(s)}))));
		} else {
			if (len <= 12 || (radix == 10 && len <= 18)) {
				return parseLong(s, radix);
			}
			int64_t first = parseLong(s, 0, len - 1, radix);
			int32_t second = $Character::digit(s->charAt(len - 1), radix);
			if (second < 0) {
				$throwNew($NumberFormatException, $$str({"Bad digit at end of "_s, s}));
			}
			int64_t result = first * radix + second;
			int32_t guard = radix * (int32_t)((int64_t)((uint64_t)first >> 57));
			if (guard >= 128 || (result >= 0 && guard >= 128 - $Character::MAX_RADIX)) {
				$throwNew($NumberFormatException, $($String::format("String value %s exceeds range of unsigned long."_s, $$new($ObjectArray, {$of(s)}))));
			}
			return result;
		}
	} else {
		$throw($($NumberFormatException::forInputString(s, radix)));
	}
}

int64_t Long::parseUnsignedLong($CharSequence* s, int32_t beginIndex, int32_t endIndex, int32_t radix) {
	$init(Long);
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
			$throwNew($NumberFormatException, $($String::format("Illegal leading minus sign on unsigned string %s."_s, $$new($ObjectArray, {$($of(s->subSequence(start, start + len)))}))));
		} else {
			if (len <= 12 || (radix == 10 && len <= 18)) {
				return parseLong(s, start, start + len, radix);
			}
			int64_t first = parseLong(s, start, start + len - 1, radix);
			int32_t second = $Character::digit(s->charAt(start + len - 1), radix);
			if (second < 0) {
				$throwNew($NumberFormatException, $$str({"Bad digit at end of "_s, $(s->subSequence(start, start + len))}));
			}
			int64_t result = first * radix + second;
			int32_t guard = radix * (int32_t)((int64_t)((uint64_t)first >> 57));
			if (guard >= 128 || (result >= 0 && guard >= 128 - $Character::MAX_RADIX)) {
				$throwNew($NumberFormatException, $($String::format("String value %s exceeds range of unsigned long."_s, $$new($ObjectArray, {$($of(s->subSequence(start, start + len)))}))));
			}
			return result;
		}
	} else {
		$throw($($NumberFormatException::forInputString(""_s, radix)));
	}
}

int64_t Long::parseUnsignedLong($String* s) {
	$init(Long);
	return parseUnsignedLong(s, 10);
}

Long* Long::valueOf($String* s, int32_t radix) {
	$init(Long);
	return Long::valueOf(parseLong(s, radix));
}

Long* Long::valueOf($String* s) {
	$init(Long);
	return Long::valueOf(parseLong(s, 10));
}

Long* Long::valueOf(int64_t l) {
	$init(Long);
	int32_t offset = 128;
	if (l >= -128 && l <= 127) {
		$init($Long$LongCache);
		return $nc($Long$LongCache::cache)->get((int32_t)l + offset);
	}
	return $new(Long, l);
}

Long* Long::decode($String* nm) {
	$init(Long);
	$useLocalCurrentObjectStackCache();
	int32_t radix = 10;
	int32_t index = 0;
	bool negative = false;
	$var(Long, result, nullptr);
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
		$assign(result, Long::valueOf($(nm->substring(index)), radix));
		$assign(result, negative ? Long::valueOf(-$nc(result)->longValue()) : result);
	} catch ($NumberFormatException& e) {
		$var($String, constant, negative ? ($str({"-"_s, $(nm->substring(index))})) : nm->substring(index));
		$assign(result, Long::valueOf(constant, radix));
	}
	return result;
}

void Long::init$(int64_t value) {
	$Number::init$();
	this->value = value;
}

void Long::init$($String* s) {
	$Number::init$();
	this->value = parseLong(s, 10);
}

int8_t Long::byteValue() {
	return (int8_t)this->value;
}

int16_t Long::shortValue() {
	return (int16_t)this->value;
}

int32_t Long::intValue() {
	return (int32_t)this->value;
}

int64_t Long::longValue() {
	return this->value;
}

float Long::floatValue() {
	return (float)this->value;
}

double Long::doubleValue() {
	return (double)this->value;
}

$String* Long::toString() {
	return toString(this->value);
}

int32_t Long::hashCode() {
	return Long::hashCode(this->value);
}

int32_t Long::hashCode(int64_t value) {
	$init(Long);
	return (int32_t)(value ^ ((int64_t)((uint64_t)value >> 32)));
}

bool Long::equals(Object$* obj) {
	if ($instanceOf(Long, obj)) {
		return this->value == $nc(($cast(Long, obj)))->longValue();
	}
	return false;
}

Long* Long::getLong($String* nm) {
	$init(Long);
	return getLong(nm, (Long*)nullptr);
}

Long* Long::getLong($String* nm, int64_t val) {
	$init(Long);
	$var(Long, result, Long::getLong(nm, (Long*)nullptr));
	return (result == nullptr) ? Long::valueOf(val) : result;
}

Long* Long::getLong($String* nm, Long* val) {
	$init(Long);
	$var($String, v, nullptr);
	try {
		$assign(v, $System::getProperty(nm));
	} catch ($IllegalArgumentException& e) {
	} catch ($NullPointerException& e) {
	}
	if (v != nullptr) {
		try {
			return Long::decode(v);
		} catch ($NumberFormatException& e) {
		}
	}
	return val;
}

int32_t Long::compareTo(Long* anotherLong) {
	return compare(this->value, $nc(anotherLong)->value);
}

int32_t Long::compare(int64_t x, int64_t y) {
	$init(Long);
	return (x < y) ? -1 : ((x == y) ? 0 : 1);
}

int32_t Long::compareUnsigned(int64_t x, int64_t y) {
	$init(Long);
	return compare(x + Long::MIN_VALUE, y + Long::MIN_VALUE);
}

int64_t Long::divideUnsigned(int64_t dividend, int64_t divisor) {
	$init(Long);
	if (divisor >= 0) {
		int64_t q = ($div(((int64_t)((uint64_t)dividend >> 1)), divisor)) << 1;
		int64_t r = dividend - q * divisor;
		return q + ($usr(r | ~(r - divisor), Long::SIZE - 1));
	}
	return $usr((int64_t)(dividend & (uint64_t)~(dividend - divisor)), Long::SIZE - 1);
}

int64_t Long::remainderUnsigned(int64_t dividend, int64_t divisor) {
	$init(Long);
	if (divisor >= 0) {
		int64_t q = ($div(((int64_t)((uint64_t)dividend >> 1)), divisor)) << 1;
		int64_t r = dividend - q * divisor;
		return r - ((int64_t)(($sr(~(r - divisor), Long::SIZE - 1)) & (uint64_t)divisor));
	}
	return dividend - ((int64_t)(($sr((int64_t)(dividend & (uint64_t)~(dividend - divisor)), Long::SIZE - 1)) & (uint64_t)divisor));
}

int64_t Long::highestOneBit(int64_t i) {
	$init(Long);
	return (int64_t)(i & (uint64_t)($usr(Long::MIN_VALUE, numberOfLeadingZeros(i))));
}

int64_t Long::lowestOneBit(int64_t i) {
	$init(Long);
	return (int64_t)(i & (uint64_t)-i);
}

int32_t Long::numberOfLeadingZeros(int64_t i) {
	$init(Long);
	int32_t x = (int32_t)((int64_t)((uint64_t)i >> 32));
	return x == 0 ? 32 + $Integer::numberOfLeadingZeros((int32_t)i) : $Integer::numberOfLeadingZeros(x);
}

int32_t Long::numberOfTrailingZeros(int64_t i) {
	$init(Long);
	int32_t x = (int32_t)i;
	return x == 0 ? 32 + $Integer::numberOfTrailingZeros((int32_t)((int64_t)((uint64_t)i >> 32))) : $Integer::numberOfTrailingZeros(x);
}

int32_t Long::bitCount(int64_t i) {
	$init(Long);
	i = i - ((int64_t)(((int64_t)((uint64_t)i >> 1)) & (uint64_t)(int64_t)0x5555555555555555));
	i = ((int64_t)(i & (uint64_t)(int64_t)0x3333333333333333)) + ((int64_t)(((int64_t)((uint64_t)i >> 2)) & (uint64_t)(int64_t)0x3333333333333333));
	i = (int64_t)((i + ((int64_t)((uint64_t)i >> 4))) & (uint64_t)(int64_t)0x0F0F0F0F0F0F0F0F);
	i = i + ((int64_t)((uint64_t)i >> 8));
	i = i + ((int64_t)((uint64_t)i >> 16));
	i = i + ((int64_t)((uint64_t)i >> 32));
	return (int32_t)((int32_t)i & (uint32_t)127);
}

int64_t Long::rotateLeft(int64_t i, int32_t distance) {
	$init(Long);
	return ($sl(i, distance)) | ($usr(i, -distance));
}

int64_t Long::rotateRight(int64_t i, int32_t distance) {
	$init(Long);
	return ($usr(i, distance)) | ($sl(i, -distance));
}

int64_t Long::reverse(int64_t i) {
	$init(Long);
	i = (((int64_t)(i & (uint64_t)(int64_t)0x5555555555555555)) << 1) | ((int64_t)(((int64_t)((uint64_t)i >> 1)) & (uint64_t)(int64_t)0x5555555555555555));
	i = (((int64_t)(i & (uint64_t)(int64_t)0x3333333333333333)) << 2) | ((int64_t)(((int64_t)((uint64_t)i >> 2)) & (uint64_t)(int64_t)0x3333333333333333));
	i = (((int64_t)(i & (uint64_t)(int64_t)0x0F0F0F0F0F0F0F0F)) << 4) | ((int64_t)(((int64_t)((uint64_t)i >> 4)) & (uint64_t)(int64_t)0x0F0F0F0F0F0F0F0F));
	return reverseBytes(i);
}

int32_t Long::signum(int64_t i) {
	$init(Long);
	return (int32_t)((i >> 63) | ((int64_t)((uint64_t)-i >> 63)));
}

int64_t Long::reverseBytes(int64_t i) {
	$init(Long);
	i = (((int64_t)(i & (uint64_t)(int64_t)0x00FF00FF00FF00FF)) << 8) | ((int64_t)(((int64_t)((uint64_t)i >> 8)) & (uint64_t)(int64_t)0x00FF00FF00FF00FF));
	return (((i << 48) | (((int64_t)(i & (uint64_t)(int64_t)0x00000000FFFF0000)) << 16)) | ((int64_t)(((int64_t)((uint64_t)i >> 16)) & (uint64_t)(int64_t)0x00000000FFFF0000))) | ((int64_t)((uint64_t)i >> 48));
}

int64_t Long::sum(int64_t a, int64_t b) {
	$init(Long);
	return a + b;
}

int64_t Long::max(int64_t a, int64_t b) {
	$init(Long);
	return $Math::max(a, b);
}

int64_t Long::min(int64_t a, int64_t b) {
	$init(Long);
	return $Math::min(a, b);
}

$Optional* Long::describeConstable() {
	return $Optional::of(this);
}

$Object* Long::resolveConstantDesc($MethodHandles$Lookup* lookup) {
	return $of(this);
}

int32_t Long::compareTo(Object$* anotherLong) {
	return this->compareTo($cast(Long, anotherLong));
}

void clinit$Long($Class* class$) {
	$assignStatic(Long::TYPE, $Class::getPrimitiveClass("long"_s));
}

Long::Long() {
}

$Class* Long::load$($String* name, bool initialize) {
	$loadClass(Long, name, initialize, &_Long_ClassInfo_, clinit$Long, allocate$Long);
	return class$;
}

$Class* Long::class$ = nullptr;

	} // lang
} // java