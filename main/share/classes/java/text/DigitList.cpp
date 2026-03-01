#include <java/text/DigitList.h>

#include <java/lang/AssertionError.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/Cloneable.h>
#include <java/lang/InternalError.h>
#include <java/lang/StringBuffer.h>
#include <java/math/BigDecimal.h>
#include <java/math/BigInteger.h>
#include <java/math/RoundingMode.h>
#include <java/text/DigitList$1.h>
#include <jdk/internal/math/FloatingDecimal$BinaryToASCIIConverter.h>
#include <jdk/internal/math/FloatingDecimal.h>
#include <jcpp.h>

#undef HALF_EVEN
#undef HALF_UP
#undef LONG_MIN_REP
#undef MAX_COUNT
#undef MIN_VALUE
#undef ZERO

using $ArithmeticException = ::java::lang::ArithmeticException;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $Cloneable = ::java::lang::Cloneable;
using $Double = ::java::lang::Double;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $StringBuffer = ::java::lang::StringBuffer;
using $BigDecimal = ::java::math::BigDecimal;
using $BigInteger = ::java::math::BigInteger;
using $RoundingMode = ::java::math::RoundingMode;
using $DigitList$1 = ::java::text::DigitList$1;
using $FloatingDecimal = ::jdk::internal::math::FloatingDecimal;
using $FloatingDecimal$BinaryToASCIIConverter = ::jdk::internal::math::FloatingDecimal$BinaryToASCIIConverter;

namespace java {
	namespace text {

$FieldInfo _DigitList_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(DigitList, $assertionsDisabled)},
	{"MAX_COUNT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(DigitList, MAX_COUNT)},
	{"decimalAt", "I", nullptr, $PUBLIC, $field(DigitList, decimalAt)},
	{"count", "I", nullptr, $PUBLIC, $field(DigitList, count)},
	{"digits", "[C", nullptr, $PUBLIC, $field(DigitList, digits)},
	{"data", "[C", nullptr, $PRIVATE, $field(DigitList, data)},
	{"roundingMode", "Ljava/math/RoundingMode;", nullptr, $PRIVATE, $field(DigitList, roundingMode)},
	{"isNegative", "Z", nullptr, $PRIVATE, $field(DigitList, isNegative)},
	{"LONG_MIN_REP", "[C", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DigitList, LONG_MIN_REP)},
	{"tempBuffer", "Ljava/lang/StringBuffer;", nullptr, $PRIVATE, $field(DigitList, tempBuffer)},
	{}
};

$MethodInfo _DigitList_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(DigitList, init$, void)},
	{"append", "(C)V", nullptr, $PUBLIC, $method(DigitList, append, void, char16_t)},
	{"clear", "()V", nullptr, $PUBLIC, $method(DigitList, clear, void)},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(DigitList, clone, $Object*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(DigitList, equals, bool, Object$*)},
	{"extendDigits", "(I)V", nullptr, $PRIVATE, $method(DigitList, extendDigits, void, int32_t)},
	{"fitsIntoLong", "(ZZ)Z", nullptr, 0, $method(DigitList, fitsIntoLong, bool, bool, bool)},
	{"getBigDecimal", "()Ljava/math/BigDecimal;", nullptr, $PUBLIC | $FINAL, $method(DigitList, getBigDecimal, $BigDecimal*)},
	{"getDataChars", "(I)[C", nullptr, $PRIVATE | $FINAL, $method(DigitList, getDataChars, $chars*, int32_t)},
	{"getDouble", "()D", nullptr, $PUBLIC | $FINAL, $method(DigitList, getDouble, double)},
	{"getLong", "()J", nullptr, $PUBLIC | $FINAL, $method(DigitList, getLong, int64_t)},
	{"getStringBuffer", "()Ljava/lang/StringBuffer;", nullptr, $PRIVATE, $method(DigitList, getStringBuffer, $StringBuffer*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(DigitList, hashCode, int32_t)},
	{"isLongMIN_VALUE", "()Z", nullptr, $PRIVATE, $method(DigitList, isLongMIN_VALUE, bool)},
	{"isZero", "()Z", nullptr, 0, $method(DigitList, isZero, bool)},
	{"parseInt", "([CII)I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticMethod(DigitList, parseInt, int32_t, $chars*, int32_t, int32_t)},
	{"round", "(IZZ)V", nullptr, $PRIVATE | $FINAL, $method(DigitList, round, void, int32_t, bool, bool)},
	{"set", "(ZDI)V", nullptr, $FINAL, $method(DigitList, set, void, bool, double, int32_t)},
	{"set", "(ZDIZ)V", nullptr, $FINAL, $method(DigitList, set, void, bool, double, int32_t, bool)},
	{"set", "(ZLjava/lang/String;ZZIZ)V", nullptr, $PRIVATE, $method(DigitList, set, void, bool, $String*, bool, bool, int32_t, bool)},
	{"set", "(ZJ)V", nullptr, $FINAL, $method(DigitList, set, void, bool, int64_t)},
	{"set", "(ZJI)V", nullptr, $FINAL, $method(DigitList, set, void, bool, int64_t, int32_t)},
	{"set", "(ZLjava/math/BigDecimal;IZ)V", nullptr, $FINAL, $method(DigitList, set, void, bool, $BigDecimal*, int32_t, bool)},
	{"set", "(ZLjava/math/BigInteger;I)V", nullptr, $FINAL, $method(DigitList, set, void, bool, $BigInteger*, int32_t)},
	{"setRoundingMode", "(Ljava/math/RoundingMode;)V", nullptr, 0, $method(DigitList, setRoundingMode, void, $RoundingMode*)},
	{"shouldRoundUp", "(IZZ)Z", nullptr, $PRIVATE, $method(DigitList, shouldRoundUp, bool, int32_t, bool, bool)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(DigitList, toString, $String*)},
	{}
};

$InnerClassInfo _DigitList_InnerClassesInfo_[] = {
	{"java.text.DigitList$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{}
};

$ClassInfo _DigitList_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.text.DigitList",
	"java.lang.Object",
	"java.lang.Cloneable",
	_DigitList_FieldInfo_,
	_DigitList_MethodInfo_,
	nullptr,
	nullptr,
	_DigitList_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.text.DigitList$1"
};

$Object* allocate$DigitList($Class* clazz) {
	return $of($alloc(DigitList));
}

bool DigitList::$assertionsDisabled = false;
$chars* DigitList::LONG_MIN_REP = nullptr;

void DigitList::init$() {
	this->decimalAt = 0;
	this->count = 0;
	$set(this, digits, $new($chars, DigitList::MAX_COUNT));
	$init($RoundingMode);
	$set(this, roundingMode, $RoundingMode::HALF_EVEN);
	this->isNegative = false;
}

bool DigitList::isZero() {
	for (int32_t i = 0; i < this->count; ++i) {
		if ($nc(this->digits)->get(i) != u'0') {
			return false;
		}
	}
	return true;
}

void DigitList::setRoundingMode($RoundingMode* r) {
	$set(this, roundingMode, r);
}

void DigitList::clear() {
	this->decimalAt = 0;
	this->count = 0;
}

void DigitList::append(char16_t digit) {
	if (this->count == $nc(this->digits)->length) {
		$var($chars, data, $new($chars, this->count + 100));
		$System::arraycopy(this->digits, 0, data, 0, this->count);
		$set(this, digits, data);
	}
	$nc(this->digits)->set(this->count++, digit);
}

double DigitList::getDouble() {
	$useLocalCurrentObjectStackCache();
	if (this->count == 0) {
		return 0.0;
	}
	$var($StringBuffer, temp, getStringBuffer());
	$nc(temp)->append(u'.');
	temp->append(this->digits, 0, this->count);
	temp->append(u'E');
	temp->append(this->decimalAt);
	return $Double::parseDouble($(temp->toString()));
}

int64_t DigitList::getLong() {
	$useLocalCurrentObjectStackCache();
	if (this->count == 0) {
		return 0;
	}
	if (isLongMIN_VALUE()) {
		return $Long::MIN_VALUE;
	}
	$var($StringBuffer, temp, getStringBuffer());
	$nc(temp)->append(this->digits, 0, this->count);
	for (int32_t i = this->count; i < this->decimalAt; ++i) {
		temp->append(u'0');
	}
	return $Long::parseLong($(temp->toString()));
}

$BigDecimal* DigitList::getBigDecimal() {
	$useLocalCurrentObjectStackCache();
	if (this->count == 0) {
		if (this->decimalAt == 0) {
			$init($BigDecimal);
			return $BigDecimal::ZERO;
		} else {
			return $new($BigDecimal, $$str({"0E"_s, $$str(this->decimalAt)}));
		}
	}
	if (this->decimalAt == this->count) {
		return $new($BigDecimal, this->digits, 0, this->count);
	} else {
		return $$new($BigDecimal, this->digits, 0, this->count)->scaleByPowerOfTen(this->decimalAt - this->count);
	}
}

bool DigitList::fitsIntoLong(bool isPositive, bool ignoreNegativeZero) {
	while (this->count > 0 && $nc(this->digits)->get(this->count - 1) == u'0') {
		--this->count;
	}
	if (this->count == 0) {
		return isPositive || ignoreNegativeZero;
	}
	if (this->decimalAt < this->count || this->decimalAt > DigitList::MAX_COUNT) {
		return false;
	}
	if (this->decimalAt < DigitList::MAX_COUNT) {
		return true;
	}
	for (int32_t i = 0; i < this->count; ++i) {
		char16_t dig = $nc(this->digits)->get(i);
		char16_t max = $nc(DigitList::LONG_MIN_REP)->get(i);
		if (dig > max) {
			return false;
		}
		if (dig < max) {
			return true;
		}
	}
	if (this->count < this->decimalAt) {
		return true;
	}
	return !isPositive;
}

void DigitList::set(bool isNegative, double source, int32_t maximumFractionDigits) {
	set(isNegative, source, maximumFractionDigits, true);
}

void DigitList::set(bool isNegative, double source, int32_t maximumDigits, bool fixedPoint) {
	$useLocalCurrentObjectStackCache();
	$var($FloatingDecimal$BinaryToASCIIConverter, fdConverter, $FloatingDecimal::getBinaryToASCIIConverter(source));
	bool hasBeenRoundedUp = $nc(fdConverter)->digitsRoundedUp();
	bool valueExactAsDecimal = fdConverter->decimalDigitsExact();
	if (!DigitList::$assertionsDisabled && ! !fdConverter->isExceptional()) {
		$throwNew($AssertionError);
	}
	$var($String, digitsString, fdConverter->toJavaFormatString());
	set(isNegative, digitsString, hasBeenRoundedUp, valueExactAsDecimal, maximumDigits, fixedPoint);
}

void DigitList::set(bool isNegative, $String* s, bool roundedUp, bool valueExactAsDecimal, int32_t maximumDigits, bool fixedPoint) {
	this->isNegative = isNegative;
	int32_t len = $nc(s)->length();
	$var($chars, source, getDataChars(len));
	s->getChars(0, len, source, 0);
	this->decimalAt = -1;
	this->count = 0;
	int32_t exponent = 0;
	int32_t leadingZerosAfterDecimal = 0;
	bool nonZeroDigitSeen = false;
	for (int32_t i = 0; i < len;) {
		char16_t c = $nc(source)->get(i++);
		if (c == u'.') {
			this->decimalAt = this->count;
		} else if (c == u'e' || c == u'E') {
			exponent = parseInt(source, i, len);
			break;
		} else {
			if (!nonZeroDigitSeen) {
				nonZeroDigitSeen = (c != u'0');
				if (!nonZeroDigitSeen && this->decimalAt != -1) {
					++leadingZerosAfterDecimal;
				}
			}
			if (nonZeroDigitSeen) {
				$nc(this->digits)->set(this->count++, c);
			}
		}
	}
	if (this->decimalAt == -1) {
		this->decimalAt = this->count;
	}
	if (nonZeroDigitSeen) {
		this->decimalAt += exponent - leadingZerosAfterDecimal;
	}
	if (fixedPoint) {
		if (-this->decimalAt > maximumDigits) {
			this->count = 0;
			return;
		} else if (-this->decimalAt == maximumDigits) {
			if (shouldRoundUp(0, roundedUp, valueExactAsDecimal)) {
				this->count = 1;
				++this->decimalAt;
				$nc(this->digits)->set(0, u'1');
			} else {
				this->count = 0;
			}
			return;
		}
	}
	while (this->count > 1 && $nc(this->digits)->get(this->count - 1) == u'0') {
		--this->count;
	}
	round(fixedPoint ? (maximumDigits + this->decimalAt) : maximumDigits, roundedUp, valueExactAsDecimal);
}

void DigitList::round(int32_t maximumDigits, bool alreadyRounded, bool valueExactAsDecimal) {
	if (maximumDigits >= 0 && maximumDigits < this->count) {
		if (shouldRoundUp(maximumDigits, alreadyRounded, valueExactAsDecimal)) {
			for (;;) {
				--maximumDigits;
				if (maximumDigits < 0) {
					$nc(this->digits)->set(0, u'1');
					++this->decimalAt;
					maximumDigits = 0;
					break;
				}
				++(*$nc(this->digits))[maximumDigits];
				if ($nc(this->digits)->get(maximumDigits) <= u'9') {
					break;
				}
			}
			++maximumDigits;
		}
		this->count = maximumDigits;
		while (this->count > 1 && $nc(this->digits)->get(this->count - 1) == u'0') {
			--this->count;
		}
	}
}

bool DigitList::shouldRoundUp(int32_t maximumDigits, bool alreadyRounded, bool valueExactAsDecimal) {
	if (maximumDigits < this->count) {
		$init($DigitList$1);
		switch ($nc($DigitList$1::$SwitchMap$java$math$RoundingMode)->get($nc((this->roundingMode))->ordinal())) {
		case 1:
			{
				for (int32_t i = maximumDigits; i < this->count; ++i) {
					if ($nc(this->digits)->get(i) != u'0') {
						return true;
					}
				}
				break;
			}
		case 2:
			{
				break;
			}
		case 3:
			{
				for (int32_t i = maximumDigits; i < this->count; ++i) {
					if ($nc(this->digits)->get(i) != u'0') {
						return !this->isNegative;
					}
				}
				break;
			}
		case 4:
			{
				for (int32_t i = maximumDigits; i < this->count; ++i) {
					if ($nc(this->digits)->get(i) != u'0') {
						return this->isNegative;
					}
				}
				break;
			}
		case 5:
			{}
		case 6:
			{
				if ($nc(this->digits)->get(maximumDigits) > u'5') {
					return true;
				} else if ($nc(this->digits)->get(maximumDigits) == u'5') {
					if (maximumDigits != (this->count - 1)) {
						return true;
					} else if (valueExactAsDecimal) {
						$init($RoundingMode);
						return this->roundingMode == $RoundingMode::HALF_UP;
					} else {
						return !alreadyRounded;
					}
				}
				break;
			}
		case 7:
			{
				if ($nc(this->digits)->get(maximumDigits) > u'5') {
					return true;
				} else if ($nc(this->digits)->get(maximumDigits) == u'5') {
					if (maximumDigits == (this->count - 1)) {
						if (alreadyRounded) {
							return false;
						}
						if (!valueExactAsDecimal) {
							return true;
						} else {
							return ((maximumDigits > 0) && ($nc(this->digits)->get(maximumDigits - 1) % 2 != 0));
						}
					} else {
						for (int32_t i = maximumDigits + 1; i < this->count; ++i) {
							if ($nc(this->digits)->get(i) != u'0') {
								return true;
							}
						}
					}
				}
				break;
			}
		case 8:
			{
				for (int32_t i = maximumDigits; i < this->count; ++i) {
					if ($nc(this->digits)->get(i) != u'0') {
						$throwNew($ArithmeticException, "Rounding needed with the rounding mode being set to RoundingMode.UNNECESSARY"_s);
					}
				}
				break;
			}
		default:
			{
				if (!DigitList::$assertionsDisabled) {
					$throwNew($AssertionError);
				}
			}
		}
	}
	return false;
}

void DigitList::set(bool isNegative, int64_t source) {
	set(isNegative, source, 0);
}

void DigitList::set(bool isNegative, int64_t source, int32_t maximumDigits) {
	this->isNegative = isNegative;
	if (source <= 0) {
		if (source == $Long::MIN_VALUE) {
			this->decimalAt = (this->count = DigitList::MAX_COUNT);
			$System::arraycopy(DigitList::LONG_MIN_REP, 0, this->digits, 0, this->count);
		} else {
			this->decimalAt = (this->count = 0);
		}
	} else {
		int32_t left = DigitList::MAX_COUNT;
		int32_t right = 0;
		while (source > 0) {
			$nc(this->digits)->set(--left, (char16_t)(u'0' + (source % 10)));
			source /= 10;
		}
		this->decimalAt = DigitList::MAX_COUNT - left;
		for (right = DigitList::MAX_COUNT - 1; $nc(this->digits)->get(right) == u'0'; --right) {
		}
		this->count = right - left + 1;
		$System::arraycopy(this->digits, left, this->digits, 0, this->count);
	}
	if (maximumDigits > 0) {
		round(maximumDigits, false, true);
	}
}

void DigitList::set(bool isNegative, $BigDecimal* source, int32_t maximumDigits, bool fixedPoint) {
	$var($String, s, $nc(source)->toString());
	extendDigits($nc(s)->length());
	set(isNegative, s, false, true, maximumDigits, fixedPoint);
}

void DigitList::set(bool isNegative, $BigInteger* source, int32_t maximumDigits) {
	this->isNegative = isNegative;
	$var($String, s, $nc(source)->toString());
	int32_t len = $nc(s)->length();
	extendDigits(len);
	s->getChars(0, len, this->digits, 0);
	this->decimalAt = len;
	int32_t right = 0;
	for (right = len - 1; right >= 0 && $nc(this->digits)->get(right) == u'0'; --right) {
	}
	this->count = right + 1;
	if (maximumDigits > 0) {
		round(maximumDigits, false, true);
	}
}

bool DigitList::equals(Object$* obj) {
	if ($equals(this, obj)) {
		return true;
	}
	$var(DigitList, other, nullptr);
	bool var$0 = $instanceOf(DigitList, obj);
	if (var$0) {
		$assign(other, $cast(DigitList, obj));
		var$0 = true;
	}
	if (!(var$0)) {
		return false;
	}
	if (this->count != $nc(other)->count || this->decimalAt != $nc(other)->decimalAt) {
		return false;
	}
	for (int32_t i = 0; i < this->count; ++i) {
		if ($nc(this->digits)->get(i) != $nc($nc(other)->digits)->get(i)) {
			return false;
		}
	}
	return true;
}

int32_t DigitList::hashCode() {
	int32_t hashcode = this->decimalAt;
	for (int32_t i = 0; i < this->count; ++i) {
		hashcode = hashcode * 37 + $nc(this->digits)->get(i);
	}
	return hashcode;
}

$Object* DigitList::clone() {
	$useLocalCurrentObjectStackCache();
	try {
		$var(DigitList, other, $cast(DigitList, $Cloneable::clone()));
		$var($chars, newDigits, $new($chars, $nc(this->digits)->length));
		$System::arraycopy(this->digits, 0, newDigits, 0, $nc(this->digits)->length);
		$set($nc(other), digits, newDigits);
		$set(other, tempBuffer, nullptr);
		return $of(other);
	} catch ($CloneNotSupportedException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

bool DigitList::isLongMIN_VALUE() {
	if (this->decimalAt != this->count || this->count != DigitList::MAX_COUNT) {
		return false;
	}
	for (int32_t i = 0; i < this->count; ++i) {
		if ($nc(this->digits)->get(i) != $nc(DigitList::LONG_MIN_REP)->get(i)) {
			return false;
		}
	}
	return true;
}

int32_t DigitList::parseInt($chars* str, int32_t offset, int32_t strLen) {
	$init(DigitList);
	char16_t c = 0;
	bool positive = true;
	if ((c = $nc(str)->get(offset)) == u'-') {
		positive = false;
		++offset;
	} else if (c == u'+') {
		++offset;
	}
	int32_t value = 0;
	while (offset < strLen) {
		c = $nc(str)->get(offset++);
		if (c >= u'0' && c <= u'9') {
			value = value * 10 + (c - u'0');
		} else {
			break;
		}
	}
	return positive ? value : -value;
}

$String* DigitList::toString() {
	if (isZero()) {
		return "0"_s;
	}
	$var($StringBuffer, buf, getStringBuffer());
	$nc(buf)->append("0."_s);
	buf->append(this->digits, 0, this->count);
	buf->append("x10^"_s);
	buf->append(this->decimalAt);
	return buf->toString();
}

$StringBuffer* DigitList::getStringBuffer() {
	if (this->tempBuffer == nullptr) {
		$set(this, tempBuffer, $new($StringBuffer, DigitList::MAX_COUNT));
	} else {
		$nc(this->tempBuffer)->setLength(0);
	}
	return this->tempBuffer;
}

void DigitList::extendDigits(int32_t len) {
	if (len > $nc(this->digits)->length) {
		$set(this, digits, $new($chars, len));
	}
}

$chars* DigitList::getDataChars(int32_t length) {
	if (this->data == nullptr || $nc(this->data)->length < length) {
		$set(this, data, $new($chars, length));
	}
	return this->data;
}

void clinit$DigitList($Class* class$) {
	DigitList::$assertionsDisabled = !DigitList::class$->desiredAssertionStatus();
	$assignStatic(DigitList::LONG_MIN_REP, "9223372036854775808"_s->toCharArray());
}

DigitList::DigitList() {
}

$Class* DigitList::load$($String* name, bool initialize) {
	$loadClass(DigitList, name, initialize, &_DigitList_ClassInfo_, clinit$DigitList, allocate$DigitList);
	return class$;
}

$Class* DigitList::class$ = nullptr;

	} // text
} // java