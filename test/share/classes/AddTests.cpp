#include <AddTests.h>

#include <java/lang/Enum.h>
#include <java/math/BigDecimal.h>
#include <java/math/BigInteger.h>
#include <java/math/MathContext.h>
#include <java/math/RoundingMode.h>
#include <java/util/EnumSet.h>
#include <java/util/Iterator.h>
#include <java/util/Set.h>
#include <jcpp.h>

#undef DOWN
#undef MAX_VALUE
#undef ONE
#undef UNNECESSARY

using $BigDecimalArray = $Array<::java::math::BigDecimal>;
using $PrintStream = ::java::io::PrintStream;
using $ArithmeticException = ::java::lang::ArithmeticException;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $BigDecimal = ::java::math::BigDecimal;
using $BigInteger = ::java::math::BigInteger;
using $MathContext = ::java::math::MathContext;
using $RoundingMode = ::java::math::RoundingMode;
using $EnumSet = ::java::util::EnumSet;
using $Iterator = ::java::util::Iterator;
using $Set = ::java::util::Set;

$FieldInfo _AddTests_FieldInfo_[] = {
	{"nonExactRoundingModes", "Ljava/util/Set;", "Ljava/util/Set<Ljava/math/RoundingMode;>;", $PRIVATE | $STATIC, $staticField(AddTests, nonExactRoundingModes)},
	{}
};

$MethodInfo _AddTests_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(AddTests, init$, void)},
	{"addWithoutException", "(Ljava/math/BigDecimal;Ljava/math/BigDecimal;Ljava/math/MathContext;)I", nullptr, $PRIVATE | $STATIC, $staticMethod(AddTests, addWithoutException, int32_t, $BigDecimal*, $BigDecimal*, $MathContext*)},
	{"arithmeticExceptionTest", "()I", nullptr, $PRIVATE | $STATIC, $staticMethod(AddTests, arithmeticExceptionTest, int32_t)},
	{"extremaTests", "()I", nullptr, $PRIVATE | $STATIC, $staticMethod(AddTests, extremaTests, int32_t)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(AddTests, main, void, $StringArray*)},
	{"precisionConsistencyTest", "()I", nullptr, $PRIVATE | $STATIC, $staticMethod(AddTests, precisionConsistencyTest, int32_t)},
	{"printAddition", "(Ljava/math/BigDecimal;Ljava/math/BigDecimal;Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(AddTests, printAddition, void, $BigDecimal*, $BigDecimal*, $String*)},
	{"roundAway", "(Ljava/math/BigDecimal;Ljava/math/BigDecimal;)I", nullptr, $PRIVATE | $STATIC, $staticMethod(AddTests, roundAway, int32_t, $BigDecimal*, $BigDecimal*)},
	{"roundAway0", "(Ljava/math/BigDecimal;Ljava/math/BigDecimal;)I", nullptr, $PRIVATE | $STATIC, $staticMethod(AddTests, roundAway0, int32_t, $BigDecimal*, $BigDecimal*)},
	{"roundAway1", "(Ljava/math/BigDecimal;Ljava/math/BigDecimal;)I", nullptr, $PRIVATE | $STATIC, $staticMethod(AddTests, roundAway1, int32_t, $BigDecimal*, $BigDecimal*)},
	{"roundingGradationTests", "()I", nullptr, $PRIVATE | $STATIC, $staticMethod(AddTests, roundingGradationTests, int32_t)},
	{"simpleTests", "()I", nullptr, $PRIVATE | $STATIC, $staticMethod(AddTests, simpleTests, int32_t)},
	{}
};

$ClassInfo _AddTests_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"AddTests",
	"java.lang.Object",
	nullptr,
	_AddTests_FieldInfo_,
	_AddTests_MethodInfo_
};

$Object* allocate$AddTests($Class* clazz) {
	return $of($alloc(AddTests));
}

$Set* AddTests::nonExactRoundingModes = nullptr;

void AddTests::init$() {
}

int32_t AddTests::simpleTests() {
	$init(AddTests);
	$useLocalCurrentObjectStackCache();
	int32_t failures = 0;
	$var($BigDecimalArray, bd1, $new($BigDecimalArray, {
		$$new($BigDecimal, $$new($BigInteger, "7812404666936930160"_s), 11),
		$$new($BigDecimal, $$new($BigInteger, "7812404666936930160"_s), 12),
		$$new($BigDecimal, $$new($BigInteger, "7812404666936930160"_s), 13)
	}));
	$var($BigDecimal, bd2, $new($BigDecimal, $$new($BigInteger, "2790000"_s), 1));
	$var($BigDecimalArray, expectedResult, $new($BigDecimalArray, {
		$$new($BigDecimal, "78403046.66936930160"_s),
		$$new($BigDecimal, "8091404.666936930160"_s),
		$$new($BigDecimal, "1060240.4666936930160"_s)
	}));
	for (int32_t i = 0; i < bd1->length; ++i) {
		if (!$nc($($nc(bd1->get(i))->add(bd2)))->equals(expectedResult->get(i))) {
			++failures;
		}
	}
	return failures;
}

int32_t AddTests::extremaTests() {
	$init(AddTests);
	$useLocalCurrentObjectStackCache();
	int32_t failures = 0;
	$var($BigDecimal, var$0, $BigDecimal::valueOf(1, -$Integer::MAX_VALUE));
	failures += addWithoutException(var$0, $($BigDecimal::valueOf(2, $Integer::MAX_VALUE)), nullptr);
	$var($BigDecimal, var$1, $BigDecimal::valueOf(1, -$Integer::MAX_VALUE));
	failures += addWithoutException(var$1, $($BigDecimal::valueOf(-2, $Integer::MAX_VALUE)), nullptr);
	return failures;
}

int32_t AddTests::addWithoutException($BigDecimal* b1, $BigDecimal* b2, $MathContext* mc$renamed) {
	$init(AddTests);
	$useLocalCurrentObjectStackCache();
	$var($MathContext, mc, mc$renamed);
	if (mc == nullptr) {
		$init($RoundingMode);
		$assign(mc, $new($MathContext, 2, $RoundingMode::DOWN));
	}
	try {
		$var($BigDecimal, sum, $nc(b1)->add(b2, mc));
		printAddition(b1, b2, $($nc(sum)->toString()));
		return 0;
	} catch ($ArithmeticException& ae) {
		printAddition(b1, b2, "Exception!"_s);
		return 1;
	}
	$shouldNotReachHere();
}

int32_t AddTests::roundingGradationTests() {
	$init(AddTests);
	$useLocalCurrentObjectStackCache();
	int32_t failures = 0;
	$var($BigDecimal, var$0, $new($BigDecimal, "1234e100"_s));
	failures += roundAway(var$0, $$new($BigDecimal, "1234e97"_s));
	$var($BigDecimal, var$1, $new($BigDecimal, "1234e100"_s));
	failures += roundAway(var$1, $$new($BigDecimal, "1234e96"_s));
	$var($BigDecimal, var$2, $new($BigDecimal, "1234e100"_s));
	failures += roundAway(var$2, $$new($BigDecimal, "1234e95"_s));
	$var($BigDecimal, var$3, $new($BigDecimal, "1234e100"_s));
	failures += roundAway(var$3, $$new($BigDecimal, "1234e94"_s));
	$var($BigDecimal, var$4, $new($BigDecimal, "1234e100"_s));
	failures += roundAway(var$4, $$new($BigDecimal, "1234e93"_s));
	$var($BigDecimal, var$5, $new($BigDecimal, "1234e100"_s));
	failures += roundAway(var$5, $$new($BigDecimal, "1234e92"_s));
	$var($BigDecimal, var$6, $new($BigDecimal, "1234e100"_s));
	failures += roundAway(var$6, $$new($BigDecimal, "1234e50"_s));
	$var($BigDecimal, var$7, $new($BigDecimal, "1000e100"_s));
	failures += roundAway(var$7, $$new($BigDecimal, "1234e97"_s));
	$var($BigDecimal, var$8, $new($BigDecimal, "1000e100"_s));
	failures += roundAway(var$8, $$new($BigDecimal, "1234e96"_s));
	$var($BigDecimal, var$9, $new($BigDecimal, "1000e100"_s));
	failures += roundAway(var$9, $$new($BigDecimal, "1234e95"_s));
	$var($BigDecimal, var$10, $new($BigDecimal, "1000e100"_s));
	failures += roundAway(var$10, $$new($BigDecimal, "1234e94"_s));
	$var($BigDecimal, var$11, $new($BigDecimal, "1000e100"_s));
	failures += roundAway(var$11, $$new($BigDecimal, "1234e93"_s));
	$var($BigDecimal, var$12, $new($BigDecimal, "1000e100"_s));
	failures += roundAway(var$12, $$new($BigDecimal, "1234e92"_s));
	$var($BigDecimal, var$13, $new($BigDecimal, "1000e100"_s));
	failures += roundAway(var$13, $$new($BigDecimal, "1234e50"_s));
	$var($BigDecimal, var$14, $new($BigDecimal, "1999e100"_s));
	failures += roundAway(var$14, $$new($BigDecimal, "1234e97"_s));
	$var($BigDecimal, var$15, $new($BigDecimal, "1999e100"_s));
	failures += roundAway(var$15, $$new($BigDecimal, "1234e96"_s));
	$var($BigDecimal, var$16, $new($BigDecimal, "1999e100"_s));
	failures += roundAway(var$16, $$new($BigDecimal, "1234e95"_s));
	$var($BigDecimal, var$17, $new($BigDecimal, "1999e100"_s));
	failures += roundAway(var$17, $$new($BigDecimal, "1234e94"_s));
	$var($BigDecimal, var$18, $new($BigDecimal, "1999e100"_s));
	failures += roundAway(var$18, $$new($BigDecimal, "1234e93"_s));
	$var($BigDecimal, var$19, $new($BigDecimal, "1999e100"_s));
	failures += roundAway(var$19, $$new($BigDecimal, "1234e92"_s));
	$var($BigDecimal, var$20, $new($BigDecimal, "1999e100"_s));
	failures += roundAway(var$20, $$new($BigDecimal, "1234e50"_s));
	$var($BigDecimal, var$21, $new($BigDecimal, "9999e100"_s));
	failures += roundAway(var$21, $$new($BigDecimal, "1234e97"_s));
	$var($BigDecimal, var$22, $new($BigDecimal, "9999e100"_s));
	failures += roundAway(var$22, $$new($BigDecimal, "1234e96"_s));
	$var($BigDecimal, var$23, $new($BigDecimal, "9999e100"_s));
	failures += roundAway(var$23, $$new($BigDecimal, "1234e95"_s));
	$var($BigDecimal, var$24, $new($BigDecimal, "9999e100"_s));
	failures += roundAway(var$24, $$new($BigDecimal, "1234e94"_s));
	$var($BigDecimal, var$25, $new($BigDecimal, "9999e100"_s));
	failures += roundAway(var$25, $$new($BigDecimal, "1234e93"_s));
	$var($BigDecimal, var$26, $new($BigDecimal, "9999e100"_s));
	failures += roundAway(var$26, $$new($BigDecimal, "1234e92"_s));
	$var($BigDecimal, var$27, $new($BigDecimal, "9999e100"_s));
	failures += roundAway(var$27, $$new($BigDecimal, "1234e50"_s));
	return failures;
}

void AddTests::printAddition($BigDecimal* b1, $BigDecimal* b2, $String* s) {
	$init(AddTests);
	$nc($System::out)->println($$str({""_s, b1, "\t+\t"_s, b2, "\t=\t"_s, s}));
}

int32_t AddTests::roundAway($BigDecimal* b1, $BigDecimal* b2) {
	$init(AddTests);
	$useLocalCurrentObjectStackCache();
	int32_t failures = 0;
	$nc(b1)->precision();
	$nc(b2)->precision();
	$var($BigDecimal, b1_negate, b1->negate());
	$var($BigDecimal, b2_negate, b2->negate());
	$nc(b1_negate)->precision();
	$nc(b2_negate)->precision();
	failures += roundAway1(b1, b2);
	failures += roundAway1(b1, b2_negate);
	failures += roundAway1(b1_negate, b2);
	failures += roundAway1(b1_negate, b2_negate);
	return failures;
}

int32_t AddTests::roundAway1($BigDecimal* b1, $BigDecimal* b2) {
	$init(AddTests);
	int32_t failures = 0;
	failures += roundAway0(b1, b2);
	failures += roundAway0(b2, b1);
	return failures;
}

int32_t AddTests::roundAway0($BigDecimal* b1, $BigDecimal* b2) {
	$init(AddTests);
	$useLocalCurrentObjectStackCache();
	int32_t failures = 0;
	$var($BigDecimal, exactSum, $nc(b1)->add(b2));
	for (int32_t precision = 1; precision < $nc(exactSum)->precision() + 2; ++precision) {
		{
			$var($Iterator, i$, $nc(AddTests::nonExactRoundingModes)->iterator());
			for (; $nc(i$)->hasNext();) {
				$RoundingMode* rm = $cast($RoundingMode, i$->next());
				{
					$var($MathContext, mc, $new($MathContext, precision, rm));
					$var($BigDecimal, roundedExactSum, exactSum->round(mc));
					try {
						$var($BigDecimal, sum, b1->add(b2, mc));
						if (!$nc(roundedExactSum)->equals(sum)) {
							++failures;
							$nc($System::out)->println($$str({"Exact sum "_s, exactSum, "\trounded by "_s, mc, "\texpected: "_s, roundedExactSum, " got: "_s}));
							printAddition(b1, b2, $($nc(sum)->toString()));
						}
					} catch ($ArithmeticException& ae) {
						printAddition(b1, b2, "Exception!"_s);
						++failures;
					}
				}
			}
		}
	}
	return failures;
}

int32_t AddTests::precisionConsistencyTest() {
	$init(AddTests);
	$useLocalCurrentObjectStackCache();
	int32_t failures = 0;
	$init($RoundingMode);
	$var($MathContext, mc, $new($MathContext, 1, $RoundingMode::DOWN));
	$var($BigDecimal, a, $BigDecimal::valueOf(1999, -1));
	$var($BigDecimal, sum1, $nc(a)->add($BigDecimal::ONE, mc));
	a->precision();
	$var($BigDecimal, sum2, a->add($BigDecimal::ONE, mc));
	if (!$nc(sum1)->equals(sum2)) {
		++failures;
		$nc($System::out)->println("Unequal sums after calling precision!"_s);
		$nc($System::out)->print("Before:\t"_s);
		printAddition(a, $BigDecimal::ONE, $(sum1->toString()));
		$nc($System::out)->print("After:\t"_s);
		printAddition(a, $BigDecimal::ONE, $($nc(sum2)->toString()));
	}
	return failures;
}

int32_t AddTests::arithmeticExceptionTest() {
	$init(AddTests);
	$useLocalCurrentObjectStackCache();
	int32_t failures = 0;
	$var($BigDecimal, x, nullptr);
	try {
		$assign(x, $$new($BigDecimal, "1e2147483647"_s)->add($$new($BigDecimal, 1)));
		++failures;
	} catch ($ArithmeticException& ae) {
	}
	return failures;
}

void AddTests::main($StringArray* argv) {
	$init(AddTests);
	$useLocalCurrentObjectStackCache();
	int32_t failures = 0;
	failures += extremaTests();
	failures += roundingGradationTests();
	failures += precisionConsistencyTest();
	failures += arithmeticExceptionTest();
	if (failures > 0) {
		$throwNew($RuntimeException, $$str({"Incurred "_s, $$str(failures), " failures while testing rounding add."_s}));
	}
}

void clinit$AddTests($Class* class$) {
	$init($RoundingMode);
	$assignStatic(AddTests::nonExactRoundingModes, $EnumSet::complementOf($($EnumSet::of($RoundingMode::UNNECESSARY))));
}

AddTests::AddTests() {
}

$Class* AddTests::load$($String* name, bool initialize) {
	$loadClass(AddTests, name, initialize, &_AddTests_ClassInfo_, clinit$AddTests, allocate$AddTests);
	return class$;
}

$Class* AddTests::class$ = nullptr;