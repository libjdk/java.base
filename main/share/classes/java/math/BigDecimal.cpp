#include <java/math/BigDecimal.h>

#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream.h>
#include <java/io/StreamCorruptedException.h>
#include <java/lang/ArrayIndexOutOfBoundsException.h>
#include <java/lang/AssertionError.h>
#include <java/lang/IndexOutOfBoundsException.h>
#include <java/lang/Math.h>
#include <java/lang/NegativeArraySizeException.h>
#include <java/lang/Number.h>
#include <java/lang/NumberFormatException.h>
#include <java/math/BigDecimal$1.h>
#include <java/math/BigDecimal$LongOverflow.h>
#include <java/math/BigDecimal$StringBuilderHelper.h>
#include <java/math/BigDecimal$UnsafeHolder.h>
#include <java/math/BigInteger.h>
#include <java/math/MathContext.h>
#include <java/math/MutableBigInteger.h>
#include <java/math/RoundingMode.h>
#include <java/util/Arrays.h>
#include <java/util/Objects.h>
#include <jcpp.h>

#undef BIG_TEN_POWERS_TABLE
#undef BIG_TEN_POWERS_TABLE_INITLEN
#undef BIG_TEN_POWERS_TABLE_MAX
#undef DIGIT_ONES
#undef DIGIT_TENS
#undef DIV_NUM_BASE
#undef DOUBLE_10_POW
#undef DOWN
#undef FLOAT_10_POW
#undef HALF_EVEN
#undef HALF_LONG_MAX_VALUE
#undef HALF_LONG_MIN_VALUE
#undef INFLATED
#undef INFLATED_BIGINT
#undef LONGLONG_TEN_POWERS_TABLE
#undef LONG_TEN_POWERS_TABLE
#undef MAX_COMPACT_DIGITS
#undef MAX_VALUE
#undef MIN_VALUE
#undef ONE
#undef ONE_HALF
#undef ONE_TENTH
#undef ROUND_CEILING
#undef ROUND_DOWN
#undef ROUND_FLOOR
#undef ROUND_HALF_DOWN
#undef ROUND_HALF_EVEN
#undef ROUND_HALF_UP
#undef ROUND_UNNECESSARY
#undef ROUND_UP
#undef TEN
#undef THRESHOLDS_TABLE
#undef TWO
#undef UNLIMITED
#undef UNNECESSARY
#undef ZERO
#undef ZERO_SCALED_BY
#undef ZERO_THROUGH_TEN

using $BigDecimalArray = $Array<::java::math::BigDecimal>;
using $BigIntegerArray = $Array<::java::math::BigInteger>;
using $longArray2 = $Array<int64_t, 2>;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $PrintStream = ::java::io::PrintStream;
using $StreamCorruptedException = ::java::io::StreamCorruptedException;
using $ArithmeticException = ::java::lang::ArithmeticException;
using $ArrayIndexOutOfBoundsException = ::java::lang::ArrayIndexOutOfBoundsException;
using $AssertionError = ::java::lang::AssertionError;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Double = ::java::lang::Double;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IndexOutOfBoundsException = ::java::lang::IndexOutOfBoundsException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $NamedAttribute = ::java::lang::NamedAttribute;
using $NegativeArraySizeException = ::java::lang::NegativeArraySizeException;
using $Number = ::java::lang::Number;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $BigDecimal$1 = ::java::math::BigDecimal$1;
using $BigDecimal$LongOverflow = ::java::math::BigDecimal$LongOverflow;
using $BigDecimal$StringBuilderHelper = ::java::math::BigDecimal$StringBuilderHelper;
using $BigDecimal$UnsafeHolder = ::java::math::BigDecimal$UnsafeHolder;
using $BigInteger = ::java::math::BigInteger;
using $MathContext = ::java::math::MathContext;
using $MutableBigInteger = ::java::math::MutableBigInteger;
using $RoundingMode = ::java::math::RoundingMode;
using $Arrays = ::java::util::Arrays;
using $Objects = ::java::util::Objects;

namespace java {
	namespace math {

$NamedAttribute BigDecimal_Attribute_var$0[] = {
	{"since", 's', "9"},
	{}
};

$CompoundAttribute _BigDecimal_FieldAnnotations_ROUND_UP[] = {
	{"Ljava/lang/Deprecated;", BigDecimal_Attribute_var$0},
	{}
};

$NamedAttribute BigDecimal_Attribute_var$1[] = {
	{"since", 's', "9"},
	{}
};

$CompoundAttribute _BigDecimal_FieldAnnotations_ROUND_DOWN[] = {
	{"Ljava/lang/Deprecated;", BigDecimal_Attribute_var$1},
	{}
};

$NamedAttribute BigDecimal_Attribute_var$2[] = {
	{"since", 's', "9"},
	{}
};

$CompoundAttribute _BigDecimal_FieldAnnotations_ROUND_CEILING[] = {
	{"Ljava/lang/Deprecated;", BigDecimal_Attribute_var$2},
	{}
};

$NamedAttribute BigDecimal_Attribute_var$3[] = {
	{"since", 's', "9"},
	{}
};

$CompoundAttribute _BigDecimal_FieldAnnotations_ROUND_FLOOR[] = {
	{"Ljava/lang/Deprecated;", BigDecimal_Attribute_var$3},
	{}
};

$NamedAttribute BigDecimal_Attribute_var$4[] = {
	{"since", 's', "9"},
	{}
};

$CompoundAttribute _BigDecimal_FieldAnnotations_ROUND_HALF_UP[] = {
	{"Ljava/lang/Deprecated;", BigDecimal_Attribute_var$4},
	{}
};

$NamedAttribute BigDecimal_Attribute_var$5[] = {
	{"since", 's', "9"},
	{}
};

$CompoundAttribute _BigDecimal_FieldAnnotations_ROUND_HALF_DOWN[] = {
	{"Ljava/lang/Deprecated;", BigDecimal_Attribute_var$5},
	{}
};

$NamedAttribute BigDecimal_Attribute_var$6[] = {
	{"since", 's', "9"},
	{}
};

$CompoundAttribute _BigDecimal_FieldAnnotations_ROUND_HALF_EVEN[] = {
	{"Ljava/lang/Deprecated;", BigDecimal_Attribute_var$6},
	{}
};

$NamedAttribute BigDecimal_Attribute_var$7[] = {
	{"since", 's', "9"},
	{}
};

$CompoundAttribute _BigDecimal_FieldAnnotations_ROUND_UNNECESSARY[] = {
	{"Ljava/lang/Deprecated;", BigDecimal_Attribute_var$7},
	{}
};

$NamedAttribute BigDecimal_Attribute_var$8[] = {
	{"since", 's', "9"},
	{}
};

$CompoundAttribute _BigDecimal_MethodAnnotations_divide49[] = {
	{"Ljava/lang/Deprecated;", BigDecimal_Attribute_var$8},
	{}
};

$NamedAttribute BigDecimal_Attribute_var$9[] = {
	{"since", 's', "9"},
	{}
};

$CompoundAttribute _BigDecimal_MethodAnnotations_divide51[] = {
	{"Ljava/lang/Deprecated;", BigDecimal_Attribute_var$9},
	{}
};

$NamedAttribute BigDecimal_Attribute_var$10[] = {
	{"since", 's', "9"},
	{}
};

$CompoundAttribute _BigDecimal_MethodAnnotations_setScale139[] = {
	{"Ljava/lang/Deprecated;", BigDecimal_Attribute_var$10},
	{}
};

$FieldInfo _BigDecimal_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(BigDecimal, $assertionsDisabled)},
	{"intVal", "Ljava/math/BigInteger;", nullptr, $PRIVATE | $FINAL, $field(BigDecimal, intVal)},
	{"scale", "I", nullptr, $PRIVATE | $FINAL, $field(BigDecimal, scale$)},
	{"precision", "I", nullptr, $PRIVATE | $TRANSIENT, $field(BigDecimal, precision$)},
	{"stringCache", "Ljava/lang/String;", nullptr, $PRIVATE | $TRANSIENT, $field(BigDecimal, stringCache)},
	{"INFLATED", "J", nullptr, $STATIC | $FINAL, $constField(BigDecimal, INFLATED)},
	{"INFLATED_BIGINT", "Ljava/math/BigInteger;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(BigDecimal, INFLATED_BIGINT)},
	{"intCompact", "J", nullptr, $PRIVATE | $FINAL | $TRANSIENT, $field(BigDecimal, intCompact)},
	{"MAX_COMPACT_DIGITS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(BigDecimal, MAX_COMPACT_DIGITS)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(BigDecimal, serialVersionUID)},
	{"ZERO_THROUGH_TEN", "[Ljava/math/BigDecimal;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(BigDecimal, ZERO_THROUGH_TEN)},
	{"ZERO_SCALED_BY", "[Ljava/math/BigDecimal;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(BigDecimal, ZERO_SCALED_BY)},
	{"HALF_LONG_MAX_VALUE", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(BigDecimal, HALF_LONG_MAX_VALUE)},
	{"HALF_LONG_MIN_VALUE", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(BigDecimal, HALF_LONG_MIN_VALUE)},
	{"ZERO", "Ljava/math/BigDecimal;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(BigDecimal, ZERO)},
	{"ONE", "Ljava/math/BigDecimal;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(BigDecimal, ONE)},
	{"TEN", "Ljava/math/BigDecimal;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(BigDecimal, TEN)},
	{"ONE_TENTH", "Ljava/math/BigDecimal;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(BigDecimal, ONE_TENTH)},
	{"ONE_HALF", "Ljava/math/BigDecimal;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(BigDecimal, ONE_HALF)},
	{"ROUND_UP", "I", nullptr, $PUBLIC | $STATIC | $FINAL | $DEPRECATED, $constField(BigDecimal, ROUND_UP), _BigDecimal_FieldAnnotations_ROUND_UP},
	{"ROUND_DOWN", "I", nullptr, $PUBLIC | $STATIC | $FINAL | $DEPRECATED, $constField(BigDecimal, ROUND_DOWN), _BigDecimal_FieldAnnotations_ROUND_DOWN},
	{"ROUND_CEILING", "I", nullptr, $PUBLIC | $STATIC | $FINAL | $DEPRECATED, $constField(BigDecimal, ROUND_CEILING), _BigDecimal_FieldAnnotations_ROUND_CEILING},
	{"ROUND_FLOOR", "I", nullptr, $PUBLIC | $STATIC | $FINAL | $DEPRECATED, $constField(BigDecimal, ROUND_FLOOR), _BigDecimal_FieldAnnotations_ROUND_FLOOR},
	{"ROUND_HALF_UP", "I", nullptr, $PUBLIC | $STATIC | $FINAL | $DEPRECATED, $constField(BigDecimal, ROUND_HALF_UP), _BigDecimal_FieldAnnotations_ROUND_HALF_UP},
	{"ROUND_HALF_DOWN", "I", nullptr, $PUBLIC | $STATIC | $FINAL | $DEPRECATED, $constField(BigDecimal, ROUND_HALF_DOWN), _BigDecimal_FieldAnnotations_ROUND_HALF_DOWN},
	{"ROUND_HALF_EVEN", "I", nullptr, $PUBLIC | $STATIC | $FINAL | $DEPRECATED, $constField(BigDecimal, ROUND_HALF_EVEN), _BigDecimal_FieldAnnotations_ROUND_HALF_EVEN},
	{"ROUND_UNNECESSARY", "I", nullptr, $PUBLIC | $STATIC | $FINAL | $DEPRECATED, $constField(BigDecimal, ROUND_UNNECESSARY), _BigDecimal_FieldAnnotations_ROUND_UNNECESSARY},
	{"DOUBLE_10_POW", "[D", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(BigDecimal, DOUBLE_10_POW)},
	{"FLOAT_10_POW", "[F", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(BigDecimal, FLOAT_10_POW)},
	{"LONG_TEN_POWERS_TABLE", "[J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(BigDecimal, LONG_TEN_POWERS_TABLE)},
	{"BIG_TEN_POWERS_TABLE", "[Ljava/math/BigInteger;", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(BigDecimal, BIG_TEN_POWERS_TABLE)},
	{"BIG_TEN_POWERS_TABLE_INITLEN", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(BigDecimal, BIG_TEN_POWERS_TABLE_INITLEN)},
	{"BIG_TEN_POWERS_TABLE_MAX", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(BigDecimal, BIG_TEN_POWERS_TABLE_MAX)},
	{"THRESHOLDS_TABLE", "[J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(BigDecimal, THRESHOLDS_TABLE)},
	{"DIV_NUM_BASE", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(BigDecimal, DIV_NUM_BASE)},
	{"LONGLONG_TEN_POWERS_TABLE", "[[J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(BigDecimal, LONGLONG_TEN_POWERS_TABLE)},
	{}
};

$MethodInfo _BigDecimal_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "(Ljava/math/BigInteger;JII)V", nullptr, 0, $method(BigDecimal, init$, void, $BigInteger*, int64_t, int32_t, int32_t)},
	{"<init>", "([CII)V", nullptr, $PUBLIC, $method(BigDecimal, init$, void, $chars*, int32_t, int32_t)},
	{"<init>", "([CIILjava/math/MathContext;)V", nullptr, $PUBLIC, $method(BigDecimal, init$, void, $chars*, int32_t, int32_t, $MathContext*)},
	{"<init>", "([C)V", nullptr, $PUBLIC, $method(BigDecimal, init$, void, $chars*)},
	{"<init>", "([CLjava/math/MathContext;)V", nullptr, $PUBLIC, $method(BigDecimal, init$, void, $chars*, $MathContext*)},
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(BigDecimal, init$, void, $String*)},
	{"<init>", "(Ljava/lang/String;Ljava/math/MathContext;)V", nullptr, $PUBLIC, $method(BigDecimal, init$, void, $String*, $MathContext*)},
	{"<init>", "(D)V", nullptr, $PUBLIC, $method(BigDecimal, init$, void, double)},
	{"<init>", "(DLjava/math/MathContext;)V", nullptr, $PUBLIC, $method(BigDecimal, init$, void, double, $MathContext*)},
	{"<init>", "(Ljava/math/BigInteger;)V", nullptr, $PUBLIC, $method(BigDecimal, init$, void, $BigInteger*)},
	{"<init>", "(Ljava/math/BigInteger;Ljava/math/MathContext;)V", nullptr, $PUBLIC, $method(BigDecimal, init$, void, $BigInteger*, $MathContext*)},
	{"<init>", "(Ljava/math/BigInteger;I)V", nullptr, $PUBLIC, $method(BigDecimal, init$, void, $BigInteger*, int32_t)},
	{"<init>", "(Ljava/math/BigInteger;ILjava/math/MathContext;)V", nullptr, $PUBLIC, $method(BigDecimal, init$, void, $BigInteger*, int32_t, $MathContext*)},
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(BigDecimal, init$, void, int32_t)},
	{"<init>", "(ILjava/math/MathContext;)V", nullptr, $PUBLIC, $method(BigDecimal, init$, void, int32_t, $MathContext*)},
	{"<init>", "(J)V", nullptr, $PUBLIC, $method(BigDecimal, init$, void, int64_t)},
	{"<init>", "(JLjava/math/MathContext;)V", nullptr, $PUBLIC, $method(BigDecimal, init$, void, int64_t, $MathContext*)},
	{"abs", "()Ljava/math/BigDecimal;", nullptr, $PUBLIC, $virtualMethod(BigDecimal, abs, BigDecimal*)},
	{"abs", "(Ljava/math/MathContext;)Ljava/math/BigDecimal;", nullptr, $PUBLIC, $virtualMethod(BigDecimal, abs, BigDecimal*, $MathContext*)},
	{"add", "(Ljava/math/BigDecimal;)Ljava/math/BigDecimal;", nullptr, $PUBLIC, $virtualMethod(BigDecimal, add, BigDecimal*, BigDecimal*)},
	{"add", "(Ljava/math/BigDecimal;Ljava/math/MathContext;)Ljava/math/BigDecimal;", nullptr, $PUBLIC, $virtualMethod(BigDecimal, add, BigDecimal*, BigDecimal*, $MathContext*)},
	{"add", "(JJ)J", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, add, int64_t, int64_t, int64_t)},
	{"add", "(JJI)Ljava/math/BigDecimal;", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, add, BigDecimal*, int64_t, int64_t, int32_t)},
	{"add", "(JIJI)Ljava/math/BigDecimal;", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, add, BigDecimal*, int64_t, int32_t, int64_t, int32_t)},
	{"add", "(JILjava/math/BigInteger;I)Ljava/math/BigDecimal;", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, add, BigDecimal*, int64_t, int32_t, $BigInteger*, int32_t)},
	{"add", "(Ljava/math/BigInteger;ILjava/math/BigInteger;I)Ljava/math/BigDecimal;", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, add, BigDecimal*, $BigInteger*, int32_t, $BigInteger*, int32_t)},
	{"adjustScale", "(IJ)I", nullptr, $PRIVATE, $method(BigDecimal, adjustScale, int32_t, int32_t, int64_t)},
	{"audit", "()Ljava/math/BigDecimal;", nullptr, $PRIVATE, $method(BigDecimal, audit, BigDecimal*)},
	{"bigDigitLength", "(Ljava/math/BigInteger;)I", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, bigDigitLength, int32_t, $BigInteger*)},
	{"bigMultiplyPowerTen", "(I)Ljava/math/BigInteger;", nullptr, $PRIVATE, $method(BigDecimal, bigMultiplyPowerTen, $BigInteger*, int32_t)},
	{"bigMultiplyPowerTen", "(JI)Ljava/math/BigInteger;", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, bigMultiplyPowerTen, $BigInteger*, int64_t, int32_t)},
	{"bigMultiplyPowerTen", "(Ljava/math/BigInteger;I)Ljava/math/BigInteger;", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, bigMultiplyPowerTen, $BigInteger*, $BigInteger*, int32_t)},
	{"bigTenToThe", "(I)Ljava/math/BigInteger;", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, bigTenToThe, $BigInteger*, int32_t)},
	{"byteValueExact", "()B", nullptr, $PUBLIC, $virtualMethod(BigDecimal, byteValueExact, int8_t)},
	{"checkScale", "(J)I", nullptr, $PRIVATE, $method(BigDecimal, checkScale, int32_t, int64_t)},
	{"checkScale", "(JJ)I", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, checkScale, int32_t, int64_t, int64_t)},
	{"checkScale", "(Ljava/math/BigInteger;J)I", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, checkScale, int32_t, $BigInteger*, int64_t)},
	{"checkScaleNonZero", "(J)I", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, checkScaleNonZero, int32_t, int64_t)},
	{"commonNeedIncrement", "(IIIZ)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, commonNeedIncrement, bool, int32_t, int32_t, int32_t, bool)},
	{"compactValFor", "(Ljava/math/BigInteger;)J", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, compactValFor, int64_t, $BigInteger*)},
	{"compareMagnitude", "(Ljava/math/BigDecimal;)I", nullptr, $PRIVATE, $method(BigDecimal, compareMagnitude, int32_t, BigDecimal*)},
	{"compareMagnitudeNormalized", "(JIJI)I", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, compareMagnitudeNormalized, int32_t, int64_t, int32_t, int64_t, int32_t)},
	{"compareMagnitudeNormalized", "(JILjava/math/BigInteger;I)I", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, compareMagnitudeNormalized, int32_t, int64_t, int32_t, $BigInteger*, int32_t)},
	{"compareMagnitudeNormalized", "(Ljava/math/BigInteger;ILjava/math/BigInteger;I)I", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, compareMagnitudeNormalized, int32_t, $BigInteger*, int32_t, $BigInteger*, int32_t)},
	{"compareTo", "(Ljava/math/BigDecimal;)I", nullptr, $PUBLIC, $virtualMethod(BigDecimal, compareTo, int32_t, BigDecimal*)},
	{"compareTo", "(Ljava/lang/Object;)I", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(BigDecimal, compareTo, int32_t, Object$*)},
	{"createAndStripZerosToMatchScale", "(Ljava/math/BigInteger;IJ)Ljava/math/BigDecimal;", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, createAndStripZerosToMatchScale, BigDecimal*, $BigInteger*, int32_t, int64_t)},
	{"createAndStripZerosToMatchScale", "(JIJ)Ljava/math/BigDecimal;", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, createAndStripZerosToMatchScale, BigDecimal*, int64_t, int32_t, int64_t)},
	{"divRemNegativeLong", "(JJ)[J", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, divRemNegativeLong, $longs*, int64_t, int64_t)},
	{"divide", "(Ljava/math/BigDecimal;II)Ljava/math/BigDecimal;", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(BigDecimal, divide, BigDecimal*, BigDecimal*, int32_t, int32_t), nullptr, nullptr, _BigDecimal_MethodAnnotations_divide49},
	{"divide", "(Ljava/math/BigDecimal;ILjava/math/RoundingMode;)Ljava/math/BigDecimal;", nullptr, $PUBLIC, $virtualMethod(BigDecimal, divide, BigDecimal*, BigDecimal*, int32_t, $RoundingMode*)},
	{"divide", "(Ljava/math/BigDecimal;I)Ljava/math/BigDecimal;", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(BigDecimal, divide, BigDecimal*, BigDecimal*, int32_t), nullptr, nullptr, _BigDecimal_MethodAnnotations_divide51},
	{"divide", "(Ljava/math/BigDecimal;Ljava/math/RoundingMode;)Ljava/math/BigDecimal;", nullptr, $PUBLIC, $virtualMethod(BigDecimal, divide, BigDecimal*, BigDecimal*, $RoundingMode*)},
	{"divide", "(Ljava/math/BigDecimal;)Ljava/math/BigDecimal;", nullptr, $PUBLIC, $virtualMethod(BigDecimal, divide, BigDecimal*, BigDecimal*)},
	{"divide", "(Ljava/math/BigDecimal;Ljava/math/MathContext;)Ljava/math/BigDecimal;", nullptr, $PUBLIC, $virtualMethod(BigDecimal, divide, BigDecimal*, BigDecimal*, $MathContext*)},
	{"divide", "(JIJIJLjava/math/MathContext;)Ljava/math/BigDecimal;", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, divide, BigDecimal*, int64_t, int32_t, int64_t, int32_t, int64_t, $MathContext*)},
	{"divide", "(Ljava/math/BigInteger;IJIJLjava/math/MathContext;)Ljava/math/BigDecimal;", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, divide, BigDecimal*, $BigInteger*, int32_t, int64_t, int32_t, int64_t, $MathContext*)},
	{"divide", "(JILjava/math/BigInteger;IJLjava/math/MathContext;)Ljava/math/BigDecimal;", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, divide, BigDecimal*, int64_t, int32_t, $BigInteger*, int32_t, int64_t, $MathContext*)},
	{"divide", "(Ljava/math/BigInteger;ILjava/math/BigInteger;IJLjava/math/MathContext;)Ljava/math/BigDecimal;", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, divide, BigDecimal*, $BigInteger*, int32_t, $BigInteger*, int32_t, int64_t, $MathContext*)},
	{"divide", "(JIJIII)Ljava/math/BigDecimal;", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, divide, BigDecimal*, int64_t, int32_t, int64_t, int32_t, int32_t, int32_t)},
	{"divide", "(Ljava/math/BigInteger;IJIII)Ljava/math/BigDecimal;", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, divide, BigDecimal*, $BigInteger*, int32_t, int64_t, int32_t, int32_t, int32_t)},
	{"divide", "(JILjava/math/BigInteger;III)Ljava/math/BigDecimal;", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, divide, BigDecimal*, int64_t, int32_t, $BigInteger*, int32_t, int32_t, int32_t)},
	{"divide", "(Ljava/math/BigInteger;ILjava/math/BigInteger;III)Ljava/math/BigDecimal;", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, divide, BigDecimal*, $BigInteger*, int32_t, $BigInteger*, int32_t, int32_t, int32_t)},
	{"divideAndRemainder", "(Ljava/math/BigDecimal;)[Ljava/math/BigDecimal;", nullptr, $PUBLIC, $virtualMethod(BigDecimal, divideAndRemainder, $BigDecimalArray*, BigDecimal*)},
	{"divideAndRemainder", "(Ljava/math/BigDecimal;Ljava/math/MathContext;)[Ljava/math/BigDecimal;", nullptr, $PUBLIC, $virtualMethod(BigDecimal, divideAndRemainder, $BigDecimalArray*, BigDecimal*, $MathContext*)},
	{"divideAndRound", "(JJIII)Ljava/math/BigDecimal;", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, divideAndRound, BigDecimal*, int64_t, int64_t, int32_t, int32_t, int32_t)},
	{"divideAndRound", "(JJI)J", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, divideAndRound, int64_t, int64_t, int64_t, int32_t)},
	{"divideAndRound", "(Ljava/math/BigInteger;JI)Ljava/math/BigInteger;", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, divideAndRound, $BigInteger*, $BigInteger*, int64_t, int32_t)},
	{"divideAndRound", "(Ljava/math/BigInteger;JIII)Ljava/math/BigDecimal;", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, divideAndRound, BigDecimal*, $BigInteger*, int64_t, int32_t, int32_t, int32_t)},
	{"divideAndRound", "(Ljava/math/BigInteger;Ljava/math/BigInteger;I)Ljava/math/BigInteger;", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, divideAndRound, $BigInteger*, $BigInteger*, $BigInteger*, int32_t)},
	{"divideAndRound", "(Ljava/math/BigInteger;Ljava/math/BigInteger;III)Ljava/math/BigDecimal;", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, divideAndRound, BigDecimal*, $BigInteger*, $BigInteger*, int32_t, int32_t, int32_t)},
	{"divideAndRound128", "(JJJIIII)Ljava/math/BigDecimal;", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, divideAndRound128, BigDecimal*, int64_t, int64_t, int64_t, int32_t, int32_t, int32_t, int32_t)},
	{"divideAndRoundByTenPow", "(Ljava/math/BigInteger;II)Ljava/math/BigInteger;", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, divideAndRoundByTenPow, $BigInteger*, $BigInteger*, int32_t, int32_t)},
	{"divideSmallFastPath", "(JIJIJLjava/math/MathContext;)Ljava/math/BigDecimal;", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, divideSmallFastPath, BigDecimal*, int64_t, int32_t, int64_t, int32_t, int64_t, $MathContext*)},
	{"divideToIntegralValue", "(Ljava/math/BigDecimal;)Ljava/math/BigDecimal;", nullptr, $PUBLIC, $virtualMethod(BigDecimal, divideToIntegralValue, BigDecimal*, BigDecimal*)},
	{"divideToIntegralValue", "(Ljava/math/BigDecimal;Ljava/math/MathContext;)Ljava/math/BigDecimal;", nullptr, $PUBLIC, $virtualMethod(BigDecimal, divideToIntegralValue, BigDecimal*, BigDecimal*, $MathContext*)},
	{"doRound", "(Ljava/math/BigDecimal;Ljava/math/MathContext;)Ljava/math/BigDecimal;", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, doRound, BigDecimal*, BigDecimal*, $MathContext*)},
	{"doRound", "(JILjava/math/MathContext;)Ljava/math/BigDecimal;", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, doRound, BigDecimal*, int64_t, int32_t, $MathContext*)},
	{"doRound", "(Ljava/math/BigInteger;ILjava/math/MathContext;)Ljava/math/BigDecimal;", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, doRound, BigDecimal*, $BigInteger*, int32_t, $MathContext*)},
	{"doRound128", "(JJIILjava/math/MathContext;)Ljava/math/BigDecimal;", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, doRound128, BigDecimal*, int64_t, int64_t, int32_t, int32_t, $MathContext*)},
	{"doubleValue", "()D", nullptr, $PUBLIC, $virtualMethod(BigDecimal, doubleValue, double)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(BigDecimal, equals, bool, Object$*)},
	{"expandBigIntegerTenPowers", "(I)Ljava/math/BigInteger;", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, expandBigIntegerTenPowers, $BigInteger*, int32_t)},
	{"floatValue", "()F", nullptr, $PUBLIC, $virtualMethod(BigDecimal, floatValue, float)},
	{"fractionOnly", "()Z", nullptr, $PRIVATE, $method(BigDecimal, fractionOnly, bool)},
	{"getValueString", "(ILjava/lang/String;I)Ljava/lang/String;", nullptr, $PRIVATE, $method(BigDecimal, getValueString, $String*, int32_t, $String*, int32_t)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(BigDecimal, hashCode, int32_t)},
	{"inflated", "()Ljava/math/BigInteger;", nullptr, $PRIVATE, $method(BigDecimal, inflated, $BigInteger*)},
	{"intValue", "()I", nullptr, $PUBLIC, $virtualMethod(BigDecimal, intValue, int32_t)},
	{"intValueExact", "()I", nullptr, $PUBLIC, $virtualMethod(BigDecimal, intValueExact, int32_t)},
	{"isPowerOfTen", "()Z", nullptr, $PRIVATE, $method(BigDecimal, isPowerOfTen, bool)},
	{"layoutChars", "(Z)Ljava/lang/String;", nullptr, $PRIVATE, $method(BigDecimal, layoutChars, $String*, bool)},
	{"longCompareMagnitude", "(JJ)I", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, longCompareMagnitude, int32_t, int64_t, int64_t)},
	{"longDigitLength", "(J)I", nullptr, $STATIC, $staticMethod(BigDecimal, longDigitLength, int32_t, int64_t)},
	{"longLongCompareMagnitude", "(JJJJ)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, longLongCompareMagnitude, bool, int64_t, int64_t, int64_t, int64_t)},
	{"longMultiplyPowerTen", "(JI)J", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, longMultiplyPowerTen, int64_t, int64_t, int32_t)},
	{"longValue", "()J", nullptr, $PUBLIC, $virtualMethod(BigDecimal, longValue, int64_t)},
	{"longValueExact", "()J", nullptr, $PUBLIC, $virtualMethod(BigDecimal, longValueExact, int64_t)},
	{"make64", "(JJ)J", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, make64, int64_t, int64_t, int64_t)},
	{"matchScale", "([Ljava/math/BigDecimal;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, matchScale, void, $BigDecimalArray*)},
	{"max", "(Ljava/math/BigDecimal;)Ljava/math/BigDecimal;", nullptr, $PUBLIC, $virtualMethod(BigDecimal, max, BigDecimal*, BigDecimal*)},
	{"min", "(Ljava/math/BigDecimal;)Ljava/math/BigDecimal;", nullptr, $PUBLIC, $virtualMethod(BigDecimal, min, BigDecimal*, BigDecimal*)},
	{"movePointLeft", "(I)Ljava/math/BigDecimal;", nullptr, $PUBLIC, $virtualMethod(BigDecimal, movePointLeft, BigDecimal*, int32_t)},
	{"movePointRight", "(I)Ljava/math/BigDecimal;", nullptr, $PUBLIC, $virtualMethod(BigDecimal, movePointRight, BigDecimal*, int32_t)},
	{"mulsub", "(JJJJJ)J", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, mulsub, int64_t, int64_t, int64_t, int64_t, int64_t, int64_t)},
	{"multiply", "(Ljava/math/BigDecimal;)Ljava/math/BigDecimal;", nullptr, $PUBLIC, $virtualMethod(BigDecimal, multiply, BigDecimal*, BigDecimal*)},
	{"multiply", "(Ljava/math/BigDecimal;Ljava/math/MathContext;)Ljava/math/BigDecimal;", nullptr, $PUBLIC, $virtualMethod(BigDecimal, multiply, BigDecimal*, BigDecimal*, $MathContext*)},
	{"multiply", "(JJ)J", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, multiply, int64_t, int64_t, int64_t)},
	{"multiply", "(JJI)Ljava/math/BigDecimal;", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, multiply, BigDecimal*, int64_t, int64_t, int32_t)},
	{"multiply", "(JLjava/math/BigInteger;I)Ljava/math/BigDecimal;", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, multiply, BigDecimal*, int64_t, $BigInteger*, int32_t)},
	{"multiply", "(Ljava/math/BigInteger;Ljava/math/BigInteger;I)Ljava/math/BigDecimal;", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, multiply, BigDecimal*, $BigInteger*, $BigInteger*, int32_t)},
	{"multiplyAndRound", "(JJILjava/math/MathContext;)Ljava/math/BigDecimal;", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, multiplyAndRound, BigDecimal*, int64_t, int64_t, int32_t, $MathContext*)},
	{"multiplyAndRound", "(JLjava/math/BigInteger;ILjava/math/MathContext;)Ljava/math/BigDecimal;", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, multiplyAndRound, BigDecimal*, int64_t, $BigInteger*, int32_t, $MathContext*)},
	{"multiplyAndRound", "(Ljava/math/BigInteger;Ljava/math/BigInteger;ILjava/math/MathContext;)Ljava/math/BigDecimal;", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, multiplyAndRound, BigDecimal*, $BigInteger*, $BigInteger*, int32_t, $MathContext*)},
	{"multiplyDivideAndRound", "(JJJIII)Ljava/math/BigDecimal;", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, multiplyDivideAndRound, BigDecimal*, int64_t, int64_t, int64_t, int32_t, int32_t, int32_t)},
	{"needIncrement", "(JIIJJ)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, needIncrement, bool, int64_t, int32_t, int32_t, int64_t, int64_t)},
	{"needIncrement", "(JIILjava/math/MutableBigInteger;J)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, needIncrement, bool, int64_t, int32_t, int32_t, $MutableBigInteger*, int64_t)},
	{"needIncrement", "(Ljava/math/MutableBigInteger;IILjava/math/MutableBigInteger;Ljava/math/MutableBigInteger;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, needIncrement, bool, $MutableBigInteger*, int32_t, int32_t, $MutableBigInteger*, $MutableBigInteger*)},
	{"negate", "()Ljava/math/BigDecimal;", nullptr, $PUBLIC, $virtualMethod(BigDecimal, negate, BigDecimal*)},
	{"negate", "(Ljava/math/MathContext;)Ljava/math/BigDecimal;", nullptr, $PUBLIC, $virtualMethod(BigDecimal, negate, BigDecimal*, $MathContext*)},
	{"parseExp", "([CII)J", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, parseExp, int64_t, $chars*, int32_t, int32_t)},
	{"plus", "()Ljava/math/BigDecimal;", nullptr, $PUBLIC, $virtualMethod(BigDecimal, plus, BigDecimal*)},
	{"plus", "(Ljava/math/MathContext;)Ljava/math/BigDecimal;", nullptr, $PUBLIC, $virtualMethod(BigDecimal, plus, BigDecimal*, $MathContext*)},
	{"pow", "(I)Ljava/math/BigDecimal;", nullptr, $PUBLIC, $virtualMethod(BigDecimal, pow, BigDecimal*, int32_t)},
	{"pow", "(ILjava/math/MathContext;)Ljava/math/BigDecimal;", nullptr, $PUBLIC, $virtualMethod(BigDecimal, pow, BigDecimal*, int32_t, $MathContext*)},
	{"preAlign", "(Ljava/math/BigDecimal;Ljava/math/BigDecimal;JLjava/math/MathContext;)[Ljava/math/BigDecimal;", nullptr, $PRIVATE, $method(BigDecimal, preAlign, $BigDecimalArray*, BigDecimal*, BigDecimal*, int64_t, $MathContext*)},
	{"precision", "()I", nullptr, $PUBLIC, $virtualMethod(BigDecimal, precision, int32_t)},
	{"precision", "(JJ)I", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, precision, int32_t, int64_t, int64_t)},
	{"print", "(Ljava/lang/String;Ljava/math/BigDecimal;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, print, void, $String*, BigDecimal*)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(BigDecimal, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"remainder", "(Ljava/math/BigDecimal;)Ljava/math/BigDecimal;", nullptr, $PUBLIC, $virtualMethod(BigDecimal, remainder, BigDecimal*, BigDecimal*)},
	{"remainder", "(Ljava/math/BigDecimal;Ljava/math/MathContext;)Ljava/math/BigDecimal;", nullptr, $PUBLIC, $virtualMethod(BigDecimal, remainder, BigDecimal*, BigDecimal*, $MathContext*)},
	{"round", "(Ljava/math/MathContext;)Ljava/math/BigDecimal;", nullptr, $PUBLIC, $virtualMethod(BigDecimal, round, BigDecimal*, $MathContext*)},
	{"roundedTenPower", "(IIII)Ljava/math/BigDecimal;", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, roundedTenPower, BigDecimal*, int32_t, int32_t, int32_t, int32_t)},
	{"saturateLong", "(J)I", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, saturateLong, int32_t, int64_t)},
	{"scale", "()I", nullptr, $PUBLIC, $virtualMethod(BigDecimal, scale, int32_t)},
	{"scaleByPowerOfTen", "(I)Ljava/math/BigDecimal;", nullptr, $PUBLIC, $virtualMethod(BigDecimal, scaleByPowerOfTen, BigDecimal*, int32_t)},
	{"scaledTenPow", "(III)Ljava/math/BigDecimal;", nullptr, $STATIC, $staticMethod(BigDecimal, scaledTenPow, BigDecimal*, int32_t, int32_t, int32_t)},
	{"setScale", "(ILjava/math/RoundingMode;)Ljava/math/BigDecimal;", nullptr, $PUBLIC, $virtualMethod(BigDecimal, setScale, BigDecimal*, int32_t, $RoundingMode*)},
	{"setScale", "(II)Ljava/math/BigDecimal;", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(BigDecimal, setScale, BigDecimal*, int32_t, int32_t), nullptr, nullptr, _BigDecimal_MethodAnnotations_setScale139},
	{"setScale", "(I)Ljava/math/BigDecimal;", nullptr, $PUBLIC, $virtualMethod(BigDecimal, setScale, BigDecimal*, int32_t)},
	{"shortValueExact", "()S", nullptr, $PUBLIC, $virtualMethod(BigDecimal, shortValueExact, int16_t)},
	{"signum", "()I", nullptr, $PUBLIC, $virtualMethod(BigDecimal, signum, int32_t)},
	{"sqrt", "(Ljava/math/MathContext;)Ljava/math/BigDecimal;", nullptr, $PUBLIC, $virtualMethod(BigDecimal, sqrt, BigDecimal*, $MathContext*)},
	{"square", "()Ljava/math/BigDecimal;", nullptr, $PRIVATE, $method(BigDecimal, square, BigDecimal*)},
	{"squareRootResultAssertions", "(Ljava/math/BigDecimal;Ljava/math/MathContext;)Z", nullptr, $PRIVATE, $method(BigDecimal, squareRootResultAssertions, bool, BigDecimal*, $MathContext*)},
	{"squareRootZeroResultAssertions", "(Ljava/math/BigDecimal;Ljava/math/MathContext;)Z", nullptr, $PRIVATE, $method(BigDecimal, squareRootZeroResultAssertions, bool, BigDecimal*, $MathContext*)},
	{"stripTrailingZeros", "()Ljava/math/BigDecimal;", nullptr, $PUBLIC, $virtualMethod(BigDecimal, stripTrailingZeros, BigDecimal*)},
	{"stripZerosToMatchScale", "(Ljava/math/BigInteger;JII)Ljava/math/BigDecimal;", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, stripZerosToMatchScale, BigDecimal*, $BigInteger*, int64_t, int32_t, int32_t)},
	{"subtract", "(Ljava/math/BigDecimal;)Ljava/math/BigDecimal;", nullptr, $PUBLIC, $virtualMethod(BigDecimal, subtract, BigDecimal*, BigDecimal*)},
	{"subtract", "(Ljava/math/BigDecimal;Ljava/math/MathContext;)Ljava/math/BigDecimal;", nullptr, $PUBLIC, $virtualMethod(BigDecimal, subtract, BigDecimal*, BigDecimal*, $MathContext*)},
	{"toBigInteger", "()Ljava/math/BigInteger;", nullptr, $PUBLIC, $virtualMethod(BigDecimal, toBigInteger, $BigInteger*)},
	{"toBigIntegerExact", "()Ljava/math/BigInteger;", nullptr, $PUBLIC, $virtualMethod(BigDecimal, toBigIntegerExact, $BigInteger*)},
	{"toEngineeringString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(BigDecimal, toEngineeringString, $String*)},
	{"toPlainString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(BigDecimal, toPlainString, $String*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(BigDecimal, toString, $String*)},
	{"ulp", "()Ljava/math/BigDecimal;", nullptr, $PUBLIC, $virtualMethod(BigDecimal, ulp, BigDecimal*)},
	{"unscaledValue", "()Ljava/math/BigInteger;", nullptr, $PUBLIC, $virtualMethod(BigDecimal, unscaledValue, $BigInteger*)},
	{"unsignedLongCompare", "(JJ)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, unsignedLongCompare, bool, int64_t, int64_t)},
	{"unsignedLongCompareEq", "(JJ)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(BigDecimal, unsignedLongCompareEq, bool, int64_t, int64_t)},
	{"valueOf", "(JI)Ljava/math/BigDecimal;", nullptr, $PUBLIC | $STATIC, $staticMethod(BigDecimal, valueOf, BigDecimal*, int64_t, int32_t)},
	{"valueOf", "(J)Ljava/math/BigDecimal;", nullptr, $PUBLIC | $STATIC, $staticMethod(BigDecimal, valueOf, BigDecimal*, int64_t)},
	{"valueOf", "(JII)Ljava/math/BigDecimal;", nullptr, $STATIC, $staticMethod(BigDecimal, valueOf, BigDecimal*, int64_t, int32_t, int32_t)},
	{"valueOf", "(Ljava/math/BigInteger;II)Ljava/math/BigDecimal;", nullptr, $STATIC, $staticMethod(BigDecimal, valueOf, BigDecimal*, $BigInteger*, int32_t, int32_t)},
	{"valueOf", "(D)Ljava/math/BigDecimal;", nullptr, $PUBLIC | $STATIC, $staticMethod(BigDecimal, valueOf, BigDecimal*, double)},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE, $method(BigDecimal, writeObject, void, $ObjectOutputStream*), "java.io.IOException"},
	{"zeroValueOf", "(I)Ljava/math/BigDecimal;", nullptr, $STATIC, $staticMethod(BigDecimal, zeroValueOf, BigDecimal*, int32_t)},
	{}
};

$InnerClassInfo _BigDecimal_InnerClassesInfo_[] = {
	{"java.math.BigDecimal$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{"java.math.BigDecimal$UnsafeHolder", "java.math.BigDecimal", "UnsafeHolder", $PRIVATE | $STATIC},
	{"java.math.BigDecimal$StringBuilderHelper", "java.math.BigDecimal", "StringBuilderHelper", $STATIC},
	{"java.math.BigDecimal$LongOverflow", "java.math.BigDecimal", "LongOverflow", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _BigDecimal_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.math.BigDecimal",
	"java.lang.Number",
	"java.lang.Comparable",
	_BigDecimal_FieldInfo_,
	_BigDecimal_MethodInfo_,
	"Ljava/lang/Number;Ljava/lang/Comparable<Ljava/math/BigDecimal;>;",
	nullptr,
	_BigDecimal_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.math.BigDecimal$1,java.math.BigDecimal$UnsafeHolder,java.math.BigDecimal$StringBuilderHelper,java.math.BigDecimal$LongOverflow"
};

$Object* allocate$BigDecimal($Class* clazz) {
	return $of($alloc(BigDecimal));
}

$Object* BigDecimal::clone() {
	 return this->$Number::clone();
}

void BigDecimal::finalize() {
	this->$Number::finalize();
}

bool BigDecimal::$assertionsDisabled = false;
$BigInteger* BigDecimal::INFLATED_BIGINT = nullptr;
$BigDecimalArray* BigDecimal::ZERO_THROUGH_TEN = nullptr;
$BigDecimalArray* BigDecimal::ZERO_SCALED_BY = nullptr;
BigDecimal* BigDecimal::ZERO = nullptr;
BigDecimal* BigDecimal::ONE = nullptr;
BigDecimal* BigDecimal::TEN = nullptr;
BigDecimal* BigDecimal::ONE_TENTH = nullptr;
BigDecimal* BigDecimal::ONE_HALF = nullptr;
$doubles* BigDecimal::DOUBLE_10_POW = nullptr;
$floats* BigDecimal::FLOAT_10_POW = nullptr;
$longs* BigDecimal::LONG_TEN_POWERS_TABLE = nullptr;
$volatile($BigIntegerArray*) BigDecimal::BIG_TEN_POWERS_TABLE = nullptr;
int32_t BigDecimal::BIG_TEN_POWERS_TABLE_INITLEN = 0;
int32_t BigDecimal::BIG_TEN_POWERS_TABLE_MAX = 0;
$longs* BigDecimal::THRESHOLDS_TABLE = nullptr;
$longArray2* BigDecimal::LONGLONG_TEN_POWERS_TABLE = nullptr;

void BigDecimal::init$($BigInteger* intVal, int64_t val, int32_t scale, int32_t prec) {
	$Number::init$();
	this->scale$ = scale;
	this->precision$ = prec;
	this->intCompact = val;
	$set(this, intVal, intVal);
}

void BigDecimal::init$($chars* in, int32_t offset, int32_t len) {
	$init($MathContext);
	BigDecimal::init$(in, offset, len, $MathContext::UNLIMITED);
}

void BigDecimal::init$($chars* in, int32_t offset, int32_t len, $MathContext* mc) {
	$useLocalCurrentObjectStackCache();
	$Number::init$();
	try {
		$Objects::checkFromIndexSize(offset, len, $nc(in)->length);
	} catch ($IndexOutOfBoundsException& e) {
		$throwNew($NumberFormatException, "Bad offset or len arguments for char[] input."_s);
	}
	int32_t prec = 0;
	int32_t scl = 0;
	int64_t rs = 0;
	$var($BigInteger, rb, nullptr);
	try {
		bool isneg = false;
		if ($nc(in)->get(offset) == u'-') {
			isneg = true;
			++offset;
			--len;
		} else if (in->get(offset) == u'+') {
			++offset;
			--len;
		}
		bool dot = false;
		int64_t exp = 0;
		char16_t c = 0;
		bool isCompact = (len <= BigDecimal::MAX_COMPACT_DIGITS);
		int32_t idx = 0;
		if (isCompact) {
			for (; len > 0; ++offset, --len) {
				c = $nc(in)->get(offset);
				if (c == u'0') {
					if (prec == 0) {
						prec = 1;
					} else if (rs != 0) {
						rs *= 10;
						++prec;
					}
					if (dot) {
						++scl;
					}
				} else if (c >= u'1' && c <= u'9') {
					int32_t digit = c - u'0';
					if (prec != 1 || rs != 0) {
						++prec;
					}
					rs = rs * 10 + digit;
					if (dot) {
						++scl;
					}
				} else if (c == u'.') {
					if (dot) {
						$throwNew($NumberFormatException, "Character array contains more than one decimal point."_s);
					}
					dot = true;
				} else if ($Character::isDigit(c)) {
					int32_t digit = $Character::digit(c, 10);
					if (digit == 0) {
						if (prec == 0) {
							prec = 1;
						} else if (rs != 0) {
							rs *= 10;
							++prec;
						}
					} else {
						if (prec != 1 || rs != 0) {
							++prec;
						}
						rs = rs * 10 + digit;
					}
					if (dot) {
						++scl;
					}
				} else if ((c == u'e') || (c == u'E')) {
					exp = parseExp(in, offset, len);
					if ((int32_t)exp != exp) {
						$throwNew($NumberFormatException, "Exponent overflow."_s);
					}
					break;
				} else {
					$throwNew($NumberFormatException, $$str({"Character "_s, $$str(c), " is neither a decimal digit number, decimal point, nor \"e\" notation exponential mark."_s}));
				}
			}
			if (prec == 0) {
				$throwNew($NumberFormatException, "No digits found."_s);
			}
			if (exp != 0) {
				scl = adjustScale(scl, exp);
			}
			rs = isneg ? -rs : rs;
			int32_t mcp = $nc(mc)->precision;
			int32_t drop = prec - mcp;
			if (mcp > 0 && drop > 0) {
				while (drop > 0) {
					scl = checkScaleNonZero((int64_t)scl - drop);
					rs = divideAndRound(rs, $nc(BigDecimal::LONG_TEN_POWERS_TABLE)->get(drop), mc->roundingMode->oldMode);
					prec = longDigitLength(rs);
					drop = prec - mcp;
				}
			}
		} else {
			$var($chars, coeff, $new($chars, len));
			for (; len > 0; ++offset, --len) {
				c = $nc(in)->get(offset);
				if ((c >= u'0' && c <= u'9') || $Character::isDigit(c)) {
					if (c == u'0' || $Character::digit(c, 10) == 0) {
						if (prec == 0) {
							coeff->set(idx, c);
							prec = 1;
						} else if (idx != 0) {
							coeff->set(idx++, c);
							++prec;
						}
					} else {
						if (prec != 1 || idx != 0) {
							++prec;
						}
						coeff->set(idx++, c);
					}
					if (dot) {
						++scl;
					}
					continue;
				}
				if (c == u'.') {
					if (dot) {
						$throwNew($NumberFormatException, "Character array contains more than one decimal point."_s);
					}
					dot = true;
					continue;
				}
				if ((c != u'e') && (c != u'E')) {
					$throwNew($NumberFormatException, "Character array is missing \"e\" notation exponential mark."_s);
				}
				exp = parseExp(in, offset, len);
				if ((int32_t)exp != exp) {
					$throwNew($NumberFormatException, "Exponent overflow."_s);
				}
				break;
			}
			if (prec == 0) {
				$throwNew($NumberFormatException, "No digits found."_s);
			}
			if (exp != 0) {
				scl = adjustScale(scl, exp);
			}
			$assign(rb, $new($BigInteger, coeff, isneg ? -1 : 1, prec));
			rs = compactValFor(rb);
			int32_t mcp = $nc(mc)->precision;
			if (mcp > 0 && (prec > mcp)) {
				if (rs == BigDecimal::INFLATED) {
					int32_t drop = prec - mcp;
					while (drop > 0) {
						scl = checkScaleNonZero((int64_t)scl - drop);
						$assign(rb, divideAndRoundByTenPow(rb, drop, mc->roundingMode->oldMode));
						rs = compactValFor(rb);
						if (rs != BigDecimal::INFLATED) {
							prec = longDigitLength(rs);
							break;
						}
						prec = bigDigitLength(rb);
						drop = prec - mcp;
					}
				}
				if (rs != BigDecimal::INFLATED) {
					int32_t drop = prec - mcp;
					while (drop > 0) {
						scl = checkScaleNonZero((int64_t)scl - drop);
						rs = divideAndRound(rs, $nc(BigDecimal::LONG_TEN_POWERS_TABLE)->get(drop), mc->roundingMode->oldMode);
						prec = longDigitLength(rs);
						drop = prec - mcp;
					}
					$assign(rb, nullptr);
				}
			}
		}
	} catch ($ArrayIndexOutOfBoundsException& e) {
		$var($NumberFormatException, nfe, $new($NumberFormatException));
		nfe->initCause(e);
		$throw(nfe);
	} catch ($NegativeArraySizeException& e) {
		$var($NumberFormatException, nfe, $new($NumberFormatException));
		nfe->initCause(e);
		$throw(nfe);
	}
	this->scale$ = scl;
	this->precision$ = prec;
	this->intCompact = rs;
	$set(this, intVal, rb);
}

int32_t BigDecimal::adjustScale(int32_t scl, int64_t exp) {
	int64_t adjustedScale = scl - exp;
	if (adjustedScale > $Integer::MAX_VALUE || adjustedScale < $Integer::MIN_VALUE) {
		$throwNew($NumberFormatException, "Scale out of range."_s);
	}
	scl = (int32_t)adjustedScale;
	return scl;
}

int64_t BigDecimal::parseExp($chars* in, int32_t offset, int32_t len) {
	$init(BigDecimal);
	int64_t exp = 0;
	++offset;
	char16_t c = $nc(in)->get(offset);
	--len;
	bool negexp = (c == u'-');
	if (negexp || c == u'+') {
		++offset;
		c = in->get(offset);
		--len;
	}
	if (len <= 0) {
		$throwNew($NumberFormatException, "No exponent digits."_s);
	}
	while (len > 10 && (c == u'0' || ($Character::digit(c, 10) == 0))) {
		++offset;
		c = in->get(offset);
		--len;
	}
	if (len > 10) {
		$throwNew($NumberFormatException, "Too many nonzero exponent digits."_s);
	}
	for (;; --len) {
		int32_t v = 0;
		if (c >= u'0' && c <= u'9') {
			v = c - u'0';
		} else {
			v = $Character::digit(c, 10);
			if (v < 0) {
				$throwNew($NumberFormatException, "Not a digit."_s);
			}
		}
		exp = exp * 10 + v;
		if (len == 1) {
			break;
		}
		++offset;
		c = in->get(offset);
	}
	if (negexp) {
		exp = -exp;
	}
	return exp;
}

void BigDecimal::init$($chars* in) {
	BigDecimal::init$(in, 0, $nc(in)->length);
}

void BigDecimal::init$($chars* in, $MathContext* mc) {
	BigDecimal::init$(in, 0, $nc(in)->length, mc);
}

void BigDecimal::init$($String* val) {
	$var($chars, var$0, $nc(val)->toCharArray());
	BigDecimal::init$(var$0, 0, val->length());
}

void BigDecimal::init$($String* val, $MathContext* mc) {
	$var($chars, var$0, $nc(val)->toCharArray());
	BigDecimal::init$(var$0, 0, val->length(), mc);
}

void BigDecimal::init$(double val) {
	$init($MathContext);
	BigDecimal::init$(val, $MathContext::UNLIMITED);
}

void BigDecimal::init$(double val, $MathContext* mc) {
	$useLocalCurrentObjectStackCache();
	$Number::init$();
	bool var$0 = $Double::isInfinite(val);
	if (var$0 || $Double::isNaN(val)) {
		$throwNew($NumberFormatException, "Infinite or NaN"_s);
	}
	int64_t valBits = $Double::doubleToLongBits(val);
	int32_t sign = ((valBits >> 63) == 0 ? 1 : -1);
	int32_t exponent = (int32_t)((int64_t)((valBits >> 52) & (uint64_t)(int64_t)2047));
	int64_t significand = (exponent == 0 ? ((int64_t)(valBits & (uint64_t)(((int64_t)1 << 52) - 1))) << 1 : ((int64_t)(valBits & (uint64_t)(((int64_t)1 << 52) - 1))) | ((int64_t)1 << 52));
	exponent -= 1075;
	if (significand == 0) {
		$init($BigInteger);
		$set(this, intVal, $BigInteger::ZERO);
		this->scale$ = 0;
		this->intCompact = 0;
		this->precision$ = 1;
		return;
	}
	while (((int64_t)(significand & (uint64_t)(int64_t)1)) == 0) {
		significand >>= 1;
		++exponent;
	}
	int32_t scl = 0;
	$var($BigInteger, rb, nullptr);
	int64_t compactVal = sign * significand;
	if (exponent == 0) {
		$assign(rb, (compactVal == BigDecimal::INFLATED) ? BigDecimal::INFLATED_BIGINT : ($BigInteger*)nullptr);
	} else {
		if (exponent < 0) {
			$assign(rb, $nc($($nc($($BigInteger::valueOf((int64_t)5)))->pow(-exponent)))->multiply(compactVal));
			scl = -exponent;
		} else {
			$init($BigInteger);
			$assign(rb, $nc($($nc($BigInteger::TWO)->pow(exponent)))->multiply(compactVal));
		}
		compactVal = compactValFor(rb);
	}
	int32_t prec = 0;
	int32_t mcp = $nc(mc)->precision;
	if (mcp > 0) {
		int32_t mode = mc->roundingMode->oldMode;
		int32_t drop = 0;
		if (compactVal == BigDecimal::INFLATED) {
			prec = bigDigitLength(rb);
			drop = prec - mcp;
			while (drop > 0) {
				scl = checkScaleNonZero((int64_t)scl - drop);
				$assign(rb, divideAndRoundByTenPow(rb, drop, mode));
				compactVal = compactValFor(rb);
				if (compactVal != BigDecimal::INFLATED) {
					break;
				}
				prec = bigDigitLength(rb);
				drop = prec - mcp;
			}
		}
		if (compactVal != BigDecimal::INFLATED) {
			prec = longDigitLength(compactVal);
			drop = prec - mcp;
			while (drop > 0) {
				scl = checkScaleNonZero((int64_t)scl - drop);
				compactVal = divideAndRound(compactVal, $nc(BigDecimal::LONG_TEN_POWERS_TABLE)->get(drop), mc->roundingMode->oldMode);
				prec = longDigitLength(compactVal);
				drop = prec - mcp;
			}
			$assign(rb, nullptr);
		}
	}
	$set(this, intVal, rb);
	this->intCompact = compactVal;
	this->scale$ = scl;
	this->precision$ = prec;
}

void BigDecimal::init$($BigInteger* val) {
	$Number::init$();
	this->scale$ = 0;
	$set(this, intVal, val);
	this->intCompact = compactValFor(val);
}

void BigDecimal::init$($BigInteger* val, $MathContext* mc) {
	BigDecimal::init$(val, 0, mc);
}

void BigDecimal::init$($BigInteger* unscaledVal, int32_t scale) {
	$Number::init$();
	$set(this, intVal, unscaledVal);
	this->intCompact = compactValFor(unscaledVal);
	this->scale$ = scale;
}

void BigDecimal::init$($BigInteger* unscaledVal$renamed, int32_t scale, $MathContext* mc) {
	$var($BigInteger, unscaledVal, unscaledVal$renamed);
	$Number::init$();
	int64_t compactVal = compactValFor(unscaledVal);
	int32_t mcp = $nc(mc)->precision;
	int32_t prec = 0;
	if (mcp > 0) {
		int32_t mode = mc->roundingMode->oldMode;
		if (compactVal == BigDecimal::INFLATED) {
			prec = bigDigitLength(unscaledVal);
			int32_t drop = prec - mcp;
			while (drop > 0) {
				scale = checkScaleNonZero((int64_t)scale - drop);
				$assign(unscaledVal, divideAndRoundByTenPow(unscaledVal, drop, mode));
				compactVal = compactValFor(unscaledVal);
				if (compactVal != BigDecimal::INFLATED) {
					break;
				}
				prec = bigDigitLength(unscaledVal);
				drop = prec - mcp;
			}
		}
		if (compactVal != BigDecimal::INFLATED) {
			prec = longDigitLength(compactVal);
			int32_t drop = prec - mcp;
			while (drop > 0) {
				scale = checkScaleNonZero((int64_t)scale - drop);
				compactVal = divideAndRound(compactVal, $nc(BigDecimal::LONG_TEN_POWERS_TABLE)->get(drop), mode);
				prec = longDigitLength(compactVal);
				drop = prec - mcp;
			}
			$assign(unscaledVal, nullptr);
		}
	}
	$set(this, intVal, unscaledVal);
	this->intCompact = compactVal;
	this->scale$ = scale;
	this->precision$ = prec;
}

void BigDecimal::init$(int32_t val) {
	$Number::init$();
	this->intCompact = val;
	this->scale$ = 0;
	$set(this, intVal, nullptr);
}

void BigDecimal::init$(int32_t val, $MathContext* mc) {
	$Number::init$();
	int32_t mcp = $nc(mc)->precision;
	int64_t compactVal = val;
	int32_t scl = 0;
	int32_t prec = 0;
	if (mcp > 0) {
		prec = longDigitLength(compactVal);
		int32_t drop = prec - mcp;
		while (drop > 0) {
			scl = checkScaleNonZero((int64_t)scl - drop);
			compactVal = divideAndRound(compactVal, $nc(BigDecimal::LONG_TEN_POWERS_TABLE)->get(drop), mc->roundingMode->oldMode);
			prec = longDigitLength(compactVal);
			drop = prec - mcp;
		}
	}
	$set(this, intVal, nullptr);
	this->intCompact = compactVal;
	this->scale$ = scl;
	this->precision$ = prec;
}

void BigDecimal::init$(int64_t val) {
	$Number::init$();
	this->intCompact = val;
	$set(this, intVal, (val == BigDecimal::INFLATED) ? BigDecimal::INFLATED_BIGINT : ($BigInteger*)nullptr);
	this->scale$ = 0;
}

void BigDecimal::init$(int64_t val, $MathContext* mc) {
	$Number::init$();
	int32_t mcp = $nc(mc)->precision;
	int32_t mode = mc->roundingMode->oldMode;
	int32_t prec = 0;
	int32_t scl = 0;
	$var($BigInteger, rb, (val == BigDecimal::INFLATED) ? BigDecimal::INFLATED_BIGINT : ($BigInteger*)nullptr);
	if (mcp > 0) {
		if (val == BigDecimal::INFLATED) {
			prec = 19;
			int32_t drop = prec - mcp;
			while (drop > 0) {
				scl = checkScaleNonZero((int64_t)scl - drop);
				$assign(rb, divideAndRoundByTenPow(rb, drop, mode));
				val = compactValFor(rb);
				if (val != BigDecimal::INFLATED) {
					break;
				}
				prec = bigDigitLength(rb);
				drop = prec - mcp;
			}
		}
		if (val != BigDecimal::INFLATED) {
			prec = longDigitLength(val);
			int32_t drop = prec - mcp;
			while (drop > 0) {
				scl = checkScaleNonZero((int64_t)scl - drop);
				val = divideAndRound(val, $nc(BigDecimal::LONG_TEN_POWERS_TABLE)->get(drop), mc->roundingMode->oldMode);
				prec = longDigitLength(val);
				drop = prec - mcp;
			}
			$assign(rb, nullptr);
		}
	}
	$set(this, intVal, rb);
	this->intCompact = val;
	this->scale$ = scl;
	this->precision$ = prec;
}

BigDecimal* BigDecimal::valueOf(int64_t unscaledVal, int32_t scale) {
	$init(BigDecimal);
	if (scale == 0) {
		return valueOf(unscaledVal);
	} else if (unscaledVal == 0) {
		return zeroValueOf(scale);
	}
	return $new(BigDecimal, unscaledVal == BigDecimal::INFLATED ? BigDecimal::INFLATED_BIGINT : ($BigInteger*)nullptr, unscaledVal, scale, 0);
}

BigDecimal* BigDecimal::valueOf(int64_t val) {
	$init(BigDecimal);
	if (val >= 0 && val < $nc(BigDecimal::ZERO_THROUGH_TEN)->length) {
		return $nc(BigDecimal::ZERO_THROUGH_TEN)->get((int32_t)val);
	} else if (val != BigDecimal::INFLATED) {
		return $new(BigDecimal, ($BigInteger*)nullptr, val, 0, 0);
	}
	return $new(BigDecimal, BigDecimal::INFLATED_BIGINT, val, 0, 0);
}

BigDecimal* BigDecimal::valueOf(int64_t unscaledVal, int32_t scale, int32_t prec) {
	$init(BigDecimal);
	if (scale == 0 && unscaledVal >= 0 && unscaledVal < $nc(BigDecimal::ZERO_THROUGH_TEN)->length) {
		return $nc(BigDecimal::ZERO_THROUGH_TEN)->get((int32_t)unscaledVal);
	} else if (unscaledVal == 0) {
		return zeroValueOf(scale);
	}
	return $new(BigDecimal, unscaledVal == BigDecimal::INFLATED ? BigDecimal::INFLATED_BIGINT : ($BigInteger*)nullptr, unscaledVal, scale, prec);
}

BigDecimal* BigDecimal::valueOf($BigInteger* intVal, int32_t scale, int32_t prec) {
	$init(BigDecimal);
	int64_t val = compactValFor(intVal);
	if (val == 0) {
		return zeroValueOf(scale);
	} else {
		if (scale == 0 && val >= 0 && val < $nc(BigDecimal::ZERO_THROUGH_TEN)->length) {
			return $nc(BigDecimal::ZERO_THROUGH_TEN)->get((int32_t)val);
		}
	}
	return $new(BigDecimal, intVal, val, scale, prec);
}

BigDecimal* BigDecimal::zeroValueOf(int32_t scale) {
	$init(BigDecimal);
	if (scale >= 0 && scale < $nc(BigDecimal::ZERO_SCALED_BY)->length) {
		return $nc(BigDecimal::ZERO_SCALED_BY)->get(scale);
	} else {
		$init($BigInteger);
		return $new(BigDecimal, $BigInteger::ZERO, (int64_t)0, scale, 1);
	}
}

BigDecimal* BigDecimal::valueOf(double val) {
	$init(BigDecimal);
	return $new(BigDecimal, $($Double::toString(val)));
}

BigDecimal* BigDecimal::add(BigDecimal* augend) {
	if (this->intCompact != BigDecimal::INFLATED) {
		if ($nc(augend)->intCompact != BigDecimal::INFLATED) {
			return add(this->intCompact, this->scale$, augend->intCompact, augend->scale$);
		} else {
			return add(this->intCompact, this->scale$, augend->intVal, augend->scale$);
		}
	} else if ($nc(augend)->intCompact != BigDecimal::INFLATED) {
		return add(augend->intCompact, augend->scale$, this->intVal, this->scale$);
	} else {
		return add(this->intVal, this->scale$, augend->intVal, augend->scale$);
	}
}

BigDecimal* BigDecimal::add(BigDecimal* augend$renamed, $MathContext* mc) {
	$useLocalCurrentObjectStackCache();
	$var(BigDecimal, augend, augend$renamed);
	if ($nc(mc)->precision == 0) {
		return add(augend);
	}
	$var(BigDecimal, lhs, this);
	{
		bool lhsIsZero = lhs->signum() == 0;
		bool augendIsZero = $nc(augend)->signum() == 0;
		if (lhsIsZero || augendIsZero) {
			int32_t var$0 = lhs->scale();
			int32_t preferredScale = $Math::max(var$0, augend->scale());
			$var(BigDecimal, result, nullptr);
			if (lhsIsZero && augendIsZero) {
				return zeroValueOf(preferredScale);
			}
			$assign(result, lhsIsZero ? doRound(augend, mc) : doRound(lhs, mc));
			if ($nc(result)->scale() == preferredScale) {
				return result;
			} else if (result->scale() > preferredScale) {
				return stripZerosToMatchScale(result->intVal, result->intCompact, result->scale$, preferredScale);
			} else {
				int32_t precisionDiff = $nc(mc)->precision - result->precision();
				int32_t scaleDiff = preferredScale - result->scale();
				if (precisionDiff >= scaleDiff) {
					return result->setScale(preferredScale);
				} else {
					return result->setScale(result->scale() + precisionDiff);
				}
			}
		}
	}
	int64_t padding = (int64_t)lhs->scale$ - $nc(augend)->scale$;
	if (padding != 0) {
		$var($BigDecimalArray, arg, preAlign(lhs, augend, padding, mc));
		matchScale(arg);
		$assign(lhs, $nc(arg)->get(0));
		$assign(augend, arg->get(1));
	}
	return doRound($($nc($(lhs->inflated()))->add($(augend->inflated()))), lhs->scale$, mc);
}

$BigDecimalArray* BigDecimal::preAlign(BigDecimal* lhs, BigDecimal* augend, int64_t padding, $MathContext* mc) {
	$useLocalCurrentObjectStackCache();
	if (!BigDecimal::$assertionsDisabled && !(padding != 0)) {
		$throwNew($AssertionError);
	}
	$var(BigDecimal, big, nullptr);
	$var(BigDecimal, small, nullptr);
	if (padding < 0) {
		$assign(big, lhs);
		$assign(small, augend);
	} else {
		$assign(big, augend);
		$assign(small, lhs);
	}
	int64_t estResultUlpScale = (int64_t)$nc(big)->scale$ - big->precision() + $nc(mc)->precision;
	int64_t smallHighDigitPos = (int64_t)$nc(small)->scale$ - small->precision() + 1;
	if (smallHighDigitPos > big->scale$ + 2 && smallHighDigitPos > estResultUlpScale + 2) {
		int64_t var$0 = (int64_t)small->signum();
		$assign(small, BigDecimal::valueOf(var$0, this->checkScale($Math::max((int64_t)big->scale$, estResultUlpScale) + 3)));
	}
	$var($BigDecimalArray, result, $new($BigDecimalArray, {
		big,
		small
	}));
	return result;
}

BigDecimal* BigDecimal::subtract(BigDecimal* subtrahend) {
	$useLocalCurrentObjectStackCache();
	if (this->intCompact != BigDecimal::INFLATED) {
		if ($nc(subtrahend)->intCompact != BigDecimal::INFLATED) {
			return add(this->intCompact, this->scale$, -subtrahend->intCompact, subtrahend->scale$);
		} else {
			return add(this->intCompact, this->scale$, $($nc(subtrahend->intVal)->negate()), subtrahend->scale$);
		}
	} else if ($nc(subtrahend)->intCompact != BigDecimal::INFLATED) {
		return add(-subtrahend->intCompact, subtrahend->scale$, this->intVal, this->scale$);
	} else {
		return add(this->intVal, this->scale$, $($nc(subtrahend->intVal)->negate()), subtrahend->scale$);
	}
}

BigDecimal* BigDecimal::subtract(BigDecimal* subtrahend, $MathContext* mc) {
	if ($nc(mc)->precision == 0) {
		return subtract(subtrahend);
	}
	return add($($nc(subtrahend)->negate()), mc);
}

BigDecimal* BigDecimal::multiply(BigDecimal* multiplicand) {
	int32_t productScale = checkScale((int64_t)this->scale$ + $nc(multiplicand)->scale$);
	if (this->intCompact != BigDecimal::INFLATED) {
		if ($nc(multiplicand)->intCompact != BigDecimal::INFLATED) {
			return multiply(this->intCompact, multiplicand->intCompact, productScale);
		} else {
			return multiply(this->intCompact, multiplicand->intVal, productScale);
		}
	} else if ($nc(multiplicand)->intCompact != BigDecimal::INFLATED) {
		return multiply(multiplicand->intCompact, this->intVal, productScale);
	} else {
		return multiply(this->intVal, multiplicand->intVal, productScale);
	}
}

BigDecimal* BigDecimal::multiply(BigDecimal* multiplicand, $MathContext* mc) {
	if ($nc(mc)->precision == 0) {
		return multiply(multiplicand);
	}
	int32_t productScale = checkScale((int64_t)this->scale$ + $nc(multiplicand)->scale$);
	if (this->intCompact != BigDecimal::INFLATED) {
		if ($nc(multiplicand)->intCompact != BigDecimal::INFLATED) {
			return multiplyAndRound(this->intCompact, multiplicand->intCompact, productScale, mc);
		} else {
			return multiplyAndRound(this->intCompact, multiplicand->intVal, productScale, mc);
		}
	} else if ($nc(multiplicand)->intCompact != BigDecimal::INFLATED) {
		return multiplyAndRound(multiplicand->intCompact, this->intVal, productScale, mc);
	} else {
		return multiplyAndRound(this->intVal, multiplicand->intVal, productScale, mc);
	}
}

BigDecimal* BigDecimal::divide(BigDecimal* divisor, int32_t scale, int32_t roundingMode) {
	if (roundingMode < BigDecimal::ROUND_UP || roundingMode > BigDecimal::ROUND_UNNECESSARY) {
		$throwNew($IllegalArgumentException, "Invalid rounding mode"_s);
	}
	if (this->intCompact != BigDecimal::INFLATED) {
		if ($nc(divisor)->intCompact != BigDecimal::INFLATED) {
			return divide(this->intCompact, this->scale$, divisor->intCompact, divisor->scale$, scale, roundingMode);
		} else {
			return divide(this->intCompact, this->scale$, divisor->intVal, divisor->scale$, scale, roundingMode);
		}
	} else if ($nc(divisor)->intCompact != BigDecimal::INFLATED) {
		return divide(this->intVal, this->scale$, divisor->intCompact, divisor->scale$, scale, roundingMode);
	} else {
		return divide(this->intVal, this->scale$, divisor->intVal, divisor->scale$, scale, roundingMode);
	}
}

BigDecimal* BigDecimal::divide(BigDecimal* divisor, int32_t scale, $RoundingMode* roundingMode) {
	return divide(divisor, scale, $nc(roundingMode)->oldMode);
}

BigDecimal* BigDecimal::divide(BigDecimal* divisor, int32_t roundingMode) {
	return this->divide(divisor, this->scale$, roundingMode);
}

BigDecimal* BigDecimal::divide(BigDecimal* divisor, $RoundingMode* roundingMode) {
	return this->divide(divisor, this->scale$, $nc(roundingMode)->oldMode);
}

BigDecimal* BigDecimal::divide(BigDecimal* divisor) {
	$useLocalCurrentObjectStackCache();
	if ($nc(divisor)->signum() == 0) {
		if (this->signum() == 0) {
			$throwNew($ArithmeticException, "Division undefined"_s);
		}
		$throwNew($ArithmeticException, "Division by zero"_s);
	}
	int32_t preferredScale = saturateLong((int64_t)this->scale$ - $nc(divisor)->scale$);
	if (this->signum() == 0) {
		return zeroValueOf(preferredScale);
	} else {
		int32_t var$0 = this->precision();
		$init($RoundingMode);
		$var($MathContext, mc, $new($MathContext, (int32_t)$Math::min(var$0 + $cast(int64_t, $Math::ceil(10.0 * $nc(divisor)->precision() / 3.0)), (int64_t)$Integer::MAX_VALUE), $RoundingMode::UNNECESSARY));
		$var(BigDecimal, quotient, nullptr);
		try {
			$assign(quotient, this->divide(divisor, mc));
		} catch ($ArithmeticException& e) {
			$throwNew($ArithmeticException, "Non-terminating decimal expansion; no exact representable decimal result."_s);
		}
		int32_t quotientScale = $nc(quotient)->scale();
		if (preferredScale > quotientScale) {
			return quotient->setScale(preferredScale, BigDecimal::ROUND_UNNECESSARY);
		}
		return quotient;
	}
}

BigDecimal* BigDecimal::divide(BigDecimal* divisor, $MathContext* mc) {
	int32_t mcp = $nc(mc)->precision;
	if (mcp == 0) {
		return divide(divisor);
	}
	$var(BigDecimal, dividend, this);
	int64_t preferredScale = (int64_t)dividend->scale$ - $nc(divisor)->scale$;
	if (divisor->signum() == 0) {
		if (dividend->signum() == 0) {
			$throwNew($ArithmeticException, "Division undefined"_s);
		}
		$throwNew($ArithmeticException, "Division by zero"_s);
	}
	if (dividend->signum() == 0) {
		return zeroValueOf(saturateLong(preferredScale));
	}
	int32_t xscale = dividend->precision();
	int32_t yscale = divisor->precision();
	if (dividend->intCompact != BigDecimal::INFLATED) {
		if (divisor->intCompact != BigDecimal::INFLATED) {
			return divide(dividend->intCompact, xscale, divisor->intCompact, yscale, preferredScale, mc);
		} else {
			return divide(dividend->intCompact, xscale, divisor->intVal, yscale, preferredScale, mc);
		}
	} else if (divisor->intCompact != BigDecimal::INFLATED) {
		return divide(dividend->intVal, xscale, divisor->intCompact, yscale, preferredScale, mc);
	} else {
		return divide(dividend->intVal, xscale, divisor->intVal, yscale, preferredScale, mc);
	}
}

BigDecimal* BigDecimal::divideToIntegralValue(BigDecimal* divisor) {
	$useLocalCurrentObjectStackCache();
	int32_t preferredScale = saturateLong((int64_t)this->scale$ - $nc(divisor)->scale$);
	if (this->compareMagnitude(divisor) < 0) {
		return zeroValueOf(preferredScale);
	}
	bool var$0 = this->signum() == 0;
	if (var$0 && $nc(divisor)->signum() != 0) {
		return this->setScale(preferredScale, BigDecimal::ROUND_UNNECESSARY);
	}
	int32_t var$2 = this->precision();
	int64_t var$1 = var$2 + $cast(int64_t, $Math::ceil(10.0 * $nc(divisor)->precision() / 3.0));
	int64_t var$4 = (int64_t)this->scale();
	int64_t var$3 = $Math::abs(var$4 - $nc(divisor)->scale());
	int32_t maxDigits = (int32_t)$Math::min(var$1 + var$3 + 2, (int64_t)$Integer::MAX_VALUE);
	$init($RoundingMode);
	$var(BigDecimal, quotient, this->divide(divisor, $$new($MathContext, maxDigits, $RoundingMode::DOWN)));
	if ($nc(quotient)->scale$ > 0) {
		$assign(quotient, quotient->setScale(0, $RoundingMode::DOWN));
		$assign(quotient, stripZerosToMatchScale($nc(quotient)->intVal, quotient->intCompact, quotient->scale$, preferredScale));
	}
	if ($nc(quotient)->scale$ < preferredScale) {
		$assign(quotient, quotient->setScale(preferredScale, BigDecimal::ROUND_UNNECESSARY));
	}
	return quotient;
}

BigDecimal* BigDecimal::divideToIntegralValue(BigDecimal* divisor, $MathContext* mc) {
	$useLocalCurrentObjectStackCache();
	if ($nc(mc)->precision == 0 || (this->compareMagnitude(divisor) < 0)) {
		return divideToIntegralValue(divisor);
	}
	int32_t preferredScale = saturateLong((int64_t)this->scale$ - $nc(divisor)->scale$);
	$init($RoundingMode);
	$var(BigDecimal, result, this->divide(divisor, $$new($MathContext, $nc(mc)->precision, $RoundingMode::DOWN)));
	if ($nc(result)->scale() < 0) {
		$var(BigDecimal, product, result->multiply(divisor));
		if ($nc($(this->subtract(product)))->compareMagnitude(divisor) >= 0) {
			$throwNew($ArithmeticException, "Division impossible"_s);
		}
	} else if (result->scale() > 0) {
		$assign(result, result->setScale(0, $RoundingMode::DOWN));
	}
	int32_t precisionDiff = 0;
	bool var$0 = (preferredScale > $nc(result)->scale());
	if (var$0 && (precisionDiff = $nc(mc)->precision - result->precision()) > 0) {
		int32_t var$1 = result->scale();
		return result->setScale(var$1 + $Math::min(precisionDiff, preferredScale - result->scale$));
	} else {
		return stripZerosToMatchScale(result->intVal, result->intCompact, result->scale$, preferredScale);
	}
}

BigDecimal* BigDecimal::remainder(BigDecimal* divisor) {
	$var($BigDecimalArray, divrem, this->divideAndRemainder(divisor));
	return $nc(divrem)->get(1);
}

BigDecimal* BigDecimal::remainder(BigDecimal* divisor, $MathContext* mc) {
	$var($BigDecimalArray, divrem, this->divideAndRemainder(divisor, mc));
	return $nc(divrem)->get(1);
}

$BigDecimalArray* BigDecimal::divideAndRemainder(BigDecimal* divisor) {
	$useLocalCurrentObjectStackCache();
	$var($BigDecimalArray, result, $new($BigDecimalArray, 2));
	result->set(0, $(this->divideToIntegralValue(divisor)));
	result->set(1, $(this->subtract($($nc(result->get(0))->multiply(divisor)))));
	return result;
}

$BigDecimalArray* BigDecimal::divideAndRemainder(BigDecimal* divisor, $MathContext* mc) {
	$useLocalCurrentObjectStackCache();
	if ($nc(mc)->precision == 0) {
		return divideAndRemainder(divisor);
	}
	$var($BigDecimalArray, result, $new($BigDecimalArray, 2));
	$var(BigDecimal, lhs, this);
	result->set(0, $(lhs->divideToIntegralValue(divisor, mc)));
	result->set(1, $(lhs->subtract($($nc(result->get(0))->multiply(divisor)))));
	return result;
}

BigDecimal* BigDecimal::sqrt($MathContext* mc) {
	$useLocalCurrentObjectStackCache();
	int32_t signum = this->signum();
	if (signum == 1) {
		int32_t preferredScale = this->scale() / 2;
		$var(BigDecimal, zeroWithFinalPreferredScale, valueOf(0, preferredScale));
		$var(BigDecimal, stripped, this->stripTrailingZeros());
		int32_t strippedScale = $nc(stripped)->scale();
		if (stripped->isPowerOfTen() && strippedScale % 2 == 0) {
			$var(BigDecimal, result, valueOf(1, strippedScale / 2));
			if ($nc(result)->scale() != preferredScale) {
				$assign(result, result->add(zeroWithFinalPreferredScale, mc));
			}
			return result;
		}
		int32_t scaleAdjust = 0;
		int32_t var$0 = stripped->scale();
		int32_t scale = var$0 - stripped->precision() + 1;
		if (scale % 2 == 0) {
			scaleAdjust = scale;
		} else {
			scaleAdjust = scale - 1;
		}
		$var(BigDecimal, working, stripped->scaleByPowerOfTen(scaleAdjust));
		bool var$1 = !BigDecimal::$assertionsDisabled;
		if (var$1) {
			bool var$2 = $nc(BigDecimal::ONE_TENTH)->compareTo(working) <= 0;
			var$1 = !(var$2 && $nc(working)->compareTo(BigDecimal::TEN) < 0);
		}
		if (var$1) {
			$throwNew($AssertionError);
		}
		$var(BigDecimal, guess, $new(BigDecimal, $Math::sqrt($nc(working)->doubleValue())));
		int32_t guessPrecision = 15;
		int32_t originalPrecision = $nc(mc)->getPrecision();
		int32_t targetPrecision = 0;
		if (originalPrecision == 0) {
			targetPrecision = stripped->precision() / 2 + 1;
		} else {
			$init($BigDecimal$1);
			switch ($nc($BigDecimal$1::$SwitchMap$java$math$RoundingMode)->get($nc(($(mc->getRoundingMode())))->ordinal())) {
			case 1:
				{}
			case 2:
				{}
			case 3:
				{
					targetPrecision = 2 * originalPrecision;
					if (targetPrecision < 0) {
						targetPrecision = $Integer::MAX_VALUE - 2;
					}
					break;
				}
			default:
				{
					targetPrecision = originalPrecision;
					break;
				}
			}
		}
		$var(BigDecimal, approx, guess);
		int32_t workingPrecision = $nc(working)->precision();
		do {
			int32_t tmpPrecision = $Math::max($Math::max(guessPrecision, targetPrecision + 2), workingPrecision);
			$init($RoundingMode);
			$var($MathContext, mcTmp, $new($MathContext, tmpPrecision, $RoundingMode::HALF_EVEN));
			$assign(approx, $nc(BigDecimal::ONE_HALF)->multiply($(approx->add($(working->divide(approx, mcTmp)), mcTmp))));
			guessPrecision *= 2;
		} while (guessPrecision < targetPrecision + 2);
		$var(BigDecimal, result, nullptr);
		$RoundingMode* targetRm = mc->getRoundingMode();
		$init($RoundingMode);
		if (targetRm == $RoundingMode::UNNECESSARY || originalPrecision == 0) {
			$RoundingMode* tmpRm = (targetRm == $RoundingMode::UNNECESSARY) ? $RoundingMode::DOWN : targetRm;
			$var($MathContext, mcTmp, $new($MathContext, targetPrecision, tmpRm));
			$assign(result, $nc($(approx->scaleByPowerOfTen(-scaleAdjust / 2)))->round(mcTmp));
			if ($nc($(this->subtract($($nc(result)->square()))))->compareTo(BigDecimal::ZERO) != 0) {
				$throwNew($ArithmeticException, "Computed square root not exact."_s);
			}
		} else {
			$assign(result, $nc($(approx->scaleByPowerOfTen(-scaleAdjust / 2)))->round(mc));
			$init($BigDecimal$1);
			switch ($nc($BigDecimal$1::$SwitchMap$java$math$RoundingMode)->get($nc((targetRm))->ordinal())) {
			case 4:
				{}
			case 5:
				{
					if ($nc($($nc(result)->square()))->compareTo(this) > 0) {
						$var(BigDecimal, ulp, result->ulp());
						if (approx->compareTo(BigDecimal::ONE) == 0) {
							$assign(ulp, $nc(ulp)->multiply(BigDecimal::ONE_TENTH));
						}
						$assign(result, result->subtract(ulp));
					}
					break;
				}
			case 6:
				{}
			case 7:
				{
					if ($nc($($nc(result)->square()))->compareTo(this) < 0) {
						$assign(result, result->add($(result->ulp())));
					}
					break;
				}
			default:
				{
					break;
				}
			}
		}
		if (!BigDecimal::$assertionsDisabled && !squareRootResultAssertions(result, mc)) {
			$throwNew($AssertionError);
		}
		if ($nc(result)->scale() != preferredScale) {
			$assign(result, $nc($(result->stripTrailingZeros()))->add(zeroWithFinalPreferredScale, $$new($MathContext, originalPrecision, $RoundingMode::UNNECESSARY)));
		}
		return result;
	} else {
		$var(BigDecimal, result, nullptr);
		switch (signum) {
		case -1:
			{
				$throwNew($ArithmeticException, "Attempted square root of negative BigDecimal"_s);
			}
		case 0:
			{
				$assign(result, valueOf(0, this->scale() / 2));
				if (!BigDecimal::$assertionsDisabled && !squareRootResultAssertions(result, mc)) {
					$throwNew($AssertionError);
				}
				return result;
			}
		default:
			{
				$throwNew($AssertionError, $of("Bad value from signum"_s));
			}
		}
	}
}

BigDecimal* BigDecimal::square() {
	return this->multiply(this);
}

bool BigDecimal::isPowerOfTen() {
	$init($BigInteger);
	return $nc($BigInteger::ONE)->equals($(this->unscaledValue()));
}

bool BigDecimal::squareRootResultAssertions(BigDecimal* result, $MathContext* mc) {
	$useLocalCurrentObjectStackCache();
	if ($nc(result)->signum() == 0) {
		return squareRootZeroResultAssertions(result, mc);
	} else {
		$RoundingMode* rm = $nc(mc)->getRoundingMode();
		$var(BigDecimal, ulp, result->ulp());
		$var(BigDecimal, neighborUp, result->add(ulp));
		if (result->isPowerOfTen()) {
			$assign(ulp, $nc(ulp)->divide(BigDecimal::TEN));
		}
		$var(BigDecimal, neighborDown, result->subtract(ulp));
		bool var$0 = !BigDecimal::$assertionsDisabled;
		if (var$0) {
			bool var$1 = result->signum() == 1;
			var$0 = !(var$1 && this->signum() == 1);
		}
		if (var$0) {
			$throwNew($AssertionError, $of("Bad signum of this and/or its sqrt."_s));
		}
		$init($BigDecimal$1);
		{
			$var(BigDecimal, err, nullptr)
			$var(BigDecimal, errUp, nullptr)
			$var(BigDecimal, errDown, nullptr)
			int32_t err_comp_errUp = 0;
			int32_t err_comp_errDown = 0;
			switch ($nc($BigDecimal$1::$SwitchMap$java$math$RoundingMode)->get($nc((rm))->ordinal())) {
			case 4:
				{}
			case 5:
				{
					bool var$2 = !BigDecimal::$assertionsDisabled;
					if (var$2) {
						bool var$3 = $nc($(result->square()))->compareTo(this) <= 0;
						var$2 = !(var$3 && $nc($($nc(neighborUp)->square()))->compareTo(this) > 0);
					}
					if (var$2) {
						$throwNew($AssertionError, $of($$str({"Square of result out for bounds rounding "_s, rm})));
					}
					return true;
				}
			case 6:
				{}
			case 7:
				{
					bool var$4 = !BigDecimal::$assertionsDisabled;
					if (var$4) {
						bool var$5 = $nc($(result->square()))->compareTo(this) >= 0;
						var$4 = !(var$5 && $nc($($nc(neighborDown)->square()))->compareTo(this) < 0);
					}
					if (var$4) {
						$throwNew($AssertionError, $of($$str({"Square of result out for bounds rounding "_s, rm})));
					}
					return true;
				}
			case 2:
				{}
			case 3:
				{}
			case 1:
				{
					$assign(err, $nc($($nc($(result->square()))->subtract(this)))->abs());
					$assign(errUp, $nc($($nc(neighborUp)->square()))->subtract(this));
					$assign(errDown, this->subtract($($nc(neighborDown)->square())));
					err_comp_errUp = $nc(err)->compareTo(errUp);
					err_comp_errDown = err->compareTo(errDown);
					bool var$6 = !BigDecimal::$assertionsDisabled;
					if (var$6) {
						bool var$7 = $nc(errUp)->signum() == 1;
						var$6 = !(var$7 && $nc(errDown)->signum() == 1);
					}
					if (var$6) {
						$throwNew($AssertionError, $of("Errors of neighbors squared don\'t have correct signs"_s));
					}
					if (!BigDecimal::$assertionsDisabled && !(err_comp_errUp <= 0 || err_comp_errDown <= 0)) {
						$throwNew($AssertionError, $of($$str({"Computed square root has larger error than neighbors for "_s, rm})));
					}
					if (!BigDecimal::$assertionsDisabled && !(((err_comp_errUp == 0) ? err_comp_errDown < 0 : true) && ((err_comp_errDown == 0) ? err_comp_errUp < 0 : true))) {
						$throwNew($AssertionError, $of("Incorrect error relationships"_s));
					}
					return true;
				}
			default:
				{
					return true;
				}
			}
		}
	}
}

bool BigDecimal::squareRootZeroResultAssertions(BigDecimal* result, $MathContext* mc) {
	return this->compareTo(BigDecimal::ZERO) == 0;
}

BigDecimal* BigDecimal::pow(int32_t n) {
	$useLocalCurrentObjectStackCache();
	if (n < 0 || n > 0x3B9AC9FF) {
		$throwNew($ArithmeticException, "Invalid operation"_s);
	}
	int32_t newScale = checkScale((int64_t)this->scale$ * n);
	return $new(BigDecimal, $($nc($(this->inflated()))->pow(n)), newScale);
}

BigDecimal* BigDecimal::pow(int32_t n, $MathContext* mc) {
	$useLocalCurrentObjectStackCache();
	if ($nc(mc)->precision == 0) {
		return pow(n);
	}
	if (n < (int32_t)0xC4653601 || n > 0x3B9AC9FF) {
		$throwNew($ArithmeticException, "Invalid operation"_s);
	}
	if (n == 0) {
		return BigDecimal::ONE;
	}
	$var(BigDecimal, lhs, this);
	$var($MathContext, workmc, mc);
	int32_t mag = $Math::abs(n);
	if ($nc(mc)->precision > 0) {
		int32_t elength = longDigitLength(mag);
		if (elength > mc->precision) {
			$throwNew($ArithmeticException, "Invalid operation"_s);
		}
		$assign(workmc, $new($MathContext, mc->precision + elength + 1, mc->roundingMode));
	}
	$var(BigDecimal, acc, BigDecimal::ONE);
	bool seenbit = false;
	for (int32_t i = 1;; ++i) {
		mag += mag;
		if (mag < 0) {
			seenbit = true;
			$assign(acc, $nc(acc)->multiply(lhs, workmc));
		}
		if (i == 31) {
			break;
		}
		if (seenbit) {
			$assign(acc, $nc(acc)->multiply(acc, workmc));
		}
	}
	if (n < 0) {
		$assign(acc, $nc(BigDecimal::ONE)->divide(acc, workmc));
	}
	return doRound(acc, mc);
}

BigDecimal* BigDecimal::abs() {
	return (signum() < 0 ? negate() : this);
}

BigDecimal* BigDecimal::abs($MathContext* mc) {
	return (signum() < 0 ? negate(mc) : plus(mc));
}

BigDecimal* BigDecimal::negate() {
	if (this->intCompact == BigDecimal::INFLATED) {
		return $new(BigDecimal, $($nc(this->intVal)->negate()), BigDecimal::INFLATED, this->scale$, this->precision$);
	} else {
		return valueOf(-this->intCompact, this->scale$, this->precision$);
	}
}

BigDecimal* BigDecimal::negate($MathContext* mc) {
	return $nc($(negate()))->plus(mc);
}

BigDecimal* BigDecimal::plus() {
	return this;
}

BigDecimal* BigDecimal::plus($MathContext* mc) {
	if ($nc(mc)->precision == 0) {
		return this;
	}
	return doRound(this, mc);
}

int32_t BigDecimal::signum() {
	return (this->intCompact != BigDecimal::INFLATED) ? $Long::signum(this->intCompact) : $nc(this->intVal)->signum();
}

int32_t BigDecimal::scale() {
	return this->scale$;
}

int32_t BigDecimal::precision() {
	int32_t result = this->precision$;
	if (result == 0) {
		int64_t s = this->intCompact;
		if (s != BigDecimal::INFLATED) {
			result = longDigitLength(s);
		} else {
			result = bigDigitLength(this->intVal);
		}
		this->precision$ = result;
	}
	return result;
}

$BigInteger* BigDecimal::unscaledValue() {
	return this->inflated();
}

BigDecimal* BigDecimal::round($MathContext* mc) {
	return plus(mc);
}

BigDecimal* BigDecimal::setScale(int32_t newScale, $RoundingMode* roundingMode) {
	return setScale(newScale, $nc(roundingMode)->oldMode);
}

BigDecimal* BigDecimal::setScale(int32_t newScale, int32_t roundingMode) {
	$useLocalCurrentObjectStackCache();
	if (roundingMode < BigDecimal::ROUND_UP || roundingMode > BigDecimal::ROUND_UNNECESSARY) {
		$throwNew($IllegalArgumentException, "Invalid rounding mode"_s);
	}
	int32_t oldScale = this->scale$;
	if (newScale == oldScale) {
		return this;
	}
	if (this->signum() == 0) {
		return zeroValueOf(newScale);
	}
	if (this->intCompact != BigDecimal::INFLATED) {
		int64_t rs = this->intCompact;
		if (newScale > oldScale) {
			int32_t raise = checkScale((int64_t)newScale - oldScale);
			if ((rs = longMultiplyPowerTen(rs, raise)) != BigDecimal::INFLATED) {
				return valueOf(rs, newScale);
			}
			$var($BigInteger, rb, bigMultiplyPowerTen(raise));
			return $new(BigDecimal, rb, BigDecimal::INFLATED, newScale, (this->precision$ > 0) ? this->precision$ + raise : 0);
		} else {
			int32_t drop = checkScale((int64_t)oldScale - newScale);
			if (drop < $nc(BigDecimal::LONG_TEN_POWERS_TABLE)->length) {
				return divideAndRound(rs, $nc(BigDecimal::LONG_TEN_POWERS_TABLE)->get(drop), newScale, roundingMode, newScale);
			} else {
				$var($BigInteger, var$0, this->inflated());
				return divideAndRound(var$0, $(bigTenToThe(drop)), newScale, roundingMode, newScale);
			}
		}
	} else if (newScale > oldScale) {
		int32_t raise = checkScale((int64_t)newScale - oldScale);
		$var($BigInteger, rb, bigMultiplyPowerTen(this->intVal, raise));
		return $new(BigDecimal, rb, BigDecimal::INFLATED, newScale, (this->precision$ > 0) ? this->precision$ + raise : 0);
	} else {
		int32_t drop = checkScale((int64_t)oldScale - newScale);
		if (drop < $nc(BigDecimal::LONG_TEN_POWERS_TABLE)->length) {
			return divideAndRound(this->intVal, $nc(BigDecimal::LONG_TEN_POWERS_TABLE)->get(drop), newScale, roundingMode, newScale);
		} else {
			return divideAndRound(this->intVal, $(bigTenToThe(drop)), newScale, roundingMode, newScale);
		}
	}
}

BigDecimal* BigDecimal::setScale(int32_t newScale) {
	return setScale(newScale, BigDecimal::ROUND_UNNECESSARY);
}

BigDecimal* BigDecimal::movePointLeft(int32_t n) {
	if (n == 0) {
		return this;
	}
	int32_t newScale = checkScale((int64_t)this->scale$ + n);
	$var(BigDecimal, num, $new(BigDecimal, this->intVal, this->intCompact, newScale, 0));
	return num->scale$ < 0 ? num->setScale(0, BigDecimal::ROUND_UNNECESSARY) : num;
}

BigDecimal* BigDecimal::movePointRight(int32_t n) {
	if (n == 0) {
		return this;
	}
	int32_t newScale = checkScale((int64_t)this->scale$ - n);
	$var(BigDecimal, num, $new(BigDecimal, this->intVal, this->intCompact, newScale, 0));
	return num->scale$ < 0 ? num->setScale(0, BigDecimal::ROUND_UNNECESSARY) : num;
}

BigDecimal* BigDecimal::scaleByPowerOfTen(int32_t n) {
	return $new(BigDecimal, this->intVal, this->intCompact, checkScale((int64_t)this->scale$ - n), this->precision$);
}

BigDecimal* BigDecimal::stripTrailingZeros() {
	if (this->intCompact == 0 || (this->intVal != nullptr && $nc(this->intVal)->signum() == 0)) {
		return BigDecimal::ZERO;
	} else if (this->intCompact != BigDecimal::INFLATED) {
		return createAndStripZerosToMatchScale(this->intCompact, this->scale$, $Long::MIN_VALUE);
	} else {
		return createAndStripZerosToMatchScale(this->intVal, this->scale$, $Long::MIN_VALUE);
	}
}

int32_t BigDecimal::compareTo(BigDecimal* val) {
	if (this->scale$ == $nc(val)->scale$) {
		int64_t xs = this->intCompact;
		int64_t ys = val->intCompact;
		if (xs != BigDecimal::INFLATED && ys != BigDecimal::INFLATED) {
			return xs != ys ? ((xs > ys) ? 1 : -1) : 0;
		}
	}
	int32_t xsign = this->signum();
	int32_t ysign = $nc(val)->signum();
	if (xsign != ysign) {
		return (xsign > ysign) ? 1 : -1;
	}
	if (xsign == 0) {
		return 0;
	}
	int32_t cmp = compareMagnitude(val);
	return (xsign > 0) ? cmp : -cmp;
}

int32_t BigDecimal::compareMagnitude(BigDecimal* val) {
	$useLocalCurrentObjectStackCache();
	int64_t ys = $nc(val)->intCompact;
	int64_t xs = this->intCompact;
	if (xs == 0) {
		return (ys == 0) ? 0 : -1;
	}
	if (ys == 0) {
		return 1;
	}
	int64_t sdiff = (int64_t)this->scale$ - val->scale$;
	if (sdiff != 0) {
		int64_t xae = (int64_t)this->precision() - this->scale$;
		int64_t yae = (int64_t)val->precision() - val->scale$;
		if (xae < yae) {
			return -1;
		}
		if (xae > yae) {
			return 1;
		}
		if (sdiff < 0) {
			bool var$0 = sdiff > $Integer::MIN_VALUE;
			if (var$0) {
				bool var$1 = xs == BigDecimal::INFLATED;
				var$0 = (var$1 || (xs = longMultiplyPowerTen(xs, (int32_t)-sdiff)) == BigDecimal::INFLATED);
			}
			if (var$0 && ys == BigDecimal::INFLATED) {
				$var($BigInteger, rb, bigMultiplyPowerTen((int32_t)-sdiff));
				return $nc(rb)->compareMagnitude(val->intVal);
			}
		} else {
			bool var$4 = sdiff <= $Integer::MAX_VALUE;
			if (var$4) {
				bool var$5 = ys == BigDecimal::INFLATED;
				var$4 = (var$5 || (ys = longMultiplyPowerTen(ys, (int32_t)sdiff)) == BigDecimal::INFLATED);
			}
			if (var$4 && xs == BigDecimal::INFLATED) {
				$var($BigInteger, rb, val->bigMultiplyPowerTen((int32_t)sdiff));
				return $nc(this->intVal)->compareMagnitude(rb);
			}
		}
	}
	if (xs != BigDecimal::INFLATED) {
		return (ys != BigDecimal::INFLATED) ? longCompareMagnitude(xs, ys) : -1;
	} else if (ys != BigDecimal::INFLATED) {
		return 1;
	} else {
		return $nc(this->intVal)->compareMagnitude(val->intVal);
	}
}

bool BigDecimal::equals(Object$* x) {
	$useLocalCurrentObjectStackCache();
	$var(BigDecimal, xDec, nullptr);
	bool var$0 = $instanceOf(BigDecimal, x);
	if (var$0) {
		$assign(xDec, $cast(BigDecimal, x));
		var$0 = true;
	}
	if (!(var$0)) {
		return false;
	}
	if ($equals(x, this)) {
		return true;
	}
	if (this->scale$ != $nc(xDec)->scale$) {
		return false;
	}
	int64_t s = this->intCompact;
	int64_t xs = $nc(xDec)->intCompact;
	if (s != BigDecimal::INFLATED) {
		if (xs == BigDecimal::INFLATED) {
			xs = compactValFor(xDec->intVal);
		}
		return xs == s;
	} else if (xs != BigDecimal::INFLATED) {
		return xs == compactValFor(this->intVal);
	}
	return $nc($(this->inflated()))->equals($(xDec->inflated()));
}

BigDecimal* BigDecimal::min(BigDecimal* val) {
	return (compareTo(val) <= 0 ? this : val);
}

BigDecimal* BigDecimal::max(BigDecimal* val) {
	return (compareTo(val) >= 0 ? this : val);
}

int32_t BigDecimal::hashCode() {
	if (this->intCompact != BigDecimal::INFLATED) {
		int64_t val2 = (this->intCompact < 0) ? -this->intCompact : this->intCompact;
		int32_t temp = (int32_t)(((int32_t)((int64_t)((uint64_t)val2 >> 32))) * 31 + ((int64_t)(val2 & (uint64_t)(int64_t)0x00000000FFFFFFFF)));
		return 31 * ((this->intCompact < 0) ? -temp : temp) + this->scale$;
	} else {
		return 31 * $nc(this->intVal)->hashCode() + this->scale$;
	}
}

$String* BigDecimal::toString() {
	$var($String, sc, this->stringCache);
	if (sc == nullptr) {
		$set(this, stringCache, ($assign(sc, layoutChars(true))));
	}
	return sc;
}

$String* BigDecimal::toEngineeringString() {
	return layoutChars(false);
}

$String* BigDecimal::toPlainString() {
	$useLocalCurrentObjectStackCache();
	if (this->scale$ == 0) {
		if (this->intCompact != BigDecimal::INFLATED) {
			return $Long::toString(this->intCompact);
		} else {
			return $nc(this->intVal)->toString();
		}
	}
	if (this->scale$ < 0) {
		if (signum() == 0) {
			return "0"_s;
		}
		int32_t trailingZeros = checkScaleNonZero((-(int64_t)this->scale$));
		$var($StringBuilder, buf, nullptr);
		if (this->intCompact != BigDecimal::INFLATED) {
			$assign(buf, $new($StringBuilder, 20 + trailingZeros));
			buf->append(this->intCompact);
		} else {
			$var($String, str, $nc(this->intVal)->toString());
			$assign(buf, $new($StringBuilder, $nc(str)->length() + trailingZeros));
			buf->append(str);
		}
		for (int32_t i = 0; i < trailingZeros; ++i) {
			$nc(buf)->append(u'0');
		}
		return $nc(buf)->toString();
	}
	$var($String, str, nullptr);
	if (this->intCompact != BigDecimal::INFLATED) {
		$assign(str, $Long::toString($Math::abs(this->intCompact)));
	} else {
		$assign(str, $nc($($nc(this->intVal)->abs()))->toString());
	}
	return getValueString(signum(), str, this->scale$);
}

$String* BigDecimal::getValueString(int32_t signum, $String* intString, int32_t scale) {
	$var($StringBuilder, buf, nullptr);
	int32_t insertionPoint = $nc(intString)->length() - scale;
	if (insertionPoint == 0) {
		return $str({(signum < 0 ? "-0."_s : "0."_s), intString});
	} else if (insertionPoint > 0) {
		$assign(buf, $new($StringBuilder, intString));
		buf->insert(insertionPoint, u'.');
		if (signum < 0) {
			buf->insert(0, u'-');
		}
	} else {
		$assign(buf, $new($StringBuilder, 3 - insertionPoint + intString->length()));
		buf->append(signum < 0 ? "-0."_s : "0."_s);
		for (int32_t i = 0; i < -insertionPoint; ++i) {
			buf->append(u'0');
		}
		buf->append(intString);
	}
	return $nc(buf)->toString();
}

$BigInteger* BigDecimal::toBigInteger() {
	return $nc($(this->setScale(0, BigDecimal::ROUND_DOWN)))->inflated();
}

$BigInteger* BigDecimal::toBigIntegerExact() {
	return $nc($(this->setScale(0, BigDecimal::ROUND_UNNECESSARY)))->inflated();
}

int64_t BigDecimal::longValue() {
	if (this->intCompact != BigDecimal::INFLATED && this->scale$ == 0) {
		return this->intCompact;
	} else {
		bool var$1 = this->signum() == 0;
		if (var$1 || fractionOnly() || this->scale$ <= -64) {
			return 0;
		} else {
			return $nc($(toBigInteger()))->longValue();
		}
	}
}

bool BigDecimal::fractionOnly() {
	if (!BigDecimal::$assertionsDisabled && !(this->signum() != 0)) {
		$throwNew($AssertionError);
	}
	return (this->precision() - this->scale$) <= 0;
}

int64_t BigDecimal::longValueExact() {
	$useLocalCurrentObjectStackCache();
	if (this->intCompact != BigDecimal::INFLATED && this->scale$ == 0) {
		return this->intCompact;
	}
	if (this->signum() == 0) {
		return 0;
	}
	if (fractionOnly()) {
		$throwNew($ArithmeticException, "Rounding necessary"_s);
	}
	if ((precision() - this->scale$) > 19) {
		$throwNew($ArithmeticException, "Overflow"_s);
	}
	$var(BigDecimal, num, this->setScale(0, BigDecimal::ROUND_UNNECESSARY));
	if ($nc(num)->precision() >= 19) {
		$BigDecimal$LongOverflow::check(num);
	}
	return $nc($($nc(num)->inflated()))->longValue();
}

int32_t BigDecimal::intValue() {
	return (this->intCompact != BigDecimal::INFLATED && this->scale$ == 0) ? (int32_t)this->intCompact : (int32_t)longValue();
}

int32_t BigDecimal::intValueExact() {
	int64_t num = 0;
	num = this->longValueExact();
	if ((int32_t)num != num) {
		$throwNew($ArithmeticException, "Overflow"_s);
	}
	return (int32_t)num;
}

int16_t BigDecimal::shortValueExact() {
	int64_t num = 0;
	num = this->longValueExact();
	if ((int16_t)num != num) {
		$throwNew($ArithmeticException, "Overflow"_s);
	}
	return (int16_t)num;
}

int8_t BigDecimal::byteValueExact() {
	int64_t num = 0;
	num = this->longValueExact();
	if ((int8_t)num != num) {
		$throwNew($ArithmeticException, "Overflow"_s);
	}
	return (int8_t)num;
}

float BigDecimal::floatValue() {
	if (this->intCompact != BigDecimal::INFLATED) {
		if (this->scale$ == 0) {
			return (float)this->intCompact;
		} else if ($Math::abs(this->intCompact) < (int64_t)1 << 22) {
			if (this->scale$ > 0 && this->scale$ < $nc(BigDecimal::FLOAT_10_POW)->length) {
				return (float)this->intCompact / $nc(BigDecimal::FLOAT_10_POW)->get(this->scale$);
			} else if (this->scale$ < 0 && this->scale$ > -$nc(BigDecimal::FLOAT_10_POW)->length) {
				return (float)this->intCompact * $nc(BigDecimal::FLOAT_10_POW)->get(-this->scale$);
			}
		}
	}
	return $Float::parseFloat($(this->toString()));
}

double BigDecimal::doubleValue() {
	if (this->intCompact != BigDecimal::INFLATED) {
		if (this->scale$ == 0) {
			return (double)this->intCompact;
		} else if ($Math::abs(this->intCompact) < (int64_t)1 << 52) {
			if (this->scale$ > 0 && this->scale$ < $nc(BigDecimal::DOUBLE_10_POW)->length) {
				return (double)this->intCompact / $nc(BigDecimal::DOUBLE_10_POW)->get(this->scale$);
			} else if (this->scale$ < 0 && this->scale$ > -$nc(BigDecimal::DOUBLE_10_POW)->length) {
				return (double)this->intCompact * $nc(BigDecimal::DOUBLE_10_POW)->get(-this->scale$);
			}
		}
	}
	return $Double::parseDouble($(this->toString()));
}

BigDecimal* BigDecimal::ulp() {
	return BigDecimal::valueOf((int64_t)1, this->scale(), 1);
}

$String* BigDecimal::layoutChars(bool sci) {
	$useLocalCurrentObjectStackCache();
	if (this->scale$ == 0) {
		return (this->intCompact != BigDecimal::INFLATED) ? $Long::toString(this->intCompact) : $nc(this->intVal)->toString();
	}
	if (this->scale$ == 2 && this->intCompact >= 0 && this->intCompact < $Integer::MAX_VALUE) {
		int32_t lowInt = (int32_t)this->intCompact % 100;
		int32_t highInt = (int32_t)this->intCompact / 100;
		$init($BigDecimal$StringBuilderHelper);
		return ($str({$($Integer::toString(highInt)), $$str(u'.'), $$str($nc($BigDecimal$StringBuilderHelper::DIGIT_TENS)->get(lowInt)), $$str($nc($BigDecimal$StringBuilderHelper::DIGIT_ONES)->get(lowInt))}));
	}
	$var($BigDecimal$StringBuilderHelper, sbHelper, $new($BigDecimal$StringBuilderHelper));
	$var($chars, coeff, nullptr);
	int32_t offset = 0;
	if (this->intCompact != BigDecimal::INFLATED) {
		offset = sbHelper->putIntCompact($Math::abs(this->intCompact));
		$assign(coeff, sbHelper->getCompactCharArray());
	} else {
		offset = 0;
		$assign(coeff, $nc($($nc($($nc(this->intVal)->abs()))->toString()))->toCharArray());
	}
	$var($StringBuilder, buf, sbHelper->getStringBuilder());
	if (signum() < 0) {
		$nc(buf)->append(u'-');
	}
	int32_t coeffLen = $nc(coeff)->length - offset;
	int64_t adjusted = -(int64_t)this->scale$ + (coeffLen - 1);
	if ((this->scale$ >= 0) && (adjusted >= -6)) {
		int32_t pad = this->scale$ - coeffLen;
		if (pad >= 0) {
			$nc(buf)->append(u'0');
			buf->append(u'.');
			for (; pad > 0; --pad) {
				buf->append(u'0');
			}
			buf->append(coeff, offset, coeffLen);
		} else {
			$nc(buf)->append(coeff, offset, -pad);
			buf->append(u'.');
			buf->append(coeff, -pad + offset, this->scale$);
		}
	} else {
		if (sci) {
			$nc(buf)->append(coeff->get(offset));
			if (coeffLen > 1) {
				buf->append(u'.');
				buf->append(coeff, offset + 1, coeffLen - 1);
			}
		} else {
			int32_t sig = (int32_t)(adjusted % 3);
			if (sig < 0) {
				sig += 3;
			}
			adjusted -= sig;
			++sig;
			if (signum() == 0) {
				switch (sig) {
				case 1:
					{
						$nc(buf)->append(u'0');
						break;
					}
				case 2:
					{
						$nc(buf)->append("0.00"_s);
						adjusted += 3;
						break;
					}
				case 3:
					{
						$nc(buf)->append("0.0"_s);
						adjusted += 3;
						break;
					}
				default:
					{
						$throwNew($AssertionError, $of($$str({"Unexpected sig value "_s, $$str(sig)})));
					}
				}
			} else if (sig >= coeffLen) {
				$nc(buf)->append(coeff, offset, coeffLen);
				for (int32_t i = sig - coeffLen; i > 0; --i) {
					buf->append(u'0');
				}
			} else {
				$nc(buf)->append(coeff, offset, sig);
				buf->append(u'.');
				buf->append(coeff, offset + sig, coeffLen - sig);
			}
		}
		if (adjusted != 0) {
			$nc(buf)->append(u'E');
			if (adjusted > 0) {
				buf->append(u'+');
			}
			buf->append(adjusted);
		}
	}
	return $nc(buf)->toString();
}

$BigInteger* BigDecimal::bigTenToThe(int32_t n) {
	$init(BigDecimal);
	if (n < 0) {
		$init($BigInteger);
		return $BigInteger::ZERO;
	}
	if (n < BigDecimal::BIG_TEN_POWERS_TABLE_MAX) {
		$var($BigIntegerArray, pows, BigDecimal::BIG_TEN_POWERS_TABLE);
		if (n < $nc(pows)->length) {
			return pows->get(n);
		} else {
			return expandBigIntegerTenPowers(n);
		}
	}
	$init($BigInteger);
	return $nc($BigInteger::TEN)->pow(n);
}

$BigInteger* BigDecimal::expandBigIntegerTenPowers(int32_t n) {
	$init(BigDecimal);
	$useLocalCurrentObjectStackCache();
	$synchronized(BigDecimal::class$) {
		$var($BigIntegerArray, pows, BigDecimal::BIG_TEN_POWERS_TABLE);
		int32_t curLen = $nc(pows)->length;
		if (curLen <= n) {
			int32_t newLen = curLen << 1;
			while (newLen <= n) {
				newLen <<= 1;
			}
			$assign(pows, $fcast($BigIntegerArray, $Arrays::copyOf(pows, newLen)));
			for (int32_t i = curLen; i < newLen; ++i) {
				$init($BigInteger);
				pows->set(i, $($nc(pows->get(i - 1))->multiply($BigInteger::TEN)));
			}
			$assignStatic(BigDecimal::BIG_TEN_POWERS_TABLE, pows);
		}
		return pows->get(n);
	}
}

int64_t BigDecimal::longMultiplyPowerTen(int64_t val, int32_t n) {
	$init(BigDecimal);
	$useLocalCurrentObjectStackCache();
	if (val == 0 || n <= 0) {
		return val;
	}
	$var($longs, tab, BigDecimal::LONG_TEN_POWERS_TABLE);
	$var($longs, bounds, BigDecimal::THRESHOLDS_TABLE);
	if (n < $nc(tab)->length && n < $nc(bounds)->length) {
		int64_t tenpower = tab->get(n);
		if (val == 1) {
			return tenpower;
		}
		if ($Math::abs(val) <= bounds->get(n)) {
			return val * tenpower;
		}
	}
	return BigDecimal::INFLATED;
}

$BigInteger* BigDecimal::bigMultiplyPowerTen(int32_t n) {
	$useLocalCurrentObjectStackCache();
	if (n <= 0) {
		return this->inflated();
	}
	if (this->intCompact != BigDecimal::INFLATED) {
		return $nc($(bigTenToThe(n)))->multiply(this->intCompact);
	} else {
		return $nc(this->intVal)->multiply($(bigTenToThe(n)));
	}
}

$BigInteger* BigDecimal::inflated() {
	if (this->intVal == nullptr) {
		return $BigInteger::valueOf(this->intCompact);
	}
	return this->intVal;
}

void BigDecimal::matchScale($BigDecimalArray* val) {
	$init(BigDecimal);
	$useLocalCurrentObjectStackCache();
	if ($nc($nc(val)->get(0))->scale$ < $nc(val->get(1))->scale$) {
		val->set(0, $($nc(val->get(0))->setScale($nc(val->get(1))->scale$, BigDecimal::ROUND_UNNECESSARY)));
	} else if ($nc(val->get(1))->scale$ < $nc(val->get(0))->scale$) {
		val->set(1, $($nc(val->get(1))->setScale($nc(val->get(0))->scale$, BigDecimal::ROUND_UNNECESSARY)));
	}
}

void BigDecimal::readObject($ObjectInputStream* s) {
	$nc(s)->defaultReadObject();
	if (this->intVal == nullptr) {
		$var($String, message, "BigDecimal: null intVal in stream"_s);
		$throwNew($StreamCorruptedException, message);
	}
	$BigDecimal$UnsafeHolder::setIntCompact(this, compactValFor(this->intVal));
}

void BigDecimal::writeObject($ObjectOutputStream* s) {
	if (this->intVal == nullptr) {
		$BigDecimal$UnsafeHolder::setIntValVolatile(this, $($BigInteger::valueOf(this->intCompact)));
	}
	$nc(s)->defaultWriteObject();
}

int32_t BigDecimal::longDigitLength(int64_t x) {
	$init(BigDecimal);
	if (!BigDecimal::$assertionsDisabled && !(x != BigDecimal::INFLATED)) {
		$throwNew($AssertionError);
	}
	if (x < 0) {
		x = -x;
	}
	if (x < 10) {
		return 1;
	}
	int32_t r = (int32_t)((uint32_t)((64 - $Long::numberOfLeadingZeros(x) + 1) * 1233) >> 12);
	$var($longs, tab, BigDecimal::LONG_TEN_POWERS_TABLE);
	return (r >= $nc(tab)->length || x < $nc(tab)->get(r)) ? r : r + 1;
}

int32_t BigDecimal::bigDigitLength($BigInteger* b) {
	$init(BigDecimal);
	if ($nc(b)->signum$ == 0) {
		return 1;
	}
	int32_t r = (int32_t)((int64_t)((uint64_t)(((int64_t)$nc(b)->bitLength() + 1) * 0x268826A1) >> 31));
	return b->compareMagnitude($(bigTenToThe(r))) < 0 ? r : r + 1;
}

int32_t BigDecimal::checkScale(int64_t val) {
	int32_t asInt = (int32_t)val;
	if (asInt != val) {
		asInt = val > $Integer::MAX_VALUE ? $Integer::MAX_VALUE : $Integer::MIN_VALUE;
		$var($BigInteger, b, nullptr);
		bool var$0 = this->intCompact != 0;
		if (var$0) {
			bool var$1 = ($assign(b, this->intVal)) == nullptr;
			var$0 = (var$1 || $nc(b)->signum() != 0);
		}
		if (var$0) {
			$throwNew($ArithmeticException, asInt > 0 ? "Underflow"_s : "Overflow"_s);
		}
	}
	return asInt;
}

int64_t BigDecimal::compactValFor($BigInteger* b) {
	$init(BigDecimal);
	$var($ints, m, $nc(b)->mag);
	int32_t len = $nc(m)->length;
	if (len == 0) {
		return 0;
	}
	int32_t d = m->get(0);
	if (len > 2 || (len == 2 && d < 0)) {
		return BigDecimal::INFLATED;
	}
	int64_t u = (len == 2) ? (((int64_t)((int64_t)m->get(1) & (uint64_t)(int64_t)0x00000000FFFFFFFF)) + (((int64_t)d) << 32)) : ((int64_t)(((int64_t)d) & (uint64_t)(int64_t)0x00000000FFFFFFFF));
	return (b->signum$ < 0) ? -u : u;
}

int32_t BigDecimal::longCompareMagnitude(int64_t x, int64_t y) {
	$init(BigDecimal);
	if (x < 0) {
		x = -x;
	}
	if (y < 0) {
		y = -y;
	}
	return (x < y) ? -1 : ((x == y) ? 0 : 1);
}

int32_t BigDecimal::saturateLong(int64_t s) {
	$init(BigDecimal);
	int32_t i = (int32_t)s;
	return (s == i) ? i : (s < 0 ? $Integer::MIN_VALUE : $Integer::MAX_VALUE);
}

void BigDecimal::print($String* name, BigDecimal* bd) {
	$init(BigDecimal);
	$useLocalCurrentObjectStackCache();
	$nc($System::err)->format("%s:\tintCompact %d\tintVal %d\tscale %d\tprecision %d%n"_s, $$new($ObjectArray, {
		$of(name),
		$($of($Long::valueOf($nc(bd)->intCompact))),
		$of($nc(bd)->intVal),
		$($of($Integer::valueOf(bd->scale$))),
		$($of($Integer::valueOf(bd->precision$)))
	}));
}

BigDecimal* BigDecimal::audit() {
	$useLocalCurrentObjectStackCache();
	if (this->intCompact == BigDecimal::INFLATED) {
		if (this->intVal == nullptr) {
			print("audit"_s, this);
			$throwNew($AssertionError, $of("null intVal"_s));
		}
		if (this->precision$ > 0 && this->precision$ != bigDigitLength(this->intVal)) {
			print("audit"_s, this);
			$throwNew($AssertionError, $of("precision mismatch"_s));
		}
	} else {
		if (this->intVal != nullptr) {
			int64_t val = $nc(this->intVal)->longValue();
			if (val != this->intCompact) {
				print("audit"_s, this);
				$throwNew($AssertionError, $of($$str({"Inconsistent state, intCompact="_s, $$str(this->intCompact), "\t intVal="_s, $$str(val)})));
			}
		}
		if (this->precision$ > 0 && this->precision$ != longDigitLength(this->intCompact)) {
			print("audit"_s, this);
			$throwNew($AssertionError, $of("precision mismatch"_s));
		}
	}
	return this;
}

int32_t BigDecimal::checkScaleNonZero(int64_t val) {
	$init(BigDecimal);
	int32_t asInt = (int32_t)val;
	if (asInt != val) {
		$throwNew($ArithmeticException, asInt > 0 ? "Underflow"_s : "Overflow"_s);
	}
	return asInt;
}

int32_t BigDecimal::checkScale(int64_t intCompact, int64_t val) {
	$init(BigDecimal);
	int32_t asInt = (int32_t)val;
	if (asInt != val) {
		asInt = val > $Integer::MAX_VALUE ? $Integer::MAX_VALUE : $Integer::MIN_VALUE;
		if (intCompact != 0) {
			$throwNew($ArithmeticException, asInt > 0 ? "Underflow"_s : "Overflow"_s);
		}
	}
	return asInt;
}

int32_t BigDecimal::checkScale($BigInteger* intVal, int64_t val) {
	$init(BigDecimal);
	int32_t asInt = (int32_t)val;
	if (asInt != val) {
		asInt = val > $Integer::MAX_VALUE ? $Integer::MAX_VALUE : $Integer::MIN_VALUE;
		if ($nc(intVal)->signum() != 0) {
			$throwNew($ArithmeticException, asInt > 0 ? "Underflow"_s : "Overflow"_s);
		}
	}
	return asInt;
}

BigDecimal* BigDecimal::doRound(BigDecimal* val, $MathContext* mc) {
	$init(BigDecimal);
	int32_t mcp = $nc(mc)->precision;
	bool wasDivided = false;
	if (mcp > 0) {
		$var($BigInteger, intVal, $nc(val)->intVal);
		int64_t compactVal = val->intCompact;
		int32_t scale = val->scale$;
		int32_t prec = val->precision();
		int32_t mode = mc->roundingMode->oldMode;
		int32_t drop = 0;
		if (compactVal == BigDecimal::INFLATED) {
			drop = prec - mcp;
			while (drop > 0) {
				scale = checkScaleNonZero((int64_t)scale - drop);
				$assign(intVal, divideAndRoundByTenPow(intVal, drop, mode));
				wasDivided = true;
				compactVal = compactValFor(intVal);
				if (compactVal != BigDecimal::INFLATED) {
					prec = longDigitLength(compactVal);
					break;
				}
				prec = bigDigitLength(intVal);
				drop = prec - mcp;
			}
		}
		if (compactVal != BigDecimal::INFLATED) {
			drop = prec - mcp;
			while (drop > 0) {
				scale = checkScaleNonZero((int64_t)scale - drop);
				compactVal = divideAndRound(compactVal, $nc(BigDecimal::LONG_TEN_POWERS_TABLE)->get(drop), mc->roundingMode->oldMode);
				wasDivided = true;
				prec = longDigitLength(compactVal);
				drop = prec - mcp;
				$assign(intVal, nullptr);
			}
		}
		return wasDivided ? $new(BigDecimal, intVal, compactVal, scale, prec) : val;
	}
	return val;
}

BigDecimal* BigDecimal::doRound(int64_t compactVal, int32_t scale, $MathContext* mc) {
	$init(BigDecimal);
	int32_t mcp = $nc(mc)->precision;
	if (mcp > 0 && mcp < 19) {
		int32_t prec = longDigitLength(compactVal);
		int32_t drop = prec - mcp;
		while (drop > 0) {
			scale = checkScaleNonZero((int64_t)scale - drop);
			compactVal = divideAndRound(compactVal, $nc(BigDecimal::LONG_TEN_POWERS_TABLE)->get(drop), mc->roundingMode->oldMode);
			prec = longDigitLength(compactVal);
			drop = prec - mcp;
		}
		return valueOf(compactVal, scale, prec);
	}
	return valueOf(compactVal, scale);
}

BigDecimal* BigDecimal::doRound($BigInteger* intVal$renamed, int32_t scale, $MathContext* mc) {
	$init(BigDecimal);
	$var($BigInteger, intVal, intVal$renamed);
	int32_t mcp = $nc(mc)->precision;
	int32_t prec = 0;
	if (mcp > 0) {
		int64_t compactVal = compactValFor(intVal);
		int32_t mode = mc->roundingMode->oldMode;
		int32_t drop = 0;
		if (compactVal == BigDecimal::INFLATED) {
			prec = bigDigitLength(intVal);
			drop = prec - mcp;
			while (drop > 0) {
				scale = checkScaleNonZero((int64_t)scale - drop);
				$assign(intVal, divideAndRoundByTenPow(intVal, drop, mode));
				compactVal = compactValFor(intVal);
				if (compactVal != BigDecimal::INFLATED) {
					break;
				}
				prec = bigDigitLength(intVal);
				drop = prec - mcp;
			}
		}
		if (compactVal != BigDecimal::INFLATED) {
			prec = longDigitLength(compactVal);
			drop = prec - mcp;
			while (drop > 0) {
				scale = checkScaleNonZero((int64_t)scale - drop);
				compactVal = divideAndRound(compactVal, $nc(BigDecimal::LONG_TEN_POWERS_TABLE)->get(drop), mc->roundingMode->oldMode);
				prec = longDigitLength(compactVal);
				drop = prec - mcp;
			}
			return valueOf(compactVal, scale, prec);
		}
	}
	return $new(BigDecimal, intVal, BigDecimal::INFLATED, scale, prec);
}

$BigInteger* BigDecimal::divideAndRoundByTenPow($BigInteger* intVal$renamed, int32_t tenPow, int32_t roundingMode) {
	$init(BigDecimal);
	$useLocalCurrentObjectStackCache();
	$var($BigInteger, intVal, intVal$renamed);
	if (tenPow < $nc(BigDecimal::LONG_TEN_POWERS_TABLE)->length) {
		$assign(intVal, divideAndRound(intVal, $nc(BigDecimal::LONG_TEN_POWERS_TABLE)->get(tenPow), roundingMode));
	} else {
		$assign(intVal, divideAndRound(intVal, $(bigTenToThe(tenPow)), roundingMode));
	}
	return intVal;
}

BigDecimal* BigDecimal::divideAndRound(int64_t ldividend, int64_t ldivisor, int32_t scale, int32_t roundingMode, int32_t preferredScale) {
	$init(BigDecimal);
	int32_t qsign = 0;
	int64_t q = $div(ldividend, ldivisor);
	if (roundingMode == BigDecimal::ROUND_DOWN && scale == preferredScale) {
		return valueOf(q, scale);
	}
	int64_t r = $mod(ldividend, ldivisor);
	qsign = ((ldividend < 0) == (ldivisor < 0)) ? 1 : -1;
	if (r != 0) {
		bool increment = needIncrement(ldivisor, roundingMode, qsign, q, r);
		return valueOf((increment ? q + qsign : q), scale);
	} else if (preferredScale != scale) {
		return createAndStripZerosToMatchScale(q, scale, (int64_t)preferredScale);
	} else {
		return valueOf(q, scale);
	}
}

int64_t BigDecimal::divideAndRound(int64_t ldividend, int64_t ldivisor, int32_t roundingMode) {
	$init(BigDecimal);
	int32_t qsign = 0;
	int64_t q = $div(ldividend, ldivisor);
	if (roundingMode == BigDecimal::ROUND_DOWN) {
		return q;
	}
	int64_t r = $mod(ldividend, ldivisor);
	qsign = ((ldividend < 0) == (ldivisor < 0)) ? 1 : -1;
	if (r != 0) {
		bool increment = needIncrement(ldivisor, roundingMode, qsign, q, r);
		return increment ? q + qsign : q;
	} else {
		return q;
	}
}

bool BigDecimal::commonNeedIncrement(int32_t roundingMode, int32_t qsign, int32_t cmpFracHalf, bool oddQuot) {
	$init(BigDecimal);
	$useLocalCurrentObjectStackCache();
	switch (roundingMode) {
	case BigDecimal::ROUND_UNNECESSARY:
		{
			$throwNew($ArithmeticException, "Rounding necessary"_s);
		}
	case BigDecimal::ROUND_UP:
		{
			return true;
		}
	case BigDecimal::ROUND_DOWN:
		{
			return false;
		}
	case BigDecimal::ROUND_CEILING:
		{
			return qsign > 0;
		}
	case BigDecimal::ROUND_FLOOR:
		{
			return qsign < 0;
		}
	default:
		{
			if (!BigDecimal::$assertionsDisabled && !(roundingMode >= BigDecimal::ROUND_HALF_UP && roundingMode <= BigDecimal::ROUND_HALF_EVEN)) {
				$throwNew($AssertionError, $of($$str({"Unexpected rounding mode"_s, $($RoundingMode::valueOf(roundingMode))})));
			}
			if (cmpFracHalf < 0) {
				return false;
			} else if (cmpFracHalf > 0) {
				return true;
			} else {
				if (!BigDecimal::$assertionsDisabled && !(cmpFracHalf == 0)) {
					$throwNew($AssertionError);
				}

				bool var$0 = false;
				switch (roundingMode) {
				case BigDecimal::ROUND_HALF_DOWN:
					{
						var$0 = false;
						break;
					}
				case BigDecimal::ROUND_HALF_UP:
					{
						var$0 = true;
						break;
					}
				case BigDecimal::ROUND_HALF_EVEN:
					{
						var$0 = oddQuot;
						break;
					}
				default:
					{
						$throwNew($AssertionError, $of($$str({"Unexpected rounding mode"_s, $$str(roundingMode)})));
					}
				}
				return var$0;
			}
		}
	}
}

bool BigDecimal::needIncrement(int64_t ldivisor, int32_t roundingMode, int32_t qsign, int64_t q, int64_t r) {
	$init(BigDecimal);
	if (!BigDecimal::$assertionsDisabled && !(r != (int64_t)0)) {
		$throwNew($AssertionError);
	}
	int32_t cmpFracHalf = 0;
	if (r <= BigDecimal::HALF_LONG_MIN_VALUE || r > BigDecimal::HALF_LONG_MAX_VALUE) {
		cmpFracHalf = 1;
	} else {
		cmpFracHalf = longCompareMagnitude(2 * r, ldivisor);
	}
	return commonNeedIncrement(roundingMode, qsign, cmpFracHalf, ((int64_t)(q & (uint64_t)(int64_t)1)) != (int64_t)0);
}

$BigInteger* BigDecimal::divideAndRound($BigInteger* bdividend, int64_t ldivisor, int32_t roundingMode) {
	$init(BigDecimal);
	$useLocalCurrentObjectStackCache();
	$var($MutableBigInteger, mdividend, $new($MutableBigInteger, $nc(bdividend)->mag));
	$var($MutableBigInteger, mq, $new($MutableBigInteger));
	int64_t r = mdividend->divide(ldivisor, mq);
	bool isRemainderZero = (r == 0);
	int32_t qsign = (ldivisor < 0) ? -$nc(bdividend)->signum$ : bdividend->signum$;
	if (!isRemainderZero) {
		if (needIncrement(ldivisor, roundingMode, qsign, mq, r)) {
			mq->add($MutableBigInteger::ONE);
		}
	}
	return mq->toBigInteger(qsign);
}

BigDecimal* BigDecimal::divideAndRound($BigInteger* bdividend, int64_t ldivisor, int32_t scale, int32_t roundingMode, int32_t preferredScale) {
	$init(BigDecimal);
	$useLocalCurrentObjectStackCache();
	$var($MutableBigInteger, mdividend, $new($MutableBigInteger, $nc(bdividend)->mag));
	$var($MutableBigInteger, mq, $new($MutableBigInteger));
	int64_t r = mdividend->divide(ldivisor, mq);
	bool isRemainderZero = (r == 0);
	int32_t qsign = (ldivisor < 0) ? -$nc(bdividend)->signum$ : bdividend->signum$;
	if (!isRemainderZero) {
		if (needIncrement(ldivisor, roundingMode, qsign, mq, r)) {
			mq->add($MutableBigInteger::ONE);
		}
		return mq->toBigDecimal(qsign, scale);
	} else if (preferredScale != scale) {
		int64_t compactVal = mq->toCompactValue(qsign);
		if (compactVal != BigDecimal::INFLATED) {
			return createAndStripZerosToMatchScale(compactVal, scale, (int64_t)preferredScale);
		}
		$var($BigInteger, intVal, mq->toBigInteger(qsign));
		return createAndStripZerosToMatchScale(intVal, scale, (int64_t)preferredScale);
	} else {
		return mq->toBigDecimal(qsign, scale);
	}
}

bool BigDecimal::needIncrement(int64_t ldivisor, int32_t roundingMode, int32_t qsign, $MutableBigInteger* mq, int64_t r) {
	$init(BigDecimal);
	if (!BigDecimal::$assertionsDisabled && !(r != (int64_t)0)) {
		$throwNew($AssertionError);
	}
	int32_t cmpFracHalf = 0;
	if (r <= BigDecimal::HALF_LONG_MIN_VALUE || r > BigDecimal::HALF_LONG_MAX_VALUE) {
		cmpFracHalf = 1;
	} else {
		cmpFracHalf = longCompareMagnitude(2 * r, ldivisor);
	}
	return commonNeedIncrement(roundingMode, qsign, cmpFracHalf, $nc(mq)->isOdd());
}

$BigInteger* BigDecimal::divideAndRound($BigInteger* bdividend, $BigInteger* bdivisor, int32_t roundingMode) {
	$init(BigDecimal);
	$useLocalCurrentObjectStackCache();
	bool isRemainderZero = false;
	int32_t qsign = 0;
	$var($MutableBigInteger, mdividend, $new($MutableBigInteger, $nc(bdividend)->mag));
	$var($MutableBigInteger, mq, $new($MutableBigInteger));
	$var($MutableBigInteger, mdivisor, $new($MutableBigInteger, $nc(bdivisor)->mag));
	$var($MutableBigInteger, mr, mdividend->divide(mdivisor, mq));
	isRemainderZero = $nc(mr)->isZero();
	qsign = ($nc(bdividend)->signum$ != $nc(bdivisor)->signum$) ? -1 : 1;
	if (!isRemainderZero) {
		if (needIncrement(mdivisor, roundingMode, qsign, mq, mr)) {
			mq->add($MutableBigInteger::ONE);
		}
	}
	return mq->toBigInteger(qsign);
}

BigDecimal* BigDecimal::divideAndRound($BigInteger* bdividend, $BigInteger* bdivisor, int32_t scale, int32_t roundingMode, int32_t preferredScale) {
	$init(BigDecimal);
	$useLocalCurrentObjectStackCache();
	bool isRemainderZero = false;
	int32_t qsign = 0;
	$var($MutableBigInteger, mdividend, $new($MutableBigInteger, $nc(bdividend)->mag));
	$var($MutableBigInteger, mq, $new($MutableBigInteger));
	$var($MutableBigInteger, mdivisor, $new($MutableBigInteger, $nc(bdivisor)->mag));
	$var($MutableBigInteger, mr, mdividend->divide(mdivisor, mq));
	isRemainderZero = $nc(mr)->isZero();
	qsign = ($nc(bdividend)->signum$ != $nc(bdivisor)->signum$) ? -1 : 1;
	if (!isRemainderZero) {
		if (needIncrement(mdivisor, roundingMode, qsign, mq, mr)) {
			mq->add($MutableBigInteger::ONE);
		}
		return mq->toBigDecimal(qsign, scale);
	} else if (preferredScale != scale) {
		int64_t compactVal = mq->toCompactValue(qsign);
		if (compactVal != BigDecimal::INFLATED) {
			return createAndStripZerosToMatchScale(compactVal, scale, (int64_t)preferredScale);
		}
		$var($BigInteger, intVal, mq->toBigInteger(qsign));
		return createAndStripZerosToMatchScale(intVal, scale, (int64_t)preferredScale);
	} else {
		return mq->toBigDecimal(qsign, scale);
	}
}

bool BigDecimal::needIncrement($MutableBigInteger* mdivisor, int32_t roundingMode, int32_t qsign, $MutableBigInteger* mq, $MutableBigInteger* mr) {
	$init(BigDecimal);
	if (!BigDecimal::$assertionsDisabled && ! !$nc(mr)->isZero()) {
		$throwNew($AssertionError);
	}
	int32_t cmpFracHalf = $nc(mr)->compareHalf(mdivisor);
	return commonNeedIncrement(roundingMode, qsign, cmpFracHalf, $nc(mq)->isOdd());
}

BigDecimal* BigDecimal::createAndStripZerosToMatchScale($BigInteger* intVal$renamed, int32_t scale, int64_t preferredScale) {
	$init(BigDecimal);
	$useLocalCurrentObjectStackCache();
	$var($BigInteger, intVal, intVal$renamed);
	$var($BigIntegerArray, qr, nullptr);
	$init($BigInteger);
	while ($nc(intVal)->compareMagnitude($BigInteger::TEN) >= 0 && scale > preferredScale) {
		if (intVal->testBit(0)) {
			break;
		}
		$assign(qr, intVal->divideAndRemainder($BigInteger::TEN));
		if ($nc($nc(qr)->get(1))->signum() != 0) {
			break;
		}
		$assign(intVal, $nc(qr)->get(0));
		scale = checkScale(intVal, (int64_t)scale - 1);
	}
	return valueOf(intVal, scale, 0);
}

BigDecimal* BigDecimal::createAndStripZerosToMatchScale(int64_t compactVal, int32_t scale, int64_t preferredScale) {
	$init(BigDecimal);
	while ($Math::abs(compactVal) >= (int64_t)10 && scale > preferredScale) {
		if (((int64_t)(compactVal & (uint64_t)(int64_t)1)) != (int64_t)0) {
			break;
		}
		int64_t r = $mod(compactVal, (int64_t)10);
		if (r != (int64_t)0) {
			break;
		}
		compactVal /= 10;
		scale = checkScale(compactVal, (int64_t)scale - 1);
	}
	return valueOf(compactVal, scale);
}

BigDecimal* BigDecimal::stripZerosToMatchScale($BigInteger* intVal, int64_t intCompact, int32_t scale, int32_t preferredScale) {
	$init(BigDecimal);
	if (intCompact != BigDecimal::INFLATED) {
		return createAndStripZerosToMatchScale(intCompact, scale, (int64_t)preferredScale);
	} else {
		return createAndStripZerosToMatchScale(intVal == nullptr ? BigDecimal::INFLATED_BIGINT : intVal, scale, (int64_t)preferredScale);
	}
}

int64_t BigDecimal::add(int64_t xs, int64_t ys) {
	$init(BigDecimal);
	int64_t sum = xs + ys;
	if (((int64_t)((sum ^ xs) & (uint64_t)(sum ^ ys))) >= (int64_t)0) {
		return sum;
	}
	return BigDecimal::INFLATED;
}

BigDecimal* BigDecimal::add(int64_t xs, int64_t ys, int32_t scale) {
	$init(BigDecimal);
	$useLocalCurrentObjectStackCache();
	int64_t sum = add(xs, ys);
	if (sum != BigDecimal::INFLATED) {
		return BigDecimal::valueOf(sum, scale);
	}
	return $new(BigDecimal, $($nc($($BigInteger::valueOf(xs)))->add(ys)), scale);
}

BigDecimal* BigDecimal::add(int64_t xs, int32_t scale1, int64_t ys, int32_t scale2) {
	$init(BigDecimal);
	$useLocalCurrentObjectStackCache();
	int64_t sdiff = (int64_t)scale1 - scale2;
	if (sdiff == 0) {
		return add(xs, ys, scale1);
	} else if (sdiff < 0) {
		int32_t raise = checkScale(xs, -sdiff);
		int64_t scaledX = longMultiplyPowerTen(xs, raise);
		if (scaledX != BigDecimal::INFLATED) {
			return add(scaledX, ys, scale2);
		} else {
			$var($BigInteger, bigsum, $nc($(bigMultiplyPowerTen(xs, raise)))->add(ys));
			return ((xs ^ ys) >= 0) ? $new(BigDecimal, bigsum, BigDecimal::INFLATED, scale2, 0) : valueOf(bigsum, scale2, 0);
		}
	} else {
		int32_t raise = checkScale(ys, sdiff);
		int64_t scaledY = longMultiplyPowerTen(ys, raise);
		if (scaledY != BigDecimal::INFLATED) {
			return add(xs, scaledY, scale1);
		} else {
			$var($BigInteger, bigsum, $nc($(bigMultiplyPowerTen(ys, raise)))->add(xs));
			return ((xs ^ ys) >= 0) ? $new(BigDecimal, bigsum, BigDecimal::INFLATED, scale1, 0) : valueOf(bigsum, scale1, 0);
		}
	}
}

BigDecimal* BigDecimal::add(int64_t xs, int32_t scale1, $BigInteger* snd$renamed, int32_t scale2) {
	$init(BigDecimal);
	$useLocalCurrentObjectStackCache();
	$var($BigInteger, snd, snd$renamed);
	int32_t rscale = scale1;
	int64_t sdiff = (int64_t)rscale - scale2;
	bool sameSigns = ($Long::signum(xs) == $nc(snd)->signum$);
	$var($BigInteger, sum, nullptr);
	if (sdiff < 0) {
		int32_t raise = checkScale(xs, -sdiff);
		rscale = scale2;
		int64_t scaledX = longMultiplyPowerTen(xs, raise);
		if (scaledX == BigDecimal::INFLATED) {
			$assign(sum, snd->add($(bigMultiplyPowerTen(xs, raise))));
		} else {
			$assign(sum, snd->add(scaledX));
		}
	} else {
		int32_t raise = checkScale(snd, sdiff);
		$assign(snd, bigMultiplyPowerTen(snd, raise));
		$assign(sum, $nc(snd)->add(xs));
	}
	return (sameSigns) ? $new(BigDecimal, sum, BigDecimal::INFLATED, rscale, 0) : valueOf(sum, rscale, 0);
}

BigDecimal* BigDecimal::add($BigInteger* fst$renamed, int32_t scale1, $BigInteger* snd$renamed, int32_t scale2) {
	$init(BigDecimal);
	$useLocalCurrentObjectStackCache();
	$var($BigInteger, fst, fst$renamed);
	$var($BigInteger, snd, snd$renamed);
	int32_t rscale = scale1;
	int64_t sdiff = (int64_t)rscale - scale2;
	if (sdiff != 0) {
		if (sdiff < 0) {
			int32_t raise = checkScale(fst, -sdiff);
			rscale = scale2;
			$assign(fst, bigMultiplyPowerTen(fst, raise));
		} else {
			int32_t raise = checkScale(snd, sdiff);
			$assign(snd, bigMultiplyPowerTen(snd, raise));
		}
	}
	$var($BigInteger, sum, $nc(fst)->add(snd));
	return (fst->signum$ == $nc(snd)->signum$) ? $new(BigDecimal, sum, BigDecimal::INFLATED, rscale, 0) : valueOf(sum, rscale, 0);
}

$BigInteger* BigDecimal::bigMultiplyPowerTen(int64_t value, int32_t n) {
	$init(BigDecimal);
	if (n <= 0) {
		return $BigInteger::valueOf(value);
	}
	return $nc($(bigTenToThe(n)))->multiply(value);
}

$BigInteger* BigDecimal::bigMultiplyPowerTen($BigInteger* value, int32_t n) {
	$init(BigDecimal);
	if (n <= 0) {
		return value;
	}
	if (n < $nc(BigDecimal::LONG_TEN_POWERS_TABLE)->length) {
		return $nc(value)->multiply($nc(BigDecimal::LONG_TEN_POWERS_TABLE)->get(n));
	}
	return $nc(value)->multiply($(bigTenToThe(n)));
}

BigDecimal* BigDecimal::divideSmallFastPath(int64_t xs, int32_t xscale, int64_t ys, int32_t yscale, int64_t preferredScale, $MathContext* mc) {
	$init(BigDecimal);
	$useLocalCurrentObjectStackCache();
	int32_t mcp = $nc(mc)->precision;
	int32_t roundingMode = mc->roundingMode->oldMode;
	if (!BigDecimal::$assertionsDisabled && !((xscale <= yscale) && (yscale < 18) && (mcp < 18))) {
		$throwNew($AssertionError);
	}
	int32_t xraise = yscale - xscale;
	int64_t scaledX = (xraise == 0) ? xs : longMultiplyPowerTen(xs, xraise);
	$var(BigDecimal, quotient, nullptr);
	int32_t cmp = longCompareMagnitude(scaledX, ys);
	if (cmp > 0) {
		yscale -= 1;
		int32_t scl = checkScaleNonZero(preferredScale + yscale - xscale + mcp);
		if (checkScaleNonZero((int64_t)mcp + yscale - xscale) > 0) {
			int32_t raise = checkScaleNonZero((int64_t)mcp + yscale - xscale);
			int64_t scaledXs = 0;
			if ((scaledXs = longMultiplyPowerTen(xs, raise)) == BigDecimal::INFLATED) {
				$assign(quotient, nullptr);
				if ((mcp - 1) >= 0 && (mcp - 1) < $nc(BigDecimal::LONG_TEN_POWERS_TABLE)->length) {
					$assign(quotient, multiplyDivideAndRound($nc(BigDecimal::LONG_TEN_POWERS_TABLE)->get(mcp - 1), scaledX, ys, scl, roundingMode, checkScaleNonZero(preferredScale)));
				}
				if (quotient == nullptr) {
					$var($BigInteger, rb, bigMultiplyPowerTen(scaledX, mcp - 1));
					$assign(quotient, divideAndRound(rb, ys, scl, roundingMode, checkScaleNonZero(preferredScale)));
				}
			} else {
				$assign(quotient, divideAndRound(scaledXs, ys, scl, roundingMode, checkScaleNonZero(preferredScale)));
			}
		} else {
			int32_t newScale = checkScaleNonZero((int64_t)xscale - mcp);
			if (newScale == yscale) {
				$assign(quotient, divideAndRound(xs, ys, scl, roundingMode, checkScaleNonZero(preferredScale)));
			} else {
				int32_t raise = checkScaleNonZero((int64_t)newScale - yscale);
				int64_t scaledYs = 0;
				if ((scaledYs = longMultiplyPowerTen(ys, raise)) == BigDecimal::INFLATED) {
					$var($BigInteger, rb, bigMultiplyPowerTen(ys, raise));
					$var($BigInteger, var$0, $BigInteger::valueOf(xs));
					$var($BigInteger, var$1, rb);
					int32_t var$2 = scl;
					int32_t var$3 = roundingMode;
					$assign(quotient, divideAndRound(var$0, var$1, var$2, var$3, checkScaleNonZero(preferredScale)));
				} else {
					$assign(quotient, divideAndRound(xs, scaledYs, scl, roundingMode, checkScaleNonZero(preferredScale)));
				}
			}
		}
	} else {
		int32_t scl = checkScaleNonZero(preferredScale + yscale - xscale + mcp);
		if (cmp == 0) {
			$assign(quotient, roundedTenPower(((scaledX < 0) == (ys < 0)) ? 1 : -1, mcp, scl, checkScaleNonZero(preferredScale)));
		} else {
			int64_t scaledXs = 0;
			if ((scaledXs = longMultiplyPowerTen(scaledX, mcp)) == BigDecimal::INFLATED) {
				$assign(quotient, nullptr);
				if (mcp < $nc(BigDecimal::LONG_TEN_POWERS_TABLE)->length) {
					$assign(quotient, multiplyDivideAndRound($nc(BigDecimal::LONG_TEN_POWERS_TABLE)->get(mcp), scaledX, ys, scl, roundingMode, checkScaleNonZero(preferredScale)));
				}
				if (quotient == nullptr) {
					$var($BigInteger, rb, bigMultiplyPowerTen(scaledX, mcp));
					$assign(quotient, divideAndRound(rb, ys, scl, roundingMode, checkScaleNonZero(preferredScale)));
				}
			} else {
				$assign(quotient, divideAndRound(scaledXs, ys, scl, roundingMode, checkScaleNonZero(preferredScale)));
			}
		}
	}
	return doRound(quotient, mc);
}

BigDecimal* BigDecimal::divide(int64_t xs, int32_t xscale, int64_t ys, int32_t yscale, int64_t preferredScale, $MathContext* mc) {
	$init(BigDecimal);
	$useLocalCurrentObjectStackCache();
	int32_t mcp = $nc(mc)->precision;
	if (xscale <= yscale && yscale < 18 && mcp < 18) {
		return divideSmallFastPath(xs, xscale, ys, yscale, preferredScale, mc);
	}
	if (compareMagnitudeNormalized(xs, xscale, ys, yscale) > 0) {
		yscale -= 1;
	}
	int32_t roundingMode = mc->roundingMode->oldMode;
	int32_t scl = checkScaleNonZero(preferredScale + yscale - xscale + mcp);
	$var(BigDecimal, quotient, nullptr);
	if (checkScaleNonZero((int64_t)mcp + yscale - xscale) > 0) {
		int32_t raise = checkScaleNonZero((int64_t)mcp + yscale - xscale);
		int64_t scaledXs = 0;
		if ((scaledXs = longMultiplyPowerTen(xs, raise)) == BigDecimal::INFLATED) {
			$var($BigInteger, rb, bigMultiplyPowerTen(xs, raise));
			$assign(quotient, divideAndRound(rb, ys, scl, roundingMode, checkScaleNonZero(preferredScale)));
		} else {
			$assign(quotient, divideAndRound(scaledXs, ys, scl, roundingMode, checkScaleNonZero(preferredScale)));
		}
	} else {
		int32_t newScale = checkScaleNonZero((int64_t)xscale - mcp);
		if (newScale == yscale) {
			$assign(quotient, divideAndRound(xs, ys, scl, roundingMode, checkScaleNonZero(preferredScale)));
		} else {
			int32_t raise = checkScaleNonZero((int64_t)newScale - yscale);
			int64_t scaledYs = 0;
			if ((scaledYs = longMultiplyPowerTen(ys, raise)) == BigDecimal::INFLATED) {
				$var($BigInteger, rb, bigMultiplyPowerTen(ys, raise));
				$var($BigInteger, var$0, $BigInteger::valueOf(xs));
				$var($BigInteger, var$1, rb);
				int32_t var$2 = scl;
				int32_t var$3 = roundingMode;
				$assign(quotient, divideAndRound(var$0, var$1, var$2, var$3, checkScaleNonZero(preferredScale)));
			} else {
				$assign(quotient, divideAndRound(xs, scaledYs, scl, roundingMode, checkScaleNonZero(preferredScale)));
			}
		}
	}
	return doRound(quotient, mc);
}

BigDecimal* BigDecimal::divide($BigInteger* xs, int32_t xscale, int64_t ys, int32_t yscale, int64_t preferredScale, $MathContext* mc) {
	$init(BigDecimal);
	$useLocalCurrentObjectStackCache();
	if ((-compareMagnitudeNormalized(ys, yscale, xs, xscale)) > 0) {
		yscale -= 1;
	}
	int32_t mcp = $nc(mc)->precision;
	int32_t roundingMode = mc->roundingMode->oldMode;
	$var(BigDecimal, quotient, nullptr);
	int32_t scl = checkScaleNonZero(preferredScale + yscale - xscale + mcp);
	if (checkScaleNonZero((int64_t)mcp + yscale - xscale) > 0) {
		int32_t raise = checkScaleNonZero((int64_t)mcp + yscale - xscale);
		$var($BigInteger, rb, bigMultiplyPowerTen(xs, raise));
		$assign(quotient, divideAndRound(rb, ys, scl, roundingMode, checkScaleNonZero(preferredScale)));
	} else {
		int32_t newScale = checkScaleNonZero((int64_t)xscale - mcp);
		if (newScale == yscale) {
			$assign(quotient, divideAndRound(xs, ys, scl, roundingMode, checkScaleNonZero(preferredScale)));
		} else {
			int32_t raise = checkScaleNonZero((int64_t)newScale - yscale);
			int64_t scaledYs = 0;
			if ((scaledYs = longMultiplyPowerTen(ys, raise)) == BigDecimal::INFLATED) {
				$var($BigInteger, rb, bigMultiplyPowerTen(ys, raise));
				$assign(quotient, divideAndRound(xs, rb, scl, roundingMode, checkScaleNonZero(preferredScale)));
			} else {
				$assign(quotient, divideAndRound(xs, scaledYs, scl, roundingMode, checkScaleNonZero(preferredScale)));
			}
		}
	}
	return doRound(quotient, mc);
}

BigDecimal* BigDecimal::divide(int64_t xs, int32_t xscale, $BigInteger* ys, int32_t yscale, int64_t preferredScale, $MathContext* mc) {
	$init(BigDecimal);
	$useLocalCurrentObjectStackCache();
	if (compareMagnitudeNormalized(xs, xscale, ys, yscale) > 0) {
		yscale -= 1;
	}
	int32_t mcp = $nc(mc)->precision;
	int32_t roundingMode = mc->roundingMode->oldMode;
	$var(BigDecimal, quotient, nullptr);
	int32_t scl = checkScaleNonZero(preferredScale + yscale - xscale + mcp);
	if (checkScaleNonZero((int64_t)mcp + yscale - xscale) > 0) {
		int32_t raise = checkScaleNonZero((int64_t)mcp + yscale - xscale);
		$var($BigInteger, rb, bigMultiplyPowerTen(xs, raise));
		$assign(quotient, divideAndRound(rb, ys, scl, roundingMode, checkScaleNonZero(preferredScale)));
	} else {
		int32_t newScale = checkScaleNonZero((int64_t)xscale - mcp);
		int32_t raise = checkScaleNonZero((int64_t)newScale - yscale);
		$var($BigInteger, rb, bigMultiplyPowerTen(ys, raise));
		$var($BigInteger, var$0, $BigInteger::valueOf(xs));
		$var($BigInteger, var$1, rb);
		int32_t var$2 = scl;
		int32_t var$3 = roundingMode;
		$assign(quotient, divideAndRound(var$0, var$1, var$2, var$3, checkScaleNonZero(preferredScale)));
	}
	return doRound(quotient, mc);
}

BigDecimal* BigDecimal::divide($BigInteger* xs, int32_t xscale, $BigInteger* ys, int32_t yscale, int64_t preferredScale, $MathContext* mc) {
	$init(BigDecimal);
	$useLocalCurrentObjectStackCache();
	if (compareMagnitudeNormalized(xs, xscale, ys, yscale) > 0) {
		yscale -= 1;
	}
	int32_t mcp = $nc(mc)->precision;
	int32_t roundingMode = mc->roundingMode->oldMode;
	$var(BigDecimal, quotient, nullptr);
	int32_t scl = checkScaleNonZero(preferredScale + yscale - xscale + mcp);
	if (checkScaleNonZero((int64_t)mcp + yscale - xscale) > 0) {
		int32_t raise = checkScaleNonZero((int64_t)mcp + yscale - xscale);
		$var($BigInteger, rb, bigMultiplyPowerTen(xs, raise));
		$assign(quotient, divideAndRound(rb, ys, scl, roundingMode, checkScaleNonZero(preferredScale)));
	} else {
		int32_t newScale = checkScaleNonZero((int64_t)xscale - mcp);
		int32_t raise = checkScaleNonZero((int64_t)newScale - yscale);
		$var($BigInteger, rb, bigMultiplyPowerTen(ys, raise));
		$assign(quotient, divideAndRound(xs, rb, scl, roundingMode, checkScaleNonZero(preferredScale)));
	}
	return doRound(quotient, mc);
}

BigDecimal* BigDecimal::multiplyDivideAndRound(int64_t dividend0, int64_t dividend1, int64_t divisor, int32_t scale, int32_t roundingMode, int32_t preferredScale) {
	$init(BigDecimal);
	int32_t var$1 = $Long::signum(dividend0);
	int32_t var$0 = var$1 * $Long::signum(dividend1);
	int32_t qsign = var$0 * $Long::signum(divisor);
	dividend0 = $Math::abs(dividend0);
	dividend1 = $Math::abs(dividend1);
	divisor = $Math::abs(divisor);
	int64_t d0_hi = (int64_t)((uint64_t)dividend0 >> 32);
	int64_t d0_lo = (int64_t)(dividend0 & (uint64_t)(int64_t)0x00000000FFFFFFFF);
	int64_t d1_hi = (int64_t)((uint64_t)dividend1 >> 32);
	int64_t d1_lo = (int64_t)(dividend1 & (uint64_t)(int64_t)0x00000000FFFFFFFF);
	int64_t product = d0_lo * d1_lo;
	int64_t d0 = (int64_t)(product & (uint64_t)(int64_t)0x00000000FFFFFFFF);
	int64_t d1 = (int64_t)((uint64_t)product >> 32);
	product = d0_hi * d1_lo + d1;
	d1 = (int64_t)(product & (uint64_t)(int64_t)0x00000000FFFFFFFF);
	int64_t d2 = (int64_t)((uint64_t)product >> 32);
	product = d0_lo * d1_hi + d1;
	d1 = (int64_t)(product & (uint64_t)(int64_t)0x00000000FFFFFFFF);
	d2 += (int64_t)((uint64_t)product >> 32);
	int64_t d3 = (int64_t)((uint64_t)d2 >> 32);
	d2 &= (uint64_t)0x00000000FFFFFFFF;
	product = d0_hi * d1_hi + d2;
	d2 = (int64_t)(product & (uint64_t)(int64_t)0x00000000FFFFFFFF);
	d3 = (int64_t)((((int64_t)((uint64_t)product >> 32)) + d3) & (uint64_t)(int64_t)0x00000000FFFFFFFF);
	int64_t dividendHi = make64(d3, d2);
	int64_t dividendLo = make64(d1, d0);
	return divideAndRound128(dividendHi, dividendLo, divisor, qsign, scale, roundingMode, preferredScale);
}

BigDecimal* BigDecimal::divideAndRound128(int64_t dividendHi, int64_t dividendLo, int64_t divisor, int32_t sign, int32_t scale, int32_t roundingMode, int32_t preferredScale) {
	$init(BigDecimal);
	$useLocalCurrentObjectStackCache();
	if (dividendHi >= divisor) {
		return nullptr;
	}
	int32_t shift = $Long::numberOfLeadingZeros(divisor);
	divisor <<= shift;
	int64_t v1 = (int64_t)((uint64_t)divisor >> 32);
	int64_t v0 = (int64_t)(divisor & (uint64_t)(int64_t)0x00000000FFFFFFFF);
	int64_t tmp = $sl(dividendLo, shift);
	int64_t u1 = (int64_t)((uint64_t)tmp >> 32);
	int64_t u0 = (int64_t)(tmp & (uint64_t)(int64_t)0x00000000FFFFFFFF);
	tmp = ($sl(dividendHi, shift)) | ($usr(dividendLo, 64 - shift));
	int64_t u2 = (int64_t)(tmp & (uint64_t)(int64_t)0x00000000FFFFFFFF);
	int64_t q1 = 0;
	int64_t r_tmp = 0;
	if (v1 == 1) {
		q1 = tmp;
		r_tmp = 0;
	} else if (tmp >= 0) {
		q1 = $div(tmp, v1);
		r_tmp = tmp - q1 * v1;
	} else {
		$var($longs, rq, divRemNegativeLong(tmp, v1));
		q1 = $nc(rq)->get(1);
		r_tmp = rq->get(0);
	}
	while (q1 >= BigDecimal::DIV_NUM_BASE || unsignedLongCompare(q1 * v0, make64(r_tmp, u1))) {
		--q1;
		r_tmp += v1;
		if (r_tmp >= BigDecimal::DIV_NUM_BASE) {
			break;
		}
	}
	tmp = mulsub(u2, u1, v1, v0, q1);
	u1 = (int64_t)(tmp & (uint64_t)(int64_t)0x00000000FFFFFFFF);
	int64_t q0 = 0;
	if (v1 == 1) {
		q0 = tmp;
		r_tmp = 0;
	} else if (tmp >= 0) {
		q0 = $div(tmp, v1);
		r_tmp = tmp - q0 * v1;
	} else {
		$var($longs, rq, divRemNegativeLong(tmp, v1));
		q0 = $nc(rq)->get(1);
		r_tmp = rq->get(0);
	}
	while (q0 >= BigDecimal::DIV_NUM_BASE || unsignedLongCompare(q0 * v0, make64(r_tmp, u0))) {
		--q0;
		r_tmp += v1;
		if (r_tmp >= BigDecimal::DIV_NUM_BASE) {
			break;
		}
	}
	if ((int32_t)q1 < 0) {
		$var($MutableBigInteger, mq, $new($MutableBigInteger, $$new($ints, {
			(int32_t)q1,
			(int32_t)q0
		})));
		if (roundingMode == BigDecimal::ROUND_DOWN && scale == preferredScale) {
			return mq->toBigDecimal(sign, scale);
		}
		int64_t r = $usr(mulsub(u1, u0, v1, v0, q0), shift);
		if (r != 0) {
			if (needIncrement($usr(divisor, shift), roundingMode, sign, mq, r)) {
				$init($MutableBigInteger);
				mq->add($MutableBigInteger::ONE);
			}
			return mq->toBigDecimal(sign, scale);
		} else if (preferredScale != scale) {
			$var($BigInteger, intVal, mq->toBigInteger(sign));
			return createAndStripZerosToMatchScale(intVal, scale, (int64_t)preferredScale);
		} else {
			return mq->toBigDecimal(sign, scale);
		}
	}
	int64_t q = make64(q1, q0);
	q *= sign;
	if (roundingMode == BigDecimal::ROUND_DOWN && scale == preferredScale) {
		return valueOf(q, scale);
	}
	int64_t r = $usr(mulsub(u1, u0, v1, v0, q0), shift);
	if (r != 0) {
		bool increment = needIncrement($usr(divisor, shift), roundingMode, sign, q, r);
		return valueOf((increment ? q + sign : q), scale);
	} else if (preferredScale != scale) {
		return createAndStripZerosToMatchScale(q, scale, (int64_t)preferredScale);
	} else {
		return valueOf(q, scale);
	}
}

BigDecimal* BigDecimal::roundedTenPower(int32_t qsign, int32_t raise, int32_t scale, int32_t preferredScale) {
	$init(BigDecimal);
	if (scale > preferredScale) {
		int32_t diff = scale - preferredScale;
		if (diff < raise) {
			return scaledTenPow(raise - diff, qsign, preferredScale);
		} else {
			return valueOf(qsign, scale - raise);
		}
	} else {
		return scaledTenPow(raise, qsign, scale);
	}
}

BigDecimal* BigDecimal::scaledTenPow(int32_t n, int32_t sign, int32_t scale) {
	$init(BigDecimal);
	if (n < $nc(BigDecimal::LONG_TEN_POWERS_TABLE)->length) {
		return valueOf(sign * $nc(BigDecimal::LONG_TEN_POWERS_TABLE)->get(n), scale);
	} else {
		$var($BigInteger, unscaledVal, bigTenToThe(n));
		if (sign == -1) {
			$assign(unscaledVal, $nc(unscaledVal)->negate());
		}
		return $new(BigDecimal, unscaledVal, BigDecimal::INFLATED, scale, n + 1);
	}
}

$longs* BigDecimal::divRemNegativeLong(int64_t n, int64_t d) {
	$init(BigDecimal);
	$useLocalCurrentObjectStackCache();
	if (!BigDecimal::$assertionsDisabled && !(n < 0)) {
		$throwNew($AssertionError, $of($$str({"Non-negative numerator "_s, $$str(n)})));
	}
	if (!BigDecimal::$assertionsDisabled && !(d != 1)) {
		$throwNew($AssertionError, $of("Unity denominator"_s));
	}
	int64_t q = $div(((int64_t)((uint64_t)n >> 1)), ((int64_t)((uint64_t)d >> 1)));
	int64_t r = n - q * d;
	while (r < 0) {
		r += d;
		--q;
	}
	while (r >= d) {
		r -= d;
		++q;
	}
	return $new($longs, {
		r,
		q
	});
}

int64_t BigDecimal::make64(int64_t hi, int64_t lo) {
	$init(BigDecimal);
	return (hi << 32) | lo;
}

int64_t BigDecimal::mulsub(int64_t u1, int64_t u0, int64_t v1, int64_t v0, int64_t q0) {
	$init(BigDecimal);
	int64_t tmp = u0 - q0 * v0;
	return make64(u1 + ((int64_t)((uint64_t)tmp >> 32)) - q0 * v1, (int64_t)(tmp & (uint64_t)(int64_t)0x00000000FFFFFFFF));
}

bool BigDecimal::unsignedLongCompare(int64_t one, int64_t two) {
	$init(BigDecimal);
	return (one + $Long::MIN_VALUE) > (two + $Long::MIN_VALUE);
}

bool BigDecimal::unsignedLongCompareEq(int64_t one, int64_t two) {
	$init(BigDecimal);
	return (one + $Long::MIN_VALUE) >= (two + $Long::MIN_VALUE);
}

int32_t BigDecimal::compareMagnitudeNormalized(int64_t xs, int32_t xscale, int64_t ys, int32_t yscale) {
	$init(BigDecimal);
	int32_t sdiff = xscale - yscale;
	if (sdiff != 0) {
		if (sdiff < 0) {
			xs = longMultiplyPowerTen(xs, -sdiff);
		} else {
			ys = longMultiplyPowerTen(ys, sdiff);
		}
	}
	if (xs != BigDecimal::INFLATED) {
		return (ys != BigDecimal::INFLATED) ? longCompareMagnitude(xs, ys) : -1;
	} else {
		return 1;
	}
}

int32_t BigDecimal::compareMagnitudeNormalized(int64_t xs, int32_t xscale, $BigInteger* ys, int32_t yscale) {
	$init(BigDecimal);
	if (xs == 0) {
		return -1;
	}
	int32_t sdiff = xscale - yscale;
	if (sdiff < 0) {
		if (longMultiplyPowerTen(xs, -sdiff) == BigDecimal::INFLATED) {
			return $nc($(bigMultiplyPowerTen(xs, -sdiff)))->compareMagnitude(ys);
		}
	}
	return -1;
}

int32_t BigDecimal::compareMagnitudeNormalized($BigInteger* xs, int32_t xscale, $BigInteger* ys, int32_t yscale) {
	$init(BigDecimal);
	$useLocalCurrentObjectStackCache();
	int32_t sdiff = xscale - yscale;
	if (sdiff < 0) {
		return $nc($(bigMultiplyPowerTen(xs, -sdiff)))->compareMagnitude(ys);
	} else {
		return $nc(xs)->compareMagnitude($(bigMultiplyPowerTen(ys, sdiff)));
	}
}

int64_t BigDecimal::multiply(int64_t x, int64_t y) {
	$init(BigDecimal);
	int64_t product = x * y;
	int64_t ax = $Math::abs(x);
	int64_t ay = $Math::abs(y);
	if (((int64_t)((uint64_t)(ax | ay) >> 31) == 0) || (y == 0) || ($div(product, y) == x)) {
		return product;
	}
	return BigDecimal::INFLATED;
}

BigDecimal* BigDecimal::multiply(int64_t x, int64_t y, int32_t scale) {
	$init(BigDecimal);
	$useLocalCurrentObjectStackCache();
	int64_t product = multiply(x, y);
	if (product != BigDecimal::INFLATED) {
		return valueOf(product, scale);
	}
	return $new(BigDecimal, $($nc($($BigInteger::valueOf(x)))->multiply(y)), BigDecimal::INFLATED, scale, 0);
}

BigDecimal* BigDecimal::multiply(int64_t x, $BigInteger* y, int32_t scale) {
	$init(BigDecimal);
	if (x == 0) {
		return zeroValueOf(scale);
	}
	return $new(BigDecimal, $($nc(y)->multiply(x)), BigDecimal::INFLATED, scale, 0);
}

BigDecimal* BigDecimal::multiply($BigInteger* x, $BigInteger* y, int32_t scale) {
	$init(BigDecimal);
	return $new(BigDecimal, $($nc(x)->multiply(y)), BigDecimal::INFLATED, scale, 0);
}

BigDecimal* BigDecimal::multiplyAndRound(int64_t x, int64_t y, int32_t scale, $MathContext* mc) {
	$init(BigDecimal);
	$useLocalCurrentObjectStackCache();
	int64_t product = multiply(x, y);
	if (product != BigDecimal::INFLATED) {
		return doRound(product, scale, mc);
	}
	int32_t rsign = 1;
	if (x < 0) {
		x = -x;
		rsign = -1;
	}
	if (y < 0) {
		y = -y;
		rsign *= -1;
	}
	int64_t m0_hi = (int64_t)((uint64_t)x >> 32);
	int64_t m0_lo = (int64_t)(x & (uint64_t)(int64_t)0x00000000FFFFFFFF);
	int64_t m1_hi = (int64_t)((uint64_t)y >> 32);
	int64_t m1_lo = (int64_t)(y & (uint64_t)(int64_t)0x00000000FFFFFFFF);
	product = m0_lo * m1_lo;
	int64_t m0 = (int64_t)(product & (uint64_t)(int64_t)0x00000000FFFFFFFF);
	int64_t m1 = (int64_t)((uint64_t)product >> 32);
	product = m0_hi * m1_lo + m1;
	m1 = (int64_t)(product & (uint64_t)(int64_t)0x00000000FFFFFFFF);
	int64_t m2 = (int64_t)((uint64_t)product >> 32);
	product = m0_lo * m1_hi + m1;
	m1 = (int64_t)(product & (uint64_t)(int64_t)0x00000000FFFFFFFF);
	m2 += (int64_t)((uint64_t)product >> 32);
	int64_t m3 = (int64_t)((uint64_t)m2 >> 32);
	m2 &= (uint64_t)0x00000000FFFFFFFF;
	product = m0_hi * m1_hi + m2;
	m2 = (int64_t)(product & (uint64_t)(int64_t)0x00000000FFFFFFFF);
	m3 = (int64_t)((((int64_t)((uint64_t)product >> 32)) + m3) & (uint64_t)(int64_t)0x00000000FFFFFFFF);
	int64_t mHi = make64(m3, m2);
	int64_t mLo = make64(m1, m0);
	$var(BigDecimal, res, doRound128(mHi, mLo, rsign, scale, mc));
	if (res != nullptr) {
		return res;
	}
	$assign(res, $new(BigDecimal, $($nc($($BigInteger::valueOf(x)))->multiply(y * rsign)), BigDecimal::INFLATED, scale, 0));
	return doRound(res, mc);
}

BigDecimal* BigDecimal::multiplyAndRound(int64_t x, $BigInteger* y, int32_t scale, $MathContext* mc) {
	$init(BigDecimal);
	if (x == 0) {
		return zeroValueOf(scale);
	}
	return doRound($($nc(y)->multiply(x)), scale, mc);
}

BigDecimal* BigDecimal::multiplyAndRound($BigInteger* x, $BigInteger* y, int32_t scale, $MathContext* mc) {
	$init(BigDecimal);
	return doRound($($nc(x)->multiply(y)), scale, mc);
}

BigDecimal* BigDecimal::doRound128(int64_t hi, int64_t lo, int32_t sign, int32_t scale, $MathContext* mc) {
	$init(BigDecimal);
	int32_t mcp = $nc(mc)->precision;
	int32_t drop = 0;
	$var(BigDecimal, res, nullptr);
	bool var$0 = ((drop = precision(hi, lo) - mcp) > 0);
	if (var$0 && (drop < $nc(BigDecimal::LONG_TEN_POWERS_TABLE)->length)) {
		scale = checkScaleNonZero((int64_t)scale - drop);
		$assign(res, divideAndRound128(hi, lo, $nc(BigDecimal::LONG_TEN_POWERS_TABLE)->get(drop), sign, scale, mc->roundingMode->oldMode, scale));
	}
	if (res != nullptr) {
		return doRound(res, mc);
	}
	return nullptr;
}

int32_t BigDecimal::precision(int64_t hi, int64_t lo) {
	$init(BigDecimal);
	if (hi == 0) {
		if (lo >= 0) {
			return longDigitLength(lo);
		}
		return (unsignedLongCompareEq(lo, $nc($nc(BigDecimal::LONGLONG_TEN_POWERS_TABLE)->get(0))->get(1))) ? 20 : 19;
	}
	int32_t r = (int32_t)((uint32_t)((128 - $Long::numberOfLeadingZeros(hi) + 1) * 1233) >> 12);
	int32_t idx = r - 19;
	return (idx >= $nc(BigDecimal::LONGLONG_TEN_POWERS_TABLE)->length || longLongCompareMagnitude(hi, lo, $nc($nc(BigDecimal::LONGLONG_TEN_POWERS_TABLE)->get(idx))->get(0), $nc($nc(BigDecimal::LONGLONG_TEN_POWERS_TABLE)->get(idx))->get(1))) ? r : r + 1;
}

bool BigDecimal::longLongCompareMagnitude(int64_t hi0, int64_t lo0, int64_t hi1, int64_t lo1) {
	$init(BigDecimal);
	if (hi0 != hi1) {
		return hi0 < hi1;
	}
	return (lo0 + $Long::MIN_VALUE) < (lo1 + $Long::MIN_VALUE);
}

BigDecimal* BigDecimal::divide(int64_t dividend, int32_t dividendScale, int64_t divisor, int32_t divisorScale, int32_t scale, int32_t roundingMode) {
	$init(BigDecimal);
	$useLocalCurrentObjectStackCache();
	if (checkScale(dividend, (int64_t)scale + divisorScale) > dividendScale) {
		int32_t newScale = scale + divisorScale;
		int32_t raise = newScale - dividendScale;
		if (raise < $nc(BigDecimal::LONG_TEN_POWERS_TABLE)->length) {
			int64_t xs = dividend;
			if ((xs = longMultiplyPowerTen(xs, raise)) != BigDecimal::INFLATED) {
				return divideAndRound(xs, divisor, scale, roundingMode, scale);
			}
			$var(BigDecimal, q, multiplyDivideAndRound($nc(BigDecimal::LONG_TEN_POWERS_TABLE)->get(raise), dividend, divisor, scale, roundingMode, scale));
			if (q != nullptr) {
				return q;
			}
		}
		$var($BigInteger, scaledDividend, bigMultiplyPowerTen(dividend, raise));
		return divideAndRound(scaledDividend, divisor, scale, roundingMode, scale);
	} else {
		int32_t newScale = checkScale(divisor, (int64_t)dividendScale - scale);
		int32_t raise = newScale - divisorScale;
		if (raise < $nc(BigDecimal::LONG_TEN_POWERS_TABLE)->length) {
			int64_t ys = divisor;
			if ((ys = longMultiplyPowerTen(ys, raise)) != BigDecimal::INFLATED) {
				return divideAndRound(dividend, ys, scale, roundingMode, scale);
			}
		}
		$var($BigInteger, scaledDivisor, bigMultiplyPowerTen(divisor, raise));
		return divideAndRound($($BigInteger::valueOf(dividend)), scaledDivisor, scale, roundingMode, scale);
	}
}

BigDecimal* BigDecimal::divide($BigInteger* dividend, int32_t dividendScale, int64_t divisor, int32_t divisorScale, int32_t scale, int32_t roundingMode) {
	$init(BigDecimal);
	$useLocalCurrentObjectStackCache();
	if (checkScale(dividend, (int64_t)scale + divisorScale) > dividendScale) {
		int32_t newScale = scale + divisorScale;
		int32_t raise = newScale - dividendScale;
		$var($BigInteger, scaledDividend, bigMultiplyPowerTen(dividend, raise));
		return divideAndRound(scaledDividend, divisor, scale, roundingMode, scale);
	} else {
		int32_t newScale = checkScale(divisor, (int64_t)dividendScale - scale);
		int32_t raise = newScale - divisorScale;
		if (raise < $nc(BigDecimal::LONG_TEN_POWERS_TABLE)->length) {
			int64_t ys = divisor;
			if ((ys = longMultiplyPowerTen(ys, raise)) != BigDecimal::INFLATED) {
				return divideAndRound(dividend, ys, scale, roundingMode, scale);
			}
		}
		$var($BigInteger, scaledDivisor, bigMultiplyPowerTen(divisor, raise));
		return divideAndRound(dividend, scaledDivisor, scale, roundingMode, scale);
	}
}

BigDecimal* BigDecimal::divide(int64_t dividend, int32_t dividendScale, $BigInteger* divisor, int32_t divisorScale, int32_t scale, int32_t roundingMode) {
	$init(BigDecimal);
	$useLocalCurrentObjectStackCache();
	if (checkScale(dividend, (int64_t)scale + divisorScale) > dividendScale) {
		int32_t newScale = scale + divisorScale;
		int32_t raise = newScale - dividendScale;
		$var($BigInteger, scaledDividend, bigMultiplyPowerTen(dividend, raise));
		return divideAndRound(scaledDividend, divisor, scale, roundingMode, scale);
	} else {
		int32_t newScale = checkScale(divisor, (int64_t)dividendScale - scale);
		int32_t raise = newScale - divisorScale;
		$var($BigInteger, scaledDivisor, bigMultiplyPowerTen(divisor, raise));
		return divideAndRound($($BigInteger::valueOf(dividend)), scaledDivisor, scale, roundingMode, scale);
	}
}

BigDecimal* BigDecimal::divide($BigInteger* dividend, int32_t dividendScale, $BigInteger* divisor, int32_t divisorScale, int32_t scale, int32_t roundingMode) {
	$init(BigDecimal);
	$useLocalCurrentObjectStackCache();
	if (checkScale(dividend, (int64_t)scale + divisorScale) > dividendScale) {
		int32_t newScale = scale + divisorScale;
		int32_t raise = newScale - dividendScale;
		$var($BigInteger, scaledDividend, bigMultiplyPowerTen(dividend, raise));
		return divideAndRound(scaledDividend, divisor, scale, roundingMode, scale);
	} else {
		int32_t newScale = checkScale(divisor, (int64_t)dividendScale - scale);
		int32_t raise = newScale - divisorScale;
		$var($BigInteger, scaledDivisor, bigMultiplyPowerTen(divisor, raise));
		return divideAndRound(dividend, scaledDivisor, scale, roundingMode, scale);
	}
}

int32_t BigDecimal::compareTo(Object$* val) {
	return this->compareTo($cast(BigDecimal, val));
}

void clinit$BigDecimal($Class* class$) {
	$useLocalCurrentObjectStackCache();
	BigDecimal::$assertionsDisabled = !BigDecimal::class$->desiredAssertionStatus();
	$assignStatic(BigDecimal::INFLATED_BIGINT, $BigInteger::valueOf(BigDecimal::INFLATED));
	$assignStatic(BigDecimal::ZERO_THROUGH_TEN, $new($BigDecimalArray, {
		$$new(BigDecimal, $BigInteger::ZERO, (int64_t)0, 0, 1),
		$$new(BigDecimal, $BigInteger::ONE, (int64_t)1, 0, 1),
		$$new(BigDecimal, $BigInteger::TWO, (int64_t)2, 0, 1),
		$$new(BigDecimal, $($BigInteger::valueOf((int64_t)3)), (int64_t)3, 0, 1),
		$$new(BigDecimal, $($BigInteger::valueOf((int64_t)4)), (int64_t)4, 0, 1),
		$$new(BigDecimal, $($BigInteger::valueOf((int64_t)5)), (int64_t)5, 0, 1),
		$$new(BigDecimal, $($BigInteger::valueOf((int64_t)6)), (int64_t)6, 0, 1),
		$$new(BigDecimal, $($BigInteger::valueOf((int64_t)7)), (int64_t)7, 0, 1),
		$$new(BigDecimal, $($BigInteger::valueOf((int64_t)8)), (int64_t)8, 0, 1),
		$$new(BigDecimal, $($BigInteger::valueOf((int64_t)9)), (int64_t)9, 0, 1),
		$$new(BigDecimal, $BigInteger::TEN, (int64_t)10, 0, 2)
	}));
	$assignStatic(BigDecimal::ZERO_SCALED_BY, $new($BigDecimalArray, {
		$nc(BigDecimal::ZERO_THROUGH_TEN)->get(0),
		$$new(BigDecimal, $BigInteger::ZERO, (int64_t)0, 1, 1),
		$$new(BigDecimal, $BigInteger::ZERO, (int64_t)0, 2, 1),
		$$new(BigDecimal, $BigInteger::ZERO, (int64_t)0, 3, 1),
		$$new(BigDecimal, $BigInteger::ZERO, (int64_t)0, 4, 1),
		$$new(BigDecimal, $BigInteger::ZERO, (int64_t)0, 5, 1),
		$$new(BigDecimal, $BigInteger::ZERO, (int64_t)0, 6, 1),
		$$new(BigDecimal, $BigInteger::ZERO, (int64_t)0, 7, 1),
		$$new(BigDecimal, $BigInteger::ZERO, (int64_t)0, 8, 1),
		$$new(BigDecimal, $BigInteger::ZERO, (int64_t)0, 9, 1),
		$$new(BigDecimal, $BigInteger::ZERO, (int64_t)0, 10, 1),
		$$new(BigDecimal, $BigInteger::ZERO, (int64_t)0, 11, 1),
		$$new(BigDecimal, $BigInteger::ZERO, (int64_t)0, 12, 1),
		$$new(BigDecimal, $BigInteger::ZERO, (int64_t)0, 13, 1),
		$$new(BigDecimal, $BigInteger::ZERO, (int64_t)0, 14, 1),
		$$new(BigDecimal, $BigInteger::ZERO, (int64_t)0, 15, 1)
	}));
	$assignStatic(BigDecimal::ZERO, $nc(BigDecimal::ZERO_THROUGH_TEN)->get(0));
	$assignStatic(BigDecimal::ONE, $nc(BigDecimal::ZERO_THROUGH_TEN)->get(1));
	$assignStatic(BigDecimal::TEN, $nc(BigDecimal::ZERO_THROUGH_TEN)->get(10));
	$assignStatic(BigDecimal::ONE_TENTH, BigDecimal::valueOf(1, 1));
	$assignStatic(BigDecimal::ONE_HALF, BigDecimal::valueOf(5, 1));
	$assignStatic(BigDecimal::DOUBLE_10_POW, $new($doubles, {
		1.0,
		10.0,
		100.0,
		1000.0,
		10000.0,
		100000.0,
		1000000.0,
		1.0E7,
		1.0E8,
		1.0E9,
		1.0E10,
		1.0E11,
		1.0E12,
		1.0E13,
		1.0E14,
		1.0E15,
		1.0E16,
		1.0E17,
		1.0E18,
		1.0E19,
		1.0E20,
		1.0E21,
		1.0E22
	}));
	$assignStatic(BigDecimal::FLOAT_10_POW, $new($floats, {
		1.0f,
		10.0f,
		100.0f,
		1000.0f,
		10000.0f,
		100000.0f,
		1000000.0f,
		1.0E7f,
		1.0E8f,
		1.0E9f,
		1.0E10f
	}));
	$assignStatic(BigDecimal::LONG_TEN_POWERS_TABLE, $new($longs, {
		(int64_t)1,
		(int64_t)10,
		(int64_t)100,
		(int64_t)1000,
		(int64_t)10000,
		(int64_t)0x000186A0,
		(int64_t)0x000F4240,
		(int64_t)0x00989680,
		(int64_t)0x05F5E100,
		(int64_t)0x3B9ACA00,
		(int64_t)0x00000002540BE400,
		(int64_t)0x000000174876E800,
		(int64_t)0x000000E8D4A51000,
		(int64_t)0x000009184E72A000,
		(int64_t)0x00005AF3107A4000,
		(int64_t)0x00038D7EA4C68000,
		(int64_t)0x002386F26FC10000,
		(int64_t)0x016345785D8A0000,
		(int64_t)0x0DE0B6B3A7640000
	}));
	$assignStatic(BigDecimal::BIG_TEN_POWERS_TABLE, $new($BigIntegerArray, {
		$BigInteger::ONE,
		$($BigInteger::valueOf((int64_t)10)),
		$($BigInteger::valueOf((int64_t)100)),
		$($BigInteger::valueOf((int64_t)1000)),
		$($BigInteger::valueOf((int64_t)10000)),
		$($BigInteger::valueOf((int64_t)0x000186A0)),
		$($BigInteger::valueOf((int64_t)0x000F4240)),
		$($BigInteger::valueOf((int64_t)0x00989680)),
		$($BigInteger::valueOf((int64_t)0x05F5E100)),
		$($BigInteger::valueOf((int64_t)0x3B9ACA00)),
		$($BigInteger::valueOf((int64_t)0x00000002540BE400)),
		$($BigInteger::valueOf((int64_t)0x000000174876E800)),
		$($BigInteger::valueOf((int64_t)0x000000E8D4A51000)),
		$($BigInteger::valueOf((int64_t)0x000009184E72A000)),
		$($BigInteger::valueOf((int64_t)0x00005AF3107A4000)),
		$($BigInteger::valueOf((int64_t)0x00038D7EA4C68000)),
		$($BigInteger::valueOf((int64_t)0x002386F26FC10000)),
		$($BigInteger::valueOf((int64_t)0x016345785D8A0000)),
		$($BigInteger::valueOf((int64_t)0x0DE0B6B3A7640000))
	}));
	BigDecimal::BIG_TEN_POWERS_TABLE_INITLEN = $nc(BigDecimal::BIG_TEN_POWERS_TABLE)->length;
	BigDecimal::BIG_TEN_POWERS_TABLE_MAX = 16 * BigDecimal::BIG_TEN_POWERS_TABLE_INITLEN;
	$assignStatic(BigDecimal::THRESHOLDS_TABLE, $new($longs, {
		$Long::MAX_VALUE,
		$div($Long::MAX_VALUE, (int64_t)10),
		$div($Long::MAX_VALUE, (int64_t)100),
		$div($Long::MAX_VALUE, (int64_t)1000),
		$div($Long::MAX_VALUE, (int64_t)10000),
		$div($Long::MAX_VALUE, (int64_t)100000),
		$div($Long::MAX_VALUE, (int64_t)1000000),
		$div($Long::MAX_VALUE, (int64_t)10000000),
		$div($Long::MAX_VALUE, (int64_t)100000000),
		$div($Long::MAX_VALUE, (int64_t)1000000000),
		$div($Long::MAX_VALUE, (int64_t)0x00000002540BE400),
		$div($Long::MAX_VALUE, (int64_t)0x000000174876E800),
		$div($Long::MAX_VALUE, (int64_t)0x000000E8D4A51000),
		$div($Long::MAX_VALUE, (int64_t)0x000009184E72A000),
		$div($Long::MAX_VALUE, (int64_t)0x00005AF3107A4000),
		$div($Long::MAX_VALUE, (int64_t)0x00038D7EA4C68000),
		$div($Long::MAX_VALUE, (int64_t)0x002386F26FC10000),
		$div($Long::MAX_VALUE, (int64_t)0x016345785D8A0000),
		$div($Long::MAX_VALUE, (int64_t)0x0DE0B6B3A7640000)
	}));
	$assignStatic(BigDecimal::LONGLONG_TEN_POWERS_TABLE, $new($longArray2, {
		$$new($longs, {
			(int64_t)0,
			(int64_t)0x8AC7230489E80000
		}),
		$$new($longs, {
			(int64_t)5,
			(int64_t)0x6BC75E2D63100000
		}),
		$$new($longs, {
			(int64_t)54,
			(int64_t)0x35C9ADC5DEA00000
		}),
		$$new($longs, {
			(int64_t)542,
			(int64_t)0x19E0C9BAB2400000
		}),
		$$new($longs, {
			(int64_t)5421,
			(int64_t)0x02C7E14AF6800000
		}),
		$$new($longs, {
			(int64_t)54210,
			(int64_t)0x1BCECCEDA1000000
		}),
		$$new($longs, {
			(int64_t)542101,
			(int64_t)0x161401484A000000
		}),
		$$new($longs, {
			(int64_t)5421010,
			(int64_t)0xDCC80CD2E4000000
		}),
		$$new($longs, {
			(int64_t)54210108,
			(int64_t)0x9FD0803CE8000000
		}),
		$$new($longs, {
			(int64_t)542101086,
			(int64_t)0x3E25026110000000
		}),
		$$new($longs, {
			(int64_t)0x00000001431E0FAE,
			(int64_t)0x6D7217CAA0000000
		}),
		$$new($longs, {
			(int64_t)0x0000000C9F2C9CD0,
			(int64_t)0x4674EDEA40000000
		}),
		$$new($longs, {
			(int64_t)0x0000007E37BE2022,
			(int64_t)0xC0914B2680000000
		}),
		$$new($longs, {
			(int64_t)0x000004EE2D6D415B,
			(int64_t)0x85ACEF8100000000
		}),
		$$new($longs, {
			(int64_t)0x0000314DC6448D93,
			(int64_t)0x38C15B0A00000000
		}),
		$$new($longs, {
			(int64_t)0x0001ED09BEAD87C0,
			(int64_t)0x378D8E6400000000
		}),
		$$new($longs, {
			(int64_t)0x0013426172C74D82,
			(int64_t)0x2B878FE800000000
		}),
		$$new($longs, {
			(int64_t)0x00C097CE7BC90715,
			(int64_t)0xB34B9F1000000000
		}),
		$$new($longs, {
			(int64_t)0x0785EE10D5DA46D9,
			(int64_t)0x00F436A000000000
		}),
		$$new($longs, {
			(int64_t)0x4B3B4CA85A86C47A,
			(int64_t)0x098A224000000000
		})
	}));
}

BigDecimal::BigDecimal() {
}

$Class* BigDecimal::load$($String* name, bool initialize) {
	$loadClass(BigDecimal, name, initialize, &_BigDecimal_ClassInfo_, clinit$BigDecimal, allocate$BigDecimal);
	return class$;
}

$Class* BigDecimal::class$ = nullptr;

	} // math
} // java