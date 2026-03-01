#include <NumberFormatRounding.h>

#include <java/lang/Number.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/math/RoundingMode.h>
#include <java/text/ChoiceFormat.h>
#include <java/text/NumberFormat.h>
#include <java/text/ParseException.h>
#include <jcpp.h>

#undef AE
#undef CEILING
#undef DOWN
#undef FLOOR
#undef HALF_DOWN
#undef HALF_EVEN
#undef HALF_UP
#undef UNNECESSARY
#undef UP

using $ArithmeticException = ::java::lang::ArithmeticException;
using $ClassInfo = ::java::lang::ClassInfo;
using $Double = ::java::lang::Double;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $Number = ::java::lang::Number;
using $RuntimeException = ::java::lang::RuntimeException;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $RoundingMode = ::java::math::RoundingMode;
using $ChoiceFormat = ::java::text::ChoiceFormat;
using $NumberFormat = ::java::text::NumberFormat;
using $ParseException = ::java::text::ParseException;

$FieldInfo _NumberFormatRounding_FieldInfo_[] = {
	{"AE", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(NumberFormatRounding, AE)},
	{"src", "[D", nullptr, $STATIC | $FINAL, $staticField(NumberFormatRounding, src)},
	{"up", "[Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(NumberFormatRounding, up)},
	{"down", "[Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(NumberFormatRounding, down)},
	{"ceiling", "[Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(NumberFormatRounding, ceiling)},
	{"floor", "[Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(NumberFormatRounding, floor)},
	{"half_up", "[Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(NumberFormatRounding, half_up)},
	{"half_down", "[Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(NumberFormatRounding, half_down)},
	{"half_even", "[Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(NumberFormatRounding, half_even)},
	{"unnecessary", "[Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(NumberFormatRounding, unnecessary)},
	{}
};

$MethodInfo _NumberFormatRounding_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(NumberFormatRounding, init$, void)},
	{"basicTest", "()V", nullptr, $STATIC, $staticMethod(NumberFormatRounding, basicTest, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(NumberFormatRounding, main, void, $StringArray*)},
	{"roundTest", "(Ljava/math/RoundingMode;[Ljava/lang/String;)V", nullptr, $STATIC, $staticMethod(NumberFormatRounding, roundTest, void, $RoundingMode*, $StringArray*)},
	{}
};

$ClassInfo _NumberFormatRounding_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"NumberFormatRounding",
	"java.lang.Object",
	nullptr,
	_NumberFormatRounding_FieldInfo_,
	_NumberFormatRounding_MethodInfo_
};

$Object* allocate$NumberFormatRounding($Class* clazz) {
	return $of($alloc(NumberFormatRounding));
}

$String* NumberFormatRounding::AE = nullptr;
$doubles* NumberFormatRounding::src = nullptr;
$StringArray* NumberFormatRounding::up = nullptr;
$StringArray* NumberFormatRounding::down = nullptr;
$StringArray* NumberFormatRounding::ceiling = nullptr;
$StringArray* NumberFormatRounding::floor = nullptr;
$StringArray* NumberFormatRounding::half_up = nullptr;
$StringArray* NumberFormatRounding::half_down = nullptr;
$StringArray* NumberFormatRounding::half_even = nullptr;
$StringArray* NumberFormatRounding::unnecessary = nullptr;

void NumberFormatRounding::init$() {
}

void NumberFormatRounding::main($StringArray* args) {
	$init(NumberFormatRounding);
	basicTest();
	$init($RoundingMode);
	roundTest($RoundingMode::UP, NumberFormatRounding::up);
	roundTest($RoundingMode::DOWN, NumberFormatRounding::down);
	roundTest($RoundingMode::CEILING, NumberFormatRounding::ceiling);
	roundTest($RoundingMode::FLOOR, NumberFormatRounding::floor);
	roundTest($RoundingMode::HALF_UP, NumberFormatRounding::half_up);
	roundTest($RoundingMode::HALF_DOWN, NumberFormatRounding::half_down);
	roundTest($RoundingMode::HALF_EVEN, NumberFormatRounding::half_even);
	roundTest($RoundingMode::UNNECESSARY, NumberFormatRounding::unnecessary);
}

void NumberFormatRounding::basicTest() {
	$init(NumberFormatRounding);
	$useLocalCurrentObjectStackCache();
	$var($NumberFormat, nf, $NumberFormat::getIntegerInstance());
	$init($RoundingMode);
	if ($nc(nf)->getRoundingMode() != $RoundingMode::HALF_EVEN) {
		$throwNew($RuntimeException, "default rounding is not HALF_EVEN"_s);
	}
	try {
		$nc(nf)->setRoundingMode(nullptr);
		$throwNew($RuntimeException, "NullPointerException is not thrown by calling setRoundingMode(null)"_s);
	} catch ($NullPointerException& npe) {
	}
	$var($ChoiceFormat, cf, $new($ChoiceFormat, ""_s));
	try {
		cf->setRoundingMode($RoundingMode::HALF_EVEN);
		$throwNew($RuntimeException, "UnsupportedOperationException is not thrown by calling setRoundingMode()"_s);
	} catch ($UnsupportedOperationException& uoe) {
	}
	try {
		cf->getRoundingMode();
		$throwNew($RuntimeException, "UnsupportedOperationException is not thrown by calling getRoundingMode()"_s);
	} catch ($UnsupportedOperationException& uoe) {
	}
}

void NumberFormatRounding::roundTest($RoundingMode* rm, $StringArray* expected) {
	$init(NumberFormatRounding);
	$useLocalCurrentObjectStackCache();
	$var($NumberFormat, nf, $NumberFormat::getIntegerInstance());
	$nc(nf)->setRoundingMode(rm);
	if (nf->getRoundingMode() != rm) {
		$throwNew($RuntimeException, "set rounding mode is not returned by get method"_s);
	}
	for (int32_t i = 0; i < $nc(NumberFormatRounding::src)->length; ++i) {
		$var($String, result, nullptr);
		try {
			$assign(result, $nc($of($(nf->parse($(nf->format($nc(NumberFormatRounding::src)->get(i)))))))->toString());
			if (!$nc(result)->equals($nc(expected)->get(i))) {
				$throwNew($RuntimeException, $$str({"rounding test #"_s, $$str(i), " failed. mode: "_s, rm, " src: "_s, $$str($nc(NumberFormatRounding::src)->get(i)), " expected: "_s, $nc(expected)->get(i), " result: "_s, result}));
			}
		} catch ($ArithmeticException& ae) {
			if ($nc($nc(expected)->get(i))->equals(NumberFormatRounding::AE)) {
				continue;
			} else {
				$assign(result, NumberFormatRounding::AE);
				$throwNew($RuntimeException, $$str({"rounding test #"_s, $$str(i), " failed. mode: "_s, rm, " src: "_s, $$str($nc(NumberFormatRounding::src)->get(i)), " expected: "_s, expected->get(i), " result: "_s, result}));
			}
		} catch ($ParseException& pe) {
			$throwNew($RuntimeException, "ParseException ocurred."_s, pe);
		}
	}
}

void clinit$NumberFormatRounding($Class* class$) {
	$assignStatic(NumberFormatRounding::AE, "ArithmeticException"_s);
	$assignStatic(NumberFormatRounding::src, $new($doubles, {
		5.5,
		2.5,
		1.6,
		1.1,
		1.0,
		-1.0,
		-1.1,
		-1.6,
		-2.5,
		-5.5,
		5.501,
		-5.501,
		5.5,
		-5.5,
		1.001,
		-1.001,
		4.501,
		-4.501,
		4.5,
		-4.5
	}));
	$assignStatic(NumberFormatRounding::up, $new($StringArray, {
		"6"_s,
		"3"_s,
		"2"_s,
		"2"_s,
		"1"_s,
		"-1"_s,
		"-2"_s,
		"-2"_s,
		"-3"_s,
		"-6"_s,
		"6"_s,
		"-6"_s,
		"6"_s,
		"-6"_s,
		"2"_s,
		"-2"_s,
		"5"_s,
		"-5"_s,
		"5"_s,
		"-5"_s
	}));
	$assignStatic(NumberFormatRounding::down, $new($StringArray, {
		"5"_s,
		"2"_s,
		"1"_s,
		"1"_s,
		"1"_s,
		"-1"_s,
		"-1"_s,
		"-1"_s,
		"-2"_s,
		"-5"_s,
		"5"_s,
		"-5"_s,
		"5"_s,
		"-5"_s,
		"1"_s,
		"-1"_s,
		"4"_s,
		"-4"_s,
		"4"_s,
		"-4"_s
	}));
	$assignStatic(NumberFormatRounding::ceiling, $new($StringArray, {
		"6"_s,
		"3"_s,
		"2"_s,
		"2"_s,
		"1"_s,
		"-1"_s,
		"-1"_s,
		"-1"_s,
		"-2"_s,
		"-5"_s,
		"6"_s,
		"-5"_s,
		"6"_s,
		"-5"_s,
		"2"_s,
		"-1"_s,
		"5"_s,
		"-4"_s,
		"5"_s,
		"-4"_s
	}));
	$assignStatic(NumberFormatRounding::floor, $new($StringArray, {
		"5"_s,
		"2"_s,
		"1"_s,
		"1"_s,
		"1"_s,
		"-1"_s,
		"-2"_s,
		"-2"_s,
		"-3"_s,
		"-6"_s,
		"5"_s,
		"-6"_s,
		"5"_s,
		"-6"_s,
		"1"_s,
		"-2"_s,
		"4"_s,
		"-5"_s,
		"4"_s,
		"-5"_s
	}));
	$assignStatic(NumberFormatRounding::half_up, $new($StringArray, {
		"6"_s,
		"3"_s,
		"2"_s,
		"1"_s,
		"1"_s,
		"-1"_s,
		"-1"_s,
		"-2"_s,
		"-3"_s,
		"-6"_s,
		"6"_s,
		"-6"_s,
		"6"_s,
		"-6"_s,
		"1"_s,
		"-1"_s,
		"5"_s,
		"-5"_s,
		"5"_s,
		"-5"_s
	}));
	$assignStatic(NumberFormatRounding::half_down, $new($StringArray, {
		"5"_s,
		"2"_s,
		"2"_s,
		"1"_s,
		"1"_s,
		"-1"_s,
		"-1"_s,
		"-2"_s,
		"-2"_s,
		"-5"_s,
		"6"_s,
		"-6"_s,
		"5"_s,
		"-5"_s,
		"1"_s,
		"-1"_s,
		"5"_s,
		"-5"_s,
		"4"_s,
		"-4"_s
	}));
	$assignStatic(NumberFormatRounding::half_even, $new($StringArray, {
		"6"_s,
		"2"_s,
		"2"_s,
		"1"_s,
		"1"_s,
		"-1"_s,
		"-1"_s,
		"-2"_s,
		"-2"_s,
		"-6"_s,
		"6"_s,
		"-6"_s,
		"6"_s,
		"-6"_s,
		"1"_s,
		"-1"_s,
		"5"_s,
		"-5"_s,
		"4"_s,
		"-4"_s
	}));
	$assignStatic(NumberFormatRounding::unnecessary, $new($StringArray, {
		NumberFormatRounding::AE,
		NumberFormatRounding::AE,
		NumberFormatRounding::AE,
		NumberFormatRounding::AE,
		"1"_s,
		"-1"_s,
		NumberFormatRounding::AE,
		NumberFormatRounding::AE,
		NumberFormatRounding::AE,
		NumberFormatRounding::AE,
		NumberFormatRounding::AE,
		NumberFormatRounding::AE,
		NumberFormatRounding::AE,
		NumberFormatRounding::AE,
		NumberFormatRounding::AE,
		NumberFormatRounding::AE,
		NumberFormatRounding::AE,
		NumberFormatRounding::AE,
		NumberFormatRounding::AE,
		NumberFormatRounding::AE
	}));
}

NumberFormatRounding::NumberFormatRounding() {
}

$Class* NumberFormatRounding::load$($String* name, bool initialize) {
	$loadClass(NumberFormatRounding, name, initialize, &_NumberFormatRounding_ClassInfo_, clinit$NumberFormatRounding, allocate$NumberFormatRounding);
	return class$;
}

$Class* NumberFormatRounding::class$ = nullptr;